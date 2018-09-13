
@begin
include "ucl_uctrdpmd.h"
@end

// - uctrdp global init object -
uctrdpmd_c g_uctrdp;

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
 * static members of class uctrdpmd_c
 */

mutex_s uctrdpmd_c::gate_id_mutex;
bi_array_s uctrdpmd_c::free_gate_ids;
int uctrdpmd_c::next_gate_id;

