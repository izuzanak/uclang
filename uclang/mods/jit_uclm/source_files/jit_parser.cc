
@begin
include "ucl_jit.h"
@end

/*
 * constants and definitions
 */

// - jit type strings -
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

extern const jit_type_t c_type_jit_types[] =
{/*{{{*/
  jit_type_void,
  jit_type_sbyte,
  jit_type_ubyte,
  jit_type_short,
  jit_type_ushort,
  jit_type_int,
  jit_type_uint,
  jit_type_long,
  jit_type_ulong,
  jit_type_float32,
  jit_type_float64,
  jit_type_void_ptr,
};/*}}}*/

extern const unsigned c_type_size_power[] =
{/*{{{*/
  0,
  0,
  0,
  1,
  1,
  2,
  2,
  3,
  3,
  2,
  3,
  (unsigned)(logf(sizeof(pointer))/logf(2)),
};/*}}}*/

extern const unsigned c_type_conv_dist[][c_var_type_cnt] =
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
 * methods of generated structures
 */

// -- label_array_s --
@begin
   methods label_array_s
@end

// -- var_type_s --
@begin
   methods var_type_s
@end

// -- var_types_s --
@begin
   methods var_types_s
@end

// -- var_record_s --
@begin
   methods var_record_s
@end

// -- var_records_s --
@begin
   methods var_records_s
@end

// -- fun_record_s --
@begin
   methods fun_record_s
@end

// -- fun_records_s --
@begin
   methods fun_records_s
@end

// -- exp_node_s --
@begin
   methods exp_node_s
@end

// -- exp_nodes_s --
@begin
   methods exp_nodes_s
@end

// -- jit_parser_s --
@begin
   methods jit_parser_s
@end

unsigned jit_parser_s::recognize_type(unsigned a_length,const char *a_data)
{/*{{{*/
#define GET_JIT_TYPE_NEXT_CHAR() \
{\
   if (input_idx < a_length) {\
      in_char = (unsigned char)a_data[input_idx];\
   }\
   else {\
      in_char = '\0';\
   }\
}

#define CLOSE_JIT_TYPE_CHAR(RET_TERM_IDX) \
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
   GET_JIT_TYPE_NEXT_CHAR();

   if (in_char == 102)
      goto state_1_label;

   if (in_char == 105)
      goto state_2_label;

   if (in_char == 117)
      goto state_3_label;

   return c_idx_not_exist;

// - STATE 1 - 
state_1_label:
   CLOSE_JIT_TYPE_CHAR(c_idx_not_exist);
   GET_JIT_TYPE_NEXT_CHAR();

   if (in_char == 51)
      goto state_4_label;

   if (in_char == 54)
      goto state_5_label;

   return c_idx_not_exist;

// - STATE 2 - 
state_2_label:
   CLOSE_JIT_TYPE_CHAR(c_idx_not_exist);
   GET_JIT_TYPE_NEXT_CHAR();

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
   CLOSE_JIT_TYPE_CHAR(c_idx_not_exist);
   GET_JIT_TYPE_NEXT_CHAR();

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
   CLOSE_JIT_TYPE_CHAR(c_idx_not_exist);
   GET_JIT_TYPE_NEXT_CHAR();

   if (in_char == 50)
      goto state_14_label;

   return c_idx_not_exist;

// - STATE 5 - 
state_5_label:
   CLOSE_JIT_TYPE_CHAR(c_idx_not_exist);
   GET_JIT_TYPE_NEXT_CHAR();

   if (in_char == 52)
      goto state_15_label;

   return c_idx_not_exist;

// - STATE 6 - 
state_6_label:
   CLOSE_JIT_TYPE_CHAR(c_idx_not_exist);
   GET_JIT_TYPE_NEXT_CHAR();

   if (in_char == 54)
      goto state_16_label;

   return c_idx_not_exist;

// - STATE 7 - 
state_7_label:
   CLOSE_JIT_TYPE_CHAR(c_idx_not_exist);
   GET_JIT_TYPE_NEXT_CHAR();

   if (in_char == 50)
      goto state_17_label;

   return c_idx_not_exist;

// - STATE 8 - 
state_8_label:
   CLOSE_JIT_TYPE_CHAR(c_idx_not_exist);
   GET_JIT_TYPE_NEXT_CHAR();

   if (in_char == 52)
      goto state_18_label;

   return c_idx_not_exist;

// - STATE 9 - 
state_9_label:
   CLOSE_JIT_TYPE_CHAR(c_var_type_i8);
   return c_var_type_i8;


// - STATE 10 - 
state_10_label:
   CLOSE_JIT_TYPE_CHAR(c_idx_not_exist);
   GET_JIT_TYPE_NEXT_CHAR();

   if (in_char == 54)
      goto state_19_label;

   return c_idx_not_exist;

// - STATE 11 - 
state_11_label:
   CLOSE_JIT_TYPE_CHAR(c_idx_not_exist);
   GET_JIT_TYPE_NEXT_CHAR();

   if (in_char == 50)
      goto state_20_label;

   return c_idx_not_exist;

// - STATE 12 - 
state_12_label:
   CLOSE_JIT_TYPE_CHAR(c_idx_not_exist);
   GET_JIT_TYPE_NEXT_CHAR();

   if (in_char == 52)
      goto state_21_label;

   return c_idx_not_exist;

// - STATE 13 - 
state_13_label:
   CLOSE_JIT_TYPE_CHAR(c_var_type_u8);
   return c_var_type_u8;

// - STATE 14 - 
state_14_label:
   CLOSE_JIT_TYPE_CHAR(c_var_type_f32);
   return c_var_type_f32;

// - STATE 15 - 
state_15_label:
   CLOSE_JIT_TYPE_CHAR(c_var_type_f64);
   return c_var_type_f64;

// - STATE 16 - 
state_16_label:
   CLOSE_JIT_TYPE_CHAR(c_var_type_i16);
   return c_var_type_i16;

// - STATE 17 - 
state_17_label:
   CLOSE_JIT_TYPE_CHAR(c_var_type_i32);
   return c_var_type_i32;

// - STATE 18 - 
state_18_label:
   CLOSE_JIT_TYPE_CHAR(c_var_type_i64);
   return c_var_type_i64;

// - STATE 19 - 
state_19_label:
   CLOSE_JIT_TYPE_CHAR(c_var_type_u16);
   return c_var_type_u16;

// - STATE 20 - 
state_20_label:
   CLOSE_JIT_TYPE_CHAR(c_var_type_u32);
   return c_var_type_u32;

// - STATE 21 - 
state_21_label:
   CLOSE_JIT_TYPE_CHAR(c_var_type_u64);
   return c_var_type_u64;

}/*}}}*/

void jit_parser_s::create_signature(unsigned a_name_length,char *a_name_data,unsigned a_param_cnt,var_type_s **a_param_types,string_s &a_target)
{/*{{{*/

  // - determine signature length -
  unsigned length = a_name_length + 1;

  if (a_param_cnt > 0)
  {
    var_type_s **pt_ptr = a_param_types;
    var_type_s **pt_ptr_end = pt_ptr + a_param_cnt;
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
    var_type_s **pt_ptr = a_param_types;
    var_type_s **pt_ptr_end = pt_ptr + a_param_cnt;
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

unsigned jit_parser_s::recognize_terminal(unsigned &input_idx)
{/*{{{*/
  unsigned source_string_length = source_string.size - 1;

#define GET_JIT_NEXT_CHAR() \
  {\
    if (input_idx < source_string_length) {\
      in_char = (unsigned char)source_string[input_idx];\
    }\
    else {\
      in_char = '\0';\
    }\
  }

#define CLOSE_JIT_CHAR(RET_TERM_IDX) \
  {\
    if (in_char == '\0') {\
      return RET_TERM_IDX;\
    }\
    \
    input_idx++;\
  }

   unsigned short in_char;

// - STATE 0 - 
   GET_JIT_NEXT_CHAR();

   if (in_char == 0)
      goto state_1_label;

   if (in_char >= 9 && in_char < 11)
      goto state_42_label;

   if (in_char == 32)
      goto state_42_label;

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

   if (in_char == 103)
      goto state_32_label;

   if (in_char == 104)
      goto state_26_label;

   if (in_char == 105)
      goto state_33_label;

   if (in_char >= 106 && in_char < 114)
      goto state_26_label;

   if (in_char == 114)
      goto state_34_label;

   if (in_char >= 115 && in_char < 117)
      goto state_26_label;

   if (in_char == 117)
      goto state_35_label;

   if (in_char == 118)
      goto state_36_label;

   if (in_char == 119)
      goto state_37_label;

   if (in_char >= 120 && in_char < 123)
      goto state_26_label;

   if (in_char == 123)
      goto state_38_label;

   if (in_char == 124)
      goto state_39_label;

   if (in_char == 125)
      goto state_40_label;

   if (in_char == 126)
      goto state_41_label;

   return c_idx_not_exist;

// - STATE 1 - 
state_1_label:
   CLOSE_JIT_CHAR(71);
   return 71;

// - STATE 2 - 
state_2_label:
   CLOSE_JIT_CHAR(63);
   GET_JIT_NEXT_CHAR();

   if (in_char == 61)
      goto state_44_label;

   return 63;

// - STATE 3 - 
state_3_label:
   CLOSE_JIT_CHAR(c_idx_not_exist);
   GET_JIT_NEXT_CHAR();

   if (in_char < 10)
      goto state_3_label;

   if (in_char == 10)
      goto state_45_label;

   if (in_char >= 11 && in_char < 257)
      goto state_3_label;

   return c_idx_not_exist;

// - STATE 4 - 
state_4_label:
   CLOSE_JIT_CHAR(60);
   GET_JIT_NEXT_CHAR();

   if (in_char == 61)
      goto state_46_label;

   return 60;

// - STATE 5 - 
state_5_label:
   CLOSE_JIT_CHAR(44);
   GET_JIT_NEXT_CHAR();

   if (in_char == 38)
      goto state_47_label;

   if (in_char == 61)
      goto state_48_label;

   return 44;

// - STATE 6 - 
state_6_label:
   CLOSE_JIT_CHAR(c_idx_not_exist);
   GET_JIT_NEXT_CHAR();

   if (in_char < 92)
      goto state_50_label;

   if (in_char == 92)
      goto state_49_label;

   if (in_char >= 93 && in_char < 257)
      goto state_50_label;

   return c_idx_not_exist;

// - STATE 7 - 
state_7_label:
   CLOSE_JIT_CHAR(14);
   return 14;

// - STATE 8 - 
state_8_label:
   CLOSE_JIT_CHAR(15);
   return 15;

// - STATE 9 - 
state_9_label:
   CLOSE_JIT_CHAR(58);
   GET_JIT_NEXT_CHAR();

   if (in_char == 61)
      goto state_51_label;

   return 58;

// - STATE 10 - 
state_10_label:
   CLOSE_JIT_CHAR(55);
   GET_JIT_NEXT_CHAR();

   if (in_char == 43)
      goto state_52_label;

   if (in_char == 61)
      goto state_53_label;

   return 55;

// - STATE 11 - 
state_11_label:
   CLOSE_JIT_CHAR(20);
   return 20;

// - STATE 12 - 
state_12_label:
   CLOSE_JIT_CHAR(56);
   GET_JIT_NEXT_CHAR();

   if (in_char == 45)
      goto state_54_label;

   if (in_char == 61)
      goto state_55_label;

   return 56;

// - STATE 13 - 
state_13_label:
   CLOSE_JIT_CHAR(57);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_56_label;

   return 57;

// - STATE 14 - 
state_14_label:
   CLOSE_JIT_CHAR(59);
   GET_JIT_NEXT_CHAR();

   if (in_char == 42)
      goto state_57_label;

   if (in_char == 47)
      goto state_58_label;

   if (in_char == 61)
      goto state_59_label;

   return 59;

// - STATE 15 - 
state_15_label:
   CLOSE_JIT_CHAR(4);
   GET_JIT_NEXT_CHAR();

   if (in_char == 46)
      goto state_60_label;

   if (in_char >= 48 && in_char < 56)
      goto state_61_label;

   if (in_char >= 56 && in_char < 58)
      goto state_43_label;

   if (in_char == 69)
      goto state_62_label;

   if (in_char == 70)
      goto state_63_label;

   if (in_char == 76)
      goto state_64_label;

   if (in_char == 88)
      goto state_65_label;

   if (in_char == 101)
      goto state_62_label;

   if (in_char == 102)
      goto state_63_label;

   if (in_char == 108)
      goto state_64_label;

   if (in_char == 120)
      goto state_65_label;

   return 4;

// - STATE 16 - 
state_16_label:
   CLOSE_JIT_CHAR(5);
   GET_JIT_NEXT_CHAR();

   if (in_char == 46)
      goto state_60_label;

   if (in_char >= 48 && in_char < 58)
      goto state_16_label;

   if (in_char == 69)
      goto state_62_label;

   if (in_char == 70)
      goto state_63_label;

   if (in_char == 76)
      goto state_66_label;

   if (in_char == 101)
      goto state_62_label;

   if (in_char == 102)
      goto state_63_label;

   if (in_char == 108)
      goto state_66_label;

   return 5;

// - STATE 17 - 
state_17_label:
   CLOSE_JIT_CHAR(65);
   return 65;

// - STATE 18 - 
state_18_label:
   CLOSE_JIT_CHAR(21);
   return 21;

// - STATE 19 - 
state_19_label:
   CLOSE_JIT_CHAR(50);
   GET_JIT_NEXT_CHAR();

   if (in_char == 60)
      goto state_67_label;

   if (in_char == 61)
      goto state_68_label;

   return 50;

// - STATE 20 - 
state_20_label:
   CLOSE_JIT_CHAR(31);
   GET_JIT_NEXT_CHAR();

   if (in_char == 61)
      goto state_69_label;

   return 31;

// - STATE 21 - 
state_21_label:
   CLOSE_JIT_CHAR(49);
   GET_JIT_NEXT_CHAR();

   if (in_char == 61)
      goto state_70_label;

   if (in_char == 62)
      goto state_71_label;

   return 49;

// - STATE 22 - 
state_22_label:
   CLOSE_JIT_CHAR(64);
   return 64;

// - STATE 23 - 
state_23_label:
   CLOSE_JIT_CHAR(18);
   return 18;

// - STATE 24 - 
state_24_label:
   CLOSE_JIT_CHAR(19);
   return 19;

// - STATE 25 - 
state_25_label:
   CLOSE_JIT_CHAR(46);
   GET_JIT_NEXT_CHAR();

   if (in_char == 61)
      goto state_72_label;

   return 46;

// - STATE 26 - 
state_26_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

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
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 114)
      goto state_26_label;

   if (in_char == 114)
      goto state_73_label;

   if (in_char >= 115 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 28 - 
state_28_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

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

// - STATE 29 - 
state_29_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 111)
      goto state_26_label;

   if (in_char == 111)
      goto state_75_label;

   if (in_char >= 112 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 30 - 
state_30_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 108)
      goto state_26_label;

   if (in_char == 108)
      goto state_76_label;

   if (in_char >= 109 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 31 - 
state_31_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 51)
      goto state_26_label;

   if (in_char == 51)
      goto state_77_label;

   if (in_char >= 52 && in_char < 54)
      goto state_26_label;

   if (in_char == 54)
      goto state_78_label;

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
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 111)
      goto state_26_label;

   if (in_char == 111)
      goto state_79_label;

   if (in_char >= 112 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 33 - 
state_33_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char == 48)
      goto state_26_label;

   if (in_char == 49)
      goto state_80_label;

   if (in_char == 50)
      goto state_26_label;

   if (in_char == 51)
      goto state_81_label;

   if (in_char >= 52 && in_char < 54)
      goto state_26_label;

   if (in_char == 54)
      goto state_82_label;

   if (in_char == 55)
      goto state_26_label;

   if (in_char == 56)
      goto state_83_label;

   if (in_char == 57)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 102)
      goto state_26_label;

   if (in_char == 102)
      goto state_84_label;

   if (in_char >= 103 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 34 - 
state_34_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 101)
      goto state_26_label;

   if (in_char == 101)
      goto state_85_label;

   if (in_char >= 102 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 35 - 
state_35_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char == 48)
      goto state_26_label;

   if (in_char == 49)
      goto state_86_label;

   if (in_char == 50)
      goto state_26_label;

   if (in_char == 51)
      goto state_87_label;

   if (in_char >= 52 && in_char < 54)
      goto state_26_label;

   if (in_char == 54)
      goto state_88_label;

   if (in_char == 55)
      goto state_26_label;

   if (in_char == 56)
      goto state_83_label;

   if (in_char == 57)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 36 - 
state_36_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 111)
      goto state_26_label;

   if (in_char == 111)
      goto state_89_label;

   if (in_char >= 112 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 37 - 
state_37_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 104)
      goto state_26_label;

   if (in_char == 104)
      goto state_90_label;

   if (in_char >= 105 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 38 - 
state_38_label:
   CLOSE_JIT_CHAR(16);
   return 16;

// - STATE 39 - 
state_39_label:
   CLOSE_JIT_CHAR(45);
   GET_JIT_NEXT_CHAR();

   if (in_char == 61)
      goto state_91_label;

   if (in_char == 124)
      goto state_92_label;

   return 45;

// - STATE 40 - 
state_40_label:
   CLOSE_JIT_CHAR(17);
   return 17;

// - STATE 41 - 
state_41_label:
   CLOSE_JIT_CHAR(66);
   return 66;

// - STATE 42 - 
state_42_label:
   CLOSE_JIT_CHAR(67);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 9 && in_char < 11)
      goto state_42_label;

   if (in_char == 32)
      goto state_42_label;

   return 67;

// - STATE 43 - 
state_43_label:
   CLOSE_JIT_CHAR(c_idx_not_exist);
   GET_JIT_NEXT_CHAR();

   if (in_char == 46)
      goto state_60_label;

   if (in_char >= 48 && in_char < 58)
      goto state_43_label;

   if (in_char == 69)
      goto state_62_label;

   if (in_char == 70)
      goto state_63_label;

   if (in_char == 101)
      goto state_62_label;

   if (in_char == 102)
      goto state_63_label;

   return c_idx_not_exist;

// - STATE 44 - 
state_44_label:
   CLOSE_JIT_CHAR(48);
   return 48;

// - STATE 45 - 
state_45_label:
   CLOSE_JIT_CHAR(68);
   return 68;

// - STATE 46 - 
state_46_label:
   CLOSE_JIT_CHAR(36);
   return 36;

// - STATE 47 - 
state_47_label:
   CLOSE_JIT_CHAR(42);
   return 42;

// - STATE 48 - 
state_48_label:
   CLOSE_JIT_CHAR(39);
   return 39;

// - STATE 49 - 
state_49_label:
   CLOSE_JIT_CHAR(c_idx_not_exist);
   GET_JIT_NEXT_CHAR();

   if (in_char == 34)
      goto state_93_label;

   if (in_char == 39)
      goto state_94_label;

   if (in_char >= 48 && in_char < 56)
      goto state_95_label;

   if (in_char == 63)
      goto state_93_label;

   if (in_char == 92)
      goto state_93_label;

   if (in_char >= 97 && in_char < 99)
      goto state_93_label;

   if (in_char == 102)
      goto state_93_label;

   if (in_char == 110)
      goto state_93_label;

   if (in_char == 114)
      goto state_93_label;

   if (in_char == 116)
      goto state_93_label;

   if (in_char == 118)
      goto state_93_label;

   if (in_char == 120)
      goto state_96_label;

   return c_idx_not_exist;

// - STATE 50 - 
state_50_label:
   CLOSE_JIT_CHAR(c_idx_not_exist);
   GET_JIT_NEXT_CHAR();

   if (in_char == 39)
      goto state_97_label;

   return c_idx_not_exist;

// - STATE 51 - 
state_51_label:
   CLOSE_JIT_CHAR(34);
   return 34;

// - STATE 52 - 
state_52_label:
   CLOSE_JIT_CHAR(61);
   return 61;

// - STATE 53 - 
state_53_label:
   CLOSE_JIT_CHAR(32);
   return 32;

// - STATE 54 - 
state_54_label:
   CLOSE_JIT_CHAR(62);
   return 62;

// - STATE 55 - 
state_55_label:
   CLOSE_JIT_CHAR(33);
   return 33;

// - STATE 56 - 
state_56_label:
   CLOSE_JIT_CHAR(11);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_56_label;

   if (in_char == 69)
      goto state_62_label;

   if (in_char == 70)
      goto state_63_label;

   if (in_char == 101)
      goto state_62_label;

   if (in_char == 102)
      goto state_63_label;

   return 11;

// - STATE 57 - 
state_57_label:
   CLOSE_JIT_CHAR(c_idx_not_exist);
   GET_JIT_NEXT_CHAR();

   if (in_char < 42)
      goto state_57_label;

   if (in_char == 42)
      goto state_98_label;

   if (in_char >= 43 && in_char < 257)
      goto state_57_label;

   return c_idx_not_exist;

// - STATE 58 - 
state_58_label:
   CLOSE_JIT_CHAR(c_idx_not_exist);
   GET_JIT_NEXT_CHAR();

   if (in_char < 10)
      goto state_58_label;

   if (in_char == 10)
      goto state_99_label;

   if (in_char >= 11 && in_char < 257)
      goto state_58_label;

   return c_idx_not_exist;

// - STATE 59 - 
state_59_label:
   CLOSE_JIT_CHAR(35);
   return 35;

// - STATE 60 - 
state_60_label:
   CLOSE_JIT_CHAR(11);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_56_label;

   if (in_char == 69)
      goto state_62_label;

   if (in_char == 70)
      goto state_63_label;

   if (in_char == 101)
      goto state_62_label;

   if (in_char == 102)
      goto state_63_label;

   return 11;

// - STATE 61 - 
state_61_label:
   CLOSE_JIT_CHAR(4);
   GET_JIT_NEXT_CHAR();

   if (in_char == 46)
      goto state_60_label;

   if (in_char >= 48 && in_char < 56)
      goto state_61_label;

   if (in_char >= 56 && in_char < 58)
      goto state_43_label;

   if (in_char == 69)
      goto state_62_label;

   if (in_char == 70)
      goto state_63_label;

   if (in_char == 76)
      goto state_64_label;

   if (in_char == 101)
      goto state_62_label;

   if (in_char == 102)
      goto state_63_label;

   if (in_char == 108)
      goto state_64_label;

   return 4;

// - STATE 62 - 
state_62_label:
   CLOSE_JIT_CHAR(c_idx_not_exist);
   GET_JIT_NEXT_CHAR();

   if (in_char == 43)
      goto state_100_label;

   if (in_char == 45)
      goto state_100_label;

   if (in_char >= 48 && in_char < 58)
      goto state_101_label;

   return c_idx_not_exist;

// - STATE 63 - 
state_63_label:
   CLOSE_JIT_CHAR(10);
   return 10;

// - STATE 64 - 
state_64_label:
   CLOSE_JIT_CHAR(7);
   return 7;

// - STATE 65 - 
state_65_label:
   CLOSE_JIT_CHAR(c_idx_not_exist);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_102_label;

   if (in_char >= 65 && in_char < 71)
      goto state_102_label;

   if (in_char >= 97 && in_char < 103)
      goto state_102_label;

   return c_idx_not_exist;

// - STATE 66 - 
state_66_label:
   CLOSE_JIT_CHAR(8);
   return 8;

// - STATE 67 - 
state_67_label:
   CLOSE_JIT_CHAR(54);
   GET_JIT_NEXT_CHAR();

   if (in_char == 61)
      goto state_103_label;

   return 54;

// - STATE 68 - 
state_68_label:
   CLOSE_JIT_CHAR(52);
   return 52;

// - STATE 69 - 
state_69_label:
   CLOSE_JIT_CHAR(47);
   return 47;

// - STATE 70 - 
state_70_label:
   CLOSE_JIT_CHAR(51);
   return 51;

// - STATE 71 - 
state_71_label:
   CLOSE_JIT_CHAR(53);
   GET_JIT_NEXT_CHAR();

   if (in_char == 61)
      goto state_104_label;

   return 53;

// - STATE 72 - 
state_72_label:
   CLOSE_JIT_CHAR(41);
   return 41;

// - STATE 73 - 
state_73_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 101)
      goto state_26_label;

   if (in_char == 101)
      goto state_105_label;

   if (in_char >= 102 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 74 - 
state_74_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 110)
      goto state_26_label;

   if (in_char == 110)
      goto state_106_label;

   if (in_char >= 111 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 75 - 
state_75_label:
   CLOSE_JIT_CHAR(25);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 25;

// - STATE 76 - 
state_76_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 115)
      goto state_26_label;

   if (in_char == 115)
      goto state_107_label;

   if (in_char >= 116 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 77 - 
state_77_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 50)
      goto state_26_label;

   if (in_char == 50)
      goto state_83_label;

   if (in_char >= 51 && in_char < 58)
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
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 52)
      goto state_26_label;

   if (in_char == 52)
      goto state_83_label;

   if (in_char >= 53 && in_char < 58)
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
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 116)
      goto state_26_label;

   if (in_char == 116)
      goto state_108_label;

   if (in_char >= 117 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 80 - 
state_80_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 54)
      goto state_26_label;

   if (in_char == 54)
      goto state_83_label;

   if (in_char >= 55 && in_char < 58)
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
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 50)
      goto state_26_label;

   if (in_char == 50)
      goto state_83_label;

   if (in_char >= 51 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 82 - 
state_82_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 52)
      goto state_26_label;

   if (in_char == 52)
      goto state_83_label;

   if (in_char >= 53 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 83 - 
state_83_label:
   CLOSE_JIT_CHAR(12);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 12;

// - STATE 84 - 
state_84_label:
   CLOSE_JIT_CHAR(23);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 23;

// - STATE 85 - 
state_85_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 116)
      goto state_26_label;

   if (in_char == 116)
      goto state_109_label;

   if (in_char >= 117 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 86 - 
state_86_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 54)
      goto state_26_label;

   if (in_char == 54)
      goto state_83_label;

   if (in_char >= 55 && in_char < 58)
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
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 50)
      goto state_26_label;

   if (in_char == 50)
      goto state_83_label;

   if (in_char >= 51 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 88 - 
state_88_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 52)
      goto state_26_label;

   if (in_char == 52)
      goto state_83_label;

   if (in_char >= 53 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 89 - 
state_89_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 108)
      goto state_26_label;

   if (in_char == 108)
      goto state_110_label;

   if (in_char >= 109 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 90 - 
state_90_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 105)
      goto state_26_label;

   if (in_char == 105)
      goto state_111_label;

   if (in_char >= 106 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 91 - 
state_91_label:
   CLOSE_JIT_CHAR(40);
   return 40;

// - STATE 92 - 
state_92_label:
   CLOSE_JIT_CHAR(43);
   return 43;

// - STATE 93 - 
state_93_label:
   CLOSE_JIT_CHAR(c_idx_not_exist);
   GET_JIT_NEXT_CHAR();

   if (in_char == 39)
      goto state_112_label;

   return c_idx_not_exist;

// - STATE 94 - 
state_94_label:
   CLOSE_JIT_CHAR(0);
   GET_JIT_NEXT_CHAR();

   if (in_char == 39)
      goto state_112_label;

   return 0;

// - STATE 95 - 
state_95_label:
   CLOSE_JIT_CHAR(c_idx_not_exist);
   GET_JIT_NEXT_CHAR();

   if (in_char == 39)
      goto state_113_label;

   if (in_char >= 48 && in_char < 56)
      goto state_114_label;

   return c_idx_not_exist;

// - STATE 96 - 
state_96_label:
   CLOSE_JIT_CHAR(c_idx_not_exist);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_115_label;

   if (in_char >= 65 && in_char < 71)
      goto state_115_label;

   if (in_char >= 97 && in_char < 103)
      goto state_115_label;

   return c_idx_not_exist;

// - STATE 97 - 
state_97_label:
   CLOSE_JIT_CHAR(0);
   return 0;

// - STATE 98 - 
state_98_label:
   CLOSE_JIT_CHAR(c_idx_not_exist);
   GET_JIT_NEXT_CHAR();

   if (in_char < 47)
      goto state_57_label;

   if (in_char == 47)
      goto state_116_label;

   if (in_char >= 48 && in_char < 257)
      goto state_57_label;

   return c_idx_not_exist;

// - STATE 99 - 
state_99_label:
   CLOSE_JIT_CHAR(69);
   return 69;

// - STATE 100 - 
state_100_label:
   CLOSE_JIT_CHAR(c_idx_not_exist);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_101_label;

   return c_idx_not_exist;

// - STATE 101 - 
state_101_label:
   CLOSE_JIT_CHAR(11);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_101_label;

   if (in_char == 70)
      goto state_63_label;

   if (in_char == 102)
      goto state_63_label;

   return 11;

// - STATE 102 - 
state_102_label:
   CLOSE_JIT_CHAR(6);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_102_label;

   if (in_char >= 65 && in_char < 71)
      goto state_102_label;

   if (in_char == 76)
      goto state_117_label;

   if (in_char >= 97 && in_char < 103)
      goto state_102_label;

   if (in_char == 108)
      goto state_117_label;

   return 6;

// - STATE 103 - 
state_103_label:
   CLOSE_JIT_CHAR(37);
   return 37;

// - STATE 104 - 
state_104_label:
   CLOSE_JIT_CHAR(38);
   return 38;

// - STATE 105 - 
state_105_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char == 97)
      goto state_118_label;

   if (in_char >= 98 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 106 - 
state_106_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 116)
      goto state_26_label;

   if (in_char == 116)
      goto state_119_label;

   if (in_char >= 117 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 107 - 
state_107_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 101)
      goto state_26_label;

   if (in_char == 101)
      goto state_120_label;

   if (in_char >= 102 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 108 - 
state_108_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 111)
      goto state_26_label;

   if (in_char == 111)
      goto state_121_label;

   if (in_char >= 112 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 109 - 
state_109_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 117)
      goto state_26_label;

   if (in_char == 117)
      goto state_122_label;

   if (in_char >= 118 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 110 - 
state_110_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char == 97)
      goto state_123_label;

   if (in_char >= 98 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 111 - 
state_111_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 108)
      goto state_26_label;

   if (in_char == 108)
      goto state_124_label;

   if (in_char >= 109 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 112 - 
state_112_label:
   CLOSE_JIT_CHAR(3);
   return 3;

// - STATE 113 - 
state_113_label:
   CLOSE_JIT_CHAR(1);
   return 1;

// - STATE 114 - 
state_114_label:
   CLOSE_JIT_CHAR(c_idx_not_exist);
   GET_JIT_NEXT_CHAR();

   if (in_char == 39)
      goto state_113_label;

   if (in_char >= 48 && in_char < 56)
      goto state_125_label;

   return c_idx_not_exist;

// - STATE 115 - 
state_115_label:
   CLOSE_JIT_CHAR(c_idx_not_exist);
   GET_JIT_NEXT_CHAR();

   if (in_char == 39)
      goto state_126_label;

   if (in_char >= 48 && in_char < 58)
      goto state_127_label;

   if (in_char >= 65 && in_char < 71)
      goto state_127_label;

   if (in_char >= 97 && in_char < 103)
      goto state_127_label;

   return c_idx_not_exist;

// - STATE 116 - 
state_116_label:
   CLOSE_JIT_CHAR(70);
   return 70;

// - STATE 117 - 
state_117_label:
   CLOSE_JIT_CHAR(9);
   return 9;

// - STATE 118 - 
state_118_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 107)
      goto state_26_label;

   if (in_char == 107)
      goto state_128_label;

   if (in_char >= 108 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 119 - 
state_119_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 105)
      goto state_26_label;

   if (in_char == 105)
      goto state_129_label;

   if (in_char >= 106 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 120 - 
state_120_label:
   CLOSE_JIT_CHAR(24);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 24;

// - STATE 121 - 
state_121_label:
   CLOSE_JIT_CHAR(30);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 30;

// - STATE 122 - 
state_122_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 114)
      goto state_26_label;

   if (in_char == 114)
      goto state_130_label;

   if (in_char >= 115 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 123 - 
state_123_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 116)
      goto state_26_label;

   if (in_char == 116)
      goto state_131_label;

   if (in_char >= 117 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 124 - 
state_124_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 101)
      goto state_26_label;

   if (in_char == 101)
      goto state_132_label;

   if (in_char >= 102 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 125 - 
state_125_label:
   CLOSE_JIT_CHAR(c_idx_not_exist);
   GET_JIT_NEXT_CHAR();

   if (in_char == 39)
      goto state_113_label;

   return c_idx_not_exist;

// - STATE 126 - 
state_126_label:
   CLOSE_JIT_CHAR(2);
   return 2;

// - STATE 127 - 
state_127_label:
   CLOSE_JIT_CHAR(c_idx_not_exist);
   GET_JIT_NEXT_CHAR();

   if (in_char == 39)
      goto state_126_label;

   return c_idx_not_exist;

// - STATE 128 - 
state_128_label:
   CLOSE_JIT_CHAR(27);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 27;

// - STATE 129 - 
state_129_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 110)
      goto state_26_label;

   if (in_char == 110)
      goto state_133_label;

   if (in_char >= 111 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 130 - 
state_130_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 110)
      goto state_26_label;

   if (in_char == 110)
      goto state_134_label;

   if (in_char >= 111 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 131 - 
state_131_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 105)
      goto state_26_label;

   if (in_char == 105)
      goto state_135_label;

   if (in_char >= 106 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 132 - 
state_132_label:
   CLOSE_JIT_CHAR(26);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 26;

// - STATE 133 - 
state_133_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 117)
      goto state_26_label;

   if (in_char == 117)
      goto state_136_label;

   if (in_char >= 118 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 134 - 
state_134_label:
   CLOSE_JIT_CHAR(29);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 29;

// - STATE 135 - 
state_135_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 108)
      goto state_26_label;

   if (in_char == 108)
      goto state_137_label;

   if (in_char >= 109 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 136 - 
state_136_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 101)
      goto state_26_label;

   if (in_char == 101)
      goto state_138_label;

   if (in_char >= 102 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 137 - 
state_137_label:
   CLOSE_JIT_CHAR(13);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 101)
      goto state_26_label;

   if (in_char == 101)
      goto state_139_label;

   if (in_char >= 102 && in_char < 123)
      goto state_26_label;

   return 13;

// - STATE 138 - 
state_138_label:
   CLOSE_JIT_CHAR(28);
   GET_JIT_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58)
      goto state_26_label;

   if (in_char >= 65 && in_char < 91)
      goto state_26_label;

   if (in_char == 95)
      goto state_26_label;

   if (in_char >= 97 && in_char < 123)
      goto state_26_label;

   return 28;

// - STATE 139 - 
state_139_label:
   CLOSE_JIT_CHAR(22);
   GET_JIT_NEXT_CHAR();

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

bool jit_parser_s::parse_source()
{/*{{{*/
  old_input_idx = 0;

  lalr_stack.clear();
  lalr_stack.push(0);

  unsigned input_idx = 0;
  unsigned ret_term = c_idx_not_exist;

  do
  {
    // - retrieve of next terminal symbol -
    while (ret_term == c_idx_not_exist)
    {
      old_input_idx = input_idx;

      ret_term = recognize_terminal(input_idx);
      debug_message_5(fprintf(stderr,"jit_parser: recognized terminal: %u\n",ret_term));

      // - PARSE ERROR unrecognized terminal -
      if (ret_term == c_idx_not_exist)
      {
        interpreter_thread_s &it = *((interpreter_thread_s *)it_ptr);
        exception_s *new_exception = exception_s::throw_exception(it,c_error_JIT_PARSER_UNRECOGNIZED_TERMINAL,0,(location_s *)it.blank_location);
        new_exception->params.push(old_input_idx);

        return false;
      }

      // - skip of _SKIP_ terminals -
      if (ret_term >= 67 && ret_term <= 70)
      {
        ret_term = c_idx_not_exist;
      }
    }

    // - retrieve of action from table of actions -
    unsigned parse_action = jit_lalr_table[lalr_stack.last().lalr_state*c_jit_terminal_plus_nonterminal_cnt + ret_term];

    // - PARSE ERROR wrong syntax -
    if (parse_action == c_idx_not_exist)
    {
        interpreter_thread_s &it = *((interpreter_thread_s *)it_ptr);
        exception_s *new_exception = exception_s::throw_exception(it,c_error_JIT_PARSER_SYNTAX_ERROR,0,(location_s *)it.blank_location);
        new_exception->params.push(old_input_idx);

        return false;
    }

    // - action SHIFT -
    if (parse_action < c_jit_lalr_table_reduce_base)
    {

      if (ret_term == 71)
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
      parse_action -= c_jit_lalr_table_reduce_base;

      // - call of function assigned to reduction -
      if (jit_pa_callers[parse_action] != jit_pa_null)
      {
        if (!jit_pa_callers[parse_action](*this))
        {
          return false;
        }
      }

      // - remove of rule body from lalr_stack -
      lalr_stack.used -= jit_rule_body_lengths[parse_action];

      // - insert of new automat state to stack -
      unsigned goto_val = jit_lalr_table[lalr_stack.last().lalr_state*c_jit_terminal_plus_nonterminal_cnt + jit_rule_head_idxs[parse_action]];
      lalr_stack.push(goto_val);
    }

  }
  while(1);

  return true;
}/*}}}*/

