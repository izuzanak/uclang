
#ifndef __UCL_DOCU_H
#define __UCL_DOCU_H

@begin
include "script_parser.h"
@end

/*
 * parse constants
 */

const unsigned c_dp_rule_cnt = 24;
extern const unsigned dp_rule_head_idxs[c_dp_rule_cnt];
extern const unsigned dp_rule_body_lengths[c_dp_rule_cnt];

/*
 * LALR parse table
 */

#define dp_blank c_idx_not_exist
#define DP_SHIFT(VALUE) VALUE
#define DP_REDUCE(VALUE) c_dp_lalr_table_reduce_base + VALUE
#define DP_GOTO(VALUE) VALUE

const unsigned c_dp_lalr_table_reduce_base = 0x80000000;
const unsigned c_dp_terminal_plus_nonterminal_cnt = 26;
const unsigned dp_lalr_state_cnt = 30;

extern const unsigned dp_lalr_table[dp_lalr_state_cnt*c_dp_terminal_plus_nonterminal_cnt];

// - comment element type identifiers -
enum
{
  c_comm_type_unknown = 0,
  c_comm_type_file,
  c_comm_type_class,
  c_comm_type_method,
  c_comm_type_var
};

/*
 * definition of structure docu_source_s
 */

struct docu_source_s
{
  location_s *source_ptr;
  unsigned src_length;
  char *src_data;
  name_pos_array_s comment_ranges;

  inline void init();
  inline void clear(interpreter_thread_s &it);

  unsigned fa_recognize(unsigned &input_idx);
  void find_comments();
};

/*
 * definition of structure docu_comment_s
 */

struct docu_comment_s
{
  location_s *ds_ptr;
  unsigned index;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure docu_parsed_s
 */

struct docu_parsed_s
{
  unsigned src_length;
  char *src_data;

  bool after_member;
  unsigned comm_type;

  location_s *id_string_ptr;
  location_s *brief_ptr;
  location_s *paragraphs_ptr;
  location_s *param_names_ptr;
  location_s *params_ptr;
  location_s *return_ptr;

  name_pos_array_s text_lines;
  lalr_stack_s lalr_stack;

  static const unsigned c_parse_action_cnt;
  static bool(*pa_callers[])(interpreter_thread_s &it,docu_parsed_s &_this);

  inline void init();
  inline void clear(interpreter_thread_s &it);

  static bool pa_null(interpreter_thread_s &it,docu_parsed_s &_this);
  static bool pa_paragraph(interpreter_thread_s &it,docu_parsed_s &_this);
  static bool pa_after_member(interpreter_thread_s &it,docu_parsed_s &_this);
  static bool pa_brief(interpreter_thread_s &it,docu_parsed_s &_this);
  static bool pa_param(interpreter_thread_s &it,docu_parsed_s &_this);
  static bool pa_return(interpreter_thread_s &it,docu_parsed_s &_this);
  static bool pa_file(interpreter_thread_s &it,docu_parsed_s &_this);
  static bool pa_class(interpreter_thread_s &it,docu_parsed_s &_this);
  static bool pa_method(interpreter_thread_s &it,docu_parsed_s &_this);
  static bool pa_var(interpreter_thread_s &it,docu_parsed_s &_this);
  static bool pa_text_line(interpreter_thread_s &it,docu_parsed_s &_this);

  void text_lines_to_string(string_s &a_target);
  unsigned fa_recognize(unsigned &input_idx);
  bool parse(interpreter_thread_s &it,string_s &a_source);
};

/*
 * inline methods of structure docu_source_s
 */

inline void docu_source_s::init()
{/*{{{*/
  source_ptr = nullptr;
  src_length = 0;
  src_data = nullptr;
  comment_ranges.init();
}/*}}}*/

inline void docu_source_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release source string -
  if (source_ptr != nullptr)
  {
    it.release_location_ptr(source_ptr);
  }

  // - release comment ranges -
  comment_ranges.clear();

  init();
}/*}}}*/

/*
 * inline methods of structure docu_comment_s
 */

inline void docu_comment_s::init()
{/*{{{*/
  ds_ptr = nullptr;
}/*}}}*/

inline void docu_comment_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release source string -
  if (ds_ptr != nullptr)
  {
    it.release_location_ptr(ds_ptr);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure docu_parsed_s
 */

inline void docu_parsed_s::init()
{/*{{{*/
  after_member = false;
  comm_type = c_comm_type_unknown;

  id_string_ptr = nullptr;
  brief_ptr = nullptr;
  paragraphs_ptr = nullptr;
  param_names_ptr = nullptr;
  params_ptr = nullptr;
  return_ptr = nullptr;

  text_lines.init();
  lalr_stack.init();
}/*}}}*/

inline void docu_parsed_s::clear(interpreter_thread_s &it)
{/*{{{*/

  #define DOCU_PARSER_RELEASE_LOCATION(POINTER) \
  {/*{{{*/\
    if (POINTER != nullptr)\
    {\
      it.release_location_ptr(POINTER);\
    }\
  }/*}}}*/

  DOCU_PARSER_RELEASE_LOCATION(id_string_ptr);
  DOCU_PARSER_RELEASE_LOCATION(brief_ptr);
  DOCU_PARSER_RELEASE_LOCATION(paragraphs_ptr);
  DOCU_PARSER_RELEASE_LOCATION(param_names_ptr);
  DOCU_PARSER_RELEASE_LOCATION(params_ptr);
  DOCU_PARSER_RELEASE_LOCATION(return_ptr);

  text_lines.clear();
  lalr_stack.clear();

  init();
}/*}}}*/

#endif

