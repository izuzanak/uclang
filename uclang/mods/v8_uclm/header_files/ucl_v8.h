
#ifndef __UCL_V8_H
#define __UCL_V8_H

@begin
include "script_parser.h"
@end

#include "v8.h"

using namespace v8;

/*
 * constants and definitions
 */

extern unsigned c_bi_class_v8_object;
extern unsigned c_bi_class_v8_reference;
extern unsigned c_rm_class_dict;

// - max method parameter count -
const unsigned c_max_method_param_cnt = 32;

// - basic handle type (same size as handler) -
typedef pointer v8_htype;

// - handle context scope -
#define UCL_HANDLE_CONTEXT_SCOPE() \
  HandleScope handle_scope;\
  Context::Scope context_scope(Context::GetCurrent());

// - rethrow V8 exception -
#define UCL_RETHROW_V8_EXCEPTION(TRY_CATCH,EXCEPTION) \
{/*{{{*/\
\
  /* - process error message - */\
  Handle<String> hnd_error = TRY_CATCH.Exception()->ToString();\
  int error_length = hnd_error->Utf8Length();\
\
  string_s *error_str_ptr = it.get_new_string_ptr();\
  error_str_ptr->create(error_length);\
  hnd_error->WriteUtf8(error_str_ptr->data,error_length);\
\
  BIC_CREATE_NEW_LOCATION(error_location,c_bi_class_string,error_str_ptr);\
\
  /* - process error line - */\
  Handle<Message> hnd_message = TRY_CATCH.Message();\
  Handle<String> hnd_line = hnd_message->GetSourceLine();\
  int line_length = hnd_line->Utf8Length();\
\
  string_s *line_str_ptr = it.get_new_string_ptr();\
  line_str_ptr->create(line_length);\
  hnd_line->WriteUtf8(line_str_ptr->data,line_length);\
\
  BIC_CREATE_NEW_LOCATION(line_location,c_bi_class_string,line_str_ptr);\
\
  /* - process error resource - */\
  Handle<String> hnd_res = hnd_message->GetScriptResourceName()->ToString();\
  int res_length = hnd_res->Utf8Length();\
\
  string_s *res_str_ptr = it.get_new_string_ptr();\
  res_str_ptr->create(res_length);\
  hnd_res->WriteUtf8(res_str_ptr->data,res_length);\
\
  BIC_CREATE_NEW_LOCATION(res_location,c_bi_class_string,res_str_ptr);\
\
  /* - create exception array - */\
  pointer_array_s *array_ptr = it.get_new_array_ptr();\
  array_ptr->push(error_location);\
  array_ptr->push(line_location);\
  array_ptr->push(res_location);\
\
  BIC_CREATE_NEW_LOCATION_REFS(arr_location,c_bi_class_array,array_ptr,0);\
\
  /* - create and throw exception - */\
  exception_s *new_exception = exception_s::throw_exception(it,module.error_base + EXCEPTION,operands[c_source_pos_idx],arr_location);\
  new_exception->params.push(hnd_message->GetLineNumber());\
  new_exception->params.push(hnd_message->GetStartColumn());\
}/*}}}*/

/*
 * definition of structure v8_reference_s
 */

struct v8_reference_s
{
  Persistent<Object> per_obj;
  Persistent<Value> per_key;

  inline void init();
  inline void clear(interpreter_thread_s &it);

  inline Handle<Value> get();
  inline bool set(Handle<Value> hnd_value);
};

/*
 * definition of class v8_c
 */
class v8_c
{
  public:
  inline v8_c();
  inline ~v8_c();

  static Handle<Value> create_v8_object(interpreter_thread_s &it,location_s *location_ptr);
  static location_s *v8_object_value(interpreter_thread_s &it,Handle<Value> hnd_value,uli source_pos);
};

/*
 * inline methods of structure v8_reference_s
 */

inline void v8_reference_s::init()
{/*{{{*/
}/*}}}*/

inline void v8_reference_s::clear(interpreter_thread_s &it)
{/*{{{*/
  per_obj.Dispose();
  per_key.Dispose();

  init();
}/*}}}*/

inline Handle<Value> v8_reference_s::get()
{/*{{{*/
  return per_obj->Get(per_key);
}/*}}}*/

inline bool v8_reference_s::set(Handle<Value> hnd_value)
{/*{{{*/
  return per_obj->Set(per_key,hnd_value);
}/*}}}*/

/*
 * inline methods of class v8_c
 */

inline v8_c::v8_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"v8_init()\n"););
}/*}}}*/

inline v8_c::~v8_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"v8_exit()\n"););

  // - release any resources used by v8 -
  V8::Dispose();
}/*}}}*/

#endif

