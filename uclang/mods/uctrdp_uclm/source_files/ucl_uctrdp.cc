
@begin
include "ucl_uctrdp.h"
@end

// - uctrdp global init object -
uctrdp_c g_uctrdp;

/*
 * methods of generated structures
 */

// -- handle_data_s --
@begin
methods handle_data_s
@end

// -- handle_data_rb_tree_s --
@begin
methods handle_data_rb_tree_s
@end

/*
 * static members of class uctrdp_c
 */

mutex_s uctrdp_c::gate_id_mutex;
bi_array_s uctrdp_c::free_gate_ids;
int uctrdp_c::next_gate_id;

