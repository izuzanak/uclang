
@begin
include "ucl_lang.h"
@end

void get_top_level_classes(interpreter_thread_s &it,ui_array_s &a_class_idxs)
{/*{{{*/
  class_records_s &class_records = ((interpreter_s *)it.interpreter_ptr)->class_records;

  // *****

  a_class_idxs.used = 0;

  if (class_records.used != 0)
  {
    class_record_s *cr_ptr = class_records.data;
    class_record_s *cr_ptr_end = cr_ptr + class_records.used;

    do
    {
      if (cr_ptr->parent_record == c_idx_not_exist)
      {
        a_class_idxs.push(cr_ptr - class_records.data);
      }
    }
    while(++cr_ptr < cr_ptr_end);
  }
}/*}}}*/

bool get_top_level_class(interpreter_thread_s &it,unsigned a_name_idx,unsigned &a_class_idx)
{/*{{{*/
  class_records_s &class_records = ((interpreter_s *)it.interpreter_ptr)->class_records;

  // *****

  if (class_records.used != 0)
  {
    class_record_s *cr_ptr = class_records.data;
    class_record_s *cr_ptr_end = cr_ptr + class_records.used;

    do
    {
      if (cr_ptr->parent_record == c_idx_not_exist && cr_ptr->name_idx == a_name_idx)
      {
        a_class_idx = cr_ptr - class_records.data;

        return true;
      }
    }
    while(++cr_ptr < cr_ptr_end);
  }

  a_class_idx = c_idx_not_exist;

  return false;
}/*}}}*/

bool get_class_idx_by_path(interpreter_thread_s &it,pointer_array_s *a_path_array,unsigned a_path_length,unsigned &a_class_idx)
{/*{{{*/
  class_records_s &class_records = ((interpreter_s *)it.interpreter_ptr)->class_records;
  string_rb_tree_s &class_symbol_names = ((interpreter_s *)it.interpreter_ptr)->class_symbol_names;

  // *****

  unsigned name_idxs[a_path_length];

  // - process class names from path array -
  pointer *p_ptr = a_path_array->data;
  pointer *p_ptr_end = p_ptr + a_path_length;
  unsigned *n_ptr = name_idxs;
  do
  {
    location_s *location = it.get_location_value(*p_ptr);

    if (location->v_type != c_bi_class_string)
    {
      return false;
    }

    // - retrieve index of class symbol -
    string_s *str = (string_s *)location->v_data_ptr;
    *n_ptr = class_symbol_names.get_idx_char_ptr(str->size - 1,str->data);

    if (*n_ptr == c_idx_not_exist)
    {
      return false;
    }

  }
  while(++n_ptr,++p_ptr < p_ptr_end);

  // - retrieve top level class index -
  unsigned class_idx;
  if (!get_top_level_class(it,name_idxs[0],class_idx))
  {
    return false;
  }

  // - process rest of class path -
  if (a_path_length > 1)
  {
    unsigned name_idx = 1;
    do
    {
      ui_array_s &class_record_idxs = class_records[class_idx].class_record_idxs;
      if (class_record_idxs.used != 0)
      {

        unsigned *cri_ptr = class_record_idxs.data;
        unsigned *cri_ptr_end = cri_ptr + class_record_idxs.used;
        do
        {
          if (class_records[*cri_ptr].name_idx == name_idxs[name_idx])
          {
            class_idx = *cri_ptr;
            break;
          }
        }
        while(++cri_ptr < cri_ptr_end);

        // - test if class was found -
        if (cri_ptr >= cri_ptr_end)
        {
          return false;
        }
      }
      else
      {
        return false;
      }
    }
    while(++name_idx < a_path_length);
  }

  a_class_idx = class_idx;

  return true;
}/*}}}*/

