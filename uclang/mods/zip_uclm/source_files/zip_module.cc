
@begin
include "zip_module.h"
@end

// - ZIP indexes of built in classes -
unsigned c_bi_class_zip_archive = c_idx_not_exist;
unsigned c_bi_class_zip_index = c_idx_not_exist;

// - ZIP module -
built_in_module_s module =
{/*{{{*/
  2,                   // Class count
  zip_classes,         // Classes

  0,                   // Error base index
  2,                   // Error count
  zip_error_strings,   // Error strings

  zip_initialize,      // Initialize function
  zip_print_exception, // Print exceptions function
};/*}}}*/

// - ZIP classes -
built_in_class_s *zip_classes[] =
{/*{{{*/
  &zip_archive_class,
  &zip_index_class,
};/*}}}*/

// - ZIP error strings -
const char *zip_error_strings[] =
{/*{{{*/
  "error_ZIP_ARCHIVE_OPEN_ERROR",
  "error_ZIP_ARCHIVE_NOT_OPENED",
};/*}}}*/

// - ZIP initialize -
bool zip_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize zip_archive class identifier -
  c_bi_class_zip_archive = class_base_idx++;

  // - initialize zip_index class identifier -
  c_bi_class_zip_index = class_base_idx++;

  return true;
}/*}}}*/

// - ZIP print exception -
bool zip_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_ZIP_ARCHIVE_OPEN_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while opening zip archive: %s\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_ZIP_ARCHIVE_NOT_OPENED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nZip archive is not opened\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class ZIP_ARCHIVE -
built_in_class_s zip_archive_class =
{/*{{{*/
  "ZipArchive",
  c_modifier_public | c_modifier_final,
  11, zip_archive_methods,
  5 + 14, zip_archive_variables,
  bic_zip_archive_consts,
  bic_zip_archive_init,
  bic_zip_archive_clear,
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

built_in_method_s zip_archive_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_zip_archive_operator_binary_equal
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_zip_archive_operator_binary_le_br_re_br
  },
  {
    "ZipArchive#2",
    c_modifier_public | c_modifier_final,
    bic_zip_archive_method_ZipArchive_2
  },
  {
    "close#0",
    c_modifier_public | c_modifier_final,
    bic_zip_archive_method_close_0
  },
  {
    "discard#0",
    c_modifier_public | c_modifier_final,
    bic_zip_archive_method_discard_0
  },
  {
    "item#1",
    c_modifier_public | c_modifier_final,
    bic_zip_archive_method_item_1
  },
  {
    "first_idx#0",
    c_modifier_public | c_modifier_final,
    bic_zip_archive_method_first_idx_0
  },
  {
    "next_idx#1",
    c_modifier_public | c_modifier_final,
    bic_zip_archive_method_next_idx_1
  },
  {
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_zip_archive_method_length_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_zip_archive_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_zip_archive_method_print_0
  },
};/*}}}*/

built_in_variable_s zip_archive_variables[] =
{/*{{{*/

  // - open flag values -
  { "CREATE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EXCL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CHECKCONS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TRUNCATE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "RDONLY", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - other flag values -
  { "FL_NOCASE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FL_NODIR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FL_COMPRESSED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FL_UNCHANGED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FL_RECOMPRESS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FL_ENCRYPTED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FL_ENC_GUESS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FL_ENC_RAW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FL_ENC_STRICT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FL_LOCAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FL_CENTRAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FL_ENC_UTF_8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FL_ENC_CP437", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FL_OVERWRITE", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

#define BIC_ZIP_ERROR_LOCATION_FROM_CODE(ERROR_LOCATION,ERROR_CODE) \
/*{{{*/\
    zip_error_t ze;\
    zip_error_init_with_code(&ze,ERROR_CODE);\
    const char *error_str = zip_error_strerror(&ze);\
    \
    /* - create error string - */\
    string_s *string_ptr = it.get_new_string_ptr();\
    string_ptr->set(strlen(error_str),error_str);\
    zip_error_fini(&ze);\
    \
    BIC_CREATE_NEW_LOCATION_REFS(ERROR_LOCATION,c_bi_class_string,string_ptr,0);\
/*}}}*/

#define BIC_ZIP_ARCHIVE_RETRIEVE_FROM(LOCATION) \
/*{{{*/\
  zip_t *za_ptr = (zip_t *)LOCATION->v_data_ptr;\
  \
  /* - ERROR - */\
  if (za_ptr == nullptr)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_ZIP_ARCHIVE_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
/*}}}*/

#define BIC_ZIP_ARCHIVE_CHECK_INDEX() \
/*{{{*/\
  long long int entry_cnt = zip_get_num_entries(za_ptr,0);\
  \
  /* - ERROR - */\
  if (index < 0 || index >= entry_cnt)\
  {\
    /* FIXME TODO throw proper exception */\
    BIC_TODO_ERROR(__FILE__,__LINE__);\
    return false;\
  }\
/*}}}*/

#define BIC_ZIP_ARCHIVE_ITEM(NAME) \
{/*{{{*/\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
  \
  BIC_ZIP_ARCHIVE_RETRIEVE_FROM(dst_location);\
\
  long long int index;\
  \
  if (!it.retrieve_integer(src_0_location,index))\
  {\
    /* - ERROR - */\
    if (src_0_location->v_type != c_bi_class_string)\
    {\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
      \
      return false;\
    }\
    \
    string_s *name_ptr = (string_s *)src_0_location->v_data_ptr;\
   \
    /* - ERROR - */\
    if ((index = zip_name_locate(za_ptr,name_ptr->data,0)) == -1)\
    {\
      /* FIXME TODO throw proper exception */\
      BIC_TODO_ERROR(__FILE__,__LINE__);\
      return false;\
    }\
  }\
  else {\
    BIC_ZIP_ARCHIVE_CHECK_INDEX();\
  }\
  \
  /* - create new zip index object - */\
  zip_index_s *zi_ptr = (zip_index_s *)cmalloc(sizeof(zip_index_s));\
  \
  dst_location->v_reference_cnt.atomic_inc();\
  zi_ptr->archive_loc = dst_location;\
  zi_ptr->index = index;\
  \
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_zip_index,zi_ptr);\
  BIC_SET_RESULT(new_location);\
  \
  return true;\
}/*}}}*/

void bic_zip_archive_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert open flag values -
  {
    const_locations.push_blanks(5);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 5);

#define CREATE_ZIP_OPEN_FLAG_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_ZIP_OPEN_FLAG_BIC_STATIC(ZIP_CREATE);
    CREATE_ZIP_OPEN_FLAG_BIC_STATIC(ZIP_EXCL);
    CREATE_ZIP_OPEN_FLAG_BIC_STATIC(ZIP_CHECKCONS);
    CREATE_ZIP_OPEN_FLAG_BIC_STATIC(ZIP_TRUNCATE);
    CREATE_ZIP_OPEN_FLAG_BIC_STATIC(ZIP_RDONLY);
  }

  // - insert other flag values -
  {
    const_locations.push_blanks(14);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 14);

#define CREATE_ZIP_OTHER_FLAG_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_ZIP_OTHER_FLAG_BIC_STATIC(ZIP_FL_NOCASE);
    CREATE_ZIP_OTHER_FLAG_BIC_STATIC(ZIP_FL_NODIR);
    CREATE_ZIP_OTHER_FLAG_BIC_STATIC(ZIP_FL_COMPRESSED);
    CREATE_ZIP_OTHER_FLAG_BIC_STATIC(ZIP_FL_UNCHANGED);
    CREATE_ZIP_OTHER_FLAG_BIC_STATIC(ZIP_FL_RECOMPRESS);
    CREATE_ZIP_OTHER_FLAG_BIC_STATIC(ZIP_FL_ENCRYPTED);
    CREATE_ZIP_OTHER_FLAG_BIC_STATIC(ZIP_FL_ENC_GUESS);
    CREATE_ZIP_OTHER_FLAG_BIC_STATIC(ZIP_FL_ENC_RAW);
    CREATE_ZIP_OTHER_FLAG_BIC_STATIC(ZIP_FL_ENC_STRICT);
    CREATE_ZIP_OTHER_FLAG_BIC_STATIC(ZIP_FL_LOCAL);
    CREATE_ZIP_OTHER_FLAG_BIC_STATIC(ZIP_FL_CENTRAL);
    CREATE_ZIP_OTHER_FLAG_BIC_STATIC(ZIP_FL_ENC_UTF_8);
    CREATE_ZIP_OTHER_FLAG_BIC_STATIC(ZIP_FL_ENC_CP437);
    CREATE_ZIP_OTHER_FLAG_BIC_STATIC(ZIP_FL_OVERWRITE);
  }

}/*}}}*/

void bic_zip_archive_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (zip_t *)nullptr;
}/*}}}*/

void bic_zip_archive_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  zip_t *za_ptr = (zip_t *)location_ptr->v_data_ptr;

  if (za_ptr != nullptr)
  {
    zip_close(za_ptr);
  }
}/*}}}*/

bool bic_zip_archive_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ZIP_ARCHIVE_ITEM("operator_binary_le_br_re_br#1");
}/*}}}*/

bool bic_zip_archive_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_zip_archive_method_ZipArchive_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int flags;

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string ||
      !it.retrieve_integer(src_1_location,flags))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("ZipArchive#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  string_s *file_name = (string_s *)src_0_location->v_data_ptr;

  int error;
  zip_t *za_ptr = zip_open(file_name->data,flags,&error);

  // - ERROR -
  if (za_ptr == nullptr)
  {
    BIC_ZIP_ERROR_LOCATION_FROM_CODE(error_loc,error);

    exception_s::throw_exception(it,module.error_base + c_error_ZIP_ARCHIVE_OPEN_ERROR,operands[c_source_pos_idx],error_loc);
    return false;
  }

  dst_location->v_data_ptr = (zip_t *)za_ptr;

  return true;
}/*}}}*/

bool bic_zip_archive_method_close_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  BIC_ZIP_ARCHIVE_RETRIEVE_FROM(dst_location);

  // - ERROR -
  if (zip_close(za_ptr) != 0)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  dst_location->v_data_ptr = (zip_t *)nullptr;

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_zip_archive_method_discard_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  BIC_ZIP_ARCHIVE_RETRIEVE_FROM(dst_location);

  zip_discard(za_ptr);

  dst_location->v_data_ptr = (zip_t *)nullptr;

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_zip_archive_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ZIP_ARCHIVE_ITEM("item#1");
}/*}}}*/

bool bic_zip_archive_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  BIC_ZIP_ARCHIVE_RETRIEVE_FROM(dst_location);

  if (zip_get_num_entries(za_ptr,0) > 0)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,0);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_zip_archive_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
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

  BIC_ZIP_ARCHIVE_RETRIEVE_FROM(dst_location);
  BIC_ZIP_ARCHIVE_CHECK_INDEX();

  if (++index < entry_cnt)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,index);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_zip_archive_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  BIC_ZIP_ARCHIVE_RETRIEVE_FROM(dst_location);

  long long int result = zip_get_num_entries(za_ptr,0);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_zip_archive_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("ZipArchive"),"ZipArchive");
  );

  return true;
}/*}}}*/

bool bic_zip_archive_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("ZipArchive");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class ZIP_INDEX -
built_in_class_s zip_index_class =
{/*{{{*/
  "ZipIndex",
  c_modifier_public | c_modifier_final,
  6, zip_index_methods,
  0, zip_index_variables,
  bic_zip_index_consts,
  bic_zip_index_init,
  bic_zip_index_clear,
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

built_in_method_s zip_index_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_zip_index_operator_binary_equal
  },
  {
    "index#0",
    c_modifier_public | c_modifier_final,
    bic_zip_index_method_index_0
  },
  {
    "name#0",
    c_modifier_public | c_modifier_final,
    bic_zip_index_method_name_0
  },
  {
    "size#0",
    c_modifier_public | c_modifier_final,
    bic_zip_index_method_size_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_zip_index_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_zip_index_method_print_0
  },
};/*}}}*/

built_in_variable_s zip_index_variables[] =
{/*{{{*/
};/*}}}*/

void bic_zip_index_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_zip_index_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (zip_index_s *)nullptr;
}/*}}}*/

void bic_zip_index_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  zip_index_s *zi_ptr = (zip_index_s *)location_ptr->v_data_ptr;

  if (zi_ptr != nullptr)
  {
    zi_ptr->clear(it);
    cfree(zi_ptr);
  }
}/*}}}*/

bool bic_zip_index_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_zip_index_method_index_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((zip_index_s *)dst_location->v_data_ptr)->index;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_zip_index_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  zip_index_s *zi_ptr = (zip_index_s *)dst_location->v_data_ptr;

  BIC_ZIP_ARCHIVE_RETRIEVE_FROM(zi_ptr->archive_loc);

  const char *name = zip_get_name(za_ptr,zi_ptr->index,0);

  // - ERROR -
  if (name == nullptr)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(name),name);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_zip_index_method_size_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  zip_index_s *zi_ptr = (zip_index_s *)dst_location->v_data_ptr;

  BIC_ZIP_ARCHIVE_RETRIEVE_FROM(zi_ptr->archive_loc);

  zip_stat_t stat;

  // - ERROR -
  if (zip_stat_index(za_ptr,zi_ptr->index,0,&stat) != 0 ||
      (stat.valid & ZIP_STAT_SIZE) == 0)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  long long int result = stat.size;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_zip_index_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("ZipIndex"),"ZipIndex");
  );

  return true;
}/*}}}*/

bool bic_zip_index_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("ZipIndex");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

