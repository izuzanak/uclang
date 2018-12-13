
@begin
include "binbits_module.h"
@end

// - BINBITS indexes of built in classes -
unsigned c_bi_class_bin_array = c_idx_not_exist;
unsigned c_bi_class_bin_array_ref = c_idx_not_exist;
unsigned c_bi_class_bin_dict = c_idx_not_exist;
unsigned c_bi_class_bin_dict_ref = c_idx_not_exist;

// - BINBITS module -
built_in_module_s module =
{/*{{{*/
  4,                       // Class count
  binbits_classes,         // Classes

  0,                       // Error base index
  11,                      // Error count
  binbits_error_strings,   // Error strings

  binbits_initialize,      // Initialize function
  binbits_print_exception, // Print exceptions function
};/*}}}*/

// - BINBITS classes -
built_in_class_s *binbits_classes[] =
{/*{{{*/
  &bin_array_class,
  &bin_array_ref_class,
  &bin_dict_class,
  &bin_dict_ref_class,
};/*}}}*/

// - BINBITS error strings -
const char *binbits_error_strings[] =
{/*{{{*/
  "error_BIN_ARRAY_UNKNOWN_DATA_TYPE",
  "error_BIN_ARRAY_INDEX_EXCEEDS_RANGE",
  "error_BIN_ARRAY_WRONG_RANGE_INDEXES",
  "error_BIN_ARRAY_CANNOT_RESIZE_TO_SMALLER_SIZE",
  "error_BIN_ARRAY_NO_ELEMENTS",
  "error_BIN_ARRAY_UNSUPPORTED_TYPE_OF_SOURCE_ITERABLE_ITEM",
  "error_BIN_ARRAY_REF_INVALID_REFERENCE",
  "error_BIN_DICT_UNKNOWN_DATA_TYPE",
  "error_BIN_DICT_INDEX_DOES_NOT_REFER_TO_VALID_VALUE",
  "error_BIN_DICT_INVALID_KEY",
  "error_BIN_DICT_REF_INVALID_REFERENCE",
};/*}}}*/

// - BINBITS initialize -
bool binbits_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize bin_array class identifier -
  c_bi_class_bin_array = class_base_idx++;

  // - initialize bin_array_ref class identifier -
  c_bi_class_bin_array_ref = class_base_idx++;

  // - initialize bin_dict class identifier -
  c_bi_class_bin_dict = class_base_idx++;

  // - initialize bin_dict_ref class identifier -
  c_bi_class_bin_dict_ref = class_base_idx++;

  return true;
}/*}}}*/

// - BINBITS print exception -
bool binbits_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_BIN_ARRAY_UNKNOWN_DATA_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nData type not supported by binary array\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_BIN_ARRAY_INDEX_EXCEEDS_RANGE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nIndex %" HOST_LL_FORMAT "d exceeds binary array range\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_BIN_ARRAY_WRONG_RANGE_INDEXES:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong range indexes %" HOST_LL_FORMAT "d, %" HOST_LL_FORMAT "d for binary array\n",exception.params[0],exception.params[1]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_BIN_ARRAY_CANNOT_RESIZE_TO_SMALLER_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nResize binary array of size %" HOST_LL_FORMAT "d to size %" HOST_LL_FORMAT "d\n",exception.params[1],exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_BIN_ARRAY_NO_ELEMENTS:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nBinary array does not contain any elements\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_BIN_ARRAY_UNSUPPORTED_TYPE_OF_SOURCE_ITERABLE_ITEM:
    {
      class_record_s &class_record = it.class_records[exception.params[0]];

      fprintf(stderr," ---------------------------------------- \n");
      fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
      print_error_line(source.source_string,source_pos);
      fprintf(stderr,"\nUnsupported type ");
      print_class_sequence(it.class_symbol_names,it.class_records,class_stack,class_record.parent_record);
      fprintf(stderr,"%s of source iterable item\n",it.class_symbol_names[class_record.name_idx].data);
      fprintf(stderr," ---------------------------------------- \n");
    }
    break;
  case c_error_BIN_ARRAY_REF_INVALID_REFERENCE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid binary array reference\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_BIN_DICT_UNKNOWN_DATA_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nData type not supported by binary dictionary\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_BIN_DICT_INDEX_DOES_NOT_REFER_TO_VALID_VALUE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nIndex %" HOST_LL_FORMAT "d does not refer to valid binary dictionary element\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_BIN_DICT_INVALID_KEY:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid binary dictionary key value\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_BIN_DICT_REF_INVALID_REFERENCE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid binary dictionary reference\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class BIN_ARRAY -
built_in_class_s bin_array_class =
{/*{{{*/
  "BinArray",
  c_modifier_public | c_modifier_final,
  31, bin_array_methods,
  4, bin_array_variables,
  bic_bin_array_consts,
  bic_bin_array_init,
  bic_bin_array_clear,
  nullptr,
  bic_bin_array_length,
  bic_bin_array_item,
  bic_bin_array_first_idx,
  bic_bin_array_next_idx,
  nullptr,
  nullptr,
  bic_bin_array_pack,
  bic_bin_array_unpack,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s bin_array_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_bin_array_operator_binary_equal
  },
  {
    "operator_binary_plus_equal#1",
    c_modifier_public | c_modifier_final,
    bic_bin_array_operator_binary_plus_equal
  },
  {
    "operator_binary_double_equal#1",
    c_modifier_public | c_modifier_final,
    bic_bin_array_operator_binary_double_equal
  },
  {
    "operator_binary_exclamation_equal#1",
    c_modifier_public | c_modifier_final,
    bic_bin_array_operator_binary_exclamation_equal
  },
  {
    "operator_binary_plus#1",
    c_modifier_public | c_modifier_final,
    bic_bin_array_operator_binary_plus
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_bin_array_operator_binary_le_br_re_br
  },
  {
    "BinArray#1",
    c_modifier_public | c_modifier_final,
    bic_bin_array_method_BinArray_1
  },
  {
    "BinArray#2",
    c_modifier_public | c_modifier_final,
    bic_bin_array_method_BinArray_2
  },
  {
    "clear#0",
    c_modifier_public | c_modifier_final,
    bic_bin_array_method_clear_0
  },
  {
    "resize#1",
    c_modifier_public | c_modifier_final,
    bic_bin_array_method_resize_1
  },
  {
    "items#0",
    c_modifier_public | c_modifier_final,
    bic_bin_array_method_items_0
  },
  {
    "push#1",
    c_modifier_public | c_modifier_final,
    bic_bin_array_method_push_1
  },
  {
    "pop#0",
    c_modifier_public | c_modifier_final,
    bic_bin_array_method_pop_0
  },
  {
    "last#0",
    c_modifier_public | c_modifier_final,
    bic_bin_array_method_last_0
  },
  {
    "fill#1",
    c_modifier_public | c_modifier_final,
    bic_bin_array_method_fill_1
  },
  {
    "head#1",
    c_modifier_public | c_modifier_final,
    bic_bin_array_method_head_1
  },
  {
    "tail#1",
    c_modifier_public | c_modifier_final,
    bic_bin_array_method_tail_1
  },
  {
    "range#2",
    c_modifier_public | c_modifier_final,
    bic_bin_array_method_range_2
  },
  {
    "get_idx#1",
    c_modifier_public | c_modifier_final,
    bic_bin_array_method_get_idx_1
  },
  {
    "get_idxs#1",
    c_modifier_public | c_modifier_final,
    bic_bin_array_method_get_idxs_1
  },
  {
    "contain#1",
    c_modifier_public | c_modifier_final,
    bic_bin_array_method_contain_1
  },
  {
    "compare#1",
    c_modifier_public | c_modifier_final,
    bic_bin_array_method_compare_1
  },
  {
    "item#1",
    c_modifier_public | c_modifier_final,
    bic_bin_array_method_item_1
  },
  {
    "first_idx#0",
    c_modifier_public | c_modifier_final,
    bic_bin_array_method_first_idx_0
  },
  {
    "last_idx#0",
    c_modifier_public | c_modifier_final,
    bic_bin_array_method_last_idx_0
  },
  {
    "next_idx#1",
    c_modifier_public | c_modifier_final,
    bic_bin_array_method_next_idx_1
  },
  {
    "prev_idx#1",
    c_modifier_public | c_modifier_final,
    bic_bin_array_method_prev_idx_1
  },
  {
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_bin_array_method_length_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_bin_array_method_to_string_0
  },
  {
    "to_string#1",
    c_modifier_public | c_modifier_final,
    bic_bin_array_method_to_string_1
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_bin_array_method_print_0
  },
};/*}}}*/

built_in_variable_s bin_array_variables[] =
{/*{{{*/

  // - insert binary array type constants -
  { "TYPE_INT32", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_UINT32", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_FLOAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_DOUBLE", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

#define BIC_BIN_ARRAY_COMPARE_ELEMENTS(ARRAY_TYPE,TYPE) \
{/*{{{*/\
  ARRAY_TYPE *f_array_ptr = (ARRAY_TYPE *)f_ba_ptr->cont;\
  ARRAY_TYPE *s_array_ptr = (ARRAY_TYPE *)s_ba_ptr->cont;\
\
  if (f_array_ptr->used != s_array_ptr->used)\
  {\
    result = f_array_ptr->used < s_array_ptr->used ? -1 : 1;\
  }\
  else\
  {\
    result = 0;\
\
    if (f_array_ptr->used > 0)\
    {\
      TYPE *f_ptr = f_array_ptr->data;\
      TYPE *f_ptr_end = f_ptr + f_array_ptr->used;\
      TYPE *s_ptr = s_array_ptr->data;\
      do {\
        if (*f_ptr != *s_ptr)\
        {\
          result = *f_ptr < *s_ptr ? -1 : 1;\
          break;\
        }\
      } while(++s_ptr,++f_ptr < f_ptr_end);\
    }\
  }\
}/*}}}*/

#define BIC_BIN_ARRAY_COMPARE(FIRST_LOC_PTR,SECOND_LOC_PTR,SOURCE_POS) \
  {/*{{{*/\
    if ((SECOND_LOC_PTR)->v_type == c_bi_class_bin_array)\
    {\
      bin_array_s *f_ba_ptr = (bin_array_s *)(FIRST_LOC_PTR)->v_data_ptr;\
      bin_array_s *s_ba_ptr = (bin_array_s *)(SECOND_LOC_PTR)->v_data_ptr;\
\
      if (f_ba_ptr->type == s_ba_ptr->type)\
      {\
        switch (f_ba_ptr->type)\
        {\
        case c_bin_array_type_int32:\
          BIC_BIN_ARRAY_COMPARE_ELEMENTS(bi_array_s,int);\
          break;\
        case c_bin_array_type_uint32:\
          BIC_BIN_ARRAY_COMPARE_ELEMENTS(ui_array_s,unsigned);\
          break;\
        case c_bin_array_type_float:\
          BIC_BIN_ARRAY_COMPARE_ELEMENTS(bf_array_s,float);\
          break;\
        case c_bin_array_type_double:\
          BIC_BIN_ARRAY_COMPARE_ELEMENTS(bd_array_s,double);\
          break;\
        default:\
          cassert(0);\
        }\
      }\
      else\
      {\
        result = f_ba_ptr->type < s_ba_ptr->type ? -1 : 1;\
      }\
    }\
    else\
    {\
      result = c_bi_class_bin_array < (SECOND_LOC_PTR)->v_type ? -1 : 1;\
    }\
  }/*}}}*/

#define BIC_BIN_ARRAY_GET_USED(LOCATION) \
/*{{{*/\
  bin_array_s *ba_ptr = (bin_array_s *)(LOCATION)->v_data_ptr;\
  unsigned used;\
\
  switch (ba_ptr->type)\
  {\
  case c_bin_array_type_int32:\
    used = ((bi_array_s *)ba_ptr->cont)->used;\
    break;\
  case c_bin_array_type_uint32:\
    used = ((ui_array_s *)ba_ptr->cont)->used;\
    break;\
  case c_bin_array_type_float:\
    used = ((bf_array_s *)ba_ptr->cont)->used;\
    break;\
  case c_bin_array_type_double:\
    used = ((bd_array_s *)ba_ptr->cont)->used;\
    break;\
  default:\
    cassert(0);\
  }\
/*}}}*/

#define BIC_BIN_ARRAY_APPEND_INTEGER_ARRAY(SRC_LOCATION,TARGET_PTR) \
{/*{{{*/\
  pointer_array_s *source_ptr = (pointer_array_s *)SRC_LOCATION->v_data_ptr;\
\
  if (source_ptr->used != 0)\
  {\
    pointer *ptr = source_ptr->data;\
    pointer *ptr_end = ptr + source_ptr->used;\
\
    do\
    {\
      location_s *item_location = it.get_location_value(*ptr);\
      long long int value;\
\
      /* - ERROR - */\
      if (!it.retrieve_integer(item_location,value))\
      {\
        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_BIN_ARRAY_UNSUPPORTED_TYPE_OF_SOURCE_ITERABLE_ITEM,operands[c_source_pos_idx],(location_s *)it.blank_location);\
        new_exception->params.push(item_location->v_type);\
\
        return false;\
      }\
\
      /* - push value to binary array - */\
      (TARGET_PTR)->push(value);\
    }\
    while(++ptr < ptr_end);\
  }\
}/*}}}*/

#define BIC_BIN_ARRAY_APPEND_FLOAT_ARRAY(SRC_LOCATION,TARGET_PTR) \
{/*{{{*/\
  pointer_array_s *source_ptr = (pointer_array_s *)SRC_LOCATION->v_data_ptr;\
\
  if (source_ptr->used != 0)\
  {\
    pointer *ptr = source_ptr->data;\
    pointer *ptr_end = ptr + source_ptr->used;\
\
    do\
    {\
      location_s *item_location = it.get_location_value(*ptr);\
      double value;\
\
      /* - ERROR - */\
      if (!it.retrieve_float(item_location,value))\
      {\
        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_BIN_ARRAY_UNSUPPORTED_TYPE_OF_SOURCE_ITERABLE_ITEM,operands[c_source_pos_idx],(location_s *)it.blank_location);\
        new_exception->params.push(item_location->v_type);\
\
        return false;\
      }\
\
      /* - push value to binary array - */\
      (TARGET_PTR)->push(value);\
    }\
    while(++ptr < ptr_end);\
  }\
}/*}}}*/

#define BIC_BIN_ARRAY_APPEND_INTEGER_ITERABLE_BODY(TARGET_PTR) \
{/*{{{*/\
  long long int value;\
\
  /* - ERROR - */\
  if (!it.retrieve_integer(item_location,value))\
  {\
    it.release_location_ptr(item_reference);\
\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_BIN_ARRAY_UNSUPPORTED_TYPE_OF_SOURCE_ITERABLE_ITEM,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(item_location->v_type);\
\
    return false;\
  }\
\
  it.release_location_ptr(item_reference);\
\
  /* - push value to binary array - */\
  (TARGET_PTR)->push(value);\
}/*}}}*/

#define BIC_BIN_ARRAY_APPEND_FLOAT_ITERABLE_BODY(TARGET_PTR) \
{/*{{{*/\
  double value;\
\
  /* - ERROR - */\
  if (!it.retrieve_float(item_location,value))\
  {\
    it.release_location_ptr(item_reference);\
\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_BIN_ARRAY_UNSUPPORTED_TYPE_OF_SOURCE_ITERABLE_ITEM,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(item_location->v_type);\
\
    return false;\
  }\
\
  it.release_location_ptr(item_reference);\
\
  /* - push value to binary array - */\
  (TARGET_PTR)->push(value);\
}/*}}}*/

#define BIC_BIN_ARRAY_APPEND_ITERABLE(SRC_LOCATION,TARGET_PTR,BODY_TYPE) \
{/*{{{*/\
\
  /* - retrieve iterable type - */\
  unsigned iter_type = it.get_iterable_type(SRC_LOCATION);\
\
  /* - ERROR - */\
  if (iter_type == c_idx_not_exist)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,c_error_OBJECT_OF_CLASS_IS_NOT_ITERABLE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(SRC_LOCATION->v_type);\
\
    return false;\
  }\
\
  if (iter_type == c_iter_first_idx_next_idx_item)\
  {\
    long long int index;\
    location_s *item_reference;\
    location_s *item_location;\
\
    /* - retrieve first index - */\
    BIC_CALL_FIRST_IDX(it,SRC_LOCATION,index,operands[c_source_pos_idx],return false;);\
\
    while (index != c_idx_not_exist)\
    {\
      /* - retrieve item location - */\
      BIC_CALL_ITEM(it,SRC_LOCATION,index,item_reference,operands[c_source_pos_idx],return false;);\
      item_location = it.get_location_value(item_reference);\
\
      BIC_BIN_ARRAY_APPEND_ ## BODY_TYPE ## _ITERABLE_BODY(TARGET_PTR);\
\
      /* - retrieve next index - */\
      BIC_CALL_NEXT_IDX(it,SRC_LOCATION,index,index,operands[c_source_pos_idx],return false;);\
    }\
  }\
  else if (iter_type == c_iter_next_item)\
  {\
    location_s *item_reference;\
    location_s *item_location;\
\
    do\
    {\
      /* - retrieve next item location - */\
      BIC_CALL_NEXT_ITEM(it,SRC_LOCATION,item_reference,operands[c_source_pos_idx],return false;);\
      item_location = it.get_location_value(item_reference);\
\
      if (item_location->v_type == c_bi_class_blank)\
      {\
        it.release_location_ptr(item_reference);\
        break;\
      }\
\
      BIC_BIN_ARRAY_APPEND_ ## BODY_TYPE ## _ITERABLE_BODY(TARGET_PTR);\
\
    }\
    while(true);\
  }\
  else\
  {\
    cassert(0);\
  }\
}/*}}}*/

#define BIC_BIN_ARRAY_CHECK_INDEX() \
/*{{{*/\
  BIC_BIN_ARRAY_GET_USED(dst_location);\
\
  /* - ERROR - */\
  if (index < 0 || index >= used)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_BIN_ARRAY_INDEX_EXCEEDS_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(index);\
\
    return false;\
  }\
/*}}}*/

#define BIC_BIN_ARRAY_ITEM(NAME) \
{/*{{{*/\
@begin ucl_params
<
index:retrieve_integer
>
method NAME
macro
; @end\
\
  BIC_BIN_ARRAY_CHECK_INDEX();\
\
  /* - create bin array reference - */\
  bin_array_ref_s *bar_ptr = ba_ptr->create_reference(dst_location,index);\
\
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_bin_array_ref,bar_ptr);\
  BIC_SET_RESULT(new_location);\
}/*}}}*/

void bic_bin_array_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert binary array type constants -
  {
    const_locations.push_blanks(4);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 4);

#define CREATE_BIN_ARRAY_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_BIN_ARRAY_TYPE_BIC_STATIC(c_bin_array_type_int32);
    CREATE_BIN_ARRAY_TYPE_BIC_STATIC(c_bin_array_type_uint32);
    CREATE_BIN_ARRAY_TYPE_BIC_STATIC(c_bin_array_type_float);
    CREATE_BIN_ARRAY_TYPE_BIC_STATIC(c_bin_array_type_double);
  }

}/*}}}*/

void bic_bin_array_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (bin_array_s *)nullptr;
}/*}}}*/

void bic_bin_array_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  bin_array_s *ba_ptr = (bin_array_s *)location_ptr->v_data_ptr;

  if (ba_ptr != nullptr)
  {
    ba_ptr->clear(it);
    cfree(ba_ptr);
  }
}/*}}}*/

unsigned bic_bin_array_length(location_s *location_ptr)
{/*{{{*/
  BIC_BIN_ARRAY_GET_USED(location_ptr);
  return used;
}/*}}}*/

location_s *bic_bin_array_item(interpreter_thread_s &it,location_s *location_ptr,unsigned index)
{/*{{{*/
  BIC_BIN_ARRAY_GET_USED(location_ptr);

  // FIXME TODO check index ...
  cassert(index < used);

  // - create bin array reference -
  bin_array_ref_s *bar_ptr = ba_ptr->create_reference(location_ptr,index);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_bin_array_ref,bar_ptr);
  return new_location;
}/*}}}*/

unsigned bic_bin_array_first_idx(location_s *location_ptr)
{/*{{{*/
  BIC_BIN_ARRAY_GET_USED(location_ptr);
  return used != 0 ? 0 : c_idx_not_exist;
}/*}}}*/

unsigned bic_bin_array_next_idx(location_s *location_ptr,unsigned index)
{/*{{{*/
  BIC_BIN_ARRAY_GET_USED(location_ptr);

  // FIXME TODO check index ...
  cassert(index < used);

  return (index + 1 < used) ? index + 1 : c_idx_not_exist;
}/*}}}*/

bool bic_bin_array_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack)
{/*{{{*/
  bin_array_s *ba_ptr = (bin_array_s *)location_ptr->v_data_ptr;

#define BIC_BIN_ARRAY_PACK(ARRAY_TYPE,TYPE) \
{/*{{{*/\
  ARRAY_TYPE *array_ptr = (ARRAY_TYPE *)ba_ptr->cont;\
\
  if (array_ptr->used != 0)\
  {\
    TYPE *e_ptr = array_ptr->data + array_ptr->used;\
    TYPE *e_ptr_end = array_ptr->data;\
\
    do\
    {\
      stream.append(sizeof(TYPE),(const char *)(--e_ptr));\
    }\
    while(e_ptr > e_ptr_end);\
  }\
\
  stream.append(sizeof(unsigned),(const char *)&array_ptr->used);\
}/*}}}*/

  switch (ba_ptr->type)
  {
  case c_bin_array_type_int32:
    BIC_BIN_ARRAY_PACK(bi_array_s,int);
    break;
  case c_bin_array_type_uint32:
    BIC_BIN_ARRAY_PACK(ui_array_s,unsigned);
    break;
  case c_bin_array_type_float:
    BIC_BIN_ARRAY_PACK(bf_array_s,float);
    break;
  case c_bin_array_type_double:
    BIC_BIN_ARRAY_PACK(bd_array_s,double);
    break;
  default:
    cassert(0);
  }

  stream.append(sizeof(unsigned),(const char *)&ba_ptr->type);

  return true;
}/*}}}*/

bool bic_bin_array_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos)
{/*{{{*/
  if (stream.used < sizeof(unsigned))
  {
    return false;
  }

  unsigned type;
  stream.from_end(sizeof(unsigned),(char *)&type,order_bytes);

  // - binary array container pointer -
  void *cont = nullptr;

#define BIC_BIN_ARRAY_UNPACK(ARRAY_TYPE,TYPE) \
{/*{{{*/\
  if (stream.used < sizeof(unsigned))\
  {\
    return false;\
  }\
\
  unsigned length;\
  stream.from_end(sizeof(unsigned),(char *)&length,order_bytes);\
\
  if (stream.used < length*sizeof(TYPE))\
  {\
    return false;\
  }\
\
  ARRAY_TYPE *array_ptr = (ARRAY_TYPE *)cmalloc(sizeof(ARRAY_TYPE));\
  array_ptr->init_size(length);\
\
  TYPE *e_ptr = array_ptr->data;\
  TYPE *e_ptr_end = e_ptr + length;\
  do {\
    stream.from_end(sizeof(TYPE),(char *)e_ptr,order_bytes);\
  } while(++e_ptr < e_ptr_end);\
\
  array_ptr->used = length;\
  cont = array_ptr;\
}/*}}}*/

  switch (type)
  {
  case c_bin_array_type_int32:
    BIC_BIN_ARRAY_UNPACK(bi_array_s,int);
    break;
  case c_bin_array_type_uint32:
    BIC_BIN_ARRAY_UNPACK(ui_array_s,unsigned);
    break;
  case c_bin_array_type_float:
    BIC_BIN_ARRAY_UNPACK(bf_array_s,float);
    break;
  case c_bin_array_type_double:
    BIC_BIN_ARRAY_UNPACK(bd_array_s,double);
    break;
  default:
    cassert(0);
  }

  // - create binary array object -
  bin_array_s *ba_ptr = (bin_array_s *)cmalloc(sizeof(bin_array_s));
  ba_ptr->init();

  ba_ptr->type = type;
  ba_ptr->cont = cont;

  location_ptr->v_data_ptr = (bin_array_s *)ba_ptr;

  return true;
}/*}}}*/

bool bic_bin_array_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_bin_array_operator_binary_plus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  bin_array_s *ba_ptr = (bin_array_s *)dst_location->v_data_ptr;

  // - construct container from array -
  if (src_0_location->v_type == c_bi_class_array)
  {
    switch (ba_ptr->type)
    {
    case c_bin_array_type_int32:
      BIC_BIN_ARRAY_APPEND_INTEGER_ARRAY(src_0_location,(bi_array_s *)ba_ptr->cont);
      break;
    case c_bin_array_type_uint32:
      BIC_BIN_ARRAY_APPEND_INTEGER_ARRAY(src_0_location,(ui_array_s *)ba_ptr->cont);
      break;
    case c_bin_array_type_float:
      BIC_BIN_ARRAY_APPEND_FLOAT_ARRAY(src_0_location,(bf_array_s *)ba_ptr->cont);
      break;
    case c_bin_array_type_double:
      BIC_BIN_ARRAY_APPEND_FLOAT_ARRAY(src_0_location,(bd_array_s *)ba_ptr->cont);
      break;
    default:
      cassert(0);
    }
  }

  // - construct container from iterable -
  else
  {
    switch (ba_ptr->type)
    {
    case c_bin_array_type_int32:
      BIC_BIN_ARRAY_APPEND_ITERABLE(src_0_location,(bi_array_s *)ba_ptr->cont,INTEGER);
      break;
    case c_bin_array_type_uint32:
      BIC_BIN_ARRAY_APPEND_ITERABLE(src_0_location,(ui_array_s *)ba_ptr->cont,INTEGER);
      break;
    case c_bin_array_type_float:
      BIC_BIN_ARRAY_APPEND_ITERABLE(src_0_location,(bf_array_s *)ba_ptr->cont,FLOAT);
      break;
    case c_bin_array_type_double:
      BIC_BIN_ARRAY_APPEND_ITERABLE(src_0_location,(bd_array_s *)ba_ptr->cont,FLOAT);
      break;
    default:
      cassert(0);
    }
  }

  dst_location->v_reference_cnt.atomic_inc();

  BIC_SET_RESULT(dst_location);

  return true;
}/*}}}*/

bool bic_bin_array_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_BIN_ARRAY_COMPARE(dst_location,src_0_location,operands[c_source_pos_idx]);
  result = result == 0;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_bin_array_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_BIN_ARRAY_COMPARE(dst_location,src_0_location,operands[c_source_pos_idx]);
  result = result != 0;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_bin_array_operator_binary_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  bin_array_s *ba_ptr = (bin_array_s *)dst_location->v_data_ptr;

  // - create new binary array object -
  bin_array_s *new_ba_ptr = (bin_array_s *)cmalloc(sizeof(bin_array_s));
  new_ba_ptr->init();

#define BIC_BIN_ARRAY_OPERATOR_BINARY_PLUS(ARRAY_TYPE) \
{/*{{{*/\
  ARRAY_TYPE *array_ptr = (ARRAY_TYPE *)cmalloc(sizeof(ARRAY_TYPE));\
  array_ptr->init();\
\
  /* - copy binary array content - */\
  *array_ptr = *((ARRAY_TYPE *)ba_ptr->cont);\
\
  new_ba_ptr->type = ba_ptr->type;\
  new_ba_ptr->cont = array_ptr;\
}/*}}}*/

  switch (ba_ptr->type)
  {
  case c_bin_array_type_int32:
    BIC_BIN_ARRAY_OPERATOR_BINARY_PLUS(bi_array_s);
    break;
  case c_bin_array_type_uint32:
    BIC_BIN_ARRAY_OPERATOR_BINARY_PLUS(ui_array_s);
    break;
  case c_bin_array_type_float:
    BIC_BIN_ARRAY_OPERATOR_BINARY_PLUS(bf_array_s);
    break;
  case c_bin_array_type_double:
    BIC_BIN_ARRAY_OPERATOR_BINARY_PLUS(bd_array_s);
    break;
  default:
    cassert(0);
  }

  // - create target location -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_bin_array,new_ba_ptr);
  BIC_SET_RESULT(new_location);

  // - construct container from array -
  if (src_0_location->v_type == c_bi_class_array)
  {
    switch (new_ba_ptr->type)
    {
    case c_bin_array_type_int32:
      BIC_BIN_ARRAY_APPEND_INTEGER_ARRAY(src_0_location,(bi_array_s *)new_ba_ptr->cont);
      break;
    case c_bin_array_type_uint32:
      BIC_BIN_ARRAY_APPEND_INTEGER_ARRAY(src_0_location,(ui_array_s *)new_ba_ptr->cont);
      break;
    case c_bin_array_type_float:
      BIC_BIN_ARRAY_APPEND_FLOAT_ARRAY(src_0_location,(bf_array_s *)new_ba_ptr->cont);
      break;
    case c_bin_array_type_double:
      BIC_BIN_ARRAY_APPEND_FLOAT_ARRAY(src_0_location,(bd_array_s *)new_ba_ptr->cont);
      break;
    default:
      cassert(0);
    }
  }

  // - construct container from iterable -
  else
  {
    switch (new_ba_ptr->type)
    {
    case c_bin_array_type_int32:
      BIC_BIN_ARRAY_APPEND_ITERABLE(src_0_location,(bi_array_s *)new_ba_ptr->cont,INTEGER);
      break;
    case c_bin_array_type_uint32:
      BIC_BIN_ARRAY_APPEND_ITERABLE(src_0_location,(ui_array_s *)new_ba_ptr->cont,INTEGER);
      break;
    case c_bin_array_type_float:
      BIC_BIN_ARRAY_APPEND_ITERABLE(src_0_location,(bf_array_s *)new_ba_ptr->cont,FLOAT);
      break;
    case c_bin_array_type_double:
      BIC_BIN_ARRAY_APPEND_ITERABLE(src_0_location,(bd_array_s *)new_ba_ptr->cont,FLOAT);
      break;
    default:
      cassert(0);
    }
  }

  return true;
}/*}}}*/

bool bic_bin_array_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_BIN_ARRAY_ITEM("item#1");

  return true;
}/*}}}*/

bool bic_bin_array_method_BinArray_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
type:retrieve_integer
>
method BinArray
; @end

  // - binary array container pointer -
  void *cont = nullptr;

  switch (type)
  {
  case c_bin_array_type_int32:
    {/*{{{*/
      bi_array_s *array_ptr = (bi_array_s *)cmalloc(sizeof(bi_array_s));
      array_ptr->init();

      cont = array_ptr;
    }/*}}}*/
    break;
  case c_bin_array_type_uint32:
    {/*{{{*/
      ui_array_s *array_ptr = (ui_array_s *)cmalloc(sizeof(ui_array_s));
      array_ptr->init();

      cont = array_ptr;
    }/*}}}*/
    break;
  case c_bin_array_type_float:
    {/*{{{*/
      bf_array_s *array_ptr = (bf_array_s *)cmalloc(sizeof(bf_array_s));
      array_ptr->init();

      cont = array_ptr;
    }/*}}}*/
    break;
  case c_bin_array_type_double:
    {/*{{{*/
      bd_array_s *array_ptr = (bd_array_s *)cmalloc(sizeof(bd_array_s));
      array_ptr->init();

      cont = array_ptr;
    }/*}}}*/
    break;

  // - ERROR -
  default:
    exception_s::throw_exception(it,module.error_base + c_error_BIN_ARRAY_UNKNOWN_DATA_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create binary array object -
  bin_array_s *ba_ptr = (bin_array_s *)cmalloc(sizeof(bin_array_s));
  ba_ptr->init();

  ba_ptr->type = type;
  ba_ptr->cont = cont;

  dst_location->v_data_ptr = (bin_array_s *)ba_ptr;

  return true;
}/*}}}*/

bool bic_bin_array_method_BinArray_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
type:retrieve_integer
iterable:ignore
>
method BinArray
; @end

  // - binary array container pointer -
  void *cont = nullptr;

  switch (type)
  {
  case c_bin_array_type_int32:
    {/*{{{*/
      bi_array_s *array_ptr = (bi_array_s *)cmalloc(sizeof(bi_array_s));
      array_ptr->init();

      cont = array_ptr;
    }/*}}}*/
    break;
  case c_bin_array_type_uint32:
    {/*{{{*/
      ui_array_s *array_ptr = (ui_array_s *)cmalloc(sizeof(ui_array_s));
      array_ptr->init();

      cont = array_ptr;
    }/*}}}*/
    break;
  case c_bin_array_type_float:
    {/*{{{*/
      bf_array_s *array_ptr = (bf_array_s *)cmalloc(sizeof(bf_array_s));
      array_ptr->init();

      cont = array_ptr;
    }/*}}}*/
    break;
  case c_bin_array_type_double:
    {/*{{{*/
      bd_array_s *array_ptr = (bd_array_s *)cmalloc(sizeof(bd_array_s));
      array_ptr->init();

      cont = array_ptr;
    }/*}}}*/
    break;

  // - ERROR -
  default:
    exception_s::throw_exception(it,module.error_base + c_error_BIN_ARRAY_UNKNOWN_DATA_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create binary array object -
  bin_array_s *ba_ptr = (bin_array_s *)cmalloc(sizeof(bin_array_s));
  ba_ptr->init();

  ba_ptr->type = type;
  ba_ptr->cont = cont;

  dst_location->v_data_ptr = (bin_array_s *)ba_ptr;

  // - construct container from array -
  if (src_1_location->v_type == c_bi_class_array)
  {
    switch (ba_ptr->type)
    {
    case c_bin_array_type_int32:
      BIC_BIN_ARRAY_APPEND_INTEGER_ARRAY(src_1_location,(bi_array_s *)ba_ptr->cont);
      break;
    case c_bin_array_type_uint32:
      BIC_BIN_ARRAY_APPEND_INTEGER_ARRAY(src_1_location,(ui_array_s *)ba_ptr->cont);
      break;
    case c_bin_array_type_float:
      BIC_BIN_ARRAY_APPEND_FLOAT_ARRAY(src_1_location,(bf_array_s *)ba_ptr->cont);
      break;
    case c_bin_array_type_double:
      BIC_BIN_ARRAY_APPEND_FLOAT_ARRAY(src_1_location,(bd_array_s *)ba_ptr->cont);
      break;
    default:
      cassert(0);
    }
  }

  // - construct container from iterable -
  else
  {
    switch (ba_ptr->type)
    {
    case c_bin_array_type_int32:
      BIC_BIN_ARRAY_APPEND_ITERABLE(src_1_location,(bi_array_s *)ba_ptr->cont,INTEGER);
      break;
    case c_bin_array_type_uint32:
      BIC_BIN_ARRAY_APPEND_ITERABLE(src_1_location,(ui_array_s *)ba_ptr->cont,INTEGER);
      break;
    case c_bin_array_type_float:
      BIC_BIN_ARRAY_APPEND_ITERABLE(src_1_location,(bf_array_s *)ba_ptr->cont,FLOAT);
      break;
    case c_bin_array_type_double:
      BIC_BIN_ARRAY_APPEND_ITERABLE(src_1_location,(bd_array_s *)ba_ptr->cont,FLOAT);
      break;
    default:
      cassert(0);
    }
  }

  return true;
}/*}}}*/

bool bic_bin_array_method_clear_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  bin_array_s *ba_ptr = (bin_array_s *)dst_location->v_data_ptr;

  switch (ba_ptr->type)
  {
  case c_bin_array_type_int32:
    ((bi_array_s *)ba_ptr->cont)->clear();
    break;
  case c_bin_array_type_uint32:
    ((ui_array_s *)ba_ptr->cont)->clear();
    break;
  case c_bin_array_type_float:
    ((bf_array_s *)ba_ptr->cont)->clear();
    break;
  case c_bin_array_type_double:
    ((bd_array_s *)ba_ptr->cont)->clear();
    break;
  default:
    cassert(0);
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_bin_array_method_resize_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
new_size:retrieve_integer
>
method resize
; @end

  bin_array_s *ba_ptr = (bin_array_s *)dst_location->v_data_ptr;

#define BIC_BIN_ARRAY_METHOD_RESIZE(ARRAY_TYPE,TYPE) \
{/*{{{*/\
  ARRAY_TYPE *array_ptr = (ARRAY_TYPE *)ba_ptr->cont;\
\
  /* - ERROR - */\
  if (array_ptr->used > new_size)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_BIN_ARRAY_CANNOT_RESIZE_TO_SMALLER_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(new_size);\
    new_exception->params.push(array_ptr->used);\
\
    return false;\
  }\
\
  /* - resize array - */\
  array_ptr->copy_resize(new_size);\
  memset(array_ptr->data + array_ptr->used,0,(new_size - array_ptr->used)*sizeof(TYPE));\
  array_ptr->used = new_size;\
}/*}}}*/

  switch (ba_ptr->type)
  {
  case c_bin_array_type_int32:
    {/*{{{*/
      BIC_BIN_ARRAY_METHOD_RESIZE(bi_array_s,int);
    }/*}}}*/
    break;
  case c_bin_array_type_uint32:
    {/*{{{*/
      BIC_BIN_ARRAY_METHOD_RESIZE(ui_array_s,unsigned);
    }/*}}}*/
    break;
  case c_bin_array_type_float:
    {/*{{{*/
      BIC_BIN_ARRAY_METHOD_RESIZE(bf_array_s,float);
    }/*}}}*/
    break;
  case c_bin_array_type_double:
    {/*{{{*/
      BIC_BIN_ARRAY_METHOD_RESIZE(bd_array_s,double);
    }/*}}}*/
    break;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_bin_array_method_items_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  bin_array_s *ba_ptr = (bin_array_s *)dst_location->v_data_ptr;
  pointer_array_s *target_array = it.get_new_array_ptr();

#define BIC_BIN_ARRAY_METHOD_ITEMS_INTEGER(ARR_TYPE,TYPE) \
{/*{{{*/\
  ARR_TYPE *array_ptr = (ARR_TYPE *)ba_ptr->cont;\
\
  if (array_ptr->used != 0)\
  {\
    TYPE *ptr = array_ptr->data;\
    TYPE *ptr_end = ptr + array_ptr->used;\
    do {\
      long long int value = *ptr;\
\
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);\
      target_array->push(new_location);\
\
    } while(++ptr < ptr_end);\
  }\
}/*}}}*/

#define BIC_BIN_ARRAY_METHOD_ITEMS_FLOAT(ARR_TYPE,TYPE) \
{/*{{{*/\
  ARR_TYPE *array_ptr = (ARR_TYPE *)ba_ptr->cont;\
\
  if (array_ptr->used != 0)\
  {\
    TYPE *ptr = array_ptr->data;\
    TYPE *ptr_end = ptr + array_ptr->used;\
    do {\
      double value = *ptr;\
\
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_float,value);\
      target_array->push(new_location);\
\
    } while(++ptr < ptr_end);\
  }\
}/*}}}*/

  switch (ba_ptr->type)
  {
  case c_bin_array_type_int32:
    BIC_BIN_ARRAY_METHOD_ITEMS_INTEGER(bi_array_s,int);
    break;
  case c_bin_array_type_uint32:
    BIC_BIN_ARRAY_METHOD_ITEMS_INTEGER(ui_array_s,unsigned);
    break;
  case c_bin_array_type_float:
    BIC_BIN_ARRAY_METHOD_ITEMS_FLOAT(bf_array_s,float);
    break;
  case c_bin_array_type_double:
    BIC_BIN_ARRAY_METHOD_ITEMS_FLOAT(bd_array_s,double);
    break;
  default:
    cassert(0);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,target_array);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_bin_array_method_push_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
value:ignore
>
method push
; @end

  bin_array_s *ba_ptr = (bin_array_s *)dst_location->v_data_ptr;

  switch (ba_ptr->type)
  {
  case c_bin_array_type_int32:
  case c_bin_array_type_uint32:
    {/*{{{*/
      long long int value;

      // - ERROR -
      if (!it.retrieve_integer(src_0_location,value))
      {
        exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
        BIC_EXCEPTION_PUSH_METHOD_RI("push#1");
        new_exception->params.push(1);
        new_exception->params.push(src_0_location->v_type);

        return false;
      }

      switch (ba_ptr->type)
      {
      case c_bin_array_type_int32:
        ((bi_array_s *)ba_ptr->cont)->push(value);
        break;
      case c_bin_array_type_uint32:
        ((ui_array_s *)ba_ptr->cont)->push(value);
        break;
      }
    }/*}}}*/
    break;
  case c_bin_array_type_float:
  case c_bin_array_type_double:
    {/*{{{*/
      double value;

      // - ERROR -
      if (!it.retrieve_float(src_0_location,value))
      {
        exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
        BIC_EXCEPTION_PUSH_METHOD_RI("push#1");
        new_exception->params.push(1);
        new_exception->params.push(src_0_location->v_type);

        return false;
      }

      switch (ba_ptr->type)
      {
      case c_bin_array_type_float:
        ((bf_array_s *)ba_ptr->cont)->push(value);
        break;
      case c_bin_array_type_double:
        ((bd_array_s *)ba_ptr->cont)->push(value);
        break;
      }
    }/*}}}*/
    break;
  default:
    cassert(0);
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_bin_array_method_pop_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  bin_array_s *ba_ptr = (bin_array_s *)dst_location->v_data_ptr;

#define BIC_BIN_ARRAY_METHOD_POP_INTEGER(ARRAY_TYPE) \
{/*{{{*/\
  ARRAY_TYPE *array_ptr = (ARRAY_TYPE *)ba_ptr->cont;\
\
  /* - ERROR - */\
  if (array_ptr->used == 0)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_BIN_ARRAY_NO_ELEMENTS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  long long int result = array_ptr->pop();\
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
}/*}}}*/

#define BIC_BIN_ARRAY_METHOD_POP_FLOAT(ARRAY_TYPE) \
{/*{{{*/\
  ARRAY_TYPE *array_ptr = (ARRAY_TYPE *)ba_ptr->cont;\
\
  /* - ERROR - */\
  if (array_ptr->used == 0)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_BIN_ARRAY_NO_ELEMENTS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  double result = array_ptr->pop();\
\
  BIC_SIMPLE_SET_RES(c_bi_class_float,result);\
}/*}}}*/

  switch (ba_ptr->type)
  {
  case c_bin_array_type_int32:
    BIC_BIN_ARRAY_METHOD_POP_INTEGER(bi_array_s);
    break;
  case c_bin_array_type_uint32:
    BIC_BIN_ARRAY_METHOD_POP_INTEGER(ui_array_s);
    break;
  case c_bin_array_type_float:
    BIC_BIN_ARRAY_METHOD_POP_FLOAT(bf_array_s);
    break;
  case c_bin_array_type_double:
    BIC_BIN_ARRAY_METHOD_POP_FLOAT(bd_array_s);
    break;
  default:
    cassert(0);
  }

  return true;
}/*}}}*/

bool bic_bin_array_method_last_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  bin_array_s *ba_ptr = (bin_array_s *)dst_location->v_data_ptr;

#define BIC_BIN_ARRAY_METHOD_LAST_INTEGER(ARRAY_TYPE) \
{/*{{{*/\
  ARRAY_TYPE *array_ptr = (ARRAY_TYPE *)ba_ptr->cont;\
\
  /* - ERROR - */\
  if (array_ptr->used == 0)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_BIN_ARRAY_NO_ELEMENTS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  long long int result = array_ptr->last();\
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
}/*}}}*/

#define BIC_BIN_ARRAY_METHOD_LAST_FLOAT(ARRAY_TYPE) \
{/*{{{*/\
  ARRAY_TYPE *array_ptr = (ARRAY_TYPE *)ba_ptr->cont;\
\
  /* - ERROR - */\
  if (array_ptr->used == 0)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_BIN_ARRAY_NO_ELEMENTS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  double result = array_ptr->last();\
\
  BIC_SIMPLE_SET_RES(c_bi_class_float,result);\
}/*}}}*/

  switch (ba_ptr->type)
  {
  case c_bin_array_type_int32:
    BIC_BIN_ARRAY_METHOD_LAST_INTEGER(bi_array_s);
    break;
  case c_bin_array_type_uint32:
    BIC_BIN_ARRAY_METHOD_LAST_INTEGER(ui_array_s);
    break;
  case c_bin_array_type_float:
    BIC_BIN_ARRAY_METHOD_LAST_FLOAT(bf_array_s);
    break;
  case c_bin_array_type_double:
    BIC_BIN_ARRAY_METHOD_LAST_FLOAT(bd_array_s);
    break;
  default:
    cassert(0);
  }

  return true;
}/*}}}*/

bool bic_bin_array_method_fill_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
value:ignore
>
method fill
; @end

  bin_array_s *ba_ptr = (bin_array_s *)dst_location->v_data_ptr;

  switch (ba_ptr->type)
  {
  case c_bin_array_type_int32:
  case c_bin_array_type_uint32:
    {/*{{{*/
      long long int value;

      // - ERROR -
      if (!it.retrieve_integer(src_0_location,value))
      {
        exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
        BIC_EXCEPTION_PUSH_METHOD_RI("fill#1");
        new_exception->params.push(1);
        new_exception->params.push(src_0_location->v_type);

        return false;
      }

      switch (ba_ptr->type)
      {
      case c_bin_array_type_int32:
        {/*{{{*/
          bi_array_s *array_ptr = (bi_array_s *)ba_ptr->cont;
          unsigned size = array_ptr->size;

          array_ptr->size = array_ptr->used;
          array_ptr->fill(value);
          array_ptr->size = size;
        }/*}}}*/
        break;
      case c_bin_array_type_uint32:
        {/*{{{*/
          ui_array_s *array_ptr = (ui_array_s *)ba_ptr->cont;
          unsigned size = array_ptr->size;

          array_ptr->size = array_ptr->used;
          array_ptr->fill(value);
          array_ptr->size = size;
        }/*}}}*/
        break;
      }
    }/*}}}*/
    break;
  case c_bin_array_type_float:
  case c_bin_array_type_double:
    {/*{{{*/
      double value;

      // - ERROR -
      if (!it.retrieve_float(src_0_location,value))
      {
        exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
        BIC_EXCEPTION_PUSH_METHOD_RI("fill#1");
        new_exception->params.push(1);
        new_exception->params.push(src_0_location->v_type);

        return false;
      }

      switch (ba_ptr->type)
      {
      case c_bin_array_type_float:
        {/*{{{*/
          bf_array_s *array_ptr = (bf_array_s *)ba_ptr->cont;
          unsigned size = array_ptr->size;

          array_ptr->size = array_ptr->used;
          array_ptr->fill(value);
          array_ptr->size = size;
        }/*}}}*/
        break;
      case c_bin_array_type_double:
        {/*{{{*/
          bd_array_s *array_ptr = (bd_array_s *)ba_ptr->cont;
          unsigned size = array_ptr->size;

          array_ptr->size = array_ptr->used;
          array_ptr->fill(value);
          array_ptr->size = size;
        }/*}}}*/
        break;
      }
    }/*}}}*/
    break;
  default:
    cassert(0);
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_bin_array_method_head_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
original_length:retrieve_integer
>
method head
; @end

  bin_array_s *ba_ptr = (bin_array_s *)dst_location->v_data_ptr;

  // - binary array container pointer -
  void *cont = nullptr;

#define BIC_BIN_ARRAY_METHOD_HEAD(ARRAY_TYPE) \
{/*{{{*/\
  ARRAY_TYPE *array_ptr = (ARRAY_TYPE *)ba_ptr->cont;\
\
  /* - adjust length parameter - */\
  long long int length = original_length;\
\
  if (length < 0)\
  {\
    length = array_ptr->used + length;\
  }\
\
  /* - ERROR - */\
  if (length < 0 || length > array_ptr->used)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_BIN_ARRAY_INDEX_EXCEEDS_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(original_length);\
\
    return false;\
  }\
\
  ARRAY_TYPE *new_array_ptr = (ARRAY_TYPE *)cmalloc(sizeof(ARRAY_TYPE));\
  new_array_ptr->init();\
  new_array_ptr->set(length,array_ptr->data);\
\
  cont = new_array_ptr;\
}/*}}}*/

  switch (ba_ptr->type)
  {
  case c_bin_array_type_int32:
    BIC_BIN_ARRAY_METHOD_HEAD(bi_array_s);
    break;
  case c_bin_array_type_uint32:
    BIC_BIN_ARRAY_METHOD_HEAD(ui_array_s);
    break;
  case c_bin_array_type_float:
    BIC_BIN_ARRAY_METHOD_HEAD(bf_array_s);
    break;
  case c_bin_array_type_double:
    BIC_BIN_ARRAY_METHOD_HEAD(bd_array_s);
    break;
  default:
    cassert(0);
  }

  // - create binary array object -
  bin_array_s *new_ba_ptr = (bin_array_s *)cmalloc(sizeof(bin_array_s));
  new_ba_ptr->init();

  new_ba_ptr->type = ba_ptr->type;
  new_ba_ptr->cont = cont;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_bin_array,new_ba_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_bin_array_method_tail_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
original_length:retrieve_integer
>
method tail
; @end

  bin_array_s *ba_ptr = (bin_array_s *)dst_location->v_data_ptr;

  // - binary array container pointer -
  void *cont = nullptr;

#define BIC_BIN_ARRAY_METHOD_TAIL(ARRAY_TYPE) \
{/*{{{*/\
  ARRAY_TYPE *array_ptr = (ARRAY_TYPE *)ba_ptr->cont;\
\
  /* - adjust length parameter - */\
  long long int length = original_length;\
\
  if (length < 0)\
  {\
    length = array_ptr->used + length;\
  }\
\
  /* - ERROR - */\
  if (length < 0 || length > array_ptr->used)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_BIN_ARRAY_INDEX_EXCEEDS_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(original_length);\
\
    return false;\
  }\
\
  ARRAY_TYPE *new_array_ptr = (ARRAY_TYPE *)cmalloc(sizeof(ARRAY_TYPE));\
  new_array_ptr->init();\
  new_array_ptr->set(length,array_ptr->data + (array_ptr->used - length));\
\
  cont = new_array_ptr;\
}/*}}}*/

  switch (ba_ptr->type)
  {
  case c_bin_array_type_int32:
    BIC_BIN_ARRAY_METHOD_TAIL(bi_array_s);
    break;
  case c_bin_array_type_uint32:
    BIC_BIN_ARRAY_METHOD_TAIL(ui_array_s);
    break;
  case c_bin_array_type_float:
    BIC_BIN_ARRAY_METHOD_TAIL(bf_array_s);
    break;
  case c_bin_array_type_double:
    BIC_BIN_ARRAY_METHOD_TAIL(bd_array_s);
    break;
  default:
    cassert(0);
  }

  // - create binary array object -
  bin_array_s *new_ba_ptr = (bin_array_s *)cmalloc(sizeof(bin_array_s));
  new_ba_ptr->init();

  new_ba_ptr->type = ba_ptr->type;
  new_ba_ptr->cont = cont;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_bin_array,new_ba_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_bin_array_method_range_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
original_first_index:retrieve_integer
original_second_index:retrieve_integer
>
method range
; @end

  bin_array_s *ba_ptr = (bin_array_s *)dst_location->v_data_ptr;

  // - binary array container pointer -
  void *cont = nullptr;

#define BIC_BIN_ARRAY_METHOD_RANGE(ARRAY_TYPE) \
{/*{{{*/\
  ARRAY_TYPE *array_ptr = (ARRAY_TYPE *)ba_ptr->cont;\
\
  /* - adjust first_index parameter - */\
  long long int first_index = original_first_index;\
  if (first_index < 0)\
  {\
    first_index = array_ptr->used + first_index;\
  }\
\
  /* - adjust second_index parameter - */\
  long long int second_index = original_second_index;\
  if (second_index < 0)\
  {\
    second_index = array_ptr->used + second_index;\
  }\
\
  /* - ERROR - */\
  if (first_index > second_index ||\
      first_index < 0 || first_index >= array_ptr->used ||\
      second_index < 0 || second_index >= array_ptr->used)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_BIN_ARRAY_WRONG_RANGE_INDEXES,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(original_first_index);\
    new_exception->params.push(original_second_index);\
\
    return false;\
  }\
\
  ARRAY_TYPE *new_array_ptr = (ARRAY_TYPE *)cmalloc(sizeof(ARRAY_TYPE));\
  new_array_ptr->init();\
  new_array_ptr->set(second_index - first_index + 1,array_ptr->data + first_index);\
\
  cont = new_array_ptr;\
}/*}}}*/

  switch (ba_ptr->type)
  {
  case c_bin_array_type_int32:
    BIC_BIN_ARRAY_METHOD_RANGE(bi_array_s);
    break;
  case c_bin_array_type_uint32:
    BIC_BIN_ARRAY_METHOD_RANGE(ui_array_s);
    break;
  case c_bin_array_type_float:
    BIC_BIN_ARRAY_METHOD_RANGE(bf_array_s);
    break;
  case c_bin_array_type_double:
    BIC_BIN_ARRAY_METHOD_RANGE(bd_array_s);
    break;
  default:
    cassert(0);
  }

  // - create binary array object -
  bin_array_s *new_ba_ptr = (bin_array_s *)cmalloc(sizeof(bin_array_s));
  new_ba_ptr->init();

  new_ba_ptr->type = ba_ptr->type;
  new_ba_ptr->cont = cont;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_bin_array,new_ba_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_bin_array_method_get_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
valiue:ignore
>
method get_idx
; @end

  bin_array_s *ba_ptr = (bin_array_s *)dst_location->v_data_ptr;

  long long int index;

  switch (ba_ptr->type)
  {
  case c_bin_array_type_int32:
  case c_bin_array_type_uint32:
    {/*{{{*/
      long long int value;

      // - ERROR -
      if (!it.retrieve_integer(src_0_location,value))
      {
        exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
        BIC_EXCEPTION_PUSH_METHOD_RI("get_idx#1");
        new_exception->params.push(1);
        new_exception->params.push(src_0_location->v_type);

        return false;
      }

      switch (ba_ptr->type)
      {
      case c_bin_array_type_int32:
        index = ((bi_array_s *)ba_ptr->cont)->get_idx(value);
        break;
      case c_bin_array_type_uint32:
        index = ((ui_array_s *)ba_ptr->cont)->get_idx(value);
        break;
      }
    }/*}}}*/
    break;
  case c_bin_array_type_float:
  case c_bin_array_type_double:
    {/*{{{*/
      double value;

      // - ERROR -
      if (!it.retrieve_float(src_0_location,value))
      {
        exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
        BIC_EXCEPTION_PUSH_METHOD_RI("get_idx#1");
        new_exception->params.push(1);
        new_exception->params.push(src_0_location->v_type);

        return false;
      }

      switch (ba_ptr->type)
      {
      case c_bin_array_type_float:
        index = ((bf_array_s *)ba_ptr->cont)->get_idx(value);
        break;
      case c_bin_array_type_double:
        index = ((bd_array_s *)ba_ptr->cont)->get_idx(value);
        break;
      }
    }/*}}}*/
    break;
  default:
    cassert(0);
  }

  BIC_SET_RESULT_CONT_INDEX(index);

  return true;
}/*}}}*/

bool bic_bin_array_method_get_idxs_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
value:ignore
>
method get_idxs
; @end

  bin_array_s *ba_ptr = (bin_array_s *)dst_location->v_data_ptr;

  ui_array_s idxs_array;
  idxs_array.init();

#define BIC_BIN_ARRAY_METHOD_GET_IDXS(ARRAY_TYPE,TYPE) \
{/*{{{*/\
  ARRAY_TYPE *array_ptr = (ARRAY_TYPE *)ba_ptr->cont;\
\
  if (array_ptr->used != 0)\
  {\
    TYPE *ptr = array_ptr->data;\
    TYPE *ptr_end = ptr + array_ptr->used;\
    do {\
      if (*ptr == value)\
      {\
        idxs_array.push(ptr - array_ptr->data);\
      }\
    } while(++ptr < ptr_end);\
  }\
}/*}}}*/

  switch (ba_ptr->type)
  {
  case c_bin_array_type_int32:
  case c_bin_array_type_uint32:
    {/*{{{*/
      long long int value;

      // - ERROR -
      if (!it.retrieve_integer(src_0_location,value))
      {
        idxs_array.clear();

        exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
        BIC_EXCEPTION_PUSH_METHOD_RI("get_idxs#1");
        new_exception->params.push(1);
        new_exception->params.push(src_0_location->v_type);

        return false;
      }

      switch (ba_ptr->type)
      {
      case c_bin_array_type_int32:
        BIC_BIN_ARRAY_METHOD_GET_IDXS(bi_array_s,int);
        break;
      case c_bin_array_type_uint32:
        BIC_BIN_ARRAY_METHOD_GET_IDXS(ui_array_s,unsigned);
        break;
      }
    }/*}}}*/
    break;
  case c_bin_array_type_float:
  case c_bin_array_type_double:
    {/*{{{*/
      double value;

      // - ERROR -
      if (!it.retrieve_float(src_0_location,value))
      {
        idxs_array.clear();

        exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
        BIC_EXCEPTION_PUSH_METHOD_RI("get_idxs#1");
        new_exception->params.push(1);
        new_exception->params.push(src_0_location->v_type);

        return false;
      }

      switch (ba_ptr->type)
      {
      case c_bin_array_type_float:
        BIC_BIN_ARRAY_METHOD_GET_IDXS(bf_array_s,float);
        break;
      case c_bin_array_type_double:
        BIC_BIN_ARRAY_METHOD_GET_IDXS(bd_array_s,double);
        break;
      }
    }/*}}}*/
    break;
  default:
    cassert(0);
  }

  // - construct array from temporary array of indexes -
  pointer_array_s *res_array_ptr = it.get_new_array_ptr();

  BIC_CONT_CONSTRUCT_IDXS_ARRAY();

  idxs_array.clear();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,res_array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_bin_array_method_contain_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
value:ignore
>
method contain
; @end

  bin_array_s *ba_ptr = (bin_array_s *)dst_location->v_data_ptr;

  long long int found = 0;

  switch (ba_ptr->type)
  {
  case c_bin_array_type_int32:
  case c_bin_array_type_uint32:
    {/*{{{*/
      long long int value;

      // - ERROR -
      if (!it.retrieve_integer(src_0_location,value))
      {
        exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
        BIC_EXCEPTION_PUSH_METHOD_RI("contain#1");
        new_exception->params.push(1);
        new_exception->params.push(src_0_location->v_type);

        return false;
      }

      switch (ba_ptr->type)
      {
      case c_bin_array_type_int32:
        found = ((bi_array_s *)ba_ptr->cont)->get_idx(value) != c_idx_not_exist;
        break;
      case c_bin_array_type_uint32:
        found = ((ui_array_s *)ba_ptr->cont)->get_idx(value) != c_idx_not_exist;
        break;
      }
    }/*}}}*/
    break;
  case c_bin_array_type_float:
  case c_bin_array_type_double:
    {/*{{{*/
      double value;

      // - ERROR -
      if (!it.retrieve_float(src_0_location,value))
      {
        exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
        BIC_EXCEPTION_PUSH_METHOD_RI("contain#1");
        new_exception->params.push(1);
        new_exception->params.push(src_0_location->v_type);

        return false;
      }

      switch (ba_ptr->type)
      {
      case c_bin_array_type_float:
        found = ((bf_array_s *)ba_ptr->cont)->get_idx(value) != c_idx_not_exist;
        break;
      case c_bin_array_type_double:
        found = ((bd_array_s *)ba_ptr->cont)->get_idx(value) != c_idx_not_exist;
        break;
      }
    }/*}}}*/
    break;
  default:
    cassert(0);
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,found);

  return true;
}/*}}}*/

bool bic_bin_array_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_BIN_ARRAY_COMPARE(dst_location,src_0_location,operands[c_source_pos_idx]);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_bin_array_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_BIN_ARRAY_ITEM("item#1");

  return true;
}/*}}}*/

bool bic_bin_array_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  BIC_BIN_ARRAY_GET_USED(dst_location);

  if (used > 0)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,0);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_bin_array_method_last_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  BIC_BIN_ARRAY_GET_USED(dst_location);

  if (used > 0)
  {
    long long int result = used - 1;

    BIC_SIMPLE_SET_RES(c_bi_class_integer,result);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_bin_array_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
index:retrieve_integer
>
method next_idx
; @end

  BIC_BIN_ARRAY_CHECK_INDEX();

  if (++index < used)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,index);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_bin_array_method_prev_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
index:retrieve_integer
>
method prev_idx
; @end

  BIC_BIN_ARRAY_CHECK_INDEX();

  if (index >= 1)
  {
    long long int result = index - 1;

    BIC_SIMPLE_SET_RES(c_bi_class_integer,result);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_bin_array_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  bin_array_s *ba_ptr = (bin_array_s *)dst_location->v_data_ptr;
  long long int result;

  switch (ba_ptr->type)
  {
  case c_bin_array_type_int32:
    result = ((bi_array_s *)ba_ptr->cont)->used;
    break;
  case c_bin_array_type_uint32:
    result = ((ui_array_s *)ba_ptr->cont)->used;
    break;
  case c_bin_array_type_float:
    result = ((bf_array_s *)ba_ptr->cont)->used;
    break;
  case c_bin_array_type_double:
    result = ((bd_array_s *)ba_ptr->cont)->used;
    break;
  default:
    cassert(0);
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_bin_array_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  bin_array_s *ba_ptr = (bin_array_s *)dst_location->v_data_ptr;

  string_array_s strings;
  strings.init();

  unsigned strings_size = 0;

#define BIC_BIN_ARRAY_METHOD_TO_STRING(ARRAY_TYPE,TYPE,FORMAT) \
{/*{{{*/\
  ARRAY_TYPE *array_ptr = (ARRAY_TYPE *)ba_ptr->cont;\
\
  strings.copy_resize(array_ptr->used);\
  strings.used = strings.size;\
\
  if (array_ptr->used != 0)\
  {\
    TYPE *e_ptr = array_ptr->data;\
    TYPE *e_ptr_end = e_ptr + array_ptr->used;\
    string_s *s_ptr = strings.data;\
\
    do {\
      s_ptr->setf(FORMAT,*e_ptr);\
      strings_size += s_ptr->size - 1;\
    }\
    while(++s_ptr,++e_ptr < e_ptr_end);\
  }\
}/*}}}*/

  switch (ba_ptr->type)
  {
  case c_bin_array_type_int32:
    BIC_BIN_ARRAY_METHOD_TO_STRING(bi_array_s,int,"%d")
    break;
  case c_bin_array_type_uint32:
    BIC_BIN_ARRAY_METHOD_TO_STRING(ui_array_s,unsigned,"%u")
    break;
  case c_bin_array_type_float:
    BIC_BIN_ARRAY_METHOD_TO_STRING(bf_array_s,float,"%f")
    break;
  case c_bin_array_type_double:
    BIC_BIN_ARRAY_METHOD_TO_STRING(bd_array_s,double,"%f")
    break;
  default:
    cassert(0);
  }

  string_s *string_ptr = it.get_new_string_ptr();

  BIC_CONT_TO_STRING_0_CONSTRUCT();

  // - release string array -
  strings.clear();

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_bin_array_method_to_string_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
delimiter:c_bi_class_string
>
method to_string
; @end

  bin_array_s *ba_ptr = (bin_array_s *)dst_location->v_data_ptr;
  string_s *del_string_ptr = (string_s *)src_0_location->v_data_ptr;

  string_array_s strings;
  strings.init();

  unsigned strings_size = 0;

  switch (ba_ptr->type)
  {
  case c_bin_array_type_int32:
    BIC_BIN_ARRAY_METHOD_TO_STRING(bi_array_s,int,"%d")
    break;
  case c_bin_array_type_uint32:
    BIC_BIN_ARRAY_METHOD_TO_STRING(ui_array_s,unsigned,"%u")
    break;
  case c_bin_array_type_float:
    BIC_BIN_ARRAY_METHOD_TO_STRING(bf_array_s,float,"%f")
    break;
  case c_bin_array_type_double:
    BIC_BIN_ARRAY_METHOD_TO_STRING(bd_array_s,double,"%f")
    break;
  default:
    cassert(0);
  }

  string_s *string_ptr = it.get_new_string_ptr();

  BIC_CONT_TO_STRING_1_CONSTRUCT();

  // - release string array -
  strings.clear();

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_bin_array_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  bin_array_s *ba_ptr = (bin_array_s *)dst_location->v_data_ptr;

  putchar('[');

#define BIC_BIN_ARRAY_METHOD_PRINT(ARRAY_TYPE,TYPE,FORMAT) \
{/*{{{*/\
  ARRAY_TYPE *array_ptr = (ARRAY_TYPE *)ba_ptr->cont;\
\
  if (array_ptr->used != 0)\
  {\
    TYPE *e_ptr = array_ptr->data;\
    TYPE *e_ptr_end = e_ptr + array_ptr->used;\
\
    do {\
      printf(FORMAT,*e_ptr);\
      if (++e_ptr >= e_ptr_end) break;\
      putchar(',');\
    }\
    while(true);\
  }\
}/*}}}*/

  switch (ba_ptr->type)
  {
  case c_bin_array_type_int32:
    BIC_BIN_ARRAY_METHOD_PRINT(bi_array_s,int,"%d")
    break;
  case c_bin_array_type_uint32:
    BIC_BIN_ARRAY_METHOD_PRINT(ui_array_s,unsigned,"%u")
    break;
  case c_bin_array_type_float:
    BIC_BIN_ARRAY_METHOD_PRINT(bf_array_s,float,"%f")
    break;
  case c_bin_array_type_double:
    BIC_BIN_ARRAY_METHOD_PRINT(bd_array_s,double,"%f")
    break;
  default:
    cassert(0);
  }

  putchar(']');

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

// - class BIN_ARRAY_REF -
built_in_class_s bin_array_ref_class =
{/*{{{*/
  "BinArrayRef",
  c_modifier_public | c_modifier_final,
  4, bin_array_ref_methods,
  0, bin_array_ref_variables,
  bic_bin_array_ref_consts,
  bic_bin_array_ref_init,
  bic_bin_array_ref_clear,
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

built_in_method_s bin_array_ref_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_bin_array_ref_operator_binary_equal
  },
  {
    "value#0",
    c_modifier_public | c_modifier_final,
    bic_bin_array_ref_method_value_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_bin_array_ref_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_bin_array_ref_method_print_0
  },
};/*}}}*/

built_in_variable_s bin_array_ref_variables[] =
{/*{{{*/
};/*}}}*/

void bic_bin_array_ref_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_bin_array_ref_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (bin_array_ref_s *)nullptr;
}/*}}}*/

void bic_bin_array_ref_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  bin_array_ref_s *bar_ptr = (bin_array_ref_s *)location_ptr->v_data_ptr;

  if (bar_ptr != nullptr)
  {
    ((bin_array_s *)bar_ptr->ba_location->v_data_ptr)->release_reference(it,bar_ptr);
  }
}/*}}}*/

bool bic_bin_array_ref_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
value:ignore
>
method operator_binary_equal
; @end

  bin_array_ref_s *bar_ptr = (bin_array_ref_s *)dst_location->v_data_ptr;
  bin_array_s *ba_ptr = (bin_array_s *)bar_ptr->ba_location->v_data_ptr;

#define BIC_BIN_ARRAY_REF_OPERATOR_BINARY_EQUAL(ARR_TYPE,TYPE) \
{/*{{{*/\
  ARR_TYPE *array_ptr = (ARR_TYPE *)ba_ptr->cont;\
\
  /* - ERROR - */\
  if (bar_ptr->index >= array_ptr->used)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_BIN_ARRAY_REF_INVALID_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  TYPE &value_ref = array_ptr->data[bar_ptr->index];\
  value_ref = value;\
  value = value_ref;\
}/*}}}*/

  switch (ba_ptr->type)
  {
  case c_bin_array_type_int32:
  case c_bin_array_type_uint32:
    {/*{{{*/
      long long int value;

      // - ERROR -
      if (!it.retrieve_integer(src_0_location,value))
      {
        exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
        BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_equal#1");
        new_exception->params.push(1);
        new_exception->params.push(src_0_location->v_type);

        return false;
      }

      switch (ba_ptr->type)
      {
      case c_bin_array_type_int32:
        BIC_BIN_ARRAY_REF_OPERATOR_BINARY_EQUAL(bi_array_s,int);
        break;
      case c_bin_array_type_uint32:
        BIC_BIN_ARRAY_REF_OPERATOR_BINARY_EQUAL(ui_array_s,unsigned);
        break;
      }

      BIC_SIMPLE_SET_RES(c_bi_class_integer,value);
    }/*}}}*/
    break;
  case c_bin_array_type_float:
  case c_bin_array_type_double:
    {/*{{{*/
      double value;

      // - ERROR -
      if (!it.retrieve_float(src_0_location,value))
      {
        exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
        BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_equal#1");
        new_exception->params.push(1);
        new_exception->params.push(src_0_location->v_type);

        return false;
      }

      switch (ba_ptr->type)
      {
      case c_bin_array_type_float:
        BIC_BIN_ARRAY_REF_OPERATOR_BINARY_EQUAL(bf_array_s,float);
        break;
      case c_bin_array_type_double:
        BIC_BIN_ARRAY_REF_OPERATOR_BINARY_EQUAL(bd_array_s,double);
        break;
      }

      BIC_SIMPLE_SET_RES(c_bi_class_float,value);
    }/*}}}*/
    break;
  default:
    cassert(0);
  }

  return true;
}/*}}}*/

bool bic_bin_array_ref_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  bin_array_ref_s *bar_ptr = (bin_array_ref_s *)dst_location->v_data_ptr;
  bin_array_s *ba_ptr = (bin_array_s *)bar_ptr->ba_location->v_data_ptr;

#define BIC_BIN_ARRAY_REF_METHOD_VALUE_INTEGER(ARR_TYPE) \
{/*{{{*/\
  ARR_TYPE *array_ptr = (ARR_TYPE *)ba_ptr->cont;\
\
  /* - ERROR - */\
  if (bar_ptr->index >= array_ptr->used)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_BIN_ARRAY_REF_INVALID_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  long long int result = array_ptr->data[bar_ptr->index];\
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
}/*}}}*/

#define BIC_BIN_ARRAY_REF_METHOD_VALUE_FLOAT(ARR_TYPE) \
{/*{{{*/\
  ARR_TYPE *array_ptr = (ARR_TYPE *)ba_ptr->cont;\
\
  /* - ERROR - */\
  if (bar_ptr->index >= array_ptr->used)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_BIN_ARRAY_REF_INVALID_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  double result = array_ptr->data[bar_ptr->index];\
\
  BIC_SIMPLE_SET_RES(c_bi_class_float,result);\
}/*}}}*/

  switch (ba_ptr->type)
  {
  case c_bin_array_type_int32:
    BIC_BIN_ARRAY_REF_METHOD_VALUE_INTEGER(bi_array_s);
    break;
  case c_bin_array_type_uint32:
    BIC_BIN_ARRAY_REF_METHOD_VALUE_INTEGER(ui_array_s);
    break;
  case c_bin_array_type_float:
    BIC_BIN_ARRAY_REF_METHOD_VALUE_FLOAT(bf_array_s);
    break;
  case c_bin_array_type_double:
    BIC_BIN_ARRAY_REF_METHOD_VALUE_FLOAT(bd_array_s);
    break;
  default:
    cassert(0);
  }

  return true;
}/*}}}*/

bool bic_bin_array_ref_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("BinArrayRef"),"BinArrayRef")
  );

  return true;
}/*}}}*/

bool bic_bin_array_ref_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("BinArrayRef");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class BIN_DICT -
built_in_class_s bin_dict_class =
{/*{{{*/
  "BinDict",
  c_modifier_public | c_modifier_final,
  24, bin_dict_methods,
  2, bin_dict_variables,
  bic_bin_dict_consts,
  bic_bin_dict_init,
  bic_bin_dict_clear,
  nullptr,
  bic_bin_dict_length,
  bic_bin_dict_item,
  bic_bin_dict_first_idx,
  bic_bin_dict_next_idx,
  nullptr,
  nullptr,
  bic_bin_dict_pack,
  bic_bin_dict_unpack,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s bin_dict_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_bin_dict_operator_binary_equal
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_bin_dict_operator_binary_le_br_re_br
  },
  {
    "BinDict#1",
    c_modifier_public | c_modifier_final,
    bic_bin_dict_method_BinDict_1
  },
  {
    "clear#0",
    c_modifier_public | c_modifier_final,
    bic_bin_dict_method_clear_0
  },
  {
    "keys#0",
    c_modifier_public | c_modifier_final,
    bic_bin_dict_method_keys_0
  },
  {
    "items#0",
    c_modifier_public | c_modifier_final,
    bic_bin_dict_method_items_0
  },
  {
    "has_key#1",
    c_modifier_public | c_modifier_final,
    bic_bin_dict_method_has_key_1
  },
  {
    "remove_key#1",
    c_modifier_public | c_modifier_final,
    bic_bin_dict_method_remove_key_1
  },
  {
    "first_key#0",
    c_modifier_public | c_modifier_final,
    bic_bin_dict_method_first_key_0
  },
  {
    "last_key#0",
    c_modifier_public | c_modifier_final,
    bic_bin_dict_method_last_key_0
  },
  {
    "next_key#1",
    c_modifier_public | c_modifier_final,
    bic_bin_dict_method_next_key_1
  },
  {
    "prev_key#1",
    c_modifier_public | c_modifier_final,
    bic_bin_dict_method_prev_key_1
  },
  {
    "lee_key#1",
    c_modifier_public | c_modifier_final,
    bic_bin_dict_method_lee_key_1
  },
  {
    "gre_key#1",
    c_modifier_public | c_modifier_final,
    bic_bin_dict_method_gre_key_1
  },
  {
    "compare#1",
    c_modifier_public | c_modifier_final,
    bic_bin_dict_method_compare_1
  },
  {
    "item#1",
    c_modifier_public | c_modifier_final,
    bic_bin_dict_method_item_1
  },
  {
    "first_idx#0",
    c_modifier_public | c_modifier_final,
    bic_bin_dict_method_first_idx_0
  },
  {
    "last_idx#0",
    c_modifier_public | c_modifier_final,
    bic_bin_dict_method_last_idx_0
  },
  {
    "next_idx#1",
    c_modifier_public | c_modifier_final,
    bic_bin_dict_method_next_idx_1
  },
  {
    "prev_idx#1",
    c_modifier_public | c_modifier_final,
    bic_bin_dict_method_prev_idx_1
  },
  {
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_bin_dict_method_length_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_bin_dict_method_to_string_0
  },
  {
    "to_string#1",
    c_modifier_public | c_modifier_final,
    bic_bin_dict_method_to_string_1
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_bin_dict_method_print_0
  },
};/*}}}*/

built_in_variable_s bin_dict_variables[] =
{/*{{{*/

  // - insert binary array type constants -
  { "TYPE_INT64_INT64", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_INT64_FLOAT64", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

#define BIC_BIN_DICT_CHECK_IDX(MAP_NAME) \
/*{{{*/\
  MAP_NAME ## _tree_s *tree_ptr = (MAP_NAME ## _tree_s *)bd_ptr->cont;\
\
  /* - ERROR - */\
  if (index < 0 || index >= tree_ptr->used || !tree_ptr->data[index].valid)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_BIN_DICT_INDEX_DOES_NOT_REFER_TO_VALID_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(index);\
\
    return false;\
  }\
/*}}}*/

#define BIC_BIN_DICT_COMPARE_ELEMENTS(MAP_NAME) \
{/*{{{*/\
  MAP_NAME ## _tree_s *f_tree_ptr = (MAP_NAME ## _tree_s *)f_bd_ptr->cont;\
  MAP_NAME ## _tree_s *s_tree_ptr = (MAP_NAME ## _tree_s *)s_bd_ptr->cont;\
\
  if (f_tree_ptr->count != s_tree_ptr->count)\
  {\
    result = f_tree_ptr->count < s_tree_ptr->count ? -1 : 1;\
  }\
  else {\
    result = 0;\
\
    if (f_tree_ptr->count != 0)\
    {\
      unsigned f_stack[f_tree_ptr->get_descent_stack_size()];\
      unsigned s_stack[s_tree_ptr->get_descent_stack_size()];\
\
      unsigned *f_stack_ptr = f_stack;\
      unsigned *s_stack_ptr = s_stack;\
\
      unsigned ft_idx = f_tree_ptr->get_stack_min_value_idx(f_tree_ptr->root_idx,&f_stack_ptr);\
      unsigned st_idx = s_tree_ptr->get_stack_min_value_idx(s_tree_ptr->root_idx,&s_stack_ptr);\
\
      do {\
        MAP_NAME ## _s &f_map = f_tree_ptr->data[ft_idx].object;\
        MAP_NAME ## _s &s_map = s_tree_ptr->data[st_idx].object;\
\
        if (f_map.key != s_map.key)\
        {\
          result = f_map.key < s_map.key ? -1 : 1;\
          break;\
        }\
\
        if (f_map.value != s_map.value)\
        {\
          result = f_map.value < s_map.value ? -1 : 1;\
          break;\
        }\
\
        ft_idx = f_tree_ptr->get_stack_next_idx(ft_idx,&f_stack_ptr,f_stack);\
        st_idx = s_tree_ptr->get_stack_next_idx(st_idx,&s_stack_ptr,s_stack);\
      } while(ft_idx != c_idx_not_exist);\
    }\
  }\
}/*}}}*/

#define BIC_BIN_DICT_COMPARE(FIRST_LOC_PTR,SECOND_LOC_PTR,SOURCE_POS) \
{/*{{{*/\
  if ((SECOND_LOC_PTR)->v_type == c_bi_class_bin_dict)\
  {\
    bin_dict_s *f_bd_ptr = (bin_dict_s *)(FIRST_LOC_PTR)->v_data_ptr;\
    bin_dict_s *s_bd_ptr = (bin_dict_s *)(SECOND_LOC_PTR)->v_data_ptr;\
\
    if (f_bd_ptr->type == s_bd_ptr->type)\
    {\
      switch (f_bd_ptr->type)\
      {\
      case c_bin_dict_type_int64_int64:\
        BIC_BIN_DICT_COMPARE_ELEMENTS(lli_lli_map);\
        break;\
      case c_bin_dict_type_int64_float64:\
        BIC_BIN_DICT_COMPARE_ELEMENTS(lli_bd_map);\
        break;\
      default:\
        cassert(0);\
      }\
    }\
    else\
    {\
      result = f_bd_ptr->type < s_bd_ptr->type ? -1 : 1;\
    }\
  }\
  else\
  {\
    result = c_bi_class_bin_dict < (SECOND_LOC_PTR)->v_type ? -1 : 1;\
  }\
}/*}}}*/

void bic_bin_dict_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert binary array type constants -
  {
    const_locations.push_blanks(2);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 2);

#define CREATE_BIN_DICT_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_BIN_DICT_TYPE_BIC_STATIC(c_bin_dict_type_int64_int64);
    CREATE_BIN_DICT_TYPE_BIC_STATIC(c_bin_dict_type_int64_float64);
  }

}/*}}}*/

void bic_bin_dict_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (bin_dict_s *)nullptr;
}/*}}}*/

void bic_bin_dict_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  bin_dict_s *bd_ptr = (bin_dict_s *)location_ptr->v_data_ptr;

  if (bd_ptr != nullptr)
  {
    bd_ptr->clear(it);
    cfree(bd_ptr);
  }
}/*}}}*/

unsigned bic_bin_dict_length(location_s *location_ptr)
{/*{{{*/
  bin_dict_s *bd_ptr = (bin_dict_s *)location_ptr->v_data_ptr;

  switch (bd_ptr->type)
  {
  case c_bin_dict_type_int64_int64:
    return ((lli_lli_map_tree_s *)bd_ptr->cont)->count;
  case c_bin_dict_type_int64_float64:
    return ((lli_bd_map_tree_s *)bd_ptr->cont)->count;
  default:
    cassert(0);
  }
}/*}}}*/

location_s *bic_bin_dict_item(interpreter_thread_s &it,location_s *location_ptr,unsigned index)
{/*{{{*/
  bin_dict_s *bd_ptr = (bin_dict_s *)location_ptr->v_data_ptr;

#define BIC_BIN_DICT_ITEM(MAP_NAME) \
{/*{{{*/\
  MAP_NAME ## _tree_s *tree_ptr = (MAP_NAME ## _tree_s *)bd_ptr->cont;\
\
  /* - ERROR - */\
  cassert(index < tree_ptr->used && tree_ptr->data[index].valid);\
}/*}}}*/

  switch (bd_ptr->type)
  {
  case c_bin_dict_type_int64_int64:
    BIC_BIN_DICT_ITEM(lli_lli_map);
    break;
  case c_bin_dict_type_int64_float64:
    BIC_BIN_DICT_ITEM(lli_bd_map);
    break;
  default:
    cassert(0);
  }

  // - create bin dict reference -
  bin_dict_ref_s *bdr_ptr = bd_ptr->create_reference(location_ptr,index);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_bin_dict_ref,bdr_ptr);

  return new_location;
}/*}}}*/

unsigned bic_bin_dict_first_idx(location_s *location_ptr)
{/*{{{*/
  bin_dict_s *bd_ptr = (bin_dict_s *)location_ptr->v_data_ptr;

#define BIC_BIN_DICT_FIRST_IDX(MAP_NAME) \
{/*{{{*/\
  MAP_NAME ## _tree_s *tree_ptr = (MAP_NAME ## _tree_s *)bd_ptr->cont;\
\
  if (tree_ptr->root_idx != c_idx_not_exist)\
  {\
    return tree_ptr->get_min_value_idx(tree_ptr->root_idx);\
  }\
\
  return c_idx_not_exist;\
}/*}}}*/

  switch (bd_ptr->type)
  {
  case c_bin_dict_type_int64_int64:
    BIC_BIN_DICT_FIRST_IDX(lli_lli_map);
    break;
  case c_bin_dict_type_int64_float64:
    BIC_BIN_DICT_FIRST_IDX(lli_bd_map);
    break;
  default:
    cassert(0);
  }
}/*}}}*/

unsigned bic_bin_dict_next_idx(location_s *location_ptr,unsigned index)
{/*{{{*/
  bin_dict_s *bd_ptr = (bin_dict_s *)location_ptr->v_data_ptr;

#define BIC_BIN_DICT_NEXT_IDX(MAP_NAME) \
{/*{{{*/\
  MAP_NAME ## _tree_s *tree_ptr = (MAP_NAME ## _tree_s *)bd_ptr->cont;\
\
  /* - ERROR - */\
  cassert(index < tree_ptr->used && tree_ptr->data[index].valid);\
\
  return tree_ptr->get_next_idx(index);\
}/*}}}*/

  switch (bd_ptr->type)
  {
  case c_bin_dict_type_int64_int64:
    BIC_BIN_DICT_NEXT_IDX(lli_lli_map);
    break;
  case c_bin_dict_type_int64_float64:
    BIC_BIN_DICT_NEXT_IDX(lli_bd_map);
    break;
  default:
    cassert(0);
  }
}/*}}}*/

bool bic_bin_dict_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack)
{/*{{{*/
  bin_dict_s *bd_ptr = (bin_dict_s *)location_ptr->v_data_ptr;

#define BIC_BIN_DICT_PACK(MAP_NAME,KEY_TYPE,VALUE_TYPE) \
{/*{{{*/\
  MAP_NAME ## _tree_s *tree_ptr = (MAP_NAME ## _tree_s *)bd_ptr->cont;\
\
  if (tree_ptr->root_idx != c_idx_not_exist)\
  {\
    unsigned stack[tree_ptr->get_descent_stack_size()];\
    unsigned *stack_ptr = stack;\
\
    unsigned kv_idx = tree_ptr->get_stack_min_value_idx(tree_ptr->root_idx,&stack_ptr);\
    do {\
      MAP_NAME ## _s &key_value = tree_ptr->data[kv_idx].object;\
\
      stream.append(sizeof(KEY_TYPE),(const char *)&key_value.key);\
      stream.append(sizeof(VALUE_TYPE),(const char *)&key_value.value);\
\
      kv_idx = tree_ptr->get_stack_next_idx(kv_idx,&stack_ptr,stack);\
    } while(kv_idx != c_idx_not_exist);\
  }\
\
  stream.append(sizeof(unsigned),(const char *)&tree_ptr->count);\
}/*}}}*/

  switch (bd_ptr->type)
  {
  case c_bin_dict_type_int64_int64:
    BIC_BIN_DICT_PACK(lli_lli_map,long long int,long long int);
    break;
  case c_bin_dict_type_int64_float64:
    BIC_BIN_DICT_PACK(lli_bd_map,long long int,double);
    break;
  default:
    cassert(0);
  }

  stream.append(sizeof(unsigned),(const char *)&bd_ptr->type);

  return true;
}/*}}}*/

bool bic_bin_dict_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos)
{/*{{{*/
  if (stream.used < sizeof(unsigned))
  {
    return false;
  }

  unsigned type;
  stream.from_end(sizeof(unsigned),(char *)&type,order_bytes);

  // - binary array container pointer -
  void *cont = nullptr;

#define BIC_BIN_DICT_UNPACK(MAP_NAME,KEY_TYPE,VALUE_TYPE) \
{/*{{{*/\
  if (stream.used < sizeof(unsigned))\
  {\
    return false;\
  }\
\
  unsigned count;\
  stream.from_end(sizeof(unsigned),(char *)&count,order_bytes);\
\
  if (stream.used < count*(sizeof(KEY_TYPE) + sizeof(VALUE_TYPE)))\
  {\
    return false;\
  }\
\
  MAP_NAME ## _tree_s *tree_ptr = (MAP_NAME ## _tree_s *)cmalloc(sizeof(MAP_NAME ## _tree_s));\
  tree_ptr->init();\
\
  do {\
    MAP_NAME ## _s key_value;\
\
    stream.from_end(sizeof(VALUE_TYPE),(char *)&key_value.value,order_bytes);\
    stream.from_end(sizeof(KEY_TYPE),(char *)&key_value.key,order_bytes);\
\
    tree_ptr->insert(key_value);\
  } while(--count > 0);\
\
  cont = tree_ptr;\
}/*}}}*/

  switch (type)
  {
  case c_bin_dict_type_int64_int64:
    BIC_BIN_DICT_UNPACK(lli_lli_map,long long int,long long int);
    break;
  case c_bin_dict_type_int64_float64:
    BIC_BIN_DICT_UNPACK(lli_bd_map,long long int,double);
    break;
  default:
    cassert(0);
  }

  // - create binary dict object -
  bin_dict_s *bd_ptr = (bin_dict_s *)cmalloc(sizeof(bin_dict_s));
  bd_ptr->init();

  bd_ptr->type = type;
  bd_ptr->cont = cont;

  location_ptr->v_data_ptr = (bin_dict_s *)bd_ptr;

  return true;
}/*}}}*/

bool bic_bin_dict_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_bin_dict_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
key:ignore
>
method operator_binary_le_br_re_br
; @end

  bin_dict_s *bd_ptr = (bin_dict_s *)dst_location->v_data_ptr;
  unsigned index;

  switch (bd_ptr->type)
  {
  case c_bin_dict_type_int64_int64:
  case c_bin_dict_type_int64_float64:
    {
      long long int key;

      // - ERROR -
      if (!it.retrieve_integer(src_0_location,key))
      {
        exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
        BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_le_br_re_br#1");
        new_exception->params.push(1);
        new_exception->params.push(src_0_location->v_type);

        return false;
      }

#define BIC_BIN_DICT_OPERATOR_BINARY_LE_BR_RE_BR_INTEGER(MAP_NAME,DEFAULT_VALUE) \
{/*{{{*/\
  MAP_NAME ## _tree_s *tree_ptr = (MAP_NAME ## _tree_s *)bd_ptr->cont;\
  MAP_NAME ## _s insert_map = {key,DEFAULT_VALUE};\
  index = tree_ptr->unique_insert(insert_map);\
}/*}}}*/

      switch (bd_ptr->type)
      {
      case c_bin_dict_type_int64_int64:
        BIC_BIN_DICT_OPERATOR_BINARY_LE_BR_RE_BR_INTEGER(lli_lli_map,0);
        break;
      case c_bin_dict_type_int64_float64:
        BIC_BIN_DICT_OPERATOR_BINARY_LE_BR_RE_BR_INTEGER(lli_bd_map,0.0);
        break;
      default:
        cassert(0);
      }
    }
    break;
  default:
    cassert(0);
  }

  // - create bin dict reference -
  bin_dict_ref_s *bdr_ptr = bd_ptr->create_reference(dst_location,index);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_bin_dict_ref,bdr_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_bin_dict_method_BinDict_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
type:retrieve_integer
>
method BinDict
; @end

  // - binary dict container pointer -
  void *cont = nullptr;

  switch (type)
  {
  case c_bin_dict_type_int64_int64:
    {/*{{{*/
      lli_lli_map_tree_s *tree_ptr = (lli_lli_map_tree_s *)cmalloc(sizeof(lli_lli_map_tree_s));
      tree_ptr->init();

      cont = tree_ptr;
    }/*}}}*/
    break;
  case c_bin_dict_type_int64_float64:
    {/*{{{*/
      lli_bd_map_tree_s *tree_ptr = (lli_bd_map_tree_s *)cmalloc(sizeof(lli_bd_map_tree_s));
      tree_ptr->init();

      cont = tree_ptr;
    }/*}}}*/
    break;

  // - ERROR -
  default:

    exception_s::throw_exception(it,module.error_base + c_error_BIN_DICT_UNKNOWN_DATA_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create binary dict object -
  bin_dict_s *bd_ptr = (bin_dict_s *)cmalloc(sizeof(bin_dict_s));
  bd_ptr->init();

  bd_ptr->type = type;
  bd_ptr->cont = cont;

  dst_location->v_data_ptr = (bin_dict_s *)bd_ptr;

  return true;
}/*}}}*/

bool bic_bin_dict_method_clear_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  bin_dict_s *bd_ptr = (bin_dict_s *)dst_location->v_data_ptr;

  switch (bd_ptr->type)
  {
  case c_bin_dict_type_int64_int64:
    ((lli_lli_map_tree_s *)bd_ptr->cont)->clear();
    break;
  case c_bin_dict_type_int64_float64:
    ((lli_bd_map_tree_s *)bd_ptr->cont)->clear();
    break;
  default:
    cassert(0);
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_bin_dict_method_keys_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  bin_dict_s *bd_ptr = (bin_dict_s *)dst_location->v_data_ptr;
  pointer_array_s *target_array = it.get_new_array_ptr();

#define BIC_BIN_DICT_METHOD_KEYS_INTEGER(MAP_NAME) \
{/*{{{*/\
  MAP_NAME ## _tree_s *tree_ptr = (MAP_NAME ## _tree_s *)bd_ptr->cont;\
\
  if (tree_ptr->root_idx != c_idx_not_exist)\
  {\
    unsigned stack[tree_ptr->get_descent_stack_size()];\
    unsigned *stack_ptr = stack;\
\
    unsigned kv_idx = tree_ptr->get_stack_min_value_idx(tree_ptr->root_idx,&stack_ptr);\
    do {\
      long long int value = tree_ptr->data[kv_idx].object.key;\
\
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);\
      target_array->push(new_location);\
\
      kv_idx = tree_ptr->get_stack_next_idx(kv_idx,&stack_ptr,stack);\
    } while(kv_idx != c_idx_not_exist);\
  }\
}/*}}}*/

  switch (bd_ptr->type)
  {
  case c_bin_dict_type_int64_int64:
    BIC_BIN_DICT_METHOD_KEYS_INTEGER(lli_lli_map);
    break;
  case c_bin_dict_type_int64_float64:
    BIC_BIN_DICT_METHOD_KEYS_INTEGER(lli_bd_map);
    break;
  default:
    cassert(0);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,target_array);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_bin_dict_method_items_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  bin_dict_s *bd_ptr = (bin_dict_s *)dst_location->v_data_ptr;
  pointer_array_s *target_array = it.get_new_array_ptr();

#define BIC_BIN_DICT_METHOD_ITEMS_INTEGER(MAP_NAME) \
{/*{{{*/\
  MAP_NAME ## _tree_s *tree_ptr = (MAP_NAME ## _tree_s *)bd_ptr->cont;\
\
  if (tree_ptr->root_idx != c_idx_not_exist)\
  {\
    unsigned stack[tree_ptr->get_descent_stack_size()];\
    unsigned *stack_ptr = stack;\
\
    unsigned kv_idx = tree_ptr->get_stack_min_value_idx(tree_ptr->root_idx,&stack_ptr);\
    do {\
      long long int value = tree_ptr->data[kv_idx].object.value;\
\
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);\
      target_array->push(new_location);\
\
      kv_idx = tree_ptr->get_stack_next_idx(kv_idx,&stack_ptr,stack);\
    } while(kv_idx != c_idx_not_exist);\
  }\
}/*}}}*/

#define BIC_BIN_DICT_METHOD_ITEMS_FLOAT(MAP_NAME) \
{/*{{{*/\
  MAP_NAME ## _tree_s *tree_ptr = (MAP_NAME ## _tree_s *)bd_ptr->cont;\
\
  if (tree_ptr->root_idx != c_idx_not_exist)\
  {\
    unsigned stack[tree_ptr->get_descent_stack_size()];\
    unsigned *stack_ptr = stack;\
\
    unsigned kv_idx = tree_ptr->get_stack_min_value_idx(tree_ptr->root_idx,&stack_ptr);\
    do {\
      double value = tree_ptr->data[kv_idx].object.value;\
\
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_float,value);\
      target_array->push(new_location);\
\
      kv_idx = tree_ptr->get_stack_next_idx(kv_idx,&stack_ptr,stack);\
    } while(kv_idx != c_idx_not_exist);\
  }\
}/*}}}*/

  switch (bd_ptr->type)
  {
  case c_bin_dict_type_int64_int64:
    BIC_BIN_DICT_METHOD_ITEMS_INTEGER(lli_lli_map);
    break;
  case c_bin_dict_type_int64_float64:
    BIC_BIN_DICT_METHOD_ITEMS_FLOAT(lli_bd_map);
    break;
  default:
    cassert(0);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,target_array);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_bin_dict_method_has_key_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
key:ignore
>
method has_key
; @end

  bin_dict_s *bd_ptr = (bin_dict_s *)dst_location->v_data_ptr;
  long long int result;

#define BIC_BIN_DICT_METHOD_HAS_KEY(MAP_NAME) \
{/*{{{*/\
  MAP_NAME ## _tree_s *tree_ptr = (MAP_NAME ## _tree_s *)bd_ptr->cont;\
  MAP_NAME ## _s search_map;\
  search_map.key = key;\
\
  result = tree_ptr->get_idx(search_map) != c_idx_not_exist;\
}/*}}}*/

  switch (bd_ptr->type)
  {
  case c_bin_dict_type_int64_int64:
  case c_bin_dict_type_int64_float64:
    {
      long long int key;

      // - ERROR -
      if (!it.retrieve_integer(src_0_location,key))
      {
        exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
        BIC_EXCEPTION_PUSH_METHOD_RI("has_key#1");
        new_exception->params.push(1);
        new_exception->params.push(src_0_location->v_type);

        return false;
      }

      switch (bd_ptr->type)
      {
      case c_bin_dict_type_int64_int64:
        BIC_BIN_DICT_METHOD_HAS_KEY(lli_lli_map);
        break;
      case c_bin_dict_type_int64_float64:
        BIC_BIN_DICT_METHOD_HAS_KEY(lli_bd_map);
        break;
      }
    }
    break;
  default:
    cassert(0);
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_bin_dict_method_remove_key_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
key:ignore
>
method remove_key
; @end

  bin_dict_s *bd_ptr = (bin_dict_s *)dst_location->v_data_ptr;

#define BIC_BIN_DICT_METHOD_REMOVE_KEY(MAP_NAME) \
{/*{{{*/\
  MAP_NAME ## _tree_s *tree_ptr = (MAP_NAME ## _tree_s *)bd_ptr->cont;\
  MAP_NAME ## _s search_map;\
  search_map.key = key;\
\
  unsigned index = tree_ptr->get_idx(search_map);\
\
  /* - ERROR - */\
  if (index == c_idx_not_exist)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_BIN_DICT_INVALID_KEY,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  tree_ptr->remove(index);\
}/*}}}*/

  switch (bd_ptr->type)
  {
  case c_bin_dict_type_int64_int64:
  case c_bin_dict_type_int64_float64:
    {
      long long int key;

      // - ERROR -
      if (!it.retrieve_integer(src_0_location,key))
      {
        exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
        BIC_EXCEPTION_PUSH_METHOD_RI("remove_key#1");
        new_exception->params.push(1);
        new_exception->params.push(src_0_location->v_type);

        return false;
      }

      switch (bd_ptr->type)
      {
      case c_bin_dict_type_int64_int64:
        BIC_BIN_DICT_METHOD_REMOVE_KEY(lli_lli_map);
        break;
      case c_bin_dict_type_int64_float64:
        BIC_BIN_DICT_METHOD_REMOVE_KEY(lli_bd_map);
        break;
      }
    }
    break;
  default:
    cassert(0);
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_bin_dict_method_first_key_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  bin_dict_s *bd_ptr = (bin_dict_s *)dst_location->v_data_ptr;

#define BIC_BIN_DICT_METHOD_FIRST_KEY_INTEGER(MAP_NAME) \
{/*{{{*/\
  MAP_NAME ## _tree_s *tree_ptr = (MAP_NAME ## _tree_s *)bd_ptr->cont;\
\
  if (tree_ptr->root_idx != c_idx_not_exist)\
  {\
    unsigned min_value_idx = tree_ptr->get_min_value_idx(tree_ptr->root_idx);\
    long long int key = tree_ptr->data[min_value_idx].object.key;\
\
    BIC_SIMPLE_SET_RES(c_bi_class_integer,key);\
  }\
  else\
  {\
    BIC_SET_RESULT_BLANK();\
  }\
}/*}}}*/

  switch (bd_ptr->type)
  {
  case c_bin_dict_type_int64_int64:
    BIC_BIN_DICT_METHOD_FIRST_KEY_INTEGER(lli_lli_map);
    break;
  case c_bin_dict_type_int64_float64:
    BIC_BIN_DICT_METHOD_FIRST_KEY_INTEGER(lli_bd_map);
    break;
  default:
    cassert(0);
  }

  return true;
}/*}}}*/

bool bic_bin_dict_method_last_key_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  bin_dict_s *bd_ptr = (bin_dict_s *)dst_location->v_data_ptr;

#define BIC_BIN_DICT_METHOD_LAST_KEY_INTEGER(MAP_NAME) \
{/*{{{*/\
  MAP_NAME ## _tree_s *tree_ptr = (MAP_NAME ## _tree_s *)bd_ptr->cont;\
\
  if (tree_ptr->root_idx != c_idx_not_exist)\
  {\
    unsigned max_value_idx = tree_ptr->get_max_value_idx(tree_ptr->root_idx);\
    long long int key = tree_ptr->data[max_value_idx].object.key;\
\
    BIC_SIMPLE_SET_RES(c_bi_class_integer,key);\
  }\
  else\
  {\
    BIC_SET_RESULT_BLANK();\
  }\
}/*}}}*/

  switch (bd_ptr->type)
  {
  case c_bin_dict_type_int64_int64:
    BIC_BIN_DICT_METHOD_LAST_KEY_INTEGER(lli_lli_map);
    break;
  case c_bin_dict_type_int64_float64:
    BIC_BIN_DICT_METHOD_LAST_KEY_INTEGER(lli_bd_map);
    break;
  default:
    cassert(0);
  }

  return true;
}/*}}}*/

bool bic_bin_dict_method_next_key_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
key:ignore
>
method next_key
; @end

  bin_dict_s *bd_ptr = (bin_dict_s *)dst_location->v_data_ptr;

#define BIC_BIN_DICT_METHOD_NEXT_KEY_INTEGER(MAP_NAME) \
{/*{{{*/\
  MAP_NAME ## _tree_s *tree_ptr = (MAP_NAME ## _tree_s *)bd_ptr->cont;\
  MAP_NAME ## _s search_map;\
  search_map.key = key;\
\
  unsigned index = tree_ptr->get_idx(search_map);\
\
  if (index != c_idx_not_exist)\
  {\
    unsigned next_value_idx = tree_ptr->get_next_idx(index);\
\
    if (next_value_idx != c_idx_not_exist)\
    {\
      long long int next_key = tree_ptr->data[next_value_idx].object.key;\
\
      BIC_SIMPLE_SET_RES(c_bi_class_integer,next_key);\
    }\
    else\
    {\
      BIC_SET_RESULT_BLANK();\
    }\
  }\
  else\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_BIN_DICT_INVALID_KEY,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
}/*}}}*/

  switch (bd_ptr->type)
  {
  case c_bin_dict_type_int64_int64:
  case c_bin_dict_type_int64_float64:
    {
      long long int key;

      // - ERROR -
      if (!it.retrieve_integer(src_0_location,key))
      {
        exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
        BIC_EXCEPTION_PUSH_METHOD_RI("next_key#1");
        new_exception->params.push(1);
        new_exception->params.push(src_0_location->v_type);

        return false;
      }

      switch (bd_ptr->type)
      {
      case c_bin_dict_type_int64_int64:
        BIC_BIN_DICT_METHOD_NEXT_KEY_INTEGER(lli_lli_map);
        break;
      case c_bin_dict_type_int64_float64:
        BIC_BIN_DICT_METHOD_NEXT_KEY_INTEGER(lli_bd_map);
        break;
      }
    }
    break;
  default:
    cassert(0);
  }

  return true;
}/*}}}*/

bool bic_bin_dict_method_prev_key_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
key:ignore
>
method prev_key
; @end

  bin_dict_s *bd_ptr = (bin_dict_s *)dst_location->v_data_ptr;

#define BIC_BIN_DICT_METHOD_PREV_KEY_INTEGER(MAP_NAME) \
{/*{{{*/\
  MAP_NAME ## _tree_s *tree_ptr = (MAP_NAME ## _tree_s *)bd_ptr->cont;\
  MAP_NAME ## _s search_map;\
  search_map.key = key;\
\
  unsigned index = tree_ptr->get_idx(search_map);\
\
  if (index != c_idx_not_exist)\
  {\
    unsigned prev_value_idx = tree_ptr->get_prev_idx(index);\
\
    if (prev_value_idx != c_idx_not_exist)\
    {\
      long long int prev_key = tree_ptr->data[prev_value_idx].object.key;\
\
      BIC_SIMPLE_SET_RES(c_bi_class_integer,prev_key);\
    }\
    else\
    {\
      BIC_SET_RESULT_BLANK();\
    }\
  }\
  else\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_BIN_DICT_INVALID_KEY,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
}/*}}}*/

  switch (bd_ptr->type)
  {
  case c_bin_dict_type_int64_int64:
  case c_bin_dict_type_int64_float64:
    {
      long long int key;

      // - ERROR -
      if (!it.retrieve_integer(src_0_location,key))
      {
        exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
        BIC_EXCEPTION_PUSH_METHOD_RI("prev_key#1");
        new_exception->params.push(1);
        new_exception->params.push(src_0_location->v_type);

        return false;
      }

      switch (bd_ptr->type)
      {
      case c_bin_dict_type_int64_int64:
        BIC_BIN_DICT_METHOD_PREV_KEY_INTEGER(lli_lli_map);
        break;
      case c_bin_dict_type_int64_float64:
        BIC_BIN_DICT_METHOD_PREV_KEY_INTEGER(lli_bd_map);
        break;
      }
    }
    break;
  default:
    cassert(0);
  }

  return true;
}/*}}}*/

bool bic_bin_dict_method_lee_key_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
key:ignore
>
method lee_key
; @end

  bin_dict_s *bd_ptr = (bin_dict_s *)dst_location->v_data_ptr;

#define BIC_BIN_DICT_METHOD_LEE_KEY_INTEGER(MAP_NAME) \
{/*{{{*/\
  MAP_NAME ## _tree_s *tree_ptr = (MAP_NAME ## _tree_s *)bd_ptr->cont;\
  MAP_NAME ## _s search_map;\
  search_map.key = key;\
\
  unsigned index = tree_ptr->get_lee_idx(search_map);\
\
  if (index != c_idx_not_exist)\
  {\
    long long int key = tree_ptr->data[index].object.key;\
\
    BIC_SIMPLE_SET_RES(c_bi_class_integer,key);\
  }\
  else\
  {\
    BIC_SET_RESULT_BLANK();\
  }\
}/*}}}*/

  switch (bd_ptr->type)
  {
  case c_bin_dict_type_int64_int64:
  case c_bin_dict_type_int64_float64:
    {
      long long int key;

      // - ERROR -
      if (!it.retrieve_integer(src_0_location,key))
      {
        exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
        BIC_EXCEPTION_PUSH_METHOD_RI("lee_key#1");
        new_exception->params.push(1);
        new_exception->params.push(src_0_location->v_type);

        return false;
      }

      switch (bd_ptr->type)
      {
      case c_bin_dict_type_int64_int64:
        BIC_BIN_DICT_METHOD_LEE_KEY_INTEGER(lli_lli_map);
        break;
      case c_bin_dict_type_int64_float64:
        BIC_BIN_DICT_METHOD_LEE_KEY_INTEGER(lli_bd_map);
        break;
      }
    }
    break;
  default:
    cassert(0);
  }

  return true;
}/*}}}*/

bool bic_bin_dict_method_gre_key_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
key:ignore
>
method gre_key
; @end

  bin_dict_s *bd_ptr = (bin_dict_s *)dst_location->v_data_ptr;

#define BIC_BIN_DICT_METHOD_GRE_KEY_INTEGER(MAP_NAME) \
{/*{{{*/\
  MAP_NAME ## _tree_s *tree_ptr = (MAP_NAME ## _tree_s *)bd_ptr->cont;\
  MAP_NAME ## _s search_map;\
  search_map.key = key;\
\
  unsigned index = tree_ptr->get_gre_idx(search_map);\
\
  if (index != c_idx_not_exist)\
  {\
    long long int key = tree_ptr->data[index].object.key;\
\
    BIC_SIMPLE_SET_RES(c_bi_class_integer,key);\
  }\
  else\
  {\
    BIC_SET_RESULT_BLANK();\
  }\
}/*}}}*/

  switch (bd_ptr->type)
  {
  case c_bin_dict_type_int64_int64:
  case c_bin_dict_type_int64_float64:
    {
      long long int key;

      // - ERROR -
      if (!it.retrieve_integer(src_0_location,key))
      {
        exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
        BIC_EXCEPTION_PUSH_METHOD_RI("gre_key#1");
        new_exception->params.push(1);
        new_exception->params.push(src_0_location->v_type);

        return false;
      }

      switch (bd_ptr->type)
      {
      case c_bin_dict_type_int64_int64:
        BIC_BIN_DICT_METHOD_GRE_KEY_INTEGER(lli_lli_map);
        break;
      case c_bin_dict_type_int64_float64:
        BIC_BIN_DICT_METHOD_GRE_KEY_INTEGER(lli_bd_map);
        break;
      }
    }
    break;
  default:
    cassert(0);
  }

  return true;
}/*}}}*/

bool bic_bin_dict_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_BIN_DICT_COMPARE(dst_location,src_0_location,operands[c_source_pos_idx]);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_bin_dict_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
index:retrieve_integer
>
method item
; @end

  bin_dict_s *bd_ptr = (bin_dict_s *)dst_location->v_data_ptr;

  switch (bd_ptr->type)
  {
  case c_bin_dict_type_int64_int64:
    {
      BIC_BIN_DICT_CHECK_IDX(lli_lli_map);
    }
    break;
  case c_bin_dict_type_int64_float64:
    {
      BIC_BIN_DICT_CHECK_IDX(lli_bd_map);
    }
    break;
  default:
    cassert(0);
  }

  // - create bin dict reference -
  bin_dict_ref_s *bdr_ptr = bd_ptr->create_reference(dst_location,index);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_bin_dict_ref,bdr_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_bin_dict_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  bin_dict_s *bd_ptr = (bin_dict_s *)dst_location->v_data_ptr;

#define BIC_BIN_DICT_METHOD_FIRST_IDX(MAP_NAME) \
{/*{{{*/\
  MAP_NAME ## _tree_s *tree_ptr = (MAP_NAME ## _tree_s *)bd_ptr->cont;\
\
  if (tree_ptr->root_idx != c_idx_not_exist)\
  {\
    long long int index = tree_ptr->get_min_value_idx(tree_ptr->root_idx);\
\
    BIC_SIMPLE_SET_RES(c_bi_class_integer,index);\
  }\
  else\
  {\
    BIC_SET_RESULT_BLANK();\
  }\
}/*}}}*/

  switch (bd_ptr->type)
  {
  case c_bin_dict_type_int64_int64:
    BIC_BIN_DICT_METHOD_FIRST_IDX(lli_lli_map);
    break;
  case c_bin_dict_type_int64_float64:
    BIC_BIN_DICT_METHOD_FIRST_IDX(lli_bd_map);
    break;
  default:
    cassert(0);
  }

  return true;
}/*}}}*/

bool bic_bin_dict_method_last_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  bin_dict_s *bd_ptr = (bin_dict_s *)dst_location->v_data_ptr;

#define BIC_BIN_DICT_METHOD_LAST_IDX(MAP_NAME) \
{/*{{{*/\
  MAP_NAME ## _tree_s *tree_ptr = (MAP_NAME ## _tree_s *)bd_ptr->cont;\
\
  if (tree_ptr->root_idx != c_idx_not_exist)\
  {\
    long long int index = tree_ptr->get_max_value_idx(tree_ptr->root_idx);\
\
    BIC_SIMPLE_SET_RES(c_bi_class_integer,index);\
  }\
  else\
  {\
    BIC_SET_RESULT_BLANK();\
  }\
}/*}}}*/

  switch (bd_ptr->type)
  {
  case c_bin_dict_type_int64_int64:
    BIC_BIN_DICT_METHOD_LAST_IDX(lli_lli_map);
    break;
  case c_bin_dict_type_int64_float64:
    BIC_BIN_DICT_METHOD_LAST_IDX(lli_bd_map);
    break;
  default:
    cassert(0);
  }

  return true;
}/*}}}*/

bool bic_bin_dict_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
index:retrieve_integer
>
method next_idx
; @end

  bin_dict_s *bd_ptr = (bin_dict_s *)dst_location->v_data_ptr;
  long long int result;

#define BIC_BIN_DICT_METHOD_NEXT_IDX(MAP_NAME) \
{/*{{{*/\
  BIC_BIN_DICT_CHECK_IDX(MAP_NAME);\
\
  result = tree_ptr->get_next_idx(index);\
}/*}}}*/

  switch (bd_ptr->type)
  {
  case c_bin_dict_type_int64_int64:
    BIC_BIN_DICT_METHOD_NEXT_IDX(lli_lli_map);
    break;
  case c_bin_dict_type_int64_float64:
    BIC_BIN_DICT_METHOD_NEXT_IDX(lli_bd_map);
    break;
  default:
    cassert(0);
  }

  BIC_SET_RESULT_CONT_INDEX(result);

  return true;
}/*}}}*/

bool bic_bin_dict_method_prev_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
index:retrieve_integer
>
method prev_idx
; @end

  bin_dict_s *bd_ptr = (bin_dict_s *)dst_location->v_data_ptr;
  long long int result;

#define BIC_BIN_DICT_METHOD_PREV_IDX(MAP_NAME) \
{/*{{{*/\
  BIC_BIN_DICT_CHECK_IDX(MAP_NAME);\
\
  result = tree_ptr->get_prev_idx(index);\
}/*}}}*/

  switch (bd_ptr->type)
  {
  case c_bin_dict_type_int64_int64:
    BIC_BIN_DICT_METHOD_PREV_IDX(lli_lli_map);
    break;
  case c_bin_dict_type_int64_float64:
    BIC_BIN_DICT_METHOD_PREV_IDX(lli_bd_map);
    break;
  default:
    cassert(0);
  }

  BIC_SET_RESULT_CONT_INDEX(result);

  return true;
}/*}}}*/

bool bic_bin_dict_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  bin_dict_s *bd_ptr = (bin_dict_s *)dst_location->v_data_ptr;
  long long int result;

  switch (bd_ptr->type)
  {
  case c_bin_dict_type_int64_int64:
    result = ((lli_lli_map_tree_s *)bd_ptr->cont)->count;
    break;
  case c_bin_dict_type_int64_float64:
    result = ((lli_bd_map_tree_s *)bd_ptr->cont)->count;
    break;
  default:
    cassert(0);
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_bin_dict_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  bin_dict_s *bd_ptr = (bin_dict_s *)dst_location->v_data_ptr;

  string_array_s strings;
  strings.init();

  unsigned strings_size = 0;

#define BIC_BIN_DICT_METHOD_TO_STRING(MAP_NAME,FORMAT) \
{/*{{{*/\
  MAP_NAME ## _tree_s *tree_ptr = (MAP_NAME ## _tree_s *)bd_ptr->cont;\
\
  if (tree_ptr->root_idx != c_idx_not_exist)\
  {\
    strings.copy_resize(tree_ptr->count);\
    strings.used = strings.size;\
\
    unsigned stack[tree_ptr->get_descent_stack_size()];\
    unsigned *stack_ptr = stack;\
\
    unsigned kv_idx = tree_ptr->get_stack_min_value_idx(tree_ptr->root_idx,&stack_ptr);\
    string_s *s_ptr = strings.data;\
\
    do {\
      MAP_NAME ## _s &key_value = tree_ptr->data[kv_idx].object;\
\
      s_ptr->setf(FORMAT,key_value.key,key_value.value);\
      strings_size += s_ptr->size - 1;\
\
      kv_idx = tree_ptr->get_stack_next_idx(kv_idx,&stack_ptr,stack);\
    } while(++s_ptr,kv_idx != c_idx_not_exist);\
  }\
}/*}}}*/

  switch (bd_ptr->type)
  {
  case c_bin_dict_type_int64_int64:
    BIC_BIN_DICT_METHOD_TO_STRING(lli_lli_map,"%" HOST_LL_FORMAT "d:%" HOST_LL_FORMAT "d");
    break;
  case c_bin_dict_type_int64_float64:
    BIC_BIN_DICT_METHOD_TO_STRING(lli_bd_map,"%" HOST_LL_FORMAT "d:%f");
    break;
  default:
    cassert(0);
  }

  string_s *string_ptr = it.get_new_string_ptr();

  BIC_CONT_TO_STRING_0_CONSTRUCT();

  // - release string array -
  strings.clear();

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_bin_dict_method_to_string_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
delimiter:c_bi_class_string
>
method to_string
; @end

  bin_dict_s *bd_ptr = (bin_dict_s *)dst_location->v_data_ptr;
  string_s *del_string_ptr = (string_s *)src_0_location->v_data_ptr;

  string_array_s strings;
  strings.init();

  unsigned strings_size = 0;

  switch (bd_ptr->type)
  {
  case c_bin_dict_type_int64_int64:
    BIC_BIN_DICT_METHOD_TO_STRING(lli_lli_map,"%" HOST_LL_FORMAT "d:%" HOST_LL_FORMAT "d");
    break;
  case c_bin_dict_type_int64_float64:
    BIC_BIN_DICT_METHOD_TO_STRING(lli_bd_map,"%" HOST_LL_FORMAT "d:%f");
    break;
  default:
    cassert(0);
  }

  string_s *string_ptr = it.get_new_string_ptr();

  BIC_CONT_TO_STRING_1_CONSTRUCT();

  // - release string array -
  strings.clear();

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_bin_dict_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  bin_dict_s *bd_ptr = (bin_dict_s *)dst_location->v_data_ptr;

  putchar('[');

#define BIC_BIN_DICT_METHOD_PRINT(MAP_NAME,FORMAT) \
{/*{{{*/\
  MAP_NAME ## _tree_s *tree_ptr = (MAP_NAME ## _tree_s *)bd_ptr->cont;\
\
  if (tree_ptr->root_idx != c_idx_not_exist)\
  {\
    unsigned stack[tree_ptr->get_descent_stack_size()];\
    unsigned *stack_ptr = stack;\
\
    unsigned kv_idx = tree_ptr->get_stack_min_value_idx(tree_ptr->root_idx,&stack_ptr);\
    do {\
      MAP_NAME ## _s &key_value = tree_ptr->data[kv_idx].object;\
\
      printf(FORMAT,key_value.key,key_value.value);\
\
      kv_idx = tree_ptr->get_stack_next_idx(kv_idx,&stack_ptr,stack);\
      if (kv_idx == c_idx_not_exist) break;\
\
      putchar(',');\
    } while(true);\
  }\
}/*}}}*/

  switch (bd_ptr->type)
  {
  case c_bin_dict_type_int64_int64:
    BIC_BIN_DICT_METHOD_PRINT(lli_lli_map,"%" HOST_LL_FORMAT "d:%" HOST_LL_FORMAT "d");
    break;
  case c_bin_dict_type_int64_float64:
    BIC_BIN_DICT_METHOD_PRINT(lli_bd_map,"%" HOST_LL_FORMAT "d:%f");
    break;
  default:
    cassert(0);
  }

  putchar(']');

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

// - class BIN_DICT_REF -
built_in_class_s bin_dict_ref_class =
{/*{{{*/
  "BinDictRef",
  c_modifier_public | c_modifier_final,
  5, bin_dict_ref_methods,
  0, bin_dict_ref_variables,
  bic_bin_dict_ref_consts,
  bic_bin_dict_ref_init,
  bic_bin_dict_ref_clear,
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

built_in_method_s bin_dict_ref_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_bin_dict_ref_operator_binary_equal
  },
  {
    "key#0",
    c_modifier_public | c_modifier_final,
    bic_bin_dict_ref_method_key_0
  },
  {
    "value#0",
    c_modifier_public | c_modifier_final,
    bic_bin_dict_ref_method_value_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_bin_dict_ref_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_bin_dict_ref_method_print_0
  },
};/*}}}*/

built_in_variable_s bin_dict_ref_variables[] =
{/*{{{*/
};/*}}}*/

void bic_bin_dict_ref_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_bin_dict_ref_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (bin_dict_ref_s *)nullptr;
}/*}}}*/

void bic_bin_dict_ref_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  bin_dict_ref_s *bdr_ptr = (bin_dict_ref_s *)location_ptr->v_data_ptr;

  if (bdr_ptr != nullptr)
  {
    ((bin_dict_s *)bdr_ptr->bd_location->v_data_ptr)->release_reference(it,bdr_ptr);
  }
}/*}}}*/

bool bic_bin_dict_ref_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
value:ignore
>
method operator_binary_equal
; @end

  bin_dict_ref_s *bdr_ptr = (bin_dict_ref_s *)dst_location->v_data_ptr;
  bin_dict_s *bd_ptr = (bin_dict_s *)bdr_ptr->bd_location->v_data_ptr;

  switch (bd_ptr->type)
  {
  case c_bin_dict_type_int64_int64:
    {/*{{{*/
      long long int value;

      // - ERROR -
      if (!it.retrieve_integer(src_0_location,value))
      {
        exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
        BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_equal#1");
        new_exception->params.push(1);
        new_exception->params.push(src_0_location->v_type);

        return false;
      }

      lli_lli_map_tree_s *tree_ptr = (lli_lli_map_tree_s *)bd_ptr->cont;
      lli_lli_map_tree_s_node *key_value_node;

      // - ERROR -
      if (bdr_ptr->index >= tree_ptr->used ||
          !((key_value_node = tree_ptr->data + bdr_ptr->index)->valid))
      {
        exception_s::throw_exception(it,module.error_base + c_error_BIN_DICT_REF_INVALID_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      key_value_node->object.value = value;

      BIC_SIMPLE_SET_RES(c_bi_class_integer,value);
    }/*}}}*/
    break;
  case c_bin_dict_type_int64_float64:
    {/*{{{*/
      double value;

      // - ERROR -
      if (!it.retrieve_float(src_0_location,value))
      {
        exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
        BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_equal#1");
        new_exception->params.push(1);
        new_exception->params.push(src_0_location->v_type);

        return false;
      }

      lli_bd_map_tree_s *tree_ptr = (lli_bd_map_tree_s *)bd_ptr->cont;
      lli_bd_map_tree_s_node *key_value_node;

      // - ERROR -
      if (bdr_ptr->index >= tree_ptr->used ||
          !((key_value_node = tree_ptr->data + bdr_ptr->index)->valid))
      {
        exception_s::throw_exception(it,module.error_base + c_error_BIN_DICT_REF_INVALID_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      key_value_node->object.value = value;

      BIC_SIMPLE_SET_RES(c_bi_class_float,value);
    }/*}}}*/
    break;
  default:
    cassert(0);
  }

  return true;
}/*}}}*/

bool bic_bin_dict_ref_method_key_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  bin_dict_ref_s *bdr_ptr = (bin_dict_ref_s *)dst_location->v_data_ptr;
  bin_dict_s *bd_ptr = (bin_dict_s *)bdr_ptr->bd_location->v_data_ptr;

#define BIC_BIN_DICT_REF_METHOD_KEY_INTEGER(MAP_NAME) \
{/*{{{*/\
  MAP_NAME ## _tree_s *tree_ptr = (MAP_NAME ## _tree_s *)bd_ptr->cont;\
  MAP_NAME ## _tree_s_node *key_value_node;\
\
  /* - ERROR - */\
  if (bdr_ptr->index >= tree_ptr->used ||\
      !((key_value_node = tree_ptr->data + bdr_ptr->index)->valid))\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_BIN_DICT_REF_INVALID_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  long long int &key = key_value_node->object.key;\
  BIC_SIMPLE_SET_RES(c_bi_class_integer,key);\
}/*}}}*/

  switch (bd_ptr->type)
  {
  case c_bin_dict_type_int64_int64:
    BIC_BIN_DICT_REF_METHOD_KEY_INTEGER(lli_lli_map);
    break;
  case c_bin_dict_type_int64_float64:
    BIC_BIN_DICT_REF_METHOD_KEY_INTEGER(lli_bd_map);
    break;
  default:
    cassert(0);
  }

  return true;
}/*}}}*/

bool bic_bin_dict_ref_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  bin_dict_ref_s *bdr_ptr = (bin_dict_ref_s *)dst_location->v_data_ptr;
  bin_dict_s *bd_ptr = (bin_dict_s *)bdr_ptr->bd_location->v_data_ptr;

  switch (bd_ptr->type)
  {
  case c_bin_dict_type_int64_int64:
    {/*{{{*/
      lli_lli_map_tree_s *tree_ptr = (lli_lli_map_tree_s *)bd_ptr->cont;
      lli_lli_map_tree_s_node *key_value_node;

      // - ERROR -
      if (bdr_ptr->index >= tree_ptr->used ||
          !((key_value_node = tree_ptr->data + bdr_ptr->index)->valid))
      {
        exception_s::throw_exception(it,module.error_base + c_error_BIN_DICT_REF_INVALID_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      long long int &value = key_value_node->object.value;

      BIC_SIMPLE_SET_RES(c_bi_class_integer,value);
    }/*}}}*/
    break;
  case c_bin_dict_type_int64_float64:
    {/*{{{*/
      lli_bd_map_tree_s *tree_ptr = (lli_bd_map_tree_s *)bd_ptr->cont;
      lli_bd_map_tree_s_node *key_value_node;

      // - ERROR -
      if (bdr_ptr->index >= tree_ptr->used ||
          !((key_value_node = tree_ptr->data + bdr_ptr->index)->valid))
      {
        exception_s::throw_exception(it,module.error_base + c_error_BIN_DICT_REF_INVALID_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      double &value = key_value_node->object.value;

      BIC_SIMPLE_SET_RES(c_bi_class_float,value);
    }/*}}}*/
    break;
  default:
    cassert(0);
  }

  return true;
}/*}}}*/

bool bic_bin_dict_ref_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("BinDictRef"),"BinDictRef")
  );

  return true;
}/*}}}*/

bool bic_bin_dict_ref_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("BinDictRef");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

