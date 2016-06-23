
#ifndef __UCL_JSON_H
#define __UCL_JSON_H

/*
 * header files
 */

@begin
include "script_parser.h"
@end

/*
 * constants and definitions
 */

extern unsigned c_rm_class_dict;

const unsigned max_number_string_length = 128;

const unsigned c_json_rule_cnt = 24;
const unsigned json_rule_head_idxs[c_json_rule_cnt] = {14, 15, 16, 17, 17, 18, 19, 19, 20, 21, 22, 22, 23, 24, 24, 25, 25, 25, 25, 25, 25, 25, 25, 26, };
const unsigned json_rule_body_lengths[c_json_rule_cnt] = {1, 2, 2, 1, 2, 1, 3, 1, 3, 2, 1, 2, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };

#define json_blank c_idx_not_exist
#define JSON_SHIFT(VALUE) VALUE
#define JSON_REDUCE(VALUE) c_json_lalr_table_reduce_base + VALUE
#define JSON_GOTO(VALUE) VALUE

const unsigned c_json_lalr_table_reduce_base = 0x80000000;
const unsigned c_json_terminal_plus_nonterminal_cnt = 27;
const unsigned json_lalr_state_cnt = 32;

const unsigned json_lalr_table[json_lalr_state_cnt*c_json_terminal_plus_nonterminal_cnt] = {
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,    JSON_SHIFT(5),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,     JSON_GOTO(1),     JSON_GOTO(2),     JSON_GOTO(3),     JSON_GOTO(4),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,    JSON_SHIFT(6),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,    JSON_SHIFT(7),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
   JSON_SHIFT(11),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,   JSON_REDUCE(3),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,     JSON_GOTO(8),     JSON_GOTO(9),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,    JSON_GOTO(10),
   JSON_REDUCE(5),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,   JSON_REDUCE(5),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,   JSON_REDUCE(2),       json_blank,   JSON_REDUCE(2),   JSON_REDUCE(2),       json_blank,       json_blank,   JSON_REDUCE(2),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,   JSON_REDUCE(4),       json_blank,       json_blank,   JSON_SHIFT(12),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,   JSON_REDUCE(7),       json_blank,       json_blank,   JSON_REDUCE(7),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,   JSON_SHIFT(13),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,  JSON_REDUCE(23),       json_blank,  JSON_REDUCE(23),  JSON_REDUCE(23),  JSON_REDUCE(23),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
   JSON_SHIFT(11),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,    JSON_GOTO(14),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,    JSON_GOTO(10),
   JSON_SHIFT(11),   JSON_SHIFT(17),   JSON_SHIFT(18),   JSON_SHIFT(21),   JSON_SHIFT(22),   JSON_SHIFT(23),    JSON_SHIFT(5),       json_blank,   JSON_SHIFT(26),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,    JSON_GOTO(19),     JSON_GOTO(3),     JSON_GOTO(4),       json_blank,       json_blank,    JSON_GOTO(20),    JSON_GOTO(24),    JSON_GOTO(25),       json_blank,    JSON_GOTO(15),    JSON_GOTO(16),
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,   JSON_REDUCE(6),       json_blank,       json_blank,   JSON_REDUCE(6),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,   JSON_REDUCE(8),       json_blank,       json_blank,   JSON_REDUCE(8),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,  JSON_REDUCE(15),       json_blank,  JSON_REDUCE(15),  JSON_REDUCE(15),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,  JSON_REDUCE(16),       json_blank,  JSON_REDUCE(16),  JSON_REDUCE(16),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,  JSON_REDUCE(17),       json_blank,  JSON_REDUCE(17),  JSON_REDUCE(17),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,  JSON_REDUCE(18),       json_blank,  JSON_REDUCE(18),  JSON_REDUCE(18),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,  JSON_REDUCE(19),       json_blank,  JSON_REDUCE(19),  JSON_REDUCE(19),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,  JSON_REDUCE(20),       json_blank,  JSON_REDUCE(20),  JSON_REDUCE(20),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,  JSON_REDUCE(21),       json_blank,  JSON_REDUCE(21),  JSON_REDUCE(21),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,  JSON_REDUCE(22),       json_blank,  JSON_REDUCE(22),  JSON_REDUCE(22),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,   JSON_SHIFT(27),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
   JSON_SHIFT(11),   JSON_SHIFT(17),   JSON_SHIFT(18),   JSON_SHIFT(21),   JSON_SHIFT(22),   JSON_SHIFT(23),    JSON_SHIFT(5),       json_blank,   JSON_SHIFT(26),  JSON_REDUCE(10),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,    JSON_GOTO(19),     JSON_GOTO(3),     JSON_GOTO(4),       json_blank,       json_blank,    JSON_GOTO(20),    JSON_GOTO(24),    JSON_GOTO(25),    JSON_GOTO(28),    JSON_GOTO(29),    JSON_GOTO(16),
  JSON_REDUCE(12),  JSON_REDUCE(12),  JSON_REDUCE(12),  JSON_REDUCE(12),  JSON_REDUCE(12),  JSON_REDUCE(12),  JSON_REDUCE(12),       json_blank,  JSON_REDUCE(12),  JSON_REDUCE(12),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,   JSON_REDUCE(9),       json_blank,   JSON_REDUCE(9),   JSON_REDUCE(9),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,  JSON_REDUCE(11),   JSON_SHIFT(30),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,  JSON_REDUCE(14),  JSON_REDUCE(14),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
   JSON_SHIFT(11),   JSON_SHIFT(17),   JSON_SHIFT(18),   JSON_SHIFT(21),   JSON_SHIFT(22),   JSON_SHIFT(23),    JSON_SHIFT(5),       json_blank,   JSON_SHIFT(26),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,    JSON_GOTO(19),     JSON_GOTO(3),     JSON_GOTO(4),       json_blank,       json_blank,    JSON_GOTO(20),    JSON_GOTO(24),    JSON_GOTO(25),       json_blank,    JSON_GOTO(31),    JSON_GOTO(16),
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,  JSON_REDUCE(13),  JSON_REDUCE(13),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
};

/*
 * definition of structure json_creator_s
 */

struct json_creator_s
{
  static void append_string(string_s &a_string,bc_array_s &a_buffer);
};

/*
 * definition of generated structures
 */

// -- cs_element_s --
@begin
struct
<
pointer:location_ptr
bool:initialize
unsigned:index
>
cs_element_s;
@end

// -- create_stack_s --
@begin
array<cs_element_s> create_stack_s;
@end

// -- json_parser_s --
@begin
struct
<
pointer:it_ptr
string_s:source_string

unsigned:old_input_idx

lli_rb_tree_s:const_integers
bd_rb_tree_s:const_floats
string_rb_tree_s:const_strings

pointer:true_location
pointer:false_location
pointer_array_s:integer_locations
pointer_array_s:float_locations
pointer_array_s:string_locations

ui_array_s:string_idxs

pointer_array_s:values
pointer_array_s:arrays
pointer_array_s:objects

lalr_stack_s:lalr_stack
>

additions
{
  // - return index of next terminal symbol (token) in input source -
  unsigned recognize_terminal(unsigned &a_input_idx);

  // - parse input string -
  bool parse_source(interpreter_thread_s &a_it,string_s &a_string);

  // - release interpreter locations -
  void release_locations();
}

  json_parser_s;
@end

/*
 * inline methods of generated structures
 */

// -- cs_element_s --
@begin
inlines cs_element_s
@end

// -- create_stack_s --
@begin
inlines create_stack_s
@end

// -- json_parser_s --
@begin
inlines json_parser_s
@end

#endif

