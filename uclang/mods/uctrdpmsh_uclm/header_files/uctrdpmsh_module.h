
#ifndef __UCTRDPMSH_MODULE_H
#define __UCTRDPMSH_MODULE_H

@begin
include "ucl_uctrdpmsh.h"
@end

// - UCTRDPMSH indexes of built in classes -
extern unsigned c_bi_class_trdp_page;

// - UCTRDPMSH module -
extern built_in_module_s module;

// - UCTRDPMSH classes -
extern built_in_class_s *uctrdpmsh_classes[];

// - UCTRDPMSH error strings -
extern const char *uctrdpmsh_error_strings[];

// - UCTRDPMSH initialize -
bool uctrdpmsh_initialize(script_parser_s &sp);

// - UCTRDPMSH print exception -
bool uctrdpmsh_print_exception(interpreter_s &it,exception_s &exception);

// - class TRDP_PAGE -
extern built_in_variable_s trdp_page_variables[];
extern built_in_method_s trdp_page_methods[];
extern built_in_class_s trdp_page_class;

void bic_trdp_page_consts(location_array_s &const_locations);
void bic_trdp_page_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_trdp_page_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_trdp_page_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_page_method_TrdpPage_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_page_method_size_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_page_method_pack_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_page_method_unpack_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_page_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_page_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

