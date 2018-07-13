
@begin
include "datrie_module.h"
@end

// - DATRIE indexes of built in classes -
unsigned c_bi_class_datrie_alpha_map = c_idx_not_exist;
unsigned c_bi_class_datrie = c_idx_not_exist;
unsigned c_bi_class_datrie_iterator = c_idx_not_exist;

// - DATRIE indexes of remote classes -
unsigned c_rm_class_unicode_char = c_idx_not_exist;
unsigned c_rm_class_unicode_string = c_idx_not_exist;

// - DATRIE module -
built_in_module_s module =
{/*{{{*/
  3,                      // Class count
  datrie_classes,         // Classes

  0,                      // Error base index
  9,                      // Error count
  datrie_error_strings,   // Error strings

  datrie_initialize,      // Initialize function
  datrie_print_exception, // Print exceptions function
};/*}}}*/

// - DATRIE classes -
built_in_class_s *datrie_classes[] =
{/*{{{*/
  &datrie_alpha_map_class,
  &datrie_class,
  &datrie_iterator_class,
};/*}}}*/

// - DATRIE error strings -
const char *datrie_error_strings[] =
{/*{{{*/
  "error_DATRIE_ALPHA_MAP_CREATE_ERROR",
  "error_DATRIE_ALPHA_MAP_ADD_RANGE_ERROR",
  "error_DATRIE_CREATE_ERROR",
  "error_DATRIE_STORE_ERROR",
  "error_DATRIE_RETRIEVE_ERROR",
  "error_DATRIE_INVALID_KEY",
  "error_DATRIE_INVALID_KEY_TYPE",
  "error_DATRIE_SOURCE_NOT_DIVISIBLE_BY_TWO",
  "error_DATRIE_ITERATOR_CREATE_ERROR",
};/*}}}*/

// - DATRIE initialize -
bool datrie_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize datrie_alpha_map class identifier -
  c_bi_class_datrie_alpha_map = class_base_idx++;

  // - initialize datrie class identifier -
  c_bi_class_datrie = class_base_idx++;

  // - initialize datrie_iterator class identifier -
  c_bi_class_datrie_iterator = class_base_idx++;

  // - retrieve remote unicode_char class index -
  c_rm_class_unicode_char = sp.resolve_class_idx_by_name("UnicodeChar",c_idx_not_exist);

  // - retrieve remote unicode_string class index -
  c_rm_class_unicode_string = sp.resolve_class_idx_by_name("UnicodeString",c_idx_not_exist);

  // - ERROR -
  if (c_rm_class_unicode_char == c_idx_not_exist ||
      c_rm_class_unicode_string == c_idx_not_exist)
  {
    sp.error_code.push(ei_module_cannot_find_remote_class);
    sp.error_code.push(sp.module_names_positions[sp.module_idx].ui_first);
    sp.error_code.push(sp.module_idx);

    return false;
  }

  return true;
}/*}}}*/

// - DATRIE print exception -
bool datrie_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_DATRIE_ALPHA_MAP_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating double array trie alphabet map\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_DATRIE_ALPHA_MAP_ADD_RANGE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while adding range to double array trie alphabet map\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_DATRIE_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating double array trie\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_DATRIE_STORE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while storing value to double array trie\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_DATRIE_RETRIEVE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while retrieving value from double array trie\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_DATRIE_INVALID_KEY:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid datrie key value\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_DATRIE_INVALID_KEY_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid datrie key value, expected UnicodeString\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_DATRIE_SOURCE_NOT_DIVISIBLE_BY_TWO:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nLength of datrie source is not divisible by two\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_DATRIE_ITERATOR_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creting double array trie iterator\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class DATRIE_ALPHA_MAP -
built_in_class_s datrie_alpha_map_class =
{/*{{{*/
  "DatrieAlphaMap",
  c_modifier_public | c_modifier_final,
  5, datrie_alpha_map_methods,
  0, datrie_alpha_map_variables,
  bic_datrie_alpha_map_consts,
  bic_datrie_alpha_map_init,
  bic_datrie_alpha_map_clear,
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

built_in_method_s datrie_alpha_map_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_datrie_alpha_map_operator_binary_equal
  },
  {
    "DatrieAlphaMap#0",
    c_modifier_public | c_modifier_final,
    bic_datrie_alpha_map_method_DatrieAlphaMap_0
  },
  {
    "add_range#2",
    c_modifier_public | c_modifier_final,
    bic_datrie_alpha_map_method_add_range_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_datrie_alpha_map_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_datrie_alpha_map_method_print_0
  },
};/*}}}*/

built_in_variable_s datrie_alpha_map_variables[] =
{/*{{{*/
};/*}}}*/

void bic_datrie_alpha_map_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_datrie_alpha_map_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (AlphaMap *)nullptr;
}/*}}}*/

void bic_datrie_alpha_map_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  AlphaMap *am_ptr = (AlphaMap *)location_ptr->v_data_ptr;

  if (am_ptr != nullptr)
  {
    alpha_map_free(am_ptr);
  }
}/*}}}*/

bool bic_datrie_alpha_map_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_datrie_alpha_map_method_DatrieAlphaMap_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  AlphaMap *am_ptr = alpha_map_new();

  // - ERROR -
  if (am_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_DATRIE_ALPHA_MAP_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set destination data pointer -
  dst_location->v_data_ptr = (AlphaMap *)am_ptr;

  return true;
}/*}}}*/

bool bic_datrie_alpha_map_method_add_range_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_rm_class_unicode_char ||
      src_1_location->v_type != c_rm_class_unicode_char)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("add_range#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  AlphaMap *am_ptr = (AlphaMap *)dst_location->v_data_ptr;
  u_int32_t begin = (u_int32_t)src_0_location->v_data_ptr;
  u_int32_t end = (u_int32_t)src_1_location->v_data_ptr;;

  // - ERROR -
  if (alpha_map_add_range(am_ptr,begin,end) != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_DATRIE_ALPHA_MAP_ADD_RANGE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_datrie_alpha_map_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("DatrieAlphaMap"),"DatrieAlphaMap");
  );

  return true;
}/*}}}*/

bool bic_datrie_alpha_map_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("DatrieAlphaMap");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class DATRIE -
built_in_class_s datrie_class =
{/*{{{*/
  "Datrie",
  c_modifier_public | c_modifier_final,
  16, datrie_methods,
  0, datrie_variables,
  bic_datrie_consts,
  bic_datrie_init,
  bic_datrie_clear,
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

built_in_method_s datrie_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_datrie_operator_binary_equal
  },
  {
    "operator_binary_double_equal#1",
    c_modifier_public | c_modifier_final,
    bic_datrie_operator_binary_double_equal
  },
  {
    "operator_binary_exclamation_equal#1",
    c_modifier_public | c_modifier_final,
    bic_datrie_operator_binary_exclamation_equal
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_datrie_operator_binary_le_br_re_br
  },
  {
    "Datrie#1",
    c_modifier_public | c_modifier_final,
    bic_datrie_method_Datrie_1
  },
  {
    "Datrie#2",
    c_modifier_public | c_modifier_final,
    bic_datrie_method_Datrie_2
  },
  {
    "keys#0",
    c_modifier_public | c_modifier_final,
    bic_datrie_method_keys_0
  },
  {
    "items#0",
    c_modifier_public | c_modifier_final,
    bic_datrie_method_items_0
  },
  {
    "iterator#0",
    c_modifier_public | c_modifier_final,
    bic_datrie_method_iterator_0
  },
  {
    "has_key#1",
    c_modifier_public | c_modifier_final,
    bic_datrie_method_has_key_1
  },
  {
    "remove_key#1",
    c_modifier_public | c_modifier_final,
    bic_datrie_method_remove_key_1
  },
  {
    "contain#1",
    c_modifier_public | c_modifier_final,
    bic_datrie_method_contain_1
  },
  {
    "compare#1",
    c_modifier_public | c_modifier_final,
    bic_datrie_method_compare_1
  },
  {
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_datrie_method_length_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_datrie_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_datrie_method_print_0
  },
};/*}}}*/

built_in_variable_s datrie_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_DATRIE_METHOD_CONTAIN(NAME) \
{/*{{{*/\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
  \
  if (src_0_location->v_type != c_rm_class_unicode_string)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
    new_exception->params.push(1);\
    new_exception->params.push(src_0_location->v_type);\
    \
    return false;\
  }\
  \
  datrie_s *dt_ptr = (datrie_s *)dst_location->v_data_ptr;\
  ui_array_s *ustring_ptr = (ui_array_s *)src_0_location->v_data_ptr;\
  \
  TrieData index;\
  long long int result = trie_retrieve(dt_ptr->trie_ptr,ustring_ptr->data,&index);\
  \
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
  \
  return true;\
}/*}}}*/

#define BIC_DATRIE_COMPARE(SOURCE_POS) \
{/*{{{*/\
  if (src_0_location->v_type == c_bi_class_datrie)\
  {\
    datrie_s *f_dt_ptr = (datrie_s *)dst_location->v_data_ptr;\
    datrie_s *s_dt_ptr = (datrie_s *)src_0_location->v_data_ptr;\
    \
    if (f_dt_ptr->data_list.count != s_dt_ptr->data_list.count)\
    {\
      result = f_dt_ptr->data_list.count < s_dt_ptr->data_list.count ? -1 : 1;\
    }\
    else {\
      result = 0;\
      \
      if (f_dt_ptr->data_list.count != 0)\
      {\
        TrieState *f_state_ptr = nullptr;\
        TrieState *s_state_ptr = nullptr;\
        \
        TrieIterator *f_iter_ptr = nullptr;\
        TrieIterator *s_iter_ptr = nullptr;\
        \
        /* - ERROR - */\
        if ((f_state_ptr = trie_root(f_dt_ptr->trie_ptr)) == nullptr ||\
            (s_state_ptr = trie_root(s_dt_ptr->trie_ptr)) == nullptr ||\
            (f_iter_ptr = trie_iterator_new(f_state_ptr)) == nullptr ||\
            (s_iter_ptr = trie_iterator_new(s_state_ptr)) == nullptr)\
        {\
          if (f_iter_ptr != nullptr) trie_iterator_free(f_iter_ptr);\
          if (s_iter_ptr != nullptr) trie_iterator_free(s_iter_ptr);\
          if (f_state_ptr != nullptr) trie_state_free(f_state_ptr);\
          if (s_state_ptr != nullptr) trie_state_free(s_state_ptr);\
          \
          exception_s::throw_exception(it,module.error_base + c_error_DATRIE_ITERATOR_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
          return false;\
        }\
        \
        while (trie_iterator_next(f_iter_ptr) &&\
               trie_iterator_next(s_iter_ptr))\
        {\
          AlphaChar *f_key = trie_iterator_get_key(f_iter_ptr);\
          AlphaChar *s_key = trie_iterator_get_key(s_iter_ptr);\
          \
          /* - compare keys - */\
          AlphaChar *f_key_ptr = f_key;\
          AlphaChar *s_key_ptr = s_key;\
          do {\
            if (*f_key_ptr != *s_key_ptr)\
            {\
              result = *f_key_ptr < *s_key_ptr ? -1 : 1;\
              break;\
            }\
          } while(++s_key_ptr,*f_key_ptr++ != 0);\
          \
          cfree(f_key);\
          cfree(s_key);\
          \
          if (result != 0) {\
            break;\
          }\
          \
          location_s *f_value = (location_s *)f_dt_ptr->data_list[trie_iterator_get_data(f_iter_ptr)];\
          location_s *s_value = (location_s *)s_dt_ptr->data_list[trie_iterator_get_data(s_iter_ptr)];\
          \
          /* - compare values - */\
          BIC_CALL_COMPARE(it,f_value,s_value,SOURCE_POS,\
            trie_iterator_free(f_iter_ptr);\
            trie_iterator_free(s_iter_ptr);\
            trie_state_free(f_state_ptr);\
            trie_state_free(s_state_ptr);\
            \
            return false\
          );\
          \
          if (result != 0) {\
            break;\
          }\
        }\
        \
        trie_iterator_free(f_iter_ptr);\
        trie_iterator_free(s_iter_ptr);\
        trie_state_free(f_state_ptr);\
        trie_state_free(s_state_ptr);\
      }\
    }\
  }\
  else\
  {\
    result = c_bi_class_datrie < src_0_location->v_type ? -1 : 1;\
  }\
}/*}}}*/

#define BIC_DATRIE_APPEND_ARRAY(SRC_LOCATION,TARGET_PTR) \
{/*{{{*/\
  pointer_array_s *source_ptr = (pointer_array_s *)SRC_LOCATION->v_data_ptr;\
  \
  /* - ERROR - */\
  if (source_ptr->used & 1)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_DATRIE_SOURCE_NOT_DIVISIBLE_BY_TWO,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
  \
  if (source_ptr->used != 0)\
  {\
    pointer *ptr = source_ptr->data;\
    pointer *ptr_end = ptr + source_ptr->used;\
    \
    do\
    {\
      location_s *key_location = it.get_location_value(ptr[0]);\
      location_s *val_location = it.get_location_value(ptr[1]);\
      \
      /* - ERROR - */\
      if (key_location->v_type != c_rm_class_unicode_string)\
      {\
        exception_s::throw_exception(it,module.error_base + c_error_DATRIE_INVALID_KEY_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
        return false;\
      }\
      \
      ui_array_s *ustring_ptr = (ui_array_s *)key_location->v_data_ptr;\
      \
      val_location->v_reference_cnt.atomic_inc();\
      TrieData index = TARGET_PTR->data_list.append(val_location);\
      \
      if (!trie_store_if_absent(TARGET_PTR->trie_ptr,ustring_ptr->data,index))\
      {\
        /* - ERROR - */\
        TrieData old_index;\
        if (!trie_retrieve(TARGET_PTR->trie_ptr,ustring_ptr->data,&old_index))\
        {\
          TARGET_PTR->data_list.remove(index);\
          it.release_location_ptr(val_location);\
          \
          exception_s::throw_exception(it,module.error_base + c_error_DATRIE_RETRIEVE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
          return false;\
        }\
        \
        it.release_location_ptr((location_s *)TARGET_PTR->data_list[old_index]);\
        TARGET_PTR->data_list.remove(old_index);\
        \
        /* - ERROR - */\
        if (!trie_store(TARGET_PTR->trie_ptr,ustring_ptr->data,index))\
        {\
          TARGET_PTR->data_list.remove(index);\
          it.release_location_ptr(val_location);\
          \
          exception_s::throw_exception(it,module.error_base + c_error_DATRIE_STORE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
          return false;\
        }\
      }\
    }\
    while((ptr += 2) < ptr_end);\
  }\
}/*}}}*/

#define BIC_DATRIE_APPEND_ITERABLE_BODY(TARGET_PTR) \
{/*{{{*/\
  key_location->v_reference_cnt.atomic_inc();\
  val_location->v_reference_cnt.atomic_inc();\
  \
  it.release_location_ptr(key_reference);\
  it.release_location_ptr(val_reference);\
  \
  /* - ERROR - */\
  if (key_location->v_type != c_rm_class_unicode_string)\
  {\
    it.release_location_ptr(key_location);\
    it.release_location_ptr(val_location);\
    \
    exception_s::throw_exception(it,module.error_base + c_error_DATRIE_INVALID_KEY_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
  \
  ui_array_s *ustring_ptr = (ui_array_s *)key_location->v_data_ptr;\
  \
  TrieData index = TARGET_PTR->data_list.append(val_location);\
  \
  if (!trie_store_if_absent(TARGET_PTR->trie_ptr,ustring_ptr->data,index))\
  {\
    /* - ERROR - */\
    TrieData old_index;\
    if (!trie_retrieve(TARGET_PTR->trie_ptr,ustring_ptr->data,&old_index))\
    {\
      TARGET_PTR->data_list.remove(index);\
      it.release_location_ptr(key_location);\
      it.release_location_ptr(val_location);\
      \
      exception_s::throw_exception(it,module.error_base + c_error_DATRIE_RETRIEVE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      return false;\
    }\
    \
    it.release_location_ptr((location_s *)TARGET_PTR->data_list[old_index]);\
    TARGET_PTR->data_list.remove(old_index);\
    \
    /* - ERROR - */\
    if (!trie_store(TARGET_PTR->trie_ptr,ustring_ptr->data,index))\
    {\
      TARGET_PTR->data_list.remove(index);\
      it.release_location_ptr(key_location);\
      it.release_location_ptr(val_location);\
      \
      exception_s::throw_exception(it,module.error_base + c_error_DATRIE_STORE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      return false;\
    }\
  }\
  \
  it.release_location_ptr(key_location);\
}/*}}}*/

#define BIC_DATRIE_APPEND_ITERABLE(SRC_LOCATION,TARGET_PTR) \
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
    location_s *key_reference;\
    location_s *key_location;\
    location_s *val_reference;\
    location_s *val_location;\
    \
    BIC_CALL_FIRST_IDX(it,SRC_LOCATION,index,operands[c_source_pos_idx],return false;);\
    \
    while (index != c_idx_not_exist)\
    {\
      BIC_CALL_ITEM(it,SRC_LOCATION,index,key_reference,operands[c_source_pos_idx],return false;);\
      key_location = it.get_location_value(key_reference);\
      \
      BIC_CALL_NEXT_IDX(it,SRC_LOCATION,index,index,operands[c_source_pos_idx],\
                        it.release_location_ptr(key_reference);\
                        return false;\
                       );\
      \
      /* - ERROR - */\
      if (index == c_idx_not_exist)\
      {\
        it.release_location_ptr(key_reference);\
        \
        exception_s::throw_exception(it,module.error_base + c_error_DATRIE_SOURCE_NOT_DIVISIBLE_BY_TWO,operands[c_source_pos_idx],(location_s *)it.blank_location);\
        return false;\
      }\
      \
      BIC_CALL_ITEM(it,SRC_LOCATION,index,val_reference,operands[c_source_pos_idx],\
                    it.release_location_ptr(key_reference);\
                    return false;\
                   );\
      val_location = it.get_location_value(val_reference);\
      \
      BIC_DATRIE_APPEND_ITERABLE_BODY(TARGET_PTR);\
      \
      BIC_CALL_NEXT_IDX(it,SRC_LOCATION,index,index,operands[c_source_pos_idx],return false;);\
    }\
  }\
  else if (iter_type == c_iter_next_item)\
  {\
    location_s *key_reference;\
    location_s *key_location;\
    location_s *val_reference;\
    location_s *val_location;\
    \
    do\
    {\
      BIC_CALL_NEXT_ITEM(it,SRC_LOCATION,key_reference,operands[c_source_pos_idx],return false;);\
      key_location = it.get_location_value(key_reference);\
      \
      if (key_location->v_type == c_bi_class_blank)\
      {\
        it.release_location_ptr(key_reference);\
        break;\
      }\
      \
      BIC_CALL_NEXT_ITEM(it,SRC_LOCATION,val_reference,operands[c_source_pos_idx],\
                         it.release_location_ptr(key_reference);\
                         \
                         exception_s::throw_exception(it,module.error_base + c_error_DATRIE_SOURCE_NOT_DIVISIBLE_BY_TWO,operands[c_source_pos_idx],(location_s *)it.blank_location);\
                         return false;\
                        );\
      val_location = it.get_location_value(val_reference);\
      \
      BIC_DATRIE_APPEND_ITERABLE_BODY(TARGET_PTR);\
      \
    }\
    while(true);\
  }\
  else\
  {\
    cassert(0);\
  }\
}/*}}}*/

void bic_datrie_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_datrie_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (datrie_s *)nullptr;
}/*}}}*/

void bic_datrie_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  datrie_s *dt_ptr = (datrie_s *)location_ptr->v_data_ptr;

  // - if datrie exists -
  if (dt_ptr != nullptr)
  {
    dt_ptr->clear(it);
    cfree(dt_ptr);
  }
}/*}}}*/

bool bic_datrie_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_datrie_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_DATRIE_COMPARE(operands[c_source_pos_idx]);
  result = result == 0;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_datrie_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_DATRIE_COMPARE(operands[c_source_pos_idx]);
  result = result != 0;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_datrie_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_rm_class_unicode_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_le_br_re_br#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  datrie_s *dt_ptr = (datrie_s *)dst_location->v_data_ptr;
  ui_array_s *ustring_ptr = (ui_array_s *)src_0_location->v_data_ptr;

  TrieData index;

  // - key does not exist -
  if (!trie_retrieve(dt_ptr->trie_ptr,ustring_ptr->data,&index))
  {
    location_s *value_location = it.get_new_location_ptr();
    value_location->v_type = c_bi_class_blank;
    value_location->v_reference_cnt.atomic_set(1);

    index = dt_ptr->data_list.append(value_location);

    // - ERROR -
    if (!trie_store(dt_ptr->trie_ptr,ustring_ptr->data,index))
    {
      dt_ptr->data_list.remove(index);
      it.release_location_ptr(value_location);

      exception_s::throw_exception(it,module.error_base + c_error_DATRIE_STORE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }
  }

  pointer *value_location = &dt_ptr->data_list[index];
  location_s *new_ref_location = it.get_new_reference((location_s **)value_location);

  BIC_SET_RESULT(new_ref_location);

  return true;
}/*}}}*/

bool bic_datrie_method_Datrie_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_datrie_alpha_map)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Datrie#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  AlphaMap *am_ptr = (AlphaMap *)src_0_location->v_data_ptr;

  // - ERROR -
  Trie *trie_ptr;
  if ((trie_ptr = trie_new(am_ptr)) == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_DATRIE_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create datrie object -
  datrie_s *dt_ptr = (datrie_s *)cmalloc(sizeof(datrie_s));
  dt_ptr->init();

  dt_ptr->trie_ptr = trie_ptr;

  // - set reference to alpha map -
  src_0_location->v_reference_cnt.atomic_inc();
  dt_ptr->alpha_map_loc = src_0_location;

  // - set destination data pointer -
  dst_location->v_data_ptr = (datrie_s *)dt_ptr;

  return true;
}/*}}}*/

bool bic_datrie_method_Datrie_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_datrie_alpha_map)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Datrie#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  AlphaMap *am_ptr = (AlphaMap *)src_0_location->v_data_ptr;

  // - ERROR -
  Trie *trie_ptr;
  if ((trie_ptr = trie_new(am_ptr)) == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_DATRIE_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create datrie object -
  datrie_s *dt_ptr = (datrie_s *)cmalloc(sizeof(datrie_s));
  dt_ptr->init();

  dt_ptr->trie_ptr = trie_ptr;

  // - set reference to alpha map -
  src_0_location->v_reference_cnt.atomic_inc();
  dt_ptr->alpha_map_loc = src_0_location;

  // - set destination data pointer -
  dst_location->v_data_ptr = (datrie_s *)dt_ptr;

  // - construct container from array -
  if (src_1_location->v_type == c_bi_class_array)
  {
    BIC_DATRIE_APPEND_ARRAY(src_1_location,dt_ptr);
  }

  // - construct container from iterable -
  else
  {
    BIC_DATRIE_APPEND_ITERABLE(src_1_location,dt_ptr);
  }

  return true;
}/*}}}*/

bool bic_datrie_method_keys_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  datrie_s *dt_ptr = (datrie_s *)dst_location->v_data_ptr;

  // - ERROR -
  TrieState *state_ptr = trie_root(dt_ptr->trie_ptr);
  if (state_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_DATRIE_ITERATOR_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  TrieIterator *iter_ptr = trie_iterator_new(state_ptr);
  if (iter_ptr == nullptr)
  {
    trie_state_free(state_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_DATRIE_ITERATOR_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  pointer_array_s *array_ptr = it.get_new_array_ptr();
  BIC_CREATE_NEW_LOCATION(array_location,c_bi_class_array,array_ptr);

  while (trie_iterator_next(iter_ptr))
  {
    ui_array_s *ustring_ptr = (ui_array_s *)cmalloc(sizeof(ui_array_s));
    ustring_ptr->data = trie_iterator_get_key(iter_ptr);

    /* - retrieve key string size - */
    unsigned *c_ptr = ustring_ptr->data;
    while (*c_ptr++ != 0) {};

    ustring_ptr->size = c_ptr - ustring_ptr->data;
    ustring_ptr->used = ustring_ptr->size;

    BIC_CREATE_NEW_LOCATION(new_location,c_rm_class_unicode_string,ustring_ptr);
    array_ptr->push(new_location);
  }

  trie_iterator_free(iter_ptr);
  trie_state_free(state_ptr);

  BIC_SET_RESULT(array_location);

  return true;
}/*}}}*/

bool bic_datrie_method_items_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  datrie_s *dt_ptr = (datrie_s *)dst_location->v_data_ptr;

  // - ERROR -
  TrieState *state_ptr = trie_root(dt_ptr->trie_ptr);
  if (state_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_DATRIE_ITERATOR_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  TrieIterator *iter_ptr = trie_iterator_new(state_ptr);
  if (iter_ptr == nullptr)
  {
    trie_state_free(state_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_DATRIE_ITERATOR_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  pointer_array_s *array_ptr = it.get_new_array_ptr();
  BIC_CREATE_NEW_LOCATION(array_location,c_bi_class_array,array_ptr);

  while (trie_iterator_next(iter_ptr))
  {
    location_s *value_location = it.get_location_value(
        dt_ptr->data_list[trie_iterator_get_data(iter_ptr)]);

    value_location->v_reference_cnt.atomic_inc();
    array_ptr->push(value_location);
  }

  trie_iterator_free(iter_ptr);
  trie_state_free(state_ptr);

  BIC_SET_RESULT(array_location);

  return true;
}/*}}}*/

bool bic_datrie_method_iterator_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  datrie_s *dt_ptr = (datrie_s *)dst_location->v_data_ptr;

  // - ERROR -
  TrieState *state_ptr = trie_root(dt_ptr->trie_ptr);
  if (state_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_DATRIE_ITERATOR_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  TrieIterator *iter_ptr = trie_iterator_new(state_ptr);
  if (iter_ptr == nullptr)
  {
    trie_state_free(state_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_DATRIE_ITERATOR_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create datrie_iterator object -
  datrie_iterator_s *di_ptr = (datrie_iterator_s *)cmalloc(sizeof(datrie_iterator_s));
  di_ptr->init();

  dst_location->v_reference_cnt.atomic_inc();
  di_ptr->datrie_loc = dst_location;

  di_ptr->state_ptr = state_ptr;
  di_ptr->iter_ptr = iter_ptr;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_datrie_iterator,di_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_datrie_method_has_key_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_DATRIE_METHOD_CONTAIN("has_key#1");
}/*}}}*/

bool bic_datrie_method_remove_key_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_rm_class_unicode_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("remove_key#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  datrie_s *dt_ptr = (datrie_s *)dst_location->v_data_ptr;
  ui_array_s *ustring_ptr = (ui_array_s *)src_0_location->v_data_ptr;

  // - key does exist -
  TrieData index;
  if (trie_retrieve(dt_ptr->trie_ptr,ustring_ptr->data,&index))
  {
    trie_delete(dt_ptr->trie_ptr,ustring_ptr->data);

    // - remove value location -
    it.release_location_ptr((location_s *)dt_ptr->data_list[index]);
    dt_ptr->data_list.remove(index);
  }

  // - ERROR -
  else
  {
    exception_s::throw_exception(it,module.error_base + c_error_DATRIE_INVALID_KEY,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_datrie_method_contain_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_DATRIE_METHOD_CONTAIN("contain#1");
}/*}}}*/

bool bic_datrie_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_DATRIE_COMPARE(operands[c_source_pos_idx]);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_datrie_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((datrie_s *)dst_location->v_data_ptr)->data_list.count;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_datrie_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Datrie"),"Datrie");
  );

  return true;
}/*}}}*/

bool bic_datrie_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Datrie");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class DATRIE_ITERATOR -
built_in_class_s datrie_iterator_class =
{/*{{{*/
  "DatrieIterator",
  c_modifier_public | c_modifier_final,
  6, datrie_iterator_methods,
  0, datrie_iterator_variables,
  bic_datrie_iterator_consts,
  bic_datrie_iterator_init,
  bic_datrie_iterator_clear,
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

built_in_method_s datrie_iterator_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_datrie_iterator_operator_binary_equal
  },
  {
    "key#0",
    c_modifier_public | c_modifier_final,
    bic_datrie_iterator_method_key_0
  },
  {
    "value#0",
    c_modifier_public | c_modifier_final,
    bic_datrie_iterator_method_value_0
  },
  {
    "next_item#0",
    c_modifier_public | c_modifier_final,
    bic_datrie_iterator_method_next_item_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_datrie_iterator_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_datrie_iterator_method_print_0
  },
};/*}}}*/

built_in_variable_s datrie_iterator_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_DATRIE_ITERATOR_METHOD_KEY() \
{/*{{{*/\
  ui_array_s *ustring_ptr = (ui_array_s *)cmalloc(sizeof(ui_array_s));\
  ustring_ptr->data = trie_iterator_get_key(di_ptr->iter_ptr);\
  \
  /* - retrieve key string size - */\
  unsigned *c_ptr = ustring_ptr->data;\
  while (*c_ptr++ != 0) {};\
  \
  ustring_ptr->size = c_ptr - ustring_ptr->data;\
  ustring_ptr->used = ustring_ptr->size;\
  \
  BIC_CREATE_NEW_LOCATION(new_location,c_rm_class_unicode_string,ustring_ptr);\
  BIC_SET_RESULT(new_location);\
}/*}}}*/

void bic_datrie_iterator_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_datrie_iterator_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (datrie_iterator_s *)nullptr;
}/*}}}*/

void bic_datrie_iterator_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  datrie_iterator_s *di_ptr = (datrie_iterator_s *)location_ptr->v_data_ptr;

  if (di_ptr != nullptr)
  {
    di_ptr->clear(it);
    cfree(di_ptr);
  }
}/*}}}*/

bool bic_datrie_iterator_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_datrie_iterator_method_key_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  datrie_iterator_s *di_ptr = (datrie_iterator_s *)dst_location->v_data_ptr;

  BIC_DATRIE_ITERATOR_METHOD_KEY();

  return true;
}/*}}}*/

bool bic_datrie_iterator_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  datrie_iterator_s *di_ptr = (datrie_iterator_s *)dst_location->v_data_ptr;
  datrie_s *dt_ptr = (datrie_s *)di_ptr->datrie_loc->v_data_ptr;

  pointer *value_location = &dt_ptr->data_list[trie_iterator_get_data(di_ptr->iter_ptr)];
  location_s *new_ref_location = it.get_new_reference((location_s **)value_location);

  BIC_SET_RESULT(new_ref_location);

  return true;
}/*}}}*/

bool bic_datrie_iterator_method_next_item_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  datrie_iterator_s *di_ptr = (datrie_iterator_s *)dst_location->v_data_ptr;

  if (trie_iterator_next(di_ptr->iter_ptr))
  {
    BIC_DATRIE_ITERATOR_METHOD_KEY();
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_datrie_iterator_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("DatrieIterator"),"DatrieIterator");
  );

  return true;
}/*}}}*/

bool bic_datrie_iterator_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("DatrieIterator");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

