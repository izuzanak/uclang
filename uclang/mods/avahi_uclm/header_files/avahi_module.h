
#ifndef __AVAHI_MODULE_H
#define __AVAHI_MODULE_H

@begin
include "ucl_avahi.h"
@end

// - AVAHI indexes of built in classes -
extern unsigned c_bi_class_avahi_poll;
extern unsigned c_bi_class_avahi_client;

// - AVAHI module -
extern "C" EXPORT built_in_module_s module;

// - AVAHI classes -
extern built_in_class_s *avahi_classes[];

// - AVAHI error identifiers -
enum
{
  c_error_AVAHI_DUMMY_ERROR = 0,
};

// - AVAHI error strings -
extern const char *avahi_error_strings[];

// - AVAHI initialize -
bool avahi_initialize(script_parser_s &sp);

// - AVAHI print exception -
bool avahi_print_exception(interpreter_s &it,exception_s &exception);

// - class AVAHI_POLL -
extern built_in_variable_s avahi_poll_variables[];
extern built_in_method_s avahi_poll_methods[];
extern built_in_class_s avahi_poll_class;

void bic_avahi_poll_consts(location_array_s &const_locations);
void bic_avahi_poll_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_avahi_poll_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_avahi_poll_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_avahi_poll_method_AvahiPoll_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_avahi_poll_method_get_fds_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_avahi_poll_method_timeout_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_avahi_poll_method_process_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_avahi_poll_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_avahi_poll_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class AVAHI_CLIENT -
extern built_in_variable_s avahi_client_variables[];
extern built_in_method_s avahi_client_methods[];
extern built_in_class_s avahi_client_class;

void bic_avahi_client_consts(location_array_s &const_locations);
void bic_avahi_client_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_avahi_client_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_avahi_client_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_avahi_client_method_AvahiClient_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_avahi_client_method_state_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_avahi_client_method_user_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_avahi_client_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_avahi_client_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

