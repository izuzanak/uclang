
@begin
include "ucl_pack.h"
@end

/*
 * methods of generated structures
 */

// -- name_pos_tree_s --
@begin
methods name_pos_tree_s
@end

// -- class_pack_s --
@begin
methods class_pack_s
@end

void class_pack_s::write_class_to_stream(interpreter_thread_s &a_it,unsigned a_class_idx,unsigned a_parent_idx)
{/*{{{*/

  // - retrieve class name -
  class_record_s &class_record = ((interpreter_s *)a_it.interpreter_ptr)->class_records[a_class_idx];
  string_s &class_name = ((interpreter_s *)a_it.interpreter_ptr)->class_symbol_names[class_record.name_idx];

  // - write class name to stream -
  class_stream.append(sizeof(unsigned),(const char *)&class_name.size);
  class_stream.append(class_name.size,(const char *)class_name.data);

  // - write parent class index to stream -
  class_stream.append(sizeof(unsigned),(const char *)&a_parent_idx);
}/*}}}*/

unsigned class_pack_s::pack_class_name(interpreter_thread_s &a_it,unsigned a_class_idx)
{/*{{{*/

  // - insert class index to class stack -
  class_stack.push(a_class_idx);

  unsigned p_idx = c_idx_not_exist;
  do
  {
    unsigned c_idx = class_stack.last();

    // - retrieve location class record -
    class_record_s &class_record = ((interpreter_s *)a_it.interpreter_ptr)->class_records[c_idx];

    if (p_idx == c_idx_not_exist)
    {
      // - find class name position -
      name_pos_s search_np = {c_idx,c_idx_not_exist};
      unsigned np_idx = name_pos_tree.get_idx(search_np);

      // - if class index c_idx is already stored -
      if (np_idx != c_idx_not_exist)
      {
        p_idx = name_pos_tree[np_idx].ui_second;

        class_stack.pop();
      }
      else
      {

        // - if class has parent class -
        if (class_record.parent_record != c_idx_not_exist)
        {
          class_stack.push(class_record.parent_record);
        }
        else
        {

          // - write class to stream -
          write_class_to_stream(a_it,c_idx,c_idx_not_exist);

          p_idx = name_pos_tree.count;

          name_pos_s insert_np = {c_idx,p_idx};
          name_pos_tree.insert(insert_np);

          class_stack.pop();
        }
      }
    }
    else
    {

      // - write class to stream -
      write_class_to_stream(a_it,c_idx,p_idx);

      p_idx = name_pos_tree.count;

      name_pos_s insert_np = {c_idx,p_idx};
      name_pos_tree.insert(insert_np);

      class_stack.pop();
    }

  }
  while(class_stack.used > 0);

  return p_idx;
}/*}}}*/

// -- class_unpack_s --
@begin
methods class_unpack_s
@end

bool class_unpack_s::unpack_from_stream(interpreter_thread_s &a_it,const char *a_stream,unsigned a_length,bool a_order_bytes)
{/*{{{*/
  class_idxs.used = 0;

  if (a_length == 0)
  {
    return true;
  }

  // - retrieve reference to class symbol names -
  string_rb_tree_s &class_symbol_names = ((interpreter_s *)a_it.interpreter_ptr)->class_symbol_names;

  // - retrieve reference to class records -
  class_records_s &class_records = ((interpreter_s *)a_it.interpreter_ptr)->class_records;

#define STREAM_LENGTH_TEST(LENGTH) \
  {/*{{{*/\
    if ((unsigned)(s_ptr_end - s_ptr) < LENGTH)\
    {\
      return false;\
    }\
  }/*}}}*/

  const char *s_ptr = a_stream;
  const char *s_ptr_end = s_ptr + a_length;
  do
  {

    STREAM_LENGTH_TEST(sizeof(unsigned));

    // - read class name size -
    unsigned class_name_size;
    memcpy_bo(&class_name_size,s_ptr,sizeof(unsigned),a_order_bytes);
    s_ptr += sizeof(unsigned);

    STREAM_LENGTH_TEST(class_name_size);

    // - read class name -
    const char *class_name = s_ptr;
    s_ptr += class_name_size;

    STREAM_LENGTH_TEST(sizeof(unsigned));

    // - read parent class index -
    unsigned parent_idx;
    memcpy_bo(&parent_idx,s_ptr,sizeof(unsigned),a_order_bytes);
    s_ptr += sizeof(unsigned);

    // - retrieve class name index -
    unsigned class_name_idx = class_symbol_names.get_idx_char_ptr(class_name_size - 1,class_name);

    // - ERROR -
    if (class_name_idx == c_idx_not_exist)
    {
      return false;
    }

    // - retrieve class record index -
    if (parent_idx != c_idx_not_exist)
    {
      if (class_idxs.used <= parent_idx)
      {
        return false;
      }

      parent_idx = class_idxs[parent_idx];
    }

    // - retrieve class record index -
    unsigned class_idx = c_idx_not_exist;

    if (class_records.used != 0)
    {
      class_record_s *cr_ptr = class_records.data;
      class_record_s *cr_ptr_end = cr_ptr + class_records.used;

      do
      {
        if (cr_ptr->parent_record == parent_idx && cr_ptr->name_idx == class_name_idx)
        {
          class_idx = cr_ptr - class_records.data;
          break;
        }
      }
      while(++cr_ptr < cr_ptr_end);
    }

    // - ERROR -
    if (class_idx == c_idx_not_exist)
    {
      return false;
    }

    // - insert class index to class indexes array -
    class_idxs.push(class_idx);

  }
  while(s_ptr < s_ptr_end);

  return true;
}/*}}}*/

/*
 * global functions
 */

bool bi_object_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack)
{/*{{{*/
  pointer_array_s *object_ptr = (pointer_array_s *)location_ptr->v_data_ptr;

  stream.append(sizeof(unsigned),(const char *)&object_ptr->used);

  if (object_ptr->used != 0)
  {
    pointer *l_ptr = object_ptr->data;
    pointer *l_ptr_end = l_ptr + object_ptr->used;

    do
    {
      loc_stack.push(*l_ptr);
    }
    while(++l_ptr < l_ptr_end);
  }

  return true;
}/*}}}*/

bool bi_object_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos)
{/*{{{*/
  pointer_array_s *object_ptr = it.get_new_array_ptr();

  location_ptr->v_data_ptr = (basic_64b)object_ptr;

  if (stream.used < sizeof(unsigned))
  {
    return false;
  }

  unsigned count;
  stream.from_end(sizeof(unsigned),(char *)&count,order_bytes);

  if (loc_stack.used < count)
  {
    return false;
  }

  if (count > 0)
  {
    object_ptr->copy_resize(count);

    pointer *l_ptr = loc_stack.data + (loc_stack.used - count);
    pointer *l_ptr_end = loc_stack.data + loc_stack.used;
    do
    {
      object_ptr->push(*l_ptr);
    }
    while(++l_ptr < l_ptr_end);

    loc_stack.used -= count;
  }

  return true;
}/*}}}*/

unsigned pcd_terminal_recognize(char **a_ptr)
{/*{{{*/
#define PCD_GET_NEXT_CHAR() in_char = **a_ptr;
#define PCD_CLOSE_CHAR(RET_TERM_IDX) ++(*a_ptr);

  unsigned short in_char;

// - STATE 0 -
  PCD_GET_NEXT_CHAR();

  if (in_char == 0)
    goto state_1_label;

  if (in_char >= 48 && in_char < 58)
    goto state_2_label;

  if (in_char == 60)
    goto state_3_label;

  if (in_char == 61)
    goto state_4_label;

  if (in_char == 62)
    goto state_5_label;

  if (in_char == 66)
    goto state_6_label;

  if (in_char == 72)
    goto state_7_label;

  if (in_char == 73)
    goto state_8_label;

  if (in_char == 76)
    goto state_9_label;

  if (in_char == 81)
    goto state_10_label;

  if (in_char == 98)
    goto state_11_label;

  if (in_char == 99)
    goto state_12_label;

  if (in_char == 100)
    goto state_13_label;

  if (in_char == 102)
    goto state_14_label;

  if (in_char == 104)
    goto state_15_label;

  if (in_char == 105)
    goto state_16_label;

  if (in_char == 108)
    goto state_17_label;

  if (in_char == 113)
    goto state_18_label;

  if (in_char == 115)
    goto state_19_label;

  return c_idx_not_exist;

// - STATE 1 -
state_1_label:
  PCD_CLOSE_CHAR(18)
  return 18;

// - STATE 2 -
state_2_label:
  PCD_CLOSE_CHAR(0)
  PCD_GET_NEXT_CHAR();

  if (in_char >= 48 && in_char < 58)
    goto state_2_label;

  return 0;

// - STATE 3 -
state_3_label:
  PCD_CLOSE_CHAR(2)
  return 2;

// - STATE 4 -
state_4_label:
  PCD_CLOSE_CHAR(1)
  return 1;

// - STATE 5 -
state_5_label:
  PCD_CLOSE_CHAR(3)
  return 3;

// - STATE 6 -
state_6_label:
  PCD_CLOSE_CHAR(6)
  return 6;

// - STATE 7 -
state_7_label:
  PCD_CLOSE_CHAR(8)
  return 8;

// - STATE 8 -
state_8_label:
  PCD_CLOSE_CHAR(10)
  return 10;

// - STATE 9 -
state_9_label:
  PCD_CLOSE_CHAR(12)
  return 12;

// - STATE 10 -
state_10_label:
  PCD_CLOSE_CHAR(14)
  return 14;

// - STATE 11 -
state_11_label:
  PCD_CLOSE_CHAR(5)
  return 5;

// - STATE 12 -
state_12_label:
  PCD_CLOSE_CHAR(4)
  return 4;

// - STATE 13 -
state_13_label:
  PCD_CLOSE_CHAR(16)
  return 16;

// - STATE 14 -
state_14_label:
  PCD_CLOSE_CHAR(15)
  return 15;

// - STATE 15 -
state_15_label:
  PCD_CLOSE_CHAR(7)
  return 7;

// - STATE 16 -
state_16_label:
  PCD_CLOSE_CHAR(9)
  return 9;

// - STATE 17 -
state_17_label:
  PCD_CLOSE_CHAR(11)
  return 11;

// - STATE 18 -
state_18_label:
  PCD_CLOSE_CHAR(13)
  return 13;

// - STATE 19 -
state_19_label:
  PCD_CLOSE_CHAR(17)
  return 17;

}/*}}}*/

