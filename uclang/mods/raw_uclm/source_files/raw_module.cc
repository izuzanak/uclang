
@begin
include "raw_module.h"
@end

// - RAW indexes of built in classes -
unsigned c_bi_class_raw_lib = c_idx_not_exist;
unsigned c_bi_class_raw_processor = c_idx_not_exist;
unsigned c_bi_class_raw_image = c_idx_not_exist;

// - RAW module -
EXPORT built_in_module_s module =
{/*{{{*/
  3,                    // Class count
  raw_classes,          // Classes

  0,                    // Error base index
  9,                    // Error count
  raw_error_strings,    // Error strings

  raw_initialize,       // Initialize function
  raw_print_exception,  // Print exceptions function
};/*}}}*/

// - RAW classes -
built_in_class_s *raw_classes[] =
{/*{{{*/
  &raw_lib_class,
  &raw_processor_class,
  &raw_image_class,
};/*}}}*/

// - RAW error strings -
const char *raw_error_strings[] =
{/*{{{*/
  "error_RAW_PROCESSOR_OPEN_FILE_ERROR",
  "error_RAW_PROCESSOR_OPEN_BUFFER_ERROR",
  "error_RAW_PROCESSOR_UNPACK_IMAGE_ERROR",
  "error_RAW_PROCESSOR_UNPACK_THUMBNAIL_ERROR",
  "error_RAW_PROCESSOR_PROCESS_ERROR",
  "error_RAW_PROCESSOR_IMAGE_NOT_PROCESSED_YET",
  "error_RAW_PROCESSOR_MAKE_IMAGE_ERROR",
  "error_RAW_PROCESSOR_MAKE_THUMBNAIL_ERROR",
  "error_RAW_IMAGE_INVALID_IMAGE_TYPE",
};/*}}}*/

// - RAW initialize -
bool raw_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize raw_lib class identifier -
  c_bi_class_raw_lib = class_base_idx++;

  // - initialize raw_processor class identifier -
  c_bi_class_raw_processor = class_base_idx++;

  // - initialize raw_image class identifier -
  c_bi_class_raw_image = class_base_idx++;

  return true;
}/*}}}*/

// - RAW print exception -
bool raw_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_RAW_PROCESSOR_OPEN_FILE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot read raw image from file \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_RAW_PROCESSOR_OPEN_BUFFER_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot read raw image from buffer\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_RAW_PROCESSOR_UNPACK_IMAGE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while unpacking raw image\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_RAW_PROCESSOR_UNPACK_THUMBNAIL_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while unpacking raw image thumbnail\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_RAW_PROCESSOR_PROCESS_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while processing raw image\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_RAW_PROCESSOR_IMAGE_NOT_PROCESSED_YET:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError, raw image was not processed yet\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_RAW_PROCESSOR_MAKE_IMAGE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating processed raw image\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_RAW_PROCESSOR_MAKE_THUMBNAIL_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating raw image thumbnail\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_RAW_IMAGE_INVALID_IMAGE_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid processed raw image type, expected bitmap\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class RAW_LIB -
built_in_class_s raw_lib_class =
{/*{{{*/
  "RawLib",
  c_modifier_public | c_modifier_final,
  5, raw_lib_methods,
  0, raw_lib_variables,
  bic_raw_lib_consts,
  bic_raw_lib_init,
  bic_raw_lib_clear,
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

built_in_method_s raw_lib_methods[] =
{/*{{{*/
  {
    "version#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_raw_lib_method_version_0
  },
  {
    "version_number#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_raw_lib_method_version_number_0
  },
  {
    "camera_list#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_raw_lib_method_camera_list_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_raw_lib_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_raw_lib_method_print_0
  },
};/*}}}*/

built_in_variable_s raw_lib_variables[] =
{/*{{{*/
};/*}}}*/

void bic_raw_lib_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_raw_lib_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_raw_lib_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_raw_lib_method_version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  const char *version = LibRaw::version();

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(version),version);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_raw_lib_method_version_number_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  long long int result = LibRaw::versionNumber();

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_raw_lib_method_camera_list_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  const char **list = LibRaw::cameraList();

  pointer_array_s *array_ptr = it.get_new_array_ptr();
  BIC_CREATE_NEW_LOCATION(array_loc,c_bi_class_array,array_ptr);

  while (*list != nullptr)
  {
    string_s *string_ptr = it.get_new_string_ptr();
    string_ptr->set(strlen(*list),*list);

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
    array_ptr->push(new_location);

    ++list;
  }

  BIC_SET_RESULT(array_loc);

  return true;
}/*}}}*/

bool bic_raw_lib_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("RawLib"),"RawLib");
  );

  return true;
}/*}}}*/

bool bic_raw_lib_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("RawLib");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class RAW_PROCESSOR -
built_in_class_s raw_processor_class =
{/*{{{*/
  "RawProcessor",
  c_modifier_public | c_modifier_final,
  8, raw_processor_methods,
  2, raw_processor_variables,
  bic_raw_processor_consts,
  bic_raw_processor_init,
  bic_raw_processor_clear,
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

built_in_method_s raw_processor_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_raw_processor_operator_binary_equal
  },
  {
    "open_file#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_raw_processor_method_open_file_2
  },
  {
    "open_buffer#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_raw_processor_method_open_buffer_2
  },
  {
    "process#1",
    c_modifier_public | c_modifier_final,
    bic_raw_processor_method_process_1
  },
  {
    "get_image#0",
    c_modifier_public | c_modifier_final,
    bic_raw_processor_method_get_image_0
  },
  {
    "get_thumb#0",
    c_modifier_public | c_modifier_final,
    bic_raw_processor_method_get_thumb_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_raw_processor_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_raw_processor_method_print_0
  },
};/*}}}*/

built_in_variable_s raw_processor_variables[] =
{/*{{{*/

  // - raw processor flag values -
  { "NO_MEMERR_CALLBACK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NO_DATAERR_CALLBACK", c_modifier_public | c_modifier_static | c_modifier_static_const },
};/*}}}*/

void bic_raw_processor_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert raw processor flag values -
  {
    const_locations.push_blanks(2);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 2);

#define CREATE_RAW_PROCESSOR_FLAG_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_RAW_PROCESSOR_FLAG_BIC_STATIC(LIBRAW_OPIONS_NO_MEMERR_CALLBACK);
    CREATE_RAW_PROCESSOR_FLAG_BIC_STATIC(LIBRAW_OPIONS_NO_DATAERR_CALLBACK);
  }

}/*}}}*/

void bic_raw_processor_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (raw_processor_s *)nullptr;
}/*}}}*/

void bic_raw_processor_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  raw_processor_s *rp_ptr = (raw_processor_s *)location_ptr->v_data_ptr;

  if (rp_ptr != nullptr)
  {
    rp_ptr->clear(it);
    cfree(rp_ptr);
  }
}/*}}}*/

bool bic_raw_processor_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_raw_processor_method_open_file_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
path:c_bi_class_string
flags:retrieve_integer
>
class c_bi_class_raw_processor
method open_file
static_method
; @end

  string_s *file_name = (string_s *)src_0_location->v_data_ptr;

  LibRaw *lr_ptr = new LibRaw(flags);

  // - ERROR -
  if (lr_ptr->open_file(file_name->data) != 0)
  {
    delete lr_ptr;

    exception_s::throw_exception(it,module.error_base + c_error_RAW_PROCESSOR_OPEN_FILE_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  // - create raw_processor object -
  raw_processor_s *rp_ptr = (raw_processor_s *)cmalloc(sizeof(raw_processor_s));
  rp_ptr->init();

  rp_ptr->lr_ptr = lr_ptr;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_raw_processor,rp_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_raw_processor_method_open_buffer_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:retrieve_data_buffer
flags:retrieve_integer
>
class c_bi_class_raw_processor
method open_buffer
static_method
; @end

  LibRaw *lr_ptr = new LibRaw(flags);

  // - ERROR -
  if (lr_ptr->open_buffer((void *)data_ptr,data_size) != 0)
  {
    delete lr_ptr;

    exception_s::throw_exception(it,module.error_base + c_error_RAW_PROCESSOR_OPEN_BUFFER_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create raw_processor object -
  raw_processor_s *rp_ptr = (raw_processor_s *)cmalloc(sizeof(raw_processor_s));
  rp_ptr->init();

  // - set source buffer reference -
  src_0_location->v_reference_cnt.atomic_inc();
  rp_ptr->buffer_loc = src_0_location;

  rp_ptr->lr_ptr = lr_ptr;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_raw_processor,rp_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_raw_processor_method_process_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
dcraw_opts:c_bi_class_array
>
method process
; @end

  raw_processor_s *rp_ptr = (raw_processor_s *)dst_location->v_data_ptr;

  // TODO process dcraw options

  // - unpack raw image if needed -
  if (!(rp_ptr->state & c_raw_proc_state_unpacked))
  {
    // - ERROR -
    if (rp_ptr->lr_ptr->unpack() != 0)
    {
      exception_s::throw_exception(it,module.error_base + c_error_RAW_PROCESSOR_UNPACK_IMAGE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    rp_ptr->state |= c_raw_proc_state_unpacked;
  }

  // - ERROR -
  if (rp_ptr->lr_ptr->dcraw_process() != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_RAW_PROCESSOR_PROCESS_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set processed flag -
  rp_ptr->state |= c_raw_proc_state_processed;

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_raw_processor_method_get_image_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  raw_processor_s *rp_ptr = (raw_processor_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (!(rp_ptr->state & c_raw_proc_state_processed))
  {
    exception_s::throw_exception(it,module.error_base + c_error_RAW_PROCESSOR_IMAGE_NOT_PROCESSED_YET,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  libraw_processed_image_t *lrpi_ptr = rp_ptr->lr_ptr->dcraw_make_mem_image(nullptr);

  // - ERROR -
  if (lrpi_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_RAW_PROCESSOR_MAKE_IMAGE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_raw_image,lrpi_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_raw_processor_method_get_thumb_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  raw_processor_s *rp_ptr = (raw_processor_s *)dst_location->v_data_ptr;

  // - unpack raw image thumbnail if needed -
  if (!(rp_ptr->state & c_raw_proc_state_unpacked_thumb))
  {
    // - ERROR -
    if (rp_ptr->lr_ptr->unpack_thumb() != 0)
    {
      exception_s::throw_exception(it,module.error_base + c_error_RAW_PROCESSOR_UNPACK_THUMBNAIL_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }
    
    rp_ptr->state |= c_raw_proc_state_unpacked_thumb;
  }

  libraw_processed_image_t *lrpi_ptr = rp_ptr->lr_ptr->dcraw_make_mem_thumb(nullptr);

  // - ERROR -
  if (lrpi_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_RAW_PROCESSOR_MAKE_THUMBNAIL_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_raw_image,lrpi_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_raw_processor_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("RawProcessor"),"RawProcessor");
  );

  return true;
}/*}}}*/

bool bic_raw_processor_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("RawProcessor");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class RAW_IMAGE -
built_in_class_s raw_image_class =
{/*{{{*/
  "RawImage",
  c_modifier_public | c_modifier_final,
  9, raw_image_methods,
  2, raw_image_variables,
  bic_raw_image_consts,
  bic_raw_image_init,
  bic_raw_image_clear,
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

built_in_method_s raw_image_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_raw_image_operator_binary_equal
  },
  {
    "get_type#0",
    c_modifier_public | c_modifier_final,
    bic_raw_image_method_get_type_0
  },
  {
    "width#0",
    c_modifier_public | c_modifier_final,
    bic_raw_image_method_width_0
  },
  {
    "height#0",
    c_modifier_public | c_modifier_final,
    bic_raw_image_method_height_0
  },
  {
    "colors#0",
    c_modifier_public | c_modifier_final,
    bic_raw_image_method_colors_0
  },
  {
    "bits#0",
    c_modifier_public | c_modifier_final,
    bic_raw_image_method_bits_0
  },
  {
    "buffer#0",
    c_modifier_public | c_modifier_final,
    bic_raw_image_method_buffer_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_raw_image_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_raw_image_method_print_0
  },
};/*}}}*/

built_in_variable_s raw_image_variables[] =
{/*{{{*/

  // - raw image formats -
  { "IMAGE_JPEG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IMAGE_BITMAP", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

#define BIC_RAW_IMAGE_GET_BITMAP_INTEGER(NAME) \
{/*{{{*/\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  libraw_processed_image_t *lrpi_ptr = (libraw_processed_image_t *)dst_location->v_data_ptr;\
\
  /* - ERROR - */\
  if (lrpi_ptr->type != LIBRAW_IMAGE_BITMAP)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_RAW_IMAGE_INVALID_IMAGE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  long long int result = lrpi_ptr->NAME;\
\
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
\
  return true;\
}/*}}}*/

void bic_raw_image_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert raw image formats -
  {
    const_locations.push_blanks(2);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 2);

#define CREATE_RAW_IMAGE_FORMAT_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_RAW_IMAGE_FORMAT_BIC_STATIC(LIBRAW_IMAGE_JPEG);
    CREATE_RAW_IMAGE_FORMAT_BIC_STATIC(LIBRAW_IMAGE_BITMAP);
  }

}/*}}}*/

void bic_raw_image_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (libraw_processed_image_t *)nullptr;
}/*}}}*/

void bic_raw_image_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  libraw_processed_image_t *lrpi_ptr = (libraw_processed_image_t *)location_ptr->v_data_ptr;

  if (lrpi_ptr != nullptr)
  {
    LibRaw::dcraw_clear_mem(lrpi_ptr);
  }
}/*}}}*/

bool bic_raw_image_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_raw_image_method_get_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((libraw_processed_image_t *)dst_location->v_data_ptr)->type;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_raw_image_method_width_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_RAW_IMAGE_GET_BITMAP_INTEGER(width);
}/*}}}*/

bool bic_raw_image_method_height_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_RAW_IMAGE_GET_BITMAP_INTEGER(height);
}/*}}}*/

bool bic_raw_image_method_colors_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_RAW_IMAGE_GET_BITMAP_INTEGER(colors);
}/*}}}*/

bool bic_raw_image_method_bits_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_RAW_IMAGE_GET_BITMAP_INTEGER(bits);
}/*}}}*/

bool bic_raw_image_method_buffer_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  libraw_processed_image_t *lrpi_ptr = (libraw_processed_image_t *)dst_location->v_data_ptr;

  // - create buffer object -
  buffer_s *buffer_ptr = (buffer_s *)cmalloc(sizeof(buffer_s));

  // - set owner reference -
  dst_location->v_reference_cnt.atomic_inc();
  buffer_ptr->owner_ptr = dst_location;

  buffer_ptr->data = lrpi_ptr->data;
  buffer_ptr->size = lrpi_ptr->data_size;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_buffer,buffer_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_raw_image_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("RawImage"),"RawImage");
  );

  return true;
}/*}}}*/

bool bic_raw_image_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("RawImage");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

