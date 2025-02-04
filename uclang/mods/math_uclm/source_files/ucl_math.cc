
@begin
include "ucl_math.h"
@end

/*
 * methods of generated structures
 */

// -- bb_array_s --
@begin
methods bb_array_s
@end

// -- primes_s --
@begin
methods primes_s
@end

void primes_s::create_sieve(unsigned a_size)
{/*{{{*/
  clear();

  unsigned half_size = a_size >> 1;
  unsigned sqrt_size = sqrt(a_size);

  sieve.copy_resize(half_size);
  sieve.fill(true);

  unsigned i = 3;
  while (i <= sqrt_size)
  {
    if (sieve[i >> 1])
    {
      unsigned ii = (i*i) >> 1;
      do
      {
        sieve[ii] = false;
      }
      while((ii += i) < half_size);
    }

    i += 2;
  }
}/*}}}*/

unsigned primes_s::next_idx(unsigned a_idx)
{/*{{{*/
  unsigned idx = a_idx;

  if (idx >= sieve.used)
  {
    return c_idx_not_exist;
  }

  do
  {
    if (++idx >= sieve.used)
    {
      return c_idx_not_exist;
    }
  }
  while(!sieve[idx]);

  return idx;
}/*}}}*/

unsigned primes_s::get_prime(unsigned a_idx)
{/*{{{*/
  if (a_idx >= sieve.used)
  {
    return c_idx_not_exist;
  }

  if (a_idx == 0)
  {
    return 2;
  }

  if (sieve[a_idx])
  {
    return (2*a_idx) + 1;
  }

  return c_idx_not_exist;
}/*}}}*/

