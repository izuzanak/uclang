
#ifndef __LIGHTNING_PARSER_H
#define __LIGHTNING_PARSER_H

@begin
include "script_parser.h"
@end

#ifdef __cplusplus
  extern "C" {
#endif

#include <lightning.h>

#ifdef __cplusplus
  }
#endif

// - jit_state_t typedef -
typedef jit_state_t * jit_state_t_ptr;
@begin
define jit_state_t_ptr basic
@end

/*
 * constants and definitions
 */

// - value types -
const unsigned c_val_type_cnt = 12;
enum
{
  c_val_type_void = 0,
  c_val_type_i8,
  c_val_type_u8,
  c_val_type_i16,
  c_val_type_u16,
  c_val_type_i32,
  c_val_type_u32,
  c_val_type_i64,
  c_val_type_u64,
  c_val_type_f32,
  c_val_type_f64,
  c_val_type_ptr,
};

// - lightning type strings -
extern const char *c_type_strings[];
extern const unsigned c_type_str_lengths[];
extern const unsigned c_type_size[];
extern const unsigned c_type_conv_dist[][c_val_type_cnt];
extern const bool c_type_is_int[];

// - variable type modifiers -
enum
{
  c_val_modifier_variable  = 0x0001,
  c_val_modifier_parameter = 0x0002,
  c_val_modifier_constant  = 0x0004,
  c_val_modifier_temporary = 0x0008,
  c_val_modifier_reference = 0x0010,

  c_val_base_mask = 0x00ff,
};

// - intermediate operation codes -
enum
{
  im_insn_store = 0,

  im_insn_add,
  im_insn_sub,
  im_insn_mul,
  im_insn_div,
  im_insn_rem,

  im_insn_and,
  im_insn_or,
  im_insn_xor,
  im_insn_not,

  im_insn_shl,
  im_insn_shr,

  im_insn_neg,
  im_insn_to_bool,
  im_insn_to_not_bool,

  im_insn_eq,
  im_insn_ne,
  im_insn_le,
  im_insn_ge,
  im_insn_lt,
  im_insn_gt,

  im_insn_convert,
  im_insn_alloca,
  im_insn_address_of,

  im_insn_label,
  im_insn_branch,
  im_insn_branch_if,
  im_insn_branch_if_not,
  im_insn_call,

  im_insn_load_elem_address,
  im_insn_load_relative,
  im_insn_store_relative,
  im_insn_return,
};

// - LIGHTNING error identifiers -
enum
{
  c_error_LIGHTNING_PARSER_UNRECOGNIZED_TERMINAL = 0,
  c_error_LIGHTNING_PARSER_SYNTAX_ERROR,
};

/*
 * parse constants
 */
const unsigned c_ltg_rule_cnt = 122;
extern const unsigned ltg_rule_head_idxs[c_ltg_rule_cnt];
extern const unsigned ltg_rule_body_lengths[c_ltg_rule_cnt];

/*
 * LALR parse table
 */
#define ltg_blank c_idx_not_exist
#define LTG_SHIFT(VALUE) VALUE
#define LTG_REDUCE(VALUE) c_ltg_lalr_table_reduce_base + VALUE
#define LTG_GOTO(VALUE) VALUE

const unsigned c_ltg_lalr_table_reduce_base = 0x80000000;
const unsigned c_ltg_terminal_plus_nonterminal_cnt = 115;
const unsigned ltg_lalr_state_cnt = 207;

extern const unsigned ltg_lalr_table[ltg_lalr_state_cnt*c_ltg_terminal_plus_nonterminal_cnt];

/*
 * definition of generated structures
 */

// -- val_type_s --
@begin
struct
<
unsigned:type_id
unsigned:pointer_level
unsigned:modifiers
>

additions
{
  inline bool are_comparable(val_type_s &a_src);
  inline bool are_assignable(val_type_s &a_src);
  inline bool is_temp_const();
  inline bool is_integer();
  inline bool is_pointer();
  inline unsigned jit_type();
  inline unsigned jit_pointed_type();
}

val_type_s;
@end

// -- val_types_s --
@begin
array<val_type_s> val_types_s;
@end

// -- val_record_s --
@begin
struct
<
val_type_s:type
v_data_type:value
unsigned:live_start
unsigned:live_end
>

additions
{
  inline bool are_comparable(val_record_s &a_src);
  inline bool are_assignable(val_record_s &a_src);
  inline bool is_temp_const();
  inline bool is_integer();
  inline bool is_pointer();
  inline unsigned jit_type();
  inline unsigned jit_pointed_type();
  inline void update_live(unsigned a_position);

  inline unsigned res_type_id(val_record_s &a_second);
}

val_record_s;
@end

// -- val_records_s --
@begin
array<val_record_s> val_records_s;
@end

// -- fun_record_s --
@begin
struct
<
string_s:name
val_type_s:ret_type
val_types_s:param_types
>
fun_record_s;
@end

// -- fun_records_s --
@begin
array<fun_record_s> fun_records_s;
@end

// -- ltg_parser_s --
@begin
struct
<
$// - interpreter thread pointer -
pointer:it_ptr

$// - ucl jit state pointer -
pointer:ucl_jit_state

$// - jit state pointer -
jit_state_t_ptr:_jit

$// - function ucl signature -
string_s:ucl_signature

$// - code source string -
string_s:source_string

$// - variable names -
string_rb_tree_s:val_names

$// - value records -
val_records_s:val_records

$// - function record -
fun_record_s:fun_record

$// - expression stack -
ui_array_s:exp_values

$// - intermediate code -
ui_array_s:intermediate_code

$// - TEMPORARY PARSE VARIABLES -

$// - value modifier -
unsigned:tmp_modifiers

$// - value types stack -
val_types_s:tmp_val_types

$// - parameter record indexes -
ui_array_s:fun_param_idxs
name_pos_s:fun_name_pos

$// - block variables -
ui_array_s:block_var_idxs
ui_array_s:block_var_bases

$// - parse, old index of lexical analyzer -
unsigned:old_input_idx

$// - parse, LALR stack -
lalr_stack_s:lalr_stack
>

additions
{
  static unsigned recognize_type(unsigned a_length,const char *a_data);
  static void create_signature(unsigned a_name_length,char *a_name_data,unsigned a_param_cnt,val_type_s **a_param_types,string_s &a_target);
  unsigned recognize_terminal(unsigned &input_idx);
  bool parse_source();

  void instr_getarg(unsigned a_type,int a_reg_trg,jit_node_t *a_arg_id);
  void instr_stxi(unsigned a_type,int a_offset,int a_reg_base,int a_reg_src);
  void instr_ldxi(unsigned a_type,int a_reg_trg,int a_reg_base,int a_offset);
  void instr_movr(unsigned a_type_trg,unsigned a_type_src,int a_reg_trg,int a_reg_src);
  void instr_movi(unsigned a_type_trg,unsigned a_type_src,int a_reg_trg,v_data_type a_value);
}

ltg_parser_s;
@end

/*
 * inline methods of generated structures
 */

// -- val_type_s --
@begin
inlines val_type_s
@end

inline bool val_type_s::are_comparable(val_type_s &a_second)
{/*{{{*/

  // - if target is basic type -
  if (pointer_level == 0)
  {
    return a_second.pointer_level == 0;
  }

  // - if target is pointer -
  else
  {
    return pointer_level == a_second.pointer_level && type_id == a_second.type_id;
  }
}/*}}}*/

inline bool val_type_s::are_assignable(val_type_s &a_src)
{/*{{{*/

  // - if target is constant -
  if (is_temp_const())
  {
    return false;
  }

  return are_comparable(a_src);
}/*}}}*/

inline bool val_type_s::is_temp_const()
{/*{{{*/
  return modifiers & (c_val_modifier_constant | c_val_modifier_temporary);
}/*}}}*/

inline bool val_type_s::is_integer()
{/*{{{*/
  return c_type_is_int[type_id];
}/*}}}*/

inline bool val_type_s::is_pointer()
{/*{{{*/
  return pointer_level > 0;
}/*}}}*/

inline unsigned val_type_s::jit_type()
{/*{{{*/
  return pointer_level == 0 ? type_id : c_val_type_ptr;
}/*}}}*/

inline unsigned val_type_s::jit_pointed_type()
{/*{{{*/
  debug_assert(pointer_level > 0);
  return pointer_level <= 1 ? type_id : c_val_type_ptr;
}/*}}}*/

// -- val_types_s --
@begin
inlines val_types_s
@end

// -- val_record_s --
@begin
inlines val_record_s
@end

inline bool val_record_s::are_comparable(val_record_s &a_second)
{/*{{{*/
  return type.are_comparable(a_second.type);
}/*}}}*/

inline bool val_record_s::are_assignable(val_record_s &a_src)
{/*{{{*/
  return type.are_assignable(a_src.type);
}/*}}}*/

inline bool val_record_s::is_temp_const()
{/*{{{*/
  return type.is_temp_const();
}/*}}}*/

inline bool val_record_s::is_integer()
{/*{{{*/
  return type.is_integer();
}/*}}}*/

inline bool val_record_s::is_pointer()
{/*{{{*/
  return type.is_pointer();
}/*}}}*/

inline unsigned val_record_s::jit_type()
{/*{{{*/
  return type.jit_type();
}/*}}}*/

inline unsigned val_record_s::jit_pointed_type()
{/*{{{*/
  return type.jit_pointed_type();
}/*}}}*/

inline void val_record_s::update_live(unsigned a_position)
{/*{{{*/

  // - update live start -
  if (live_start == c_idx_not_exist)
  {
    live_start = a_position;
  }

  // - update live end -
  live_end = a_position;
}/*}}}*/

inline unsigned val_record_s::res_type_id(val_record_s &a_second)
{/*{{{*/
  return type.type_id > a_second.type.type_id ? type.type_id : a_second.type.type_id;
}/*}}}*/

// -- val_records_s --
@begin
inlines val_records_s
@end

// -- fun_record_s --
@begin
inlines fun_record_s
@end

// -- fun_records_s --
@begin
inlines fun_records_s
@end

// -- ltg_parser_s --
@begin
inlines ltg_parser_s
@end

@begin
include "lightning_parse_actions.h"
@end

#endif

