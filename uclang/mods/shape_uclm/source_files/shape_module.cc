
@begin
include "shape_module.h"
@end

// - SHAPE indexes of built in classes -
unsigned c_bi_class_shp_handle = c_idx_not_exist;

// - SHAPE module -
EXPORT built_in_module_s module =
{/*{{{*/
  1,                     // Class count
  shape_classes,         // Classes

  0,                     // Error base index
  1,                     // Error count
  shape_error_strings,   // Error strings

  shape_initialize,      // Initialize function
  shape_print_exception, // Print exceptions function
};/*}}}*/

// - SHAPE classes -
built_in_class_s *shape_classes[] =
{/*{{{*/
  &shp_handle_class,
};/*}}}*/

// - SHAPE error strings -
const char *shape_error_strings[] =
{/*{{{*/
  "error_SHAPE_DUMMY_ERROR",
};/*}}}*/

// - SHAPE initialize -
bool shape_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize shp_handle class identifier -
  c_bi_class_shp_handle = class_base_idx++;

  return true;
}/*}}}*/

// - SHAPE print exception -
bool shape_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_SHAPE_DUMMY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nShape dummy error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class SHP_HANDLE -
built_in_class_s shp_handle_class =
{/*{{{*/
  "ShpHandle",
  c_modifier_public | c_modifier_final,
  4, shp_handle_methods,
  0, shp_handle_variables,
  bic_shp_handle_consts,
  bic_shp_handle_init,
  bic_shp_handle_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s shp_handle_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_shp_handle_operator_binary_equal
  },
  {
    "ShpHandle#1",
    c_modifier_public | c_modifier_final,
    bic_shp_handle_method_ShpHanle_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_shp_handle_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_shp_handle_method_print_0
  },
};/*}}}*/

built_in_variable_s shp_handle_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_shp_handle_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_shp_handle_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_shp_handle_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_shp_handle_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_shp_handle_method_ShpHanle_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  
  // FIXME TODO continue ...
  BIC_TODO_ERROR(__FILE__,__LINE__);
  return false;
}/*}}}*/

bool bic_shp_handle_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("ShpHandle"),"ShpHandle");
  );

  return true;
}/*}}}*/

bool bic_shp_handle_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("ShpHandle");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

