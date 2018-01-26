
@begin
include "nacl_module.h"
@end

// - NACL indexes of built in classes -
unsigned c_bi_class_nacl = c_idx_not_exist;
unsigned c_bi_class_nacl_3d = c_idx_not_exist;
unsigned c_bi_class_core = c_idx_not_exist;
unsigned c_bi_class_time = c_idx_not_exist;
unsigned c_bi_class_console = c_idx_not_exist;
unsigned c_bi_class_message = c_idx_not_exist;
unsigned c_bi_class_net_address = c_idx_not_exist;

// - NACL module -
built_in_module_s module =
{/*{{{*/
  7,                    // Class count
  nacl_classes,         // Classes

  0,                    // Error base index
  8,                    // Error count
  nacl_error_strings,   // Error strings

  nacl_initialize,      // Initialize function
  nacl_print_exception, // Print exceptions function
};/*}}}*/

// - NACL classes -
built_in_class_s *nacl_classes[] =
{/*{{{*/
  &nacl_class,
  &nacl_3d_class,
  &core_class,
  &time_class,
  &console_class,
  &message_class,
  &net_address_class,
};/*}}}*/

// - NACL error strings -
const char *nacl_error_strings[] =
{/*{{{*/
  "error_NACL_OBJECT_ALREADY_CREATED",
  "error_NACL_WRONG_CALLBACK_DELEGATE",
  "error_NACL_3D_CONTEXT_CREATE_ERROR",
  "error_NACL_3D_CONTEXT_ALREADY_CREATED",
  "error_TIME_WRONG_INIT_STRING",
  "error_CONSOLE_LOG_LEVEL_ERROR",
  "error_NET_ADDRESS_ADDRESS_TYPE_ERROR",
  "error_NET_ADDRESS_UNRECOGNIZED_FAMILY",
};/*}}}*/

// - NACL initialize -
bool nacl_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize nacl class identifier -
  c_bi_class_nacl = class_base_idx++;

  // - initialize nacl_3d class identifier -
  c_bi_class_nacl_3d = class_base_idx++;

  // - initialize core class identifier -
  c_bi_class_core = class_base_idx++;

  // - initialize time class identifier -
  c_bi_class_time = class_base_idx++;

  // - initialize console class identifier -
  c_bi_class_console = class_base_idx++;

  // - initialize message class identifier -
  c_bi_class_message = class_base_idx++;

  // - initialize net_address class identifier -
  c_bi_class_net_address = class_base_idx++;

  return true;
}/*}}}*/

// - NACL print exception -
bool nacl_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_NACL_OBJECT_ALREADY_CREATED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nNACL object was already created\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_NACL_WRONG_CALLBACK_DELEGATE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong type of delegate for this NACL callback\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_NACL_3D_CONTEXT_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot create NACL 3D context\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_NACL_3D_CONTEXT_ALREADY_CREATED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nNACL 3D context was already created\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TIME_WRONG_INIT_STRING:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong date/time string \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CONSOLE_LOG_LEVEL_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUnrecognized requested console log level\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_NET_ADDRESS_ADDRESS_TYPE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nNetAddress address must be composed only from integers\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_NET_ADDRESS_UNRECOGNIZED_FAMILY:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUnrecognized net address family, %" HOST_LL_FORMAT "d address components\n", exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class NACL -
built_in_class_s nacl_class =
{/*{{{*/
  "Nacl",
  c_modifier_public | c_modifier_final,
  8, nacl_methods,
  0, nacl_variables,
  bic_nacl_consts,
  bic_nacl_init,
  bic_nacl_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s nacl_methods[] =
{/*{{{*/
  {
    "Nacl#0",
    c_modifier_public | c_modifier_final,
    bic_nacl_method_Nacl_0
  },
  {
    "OnDestroy#1",
    c_modifier_public | c_modifier_final,
    bic_nacl_method_OnDestroy_1
  },
  {
    "OnChangeView#1",
    c_modifier_public | c_modifier_final,
    bic_nacl_method_OnChangeView_1
  },
  {
    "OnChangeFocus#1",
    c_modifier_public | c_modifier_final,
    bic_nacl_method_OnChangeFocus_1
  },
  {
    "CallOnMainThread#3",
    c_modifier_public | c_modifier_final,
    bic_nacl_method_CallOnMainThread_3
  },
  {
    "Get3D#2",
    c_modifier_public | c_modifier_final,
    bic_nacl_method_Get3D_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_nacl_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_nacl_method_print_0
  },
};/*}}}*/

built_in_variable_s nacl_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_NACL_DELEGATE_CHECK(LOCATION,PARAM_CNT) \
{/*{{{*/\
\
  /* - retrieve delegate pointer - */\
  delegate_s *delegate_ptr = (delegate_s *)(LOCATION)->v_data_ptr;\
\
  /* - ERROR - */\
  if (delegate_ptr->param_cnt != PARAM_CNT)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_NACL_WRONG_CALLBACK_DELEGATE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
}/*}}}*/

#define BIC_NACL_DELEGATE(NAME,DLG_PTR_NAME,PARAM_CNT) \
{/*{{{*/\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
  /* - ERROR - */\
  if (src_0_location->v_type != c_bi_class_delegate)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
    new_exception->params.push(1);\
    new_exception->params.push(src_0_location->v_type);\
\
    return false;\
  }\
\
  BIC_NACL_DELEGATE_CHECK(src_0_location,PARAM_CNT);\
\
  /* - release previous delegate - */\
  if (DLG_PTR_NAME != nullptr)\
  {\
    it.release_location_ptr(DLG_PTR_NAME);\
  }\
\
  /* - register new delegate - */\
  src_0_location->v_reference_cnt.atomic_inc();\
  DLG_PTR_NAME = src_0_location;\
\
  BIC_SET_RESULT_DESTINATION();\
\
  return true;\
}/*}}}*/

void bic_nacl_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_nacl_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (void *)nullptr;
}/*}}}*/

void bic_nacl_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(nacl_it_ptr != nullptr);

  // - reset nacl interpreter thread pointer -
  nacl_it_ptr = nullptr;

  // - release nacl instance destroy delegate -
  if (nacl_destroy_dlg != nullptr)
  {
    it.release_location_ptr(nacl_destroy_dlg);
    nacl_destroy_dlg = nullptr;
  }

  // - release nacl instance change view delegate -
  if (nacl_change_view_dlg != nullptr)
  {
    it.release_location_ptr(nacl_change_view_dlg);
    nacl_change_view_dlg = nullptr;
  }

  // - release nacl instance change focus delegate -
  if (nacl_change_focus_dlg != nullptr)
  {
    it.release_location_ptr(nacl_change_focus_dlg);
    nacl_change_focus_dlg = nullptr;
  }
}/*}}}*/

bool bic_nacl_method_Nacl_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/

  // - ERROR -
  if (nacl_it_ptr != nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_NACL_OBJECT_ALREADY_CREATED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set nacl interpreter thread pointer -
  nacl_it_ptr = &it;

  return true;
}/*}}}*/

bool bic_nacl_method_OnDestroy_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_NACL_DELEGATE("OnDestroy#1",nacl_destroy_dlg,0);
}/*}}}*/

bool bic_nacl_method_OnChangeView_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_NACL_DELEGATE("OnChangeView#1",nacl_change_view_dlg,0);
}/*}}}*/

bool bic_nacl_method_OnChangeFocus_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_NACL_DELEGATE("OnChangeFocus#1",nacl_change_focus_dlg,0);
}/*}}}*/

bool bic_nacl_method_CallOnMainThread_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);

  long long int delay;

  if (!it.retrieve_integer(src_0_location,delay) ||
      src_1_location->v_type != c_bi_class_delegate)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("CallOnMainThread#3");
    new_exception->params.push(3);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);

    return false;
  }

  BIC_NACL_DELEGATE_CHECK(src_1_location,1);

  // - create callback data object -
  callback_data_s *cd_ptr = (callback_data_s *)cmalloc(sizeof(callback_data_s));
  cd_ptr->init();

  // - set delegate pointer -
  src_1_location->v_reference_cnt.atomic_inc();
  cd_ptr->delegate_ptr = src_1_location;

  // - set user data pointer -
  src_2_location->v_reference_cnt.atomic_inc();
  cd_ptr->user_data_ptr = src_2_location;

  PP_CompletionCallback cc = PP_MakeCompletionCallback(on_completion_callback,cd_ptr);
  ppb_core_iface->CallOnMainThread(delay,cc,0);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_nacl_method_Get3D_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int width;
  long long int height;

  if (!it.retrieve_integer(src_0_location,width) ||
      !it.retrieve_integer(src_1_location,height))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Get3D#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  // - ERROR -
  if (pp_3d_context != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_NACL_3D_CONTEXT_ALREADY_CREATED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (!glInitializePPAPI(ppb_get_iface))
  {
    exception_s::throw_exception(it,module.error_base + c_error_NACL_3D_CONTEXT_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  int32_t attribs[] = {
    PP_GRAPHICS3DATTRIB_ALPHA_SIZE, 8,
    PP_GRAPHICS3DATTRIB_DEPTH_SIZE, 24,
    PP_GRAPHICS3DATTRIB_STENCIL_SIZE, 8,
    PP_GRAPHICS3DATTRIB_SAMPLES, 0,
    PP_GRAPHICS3DATTRIB_SAMPLE_BUFFERS, 0,
    PP_GRAPHICS3DATTRIB_WIDTH, width,
    PP_GRAPHICS3DATTRIB_HEIGHT, height,
    PP_GRAPHICS3DATTRIB_NONE
  };

  // - create and initialize 3D rendering context -
  pp_3d_context = ppb_graphics_3d_iface->Create(pp_inst,0,attribs);

  // - ERROR -
  if (pp_3d_context == 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_NACL_3D_CONTEXT_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - bind graphics to display surface -
  int res = ppb_inst_iface->BindGraphics(pp_inst,pp_3d_context);

  // - ERROR -
  if (res == PP_FALSE)
  {
    // - reset current graphic context -
    glSetCurrentContextPPAPI(0);

    exception_s::throw_exception(it,module.error_base + c_error_NACL_3D_CONTEXT_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set 3d context as current graphic context -
  glSetCurrentContextPPAPI(pp_3d_context);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_nacl_3d,nullptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_nacl_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Nacl"),"Nacl");
  );

  return true;
}/*}}}*/

bool bic_nacl_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Nacl");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class NACL_3D -
built_in_class_s nacl_3d_class =
{/*{{{*/
  "Nacl3D",
  c_modifier_public | c_modifier_final,
  4, nacl_3d_methods,
  0, nacl_3d_variables,
  bic_nacl_3d_consts,
  bic_nacl_3d_init,
  bic_nacl_3d_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s nacl_3d_methods[] =
{/*{{{*/
  {
    "SetCurrentContext#0",
    c_modifier_public | c_modifier_final,
    bic_nacl_3d_method_SetCurrentContext_0
  },
  {
    "SwapBuffers#2",
    c_modifier_public | c_modifier_final,
    bic_nacl_3d_method_SwapBuffers_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_nacl_3d_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_nacl_3d_method_print_0
  },
};/*}}}*/

built_in_variable_s nacl_3d_variables[] =
{/*{{{*/
};/*}}}*/

void bic_nacl_3d_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_nacl_3d_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (void *)nullptr;
}/*}}}*/

void bic_nacl_3d_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(pp_3d_context != 0);

  // - unbind graphics from current display surface -
  ppb_inst_iface->BindGraphics(pp_inst,0);

  // - reset nacl 3d context -
  ppb_core_iface->ReleaseResource(pp_3d_context);
  pp_3d_context = 0;
}/*}}}*/

bool bic_nacl_3d_method_SetCurrentContext_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/

  // - set 3d context as current graphic context -
  glSetCurrentContextPPAPI(pp_3d_context);

  return true;
}/*}}}*/

bool bic_nacl_3d_method_SwapBuffers_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  if (src_0_location->v_type != c_bi_class_delegate)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("SwapBuffers#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  BIC_NACL_DELEGATE_CHECK(src_0_location,1);

  // - create callback data object -
  callback_data_s *cd_ptr = (callback_data_s *)cmalloc(sizeof(callback_data_s));
  cd_ptr->init();

  // - set delegate pointer -
  src_0_location->v_reference_cnt.atomic_inc();
  cd_ptr->delegate_ptr = src_0_location;

  // - set user data pointer -
  src_1_location->v_reference_cnt.atomic_inc();
  cd_ptr->user_data_ptr = src_1_location;

  PP_CompletionCallback cc = PP_MakeCompletionCallback(on_completion_callback,cd_ptr);
  ppb_graphics_3d_iface->SwapBuffers(pp_3d_context,cc);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_nacl_3d_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Nacl3D"),"Nacl3D");
  );

  return true;
}/*}}}*/

bool bic_nacl_3d_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Nacl3D");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class CORE -
built_in_class_s core_class =
{/*{{{*/
  "Core",
  c_modifier_public | c_modifier_final,
  4, core_methods,
  0, core_variables,
  bic_core_consts,
  bic_core_init,
  bic_core_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s core_methods[] =
{/*{{{*/
  {
    "time#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_core_method_time_0
  },
  {
    "time_ticks#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_core_method_time_ticks_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_core_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_core_method_print_0
  },
};/*}}}*/

built_in_variable_s core_variables[] =
{/*{{{*/
};/*}}}*/

void bic_core_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_core_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_core_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_core_method_time_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  PP_Time time = ppb_core_iface->GetTime();

  BIC_SIMPLE_SET_RES(c_bi_class_time,time);

  return true;
}/*}}}*/

bool bic_core_method_time_ticks_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  double ticks = ppb_core_iface->GetTimeTicks();

  BIC_SIMPLE_SET_RES(c_bi_class_float,ticks);

  return true;
}/*}}}*/

bool bic_core_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Core"),"Core");
  );

  return true;
}/*}}}*/

bool bic_core_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Core");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class TIME -
built_in_class_s time_class =
{/*{{{*/
  "Time",
  c_modifier_public | c_modifier_final,
  12, time_methods,
  0, time_variables,
  bic_time_consts,
  bic_time_init,
  bic_time_clear,
  bic_time_compare,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s time_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_time_operator_binary_equal
  },
  {
    "Time#0",
    c_modifier_public | c_modifier_final,
    bic_time_method_Time_0
  },
  {
    "Time#1",
    c_modifier_public | c_modifier_final,
    bic_time_method_Time_1
  },
  {
    "value#0",
    c_modifier_public | c_modifier_final,
    bic_time_method_value_0
  },
  {
    "seconds#0",
    c_modifier_public | c_modifier_final,
    bic_time_method_seconds_0
  },
  {
    "minutes#0",
    c_modifier_public | c_modifier_final,
    bic_time_method_minutes_0
  },
  {
    "hours#0",
    c_modifier_public | c_modifier_final,
    bic_time_method_hours_0
  },
  {
    "days#0",
    c_modifier_public | c_modifier_final,
    bic_time_method_days_0
  },
  {
    "datetime#0",
    c_modifier_public | c_modifier_final,
    bic_time_method_datetime_0
  },
  {
    "compare#1",
    c_modifier_public | c_modifier_final,
    bic_time_method_compare_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_time_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_time_method_print_0
  },
};/*}}}*/

built_in_variable_s time_variables[] =
{/*{{{*/
};/*}}}*/

void bic_time_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_time_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (PP_Time)0.0;
}/*}}}*/

void bic_time_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

int bic_time_compare(location_s *first_loc,location_s *second_loc)
{/*{{{*/
  PP_Time first = (PP_Time)first_loc->v_data_ptr;
  PP_Time second = (PP_Time)second_loc->v_data_ptr;

  return first < second ? -1 : (first > second ? 1 : 0);
}/*}}}*/

bool bic_time_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_time_method_Time_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  dst_location->v_data_ptr = (PP_Time)ppb_core_iface->GetTime();

  return true;
}/*}}}*/

bool bic_time_method_Time_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  PP_Time time;

  switch (src_0_location->v_type)
  {
    case c_bi_class_integer:
    {
      long long int nanosec = (long long int)src_0_location->v_data_ptr;
      TIME_NANOSEC_TO_DOUBLE(nanosec,time);
    }
    break;

    case c_bi_class_float:
      time = (double)src_0_location->v_data_ptr;
      break;

    case c_bi_class_string:
    {
      string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

      // - ERROR -
      if (string_ptr->size != 15)
      {
        exception_s::throw_exception(it,module.error_base + c_error_TIME_WRONG_INIT_STRING,operands[c_source_pos_idx],src_0_location);
        return false;
      }

      datetime_s dt;

      char str[15];
      memcpy(str,string_ptr->data,15);

#define BIC_TIME_RETRIEVE_COMP(TARGET,START,END) \
{/*{{{*/\
  char tmp_char = str[END];\
  str[END] = '\0';\
  \
  char *end_ptr;\
  TARGET = strtol(str + START,&end_ptr,10);\
  \
  /* - ERROR - */\
  if (end_ptr != str + END)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_TIME_WRONG_INIT_STRING,operands[c_source_pos_idx],src_0_location);\
    return false;\
  }\
  \
  str[END] = tmp_char;\
}/*}}}*/

      dt.nsec = 0;
      dt.usec = 0;
      dt.msec = 0;

      BIC_TIME_RETRIEVE_COMP(dt.sec  ,12,14);
      BIC_TIME_RETRIEVE_COMP(dt.min  ,10,12);
      BIC_TIME_RETRIEVE_COMP(dt.hour ,8 ,10);
      BIC_TIME_RETRIEVE_COMP(dt.day  ,6 ,8);
      BIC_TIME_RETRIEVE_COMP(dt.month,4 ,6);
      BIC_TIME_RETRIEVE_COMP(dt.year ,0 ,4);

      // - ERROR -
      if (dt.year < 1970 || dt.month < 1 || dt.month > 12 || dt.day < 1 ||
          dt.day > c_month_days_arr[datetime_s::is_leap_year(dt.year)][dt.month - 1] ||
          dt.hour >= 24 || dt.min >= 60 || dt.sec >= 60)
      {
        exception_s::throw_exception(it,module.error_base + c_error_TIME_WRONG_INIT_STRING,operands[c_source_pos_idx],src_0_location);
        return false;
      }

      // - convert datetime to time value -
      long long unsigned nanosec;
      dt.to_nanosec(nanosec);
      TIME_NANOSEC_TO_DOUBLE(nanosec,time);
    }
    break;

    default:
    {
      // - process time value -
      if (src_0_location->v_type == c_bi_class_time)
      {
        time = (PP_Time)src_0_location->v_data_ptr;
      }

      // - ERROR -
      else
      {
        exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
        BIC_EXCEPTION_PUSH_METHOD_RI("Time#1");
        new_exception->params.push(1);
        new_exception->params.push(src_0_location->v_type);

        return false;
      }
    }
  }

  dst_location->v_data_ptr = (PP_Time)time;

  return true;
}/*}}}*/

bool bic_time_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  PP_Time time = (PP_Time)dst_location->v_data_ptr;

  BIC_SIMPLE_SET_RES(c_bi_class_float,time);

  return true;
}/*}}}*/

bool bic_time_method_seconds_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  PP_Time time = (PP_Time)dst_location->v_data_ptr;
  long long int result = (long long int)time;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_time_method_minutes_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  PP_Time time = (PP_Time)dst_location->v_data_ptr;
  long long int result = ((long long int)time)/60;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_time_method_hours_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  PP_Time time = (PP_Time)dst_location->v_data_ptr;
  long long int result = ((long long int)time)/3600;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_time_method_days_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  PP_Time time = (PP_Time)dst_location->v_data_ptr;
  long long int result = ((long long int)time)/86400;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_time_method_datetime_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  PP_Time time = (PP_Time)dst_location->v_data_ptr;

  long long unsigned nanosec;
  TIME_DOUBLE_TO_NANOSEC(time,nanosec);

  // - convert time to date time structure -
  datetime_s datetime;
  datetime.from_nanosec(nanosec);

  // - create new array pointer -
  pointer_array_s *array_ptr = it.get_new_array_ptr();
  array_ptr->copy_resize(c_datetime_value_cnt);
  array_ptr->used = array_ptr->size;

  pointer *l_ptr = array_ptr->data;
  pointer *l_ptr_end = array_ptr->data + array_ptr->used;
  do {
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,0)

    *l_ptr = (pointer)new_location;

  } while(++l_ptr < l_ptr_end);

  // - set system time values -
  ((location_s *)array_ptr->data[0])->v_data_ptr = (long long int)datetime.year;
  ((location_s *)array_ptr->data[1])->v_data_ptr = (long long int)datetime.month;
  ((location_s *)array_ptr->data[2])->v_data_ptr = (long long int)datetime.day;
  ((location_s *)array_ptr->data[3])->v_data_ptr = (long long int)datetime.wday;
  ((location_s *)array_ptr->data[4])->v_data_ptr = (long long int)datetime.hour;
  ((location_s *)array_ptr->data[5])->v_data_ptr = (long long int)datetime.min;
  ((location_s *)array_ptr->data[6])->v_data_ptr = (long long int)datetime.sec;
  ((location_s *)array_ptr->data[7])->v_data_ptr = (long long int)datetime.msec;
  ((location_s *)array_ptr->data[8])->v_data_ptr = (long long int)datetime.usec;
  ((location_s *)array_ptr->data[9])->v_data_ptr = (long long int)datetime.nsec;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_time_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  if (src_0_location->v_type == c_bi_class_time)
  {
    PP_Time first = (PP_Time)dst_location->v_data_ptr;
    PP_Time second = (PP_Time)src_0_location->v_data_ptr;

    result = first < second ? -1 : (first > second ? 1 : 0);
  }
  else
  {
    result = c_bi_class_time < src_0_location->v_type ? -1 : 1;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_time_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING(

    PP_Time time = (PP_Time)dst_location->v_data_ptr;

    // - convert time to datetime structure -
    datetime_s datetime;
    datetime.from_seconds((long long unsigned)time);

    string_ptr->setf("%4.4hu/%2.2hhu/%2.2hhu %2.2hhu:%2.2hhu:%2.2hhu"
      ,datetime.year,datetime.month,datetime.day,datetime.hour,datetime.min,datetime.sec);
  );

  return true;
}/*}}}*/

bool bic_time_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  PP_Time time = (PP_Time)dst_location->v_data_ptr;

  // - convert time to datetime structure -
  datetime_s datetime;
  datetime.from_seconds((long long unsigned)time);

  printf("%4.4hu/%2.2hhu/%2.2hhu %2.2hhu:%2.2hhu:%2.2hhu"
      ,datetime.year,datetime.month,datetime.day,datetime.hour,datetime.min,datetime.sec);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

// - class CONSOLE -
built_in_class_s console_class =
{/*{{{*/
  "Console",
  c_modifier_public | c_modifier_final,
  7, console_methods,
  4, console_variables,
  bic_console_consts,
  bic_console_init,
  bic_console_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s console_methods[] =
{/*{{{*/
  {
    "tip#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_console_method_tip_1
  },
  {
    "log#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_console_method_log_1
  },
  {
    "log#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_console_method_log_2
  },
  {
    "warning#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_console_method_warning_1
  },
  {
    "error#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_console_method_error_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_console_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_console_method_print_0
  },
};/*}}}*/

built_in_variable_s console_variables[] =
{/*{{{*/
  {
    "LOGLEVEL_TIP",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "LOGLEVEL_LOG",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "LOGLEVEL_WARNING",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "LOGLEVEL_ERROR",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
};/*}}}*/

#define CONSOLE_LOG(CLASS_IDX,NAME,LOGLEVEL) \
{/*{{{*/\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
  /* - ERROR - */\
  if (src_0_location->v_type != c_bi_class_string)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,CLASS_IDX,NAME);\
    new_exception->params.push(1);\
    new_exception->params.push(src_0_location->v_type);\
\
    return false;\
  }\
\
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;\
\
  PP_Var pp_str;\
  PP_FROM_STRING(string_ptr,pp_str);\
  ppb_console_iface->Log(pp_inst,LOGLEVEL,pp_str);\
  PP_RELEASE(pp_str);\
\
  BIC_SET_RESULT_BLANK();\
\
  return true;\
}/*}}}*/

void bic_console_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert console loglevel constants -
  {
    const_locations.push_blanks(4);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 4);

#define CREATE_CONSOLE_LOGLEVEL_BIC_STATIC(LOGLEVEL)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)LOGLEVEL;\
  cv_ptr++;

    CREATE_CONSOLE_LOGLEVEL_BIC_STATIC(PP_LOGLEVEL_TIP);
    CREATE_CONSOLE_LOGLEVEL_BIC_STATIC(PP_LOGLEVEL_LOG);
    CREATE_CONSOLE_LOGLEVEL_BIC_STATIC(PP_LOGLEVEL_WARNING);
    CREATE_CONSOLE_LOGLEVEL_BIC_STATIC(PP_LOGLEVEL_ERROR);
  }
}/*}}}*/

void bic_console_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_console_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_console_method_tip_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  CONSOLE_LOG(c_bi_class_console,"tip#1",PP_LOGLEVEL_TIP);
}/*}}}*/

bool bic_console_method_log_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  CONSOLE_LOG(c_bi_class_console,"log#1",PP_LOGLEVEL_LOG);
}/*}}}*/

bool bic_console_method_log_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int log_level;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,log_level) ||
      src_1_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_console,"log#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  switch (log_level)
  {
    case PP_LOGLEVEL_TIP:
    case PP_LOGLEVEL_LOG:
    case PP_LOGLEVEL_WARNING:
    case PP_LOGLEVEL_ERROR:
      break;

    // - ERROR -
    default:
      exception_s::throw_exception(it,module.error_base + c_error_CONSOLE_LOG_LEVEL_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
  }

  string_s *string_ptr = (string_s *)src_1_location->v_data_ptr;

  PP_Var pp_str;
  PP_FROM_STRING(string_ptr,pp_str);
  ppb_console_iface->Log(pp_inst,(PP_LogLevel)log_level,pp_str);
  PP_RELEASE(pp_str);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_console_method_warning_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  CONSOLE_LOG(c_bi_class_console,"warning#1",PP_LOGLEVEL_WARNING);
}/*}}}*/

bool bic_console_method_error_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  CONSOLE_LOG(c_bi_class_console,"error#1",PP_LOGLEVEL_ERROR);
}/*}}}*/

bool bic_console_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Console"),"Console");
  );

  return true;
}/*}}}*/

bool bic_console_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Console");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class MESSAGE -
built_in_class_s message_class =
{/*{{{*/
  "Message",
  c_modifier_public | c_modifier_final,
  3, message_methods,
  0, message_variables,
  bic_message_consts,
  bic_message_init,
  bic_message_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s message_methods[] =
{/*{{{*/
  {
    "post#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_message_method_post_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_message_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_message_method_print_0
  },
};/*}}}*/

built_in_variable_s message_variables[] =
{/*{{{*/
  {
    "LOGLEVEL_TIP",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "LOGLEVEL_LOG",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "LOGLEVEL_WARNING",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "LOGLEVEL_ERROR",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
};/*}}}*/

void bic_message_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_message_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_message_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_message_method_post_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_message,"post#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  PP_Var pp_str;
  PP_FROM_STRING(string_ptr,pp_str);
  ppb_message_iface->PostMessage(pp_inst,pp_str);
  PP_RELEASE(pp_str);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_message_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Message"),"Message");
  );

  return true;
}/*}}}*/

bool bic_message_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Message");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class NET_ADDRESS -
built_in_class_s net_address_class =
{/*{{{*/
  "NetAddress",
  c_modifier_public | c_modifier_final,
  5, net_address_methods,
  3, net_address_variables,
  bic_net_address_consts,
  bic_net_address_init,
  bic_net_address_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s net_address_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_net_address_operator_binary_equal
  },
  {
    "NetAddress#2",
    c_modifier_public | c_modifier_final,
    bic_net_address_method_NetAddress_2
  },
  {
    "family#0",
    c_modifier_public | c_modifier_final,
    bic_net_address_method_family_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_net_address_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_net_address_method_print_0
  },
};/*}}}*/

built_in_variable_s net_address_variables[] =
{/*{{{*/
  {
    "FAMILY_UNSPECIFIED",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "FAMILY_IPV4",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "FAMILY_IPV6",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
};/*}}}*/

void bic_net_address_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert net address family types constants -
  {
    const_locations.push_blanks(3);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 3);

#define CREATE_NET_ADDRESS_FAMILY_TYPE_BIC_STATIC(FAMILY_TYPE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)FAMILY_TYPE;\
  cv_ptr++;

    CREATE_NET_ADDRESS_FAMILY_TYPE_BIC_STATIC(PP_NETADDRESS_FAMILY_UNSPECIFIED);
    CREATE_NET_ADDRESS_FAMILY_TYPE_BIC_STATIC(PP_NETADDRESS_FAMILY_IPV4);
    CREATE_NET_ADDRESS_FAMILY_TYPE_BIC_STATIC(PP_NETADDRESS_FAMILY_IPV6);
  }
}/*}}}*/

void bic_net_address_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (PP_Resource)0;
}/*}}}*/

void bic_net_address_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  PP_Resource pp_res = (PP_Resource)location_ptr->v_data_ptr;

  if (pp_res != 0)
  {
    ppb_core_iface->ReleaseResource(pp_res);
  }
}/*}}}*/

bool bic_net_address_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_net_address_method_NetAddress_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int port;

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_array ||
      !it.retrieve_integer(src_1_location,port))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("NetAddress#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  pointer_array_s *array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

#define BIC_NET_ADDRESS_SET_ADDRESS \
{/*{{{*/\
  pointer *p_ptr = array_ptr->data;\
  pointer *p_ptr_end = p_ptr + array_ptr->used;\
  uint8_t *a_ptr = addr.addr;\
  do {\
    location_s *location = (location_s *)*p_ptr;\
\
    /* - ERROR - */\
    if (location->v_type != c_bi_class_integer)\
    {\
      exception_s::throw_exception(it,module.error_base + c_error_NET_ADDRESS_ADDRESS_TYPE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      return false;\
    }\
    \
    *a_ptr = (long long int)location->v_data_ptr;\
  } while(++a_ptr,++p_ptr < p_ptr_end);\
\
  addr.port = port;\
}/*}}}*/

  PP_Resource pp_addr = 0;

  switch (array_ptr->used)
  {
  // - initialize by IPv4 address -
  case 4:
    {
      PP_NetAddress_IPv4 addr;
      BIC_NET_ADDRESS_SET_ADDRESS;
      pp_addr = ppb_net_addr_iface->CreateFromIPv4Address(pp_inst,&addr);
    }
    break;

  // - initialize by IPv6 address -
  case 16:
    {
      PP_NetAddress_IPv6 addr;
      BIC_NET_ADDRESS_SET_ADDRESS;
      pp_addr = ppb_net_addr_iface->CreateFromIPv6Address(pp_inst,&addr);
    }
    break;

  // - ERROR -
  default:
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_NET_ADDRESS_UNRECOGNIZED_FAMILY,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(array_ptr->used);

    return false;
  }

  dst_location->v_data_ptr = (PP_Resource)pp_addr;

  return true;
}/*}}}*/

bool bic_net_address_method_family_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  PP_Resource pp_res = (PP_Resource)dst_location->v_data_ptr;
  long long int result = ppb_net_addr_iface->GetFamily(pp_res);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_net_address_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  PP_Resource pp_res = (PP_Resource)dst_location->v_data_ptr;
  PP_Var pp_str = ppb_net_addr_iface->DescribeAsString(pp_res,PP_TRUE);

  string_s *string_ptr = it.get_new_string_ptr();
  PP_TO_STRING(pp_str,string_ptr);
  PP_RELEASE(pp_str);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_net_address_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  PP_Resource pp_res = (PP_Resource)dst_location->v_data_ptr;
  PP_Var pp_str = ppb_net_addr_iface->DescribeAsString(pp_res,PP_TRUE);

  PP_STRING_FWRITE(pp_str,stdout);
  PP_RELEASE(pp_str);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

