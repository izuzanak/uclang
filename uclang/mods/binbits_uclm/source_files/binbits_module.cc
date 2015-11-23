
@begin
include "binbits_module.h"
@end

// - BINBITS indexes of built in classes -
unsigned c_bi_class_bin_array = c_idx_not_exist;
unsigned c_bi_class_bin_array_ref = c_idx_not_exist;

// - BINBITS module -
built_in_module_s module =
{/*{{{*/
  2,                       // Class count
  binbits_classes,         // Classes

  0,                       // Error base index
  1,                       // Error count
  binbits_error_strings,   // Error strings

  binbits_initialize,      // Initialize function
  binbits_print_exception, // Print exceptions function
};/*}}}*/

// - BINBITS classes -
built_in_class_s *binbits_classes[] =
{/*{{{*/
  &bin_array_class,
  &bin_array_ref_class,
};/*}}}*/

// - BINBITS error strings -
const char *binbits_error_strings[] =
{/*{{{*/
  "error_BIN_ARRAY_DUMMY_ERROR",
};/*}}}*/

// - BINBITS initialize -
bool binbits_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize bin_array class identifier -
  c_bi_class_bin_array = class_base_idx++;

  // - initialize bin_array_ref class identifier -
  c_bi_class_bin_array_ref = class_base_idx++;

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
  case c_error_BIN_ARRAY_DUMMY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nBinary array dummy error\n");
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
  16, bin_array_methods,
  2, bin_array_variables,
  bic_bin_array_consts,
  bic_bin_array_init,
  bic_bin_array_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s bin_array_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_bin_array_operator_binary_equal
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
  { "TYPE_INT32",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_UINT32", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

#define BIC_BIN_ARRAY_GET_USED() \
  /*{{{*/\
  bin_array_s *ba_ptr = (bin_array_s *)((location_s *)dst_location)->v_data_ptr;\
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
  default:\
    cassert(0);\
  }\
  /*}}}*/

#define BIC_BIN_ARRAY_CHECK_INDEX() \
  /*{{{*/\
  BIC_BIN_ARRAY_GET_USED();\
  \
  /* - ERROR - */\
  if (index < 0 || index >= used)\
  {\
    /* FIXME TODO throw proper exception */\
    BIC_TODO_ERROR(__FILE__,__LINE__);\
    return false;\
  }\
  /*}}}*/

#define BIC_BIN_ARRAY_ITEM(NAME) \
  {/*{{{*/\
    pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
    pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
    location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
    \
    long long int index;\
    \
    /* - ERROR - */\
    if (!it.retrieve_integer(src_0_location,index))\
    {\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
      \
      return false;\
    }\
    \
    BIC_BIN_ARRAY_CHECK_INDEX();\
    \
    /* - create bin array reference - */\
    bin_array_ref_s *bar_ptr = ba_ptr->create_reference((location_s *)dst_location,index);\
    \
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_bin_array_ref,bar_ptr);\
    BIC_SET_RESULT(new_location);\
  }/*}}}*/

void bic_bin_array_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert binary array type constants -
  {
    const_locations.push_blanks(2);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 2);

#define CREATE_BIN_ARRAY_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (basic_64b)VALUE;\
  cv_ptr++;

    CREATE_BIN_ARRAY_TYPE_BIC_STATIC(c_bin_array_type_int32);
    CREATE_BIN_ARRAY_TYPE_BIC_STATIC(c_bin_array_type_uint32);
  }

}/*}}}*/

void bic_bin_array_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)NULL;
}/*}}}*/

void bic_bin_array_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  bin_array_s *ba_ptr = (bin_array_s *)location_ptr->v_data_ptr;

  if (ba_ptr != NULL)
  {
    ba_ptr->clear(it);
    cfree(ba_ptr);
  }
}/*}}}*/

bool bic_bin_array_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_bin_array_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_BIN_ARRAY_ITEM("item#1");

  return true;
}/*}}}*/

bool bic_bin_array_method_BinArray_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int type;

  if (!it.retrieve_integer(src_0_location,type))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("BinArray#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - binary array container pointer -
  void *cont = NULL;

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

  // - ERROR -
  default:
    
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  // - create binary array object -
  bin_array_s *ba_ptr = (bin_array_s *)cmalloc(sizeof(bin_array_s));
  ba_ptr->init();

  ba_ptr->type = type;
  ba_ptr->cont = cont;

  dst_location->v_data_ptr = (basic_64b)ba_ptr;

  return true;
}/*}}}*/

bool bic_bin_array_method_clear_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
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
  default:
    cassert(0);
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_bin_array_method_resize_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int new_size;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,new_size))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("resize#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  bin_array_s *ba_ptr = (bin_array_s *)dst_location->v_data_ptr;

#define BIC_BIN_ARRAY_RESIZE(ARRAY_TYPE,TYPE) \
{/*{{{*/\
  ARRAY_TYPE *array_ptr = (ARRAY_TYPE *)ba_ptr->cont;\
\
  /* - ERROR - */\
  if (array_ptr->used > new_size)\
  {\
    /* FIXME TODO throw proper exception */\
    BIC_TODO_ERROR(__FILE__,__LINE__);\
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
      BIC_BIN_ARRAY_RESIZE(bi_array_s,int);
    }/*}}}*/
    break;
  case c_bin_array_type_uint32:
    {/*{{{*/
      BIC_BIN_ARRAY_RESIZE(ui_array_s,unsigned);
    }/*}}}*/
    break;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_bin_array_method_push_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  bin_array_s *ba_ptr = (bin_array_s *)dst_location->v_data_ptr;

  switch (ba_ptr->type)
  {
  case c_bin_array_type_int32:
  case c_bin_array_type_uint32:
    {
      long long int value;

      // - ERROR -
      if (!it.retrieve_integer(src_0_location,value))
      {
        // FIXME TODO throw proper exception
        BIC_TODO_ERROR(__FILE__,__LINE__);
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
    }
    break;
  default:
    cassert(0);
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_bin_array_method_pop_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  bin_array_s *ba_ptr = (bin_array_s *)dst_location->v_data_ptr;

  switch (ba_ptr->type)
  {
  case c_bin_array_type_int32:
    {/*{{{*/
      bi_array_s *array_ptr = (bi_array_s *)ba_ptr->cont;

      // - ERROR -
      if (array_ptr->used == 0)
      {
        // FIXME TODO throw proper exception
        BIC_TODO_ERROR(__FILE__,__LINE__);
        return false;
      }

      long long int result = array_ptr->pop();
      BIC_SIMPLE_SET_RES(c_bi_class_integer,result);
    }/*}}}*/
    break;
  case c_bin_array_type_uint32:
    {/*{{{*/
      ui_array_s *array_ptr = (ui_array_s *)ba_ptr->cont;

      // - ERROR -
      if (array_ptr->used == 0)
      {
        // FIXME TODO throw proper exception
        BIC_TODO_ERROR(__FILE__,__LINE__);
        return false;
      }

      long long int result = array_ptr->pop();
      BIC_SIMPLE_SET_RES(c_bi_class_integer,result);
    }/*}}}*/
    break;
  default:
    cassert(0);
  }

  return true;
}/*}}}*/

bool bic_bin_array_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_BIN_ARRAY_ITEM("item#1");

  return true;
}/*}}}*/

bool bic_bin_array_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  BIC_BIN_ARRAY_GET_USED();

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
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  BIC_BIN_ARRAY_GET_USED();

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
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int index;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,index))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("next_idx#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

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
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int index;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,index))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("prev_idx#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

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
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
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
  default:
    cassert(0);
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_bin_array_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  bin_array_s *ba_ptr = (bin_array_s *)dst_location->v_data_ptr;

  string_array_s strings;
  strings.init();

  unsigned strings_size = 0;

#define BIC_BIN_ARRAY_TO_STRING(ARRAY_TYPE,TYPE,FORMAT) \
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
    BIC_BIN_ARRAY_TO_STRING(bi_array_s,int,"%d")
    break;
  case c_bin_array_type_uint32:
    BIC_BIN_ARRAY_TO_STRING(ui_array_s,unsigned,"%u")
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
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("to_string#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  bin_array_s *ba_ptr = (bin_array_s *)dst_location->v_data_ptr;
  string_s *del_string_ptr = (string_s *)src_0_location->v_data_ptr;

  string_array_s strings;
  strings.init();

  unsigned strings_size = 0;

  switch (ba_ptr->type)
  {
  case c_bin_array_type_int32:
    BIC_BIN_ARRAY_TO_STRING(bi_array_s,int,"%d")
    break;
  case c_bin_array_type_uint32:
    BIC_BIN_ARRAY_TO_STRING(ui_array_s,unsigned,"%u")
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
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  bin_array_s *ba_ptr = (bin_array_s *)dst_location->v_data_ptr;

  putchar('[');

#define BIC_BIN_ARRAY_PRINT(ARRAY_TYPE,TYPE,FORMAT) \
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
    BIC_BIN_ARRAY_PRINT(bi_array_s,int,"%d")
    break;
  case c_bin_array_type_uint32:
    BIC_BIN_ARRAY_PRINT(ui_array_s,unsigned,"%u")
    break;
  default:
    cassert(0);
  }

  putchar(']');

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class BIN_ARRAY_REF -
built_in_class_s bin_array_ref_class =
{/*{{{*/
  "BinArrayRef",
  c_modifier_public | c_modifier_final,
  3, bin_array_ref_methods,
  0, bin_array_ref_variables,
  bic_bin_array_ref_consts,
  bic_bin_array_ref_init,
  bic_bin_array_ref_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s bin_array_ref_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_bin_array_ref_operator_binary_equal
  },

  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_bin_array_ref_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
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
  location_ptr->v_data_ptr = (basic_64b)NULL;
}/*}}}*/

void bic_bin_array_ref_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  bin_array_ref_s *bar_ptr = (bin_array_ref_s *)location_ptr->v_data_ptr;

  if (bar_ptr != NULL)
  {
    ((bin_array_s *)bar_ptr->ba_location->v_data_ptr)->release_reference(it,bar_ptr);
  }
}/*}}}*/

bool bic_bin_array_ref_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_bin_array_ref_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("BinArrayRef"),"BinArrayRef");
  );

  return true;
}/*}}}*/

bool bic_bin_array_ref_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("BinArrayRef");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

