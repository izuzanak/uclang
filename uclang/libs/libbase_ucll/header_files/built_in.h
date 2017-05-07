
#ifndef __BUILD_IN_H
#define __BUILD_IN_H

// - count of built in method names -
const unsigned c_built_in_method_cnt = 49;

// - indexes of built in methods -
enum
{/*{{{*/

  c_operator_binary_equal,
  c_operator_binary_plus_equal,
  c_operator_binary_minus_equal,
  c_operator_binary_asterisk_equal,
  c_operator_binary_slash_equal,
  c_operator_binary_percent_equal,
  c_operator_binary_double_ls_br_equal,
  c_operator_binary_double_rs_br_equal,
  c_operator_binary_ampersand_equal,
  c_operator_binary_pipe_equal,
  c_operator_binary_circumflex_equal,
  c_operator_binary_double_ampersand,
  c_operator_binary_double_pipe,
  c_operator_binary_ampersand,
  c_operator_binary_pipe,
  c_operator_binary_circumflex,
  c_operator_binary_double_equal,
  c_operator_binary_exclamation_equal,
  c_operator_binary_rs_br,
  c_operator_binary_ls_br,
  c_operator_binary_rs_br_equal,
  c_operator_binary_ls_br_equal,
  c_operator_binary_double_rs_br,
  c_operator_binary_double_ls_br,
  c_operator_binary_plus,
  c_operator_binary_minus,
  c_operator_binary_asterisk,
  c_operator_binary_slash,
  c_operator_binary_percent,
  c_operator_unary_post_double_plus,
  c_operator_unary_post_double_minus,
  c_operator_unary_pre_double_plus,
  c_operator_unary_pre_double_minus,
  c_operator_unary_pre_plus,
  c_operator_unary_pre_minus,
  c_operator_unary_pre_exclamation,
  c_operator_unary_pre_tilde,
  c_operator_binary_le_br_re_br,

  c_built_in_method_contain_1,
  c_built_in_method_compare_1,
  c_built_in_method_item_1,
  c_built_in_method_first_idx_0,
  c_built_in_method_last_idx_0,
  c_built_in_method_next_idx_1,
  c_built_in_method_prev_idx_1,
  c_built_in_method_next_item_0,

  c_built_in_method_length_0,
  c_built_in_method_to_string_0,
  c_built_in_method_print_0
};/*}}}*/

// - names of built in methods -
extern const char *c_built_in_method_symbol_names[];

// - indexes of built in method names -
extern unsigned c_built_in_method_idxs[];

// - indexes of built in classes -
enum
{/*{{{*/

  c_bi_class_blank = 0,
  c_bi_class_char,
  c_bi_class_integer,
  c_bi_class_float,
  c_bi_class_string,
  c_bi_class_array,
  c_bi_class_error,
  c_bi_class_exception,
  c_bi_class_type,
  c_bi_class_mutex,
  c_bi_class_thread,
  c_bi_class_delegate,
  c_bi_class_buffer,

  c_bi_reference = 0xffffffff
};/*}}}*/

#define BIC_TODO_ERROR(FILE_NAME,LINE) \
  {/*{{{*/\
    string_s *string_ptr = it.get_new_string_ptr();\
    string_ptr->set(strlen(FILE_NAME),FILE_NAME);\
    \
    BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_string,string_ptr,0);\
    \
    exception_s *new_exception = exception_s::throw_exception(it,c_error_TODO_EXCEPTION,operands[c_source_pos_idx],new_location);\
    new_exception->params.push(LINE);\
  }/*}}}*/

// - create new location macros -
#define BIC_CREATE_NEW_LOCATION(NAME,CLASS_IDX,VALUE) \
  /*{{{*/\
  location_s *NAME = it.get_new_location_ptr();\
  NAME->v_type = CLASS_IDX;\
  NAME->v_reference_cnt.atomic_set(1);\
  NAME->v_data_ptr = (VALUE);\
  /*}}}*/

#define BIC_CREATE_NEW_LOCATION_REFS(NAME,CLASS_IDX,VALUE,REF_COUNT) \
  /*{{{*/\
  location_s *NAME = it.get_new_location_ptr();\
  NAME->v_type = CLASS_IDX;\
  NAME->v_reference_cnt.atomic_set(REF_COUNT);\
  NAME->v_data_ptr = (VALUE);\
  /*}}}*/

// - set destination macros -
#define BIC_SET_DESTINATION(LOCATION_PTR) \
  {/*{{{*/\
    it.release_location_ptr((location_s *)dst_location);\
    dst_location = (pointer)LOCATION_PTR;\
  }/*}}}*/

// - set result macros -
#define BIC_SET_RESULT(LOCATION_PTR) \
  {/*{{{*/\
    it.release_location_ptr((location_s *)res_location);\
    res_location = (pointer)LOCATION_PTR;\
  }/*}}}*/

#define BIC_SET_RESULT_BLANK() \
  {/*{{{*/\
    ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();\
    BIC_SET_RESULT(it.blank_location);\
  }/*}}}*/

#define BIC_SET_RESULT_DESTINATION() \
  {/*{{{*/\
    dst_location->v_reference_cnt.atomic_inc();\
    BIC_SET_RESULT(dst_location);\
  }/*}}}*/

#define BIC_SET_RESULT_STRING(VALUE) \
  {/*{{{*/\
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,(VALUE));\
    BIC_SET_RESULT(new_location);\
  }/*}}}*/

#define BIC_SIMPLE_SET_RES(CLASS_IDX,VALUE) \
  {/*{{{*/\
    if (((location_s *)res_location)->v_type == CLASS_IDX &&\
        ((location_s *)res_location)->v_reference_cnt.value() == 1)\
    {\
      ((location_s *)res_location)->v_data_ptr = (VALUE);\
    }\
    else {\
      BIC_CREATE_NEW_LOCATION(new_location,CLASS_IDX,VALUE);\
      BIC_SET_RESULT(new_location);\
    }\
  }/*}}}*/

#define BIC_SET_RESULT_CONT_INDEX(INDEX) \
  {/*{{{*/\
    if (INDEX != c_idx_not_exist)\
    {\
      BIC_SIMPLE_SET_RES(c_bi_class_integer,INDEX);\
    }\
    else {\
      BIC_SET_RESULT_BLANK();\
    }\
  }/*}}}*/

#define BIC_SIMPLE_SET_DST_AND_RES(CLASS_IDX,VALUE) \
  {/*{{{*/\
    if (((location_s *)dst_location)->v_reference_cnt.value() == 1)\
    {\
      ((location_s *)dst_location)->v_data_ptr = (VALUE);\
    }\
    else {\
      BIC_CREATE_NEW_LOCATION(new_location,CLASS_IDX,VALUE);\
      \
      ((location_s *)dst_location)->v_reference_cnt.atomic_dec();\
      dst_location = (pointer)new_location;\
    }\
    \
    if (((location_s *)res_location)->v_type == CLASS_IDX)\
    {\
      if (((location_s *)res_location)->v_reference_cnt.value() == 1)\
      {\
        ((location_s *)res_location)->v_data_ptr = (VALUE);\
      }\
      else\
      {\
        ((location_s *)res_location)->v_reference_cnt.atomic_dec();\
        ((location_s *)dst_location)->v_reference_cnt.atomic_inc();\
        res_location = dst_location;\
      }\
    }\
    else {\
      ((location_s *)dst_location)->v_reference_cnt.atomic_inc();\
      BIC_SET_RESULT(dst_location);\
    }\
  }/*}}}*/

// - exception push method index macros -
#define BIC_EXCEPTION_PUSH_METHOD_RI(NAME) \
  {/*{{{*/\
    unsigned name_idx = ((interpreter_s *)it.interpreter_ptr)->method_symbol_names.get_idx_char_ptr(strlen(NAME),NAME);\
    cassert(name_idx != c_idx_not_exist);\
    unsigned method_ri = ((interpreter_s *)it.interpreter_ptr)->class_records[((location_s *)dst_location)->v_type].mnri_map.map_name(name_idx);\
    cassert(method_ri != c_idx_not_exist);\
    \
    new_exception->params.push(method_ri);\
  }/*}}}*/

#define BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(IT,CLASS_IDX,NAME) \
  {/*{{{*/\
    unsigned name_idx = ((interpreter_s *)IT.interpreter_ptr)->method_symbol_names.get_idx_char_ptr(strlen(NAME),NAME);\
    cassert(name_idx != c_idx_not_exist);\
    unsigned method_ri = ((interpreter_s *)IT.interpreter_ptr)->class_records[CLASS_IDX].mnri_map.map_name(name_idx);\
    cassert(method_ri != c_idx_not_exist);\
    \
    new_exception->params.push(method_ri);\
  }/*}}}*/

// - methods to_string#0, to_string#1 macros -
#define BIC_TO_STRING(OPERATION) \
  {/*{{{*/\
    pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
    \
    string_s *string_ptr = it.get_new_string_ptr();\
    OPERATION;\
    \
    location_s *new_location = it.get_new_location_ptr();\
    new_location->v_type = c_bi_class_string;\
    new_location->v_reference_cnt.atomic_set(1);\
    new_location->v_data_ptr = (string_s *)string_ptr;\
    \
    it.release_location_ptr((location_s *)res_location);\
    res_location = (pointer)new_location;\
  }/*}}}*/

#define BIC_TO_STRING_WITHOUT_DEST(OPERATION) \
  {/*{{{*/\
    pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
    \
    string_s *string_ptr = it.get_new_string_ptr();\
    OPERATION;\
    \
    location_s *new_location = it.get_new_location_ptr();\
    new_location->v_type = c_bi_class_string;\
    new_location->v_reference_cnt.atomic_set(1);\
    new_location->v_data_ptr = (string_s *)string_ptr;\
    \
    it.release_location_ptr((location_s *)res_location);\
    res_location = (pointer)new_location;\
  }/*}}}*/

// - container finalize macros -
#define BIC_CONT_TO_STRING_0_CONSTRUCT() \
  {/*{{{*/\
    /* - adjust result string size - */\
    strings_size += 1 + (strings.used != 0 ? strings.used - 1 : 0) + 2;\
    \
    /* - create result string data - */\
    string_ptr->size = strings_size;\
    string_ptr->data = (char *)cmalloc(strings_size*sizeof(char));\
    \
    char *rs_ptr = string_ptr->data;\
    *rs_ptr++ = '[';\
    \
    if (strings.used != 0)\
    {\
      /* - strings cocatenation - */\
      string_s *s_ptr = strings.data;\
      string_s *s_ptr_end = s_ptr + strings.used;\
      \
      /* - copy first string - */\
      memcpy(rs_ptr,s_ptr->data,(s_ptr->size - 1)*sizeof(char));\
      rs_ptr += s_ptr->size - 1;\
      s_ptr++;\
      \
      if (s_ptr < s_ptr_end)\
      {\
        do\
        {\
          *rs_ptr++ = ',';\
          memcpy(rs_ptr,s_ptr->data,(s_ptr->size - 1)*sizeof(char));\
          rs_ptr += s_ptr->size - 1;\
        }\
        while(++s_ptr < s_ptr_end);\
      }\
    }\
    \
    *rs_ptr++ = ']';\
    *rs_ptr = '\0';\
  }/*}}}*/

#define BIC_CONT_TO_STRING_1_CONSTRUCT() \
  {/*{{{*/\
    if (strings.used != 0)\
    {\
      /* - adjust result string size - */\
      strings_size += (del_string_ptr->size - 1)*(strings.used - 1) + 1;\
      \
      /* - create result string data - */\
      string_ptr->size = strings_size;\
      string_ptr->data = (char *)cmalloc(strings_size*sizeof(char));\
      \
      /* - strings cocatenation - */\
      char *rs_ptr = string_ptr->data;\
      string_s *s_ptr = strings.data;\
      string_s *s_ptr_end = s_ptr + strings.used;\
      \
      /* - copy first string - */\
      memcpy(rs_ptr,s_ptr->data,(s_ptr->size - 1)*sizeof(char));\
      rs_ptr += s_ptr->size - 1;\
      s_ptr++;\
      \
      if (s_ptr < s_ptr_end)\
      {\
        do\
        {\
          memcpy(rs_ptr,del_string_ptr->data,(del_string_ptr->size - 1)*sizeof(char));\
          rs_ptr += del_string_ptr->size - 1;\
          memcpy(rs_ptr,s_ptr->data,(s_ptr->size - 1)*sizeof(char));\
          rs_ptr += s_ptr->size - 1;\
        }\
        while(++s_ptr < s_ptr_end);\
      }\
      \
      *rs_ptr = '\0';\
    }\
  }/*}}}*/

#define BIC_CONT_CONSTRUCT_IDXS_ARRAY() \
  {/*{{{*/\
    res_array_ptr->copy_resize(idxs_array.used);\
    \
    if (idxs_array.used != 0)\
    {\
      unsigned *i_ptr = idxs_array.data;\
      unsigned *i_ptr_end = i_ptr + idxs_array.used;\
      do\
      {\
        BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,*i_ptr);\
        res_array_ptr->push((pointer)new_location);\
      }\
      while(++i_ptr < i_ptr_end);\
    }\
  }/*}}}*/

// - locations compare macros -
#define BIC_CALL_COMPARE(IT,FIRST_LOC_PTR,SECOND_LOC_PTR,SOURCE_POS,ERR_CODE) \
  {/*{{{*/\
    location_s *first_loc = IT.get_location_value(FIRST_LOC_PTR);\
    location_s *second_loc = IT.get_location_value(SECOND_LOC_PTR);\
    \
    /* - compare locations types - */\
    if (first_loc->v_type != second_loc->v_type)\
    {\
      result = first_loc->v_type < second_loc->v_type ? -1 : 1;\
    }\
    else {\
      class_record_s &class_record = ((interpreter_s *)IT.interpreter_ptr)->class_records[first_loc->v_type];\
      \
      /* - test if location type is built in class, and if it has defined built in function - */\
      if (class_record.modifiers & c_modifier_built_in && class_record.bi_class_ptr->compare_caller != NULL)\
      {\
        result = (long long int)class_record.bi_class_ptr->compare_caller(first_loc,second_loc);\
      }\
      else {\
        unsigned new_stack_base = IT.data_stack.used;\
        \
        /* - call compare method - */\
        ((location_s *)IT.blank_location)->v_reference_cnt.atomic_inc();\
        IT.data_stack.push(IT.blank_location);\
        \
        first_loc->v_reference_cnt.atomic_inc();\
        IT.data_stack.push((pointer)first_loc);\
        \
        second_loc->v_reference_cnt.atomic_inc();\
        IT.data_stack.push((pointer)second_loc);\
        \
        uli tmp_code[7] = {i_call,2,c_built_in_method_idxs[c_built_in_method_compare_1],SOURCE_POS,0,1,2};\
        \
        if (!IT.call_method(tmp_code,new_stack_base))\
        {\
          IT.release_stack_from(new_stack_base);\
          \
          ERR_CODE;\
        }\
        \
        /* - get result from return value - */\
        location_s *ret_location = (location_s *)IT.get_stack_value(new_stack_base);\
        if (ret_location->v_type != c_bi_class_integer)\
        {\
          IT.release_stack_from(new_stack_base);\
          \
          exception_s *new_exception = exception_s::throw_exception(IT,c_error_METHOD_NOT_RETURN_INTEGER,SOURCE_POS,(location_s *)IT.blank_location);\
          BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(IT,first_loc->v_type,"compare#1");\
          \
          ERR_CODE;\
        }\
        \
        /* - retrieve result from location - */\
        result = (long long int)ret_location->v_data_ptr;\
        \
        IT.release_stack_from(new_stack_base);\
      }\
    }\
  }/*}}}*/

// - built in call macros -
#define BIC_CALL_TO_STRING(IT,LOCATION_PTR,SOURCE_POS,ERR_CODE) \
  {/*{{{*/\
    unsigned new_stack_base = IT.data_stack.used;\
    \
    ((location_s *)IT.blank_location)->v_reference_cnt.atomic_inc();\
    IT.data_stack.push(IT.blank_location);\
    \
    location_s *location = (location_s *)(LOCATION_PTR);\
    location->v_reference_cnt.atomic_inc();\
    IT.data_stack.push((pointer)location);\
    \
    uli tmp_code[6] = {i_call,1,c_built_in_method_idxs[c_built_in_method_to_string_0],SOURCE_POS,0,1};\
    \
    if (!IT.call_method(tmp_code,new_stack_base))\
    {\
      IT.release_stack_from(new_stack_base);\
      \
      ERR_CODE;\
    }\
    else\
    {\
      /* - get string from return value - */\
      location_s *ret_location = (location_s *)IT.get_stack_value(new_stack_base);\
      if (ret_location->v_type != c_bi_class_string) {\
        IT.release_stack_from(new_stack_base);\
        \
        exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_RETURN_STRING,SOURCE_POS,(location_s *)IT.blank_location);\
        BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,location->v_type,"to_string#0");\
        \
        ERR_CODE;\
      }\
      \
      /* - copy string from location - */\
      *s_ptr = *((string_s *)ret_location->v_data_ptr);\
      strings_size += s_ptr->size - 1;\
      \
      IT.release_stack_from(new_stack_base);\
    }\
  }/*}}}*/

#define BIC_CALL_PRINT(IT,LOCATION_PTR,SOURCE_POS,ERR_CODE) \
  {/*{{{*/\
    unsigned new_stack_base = IT.data_stack.used;\
    \
    ((location_s *)IT.blank_location)->v_reference_cnt.atomic_inc();\
    IT.data_stack.push(IT.blank_location);\
    \
    location_s *location = (location_s *)(LOCATION_PTR);\
    location->v_reference_cnt.atomic_inc();\
    IT.data_stack.push((pointer)location);\
    \
    uli tmp_code[6] = {i_call,1,c_built_in_method_idxs[c_built_in_method_print_0],SOURCE_POS,0,1};\
    \
    if (!IT.call_method(tmp_code,new_stack_base))\
    {\
      IT.release_stack_from(new_stack_base);\
      \
      ERR_CODE;\
    }\
    \
    IT.release_stack_from(new_stack_base);\
  }/*}}}*/

#define BIC_CALL_LENGTH(IT,LOCATION_PTR,TRG_LENGTH,SOURCE_POS,ERR_CODE) \
  {/*{{{*/\
    location_s *location = IT.get_location_value(LOCATION_PTR);\
    \
    class_record_s &class_record = ((interpreter_s *)IT.interpreter_ptr)->class_records[location->v_type];\
    \
    /* - test if location type is built in class, and if it has defined built in function - */\
    if (class_record.modifiers & c_modifier_built_in && class_record.bi_class_ptr->length_caller != NULL)\
    {\
      TRG_LENGTH = (long long int)class_record.bi_class_ptr->length_caller(location);\
    }\
    else {\
      unsigned new_stack_base = IT.data_stack.used;\
      \
      ((location_s *)IT.blank_location)->v_reference_cnt.atomic_inc();\
      IT.data_stack.push(IT.blank_location);\
      \
      location_s *location = (location_s *)(LOCATION_PTR);\
      location->v_reference_cnt.atomic_inc();\
      IT.data_stack.push((pointer)location);\
      \
      uli tmp_code[6] = {i_call,1,c_built_in_method_idxs[c_built_in_method_length_0],SOURCE_POS,0,1};\
      \
      if (!IT.call_method(tmp_code,new_stack_base))\
      {\
        IT.release_stack_from(new_stack_base);\
        \
        ERR_CODE;\
      }\
      \
      /* - get length from return value - */\
      location_s *ret_location = (location_s *)IT.get_stack_value(new_stack_base);\
      \
      if (ret_location->v_type != c_bi_class_integer)\
      {\
        IT.release_stack_from(new_stack_base);\
        \
        unsigned method_ri = ((interpreter_s *)IT.interpreter_ptr)->class_records[location->v_type].mnri_map.map_name(c_built_in_method_idxs[c_built_in_method_length_0]);\
        cassert(method_ri != c_idx_not_exist);\
        \
        exception_s *new_exception = exception_s::throw_exception(IT,c_error_METHOD_NOT_RETURN_INTEGER,SOURCE_POS,(location_s *)IT.blank_location);\
        new_exception->params.push(method_ri);\
        \
        ERR_CODE;\
      }\
      \
      TRG_LENGTH = (long long int)ret_location->v_data_ptr;\
      \
      IT.release_stack_from(new_stack_base);\
    }\
  }/*}}}*/

#define BIC_CALL_ITEM(IT,LOCATION_PTR,SRC_INDEX,TRG_LOCATION_PTR,SOURCE_POS,ERR_CODE) \
  {/*{{{*/\
    location_s *location = IT.get_location_value(LOCATION_PTR);\
    \
    class_record_s &class_record = ((interpreter_s *)IT.interpreter_ptr)->class_records[location->v_type];\
    \
    /* - test if location type is built in class, and if it has defined built in function - */\
    if (class_record.modifiers & c_modifier_built_in && class_record.bi_class_ptr->item_caller != NULL)\
    {\
      TRG_LOCATION_PTR = class_record.bi_class_ptr->item_caller(IT,location,SRC_INDEX);\
    }\
    else {\
      unsigned new_stack_base = IT.data_stack.used;\
      \
      ((location_s *)IT.blank_location)->v_reference_cnt.atomic_inc();\
      IT.data_stack.push(IT.blank_location);\
      \
      location->v_reference_cnt.atomic_inc();\
      IT.data_stack.push((pointer)location);\
      \
      location_s *idx_location = IT.get_new_location_ptr();\
      idx_location->v_type = c_bi_class_integer;\
      idx_location->v_reference_cnt.atomic_set(1);\
      idx_location->v_data_ptr = (SRC_INDEX);\
      IT.data_stack.push((pointer)idx_location);\
      \
      uli tmp_code[7] = {i_call,2,c_built_in_method_idxs[c_built_in_method_item_1],SOURCE_POS,0,1,2};\
      \
      if (!IT.call_method(tmp_code,new_stack_base))\
      {\
        IT.release_stack_from(new_stack_base);\
        \
        ERR_CODE;\
      }\
      \
      /* - get item from return value - */\
      location_s *ret_location = (location_s *)IT.data_stack[new_stack_base];\
      \
      ret_location->v_reference_cnt.atomic_inc();\
      TRG_LOCATION_PTR = ret_location;\
      \
      IT.release_stack_from(new_stack_base);\
    }\
  }/*}}}*/

#define BIC_CALL_FIRST_IDX(IT,LOCATION_PTR,TRG_INDEX,SOURCE_POS,ERR_CODE) \
  {/*{{{*/\
    location_s *location = IT.get_location_value(LOCATION_PTR);\
    \
    class_record_s &class_record = ((interpreter_s *)IT.interpreter_ptr)->class_records[location->v_type];\
    \
    /* - test if location type is built in class, and if it has defined built in function - */\
    if (class_record.modifiers & c_modifier_built_in && class_record.bi_class_ptr->first_idx_caller != NULL)\
    {\
      TRG_INDEX = (long long int)class_record.bi_class_ptr->first_idx_caller(location);\
    }\
    else {\
      unsigned new_stack_base = IT.data_stack.used;\
      \
      ((location_s *)IT.blank_location)->v_reference_cnt.atomic_inc();\
      IT.data_stack.push(IT.blank_location);\
      \
      location_s *location = (location_s *)(LOCATION_PTR);\
      location->v_reference_cnt.atomic_inc();\
      IT.data_stack.push((pointer)location);\
      \
      uli tmp_code[6] = {i_call,1,c_built_in_method_idxs[c_built_in_method_first_idx_0],SOURCE_POS,0,1};\
      \
      if (!IT.call_method(tmp_code,new_stack_base))\
      {\
        IT.release_stack_from(new_stack_base);\
        \
        ERR_CODE;\
      }\
      \
      /* - get index from return value - */\
      location_s *ret_location = (location_s *)IT.get_stack_value(new_stack_base);\
      \
      switch (ret_location->v_type)\
      {\
      case c_bi_class_blank:\
        TRG_INDEX = (long long int)c_idx_not_exist;\
        break;\
        \
      case c_bi_class_integer:\
        TRG_INDEX = (long long int)ret_location->v_data_ptr;\
        break;\
        \
      default:\
      {\
        IT.release_stack_from(new_stack_base);\
        \
        unsigned method_ri = ((interpreter_s *)IT.interpreter_ptr)->class_records[location->v_type].mnri_map.map_name(c_built_in_method_idxs[c_built_in_method_first_idx_0]);\
        cassert(method_ri != c_idx_not_exist);\
        \
        exception_s *new_exception = exception_s::throw_exception(IT,c_error_METHOD_NOT_RETURN_INDEX,SOURCE_POS,(location_s *)IT.blank_location);\
        new_exception->params.push(method_ri);\
        \
        ERR_CODE;\
      }\
      }\
      \
      IT.release_stack_from(new_stack_base);\
    }\
  }/*}}}*/

#define BIC_CALL_NEXT_IDX(IT,LOCATION_PTR,SRC_INDEX,TRG_INDEX,SOURCE_POS,ERR_CODE) \
  {/*{{{*/\
    location_s *location = IT.get_location_value(LOCATION_PTR);\
    \
    class_record_s &class_record = ((interpreter_s *)IT.interpreter_ptr)->class_records[location->v_type];\
    \
    /* - test if location type is built in class, and if it has defined built in function - */\
    if (class_record.modifiers & c_modifier_built_in && class_record.bi_class_ptr->next_idx_caller != NULL)\
    {\
      TRG_INDEX = (long long int)class_record.bi_class_ptr->next_idx_caller(location,SRC_INDEX);\
    }\
    else {\
      unsigned new_stack_base = IT.data_stack.used;\
      \
      ((location_s *)IT.blank_location)->v_reference_cnt.atomic_inc();\
      IT.data_stack.push(IT.blank_location);\
      \
      location_s *location = (location_s *)(LOCATION_PTR);\
      location->v_reference_cnt.atomic_inc();\
      IT.data_stack.push((pointer)location);\
      \
      location_s *idx_location = IT.get_new_location_ptr();\
      idx_location->v_type = c_bi_class_integer;\
      idx_location->v_reference_cnt.atomic_set(1);\
      idx_location->v_data_ptr = (SRC_INDEX);\
      IT.data_stack.push((pointer)idx_location);\
      \
      uli tmp_code[7] = {i_call,2,c_built_in_method_idxs[c_built_in_method_next_idx_1],SOURCE_POS,0,1,2};\
      \
      if (!IT.call_method(tmp_code,new_stack_base))\
      {\
        IT.release_stack_from(new_stack_base);\
        \
        ERR_CODE;\
      }\
      \
      /* - get index from return value - */\
      location_s *ret_location = (location_s *)IT.get_stack_value(new_stack_base);\
      \
      switch (ret_location->v_type)\
      {\
      case c_bi_class_blank:\
        TRG_INDEX = (long long int)c_idx_not_exist;\
        break;\
        \
      case c_bi_class_integer:\
        TRG_INDEX = (long long int)ret_location->v_data_ptr;\
        break;\
        \
      default:\
      {\
        IT.release_stack_from(new_stack_base);\
        \
        unsigned method_ri = ((interpreter_s *)IT.interpreter_ptr)->class_records[location->v_type].mnri_map.map_name(c_built_in_method_idxs[c_built_in_method_next_idx_1]);\
        cassert(method_ri != c_idx_not_exist);\
        \
        exception_s *new_exception = exception_s::throw_exception(IT,c_error_METHOD_NOT_RETURN_INDEX,SOURCE_POS,(location_s *)IT.blank_location);\
        new_exception->params.push(method_ri);\
        \
        ERR_CODE;\
      }\
      }\
      \
      IT.release_stack_from(new_stack_base);\
    }\
  }/*}}}*/

#define BIC_CALL_NEXT_ITEM(IT,LOCATION_PTR,TRG_LOCATION_PTR,SOURCE_POS,ERR_CODE) \
  {/*{{{*/\
    location_s *location = IT.get_location_value(LOCATION_PTR);\
    \
    class_record_s &class_record = ((interpreter_s *)IT.interpreter_ptr)->class_records[location->v_type];\
    \
    /* - test if location type is built in class, and if it has defined built in function - */\
    if (class_record.modifiers & c_modifier_built_in && class_record.bi_class_ptr->next_item_caller != NULL)\
    {\
      TRG_LOCATION_PTR = class_record.bi_class_ptr->next_item_caller(IT,location,SOURCE_POS);\
      \
      if (TRG_LOCATION_PTR == NULL)\
      {\
        ERR_CODE;\
      }\
    }\
    else {\
      unsigned new_stack_base = IT.data_stack.used;\
      \
      ((location_s *)IT.blank_location)->v_reference_cnt.atomic_inc();\
      IT.data_stack.push(IT.blank_location);\
      \
      location->v_reference_cnt.atomic_inc();\
      IT.data_stack.push((pointer)location);\
      \
      uli tmp_code[6] = {i_call,1,c_built_in_method_idxs[c_built_in_method_next_item_0],SOURCE_POS,0,1};\
      \
      if (!IT.call_method(tmp_code,new_stack_base))\
      {\
        IT.release_stack_from(new_stack_base);\
        \
        ERR_CODE;\
      }\
      \
      /* - get item from return value - */\
      location_s *ret_location = (location_s *)IT.data_stack[new_stack_base];\
      \
      ret_location->v_reference_cnt.atomic_inc();\
      TRG_LOCATION_PTR = ret_location;\
      \
      IT.release_stack_from(new_stack_base);\
    }\
  }/*}}}*/

#define BIC_CALL_DELEGATE_PARAMETERS(IT,PARAM_CNT,PARAM_DATA,DELEGATE_PTR,PARAM_IDX,PARAM_BASE) \
{/*{{{*/\
  unsigned param_idx = PARAM_IDX;\
\
  if (DELEGATE_PTR->papply != NULL)\
  {\
    pointer_array_s *papply_params = (pointer_array_s *)DELEGATE_PTR->papply;\
\
    pointer *p_ptr = papply_params->data;\
    pointer *p_ptr_end = p_ptr + papply_params->used;\
    do\
    {\
      /* - push parameter to stack - */\
      ((location_s *)*p_ptr)->v_reference_cnt.atomic_inc();\
      IT.data_stack.push(*p_ptr);\
      \
      /* - set parameter index in code - */\
      tmp_code[PARAM_BASE + param_idx] = param_idx;\
    }\
    while(++param_idx,++p_ptr < p_ptr_end);\
  }\
\
  if (PARAM_CNT != 0)\
  {\
    pointer *p_ptr = PARAM_DATA;\
    pointer *p_ptr_end = p_ptr + PARAM_CNT;\
    do\
    {\
      /* - push parameter to stack - */\
      ((location_s *)*p_ptr)->v_reference_cnt.atomic_inc();\
      IT.data_stack.push(*p_ptr);\
      \
      /* - set parameter index in code - */\
      tmp_code[PARAM_BASE + param_idx] = param_idx;\
    }\
    while(++param_idx,++p_ptr < p_ptr_end);\
  }\
}/*}}}*/

#define BIC_CALL_DELEGATE(IT,DELEGATE_PTR,PARAM_DATA,PARAM_CNT,TRG_LOCATION_PTR,SOURCE_POS,ERR_CODE) \
  {/*{{{*/\
    unsigned new_stack_base = IT.data_stack.used;\
    \
    /* - push result location to stack - */\
    ((location_s *)IT.blank_location)->v_reference_cnt.atomic_inc();\
    IT.data_stack.push(IT.blank_location);\
    \
    /* - if delegate is static - */\
    if (DELEGATE_PTR->object_location == NULL)\
    {/*{{{*/\
      uli tmp_code[5 + DELEGATE_PTR->orig_param_cnt];\
      tmp_code[0] = i_static_call;\
      tmp_code[1] = DELEGATE_PTR->orig_param_cnt;\
      tmp_code[2] = SOURCE_POS;\
      tmp_code[3] = 0;\
      tmp_code[4] = DELEGATE_PTR->name_idx_ri;\
      \
      /* - push parameters to stack - */\
      BIC_CALL_DELEGATE_PARAMETERS(IT,PARAM_CNT,PARAM_DATA,DELEGATE_PTR,1,4);\
      \
      /* - call static method - */\
      uli *code_ptr = tmp_code;\
      inst_params_s params = {&(IT),&code_ptr,new_stack_base,NULL};\
      if (inst_static_call(&params) != c_run_return_code_OK)\
      {\
        IT.release_stack_from(new_stack_base);\
        \
        ERR_CODE;\
      }\
    }/*}}}*/\
    \
    /* - if delegate is not static - */\
    else\
    {/*{{{*/\
      \
      /* - push this location to stack - */\
      location_s *location = DELEGATE_PTR->object_location;\
      location->v_reference_cnt.atomic_inc();\
      IT.data_stack.push((pointer)location);\
      \
      uli tmp_code[8 + DELEGATE_PTR->orig_param_cnt];\
      tmp_code[0] = i_call;\
      tmp_code[1] = 1 + DELEGATE_PTR->orig_param_cnt;\
      tmp_code[2] = DELEGATE_PTR->name_idx_ri;\
      tmp_code[3] = SOURCE_POS;\
      tmp_code[4] = 0;\
      tmp_code[5] = 1;\
      \
      /* - push parameters to stack - */\
      BIC_CALL_DELEGATE_PARAMETERS(IT,PARAM_CNT,PARAM_DATA,DELEGATE_PTR,2,4);\
      \
      /* - call method - */\
      uli *code_ptr = tmp_code;\
      inst_params_s params = {&(IT),&code_ptr,new_stack_base,NULL};\
      if (inst_call(&params) != c_run_return_code_OK)\
      {\
        IT.release_stack_from(new_stack_base);\
        \
        ERR_CODE;\
      }\
    }/*}}}*/\
    \
    /* - get return value - */\
    location_s *ret_location = (location_s *)IT.data_stack[new_stack_base];\
    \
    ret_location->v_reference_cnt.atomic_inc();\
    TRG_LOCATION_PTR = ret_location;\
    \
    IT.release_stack_from(new_stack_base);\
  }/*}}}*/

#define BIC_CALL_OPERATOR_BINARY_PLUS(IT,LOCATION_PTR,SRC_LOCATION_PTR,TRG_LOCATION_PTR,SOURCE_POS,ERR_CODE) \
  {/*{{{*/\
    unsigned new_stack_base = IT.data_stack.used;\
    \
    ((location_s *)IT.blank_location)->v_reference_cnt.atomic_inc();\
    IT.data_stack.push(IT.blank_location);\
    \
    location_s *location = (location_s *)(LOCATION_PTR);\
    location->v_reference_cnt.atomic_inc();\
    IT.data_stack.push((pointer)location);\
    \
    location_s *src_location = (location_s *)(SRC_LOCATION_PTR);\
    src_location->v_reference_cnt.atomic_inc();\
    IT.data_stack.push((pointer)src_location);\
    \
    uli tmp_code[7] = {i_call,2,c_built_in_method_idxs[c_operator_binary_plus],SOURCE_POS,0,1,2};\
    \
    if (!IT.call_method(tmp_code,new_stack_base))\
    {\
      IT.release_stack_from(new_stack_base);\
      \
      ERR_CODE;\
    }\
    \
    /* - get result value - */\
    location_s *ret_location = (location_s *)IT.data_stack[new_stack_base];\
    \
    ret_location->v_reference_cnt.atomic_inc();\
    TRG_LOCATION_PTR = ret_location;\
    \
    IT.release_stack_from(new_stack_base);\
  }/*}}}*/

#endif

