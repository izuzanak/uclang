
@begin
include "ucl_uctrdp.h"
@end

// - uctrdp global init object -
uctrdp_c g_uctrdp;

/*
 * static members of class uctrdp_c
 */

mutex_s uctrdp_c::gate_id_mutex;
bi_array_s uctrdp_c::free_gate_ids;
int uctrdp_c::next_gate_id;

