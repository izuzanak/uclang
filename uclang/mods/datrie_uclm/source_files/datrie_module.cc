
@begin
include "datrie_module.h"
@end

// - DATRIE indexes of built in classes -
unsigned c_bi_class_datrie_alpha_map = c_idx_not_exist;
unsigned c_bi_class_datrie = c_idx_not_exist;

// - DATRIE indexes of remote classes -
unsigned c_rm_class_unicode_char = c_idx_not_exist;
unsigned c_rm_class_unicode_string = c_idx_not_exist;

// - DATRIE module -
built_in_module_s module =
{/*{{{*/
  2,                      // Class count
  datrie_classes,         // Classes

  0,                      // Error base index
  4,                      // Error count
  datrie_error_strings,   // Error strings

  datrie_initialize,      // Initialize function
  datrie_print_exception, // Print exceptions function
};/*}}}*/

// - DATRIE classes -
built_in_class_s *datrie_classes[] =
{/*{{{*/
  &datrie_alpha_map_class,
  &datrie_class,
};/*}}}*/

// - DATRIE error strings -
const char *datrie_error_strings[] =
{/*{{{*/
  "error_DATRIE_ALPHA_MAP_CREATE_ERROR",
  "error_DATRIE_ALPHA_MAP_ADD_RANGE_ERROR",
  "error_DATRIE_CREATE_ERROR",
  "error_DATRIE_STORE_ERROR",
};/*}}}*/

// - DATRIE initialize -
bool datrie_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize datrie_alpha_map class identifier -
  c_bi_class_datrie_alpha_map = class_base_idx++;

  // - initialize datrie class identifier -
  c_bi_class_datrie = class_base_idx++;

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
  6, datrie_methods,
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
    "Datrie#1",
    c_modifier_public | c_modifier_final,
    bic_datrie_method_Datrie_1
  },
  {
    "store#2",
    c_modifier_public | c_modifier_final,
    bic_datrie_method_store_2
  },
  {
    "retrieve#1",
    c_modifier_public | c_modifier_final,
    bic_datrie_method_retrieve_1
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

  // - if xml node exists -
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

bool bic_datrie_method_store_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  if (src_0_location->v_type != c_rm_class_unicode_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("store#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  datrie_s *dt_ptr = (datrie_s *)dst_location->v_data_ptr;
  ui_array_s *ustring_ptr = (ui_array_s *)src_0_location->v_data_ptr;

  // - key already exists -
  TrieData index;
  if (trie_retrieve(dt_ptr->trie_ptr,ustring_ptr->data,&index))
  {
    pointer &data_ptr = dt_ptr->data_list[index];

    // - release old value -
    it.release_location_ptr((location_s *)data_ptr);

    // - set new value -
    src_1_location->v_reference_cnt.atomic_inc();
    data_ptr = src_1_location;
  }

  // - key does not exist -
  else
  {
    unsigned new_index = dt_ptr->data_list.append(src_1_location);

    // - ERROR -
    if (!trie_store(dt_ptr->trie_ptr,ustring_ptr->data,new_index))
    {
      dt_ptr->data_list.remove(new_index);

      exception_s::throw_exception(it,module.error_base + c_error_DATRIE_STORE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    src_1_location->v_reference_cnt.atomic_inc();
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_datrie_method_retrieve_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_rm_class_unicode_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("retrieve#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  datrie_s *dt_ptr = (datrie_s *)dst_location->v_data_ptr;
  ui_array_s *ustring_ptr = (ui_array_s *)src_0_location->v_data_ptr;

  // - key exists -
  TrieData index;
  if (trie_retrieve(dt_ptr->trie_ptr,ustring_ptr->data,&index))
  {
    location_s *item_location = it.get_location_value((location_s *)dt_ptr->data_list[index]);

    item_location->v_reference_cnt.atomic_inc();
    BIC_SET_RESULT(item_location);
  }

  // - key does not exist -
  else
  {
    BIC_SET_RESULT_BLANK();
  }

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

