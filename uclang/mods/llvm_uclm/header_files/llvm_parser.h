
#ifndef __LLVM_PARSER_H
#define __LLVM_PARSER_H

@begin
include "script_parser.h"
@end

#include "llvm/IR/Verifier.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/Analysis/Passes.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/ExecutionEngine/JIT.h"
#include "llvm/PassManager.h"
#include "llvm/Support/TargetSelect.h"

using namespace llvm;

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

// - llvm type strings -
extern const char *c_type_strings[];
extern const unsigned c_type_str_lengths[];

// - variable type modifiers -
enum
{
  c_var_modifier_constant  = 0x01,
  c_var_modifier_temporary = 0x02,
  c_var_modifier_volatile  = 0x10,
  c_var_modifier_reference = 0x20,
};

// - LLVM error identifiers -
enum
{
  c_error_LLVM_PARSER_UNRECOGNIZED_TERMINAL = 0,
  c_error_LLVM_PARSER_SYNTAX_ERROR,
};

/*
 * parse constants
 */
const unsigned c_llvm_rule_cnt = 122;
extern const unsigned llvm_rule_head_idxs[c_llvm_rule_cnt];
extern const unsigned llvm_rule_body_lengths[c_llvm_rule_cnt];

/*
 * LALR parse table
 */
#define llvm_blank c_idx_not_exist
#define LLVM_SHIFT(VALUE) VALUE
#define LLVM_REDUCE(VALUE) c_llvm_lalr_table_reduce_base + VALUE
#define LLVM_GOTO(VALUE) VALUE

const unsigned c_llvm_lalr_table_reduce_base = 0x80000000;
const unsigned c_llvm_terminal_plus_nonterminal_cnt = 115;
const unsigned llvm_lalr_state_cnt = 207;

extern const unsigned llvm_lalr_table[llvm_lalr_state_cnt*c_llvm_terminal_plus_nonterminal_cnt];

/*
 * definition of generated structures
 */

// -- llvm_parser_s --
@begin
struct
<
$// - interpreter thread pointer -
pointer:it_ptr

$// - code source string -
string_s:source_string

$// - parse, old index of lexical analyzer -
unsigned:old_input_idx

$// - parse, LALR stack -
lalr_stack_s:lalr_stack
>

additions
{
  static unsigned recognize_type(unsigned a_length,const char *a_data);
  unsigned recognize_terminal(unsigned &input_idx);
  bool parse_source();
}

llvm_parser_s;
@end

/*
 * inline methods of generated structures
 */

// -- llvm_parser_s --
@begin
inlines llvm_parser_s
@end

@begin
include "llvm_parse_actions.h"
@end

#endif

