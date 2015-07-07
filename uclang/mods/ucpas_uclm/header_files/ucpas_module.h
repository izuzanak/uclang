
#ifndef __UCPAS_MODULE_H
#define __UCPAS_MODULE_H

@begin
include "ucl_ucpas.h"
@end

// - UCPAS indexes of built in classes -
extern unsigned c_bi_class_pas;
extern unsigned c_bi_class_pas_device;

// - UCPAS module -
extern built_in_module_s module;

// - UCPAS classes -
extern built_in_class_s *ucpas_classes[];

// - UCPAS error identifiers -
enum
{
  c_error_PAS_LIB_ALREADY_INITIALIZED = 0,
  c_error_PAS_LIB_INITIALIZE_ERROR,
  c_error_PAS_LIB_WRONG_IP_ADDRESS_FORMAT,
  c_error_PAS_LIB_WRONG_SAMPLES_DATA_LENGTH,
  c_error_PAS_LIB_WRONG_VOLUME_VALUE,
  c_error_PAS_DEVICE_VERSION_STRING_TOO_LONG,
};

// - UCPAS error strings -
extern const char *ucpas_error_strings[];

// - UCPAS initialize -
bool ucpas_initialize(script_parser_s &sp);

// - UCPAS print exception -
bool ucpas_print_exception(interpreter_s &it,exception_s &exception);

// - class PAS -
extern built_in_variable_s pas_variables[];
extern built_in_method_s pas_methods[];
extern built_in_class_s pas_class;

void bic_pas_consts(location_array_s &const_locations);
void bic_pas_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_pas_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_pas_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pas_method_Pas_5(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pas_method_master_ip_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pas_method_master_ip_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pas_method_device_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pas_method_device_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pas_method_update_device_status_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pas_method_samples_append_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pas_method_samples_append_silence_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pas_method_samples_clear_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pas_method_samples_count_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pas_method_audio_section_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pas_method_audio_section_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pas_method_priority_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pas_method_priority_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pas_method_volume_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pas_method_volume_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pas_method_pause_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pas_method_version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pas_method_debug_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pas_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pas_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class PAS_DEVICE -
extern built_in_variable_s pas_device_variables[];
extern built_in_method_s pas_device_methods[];
extern built_in_class_s pas_device_class;

void bic_pas_device_consts(location_array_s &const_locations);
void bic_pas_device_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_pas_device_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_pas_device_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pas_device_method_PasDevice_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pas_device_method_uid_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pas_device_method_vid_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pas_device_method_status_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pas_device_method_version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pas_device_method_section_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pas_device_method_dev_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pas_device_method_uid_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pas_device_method_vid_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pas_device_method_status_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pas_device_method_version_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pas_device_method_section_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pas_device_method_dev_type_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pas_device_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pas_device_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

