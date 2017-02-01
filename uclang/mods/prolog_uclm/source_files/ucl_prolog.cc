
@begin
include "ucl_prolog.h"
@end

// - prolog global init object -
prolog_c g_prolog;

/*
 * methods of class prolog_c
 */

bool prolog_c::retrieve_atom(location_s *location_ptr,atom_t &atom)
{/*{{{*/
  if (location_ptr->v_type == c_bi_class_prolog_atom)
  {
    atom = (atom_t)location_ptr->v_data_ptr;
    return true;
  }

  if (location_ptr->v_type == c_bi_class_string)
  {
    string_s *string_ptr = (string_s *)location_ptr->v_data_ptr;
    atom = PL_new_atom_nchars(string_ptr->size - 1,string_ptr->data);
    return true;
  }
  
  return false;
}/*}}}*/

bool prolog_c::create_prolog_term(interpreter_thread_s &it,term_t term,location_s *location_ptr)
{/*{{{*/

  //PL_VARIABLE
  //PL_ATOM
  //PL_NIL
  //PL_BLOB
  //PL_STRING
  //PL_INTEGER
  //PL_FLOAT
  //PL_TERM
  //PL_LIST_PAIR
  //PL_DICT

  if (location_ptr->v_type == c_bi_class_prolog_atom)
  {
    atom_t atom = (atom_t)location_ptr->v_data_ptr;
    return PL_put_atom(term,atom);
  }
  // FIXME TODO remote dict
  //else if (location_ptr->v_type != c_rm_class_dict)
  //{
  //}
  else
  {
    switch (location_ptr->v_type)
    {
      case c_bi_class_blank:
        return PL_put_nil(term);
      case c_bi_class_integer:
        return PL_put_integer(term,(long long int)location_ptr->v_data_ptr);
      case c_bi_class_float:
        return PL_put_float(term,(double)location_ptr->v_data_ptr);
      case c_bi_class_string:
        {
          string_s *string_ptr = (string_s *)location_ptr->v_data_ptr;
          atom_t atom = PL_new_atom_nchars(string_ptr->size - 1,string_ptr->data);
          return PL_put_atom(term,atom);
        }
      // FIXME TODO array
      // case c_bi_class_array
      default:
        return false;
    }
  }
}/*}}}*/

location_s *prolog_c::prolog_term_value(interpreter_thread_s &it,term_t term,uli source_pos)
{/*{{{*/

  // FIXME TODO continue ...
  return NULL;
}/*}}}*/

