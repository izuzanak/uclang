
@begin
include "ucl_ucgcg.h"
@end

/*
 * methods of structure gcg_msg_s
 */

unsigned gcg_msg_s::head_recognize(const char *string,unsigned &input_idx)
{/*{{{*/
#define GET_NEXT_CHAR() \
{\
  in_char = string[input_idx];\
}

#define CLOSE_CHAR(RET_TERM_IDX) \
{\
   if (in_char == '\0') {\
      return RET_TERM_IDX;\
   }\
\
   input_idx++;\
}

   unsigned char in_char;

// - STATE 0 -
   GET_NEXT_CHAR();

   if (in_char >= 9 && in_char < 11)
      goto state_3_label;

   if (in_char == 32)
      goto state_3_label;

   if (in_char == 34)
      goto state_1_label;

   if (in_char == 123)
      goto state_2_label;

   return c_idx_not_exist;

// - STATE 1 -
state_1_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 77)
      goto state_4_label;

   return c_idx_not_exist;

// - STATE 2 -
state_2_label:
   CLOSE_CHAR(0);
   GET_NEXT_CHAR();

   if (in_char >= 9 && in_char < 11)
      goto state_2_label;

   if (in_char == 32)
      goto state_2_label;

   return 0;

// - STATE 3 -
state_3_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char >= 9 && in_char < 11)
      goto state_3_label;

   if (in_char == 32)
      goto state_3_label;

   if (in_char == 123)
      goto state_2_label;

   return c_idx_not_exist;

// - STATE 4 -
state_4_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 68)
      goto state_5_label;

   return c_idx_not_exist;

// - STATE 5 -
state_5_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 72)
      goto state_6_label;

   return c_idx_not_exist;

// - STATE 6 -
state_6_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 101)
      goto state_7_label;

   return c_idx_not_exist;

// - STATE 7 -
state_7_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 97)
      goto state_8_label;

   return c_idx_not_exist;

// - STATE 8 -
state_8_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 100)
      goto state_9_label;

   return c_idx_not_exist;

// - STATE 9 -
state_9_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 101)
      goto state_10_label;

   return c_idx_not_exist;

// - STATE 10 -
state_10_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 114)
      goto state_11_label;

   return c_idx_not_exist;

// - STATE 11 -
state_11_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 34)
      goto state_12_label;

   return c_idx_not_exist;

// - STATE 12 -
state_12_label:
   CLOSE_CHAR(1);
   return 1;

}/*}}}*/

unsigned gcg_msg_s::tail_recognize(const char *string,int &input_idx)
{/*{{{*/
#define GET_PREV_CHAR() \
{\
   if (input_idx >= 0) {\
      in_char = string[input_idx];\
   }\
   else {\
      in_char = '\0';\
   }\
}

#define CLOSE_PREV_CHAR(RET_TERM_IDX) \
{\
   if (in_char == '\0') {\
      return RET_TERM_IDX;\
   }\
\
   input_idx--;\
}

   unsigned char in_char;

// - STATE 0 -
   GET_PREV_CHAR();

   if (in_char >= 9 && in_char < 11)
      goto state_4_label;

   if (in_char == 32)
      goto state_4_label;

   if (in_char >= 48 && in_char < 58)
      goto state_1_label;

   if (in_char == 58)
      goto state_2_label;

   if (in_char >= 65 && in_char < 71)
      goto state_1_label;

   if (in_char >= 97 && in_char < 103)
      goto state_1_label;

   if (in_char == 125)
      goto state_3_label;

   return c_idx_not_exist;

// - STATE 1 -
state_1_label:
   CLOSE_PREV_CHAR(1);
   GET_PREV_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_1_label;

   if (in_char >= 65 && in_char < 71)
      goto state_1_label;

   if (in_char >= 97 && in_char < 103)
      goto state_1_label;

   return 1;

// - STATE 2 -
state_2_label:
   CLOSE_PREV_CHAR(c_idx_not_exist);
   GET_PREV_CHAR();

   if (in_char >= 9 && in_char < 11)
      goto state_2_label;

   if (in_char == 32)
      goto state_2_label;

   if (in_char == 34)
      goto state_5_label;

   return c_idx_not_exist;

// - STATE 3 -
state_3_label:
   CLOSE_PREV_CHAR(0);
   GET_PREV_CHAR();

   if (in_char >= 9 && in_char < 11)
      goto state_3_label;

   if (in_char == 32)
      goto state_3_label;

   return 0;

// - STATE 4 -
state_4_label:
   CLOSE_PREV_CHAR(c_idx_not_exist);
   GET_PREV_CHAR();

   if (in_char >= 9 && in_char < 11)
      goto state_4_label;

   if (in_char == 32)
      goto state_4_label;

   if (in_char == 58)
      goto state_2_label;

   if (in_char == 125)
      goto state_3_label;

   return c_idx_not_exist;

// - STATE 5 -
state_5_label:
   CLOSE_PREV_CHAR(c_idx_not_exist);
   GET_PREV_CHAR();

   if (in_char == 83)
      goto state_6_label;

   return c_idx_not_exist;

// - STATE 6 -
state_6_label:
   CLOSE_PREV_CHAR(c_idx_not_exist);
   GET_PREV_CHAR();

   if (in_char == 67)
      goto state_7_label;

   return c_idx_not_exist;

// - STATE 7 -
state_7_label:
   CLOSE_PREV_CHAR(c_idx_not_exist);
   GET_PREV_CHAR();

   if (in_char == 70)
      goto state_8_label;

   return c_idx_not_exist;

// - STATE 8 -
state_8_label:
   CLOSE_PREV_CHAR(c_idx_not_exist);
   GET_PREV_CHAR();

   if (in_char == 100)
      goto state_9_label;

   return c_idx_not_exist;

// - STATE 9 -
state_9_label:
   CLOSE_PREV_CHAR(c_idx_not_exist);
   GET_PREV_CHAR();

   if (in_char == 109)
      goto state_10_label;

   return c_idx_not_exist;

// - STATE 10 -
state_10_label:
   CLOSE_PREV_CHAR(c_idx_not_exist);
   GET_PREV_CHAR();

   if (in_char == 34)
      goto state_11_label;

   return c_idx_not_exist;

// - STATE 11 -
state_11_label:
   CLOSE_PREV_CHAR(c_idx_not_exist);
   GET_PREV_CHAR();

   if (in_char >= 9 && in_char < 11)
      goto state_11_label;

   if (in_char == 32)
      goto state_11_label;

   if (in_char == 44)
      goto state_12_label;

   return c_idx_not_exist;

// - STATE 12 -
state_12_label:
   CLOSE_PREV_CHAR(2);
   GET_PREV_CHAR();

   if (in_char >= 9 && in_char < 11)
      goto state_12_label;

   if (in_char == 32)
      goto state_12_label;

   return 2;

}/*}}}*/

void gcg_msg_s::head_find(const char *string,unsigned &data_begin)
{/*{{{*/
  data_begin = c_idx_not_exist;

  unsigned input_idx = 0;
  unsigned term;

  term = head_recognize(string,input_idx);
  if (term != head_term_bracket) return;

  unsigned old_input_idx = input_idx;
  term = head_recognize(string,input_idx);
  if (term != head_term_header) return;

  data_begin = old_input_idx;
}/*}}}*/

void gcg_msg_s::tail_find(const char *string,unsigned length,unsigned &crc_begin,unsigned &data_end)
{/*{{{*/
  data_end = c_idx_not_exist;
  crc_begin = c_idx_not_exist;

  int input_idx = length - 1;
  unsigned term;

  term = tail_recognize(string,input_idx);
  if (term != tail_term_bracket) return;

  int old_input_idx = input_idx;
  term = tail_recognize(string,input_idx);
  if (term != tail_term_crc) return;

  // - check crc size -
  if (old_input_idx - input_idx != 8) return;
  crc_begin = input_idx + 1;

  term = tail_recognize(string,input_idx);
  if (term != tail_term_colon_fcs_comma) return;

  old_input_idx = input_idx;
  term = tail_recognize(string,input_idx);
  if (term != tail_term_bracket) return;

  data_end = old_input_idx;
}/*}}}*/

