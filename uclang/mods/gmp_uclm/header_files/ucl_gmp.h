
#ifndef __UCL_GMP_H
#define __UCL_GMP_H

@begin
include "script_parser.h"
@end

#include <stdint.h>
#include <gmp.h>
#include <mpfr.h>

/*
 * definition of class gmp_c
 */
class gmp_c
{
  public:
  inline gmp_c();
  inline ~gmp_c();

  static void setf(string_s &a_target,const char *a_format,...);

  static void mpz_set_lli(mpz_ptr a_mpz,long long int a_value);
  static int mpz_cmp_lli(mpz_ptr a_mpz,long long int a_value);
  static void mpz_add_lli(mpz_ptr a_res,mpz_srcptr a_mpz,long long int a_value);
  static void mpz_sub_lli(mpz_ptr a_res,mpz_srcptr a_mpz,long long int a_value);
  static void mpz_mul_lli(mpz_ptr a_res,mpz_srcptr a_mpz,long long int a_value);
  static void mpz_div_lli(mpz_ptr a_res,mpz_srcptr a_mpz,long long int a_value);
  static void mpz_mod_lli(mpz_ptr a_res,mpz_srcptr a_mpz,long long int a_value);

  static void mpq_set_lli(mpq_ptr a_mpq,long long int a_value);
  static void mpq_set_lli_lli(mpq_ptr a_mpq,long long int a_value,long long int a_denom);
  static void mpq_set_z_lli(mpq_ptr a_mpq,mpz_srcptr a_value,long long int a_denom);
  static void mpq_set_lli_z(mpq_ptr a_mpq,long long int a_value,mpz_srcptr a_denom);
  static void mpq_set_z_z(mpq_ptr a_mpq,mpz_srcptr a_value,mpz_srcptr a_denom);
  static int mpq_cmp_lli(mpq_ptr a_mpq,long long int a_value);
  static void mpq_add_lli(mpq_ptr a_res,mpq_srcptr a_mpq,long long int a_value);
  static void mpq_sub_lli(mpq_ptr a_res,mpq_srcptr a_mpq,long long int a_value);
  static void mpq_mul_lli(mpq_ptr a_res,mpq_srcptr a_mpq,long long int a_value);
  static void mpq_mul_z(mpq_ptr a_res,mpq_srcptr a_mpq,mpz_srcptr a_mpz);

  static int mpfr_cmp_lli(mpfr_ptr a_mpfr,long long int a_value);
  static void mpfr_add_lli(mpfr_ptr a_res,mpfr_srcptr a_mpfr,long long int a_value,mpfr_rnd_t a_rnd);
  static void mpfr_sub_lli(mpfr_ptr a_res,mpfr_srcptr a_mpfr,long long int a_value,mpfr_rnd_t a_rnd);
  static void mpfr_mul_lli(mpfr_ptr a_res,mpfr_srcptr a_mpfr,long long int a_value,mpfr_rnd_t a_rnd);
  static void mpfr_div_lli(mpfr_ptr a_res,mpfr_srcptr a_mpfr,long long int a_value,mpfr_rnd_t a_rnd);
  static void mpfr_pow_lli(mpfr_ptr a_res,mpfr_srcptr a_mpfr,long long int a_value,mpfr_rnd_t a_rnd);
};

/*
 * inline methods of class gmp_c
 */

inline gmp_c::gmp_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"gmp_init()\n"););

  // - set default precision -
  mpfr_set_default_prec(256);
}/*}}}*/

inline gmp_c::~gmp_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"gmp_exit()\n"););
}/*}}}*/

#endif

