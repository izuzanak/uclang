
#ifndef __UCL_GA_H
#define __UCL_GA_H

@begin
include "script_parser.h"
@end

#include <ga/ga.h>
#include <ga/GARealGenome.h>

// - GA indexes of built in classes -
extern unsigned c_bi_class_ga_real_genome;
extern unsigned c_bi_class_ga_tmp_real_genome;

// - external error identifiers -
extern unsigned c_ext_error_GA_GENOME_OBJECTIVE_WRONG_RETURN_VALUE;

/*
 * definition of structure ga_real_genome_s
 */

struct ga_real_genome_s
{
  interpreter_thread_s *it_ptr;
  unsigned source_pos;
  unsigned ret_code;

  GARealGenome *genome;
  location_s *objective_dlg;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure ga_s
 */
class ga_s
{
  public:
  static float objective_real(GAGenome& genome);
};

/*
 * inline methods of structure ga_real_genome_s
 */

inline void ga_real_genome_s::init()
{/*{{{*/
  it_ptr = NULL;
  source_pos = 0;
  ret_code = c_run_return_code_OK;

  genome = NULL;
  objective_dlg = NULL;
}/*}}}*/

inline void ga_real_genome_s::clear(interpreter_thread_s &it)
{/*{{{*/
 
  // - release objective delegate -
  if (objective_dlg != NULL)
  {
    it.release_location_ptr(objective_dlg);
  }

  // - release genome -
  if (genome != NULL)
  {
    delete genome;
  }

  init();
}/*}}}*/

#endif

