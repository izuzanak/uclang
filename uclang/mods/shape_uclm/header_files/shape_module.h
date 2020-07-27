
#ifndef __SHAPE_MODULE_H
#define __SHAPE_MODULE_H

@begin
include "ucl_shape.h"
@end

// - SHAPE indexes of built in classes -
extern unsigned c_bi_class_shp_handle;
extern unsigned c_bi_class_shp_object;

// - SHAPE module -
extern "C" EXPORT built_in_module_s module;

// - SHAPE classes -
extern built_in_class_s *shape_classes[];

// - SHAPE error identifiers -
enum
{
  c_error_SHP_HANDLE_FILE_OPEN_ERROR,
  c_error_SHP_HANDLE_INDEX_EXCEEDS_RANGE,
  c_error_SHP_OBJECT_INDEX_EXCEEDS_RANGE,
};

// - SHAPE error strings -
extern const char *shape_error_strings[];

// - SHAPE initialize -
bool shape_initialize(script_parser_s &sp);

// - SHAPE print exception -
bool shape_print_exception(interpreter_s &it,exception_s &exception);

// - class SHP_HANDLE -
extern built_in_variable_s shp_handle_variables[];
extern built_in_method_s shp_handle_methods[];
extern built_in_class_s shp_handle_class;

void bic_shp_handle_consts(location_array_s &const_locations);
void bic_shp_handle_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_shp_handle_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_shp_handle_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_shp_handle_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_shp_handle_method_ShpHandle_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_shp_handle_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_shp_handle_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_shp_handle_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_shp_handle_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_shp_handle_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_shp_handle_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class SHP_OBJECT -
extern built_in_variable_s shp_object_variables[];
extern built_in_method_s shp_object_methods[];
extern built_in_class_s shp_object_class;

void bic_shp_object_consts(location_array_s &const_locations);
void bic_shp_object_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_shp_object_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_shp_object_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_shp_object_method_shape_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_shp_object_method_id_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_shp_object_method_x_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_shp_object_method_y_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_shp_object_method_z_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_shp_object_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_shp_object_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_shp_object_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

