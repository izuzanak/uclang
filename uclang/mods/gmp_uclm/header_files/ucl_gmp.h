
#ifndef __UCL_GMP_H
#define __UCL_GMP_H

@begin
include "script_parser.h"
@end

#include <gmp.h>

/*
 * definition of class gmp_c
 */
class gmp_c
{
  public:
  inline gmp_c();
  inline ~gmp_c();

  static void setf(string_s &a_target,const char *a_format,...);
  static void mpz_set_lli(mpz_t &a_mpz,long long int a_value);
  static void mpq_set_lli(mpq_t &a_mpq,long long int a_value);
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

