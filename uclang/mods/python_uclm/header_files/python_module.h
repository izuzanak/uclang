
#ifndef __PYTHON_MODULE_H
#define __PYTHON_MODULE_H

@begin
include "ucl_python.h"
@end

// - PYTHON indexes of built in classes -
extern unsigned c_bi_class_py_object;
extern unsigned c_bi_class_py_attr_ref;
extern unsigned c_bi_class_py_item_ref;

// - PYTHON module -
extern built_in_module_s module;

// - PYTHON classes -
extern built_in_class_s *python_classes[];

// - PYTHON error identifiers -
enum
{
  c_error_PY_OBJECT_INVOKE_METHOD_UNKNOWN_NAME = 0,
  c_error_PY_OBJECT_INVOKE_METHOD_ERROR,
  c_error_PY_OBJECT_INVOKE_METHOD_WRONG_PARAMETER,
  c_error_PY_OBJECT_MEMBER_SELECT_ERROR,
  c_error_PY_OBJECT_ITEM_SELECT_ERROR,
  c_error_PY_OBJECT_WRONG_OBJECT_REFERENCE,
  c_error_PY_OBJECT_CREATE_ERROR,
  c_error_PY_OBJECT_MODULE_ERROR,
  c_error_PY_OBJECT_TUPLE_CREATE_ERROR,
  c_error_PY_OBJECT_VALUE_ERROR,
  c_error_PY_OBJECT_TYPE_ERROR,
  c_error_PY_OBJECT_LENGTH_ERROR,
  c_error_PY_OBJECT_GET_ATTR_ERROR,
  c_error_PY_OBJECT_SET_ATTR_ERROR,
  c_error_PY_OBJECT_DEL_ATTR_ERROR,
  c_error_PY_OBJECT_GET_ITEM_ERROR,
  c_error_PY_OBJECT_SET_ITEM_ERROR,
  c_error_PY_OBJECT_DEL_ITEM_ERROR,
  c_error_PY_OBJECT_DIR_ERROR,
  c_error_PY_OBJECT_TO_STRING_ERROR,
};

// - PYTHON error strings -
extern const char *python_error_strings[];

// - PYTHON initialize -
bool python_initialize(script_parser_s &sp);

// - PYTHON print exception -
bool python_print_exception(interpreter_s &it,exception_s &exception);

// - class PY_OBJECT -
extern built_in_variable_s py_object_variables[];
extern built_in_method_s py_object_methods[];
extern built_in_class_s py_object_class;

void bic_py_object_consts(location_array_s &const_locations);
void bic_py_object_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_py_object_clear(interpreter_thread_s &it,location_s *location_ptr);
bool bic_py_object_invoke(interpreter_thread_s &it,uli *code,unsigned stack_base,uli *operands);
bool bic_py_object_member(interpreter_thread_s &it,uli *code,unsigned stack_base);

bool bic_py_object_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_py_object_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_py_object_method_PyObject_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_py_object_method_module_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_py_object_method_tuple_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_py_object_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_py_object_method_get_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_py_object_method_has_attr_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_py_object_method_get_attr_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_py_object_method_set_attr_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_py_object_method_del_attr_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_py_object_method_call_attr_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_py_object_method_get_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_py_object_method_set_item_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_py_object_method_del_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_py_object_method_dir_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_py_object_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_py_object_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_py_object_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class PY_ATTR_REF -
extern built_in_variable_s py_attr_ref_variables[];
extern built_in_method_s py_attr_ref_methods[];
extern built_in_class_s py_attr_ref_class;

void bic_py_attr_ref_consts(location_array_s &const_locations);
void bic_py_attr_ref_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_py_attr_ref_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_py_attr_ref_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_py_attr_ref_method_get_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_py_attr_ref_method_set_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class PY_ITEM_REF -
extern built_in_variable_s py_item_ref_variables[];
extern built_in_method_s py_item_ref_methods[];
extern built_in_class_s py_item_ref_class;

void bic_py_item_ref_consts(location_array_s &const_locations);
void bic_py_item_ref_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_py_item_ref_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_py_item_ref_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_py_item_ref_method_get_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_py_item_ref_method_set_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

