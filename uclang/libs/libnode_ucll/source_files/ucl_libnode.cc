
@begin
include "ucl_libnode.h"
@end

// - global interpreter pointer -
interpreter_s *interpreter_ptr = NULL;

// - UclNode global init object -
UclNode g_UclNode;

/*
 * methods of class UclNode
 */

bool UclNode::Initialize(const char **a_modules)
{/*{{{*/

  // - source initialization -
  source_s source;
  source.init();

  // - set empty source file -
  source.file_name.set(strlen("none"),"none");
  source.source_string.set(strlen("\n"),"\n");

  // - modules path initialization -
  string_s mods_path;
  mods_path.init();

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX || SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS

  // - if modules path was not defined -
  if (mods_path.data == &c_string_terminating_char)
  {
    // - read modules path environment variable -
    char *mp_value = getenv("UCLANG_MODS_PATH");
    if (mp_value != NULL)
    {
      // - set modules path to value of environment variable -
      mods_path.set(strlen(mp_value),mp_value);
    }
  }
#endif

  // Test sizes of used data types
  if (sizeof(void *)        != sizeof(long unsigned) ||
      sizeof(unsigned)      != 4 ||
      sizeof(char)          != 1 ||
      sizeof(long long int) != 8 ||
      sizeof(double)        != 8)
  {
    fprintf(stderr,"Not tested on non 32bit system, sorry\n");

    mods_path.clear();
    source.clear();

    return false;
  }

  // - creation of parser object -
  parser.initialize_parser(source,mods_path);

  mods_path.clear();
  source.clear();

#define UCL_NODE_IMPORT_MODULE(NAME) \
{/*{{{*/\
  const char *name_data = NAME;\
  unsigned name_length = strlen(name_data);\
\
  /* - insert module name to module names array - */\
  unsigned name_idx = parser.module_names.get_idx_char_ptr(name_length,name_data);\
  if (name_idx == c_idx_not_exist)\
  {\
    parser.module_names.push_blank();\
    parser.module_names.last().set(name_length,name_data);\
\
    /* - set module import name position - */\
    parser.module_names_positions.push_blank();\
    parser.module_names_positions.last().set(SET_SRC_POS(0,0),SET_SRC_POS(0,0));\
  }\
}/*}}}*/

  // - always imported modules -
  UCL_NODE_IMPORT_MODULE("node");

  // - import user defined modules -
  const char **module = a_modules;
  while (*module)
  {
    UCL_NODE_IMPORT_MODULE(*module);
    ++module;
  }

  parser.process_modules();
  if (parser.error_code.used != 0)
  {
    parser.process_errors();

    Clear();
    return false;
  }

  parser.extended_classes_search();
  if (parser.error_code.used != 0)
  {
    parser.process_errors();

    Clear();
    return false;
  }

  parser.element_search();
  if (parser.error_code.used != 0)
  {
    parser.process_errors();

    Clear();
    return false;
  }

  parser.generate_intermediate_code();
  if (parser.error_code.used != 0)
  {
    parser.process_errors();

    Clear();
    return false;
  }

  // - create ucl node module bool list -
  bool modules[c_uclvar_module_count];

  // - always presented modules -
  modules[c_uclvar_module_base] = true;
  modules[c_uclvar_module_node] = true;

#define UCL_NODE_CHECK_MODULE_PRESENCE(NAME) \
{/*{{{*/\
  modules[c_uclvar_module_ ## NAME] =\
    parser.module_names.get_idx_char_ptr(strlen(#NAME),#NAME) != c_idx_not_exist;\
}/*}}}*/

  // - check modules presence -
  UCL_NODE_CHECK_MODULE_PRESENCE(sys);
  UCL_NODE_CHECK_MODULE_PRESENCE(inotify);
  UCL_NODE_CHECK_MODULE_PRESENCE(pack);
  UCL_NODE_CHECK_MODULE_PRESENCE(parser);
  UCL_NODE_CHECK_MODULE_PRESENCE(sqlite);
  UCL_NODE_CHECK_MODULE_PRESENCE(http);
  UCL_NODE_CHECK_MODULE_PRESENCE(websocket);
  UCL_NODE_CHECK_MODULE_PRESENCE(curl);
  UCL_NODE_CHECK_MODULE_PRESENCE(ucf);
  UCL_NODE_CHECK_MODULE_PRESENCE(ftp);
  UCL_NODE_CHECK_MODULE_PRESENCE(ssh2);
  UCL_NODE_CHECK_MODULE_PRESENCE(jit);
  UCL_NODE_CHECK_MODULE_PRESENCE(containers);
  UCL_NODE_CHECK_MODULE_PRESENCE(algorithms);
  UCL_NODE_CHECK_MODULE_PRESENCE(json);
  UCL_NODE_CHECK_MODULE_PRESENCE(xml);

  // - initialize ucl variables (parser) -
  UclVar::Initialize(parser,modules);

  interpreter.create_from_script_parser(parser);

  // - set global pointer to interpreter -
  interpreter_ptr = &interpreter;

  interpreter.create_constant_and_static_locations();

  // - initialize ucl variables (interpreter) -
  UclVar::Initialize(interpreter,modules);

  // - create interpreter thread -
  {
    // - creation of description of main thread -
    thread = (interpreter_thread_s *)cmalloc(sizeof(interpreter_thread_s));
    thread->init();

    thread->interpreter_ptr = (pointer)&interpreter;

    // - creation of thread location for main thread -
    {
      thread_s *new_thread = (thread_s *)cmalloc(sizeof(thread_s));
      new_thread->init();

      new_thread->create_from_actual(pthread_self());

      location_s *new_location = thread->get_new_location_ptr();
      new_location->v_type = c_bi_class_thread;
      new_location->v_reference_cnt.atomic_set(1);
      new_location->v_data_ptr = (basic_64b)new_thread;

      thread->thread_location = (pointer)new_location;
    }

    // - creation of blank, and exception location for main thread -
    {
      location_s *new_location = thread->get_new_location_ptr();
      new_location->v_type = c_bi_class_blank;
      new_location->v_reference_cnt.atomic_set(2);

      thread->blank_location = (pointer)new_location;
      thread->exception_location = (pointer)new_location;
    }

    try
    {
      // - setting of stack for static code -
      if (interpreter.stack_size != 0)
      {
        unsigned stack_size_cnt = interpreter.stack_size;
        ((location_s *)thread->blank_location)->v_reference_cnt.atomic_add(stack_size_cnt);

        do
        {
          thread->data_stack.push(thread->blank_location);
        }
        while(--stack_size_cnt);
      }

      if (interpreter.static_begin_code.used != 0)
      {
        // - launch static begin code -
        thread->run_expression_code(interpreter.static_begin_code.data,0,NULL);
        if (((location_s *)thread->exception_location)->v_type != c_bi_class_blank)
        {
          // - print exception message -
          exception_s *exception_ptr = (exception_s *)((location_s *)thread->exception_location)->v_data_ptr;
          interpreter.print_exception_message(*exception_ptr);

          Clear();
          return false;
        }
      }

      if (interpreter.static_run_time_code.used != 0)
      {
        // - launch static run time code -
        thread->run_expression_code(interpreter.static_run_time_code.data,0,NULL);
        if (((location_s *)thread->exception_location)->v_type != c_bi_class_blank)
        {
          // - print exception message -
          exception_s *exception_ptr = (exception_s *)((location_s *)thread->exception_location)->v_data_ptr;
          interpreter.print_exception_message(*exception_ptr);

          Clear();
          return false;
        }
      }

      thread->release_stack_from(0);

      // - set pointer to interpreter main thread -
      interpreter.main_thread_ptr = thread;
    }
    catch (int)
    {
      Clear();
      return false;
    }
  }

  // - initialize UclVar thread -
  UclVar::InitThread(*thread);

  return true;
}/*}}}*/

bool UclNode::Clear()
{/*{{{*/

  // - release ucl variables -
  UclVar::Release(interpreter);

  if (thread != NULL)
  {
    // - release location from stack -
    thread->release_stack_from(0);

    // - remove pointer to interpreter main thread -
    interpreter.main_thread_ptr = NULL;

    // - release thread locations -
    thread->release_location_ptr((location_s *)thread->thread_location);

    // - release thread blank and exception locations -
    thread->release_location_ptr((location_s *)thread->blank_location);
    thread->release_location_ptr((location_s *)thread->exception_location);

    // - remove thread description from memory -
    thread->free_variables_clear();
    thread->clear();
    cfree(thread);
  }

  interpreter.release_constant_and_static_locations();

  // - remove global pointer to interpreter -
  interpreter_ptr = NULL;

  // - release interpreter -
  interpreter.clear();

  // - release parser -
  parser.clear();

  return true;
}/*}}}*/

