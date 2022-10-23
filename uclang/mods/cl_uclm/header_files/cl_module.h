
#ifndef __CL_MODULE_H
#define __CL_MODULE_H

@begin
include "ucl_cl.h"
@end

// - CL indexes of built in classes -
extern unsigned c_bi_class_cl;
extern unsigned c_bi_class_cl_platform;
extern unsigned c_bi_class_cl_device;

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

bool bic_cl_method_get_platform_ids_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
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
bool bic_cl_platform_method_get_device_ids_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
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
bool bic_cl_device_method_dummy_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cl_device_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cl_device_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

