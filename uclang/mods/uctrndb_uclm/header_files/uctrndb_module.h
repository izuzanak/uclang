
#ifndef __UCTRNDB_MODULE_H
#define __UCTRNDB_MODULE_H

@begin
include "ucl_uctrndb.h"
@end

// - UCTRNDB indexes of built in classes -
extern unsigned c_bi_class_trndb_client;

// - UCTRNDB module -
extern built_in_module_s module;

// - UCTRNDB classes -
extern built_in_class_s *uctrndb_classes[];

// - UCTRNDB error identifiers -
enum
{
  c_error_TRNDB_DUMMY_ERROR = 0,
};

// - UCTRNDB error strings -
extern const char *uctrndb_error_strings[];

// - UCTRNDB initialize -
bool uctrndb_initialize(script_parser_s &sp);

// - UCTRNDB print exception -
bool uctrndb_print_exception(interpreter_s &it,exception_s &exception);

// - class TRNDB_CLIENT -
extern built_in_variable_s trndb_client_variables[];
extern built_in_method_s trndb_client_methods[];
extern built_in_class_s trndb_client_class;

void bic_trndb_client_consts(location_array_s &const_locations);
void bic_trndb_client_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_trndb_client_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_trndb_client_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trndb_client_method_TrndbClient_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trndb_client_method_SetCallback_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trndb_client_method_Recall_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trndb_client_method_Relock_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trndb_client_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trndb_client_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

