
#ifndef __NODE_MODULE_H
#define __NODE_MODULE_H

@begin
include "ucl_node.h"
@end

// - NODE indexes of built in classes -
extern unsigned c_bi_class_node_callback;

// - NODE module -
extern built_in_module_s module;

// - NODE classes -
extern built_in_class_s *node_classes[];

// - NODE error identifiers -
enum
{
  c_error_NODE_CALLBACK_MAX_PARAM_COUNT_EXCEEDED = 0,
  c_error_NODE_CALLBACK_WRONG_PARAM_COUNT,
};

// - NODE error strings -
extern const char *node_error_strings[];

// - NODE initialize -
bool node_initialize(script_parser_s &sp);

// - NODE print exception -
bool node_print_exception(interpreter_s &it,exception_s &exception);

// - class NODE_CALLBACK -
extern built_in_variable_s node_callback_variables[];
extern built_in_method_s node_callback_methods[];
extern built_in_class_s node_callback_class;

void bic_node_callback_consts(location_array_s &const_locations);
void bic_node_callback_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_node_callback_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_node_callback_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_node_callback_method_NodeCallback_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_node_callback_method_call_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_node_callback_method_call_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_node_callback_method_call_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_node_callback_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_node_callback_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

