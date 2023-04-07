
#ifndef __UCL_LEDMAT_H
#define __UCL_LEDMAT_H

@begin
include "script_parser.h"
@end

//#define ENABLE_SPI_PI
#define ENABLE_SPI_UDP

#if defined(ENABLE_SPI_PI)
#include <wiringPiSPI.h>
#elif defined(ENABLE_SPI_UDP)
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#endif

// - spi commands -
enum {
  c_spi_cmd_buffer_load = 0x01,
  c_spi_cmd_buffer_swap = 0x02,
  c_spi_cmd_brightness  = 0x03,
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
#if defined(ENABLE_SPI_PI)
  int fd;
#elif defined(ENABLE_SPI_UDP)
  int sock;
  sockaddr_in target_addr;
#endif
  uc *data;

  bool spi_setup(int a_channel,int a_speed);
  inline int spi_write(uc * a_data,int a_size);

  inline void init();
  inline void clear(interpreter_thread_s &it);
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
 * inline methods of structure ledmat_s
 */

inline int ledmat_s::spi_write(uc * a_data,int a_size)
{/*{{{*/
#if defined(ENABLE_SPI_PI)
  wiringPiSPIDataRW(channel,a_data,a_size);
  return a_size;
#elif defined(ENABLE_SPI_UDP)
  long int cnt = sendto(sock,a_data,a_size,0,(sockaddr *)&target_addr,sizeof(sockaddr_in));
  return cnt;
#else
  fprintf(stderr,"wiringPiSPIDataRW(%d,%p,%d)\n",channel,a_data,a_size);
  return a_size;
#endif
}/*}}}*/

inline void ledmat_s::init()
{/*{{{*/
#if defined(ENABLE_SPI_PI)
  fd = -1;
#elif defined(ENABLE_SPI_UDP)
  sock = -1;
#endif
  data = nullptr;
}/*}}}*/

inline void ledmat_s::clear(interpreter_thread_s &it)
{/*{{{*/
#if defined(ENABLE_SPI_PI)
  if (fd != -1)
  {
    close(fd);
  }
#elif defined(ENABLE_SPI_UDP)
  if (sock != -1)
  {
    close(sock);
  }
#endif

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

