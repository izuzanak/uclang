
@begin
include "zlib_module.h"
@end

// - ZLIB indexes of built in classes -
unsigned c_bi_class_zlib = c_idx_not_exist;

// - ZLIB indexes of remote classes -
unsigned c_rm_class_socket = c_idx_not_exist;

// - ZLIB module -
built_in_module_s module =
{/*{{{*/
  1,                    // Class count
  zlib_classes,         // Classes

  0,                    // Error base index
  4,                    // Error count
  zlib_error_strings,   // Error strings

  zlib_initialize,      // Initialize function
  zlib_print_exception, // Print exceptions function
};/*}}}*/

// - ZLIB classes -
built_in_class_s *zlib_classes[] =
{/*{{{*/
  &zlib_class,
};/*}}}*/

// - ZLIB error strings -
const char *zlib_error_strings[] =
{/*{{{*/
  "error_ZLIB_COMPRESS_INVALID_LEVEL",
  "error_ZLIB_NOT_ENOUGHT_SPACE_IN_BUFFER",
  "error_ZLIB_COMPRESS_ERROR",
  "error_ZLIB_UNCOMPRESS_ERROR",
};/*}}}*/

// - ZLIB initialize -
bool zlib_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize zlib class identifier -
  c_bi_class_zlib = class_base_idx++;

  return true;
}/*}}}*/

// - ZLIB print exception -
bool zlib_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

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
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

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
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int level;

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string ||
      !it.retrieve_integer(src_1_location,level))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_zlib,"compress#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  // - ERROR -
  if (level < 0 || level > 9)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_ZLIB_COMPRESS_INVALID_LEVEL,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(level);

    return false;
  }

  string_s *source_ptr = (string_s *)src_0_location->v_data_ptr;

  // - retrieve maximal target length -
  uLongf target_length = compressBound(source_ptr->size - 1);

  // - create target string -
  string_s *target_ptr = it.get_new_string_ptr();
  target_ptr->create(target_length);

  // - ERROR -
  if (compress2((Bytef *)target_ptr->data,&target_length,(Bytef *)source_ptr->data,source_ptr->size - 1,level) != Z_OK)
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
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int lli_target_length;

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string ||
      !it.retrieve_integer(src_1_location,lli_target_length))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_zlib,"uncompress#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  // - ERROR -
  if (lli_target_length <= 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_ZLIB_NOT_ENOUGHT_SPACE_IN_BUFFER,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  string_s *source_ptr = (string_s *)src_0_location->v_data_ptr;

  // - retrieve target length -
  uLongf target_length = lli_target_length;

  // - create target string -
  string_s *target_ptr = it.get_new_string_ptr();
  target_ptr->create(target_length);

  // - uncompress data -
  int res = uncompress((Bytef *)target_ptr->data,&target_length,(Bytef *)source_ptr->data,source_ptr->size - 1);

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
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("ZLib");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

