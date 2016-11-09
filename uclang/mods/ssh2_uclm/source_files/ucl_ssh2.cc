
@begin
include "ucl_ssh2.h"
@end

// - ssh2 global init object -
ssh2_c g_ssh2;

/*
 * static members of class ssh2_c
 */

mutex_s ssh2_c::fake_kbd_mutex;
unsigned ssh2_c::pass_length;
char *ssh2_c::pass;

/*
 * methods of class ssh2_c
 */

void ssh2_c::fake_kbd_callback(const char *name,int name_len,const char
    *instruction,int instruction_len,int num_prompts,const
    LIBSSH2_USERAUTH_KBDINT_PROMPT *prompts,LIBSSH2_USERAUTH_KBDINT_RESPONSE
    *responses,void **abstract)
{/*{{{*/

  if (num_prompts > 0)
  {
    int idx = 0;
    do
    {
      char *pass_copy = (char *)cmalloc(pass_length + 1);
      memcpy(pass_copy,pass,pass_length + 1);

      responses[idx].text = pass_copy;
      responses[idx].length = pass_length;
    }
    while(++idx < num_prompts);
  }
}/*}}}*/

int ssh2_c::userauth_fake_kbd(ssh2_session_s &ssh2s,string_s &a_user,string_s &a_pass)
{/*{{{*/

  fake_kbd_mutex.lock();

  pass_length = a_pass.size - 1;
  pass = a_pass.data;

  int result = libssh2_userauth_keyboard_interactive_ex(ssh2s.session,a_user.data,a_user.size - 1,fake_kbd_callback);

  fake_kbd_mutex.unlock();

  return result;
}/*}}}*/

