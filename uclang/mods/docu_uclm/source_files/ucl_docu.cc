
@begin
include "ucl_docu.h"
@end

/*
 * parse constants
 */

const unsigned dp_rule_head_idxs[c_dp_rule_cnt] = {16, 17, 17, 18, 18, 19, 19, 19, 20, 21, 22, 22, 23, 23, 23, 23, 23, 23, 23, 23, 23, 24, 24, 25, };
const unsigned dp_rule_body_lengths[c_dp_rule_cnt] = {1, 2, 1, 2, 1, 1, 2, 1, 1, 1, 1, 2, 1, 2, 2, 2, 2, 1, 1, 1, 1, 1, 2, 1, };

/*
 * LALR parse table
 */

const unsigned dp_lalr_table[dp_lalr_state_cnt*c_dp_terminal_plus_nonterminal_cnt] =
{/*{{{*/
   DP_SHIFT(11),   DP_SHIFT(20),   DP_SHIFT(10),   DP_SHIFT(12),   DP_SHIFT(13),   DP_SHIFT(14),   DP_SHIFT(15),   DP_SHIFT(16),   DP_SHIFT(17),   DP_SHIFT(18),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,    DP_SHIFT(3),       dp_blank,     DP_GOTO(1),     DP_GOTO(2),     DP_GOTO(4),     DP_GOTO(6),     DP_GOTO(7),     DP_GOTO(5),     DP_GOTO(8),     DP_GOTO(9),    DP_GOTO(19),
       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,
       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,   DP_SHIFT(21),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,
       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,
   DP_SHIFT(11),       dp_blank,       dp_blank,   DP_SHIFT(12),   DP_SHIFT(13),   DP_SHIFT(14),   DP_SHIFT(15),   DP_SHIFT(16),   DP_SHIFT(17),   DP_SHIFT(18),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,    DP_GOTO(22),     DP_GOTO(8),       dp_blank,       dp_blank,
   DP_SHIFT(11),       dp_blank,       dp_blank,   DP_SHIFT(12),   DP_SHIFT(13),   DP_SHIFT(14),   DP_SHIFT(15),   DP_SHIFT(16),   DP_SHIFT(17),   DP_SHIFT(18),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,   DP_REDUCE(4),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,    DP_GOTO(23),       dp_blank,       dp_blank,
   DP_REDUCE(5),       dp_blank,       dp_blank,   DP_REDUCE(5),   DP_REDUCE(5),   DP_REDUCE(5),   DP_REDUCE(5),   DP_REDUCE(5),   DP_REDUCE(5),   DP_REDUCE(5),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,
   DP_REDUCE(7),   DP_SHIFT(20),       dp_blank,   DP_REDUCE(7),   DP_REDUCE(7),   DP_REDUCE(7),   DP_REDUCE(7),   DP_REDUCE(7),   DP_REDUCE(7),   DP_REDUCE(7),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,    DP_GOTO(24),       dp_blank,       dp_blank,       dp_blank,     DP_GOTO(9),    DP_GOTO(19),
  DP_REDUCE(10),       dp_blank,       dp_blank,  DP_REDUCE(10),  DP_REDUCE(10),  DP_REDUCE(10),  DP_REDUCE(10),  DP_REDUCE(10),  DP_REDUCE(10),  DP_REDUCE(10),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,  DP_REDUCE(10),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,
   DP_REDUCE(8),   DP_SHIFT(20),       dp_blank,   DP_REDUCE(8),   DP_REDUCE(8),   DP_REDUCE(8),   DP_REDUCE(8),   DP_REDUCE(8),   DP_REDUCE(8),   DP_REDUCE(8),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,   DP_REDUCE(8),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,    DP_GOTO(25),
   DP_REDUCE(9),   DP_REDUCE(9),       dp_blank,   DP_REDUCE(9),   DP_REDUCE(9),   DP_REDUCE(9),   DP_REDUCE(9),   DP_REDUCE(9),   DP_REDUCE(9),   DP_REDUCE(9),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,
  DP_REDUCE(12),   DP_SHIFT(20),       dp_blank,  DP_REDUCE(12),  DP_REDUCE(12),  DP_REDUCE(12),  DP_REDUCE(12),  DP_REDUCE(12),  DP_REDUCE(12),  DP_REDUCE(12),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,  DP_REDUCE(12),       dp_blank,       dp_blank,       dp_blank,       dp_blank,    DP_GOTO(26),       dp_blank,       dp_blank,       dp_blank,     DP_GOTO(9),    DP_GOTO(19),
       dp_blank,   DP_SHIFT(20),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,    DP_GOTO(27),    DP_GOTO(19),
       dp_blank,   DP_SHIFT(20),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,    DP_GOTO(28),    DP_GOTO(19),
       dp_blank,   DP_SHIFT(20),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,    DP_GOTO(29),    DP_GOTO(19),
  DP_REDUCE(17),       dp_blank,       dp_blank,  DP_REDUCE(17),  DP_REDUCE(17),  DP_REDUCE(17),  DP_REDUCE(17),  DP_REDUCE(17),  DP_REDUCE(17),  DP_REDUCE(17),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,  DP_REDUCE(17),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,
  DP_REDUCE(18),       dp_blank,       dp_blank,  DP_REDUCE(18),  DP_REDUCE(18),  DP_REDUCE(18),  DP_REDUCE(18),  DP_REDUCE(18),  DP_REDUCE(18),  DP_REDUCE(18),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,  DP_REDUCE(18),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,
  DP_REDUCE(19),       dp_blank,       dp_blank,  DP_REDUCE(19),  DP_REDUCE(19),  DP_REDUCE(19),  DP_REDUCE(19),  DP_REDUCE(19),  DP_REDUCE(19),  DP_REDUCE(19),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,  DP_REDUCE(19),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,
  DP_REDUCE(20),       dp_blank,       dp_blank,  DP_REDUCE(20),  DP_REDUCE(20),  DP_REDUCE(20),  DP_REDUCE(20),  DP_REDUCE(20),  DP_REDUCE(20),  DP_REDUCE(20),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,  DP_REDUCE(20),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,
  DP_REDUCE(21),  DP_REDUCE(21),       dp_blank,  DP_REDUCE(21),  DP_REDUCE(21),  DP_REDUCE(21),  DP_REDUCE(21),  DP_REDUCE(21),  DP_REDUCE(21),  DP_REDUCE(21),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,  DP_REDUCE(21),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,
  DP_REDUCE(23),  DP_REDUCE(23),       dp_blank,  DP_REDUCE(23),  DP_REDUCE(23),  DP_REDUCE(23),  DP_REDUCE(23),  DP_REDUCE(23),  DP_REDUCE(23),  DP_REDUCE(23),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,  DP_REDUCE(23),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,
       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,
   DP_SHIFT(11),       dp_blank,       dp_blank,   DP_SHIFT(12),   DP_SHIFT(13),   DP_SHIFT(14),   DP_SHIFT(15),   DP_SHIFT(16),   DP_SHIFT(17),   DP_SHIFT(18),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,   DP_REDUCE(3),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,    DP_GOTO(23),       dp_blank,       dp_blank,
  DP_REDUCE(11),       dp_blank,       dp_blank,  DP_REDUCE(11),  DP_REDUCE(11),  DP_REDUCE(11),  DP_REDUCE(11),  DP_REDUCE(11),  DP_REDUCE(11),  DP_REDUCE(11),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,  DP_REDUCE(11),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,
   DP_REDUCE(6),       dp_blank,       dp_blank,   DP_REDUCE(6),   DP_REDUCE(6),   DP_REDUCE(6),   DP_REDUCE(6),   DP_REDUCE(6),   DP_REDUCE(6),   DP_REDUCE(6),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,
  DP_REDUCE(22),  DP_REDUCE(22),       dp_blank,  DP_REDUCE(22),  DP_REDUCE(22),  DP_REDUCE(22),  DP_REDUCE(22),  DP_REDUCE(22),  DP_REDUCE(22),  DP_REDUCE(22),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,  DP_REDUCE(22),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,
  DP_REDUCE(13),       dp_blank,       dp_blank,  DP_REDUCE(13),  DP_REDUCE(13),  DP_REDUCE(13),  DP_REDUCE(13),  DP_REDUCE(13),  DP_REDUCE(13),  DP_REDUCE(13),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,  DP_REDUCE(13),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,
  DP_REDUCE(14),   DP_SHIFT(20),       dp_blank,  DP_REDUCE(14),  DP_REDUCE(14),  DP_REDUCE(14),  DP_REDUCE(14),  DP_REDUCE(14),  DP_REDUCE(14),  DP_REDUCE(14),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,  DP_REDUCE(14),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,    DP_GOTO(25),
  DP_REDUCE(15),   DP_SHIFT(20),       dp_blank,  DP_REDUCE(15),  DP_REDUCE(15),  DP_REDUCE(15),  DP_REDUCE(15),  DP_REDUCE(15),  DP_REDUCE(15),  DP_REDUCE(15),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,  DP_REDUCE(15),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,    DP_GOTO(25),
  DP_REDUCE(16),   DP_SHIFT(20),       dp_blank,  DP_REDUCE(16),  DP_REDUCE(16),  DP_REDUCE(16),  DP_REDUCE(16),  DP_REDUCE(16),  DP_REDUCE(16),  DP_REDUCE(16),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,  DP_REDUCE(16),       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,       dp_blank,    DP_GOTO(25),
};/*}}}*/

/*
 * methods of structure docu_source_s
 */

unsigned docu_source_s::fa_recognize(unsigned &input_idx) // lgtm [cpp/use-of-goto]
{/*{{{*/
#define DOCU_COMM_GET_NEXT_CHAR() \
  {\
    if (input_idx < src_length) {\
      in_char = (unsigned char)src_data[input_idx];\
    }\
    else {\
      in_char = '\0';\
    }\
  }

#define DOCU_COMM_CLOSE_CHAR(RET_TERM_IDX) \
  {\
    if (in_char == '\0') {\
      return RET_TERM_IDX;\
    }\
\
    input_idx++;\
  }

   unsigned char in_char;

// - STATE 0 -
   DOCU_COMM_GET_NEXT_CHAR();

   if (in_char == 0) {
      goto state_1_label;
   }
   if (in_char == 35) {
      goto state_2_label;
   }
   if (in_char == 47) {
      goto state_3_label;
   }
   return c_idx_not_exist;

// - STATE 1 -
state_1_label:
   DOCU_COMM_CLOSE_CHAR(1);
   return 1;

// - STATE 2 -
state_2_label:
   DOCU_COMM_CLOSE_CHAR(c_idx_not_exist);
   DOCU_COMM_GET_NEXT_CHAR();

   if (in_char == 33) {
      goto state_4_label;
   }
   if (in_char == 35) {
      goto state_4_label;
   }
   return c_idx_not_exist;

// - STATE 3 -
state_3_label:
   DOCU_COMM_CLOSE_CHAR(c_idx_not_exist);
   DOCU_COMM_GET_NEXT_CHAR();

   if (in_char == 42) {
      goto state_5_label;
   }
   if (in_char == 47) {
      goto state_6_label;
   }
   return c_idx_not_exist;

// - STATE 4 -
state_4_label:
   DOCU_COMM_CLOSE_CHAR(c_idx_not_exist);
   DOCU_COMM_GET_NEXT_CHAR();

   if (in_char < 10) {
      goto state_4_label;
   }
   if (in_char == 10) {
      goto state_7_label;
   }
   if (in_char >= 11) {
      goto state_4_label;
   }
   return c_idx_not_exist;

// - STATE 5 -
state_5_label:
   DOCU_COMM_CLOSE_CHAR(c_idx_not_exist);
   DOCU_COMM_GET_NEXT_CHAR();

   if (in_char == 33) {
      goto state_8_label;
   }
   if (in_char == 42) {
      goto state_8_label;
   }
   return c_idx_not_exist;

// - STATE 6 -
state_6_label:
   DOCU_COMM_CLOSE_CHAR(c_idx_not_exist);
   DOCU_COMM_GET_NEXT_CHAR();

   if (in_char == 33) {
      goto state_9_label;
   }
   if (in_char == 47) {
      goto state_9_label;
   }
   return c_idx_not_exist;

// - STATE 7 -
state_7_label:
   DOCU_COMM_CLOSE_CHAR(0);
   DOCU_COMM_GET_NEXT_CHAR();

   if (in_char == 9) {
      goto state_7_label;
   }
   if (in_char == 32) {
      goto state_7_label;
   }
   return 0;

// - STATE 8 -
state_8_label:
   DOCU_COMM_CLOSE_CHAR(c_idx_not_exist);
   DOCU_COMM_GET_NEXT_CHAR();

   if (in_char < 42) {
      goto state_8_label;
   }
   if (in_char == 42) {
      goto state_10_label;
   }
   if (in_char >= 43) {
      goto state_8_label;
   }
   return c_idx_not_exist;

// - STATE 9 -
state_9_label:
   DOCU_COMM_CLOSE_CHAR(c_idx_not_exist);
   DOCU_COMM_GET_NEXT_CHAR();

   if (in_char < 10) {
      goto state_9_label;
   }
   if (in_char == 10) {
      goto state_7_label;
   }
   if (in_char >= 11) {
      goto state_9_label;
   }
   return c_idx_not_exist;

// - STATE 10 -
state_10_label:
   DOCU_COMM_CLOSE_CHAR(c_idx_not_exist);
   DOCU_COMM_GET_NEXT_CHAR();

   if (in_char < 47) {
      goto state_8_label;
   }
   if (in_char == 47) {
      goto state_11_label;
   }
   if (in_char >= 48) {
      goto state_8_label;
   }
   return c_idx_not_exist;

// - STATE 11 -
state_11_label:
   DOCU_COMM_CLOSE_CHAR(0);
   DOCU_COMM_GET_NEXT_CHAR();

   if (in_char == 9) {
      goto state_11_label;
   }
   if (in_char == 10) {
      goto state_7_label;
   }
   if (in_char == 32) {
      goto state_11_label;
   }
   return 0;

}/*}}}*/

void docu_source_s::find_comments()
{/*{{{*/
  comment_ranges.used = 0;

  // - end of last comment -
  unsigned last_end_idx = c_idx_not_exist;

  unsigned old_input_idx = 0;
  unsigned input_idx = 0;
  unsigned ret_term = c_idx_not_exist;

  do
  {
    // - store old input index -
    old_input_idx = input_idx;

    // - recognize next terminal -
    ret_term = fa_recognize(input_idx);

    if (ret_term == c_idx_not_exist)
    {
      input_idx = old_input_idx + 1;
    }
    else
    {
      // - end of input -
      if (ret_term == 1)
      {
        break;
      }

      // - empty comment -
      if (old_input_idx == input_idx)
      {
        input_idx++;
      }

      // - recognized comment -
      else
      {
        if (last_end_idx == old_input_idx)
        {
          // - add comment to previous comment range -
          comment_ranges.last().ui_second = input_idx;
        }
        else
        {
          // - create new comment range -
          comment_ranges.push_blank();
          comment_ranges.last().set(old_input_idx,input_idx);
        }

        // - update last end index -
        last_end_idx = input_idx;
      }
    }
  }
  while(true);
}/*}}}*/

/*
 * static members of structure docu_parsed_s
 */

// - callers of parse action functions -
const unsigned docu_parsed_s::c_parse_action_cnt = 24;
bool(*docu_parsed_s::pa_callers[docu_parsed_s::c_parse_action_cnt])(interpreter_thread_s &it,docu_parsed_s &_this) =
{/*{{{*/
  pa_null,
  pa_null,
  pa_null,
  pa_null,
  pa_null,
  pa_null,
  pa_null,
  pa_null,
  pa_paragraph,
  pa_after_member,
  pa_null,
  pa_null,
  pa_null,
  pa_null,
  pa_brief,
  pa_param,
  pa_return,
  pa_file,
  pa_class,
  pa_method,
  pa_var,
  pa_null,
  pa_null,
  pa_text_line
};/*}}}*/

/*
 * methods of structure docu_parsed_s
 */

#define DOCU_PARSED_PUSH_TO_ARRAY(POINTER,SET_CODE) \
{/*{{{*/\
  pointer_array_s *array_ptr;\
\
  if (POINTER->v_type != c_bi_class_array)\
  {\
    /* - construct array - */\
    array_ptr = it.get_new_array_ptr();\
\
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);\
    it.release_location_ptr(POINTER);\
    POINTER = new_location;\
  }\
  else\
  {\
    /* - retrieve array - */\
    array_ptr = (pointer_array_s *)POINTER->v_data_ptr;\
  }\
\
  /* - construct string - */\
  string_s *string_ptr = it.get_new_string_ptr();\
\
  SET_CODE;\
\
  /* - push location to array - */\
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);\
  array_ptr->push(new_location);\
}/*}}}*/

bool docu_parsed_s::pa_null(interpreter_thread_s &it,docu_parsed_s &_this)
{/*{{{*/
  debug_assert(0);

  debug_message_6(fprintf(stderr,"docu_parsed_s: parse_action: pa_null\n"));

  return true;
}/*}}}*/

bool docu_parsed_s::pa_paragraph(interpreter_thread_s &it,docu_parsed_s &_this)
{/*{{{*/
  location_s *&paragraphs_ptr = _this.paragraphs_ptr;

  // *****

  DOCU_PARSED_PUSH_TO_ARRAY(
    paragraphs_ptr,
    _this.text_lines_to_string(*string_ptr);
  )

  debug_message_6(fprintf(stderr,"docu_parsed_s: parse_action: pa_paragraph\n"));

  return true;
}/*}}}*/

bool docu_parsed_s::pa_after_member(interpreter_thread_s &it,docu_parsed_s &_this)
{/*{{{*/
  bool &after_member = _this.after_member;

  // *****

  // - set after member flag -
  after_member = true;

  debug_message_6(fprintf(stderr,"docu_parsed_s: parse_action: pa_after_member\n"));

  return true;
}/*}}}*/

bool docu_parsed_s::pa_brief(interpreter_thread_s &it,docu_parsed_s &_this)
{/*{{{*/
  location_s *&brief_ptr = _this.brief_ptr;

  // *****

  // - store brief description -
  string_s *string_ptr = it.get_new_string_ptr();
  _this.text_lines_to_string(*string_ptr);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
  it.release_location_ptr(brief_ptr);
  brief_ptr = new_location;

  debug_message_6(fprintf(stderr,"docu_parsed_s: parse_action: pa_brief\n"));

  return true;
}/*}}}*/

bool docu_parsed_s::pa_param(interpreter_thread_s &it,docu_parsed_s &_this)
{/*{{{*/
  char *&src_data = _this.src_data;
  location_s *&param_names_ptr = _this.param_names_ptr;
  location_s *&params_ptr = _this.params_ptr;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack[lalr_stack.used - 2];
  unsigned terminal_start = lse.terminal_start + 7;

  DOCU_PARSED_PUSH_TO_ARRAY(
    param_names_ptr,
    string_ptr->set(lse.terminal_end - terminal_start,src_data + terminal_start);
  )

  DOCU_PARSED_PUSH_TO_ARRAY(
    params_ptr,
    _this.text_lines_to_string(*string_ptr);
  )

  debug_message_6(fprintf(stderr,"docu_parsed_s: parse_action: pa_param\n"));

  return true;
}/*}}}*/

bool docu_parsed_s::pa_return(interpreter_thread_s &it,docu_parsed_s &_this)
{/*{{{*/
  location_s *&return_ptr = _this.return_ptr;

  // *****

  // - store return value description -
  string_s *string_ptr = it.get_new_string_ptr();
  _this.text_lines_to_string(*string_ptr);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
  it.release_location_ptr(return_ptr);
  return_ptr = new_location;

  debug_message_6(fprintf(stderr,"docu_parsed_s: parse_action: pa_return\n"));

  return true;
}/*}}}*/

bool docu_parsed_s::pa_file(interpreter_thread_s &it,docu_parsed_s &_this)
{/*{{{*/
  char *&src_data = _this.src_data;
  unsigned &comm_type = _this.comm_type;
  location_s *&id_string_ptr = _this.id_string_ptr;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned terminal_start = lse.terminal_start + 6;

  // - store comment type -
  comm_type = c_comm_type_file;

  // - store element id string -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(lse.terminal_end - terminal_start,src_data + terminal_start);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
  it.release_location_ptr(id_string_ptr);
  id_string_ptr = new_location;

  debug_message_6(fprintf(stderr,"docu_parsed_s: parse_action: pa_file\n"));

  return true;
}/*}}}*/

bool docu_parsed_s::pa_class(interpreter_thread_s &it,docu_parsed_s &_this)
{/*{{{*/
  char *&src_data = _this.src_data;
  unsigned &comm_type = _this.comm_type;
  location_s *&id_string_ptr = _this.id_string_ptr;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned terminal_start = lse.terminal_start + 7;

  // - store comment type -
  comm_type = c_comm_type_class;

  // - store element id string -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(lse.terminal_end - terminal_start,src_data + terminal_start);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
  it.release_location_ptr(id_string_ptr);
  id_string_ptr = new_location;

  debug_message_6(fprintf(stderr,"docu_parsed_s: parse_action: pa_class\n"));

  return true;
}/*}}}*/

bool docu_parsed_s::pa_method(interpreter_thread_s &it,docu_parsed_s &_this)
{/*{{{*/
  char *&src_data = _this.src_data;
  unsigned &comm_type = _this.comm_type;
  location_s *&id_string_ptr = _this.id_string_ptr;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned terminal_start = lse.terminal_start + 8;

  // - store comment type -
  comm_type = c_comm_type_method;

  // - store element id string -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(lse.terminal_end - terminal_start,src_data + terminal_start);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
  it.release_location_ptr(id_string_ptr);
  id_string_ptr = new_location;

  debug_message_6(fprintf(stderr,"docu_parsed_s: parse_action: pa_method\n"));

  return true;
}/*}}}*/

bool docu_parsed_s::pa_var(interpreter_thread_s &it,docu_parsed_s &_this)
{/*{{{*/
  char *&src_data = _this.src_data;
  unsigned &comm_type = _this.comm_type;
  location_s *&id_string_ptr = _this.id_string_ptr;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned terminal_start = lse.terminal_start + 5;

  // - store comment type -
  comm_type = c_comm_type_var;

  // - store element id string -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(lse.terminal_end - terminal_start,src_data + terminal_start);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
  it.release_location_ptr(id_string_ptr);
  id_string_ptr = new_location;

  debug_message_6(fprintf(stderr,"docu_parsed_s: parse_action: pa_var\n"));

  return true;
}/*}}}*/

bool docu_parsed_s::pa_text_line(interpreter_thread_s &it,docu_parsed_s &_this)
{/*{{{*/
  name_pos_array_s &text_lines = _this.text_lines;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();

  text_lines.push_blank();
  text_lines.last().set(lse.terminal_start,lse.terminal_end);

  debug_message_6(fprintf(stderr,"docu_parsed_s: parse_action: pa_text_line\n"));

  return true;
}/*}}}*/

void docu_parsed_s::text_lines_to_string(string_s &a_target)
{/*{{{*/
  a_target.clear();

  if (text_lines.used != 0)
  {
    unsigned length = 0;

    // - compute length of target string -
    name_pos_s *np_ptr = text_lines.data;
    name_pos_s *np_ptr_end = np_ptr + text_lines.used;
    do {
      length += np_ptr->ui_second - np_ptr->ui_first;
    } while(++np_ptr < np_ptr_end);

    a_target.create(length);

    // - construct target string -
    char *t_ptr = a_target.data;
    np_ptr = text_lines.data;
    do {
      unsigned tl_length = np_ptr->ui_second - np_ptr->ui_first;

      memcpy(t_ptr,src_data + np_ptr->ui_first,tl_length);
      t_ptr += tl_length;

    } while(++np_ptr < np_ptr_end);

    // - remove last new line character -
    a_target.size -= 1;
    a_target.data[a_target.size - 1]= '\0';

    // - release used text lines -
    text_lines.used = 0;
  }
}/*}}}*/

unsigned docu_parsed_s::fa_recognize(unsigned &input_idx) // lgtm [cpp/use-of-goto]
{/*{{{*/
#define DOCU_PARSE_GET_NEXT_CHAR() \
  {\
    if (input_idx < src_length) {\
      in_char = (unsigned char)src_data[input_idx];\
    }\
    else {\
      in_char = '\0';\
    }\
  }

#define DOCU_PARSE_CLOSE_CHAR(RET_TERM_IDX) \
  {\
    if (in_char == '\0') {\
      return RET_TERM_IDX;\
    }\
\
    input_idx++;\
  }

   unsigned char in_char;

// - STATE 0 -
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 0) {
      goto state_1_label;
   }
   if (in_char == 9) {
      goto state_2_label;
   }
   if (in_char == 10) {
      goto state_3_label;
   }
   if (in_char == 32) {
      goto state_2_label;
   }
   if (in_char == 35) {
      goto state_4_label;
   }
   if (in_char == 42) {
      goto state_5_label;
   }
   if (in_char == 47) {
      goto state_6_label;
   }
   if (in_char >= 48 && in_char < 58) {
      goto state_9_label;
   }
   if (in_char == 60) {
      goto state_7_label;
   }
   if (in_char == 64) {
      goto state_8_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_9_label;
   }
   if (in_char == 92) {
      goto state_8_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_9_label;
   }
   return c_idx_not_exist;

// - STATE 1 -
state_1_label:
   DOCU_PARSE_CLOSE_CHAR(15);
   return 15;

// - STATE 2 -
state_2_label:
   DOCU_PARSE_CLOSE_CHAR(10);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 9) {
      goto state_2_label;
   }
   if (in_char == 32) {
      goto state_2_label;
   }
   return 10;

// - STATE 3 -
state_3_label:
   DOCU_PARSE_CLOSE_CHAR(0);
   return 0;

// - STATE 4 -
state_4_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 33) {
      goto state_10_label;
   }
   if (in_char == 35) {
      goto state_10_label;
   }
   return c_idx_not_exist;

// - STATE 5 -
state_5_label:
   DOCU_PARSE_CLOSE_CHAR(14);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 47) {
      goto state_11_label;
   }
   return 14;

// - STATE 6 -
state_6_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 42) {
      goto state_12_label;
   }
   if (in_char == 47) {
      goto state_13_label;
   }
   return c_idx_not_exist;

// - STATE 7 -
state_7_label:
   DOCU_PARSE_CLOSE_CHAR(2);
   return 2;

// - STATE 8 -
state_8_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 98) {
      goto state_14_label;
   }
   if (in_char == 99) {
      goto state_15_label;
   }
   if (in_char == 102) {
      goto state_16_label;
   }
   if (in_char == 109) {
      goto state_17_label;
   }
   if (in_char == 112) {
      goto state_18_label;
   }
   if (in_char == 114) {
      goto state_19_label;
   }
   if (in_char == 118) {
      goto state_20_label;
   }
   return c_idx_not_exist;

// - STATE 9 -
state_9_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char < 10) {
      goto state_9_label;
   }
   if (in_char == 10) {
      goto state_21_label;
   }
   if (in_char >= 11) {
      goto state_9_label;
   }
   return c_idx_not_exist;

// - STATE 10 -
state_10_label:
   DOCU_PARSE_CLOSE_CHAR(11);
   return 11;

// - STATE 11 -
state_11_label:
   DOCU_PARSE_CLOSE_CHAR(14);
   return 14;

// - STATE 12 -
state_12_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 33) {
      goto state_22_label;
   }
   if (in_char == 42) {
      goto state_22_label;
   }
   return c_idx_not_exist;

// - STATE 13 -
state_13_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 33) {
      goto state_23_label;
   }
   if (in_char == 47) {
      goto state_23_label;
   }
   return c_idx_not_exist;

// - STATE 14 -
state_14_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 114) {
      goto state_24_label;
   }
   return c_idx_not_exist;

// - STATE 15 -
state_15_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 108) {
      goto state_25_label;
   }
   return c_idx_not_exist;

// - STATE 16 -
state_16_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 105) {
      goto state_26_label;
   }
   return c_idx_not_exist;

// - STATE 17 -
state_17_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 101) {
      goto state_27_label;
   }
   return c_idx_not_exist;

// - STATE 18 -
state_18_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 97) {
      goto state_28_label;
   }
   return c_idx_not_exist;

// - STATE 19 -
state_19_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 101) {
      goto state_29_label;
   }
   return c_idx_not_exist;

// - STATE 20 -
state_20_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 97) {
      goto state_30_label;
   }
   return c_idx_not_exist;

// - STATE 21 -
state_21_label:
   DOCU_PARSE_CLOSE_CHAR(1);
   return 1;

// - STATE 22 -
state_22_label:
   DOCU_PARSE_CLOSE_CHAR(13);
   return 13;

// - STATE 23 -
state_23_label:
   DOCU_PARSE_CLOSE_CHAR(12);
   return 12;

// - STATE 24 -
state_24_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 105) {
      goto state_31_label;
   }
   return c_idx_not_exist;

// - STATE 25 -
state_25_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 97) {
      goto state_32_label;
   }
   return c_idx_not_exist;

// - STATE 26 -
state_26_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 108) {
      goto state_33_label;
   }
   return c_idx_not_exist;

// - STATE 27 -
state_27_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 116) {
      goto state_34_label;
   }
   return c_idx_not_exist;

// - STATE 28 -
state_28_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 114) {
      goto state_35_label;
   }
   return c_idx_not_exist;

// - STATE 29 -
state_29_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 116) {
      goto state_36_label;
   }
   return c_idx_not_exist;

// - STATE 30 -
state_30_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 114) {
      goto state_37_label;
   }
   return c_idx_not_exist;

// - STATE 31 -
state_31_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 101) {
      goto state_38_label;
   }
   return c_idx_not_exist;

// - STATE 32 -
state_32_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 115) {
      goto state_39_label;
   }
   return c_idx_not_exist;

// - STATE 33 -
state_33_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 101) {
      goto state_40_label;
   }
   return c_idx_not_exist;

// - STATE 34 -
state_34_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 104) {
      goto state_41_label;
   }
   return c_idx_not_exist;

// - STATE 35 -
state_35_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 97) {
      goto state_42_label;
   }
   return c_idx_not_exist;

// - STATE 36 -
state_36_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 117) {
      goto state_43_label;
   }
   return c_idx_not_exist;

// - STATE 37 -
state_37_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 32) {
      goto state_44_label;
   }
   return c_idx_not_exist;

// - STATE 38 -
state_38_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 102) {
      goto state_45_label;
   }
   return c_idx_not_exist;

// - STATE 39 -
state_39_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 115) {
      goto state_46_label;
   }
   return c_idx_not_exist;

// - STATE 40 -
state_40_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 32) {
      goto state_47_label;
   }
   return c_idx_not_exist;

// - STATE 41 -
state_41_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 111) {
      goto state_48_label;
   }
   return c_idx_not_exist;

// - STATE 42 -
state_42_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 109) {
      goto state_49_label;
   }
   return c_idx_not_exist;

// - STATE 43 -
state_43_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 114) {
      goto state_50_label;
   }
   return c_idx_not_exist;

// - STATE 44 -
state_44_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 46) {
      goto state_51_label;
   }
   if (in_char >= 48 && in_char < 58) {
      goto state_51_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_51_label;
   }
   if (in_char == 95) {
      goto state_51_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_51_label;
   }
   return c_idx_not_exist;

// - STATE 45 -
state_45_label:
   DOCU_PARSE_CLOSE_CHAR(3);
   return 3;

// - STATE 46 -
state_46_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 32) {
      goto state_52_label;
   }
   return c_idx_not_exist;

// - STATE 47 -
state_47_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 46) {
      goto state_53_label;
   }
   if (in_char >= 48 && in_char < 58) {
      goto state_53_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_53_label;
   }
   if (in_char == 95) {
      goto state_53_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_53_label;
   }
   return c_idx_not_exist;

// - STATE 48 -
state_48_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 100) {
      goto state_54_label;
   }
   return c_idx_not_exist;

// - STATE 49 -
state_49_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 32) {
      goto state_55_label;
   }
   return c_idx_not_exist;

// - STATE 50 -
state_50_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 110) {
      goto state_56_label;
   }
   return c_idx_not_exist;

// - STATE 51 -
state_51_label:
   DOCU_PARSE_CLOSE_CHAR(9);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 35) {
      goto state_51_label;
   }
   if (in_char == 46) {
      goto state_51_label;
   }
   if (in_char >= 48 && in_char < 58) {
      goto state_51_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_51_label;
   }
   if (in_char == 95) {
      goto state_51_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_51_label;
   }
   return 9;

// - STATE 52 -
state_52_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 46) {
      goto state_57_label;
   }
   if (in_char >= 48 && in_char < 58) {
      goto state_57_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_57_label;
   }
   if (in_char == 95) {
      goto state_57_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_57_label;
   }
   return c_idx_not_exist;

// - STATE 53 -
state_53_label:
   DOCU_PARSE_CLOSE_CHAR(6);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char >= 45 && in_char < 47) {
      goto state_53_label;
   }
   if (in_char >= 48 && in_char < 58) {
      goto state_53_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_53_label;
   }
   if (in_char == 95) {
      goto state_53_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_53_label;
   }
   return 6;

// - STATE 54 -
state_54_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 32) {
      goto state_58_label;
   }
   return c_idx_not_exist;

// - STATE 55 -
state_55_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char >= 65 && in_char < 91) {
      goto state_59_label;
   }
   if (in_char == 95) {
      goto state_59_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_59_label;
   }
   return c_idx_not_exist;

// - STATE 56 -
state_56_label:
   DOCU_PARSE_CLOSE_CHAR(5);
   return 5;

// - STATE 57 -
state_57_label:
   DOCU_PARSE_CLOSE_CHAR(7);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 46) {
      goto state_57_label;
   }
   if (in_char >= 48 && in_char < 58) {
      goto state_57_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_57_label;
   }
   if (in_char == 95) {
      goto state_57_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_57_label;
   }
   return 7;

// - STATE 58 -
state_58_label:
   DOCU_PARSE_CLOSE_CHAR(c_idx_not_exist);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 46) {
      goto state_60_label;
   }
   if (in_char >= 48 && in_char < 58) {
      goto state_60_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_60_label;
   }
   if (in_char == 95) {
      goto state_60_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_60_label;
   }
   return c_idx_not_exist;

// - STATE 59 -
state_59_label:
   DOCU_PARSE_CLOSE_CHAR(4);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_59_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_59_label;
   }
   if (in_char == 95) {
      goto state_59_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_59_label;
   }
   return 4;

// - STATE 60 -
state_60_label:
   DOCU_PARSE_CLOSE_CHAR(8);
   DOCU_PARSE_GET_NEXT_CHAR();

   if (in_char == 35) {
      goto state_60_label;
   }
   if (in_char == 46) {
      goto state_60_label;
   }
   if (in_char >= 48 && in_char < 58) {
      goto state_60_label;
   }
   if (in_char >= 65 && in_char < 91) {
      goto state_60_label;
   }
   if (in_char == 95) {
      goto state_60_label;
   }
   if (in_char >= 97 && in_char < 123) {
      goto state_60_label;
   }
   return 8;

}/*}}}*/

bool docu_parsed_s::parse(interpreter_thread_s &it,string_s &a_source)
{/*{{{*/
  lalr_stack.used = 0;
  lalr_stack.push(0);

  src_length = a_source.size - 1;
  src_data = a_source.data;

  unsigned parse_action;

  unsigned old_input_idx = 0;
  unsigned input_idx = 0;
  unsigned ret_term = c_idx_not_exist;

  do
  {
    while (ret_term == c_idx_not_exist)
    {
      old_input_idx = input_idx;

      ret_term = fa_recognize(input_idx);

      // - ERROR -
      if (ret_term == c_idx_not_exist)
      {
        return false;
      }

      if (ret_term == 10 || ret_term == 11 || ret_term == 12 || ret_term == 13 || ret_term == 14)
      {
        ret_term = c_idx_not_exist;
      }
    }

    // - nalezeni akce v tabulce akci -
    parse_action = dp_lalr_table[lalr_stack.last().lalr_state*c_dp_terminal_plus_nonterminal_cnt + ret_term];

    // - ERROR -
    if (parse_action == c_idx_not_exist)
    {
      return false;
    }

    // - akce SHIFT -
    if (parse_action < c_dp_lalr_table_reduce_base)
    {
      if (ret_term == 15)
      {
        break;
      }

      // - vlozi na zasobnik novy stav a pozici terminalu ve zdrojovem retezci -
      lalr_stack.push(parse_action,old_input_idx,input_idx);
      ret_term = c_idx_not_exist;
    }

    // -akce REDUCE-
    else
    {
      parse_action -= c_dp_lalr_table_reduce_base;

      // - call assigned function to reduction -
      if (pa_callers[parse_action] != pa_null)
      {
        if (!pa_callers[parse_action](it,*this))
        {
          return false;
        }
      }

      // - odstraneni tela pravidla z vrcholu zasobniku -
      lalr_stack.used -= dp_rule_body_lengths[parse_action];

      // - ulozeni noveho stavu automatu na zasobnik -
      unsigned goto_val = dp_lalr_table[lalr_stack.last().lalr_state*c_dp_terminal_plus_nonterminal_cnt + dp_rule_head_idxs[parse_action]];
      lalr_stack.push(goto_val);
    }

  }
  while(true);

  return true;
}/*}}}*/

