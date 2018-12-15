
@begin
include "utf8proc_module.h"
@end

// - UTF8PROC indexes of built in classes -
unsigned c_bi_class_utf8proc = c_idx_not_exist;
unsigned c_bi_class_unicode_char = c_idx_not_exist;
unsigned c_bi_class_unicode_string = c_idx_not_exist;

// - UTF8PROC module -
built_in_module_s module =
{/*{{{*/
  3,                        // Class count
  utf8proc_classes,         // Classes

  0,                        // Error base index
  6,                        // Error count
  utf8proc_error_strings,   // Error strings

  utf8proc_initialize,      // Initialize function
  utf8proc_print_exception, // Print exceptions function
};/*}}}*/

// - UTF8PROC classes -
built_in_class_s *utf8proc_classes[] =
{/*{{{*/
  &utf8proc_class,
  &unicode_char_class,
  &unicode_string_class,
};/*}}}*/

// - UTF8PROC error strings -
const char *utf8proc_error_strings[] =
{/*{{{*/
  "error_UTF8PROC_UTF8_SEQUENCE_INVALID_CODE_POINT",
  "error_UNICODE_CHAR_INVALID_CODE_POINT",
  "error_UNICODE_STRING_UTF8_DECOMPOSE_ERROR",
  "error_UNICODE_STRING_UTF8_CREATE_ERROR",
  "error_UNICODE_STRING_INDEX_EXCEEDS_RANGE",
  "error_UNICODE_STRING_WRONG_RANGE_INDEXES",
};/*}}}*/

// - UTF8PROC initialize -
bool utf8proc_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize utf8proc class identifier -
  c_bi_class_utf8proc = class_base_idx++;

  // - initialize unicode_char class identifier -
  c_bi_class_unicode_char = class_base_idx++;

  // - initialize unicode_string class identifier -
  c_bi_class_unicode_string = class_base_idx++;

  return true;
}/*}}}*/

// - UTF8PROC print exception -
bool utf8proc_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_UTF8PROC_UTF8_SEQUENCE_INVALID_CODE_POINT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot read valid code point from UTF-8 sequence\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_UNICODE_CHAR_INVALID_CODE_POINT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid unicode character code point %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_UNICODE_STRING_UTF8_DECOMPOSE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while decomposing UTF-8 sequence to code points\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_UNICODE_STRING_UTF8_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating UTF-8 sequence from code points\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_UNICODE_STRING_INDEX_EXCEEDS_RANGE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nIndex %" HOST_LL_FORMAT "d exceeds unicode string range\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_UNICODE_STRING_WRONG_RANGE_INDEXES:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong range indexes %" HOST_LL_FORMAT "d, %" HOST_LL_FORMAT "d for unicode string\n",exception.params[0],exception.params[1]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class UTF8PROC -
built_in_class_s utf8proc_class =
{/*{{{*/
  "Utf8Proc",
  c_modifier_public | c_modifier_final,
  5, utf8proc_methods,
  0, utf8proc_variables,
  bic_utf8proc_consts,
  bic_utf8proc_init,
  bic_utf8proc_clear,
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

built_in_method_s utf8proc_methods[] =
{/*{{{*/
  {
    "to_lower#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_utf8proc_method_to_lower_1
  },
  {
    "to_upper#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_utf8proc_method_to_upper_1
  },
  {
    "version#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_utf8proc_method_version_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_utf8proc_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_utf8proc_method_print_0
  },
};/*}}}*/

built_in_variable_s utf8proc_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_UTF8PROC_TRANSFORM_STRING(CODE_POINT_CODE) \
/*{{{*/\
\
  /* - create target buffer - */\
  bc_array_s buffer;\
  buffer.init_size(source_ptr->size);\
\
  if (source_ptr->size > 1)\
  {\
    const utf8proc_uint8_t *s_ptr = (const utf8proc_uint8_t *)source_ptr->data;\
    const utf8proc_uint8_t *s_ptr_end = s_ptr + source_ptr->size - 1;\
\
    utf8proc_int32_t code_point;\
    do {\
\
      /* - retrieve next code point - */\
      s_ptr += utf8proc_iterate(s_ptr,s_ptr_end - s_ptr,&code_point);\
\
      /* - ERROR - */\
      if (code_point < 0)\
      {\
        buffer.clear();\
\
        exception_s::throw_exception(it,module.error_base + c_error_UTF8PROC_UTF8_SEQUENCE_INVALID_CODE_POINT,operands[c_source_pos_idx],(location_s *)it.blank_location);\
        return false;\
      }\
\
      CODE_POINT_CODE;\
\
      /* - encode code point to target buffer - */\
      buffer.reserve(4);\
      buffer.used += utf8proc_encode_char(code_point,\
          (utf8proc_uint8_t *)(buffer.data + buffer.used));\
\
    } while(s_ptr < s_ptr_end);\
  }\
\
  buffer.push('\0');\
\
  /* - create target string - */\
  string_s *target_ptr = it.get_new_string_ptr();\
  target_ptr->data = buffer.data;\
  target_ptr->size = buffer.used;\
/*}}}*/

void bic_utf8proc_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_utf8proc_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_utf8proc_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_utf8proc_method_to_lower_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:c_bi_class_string
>
class c_bi_class_utf8proc
method to_lower
static_method
; @end

  string_s *source_ptr = (string_s *)src_0_location->v_data_ptr;

  BIC_UTF8PROC_TRANSFORM_STRING(

    // - code point to lower -
    code_point = utf8proc_tolower(code_point);
  );

  BIC_SET_RESULT_STRING(target_ptr);

  return true;
}/*}}}*/

bool bic_utf8proc_method_to_upper_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:c_bi_class_string
>
class c_bi_class_utf8proc
method to_upper
static_method
; @end

  string_s *source_ptr = (string_s *)src_0_location->v_data_ptr;

  BIC_UTF8PROC_TRANSFORM_STRING(

    // - code point to upper -
    code_point = utf8proc_toupper(code_point);
  );

  BIC_SET_RESULT_STRING(target_ptr);

  return true;
}/*}}}*/

bool bic_utf8proc_method_version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  const char *version = utf8proc_version();

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(version),version);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_utf8proc_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Utf8Proc"),"Utf8Proc");
  );

  return true;
}/*}}}*/

bool bic_utf8proc_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Utf8Proc");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class UNICODE_CHAR -
built_in_class_s unicode_char_class =
{/*{{{*/
  "UnicodeChar",
  c_modifier_public | c_modifier_final,
  11, unicode_char_methods,
  0, unicode_char_variables,
  bic_unicode_char_consts,
  bic_unicode_char_init,
  bic_unicode_char_clear,
  bic_unicode_char_compare,
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

built_in_method_s unicode_char_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_unicode_char_operator_binary_equal
  },
  {
    "operator_binary_double_equal#1",
    c_modifier_public | c_modifier_final,
    bic_unicode_char_operator_binary_double_equal
  },
  {
    "operator_binary_exclamation_equal#1",
    c_modifier_public | c_modifier_final,
    bic_unicode_char_operator_binary_exclamation_equal
  },
  {
    "UnicodeChar#0",
    c_modifier_public | c_modifier_final,
    bic_unicode_char_method_UnicodeChar_0
  },
  {
    "UnicodeChar#1",
    c_modifier_public | c_modifier_final,
    bic_unicode_char_method_UnicodeChar_1
  },
  {
    "to_lower#0",
    c_modifier_public | c_modifier_final,
    bic_unicode_char_method_to_lower_0
  },
  {
    "to_upper#0",
    c_modifier_public | c_modifier_final,
    bic_unicode_char_method_to_upper_0
  },
  {
    "value#0",
    c_modifier_public | c_modifier_final,
    bic_unicode_char_method_value_0
  },
  {
    "compare#1",
    c_modifier_public | c_modifier_final,
    bic_unicode_char_method_compare_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_unicode_char_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_unicode_char_method_print_0
  },
};/*}}}*/

built_in_variable_s unicode_char_variables[] =
{/*{{{*/
};/*}}}*/

void bic_unicode_char_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_unicode_char_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (utf8proc_int32_t)0;
}/*}}}*/

void bic_unicode_char_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

int bic_unicode_char_compare(location_s *first_loc,location_s *second_loc)
{/*{{{*/
  utf8proc_int32_t first = (utf8proc_int32_t)first_loc->v_data_ptr;
  utf8proc_int32_t second = (utf8proc_int32_t)second_loc->v_data_ptr;

  return first < second ? -1 : (first > second ? 1 : 0);
}/*}}}*/

bool bic_unicode_char_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

#define BIC_UNICODE_CHAR_COMPARE_WITH_TYPE_BOOL() \
  {/*{{{*/\
    switch (src_0_location->v_type) {\
    case c_bi_class_char:\
      result = (utf8proc_int32_t)dst_location->v_data_ptr == (char)src_0_location->v_data_ptr;\
      break;\
    case c_bi_class_integer:\
      result = (utf8proc_int32_t)dst_location->v_data_ptr == (long long int)src_0_location->v_data_ptr;\
      break;\
    case c_bi_class_float:\
      result = (utf8proc_int32_t)dst_location->v_data_ptr == (double)src_0_location->v_data_ptr;\
      break;\
    default:\
      if (src_0_location->v_type == c_bi_class_unicode_char)\
      {\
        result = (utf8proc_int32_t)dst_location->v_data_ptr == (utf8proc_int32_t)src_0_location->v_data_ptr;\
      }\
      else\
      {\
        result = 0;\
      }\
      break;\
    }\
  }/*}}}*/

bool bic_unicode_char_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_UNICODE_CHAR_COMPARE_WITH_TYPE_BOOL();

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_unicode_char_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_UNICODE_CHAR_COMPARE_WITH_TYPE_BOOL();
  result = !result;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_unicode_char_method_UnicodeChar_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  return true;
}/*}}}*/

bool bic_unicode_char_method_UnicodeChar_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
character:ignore
>
method UnicodeChar
; @end

  utf8proc_int32_t result;

  switch (src_0_location->v_type)
  {
  case c_bi_class_char:
    result = (char)src_0_location->v_data_ptr;
    break;
  case c_bi_class_integer:
    result = (long long int)src_0_location->v_data_ptr;
    break;
  default:
    {
      if (src_0_location->v_type == c_bi_class_unicode_char)
      {
        result = (utf8proc_int32_t)src_0_location->v_data_ptr;
      }

      // - ERROR -
      else
      {
        exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
        BIC_EXCEPTION_PUSH_METHOD_RI("UnicodeChar#1");
        new_exception->params.push(1);
        new_exception->params.push(src_0_location->v_type);

        return false;
      }
    }
  }

  // - ERROR -
  if (!utf8proc_codepoint_valid(result))
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_UNICODE_CHAR_INVALID_CODE_POINT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(result);

    return false;
  }

  dst_location->v_data_ptr = (utf8proc_int32_t)result;

  return true;
}/*}}}*/

bool bic_unicode_char_method_to_lower_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  utf8proc_int32_t result =
    utf8proc_tolower((utf8proc_int32_t)dst_location->v_data_ptr);

  BIC_SIMPLE_SET_RES(c_bi_class_unicode_char,result);

  return true;
}/*}}}*/

bool bic_unicode_char_method_to_upper_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  utf8proc_int32_t result =
    utf8proc_toupper((utf8proc_int32_t)dst_location->v_data_ptr);

  BIC_SIMPLE_SET_RES(c_bi_class_unicode_char,result);

  return true;
}/*}}}*/

bool bic_unicode_char_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = (utf8proc_int32_t)dst_location->v_data_ptr;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_unicode_char_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  if (src_0_location->v_type == c_bi_class_unicode_char)
  {
    utf8proc_int32_t first = (utf8proc_int32_t)dst_location->v_data_ptr;
    utf8proc_int32_t second = (utf8proc_int32_t)src_0_location->v_data_ptr;

    result = first < second ? -1 : (first > second ? 1 : 0);
  }
  else
  {
    result = c_bi_class_unicode_char < src_0_location->v_type ? -1 : 1;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_unicode_char_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING(
    string_ptr->data = (char *)cmalloc(4*sizeof(char));

    utf8proc_ssize_t count = utf8proc_encode_char(
      (utf8proc_int32_t)dst_location->v_data_ptr,
      (utf8proc_uint8_t *)string_ptr->data);

    string_ptr->data[count] = '\0';
    string_ptr->size = count + 1;
  );

  return true;
}/*}}}*/

bool bic_unicode_char_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  utf8proc_uint8_t buffer[4];
  utf8proc_ssize_t count = utf8proc_encode_char(
    (utf8proc_int32_t)dst_location->v_data_ptr,buffer);

  fwrite(buffer,count,1,stdout);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

// - class UNICODE_STRING -
built_in_class_s unicode_string_class =
{/*{{{*/
  "UnicodeString",
  c_modifier_public | c_modifier_final,
  21, unicode_string_methods,
  0, unicode_string_variables,
  bic_unicode_string_consts,
  bic_unicode_string_init,
  bic_unicode_string_clear,
  bic_unicode_string_compare,
  bic_unicode_string_length,
  bic_unicode_string_item,
  bic_unicode_string_first_idx,
  bic_unicode_string_next_idx,
  nullptr,
  bic_unicode_string_from_slice,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s unicode_string_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_unicode_string_operator_binary_equal
  },
  {
    "operator_binary_plus_equal#1",
    c_modifier_public | c_modifier_final,
    bic_unicode_string_operator_binary_plus_equal
  },
  {
    "operator_binary_asterisk_equal#1",
    c_modifier_public | c_modifier_final,
    bic_unicode_string_operator_binary_asterisk_equal
  },
  {
    "operator_binary_double_equal#1",
    c_modifier_public | c_modifier_final,
    bic_unicode_string_operator_binary_double_equal
  },
  {
    "operator_binary_exclamation_equal#1",
    c_modifier_public | c_modifier_final,
    bic_unicode_string_operator_binary_exclamation_equal
  },
  {
    "operator_binary_plus#1",
    c_modifier_public | c_modifier_final,
    bic_unicode_string_operator_binary_plus
  },
  {
    "operator_binary_asterisk#1",
    c_modifier_public | c_modifier_final,
    bic_unicode_string_operator_binary_asterisk
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_unicode_string_operator_binary_le_br_re_br
  },
  {
    "UnicodeString#1",
    c_modifier_public | c_modifier_final,
    bic_unicode_string_method_UnicodeString_1
  },
  {
    "to_lower#0",
    c_modifier_public | c_modifier_final,
    bic_unicode_string_method_to_lower_0
  },
  {
    "to_upper#0",
    c_modifier_public | c_modifier_final,
    bic_unicode_string_method_to_upper_0
  },
  {
    "head#1",
    c_modifier_public | c_modifier_final,
    bic_unicode_string_method_head_1
  },
  {
    "tail#1",
    c_modifier_public | c_modifier_final,
    bic_unicode_string_method_tail_1
  },
  {
    "range#2",
    c_modifier_public | c_modifier_final,
    bic_unicode_string_method_range_2
  },
  {
    "compare#1",
    c_modifier_public | c_modifier_final,
    bic_unicode_string_method_compare_1
  },
  {
    "item#1",
    c_modifier_public | c_modifier_final,
    bic_unicode_string_method_item_1
  },
  {
    "first_idx#0",
    c_modifier_public | c_modifier_final,
    bic_unicode_string_method_first_idx_0
  },
  {
    "next_idx#1",
    c_modifier_public | c_modifier_final,
    bic_unicode_string_method_next_idx_1
  },
  {
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_unicode_string_method_length_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_unicode_string_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_unicode_string_method_print_0
  },
};/*}}}*/

built_in_variable_s unicode_string_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_UNICODE_STRING_CHECK_INDEX() \
  /*{{{*/\
  ui_array_s *ustring_ptr = (ui_array_s *)dst_location->v_data_ptr;\
\
  /* - ERROR - */\
  if (index < 0 || index >= (ustring_ptr->used - 1)) {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_UNICODE_STRING_INDEX_EXCEEDS_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(index);\
\
    return false;\
  }\
  /*}}}*/

#define BIC_UNICODE_STRING_ITEM(NAME) \
  {/*{{{*/\
@begin ucl_params
<
index:retrieve_integer
>
method NAME
macro
; @end\
\
    BIC_UNICODE_STRING_CHECK_INDEX();\
\
    utf8proc_int32_t result = (utf8proc_int32_t)ustring_ptr->data[index];\
\
    BIC_SIMPLE_SET_RES(c_bi_class_unicode_char,result);\
  }/*}}}*/

#define BIC_UNICODE_STRING_OPERATOR_BINARY_PLUS(NAME) \
/*{{{*/\
@begin ucl_params
<
second:c_bi_class_unicode_string
second:c_bi_class_string
>
method NAME
macro
; @end\
\
  ui_array_s *first_ptr = (ui_array_s *)dst_location->v_data_ptr;\
  unsigned f_length = first_ptr->used - 1;\
\
  ui_array_s *result_ptr;\
\
  if (src_0_location->v_type == c_bi_class_unicode_string)\
  {\
    ui_array_s *second_ptr = (ui_array_s *)src_0_location->v_data_ptr;\
    unsigned s_length = second_ptr->used - 1;\
\
    /* - create unicode string - */\
    result_ptr = (ui_array_s *)cmalloc(sizeof(ui_array_s));\
    result_ptr->init_size(f_length + s_length + 1);\
\
    /* - construct result unicode string - */\
    memcpy(result_ptr->data,first_ptr->data,f_length*sizeof(unsigned));\
    memcpy(result_ptr->data + f_length,second_ptr->data,s_length*sizeof(unsigned));\
\
    result_ptr->data[f_length + s_length] = 0;\
    result_ptr->used = result_ptr->size;\
  }\
  else\
  {\
    string_s *second_ptr = (string_s *)src_0_location->v_data_ptr;\
    unsigned s_length = second_ptr->size - 1;\
\
    /* - create unicode string - */\
    result_ptr = (ui_array_s *)cmalloc(sizeof(ui_array_s));\
    result_ptr->init_size(f_length + s_length + 1);\
\
    /* - construct result unicode string - */\
    memcpy(result_ptr->data,first_ptr->data,f_length*sizeof(unsigned));\
\
    utf8proc_ssize_t cp_count = utf8proc_decompose(\
        (const utf8proc_uint8_t *)second_ptr->data,s_length,\
        (utf8proc_int32_t *)result_ptr->data + f_length,s_length,\
        (utf8proc_option_t)0);\
\
    result_ptr->data[f_length + cp_count] = 0;\
    result_ptr->used = f_length + cp_count + 1;\
  }\
/*}}}*/

#define BIC_UNICODE_STRING_OPERATOR_BINARY_ASTERISK(NAME) \
/*{{{*/\
@begin ucl_params
<
mult:retrieve_integer
>
method NAME
macro
; @end\
\
  ui_array_s *source_ptr = (ui_array_s *)dst_location->v_data_ptr;\
  unsigned s_length = source_ptr->used - 1;\
\
  /* - create unicode string - */\
  ui_array_s *result_ptr = (ui_array_s *)cmalloc(sizeof(ui_array_s));\
  result_ptr->init_size(s_length*mult + 1);\
\
  if (s_length != 0 && mult > 0)\
  {\
    /* - construct result unicode string - */\
    do {\
      memcpy(result_ptr->data + result_ptr->used,source_ptr->data,s_length*sizeof(unsigned));\
    } while((result_ptr->used += s_length) < result_ptr->size - 1);\
  }\
\
  result_ptr->push(0);\
/*}}}*/

#define BIC_UNICODE_STRING_TRANSFORM_STRING(CODE_POINT_CODE) \
/*{{{*/\
\
  /* - create target unicode string - */\
  ui_array_s *target_ptr = (ui_array_s *)cmalloc(sizeof(ui_array_s));\
  target_ptr->init_size(source_ptr->used);\
\
  if (source_ptr->used > 1)\
  {\
    utf8proc_int32_t *s_ptr = (utf8proc_int32_t *)source_ptr->data;\
    utf8proc_int32_t *s_ptr_end = s_ptr + source_ptr->used - 1;\
    utf8proc_int32_t *t_ptr = (utf8proc_int32_t *)target_ptr->data;\
    do {\
      CODE_POINT_CODE;\
    } while(++t_ptr,++s_ptr < s_ptr_end);\
  }\
\
  target_ptr->data[source_ptr->used - 1] = 0;\
  target_ptr->used = source_ptr->used;\
/*}}}*/

void bic_unicode_string_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_unicode_string_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (ui_array_s *)nullptr;
}/*}}}*/

void bic_unicode_string_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  ui_array_s *ustring_ptr = (ui_array_s *)location_ptr->v_data_ptr;

  // - if websocket context exists -
  if (ustring_ptr != nullptr)
  {
    ustring_ptr->clear();
    cfree(ustring_ptr);
  }
}/*}}}*/

int bic_unicode_string_compare(location_s *first_loc,location_s *second_loc)
{/*{{{*/
  ui_array_s *first = (ui_array_s *)first_loc->v_data_ptr;
  ui_array_s *second = (ui_array_s *)second_loc->v_data_ptr;

  if (first->used < second->used) { return -1; }
  if (first->used > second->used) { return 1; }

  if (first->used > 1)
  {
    utf8proc_int32_t *f_ptr = (utf8proc_int32_t *)first->data;
    utf8proc_int32_t *f_ptr_end = f_ptr + first->used - 1;
    utf8proc_int32_t *s_ptr = (utf8proc_int32_t *)second->data;

    do {

      // - if code points differs -
      if (*f_ptr != *s_ptr)
      {
        return (*f_ptr < *s_ptr) ? -1 : 1;
      }

    } while(++s_ptr,++f_ptr < f_ptr_end);
  }

  return 0;
}/*}}}*/

unsigned bic_unicode_string_length(location_s *location_ptr)
{/*{{{*/
  ui_array_s *ustring_ptr = (ui_array_s *)location_ptr->v_data_ptr;
  return ustring_ptr->used - 1;
}/*}}}*/

location_s *bic_unicode_string_item(interpreter_thread_s &it,location_s *location_ptr,unsigned index)
{/*{{{*/
  ui_array_s *ustring_ptr = (ui_array_s *)location_ptr->v_data_ptr;

  // FIXME TODO check index ...
  cassert(index < ustring_ptr->used - 1);

  utf8proc_int32_t result = (utf8proc_int32_t)ustring_ptr->data[index];
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_unicode_char,result);

  return new_location;
}/*}}}*/

unsigned bic_unicode_string_first_idx(location_s *location_ptr)
{/*{{{*/
  ui_array_s *ustring_ptr = (ui_array_s *)location_ptr->v_data_ptr;
  return ustring_ptr->used > 1 ? 0 : c_idx_not_exist;
}/*}}}*/

unsigned bic_unicode_string_next_idx(location_s *location_ptr,unsigned index)
{/*{{{*/
  ui_array_s *ustring_ptr = (ui_array_s *)location_ptr->v_data_ptr;

  // FIXME TODO check index ...
  cassert(index < ustring_ptr->used - 1);

  return (index + 1 < ustring_ptr->used - 1) ? index + 1 : c_idx_not_exist;
}/*}}}*/

location_s *bic_unicode_string_from_slice(interpreter_thread_s &it,location_s *location_ptr,pointer_array_s &slice_array)
{/*{{{*/
  ui_array_s *ustring_ptr = (ui_array_s *)cmalloc(sizeof(ui_array_s));
  ustring_ptr->init_size(slice_array.used + 1);
  ustring_ptr->used = ustring_ptr->size;

  if (slice_array.used > 0)
  {
    pointer *l_ptr = slice_array.data;
    pointer *l_ptr_end = l_ptr + slice_array.used;
    utf8proc_int32_t *c_ptr = (utf8proc_int32_t *)ustring_ptr->data;
    do
    {
      *c_ptr = (utf8proc_int32_t)((location_s *)*l_ptr)->v_data_ptr;
    }
    while(++c_ptr,++l_ptr < l_ptr_end);
  }

  ustring_ptr->data[slice_array.used] = 0;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_unicode_string,ustring_ptr);

  return new_location;
}/*}}}*/

bool bic_unicode_string_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_unicode_string_operator_binary_plus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_UNICODE_STRING_OPERATOR_BINARY_PLUS("operator_binary_plus_equal#1");

  BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_unicode_string,result_ptr,2);

  BIC_SET_DESTINATION(new_location);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_unicode_string_operator_binary_asterisk_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_UNICODE_STRING_OPERATOR_BINARY_ASTERISK("operator_binary_asterisk_equal#1");

  BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_unicode_string,result_ptr,2);

  BIC_SET_DESTINATION(new_location);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_unicode_string_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  if (src_0_location->v_type == c_bi_class_unicode_string)
  {
    result = *((ui_array_s *)dst_location->v_data_ptr) == *((ui_array_s *)src_0_location->v_data_ptr);
  }
  else
  {
    result = 0;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_unicode_string_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  if (src_0_location->v_type == c_bi_class_unicode_string)
  {
    result = !(*((ui_array_s *)dst_location->v_data_ptr) == *((ui_array_s *)src_0_location->v_data_ptr));
  }
  else
  {
    result = 1;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_unicode_string_operator_binary_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_UNICODE_STRING_OPERATOR_BINARY_PLUS("operator_binary_plus#1");

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_unicode_string,result_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_unicode_string_operator_binary_asterisk(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_UNICODE_STRING_OPERATOR_BINARY_ASTERISK("operator_binary_asterisk#1")

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_unicode_string,result_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_unicode_string_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_UNICODE_STRING_ITEM("operator_binary_le_br_re_br#1");

  return true;
}/*}}}*/

bool bic_unicode_string_method_UnicodeString_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:c_bi_class_string
>
method UnicodeString
; @end

  string_s *source_ptr = (string_s *)src_0_location->v_data_ptr;
  utf8proc_ssize_t source_length = source_ptr->size - 1;

  // - create unicode string -
  ui_array_s *ustring_ptr = (ui_array_s *)cmalloc(sizeof(ui_array_s));
  ustring_ptr->init_size(source_length + 1);

  utf8proc_ssize_t cp_count = utf8proc_decompose(
      (const utf8proc_uint8_t *)source_ptr->data,source_length,
      (utf8proc_int32_t *)ustring_ptr->data,source_length,
      (utf8proc_option_t)0);

  // - ERROR -
  if (cp_count < 0 || cp_count > source_length)
  {
    ustring_ptr->clear();
    cfree(ustring_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_UNICODE_STRING_UTF8_DECOMPOSE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  ustring_ptr->data[cp_count] = 0;
  ustring_ptr->used = cp_count + 1;

  dst_location->v_data_ptr = (ui_array_s *)ustring_ptr;

  return true;
}/*}}}*/

bool bic_unicode_string_method_to_lower_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ui_array_s *source_ptr = (ui_array_s *)dst_location->v_data_ptr;

  BIC_UNICODE_STRING_TRANSFORM_STRING(

    // - code point to lower -
    *t_ptr = utf8proc_tolower(*s_ptr);
  )

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_unicode_string,target_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_unicode_string_method_to_upper_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ui_array_s *source_ptr = (ui_array_s *)dst_location->v_data_ptr;

  BIC_UNICODE_STRING_TRANSFORM_STRING(

    // - code point to upper -
    *t_ptr = utf8proc_toupper(*s_ptr);
  )

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_unicode_string,target_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_unicode_string_method_head_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
original_length:retrieve_integer
>
method head
; @end

  ui_array_s *ustring_ptr = (ui_array_s *)dst_location->v_data_ptr;

  // - adjust length parameter -
  long long int length = original_length;

  if (length < 0)
  {
    length = ustring_ptr->used - 1 + length;
  }

  // - ERROR -
  if (length < 0 || length > ustring_ptr->used - 1)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_UNICODE_STRING_INDEX_EXCEEDS_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(original_length);

    return false;
  }

  // - create unicode string -
  ui_array_s *new_ustring_ptr = (ui_array_s *)cmalloc(sizeof(ui_array_s));
  new_ustring_ptr->init_size(length + 1);

  // - copy unicode string head -
  memcpy(new_ustring_ptr->data,ustring_ptr->data,length*sizeof(unsigned));
  new_ustring_ptr->data[length] = 0;
  new_ustring_ptr->used = length + 1;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_unicode_string,new_ustring_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_unicode_string_method_tail_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
original_length:retrieve_integer
>
method tail
; @end

  ui_array_s *ustring_ptr = (ui_array_s *)dst_location->v_data_ptr;

  // - adjust length parameter -
  long long int length = original_length;

  if (length < 0)
  {
    length = ustring_ptr->used - 1 + length;
  }

  // - ERROR -
  if (length < 0 || length > ustring_ptr->used - 1)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_UNICODE_STRING_INDEX_EXCEEDS_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(original_length);

    return false;
  }

  // - create unicode string -
  ui_array_s *new_ustring_ptr = (ui_array_s *)cmalloc(sizeof(ui_array_s));
  new_ustring_ptr->init_size(length + 1);

  // - copy unicode string tail -
  memcpy(new_ustring_ptr->data,ustring_ptr->data + (ustring_ptr->used - 1 - length),length*sizeof(unsigned));
  new_ustring_ptr->data[length] = 0;
  new_ustring_ptr->used = length + 1;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_unicode_string,new_ustring_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_unicode_string_method_range_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
original_first_index:retrieve_integer
original_second_index:retrieve_integer
>
method range
; @end

  ui_array_s *ustring_ptr = (ui_array_s *)dst_location->v_data_ptr;

  // - adjust first_index parameter -
  long long int first_index = original_first_index;
  if (first_index < 0)
  {
    first_index = ustring_ptr->used - 1 + first_index;
  }

  // - adjust second_index parameter -
  long long int second_index = original_second_index;
  if (second_index < 0)
  {
    second_index = ustring_ptr->used - 1 + second_index;
  }

  // - ERROR -
  if (first_index > second_index ||
      first_index < 0 || first_index >= ustring_ptr->used - 1 ||
      second_index < 0 || second_index >= ustring_ptr->used - 1)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_UNICODE_STRING_WRONG_RANGE_INDEXES,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(original_first_index);
    new_exception->params.push(original_second_index);

    return false;
  }

  // - new unicode string length -
  unsigned length = second_index - first_index + 1;

  // - create unicode string -
  ui_array_s *new_ustring_ptr = (ui_array_s *)cmalloc(sizeof(ui_array_s));
  new_ustring_ptr->init_size(length + 1);

  // - copy unicode string range -
  memcpy(new_ustring_ptr->data,ustring_ptr->data + first_index,length*sizeof(unsigned));
  new_ustring_ptr->data[length] = 0;
  new_ustring_ptr->used = length + 1;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_unicode_string,new_ustring_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_unicode_string_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  if (src_0_location->v_type == c_bi_class_unicode_string)
  {
    ui_array_s *first = (ui_array_s *)dst_location->v_data_ptr;
    ui_array_s *second = (ui_array_s *)src_0_location->v_data_ptr;

    if (first->used == second->used)
    {
      result = 0;

      if (first->used > 1)
      {
        utf8proc_int32_t *f_ptr = (utf8proc_int32_t *)first->data;
        utf8proc_int32_t *f_ptr_end = f_ptr + first->used - 1;
        utf8proc_int32_t *s_ptr = (utf8proc_int32_t *)second->data;

        do {

          // - if code points differs -
          if (*f_ptr != *s_ptr)
          {
            result = (*f_ptr < *s_ptr) ? -1 : 1;
            break;
          }

        } while(++s_ptr,++f_ptr < f_ptr_end);
      }
    }
    else
    {
      result = (first->used < second->used) ? -1 : 1;
    }
  }
  else
  {
    result = c_bi_class_unicode_string < src_0_location->v_type ? -1 : 1;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_unicode_string_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_UNICODE_STRING_ITEM("item#1");

  return true;
}/*}}}*/

bool bic_unicode_string_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ui_array_s *ustring_ptr = (ui_array_s *)dst_location->v_data_ptr;

  if (ustring_ptr->used > 1)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,0);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_unicode_string_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
index:retrieve_integer
>
method next_idx
; @end

  BIC_UNICODE_STRING_CHECK_INDEX();

  if (++index < ustring_ptr->used - 1)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,index);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_unicode_string_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((ui_array_s *)dst_location->v_data_ptr)->used - 1;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_unicode_string_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ui_array_s *ustring_ptr = (ui_array_s *)dst_location->v_data_ptr;

  bc_array_s buffer;
  buffer.init();

  // - ERROR -
  if (!utf8proc_s::unicode_to_utf8(*ustring_ptr,buffer))
  {
    buffer.clear();

    exception_s::throw_exception(it,module.error_base + c_error_UNICODE_STRING_UTF8_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  buffer.push('\0');

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->data = buffer.data;
  string_ptr->size = buffer.used;

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_unicode_string_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  utf8proc_s::unicode_print(*((ui_array_s *)dst_location->v_data_ptr));

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

