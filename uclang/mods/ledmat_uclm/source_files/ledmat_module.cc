
@begin
include "ledmat_module.h"
@end

// - LEDMAT indexes of built in classes -
unsigned c_bi_class_ledmat = c_idx_not_exist;
unsigned c_bi_class_ledmat_buffer = c_idx_not_exist;

// - LEDMAT module -
EXPORT built_in_module_s module =
{/*{{{*/
  2,                      // Class count
  ledmat_classes,         // Classes

  0,                      // Error base index
  11,                     // Error count
  ledmat_error_strings,   // Error strings

  ledmat_initialize,      // Initialize function
  ledmat_print_exception, // Print exceptions function
};/*}}}*/

// - LEDMAT classes -
built_in_class_s *ledmat_classes[] =
{/*{{{*/
  &ledmat_class,
  &ledmat_buffer_class,
};/*}}}*/

// - LEDMAT error strings -
const char *ledmat_error_strings[] =
{/*{{{*/
  "error_LEDMAT_INVALID_ARGUMENTS",
  "error_LEDMAT_INVALID_BUFFER_SIZE",
  "error_LEDMAT_MEMORY_ERROR",
  "error_LEDMAT_SETUP_ERROR",
  "error_LEDMAT_INVALID_BRIGHTNESS_VALUE",
  "error_LEDMAT_BUFFER_INVALID_SIZE",
  "error_LEDMAT_BUFFER_MEMORY_ERROR",
  "error_LEDMAT_BUFFER_INVALID_BYTE_VALUE",
  "error_LEDMAT_BUFFER_INVALID_DATA_SIZE",
  "error_LEDMAT_BUFFER_INVALID_BUFFER_SIZE",
  "error_LEDMAT_BUFFER_INVALID_SHIFT_VALUE",
};/*}}}*/

// - LEDMAT initialize -
bool ledmat_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize ledmat class identifier -
  c_bi_class_ledmat = class_base_idx++;

  // - initialize ledmat_buffer class identifier -
  c_bi_class_ledmat_buffer = class_base_idx++;

  return true;
}/*}}}*/

// - LEDMAT print exception -
bool ledmat_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_LEDMAT_INVALID_ARGUMENTS:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nLedMat, invalid arguments\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_LEDMAT_INVALID_BUFFER_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nLedMat, invalid buffer size: %" HOST_LL_FORMAT "d x %" HOST_LL_FORMAT "d\n",exception.params[0],exception.params[1]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_LEDMAT_MEMORY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nLedMat, memory error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_LEDMAT_SETUP_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nLedMat setup error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_LEDMAT_INVALID_BRIGHTNESS_VALUE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nLedMat, invalid brightness value: %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_LEDMAT_BUFFER_INVALID_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nLedMatBuffer, invalid size: %" HOST_LL_FORMAT "d x %" HOST_LL_FORMAT "d\n",exception.params[0],exception.params[1]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_LEDMAT_BUFFER_MEMORY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nLedMatBuffer, memory error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_LEDMAT_BUFFER_INVALID_BYTE_VALUE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nLedMatBuffer, invalid fill byte value: %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_LEDMAT_BUFFER_INVALID_DATA_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nLedMatBuffer, invalid data size: %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_LEDMAT_BUFFER_INVALID_BUFFER_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nLedMatBuffer, invalid source buffer size: %" HOST_LL_FORMAT "d x %" HOST_LL_FORMAT "d\n",exception.params[0],exception.params[1]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_LEDMAT_BUFFER_INVALID_SHIFT_VALUE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nLedMatBuffer, invalid shift value: %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class LEDMAT -
built_in_class_s ledmat_class =
{/*{{{*/
  "LedMat",
  c_modifier_public | c_modifier_final,
  7, ledmat_methods,
  0, ledmat_variables,
  bic_ledmat_consts,
  bic_ledmat_init,
  bic_ledmat_clear,
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

built_in_method_s ledmat_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_ledmat_operator_binary_equal
  },
  {
    "LedMat#4",
    c_modifier_public | c_modifier_final,
    bic_ledmat_method_LedMat_4
  },
  {
    "buffer_load#1",
    c_modifier_public | c_modifier_final,
    bic_ledmat_method_buffer_load_1
  },
  {
    "buffer_swap#0",
    c_modifier_public | c_modifier_final,
    bic_ledmat_method_buffer_swap_0
  },
  {
    "brightness#1",
    c_modifier_public | c_modifier_final,
    bic_ledmat_method_brightness_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ledmat_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ledmat_method_print_0
  },
};/*}}}*/

built_in_variable_s ledmat_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_ledmat_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_ledmat_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (ledmat_s *)nullptr;
}/*}}}*/

void bic_ledmat_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/

  // - retrieve ledmat pointer -
  ledmat_s *lm_ptr = (ledmat_s *)location_ptr->v_data_ptr;

  // - if ledmat pointer is not null release it -
  if (lm_ptr != nullptr)
  {
    lm_ptr->clear(it);
    cfree(lm_ptr);
  }
}/*}}}*/

bool bic_ledmat_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_ledmat_method_LedMat_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
channel:retrieve_integer
speed:retrieve_integer
col_cnt:retrieve_integer
row_cnt:retrieve_integer
>
method LedMat
; @end

  // - ERROR -
  if (channel < 0 || channel > 1 ||
      speed < 1000 || speed > UINT_MAX)
  {
    exception_s::throw_exception(it,module.error_base + c_error_LEDMAT_INVALID_ARGUMENTS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (col_cnt < 1 || col_cnt > UINT_MAX ||
      row_cnt < 1 || row_cnt > UINT_MAX ||
      col_cnt & 0x07)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_LEDMAT_INVALID_BUFFER_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(col_cnt);
    new_exception->params.push(row_cnt);

    return false;
  }

  uc *data = (uc *)cmalloc(row_cnt*(col_cnt >> 3)*sizeof(uc));

  // - ERROR -
  if (data == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_LEDMAT_MEMORY_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  int fd = wiringPiSPISetup(channel,speed);

  // - ERROR -
  if (fd == -1)
  {
    cfree(data);

    exception_s::throw_exception(it,module.error_base + c_error_LEDMAT_SETUP_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create ledmat object -
  ledmat_s *lm_ptr = (ledmat_s *)cmalloc(sizeof(ledmat_s));
  lm_ptr->init();

  lm_ptr->channel = channel;
  lm_ptr->speed = speed;
  lm_ptr->col_cnt = col_cnt;
  lm_ptr->row_cnt = row_cnt;
  lm_ptr->fd = fd;
  lm_ptr->data = data;

  dst_location->v_data_ptr = (ledmat_s *)lm_ptr;

  return true;
}/*}}}*/

bool bic_ledmat_method_buffer_load_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
buffer:c_bi_class_ledmat_buffer
>
method write
; @end

  ledmat_s *lm_ptr = (ledmat_s *)dst_location->v_data_ptr;
  ledmat_buffer_s *lmb_ptr = (ledmat_buffer_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (lm_ptr->col_cnt != lmb_ptr->col_cnt ||
      lm_ptr->row_cnt != lmb_ptr->row_cnt)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_LEDMAT_INVALID_BUFFER_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(lmb_ptr->col_cnt);
    new_exception->params.push(lmb_ptr->row_cnt);

    return false;
  }

  unsigned data_size = lm_ptr->row_cnt*(lm_ptr->col_cnt >> 3);
  memcpy(lm_ptr->data,lmb_ptr->data,data_size);

  uc command = c_spi_cmd_buffer_load;
  wiringPiSPIDataRW(lm_ptr->channel,&command,1);

  wiringPiSPIDataRW(lm_ptr->channel,lm_ptr->data,data_size);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_ledmat_method_buffer_swap_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ledmat_s *lm_ptr = (ledmat_s *)dst_location->v_data_ptr;

  uc command = c_spi_cmd_buffer_swap;
  wiringPiSPIDataRW(lm_ptr->channel,&command,1);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_ledmat_method_brightness_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
brightness:retrieve_integer
>
method brightness
; @end

  // - ERROR -
  if (brightness < 0 || brightness > 127)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_LEDMAT_INVALID_BRIGHTNESS_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(brightness);

    return false;
  }

  ledmat_s *lm_ptr = (ledmat_s *)dst_location->v_data_ptr;

  uc command[2] = {c_spi_cmd_brightness,(uc)brightness};
  wiringPiSPIDataRW(lm_ptr->channel,command,2);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_ledmat_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("LedMat"),"LedMat");
  );

  return true;
}/*}}}*/

bool bic_ledmat_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("LedMat");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class LEDMAT_BUFFER -
built_in_class_s ledmat_buffer_class =
{/*{{{*/
  "LedMatBuffer",
  c_modifier_public | c_modifier_final,
  7, ledmat_buffer_methods,
  0, ledmat_buffer_variables,
  bic_ledmat_buffer_consts,
  bic_ledmat_buffer_init,
  bic_ledmat_buffer_clear,
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

built_in_method_s ledmat_buffer_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_ledmat_buffer_operator_binary_equal
  },
  {
    "LedMatBuffer#2",
    c_modifier_public | c_modifier_final,
    bic_ledmat_buffer_method_LedMatBuffer_2
  },
  {
    "fill#1",
    c_modifier_public | c_modifier_final,
    bic_ledmat_buffer_method_fill_1
  },
  {
    "set#1",
    c_modifier_public | c_modifier_final,
    bic_ledmat_buffer_method_set_1
  },
  {
    "rotate#2",
    c_modifier_public | c_modifier_final,
    bic_ledmat_buffer_method_rotate_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ledmat_buffer_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ledmat_buffer_method_print_0
  },
};/*}}}*/

built_in_variable_s ledmat_buffer_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_ledmat_buffer_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_ledmat_buffer_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (ledmat_buffer_s *)nullptr;
}/*}}}*/

void bic_ledmat_buffer_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/

  // - retrieve ledmat_buffer pointer -
  ledmat_buffer_s *lmb_ptr = (ledmat_buffer_s *)location_ptr->v_data_ptr;

  // - if ledmat_buffer pointer is not null release it -
  if (lmb_ptr != nullptr)
  {
    lmb_ptr->clear(it);
    cfree(lmb_ptr);
  }

}/*}}}*/

bool bic_ledmat_buffer_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_ledmat_buffer_method_LedMatBuffer_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
col_cnt:retrieve_integer
row_cnt:retrieve_integer
>
method LedMatBuffer
; @end

  // - ERROR -
  if (col_cnt < 1 || col_cnt > UINT_MAX ||
      row_cnt < 1 || row_cnt > UINT_MAX ||
      col_cnt & 0x07)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_LEDMAT_BUFFER_INVALID_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(col_cnt);
    new_exception->params.push(row_cnt);

    return false;
  }

  uc *data = (uc *)cmalloc(row_cnt*(col_cnt >> 3)*sizeof(uc));

  // - ERROR -
  if (data == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_LEDMAT_BUFFER_MEMORY_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create ledmat object -
  ledmat_buffer_s *lmb_ptr = (ledmat_buffer_s *)cmalloc(sizeof(ledmat_buffer_s));
  lmb_ptr->init();

  lmb_ptr->col_cnt = col_cnt;
  lmb_ptr->row_cnt = row_cnt;
  lmb_ptr->data = data;

  dst_location->v_data_ptr = (ledmat_buffer_s *)lmb_ptr;

  return true;
}/*}}}*/

bool bic_ledmat_buffer_method_fill_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
value:retrieve_integer
>
method fill
; @end

  if (value < 0 || value > 255)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_LEDMAT_BUFFER_INVALID_BYTE_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(value);

    return false;
  }

  ledmat_buffer_s *lmb_ptr = (ledmat_buffer_s *)dst_location->v_data_ptr;

  memset(lmb_ptr->data,value,lmb_ptr->row_cnt*(lmb_ptr->col_cnt >> 3));

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_ledmat_buffer_method_set_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:retrieve_data_buffer
>
method set
; @end

  ledmat_buffer_s *lmb_ptr = (ledmat_buffer_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (lmb_ptr->row_cnt*lmb_ptr->col_cnt != data_size)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_LEDMAT_BUFFER_INVALID_DATA_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(data_size);

    return false;
  }

  uc *d_ptr = (uc *)data_ptr;
  uc *d_ptr_end = d_ptr + data_size;
  uc *b_ptr = lmb_ptr->data;

  unsigned value = 0;
  unsigned bit_cnt = 0;
  do {
    value |= !!*d_ptr;

    if (++bit_cnt >= 8)
    {
      *b_ptr++ = value;

      value = 0;
      bit_cnt = 0;
    }
    else
    {
      value <<= 1;
    }
  } while(++d_ptr < d_ptr_end);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_ledmat_buffer_method_rotate_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
source:c_bi_class_ledmat_buffer
shift:retrieve_integer
>
method rotate
; @end

  ledmat_buffer_s *lmb_ptr = (ledmat_buffer_s *)dst_location->v_data_ptr;
  ledmat_buffer_s *s_lmb_ptr = (ledmat_buffer_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (lmb_ptr->row_cnt != s_lmb_ptr->row_cnt || lmb_ptr->col_cnt > s_lmb_ptr->col_cnt)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_LEDMAT_BUFFER_INVALID_BUFFER_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(s_lmb_ptr->col_cnt);
    new_exception->params.push(s_lmb_ptr->row_cnt);

    return false;
  }

  // - ERROR -
  if (shift < 0 || shift >= s_lmb_ptr->col_cnt)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_LEDMAT_BUFFER_INVALID_SHIFT_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(shift);

    return false;
  }

  unsigned col_byte_cnt = lmb_ptr->col_cnt >> 3;
  unsigned s_col_byte_cnt = s_lmb_ptr->col_cnt >> 3;

  unsigned byte_shift = shift / 8;
  unsigned bit_shift = shift % 8;

  uc mask_0 = 0xff >> bit_shift;
  uc mask_1 = 0xff << (8 - bit_shift);

  uc *t_ptr = lmb_ptr->data;

  unsigned row_cnt = 0;
  do {
    unsigned col_cnt = 0;
    uc *sr_ptr = s_lmb_ptr->data + row_cnt*s_col_byte_cnt;
    uc *s_ptr = sr_ptr + byte_shift;
    uc *s_ptr_end = sr_ptr + s_col_byte_cnt;
    do {
      *t_ptr = (s_ptr[0] & mask_0) << bit_shift;

      if (++s_ptr >= s_ptr_end) { s_ptr = sr_ptr; }

      *t_ptr |= (s_ptr[0] & mask_1) >> (8 - bit_shift);
    } while(++t_ptr,++col_cnt < col_byte_cnt);
  } while(++row_cnt < lmb_ptr->row_cnt);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_ledmat_buffer_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("LedMatBuffer"),"LedMatBuffer");
  );

  return true;
}/*}}}*/

bool bic_ledmat_buffer_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("LedMatBuffer");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

