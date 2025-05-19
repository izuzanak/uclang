
@begin
include "ucl_ledmat.h"
@end

/*
 * methods of structure ledmat_s
 */

bool ledmat_s::spi_setup(int a_channel,int a_speed)
{/*{{{*/
#if defined(ENABLE_SPI_PI)
  fd = wiringPiSPISetup(a_channel,a_speed);
  return fd != -1;
#elif defined(ENABLE_SPI_UDP)

  // - fill target address structure -
  target_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  target_addr.sin_port = htons(5500 + a_channel);
  target_addr.sin_family = AF_INET;

  // - create socket -
  sock = socket(AF_INET,SOCK_DGRAM,0);
  if (sock == -1)
  {
    return false;
  }

  // - fill address structure -
  sockaddr_in addr;
  target_addr.sin_addr.s_addr = inet_addr("0.0.0.0");
  addr.sin_port = htons(0);
  addr.sin_family = AF_INET;

  // - ERROR -
  if (bind(sock,(sockaddr *)&addr,sizeof(sockaddr_in)) != 0)
  {
    close(sock);

    return false;
  }

  return true;
#else
  fprintf(stderr,"wiringPiSPISetup(%d,%d)\n",a_channel,a_speed);
  return true;
#endif
}/*}}}*/

/*
 * methods of structure ledmat_buffer_s
 */

