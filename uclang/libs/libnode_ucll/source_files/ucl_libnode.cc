
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

bool UclNode::Initialize(bool *a_modules)
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

    exit(125);
  }

  // - creation of parser object -
  parser.initialize_parser(source,mods_path);

  mods_path.clear();
  source.clear();

  // - exist errors -
  if (parser.error_code.used != 0)
  {
    parser.process_errors();
    return false;
  }

#define UCL_NODE_IMPORT_MODULE(NAME) \
{/*{{{*/\
  parser.module_names.push_blank();\
  parser.module_names.last().set(strlen(NAME),NAME);\
\
  parser.module_names_positions.push_blank();\
  parser.module_names_positions.last().set(SET_SRC_POS(0,0),SET_SRC_POS(0,0));\
\
  parser.load_module(NAME "_uclm" DYNAMIC_LIB_EXTENSION);\
\
  /* - exist errors - */\
  if (parser.error_code.used != 0)\
  {\
    parser.process_errors();\
    cassert(0);\
  }\
\
  parser.module_idx++;\
}/*}}}*/

  UCL_NODE_IMPORT_MODULE("node");

  // - module sys -
  if (a_modules[c_uclvar_module_sys])
  {
    UCL_NODE_IMPORT_MODULE("sys");
  }

  // - module containers -
  if (a_modules[c_uclvar_module_containers])
  {
    UCL_NODE_IMPORT_MODULE("containers");
  }

  // - module json -
  if (a_modules[c_uclvar_module_json])
  {
    UCL_NODE_IMPORT_MODULE("json");
  }

  // - module websocket -
  if (a_modules[c_uclvar_module_websocket])
  {
    UCL_NODE_IMPORT_MODULE("websocket");
  }

  // - module jit -
  if (a_modules[c_uclvar_module_jit])
  {
    UCL_NODE_IMPORT_MODULE("jit");
  }

  parser.element_search();
  if (parser.error_code.used != 0)
  {
    parser.process_errors();
    return false;
  }

  // - initialize ucl variables (parser) -
  UclVar::Initialize(parser,a_modules);

  interpreter.create_from_script_parser(parser);

  // - set global pointer to interpreter -
  interpreter_ptr = &interpreter;

  interpreter.create_constant_and_static_locations();

  // - initialize ucl variables (interpreter) -
  UclVar::Initialize(interpreter,a_modules);

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

    // - set pointer to interpreter main thread -
    interpreter.main_thread_ptr = thread;
  }

  // - initialize UclVar thread -
  UclVar::InitThread(*thread);

  return true;
}/*}}}*/

bool UclNode::Clear()
{/*{{{*/

  // - release ucl variables -
  UclVar::Release(interpreter);

  // - release of location from stack -
  thread->release_stack_from(0);

  // - remove pointer to interpreter main thread -
  interpreter.main_thread_ptr = NULL;

  // - release of thread locations -
  thread->release_location_ptr((location_s *)thread->thread_location);

  // - release of thread blank and exception locations -
  thread->release_location_ptr((location_s *)thread->blank_location);
  thread->release_location_ptr((location_s *)thread->exception_location);

  // - remove of thread description from memory -
  thread->free_variables_clear();
  thread->clear();
  cfree(thread);

  interpreter.release_constant_and_static_locations();

  // - remove global pointer to interpreter -
  interpreter_ptr = NULL;

  interpreter.clear();

  // - release of parser -
  parser.clear();

  return true;
}/*}}}*/

