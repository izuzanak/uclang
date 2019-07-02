
@begin
include "quirc_module.h"
@end

// - QUIRC indexes of built in classes -
unsigned c_bi_class_quirc = c_idx_not_exist;
unsigned c_bi_class_quirc_code = c_idx_not_exist;
unsigned c_bi_class_quirc_data = c_idx_not_exist;

// - QUIRC module -
EXPORT built_in_module_s module =
{/*{{{*/
  3,                     // Class count
  quirc_classes,         // Classes

  0,                     // Error base index
  5,                     // Error count
  quirc_error_strings,   // Error strings

  quirc_initialize,      // Initialize function
  quirc_print_exception, // Print exceptions function
};/*}}}*/

// - QUIRC classes -
built_in_class_s *quirc_classes[] =
{/*{{{*/
  &quirc_class,
  &quirc_code_class,
  &quirc_data_class,
};/*}}}*/

// - QUIRC error strings -
const char *quirc_error_strings[] =
{/*{{{*/
  "error_QUIRC_INDEX_DOES_NOT_REFER_TO_VALID_VALUE",
  "error_QUIRC_INVALID_IMAGE_SIZE_PROPERTIES",
  "error_QUIRC_CREATE_INSTANCE_ERROR",
  "error_QUIRC_PTROCESS_INVALID_DATA_SIZE",
  "error_QUIRC_CODE_DECODE_DATA_ERROR",
};/*}}}*/

// - QUIRC initialize -
bool quirc_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize quirc class identifier -
  c_bi_class_quirc = class_base_idx++;

  // - initialize quirc_code class identifier -
  c_bi_class_quirc_code = class_base_idx++;

  // - initialize quirc_data class identifier -
  c_bi_class_quirc_data = class_base_idx++;

  return true;
}/*}}}*/

// - QUIRC print exception -
bool quirc_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_QUIRC_INDEX_DOES_NOT_REFER_TO_VALID_VALUE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nIndex %" HOST_LL_FORMAT "d does not refer to valid quirc code\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_QUIRC_INVALID_IMAGE_SIZE_PROPERTIES:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid quirc image size properties\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_QUIRC_CREATE_INSTANCE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating quirc instance\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_QUIRC_PTROCESS_INVALID_DATA_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nQuirc, invalid size of data to process\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_QUIRC_CODE_DECODE_DATA_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while decoding code to data\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class QUIRC -
built_in_class_s quirc_class =
{/*{{{*/
  "Quirc",
  c_modifier_public | c_modifier_final,
  10, quirc_methods,
  0, quirc_variables,
  bic_quirc_consts,
  bic_quirc_init,
  bic_quirc_clear,
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

built_in_method_s quirc_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_quirc_operator_binary_equal
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_quirc_operator_binary_le_br_re_br
  },
  {
    "Quirc#2",
    c_modifier_public | c_modifier_final,
    bic_quirc_method_Quirc_2
  },
  {
    "process#1",
    c_modifier_public | c_modifier_final,
    bic_quirc_method_process_1
  },
  {
    "item#1",
    c_modifier_public | c_modifier_final,
    bic_quirc_method_item_1
  },
  {
    "first_idx#0",
    c_modifier_public | c_modifier_final,
    bic_quirc_method_first_idx_0
  },
  {
    "next_idx#1",
    c_modifier_public | c_modifier_final,
    bic_quirc_method_next_idx_1
  },
  {
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_quirc_method_length_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_quirc_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_quirc_method_print_0
  },
};/*}}}*/

built_in_variable_s quirc_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

#define BIC_QUIRC_CHECK_INDEX() \
/*{{{*/\
  quirc_s *qrc_ptr = (quirc_s *)dst_location->v_data_ptr;\
\
  int code_count = quirc_count(qrc_ptr->quirc_ptr);\
\
  /* - ERROR - */\
  if (index < 0 || index >= code_count)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_QUIRC_INDEX_DOES_NOT_REFER_TO_VALID_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(index);\
\
    return false;\
  }\
/*}}}*/

#define BIC_QUIRC_ITEM(NAME) \
{/*{{{*/\
@begin ucl_params
<
index:retrieve_integer
>
method NAME
macro
; @end\
\
  BIC_QUIRC_CHECK_INDEX();\
\
  /* - create quirc_code object - */\
  quirc_code *qrcc_ptr = (quirc_code *)cmalloc(sizeof(quirc_code));\
  quirc_extract(qrc_ptr->quirc_ptr,index,qrcc_ptr);\
\
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_quirc_code,qrcc_ptr);\
  BIC_SET_RESULT(new_location);\
}/*}}}*/

void bic_quirc_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_quirc_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (quirc_s *)nullptr;
}/*}}}*/

void bic_quirc_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  quirc_s *qrc_ptr = (quirc_s *)location_ptr->v_data_ptr;

  if (qrc_ptr != nullptr)
  {
    qrc_ptr->clear(it);
    cfree(qrc_ptr);
  }
}/*}}}*/

bool bic_quirc_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_quirc_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_QUIRC_ITEM("operator_binary_le_br_re_br#1");

  return true;
}/*}}}*/

bool bic_quirc_method_Quirc_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
width:retrieve_integer
height:retrieve_integer
>
method Quirc
; @end

  // - ERROR -
  if (width <= 0 || height <= 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_QUIRC_INVALID_IMAGE_SIZE_PROPERTIES,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  quirc *quirc_ptr = quirc_new();

  // - ERROR -
  if (quirc_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_QUIRC_CREATE_INSTANCE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (quirc_resize(quirc_ptr,width,height))
  {
    quirc_destroy(quirc_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_QUIRC_CREATE_INSTANCE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create quirc object -
  quirc_s *qrc_ptr = (quirc_s *)cmalloc(sizeof(quirc_s));
  qrc_ptr->init();

  qrc_ptr->quirc_ptr = quirc_ptr;

  dst_location->v_data_ptr = (quirc_s *)qrc_ptr;

  return true;
}/*}}}*/

bool bic_quirc_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_QUIRC_ITEM("item#1");

  return true;
}/*}}}*/

bool bic_quirc_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  quirc_s *qrc_ptr = (quirc_s *)dst_location->v_data_ptr;

  if (quirc_count(qrc_ptr->quirc_ptr) > 0)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,0);
  }
  else {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_quirc_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
index:retrieve_integer
>
method next_idx
; @end

  BIC_QUIRC_CHECK_INDEX();

  if (++index < code_count)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,index);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_quirc_method_process_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:retrieve_data_buffer
>
method process
; @end

  quirc_s *qrc_ptr = (quirc_s *)dst_location->v_data_ptr;

  int quirc_width;
  int quirc_height;
  uint8_t *quirc_buffer = quirc_begin(qrc_ptr->quirc_ptr,&quirc_width,&quirc_height);
  
  // - ERROR -
  if ((unsigned)(quirc_width*quirc_height) != data_size)
  {
    exception_s::throw_exception(it,module.error_base + c_error_QUIRC_PTROCESS_INVALID_DATA_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - copy data to quirc buffer -
  memcpy(quirc_buffer,data_ptr,data_size);

  quirc_end(qrc_ptr->quirc_ptr);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_quirc_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = quirc_count(((quirc_s *)dst_location->v_data_ptr)->quirc_ptr);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_quirc_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Quirc"),"Quirc");
  );

  return true;
}/*}}}*/

bool bic_quirc_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Quirc");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class QUIRC_CODE -
built_in_class_s quirc_code_class =
{/*{{{*/
  "QuircCode",
  c_modifier_public | c_modifier_final,
  4, quirc_code_methods,
  0, quirc_code_variables,
  bic_quirc_code_consts,
  bic_quirc_code_init,
  bic_quirc_code_clear,
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

built_in_method_s quirc_code_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_quirc_code_operator_binary_equal
  },
  {
    "decode#0",
    c_modifier_public | c_modifier_final,
    bic_quirc_code_method_decode_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_quirc_code_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_quirc_code_method_print_0
  },
};/*}}}*/

built_in_variable_s quirc_code_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_quirc_code_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_quirc_code_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (quirc_code *)nullptr;
}/*}}}*/

void bic_quirc_code_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  quirc_code *qrcc_ptr = (quirc_code *)location_ptr->v_data_ptr;

  if (qrcc_ptr != nullptr)
  {
    cfree(qrcc_ptr);
  }
}/*}}}*/

bool bic_quirc_code_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_quirc_code_method_decode_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  quirc_code *qrcc_ptr = (quirc_code *)dst_location->v_data_ptr;

  // - create quirc_data object -
  quirc_data *qrcd_ptr = (quirc_data *)cmalloc(sizeof(quirc_data));

  // - ERROR -
  if (quirc_decode(qrcc_ptr,qrcd_ptr) != 0)
  {
    cfree(qrcd_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_QUIRC_CODE_DECODE_DATA_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_quirc_data,qrcd_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_quirc_code_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("QuircCode"),"QuircCode");
  );

  return true;
}/*}}}*/

bool bic_quirc_code_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("QuircCode");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class QUIRC_DATA -
built_in_class_s quirc_data_class =
{/*{{{*/
  "QuircData",
  c_modifier_public | c_modifier_final,
  4, quirc_data_methods,
  0, quirc_data_variables,
  bic_quirc_data_consts,
  bic_quirc_data_init,
  bic_quirc_data_clear,
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

built_in_method_s quirc_data_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_quirc_data_operator_binary_equal
  },
  {
    "payload#0",
    c_modifier_public | c_modifier_final,
    bic_quirc_data_method_payload_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_quirc_data_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_quirc_data_method_print_0
  },
};/*}}}*/

built_in_variable_s quirc_data_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_quirc_data_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_quirc_data_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (quirc_data *)nullptr;
}/*}}}*/

void bic_quirc_data_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  quirc_data *qrcc_ptr = (quirc_data *)location_ptr->v_data_ptr;

  if (qrcc_ptr != nullptr)
  {
    cfree(qrcc_ptr);
  }
}/*}}}*/

bool bic_quirc_data_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_quirc_data_method_payload_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  quirc_data *qrcd_ptr = (quirc_data *)dst_location->v_data_ptr;

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(qrcd_ptr->payload_len,(const char *)qrcd_ptr->payload);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_quirc_data_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("QuircData"),"QuircData");
  );

  return true;
}/*}}}*/

bool bic_quirc_data_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("QuircData");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

