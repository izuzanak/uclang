
#ifndef __SPAWNER_H
#define __SPAWNER_H

@begin
include "script_parser.h"
@end

#if SYSTEM_TYPE_UNIX_SPAWNER == ENABLED

#include <fcntl.h>
#include <poll.h>
#include <sys/wait.h>

/*
 * constants and definitions
 */

const unsigned c_spwn_rule_cnt = 22;
extern const unsigned spwn_rule_head_idxs[c_spwn_rule_cnt];
extern const unsigned spwn_rule_body_lengths[c_spwn_rule_cnt];

#define spwn_blank c_idx_not_exist
#define SPWN_SHIFT(VALUE) VALUE
#define SPWN_REDUCE(VALUE) c_spwn_lalr_table_reduce_base + VALUE
#define SPWN_GOTO(VALUE) VALUE

const unsigned c_spwn_lalr_table_reduce_base = 0x80000000;
const unsigned c_spwn_terminal_plus_nonterminal_cnt = 23;
const unsigned spwn_lalr_state_cnt = 31;

extern const unsigned spwn_lalr_table[spwn_lalr_state_cnt*c_spwn_terminal_plus_nonterminal_cnt];

/*
 * global spawner variables
 */

extern atomic_s g_spawner_running;

/*
 * definition of generated structures
 */

// -- spawn_parser_s --
@begin
struct
<
string_s:source_string
unsigned:old_input_idx
bi_array_s:fd_stack
string_array_s:arguments
lalr_stack_s:lalr_stack
>

additions
{
  // - open file with requested flags -
  static int open_file(char *ptr,char *ptr_end,int flags);

  // - return index of next terminal symbol (token) in input source -
  unsigned recognize_terminal(unsigned &a_input_idx);

  // - parse input string -
  bool parse_source(string_s &a_string);
}

spawn_parser_s;
@end

/*
 * inline methods of generated structures
 */

// -- spawn_parser_s --
@begin
inlines spawn_parser_s
@end

// - spawner global functions -

/*!
 * \brief function implementing process spawner
 * \param spawner_path - path to spawner fifo pipe
 * \param spawn_args - list of spawn arguments
 */
int run_spawner(const char *proc_name,const char *spawner_path,string_array_s &spawn_args);

#endif

#endif

