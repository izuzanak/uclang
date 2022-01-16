
#ifndef __XXHASH_MODULE_H
#define __XXHASH_MODULE_H

@begin
include "ucl_xxhash.h"
@end

// - XXHASH indexes of built in classes -
extern unsigned c_bi_class_xxhash64;

// - XXHASH module -
extern "C" EXPORT built_in_module_s module;

// - XXHASH classes -
extern built_in_class_s *xxhash_classes[];

// - XXHASH error identifiers -
enum
{
  c_error_XXHASH_CREATE_RESET_ERROR = 0,
  c_error_XXHASH_UPDATE_ERROR,
};

// - XXHASH error strings -
extern const char *xxhash_error_strings[];

// - XXHASH initialize -
bool xxhash_initialize(script_parser_s &sp);

// - XXHASH print exception -
bool xxhash_print_exception(interpreter_s &it,exception_s &exception);

// - class XXHash64 -
extern built_in_variable_s xxhash64_variables[];
extern built_in_method_s xxhash64_methods[];
extern built_in_class_s xxhash64_class;

void bic_xxhash64_consts(location_array_s &const_locations);
void bic_xxhash64_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_xxhash64_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_xxhash64_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xxhash64_method_XXHash64_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xxhash64_method_hash_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xxhash64_method_update_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xxhash64_method_digest_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xxhash64_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xxhash64_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

