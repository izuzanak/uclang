
#ifndef __UCL_PACK_H
#define __UCL_PACK_H

@begin
include "script_parser.h"
@end

/*
 * basic definitions and constants
 */

extern const unsigned short c_two_bytes;
extern const bool c_big_endian;
extern const bool c_little_endian;

// - pack code/decode terminals -
enum
{
  PCD_TERM_NUMBER = 0,
  PCD_TERM_NATIVE,
  PCD_TERM_LITTLE_ENDIAN,
  PCD_TERM_BIG_ENDIAN,
  PCD_TERM_CHAR,
  PCD_TERM_SIGNED_BYTE,
  PCD_TERM_UNSIGNED_BYTE,
  PCD_TERM_SHORT,
  PCD_TERM_UNSIGNED_SHORT,
  PCD_TERM_INT,
  PCD_TERM_UNSIGNED,
  PCD_TERM_LONG_INT,
  PCD_TERM_LONG_UNSIGNED,
  PCD_TERM_LONG_LONG_INT,
  PCD_TERM_LONG_LONG_UNSIGNED,
  PCD_TERM_FLOAT,
  PCD_TERM_DOUBLE,
  PCD_TERM_STRING,
  PCD_TERM_END,
};

/*
 * definition of generated structures
 */

// -- name_pos_tree_s --
@begin
safe_rb_tree<name_pos_s> name_pos_tree_s;
@end

// -- class_pack_s --
@begin
struct
    <
    name_pos_tree_s:name_pos_tree
    bc_array_s:class_stream
    ui_array_s:class_stack
    >

    additions
{
  void write_class_to_stream(interpreter_thread_s &a_it,unsigned a_class_idx,unsigned a_parent_idx);
  unsigned pack_class_name(interpreter_thread_s &a_it,unsigned a_class_idx);
}

class_pack_s;
@end

// -- class_unpack_s --
@begin
struct
    <
    ui_array_s:class_idxs
    >

    additions
{
  inline unsigned get_class_idx(unsigned a_class_pos);
  bool unpack_from_stream(interpreter_thread_s &a_it,const char *a_stream,unsigned a_length,bool a_order_bytes);
}

class_unpack_s;
@end

/*
 * inline methods of generated structures
 */

// -- name_pos_tree_s --
@begin
inlines name_pos_tree_s
@end

inline int name_pos_tree_s::__compare_value(name_pos_s &a_first,name_pos_s &a_second)
{/*{{{*/
  register unsigned first = a_first.ui_first;
  register unsigned second = a_second.ui_first;

  return first < second ? -1 : (first > second ? 1 : 0);
}/*}}}*/

// -- class_pack_s --
@begin
inlines class_pack_s
@end

// -- class_unpack_s --
@begin
inlines class_unpack_s
@end

inline unsigned class_unpack_s::get_class_idx(unsigned a_class_pos)
{/*{{{*/
  if (a_class_pos >= class_idxs.used)
  {
    return c_idx_not_exist;
  }

  return class_idxs[a_class_pos];
}/*}}}*/

/*
 * definition of global functions
 */

bool bi_object_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack);
bool bi_object_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos);

unsigned pcd_terminal_recognize(char **a_ptr);

#endif

