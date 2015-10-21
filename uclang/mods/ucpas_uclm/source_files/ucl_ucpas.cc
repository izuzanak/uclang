
@begin
include "ucl_ucpas.h"
@end

/*
 * basic definitions and constants
 */

const unsigned short c_two_bytes = 0xff00;
const bool c_little_endian = ((unsigned char *)&c_two_bytes)[1] == 0xff;

/*
 * static members of structure pas_s
 */

unsigned pas_s::lib_status = PAS_STATUS_CLOSED;

mutex_s pas_s::mutex;
u32_t pas_s::master_ip;
pas_device_s pas_s::device;
si_queue_s pas_s::sample_queue;
unsigned pas_s::audio_section;
unsigned pas_s::priority;
unsigned pas_s::volume;
bool pas_s::paused;

/*
 * methods of generated structures
 */

// -- si_queue_s --
@begin
   methods si_queue_s
@end

/*
 * methods of structure pas_s
 */

fn_t pas_s::callback(u32_t event,u16_t type,void *data,u32_t data_size)
{/*{{{*/
  fn_t ret_val = SUCCESS;

  // - lock pas data mutex -
  pas_s::mutex.lock();

  switch (event)
  {
  case PAS_EVT_IDENTIFY:
    {
      // - update device status -
      ret_val = pas_update_status(device.uid,device.vid,device.fail_code,device.status,&device.ident);
    }
    break;

  case PAS_EVT_CHANGEMASTER:
    {
      // - retrieve master rux ip address -
      master_ip = pas_getmasterip();
    }
    break;

  case PAS_EVT_TRANSMIT_AUDIO:
    {
      static short samples[PAS_SAMPLES];

      // - if there are samples to be played -
      if (pas_s::sample_queue.used > 0)
      {
        // - if playback is paused -
        if (pas_s::paused)
        {
          // - send empty set of samples -
          ret_val = pas_sendaudio(PKT_TYPE_XPDO_AUDIO_A,PKT_STATUS_ANNOUNCE,audio_section,priority,NULL,0);
        }
        else
        {
          // - retrieve samples from queue -
          short *s_ptr = samples;
          short *s_ptr_end = samples + PAS_SAMPLES;
          do {
            *s_ptr++ = pas_s::sample_queue.next();
          } while(s_ptr < s_ptr_end && pas_s::sample_queue.used > 0);

          // - erase rest of sample data -
          if (s_ptr < s_ptr_end)
          {
            memset(s_ptr,0,(s_ptr_end - s_ptr_end)*sizeof(short));
          }

          // - send samples to be played -
          ret_val = pas_sendaudio(PKT_TYPE_XPDO_AUDIO_A,PKT_STATUS_ANNOUNCE,audio_section,priority,samples,PAS_SAMPLES);
        }
      }
    }
    break;
  }

  // - unlock pas data mutex -
  pas_s::mutex.unlock();

  return ret_val;
}/*}}}*/

