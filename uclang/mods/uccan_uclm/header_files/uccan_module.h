
#ifndef __UCCAN_MODULE_H
#define __UCCAN_MODULE_H

@begin
include "ucl_uccan.h"
@end

// - UCCAN indexes of built in classes -
extern unsigned c_bi_class_traffic_store;

// - UCCAN module -
extern built_in_module_s module;

// - UCCAN classes -
extern built_in_class_s *uccan_classes[];

// - UCCAN error identifiers -
enum
{
  c_error_CAN_DUMMY_ERROR = 0,
};

// - UCCAN error strings -
extern const char *uccan_error_strings[];

// - UCCAN initialize -
bool uccan_initialize(script_parser_s &sp);

// - UCCAN print exception -
bool uccan_print_exception(interpreter_s &it,exception_s &exception);

// - class TRAFFIC_STORE -
extern built_in_variable_s traffic_store_variables[];
extern built_in_method_s traffic_store_methods[];
extern built_in_class_s traffic_store_class;

void bic_traffic_store_consts(location_array_s &const_locations);
void bic_traffic_store_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_traffic_store_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_traffic_store_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_traffic_store_method_TrafficStore_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_traffic_store_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_traffic_store_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

