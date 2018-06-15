
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
extern const unsigned json_rule_head_idxs[c_json_rule_cnt];
extern const unsigned json_rule_body_lengths[c_json_rule_cnt];

#define json_blank c_idx_not_exist
#define JSON_SHIFT(VALUE) VALUE
#define JSON_REDUCE(VALUE) c_json_lalr_table_reduce_base + VALUE
#define JSON_GOTO(VALUE) VALUE

const unsigned c_json_lalr_table_reduce_base = 0x80000000;
const unsigned c_json_terminal_plus_nonterminal_cnt = 27;
const unsigned json_lalr_state_cnt = 32;

extern const unsigned json_lalr_table[json_lalr_state_cnt*c_json_terminal_plus_nonterminal_cnt];

// - JSON error identifiers -
enum
{
  c_error_JSON_CREATE_UNSUPPORTED_CLASS = 0,
  c_error_JSON_CREATE_NO_STRING_DICT_KEY,
  c_error_JSON_PARSE_ERROR,
};

/*
 * definition of structure json_creator_s
 */

struct json_creator_s
{
  static void append_string(string_s &a_string,bc_array_s &a_buffer);
  static unsigned create_nice(interpreter_thread_s &it,location_s *a_location,string_s &a_tabulator,string_s &a_indent,bc_array_s &a_buffer);
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

