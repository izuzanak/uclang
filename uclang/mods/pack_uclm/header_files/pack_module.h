
#ifndef __PACK_MODULE_H
#define __PACK_MODULE_H

@begin
include "ucl_pack.h"
@end

// - PACK indexes of built in classes -
extern unsigned c_bi_class_pack;

// - PACK module -
extern built_in_module_s module;

// - PACK classes -
extern built_in_class_s *pack_classes[];

// - PACK error identifiers -
enum
{
  c_error_PACK_BUILT_IN_NOT_DEFINED_PACK = 0,
  c_error_PACK_BUILT_IN_NOT_DEFINED_UNPACK,
  c_error_PACK_ERROR_WHILE_PACKING_OBJECT,
  c_error_PACK_ERROR_WHILE_UNPACKING_VALUE_STREAM,
  c_error_PACK_ERROR_WHILE_UNPACKING_CLASS_STREAM,
  c_error_PACK_ERROR_WHILE_UNPACKING_OBJECT,
  c_error_PACK_CODE_NOT_ENOUGH_ARGUMENTS,
  c_error_PACK_CODE_WRONG_ARGUMENT_TYPE,
  c_error_PACK_CODE_WRONG_FORMAT_STRING,
  c_error_PACK_CODE_NOT_ALL_ARGUMENTS_CONVERTED,
  c_error_PACK_DECODE_NOT_ENOUGH_DATA_BYTES,
};

// - PACK error strings -
extern const char *pack_error_strings[];

// - PACK initialize -
bool pack_initialize(script_parser_s &sp);

// - PACK print exception -
bool pack_print_exception(interpreter_s &it,exception_s &exception);

// - class PACK -
extern built_in_variable_s pack_variables[];
extern built_in_method_s pack_methods[];
extern built_in_class_s pack_class;

void bic_pack_consts(location_array_s &const_locations);
void bic_pack_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_pack_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_pack_method_pack_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pack_method_unpack_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pack_method_code_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pack_method_decode_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pack_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pack_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

