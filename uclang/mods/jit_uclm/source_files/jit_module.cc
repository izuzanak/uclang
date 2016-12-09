
@begin
include "jit_module.h"
@end

// - JIT indexes of built in classes -
unsigned c_bi_class_jit_context = c_idx_not_exist;
unsigned c_bi_class_jit_function = c_idx_not_exist;

// - JIT module -
built_in_module_s module =
{/*{{{*/
  2,                   // Class count
  jit_classes,         // Classes

  0,                   // Error base index
  16,                  // Error count
  jit_error_strings,   // Error strings

  jit_initialize,      // Initialize function
  jit_print_exception, // Print exceptions function
};/*}}}*/

// - JIT classes -
built_in_class_s *jit_classes[] =
{/*{{{*/
  &jit_context_class,
  &jit_function_class,
};/*}}}*/

// - JIT error strings -
const char *jit_error_strings[] =
{/*{{{*/
  "error_JIT_PARSER_UNRECOGNIZED_TERMINAL",
  "error_JIT_PARSER_SYNTAX_ERROR",
  "error_JIT_PARSER_DUPLICIT_FUNCTION_DEFINITION",
  "error_JIT_PARSER_DUPLICIT_PARAMETER_IDENTIFIER",
  "error_JIT_PARSER_DUPLICIT_VAR_PARAM_IDENTIFIER",
  "error_JIT_PARSER_DUPLICIT_LABEL",
  "error_JIT_PARSER_UNKNOWN_DATA_TYPE",
  "error_JIT_PARSER_UNDECLARED_VARIABLE",
  "error_JIT_PARSER_UNDECLARED_FUNCTION",
  "error_JIT_PARSER_INCOMPATIBLE_VALUE_TYPES",
  "error_JIT_PARSER_USED_UNDEFINED_LABEL",

  "error_JIT_CONTEXT_CREATE_ERROR",
  "error_JIT_FUNCTION_PARAM_WRONG_COUNT",
  "error_JIT_FUNCTION_PARAM_POINTER_NOT_SUPPORTED",
  "error_JIT_FUNCTION_PARAM_WRONG_TYPE",
  "error_JIT_FUNCTION_PARAM_UNSUPPORTED_TYPE",
};/*}}}*/

// - JIT initialize -
bool jit_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize jit_context class identifier -
  c_bi_class_jit_context = class_base_idx++;

  // - initialize jit_function class identifier -
  c_bi_class_jit_function = class_base_idx++;

  return true;
}/*}}}*/

// - JIT print exception -
bool jit_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_JIT_PARSER_UNRECOGNIZED_TERMINAL:
  case c_error_JIT_PARSER_SYNTAX_ERROR:
  case c_error_JIT_PARSER_DUPLICIT_FUNCTION_DEFINITION:
  case c_error_JIT_PARSER_DUPLICIT_PARAMETER_IDENTIFIER:
  case c_error_JIT_PARSER_DUPLICIT_VAR_PARAM_IDENTIFIER:
  case c_error_JIT_PARSER_DUPLICIT_LABEL:
  case c_error_JIT_PARSER_UNKNOWN_DATA_TYPE:
  case c_error_JIT_PARSER_UNDECLARED_VARIABLE:
  case c_error_JIT_PARSER_UNDECLARED_FUNCTION:
  case c_error_JIT_PARSER_INCOMPATIBLE_VALUE_TYPES:
    {
      string_s &jit_source = *((string_s *)((location_s *)exception.obj_location)->v_data_ptr);
      unsigned jit_source_pos = exception.params[0];

      fprintf(stderr," ---------------------------------------- \n");
      fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
      fprintf(stderr,"JIT source string on line: %u\n",jit_source.get_character_line(jit_source_pos));

      switch (exception.type - module.error_base)
      {
      case c_error_JIT_PARSER_UNRECOGNIZED_TERMINAL:
        print_error_show_line(jit_source,jit_source_pos);
        fprintf(stderr,"Unrecognized input terminal\n");
        fprintf(stderr," ---------------------------------------- \n");
        break;
      case c_error_JIT_PARSER_SYNTAX_ERROR:
        print_error_show_line(jit_source,jit_source_pos);
        fprintf(stderr,"Wrong program syntax\n");
        fprintf(stderr," ---------------------------------------- \n");
        break;
      case c_error_JIT_PARSER_DUPLICIT_FUNCTION_DEFINITION:
        print_error_show_line(jit_source,jit_source_pos);
        fprintf(stderr,"Duplicit function definition\n");
        fprintf(stderr," ---------------------------------------- \n");
        break;
      case c_error_JIT_PARSER_DUPLICIT_PARAMETER_IDENTIFIER:
        print_error_show_line(jit_source,jit_source_pos);
        fprintf(stderr,"Duplicit parameter identifier\n");
        fprintf(stderr," ---------------------------------------- \n");
        break;
      case c_error_JIT_PARSER_DUPLICIT_VAR_PARAM_IDENTIFIER:
        print_error_show_line(jit_source,jit_source_pos);
        fprintf(stderr,"Duplicit variable/parameter identifier\n");
        fprintf(stderr," ---------------------------------------- \n");
        break;
      case c_error_JIT_PARSER_DUPLICIT_LABEL:
        print_error_show_line(jit_source,jit_source_pos);
        fprintf(stderr,"Duplicit label\n");
        fprintf(stderr," ---------------------------------------- \n");
        break;
      case c_error_JIT_PARSER_UNKNOWN_DATA_TYPE:
        print_error_show_line(jit_source,jit_source_pos);
        fprintf(stderr,"Unknown data type\n");
        fprintf(stderr," ---------------------------------------- \n");
        break;
      case c_error_JIT_PARSER_UNDECLARED_VARIABLE:
        print_error_show_line(jit_source,jit_source_pos);
        fprintf(stderr,"Variable was not declared\n");
        fprintf(stderr," ---------------------------------------- \n");
        break;
      case c_error_JIT_PARSER_UNDECLARED_FUNCTION:
        print_error_show_line(jit_source,jit_source_pos);
        fprintf(stderr,"No matching function for call\n");
        fprintf(stderr," ---------------------------------------- \n");
        break;
      case c_error_JIT_PARSER_INCOMPATIBLE_VALUE_TYPES:
        print_error_show_line(jit_source,jit_source_pos);
        fprintf(stderr,"Incompatible value type/s for operation\n");
        fprintf(stderr," ---------------------------------------- \n");
        break;
      }
    }
    break;
  case c_error_JIT_PARSER_USED_UNDEFINED_LABEL:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUsed but undefined label \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_JIT_CONTEXT_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating JIT context\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_JIT_FUNCTION_PARAM_WRONG_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCall of JIT function require %" HOST_LL_FORMAT "d parameter/s\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_JIT_FUNCTION_PARAM_POINTER_NOT_SUPPORTED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nJIT pointer parameters are not supported yet.\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_JIT_FUNCTION_PARAM_WRONG_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nJIT call, at position %" HOST_LL_FORMAT "d expected %s received %s\n",
            exception.params[0],it.class_symbol_names[it.class_records[exception.params[1]].name_idx].data,it.class_symbol_names[it.class_records[exception.params[2]].name_idx].data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_JIT_FUNCTION_PARAM_UNSUPPORTED_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nJIT unsupported parameter type.\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class JIT_CONTEXT -
built_in_class_s jit_context_class =
{/*{{{*/
  "JitContext",
  c_modifier_public | c_modifier_final,
  5, jit_context_methods,
  10, jit_context_variables,
  bic_jit_context_consts,
  bic_jit_context_init,
  bic_jit_context_clear,
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

built_in_method_s jit_context_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_jit_context_operator_binary_equal
  },
  {
    "JitContext#0",
    c_modifier_public | c_modifier_final,
    bic_jit_context_method_JitContext_0
  },
  {
    "create_fun#1",
    c_modifier_public | c_modifier_final,
    bic_jit_context_method_create_fun_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_jit_context_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_jit_context_method_print_0
  },
};/*}}}*/

built_in_variable_s jit_context_variables[] =
{/*{{{*/

  // - jit data types -
  { "TYPE_I8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_U8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_I16", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_U16", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_I32", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_U32", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_I64", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_U64", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_F32", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_F64", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_jit_context_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert jit data type constants -
  {
    const_locations.push_blanks(10);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 10);

#define CREATE_JIT_CONTEXT_DATA_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_JIT_CONTEXT_DATA_TYPE_BIC_STATIC(c_var_type_i8);
    CREATE_JIT_CONTEXT_DATA_TYPE_BIC_STATIC(c_var_type_u8);
    CREATE_JIT_CONTEXT_DATA_TYPE_BIC_STATIC(c_var_type_i16);
    CREATE_JIT_CONTEXT_DATA_TYPE_BIC_STATIC(c_var_type_u16);
    CREATE_JIT_CONTEXT_DATA_TYPE_BIC_STATIC(c_var_type_i32);
    CREATE_JIT_CONTEXT_DATA_TYPE_BIC_STATIC(c_var_type_u32);
    CREATE_JIT_CONTEXT_DATA_TYPE_BIC_STATIC(c_var_type_i64);
    CREATE_JIT_CONTEXT_DATA_TYPE_BIC_STATIC(c_var_type_u64);
    CREATE_JIT_CONTEXT_DATA_TYPE_BIC_STATIC(c_var_type_f32);
    CREATE_JIT_CONTEXT_DATA_TYPE_BIC_STATIC(c_var_type_f64);
  }

}/*}}}*/

void bic_jit_context_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (jit_context_s *)NULL;
}/*}}}*/

void bic_jit_context_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  jit_context_s *jc_ptr = (jit_context_s *)location_ptr->v_data_ptr;

  // - if jit context object exists -
  if (jc_ptr != NULL)
  {
    jc_ptr->clear(it);
    cfree(jc_ptr);
  }
}/*}}}*/

bool bic_jit_context_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_jit_context_method_JitContext_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - create jit context object -
  jit_context_s *jc_ptr = (jit_context_s *)cmalloc(sizeof(jit_context_s));
  jc_ptr->init();

  // - ERROR -
  if ((jc_ptr->context = jit_context_create()) == NULL)
  {
    jc_ptr->clear(it);
    cfree(jc_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_JIT_CONTEXT_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  dst_location->v_data_ptr = (jit_context_s *)jc_ptr;

  return true;
}/*}}}*/

bool bic_jit_context_method_create_fun_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("create_fun#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  jit_context_s *jc_ptr = (jit_context_s *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - start function build -
  jit_context_build_start(jc_ptr->context);

  // - create jit parser -
  jit_parser_s parser;
  parser.init();

  parser.it_ptr = &it;
  parser.ucl_context = jc_ptr;

  // - parse source string -
  parser.source_string = *string_ptr;
  parser.tmp_modifiers = 0;

  if (!parser.parse_source())
  {
    parser.clear();

    // - retrieve thrown exception -
    exception_s *exception = (exception_s *)((location_s *)it.exception_location)->v_data_ptr;

    // - modify error type and position -
    exception->type += module.error_base;
    exception->position = operands[c_source_pos_idx];

    // - add source string as object to exception -
    it.release_location_ptr((location_s *)exception->obj_location);
    src_0_location->v_reference_cnt.atomic_inc();
    exception->obj_location = src_0_location;

    return false;
  }

  // FIXME debug test
  cassert(parser.tmp_var_types.used == 0);
  cassert(parser.exp_node_stack.used == 0);
  cassert(parser.label_idxs.used == 0);
  cassert(parser.cb_label_idxs.used == 0);

  // - check named labels -
  if (parser.named_label_idxs.used != 0)
  {
    unsigned *nli_ptr = parser.named_label_idxs.data;
    unsigned *nli_ptr_end = nli_ptr + parser.named_label_idxs.used;
    do {

      // - if named label exist -
      if (*nli_ptr != c_idx_not_exist)
      {
        // - ERROR -
        if (!jit_block_from_label((jit_function_t)parser.jit_function,parser.labels[*nli_ptr]))
        {
          // - create label name location -
          string_s *string_ptr = it.get_new_string_ptr();
          *string_ptr = parser.label_names[nli_ptr - parser.named_label_idxs.data];

          BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_string,string_ptr,0);

          // - release parser -
          parser.clear();

          exception_s::throw_exception(it,module.error_base + c_error_JIT_PARSER_USED_UNDEFINED_LABEL,operands[c_source_pos_idx],new_location);
          return false;
        }
      }
    } while(++nli_ptr < nli_ptr_end);
  }

  // FIXME debug output
  //jit_dump_function(stdout,(jit_function_t)parser.jit_function,NULL);

  // - compile function -
  jit_function_compile((jit_function_t)parser.jit_function);

  // - register function signature -
  unsigned sig_idx = jc_ptr->ucl_signatures.swap_insert(parser.ucl_signature);

  // - register function name -
  unsigned fun_idx = jc_ptr->fun_names.insert(parser.fun_record.name);
  cassert(fun_idx == sig_idx);

  while (jc_ptr->fun_records.used <= fun_idx)
  {
    jc_ptr->fun_records.push_blank();
  }

  // - store function pointer in context -
  jc_ptr->fun_records.last().swap(parser.fun_record);

  // - release jit parser -
  parser.clear();

  // - end function build -
  jit_context_build_end(jc_ptr->context);

  // - create jit function object -
  jit_function_s *jf_ptr = (jit_function_s *)cmalloc(sizeof(jit_function_s));
  jf_ptr->init();

  // - set reference to jit context -
  dst_location->v_reference_cnt.atomic_inc();
  jf_ptr->jc_ptr = dst_location;

  // - set function index -
  jf_ptr->index = fun_idx;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_jit_function,jf_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_jit_context_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("JitContext"),"JitContext");
  );

  return true;
}/*}}}*/

bool bic_jit_context_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("JitContext");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class JIT_FUNCTION -
built_in_class_s jit_function_class =
{/*{{{*/
  "JitFunction",
  c_modifier_public | c_modifier_final,
  5, jit_function_methods,
  0, jit_function_variables,
  bic_jit_function_consts,
  bic_jit_function_init,
  bic_jit_function_clear,
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

built_in_method_s jit_function_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_jit_function_operator_binary_equal
  },
  {
    "signature#0",
    c_modifier_public | c_modifier_final,
    bic_jit_function_method_signature_0
  },
  {
    "call#1",
    c_modifier_public | c_modifier_final,
    bic_jit_function_method_call_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_jit_function_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_jit_function_method_print_0
  },
};/*}}}*/

built_in_variable_s jit_function_variables[] =
{/*{{{*/
};/*}}}*/

void bic_jit_function_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_jit_function_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (jit_function_s *)NULL;
}/*}}}*/

void bic_jit_function_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  jit_function_s *jf_ptr = (jit_function_s *)location_ptr->v_data_ptr;

  // - if jit function object exists -
  if (jf_ptr != NULL)
  {
    jf_ptr->clear(it);
    cfree(jf_ptr);
  }
}/*}}}*/

bool bic_jit_function_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_jit_function_method_signature_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  jit_function_s *jf_ptr = (jit_function_s *)dst_location->v_data_ptr;
  jit_context_s *jc_ptr = (jit_context_s *)jf_ptr->jc_ptr->v_data_ptr;

  string_s *string_ptr = it.get_new_string_ptr();
  *string_ptr = jc_ptr->ucl_signatures[jf_ptr->index];

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_jit_function_method_call_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_array)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("call#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  jit_function_s *jf_ptr = (jit_function_s *)dst_location->v_data_ptr;
  jit_context_s *jc_ptr = (jit_context_s *)jf_ptr->jc_ptr->v_data_ptr;

  // - retrieve function record -
  fun_record_s &fun_record = jc_ptr->fun_records[jf_ptr->index];

  // - retrieve type references -
  var_types_s &param_types = fun_record.param_types;
  var_type_s &ret_type = fun_record.ret_type;

  // - retrieve argument array -
  pointer_array_s *array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (param_types.used != array_ptr->used)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_JIT_FUNCTION_PARAM_WRONG_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(param_types.used);

    return false;
  }

  // - parameter values -
  char param_values[param_types.used * 8];

  // - parameter values pointers -
  pointer params[param_types.used];

  // - process parameters -
  if (param_types.used > 0)
  {
    // - parameter type pointer -
    var_type_s *pt_ptr = param_types.data;
    var_type_s *pt_ptr_end = pt_ptr + param_types.used;

    // - parameter array pointer -
    pointer *pa_ptr = array_ptr->data;

    // - parameter value pointer -
    char *pv_ptr = param_values;

    // - parameter pointer pointer -
    pointer *pp_ptr = params;

    do {
      location_s *item_location = it.get_location_value(*pa_ptr);

      // - parameter is pointer -
      if (pt_ptr->is_pointer())
      {
        // - ERROR -
        if (pt_ptr->pointer_level > 1)
        {
          exception_s::throw_exception(it,module.error_base + c_error_JIT_FUNCTION_PARAM_UNSUPPORTED_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
          return false;
        }

        switch (pt_ptr->type_id)
        {
          case c_var_type_i8:
          case c_var_type_u8:
            {
              // - ERROR -
              if (item_location->v_type != c_bi_class_string)
              {
                exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_JIT_FUNCTION_PARAM_WRONG_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
                new_exception->params.push(pt_ptr - param_types.data);
                new_exception->params.push(c_bi_class_string);
                new_exception->params.push(item_location->v_type);

                return false;
              }

              // - store param pointer -
              *pp_ptr++ = pv_ptr;

              // - store param value -
              *((jit_ptr *)pv_ptr) = ((string_s *)item_location->v_data_ptr)->data;
              pv_ptr += sizeof(jit_ptr);
            }
            break;

          default:

          // - ERROR -
          exception_s::throw_exception(it,module.error_base + c_error_JIT_FUNCTION_PARAM_UNSUPPORTED_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
          return false;
        }
      }

      // - parameter is not pointer -
      else
      {
        switch (pt_ptr->type_id)
        {
          case c_var_type_i8:
          case c_var_type_u8:
          case c_var_type_i16:
          case c_var_type_u16:
          case c_var_type_i32:
          case c_var_type_u32:
          case c_var_type_i64:
          case c_var_type_u64:
            {/*{{{*/
              long long int value;

              // - ERROR -
              if (!it.retrieve_integer(item_location,value))
              {
                exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_JIT_FUNCTION_PARAM_WRONG_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
                new_exception->params.push(pt_ptr - param_types.data);
                new_exception->params.push(c_bi_class_integer);
                new_exception->params.push(item_location->v_type);

                return false;
              }

              // - store param pointer -
              *pp_ptr++ = pv_ptr;

              // - store param value -
              switch (pt_ptr->type_id)
              {
                case c_var_type_i8:
                  *((jit_sbyte *)pv_ptr) = value;
                  pv_ptr += sizeof(jit_sbyte);
                  break;
                case c_var_type_u8:
                  *((jit_ubyte *)pv_ptr) = value;
                  pv_ptr += sizeof(jit_ubyte);
                  break;
                case c_var_type_i16:
                  *((jit_short *)pv_ptr) = value;
                  pv_ptr += sizeof(jit_short);
                  break;
                case c_var_type_u16:
                  *((jit_ushort *)pv_ptr) = value;
                  pv_ptr += sizeof(jit_ushort);
                  break;
                case c_var_type_i32:
                  *((jit_int *)pv_ptr) = value;
                  pv_ptr += sizeof(jit_int);
                  break;
                case c_var_type_u32:
                  *((jit_uint *)pv_ptr) = value;
                  pv_ptr += sizeof(jit_uint);
                  break;
                case c_var_type_i64:
                  *((jit_long *)pv_ptr) = value;
                  pv_ptr += sizeof(jit_long);
                  break;
                case c_var_type_u64:
                  *((jit_ulong *)pv_ptr) = value;
                  pv_ptr += sizeof(jit_ulong);
                  break;
              }
            }/*}}}*/
            break;
          case c_var_type_f32:
          case c_var_type_f64:
            {/*{{{*/
              double value;

              // - ERROR -
              if (!it.retrieve_float(item_location,value))
              {
                exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_JIT_FUNCTION_PARAM_WRONG_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
                new_exception->params.push(pt_ptr - param_types.data);
                new_exception->params.push(c_bi_class_float);
                new_exception->params.push(item_location->v_type);

                return false;
              }

              // - store param pointer -
              *pp_ptr++ = pv_ptr;

              // - store param value -
              switch (pt_ptr->type_id)
              {
                case c_var_type_f32:
                  *((jit_float32 *)pv_ptr) = value;
                  pv_ptr += sizeof(jit_float32);
                  break;

                case c_var_type_f64:
                  *((jit_float64 *)pv_ptr) = value;
                  pv_ptr += sizeof(jit_float64);
                  break;
              }
            }/*}}}*/
            break;

          // - ERROR -
          default:
          {
            exception_s::throw_exception(it,module.error_base + c_error_JIT_FUNCTION_PARAM_UNSUPPORTED_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
            return false;
          }
        }
      }
    } while(++pa_ptr,++pt_ptr < pt_ptr_end);
  }

  // - call jit function -
  long long int ret_value;
  char *ret_val = (char *)&ret_value;
  jit_function_apply((jit_function_t)fun_record.jit_function,params,ret_val);

  // - process return value -
  if (ret_type.is_pointer())
  {
    // - ERROR -
    exception_s::throw_exception(it,module.error_base + c_error_JIT_FUNCTION_PARAM_POINTER_NOT_SUPPORTED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  switch (ret_type.type_id)
  {
    case c_var_type_i8:
    case c_var_type_u8:
    case c_var_type_i16:
    case c_var_type_u16:
    case c_var_type_i32:
    case c_var_type_u32:
    case c_var_type_i64:
    case c_var_type_u64:
      {/*{{{*/
        long long int result = 0;

        switch (ret_type.type_id)
        {
          case c_var_type_i8:
            result = *((jit_sbyte *)ret_val);
            break;
          case c_var_type_u8:
            result = *((jit_ubyte *)ret_val);
            break;
          case c_var_type_i16:
            result = *((jit_short *)ret_val);
            break;
          case c_var_type_u16:
            result = *((jit_ushort *)ret_val);
            break;
          case c_var_type_i32:
            result = *((jit_int *)ret_val);
            break;
          case c_var_type_u32:
            result = *((jit_uint *)ret_val);
            break;
          case c_var_type_i64:
            result = *((jit_long *)ret_val);
            break;
          case c_var_type_u64:
            result = *((jit_ulong *)ret_val);
            break;
          default:
            cassert(0);
        }

        BIC_SIMPLE_SET_RES(c_bi_class_integer,result);
      }/*}}}*/
      break;
    case c_var_type_f32:
    case c_var_type_f64:
      {/*{{{*/
        double result;

        switch (ret_type.type_id)
        {
          case c_var_type_f32:
            result = *((jit_float32 *)ret_val);
            break;
          case c_var_type_f64:
            result = *((jit_float64 *)ret_val);
            break;
        }

        BIC_SIMPLE_SET_RES(c_bi_class_float,result);
      }/*}}}*/
      break;

    // - ERROR -
    default:
    {
      exception_s::throw_exception(it,module.error_base + c_error_JIT_FUNCTION_PARAM_UNSUPPORTED_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }
  }

  return true;
}/*}}}*/

bool bic_jit_function_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("JitFunction"),"JitFunction");
  );

  return true;
}/*}}}*/

bool bic_jit_function_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("JitFunction");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

