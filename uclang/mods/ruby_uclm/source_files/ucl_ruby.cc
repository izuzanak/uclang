
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

VALUE ruby_c::rb_big2ll_protect(VALUE a_big_num)
{/*{{{*/
  rb_big2ll(a_big_num);

  return Qnil;
}/*}}}*/

VALUE ruby_c::create_ruby_value(interpreter_thread_s &it,location_s *location_ptr,int &status)
{/*{{{*/
  status = 0;

  if (location_ptr->v_type == c_bi_class_ruby_value)
  {
    return ruby_c::get_value((unsigned)location_ptr->v_data_ptr);
  }
  else
  {
    status = 1;
    return Qnil;
  }
}/*}}}*/

location_s *ruby_c::ruby_value_value(interpreter_thread_s &it,VALUE rv_value,uli source_pos)
{/*{{{*/
  switch (TYPE(rv_value))
  {
  case T_NIL:
  {/*{{{*/
    ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();
    return (location_s *)it.blank_location;
  }/*}}}*/

  case T_FIXNUM:
  {/*{{{*/
    long long int value = FIX2LONG(rv_value);

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);
    return new_location;
  }/*}}}*/

  case T_BIGNUM:
  {/*{{{*/
    int state;
    rb_protect(ruby_c::rb_big2ll_protect,rv_value,&state);

    // - ERROR -
    if (state)
    {
      return NULL;
    }

    long long int value = rb_big2ll(rv_value);

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);
    return new_location;
  }/*}}}*/

  case T_FLOAT:
  {/*{{{*/
    double value = RFLOAT_VALUE(rv_value);

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_float,value);
    return new_location;
  }/*}}}*/

  case T_STRING:
  {/*{{{*/
    string_s *string_ptr = it.get_new_string_ptr();
    string_ptr->set(RSTRING_LEN(rv_value),StringValuePtr(rv_value));

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
    return new_location;
  }/*}}}*/

  case T_SYMBOL:
  case T_ARRAY:
  case T_HASH:
  case T_TRUE:
  case T_FALSE:
  case T_DATA:

  default:
    return NULL;
  }
}/*}}}*/

