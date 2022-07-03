
#ifndef __UCL_LEDMAT_H
#define __UCL_LEDMAT_H

@begin
include "script_parser.h"
@end

#define ENABLE_WIRING_PI

#if defined(ENABLE_WIRING_PI)
#include <wiringPiSPI.h>
#else
inline int wiringPiSPISetup(int a_channel,int a_speed)
{
  fprintf(stderr,"wiringPiSPISetup(%d,%d)\n",a_channel,a_speed);
  return 1;
}

inline int wiringPiSPIDataRW(int a_channel,uc * a_data,int a_size)
{
  fprintf(stderr,"wiringPiSPIDataRW(%d,%p,%d)\n",a_channel,a_data,a_size);
  return a_size;
}
#endif

// - spi commands -
enum {
  c_spi_cmd_buffer_load = 0x01,
  c_spi_cmd_buffer_swap = 0x02,
  c_spi_cmd_brightness  = 0x03,
};

/*
 * definition of structure ledmat_buffer_s
 */

struct ledmat_buffer_s
{
  unsigned col_cnt;
  unsigned row_cnt;
  uc *data;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure ledmat_s
 */

struct ledmat_s
{
  unsigned channel;
  unsigned speed;
  unsigned col_cnt;
  unsigned row_cnt;
  int fd;
  uc *data;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure ledmat_s
 */

inline void ledmat_s::init()
{/*{{{*/
  fd = -1;
  data = nullptr;
}/*}}}*/

inline void ledmat_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (fd != -1)
  {
#if defined(ENABLE_WIRING_PI)
    close(fd);
#endif
  }

  if (data != nullptr)
  {
    cfree(data);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure ledmat_buffer_s
 */

inline void ledmat_buffer_s::init()
{/*{{{*/
  data = nullptr;
}/*}}}*/

inline void ledmat_buffer_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (data != nullptr)
  {
    cfree(data);
  }

  init();
}/*}}}*/

#endif

