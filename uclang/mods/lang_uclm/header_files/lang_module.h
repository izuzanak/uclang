
#ifndef __LANG_MODULE_H
#define __LANG_MODULE_H

@begin
include "ucl_lang.h"
@end

// - LANG indexes of built in classes -
extern unsigned c_bi_class_lang;
extern unsigned c_bi_class_namespace_ref;
extern unsigned c_bi_class_class_ref;
extern unsigned c_bi_class_method_ref;
extern unsigned c_bi_class_var_ref;
extern unsigned c_bi_class_param_ref;

// - LANG module -
extern built_in_module_s module;

// - LANG classes -
extern built_in_class_s *lang_classes[];

// - LANG error identifiers -
enum
{
  c_error_LANG_CLASS_WAS_NOT_FOUND = 0,
  c_error_CLASS_REF_CLASS_WAS_NOT_FOUND,
  c_error_CLASS_REF_METHOD_WAS_NOT_FOUND,
  c_error_CLASS_REF_VARIABLE_WAS_NOT_FOUND,
  c_error_METHOD_REF_PARAMETER_WAS_NOT_FOUND,
};

// - LANG error strings -
extern const char *lang_error_strings[];

// - LANG initialize -
bool lang_initialize(script_parser_s &sp);

// - LANG print exception -
bool lang_print_exception(interpreter_s &it,exception_s &exception);

// - class LANG -
extern built_in_variable_s lang_variables[];
extern built_in_method_s lang_methods[];
extern built_in_class_s lang_class;

void bic_lang_consts(location_array_s &const_locations);
void bic_lang_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_lang_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_lang_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_lang_method_version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_lang_method_classes_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_lang_method_cls_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_lang_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_lang_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class NAMESPACE_REF -
extern built_in_variable_s namespace_ref_variables[];
extern built_in_method_s namespace_ref_methods[];
extern built_in_class_s namespace_ref_class;

void bic_namespace_ref_consts(location_array_s &const_locations);
void bic_namespace_ref_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_namespace_ref_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_namespace_ref_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_namespace_ref_method_global_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_namespace_ref_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_namespace_ref_method_namespaces_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_namespace_ref_method_classes_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_namespace_ref_method_nspace_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_namespace_ref_method_cls_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_namespace_ref_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_namespace_ref_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class CLASS_REF -
extern built_in_variable_s class_ref_variables[];
extern built_in_method_s class_ref_methods[];
extern built_in_class_s class_ref_class;

void bic_class_ref_consts(location_array_s &const_locations);
void bic_class_ref_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_class_ref_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_class_ref_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_class_ref_method_ClassRef_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_class_ref_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_class_ref_method_is_built_in_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_class_ref_method_parent_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_class_ref_method_classes_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_class_ref_method_methods_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_class_ref_method_vars_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_class_ref_method_cls_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_class_ref_method_method_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_class_ref_method_variable_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_class_ref_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_class_ref_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class METHOD_REF -
extern built_in_variable_s method_ref_variables[];
extern built_in_method_s method_ref_methods[];
extern built_in_class_s method_ref_class;

void bic_method_ref_consts(location_array_s &const_locations);
void bic_method_ref_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_method_ref_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_method_ref_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_method_ref_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_method_ref_method_is_static_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_method_ref_method_parent_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_method_ref_method_params_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_method_ref_method_param_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_method_ref_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_method_ref_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class VAR_REF -
extern built_in_variable_s var_ref_variables[];
extern built_in_method_s var_ref_methods[];
extern built_in_class_s var_ref_class;

void bic_var_ref_consts(location_array_s &const_locations);
void bic_var_ref_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_var_ref_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_var_ref_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_var_ref_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_var_ref_method_parent_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_var_ref_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_var_ref_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class PARAM_REF -
extern built_in_variable_s param_ref_variables[];
extern built_in_method_s param_ref_methods[];
extern built_in_class_s param_ref_class;

void bic_param_ref_consts(location_array_s &const_locations);
void bic_param_ref_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_param_ref_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_param_ref_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_param_ref_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_param_ref_method_parent_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_param_ref_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_param_ref_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

