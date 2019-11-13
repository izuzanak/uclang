
@begin
include "checksum_module.h"
@end

// - CHECKSUM indexes of built in classes -
unsigned c_bi_class_bcc = c_idx_not_exist;

// - CHECKSUM module -
EXPORT built_in_module_s module =
{/*{{{*/
  1,                         // Class count
  checksum_classes,          // Classes

  0,                         // Error base index
  1,                         // Error count
  checksum_error_strings,    // Error strings

  checksum_initialize,       // Initialize function
  checksum_print_exception,  // Print exceptions function
};/*}}}*/

// - CHECKSUM classes -
built_in_class_s *checksum_classes[] =
{/*{{{*/
  &bcc_class,
};/*}}}*/

// - CHECKSUM error strings -
const char *checksum_error_strings[] =
{/*{{{*/
  "error_CHECKSUM_DUMMY_ERROR",
};/*}}}*/

// - CHECKSUM initialize -
bool checksum_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize bcc class identifier -
  c_bi_class_bcc = class_base_idx++;

  return true;
}/*}}}*/

// - CHECKSUM print exception -
bool checksum_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_CHECKSUM_DUMMY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nChecksum dummy error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class BCC -
built_in_class_s bcc_class =
{/*{{{*/
  "Bcc",
  c_modifier_public | c_modifier_final,
  6, bcc_methods,
  0, bcc_variables,
  bic_bcc_consts,
  bic_bcc_init,
  bic_bcc_clear,
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

built_in_method_s bcc_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_bcc_operator_binary_equal
  },
  {
    "Bcc#0",
    c_modifier_public | c_modifier_final,
    bic_bcc_method_Bcc_0
  },
  {
    "append#1",
    c_modifier_public | c_modifier_final,
    bic_bcc_method_append_1
  },
  {
    "value#0",
    c_modifier_public | c_modifier_final,
    bic_bcc_method_value_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_bcc_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_bcc_method_print_0
  },
};/*}}}*/

built_in_variable_s bcc_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_bcc_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_bcc_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

void bic_bcc_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

bool bic_bcc_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_bcc_method_Bcc_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - set bcc value to zero -
  dst_location->v_data_ptr = (long long int)0;

  return true;
}/*}}}*/

bool bic_bcc_method_append_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:retrieve_data_buffer
>
method append
; @end

  // - retrieve bcc value -
  unsigned char value = (long long int)dst_location->v_data_ptr;

  if (data_size)
  {
    unsigned char *b_ptr = (unsigned char *)data_ptr;
    unsigned char *b_ptr_end = b_ptr + data_size;

    do {
      value ^= *b_ptr;
    } while(++b_ptr < b_ptr_end);
  }

  // - set bcc value -
  dst_location->v_data_ptr = (long long int)value;

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_bcc_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve bcc value -
  long long int result = (long long int)dst_location->v_data_ptr;
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_bcc_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Bcc"),"Bcc")
  );

  return true;
}/*}}}*/

bool bic_bcc_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Bcc");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

