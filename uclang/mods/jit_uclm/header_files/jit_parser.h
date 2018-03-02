
#ifndef __JIT_PARSER_H
#define __JIT_PARSER_H

@begin
include "script_parser.h"
@end

#include "jit/jit.h"
#include "jit/jit-dump.h"

/*
 * constants and definitions
 */

// - variable types -
const unsigned c_var_type_cnt = 12;
enum
{
  c_var_type_void = 0,
  c_var_type_i8,
  c_var_type_u8,
  c_var_type_i16,
  c_var_type_u16,
  c_var_type_i32,
  c_var_type_u32,
  c_var_type_i64,
  c_var_type_u64,
  c_var_type_f32,
  c_var_type_f64,
  c_var_type_ptr,
};

// - jit type strings -
extern const char *c_type_strings[];
extern const unsigned c_type_str_lengths[];
extern const jit_type_t c_type_jit_types[];
extern const unsigned c_type_size_power[];
extern const unsigned c_type_conv_dist[][c_var_type_cnt];
extern const bool c_type_is_int[];

// - variable type modifiers -
enum
{
  c_var_modifier_constant  = 0x01,
  c_var_modifier_temporary = 0x02,
  c_var_modifier_volatile  = 0x10,
  c_var_modifier_reference = 0x20,
};

// - JIT error identifiers -
enum
{
  c_error_JIT_PARSER_UNRECOGNIZED_TERMINAL = 0,
  c_error_JIT_PARSER_SYNTAX_ERROR,
  c_error_JIT_PARSER_DUPLICIT_FUNCTION_DEFINITION,
  c_error_JIT_PARSER_DUPLICIT_PARAMETER_IDENTIFIER,
  c_error_JIT_PARSER_DUPLICIT_VAR_PARAM_IDENTIFIER,
  c_error_JIT_PARSER_DUPLICIT_LABEL,
  c_error_JIT_PARSER_UNKNOWN_DATA_TYPE,
  c_error_JIT_PARSER_UNDECLARED_VARIABLE,
  c_error_JIT_PARSER_UNDECLARED_FUNCTION,
  c_error_JIT_PARSER_INCOMPATIBLE_VALUE_TYPES,
  c_error_JIT_PARSER_USED_UNDEFINED_LABEL,

  c_error_JIT_CONTEXT_CREATE_ERROR,
  c_error_JIT_FUNCTION_PARAM_WRONG_COUNT,
  c_error_JIT_FUNCTION_PARAM_POINTER_NOT_SUPPORTED,
  c_error_JIT_FUNCTION_PARAM_WRONG_TYPE,
  c_error_JIT_FUNCTION_PARAM_UNSUPPORTED_TYPE,
};

/*
 * parse constants
 */
const unsigned c_jit_rule_cnt = 124;
extern const unsigned jit_rule_head_idxs[c_jit_rule_cnt];
extern const unsigned jit_rule_body_lengths[c_jit_rule_cnt];

/*
 * LALR parse table
 */
#define jit_blank c_idx_not_exist
#define JIT_SHIFT(VALUE) VALUE
#define JIT_REDUCE(VALUE) c_jit_lalr_table_reduce_base + VALUE
#define JIT_GOTO(VALUE) VALUE

const unsigned c_jit_lalr_table_reduce_base = 0x80000000;
const unsigned c_jit_terminal_plus_nonterminal_cnt = 116;
const unsigned jit_lalr_state_cnt = 212;

extern const unsigned jit_lalr_table[jit_lalr_state_cnt*c_jit_terminal_plus_nonterminal_cnt];

/*
 * definition of generated structures
 */

// - define jit label type -
@begin
define jit_label_t basic
@end

// -- label_array_s --
@begin
array<jit_label_t> label_array_s;
@end

// -- var_type_s --
@begin
struct
<
unsigned:type_id
unsigned:pointer_level
unsigned:modifiers
>

additions
{
  inline bool are_comparable(var_type_s &a_src);
  inline bool are_assignable(var_type_s &a_src);
  inline bool is_temp_const();
  inline bool is_pointer();
  inline jit_type_t jit_type();
  inline jit_type_t jit_pointed_type();
}

var_type_s;
@end

// -- var_types_s --
@begin
array<var_type_s> var_types_s;
@end

// -- var_record_s --
@begin
struct
<
var_type_s:type
pointer:value
>
var_record_s;
@end

// -- var_records_s --
@begin
array<var_record_s> var_records_s;
@end

// -- fun_record_s --
@begin
struct
<
string_s:name
var_type_s:ret_type
var_types_s:param_types
pointer:jit_function
>
fun_record_s;
@end

// -- fun_records_s --
@begin
array<fun_record_s> fun_records_s;
@end

// -- exp_node_s --
@begin
struct
<
var_type_s:type
pointer:value
>

additions
{
  inline bool are_comparable(exp_node_s &a_src);
  inline bool are_assignable(exp_node_s &a_src);
  inline bool is_temp_const();
  inline bool is_integer();
  inline bool is_pointer();
  inline jit_type_t jit_type();
  inline jit_type_t jit_pointed_type();
  inline int pointed_size_power();

  inline unsigned res_type_id(exp_node_s &a_second);
  inline jit_value_t load_value(jit_function_t jit_function);
  inline void store_value(jit_function_t jit_function,jit_value_t a_value);
}

exp_node_s;
@end

// -- exp_nodes_s --
@begin
array<exp_node_s> exp_nodes_s;
@end

// -- jit_parser_s --
@begin
struct
<
$// - interpreter thread pointer -
pointer:it_ptr

$// - context ucl pointer -
pointer:ucl_context

$// - function jit pointer -
pointer:jit_function

$// - function ucl signature -
string_s:ucl_signature

$// - code source string -
string_s:source_string

$// - variable names -
string_rb_tree_s:var_names

$// - variable records -
var_records_s:var_records

$// - function record -
fun_record_s:fun_record

$// - variable modifier -
unsigned:tmp_modifiers

$// - variable types stack -
var_types_s:tmp_var_types

$// - parameter record indexes -
ui_array_s:fun_param_idxs
name_pos_s:fun_name_pos

$// - fun call parameter count -
ui_array_s:param_cnt
ui_array_s:function_idxs

$// - expression stack -
exp_nodes_s:exp_node_stack

$// - label names -
string_rb_tree_s:label_names
ui_array_s:named_label_idxs

$// - label stack -
label_array_s:labels
ui_array_s:label_idxs
ui_array_s:cb_label_idxs

$// - block variables -
ui_array_s:variable_idxs
ui_array_s:block_var_bases

$// - parse, old index of lexical analyzer -
unsigned:old_input_idx

$// - parse, LALR stack -
lalr_stack_s:lalr_stack
>

additions
{
static unsigned recognize_type(unsigned a_length,const char *a_data);
static void create_signature(unsigned a_name_length,char *a_name_data,unsigned a_param_cnt,var_type_s **a_param_types,string_s &a_target);
unsigned recognize_terminal(unsigned &input_idx);
bool parse_source();
}

jit_parser_s;
@end

/*
 * inline methods of generated structures
 */

// -- label_array_s --
@begin
inlines label_array_s
@end

// -- var_type_s --
@begin
inlines var_type_s
@end

inline bool var_type_s::are_comparable(var_type_s &a_second)
{/*{{{*/

  // - if target is basic type -
  if (pointer_level == 0)
  {
    return a_second.pointer_level == 0;
  }

  // - target is pointer -
  return pointer_level == a_second.pointer_level && type_id == a_second.type_id;
}/*}}}*/

inline bool var_type_s::are_assignable(var_type_s &a_src)
{/*{{{*/

  // - if target is constant -
  if (is_temp_const())
  {
    return false;
  }

  return are_comparable(a_src);
}/*}}}*/

inline bool var_type_s::is_temp_const()
{/*{{{*/
  return modifiers & (c_var_modifier_constant | c_var_modifier_temporary);
}/*}}}*/

inline bool var_type_s::is_pointer()
{/*{{{*/
  return pointer_level > 0;
}/*}}}*/

inline jit_type_t var_type_s::jit_type()
{/*{{{*/
  return pointer_level == 0 ? c_type_jit_types[type_id] : jit_type_void_ptr;
}/*}}}*/

inline jit_type_t var_type_s::jit_pointed_type()
{/*{{{*/
  debug_assert(pointer_level > 0);
  return pointer_level <= 1 ? c_type_jit_types[type_id] : jit_type_void_ptr;
}/*}}}*/

// -- var_types_s --
@begin
inlines var_types_s
@end

// -- var_record_s --
@begin
inlines var_record_s
@end

// -- var_records_s --
@begin
inlines var_records_s
@end

// -- fun_record_s --
@begin
inlines fun_record_s
@end

// -- fun_records_s --
@begin
inlines fun_records_s
@end

// -- exp_node_s --
@begin
inlines exp_node_s
@end

inline bool exp_node_s::are_comparable(exp_node_s &a_second)
{/*{{{*/
  return type.are_comparable(a_second.type);
}/*}}}*/

inline bool exp_node_s::are_assignable(exp_node_s &a_src)
{/*{{{*/
  return type.are_assignable(a_src.type);
}/*}}}*/

inline bool exp_node_s::is_temp_const()
{/*{{{*/
  return type.is_temp_const();
}/*}}}*/

inline bool exp_node_s::is_integer()
{/*{{{*/
  return c_type_is_int[type.type_id];
}/*}}}*/

inline bool exp_node_s::is_pointer()
{/*{{{*/
  return type.is_pointer();
}/*}}}*/

inline jit_type_t exp_node_s::jit_type()
{/*{{{*/
  return type.jit_type();
}/*}}}*/

inline jit_type_t exp_node_s::jit_pointed_type()
{/*{{{*/
  return type.jit_pointed_type();
}/*}}}*/

inline int exp_node_s::pointed_size_power()
{/*{{{*/
  debug_assert(type.pointer_level > 0);
  return type.pointer_level <= 1 ? c_type_size_power[type.type_id] : c_type_size_power[c_var_type_ptr];
}/*}}}*/

inline unsigned exp_node_s::res_type_id(exp_node_s &a_second)
{/*{{{*/
  return type.type_id > a_second.type.type_id ? type.type_id : a_second.type.type_id;
}/*}}}*/

inline jit_value_t exp_node_s::load_value(jit_function_t jit_function)
{/*{{{*/

  // - if source is reference -
  if (type.modifiers & c_var_modifier_reference)
  {
    return jit_insn_load_relative(jit_function,(jit_value_t)value,0,jit_type());
  }
  else
  {
    return (jit_value_t)value;
  }
}/*}}}*/

inline void exp_node_s::store_value(jit_function_t jit_function,jit_value_t a_value)
{/*{{{*/

  // - if target is reference -
  if (type.modifiers & c_var_modifier_reference)
  {
    jit_type_t trg_type = jit_type();

    // - if type of value differs from type of target -
    if (jit_value_get_type(a_value) != trg_type)
    {
      jit_value_t tmp_value = jit_insn_convert(jit_function,a_value,trg_type,0);
      jit_insn_store_relative(jit_function,(jit_value_t)value,0,tmp_value);
    }
    else
    {
      jit_insn_store_relative(jit_function,(jit_value_t)value,0,a_value);
    }
  }
  else
  {
    jit_insn_store(jit_function,(jit_value_t)value,a_value);
  }
}/*}}}*/

// -- exp_nodes_s --
@begin
inlines exp_nodes_s
@end

// -- jit_parser_s --
@begin
inlines jit_parser_s
@end

@begin
include "jit_parse_actions.h"
@end

#endif

