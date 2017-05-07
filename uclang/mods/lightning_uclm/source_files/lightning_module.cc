
@begin
include "lightning_module.h"
@end

// - LIGHTNING indexes of built in classes -
unsigned c_bi_class_ltg_jit_state = c_idx_not_exist;

// - LIGHTNING module -
built_in_module_s module =
{/*{{{*/
  1,                         // Class count
  lightning_classes,         // Classes

  0,                         // Error base index
  2,                         // Error count
  lightning_error_strings,   // Error strings

  lightning_initialize,      // Initialize function
  lightning_print_exception, // Print exceptions function
};/*}}}*/

// - LIGHTNING classes -
built_in_class_s *lightning_classes[] =
{/*{{{*/
  &ltg_jit_state_class,
};/*}}}*/

// - LIGHTNING error strings -
const char *lightning_error_strings[] =
{/*{{{*/
  "error_LIGHTNING_PARSER_UNRECOGNIZED_TERMINAL",
  "error_LIGHTNING_PARSER_SYNTAX_ERROR",
};/*}}}*/

// - LIGHTNING initialize -
bool lightning_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize ltg_jit_state class identifier -
  c_bi_class_ltg_jit_state = class_base_idx++;

  return true;
}/*}}}*/

// - LIGHTNING print exception -
bool lightning_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_LIGHTNING_PARSER_UNRECOGNIZED_TERMINAL:
  case c_error_LIGHTNING_PARSER_SYNTAX_ERROR:
    {
      string_s &ltg_source = *((string_s *)((location_s *)exception.obj_location)->v_data_ptr);
      unsigned ltg_source_pos = exception.params[0];

      fprintf(stderr," ---------------------------------------- \n");
      fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
      fprintf(stderr,"LIGHTNING source string on line: %u\n",ltg_source.get_character_line(ltg_source_pos));

      switch (exception.type - module.error_base)
      {
      case c_error_LIGHTNING_PARSER_UNRECOGNIZED_TERMINAL:
        print_error_show_line(ltg_source,ltg_source_pos);
        fprintf(stderr,"Unrecognized input terminal\n");
        fprintf(stderr," ---------------------------------------- \n");
        break;
      case c_error_LIGHTNING_PARSER_SYNTAX_ERROR:
        print_error_show_line(ltg_source,ltg_source_pos);
        fprintf(stderr,"Wrong program syntax\n");
        fprintf(stderr," ---------------------------------------- \n");
        break;
      }
    }
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class LTG_JIT_STATE -
built_in_class_s ltg_jit_state_class =
{/*{{{*/
  "LtgJitState",
  c_modifier_public | c_modifier_final,
  5, ltg_jit_state_methods,
  10, ltg_jit_state_variables,
  bic_ltg_jit_state_consts,
  bic_ltg_jit_state_init,
  bic_ltg_jit_state_clear,
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

built_in_method_s ltg_jit_state_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_ltg_jit_state_operator_binary_equal
  },
  {
    "LtgJitState#0",
    c_modifier_public | c_modifier_final,
    bic_ltg_jit_state_method_LtgJitState_0
  },
  {
    "create_fun#1",
    c_modifier_public | c_modifier_final,
    bic_ltg_jit_state_method_create_fun_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ltg_jit_state_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ltg_jit_state_method_print_0
  },
};/*}}}*/

built_in_variable_s ltg_jit_state_variables[] =
{/*{{{*/

  // - lightning data types -
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

void bic_ltg_jit_state_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert lightning data type constants -
  {
    const_locations.push_blanks(10);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 10);

#define CREATE_LTG_JIT_STATE_DATA_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_LTG_JIT_STATE_DATA_TYPE_BIC_STATIC(c_val_type_i8);
    CREATE_LTG_JIT_STATE_DATA_TYPE_BIC_STATIC(c_val_type_u8);
    CREATE_LTG_JIT_STATE_DATA_TYPE_BIC_STATIC(c_val_type_i16);
    CREATE_LTG_JIT_STATE_DATA_TYPE_BIC_STATIC(c_val_type_u16);
    CREATE_LTG_JIT_STATE_DATA_TYPE_BIC_STATIC(c_val_type_i32);
    CREATE_LTG_JIT_STATE_DATA_TYPE_BIC_STATIC(c_val_type_u32);
    CREATE_LTG_JIT_STATE_DATA_TYPE_BIC_STATIC(c_val_type_i64);
    CREATE_LTG_JIT_STATE_DATA_TYPE_BIC_STATIC(c_val_type_u64);
    CREATE_LTG_JIT_STATE_DATA_TYPE_BIC_STATIC(c_val_type_f32);
    CREATE_LTG_JIT_STATE_DATA_TYPE_BIC_STATIC(c_val_type_f64);
  }

}/*}}}*/

void bic_ltg_jit_state_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (jit_state_s *)NULL;
}/*}}}*/

void bic_ltg_jit_state_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  jit_state_s *js_ptr = (jit_state_s *)location_ptr->v_data_ptr;

  // - if jit state object exists -
  if (js_ptr != NULL)
  {
    js_ptr->clear(it);
    cfree(js_ptr);
  }
}/*}}}*/

bool bic_ltg_jit_state_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_ltg_jit_state_method_LtgJitState_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - create jit state object -
  jit_state_s *js_ptr = (jit_state_s *)cmalloc(sizeof(jit_state_s));
  js_ptr->init();

  dst_location->v_data_ptr = (jit_state_s *)js_ptr;

  return true;
}/*}}}*/

bool bic_ltg_jit_state_method_create_fun_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
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

  jit_state_s *js_ptr = (jit_state_s *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create lightning parser -
  ltg_parser_s parser;
  parser.init();

  parser.it_ptr = &it;
  parser.ucl_jit_state = js_ptr;

  // - create new jit state -
  parser._jit = jit_new_state();
  js_ptr->jit_states.push(parser._jit);

  // - parse source string -
  parser.source_string = *string_ptr;
  parser.tmp_modifiers = 0;

  if (!parser.parse_source())
  {
    parser.clear();

    // - destroy jit state -
    jit_state_t_ptr _jit = (jit_state_t *)js_ptr->jit_states.pop();
    jit_clear_state();
    jit_destroy_state();

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
  fprintf(stderr,"parser.tmp_val_types.used:  %u\n",parser.tmp_val_types.used);
  fprintf(stderr,"parser.exp_values.used: %u\n",parser.exp_values.used);
  //fprintf(stderr,"parser.label_idxs.used:     %u\n",parser.label_idxs.used);
  //fprintf(stderr,"parser.cb_label_idxs.used:  %u\n",parser.cb_label_idxs.used);

  // - retrieve jit state -
  jit_state_t_ptr _jit = parser._jit;

  // - crete epilog and emit code -
  jit_epilog();
  jit_emit();

  // - clear jit state -
  jit_clear_state();

  // FIXME debug output
  jit_disassemble();

  // - release lightning parser -
  parser.clear();

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_ltg_jit_state_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("LtgJitState"),"LtgJitState");
  );

  return true;
}/*}}}*/

bool bic_ltg_jit_state_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("LtgJitState");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

