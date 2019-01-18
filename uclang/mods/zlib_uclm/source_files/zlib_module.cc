
@begin
include "zlib_module.h"
@end

// - ZLIB indexes of built in classes -
unsigned c_bi_class_zlib = c_idx_not_exist;
unsigned c_bi_class_gz_file = c_idx_not_exist;

// - ZLIB module -
EXPORT built_in_module_s module =
{/*{{{*/
  2,                    // Class count
  zlib_classes,         // Classes

  0,                    // Error base index
  11,                   // Error count
  zlib_error_strings,   // Error strings

  zlib_initialize,      // Initialize function
  zlib_print_exception, // Print exceptions function
};/*}}}*/

// - ZLIB classes -
built_in_class_s *zlib_classes[] =
{/*{{{*/
  &zlib_class,
  &gz_file_class,
};/*}}}*/

// - ZLIB error strings -
const char *zlib_error_strings[] =
{/*{{{*/
  "error_ZLIB_COMPRESS_INVALID_LEVEL",
  "error_ZLIB_NOT_ENOUGHT_SPACE_IN_BUFFER",
  "error_ZLIB_COMPRESS_ERROR",
  "error_ZLIB_UNCOMPRESS_ERROR",
  "error_GZ_FILE_OPEN_ERROR",
  "error_GZ_FILE_SEEK_ERROR",
  "error_GZ_FILE_CLOSE_ERROR",
  "error_GZ_FILE_WRITE_ERROR",
  "error_GZ_FILE_READ_ERROR",
  "error_GZ_FILE_READ_NEGATIVE_BYTE_COUNT",
  "error_GZ_FILE_NOT_OPENED",
};/*}}}*/

// - ZLIB initialize -
bool zlib_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize zlib class identifier -
  c_bi_class_zlib = class_base_idx++;

  // - initialize gz_file class identifier -
  c_bi_class_gz_file = class_base_idx++;

  return true;
}/*}}}*/

// - ZLIB print exception -
bool zlib_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_ZLIB_COMPRESS_INVALID_LEVEL:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nZLib invalid compression level %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_ZLIB_NOT_ENOUGHT_SPACE_IN_BUFFER:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nZLib not enought space in output buffer\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_ZLIB_COMPRESS_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nZLib compression error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_ZLIB_UNCOMPRESS_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nZLib uncompress error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GZ_FILE_OPEN_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot open gz file \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GZ_FILE_SEEK_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot set position (seek) in gz file\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GZ_FILE_CLOSE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot close gz file\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GZ_FILE_WRITE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while writing to gz file\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GZ_FILE_READ_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while reading from gz file\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GZ_FILE_READ_NEGATIVE_BYTE_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot read %" HOST_LL_FORMAT "d bytes from gz file\n", exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GZ_FILE_NOT_OPENED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nGz file is not opened\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class ZLIB -
built_in_class_s zlib_class =
{/*{{{*/
  "ZLib",
  c_modifier_public | c_modifier_final,
  4, zlib_methods,
  0, zlib_variables,
  bic_zlib_consts,
  bic_zlib_init,
  bic_zlib_clear,
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

built_in_method_s zlib_methods[] =
{/*{{{*/
  {
    "compress#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_zlib_method_compress_2
  },
  {
    "uncompress#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_zlib_method_uncompress_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_zlib_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_zlib_method_print_0
  },
};/*}}}*/

built_in_variable_s zlib_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_zlib_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_zlib_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_zlib_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_zlib_method_compress_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:retrieve_data_buffer
level:retrieve_integer
>
class c_bi_class_zlib
method compress
static_method
; @end

  // - ERROR -
  if (level < 0 || level > 9)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_ZLIB_COMPRESS_INVALID_LEVEL,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(level);

    return false;
  }

  // - retrieve maximal target length -
  uLongf target_length = compressBound(data_size);

  // - create target string -
  string_s *target_ptr = it.get_new_string_ptr();
  target_ptr->create(target_length);

  // - ERROR -
  if (compress2((Bytef *)target_ptr->data,&target_length,(Bytef *)data_ptr,data_size,level) != Z_OK)
  {
    target_ptr->clear();
    cfree(target_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_ZLIB_COMPRESS_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - adjust string size -
  target_ptr->data[target_length] = '\0';
  target_ptr->size = target_length + 1;

  BIC_SET_RESULT_STRING(target_ptr);

  return true;
}/*}}}*/

bool bic_zlib_method_uncompress_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:retrieve_data_buffer
lli_target_length:retrieve_integer
>
class c_bi_class_zlib
method uncompress
static_method
; @end

  // - ERROR -
  if (lli_target_length <= 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_ZLIB_NOT_ENOUGHT_SPACE_IN_BUFFER,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - retrieve target length -
  uLongf target_length = lli_target_length;

  // - create target string -
  string_s *target_ptr = it.get_new_string_ptr();
  target_ptr->create(target_length);

  // - uncompress data -
  int res = uncompress((Bytef *)target_ptr->data,&target_length,(Bytef *)data_ptr,data_size);

  // - ERROR -
  if (res != Z_OK)
  {
    target_ptr->clear();
    cfree(target_ptr);

    if (res == Z_BUF_ERROR)
    {
      exception_s::throw_exception(it,module.error_base + c_error_ZLIB_NOT_ENOUGHT_SPACE_IN_BUFFER,operands[c_source_pos_idx],(location_s *)it.blank_location);
    }
    else
    {
      exception_s::throw_exception(it,module.error_base + c_error_ZLIB_UNCOMPRESS_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    }

    return false;
  }

  // - adjust string size -
  target_ptr->data[target_length] = '\0';
  target_ptr->size = target_length + 1;

  BIC_SET_RESULT_STRING(target_ptr);

  return true;
}/*}}}*/

bool bic_zlib_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("ZLib"),"ZLib");
  );

  return true;
}/*}}}*/

bool bic_zlib_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("ZLib");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class GZ_FILE -
built_in_class_s gz_file_class =
{/*{{{*/
  "GzFile",
  c_modifier_public | c_modifier_final,
  14, gz_file_methods,
  2, gz_file_variables,
  bic_gz_file_consts,
  bic_gz_file_init,
  bic_gz_file_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  bic_gz_file_next_item,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s gz_file_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gz_file_operator_binary_equal
  },
  {
    "GzFile#2",
    c_modifier_public | c_modifier_final,
    bic_gz_file_method_GzFile_2
  },
  {
    "seek#2",
    c_modifier_public | c_modifier_final,
    bic_gz_file_method_seek_2
  },
  {
    "tell#0",
    c_modifier_public | c_modifier_final,
    bic_gz_file_method_tell_0
  },
  {
    "close#0",
    c_modifier_public | c_modifier_final,
    bic_gz_file_method_close_0
  },
  {
    "write#1",
    c_modifier_public | c_modifier_final,
    bic_gz_file_method_write_1
  },
  {
    "write_close#1",
    c_modifier_public | c_modifier_final,
    bic_gz_file_method_write_close_1
  },
  {
    "read#0",
    c_modifier_public | c_modifier_final,
    bic_gz_file_method_read_0
  },
  {
    "readln#0",
    c_modifier_public | c_modifier_final,
    bic_gz_file_method_readln_0
  },
  {
    "read#1",
    c_modifier_public | c_modifier_final,
    bic_gz_file_method_read_1
  },
  {
    "read_close#0",
    c_modifier_public | c_modifier_final,
    bic_gz_file_method_read_close_0
  },
  {
    "next_item#0",
    c_modifier_public | c_modifier_final,
    bic_gz_file_method_next_item_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gz_file_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gz_file_method_print_0
  },
};/*}}}*/

built_in_variable_s gz_file_variables[] =
{/*{{{*/

  // - seek whence values -
  { "SEEK_SET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SEEK_CUR", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

#define BIC_GZ_FILE_METHOD_WRITE_1() \
/*{{{*/\
\
  /* - retrieve pointer to gz file - */\
  gzFile gzf_ptr = (gzFile)dst_location->v_data_ptr;\
\
  /* - ERROR - */\
  if (gzf_ptr == nullptr)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_GZ_FILE_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  /* - ERROR - */\
  if (gzwrite(gzf_ptr,data_ptr,data_size) != (int)data_size)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_GZ_FILE_WRITE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
/*}}}*/

#define BIC_GZ_FILE_METHOD_READ_0() \
/*{{{*/\
\
  /* - retrieve pointer to gz file - */\
  gzFile gzf_ptr = (gzFile)dst_location->v_data_ptr;\
\
  /* - ERROR - */\
  if (gzf_ptr == nullptr)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_GZ_FILE_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  const int c_buffer_add = 1024;\
\
  /* - target data buffer - */\
  bc_array_s data_buffer;\
  data_buffer.init();\
\
  int read_cnt;\
  do\
  {\
    unsigned old_used = data_buffer.used;\
    data_buffer.push_blanks(c_buffer_add);\
    read_cnt = gzread(gzf_ptr,data_buffer.data + old_used,c_buffer_add);\
  }\
  while(read_cnt >= c_buffer_add);\
\
  if (read_cnt < 0)\
  {\
    data_buffer.clear();\
\
    exception_s::throw_exception(it,module.error_base + c_error_GZ_FILE_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  data_buffer.used = (data_buffer.used - c_buffer_add) + read_cnt;\
\
  /* - was any data read from file - */\
  if (data_buffer.used == 0)\
  {\
    data_buffer.clear();\
\
    BIC_SET_RESULT_BLANK();\
  }\
  else\
  {\
    data_buffer.push('\0');\
\
    /* - return data string - */\
    string_s *string_ptr = it.get_new_string_ptr();\
    string_ptr->data = data_buffer.data;\
    string_ptr->size = data_buffer.used;\
\
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);\
    BIC_SET_RESULT(new_location);\
  }\
/*}}}*/

#define BIC_GZ_FILE_METHOD_CLOSE_0() \
/*{{{*/\
\
  /* - ERROR - */\
  if (gzclose(gzf_ptr) != Z_OK)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_GZ_FILE_CLOSE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  dst_location->v_data_ptr = (gzFile)nullptr;\
/*}}}*/

#define BIC_GZ_FILE_READLN() \
/*{{{*/\
  const unsigned c_init_buffer_size = 1024;\
\
  /* - target data buffer - */\
  bc_array_s line_buffer;\
  line_buffer.init_size(c_init_buffer_size);\
\
  int ch;\
  do {\
    /* - read next character from gz file - */\
    ch = gzgetc(gzf_ptr);\
\
    /* - test end of line - */\
    if (ch == '\n' || ch == -1)\
      break;\
\
    /* - insert character to line buffer - */\
    line_buffer.push(ch);\
\
  } while(true);\
/*}}}*/

#define BIC_FD_NEXT_ITEM() \
{/*{{{*/\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  /* - retrieve pointer to gz file - */\
  gzFile gzf_ptr = (gzFile)dst_location->v_data_ptr;\
\
  /* - ERROR - */\
  if (gzf_ptr == nullptr)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_GZ_FILE_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  BIC_GZ_FILE_READLN();\
\
  /* - ERROR - */\
  if (ch == -1 && !gzeof(gzf_ptr))\
  {\
    line_buffer.clear();\
\
    exception_s::throw_exception(it,module.error_base + c_error_GZ_FILE_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  if (gzeof(gzf_ptr) && line_buffer.used == 0)\
  {\
    line_buffer.clear();\
\
    BIC_SET_RESULT_BLANK();\
  }\
  else {\
    line_buffer.push('\0');\
\
    /* - return data string - */\
    string_s *string_ptr = it.get_new_string_ptr();\
    string_ptr->data = line_buffer.data;\
    string_ptr->size = line_buffer.used;\
\
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);\
    BIC_SET_RESULT(new_location)\
  }\
\
  return true;\
}/*}}}*/

void bic_gz_file_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert seek whence values -
  {
    const_locations.push_blanks(2);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 2);

#define CREATE_GZ_FILE_SEEK_WHENCE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_GZ_FILE_SEEK_WHENCE_BIC_STATIC(SEEK_SET);
    CREATE_GZ_FILE_SEEK_WHENCE_BIC_STATIC(SEEK_CUR);
  }

}/*}}}*/

void bic_gz_file_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (gzFile)nullptr;
}/*}}}*/

void bic_gz_file_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  gzFile gzf_ptr = (gzFile)location_ptr->v_data_ptr;

  if (gzf_ptr != nullptr)
  {
    gzclose(gzf_ptr);
  }
}/*}}}*/

location_s *bic_gz_file_next_item(interpreter_thread_s &it,location_s *location_ptr,unsigned source_pos)
{/*{{{*/

  // - retrieve pointer to gz file -
  gzFile gzf_ptr = (gzFile)location_ptr->v_data_ptr;

  // - ERROR -
  if (gzf_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GZ_FILE_NOT_OPENED,source_pos,(location_s *)it.blank_location);
    return nullptr;
  }

  BIC_GZ_FILE_READLN();

  // - ERROR -
  if (ch == -1 && !gzeof(gzf_ptr))
  {
    line_buffer.clear();

    exception_s::throw_exception(it,module.error_base + c_error_GZ_FILE_READ_ERROR,source_pos,(location_s *)it.blank_location);
    return nullptr;
  }

  if (gzeof(gzf_ptr) && line_buffer.used == 0)
  {
    line_buffer.clear();

    ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();
    return ((location_s *)it.blank_location);
  }

  line_buffer.push('\0');

  // - return data string -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->data = line_buffer.data;
  string_ptr->size = line_buffer.used;

  // - create result location -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);

  return new_location;
}/*}}}*/

bool bic_gz_file_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_gz_file_method_GzFile_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
path:c_bi_class_string
mode:c_bi_class_string
>
method GzFile
; @end

  string_s *file_name = (string_s *)src_0_location->v_data_ptr;
  string_s *file_mode = (string_s *)src_1_location->v_data_ptr;

  gzFile gzf_ptr = gzopen(file_name->data,file_mode->data);

  // - ERROR -
  if (gzf_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GZ_FILE_OPEN_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  dst_location->v_data_ptr = (gzFile)gzf_ptr;

  return true;
}/*}}}*/

bool bic_gz_file_method_seek_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
offset:retrieve_integer
whence:retrieve_integer
>
method seek
; @end

  // - retrieve pointer to gz file -
  gzFile gzf_ptr = (gzFile)dst_location->v_data_ptr;

  // - ERROR -
  if (gzf_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GZ_FILE_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  long long int result = gzseek(gzf_ptr,offset,whence);

  // - ERROR -
  if (result <= 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GZ_FILE_SEEK_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_gz_file_method_tell_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve pointer to gz file -
  gzFile gzf_ptr = (gzFile)dst_location->v_data_ptr;

  // - ERROR -
  if (gzf_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GZ_FILE_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  long long int result = gztell(gzf_ptr);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_gz_file_method_close_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve pointer to file -
  gzFile gzf_ptr = (gzFile)dst_location->v_data_ptr;

  // - ERROR -
  if (gzf_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GZ_FILE_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_GZ_FILE_METHOD_CLOSE_0();

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_gz_file_method_write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:retrieve_data_buffer
>
method write
; @end

  BIC_GZ_FILE_METHOD_WRITE_1();

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_gz_file_method_write_close_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:retrieve_data_buffer
>
method write_close
; @end

  BIC_GZ_FILE_METHOD_WRITE_1();
  BIC_GZ_FILE_METHOD_CLOSE_0();

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_gz_file_method_read_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  BIC_GZ_FILE_METHOD_READ_0();

  return true;
}/*}}}*/

bool bic_gz_file_method_readln_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FD_NEXT_ITEM();
}/*}}}*/

bool bic_gz_file_method_read_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
byte_cnt:retrieve_integer
>
method read
; @end

  // - retrieve pointer to gz file -
  gzFile gzf_ptr = (gzFile)dst_location->v_data_ptr;

  // - ERROR -
  if (gzf_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GZ_FILE_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (byte_cnt < 0)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GZ_FILE_READ_NEGATIVE_BYTE_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(byte_cnt);

    return false;
  }

  // - target data string -
  string_s data_string;
  data_string.init();
  data_string.create(byte_cnt);

  int read_cnt = gzread(gzf_ptr,data_string.data,byte_cnt);

  // - ERROR -
  if (read_cnt < byte_cnt)
  {
    data_string.clear();

    exception_s::throw_exception(it,module.error_base + c_error_GZ_FILE_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - return data string -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->swap(data_string);
  data_string.clear();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_gz_file_method_read_close_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  BIC_GZ_FILE_METHOD_READ_0();
  BIC_GZ_FILE_METHOD_CLOSE_0();

  return true;
}/*}}}*/

bool bic_gz_file_method_next_item_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FD_NEXT_ITEM();
}/*}}}*/

bool bic_gz_file_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("GzFile"),"GzFile");
  );

  return true;
}/*}}}*/

bool bic_gz_file_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("GzFile");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

