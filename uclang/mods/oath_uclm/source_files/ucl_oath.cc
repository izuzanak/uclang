
@begin
include "ucl_oath.h"
@end

// - oath global init object -
oath_c g_oath;

unsigned oath_rc_error_idx(int a_rc)
{/*{{{*/

  // - unknown or non-negative codes map to the first error slot -
  if (a_rc >= 0 || a_rc < OATH_LAST_ERROR)
  {
    return 0;
  }

  return (unsigned)(-a_rc - 1);
}/*}}}*/

size_t oath_truncation_offset(long long int a_offset)
{/*{{{*/
  return a_offset < 0 ? OATH_HOTP_DYNAMIC_TRUNCATION : (size_t)a_offset;
}/*}}}*/

bool oath_flags_valid(long long int a_flags)
{/*{{{*/
  return a_flags == 0 || a_flags == OATH_TOTP_HMAC_SHA256 || a_flags == OATH_TOTP_HMAC_SHA512;
}/*}}}*/

bool oath_time_step_valid(long long int a_time_step)
{/*{{{*/
  return a_time_step >= 1 && a_time_step <= UINT_MAX;
}/*}}}*/

location_s *oath_totp_result_array(interpreter_thread_s &it,int a_otp_pos,uint64_t a_otp_counter)
{/*{{{*/
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  BIC_CREATE_NEW_LOCATION(pos_location,c_bi_class_integer,(long long int)a_otp_pos);
  array_ptr->push(pos_location);

  BIC_CREATE_NEW_LOCATION(counter_location,c_bi_class_integer,(long long int)a_otp_counter);
  array_ptr->push(counter_location);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);

  return new_location;
}/*}}}*/

