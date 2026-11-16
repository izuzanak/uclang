
#ifndef __UCL_OATH_H
#define __UCL_OATH_H

@begin
include "script_parser.h"
@end

#include <oath.h>

// - size of otp output buffer, enough for 8 digits, checksum digit and terminator -
const unsigned c_oath_otp_buffer_size = 16;

/*
 * definition of class oath_c
 */

class oath_c
{
  public:
  inline oath_c() noexcept;
  inline ~oath_c();
};

// -- oath_hotp_s --
@begin
struct
<
string_s:secret
ui:digits
bi:add_checksum
lli:truncation_offset
>
oath_hotp_s;
@end

// -- oath_totp_s --
@begin
struct
<
string_s:secret
ui:digits
ui:time_step
lli:start_offset
bi:flags
>
oath_totp_s;
@end

// - map liboath return code to module error index -
unsigned oath_rc_error_idx(int a_rc);

// - convert script truncation offset to liboath value, negative means dynamic truncation -
size_t oath_truncation_offset(long long int a_offset);

// - check totp flags value -
bool oath_flags_valid(long long int a_flags);

// - check time step value -
bool oath_time_step_valid(long long int a_time_step);

// - create array [otp_pos,otp_counter] -
location_s *oath_totp_result_array(interpreter_thread_s &it,int a_otp_pos,uint64_t a_otp_counter);

// -- oath_hotp_s --
@begin
inlines oath_hotp_s
@end

// -- oath_totp_s --
@begin
inlines oath_totp_s
@end

/*
 * inline methods of class oath_c
 */

inline oath_c::oath_c() noexcept
{/*{{{*/
  oath_init();
}/*}}}*/

inline oath_c::~oath_c()
{/*{{{*/
  oath_done();
}/*}}}*/

#endif

