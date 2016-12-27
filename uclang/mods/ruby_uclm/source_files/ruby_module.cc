
@begin
include "ruby_module.h"
@end

// - RUBY indexes of built in classes -
unsigned c_bi_class_ruby_interpreter = c_idx_not_exist;
unsigned c_bi_class_ruby_value = c_idx_not_exist;

// - RUBY indexes of remote classes -
unsigned c_rm_class_dict = c_idx_not_exist;

// - RUBY module -
built_in_module_s module =
{/*{{{*/
  2,                    // Class count
  ruby_classes,         // Classes

  0,                    // Error base index
  3,                    // Error count
  ruby_error_strings,   // Error strings

  ruby_initialize,      // Initialize function
  ruby_print_exception, // Print exceptions function
};/*}}}*/

// - RUBY classes -
built_in_class_s *ruby_classes[] =
{/*{{{*/
  &ruby_interpreter_class,
  &ruby_value_class,
};/*}}}*/

// - RUBY error strings -
const char *ruby_error_strings[] =
{/*{{{*/
  "error_RUBY_INTERPRETER_PROCESS_CODE_ERROR",
  "error_RUBY_VALUE_WRONG_VALUE_REFERENCE",
  "error_RUBY_VALUE_VALUE_ERROR",
};/*}}}*/

// - RUBY initialize -
bool ruby_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize ruby_interpreter class identifier -
  c_bi_class_ruby_interpreter = class_base_idx++;

  // - initialize ruby_value class identifier -
  c_bi_class_ruby_value = class_base_idx++;

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

// - RUBY print exception -
bool ruby_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_RUBY_INTERPRETER_PROCESS_CODE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while processing Ruby code: %s\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_RUBY_VALUE_WRONG_VALUE_REFERENCE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong reference to Ruby value\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_RUBY_VALUE_VALUE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while retrieving value of Ruby value\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class RUBY_INTERPRETER -
built_in_class_s ruby_interpreter_class =
{/*{{{*/
  "RubyInterpreter",
  c_modifier_public | c_modifier_final,
  7, ruby_interpreter_methods,
  0, ruby_interpreter_variables,
  bic_ruby_interpreter_consts,
  bic_ruby_interpreter_init,
  bic_ruby_interpreter_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s ruby_interpreter_methods[] =
{/*{{{*/
  {
    "eval#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ruby_interpreter_method_eval_1
  },
  {
    "load#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ruby_interpreter_method_load_1
  },
  {
    "require#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ruby_interpreter_method_require_1
  },
  {
    "gv_get#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ruby_interpreter_method_gv_get_1
  },
  {
    "gv_set#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ruby_interpreter_method_gv_set_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ruby_interpreter_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ruby_interpreter_method_print_0
  },
};/*}}}*/

built_in_variable_s ruby_interpreter_variables[] =
{/*{{{*/
};/*}}}*/

void bic_ruby_interpreter_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_ruby_interpreter_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

void bic_ruby_interpreter_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

#define BIC_RUBY_INTERPRETER_RETRIEVE_ERROR_LOCATION() \
/*{{{*/\
  VALUE rv_error = rb_obj_as_string(rb_errinfo());\
  rb_set_errinfo(Qnil);\
\
  string_s *err_string = it.get_new_string_ptr();\
  err_string->set(RSTRING_LEN(rv_error),RSTRING_PTR(rv_error));\
\
  BIC_CREATE_NEW_LOCATION(err_location,c_bi_class_string,err_string);\
/*}}}*/

bool bic_ruby_interpreter_method_eval_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_ruby_interpreter,"eval#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  int state;
  VALUE rv_result = rb_eval_string_protect(string_ptr->data,&state);

  // - ERROR -
  if (state)
  {
    BIC_RUBY_INTERPRETER_RETRIEVE_ERROR_LOCATION();

    exception_s::throw_exception(it,module.error_base + c_error_RUBY_INTERPRETER_PROCESS_CODE_ERROR,operands[c_source_pos_idx],err_location);
    return false;
  }

  unsigned value_idx = ruby_c::keep_value(rv_result);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_ruby_value,value_idx);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_ruby_interpreter_method_load_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_ruby_interpreter,"load#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;
  VALUE rv_file_name = rb_str_new(string_ptr->data,string_ptr->size - 1);

  int state;
  rb_protect(ruby_c::rb_load_protect,rv_file_name,&state);

  // - ERROR -
  if (state)
  {
    BIC_RUBY_INTERPRETER_RETRIEVE_ERROR_LOCATION();

    exception_s::throw_exception(it,module.error_base + c_error_RUBY_INTERPRETER_PROCESS_CODE_ERROR,operands[c_source_pos_idx],err_location);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_ruby_interpreter_method_require_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_ruby_interpreter,"require#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;
  VALUE rv_file_name = rb_str_new(string_ptr->data,string_ptr->size - 1);

  int state;
  VALUE rv_result = rb_protect(ruby_c::rb_require_protect,rv_file_name,&state);

  // - ERROR -
  if (state)
  {
    BIC_RUBY_INTERPRETER_RETRIEVE_ERROR_LOCATION();

    exception_s::throw_exception(it,module.error_base + c_error_RUBY_INTERPRETER_PROCESS_CODE_ERROR,operands[c_source_pos_idx],err_location);
    return false;
  }

  unsigned value_idx = ruby_c::keep_value(rv_result);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_ruby_value,value_idx);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_ruby_interpreter_method_gv_get_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_ruby_interpreter,"gv_get#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  VALUE rv_result = rb_gv_get(((string_s *)src_0_location->v_data_ptr)->data);

  unsigned value_idx = ruby_c::keep_value(rv_result);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_ruby_value,value_idx);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_ruby_interpreter_method_gv_set_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  
  // FIXME TODO continue ...
  BIC_TODO_ERROR(__FILE__,__LINE__);
  return false;
}/*}}}*/

bool bic_ruby_interpreter_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("RubyInterpreter"),"RubyInterpreter");
  );

  return true;
}/*}}}*/

bool bic_ruby_interpreter_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("RubyInterpreter");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class RUBY_VALUE -
built_in_class_s ruby_value_class =
{/*{{{*/
  "RubyValue",
  c_modifier_public | c_modifier_final,
  4, ruby_value_methods,
  0, ruby_value_variables,
  bic_ruby_value_consts,
  bic_ruby_value_init,
  bic_ruby_value_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s ruby_value_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_ruby_value_operator_binary_equal
  },
  {
    "value#0",
    c_modifier_public | c_modifier_final,
    bic_ruby_value_method_value_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ruby_value_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ruby_value_method_print_0
  },
};/*}}}*/

built_in_variable_s ruby_value_variables[] =
{/*{{{*/
};/*}}}*/

void bic_ruby_value_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_ruby_value_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (unsigned)c_idx_not_exist;
}/*}}}*/

void bic_ruby_value_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  unsigned value_idx = (unsigned)location_ptr->v_data_ptr;

  if (value_idx != c_idx_not_exist)
  {
    ruby_c::release_value(value_idx);
  }
}/*}}}*/

bool bic_ruby_value_invoke(interpreter_thread_s &it,uli *code,unsigned stack_base,uli *operands)
{/*{{{*/

  // FIXME TODO continue ...
  cassert(0);
}/*}}}*/

bool bic_ruby_value_member(interpreter_thread_s &it,uli *code,unsigned stack_base)
{/*{{{*/

  // FIXME TODO continue ...
  cassert(0);
}/*}}}*/

bool bic_ruby_value_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_ruby_value_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  int status;
  VALUE rv_dst = ruby_c::create_ruby_value(it,dst_location,status);

  // - ERROR -
  if (status)
  {
    exception_s::throw_exception(it,module.error_base + c_error_RUBY_VALUE_WRONG_VALUE_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  location_s *location_ptr = ruby_c::ruby_value_value(it,rv_dst,operands[c_source_pos_idx]);

  // - ERROR -
  if (location_ptr == NULL)
  {
    // - if exception was already thrown -
    if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
    {
      return false;
    }

    exception_s::throw_exception(it,module.error_base + c_error_RUBY_VALUE_VALUE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT(location_ptr);

  return true;
}/*}}}*/

bool bic_ruby_value_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("RubyValue"),"RubyValue");
  );

  return true;
}/*}}}*/

bool bic_ruby_value_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("RubyValue");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

