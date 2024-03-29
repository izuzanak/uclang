
@begin
include "cl_module.h"
@end

// - CL indexes of built in classes -
unsigned c_bi_class_cl = c_idx_not_exist;
unsigned c_bi_class_cl_platform = c_idx_not_exist;
unsigned c_bi_class_cl_device = c_idx_not_exist;
unsigned c_bi_class_cl_context = c_idx_not_exist;
unsigned c_bi_class_cl_command_queue = c_idx_not_exist;
unsigned c_bi_class_cl_program = c_idx_not_exist;
unsigned c_bi_class_cl_kernel = c_idx_not_exist;
unsigned c_bi_class_cl_mem = c_idx_not_exist;
unsigned c_bi_class_cl_memmap = c_idx_not_exist;

// - CL module -
EXPORT built_in_module_s module =
{/*{{{*/
  9,                   // Class count
  cl_classes,          // Classes

  0,                   // Error base index
  25,                  // Error count
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
  &cl_context_class,
  &cl_command_queue_class,
  &cl_program_class,
  &cl_kernel_class,
  &cl_mem_class,
  &cl_memmap_class,
};/*}}}*/

// - CL error strings -
const char *cl_error_strings[] =
{/*{{{*/
  "error_CL_GET_PLATFORMS_ERROR",
  "error_CL_PLATFORM_INFO_ERROR",
  "error_CL_PLATFORM_GET_DEVICES_ERROR",
  "error_CL_DEVICE_INFO_ERROR",
  "error_CL_DEVICE_INFO_LARGE_VALUE_ERROR",
  "error_CL_INVALID_DEVICE_LIST",
  "error_CL_CONTEXT_CREATE_ERROR",
  "error_CL_CONTEXT_CREATE_COMMAND_QUEUE_ERROR",
  "error_CL_CONTEXT_CREATE_PROGRAM_ERROR",
  "error_CL_CONTEXT_INVLAID_BUFFER_SIZE",
  "error_CL_CONTEXT_INVLAID_BUFFER_HOST_DATA_SIZE",
  "error_CL_CONTEXT_CREATE_BUFFER_ERROR",
  "error_CL_COMMAND_QUEUE_ENQUEUE_KERNEL_DIMENSION_SIZE_MISMATCH",
  "error_CL_COMMAND_QUEUE_ENQUEUE_KERNEL_INVALID_WORK_SIZE_VALUE",
  "error_CL_COMMAND_QUEUE_ENQUEUE_KERNEL_ERROR",
  "error_CL_COMMAND_QUEUE_FINISH_ERROR",
  "error_CL_PROGRAM_BUILD_ERROR",
  "error_CL_PROGRAM_BUILD_ERROR_WITH_LOG",
  "error_CL_PROGRAM_CREATE_KERNEL_ERROR",
  "error_CL_KERNEL_INFO_ERROR",
  "error_CL_KERNEL_INVALID_ARGUMENT_INDEX",
  "error_CL_KERNEL_SET_ARGUMENT_ERROR",
  "error_CL_KERNEL_INVALID_ARGUMENT_TYPE",
  "error_CL_MEM_MISMATCH_MAP_COMMAND_QUEUE_CONTEXT",
  "error_CL_MEM_INVALID_MAP_OFFSET_OR_SIZE",
  "error_CL_MEM_MAP_BUFFER_ERROR",
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

  // - initialize cl_context class identifier -
  c_bi_class_cl_context = class_base_idx++;

  // - initialize cl_command_queue class identifier -
  c_bi_class_cl_command_queue = class_base_idx++;

  // - initialize cl_program class identifier -
  c_bi_class_cl_program = class_base_idx++;

  // - initialize cl_kernel class identifier -
  c_bi_class_cl_kernel = class_base_idx++;

  // - initialize cl_mem class identifier -
  c_bi_class_cl_mem = class_base_idx++;

  // - initialize cl_memmap class identifier -
  c_bi_class_cl_memmap = class_base_idx++;

  return true;
}/*}}}*/

// - CL print exception -
bool cl_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_CL_GET_PLATFORMS_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nOpenCL get platform identifiers error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CL_PLATFORM_INFO_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nOpenCL platform, get info error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CL_PLATFORM_GET_DEVICES_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nOpenCL platform, get device identifiers error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CL_DEVICE_INFO_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nOpenCL device, get info error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CL_DEVICE_INFO_LARGE_VALUE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nOpenCL device, get info value is too large\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CL_INVALID_DEVICE_LIST:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid list of OpenCL devices\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CL_CONTEXT_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nOpenCL context create error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CL_CONTEXT_CREATE_COMMAND_QUEUE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nOpenCL context, create command queue error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CL_CONTEXT_CREATE_PROGRAM_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nOpenCL context, create program error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CL_CONTEXT_INVLAID_BUFFER_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nOpenCL context, invalid buffer size\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CL_CONTEXT_INVLAID_BUFFER_HOST_DATA_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nOpenCL context, invalid buffer host data size\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CL_CONTEXT_CREATE_BUFFER_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nOpenCL context, create buffer error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CL_COMMAND_QUEUE_ENQUEUE_KERNEL_DIMENSION_SIZE_MISMATCH:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nOpenCL command queue, enqueue kernel dimension mismatch\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CL_COMMAND_QUEUE_ENQUEUE_KERNEL_INVALID_WORK_SIZE_VALUE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nOpenCL command queue, invalid global work size value\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CL_COMMAND_QUEUE_ENQUEUE_KERNEL_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nOpenCL command queue, enqueue kernel error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CL_COMMAND_QUEUE_FINISH_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nOpenCL command queue, finish error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CL_PROGRAM_BUILD_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nOpenCL program, build error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CL_PROGRAM_BUILD_ERROR_WITH_LOG:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nOpenCL program, build error:\n");
    fprintf(stderr,"%s",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CL_PROGRAM_CREATE_KERNEL_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nOpenCL program, create kernel error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CL_KERNEL_INFO_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nOpenCL kernel, get info error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CL_KERNEL_INVALID_ARGUMENT_INDEX:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nOpenCL kernel, invalid argument index\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CL_KERNEL_SET_ARGUMENT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nOpenCL kernel, set argument error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CL_KERNEL_INVALID_ARGUMENT_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nOpenCL kernel, invalid argument type\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CL_MEM_MISMATCH_MAP_COMMAND_QUEUE_CONTEXT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nOpenCL mem, mismatch map command queue context\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CL_MEM_INVALID_MAP_OFFSET_OR_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nOpenCL mem, invalid map offset or size values\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CL_MEM_MAP_BUFFER_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nOpenCL mem, map buffer error\n");
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
    exception_s::throw_exception(it,module.error_base + c_error_CL_GET_PLATFORMS_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  cl_platform_id platforms[num_platforms];

  // - ERROR -
  if (clGetPlatformIDs(num_platforms,platforms,nullptr) != CL_SUCCESS)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CL_GET_PLATFORMS_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
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
          exception_s::throw_exception(it,module.error_base + c_error_CL_PLATFORM_INFO_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
          return false;
        }

        string_s *string_ptr = it.get_new_string_ptr();

        // - not empty string -
        if (param_value_size > 1)
        {
          string_ptr->create(param_value_size - 1);

          // - ERROR -
          if (clGetPlatformInfo(platform_id,name,string_ptr->size,string_ptr->data,nullptr) != CL_SUCCESS)
          {
            string_ptr->clear();
            cfree(string_ptr);

            exception_s::throw_exception(it,module.error_base + c_error_CL_PLATFORM_INFO_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
            return false;
          }
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
          exception_s::throw_exception(it,module.error_base + c_error_CL_PLATFORM_INFO_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
          return false;
        }

        long long int result = value;

        BIC_SIMPLE_SET_RES(c_bi_class_integer,result);
      }/*}}}*/
      break;

    // - ERROR -
    default:

      exception_s::throw_exception(it,module.error_base + c_error_CL_PLATFORM_INFO_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
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
method get_devices
; @end

  cl_platform_id platform_id = (cl_platform_id)dst_location->v_data_ptr;

  cl_uint num_devices = 0;

  // - ERROR -
  if (clGetDeviceIDs(platform_id,device_type,0,nullptr,&num_devices) != CL_SUCCESS)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CL_PLATFORM_GET_DEVICES_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  cl_device_id devices[num_devices];

  // - ERROR -
  if (clGetDeviceIDs(platform_id,device_type,num_devices,devices,nullptr) != CL_SUCCESS)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CL_PLATFORM_GET_DEVICES_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
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
  6 + 91, cl_device_variables,
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
    "info#1",
    c_modifier_public | c_modifier_final,
    bic_cl_device_method_info_1
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

  // - cl device type values -
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
  { "SUB_GROUP_INDEPENDENT_FORWARD_PROGRESS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SVM_CAPABILITIES", c_modifier_public | c_modifier_static | c_modifier_static_const },
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
    const_locations.push_blanks(91);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 91);

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
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_SUB_GROUP_INDEPENDENT_FORWARD_PROGRESS);
    CREATE_CL_DEVICE_INFO_BIC_STATIC(CL_DEVICE_SVM_CAPABILITIES);
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

bool bic_cl_device_method_info_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
name:retrieve_integer
>
method info
; @end

  cl_device_id device_id = (cl_device_id)dst_location->v_data_ptr;

  size_t param_value_size;

  // - ERROR -
  if (clGetDeviceInfo(device_id,name,0,nullptr,&param_value_size) != CL_SUCCESS)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CL_DEVICE_INFO_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  switch (name)
  {
    case CL_DEVICE_BUILT_IN_KERNELS:
    case CL_DEVICE_EXTENSIONS:
    case CL_DEVICE_IL_VERSION:
    case CL_DEVICE_NAME:
    case CL_DEVICE_OPENCL_C_VERSION:
    case CL_DEVICE_PROFILE:
    case CL_DEVICE_VENDOR:
    case CL_DEVICE_VERSION:
    case CL_DRIVER_VERSION:
      {/*{{{*/
        string_s *string_ptr = it.get_new_string_ptr();

        // - not empty string -
        if (param_value_size > 1)
        {
          string_ptr->create(param_value_size - 1);

          // - ERROR -
          if (clGetDeviceInfo(device_id,name,string_ptr->size,string_ptr->data,nullptr) != CL_SUCCESS)
          {
            string_ptr->clear();
            cfree(string_ptr);

            exception_s::throw_exception(it,module.error_base + c_error_CL_DEVICE_INFO_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
            return false;
          }
        }

        BIC_SET_RESULT_STRING(string_ptr);
      }/*}}}*/
      break;
    default:
      {/*{{{*/
        char param_data[param_value_size];

        // - ERROR -
        if (clGetDeviceInfo(device_id,name,param_value_size,param_data,nullptr) != CL_SUCCESS)
        {
          exception_s::throw_exception(it,module.error_base + c_error_CL_DEVICE_INFO_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
          return false;
        }

        switch (name)
        {
          case CL_DEVICE_GLOBAL_VARIABLE_PREFERRED_TOTAL_SIZE:
          case CL_DEVICE_IMAGE2D_MAX_HEIGHT:
          case CL_DEVICE_IMAGE2D_MAX_WIDTH:
          case CL_DEVICE_IMAGE3D_MAX_DEPTH:
          case CL_DEVICE_IMAGE3D_MAX_HEIGHT:
          case CL_DEVICE_IMAGE3D_MAX_WIDTH:
          case CL_DEVICE_IMAGE_MAX_ARRAY_SIZE:
          case CL_DEVICE_IMAGE_MAX_BUFFER_SIZE:
          case CL_DEVICE_MAX_GLOBAL_VARIABLE_SIZE:
          case CL_DEVICE_MAX_PARAMETER_SIZE:
          case CL_DEVICE_MAX_WORK_GROUP_SIZE:
          case CL_DEVICE_PRINTF_BUFFER_SIZE:
          case CL_DEVICE_PROFILING_TIMER_RESOLUTION:
            {/*{{{*/
              size_t value;
              memcpy(&value,param_data,sizeof(size_t));

              // -ERROR  -
              if (value > LLONG_MAX)
              {
                exception_s::throw_exception(it,module.error_base + c_error_CL_DEVICE_INFO_LARGE_VALUE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
                return false;
              }

              long long int result = value;

              BIC_SIMPLE_SET_RES(c_bi_class_integer,result);
            }/*}}}*/
            break;
          case CL_DEVICE_ADDRESS_BITS:
          case CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE:
          case CL_DEVICE_IMAGE_BASE_ADDRESS_ALIGNMENT:
          case CL_DEVICE_IMAGE_PITCH_ALIGNMENT:
          case CL_DEVICE_MAX_CLOCK_FREQUENCY:
          case CL_DEVICE_MAX_COMPUTE_UNITS:
          case CL_DEVICE_MAX_CONSTANT_ARGS:
          case CL_DEVICE_MAX_NUM_SUB_GROUPS:
          case CL_DEVICE_MAX_ON_DEVICE_EVENTS:
          case CL_DEVICE_MAX_ON_DEVICE_QUEUES:
          case CL_DEVICE_MAX_PIPE_ARGS:
          case CL_DEVICE_MAX_READ_IMAGE_ARGS:
          case CL_DEVICE_MAX_READ_WRITE_IMAGE_ARGS:
          case CL_DEVICE_MAX_SAMPLERS:
          case CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS:
          case CL_DEVICE_MAX_WRITE_IMAGE_ARGS:
          case CL_DEVICE_MEM_BASE_ADDR_ALIGN:
          case CL_DEVICE_NATIVE_VECTOR_WIDTH_CHAR:
          case CL_DEVICE_NATIVE_VECTOR_WIDTH_SHORT:
          case CL_DEVICE_NATIVE_VECTOR_WIDTH_INT:
          case CL_DEVICE_NATIVE_VECTOR_WIDTH_LONG:
          case CL_DEVICE_NATIVE_VECTOR_WIDTH_FLOAT:
          case CL_DEVICE_NATIVE_VECTOR_WIDTH_DOUBLE:
          case CL_DEVICE_NATIVE_VECTOR_WIDTH_HALF:
          case CL_DEVICE_PARTITION_MAX_SUB_DEVICES:
          case CL_DEVICE_PIPE_MAX_ACTIVE_RESERVATIONS:
          case CL_DEVICE_PIPE_MAX_PACKET_SIZE:
          case CL_DEVICE_PREFERRED_GLOBAL_ATOMIC_ALIGNMENT:
          case CL_DEVICE_PREFERRED_LOCAL_ATOMIC_ALIGNMENT:
          case CL_DEVICE_PREFERRED_PLATFORM_ATOMIC_ALIGNMENT:
          case CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR:
          case CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT:
          case CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT:
          case CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG:
          case CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT:
          case CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE:
          case CL_DEVICE_PREFERRED_VECTOR_WIDTH_HALF:
          case CL_DEVICE_QUEUE_ON_DEVICE_MAX_SIZE:
          case CL_DEVICE_QUEUE_ON_DEVICE_PREFERRED_SIZE:
          case CL_DEVICE_REFERENCE_COUNT:
          case CL_DEVICE_VENDOR_ID:
            {/*{{{*/
              cl_uint value;
              memcpy(&value,param_data,sizeof(cl_uint));

              long long int result = value;

              BIC_SIMPLE_SET_RES(c_bi_class_integer,result);
            }/*}}}*/
            break;
          case CL_DEVICE_GLOBAL_MEM_CACHE_SIZE:
          case CL_DEVICE_GLOBAL_MEM_SIZE:
          case CL_DEVICE_LOCAL_MEM_SIZE:
          case CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE:
          case CL_DEVICE_MAX_MEM_ALLOC_SIZE:
            {/*{{{*/
              cl_ulong value;
              memcpy(&value,param_data,sizeof(cl_ulong));

              // -ERROR  -
              if (value > LLONG_MAX)
              {
                exception_s::throw_exception(it,module.error_base + c_error_CL_DEVICE_INFO_LARGE_VALUE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
                return false;
              }

              long long int result = value;

              BIC_SIMPLE_SET_RES(c_bi_class_integer,result);
            }/*}}}*/
            break;
          case CL_DEVICE_AVAILABLE:
          case CL_DEVICE_COMPILER_AVAILABLE:
          case CL_DEVICE_ENDIAN_LITTLE:
          case CL_DEVICE_ERROR_CORRECTION_SUPPORT:
          case CL_DEVICE_IMAGE_SUPPORT:
          case CL_DEVICE_LINKER_AVAILABLE:
          case CL_DEVICE_PREFERRED_INTEROP_USER_SYNC:
          case CL_DEVICE_SUB_GROUP_INDEPENDENT_FORWARD_PROGRESS:
            {/*{{{*/
              cl_bool value;
              memcpy(&value,param_data,sizeof(cl_bool));

              long long int result = value;

              BIC_SIMPLE_SET_RES(c_bi_class_integer,result);
            }/*}}}*/
            break;
          case CL_DEVICE_DOUBLE_FP_CONFIG:
          case CL_DEVICE_EXECUTION_CAPABILITIES:
          case CL_DEVICE_PARTITION_AFFINITY_DOMAIN:
          case CL_DEVICE_SINGLE_FP_CONFIG:
          case CL_DEVICE_SVM_CAPABILITIES:
          case CL_DEVICE_TYPE:
          case CL_DEVICE_QUEUE_ON_DEVICE_PROPERTIES:
          case CL_DEVICE_QUEUE_ON_HOST_PROPERTIES:
            {/*{{{*/
              cl_bitfield value;
              memcpy(&value,param_data,sizeof(cl_bitfield));

              long long int result = value;

              BIC_SIMPLE_SET_RES(c_bi_class_integer,result);
            }/*}}}*/
            break;
          case CL_DEVICE_GLOBAL_MEM_CACHE_TYPE:
          case CL_DEVICE_LOCAL_MEM_TYPE:
            {/*{{{*/
              cl_uint value;
              memcpy(&value,param_data,sizeof(cl_uint));

              long long int result = value;

              BIC_SIMPLE_SET_RES(c_bi_class_integer,result);
            }/*}}}*/
            break;
          case CL_DEVICE_PARENT_DEVICE:
            {/*{{{*/
              cl_device_id device_id;
              memcpy(&device_id,param_data,sizeof(cl_device_id));

              if (device_id != nullptr)
              {
                BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_cl_device,device_id);
                BIC_SET_RESULT(new_location);
              }
              else
              {
                BIC_SET_RESULT_BLANK();
              }
            }/*}}}*/
            break;
          case CL_DEVICE_PLATFORM:
            {/*{{{*/
              cl_platform_id platform_id;
              memcpy(&platform_id,param_data,sizeof(cl_platform_id));

              if (platform_id != nullptr)
              {
                BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_cl_platform,platform_id);
                BIC_SET_RESULT(new_location);
              }
              else
              {
                BIC_SET_RESULT_BLANK();
              }
            }/*}}}*/
            break;
          case CL_DEVICE_MAX_WORK_ITEM_SIZES:
            {/*{{{*/

              // - create new array pointer -
              pointer_array_s *array_ptr = it.get_new_array_ptr();
              BIC_CREATE_NEW_LOCATION(array_location,c_bi_class_array,array_ptr);

              if (param_value_size > 0)
              {
                char *p_ptr = param_data;
                char *p_ptr_end = p_ptr + param_value_size;
                do {
                  size_t value;
                  memcpy(&value,p_ptr,sizeof(size_t));

                  // - ERROR -
                  if (value > LLONG_MAX)
                  {
                    it.release_location_ptr(array_location);

                    exception_s::throw_exception(it,module.error_base + c_error_CL_DEVICE_INFO_LARGE_VALUE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
                    return false;
                  }

                  long long int result = value;

                  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,result);
                  array_ptr->push(new_location);

                } while((p_ptr += sizeof(size_t)) < p_ptr_end);
              }

              BIC_SET_RESULT(array_location);
            }/*}}}*/
            break;
          case CL_DEVICE_PARTITION_PROPERTIES:
          case CL_DEVICE_PARTITION_TYPE:
            {/*{{{*/

              // - create new array pointer -
              pointer_array_s *array_ptr = it.get_new_array_ptr();
              BIC_CREATE_NEW_LOCATION(array_location,c_bi_class_array,array_ptr);

              if (param_value_size > 0)
              {
                char *p_ptr = param_data;
                char *p_ptr_end = p_ptr + param_value_size;
                do {
                  intptr_t value;
                  memcpy(&value,p_ptr,sizeof(intptr_t));

                  long long int result = value;

                  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,result);
                  array_ptr->push(new_location);

                } while((p_ptr += sizeof(intptr_t)) < p_ptr_end);
              }

              BIC_SET_RESULT(array_location);
            }/*}}}*/
            break;

          // - ERROR -
          default:

            exception_s::throw_exception(it,module.error_base + c_error_CL_DEVICE_INFO_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
            return false;
        }
      }/*}}}*/
  }

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

// - class CL_CONTEXT -
built_in_class_s cl_context_class =
{/*{{{*/
  "ClContext",
  c_modifier_public | c_modifier_final,
  7, cl_context_methods,
  0, cl_context_variables,
  bic_cl_context_consts,
  bic_cl_context_init,
  bic_cl_context_clear,
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

built_in_method_s cl_context_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_cl_context_operator_binary_equal
  },
  {
    "ClContext#1",
    c_modifier_public | c_modifier_final,
    bic_cl_context_method_ClContext_1
  },
  {
    "command_queue#1",
    c_modifier_public | c_modifier_final,
    bic_cl_context_method_command_queue_1
  },
  {
    "program#1",
    c_modifier_public | c_modifier_final,
    bic_cl_context_method_program_1
  },
  {
    "buffer#3",
    c_modifier_public | c_modifier_final,
    bic_cl_context_method_buffer_3
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cl_context_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cl_context_method_print_0
  },
};/*}}}*/

built_in_variable_s cl_context_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_cl_context_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_cl_context_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (cl_context)nullptr;
}/*}}}*/

void bic_cl_context_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cl_context ctx = (cl_context)location_ptr->v_data_ptr;

  if (ctx != nullptr)
  {
    clReleaseContext(ctx);
  }
}/*}}}*/

bool bic_cl_context_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_cl_context_method_ClContext_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
devices:c_bi_class_array
>
method ClContext
; @end

  pointer_array_s *array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (array_ptr->used <= 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CL_INVALID_DEVICE_LIST,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  cl_device_id devices[array_ptr->used];

  pointer *p_ptr = array_ptr->data;
  pointer *p_ptr_end = p_ptr + array_ptr->used;
  cl_device_id *d_ptr = devices;
  do {
    location_s *item_loc = it.get_location_value(*p_ptr);

    // - ERROR -
    if (item_loc->v_type != c_bi_class_cl_device)
    {
      exception_s::throw_exception(it,module.error_base + c_error_CL_INVALID_DEVICE_LIST,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    *d_ptr = (cl_device_id)item_loc->v_data_ptr;
  } while(++d_ptr,++p_ptr < p_ptr_end);

  // - ERROR -
  cl_context ctx = clCreateContext(nullptr,array_ptr->used,devices,nullptr,nullptr,nullptr);
  if (ctx == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CL_CONTEXT_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  dst_location->v_data_ptr = (cl_context)ctx;

  return true;
}/*}}}*/

bool bic_cl_context_method_command_queue_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
device:c_bi_class_cl_device
>
method command_queue
; @end

  cl_context ctx = (cl_context)dst_location->v_data_ptr;
  cl_device_id device_id = (cl_device_id)src_0_location->v_data_ptr;

  // - ERROR -
  cl_command_queue cqueue = clCreateCommandQueueWithProperties(ctx,device_id,nullptr,nullptr);
  if (cqueue == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CL_CONTEXT_CREATE_COMMAND_QUEUE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_cl_command_queue,cqueue);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_cl_context_method_program_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
code:c_bi_class_string
>
method program
; @end

  cl_context ctx = (cl_context)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  const char *string = string_ptr->data;
  size_t length = string_ptr->size - 1;

  // - ERROR -
  cl_program program = clCreateProgramWithSource(ctx,1,&string,&length,nullptr);
  if (program == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CL_CONTEXT_CREATE_PROGRAM_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_cl_program,program);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_cl_context_method_buffer_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
flags:retrieve_integer
size:retrieve_integer
data:retrieve_data_buffer
data:c_bi_class_blank
>
method buffer
; @end

  cl_context ctx = (cl_context)dst_location->v_data_ptr;

  if (src_2_location->v_type == c_bi_class_blank)
  {
    data_ptr = nullptr;
    data_size = 0;
  }

  // - ERROR -
  if (size <= 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CL_CONTEXT_INVLAID_BUFFER_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (data_size != 0 && data_size < size)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CL_CONTEXT_INVLAID_BUFFER_HOST_DATA_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  cl_mem mem = clCreateBuffer(ctx,flags,size,(void *)data_ptr,nullptr);
  if (mem == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CL_CONTEXT_CREATE_BUFFER_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_cl_mem,mem);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_cl_context_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("ClContext"),"ClContext");
  );

  return true;
}/*}}}*/

bool bic_cl_context_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("ClContext");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class CL_COMMAND_QUEUE -
built_in_class_s cl_command_queue_class =
{/*{{{*/
  "ClCommandQueue",
  c_modifier_public | c_modifier_final,
  5, cl_command_queue_methods,
  0, cl_command_queue_variables,
  bic_cl_command_queue_consts,
  bic_cl_command_queue_init,
  bic_cl_command_queue_clear,
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

built_in_method_s cl_command_queue_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_cl_command_queue_operator_binary_equal
  },
  {
    "enqueue_nd_range_kernel#3",
    c_modifier_public | c_modifier_final,
    bic_cl_command_queue_method_enqueue_nd_range_kernel_3
  },
  {
    "finish#0",
    c_modifier_public | c_modifier_final,
    bic_cl_command_queue_method_finish_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cl_command_queue_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cl_command_queue_method_print_0
  },
};/*}}}*/

built_in_variable_s cl_command_queue_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_cl_command_queue_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_cl_command_queue_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (cl_command_queue)nullptr;
}/*}}}*/

void bic_cl_command_queue_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cl_command_queue cqueue = (cl_command_queue)location_ptr->v_data_ptr;

  if (cqueue != nullptr)
  {
    clReleaseCommandQueue(cqueue);
  }
}/*}}}*/

bool bic_cl_command_queue_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_cl_command_queue_method_enqueue_nd_range_kernel_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
kernel:c_bi_class_cl_kernel
work_dim:retrieve_integer
global_work_size:c_bi_class_array
>
method enqueue_nd_range_kernel
; @end

  cl_command_queue cqueue = (cl_command_queue)dst_location->v_data_ptr;
  cl_kernel kernel = (cl_kernel)src_0_location->v_data_ptr;
  pointer_array_s *gws_array_ptr = (pointer_array_s *)src_2_location->v_data_ptr;

  // - ERROR -
  if (work_dim <= 0 || gws_array_ptr->used != work_dim)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CL_COMMAND_QUEUE_ENQUEUE_KERNEL_DIMENSION_SIZE_MISMATCH,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  size_t global_work_size[work_dim];

  pointer *gws_ptr = gws_array_ptr->data;
  pointer *gws_ptr_end = gws_ptr + gws_array_ptr->used;
  size_t *gwsv_ptr = global_work_size;
  do {
    location_s *item_loc = it.get_location_value(*gws_ptr);

    // - ERROR -
    long long int value;
    if (!it.retrieve_integer(item_loc,value) || value <= 0)
    {
      exception_s::throw_exception(it,module.error_base + c_error_CL_COMMAND_QUEUE_ENQUEUE_KERNEL_INVALID_WORK_SIZE_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    // - set global work size value -
    *gwsv_ptr++ = value;

  } while(++gws_ptr < gws_ptr_end);

  // - ERROR -
  if (clEnqueueNDRangeKernel(cqueue,kernel,work_dim,
        nullptr,global_work_size,nullptr,0,nullptr,nullptr) != CL_SUCCESS)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CL_COMMAND_QUEUE_ENQUEUE_KERNEL_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_cl_command_queue_method_finish_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  cl_command_queue cqueue = (cl_command_queue)dst_location->v_data_ptr;

  // - ERROR -
  if (clFinish(cqueue) != CL_SUCCESS)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CL_COMMAND_QUEUE_FINISH_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_cl_command_queue_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("ClCommandQueue"),"ClCommandQueue");
  );

  return true;
}/*}}}*/

bool bic_cl_command_queue_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("ClCommandQueue");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class CL_PROGRAM -
built_in_class_s cl_program_class =
{/*{{{*/
  "ClProgram",
  c_modifier_public | c_modifier_final,
  5, cl_program_methods,
  0, cl_program_variables,
  bic_cl_program_consts,
  bic_cl_program_init,
  bic_cl_program_clear,
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

built_in_method_s cl_program_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_cl_program_operator_binary_equal
  },
  {
    "build#1",
    c_modifier_public | c_modifier_final,
    bic_cl_program_method_build_1
  },
  {
    "kernel#1",
    c_modifier_public | c_modifier_final,
    bic_cl_program_method_kernel_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cl_program_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cl_program_method_print_0
  },
};/*}}}*/

built_in_variable_s cl_program_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_cl_program_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_cl_program_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (cl_program)nullptr;
}/*}}}*/

void bic_cl_program_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cl_program program = (cl_program)location_ptr->v_data_ptr;

  if (program != nullptr)
  {
    clReleaseProgram(program);
  }
}/*}}}*/

bool bic_cl_program_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_cl_program_method_build_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
devices:c_bi_class_array
>
method build
; @end

  cl_program program = (cl_program)dst_location->v_data_ptr;
  pointer_array_s *array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (array_ptr->used <= 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CL_INVALID_DEVICE_LIST,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  cl_device_id devices[array_ptr->used];

  pointer *p_ptr = array_ptr->data;
  pointer *p_ptr_end = p_ptr + array_ptr->used;
  cl_device_id *d_ptr = devices;
  do {
    location_s *item_loc = it.get_location_value(*p_ptr);

    // - ERROR -
    if (item_loc->v_type != c_bi_class_cl_device)
    {
      exception_s::throw_exception(it,module.error_base + c_error_CL_INVALID_DEVICE_LIST,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    *d_ptr = (cl_device_id)item_loc->v_data_ptr;
  } while(++d_ptr,++p_ptr < p_ptr_end);


  // - ERROR -
  if (clBuildProgram(program,array_ptr->used,devices,nullptr,nullptr,nullptr) != CL_SUCCESS)
  {
    // - ERROR -
    size_t build_log_size;
    if (clGetProgramBuildInfo(program,devices[0],CL_PROGRAM_BUILD_LOG,0,nullptr,&build_log_size) != CL_SUCCESS)
    {
      exception_s::throw_exception(it,module.error_base + c_error_CL_PROGRAM_BUILD_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    string_s *string_ptr = it.get_new_string_ptr();

    // - not empty build log -
    if (build_log_size > 1)
    {
      string_ptr->create(build_log_size - 1);

      // - ERROR -
      if (clGetProgramBuildInfo(program,devices[0],CL_PROGRAM_BUILD_LOG,string_ptr->size,string_ptr->data,nullptr) != CL_SUCCESS)
      {
        string_ptr->clear();
        cfree(string_ptr);

        exception_s::throw_exception(it,module.error_base + c_error_CL_PROGRAM_BUILD_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }
    }

    BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_string,string_ptr,0);

    exception_s::throw_exception(it,module.error_base + c_error_CL_PROGRAM_BUILD_ERROR_WITH_LOG,operands[c_source_pos_idx],new_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_cl_program_method_kernel_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
name:c_bi_class_string
>
method kernel
; @end

  cl_program program = (cl_program)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  cl_kernel kernel = clCreateKernel(program,string_ptr->data,nullptr);
  if (kernel == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CL_PROGRAM_CREATE_KERNEL_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_cl_kernel,kernel);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_cl_program_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("ClProgram"),"ClProgram");
  );

  return true;
}/*}}}*/

bool bic_cl_program_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("ClProgram");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class CL_KERNEL -
built_in_class_s cl_kernel_class =
{/*{{{*/
  "ClKernel",
  c_modifier_public | c_modifier_final,
  8, cl_kernel_methods,
  0, cl_kernel_variables,
  bic_cl_kernel_consts,
  bic_cl_kernel_init,
  bic_cl_kernel_clear,
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

built_in_method_s cl_kernel_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_cl_kernel_operator_binary_equal
  },
  {
    "function_name#0",
    c_modifier_public | c_modifier_final,
    bic_cl_kernel_method_function_name_0
  },
  {
    "arg_count#0",
    c_modifier_public | c_modifier_final,
    bic_cl_kernel_method_arg_count_0
  },
  {
    "reference_count#0",
    c_modifier_public | c_modifier_final,
    bic_cl_kernel_method_reference_count_0
  },
  {
    "attributes#0",
    c_modifier_public | c_modifier_final,
    bic_cl_kernel_method_attributes_0
  },
  {
    "set_arg#2",
    c_modifier_public | c_modifier_final,
    bic_cl_kernel_method_set_arg_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cl_kernel_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cl_kernel_method_print_0
  },
};/*}}}*/

built_in_variable_s cl_kernel_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

#define CL_KERNEL_GET_INFO_STRING(PARAM_NAME) \
{/*{{{*/\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  cl_kernel kernel = (cl_kernel)dst_location->v_data_ptr;\
\
  size_t param_value_size;\
\
  /* - ERROR - */\
  if (clGetKernelInfo(kernel,PARAM_NAME,\
        0,nullptr,&param_value_size) != CL_SUCCESS)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_CL_KERNEL_INFO_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  string_s *string_ptr = it.get_new_string_ptr();\
\
  /* - not empty string - */\
  if (param_value_size > 1)\
  {\
    string_ptr->create(param_value_size - 1);\
\
    /* - ERROR - */\
    if (clGetKernelInfo(kernel,PARAM_NAME,\
          string_ptr->size,string_ptr->data,nullptr) != CL_SUCCESS)\
    {\
      string_ptr->clear();\
      cfree(string_ptr);\
\
      exception_s::throw_exception(it,module.error_base + c_error_CL_KERNEL_INFO_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      return false;\
    }\
  }\
\
  BIC_SET_RESULT_STRING(string_ptr);\
\
  return true;\
}/*}}}*/

#define CL_KERNEL_GET_INFO_TYPE(PARAM_TYPE,PARAM_NAME,RESULT_CODE) \
{/*{{{*/\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  cl_kernel kernel = (cl_kernel)dst_location->v_data_ptr;\
\
  /* - ERROR - */\
  PARAM_TYPE value;\
  if (clGetKernelInfo(kernel,PARAM_NAME,sizeof(PARAM_TYPE),&value,nullptr) != CL_SUCCESS)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_CL_KERNEL_INFO_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  RESULT_CODE;\
\
  return true;\
}/*}}}*/

void bic_cl_kernel_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_cl_kernel_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (cl_kernel)nullptr;
}/*}}}*/

void bic_cl_kernel_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cl_kernel kernel = (cl_kernel)location_ptr->v_data_ptr;

  if (kernel != nullptr)
  {
    clReleaseKernel(kernel);
  }
}/*}}}*/

bool bic_cl_kernel_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_cl_kernel_method_function_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  CL_KERNEL_GET_INFO_STRING(CL_KERNEL_FUNCTION_NAME);
}/*}}}*/

bool bic_cl_kernel_method_arg_count_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  CL_KERNEL_GET_INFO_TYPE(cl_uint,CL_KERNEL_NUM_ARGS,
    long long int result = value;

    BIC_SIMPLE_SET_RES(c_bi_class_integer,result);
  );
}/*}}}*/

bool bic_cl_kernel_method_reference_count_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  CL_KERNEL_GET_INFO_TYPE(cl_uint,CL_KERNEL_REFERENCE_COUNT,
    long long int result = value;

    BIC_SIMPLE_SET_RES(c_bi_class_integer,result);
  );
}/*}}}*/

bool bic_cl_kernel_method_attributes_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  CL_KERNEL_GET_INFO_STRING(CL_KERNEL_ATTRIBUTES);
}/*}}}*/

bool bic_cl_kernel_method_set_arg_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
index:retrieve_integer
value:ignore
>
method set_arg
; @end

  cl_kernel kernel = (cl_kernel)dst_location->v_data_ptr;

  // - ERROR -
  cl_uint num_args;
  if (clGetKernelInfo(kernel,CL_KERNEL_NUM_ARGS,sizeof(cl_uint),&num_args,nullptr) != CL_SUCCESS)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CL_KERNEL_INFO_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (index >= num_args)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CL_KERNEL_INVALID_ARGUMENT_INDEX,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  if (src_1_location->v_type == c_bi_class_cl_mem)
  {
    cl_mem mem = (cl_mem)src_1_location->v_data_ptr;

    // - ERROR -
    if (clSetKernelArg(kernel,index,sizeof(mem),&mem) != CL_SUCCESS)
    {
      exception_s::throw_exception(it,module.error_base + c_error_CL_KERNEL_SET_ARGUMENT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }
  }

  // - ERROR -
  else
  {
    exception_s::throw_exception(it,module.error_base + c_error_CL_KERNEL_INVALID_ARGUMENT_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_cl_kernel_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("ClKernel"),"ClKernel");
  );

  return true;
}/*}}}*/

bool bic_cl_kernel_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("ClKernel");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class CL_MEM -
built_in_class_s cl_mem_class =
{/*{{{*/
  "ClMem",
  c_modifier_public | c_modifier_final,
  4, cl_mem_methods,
  9 + 3, cl_mem_variables,
  bic_cl_mem_consts,
  bic_cl_mem_init,
  bic_cl_mem_clear,
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

built_in_method_s cl_mem_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_cl_mem_operator_binary_equal
  },
  {
    "map#4",
    c_modifier_public | c_modifier_final,
    bic_cl_mem_method_map_4
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cl_mem_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cl_mem_method_print_0
  },
};/*}}}*/

built_in_variable_s cl_mem_variables[] =
{/*{{{*/

  // - cl mem flag values -
  { "READ_WRITE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "WRITE_ONLY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "READ_ONLY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "USE_HOST_PTR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ALLOC_HOST_PTR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "COPY_HOST_PTR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HOST_WRITE_ONLY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HOST_READ_ONLY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "HOST_NO_ACCESS", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - cl mem map values -
  { "MAP_READ", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAP_WRITE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAP_WRITE_INVALIDATE_REGION", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_cl_mem_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert cl mem flag values -
  {
    const_locations.push_blanks(9);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 9);

#define CREATE_CL_MEM_FLAG_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_CL_MEM_FLAG_BIC_STATIC(CL_MEM_READ_WRITE);
    CREATE_CL_MEM_FLAG_BIC_STATIC(CL_MEM_WRITE_ONLY);
    CREATE_CL_MEM_FLAG_BIC_STATIC(CL_MEM_READ_ONLY);
    CREATE_CL_MEM_FLAG_BIC_STATIC(CL_MEM_USE_HOST_PTR);
    CREATE_CL_MEM_FLAG_BIC_STATIC(CL_MEM_ALLOC_HOST_PTR);
    CREATE_CL_MEM_FLAG_BIC_STATIC(CL_MEM_COPY_HOST_PTR);
    CREATE_CL_MEM_FLAG_BIC_STATIC(CL_MEM_HOST_WRITE_ONLY);
    CREATE_CL_MEM_FLAG_BIC_STATIC(CL_MEM_HOST_READ_ONLY);
    CREATE_CL_MEM_FLAG_BIC_STATIC(CL_MEM_HOST_NO_ACCESS);
  }

  // - insert cl mem map values -
  {
    const_locations.push_blanks(3);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 3);

#define CREATE_CL_MEM_MAP_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_CL_MEM_MAP_BIC_STATIC(CL_MAP_READ);
    CREATE_CL_MEM_MAP_BIC_STATIC(CL_MAP_WRITE);
    CREATE_CL_MEM_MAP_BIC_STATIC(CL_MAP_WRITE_INVALIDATE_REGION);
  }

}/*}}}*/

void bic_cl_mem_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (cl_mem)nullptr;
}/*}}}*/

void bic_cl_mem_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cl_mem mem = (cl_mem)location_ptr->v_data_ptr;

  if (mem != nullptr)
  {
    clReleaseMemObject(mem);
  }
}/*}}}*/

bool bic_cl_mem_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_cl_mem_method_map_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
command_queue:c_bi_class_cl_command_queue
flags:retrieve_integer
offset:retrieve_integer
size:retrieve_integer
>
method map
; @end

  cl_mem mem = (cl_mem)dst_location->v_data_ptr;
  cl_command_queue cqueue = (cl_command_queue)src_0_location->v_data_ptr;

  // - ERROR -
  cl_context mem_ctx;
  cl_context cqueue_ctx;
  if (clGetMemObjectInfo(mem,CL_MEM_CONTEXT,sizeof(cl_context),&mem_ctx,nullptr) != CL_SUCCESS ||
      clGetCommandQueueInfo(cqueue,CL_QUEUE_CONTEXT,sizeof(cl_context),&cqueue_ctx,nullptr) != CL_SUCCESS ||
      mem_ctx != cqueue_ctx)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CL_MEM_MISMATCH_MAP_COMMAND_QUEUE_CONTEXT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  size_t mem_size;
  if (clGetMemObjectInfo(mem,CL_MEM_SIZE,sizeof(size_t),&mem_size,nullptr) != CL_SUCCESS ||
      offset < 0 || size < 0 ||
      size ?
        (((size_t)(offset + size)) > mem_size) :
        (size = mem_size - offset, (size_t)offset >= mem_size)
      )
  {
    exception_s::throw_exception(it,module.error_base + c_error_CL_MEM_INVALID_MAP_OFFSET_OR_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  void *data;
  if ((data = clEnqueueMapBuffer(cqueue,mem,CL_TRUE,flags,
          offset,size,0,nullptr,nullptr,nullptr)) == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CL_MEM_MAP_BUFFER_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create cl_memmap object -
  cl_memmap_s *mm_ptr = (cl_memmap_s *)cmalloc(sizeof(cl_memmap_s));
  mm_ptr->init();

  // - create mem reference -
  dst_location->v_reference_cnt.atomic_inc();
  mm_ptr->mem_loc = dst_location;

  // - create command queue reference -
  src_0_location->v_reference_cnt.atomic_inc();
  mm_ptr->cqueue_loc = src_0_location;

  mm_ptr->data = data;
  mm_ptr->size = size;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_cl_memmap,mm_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_cl_mem_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("ClMem"),"ClMem");
  );

  return true;
}/*}}}*/

bool bic_cl_mem_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("ClMem");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class CL_MEMMAP -
built_in_class_s cl_memmap_class =
{/*{{{*/
  "ClMemmap",
  c_modifier_public | c_modifier_final,
  4, cl_memmap_methods,
  0, cl_memmap_variables,
  bic_cl_memmap_consts,
  bic_cl_memmap_init,
  bic_cl_memmap_clear,
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

built_in_method_s cl_memmap_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_cl_memmap_operator_binary_equal
  },
  {
    "buffer#0",
    c_modifier_public | c_modifier_final,
    bic_cl_memmap_method_buffer_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cl_memmap_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cl_memmap_method_print_0
  },
};/*}}}*/

built_in_variable_s cl_memmap_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_cl_memmap_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_cl_memmap_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (cl_memmap_s *)nullptr;
}/*}}}*/

void bic_cl_memmap_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cl_memmap_s *mm_ptr = (cl_memmap_s *)location_ptr->v_data_ptr;

  // - if memap exists -
  if (mm_ptr != nullptr)
  {
    mm_ptr->clear(it);
    cfree(mm_ptr);
  }
}/*}}}*/

bool bic_cl_memmap_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_cl_memmap_method_buffer_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  cl_memmap_s *mm_ptr = (cl_memmap_s *)dst_location->v_data_ptr;

  // - create buffer object -
  buffer_s *buffer_ptr = (buffer_s *)cmalloc(sizeof(buffer_s));

  // - set owner reference -
  dst_location->v_reference_cnt.atomic_inc();
  buffer_ptr->owner_ptr = dst_location;

  buffer_ptr->data = mm_ptr->data;
  buffer_ptr->size = mm_ptr->size;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_buffer,buffer_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_cl_memmap_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("ClMemmap"),"ClMemmap");
  );

  return true;
}/*}}}*/

bool bic_cl_memmap_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("ClMemmap");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

