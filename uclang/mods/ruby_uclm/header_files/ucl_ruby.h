
#ifndef __UCL_RUBY_H
#define __UCL_RUBY_H

@begin
include "script_parser.h"
@end

#include <ruby.h>

/*
 * constants and definitions
 */

extern unsigned c_bi_class_ruby_symbol;
extern unsigned c_bi_class_ruby_value;
extern unsigned c_bi_class_ruby_iv_ref;
extern unsigned c_bi_class_ruby_item_ref;
extern unsigned c_rm_class_dict;

// - max method parameter count -
const unsigned c_max_method_param_cnt = 32;

// - return statuses -
enum
{
  STATUS_OK = 0,
  STATUS_ERROR
};

/*
 * definition of structure call_args_s
 */

struct call_args_s
{
  VALUE recv;
  ID mid;
  unsigned argc;
  const VALUE *argv;
};

/*
 * definition of class ruby_c
 */
class ruby_c
{
  private:
  static VALUE values;
  static ui_array_s free_idxs;

  public:
  inline ruby_c();
  inline ~ruby_c();

  inline static unsigned keep_value(VALUE a_value);
  inline static void release_value(unsigned a_idx);
  inline static VALUE get_value(unsigned a_idx);

  static VALUE rb_load_protect(VALUE a_file_name);
  static VALUE rb_require_protect(VALUE a_file_name);
  static VALUE rb_big2ll_protect(VALUE a_big_num);
  static VALUE rb_funcallv_protect(VALUE a_args);

  static int hash_kv_pair(VALUE key,VALUE value,VALUE array);

  static VALUE create_ruby_value(interpreter_thread_s &it,location_s *location_ptr,int &status);
  static location_s *ruby_value_value(interpreter_thread_s &it,VALUE value,uli source_pos);
};

/*
 * definition of structure ruby_reference_s
 */

struct ruby_reference_s
{
  unsigned obj_idx;
  unsigned key_idx;

  inline void init();
  inline void clear(interpreter_thread_s &it);

  inline VALUE get_iv(int &status);
  inline bool set_iv(VALUE rv_value);

  inline VALUE get_item(int &status);
  inline bool set_item(VALUE rv_value);
};

/*
 * inline methods of class ruby_c
 */

inline ruby_c::ruby_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"ruby_init()\n"););

  ruby_init();
  ruby_script("uclang");
  ruby_init_loadpath();

  values = rb_ary_new();
  rb_gc_register_address(&values);

  free_idxs.init();
}/*}}}*/

inline ruby_c::~ruby_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"ruby_exit()\n"););

  rb_gc_unregister_address(&values);
  free_idxs.clear();

  // - final ruby gc run -
  rb_gc_start();

  ruby_cleanup(0);
}/*}}}*/

inline unsigned ruby_c::keep_value(VALUE a_value)
{/*{{{*/
  unsigned idx;

  if (free_idxs.used != 0)
  {
    idx = free_idxs.pop();
    rb_ary_store(values,idx,a_value);
  }
  else
  {
    idx = RARRAY_LEN(values);
    rb_ary_push(values,a_value);
  }

  return idx;
}/*}}}*/

inline void ruby_c::release_value(unsigned a_idx)
{/*{{{*/
  rb_ary_store(values,a_idx,Qnil);
  free_idxs.push(a_idx);
}/*}}}*/

inline VALUE ruby_c::get_value(unsigned a_idx)
{/*{{{*/
  return rb_ary_entry(values,a_idx);
}/*}}}*/

/*
 * inline methods of structure ruby_reference_s
 */

inline void ruby_reference_s::init()
{/*{{{*/
  obj_idx = c_idx_not_exist;
  key_idx = c_idx_not_exist;
}/*}}}*/

inline void ruby_reference_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (obj_idx != c_idx_not_exist)
  {
    ruby_c::release_value(obj_idx);
  }

  if (key_idx != c_idx_not_exist)
  {
    ruby_c::release_value(key_idx);
  }

  init();
}/*}}}*/

inline VALUE ruby_reference_s::get_iv(int &status)
{/*{{{*/
  VALUE rv_obj = ruby_c::get_value(obj_idx);
  VALUE rv_key = ruby_c::get_value(key_idx);

  return rb_ivar_get(rv_obj,rb_intern_str(rv_key));
}/*}}}*/

inline bool ruby_reference_s::set_iv(VALUE rv_value)
{/*{{{*/
  VALUE rv_obj = ruby_c::get_value(obj_idx);
  VALUE rv_key = ruby_c::get_value(key_idx);

  return rb_ivar_set(rv_obj,rb_intern_str(rv_key),rv_value);
}/*}}}*/

inline VALUE ruby_reference_s::get_item(int &status)
{/*{{{*/
  VALUE rv_obj = ruby_c::get_value(obj_idx);
  VALUE rv_key = ruby_c::get_value(key_idx);

  switch (TYPE(rv_obj))
  {
  case T_ARRAY:
    return rb_ary_entry(rv_obj,RB_NUM2LONG(rv_key));

  case T_HASH:
    return rb_hash_lookup(rv_obj,rv_key);

  default:
    cassert(0);
  }
}/*}}}*/

inline bool ruby_reference_s::set_item(VALUE rv_value)
{/*{{{*/
  VALUE rv_obj = ruby_c::get_value(obj_idx);
  VALUE rv_key = ruby_c::get_value(key_idx);

  switch (TYPE(rv_obj))
  {
  case T_ARRAY:
    rb_ary_store(rv_obj,RB_NUM2LONG(rv_key),rv_value);
    return true;

  case T_HASH:
    rb_hash_aset(rv_obj,rv_key,rv_value);
    return true;

  default:
    cassert(0);
  }
}/*}}}*/

#endif

