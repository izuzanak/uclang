
@begin
include "rust_module.h"
@end

// - RUST indexes of built in classes -
unsigned c_bi_class_rust_string = c_idx_not_exist;

// - RUST module -
EXPORT built_in_module_s module =
{/*{{{*/
  1,                    // Class count
  rust_classes,         // Classes

  0,                    // Error base index
  1,                    // Error count
  rust_error_strings,   // Error strings

  rust_initialize,      // Initialize function
  rust_print_exception, // Print exceptions function
};/*}}}*/

// - RUST classes -
built_in_class_s *rust_classes[] =
{/*{{{*/
  &rust_string_class,
};/*}}}*/

// - RUST error strings -
const char *rust_error_strings[] =
{/*{{{*/
  "error_RUST_STRING_UTF8_ENCODING_ERROR",
};/*}}}*/

// - RUST initialize -
bool rust_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize rust_string class identifier -
  c_bi_class_rust_string = class_base_idx++;

  return true;
}/*}}}*/

// - RUST print exception -
bool rust_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_RUST_STRING_UTF8_ENCODING_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nRust UTF-8 sequence decomposing error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class RUST_STRING -
built_in_class_s rust_string_class =
{/*{{{*/
  "RustString",
  c_modifier_public | c_modifier_final,
  8, rust_string_methods,
  0, rust_string_variables,
  bic_rust_string_consts,
  bic_rust_string_init,
  bic_rust_string_clear,
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

built_in_method_s rust_string_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_rust_string_operator_binary_equal
  },
  {
    "operator_unary_post_double_plus#0",
    c_modifier_public | c_modifier_final,
    bic_rust_string_operator_unary_post_double_plus
  },
  {
    "operator_unary_pre_double_plus#0",
    c_modifier_public | c_modifier_final,
    bic_rust_string_operator_unary_pre_double_plus
  },
  {
    "RustString#0",
    c_modifier_public | c_modifier_final,
    bic_rust_string_method_RustString_0
  },
  {
    "RustString#1",
    c_modifier_public | c_modifier_final,
    bic_rust_string_method_RustString_1
  },
  {
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_rust_string_method_length_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_rust_string_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_rust_string_method_print_0
  },
};/*}}}*/

built_in_variable_s rust_string_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

