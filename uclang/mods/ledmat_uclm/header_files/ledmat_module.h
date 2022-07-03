
#ifndef __LEDMAT_MODULE_H
#define __LEDMAT_MODULE_H

@begin
include "ucl_ledmat.h"
@end

// - LEDMAT indexes of built in classes -
extern unsigned c_bi_class_ledmat;
extern unsigned c_bi_class_ledmat_buffer;

// - LEDMAT module -
extern "C" EXPORT built_in_module_s module;

// - LEDMAT classes -
extern built_in_class_s *ledmat_classes[];

// - LEDMAT error identifiers -
enum
{
  c_error_LEDMAT_INVALID_ARGUMENTS = 0,
  c_error_LEDMAT_INVALID_BUFFER_SIZE,
  c_error_LEDMAT_MEMORY_ERROR,
  c_error_LEDMAT_SETUP_ERROR,
  c_error_LEDMAT_INVALID_BRIGHTNESS_VALUE,
  c_error_LEDMAT_BUFFER_INVALID_SIZE,
  c_error_LEDMAT_BUFFER_MEMORY_ERROR,
  c_error_LEDMAT_BUFFER_INVALID_BYTE_VALUE,
  c_error_LEDMAT_BUFFER_INVALID_DATA_SIZE,
  c_error_LEDMAT_BUFFER_INVALID_BUFFER_SIZE,
  c_error_LEDMAT_BUFFER_INVALID_SHIFT_VALUE,
};

// - LEDMAT error strings -
extern const char *ledmat_error_strings[];

// - LEDMAT initialize -
bool ledmat_initialize(script_parser_s &sp);

// - LEDMAT print exception -
bool ledmat_print_exception(interpreter_s &it,exception_s &exception);

// - class LEDMAT -
extern built_in_variable_s ledmat_variables[];
extern built_in_method_s ledmat_methods[];
extern built_in_class_s ledmat_class;

void bic_ledmat_consts(location_array_s &const_locations);
void bic_ledmat_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_ledmat_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_ledmat_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ledmat_method_LedMat_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ledmat_method_buffer_load_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ledmat_method_buffer_swap_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ledmat_method_brightness_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ledmat_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ledmat_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class LEDMAT_BUFFER -
extern built_in_variable_s ledmat_buffer_variables[];
extern built_in_method_s ledmat_buffer_methods[];
extern built_in_class_s ledmat_buffer_class;

void bic_ledmat_buffer_consts(location_array_s &const_locations);
void bic_ledmat_buffer_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_ledmat_buffer_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_ledmat_buffer_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ledmat_buffer_method_LedMatBuffer_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ledmat_buffer_method_fill_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ledmat_buffer_method_set_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ledmat_buffer_method_rotate_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ledmat_buffer_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ledmat_buffer_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

