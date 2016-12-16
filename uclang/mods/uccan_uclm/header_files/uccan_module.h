
#ifndef __UCCAN_MODULE_H
#define __UCCAN_MODULE_H

@begin
include "ucl_uccan.h"
@end

// - UCCAN indexes of built in classes -
extern unsigned c_bi_class_can_obj_dict;
extern unsigned c_bi_class_can_object;

// - UCCAN module -
extern built_in_module_s module;

// - UCCAN classes -
extern built_in_class_s *uccan_classes[];

// - UCCAN error identifiers -
enum
{
  c_error_CAN_OBJECT_DICT_CREATE_ERROR = 0,
  c_error_CAN_OBJECT_DICT_OPEN_ERROR,
  c_error_CAN_OBJECT_DICT_INDEX_NOT_PRESENT,
  c_error_CAN_OBJECT_UNSUPPORTED_VARIABLE_TYPE,
  c_error_CAN_OBJECT_UNSUPPORTED_OBJECT_TYPE,
  c_error_CAN_OBJECT_READ_ERROR,
};

// - UCCAN error strings -
extern const char *uccan_error_strings[];

// - UCCAN initialize -
bool uccan_initialize(script_parser_s &sp);

// - UCCAN print exception -
bool uccan_print_exception(interpreter_s &it,exception_s &exception);

// - class CAN_OBJ_DICT -
extern built_in_variable_s can_obj_dict_variables[];
extern built_in_method_s can_obj_dict_methods[];
extern built_in_class_s can_obj_dict_class;

void bic_can_obj_dict_consts(location_array_s &const_locations);
void bic_can_obj_dict_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_can_obj_dict_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_can_obj_dict_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_can_obj_dict_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_can_obj_dict_method_CanObjDict_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_can_obj_dict_method_CanObjDict_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_can_obj_dict_method_FindObj_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_can_obj_dict_method_FindObj_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_can_obj_dict_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_can_obj_dict_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class CAN_OBJECT -
extern built_in_variable_s can_object_variables[];
extern built_in_method_s can_object_methods[];
extern built_in_class_s can_object_class;

void bic_can_object_consts(location_array_s &const_locations);
void bic_can_object_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_can_object_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_can_object_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_can_object_method_size_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_can_object_method_flags_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_can_object_method_buffer_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_can_object_method_get_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_can_object_method_write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_can_object_method_read_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_can_object_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_can_object_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

