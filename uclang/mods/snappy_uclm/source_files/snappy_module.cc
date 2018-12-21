
@begin
include "snappy_module.h"
@end

// - SNAPPY indexes of built in classes -
unsigned c_bi_class_snappy = c_idx_not_exist;

// - SNAPPY module -
built_in_module_s module =
{/*{{{*/
  1,                      // Class count
  snappy_classes,         // Classes

  0,                      // Error base index
  2,                      // Error count
  snappy_error_strings,   // Error strings

  snappy_initialize,      // Initialize function
  snappy_print_exception, // Print exceptions function
};/*}}}*/

// - SNAPPY classes -
built_in_class_s *snappy_classes[] =
{/*{{{*/
  &snappy_class,
};/*}}}*/

// - SNAPPY error strings -
const char *snappy_error_strings[] =
{/*{{{*/
  "error_SNAPPY_GET_UNCOMPRESSED_LENGTH",
  "error_SNAPPY_UNCOMPRESS_ERROR",
};/*}}}*/

// - SNAPPY initialize -
bool snappy_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize snappy class identifier -
  c_bi_class_snappy = class_base_idx++;

  return true;
}/*}}}*/

// - SNAPPY print exception -
bool snappy_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_SNAPPY_GET_UNCOMPRESSED_LENGTH:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSnappy cannot get uncompressed data length\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SNAPPY_UNCOMPRESS_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSnappy uncompress error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class SNAPPY -
built_in_class_s snappy_class =
{/*{{{*/
  "Snappy",
  c_modifier_public | c_modifier_final,
  4, snappy_methods,
  0, snappy_variables,
  bic_snappy_consts,
  bic_snappy_init,
  bic_snappy_clear,
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

built_in_method_s snappy_methods[] =
{/*{{{*/
  {
    "compress#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_snappy_method_compress_1
  },
  {
    "uncompress#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_snappy_method_uncompress_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_snappy_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_snappy_method_print_0
  },
};/*}}}*/

built_in_variable_s snappy_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_snappy_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_snappy_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_snappy_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_snappy_method_compress_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:c_bi_class_string
>
class c_bi_class_snappy
method compress
static_method
; @end

  string_s *source_ptr = (string_s *)src_0_location->v_data_ptr;

  // - retrieve maximal target length -
  size_t target_length = snappy::MaxCompressedLength(source_ptr->size - 1);

  // - create target string -
  string_s *target_ptr = it.get_new_string_ptr();
  target_ptr->create(target_length);

  snappy::RawCompress(source_ptr->data,source_ptr->size - 1,target_ptr->data,&target_length);

  // - adjust string size -
  target_ptr->data[target_length] = '\0';
  target_ptr->size = target_length + 1;

  BIC_SET_RESULT_STRING(target_ptr);

  return true;
}/*}}}*/

bool bic_snappy_method_uncompress_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:c_bi_class_string
>
class c_bi_class_snappy
method uncompress
static_method
; @end

  string_s *source_ptr = (string_s *)src_0_location->v_data_ptr;

  // - retrieve target length -
  size_t target_length;

  // - ERROR -
  if (!snappy::GetUncompressedLength(source_ptr->data,source_ptr->size - 1,&target_length))
  {
    exception_s::throw_exception(it,module.error_base + c_error_SNAPPY_GET_UNCOMPRESSED_LENGTH,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create target string -
  string_s *target_ptr = it.get_new_string_ptr();
  target_ptr->create(target_length);

  // - ERROR -
  if (!snappy::RawUncompress(source_ptr->data,source_ptr->size - 1,target_ptr->data))
  {
    target_ptr->clear();
    cfree(target_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_SNAPPY_UNCOMPRESS_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_STRING(target_ptr);

  return true;
}/*}}}*/

bool bic_snappy_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Snappy"),"Snappy");
  );

  return true;
}/*}}}*/

bool bic_snappy_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Snappy");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

