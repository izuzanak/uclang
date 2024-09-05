
@begin
include "isal_module.h"
@end

// - ISAL indexes of built in classes -
unsigned c_bi_class_isal_crc_16 = c_idx_not_exist;

// - ISAL module -
EXPORT built_in_module_s module =
{/*{{{*/
  1,                    // Class count
  isal_classes,         // Classes

  0,                    // Error base index
  1,                    // Error count
  isal_error_strings,   // Error strings

  isal_initialize,      // Initialize function
  isal_print_exception, // Print exceptions function
};/*}}}*/

// - ISAL classes -
built_in_class_s *isal_classes[] =
{/*{{{*/
  &isal_crc_16_class,
};/*}}}*/

// - ISAL error strings -
const char *isal_error_strings[] =
{/*{{{*/
  "error_ISAL_DUMMY_ERROR",
};/*}}}*/

// - ISAL initialize -
bool isal_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize isal_crc_16 class identifier -
  c_bi_class_isal_crc_16 = class_base_idx++;

  return true;
}/*}}}*/

// - ISAL print exception -
bool isal_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_ISAL_DUMMY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nISAL dummy error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class ISAL_CRC_16 -
built_in_class_s isal_crc_16_class =
{/*{{{*/
  "IsalCrc16",
  c_modifier_public | c_modifier_final,
  6, isal_crc_16_methods,
  0, isal_crc_16_variables,
  bic_isal_crc_16_consts,
  bic_isal_crc_16_init,
  bic_isal_crc_16_clear,
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

built_in_method_s isal_crc_16_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_isal_crc_16_operator_binary_equal
  },
  {
    "IsalCrc16#1",
    c_modifier_public | c_modifier_final,
    bic_isal_crc_16_method_IsalCrc16_1
  },
  {
    "append#1",
    c_modifier_public | c_modifier_final,
    bic_isal_crc_16_method_append_1
  },
  {
    "value#0",
    c_modifier_public | c_modifier_final,
    bic_isal_crc_16_method_value_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_isal_crc_16_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_isal_crc_16_method_print_0
  },
};/*}}}*/

built_in_variable_s isal_crc_16_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_isal_crc_16_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_isal_crc_16_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

void bic_isal_crc_16_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

bool bic_isal_crc_16_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_isal_crc_16_method_IsalCrc16_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
init_value:retrieve_integer
>
method IsalCrc16
; @end

  // - set crc initial value -
  dst_location->v_data_ptr = (long long int)init_value;

  return true;
}/*}}}*/

bool bic_isal_crc_16_method_append_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:retrieve_data_buffer
>
method append
; @end

  // - retrieve crc value -
  unsigned short value = (long long int)dst_location->v_data_ptr;

  // - update crc value -
  value = crc16_t10dif(value,(unsigned char *)data_ptr,data_size);

  // - set crc value -
  dst_location->v_data_ptr = (long long int)value;

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_isal_crc_16_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve crc value -
  long long int result = (long long int)dst_location->v_data_ptr;
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_isal_crc_16_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("IsalCrc16"),"IsalCrc16")
  );

  return true;
}/*}}}*/

bool bic_isal_crc_16_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("IsalCrc16");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

