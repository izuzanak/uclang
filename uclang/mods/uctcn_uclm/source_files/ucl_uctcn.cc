
@begin
include "ucl_uctcn.h"
@end

// - uctcn global init object -
uctcn_c g_uctcn;

/*
 * methods of generated structures
 */

// -- ui_rb_tree_s --
@begin
   methods ui_rb_tree_s
@end

// -- pv_list_array_s --
@begin
   methods pv_list_array_s
@end

/*
 * methods of structure proc_var_set_s
 */

void proc_var_set_s::add_variable(string_s &a_name,int a_type,int a_count,int a_offset,int a_bitoff,int a_bit_size)
{/*{{{*/

  // - insert variable name to name array -
  name_array.push(a_name);

  // - insert variable to list array -
  list_array.push_blank();
  pv_list_s &list = list_array.last();

  // - set variable properties -
  list.u8DerivedType = a_type;
  list.u8ArrayCount  = a_count;
  list.u8OctetOffset = a_offset;
  list.u8BitNumber   = a_bitoff;

  // - variable byte size -
  int byte_size = ((a_bit_size - 1) >> 3) + 1;

  // - allocate variable memory -
  list.pVariable = cmalloc(byte_size);

  // - update pv set list properties -
  pv_set.u16CPvList = list_array.used;
  pv_set.asPvList = list_array.data;

}/*}}}*/

