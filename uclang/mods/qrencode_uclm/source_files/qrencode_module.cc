
@begin
include "qrencode_module.h"
@end

// - QRENCODE indexes of built in classes -
unsigned c_bi_class_qr_code = c_idx_not_exist;

// - QRENCODE module -
EXPORT built_in_module_s module =
{/*{{{*/
  1,                        // Class count
  qrencode_classes,         // Classes

  0,                        // Error base index
  1,                        // Error count
  qrencode_error_strings,   // Error strings

  qrencode_initialize,      // Initialize function
  qrencode_print_exception, // Print exceptions function
};/*}}}*/

// - QRENCODE classes -
built_in_class_s *qrencode_classes[] =
{/*{{{*/
  &qr_code_class,
};/*}}}*/

// - QRENCODE error strings -
const char *qrencode_error_strings[] =
{/*{{{*/
  "error_QRENCODE_QRCODE_ENCODE_ERROR",
};/*}}}*/

// - QRENCODE initialize -
bool qrencode_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize qr_code class identifier -
  c_bi_class_qr_code = class_base_idx++;

  return true;
}/*}}}*/

// - QRENCODE print exception -
bool qrencode_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_QRENCODE_QRCODE_ENCODE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nQRCode, create error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class QR_CODE -
built_in_class_s qr_code_class =
{/*{{{*/
  "QRCode",
  c_modifier_public | c_modifier_final,
  8, qr_code_methods,
  4 + 9, qr_code_variables,
  bic_qr_code_consts,
  bic_qr_code_init,
  bic_qr_code_clear,
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

built_in_method_s qr_code_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_qr_code_operator_binary_equal
  },
  {
    "encode_string#4",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_qr_code_method_encode_string_4
  },
  {
    "encode_data#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_qr_code_method_encode_data_2
  },
  {
    "version#0",
    c_modifier_public | c_modifier_final,
    bic_qr_code_method_version_0
  },
  {
    "width#0",
    c_modifier_public | c_modifier_final,
    bic_qr_code_method_width_0
  },
  {
    "buffer#0",
    c_modifier_public | c_modifier_final,
    bic_qr_code_method_buffer_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_qr_code_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_qr_code_method_print_0
  },
};/*}}}*/

built_in_variable_s qr_code_variables[] =
{/*{{{*/

  // - error correction level constants -
  { "ECLEVEL_L", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ECLEVEL_M", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ECLEVEL_Q", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ECLEVEL_H", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - qr encoding mode constants -
  { "MODE_NUL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MODE_NUM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MODE_AN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MODE_8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MODE_KANJI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MODE_STRUCTURE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MODE_ECI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MODE_FNC1FIRST", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MODE_FNC1SECOND", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_qr_code_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert error correction level constants -
  {
    const_locations.push_blanks(4);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 4);

#define CREATE_ERROR_CORRECTION_LEVEL_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_ERROR_CORRECTION_LEVEL_BIC_STATIC(QR_ECLEVEL_L);
    CREATE_ERROR_CORRECTION_LEVEL_BIC_STATIC(QR_ECLEVEL_M);
    CREATE_ERROR_CORRECTION_LEVEL_BIC_STATIC(QR_ECLEVEL_Q);
    CREATE_ERROR_CORRECTION_LEVEL_BIC_STATIC(QR_ECLEVEL_H);
  }

  // - insert qr encoding mode constants -
  {
    const_locations.push_blanks(9);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 9);

#define CREATE_QR_ENCODING_MODE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_QR_ENCODING_MODE_BIC_STATIC(QR_MODE_NUL);
    CREATE_QR_ENCODING_MODE_BIC_STATIC(QR_MODE_NUM);
    CREATE_QR_ENCODING_MODE_BIC_STATIC(QR_MODE_AN);
    CREATE_QR_ENCODING_MODE_BIC_STATIC(QR_MODE_8);
    CREATE_QR_ENCODING_MODE_BIC_STATIC(QR_MODE_KANJI);
    CREATE_QR_ENCODING_MODE_BIC_STATIC(QR_MODE_STRUCTURE);
    CREATE_QR_ENCODING_MODE_BIC_STATIC(QR_MODE_ECI);
    CREATE_QR_ENCODING_MODE_BIC_STATIC(QR_MODE_FNC1FIRST);
    CREATE_QR_ENCODING_MODE_BIC_STATIC(QR_MODE_FNC1SECOND);
  }

}/*}}}*/

void bic_qr_code_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (QRcode *)nullptr;
}/*}}}*/

void bic_qr_code_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  QRcode *qrc_ptr = (QRcode *)location_ptr->v_data_ptr;

  if (qrc_ptr != nullptr)
  {
    QRcode_free(qrc_ptr);
  }
}/*}}}*/

bool bic_qr_code_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_qr_code_method_encode_string_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:retrieve_data_buffer
error_correction_level:retrieve_integer
encoding_mode:retrieve_integer
case_sensitive:retrieve_integer
>
class c_bi_class_qr_code
method encode_string
static_method
; @end

  QRcode *qrc_ptr = QRcode_encodeString(
      (char *)data_ptr,0,(QRecLevel)error_correction_level,(QRencodeMode)encoding_mode,case_sensitive);

  // - ERROR -
  if (qrc_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_QRENCODE_QRCODE_ENCODE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_qr_code,qrc_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_qr_code_method_encode_data_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:retrieve_data_buffer
error_correction_level:retrieve_integer
>
class c_bi_class_qr_code
method encode_data
static_method
; @end

  QRcode *qrc_ptr = QRcode_encodeData(
      data_size,(unsigned char *)data_ptr,0,(QRecLevel)error_correction_level);

  // - ERROR -
  if (qrc_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_QRENCODE_QRCODE_ENCODE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_qr_code,qrc_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_qr_code_method_version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  QRcode *qrc_ptr = (QRcode *)dst_location->v_data_ptr;
  long long int result = qrc_ptr->version;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_qr_code_method_width_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  QRcode *qrc_ptr = (QRcode *)dst_location->v_data_ptr;
  long long int result = qrc_ptr->width;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_qr_code_method_buffer_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  QRcode *qrc_ptr = (QRcode *)dst_location->v_data_ptr;
  unsigned code_size = qrc_ptr->width*qrc_ptr->width;

  // - create buffer object -
  buffer_s *buffer_ptr = (buffer_s *)cmalloc(sizeof(buffer_s));

  // - reset owner reference -
  buffer_ptr->owner_ptr = nullptr;
  buffer_ptr->data = cmalloc(code_size);
  buffer_ptr->size = code_size;

  if (code_size > 0)
  {
    unsigned char *qr_ptr = qrc_ptr->data;
    unsigned char *qr_ptr_end = qr_ptr + code_size;
    unsigned char *b_ptr = (unsigned char *)buffer_ptr->data;

    do {
      *b_ptr = (*qr_ptr & 0x01) ? 0 : 255;
    } while(++b_ptr,++qr_ptr < qr_ptr_end);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_buffer,buffer_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_qr_code_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("QRCode"),"QRCode");
  );

  return true;
}/*}}}*/

bool bic_qr_code_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("QRCode");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

