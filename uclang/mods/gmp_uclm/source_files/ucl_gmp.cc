
@begin
include "ucl_gmp.h"
@end

// - gmp global init object -
gmp_c g_gmp;

void gmp_c::setf(string_s &a_target,const char *a_format,...)
{/*{{{*/
  a_target.clear();

  const size_t init_size = 128;
  va_list ap;

  a_target.data = (char *)cmalloc(init_size*sizeof(char));

  va_start(ap,a_format);
  int length = gmp_vsnprintf(a_target.data,init_size,a_format,ap);
  va_end(ap);

  a_target.size = length + 1;

  if (a_target.size > init_size)
  {
    cfree(a_target.data);
    a_target.data = (char *)cmalloc(a_target.size*sizeof(char));

    va_start(ap,a_format);
    gmp_vsnprintf(a_target.data,a_target.size,a_format,ap);
    va_end(ap);
  }
}/*}}}*/

void gmp_c::mpz_set_lli(mpz_t &a_mpz,long long int a_value)
{/*{{{*/
  if (a_value >= LONG_MIN && a_value <= LONG_MAX)
  {
    mpz_set_si(a_mpz,(long int)a_value);
  }
  else if (a_value >= 0 && a_value <= ULONG_MAX)
  {
    mpz_set_ui(a_mpz,(unsigned long int)a_value);
  }
  else
  {
    char buffer[32];
    snprintf(buffer,32,"%" HOST_LL_FORMAT "d",a_value);
    mpz_set_str(a_mpz,buffer,10);
  }
}/*}}}*/

