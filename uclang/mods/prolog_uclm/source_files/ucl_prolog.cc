
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

