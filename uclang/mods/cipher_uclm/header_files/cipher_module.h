
#ifndef __CIPHER_MODULE_H
#define __CIPHER_MODULE_H

@begin
include "script_parser.h"
@end

// - CIPHER indexes of built in classes -
extern unsigned c_bi_class_cipher_rc4;

// - CIPHER module -
extern built_in_module_s module;

// - CIPHER classes -
extern built_in_class_s *cipher_classes[];

// - CIPHER error identifiers -
//enum
//{
//};

// - CIPHER error strings -
extern const char *cipher_error_strings[];

// - CIPHER initialize -
bool cipher_initialize(script_parser_s &sp);

// - CIPHER print exception -
bool cipher_print_exception(interpreter_s &it,exception_s &exception);

// - class CIPHER_RC4 -
extern built_in_variable_s cipher_rc4_variables[];
extern built_in_method_s cipher_rc4_methods[];
extern built_in_class_s cipher_rc4_class;

void bic_cipher_rc4_consts(location_array_s &const_locations);
void bic_cipher_rc4_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_cipher_rc4_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_cipher_rc4_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cipher_rc4_method_CipherRc4_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cipher_rc4_method_process_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cipher_rc4_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cipher_rc4_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

