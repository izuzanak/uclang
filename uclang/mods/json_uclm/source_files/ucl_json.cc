
@begin
include "ucl_json.h"
include "json_parse_actions.h"
@end

/*
 * methods of structure json_creator_s
 */

void json_creator_s::append_string(string_s &a_string,bc_array_s &a_buffer)
{/*{{{*/
  if (a_string.size > 1)
  {
    char *ptr = a_string.data;
    char *ptr_end = ptr + a_string.size - 1;
    do {

      switch (*ptr)
      {
        case '\b':
          a_buffer.push('\\');
          a_buffer.push('b');
          break;
        case '\f':
          a_buffer.push('\\');
          a_buffer.push('f');
          break;
        case '\n':
          a_buffer.push('\\');
          a_buffer.push('n');
          break;
        case '\r':
          a_buffer.push('\\');
          a_buffer.push('r');
          break;
        case '\t':
          a_buffer.push('\\');
          a_buffer.push('t');
          break;
        case '\\':
          a_buffer.push('\\');
          a_buffer.push('\\');
          break;
        case '"':
          a_buffer.push('\\');
          a_buffer.push('"');
          break;
        default:
          a_buffer.push(*ptr);
      }

    } while(++ptr < ptr_end);
  }
}/*}}}*/

/*
 * methods of generated structures
 */

// -- cs_element_s --
@begin
methods cs_element_s
@end

// -- create_stack_s --
@begin
methods create_stack_s
@end

// -- json_parser_s --
@begin
methods json_parser_s
@end

unsigned json_parser_s::recognize_terminal(unsigned &a_input_idx)
{/*{{{*/
  unsigned source_string_length = source_string.size - 1;

#define JSON_GET_NEXT_CHAR() \
  {\
    if (a_input_idx < source_string_length) {\
      in_char = (unsigned char)source_string[a_input_idx];\
    }\
    else {\
      in_char = '\0';\
    }\
  }

#define JSON_CLOSE_CHAR(RET_TERM_IDX) \
  {\
    if (in_char == '\0') {\
      return RET_TERM_IDX;\
    }\
    \
    a_input_idx++;\
  }

   unsigned short in_char;

// - STATE 0 -
   JSON_GET_NEXT_CHAR();

   if (in_char == 0)
      goto state_1_label;

   if (in_char >= 9 && in_char < 11)
      goto state_15_label;

   if (in_char == 32)
      goto state_15_label;

   if (in_char == 34)
      goto state_2_label;

   if (in_char == 44)
      goto state_3_label;

   if (in_char == 45)
      goto state_4_label;

   if (in_char == 48)
      goto state_5_label;

   if (in_char >= 49 && in_char < 58)
      goto state_6_label;

   if (in_char == 58)
      goto state_7_label;

   if (in_char == 91)
      goto state_8_label;

   if (in_char == 93)
      goto state_9_label;

   if (in_char == 102)
      goto state_10_label;

   if (in_char == 110)
      goto state_11_label;

   if (in_char == 116)
      goto state_12_label;

   if (in_char == 123)
      goto state_13_label;

   if (in_char == 125)
      goto state_14_label;

   return c_idx_not_exist;

// - STATE 1 -
state_1_label:
   JSON_CLOSE_CHAR(13)
   return 13;

// - STATE 2 -
state_2_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char < 34)
      goto state_2_label;

   if (in_char == 34)
      goto state_16_label;

   if (in_char >= 35 && in_char < 92)
      goto state_2_label;

   if (in_char == 92)
      goto state_17_label;

   if (in_char >= 93 && in_char < 256)
      goto state_2_label;

   return c_idx_not_exist;

// - STATE 3 -
state_3_label:
   JSON_CLOSE_CHAR(10)
   return 10;

// - STATE 4 -
state_4_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char == 48)
      goto state_5_label;

   if (in_char >= 49 && in_char < 58)
      goto state_6_label;

   return c_idx_not_exist;

// - STATE 5 -
state_5_label:
   JSON_CLOSE_CHAR(1)
   JSON_GET_NEXT_CHAR();

   if (in_char == 46)
      goto state_18_label;

   if (in_char == 69)
      goto state_19_label;

   if (in_char == 101)
      goto state_19_label;

   return 1;

// - STATE 6 -
state_6_label:
   JSON_CLOSE_CHAR(1)
   JSON_GET_NEXT_CHAR();

   if (in_char == 46)
      goto state_18_label;

   if (in_char >= 48 && in_char < 58)
      goto state_6_label;

   if (in_char == 69)
      goto state_19_label;

   if (in_char == 101)
      goto state_19_label;

   return 1;

// - STATE 7 -
state_7_label:
   JSON_CLOSE_CHAR(11)
   return 11;

// - STATE 8 -
state_8_label:
   JSON_CLOSE_CHAR(8)
   return 8;

// - STATE 9 -
state_9_label:
   JSON_CLOSE_CHAR(9)
   return 9;

// - STATE 10 -
state_10_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char == 97)
      goto state_20_label;

   return c_idx_not_exist;

// - STATE 11 -
state_11_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char == 117)
      goto state_21_label;

   return c_idx_not_exist;

// - STATE 12 -
state_12_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char == 114)
      goto state_22_label;

   return c_idx_not_exist;

// - STATE 13 -
state_13_label:
   JSON_CLOSE_CHAR(6)
   return 6;

// - STATE 14 -
state_14_label:
   JSON_CLOSE_CHAR(7)
   return 7;

// - STATE 15 -
state_15_label:
   JSON_CLOSE_CHAR(12)
   JSON_GET_NEXT_CHAR();

   if (in_char >= 9 && in_char < 11)
      goto state_15_label;

   if (in_char == 32)
      goto state_15_label;

   return 12;

// - STATE 16 -
state_16_label:
   JSON_CLOSE_CHAR(0)
   return 0;

// - STATE 17 -
state_17_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char == 34)
      goto state_2_label;

   if (in_char == 47)
      goto state_2_label;

   if (in_char == 92)
      goto state_2_label;

   if (in_char == 98)
      goto state_2_label;

   if (in_char == 102)
      goto state_2_label;

   if (in_char == 110)
      goto state_2_label;

   if (in_char == 114)
      goto state_2_label;

   if (in_char == 116)
      goto state_2_label;

   if (in_char == 117)
      goto state_23_label;

   return c_idx_not_exist;

// - STATE 18 -
state_18_label:
   JSON_CLOSE_CHAR(2)
   JSON_GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_18_label;

   if (in_char == 69)
      goto state_19_label;

   if (in_char == 101)
      goto state_19_label;

   return 2;

// - STATE 19 -
state_19_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char == 43)
      goto state_24_label;

   if (in_char == 45)
      goto state_24_label;

   if (in_char >= 48 && in_char < 58)
      goto state_25_label;

   return c_idx_not_exist;

// - STATE 20 -
state_20_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char == 108)
      goto state_26_label;

   return c_idx_not_exist;

// - STATE 21 -
state_21_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char == 108)
      goto state_27_label;

   return c_idx_not_exist;

// - STATE 22 -
state_22_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char == 117)
      goto state_28_label;

   return c_idx_not_exist;

// - STATE 23 -
state_23_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_29_label;

   if (in_char >= 65 && in_char < 71)
      goto state_29_label;

   if (in_char >= 97 && in_char < 103)
      goto state_29_label;

   return c_idx_not_exist;

// - STATE 24 -
state_24_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_25_label;

   return c_idx_not_exist;

// - STATE 25 -
state_25_label:
   JSON_CLOSE_CHAR(2)
   JSON_GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_25_label;

   return 2;

// - STATE 26 -
state_26_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char == 115)
      goto state_30_label;

   return c_idx_not_exist;

// - STATE 27 -
state_27_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char == 108)
      goto state_31_label;

   return c_idx_not_exist;

// - STATE 28 -
state_28_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char == 101)
      goto state_32_label;

   return c_idx_not_exist;

// - STATE 29 -
state_29_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_33_label;

   if (in_char >= 65 && in_char < 71)
      goto state_33_label;

   if (in_char >= 97 && in_char < 103)
      goto state_33_label;

   return c_idx_not_exist;

// - STATE 30 -
state_30_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char == 101)
      goto state_34_label;

   return c_idx_not_exist;

// - STATE 31 -
state_31_label:
   JSON_CLOSE_CHAR(5)
   return 5;

// - STATE 32 -
state_32_label:
   JSON_CLOSE_CHAR(3)
   return 3;

// - STATE 33 -
state_33_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_35_label;

   if (in_char >= 65 && in_char < 71)
      goto state_35_label;

   if (in_char >= 97 && in_char < 103)
      goto state_35_label;

   return c_idx_not_exist;

// - STATE 34 -
state_34_label:
   JSON_CLOSE_CHAR(4)
   return 4;

// - STATE 35 -
state_35_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_2_label;

   if (in_char >= 65 && in_char < 71)
      goto state_2_label;

   if (in_char >= 97 && in_char < 103)
      goto state_2_label;

   return c_idx_not_exist;

}/*}}}*/

bool json_parser_s::parse_source(interpreter_thread_s &a_it,string_s &a_string)
{/*{{{*/
  it_ptr = &a_it;
  source_string.swap(a_string);

  old_input_idx = 0;

  true_location = NULL;
  false_location = NULL;

  lalr_stack.clear();
  lalr_stack.push(0);

  unsigned input_idx = 0;
  unsigned ret_term = c_idx_not_exist;

#define JSON_PARSE_SOURCE_RETURN() \
  source_string.swap(a_string);

  do
  {
    // - retrieve next terminal symbol -
    while (ret_term == c_idx_not_exist)
    {
      old_input_idx = input_idx;

      ret_term = recognize_terminal(input_idx);
      debug_message_6(fprintf(stderr,"json_parser: recognized terminal: %u\n",ret_term));

      // - PARSE ERROR unrecognized terminal -
      if (ret_term == c_idx_not_exist)
      {
        JSON_PARSE_SOURCE_RETURN();
        return false;
      }

      // - skipping of _SKIP_ terminals -
      if (ret_term == 12)
      {
        ret_term = c_idx_not_exist;
      }
    }

    // - retrieve action from table of actions -
    unsigned parse_action = json_lalr_table[lalr_stack.last().lalr_state*c_json_terminal_plus_nonterminal_cnt + ret_term];

    // - PARSE ERROR wrong syntax -
    if (parse_action == c_idx_not_exist)
    {
      JSON_PARSE_SOURCE_RETURN();
      return false;
    }

    // - action JSON_SHIFT -
    if (parse_action < c_json_lalr_table_reduce_base)
    {
      if (ret_term == 13)
      {
        break;
      }

      // - insertion of state, and terminal position in source string -
      lalr_stack.push(parse_action,old_input_idx,input_idx);
      ret_term = c_idx_not_exist;
    }

    // - action JSON_REDUCE-
    else
    {
      parse_action -= c_json_lalr_table_reduce_base;

      // - call function assigned to reduction -
      if (json_pa_callers[parse_action] != pa_json_null)
      {
        if (!json_pa_callers[parse_action](*this))
        {
          JSON_PARSE_SOURCE_RETURN();
          return false;
        }
      }

      // - remove rule body from lalr_stack -
      lalr_stack.used -= json_rule_body_lengths[parse_action];

      // - insert new automat state to stack -
      unsigned goto_val = json_lalr_table[lalr_stack.last().lalr_state*c_json_terminal_plus_nonterminal_cnt + json_rule_head_idxs[parse_action]];
      lalr_stack.push(goto_val);
    }

  }
  while(1);

  JSON_PARSE_SOURCE_RETURN();
  return true;
}/*}}}*/

void json_parser_s::release_locations()
{/*{{{*/
  interpreter_thread_s &it = *((interpreter_thread_s *)it_ptr);

  // - release true location -
  if (true_location != NULL)
  {
    it.release_location_ptr((location_s *)true_location);
  }

  // - release false location -
  if (false_location != NULL)
  {
    it.release_location_ptr((location_s *)false_location);
  }

  // - release integer locations -
  if (integer_locations.used != 0)
  {
    pointer *il_ptr = integer_locations.data;
    pointer *il_ptr_end = il_ptr + integer_locations.used;
    do {
      if (*il_ptr != NULL)
      {
        it.release_location_ptr((location_s *)*il_ptr);
      }
    } while(++il_ptr < il_ptr_end);
  }

  // - release float locations -
  if (float_locations.used != 0)
  {
    pointer *fl_ptr = float_locations.data;
    pointer *fl_ptr_end = fl_ptr + float_locations.used;
    do {
      if (*fl_ptr != NULL)
      {
        it.release_location_ptr((location_s *)*fl_ptr);
      }
    } while(++fl_ptr < fl_ptr_end);
  }

  // - release string locations -
  if (string_locations.used != 0)
  {
    pointer *sl_ptr = string_locations.data;
    pointer *sl_ptr_end = sl_ptr + string_locations.used;
    do {
      if (*sl_ptr != NULL)
      {
        it.release_location_ptr((location_s *)*sl_ptr);
      }
    } while(++sl_ptr < sl_ptr_end);
  }

  // - release values -
  if (values.used != 0)
  {
    pointer *v_ptr = values.data;
    pointer *v_ptr_end = v_ptr + values.used;
    do {
      it.release_location_ptr((location_s *)*v_ptr);
    } while(++v_ptr < v_ptr_end);
  }

  // - release arrays -
  if (arrays.used != 0)
  {
    pointer *a_ptr = arrays.data;
    pointer *a_ptr_end = a_ptr + arrays.used;
    do {
      it.release_location_ptr((location_s *)*a_ptr);
    } while(++a_ptr < a_ptr_end);
  }

  // - release objects -
  if (objects.used != 0)
  {
    pointer *o_ptr = objects.data;
    pointer *o_ptr_end = o_ptr + objects.used;
    do {
      it.release_location_ptr((location_s *)*o_ptr);
    } while(++o_ptr < o_ptr_end);
  }
}/*}}}*/

/*
 * global function
 */

