
#ifndef __UCL_FTP_H
#define __UCL_FTP_H

@begin
include "script_parser.h"
@end

#include "ftplib.h"

// - ftp session states -
enum
{
  FTP_SESSION_STATE_DISCONNECTED = 0,
  FTP_SESSION_STATE_CONNECTED,
  FTP_SESSION_STATE_AUTHENTICATED,
};

/*
 * definition of class ftp_init_c
 */
class ftp_init_c
{
  public:
  inline ftp_init_c()
  {
    debug_message_2(fprintf(stderr,"ftplib_init()\n"););

    // - initialize ftp library -
    FtpInit();
  }
  inline ~ftp_init_c()
  {
    debug_message_2(fprintf(stderr,"ftplib_exit()\n"););
  }
};

// - ftp global init object -
ftp_init_c ftp_init;

/*
 * definition of structure ftp_session_s
 */

struct ftp_session_s
{
  netbuf *nb_ptr;
  unsigned state;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure ftp_handle_s
 */

struct ftp_handle_s
{
  netbuf *nb_ptr;
  location_s *ftps_ptr;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure ftp_session_s
 */

inline void ftp_session_s::init()
{/*{{{*/
  nb_ptr = nullptr;
  state = FTP_SESSION_STATE_DISCONNECTED;
}/*}}}*/

inline void ftp_session_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (nb_ptr != nullptr)
  {
    FtpQuit(nb_ptr);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure ftp_handle_s
 */

inline void ftp_handle_s::init()
{/*{{{*/
  nb_ptr = nullptr;
  ftps_ptr = nullptr;
}/*}}}*/

inline void ftp_handle_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (nb_ptr != nullptr)
  {
    FtpClose(nb_ptr);
  }

  if (ftps_ptr != nullptr)
  {
    it.release_location_ptr(ftps_ptr);
  }

  init();
}/*}}}*/

#endif

