
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
    mpz_set_si(a_mpz,a_value);
  }
  else if (a_value >= 0 && a_value <= ULONG_MAX)
  {
    mpz_set_ui(a_mpz,a_value);
  }
  else
  {
    char buffer[32];
    snprintf(buffer,32,"%" HOST_LL_FORMAT "d",a_value);
    mpz_set_str(a_mpz,buffer,10);
  }
}/*}}}*/

void gmp_c::mpq_set_lli(mpq_t &a_mpq,long long int a_value)
{/*{{{*/
  if (a_value >= LONG_MIN && a_value <= LONG_MAX)
  {
    mpq_set_si(a_mpq,a_value,1);
  }
  else if (a_value >= 0 && a_value <= ULONG_MAX)
  {
    mpq_set_ui(a_mpq,a_value,1);
  }
  else
  {
    char buffer[32];
    snprintf(buffer,32,"%" HOST_LL_FORMAT "d/1",a_value);
    mpq_set_str(a_mpq,buffer,10);
  }
}/*}}}*/

void gmp_c::mpq_set_lli_lli(mpq_t &a_mpq,long long int a_value,long long int a_denom)
{/*{{{*/
  do
  {
    if (a_denom >= 0 && a_denom < ULONG_MAX)
    {
      if (a_value >= LONG_MIN && a_value <= LONG_MAX)
      {
        mpq_set_si(a_mpq,a_value,a_denom);
        break;
      }
      else if (a_value >= 0 && a_value <= ULONG_MAX)
      {
        mpq_set_ui(a_mpq,a_value,a_denom);
        break;
      }
    }

    char buffer[64];
    snprintf(buffer,64,"%" HOST_LL_FORMAT "d/%" HOST_LL_FORMAT "d",a_value,a_denom);
    mpq_set_str(a_mpq,buffer,10);
  } while(0);

  mpq_canonicalize(a_mpq);
}/*}}}*/

void gmp_c::mpf_set_lli(mpf_t &a_mpf,long long int a_value)
{/*{{{*/
  if (a_value >= LONG_MIN && a_value <= LONG_MAX)
  {
    mpf_set_si(a_mpf,a_value);
  }
  else if (a_value >= 0 && a_value <= ULONG_MAX)
  {
    mpf_set_ui(a_mpf,a_value);
  }
  else
  {
    char buffer[32];
    snprintf(buffer,32,"%" HOST_LL_FORMAT "d",a_value);
    mpf_set_str(a_mpf,buffer,10);
  }
}/*}}}*/

