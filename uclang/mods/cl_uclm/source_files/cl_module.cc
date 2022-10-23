
@begin
include "cl_module.h"
@end

// - CL indexes of built in classes -
unsigned c_bi_class_cl = c_idx_not_exist;
unsigned c_bi_class_cl_platform = c_idx_not_exist;
unsigned c_bi_class_cl_device = c_idx_not_exist;

// - CL module -
EXPORT built_in_module_s module =
{/*{{{*/
  3,                   // Class count
  cl_classes,          // Classes

  0,                   // Error base index
  1,                   // Error count
  cl_error_strings,    // Error strings

  cl_initialize,       // Initialize function
  cl_print_exception,  // Print exceptions function
};/*}}}*/

// - CL classes -
built_in_class_s *cl_classes[] =
{/*{{{*/
  &cl_class,
  &cl_platform_class,
  &cl_device_class,
};/*}}}*/

// - CL error strings -
const char *cl_error_strings[] =
{/*{{{*/
  "error_CL_DUMMY_ERROR",
};/*}}}*/

// - CL initialize -
bool cl_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize cl class identifier -
  c_bi_class_cl = class_base_idx++;

  // - initialize cl_platform class identifier -
  c_bi_class_cl_platform = class_base_idx++;

  // - initialize cl_device class identifier -
  c_bi_class_cl_device = class_base_idx++;

  return true;
}/*}}}*/

// - CL print exception -
bool cl_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_CL_DUMMY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nOpenCL dummy error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class CL -
built_in_class_s cl_class =
{/*{{{*/
  "Cl",
  c_modifier_public | c_modifier_final,
  3, cl_methods,
  0, cl_variables,
  bic_cl_consts,
  bic_cl_init,
  bic_cl_clear,
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

built_in_method_s cl_methods[] =
{/*{{{*/
  {
    "get_platforms#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cl_method_get_platforms_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cl_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cl_method_print_0
  },
};/*}}}*/

built_in_variable_s cl_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_cl_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_cl_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_cl_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_cl_method_get_platforms_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  cl_uint num_platforms = 0;

  // - ERROR -
  if (clGetPlatformIDs(0,nullptr,&num_platforms) != CL_SUCCESS)
  {
    // FIXME TODO throw proper exception ...
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  cl_platform_id platforms[num_platforms];

  // - ERROR -
  if (clGetPlatformIDs(num_platforms,platforms,nullptr) != CL_SUCCESS)
  {
    // FIXME TODO throw proper exception ...
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  // - create new array pointer -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  // - some platforms were found -
  if (num_platforms > 0)
  {
    cl_platform_id *pi_ptr = platforms;
    cl_platform_id *pi_ptr_end = pi_ptr + num_platforms;
    do {

      // - create new platform id location -
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_cl_platform,*pi_ptr);

      // - insert platform id location to pointer array -
      array_ptr->push((pointer)new_location);

    } while(++pi_ptr < pi_ptr_end);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_cl_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Cl"),"Cl");
  );

  return true;
}/*}}}*/

bool bic_cl_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Cl");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class CL_PLATFORM -
built_in_class_s cl_platform_class =
{/*{{{*/
  "ClPlatform",
  c_modifier_public | c_modifier_final,
  5, cl_platform_methods,
  7, cl_platform_variables,
  bic_cl_platform_consts,
  bic_cl_platform_init,
  bic_cl_platform_clear,
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

built_in_method_s cl_platform_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_cl_platform_operator_binary_equal
  },
  {
    "info#1",
    c_modifier_public | c_modifier_final,
    bic_cl_platform_method_info_1
  },
  {
    "get_devices#1",
    c_modifier_public | c_modifier_final,
    bic_cl_platform_method_get_devices_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cl_platform_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cl_platform_method_print_0
  },
};/*}}}*/

built_in_variable_s cl_platform_variables[] =
{/*{{{*/

  // - cl platform info values -
  { "PROFILE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VERSION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NAME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VENDOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EXTENSIONS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HOST_TIMER_RESOLUTION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ICD_SUFFIX_KHR", c_modifier_public | c_modifier_static | c_modifier_static_const },
};/*}}}*/

void bic_cl_platform_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert cl platform info values -
  {
    const_locations.push_blanks(7);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 7);

#define CREATE_CL_PLATFORM_INFO_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_CL_PLATFORM_INFO_BIC_STATIC(CL_PLATFORM_PROFILE);
    CREATE_CL_PLATFORM_INFO_BIC_STATIC(CL_PLATFORM_VERSION);
    CREATE_CL_PLATFORM_INFO_BIC_STATIC(CL_PLATFORM_NAME);
    CREATE_CL_PLATFORM_INFO_BIC_STATIC(CL_PLATFORM_VENDOR);
    CREATE_CL_PLATFORM_INFO_BIC_STATIC(CL_PLATFORM_EXTENSIONS);
    CREATE_CL_PLATFORM_INFO_BIC_STATIC(CL_PLATFORM_HOST_TIMER_RESOLUTION);
    CREATE_CL_PLATFORM_INFO_BIC_STATIC(CL_PLATFORM_ICD_SUFFIX_KHR);
  }
}/*}}}*/

void bic_cl_platform_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (cl_platform_id)nullptr;
}/*}}}*/

void bic_cl_platform_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

bool bic_cl_platform_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_cl_platform_method_info_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
name:retrieve_integer
>
method info
; @end

  // - retrieve platform id -
  cl_platform_id platform_id = (cl_platform_id)dst_location->v_data_ptr;

  size_t param_value_size;

  switch (name)
  {
    case CL_PLATFORM_PROFILE:
    case CL_PLATFORM_VERSION:
    case CL_PLATFORM_NAME:
    case CL_PLATFORM_VENDOR:
    case CL_PLATFORM_EXTENSIONS:
    case CL_PLATFORM_ICD_SUFFIX_KHR:
      {/*{{{*/

        // - ERROR -
        if (clGetPlatformInfo(platform_id,name,0,nullptr,&param_value_size) != CL_SUCCESS)
        {
          // FIXME TODO throw proper exception ...
          BIC_TODO_ERROR(__FILE__,__LINE__);
          return false;
        }

        string_s *string_ptr = it.get_new_string_ptr();
        string_ptr->create(param_value_size);

        // - ERROR -
        if (clGetPlatformInfo(platform_id,name,string_ptr->size - 1,string_ptr->data,nullptr) != CL_SUCCESS)
        {
          string_ptr->clear();
          cfree(string_ptr);

          // FIXME TODO throw proper exception ...
          BIC_TODO_ERROR(__FILE__,__LINE__);
          return false;
        }

        BIC_SET_RESULT_STRING(string_ptr);
      }/*}}}*/
      break;
    case CL_PLATFORM_HOST_TIMER_RESOLUTION:
      {/*{{{*/
        cl_ulong value;

        // - ERROR -
        if (clGetPlatformInfo(platform_id,name,sizeof(cl_ulong),&value,nullptr) != CL_SUCCESS)
        {
          // FIXME TODO throw proper exception ...
          BIC_TODO_ERROR(__FILE__,__LINE__);
          return false;
        }

        long long int result = value;

        BIC_SIMPLE_SET_RES(c_bi_class_integer,result);
      }/*}}}*/
      break;

    // - ERROR -
    default:

      // FIXME TODO throw proper exception ...
      BIC_TODO_ERROR(__FILE__,__LINE__);
      return false;
  }

  return true;
}/*}}}*/

bool bic_cl_platform_method_get_devices_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
device_type:retrieve_integer
>
method get_device_ids
; @end

  // - retrieve platform id -
  cl_platform_id platform_id = (cl_platform_id)dst_location->v_data_ptr;

  cl_uint num_devices = 0;

  // - ERROR -
  if (clGetDeviceIDs(platform_id,device_type,0,nullptr,&num_devices) != CL_SUCCESS)
  {
    // FIXME TODO throw proper exception ...
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  cl_device_id devices[num_devices];

  // - ERROR -
  if (clGetDeviceIDs(platform_id,device_type,num_devices,devices,nullptr) != CL_SUCCESS)
  {
    // FIXME TODO throw proper exception ...
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  // - create new array pointer -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  // - some devices were found -
  if (num_devices > 0)
  {
    cl_device_id *di_ptr = devices;
    cl_device_id *di_ptr_end = di_ptr + num_devices;
    do {

      // - create new device id location -
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_cl_device,*di_ptr);

      // - insert device id location to pointer array -
      array_ptr->push((pointer)new_location);

    } while(++di_ptr < di_ptr_end);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_cl_platform_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("ClPlatform"),"ClPlatform");
  );

  return true;
}/*}}}*/

bool bic_cl_platform_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("ClPlatform");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class CL_DEVICE -
built_in_class_s cl_device_class =
{/*{{{*/
  "ClDevice",
  c_modifier_public | c_modifier_final,
  4, cl_device_methods,
  6 + 93, cl_device_variables,
  bic_cl_device_consts,
  bic_cl_device_init,
  bic_cl_device_clear,
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

built_in_method_s cl_device_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_cl_device_operator_binary_equal
  },
  {
    "dummy#0",
    c_modifier_public | c_modifier_final,
    bic_cl_device_method_dummy_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cl_device_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cl_device_method_print_0
  },
};/*}}}*/

built_in_variable_s cl_device_variables[] =
{/*{{{*/

  // - cl defvice type values -
  { "TYPE_CPU", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_GPU", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_ACCELERATOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_CUSTOM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_DEFAULT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_ALL", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - cl device info values -
  { "ADDRESS_BITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AVAILABLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "BUILT_IN_KERNELS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "COMPILER_AVAILABLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "DOUBLE_FP_CONFIG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ENDIAN_LITTLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ERROR_CORRECTION_SUPPORT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EXECUTION_CAPABILITIES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EXTENSIONS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLOBAL_MEM_CACHE_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLOBAL_MEM_CACHE_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLOBAL_MEM_CACHELINE_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLOBAL_MEM_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GLOBAL_VARIABLE_PREFERRED_TOTAL_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IL_VERSION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IMAGE2D_MAX_HEIGHT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IMAGE2D_MAX_WIDTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IMAGE3D_MAX_DEPTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IMAGE3D_MAX_HEIGHT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IMAGE3D_MAX_WIDTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IMAGE_BASE_ADDRESS_ALIGNMENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IMAGE_MAX_ARRAY_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IMAGE_MAX_BUFFER_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IMAGE_PITCH_ALIGNMENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IMAGE_SUPPORT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "LINKER_AVAILABLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "LOCAL_MEM_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "LOCAL_MEM_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAX_CLOCK_FREQUENCY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAX_COMPUTE_UNITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAX_CONSTANT_ARGS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAX_CONSTANT_BUFFER_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAX_GLOBAL_VARIABLE_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAX_MEM_ALLOC_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAX_NUM_SUB_GROUPS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAX_ON_DEVICE_EVENTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAX_ON_DEVICE_QUEUES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAX_PARAMETER_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAX_PIPE_ARGS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAX_READ_IMAGE_ARGS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAX_READ_WRITE_IMAGE_ARGS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAX_SAMPLERS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAX_WORK_GROUP_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAX_WORK_ITEM_DIMENSIONS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAX_WORK_ITEM_SIZES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAX_WRITE_IMAGE_ARGS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MEM_BASE_ADDR_ALIGN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NAME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NATIVE_VECTOR_WIDTH_CHAR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NATIVE_VECTOR_WIDTH_SHORT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NATIVE_VECTOR_WIDTH_INT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NATIVE_VECTOR_WIDTH_LONG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NATIVE_VECTOR_WIDTH_FLOAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NATIVE_VECTOR_WIDTH_DOUBLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NATIVE_VECTOR_WIDTH_HALF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPENCL_C_VERSION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PARENT_DEVICE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PARTITION_AFFINITY_DOMAIN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PARTITION_MAX_SUB_DEVICES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PARTITION_PROPERTIES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PARTITION_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PIPE_MAX_ACTIVE_RESERVATIONS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PIPE_MAX_PACKET_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PLATFORM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PREFERRED_GLOBAL_ATOMIC_ALIGNMENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PREFERRED_INTEROP_USER_SYNC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PREFERRED_LOCAL_ATOMIC_ALIGNMENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PREFERRED_PLATFORM_ATOMIC_ALIGNMENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PREFERRED_VECTOR_WIDTH_CHAR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PREFERRED_VECTOR_WIDTH_SHORT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PREFERRED_VECTOR_WIDTH_INT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PREFERRED_VECTOR_WIDTH_LONG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PREFERRED_VECTOR_WIDTH_FLOAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PREFERRED_VECTOR_WIDTH_DOUBLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PREFERRED_VECTOR_WIDTH_HALF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PRINTF_BUFFER_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROFILE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PROFILING_TIMER_RESOLUTION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "QUEUE_ON_DEVICE_MAX_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "QUEUE_ON_DEVICE_PREFERRED_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "QUEUE_ON_DEVICE_PROPERTIES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "QUEUE_ON_HOST_PROPERTIES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "REFERENCE_COUNT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SINGLE_FP_CONFIG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SPIR_VERSIONS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SUB_GROUP_INDEPENDENT_FORWARD_PROGRESS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SVM_CAPABILITIES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TERMINATE_CAPABILITY_KHR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VENDOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VENDOR_ID", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "DEVICE_VERSION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "DRIVER_VERSION", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_cl_device_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert cl device type values -
  {
    const_locations.push_blanks(6);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 6);

#define CREATE_CL_DEVICE_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_CL_DEVICE_TYPE_BIC_STATIC(CL_DEVICE_TYPE_CPU);
    CREATE_CL_DEVICE_TYPE_BIC_STATIC(CL_DEVICE_TYPE_GPU);
    CREATE_CL_DEVICE_TYPE_BIC_STATIC(CL_DEVICE_TYPE_ACCELERATOR);
    CREATE_CL_DEVICE_TYPE_BIC_STATIC(CL_DEVICE_TYPE_CUSTOM);
    CREATE_CL_DEVICE_TYPE_BIC_STATIC(CL_DEVICE_TYPE_DEFAULT);
    CREATE_CL_DEVICE_TYPE_BIC_STATIC(CL_DEVICE_TYPE_ALL);
  }

  // - insert cl device info values -
  {
    const_locations.push_blanks(93);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 93);

#define CREATE_CL_DEVICE_INFO_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_ADDRESS_BITS);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_AVAILABLE);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_BUILT_IN_KERNELS);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_COMPILER_AVAILABLE);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_DOUBLE_FP_CONFIG);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_ENDIAN_LITTLE);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_ERROR_CORRECTION_SUPPORT);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_EXECUTION_CAPABILITIES);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_EXTENSIONS);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_GLOBAL_MEM_CACHE_SIZE);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_GLOBAL_MEM_CACHE_TYPE);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_GLOBAL_MEM_SIZE);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_GLOBAL_VARIABLE_PREFERRED_TOTAL_SIZE);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_IL_VERSION);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_IMAGE2D_MAX_HEIGHT);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_IMAGE2D_MAX_WIDTH);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_IMAGE3D_MAX_DEPTH);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_IMAGE3D_MAX_HEIGHT);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_IMAGE3D_MAX_WIDTH);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_IMAGE_BASE_ADDRESS_ALIGNMENT);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_IMAGE_MAX_ARRAY_SIZE);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_IMAGE_MAX_BUFFER_SIZE);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_IMAGE_PITCH_ALIGNMENT);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_IMAGE_SUPPORT);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_LINKER_AVAILABLE);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_LOCAL_MEM_SIZE);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_LOCAL_MEM_TYPE);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_MAX_CLOCK_FREQUENCY);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_MAX_COMPUTE_UNITS);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_MAX_CONSTANT_ARGS);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_MAX_GLOBAL_VARIABLE_SIZE);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_MAX_MEM_ALLOC_SIZE);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_MAX_NUM_SUB_GROUPS);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_MAX_ON_DEVICE_EVENTS);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_MAX_ON_DEVICE_QUEUES);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_MAX_PARAMETER_SIZE);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_MAX_PIPE_ARGS);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_MAX_READ_IMAGE_ARGS);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_MAX_READ_WRITE_IMAGE_ARGS);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_MAX_SAMPLERS);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_MAX_WORK_GROUP_SIZE);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_MAX_WORK_ITEM_SIZES);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_MAX_WRITE_IMAGE_ARGS);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_MEM_BASE_ADDR_ALIGN);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_NAME);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_NATIVE_VECTOR_WIDTH_CHAR);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_NATIVE_VECTOR_WIDTH_SHORT);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_NATIVE_VECTOR_WIDTH_INT);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_NATIVE_VECTOR_WIDTH_LONG);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_NATIVE_VECTOR_WIDTH_FLOAT);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_NATIVE_VECTOR_WIDTH_DOUBLE);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_NATIVE_VECTOR_WIDTH_HALF);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_OPENCL_C_VERSION);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_PARENT_DEVICE);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_PARTITION_AFFINITY_DOMAIN);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_PARTITION_MAX_SUB_DEVICES);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_PARTITION_PROPERTIES);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_PARTITION_TYPE);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_PIPE_MAX_ACTIVE_RESERVATIONS);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_PIPE_MAX_PACKET_SIZE);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_PLATFORM);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_PREFERRED_GLOBAL_ATOMIC_ALIGNMENT);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_PREFERRED_INTEROP_USER_SYNC);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_PREFERRED_LOCAL_ATOMIC_ALIGNMENT);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_PREFERRED_PLATFORM_ATOMIC_ALIGNMENT);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_PREFERRED_VECTOR_WIDTH_HALF);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_PRINTF_BUFFER_SIZE);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_PROFILE);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_PROFILING_TIMER_RESOLUTION);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_QUEUE_ON_DEVICE_MAX_SIZE);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_QUEUE_ON_DEVICE_PREFERRED_SIZE);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_QUEUE_ON_DEVICE_PROPERTIES);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_QUEUE_ON_HOST_PROPERTIES);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_REFERENCE_COUNT);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_SINGLE_FP_CONFIG);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_SPIR_VERSIONS);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_SUB_GROUP_INDEPENDENT_FORWARD_PROGRESS);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_SVM_CAPABILITIES);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_TERMINATE_CAPABILITY_KHR);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_TYPE);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_VENDOR);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_VENDOR_ID);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_VERSION);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DRIVER_VERSION);
  }

}/*}}}*/

void bic_cl_device_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (cl_device_id)nullptr;
}/*}}}*/

void bic_cl_device_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

bool bic_cl_device_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_cl_device_method_dummy_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  long long int result = 0;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_cl_device_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("ClDevice"),"ClDevice");
  );

  return true;
}/*}}}*/

bool bic_cl_device_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("ClDevice");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

