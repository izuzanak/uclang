
@begin
include "uv_module.h"
@end

// - UV indexes of built in classes -
unsigned c_bi_class_uv_loop = c_idx_not_exist;

// - UV module -
built_in_module_s module =
{/*{{{*/
  1,                  // Class count
  uv_classes,         // Classes

  0,                  // Error base index
  1,                  // Error count
  uv_error_strings,   // Error strings

  uv_initialize,      // Initialize function
  uv_print_exception, // Print exceptions function
};/*}}}*/

// - UV classes -
built_in_class_s *uv_classes[] =
{/*{{{*/
  &uv_loop_class,
};/*}}}*/

// - UV error strings -
const char *uv_error_strings[] =
{/*{{{*/
  "error_UV_DUMMY_ERROR",
};/*}}}*/

// - UV initialize -
bool uv_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize uv_loop class identifier -
  c_bi_class_uv_loop = class_base_idx++;

  return true;
}/*}}}*/

// - UV print exception -
bool uv_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_UV_DUMMY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nLibuv dummy error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class UV_LOOP -
built_in_class_s uv_loop_class =
{/*{{{*/
  "UvLoop",
  c_modifier_public | c_modifier_final,
  4, uv_loop_methods,
  3, uv_loop_variables,
  bic_uv_loop_consts,
  bic_uv_loop_init,
  bic_uv_loop_clear,
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

built_in_method_s uv_loop_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_uv_loop_operator_binary_equal
  },
  {
    "UvLoop#0",
    c_modifier_public | c_modifier_final,
    bic_uv_loop_method_UvLoop_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_uv_loop_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_uv_loop_method_print_0
  },
};/*}}}*/

built_in_variable_s uv_loop_variables[] =
{/*{{{*/

  // - uv loop run mode constants -
  { "UV_RUN_DEFAULT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "UV_RUN_ONCE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "UV_RUN_NOWAIT", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_uv_loop_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert uv loop run mode constants -
  {
    const_locations.push_blanks(3);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 3);

#define CREATE_UV_LOOP_RUN_MODE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_UV_LOOP_RUN_MODE_BIC_STATIC(UV_RUN_DEFAULT);
    CREATE_UV_LOOP_RUN_MODE_BIC_STATIC(UV_RUN_ONCE);
    CREATE_UV_LOOP_RUN_MODE_BIC_STATIC(UV_RUN_NOWAIT);
  }
}/*}}}*/

void bic_uv_loop_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (uv_loop_t *)nullptr;
}/*}}}*/

void bic_uv_loop_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  uv_loop_t *uvl_ptr = (uv_loop_t *)location_ptr->v_data_ptr;

  if (uvl_ptr != nullptr)
  {
    // - close uv loop -
    uv_loop_close(uvl_ptr);
    cfree(uvl_ptr);
  }
}/*}}}*/

bool bic_uv_loop_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_uv_loop_method_UvLoop_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - create and initialize uv loop object -
  uv_loop_t *uvl_ptr = (uv_loop_t *)cmalloc(sizeof(uv_loop_t));
  uv_loop_init(uvl_ptr);

  dst_location->v_data_ptr = (uv_loop_t *)uvl_ptr;

  return true;
}/*}}}*/

bool bic_uv_loop_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("UvLoop"),"UvLoop");
  );

  return true;
}/*}}}*/

bool bic_uv_loop_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("UvLoop");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

