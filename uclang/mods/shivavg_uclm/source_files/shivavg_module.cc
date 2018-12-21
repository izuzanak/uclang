
@begin
include "shivavg_module.h"
@end

// - SHIVAVG indexes of built in classes -
unsigned c_bi_class_shiva_vg = c_idx_not_exist;

// - SHIVAVG module -
built_in_module_s module =
{/*{{{*/
  1,                       // Class count
  shivavg_classes,         // Classes

  0,                       // Error base index
  2,                       // Error count
  shivavg_error_strings,   // Error strings

  shivavg_initialize,      // Initialize function
  shivavg_print_exception, // Print exceptions function
};/*}}}*/

// - SHIVAVG classes -
built_in_class_s *shivavg_classes[] =
{/*{{{*/
  &shiva_vg_class,
};/*}}}*/

// - SHIVAVG error strings -
const char *shivavg_error_strings[] =
{/*{{{*/
  "error_SHIVA_VG_CONTEXT_ALREADY_CREATED",
  "error_SHIVA_VG_CONTEXT_CREATE_ERROR",
};/*}}}*/

// - SHIVAVG initialize -
bool shivavg_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize shiva_vg class identifier -
  c_bi_class_shiva_vg = class_base_idx++;

  return true;
}/*}}}*/

// - SHIVAVG print exception -
bool shivavg_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_SHIVA_VG_CONTEXT_ALREADY_CREATED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nShivaVg context was already created\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SHIVA_VG_CONTEXT_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating ShivaVg context\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class SHIVA_VG -
built_in_class_s shiva_vg_class =
{/*{{{*/
  "ShivaVg",
  c_modifier_public | c_modifier_final,
  4, shiva_vg_methods,
  0, shiva_vg_variables,
  bic_shiva_vg_consts,
  bic_shiva_vg_init,
  bic_shiva_vg_clear,
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

built_in_method_s shiva_vg_methods[] =
{/*{{{*/
  {
    "create_context#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_shiva_vg_method_create_context_2
  },
  {
    "resize_surface#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_shiva_vg_method_resize_surface_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_shiva_vg_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_shiva_vg_method_print_0
  },
};/*}}}*/

built_in_variable_s shiva_vg_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_shiva_vg_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_shiva_vg_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_shiva_vg_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_shiva_vg_method_create_context_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
width:retrieve_integer
height:retrieve_integer
>
method create_context
; @end

  // - ERROR -
  if (shivavg_c::context)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SHIVA_VG_CONTEXT_ALREADY_CREATED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (!vgCreateContextSH(width,height))
  {
    exception_s::throw_exception(it,module.error_base + c_error_SHIVA_VG_CONTEXT_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set context flag -
  shivavg_c::context = true;

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_shiva_vg_method_resize_surface_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
width:retrieve_integer
height:retrieve_integer
>
method resize_surface
; @end

  vgResizeSurfaceSH(width,height);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_shiva_vg_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("ShivaVg"),"ShivaVg");
  );

  return true;
}/*}}}*/

bool bic_shiva_vg_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("ShivaVg");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

