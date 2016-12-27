
#ifndef __UCL_RUBY_H
#define __UCL_RUBY_H

@begin
include "script_parser.h"
@end

#include <ruby.h>

/*
 * constants and definitions
 */

extern unsigned c_bi_class_ruby_value;
extern unsigned c_rm_class_dict;

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

  static int hash_kv_pair(VALUE key,VALUE value,VALUE array);

  static VALUE create_ruby_value(interpreter_thread_s &it,location_s *location_ptr,int &status);
  static location_s *ruby_value_value(interpreter_thread_s &it,VALUE value,uli source_pos);
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

  // FIXME debug output
  fprintf(stderr,"DEBUG_OUTPUT - RARRAY_LEN(values): %ld\n",RARRAY_LEN(values));
  fprintf(stderr,"DEBUG_OUTPUT - free_idxs.used: %u\n",free_idxs.used);

  rb_gc_unregister_address(&values);
  free_idxs.clear();

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

#endif
