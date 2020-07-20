
#ifndef __SHAPE_MODULE_H
#define __SHAPE_MODULE_H

@begin
include "ucl_shape.h"
@end

// - SHAPE indexes of built in classes -
extern unsigned c_bi_class_shp_handle;

// - SHAPE module -
extern "C" EXPORT built_in_module_s module;

// - SHAPE classes -
extern built_in_class_s *shape_classes[];

// - SHAPE error identifiers -
enum
{
  c_error_SHAPE_DUMMY_ERROR,
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
bool bic_shp_handle_method_ShpHanle_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_shp_handle_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_shp_handle_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

