
@begin
include "opencv_module.h"
@end

// - OPENCV indexes of built in classes -
unsigned c_bi_class_cv = c_idx_not_exist;
unsigned c_bi_class_cv_mat = c_idx_not_exist;
unsigned c_bi_class_cv_window = c_idx_not_exist;
unsigned c_bi_class_cv_capture = c_idx_not_exist;
unsigned c_bi_class_cv_writer = c_idx_not_exist;

// - OPENCV module -
built_in_module_s module =
{/*{{{*/
  5,                      // Class count
  opencv_classes,         // Classes

  0,                      // Error base index
  15,                      // Error count
  opencv_error_strings,   // Error strings

  opencv_initialize,      // Initialize function
  opencv_print_exception, // Print exceptions function
};/*}}}*/

// - OPENCV classes -
built_in_class_s *opencv_classes[] =
{/*{{{*/
  &cv_class,
  &cv_mat_class,
  &cv_window_class,
  &cv_capture_class,
  &cv_writer_class,
};/*}}}*/

// - OPENCV error strings -
const char *opencv_error_strings[] =
{/*{{{*/
  "error_CV_MAT_ENCODE_PARAMETERS_ERROR",
  "error_CV_MAT_IMAGE_READ_ERROR",
  "error_CV_MAT_IMAGE_WRITE_ERROR",
  "error_CV_MAT_IMAGE_DECODE_ERROR",
  "error_CV_MAT_IMAGE_ENCODE_ERROR",
  "error_CV_WINDOW_CREATE_ERROR",
  "error_CV_WINDOW_SHOW_ERROR",
  "error_CV_CAPTURE_DEVICE_OPEN_ERROR",
  "error_CV_CAPTURE_FILE_OPEN_ERROR",
  "error_CV_CAPTURE_RETRIEVE_ERROR",
  "error_CV_CAPTURE_SET_PROPERTY_ERROR",
  "error_CV_WRITER_TOO_SHORT_FOURCC_CODE",
  "error_CV_WRITER_CREATE_ERROR",
  "error_CV_WRITER_WRITE_WRONG_IMAGE_SIZE",
  "error_CV_WRITER_WRITE_ERROR",
};/*}}}*/

// - OPENCV initialize -
bool opencv_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize cv class identifier -
  c_bi_class_cv = class_base_idx++;

  // - initialize cv_mat class identifier -
  c_bi_class_cv_mat = class_base_idx++;

  // - initialize cv_window class identifier -
  c_bi_class_cv_window = class_base_idx++;

  // - initialize cv_capture class identifier -
  c_bi_class_cv_capture = class_base_idx++;

  // - initialize cv_writer class identifier -
  c_bi_class_cv_writer = class_base_idx++;

  return true;
}/*}}}*/

// - OPENCV print exception -
bool opencv_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_CV_MAT_ENCODE_PARAMETERS_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong opencv image write/encode parameters\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CV_MAT_IMAGE_READ_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while reading image from file \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CV_MAT_IMAGE_WRITE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while writing image to file \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CV_MAT_IMAGE_DECODE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while decoding image from data\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CV_MAT_IMAGE_ENCODE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while encoding image to data\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CV_WINDOW_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating opencv window\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CV_WINDOW_SHOW_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while showing image in opencv window\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CV_CAPTURE_DEVICE_OPEN_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot open video capture device %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CV_CAPTURE_FILE_OPEN_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot open video file \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CV_CAPTURE_RETRIEVE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot retrieve image from video capture\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CV_CAPTURE_SET_PROPERTY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot set video capture property\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CV_WRITER_TOO_SHORT_FOURCC_CODE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nToo short FOURCC digital media format code\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CV_WRITER_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating video writer\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CV_WRITER_WRITE_WRONG_IMAGE_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nDifferent image size, than expected by video writer\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CV_WRITER_WRITE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while writing image to video\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class CV -
built_in_class_s cv_class =
{/*{{{*/
  "Cv",
  c_modifier_public | c_modifier_final,
  3, cv_methods,
  15, cv_variables,
  bic_cv_consts,
  bic_cv_init,
  bic_cv_clear,
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

built_in_method_s cv_methods[] =
{/*{{{*/
  {
    "wait_key#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cv_method_wait_key_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cv_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cv_method_print_0
  },
};/*}}}*/

built_in_variable_s cv_variables[] =
{/*{{{*/
  { "LOAD_IMAGE_UNCHANGED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "LOAD_IMAGE_GRAYSCALE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "LOAD_IMAGE_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "LOAD_IMAGE_ANYDEPTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "LOAD_IMAGE_ANYCOLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },

  { "IMWRITE_JPEG_QUALITY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IMWRITE_PNG_COMPRESSION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IMWRITE_PNG_STRATEGY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IMWRITE_PNG_BILEVEL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IMWRITE_PNG_STRATEGY_DEFAULT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IMWRITE_PNG_STRATEGY_FILTERED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IMWRITE_PNG_STRATEGY_HUFFMAN_ONLY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IMWRITE_PNG_STRATEGY_RLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IMWRITE_PNG_STRATEGY_FIXED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IMWRITE_PXM_BINARY", c_modifier_public | c_modifier_static | c_modifier_static_const },
};/*}}}*/

void bic_cv_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert read image constants -
  {
    const_locations.push_blanks(5);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 5);

#define CREATE_CV_LOAD_IMAGE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_CV_LOAD_IMAGE_BIC_STATIC(CV_LOAD_IMAGE_UNCHANGED);
    CREATE_CV_LOAD_IMAGE_BIC_STATIC(CV_LOAD_IMAGE_GRAYSCALE);
    CREATE_CV_LOAD_IMAGE_BIC_STATIC(CV_LOAD_IMAGE_COLOR);
    CREATE_CV_LOAD_IMAGE_BIC_STATIC(CV_LOAD_IMAGE_ANYDEPTH);
    CREATE_CV_LOAD_IMAGE_BIC_STATIC(CV_LOAD_IMAGE_ANYCOLOR);
  }

  // - insert write image constants -
  {
    const_locations.push_blanks(10);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 10);

#define CREATE_CV_IMWRITE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_CV_IMWRITE_BIC_STATIC(CV_IMWRITE_JPEG_QUALITY);
    CREATE_CV_IMWRITE_BIC_STATIC(CV_IMWRITE_PNG_COMPRESSION);
    CREATE_CV_IMWRITE_BIC_STATIC(CV_IMWRITE_PNG_STRATEGY);
    CREATE_CV_IMWRITE_BIC_STATIC(CV_IMWRITE_PNG_BILEVEL);
    CREATE_CV_IMWRITE_BIC_STATIC(CV_IMWRITE_PNG_STRATEGY_DEFAULT);
    CREATE_CV_IMWRITE_BIC_STATIC(CV_IMWRITE_PNG_STRATEGY_FILTERED);
    CREATE_CV_IMWRITE_BIC_STATIC(CV_IMWRITE_PNG_STRATEGY_HUFFMAN_ONLY);
    CREATE_CV_IMWRITE_BIC_STATIC(CV_IMWRITE_PNG_STRATEGY_RLE);
    CREATE_CV_IMWRITE_BIC_STATIC(CV_IMWRITE_PNG_STRATEGY_FIXED);
    CREATE_CV_IMWRITE_BIC_STATIC(CV_IMWRITE_PXM_BINARY);
  }

}/*}}}*/

void bic_cv_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_cv_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_cv_method_wait_key_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int delay;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,delay))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_cv,"wait_key#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  long long int result = waitKey(delay);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_cv_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Cv"),"Cv");
  );

  return true;
}/*}}}*/

bool bic_cv_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Cv");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class CV_MAT -
built_in_class_s cv_mat_class =
{/*{{{*/
  "CvMat",
  c_modifier_public | c_modifier_final,
  8, cv_mat_methods,
  0, cv_mat_variables,
  bic_cv_mat_consts,
  bic_cv_mat_init,
  bic_cv_mat_clear,
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

built_in_method_s cv_mat_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_cv_mat_operator_binary_equal
  },
  {
    "CvMat#1",
    c_modifier_public | c_modifier_final,
    bic_cv_mat_method_CvMat_1
  },
  {
    "read#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cv_mat_method_read_2
  },
  {
    "write#2",
    c_modifier_public | c_modifier_final,
    bic_cv_mat_method_write_2
  },
  {
    "decode#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cv_mat_method_decode_2
  },
  {
    "encode#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cv_mat_method_encode_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cv_mat_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cv_mat_method_print_0
  },
};/*}}}*/

built_in_variable_s cv_mat_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_CV_MAT_IMWRITE_PARAMETERS(ERROR_CODE) \
/*{{{*/\
\
  /* - ERROR - */\
  if (array_ptr->used & 0x01)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_CV_MAT_ENCODE_PARAMETERS_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    ERROR_CODE;\
  }\
\
  vector<int> params;\
\
  if (array_ptr->used != 0)\
  {\
    long long int value;\
\
    pointer *p_ptr = array_ptr->data;\
    pointer *p_ptr_end = p_ptr + array_ptr->used;\
    do {\
      location_s *item_location = it.get_location_value(*p_ptr);\
\
      /* - ERROR - */\
      if (!it.retrieve_integer(item_location,value))\
      {\
        exception_s::throw_exception(it,module.error_base + c_error_CV_MAT_ENCODE_PARAMETERS_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
        ERROR_CODE;\
      }\
\
      params.push_back(value);\
    } while(++p_ptr < p_ptr_end);\
  }\
/*}}}*/

void bic_cv_mat_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_cv_mat_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (Mat *)nullptr;
}/*}}}*/

void bic_cv_mat_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  Mat *mat_ptr = (Mat *)location_ptr->v_data_ptr;

  if (mat_ptr != nullptr)
  {
    delete mat_ptr;
  }
}/*}}}*/

bool bic_cv_mat_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_cv_mat_method_CvMat_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/

  // FIXME TODO continue ...
  BIC_TODO_ERROR(__FILE__,__LINE__);
  return false;
}/*}}}*/

bool bic_cv_mat_method_read_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int flags;

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string ||
      !it.retrieve_integer(src_1_location,flags))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_cv_mat,"read#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create cv mat object -
  Mat *mat_ptr = new Mat();

  // - read image from file -
  *mat_ptr = imread(string_ptr->data,flags);

  // - ERROR -
  if (mat_ptr->data == nullptr)
  {
    delete mat_ptr;

    exception_s::throw_exception(it,module.error_base + c_error_CV_MAT_IMAGE_READ_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_cv_mat,mat_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_cv_mat_method_write_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string ||
      src_1_location->v_type != c_bi_class_array)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("write#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  Mat *mat_ptr = (Mat *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;
  pointer_array_s *array_ptr = (pointer_array_s *)src_1_location->v_data_ptr;

  BIC_CV_MAT_IMWRITE_PARAMETERS(return false);

  bool error = false;

  try
  {
    // - write image to file -
    error = !imwrite(string_ptr->data,*mat_ptr,params);
  }
  catch (const cv::Exception &e)
  {
    error = true;
  }

  // - ERROR -
  if (error)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CV_MAT_IMAGE_WRITE_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_cv_mat_method_decode_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int flags;

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string ||
      !it.retrieve_integer(src_1_location,flags))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_cv_mat,"decode#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create cv mat object -
  Mat *mat_ptr = new Mat();

  // - decode image from buffer -
  *mat_ptr = imdecode(Mat(1,string_ptr->size - 1,CV_8UC1,string_ptr->data),flags);

  // - ERROR -
  if (mat_ptr->data == nullptr)
  {
    delete mat_ptr;

    exception_s::throw_exception(it,module.error_base + c_error_CV_MAT_IMAGE_DECODE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_cv_mat,mat_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_cv_mat_method_encode_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string ||
      src_1_location->v_type != c_bi_class_array)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("encode#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  Mat *mat_ptr = (Mat *)dst_location->v_data_ptr;
  string_s *extension_ptr = (string_s *)src_0_location->v_data_ptr;
  pointer_array_s *array_ptr = (pointer_array_s *)src_1_location->v_data_ptr;

  BIC_CV_MAT_IMWRITE_PARAMETERS(return false);

  bool error = false;
  vector<unsigned char> data;

  try
  {
    // - write image to file -
    error = !imencode(extension_ptr->data,*mat_ptr,data,params);
  }
  catch (const cv::Exception &e)
  {
    error = true;
  }

  // - ERROR -
  if (error)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CV_MAT_IMAGE_ENCODE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  string_s *data_ptr = it.get_new_string_ptr();
  data_ptr->set(data.size(),(char *)data.data());

  BIC_SET_RESULT_STRING(data_ptr);

  return true;
}/*}}}*/

bool bic_cv_mat_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("CvMat"),"CvMat");
  );

  return true;
}/*}}}*/

bool bic_cv_mat_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("CvMat");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class CV_WINDOW -
built_in_class_s cv_window_class =
{/*{{{*/
  "CvWindow",
  c_modifier_public | c_modifier_final,
  5, cv_window_methods,
  0, cv_window_variables,
  bic_cv_window_consts,
  bic_cv_window_init,
  bic_cv_window_clear,
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

built_in_method_s cv_window_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_cv_window_operator_binary_equal
  },
  {
    "CvWindow#1",
    c_modifier_public | c_modifier_final,
    bic_cv_window_method_CvWindow_1
  },
  {
    "show#1",
    c_modifier_public | c_modifier_final,
    bic_cv_window_method_show_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cv_window_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cv_window_method_print_0
  },
};/*}}}*/

built_in_variable_s cv_window_variables[] =
{/*{{{*/
};/*}}}*/

void bic_cv_window_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_cv_window_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (cv_window_s *)nullptr;
}/*}}}*/

void bic_cv_window_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cv_window_s *win_ptr = (cv_window_s *)location_ptr->v_data_ptr;

  if (win_ptr != nullptr)
  {
    try
    {
      // - destroy opencv window -
      destroyWindow(win_ptr->name.data);
    }
    catch (const cv::Exception &e)
    {
    }

    win_ptr->clear(it);
    cfree(win_ptr);
  }
}/*}}}*/

bool bic_cv_window_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_cv_window_method_CvWindow_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("CvWindow#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  try
  {
    // - create opencv window -
    cvNamedWindow(string_ptr->data);
  }

  // - ERROR -
  catch (const cv::Exception &e)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CV_WINDOW_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create cv window object -
  cv_window_s *win_ptr = (cv_window_s *)cmalloc(sizeof(cv_window_s));
  win_ptr->init();

  win_ptr->name = *string_ptr;

  dst_location->v_data_ptr = (cv_window_s *)win_ptr;

  return true;
}/*}}}*/

bool bic_cv_window_method_show_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_cv_mat)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("show#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  cv_window_s *win_ptr = (cv_window_s *)dst_location->v_data_ptr;
  Mat *mat_ptr = (Mat *)src_0_location->v_data_ptr;

  try
  {
    // - show image in window -
    imshow(win_ptr->name.data,*mat_ptr);
  }

  // - ERROR -
  catch (const cv::Exception &e)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CV_WINDOW_SHOW_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_cv_window_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("CvWindow"),"CvWindow");
  );

  return true;
}/*}}}*/

bool bic_cv_window_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("CvWindow");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class CV_CAPTURE -
built_in_class_s cv_capture_class =
{/*{{{*/
  "CvCapture",
  c_modifier_public | c_modifier_final,
  11, cv_capture_methods,
  115, cv_capture_variables,
  bic_cv_capture_consts,
  bic_cv_capture_init,
  bic_cv_capture_clear,
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

built_in_method_s cv_capture_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_cv_capture_operator_binary_equal
  },
  {
    "CvCapture#1",
    c_modifier_public | c_modifier_final,
    bic_cv_capture_method_CvCapture_1
  },
  {
    "grab#0",
    c_modifier_public | c_modifier_final,
    bic_cv_capture_method_grab_0
  },
  {
    "retrieve#0",
    c_modifier_public | c_modifier_final,
    bic_cv_capture_method_retrieve_0
  },
  {
    "retrieve#1",
    c_modifier_public | c_modifier_final,
    bic_cv_capture_method_retrieve_1
  },
  {
    "width#0",
    c_modifier_public | c_modifier_final,
    bic_cv_capture_method_width_0
  },
  {
    "height#0",
    c_modifier_public | c_modifier_final,
    bic_cv_capture_method_height_0
  },
  {
    "get#1",
    c_modifier_public | c_modifier_final,
    bic_cv_capture_method_get_1
  },
  {
    "set#2",
    c_modifier_public | c_modifier_final,
    bic_cv_capture_method_set_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cv_capture_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cv_capture_method_print_0
  },
};/*}}}*/

built_in_variable_s cv_capture_variables[] =
{/*{{{*/
  { "PROP_POS_MSEC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_POS_FRAMES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_POS_AVI_RATIO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_FRAME_WIDTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_FRAME_HEIGHT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_FPS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_FOURCC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_FRAME_COUNT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_FORMAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_BRIGHTNESS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_CONTRAST", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_SATURATION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_HUE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_GAIN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_EXPOSURE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_CONVERT_RGB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_WHITE_BALANCE_BLUE_U", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_RECTIFICATION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_MONOCROME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_SHARPNESS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_AUTO_EXPOSURE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_GAMMA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_TEMPERATURE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_TRIGGER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_TRIGGER_DELAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_WHITE_BALANCE_RED_V", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_ZOOM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_FOCUS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_GUID", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_ISO_SPEED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_MAX_DC1394", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_BACKLIGHT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_PAN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_TILT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_ROLL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_IRIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_SETTINGS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_AUTOGRAB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_SUPPORTED_PREVIEW_SIZES_STRING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_PREVIEW_FORMAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPENNI_DEPTH_GENERATOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPENNI_IMAGE_GENERATOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPENNI_GENERATORS_MASK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_OPENNI_OUTPUT_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_OPENNI_FRAME_MAX_DEPTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_OPENNI_BASELINE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_OPENNI_FOCAL_LENGTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_OPENNI_REGISTRATION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_OPENNI_REGISTRATION_ON", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_OPENNI_APPROX_FRAME_SYNC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_OPENNI_MAX_BUFFER_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_OPENNI_CIRCLE_BUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_OPENNI_MAX_TIME_DURATION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_OPENNI_GENERATOR_PRESENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPENNI_IMAGE_GENERATOR_PRESENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPENNI_IMAGE_GENERATOR_OUTPUT_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPENNI_DEPTH_GENERATOR_BASELINE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPENNI_DEPTH_GENERATOR_FOCAL_LENGTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPENNI_DEPTH_GENERATOR_REGISTRATION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPENNI_DEPTH_GENERATOR_REGISTRATION_ON", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GSTREAMER_QUEUE_LENGTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_PVAPI_MULTICASTIP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_XI_DOWNSAMPLING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_XI_DATA_FORMAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_XI_OFFSET_X", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_XI_OFFSET_Y", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_XI_TRG_SOURCE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_XI_TRG_SOFTWARE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_XI_GPI_SELECTOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_XI_GPI_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_XI_GPI_LEVEL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_XI_GPO_SELECTOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_XI_GPO_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_XI_LED_SELECTOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_XI_LED_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_XI_MANUAL_WB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_XI_AUTO_WB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_XI_AEAG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_XI_EXP_PRIORITY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_XI_AE_MAX_LIMIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_XI_AG_MAX_LIMIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_XI_AEAG_LEVEL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_XI_TIMEOUT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_ANDROID_FLASH_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_ANDROID_FOCUS_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_ANDROID_WHITE_BALANCE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_ANDROID_ANTIBANDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_ANDROID_FOCAL_LENGTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_ANDROID_FOCUS_DISTANCE_NEAR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_ANDROID_FOCUS_DISTANCE_OPTIMAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_ANDROID_FOCUS_DISTANCE_FAR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_ANDROID_EXPOSE_LOCK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_ANDROID_WHITEBALANCE_LOCK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_IOS_DEVICE_FOCUS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_IOS_DEVICE_EXPOSURE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_IOS_DEVICE_FLASH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_IOS_DEVICE_WHITEBALANCE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_IOS_DEVICE_TORCH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_GIGA_FRAME_OFFSET_X", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_GIGA_FRAME_OFFSET_Y", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_GIGA_FRAME_WIDTH_MAX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_GIGA_FRAME_HEIGH_MAX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_GIGA_FRAME_SENS_WIDTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_GIGA_FRAME_SENS_HEIGH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_INTELPERC_PROFILE_COUNT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_INTELPERC_PROFILE_IDX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_INTELPERC_DEPTH_LOW_CONFIDENCE_VALUE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_INTELPERC_DEPTH_SATURATION_VALUE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_INTELPERC_DEPTH_CONFIDENCE_THRESHOLD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_INTELPERC_DEPTH_FOCAL_LENGTH_HORZ", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROP_INTELPERC_DEPTH_FOCAL_LENGTH_VERT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INTELPERC_DEPTH_GENERATOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INTELPERC_IMAGE_GENERATOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INTELPERC_GENERATORS_MASK", c_modifier_public | c_modifier_static | c_modifier_static_const },
};/*}}}*/

void bic_cv_capture_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert video capture property id constants -
  {
    const_locations.push_blanks(115);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 115);

#define CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_POS_MSEC);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_POS_FRAMES);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_POS_AVI_RATIO);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_FRAME_WIDTH);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_FRAME_HEIGHT);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_FPS);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_FOURCC);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_FRAME_COUNT);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_FORMAT);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_MODE);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_BRIGHTNESS);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_CONTRAST);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_SATURATION);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_HUE);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_GAIN);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_EXPOSURE);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_CONVERT_RGB);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_WHITE_BALANCE_BLUE_U);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_RECTIFICATION);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_MONOCROME);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_SHARPNESS);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_AUTO_EXPOSURE);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_GAMMA);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_TEMPERATURE);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_TRIGGER);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_TRIGGER_DELAY);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_WHITE_BALANCE_RED_V);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_ZOOM);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_FOCUS);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_GUID);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_ISO_SPEED);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_MAX_DC1394);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_BACKLIGHT);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_PAN);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_TILT);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_ROLL);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_IRIS);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_SETTINGS);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_AUTOGRAB);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_SUPPORTED_PREVIEW_SIZES_STRING);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_PREVIEW_FORMAT);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_OPENNI_DEPTH_GENERATOR);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_OPENNI_IMAGE_GENERATOR);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_OPENNI_GENERATORS_MASK);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_OPENNI_OUTPUT_MODE);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_OPENNI_FRAME_MAX_DEPTH);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_OPENNI_BASELINE);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_OPENNI_FOCAL_LENGTH);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_OPENNI_REGISTRATION);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_OPENNI_REGISTRATION_ON);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_OPENNI_APPROX_FRAME_SYNC);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_OPENNI_MAX_BUFFER_SIZE);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_OPENNI_CIRCLE_BUFFER);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_OPENNI_MAX_TIME_DURATION);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_OPENNI_GENERATOR_PRESENT);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_OPENNI_IMAGE_GENERATOR_PRESENT);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_OPENNI_IMAGE_GENERATOR_OUTPUT_MODE);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_OPENNI_DEPTH_GENERATOR_BASELINE);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_OPENNI_DEPTH_GENERATOR_FOCAL_LENGTH);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_OPENNI_DEPTH_GENERATOR_REGISTRATION);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_OPENNI_DEPTH_GENERATOR_REGISTRATION_ON);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_GSTREAMER_QUEUE_LENGTH);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_PVAPI_MULTICASTIP);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_XI_DOWNSAMPLING);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_XI_DATA_FORMAT);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_XI_OFFSET_X);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_XI_OFFSET_Y);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_XI_TRG_SOURCE);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_XI_TRG_SOFTWARE);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_XI_GPI_SELECTOR);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_XI_GPI_MODE);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_XI_GPI_LEVEL);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_XI_GPO_SELECTOR);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_XI_GPO_MODE);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_XI_LED_SELECTOR);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_XI_LED_MODE);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_XI_MANUAL_WB);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_XI_AUTO_WB);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_XI_AEAG);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_XI_EXP_PRIORITY);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_XI_AE_MAX_LIMIT);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_XI_AG_MAX_LIMIT);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_XI_AEAG_LEVEL);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_XI_TIMEOUT);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_ANDROID_FLASH_MODE);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_ANDROID_FOCUS_MODE);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_ANDROID_WHITE_BALANCE);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_ANDROID_ANTIBANDING);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_ANDROID_FOCAL_LENGTH);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_ANDROID_FOCUS_DISTANCE_NEAR);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_ANDROID_FOCUS_DISTANCE_OPTIMAL);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_ANDROID_FOCUS_DISTANCE_FAR);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_ANDROID_EXPOSE_LOCK);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_ANDROID_WHITEBALANCE_LOCK);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_IOS_DEVICE_FOCUS);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_IOS_DEVICE_EXPOSURE);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_IOS_DEVICE_FLASH);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_IOS_DEVICE_WHITEBALANCE);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_IOS_DEVICE_TORCH);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_GIGA_FRAME_OFFSET_X);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_GIGA_FRAME_OFFSET_Y);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_GIGA_FRAME_WIDTH_MAX);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_GIGA_FRAME_HEIGH_MAX);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_GIGA_FRAME_SENS_WIDTH);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_GIGA_FRAME_SENS_HEIGH);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_INTELPERC_PROFILE_COUNT);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_INTELPERC_PROFILE_IDX);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_INTELPERC_DEPTH_LOW_CONFIDENCE_VALUE);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_INTELPERC_DEPTH_SATURATION_VALUE);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_INTELPERC_DEPTH_CONFIDENCE_THRESHOLD);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_INTELPERC_DEPTH_FOCAL_LENGTH_HORZ);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_PROP_INTELPERC_DEPTH_FOCAL_LENGTH_VERT);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_INTELPERC_DEPTH_GENERATOR);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_INTELPERC_IMAGE_GENERATOR);
    CREATE_CV_CAPTURE_PROP_ID_BIC_STATIC(CV_CAP_INTELPERC_GENERATORS_MASK);
  }

}/*}}}*/

void bic_cv_capture_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (VideoCapture *)nullptr;
}/*}}}*/

void bic_cv_capture_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  VideoCapture *vc_ptr = (VideoCapture *)location_ptr->v_data_ptr;

  if (vc_ptr != nullptr)
  {
    // - if video capture is opened -
    if (vc_ptr->isOpened())
    {
      vc_ptr->release();
    }

    delete vc_ptr;
  }
}/*}}}*/

bool bic_cv_capture_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_cv_capture_method_CvCapture_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    long long int device;

    // - ERROR -
    if (!it.retrieve_integer(src_0_location,device))
    {
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
      BIC_EXCEPTION_PUSH_METHOD_RI("CvCapture#1");
      new_exception->params.push(1);
      new_exception->params.push(src_0_location->v_type);

      return false;
    }

    VideoCapture *vc_ptr = new VideoCapture();

    // - ERROR -
    if (!vc_ptr->open(device))
    {
      delete vc_ptr;

      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_CV_CAPTURE_DEVICE_OPEN_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(device);

      return false;
    }

    dst_location->v_data_ptr = (VideoCapture *)vc_ptr;
  }
  else
  {
    string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;
    VideoCapture *vc_ptr = new VideoCapture();

    // - ERROR -
    if (!vc_ptr->open(string_ptr->data))
    {
      delete vc_ptr;

      exception_s::throw_exception(it,module.error_base + c_error_CV_CAPTURE_FILE_OPEN_ERROR,operands[c_source_pos_idx],src_0_location);
      return false;
    }

    dst_location->v_data_ptr = (VideoCapture *)vc_ptr;
  }

  return true;
}/*}}}*/

bool bic_cv_capture_method_grab_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  VideoCapture *vc_ptr = (VideoCapture *)dst_location->v_data_ptr;

  long long int result = vc_ptr->grab();

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_cv_capture_method_retrieve_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  VideoCapture *vc_ptr = (VideoCapture *)dst_location->v_data_ptr;
  Mat *mat_ptr = new Mat();

  // - ERROR -
  if (!vc_ptr->retrieve(*mat_ptr))
  {
    delete mat_ptr;

    exception_s::throw_exception(it,module.error_base + c_error_CV_CAPTURE_RETRIEVE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_cv_mat,mat_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_cv_capture_method_retrieve_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_cv_mat)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("retrieve#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  VideoCapture *vc_ptr = (VideoCapture *)dst_location->v_data_ptr;
  Mat *mat_ptr = (Mat *)src_0_location->v_data_ptr;

  // - ERROR -
  if (!vc_ptr->retrieve(*mat_ptr))
  {
    exception_s::throw_exception(it,module.error_base + c_error_CV_CAPTURE_RETRIEVE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_cv_capture_method_width_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  VideoCapture *vc_ptr = (VideoCapture *)dst_location->v_data_ptr;
  long long int result = vc_ptr->get(CV_CAP_PROP_FRAME_WIDTH);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_cv_capture_method_height_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  VideoCapture *vc_ptr = (VideoCapture *)dst_location->v_data_ptr;
  long long int result = vc_ptr->get(CV_CAP_PROP_FRAME_HEIGHT);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_cv_capture_method_get_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int prop_id;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,prop_id))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("get#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  VideoCapture *vc_ptr = (VideoCapture *)dst_location->v_data_ptr;
  double result = vc_ptr->get(prop_id);

  BIC_SIMPLE_SET_RES(c_bi_class_float,result);

  return true;
}/*}}}*/

bool bic_cv_capture_method_set_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int prop_id;
  double value;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,prop_id) ||
      !it.retrieve_float(src_1_location,value))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("set#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  VideoCapture *vc_ptr = (VideoCapture *)dst_location->v_data_ptr;

  // - ERROR -
  if (vc_ptr->set(prop_id,value))
  {
    exception_s::throw_exception(it,module.error_base + c_error_CV_CAPTURE_SET_PROPERTY_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_cv_capture_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("CvCapture"),"CvCapture");
  );

  return true;
}/*}}}*/

bool bic_cv_capture_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("CvCapture");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class CV_WRITER -
built_in_class_s cv_writer_class =
{/*{{{*/
  "CvWriter",
  c_modifier_public | c_modifier_final,
  7, cv_writer_methods,
  0, cv_writer_variables,
  bic_cv_writer_consts,
  bic_cv_writer_init,
  bic_cv_writer_clear,
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

built_in_method_s cv_writer_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_cv_writer_operator_binary_equal
  },
  {
    "CvWriter#6",
    c_modifier_public | c_modifier_final,
    bic_cv_writer_method_CvWriter_6
  },
  {
    "width#0",
    c_modifier_public | c_modifier_final,
    bic_cv_writer_method_width_0
  },
  {
    "height#0",
    c_modifier_public | c_modifier_final,
    bic_cv_writer_method_height_0
  },
  {
    "write#1",
    c_modifier_public | c_modifier_final,
    bic_cv_writer_method_write_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cv_writer_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cv_writer_method_print_0
  },
};/*}}}*/

built_in_variable_s cv_writer_variables[] =
{/*{{{*/
};/*}}}*/

void bic_cv_writer_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_cv_writer_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (cv_writer_s *)nullptr;
}/*}}}*/

void bic_cv_writer_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cv_writer_s *vw_ptr = (cv_writer_s *)location_ptr->v_data_ptr;

  if (vw_ptr != nullptr)
  {
    vw_ptr->clear(it);
    cfree(vw_ptr);
  }
}/*}}}*/

bool bic_cv_writer_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_cv_writer_method_CvWriter_6(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);
  location_s *src_3_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_3_op_idx]);
  location_s *src_4_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_4_op_idx]);
  location_s *src_5_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_5_op_idx]);

  long long int fps;
  long long int width;
  long long int height;
  long long int color;

  if (src_0_location->v_type != c_bi_class_string ||
      src_1_location->v_type != c_bi_class_string ||
      !it.retrieve_integer(src_2_location,fps) ||
      !it.retrieve_integer(src_3_location,width) ||
      !it.retrieve_integer(src_4_location,height) ||
      !it.retrieve_integer(src_5_location,color))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("CvWriter#6");
    new_exception->params.push(6);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);
    new_exception->params.push(src_3_location->v_type);
    new_exception->params.push(src_4_location->v_type);
    new_exception->params.push(src_5_location->v_type);

    return false;
  }

  string_s *name_ptr = (string_s *)src_0_location->v_data_ptr;
  string_s *fourcc_ptr = (string_s *)src_1_location->v_data_ptr;

  // - ERROR -
  if (fourcc_ptr->size < 5)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CV_WRITER_TOO_SHORT_FOURCC_CODE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  char *fcc_ptr = fourcc_ptr->data;
  int fourcc = CV_FOURCC_MACRO(fcc_ptr[0],fcc_ptr[1],fcc_ptr[2],fcc_ptr[3]);

  VideoWriter *writer_ptr = new VideoWriter();

  // - ERROR -
  if (!writer_ptr->open(name_ptr->data,fourcc,fps,Size(width,height),color))
  {
    delete writer_ptr;

    exception_s::throw_exception(it,module.error_base + c_error_CV_WRITER_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create writer object -
  cv_writer_s *vw_ptr = (cv_writer_s *)cmalloc(sizeof(cv_writer_s));
  vw_ptr->init();

  vw_ptr->width = width;
  vw_ptr->height = height;
  vw_ptr->writer_ptr = writer_ptr;

  dst_location->v_data_ptr = (cv_writer_s *)vw_ptr;

  return true;
}/*}}}*/

bool bic_cv_writer_method_width_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  cv_writer_s *vw_ptr = (cv_writer_s *)dst_location->v_data_ptr;

  long long int result = vw_ptr->width;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_cv_writer_method_height_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  cv_writer_s *vw_ptr = (cv_writer_s *)dst_location->v_data_ptr;

  long long int result = vw_ptr->height;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_cv_writer_method_write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_cv_mat)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("write#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  cv_writer_s *vw_ptr = (cv_writer_s *)dst_location->v_data_ptr;
  Mat *mat_ptr = (Mat *)src_0_location->v_data_ptr;

  // - ERROR -
  if (vw_ptr->width != mat_ptr->cols || vw_ptr->height != mat_ptr->rows)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CV_WRITER_WRITE_WRONG_IMAGE_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  try
  {
    vw_ptr->writer_ptr->write(*mat_ptr);
  }

  // - ERROR -
  catch (const cv::Exception &e)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CV_WRITER_WRITE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_cv_writer_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("CvWriter"),"CvWriter");
  );

  return true;
}/*}}}*/

bool bic_cv_writer_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("CvWriter");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

