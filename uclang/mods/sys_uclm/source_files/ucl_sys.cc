
@begin
include "ucl_sys.h"
@end

/*
 * methods of generated structures
 */

// -- timer_record_s --
@begin
   methods timer_record_s
@end

// -- timer_record_rb_tree_s --
@begin
   methods timer_record_rb_tree_s
@end

/*
 * inline methods of structure timer_s
 */

void timer_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - if some records exists -
  if (records.root_idx != c_idx_not_exist)
  {
    unsigned stack[records.get_descent_stack_size()];
    unsigned *stack_ptr = stack;
    
    // - release all records locations -
    unsigned r_idx = records.get_stack_min_value_idx(records.root_idx,&stack_ptr);
    do {
      timer_record_s &record = records.data[r_idx].object;

      // - release record callback delegate -
      it.release_location_ptr((location_s *)record.callback_dlg);

      // - release record callback parameter -
      it.release_location_ptr((location_s *)record.parameter);
      
      r_idx = records.get_stack_next_idx(r_idx,&stack_ptr,stack);
    } while(r_idx != c_idx_not_exist);
  }

  records.clear();

  init();
}/*}}}*/

