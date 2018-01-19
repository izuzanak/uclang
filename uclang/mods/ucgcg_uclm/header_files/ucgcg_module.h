
#ifndef __UCGCG_MODULE_H
#define __UCGCG_MODULE_H

@begin
include "ucl_ucgcg.h"
@end

// - UCGCG indexes of built in classes -
extern unsigned c_bi_class_gcg_msg;

// - UCGCG module -
extern built_in_module_s module;

// - UCGCG classes -
extern built_in_class_s *ucgcg_classes[];

// - UCGCG error identifiers -
enum
{
  c_error_GCG_INVALID_MESSAGE_HEAD = 0,
  c_error_GCG_INVALID_MESSAGE_TAIL,
  c_error_GCG_INVALID_MESSAGE_CRC_CHECKSUM,
};

// - UCGCG error strings -
extern const char *ucgcg_error_strings[];

// - UCGCG initialize -
bool ucgcg_initialize(script_parser_s &sp);

// - UCGCG print exception -
bool ucgcg_print_exception(interpreter_s &it,exception_s &exception);

// - class GCG_MSG -
extern built_in_variable_s gcg_msg_variables[];
extern built_in_method_s gcg_msg_methods[];
extern built_in_class_s gcg_msg_class;

void bic_gcg_msg_consts(location_array_s &const_locations);
void bic_gcg_msg_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_gcg_msg_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_gcg_msg_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gcg_msg_method_GcgMsg_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gcg_msg_method_GcgMsg_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gcg_msg_method_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gcg_msg_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gcg_msg_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

