
@begin
include "uclang.h"
@end

// - global interpreter pointer -
interpreter_s *interpreter_ptr = NULL;

#if SYSTEM_TYPE_UNIX_SIGACTION == ENABLED
void term_signal_handler(int signum)
{/*{{{*/

  // - if interpreter not exist or its main thread is not running -
  if (interpreter_ptr == NULL || interpreter_ptr->main_thread_ptr == NULL)
  {
#if SYSTEM_TYPE_UNIX_SPAWNER == ENABLED
    if (g_spawner_running.value())
    {
      g_spawner_running.atomic_set(0);
    }
    else
#endif
    {
      // - just terminate -
      exit(1);
    }

    return;
  }

  // - retrieve thread object -
  interpreter_thread_s &it = *((interpreter_thread_s *)interpreter_ptr->main_thread_ptr);

  // - if this thread is main interpreter thread -
  if (pthread_self() == ((thread_s *)((location_s *)it.thread_location)->v_data_ptr)->thread)
  {
    // - execute signal handler -
    if (!it.handle_signal(signum))
    {
      if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
      {
        // - print exception message -
        exception_s *exception_ptr = (exception_s *)((location_s *)it.exception_location)->v_data_ptr;
        interpreter_ptr->print_exception_message(*exception_ptr);
      }
    }

    // - set interpreter terminate flag -
    interpreter_ptr->terminate.atomic_set(signum);
  }
}/*}}}*/
#endif

void *run_interpreter(void *data)
{/*{{{*/
  int return_value = 0;

  {
#if SYSTEM_TYPE_UNIX_SIGACTION == ENABLED

    // - create signal ignore action -
    struct sigaction ignore_action;
    ignore_action.sa_handler = SIG_IGN;
    sigemptyset(&ignore_action.sa_mask);
    ignore_action.sa_flags = 0;

    // - ignore SIGPIPE signal -
    sigaction(SIGPIPE,&ignore_action,NULL);

    // - create signal handler action -
    struct sigaction signal_term_action;
    signal_term_action.sa_handler = term_signal_handler;
    sigemptyset(&signal_term_action.sa_mask);
    signal_term_action.sa_flags = 0;

    struct sigaction old_action;

    // - set signal handlers -
    sigaction(SIGINT,NULL,&old_action);
    if (old_action.sa_handler != SIG_IGN)
      sigaction(SIGINT,&signal_term_action,NULL);

    sigaction(SIGTERM,NULL,&old_action);
    if (old_action.sa_handler != SIG_IGN)
      sigaction(SIGTERM,&signal_term_action,NULL);

    sigaction(SIGHUP,NULL,&old_action);
    if (old_action.sa_handler != SIG_IGN)
      sigaction(SIGHUP,&signal_term_action,NULL);
#endif

    // - init source -
    source_s source;
    source.init();

    // - init modules path -
    string_s mods_path;
    mods_path.init();

    // - init argument list -
    string_array_s arg_list;
    arg_list.init();

#if SYSTEM_TYPE == SYSTEM_TYPE_DSP
    int argc = 1;
    char *argv[] = {(char *)"main",NULL};

    // - fake program source for DSP -
    const char *dummy_src =
"class Main\n"
"{\n"
"  static public main(argv)\n"
"  {\n"
"    \"Hello world!\\n\".print();\n"
"\n"
"    return 0;\n"
"  }\n"
"}\n";

    // - initialize source structure -
    source.file_name.set(strlen("dummy"),"dummy");
    source.source_string.set(strlen(dummy_src),dummy_src);
#else
    int argc = (int)(t_ps_uint)((pointer *)data)[0];
    char **argv = (char **)((pointer *)data)[1];

    // - count of arguments removed by interpreter -
    int arg_idx = 1;

    const char *arg_mods_ptr = "-mods=";
    const int arg_mods_len = strlen(arg_mods_ptr);

#if SYSTEM_TYPE_UNIX_SPAWNER == ENABLED
    const char *arg_spawn_ptr = "-spawner=";
    const int arg_spawn_len = strlen(arg_spawn_ptr);

    const char *spawner_path = NULL;
#endif

    // - process interpreter arguments -
    if (arg_idx < argc)
    {
      do {
        char *arg_ptr = argv[arg_idx];

        // - test modules argument -
        if (strncmp(arg_ptr,arg_mods_ptr,arg_mods_len) == 0)
          mods_path.set(strlen(arg_ptr) - arg_mods_len,arg_ptr + arg_mods_len);
        
#if SYSTEM_TYPE_UNIX_SPAWNER == ENABLED
        // - test spawner argument -
        else if (strncmp(arg_ptr,arg_spawn_ptr,arg_spawn_len) == 0)
          spawner_path = arg_ptr + arg_spawn_len;
#endif

        // - argument was not recognized -
        else
        {
          break;
        }

      } while(++arg_idx < argc);
    }

    // - simple argument test -
    if (argc <= arg_idx)
    {
      fprintf(stderr,"%s: Expected argument with name of script\n",argv[0]);

      exit(22);
    }

    // - initialize source structure -
    source.file_name.set(strlen(argv[arg_idx]),argv[arg_idx]);
    if (!source.source_string.load_text_file(argv[arg_idx]))
    {
      fprintf(stderr,"%s: Cannot open source file \"%s\"\n",argv[0],argv[arg_idx]);

      mods_path.clear();
      source.clear();

      exit(2);
    }
#endif

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
      fprintf(stderr,"%s: Unsupported sizes of basic data types\n",argv[0]);

      mods_path.clear();
      source.clear();

      exit(125);
    }

    // - creation of parser object -
    script_parser_s parser;
    parser.init();

    debug_message_1(fprintf(stderr,"main: script_parser, initialization\n"); tm_mark_time());
    parser.initialize_parser(source,mods_path);
    debug_message_1(fprintf(stderr,"main: script_parser, initialization (%" HOST_LL_FORMAT "d us) DONE\n" MP_COMMA tm_time_diff()));

    mods_path.clear();
    source.clear();

    // - parse source script -
    debug_message_1(fprintf(stderr,"main: script_parser, source parse\n"); tm_mark_time());
    parser.parse_script(0);

    // - exist errors ? -
    if (parser.error_code.used != 0)
    {
      debug_message_1(fprintf(stderr,"main: script_parser, source parse (%" HOST_LL_FORMAT "d us) FAILED\n" MP_COMMA tm_time_diff()));
      parser.process_errors();
    }
    else
    {
      debug_message_1(fprintf(stderr,"main: script_parser, source parse (%" HOST_LL_FORMAT "d us) DONE\n" MP_COMMA tm_time_diff()));

      // - run process flag -
      bool run_process = true;

#if SYSTEM_TYPE_UNIX_SPAWNER == ENABLED

      // - if spawner path is set -
      if (spawner_path != NULL)
      {
        debug_message_1(fprintf(stderr,"main: script_parser, process modules\n"); tm_mark_time());
        parser.process_modules();

        if (parser.error_code.used != 0)
        {
          debug_message_1(fprintf(stderr,"main: script_parser, process modules (%" HOST_LL_FORMAT "d us) FAILED\n" MP_COMMA tm_time_diff()));
          parser.process_errors();

          // - reset run process flag -
          run_process = false;
        }
        else
        {
          // - run process spawner -
          int res;
          if ((res = run_spawner(argv[0],spawner_path,arg_list)) <= 0)
          {
            // - set return value -
            return_value = -res;

            // - reset run process flag -
            run_process = false;
          }
          else
          {
            // - update process cmdline buffer -
            {
              char *a_ptr = argv[1];
              char *a_ptr_end = argv[argc - 1] + strlen(argv[argc - 1]) + 1;
              memset(a_ptr,0,a_ptr_end - a_ptr);

              string_s *s_ptr = arg_list.data;
              string_s *s_ptr_end = s_ptr + arg_list.used;
              do {
                
                // - if there is no space left -
                if (a_ptr + s_ptr->size > a_ptr_end)
                {
                  break;
                }

                memcpy(a_ptr,s_ptr->data,s_ptr->size);
                a_ptr += s_ptr->size;

              } while(++s_ptr < s_ptr_end);
            }

            // - insert module name to module names array -
            unsigned name_idx = parser.module_names.get_idx(arg_list[0]);
            if (name_idx == c_idx_not_exist)
            {
              // - push module to module names -
              parser.module_names.push(arg_list[0]);

              // - set module import name position -
              parser.module_names_positions.push_blank();
              parser.module_names_positions.last().set(SET_SRC_POS(0,0),SET_SRC_POS(0,0));
            }
          }
        }
      }
      else
#endif
      // - initialize list of process arguments -
      {
        char **a_ptr = argv + arg_idx;
        char **a_ptr_end = argv + argc;

        do {
          arg_list.push_blank();
          arg_list.last().set(strlen(*a_ptr),*a_ptr);
        } while(++a_ptr < a_ptr_end);
      }

      // - if process was not canceled -
      if (run_process)
      {
        debug_message_1(fprintf(stderr,"main: script_parser, process modules\n"); tm_mark_time());
        parser.process_modules();

        if (parser.error_code.used != 0)
        {
          debug_message_1(fprintf(stderr,"main: script_parser, process modules (%" HOST_LL_FORMAT "d us) FAILED\n" MP_COMMA tm_time_diff()));
          parser.process_errors();
        }
        else
        {
          debug_message_1(fprintf(stderr,"main: script_parser, process modules (%" HOST_LL_FORMAT "d us) DONE\n" MP_COMMA tm_time_diff()));
          debug_message_1(fprintf(stderr,"main: script_parser, classes search\n"); tm_mark_time());
          parser.extended_classes_search();

          // - exist errors ? -
          if (parser.error_code.used != 0)
          {
            debug_message_1(fprintf(stderr,"main: script_parser, classes search (%" HOST_LL_FORMAT "d us) FAILED\n" MP_COMMA tm_time_diff()));
            parser.process_errors();
          }
          else
          {
            debug_message_1(fprintf(stderr,"main: script_parser, classes search (%" HOST_LL_FORMAT "d us) DONE\n" MP_COMMA tm_time_diff()));
            debug_message_1(fprintf(stderr,"main: script_parser, element search\n"); tm_mark_time());
            parser.element_search();

            // - exist errors ? -
            if (parser.error_code.used != 0)
            {
              debug_message_1(fprintf(stderr,"main: script_parser, element search (%" HOST_LL_FORMAT "d us) FAILED\n" MP_COMMA tm_time_diff()));
              parser.process_errors();
            }
            else
            {
              debug_message_1(fprintf(stderr,"main: script_parser, element search (%" HOST_LL_FORMAT "d us) DONE\n" MP_COMMA tm_time_diff()));

              //parser.DEBUG_show_variables();
              //parser.DEBUG_show_methods();
              //parser.DEBUG_show_classes();
              //parser.DEBUG_show_namespaces();

              //parser.DEBUG_show_init_expressions();
              //parser.DEBUG_show_method_flow_graphs();

              //parser.DEBUG_show_dot_format_method_expressions();
              //parser.DEBUG_show_dot_format_init_expressions();
              //parser.DEBUG_show_dot_format_method_flow_graphs();
              //parser.DEBUG_show_dot_format_class_inheritance();

              //parser.DEBUG_gen_ucl_description(stderr);

              debug_message_1(fprintf(stderr,"main: script_parser, intermediate code generation\n"); tm_mark_time());
              parser.generate_intermediate_code();

              // - exist errors ? -
              if (parser.error_code.used != 0)
              {
                debug_message_1(fprintf(stderr,"main: script_parser, intermediate code generation (%" HOST_LL_FORMAT "d us) FAILED\n" MP_COMMA tm_time_diff()));
                parser.process_errors();
              }
              else
              {
                debug_message_1(fprintf(stderr,"main: script parser, intermediate code generation (%" HOST_LL_FORMAT "d us) DONE\n" MP_COMMA tm_time_diff()));

                // - prints out intermediate code -
                //parser.DEBUG_show_static_im_code();
                //parser.DEBUG_show_class_im_codes();
                //parser.DEBUG_show_method_im_codes();

                interpreter_s interpreter;
                interpreter.init();

                debug_message_1(fprintf(stderr,"main: interpreter initialization from script parser\n"); tm_mark_time());
                interpreter.create_from_script_parser(parser);
                debug_message_1(fprintf(stderr,"main: interpreter initialization from script parser (%" HOST_LL_FORMAT "d us) DONE\n" MP_COMMA tm_time_diff()));

                // - set global pointer to interpreter -
                interpreter_ptr = &interpreter;

                debug_message_1(fprintf(stderr,"main: interpreter, creation of constants and locations\n"); tm_mark_time());
                interpreter.create_constant_and_static_locations();
                debug_message_1(fprintf(stderr,"main: interpreter, creation of constants and locations (%" HOST_LL_FORMAT "d us) DONE\n" MP_COMMA tm_time_diff()));

                // - prints defined locations of constants -
                //interpreter.DEBUG_print_const_locations();

                // - execute method defined by its parrent class name and its name -
                // - executed method must be defined as static -
                debug_message_1(fprintf(stderr,"main: interpreter, run of main thread\n"); tm_mark_time());
                return_value = interpreter.run_main_thread("Main","main#1",arg_list);
                debug_message_1(fprintf(stderr,"main: interpreter, run of main thread (%" HOST_LL_FORMAT "d us) DONE\n" MP_COMMA tm_time_diff()));

                debug_message_1(fprintf(stderr,"main: interpreter, static locations release\n"); tm_mark_time());
                interpreter.release_constant_and_static_locations();
                debug_message_1(fprintf(stderr,"main: interpreter, static locations release (%" HOST_LL_FORMAT "d us) DONE\n" MP_COMMA tm_time_diff()));

                // - remove global pointer to interpreter -
                interpreter_ptr = NULL;

                debug_message_1(fprintf(stderr,"main: interpreter remove\n"); tm_mark_time());
                interpreter.clear();
                debug_message_1(fprintf(stderr,"main: interpreter remove (%" HOST_LL_FORMAT "d us) DONE\n" MP_COMMA tm_time_diff()));
              }
            }
          }
        }
      }
    }

    // - release parser -
    debug_message_1(fprintf(stderr,"main: parser remove\n"); tm_mark_time());
    parser.clear();
    debug_message_1(fprintf(stderr,"main: parser remove (%" HOST_LL_FORMAT "d us) DONE\n" MP_COMMA tm_time_diff()));

    // - release argument list -
    arg_list.clear();
  }

#if !defined(ANDROID)
  // - exit with return code -
  exit(return_value);
#endif

  return (pointer)(t_ps_uint)return_value;
}/*}}}*/

#if SYSTEM_TYPE_UNIX_CHROME_NACL != ENABLED
int main(int argc,char **argv)
{/*{{{*/

  // - call main thread function -
#if THREAD_LIB == THREAD_LIB_DSP_TSK
  fprintf(stderr,"DSP main function ... nothing to do\n");
#else

  // - values given to main thread function -
  pointer mt_start_info[2] = {(pointer)(t_ps_uint)argc,(pointer)argv};

  run_interpreter(&mt_start_info);
#endif
}/*}}}*/
#endif

