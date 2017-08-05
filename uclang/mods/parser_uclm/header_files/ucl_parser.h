
#ifndef __UCL_PARSER_H
#define __UCL_PARSER_H

@begin
include "parser_code.h"
@end

/*
 * definition of structure fa_source_s
 */

struct fa_source_s
{
  location_s *final_automata_loc;
  location_s *source_loc;
  unsigned old_input_idx;
  unsigned input_idx;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure parse_state_s
 */

struct parse_state_s
{
  interpreter_thread_s *it_ptr;
  unsigned source_pos;
  location_s *parser_loc;
  location_s *source_loc;

  bool in_reduce_callback;
  unsigned old_input_idx;
  unsigned input_idx;
  unsigned parse_action;
  lalr_stack_s lalr_stack;

  inline void init();
  inline void clear(interpreter_thread_s &it);

  bool parse_source_string(location_s *parse_state_loc,delegate_s *delegate_ptr,bool &a_parser_err);
};

/*
 * inline methods of structure fa_source_s
 */

inline void fa_source_s::init()
{/*{{{*/
  final_automata_loc = nullptr;
  source_loc = nullptr;
  old_input_idx = 0;
  input_idx = 0;
}/*}}}*/

inline void fa_source_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release final automata -
  if (final_automata_loc != nullptr)
  {
    it.release_location_ptr(final_automata_loc);
  }

  // - release source -
  if (source_loc != nullptr)
  {
    it.release_location_ptr(source_loc);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure parse_state_s
 */

inline void parse_state_s::init()
{/*{{{*/
  parser_loc = nullptr;
  source_loc = nullptr;
  lalr_stack.init();
}/*}}}*/

inline void parse_state_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release parser location -
  if (parser_loc != nullptr)
  {
    it.release_location_ptr(parser_loc);
  }

  // - release source location -
  if (source_loc != nullptr)
  {
    it.release_location_ptr(source_loc);
  }

  lalr_stack.clear();
}/*}}}*/

#endif


