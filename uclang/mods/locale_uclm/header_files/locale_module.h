
#ifndef __LOCALE_MODULE_H
#define __LOCALE_MODULE_H

@begin
include "ucl_locale.h"
@end

// - LOCALE indexes of built in classes -
extern unsigned c_bi_class_locale;

// - LOCALE module -
extern "C" IMPORT built_in_module_s module;

// - LOCALE classes -
extern built_in_class_s *locale_classes[];

// - LOCALE error identifiers -
enum
{
  c_error_LOCALE_BIND_MESSAGE_DOMAIN_ERROR = 0,
  c_error_LOCALE_MESSAGE_DOMAIN_ERROR,
  c_error_LOCALE_INVALID_LOCALE_CATEGORY,
  c_error_LOCALE_LOCALE_ERROR,
};

// - LOCALE error strings -
extern const char *locale_error_strings[];

// - LOCALE initialize -
bool locale_initialize(script_parser_s &sp);

// - LOCALE print exception -
bool locale_print_exception(interpreter_s &it,exception_s &exception);

// - class LOCALE -
extern built_in_variable_s locale_variables[];
extern built_in_method_s locale_methods[];
extern built_in_class_s locale_class;

void bic_locale_consts(location_array_s &const_locations);
void bic_locale_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_locale_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_locale_method_bind_domain_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_locale_method_bind_domain_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_locale_method_domain_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_locale_method_domain_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_locale_method_locale_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_locale_method_locale_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_locale_method_gettext_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_locale_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_locale_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

