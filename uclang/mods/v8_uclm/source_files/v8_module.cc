
@begin
include "v8_module.h"
@end

// - V8 indexes of built in classes -
unsigned c_bi_class_v8_engine = c_idx_not_exist;
unsigned c_bi_class_v8_context = c_idx_not_exist;
unsigned c_bi_class_v8_script = c_idx_not_exist;
unsigned c_bi_class_v8_heap_stat = c_idx_not_exist;
unsigned c_bi_class_v8_object = c_idx_not_exist;
unsigned c_bi_class_v8_reference = c_idx_not_exist;

// - V8 indexes of remote classes -
unsigned c_rm_class_dict = c_idx_not_exist;

// - V8 module -
built_in_module_s module =
{/*{{{*/
  6,                   // Class count
  v8_classes,          // Classes

  0,                   // Error base index
  14,                  // Error count
  v8_error_strings,    // Error strings

  v8_initialize,       // Initialize function
  v8_print_exception,  // Print exceptions function
};/*}}}*/

// - V8 classes -
built_in_class_s *v8_classes[] =
{/*{{{*/
  &v8_engine_class,
  &v8_context_class,
  &v8_script_class,
  &v8_heap_stat_class,
  &v8_object_class,
  &v8_reference_class,
};/*}}}*/

// - V8 error strings -
const char *v8_error_strings[] =
{/*{{{*/
  "error_V8_SCRIPT_COMPILE_ERROR",
  "error_V8_SCRIPT_EXECUTE_ERROR",
  "error_V8_OBJECT_INVOKE_METHOD_ERROR",
  "error_V8_OBJECT_INVOKE_METHOD_WRONG_PARAMETER",
  "error_V8_OBJECT_MEMBER_SELECT_ERROR",
  "error_V8_OBJECT_WRONG_OBJECT_REFERENCE",
  "error_V8_OBJECT_CREATE_ERROR",
  "error_V8_OBJECT_VALUE_ERROR",
  "error_V8_OBJECT_HAS_PROP_ERROR",
  "error_V8_OBJECT_GET_PROP_ERROR",
  "error_V8_OBJECT_SET_PROP_ERROR",
  "error_V8_OBJECT_DEL_PROP_ERROR",
  "error_V8_OBJECT_PROP_NAMES_ERROR",
  "error_V8_OBJECT_LENGTH_ERROR",
};/*}}}*/

// - V8 initialize -
bool v8_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize v8_engine class identifier -
  c_bi_class_v8_engine = class_base_idx++;

  // - initialize v8_context class identifier -
  c_bi_class_v8_context = class_base_idx++;

  // - initialize v8_script class identifier -
  c_bi_class_v8_script = class_base_idx++;

  // - initialize v8_heap_stat class identifier -
  c_bi_class_v8_heap_stat = class_base_idx++;

  // - initialize v8_object class identifier -
  c_bi_class_v8_object = class_base_idx++;

  // - initialize v8_reference class identifier -
  c_bi_class_v8_reference = class_base_idx++;

  // - retrieve remote dict class index -
  c_rm_class_dict = sp.resolve_class_idx_by_name("Dict",c_idx_not_exist);

  // - ERROR -
  if (c_rm_class_dict == c_idx_not_exist)
  {
    sp.error_code.push(ei_module_cannot_find_remote_class);
    sp.error_code.push(sp.module_names_positions[sp.module_idx].ui_first);
    sp.error_code.push(sp.module_idx);

    return false;
  }

  return true;
}/*}}}*/

// - V8 print exception -
bool v8_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_V8_SCRIPT_COMPILE_ERROR:
    {
      pointer_array_s *array_ptr = (pointer_array_s *)((location_s *)exception.obj_location)->v_data_ptr;
      string_s *error_string = (string_s *)((location_s *)array_ptr->data[0])->v_data_ptr;
      string_s *line_string = (string_s *)((location_s *)array_ptr->data[1])->v_data_ptr;
      string_s *res_string = (string_s *)((location_s *)array_ptr->data[2])->v_data_ptr;

      fprintf(stderr," ---------------------------------------- \n");
      fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
      print_error_line(source.source_string,source_pos);
      fprintf(stderr,"\nV8 script compile error: in file: \"%s\" on line: %" HOST_LL_FORMAT "d\n",res_string->data,exception.params[0]);
      print_error_show_line(*line_string,exception.params[1]);
      fprintf(stderr,"%s\n",error_string->data);
      fprintf(stderr," ---------------------------------------- \n");
    }
    break;
  case c_error_V8_SCRIPT_EXECUTE_ERROR:
    {
      pointer_array_s *array_ptr = (pointer_array_s *)((location_s *)exception.obj_location)->v_data_ptr;
      string_s *error_string = (string_s *)((location_s *)array_ptr->data[0])->v_data_ptr;
      string_s *line_string = (string_s *)((location_s *)array_ptr->data[1])->v_data_ptr;
      string_s *res_string = (string_s *)((location_s *)array_ptr->data[2])->v_data_ptr;

      fprintf(stderr," ---------------------------------------- \n");
      fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
      print_error_line(source.source_string,source_pos);
      fprintf(stderr,"\nV8 script runtime error: in file: \"%s\" on line: %" HOST_LL_FORMAT "d\n",res_string->data,exception.params[0]);
      print_error_show_line(*line_string,exception.params[1]);
      fprintf(stderr,"%s\n",error_string->data);
      fprintf(stderr," ---------------------------------------- \n");
    }
    break;
  case c_error_V8_OBJECT_INVOKE_METHOD_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while invoking V8 object method\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_V8_OBJECT_INVOKE_METHOD_WRONG_PARAMETER:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot process parameter %" HOST_LL_FORMAT "d of v8 object method\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_V8_OBJECT_MEMBER_SELECT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while selecting member of V8 object\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_V8_OBJECT_WRONG_OBJECT_REFERENCE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong reference to V8 object\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_V8_OBJECT_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating V8 object\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_V8_OBJECT_VALUE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while retrieving V8 object value\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_V8_OBJECT_HAS_PROP_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot test if V8 object has property\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_V8_OBJECT_GET_PROP_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot get property of V8 object\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_V8_OBJECT_SET_PROP_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot set property of V8 object\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_V8_OBJECT_DEL_PROP_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot delete property of V8 object\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_V8_OBJECT_PROP_NAMES_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot retrieve names of V8 object properties\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_V8_OBJECT_LENGTH_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot retrieve length of V8 object\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class V8_ENGINE -
built_in_class_s v8_engine_class =
{/*{{{*/
  "V8Engine",
  c_modifier_public | c_modifier_final,
  5, v8_engine_methods,
  0, v8_engine_variables,
  bic_v8_engine_consts,
  bic_v8_engine_init,
  bic_v8_engine_clear,
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

built_in_method_s v8_engine_methods[] =
{/*{{{*/
  {
    "is_dead#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_v8_engine_method_is_dead_0
  },
  {
    "version#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_v8_engine_method_version_0
  },
  {
    "notify_idle#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_v8_engine_method_notify_idle_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_v8_engine_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_v8_engine_method_print_0
  },
};/*}}}*/

built_in_variable_s v8_engine_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_v8_engine_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_v8_engine_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_v8_engine_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_v8_engine_method_is_dead_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  long long int result = V8::IsDead();

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_v8_engine_method_version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  const char *version = V8::GetVersion();

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(version),version);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_v8_engine_method_notify_idle_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
hint:retrieve_integer
>
class c_bi_class_v8_engine
method notify_idle
static_method
; @end

  V8::IdleNotification(hint);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_v8_engine_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("V8Engine"),"V8Engine");
  );

  return true;
}/*}}}*/

bool bic_v8_engine_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("V8Engine");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class V8_CONTEXT -
built_in_class_s v8_context_class =
{/*{{{*/
  "V8Context",
  c_modifier_public | c_modifier_final,
  7, v8_context_methods,
  0, v8_context_variables,
  bic_v8_context_consts,
  bic_v8_context_init,
  bic_v8_context_clear,
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

built_in_method_s v8_context_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_v8_context_operator_binary_equal
  },
  {
    "V8Context#0",
    c_modifier_public | c_modifier_final,
    bic_v8_context_method_V8Context_0
  },
  {
    "enter#0",
    c_modifier_public | c_modifier_final,
    bic_v8_context_method_enter_0
  },
  {
    "exit#0",
    c_modifier_public | c_modifier_final,
    bic_v8_context_method_exit_0
  },
  {
    "global_object#0",
    c_modifier_public | c_modifier_final,
    bic_v8_context_method_global_object_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_v8_context_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_v8_context_method_print_0
  },
};/*}}}*/

built_in_variable_s v8_context_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_v8_context_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_v8_context_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (v8_htype)nullptr;
}/*}}}*/

void bic_v8_context_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  v8_htype context_hnd = (v8_htype)location_ptr->v_data_ptr;

  if (context_hnd != nullptr)
  {
    Persistent<Context> per_context = *((Persistent<Context> *)&context_hnd);
    per_context.Dispose();

    // - clean all context junk -
    V8::ContextDisposedNotification();
    while(!V8::IdleNotification(1000)) {};
  }
}/*}}}*/

bool bic_v8_context_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_v8_context_method_V8Context_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - create new context -
  Persistent<Context> per_context = Context::New();

  dst_location->v_data_ptr = (v8_htype)*((v8_htype *)&per_context);

  return true;
}/*}}}*/

bool bic_v8_context_method_enter_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  v8_htype context_hnd = (v8_htype)dst_location->v_data_ptr;
  Persistent<Context> per_context = *((Persistent<Context> *)&context_hnd);

  // - enter context -
  per_context->Enter();

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_v8_context_method_exit_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  v8_htype context_hnd = (v8_htype)dst_location->v_data_ptr;
  Persistent<Context> per_context = *((Persistent<Context> *)&context_hnd);

  // - exit context -
  per_context->Exit();

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_v8_context_method_global_object_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  UCL_HANDLE_CONTEXT_SCOPE();

  v8_htype context_hnd = (v8_htype)dst_location->v_data_ptr;
  Persistent<Context> per_context = *((Persistent<Context> *)&context_hnd);

  // - retrieve global object -
  Handle<v8::Object> hnd_value = per_context->Global();
  Persistent<Value> per_value = Persistent<Value>::New(hnd_value);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_v8_object,(v8_htype)*((v8_htype *)&per_value));
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_v8_context_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("V8Context"),"V8Context");
  );

  return true;
}/*}}}*/

bool bic_v8_context_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("V8Context");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class V8_SCRIPT -
built_in_class_s v8_script_class =
{/*{{{*/
  "V8Script",
  c_modifier_public | c_modifier_final,
  5, v8_script_methods,
  0, v8_script_variables,
  bic_v8_script_consts,
  bic_v8_script_init,
  bic_v8_script_clear,
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

built_in_method_s v8_script_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_v8_script_operator_binary_equal
  },
  {
    "compile#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_v8_script_method_compile_1
  },
  {
    "run#0",
    c_modifier_public | c_modifier_final,
    bic_v8_script_method_run_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_v8_script_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_v8_script_method_print_0
  },
};/*}}}*/

built_in_variable_s v8_script_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_v8_script_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_v8_script_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (v8_htype)nullptr;
}/*}}}*/

void bic_v8_script_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  v8_htype hnd_value = (v8_htype)location_ptr->v_data_ptr;

  if (hnd_value != nullptr)
  {
    Persistent<Script> per_script = *((Persistent<Script> *)&hnd_value);
    per_script.Dispose();
  }
}/*}}}*/

bool bic_v8_script_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_v8_script_method_compile_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
source:ignore
>
static_method
; @end

  UCL_HANDLE_CONTEXT_SCOPE();

  Handle<Value> hnd_source = v8_c::create_v8_object(it,src_0_location);

  if (!hnd_source->IsString())
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_v8_script,"compile#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  TryCatch try_catch;
  Handle<Script> hnd_script = Script::Compile(Handle<String>::Cast(hnd_source));

  // - ERROR -
  if (hnd_script.IsEmpty())
  {
    UCL_RETHROW_V8_EXCEPTION(try_catch,c_error_V8_SCRIPT_COMPILE_ERROR);

    return false;
  }

  Persistent<Script> per_script = Persistent<Script>::New(hnd_script);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_v8_script,(v8_htype)*((v8_htype *)&per_script));
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_v8_script_method_run_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  UCL_HANDLE_CONTEXT_SCOPE();

  v8_htype script_hnd = (v8_htype)dst_location->v_data_ptr;
  Persistent<Script> per_script = *((Persistent<Script> *)&script_hnd);

  // - execute script -
  TryCatch try_catch;
  Handle<Value> hnd_result = per_script->Run();

  // - ERROR -
  if (hnd_result.IsEmpty())
  {
    UCL_RETHROW_V8_EXCEPTION(try_catch,c_error_V8_SCRIPT_EXECUTE_ERROR);

    return false;
  }

  Persistent<Value> per_result = Persistent<Value>::New(hnd_result);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_v8_object,(v8_htype)*((v8_htype *)&per_result));
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_v8_script_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("V8Script"),"V8Script");
  );

  return true;
}/*}}}*/

bool bic_v8_script_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("V8Script");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class V8_HEAP_STAT -
built_in_class_s v8_heap_stat_class =
{/*{{{*/
  "V8HeapStat",
  c_modifier_public | c_modifier_final,
  9, v8_heap_stat_methods,
  0, v8_heap_stat_variables,
  bic_v8_heap_stat_consts,
  bic_v8_heap_stat_init,
  bic_v8_heap_stat_clear,
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

built_in_method_s v8_heap_stat_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_v8_heap_stat_operator_binary_equal
  },
  {
    "V8HeapStat#0",
    c_modifier_public | c_modifier_final,
    bic_v8_heap_stat_method_V8HeapStat_0
  },
  {
    "update#0",
    c_modifier_public | c_modifier_final,
    bic_v8_heap_stat_method_update_0
  },
  {
    "total#0",
    c_modifier_public | c_modifier_final,
    bic_v8_heap_stat_method_total_0
  },
  {
    "executable#0",
    c_modifier_public | c_modifier_final,
    bic_v8_heap_stat_method_executable_0
  },
  {
    "used#0",
    c_modifier_public | c_modifier_final,
    bic_v8_heap_stat_method_used_0
  },
  {
    "limit#0",
    c_modifier_public | c_modifier_final,
    bic_v8_heap_stat_method_limit_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_v8_heap_stat_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_v8_heap_stat_method_print_0
  },
};/*}}}*/

built_in_variable_s v8_heap_stat_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_v8_heap_stat_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_v8_heap_stat_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (HeapStatistics *)nullptr;
}/*}}}*/

void bic_v8_heap_stat_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  HeapStatistics *hs_ptr = (HeapStatistics *)location_ptr->v_data_ptr;

  if (hs_ptr != nullptr)
  {
    delete hs_ptr;
  }
}/*}}}*/

bool bic_v8_heap_stat_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_v8_heap_stat_method_V8HeapStat_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - create heap statistics object -
  HeapStatistics *hs_ptr = new HeapStatistics();

  // - retrieve v8 heap statistics -
  V8::GetHeapStatistics(hs_ptr);

  dst_location->v_data_ptr = (HeapStatistics *)hs_ptr;

  return true;
}/*}}}*/

bool bic_v8_heap_stat_method_update_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  HeapStatistics *hs_ptr = (HeapStatistics *)dst_location->v_data_ptr;

  // - retrieve v8 heap statistics -
  V8::GetHeapStatistics(hs_ptr);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_v8_heap_stat_method_total_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  HeapStatistics *hs_ptr = (HeapStatistics *)dst_location->v_data_ptr;
  long long int result = hs_ptr->total_heap_size();

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_v8_heap_stat_method_executable_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  HeapStatistics *hs_ptr = (HeapStatistics *)dst_location->v_data_ptr;
  long long int result = hs_ptr->total_heap_size_executable();

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_v8_heap_stat_method_used_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  HeapStatistics *hs_ptr = (HeapStatistics *)dst_location->v_data_ptr;
  long long int result = hs_ptr->used_heap_size();

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_v8_heap_stat_method_limit_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  HeapStatistics *hs_ptr = (HeapStatistics *)dst_location->v_data_ptr;
  long long int result = hs_ptr->heap_size_limit();

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_v8_heap_stat_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("V8HeapStat"),"V8HeapStat");
  );

  return true;
}/*}}}*/

bool bic_v8_heap_stat_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("V8HeapStat");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class V8_OBJECT -
built_in_class_s v8_object_class =
{/*{{{*/
  "V8Object",
  c_modifier_public | c_modifier_final,
  15, v8_object_methods,
  0, v8_object_variables,
  bic_v8_object_consts,
  bic_v8_object_init,
  bic_v8_object_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  bic_v8_object_invoke,
  bic_v8_object_member
};/*}}}*/

built_in_method_s v8_object_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_v8_object_operator_binary_equal
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_v8_object_operator_binary_le_br_re_br
  },
  {
    "V8Object#1",
    c_modifier_public | c_modifier_final,
    bic_v8_object_method_V8Object_1
  },
  {
    "value#0",
    c_modifier_public | c_modifier_final,
    bic_v8_object_method_value_0
  },
  {
    "has_prop#1",
    c_modifier_public | c_modifier_final,
    bic_v8_object_method_has_prop_1
  },
  {
    "has_own_prop#1",
    c_modifier_public | c_modifier_final,
    bic_v8_object_method_has_own_prop_1
  },
  {
    "get_prop#1",
    c_modifier_public | c_modifier_final,
    bic_v8_object_method_get_prop_1
  },
  {
    "set_prop#2",
    c_modifier_public | c_modifier_final,
    bic_v8_object_method_set_prop_2
  },
  {
    "del_prop#1",
    c_modifier_public | c_modifier_final,
    bic_v8_object_method_del_prop_1
  },
  {
    "prop_names#0",
    c_modifier_public | c_modifier_final,
    bic_v8_object_method_prop_names_0
  },
  {
    "own_prop_names#0",
    c_modifier_public | c_modifier_final,
    bic_v8_object_method_own_prop_names_0
  },
  {
    "construct#1",
    c_modifier_public | c_modifier_final,
    bic_v8_object_method_construct_1
  },
  {
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_v8_object_method_length_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_v8_object_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_v8_object_method_print_0
  },
};/*}}}*/

built_in_variable_s v8_object_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_v8_object_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_v8_object_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (v8_htype)nullptr;
}/*}}}*/

void bic_v8_object_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  v8_htype hnd_value = (v8_htype)location_ptr->v_data_ptr;

  if (hnd_value != nullptr)
  {
    Persistent<Value> per_value = *((Persistent<Value> *)&hnd_value);
    per_value.Dispose();
  }
}/*}}}*/

bool bic_v8_object_invoke(interpreter_thread_s &it,uli *code,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  UCL_HANDLE_CONTEXT_SCOPE();

  // - retrieve object -
  Handle<Value> hnd_dst = v8_c::create_v8_object(it,dst_location);

  // - ERROR -
  if (hnd_dst->IsUndefined())
  {
    exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_WRONG_OBJECT_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (!hnd_dst->IsObject())
  {
    exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_INVOKE_METHOD_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - cast value to object -
  Handle<Object> hnd_obj = Handle<Object>::Cast(hnd_dst);

  // - method name reference -
  string_s &name_ref = ((interpreter_s *)it.interpreter_ptr)->method_symbol_names[code[icl_name_idx]];

  // - parameter count and method name length -
  unsigned param_cnt = (unsigned)code[icl_parm_cnt] - 1;
  unsigned name_length = strchr(name_ref.data,'#') - name_ref.data;

  // - retrieve function -
  Handle<Value> hnd_fun = hnd_obj->Get(String::New(name_ref.data,name_length));

  // - ERROR -
  if (!hnd_fun->IsFunction())
  {
    exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_INVOKE_METHOD_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - prepare parameters -
  Handle<Value> hnd_params[c_max_method_param_cnt];

  if (param_cnt > 0)
  {
    unsigned param_idx = 0;
    do {
      Handle<Value> &hnd_param = hnd_params[param_idx];

      location_s *param_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx + param_idx]);
      hnd_param = v8_c::create_v8_object(it,param_location);

      // - ERROR -
      if (hnd_param->IsUndefined())
      {
        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_INVOKE_METHOD_WRONG_PARAMETER,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(param_idx);

        return false;
      }

    } while(++param_idx < param_cnt);
  }

  // - call object method -
  Handle<Value> hnd_result = Handle<Function>::Cast(hnd_fun)->Call(hnd_obj,param_cnt,hnd_params);
  Persistent<Value> per_result = Persistent<Value>::New(hnd_result);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_v8_object,(v8_htype)*((v8_htype *)&per_result));
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_v8_object_member(interpreter_thread_s &it,uli *code,unsigned stack_base)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + code[ioms_stack_object]);

  UCL_HANDLE_CONTEXT_SCOPE();

  // - retrieve object -
  Handle<Value> hnd_dst = v8_c::create_v8_object(it,dst_location);

  // - ERROR -
  if (hnd_dst->IsUndefined())
  {
    exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_WRONG_OBJECT_REFERENCE,code[ioms_source_pos],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (!hnd_dst->IsObject())
  {
    exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_MEMBER_SELECT_ERROR,code[ioms_source_pos],(location_s *)it.blank_location);
    return false;
  }

  // - cast value to object -
  Handle<Object> hnd_obj = Handle<Object>::Cast(hnd_dst);

  // - retrieve member name -
  string_s &name_ref = ((interpreter_s *)it.interpreter_ptr)->variable_symbol_names[code[ioms_var_name]];
  Handle<String> hnd_name = String::New(name_ref.data,name_ref.size - 1);

  // - create reference object -
  v8_reference_s *v8_ref_ptr = (v8_reference_s *)cmalloc(sizeof(v8_reference_s));
  v8_ref_ptr->init();

  v8_ref_ptr->per_obj = Persistent<Object>::New(hnd_obj);
  v8_ref_ptr->per_key = Persistent<Value>::New(hnd_name);

  // - create target location -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_v8_reference,v8_ref_ptr);

  pointer &trg_location = it.data_stack[stack_base + code[ioms_stack_trg]];
  it.release_location_ptr((location_s *)trg_location);
  trg_location = (pointer)new_location;

  return true;
}/*}}}*/

bool bic_v8_object_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_v8_object_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  UCL_HANDLE_CONTEXT_SCOPE();

  Handle<Value> hnd_dst = v8_c::create_v8_object(it,dst_location);

  // - ERROR -
  if (hnd_dst->IsUndefined())
  {
    exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_WRONG_OBJECT_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  Handle<Value> hnd_src_0 = v8_c::create_v8_object(it,src_0_location);

  // - ERROR -
  if (hnd_src_0->IsUndefined())
  {
    exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_MEMBER_SELECT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (!hnd_dst->IsObject())
  {
    exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_MEMBER_SELECT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create reference object -
  v8_reference_s *v8_ref_ptr = (v8_reference_s *)cmalloc(sizeof(v8_reference_s));
  v8_ref_ptr->init();

  v8_ref_ptr->per_obj = Persistent<Object>::New(Handle<Object>::Cast(hnd_dst));
  v8_ref_ptr->per_key = Persistent<Value>::New(hnd_src_0);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_v8_reference,v8_ref_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_v8_object_method_V8Object_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  UCL_HANDLE_CONTEXT_SCOPE();

  Handle<Value> hnd_value = v8_c::create_v8_object(it,src_0_location);

  // - ERROR -
  if (hnd_value->IsUndefined())
  {
    exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  Persistent<Value> per_value = Persistent<Value>::New(hnd_value);
  dst_location->v_data_ptr = (v8_htype)*((v8_htype *)&per_value);

  return true;
}/*}}}*/

bool bic_v8_object_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  UCL_HANDLE_CONTEXT_SCOPE();

  Handle<Value> hnd_dst = v8_c::create_v8_object(it,dst_location);

  // - ERROR -
  if (hnd_dst->IsUndefined())
  {
    exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_WRONG_OBJECT_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  location_s *location_ptr = v8_c::v8_object_value(it,hnd_dst,operands[c_source_pos_idx]);

  // - ERROR -
  if (location_ptr == nullptr)
  {
    // - if exception was already thrown -
    if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
    {
      return false;
    }

    exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_VALUE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT(location_ptr);

  return true;
}/*}}}*/

#define BIC_V8_OBJECT_HAS_PROPERTY(FUNCTION) \
{/*{{{*/\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
  UCL_HANDLE_CONTEXT_SCOPE();\
\
  Handle<Value> hnd_dst = v8_c::create_v8_object(it,dst_location);\
\
  /* - ERROR - */\
  if (hnd_dst->IsUndefined())\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_WRONG_OBJECT_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  /* - ERROR - */\
  if (!hnd_dst->IsObject())\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_HAS_PROP_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  Handle<Value> hnd_src_0 = v8_c::create_v8_object(it,src_0_location);\
\
  /* - ERROR - */\
  if (hnd_src_0->IsUndefined())\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_HAS_PROP_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  long long int result = Handle<Object>::Cast(hnd_dst)->FUNCTION(hnd_src_0->ToString());\
\
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
\
  return true;\
}/*}}}*/

bool bic_v8_object_method_has_prop_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_V8_OBJECT_HAS_PROPERTY(Has);
}/*}}}*/

bool bic_v8_object_method_has_own_prop_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_V8_OBJECT_HAS_PROPERTY(HasOwnProperty);
}/*}}}*/

bool bic_v8_object_method_get_prop_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  UCL_HANDLE_CONTEXT_SCOPE();

  Handle<Value> hnd_dst = v8_c::create_v8_object(it,dst_location);

  // - ERROR -
  if (hnd_dst->IsUndefined())
  {
    exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_WRONG_OBJECT_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (!hnd_dst->IsObject())
  {
    exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_GET_PROP_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  Handle<Value> hnd_src_0 = v8_c::create_v8_object(it,src_0_location);

  // - ERROR -
  if (hnd_src_0->IsUndefined())
  {
    exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_GET_PROP_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  Handle<Value> hnd_result = Handle<Object>::Cast(hnd_dst)->Get(hnd_src_0);
  Persistent<Value> per_result = Persistent<Value>::New(hnd_result);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_v8_object,(v8_htype)*((v8_htype *)&per_result));
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_v8_object_method_set_prop_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  UCL_HANDLE_CONTEXT_SCOPE();

  Handle<Value> hnd_dst = v8_c::create_v8_object(it,dst_location);

  // - ERROR -
  if (hnd_dst->IsUndefined())
  {
    exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_WRONG_OBJECT_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (!hnd_dst->IsObject())
  {
    exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_SET_PROP_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  Handle<Value> hnd_src_0 = v8_c::create_v8_object(it,src_0_location);
  Handle<Value> hnd_src_1 = v8_c::create_v8_object(it,src_1_location);

  // - ERROR -
  if (hnd_src_0->IsUndefined() || hnd_src_1->IsUndefined())
  {
    exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_SET_PROP_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (!Handle<Object>::Cast(hnd_dst)->Set(hnd_src_0,hnd_src_1))
  {
    exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_SET_PROP_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_v8_object_method_del_prop_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  UCL_HANDLE_CONTEXT_SCOPE();

  Handle<Value> hnd_dst = v8_c::create_v8_object(it,dst_location);

  // - ERROR -
  if (hnd_dst->IsUndefined())
  {
    exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_WRONG_OBJECT_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (!hnd_dst->IsObject())
  {
    exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_DEL_PROP_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  Handle<Value> hnd_src_0 = v8_c::create_v8_object(it,src_0_location);

  // - ERROR -
  if (hnd_src_0->IsUndefined())
  {
    exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_DEL_PROP_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  if (!Handle<Object>::Cast(hnd_dst)->Delete(hnd_src_0->ToString()))
  {
    exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_DEL_PROP_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

#define BIC_V8_OBJECT_PROPERTY_NAMES(FUNCTION) \
{/*{{{*/\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  UCL_HANDLE_CONTEXT_SCOPE();\
\
  Handle<Value> hnd_dst = v8_c::create_v8_object(it,dst_location);\
\
  /* - ERROR - */\
  if (hnd_dst->IsUndefined())\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_WRONG_OBJECT_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  /* - ERROR - */\
  if (!hnd_dst->IsObject())\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_PROP_NAMES_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  Handle<Value> hnd_result = Handle<Object>::Cast(hnd_dst)->FUNCTION();\
  Persistent<Value> per_result = Persistent<Value>::New(hnd_result);\
\
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_v8_object,(v8_htype)*((v8_htype *)&per_result));\
  BIC_SET_RESULT(new_location);\
\
  return true;\
}/*}}}*/

bool bic_v8_object_method_prop_names_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_V8_OBJECT_PROPERTY_NAMES(GetPropertyNames);
}/*}}}*/

bool bic_v8_object_method_own_prop_names_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_V8_OBJECT_PROPERTY_NAMES(GetOwnPropertyNames);
}/*}}}*/

bool bic_v8_object_method_construct_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
parameters:c_bi_class_array
>
method construct
; @end

  UCL_HANDLE_CONTEXT_SCOPE();

  Handle<Value> hnd_dst = v8_c::create_v8_object(it,dst_location);

  // - ERROR -
  if (hnd_dst->IsUndefined())
  {
    exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_WRONG_OBJECT_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (!hnd_dst->IsObject())
  {
    exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_INVOKE_METHOD_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - retrieve parameters array -
  pointer_array_s *array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

  // - prepare parameters -
  unsigned param_cnt = array_ptr->used;
  Handle<Value> hnd_params[c_max_method_param_cnt];

  if (param_cnt > 0)
  {
    unsigned param_idx = 0;
    do {
      Handle<Value> &hnd_param = hnd_params[param_idx];

      location_s *param_location = (location_s *)it.get_location_value(array_ptr->data[param_idx]);
      hnd_param = v8_c::create_v8_object(it,param_location);

      // - ERROR -
      if (hnd_param->IsUndefined())
      {
        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_INVOKE_METHOD_WRONG_PARAMETER,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(param_idx);

        return false;
      }

    } while(++param_idx < param_cnt);
  }

  // - call object method -
  Handle<Value> hnd_result = Handle<Object>::Cast(hnd_dst)->CallAsConstructor(param_cnt,hnd_params);
  Persistent<Value> per_result = Persistent<Value>::New(hnd_result);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_v8_object,(v8_htype)*((v8_htype *)&per_result));
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_v8_object_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  UCL_HANDLE_CONTEXT_SCOPE();

  Handle<Value> hnd_dst = v8_c::create_v8_object(it,dst_location);

  // - ERROR -
  if (hnd_dst->IsUndefined())
  {
    exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_WRONG_OBJECT_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  long long int result;

  if (hnd_dst->IsString())
  {
    Handle<String> hnd_string = Handle<String>::Cast(hnd_dst);
    result = hnd_string->Length();
  }
  else if (hnd_dst->IsArray())
  {
    Handle<Array> hnd_array = Handle<Array>::Cast(hnd_dst);
    result = hnd_array->Length();
  }

  // - ERROR -
  else
  {
    exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_LENGTH_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_v8_object_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  UCL_HANDLE_CONTEXT_SCOPE();

  Handle<Value> hnd_dst = v8_c::create_v8_object(it,dst_location);

  // - ERROR -
  if (hnd_dst->IsUndefined())
  {
    exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_WRONG_OBJECT_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  Handle<String> hnd_string = hnd_dst->ToString();
  int length = hnd_string->Utf8Length();

  // - create string object -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->create(length);
  hnd_string->WriteUtf8(string_ptr->data,length);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_v8_object_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  UCL_HANDLE_CONTEXT_SCOPE();

  Handle<Value> hnd_dst = v8_c::create_v8_object(it,dst_location);

  // - ERROR -
  if (hnd_dst->IsUndefined())
  {
    exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_WRONG_OBJECT_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  Handle<String> hnd_string = hnd_dst->ToString();
  String::Utf8Value utf8_value(hnd_string);

  // - print string content -
  fwrite(*utf8_value,utf8_value.length(),1,stdout);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

// - class V8_REFERENCE -
built_in_class_s v8_reference_class =
{/*{{{*/
  "V8Reference",
  c_modifier_public | c_modifier_final,
  16, v8_reference_methods,
  0, v8_reference_variables,
  bic_v8_reference_consts,
  bic_v8_reference_init,
  bic_v8_reference_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  bic_v8_object_invoke,
  bic_v8_object_member
};/*}}}*/

built_in_method_s v8_reference_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_v8_reference_operator_binary_equal
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_v8_object_operator_binary_le_br_re_br
  },
  {
    "value#0",
    c_modifier_public | c_modifier_final,
    bic_v8_object_method_value_0
  },
  {
    "has_prop#1",
    c_modifier_public | c_modifier_final,
    bic_v8_object_method_has_prop_1
  },
  {
    "has_own_prop#1",
    c_modifier_public | c_modifier_final,
    bic_v8_object_method_has_own_prop_1
  },
  {
    "get_prop#1",
    c_modifier_public | c_modifier_final,
    bic_v8_object_method_get_prop_1
  },
  {
    "set_prop#2",
    c_modifier_public | c_modifier_final,
    bic_v8_object_method_set_prop_2
  },
  {
    "del_prop#1",
    c_modifier_public | c_modifier_final,
    bic_v8_object_method_del_prop_1
  },
  {
    "prop_names#0",
    c_modifier_public | c_modifier_final,
    bic_v8_object_method_prop_names_0
  },
  {
    "own_prop_names#0",
    c_modifier_public | c_modifier_final,
    bic_v8_object_method_own_prop_names_0
  },
  {
    "construct#1",
    c_modifier_public | c_modifier_final,
    bic_v8_object_method_construct_1
  },
  {
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_v8_object_method_length_0
  },
  {
    "get#0",
    c_modifier_public | c_modifier_final,
    bic_v8_reference_method_get_0
  },
  {
    "set#1",
    c_modifier_public | c_modifier_final,
    bic_v8_reference_method_set_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_v8_object_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_v8_object_method_print_0
  },
};/*}}}*/

built_in_variable_s v8_reference_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_v8_reference_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_v8_reference_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (v8_reference_s *)nullptr;
}/*}}}*/

void bic_v8_reference_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  v8_reference_s *v8_ref_ptr = (v8_reference_s *)location_ptr->v_data_ptr;

  if (v8_ref_ptr != nullptr)
  {
    v8_ref_ptr->clear(it);
    cfree(v8_ref_ptr);
  }
}/*}}}*/

bool bic_v8_reference_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  UCL_HANDLE_CONTEXT_SCOPE();

  Handle<Value> hnd_src_0 = v8_c::create_v8_object(it,src_0_location);

  // - ERROR -
  if (hnd_src_0->IsUndefined())
  {
    exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_SET_PROP_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  v8_reference_s *v8_ref_ptr = (v8_reference_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (!v8_ref_ptr->set(hnd_src_0))
  {
    exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_SET_PROP_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  Persistent<Value> per_src_0 = Persistent<Value>::New(hnd_src_0);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_v8_object,(v8_htype)*((v8_htype *)&per_src_0));
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_v8_reference_method_get_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  UCL_HANDLE_CONTEXT_SCOPE();

  Handle<Value> hnd_result = ((v8_reference_s *)dst_location->v_data_ptr)->get();
  Persistent<Value> per_result = Persistent<Value>::New(hnd_result);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_v8_object,(v8_htype)*((v8_htype *)&per_result));
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_v8_reference_method_set_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  UCL_HANDLE_CONTEXT_SCOPE();

  Handle<Value> hnd_src_0 = v8_c::create_v8_object(it,src_0_location);

  // - ERROR -
  if (hnd_src_0->IsUndefined())
  {
    exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_SET_PROP_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  v8_reference_s *v8_ref_ptr = (v8_reference_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (!v8_ref_ptr->set(hnd_src_0))
  {
    exception_s::throw_exception(it,module.error_base + c_error_V8_OBJECT_SET_PROP_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

