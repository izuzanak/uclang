
@begin
include "spawner.h"
include "spawn_parse_actions.h"
@end

/*
 * constants and definitions
 */

// - callers of parse action functions -
const unsigned c_spawn_parse_action_cnt = 22;
bool(*spawn_pa_callers[c_spawn_parse_action_cnt])(spawn_parser_s &_this) =
{/*{{{*/
  pa_spawn_null,

  pa_spawn_null,
  pa_spawn_null,

  pa_spawn_redirect_from_fd,
  pa_spawn_redirect_to_fd,

  pa_spawn_redirect_from_file,
  pa_spawn_redirect_to_file,

  pa_spawn_append_to_file,
  pa_spawn_redirect_all_to_file,
  pa_spawn_append_all_to_file,

  pa_spawn_argument,

  pa_spawn_fd,
  pa_spawn_fd,
  pa_spawn_fd,

  pa_spawn_fd_stdin,
  pa_spawn_fd_stdout,
  pa_spawn_fd_stdout,

  pa_spawn_null,
  pa_spawn_null,
  pa_spawn_null,
  pa_spawn_null,

  pa_spawn_null,
};/*}}}*/

/*
 * parse action macros
 */

/*
 * functions implementing parse actions of spawn parser
 */

bool pa_spawn_null(spawn_parser_s &_this)
{/*{{{*/
  debug_message_0(fprintf(stderr,"spawn_parser: parse_action: pa_spawn_null\n"));

  return true;
}/*}}}*/

bool pa_spawn_redirect_from_fd(spawn_parser_s &_this)
{/*{{{*/
  string_s &source_string = _this.source_string;
  bi_array_s &fd_stack = _this.fd_stack;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();

  char *fd_data = source_string.data + lse.terminal_start;
  long long int fd = strtoll(fd_data,NULL,10);

  // - ERROR -
  if (dup2(fd,fd_stack.pop()) == -1)
  {
    return false;
  }

  debug_message_0(
    char *end_ptr = source_string.data + lse.terminal_end;
    char tmp_char = *end_ptr;
    *end_ptr = '\0';
    fprintf(stderr,"spawn_parser: parse_action: pa_spawn_redirect_from_fd: %s\n",source_string.data + lse.terminal_start);
    *end_ptr = tmp_char;
  );

  return true;
}/*}}}*/

bool pa_spawn_redirect_to_fd(spawn_parser_s &_this)
{/*{{{*/
  string_s &source_string = _this.source_string;
  bi_array_s &fd_stack = _this.fd_stack;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();

  char *fd_data = source_string.data + lse.terminal_start;
  long long int fd = strtoll(fd_data,NULL,10);

  // - ERROR -
  if (dup2(fd,fd_stack.pop()) == -1)
  {
    return false;
  }

  debug_message_0(
    char *end_ptr = source_string.data + lse.terminal_end;
    char tmp_char = *end_ptr;
    *end_ptr = '\0';
    fprintf(stderr,"spawn_parser: parse_action: pa_spawn_redirect_to_fd: %s\n",source_string.data + lse.terminal_start);
    *end_ptr = tmp_char;
  );

  return true;
}/*}}}*/

bool pa_spawn_redirect_from_file(spawn_parser_s &_this)
{/*{{{*/
  string_s &source_string = _this.source_string;
  bi_array_s &fd_stack = _this.fd_stack;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();

  int fd = spawn_parser_s::open_file(
      source_string.data + lse.terminal_start,
      source_string.data + lse.terminal_end,
      O_RDONLY);

  // - ERROR -
  if (fd == -1)
    return false;

  // - ERROR -
  if (dup2(fd,fd_stack.pop()) == -1)
  {
    close(fd);

    return false;
  }

  // - ERROR -
  if (close(fd) == -1)
    return false;

  debug_message_0(
    char *end_ptr = source_string.data + lse.terminal_end;
    char tmp_char = *end_ptr;
    *end_ptr = '\0';
    fprintf(stderr,"spawn_parser: parse_action: pa_spawn_redirect_from_file: %s\n",source_string.data + lse.terminal_start);
    *end_ptr = tmp_char;
  );

  return true;
}/*}}}*/

bool pa_spawn_redirect_to_file(spawn_parser_s &_this)
{/*{{{*/
  string_s &source_string = _this.source_string;
  bi_array_s &fd_stack = _this.fd_stack;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();

  int fd = spawn_parser_s::open_file(
      source_string.data + lse.terminal_start,
      source_string.data + lse.terminal_end,
      O_CREAT | O_WRONLY | O_TRUNC);

  // - ERROR -
  if (fd == -1)
    return false;

  // - ERROR -
  if (dup2(fd,fd_stack.pop()) == -1)
  {
    close(fd);

    return false;
  }

  // - ERROR -
  if (close(fd) == -1)
    return false;

  debug_message_0(
    char *end_ptr = source_string.data + lse.terminal_end;
    char tmp_char = *end_ptr;
    *end_ptr = '\0';
    fprintf(stderr,"spawn_parser: parse_action: pa_spawn_redirect_to_file: %s\n",source_string.data + lse.terminal_start);
    *end_ptr = tmp_char;
  );

  return true;
}/*}}}*/

bool pa_spawn_append_to_file(spawn_parser_s &_this)
{/*{{{*/
  string_s &source_string = _this.source_string;
  bi_array_s &fd_stack = _this.fd_stack;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();

  int fd = spawn_parser_s::open_file(
      source_string.data + lse.terminal_start,
      source_string.data + lse.terminal_end,
      O_CREAT | O_WRONLY | O_APPEND);

  // - ERROR -
  if (fd == -1)
    return false;

  // - ERROR -
  if (dup2(fd,fd_stack.pop()) == -1)
  {
    close(fd);

    return false;
  }

  // - ERROR -
  if (close(fd) == -1)
    return false;

  debug_message_0(
    char *end_ptr = source_string.data + lse.terminal_end;
    char tmp_char = *end_ptr;
    *end_ptr = '\0';
    fprintf(stderr,"spawn_parser: parse_action: pa_spawn_append_to_file: %s\n",source_string.data + lse.terminal_start);
    *end_ptr = tmp_char;
  );

  return true;
}/*}}}*/

bool pa_spawn_redirect_all_to_file(spawn_parser_s &_this)
{/*{{{*/
  string_s &source_string = _this.source_string;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();

  int fd = spawn_parser_s::open_file(
      source_string.data + lse.terminal_start,
      source_string.data + lse.terminal_end,
      O_CREAT | O_WRONLY | O_TRUNC);

  // - ERROR -
  if (fd == -1)
    return false;

  // - ERROR -
  if (dup2(fd,STDOUT_FILENO) == -1 ||
      dup2(fd,STDERR_FILENO) == -1)
  {
    close(fd);

    return false;
  }

  // - ERROR -
  if (close(fd) == -1)
    return false;

  debug_message_0(
    char *end_ptr = source_string.data + lse.terminal_end;
    char tmp_char = *end_ptr;
    *end_ptr = '\0';
    fprintf(stderr,"spawn_parser: parse_action: pa_spawn_redirect_all_to_file: %s\n",source_string.data + lse.terminal_start);
    *end_ptr = tmp_char;
  );

  return true;
}/*}}}*/

bool pa_spawn_append_all_to_file(spawn_parser_s &_this)
{/*{{{*/
  string_s &source_string = _this.source_string;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();

  int fd = spawn_parser_s::open_file(
      source_string.data + lse.terminal_start,
      source_string.data + lse.terminal_end,
      O_CREAT | O_WRONLY | O_APPEND);

  // - ERROR -
  if (fd == -1)
    return false;

  // - ERROR -
  if (dup2(fd,STDOUT_FILENO) == -1 ||
      dup2(fd,STDERR_FILENO) == -1)
  {
    close(fd);

    return false;
  }

  // - ERROR -
  if (close(fd) == -1)
    return false;

  debug_message_0(
    char *end_ptr = source_string.data + lse.terminal_end;
    char tmp_char = *end_ptr;
    *end_ptr = '\0';
    fprintf(stderr,"spawn_parser: parse_action: pa_spawn_append_all_to_file: %s\n",source_string.data + lse.terminal_start);
    *end_ptr = tmp_char;
  );

  return true;
}/*}}}*/

bool pa_spawn_argument(spawn_parser_s &_this)
{/*{{{*/
  string_s &source_string = _this.source_string;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();

  // FIXME TODO continue (remove enclosing ' or ")

  debug_message_0(
    char *end_ptr = source_string.data + lse.terminal_end;
    char tmp_char = *end_ptr;
    *end_ptr = '\0';
    fprintf(stderr,"spawn_parser: parse_action: pa_spawn_argument: %s\n",source_string.data + lse.terminal_start);
    *end_ptr = tmp_char;
  );

  return true;
}/*}}}*/

bool pa_spawn_fd(spawn_parser_s &_this)
{/*{{{*/
  string_s &source_string = _this.source_string;
  bi_array_s &fd_stack = _this.fd_stack;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();

  char *fd_data = source_string.data + lse.terminal_start;
  long long int fd = strtoll(fd_data,NULL,10);

  fd_stack.push(fd);

  debug_message_0(
    char *end_ptr = source_string.data + lse.terminal_end;
    char tmp_char = *end_ptr;
    *end_ptr = '\0';
    fprintf(stderr,"spawn_parser: parse_action: pa_spawn_fd: %s\n",source_string.data + lse.terminal_start);
    *end_ptr = tmp_char;
  );

  return true;
}/*}}}*/

bool pa_spawn_fd_stdin(spawn_parser_s &_this)
{/*{{{*/
  bi_array_s &fd_stack = _this.fd_stack;

  // *****

  fd_stack.push(STDIN_FILENO);

  debug_message_0(fprintf(stderr,"spawn_parser: parse_action: pa_spawn_fd_stdin\n"));

  return true;
}/*}}}*/

bool pa_spawn_fd_stdout(spawn_parser_s &_this)
{/*{{{*/
  bi_array_s &fd_stack = _this.fd_stack;

  // *****

  fd_stack.push(STDOUT_FILENO);

  debug_message_0(fprintf(stderr,"spawn_parser: parse_action: pa_spawn_fd_stdout\n"));

  return true;
}/*}}}*/

