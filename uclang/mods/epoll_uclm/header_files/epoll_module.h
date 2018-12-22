
#ifndef __EPOLL_MODULE_H
#define __EPOLL_MODULE_H

@begin
include "ucl_epoll.h"
@end

// - EPOLL indexes of built in classes -
extern unsigned c_bi_class_epoll;

// - EPOLL module -
extern "C" IMPORT built_in_module_s module;

// - EPOLL classes -
extern built_in_class_s *epoll_classes[];

// - EPOLL error identifiers -
enum
{
  c_error_EPOLL_CREATE_ERROR = 0,
  c_error_EPOLL_WRONG_FDS_AND_EVENTS_ARRAY_SIZE,
  c_error_EPOLL_WRONG_FD_OR_EVENTS_VALUE_TYPE,
  c_error_EPOLL_CONTROL_ADD_ERROR,
  c_error_EPOLL_CONTROL_MODIFY_ERROR,
  c_error_EPOLL_CONTROL_DELETE_ERROR,
  c_error_EPOLL_WAIT_INVALID_MAX_EVENT_COUNT,
  c_error_EPOLL_WAIT_ERROR,
};

// - EPOLL error strings -
extern const char *epoll_error_strings[];

// - EPOLL initialize -
bool epoll_initialize(script_parser_s &sp);

// - EPOLL print exception -
bool epoll_print_exception(interpreter_s &it,exception_s &exception);

// - class EPOLL -
extern built_in_variable_s epoll_variables[];
extern built_in_method_s epoll_methods[];
extern built_in_class_s epoll_class;

void bic_epoll_consts(location_array_s &const_locations);
void bic_epoll_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_epoll_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_epoll_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_epoll_method_Epoll_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_epoll_method_update_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_epoll_method_wait_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_epoll_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_epoll_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

