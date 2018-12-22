
#ifndef __INOTIFY_MODULE_H
#define __INOTIFY_MODULE_H

@begin
include "ucl_inotify.h"
@end

// - INOTIFY indexes of built in classes -
extern unsigned c_bi_class_inotify;
extern unsigned c_bi_class_inotify_watch;
extern unsigned c_bi_class_inotify_event;

// - INOTIFY module -
extern "C" IMPORT built_in_module_s module;

// - INOTIFY classes -
extern built_in_class_s *inotify_classes[];

// - INOTIFY error identifiers -
enum
{
  c_error_INOTIFY_CREATE_ERROR = 0,
  c_error_INOTIFY_ADD_WATCH_ERROR,
  c_error_INOTIFY_READ_ERROR,
};

// - INOTIFY error strings -
extern const char *inotify_error_strings[];

// - INOTIFY initialize -
bool inotify_initialize(script_parser_s &sp);

// - INOTIFY print exception -
bool inotify_print_exception(interpreter_s &it,exception_s &exception);

// - class INOTIFY -
extern built_in_variable_s inotify_variables[];
extern built_in_method_s inotify_methods[];
extern built_in_class_s inotify_class;

void bic_inotify_consts(location_array_s &const_locations);
void bic_inotify_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_inotify_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_inotify_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_inotify_method_Inotify_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_inotify_method_add_watch_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_inotify_method_read_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_inotify_method_get_fd_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_inotify_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_inotify_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class INOTIFY_WATCH -
extern built_in_variable_s inotify_watch_variables[];
extern built_in_method_s inotify_watch_methods[];
extern built_in_class_s inotify_watch_class;

void bic_inotify_watch_consts(location_array_s &const_locations);
void bic_inotify_watch_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_inotify_watch_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_inotify_watch_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_inotify_watch_method_watch_id_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_inotify_watch_method_mask_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_inotify_watch_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_inotify_watch_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_inotify_watch_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class INOTIFY_EVENT -
extern built_in_variable_s inotify_event_variables[];
extern built_in_method_s inotify_event_methods[];
extern built_in_class_s inotify_event_class;

void bic_inotify_event_consts(location_array_s &const_locations);
void bic_inotify_event_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_inotify_event_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_inotify_event_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_inotify_event_method_watch_id_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_inotify_event_method_mask_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_inotify_event_method_cookie_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_inotify_event_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_inotify_event_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_inotify_event_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

