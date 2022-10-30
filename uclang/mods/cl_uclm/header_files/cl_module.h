
#ifndef __CL_MODULE_H
#define __CL_MODULE_H

@begin
include "ucl_cl.h"
@end

// - CL indexes of built in classes -
extern unsigned c_bi_class_cl;
extern unsigned c_bi_class_cl_platform;
extern unsigned c_bi_class_cl_device;
extern unsigned c_bi_class_cl_context;
extern unsigned c_bi_class_cl_command_queue;
extern unsigned c_bi_class_cl_program;
extern unsigned c_bi_class_cl_kernel;
extern unsigned c_bi_class_cl_mem;

// - CL module -
extern "C" EXPORT built_in_module_s module;

// - CL classes -
extern built_in_class_s *cl_classes[];

// - CL error identifiers -
enum
{
  c_error_CL_DUMMY_ERROR = 0,
};

// - CL error strings -
extern const char *cl_error_strings[];

// - CL initialize -
bool cl_initialize(script_parser_s &sp);

// - CL print exception -
bool cl_print_exception(interpreter_s &it,exception_s &exception);

// - class CL -
extern built_in_variable_s cl_variables[];
extern built_in_method_s cl_methods[];
extern built_in_class_s cl_class;

void bic_cl_consts(location_array_s &const_locations);
void bic_cl_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_cl_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_cl_method_get_platforms_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cl_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cl_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class CL_PLATFORM -
extern built_in_variable_s cl_platform_variables[];
extern built_in_method_s cl_platform_methods[];
extern built_in_class_s cl_platform_class;

void bic_cl_platform_consts(location_array_s &const_locations);
void bic_cl_platform_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_cl_platform_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_cl_platform_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cl_platform_method_info_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cl_platform_method_get_devices_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cl_platform_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cl_platform_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class CL_DEVICE -
extern built_in_variable_s cl_device_variables[];
extern built_in_method_s cl_device_methods[];
extern built_in_class_s cl_device_class;

void bic_cl_device_consts(location_array_s &const_locations);
void bic_cl_device_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_cl_device_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_cl_device_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cl_device_method_info_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cl_device_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cl_device_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class CL_CONTEXT -
extern built_in_variable_s cl_context_variables[];
extern built_in_method_s cl_context_methods[];
extern built_in_class_s cl_context_class;

void bic_cl_context_consts(location_array_s &const_locations);
void bic_cl_context_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_cl_context_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_cl_context_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cl_context_method_ClContext_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cl_context_method_command_queue_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cl_context_method_program_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cl_context_method_buffer_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cl_context_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cl_context_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class CL_COMMAND_QUEUE -
extern built_in_variable_s cl_command_queue_variables[];
extern built_in_method_s cl_command_queue_methods[];
extern built_in_class_s cl_command_queue_class;

void bic_cl_command_queue_consts(location_array_s &const_locations);
void bic_cl_command_queue_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_cl_command_queue_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_cl_command_queue_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cl_command_queue_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cl_command_queue_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class CL_PROGRAM -
extern built_in_variable_s cl_program_variables[];
extern built_in_method_s cl_program_methods[];
extern built_in_class_s cl_program_class;

void bic_cl_program_consts(location_array_s &const_locations);
void bic_cl_program_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_cl_program_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_cl_program_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cl_program_method_build_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cl_program_method_kernel_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cl_program_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cl_program_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class CL_KERNEL -
extern built_in_variable_s cl_kernel_variables[];
extern built_in_method_s cl_kernel_methods[];
extern built_in_class_s cl_kernel_class;

void bic_cl_kernel_consts(location_array_s &const_locations);
void bic_cl_kernel_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_cl_kernel_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_cl_kernel_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cl_kernel_method_set_arg_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cl_kernel_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cl_kernel_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class CL_MEM -
extern built_in_variable_s cl_mem_variables[];
extern built_in_method_s cl_mem_methods[];
extern built_in_class_s cl_mem_class;

void bic_cl_mem_consts(location_array_s &const_locations);
void bic_cl_mem_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_cl_mem_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_cl_mem_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cl_mem_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cl_mem_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

