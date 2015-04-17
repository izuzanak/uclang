
@begin
include "ucl_gl.h"
@end

built_in_variable_s gl_variables[] =
{
#if defined(UCBOX_IMX6) || defined(ANDROID) || defined(NACL)
/*{{{*/
  { "GL_ES_VERSION_2_0", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_BUFFER_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_BUFFER_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_BUFFER_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FALSE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRUE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POINTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINE_LOOP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINE_STRIP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRIANGLES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRIANGLE_STRIP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRIANGLE_FAN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ZERO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ONE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SRC_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ONE_MINUS_SRC_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SRC_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ONE_MINUS_SRC_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DST_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ONE_MINUS_DST_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DST_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ONE_MINUS_DST_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SRC_ALPHA_SATURATE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FUNC_ADD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLEND_EQUATION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLEND_EQUATION_RGB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLEND_EQUATION_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FUNC_SUBTRACT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FUNC_REVERSE_SUBTRACT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLEND_DST_RGB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLEND_SRC_RGB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLEND_DST_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLEND_SRC_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONSTANT_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ONE_MINUS_CONSTANT_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONSTANT_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ONE_MINUS_CONSTANT_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLEND_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARRAY_BUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ELEMENT_ARRAY_BUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARRAY_BUFFER_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ELEMENT_ARRAY_BUFFER_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STREAM_DRAW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STATIC_DRAW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DYNAMIC_DRAW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BUFFER_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BUFFER_USAGE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_VERTEX_ATTRIB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRONT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BACK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRONT_AND_BACK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_2D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CULL_FACE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLEND", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DITHER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_TEST", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_TEST", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SCISSOR_TEST", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POLYGON_OFFSET_FILL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_ALPHA_TO_COVERAGE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_COVERAGE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NO_ERROR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INVALID_ENUM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INVALID_VALUE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INVALID_OPERATION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUT_OF_MEMORY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CCW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINE_WIDTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALIASED_POINT_SIZE_RANGE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALIASED_LINE_WIDTH_RANGE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CULL_FACE_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRONT_FACE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_RANGE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_WRITEMASK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_CLEAR_VALUE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_FUNC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_CLEAR_VALUE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_FUNC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_FAIL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_PASS_DEPTH_FAIL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_PASS_DEPTH_PASS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_REF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_VALUE_MASK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_WRITEMASK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_BACK_FUNC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_BACK_FAIL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_BACK_PASS_DEPTH_FAIL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_BACK_PASS_DEPTH_PASS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_BACK_REF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_BACK_VALUE_MASK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_BACK_WRITEMASK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIEWPORT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SCISSOR_BOX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_CLEAR_VALUE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_WRITEMASK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNPACK_ALIGNMENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PACK_ALIGNMENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TEXTURE_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VIEWPORT_DIMS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SUBPIXEL_BITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RED_BITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GREEN_BITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLUE_BITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA_BITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_BITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_BITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POLYGON_OFFSET_UNITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POLYGON_OFFSET_FACTOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BINDING_2D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_BUFFERS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_COVERAGE_VALUE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_COVERAGE_INVERT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NUM_COMPRESSED_TEXTURE_FORMATS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_TEXTURE_FORMATS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DONT_CARE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FASTEST", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NICEST", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GENERATE_MIPMAP_HINT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BYTE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_BYTE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SHORT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_SHORT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FIXED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_COMPONENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_SHORT_4_4_4_4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_SHORT_5_5_5_1", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_SHORT_5_6_5", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAGMENT_SHADER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_SHADER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VERTEX_ATTRIBS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VERTEX_UNIFORM_VECTORS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VARYING_VECTORS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TEXTURE_IMAGE_UNITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_FRAGMENT_UNIFORM_VECTORS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SHADER_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DELETE_STATUS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINK_STATUS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VALIDATE_STATUS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATTACHED_SHADERS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ACTIVE_UNIFORMS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ACTIVE_UNIFORM_MAX_LENGTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ACTIVE_ATTRIBUTES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ACTIVE_ATTRIBUTE_MAX_LENGTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SHADING_LANGUAGE_VERSION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_PROGRAM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NEVER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LESS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EQUAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LEQUAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GREATER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NOTEQUAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GEQUAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALWAYS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_KEEP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REPLACE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INCR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DECR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INVERT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INCR_WRAP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DECR_WRAP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VENDOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERSION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXTENSIONS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NEAREST", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINEAR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NEAREST_MIPMAP_NEAREST", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINEAR_MIPMAP_NEAREST", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NEAREST_MIPMAP_LINEAR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINEAR_MIPMAP_LINEAR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_MAG_FILTER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_MIN_FILTER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_WRAP_S", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_WRAP_T", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CUBE_MAP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BINDING_CUBE_MAP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CUBE_MAP_POSITIVE_X", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CUBE_MAP_NEGATIVE_X", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CUBE_MAP_POSITIVE_Y", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CUBE_MAP_NEGATIVE_Y", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CUBE_MAP_POSITIVE_Z", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CUBE_MAP_NEGATIVE_Z", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_CUBE_MAP_TEXTURE_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE0", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE1", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE5", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE6", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE7", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE9", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE10", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE11", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE12", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE13", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE14", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE15", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE16", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE17", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE18", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE19", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE20", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE21", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE22", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE23", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE24", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE25", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE26", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE27", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE28", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE29", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE30", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE31", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ACTIVE_TEXTURE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REPEAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLAMP_TO_EDGE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MIRRORED_REPEAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_VEC2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_VEC3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_VEC4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_VEC2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_VEC3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_VEC4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BOOL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BOOL_VEC2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BOOL_VEC3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BOOL_VEC4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_MAT2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_MAT3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_MAT4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_2D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_CUBE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY_ENABLED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY_STRIDE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY_NORMALIZED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY_POINTER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMPLEMENTATION_COLOR_READ_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMPLEMENTATION_COLOR_READ_FORMAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPILE_STATUS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INFO_LOG_LENGTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SHADER_SOURCE_LENGTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SHADER_COMPILER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SHADER_BINARY_FORMATS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NUM_SHADER_BINARY_FORMATS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LOW_FLOAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MEDIUM_FLOAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HIGH_FLOAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LOW_INT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MEDIUM_INT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HIGH_INT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB5_A1", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB565", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_COMPONENT16", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_INDEX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_INDEX8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER_WIDTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER_HEIGHT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER_INTERNAL_FORMAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER_RED_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER_GREEN_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER_BLUE_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER_ALPHA_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER_DEPTH_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER_STENCIL_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ATTACHMENT0", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_ATTACHMENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_ATTACHMENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NONE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_COMPLETE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_UNSUPPORTED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_RENDERBUFFER_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INVALID_FRAMEBUFFER_OPERATION", c_modifier_public | c_modifier_static | c_modifier_static_const },
/*}}}*/
#elif defined(LINUX)
/*{{{*/
  { "GL_VERSION_1_1", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERSION_1_2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERSION_1_3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_imaging", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FALSE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRUE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BYTE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_BYTE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SHORT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_SHORT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_2_BYTES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_3_BYTES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_4_BYTES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOUBLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POINTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINE_LOOP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINE_STRIP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRIANGLES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRIANGLE_STRIP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRIANGLE_FAN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_QUADS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_QUAD_STRIP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POLYGON", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NORMAL_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INDEX_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COORD_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EDGE_FLAG_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ARRAY_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ARRAY_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ARRAY_STRIDE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NORMAL_ARRAY_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NORMAL_ARRAY_STRIDE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ARRAY_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ARRAY_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ARRAY_STRIDE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INDEX_ARRAY_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INDEX_ARRAY_STRIDE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COORD_ARRAY_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COORD_ARRAY_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COORD_ARRAY_STRIDE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EDGE_FLAG_ARRAY_STRIDE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ARRAY_POINTER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NORMAL_ARRAY_POINTER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ARRAY_POINTER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INDEX_ARRAY_POINTER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COORD_ARRAY_POINTER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EDGE_FLAG_ARRAY_POINTER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_V2F", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_V3F", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_C4UB_V2F", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_C4UB_V3F", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_C3F_V3F", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_N3F_V3F", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_C4F_N3F_V3F", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_T2F_V3F", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_T4F_V4F", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_T2F_C4UB_V3F", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_T2F_C3F_V3F", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_T2F_N3F_V3F", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_T2F_C4F_N3F_V3F", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_T4F_C4F_N3F_V4F", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROJECTION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POINT_SMOOTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POINT_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POINT_SIZE_GRANULARITY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POINT_SIZE_RANGE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINE_SMOOTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINE_STIPPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINE_STIPPLE_PATTERN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINE_STIPPLE_REPEAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINE_WIDTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINE_WIDTH_GRANULARITY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINE_WIDTH_RANGE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POINT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FILL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CCW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRONT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BACK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POLYGON_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POLYGON_SMOOTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POLYGON_STIPPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EDGE_FLAG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CULL_FACE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CULL_FACE_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRONT_FACE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POLYGON_OFFSET_FACTOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POLYGON_OFFSET_UNITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POLYGON_OFFSET_POINT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POLYGON_OFFSET_LINE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POLYGON_OFFSET_FILL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPILE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPILE_AND_EXECUTE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LIST_BASE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LIST_INDEX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LIST_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NEVER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LESS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EQUAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LEQUAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GREATER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NOTEQUAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GEQUAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALWAYS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_TEST", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_BITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_CLEAR_VALUE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_FUNC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_RANGE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_WRITEMASK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_COMPONENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LIGHTING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LIGHT0", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LIGHT1", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LIGHT2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LIGHT3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LIGHT4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LIGHT5", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LIGHT6", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LIGHT7", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SPOT_EXPONENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SPOT_CUTOFF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONSTANT_ATTENUATION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINEAR_ATTENUATION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_QUADRATIC_ATTENUATION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AMBIENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DIFFUSE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SPECULAR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SHININESS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EMISSION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POSITION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SPOT_DIRECTION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AMBIENT_AND_DIFFUSE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_INDEXES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LIGHT_MODEL_TWO_SIDE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LIGHT_MODEL_LOCAL_VIEWER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LIGHT_MODEL_AMBIENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRONT_AND_BACK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SHADE_MODEL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SMOOTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_MATERIAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_MATERIAL_FACE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_MATERIAL_PARAMETER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NORMALIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLIP_PLANE0", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLIP_PLANE1", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLIP_PLANE2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLIP_PLANE3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLIP_PLANE4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLIP_PLANE5", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ACCUM_RED_BITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ACCUM_GREEN_BITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ACCUM_BLUE_BITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ACCUM_ALPHA_BITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ACCUM_CLEAR_VALUE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ACCUM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ADD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LOAD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MULT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RETURN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA_TEST", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA_TEST_REF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA_TEST_FUNC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLEND", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLEND_SRC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLEND_DST", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ZERO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ONE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SRC_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ONE_MINUS_SRC_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SRC_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ONE_MINUS_SRC_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DST_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ONE_MINUS_DST_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DST_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ONE_MINUS_DST_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SRC_ALPHA_SATURATE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FEEDBACK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SELECT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_2D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_3D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_3D_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_3D_COLOR_TEXTURE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_4D_COLOR_TEXTURE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POINT_TOKEN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINE_TOKEN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINE_RESET_TOKEN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POLYGON_TOKEN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BITMAP_TOKEN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_PIXEL_TOKEN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COPY_PIXEL_TOKEN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PASS_THROUGH_TOKEN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FEEDBACK_BUFFER_POINTER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FEEDBACK_BUFFER_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FEEDBACK_BUFFER_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SELECTION_BUFFER_POINTER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SELECTION_BUFFER_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_DENSITY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_INDEX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_START", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_END", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINEAR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXP2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LOGIC_OP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INDEX_LOGIC_OP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_LOGIC_OP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LOGIC_OP_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLEAR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COPY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COPY_INVERTED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NOOP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INVERT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AND", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NAND", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_XOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EQUIV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AND_REVERSE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AND_INVERTED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OR_REVERSE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OR_INVERTED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_BITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_TEST", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_CLEAR_VALUE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_FUNC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_VALUE_MASK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_FAIL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_PASS_DEPTH_FAIL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_PASS_DEPTH_PASS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_REF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_WRITEMASK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_INDEX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_KEEP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REPLACE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INCR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DECR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NONE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LEFT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RIGHT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRONT_LEFT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRONT_RIGHT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BACK_LEFT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BACK_RIGHT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AUX0", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AUX1", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AUX2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AUX3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_INDEX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GREEN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLUE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA_BITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RED_BITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GREEN_BITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLUE_BITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INDEX_BITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SUBPIXEL_BITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AUX_BUFFERS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_READ_BUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOUBLEBUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STEREO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BITMAP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DITHER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_LIST_NESTING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_EVAL_ORDER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_LIGHTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_CLIP_PLANES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TEXTURE_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PIXEL_MAP_TABLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_ATTRIB_STACK_DEPTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_MODELVIEW_STACK_DEPTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_NAME_STACK_DEPTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROJECTION_STACK_DEPTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TEXTURE_STACK_DEPTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VIEWPORT_DIMS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_CLIENT_ATTRIB_STACK_DEPTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATTRIB_STACK_DEPTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLIENT_ATTRIB_STACK_DEPTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_CLEAR_VALUE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_WRITEMASK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_INDEX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_NORMAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_RASTER_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_RASTER_DISTANCE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_RASTER_INDEX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_RASTER_POSITION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_RASTER_TEXTURE_COORDS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_RASTER_POSITION_VALID", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_TEXTURE_COORDS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INDEX_CLEAR_VALUE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INDEX_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INDEX_WRITEMASK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW_MATRIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW_STACK_DEPTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NAME_STACK_DEPTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROJECTION_MATRIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROJECTION_STACK_DEPTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDER_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_MATRIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_STACK_DEPTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIEWPORT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AUTO_NORMAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP1_COLOR_4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP1_INDEX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP1_NORMAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP1_TEXTURE_COORD_1", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP1_TEXTURE_COORD_2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP1_TEXTURE_COORD_3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP1_TEXTURE_COORD_4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP1_VERTEX_3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP1_VERTEX_4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP2_COLOR_4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP2_INDEX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP2_NORMAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP2_TEXTURE_COORD_1", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP2_TEXTURE_COORD_2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP2_TEXTURE_COORD_3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP2_TEXTURE_COORD_4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP2_VERTEX_3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP2_VERTEX_4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP1_GRID_DOMAIN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP1_GRID_SEGMENTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP2_GRID_DOMAIN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP2_GRID_SEGMENTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COEFF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ORDER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOMAIN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PERSPECTIVE_CORRECTION_HINT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POINT_SMOOTH_HINT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINE_SMOOTH_HINT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POLYGON_SMOOTH_HINT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_HINT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DONT_CARE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FASTEST", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NICEST", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SCISSOR_BOX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SCISSOR_TEST", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP_STENCIL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INDEX_SHIFT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INDEX_OFFSET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RED_SCALE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RED_BIAS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GREEN_SCALE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GREEN_BIAS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLUE_SCALE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLUE_BIAS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA_SCALE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA_BIAS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_SCALE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_BIAS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_MAP_S_TO_S_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_MAP_I_TO_I_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_MAP_I_TO_R_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_MAP_I_TO_G_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_MAP_I_TO_B_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_MAP_I_TO_A_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_MAP_R_TO_R_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_MAP_G_TO_G_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_MAP_B_TO_B_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_MAP_A_TO_A_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_MAP_S_TO_S", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_MAP_I_TO_I", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_MAP_I_TO_R", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_MAP_I_TO_G", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_MAP_I_TO_B", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_MAP_I_TO_A", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_MAP_R_TO_R", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_MAP_G_TO_G", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_MAP_B_TO_B", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_MAP_A_TO_A", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PACK_ALIGNMENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PACK_LSB_FIRST", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PACK_ROW_LENGTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PACK_SKIP_PIXELS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PACK_SKIP_ROWS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PACK_SWAP_BYTES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNPACK_ALIGNMENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNPACK_LSB_FIRST", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNPACK_ROW_LENGTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNPACK_SKIP_PIXELS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNPACK_SKIP_ROWS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNPACK_SWAP_BYTES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ZOOM_X", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ZOOM_Y", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_ENV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_ENV_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_1D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_2D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_WRAP_S", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_WRAP_T", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_MAG_FILTER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_MIN_FILTER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_ENV_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_GEN_S", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_GEN_T", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_GEN_R", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_GEN_Q", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_GEN_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BORDER_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_WIDTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_HEIGHT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BORDER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COMPONENTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_RED_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_GREEN_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BLUE_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_ALPHA_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_LUMINANCE_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_INTENSITY_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NEAREST_MIPMAP_NEAREST", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NEAREST_MIPMAP_LINEAR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINEAR_MIPMAP_NEAREST", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINEAR_MIPMAP_LINEAR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OBJECT_LINEAR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OBJECT_PLANE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EYE_LINEAR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EYE_PLANE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SPHERE_MAP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DECAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODULATE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NEAREST", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REPEAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLAMP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_S", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_T", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_R", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_Q", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VENDOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERSION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXTENSIONS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NO_ERROR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INVALID_ENUM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INVALID_VALUE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INVALID_OPERATION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STACK_OVERFLOW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STACK_UNDERFLOW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUT_OF_MEMORY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POINT_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINE_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POLYGON_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POLYGON_STIPPLE_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_MODE_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LIGHTING_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_BUFFER_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ACCUM_BUFFER_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_BUFFER_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIEWPORT_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ENABLE_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_BUFFER_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HINT_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EVAL_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LIST_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SCISSOR_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALL_ATTRIB_BITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROXY_TEXTURE_1D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROXY_TEXTURE_2D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_PRIORITY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_RESIDENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BINDING_1D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BINDING_2D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_INTERNAL_FORMAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA12", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA16", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE12", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE16", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE4_ALPHA4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE6_ALPHA2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE8_ALPHA8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE12_ALPHA4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE12_ALPHA12", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE16_ALPHA16", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTENSITY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTENSITY4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTENSITY8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTENSITY12", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTENSITY16", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_R3_G3_B2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB5", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB10", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB12", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB16", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB5_A1", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB10_A2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA12", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA16", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLIENT_PIXEL_STORE_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLIENT_VERTEX_ARRAY_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALL_CLIENT_ATTRIB_BITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLIENT_ALL_ATTRIB_BITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RESCALE_NORMAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLAMP_TO_EDGE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_ELEMENTS_VERTICES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_ELEMENTS_INDICES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BGR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BGRA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_BYTE_3_3_2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_BYTE_2_3_3_REV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_SHORT_5_6_5", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_SHORT_5_6_5_REV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_SHORT_4_4_4_4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_SHORT_4_4_4_4_REV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_SHORT_5_5_5_1", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_SHORT_1_5_5_5_REV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_8_8_8_8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_8_8_8_8_REV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_10_10_10_2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_2_10_10_10_REV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LIGHT_MODEL_COLOR_CONTROL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SINGLE_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SEPARATE_SPECULAR_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_MIN_LOD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_MAX_LOD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BASE_LEVEL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_MAX_LEVEL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SMOOTH_POINT_SIZE_RANGE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SMOOTH_POINT_SIZE_GRANULARITY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SMOOTH_LINE_WIDTH_RANGE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SMOOTH_LINE_WIDTH_GRANULARITY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALIASED_POINT_SIZE_RANGE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALIASED_LINE_WIDTH_RANGE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PACK_SKIP_IMAGES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PACK_IMAGE_HEIGHT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNPACK_SKIP_IMAGES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNPACK_IMAGE_HEIGHT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_3D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROXY_TEXTURE_3D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_DEPTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_WRAP_R", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_3D_TEXTURE_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BINDING_3D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONSTANT_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ONE_MINUS_CONSTANT_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONSTANT_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ONE_MINUS_CONSTANT_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_TABLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_CONVOLUTION_COLOR_TABLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_COLOR_MATRIX_COLOR_TABLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROXY_COLOR_TABLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROXY_POST_CONVOLUTION_COLOR_TABLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_TABLE_SCALE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_TABLE_BIAS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_TABLE_FORMAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_TABLE_WIDTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_TABLE_RED_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_TABLE_GREEN_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_TABLE_BLUE_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_TABLE_ALPHA_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_TABLE_LUMINANCE_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_TABLE_INTENSITY_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONVOLUTION_1D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONVOLUTION_2D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SEPARABLE_2D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONVOLUTION_BORDER_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONVOLUTION_FILTER_SCALE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONVOLUTION_FILTER_BIAS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REDUCE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONVOLUTION_FORMAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONVOLUTION_WIDTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONVOLUTION_HEIGHT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_CONVOLUTION_WIDTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_CONVOLUTION_HEIGHT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_CONVOLUTION_RED_SCALE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_CONVOLUTION_GREEN_SCALE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_CONVOLUTION_BLUE_SCALE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_CONVOLUTION_ALPHA_SCALE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_CONVOLUTION_RED_BIAS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_CONVOLUTION_GREEN_BIAS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_CONVOLUTION_BLUE_BIAS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_CONVOLUTION_ALPHA_BIAS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONSTANT_BORDER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REPLICATE_BORDER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONVOLUTION_BORDER_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_MATRIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_MATRIX_STACK_DEPTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_COLOR_MATRIX_STACK_DEPTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_COLOR_MATRIX_RED_SCALE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_COLOR_MATRIX_GREEN_SCALE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_COLOR_MATRIX_BLUE_SCALE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_COLOR_MATRIX_ALPHA_SCALE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_COLOR_MATRIX_RED_BIAS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_COLOR_MATRIX_GREEN_BIAS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_COLOR_MATRIX_BLUE_BIAS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_COLOR_MATRIX_ALPHA_BIAS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HISTOGRAM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROXY_HISTOGRAM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HISTOGRAM_WIDTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HISTOGRAM_FORMAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HISTOGRAM_RED_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HISTOGRAM_GREEN_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HISTOGRAM_BLUE_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HISTOGRAM_ALPHA_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HISTOGRAM_LUMINANCE_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HISTOGRAM_SINK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MINMAX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MINMAX_FORMAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MINMAX_SINK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TABLE_TOO_LARGE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLEND_EQUATION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MIN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FUNC_ADD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FUNC_SUBTRACT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FUNC_REVERSE_SUBTRACT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLEND_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE0", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE1", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE5", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE6", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE7", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE9", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE10", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE11", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE12", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE13", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE14", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE15", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE16", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE17", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE18", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE19", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE20", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE21", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE22", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE23", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE24", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE25", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE26", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE27", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE28", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE29", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE30", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE31", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ACTIVE_TEXTURE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLIENT_ACTIVE_TEXTURE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TEXTURE_UNITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NORMAL_MAP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REFLECTION_MAP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CUBE_MAP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BINDING_CUBE_MAP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CUBE_MAP_POSITIVE_X", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CUBE_MAP_NEGATIVE_X", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CUBE_MAP_POSITIVE_Y", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CUBE_MAP_NEGATIVE_Y", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CUBE_MAP_POSITIVE_Z", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CUBE_MAP_NEGATIVE_Z", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROXY_TEXTURE_CUBE_MAP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_CUBE_MAP_TEXTURE_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_LUMINANCE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_LUMINANCE_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_INTENSITY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_RGB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_RGBA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COMPRESSION_HINT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COMPRESSED_IMAGE_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COMPRESSED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NUM_COMPRESSED_TEXTURE_FORMATS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_TEXTURE_FORMATS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MULTISAMPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_ALPHA_TO_COVERAGE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_ALPHA_TO_ONE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_COVERAGE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_BUFFERS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_COVERAGE_VALUE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_COVERAGE_INVERT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MULTISAMPLE_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSPOSE_MODELVIEW_MATRIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSPOSE_PROJECTION_MATRIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSPOSE_TEXTURE_MATRIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSPOSE_COLOR_MATRIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMBINE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMBINE_RGB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMBINE_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SOURCE0_RGB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SOURCE1_RGB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SOURCE2_RGB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SOURCE0_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SOURCE1_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SOURCE2_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OPERAND0_RGB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OPERAND1_RGB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OPERAND2_RGB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OPERAND0_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OPERAND1_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OPERAND2_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB_SCALE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ADD_SIGNED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTERPOLATE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SUBTRACT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONSTANT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PRIMARY_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PREVIOUS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOT3_RGB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOT3_RGBA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLAMP_TO_BORDER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_multitexture", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE0_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE1_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE2_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE3_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE4_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE5_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE6_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE7_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE8_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE9_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE10_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE11_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE12_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE13_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE14_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE15_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE16_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE17_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE18_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE19_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE20_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE21_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE22_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE23_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE24_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE25_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE26_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE27_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE28_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE29_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE30_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE31_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ACTIVE_TEXTURE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLIENT_ACTIVE_TEXTURE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TEXTURE_UNITS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MESA_packed_depth_stencil", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_STENCIL_MESA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_24_8_MESA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_8_24_REV_MESA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_SHORT_15_1_MESA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_SHORT_1_15_REV_MESA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_1D_ARRAY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROXY_TEXTURE_1D_ARRAY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_2D_ARRAY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROXY_TEXTURE_2D_ARRAY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BINDING_1D_ARRAY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BINDING_2D_ARRAY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_ARRAY_TEXTURE_LAYERS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATI_blend_equation_separate", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA_BLEND_EQUATION_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OES_EGL_image", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GLEXT_VERSION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERSION_1_4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLEND_DST_RGB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLEND_SRC_RGB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLEND_DST_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLEND_SRC_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POINT_FADE_THRESHOLD_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_COMPONENT16", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_COMPONENT24", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_COMPONENT32", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MIRRORED_REPEAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TEXTURE_LOD_BIAS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_LOD_BIAS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INCR_WRAP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DECR_WRAP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_DEPTH_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COMPARE_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COMPARE_FUNC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POINT_SIZE_MIN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POINT_SIZE_MAX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POINT_DISTANCE_ATTENUATION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GENERATE_MIPMAP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GENERATE_MIPMAP_HINT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_COORDINATE_SOURCE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_COORDINATE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAGMENT_DEPTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_FOG_COORDINATE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_COORDINATE_ARRAY_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_COORDINATE_ARRAY_STRIDE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_COORDINATE_ARRAY_POINTER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_COORDINATE_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_SUM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_SECONDARY_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SECONDARY_COLOR_ARRAY_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SECONDARY_COLOR_ARRAY_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SECONDARY_COLOR_ARRAY_STRIDE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SECONDARY_COLOR_ARRAY_POINTER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SECONDARY_COLOR_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_FILTER_CONTROL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_TEXTURE_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPARE_R_TO_TEXTURE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERSION_1_5", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BUFFER_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BUFFER_USAGE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_QUERY_COUNTER_BITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_QUERY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_QUERY_RESULT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_QUERY_RESULT_AVAILABLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARRAY_BUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ELEMENT_ARRAY_BUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARRAY_BUFFER_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ELEMENT_ARRAY_BUFFER_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_READ_ONLY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_WRITE_ONLY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_READ_WRITE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BUFFER_ACCESS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BUFFER_MAPPED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BUFFER_MAP_POINTER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STREAM_DRAW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STREAM_READ", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STREAM_COPY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STATIC_DRAW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STATIC_READ", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STATIC_COPY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DYNAMIC_DRAW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DYNAMIC_READ", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DYNAMIC_COPY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLES_PASSED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SRC1_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ARRAY_BUFFER_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NORMAL_ARRAY_BUFFER_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ARRAY_BUFFER_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INDEX_ARRAY_BUFFER_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EDGE_FLAG_ARRAY_BUFFER_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_WEIGHT_ARRAY_BUFFER_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_COORD_SRC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_COORD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_FOG_COORD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_COORD_ARRAY_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_COORD_ARRAY_STRIDE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_COORD_ARRAY_POINTER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_COORD_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_COORD_ARRAY_BUFFER_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SRC0_RGB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SRC1_RGB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SRC2_RGB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SRC0_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SRC2_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERSION_2_0", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLEND_EQUATION_RGB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY_ENABLED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY_STRIDE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_VERTEX_ATTRIB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_PROGRAM_POINT_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY_POINTER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_BACK_FUNC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_BACK_FAIL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_BACK_PASS_DEPTH_FAIL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_BACK_PASS_DEPTH_PASS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_DRAW_BUFFERS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER0", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER1", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER5", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER6", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER7", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER9", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER10", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER11", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER12", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER13", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER14", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER15", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLEND_EQUATION_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VERTEX_ATTRIBS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY_NORMALIZED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TEXTURE_IMAGE_UNITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAGMENT_SHADER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_SHADER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_FRAGMENT_UNIFORM_COMPONENTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VERTEX_UNIFORM_COMPONENTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VARYING_FLOATS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SHADER_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_VEC2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_VEC3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_VEC4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_VEC2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_VEC3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_VEC4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BOOL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BOOL_VEC2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BOOL_VEC3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BOOL_VEC4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_MAT2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_MAT3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_MAT4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_1D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_2D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_3D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_CUBE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_1D_SHADOW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_2D_SHADOW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DELETE_STATUS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPILE_STATUS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINK_STATUS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VALIDATE_STATUS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INFO_LOG_LENGTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATTACHED_SHADERS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ACTIVE_UNIFORMS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ACTIVE_UNIFORM_MAX_LENGTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SHADER_SOURCE_LENGTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ACTIVE_ATTRIBUTES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ACTIVE_ATTRIBUTE_MAX_LENGTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAGMENT_SHADER_DERIVATIVE_HINT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SHADING_LANGUAGE_VERSION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_PROGRAM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POINT_SPRITE_COORD_ORIGIN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LOWER_LEFT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UPPER_LEFT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_BACK_REF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_BACK_VALUE_MASK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_BACK_WRITEMASK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_PROGRAM_TWO_SIDE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POINT_SPRITE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COORD_REPLACE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TEXTURE_COORDS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERSION_2_1", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_PACK_BUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_UNPACK_BUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_PACK_BUFFER_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_UNPACK_BUFFER_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_MAT2x3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_MAT2x4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_MAT3x2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_MAT3x4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_MAT4x2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_MAT4x3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SRGB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SRGB8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SRGB_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SRGB8_ALPHA8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SRGB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SRGB_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_RASTER_SECONDARY_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SLUMINANCE_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SLUMINANCE8_ALPHA8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SLUMINANCE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SLUMINANCE8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SLUMINANCE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SLUMINANCE_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERSION_3_0", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPARE_REF_TO_TEXTURE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLIP_DISTANCE0", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLIP_DISTANCE1", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLIP_DISTANCE2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLIP_DISTANCE3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLIP_DISTANCE4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLIP_DISTANCE5", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLIP_DISTANCE6", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLIP_DISTANCE7", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_CLIP_DISTANCES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAJOR_VERSION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MINOR_VERSION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NUM_EXTENSIONS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONTEXT_FLAGS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_RED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_RG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA32F", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB32F", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA16F", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB16F", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY_INTEGER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_ARRAY_TEXTURE_LAYERS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MIN_PROGRAM_TEXEL_OFFSET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_TEXEL_OFFSET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLAMP_READ_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FIXED_ONLY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VARYING_COMPONENTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_1D_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROXY_TEXTURE_1D_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_2D_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROXY_TEXTURE_2D_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BINDING_1D_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BINDING_2D_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_R11F_G11F_B10F", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_10F_11F_11F_REV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB9_E5", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_5_9_9_9_REV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_SHARED_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK_BUFFER_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK_VARYINGS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK_BUFFER_START", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK_BUFFER_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PRIMITIVES_GENERATED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RASTERIZER_DISCARD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTERLEAVED_ATTRIBS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SEPARATE_ATTRIBS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK_BUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK_BUFFER_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA32UI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB32UI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA16UI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB16UI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA8UI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB8UI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA32I", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB32I", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA16I", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB16I", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA8I", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB8I", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RED_INTEGER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GREEN_INTEGER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLUE_INTEGER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB_INTEGER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA_INTEGER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BGR_INTEGER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BGRA_INTEGER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_1D_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_2D_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_1D_ARRAY_SHADOW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_2D_ARRAY_SHADOW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_CUBE_SHADOW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_VEC2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_VEC3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_VEC4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_SAMPLER_1D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_SAMPLER_2D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_SAMPLER_3D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_SAMPLER_CUBE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_SAMPLER_1D_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_SAMPLER_2D_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_SAMPLER_1D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_SAMPLER_2D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_SAMPLER_3D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_SAMPLER_CUBE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_SAMPLER_1D_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_SAMPLER_2D_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_QUERY_WAIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_QUERY_NO_WAIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_QUERY_BY_REGION_WAIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_QUERY_BY_REGION_NO_WAIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BUFFER_ACCESS_FLAGS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BUFFER_MAP_LENGTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BUFFER_MAP_OFFSET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_COMPONENT32F", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH32F_STENCIL8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_32_UNSIGNED_INT_24_8_REV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INVALID_FRAMEBUFFER_OPERATION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_DEFAULT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_UNDEFINED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_STENCIL_ATTACHMENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_RENDERBUFFER_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_STENCIL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_24_8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH24_STENCIL8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_STENCIL_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_RED_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_GREEN_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BLUE_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_ALPHA_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_DEPTH_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_NORMALIZED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_FRAMEBUFFER_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_READ_FRAMEBUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_FRAMEBUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_READ_FRAMEBUFFER_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER_SAMPLES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_COMPLETE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_UNSUPPORTED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_COLOR_ATTACHMENTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ATTACHMENT0", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ATTACHMENT1", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ATTACHMENT2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ATTACHMENT3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ATTACHMENT4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ATTACHMENT5", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ATTACHMENT6", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ATTACHMENT7", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ATTACHMENT8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ATTACHMENT9", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ATTACHMENT10", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ATTACHMENT11", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ATTACHMENT12", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ATTACHMENT13", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ATTACHMENT14", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ATTACHMENT15", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_ATTACHMENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_ATTACHMENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER_WIDTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER_HEIGHT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER_INTERNAL_FORMAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_INDEX1", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_INDEX4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_INDEX8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_INDEX16", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER_RED_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER_GREEN_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER_BLUE_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER_ALPHA_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER_DEPTH_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER_STENCIL_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_SAMPLES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INDEX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_LUMINANCE_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_INTENSITY_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_SRGB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HALF_FLOAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP_READ_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP_WRITE_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP_INVALIDATE_RANGE_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP_INVALIDATE_BUFFER_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP_FLUSH_EXPLICIT_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP_UNSYNCHRONIZED_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_RED_RGTC1", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SIGNED_RED_RGTC1", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_RG_RGTC2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SIGNED_RG_RGTC2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RG_INTEGER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_R8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_R16", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RG8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RG16", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_R16F", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_R32F", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RG16F", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RG32F", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_R8I", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_R8UI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_R16I", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_R16UI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_R32I", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_R32UI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RG8I", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RG8UI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RG16I", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RG16UI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RG32I", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RG32UI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ARRAY_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLAMP_VERTEX_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLAMP_FRAGMENT_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA_INTEGER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERSION_3_1", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_2D_RECT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_2D_RECT_SHADOW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_BUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_SAMPLER_2D_RECT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_SAMPLER_BUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_SAMPLER_2D_RECT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_SAMPLER_BUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TEXTURE_BUFFER_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BINDING_BUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BUFFER_DATA_STORE_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_RECTANGLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BINDING_RECTANGLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROXY_TEXTURE_RECTANGLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_RECTANGLE_TEXTURE_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_R8_SNORM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RG8_SNORM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB8_SNORM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA8_SNORM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_R16_SNORM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RG16_SNORM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB16_SNORM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA16_SNORM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SIGNED_NORMALIZED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PRIMITIVE_RESTART", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PRIMITIVE_RESTART_INDEX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COPY_READ_BUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COPY_WRITE_BUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNIFORM_BUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNIFORM_BUFFER_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNIFORM_BUFFER_START", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNIFORM_BUFFER_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VERTEX_UNIFORM_BLOCKS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_FRAGMENT_UNIFORM_BLOCKS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_COMBINED_UNIFORM_BLOCKS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_UNIFORM_BUFFER_BINDINGS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_UNIFORM_BLOCK_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ACTIVE_UNIFORM_BLOCKS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNIFORM_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNIFORM_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNIFORM_NAME_LENGTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNIFORM_BLOCK_INDEX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNIFORM_OFFSET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNIFORM_ARRAY_STRIDE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNIFORM_MATRIX_STRIDE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNIFORM_IS_ROW_MAJOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNIFORM_BLOCK_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNIFORM_BLOCK_DATA_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNIFORM_BLOCK_NAME_LENGTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INVALID_INDEX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERSION_3_2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONTEXT_CORE_PROFILE_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONTEXT_COMPATIBILITY_PROFILE_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINES_ADJACENCY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINE_STRIP_ADJACENCY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRIANGLES_ADJACENCY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRIANGLE_STRIP_ADJACENCY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_POINT_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_ATTACHMENT_LAYERED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GEOMETRY_SHADER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GEOMETRY_VERTICES_OUT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GEOMETRY_INPUT_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GEOMETRY_OUTPUT_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_GEOMETRY_UNIFORM_COMPONENTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_GEOMETRY_OUTPUT_VERTICES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VERTEX_OUTPUT_COMPONENTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_GEOMETRY_INPUT_COMPONENTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_GEOMETRY_OUTPUT_COMPONENTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_FRAGMENT_INPUT_COMPONENTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONTEXT_PROFILE_MASK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_CLAMP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FIRST_VERTEX_CONVENTION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LAST_VERTEX_CONVENTION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROVOKING_VERTEX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CUBE_MAP_SEAMLESS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_SERVER_WAIT_TIMEOUT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OBJECT_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SYNC_CONDITION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SYNC_STATUS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SYNC_FLAGS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SYNC_FENCE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SYNC_GPU_COMMANDS_COMPLETE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNALED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SIGNALED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALREADY_SIGNALED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TIMEOUT_EXPIRED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONDITION_SATISFIED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_WAIT_FAILED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TIMEOUT_IGNORED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SYNC_FLUSH_COMMANDS_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_POSITION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_MASK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_MASK_VALUE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_SAMPLE_MASK_WORDS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_2D_MULTISAMPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROXY_TEXTURE_2D_MULTISAMPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_2D_MULTISAMPLE_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BINDING_2D_MULTISAMPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_SAMPLES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_FIXED_SAMPLE_LOCATIONS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_2D_MULTISAMPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_SAMPLER_2D_MULTISAMPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_2D_MULTISAMPLE_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_COLOR_TEXTURE_SAMPLES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_DEPTH_TEXTURE_SAMPLES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_INTEGER_SAMPLES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERSION_3_3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY_DIVISOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SRC1_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ONE_MINUS_SRC1_COLOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ONE_MINUS_SRC1_ALPHA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_DUAL_SOURCE_DRAW_BUFFERS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ANY_SAMPLES_PASSED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB10_A2UI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_SWIZZLE_R", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_SWIZZLE_G", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_SWIZZLE_B", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_SWIZZLE_A", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_SWIZZLE_RGBA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TIME_ELAPSED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TIMESTAMP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_2_10_10_10_REV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERSION_4_0", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_SHADING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MIN_SAMPLE_SHADING_VALUE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CUBE_MAP_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BINDING_CUBE_MAP_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROXY_TEXTURE_CUBE_MAP_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_CUBE_MAP_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_SAMPLER_CUBE_MAP_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_INDIRECT_BUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_INDIRECT_BUFFER_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GEOMETRY_SHADER_INVOCATIONS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_GEOMETRY_SHADER_INVOCATIONS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MIN_FRAGMENT_INTERPOLATION_OFFSET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_FRAGMENT_INTERPOLATION_OFFSET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAGMENT_INTERPOLATION_OFFSET_BITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VERTEX_STREAMS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOUBLE_VEC2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOUBLE_VEC3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOUBLE_VEC4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOUBLE_MAT2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOUBLE_MAT3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOUBLE_MAT4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOUBLE_MAT2x3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOUBLE_MAT2x4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOUBLE_MAT3x2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOUBLE_MAT3x4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOUBLE_MAT4x2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOUBLE_MAT4x3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ACTIVE_SUBROUTINES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ACTIVE_SUBROUTINE_UNIFORMS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ACTIVE_SUBROUTINE_MAX_LENGTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_SUBROUTINES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NUM_COMPATIBLE_SUBROUTINES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPATIBLE_SUBROUTINES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATCHES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATCH_VERTICES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATCH_DEFAULT_INNER_LEVEL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATCH_DEFAULT_OUTER_LEVEL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TESS_CONTROL_OUTPUT_VERTICES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TESS_GEN_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TESS_GEN_SPACING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TESS_GEN_VERTEX_ORDER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TESS_GEN_POINT_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ISOLINES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRACTIONAL_ODD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRACTIONAL_EVEN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PATCH_VERTICES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TESS_GEN_LEVEL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TESS_PATCH_COMPONENTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TESS_CONTROL_INPUT_COMPONENTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TESS_EVALUATION_SHADER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TESS_CONTROL_SHADER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TRANSFORM_FEEDBACK_BUFFERS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERSION_4_1", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FIXED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMPLEMENTATION_COLOR_READ_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMPLEMENTATION_COLOR_READ_FORMAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LOW_FLOAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MEDIUM_FLOAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HIGH_FLOAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LOW_INT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MEDIUM_INT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HIGH_INT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SHADER_COMPILER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SHADER_BINARY_FORMATS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NUM_SHADER_BINARY_FORMATS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VERTEX_UNIFORM_VECTORS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VARYING_VECTORS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_FRAGMENT_UNIFORM_VECTORS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB565", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_BINARY_RETRIEVABLE_HINT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_BINARY_LENGTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NUM_PROGRAM_BINARY_FORMATS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_BINARY_FORMATS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_SHADER_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAGMENT_SHADER_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GEOMETRY_SHADER_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TESS_CONTROL_SHADER_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TESS_EVALUATION_SHADER_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALL_SHADER_BITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_SEPARABLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ACTIVE_PROGRAM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_PIPELINE_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VIEWPORTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIEWPORT_SUBPIXEL_BITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIEWPORT_BOUNDS_RANGE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LAYER_PROVOKING_VERTEX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIEWPORT_INDEX_PROVOKING_VERTEX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNDEFINED_VERTEX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERSION_4_2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNPACK_COMPRESSED_BLOCK_WIDTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNPACK_COMPRESSED_BLOCK_HEIGHT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNPACK_COMPRESSED_BLOCK_DEPTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNPACK_COMPRESSED_BLOCK_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PACK_COMPRESSED_BLOCK_WIDTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PACK_COMPRESSED_BLOCK_HEIGHT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PACK_COMPRESSED_BLOCK_DEPTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PACK_COMPRESSED_BLOCK_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NUM_SAMPLE_COUNTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MIN_MAP_BUFFER_ALIGNMENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATOMIC_COUNTER_BUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATOMIC_COUNTER_BUFFER_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATOMIC_COUNTER_BUFFER_START", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATOMIC_COUNTER_BUFFER_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VERTEX_ATOMIC_COUNTERS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_GEOMETRY_ATOMIC_COUNTERS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_FRAGMENT_ATOMIC_COUNTERS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_COMBINED_ATOMIC_COUNTERS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ACTIVE_ATOMIC_COUNTER_BUFFERS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_ATOMIC_COUNTER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ELEMENT_ARRAY_BARRIER_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNIFORM_BARRIER_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_FETCH_BARRIER_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SHADER_IMAGE_ACCESS_BARRIER_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMMAND_BARRIER_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_BUFFER_BARRIER_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_UPDATE_BARRIER_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BUFFER_UPDATE_BARRIER_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_BARRIER_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK_BARRIER_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATOMIC_COUNTER_BARRIER_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALL_BARRIER_BITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_IMAGE_UNITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_BINDING_NAME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_BINDING_LEVEL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_BINDING_LAYERED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_BINDING_LAYER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_BINDING_ACCESS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_1D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_2D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_3D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_2D_RECT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_CUBE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_BUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_1D_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_2D_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_CUBE_MAP_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_2D_MULTISAMPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_2D_MULTISAMPLE_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_IMAGE_1D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_IMAGE_2D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_IMAGE_3D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_IMAGE_2D_RECT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_IMAGE_CUBE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_IMAGE_BUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_IMAGE_1D_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_IMAGE_2D_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_IMAGE_CUBE_MAP_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_IMAGE_2D_MULTISAMPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_IMAGE_1D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_IMAGE_2D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_IMAGE_3D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_IMAGE_2D_RECT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_IMAGE_CUBE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_IMAGE_BUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_IMAGE_1D_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_IMAGE_2D_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_IMAGE_SAMPLES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_BINDING_FORMAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_FORMAT_COMPATIBILITY_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VERTEX_IMAGE_UNIFORMS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_GEOMETRY_IMAGE_UNIFORMS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_FRAGMENT_IMAGE_UNIFORMS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_COMBINED_IMAGE_UNIFORMS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_IMMUTABLE_FORMAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERSION_4_3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NUM_SHADING_LANGUAGE_VERSIONS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY_LONG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_RGB8_ETC2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SRGB8_ETC2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_RGBA8_ETC2_EAC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_R11_EAC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SIGNED_R11_EAC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_RG11_EAC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SIGNED_RG11_EAC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PRIMITIVE_RESTART_FIXED_INDEX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ANY_SAMPLES_PASSED_CONSERVATIVE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_ELEMENT_INDEX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPUTE_SHADER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_COMPUTE_UNIFORM_BLOCKS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_COMPUTE_IMAGE_UNIFORMS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_COMPUTE_SHARED_MEMORY_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_COMPUTE_UNIFORM_COMPONENTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_COMPUTE_ATOMIC_COUNTERS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_COMPUTE_WORK_GROUP_COUNT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_COMPUTE_WORK_GROUP_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DISPATCH_INDIRECT_BUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DISPATCH_INDIRECT_BUFFER_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_OUTPUT_SYNCHRONOUS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_CALLBACK_FUNCTION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_CALLBACK_USER_PARAM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_SOURCE_API", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_SOURCE_WINDOW_SYSTEM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_SOURCE_SHADER_COMPILER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_SOURCE_THIRD_PARTY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_SOURCE_APPLICATION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_SOURCE_OTHER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_TYPE_ERROR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_TYPE_PORTABILITY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_TYPE_PERFORMANCE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_TYPE_OTHER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_DEBUG_MESSAGE_LENGTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_DEBUG_LOGGED_MESSAGES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_LOGGED_MESSAGES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_SEVERITY_HIGH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_SEVERITY_MEDIUM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_SEVERITY_LOW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_TYPE_MARKER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_TYPE_PUSH_GROUP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_TYPE_POP_GROUP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_SEVERITY_NOTIFICATION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_DEBUG_GROUP_STACK_DEPTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_GROUP_STACK_DEPTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SHADER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_QUERY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_PIPELINE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_LABEL_LENGTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_OUTPUT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONTEXT_FLAG_DEBUG_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_UNIFORM_LOCATIONS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_DEFAULT_WIDTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_DEFAULT_HEIGHT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_DEFAULT_LAYERS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_DEFAULT_SAMPLES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_FRAMEBUFFER_WIDTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_FRAMEBUFFER_HEIGHT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_FRAMEBUFFER_LAYERS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_FRAMEBUFFER_SAMPLES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTERNALFORMAT_SUPPORTED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTERNALFORMAT_PREFERRED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTERNALFORMAT_RED_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTERNALFORMAT_GREEN_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTERNALFORMAT_BLUE_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTERNALFORMAT_ALPHA_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTERNALFORMAT_DEPTH_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTERNALFORMAT_STENCIL_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTERNALFORMAT_SHARED_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTERNALFORMAT_RED_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTERNALFORMAT_GREEN_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTERNALFORMAT_BLUE_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTERNALFORMAT_ALPHA_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTERNALFORMAT_DEPTH_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTERNALFORMAT_STENCIL_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_WIDTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_HEIGHT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_DEPTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_LAYERS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_COMBINED_DIMENSIONS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_COMPONENTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_COMPONENTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_COMPONENTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_RENDERABLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_RENDERABLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_RENDERABLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_RENDERABLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_RENDERABLE_LAYERED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_BLEND", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_READ_PIXELS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_READ_PIXELS_FORMAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_READ_PIXELS_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_IMAGE_FORMAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_IMAGE_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GET_TEXTURE_IMAGE_FORMAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GET_TEXTURE_IMAGE_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MIPMAP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MANUAL_GENERATE_MIPMAP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AUTO_GENERATE_MIPMAP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ENCODING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SRGB_READ", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SRGB_WRITE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FILTER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_TEXTURE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TESS_CONTROL_TEXTURE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TESS_EVALUATION_TEXTURE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GEOMETRY_TEXTURE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAGMENT_TEXTURE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPUTE_TEXTURE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_SHADOW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_GATHER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_GATHER_SHADOW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SHADER_IMAGE_LOAD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SHADER_IMAGE_STORE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SHADER_IMAGE_ATOMIC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_TEXEL_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_COMPATIBILITY_CLASS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_PIXEL_FORMAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_PIXEL_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COMPRESSED_BLOCK_WIDTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COMPRESSED_BLOCK_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLEAR_BUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_VIEW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIEW_COMPATIBILITY_CLASS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FULL_SUPPORT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CAVEAT_SUPPORT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_CLASS_4_X_32", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_CLASS_2_X_32", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_CLASS_1_X_32", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_CLASS_4_X_16", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_CLASS_2_X_16", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_CLASS_1_X_16", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_CLASS_4_X_8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_CLASS_2_X_8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_CLASS_1_X_8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_CLASS_11_11_10", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_CLASS_10_10_10_2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIEW_CLASS_128_BITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIEW_CLASS_96_BITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIEW_CLASS_64_BITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIEW_CLASS_48_BITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIEW_CLASS_32_BITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIEW_CLASS_24_BITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIEW_CLASS_16_BITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIEW_CLASS_8_BITS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIEW_CLASS_S3TC_DXT1_RGB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIEW_CLASS_S3TC_DXT1_RGBA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIEW_CLASS_S3TC_DXT3_RGBA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIEW_CLASS_S3TC_DXT5_RGBA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIEW_CLASS_RGTC1_RED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIEW_CLASS_RGTC2_RG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIEW_CLASS_BPTC_UNORM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIEW_CLASS_BPTC_FLOAT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNIFORM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNIFORM_BLOCK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_INPUT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_OUTPUT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BUFFER_VARIABLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SHADER_STORAGE_BLOCK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_SUBROUTINE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TESS_CONTROL_SUBROUTINE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TESS_EVALUATION_SUBROUTINE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GEOMETRY_SUBROUTINE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAGMENT_SUBROUTINE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPUTE_SUBROUTINE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_SUBROUTINE_UNIFORM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TESS_CONTROL_SUBROUTINE_UNIFORM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TESS_EVALUATION_SUBROUTINE_UNIFORM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GEOMETRY_SUBROUTINE_UNIFORM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAGMENT_SUBROUTINE_UNIFORM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPUTE_SUBROUTINE_UNIFORM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK_VARYING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ACTIVE_RESOURCES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_NAME_LENGTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_NUM_ACTIVE_VARIABLES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_NUM_COMPATIBLE_SUBROUTINES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NAME_LENGTH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARRAY_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OFFSET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLOCK_INDEX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARRAY_STRIDE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX_STRIDE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IS_ROW_MAJOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATOMIC_COUNTER_BUFFER_INDEX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BUFFER_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BUFFER_DATA_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NUM_ACTIVE_VARIABLES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ACTIVE_VARIABLES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REFERENCED_BY_VERTEX_SHADER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REFERENCED_BY_TESS_CONTROL_SHADER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REFERENCED_BY_TESS_EVALUATION_SHADER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REFERENCED_BY_GEOMETRY_SHADER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REFERENCED_BY_FRAGMENT_SHADER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REFERENCED_BY_COMPUTE_SHADER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TOP_LEVEL_ARRAY_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TOP_LEVEL_ARRAY_STRIDE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LOCATION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LOCATION_INDEX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IS_PER_PATCH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SHADER_STORAGE_BUFFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SHADER_STORAGE_BUFFER_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SHADER_STORAGE_BUFFER_START", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SHADER_STORAGE_BUFFER_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_SHADER_STORAGE_BLOCK_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SHADER_STORAGE_BARRIER_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_STENCIL_TEXTURE_MODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BUFFER_OFFSET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BUFFER_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_VIEW_MIN_LEVEL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_VIEW_NUM_LEVELS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_VIEW_MIN_LAYER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_VIEW_NUM_LAYERS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_IMMUTABLE_LEVELS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_RELATIVE_OFFSET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_BINDING_DIVISOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_BINDING_OFFSET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_BINDING_STRIDE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VERTEX_ATTRIB_BINDINGS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DISPLAY_LIST", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_ES2_compatibility", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_ES3_compatibility", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_arrays_of_arrays", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_base_instance", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_blend_func_extended", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_cl_event", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SYNC_CL_EVENT_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SYNC_CL_EVENT_COMPLETE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_clear_buffer_object", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_color_buffer_float", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA_FLOAT_MODE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLAMP_VERTEX_COLOR_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLAMP_FRAGMENT_COLOR_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLAMP_READ_COLOR_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FIXED_ONLY_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_compatibility", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_compressed_texture_pixel_storage", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_compute_shader", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPUTE_SHADER_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_conservative_depth", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_copy_buffer", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COPY_READ_BUFFER_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COPY_WRITE_BUFFER_BINDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_copy_image", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_debug_output", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_CALLBACK_FUNCTION_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_CALLBACK_USER_PARAM_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_SOURCE_API_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_SOURCE_WINDOW_SYSTEM_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_SOURCE_SHADER_COMPILER_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_SOURCE_THIRD_PARTY_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_SOURCE_APPLICATION_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_SOURCE_OTHER_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_TYPE_ERROR_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_TYPE_PORTABILITY_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_TYPE_PERFORMANCE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_TYPE_OTHER_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_DEBUG_MESSAGE_LENGTH_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_DEBUG_LOGGED_MESSAGES_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_LOGGED_MESSAGES_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_SEVERITY_HIGH_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_SEVERITY_MEDIUM_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_SEVERITY_LOW_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_depth_buffer_float", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_depth_clamp", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_depth_texture", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_COMPONENT16_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_COMPONENT24_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_COMPONENT32_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_DEPTH_SIZE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_TEXTURE_MODE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_draw_buffers", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_DRAW_BUFFERS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER0_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER1_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER2_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER3_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER4_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER5_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER6_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER7_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER8_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER9_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER10_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER11_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER12_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER13_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER14_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER15_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_draw_buffers_blend", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_draw_elements_base_vertex", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_draw_indirect", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_draw_instanced", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_explicit_attrib_location", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_explicit_uniform_location", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_fragment_coord_conventions", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_fragment_layer_viewport", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_fragment_program", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAGMENT_PROGRAM_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_FORMAT_ASCII_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_LENGTH_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_FORMAT_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_BINDING_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_INSTRUCTIONS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_INSTRUCTIONS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_NATIVE_INSTRUCTIONS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_TEMPORARIES_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_TEMPORARIES_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_NATIVE_TEMPORARIES_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_NATIVE_TEMPORARIES_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_PARAMETERS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_PARAMETERS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_NATIVE_PARAMETERS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_NATIVE_PARAMETERS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_ATTRIBS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_ATTRIBS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_NATIVE_ATTRIBS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_NATIVE_ATTRIBS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_ENV_PARAMETERS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_UNDER_NATIVE_LIMITS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_ALU_INSTRUCTIONS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_TEX_INSTRUCTIONS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_TEX_INDIRECTIONS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_ALU_INSTRUCTIONS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_TEX_INSTRUCTIONS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_TEX_INDIRECTIONS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_STRING_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_ERROR_POSITION_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_MATRIX_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSPOSE_CURRENT_MATRIX_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_MATRIX_STACK_DEPTH_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_MATRICES_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TEXTURE_COORDS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TEXTURE_IMAGE_UNITS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_ERROR_STRING_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX0_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX1_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX2_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX3_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX4_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX5_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX6_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX7_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX8_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX9_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX10_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX11_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX12_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX13_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX14_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX15_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX16_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX17_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX18_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX19_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX20_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX21_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX22_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX23_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX24_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX25_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX26_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX27_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX28_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX29_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX30_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX31_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_fragment_program_shadow", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_fragment_shader", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAGMENT_SHADER_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAGMENT_SHADER_DERIVATIVE_HINT_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_framebuffer_no_attachments", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_framebuffer_object", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_framebuffer_sRGB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_geometry_shader4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINES_ADJACENCY_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINE_STRIP_ADJACENCY_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRIANGLES_ADJACENCY_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRIANGLE_STRIP_ADJACENCY_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_POINT_SIZE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_ATTACHMENT_LAYERED_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GEOMETRY_SHADER_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GEOMETRY_VERTICES_OUT_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GEOMETRY_INPUT_TYPE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GEOMETRY_OUTPUT_TYPE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_GEOMETRY_VARYING_COMPONENTS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VERTEX_VARYING_COMPONENTS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_GEOMETRY_OUTPUT_VERTICES_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_get_program_binary", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_gpu_shader5", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_gpu_shader_fp64", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_half_float_pixel", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HALF_FLOAT_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_half_float_vertex", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_instanced_arrays", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY_DIVISOR_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_internalformat_query", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_internalformat_query2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SRGB_DECODE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_invalidate_subdata", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_map_buffer_alignment", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_map_buffer_range", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_matrix_palette", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX_PALETTE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_MATRIX_PALETTE_STACK_DEPTH_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PALETTE_MATRICES_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_PALETTE_MATRIX_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX_INDEX_ARRAY_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_MATRIX_INDEX_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX_INDEX_ARRAY_SIZE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX_INDEX_ARRAY_TYPE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX_INDEX_ARRAY_STRIDE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX_INDEX_ARRAY_POINTER_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_multi_draw_indirect", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_multisample", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MULTISAMPLE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_ALPHA_TO_COVERAGE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_ALPHA_TO_ONE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_COVERAGE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_BUFFERS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLES_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_COVERAGE_VALUE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_COVERAGE_INVERT_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MULTISAMPLE_BIT_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_occlusion_query", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_QUERY_COUNTER_BITS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_QUERY_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_QUERY_RESULT_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_QUERY_RESULT_AVAILABLE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLES_PASSED_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_occlusion_query2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_pixel_buffer_object", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_PACK_BUFFER_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_UNPACK_BUFFER_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_PACK_BUFFER_BINDING_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_UNPACK_BUFFER_BINDING_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_point_parameters", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POINT_SIZE_MIN_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POINT_SIZE_MAX_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POINT_FADE_THRESHOLD_SIZE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POINT_DISTANCE_ATTENUATION_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_point_sprite", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POINT_SPRITE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COORD_REPLACE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_program_interface_query", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_provoking_vertex", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_robust_buffer_access_behavior", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_robustness", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LOSE_CONTEXT_ON_RESET_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GUILTY_CONTEXT_RESET_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INNOCENT_CONTEXT_RESET_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNKNOWN_CONTEXT_RESET_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RESET_NOTIFICATION_STRATEGY_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NO_RESET_NOTIFICATION_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_robustness_isolation", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_sample_shading", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_SHADING_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MIN_SAMPLE_SHADING_VALUE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_sampler_objects", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_seamless_cube_map", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_separate_shader_objects", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_shader_atomic_counters", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_shader_bit_encoding", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_shader_image_load_store", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_shader_image_size", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_shader_objects", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_OBJECT_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SHADER_OBJECT_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OBJECT_TYPE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OBJECT_SUBTYPE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_VEC2_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_VEC3_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_VEC4_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_VEC2_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_VEC3_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_VEC4_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BOOL_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BOOL_VEC2_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BOOL_VEC3_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BOOL_VEC4_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_MAT2_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_MAT3_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_MAT4_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_1D_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_2D_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_3D_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_CUBE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_1D_SHADOW_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_2D_SHADOW_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_2D_RECT_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_2D_RECT_SHADOW_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OBJECT_DELETE_STATUS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OBJECT_COMPILE_STATUS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OBJECT_LINK_STATUS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OBJECT_VALIDATE_STATUS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OBJECT_INFO_LOG_LENGTH_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OBJECT_ATTACHED_OBJECTS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OBJECT_ACTIVE_UNIFORMS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OBJECT_ACTIVE_UNIFORM_MAX_LENGTH_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OBJECT_SHADER_SOURCE_LENGTH_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_shader_precision", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_shader_stencil_export", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_shader_storage_buffer_object", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_shader_subroutine", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_shader_texture_lod", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_shading_language_100", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SHADING_LANGUAGE_VERSION_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_shading_language_420pack", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_shading_language_include", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SHADER_INCLUDE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NAMED_STRING_LENGTH_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NAMED_STRING_TYPE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_shading_language_packing", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_shadow", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COMPARE_MODE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COMPARE_FUNC_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPARE_R_TO_TEXTURE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_shadow_ambient", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COMPARE_FAIL_VALUE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_stencil_texturing", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_sync", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_tessellation_shader", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_texture_border_clamp", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLAMP_TO_BORDER_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_texture_buffer_object", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BUFFER_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TEXTURE_BUFFER_SIZE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BINDING_BUFFER_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BUFFER_DATA_STORE_BINDING_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BUFFER_FORMAT_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_texture_buffer_object_rgb32", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_texture_buffer_range", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_texture_compression", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_ALPHA_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_LUMINANCE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_LUMINANCE_ALPHA_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_INTENSITY_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_RGB_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_RGBA_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COMPRESSION_HINT_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COMPRESSED_IMAGE_SIZE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COMPRESSED_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_TEXTURE_FORMATS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_texture_compression_bptc", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_RGBA_BPTC_UNORM_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_texture_compression_rgtc", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_texture_cube_map", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NORMAL_MAP_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REFLECTION_MAP_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CUBE_MAP_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BINDING_CUBE_MAP_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROXY_TEXTURE_CUBE_MAP_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_CUBE_MAP_TEXTURE_SIZE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_texture_cube_map_array", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CUBE_MAP_ARRAY_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROXY_TEXTURE_CUBE_MAP_ARRAY_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_CUBE_MAP_ARRAY_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_SAMPLER_CUBE_MAP_ARRAY_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_texture_env_add", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_texture_env_combine", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMBINE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMBINE_RGB_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMBINE_ALPHA_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SOURCE0_RGB_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SOURCE1_RGB_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SOURCE2_RGB_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SOURCE0_ALPHA_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SOURCE1_ALPHA_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SOURCE2_ALPHA_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OPERAND0_RGB_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OPERAND1_RGB_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OPERAND2_RGB_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OPERAND0_ALPHA_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OPERAND1_ALPHA_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OPERAND2_ALPHA_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB_SCALE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ADD_SIGNED_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTERPOLATE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SUBTRACT_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONSTANT_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PRIMARY_COLOR_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PREVIOUS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_texture_env_crossbar", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_texture_env_dot3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOT3_RGB_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOT3_RGBA_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_texture_float", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_RED_TYPE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_GREEN_TYPE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BLUE_TYPE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_ALPHA_TYPE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_LUMINANCE_TYPE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_INTENSITY_TYPE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_DEPTH_TYPE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_NORMALIZED_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA32F_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB32F_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA32F_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTENSITY32F_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE32F_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE_ALPHA32F_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA16F_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB16F_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA16F_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTENSITY16F_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE16F_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE_ALPHA16F_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_texture_gather", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_texture_mirrored_repeat", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MIRRORED_REPEAT_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_texture_multisample", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_texture_non_power_of_two", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_texture_query_levels", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_texture_query_lod", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_texture_rectangle", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_RECTANGLE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BINDING_RECTANGLE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROXY_TEXTURE_RECTANGLE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_RECTANGLE_TEXTURE_SIZE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_texture_rg", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_texture_rgb10_a2ui", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_texture_storage", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_texture_storage_multisample", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_texture_swizzle", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_texture_view", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_timer_query", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_transform_feedback2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK_PAUSED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK_ACTIVE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_transform_feedback3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_transform_feedback_instanced", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_transpose_matrix", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSPOSE_MODELVIEW_MATRIX_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSPOSE_PROJECTION_MATRIX_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSPOSE_TEXTURE_MATRIX_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSPOSE_COLOR_MATRIX_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_uniform_buffer_object", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_GEOMETRY_UNIFORM_BLOCKS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_vertex_array_bgra", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_vertex_array_object", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_vertex_attrib_64bit", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_vertex_attrib_binding", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_vertex_blend", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VERTEX_UNITS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ACTIVE_VERTEX_UNITS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_WEIGHT_SUM_UNITY_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_BLEND_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_WEIGHT_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_WEIGHT_ARRAY_TYPE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_WEIGHT_ARRAY_STRIDE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_WEIGHT_ARRAY_SIZE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_WEIGHT_ARRAY_POINTER_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_WEIGHT_ARRAY_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW0_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW1_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW2_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW3_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW4_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW5_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW6_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW7_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW8_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW9_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW10_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW11_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW12_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW13_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW14_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW15_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW16_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW17_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW18_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW19_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW20_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW21_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW22_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW23_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW24_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW25_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW26_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW27_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW28_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW29_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW30_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW31_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_vertex_buffer_object", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BUFFER_SIZE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BUFFER_USAGE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARRAY_BUFFER_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ELEMENT_ARRAY_BUFFER_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARRAY_BUFFER_BINDING_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ELEMENT_ARRAY_BUFFER_BINDING_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ARRAY_BUFFER_BINDING_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NORMAL_ARRAY_BUFFER_BINDING_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ARRAY_BUFFER_BINDING_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INDEX_ARRAY_BUFFER_BINDING_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EDGE_FLAG_ARRAY_BUFFER_BINDING_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_WEIGHT_ARRAY_BUFFER_BINDING_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_READ_ONLY_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_WRITE_ONLY_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_READ_WRITE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BUFFER_ACCESS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BUFFER_MAPPED_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BUFFER_MAP_POINTER_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STREAM_DRAW_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STREAM_READ_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STREAM_COPY_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STATIC_DRAW_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STATIC_READ_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STATIC_COPY_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DYNAMIC_DRAW_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DYNAMIC_READ_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DYNAMIC_COPY_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_vertex_program", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_SUM_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_PROGRAM_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY_ENABLED_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY_SIZE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY_STRIDE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY_TYPE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_VERTEX_ATTRIB_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_PROGRAM_POINT_SIZE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_PROGRAM_TWO_SIDE_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY_POINTER_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VERTEX_ATTRIBS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY_NORMALIZED_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_ADDRESS_REGISTERS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_ADDRESS_REGISTERS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_vertex_shader", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_SHADER_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VERTEX_UNIFORM_COMPONENTS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VARYING_FLOATS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OBJECT_ACTIVE_ATTRIBUTES_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OBJECT_ACTIVE_ATTRIBUTE_MAX_LENGTH_ARB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_vertex_type_2_10_10_10_rev", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_viewport_array", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARB_window_pos", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_KHR_debug", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_KHR_texture_compression_astc_ldr", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_RGBA_ASTC_4x4_KHR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_RGBA_ASTC_5x4_KHR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_RGBA_ASTC_5x5_KHR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_RGBA_ASTC_6x5_KHR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_RGBA_ASTC_6x6_KHR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_RGBA_ASTC_8x5_KHR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_RGBA_ASTC_8x6_KHR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_RGBA_ASTC_8x8_KHR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_RGBA_ASTC_10x5_KHR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_RGBA_ASTC_10x6_KHR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_RGBA_ASTC_10x8_KHR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_RGBA_ASTC_10x10_KHR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_RGBA_ASTC_12x10_KHR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_RGBA_ASTC_12x12_KHR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4_KHR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4_KHR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5_KHR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5_KHR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6_KHR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x5_KHR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x6_KHR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x8_KHR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x5_KHR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x10_KHR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x12_KHR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OES_byte_coordinates", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OES_compressed_paletted_texture", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PALETTE4_RGB8_OES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PALETTE4_RGBA8_OES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PALETTE4_R5_G6_B5_OES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PALETTE4_RGBA4_OES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PALETTE4_RGB5_A1_OES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PALETTE8_RGB8_OES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PALETTE8_RGBA8_OES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PALETTE8_R5_G6_B5_OES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PALETTE8_RGBA4_OES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PALETTE8_RGB5_A1_OES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OES_fixed_point", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FIXED_OES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OES_query_matrix", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OES_read_format", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMPLEMENTATION_COLOR_READ_TYPE_OES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMPLEMENTATION_COLOR_READ_FORMAT_OES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OES_single_precision", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_3DFX_multisample", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MULTISAMPLE_3DFX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_BUFFERS_3DFX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLES_3DFX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MULTISAMPLE_BIT_3DFX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_3DFX_tbuffer", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_3DFX_texture_compression_FXT1", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_RGB_FXT1_3DFX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_RGBA_FXT1_3DFX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AMD_blend_minmax_factor", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FACTOR_MIN_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FACTOR_MAX_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AMD_conservative_depth", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AMD_debug_output", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_DEBUG_MESSAGE_LENGTH_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_DEBUG_LOGGED_MESSAGES_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_LOGGED_MESSAGES_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_SEVERITY_HIGH_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_SEVERITY_MEDIUM_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_SEVERITY_LOW_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_CATEGORY_API_ERROR_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_CATEGORY_WINDOW_SYSTEM_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_CATEGORY_DEPRECATION_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_CATEGORY_UNDEFINED_BEHAVIOR_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_CATEGORY_PERFORMANCE_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_CATEGORY_SHADER_COMPILER_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_CATEGORY_APPLICATION_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEBUG_CATEGORY_OTHER_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AMD_depth_clamp_separate", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_CLAMP_NEAR_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_CLAMP_FAR_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AMD_draw_buffers_blend", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AMD_interleaved_elements", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ELEMENT_SWIZZLE_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ID_SWIZZLE_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AMD_multi_draw_indirect", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AMD_name_gen_delete", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DATA_BUFFER_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PERFORMANCE_MONITOR_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_QUERY_OBJECT_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ARRAY_OBJECT_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_OBJECT_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AMD_performance_monitor", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COUNTER_TYPE_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COUNTER_RANGE_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT64_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PERCENTAGE_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PERFMON_RESULT_AVAILABLE_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PERFMON_RESULT_SIZE_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PERFMON_RESULT_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AMD_pinned_memory", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXTERNAL_VIRTUAL_MEMORY_BUFFER_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AMD_query_buffer_object", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_QUERY_BUFFER_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_QUERY_BUFFER_BINDING_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_QUERY_RESULT_NO_WAIT_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AMD_sample_positions", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SUBSAMPLE_DISTANCE_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AMD_seamless_cubemap_per_texture", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AMD_shader_stencil_export", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AMD_shader_trinary_minmax", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AMD_sparse_texture", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIRTUAL_PAGE_SIZE_X_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIRTUAL_PAGE_SIZE_Y_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIRTUAL_PAGE_SIZE_Z_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_SPARSE_TEXTURE_SIZE_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_SPARSE_3D_TEXTURE_SIZE_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MIN_SPARSE_LEVEL_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MIN_LOD_WARNING_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_STORAGE_SPARSE_BIT_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AMD_stencil_operation_extended", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SET_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REPLACE_VALUE_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_OP_VALUE_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_BACK_OP_VALUE_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AMD_texture_texture4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AMD_transform_feedback3_lines_triangles", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AMD_vertex_shader_layer", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AMD_vertex_shader_tessellator", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_BUFFER_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_SAMPLER_BUFFER_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_SAMPLER_BUFFER_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TESSELLATION_MODE_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TESSELLATION_FACTOR_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DISCRETE_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONTINUOUS_AMD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AMD_vertex_shader_viewport_index", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_APPLE_aux_depth_stencil", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AUX_DEPTH_STENCIL_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_APPLE_client_storage", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNPACK_CLIENT_STORAGE_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_APPLE_element_array", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ELEMENT_ARRAY_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ELEMENT_ARRAY_TYPE_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ELEMENT_ARRAY_POINTER_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_APPLE_fence", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_PIXELS_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FENCE_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_APPLE_float_pixels", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HALF_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA_FLOAT32_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB_FLOAT32_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA_FLOAT32_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTENSITY_FLOAT32_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE_FLOAT32_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE_ALPHA_FLOAT32_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA_FLOAT16_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB_FLOAT16_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA_FLOAT16_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTENSITY_FLOAT16_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE_FLOAT16_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE_ALPHA_FLOAT16_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_FLOAT_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_APPLE_flush_buffer_range", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BUFFER_SERIALIZED_MODIFY_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BUFFER_FLUSHING_UNMAP_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_APPLE_object_purgeable", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BUFFER_OBJECT_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RELEASED_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VOLATILE_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RETAINED_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNDEFINED_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PURGEABLE_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_APPLE_rgb_422", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB_422_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_SHORT_8_8_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_SHORT_8_8_REV_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_APPLE_row_bytes", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PACK_ROW_BYTES_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNPACK_ROW_BYTES_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_APPLE_specular_vector", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LIGHT_MODEL_SPECULAR_VECTOR_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_APPLE_texture_range", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_RANGE_LENGTH_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_RANGE_POINTER_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_STORAGE_HINT_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STORAGE_PRIVATE_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STORAGE_CACHED_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STORAGE_SHARED_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_APPLE_transform_hint", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_HINT_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_APPLE_vertex_array_object", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ARRAY_BINDING_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_APPLE_vertex_array_range", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ARRAY_RANGE_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ARRAY_RANGE_LENGTH_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ARRAY_STORAGE_HINT_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ARRAY_RANGE_POINTER_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STORAGE_CLIENT_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_APPLE_vertex_program_evaluators", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_MAP1_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_MAP2_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_MAP1_SIZE_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_MAP1_COEFF_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_MAP1_ORDER_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_MAP1_DOMAIN_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_MAP2_SIZE_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_MAP2_COEFF_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_MAP2_ORDER_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_MAP2_DOMAIN_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_APPLE_ycbcr_422", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_YCBCR_422_APPLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATI_draw_buffers", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_DRAW_BUFFERS_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER0_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER1_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER2_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER3_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER4_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER5_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER6_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER7_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER8_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER9_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER10_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER11_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER12_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER13_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER14_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_BUFFER15_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATI_element_array", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ELEMENT_ARRAY_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ELEMENT_ARRAY_TYPE_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ELEMENT_ARRAY_POINTER_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATI_envmap_bumpmap", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BUMP_ROT_MATRIX_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BUMP_ROT_MATRIX_SIZE_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BUMP_NUM_TEX_UNITS_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BUMP_TEX_UNITS_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DUDV_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DU8DV8_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BUMP_ENVMAP_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BUMP_TARGET_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATI_fragment_shader", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAGMENT_SHADER_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REG_0_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REG_1_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REG_2_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REG_3_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REG_4_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REG_5_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REG_6_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REG_7_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REG_8_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REG_9_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REG_10_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REG_11_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REG_12_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REG_13_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REG_14_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REG_15_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REG_16_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REG_17_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REG_18_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REG_19_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REG_20_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REG_21_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REG_22_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REG_23_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REG_24_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REG_25_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REG_26_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REG_27_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REG_28_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REG_29_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REG_30_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REG_31_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CON_0_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CON_1_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CON_2_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CON_3_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CON_4_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CON_5_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CON_6_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CON_7_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CON_8_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CON_9_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CON_10_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CON_11_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CON_12_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CON_13_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CON_14_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CON_15_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CON_16_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CON_17_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CON_18_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CON_19_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CON_20_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CON_21_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CON_22_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CON_23_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CON_24_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CON_25_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CON_26_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CON_27_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CON_28_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CON_29_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CON_30_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CON_31_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MOV_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ADD_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MUL_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SUB_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOT3_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOT4_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAD_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LERP_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CND_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CND0_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOT2_ADD_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SECONDARY_INTERPOLATOR_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NUM_FRAGMENT_REGISTERS_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NUM_FRAGMENT_CONSTANTS_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NUM_PASSES_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NUM_INSTRUCTIONS_PER_PASS_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NUM_INSTRUCTIONS_TOTAL_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NUM_INPUT_INTERPOLATOR_COMPONENTS_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NUM_LOOPBACK_COMPONENTS_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ALPHA_PAIRING_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SWIZZLE_STR_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SWIZZLE_STQ_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SWIZZLE_STR_DR_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SWIZZLE_STQ_DQ_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SWIZZLE_STRQ_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SWIZZLE_STRQ_DQ_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RED_BIT_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GREEN_BIT_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLUE_BIT_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_2X_BIT_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_4X_BIT_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_8X_BIT_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HALF_BIT_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_QUARTER_BIT_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EIGHTH_BIT_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SATURATE_BIT_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMP_BIT_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NEGATE_BIT_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BIAS_BIT_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATI_map_object_buffer", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATI_meminfo", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VBO_FREE_MEMORY_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_FREE_MEMORY_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER_FREE_MEMORY_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATI_pixel_format_float", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA_FLOAT_MODE_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_CLEAR_UNCLAMPED_VALUE_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATI_pn_triangles", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PN_TRIANGLES_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PN_TRIANGLES_TESSELATION_LEVEL_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PN_TRIANGLES_POINT_MODE_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PN_TRIANGLES_NORMAL_MODE_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PN_TRIANGLES_TESSELATION_LEVEL_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PN_TRIANGLES_POINT_MODE_LINEAR_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PN_TRIANGLES_POINT_MODE_CUBIC_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PN_TRIANGLES_NORMAL_MODE_LINEAR_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PN_TRIANGLES_NORMAL_MODE_QUADRATIC_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATI_separate_stencil", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_BACK_FUNC_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_BACK_FAIL_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_BACK_PASS_DEPTH_FAIL_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_BACK_PASS_DEPTH_PASS_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATI_text_fragment_shader", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXT_FRAGMENT_SHADER_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATI_texture_env_combine3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODULATE_ADD_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODULATE_SIGNED_ADD_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODULATE_SUBTRACT_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATI_texture_float", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA_FLOAT32_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB_FLOAT32_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA_FLOAT32_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTENSITY_FLOAT32_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE_FLOAT32_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE_ALPHA_FLOAT32_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA_FLOAT16_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB_FLOAT16_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA_FLOAT16_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTENSITY_FLOAT16_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE_FLOAT16_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE_ALPHA_FLOAT16_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATI_texture_mirror_once", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MIRROR_CLAMP_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MIRROR_CLAMP_TO_EDGE_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATI_vertex_array_object", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STATIC_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DYNAMIC_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PRESERVE_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DISCARD_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OBJECT_BUFFER_SIZE_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OBJECT_BUFFER_USAGE_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARRAY_OBJECT_BUFFER_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARRAY_OBJECT_OFFSET_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATI_vertex_attrib_array_object", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATI_vertex_streams", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VERTEX_STREAMS_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_STREAM0_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_STREAM1_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_STREAM2_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_STREAM3_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_STREAM4_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_STREAM5_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_STREAM6_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_STREAM7_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_SOURCE_ATI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_422_pixels", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_422_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_422_REV_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_422_AVERAGE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_422_REV_AVERAGE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_abgr", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ABGR_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_bgra", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BGR_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BGRA_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_bindable_uniform", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VERTEX_BINDABLE_UNIFORMS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_FRAGMENT_BINDABLE_UNIFORMS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_GEOMETRY_BINDABLE_UNIFORMS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_BINDABLE_UNIFORM_SIZE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNIFORM_BUFFER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNIFORM_BUFFER_BINDING_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_blend_color", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONSTANT_COLOR_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ONE_MINUS_CONSTANT_COLOR_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONSTANT_ALPHA_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ONE_MINUS_CONSTANT_ALPHA_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLEND_COLOR_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_blend_equation_separate", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLEND_EQUATION_RGB_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLEND_EQUATION_ALPHA_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_blend_func_separate", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLEND_DST_RGB_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLEND_SRC_RGB_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLEND_DST_ALPHA_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLEND_SRC_ALPHA_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_blend_logic_op", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_blend_minmax", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MIN_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FUNC_ADD_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLEND_EQUATION_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_blend_subtract", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FUNC_SUBTRACT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FUNC_REVERSE_SUBTRACT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_clip_volume_hint", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLIP_VOLUME_CLIPPING_HINT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_cmyka", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CMYK_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CMYKA_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PACK_CMYK_HINT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNPACK_CMYK_HINT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_color_subtable", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_compiled_vertex_array", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARRAY_ELEMENT_LOCK_FIRST_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARRAY_ELEMENT_LOCK_COUNT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_convolution", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONVOLUTION_1D_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONVOLUTION_2D_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SEPARABLE_2D_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONVOLUTION_BORDER_MODE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONVOLUTION_FILTER_SCALE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONVOLUTION_FILTER_BIAS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REDUCE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONVOLUTION_FORMAT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONVOLUTION_WIDTH_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONVOLUTION_HEIGHT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_CONVOLUTION_WIDTH_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_CONVOLUTION_HEIGHT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_CONVOLUTION_RED_SCALE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_CONVOLUTION_GREEN_SCALE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_CONVOLUTION_BLUE_SCALE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_CONVOLUTION_ALPHA_SCALE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_CONVOLUTION_RED_BIAS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_CONVOLUTION_GREEN_BIAS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_CONVOLUTION_BLUE_BIAS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_CONVOLUTION_ALPHA_BIAS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_coordinate_frame", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TANGENT_ARRAY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BINORMAL_ARRAY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_TANGENT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_BINORMAL_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TANGENT_ARRAY_TYPE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TANGENT_ARRAY_STRIDE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BINORMAL_ARRAY_TYPE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BINORMAL_ARRAY_STRIDE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TANGENT_ARRAY_POINTER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BINORMAL_ARRAY_POINTER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP1_TANGENT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP2_TANGENT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP1_BINORMAL_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP2_BINORMAL_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_copy_texture", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_cull_vertex", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CULL_VERTEX_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CULL_VERTEX_EYE_POSITION_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CULL_VERTEX_OBJECT_POSITION_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_depth_bounds_test", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_BOUNDS_TEST_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_BOUNDS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_direct_state_access", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_MATRIX_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSPOSE_PROGRAM_MATRIX_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_MATRIX_STACK_DEPTH_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_draw_buffers2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_draw_instanced", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_draw_range_elements", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_ELEMENTS_VERTICES_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_ELEMENTS_INDICES_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_fog_coord", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_COORDINATE_SOURCE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_COORDINATE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAGMENT_DEPTH_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_FOG_COORDINATE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_COORDINATE_ARRAY_TYPE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_COORDINATE_ARRAY_STRIDE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_COORDINATE_ARRAY_POINTER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_COORDINATE_ARRAY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_framebuffer_blit", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_READ_FRAMEBUFFER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_FRAMEBUFFER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_FRAMEBUFFER_BINDING_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_READ_FRAMEBUFFER_BINDING_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_framebuffer_multisample", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER_SAMPLES_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_SAMPLES_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_framebuffer_multisample_blit_scaled", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SCALED_RESOLVE_FASTEST_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SCALED_RESOLVE_NICEST_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_framebuffer_object", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INVALID_FRAMEBUFFER_OPERATION_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_RENDERBUFFER_SIZE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_BINDING_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER_BINDING_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_3D_ZOFFSET_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_COMPLETE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_INCOMPLETE_FORMATS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_UNSUPPORTED_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_COLOR_ATTACHMENTS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ATTACHMENT0_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ATTACHMENT1_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ATTACHMENT2_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ATTACHMENT3_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ATTACHMENT4_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ATTACHMENT5_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ATTACHMENT6_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ATTACHMENT7_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ATTACHMENT8_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ATTACHMENT9_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ATTACHMENT10_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ATTACHMENT11_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ATTACHMENT12_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ATTACHMENT13_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ATTACHMENT14_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ATTACHMENT15_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_ATTACHMENT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_ATTACHMENT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER_WIDTH_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER_HEIGHT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER_INTERNAL_FORMAT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_INDEX1_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_INDEX4_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_INDEX8_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_INDEX16_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER_RED_SIZE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER_GREEN_SIZE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER_BLUE_SIZE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER_ALPHA_SIZE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER_DEPTH_SIZE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER_STENCIL_SIZE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_framebuffer_sRGB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_SRGB_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_SRGB_CAPABLE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_geometry_shader4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GEOMETRY_SHADER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GEOMETRY_VERTICES_OUT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GEOMETRY_INPUT_TYPE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GEOMETRY_OUTPUT_TYPE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_GEOMETRY_VARYING_COMPONENTS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VERTEX_VARYING_COMPONENTS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VARYING_COMPONENTS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_GEOMETRY_OUTPUT_VERTICES_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINES_ADJACENCY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINE_STRIP_ADJACENCY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRIANGLES_ADJACENCY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRIANGLE_STRIP_ADJACENCY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_ATTACHMENT_LAYERED_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_POINT_SIZE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_gpu_program_parameters", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_gpu_shader4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY_INTEGER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_1D_ARRAY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_2D_ARRAY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_BUFFER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_1D_ARRAY_SHADOW_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_2D_ARRAY_SHADOW_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_CUBE_SHADOW_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_VEC2_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_VEC3_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_VEC4_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_SAMPLER_1D_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_SAMPLER_2D_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_SAMPLER_3D_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_SAMPLER_CUBE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_SAMPLER_2D_RECT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_SAMPLER_1D_ARRAY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_SAMPLER_2D_ARRAY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_SAMPLER_BUFFER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_SAMPLER_1D_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_SAMPLER_2D_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_SAMPLER_3D_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_SAMPLER_CUBE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_SAMPLER_2D_RECT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_SAMPLER_1D_ARRAY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_SAMPLER_2D_ARRAY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_SAMPLER_BUFFER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MIN_PROGRAM_TEXEL_OFFSET_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_TEXEL_OFFSET_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_histogram", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HISTOGRAM_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROXY_HISTOGRAM_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HISTOGRAM_WIDTH_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HISTOGRAM_FORMAT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HISTOGRAM_RED_SIZE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HISTOGRAM_GREEN_SIZE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HISTOGRAM_BLUE_SIZE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HISTOGRAM_ALPHA_SIZE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HISTOGRAM_LUMINANCE_SIZE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HISTOGRAM_SINK_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MINMAX_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MINMAX_FORMAT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MINMAX_SINK_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TABLE_TOO_LARGE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_index_array_formats", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IUI_V2F_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IUI_V3F_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IUI_N3F_V2F_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IUI_N3F_V3F_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_T2F_IUI_V2F_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_T2F_IUI_V3F_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_T2F_IUI_N3F_V2F_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_T2F_IUI_N3F_V3F_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_index_func", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INDEX_TEST_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INDEX_TEST_FUNC_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INDEX_TEST_REF_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_index_material", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INDEX_MATERIAL_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INDEX_MATERIAL_PARAMETER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INDEX_MATERIAL_FACE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_index_texture", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_light_texture", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAGMENT_MATERIAL_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAGMENT_NORMAL_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAGMENT_COLOR_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATTENUATION_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SHADOW_ATTENUATION_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_APPLICATION_MODE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_LIGHT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_MATERIAL_FACE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_MATERIAL_PARAMETER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_misc_attribute", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_multi_draw_arrays", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_multisample", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MULTISAMPLE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_ALPHA_TO_MASK_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_ALPHA_TO_ONE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_MASK_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_1PASS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_2PASS_0_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_2PASS_1_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_4PASS_0_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_4PASS_1_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_4PASS_2_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_4PASS_3_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_BUFFERS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLES_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_MASK_VALUE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_MASK_INVERT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_PATTERN_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MULTISAMPLE_BIT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_packed_depth_stencil", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_STENCIL_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_24_8_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH24_STENCIL8_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_STENCIL_SIZE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_packed_float", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_R11F_G11F_B10F_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_10F_11F_11F_REV_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA_SIGNED_COMPONENTS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_packed_pixels", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_BYTE_3_3_2_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_SHORT_4_4_4_4_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_SHORT_5_5_5_1_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_8_8_8_8_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_10_10_10_2_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_paletted_texture", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_INDEX1_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_INDEX2_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_INDEX4_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_INDEX8_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_INDEX12_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_INDEX16_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_INDEX_SIZE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_pixel_buffer_object", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_PACK_BUFFER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_UNPACK_BUFFER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_PACK_BUFFER_BINDING_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_UNPACK_BUFFER_BINDING_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_pixel_transform", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_TRANSFORM_2D_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_MAG_FILTER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_MIN_FILTER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_CUBIC_WEIGHT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CUBIC_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AVERAGE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_TRANSFORM_2D_MATRIX_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_pixel_transform_color_table", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_point_parameters", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POINT_SIZE_MIN_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POINT_SIZE_MAX_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POINT_FADE_THRESHOLD_SIZE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DISTANCE_ATTENUATION_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_polygon_offset", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POLYGON_OFFSET_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POLYGON_OFFSET_FACTOR_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POLYGON_OFFSET_BIAS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_provoking_vertex", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FIRST_VERTEX_CONVENTION_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LAST_VERTEX_CONVENTION_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROVOKING_VERTEX_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_rescale_normal", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RESCALE_NORMAL_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_secondary_color", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_SUM_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_SECONDARY_COLOR_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SECONDARY_COLOR_ARRAY_SIZE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SECONDARY_COLOR_ARRAY_TYPE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SECONDARY_COLOR_ARRAY_STRIDE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SECONDARY_COLOR_ARRAY_POINTER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SECONDARY_COLOR_ARRAY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_separate_shader_objects", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ACTIVE_PROGRAM_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_separate_specular_color", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LIGHT_MODEL_COLOR_CONTROL_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SINGLE_COLOR_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SEPARATE_SPECULAR_COLOR_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_shader_image_load_store", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_IMAGE_UNITS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_BINDING_NAME_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_BINDING_LEVEL_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_BINDING_LAYERED_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_BINDING_LAYER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_BINDING_ACCESS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_1D_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_2D_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_3D_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_2D_RECT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_CUBE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_BUFFER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_1D_ARRAY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_2D_ARRAY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_CUBE_MAP_ARRAY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_2D_MULTISAMPLE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_2D_MULTISAMPLE_ARRAY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_IMAGE_1D_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_IMAGE_2D_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_IMAGE_3D_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_IMAGE_2D_RECT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_IMAGE_CUBE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_IMAGE_BUFFER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_IMAGE_1D_ARRAY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_IMAGE_2D_ARRAY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_IMAGE_CUBE_MAP_ARRAY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_IMAGE_2D_MULTISAMPLE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_IMAGE_1D_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_IMAGE_2D_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_IMAGE_3D_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_IMAGE_2D_RECT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_IMAGE_CUBE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_IMAGE_BUFFER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_IMAGE_1D_ARRAY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_IMAGE_2D_ARRAY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_IMAGE_SAMPLES_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_BINDING_FORMAT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ELEMENT_ARRAY_BARRIER_BIT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNIFORM_BARRIER_BIT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_FETCH_BARRIER_BIT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SHADER_IMAGE_ACCESS_BARRIER_BIT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMMAND_BARRIER_BIT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_BUFFER_BARRIER_BIT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_UPDATE_BARRIER_BIT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BUFFER_UPDATE_BARRIER_BIT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEBUFFER_BARRIER_BIT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK_BARRIER_BIT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATOMIC_COUNTER_BARRIER_BIT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALL_BARRIER_BITS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_shadow_funcs", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_shared_texture_palette", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SHARED_TEXTURE_PALETTE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_stencil_clear_tag", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_TAG_BITS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_CLEAR_TAG_VALUE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_stencil_two_side", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STENCIL_TEST_TWO_SIDE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ACTIVE_STENCIL_FACE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_stencil_wrap", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INCR_WRAP_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DECR_WRAP_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_subtexture", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_texture", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA4_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA8_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA12_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA16_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE4_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE8_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE12_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE16_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE4_ALPHA4_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE6_ALPHA2_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE8_ALPHA8_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE12_ALPHA4_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE12_ALPHA12_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE16_ALPHA16_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTENSITY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTENSITY4_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTENSITY8_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTENSITY12_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTENSITY16_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB2_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB4_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB5_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB8_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB10_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB12_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB16_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA2_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA4_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB5_A1_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA8_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB10_A2_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA12_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA16_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_RED_SIZE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_GREEN_SIZE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BLUE_SIZE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_ALPHA_SIZE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_LUMINANCE_SIZE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_INTENSITY_SIZE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REPLACE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROXY_TEXTURE_1D_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROXY_TEXTURE_2D_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_TOO_LARGE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_texture3D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PACK_SKIP_IMAGES_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PACK_IMAGE_HEIGHT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNPACK_SKIP_IMAGES_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNPACK_IMAGE_HEIGHT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_3D_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROXY_TEXTURE_3D_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_DEPTH_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_WRAP_R_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_3D_TEXTURE_SIZE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_texture_array", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPARE_REF_DEPTH_TO_TEXTURE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_texture_buffer_object", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BUFFER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TEXTURE_BUFFER_SIZE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BINDING_BUFFER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BUFFER_DATA_STORE_BINDING_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BUFFER_FORMAT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_texture_compression_latc", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_LUMINANCE_LATC1_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SIGNED_LUMINANCE_LATC1_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_LUMINANCE_ALPHA_LATC2_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SIGNED_LUMINANCE_ALPHA_LATC2_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_texture_compression_rgtc", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_RED_RGTC1_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SIGNED_RED_RGTC1_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_RED_GREEN_RGTC2_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SIGNED_RED_GREEN_RGTC2_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_texture_compression_s3tc", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_RGB_S3TC_DXT1_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_RGBA_S3TC_DXT1_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_RGBA_S3TC_DXT3_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_RGBA_S3TC_DXT5_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_texture_cube_map", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NORMAL_MAP_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REFLECTION_MAP_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CUBE_MAP_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BINDING_CUBE_MAP_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CUBE_MAP_POSITIVE_X_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CUBE_MAP_NEGATIVE_X_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CUBE_MAP_POSITIVE_Y_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CUBE_MAP_POSITIVE_Z_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROXY_TEXTURE_CUBE_MAP_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_CUBE_MAP_TEXTURE_SIZE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_texture_env_add", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_texture_env_combine", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMBINE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMBINE_RGB_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMBINE_ALPHA_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB_SCALE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ADD_SIGNED_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTERPOLATE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONSTANT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PRIMARY_COLOR_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PREVIOUS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SOURCE0_RGB_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SOURCE1_RGB_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SOURCE2_RGB_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SOURCE0_ALPHA_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SOURCE1_ALPHA_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SOURCE2_ALPHA_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OPERAND0_RGB_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OPERAND1_RGB_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OPERAND2_RGB_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OPERAND0_ALPHA_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OPERAND1_ALPHA_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OPERAND2_ALPHA_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_texture_env_dot3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOT3_RGB_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOT3_RGBA_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_texture_filter_anisotropic", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_MAX_ANISOTROPY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_texture_integer", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA32UI_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB32UI_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA32UI_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTENSITY32UI_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE32UI_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE_ALPHA32UI_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA16UI_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB16UI_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA16UI_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTENSITY16UI_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE16UI_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE_ALPHA16UI_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA8UI_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB8UI_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA8UI_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTENSITY8UI_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE8UI_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE_ALPHA8UI_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA32I_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB32I_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA32I_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTENSITY32I_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE32I_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE_ALPHA32I_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA16I_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB16I_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA16I_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTENSITY16I_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE16I_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE_ALPHA16I_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA8I_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB8I_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA8I_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTENSITY8I_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE8I_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE_ALPHA8I_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RED_INTEGER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GREEN_INTEGER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLUE_INTEGER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA_INTEGER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB_INTEGER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA_INTEGER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BGR_INTEGER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BGRA_INTEGER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE_INTEGER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE_ALPHA_INTEGER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA_INTEGER_MODE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_texture_lod_bias", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TEXTURE_LOD_BIAS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_FILTER_CONTROL_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_LOD_BIAS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_texture_mirror_clamp", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MIRROR_CLAMP_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MIRROR_CLAMP_TO_EDGE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MIRROR_CLAMP_TO_BORDER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_texture_object", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_PRIORITY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_RESIDENT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_1D_BINDING_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_2D_BINDING_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_3D_BINDING_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_texture_perturb_normal", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PERTURB_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_NORMAL_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_texture_sRGB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SRGB_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SRGB8_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SRGB_ALPHA_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SRGB8_ALPHA8_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SLUMINANCE_ALPHA_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SLUMINANCE8_ALPHA8_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SLUMINANCE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SLUMINANCE8_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SRGB_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SRGB_ALPHA_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SLUMINANCE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SLUMINANCE_ALPHA_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SRGB_S3TC_DXT1_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_texture_sRGB_decode", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_SRGB_DECODE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DECODE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SKIP_DECODE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_texture_shared_exponent", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB9_E5_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_5_9_9_9_REV_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_SHARED_SIZE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_texture_snorm", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA_SNORM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE_SNORM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE_ALPHA_SNORM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTENSITY_SNORM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA8_SNORM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE8_SNORM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE8_ALPHA8_SNORM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTENSITY8_SNORM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA16_SNORM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE16_SNORM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LUMINANCE16_ALPHA16_SNORM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTENSITY16_SNORM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RED_SNORM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RG_SNORM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB_SNORM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA_SNORM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_texture_swizzle", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_SWIZZLE_R_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_SWIZZLE_G_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_SWIZZLE_B_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_SWIZZLE_A_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_SWIZZLE_RGBA_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_timer_query", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TIME_ELAPSED_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_transform_feedback", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK_BUFFER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK_BUFFER_START_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTERLEAVED_ATTRIBS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SEPARATE_ATTRIBS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PRIMITIVES_GENERATED_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RASTERIZER_DISCARD_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK_VARYINGS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK_BUFFER_MODE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_vertex_array", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ARRAY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NORMAL_ARRAY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ARRAY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INDEX_ARRAY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COORD_ARRAY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EDGE_FLAG_ARRAY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ARRAY_SIZE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ARRAY_TYPE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ARRAY_STRIDE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ARRAY_COUNT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NORMAL_ARRAY_TYPE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NORMAL_ARRAY_STRIDE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NORMAL_ARRAY_COUNT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ARRAY_SIZE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ARRAY_TYPE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ARRAY_STRIDE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ARRAY_COUNT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INDEX_ARRAY_TYPE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INDEX_ARRAY_STRIDE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INDEX_ARRAY_COUNT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COORD_ARRAY_SIZE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COORD_ARRAY_TYPE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COORD_ARRAY_STRIDE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COORD_ARRAY_COUNT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EDGE_FLAG_ARRAY_STRIDE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EDGE_FLAG_ARRAY_COUNT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ARRAY_POINTER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NORMAL_ARRAY_POINTER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ARRAY_POINTER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INDEX_ARRAY_POINTER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COORD_ARRAY_POINTER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EDGE_FLAG_ARRAY_POINTER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_vertex_array_bgra", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_vertex_attrib_64bit", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOUBLE_VEC2_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOUBLE_VEC3_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOUBLE_VEC4_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOUBLE_MAT2_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOUBLE_MAT3_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOUBLE_MAT4_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOUBLE_MAT2x3_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOUBLE_MAT2x4_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOUBLE_MAT3x2_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOUBLE_MAT3x4_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOUBLE_MAT4x2_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOUBLE_MAT4x3_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_vertex_shader", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_SHADER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_SHADER_BINDING_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OP_INDEX_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OP_NEGATE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OP_DOT3_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OP_DOT4_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OP_MUL_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OP_ADD_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OP_MADD_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OP_FRAC_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OP_MAX_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OP_MIN_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OP_SET_GE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OP_SET_LT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OP_CLAMP_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OP_FLOOR_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OP_ROUND_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OP_EXP_BASE_2_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OP_LOG_BASE_2_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OP_POWER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OP_RECIP_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OP_RECIP_SQRT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OP_SUB_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OP_CROSS_PRODUCT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OP_MULTIPLY_MATRIX_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OP_MOV_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUTPUT_VERTEX_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUTPUT_COLOR0_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUTPUT_COLOR1_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUTPUT_TEXTURE_COORD0_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUTPUT_TEXTURE_COORD1_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUTPUT_TEXTURE_COORD2_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUTPUT_TEXTURE_COORD3_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUTPUT_TEXTURE_COORD4_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUTPUT_TEXTURE_COORD5_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUTPUT_TEXTURE_COORD6_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUTPUT_TEXTURE_COORD7_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUTPUT_TEXTURE_COORD8_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUTPUT_TEXTURE_COORD9_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUTPUT_TEXTURE_COORD10_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUTPUT_TEXTURE_COORD11_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUTPUT_TEXTURE_COORD12_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUTPUT_TEXTURE_COORD13_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUTPUT_TEXTURE_COORD14_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUTPUT_TEXTURE_COORD15_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUTPUT_TEXTURE_COORD16_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUTPUT_TEXTURE_COORD17_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUTPUT_TEXTURE_COORD18_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUTPUT_TEXTURE_COORD19_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUTPUT_TEXTURE_COORD20_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUTPUT_TEXTURE_COORD21_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUTPUT_TEXTURE_COORD22_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUTPUT_TEXTURE_COORD23_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUTPUT_TEXTURE_COORD24_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUTPUT_TEXTURE_COORD25_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUTPUT_TEXTURE_COORD26_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUTPUT_TEXTURE_COORD27_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUTPUT_TEXTURE_COORD28_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUTPUT_TEXTURE_COORD29_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUTPUT_TEXTURE_COORD30_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUTPUT_TEXTURE_COORD31_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OUTPUT_FOG_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SCALAR_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VECTOR_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VARIANT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INVARIANT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LOCAL_CONSTANT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LOCAL_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VERTEX_SHADER_INSTRUCTIONS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VERTEX_SHADER_VARIANTS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VERTEX_SHADER_INVARIANTS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VERTEX_SHADER_LOCAL_CONSTANTS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VERTEX_SHADER_LOCALS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_OPTIMIZED_VERTEX_SHADER_INSTRUCTIONS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_OPTIMIZED_VERTEX_SHADER_VARIANTS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCAL_CONSTANTS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_OPTIMIZED_VERTEX_SHADER_INVARIANTS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCALS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_SHADER_INSTRUCTIONS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_SHADER_VARIANTS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_SHADER_INVARIANTS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_SHADER_LOCAL_CONSTANTS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_SHADER_LOCALS_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_SHADER_OPTIMIZED_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_X_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_Y_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_Z_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_W_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NEGATIVE_X_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NEGATIVE_Y_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NEGATIVE_Z_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NEGATIVE_W_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ZERO_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ONE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NEGATIVE_ONE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NORMALIZED_RANGE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FULL_RANGE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_VERTEX_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MVP_MATRIX_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VARIANT_VALUE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VARIANT_DATATYPE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VARIANT_ARRAY_STRIDE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VARIANT_ARRAY_TYPE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VARIANT_ARRAY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VARIANT_ARRAY_POINTER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INVARIANT_VALUE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INVARIANT_DATATYPE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LOCAL_CONSTANT_VALUE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LOCAL_CONSTANT_DATATYPE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_vertex_weighting", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW0_STACK_DEPTH_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW1_STACK_DEPTH_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW0_MATRIX_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW1_MATRIX_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_WEIGHTING_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW0_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW1_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_VERTEX_WEIGHT_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_WEIGHT_ARRAY_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_WEIGHT_ARRAY_SIZE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_WEIGHT_ARRAY_TYPE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_WEIGHT_ARRAY_STRIDE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_WEIGHT_ARRAY_POINTER_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXT_x11_sync_object", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SYNC_X11_FENCE_EXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GREMEDY_frame_terminator", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GREMEDY_string_marker", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HP_convolution_border_modes", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IGNORE_BORDER_HP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONSTANT_BORDER_HP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REPLICATE_BORDER_HP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONVOLUTION_BORDER_COLOR_HP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HP_image_transform", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_SCALE_X_HP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_SCALE_Y_HP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_TRANSLATE_X_HP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_TRANSLATE_Y_HP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_ROTATE_ANGLE_HP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_ROTATE_ORIGIN_X_HP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_ROTATE_ORIGIN_Y_HP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_MAG_FILTER_HP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_MIN_FILTER_HP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_CUBIC_WEIGHT_HP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CUBIC_HP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AVERAGE_HP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IMAGE_TRANSFORM_2D_HP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_IMAGE_TRANSFORM_COLOR_TABLE_HP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROXY_POST_IMAGE_TRANSFORM_COLOR_TABLE_HP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HP_occlusion_test", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OCCLUSION_TEST_HP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OCCLUSION_TEST_RESULT_HP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HP_texture_lighting", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_LIGHTING_MODE_HP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_POST_SPECULAR_HP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_PRE_SPECULAR_HP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IBM_cull_vertex", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CULL_VERTEX_IBM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IBM_multimode_draw_arrays", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IBM_rasterpos_clip", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RASTER_POSITION_UNCLIPPED_IBM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IBM_static_data", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALL_STATIC_DATA_IBM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STATIC_VERTEX_ARRAY_IBM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IBM_texture_mirrored_repeat", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MIRRORED_REPEAT_IBM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IBM_vertex_array_lists", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ARRAY_LIST_IBM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NORMAL_ARRAY_LIST_IBM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ARRAY_LIST_IBM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INDEX_ARRAY_LIST_IBM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COORD_ARRAY_LIST_IBM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EDGE_FLAG_ARRAY_LIST_IBM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_COORDINATE_ARRAY_LIST_IBM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SECONDARY_COLOR_ARRAY_LIST_IBM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ARRAY_LIST_STRIDE_IBM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NORMAL_ARRAY_LIST_STRIDE_IBM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ARRAY_LIST_STRIDE_IBM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INDEX_ARRAY_LIST_STRIDE_IBM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COORD_ARRAY_LIST_STRIDE_IBM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EDGE_FLAG_ARRAY_LIST_STRIDE_IBM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_COORDINATE_ARRAY_LIST_STRIDE_IBM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SECONDARY_COLOR_ARRAY_LIST_STRIDE_IBM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INGR_blend_func_separate", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INGR_color_clamp", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RED_MIN_CLAMP_INGR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GREEN_MIN_CLAMP_INGR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLUE_MIN_CLAMP_INGR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA_MIN_CLAMP_INGR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RED_MAX_CLAMP_INGR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GREEN_MAX_CLAMP_INGR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BLUE_MAX_CLAMP_INGR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA_MAX_CLAMP_INGR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INGR_interlace_read", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTERLACE_READ_INGR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTEL_map_texture", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_MEMORY_LAYOUT_INTEL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LAYOUT_DEFAULT_INTEL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LAYOUT_LINEAR_INTEL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LAYOUT_LINEAR_CPU_CACHED_INTEL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTEL_parallel_arrays", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PARALLEL_ARRAYS_INTEL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ARRAY_PARALLEL_POINTERS_INTEL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NORMAL_ARRAY_PARALLEL_POINTERS_INTEL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ARRAY_PARALLEL_POINTERS_INTEL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COORD_ARRAY_PARALLEL_POINTERS_INTEL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MESAX_texture_stack", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_1D_STACK_MESAX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_2D_STACK_MESAX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROXY_TEXTURE_1D_STACK_MESAX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROXY_TEXTURE_2D_STACK_MESAX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_1D_STACK_BINDING_MESAX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_2D_STACK_BINDING_MESAX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MESA_pack_invert", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PACK_INVERT_MESA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MESA_resize_buffers", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MESA_window_pos", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MESA_ycbcr_texture", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_SHORT_8_8_MESA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_SHORT_8_8_REV_MESA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_YCBCR_MESA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NVX_conditional_render", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_bindless_texture", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_blend_square", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_compute_program5", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPUTE_PROGRAM_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMPUTE_PROGRAM_PARAMETER_BUFFER_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_conditional_render", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_QUERY_WAIT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_QUERY_NO_WAIT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_QUERY_BY_REGION_WAIT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_QUERY_BY_REGION_NO_WAIT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_copy_depth_to_color", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_STENCIL_TO_RGBA_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_STENCIL_TO_BGRA_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_copy_image", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_deep_texture3D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_DEEP_3D_TEXTURE_WIDTH_HEIGHT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_DEEP_3D_TEXTURE_DEPTH_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_depth_buffer_float", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_COMPONENT32F_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH32F_STENCIL8_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_32_UNSIGNED_INT_24_8_REV_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_BUFFER_FLOAT_MODE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_depth_clamp", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_CLAMP_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_draw_texture", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_evaluators", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EVAL_2D_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EVAL_TRIANGULAR_2D_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP_TESSELLATION_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP_ATTRIB_U_ORDER_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP_ATTRIB_V_ORDER_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EVAL_FRACTIONAL_TESSELLATION_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EVAL_VERTEX_ATTRIB0_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EVAL_VERTEX_ATTRIB1_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EVAL_VERTEX_ATTRIB2_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EVAL_VERTEX_ATTRIB3_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EVAL_VERTEX_ATTRIB4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EVAL_VERTEX_ATTRIB5_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EVAL_VERTEX_ATTRIB6_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EVAL_VERTEX_ATTRIB7_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EVAL_VERTEX_ATTRIB8_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EVAL_VERTEX_ATTRIB9_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EVAL_VERTEX_ATTRIB10_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EVAL_VERTEX_ATTRIB11_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EVAL_VERTEX_ATTRIB12_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EVAL_VERTEX_ATTRIB13_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EVAL_VERTEX_ATTRIB14_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EVAL_VERTEX_ATTRIB15_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_MAP_TESSELLATION_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_RATIONAL_EVAL_ORDER_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_explicit_multisample", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_POSITION_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_MASK_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_MASK_VALUE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BINDING_RENDERBUFFER_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_RENDERBUFFER_DATA_STORE_BINDING_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_RENDERBUFFER_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLER_RENDERBUFFER_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT_SAMPLER_RENDERBUFFER_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_SAMPLER_RENDERBUFFER_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_SAMPLE_MASK_WORDS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_fence", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALL_COMPLETED_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FENCE_STATUS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FENCE_CONDITION_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_float_buffer", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_R_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_RG_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_RGB_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_RGBA_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_R16_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_R32_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_RG16_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_RG32_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_RGB16_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_RGB32_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_RGBA16_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_RGBA32_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_FLOAT_COMPONENTS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_CLEAR_COLOR_VALUE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT_RGBA_MODE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_fog_distance", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_DISTANCE_MODE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EYE_RADIAL_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EYE_PLANE_ABSOLUTE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_fragment_program", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_FRAGMENT_PROGRAM_LOCAL_PARAMETERS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAGMENT_PROGRAM_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TEXTURE_COORDS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TEXTURE_IMAGE_UNITS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAGMENT_PROGRAM_BINDING_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_ERROR_STRING_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_fragment_program2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_EXEC_INSTRUCTIONS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_CALL_DEPTH_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_IF_DEPTH_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_LOOP_DEPTH_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_LOOP_COUNT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_fragment_program4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_fragment_program_option", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_framebuffer_multisample_coverage", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER_COVERAGE_SAMPLES_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RENDERBUFFER_COLOR_SAMPLES_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_MULTISAMPLE_COVERAGE_MODES_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MULTISAMPLE_COVERAGE_MODES_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_geometry_program4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GEOMETRY_PROGRAM_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_OUTPUT_VERTICES_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_TOTAL_OUTPUT_COMPONENTS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_geometry_shader4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_gpu_program4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MIN_PROGRAM_TEXEL_OFFSET_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_TEXEL_OFFSET_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_ATTRIB_COMPONENTS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_RESULT_COMPONENTS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_ATTRIB_COMPONENTS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_RESULT_COMPONENTS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_GENERIC_ATTRIBS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_GENERIC_RESULTS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_gpu_program5", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_GEOMETRY_PROGRAM_INVOCATIONS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MIN_FRAGMENT_INTERPOLATION_OFFSET_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_FRAGMENT_INTERPOLATION_OFFSET_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAGMENT_PROGRAM_INTERPOLATION_OFFSET_BITS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_SUBROUTINE_PARAMETERS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_SUBROUTINE_NUM_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_gpu_shader5", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT64_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT64_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT8_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT8_VEC2_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT8_VEC3_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT8_VEC4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT16_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT16_VEC2_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT16_VEC3_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT16_VEC4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT64_VEC2_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT64_VEC3_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INT64_VEC4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT8_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT8_VEC2_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT8_VEC3_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT8_VEC4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT16_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT16_VEC2_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT16_VEC3_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT16_VEC4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT64_VEC2_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT64_VEC3_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT64_VEC4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT16_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT16_VEC2_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT16_VEC3_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FLOAT16_VEC4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_half_float", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HALF_FLOAT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_light_max_exponent", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_SHININESS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_SPOT_EXPONENT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_multisample_coverage", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_SAMPLES_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_multisample_filter_hint", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MULTISAMPLE_FILTER_HINT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_occlusion_query", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_COUNTER_BITS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_OCCLUSION_QUERY_ID_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_COUNT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_COUNT_AVAILABLE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_packed_depth_stencil", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_STENCIL_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_24_8_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_parameter_buffer_object", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_PARAMETER_BUFFER_BINDINGS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_PARAMETER_BUFFER_SIZE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_PROGRAM_PARAMETER_BUFFER_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GEOMETRY_PROGRAM_PARAMETER_BUFFER_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAGMENT_PROGRAM_PARAMETER_BUFFER_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_parameter_buffer_object2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_path_rendering", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_FORMAT_SVG_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_FORMAT_PS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STANDARD_FONT_NAME_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SYSTEM_FONT_NAME_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FILE_NAME_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_STROKE_WIDTH_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_END_CAPS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_INITIAL_END_CAP_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_TERMINAL_END_CAP_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_JOIN_STYLE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_MITER_LIMIT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_DASH_CAPS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_INITIAL_DASH_CAP_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_TERMINAL_DASH_CAP_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_DASH_OFFSET_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_CLIENT_LENGTH_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_FILL_MODE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_FILL_MASK_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_FILL_COVER_MODE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_STROKE_COVER_MODE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_STROKE_MASK_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COUNT_UP_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COUNT_DOWN_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_OBJECT_BOUNDING_BOX_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONVEX_HULL_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BOUNDING_BOX_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSLATE_X_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSLATE_Y_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSLATE_2D_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSLATE_3D_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AFFINE_2D_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_AFFINE_3D_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSPOSE_AFFINE_2D_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSPOSE_AFFINE_3D_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UTF8_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UTF16_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BOUNDING_BOX_OF_BOUNDING_BOXES_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_COMMAND_COUNT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_COORD_COUNT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_DASH_ARRAY_COUNT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_COMPUTED_LENGTH_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_FILL_BOUNDING_BOX_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_STROKE_BOUNDING_BOX_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SQUARE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ROUND_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRIANGULAR_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BEVEL_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MITER_REVERT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MITER_TRUNCATE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SKIP_MISSING_GLYPH_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_USE_MISSING_GLYPH_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_ERROR_POSITION_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_FOG_GEN_MODE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ACCUM_ADJACENT_PAIRS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ADJACENT_PAIRS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FIRST_TO_REST_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_GEN_MODE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_GEN_COEFF_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_GEN_COLOR_FORMAT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_GEN_COMPONENTS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_STENCIL_FUNC_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_STENCIL_REF_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_STENCIL_VALUE_MASK_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_STENCIL_DEPTH_OFFSET_FACTOR_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_STENCIL_DEPTH_OFFSET_UNITS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_COVER_DEPTH_FUNC_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PATH_DASH_OFFSET_RESET_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MOVE_TO_RESETS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MOVE_TO_CONTINUES_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLOSE_PATH_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MOVE_TO_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RELATIVE_MOVE_TO_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINE_TO_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RELATIVE_LINE_TO_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HORIZONTAL_LINE_TO_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RELATIVE_HORIZONTAL_LINE_TO_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTICAL_LINE_TO_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RELATIVE_VERTICAL_LINE_TO_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_QUADRATIC_CURVE_TO_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RELATIVE_QUADRATIC_CURVE_TO_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CUBIC_CURVE_TO_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RELATIVE_CUBIC_CURVE_TO_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SMOOTH_QUADRATIC_CURVE_TO_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SMOOTH_CUBIC_CURVE_TO_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SMALL_CCW_ARC_TO_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RELATIVE_SMALL_CCW_ARC_TO_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SMALL_CW_ARC_TO_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RELATIVE_SMALL_CW_ARC_TO_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LARGE_CCW_ARC_TO_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RELATIVE_LARGE_CCW_ARC_TO_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LARGE_CW_ARC_TO_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RELATIVE_LARGE_CW_ARC_TO_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RESTART_PATH_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DUP_FIRST_CUBIC_CURVE_TO_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DUP_LAST_CUBIC_CURVE_TO_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RECT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CIRCULAR_CCW_ARC_TO_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CIRCULAR_CW_ARC_TO_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CIRCULAR_TANGENT_ARC_TO_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ARC_TO_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RELATIVE_ARC_TO_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BOLD_BIT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ITALIC_BIT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GLYPH_WIDTH_BIT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GLYPH_HEIGHT_BIT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GLYPH_HORIZONTAL_BEARING_X_BIT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GLYPH_HORIZONTAL_BEARING_Y_BIT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GLYPH_HORIZONTAL_BEARING_ADVANCE_BIT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GLYPH_VERTICAL_BEARING_X_BIT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GLYPH_VERTICAL_BEARING_Y_BIT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GLYPH_VERTICAL_BEARING_ADVANCE_BIT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GLYPH_HAS_KERNING_BIT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FONT_X_MIN_BOUNDS_BIT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FONT_Y_MIN_BOUNDS_BIT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FONT_X_MAX_BOUNDS_BIT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FONT_Y_MAX_BOUNDS_BIT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FONT_UNITS_PER_EM_BIT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FONT_ASCENDER_BIT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FONT_DESCENDER_BIT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FONT_HEIGHT_BIT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FONT_MAX_ADVANCE_WIDTH_BIT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FONT_MAX_ADVANCE_HEIGHT_BIT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FONT_UNDERLINE_POSITION_BIT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FONT_UNDERLINE_THICKNESS_BIT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FONT_HAS_KERNING_BIT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PRIMARY_COLOR_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SECONDARY_COLOR_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_pixel_data_range", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_WRITE_PIXEL_DATA_RANGE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_READ_PIXEL_DATA_RANGE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_WRITE_PIXEL_DATA_RANGE_LENGTH_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_READ_PIXEL_DATA_RANGE_LENGTH_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_WRITE_PIXEL_DATA_RANGE_POINTER_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_READ_PIXEL_DATA_RANGE_POINTER_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_point_sprite", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POINT_SPRITE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COORD_REPLACE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POINT_SPRITE_R_MODE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_present_video", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAME_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FIELDS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_TIME_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NUM_FILL_STREAMS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PRESENT_TIME_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PRESENT_DURATION_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_primitive_restart", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PRIMITIVE_RESTART_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PRIMITIVE_RESTART_INDEX_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_register_combiners", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REGISTER_COMBINERS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VARIABLE_A_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VARIABLE_B_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VARIABLE_C_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VARIABLE_D_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VARIABLE_E_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VARIABLE_F_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VARIABLE_G_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONSTANT_COLOR0_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONSTANT_COLOR1_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SPARE0_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SPARE1_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DISCARD_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_E_TIMES_F_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SPARE0_PLUS_SECONDARY_COLOR_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_IDENTITY_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INVERT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXPAND_NORMAL_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EXPAND_NEGATE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HALF_BIAS_NORMAL_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HALF_BIAS_NEGATE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SIGNED_IDENTITY_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SIGNED_NEGATE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SCALE_BY_TWO_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SCALE_BY_FOUR_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SCALE_BY_ONE_HALF_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BIAS_BY_NEGATIVE_ONE_HALF_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMBINER_INPUT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMBINER_MAPPING_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMBINER_COMPONENT_USAGE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMBINER_AB_DOT_PRODUCT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMBINER_CD_DOT_PRODUCT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMBINER_MUX_SUM_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMBINER_SCALE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMBINER_BIAS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMBINER_AB_OUTPUT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMBINER_CD_OUTPUT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMBINER_SUM_OUTPUT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_GENERAL_COMBINERS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NUM_GENERAL_COMBINERS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_SUM_CLAMP_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMBINER0_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMBINER1_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMBINER2_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMBINER3_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMBINER4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMBINER5_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMBINER6_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMBINER7_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_register_combiners2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PER_STAGE_CONSTANTS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_shader_atomic_counters", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_shader_atomic_float", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_shader_buffer_load", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BUFFER_GPU_ADDRESS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GPU_ADDRESS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_SHADER_BUFFER_ADDRESS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_shader_buffer_store", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SHADER_GLOBAL_ACCESS_BARRIER_BIT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_shader_storage_buffer_object", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_tessellation_program5", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_PROGRAM_PATCH_ATTRIBS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TESS_CONTROL_PROGRAM_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TESS_EVALUATION_PROGRAM_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TESS_CONTROL_PROGRAM_PARAMETER_BUFFER_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TESS_EVALUATION_PROGRAM_PARAMETER_BUFFER_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_texgen_emboss", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EMBOSS_LIGHT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EMBOSS_CONSTANT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EMBOSS_MAP_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_texgen_reflection", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NORMAL_MAP_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REFLECTION_MAP_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_texture_barrier", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_texture_compression_vtc", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_texture_env_combine4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COMBINE4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SOURCE3_RGB_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SOURCE3_ALPHA_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OPERAND3_RGB_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OPERAND3_ALPHA_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_texture_expand_normal", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_UNSIGNED_REMAP_MODE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_texture_multisample", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COVERAGE_SAMPLES_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COLOR_SAMPLES_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_texture_rectangle", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_RECTANGLE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BINDING_RECTANGLE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROXY_TEXTURE_RECTANGLE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_RECTANGLE_TEXTURE_SIZE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_texture_shader", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OFFSET_TEXTURE_RECTANGLE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OFFSET_TEXTURE_RECTANGLE_SCALE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOT_PRODUCT_TEXTURE_RECTANGLE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA_UNSIGNED_DOT_PRODUCT_MAPPING_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_S8_S8_8_8_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNSIGNED_INT_8_8_S8_S8_REV_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DSDT_MAG_INTENSITY_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SHADER_CONSISTENT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_SHADER_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SHADER_OPERATION_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CULL_MODES_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OFFSET_TEXTURE_MATRIX_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OFFSET_TEXTURE_SCALE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OFFSET_TEXTURE_BIAS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OFFSET_TEXTURE_2D_MATRIX_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OFFSET_TEXTURE_2D_SCALE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OFFSET_TEXTURE_2D_BIAS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PREVIOUS_TEXTURE_INPUT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONST_EYE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PASS_THROUGH_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CULL_FRAGMENT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OFFSET_TEXTURE_2D_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPENDENT_AR_TEXTURE_2D_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPENDENT_GB_TEXTURE_2D_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOT_PRODUCT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOT_PRODUCT_DEPTH_REPLACE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOT_PRODUCT_TEXTURE_2D_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOT_PRODUCT_TEXTURE_CUBE_MAP_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOT_PRODUCT_DIFFUSE_CUBE_MAP_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOT_PRODUCT_REFLECT_CUBE_MAP_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOT_PRODUCT_CONST_EYE_REFLECT_CUBE_MAP_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HILO_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DSDT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DSDT_MAG_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DSDT_MAG_VIB_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HILO16_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SIGNED_HILO_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SIGNED_HILO16_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SIGNED_RGBA_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SIGNED_RGBA8_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SIGNED_RGB_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SIGNED_RGB8_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SIGNED_LUMINANCE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SIGNED_LUMINANCE8_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SIGNED_LUMINANCE_ALPHA_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SIGNED_LUMINANCE8_ALPHA8_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SIGNED_ALPHA_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SIGNED_ALPHA8_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SIGNED_INTENSITY_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SIGNED_INTENSITY8_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DSDT8_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DSDT8_MAG8_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DSDT8_MAG8_INTENSITY8_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SIGNED_RGB_UNSIGNED_ALPHA_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SIGNED_RGB8_UNSIGNED_ALPHA8_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HI_SCALE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LO_SCALE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DS_SCALE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DT_SCALE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAGNITUDE_SCALE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIBRANCE_SCALE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HI_BIAS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LO_BIAS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DS_BIAS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DT_BIAS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAGNITUDE_BIAS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIBRANCE_BIAS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BORDER_VALUES_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_HI_SIZE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_LO_SIZE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_DS_SIZE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_DT_SIZE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_MAG_SIZE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_texture_shader2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOT_PRODUCT_TEXTURE_3D_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_texture_shader3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OFFSET_PROJECTIVE_TEXTURE_2D_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OFFSET_PROJECTIVE_TEXTURE_2D_SCALE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_SCALE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OFFSET_HILO_TEXTURE_2D_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OFFSET_HILO_TEXTURE_RECTANGLE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OFFSET_HILO_PROJECTIVE_TEXTURE_2D_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OFFSET_HILO_PROJECTIVE_TEXTURE_RECTANGLE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPENDENT_HILO_TEXTURE_2D_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPENDENT_RGB_TEXTURE_3D_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPENDENT_RGB_TEXTURE_CUBE_MAP_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOT_PRODUCT_PASS_THROUGH_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOT_PRODUCT_TEXTURE_1D_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DOT_PRODUCT_AFFINE_DEPTH_REPLACE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_HILO8_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SIGNED_HILO8_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FORCE_BLUE_TO_ONE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_transform_feedback", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BACK_PRIMARY_COLOR_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BACK_SECONDARY_COLOR_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COORD_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLIP_DISTANCE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ID_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PRIMITIVE_ID_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GENERIC_ATTRIB_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK_ATTRIBS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK_BUFFER_MODE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ACTIVE_VARYINGS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ACTIVE_VARYING_MAX_LENGTH_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK_VARYINGS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK_BUFFER_START_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK_RECORD_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PRIMITIVES_GENERATED_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RASTERIZER_DISCARD_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTERLEAVED_ATTRIBS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SEPARATE_ATTRIBS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK_BUFFER_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LAYER_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NEXT_BUFFER_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SKIP_COMPONENTS4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SKIP_COMPONENTS3_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SKIP_COMPONENTS2_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SKIP_COMPONENTS1_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_transform_feedback2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSFORM_FEEDBACK_BINDING_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_vdpau_interop", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SURFACE_STATE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SURFACE_REGISTERED_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SURFACE_MAPPED_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_WRITE_DISCARD_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_vertex_array_range", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ARRAY_RANGE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ARRAY_RANGE_LENGTH_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ARRAY_RANGE_VALID_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VERTEX_ARRAY_RANGE_ELEMENT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ARRAY_RANGE_POINTER_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_vertex_array_range2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ARRAY_RANGE_WITHOUT_FLUSH_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_vertex_attrib_integer_64bit", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_vertex_buffer_unified_memory", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ELEMENT_ARRAY_UNIFIED_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY_ADDRESS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ARRAY_ADDRESS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NORMAL_ARRAY_ADDRESS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ARRAY_ADDRESS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INDEX_ARRAY_ADDRESS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COORD_ARRAY_ADDRESS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EDGE_FLAG_ARRAY_ADDRESS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SECONDARY_COLOR_ARRAY_ADDRESS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_COORD_ARRAY_ADDRESS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ELEMENT_ARRAY_ADDRESS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY_LENGTH_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ARRAY_LENGTH_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NORMAL_ARRAY_LENGTH_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_ARRAY_LENGTH_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INDEX_ARRAY_LENGTH_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COORD_ARRAY_LENGTH_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EDGE_FLAG_ARRAY_LENGTH_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SECONDARY_COLOR_ARRAY_LENGTH_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_COORD_ARRAY_LENGTH_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ELEMENT_ARRAY_LENGTH_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_INDIRECT_UNIFIED_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_INDIRECT_ADDRESS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DRAW_INDIRECT_LENGTH_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_vertex_program", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_PROGRAM_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_STATE_PROGRAM_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATTRIB_ARRAY_SIZE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATTRIB_ARRAY_STRIDE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATTRIB_ARRAY_TYPE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_ATTRIB_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_LENGTH_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_STRING_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MODELVIEW_PROJECTION_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IDENTITY_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INVERSE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRANSPOSE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INVERSE_TRANSPOSE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TRACK_MATRIX_STACK_DEPTH_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_TRACK_MATRICES_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX0_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX1_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX2_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX3_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX5_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX6_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATRIX7_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_MATRIX_STACK_DEPTH_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_MATRIX_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_PROGRAM_POINT_SIZE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_PROGRAM_TWO_SIDE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_PARAMETER_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ATTRIB_ARRAY_POINTER_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_TARGET_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_RESIDENT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRACK_MATRIX_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRACK_MATRIX_TRANSFORM_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_PROGRAM_BINDING_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROGRAM_ERROR_POSITION_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY0_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY1_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY2_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY3_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY5_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY6_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY7_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY8_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY9_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY10_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY11_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY12_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY13_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY14_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY15_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP1_VERTEX_ATTRIB0_4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP1_VERTEX_ATTRIB1_4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP1_VERTEX_ATTRIB2_4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP1_VERTEX_ATTRIB3_4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP1_VERTEX_ATTRIB4_4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP1_VERTEX_ATTRIB5_4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP1_VERTEX_ATTRIB6_4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP1_VERTEX_ATTRIB7_4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP1_VERTEX_ATTRIB8_4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP1_VERTEX_ATTRIB9_4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP1_VERTEX_ATTRIB10_4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP1_VERTEX_ATTRIB11_4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP1_VERTEX_ATTRIB12_4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP1_VERTEX_ATTRIB13_4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP1_VERTEX_ATTRIB14_4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP1_VERTEX_ATTRIB15_4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP2_VERTEX_ATTRIB0_4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP2_VERTEX_ATTRIB1_4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP2_VERTEX_ATTRIB2_4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP2_VERTEX_ATTRIB3_4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP2_VERTEX_ATTRIB4_4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP2_VERTEX_ATTRIB5_4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP2_VERTEX_ATTRIB6_4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP2_VERTEX_ATTRIB7_4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP2_VERTEX_ATTRIB8_4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP2_VERTEX_ATTRIB9_4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP2_VERTEX_ATTRIB10_4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP2_VERTEX_ATTRIB11_4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP2_VERTEX_ATTRIB12_4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP2_VERTEX_ATTRIB13_4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP2_VERTEX_ATTRIB14_4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAP2_VERTEX_ATTRIB15_4_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_vertex_program1_1", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_vertex_program2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_vertex_program2_option", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_vertex_program3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_vertex_program4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_ATTRIB_ARRAY_INTEGER_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NV_video_capture", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIDEO_BUFFER_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIDEO_BUFFER_BINDING_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FIELD_UPPER_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FIELD_LOWER_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NUM_VIDEO_CAPTURE_STREAMS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NEXT_VIDEO_CAPTURE_BUFFER_STATUS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIDEO_CAPTURE_TO_422_SUPPORTED_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LAST_VIDEO_CAPTURE_STATUS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIDEO_BUFFER_PITCH_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIDEO_COLOR_CONVERSION_MATRIX_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIDEO_COLOR_CONVERSION_MAX_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIDEO_COLOR_CONVERSION_MIN_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIDEO_COLOR_CONVERSION_OFFSET_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIDEO_BUFFER_INTERNAL_FORMAT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PARTIAL_SUCCESS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SUCCESS_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FAILURE_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_YCBYCR8_422_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_YCBAYCR8A_4224_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_Z6Y10Z6CB10Z6Y10Z6CR10_422_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_Z6Y10Z6CB10Z6A10Z6Y10Z6CR10Z6A10_4224_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_Z4Y12Z4CB12Z4Y12Z4CR12_422_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_Z4Y12Z4CB12Z4A12Z4Y12Z4CR12Z4A12_4224_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_Z4Y12Z4CB12Z4CR12_444_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIDEO_CAPTURE_FRAME_WIDTH_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIDEO_CAPTURE_FRAME_HEIGHT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIDEO_CAPTURE_FIELD_UPPER_HEIGHT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIDEO_CAPTURE_FIELD_LOWER_HEIGHT_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VIDEO_CAPTURE_SURFACE_ORIGIN_NV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OML_interlace", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTERLACE_OML", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTERLACE_READ_OML", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OML_resample", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PACK_RESAMPLE_OML", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNPACK_RESAMPLE_OML", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RESAMPLE_REPLICATE_OML", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RESAMPLE_ZERO_FILL_OML", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RESAMPLE_AVERAGE_OML", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RESAMPLE_DECIMATE_OML", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OML_subsample", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FORMAT_SUBSAMPLE_24_24_OML", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FORMAT_SUBSAMPLE_244_244_OML", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PGI_misc_hints", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PREFER_DOUBLEBUFFER_HINT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONSERVE_MEMORY_HINT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RECLAIM_MEMORY_HINT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NATIVE_GRAPHICS_HANDLE_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NATIVE_GRAPHICS_BEGIN_HINT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NATIVE_GRAPHICS_END_HINT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALWAYS_FAST_HINT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALWAYS_SOFT_HINT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALLOW_DRAW_OBJ_HINT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALLOW_DRAW_WIN_HINT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALLOW_DRAW_FRG_HINT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALLOW_DRAW_MEM_HINT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STRICT_DEPTHFUNC_HINT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STRICT_LIGHTING_HINT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_STRICT_SCISSOR_HINT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FULL_STIPPLE_HINT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLIP_NEAR_HINT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLIP_FAR_HINT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_WIDE_LINE_HINT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_BACK_NORMALS_HINT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PGI_vertex_hints", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_DATA_HINT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_CONSISTENT_HINT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MATERIAL_SIDE_HINT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_VERTEX_HINT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR3_BIT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR4_BIT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EDGEFLAG_BIT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INDEX_BIT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAT_AMBIENT_BIT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAT_AMBIENT_AND_DIFFUSE_BIT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAT_DIFFUSE_BIT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAT_EMISSION_BIT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAT_COLOR_INDEXES_BIT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAT_SHININESS_BIT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAT_SPECULAR_BIT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NORMAL_BIT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXCOORD1_BIT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXCOORD2_BIT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXCOORD3_BIT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXCOORD4_BIT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX23_BIT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX4_BIT_PGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REND_screen_coordinates", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SCREEN_COORDINATES_REND", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INVERTED_SCREEN_W_REND", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_S3_s3tc", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB_S3TC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGB4_S3TC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA_S3TC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA4_S3TC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA_DXT5_S3TC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RGBA4_DXT5_S3TC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIS_detail_texture", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DETAIL_TEXTURE_2D_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DETAIL_TEXTURE_2D_BINDING_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINEAR_DETAIL_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINEAR_DETAIL_ALPHA_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINEAR_DETAIL_COLOR_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DETAIL_TEXTURE_LEVEL_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DETAIL_TEXTURE_MODE_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DETAIL_TEXTURE_FUNC_POINTS_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIS_fog_function", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_FUNC_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_FUNC_POINTS_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_FOG_FUNC_POINTS_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIS_generate_mipmap", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GENERATE_MIPMAP_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GENERATE_MIPMAP_HINT_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIS_multisample", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MULTISAMPLE_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_ALPHA_TO_MASK_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_ALPHA_TO_ONE_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_MASK_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_1PASS_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_2PASS_0_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_2PASS_1_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_4PASS_0_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_4PASS_1_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_4PASS_2_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_4PASS_3_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_BUFFERS_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLES_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_MASK_VALUE_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_MASK_INVERT_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SAMPLE_PATTERN_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIS_pixel_texture", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_TEXTURE_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_FRAGMENT_RGB_SOURCE_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_FRAGMENT_ALPHA_SOURCE_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_GROUP_COLOR_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIS_point_line_texgen", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EYE_DISTANCE_TO_POINT_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OBJECT_DISTANCE_TO_POINT_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EYE_DISTANCE_TO_LINE_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OBJECT_DISTANCE_TO_LINE_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EYE_POINT_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OBJECT_POINT_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_EYE_LINE_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_OBJECT_LINE_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIS_point_parameters", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POINT_SIZE_MIN_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POINT_SIZE_MAX_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POINT_FADE_THRESHOLD_SIZE_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DISTANCE_ATTENUATION_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIS_sharpen_texture", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINEAR_SHARPEN_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINEAR_SHARPEN_ALPHA_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINEAR_SHARPEN_COLOR_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SHARPEN_TEXTURE_FUNC_POINTS_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIS_texture4D", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PACK_SKIP_VOLUMES_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PACK_IMAGE_DEPTH_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNPACK_SKIP_VOLUMES_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNPACK_IMAGE_DEPTH_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_4D_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROXY_TEXTURE_4D_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_4DSIZE_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_WRAP_Q_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_4D_TEXTURE_SIZE_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_4D_BINDING_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIS_texture_border_clamp", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLAMP_TO_BORDER_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIS_texture_color_mask", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COLOR_WRITEMASK_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIS_texture_edge_clamp", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CLAMP_TO_EDGE_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIS_texture_filter4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FILTER4_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_FILTER4_SIZE_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIS_texture_lod", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_MIN_LOD_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_MAX_LOD_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_BASE_LEVEL_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_MAX_LEVEL_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIS_texture_select", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DUAL_ALPHA4_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DUAL_ALPHA8_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DUAL_ALPHA12_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DUAL_ALPHA16_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DUAL_LUMINANCE4_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DUAL_LUMINANCE8_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DUAL_LUMINANCE12_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DUAL_LUMINANCE16_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DUAL_INTENSITY4_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DUAL_INTENSITY8_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DUAL_INTENSITY12_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DUAL_INTENSITY16_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DUAL_LUMINANCE_ALPHA4_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DUAL_LUMINANCE_ALPHA8_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_QUAD_ALPHA4_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_QUAD_ALPHA8_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_QUAD_LUMINANCE4_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_QUAD_LUMINANCE8_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_QUAD_INTENSITY4_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_QUAD_INTENSITY8_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DUAL_TEXTURE_SELECT_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_QUAD_TEXTURE_SELECT_SGIS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_async", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ASYNC_MARKER_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_async_histogram", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ASYNC_HISTOGRAM_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_ASYNC_HISTOGRAM_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_async_pixel", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ASYNC_TEX_IMAGE_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ASYNC_DRAW_PIXELS_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ASYNC_READ_PIXELS_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_ASYNC_TEX_IMAGE_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_ASYNC_DRAW_PIXELS_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_ASYNC_READ_PIXELS_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_blend_alpha_minmax", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA_MIN_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_ALPHA_MAX_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_calligraphic_fragment", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CALLIGRAPHIC_FRAGMENT_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_clipmap", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINEAR_CLIPMAP_LINEAR_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CLIPMAP_CENTER_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CLIPMAP_FRAME_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CLIPMAP_OFFSET_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CLIPMAP_VIRTUAL_DEPTH_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CLIPMAP_LOD_OFFSET_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CLIPMAP_DEPTH_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_CLIPMAP_DEPTH_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_CLIPMAP_VIRTUAL_DEPTH_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NEAREST_CLIPMAP_NEAREST_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_NEAREST_CLIPMAP_LINEAR_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LINEAR_CLIPMAP_NEAREST_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_convolution_accuracy", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CONVOLUTION_HINT_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_depth_pass_instrument", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_depth_texture", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_COMPONENT16_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_COMPONENT24_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEPTH_COMPONENT32_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_flush_raster", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_fog_offset", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_OFFSET_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_OFFSET_VALUE_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_fragment_lighting", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAGMENT_LIGHTING_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAGMENT_COLOR_MATERIAL_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAGMENT_COLOR_MATERIAL_FACE_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAGMENT_COLOR_MATERIAL_PARAMETER_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_FRAGMENT_LIGHTS_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_ACTIVE_LIGHTS_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_CURRENT_RASTER_NORMAL_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LIGHT_ENV_MODE_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAGMENT_LIGHT_MODEL_LOCAL_VIEWER_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAGMENT_LIGHT_MODEL_TWO_SIDE_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAGMENT_LIGHT_MODEL_AMBIENT_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAGMENT_LIGHT_MODEL_NORMAL_INTERPOLATION_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAGMENT_LIGHT0_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAGMENT_LIGHT1_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAGMENT_LIGHT2_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAGMENT_LIGHT3_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAGMENT_LIGHT4_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAGMENT_LIGHT5_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAGMENT_LIGHT6_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAGMENT_LIGHT7_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_framezoom", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEZOOM_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FRAMEZOOM_FACTOR_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_FRAMEZOOM_FACTOR_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_igloo_interface", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_instruments", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INSTRUMENT_BUFFER_POINTER_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INSTRUMENT_MEASUREMENTS_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_interlace", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_INTERLACE_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_ir_instrument1", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_IR_INSTRUMENT1_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_list_priority", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_LIST_PRIORITY_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_pixel_texture", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_TEX_GEN_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_TEX_GEN_MODE_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_pixel_tiles", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_TILE_BEST_ALIGNMENT_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_TILE_CACHE_INCREMENT_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_TILE_WIDTH_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_TILE_HEIGHT_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_TILE_GRID_WIDTH_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_TILE_GRID_HEIGHT_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_TILE_GRID_DEPTH_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_TILE_CACHE_SIZE_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_polynomial_ffd", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_DEFORMATION_BIT_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GEOMETRY_DEFORMATION_BIT_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GEOMETRY_DEFORMATION_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_DEFORMATION_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_DEFORMATIONS_MASK_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_DEFORMATION_ORDER_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_reference_plane", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REFERENCE_PLANE_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REFERENCE_PLANE_EQUATION_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_resample", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PACK_RESAMPLE_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNPACK_RESAMPLE_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RESAMPLE_REPLICATE_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RESAMPLE_ZERO_FILL_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RESAMPLE_DECIMATE_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_scalebias_hint", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SCALEBIAS_HINT_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_shadow", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COMPARE_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COMPARE_OPERATOR_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_LEQUAL_R_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_GEQUAL_R_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_shadow_ambient", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SHADOW_AMBIENT_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_sprite", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SPRITE_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SPRITE_MODE_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SPRITE_AXIS_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SPRITE_TRANSLATION_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SPRITE_AXIAL_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SPRITE_OBJECT_ALIGNED_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SPRITE_EYE_ALIGNED_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_subsample", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PACK_SUBSAMPLE_RATE_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNPACK_SUBSAMPLE_RATE_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_SUBSAMPLE_4444_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_SUBSAMPLE_2424_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PIXEL_SUBSAMPLE_4242_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_tag_sample_buffer", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_texture_add_env", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_ENV_BIAS_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_texture_coordinate_clamp", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_MAX_CLAMP_S_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_MAX_CLAMP_T_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_MAX_CLAMP_R_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_texture_lod_bias", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_LOD_BIAS_S_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_LOD_BIAS_T_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_LOD_BIAS_R_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_texture_multi_buffer", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_MULTI_BUFFER_HINT_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_texture_scale_bias", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_TEXTURE_FILTER_BIAS_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_TEXTURE_FILTER_SCALE_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_TEXTURE_FILTER_BIAS_RANGE_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_TEXTURE_FILTER_SCALE_RANGE_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_vertex_preclip", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_PRECLIP_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_VERTEX_PRECLIP_HINT_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_ycrcb", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_YCRCB_422_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_YCRCB_444_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_ycrcb_subsample", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGIX_ycrcba", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_YCRCB_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_YCRCBA_SGIX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGI_color_matrix", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_MATRIX_SGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_MATRIX_STACK_DEPTH_SGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_MAX_COLOR_MATRIX_STACK_DEPTH_SGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_COLOR_MATRIX_RED_SCALE_SGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_COLOR_MATRIX_GREEN_SCALE_SGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_COLOR_MATRIX_BLUE_SCALE_SGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_COLOR_MATRIX_ALPHA_SCALE_SGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_COLOR_MATRIX_RED_BIAS_SGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_COLOR_MATRIX_GREEN_BIAS_SGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_COLOR_MATRIX_BLUE_BIAS_SGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_COLOR_MATRIX_ALPHA_BIAS_SGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGI_color_table", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_TABLE_SGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_CONVOLUTION_COLOR_TABLE_SGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_POST_COLOR_MATRIX_COLOR_TABLE_SGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROXY_COLOR_TABLE_SGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROXY_POST_CONVOLUTION_COLOR_TABLE_SGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE_SGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_TABLE_SCALE_SGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_TABLE_BIAS_SGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_TABLE_FORMAT_SGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_TABLE_WIDTH_SGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_TABLE_RED_SIZE_SGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_TABLE_GREEN_SIZE_SGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_TABLE_BLUE_SIZE_SGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_TABLE_ALPHA_SIZE_SGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_TABLE_LUMINANCE_SIZE_SGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_COLOR_TABLE_INTENSITY_SIZE_SGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SGI_texture_color_table", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_COLOR_TABLE_SGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PROXY_TEXTURE_COLOR_TABLE_SGI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SUNX_constant_data", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_UNPACK_CONSTANT_DATA_SUNX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TEXTURE_CONSTANT_DATA_SUNX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SUN_convolution_border_modes", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_WRAP_BORDER_SUN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SUN_global_alpha", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GLOBAL_ALPHA_SUN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_GLOBAL_ALPHA_FACTOR_SUN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SUN_mesh_array", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_QUAD_MESH_SUN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRIANGLE_MESH_SUN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SUN_slice_accum", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SLICE_ACCUM_SUN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SUN_triangle_list", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_RESTART_SUN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REPLACE_MIDDLE_SUN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REPLACE_OLDEST_SUN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_TRIANGLE_LIST_SUN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REPLACEMENT_CODE_SUN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REPLACEMENT_CODE_ARRAY_SUN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REPLACEMENT_CODE_ARRAY_TYPE_SUN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REPLACEMENT_CODE_ARRAY_STRIDE_SUN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_REPLACEMENT_CODE_ARRAY_POINTER_SUN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_R1UI_V3F_SUN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_R1UI_C4UB_V3F_SUN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_R1UI_C3F_V3F_SUN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_R1UI_N3F_V3F_SUN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_R1UI_C4F_N3F_V3F_SUN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_R1UI_T2F_V3F_SUN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_R1UI_T2F_N3F_V3F_SUN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_R1UI_T2F_C4F_N3F_V3F_SUN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_SUN_vertex", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_WIN_phong_shading", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PHONG_WIN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_PHONG_HINT_WIN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_WIN_specular_fog", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GL_FOG_SPECULAR_TEXTURE_WIN", c_modifier_public | c_modifier_static | c_modifier_static_const },
/*}}}*/
#endif
};

void bic_gl_consts(location_array_s &const_locations)
{
#if defined(UCBOX_IMX6) || defined(ANDROID) || defined(NACL)
  // - insert gl basic constants -
  {/*{{{*/
    const_locations.push_blanks(303);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 303);

#define CREATE_GL_BASIC_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (basic_64b)VALUE;\
  cv_ptr++;

    CREATE_GL_BASIC_BIC_STATIC(GL_ES_VERSION_2_0);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_BUFFER_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_BUFFER_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_BUFFER_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FALSE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRUE);
    CREATE_GL_BASIC_BIC_STATIC(GL_POINTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINES);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINE_LOOP);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINE_STRIP);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRIANGLES);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRIANGLE_STRIP);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRIANGLE_FAN);
    CREATE_GL_BASIC_BIC_STATIC(GL_ZERO);
    CREATE_GL_BASIC_BIC_STATIC(GL_ONE);
    CREATE_GL_BASIC_BIC_STATIC(GL_SRC_COLOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_ONE_MINUS_SRC_COLOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_SRC_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_ONE_MINUS_SRC_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_DST_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_ONE_MINUS_DST_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_DST_COLOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_ONE_MINUS_DST_COLOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_SRC_ALPHA_SATURATE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FUNC_ADD);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLEND_EQUATION);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLEND_EQUATION_RGB);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLEND_EQUATION_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_FUNC_SUBTRACT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FUNC_REVERSE_SUBTRACT);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLEND_DST_RGB);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLEND_SRC_RGB);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLEND_DST_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLEND_SRC_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONSTANT_COLOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_ONE_MINUS_CONSTANT_COLOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONSTANT_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_ONE_MINUS_CONSTANT_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLEND_COLOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARRAY_BUFFER);
    CREATE_GL_BASIC_BIC_STATIC(GL_ELEMENT_ARRAY_BUFFER);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARRAY_BUFFER_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_ELEMENT_ARRAY_BUFFER_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_STREAM_DRAW);
    CREATE_GL_BASIC_BIC_STATIC(GL_STATIC_DRAW);
    CREATE_GL_BASIC_BIC_STATIC(GL_DYNAMIC_DRAW);
    CREATE_GL_BASIC_BIC_STATIC(GL_BUFFER_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_BUFFER_USAGE);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_VERTEX_ATTRIB);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRONT);
    CREATE_GL_BASIC_BIC_STATIC(GL_BACK);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRONT_AND_BACK);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_2D);
    CREATE_GL_BASIC_BIC_STATIC(GL_CULL_FACE);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLEND);
    CREATE_GL_BASIC_BIC_STATIC(GL_DITHER);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_TEST);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_TEST);
    CREATE_GL_BASIC_BIC_STATIC(GL_SCISSOR_TEST);
    CREATE_GL_BASIC_BIC_STATIC(GL_POLYGON_OFFSET_FILL);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_ALPHA_TO_COVERAGE);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_COVERAGE);
    CREATE_GL_BASIC_BIC_STATIC(GL_NO_ERROR);
    CREATE_GL_BASIC_BIC_STATIC(GL_INVALID_ENUM);
    CREATE_GL_BASIC_BIC_STATIC(GL_INVALID_VALUE);
    CREATE_GL_BASIC_BIC_STATIC(GL_INVALID_OPERATION);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUT_OF_MEMORY);
    CREATE_GL_BASIC_BIC_STATIC(GL_CW);
    CREATE_GL_BASIC_BIC_STATIC(GL_CCW);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINE_WIDTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALIASED_POINT_SIZE_RANGE);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALIASED_LINE_WIDTH_RANGE);
    CREATE_GL_BASIC_BIC_STATIC(GL_CULL_FACE_MODE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRONT_FACE);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_RANGE);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_WRITEMASK);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_CLEAR_VALUE);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_FUNC);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_CLEAR_VALUE);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_FUNC);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_FAIL);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_PASS_DEPTH_FAIL);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_PASS_DEPTH_PASS);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_REF);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_VALUE_MASK);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_WRITEMASK);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_BACK_FUNC);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_BACK_FAIL);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_BACK_PASS_DEPTH_FAIL);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_BACK_PASS_DEPTH_PASS);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_BACK_REF);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_BACK_VALUE_MASK);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_BACK_WRITEMASK);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIEWPORT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SCISSOR_BOX);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_CLEAR_VALUE);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_WRITEMASK);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNPACK_ALIGNMENT);
    CREATE_GL_BASIC_BIC_STATIC(GL_PACK_ALIGNMENT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TEXTURE_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VIEWPORT_DIMS);
    CREATE_GL_BASIC_BIC_STATIC(GL_SUBPIXEL_BITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_RED_BITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_GREEN_BITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLUE_BITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA_BITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_BITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_BITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_POLYGON_OFFSET_UNITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_POLYGON_OFFSET_FACTOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BINDING_2D);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_BUFFERS);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLES);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_COVERAGE_VALUE);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_COVERAGE_INVERT);
    CREATE_GL_BASIC_BIC_STATIC(GL_NUM_COMPRESSED_TEXTURE_FORMATS);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_TEXTURE_FORMATS);
    CREATE_GL_BASIC_BIC_STATIC(GL_DONT_CARE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FASTEST);
    CREATE_GL_BASIC_BIC_STATIC(GL_NICEST);
    CREATE_GL_BASIC_BIC_STATIC(GL_GENERATE_MIPMAP_HINT);
    CREATE_GL_BASIC_BIC_STATIC(GL_BYTE);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_BYTE);
    CREATE_GL_BASIC_BIC_STATIC(GL_SHORT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_SHORT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FIXED);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_COMPONENT);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_SHORT_4_4_4_4);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_SHORT_5_5_5_1);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_SHORT_5_6_5);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAGMENT_SHADER);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_SHADER);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VERTEX_ATTRIBS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VERTEX_UNIFORM_VECTORS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VARYING_VECTORS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TEXTURE_IMAGE_UNITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_FRAGMENT_UNIFORM_VECTORS);
    CREATE_GL_BASIC_BIC_STATIC(GL_SHADER_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_DELETE_STATUS);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINK_STATUS);
    CREATE_GL_BASIC_BIC_STATIC(GL_VALIDATE_STATUS);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATTACHED_SHADERS);
    CREATE_GL_BASIC_BIC_STATIC(GL_ACTIVE_UNIFORMS);
    CREATE_GL_BASIC_BIC_STATIC(GL_ACTIVE_UNIFORM_MAX_LENGTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_ACTIVE_ATTRIBUTES);
    CREATE_GL_BASIC_BIC_STATIC(GL_ACTIVE_ATTRIBUTE_MAX_LENGTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_SHADING_LANGUAGE_VERSION);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_PROGRAM);
    CREATE_GL_BASIC_BIC_STATIC(GL_NEVER);
    CREATE_GL_BASIC_BIC_STATIC(GL_LESS);
    CREATE_GL_BASIC_BIC_STATIC(GL_EQUAL);
    CREATE_GL_BASIC_BIC_STATIC(GL_LEQUAL);
    CREATE_GL_BASIC_BIC_STATIC(GL_GREATER);
    CREATE_GL_BASIC_BIC_STATIC(GL_NOTEQUAL);
    CREATE_GL_BASIC_BIC_STATIC(GL_GEQUAL);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALWAYS);
    CREATE_GL_BASIC_BIC_STATIC(GL_KEEP);
    CREATE_GL_BASIC_BIC_STATIC(GL_REPLACE);
    CREATE_GL_BASIC_BIC_STATIC(GL_INCR);
    CREATE_GL_BASIC_BIC_STATIC(GL_DECR);
    CREATE_GL_BASIC_BIC_STATIC(GL_INVERT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INCR_WRAP);
    CREATE_GL_BASIC_BIC_STATIC(GL_DECR_WRAP);
    CREATE_GL_BASIC_BIC_STATIC(GL_VENDOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERER);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERSION);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXTENSIONS);
    CREATE_GL_BASIC_BIC_STATIC(GL_NEAREST);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINEAR);
    CREATE_GL_BASIC_BIC_STATIC(GL_NEAREST_MIPMAP_NEAREST);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINEAR_MIPMAP_NEAREST);
    CREATE_GL_BASIC_BIC_STATIC(GL_NEAREST_MIPMAP_LINEAR);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINEAR_MIPMAP_LINEAR);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_MAG_FILTER);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_MIN_FILTER);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_WRAP_S);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_WRAP_T);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CUBE_MAP);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BINDING_CUBE_MAP);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CUBE_MAP_POSITIVE_X);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CUBE_MAP_NEGATIVE_X);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CUBE_MAP_POSITIVE_Y);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CUBE_MAP_POSITIVE_Z);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_CUBE_MAP_TEXTURE_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE0);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE1);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE2);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE3);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE4);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE5);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE6);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE7);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE8);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE9);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE10);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE11);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE12);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE13);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE14);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE15);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE16);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE17);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE18);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE19);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE20);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE21);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE22);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE23);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE24);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE25);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE26);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE27);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE28);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE29);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE30);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE31);
    CREATE_GL_BASIC_BIC_STATIC(GL_ACTIVE_TEXTURE);
    CREATE_GL_BASIC_BIC_STATIC(GL_REPEAT);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLAMP_TO_EDGE);
    CREATE_GL_BASIC_BIC_STATIC(GL_MIRRORED_REPEAT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_VEC2);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_VEC3);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_VEC4);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_VEC2);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_VEC3);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_VEC4);
    CREATE_GL_BASIC_BIC_STATIC(GL_BOOL);
    CREATE_GL_BASIC_BIC_STATIC(GL_BOOL_VEC2);
    CREATE_GL_BASIC_BIC_STATIC(GL_BOOL_VEC3);
    CREATE_GL_BASIC_BIC_STATIC(GL_BOOL_VEC4);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_MAT2);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_MAT3);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_MAT4);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_2D);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_CUBE);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY_ENABLED);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY_STRIDE);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY_NORMALIZED);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY_POINTER);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMPLEMENTATION_COLOR_READ_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMPLEMENTATION_COLOR_READ_FORMAT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPILE_STATUS);
    CREATE_GL_BASIC_BIC_STATIC(GL_INFO_LOG_LENGTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_SHADER_SOURCE_LENGTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_SHADER_COMPILER);
    CREATE_GL_BASIC_BIC_STATIC(GL_SHADER_BINARY_FORMATS);
    CREATE_GL_BASIC_BIC_STATIC(GL_NUM_SHADER_BINARY_FORMATS);
    CREATE_GL_BASIC_BIC_STATIC(GL_LOW_FLOAT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MEDIUM_FLOAT);
    CREATE_GL_BASIC_BIC_STATIC(GL_HIGH_FLOAT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LOW_INT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MEDIUM_INT);
    CREATE_GL_BASIC_BIC_STATIC(GL_HIGH_INT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA4);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB5_A1);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB565);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_COMPONENT16);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_INDEX);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_INDEX8);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER_WIDTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER_HEIGHT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER_INTERNAL_FORMAT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER_RED_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER_GREEN_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER_BLUE_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER_ALPHA_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER_DEPTH_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER_STENCIL_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ATTACHMENT0);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_ATTACHMENT);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_ATTACHMENT);
    CREATE_GL_BASIC_BIC_STATIC(GL_NONE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_COMPLETE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_UNSUPPORTED);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_RENDERBUFFER_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_INVALID_FRAMEBUFFER_OPERATION);
  }/*}}}*/
#elif defined(LINUX)
  // - insert gl basic constants -
  {/*{{{*/
    const_locations.push_blanks(4876);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 4876);

#define CREATE_GL_BASIC_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (basic_64b)VALUE;\
  cv_ptr++;

    CREATE_GL_BASIC_BIC_STATIC(GL_VERSION_1_1);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERSION_1_2);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERSION_1_3);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_imaging);
    CREATE_GL_BASIC_BIC_STATIC(GL_FALSE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRUE);
    CREATE_GL_BASIC_BIC_STATIC(GL_BYTE);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_BYTE);
    CREATE_GL_BASIC_BIC_STATIC(GL_SHORT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_SHORT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT);
    CREATE_GL_BASIC_BIC_STATIC(GL_2_BYTES);
    CREATE_GL_BASIC_BIC_STATIC(GL_3_BYTES);
    CREATE_GL_BASIC_BIC_STATIC(GL_4_BYTES);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOUBLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_POINTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINES);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINE_LOOP);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINE_STRIP);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRIANGLES);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRIANGLE_STRIP);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRIANGLE_FAN);
    CREATE_GL_BASIC_BIC_STATIC(GL_QUADS);
    CREATE_GL_BASIC_BIC_STATIC(GL_QUAD_STRIP);
    CREATE_GL_BASIC_BIC_STATIC(GL_POLYGON);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_NORMAL_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_INDEX_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COORD_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_EDGE_FLAG_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ARRAY_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ARRAY_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ARRAY_STRIDE);
    CREATE_GL_BASIC_BIC_STATIC(GL_NORMAL_ARRAY_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_NORMAL_ARRAY_STRIDE);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ARRAY_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ARRAY_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ARRAY_STRIDE);
    CREATE_GL_BASIC_BIC_STATIC(GL_INDEX_ARRAY_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_INDEX_ARRAY_STRIDE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COORD_ARRAY_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COORD_ARRAY_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COORD_ARRAY_STRIDE);
    CREATE_GL_BASIC_BIC_STATIC(GL_EDGE_FLAG_ARRAY_STRIDE);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ARRAY_POINTER);
    CREATE_GL_BASIC_BIC_STATIC(GL_NORMAL_ARRAY_POINTER);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ARRAY_POINTER);
    CREATE_GL_BASIC_BIC_STATIC(GL_INDEX_ARRAY_POINTER);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COORD_ARRAY_POINTER);
    CREATE_GL_BASIC_BIC_STATIC(GL_EDGE_FLAG_ARRAY_POINTER);
    CREATE_GL_BASIC_BIC_STATIC(GL_V2F);
    CREATE_GL_BASIC_BIC_STATIC(GL_V3F);
    CREATE_GL_BASIC_BIC_STATIC(GL_C4UB_V2F);
    CREATE_GL_BASIC_BIC_STATIC(GL_C4UB_V3F);
    CREATE_GL_BASIC_BIC_STATIC(GL_C3F_V3F);
    CREATE_GL_BASIC_BIC_STATIC(GL_N3F_V3F);
    CREATE_GL_BASIC_BIC_STATIC(GL_C4F_N3F_V3F);
    CREATE_GL_BASIC_BIC_STATIC(GL_T2F_V3F);
    CREATE_GL_BASIC_BIC_STATIC(GL_T4F_V4F);
    CREATE_GL_BASIC_BIC_STATIC(GL_T2F_C4UB_V3F);
    CREATE_GL_BASIC_BIC_STATIC(GL_T2F_C3F_V3F);
    CREATE_GL_BASIC_BIC_STATIC(GL_T2F_N3F_V3F);
    CREATE_GL_BASIC_BIC_STATIC(GL_T2F_C4F_N3F_V3F);
    CREATE_GL_BASIC_BIC_STATIC(GL_T4F_C4F_N3F_V4F);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX_MODE);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROJECTION);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE);
    CREATE_GL_BASIC_BIC_STATIC(GL_POINT_SMOOTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_POINT_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_POINT_SIZE_GRANULARITY);
    CREATE_GL_BASIC_BIC_STATIC(GL_POINT_SIZE_RANGE);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINE_SMOOTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINE_STIPPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINE_STIPPLE_PATTERN);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINE_STIPPLE_REPEAT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINE_WIDTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINE_WIDTH_GRANULARITY);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINE_WIDTH_RANGE);
    CREATE_GL_BASIC_BIC_STATIC(GL_POINT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FILL);
    CREATE_GL_BASIC_BIC_STATIC(GL_CW);
    CREATE_GL_BASIC_BIC_STATIC(GL_CCW);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRONT);
    CREATE_GL_BASIC_BIC_STATIC(GL_BACK);
    CREATE_GL_BASIC_BIC_STATIC(GL_POLYGON_MODE);
    CREATE_GL_BASIC_BIC_STATIC(GL_POLYGON_SMOOTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_POLYGON_STIPPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_EDGE_FLAG);
    CREATE_GL_BASIC_BIC_STATIC(GL_CULL_FACE);
    CREATE_GL_BASIC_BIC_STATIC(GL_CULL_FACE_MODE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRONT_FACE);
    CREATE_GL_BASIC_BIC_STATIC(GL_POLYGON_OFFSET_FACTOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_POLYGON_OFFSET_UNITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_POLYGON_OFFSET_POINT);
    CREATE_GL_BASIC_BIC_STATIC(GL_POLYGON_OFFSET_LINE);
    CREATE_GL_BASIC_BIC_STATIC(GL_POLYGON_OFFSET_FILL);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPILE);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPILE_AND_EXECUTE);
    CREATE_GL_BASIC_BIC_STATIC(GL_LIST_BASE);
    CREATE_GL_BASIC_BIC_STATIC(GL_LIST_INDEX);
    CREATE_GL_BASIC_BIC_STATIC(GL_LIST_MODE);
    CREATE_GL_BASIC_BIC_STATIC(GL_NEVER);
    CREATE_GL_BASIC_BIC_STATIC(GL_LESS);
    CREATE_GL_BASIC_BIC_STATIC(GL_EQUAL);
    CREATE_GL_BASIC_BIC_STATIC(GL_LEQUAL);
    CREATE_GL_BASIC_BIC_STATIC(GL_GREATER);
    CREATE_GL_BASIC_BIC_STATIC(GL_NOTEQUAL);
    CREATE_GL_BASIC_BIC_STATIC(GL_GEQUAL);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALWAYS);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_TEST);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_BITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_CLEAR_VALUE);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_FUNC);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_RANGE);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_WRITEMASK);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_COMPONENT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LIGHTING);
    CREATE_GL_BASIC_BIC_STATIC(GL_LIGHT0);
    CREATE_GL_BASIC_BIC_STATIC(GL_LIGHT1);
    CREATE_GL_BASIC_BIC_STATIC(GL_LIGHT2);
    CREATE_GL_BASIC_BIC_STATIC(GL_LIGHT3);
    CREATE_GL_BASIC_BIC_STATIC(GL_LIGHT4);
    CREATE_GL_BASIC_BIC_STATIC(GL_LIGHT5);
    CREATE_GL_BASIC_BIC_STATIC(GL_LIGHT6);
    CREATE_GL_BASIC_BIC_STATIC(GL_LIGHT7);
    CREATE_GL_BASIC_BIC_STATIC(GL_SPOT_EXPONENT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SPOT_CUTOFF);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONSTANT_ATTENUATION);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINEAR_ATTENUATION);
    CREATE_GL_BASIC_BIC_STATIC(GL_QUADRATIC_ATTENUATION);
    CREATE_GL_BASIC_BIC_STATIC(GL_AMBIENT);
    CREATE_GL_BASIC_BIC_STATIC(GL_DIFFUSE);
    CREATE_GL_BASIC_BIC_STATIC(GL_SPECULAR);
    CREATE_GL_BASIC_BIC_STATIC(GL_SHININESS);
    CREATE_GL_BASIC_BIC_STATIC(GL_EMISSION);
    CREATE_GL_BASIC_BIC_STATIC(GL_POSITION);
    CREATE_GL_BASIC_BIC_STATIC(GL_SPOT_DIRECTION);
    CREATE_GL_BASIC_BIC_STATIC(GL_AMBIENT_AND_DIFFUSE);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_INDEXES);
    CREATE_GL_BASIC_BIC_STATIC(GL_LIGHT_MODEL_TWO_SIDE);
    CREATE_GL_BASIC_BIC_STATIC(GL_LIGHT_MODEL_LOCAL_VIEWER);
    CREATE_GL_BASIC_BIC_STATIC(GL_LIGHT_MODEL_AMBIENT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRONT_AND_BACK);
    CREATE_GL_BASIC_BIC_STATIC(GL_SHADE_MODEL);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLAT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SMOOTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_MATERIAL);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_MATERIAL_FACE);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_MATERIAL_PARAMETER);
    CREATE_GL_BASIC_BIC_STATIC(GL_NORMALIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLIP_PLANE0);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLIP_PLANE1);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLIP_PLANE2);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLIP_PLANE3);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLIP_PLANE4);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLIP_PLANE5);
    CREATE_GL_BASIC_BIC_STATIC(GL_ACCUM_RED_BITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_ACCUM_GREEN_BITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_ACCUM_BLUE_BITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_ACCUM_ALPHA_BITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_ACCUM_CLEAR_VALUE);
    CREATE_GL_BASIC_BIC_STATIC(GL_ACCUM);
    CREATE_GL_BASIC_BIC_STATIC(GL_ADD);
    CREATE_GL_BASIC_BIC_STATIC(GL_LOAD);
    CREATE_GL_BASIC_BIC_STATIC(GL_MULT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RETURN);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA_TEST);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA_TEST_REF);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA_TEST_FUNC);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLEND);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLEND_SRC);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLEND_DST);
    CREATE_GL_BASIC_BIC_STATIC(GL_ZERO);
    CREATE_GL_BASIC_BIC_STATIC(GL_ONE);
    CREATE_GL_BASIC_BIC_STATIC(GL_SRC_COLOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_ONE_MINUS_SRC_COLOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_SRC_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_ONE_MINUS_SRC_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_DST_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_ONE_MINUS_DST_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_DST_COLOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_ONE_MINUS_DST_COLOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_SRC_ALPHA_SATURATE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FEEDBACK);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDER);
    CREATE_GL_BASIC_BIC_STATIC(GL_SELECT);
    CREATE_GL_BASIC_BIC_STATIC(GL_2D);
    CREATE_GL_BASIC_BIC_STATIC(GL_3D);
    CREATE_GL_BASIC_BIC_STATIC(GL_3D_COLOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_3D_COLOR_TEXTURE);
    CREATE_GL_BASIC_BIC_STATIC(GL_4D_COLOR_TEXTURE);
    CREATE_GL_BASIC_BIC_STATIC(GL_POINT_TOKEN);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINE_TOKEN);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINE_RESET_TOKEN);
    CREATE_GL_BASIC_BIC_STATIC(GL_POLYGON_TOKEN);
    CREATE_GL_BASIC_BIC_STATIC(GL_BITMAP_TOKEN);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_PIXEL_TOKEN);
    CREATE_GL_BASIC_BIC_STATIC(GL_COPY_PIXEL_TOKEN);
    CREATE_GL_BASIC_BIC_STATIC(GL_PASS_THROUGH_TOKEN);
    CREATE_GL_BASIC_BIC_STATIC(GL_FEEDBACK_BUFFER_POINTER);
    CREATE_GL_BASIC_BIC_STATIC(GL_FEEDBACK_BUFFER_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FEEDBACK_BUFFER_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_SELECTION_BUFFER_POINTER);
    CREATE_GL_BASIC_BIC_STATIC(GL_SELECTION_BUFFER_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_MODE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_DENSITY);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_COLOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_INDEX);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_START);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_END);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINEAR);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXP);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXP2);
    CREATE_GL_BASIC_BIC_STATIC(GL_LOGIC_OP);
    CREATE_GL_BASIC_BIC_STATIC(GL_INDEX_LOGIC_OP);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_LOGIC_OP);
    CREATE_GL_BASIC_BIC_STATIC(GL_LOGIC_OP_MODE);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLEAR);
    CREATE_GL_BASIC_BIC_STATIC(GL_SET);
    CREATE_GL_BASIC_BIC_STATIC(GL_COPY);
    CREATE_GL_BASIC_BIC_STATIC(GL_COPY_INVERTED);
    CREATE_GL_BASIC_BIC_STATIC(GL_NOOP);
    CREATE_GL_BASIC_BIC_STATIC(GL_INVERT);
    CREATE_GL_BASIC_BIC_STATIC(GL_AND);
    CREATE_GL_BASIC_BIC_STATIC(GL_NAND);
    CREATE_GL_BASIC_BIC_STATIC(GL_OR);
    CREATE_GL_BASIC_BIC_STATIC(GL_NOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_XOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_EQUIV);
    CREATE_GL_BASIC_BIC_STATIC(GL_AND_REVERSE);
    CREATE_GL_BASIC_BIC_STATIC(GL_AND_INVERTED);
    CREATE_GL_BASIC_BIC_STATIC(GL_OR_REVERSE);
    CREATE_GL_BASIC_BIC_STATIC(GL_OR_INVERTED);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_BITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_TEST);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_CLEAR_VALUE);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_FUNC);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_VALUE_MASK);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_FAIL);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_PASS_DEPTH_FAIL);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_PASS_DEPTH_PASS);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_REF);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_WRITEMASK);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_INDEX);
    CREATE_GL_BASIC_BIC_STATIC(GL_KEEP);
    CREATE_GL_BASIC_BIC_STATIC(GL_REPLACE);
    CREATE_GL_BASIC_BIC_STATIC(GL_INCR);
    CREATE_GL_BASIC_BIC_STATIC(GL_DECR);
    CREATE_GL_BASIC_BIC_STATIC(GL_NONE);
    CREATE_GL_BASIC_BIC_STATIC(GL_LEFT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RIGHT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRONT_LEFT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRONT_RIGHT);
    CREATE_GL_BASIC_BIC_STATIC(GL_BACK_LEFT);
    CREATE_GL_BASIC_BIC_STATIC(GL_BACK_RIGHT);
    CREATE_GL_BASIC_BIC_STATIC(GL_AUX0);
    CREATE_GL_BASIC_BIC_STATIC(GL_AUX1);
    CREATE_GL_BASIC_BIC_STATIC(GL_AUX2);
    CREATE_GL_BASIC_BIC_STATIC(GL_AUX3);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_INDEX);
    CREATE_GL_BASIC_BIC_STATIC(GL_RED);
    CREATE_GL_BASIC_BIC_STATIC(GL_GREEN);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLUE);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA_BITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_RED_BITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_GREEN_BITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLUE_BITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_INDEX_BITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_SUBPIXEL_BITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_AUX_BUFFERS);
    CREATE_GL_BASIC_BIC_STATIC(GL_READ_BUFFER);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOUBLEBUFFER);
    CREATE_GL_BASIC_BIC_STATIC(GL_STEREO);
    CREATE_GL_BASIC_BIC_STATIC(GL_BITMAP);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL);
    CREATE_GL_BASIC_BIC_STATIC(GL_DITHER);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_LIST_NESTING);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_EVAL_ORDER);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_LIGHTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_CLIP_PLANES);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TEXTURE_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PIXEL_MAP_TABLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_ATTRIB_STACK_DEPTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_MODELVIEW_STACK_DEPTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_NAME_STACK_DEPTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROJECTION_STACK_DEPTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TEXTURE_STACK_DEPTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VIEWPORT_DIMS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_CLIENT_ATTRIB_STACK_DEPTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATTRIB_STACK_DEPTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLIENT_ATTRIB_STACK_DEPTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_CLEAR_VALUE);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_WRITEMASK);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_INDEX);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_COLOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_NORMAL);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_RASTER_COLOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_RASTER_DISTANCE);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_RASTER_INDEX);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_RASTER_POSITION);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_RASTER_TEXTURE_COORDS);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_RASTER_POSITION_VALID);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_TEXTURE_COORDS);
    CREATE_GL_BASIC_BIC_STATIC(GL_INDEX_CLEAR_VALUE);
    CREATE_GL_BASIC_BIC_STATIC(GL_INDEX_MODE);
    CREATE_GL_BASIC_BIC_STATIC(GL_INDEX_WRITEMASK);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW_MATRIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW_STACK_DEPTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_NAME_STACK_DEPTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROJECTION_MATRIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROJECTION_STACK_DEPTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDER_MODE);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA_MODE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_MATRIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_STACK_DEPTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIEWPORT);
    CREATE_GL_BASIC_BIC_STATIC(GL_AUTO_NORMAL);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP1_COLOR_4);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP1_INDEX);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP1_NORMAL);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP1_TEXTURE_COORD_1);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP1_TEXTURE_COORD_2);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP1_TEXTURE_COORD_3);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP1_TEXTURE_COORD_4);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP1_VERTEX_3);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP1_VERTEX_4);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP2_COLOR_4);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP2_INDEX);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP2_NORMAL);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP2_TEXTURE_COORD_1);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP2_TEXTURE_COORD_2);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP2_TEXTURE_COORD_3);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP2_TEXTURE_COORD_4);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP2_VERTEX_3);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP2_VERTEX_4);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP1_GRID_DOMAIN);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP1_GRID_SEGMENTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP2_GRID_DOMAIN);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP2_GRID_SEGMENTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_COEFF);
    CREATE_GL_BASIC_BIC_STATIC(GL_ORDER);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOMAIN);
    CREATE_GL_BASIC_BIC_STATIC(GL_PERSPECTIVE_CORRECTION_HINT);
    CREATE_GL_BASIC_BIC_STATIC(GL_POINT_SMOOTH_HINT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINE_SMOOTH_HINT);
    CREATE_GL_BASIC_BIC_STATIC(GL_POLYGON_SMOOTH_HINT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_HINT);
    CREATE_GL_BASIC_BIC_STATIC(GL_DONT_CARE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FASTEST);
    CREATE_GL_BASIC_BIC_STATIC(GL_NICEST);
    CREATE_GL_BASIC_BIC_STATIC(GL_SCISSOR_BOX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SCISSOR_TEST);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP_COLOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP_STENCIL);
    CREATE_GL_BASIC_BIC_STATIC(GL_INDEX_SHIFT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INDEX_OFFSET);
    CREATE_GL_BASIC_BIC_STATIC(GL_RED_SCALE);
    CREATE_GL_BASIC_BIC_STATIC(GL_RED_BIAS);
    CREATE_GL_BASIC_BIC_STATIC(GL_GREEN_SCALE);
    CREATE_GL_BASIC_BIC_STATIC(GL_GREEN_BIAS);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLUE_SCALE);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLUE_BIAS);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA_SCALE);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA_BIAS);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_SCALE);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_BIAS);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_MAP_S_TO_S_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_MAP_I_TO_I_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_MAP_I_TO_R_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_MAP_I_TO_G_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_MAP_I_TO_B_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_MAP_I_TO_A_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_MAP_R_TO_R_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_MAP_G_TO_G_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_MAP_B_TO_B_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_MAP_A_TO_A_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_MAP_S_TO_S);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_MAP_I_TO_I);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_MAP_I_TO_R);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_MAP_I_TO_G);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_MAP_I_TO_B);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_MAP_I_TO_A);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_MAP_R_TO_R);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_MAP_G_TO_G);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_MAP_B_TO_B);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_MAP_A_TO_A);
    CREATE_GL_BASIC_BIC_STATIC(GL_PACK_ALIGNMENT);
    CREATE_GL_BASIC_BIC_STATIC(GL_PACK_LSB_FIRST);
    CREATE_GL_BASIC_BIC_STATIC(GL_PACK_ROW_LENGTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_PACK_SKIP_PIXELS);
    CREATE_GL_BASIC_BIC_STATIC(GL_PACK_SKIP_ROWS);
    CREATE_GL_BASIC_BIC_STATIC(GL_PACK_SWAP_BYTES);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNPACK_ALIGNMENT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNPACK_LSB_FIRST);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNPACK_ROW_LENGTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNPACK_SKIP_PIXELS);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNPACK_SKIP_ROWS);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNPACK_SWAP_BYTES);
    CREATE_GL_BASIC_BIC_STATIC(GL_ZOOM_X);
    CREATE_GL_BASIC_BIC_STATIC(GL_ZOOM_Y);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_ENV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_ENV_MODE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_1D);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_2D);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_WRAP_S);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_WRAP_T);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_MAG_FILTER);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_MIN_FILTER);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_ENV_COLOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_GEN_S);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_GEN_T);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_GEN_R);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_GEN_Q);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_GEN_MODE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BORDER_COLOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_WIDTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_HEIGHT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BORDER);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COMPONENTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_RED_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_GREEN_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BLUE_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_ALPHA_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_LUMINANCE_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_INTENSITY_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_NEAREST_MIPMAP_NEAREST);
    CREATE_GL_BASIC_BIC_STATIC(GL_NEAREST_MIPMAP_LINEAR);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINEAR_MIPMAP_NEAREST);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINEAR_MIPMAP_LINEAR);
    CREATE_GL_BASIC_BIC_STATIC(GL_OBJECT_LINEAR);
    CREATE_GL_BASIC_BIC_STATIC(GL_OBJECT_PLANE);
    CREATE_GL_BASIC_BIC_STATIC(GL_EYE_LINEAR);
    CREATE_GL_BASIC_BIC_STATIC(GL_EYE_PLANE);
    CREATE_GL_BASIC_BIC_STATIC(GL_SPHERE_MAP);
    CREATE_GL_BASIC_BIC_STATIC(GL_DECAL);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODULATE);
    CREATE_GL_BASIC_BIC_STATIC(GL_NEAREST);
    CREATE_GL_BASIC_BIC_STATIC(GL_REPEAT);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLAMP);
    CREATE_GL_BASIC_BIC_STATIC(GL_S);
    CREATE_GL_BASIC_BIC_STATIC(GL_T);
    CREATE_GL_BASIC_BIC_STATIC(GL_R);
    CREATE_GL_BASIC_BIC_STATIC(GL_Q);
    CREATE_GL_BASIC_BIC_STATIC(GL_VENDOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERER);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERSION);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXTENSIONS);
    CREATE_GL_BASIC_BIC_STATIC(GL_NO_ERROR);
    CREATE_GL_BASIC_BIC_STATIC(GL_INVALID_ENUM);
    CREATE_GL_BASIC_BIC_STATIC(GL_INVALID_VALUE);
    CREATE_GL_BASIC_BIC_STATIC(GL_INVALID_OPERATION);
    CREATE_GL_BASIC_BIC_STATIC(GL_STACK_OVERFLOW);
    CREATE_GL_BASIC_BIC_STATIC(GL_STACK_UNDERFLOW);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUT_OF_MEMORY);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_POINT_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINE_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_POLYGON_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_POLYGON_STIPPLE_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_MODE_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LIGHTING_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_BUFFER_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_ACCUM_BUFFER_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_BUFFER_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIEWPORT_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_ENABLE_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_BUFFER_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_HINT_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EVAL_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LIST_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SCISSOR_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALL_ATTRIB_BITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROXY_TEXTURE_1D);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROXY_TEXTURE_2D);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_PRIORITY);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_RESIDENT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BINDING_1D);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BINDING_2D);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_INTERNAL_FORMAT);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA4);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA8);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA12);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA16);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE4);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE8);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE12);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE16);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE4_ALPHA4);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE6_ALPHA2);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE8_ALPHA8);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE12_ALPHA4);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE12_ALPHA12);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE16_ALPHA16);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTENSITY);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTENSITY4);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTENSITY8);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTENSITY12);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTENSITY16);
    CREATE_GL_BASIC_BIC_STATIC(GL_R3_G3_B2);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB4);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB5);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB8);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB10);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB12);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB16);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA2);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA4);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB5_A1);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA8);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB10_A2);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA12);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA16);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLIENT_PIXEL_STORE_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLIENT_VERTEX_ARRAY_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALL_CLIENT_ATTRIB_BITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLIENT_ALL_ATTRIB_BITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_RESCALE_NORMAL);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLAMP_TO_EDGE);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_ELEMENTS_VERTICES);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_ELEMENTS_INDICES);
    CREATE_GL_BASIC_BIC_STATIC(GL_BGR);
    CREATE_GL_BASIC_BIC_STATIC(GL_BGRA);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_BYTE_3_3_2);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_BYTE_2_3_3_REV);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_SHORT_5_6_5);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_SHORT_5_6_5_REV);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_SHORT_4_4_4_4);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_SHORT_4_4_4_4_REV);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_SHORT_5_5_5_1);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_SHORT_1_5_5_5_REV);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_8_8_8_8);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_8_8_8_8_REV);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_10_10_10_2);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_2_10_10_10_REV);
    CREATE_GL_BASIC_BIC_STATIC(GL_LIGHT_MODEL_COLOR_CONTROL);
    CREATE_GL_BASIC_BIC_STATIC(GL_SINGLE_COLOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_SEPARATE_SPECULAR_COLOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_MIN_LOD);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_MAX_LOD);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BASE_LEVEL);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_MAX_LEVEL);
    CREATE_GL_BASIC_BIC_STATIC(GL_SMOOTH_POINT_SIZE_RANGE);
    CREATE_GL_BASIC_BIC_STATIC(GL_SMOOTH_POINT_SIZE_GRANULARITY);
    CREATE_GL_BASIC_BIC_STATIC(GL_SMOOTH_LINE_WIDTH_RANGE);
    CREATE_GL_BASIC_BIC_STATIC(GL_SMOOTH_LINE_WIDTH_GRANULARITY);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALIASED_POINT_SIZE_RANGE);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALIASED_LINE_WIDTH_RANGE);
    CREATE_GL_BASIC_BIC_STATIC(GL_PACK_SKIP_IMAGES);
    CREATE_GL_BASIC_BIC_STATIC(GL_PACK_IMAGE_HEIGHT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNPACK_SKIP_IMAGES);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNPACK_IMAGE_HEIGHT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_3D);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROXY_TEXTURE_3D);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_DEPTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_WRAP_R);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_3D_TEXTURE_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BINDING_3D);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONSTANT_COLOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_ONE_MINUS_CONSTANT_COLOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONSTANT_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_ONE_MINUS_CONSTANT_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_TABLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_CONVOLUTION_COLOR_TABLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_COLOR_MATRIX_COLOR_TABLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROXY_COLOR_TABLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROXY_POST_CONVOLUTION_COLOR_TABLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_TABLE_SCALE);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_TABLE_BIAS);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_TABLE_FORMAT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_TABLE_WIDTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_TABLE_RED_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_TABLE_GREEN_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_TABLE_BLUE_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_TABLE_ALPHA_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_TABLE_LUMINANCE_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_TABLE_INTENSITY_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONVOLUTION_1D);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONVOLUTION_2D);
    CREATE_GL_BASIC_BIC_STATIC(GL_SEPARABLE_2D);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONVOLUTION_BORDER_MODE);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONVOLUTION_FILTER_SCALE);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONVOLUTION_FILTER_BIAS);
    CREATE_GL_BASIC_BIC_STATIC(GL_REDUCE);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONVOLUTION_FORMAT);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONVOLUTION_WIDTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONVOLUTION_HEIGHT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_CONVOLUTION_WIDTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_CONVOLUTION_HEIGHT);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_CONVOLUTION_RED_SCALE);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_CONVOLUTION_GREEN_SCALE);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_CONVOLUTION_BLUE_SCALE);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_CONVOLUTION_ALPHA_SCALE);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_CONVOLUTION_RED_BIAS);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_CONVOLUTION_GREEN_BIAS);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_CONVOLUTION_BLUE_BIAS);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_CONVOLUTION_ALPHA_BIAS);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONSTANT_BORDER);
    CREATE_GL_BASIC_BIC_STATIC(GL_REPLICATE_BORDER);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONVOLUTION_BORDER_COLOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_MATRIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_MATRIX_STACK_DEPTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_COLOR_MATRIX_STACK_DEPTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_COLOR_MATRIX_RED_SCALE);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_COLOR_MATRIX_GREEN_SCALE);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_COLOR_MATRIX_BLUE_SCALE);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_COLOR_MATRIX_ALPHA_SCALE);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_COLOR_MATRIX_RED_BIAS);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_COLOR_MATRIX_GREEN_BIAS);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_COLOR_MATRIX_BLUE_BIAS);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_COLOR_MATRIX_ALPHA_BIAS);
    CREATE_GL_BASIC_BIC_STATIC(GL_HISTOGRAM);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROXY_HISTOGRAM);
    CREATE_GL_BASIC_BIC_STATIC(GL_HISTOGRAM_WIDTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_HISTOGRAM_FORMAT);
    CREATE_GL_BASIC_BIC_STATIC(GL_HISTOGRAM_RED_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_HISTOGRAM_GREEN_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_HISTOGRAM_BLUE_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_HISTOGRAM_ALPHA_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_HISTOGRAM_LUMINANCE_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_HISTOGRAM_SINK);
    CREATE_GL_BASIC_BIC_STATIC(GL_MINMAX);
    CREATE_GL_BASIC_BIC_STATIC(GL_MINMAX_FORMAT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MINMAX_SINK);
    CREATE_GL_BASIC_BIC_STATIC(GL_TABLE_TOO_LARGE);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLEND_EQUATION);
    CREATE_GL_BASIC_BIC_STATIC(GL_MIN);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX);
    CREATE_GL_BASIC_BIC_STATIC(GL_FUNC_ADD);
    CREATE_GL_BASIC_BIC_STATIC(GL_FUNC_SUBTRACT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FUNC_REVERSE_SUBTRACT);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLEND_COLOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE0);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE1);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE2);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE3);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE4);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE5);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE6);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE7);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE8);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE9);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE10);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE11);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE12);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE13);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE14);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE15);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE16);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE17);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE18);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE19);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE20);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE21);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE22);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE23);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE24);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE25);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE26);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE27);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE28);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE29);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE30);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE31);
    CREATE_GL_BASIC_BIC_STATIC(GL_ACTIVE_TEXTURE);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLIENT_ACTIVE_TEXTURE);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TEXTURE_UNITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_NORMAL_MAP);
    CREATE_GL_BASIC_BIC_STATIC(GL_REFLECTION_MAP);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CUBE_MAP);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BINDING_CUBE_MAP);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CUBE_MAP_POSITIVE_X);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CUBE_MAP_NEGATIVE_X);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CUBE_MAP_POSITIVE_Y);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CUBE_MAP_POSITIVE_Z);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROXY_TEXTURE_CUBE_MAP);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_CUBE_MAP_TEXTURE_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_LUMINANCE);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_LUMINANCE_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_INTENSITY);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_RGB);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_RGBA);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COMPRESSION_HINT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COMPRESSED_IMAGE_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COMPRESSED);
    CREATE_GL_BASIC_BIC_STATIC(GL_NUM_COMPRESSED_TEXTURE_FORMATS);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_TEXTURE_FORMATS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MULTISAMPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_ALPHA_TO_COVERAGE);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_ALPHA_TO_ONE);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_COVERAGE);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_BUFFERS);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLES);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_COVERAGE_VALUE);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_COVERAGE_INVERT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MULTISAMPLE_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSPOSE_MODELVIEW_MATRIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSPOSE_PROJECTION_MATRIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSPOSE_TEXTURE_MATRIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSPOSE_COLOR_MATRIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMBINE);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMBINE_RGB);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMBINE_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_SOURCE0_RGB);
    CREATE_GL_BASIC_BIC_STATIC(GL_SOURCE1_RGB);
    CREATE_GL_BASIC_BIC_STATIC(GL_SOURCE2_RGB);
    CREATE_GL_BASIC_BIC_STATIC(GL_SOURCE0_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_SOURCE1_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_SOURCE2_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_OPERAND0_RGB);
    CREATE_GL_BASIC_BIC_STATIC(GL_OPERAND1_RGB);
    CREATE_GL_BASIC_BIC_STATIC(GL_OPERAND2_RGB);
    CREATE_GL_BASIC_BIC_STATIC(GL_OPERAND0_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_OPERAND1_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_OPERAND2_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB_SCALE);
    CREATE_GL_BASIC_BIC_STATIC(GL_ADD_SIGNED);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTERPOLATE);
    CREATE_GL_BASIC_BIC_STATIC(GL_SUBTRACT);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONSTANT);
    CREATE_GL_BASIC_BIC_STATIC(GL_PRIMARY_COLOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_PREVIOUS);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOT3_RGB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOT3_RGBA);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLAMP_TO_BORDER);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_multitexture);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE0_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE1_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE2_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE3_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE4_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE5_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE6_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE7_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE8_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE9_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE10_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE11_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE12_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE13_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE14_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE15_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE16_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE17_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE18_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE19_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE20_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE21_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE22_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE23_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE24_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE25_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE26_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE27_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE28_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE29_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE30_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE31_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ACTIVE_TEXTURE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLIENT_ACTIVE_TEXTURE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TEXTURE_UNITS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MESA_packed_depth_stencil);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_STENCIL_MESA);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_24_8_MESA);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_8_24_REV_MESA);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_SHORT_15_1_MESA);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_SHORT_1_15_REV_MESA);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_1D_ARRAY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROXY_TEXTURE_1D_ARRAY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_2D_ARRAY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROXY_TEXTURE_2D_ARRAY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BINDING_1D_ARRAY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BINDING_2D_ARRAY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_ARRAY_TEXTURE_LAYERS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATI_blend_equation_separate);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA_BLEND_EQUATION_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_OES_EGL_image);
    CREATE_GL_BASIC_BIC_STATIC(GL_GLEXT_VERSION);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERSION_1_4);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLEND_DST_RGB);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLEND_SRC_RGB);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLEND_DST_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLEND_SRC_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_POINT_FADE_THRESHOLD_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_COMPONENT16);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_COMPONENT24);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_COMPONENT32);
    CREATE_GL_BASIC_BIC_STATIC(GL_MIRRORED_REPEAT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TEXTURE_LOD_BIAS);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_LOD_BIAS);
    CREATE_GL_BASIC_BIC_STATIC(GL_INCR_WRAP);
    CREATE_GL_BASIC_BIC_STATIC(GL_DECR_WRAP);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_DEPTH_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COMPARE_MODE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COMPARE_FUNC);
    CREATE_GL_BASIC_BIC_STATIC(GL_POINT_SIZE_MIN);
    CREATE_GL_BASIC_BIC_STATIC(GL_POINT_SIZE_MAX);
    CREATE_GL_BASIC_BIC_STATIC(GL_POINT_DISTANCE_ATTENUATION);
    CREATE_GL_BASIC_BIC_STATIC(GL_GENERATE_MIPMAP);
    CREATE_GL_BASIC_BIC_STATIC(GL_GENERATE_MIPMAP_HINT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_COORDINATE_SOURCE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_COORDINATE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAGMENT_DEPTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_FOG_COORDINATE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_COORDINATE_ARRAY_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_COORDINATE_ARRAY_STRIDE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_COORDINATE_ARRAY_POINTER);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_COORDINATE_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_SUM);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_SECONDARY_COLOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_SECONDARY_COLOR_ARRAY_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_SECONDARY_COLOR_ARRAY_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_SECONDARY_COLOR_ARRAY_STRIDE);
    CREATE_GL_BASIC_BIC_STATIC(GL_SECONDARY_COLOR_ARRAY_POINTER);
    CREATE_GL_BASIC_BIC_STATIC(GL_SECONDARY_COLOR_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_FILTER_CONTROL);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_TEXTURE_MODE);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPARE_R_TO_TEXTURE);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERSION_1_5);
    CREATE_GL_BASIC_BIC_STATIC(GL_BUFFER_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_BUFFER_USAGE);
    CREATE_GL_BASIC_BIC_STATIC(GL_QUERY_COUNTER_BITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_QUERY);
    CREATE_GL_BASIC_BIC_STATIC(GL_QUERY_RESULT);
    CREATE_GL_BASIC_BIC_STATIC(GL_QUERY_RESULT_AVAILABLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARRAY_BUFFER);
    CREATE_GL_BASIC_BIC_STATIC(GL_ELEMENT_ARRAY_BUFFER);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARRAY_BUFFER_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_ELEMENT_ARRAY_BUFFER_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_READ_ONLY);
    CREATE_GL_BASIC_BIC_STATIC(GL_WRITE_ONLY);
    CREATE_GL_BASIC_BIC_STATIC(GL_READ_WRITE);
    CREATE_GL_BASIC_BIC_STATIC(GL_BUFFER_ACCESS);
    CREATE_GL_BASIC_BIC_STATIC(GL_BUFFER_MAPPED);
    CREATE_GL_BASIC_BIC_STATIC(GL_BUFFER_MAP_POINTER);
    CREATE_GL_BASIC_BIC_STATIC(GL_STREAM_DRAW);
    CREATE_GL_BASIC_BIC_STATIC(GL_STREAM_READ);
    CREATE_GL_BASIC_BIC_STATIC(GL_STREAM_COPY);
    CREATE_GL_BASIC_BIC_STATIC(GL_STATIC_DRAW);
    CREATE_GL_BASIC_BIC_STATIC(GL_STATIC_READ);
    CREATE_GL_BASIC_BIC_STATIC(GL_STATIC_COPY);
    CREATE_GL_BASIC_BIC_STATIC(GL_DYNAMIC_DRAW);
    CREATE_GL_BASIC_BIC_STATIC(GL_DYNAMIC_READ);
    CREATE_GL_BASIC_BIC_STATIC(GL_DYNAMIC_COPY);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLES_PASSED);
    CREATE_GL_BASIC_BIC_STATIC(GL_SRC1_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ARRAY_BUFFER_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_NORMAL_ARRAY_BUFFER_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ARRAY_BUFFER_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_INDEX_ARRAY_BUFFER_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_EDGE_FLAG_ARRAY_BUFFER_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_WEIGHT_ARRAY_BUFFER_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_COORD_SRC);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_COORD);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_FOG_COORD);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_COORD_ARRAY_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_COORD_ARRAY_STRIDE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_COORD_ARRAY_POINTER);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_COORD_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_COORD_ARRAY_BUFFER_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_SRC0_RGB);
    CREATE_GL_BASIC_BIC_STATIC(GL_SRC1_RGB);
    CREATE_GL_BASIC_BIC_STATIC(GL_SRC2_RGB);
    CREATE_GL_BASIC_BIC_STATIC(GL_SRC0_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_SRC2_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERSION_2_0);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLEND_EQUATION_RGB);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY_ENABLED);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY_STRIDE);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_VERTEX_ATTRIB);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_PROGRAM_POINT_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY_POINTER);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_BACK_FUNC);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_BACK_FAIL);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_BACK_PASS_DEPTH_FAIL);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_BACK_PASS_DEPTH_PASS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_DRAW_BUFFERS);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER0);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER1);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER2);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER3);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER4);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER5);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER6);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER7);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER8);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER9);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER10);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER11);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER12);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER13);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER14);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER15);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLEND_EQUATION_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VERTEX_ATTRIBS);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY_NORMALIZED);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TEXTURE_IMAGE_UNITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAGMENT_SHADER);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_SHADER);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_FRAGMENT_UNIFORM_COMPONENTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VERTEX_UNIFORM_COMPONENTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VARYING_FLOATS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_SHADER_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_VEC2);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_VEC3);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_VEC4);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_VEC2);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_VEC3);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_VEC4);
    CREATE_GL_BASIC_BIC_STATIC(GL_BOOL);
    CREATE_GL_BASIC_BIC_STATIC(GL_BOOL_VEC2);
    CREATE_GL_BASIC_BIC_STATIC(GL_BOOL_VEC3);
    CREATE_GL_BASIC_BIC_STATIC(GL_BOOL_VEC4);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_MAT2);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_MAT3);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_MAT4);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_1D);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_2D);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_3D);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_CUBE);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_1D_SHADOW);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_2D_SHADOW);
    CREATE_GL_BASIC_BIC_STATIC(GL_DELETE_STATUS);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPILE_STATUS);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINK_STATUS);
    CREATE_GL_BASIC_BIC_STATIC(GL_VALIDATE_STATUS);
    CREATE_GL_BASIC_BIC_STATIC(GL_INFO_LOG_LENGTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATTACHED_SHADERS);
    CREATE_GL_BASIC_BIC_STATIC(GL_ACTIVE_UNIFORMS);
    CREATE_GL_BASIC_BIC_STATIC(GL_ACTIVE_UNIFORM_MAX_LENGTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_SHADER_SOURCE_LENGTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_ACTIVE_ATTRIBUTES);
    CREATE_GL_BASIC_BIC_STATIC(GL_ACTIVE_ATTRIBUTE_MAX_LENGTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAGMENT_SHADER_DERIVATIVE_HINT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SHADING_LANGUAGE_VERSION);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_PROGRAM);
    CREATE_GL_BASIC_BIC_STATIC(GL_POINT_SPRITE_COORD_ORIGIN);
    CREATE_GL_BASIC_BIC_STATIC(GL_LOWER_LEFT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UPPER_LEFT);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_BACK_REF);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_BACK_VALUE_MASK);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_BACK_WRITEMASK);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_PROGRAM_TWO_SIDE);
    CREATE_GL_BASIC_BIC_STATIC(GL_POINT_SPRITE);
    CREATE_GL_BASIC_BIC_STATIC(GL_COORD_REPLACE);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TEXTURE_COORDS);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERSION_2_1);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_PACK_BUFFER);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_UNPACK_BUFFER);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_PACK_BUFFER_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_UNPACK_BUFFER_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_MAT2x3);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_MAT2x4);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_MAT3x2);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_MAT3x4);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_MAT4x2);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_MAT4x3);
    CREATE_GL_BASIC_BIC_STATIC(GL_SRGB);
    CREATE_GL_BASIC_BIC_STATIC(GL_SRGB8);
    CREATE_GL_BASIC_BIC_STATIC(GL_SRGB_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_SRGB8_ALPHA8);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SRGB);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SRGB_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_RASTER_SECONDARY_COLOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_SLUMINANCE_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_SLUMINANCE8_ALPHA8);
    CREATE_GL_BASIC_BIC_STATIC(GL_SLUMINANCE);
    CREATE_GL_BASIC_BIC_STATIC(GL_SLUMINANCE8);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SLUMINANCE);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SLUMINANCE_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERSION_3_0);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPARE_REF_TO_TEXTURE);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLIP_DISTANCE0);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLIP_DISTANCE1);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLIP_DISTANCE2);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLIP_DISTANCE3);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLIP_DISTANCE4);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLIP_DISTANCE5);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLIP_DISTANCE6);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLIP_DISTANCE7);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_CLIP_DISTANCES);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAJOR_VERSION);
    CREATE_GL_BASIC_BIC_STATIC(GL_MINOR_VERSION);
    CREATE_GL_BASIC_BIC_STATIC(GL_NUM_EXTENSIONS);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONTEXT_FLAGS);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_RED);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_RG);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA32F);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB32F);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA16F);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB16F);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY_INTEGER);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_ARRAY_TEXTURE_LAYERS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MIN_PROGRAM_TEXEL_OFFSET);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_TEXEL_OFFSET);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLAMP_READ_COLOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_FIXED_ONLY);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VARYING_COMPONENTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_1D_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROXY_TEXTURE_1D_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_2D_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROXY_TEXTURE_2D_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BINDING_1D_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BINDING_2D_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_R11F_G11F_B10F);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_10F_11F_11F_REV);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB9_E5);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_5_9_9_9_REV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_SHARED_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK_BUFFER_MODE);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK_VARYINGS);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK_BUFFER_START);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK_BUFFER_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_PRIMITIVES_GENERATED);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN);
    CREATE_GL_BASIC_BIC_STATIC(GL_RASTERIZER_DISCARD);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTERLEAVED_ATTRIBS);
    CREATE_GL_BASIC_BIC_STATIC(GL_SEPARATE_ATTRIBS);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK_BUFFER);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK_BUFFER_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA32UI);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB32UI);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA16UI);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB16UI);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA8UI);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB8UI);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA32I);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB32I);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA16I);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB16I);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA8I);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB8I);
    CREATE_GL_BASIC_BIC_STATIC(GL_RED_INTEGER);
    CREATE_GL_BASIC_BIC_STATIC(GL_GREEN_INTEGER);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLUE_INTEGER);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB_INTEGER);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA_INTEGER);
    CREATE_GL_BASIC_BIC_STATIC(GL_BGR_INTEGER);
    CREATE_GL_BASIC_BIC_STATIC(GL_BGRA_INTEGER);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_1D_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_2D_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_1D_ARRAY_SHADOW);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_2D_ARRAY_SHADOW);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_CUBE_SHADOW);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_VEC2);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_VEC3);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_VEC4);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_SAMPLER_1D);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_SAMPLER_2D);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_SAMPLER_3D);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_SAMPLER_CUBE);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_SAMPLER_1D_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_SAMPLER_2D_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_SAMPLER_1D);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_SAMPLER_2D);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_SAMPLER_3D);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_SAMPLER_CUBE);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_SAMPLER_1D_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_SAMPLER_2D_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_QUERY_WAIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_QUERY_NO_WAIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_QUERY_BY_REGION_WAIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_QUERY_BY_REGION_NO_WAIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_BUFFER_ACCESS_FLAGS);
    CREATE_GL_BASIC_BIC_STATIC(GL_BUFFER_MAP_LENGTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_BUFFER_MAP_OFFSET);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_COMPONENT32F);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH32F_STENCIL8);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_32_UNSIGNED_INT_24_8_REV);
    CREATE_GL_BASIC_BIC_STATIC(GL_INVALID_FRAMEBUFFER_OPERATION);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_DEFAULT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_UNDEFINED);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_STENCIL_ATTACHMENT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_RENDERBUFFER_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_STENCIL);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_24_8);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH24_STENCIL8);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_STENCIL_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_RED_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_GREEN_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BLUE_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_ALPHA_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_DEPTH_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_NORMALIZED);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_FRAMEBUFFER_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_READ_FRAMEBUFFER);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_FRAMEBUFFER);
    CREATE_GL_BASIC_BIC_STATIC(GL_READ_FRAMEBUFFER_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER_SAMPLES);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_COMPLETE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_UNSUPPORTED);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_COLOR_ATTACHMENTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ATTACHMENT0);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ATTACHMENT1);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ATTACHMENT2);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ATTACHMENT3);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ATTACHMENT4);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ATTACHMENT5);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ATTACHMENT6);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ATTACHMENT7);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ATTACHMENT8);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ATTACHMENT9);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ATTACHMENT10);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ATTACHMENT11);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ATTACHMENT12);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ATTACHMENT13);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ATTACHMENT14);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ATTACHMENT15);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_ATTACHMENT);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_ATTACHMENT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER_WIDTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER_HEIGHT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER_INTERNAL_FORMAT);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_INDEX1);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_INDEX4);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_INDEX8);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_INDEX16);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER_RED_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER_GREEN_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER_BLUE_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER_ALPHA_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER_DEPTH_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER_STENCIL_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_SAMPLES);
    CREATE_GL_BASIC_BIC_STATIC(GL_INDEX);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_LUMINANCE_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_INTENSITY_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_SRGB);
    CREATE_GL_BASIC_BIC_STATIC(GL_HALF_FLOAT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP_READ_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP_WRITE_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP_INVALIDATE_RANGE_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP_INVALIDATE_BUFFER_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP_FLUSH_EXPLICIT_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP_UNSYNCHRONIZED_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_RED_RGTC1);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SIGNED_RED_RGTC1);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_RG_RGTC2);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SIGNED_RG_RGTC2);
    CREATE_GL_BASIC_BIC_STATIC(GL_RG);
    CREATE_GL_BASIC_BIC_STATIC(GL_RG_INTEGER);
    CREATE_GL_BASIC_BIC_STATIC(GL_R8);
    CREATE_GL_BASIC_BIC_STATIC(GL_R16);
    CREATE_GL_BASIC_BIC_STATIC(GL_RG8);
    CREATE_GL_BASIC_BIC_STATIC(GL_RG16);
    CREATE_GL_BASIC_BIC_STATIC(GL_R16F);
    CREATE_GL_BASIC_BIC_STATIC(GL_R32F);
    CREATE_GL_BASIC_BIC_STATIC(GL_RG16F);
    CREATE_GL_BASIC_BIC_STATIC(GL_RG32F);
    CREATE_GL_BASIC_BIC_STATIC(GL_R8I);
    CREATE_GL_BASIC_BIC_STATIC(GL_R8UI);
    CREATE_GL_BASIC_BIC_STATIC(GL_R16I);
    CREATE_GL_BASIC_BIC_STATIC(GL_R16UI);
    CREATE_GL_BASIC_BIC_STATIC(GL_R32I);
    CREATE_GL_BASIC_BIC_STATIC(GL_R32UI);
    CREATE_GL_BASIC_BIC_STATIC(GL_RG8I);
    CREATE_GL_BASIC_BIC_STATIC(GL_RG8UI);
    CREATE_GL_BASIC_BIC_STATIC(GL_RG16I);
    CREATE_GL_BASIC_BIC_STATIC(GL_RG16UI);
    CREATE_GL_BASIC_BIC_STATIC(GL_RG32I);
    CREATE_GL_BASIC_BIC_STATIC(GL_RG32UI);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ARRAY_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLAMP_VERTEX_COLOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLAMP_FRAGMENT_COLOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA_INTEGER);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERSION_3_1);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_2D_RECT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_2D_RECT_SHADOW);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_BUFFER);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_SAMPLER_2D_RECT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_SAMPLER_BUFFER);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_SAMPLER_2D_RECT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_SAMPLER_BUFFER);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BUFFER);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TEXTURE_BUFFER_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BINDING_BUFFER);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BUFFER_DATA_STORE_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_RECTANGLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BINDING_RECTANGLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROXY_TEXTURE_RECTANGLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_RECTANGLE_TEXTURE_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_R8_SNORM);
    CREATE_GL_BASIC_BIC_STATIC(GL_RG8_SNORM);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB8_SNORM);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA8_SNORM);
    CREATE_GL_BASIC_BIC_STATIC(GL_R16_SNORM);
    CREATE_GL_BASIC_BIC_STATIC(GL_RG16_SNORM);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB16_SNORM);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA16_SNORM);
    CREATE_GL_BASIC_BIC_STATIC(GL_SIGNED_NORMALIZED);
    CREATE_GL_BASIC_BIC_STATIC(GL_PRIMITIVE_RESTART);
    CREATE_GL_BASIC_BIC_STATIC(GL_PRIMITIVE_RESTART_INDEX);
    CREATE_GL_BASIC_BIC_STATIC(GL_COPY_READ_BUFFER);
    CREATE_GL_BASIC_BIC_STATIC(GL_COPY_WRITE_BUFFER);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNIFORM_BUFFER);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNIFORM_BUFFER_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNIFORM_BUFFER_START);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNIFORM_BUFFER_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VERTEX_UNIFORM_BLOCKS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_FRAGMENT_UNIFORM_BLOCKS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_COMBINED_UNIFORM_BLOCKS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_UNIFORM_BUFFER_BINDINGS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_UNIFORM_BLOCK_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT);
    CREATE_GL_BASIC_BIC_STATIC(GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_ACTIVE_UNIFORM_BLOCKS);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNIFORM_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNIFORM_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNIFORM_NAME_LENGTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNIFORM_BLOCK_INDEX);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNIFORM_OFFSET);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNIFORM_ARRAY_STRIDE);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNIFORM_MATRIX_STRIDE);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNIFORM_IS_ROW_MAJOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNIFORM_BLOCK_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNIFORM_BLOCK_DATA_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNIFORM_BLOCK_NAME_LENGTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER);
    CREATE_GL_BASIC_BIC_STATIC(GL_INVALID_INDEX);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERSION_3_2);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONTEXT_CORE_PROFILE_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONTEXT_COMPATIBILITY_PROFILE_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINES_ADJACENCY);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINE_STRIP_ADJACENCY);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRIANGLES_ADJACENCY);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRIANGLE_STRIP_ADJACENCY);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_POINT_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_ATTACHMENT_LAYERED);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS);
    CREATE_GL_BASIC_BIC_STATIC(GL_GEOMETRY_SHADER);
    CREATE_GL_BASIC_BIC_STATIC(GL_GEOMETRY_VERTICES_OUT);
    CREATE_GL_BASIC_BIC_STATIC(GL_GEOMETRY_INPUT_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_GEOMETRY_OUTPUT_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_GEOMETRY_UNIFORM_COMPONENTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_GEOMETRY_OUTPUT_VERTICES);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VERTEX_OUTPUT_COMPONENTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_GEOMETRY_INPUT_COMPONENTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_GEOMETRY_OUTPUT_COMPONENTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_FRAGMENT_INPUT_COMPONENTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONTEXT_PROFILE_MASK);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_CLAMP);
    CREATE_GL_BASIC_BIC_STATIC(GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION);
    CREATE_GL_BASIC_BIC_STATIC(GL_FIRST_VERTEX_CONVENTION);
    CREATE_GL_BASIC_BIC_STATIC(GL_LAST_VERTEX_CONVENTION);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROVOKING_VERTEX);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CUBE_MAP_SEAMLESS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_SERVER_WAIT_TIMEOUT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OBJECT_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_SYNC_CONDITION);
    CREATE_GL_BASIC_BIC_STATIC(GL_SYNC_STATUS);
    CREATE_GL_BASIC_BIC_STATIC(GL_SYNC_FLAGS);
    CREATE_GL_BASIC_BIC_STATIC(GL_SYNC_FENCE);
    CREATE_GL_BASIC_BIC_STATIC(GL_SYNC_GPU_COMMANDS_COMPLETE);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNALED);
    CREATE_GL_BASIC_BIC_STATIC(GL_SIGNALED);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALREADY_SIGNALED);
    CREATE_GL_BASIC_BIC_STATIC(GL_TIMEOUT_EXPIRED);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONDITION_SATISFIED);
    CREATE_GL_BASIC_BIC_STATIC(GL_WAIT_FAILED);
    CREATE_GL_BASIC_BIC_STATIC(GL_TIMEOUT_IGNORED);
    CREATE_GL_BASIC_BIC_STATIC(GL_SYNC_FLUSH_COMMANDS_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_POSITION);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_MASK);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_MASK_VALUE);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_SAMPLE_MASK_WORDS);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_2D_MULTISAMPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROXY_TEXTURE_2D_MULTISAMPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_2D_MULTISAMPLE_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BINDING_2D_MULTISAMPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_SAMPLES);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_FIXED_SAMPLE_LOCATIONS);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_2D_MULTISAMPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_SAMPLER_2D_MULTISAMPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_2D_MULTISAMPLE_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_COLOR_TEXTURE_SAMPLES);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_DEPTH_TEXTURE_SAMPLES);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_INTEGER_SAMPLES);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERSION_3_3);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY_DIVISOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_SRC1_COLOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_ONE_MINUS_SRC1_COLOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_ONE_MINUS_SRC1_ALPHA);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_DUAL_SOURCE_DRAW_BUFFERS);
    CREATE_GL_BASIC_BIC_STATIC(GL_ANY_SAMPLES_PASSED);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB10_A2UI);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_SWIZZLE_R);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_SWIZZLE_G);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_SWIZZLE_B);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_SWIZZLE_A);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_SWIZZLE_RGBA);
    CREATE_GL_BASIC_BIC_STATIC(GL_TIME_ELAPSED);
    CREATE_GL_BASIC_BIC_STATIC(GL_TIMESTAMP);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_2_10_10_10_REV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERSION_4_0);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_SHADING);
    CREATE_GL_BASIC_BIC_STATIC(GL_MIN_SAMPLE_SHADING_VALUE);
    CREATE_GL_BASIC_BIC_STATIC(GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CUBE_MAP_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BINDING_CUBE_MAP_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROXY_TEXTURE_CUBE_MAP_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_CUBE_MAP_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_SAMPLER_CUBE_MAP_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_INDIRECT_BUFFER);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_INDIRECT_BUFFER_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_GEOMETRY_SHADER_INVOCATIONS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_GEOMETRY_SHADER_INVOCATIONS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MIN_FRAGMENT_INTERPOLATION_OFFSET);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_FRAGMENT_INTERPOLATION_OFFSET);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAGMENT_INTERPOLATION_OFFSET_BITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VERTEX_STREAMS);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOUBLE_VEC2);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOUBLE_VEC3);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOUBLE_VEC4);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOUBLE_MAT2);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOUBLE_MAT3);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOUBLE_MAT4);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOUBLE_MAT2x3);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOUBLE_MAT2x4);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOUBLE_MAT3x2);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOUBLE_MAT3x4);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOUBLE_MAT4x2);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOUBLE_MAT4x3);
    CREATE_GL_BASIC_BIC_STATIC(GL_ACTIVE_SUBROUTINES);
    CREATE_GL_BASIC_BIC_STATIC(GL_ACTIVE_SUBROUTINE_UNIFORMS);
    CREATE_GL_BASIC_BIC_STATIC(GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS);
    CREATE_GL_BASIC_BIC_STATIC(GL_ACTIVE_SUBROUTINE_MAX_LENGTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_SUBROUTINES);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS);
    CREATE_GL_BASIC_BIC_STATIC(GL_NUM_COMPATIBLE_SUBROUTINES);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPATIBLE_SUBROUTINES);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATCHES);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATCH_VERTICES);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATCH_DEFAULT_INNER_LEVEL);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATCH_DEFAULT_OUTER_LEVEL);
    CREATE_GL_BASIC_BIC_STATIC(GL_TESS_CONTROL_OUTPUT_VERTICES);
    CREATE_GL_BASIC_BIC_STATIC(GL_TESS_GEN_MODE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TESS_GEN_SPACING);
    CREATE_GL_BASIC_BIC_STATIC(GL_TESS_GEN_VERTEX_ORDER);
    CREATE_GL_BASIC_BIC_STATIC(GL_TESS_GEN_POINT_MODE);
    CREATE_GL_BASIC_BIC_STATIC(GL_ISOLINES);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRACTIONAL_ODD);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRACTIONAL_EVEN);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PATCH_VERTICES);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TESS_GEN_LEVEL);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TESS_PATCH_COMPONENTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TESS_CONTROL_INPUT_COMPONENTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER);
    CREATE_GL_BASIC_BIC_STATIC(GL_TESS_EVALUATION_SHADER);
    CREATE_GL_BASIC_BIC_STATIC(GL_TESS_CONTROL_SHADER);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TRANSFORM_FEEDBACK_BUFFERS);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERSION_4_1);
    CREATE_GL_BASIC_BIC_STATIC(GL_FIXED);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMPLEMENTATION_COLOR_READ_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMPLEMENTATION_COLOR_READ_FORMAT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LOW_FLOAT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MEDIUM_FLOAT);
    CREATE_GL_BASIC_BIC_STATIC(GL_HIGH_FLOAT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LOW_INT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MEDIUM_INT);
    CREATE_GL_BASIC_BIC_STATIC(GL_HIGH_INT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SHADER_COMPILER);
    CREATE_GL_BASIC_BIC_STATIC(GL_SHADER_BINARY_FORMATS);
    CREATE_GL_BASIC_BIC_STATIC(GL_NUM_SHADER_BINARY_FORMATS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VERTEX_UNIFORM_VECTORS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VARYING_VECTORS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_FRAGMENT_UNIFORM_VECTORS);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB565);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_BINARY_RETRIEVABLE_HINT);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_BINARY_LENGTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_NUM_PROGRAM_BINARY_FORMATS);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_BINARY_FORMATS);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_SHADER_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAGMENT_SHADER_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_GEOMETRY_SHADER_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TESS_CONTROL_SHADER_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TESS_EVALUATION_SHADER_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALL_SHADER_BITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_SEPARABLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_ACTIVE_PROGRAM);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_PIPELINE_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VIEWPORTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIEWPORT_SUBPIXEL_BITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIEWPORT_BOUNDS_RANGE);
    CREATE_GL_BASIC_BIC_STATIC(GL_LAYER_PROVOKING_VERTEX);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIEWPORT_INDEX_PROVOKING_VERTEX);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNDEFINED_VERTEX);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERSION_4_2);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNPACK_COMPRESSED_BLOCK_WIDTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNPACK_COMPRESSED_BLOCK_HEIGHT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNPACK_COMPRESSED_BLOCK_DEPTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNPACK_COMPRESSED_BLOCK_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_PACK_COMPRESSED_BLOCK_WIDTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_PACK_COMPRESSED_BLOCK_HEIGHT);
    CREATE_GL_BASIC_BIC_STATIC(GL_PACK_COMPRESSED_BLOCK_DEPTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_PACK_COMPRESSED_BLOCK_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_NUM_SAMPLE_COUNTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MIN_MAP_BUFFER_ALIGNMENT);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATOMIC_COUNTER_BUFFER);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATOMIC_COUNTER_BUFFER_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATOMIC_COUNTER_BUFFER_START);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATOMIC_COUNTER_BUFFER_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VERTEX_ATOMIC_COUNTERS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_GEOMETRY_ATOMIC_COUNTERS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_FRAGMENT_ATOMIC_COUNTERS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_COMBINED_ATOMIC_COUNTERS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS);
    CREATE_GL_BASIC_BIC_STATIC(GL_ACTIVE_ATOMIC_COUNTER_BUFFERS);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_ATOMIC_COUNTER);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_ELEMENT_ARRAY_BARRIER_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNIFORM_BARRIER_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_FETCH_BARRIER_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMMAND_BARRIER_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_BUFFER_BARRIER_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_UPDATE_BARRIER_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_BUFFER_UPDATE_BARRIER_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_BARRIER_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK_BARRIER_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATOMIC_COUNTER_BARRIER_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALL_BARRIER_BITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_IMAGE_UNITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_BINDING_NAME);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_BINDING_LEVEL);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_BINDING_LAYERED);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_BINDING_LAYER);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_BINDING_ACCESS);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_1D);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_2D);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_3D);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_2D_RECT);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_CUBE);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_BUFFER);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_1D_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_2D_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_CUBE_MAP_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_2D_MULTISAMPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_2D_MULTISAMPLE_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_IMAGE_1D);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_IMAGE_2D);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_IMAGE_3D);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_IMAGE_2D_RECT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_IMAGE_CUBE);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_IMAGE_BUFFER);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_IMAGE_1D_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_IMAGE_2D_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_IMAGE_CUBE_MAP_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_IMAGE_2D_MULTISAMPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_IMAGE_1D);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_IMAGE_2D);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_IMAGE_3D);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_IMAGE_2D_RECT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_IMAGE_CUBE);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_IMAGE_BUFFER);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_IMAGE_1D_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_IMAGE_2D_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_IMAGE_SAMPLES);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_BINDING_FORMAT);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_FORMAT_COMPATIBILITY_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VERTEX_IMAGE_UNIFORMS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_GEOMETRY_IMAGE_UNIFORMS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_FRAGMENT_IMAGE_UNIFORMS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_COMBINED_IMAGE_UNIFORMS);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_IMMUTABLE_FORMAT);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERSION_4_3);
    CREATE_GL_BASIC_BIC_STATIC(GL_NUM_SHADING_LANGUAGE_VERSIONS);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY_LONG);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_RGB8_ETC2);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SRGB8_ETC2);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_RGBA8_ETC2_EAC);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_R11_EAC);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SIGNED_R11_EAC);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_RG11_EAC);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SIGNED_RG11_EAC);
    CREATE_GL_BASIC_BIC_STATIC(GL_PRIMITIVE_RESTART_FIXED_INDEX);
    CREATE_GL_BASIC_BIC_STATIC(GL_ANY_SAMPLES_PASSED_CONSERVATIVE);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_ELEMENT_INDEX);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPUTE_SHADER);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_COMPUTE_UNIFORM_BLOCKS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_COMPUTE_IMAGE_UNIFORMS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_COMPUTE_SHARED_MEMORY_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_COMPUTE_UNIFORM_COMPONENTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_COMPUTE_ATOMIC_COUNTERS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_COMPUTE_WORK_GROUP_COUNT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_COMPUTE_WORK_GROUP_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER);
    CREATE_GL_BASIC_BIC_STATIC(GL_DISPATCH_INDIRECT_BUFFER);
    CREATE_GL_BASIC_BIC_STATIC(GL_DISPATCH_INDIRECT_BUFFER_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_CALLBACK_FUNCTION);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_CALLBACK_USER_PARAM);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_SOURCE_API);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_SOURCE_WINDOW_SYSTEM);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_SOURCE_SHADER_COMPILER);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_SOURCE_THIRD_PARTY);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_SOURCE_APPLICATION);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_SOURCE_OTHER);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_TYPE_ERROR);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_TYPE_PORTABILITY);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_TYPE_PERFORMANCE);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_TYPE_OTHER);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_DEBUG_MESSAGE_LENGTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_DEBUG_LOGGED_MESSAGES);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_LOGGED_MESSAGES);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_SEVERITY_HIGH);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_SEVERITY_MEDIUM);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_SEVERITY_LOW);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_TYPE_MARKER);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_TYPE_PUSH_GROUP);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_TYPE_POP_GROUP);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_SEVERITY_NOTIFICATION);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_DEBUG_GROUP_STACK_DEPTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_GROUP_STACK_DEPTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_BUFFER);
    CREATE_GL_BASIC_BIC_STATIC(GL_SHADER);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM);
    CREATE_GL_BASIC_BIC_STATIC(GL_QUERY);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_PIPELINE);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_LABEL_LENGTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_OUTPUT);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONTEXT_FLAG_DEBUG_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_UNIFORM_LOCATIONS);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_DEFAULT_WIDTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_DEFAULT_HEIGHT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_DEFAULT_LAYERS);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_DEFAULT_SAMPLES);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_FRAMEBUFFER_WIDTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_FRAMEBUFFER_HEIGHT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_FRAMEBUFFER_LAYERS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_FRAMEBUFFER_SAMPLES);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTERNALFORMAT_SUPPORTED);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTERNALFORMAT_PREFERRED);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTERNALFORMAT_RED_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTERNALFORMAT_GREEN_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTERNALFORMAT_BLUE_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTERNALFORMAT_ALPHA_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTERNALFORMAT_DEPTH_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTERNALFORMAT_STENCIL_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTERNALFORMAT_SHARED_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTERNALFORMAT_RED_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTERNALFORMAT_GREEN_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTERNALFORMAT_BLUE_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTERNALFORMAT_ALPHA_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTERNALFORMAT_DEPTH_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTERNALFORMAT_STENCIL_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_WIDTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_HEIGHT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_DEPTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_LAYERS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_COMBINED_DIMENSIONS);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_COMPONENTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_COMPONENTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_COMPONENTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_RENDERABLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_RENDERABLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_RENDERABLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_RENDERABLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_RENDERABLE_LAYERED);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_BLEND);
    CREATE_GL_BASIC_BIC_STATIC(GL_READ_PIXELS);
    CREATE_GL_BASIC_BIC_STATIC(GL_READ_PIXELS_FORMAT);
    CREATE_GL_BASIC_BIC_STATIC(GL_READ_PIXELS_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_IMAGE_FORMAT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_IMAGE_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_GET_TEXTURE_IMAGE_FORMAT);
    CREATE_GL_BASIC_BIC_STATIC(GL_GET_TEXTURE_IMAGE_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_MIPMAP);
    CREATE_GL_BASIC_BIC_STATIC(GL_MANUAL_GENERATE_MIPMAP);
    CREATE_GL_BASIC_BIC_STATIC(GL_AUTO_GENERATE_MIPMAP);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ENCODING);
    CREATE_GL_BASIC_BIC_STATIC(GL_SRGB_READ);
    CREATE_GL_BASIC_BIC_STATIC(GL_SRGB_WRITE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FILTER);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_TEXTURE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TESS_CONTROL_TEXTURE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TESS_EVALUATION_TEXTURE);
    CREATE_GL_BASIC_BIC_STATIC(GL_GEOMETRY_TEXTURE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAGMENT_TEXTURE);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPUTE_TEXTURE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_SHADOW);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_GATHER);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_GATHER_SHADOW);
    CREATE_GL_BASIC_BIC_STATIC(GL_SHADER_IMAGE_LOAD);
    CREATE_GL_BASIC_BIC_STATIC(GL_SHADER_IMAGE_STORE);
    CREATE_GL_BASIC_BIC_STATIC(GL_SHADER_IMAGE_ATOMIC);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_TEXEL_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_COMPATIBILITY_CLASS);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_PIXEL_FORMAT);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_PIXEL_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST);
    CREATE_GL_BASIC_BIC_STATIC(GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST);
    CREATE_GL_BASIC_BIC_STATIC(GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE);
    CREATE_GL_BASIC_BIC_STATIC(GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COMPRESSED_BLOCK_WIDTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COMPRESSED_BLOCK_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLEAR_BUFFER);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_VIEW);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIEW_COMPATIBILITY_CLASS);
    CREATE_GL_BASIC_BIC_STATIC(GL_FULL_SUPPORT);
    CREATE_GL_BASIC_BIC_STATIC(GL_CAVEAT_SUPPORT);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_CLASS_4_X_32);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_CLASS_2_X_32);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_CLASS_1_X_32);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_CLASS_4_X_16);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_CLASS_2_X_16);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_CLASS_1_X_16);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_CLASS_4_X_8);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_CLASS_2_X_8);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_CLASS_1_X_8);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_CLASS_11_11_10);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_CLASS_10_10_10_2);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIEW_CLASS_128_BITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIEW_CLASS_96_BITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIEW_CLASS_64_BITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIEW_CLASS_48_BITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIEW_CLASS_32_BITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIEW_CLASS_24_BITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIEW_CLASS_16_BITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIEW_CLASS_8_BITS);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIEW_CLASS_S3TC_DXT1_RGB);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIEW_CLASS_S3TC_DXT1_RGBA);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIEW_CLASS_S3TC_DXT3_RGBA);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIEW_CLASS_S3TC_DXT5_RGBA);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIEW_CLASS_RGTC1_RED);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIEW_CLASS_RGTC2_RG);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIEW_CLASS_BPTC_UNORM);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIEW_CLASS_BPTC_FLOAT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNIFORM);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNIFORM_BLOCK);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_INPUT);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_OUTPUT);
    CREATE_GL_BASIC_BIC_STATIC(GL_BUFFER_VARIABLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_SHADER_STORAGE_BLOCK);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_SUBROUTINE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TESS_CONTROL_SUBROUTINE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TESS_EVALUATION_SUBROUTINE);
    CREATE_GL_BASIC_BIC_STATIC(GL_GEOMETRY_SUBROUTINE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAGMENT_SUBROUTINE);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPUTE_SUBROUTINE);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_SUBROUTINE_UNIFORM);
    CREATE_GL_BASIC_BIC_STATIC(GL_TESS_CONTROL_SUBROUTINE_UNIFORM);
    CREATE_GL_BASIC_BIC_STATIC(GL_TESS_EVALUATION_SUBROUTINE_UNIFORM);
    CREATE_GL_BASIC_BIC_STATIC(GL_GEOMETRY_SUBROUTINE_UNIFORM);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAGMENT_SUBROUTINE_UNIFORM);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPUTE_SUBROUTINE_UNIFORM);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK_VARYING);
    CREATE_GL_BASIC_BIC_STATIC(GL_ACTIVE_RESOURCES);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_NAME_LENGTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_NUM_ACTIVE_VARIABLES);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_NUM_COMPATIBLE_SUBROUTINES);
    CREATE_GL_BASIC_BIC_STATIC(GL_NAME_LENGTH);
    CREATE_GL_BASIC_BIC_STATIC(GL_TYPE);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARRAY_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_OFFSET);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLOCK_INDEX);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARRAY_STRIDE);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX_STRIDE);
    CREATE_GL_BASIC_BIC_STATIC(GL_IS_ROW_MAJOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATOMIC_COUNTER_BUFFER_INDEX);
    CREATE_GL_BASIC_BIC_STATIC(GL_BUFFER_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_BUFFER_DATA_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_NUM_ACTIVE_VARIABLES);
    CREATE_GL_BASIC_BIC_STATIC(GL_ACTIVE_VARIABLES);
    CREATE_GL_BASIC_BIC_STATIC(GL_REFERENCED_BY_VERTEX_SHADER);
    CREATE_GL_BASIC_BIC_STATIC(GL_REFERENCED_BY_TESS_CONTROL_SHADER);
    CREATE_GL_BASIC_BIC_STATIC(GL_REFERENCED_BY_TESS_EVALUATION_SHADER);
    CREATE_GL_BASIC_BIC_STATIC(GL_REFERENCED_BY_GEOMETRY_SHADER);
    CREATE_GL_BASIC_BIC_STATIC(GL_REFERENCED_BY_FRAGMENT_SHADER);
    CREATE_GL_BASIC_BIC_STATIC(GL_REFERENCED_BY_COMPUTE_SHADER);
    CREATE_GL_BASIC_BIC_STATIC(GL_TOP_LEVEL_ARRAY_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TOP_LEVEL_ARRAY_STRIDE);
    CREATE_GL_BASIC_BIC_STATIC(GL_LOCATION);
    CREATE_GL_BASIC_BIC_STATIC(GL_LOCATION_INDEX);
    CREATE_GL_BASIC_BIC_STATIC(GL_IS_PER_PATCH);
    CREATE_GL_BASIC_BIC_STATIC(GL_SHADER_STORAGE_BUFFER);
    CREATE_GL_BASIC_BIC_STATIC(GL_SHADER_STORAGE_BUFFER_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_SHADER_STORAGE_BUFFER_START);
    CREATE_GL_BASIC_BIC_STATIC(GL_SHADER_STORAGE_BUFFER_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_SHADER_STORAGE_BLOCK_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SHADER_STORAGE_BARRIER_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_STENCIL_TEXTURE_MODE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BUFFER_OFFSET);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BUFFER_SIZE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_VIEW_MIN_LEVEL);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_VIEW_NUM_LEVELS);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_VIEW_MIN_LAYER);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_VIEW_NUM_LAYERS);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_IMMUTABLE_LEVELS);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_RELATIVE_OFFSET);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_BINDING_DIVISOR);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_BINDING_OFFSET);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_BINDING_STRIDE);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VERTEX_ATTRIB_BINDINGS);
    CREATE_GL_BASIC_BIC_STATIC(GL_DISPLAY_LIST);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_ES2_compatibility);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_ES3_compatibility);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_arrays_of_arrays);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_base_instance);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_blend_func_extended);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_cl_event);
    CREATE_GL_BASIC_BIC_STATIC(GL_SYNC_CL_EVENT_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_SYNC_CL_EVENT_COMPLETE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_clear_buffer_object);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_color_buffer_float);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA_FLOAT_MODE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLAMP_VERTEX_COLOR_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLAMP_FRAGMENT_COLOR_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLAMP_READ_COLOR_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_FIXED_ONLY_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_compatibility);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_compressed_texture_pixel_storage);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_compute_shader);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPUTE_SHADER_BIT);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_conservative_depth);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_copy_buffer);
    CREATE_GL_BASIC_BIC_STATIC(GL_COPY_READ_BUFFER_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_COPY_WRITE_BUFFER_BINDING);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_copy_image);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_debug_output);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_CALLBACK_FUNCTION_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_CALLBACK_USER_PARAM_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_SOURCE_API_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_SOURCE_WINDOW_SYSTEM_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_SOURCE_SHADER_COMPILER_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_SOURCE_THIRD_PARTY_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_SOURCE_APPLICATION_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_SOURCE_OTHER_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_TYPE_ERROR_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_TYPE_PORTABILITY_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_TYPE_PERFORMANCE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_TYPE_OTHER_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_DEBUG_MESSAGE_LENGTH_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_DEBUG_LOGGED_MESSAGES_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_LOGGED_MESSAGES_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_SEVERITY_HIGH_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_SEVERITY_MEDIUM_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_SEVERITY_LOW_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_depth_buffer_float);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_depth_clamp);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_depth_texture);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_COMPONENT16_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_COMPONENT24_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_COMPONENT32_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_DEPTH_SIZE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_TEXTURE_MODE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_draw_buffers);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_DRAW_BUFFERS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER0_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER1_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER2_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER3_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER4_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER5_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER6_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER7_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER8_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER9_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER10_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER11_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER12_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER13_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER14_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER15_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_draw_buffers_blend);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_draw_elements_base_vertex);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_draw_indirect);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_draw_instanced);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_explicit_attrib_location);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_explicit_uniform_location);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_fragment_coord_conventions);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_fragment_layer_viewport);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_fragment_program);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAGMENT_PROGRAM_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_FORMAT_ASCII_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_LENGTH_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_FORMAT_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_BINDING_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_INSTRUCTIONS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_INSTRUCTIONS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_NATIVE_INSTRUCTIONS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_TEMPORARIES_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_TEMPORARIES_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_NATIVE_TEMPORARIES_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_NATIVE_TEMPORARIES_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_PARAMETERS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_PARAMETERS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_NATIVE_PARAMETERS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_NATIVE_PARAMETERS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_ATTRIBS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_ATTRIBS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_NATIVE_ATTRIBS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_NATIVE_ATTRIBS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_ENV_PARAMETERS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_UNDER_NATIVE_LIMITS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_ALU_INSTRUCTIONS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_TEX_INSTRUCTIONS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_TEX_INDIRECTIONS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_ALU_INSTRUCTIONS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_TEX_INSTRUCTIONS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_TEX_INDIRECTIONS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_STRING_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_ERROR_POSITION_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_MATRIX_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSPOSE_CURRENT_MATRIX_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_MATRIX_STACK_DEPTH_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_MATRICES_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TEXTURE_COORDS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TEXTURE_IMAGE_UNITS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_ERROR_STRING_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX0_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX1_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX2_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX3_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX4_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX5_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX6_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX7_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX8_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX9_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX10_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX11_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX12_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX13_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX14_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX15_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX16_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX17_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX18_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX19_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX20_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX21_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX22_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX23_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX24_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX25_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX26_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX27_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX28_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX29_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX30_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX31_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_fragment_program_shadow);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_fragment_shader);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAGMENT_SHADER_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAGMENT_SHADER_DERIVATIVE_HINT_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_framebuffer_no_attachments);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_framebuffer_object);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_framebuffer_sRGB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_geometry_shader4);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINES_ADJACENCY_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINE_STRIP_ADJACENCY_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRIANGLES_ADJACENCY_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRIANGLE_STRIP_ADJACENCY_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_POINT_SIZE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_ATTACHMENT_LAYERED_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_GEOMETRY_SHADER_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_GEOMETRY_VERTICES_OUT_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_GEOMETRY_INPUT_TYPE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_GEOMETRY_OUTPUT_TYPE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_GEOMETRY_VARYING_COMPONENTS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VERTEX_VARYING_COMPONENTS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_GEOMETRY_OUTPUT_VERTICES_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_get_program_binary);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_gpu_shader5);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_gpu_shader_fp64);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_half_float_pixel);
    CREATE_GL_BASIC_BIC_STATIC(GL_HALF_FLOAT_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_half_float_vertex);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_instanced_arrays);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY_DIVISOR_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_internalformat_query);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_internalformat_query2);
    CREATE_GL_BASIC_BIC_STATIC(GL_SRGB_DECODE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_invalidate_subdata);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_map_buffer_alignment);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_map_buffer_range);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_matrix_palette);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX_PALETTE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_MATRIX_PALETTE_STACK_DEPTH_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PALETTE_MATRICES_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_PALETTE_MATRIX_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX_INDEX_ARRAY_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_MATRIX_INDEX_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX_INDEX_ARRAY_SIZE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX_INDEX_ARRAY_TYPE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX_INDEX_ARRAY_STRIDE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX_INDEX_ARRAY_POINTER_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_multi_draw_indirect);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_multisample);
    CREATE_GL_BASIC_BIC_STATIC(GL_MULTISAMPLE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_ALPHA_TO_COVERAGE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_ALPHA_TO_ONE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_COVERAGE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_BUFFERS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLES_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_COVERAGE_VALUE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_COVERAGE_INVERT_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MULTISAMPLE_BIT_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_occlusion_query);
    CREATE_GL_BASIC_BIC_STATIC(GL_QUERY_COUNTER_BITS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_QUERY_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_QUERY_RESULT_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_QUERY_RESULT_AVAILABLE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLES_PASSED_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_occlusion_query2);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_pixel_buffer_object);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_PACK_BUFFER_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_UNPACK_BUFFER_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_PACK_BUFFER_BINDING_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_UNPACK_BUFFER_BINDING_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_point_parameters);
    CREATE_GL_BASIC_BIC_STATIC(GL_POINT_SIZE_MIN_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_POINT_SIZE_MAX_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_POINT_FADE_THRESHOLD_SIZE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_POINT_DISTANCE_ATTENUATION_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_point_sprite);
    CREATE_GL_BASIC_BIC_STATIC(GL_POINT_SPRITE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_COORD_REPLACE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_program_interface_query);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_provoking_vertex);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_robust_buffer_access_behavior);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_robustness);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_LOSE_CONTEXT_ON_RESET_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_GUILTY_CONTEXT_RESET_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_INNOCENT_CONTEXT_RESET_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNKNOWN_CONTEXT_RESET_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_RESET_NOTIFICATION_STRATEGY_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_NO_RESET_NOTIFICATION_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_robustness_isolation);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_sample_shading);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_SHADING_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MIN_SAMPLE_SHADING_VALUE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_sampler_objects);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_seamless_cube_map);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_separate_shader_objects);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_shader_atomic_counters);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_shader_bit_encoding);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_shader_image_load_store);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_shader_image_size);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_shader_objects);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_OBJECT_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_SHADER_OBJECT_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_OBJECT_TYPE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_OBJECT_SUBTYPE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_VEC2_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_VEC3_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_VEC4_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_VEC2_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_VEC3_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_VEC4_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_BOOL_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_BOOL_VEC2_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_BOOL_VEC3_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_BOOL_VEC4_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_MAT2_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_MAT3_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_MAT4_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_1D_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_2D_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_3D_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_CUBE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_1D_SHADOW_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_2D_SHADOW_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_2D_RECT_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_2D_RECT_SHADOW_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_OBJECT_DELETE_STATUS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_OBJECT_COMPILE_STATUS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_OBJECT_LINK_STATUS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_OBJECT_VALIDATE_STATUS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_OBJECT_INFO_LOG_LENGTH_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_OBJECT_ATTACHED_OBJECTS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_OBJECT_ACTIVE_UNIFORMS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_OBJECT_ACTIVE_UNIFORM_MAX_LENGTH_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_OBJECT_SHADER_SOURCE_LENGTH_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_shader_precision);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_shader_stencil_export);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_shader_storage_buffer_object);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_shader_subroutine);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_shader_texture_lod);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_shading_language_100);
    CREATE_GL_BASIC_BIC_STATIC(GL_SHADING_LANGUAGE_VERSION_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_shading_language_420pack);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_shading_language_include);
    CREATE_GL_BASIC_BIC_STATIC(GL_SHADER_INCLUDE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_NAMED_STRING_LENGTH_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_NAMED_STRING_TYPE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_shading_language_packing);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_shadow);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COMPARE_MODE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COMPARE_FUNC_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPARE_R_TO_TEXTURE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_shadow_ambient);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COMPARE_FAIL_VALUE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_stencil_texturing);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_sync);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_tessellation_shader);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_texture_border_clamp);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLAMP_TO_BORDER_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_texture_buffer_object);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BUFFER_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TEXTURE_BUFFER_SIZE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BINDING_BUFFER_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BUFFER_DATA_STORE_BINDING_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BUFFER_FORMAT_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_texture_buffer_object_rgb32);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_texture_buffer_range);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_texture_compression);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_ALPHA_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_LUMINANCE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_LUMINANCE_ALPHA_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_INTENSITY_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_RGB_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_RGBA_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COMPRESSION_HINT_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COMPRESSED_IMAGE_SIZE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COMPRESSED_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_TEXTURE_FORMATS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_texture_compression_bptc);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_RGBA_BPTC_UNORM_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_texture_compression_rgtc);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_texture_cube_map);
    CREATE_GL_BASIC_BIC_STATIC(GL_NORMAL_MAP_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_REFLECTION_MAP_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CUBE_MAP_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BINDING_CUBE_MAP_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROXY_TEXTURE_CUBE_MAP_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_CUBE_MAP_TEXTURE_SIZE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_texture_cube_map_array);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CUBE_MAP_ARRAY_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROXY_TEXTURE_CUBE_MAP_ARRAY_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_CUBE_MAP_ARRAY_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_SAMPLER_CUBE_MAP_ARRAY_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_texture_env_add);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_texture_env_combine);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMBINE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMBINE_RGB_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMBINE_ALPHA_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_SOURCE0_RGB_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_SOURCE1_RGB_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_SOURCE2_RGB_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_SOURCE0_ALPHA_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_SOURCE1_ALPHA_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_SOURCE2_ALPHA_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_OPERAND0_RGB_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_OPERAND1_RGB_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_OPERAND2_RGB_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_OPERAND0_ALPHA_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_OPERAND1_ALPHA_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_OPERAND2_ALPHA_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB_SCALE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ADD_SIGNED_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTERPOLATE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_SUBTRACT_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONSTANT_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_PRIMARY_COLOR_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_PREVIOUS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_texture_env_crossbar);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_texture_env_dot3);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOT3_RGB_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOT3_RGBA_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_texture_float);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_RED_TYPE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_GREEN_TYPE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BLUE_TYPE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_ALPHA_TYPE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_LUMINANCE_TYPE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_INTENSITY_TYPE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_DEPTH_TYPE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_NORMALIZED_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA32F_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB32F_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA32F_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTENSITY32F_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE32F_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE_ALPHA32F_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA16F_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB16F_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA16F_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTENSITY16F_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE16F_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE_ALPHA16F_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_texture_gather);
    CREATE_GL_BASIC_BIC_STATIC(GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_texture_mirrored_repeat);
    CREATE_GL_BASIC_BIC_STATIC(GL_MIRRORED_REPEAT_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_texture_multisample);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_texture_non_power_of_two);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_texture_query_levels);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_texture_query_lod);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_texture_rectangle);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_RECTANGLE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BINDING_RECTANGLE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROXY_TEXTURE_RECTANGLE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_RECTANGLE_TEXTURE_SIZE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_texture_rg);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_texture_rgb10_a2ui);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_texture_storage);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_texture_storage_multisample);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_texture_swizzle);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_texture_view);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_timer_query);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_transform_feedback2);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK_PAUSED);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK_ACTIVE);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_transform_feedback3);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_transform_feedback_instanced);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_transpose_matrix);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSPOSE_MODELVIEW_MATRIX_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSPOSE_PROJECTION_MATRIX_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSPOSE_TEXTURE_MATRIX_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSPOSE_COLOR_MATRIX_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_uniform_buffer_object);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_GEOMETRY_UNIFORM_BLOCKS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_vertex_array_bgra);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_vertex_array_object);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_vertex_attrib_64bit);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_vertex_attrib_binding);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_vertex_blend);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VERTEX_UNITS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ACTIVE_VERTEX_UNITS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_WEIGHT_SUM_UNITY_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_BLEND_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_WEIGHT_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_WEIGHT_ARRAY_TYPE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_WEIGHT_ARRAY_STRIDE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_WEIGHT_ARRAY_SIZE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_WEIGHT_ARRAY_POINTER_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_WEIGHT_ARRAY_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW0_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW1_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW2_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW3_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW4_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW5_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW6_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW7_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW8_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW9_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW10_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW11_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW12_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW13_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW14_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW15_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW16_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW17_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW18_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW19_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW20_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW21_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW22_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW23_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW24_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW25_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW26_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW27_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW28_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW29_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW30_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW31_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_vertex_buffer_object);
    CREATE_GL_BASIC_BIC_STATIC(GL_BUFFER_SIZE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_BUFFER_USAGE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARRAY_BUFFER_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ELEMENT_ARRAY_BUFFER_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARRAY_BUFFER_BINDING_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ELEMENT_ARRAY_BUFFER_BINDING_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ARRAY_BUFFER_BINDING_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_NORMAL_ARRAY_BUFFER_BINDING_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ARRAY_BUFFER_BINDING_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_INDEX_ARRAY_BUFFER_BINDING_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_EDGE_FLAG_ARRAY_BUFFER_BINDING_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_WEIGHT_ARRAY_BUFFER_BINDING_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_READ_ONLY_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_WRITE_ONLY_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_READ_WRITE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_BUFFER_ACCESS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_BUFFER_MAPPED_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_BUFFER_MAP_POINTER_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_STREAM_DRAW_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_STREAM_READ_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_STREAM_COPY_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_STATIC_DRAW_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_STATIC_READ_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_STATIC_COPY_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DYNAMIC_DRAW_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DYNAMIC_READ_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_DYNAMIC_COPY_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_vertex_program);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_SUM_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_PROGRAM_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY_ENABLED_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY_SIZE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY_STRIDE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY_TYPE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_VERTEX_ATTRIB_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_PROGRAM_POINT_SIZE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_PROGRAM_TWO_SIDE_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY_POINTER_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VERTEX_ATTRIBS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY_NORMALIZED_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_ADDRESS_REGISTERS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_ADDRESS_REGISTERS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_vertex_shader);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_SHADER_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VERTEX_UNIFORM_COMPONENTS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VARYING_FLOATS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_OBJECT_ACTIVE_ATTRIBUTES_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_OBJECT_ACTIVE_ATTRIBUTE_MAX_LENGTH_ARB);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_vertex_type_2_10_10_10_rev);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_viewport_array);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARB_window_pos);
    CREATE_GL_BASIC_BIC_STATIC(GL_KHR_debug);
    CREATE_GL_BASIC_BIC_STATIC(GL_KHR_texture_compression_astc_ldr);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_RGBA_ASTC_4x4_KHR);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_RGBA_ASTC_5x4_KHR);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_RGBA_ASTC_5x5_KHR);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_RGBA_ASTC_6x5_KHR);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_RGBA_ASTC_6x6_KHR);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_RGBA_ASTC_8x5_KHR);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_RGBA_ASTC_8x6_KHR);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_RGBA_ASTC_8x8_KHR);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_RGBA_ASTC_10x5_KHR);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_RGBA_ASTC_10x6_KHR);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_RGBA_ASTC_10x8_KHR);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_RGBA_ASTC_10x10_KHR);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_RGBA_ASTC_12x10_KHR);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_RGBA_ASTC_12x12_KHR);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4_KHR);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4_KHR);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5_KHR);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5_KHR);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6_KHR);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x5_KHR);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x6_KHR);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x8_KHR);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x5_KHR);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x10_KHR);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x12_KHR);
    CREATE_GL_BASIC_BIC_STATIC(GL_OES_byte_coordinates);
    CREATE_GL_BASIC_BIC_STATIC(GL_OES_compressed_paletted_texture);
    CREATE_GL_BASIC_BIC_STATIC(GL_PALETTE4_RGB8_OES);
    CREATE_GL_BASIC_BIC_STATIC(GL_PALETTE4_RGBA8_OES);
    CREATE_GL_BASIC_BIC_STATIC(GL_PALETTE4_R5_G6_B5_OES);
    CREATE_GL_BASIC_BIC_STATIC(GL_PALETTE4_RGBA4_OES);
    CREATE_GL_BASIC_BIC_STATIC(GL_PALETTE4_RGB5_A1_OES);
    CREATE_GL_BASIC_BIC_STATIC(GL_PALETTE8_RGB8_OES);
    CREATE_GL_BASIC_BIC_STATIC(GL_PALETTE8_RGBA8_OES);
    CREATE_GL_BASIC_BIC_STATIC(GL_PALETTE8_R5_G6_B5_OES);
    CREATE_GL_BASIC_BIC_STATIC(GL_PALETTE8_RGBA4_OES);
    CREATE_GL_BASIC_BIC_STATIC(GL_PALETTE8_RGB5_A1_OES);
    CREATE_GL_BASIC_BIC_STATIC(GL_OES_fixed_point);
    CREATE_GL_BASIC_BIC_STATIC(GL_FIXED_OES);
    CREATE_GL_BASIC_BIC_STATIC(GL_OES_query_matrix);
    CREATE_GL_BASIC_BIC_STATIC(GL_OES_read_format);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMPLEMENTATION_COLOR_READ_TYPE_OES);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMPLEMENTATION_COLOR_READ_FORMAT_OES);
    CREATE_GL_BASIC_BIC_STATIC(GL_OES_single_precision);
    CREATE_GL_BASIC_BIC_STATIC(GL_3DFX_multisample);
    CREATE_GL_BASIC_BIC_STATIC(GL_MULTISAMPLE_3DFX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_BUFFERS_3DFX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLES_3DFX);
    CREATE_GL_BASIC_BIC_STATIC(GL_MULTISAMPLE_BIT_3DFX);
    CREATE_GL_BASIC_BIC_STATIC(GL_3DFX_tbuffer);
    CREATE_GL_BASIC_BIC_STATIC(GL_3DFX_texture_compression_FXT1);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_RGB_FXT1_3DFX);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_RGBA_FXT1_3DFX);
    CREATE_GL_BASIC_BIC_STATIC(GL_AMD_blend_minmax_factor);
    CREATE_GL_BASIC_BIC_STATIC(GL_FACTOR_MIN_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_FACTOR_MAX_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_AMD_conservative_depth);
    CREATE_GL_BASIC_BIC_STATIC(GL_AMD_debug_output);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_DEBUG_MESSAGE_LENGTH_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_DEBUG_LOGGED_MESSAGES_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_LOGGED_MESSAGES_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_SEVERITY_HIGH_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_SEVERITY_MEDIUM_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_SEVERITY_LOW_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_CATEGORY_API_ERROR_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_CATEGORY_WINDOW_SYSTEM_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_CATEGORY_DEPRECATION_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_CATEGORY_UNDEFINED_BEHAVIOR_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_CATEGORY_PERFORMANCE_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_CATEGORY_SHADER_COMPILER_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_CATEGORY_APPLICATION_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEBUG_CATEGORY_OTHER_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_AMD_depth_clamp_separate);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_CLAMP_NEAR_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_CLAMP_FAR_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_AMD_draw_buffers_blend);
    CREATE_GL_BASIC_BIC_STATIC(GL_AMD_interleaved_elements);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ELEMENT_SWIZZLE_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ID_SWIZZLE_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_AMD_multi_draw_indirect);
    CREATE_GL_BASIC_BIC_STATIC(GL_AMD_name_gen_delete);
    CREATE_GL_BASIC_BIC_STATIC(GL_DATA_BUFFER_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_PERFORMANCE_MONITOR_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_QUERY_OBJECT_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ARRAY_OBJECT_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_OBJECT_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_AMD_performance_monitor);
    CREATE_GL_BASIC_BIC_STATIC(GL_COUNTER_TYPE_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_COUNTER_RANGE_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT64_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_PERCENTAGE_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_PERFMON_RESULT_AVAILABLE_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_PERFMON_RESULT_SIZE_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_PERFMON_RESULT_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_AMD_pinned_memory);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXTERNAL_VIRTUAL_MEMORY_BUFFER_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_AMD_query_buffer_object);
    CREATE_GL_BASIC_BIC_STATIC(GL_QUERY_BUFFER_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_QUERY_BUFFER_BINDING_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_QUERY_RESULT_NO_WAIT_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_AMD_sample_positions);
    CREATE_GL_BASIC_BIC_STATIC(GL_SUBSAMPLE_DISTANCE_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_AMD_seamless_cubemap_per_texture);
    CREATE_GL_BASIC_BIC_STATIC(GL_AMD_shader_stencil_export);
    CREATE_GL_BASIC_BIC_STATIC(GL_AMD_shader_trinary_minmax);
    CREATE_GL_BASIC_BIC_STATIC(GL_AMD_sparse_texture);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIRTUAL_PAGE_SIZE_X_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIRTUAL_PAGE_SIZE_Y_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIRTUAL_PAGE_SIZE_Z_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_SPARSE_TEXTURE_SIZE_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_SPARSE_3D_TEXTURE_SIZE_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MIN_SPARSE_LEVEL_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_MIN_LOD_WARNING_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_STORAGE_SPARSE_BIT_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_AMD_stencil_operation_extended);
    CREATE_GL_BASIC_BIC_STATIC(GL_SET_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_REPLACE_VALUE_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_OP_VALUE_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_BACK_OP_VALUE_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_AMD_texture_texture4);
    CREATE_GL_BASIC_BIC_STATIC(GL_AMD_transform_feedback3_lines_triangles);
    CREATE_GL_BASIC_BIC_STATIC(GL_AMD_vertex_shader_layer);
    CREATE_GL_BASIC_BIC_STATIC(GL_AMD_vertex_shader_tessellator);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_BUFFER_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_SAMPLER_BUFFER_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_SAMPLER_BUFFER_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_TESSELLATION_MODE_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_TESSELLATION_FACTOR_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_DISCRETE_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONTINUOUS_AMD);
    CREATE_GL_BASIC_BIC_STATIC(GL_AMD_vertex_shader_viewport_index);
    CREATE_GL_BASIC_BIC_STATIC(GL_APPLE_aux_depth_stencil);
    CREATE_GL_BASIC_BIC_STATIC(GL_AUX_DEPTH_STENCIL_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_APPLE_client_storage);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNPACK_CLIENT_STORAGE_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_APPLE_element_array);
    CREATE_GL_BASIC_BIC_STATIC(GL_ELEMENT_ARRAY_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_ELEMENT_ARRAY_TYPE_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_ELEMENT_ARRAY_POINTER_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_APPLE_fence);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_PIXELS_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_FENCE_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_APPLE_float_pixels);
    CREATE_GL_BASIC_BIC_STATIC(GL_HALF_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA_FLOAT32_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB_FLOAT32_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA_FLOAT32_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTENSITY_FLOAT32_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE_FLOAT32_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE_ALPHA_FLOAT32_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA_FLOAT16_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB_FLOAT16_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA_FLOAT16_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTENSITY_FLOAT16_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE_FLOAT16_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE_ALPHA_FLOAT16_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_FLOAT_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_APPLE_flush_buffer_range);
    CREATE_GL_BASIC_BIC_STATIC(GL_BUFFER_SERIALIZED_MODIFY_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_BUFFER_FLUSHING_UNMAP_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_APPLE_object_purgeable);
    CREATE_GL_BASIC_BIC_STATIC(GL_BUFFER_OBJECT_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_RELEASED_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_VOLATILE_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_RETAINED_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNDEFINED_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_PURGEABLE_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_APPLE_rgb_422);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB_422_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_SHORT_8_8_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_SHORT_8_8_REV_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_APPLE_row_bytes);
    CREATE_GL_BASIC_BIC_STATIC(GL_PACK_ROW_BYTES_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNPACK_ROW_BYTES_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_APPLE_specular_vector);
    CREATE_GL_BASIC_BIC_STATIC(GL_LIGHT_MODEL_SPECULAR_VECTOR_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_APPLE_texture_range);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_RANGE_LENGTH_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_RANGE_POINTER_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_STORAGE_HINT_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_STORAGE_PRIVATE_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_STORAGE_CACHED_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_STORAGE_SHARED_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_APPLE_transform_hint);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_HINT_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_APPLE_vertex_array_object);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ARRAY_BINDING_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_APPLE_vertex_array_range);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ARRAY_RANGE_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ARRAY_RANGE_LENGTH_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ARRAY_STORAGE_HINT_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ARRAY_RANGE_POINTER_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_STORAGE_CLIENT_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_APPLE_vertex_program_evaluators);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_MAP1_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_MAP2_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_MAP1_SIZE_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_MAP1_COEFF_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_MAP1_ORDER_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_MAP1_DOMAIN_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_MAP2_SIZE_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_MAP2_COEFF_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_MAP2_ORDER_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_MAP2_DOMAIN_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_APPLE_ycbcr_422);
    CREATE_GL_BASIC_BIC_STATIC(GL_YCBCR_422_APPLE);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATI_draw_buffers);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_DRAW_BUFFERS_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER0_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER1_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER2_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER3_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER4_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER5_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER6_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER7_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER8_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER9_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER10_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER11_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER12_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER13_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER14_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_BUFFER15_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATI_element_array);
    CREATE_GL_BASIC_BIC_STATIC(GL_ELEMENT_ARRAY_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_ELEMENT_ARRAY_TYPE_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_ELEMENT_ARRAY_POINTER_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATI_envmap_bumpmap);
    CREATE_GL_BASIC_BIC_STATIC(GL_BUMP_ROT_MATRIX_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_BUMP_ROT_MATRIX_SIZE_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_BUMP_NUM_TEX_UNITS_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_BUMP_TEX_UNITS_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_DUDV_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_DU8DV8_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_BUMP_ENVMAP_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_BUMP_TARGET_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATI_fragment_shader);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAGMENT_SHADER_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_REG_0_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_REG_1_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_REG_2_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_REG_3_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_REG_4_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_REG_5_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_REG_6_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_REG_7_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_REG_8_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_REG_9_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_REG_10_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_REG_11_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_REG_12_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_REG_13_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_REG_14_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_REG_15_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_REG_16_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_REG_17_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_REG_18_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_REG_19_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_REG_20_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_REG_21_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_REG_22_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_REG_23_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_REG_24_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_REG_25_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_REG_26_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_REG_27_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_REG_28_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_REG_29_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_REG_30_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_REG_31_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_CON_0_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_CON_1_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_CON_2_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_CON_3_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_CON_4_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_CON_5_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_CON_6_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_CON_7_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_CON_8_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_CON_9_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_CON_10_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_CON_11_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_CON_12_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_CON_13_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_CON_14_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_CON_15_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_CON_16_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_CON_17_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_CON_18_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_CON_19_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_CON_20_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_CON_21_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_CON_22_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_CON_23_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_CON_24_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_CON_25_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_CON_26_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_CON_27_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_CON_28_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_CON_29_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_CON_30_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_CON_31_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_MOV_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_ADD_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_MUL_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_SUB_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOT3_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOT4_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAD_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_LERP_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_CND_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_CND0_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOT2_ADD_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_SECONDARY_INTERPOLATOR_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_NUM_FRAGMENT_REGISTERS_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_NUM_FRAGMENT_CONSTANTS_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_NUM_PASSES_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_NUM_INSTRUCTIONS_PER_PASS_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_NUM_INSTRUCTIONS_TOTAL_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_NUM_INPUT_INTERPOLATOR_COMPONENTS_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_NUM_LOOPBACK_COMPONENTS_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ALPHA_PAIRING_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_SWIZZLE_STR_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_SWIZZLE_STQ_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_SWIZZLE_STR_DR_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_SWIZZLE_STQ_DQ_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_SWIZZLE_STRQ_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_SWIZZLE_STRQ_DQ_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_RED_BIT_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_GREEN_BIT_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLUE_BIT_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_2X_BIT_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_4X_BIT_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_8X_BIT_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_HALF_BIT_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_QUARTER_BIT_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_EIGHTH_BIT_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_SATURATE_BIT_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMP_BIT_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_NEGATE_BIT_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_BIAS_BIT_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATI_map_object_buffer);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATI_meminfo);
    CREATE_GL_BASIC_BIC_STATIC(GL_VBO_FREE_MEMORY_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_FREE_MEMORY_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER_FREE_MEMORY_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATI_pixel_format_float);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA_FLOAT_MODE_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_CLEAR_UNCLAMPED_VALUE_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATI_pn_triangles);
    CREATE_GL_BASIC_BIC_STATIC(GL_PN_TRIANGLES_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PN_TRIANGLES_TESSELATION_LEVEL_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_PN_TRIANGLES_POINT_MODE_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_PN_TRIANGLES_NORMAL_MODE_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_PN_TRIANGLES_TESSELATION_LEVEL_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_PN_TRIANGLES_POINT_MODE_LINEAR_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_PN_TRIANGLES_POINT_MODE_CUBIC_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_PN_TRIANGLES_NORMAL_MODE_LINEAR_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_PN_TRIANGLES_NORMAL_MODE_QUADRATIC_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATI_separate_stencil);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_BACK_FUNC_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_BACK_FAIL_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_BACK_PASS_DEPTH_FAIL_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_BACK_PASS_DEPTH_PASS_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATI_text_fragment_shader);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXT_FRAGMENT_SHADER_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATI_texture_env_combine3);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODULATE_ADD_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODULATE_SIGNED_ADD_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODULATE_SUBTRACT_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATI_texture_float);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA_FLOAT32_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB_FLOAT32_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA_FLOAT32_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTENSITY_FLOAT32_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE_FLOAT32_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE_ALPHA_FLOAT32_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA_FLOAT16_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB_FLOAT16_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA_FLOAT16_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTENSITY_FLOAT16_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE_FLOAT16_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE_ALPHA_FLOAT16_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATI_texture_mirror_once);
    CREATE_GL_BASIC_BIC_STATIC(GL_MIRROR_CLAMP_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_MIRROR_CLAMP_TO_EDGE_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATI_vertex_array_object);
    CREATE_GL_BASIC_BIC_STATIC(GL_STATIC_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_DYNAMIC_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_PRESERVE_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_DISCARD_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_OBJECT_BUFFER_SIZE_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_OBJECT_BUFFER_USAGE_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARRAY_OBJECT_BUFFER_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARRAY_OBJECT_OFFSET_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATI_vertex_attrib_array_object);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATI_vertex_streams);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VERTEX_STREAMS_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_STREAM0_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_STREAM1_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_STREAM2_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_STREAM3_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_STREAM4_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_STREAM5_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_STREAM6_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_STREAM7_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_SOURCE_ATI);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_422_pixels);
    CREATE_GL_BASIC_BIC_STATIC(GL_422_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_422_REV_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_422_AVERAGE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_422_REV_AVERAGE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_abgr);
    CREATE_GL_BASIC_BIC_STATIC(GL_ABGR_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_bgra);
    CREATE_GL_BASIC_BIC_STATIC(GL_BGR_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_BGRA_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_bindable_uniform);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VERTEX_BINDABLE_UNIFORMS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_FRAGMENT_BINDABLE_UNIFORMS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_GEOMETRY_BINDABLE_UNIFORMS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_BINDABLE_UNIFORM_SIZE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNIFORM_BUFFER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNIFORM_BUFFER_BINDING_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_blend_color);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONSTANT_COLOR_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_ONE_MINUS_CONSTANT_COLOR_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONSTANT_ALPHA_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_ONE_MINUS_CONSTANT_ALPHA_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLEND_COLOR_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_blend_equation_separate);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLEND_EQUATION_RGB_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLEND_EQUATION_ALPHA_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_blend_func_separate);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLEND_DST_RGB_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLEND_SRC_RGB_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLEND_DST_ALPHA_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLEND_SRC_ALPHA_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_blend_logic_op);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_blend_minmax);
    CREATE_GL_BASIC_BIC_STATIC(GL_MIN_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FUNC_ADD_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLEND_EQUATION_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_blend_subtract);
    CREATE_GL_BASIC_BIC_STATIC(GL_FUNC_SUBTRACT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FUNC_REVERSE_SUBTRACT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_clip_volume_hint);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLIP_VOLUME_CLIPPING_HINT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_cmyka);
    CREATE_GL_BASIC_BIC_STATIC(GL_CMYK_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_CMYKA_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_PACK_CMYK_HINT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNPACK_CMYK_HINT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_color_subtable);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_compiled_vertex_array);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARRAY_ELEMENT_LOCK_FIRST_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARRAY_ELEMENT_LOCK_COUNT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_convolution);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONVOLUTION_1D_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONVOLUTION_2D_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SEPARABLE_2D_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONVOLUTION_BORDER_MODE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONVOLUTION_FILTER_SCALE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONVOLUTION_FILTER_BIAS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_REDUCE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONVOLUTION_FORMAT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONVOLUTION_WIDTH_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONVOLUTION_HEIGHT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_CONVOLUTION_WIDTH_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_CONVOLUTION_HEIGHT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_CONVOLUTION_RED_SCALE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_CONVOLUTION_GREEN_SCALE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_CONVOLUTION_BLUE_SCALE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_CONVOLUTION_ALPHA_SCALE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_CONVOLUTION_RED_BIAS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_CONVOLUTION_GREEN_BIAS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_CONVOLUTION_BLUE_BIAS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_CONVOLUTION_ALPHA_BIAS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_coordinate_frame);
    CREATE_GL_BASIC_BIC_STATIC(GL_TANGENT_ARRAY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_BINORMAL_ARRAY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_TANGENT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_BINORMAL_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TANGENT_ARRAY_TYPE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TANGENT_ARRAY_STRIDE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_BINORMAL_ARRAY_TYPE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_BINORMAL_ARRAY_STRIDE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TANGENT_ARRAY_POINTER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_BINORMAL_ARRAY_POINTER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP1_TANGENT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP2_TANGENT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP1_BINORMAL_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP2_BINORMAL_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_copy_texture);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_cull_vertex);
    CREATE_GL_BASIC_BIC_STATIC(GL_CULL_VERTEX_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_CULL_VERTEX_EYE_POSITION_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_CULL_VERTEX_OBJECT_POSITION_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_depth_bounds_test);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_BOUNDS_TEST_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_BOUNDS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_direct_state_access);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_MATRIX_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSPOSE_PROGRAM_MATRIX_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_MATRIX_STACK_DEPTH_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_draw_buffers2);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_draw_instanced);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_draw_range_elements);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_ELEMENTS_VERTICES_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_ELEMENTS_INDICES_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_fog_coord);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_COORDINATE_SOURCE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_COORDINATE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAGMENT_DEPTH_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_FOG_COORDINATE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_COORDINATE_ARRAY_TYPE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_COORDINATE_ARRAY_STRIDE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_COORDINATE_ARRAY_POINTER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_COORDINATE_ARRAY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_framebuffer_blit);
    CREATE_GL_BASIC_BIC_STATIC(GL_READ_FRAMEBUFFER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_FRAMEBUFFER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_FRAMEBUFFER_BINDING_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_READ_FRAMEBUFFER_BINDING_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_framebuffer_multisample);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER_SAMPLES_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_SAMPLES_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_framebuffer_multisample_blit_scaled);
    CREATE_GL_BASIC_BIC_STATIC(GL_SCALED_RESOLVE_FASTEST_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SCALED_RESOLVE_NICEST_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_framebuffer_object);
    CREATE_GL_BASIC_BIC_STATIC(GL_INVALID_FRAMEBUFFER_OPERATION_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_RENDERBUFFER_SIZE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_BINDING_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER_BINDING_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_3D_ZOFFSET_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_COMPLETE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_INCOMPLETE_FORMATS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_UNSUPPORTED_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_COLOR_ATTACHMENTS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ATTACHMENT0_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ATTACHMENT1_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ATTACHMENT2_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ATTACHMENT3_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ATTACHMENT4_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ATTACHMENT5_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ATTACHMENT6_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ATTACHMENT7_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ATTACHMENT8_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ATTACHMENT9_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ATTACHMENT10_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ATTACHMENT11_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ATTACHMENT12_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ATTACHMENT13_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ATTACHMENT14_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ATTACHMENT15_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_ATTACHMENT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_ATTACHMENT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER_WIDTH_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER_HEIGHT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER_INTERNAL_FORMAT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_INDEX1_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_INDEX4_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_INDEX8_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_INDEX16_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER_RED_SIZE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER_GREEN_SIZE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER_BLUE_SIZE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER_ALPHA_SIZE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER_DEPTH_SIZE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER_STENCIL_SIZE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_framebuffer_sRGB);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_SRGB_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_SRGB_CAPABLE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_geometry_shader4);
    CREATE_GL_BASIC_BIC_STATIC(GL_GEOMETRY_SHADER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_GEOMETRY_VERTICES_OUT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_GEOMETRY_INPUT_TYPE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_GEOMETRY_OUTPUT_TYPE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_GEOMETRY_VARYING_COMPONENTS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VERTEX_VARYING_COMPONENTS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VARYING_COMPONENTS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_GEOMETRY_OUTPUT_VERTICES_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINES_ADJACENCY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINE_STRIP_ADJACENCY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRIANGLES_ADJACENCY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRIANGLE_STRIP_ADJACENCY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_ATTACHMENT_LAYERED_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_POINT_SIZE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_gpu_program_parameters);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_gpu_shader4);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY_INTEGER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_1D_ARRAY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_2D_ARRAY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_BUFFER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_1D_ARRAY_SHADOW_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_2D_ARRAY_SHADOW_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_CUBE_SHADOW_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_VEC2_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_VEC3_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_VEC4_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_SAMPLER_1D_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_SAMPLER_2D_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_SAMPLER_3D_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_SAMPLER_CUBE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_SAMPLER_2D_RECT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_SAMPLER_1D_ARRAY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_SAMPLER_2D_ARRAY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_SAMPLER_BUFFER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_SAMPLER_1D_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_SAMPLER_2D_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_SAMPLER_3D_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_SAMPLER_CUBE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_SAMPLER_2D_RECT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_SAMPLER_1D_ARRAY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_SAMPLER_2D_ARRAY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_SAMPLER_BUFFER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MIN_PROGRAM_TEXEL_OFFSET_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_TEXEL_OFFSET_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_histogram);
    CREATE_GL_BASIC_BIC_STATIC(GL_HISTOGRAM_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROXY_HISTOGRAM_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_HISTOGRAM_WIDTH_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_HISTOGRAM_FORMAT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_HISTOGRAM_RED_SIZE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_HISTOGRAM_GREEN_SIZE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_HISTOGRAM_BLUE_SIZE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_HISTOGRAM_ALPHA_SIZE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_HISTOGRAM_LUMINANCE_SIZE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_HISTOGRAM_SINK_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MINMAX_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MINMAX_FORMAT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MINMAX_SINK_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TABLE_TOO_LARGE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_index_array_formats);
    CREATE_GL_BASIC_BIC_STATIC(GL_IUI_V2F_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_IUI_V3F_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_IUI_N3F_V2F_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_IUI_N3F_V3F_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_T2F_IUI_V2F_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_T2F_IUI_V3F_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_T2F_IUI_N3F_V2F_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_T2F_IUI_N3F_V3F_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_index_func);
    CREATE_GL_BASIC_BIC_STATIC(GL_INDEX_TEST_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INDEX_TEST_FUNC_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INDEX_TEST_REF_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_index_material);
    CREATE_GL_BASIC_BIC_STATIC(GL_INDEX_MATERIAL_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INDEX_MATERIAL_PARAMETER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INDEX_MATERIAL_FACE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_index_texture);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_light_texture);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAGMENT_MATERIAL_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAGMENT_NORMAL_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAGMENT_COLOR_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATTENUATION_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SHADOW_ATTENUATION_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_APPLICATION_MODE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_LIGHT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_MATERIAL_FACE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_MATERIAL_PARAMETER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_misc_attribute);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_multi_draw_arrays);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_multisample);
    CREATE_GL_BASIC_BIC_STATIC(GL_MULTISAMPLE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_ALPHA_TO_MASK_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_ALPHA_TO_ONE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_MASK_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_1PASS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_2PASS_0_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_2PASS_1_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_4PASS_0_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_4PASS_1_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_4PASS_2_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_4PASS_3_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_BUFFERS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLES_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_MASK_VALUE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_MASK_INVERT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_PATTERN_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MULTISAMPLE_BIT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_packed_depth_stencil);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_STENCIL_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_24_8_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH24_STENCIL8_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_STENCIL_SIZE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_packed_float);
    CREATE_GL_BASIC_BIC_STATIC(GL_R11F_G11F_B10F_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_10F_11F_11F_REV_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA_SIGNED_COMPONENTS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_packed_pixels);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_BYTE_3_3_2_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_SHORT_4_4_4_4_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_SHORT_5_5_5_1_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_8_8_8_8_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_10_10_10_2_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_paletted_texture);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_INDEX1_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_INDEX2_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_INDEX4_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_INDEX8_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_INDEX12_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_INDEX16_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_INDEX_SIZE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_pixel_buffer_object);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_PACK_BUFFER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_UNPACK_BUFFER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_PACK_BUFFER_BINDING_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_UNPACK_BUFFER_BINDING_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_pixel_transform);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_TRANSFORM_2D_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_MAG_FILTER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_MIN_FILTER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_CUBIC_WEIGHT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_CUBIC_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_AVERAGE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_TRANSFORM_2D_MATRIX_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_pixel_transform_color_table);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_point_parameters);
    CREATE_GL_BASIC_BIC_STATIC(GL_POINT_SIZE_MIN_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_POINT_SIZE_MAX_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_POINT_FADE_THRESHOLD_SIZE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_DISTANCE_ATTENUATION_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_polygon_offset);
    CREATE_GL_BASIC_BIC_STATIC(GL_POLYGON_OFFSET_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_POLYGON_OFFSET_FACTOR_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_POLYGON_OFFSET_BIAS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_provoking_vertex);
    CREATE_GL_BASIC_BIC_STATIC(GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FIRST_VERTEX_CONVENTION_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LAST_VERTEX_CONVENTION_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROVOKING_VERTEX_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_rescale_normal);
    CREATE_GL_BASIC_BIC_STATIC(GL_RESCALE_NORMAL_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_secondary_color);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_SUM_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_SECONDARY_COLOR_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SECONDARY_COLOR_ARRAY_SIZE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SECONDARY_COLOR_ARRAY_TYPE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SECONDARY_COLOR_ARRAY_STRIDE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SECONDARY_COLOR_ARRAY_POINTER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SECONDARY_COLOR_ARRAY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_separate_shader_objects);
    CREATE_GL_BASIC_BIC_STATIC(GL_ACTIVE_PROGRAM_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_separate_specular_color);
    CREATE_GL_BASIC_BIC_STATIC(GL_LIGHT_MODEL_COLOR_CONTROL_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SINGLE_COLOR_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SEPARATE_SPECULAR_COLOR_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_shader_image_load_store);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_IMAGE_UNITS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_BINDING_NAME_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_BINDING_LEVEL_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_BINDING_LAYERED_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_BINDING_LAYER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_BINDING_ACCESS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_1D_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_2D_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_3D_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_2D_RECT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_CUBE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_BUFFER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_1D_ARRAY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_2D_ARRAY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_CUBE_MAP_ARRAY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_2D_MULTISAMPLE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_2D_MULTISAMPLE_ARRAY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_IMAGE_1D_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_IMAGE_2D_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_IMAGE_3D_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_IMAGE_2D_RECT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_IMAGE_CUBE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_IMAGE_BUFFER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_IMAGE_1D_ARRAY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_IMAGE_2D_ARRAY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_IMAGE_CUBE_MAP_ARRAY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_IMAGE_2D_MULTISAMPLE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_IMAGE_1D_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_IMAGE_2D_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_IMAGE_3D_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_IMAGE_2D_RECT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_IMAGE_CUBE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_IMAGE_BUFFER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_IMAGE_1D_ARRAY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_IMAGE_2D_ARRAY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_IMAGE_SAMPLES_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_BINDING_FORMAT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_ELEMENT_ARRAY_BARRIER_BIT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNIFORM_BARRIER_BIT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_FETCH_BARRIER_BIT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMMAND_BARRIER_BIT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_BUFFER_BARRIER_BIT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_UPDATE_BARRIER_BIT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_BUFFER_UPDATE_BARRIER_BIT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEBUFFER_BARRIER_BIT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK_BARRIER_BIT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATOMIC_COUNTER_BARRIER_BIT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALL_BARRIER_BITS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_shadow_funcs);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_shared_texture_palette);
    CREATE_GL_BASIC_BIC_STATIC(GL_SHARED_TEXTURE_PALETTE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_stencil_clear_tag);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_TAG_BITS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_CLEAR_TAG_VALUE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_stencil_two_side);
    CREATE_GL_BASIC_BIC_STATIC(GL_STENCIL_TEST_TWO_SIDE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_ACTIVE_STENCIL_FACE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_stencil_wrap);
    CREATE_GL_BASIC_BIC_STATIC(GL_INCR_WRAP_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_DECR_WRAP_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_subtexture);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_texture);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA4_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA8_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA12_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA16_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE4_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE8_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE12_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE16_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE4_ALPHA4_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE6_ALPHA2_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE8_ALPHA8_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE12_ALPHA4_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE12_ALPHA12_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE16_ALPHA16_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTENSITY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTENSITY4_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTENSITY8_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTENSITY12_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTENSITY16_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB2_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB4_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB5_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB8_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB10_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB12_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB16_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA2_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA4_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB5_A1_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA8_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB10_A2_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA12_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA16_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_RED_SIZE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_GREEN_SIZE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BLUE_SIZE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_ALPHA_SIZE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_LUMINANCE_SIZE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_INTENSITY_SIZE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_REPLACE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROXY_TEXTURE_1D_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROXY_TEXTURE_2D_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_TOO_LARGE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_texture3D);
    CREATE_GL_BASIC_BIC_STATIC(GL_PACK_SKIP_IMAGES_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_PACK_IMAGE_HEIGHT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNPACK_SKIP_IMAGES_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNPACK_IMAGE_HEIGHT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_3D_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROXY_TEXTURE_3D_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_DEPTH_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_WRAP_R_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_3D_TEXTURE_SIZE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_texture_array);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPARE_REF_DEPTH_TO_TEXTURE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_texture_buffer_object);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BUFFER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TEXTURE_BUFFER_SIZE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BINDING_BUFFER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BUFFER_DATA_STORE_BINDING_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BUFFER_FORMAT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_texture_compression_latc);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_LUMINANCE_LATC1_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SIGNED_LUMINANCE_LATC1_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_LUMINANCE_ALPHA_LATC2_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SIGNED_LUMINANCE_ALPHA_LATC2_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_texture_compression_rgtc);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_RED_RGTC1_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SIGNED_RED_RGTC1_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_RED_GREEN_RGTC2_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SIGNED_RED_GREEN_RGTC2_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_texture_compression_s3tc);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_RGB_S3TC_DXT1_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_RGBA_S3TC_DXT1_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_RGBA_S3TC_DXT3_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_RGBA_S3TC_DXT5_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_texture_cube_map);
    CREATE_GL_BASIC_BIC_STATIC(GL_NORMAL_MAP_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_REFLECTION_MAP_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CUBE_MAP_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BINDING_CUBE_MAP_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CUBE_MAP_POSITIVE_X_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CUBE_MAP_NEGATIVE_X_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CUBE_MAP_POSITIVE_Y_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CUBE_MAP_POSITIVE_Z_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROXY_TEXTURE_CUBE_MAP_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_CUBE_MAP_TEXTURE_SIZE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_texture_env_add);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_texture_env_combine);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMBINE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMBINE_RGB_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMBINE_ALPHA_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB_SCALE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_ADD_SIGNED_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTERPOLATE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONSTANT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_PRIMARY_COLOR_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_PREVIOUS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SOURCE0_RGB_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SOURCE1_RGB_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SOURCE2_RGB_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SOURCE0_ALPHA_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SOURCE1_ALPHA_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SOURCE2_ALPHA_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OPERAND0_RGB_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OPERAND1_RGB_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OPERAND2_RGB_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OPERAND0_ALPHA_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OPERAND1_ALPHA_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OPERAND2_ALPHA_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_texture_env_dot3);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOT3_RGB_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOT3_RGBA_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_texture_filter_anisotropic);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_MAX_ANISOTROPY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_texture_integer);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA32UI_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB32UI_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA32UI_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTENSITY32UI_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE32UI_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE_ALPHA32UI_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA16UI_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB16UI_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA16UI_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTENSITY16UI_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE16UI_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE_ALPHA16UI_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA8UI_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB8UI_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA8UI_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTENSITY8UI_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE8UI_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE_ALPHA8UI_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA32I_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB32I_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA32I_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTENSITY32I_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE32I_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE_ALPHA32I_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA16I_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB16I_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA16I_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTENSITY16I_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE16I_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE_ALPHA16I_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA8I_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB8I_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA8I_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTENSITY8I_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE8I_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE_ALPHA8I_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RED_INTEGER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_GREEN_INTEGER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLUE_INTEGER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA_INTEGER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB_INTEGER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA_INTEGER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_BGR_INTEGER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_BGRA_INTEGER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE_INTEGER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE_ALPHA_INTEGER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA_INTEGER_MODE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_texture_lod_bias);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TEXTURE_LOD_BIAS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_FILTER_CONTROL_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_LOD_BIAS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_texture_mirror_clamp);
    CREATE_GL_BASIC_BIC_STATIC(GL_MIRROR_CLAMP_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MIRROR_CLAMP_TO_EDGE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MIRROR_CLAMP_TO_BORDER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_texture_object);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_PRIORITY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_RESIDENT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_1D_BINDING_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_2D_BINDING_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_3D_BINDING_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_texture_perturb_normal);
    CREATE_GL_BASIC_BIC_STATIC(GL_PERTURB_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_NORMAL_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_texture_sRGB);
    CREATE_GL_BASIC_BIC_STATIC(GL_SRGB_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SRGB8_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SRGB_ALPHA_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SRGB8_ALPHA8_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SLUMINANCE_ALPHA_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SLUMINANCE8_ALPHA8_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SLUMINANCE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SLUMINANCE8_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SRGB_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SRGB_ALPHA_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SLUMINANCE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SLUMINANCE_ALPHA_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SRGB_S3TC_DXT1_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_texture_sRGB_decode);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_SRGB_DECODE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_DECODE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SKIP_DECODE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_texture_shared_exponent);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB9_E5_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_5_9_9_9_REV_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_SHARED_SIZE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_texture_snorm);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA_SNORM);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE_SNORM);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE_ALPHA_SNORM);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTENSITY_SNORM);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA8_SNORM);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE8_SNORM);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE8_ALPHA8_SNORM);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTENSITY8_SNORM);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA16_SNORM);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE16_SNORM);
    CREATE_GL_BASIC_BIC_STATIC(GL_LUMINANCE16_ALPHA16_SNORM);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTENSITY16_SNORM);
    CREATE_GL_BASIC_BIC_STATIC(GL_RED_SNORM);
    CREATE_GL_BASIC_BIC_STATIC(GL_RG_SNORM);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB_SNORM);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA_SNORM);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_texture_swizzle);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_SWIZZLE_R_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_SWIZZLE_G_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_SWIZZLE_B_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_SWIZZLE_A_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_SWIZZLE_RGBA_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_timer_query);
    CREATE_GL_BASIC_BIC_STATIC(GL_TIME_ELAPSED_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_transform_feedback);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK_BUFFER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK_BUFFER_START_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTERLEAVED_ATTRIBS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SEPARATE_ATTRIBS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_PRIMITIVES_GENERATED_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_RASTERIZER_DISCARD_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK_VARYINGS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK_BUFFER_MODE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_vertex_array);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ARRAY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_NORMAL_ARRAY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ARRAY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INDEX_ARRAY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COORD_ARRAY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EDGE_FLAG_ARRAY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ARRAY_SIZE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ARRAY_TYPE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ARRAY_STRIDE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ARRAY_COUNT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_NORMAL_ARRAY_TYPE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_NORMAL_ARRAY_STRIDE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_NORMAL_ARRAY_COUNT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ARRAY_SIZE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ARRAY_TYPE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ARRAY_STRIDE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ARRAY_COUNT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INDEX_ARRAY_TYPE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INDEX_ARRAY_STRIDE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INDEX_ARRAY_COUNT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COORD_ARRAY_SIZE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COORD_ARRAY_TYPE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COORD_ARRAY_STRIDE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COORD_ARRAY_COUNT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EDGE_FLAG_ARRAY_STRIDE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EDGE_FLAG_ARRAY_COUNT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ARRAY_POINTER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_NORMAL_ARRAY_POINTER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ARRAY_POINTER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INDEX_ARRAY_POINTER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COORD_ARRAY_POINTER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EDGE_FLAG_ARRAY_POINTER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_vertex_array_bgra);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_vertex_attrib_64bit);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOUBLE_VEC2_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOUBLE_VEC3_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOUBLE_VEC4_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOUBLE_MAT2_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOUBLE_MAT3_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOUBLE_MAT4_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOUBLE_MAT2x3_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOUBLE_MAT2x4_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOUBLE_MAT3x2_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOUBLE_MAT3x4_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOUBLE_MAT4x2_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOUBLE_MAT4x3_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_vertex_shader);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_SHADER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_SHADER_BINDING_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OP_INDEX_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OP_NEGATE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OP_DOT3_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OP_DOT4_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OP_MUL_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OP_ADD_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OP_MADD_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OP_FRAC_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OP_MAX_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OP_MIN_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OP_SET_GE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OP_SET_LT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OP_CLAMP_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OP_FLOOR_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OP_ROUND_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OP_EXP_BASE_2_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OP_LOG_BASE_2_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OP_POWER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OP_RECIP_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OP_RECIP_SQRT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OP_SUB_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OP_CROSS_PRODUCT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OP_MULTIPLY_MATRIX_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OP_MOV_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUTPUT_VERTEX_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUTPUT_COLOR0_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUTPUT_COLOR1_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUTPUT_TEXTURE_COORD0_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUTPUT_TEXTURE_COORD1_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUTPUT_TEXTURE_COORD2_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUTPUT_TEXTURE_COORD3_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUTPUT_TEXTURE_COORD4_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUTPUT_TEXTURE_COORD5_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUTPUT_TEXTURE_COORD6_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUTPUT_TEXTURE_COORD7_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUTPUT_TEXTURE_COORD8_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUTPUT_TEXTURE_COORD9_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUTPUT_TEXTURE_COORD10_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUTPUT_TEXTURE_COORD11_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUTPUT_TEXTURE_COORD12_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUTPUT_TEXTURE_COORD13_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUTPUT_TEXTURE_COORD14_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUTPUT_TEXTURE_COORD15_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUTPUT_TEXTURE_COORD16_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUTPUT_TEXTURE_COORD17_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUTPUT_TEXTURE_COORD18_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUTPUT_TEXTURE_COORD19_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUTPUT_TEXTURE_COORD20_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUTPUT_TEXTURE_COORD21_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUTPUT_TEXTURE_COORD22_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUTPUT_TEXTURE_COORD23_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUTPUT_TEXTURE_COORD24_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUTPUT_TEXTURE_COORD25_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUTPUT_TEXTURE_COORD26_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUTPUT_TEXTURE_COORD27_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUTPUT_TEXTURE_COORD28_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUTPUT_TEXTURE_COORD29_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUTPUT_TEXTURE_COORD30_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUTPUT_TEXTURE_COORD31_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_OUTPUT_FOG_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_SCALAR_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_VECTOR_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_VARIANT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INVARIANT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LOCAL_CONSTANT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LOCAL_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VERTEX_SHADER_INSTRUCTIONS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VERTEX_SHADER_VARIANTS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VERTEX_SHADER_INVARIANTS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VERTEX_SHADER_LOCAL_CONSTANTS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VERTEX_SHADER_LOCALS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_OPTIMIZED_VERTEX_SHADER_INSTRUCTIONS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_OPTIMIZED_VERTEX_SHADER_VARIANTS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCAL_CONSTANTS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_OPTIMIZED_VERTEX_SHADER_INVARIANTS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCALS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_SHADER_INSTRUCTIONS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_SHADER_VARIANTS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_SHADER_INVARIANTS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_SHADER_LOCAL_CONSTANTS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_SHADER_LOCALS_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_SHADER_OPTIMIZED_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_X_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_Y_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_Z_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_W_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_NEGATIVE_X_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_NEGATIVE_Y_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_NEGATIVE_Z_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_NEGATIVE_W_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_ZERO_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_ONE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_NEGATIVE_ONE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_NORMALIZED_RANGE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_FULL_RANGE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_VERTEX_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MVP_MATRIX_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_VARIANT_VALUE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_VARIANT_DATATYPE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_VARIANT_ARRAY_STRIDE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_VARIANT_ARRAY_TYPE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_VARIANT_ARRAY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_VARIANT_ARRAY_POINTER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INVARIANT_VALUE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_INVARIANT_DATATYPE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LOCAL_CONSTANT_VALUE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_LOCAL_CONSTANT_DATATYPE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_vertex_weighting);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW0_STACK_DEPTH_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW1_STACK_DEPTH_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW0_MATRIX_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW1_MATRIX_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_WEIGHTING_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW0_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW1_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_VERTEX_WEIGHT_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_WEIGHT_ARRAY_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_WEIGHT_ARRAY_SIZE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_WEIGHT_ARRAY_TYPE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_WEIGHT_ARRAY_STRIDE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_WEIGHT_ARRAY_POINTER_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXT_x11_sync_object);
    CREATE_GL_BASIC_BIC_STATIC(GL_SYNC_X11_FENCE_EXT);
    CREATE_GL_BASIC_BIC_STATIC(GL_GREMEDY_frame_terminator);
    CREATE_GL_BASIC_BIC_STATIC(GL_GREMEDY_string_marker);
    CREATE_GL_BASIC_BIC_STATIC(GL_HP_convolution_border_modes);
    CREATE_GL_BASIC_BIC_STATIC(GL_IGNORE_BORDER_HP);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONSTANT_BORDER_HP);
    CREATE_GL_BASIC_BIC_STATIC(GL_REPLICATE_BORDER_HP);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONVOLUTION_BORDER_COLOR_HP);
    CREATE_GL_BASIC_BIC_STATIC(GL_HP_image_transform);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_SCALE_X_HP);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_SCALE_Y_HP);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_TRANSLATE_X_HP);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_TRANSLATE_Y_HP);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_ROTATE_ANGLE_HP);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_ROTATE_ORIGIN_X_HP);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_ROTATE_ORIGIN_Y_HP);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_MAG_FILTER_HP);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_MIN_FILTER_HP);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_CUBIC_WEIGHT_HP);
    CREATE_GL_BASIC_BIC_STATIC(GL_CUBIC_HP);
    CREATE_GL_BASIC_BIC_STATIC(GL_AVERAGE_HP);
    CREATE_GL_BASIC_BIC_STATIC(GL_IMAGE_TRANSFORM_2D_HP);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_IMAGE_TRANSFORM_COLOR_TABLE_HP);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROXY_POST_IMAGE_TRANSFORM_COLOR_TABLE_HP);
    CREATE_GL_BASIC_BIC_STATIC(GL_HP_occlusion_test);
    CREATE_GL_BASIC_BIC_STATIC(GL_OCCLUSION_TEST_HP);
    CREATE_GL_BASIC_BIC_STATIC(GL_OCCLUSION_TEST_RESULT_HP);
    CREATE_GL_BASIC_BIC_STATIC(GL_HP_texture_lighting);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_LIGHTING_MODE_HP);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_POST_SPECULAR_HP);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_PRE_SPECULAR_HP);
    CREATE_GL_BASIC_BIC_STATIC(GL_IBM_cull_vertex);
    CREATE_GL_BASIC_BIC_STATIC(GL_CULL_VERTEX_IBM);
    CREATE_GL_BASIC_BIC_STATIC(GL_IBM_multimode_draw_arrays);
    CREATE_GL_BASIC_BIC_STATIC(GL_IBM_rasterpos_clip);
    CREATE_GL_BASIC_BIC_STATIC(GL_RASTER_POSITION_UNCLIPPED_IBM);
    CREATE_GL_BASIC_BIC_STATIC(GL_IBM_static_data);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALL_STATIC_DATA_IBM);
    CREATE_GL_BASIC_BIC_STATIC(GL_STATIC_VERTEX_ARRAY_IBM);
    CREATE_GL_BASIC_BIC_STATIC(GL_IBM_texture_mirrored_repeat);
    CREATE_GL_BASIC_BIC_STATIC(GL_MIRRORED_REPEAT_IBM);
    CREATE_GL_BASIC_BIC_STATIC(GL_IBM_vertex_array_lists);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ARRAY_LIST_IBM);
    CREATE_GL_BASIC_BIC_STATIC(GL_NORMAL_ARRAY_LIST_IBM);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ARRAY_LIST_IBM);
    CREATE_GL_BASIC_BIC_STATIC(GL_INDEX_ARRAY_LIST_IBM);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COORD_ARRAY_LIST_IBM);
    CREATE_GL_BASIC_BIC_STATIC(GL_EDGE_FLAG_ARRAY_LIST_IBM);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_COORDINATE_ARRAY_LIST_IBM);
    CREATE_GL_BASIC_BIC_STATIC(GL_SECONDARY_COLOR_ARRAY_LIST_IBM);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ARRAY_LIST_STRIDE_IBM);
    CREATE_GL_BASIC_BIC_STATIC(GL_NORMAL_ARRAY_LIST_STRIDE_IBM);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ARRAY_LIST_STRIDE_IBM);
    CREATE_GL_BASIC_BIC_STATIC(GL_INDEX_ARRAY_LIST_STRIDE_IBM);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COORD_ARRAY_LIST_STRIDE_IBM);
    CREATE_GL_BASIC_BIC_STATIC(GL_EDGE_FLAG_ARRAY_LIST_STRIDE_IBM);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_COORDINATE_ARRAY_LIST_STRIDE_IBM);
    CREATE_GL_BASIC_BIC_STATIC(GL_SECONDARY_COLOR_ARRAY_LIST_STRIDE_IBM);
    CREATE_GL_BASIC_BIC_STATIC(GL_INGR_blend_func_separate);
    CREATE_GL_BASIC_BIC_STATIC(GL_INGR_color_clamp);
    CREATE_GL_BASIC_BIC_STATIC(GL_RED_MIN_CLAMP_INGR);
    CREATE_GL_BASIC_BIC_STATIC(GL_GREEN_MIN_CLAMP_INGR);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLUE_MIN_CLAMP_INGR);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA_MIN_CLAMP_INGR);
    CREATE_GL_BASIC_BIC_STATIC(GL_RED_MAX_CLAMP_INGR);
    CREATE_GL_BASIC_BIC_STATIC(GL_GREEN_MAX_CLAMP_INGR);
    CREATE_GL_BASIC_BIC_STATIC(GL_BLUE_MAX_CLAMP_INGR);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA_MAX_CLAMP_INGR);
    CREATE_GL_BASIC_BIC_STATIC(GL_INGR_interlace_read);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTERLACE_READ_INGR);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTEL_map_texture);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_MEMORY_LAYOUT_INTEL);
    CREATE_GL_BASIC_BIC_STATIC(GL_LAYOUT_DEFAULT_INTEL);
    CREATE_GL_BASIC_BIC_STATIC(GL_LAYOUT_LINEAR_INTEL);
    CREATE_GL_BASIC_BIC_STATIC(GL_LAYOUT_LINEAR_CPU_CACHED_INTEL);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTEL_parallel_arrays);
    CREATE_GL_BASIC_BIC_STATIC(GL_PARALLEL_ARRAYS_INTEL);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ARRAY_PARALLEL_POINTERS_INTEL);
    CREATE_GL_BASIC_BIC_STATIC(GL_NORMAL_ARRAY_PARALLEL_POINTERS_INTEL);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ARRAY_PARALLEL_POINTERS_INTEL);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COORD_ARRAY_PARALLEL_POINTERS_INTEL);
    CREATE_GL_BASIC_BIC_STATIC(GL_MESAX_texture_stack);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_1D_STACK_MESAX);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_2D_STACK_MESAX);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROXY_TEXTURE_1D_STACK_MESAX);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROXY_TEXTURE_2D_STACK_MESAX);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_1D_STACK_BINDING_MESAX);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_2D_STACK_BINDING_MESAX);
    CREATE_GL_BASIC_BIC_STATIC(GL_MESA_pack_invert);
    CREATE_GL_BASIC_BIC_STATIC(GL_PACK_INVERT_MESA);
    CREATE_GL_BASIC_BIC_STATIC(GL_MESA_resize_buffers);
    CREATE_GL_BASIC_BIC_STATIC(GL_MESA_window_pos);
    CREATE_GL_BASIC_BIC_STATIC(GL_MESA_ycbcr_texture);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_SHORT_8_8_MESA);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_SHORT_8_8_REV_MESA);
    CREATE_GL_BASIC_BIC_STATIC(GL_YCBCR_MESA);
    CREATE_GL_BASIC_BIC_STATIC(GL_NVX_conditional_render);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_bindless_texture);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_blend_square);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_compute_program5);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPUTE_PROGRAM_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMPUTE_PROGRAM_PARAMETER_BUFFER_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_conditional_render);
    CREATE_GL_BASIC_BIC_STATIC(GL_QUERY_WAIT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_QUERY_NO_WAIT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_QUERY_BY_REGION_WAIT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_QUERY_BY_REGION_NO_WAIT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_copy_depth_to_color);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_STENCIL_TO_RGBA_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_STENCIL_TO_BGRA_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_copy_image);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_deep_texture3D);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_DEEP_3D_TEXTURE_WIDTH_HEIGHT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_DEEP_3D_TEXTURE_DEPTH_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_depth_buffer_float);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_COMPONENT32F_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH32F_STENCIL8_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_32_UNSIGNED_INT_24_8_REV_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_BUFFER_FLOAT_MODE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_depth_clamp);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_CLAMP_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_draw_texture);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_evaluators);
    CREATE_GL_BASIC_BIC_STATIC(GL_EVAL_2D_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_EVAL_TRIANGULAR_2D_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP_TESSELLATION_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP_ATTRIB_U_ORDER_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP_ATTRIB_V_ORDER_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_EVAL_FRACTIONAL_TESSELLATION_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_EVAL_VERTEX_ATTRIB0_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_EVAL_VERTEX_ATTRIB1_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_EVAL_VERTEX_ATTRIB2_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_EVAL_VERTEX_ATTRIB3_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_EVAL_VERTEX_ATTRIB4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_EVAL_VERTEX_ATTRIB5_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_EVAL_VERTEX_ATTRIB6_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_EVAL_VERTEX_ATTRIB7_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_EVAL_VERTEX_ATTRIB8_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_EVAL_VERTEX_ATTRIB9_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_EVAL_VERTEX_ATTRIB10_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_EVAL_VERTEX_ATTRIB11_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_EVAL_VERTEX_ATTRIB12_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_EVAL_VERTEX_ATTRIB13_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_EVAL_VERTEX_ATTRIB14_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_EVAL_VERTEX_ATTRIB15_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_MAP_TESSELLATION_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_RATIONAL_EVAL_ORDER_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_explicit_multisample);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_POSITION_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_MASK_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_MASK_VALUE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BINDING_RENDERBUFFER_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_RENDERBUFFER_DATA_STORE_BINDING_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_RENDERBUFFER_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLER_RENDERBUFFER_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT_SAMPLER_RENDERBUFFER_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_SAMPLER_RENDERBUFFER_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_SAMPLE_MASK_WORDS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_fence);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALL_COMPLETED_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FENCE_STATUS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FENCE_CONDITION_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_float_buffer);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_R_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_RG_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_RGB_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_RGBA_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_R16_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_R32_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_RG16_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_RG32_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_RGB16_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_RGB32_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_RGBA16_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_RGBA32_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_FLOAT_COMPONENTS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_CLEAR_COLOR_VALUE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT_RGBA_MODE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_fog_distance);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_DISTANCE_MODE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_EYE_RADIAL_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_EYE_PLANE_ABSOLUTE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_fragment_program);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_FRAGMENT_PROGRAM_LOCAL_PARAMETERS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAGMENT_PROGRAM_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TEXTURE_COORDS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TEXTURE_IMAGE_UNITS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAGMENT_PROGRAM_BINDING_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_ERROR_STRING_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_fragment_program2);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_EXEC_INSTRUCTIONS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_CALL_DEPTH_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_IF_DEPTH_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_LOOP_DEPTH_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_LOOP_COUNT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_fragment_program4);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_fragment_program_option);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_framebuffer_multisample_coverage);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER_COVERAGE_SAMPLES_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_RENDERBUFFER_COLOR_SAMPLES_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_MULTISAMPLE_COVERAGE_MODES_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MULTISAMPLE_COVERAGE_MODES_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_geometry_program4);
    CREATE_GL_BASIC_BIC_STATIC(GL_GEOMETRY_PROGRAM_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_OUTPUT_VERTICES_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_TOTAL_OUTPUT_COMPONENTS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_geometry_shader4);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_gpu_program4);
    CREATE_GL_BASIC_BIC_STATIC(GL_MIN_PROGRAM_TEXEL_OFFSET_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_TEXEL_OFFSET_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_ATTRIB_COMPONENTS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_RESULT_COMPONENTS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_ATTRIB_COMPONENTS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_RESULT_COMPONENTS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_GENERIC_ATTRIBS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_GENERIC_RESULTS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_gpu_program5);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_GEOMETRY_PROGRAM_INVOCATIONS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MIN_FRAGMENT_INTERPOLATION_OFFSET_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_FRAGMENT_INTERPOLATION_OFFSET_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAGMENT_PROGRAM_INTERPOLATION_OFFSET_BITS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_SUBROUTINE_PARAMETERS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_SUBROUTINE_NUM_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_gpu_shader5);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT64_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT64_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT8_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT8_VEC2_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT8_VEC3_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT8_VEC4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT16_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT16_VEC2_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT16_VEC3_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT16_VEC4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT64_VEC2_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT64_VEC3_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_INT64_VEC4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT8_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT8_VEC2_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT8_VEC3_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT8_VEC4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT16_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT16_VEC2_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT16_VEC3_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT16_VEC4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT64_VEC2_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT64_VEC3_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT64_VEC4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT16_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT16_VEC2_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT16_VEC3_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FLOAT16_VEC4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_half_float);
    CREATE_GL_BASIC_BIC_STATIC(GL_HALF_FLOAT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_light_max_exponent);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_SHININESS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_SPOT_EXPONENT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_multisample_coverage);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_SAMPLES_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_multisample_filter_hint);
    CREATE_GL_BASIC_BIC_STATIC(GL_MULTISAMPLE_FILTER_HINT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_occlusion_query);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_COUNTER_BITS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_OCCLUSION_QUERY_ID_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_COUNT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_COUNT_AVAILABLE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_packed_depth_stencil);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_STENCIL_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_24_8_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_parameter_buffer_object);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_PARAMETER_BUFFER_BINDINGS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_PARAMETER_BUFFER_SIZE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_PROGRAM_PARAMETER_BUFFER_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_GEOMETRY_PROGRAM_PARAMETER_BUFFER_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAGMENT_PROGRAM_PARAMETER_BUFFER_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_parameter_buffer_object2);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_path_rendering);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_FORMAT_SVG_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_FORMAT_PS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_STANDARD_FONT_NAME_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SYSTEM_FONT_NAME_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FILE_NAME_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_STROKE_WIDTH_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_END_CAPS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_INITIAL_END_CAP_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_TERMINAL_END_CAP_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_JOIN_STYLE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_MITER_LIMIT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_DASH_CAPS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_INITIAL_DASH_CAP_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_TERMINAL_DASH_CAP_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_DASH_OFFSET_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_CLIENT_LENGTH_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_FILL_MODE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_FILL_MASK_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_FILL_COVER_MODE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_STROKE_COVER_MODE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_STROKE_MASK_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_COUNT_UP_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_COUNT_DOWN_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_OBJECT_BOUNDING_BOX_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONVEX_HULL_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_BOUNDING_BOX_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSLATE_X_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSLATE_Y_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSLATE_2D_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSLATE_3D_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_AFFINE_2D_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_AFFINE_3D_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSPOSE_AFFINE_2D_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSPOSE_AFFINE_3D_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_UTF8_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_UTF16_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_BOUNDING_BOX_OF_BOUNDING_BOXES_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_COMMAND_COUNT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_COORD_COUNT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_DASH_ARRAY_COUNT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_COMPUTED_LENGTH_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_FILL_BOUNDING_BOX_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_STROKE_BOUNDING_BOX_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SQUARE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_ROUND_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRIANGULAR_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_BEVEL_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MITER_REVERT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MITER_TRUNCATE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SKIP_MISSING_GLYPH_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_USE_MISSING_GLYPH_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_ERROR_POSITION_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_FOG_GEN_MODE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_ACCUM_ADJACENT_PAIRS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_ADJACENT_PAIRS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FIRST_TO_REST_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_GEN_MODE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_GEN_COEFF_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_GEN_COLOR_FORMAT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_GEN_COMPONENTS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_STENCIL_FUNC_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_STENCIL_REF_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_STENCIL_VALUE_MASK_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_STENCIL_DEPTH_OFFSET_FACTOR_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_STENCIL_DEPTH_OFFSET_UNITS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_COVER_DEPTH_FUNC_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PATH_DASH_OFFSET_RESET_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MOVE_TO_RESETS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MOVE_TO_CONTINUES_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLOSE_PATH_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MOVE_TO_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_RELATIVE_MOVE_TO_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINE_TO_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_RELATIVE_LINE_TO_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_HORIZONTAL_LINE_TO_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_RELATIVE_HORIZONTAL_LINE_TO_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTICAL_LINE_TO_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_RELATIVE_VERTICAL_LINE_TO_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_QUADRATIC_CURVE_TO_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_RELATIVE_QUADRATIC_CURVE_TO_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_CUBIC_CURVE_TO_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_RELATIVE_CUBIC_CURVE_TO_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SMOOTH_QUADRATIC_CURVE_TO_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SMOOTH_CUBIC_CURVE_TO_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SMALL_CCW_ARC_TO_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_RELATIVE_SMALL_CCW_ARC_TO_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SMALL_CW_ARC_TO_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_RELATIVE_SMALL_CW_ARC_TO_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_LARGE_CCW_ARC_TO_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_RELATIVE_LARGE_CCW_ARC_TO_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_LARGE_CW_ARC_TO_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_RELATIVE_LARGE_CW_ARC_TO_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_RESTART_PATH_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_DUP_FIRST_CUBIC_CURVE_TO_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_DUP_LAST_CUBIC_CURVE_TO_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_RECT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_CIRCULAR_CCW_ARC_TO_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_CIRCULAR_CW_ARC_TO_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_CIRCULAR_TANGENT_ARC_TO_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_ARC_TO_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_RELATIVE_ARC_TO_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_BOLD_BIT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_ITALIC_BIT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_GLYPH_WIDTH_BIT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_GLYPH_HEIGHT_BIT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_GLYPH_HORIZONTAL_BEARING_X_BIT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_GLYPH_HORIZONTAL_BEARING_Y_BIT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_GLYPH_HORIZONTAL_BEARING_ADVANCE_BIT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_GLYPH_VERTICAL_BEARING_X_BIT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_GLYPH_VERTICAL_BEARING_Y_BIT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_GLYPH_VERTICAL_BEARING_ADVANCE_BIT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_GLYPH_HAS_KERNING_BIT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FONT_X_MIN_BOUNDS_BIT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FONT_Y_MIN_BOUNDS_BIT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FONT_X_MAX_BOUNDS_BIT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FONT_Y_MAX_BOUNDS_BIT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FONT_UNITS_PER_EM_BIT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FONT_ASCENDER_BIT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FONT_DESCENDER_BIT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FONT_HEIGHT_BIT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FONT_MAX_ADVANCE_WIDTH_BIT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FONT_MAX_ADVANCE_HEIGHT_BIT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FONT_UNDERLINE_POSITION_BIT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FONT_UNDERLINE_THICKNESS_BIT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FONT_HAS_KERNING_BIT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PRIMARY_COLOR_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SECONDARY_COLOR_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_pixel_data_range);
    CREATE_GL_BASIC_BIC_STATIC(GL_WRITE_PIXEL_DATA_RANGE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_READ_PIXEL_DATA_RANGE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_WRITE_PIXEL_DATA_RANGE_LENGTH_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_READ_PIXEL_DATA_RANGE_LENGTH_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_WRITE_PIXEL_DATA_RANGE_POINTER_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_READ_PIXEL_DATA_RANGE_POINTER_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_point_sprite);
    CREATE_GL_BASIC_BIC_STATIC(GL_POINT_SPRITE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_COORD_REPLACE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_POINT_SPRITE_R_MODE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_present_video);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAME_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FIELDS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_TIME_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NUM_FILL_STREAMS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PRESENT_TIME_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PRESENT_DURATION_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_primitive_restart);
    CREATE_GL_BASIC_BIC_STATIC(GL_PRIMITIVE_RESTART_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PRIMITIVE_RESTART_INDEX_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_register_combiners);
    CREATE_GL_BASIC_BIC_STATIC(GL_REGISTER_COMBINERS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VARIABLE_A_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VARIABLE_B_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VARIABLE_C_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VARIABLE_D_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VARIABLE_E_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VARIABLE_F_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VARIABLE_G_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONSTANT_COLOR0_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONSTANT_COLOR1_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SPARE0_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SPARE1_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_DISCARD_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_E_TIMES_F_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SPARE0_PLUS_SECONDARY_COLOR_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_IDENTITY_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INVERT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXPAND_NORMAL_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_EXPAND_NEGATE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_HALF_BIAS_NORMAL_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_HALF_BIAS_NEGATE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SIGNED_IDENTITY_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SIGNED_NEGATE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SCALE_BY_TWO_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SCALE_BY_FOUR_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SCALE_BY_ONE_HALF_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_BIAS_BY_NEGATIVE_ONE_HALF_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMBINER_INPUT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMBINER_MAPPING_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMBINER_COMPONENT_USAGE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMBINER_AB_DOT_PRODUCT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMBINER_CD_DOT_PRODUCT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMBINER_MUX_SUM_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMBINER_SCALE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMBINER_BIAS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMBINER_AB_OUTPUT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMBINER_CD_OUTPUT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMBINER_SUM_OUTPUT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_GENERAL_COMBINERS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NUM_GENERAL_COMBINERS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_SUM_CLAMP_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMBINER0_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMBINER1_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMBINER2_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMBINER3_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMBINER4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMBINER5_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMBINER6_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMBINER7_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_register_combiners2);
    CREATE_GL_BASIC_BIC_STATIC(GL_PER_STAGE_CONSTANTS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_shader_atomic_counters);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_shader_atomic_float);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_shader_buffer_load);
    CREATE_GL_BASIC_BIC_STATIC(GL_BUFFER_GPU_ADDRESS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_GPU_ADDRESS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_SHADER_BUFFER_ADDRESS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_shader_buffer_store);
    CREATE_GL_BASIC_BIC_STATIC(GL_SHADER_GLOBAL_ACCESS_BARRIER_BIT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_shader_storage_buffer_object);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_tessellation_program5);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_PROGRAM_PATCH_ATTRIBS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TESS_CONTROL_PROGRAM_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TESS_EVALUATION_PROGRAM_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TESS_CONTROL_PROGRAM_PARAMETER_BUFFER_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TESS_EVALUATION_PROGRAM_PARAMETER_BUFFER_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_texgen_emboss);
    CREATE_GL_BASIC_BIC_STATIC(GL_EMBOSS_LIGHT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_EMBOSS_CONSTANT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_EMBOSS_MAP_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_texgen_reflection);
    CREATE_GL_BASIC_BIC_STATIC(GL_NORMAL_MAP_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_REFLECTION_MAP_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_texture_barrier);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_texture_compression_vtc);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_texture_env_combine4);
    CREATE_GL_BASIC_BIC_STATIC(GL_COMBINE4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SOURCE3_RGB_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SOURCE3_ALPHA_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_OPERAND3_RGB_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_OPERAND3_ALPHA_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_texture_expand_normal);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_UNSIGNED_REMAP_MODE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_texture_multisample);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COVERAGE_SAMPLES_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COLOR_SAMPLES_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_texture_rectangle);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_RECTANGLE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BINDING_RECTANGLE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROXY_TEXTURE_RECTANGLE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_RECTANGLE_TEXTURE_SIZE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_texture_shader);
    CREATE_GL_BASIC_BIC_STATIC(GL_OFFSET_TEXTURE_RECTANGLE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_OFFSET_TEXTURE_RECTANGLE_SCALE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOT_PRODUCT_TEXTURE_RECTANGLE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA_UNSIGNED_DOT_PRODUCT_MAPPING_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_S8_S8_8_8_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNSIGNED_INT_8_8_S8_S8_REV_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_DSDT_MAG_INTENSITY_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SHADER_CONSISTENT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_SHADER_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SHADER_OPERATION_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_CULL_MODES_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_OFFSET_TEXTURE_MATRIX_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_OFFSET_TEXTURE_SCALE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_OFFSET_TEXTURE_BIAS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_OFFSET_TEXTURE_2D_MATRIX_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_OFFSET_TEXTURE_2D_SCALE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_OFFSET_TEXTURE_2D_BIAS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PREVIOUS_TEXTURE_INPUT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONST_EYE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PASS_THROUGH_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_CULL_FRAGMENT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_OFFSET_TEXTURE_2D_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPENDENT_AR_TEXTURE_2D_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPENDENT_GB_TEXTURE_2D_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOT_PRODUCT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOT_PRODUCT_DEPTH_REPLACE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOT_PRODUCT_TEXTURE_2D_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOT_PRODUCT_TEXTURE_CUBE_MAP_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOT_PRODUCT_DIFFUSE_CUBE_MAP_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOT_PRODUCT_REFLECT_CUBE_MAP_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOT_PRODUCT_CONST_EYE_REFLECT_CUBE_MAP_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_HILO_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_DSDT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_DSDT_MAG_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_DSDT_MAG_VIB_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_HILO16_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SIGNED_HILO_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SIGNED_HILO16_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SIGNED_RGBA_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SIGNED_RGBA8_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SIGNED_RGB_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SIGNED_RGB8_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SIGNED_LUMINANCE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SIGNED_LUMINANCE8_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SIGNED_LUMINANCE_ALPHA_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SIGNED_LUMINANCE8_ALPHA8_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SIGNED_ALPHA_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SIGNED_ALPHA8_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SIGNED_INTENSITY_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SIGNED_INTENSITY8_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_DSDT8_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_DSDT8_MAG8_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_DSDT8_MAG8_INTENSITY8_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SIGNED_RGB_UNSIGNED_ALPHA_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SIGNED_RGB8_UNSIGNED_ALPHA8_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_HI_SCALE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_LO_SCALE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_DS_SCALE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_DT_SCALE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAGNITUDE_SCALE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIBRANCE_SCALE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_HI_BIAS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_LO_BIAS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_DS_BIAS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_DT_BIAS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAGNITUDE_BIAS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIBRANCE_BIAS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BORDER_VALUES_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_HI_SIZE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_LO_SIZE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_DS_SIZE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_DT_SIZE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_MAG_SIZE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_texture_shader2);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOT_PRODUCT_TEXTURE_3D_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_texture_shader3);
    CREATE_GL_BASIC_BIC_STATIC(GL_OFFSET_PROJECTIVE_TEXTURE_2D_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_OFFSET_PROJECTIVE_TEXTURE_2D_SCALE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_SCALE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_OFFSET_HILO_TEXTURE_2D_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_OFFSET_HILO_TEXTURE_RECTANGLE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_OFFSET_HILO_PROJECTIVE_TEXTURE_2D_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_OFFSET_HILO_PROJECTIVE_TEXTURE_RECTANGLE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPENDENT_HILO_TEXTURE_2D_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPENDENT_RGB_TEXTURE_3D_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPENDENT_RGB_TEXTURE_CUBE_MAP_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOT_PRODUCT_PASS_THROUGH_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOT_PRODUCT_TEXTURE_1D_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_DOT_PRODUCT_AFFINE_DEPTH_REPLACE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_HILO8_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SIGNED_HILO8_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FORCE_BLUE_TO_ONE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_transform_feedback);
    CREATE_GL_BASIC_BIC_STATIC(GL_BACK_PRIMARY_COLOR_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_BACK_SECONDARY_COLOR_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COORD_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLIP_DISTANCE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ID_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PRIMITIVE_ID_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_GENERIC_ATTRIB_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK_ATTRIBS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK_BUFFER_MODE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_ACTIVE_VARYINGS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_ACTIVE_VARYING_MAX_LENGTH_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK_VARYINGS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK_BUFFER_START_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK_RECORD_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PRIMITIVES_GENERATED_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_RASTERIZER_DISCARD_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTERLEAVED_ATTRIBS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SEPARATE_ATTRIBS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK_BUFFER_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_LAYER_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NEXT_BUFFER_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SKIP_COMPONENTS4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SKIP_COMPONENTS3_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SKIP_COMPONENTS2_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SKIP_COMPONENTS1_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_transform_feedback2);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSFORM_FEEDBACK_BINDING_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_vdpau_interop);
    CREATE_GL_BASIC_BIC_STATIC(GL_SURFACE_STATE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SURFACE_REGISTERED_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SURFACE_MAPPED_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_WRITE_DISCARD_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_vertex_array_range);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ARRAY_RANGE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ARRAY_RANGE_LENGTH_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ARRAY_RANGE_VALID_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VERTEX_ARRAY_RANGE_ELEMENT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ARRAY_RANGE_POINTER_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_vertex_array_range2);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ARRAY_RANGE_WITHOUT_FLUSH_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_vertex_attrib_integer_64bit);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_vertex_buffer_unified_memory);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_ELEMENT_ARRAY_UNIFIED_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY_ADDRESS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ARRAY_ADDRESS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NORMAL_ARRAY_ADDRESS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ARRAY_ADDRESS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_INDEX_ARRAY_ADDRESS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COORD_ARRAY_ADDRESS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_EDGE_FLAG_ARRAY_ADDRESS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SECONDARY_COLOR_ARRAY_ADDRESS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_COORD_ARRAY_ADDRESS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_ELEMENT_ARRAY_ADDRESS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY_LENGTH_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ARRAY_LENGTH_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NORMAL_ARRAY_LENGTH_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_ARRAY_LENGTH_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_INDEX_ARRAY_LENGTH_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COORD_ARRAY_LENGTH_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_EDGE_FLAG_ARRAY_LENGTH_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SECONDARY_COLOR_ARRAY_LENGTH_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_COORD_ARRAY_LENGTH_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_ELEMENT_ARRAY_LENGTH_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_INDIRECT_UNIFIED_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_INDIRECT_ADDRESS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_DRAW_INDIRECT_LENGTH_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_vertex_program);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_PROGRAM_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_STATE_PROGRAM_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATTRIB_ARRAY_SIZE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATTRIB_ARRAY_STRIDE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATTRIB_ARRAY_TYPE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_ATTRIB_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_LENGTH_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_STRING_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MODELVIEW_PROJECTION_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_IDENTITY_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_INVERSE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRANSPOSE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_INVERSE_TRANSPOSE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TRACK_MATRIX_STACK_DEPTH_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_TRACK_MATRICES_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX0_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX1_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX2_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX3_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX5_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX6_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATRIX7_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_MATRIX_STACK_DEPTH_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_MATRIX_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_PROGRAM_POINT_SIZE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_PROGRAM_TWO_SIDE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_PARAMETER_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_ATTRIB_ARRAY_POINTER_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_TARGET_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_RESIDENT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRACK_MATRIX_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRACK_MATRIX_TRANSFORM_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_PROGRAM_BINDING_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROGRAM_ERROR_POSITION_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY0_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY1_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY2_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY3_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY5_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY6_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY7_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY8_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY9_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY10_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY11_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY12_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY13_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY14_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY15_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP1_VERTEX_ATTRIB0_4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP1_VERTEX_ATTRIB1_4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP1_VERTEX_ATTRIB2_4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP1_VERTEX_ATTRIB3_4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP1_VERTEX_ATTRIB4_4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP1_VERTEX_ATTRIB5_4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP1_VERTEX_ATTRIB6_4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP1_VERTEX_ATTRIB7_4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP1_VERTEX_ATTRIB8_4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP1_VERTEX_ATTRIB9_4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP1_VERTEX_ATTRIB10_4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP1_VERTEX_ATTRIB11_4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP1_VERTEX_ATTRIB12_4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP1_VERTEX_ATTRIB13_4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP1_VERTEX_ATTRIB14_4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP1_VERTEX_ATTRIB15_4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP2_VERTEX_ATTRIB0_4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP2_VERTEX_ATTRIB1_4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP2_VERTEX_ATTRIB2_4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP2_VERTEX_ATTRIB3_4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP2_VERTEX_ATTRIB4_4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP2_VERTEX_ATTRIB5_4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP2_VERTEX_ATTRIB6_4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP2_VERTEX_ATTRIB7_4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP2_VERTEX_ATTRIB8_4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP2_VERTEX_ATTRIB9_4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP2_VERTEX_ATTRIB10_4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP2_VERTEX_ATTRIB11_4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP2_VERTEX_ATTRIB12_4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP2_VERTEX_ATTRIB13_4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP2_VERTEX_ATTRIB14_4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAP2_VERTEX_ATTRIB15_4_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_vertex_program1_1);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_vertex_program2);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_vertex_program2_option);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_vertex_program3);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_vertex_program4);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_ATTRIB_ARRAY_INTEGER_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NV_video_capture);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIDEO_BUFFER_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIDEO_BUFFER_BINDING_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FIELD_UPPER_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FIELD_LOWER_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NUM_VIDEO_CAPTURE_STREAMS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_NEXT_VIDEO_CAPTURE_BUFFER_STATUS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIDEO_CAPTURE_TO_422_SUPPORTED_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_LAST_VIDEO_CAPTURE_STATUS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIDEO_BUFFER_PITCH_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIDEO_COLOR_CONVERSION_MATRIX_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIDEO_COLOR_CONVERSION_MAX_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIDEO_COLOR_CONVERSION_MIN_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIDEO_COLOR_CONVERSION_OFFSET_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIDEO_BUFFER_INTERNAL_FORMAT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_PARTIAL_SUCCESS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_SUCCESS_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_FAILURE_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_YCBYCR8_422_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_YCBAYCR8A_4224_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_Z6Y10Z6CB10Z6Y10Z6CR10_422_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_Z6Y10Z6CB10Z6A10Z6Y10Z6CR10Z6A10_4224_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_Z4Y12Z4CB12Z4Y12Z4CR12_422_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_Z4Y12Z4CB12Z4A12Z4Y12Z4CR12Z4A12_4224_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_Z4Y12Z4CB12Z4CR12_444_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIDEO_CAPTURE_FRAME_WIDTH_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIDEO_CAPTURE_FRAME_HEIGHT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIDEO_CAPTURE_FIELD_UPPER_HEIGHT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIDEO_CAPTURE_FIELD_LOWER_HEIGHT_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_VIDEO_CAPTURE_SURFACE_ORIGIN_NV);
    CREATE_GL_BASIC_BIC_STATIC(GL_OML_interlace);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTERLACE_OML);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTERLACE_READ_OML);
    CREATE_GL_BASIC_BIC_STATIC(GL_OML_resample);
    CREATE_GL_BASIC_BIC_STATIC(GL_PACK_RESAMPLE_OML);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNPACK_RESAMPLE_OML);
    CREATE_GL_BASIC_BIC_STATIC(GL_RESAMPLE_REPLICATE_OML);
    CREATE_GL_BASIC_BIC_STATIC(GL_RESAMPLE_ZERO_FILL_OML);
    CREATE_GL_BASIC_BIC_STATIC(GL_RESAMPLE_AVERAGE_OML);
    CREATE_GL_BASIC_BIC_STATIC(GL_RESAMPLE_DECIMATE_OML);
    CREATE_GL_BASIC_BIC_STATIC(GL_OML_subsample);
    CREATE_GL_BASIC_BIC_STATIC(GL_FORMAT_SUBSAMPLE_24_24_OML);
    CREATE_GL_BASIC_BIC_STATIC(GL_FORMAT_SUBSAMPLE_244_244_OML);
    CREATE_GL_BASIC_BIC_STATIC(GL_PGI_misc_hints);
    CREATE_GL_BASIC_BIC_STATIC(GL_PREFER_DOUBLEBUFFER_HINT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONSERVE_MEMORY_HINT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_RECLAIM_MEMORY_HINT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_NATIVE_GRAPHICS_HANDLE_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_NATIVE_GRAPHICS_BEGIN_HINT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_NATIVE_GRAPHICS_END_HINT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALWAYS_FAST_HINT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALWAYS_SOFT_HINT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALLOW_DRAW_OBJ_HINT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALLOW_DRAW_WIN_HINT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALLOW_DRAW_FRG_HINT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALLOW_DRAW_MEM_HINT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_STRICT_DEPTHFUNC_HINT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_STRICT_LIGHTING_HINT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_STRICT_SCISSOR_HINT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_FULL_STIPPLE_HINT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLIP_NEAR_HINT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLIP_FAR_HINT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_WIDE_LINE_HINT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_BACK_NORMALS_HINT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_PGI_vertex_hints);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_DATA_HINT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_CONSISTENT_HINT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_MATERIAL_SIDE_HINT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_VERTEX_HINT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR3_BIT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR4_BIT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_EDGEFLAG_BIT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_INDEX_BIT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAT_AMBIENT_BIT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAT_AMBIENT_AND_DIFFUSE_BIT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAT_DIFFUSE_BIT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAT_EMISSION_BIT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAT_COLOR_INDEXES_BIT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAT_SHININESS_BIT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAT_SPECULAR_BIT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_NORMAL_BIT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXCOORD1_BIT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXCOORD2_BIT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXCOORD3_BIT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXCOORD4_BIT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX23_BIT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX4_BIT_PGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_REND_screen_coordinates);
    CREATE_GL_BASIC_BIC_STATIC(GL_SCREEN_COORDINATES_REND);
    CREATE_GL_BASIC_BIC_STATIC(GL_INVERTED_SCREEN_W_REND);
    CREATE_GL_BASIC_BIC_STATIC(GL_S3_s3tc);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB_S3TC);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGB4_S3TC);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA_S3TC);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA4_S3TC);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA_DXT5_S3TC);
    CREATE_GL_BASIC_BIC_STATIC(GL_RGBA4_DXT5_S3TC);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIS_detail_texture);
    CREATE_GL_BASIC_BIC_STATIC(GL_DETAIL_TEXTURE_2D_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_DETAIL_TEXTURE_2D_BINDING_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINEAR_DETAIL_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINEAR_DETAIL_ALPHA_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINEAR_DETAIL_COLOR_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_DETAIL_TEXTURE_LEVEL_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_DETAIL_TEXTURE_MODE_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_DETAIL_TEXTURE_FUNC_POINTS_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIS_fog_function);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_FUNC_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_FUNC_POINTS_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_FOG_FUNC_POINTS_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIS_generate_mipmap);
    CREATE_GL_BASIC_BIC_STATIC(GL_GENERATE_MIPMAP_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_GENERATE_MIPMAP_HINT_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIS_multisample);
    CREATE_GL_BASIC_BIC_STATIC(GL_MULTISAMPLE_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_ALPHA_TO_MASK_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_ALPHA_TO_ONE_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_MASK_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_1PASS_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_2PASS_0_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_2PASS_1_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_4PASS_0_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_4PASS_1_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_4PASS_2_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_4PASS_3_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_BUFFERS_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLES_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_MASK_VALUE_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_MASK_INVERT_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_SAMPLE_PATTERN_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIS_pixel_texture);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_TEXTURE_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_FRAGMENT_RGB_SOURCE_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_FRAGMENT_ALPHA_SOURCE_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_GROUP_COLOR_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIS_point_line_texgen);
    CREATE_GL_BASIC_BIC_STATIC(GL_EYE_DISTANCE_TO_POINT_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_OBJECT_DISTANCE_TO_POINT_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_EYE_DISTANCE_TO_LINE_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_OBJECT_DISTANCE_TO_LINE_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_EYE_POINT_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_OBJECT_POINT_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_EYE_LINE_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_OBJECT_LINE_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIS_point_parameters);
    CREATE_GL_BASIC_BIC_STATIC(GL_POINT_SIZE_MIN_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_POINT_SIZE_MAX_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_POINT_FADE_THRESHOLD_SIZE_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_DISTANCE_ATTENUATION_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIS_sharpen_texture);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINEAR_SHARPEN_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINEAR_SHARPEN_ALPHA_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINEAR_SHARPEN_COLOR_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_SHARPEN_TEXTURE_FUNC_POINTS_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIS_texture4D);
    CREATE_GL_BASIC_BIC_STATIC(GL_PACK_SKIP_VOLUMES_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_PACK_IMAGE_DEPTH_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNPACK_SKIP_VOLUMES_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNPACK_IMAGE_DEPTH_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_4D_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROXY_TEXTURE_4D_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_4DSIZE_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_WRAP_Q_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_4D_TEXTURE_SIZE_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_4D_BINDING_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIS_texture_border_clamp);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLAMP_TO_BORDER_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIS_texture_color_mask);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COLOR_WRITEMASK_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIS_texture_edge_clamp);
    CREATE_GL_BASIC_BIC_STATIC(GL_CLAMP_TO_EDGE_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIS_texture_filter4);
    CREATE_GL_BASIC_BIC_STATIC(GL_FILTER4_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_FILTER4_SIZE_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIS_texture_lod);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_MIN_LOD_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_MAX_LOD_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_BASE_LEVEL_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_MAX_LEVEL_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIS_texture_select);
    CREATE_GL_BASIC_BIC_STATIC(GL_DUAL_ALPHA4_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_DUAL_ALPHA8_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_DUAL_ALPHA12_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_DUAL_ALPHA16_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_DUAL_LUMINANCE4_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_DUAL_LUMINANCE8_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_DUAL_LUMINANCE12_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_DUAL_LUMINANCE16_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_DUAL_INTENSITY4_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_DUAL_INTENSITY8_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_DUAL_INTENSITY12_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_DUAL_INTENSITY16_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_DUAL_LUMINANCE_ALPHA4_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_DUAL_LUMINANCE_ALPHA8_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_QUAD_ALPHA4_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_QUAD_ALPHA8_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_QUAD_LUMINANCE4_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_QUAD_LUMINANCE8_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_QUAD_INTENSITY4_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_QUAD_INTENSITY8_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_DUAL_TEXTURE_SELECT_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_QUAD_TEXTURE_SELECT_SGIS);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_async);
    CREATE_GL_BASIC_BIC_STATIC(GL_ASYNC_MARKER_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_async_histogram);
    CREATE_GL_BASIC_BIC_STATIC(GL_ASYNC_HISTOGRAM_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_ASYNC_HISTOGRAM_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_async_pixel);
    CREATE_GL_BASIC_BIC_STATIC(GL_ASYNC_TEX_IMAGE_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_ASYNC_DRAW_PIXELS_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_ASYNC_READ_PIXELS_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_ASYNC_TEX_IMAGE_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_ASYNC_DRAW_PIXELS_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_ASYNC_READ_PIXELS_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_blend_alpha_minmax);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA_MIN_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_ALPHA_MAX_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_calligraphic_fragment);
    CREATE_GL_BASIC_BIC_STATIC(GL_CALLIGRAPHIC_FRAGMENT_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_clipmap);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINEAR_CLIPMAP_LINEAR_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CLIPMAP_CENTER_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CLIPMAP_FRAME_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CLIPMAP_OFFSET_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CLIPMAP_VIRTUAL_DEPTH_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CLIPMAP_LOD_OFFSET_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CLIPMAP_DEPTH_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_CLIPMAP_DEPTH_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_CLIPMAP_VIRTUAL_DEPTH_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_NEAREST_CLIPMAP_NEAREST_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_NEAREST_CLIPMAP_LINEAR_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_LINEAR_CLIPMAP_NEAREST_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_convolution_accuracy);
    CREATE_GL_BASIC_BIC_STATIC(GL_CONVOLUTION_HINT_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_depth_pass_instrument);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_depth_texture);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_COMPONENT16_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_COMPONENT24_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEPTH_COMPONENT32_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_flush_raster);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_fog_offset);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_OFFSET_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_OFFSET_VALUE_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_fragment_lighting);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAGMENT_LIGHTING_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAGMENT_COLOR_MATERIAL_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAGMENT_COLOR_MATERIAL_FACE_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAGMENT_COLOR_MATERIAL_PARAMETER_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_FRAGMENT_LIGHTS_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_ACTIVE_LIGHTS_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_CURRENT_RASTER_NORMAL_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_LIGHT_ENV_MODE_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAGMENT_LIGHT_MODEL_LOCAL_VIEWER_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAGMENT_LIGHT_MODEL_TWO_SIDE_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAGMENT_LIGHT_MODEL_AMBIENT_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAGMENT_LIGHT_MODEL_NORMAL_INTERPOLATION_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAGMENT_LIGHT0_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAGMENT_LIGHT1_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAGMENT_LIGHT2_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAGMENT_LIGHT3_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAGMENT_LIGHT4_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAGMENT_LIGHT5_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAGMENT_LIGHT6_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAGMENT_LIGHT7_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_framezoom);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEZOOM_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_FRAMEZOOM_FACTOR_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_FRAMEZOOM_FACTOR_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_igloo_interface);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_instruments);
    CREATE_GL_BASIC_BIC_STATIC(GL_INSTRUMENT_BUFFER_POINTER_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_INSTRUMENT_MEASUREMENTS_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_interlace);
    CREATE_GL_BASIC_BIC_STATIC(GL_INTERLACE_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_ir_instrument1);
    CREATE_GL_BASIC_BIC_STATIC(GL_IR_INSTRUMENT1_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_list_priority);
    CREATE_GL_BASIC_BIC_STATIC(GL_LIST_PRIORITY_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_pixel_texture);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_TEX_GEN_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_TEX_GEN_MODE_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_pixel_tiles);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_TILE_BEST_ALIGNMENT_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_TILE_CACHE_INCREMENT_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_TILE_WIDTH_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_TILE_HEIGHT_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_TILE_GRID_WIDTH_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_TILE_GRID_HEIGHT_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_TILE_GRID_DEPTH_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_TILE_CACHE_SIZE_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_polynomial_ffd);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_DEFORMATION_BIT_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_GEOMETRY_DEFORMATION_BIT_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_GEOMETRY_DEFORMATION_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_DEFORMATION_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_DEFORMATIONS_MASK_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_DEFORMATION_ORDER_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_reference_plane);
    CREATE_GL_BASIC_BIC_STATIC(GL_REFERENCE_PLANE_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_REFERENCE_PLANE_EQUATION_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_resample);
    CREATE_GL_BASIC_BIC_STATIC(GL_PACK_RESAMPLE_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNPACK_RESAMPLE_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_RESAMPLE_REPLICATE_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_RESAMPLE_ZERO_FILL_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_RESAMPLE_DECIMATE_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_scalebias_hint);
    CREATE_GL_BASIC_BIC_STATIC(GL_SCALEBIAS_HINT_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_shadow);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COMPARE_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COMPARE_OPERATOR_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_LEQUAL_R_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_GEQUAL_R_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_shadow_ambient);
    CREATE_GL_BASIC_BIC_STATIC(GL_SHADOW_AMBIENT_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_sprite);
    CREATE_GL_BASIC_BIC_STATIC(GL_SPRITE_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SPRITE_MODE_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SPRITE_AXIS_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SPRITE_TRANSLATION_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SPRITE_AXIAL_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SPRITE_OBJECT_ALIGNED_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SPRITE_EYE_ALIGNED_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_subsample);
    CREATE_GL_BASIC_BIC_STATIC(GL_PACK_SUBSAMPLE_RATE_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNPACK_SUBSAMPLE_RATE_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_SUBSAMPLE_4444_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_SUBSAMPLE_2424_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_PIXEL_SUBSAMPLE_4242_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_tag_sample_buffer);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_texture_add_env);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_ENV_BIAS_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_texture_coordinate_clamp);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_MAX_CLAMP_S_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_MAX_CLAMP_T_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_MAX_CLAMP_R_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_texture_lod_bias);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_LOD_BIAS_S_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_LOD_BIAS_T_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_LOD_BIAS_R_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_texture_multi_buffer);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_MULTI_BUFFER_HINT_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_texture_scale_bias);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_TEXTURE_FILTER_BIAS_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_TEXTURE_FILTER_SCALE_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_TEXTURE_FILTER_BIAS_RANGE_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_TEXTURE_FILTER_SCALE_RANGE_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_vertex_preclip);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_PRECLIP_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_VERTEX_PRECLIP_HINT_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_ycrcb);
    CREATE_GL_BASIC_BIC_STATIC(GL_YCRCB_422_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_YCRCB_444_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_ycrcb_subsample);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGIX_ycrcba);
    CREATE_GL_BASIC_BIC_STATIC(GL_YCRCB_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_YCRCBA_SGIX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGI_color_matrix);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_MATRIX_SGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_MATRIX_STACK_DEPTH_SGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_MAX_COLOR_MATRIX_STACK_DEPTH_SGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_COLOR_MATRIX_RED_SCALE_SGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_COLOR_MATRIX_GREEN_SCALE_SGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_COLOR_MATRIX_BLUE_SCALE_SGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_COLOR_MATRIX_ALPHA_SCALE_SGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_COLOR_MATRIX_RED_BIAS_SGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_COLOR_MATRIX_GREEN_BIAS_SGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_COLOR_MATRIX_BLUE_BIAS_SGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_COLOR_MATRIX_ALPHA_BIAS_SGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGI_color_table);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_TABLE_SGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_CONVOLUTION_COLOR_TABLE_SGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_POST_COLOR_MATRIX_COLOR_TABLE_SGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROXY_COLOR_TABLE_SGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROXY_POST_CONVOLUTION_COLOR_TABLE_SGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE_SGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_TABLE_SCALE_SGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_TABLE_BIAS_SGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_TABLE_FORMAT_SGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_TABLE_WIDTH_SGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_TABLE_RED_SIZE_SGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_TABLE_GREEN_SIZE_SGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_TABLE_BLUE_SIZE_SGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_TABLE_ALPHA_SIZE_SGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_TABLE_LUMINANCE_SIZE_SGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_COLOR_TABLE_INTENSITY_SIZE_SGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_SGI_texture_color_table);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_COLOR_TABLE_SGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_PROXY_TEXTURE_COLOR_TABLE_SGI);
    CREATE_GL_BASIC_BIC_STATIC(GL_SUNX_constant_data);
    CREATE_GL_BASIC_BIC_STATIC(GL_UNPACK_CONSTANT_DATA_SUNX);
    CREATE_GL_BASIC_BIC_STATIC(GL_TEXTURE_CONSTANT_DATA_SUNX);
    CREATE_GL_BASIC_BIC_STATIC(GL_SUN_convolution_border_modes);
    CREATE_GL_BASIC_BIC_STATIC(GL_WRAP_BORDER_SUN);
    CREATE_GL_BASIC_BIC_STATIC(GL_SUN_global_alpha);
    CREATE_GL_BASIC_BIC_STATIC(GL_GLOBAL_ALPHA_SUN);
    CREATE_GL_BASIC_BIC_STATIC(GL_GLOBAL_ALPHA_FACTOR_SUN);
    CREATE_GL_BASIC_BIC_STATIC(GL_SUN_mesh_array);
    CREATE_GL_BASIC_BIC_STATIC(GL_QUAD_MESH_SUN);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRIANGLE_MESH_SUN);
    CREATE_GL_BASIC_BIC_STATIC(GL_SUN_slice_accum);
    CREATE_GL_BASIC_BIC_STATIC(GL_SLICE_ACCUM_SUN);
    CREATE_GL_BASIC_BIC_STATIC(GL_SUN_triangle_list);
    CREATE_GL_BASIC_BIC_STATIC(GL_RESTART_SUN);
    CREATE_GL_BASIC_BIC_STATIC(GL_REPLACE_MIDDLE_SUN);
    CREATE_GL_BASIC_BIC_STATIC(GL_REPLACE_OLDEST_SUN);
    CREATE_GL_BASIC_BIC_STATIC(GL_TRIANGLE_LIST_SUN);
    CREATE_GL_BASIC_BIC_STATIC(GL_REPLACEMENT_CODE_SUN);
    CREATE_GL_BASIC_BIC_STATIC(GL_REPLACEMENT_CODE_ARRAY_SUN);
    CREATE_GL_BASIC_BIC_STATIC(GL_REPLACEMENT_CODE_ARRAY_TYPE_SUN);
    CREATE_GL_BASIC_BIC_STATIC(GL_REPLACEMENT_CODE_ARRAY_STRIDE_SUN);
    CREATE_GL_BASIC_BIC_STATIC(GL_REPLACEMENT_CODE_ARRAY_POINTER_SUN);
    CREATE_GL_BASIC_BIC_STATIC(GL_R1UI_V3F_SUN);
    CREATE_GL_BASIC_BIC_STATIC(GL_R1UI_C4UB_V3F_SUN);
    CREATE_GL_BASIC_BIC_STATIC(GL_R1UI_C3F_V3F_SUN);
    CREATE_GL_BASIC_BIC_STATIC(GL_R1UI_N3F_V3F_SUN);
    CREATE_GL_BASIC_BIC_STATIC(GL_R1UI_C4F_N3F_V3F_SUN);
    CREATE_GL_BASIC_BIC_STATIC(GL_R1UI_T2F_V3F_SUN);
    CREATE_GL_BASIC_BIC_STATIC(GL_R1UI_T2F_N3F_V3F_SUN);
    CREATE_GL_BASIC_BIC_STATIC(GL_R1UI_T2F_C4F_N3F_V3F_SUN);
    CREATE_GL_BASIC_BIC_STATIC(GL_SUN_vertex);
    CREATE_GL_BASIC_BIC_STATIC(GL_WIN_phong_shading);
    CREATE_GL_BASIC_BIC_STATIC(GL_PHONG_WIN);
    CREATE_GL_BASIC_BIC_STATIC(GL_PHONG_HINT_WIN);
    CREATE_GL_BASIC_BIC_STATIC(GL_WIN_specular_fog);
    CREATE_GL_BASIC_BIC_STATIC(GL_FOG_SPECULAR_TEXTURE_WIN);
  }/*}}}*/
#endif
}

