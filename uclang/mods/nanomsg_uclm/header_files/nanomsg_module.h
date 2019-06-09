
#ifndef __NANOMSG_MODULE_H
#define __NANOMSG_MODULE_H

@begin
include "ucl_nanomsg.h"
@end

// - NANOMSG indexes of built in classes -
extern unsigned c_bi_class_nano_msg;
extern unsigned c_bi_class_nano_socket;
extern unsigned c_bi_class_nano_endpoint;

// - NANOMSG module -
extern "C" EXPORT built_in_module_s module;

// - NANOMSG classes -
extern built_in_class_s *nanomsg_classes[];

// - NANOMSG error identifiers -
enum
{
  c_error_NANOMSG_DUMMY_ERROR = 0,
};

// - NANOMSG error strings -
extern const char *nanomsg_error_strings[];

// - NANOMSG initialize -
bool nanomsg_initialize(script_parser_s &sp);

// - NANOMSG print exception -
bool nanomsg_print_exception(interpreter_s &it,exception_s &exception);

// - class NANO_MSG -
extern built_in_variable_s nano_msg_variables[];
extern built_in_method_s nano_msg_methods[];
extern built_in_class_s nano_msg_class;

void bic_nano_msg_consts(location_array_s &const_locations);
void bic_nano_msg_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_nano_msg_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_nano_msg_method_term_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_nano_msg_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_nano_msg_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class NANO_SOCKET -
extern built_in_variable_s nano_socket_variables[];
extern built_in_method_s nano_socket_methods[];
extern built_in_class_s nano_socket_class;

void bic_nano_socket_consts(location_array_s &const_locations);
void bic_nano_socket_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_nano_socket_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_nano_socket_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_nano_socket_method_NanoSocket_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_nano_socket_method_bind_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_nano_socket_method_connect_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_nano_socket_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_nano_socket_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class NANO_ENDPOINT -
extern built_in_variable_s nano_endpoint_variables[];
extern built_in_method_s nano_endpoint_methods[];
extern built_in_class_s nano_endpoint_class;

void bic_nano_endpoint_consts(location_array_s &const_locations);
void bic_nano_endpoint_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_nano_endpoint_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_nano_endpoint_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_nano_endpoint_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_nano_endpoint_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

