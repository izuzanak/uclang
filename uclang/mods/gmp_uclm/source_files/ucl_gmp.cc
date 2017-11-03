
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
  int length = mpfr_vsnprintf(a_target.data,init_size,a_format,ap);
  va_end(ap);

  a_target.size = length + 1;

  if (a_target.size > init_size)
  {
    cfree(a_target.data);
    a_target.data = (char *)cmalloc(a_target.size*sizeof(char));

    va_start(ap,a_format);
    mpfr_vsnprintf(a_target.data,a_target.size,a_format,ap);
    va_end(ap);
  }
}/*}}}*/

void gmp_c::mpz_set_lli(mpz_ptr a_mpz,long long int a_value)
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

int gmp_c::mpz_cmp_lli(mpz_ptr a_mpz,long long int a_value)
{/*{{{*/
  if (a_value >= LONG_MIN && a_value <= LONG_MAX)
  {
    return mpz_cmp_si(a_mpz,a_value);
  }

  if (a_value >= 0 && a_value <= ULONG_MAX)
  {
    return mpz_cmp_ui(a_mpz,a_value);
  }

  mpz_t tmp_mpz;
  mpz_init(tmp_mpz);
  mpz_set_lli(tmp_mpz,a_value);
  int result = mpz_cmp(a_mpz,tmp_mpz);
  mpz_clear(tmp_mpz);

  return result;
}/*}}}*/

void gmp_c::mpz_add_lli(mpz_ptr a_res,mpz_srcptr a_mpz,long long int a_value)
{/*{{{*/
  if (a_value >= 0 && a_value <= ULONG_MAX)
  {
    mpz_add_ui(a_res,a_mpz,a_value);
  }
  else
  {
    mpz_set_lli(a_res,a_value);
    mpz_add(a_res,a_mpz,a_res);
  }
}/*}}}*/

void gmp_c::mpz_sub_lli(mpz_ptr a_res,mpz_srcptr a_mpz,long long int a_value)
{/*{{{*/
  if (a_value >= 0 && a_value <= ULONG_MAX)
  {
    mpz_sub_ui(a_res,a_mpz,a_value);
  }
  else
  {
    mpz_set_lli(a_res,a_value);
    mpz_sub(a_res,a_mpz,a_res);
  }
}/*}}}*/

void gmp_c::mpz_mul_lli(mpz_ptr a_res,mpz_srcptr a_mpz,long long int a_value)
{/*{{{*/
  if (a_value >= LONG_MIN && a_value <= LONG_MAX)
  {
    mpz_mul_si(a_res,a_mpz,a_value);
  }
  else if (a_value >= 0 && a_value <= ULONG_MAX)
  {
    mpz_mul_ui(a_res,a_mpz,a_value);
  }
  else
  {
    mpz_set_lli(a_res,a_value);
    mpz_mul(a_res,a_mpz,a_res);
  }
}/*}}}*/

void gmp_c::mpz_div_lli(mpz_ptr a_res,mpz_srcptr a_mpz,long long int a_value)
{/*{{{*/
  if (a_value >= 0 && a_value <= ULONG_MAX)
  {
    mpz_div_ui(a_res,a_mpz,a_value);
  }
  else
  {
    mpz_set_lli(a_res,a_value);
    mpz_div(a_res,a_mpz,a_res);
  }
}/*}}}*/

void gmp_c::mpz_mod_lli(mpz_ptr a_res,mpz_srcptr a_mpz,long long int a_value)
{/*{{{*/
  if (a_value >= 0 && a_value <= ULONG_MAX)
  {
    mpz_mod_ui(a_res,a_mpz,a_value);
  }
  else
  {
    mpz_set_lli(a_res,a_value);
    mpz_mod(a_res,a_mpz,a_res);
  }
}/*}}}*/

void gmp_c::mpq_set_lli(mpq_ptr a_mpq,long long int a_value)
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

void gmp_c::mpq_set_lli_lli(mpq_ptr a_mpq,long long int a_value,long long int a_denom)
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

void gmp_c::mpq_set_z_lli(mpq_ptr a_mpq,mpz_srcptr a_value,long long int a_denom)
{/*{{{*/
  mpz_set(mpq_numref(a_mpq),a_value);
  mpz_set_lli(mpq_denref(a_mpq),a_denom);
  mpq_canonicalize(a_mpq);
}/*}}}*/

void gmp_c::mpq_set_lli_z(mpq_ptr a_mpq,long long int a_value,mpz_srcptr a_denom)
{/*{{{*/
  mpz_set_lli(mpq_numref(a_mpq),a_value);
  mpz_set(mpq_denref(a_mpq),a_denom);
  mpq_canonicalize(a_mpq);
}/*}}}*/

void gmp_c::mpq_set_z_z(mpq_ptr a_mpq,mpz_srcptr a_value,mpz_srcptr a_denom)
{/*{{{*/
  mpz_set(mpq_numref(a_mpq),a_value);
  mpz_set(mpq_denref(a_mpq),a_denom);
  mpq_canonicalize(a_mpq);
}/*}}}*/

int gmp_c::mpq_cmp_lli(mpq_ptr a_mpq,long long int a_value)
{/*{{{*/
  if (a_value >= LONG_MIN && a_value <= LONG_MAX)
  {
    return mpq_cmp_si(a_mpq,a_value,1);
  }

  if (a_value >= 0 && a_value <= ULONG_MAX)
  {
    return mpq_cmp_ui(a_mpq,a_value,1);
  }

  mpz_t tmp_mpz;
  mpz_init(tmp_mpz);
  mpz_set_lli(tmp_mpz,a_value);
  int result = mpq_cmp_z(a_mpq,tmp_mpz);
  mpz_clear(tmp_mpz);

  return result;
}/*}}}*/

void gmp_c::mpq_add_lli(mpq_ptr a_res,mpq_srcptr a_mpq,long long int a_value)
{/*{{{*/
  if (a_value >= 0 && a_value <= ULONG_MAX)
  {
    mpq_set(a_res,a_mpq);
    mpz_addmul_ui(mpq_numref(a_res),mpq_denref(a_res),a_value);
  }
  else
  {
    mpq_set_lli(a_res,a_value);
    mpq_add(a_res,a_mpq,a_res);
  }
}/*}}}*/

void gmp_c::mpq_sub_lli(mpq_ptr a_res,mpq_srcptr a_mpq,long long int a_value)
{/*{{{*/
  if (a_value >= 0 && a_value <= ULONG_MAX)
  {
    mpq_set(a_res,a_mpq);
    mpz_submul_ui(mpq_numref(a_res),mpq_denref(a_res),a_value);
  }
  else
  {
    mpq_set_lli(a_res,a_value);
    mpq_sub(a_res,a_mpq,a_res);
  }
}/*}}}*/

void gmp_c::mpq_mul_lli(mpq_ptr a_res,mpq_srcptr a_mpq,long long int a_value)
{/*{{{*/
  mpz_mul_lli(mpq_numref(a_res),mpq_numref(a_mpq),a_value);
  mpz_set(mpq_denref(a_res),mpq_denref(a_mpq));
  mpq_canonicalize(a_res);
}/*}}}*/

void gmp_c::mpq_mul_z(mpq_ptr a_res,mpq_srcptr a_mpq,mpz_srcptr a_mpz)
{/*{{{*/
  mpz_mul(mpq_numref(a_res),mpq_numref(a_mpq),a_mpz);
  mpz_set(mpq_denref(a_res),mpq_denref(a_mpq));
  mpq_canonicalize(a_res);
}/*}}}*/

int gmp_c::mpfr_cmp_lli(mpfr_ptr a_mpfr,long long int a_value)
{/*{{{*/
  if (a_value >= LONG_MIN && a_value <= LONG_MAX)
  {
    return mpfr_cmp_si(a_mpfr,a_value);
  }

  if (a_value >= 0 && a_value <= ULONG_MAX)
  {
    return mpfr_cmp_ui(a_mpfr,a_value);
  }

  mpz_t tmp_mpz;
  mpz_init(tmp_mpz);
  mpz_set_lli(tmp_mpz,a_value);
  int result = mpfr_cmp_z(a_mpfr,tmp_mpz);
  mpz_clear(tmp_mpz);

  return result;
}/*}}}*/

void gmp_c::mpfr_add_lli(mpfr_ptr a_res,mpfr_srcptr a_mpfr,long long int a_value,mpfr_rnd_t a_rnd)
{/*{{{*/
  if (a_value >= LONG_MIN && a_value <= LONG_MAX)
  {
    mpfr_add_si(a_res,a_mpfr,a_value,a_rnd);
  }
  else if (a_value >= 0 && a_value <= ULONG_MAX)
  {
    mpfr_add_ui(a_res,a_mpfr,a_value,a_rnd);
  }
  else
  {
    mpfr_set_sj(a_res,a_value,a_rnd);
    mpfr_add(a_res,a_mpfr,a_res,a_rnd);
  }
}/*}}}*/

void gmp_c::mpfr_sub_lli(mpfr_ptr a_res,mpfr_srcptr a_mpfr,long long int a_value,mpfr_rnd_t a_rnd)
{/*{{{*/
  if (a_value >= LONG_MIN && a_value <= LONG_MAX)
  {
    mpfr_sub_si(a_res,a_mpfr,a_value,a_rnd);
  }
  else if (a_value >= 0 && a_value <= ULONG_MAX)
  {
    mpfr_sub_ui(a_res,a_mpfr,a_value,a_rnd);
  }
  else
  {
    mpfr_set_sj(a_res,a_value,a_rnd);
    mpfr_sub(a_res,a_mpfr,a_res,a_rnd);
  }
}/*}}}*/

void gmp_c::mpfr_mul_lli(mpfr_ptr a_res,mpfr_srcptr a_mpfr,long long int a_value,mpfr_rnd_t a_rnd)
{/*{{{*/
  if (a_value >= LONG_MIN && a_value <= LONG_MAX)
  {
    mpfr_mul_si(a_res,a_mpfr,a_value,a_rnd);
  }
  else if (a_value >= 0 && a_value <= ULONG_MAX)
  {
    mpfr_mul_ui(a_res,a_mpfr,a_value,a_rnd);
  }
  else
  {
    mpfr_set_sj(a_res,a_value,a_rnd);
    mpfr_mul(a_res,a_mpfr,a_res,a_rnd);
  }
}/*}}}*/

void gmp_c::mpfr_div_lli(mpfr_ptr a_res,mpfr_srcptr a_mpfr,long long int a_value,mpfr_rnd_t a_rnd)
{/*{{{*/
  if (a_value >= LONG_MIN && a_value <= LONG_MAX)
  {
    mpfr_div_si(a_res,a_mpfr,a_value,a_rnd);
  }
  else if (a_value >= 0 && a_value <= ULONG_MAX)
  {
    mpfr_div_ui(a_res,a_mpfr,a_value,a_rnd);
  }
  else
  {
    mpfr_set_sj(a_res,a_value,a_rnd);
    mpfr_div(a_res,a_mpfr,a_res,a_rnd);
  }
}/*}}}*/

void gmp_c::mpfr_pow_lli(mpfr_ptr a_res,mpfr_srcptr a_mpfr,long long int a_value,mpfr_rnd_t a_rnd)
{/*{{{*/
  if (a_value >= LONG_MIN && a_value <= LONG_MAX)
  {
    mpfr_pow_si(a_res,a_mpfr,a_value,a_rnd);
  }
  else if (a_value >= 0 && a_value <= ULONG_MAX)
  {
    mpfr_pow_ui(a_res,a_mpfr,a_value,a_rnd);
  }
  else
  {
    mpfr_set_sj(a_res,a_value,a_rnd);
    mpfr_pow(a_res,a_mpfr,a_res,a_rnd);
  }
}/*}}}*/

