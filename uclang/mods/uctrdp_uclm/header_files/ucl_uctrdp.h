
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
  location_s *evt_snd_dlg;
  location_s *evt_rcv_dlg;
  TRDP::MD::Gate gate;
  int gate_id;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure trdp_md_address_s
 */

struct trdp_md_address_s
{
  location_s *dst_user_loc;
  TRDP::IPx dst_host;
  location_s *src_user_loc;
  TRDP::IPx src_host;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure trdp_md_message_s
 */

struct trdp_md_message_s
{
  TRDP::MD::Message message;
  location_s *data_location;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure trdp_md_call_s
 */

struct trdp_md_call_s
{
  location_s *gate_location;
  TRDP::Handle handle;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure trdp_md_listener_s
 */

struct trdp_md_listener_s
{
  TRDP::MD::Listener listener;
  location_s *gate_location;
  TRDP::Handle handle;

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
  evt_snd_dlg = nullptr;
  evt_rcv_dlg = nullptr;
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

  // - release event send delegate -
  if (evt_snd_dlg != nullptr)
  {
    it.release_location_ptr(evt_snd_dlg);
  }

  // - release event receive delegate -
  if (evt_rcv_dlg != nullptr)
  {
    it.release_location_ptr(evt_rcv_dlg);
  }

  // - release md location -
  if (md_location != nullptr)
  {
    it.release_location_ptr(md_location);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure trdp_md_address_s
 */

inline void trdp_md_address_s::init()
{/*{{{*/
  dst_user_loc = nullptr;
  src_user_loc = nullptr;
}/*}}}*/

inline void trdp_md_address_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release dst_user location -
  if (dst_user_loc != nullptr)
  {
    it.release_location_ptr(dst_user_loc);
  }

  // - release src_user location -
  if (src_user_loc != nullptr)
  {
    it.release_location_ptr(src_user_loc);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure trdp_md_message_s
 */

inline void trdp_md_message_s::init()
{/*{{{*/
  data_location = nullptr;
}/*}}}*/

inline void trdp_md_message_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release data location -
  if (data_location != nullptr)
  {
    it.release_location_ptr(data_location);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure trdp_md_call_s
 */

inline void trdp_md_call_s::init()
{/*{{{*/
  gate_location = nullptr;
  handle = TRDP::TRDP_NULL_HANDLE;
}/*}}}*/

inline void trdp_md_call_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release gate location -
  if (gate_location != nullptr)
  {
    it.release_location_ptr(gate_location);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure trdp_md_listener_s
 */

inline void trdp_md_listener_s::init()
{/*{{{*/
  gate_location = nullptr;
  handle = TRDP::TRDP_NULL_HANDLE;
}/*}}}*/

inline void trdp_md_listener_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - unregister listener - 
  trdp_md_gate_s *tmg_ptr = (trdp_md_gate_s *)gate_location->v_data_ptr;
  ((TRDP::MD *)tmg_ptr->md_location->v_data_ptr)->Cancel(handle);

  // - release gate location -
  if (gate_location != nullptr)
  {
    it.release_location_ptr(gate_location);
  }

  init();
}/*}}}*/

#endif

