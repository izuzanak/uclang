
@begin
include "ucl_prolog.h"
@end

// - static members of class prolog_c -
qid_t prolog_c::qid = 0;

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
  if (location_ptr->v_type == c_bi_class_prolog_atom)
  {
    return PL_put_atom(term,(atom_t)location_ptr->v_data_ptr);
  }
  else if (location_ptr->v_type == c_bi_class_prolog_term)
  {
    return PL_put_term(term,(term_t)location_ptr->v_data_ptr);
  }

  // FIXME TODO remote dict
  //else if (location_ptr->v_type != c_rm_class_dict)
  //{
  //}
  else
  {
    switch (location_ptr->v_type)
    {
      // FIXME TODO remove c_bi_class_blank
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
  switch (PL_term_type(term))
  {
  case PL_VARIABLE:
    {/*{{{*/
      ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();
      return (location_s *)it.blank_location;
    }/*}}}*/
  case PL_ATOM:
    {/*{{{*/
      atom_t atom;
      if (!PL_get_atom(term,&atom))
      {
        return NULL;
      }

      size_t length;
      const char *data = PL_atom_nchars(atom,&length);

      string_s *string_ptr = it.get_new_string_ptr();
      string_ptr->set(length,data);

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
      return new_location;
    }/*}}}*/
  case PL_NIL:
  case PL_BLOB:
  case PL_STRING:
  case PL_INTEGER:
  case PL_FLOAT:
  case PL_TERM:
  case PL_LIST_PAIR:
  case PL_DICT:
  default:
    return NULL;
  }
}/*}}}*/

