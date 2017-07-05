
#ifndef __SNAPPY_MODULE_H
#define __SNAPPY_MODULE_H

@begin
include "ucl_snappy.h"
@end

// - SNAPPY indexes of built in classes -
extern unsigned c_bi_class_snappy;

// - SNAPPY module -
extern built_in_module_s module;

// - SNAPPY classes -
extern built_in_class_s *snappy_classes[];

// - SNAPPY error identifiers -
enum
{
  c_error_SNAPPY_GET_UNCOMPRESSED_LENGTH = 0,
  c_error_SNAPPY_UNCOMPRESS_ERROR,
};

// - SNAPPY error strings -
extern const char *snappy_error_strings[];

// - SNAPPY initialize -
bool snappy_initialize(script_parser_s &sp);

// - SNAPPY print exception -
bool snappy_print_exception(interpreter_s &it,exception_s &exception);

// - class SNAPPY -
extern built_in_variable_s snappy_variables[];
extern built_in_method_s snappy_methods[];
extern built_in_class_s snappy_class;

void bic_snappy_consts(location_array_s &const_locations);
void bic_snappy_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_snappy_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_snappy_method_compress_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_snappy_method_uncompress_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_snappy_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_snappy_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

