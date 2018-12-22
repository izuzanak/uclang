
@begin
include "ruby_module.h"
@end

// - RUBY indexes of built in classes -
unsigned c_bi_class_ruby_interpreter = c_idx_not_exist;
unsigned c_bi_class_ruby_symbol = c_idx_not_exist;
unsigned c_bi_class_ruby_value = c_idx_not_exist;
unsigned c_bi_class_ruby_iv_ref = c_idx_not_exist;
unsigned c_bi_class_ruby_item_ref = c_idx_not_exist;

// - RUBY indexes of remote classes -
unsigned c_rm_class_dict = c_idx_not_exist;

// - RUBY module -
EXPORT built_in_module_s module =
{/*{{{*/
  5,                    // Class count
  ruby_classes,         // Classes

  0,                    // Error base index
  9,                    // Error count
  ruby_error_strings,   // Error strings

  ruby_initialize,      // Initialize function
  ruby_print_exception, // Print exceptions function
};/*}}}*/

// - RUBY classes -
built_in_class_s *ruby_classes[] =
{/*{{{*/
  &ruby_interpreter_class,
  &ruby_symbol_class,
  &ruby_value_class,
  &ruby_iv_ref_class,
  &ruby_item_ref_class,
};/*}}}*/

// - RUBY error strings -
const char *ruby_error_strings[] =
{/*{{{*/
  "error_RUBY_INTERPRETER_PROCESS_CODE_ERROR",
  "error_RUBY_VALUE_INVOKE_METHOD_ERROR",
  "error_RUBY_VALUE_INVOKE_METHOD_WRONG_PARAMETER",
  "error_RUBY_VALUE_ITEM_SELECT_ERROR",
  "error_RUBY_VALUE_WRONG_VALUE_REFERENCE",
  "error_RUBY_VALUE_CREATE_ERROR",
  "error_RUBY_VALUE_VALUE_ERROR",
  "error_RUBY_VALUE_SET_INSTANCE_VALUE_ERROR",
  "error_RUBY_VALUE_SET_ITEM_ERROR",
};/*}}}*/

// - RUBY initialize -
bool ruby_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize ruby_interpreter class identifier -
  c_bi_class_ruby_interpreter = class_base_idx++;

  // - initialize ruby_symbol class identifier -
  c_bi_class_ruby_symbol = class_base_idx++;

  // - initialize ruby_value class identifier -
  c_bi_class_ruby_value = class_base_idx++;

  // - initialize ruby_iv_ref class identifier -
  c_bi_class_ruby_iv_ref = class_base_idx++;

  // - initialize ruby_item_ref class identifier -
  c_bi_class_ruby_item_ref = class_base_idx++;

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
  case c_error_RUBY_VALUE_INVOKE_METHOD_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while invoking Ruby method: %s\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_RUBY_VALUE_INVOKE_METHOD_WRONG_PARAMETER:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot process parameter %" HOST_LL_FORMAT "d of ruby value method\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_RUBY_VALUE_ITEM_SELECT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while selecting item from Ruby value\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_RUBY_VALUE_WRONG_VALUE_REFERENCE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong reference to Ruby value\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_RUBY_VALUE_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating Ruby value\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_RUBY_VALUE_VALUE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while retrieving value of Ruby value\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_RUBY_VALUE_SET_ITEM_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot set item of ruby value\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_RUBY_VALUE_SET_INSTANCE_VALUE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot set instance value of ruby value\n");
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
  6, ruby_interpreter_methods,
  0, ruby_interpreter_variables,
  bic_ruby_interpreter_consts,
  bic_ruby_interpreter_init,
  bic_ruby_interpreter_clear,
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
  BIC_CLASS_EMPTY_VARIABLES
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
  BIC_CREATE_NEW_LOCATION_REFS(err_location,c_bi_class_string,err_string,0);\
/*}}}*/

bool bic_ruby_interpreter_method_eval_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
source:c_bi_class_string
>
class c_bi_class_ruby_interpreter
method eval
static_method
; @end

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  int status;
  VALUE rv_result = rb_eval_string_protect(string_ptr->data,&status);

  // - ERROR -
  if (status)
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
@begin ucl_params
<
path:c_bi_class_string
>
class c_bi_class_ruby_interpreter
method load
static_method
; @end

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;
  VALUE rv_file_name = rb_str_new(string_ptr->data,string_ptr->size - 1);

  int status;
  rb_protect(ruby_c::rb_load_protect,rv_file_name,&status);

  // - ERROR -
  if (status)
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
@begin ucl_params
<
path:c_bi_class_string
>
class c_bi_class_ruby_interpreter
method require
static_method
; @end

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;
  VALUE rv_file_name = rb_str_new(string_ptr->data,string_ptr->size - 1);

  int status;
  VALUE rv_result = rb_protect(ruby_c::rb_require_protect,rv_file_name,&status);

  // - ERROR -
  if (status)
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
@begin ucl_params
<
name:c_bi_class_string
>
class c_bi_class_ruby_interpreter
method gv_get
static_method
; @end

  VALUE rv_result = rb_gv_get(((string_s *)src_0_location->v_data_ptr)->data);

  unsigned value_idx = ruby_c::keep_value(rv_result);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_ruby_value,value_idx);
  BIC_SET_RESULT(new_location);

  return true;
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
  printf("RubyInterpreter");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class RUBY_SYMBOL -
built_in_class_s ruby_symbol_class =
{/*{{{*/
  "RubySymbol",
  c_modifier_public | c_modifier_final,
  3, ruby_symbol_methods,
  0, ruby_symbol_variables,
  bic_ruby_symbol_consts,
  bic_ruby_symbol_init,
  bic_ruby_symbol_clear,
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

built_in_method_s ruby_symbol_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_ruby_symbol_operator_binary_equal
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_ruby_symbol_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_ruby_symbol_method_print_0
  },
};/*}}}*/

built_in_variable_s ruby_symbol_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_ruby_symbol_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_ruby_symbol_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (long long int)(ID)0;
}/*}}}*/

void bic_ruby_symbol_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

bool bic_ruby_symbol_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_ruby_symbol_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ID rv_id = (long long int)dst_location->v_data_ptr;

  // - retrieve name of symbol -
  VALUE rv_string = rb_id2str(rv_id);
  cassert(rv_string);

  // - create string object -
  unsigned name_length = RSTRING_LEN(rv_string);
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->create(name_length + 1);
  string_ptr->data[0] = ':';
  memcpy(string_ptr->data + 1,RSTRING_PTR(rv_string),name_length);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_ruby_symbol_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ID rv_id = (long long int)dst_location->v_data_ptr;

  // - retrieve name of symbol -
  VALUE rv_string = rb_id2str(rv_id);
  cassert(rv_string);

  // - write value to standard output -
  fputc(':',stdout);
  fwrite(RSTRING_PTR(rv_string),RSTRING_LEN(rv_string),1,stdout);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

// - class RUBY_VALUE -
built_in_class_s ruby_value_class =
{/*{{{*/
  "RubyValue",
  c_modifier_public | c_modifier_final,
  7, ruby_value_methods,
  0, ruby_value_variables,
  bic_ruby_value_consts,
  bic_ruby_value_init,
  bic_ruby_value_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  bic_ruby_value_invoke,
  bic_ruby_value_member
};/*}}}*/

built_in_method_s ruby_value_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_ruby_value_operator_binary_equal
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_ruby_value_operator_binary_le_br_re_br
  },
  {
    "RubyValue#1",
    c_modifier_public | c_modifier_final,
    bic_ruby_value_method_RubyValue_1
  },
  {
    "_new#1",
    c_modifier_public | c_modifier_final,
    bic_ruby_value_method__new_1
  },
  {
    "_value#0",
    c_modifier_public | c_modifier_final,
    bic_ruby_value_method__value_0
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
  BIC_CLASS_EMPTY_VARIABLES
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
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - method name reference -
  string_s &name_ref = ((interpreter_s *)it.interpreter_ptr)->method_symbol_names[code[icl_name_idx]];

  // - parameter count and method name length -
  unsigned param_cnt = (unsigned)code[icl_parm_cnt] - 1;
  unsigned name_length = strchr(name_ref.data,'#') - name_ref.data;

  // - retrieve object -
  int status = STATUS_OK;
  VALUE rv_dst = ruby_c::create_ruby_value(it,dst_location,status);

  // - ERROR -
  if (status)
  {
    exception_s::throw_exception(it,module.error_base + c_error_RUBY_VALUE_WRONG_VALUE_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - prepare parameters -
  VALUE rv_params[c_max_method_param_cnt];

  if (param_cnt > 0)
  {
    unsigned param_idx = 0;
    do {
      location_s *param_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx + param_idx]);
      rv_params[param_idx] = ruby_c::create_ruby_value(it,param_location,status);

      // - ERROR -
      if (status)
      {
        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_RUBY_VALUE_INVOKE_METHOD_WRONG_PARAMETER,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(param_idx);

        return false;
      }
    } while(++param_idx < param_cnt);
  }

  // - retrieve method id -
  ID rv_id = rb_intern2(name_ref.data,name_length);

  // - prepare call arguments -
  call_args_s args = {rv_dst,rv_id,param_cnt,rv_params};

  // - call object method -
  VALUE rv_result = rb_protect(ruby_c::rb_funcallv_protect,(VALUE)&args,&status);

  // - ERROR -
  if (status)
  {
    BIC_RUBY_INTERPRETER_RETRIEVE_ERROR_LOCATION();

    exception_s::throw_exception(it,module.error_base + c_error_RUBY_VALUE_INVOKE_METHOD_ERROR,operands[c_source_pos_idx],err_location);
    return false;
  }

  unsigned result_idx = ruby_c::keep_value(rv_result);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_ruby_value,result_idx);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_ruby_value_member(interpreter_thread_s &it,uli *code,unsigned stack_base)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + code[ioms_stack_object]);

  // - retrieve member name -
  string_s &name_ref = ((interpreter_s *)it.interpreter_ptr)->variable_symbol_names[code[ioms_var_name]];

  // - create key object -
  VALUE rv_key = rb_str_tmp_new(name_ref.size);

  // - construct instance value name -
  char *key_data = RSTRING_PTR(rv_key);
  key_data[0] = '@';
  memcpy(key_data + 1,name_ref.data,name_ref.size);

  // - retrieve object -
  int status = STATUS_OK;
  VALUE rv_dst = ruby_c::create_ruby_value(it,dst_location,status);

  // - ERROR -
  if (status)
  {
    exception_s::throw_exception(it,module.error_base + c_error_RUBY_VALUE_WRONG_VALUE_REFERENCE,code[ioms_source_pos],(location_s *)it.blank_location);
    return false;
  }

  // - create reference object -
  ruby_reference_s *ruby_iv_ref_ptr = (ruby_reference_s *)cmalloc(sizeof(ruby_reference_s));
  ruby_iv_ref_ptr->init();

  ruby_iv_ref_ptr->obj_idx = ruby_c::keep_value(rv_dst);
  ruby_iv_ref_ptr->key_idx = ruby_c::keep_value(rv_key);

  // - create target location -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_ruby_iv_ref,ruby_iv_ref_ptr);

  pointer &trg_location = it.data_stack[stack_base + code[ioms_stack_trg]];
  it.release_location_ptr((location_s *)trg_location);
  trg_location = (pointer)new_location;

  return true;
}/*}}}*/

bool bic_ruby_value_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_ruby_value_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  int status = STATUS_OK;
  VALUE rv_dst = ruby_c::create_ruby_value(it,dst_location,status);

  // - ERROR -
  if (status)
  {
    exception_s::throw_exception(it,module.error_base + c_error_RUBY_VALUE_WRONG_VALUE_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  VALUE rv_src_0 = ruby_c::create_ruby_value(it,src_0_location,status);

  // - ERROR -
  if (status)
  {
    exception_s::throw_exception(it,module.error_base + c_error_RUBY_VALUE_ITEM_SELECT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  switch (TYPE(rv_dst))
  {
  case T_ARRAY:
    {/*{{{*/
      switch (TYPE(rv_src_0))
      {
      case T_FIXNUM:
      case T_BIGNUM:
      case T_FLOAT:
        break;

      // - ERROR -
      default:
        exception_s::throw_exception(it,module.error_base + c_error_RUBY_VALUE_ITEM_SELECT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }
    }/*}}}*/
    break;
  case T_HASH:
    break;

  // - ERROR -
  default:
    exception_s::throw_exception(it,module.error_base + c_error_RUBY_VALUE_ITEM_SELECT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create reference object -
  ruby_reference_s *ruby_item_ref = (ruby_reference_s *)cmalloc(sizeof(ruby_reference_s));
  ruby_item_ref->init();

  ruby_item_ref->obj_idx = ruby_c::keep_value(rv_dst);
  ruby_item_ref->key_idx = ruby_c::keep_value(rv_src_0);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_ruby_item_ref,ruby_item_ref);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_ruby_value_method_RubyValue_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  int status = STATUS_OK;
  VALUE rv_value = ruby_c::create_ruby_value(it,src_0_location,status);

  // - ERROR -
  if (status)
  {
    exception_s::throw_exception(it,module.error_base + c_error_RUBY_VALUE_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  unsigned value_idx = ruby_c::keep_value(rv_value);
  dst_location->v_data_ptr = value_idx;

  return true;
}/*}}}*/

bool bic_ruby_value_method__new_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
parameters:c_bi_class_array
>
method _new
; @end

  int status = STATUS_OK;
  VALUE rv_dst = ruby_c::create_ruby_value(it,dst_location,status);

  // - ERROR -
  if (status)
  {
    exception_s::throw_exception(it,module.error_base + c_error_RUBY_VALUE_WRONG_VALUE_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  pointer_array_s *array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

  // - prepare parameters -
  unsigned param_cnt = array_ptr->used;
  VALUE rv_params[c_max_method_param_cnt];

  if (param_cnt > 0)
  {
    unsigned param_idx = 0;
    do {
      location_s *param_location = it.get_location_value(array_ptr->data[param_idx]);
      rv_params[param_idx] = ruby_c::create_ruby_value(it,param_location,status);

      // - ERROR -
      if (status)
      {
        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_RUBY_VALUE_INVOKE_METHOD_WRONG_PARAMETER,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(param_idx);

        return false;
      }
    } while(++param_idx < param_cnt);
  }

  // - prepare call arguments -
  call_args_s args = {rv_dst,rb_intern2("new",3),param_cnt,rv_params};

  // - call object method -
  VALUE rv_result = rb_protect(ruby_c::rb_funcallv_protect,(VALUE)&args,&status);

  // - ERROR -
  if (status)
  {
    BIC_RUBY_INTERPRETER_RETRIEVE_ERROR_LOCATION();

    exception_s::throw_exception(it,module.error_base + c_error_RUBY_VALUE_INVOKE_METHOD_ERROR,operands[c_source_pos_idx],err_location);
    return false;
  }

  unsigned result_idx = ruby_c::keep_value(rv_result);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_ruby_value,result_idx);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_ruby_value_method__value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  int status = STATUS_OK;
  VALUE rv_dst = ruby_c::create_ruby_value(it,dst_location,status);

  // - ERROR -
  if (status)
  {
    exception_s::throw_exception(it,module.error_base + c_error_RUBY_VALUE_WRONG_VALUE_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  location_s *location_ptr = ruby_c::ruby_value_value(it,rv_dst,operands[c_source_pos_idx]);

  // - ERROR -
  if (location_ptr == nullptr)
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
  printf("RubyValue");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class RUBY_IV_REF -
built_in_class_s ruby_iv_ref_class =
{/*{{{*/
  "RubyIVRef",
  c_modifier_public | c_modifier_final,
  6, ruby_iv_ref_methods,
  0, ruby_iv_ref_variables,
  bic_ruby_iv_ref_consts,
  bic_ruby_iv_ref_init,
  bic_ruby_iv_ref_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  bic_ruby_value_invoke,
  bic_ruby_value_member
};/*}}}*/

built_in_method_s ruby_iv_ref_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_ruby_iv_ref_operator_binary_equal
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_ruby_value_operator_binary_le_br_re_br
  },
  {
    "_new#1",
    c_modifier_public | c_modifier_final,
    bic_ruby_value_method__new_1
  },
  {
    "_value#0",
    c_modifier_public | c_modifier_final,
    bic_ruby_value_method__value_0
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

built_in_variable_s ruby_iv_ref_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_ruby_iv_ref_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_ruby_iv_ref_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (ruby_reference_s *)nullptr;
}/*}}}*/

void bic_ruby_iv_ref_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  ruby_reference_s *rv_iv_ref_ptr = (ruby_reference_s *)location_ptr->v_data_ptr;

  if (rv_iv_ref_ptr != nullptr)
  {
    rv_iv_ref_ptr->clear(it);
    cfree(rv_iv_ref_ptr);
  }
}/*}}}*/

bool bic_ruby_iv_ref_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
value:ignore
>
method operator_binary_equal
; @end

  int status = STATUS_OK;
  VALUE rv_src_0 = ruby_c::create_ruby_value(it,src_0_location,status);

  // - ERROR -
  if (status)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_equal#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - ERROR -
  if (!((ruby_reference_s *)dst_location->v_data_ptr)->set_iv(rv_src_0))
  {
    exception_s::throw_exception(it,module.error_base + c_error_RUBY_VALUE_SET_INSTANCE_VALUE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  unsigned src_0_idx = ruby_c::keep_value(rv_src_0);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_ruby_value,src_0_idx);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

// - class RUBY_ITEM_REF -
built_in_class_s ruby_item_ref_class =
{/*{{{*/
  "RubyItemRef",
  c_modifier_public | c_modifier_final,
  6, ruby_item_ref_methods,
  0, ruby_item_ref_variables,
  bic_ruby_item_ref_consts,
  bic_ruby_item_ref_init,
  bic_ruby_item_ref_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  bic_ruby_value_invoke,
  bic_ruby_value_member
};/*}}}*/

built_in_method_s ruby_item_ref_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_ruby_item_ref_operator_binary_equal
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_ruby_value_operator_binary_le_br_re_br
  },
  {
    "_new#1",
    c_modifier_public | c_modifier_final,
    bic_ruby_value_method__new_1
  },
  {
    "_value#0",
    c_modifier_public | c_modifier_final,
    bic_ruby_value_method__value_0
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

built_in_variable_s ruby_item_ref_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_ruby_item_ref_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_ruby_item_ref_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (ruby_reference_s *)nullptr;
}/*}}}*/

void bic_ruby_item_ref_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  ruby_reference_s *rv_iref_ptr = (ruby_reference_s *)location_ptr->v_data_ptr;

  if (rv_iref_ptr != nullptr)
  {
    rv_iref_ptr->clear(it);
    cfree(rv_iref_ptr);
  }
}/*}}}*/

bool bic_ruby_item_ref_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
value:ignore
>
method operator_binary_equal
; @end

  int status = STATUS_OK;
  VALUE rv_src_0 = ruby_c::create_ruby_value(it,src_0_location,status);

  // - ERROR -
  if (status)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_equal#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - ERROR -
  if (!((ruby_reference_s *)dst_location->v_data_ptr)->set_item(rv_src_0))
  {
    exception_s::throw_exception(it,module.error_base + c_error_RUBY_VALUE_SET_ITEM_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  unsigned src_0_idx = ruby_c::keep_value(rv_src_0);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_ruby_value,src_0_idx);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

