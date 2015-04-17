
#ifndef __COMELM_MODULE_H
#define __COMELM_MODULE_H

@begin
include "ucl_comelm.h"
@end

// - COMELM indexes of built in classes -
extern unsigned c_bi_class_elm_comm;
extern unsigned c_bi_class_elm_packet;

// - COMELM module -
extern built_in_module_s module;

// - COMELM classes -
extern built_in_class_s *comelm_classes[];

// - COMELM error identifiers -
enum
{
  c_error_ELM_COMM_INITIALIZATION_ERROR = 0,
  c_error_ELM_COMM_WRONG_MAX_TIME_DIFF_VALUE,
  c_error_ELM_COMM_TIME_SYNC_ERROR,
  c_error_ELM_COMM_WRONG_TIME_STRING,
  c_error_ELM_COMM_NEGATIVE_OFFSET_VALUE,
  c_error_ELM_COMM_NEGATIVE_COMM_SPEED_VALUE,
  c_error_ELM_COMM_COMMUNICATION_ERROR,
};

// - COMELM error strings -
extern const char *comelm_error_strings[];

// - COMELM initialize -
bool comelm_initialize(script_parser_s &sp);

// - COMELM print exception -
bool comelm_print_exception(interpreter_s &it,exception_s &exception);

// - class ELM_COMM -
extern built_in_variable_s elm_comm_variables[];
extern built_in_method_s elm_comm_methods[];
extern built_in_class_s elm_comm_class;

void bic_elm_comm_consts(location_array_s &const_locations);
void bic_elm_comm_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_elm_comm_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_elm_comm_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_elm_comm_method_ElmComm_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_elm_comm_method_check_sync_time_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_elm_comm_method_read_identification_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_elm_comm_method_read_actual_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_elm_comm_method_read_index_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_elm_comm_method_read_delta_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_elm_comm_method_write_init_speed_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_elm_comm_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_elm_comm_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class ELM_PACKET -
extern built_in_variable_s elm_packet_variables[];
extern built_in_method_s elm_packet_methods[];
extern built_in_class_s elm_packet_class;

void bic_elm_packet_consts(location_array_s &const_locations);
void bic_elm_packet_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_elm_packet_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_elm_packet_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_elm_packet_method_ElmPacket_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_elm_packet_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_elm_packet_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

