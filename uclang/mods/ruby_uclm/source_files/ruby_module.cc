
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
  1,                    // Error count
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
  "error_RUBY_DUMMY_ERROR",
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
  case c_error_RUBY_DUMMY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nRuby dummy error\n");
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
  2, ruby_interpreter_methods,
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
  3, ruby_value_methods,
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
  
  // FIXME TODO continue ...
  cassert(0);
}/*}}}*/

void bic_ruby_value_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/

  // FIXME TODO continue ...
  cassert(0);
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

