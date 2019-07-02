
#ifndef __UCL_FANN_H
#define __UCL_FANN_H

@begin
include "script_parser.h"
@end

#include <doublefann.h>

/*
 * definition of class fann_c
 */

class fann_c
{
  public:
  static mutex_s train_data_cb_mutex;
  static pointer_array_s *train_data_array;

  static void train_data_cb(unsigned num_data,unsigned num_input,unsigned num_output,double *input,double *output);

  inline fann_c();
  inline ~fann_c();
};

/*
 * inline methods of class fann_c
 */

inline fann_c::fann_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"libfann_init()\n"););

  train_data_cb_mutex.init();
}/*}}}*/

inline fann_c::~fann_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"libfann_exit()\n"););

  train_data_cb_mutex.clear();
}/*}}}*/

#endif

