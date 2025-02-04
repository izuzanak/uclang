
@begin
include "ucl_lightning.h"
@end

/*
 * constants and definitions
 */

// - lightning type strings -
const char *c_type_strings[] =
{/*{{{*/
  "void",
  "i8",
  "u8",
  "i16",
  "u16",
  "i32",
  "u32",
  "i64",
  "u64",
  "f32",
  "f64",
  "ptr",
};/*}}}*/

const unsigned c_type_str_lengths[] =
{/*{{{*/
  4,
  2,
  2,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
};/*}}}*/

extern const unsigned c_type_size[] =
{/*{{{*/
  0,
  1,
  1,
  2,
  2,
  4,
  4,
  8,
  8,
  4,
  8,
  sizeof(pointer),
};/*}}}*/

extern const unsigned c_type_conv_dist[][c_val_type_cnt] =
{/*{{{*/
  //                 void,         i8,         u8,        i16,         u16,         i32,         u32,         i64,         u64,         f32,         f64,         ptr
  /* void */ { 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,  0xffffffff,  0xffffffff,  0xffffffff,  0xffffffff,  0xffffffff,  0xffffffff,  0xffffffff,  0xffffffff },
  /* i8   */ { 0xffffffff,          0,          2,          1,           2,           1,           2,           1,           2,           1,           1,  0xffffffff },
  /* u8   */ { 0xffffffff,          2,          0,          1,           1,           1,           1,           1,           1,           1,           1,  0xffffffff },
  /* i16  */ { 0xffffffff,          4,          4,          0,           2,           1,           2,           1,           2,           1,           1,  0xffffffff },
  /* u16  */ { 0xffffffff,          4,          4,          2,           0,           1,           1,           1,           1,           1,           1,  0xffffffff },
  /* i32  */ { 0xffffffff,          8,          8,          4,           4,           0,           2,           1,           2,           2,           1,  0xffffffff },
  /* u32  */ { 0xffffffff,          8,          8,          4,           4,           2,           0,           1,           1,           4,           1,  0xffffffff },
  /* i64  */ { 0xffffffff,         16,         16,          8,           8,           4,           4,           0,           2,           8,           4,  0xffffffff },
  /* u64  */ { 0xffffffff,         16,         16,          8,           8,           4,           4,           2,           0,           8,           4,  0xffffffff },
  /* f32  */ { 0xffffffff,         16,         16,          8,           8,           4,           4,           4,           4,           0,           1,  0xffffffff },
  /* f64  */ { 0xffffffff,         32,         32,         16,          16,           8,           8,           4,           4,           2,           0,  0xffffffff },
  /* ptr  */ { 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,  0xffffffff,  0xffffffff,  0xffffffff,  0xffffffff,  0xffffffff,  0xffffffff,  0xffffffff,           0 },
};/*}}}*/

extern const bool c_type_is_int[] =
{/*{{{*/
  false,
  true,
  true,
  true,
  true,
  true,
  true,
  true,
  true,
  false,
  false,
  false,
};/*}}}*/

/*
 * parse constants
 */

const unsigned ltg_rule_head_idxs[c_ltg_rule_cnt] = {71, 72, 72, 73, 75, 74, 76, 76, 77, 77, 78, 79, 79, 80, 81, 81, 82, 83, 83, 84, 85, 86, 86, 87, 87, 88, 88, 88, 89, 82, 90, 90, 91, 82, 92, 93, 93, 94, 82, 95, 96, 82, 97, 98, 82, 82, 82, 82, 99, 100, 101, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 108, 108, 108, 109, 109, 109, 109, 109, 109, 109, 110, 110, 110, 110, 111, 111, 111, 112, 112, 112, 113, 113, 113, 113, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 107, 102, 103, 114, 104, 104, 105, 106, 106, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, };
const unsigned ltg_rule_body_lengths[c_ltg_rule_cnt] = {1, 2, 1, 4, 3, 2, 1, 2, 3, 1, 2, 2, 1, 1, 2, 1, 2, 2, 2, 1, 1, 3, 1, 2, 1, 1, 3, 4, 1, 1, 2, 3, 1, 2, 2, 1, 2, 2, 3, 1, 1, 5, 1, 1, 2, 2, 3, 2, 3, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 3, 3, 1, 3, 3, 3, 3, 3, 3, 1, 3, 3, 3, 1, 3, 3, 1, 3, 3, 1, 3, 3, 3, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 4, 3, 1, 3, 2, 2, 3, 1, 2, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };

/*
 * LALR parse table
 */

const unsigned ltg_lalr_table[ltg_lalr_state_cnt*c_ltg_terminal_plus_nonterminal_cnt] =
{/*{{{*/
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_SHIFT(7),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_SHIFT(3),       ltg_blank,     LTG_GOTO(1),     LTG_GOTO(2),     LTG_GOTO(5),     LTG_GOTO(4),       ltg_blank,       ltg_blank,       ltg_blank,     LTG_GOTO(6),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_SHIFT(8),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_SHIFT(9),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(10),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(11),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(13),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(12),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(12),       ltg_blank,  LTG_REDUCE(12),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(12),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),   LTG_SHIFT(34),   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,   LTG_SHIFT(27),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(33),   LTG_SHIFT(29),       ltg_blank,   LTG_SHIFT(31),   LTG_SHIFT(30),   LTG_SHIFT(21),   LTG_SHIFT(22),   LTG_SHIFT(23),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(14),    LTG_GOTO(15),    LTG_GOTO(16),    LTG_GOTO(25),    LTG_GOTO(26),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(17),    LTG_GOTO(28),    LTG_GOTO(18),       ltg_blank,       ltg_blank,    LTG_GOTO(19),       ltg_blank,    LTG_GOTO(20),       ltg_blank,       ltg_blank,    LTG_GOTO(24),    LTG_GOTO(32),    LTG_GOTO(37),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(35),    LTG_GOTO(36),    LTG_GOTO(38),    LTG_GOTO(39),    LTG_GOTO(40),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_SHIFT(7),       ltg_blank,       ltg_blank,   LTG_SHIFT(67),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(66),    LTG_GOTO(68),    LTG_GOTO(69),    LTG_GOTO(70),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_REDUCE(5),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(11),       ltg_blank,  LTG_REDUCE(11),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(11),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(13),       ltg_blank,  LTG_REDUCE(13),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(13),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),   LTG_SHIFT(34),   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,   LTG_SHIFT(27),   LTG_SHIFT(72),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(33),   LTG_SHIFT(29),       ltg_blank,   LTG_SHIFT(31),   LTG_SHIFT(30),   LTG_SHIFT(21),   LTG_SHIFT(22),   LTG_SHIFT(23),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(71),    LTG_GOTO(16),    LTG_GOTO(25),    LTG_GOTO(26),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(17),    LTG_GOTO(28),    LTG_GOTO(18),       ltg_blank,       ltg_blank,    LTG_GOTO(19),       ltg_blank,    LTG_GOTO(20),       ltg_blank,       ltg_blank,    LTG_GOTO(24),    LTG_GOTO(32),    LTG_GOTO(37),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(35),    LTG_GOTO(36),    LTG_GOTO(38),    LTG_GOTO(39),    LTG_GOTO(40),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
  LTG_REDUCE(15),  LTG_REDUCE(15),  LTG_REDUCE(15),  LTG_REDUCE(15),  LTG_REDUCE(15),  LTG_REDUCE(15),  LTG_REDUCE(15),  LTG_REDUCE(15),  LTG_REDUCE(15),  LTG_REDUCE(15),  LTG_REDUCE(15),  LTG_REDUCE(15),  LTG_REDUCE(15),  LTG_REDUCE(15),  LTG_REDUCE(15),       ltg_blank,  LTG_REDUCE(15),  LTG_REDUCE(15),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(15),  LTG_REDUCE(15),       ltg_blank,  LTG_REDUCE(15),  LTG_REDUCE(15),  LTG_REDUCE(15),  LTG_REDUCE(15),  LTG_REDUCE(15),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(15),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(15),  LTG_REDUCE(15),       ltg_blank,  LTG_REDUCE(15),       ltg_blank,       ltg_blank,  LTG_REDUCE(15),  LTG_REDUCE(15),  LTG_REDUCE(15),       ltg_blank,       ltg_blank,  LTG_REDUCE(15),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(73),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
  LTG_REDUCE(29),  LTG_REDUCE(29),  LTG_REDUCE(29),  LTG_REDUCE(29),  LTG_REDUCE(29),  LTG_REDUCE(29),  LTG_REDUCE(29),  LTG_REDUCE(29),  LTG_REDUCE(29),  LTG_REDUCE(29),  LTG_REDUCE(29),  LTG_REDUCE(29),  LTG_REDUCE(29),  LTG_REDUCE(29),  LTG_REDUCE(29),       ltg_blank,  LTG_REDUCE(29),  LTG_REDUCE(29),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(29),  LTG_REDUCE(29),  LTG_REDUCE(29),  LTG_REDUCE(29),  LTG_REDUCE(29),  LTG_REDUCE(29),  LTG_REDUCE(29),  LTG_REDUCE(29),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(29),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(29),  LTG_REDUCE(29),       ltg_blank,  LTG_REDUCE(29),       ltg_blank,       ltg_blank,  LTG_REDUCE(29),  LTG_REDUCE(29),  LTG_REDUCE(29),       ltg_blank,       ltg_blank,  LTG_REDUCE(29),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),   LTG_SHIFT(34),   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,   LTG_SHIFT(27),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(33),   LTG_SHIFT(29),       ltg_blank,   LTG_SHIFT(31),   LTG_SHIFT(30),   LTG_SHIFT(21),   LTG_SHIFT(22),   LTG_SHIFT(23),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(75),    LTG_GOTO(16),    LTG_GOTO(25),    LTG_GOTO(26),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(17),    LTG_GOTO(28),    LTG_GOTO(18),    LTG_GOTO(74),    LTG_GOTO(76),    LTG_GOTO(19),       ltg_blank,    LTG_GOTO(20),       ltg_blank,       ltg_blank,    LTG_GOTO(24),    LTG_GOTO(32),    LTG_GOTO(37),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(35),    LTG_GOTO(36),    LTG_GOTO(38),    LTG_GOTO(39),    LTG_GOTO(40),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(79),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(77),       ltg_blank,       ltg_blank,    LTG_GOTO(78),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),   LTG_SHIFT(34),   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,   LTG_SHIFT(27),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(33),   LTG_SHIFT(29),       ltg_blank,   LTG_SHIFT(31),   LTG_SHIFT(30),   LTG_SHIFT(21),   LTG_SHIFT(22),   LTG_SHIFT(23),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(80),    LTG_GOTO(16),    LTG_GOTO(25),    LTG_GOTO(26),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(17),    LTG_GOTO(28),    LTG_GOTO(18),       ltg_blank,       ltg_blank,    LTG_GOTO(19),       ltg_blank,    LTG_GOTO(20),       ltg_blank,       ltg_blank,    LTG_GOTO(24),    LTG_GOTO(32),    LTG_GOTO(37),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(35),    LTG_GOTO(36),    LTG_GOTO(38),    LTG_GOTO(39),    LTG_GOTO(40),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(81),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(82),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(83),    LTG_GOTO(37),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(35),    LTG_GOTO(36),    LTG_GOTO(38),    LTG_GOTO(39),    LTG_GOTO(40),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(84),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(34),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(33),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(85),    LTG_GOTO(25),    LTG_GOTO(26),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(91),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(13),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(88),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(86),    LTG_GOTO(87),    LTG_GOTO(89),    LTG_GOTO(90),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
  LTG_REDUCE(32),  LTG_REDUCE(32),  LTG_REDUCE(32),  LTG_REDUCE(32),  LTG_REDUCE(32),  LTG_REDUCE(32),  LTG_REDUCE(32),  LTG_REDUCE(32),  LTG_REDUCE(32),  LTG_REDUCE(32),  LTG_REDUCE(32),  LTG_REDUCE(32),  LTG_REDUCE(32),  LTG_REDUCE(32),  LTG_REDUCE(32),       ltg_blank,  LTG_REDUCE(32),   LTG_SHIFT(92),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(32),  LTG_REDUCE(32),       ltg_blank,  LTG_REDUCE(32),  LTG_REDUCE(32),  LTG_REDUCE(32),  LTG_REDUCE(32),  LTG_REDUCE(32),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(32),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(32),  LTG_REDUCE(32),       ltg_blank,  LTG_REDUCE(32),       ltg_blank,       ltg_blank,  LTG_REDUCE(32),  LTG_REDUCE(32),  LTG_REDUCE(32),       ltg_blank,       ltg_blank,  LTG_REDUCE(32),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),   LTG_SHIFT(34),   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,   LTG_SHIFT(27),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(33),   LTG_SHIFT(29),       ltg_blank,   LTG_SHIFT(31),   LTG_SHIFT(30),   LTG_SHIFT(21),   LTG_SHIFT(22),   LTG_SHIFT(23),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(93),    LTG_GOTO(15),    LTG_GOTO(16),    LTG_GOTO(25),    LTG_GOTO(26),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(17),    LTG_GOTO(28),    LTG_GOTO(18),       ltg_blank,       ltg_blank,    LTG_GOTO(19),       ltg_blank,    LTG_GOTO(20),       ltg_blank,       ltg_blank,    LTG_GOTO(24),    LTG_GOTO(32),    LTG_GOTO(37),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(35),    LTG_GOTO(36),    LTG_GOTO(38),    LTG_GOTO(39),    LTG_GOTO(40),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(79),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(94),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(39),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
  LTG_REDUCE(42),  LTG_REDUCE(42),  LTG_REDUCE(42),  LTG_REDUCE(42),  LTG_REDUCE(42),  LTG_REDUCE(42),  LTG_REDUCE(42),  LTG_REDUCE(42),  LTG_REDUCE(42),  LTG_REDUCE(42),  LTG_REDUCE(42),  LTG_REDUCE(42),  LTG_REDUCE(42),  LTG_REDUCE(42),  LTG_REDUCE(42),       ltg_blank,  LTG_REDUCE(42),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(42),  LTG_REDUCE(42),       ltg_blank,  LTG_REDUCE(42),  LTG_REDUCE(42),  LTG_REDUCE(42),  LTG_REDUCE(42),  LTG_REDUCE(42),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(42),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(42),  LTG_REDUCE(42),       ltg_blank,  LTG_REDUCE(42),       ltg_blank,       ltg_blank,  LTG_REDUCE(42),  LTG_REDUCE(42),  LTG_REDUCE(42),       ltg_blank,       ltg_blank,  LTG_REDUCE(42),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(19),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(19),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(20),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(20),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(50),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(50),  LTG_REDUCE(50),  LTG_REDUCE(50),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(95),   LTG_SHIFT(96),   LTG_SHIFT(97),   LTG_SHIFT(98),   LTG_SHIFT(99),  LTG_SHIFT(100),  LTG_SHIFT(101),  LTG_SHIFT(102),  LTG_SHIFT(103),  LTG_SHIFT(104),  LTG_SHIFT(105),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_SHIFT(106),  LTG_REDUCE(50),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(62),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(62),  LTG_REDUCE(62),  LTG_REDUCE(62),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(62),  LTG_REDUCE(62),  LTG_REDUCE(62),  LTG_REDUCE(62),  LTG_REDUCE(62),  LTG_REDUCE(62),  LTG_REDUCE(62),  LTG_REDUCE(62),  LTG_REDUCE(62),  LTG_REDUCE(62),  LTG_REDUCE(62),  LTG_SHIFT(107),  LTG_SHIFT(108),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(62),  LTG_REDUCE(62),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(110),    LTG_GOTO(37),   LTG_GOTO(109),       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(35),    LTG_GOTO(36),    LTG_GOTO(38),    LTG_GOTO(39),    LTG_GOTO(40),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(65),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(65),  LTG_REDUCE(65),  LTG_REDUCE(65),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(65),  LTG_REDUCE(65),  LTG_REDUCE(65),  LTG_REDUCE(65),  LTG_REDUCE(65),  LTG_REDUCE(65),  LTG_REDUCE(65),  LTG_REDUCE(65),  LTG_REDUCE(65),  LTG_REDUCE(65),  LTG_REDUCE(65),  LTG_REDUCE(65),  LTG_REDUCE(65),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_SHIFT(111),  LTG_SHIFT(112),  LTG_SHIFT(113),  LTG_SHIFT(114),  LTG_SHIFT(115),  LTG_SHIFT(116),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(65),  LTG_REDUCE(65),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(72),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(72),  LTG_REDUCE(72),  LTG_REDUCE(72),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(72),  LTG_REDUCE(72),  LTG_REDUCE(72),  LTG_REDUCE(72),  LTG_REDUCE(72),  LTG_REDUCE(72),  LTG_REDUCE(72),  LTG_REDUCE(72),  LTG_REDUCE(72),  LTG_REDUCE(72),  LTG_REDUCE(72),  LTG_REDUCE(72),  LTG_REDUCE(72),  LTG_SHIFT(117),  LTG_SHIFT(118),  LTG_SHIFT(119),  LTG_REDUCE(72),  LTG_REDUCE(72),  LTG_REDUCE(72),  LTG_REDUCE(72),  LTG_REDUCE(72),  LTG_REDUCE(72),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(72),  LTG_REDUCE(72),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(76),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(76),  LTG_REDUCE(76),  LTG_REDUCE(76),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(76),  LTG_REDUCE(76),  LTG_REDUCE(76),  LTG_REDUCE(76),  LTG_REDUCE(76),  LTG_REDUCE(76),  LTG_REDUCE(76),  LTG_REDUCE(76),  LTG_REDUCE(76),  LTG_REDUCE(76),  LTG_REDUCE(76),  LTG_REDUCE(76),  LTG_REDUCE(76),  LTG_REDUCE(76),  LTG_REDUCE(76),  LTG_REDUCE(76),  LTG_REDUCE(76),  LTG_REDUCE(76),  LTG_REDUCE(76),  LTG_REDUCE(76),  LTG_REDUCE(76),  LTG_REDUCE(76),  LTG_SHIFT(120),  LTG_SHIFT(121),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(76),  LTG_REDUCE(76),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(79),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(79),  LTG_REDUCE(79),  LTG_REDUCE(79),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(79),  LTG_REDUCE(79),  LTG_REDUCE(79),  LTG_REDUCE(79),  LTG_REDUCE(79),  LTG_REDUCE(79),  LTG_REDUCE(79),  LTG_REDUCE(79),  LTG_REDUCE(79),  LTG_REDUCE(79),  LTG_REDUCE(79),  LTG_REDUCE(79),  LTG_REDUCE(79),  LTG_REDUCE(79),  LTG_REDUCE(79),  LTG_REDUCE(79),  LTG_REDUCE(79),  LTG_REDUCE(79),  LTG_REDUCE(79),  LTG_REDUCE(79),  LTG_REDUCE(79),  LTG_REDUCE(79),  LTG_REDUCE(79),  LTG_REDUCE(79),  LTG_SHIFT(122),  LTG_SHIFT(123),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(79),  LTG_REDUCE(79),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(82),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(82),  LTG_REDUCE(82),  LTG_REDUCE(82),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(82),  LTG_REDUCE(82),  LTG_REDUCE(82),  LTG_REDUCE(82),  LTG_REDUCE(82),  LTG_REDUCE(82),  LTG_REDUCE(82),  LTG_REDUCE(82),  LTG_REDUCE(82),  LTG_REDUCE(82),  LTG_REDUCE(82),  LTG_REDUCE(82),  LTG_REDUCE(82),  LTG_REDUCE(82),  LTG_REDUCE(82),  LTG_REDUCE(82),  LTG_REDUCE(82),  LTG_REDUCE(82),  LTG_REDUCE(82),  LTG_REDUCE(82),  LTG_REDUCE(82),  LTG_REDUCE(82),  LTG_REDUCE(82),  LTG_REDUCE(82),  LTG_REDUCE(82),  LTG_REDUCE(82),       ltg_blank,  LTG_SHIFT(124),  LTG_SHIFT(125),  LTG_SHIFT(126),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(82),  LTG_REDUCE(82),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(86),       ltg_blank,       ltg_blank,  LTG_SHIFT(129),  LTG_REDUCE(86),  LTG_REDUCE(86),  LTG_REDUCE(86),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(86),  LTG_REDUCE(86),  LTG_REDUCE(86),  LTG_REDUCE(86),  LTG_REDUCE(86),  LTG_REDUCE(86),  LTG_REDUCE(86),  LTG_REDUCE(86),  LTG_REDUCE(86),  LTG_REDUCE(86),  LTG_REDUCE(86),  LTG_REDUCE(86),  LTG_REDUCE(86),  LTG_REDUCE(86),  LTG_REDUCE(86),  LTG_REDUCE(86),  LTG_REDUCE(86),  LTG_REDUCE(86),  LTG_REDUCE(86),  LTG_REDUCE(86),  LTG_REDUCE(86),  LTG_REDUCE(86),  LTG_REDUCE(86),  LTG_REDUCE(86),  LTG_REDUCE(86),  LTG_REDUCE(86),       ltg_blank,  LTG_REDUCE(86),  LTG_REDUCE(86),  LTG_REDUCE(86),  LTG_SHIFT(127),  LTG_SHIFT(128),       ltg_blank,  LTG_REDUCE(86),  LTG_REDUCE(86),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(130),
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(131),
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(132),
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(133),
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(134),
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(135),
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(136),
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(137),
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),    LTG_SHIFT(7),   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(138),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(37),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(139),    LTG_GOTO(36),    LTG_GOTO(38),    LTG_GOTO(39),    LTG_GOTO(40),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_SHIFT(142), LTG_REDUCE(100),       ltg_blank,       ltg_blank, LTG_REDUCE(100), LTG_REDUCE(100), LTG_REDUCE(100), LTG_REDUCE(100),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(100), LTG_REDUCE(100), LTG_REDUCE(100), LTG_REDUCE(100), LTG_REDUCE(100), LTG_REDUCE(100), LTG_REDUCE(100), LTG_REDUCE(100), LTG_REDUCE(100), LTG_REDUCE(100), LTG_REDUCE(100), LTG_REDUCE(100), LTG_REDUCE(100), LTG_REDUCE(100), LTG_REDUCE(100), LTG_REDUCE(100), LTG_REDUCE(100), LTG_REDUCE(100), LTG_REDUCE(100), LTG_REDUCE(100), LTG_REDUCE(100), LTG_REDUCE(100), LTG_REDUCE(100), LTG_REDUCE(100), LTG_REDUCE(100), LTG_REDUCE(100),       ltg_blank, LTG_REDUCE(100), LTG_REDUCE(100), LTG_REDUCE(100), LTG_REDUCE(100), LTG_REDUCE(100),       ltg_blank, LTG_REDUCE(100), LTG_REDUCE(100),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(140),   LTG_GOTO(141),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(110),       ltg_blank,       ltg_blank, LTG_REDUCE(110), LTG_REDUCE(110), LTG_REDUCE(110), LTG_REDUCE(110),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(110), LTG_REDUCE(110), LTG_REDUCE(110), LTG_REDUCE(110), LTG_REDUCE(110), LTG_REDUCE(110), LTG_REDUCE(110), LTG_REDUCE(110), LTG_REDUCE(110), LTG_REDUCE(110), LTG_REDUCE(110), LTG_REDUCE(110), LTG_REDUCE(110), LTG_REDUCE(110), LTG_REDUCE(110), LTG_REDUCE(110), LTG_REDUCE(110), LTG_REDUCE(110), LTG_REDUCE(110), LTG_REDUCE(110), LTG_REDUCE(110), LTG_REDUCE(110), LTG_REDUCE(110), LTG_REDUCE(110), LTG_REDUCE(110), LTG_REDUCE(110),       ltg_blank, LTG_REDUCE(110), LTG_REDUCE(110), LTG_REDUCE(110), LTG_REDUCE(110), LTG_REDUCE(110),       ltg_blank, LTG_REDUCE(110), LTG_REDUCE(110),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(111),       ltg_blank,       ltg_blank, LTG_REDUCE(111), LTG_REDUCE(111), LTG_REDUCE(111), LTG_REDUCE(111),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(111), LTG_REDUCE(111), LTG_REDUCE(111), LTG_REDUCE(111), LTG_REDUCE(111), LTG_REDUCE(111), LTG_REDUCE(111), LTG_REDUCE(111), LTG_REDUCE(111), LTG_REDUCE(111), LTG_REDUCE(111), LTG_REDUCE(111), LTG_REDUCE(111), LTG_REDUCE(111), LTG_REDUCE(111), LTG_REDUCE(111), LTG_REDUCE(111), LTG_REDUCE(111), LTG_REDUCE(111), LTG_REDUCE(111), LTG_REDUCE(111), LTG_REDUCE(111), LTG_REDUCE(111), LTG_REDUCE(111), LTG_REDUCE(111), LTG_REDUCE(111),       ltg_blank, LTG_REDUCE(111), LTG_REDUCE(111), LTG_REDUCE(111), LTG_REDUCE(111), LTG_REDUCE(111),       ltg_blank, LTG_REDUCE(111), LTG_REDUCE(111),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(112),       ltg_blank,       ltg_blank, LTG_REDUCE(112), LTG_REDUCE(112), LTG_REDUCE(112), LTG_REDUCE(112),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(112), LTG_REDUCE(112), LTG_REDUCE(112), LTG_REDUCE(112), LTG_REDUCE(112), LTG_REDUCE(112), LTG_REDUCE(112), LTG_REDUCE(112), LTG_REDUCE(112), LTG_REDUCE(112), LTG_REDUCE(112), LTG_REDUCE(112), LTG_REDUCE(112), LTG_REDUCE(112), LTG_REDUCE(112), LTG_REDUCE(112), LTG_REDUCE(112), LTG_REDUCE(112), LTG_REDUCE(112), LTG_REDUCE(112), LTG_REDUCE(112), LTG_REDUCE(112), LTG_REDUCE(112), LTG_REDUCE(112), LTG_REDUCE(112), LTG_REDUCE(112),       ltg_blank, LTG_REDUCE(112), LTG_REDUCE(112), LTG_REDUCE(112), LTG_REDUCE(112), LTG_REDUCE(112),       ltg_blank, LTG_REDUCE(112), LTG_REDUCE(112),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(113),       ltg_blank,       ltg_blank, LTG_REDUCE(113), LTG_REDUCE(113), LTG_REDUCE(113), LTG_REDUCE(113),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(113), LTG_REDUCE(113), LTG_REDUCE(113), LTG_REDUCE(113), LTG_REDUCE(113), LTG_REDUCE(113), LTG_REDUCE(113), LTG_REDUCE(113), LTG_REDUCE(113), LTG_REDUCE(113), LTG_REDUCE(113), LTG_REDUCE(113), LTG_REDUCE(113), LTG_REDUCE(113), LTG_REDUCE(113), LTG_REDUCE(113), LTG_REDUCE(113), LTG_REDUCE(113), LTG_REDUCE(113), LTG_REDUCE(113), LTG_REDUCE(113), LTG_REDUCE(113), LTG_REDUCE(113), LTG_REDUCE(113), LTG_REDUCE(113), LTG_REDUCE(113),       ltg_blank, LTG_REDUCE(113), LTG_REDUCE(113), LTG_REDUCE(113), LTG_REDUCE(113), LTG_REDUCE(113),       ltg_blank, LTG_REDUCE(113), LTG_REDUCE(113),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(114),       ltg_blank,       ltg_blank, LTG_REDUCE(114), LTG_REDUCE(114), LTG_REDUCE(114), LTG_REDUCE(114),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(114), LTG_REDUCE(114), LTG_REDUCE(114), LTG_REDUCE(114), LTG_REDUCE(114), LTG_REDUCE(114), LTG_REDUCE(114), LTG_REDUCE(114), LTG_REDUCE(114), LTG_REDUCE(114), LTG_REDUCE(114), LTG_REDUCE(114), LTG_REDUCE(114), LTG_REDUCE(114), LTG_REDUCE(114), LTG_REDUCE(114), LTG_REDUCE(114), LTG_REDUCE(114), LTG_REDUCE(114), LTG_REDUCE(114), LTG_REDUCE(114), LTG_REDUCE(114), LTG_REDUCE(114), LTG_REDUCE(114), LTG_REDUCE(114), LTG_REDUCE(114),       ltg_blank, LTG_REDUCE(114), LTG_REDUCE(114), LTG_REDUCE(114), LTG_REDUCE(114), LTG_REDUCE(114),       ltg_blank, LTG_REDUCE(114), LTG_REDUCE(114),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(115),       ltg_blank,       ltg_blank, LTG_REDUCE(115), LTG_REDUCE(115), LTG_REDUCE(115), LTG_REDUCE(115),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(115), LTG_REDUCE(115), LTG_REDUCE(115), LTG_REDUCE(115), LTG_REDUCE(115), LTG_REDUCE(115), LTG_REDUCE(115), LTG_REDUCE(115), LTG_REDUCE(115), LTG_REDUCE(115), LTG_REDUCE(115), LTG_REDUCE(115), LTG_REDUCE(115), LTG_REDUCE(115), LTG_REDUCE(115), LTG_REDUCE(115), LTG_REDUCE(115), LTG_REDUCE(115), LTG_REDUCE(115), LTG_REDUCE(115), LTG_REDUCE(115), LTG_REDUCE(115), LTG_REDUCE(115), LTG_REDUCE(115), LTG_REDUCE(115), LTG_REDUCE(115),       ltg_blank, LTG_REDUCE(115), LTG_REDUCE(115), LTG_REDUCE(115), LTG_REDUCE(115), LTG_REDUCE(115),       ltg_blank, LTG_REDUCE(115), LTG_REDUCE(115),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(116),       ltg_blank,       ltg_blank, LTG_REDUCE(116), LTG_REDUCE(116), LTG_REDUCE(116), LTG_REDUCE(116),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(116), LTG_REDUCE(116), LTG_REDUCE(116), LTG_REDUCE(116), LTG_REDUCE(116), LTG_REDUCE(116), LTG_REDUCE(116), LTG_REDUCE(116), LTG_REDUCE(116), LTG_REDUCE(116), LTG_REDUCE(116), LTG_REDUCE(116), LTG_REDUCE(116), LTG_REDUCE(116), LTG_REDUCE(116), LTG_REDUCE(116), LTG_REDUCE(116), LTG_REDUCE(116), LTG_REDUCE(116), LTG_REDUCE(116), LTG_REDUCE(116), LTG_REDUCE(116), LTG_REDUCE(116), LTG_REDUCE(116), LTG_REDUCE(116), LTG_REDUCE(116),       ltg_blank, LTG_REDUCE(116), LTG_REDUCE(116), LTG_REDUCE(116), LTG_REDUCE(116), LTG_REDUCE(116),       ltg_blank, LTG_REDUCE(116), LTG_REDUCE(116),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(117),       ltg_blank,       ltg_blank, LTG_REDUCE(117), LTG_REDUCE(117), LTG_REDUCE(117), LTG_REDUCE(117),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(117), LTG_REDUCE(117), LTG_REDUCE(117), LTG_REDUCE(117), LTG_REDUCE(117), LTG_REDUCE(117), LTG_REDUCE(117), LTG_REDUCE(117), LTG_REDUCE(117), LTG_REDUCE(117), LTG_REDUCE(117), LTG_REDUCE(117), LTG_REDUCE(117), LTG_REDUCE(117), LTG_REDUCE(117), LTG_REDUCE(117), LTG_REDUCE(117), LTG_REDUCE(117), LTG_REDUCE(117), LTG_REDUCE(117), LTG_REDUCE(117), LTG_REDUCE(117), LTG_REDUCE(117), LTG_REDUCE(117), LTG_REDUCE(117), LTG_REDUCE(117),       ltg_blank, LTG_REDUCE(117), LTG_REDUCE(117), LTG_REDUCE(117), LTG_REDUCE(117), LTG_REDUCE(117),       ltg_blank, LTG_REDUCE(117), LTG_REDUCE(117),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(118),       ltg_blank,       ltg_blank, LTG_REDUCE(118), LTG_REDUCE(118), LTG_REDUCE(118), LTG_REDUCE(118),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(118), LTG_REDUCE(118), LTG_REDUCE(118), LTG_REDUCE(118), LTG_REDUCE(118), LTG_REDUCE(118), LTG_REDUCE(118), LTG_REDUCE(118), LTG_REDUCE(118), LTG_REDUCE(118), LTG_REDUCE(118), LTG_REDUCE(118), LTG_REDUCE(118), LTG_REDUCE(118), LTG_REDUCE(118), LTG_REDUCE(118), LTG_REDUCE(118), LTG_REDUCE(118), LTG_REDUCE(118), LTG_REDUCE(118), LTG_REDUCE(118), LTG_REDUCE(118), LTG_REDUCE(118), LTG_REDUCE(118), LTG_REDUCE(118), LTG_REDUCE(118),       ltg_blank, LTG_REDUCE(118), LTG_REDUCE(118), LTG_REDUCE(118), LTG_REDUCE(118), LTG_REDUCE(118),       ltg_blank, LTG_REDUCE(118), LTG_REDUCE(118),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(119),       ltg_blank,       ltg_blank, LTG_REDUCE(119), LTG_REDUCE(119), LTG_REDUCE(119), LTG_REDUCE(119),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(119), LTG_REDUCE(119), LTG_REDUCE(119), LTG_REDUCE(119), LTG_REDUCE(119), LTG_REDUCE(119), LTG_REDUCE(119), LTG_REDUCE(119), LTG_REDUCE(119), LTG_REDUCE(119), LTG_REDUCE(119), LTG_REDUCE(119), LTG_REDUCE(119), LTG_REDUCE(119), LTG_REDUCE(119), LTG_REDUCE(119), LTG_REDUCE(119), LTG_REDUCE(119), LTG_REDUCE(119), LTG_REDUCE(119), LTG_REDUCE(119), LTG_REDUCE(119), LTG_REDUCE(119), LTG_REDUCE(119), LTG_REDUCE(119), LTG_REDUCE(119),       ltg_blank, LTG_REDUCE(119), LTG_REDUCE(119), LTG_REDUCE(119), LTG_REDUCE(119), LTG_REDUCE(119),       ltg_blank, LTG_REDUCE(119), LTG_REDUCE(119),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(120),       ltg_blank,       ltg_blank, LTG_REDUCE(120), LTG_REDUCE(120), LTG_REDUCE(120), LTG_REDUCE(120),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(120), LTG_REDUCE(120), LTG_REDUCE(120), LTG_REDUCE(120), LTG_REDUCE(120), LTG_REDUCE(120), LTG_REDUCE(120), LTG_REDUCE(120), LTG_REDUCE(120), LTG_REDUCE(120), LTG_REDUCE(120), LTG_REDUCE(120), LTG_REDUCE(120), LTG_REDUCE(120), LTG_REDUCE(120), LTG_REDUCE(120), LTG_REDUCE(120), LTG_REDUCE(120), LTG_REDUCE(120), LTG_REDUCE(120), LTG_REDUCE(120), LTG_REDUCE(120), LTG_REDUCE(120), LTG_REDUCE(120), LTG_REDUCE(120), LTG_REDUCE(120),       ltg_blank, LTG_REDUCE(120), LTG_REDUCE(120), LTG_REDUCE(120), LTG_REDUCE(120), LTG_REDUCE(120),       ltg_blank, LTG_REDUCE(120), LTG_REDUCE(120),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(121),       ltg_blank,       ltg_blank, LTG_REDUCE(121), LTG_REDUCE(121), LTG_REDUCE(121), LTG_REDUCE(121),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(121), LTG_REDUCE(121), LTG_REDUCE(121), LTG_REDUCE(121), LTG_REDUCE(121), LTG_REDUCE(121), LTG_REDUCE(121), LTG_REDUCE(121), LTG_REDUCE(121), LTG_REDUCE(121), LTG_REDUCE(121), LTG_REDUCE(121), LTG_REDUCE(121), LTG_REDUCE(121), LTG_REDUCE(121), LTG_REDUCE(121), LTG_REDUCE(121), LTG_REDUCE(121), LTG_REDUCE(121), LTG_REDUCE(121), LTG_REDUCE(121), LTG_REDUCE(121), LTG_REDUCE(121), LTG_REDUCE(121), LTG_REDUCE(121), LTG_REDUCE(121),       ltg_blank, LTG_REDUCE(121), LTG_REDUCE(121), LTG_REDUCE(121), LTG_REDUCE(121), LTG_REDUCE(121),       ltg_blank, LTG_REDUCE(121), LTG_REDUCE(121),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_REDUCE(4),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_REDUCE(6),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_SHIFT(143),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_SHIFT(144),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_REDUCE(9),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_REDUCE(9),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_SHIFT(145),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(13),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(12),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
  LTG_REDUCE(14),  LTG_REDUCE(14),  LTG_REDUCE(14),  LTG_REDUCE(14),  LTG_REDUCE(14),  LTG_REDUCE(14),  LTG_REDUCE(14),  LTG_REDUCE(14),  LTG_REDUCE(14),  LTG_REDUCE(14),  LTG_REDUCE(14),  LTG_REDUCE(14),  LTG_REDUCE(14),  LTG_REDUCE(14),  LTG_REDUCE(14),       ltg_blank,  LTG_REDUCE(14),  LTG_REDUCE(14),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(14),  LTG_REDUCE(14),       ltg_blank,  LTG_REDUCE(14),  LTG_REDUCE(14),  LTG_REDUCE(14),  LTG_REDUCE(14),  LTG_REDUCE(14),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(14),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(14),  LTG_REDUCE(14),       ltg_blank,  LTG_REDUCE(14),       ltg_blank,       ltg_blank,  LTG_REDUCE(14),  LTG_REDUCE(14),  LTG_REDUCE(14),       ltg_blank,       ltg_blank,  LTG_REDUCE(14),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_REDUCE(3),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
  LTG_REDUCE(16),  LTG_REDUCE(16),  LTG_REDUCE(16),  LTG_REDUCE(16),  LTG_REDUCE(16),  LTG_REDUCE(16),  LTG_REDUCE(16),  LTG_REDUCE(16),  LTG_REDUCE(16),  LTG_REDUCE(16),  LTG_REDUCE(16),  LTG_REDUCE(16),  LTG_REDUCE(16),  LTG_REDUCE(16),  LTG_REDUCE(16),       ltg_blank,  LTG_REDUCE(16),  LTG_REDUCE(16),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(16),  LTG_REDUCE(16),  LTG_REDUCE(16),  LTG_REDUCE(16),  LTG_REDUCE(16),  LTG_REDUCE(16),  LTG_REDUCE(16),  LTG_REDUCE(16),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(16),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(16),  LTG_REDUCE(16),       ltg_blank,  LTG_REDUCE(16),       ltg_blank,       ltg_blank,  LTG_REDUCE(16),  LTG_REDUCE(16),  LTG_REDUCE(16),       ltg_blank,       ltg_blank,  LTG_REDUCE(16),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
  LTG_REDUCE(33),  LTG_REDUCE(33),  LTG_REDUCE(33),  LTG_REDUCE(33),  LTG_REDUCE(33),  LTG_REDUCE(33),  LTG_REDUCE(33),  LTG_REDUCE(33),  LTG_REDUCE(33),  LTG_REDUCE(33),  LTG_REDUCE(33),  LTG_REDUCE(33),  LTG_REDUCE(33),  LTG_REDUCE(33),  LTG_REDUCE(33),       ltg_blank,  LTG_REDUCE(33),  LTG_REDUCE(33),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(33),  LTG_REDUCE(33),  LTG_REDUCE(33),  LTG_REDUCE(33),  LTG_REDUCE(33),  LTG_REDUCE(33),  LTG_REDUCE(33),  LTG_REDUCE(33),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(33),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(33),  LTG_REDUCE(33),       ltg_blank,  LTG_REDUCE(33),       ltg_blank,       ltg_blank,  LTG_REDUCE(33),  LTG_REDUCE(33),  LTG_REDUCE(33),       ltg_blank,       ltg_blank,  LTG_REDUCE(33),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
  LTG_REDUCE(35),  LTG_REDUCE(35),  LTG_REDUCE(35),  LTG_REDUCE(35),  LTG_REDUCE(35),  LTG_REDUCE(35),  LTG_REDUCE(35),  LTG_REDUCE(35),  LTG_REDUCE(35),  LTG_REDUCE(35),  LTG_REDUCE(35),  LTG_REDUCE(35),  LTG_REDUCE(35),  LTG_REDUCE(35),  LTG_REDUCE(35),       ltg_blank,  LTG_REDUCE(35),  LTG_REDUCE(35),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(35),  LTG_REDUCE(35),  LTG_SHIFT(146),  LTG_REDUCE(35),  LTG_REDUCE(35),  LTG_REDUCE(35),  LTG_REDUCE(35),  LTG_REDUCE(35),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(35),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(35),  LTG_REDUCE(35),       ltg_blank,  LTG_REDUCE(35),       ltg_blank,       ltg_blank,  LTG_REDUCE(35),  LTG_REDUCE(35),  LTG_REDUCE(35),       ltg_blank,       ltg_blank,  LTG_REDUCE(35),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),   LTG_SHIFT(34),   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,   LTG_SHIFT(27),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(33),   LTG_SHIFT(29),       ltg_blank,   LTG_SHIFT(31),   LTG_SHIFT(30),   LTG_SHIFT(21),   LTG_SHIFT(22),   LTG_SHIFT(23),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(147),    LTG_GOTO(16),    LTG_GOTO(25),    LTG_GOTO(26),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(17),    LTG_GOTO(28),    LTG_GOTO(18),       ltg_blank,       ltg_blank,    LTG_GOTO(19),       ltg_blank,    LTG_GOTO(20),       ltg_blank,       ltg_blank,    LTG_GOTO(24),    LTG_GOTO(32),    LTG_GOTO(37),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(35),    LTG_GOTO(36),    LTG_GOTO(38),    LTG_GOTO(39),    LTG_GOTO(40),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),   LTG_SHIFT(34),   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,   LTG_SHIFT(27),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(33),   LTG_SHIFT(29),       ltg_blank,   LTG_SHIFT(31),   LTG_SHIFT(30),   LTG_SHIFT(21),   LTG_SHIFT(22),   LTG_SHIFT(23),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(148),    LTG_GOTO(16),    LTG_GOTO(25),    LTG_GOTO(26),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(17),    LTG_GOTO(28),    LTG_GOTO(18),       ltg_blank,       ltg_blank,    LTG_GOTO(19),       ltg_blank,    LTG_GOTO(20),       ltg_blank,       ltg_blank,    LTG_GOTO(24),    LTG_GOTO(32),    LTG_GOTO(37),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(35),    LTG_GOTO(36),    LTG_GOTO(38),    LTG_GOTO(39),    LTG_GOTO(40),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
  LTG_REDUCE(40),  LTG_REDUCE(40),  LTG_REDUCE(40),  LTG_REDUCE(40),  LTG_REDUCE(40),  LTG_REDUCE(40),  LTG_REDUCE(40),  LTG_REDUCE(40),  LTG_REDUCE(40),  LTG_REDUCE(40),  LTG_REDUCE(40),  LTG_REDUCE(40),  LTG_REDUCE(40),  LTG_REDUCE(40),  LTG_REDUCE(40),       ltg_blank,  LTG_REDUCE(40),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(40),  LTG_REDUCE(40),       ltg_blank,  LTG_REDUCE(40),  LTG_REDUCE(40),  LTG_REDUCE(40),  LTG_REDUCE(40),  LTG_REDUCE(40),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(40),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(40),  LTG_REDUCE(40),       ltg_blank,  LTG_REDUCE(40),       ltg_blank,       ltg_blank,  LTG_REDUCE(40),  LTG_REDUCE(40),  LTG_REDUCE(40),       ltg_blank,       ltg_blank,  LTG_REDUCE(40),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(149),    LTG_GOTO(37),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(35),    LTG_GOTO(36),    LTG_GOTO(38),    LTG_GOTO(39),    LTG_GOTO(40),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_SHIFT(151),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(150),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
  LTG_REDUCE(44),  LTG_REDUCE(44),  LTG_REDUCE(44),  LTG_REDUCE(44),  LTG_REDUCE(44),  LTG_REDUCE(44),  LTG_REDUCE(44),  LTG_REDUCE(44),  LTG_REDUCE(44),  LTG_REDUCE(44),  LTG_REDUCE(44),  LTG_REDUCE(44),  LTG_REDUCE(44),  LTG_REDUCE(44),  LTG_REDUCE(44),       ltg_blank,  LTG_REDUCE(44),  LTG_REDUCE(44),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(44),  LTG_REDUCE(44),  LTG_REDUCE(44),  LTG_REDUCE(44),  LTG_REDUCE(44),  LTG_REDUCE(44),  LTG_REDUCE(44),  LTG_REDUCE(44),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(44),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(44),  LTG_REDUCE(44),       ltg_blank,  LTG_REDUCE(44),       ltg_blank,       ltg_blank,  LTG_REDUCE(44),  LTG_REDUCE(44),  LTG_REDUCE(44),       ltg_blank,       ltg_blank,  LTG_REDUCE(44),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
  LTG_REDUCE(45),  LTG_REDUCE(45),  LTG_REDUCE(45),  LTG_REDUCE(45),  LTG_REDUCE(45),  LTG_REDUCE(45),  LTG_REDUCE(45),  LTG_REDUCE(45),  LTG_REDUCE(45),  LTG_REDUCE(45),  LTG_REDUCE(45),  LTG_REDUCE(45),  LTG_REDUCE(45),  LTG_REDUCE(45),  LTG_REDUCE(45),       ltg_blank,  LTG_REDUCE(45),  LTG_REDUCE(45),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(45),  LTG_REDUCE(45),  LTG_REDUCE(45),  LTG_REDUCE(45),  LTG_REDUCE(45),  LTG_REDUCE(45),  LTG_REDUCE(45),  LTG_REDUCE(45),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(45),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(45),  LTG_REDUCE(45),       ltg_blank,  LTG_REDUCE(45),       ltg_blank,       ltg_blank,  LTG_REDUCE(45),  LTG_REDUCE(45),  LTG_REDUCE(45),       ltg_blank,       ltg_blank,  LTG_REDUCE(45),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_SHIFT(152),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
  LTG_REDUCE(47),  LTG_REDUCE(47),  LTG_REDUCE(47),  LTG_REDUCE(47),  LTG_REDUCE(47),  LTG_REDUCE(47),  LTG_REDUCE(47),  LTG_REDUCE(47),  LTG_REDUCE(47),  LTG_REDUCE(47),  LTG_REDUCE(47),  LTG_REDUCE(47),  LTG_REDUCE(47),  LTG_REDUCE(47),  LTG_REDUCE(47),       ltg_blank,  LTG_REDUCE(47),  LTG_REDUCE(47),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(47),  LTG_REDUCE(47),  LTG_REDUCE(47),  LTG_REDUCE(47),  LTG_REDUCE(47),  LTG_REDUCE(47),  LTG_REDUCE(47),  LTG_REDUCE(47),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(47),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(47),  LTG_REDUCE(47),       ltg_blank,  LTG_REDUCE(47),       ltg_blank,       ltg_blank,  LTG_REDUCE(47),  LTG_REDUCE(47),  LTG_REDUCE(47),       ltg_blank,       ltg_blank,  LTG_REDUCE(47),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(17),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(18),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_SHIFT(153),  LTG_REDUCE(22),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(91),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(13),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(88),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(154),    LTG_GOTO(89),    LTG_GOTO(90),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(24),  LTG_REDUCE(24),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_SHIFT(156),       ltg_blank,  LTG_REDUCE(25),  LTG_REDUCE(25),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_SHIFT(155),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(28),       ltg_blank,  LTG_REDUCE(28),  LTG_REDUCE(28),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(28),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
  LTG_REDUCE(30),  LTG_REDUCE(30),  LTG_REDUCE(30),  LTG_REDUCE(30),  LTG_REDUCE(30),  LTG_REDUCE(30),  LTG_REDUCE(30),  LTG_REDUCE(30),  LTG_REDUCE(30),  LTG_REDUCE(30),  LTG_REDUCE(30),  LTG_REDUCE(30),  LTG_REDUCE(30),  LTG_REDUCE(30),  LTG_REDUCE(30),       ltg_blank,  LTG_REDUCE(30),  LTG_REDUCE(30),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(30),  LTG_REDUCE(30),  LTG_REDUCE(30),  LTG_REDUCE(30),  LTG_REDUCE(30),  LTG_REDUCE(30),  LTG_REDUCE(30),  LTG_REDUCE(30),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(30),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(30),  LTG_REDUCE(30),       ltg_blank,  LTG_REDUCE(30),       ltg_blank,       ltg_blank,  LTG_REDUCE(30),  LTG_REDUCE(30),  LTG_REDUCE(30),       ltg_blank,       ltg_blank,  LTG_REDUCE(30),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),   LTG_SHIFT(34),   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,   LTG_SHIFT(27),  LTG_SHIFT(157),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(33),   LTG_SHIFT(29),       ltg_blank,   LTG_SHIFT(31),   LTG_SHIFT(30),   LTG_SHIFT(21),   LTG_SHIFT(22),   LTG_SHIFT(23),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(71),    LTG_GOTO(16),    LTG_GOTO(25),    LTG_GOTO(26),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(17),    LTG_GOTO(28),    LTG_GOTO(18),       ltg_blank,       ltg_blank,    LTG_GOTO(19),       ltg_blank,    LTG_GOTO(20),       ltg_blank,       ltg_blank,    LTG_GOTO(24),    LTG_GOTO(32),    LTG_GOTO(37),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(35),    LTG_GOTO(36),    LTG_GOTO(38),    LTG_GOTO(39),    LTG_GOTO(40),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
  LTG_REDUCE(34),  LTG_REDUCE(34),  LTG_REDUCE(34),  LTG_REDUCE(34),  LTG_REDUCE(34),  LTG_REDUCE(34),  LTG_REDUCE(34),  LTG_REDUCE(34),  LTG_REDUCE(34),  LTG_REDUCE(34),  LTG_REDUCE(34),  LTG_REDUCE(34),  LTG_REDUCE(34),  LTG_REDUCE(34),  LTG_REDUCE(34),       ltg_blank,  LTG_REDUCE(34),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(34),  LTG_REDUCE(34),       ltg_blank,  LTG_REDUCE(34),  LTG_REDUCE(34),  LTG_REDUCE(34),  LTG_REDUCE(34),  LTG_REDUCE(34),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(34),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(34),  LTG_REDUCE(34),       ltg_blank,  LTG_REDUCE(34),       ltg_blank,       ltg_blank,  LTG_REDUCE(34),  LTG_REDUCE(34),  LTG_REDUCE(34),       ltg_blank,       ltg_blank,  LTG_REDUCE(34),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(37),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(158),    LTG_GOTO(36),    LTG_GOTO(38),    LTG_GOTO(39),    LTG_GOTO(40),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(37),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(159),    LTG_GOTO(36),    LTG_GOTO(38),    LTG_GOTO(39),    LTG_GOTO(40),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(37),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(160),    LTG_GOTO(36),    LTG_GOTO(38),    LTG_GOTO(39),    LTG_GOTO(40),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(37),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(161),    LTG_GOTO(36),    LTG_GOTO(38),    LTG_GOTO(39),    LTG_GOTO(40),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(37),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(162),    LTG_GOTO(36),    LTG_GOTO(38),    LTG_GOTO(39),    LTG_GOTO(40),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(37),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(163),    LTG_GOTO(36),    LTG_GOTO(38),    LTG_GOTO(39),    LTG_GOTO(40),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(37),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(164),    LTG_GOTO(36),    LTG_GOTO(38),    LTG_GOTO(39),    LTG_GOTO(40),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(37),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(165),    LTG_GOTO(36),    LTG_GOTO(38),    LTG_GOTO(39),    LTG_GOTO(40),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(37),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(166),    LTG_GOTO(36),    LTG_GOTO(38),    LTG_GOTO(39),    LTG_GOTO(40),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(37),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(167),    LTG_GOTO(36),    LTG_GOTO(38),    LTG_GOTO(39),    LTG_GOTO(40),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(37),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(168),    LTG_GOTO(36),    LTG_GOTO(38),    LTG_GOTO(39),    LTG_GOTO(40),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
 LTG_REDUCE(102), LTG_REDUCE(102), LTG_REDUCE(102), LTG_REDUCE(102), LTG_REDUCE(102), LTG_REDUCE(102), LTG_REDUCE(102), LTG_REDUCE(102), LTG_REDUCE(102), LTG_REDUCE(102), LTG_REDUCE(102), LTG_REDUCE(102),       ltg_blank, LTG_REDUCE(102), LTG_REDUCE(102),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(102),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(102), LTG_REDUCE(102),       ltg_blank, LTG_REDUCE(102),       ltg_blank,       ltg_blank, LTG_REDUCE(102), LTG_REDUCE(102), LTG_REDUCE(102),       ltg_blank,       ltg_blank, LTG_REDUCE(102),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(169),    LTG_GOTO(39),    LTG_GOTO(40),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(170),    LTG_GOTO(39),    LTG_GOTO(40),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(171),    LTG_GOTO(37),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(35),    LTG_GOTO(36),    LTG_GOTO(38),    LTG_GOTO(39),    LTG_GOTO(40),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_SHIFT(172),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(173),    LTG_GOTO(40),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(174),    LTG_GOTO(40),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(175),    LTG_GOTO(40),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(176),    LTG_GOTO(40),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(177),    LTG_GOTO(40),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(178),    LTG_GOTO(40),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(179),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(180),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(181),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(182),    LTG_GOTO(42),    LTG_GOTO(43),
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(183),    LTG_GOTO(42),    LTG_GOTO(43),
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(184),    LTG_GOTO(43),
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(185),    LTG_GOTO(43),
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(186),
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(187),
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(188),
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(87),       ltg_blank,       ltg_blank,  LTG_REDUCE(87),  LTG_REDUCE(87),  LTG_REDUCE(87),  LTG_REDUCE(87),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(87),  LTG_REDUCE(87),  LTG_REDUCE(87),  LTG_REDUCE(87),  LTG_REDUCE(87),  LTG_REDUCE(87),  LTG_REDUCE(87),  LTG_REDUCE(87),  LTG_REDUCE(87),  LTG_REDUCE(87),  LTG_REDUCE(87),  LTG_REDUCE(87),  LTG_REDUCE(87),  LTG_REDUCE(87),  LTG_REDUCE(87),  LTG_REDUCE(87),  LTG_REDUCE(87),  LTG_REDUCE(87),  LTG_REDUCE(87),  LTG_REDUCE(87),  LTG_REDUCE(87),  LTG_REDUCE(87),  LTG_REDUCE(87),  LTG_REDUCE(87),  LTG_REDUCE(87),  LTG_REDUCE(87),       ltg_blank,  LTG_REDUCE(87),  LTG_REDUCE(87),  LTG_REDUCE(87),  LTG_REDUCE(87),  LTG_REDUCE(87),       ltg_blank,  LTG_REDUCE(87),  LTG_REDUCE(87),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(88),       ltg_blank,       ltg_blank,  LTG_REDUCE(88),  LTG_REDUCE(88),  LTG_REDUCE(88),  LTG_REDUCE(88),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(88),  LTG_REDUCE(88),  LTG_REDUCE(88),  LTG_REDUCE(88),  LTG_REDUCE(88),  LTG_REDUCE(88),  LTG_REDUCE(88),  LTG_REDUCE(88),  LTG_REDUCE(88),  LTG_REDUCE(88),  LTG_REDUCE(88),  LTG_REDUCE(88),  LTG_REDUCE(88),  LTG_REDUCE(88),  LTG_REDUCE(88),  LTG_REDUCE(88),  LTG_REDUCE(88),  LTG_REDUCE(88),  LTG_REDUCE(88),  LTG_REDUCE(88),  LTG_REDUCE(88),  LTG_REDUCE(88),  LTG_REDUCE(88),  LTG_REDUCE(88),  LTG_REDUCE(88),  LTG_REDUCE(88),       ltg_blank,  LTG_REDUCE(88),  LTG_REDUCE(88),  LTG_REDUCE(88),  LTG_REDUCE(88),  LTG_REDUCE(88),       ltg_blank,  LTG_REDUCE(88),  LTG_REDUCE(88),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(37),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(189),    LTG_GOTO(36),    LTG_GOTO(38),    LTG_GOTO(39),    LTG_GOTO(40),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(89),       ltg_blank,       ltg_blank,  LTG_SHIFT(129),  LTG_REDUCE(89),  LTG_REDUCE(89),  LTG_REDUCE(89),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(89),  LTG_REDUCE(89),  LTG_REDUCE(89),  LTG_REDUCE(89),  LTG_REDUCE(89),  LTG_REDUCE(89),  LTG_REDUCE(89),  LTG_REDUCE(89),  LTG_REDUCE(89),  LTG_REDUCE(89),  LTG_REDUCE(89),  LTG_REDUCE(89),  LTG_REDUCE(89),  LTG_REDUCE(89),  LTG_REDUCE(89),  LTG_REDUCE(89),  LTG_REDUCE(89),  LTG_REDUCE(89),  LTG_REDUCE(89),  LTG_REDUCE(89),  LTG_REDUCE(89),  LTG_REDUCE(89),  LTG_REDUCE(89),  LTG_REDUCE(89),  LTG_REDUCE(89),  LTG_REDUCE(89),       ltg_blank,  LTG_REDUCE(89),  LTG_REDUCE(89),  LTG_REDUCE(89),  LTG_SHIFT(127),  LTG_SHIFT(128),       ltg_blank,  LTG_REDUCE(89),  LTG_REDUCE(89),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(90),       ltg_blank,       ltg_blank,  LTG_SHIFT(129),  LTG_REDUCE(90),  LTG_REDUCE(90),  LTG_REDUCE(90),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(90),  LTG_REDUCE(90),  LTG_REDUCE(90),  LTG_REDUCE(90),  LTG_REDUCE(90),  LTG_REDUCE(90),  LTG_REDUCE(90),  LTG_REDUCE(90),  LTG_REDUCE(90),  LTG_REDUCE(90),  LTG_REDUCE(90),  LTG_REDUCE(90),  LTG_REDUCE(90),  LTG_REDUCE(90),  LTG_REDUCE(90),  LTG_REDUCE(90),  LTG_REDUCE(90),  LTG_REDUCE(90),  LTG_REDUCE(90),  LTG_REDUCE(90),  LTG_REDUCE(90),  LTG_REDUCE(90),  LTG_REDUCE(90),  LTG_REDUCE(90),  LTG_REDUCE(90),  LTG_REDUCE(90),       ltg_blank,  LTG_REDUCE(90),  LTG_REDUCE(90),  LTG_REDUCE(90),  LTG_SHIFT(127),  LTG_SHIFT(128),       ltg_blank,  LTG_REDUCE(90),  LTG_REDUCE(90),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(91),       ltg_blank,       ltg_blank,  LTG_SHIFT(129),  LTG_REDUCE(91),  LTG_REDUCE(91),  LTG_REDUCE(91),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(91),  LTG_REDUCE(91),  LTG_REDUCE(91),  LTG_REDUCE(91),  LTG_REDUCE(91),  LTG_REDUCE(91),  LTG_REDUCE(91),  LTG_REDUCE(91),  LTG_REDUCE(91),  LTG_REDUCE(91),  LTG_REDUCE(91),  LTG_REDUCE(91),  LTG_REDUCE(91),  LTG_REDUCE(91),  LTG_REDUCE(91),  LTG_REDUCE(91),  LTG_REDUCE(91),  LTG_REDUCE(91),  LTG_REDUCE(91),  LTG_REDUCE(91),  LTG_REDUCE(91),  LTG_REDUCE(91),  LTG_REDUCE(91),  LTG_REDUCE(91),  LTG_REDUCE(91),  LTG_REDUCE(91),       ltg_blank,  LTG_REDUCE(91),  LTG_REDUCE(91),  LTG_REDUCE(91),  LTG_SHIFT(127),  LTG_SHIFT(128),       ltg_blank,  LTG_REDUCE(91),  LTG_REDUCE(91),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(92),       ltg_blank,       ltg_blank,  LTG_SHIFT(129),  LTG_REDUCE(92),  LTG_REDUCE(92),  LTG_REDUCE(92),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(92),  LTG_REDUCE(92),  LTG_REDUCE(92),  LTG_REDUCE(92),  LTG_REDUCE(92),  LTG_REDUCE(92),  LTG_REDUCE(92),  LTG_REDUCE(92),  LTG_REDUCE(92),  LTG_REDUCE(92),  LTG_REDUCE(92),  LTG_REDUCE(92),  LTG_REDUCE(92),  LTG_REDUCE(92),  LTG_REDUCE(92),  LTG_REDUCE(92),  LTG_REDUCE(92),  LTG_REDUCE(92),  LTG_REDUCE(92),  LTG_REDUCE(92),  LTG_REDUCE(92),  LTG_REDUCE(92),  LTG_REDUCE(92),  LTG_REDUCE(92),  LTG_REDUCE(92),  LTG_REDUCE(92),       ltg_blank,  LTG_REDUCE(92),  LTG_REDUCE(92),  LTG_REDUCE(92),  LTG_SHIFT(127),  LTG_SHIFT(128),       ltg_blank,  LTG_REDUCE(92),  LTG_REDUCE(92),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(93),       ltg_blank,       ltg_blank,  LTG_SHIFT(129),  LTG_REDUCE(93),  LTG_REDUCE(93),  LTG_REDUCE(93),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(93),  LTG_REDUCE(93),  LTG_REDUCE(93),  LTG_REDUCE(93),  LTG_REDUCE(93),  LTG_REDUCE(93),  LTG_REDUCE(93),  LTG_REDUCE(93),  LTG_REDUCE(93),  LTG_REDUCE(93),  LTG_REDUCE(93),  LTG_REDUCE(93),  LTG_REDUCE(93),  LTG_REDUCE(93),  LTG_REDUCE(93),  LTG_REDUCE(93),  LTG_REDUCE(93),  LTG_REDUCE(93),  LTG_REDUCE(93),  LTG_REDUCE(93),  LTG_REDUCE(93),  LTG_REDUCE(93),  LTG_REDUCE(93),  LTG_REDUCE(93),  LTG_REDUCE(93),  LTG_REDUCE(93),       ltg_blank,  LTG_REDUCE(93),  LTG_REDUCE(93),  LTG_REDUCE(93),  LTG_SHIFT(127),  LTG_SHIFT(128),       ltg_blank,  LTG_REDUCE(93),  LTG_REDUCE(93),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(94),       ltg_blank,       ltg_blank,  LTG_SHIFT(129),  LTG_REDUCE(94),  LTG_REDUCE(94),  LTG_REDUCE(94),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(94),  LTG_REDUCE(94),  LTG_REDUCE(94),  LTG_REDUCE(94),  LTG_REDUCE(94),  LTG_REDUCE(94),  LTG_REDUCE(94),  LTG_REDUCE(94),  LTG_REDUCE(94),  LTG_REDUCE(94),  LTG_REDUCE(94),  LTG_REDUCE(94),  LTG_REDUCE(94),  LTG_REDUCE(94),  LTG_REDUCE(94),  LTG_REDUCE(94),  LTG_REDUCE(94),  LTG_REDUCE(94),  LTG_REDUCE(94),  LTG_REDUCE(94),  LTG_REDUCE(94),  LTG_REDUCE(94),  LTG_REDUCE(94),  LTG_REDUCE(94),  LTG_REDUCE(94),  LTG_REDUCE(94),       ltg_blank,  LTG_REDUCE(94),  LTG_REDUCE(94),  LTG_REDUCE(94),  LTG_SHIFT(127),  LTG_SHIFT(128),       ltg_blank,  LTG_REDUCE(94),  LTG_REDUCE(94),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(95),       ltg_blank,       ltg_blank,  LTG_SHIFT(129),  LTG_REDUCE(95),  LTG_REDUCE(95),  LTG_REDUCE(95),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(95),  LTG_REDUCE(95),  LTG_REDUCE(95),  LTG_REDUCE(95),  LTG_REDUCE(95),  LTG_REDUCE(95),  LTG_REDUCE(95),  LTG_REDUCE(95),  LTG_REDUCE(95),  LTG_REDUCE(95),  LTG_REDUCE(95),  LTG_REDUCE(95),  LTG_REDUCE(95),  LTG_REDUCE(95),  LTG_REDUCE(95),  LTG_REDUCE(95),  LTG_REDUCE(95),  LTG_REDUCE(95),  LTG_REDUCE(95),  LTG_REDUCE(95),  LTG_REDUCE(95),  LTG_REDUCE(95),  LTG_REDUCE(95),  LTG_REDUCE(95),  LTG_REDUCE(95),  LTG_REDUCE(95),       ltg_blank,  LTG_REDUCE(95),  LTG_REDUCE(95),  LTG_REDUCE(95),  LTG_SHIFT(127),  LTG_SHIFT(128),       ltg_blank,  LTG_REDUCE(95),  LTG_REDUCE(95),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(96),       ltg_blank,       ltg_blank,  LTG_SHIFT(129),  LTG_REDUCE(96),  LTG_REDUCE(96),  LTG_REDUCE(96),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(96),  LTG_REDUCE(96),  LTG_REDUCE(96),  LTG_REDUCE(96),  LTG_REDUCE(96),  LTG_REDUCE(96),  LTG_REDUCE(96),  LTG_REDUCE(96),  LTG_REDUCE(96),  LTG_REDUCE(96),  LTG_REDUCE(96),  LTG_REDUCE(96),  LTG_REDUCE(96),  LTG_REDUCE(96),  LTG_REDUCE(96),  LTG_REDUCE(96),  LTG_REDUCE(96),  LTG_REDUCE(96),  LTG_REDUCE(96),  LTG_REDUCE(96),  LTG_REDUCE(96),  LTG_REDUCE(96),  LTG_REDUCE(96),  LTG_REDUCE(96),  LTG_REDUCE(96),  LTG_REDUCE(96),       ltg_blank,  LTG_REDUCE(96),  LTG_REDUCE(96),  LTG_REDUCE(96),  LTG_SHIFT(127),  LTG_SHIFT(128),       ltg_blank,  LTG_REDUCE(96),  LTG_REDUCE(96),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_SHIFT(190),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(13),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(12),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_SHIFT(191),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(95),   LTG_SHIFT(96),   LTG_SHIFT(97),   LTG_SHIFT(98),   LTG_SHIFT(99),  LTG_SHIFT(100),  LTG_SHIFT(101),  LTG_SHIFT(102),  LTG_SHIFT(103),  LTG_SHIFT(104),  LTG_SHIFT(105),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_SHIFT(106),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_SHIFT(192),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52), LTG_REDUCE(105),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(194),    LTG_GOTO(37),       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(193),    LTG_GOTO(35),    LTG_GOTO(36),    LTG_GOTO(38),    LTG_GOTO(39),    LTG_GOTO(40),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
 LTG_REDUCE(107), LTG_REDUCE(107), LTG_REDUCE(107), LTG_REDUCE(107), LTG_REDUCE(107), LTG_REDUCE(107), LTG_REDUCE(107), LTG_REDUCE(107), LTG_REDUCE(107), LTG_REDUCE(107), LTG_REDUCE(107), LTG_REDUCE(107),       ltg_blank, LTG_REDUCE(107), LTG_REDUCE(107), LTG_REDUCE(107),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(107),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(107), LTG_REDUCE(107),       ltg_blank, LTG_REDUCE(107),       ltg_blank,       ltg_blank, LTG_REDUCE(107), LTG_REDUCE(107), LTG_REDUCE(107),       ltg_blank,       ltg_blank, LTG_REDUCE(107),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_REDUCE(7),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_SHIFT(7),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(195),    LTG_GOTO(70),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(10),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(10),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
  LTG_REDUCE(37),  LTG_REDUCE(37),  LTG_REDUCE(37),  LTG_REDUCE(37),  LTG_REDUCE(37),  LTG_REDUCE(37),  LTG_REDUCE(37),  LTG_REDUCE(37),  LTG_REDUCE(37),  LTG_REDUCE(37),  LTG_REDUCE(37),  LTG_REDUCE(37),  LTG_REDUCE(37),  LTG_REDUCE(37),  LTG_REDUCE(37),       ltg_blank,  LTG_REDUCE(37),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(37),  LTG_REDUCE(37),       ltg_blank,  LTG_REDUCE(37),  LTG_REDUCE(37),  LTG_REDUCE(37),  LTG_REDUCE(37),  LTG_REDUCE(37),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(37),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(37),  LTG_REDUCE(37),       ltg_blank,  LTG_REDUCE(37),       ltg_blank,       ltg_blank,  LTG_REDUCE(37),  LTG_REDUCE(37),  LTG_REDUCE(37),       ltg_blank,       ltg_blank,  LTG_REDUCE(37),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
  LTG_REDUCE(36),  LTG_REDUCE(36),  LTG_REDUCE(36),  LTG_REDUCE(36),  LTG_REDUCE(36),  LTG_REDUCE(36),  LTG_REDUCE(36),  LTG_REDUCE(36),  LTG_REDUCE(36),  LTG_REDUCE(36),  LTG_REDUCE(36),  LTG_REDUCE(36),  LTG_REDUCE(36),  LTG_REDUCE(36),  LTG_REDUCE(36),       ltg_blank,  LTG_REDUCE(36),  LTG_REDUCE(36),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(36),  LTG_REDUCE(36),  LTG_REDUCE(36),  LTG_REDUCE(36),  LTG_REDUCE(36),  LTG_REDUCE(36),  LTG_REDUCE(36),  LTG_REDUCE(36),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(36),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(36),  LTG_REDUCE(36),       ltg_blank,  LTG_REDUCE(36),       ltg_blank,       ltg_blank,  LTG_REDUCE(36),  LTG_REDUCE(36),  LTG_REDUCE(36),       ltg_blank,       ltg_blank,  LTG_REDUCE(36),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
  LTG_REDUCE(38),  LTG_REDUCE(38),  LTG_REDUCE(38),  LTG_REDUCE(38),  LTG_REDUCE(38),  LTG_REDUCE(38),  LTG_REDUCE(38),  LTG_REDUCE(38),  LTG_REDUCE(38),  LTG_REDUCE(38),  LTG_REDUCE(38),  LTG_REDUCE(38),  LTG_REDUCE(38),  LTG_REDUCE(38),  LTG_REDUCE(38),       ltg_blank,  LTG_REDUCE(38),  LTG_REDUCE(38),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(38),  LTG_REDUCE(38),  LTG_REDUCE(38),  LTG_REDUCE(38),  LTG_REDUCE(38),  LTG_REDUCE(38),  LTG_REDUCE(38),  LTG_REDUCE(38),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(38),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(38),  LTG_REDUCE(38),       ltg_blank,  LTG_REDUCE(38),       ltg_blank,       ltg_blank,  LTG_REDUCE(38),  LTG_REDUCE(38),  LTG_REDUCE(38),       ltg_blank,       ltg_blank,  LTG_REDUCE(38),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_SHIFT(196),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(79),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(197),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(43),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
  LTG_REDUCE(46),  LTG_REDUCE(46),  LTG_REDUCE(46),  LTG_REDUCE(46),  LTG_REDUCE(46),  LTG_REDUCE(46),  LTG_REDUCE(46),  LTG_REDUCE(46),  LTG_REDUCE(46),  LTG_REDUCE(46),  LTG_REDUCE(46),  LTG_REDUCE(46),  LTG_REDUCE(46),  LTG_REDUCE(46),  LTG_REDUCE(46),       ltg_blank,  LTG_REDUCE(46),  LTG_REDUCE(46),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(46),  LTG_REDUCE(46),  LTG_REDUCE(46),  LTG_REDUCE(46),  LTG_REDUCE(46),  LTG_REDUCE(46),  LTG_REDUCE(46),  LTG_REDUCE(46),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(46),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(46),  LTG_REDUCE(46),       ltg_blank,  LTG_REDUCE(46),       ltg_blank,       ltg_blank,  LTG_REDUCE(46),  LTG_REDUCE(46),  LTG_REDUCE(46),       ltg_blank,       ltg_blank,  LTG_REDUCE(46),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(91),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(13),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(88),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(198),    LTG_GOTO(87),    LTG_GOTO(89),    LTG_GOTO(90),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(23),  LTG_REDUCE(23),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(199),    LTG_GOTO(37),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(35),    LTG_GOTO(36),    LTG_GOTO(38),    LTG_GOTO(39),    LTG_GOTO(40),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(200),    LTG_GOTO(37),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(35),    LTG_GOTO(36),    LTG_GOTO(38),    LTG_GOTO(39),    LTG_GOTO(40),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
  LTG_REDUCE(31),  LTG_REDUCE(31),  LTG_REDUCE(31),  LTG_REDUCE(31),  LTG_REDUCE(31),  LTG_REDUCE(31),  LTG_REDUCE(31),  LTG_REDUCE(31),  LTG_REDUCE(31),  LTG_REDUCE(31),  LTG_REDUCE(31),  LTG_REDUCE(31),  LTG_REDUCE(31),  LTG_REDUCE(31),  LTG_REDUCE(31),       ltg_blank,  LTG_REDUCE(31),  LTG_REDUCE(31),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(31),  LTG_REDUCE(31),  LTG_REDUCE(31),  LTG_REDUCE(31),  LTG_REDUCE(31),  LTG_REDUCE(31),  LTG_REDUCE(31),  LTG_REDUCE(31),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(31),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(31),  LTG_REDUCE(31),       ltg_blank,  LTG_REDUCE(31),       ltg_blank,       ltg_blank,  LTG_REDUCE(31),  LTG_REDUCE(31),  LTG_REDUCE(31),       ltg_blank,       ltg_blank,  LTG_REDUCE(31),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(51),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(51),  LTG_REDUCE(51),  LTG_REDUCE(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(95),   LTG_SHIFT(96),   LTG_SHIFT(97),   LTG_SHIFT(98),   LTG_SHIFT(99),  LTG_SHIFT(100),  LTG_SHIFT(101),  LTG_SHIFT(102),  LTG_SHIFT(103),  LTG_SHIFT(104),  LTG_SHIFT(105),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_SHIFT(106),  LTG_REDUCE(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(52),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(52),  LTG_REDUCE(52),  LTG_REDUCE(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(95),   LTG_SHIFT(96),   LTG_SHIFT(97),   LTG_SHIFT(98),   LTG_SHIFT(99),  LTG_SHIFT(100),  LTG_SHIFT(101),  LTG_SHIFT(102),  LTG_SHIFT(103),  LTG_SHIFT(104),  LTG_SHIFT(105),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_SHIFT(106),  LTG_REDUCE(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(53),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(53),  LTG_REDUCE(53),  LTG_REDUCE(53),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(95),   LTG_SHIFT(96),   LTG_SHIFT(97),   LTG_SHIFT(98),   LTG_SHIFT(99),  LTG_SHIFT(100),  LTG_SHIFT(101),  LTG_SHIFT(102),  LTG_SHIFT(103),  LTG_SHIFT(104),  LTG_SHIFT(105),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_SHIFT(106),  LTG_REDUCE(53),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(54),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(54),  LTG_REDUCE(54),  LTG_REDUCE(54),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(95),   LTG_SHIFT(96),   LTG_SHIFT(97),   LTG_SHIFT(98),   LTG_SHIFT(99),  LTG_SHIFT(100),  LTG_SHIFT(101),  LTG_SHIFT(102),  LTG_SHIFT(103),  LTG_SHIFT(104),  LTG_SHIFT(105),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_SHIFT(106),  LTG_REDUCE(54),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(55),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(55),  LTG_REDUCE(55),  LTG_REDUCE(55),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(95),   LTG_SHIFT(96),   LTG_SHIFT(97),   LTG_SHIFT(98),   LTG_SHIFT(99),  LTG_SHIFT(100),  LTG_SHIFT(101),  LTG_SHIFT(102),  LTG_SHIFT(103),  LTG_SHIFT(104),  LTG_SHIFT(105),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_SHIFT(106),  LTG_REDUCE(55),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(56),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(56),  LTG_REDUCE(56),  LTG_REDUCE(56),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(95),   LTG_SHIFT(96),   LTG_SHIFT(97),   LTG_SHIFT(98),   LTG_SHIFT(99),  LTG_SHIFT(100),  LTG_SHIFT(101),  LTG_SHIFT(102),  LTG_SHIFT(103),  LTG_SHIFT(104),  LTG_SHIFT(105),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_SHIFT(106),  LTG_REDUCE(56),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(57),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(57),  LTG_REDUCE(57),  LTG_REDUCE(57),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(95),   LTG_SHIFT(96),   LTG_SHIFT(97),   LTG_SHIFT(98),   LTG_SHIFT(99),  LTG_SHIFT(100),  LTG_SHIFT(101),  LTG_SHIFT(102),  LTG_SHIFT(103),  LTG_SHIFT(104),  LTG_SHIFT(105),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_SHIFT(106),  LTG_REDUCE(57),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(58),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(58),  LTG_REDUCE(58),  LTG_REDUCE(58),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(95),   LTG_SHIFT(96),   LTG_SHIFT(97),   LTG_SHIFT(98),   LTG_SHIFT(99),  LTG_SHIFT(100),  LTG_SHIFT(101),  LTG_SHIFT(102),  LTG_SHIFT(103),  LTG_SHIFT(104),  LTG_SHIFT(105),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_SHIFT(106),  LTG_REDUCE(58),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(59),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(59),  LTG_REDUCE(59),  LTG_REDUCE(59),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(95),   LTG_SHIFT(96),   LTG_SHIFT(97),   LTG_SHIFT(98),   LTG_SHIFT(99),  LTG_SHIFT(100),  LTG_SHIFT(101),  LTG_SHIFT(102),  LTG_SHIFT(103),  LTG_SHIFT(104),  LTG_SHIFT(105),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_SHIFT(106),  LTG_REDUCE(59),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(60),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(60),  LTG_REDUCE(60),  LTG_REDUCE(60),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(95),   LTG_SHIFT(96),   LTG_SHIFT(97),   LTG_SHIFT(98),   LTG_SHIFT(99),  LTG_SHIFT(100),  LTG_SHIFT(101),  LTG_SHIFT(102),  LTG_SHIFT(103),  LTG_SHIFT(104),  LTG_SHIFT(105),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_SHIFT(106),  LTG_REDUCE(60),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(61),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(61),  LTG_REDUCE(61),  LTG_REDUCE(61),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(95),   LTG_SHIFT(96),   LTG_SHIFT(97),   LTG_SHIFT(98),   LTG_SHIFT(99),  LTG_SHIFT(100),  LTG_SHIFT(101),  LTG_SHIFT(102),  LTG_SHIFT(103),  LTG_SHIFT(104),  LTG_SHIFT(105),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_SHIFT(106),  LTG_REDUCE(61),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(63),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(63),  LTG_REDUCE(63),  LTG_REDUCE(63),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(63),  LTG_REDUCE(63),  LTG_REDUCE(63),  LTG_REDUCE(63),  LTG_REDUCE(63),  LTG_REDUCE(63),  LTG_REDUCE(63),  LTG_REDUCE(63),  LTG_REDUCE(63),  LTG_REDUCE(63),  LTG_REDUCE(63),  LTG_REDUCE(63),  LTG_REDUCE(63),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_SHIFT(111),  LTG_SHIFT(112),  LTG_SHIFT(113),  LTG_SHIFT(114),  LTG_SHIFT(115),  LTG_SHIFT(116),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(63),  LTG_REDUCE(63),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(64),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(64),  LTG_REDUCE(64),  LTG_REDUCE(64),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(64),  LTG_REDUCE(64),  LTG_REDUCE(64),  LTG_REDUCE(64),  LTG_REDUCE(64),  LTG_REDUCE(64),  LTG_REDUCE(64),  LTG_REDUCE(64),  LTG_REDUCE(64),  LTG_REDUCE(64),  LTG_REDUCE(64),  LTG_REDUCE(64),  LTG_REDUCE(64),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_SHIFT(111),  LTG_SHIFT(112),  LTG_SHIFT(113),  LTG_SHIFT(114),  LTG_SHIFT(115),  LTG_SHIFT(116),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(64),  LTG_REDUCE(64),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(101),       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(101), LTG_REDUCE(101), LTG_REDUCE(101),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(101), LTG_REDUCE(101), LTG_REDUCE(101), LTG_REDUCE(101), LTG_REDUCE(101), LTG_REDUCE(101), LTG_REDUCE(101), LTG_REDUCE(101), LTG_REDUCE(101), LTG_REDUCE(101), LTG_REDUCE(101),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(101), LTG_REDUCE(101),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
 LTG_REDUCE(103), LTG_REDUCE(103), LTG_REDUCE(103), LTG_REDUCE(103), LTG_REDUCE(103), LTG_REDUCE(103), LTG_REDUCE(103), LTG_REDUCE(103), LTG_REDUCE(103), LTG_REDUCE(103), LTG_REDUCE(103), LTG_REDUCE(103),       ltg_blank, LTG_REDUCE(103), LTG_REDUCE(103),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(103),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(103), LTG_REDUCE(103),       ltg_blank, LTG_REDUCE(103),       ltg_blank,       ltg_blank, LTG_REDUCE(103), LTG_REDUCE(103), LTG_REDUCE(103),       ltg_blank,       ltg_blank, LTG_REDUCE(103),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(66),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(66),  LTG_REDUCE(66),  LTG_REDUCE(66),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(66),  LTG_REDUCE(66),  LTG_REDUCE(66),  LTG_REDUCE(66),  LTG_REDUCE(66),  LTG_REDUCE(66),  LTG_REDUCE(66),  LTG_REDUCE(66),  LTG_REDUCE(66),  LTG_REDUCE(66),  LTG_REDUCE(66),  LTG_REDUCE(66),  LTG_REDUCE(66),  LTG_SHIFT(117),  LTG_SHIFT(118),  LTG_SHIFT(119),  LTG_REDUCE(66),  LTG_REDUCE(66),  LTG_REDUCE(66),  LTG_REDUCE(66),  LTG_REDUCE(66),  LTG_REDUCE(66),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(66),  LTG_REDUCE(66),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(67),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(67),  LTG_REDUCE(67),  LTG_REDUCE(67),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(67),  LTG_REDUCE(67),  LTG_REDUCE(67),  LTG_REDUCE(67),  LTG_REDUCE(67),  LTG_REDUCE(67),  LTG_REDUCE(67),  LTG_REDUCE(67),  LTG_REDUCE(67),  LTG_REDUCE(67),  LTG_REDUCE(67),  LTG_REDUCE(67),  LTG_REDUCE(67),  LTG_SHIFT(117),  LTG_SHIFT(118),  LTG_SHIFT(119),  LTG_REDUCE(67),  LTG_REDUCE(67),  LTG_REDUCE(67),  LTG_REDUCE(67),  LTG_REDUCE(67),  LTG_REDUCE(67),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(67),  LTG_REDUCE(67),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(68),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(68),  LTG_REDUCE(68),  LTG_REDUCE(68),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(68),  LTG_REDUCE(68),  LTG_REDUCE(68),  LTG_REDUCE(68),  LTG_REDUCE(68),  LTG_REDUCE(68),  LTG_REDUCE(68),  LTG_REDUCE(68),  LTG_REDUCE(68),  LTG_REDUCE(68),  LTG_REDUCE(68),  LTG_REDUCE(68),  LTG_REDUCE(68),  LTG_SHIFT(117),  LTG_SHIFT(118),  LTG_SHIFT(119),  LTG_REDUCE(68),  LTG_REDUCE(68),  LTG_REDUCE(68),  LTG_REDUCE(68),  LTG_REDUCE(68),  LTG_REDUCE(68),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(68),  LTG_REDUCE(68),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(69),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(69),  LTG_REDUCE(69),  LTG_REDUCE(69),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(69),  LTG_REDUCE(69),  LTG_REDUCE(69),  LTG_REDUCE(69),  LTG_REDUCE(69),  LTG_REDUCE(69),  LTG_REDUCE(69),  LTG_REDUCE(69),  LTG_REDUCE(69),  LTG_REDUCE(69),  LTG_REDUCE(69),  LTG_REDUCE(69),  LTG_REDUCE(69),  LTG_SHIFT(117),  LTG_SHIFT(118),  LTG_SHIFT(119),  LTG_REDUCE(69),  LTG_REDUCE(69),  LTG_REDUCE(69),  LTG_REDUCE(69),  LTG_REDUCE(69),  LTG_REDUCE(69),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(69),  LTG_REDUCE(69),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(70),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(70),  LTG_REDUCE(70),  LTG_REDUCE(70),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(70),  LTG_REDUCE(70),  LTG_REDUCE(70),  LTG_REDUCE(70),  LTG_REDUCE(70),  LTG_REDUCE(70),  LTG_REDUCE(70),  LTG_REDUCE(70),  LTG_REDUCE(70),  LTG_REDUCE(70),  LTG_REDUCE(70),  LTG_REDUCE(70),  LTG_REDUCE(70),  LTG_SHIFT(117),  LTG_SHIFT(118),  LTG_SHIFT(119),  LTG_REDUCE(70),  LTG_REDUCE(70),  LTG_REDUCE(70),  LTG_REDUCE(70),  LTG_REDUCE(70),  LTG_REDUCE(70),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(70),  LTG_REDUCE(70),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(71),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(71),  LTG_REDUCE(71),  LTG_REDUCE(71),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(71),  LTG_REDUCE(71),  LTG_REDUCE(71),  LTG_REDUCE(71),  LTG_REDUCE(71),  LTG_REDUCE(71),  LTG_REDUCE(71),  LTG_REDUCE(71),  LTG_REDUCE(71),  LTG_REDUCE(71),  LTG_REDUCE(71),  LTG_REDUCE(71),  LTG_REDUCE(71),  LTG_SHIFT(117),  LTG_SHIFT(118),  LTG_SHIFT(119),  LTG_REDUCE(71),  LTG_REDUCE(71),  LTG_REDUCE(71),  LTG_REDUCE(71),  LTG_REDUCE(71),  LTG_REDUCE(71),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(71),  LTG_REDUCE(71),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(73),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(73),  LTG_REDUCE(73),  LTG_REDUCE(73),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(73),  LTG_REDUCE(73),  LTG_REDUCE(73),  LTG_REDUCE(73),  LTG_REDUCE(73),  LTG_REDUCE(73),  LTG_REDUCE(73),  LTG_REDUCE(73),  LTG_REDUCE(73),  LTG_REDUCE(73),  LTG_REDUCE(73),  LTG_REDUCE(73),  LTG_REDUCE(73),  LTG_REDUCE(73),  LTG_REDUCE(73),  LTG_REDUCE(73),  LTG_REDUCE(73),  LTG_REDUCE(73),  LTG_REDUCE(73),  LTG_REDUCE(73),  LTG_REDUCE(73),  LTG_REDUCE(73),  LTG_SHIFT(120),  LTG_SHIFT(121),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(73),  LTG_REDUCE(73),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(74),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(74),  LTG_REDUCE(74),  LTG_REDUCE(74),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(74),  LTG_REDUCE(74),  LTG_REDUCE(74),  LTG_REDUCE(74),  LTG_REDUCE(74),  LTG_REDUCE(74),  LTG_REDUCE(74),  LTG_REDUCE(74),  LTG_REDUCE(74),  LTG_REDUCE(74),  LTG_REDUCE(74),  LTG_REDUCE(74),  LTG_REDUCE(74),  LTG_REDUCE(74),  LTG_REDUCE(74),  LTG_REDUCE(74),  LTG_REDUCE(74),  LTG_REDUCE(74),  LTG_REDUCE(74),  LTG_REDUCE(74),  LTG_REDUCE(74),  LTG_REDUCE(74),  LTG_SHIFT(120),  LTG_SHIFT(121),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(74),  LTG_REDUCE(74),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(75),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(75),  LTG_REDUCE(75),  LTG_REDUCE(75),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(75),  LTG_REDUCE(75),  LTG_REDUCE(75),  LTG_REDUCE(75),  LTG_REDUCE(75),  LTG_REDUCE(75),  LTG_REDUCE(75),  LTG_REDUCE(75),  LTG_REDUCE(75),  LTG_REDUCE(75),  LTG_REDUCE(75),  LTG_REDUCE(75),  LTG_REDUCE(75),  LTG_REDUCE(75),  LTG_REDUCE(75),  LTG_REDUCE(75),  LTG_REDUCE(75),  LTG_REDUCE(75),  LTG_REDUCE(75),  LTG_REDUCE(75),  LTG_REDUCE(75),  LTG_REDUCE(75),  LTG_SHIFT(120),  LTG_SHIFT(121),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(75),  LTG_REDUCE(75),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(77),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(77),  LTG_REDUCE(77),  LTG_REDUCE(77),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(77),  LTG_REDUCE(77),  LTG_REDUCE(77),  LTG_REDUCE(77),  LTG_REDUCE(77),  LTG_REDUCE(77),  LTG_REDUCE(77),  LTG_REDUCE(77),  LTG_REDUCE(77),  LTG_REDUCE(77),  LTG_REDUCE(77),  LTG_REDUCE(77),  LTG_REDUCE(77),  LTG_REDUCE(77),  LTG_REDUCE(77),  LTG_REDUCE(77),  LTG_REDUCE(77),  LTG_REDUCE(77),  LTG_REDUCE(77),  LTG_REDUCE(77),  LTG_REDUCE(77),  LTG_REDUCE(77),  LTG_REDUCE(77),  LTG_REDUCE(77),  LTG_SHIFT(122),  LTG_SHIFT(123),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(77),  LTG_REDUCE(77),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(78),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(78),  LTG_REDUCE(78),  LTG_REDUCE(78),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(78),  LTG_REDUCE(78),  LTG_REDUCE(78),  LTG_REDUCE(78),  LTG_REDUCE(78),  LTG_REDUCE(78),  LTG_REDUCE(78),  LTG_REDUCE(78),  LTG_REDUCE(78),  LTG_REDUCE(78),  LTG_REDUCE(78),  LTG_REDUCE(78),  LTG_REDUCE(78),  LTG_REDUCE(78),  LTG_REDUCE(78),  LTG_REDUCE(78),  LTG_REDUCE(78),  LTG_REDUCE(78),  LTG_REDUCE(78),  LTG_REDUCE(78),  LTG_REDUCE(78),  LTG_REDUCE(78),  LTG_REDUCE(78),  LTG_REDUCE(78),  LTG_SHIFT(122),  LTG_SHIFT(123),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(78),  LTG_REDUCE(78),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(80),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(80),  LTG_REDUCE(80),  LTG_REDUCE(80),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(80),  LTG_REDUCE(80),  LTG_REDUCE(80),  LTG_REDUCE(80),  LTG_REDUCE(80),  LTG_REDUCE(80),  LTG_REDUCE(80),  LTG_REDUCE(80),  LTG_REDUCE(80),  LTG_REDUCE(80),  LTG_REDUCE(80),  LTG_REDUCE(80),  LTG_REDUCE(80),  LTG_REDUCE(80),  LTG_REDUCE(80),  LTG_REDUCE(80),  LTG_REDUCE(80),  LTG_REDUCE(80),  LTG_REDUCE(80),  LTG_REDUCE(80),  LTG_REDUCE(80),  LTG_REDUCE(80),  LTG_REDUCE(80),  LTG_REDUCE(80),  LTG_REDUCE(80),  LTG_REDUCE(80),       ltg_blank,  LTG_SHIFT(124),  LTG_SHIFT(125),  LTG_SHIFT(126),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(80),  LTG_REDUCE(80),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(81),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(81),  LTG_REDUCE(81),  LTG_REDUCE(81),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(81),  LTG_REDUCE(81),  LTG_REDUCE(81),  LTG_REDUCE(81),  LTG_REDUCE(81),  LTG_REDUCE(81),  LTG_REDUCE(81),  LTG_REDUCE(81),  LTG_REDUCE(81),  LTG_REDUCE(81),  LTG_REDUCE(81),  LTG_REDUCE(81),  LTG_REDUCE(81),  LTG_REDUCE(81),  LTG_REDUCE(81),  LTG_REDUCE(81),  LTG_REDUCE(81),  LTG_REDUCE(81),  LTG_REDUCE(81),  LTG_REDUCE(81),  LTG_REDUCE(81),  LTG_REDUCE(81),  LTG_REDUCE(81),  LTG_REDUCE(81),  LTG_REDUCE(81),  LTG_REDUCE(81),       ltg_blank,  LTG_SHIFT(124),  LTG_SHIFT(125),  LTG_SHIFT(126),       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(81),  LTG_REDUCE(81),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(83),       ltg_blank,       ltg_blank,  LTG_SHIFT(129),  LTG_REDUCE(83),  LTG_REDUCE(83),  LTG_REDUCE(83),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(83),  LTG_REDUCE(83),  LTG_REDUCE(83),  LTG_REDUCE(83),  LTG_REDUCE(83),  LTG_REDUCE(83),  LTG_REDUCE(83),  LTG_REDUCE(83),  LTG_REDUCE(83),  LTG_REDUCE(83),  LTG_REDUCE(83),  LTG_REDUCE(83),  LTG_REDUCE(83),  LTG_REDUCE(83),  LTG_REDUCE(83),  LTG_REDUCE(83),  LTG_REDUCE(83),  LTG_REDUCE(83),  LTG_REDUCE(83),  LTG_REDUCE(83),  LTG_REDUCE(83),  LTG_REDUCE(83),  LTG_REDUCE(83),  LTG_REDUCE(83),  LTG_REDUCE(83),  LTG_REDUCE(83),       ltg_blank,  LTG_REDUCE(83),  LTG_REDUCE(83),  LTG_REDUCE(83),  LTG_SHIFT(127),  LTG_SHIFT(128),       ltg_blank,  LTG_REDUCE(83),  LTG_REDUCE(83),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(84),       ltg_blank,       ltg_blank,  LTG_SHIFT(129),  LTG_REDUCE(84),  LTG_REDUCE(84),  LTG_REDUCE(84),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(84),  LTG_REDUCE(84),  LTG_REDUCE(84),  LTG_REDUCE(84),  LTG_REDUCE(84),  LTG_REDUCE(84),  LTG_REDUCE(84),  LTG_REDUCE(84),  LTG_REDUCE(84),  LTG_REDUCE(84),  LTG_REDUCE(84),  LTG_REDUCE(84),  LTG_REDUCE(84),  LTG_REDUCE(84),  LTG_REDUCE(84),  LTG_REDUCE(84),  LTG_REDUCE(84),  LTG_REDUCE(84),  LTG_REDUCE(84),  LTG_REDUCE(84),  LTG_REDUCE(84),  LTG_REDUCE(84),  LTG_REDUCE(84),  LTG_REDUCE(84),  LTG_REDUCE(84),  LTG_REDUCE(84),       ltg_blank,  LTG_REDUCE(84),  LTG_REDUCE(84),  LTG_REDUCE(84),  LTG_SHIFT(127),  LTG_SHIFT(128),       ltg_blank,  LTG_REDUCE(84),  LTG_REDUCE(84),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(85),       ltg_blank,       ltg_blank,  LTG_SHIFT(129),  LTG_REDUCE(85),  LTG_REDUCE(85),  LTG_REDUCE(85),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(85),  LTG_REDUCE(85),  LTG_REDUCE(85),  LTG_REDUCE(85),  LTG_REDUCE(85),  LTG_REDUCE(85),  LTG_REDUCE(85),  LTG_REDUCE(85),  LTG_REDUCE(85),  LTG_REDUCE(85),  LTG_REDUCE(85),  LTG_REDUCE(85),  LTG_REDUCE(85),  LTG_REDUCE(85),  LTG_REDUCE(85),  LTG_REDUCE(85),  LTG_REDUCE(85),  LTG_REDUCE(85),  LTG_REDUCE(85),  LTG_REDUCE(85),  LTG_REDUCE(85),  LTG_REDUCE(85),  LTG_REDUCE(85),  LTG_REDUCE(85),  LTG_REDUCE(85),  LTG_REDUCE(85),       ltg_blank,  LTG_REDUCE(85),  LTG_REDUCE(85),  LTG_REDUCE(85),  LTG_SHIFT(127),  LTG_SHIFT(128),       ltg_blank,  LTG_REDUCE(85),  LTG_REDUCE(85),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_SHIFT(201),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(95),   LTG_SHIFT(96),   LTG_SHIFT(97),   LTG_SHIFT(98),   LTG_SHIFT(99),  LTG_SHIFT(100),  LTG_SHIFT(101),  LTG_SHIFT(102),  LTG_SHIFT(103),  LTG_SHIFT(104),  LTG_SHIFT(105),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_SHIFT(106),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(202),
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(99),       ltg_blank,       ltg_blank,  LTG_REDUCE(99),  LTG_REDUCE(99),  LTG_REDUCE(99),  LTG_REDUCE(99),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(99),  LTG_REDUCE(99),  LTG_REDUCE(99),  LTG_REDUCE(99),  LTG_REDUCE(99),  LTG_REDUCE(99),  LTG_REDUCE(99),  LTG_REDUCE(99),  LTG_REDUCE(99),  LTG_REDUCE(99),  LTG_REDUCE(99),  LTG_REDUCE(99),  LTG_REDUCE(99),  LTG_REDUCE(99),  LTG_REDUCE(99),  LTG_REDUCE(99),  LTG_REDUCE(99),  LTG_REDUCE(99),  LTG_REDUCE(99),  LTG_REDUCE(99),  LTG_REDUCE(99),  LTG_REDUCE(99),  LTG_REDUCE(99),  LTG_REDUCE(99),  LTG_REDUCE(99),  LTG_REDUCE(99),       ltg_blank,  LTG_REDUCE(99),  LTG_REDUCE(99),  LTG_REDUCE(99),  LTG_REDUCE(99),  LTG_REDUCE(99),       ltg_blank,  LTG_REDUCE(99),  LTG_REDUCE(99),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(104),       ltg_blank,       ltg_blank, LTG_REDUCE(104), LTG_REDUCE(104), LTG_REDUCE(104), LTG_REDUCE(104),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(104), LTG_REDUCE(104), LTG_REDUCE(104), LTG_REDUCE(104), LTG_REDUCE(104), LTG_REDUCE(104), LTG_REDUCE(104), LTG_REDUCE(104), LTG_REDUCE(104), LTG_REDUCE(104), LTG_REDUCE(104), LTG_REDUCE(104), LTG_REDUCE(104), LTG_REDUCE(104), LTG_REDUCE(104), LTG_REDUCE(104), LTG_REDUCE(104), LTG_REDUCE(104), LTG_REDUCE(104), LTG_REDUCE(104), LTG_REDUCE(104), LTG_REDUCE(104), LTG_REDUCE(104), LTG_REDUCE(104), LTG_REDUCE(104), LTG_REDUCE(104),       ltg_blank, LTG_REDUCE(104), LTG_REDUCE(104), LTG_REDUCE(104), LTG_REDUCE(104), LTG_REDUCE(104),       ltg_blank, LTG_REDUCE(104), LTG_REDUCE(104),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(106),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_SHIFT(203),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(109),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(109),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_REDUCE(8),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_REDUCE(8),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
  LTG_REDUCE(48),  LTG_REDUCE(48),  LTG_REDUCE(48),  LTG_REDUCE(48),  LTG_REDUCE(48),  LTG_REDUCE(48),  LTG_REDUCE(48),  LTG_REDUCE(48),  LTG_REDUCE(48),  LTG_REDUCE(48),  LTG_REDUCE(48),  LTG_REDUCE(48),  LTG_REDUCE(48),  LTG_REDUCE(48),  LTG_REDUCE(48),       ltg_blank,  LTG_REDUCE(48),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(48),  LTG_REDUCE(48),  LTG_REDUCE(48),       ltg_blank,  LTG_REDUCE(48),  LTG_REDUCE(48),  LTG_REDUCE(48),  LTG_REDUCE(48),  LTG_REDUCE(48),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(48),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(48),  LTG_REDUCE(48),       ltg_blank,  LTG_REDUCE(48),       ltg_blank,       ltg_blank,  LTG_REDUCE(48),  LTG_REDUCE(48),  LTG_REDUCE(48),       ltg_blank,       ltg_blank,  LTG_REDUCE(48),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_SHIFT(204),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(21),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(26),  LTG_REDUCE(26),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_SHIFT(205),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(97),       ltg_blank,       ltg_blank,  LTG_REDUCE(97),  LTG_REDUCE(97),  LTG_REDUCE(97),  LTG_REDUCE(97),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(97),  LTG_REDUCE(97),  LTG_REDUCE(97),  LTG_REDUCE(97),  LTG_REDUCE(97),  LTG_REDUCE(97),  LTG_REDUCE(97),  LTG_REDUCE(97),  LTG_REDUCE(97),  LTG_REDUCE(97),  LTG_REDUCE(97),  LTG_REDUCE(97),  LTG_REDUCE(97),  LTG_REDUCE(97),  LTG_REDUCE(97),  LTG_REDUCE(97),  LTG_REDUCE(97),  LTG_REDUCE(97),  LTG_REDUCE(97),  LTG_REDUCE(97),  LTG_REDUCE(97),  LTG_REDUCE(97),  LTG_REDUCE(97),  LTG_REDUCE(97),  LTG_REDUCE(97),  LTG_REDUCE(97),       ltg_blank,  LTG_REDUCE(97),  LTG_REDUCE(97),  LTG_REDUCE(97),  LTG_REDUCE(97),  LTG_REDUCE(97),       ltg_blank,  LTG_REDUCE(97),  LTG_REDUCE(97),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(98),       ltg_blank,       ltg_blank,  LTG_SHIFT(129),  LTG_REDUCE(98),  LTG_REDUCE(98),  LTG_REDUCE(98),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(98),  LTG_REDUCE(98),  LTG_REDUCE(98),  LTG_REDUCE(98),  LTG_REDUCE(98),  LTG_REDUCE(98),  LTG_REDUCE(98),  LTG_REDUCE(98),  LTG_REDUCE(98),  LTG_REDUCE(98),  LTG_REDUCE(98),  LTG_REDUCE(98),  LTG_REDUCE(98),  LTG_REDUCE(98),  LTG_REDUCE(98),  LTG_REDUCE(98),  LTG_REDUCE(98),  LTG_REDUCE(98),  LTG_REDUCE(98),  LTG_REDUCE(98),  LTG_REDUCE(98),  LTG_REDUCE(98),  LTG_REDUCE(98),  LTG_REDUCE(98),  LTG_REDUCE(98),  LTG_REDUCE(98),       ltg_blank,  LTG_REDUCE(98),  LTG_REDUCE(98),  LTG_REDUCE(98),  LTG_SHIFT(127),  LTG_SHIFT(128),       ltg_blank,  LTG_REDUCE(98),  LTG_REDUCE(98),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
   LTG_SHIFT(54),   LTG_SHIFT(55),   LTG_SHIFT(56),   LTG_SHIFT(57),   LTG_SHIFT(58),   LTG_SHIFT(59),   LTG_SHIFT(60),   LTG_SHIFT(61),   LTG_SHIFT(62),   LTG_SHIFT(63),   LTG_SHIFT(64),   LTG_SHIFT(65),       ltg_blank,   LTG_SHIFT(53),   LTG_SHIFT(52),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(51),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_SHIFT(46),   LTG_SHIFT(47),       ltg_blank,   LTG_SHIFT(50),       ltg_blank,       ltg_blank,   LTG_SHIFT(44),   LTG_SHIFT(45),   LTG_SHIFT(48),       ltg_blank,       ltg_blank,   LTG_SHIFT(49),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,   LTG_GOTO(206),    LTG_GOTO(37),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,    LTG_GOTO(35),    LTG_GOTO(36),    LTG_GOTO(38),    LTG_GOTO(39),    LTG_GOTO(40),    LTG_GOTO(41),    LTG_GOTO(42),    LTG_GOTO(43),
  LTG_REDUCE(41),  LTG_REDUCE(41),  LTG_REDUCE(41),  LTG_REDUCE(41),  LTG_REDUCE(41),  LTG_REDUCE(41),  LTG_REDUCE(41),  LTG_REDUCE(41),  LTG_REDUCE(41),  LTG_REDUCE(41),  LTG_REDUCE(41),  LTG_REDUCE(41),  LTG_REDUCE(41),  LTG_REDUCE(41),  LTG_REDUCE(41),       ltg_blank,  LTG_REDUCE(41),  LTG_REDUCE(41),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(41),  LTG_REDUCE(41),  LTG_REDUCE(41),  LTG_REDUCE(41),  LTG_REDUCE(41),  LTG_REDUCE(41),  LTG_REDUCE(41),  LTG_REDUCE(41),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(41),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(41),  LTG_REDUCE(41),       ltg_blank,  LTG_REDUCE(41),       ltg_blank,       ltg_blank,  LTG_REDUCE(41),  LTG_REDUCE(41),  LTG_REDUCE(41),       ltg_blank,       ltg_blank,  LTG_REDUCE(41),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,  LTG_REDUCE(27),  LTG_REDUCE(27),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(108),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank, LTG_REDUCE(108),       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,       ltg_blank,
};/*}}}*/

/*
 * methods of generated structures
 */

// -- val_type_s --
@begin
methods val_type_s
@end

// -- val_types_s --
@begin
methods val_types_s
@end

// -- val_record_s --
@begin
methods val_record_s
@end

// -- val_records_s --
@begin
methods val_records_s
@end

// -- fun_record_s --
@begin
methods fun_record_s
@end

// -- fun_records_s --
@begin
methods fun_records_s
@end

// -- ltg_parser_s --
@begin
methods ltg_parser_s
@end

unsigned ltg_parser_s::recognize_type(unsigned a_length,const char *a_data)
{/*{{{*/
#define GET_LTG_TYPE_NEXT_CHAR() \
{\
   if (input_idx < a_length) {\
      in_char = (unsigned char)a_data[input_idx];\
   }\
   else {\
      in_char = '\0';\
   }\
}

#define CLOSE_LTG_TYPE_CHAR(RET_TERM_IDX) \
{\
   if (in_char == '\0') {\
      return RET_TERM_IDX;\
   }\
\
   input_idx++;\
}

   unsigned input_idx = 0;
   unsigned short in_char;

// - STATE 0 -
   GET_LTG_TYPE_NEXT_CHAR();

   if (in_char == 102)
      goto state_1_label;

   if (in_char == 105)
      goto state_2_label;

   if (in_char == 117)
      goto state_3_label;

   return c_idx_not_exist;

// - STATE 1 -
state_1_label:
   CLOSE_LTG_TYPE_CHAR(c_idx_not_exist);
   GET_LTG_TYPE_NEXT_CHAR();

   if (in_char == 51)
      goto state_4_label;

   if (in_char == 54)
      goto state_5_label;

   return c_idx_not_exist;

// - STATE 2 -
state_2_label:
   CLOSE_LTG_TYPE_CHAR(c_idx_not_exist);
   GET_LTG_TYPE_NEXT_CHAR();

   if (in_char == 49)
      goto state_6_label;

   if (in_char == 51)
      goto state_7_label;

   if (in_char == 54)
      goto state_8_label;

   if (in_char == 56)
      goto state_9_label;

   return c_idx_not_exist;

// - STATE 3 -
state_3_label:
   CLOSE_LTG_TYPE_CHAR(c_idx_not_exist);
   GET_LTG_TYPE_NEXT_CHAR();

   if (in_char == 49)
      goto state_10_label;

   if (in_char == 51)
      goto state_11_label;

   if (in_char == 54)
      goto state_12_label;

   if (in_char == 56)
      goto state_13_label;

   return c_idx_not_exist;

// - STATE 4 -
state_4_label:
   CLOSE_LTG_TYPE_CHAR(c_idx_not_exist);
   GET_LTG_TYPE_NEXT_CHAR();

   if (in_char == 50)
      goto state_14_label;

   return c_idx_not_exist;

// - STATE 5 -
state_5_label:
   CLOSE_LTG_TYPE_CHAR(c_idx_not_exist);
   GET_LTG_TYPE_NEXT_CHAR();

   if (in_char == 52)
      goto state_15_label;

   return c_idx_not_exist;

// - STATE 6 -
state_6_label:
   CLOSE_LTG_TYPE_CHAR(c_idx_not_exist);
   GET_LTG_TYPE_NEXT_CHAR();

   if (in_char == 54)
      goto state_16_label;

   return c_idx_not_exist;

// - STATE 7 -
state_7_label:
   CLOSE_LTG_TYPE_CHAR(c_idx_not_exist);
   GET_LTG_TYPE_NEXT_CHAR();

   if (in_char == 50)
      goto state_17_label;

   return c_idx_not_exist;

// - STATE 8 -
state_8_label:
   CLOSE_LTG_TYPE_CHAR(c_idx_not_exist);
   GET_LTG_TYPE_NEXT_CHAR();

   if (in_char == 52)
      goto state_18_label;

   return c_idx_not_exist;

// - STATE 9 -
state_9_label:
   CLOSE_LTG_TYPE_CHAR(c_val_type_i8);
   return c_val_type_i8;

// - STATE 10 -
state_10_label:
   CLOSE_LTG_TYPE_CHAR(c_idx_not_exist);
   GET_LTG_TYPE_NEXT_CHAR();

   if (in_char == 54)
      goto state_19_label;

   return c_idx_not_exist;

// - STATE 11 -
state_11_label:
   CLOSE_LTG_TYPE_CHAR(c_idx_not_exist);
   GET_LTG_TYPE_NEXT_CHAR();

   if (in_char == 50)
      goto state_20_label;

   return c_idx_not_exist;

// - STATE 12 -
state_12_label:
   CLOSE_LTG_TYPE_CHAR(c_idx_not_exist);
   GET_LTG_TYPE_NEXT_CHAR();

   if (in_char == 52)
      goto state_21_label;

   return c_idx_not_exist;

// - STATE 13 -
state_13_label:
   CLOSE_LTG_TYPE_CHAR(c_val_type_u8);
   return c_val_type_u8;

// - STATE 14 -
state_14_label:
   CLOSE_LTG_TYPE_CHAR(c_val_type_f32);
   return c_val_type_f32;

// - STATE 15 -
state_15_label:
   CLOSE_LTG_TYPE_CHAR(c_val_type_f64);
   return c_val_type_f64;

// - STATE 16 -
state_16_label:
   CLOSE_LTG_TYPE_CHAR(c_val_type_i16);
   return c_val_type_i16;

// - STATE 17 -
state_17_label:
   CLOSE_LTG_TYPE_CHAR(c_val_type_i32);
   return c_val_type_i32;

// - STATE 18 -
state_18_label:
   CLOSE_LTG_TYPE_CHAR(c_val_type_i64);
   return c_val_type_i64;

// - STATE 19 -
state_19_label:
   CLOSE_LTG_TYPE_CHAR(c_val_type_u16);
   return c_val_type_u16;

// - STATE 20 -
state_20_label:
   CLOSE_LTG_TYPE_CHAR(c_val_type_u32);
   return c_val_type_u32;

// - STATE 21 -
state_21_label:
   CLOSE_LTG_TYPE_CHAR(c_val_type_u64);
   return c_val_type_u64;

}/*}}}*/

void ltg_parser_s::create_signature(unsigned a_name_length,char *a_name_data,unsigned a_param_cnt,val_type_s **a_param_types,string_s &a_target)
{/*{{{*/

  // - determine signature length -
  unsigned length = a_name_length + 1;

  if (a_param_cnt > 0)
  {
    val_type_s **pt_ptr = a_param_types;
    val_type_s **pt_ptr_end = pt_ptr + a_param_cnt;
    do {
      length += c_type_str_lengths[(*pt_ptr)->type_id] + 1;

      unsigned pointer_level = (*pt_ptr)->pointer_level;
      if (pointer_level > 0)
      {
        length += 1 + pointer_level;
      }
    } while(++pt_ptr < pt_ptr_end);
  }
  else
  {
    length += 1;
  }

  // - format signature to string -
  a_target.create(length);

  char *b_ptr = a_target.data;
  char *b_ptr_end = b_ptr + a_target.size;

  // - function name -
  memcpy(b_ptr,a_name_data,a_name_length);
  b_ptr += a_name_length;

  *b_ptr++ = '(';

  if (a_param_cnt > 0)
  {
    // - parameter type -
    val_type_s **pt_ptr = a_param_types;
    val_type_s **pt_ptr_end = pt_ptr + a_param_cnt;
    do {
      b_ptr += snprintf(b_ptr,b_ptr_end - b_ptr,"%s",c_type_strings[(*pt_ptr)->type_id]);

      // - parameter pointers -
      unsigned pointer_level = (*pt_ptr)->pointer_level;
      if (pointer_level > 0)
      {
        *b_ptr++ = ' ';
        while (pointer_level-- > 0) *b_ptr++ = '*';
      }

      b_ptr += snprintf(b_ptr,b_ptr_end - b_ptr,"%c",(pt_ptr + 1) >= pt_ptr_end ? ')' : ',');
    } while(++pt_ptr < pt_ptr_end);
  }
  else
  {
    *b_ptr++ = ')';
  }
}/*}}}*/

unsigned ltg_parser_s::recognize_terminal(unsigned &input_idx)
{/*{{{*/
  unsigned source_string_length = source_string.size - 1;

#define GET_LTG_NEXT_CHAR() \
  {\
    if (input_idx < source_string_length) {\
      in_char = (unsigned char)source_string[input_idx];\
    }\
    else {\
      in_char = '\0';\
    }\
  }

#define CLOSE_LTG_CHAR(RET_TERM_IDX) \
  {\
    if (in_char == '\0') {\
      return RET_TERM_IDX;\
    }\
\
    input_idx++;\
  }

   unsigned short in_char;

// - STATE 0 -
   GET_LTG_NEXT_CHAR();

   if (in_char == 0)
      goto state_1_label;

   if (in_char >= 8 && in_char < 14)
      goto state_41_label;

   if (in_char == 32)
      goto state_41_label;

   if (in_char == 33)
      goto state_2_label;

   if (in_char == 35)
      goto state_3_label;

   if (in_char == 37)
      goto state_4_label;

   if (in_char == 38)
      goto state_5_label;

   if (in_char == 39)
      goto state_6_label;

   if (in_char == 40)
      goto state_7_label;

   if (in_char == 41)
      goto state_8_label;

   if (in_char == 42)
      goto state_9_label;

   if (in_char == 43)
      goto state_10_label;

   if (in_char == 44)
      goto state_11_label;

   if (in_char == 45)
      goto state_12_label;

   if (in_char == 46)
      goto state_13_label;

   if (in_char == 47)
      goto state_14_label;

   if (in_char == 48)
      goto state_15_label;

   if (in_char >= 49 && in_char < 58)
      goto state_16_label;

   if (in_char == 58)
      goto state_17_label;

   if (in_char == 59)
      goto state_18_label;

   if (in_char == 60)
      goto state_19_label;

   if (in_char == 61)
      goto state_20_label;

   if (in_char == 62)
      goto state_21_label;

   if (in_char == 63)
      goto state_22_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 91)
      goto state_23_label;

   if (in_char == 93)
      goto state_24_label;

   if (in_char == 94)
      goto state_25_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char == 97)
      goto state_26_label;

   if (in_char == 98)
      goto state_27_label;

   if (in_char == 99)
      goto state_28_label;

   if (in_char == 100)
      goto state_29_label;

   if (in_char == 101)
      goto state_30_label;

   if (in_char == 102)
      goto state_31_label;

   if (in_char >= 103 && in_char < 105)
      goto state_26_label;

   if (in_char == 105)
      goto state_32_label;

   if (in_char >= 106 && in_char < 114)
      goto state_26_label;

   if (in_char == 114)
      goto state_33_label;

   if (in_char >= 115 && in_char < 117)
      goto state_26_label;

   if (in_char == 117)
      goto state_34_label;

   if (in_char == 118)
      goto state_35_label;

   if (in_char == 119)
      goto state_36_label;

   if (in_char >= 120 && in_char < 123)
      goto state_26_label;

   if (in_char == 123)
      goto state_37_label;

   if (in_char == 124)
      goto state_38_label;

   if (in_char == 125)
      goto state_39_label;

   if (in_char == 126)
      goto state_40_label;

   return c_idx_not_exist;

// - STATE 1 -
state_1_label:
   CLOSE_LTG_CHAR(70);
   return 70;

// - STATE 2 -
state_2_label:
   CLOSE_LTG_CHAR(62);
   GET_LTG_NEXT_CHAR();

   if (in_char == 61)
      goto state_43_label;

   return 62;

// - STATE 3 -
state_3_label:
   CLOSE_LTG_CHAR(c_idx_not_exist);
   GET_LTG_NEXT_CHAR();

   if (in_char < 10)
      goto state_3_label;

   if (in_char == 10)
      goto state_44_label;

   if (in_char >= 11 && in_char < 257)
      goto state_3_label;

   return c_idx_not_exist;

// - STATE 4 -
state_4_label:
   CLOSE_LTG_CHAR(59);
   GET_LTG_NEXT_CHAR();

   if (in_char == 61)
      goto state_45_label;

   return 59;

// - STATE 5 -
state_5_label:
   CLOSE_LTG_CHAR(43);
   GET_LTG_NEXT_CHAR();

   if (in_char == 38)
      goto state_46_label;

   if (in_char == 61)
      goto state_47_label;

   return 43;

// - STATE 6 -
state_6_label:
   CLOSE_LTG_CHAR(c_idx_not_exist);
   GET_LTG_NEXT_CHAR();

   if (in_char < 92)
      goto state_49_label;

   if (in_char == 92)
      goto state_48_label;

   if (in_char >= 93 && in_char < 257)
      goto state_49_label;

   return c_idx_not_exist;

// - STATE 7 -
state_7_label:
   CLOSE_LTG_CHAR(14);
   return 14;

// - STATE 8 -
state_8_label:
   CLOSE_LTG_CHAR(15);
   return 15;

// - STATE 9 -
state_9_label:
   CLOSE_LTG_CHAR(57);
   GET_LTG_NEXT_CHAR();

   if (in_char == 61)
      goto state_50_label;

   return 57;

// - STATE 10 -
state_10_label:
   CLOSE_LTG_CHAR(54);
   GET_LTG_NEXT_CHAR();

   if (in_char == 43)
      goto state_51_label;

   if (in_char == 61)
      goto state_52_label;

   return 54;

// - STATE 11 -
state_11_label:
   CLOSE_LTG_CHAR(20);
   return 20;

// - STATE 12 -
state_12_label:
   CLOSE_LTG_CHAR(55);
   GET_LTG_NEXT_CHAR();

   if (in_char == 45)
      goto state_53_label;

   if (in_char == 61)
      goto state_54_label;

   return 55;

// - STATE 13 -
state_13_label:
   CLOSE_LTG_CHAR(56);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_55_label;

   return 56;

// - STATE 14 -
state_14_label:
   CLOSE_LTG_CHAR(58);
   GET_LTG_NEXT_CHAR();

   if (in_char == 42)
      goto state_56_label;

   if (in_char == 47)
      goto state_57_label;

   if (in_char == 61)
      goto state_58_label;

   return 58;

// - STATE 15 -
state_15_label:
   CLOSE_LTG_CHAR(4);
   GET_LTG_NEXT_CHAR();

   if (in_char == 46)
      goto state_59_label;

   if (in_char >= 48 && in_char < 56)
      goto state_60_label;

   if (in_char >= 56 && in_char < 58)
      goto state_42_label;

   if (in_char == 69)
      goto state_61_label;

   if (in_char == 70)
      goto state_62_label;

   if (in_char == 76)
      goto state_63_label;

   if (in_char == 88)
      goto state_64_label;

   if (in_char == 101)
      goto state_61_label;

   if (in_char == 102)
      goto state_62_label;

   if (in_char == 108)
      goto state_63_label;

   if (in_char == 120)
      goto state_64_label;

   return 4;

// - STATE 16 -
state_16_label:
   CLOSE_LTG_CHAR(5);
   GET_LTG_NEXT_CHAR();

   if (in_char == 46)
      goto state_59_label;

   if (in_char >= 48 && in_char < 58)
      goto state_16_label;

   if (in_char == 69)
      goto state_61_label;

   if (in_char == 70)
      goto state_62_label;

   if (in_char == 76)
      goto state_65_label;

   if (in_char == 101)
      goto state_61_label;

   if (in_char == 102)
      goto state_62_label;

   if (in_char == 108)
      goto state_65_label;

   return 5;

// - STATE 17 -
state_17_label:
   CLOSE_LTG_CHAR(64);
   return 64;

// - STATE 18 -
state_18_label:
   CLOSE_LTG_CHAR(21);
   return 21;

// - STATE 19 -
state_19_label:
   CLOSE_LTG_CHAR(49);
   GET_LTG_NEXT_CHAR();

   if (in_char == 60)
      goto state_66_label;

   if (in_char == 61)
      goto state_67_label;

   return 49;

// - STATE 20 -
state_20_label:
   CLOSE_LTG_CHAR(30);
   GET_LTG_NEXT_CHAR();

   if (in_char == 61)
      goto state_68_label;

   return 30;

// - STATE 21 -
state_21_label:
   CLOSE_LTG_CHAR(48);
   GET_LTG_NEXT_CHAR();

   if (in_char == 61)
      goto state_69_label;

   if (in_char == 62)
      goto state_70_label;

   return 48;

// - STATE 22 -
state_22_label:
   CLOSE_LTG_CHAR(63);
   return 63;

// - STATE 23 -
state_23_label:
   CLOSE_LTG_CHAR(18);
   return 18;

// - STATE 24 -
state_24_label:
   CLOSE_LTG_CHAR(19);
   return 19;

// - STATE 25 -
state_25_label:
   CLOSE_LTG_CHAR(45);
   GET_LTG_NEXT_CHAR();

   if (in_char == 61)
      goto state_71_label;

   return 45;

// - STATE 26 -
state_26_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 27 -
state_27_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 114)
      goto state_26_label;

   if (in_char == 114)
      goto state_72_label;

   if (in_char >= 115 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 28 -
state_28_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 111)
      goto state_26_label;

   if (in_char == 111)
      goto state_73_label;

   if (in_char >= 112 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 29 -
state_29_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 111)
      goto state_26_label;

   if (in_char == 111)
      goto state_74_label;

   if (in_char >= 112 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 30 -
state_30_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 108)
      goto state_26_label;

   if (in_char == 108)
      goto state_75_label;

   if (in_char >= 109 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 31 -
state_31_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 51)
      goto state_26_label;

   if (in_char == 51)
      goto state_76_label;

   if (in_char >= 52 && in_char < 54)
      goto state_26_label;

   if (in_char == 54)
      goto state_77_label;

   if (in_char >= 55 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 32 -
state_32_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char == 48)
      goto state_26_label;

   if (in_char == 49)
      goto state_78_label;

   if (in_char == 50)
      goto state_26_label;

   if (in_char == 51)
      goto state_79_label;

   if (in_char >= 52 && in_char < 54)
      goto state_26_label;

   if (in_char == 54)
      goto state_80_label;

   if (in_char == 55)
      goto state_26_label;

   if (in_char == 56)
      goto state_81_label;

   if (in_char == 57)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 102)
      goto state_26_label;

   if (in_char == 102)
      goto state_82_label;

   if (in_char >= 103 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 33 -
state_33_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 101)
      goto state_26_label;

   if (in_char == 101)
      goto state_83_label;

   if (in_char >= 102 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 34 -
state_34_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char == 48)
      goto state_26_label;

   if (in_char == 49)
      goto state_84_label;

   if (in_char == 50)
      goto state_26_label;

   if (in_char == 51)
      goto state_85_label;

   if (in_char >= 52 && in_char < 54)
      goto state_26_label;

   if (in_char == 54)
      goto state_86_label;

   if (in_char == 55)
      goto state_26_label;

   if (in_char == 56)
      goto state_81_label;

   if (in_char == 57)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 35 -
state_35_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 111)
      goto state_26_label;

   if (in_char == 111)
      goto state_87_label;

   if (in_char >= 112 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 36 -
state_36_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 104)
      goto state_26_label;

   if (in_char == 104)
      goto state_88_label;

   if (in_char >= 105 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 37 -
state_37_label:
   CLOSE_LTG_CHAR(16);
   return 16;

// - STATE 38 -
state_38_label:
   CLOSE_LTG_CHAR(44);
   GET_LTG_NEXT_CHAR();

   if (in_char == 61)
      goto state_89_label;

   if (in_char == 124)
      goto state_90_label;

   return 44;

// - STATE 39 -
state_39_label:
   CLOSE_LTG_CHAR(17);
   return 17;

// - STATE 40 -
state_40_label:
   CLOSE_LTG_CHAR(65);
   return 65;

// - STATE 41 -
state_41_label:
   CLOSE_LTG_CHAR(66);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 8 && in_char < 14)
      goto state_41_label;

   if (in_char == 32)
      goto state_41_label;

   return 66;

// - STATE 42 -
state_42_label:
   CLOSE_LTG_CHAR(c_idx_not_exist);
   GET_LTG_NEXT_CHAR();

   if (in_char == 46)
      goto state_59_label;

   if (in_char >= 48 && in_char < 58)
      goto state_42_label;

   if (in_char == 69)
      goto state_61_label;

   if (in_char == 70)
      goto state_62_label;

   if (in_char == 101)
      goto state_61_label;

   if (in_char == 102)
      goto state_62_label;

   return c_idx_not_exist;

// - STATE 43 -
state_43_label:
   CLOSE_LTG_CHAR(47);
   return 47;

// - STATE 44 -
state_44_label:
   CLOSE_LTG_CHAR(67);
   return 67;

// - STATE 45 -
state_45_label:
   CLOSE_LTG_CHAR(35);
   return 35;

// - STATE 46 -
state_46_label:
   CLOSE_LTG_CHAR(41);
   return 41;

// - STATE 47 -
state_47_label:
   CLOSE_LTG_CHAR(38);
   return 38;

// - STATE 48 -
state_48_label:
   CLOSE_LTG_CHAR(c_idx_not_exist);
   GET_LTG_NEXT_CHAR();

   if (in_char == 34)
      goto state_91_label;

   if (in_char == 39)
      goto state_92_label;

   if (in_char >= 48 && in_char < 56)
      goto state_93_label;

   if (in_char == 63)
      goto state_91_label;

   if (in_char == 92)
      goto state_91_label;

   if (in_char >= 97 && in_char < 99)
      goto state_91_label;

   if (in_char == 102)
      goto state_91_label;

   if (in_char == 110)
      goto state_91_label;

   if (in_char == 114)
      goto state_91_label;

   if (in_char == 116)
      goto state_91_label;

   if (in_char == 118)
      goto state_91_label;

   if (in_char == 120)
      goto state_94_label;

   return c_idx_not_exist;

// - STATE 49 -
state_49_label:
   CLOSE_LTG_CHAR(c_idx_not_exist);
   GET_LTG_NEXT_CHAR();

   if (in_char == 39)
      goto state_95_label;

   return c_idx_not_exist;

// - STATE 50 -
state_50_label:
   CLOSE_LTG_CHAR(33);
   return 33;

// - STATE 51 -
state_51_label:
   CLOSE_LTG_CHAR(60);
   return 60;

// - STATE 52 -
state_52_label:
   CLOSE_LTG_CHAR(31);
   return 31;

// - STATE 53 -
state_53_label:
   CLOSE_LTG_CHAR(61);
   return 61;

// - STATE 54 -
state_54_label:
   CLOSE_LTG_CHAR(32);
   return 32;

// - STATE 55 -
state_55_label:
   CLOSE_LTG_CHAR(11);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_55_label;

   if (in_char == 69)
      goto state_61_label;

   if (in_char == 70)
      goto state_62_label;

   if (in_char == 101)
      goto state_61_label;

   if (in_char == 102)
      goto state_62_label;

   return 11;

// - STATE 56 -
state_56_label:
   CLOSE_LTG_CHAR(c_idx_not_exist);
   GET_LTG_NEXT_CHAR();

   if (in_char < 42)
      goto state_56_label;

   if (in_char == 42)
      goto state_96_label;

   if (in_char >= 43 && in_char < 257)
      goto state_56_label;

   return c_idx_not_exist;

// - STATE 57 -
state_57_label:
   CLOSE_LTG_CHAR(c_idx_not_exist);
   GET_LTG_NEXT_CHAR();

   if (in_char < 10)
      goto state_57_label;

   if (in_char == 10)
      goto state_97_label;

   if (in_char >= 11 && in_char < 257)
      goto state_57_label;

   return c_idx_not_exist;

// - STATE 58 -
state_58_label:
   CLOSE_LTG_CHAR(34);
   return 34;

// - STATE 59 -
state_59_label:
   CLOSE_LTG_CHAR(11);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_55_label;

   if (in_char == 69)
      goto state_61_label;

   if (in_char == 70)
      goto state_62_label;

   if (in_char == 101)
      goto state_61_label;

   if (in_char == 102)
      goto state_62_label;

   return 11;

// - STATE 60 -
state_60_label:
   CLOSE_LTG_CHAR(4);
   GET_LTG_NEXT_CHAR();

   if (in_char == 46)
      goto state_59_label;

   if (in_char >= 48 && in_char < 56)
      goto state_60_label;

   if (in_char >= 56 && in_char < 58)
      goto state_42_label;

   if (in_char == 69)
      goto state_61_label;

   if (in_char == 70)
      goto state_62_label;

   if (in_char == 76)
      goto state_63_label;

   if (in_char == 101)
      goto state_61_label;

   if (in_char == 102)
      goto state_62_label;

   if (in_char == 108)
      goto state_63_label;

   return 4;

// - STATE 61 -
state_61_label:
   CLOSE_LTG_CHAR(c_idx_not_exist);
   GET_LTG_NEXT_CHAR();

   if (in_char == 43)
      goto state_98_label;

   if (in_char == 45)
      goto state_98_label;

   if (in_char >= 48 && in_char < 58)
      goto state_99_label;

   return c_idx_not_exist;

// - STATE 62 -
state_62_label:
   CLOSE_LTG_CHAR(10);
   return 10;

// - STATE 63 -
state_63_label:
   CLOSE_LTG_CHAR(7);
   return 7;

// - STATE 64 -
state_64_label:
   CLOSE_LTG_CHAR(c_idx_not_exist);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_100_label;

   if (in_char >= 65 && in_char < 71)
      goto state_100_label;

   if (in_char >= 97 && in_char < 103)
      goto state_100_label;

   return c_idx_not_exist;

// - STATE 65 -
state_65_label:
   CLOSE_LTG_CHAR(8);
   return 8;

// - STATE 66 -
state_66_label:
   CLOSE_LTG_CHAR(53);
   GET_LTG_NEXT_CHAR();

   if (in_char == 61)
      goto state_101_label;

   return 53;

// - STATE 67 -
state_67_label:
   CLOSE_LTG_CHAR(51);
   return 51;

// - STATE 68 -
state_68_label:
   CLOSE_LTG_CHAR(46);
   return 46;

// - STATE 69 -
state_69_label:
   CLOSE_LTG_CHAR(50);
   return 50;

// - STATE 70 -
state_70_label:
   CLOSE_LTG_CHAR(52);
   GET_LTG_NEXT_CHAR();

   if (in_char == 61)
      goto state_102_label;

   return 52;

// - STATE 71 -
state_71_label:
   CLOSE_LTG_CHAR(40);
   return 40;

// - STATE 72 -
state_72_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 101)
      goto state_26_label;

   if (in_char == 101)
      goto state_103_label;

   if (in_char >= 102 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 73 -
state_73_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 110)
      goto state_26_label;

   if (in_char == 110)
      goto state_104_label;

   if (in_char >= 111 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 74 -
state_74_label:
   CLOSE_LTG_CHAR(25);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 25;

// - STATE 75 -
state_75_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 115)
      goto state_26_label;

   if (in_char == 115)
      goto state_105_label;

   if (in_char >= 116 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 76 -
state_76_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 50)
      goto state_26_label;

   if (in_char == 50)
      goto state_81_label;

   if (in_char >= 51 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 77 -
state_77_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 52)
      goto state_26_label;

   if (in_char == 52)
      goto state_81_label;

   if (in_char >= 53 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 78 -
state_78_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 54)
      goto state_26_label;

   if (in_char == 54)
      goto state_81_label;

   if (in_char >= 55 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 79 -
state_79_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 50)
      goto state_26_label;

   if (in_char == 50)
      goto state_81_label;

   if (in_char >= 51 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 80 -
state_80_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 52)
      goto state_26_label;

   if (in_char == 52)
      goto state_81_label;

   if (in_char >= 53 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 81 -
state_81_label:
   CLOSE_LTG_CHAR(12);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 12;

// - STATE 82 -
state_82_label:
   CLOSE_LTG_CHAR(23);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 23;

// - STATE 83 -
state_83_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 116)
      goto state_26_label;

   if (in_char == 116)
      goto state_106_label;

   if (in_char >= 117 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 84 -
state_84_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 54)
      goto state_26_label;

   if (in_char == 54)
      goto state_81_label;

   if (in_char >= 55 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 85 -
state_85_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 50)
      goto state_26_label;

   if (in_char == 50)
      goto state_81_label;

   if (in_char >= 51 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 86 -
state_86_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 52)
      goto state_26_label;

   if (in_char == 52)
      goto state_81_label;

   if (in_char >= 53 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 87 -
state_87_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 108)
      goto state_26_label;

   if (in_char == 108)
      goto state_107_label;

   if (in_char >= 109 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 88 -
state_88_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 105)
      goto state_26_label;

   if (in_char == 105)
      goto state_108_label;

   if (in_char >= 106 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 89 -
state_89_label:
   CLOSE_LTG_CHAR(39);
   return 39;

// - STATE 90 -
state_90_label:
   CLOSE_LTG_CHAR(42);
   return 42;

// - STATE 91 -
state_91_label:
   CLOSE_LTG_CHAR(c_idx_not_exist);
   GET_LTG_NEXT_CHAR();

   if (in_char == 39)
      goto state_109_label;

   return c_idx_not_exist;

// - STATE 92 -
state_92_label:
   CLOSE_LTG_CHAR(0);
   GET_LTG_NEXT_CHAR();

   if (in_char == 39)
      goto state_109_label;

   return 0;

// - STATE 93 -
state_93_label:
   CLOSE_LTG_CHAR(c_idx_not_exist);
   GET_LTG_NEXT_CHAR();

   if (in_char == 39)
      goto state_110_label;

   if (in_char >= 48 && in_char < 56)
      goto state_111_label;

   return c_idx_not_exist;

// - STATE 94 -
state_94_label:
   CLOSE_LTG_CHAR(c_idx_not_exist);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_112_label;

   if (in_char >= 65 && in_char < 71)
      goto state_112_label;

   if (in_char >= 97 && in_char < 103)
      goto state_112_label;

   return c_idx_not_exist;

// - STATE 95 -
state_95_label:
   CLOSE_LTG_CHAR(0);
   return 0;

// - STATE 96 -
state_96_label:
   CLOSE_LTG_CHAR(c_idx_not_exist);
   GET_LTG_NEXT_CHAR();

   if (in_char < 47)
      goto state_56_label;

   if (in_char == 47)
      goto state_113_label;

   if (in_char >= 48 && in_char < 257)
      goto state_56_label;

   return c_idx_not_exist;

// - STATE 97 -
state_97_label:
   CLOSE_LTG_CHAR(68);
   return 68;

// - STATE 98 -
state_98_label:
   CLOSE_LTG_CHAR(c_idx_not_exist);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_99_label;

   return c_idx_not_exist;

// - STATE 99 -
state_99_label:
   CLOSE_LTG_CHAR(11);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_99_label;

   if (in_char == 70)
      goto state_62_label;

   if (in_char == 102)
      goto state_62_label;

   return 11;

// - STATE 100 -
state_100_label:
   CLOSE_LTG_CHAR(6);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_100_label;

   if (in_char >= 65 && in_char < 71)
      goto state_100_label;

   if (in_char == 76)
      goto state_114_label;

   if (in_char >= 97 && in_char < 103)
      goto state_100_label;

   if (in_char == 108)
      goto state_114_label;

   return 6;

// - STATE 101 -
state_101_label:
   CLOSE_LTG_CHAR(36);
   return 36;

// - STATE 102 -
state_102_label:
   CLOSE_LTG_CHAR(37);
   return 37;

// - STATE 103 -
state_103_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char == 97)
      goto state_115_label;

   if (in_char >= 98 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 104 -
state_104_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 116)
      goto state_26_label;

   if (in_char == 116)
      goto state_116_label;

   if (in_char >= 117 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 105 -
state_105_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 101)
      goto state_26_label;

   if (in_char == 101)
      goto state_117_label;

   if (in_char >= 102 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 106 -
state_106_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 117)
      goto state_26_label;

   if (in_char == 117)
      goto state_118_label;

   if (in_char >= 118 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 107 -
state_107_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char == 97)
      goto state_119_label;

   if (in_char >= 98 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 108 -
state_108_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 108)
      goto state_26_label;

   if (in_char == 108)
      goto state_120_label;

   if (in_char >= 109 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 109 -
state_109_label:
   CLOSE_LTG_CHAR(3);
   return 3;

// - STATE 110 -
state_110_label:
   CLOSE_LTG_CHAR(1);
   return 1;

// - STATE 111 -
state_111_label:
   CLOSE_LTG_CHAR(c_idx_not_exist);
   GET_LTG_NEXT_CHAR();

   if (in_char == 39)
      goto state_110_label;

   if (in_char >= 48 && in_char < 56)
      goto state_121_label;

   return c_idx_not_exist;

// - STATE 112 -
state_112_label:
   CLOSE_LTG_CHAR(c_idx_not_exist);
   GET_LTG_NEXT_CHAR();

   if (in_char == 39)
      goto state_122_label;

   if (in_char >= 48 && in_char < 58)
      goto state_123_label;

   if (in_char >= 65 && in_char < 71)
      goto state_123_label;

   if (in_char >= 97 && in_char < 103)
      goto state_123_label;

   return c_idx_not_exist;

// - STATE 113 -
state_113_label:
   CLOSE_LTG_CHAR(69);
   return 69;

// - STATE 114 -
state_114_label:
   CLOSE_LTG_CHAR(9);
   return 9;

// - STATE 115 -
state_115_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 107)
      goto state_26_label;

   if (in_char == 107)
      goto state_124_label;

   if (in_char >= 108 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 116 -
state_116_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 105)
      goto state_26_label;

   if (in_char == 105)
      goto state_125_label;

   if (in_char >= 106 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 117 -
state_117_label:
   CLOSE_LTG_CHAR(24);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 24;

// - STATE 118 -
state_118_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 114)
      goto state_26_label;

   if (in_char == 114)
      goto state_126_label;

   if (in_char >= 115 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 119 -
state_119_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 116)
      goto state_26_label;

   if (in_char == 116)
      goto state_127_label;

   if (in_char >= 117 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 120 -
state_120_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 101)
      goto state_26_label;

   if (in_char == 101)
      goto state_128_label;

   if (in_char >= 102 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 121 -
state_121_label:
   CLOSE_LTG_CHAR(c_idx_not_exist);
   GET_LTG_NEXT_CHAR();

   if (in_char == 39)
      goto state_110_label;

   return c_idx_not_exist;

// - STATE 122 -
state_122_label:
   CLOSE_LTG_CHAR(2);
   return 2;

// - STATE 123 -
state_123_label:
   CLOSE_LTG_CHAR(c_idx_not_exist);
   GET_LTG_NEXT_CHAR();

   if (in_char == 39)
      goto state_122_label;

   return c_idx_not_exist;

// - STATE 124 -
state_124_label:
   CLOSE_LTG_CHAR(27);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 27;

// - STATE 125 -
state_125_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 110)
      goto state_26_label;

   if (in_char == 110)
      goto state_129_label;

   if (in_char >= 111 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 126 -
state_126_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 110)
      goto state_26_label;

   if (in_char == 110)
      goto state_130_label;

   if (in_char >= 111 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 127 -
state_127_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 105)
      goto state_26_label;

   if (in_char == 105)
      goto state_131_label;

   if (in_char >= 106 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 128 -
state_128_label:
   CLOSE_LTG_CHAR(26);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 26;

// - STATE 129 -
state_129_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 117)
      goto state_26_label;

   if (in_char == 117)
      goto state_132_label;

   if (in_char >= 118 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 130 -
state_130_label:
   CLOSE_LTG_CHAR(29);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 29;

// - STATE 131 -
state_131_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 108)
      goto state_26_label;

   if (in_char == 108)
      goto state_133_label;

   if (in_char >= 109 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 132 -
state_132_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 101)
      goto state_26_label;

   if (in_char == 101)
      goto state_134_label;

   if (in_char >= 102 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 133 -
state_133_label:
   CLOSE_LTG_CHAR(13);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 101)
      goto state_26_label;

   if (in_char == 101)
      goto state_135_label;

   if (in_char >= 102 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 134 -
state_134_label:
   CLOSE_LTG_CHAR(28);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 28;

// - STATE 135 -
state_135_label:
   CLOSE_LTG_CHAR(22);
   GET_LTG_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 22;

}/*}}}*/

bool ltg_parser_s::parse_source()
{/*{{{*/
  old_input_idx = 0;

  lalr_stack.clear();
  lalr_stack.push(0);

  unsigned input_idx = 0;
  unsigned ret_term = c_idx_not_exist;

  do
  {
    // - retrieve next terminal symbol -
    while (ret_term == c_idx_not_exist)
    {
      old_input_idx = input_idx;

      ret_term = recognize_terminal(input_idx);
      debug_message_5(fprintf(stderr,"lightning_parser: recognized terminal: %u\n",ret_term));

      // - PARSE ERROR unrecognized terminal -
      if (ret_term == c_idx_not_exist)
      {
        interpreter_thread_s &it = *((interpreter_thread_s *)it_ptr);
        exception_s *new_exception = exception_s::throw_exception(it,c_error_LIGHTNING_PARSER_UNRECOGNIZED_TERMINAL,0,(location_s *)it.blank_location);
        new_exception->params.push(old_input_idx);

        return false;
      }

      // - skipping of _SKIP_ terminals -
      if (ret_term >= 66 && ret_term <= 69)
      {
        ret_term = c_idx_not_exist;
      }
    }

    // - retrieve action from table of actions -
    unsigned parse_action = ltg_lalr_table[(lalr_stack.last().lalr_state*c_ltg_terminal_plus_nonterminal_cnt) + ret_term];

    // - PARSE ERROR wrong syntax -
    if (parse_action == c_idx_not_exist)
    {
        interpreter_thread_s &it = *((interpreter_thread_s *)it_ptr);
        exception_s *new_exception = exception_s::throw_exception(it,c_error_LIGHTNING_PARSER_SYNTAX_ERROR,0,(location_s *)it.blank_location);
        new_exception->params.push(old_input_idx);

        return false;
    }

    // - action SHIFT -
    if (parse_action < c_ltg_lalr_table_reduce_base)
    {
      if (ret_term == 70)
      {
        break;
      }

      // - insertion of state, and terminal position in source string -
      lalr_stack.push(parse_action,old_input_idx,input_idx);
      ret_term = c_idx_not_exist;
    }

    // - action REDUCE-
    else
    {
      parse_action -= c_ltg_lalr_table_reduce_base;

      // - call function assigned to reduction -
      if (ltg_pa_callers[parse_action] != ltg_pa_null)
      {
        if (!ltg_pa_callers[parse_action](*this))
        {
          return false;
        }
      }

      // - remove rule body from lalr_stack -
      lalr_stack.used -= ltg_rule_body_lengths[parse_action];

      // - insert new automat state to stack -
      unsigned goto_val = ltg_lalr_table[(lalr_stack.last().lalr_state*c_ltg_terminal_plus_nonterminal_cnt) + ltg_rule_head_idxs[parse_action]];
      lalr_stack.push(goto_val);
    }

  }
  while(true);

  return true;
}/*}}}*/

void ltg_parser_s::instr_getarg(unsigned a_type,int a_reg_trg,jit_node_t *a_arg_id)
{/*{{{*/
  switch (a_type)
  {
  case c_val_type_i8:
    jit_getarg_c(a_reg_trg,a_arg_id);
    break;
  case c_val_type_u8:
    jit_getarg_uc(a_reg_trg,a_arg_id);
    break;
  case c_val_type_i16:
    jit_getarg_s(a_reg_trg,a_arg_id);
    break;
  case c_val_type_u16:
    jit_getarg_us(a_reg_trg,a_arg_id);
    break;
  case c_val_type_i32:
    jit_getarg_i(a_reg_trg,a_arg_id);
    break;
  //case c_val_type_u32:
  //  jit_getarg_ui(a_reg_trg,a_arg_id);
  //  break;
  //case c_val_type_i64:
  //  jit_getarg_(a_reg_trg,a_arg_id);
  //  break;
  //case c_val_type_u64:
  //  jit_getarg_l(a_reg_trg,a_arg_id);
  //  break;
  case c_val_type_f32:
    jit_getarg_f(a_reg_trg,a_arg_id);
    break;
  case c_val_type_f64:
    jit_getarg_d(a_reg_trg,a_arg_id);
    break;
  case c_val_type_ptr:
    jit_getarg(a_reg_trg,a_arg_id);
    break;
  default:
    cassert(0);
  }
}/*}}}*/

void ltg_parser_s::instr_stxi(unsigned a_type,int a_offset,int a_reg_base,int a_reg_src)
{/*{{{*/
  switch (a_type)
  {
  case c_val_type_i8:
  case c_val_type_u8:
    jit_stxi_c(a_offset,a_reg_base,a_reg_src);
    break;
  case c_val_type_i16:
  case c_val_type_u16:
    jit_stxi_s(a_offset,a_reg_base,a_reg_src);
    break;
  case c_val_type_i32:
  case c_val_type_u32:
    jit_stxi_i(a_offset,a_reg_base,a_reg_src);
    break;
  //case c_val_type_i64:
  //case c_val_type_u64:
  //  jit_stxi_l(a_offset,a_reg_base,a_reg_src);
  //  break;
  case c_val_type_f32:
    jit_stxi_f(a_offset,a_reg_base,a_reg_src);
    break;
  case c_val_type_f64:
    jit_stxi_d(a_offset,a_reg_base,a_reg_src);
    break;
  case c_val_type_ptr:
    jit_stxi(a_offset,a_reg_base,a_reg_src);
    break;
  default:
    cassert(0);
  }
}/*}}}*/

void ltg_parser_s::instr_ldxi(unsigned a_type,int a_reg_trg,int a_reg_base,int a_offset)
{/*{{{*/
  switch (a_type)
  {
  case c_val_type_i8:
  case c_val_type_u8:
    jit_ldxi_c(a_reg_trg,a_reg_base,a_offset);
    break;
  case c_val_type_i16:
  case c_val_type_u16:
    jit_ldxi_s(a_reg_trg,a_reg_base,a_offset);
    break;
  case c_val_type_i32:
  case c_val_type_u32:
    jit_ldxi_i(a_reg_trg,a_reg_base,a_offset);
    break;
  //case c_val_type_i64:
  //case c_val_type_u64:
  //  jit_ldxi_l(a_reg_trg,a_reg_base,a_offset);
  //  break;
  case c_val_type_f32:
    jit_ldxi_f(a_reg_trg,a_reg_base,a_offset);
    break;
  case c_val_type_f64:
    jit_ldxi_d(a_reg_trg,a_reg_base,a_offset);
    break;
  case c_val_type_ptr:
    jit_ldxi(a_reg_trg,a_reg_base,a_offset);
    break;
  default:
    cassert(0);
  }
}/*}}}*/

void ltg_parser_s::instr_movr(unsigned a_type_trg,unsigned a_type_src,int a_reg_trg,int a_reg_src)
{/*{{{*/
  switch (a_type_trg)
  {
  case c_val_type_i8:
  case c_val_type_u8:
  case c_val_type_i16:
  case c_val_type_u16:
  case c_val_type_i32:
  case c_val_type_u32:
  case c_val_type_i64:
  case c_val_type_u64:
  case c_val_type_ptr:
    {
      switch (a_type_src)
      {
      case c_val_type_i8:
      case c_val_type_u8:
      case c_val_type_i16:
      case c_val_type_u16:
      case c_val_type_i32:
      case c_val_type_u32:
      case c_val_type_i64:
      case c_val_type_u64:
      case c_val_type_ptr:
        jit_movr(a_reg_trg,a_reg_src);
        break;
      case c_val_type_f32:
        jit_truncr_f(a_reg_trg,a_reg_src);
        break;
      case c_val_type_f64:
        jit_truncr_d(a_reg_trg,a_reg_src);
        break;
      default:
        cassert(0);
      }
    }
    break;
  case c_val_type_f32:
    {
      switch (a_type_src)
      {
      case c_val_type_i8:
      case c_val_type_u8:
      case c_val_type_i16:
      case c_val_type_u16:
      case c_val_type_i32:
      case c_val_type_u32:
      case c_val_type_i64:
      case c_val_type_u64:
      case c_val_type_ptr:
        jit_extr_f(a_reg_trg,a_reg_src);
        break;
      case c_val_type_f32:
        jit_movr_f(a_reg_trg,a_reg_src);
        break;
      case c_val_type_f64:
        jit_extr_d_f(a_reg_trg,a_reg_src);
        break;
      default:
        cassert(0);
      }
    }
    break;
  case c_val_type_f64:
    {
      switch (a_type_src)
      {
      case c_val_type_i8:
      case c_val_type_u8:
      case c_val_type_i16:
      case c_val_type_u16:
      case c_val_type_i32:
      case c_val_type_u32:
      case c_val_type_i64:
      case c_val_type_u64:
      case c_val_type_ptr:
        jit_extr_d(a_reg_trg,a_reg_src);
        break;
      case c_val_type_f32:
        jit_extr_f_d(a_reg_trg,a_reg_src);
        break;
      case c_val_type_f64:
        jit_movr_d(a_reg_trg,a_reg_src);
        break;
      default:
        cassert(0);
      }
    }
    break;
  default:
    cassert(0);
  }
}/*}}}*/

void ltg_parser_s::instr_movi(unsigned a_type_trg,unsigned a_type_src,int a_reg_trg,v_data_type a_value)
{/*{{{*/
  switch (a_type_trg)
  {
  case c_val_type_i8:
  case c_val_type_u8:
  case c_val_type_i16:
  case c_val_type_u16:
  case c_val_type_i32:
  case c_val_type_u32:
  case c_val_type_i64:
  case c_val_type_u64:
  case c_val_type_ptr:
    {
      switch (a_type_src)
      {
      case c_val_type_i8:
      case c_val_type_u8:
      case c_val_type_i16:
      case c_val_type_u16:
      case c_val_type_i32:
      case c_val_type_u32:
      case c_val_type_i64:
      case c_val_type_u64:
      case c_val_type_ptr:
        jit_movi(a_reg_trg,(int)a_value);
        break;
      case c_val_type_f32:
      case c_val_type_f64:
        jit_movi(a_reg_trg,(int)*((double *)&a_value));
        break;
      }
    }
    break;
  case c_val_type_f32:
    {
      switch (a_type_src)
      {
      case c_val_type_i8:
      case c_val_type_u8:
      case c_val_type_i16:
      case c_val_type_u16:
      case c_val_type_i32:
      case c_val_type_u32:
      case c_val_type_i64:
      case c_val_type_u64:
      case c_val_type_ptr:
        jit_movi_f(a_reg_trg,(float)(int)a_value);
        break;
      case c_val_type_f32:
      case c_val_type_f64:
        jit_movi_f(a_reg_trg,*((double *)&a_value));
        break;
      }
    }
    break;
  case c_val_type_f64:
    {
      switch (a_type_src)
      {
      case c_val_type_i8:
      case c_val_type_u8:
      case c_val_type_i16:
      case c_val_type_u16:
      case c_val_type_i32:
      case c_val_type_u32:
      case c_val_type_i64:
      case c_val_type_u64:
      case c_val_type_ptr:
        jit_movi_d(a_reg_trg,(double)(int)a_value);
        break;
      case c_val_type_f32:
      case c_val_type_f64:
        jit_movi_d(a_reg_trg,*((double *)&a_value));
        break;
      }
    }
    break;
  default:
    cassert(0);
  }
}/*}}}*/

