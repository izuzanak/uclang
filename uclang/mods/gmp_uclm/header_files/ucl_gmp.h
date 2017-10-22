
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

  static void mpfr_setf(string_s &a_target,const char *a_format,...);

  static void mpz_set_lli(mpz_t &a_mpz,long long int a_value);
  static void mpz_add_lli(mpz_t &a_res,mpz_t &a_mpz,long long int a_value);
  static void mpz_sub_lli(mpz_t &a_res,mpz_t &a_mpz,long long int a_value);
  static void mpz_mul_lli(mpz_t &a_res,mpz_t &a_mpz,long long int a_value);
  static void mpz_div_lli(mpz_t &a_res,mpz_t &a_mpz,long long int a_value);

  static void mpq_set_lli(mpq_t &a_mpq,long long int a_value);
  static void mpq_set_lli_lli(mpq_t &a_mpq,long long int a_value,long long int a_denom);
};

/*
 * inline methods of class gmp_c
 */

inline gmp_c::gmp_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"gmp_init()\n"););
}/*}}}*/

inline gmp_c::~gmp_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"gmp_exit()\n"););
}/*}}}*/

#endif

