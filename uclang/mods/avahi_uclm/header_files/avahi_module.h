
#ifndef __AVAHI_MODULE_H
#define __AVAHI_MODULE_H

@begin
include "ucl_avahi.h"
@end

// - AVAHI indexes of built in classes -
extern unsigned c_bi_class_avahi_poll;
extern unsigned c_bi_class_avahi_client;
extern unsigned c_bi_class_avahi_service_browser;

// - AVAHI module -
extern "C" EXPORT built_in_module_s module;

// - AVAHI classes -
extern built_in_class_s *avahi_classes[];

// - AVAHI error identifiers -
enum
{
  c_error_AVAHI_CLIENT_WRONG_CALLBACK_DELEGATE = 0,
  c_error_AVAHI_CLIENT_CREATE_ERROR,
  c_error_AVAHI_CLIENT_ACCESS_OUTSIDE_OF_CALLBACK,
  c_error_AVAHI_SERVICE_BROWSER_WRONG_CALLBACK_DELEGATE,
  c_error_AVAHI_SERVICE_BROWSER_CREATE_ERROR,
  c_error_AVAHI_SERVICE_BROWSER_ACCESS_OUTSIDE_OF_BROWSE_CALLBACK,
  c_error_AVAHI_SERVICE_BROWSER_ACCESS_OUTSIDE_OF_RESOLVE_CALLBACK,
  c_error_AVAHI_SERVICE_BROWSER_CREATE_RESOLVER_ERROR,
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
bool bic_avahi_poll_method_client_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
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
bool bic_avahi_client_method_state_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_avahi_client_method_user_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_avahi_client_method_service_browser_6(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_avahi_client_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_avahi_client_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class AVAHI_SERVICE_BROWSER -
extern built_in_variable_s avahi_service_browser_variables[];
extern built_in_method_s avahi_service_browser_methods[];
extern built_in_class_s avahi_service_browser_class;

void bic_avahi_service_browser_consts(location_array_s &const_locations);
void bic_avahi_service_browser_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_avahi_service_browser_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_avahi_service_browser_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_avahi_service_browser_method_event_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_avahi_service_browser_method_service_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_avahi_service_browser_method_txt_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_avahi_service_browser_method_resolve_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_avahi_service_browser_method_user_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_avahi_service_browser_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_avahi_service_browser_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

