
@begin
include "vg_module.h"
@end

// - VG indexes of built in classes -
unsigned c_bi_class_vg = c_idx_not_exist;
unsigned c_bi_class_vg_paint = c_idx_not_exist;
unsigned c_bi_class_vg_path = c_idx_not_exist;

// - VG indexes of remote classes -
unsigned c_rm_class_vec2 = c_idx_not_exist;
unsigned c_rm_class_vec3 = c_idx_not_exist;
unsigned c_rm_class_vec4 = c_idx_not_exist;
unsigned c_rm_class_mat4 = c_idx_not_exist;

// - VG module -
built_in_module_s module =
{/*{{{*/
  3,                   // Class count
  vg_classes,          // Classes

  0,                   // Error base index
  6,                   // Error count
  vg_error_strings,    // Error strings

  vg_initialize,       // Initialize function
  vg_print_exception,  // Print exceptions function
};/*}}}*/

// - VG classes -
built_in_class_s *vg_classes[] =
{/*{{{*/
  &vg_class,
  &vg_paint_class,
  &vg_path_class,
};/*}}}*/

// - VG error strings -
const char *vg_error_strings[] =
{/*{{{*/
  "error_VG_UNKNOWN_STROKE_CAP_STYLE",
  "error_VG_UNKNOWN_STROKE_JOIN_STYLE",
  "error_VG_WRONG_DASH_PATTERN_ARRAY_CONTENT",
  "error_VG_PAINT_UNKNOWN_PAINT_TYPE",
  "error_VG_PAINT_WRONG_TARGET_PAINT_MODES",
  "error_VG_PAINT_WRONG_SOURCE_PAINT_MODE",
};/*}}}*/

// - VG initialize -
bool vg_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize vg class identifier -
  c_bi_class_vg = class_base_idx++;

  // - initialize vg_paint class identifier -
  c_bi_class_vg_paint = class_base_idx++;

  // - initialize vg_path class identifier -
  c_bi_class_vg_path = class_base_idx++;

  // - retrieve remote vec3 class index -
  c_rm_class_vec2 = sp.resolve_class_idx_by_name("Vec2",c_idx_not_exist);

  // - retrieve remote vec3 class index -
  c_rm_class_vec3 = sp.resolve_class_idx_by_name("Vec3",c_idx_not_exist);

  // - retrieve remote vec3 class index -
  c_rm_class_vec4 = sp.resolve_class_idx_by_name("Vec4",c_idx_not_exist);

  // - retrieve remote mat4 class index -
  c_rm_class_mat4 = sp.resolve_class_idx_by_name("Mat4",c_idx_not_exist);

  // - ERROR -
  if (c_rm_class_vec2 == c_idx_not_exist ||
      c_rm_class_vec3 == c_idx_not_exist ||
      c_rm_class_vec4 == c_idx_not_exist ||
      c_rm_class_mat4 == c_idx_not_exist)
  {
    sp.error_code.push(ei_module_cannot_find_remote_class);
    sp.error_code.push(sp.module_names_positions[sp.module_idx].ui_first);
    sp.error_code.push(sp.module_idx);

    return false;
  }

  return true;
}/*}}}*/

// - VG print exception -
bool vg_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_VG_UNKNOWN_STROKE_CAP_STYLE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nOpenVG unrecognized stroke cap style\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_VG_UNKNOWN_STROKE_JOIN_STYLE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nOpenVG unrecognized stroke join style\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_VG_WRONG_DASH_PATTERN_ARRAY_CONTENT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nOpenVG wrong content of dash pattern array\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_VG_PAINT_UNKNOWN_PAINT_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nOpenVG unrecognized paint type\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_VG_PAINT_WRONG_TARGET_PAINT_MODES:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nOpenVG wrong target paint modes\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_VG_PAINT_WRONG_SOURCE_PAINT_MODE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nOpenVG wrong source paint mode\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class VG -
built_in_class_s vg_class =
{/*{{{*/
  "Vg",
  c_modifier_public | c_modifier_final,
  14, vg_methods,
  230, vg_variables,
  bic_vg_consts,
  bic_vg_init,
  bic_vg_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s vg_methods[] =
{/*{{{*/
  {
    "Clear#4",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_vg_method_Clear_4
  },
  {
    "ClearColor#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_vg_method_ClearColor_1
  },
  {
    "StrokeLineWidth#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_vg_method_StrokeLineWidth_1
  },
  {
    "StrokeCapStyle#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_vg_method_StrokeCapStyle_1
  },
  {
    "StrokeJoinStyle#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_vg_method_StrokeJoinStyle_1
  },
  {
    "StrokeDashPattern#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_vg_method_StrokeDashPattern_1
  },
  {
    "LoadIdentity#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_vg_method_LoadIdentity_0
  },
  {
    "Translate#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_vg_method_Translate_2
  },
  {
    "Scale#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_vg_method_Scale_2
  },
  {
    "Shear#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_vg_method_Shear_2
  },
  {
    "Rotate#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_vg_method_Rotate_1
  },
  {
    "Finish#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_vg_method_Finish_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_vg_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_vg_method_print_0
  },
};/*}}}*/

built_in_variable_s vg_variables[] =
{/*{{{*/
  { "VG_FALSE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_TRUE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_NO_ERROR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_BAD_HANDLE_ERROR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_ILLEGAL_ARGUMENT_ERROR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_OUT_OF_MEMORY_ERROR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PATH_CAPABILITY_ERROR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_UNSUPPORTED_IMAGE_FORMAT_ERROR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_UNSUPPORTED_PATH_FORMAT_ERROR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_IMAGE_IN_USE_ERROR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_NO_CONTEXT_ERROR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_MATRIX_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_FILL_RULE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_IMAGE_QUALITY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_RENDERING_QUALITY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_BLEND_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_IMAGE_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_SCISSOR_RECTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_COLOR_TRANSFORM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_COLOR_TRANSFORM_VALUES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_STROKE_LINE_WIDTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_STROKE_CAP_STYLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_STROKE_JOIN_STYLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_STROKE_MITER_LIMIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_STROKE_DASH_PATTERN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_STROKE_DASH_PHASE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_STROKE_DASH_PHASE_RESET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_TILE_FILL_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_CLEAR_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_GLYPH_ORIGIN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_MASKING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_SCISSORING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PIXEL_LAYOUT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_SCREEN_LAYOUT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_FILTER_FORMAT_LINEAR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_FILTER_FORMAT_PREMULTIPLIED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_FILTER_CHANNEL_MASK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_MAX_SCISSOR_RECTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_MAX_DASH_COUNT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_MAX_KERNEL_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_MAX_SEPARABLE_KERNEL_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_MAX_COLOR_RAMP_STOPS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_MAX_IMAGE_WIDTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_MAX_IMAGE_HEIGHT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_MAX_IMAGE_PIXELS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_MAX_IMAGE_BYTES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_MAX_FLOAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_MAX_GAUSSIAN_STD_DEVIATION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_RENDERING_QUALITY_NONANTIALIASED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_RENDERING_QUALITY_FASTER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_RENDERING_QUALITY_BETTER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PIXEL_LAYOUT_UNKNOWN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PIXEL_LAYOUT_RGB_VERTICAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PIXEL_LAYOUT_BGR_VERTICAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PIXEL_LAYOUT_RGB_HORIZONTAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PIXEL_LAYOUT_BGR_HORIZONTAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_MATRIX_PATH_USER_TO_SURFACE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_MATRIX_IMAGE_USER_TO_SURFACE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_MATRIX_FILL_PAINT_TO_USER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_MATRIX_STROKE_PAINT_TO_USER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_MATRIX_GLYPH_USER_TO_SURFACE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_CLEAR_MASK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_FILL_MASK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_SET_MASK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_UNION_MASK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_INTERSECT_MASK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_SUBTRACT_MASK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PATH_DATATYPE_S_8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PATH_DATATYPE_S_16", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PATH_DATATYPE_S_32", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PATH_DATATYPE_F", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_ABSOLUTE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_RELATIVE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_CLOSE_PATH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_MOVE_TO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_LINE_TO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_HLINE_TO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_VLINE_TO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_QUAD_TO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_CUBIC_TO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_SQUAD_TO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_SCUBIC_TO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_SCCWARC_TO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_SCWARC_TO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_LCCWARC_TO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_LCWARC_TO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_MOVE_TO_ABS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_MOVE_TO_REL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_LINE_TO_ABS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_LINE_TO_REL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_HLINE_TO_ABS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_HLINE_TO_REL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_VLINE_TO_ABS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_VLINE_TO_REL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_QUAD_TO_ABS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_QUAD_TO_REL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_CUBIC_TO_ABS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_CUBIC_TO_REL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_SQUAD_TO_ABS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_SQUAD_TO_REL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_SCUBIC_TO_ABS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_SCUBIC_TO_REL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_SCCWARC_TO_ABS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_SCCWARC_TO_REL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_SCWARC_TO_ABS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_SCWARC_TO_REL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_LCCWARC_TO_ABS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_LCCWARC_TO_REL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_LCWARC_TO_ABS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_LCWARC_TO_REL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PATH_CAPABILITY_APPEND_FROM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PATH_CAPABILITY_APPEND_TO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PATH_CAPABILITY_MODIFY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PATH_CAPABILITY_TRANSFORM_FROM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PATH_CAPABILITY_TRANSFORM_TO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PATH_CAPABILITY_INTERPOLATE_FROM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PATH_CAPABILITY_INTERPOLATE_TO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PATH_CAPABILITY_PATH_LENGTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PATH_CAPABILITY_POINT_ALONG_PATH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PATH_CAPABILITY_TANGENT_ALONG_PATH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PATH_CAPABILITY_PATH_BOUNDS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PATH_CAPABILITY_PATH_TRANSFORMED_BOUNDS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PATH_CAPABILITY_ALL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PATH_FORMAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PATH_DATATYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PATH_SCALE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PATH_BIAS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PATH_NUM_SEGMENTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PATH_NUM_COORDS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_CAP_BUTT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_CAP_ROUND", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_CAP_SQUARE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_JOIN_MITER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_JOIN_ROUND", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_JOIN_BEVEL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_EVEN_ODD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_NON_ZERO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_STROKE_PATH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_FILL_PATH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PAINT_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PAINT_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PAINT_COLOR_RAMP_SPREAD_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PAINT_COLOR_RAMP_PREMULTIPLIED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PAINT_COLOR_RAMP_STOPS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PAINT_LINEAR_GRADIENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PAINT_RADIAL_GRADIENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PAINT_PATTERN_TILING_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PAINT_TYPE_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PAINT_TYPE_LINEAR_GRADIENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PAINT_TYPE_RADIAL_GRADIENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PAINT_TYPE_PATTERN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_COLOR_RAMP_SPREAD_PAD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_COLOR_RAMP_SPREAD_REPEAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_COLOR_RAMP_SPREAD_REFLECT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_TILE_FILL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_TILE_PAD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_TILE_REPEAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_TILE_REFLECT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_sRGBX_8888", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_sRGBA_8888", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_sRGBA_8888_PRE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_sRGB_565", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_sRGBA_5551", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_sRGBA_4444", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_sL_8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_lRGBX_8888", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_lRGBA_8888", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_lRGBA_8888_PRE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_lL_8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_A_8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_BW_1", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_A_1", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_A_4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_sXRGB_8888", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_sARGB_8888", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_sARGB_8888_PRE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_sARGB_1555", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_sARGB_4444", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_lXRGB_8888", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_lARGB_8888", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_lARGB_8888_PRE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_sBGRX_8888", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_sBGRA_8888", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_sBGRA_8888_PRE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_sBGR_565", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_sBGRA_5551", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_sBGRA_4444", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_lBGRX_8888", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_lBGRA_8888", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_lBGRA_8888_PRE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_sXBGR_8888", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_sABGR_8888", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_sABGR_8888_PRE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_sABGR_1555", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_sABGR_4444", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_lXBGR_8888", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_lABGR_8888", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_lABGR_8888_PRE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_IMAGE_QUALITY_NONANTIALIASED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_IMAGE_QUALITY_FASTER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_IMAGE_QUALITY_BETTER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_IMAGE_FORMAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_IMAGE_WIDTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_IMAGE_HEIGHT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_DRAW_IMAGE_NORMAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_DRAW_IMAGE_MULTIPLY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_DRAW_IMAGE_STENCIL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_RED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_GREEN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_BLUE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_BLEND_SRC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_BLEND_SRC_OVER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_BLEND_DST_OVER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_BLEND_SRC_IN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_BLEND_DST_IN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_BLEND_MULTIPLY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_BLEND_SCREEN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_BLEND_DARKEN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_BLEND_LIGHTEN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_BLEND_ADDITIVE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_FONT_NUM_GLYPHS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_IMAGE_FORMAT_QUERY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_PATH_DATATYPE_QUERY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_HARDWARE_ACCELERATED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_HARDWARE_UNACCELERATED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_VENDOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_RENDERER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_VERSION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VG_EXTENSIONS", c_modifier_public | c_modifier_static | c_modifier_static_const },
};/*}}}*/

void bic_vg_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert vg basic constants -
  {
    const_locations.push_blanks(230);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 230);

#define CREATE_VG_BASIC_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_VG_BASIC_BIC_STATIC(VG_FALSE);
    CREATE_VG_BASIC_BIC_STATIC(VG_TRUE);
    CREATE_VG_BASIC_BIC_STATIC(VG_NO_ERROR);
    CREATE_VG_BASIC_BIC_STATIC(VG_BAD_HANDLE_ERROR);
    CREATE_VG_BASIC_BIC_STATIC(VG_ILLEGAL_ARGUMENT_ERROR);
    CREATE_VG_BASIC_BIC_STATIC(VG_OUT_OF_MEMORY_ERROR);
    CREATE_VG_BASIC_BIC_STATIC(VG_PATH_CAPABILITY_ERROR);
    CREATE_VG_BASIC_BIC_STATIC(VG_UNSUPPORTED_IMAGE_FORMAT_ERROR);
    CREATE_VG_BASIC_BIC_STATIC(VG_UNSUPPORTED_PATH_FORMAT_ERROR);
    CREATE_VG_BASIC_BIC_STATIC(VG_IMAGE_IN_USE_ERROR);
    CREATE_VG_BASIC_BIC_STATIC(VG_NO_CONTEXT_ERROR);
    CREATE_VG_BASIC_BIC_STATIC(VG_MATRIX_MODE);
    CREATE_VG_BASIC_BIC_STATIC(VG_FILL_RULE);
    CREATE_VG_BASIC_BIC_STATIC(VG_IMAGE_QUALITY);
    CREATE_VG_BASIC_BIC_STATIC(VG_RENDERING_QUALITY);
    CREATE_VG_BASIC_BIC_STATIC(VG_BLEND_MODE);
    CREATE_VG_BASIC_BIC_STATIC(VG_IMAGE_MODE);
    CREATE_VG_BASIC_BIC_STATIC(VG_SCISSOR_RECTS);
    CREATE_VG_BASIC_BIC_STATIC(VG_COLOR_TRANSFORM);
    CREATE_VG_BASIC_BIC_STATIC(VG_COLOR_TRANSFORM_VALUES);
    CREATE_VG_BASIC_BIC_STATIC(VG_STROKE_LINE_WIDTH);
    CREATE_VG_BASIC_BIC_STATIC(VG_STROKE_CAP_STYLE);
    CREATE_VG_BASIC_BIC_STATIC(VG_STROKE_JOIN_STYLE);
    CREATE_VG_BASIC_BIC_STATIC(VG_STROKE_MITER_LIMIT);
    CREATE_VG_BASIC_BIC_STATIC(VG_STROKE_DASH_PATTERN);
    CREATE_VG_BASIC_BIC_STATIC(VG_STROKE_DASH_PHASE);
    CREATE_VG_BASIC_BIC_STATIC(VG_STROKE_DASH_PHASE_RESET);
    CREATE_VG_BASIC_BIC_STATIC(VG_TILE_FILL_COLOR);
    CREATE_VG_BASIC_BIC_STATIC(VG_CLEAR_COLOR);
    CREATE_VG_BASIC_BIC_STATIC(VG_GLYPH_ORIGIN);
    CREATE_VG_BASIC_BIC_STATIC(VG_MASKING);
    CREATE_VG_BASIC_BIC_STATIC(VG_SCISSORING);
    CREATE_VG_BASIC_BIC_STATIC(VG_PIXEL_LAYOUT);
    CREATE_VG_BASIC_BIC_STATIC(VG_SCREEN_LAYOUT);
    CREATE_VG_BASIC_BIC_STATIC(VG_FILTER_FORMAT_LINEAR);
    CREATE_VG_BASIC_BIC_STATIC(VG_FILTER_FORMAT_PREMULTIPLIED);
    CREATE_VG_BASIC_BIC_STATIC(VG_FILTER_CHANNEL_MASK);
    CREATE_VG_BASIC_BIC_STATIC(VG_MAX_SCISSOR_RECTS);
    CREATE_VG_BASIC_BIC_STATIC(VG_MAX_DASH_COUNT);
    CREATE_VG_BASIC_BIC_STATIC(VG_MAX_KERNEL_SIZE);
    CREATE_VG_BASIC_BIC_STATIC(VG_MAX_SEPARABLE_KERNEL_SIZE);
    CREATE_VG_BASIC_BIC_STATIC(VG_MAX_COLOR_RAMP_STOPS);
    CREATE_VG_BASIC_BIC_STATIC(VG_MAX_IMAGE_WIDTH);
    CREATE_VG_BASIC_BIC_STATIC(VG_MAX_IMAGE_HEIGHT);
    CREATE_VG_BASIC_BIC_STATIC(VG_MAX_IMAGE_PIXELS);
    CREATE_VG_BASIC_BIC_STATIC(VG_MAX_IMAGE_BYTES);
    CREATE_VG_BASIC_BIC_STATIC(VG_MAX_FLOAT);
    CREATE_VG_BASIC_BIC_STATIC(VG_MAX_GAUSSIAN_STD_DEVIATION);
    CREATE_VG_BASIC_BIC_STATIC(VG_RENDERING_QUALITY_NONANTIALIASED);
    CREATE_VG_BASIC_BIC_STATIC(VG_RENDERING_QUALITY_FASTER);
    CREATE_VG_BASIC_BIC_STATIC(VG_RENDERING_QUALITY_BETTER);
    CREATE_VG_BASIC_BIC_STATIC(VG_PIXEL_LAYOUT_UNKNOWN);
    CREATE_VG_BASIC_BIC_STATIC(VG_PIXEL_LAYOUT_RGB_VERTICAL);
    CREATE_VG_BASIC_BIC_STATIC(VG_PIXEL_LAYOUT_BGR_VERTICAL);
    CREATE_VG_BASIC_BIC_STATIC(VG_PIXEL_LAYOUT_RGB_HORIZONTAL);
    CREATE_VG_BASIC_BIC_STATIC(VG_PIXEL_LAYOUT_BGR_HORIZONTAL);
    CREATE_VG_BASIC_BIC_STATIC(VG_MATRIX_PATH_USER_TO_SURFACE);
    CREATE_VG_BASIC_BIC_STATIC(VG_MATRIX_IMAGE_USER_TO_SURFACE);
    CREATE_VG_BASIC_BIC_STATIC(VG_MATRIX_FILL_PAINT_TO_USER);
    CREATE_VG_BASIC_BIC_STATIC(VG_MATRIX_STROKE_PAINT_TO_USER);
    CREATE_VG_BASIC_BIC_STATIC(VG_MATRIX_GLYPH_USER_TO_SURFACE);
    CREATE_VG_BASIC_BIC_STATIC(VG_CLEAR_MASK);
    CREATE_VG_BASIC_BIC_STATIC(VG_FILL_MASK);
    CREATE_VG_BASIC_BIC_STATIC(VG_SET_MASK);
    CREATE_VG_BASIC_BIC_STATIC(VG_UNION_MASK);
    CREATE_VG_BASIC_BIC_STATIC(VG_INTERSECT_MASK);
    CREATE_VG_BASIC_BIC_STATIC(VG_SUBTRACT_MASK);
    CREATE_VG_BASIC_BIC_STATIC(VG_PATH_DATATYPE_S_8);
    CREATE_VG_BASIC_BIC_STATIC(VG_PATH_DATATYPE_S_16);
    CREATE_VG_BASIC_BIC_STATIC(VG_PATH_DATATYPE_S_32);
    CREATE_VG_BASIC_BIC_STATIC(VG_PATH_DATATYPE_F);
    CREATE_VG_BASIC_BIC_STATIC(VG_ABSOLUTE);
    CREATE_VG_BASIC_BIC_STATIC(VG_RELATIVE);
    CREATE_VG_BASIC_BIC_STATIC(VG_CLOSE_PATH);
    CREATE_VG_BASIC_BIC_STATIC(VG_MOVE_TO);
    CREATE_VG_BASIC_BIC_STATIC(VG_LINE_TO);
    CREATE_VG_BASIC_BIC_STATIC(VG_HLINE_TO);
    CREATE_VG_BASIC_BIC_STATIC(VG_VLINE_TO);
    CREATE_VG_BASIC_BIC_STATIC(VG_QUAD_TO);
    CREATE_VG_BASIC_BIC_STATIC(VG_CUBIC_TO);
    CREATE_VG_BASIC_BIC_STATIC(VG_SQUAD_TO);
    CREATE_VG_BASIC_BIC_STATIC(VG_SCUBIC_TO);
    CREATE_VG_BASIC_BIC_STATIC(VG_SCCWARC_TO);
    CREATE_VG_BASIC_BIC_STATIC(VG_SCWARC_TO);
    CREATE_VG_BASIC_BIC_STATIC(VG_LCCWARC_TO);
    CREATE_VG_BASIC_BIC_STATIC(VG_LCWARC_TO);
    CREATE_VG_BASIC_BIC_STATIC(VG_MOVE_TO_ABS);
    CREATE_VG_BASIC_BIC_STATIC(VG_MOVE_TO_REL);
    CREATE_VG_BASIC_BIC_STATIC(VG_LINE_TO_ABS);
    CREATE_VG_BASIC_BIC_STATIC(VG_LINE_TO_REL);
    CREATE_VG_BASIC_BIC_STATIC(VG_HLINE_TO_ABS);
    CREATE_VG_BASIC_BIC_STATIC(VG_HLINE_TO_REL);
    CREATE_VG_BASIC_BIC_STATIC(VG_VLINE_TO_ABS);
    CREATE_VG_BASIC_BIC_STATIC(VG_VLINE_TO_REL);
    CREATE_VG_BASIC_BIC_STATIC(VG_QUAD_TO_ABS);
    CREATE_VG_BASIC_BIC_STATIC(VG_QUAD_TO_REL);
    CREATE_VG_BASIC_BIC_STATIC(VG_CUBIC_TO_ABS);
    CREATE_VG_BASIC_BIC_STATIC(VG_CUBIC_TO_REL);
    CREATE_VG_BASIC_BIC_STATIC(VG_SQUAD_TO_ABS);
    CREATE_VG_BASIC_BIC_STATIC(VG_SQUAD_TO_REL);
    CREATE_VG_BASIC_BIC_STATIC(VG_SCUBIC_TO_ABS);
    CREATE_VG_BASIC_BIC_STATIC(VG_SCUBIC_TO_REL);
    CREATE_VG_BASIC_BIC_STATIC(VG_SCCWARC_TO_ABS);
    CREATE_VG_BASIC_BIC_STATIC(VG_SCCWARC_TO_REL);
    CREATE_VG_BASIC_BIC_STATIC(VG_SCWARC_TO_ABS);
    CREATE_VG_BASIC_BIC_STATIC(VG_SCWARC_TO_REL);
    CREATE_VG_BASIC_BIC_STATIC(VG_LCCWARC_TO_ABS);
    CREATE_VG_BASIC_BIC_STATIC(VG_LCCWARC_TO_REL);
    CREATE_VG_BASIC_BIC_STATIC(VG_LCWARC_TO_ABS);
    CREATE_VG_BASIC_BIC_STATIC(VG_LCWARC_TO_REL);
    CREATE_VG_BASIC_BIC_STATIC(VG_PATH_CAPABILITY_APPEND_FROM);
    CREATE_VG_BASIC_BIC_STATIC(VG_PATH_CAPABILITY_APPEND_TO);
    CREATE_VG_BASIC_BIC_STATIC(VG_PATH_CAPABILITY_MODIFY);
    CREATE_VG_BASIC_BIC_STATIC(VG_PATH_CAPABILITY_TRANSFORM_FROM);
    CREATE_VG_BASIC_BIC_STATIC(VG_PATH_CAPABILITY_TRANSFORM_TO);
    CREATE_VG_BASIC_BIC_STATIC(VG_PATH_CAPABILITY_INTERPOLATE_FROM);
    CREATE_VG_BASIC_BIC_STATIC(VG_PATH_CAPABILITY_INTERPOLATE_TO);
    CREATE_VG_BASIC_BIC_STATIC(VG_PATH_CAPABILITY_PATH_LENGTH);
    CREATE_VG_BASIC_BIC_STATIC(VG_PATH_CAPABILITY_POINT_ALONG_PATH);
    CREATE_VG_BASIC_BIC_STATIC(VG_PATH_CAPABILITY_TANGENT_ALONG_PATH);
    CREATE_VG_BASIC_BIC_STATIC(VG_PATH_CAPABILITY_PATH_BOUNDS);
    CREATE_VG_BASIC_BIC_STATIC(VG_PATH_CAPABILITY_PATH_TRANSFORMED_BOUNDS);
    CREATE_VG_BASIC_BIC_STATIC(VG_PATH_CAPABILITY_ALL);
    CREATE_VG_BASIC_BIC_STATIC(VG_PATH_FORMAT);
    CREATE_VG_BASIC_BIC_STATIC(VG_PATH_DATATYPE);
    CREATE_VG_BASIC_BIC_STATIC(VG_PATH_SCALE);
    CREATE_VG_BASIC_BIC_STATIC(VG_PATH_BIAS);
    CREATE_VG_BASIC_BIC_STATIC(VG_PATH_NUM_SEGMENTS);
    CREATE_VG_BASIC_BIC_STATIC(VG_PATH_NUM_COORDS);
    CREATE_VG_BASIC_BIC_STATIC(VG_CAP_BUTT);
    CREATE_VG_BASIC_BIC_STATIC(VG_CAP_ROUND);
    CREATE_VG_BASIC_BIC_STATIC(VG_CAP_SQUARE);
    CREATE_VG_BASIC_BIC_STATIC(VG_JOIN_MITER);
    CREATE_VG_BASIC_BIC_STATIC(VG_JOIN_ROUND);
    CREATE_VG_BASIC_BIC_STATIC(VG_JOIN_BEVEL);
    CREATE_VG_BASIC_BIC_STATIC(VG_EVEN_ODD);
    CREATE_VG_BASIC_BIC_STATIC(VG_NON_ZERO);
    CREATE_VG_BASIC_BIC_STATIC(VG_STROKE_PATH);
    CREATE_VG_BASIC_BIC_STATIC(VG_FILL_PATH);
    CREATE_VG_BASIC_BIC_STATIC(VG_PAINT_TYPE);
    CREATE_VG_BASIC_BIC_STATIC(VG_PAINT_COLOR);
    CREATE_VG_BASIC_BIC_STATIC(VG_PAINT_COLOR_RAMP_SPREAD_MODE);
    CREATE_VG_BASIC_BIC_STATIC(VG_PAINT_COLOR_RAMP_PREMULTIPLIED);
    CREATE_VG_BASIC_BIC_STATIC(VG_PAINT_COLOR_RAMP_STOPS);
    CREATE_VG_BASIC_BIC_STATIC(VG_PAINT_LINEAR_GRADIENT);
    CREATE_VG_BASIC_BIC_STATIC(VG_PAINT_RADIAL_GRADIENT);
    CREATE_VG_BASIC_BIC_STATIC(VG_PAINT_PATTERN_TILING_MODE);
    CREATE_VG_BASIC_BIC_STATIC(VG_PAINT_TYPE_COLOR);
    CREATE_VG_BASIC_BIC_STATIC(VG_PAINT_TYPE_LINEAR_GRADIENT);
    CREATE_VG_BASIC_BIC_STATIC(VG_PAINT_TYPE_RADIAL_GRADIENT);
    CREATE_VG_BASIC_BIC_STATIC(VG_PAINT_TYPE_PATTERN);
    CREATE_VG_BASIC_BIC_STATIC(VG_COLOR_RAMP_SPREAD_PAD);
    CREATE_VG_BASIC_BIC_STATIC(VG_COLOR_RAMP_SPREAD_REPEAT);
    CREATE_VG_BASIC_BIC_STATIC(VG_COLOR_RAMP_SPREAD_REFLECT);
    CREATE_VG_BASIC_BIC_STATIC(VG_TILE_FILL);
    CREATE_VG_BASIC_BIC_STATIC(VG_TILE_PAD);
    CREATE_VG_BASIC_BIC_STATIC(VG_TILE_REPEAT);
    CREATE_VG_BASIC_BIC_STATIC(VG_TILE_REFLECT);
    CREATE_VG_BASIC_BIC_STATIC(VG_sRGBX_8888);
    CREATE_VG_BASIC_BIC_STATIC(VG_sRGBA_8888);
    CREATE_VG_BASIC_BIC_STATIC(VG_sRGBA_8888_PRE);
    CREATE_VG_BASIC_BIC_STATIC(VG_sRGB_565);
    CREATE_VG_BASIC_BIC_STATIC(VG_sRGBA_5551);
    CREATE_VG_BASIC_BIC_STATIC(VG_sRGBA_4444);
    CREATE_VG_BASIC_BIC_STATIC(VG_sL_8);
    CREATE_VG_BASIC_BIC_STATIC(VG_lRGBX_8888);
    CREATE_VG_BASIC_BIC_STATIC(VG_lRGBA_8888);
    CREATE_VG_BASIC_BIC_STATIC(VG_lRGBA_8888_PRE);
    CREATE_VG_BASIC_BIC_STATIC(VG_lL_8);
    CREATE_VG_BASIC_BIC_STATIC(VG_A_8);
    CREATE_VG_BASIC_BIC_STATIC(VG_BW_1);
    CREATE_VG_BASIC_BIC_STATIC(VG_A_1);
    CREATE_VG_BASIC_BIC_STATIC(VG_A_4);
    CREATE_VG_BASIC_BIC_STATIC(VG_sXRGB_8888);
    CREATE_VG_BASIC_BIC_STATIC(VG_sARGB_8888);
    CREATE_VG_BASIC_BIC_STATIC(VG_sARGB_8888_PRE);
    CREATE_VG_BASIC_BIC_STATIC(VG_sARGB_1555);
    CREATE_VG_BASIC_BIC_STATIC(VG_sARGB_4444);
    CREATE_VG_BASIC_BIC_STATIC(VG_lXRGB_8888);
    CREATE_VG_BASIC_BIC_STATIC(VG_lARGB_8888);
    CREATE_VG_BASIC_BIC_STATIC(VG_lARGB_8888_PRE);
    CREATE_VG_BASIC_BIC_STATIC(VG_sBGRX_8888);
    CREATE_VG_BASIC_BIC_STATIC(VG_sBGRA_8888);
    CREATE_VG_BASIC_BIC_STATIC(VG_sBGRA_8888_PRE);
    CREATE_VG_BASIC_BIC_STATIC(VG_sBGR_565);
    CREATE_VG_BASIC_BIC_STATIC(VG_sBGRA_5551);
    CREATE_VG_BASIC_BIC_STATIC(VG_sBGRA_4444);
    CREATE_VG_BASIC_BIC_STATIC(VG_lBGRX_8888);
    CREATE_VG_BASIC_BIC_STATIC(VG_lBGRA_8888);
    CREATE_VG_BASIC_BIC_STATIC(VG_lBGRA_8888_PRE);
    CREATE_VG_BASIC_BIC_STATIC(VG_sXBGR_8888);
    CREATE_VG_BASIC_BIC_STATIC(VG_sABGR_8888);
    CREATE_VG_BASIC_BIC_STATIC(VG_sABGR_8888_PRE);
    CREATE_VG_BASIC_BIC_STATIC(VG_sABGR_1555);
    CREATE_VG_BASIC_BIC_STATIC(VG_sABGR_4444);
    CREATE_VG_BASIC_BIC_STATIC(VG_lXBGR_8888);
    CREATE_VG_BASIC_BIC_STATIC(VG_lABGR_8888);
    CREATE_VG_BASIC_BIC_STATIC(VG_lABGR_8888_PRE);
    CREATE_VG_BASIC_BIC_STATIC(VG_IMAGE_QUALITY_NONANTIALIASED);
    CREATE_VG_BASIC_BIC_STATIC(VG_IMAGE_QUALITY_FASTER);
    CREATE_VG_BASIC_BIC_STATIC(VG_IMAGE_QUALITY_BETTER);
    CREATE_VG_BASIC_BIC_STATIC(VG_IMAGE_FORMAT);
    CREATE_VG_BASIC_BIC_STATIC(VG_IMAGE_WIDTH);
    CREATE_VG_BASIC_BIC_STATIC(VG_IMAGE_HEIGHT);
    CREATE_VG_BASIC_BIC_STATIC(VG_DRAW_IMAGE_NORMAL);
    CREATE_VG_BASIC_BIC_STATIC(VG_DRAW_IMAGE_MULTIPLY);
    CREATE_VG_BASIC_BIC_STATIC(VG_DRAW_IMAGE_STENCIL);
    CREATE_VG_BASIC_BIC_STATIC(VG_RED);
    CREATE_VG_BASIC_BIC_STATIC(VG_GREEN);
    CREATE_VG_BASIC_BIC_STATIC(VG_BLUE);
    CREATE_VG_BASIC_BIC_STATIC(VG_ALPHA);
    CREATE_VG_BASIC_BIC_STATIC(VG_BLEND_SRC);
    CREATE_VG_BASIC_BIC_STATIC(VG_BLEND_SRC_OVER);
    CREATE_VG_BASIC_BIC_STATIC(VG_BLEND_DST_OVER);
    CREATE_VG_BASIC_BIC_STATIC(VG_BLEND_SRC_IN);
    CREATE_VG_BASIC_BIC_STATIC(VG_BLEND_DST_IN);
    CREATE_VG_BASIC_BIC_STATIC(VG_BLEND_MULTIPLY);
    CREATE_VG_BASIC_BIC_STATIC(VG_BLEND_SCREEN);
    CREATE_VG_BASIC_BIC_STATIC(VG_BLEND_DARKEN);
    CREATE_VG_BASIC_BIC_STATIC(VG_BLEND_LIGHTEN);
    CREATE_VG_BASIC_BIC_STATIC(VG_BLEND_ADDITIVE);
    CREATE_VG_BASIC_BIC_STATIC(VG_FONT_NUM_GLYPHS);
    CREATE_VG_BASIC_BIC_STATIC(VG_IMAGE_FORMAT_QUERY);
    CREATE_VG_BASIC_BIC_STATIC(VG_PATH_DATATYPE_QUERY);
    CREATE_VG_BASIC_BIC_STATIC(VG_HARDWARE_ACCELERATED);
    CREATE_VG_BASIC_BIC_STATIC(VG_HARDWARE_UNACCELERATED);
    CREATE_VG_BASIC_BIC_STATIC(VG_VENDOR);
    CREATE_VG_BASIC_BIC_STATIC(VG_RENDERER);
    CREATE_VG_BASIC_BIC_STATIC(VG_VERSION);
    CREATE_VG_BASIC_BIC_STATIC(VG_EXTENSIONS);
  }
}/*}}}*/

void bic_vg_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_vg_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_vg_method_Clear_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);
  location_s *src_3_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_3_op_idx]);

  double x;
  double y;
  double width;
  double height;

  if (!it.retrieve_float(src_0_location,x) ||
      !it.retrieve_float(src_1_location,y) ||
      !it.retrieve_float(src_2_location,width) ||
      !it.retrieve_float(src_3_location,height))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_vg,"Clear#4");
    new_exception->params.push(4);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);
    new_exception->params.push(src_3_location->v_type);

    return false;
  }

  vgClear(x,y,width,height);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_vg_method_ClearColor_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_rm_class_vec4)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_vg,"ClearColor#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  glm::vec4 &v4 = *((glm::vec4 *)src_0_location->v_data_ptr);
  vgSetfv(VG_CLEAR_COLOR,4,glm::value_ptr(v4));

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_vg_method_StrokeLineWidth_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  double line_width;

  if (!it.retrieve_float(src_0_location,line_width))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_vg,"StrokeLineWidth#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  vgSetf(VG_STROKE_LINE_WIDTH,line_width);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_vg_method_StrokeCapStyle_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int cap_style;

  if (!it.retrieve_integer(src_0_location,cap_style))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_vg,"StrokeCapStyle#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  switch (cap_style)
  {
    case VG_CAP_BUTT:
    case VG_CAP_ROUND:
    case VG_CAP_SQUARE:
      break;

    // - ERROR -
    default:

      exception_s::throw_exception(it,module.error_base + c_error_VG_UNKNOWN_STROKE_CAP_STYLE,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
  }

  vgSeti(VG_STROKE_CAP_STYLE,cap_style);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_vg_method_StrokeJoinStyle_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int join_style;

  if (!it.retrieve_integer(src_0_location,join_style))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_vg,"StrokeJoinStyle#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  switch (join_style)
  {
    case VG_JOIN_MITER:
    case VG_JOIN_ROUND:
    case VG_JOIN_BEVEL:
      break;

    // - ERROR -
    default:

      exception_s::throw_exception(it,module.error_base + c_error_VG_UNKNOWN_STROKE_JOIN_STYLE,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
  }

  vgSeti(VG_STROKE_JOIN_STYLE,join_style);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_vg_method_StrokeDashPattern_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_array)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_vg,"StrokeDashPattern#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  pointer_array_s *array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;
  float lengths[array_ptr->used];

  if (array_ptr->used != 0)
  {
    pointer *p_ptr = array_ptr->data;
    pointer *p_ptr_end = p_ptr + array_ptr->used;
    float *f_ptr = lengths;
    do {
      location_s *item_location = it.get_location_value(*p_ptr);

      double value;

      // - ERROR -
      if (!it.retrieve_float(item_location,value))
      {
        exception_s::throw_exception(it,module.error_base + c_error_VG_WRONG_DASH_PATTERN_ARRAY_CONTENT,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      *f_ptr++ = value;
    } while(++p_ptr < p_ptr_end);
  }

  vgSetfv(VG_STROKE_DASH_PATTERN,array_ptr->used,lengths);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_vg_method_LoadIdentity_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  vgLoadIdentity();

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_vg_method_Translate_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  double x;
  double y;

  if (!it.retrieve_float(src_0_location,x) ||
      !it.retrieve_float(src_1_location,y))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_vg,"Translate#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  vgTranslate(x,y);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_vg_method_Scale_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  double x;
  double y;

  if (!it.retrieve_float(src_0_location,x) ||
      !it.retrieve_float(src_1_location,y))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_vg,"Scale#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  vgScale(x,y);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_vg_method_Shear_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  double x;
  double y;

  if (!it.retrieve_float(src_0_location,x) ||
      !it.retrieve_float(src_1_location,y))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_vg,"Shear#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  vgShear(x,y);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_vg_method_Rotate_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  double angle;

  if (!it.retrieve_float(src_0_location,angle))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_vg,"Rotate#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  vgRotate(angle);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_vg_method_Finish_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  vgFinish();

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_vg_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Vg"),"Vg");
  );

  return true;
}/*}}}*/

bool bic_vg_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("Vg");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class VG_PAINT -
built_in_class_s vg_paint_class =
{/*{{{*/
  "VgPaint",
  c_modifier_public | c_modifier_final,
  9, vg_paint_methods,
  0, vg_paint_variables,
  bic_vg_paint_consts,
  bic_vg_paint_init,
  bic_vg_paint_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s vg_paint_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_vg_paint_operator_binary_equal
  },
  {
    "VgPaint#0",
    c_modifier_public | c_modifier_final,
    bic_vg_paint_method_VgPaint_0
  },
  {
    "VgPaint#1",
    c_modifier_public | c_modifier_final,
    bic_vg_paint_method_VgPaint_1
  },
  {
    "Type#1",
    c_modifier_public | c_modifier_final,
    bic_vg_paint_method_Type_1
  },
  {
    "Color#1",
    c_modifier_public | c_modifier_final,
    bic_vg_paint_method_Color_1
  },
  {
    "Set#1",
    c_modifier_public | c_modifier_final,
    bic_vg_paint_method_Set_1
  },
  {
    "Get#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_vg_paint_method_Get_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_vg_paint_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_vg_paint_method_print_0
  },
};/*}}}*/

built_in_variable_s vg_paint_variables[] =
{/*{{{*/
};/*}}}*/

void bic_vg_paint_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_vg_paint_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (VGPaint)VG_INVALID_HANDLE;
}/*}}}*/

void bic_vg_paint_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  VGPaint paint = (VGPaint)location_ptr->v_data_ptr;

  if (paint != VG_INVALID_HANDLE)
  {
    vgDestroyPaint(paint);
  }
}/*}}}*/

bool bic_vg_paint_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_vg_paint_method_VgPaint_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  VGPaint paint = vgCreatePaint();

  dst_location->v_data_ptr = (VGPaint)paint;

  return true;
}/*}}}*/

bool bic_vg_paint_method_VgPaint_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int paint_type;

  if (!it.retrieve_integer(src_0_location,paint_type))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("VgPaint#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  switch (paint_type)
  {
    case VG_PAINT_TYPE_COLOR:
    case VG_PAINT_TYPE_LINEAR_GRADIENT:
    case VG_PAINT_TYPE_RADIAL_GRADIENT:
    case VG_PAINT_TYPE_PATTERN:
      break;

    // - ERROR -
    default:

      exception_s::throw_exception(it,module.error_base + c_error_VG_PAINT_UNKNOWN_PAINT_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
  }

  VGPaint paint = vgCreatePaint();
  vgSetParameteri(paint,VG_PAINT_TYPE,paint_type);

  dst_location->v_data_ptr = (VGPaint)paint;

  return true;
}/*}}}*/

bool bic_vg_paint_method_Type_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int paint_type;

  if (!it.retrieve_integer(src_0_location,paint_type))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Type#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  switch (paint_type)
  {
    case VG_PAINT_TYPE_COLOR:
    case VG_PAINT_TYPE_LINEAR_GRADIENT:
    case VG_PAINT_TYPE_RADIAL_GRADIENT:
    case VG_PAINT_TYPE_PATTERN:
      break;

    // - ERROR -
    default:

      exception_s::throw_exception(it,module.error_base + c_error_VG_PAINT_UNKNOWN_PAINT_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
  }

  VGPaint paint = (VGPaint)dst_location->v_data_ptr;
  vgSetParameteri(paint,VG_PAINT_TYPE,paint_type);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_vg_paint_method_Color_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_rm_class_vec4)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Color#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  VGPaint paint = (VGPaint)dst_location->v_data_ptr;
  glm::vec4 &v4 = *((glm::vec4 *)src_0_location->v_data_ptr);

  vgSetParameterfv(paint,VG_PAINT_COLOR,4,glm::value_ptr(v4));

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_vg_paint_method_Set_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int paint_modes;

  if (!it.retrieve_integer(src_0_location,paint_modes))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Set#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - ERROR -
  if (paint_modes & ~(VG_STROKE_PATH | VG_FILL_PATH))
  {
    exception_s::throw_exception(it,module.error_base + c_error_VG_PAINT_WRONG_TARGET_PAINT_MODES,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  VGPaint paint = (VGPaint)dst_location->v_data_ptr;
  vgSetPaint(paint,paint_modes);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_vg_paint_method_Get_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int paint_mode;

  if (!it.retrieve_integer(src_0_location,paint_mode))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_vg_paint,"Get#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  switch (paint_mode)
  {
    case VG_STROKE_PATH:
    case VG_FILL_PATH:
      break;

    // - ERROR -
    default:

      exception_s::throw_exception(it,module.error_base + c_error_VG_PAINT_WRONG_SOURCE_PAINT_MODE,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
  }

  VGPaint paint = vgGetPaint((VGPaintMode)paint_mode);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_vg_paint,paint);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_vg_paint_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("VgPaint"),"VgPaint");
  );

  return true;
}/*}}}*/

bool bic_vg_paint_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("VgPaint");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class VG_PATH -
built_in_class_s vg_path_class =
{/*{{{*/
  "VgPath",
  c_modifier_public | c_modifier_final,
  11, vg_path_methods,
  0, vg_path_variables,
  bic_vg_path_consts,
  bic_vg_path_init,
  bic_vg_path_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s vg_path_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_vg_path_operator_binary_equal
  },
  {
    "VgPath#0",
    c_modifier_public | c_modifier_final,
    bic_vg_path_method_VgPath_0
  },
  {
    "VgPath#2",
    c_modifier_public | c_modifier_final,
    bic_vg_path_method_VgPath_2
  },
  {
    "MoveTo#1",
    c_modifier_public | c_modifier_final,
    bic_vg_path_method_MoveTo_1
  },
  {
    "MoveTo#2",
    c_modifier_public | c_modifier_final,
    bic_vg_path_method_MoveTo_2
  },
  {
    "LineTo#1",
    c_modifier_public | c_modifier_final,
    bic_vg_path_method_LineTo_1
  },
  {
    "LineTo#2",
    c_modifier_public | c_modifier_final,
    bic_vg_path_method_LineTo_2
  },
  {
    "CloseSubpath#0",
    c_modifier_public | c_modifier_final,
    bic_vg_path_method_CloseSubpath_0
  },
  {
    "Draw#1",
    c_modifier_public | c_modifier_final,
    bic_vg_path_method_Draw_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_vg_path_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_vg_path_method_print_0
  },
};/*}}}*/

built_in_variable_s vg_path_variables[] =
{/*{{{*/
};/*}}}*/

void bic_vg_path_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_vg_path_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (VGPath)VG_INVALID_HANDLE;
}/*}}}*/

void bic_vg_path_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  VGPath path = (VGPath)location_ptr->v_data_ptr;

  if (path != VG_INVALID_HANDLE)
  {
    vgDestroyPath(path);
  }
}/*}}}*/

bool bic_vg_path_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_vg_path_method_VgPath_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  VGPath path = vgCreatePath(VG_PATH_FORMAT_STANDARD,VG_PATH_DATATYPE_F,1.0f,0.0f,0,0,VG_PATH_CAPABILITY_ALL);

  dst_location->v_data_ptr = (VGPath)path;

  return true;
}/*}}}*/

bool bic_vg_path_method_VgPath_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int segment_cap;
  long long int coordination_cap;

  if (!it.retrieve_integer(src_0_location,segment_cap) ||
      !it.retrieve_integer(src_1_location,coordination_cap))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("VgPath#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  VGPath path = vgCreatePath(VG_PATH_FORMAT_STANDARD,VG_PATH_DATATYPE_F,1.0f,0.0f,segment_cap,coordination_cap,VG_PATH_CAPABILITY_ALL);

  dst_location->v_data_ptr = (VGPath)path;

  return true;
}/*}}}*/

bool bic_vg_path_method_MoveTo_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_rm_class_vec2)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("MoveTo#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  VGPath path = (VGPath)dst_location->v_data_ptr;
  glm::vec2 &v2 = *((glm::vec2 *)src_0_location->v_data_ptr);

  VGubyte segment = VG_MOVE_TO;
  vgAppendPathData(path,1,&segment,glm::value_ptr(v2));

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_vg_path_method_MoveTo_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  double x;
  double y;

  if (!it.retrieve_float(src_0_location,x) ||
      !it.retrieve_float(src_1_location,y))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("MoveTo#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  VGPath path = (VGPath)dst_location->v_data_ptr;

  VGubyte segment = VG_MOVE_TO;
  VGfloat coords[2] = {x,y};

  vgAppendPathData(path,1,&segment,coords);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_vg_path_method_LineTo_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_rm_class_vec2)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("LineTo#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  VGPath path = (VGPath)dst_location->v_data_ptr;
  glm::vec2 &v2 = *((glm::vec2 *)src_0_location->v_data_ptr);

  VGubyte segment = VG_LINE_TO;
  vgAppendPathData(path,1,&segment,glm::value_ptr(v2));

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_vg_path_method_LineTo_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  double x;
  double y;

  if (!it.retrieve_float(src_0_location,x) ||
      !it.retrieve_float(src_1_location,y))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("LineTo#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  VGPath path = (VGPath)dst_location->v_data_ptr;

  VGubyte segment = VG_LINE_TO;
  VGfloat coords[2] = {x,y};

  vgAppendPathData(path,1,&segment,coords);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_vg_path_method_CloseSubpath_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  VGPath path = (VGPath)dst_location->v_data_ptr;

  VGubyte segment = VG_CLOSE_PATH;
  vgAppendPathData(path,1,&segment,NULL);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_vg_path_method_Draw_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int paint_modes;

  if (!it.retrieve_integer(src_0_location,paint_modes))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Draw#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - ERROR -
  if (paint_modes & ~(VG_STROKE_PATH | VG_FILL_PATH))
  {
    exception_s::throw_exception(it,module.error_base + c_error_VG_PAINT_WRONG_TARGET_PAINT_MODES,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  VGPath path = (VGPath)dst_location->v_data_ptr;
  vgDrawPath(path,paint_modes);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_vg_path_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("VgPath"),"VgPath");
  );

  return true;
}/*}}}*/

bool bic_vg_path_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("VgPath");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

