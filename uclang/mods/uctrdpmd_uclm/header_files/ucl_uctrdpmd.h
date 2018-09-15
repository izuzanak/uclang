
#ifndef __UCL_UCTRDPMD_H
#define __UCL_UCTRDPMD_H

@begin
include "script_parser.h"
@end

#include "ucf2.h"

using namespace Ucf2;

#include <uctrdp.h>

/*
 * definition of generated structures
 */

// -- handle_data_s --
@begin
struct
<
unsigned:handle
pointer:user_data_loc
>
handle_data_s;
@end

// -- handle_data_rb_tree_s --
@begin
safe_rb_tree<handle_data_s> handle_data_rb_tree_s;
@end

/*
 * definition of class uctrdpmd_c
 */
class uctrdpmd_c
{
  private:
  static mutex_s gate_id_mutex;
  static bi_array_s free_gate_ids;
  static int next_gate_id;

  public:
  inline uctrdpmd_c();
  inline ~uctrdpmd_c();

  inline static int new_gate_id();
  inline static void free_gate_id(int a_id);
};

/*
 * definition of structure trdp_md_gate_s
 */

struct trdp_md_gate_s
{
  location_s *md_location;
  location_s *evt_send_dlg;
  location_s *evt_receive_dlg;
  handle_data_rb_tree_s handle_data;
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
  unsigned char scope;
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
  unsigned char scope;
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
  location_s *user_data_loc;
  location_s *gate_location;
  TRDP::Handle handle;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure trdp_md_event_s
 */

struct trdp_md_event_s
{
  TRDP::MD::Event event;
  location_s *gate_location;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of generated structures
 */

// -- handle_data_s --
@begin
inlines handle_data_s
@end

// -- handle_data_rb_tree_s --
@begin
inlines handle_data_rb_tree_s
@end

inline int handle_data_rb_tree_s::__compare_value(handle_data_s &a_first,handle_data_s &a_second)
{/*{{{*/
  return a_first.handle < a_second.handle ? -1 : a_first.handle > a_second.handle ? 1 : 0;
}/*}}}*/

/*
 * inline methods of class uctrdpmd_c
 */

inline uctrdpmd_c::uctrdpmd_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"libfann_init()\n"););

  gate_id_mutex.init();
  free_gate_ids.init();
  next_gate_id = 0;
}/*}}}*/

inline uctrdpmd_c::~uctrdpmd_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"libfann_exit()\n"););

  gate_id_mutex.clear();
  free_gate_ids.clear();
}/*}}}*/

inline int uctrdpmd_c::new_gate_id()
{/*{{{*/
  gate_id_mutex.lock();
  int gate_id = free_gate_ids.used != 0 ? free_gate_ids.pop() : next_gate_id++;
  gate_id_mutex.unlock();

  return gate_id;
}/*}}}*/

inline void uctrdpmd_c::free_gate_id(int a_id)
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
  evt_send_dlg = nullptr;
  evt_receive_dlg = nullptr;
  handle_data.init();
  gate_id = INT_MIN;
}/*}}}*/

inline void trdp_md_gate_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - close gate -
  if (gate_id != INT_MIN)
  {
    ((TRDP::MD *)md_location->v_data_ptr)->CloseGate(gate);
    uctrdpmd_c::free_gate_id(gate_id);
  }

  // - release event send delegate -
  if (evt_send_dlg != nullptr)
  {
    it.release_location_ptr(evt_send_dlg);
  }

  // - release event receive delegate -
  if (evt_receive_dlg != nullptr)
  {
    it.release_location_ptr(evt_receive_dlg);
  }

  // - release user data of all handles -
  if (handle_data.count != 0)
  {
    handle_data_rb_tree_s_node *hnd_ptr = handle_data.data;
    handle_data_rb_tree_s_node *hnd_ptr_end = hnd_ptr + handle_data.used;

    do {
      if (hnd_ptr->valid)
      {
        // - release user data location -
        it.release_location_ptr((location_s *)hnd_ptr->object.user_data_loc);
      }
    } while(++hnd_ptr < hnd_ptr_end);
  }

  handle_data.clear();

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
  user_data_loc = nullptr;
  gate_location = nullptr;
  handle = TRDP::TRDP_NULL_HANDLE;
}/*}}}*/

inline void trdp_md_listener_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release user data location -
  if (user_data_loc != nullptr)
  {
    it.release_location_ptr(user_data_loc);
  }

  if (gate_location != nullptr)
  {
    // - unregister listener -
    if (handle != TRDP::TRDP_NULL_HANDLE)
    {
      trdp_md_gate_s *tmg_ptr = (trdp_md_gate_s *)gate_location->v_data_ptr;
      ((TRDP::MD *)tmg_ptr->md_location->v_data_ptr)->Cancel(handle);
    }

    // - release gate location -
    it.release_location_ptr(gate_location);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure trdp_md_event_s
 */

inline void trdp_md_event_s::init()
{/*{{{*/
  gate_location = nullptr;
}/*}}}*/

inline void trdp_md_event_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (gate_location != nullptr)
  {
    trdp_md_gate_s *tmg_ptr = (trdp_md_gate_s *)gate_location->v_data_ptr;

    // - release handle user data -
    handle_data_s handle_data = {event.hmsg,nullptr};

    unsigned handle_data_idx = tmg_ptr->handle_data.get_idx(handle_data);
    if (handle_data_idx != c_idx_not_exist)
    {
      location_s *user_data_loc = (location_s *)tmg_ptr->handle_data[handle_data_idx].user_data_loc;
      tmg_ptr->handle_data.remove(handle_data_idx);

      // - release user data location -
      it.release_location_ptr(user_data_loc);
    }

    // - release message handle -
    tmg_ptr->gate.Release(event.hmsg);

    // - release gate location -
    it.release_location_ptr(gate_location);
  }

  init();
}/*}}}*/

#endif
