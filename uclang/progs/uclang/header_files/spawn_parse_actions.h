
#ifndef __SPAWN_PARSE_ACTIONS_H
#define __SPAWN_PARSE_ACTIONS_H

/*
 * declaration of function describing parse actions
 */

bool pa_spawn_null(spawn_parser_s &_this);
bool pa_spawn_redirect_from_fd(spawn_parser_s &_this);
bool pa_spawn_redirect_to_fd(spawn_parser_s &_this);
bool pa_spawn_redirect_from_file(spawn_parser_s &_this);
bool pa_spawn_redirect_to_file(spawn_parser_s &_this);
bool pa_spawn_append_to_file(spawn_parser_s &_this);
bool pa_spawn_redirect_all_to_file(spawn_parser_s &_this);
bool pa_spawn_append_all_to_file(spawn_parser_s &_this);
bool pa_spawn_argument(spawn_parser_s &_this);
bool pa_spawn_fd(spawn_parser_s &_this);
bool pa_spawn_fd_stdin(spawn_parser_s &_this);
bool pa_spawn_fd_stdout(spawn_parser_s &_this);

/*
 * access to function callers
 */

extern bool(*spawn_pa_callers[])(spawn_parser_s &_this);

#endif

