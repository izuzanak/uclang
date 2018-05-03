
#ifndef __UCL_UCTRDP_H
#define __UCL_UCTRDP_H

@begin
include "script_parser.h"
@end

#include "ucf2.h"

using namespace Ucf2;

#include <uctrdp.h>

/*
 * definition of class uctrdp_c
 */
class uctrdp_c
{
  private:
  static mutex_s gate_id_mutex;
  static bi_array_s free_gate_ids;
  static int next_gate_id;

  public:
  inline uctrdp_c();
  inline ~uctrdp_c();

  inline static int new_gate_id();
  inline static void free_gate_id(int a_id);
};

/*
 * definition of structure trdp_md_gate_s
 */

struct trdp_md_gate_s
{
  location_s *md_location;
  TRDP::MD::Gate gate;
  int gate_id;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of class uctrdp_c
 */

inline uctrdp_c::uctrdp_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"libfann_init()\n"););

  gate_id_mutex.init();
  free_gate_ids.init();
  next_gate_id = 0;
}/*}}}*/

inline uctrdp_c::~uctrdp_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"libfann_exit()\n"););

  gate_id_mutex.clear();
  free_gate_ids.clear();
}/*}}}*/

inline int uctrdp_c::new_gate_id()
{/*{{{*/
  gate_id_mutex.lock();
  int gate_id = free_gate_ids.used != 0 ? free_gate_ids.pop() : next_gate_id++;
  gate_id_mutex.unlock();

  return gate_id;
}/*}}}*/

inline void uctrdp_c::free_gate_id(int a_id)
{/*{{{*/
  gate_id_mutex.lock();
  free_gate_ids.push(a_id);
  gate_id_mutex.unlock();
}/*}}}*/

/*
 * inline methods of structure trdp_md_gate_s
 */

inline void trdp_md_gate_s::init()
{/*{{{*/
  md_location = nullptr;
  gate_id = INT_MIN;
}/*}}}*/

inline void trdp_md_gate_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - close gate -
  if (gate_id != INT_MIN)
  {
    ((TRDP::MD *)md_location->v_data_ptr)->CloseGate(gate);
    uctrdp_c::free_gate_id(gate_id);
  }

  // - release md location -
  if (md_location != nullptr)
  {
    it.release_location_ptr(md_location);
  }

  init();
}/*}}}*/

#endif

