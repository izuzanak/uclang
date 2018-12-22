
#ifndef __AO_MODULE_H
#define __AO_MODULE_H

@begin
include "ucl_ao.h"
@end

// - AO indexes of built in classes -
extern unsigned c_bi_class_ao_format;
extern unsigned c_bi_class_ao_device;

// - AO module -
extern "C" IMPORT built_in_module_s module;

// - AO classes -
extern built_in_class_s *ao_classes[];

// - AO error identifiers -
enum
{
  c_error_AO_DEVICE_UNKNOWN_DRIVER_NAME = 0,
  c_error_AO_DEVICE_OPTIONS_NOT_DIVISIBLE_BY_TWO,
  c_error_AO_DEVICE_OPTION_KEY_STRING_EXPECTED,
  c_error_AO_DEVICE_OPTION_VALUE_STRING_EXPECTED,
  c_error_AO_DEVICE_CANNOT_OPEN_DEVICE,
  c_error_AO_DEVICE_CANNOT_PLAY_AUDIO_DATA,
};

// - AO error strings -
extern const char *ao_error_strings[];

// - AO initialize -
bool ao_initialize(script_parser_s &sp);

// - AO print exception -
bool ao_print_exception(interpreter_s &it,exception_s &exception);

// - class AO_FORMAT -
extern built_in_variable_s ao_format_variables[];
extern built_in_method_s ao_format_methods[];
extern built_in_class_s ao_format_class;

void bic_ao_format_consts(location_array_s &const_locations);
void bic_ao_format_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_ao_format_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_ao_format_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ao_format_method_AoFormat_5(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ao_format_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ao_format_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class AO_DEVICE -
extern built_in_variable_s ao_device_variables[];
extern built_in_method_s ao_device_methods[];
extern built_in_class_s ao_device_class;

void bic_ao_device_consts(location_array_s &const_locations);
void bic_ao_device_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_ao_device_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_ao_device_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ao_device_method_AoDevice_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ao_device_method_AoDevice_5(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ao_device_method_driver_id_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ao_device_method_play_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ao_device_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ao_device_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

