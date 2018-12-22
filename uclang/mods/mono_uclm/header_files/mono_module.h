
#ifndef __MONO_MODULE_H
#define __MONO_MODULE_H

@begin
include "ucl_mono.h"
@end

// - MONO indexes of built in classes -
extern unsigned c_bi_class_mono_assembly;
extern unsigned c_bi_class_mono_class;
extern unsigned c_bi_class_mono_object;
extern unsigned c_bi_class_mono_property;
extern unsigned c_bi_class_mono_item_ref;

// - MONO module -
extern "C" IMPORT built_in_module_s module;

// - MONO classes -
extern built_in_class_s *mono_classes[];

// - MONO error identifiers -
enum
{
  c_error_MONO_RUNTIME_EXCEPTION = 0,
  c_error_MONO_ASSEMBLY_ALREADY_OPEN,
  c_error_MONO_ASSEMBLY_NO_COMMAND_LINE_ARGUMENTS,
  c_error_MONO_ASSEMBLY_NO_STRING_COMMAND_LINE_ARGUMET,
  c_error_MONO_ASSEMBLY_OPEN_ERROR,
  c_error_MONO_ASSEMBLY_EXEC_ERROR,
  c_error_MONO_ASSEMBLY_INVALID_UCLANG_CLASSES,
  c_error_MONO_ASSEMBLY_NOT_OPEN,
  c_error_MONO_ASSEMBLY_CLASS_NOT_FOUND,
  c_error_MONO_CLASS_CANNOT_FIND_CONSTRUCTOR,
  c_error_MONO_OBJECT_INVOKE_METHOD_UNKNOWN_NAME,
  c_error_MONO_OBJECT_INVOKE_METHOD_WRONG_PARAMETER,
  c_error_MONO_OBJECT_MEMBER_SELECT_UNKNOWN_NAME,
  c_error_MONO_OBJECT_ITEM_SELECT_ERROR,
  c_error_MONO_OBJECT_CREATE_ERROR,
  c_error_MONO_OBJECT_WRONG_OBJECT_REFERENCE,
  c_error_MONO_OBJECT_ARRAY_CREATE_ERROR,
  c_error_MONO_OBJECT_VALUE_ERROR,
  c_error_MONO_OBJECT_TO_STRING_ERROR,
  c_error_MONO_OBJECT_SET_ITEM_ERROR,
  c_error_MONO_PROPERTY_NO_SET_METHOD,
};

// - MONO error strings -
extern const char *mono_error_strings[];

// - MONO initialize -
bool mono_initialize(script_parser_s &sp);

// - MONO print exception -
bool mono_print_exception(interpreter_s &it,exception_s &exception);

// - class MONO_ASSEMBLY -
extern built_in_variable_s mono_assembly_variables[];
extern built_in_method_s mono_assembly_methods[];
extern built_in_class_s mono_assembly_class;

void bic_mono_assembly_consts(location_array_s &const_locations);
void bic_mono_assembly_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_mono_assembly_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_mono_assembly_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mono_assembly_method_MonoAssembly_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mono_assembly_method_get_class_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mono_assembly_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mono_assembly_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class MONO_CLASS -
extern built_in_variable_s mono_class_variables[];
extern built_in_method_s mono_class_methods[];
extern built_in_class_s mono_class_class;

void bic_mono_class_consts(location_array_s &const_locations);
void bic_mono_class_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_mono_class_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_mono_class_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mono_class_method__name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mono_class_method__namespace_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mono_class_method__new_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mono_class_method_fields_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mono_class_method_methods_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mono_class_method_properties_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mono_class_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mono_class_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class MONO_OBJECT -
extern built_in_variable_s mono_object_variables[];
extern built_in_method_s mono_object_methods[];
extern built_in_class_s mono_object_class;

void bic_mono_object_consts(location_array_s &const_locations);
void bic_mono_object_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_mono_object_clear(interpreter_thread_s &it,location_s *location_ptr);
bool bic_mono_object_invoke(interpreter_thread_s &it,uli *code,unsigned stack_base,uli *operands);
bool bic_mono_object_member(interpreter_thread_s &it,uli *code,unsigned stack_base);

bool bic_mono_object_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mono_object_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mono_object_method_MonoObject_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mono_object_method__array_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mono_object_method__value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mono_object_method__class_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mono_object_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_mono_object_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class MONO_PROPERTY -
extern built_in_variable_s mono_property_variables[];
extern built_in_method_s mono_property_methods[];
extern built_in_class_s mono_property_class;

void bic_mono_property_consts(location_array_s &const_locations);
void bic_mono_property_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_mono_property_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_mono_property_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class MONO_ITEM_REF -
extern built_in_variable_s mono_item_ref_variables[];
extern built_in_method_s mono_item_ref_methods[];
extern built_in_class_s mono_item_ref_class;

void bic_mono_item_ref_consts(location_array_s &const_locations);
void bic_mono_item_ref_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_mono_item_ref_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_mono_item_ref_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

