
#ifndef __PAM_MODULE_H
#define __PAM_MODULE_H

@begin
include "ucl_pam.h"
@end

// - PAM indexes of built in classes -
extern unsigned c_bi_class_pam;

// - PAM module -
extern "C" EXPORT built_in_module_s module;

// - PAM classes -
extern built_in_class_s *pam_classes[];

// - PAM error identifiers -
enum
{
  c_error_PAM_DUMMY_ERROR = 0,
};

// - PAM error strings -
extern const char *pam_error_strings[];

// - PAM initialize -
bool pam_initialize(script_parser_s &sp);

// - PAM print exception -
bool pam_print_exception(interpreter_s &it,exception_s &exception);

// - class PAM -
extern built_in_variable_s pam_variables[];
extern built_in_method_s pam_methods[];
extern built_in_class_s pam_class;

void bic_pam_consts(location_array_s &const_locations);
void bic_pam_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_pam_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_pam_method_authenticate_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pam_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_pam_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

