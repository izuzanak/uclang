
#ifndef __PROLOG_MODULE_H
#define __PROLOG_MODULE_H

@begin
include "ucl_prolog.h"
@end

// - PROLOG indexes of built in classes -
extern unsigned c_bi_class_prolog_context;
extern unsigned c_bi_class_prolog_atom;
extern unsigned c_bi_class_prolog_functor;

// - PROLOG module -
extern built_in_module_s module;

// - PROLOG classes -
extern built_in_class_s *prolog_classes[];

// - PROLOG error identifiers -
enum
{
  c_error_PROLOG_DUMMY_ERROR = 0,
};

// - PROLOG error strings -
extern const char *prolog_error_strings[];

// - PROLOG initialize -
bool prolog_initialize(script_parser_s &sp);

// - PROLOG print exception -
bool prolog_print_exception(interpreter_s &it,exception_s &exception);

// - class PROLOG_CONTEXT -
extern built_in_variable_s prolog_context_variables[];
extern built_in_method_s prolog_context_methods[];
extern built_in_class_s prolog_context_class;

void bic_prolog_context_consts(location_array_s &const_locations);
void bic_prolog_context_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_prolog_context_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_prolog_context_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_prolog_context_method_PrologContext_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_prolog_context_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_prolog_context_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class PROLOG_ATOM -
extern built_in_variable_s prolog_atom_variables[];
extern built_in_method_s prolog_atom_methods[];
extern built_in_class_s prolog_atom_class;

void bic_prolog_atom_consts(location_array_s &const_locations);
void bic_prolog_atom_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_prolog_atom_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_prolog_atom_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_prolog_atom_method_PrologAtom_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_prolog_atom_method_text_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_prolog_atom_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_prolog_atom_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class PROLOG_FUNCTOR -
extern built_in_variable_s prolog_functor_variables[];
extern built_in_method_s prolog_functor_methods[];
extern built_in_class_s prolog_functor_class;

void bic_prolog_functor_consts(location_array_s &const_locations);
void bic_prolog_functor_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_prolog_functor_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_prolog_functor_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_prolog_functor_method_PrologFunctor_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_prolog_functor_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_prolog_functor_method_arity_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_prolog_functor_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_prolog_functor_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

