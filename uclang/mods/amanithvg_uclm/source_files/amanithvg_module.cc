
@begin
include "amanithvg_module.h"
@end

// - AMANITHVG indexes of built in classes -
unsigned c_bi_class_amanith_vg_context = c_idx_not_exist;
unsigned c_bi_class_amanith_vg_surface = c_idx_not_exist;

// - AMANITHVG module -
built_in_module_s module =
{/*{{{*/
  2,                         // Class count
  amanithvg_classes,         // Classes

  0,                         // Error base index
  6,                         // Error count
  amanithvg_error_strings,   // Error strings

  amanithvg_initialize,      // Initialize function
  amanithvg_print_exception, // Print exceptions function
};/*}}}*/

// - AMANITHVG classes -
built_in_class_s *amanithvg_classes[] =
{/*{{{*/
  &amanith_vg_context_class,
  &amanith_vg_surface_class,
};/*}}}*/

// - AMANITHVG error strings -
const char *amanithvg_error_strings[] =
{/*{{{*/
  "error_AMANITH_VG_CONTEXT_CREATE_ERROR",
  "error_AMANITH_VG_CONTEXT_MAKE_CURRENT_ERROR",
  "error_AMANITH_VG_CONTEXT_DROP_CURRENT_ERROR",
  "error_AMANITH_VG_CONTEXT_CURRENT_DOES_NOT_EXIST",
  "error_AMANITH_VG_SURFACE_CREATE_ERROR",
  "error_AMANITH_VG_SURFACE_CURRENT_DOES_NOT_EXIST",
};/*}}}*/

// - AMANITHVG initialize -
bool amanithvg_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize amanith_vg_context class identifier -
  c_bi_class_amanith_vg_context = class_base_idx++;

  // - initialize amanith_vg_surface class identifier -
  c_bi_class_amanith_vg_surface = class_base_idx++;

  return true;
}/*}}}*/

// - AMANITHVG print exception -
bool amanithvg_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_AMANITH_VG_CONTEXT_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nAmanithVG context create error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_AMANITH_VG_CONTEXT_MAKE_CURRENT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nAmanithVG context make current error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_AMANITH_VG_CONTEXT_DROP_CURRENT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nAmanithVG context drop current error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_AMANITH_VG_CONTEXT_CURRENT_DOES_NOT_EXIST:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCurrent AmanithVG context does not exist\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_AMANITH_VG_SURFACE_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nAmanithVG surface create error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_AMANITH_VG_SURFACE_CURRENT_DOES_NOT_EXIST:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCurrent AmanithVG surface does not exist\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class AMANITH_VG_CONTEXT -
built_in_class_s amanith_vg_context_class =
{/*{{{*/
  "AmanithVgContext",
  c_modifier_public | c_modifier_final,
  7, amanith_vg_context_methods,
  0, amanith_vg_context_variables,
  bic_amanith_vg_context_consts,
  bic_amanith_vg_context_init,
  bic_amanith_vg_context_clear,
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

built_in_method_s amanith_vg_context_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_amanith_vg_context_operator_binary_equal
  },
  {
    "AmanithVgContext#0",
    c_modifier_public | c_modifier_final,
    bic_amanith_vg_context_method_AmanithVgContext_0
  },
  {
    "make_current#1",
    c_modifier_public | c_modifier_final,
    bic_amanith_vg_context_method_make_current_1
  },
  {
    "drop_current#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_amanith_vg_context_method_drop_current_0
  },
  {
    "current#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_amanith_vg_context_method_current_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_amanith_vg_context_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_amanith_vg_context_method_print_0
  },
};/*}}}*/

built_in_variable_s amanith_vg_context_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_amanith_vg_context_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_amanith_vg_context_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (void *)nullptr;
}/*}}}*/

void bic_amanith_vg_context_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  void *ctx_ptr = (void *)location_ptr->v_data_ptr;

  if (ctx_ptr != nullptr)
  {
    vgPrivContextDestroyMZT(ctx_ptr);
  }
}/*}}}*/

bool bic_amanith_vg_context_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_amanith_vg_context_method_AmanithVgContext_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  void *ctx_ptr = vgPrivContextCreateMZT(nullptr);

  // - ERROR -
  if (ctx_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_AMANITH_VG_CONTEXT_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set amanith vg ctx_ptr destination location -
  dst_location->v_data_ptr = (void *)ctx_ptr;

  return true;
}/*}}}*/

bool bic_amanith_vg_context_method_make_current_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
surface:c_bi_class_amanith_vg_surface
>
method make_current
; @end

  void *ctx_ptr = (void *)dst_location->v_data_ptr;
  void *sface_ptr = (void *)src_0_location->v_data_ptr;

  // - ERROR -
  if (vgPrivMakeCurrentMZT(ctx_ptr,sface_ptr) == VG_FALSE)
  {
    exception_s::throw_exception(it,module.error_base + c_error_AMANITH_VG_CONTEXT_MAKE_CURRENT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - change current context location -
  if (amanith_vg_c::context_loc != nullptr)
  {
    it.release_location_ptr(amanith_vg_c::context_loc);
  }

  dst_location->v_reference_cnt.atomic_inc();
  amanith_vg_c::context_loc = dst_location;

  // - change current surface location -
  if (amanith_vg_c::surface_loc != nullptr)
  {
    it.release_location_ptr(amanith_vg_c::surface_loc);
  }

  src_0_location->v_reference_cnt.atomic_inc();
  amanith_vg_c::surface_loc = src_0_location;

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_amanith_vg_context_method_drop_current_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/

  // - ERROR -
  if (vgPrivMakeCurrentMZT(nullptr,nullptr) == VG_FALSE)
  {
    exception_s::throw_exception(it,module.error_base + c_error_AMANITH_VG_CONTEXT_DROP_CURRENT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - change current context location -
  if (amanith_vg_c::context_loc != nullptr)
  {
    it.release_location_ptr(amanith_vg_c::context_loc);
    amanith_vg_c::context_loc = nullptr;
  }

  // - change current surface location -
  if (amanith_vg_c::surface_loc != nullptr)
  {
    it.release_location_ptr(amanith_vg_c::surface_loc);
    amanith_vg_c::surface_loc = nullptr;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_amanith_vg_context_method_current_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/

  // - ERROR -
  if (amanith_vg_c::context_loc == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_AMANITH_VG_CONTEXT_CURRENT_DOES_NOT_EXIST,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  amanith_vg_c::context_loc->v_reference_cnt.atomic_inc();
  BIC_SET_RESULT(amanith_vg_c::context_loc);

  return true;
}/*}}}*/

bool bic_amanith_vg_context_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("AmanithVgContext"),"AmanithVgContext");
  );

  return true;
}/*}}}*/

bool bic_amanith_vg_context_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("AmanithVgContext");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class AMANITH_VG_SURFACE -
built_in_class_s amanith_vg_surface_class =
{/*{{{*/
  "AmanithVgSurface",
  c_modifier_public | c_modifier_final,
  9, amanith_vg_surface_methods,
  0, amanith_vg_surface_variables,
  bic_amanith_vg_surface_consts,
  bic_amanith_vg_surface_init,
  bic_amanith_vg_surface_clear,
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

built_in_method_s amanith_vg_surface_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_amanith_vg_surface_operator_binary_equal
  },
  {
    "AmanithVgSurface#5",
    c_modifier_public | c_modifier_final,
    bic_amanith_vg_surface_method_AmanithVgSurface_5
  },
  {
    "current#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_amanith_vg_surface_method_current_0
  },
  {
    "max_dimension#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_amanith_vg_surface_method_max_dimension_0
  },
  {
    "width#0",
    c_modifier_public | c_modifier_final,
    bic_amanith_vg_surface_method_width_0
  },
  {
    "height#0",
    c_modifier_public | c_modifier_final,
    bic_amanith_vg_surface_method_height_0
  },
  {
    "resize#2",
    c_modifier_public | c_modifier_final,
    bic_amanith_vg_surface_method_resize_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_amanith_vg_surface_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_amanith_vg_surface_method_print_0
  },
};/*}}}*/

built_in_variable_s amanith_vg_surface_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_amanith_vg_surface_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_amanith_vg_surface_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (void *)nullptr;
}/*}}}*/

void bic_amanith_vg_surface_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  void *sface_ptr = (void *)location_ptr->v_data_ptr;

  if (sface_ptr != nullptr)
  {
    vgPrivSurfaceDestroyMZT(sface_ptr);
  }
}/*}}}*/

bool bic_amanith_vg_surface_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/


bool bic_amanith_vg_surface_method_AmanithVgSurface_5(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
width:retrieve_integer
height:retrieve_integer
linear_color_space:retrieve_integer
alpha_premultiplied:retrieve_integer
alpha_mask:retrieve_integer
>
method AmanithVgSurface
; @end

  void *sface_ptr = vgPrivSurfaceCreateMZT(width,height,
      linear_color_space  ? VG_TRUE : VG_FALSE,
      alpha_premultiplied ? VG_TRUE : VG_FALSE,
      alpha_mask          ? VG_TRUE : VG_FALSE);

  // - ERROR -
  if (sface_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_AMANITH_VG_SURFACE_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set amanith vg surface destination location -
  dst_location->v_data_ptr = (void *)sface_ptr;

  return true;
}/*}}}*/

bool bic_amanith_vg_surface_method_current_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/

  // - ERROR -
  if (amanith_vg_c::surface_loc == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_AMANITH_VG_SURFACE_CURRENT_DOES_NOT_EXIST,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  amanith_vg_c::surface_loc->v_reference_cnt.atomic_inc();
  BIC_SET_RESULT(amanith_vg_c::surface_loc);

  return true;
}/*}}}*/

bool bic_amanith_vg_surface_method_max_dimension_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  long long int result = vgPrivSurfaceMaxDimensionGetMZT();

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_amanith_vg_surface_method_width_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = vgPrivGetSurfaceWidthMZT((void *)dst_location->v_data_ptr);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_amanith_vg_surface_method_height_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = vgPrivGetSurfaceHeightMZT((void *)dst_location->v_data_ptr);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_amanith_vg_surface_method_resize_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
width:retrieve_integer
height:retrieve_integer
>
method resize
; @end

  vgPrivSurfaceResizeMZT((void *)dst_location->v_data_ptr,width,height);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_amanith_vg_surface_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("AmanithVgSurface"),"AmanithVgSurface");
  );

  return true;
}/*}}}*/

bool bic_amanith_vg_surface_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("AmanithVgSurface");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

