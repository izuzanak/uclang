
#ifndef __IMXEGL_MODULE_H
#define __IMXEGL_MODULE_H

@begin
include "ucl_imxegl.h"
@end

// - IMXEGL indexes of built in classes -
extern unsigned c_bi_class_imx_egl;

#if defined(IPUROT_LINUX)
extern unsigned c_bi_class_imx_fb;
extern unsigned c_bi_class_imx_ipu;
#endif

// - IMXEGL module -
extern built_in_module_s module;

// - IMXEGL classes -
extern built_in_class_s *imxegl_classes[];

// - IMXEGL error identifiers -
enum
{
  c_error_IMX_EGL_UNRECOGNIZED_API = 0,
  c_error_IMX_EGL_CREATE_ERROR,
  c_error_IMX_EGL_SET_AS_GLOBAL_ERROR,
  c_error_IMX_EGL_WRONG_COUNT_OF_TEXTURES_REQUESTED,
  c_error_IMX_EGL_WRONG_TEXTURE_INDEX,
  c_error_IMX_EGL_MAKE_CURRENT_ERROR,
  c_error_IMX_EGL_SWAP_BUFFERS_ERROR,

#if defined(IPUROT_LINUX)
  c_error_IMX_FB_FILE_OPEN_ERROR,
  c_error_IMX_FB_CANNOT_READ_PROPERTIES,
  c_error_IMX_IPU_FILE_OPEN_ERROR,
  c_error_IMX_IPU_NO_TASK_PREPARED_FOR_EXECUTION,
#endif
};

// - IMXEGL error strings -
extern const char *imxegl_error_strings[];

// - IMXEGL initialize -
bool imxegl_initialize(script_parser_s &sp);

// - IMXEGL print exception -
bool imxegl_print_exception(interpreter_s &it,exception_s &exception);

// - class IMX_EGL -
extern built_in_variable_s imx_egl_variables[];
extern built_in_method_s imx_egl_methods[];
extern built_in_class_s imx_egl_class;

void bic_imx_egl_consts(location_array_s &const_locations);
void bic_imx_egl_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_imx_egl_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_imx_egl_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_imx_egl_method_ImxEgl_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_imx_egl_method_set_as_global_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_imx_egl_method_gen_textures_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_imx_egl_method_get_texture_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_imx_egl_method_global_lock_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_imx_egl_method_global_unlock_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_imx_egl_method_global_terminate_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_imx_egl_method_MakeCurrent_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_imx_egl_method_SwapBuffers_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_imx_egl_method_GetError_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_imx_egl_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_imx_egl_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#if defined(IPUROT_LINUX)
// - class IMX_FB -
extern built_in_variable_s imx_fb_variables[];
extern built_in_method_s imx_fb_methods[];
extern built_in_class_s imx_fb_class;

void bic_imx_fb_consts(location_array_s &const_locations);
void bic_imx_fb_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_imx_fb_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_imx_fb_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_imx_fb_method_ImxFb_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_imx_fb_method_width_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_imx_fb_method_height_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_imx_fb_method_bits_per_pixel_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_imx_fb_method_wait_on_vsync_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_imx_fb_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_imx_fb_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
#endif

#if defined(IPUROT_LINUX)
// - class IMX_IPU -
extern built_in_variable_s imx_ipu_variables[];
extern built_in_method_s imx_ipu_methods[];
extern built_in_class_s imx_ipu_class;

void bic_imx_ipu_consts(location_array_s &const_locations);
void bic_imx_ipu_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_imx_ipu_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_imx_ipu_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_imx_ipu_method_ImxIpu_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_imx_ipu_method_prepare_rotation_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_imx_ipu_method_execute_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_imx_ipu_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_imx_ipu_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
#endif

#endif

