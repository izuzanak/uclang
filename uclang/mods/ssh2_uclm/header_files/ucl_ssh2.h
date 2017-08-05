
#ifndef __UCL_SSH2_H
#define __UCL_SSH2_H

@begin
include "script_parser.h"
@end

#include "libssh2.h"
#include "libssh2_sftp.h"

// - hostkey hash sizes -
enum
{
  HOSTKEY_HASH_MD5_SIZE = 16,
  HOSTKEY_HASH_SHA1_SIZE = 20,
};

// - ssh2 session states -
enum
{
  SSH2_SESSION_STATE_DISCONNECTED = 0,
  SSH2_SESSION_STATE_CONNECTED,
  SSH2_SESSION_STATE_HANDSHAKED,
  SSH2_SESSION_STATE_AUTHENTICATED,
};

/*
 * definition of structure ssh2_session_s
 */

struct ssh2_session_s
{
  LIBSSH2_SESSION *session;
  location_s *sock_ptr;
  unsigned state;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure sftp_session_s
 */

struct sftp_session_s
{
  LIBSSH2_SFTP *session;
  location_s *ssh2s_ptr;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure sftp_handle_s
 */

struct sftp_handle_s
{
  LIBSSH2_SFTP_HANDLE *handle;
  location_s *sftps_ptr;

  const static unsigned c_buff_size = 32768;
  unsigned buff_idx;
  bc_array_s buffer;

  inline void init();
  inline void clear(interpreter_thread_s &it);

  inline ssize_t buff_read(bc_array_s &a_target,size_t a_count);
};

/*
 * definition of structure ssh2_channel_s
 */

struct ssh2_channel_s
{
  LIBSSH2_CHANNEL *channel;
  location_s *ssh2s_ptr;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of class ssh2_c
 */
class ssh2_c
{
  private:
  static mutex_s fake_kbd_mutex;
  static unsigned pass_length;
  static char *pass;

  public:
  inline ssh2_c();
  inline ~ssh2_c();

  /*
   * callback from ssh2 library, requesting read of user password from keyboard
   */
  static void fake_kbd_callback(const char *name,int name_len,const char
      *instruction,int instruction_len,int num_prompts,const
      LIBSSH2_USERAUTH_KBDINT_PROMPT *prompts,LIBSSH2_USERAUTH_KBDINT_RESPONSE
      *responses,void **abstract);

  /*
   * fake interactive keyboard authentication
   */
  static int userauth_fake_kbd(ssh2_session_s &ssh2s,string_s &a_user,string_s &a_pass);
};

/*
 * inline methods of structure ssh2_session_s
 */

inline void ssh2_session_s::init()
{/*{{{*/
  session = nullptr;
  sock_ptr = nullptr;
  state = SSH2_SESSION_STATE_DISCONNECTED;
}/*}}}*/

inline void ssh2_session_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (session != nullptr)
  {
    libssh2_session_disconnect(session,"Connection shutdown");
    libssh2_session_free(session);
  }

  if (sock_ptr != nullptr)
  {
    it.release_location_ptr(sock_ptr);
  }

  state = SSH2_SESSION_STATE_DISCONNECTED;

  init();
}/*}}}*/

/*
 * inline methods of structure sftp_session_s
 */

inline void sftp_session_s::init()
{/*{{{*/
  session = nullptr;
  ssh2s_ptr = nullptr;
}/*}}}*/

inline void sftp_session_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (session != nullptr)
  {
    libssh2_sftp_shutdown(session);
  }

  if (ssh2s_ptr != nullptr)
  {
    it.release_location_ptr(ssh2s_ptr);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure sftp_handle_s
 */

inline void sftp_handle_s::init()
{/*{{{*/
  handle = nullptr;
  sftps_ptr = nullptr;
  buff_idx = 0;
  buffer.init();
}/*}}}*/

inline void sftp_handle_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (handle != nullptr)
  {
    libssh2_sftp_close_handle(handle);
  }

  if (sftps_ptr != nullptr)
  {
    it.release_location_ptr(sftps_ptr);
  }

  buffer.clear();

  init();
}/*}}}*/

inline ssize_t sftp_handle_s::buff_read(bc_array_s &a_target,size_t a_count)
{/*{{{*/
  size_t to_read = a_count;
  do {

    // - if buffer is not empty -
    if (buff_idx < buffer.used)
    {
      size_t buff_byte_cnt = buffer.used - buff_idx;
      size_t from_buff_cnt = to_read < buff_byte_cnt ? to_read : buff_byte_cnt;

      a_target.append(from_buff_cnt,buffer.data + buff_idx);

      buff_idx += from_buff_cnt;
      to_read -= from_buff_cnt;
    }

    // - reset buffer if all bytes were read from it -
    if (buff_idx == buffer.used)
    {
      buff_idx = 0;
      buffer.used = 0;
    }

      // - all requested bytes were successfully readed -
    if (to_read == 0)
    {
      return a_count;
    }

    // - if count of bytes to read is greater than buffer size -
    if (to_read >= c_buff_size)
    {
      a_target.reserve(to_read);
      ssize_t read_cnt = libssh2_sftp_read(handle,a_target.data + a_target.used,to_read);

      if (read_cnt < 0) { return read_cnt; }
      if (read_cnt == 0) { return a_count - to_read; }

      a_target.used += read_cnt;
      to_read -= read_cnt;

      // - all requested bytes were successfully readed -
      if (to_read == 0)
      {
        return a_count;
      }
    }

    // - if count of bytes to read is less than buffer size -
    else
    {
      buffer.copy_resize(c_buff_size);
      ssize_t read_cnt = libssh2_sftp_read(handle,buffer.data,c_buff_size);

      if (read_cnt < 0) { return read_cnt; }
      if (read_cnt == 0) { return a_count - to_read; }

      buffer.used += read_cnt;
    }

  } while(true);
}/*}}}*/

/*
 * inline methods of structure ssh2_channel_s
 */

inline void ssh2_channel_s::init()
{/*{{{*/
  channel = nullptr;
  ssh2s_ptr = nullptr;
}/*}}}*/

inline void ssh2_channel_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (channel != nullptr)
  {
    libssh2_channel_close(channel);
    libssh2_channel_free(channel);
  }

  if (ssh2s_ptr != nullptr)
  {
    it.release_location_ptr(ssh2s_ptr);
  }

  init();
}/*}}}*/

/*
 * inline methods of class ssh2_c
 */

inline ssh2_c::ssh2_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"libssh2_init()\n"););

  fake_kbd_mutex.init();
  cassert(libssh2_init(0) == 0);
}/*}}}*/

inline ssh2_c::~ssh2_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"libssh2_exit()\n"););

  fake_kbd_mutex.clear();
  libssh2_exit();
}/*}}}*/

#endif

