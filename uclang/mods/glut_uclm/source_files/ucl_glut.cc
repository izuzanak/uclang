
@begin
include "ucl_glut.h"
@end

// - static glut_s values -
glut_s *glut_s::glut_ptr;
interpreter_thread_s *glut_s::it_ptr;
int glut_s::window;
bool glut_s::main_loop;
unsigned glut_s::main_source_pos;
unsigned glut_s::main_ret_code;

// - glut global init object -
glut_c g_glut;

/*
 * methods of structure glut_s
 */

#ifdef EMSCRIPTEN
#define GLUT_CALLBACK_ERROR_CODE \
  /* TODO terminate empscripten glut main loop */\
  exit(0)
#else
#define GLUT_CALLBACK_ERROR_CODE \
  glut_s::main_ret_code = c_run_return_code_EXCEPTION;\
  glutLeaveMainLoop();\
  return;
#endif

#define GLUT_CALL_CALLBACK_DELEGATE(NAME,PARAM_DATA,PARAM_CNT,PARAM_CODE) \
{/*{{{*/\
  if (glut_s::main_ret_code == c_run_return_code_OK &&\
      glut_s::glut_ptr->NAME ## _dlg != nullptr)\
  {\
    interpreter_thread_s &it = *glut_s::it_ptr;\
    delegate_s *delegate_ptr = (delegate_s *)glut_s::glut_ptr->NAME ## _dlg->v_data_ptr;\
\
    PARAM_CODE;\
\
    /* - call delegate method - */\
    location_s *trg_location = nullptr;\
    BIC_CALL_DELEGATE(it,delegate_ptr,PARAM_DATA,PARAM_CNT,trg_location,glut_s::main_source_pos,\
      GLUT_CALLBACK_ERROR_CODE;\
    );\
    it.release_location_ptr(trg_location);\
  }\
}/*}}}*/

void glut_s::display_func()
{/*{{{*/
  GLUT_CALL_CALLBACK_DELEGATE(display,nullptr,0,);
}/*}}}*/

void glut_s::reshape_func(int width,int height)
{/*{{{*/
  GLUT_CALL_CALLBACK_DELEGATE(reshape,param_data,param_cnt,

    BIC_CREATE_NEW_LOCATION_REFS(width_loc,c_bi_class_integer,width,0);
    BIC_CREATE_NEW_LOCATION_REFS(height_loc,c_bi_class_integer,height,0);

    const unsigned param_cnt = 2;
    pointer param_data[param_cnt] = {width_loc MP_COMMA height_loc};
  );
}/*}}}*/

void glut_s::keyboard_func(unsigned char key,int x,int y)
{/*{{{*/
  GLUT_CALL_CALLBACK_DELEGATE(keyboard,param_data,param_cnt,

    BIC_CREATE_NEW_LOCATION_REFS(key_loc,c_bi_class_char,key,0);
    BIC_CREATE_NEW_LOCATION_REFS(x_loc,c_bi_class_integer,x,0);
    BIC_CREATE_NEW_LOCATION_REFS(y_loc,c_bi_class_integer,y,0);

    const unsigned param_cnt = 3;
    pointer param_data[param_cnt] = {key_loc
      MP_COMMA x_loc
      MP_COMMA y_loc};
  );
}/*}}}*/

void glut_s::mouse_func(int butt,int state,int x,int y)
{/*{{{*/
  GLUT_CALL_CALLBACK_DELEGATE(mouse,param_data,param_cnt,

    BIC_CREATE_NEW_LOCATION_REFS(butt_loc,c_bi_class_integer,butt,0);
    BIC_CREATE_NEW_LOCATION_REFS(state_loc,c_bi_class_integer,state,0);
    BIC_CREATE_NEW_LOCATION_REFS(x_loc,c_bi_class_integer,x,0);
    BIC_CREATE_NEW_LOCATION_REFS(y_loc,c_bi_class_integer,y,0);

    const unsigned param_cnt = 4;
    pointer param_data[param_cnt] = {butt_loc
      MP_COMMA state_loc
      MP_COMMA x_loc
      MP_COMMA y_loc};
  );
}/*}}}*/

void glut_s::motion_func(int x,int y)
{/*{{{*/
  GLUT_CALL_CALLBACK_DELEGATE(motion,param_data,param_cnt,

    BIC_CREATE_NEW_LOCATION_REFS(x_loc,c_bi_class_integer,x,0);
    BIC_CREATE_NEW_LOCATION_REFS(y_loc,c_bi_class_integer,y,0);

    const unsigned param_cnt = 2;
    pointer param_data[param_cnt] = {x_loc MP_COMMA y_loc};
  );
}/*}}}*/

void glut_s::passive_motion_func(int x,int y)
{/*{{{*/
  GLUT_CALL_CALLBACK_DELEGATE(passive_motion,param_data,param_cnt,

    BIC_CREATE_NEW_LOCATION_REFS(x_loc,c_bi_class_integer,x,0);
    BIC_CREATE_NEW_LOCATION_REFS(y_loc,c_bi_class_integer,y,0);

    const unsigned param_cnt = 2;
    pointer param_data[param_cnt] = {x_loc MP_COMMA y_loc};
  );
}/*}}}*/

void glut_s::visibility_func(int state)
{/*{{{*/
  GLUT_CALL_CALLBACK_DELEGATE(visibility,param_data,param_cnt,

    BIC_CREATE_NEW_LOCATION_REFS(state_loc,c_bi_class_integer,state,0);

    const unsigned param_cnt = 1;
    pointer *param_data = (pointer *)&state_loc;
  );
}/*}}}*/

void glut_s::entry_func(int state)
{/*{{{*/
  GLUT_CALL_CALLBACK_DELEGATE(entry,param_data,param_cnt,

    BIC_CREATE_NEW_LOCATION_REFS(state_loc,c_bi_class_integer,state,0);

    const unsigned param_cnt = 1;
    pointer *param_data = (pointer *)&state_loc;
  );
}/*}}}*/

void glut_s::special_func(int key,int x,int y)
{/*{{{*/
  GLUT_CALL_CALLBACK_DELEGATE(special,param_data,param_cnt,

    BIC_CREATE_NEW_LOCATION_REFS(key_loc,c_bi_class_integer,key,0);
    BIC_CREATE_NEW_LOCATION_REFS(x_loc,c_bi_class_integer,x,0);
    BIC_CREATE_NEW_LOCATION_REFS(y_loc,c_bi_class_integer,y,0);

    const unsigned param_cnt = 3;
    pointer param_data[param_cnt] = {key_loc
      MP_COMMA x_loc
      MP_COMMA y_loc};
  );
}/*}}}*/

void glut_s::idle_func()
{/*{{{*/
  GLUT_CALL_CALLBACK_DELEGATE(idle,nullptr,0,);
}/*}}}*/

void glut_s::timer_func(int value)
{/*{{{*/
  GLUT_CALL_CALLBACK_DELEGATE(timer,param_data,param_cnt,

    BIC_CREATE_NEW_LOCATION_REFS(value_loc,c_bi_class_integer,value,0);

    const unsigned param_cnt = 1;
    pointer *param_data = (pointer *)&value_loc;
  );
}/*}}}*/

