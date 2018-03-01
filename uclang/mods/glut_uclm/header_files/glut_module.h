
#ifndef __GLUT_MODULE_H
#define __GLUT_MODULE_H

@begin
include "ucl_glut.h"
@end

// - GLUT indexes of built in classes -
extern unsigned c_bi_class_glut;

// - GLUT module -
extern built_in_module_s module;

// - GLUT classes -
extern built_in_class_s *glut_classes[];

// - GLUT error identifiers -
enum
{
  c_error_GLUT_OBJECT_ALREADY_CREATED = 0,
  c_error_GLUT_WRONG_THREAD_CONTEXT,
  c_error_GLUT_WRONG_CALLBACK_DELEGATE,
  c_error_GLUT_WINDOW_ALREADY_CREATED,
  c_error_GLUT_WINDOW_NOT_CREATED_YET,
  c_error_GLUT_ALREADY_IN_MAIN_LOOP,
};

// - GLUT error strings -
extern const char *glut_error_strings[];

// - GLUT initialize -
bool glut_initialize(script_parser_s &sp);

// - GLUT print exception -
bool glut_print_exception(interpreter_s &it,exception_s &exception);

// - class GLUT -
extern built_in_variable_s glut_variables[];
extern built_in_method_s glut_methods[];
extern built_in_class_s glut_class;

void bic_glut_consts(location_array_s &const_locations);
void bic_glut_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_glut_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_glut_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_glut_method_Glut_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_glut_method_InitWindowSize_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_glut_method_InitWindowPosition_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_glut_method_InitDisplayMode_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_glut_method_CreateWindow_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_glut_method_DisplayFunc_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_glut_method_ReshapeFunc_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_glut_method_KeyboardFunc_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_glut_method_SpecialFunc_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_glut_method_MouseFunc_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_glut_method_MotionFunc_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_glut_method_PassiveMotionFunc_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_glut_method_VisibilityFunc_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_glut_method_EntryFunc_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_glut_method_IdleFunc_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_glut_method_TimerFunc_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_glut_method_GetModifiers_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_glut_method_Get_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_glut_method_PostRedisplay_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_glut_method_SwapBuffers_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_glut_method_MainLoop_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
#ifndef EMSCRIPTEN
bool bic_glut_method_LeaveMainLoop_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
#endif
bool bic_glut_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_glut_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

