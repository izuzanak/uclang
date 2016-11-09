
#ifndef __JSON_MODULE_H
#define __JSON_MODULE_H

@begin
include "ucl_json.h"
@end


// - JSON indexes of built in classes -
extern unsigned c_bi_class_json;

// - JSON module -
extern built_in_module_s module;

// - JSON classes -
extern built_in_class_s *json_classes[];

// - JSON error identifiers -
enum
{
  c_error_JSON_CREATE_UNSUPPORTED_CLASS = 0,
  c_error_JSON_CREATE_NO_STRING_DICT_KEY,
  c_error_JSON_PARSE_ERROR,
};

// - JSON error strings -
extern const char *json_error_strings[];

// - JSON initialize -
bool json_initialize(script_parser_s &sp);

// - JSON print exception -
bool json_print_exception(interpreter_s &it,exception_s &exception);

// - class JSON -
extern built_in_variable_s json_variables[];
extern built_in_method_s json_methods[];
extern built_in_class_s json_class;

void bic_json_consts(location_array_s &const_locations);
void bic_json_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_json_clear(interpreter_thread_s &it,location_s *location_ptr);
bool bic_json_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack);
bool bic_json_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos);

bool bic_json_method_create_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_json_method_create_nice_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_json_method_parse_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_json_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_json_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

