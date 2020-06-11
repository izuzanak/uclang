
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
  else
  {
    switch (location_ptr->v_type)
    {
      case c_bi_class_blank:
        return PL_put_variable(term);
      case c_bi_class_integer:
        return PL_put_integer(term,(long long int)location_ptr->v_data_ptr);
      case c_bi_class_float:
        return PL_put_float(term,(double)location_ptr->v_data_ptr);
      case c_bi_class_string:
        {/*{{{*/
          string_s *string_ptr = (string_s *)location_ptr->v_data_ptr;
          atom_t atom = PL_new_atom_nchars(string_ptr->size - 1,string_ptr->data);
          return PL_put_atom(term,atom);
        }/*}}}*/
      case c_bi_class_array:
        {/*{{{*/
          pointer_array_s *array_ptr = (pointer_array_s *)location_ptr->v_data_ptr;

          // - create empty list -
          PL_put_nil(term);

          if (array_ptr->used != 0)
          {
            term_t item_term = PL_new_term_ref();

            // - process array items backwards -
            pointer *i_ptr = array_ptr->data + array_ptr->used;
            pointer *i_ptr_end = array_ptr->data;
            while(--i_ptr >= i_ptr_end)
            {
              location_s *item_location = it.get_location_value(*i_ptr);

              if (!prolog_c::create_prolog_term(it,item_term,item_location))
              {
                return false;
              }

              // - append head to tail -
              if (!PL_cons_list(term,item_term,term))
              {
                return false;
              }
            }
          }

          return true;
        }/*}}}*/
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

      // - ERROR -
      if (!PL_get_atom(term,&atom))
      {
        return nullptr;
      }

      size_t length;
      const char *data = PL_atom_nchars(atom,&length);

      string_s *string_ptr = it.get_new_string_ptr();
      string_ptr->set(length,data);

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
      return new_location;
    }/*}}}*/
  case PL_NIL:
    {/*{{{*/
      pointer_array_s *array_ptr = it.get_new_array_ptr();

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
      return new_location;
    }/*}}}*/
  case PL_INTEGER:
    {/*{{{*/
      int64_t value;

      // - ERROR -
      if (!PL_get_int64(term,&value))
      {
        return nullptr;
      }

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);
      return new_location;
    }/*}}}*/
  case PL_FLOAT:
    {/*{{{*/
      double value;

      // - ERROR -
      if (!PL_get_float(term,&value))
      {
        return nullptr;
      }

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_float,value);
      return new_location;
    }/*}}}*/
  case PL_LIST_PAIR:
    {/*{{{*/
      pointer_array_s *array_ptr = it.get_new_array_ptr();
      BIC_CREATE_NEW_LOCATION(arr_location,c_bi_class_array,array_ptr);

      term_t list = PL_copy_term_ref(term);
      term_t head = PL_new_term_ref();

      do {

        // - ERROR -
        if (!PL_get_list(list,head,list))
        {
          it.release_location_ptr(arr_location);
          return nullptr;
        }

        location_s *item_location = prolog_c::prolog_term_value(it,head,source_pos);

        // - ERROR -
        if (item_location == nullptr)
        {
          it.release_location_ptr(arr_location);
          return nullptr;
        }

        // - insert item to array -
        array_ptr->push(item_location);

      } while(PL_is_pair(list));

      return arr_location;
    }/*}}}*/
  case PL_BLOB:
  case PL_STRING:
  case PL_TERM:
  case PL_DICT:
  default:
    return nullptr;
  }
}/*}}}*/

