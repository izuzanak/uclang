
#ifndef __UCL_MATH_H
#define __UCL_MATH_H

@begin
include "script_parser.h"
@end

#define GLM_FORCE_RADIANS

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

/*
 * definition of generated structures
 */

// -- bb_array_s --
@begin
array<bool> bb_array_s;
@end

// -- primes_s --
@begin
struct
    <
    bb_array_s:sieve
    >

    additions
{
  void create_sieve(unsigned a_size);
  unsigned next_idx(unsigned a_idx);
  unsigned get_prime(unsigned a_idx);
}

primes_s;
@end

/*
 * inline methods of generated structures
 */

// -- bb_array_s --
@begin
inlines bb_array_s
@end

// -- primes_s --
@begin
inlines primes_s
@end

#endif

