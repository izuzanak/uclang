
@begin
include "ucl_ruby.h"
@end

// - static members of class ruby_c -
VALUE ruby_c::values;
ui_array_s ruby_c::free_idxs;

// - ruby global init object -
ruby_c g_ruby;

/*
 * methods of class ruby_c
 */

VALUE ruby_c::rb_load_protect(VALUE a_file_name)
{/*{{{*/
  rb_load(a_file_name,0);

  return Qnil;
}/*}}}*/

VALUE ruby_c::rb_require_protect(VALUE a_file_name)
{/*{{{*/
  return rb_f_require(Qnil,a_file_name);
}/*}}}*/

