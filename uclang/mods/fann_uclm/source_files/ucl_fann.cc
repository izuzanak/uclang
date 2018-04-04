
@begin
include "ucl_fann.h"
@end

// - fann global init object -
fann_c g_fann;

/*
 * static members of class fann_c
 */

mutex_s fann_c::train_data_cb_mutex;
pointer_array_s *fann_c::train_data_array;

void fann_c::train_data_cb(unsigned num_data,unsigned num_input,unsigned num_output,fann_type *input,fann_type *output)
{/*{{{*/

  // - fill set of inputs -
  pointer_array_s *in_array =
    (pointer_array_s *)interpreter_thread_s::get_location_value(
        fann_c::train_data_array->data[num_data << 1])->v_data_ptr;

  pointer *i_ptr = in_array->data;
  pointer *i_ptr_end = i_ptr + in_array->used;
  double *input_ptr = input;
  do {
    interpreter_thread_s::retrieve_float(interpreter_thread_s::get_location_value(*i_ptr),*input_ptr);
  } while(++input_ptr,++i_ptr < i_ptr_end);

  // - fill set of desired outputs -
  pointer_array_s *out_array =
    (pointer_array_s *)interpreter_thread_s::get_location_value(
        fann_c::train_data_array->data[(num_data << 1) + 1])->v_data_ptr;

  pointer *o_ptr = out_array->data;
  pointer *o_ptr_end = o_ptr + out_array->used;
  double *output_ptr = output;
  do {
    interpreter_thread_s::retrieve_float(interpreter_thread_s::get_location_value(*o_ptr),*output_ptr);
  } while(++output_ptr,++o_ptr < o_ptr_end);
}/*}}}*/

