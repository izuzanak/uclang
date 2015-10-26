
#ifndef __UCL_UCPAS_H
#define __UCL_UCPAS_H

@begin
include "script_parser.h"
@end

#ifdef __cplusplus
  extern "C" {
#endif

#include "pas.h"

#ifdef __cplusplus
  }
#endif

/*
 * basic definitions and constants
 */

extern const unsigned short c_two_bytes;
extern const bool c_little_endian;

enum
{
  PAS_STATUS_CLOSED = 0,
  PAS_STATUS_INITIALIZED
};

/*
 * definition of generated structures
 */

// -- si_queue_s --
@begin
   queue<si> si_queue_s;
@end

/*
 * definition of structure pas_device_s
 */

struct pas_device_s
{
  u64_t uid;
  u64_t vid;
  u8_t fail_code;
  u16_t status;
  struct pkt_ident_t ident;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure pas_s
 */

struct  pas_s
{
  public:
  static unsigned lib_status;

  static mutex_s mutex;
  static u32_t master_ip;
  static pas_device_s device;
  static si_queue_s sample_queue;
  static unsigned hold_delay;
  static unsigned hold_counter;
  static unsigned audio_section;
  static unsigned priority;
  static unsigned volume;
  static bool paused;

  static inline void init();
  static inline void clear(interpreter_thread_s &it);

  static fn_t callback(u32_t event,u16_t type,void *data,u32_t data_size);
};

/*
 * inline methods of generated structures
 */

// -- si_queue_s --
@begin
   inlines si_queue_s
@end

/*
 * inline methods of structure pas_device_s
 */

inline void pas_device_s::init()
{/*{{{*/
  uid       = 0;
  vid       = 0;
  fail_code = 0;
  status    = 0;

  memset(ident.version,0,PKT_VERSION_SIZE);
  ident.section     = 0;
  ident.iostatus    = 0;
  ident.evt         = 0;
  ident.errNIDuni   = 0;
  ident.errNIDmulti = 0;
  ident.devtype     = PKT_DEVTYPE_ANYCOMM;
  ident.maxvolume   = 0;
  ident.audiooutput = 0;
  ident.temp        = 0x80;
}/*}}}*/

inline void pas_device_s::clear(interpreter_thread_s &it)
{/*{{{*/
  init();
}/*}}}*/

/*
 * inline methods of structure pas_s
 */

inline void pas_s::init()
{/*{{{*/
  mutex.init();
  master_ip = 0;
  device.init();
  sample_queue.init();
  hold_delay = (1000*PAS_SAMPLES)/10;
  hold_counter = 0;
  audio_section = 0;
  priority = 0;
  volume = 50;
  paused = false;
}/*}}}*/

inline void pas_s::clear(interpreter_thread_s &it)
{/*{{{*/
  mutex.clear();
  device.clear(it);
  sample_queue.clear();

  init();
}/*}}}*/

#endif

