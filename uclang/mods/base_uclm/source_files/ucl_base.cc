
@begin
include "ucl_base.h"
@end

/*
 * global functions
 */

unsigned sf_terminal_recognize(char **a_ptr) // lgtm [cpp/use-of-goto]
{/*{{{*/
#define SF_GET_NEXT_CHAR() in_char = **a_ptr;
#define SF_CLOSE_CHAR(RET_TERM_IDX) ++(*a_ptr);

   unsigned char in_char;

// - STATE 0 -
   SF_GET_NEXT_CHAR();

   if (in_char == 32) {
      goto state_1_label;
   }
   if (in_char == 35) {
      goto state_1_label;
   }
   if (in_char == 37) {
      goto state_2_label;
   }
   if (in_char == 42) {
      goto state_3_label;
   }
   if (in_char == 43) {
      goto state_1_label;
   }
   if (in_char == 45) {
      goto state_4_label;
   }
   if (in_char == 46) {
      goto state_5_label;
   }
   if (in_char == 48) {
      goto state_6_label;
   }
   if (in_char >= 49 && in_char < 58) {
      goto state_7_label;
   }
   if (in_char >= 69 && in_char < 72) {
      goto state_8_label;
   }
   if (in_char == 88) {
      goto state_9_label;
   }
   if (in_char == 99) {
      goto state_10_label;
   }
   if (in_char == 100) {
      goto state_9_label;
   }
   if (in_char >= 101 && in_char < 104) {
      goto state_8_label;
   }
   if (in_char == 105) {
      goto state_9_label;
   }
   if (in_char == 111) {
      goto state_9_label;
   }
   if (in_char == 115) {
      goto state_11_label;
   }
   if (in_char == 120) {
      goto state_9_label;
   }
   return c_idx_not_exist;

// - STATE 1 -
state_1_label:
   SF_CLOSE_CHAR(1);
   SF_GET_NEXT_CHAR();

   if (in_char == 32) {
      goto state_1_label;
   }
   if (in_char == 35) {
      goto state_1_label;
   }
   if (in_char == 43) {
      goto state_1_label;
   }
   if (in_char == 45) {
      goto state_1_label;
   }
   if (in_char == 48) {
      goto state_1_label;
   }
   return 1;

// - STATE 2 -
state_2_label:
   SF_CLOSE_CHAR(5);
   return 5;

// - STATE 3 -
state_3_label:
   SF_CLOSE_CHAR(3);
   return 3;

// - STATE 4 -
state_4_label:
   SF_CLOSE_CHAR(0);
   return 0;

// - STATE 5 -
state_5_label:
   SF_CLOSE_CHAR(4);
   return 4;

// - STATE 6 -
state_6_label:
   SF_CLOSE_CHAR(1);
   SF_GET_NEXT_CHAR();

   if (in_char == 32) {
      goto state_1_label;
   }
   if (in_char == 35) {
      goto state_1_label;
   }
   if (in_char == 43) {
      goto state_1_label;
   }
   if (in_char == 45) {
      goto state_1_label;
   }
   if (in_char == 48) {
      goto state_6_label;
   }
   if (in_char >= 49 && in_char < 58) {
      goto state_7_label;
   }
   return 1;

// - STATE 7 -
state_7_label:
   SF_CLOSE_CHAR(2);
   SF_GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_7_label;
   }
   return 2;

// - STATE 8 -
state_8_label:
   SF_CLOSE_CHAR(8);
   return 8;

// - STATE 9 -
state_9_label:
   SF_CLOSE_CHAR(7);
   return 7;

// - STATE 10 -
state_10_label:
   SF_CLOSE_CHAR(6);
   return 6;

// - STATE 11 -
state_11_label:
   SF_CLOSE_CHAR(9);
   return 9;

}/*}}}*/

