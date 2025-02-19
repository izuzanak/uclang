
@begin
include "ucl_validator.h"
@end

/*
 * methods of structure validator_s
 */

unsigned validator_s::recognize_property(const char *a_string,unsigned &a_input_idx) // NOLINT(google-readability-function-size,readability-function-size)
{/*{{{*/
#define GET_NEXT_CHAR() \
{\
   in_char = a_string[a_input_idx];\
}

#define CLOSE_CHAR(RET_TERM_IDX) \
{\
   if (in_char == '\0') {\
      return RET_TERM_IDX;\
   }\
\
   a_input_idx++;\
}

   a_input_idx = 0;
   unsigned char in_char;

// - STATE 0 -
   GET_NEXT_CHAR();

   if (in_char == 33) {
      goto state_1_label;
   }
   if (in_char == 60) {
      goto state_2_label;
   }
   if (in_char == 61) {
      goto state_3_label;
   }
   if (in_char == 62) {
      goto state_4_label;
   }
   if (in_char == 97) {
      goto state_5_label;
   }
   if (in_char == 105) {
      goto state_6_label;
   }
   if (in_char == 108) {
      goto state_7_label;
   }
   if (in_char == 111) {
      goto state_8_label;
   }
   if (in_char == 114) {
      goto state_9_label;
   }
   if (in_char == 116) {
      goto state_10_label;
   }
   return c_idx_not_exist;

// - STATE 1 -
state_1_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 61) {
      goto state_11_label;
   }
   return c_idx_not_exist;

// - STATE 2 -
state_2_label:
   CLOSE_CHAR(3);
   GET_NEXT_CHAR();

   if (in_char == 61) {
      goto state_12_label;
   }
   return 3;

// - STATE 3 -
state_3_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 61) {
      goto state_13_label;
   }
   return c_idx_not_exist;

// - STATE 4 -
state_4_label:
   CLOSE_CHAR(4);
   GET_NEXT_CHAR();

   if (in_char == 61) {
      goto state_14_label;
   }
   return 4;

// - STATE 5 -
state_5_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 108) {
      goto state_15_label;
   }
   return c_idx_not_exist;

// - STATE 6 -
state_6_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 110) {
      goto state_16_label;
   }
   if (in_char == 116) {
      goto state_17_label;
   }
   return c_idx_not_exist;

// - STATE 7 -
state_7_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 101) {
      goto state_18_label;
   }
   return c_idx_not_exist;

// - STATE 8 -
state_8_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 112) {
      goto state_19_label;
   }
   return c_idx_not_exist;

// - STATE 9 -
state_9_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 101) {
      goto state_20_label;
   }
   return c_idx_not_exist;

// - STATE 10 -
state_10_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 101) {
      goto state_21_label;
   }
   if (in_char == 121) {
      goto state_22_label;
   }
   return c_idx_not_exist;

// - STATE 11 -
state_11_label:
   CLOSE_CHAR(2);
   return 2;

// - STATE 12 -
state_12_label:
   CLOSE_CHAR(5);
   return 5;

// - STATE 13 -
state_13_label:
   CLOSE_CHAR(1);
   return 1;

// - STATE 14 -
state_14_label:
   CLOSE_CHAR(6);
   return 6;

// - STATE 15 -
state_15_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 108) {
      goto state_23_label;
   }
   return c_idx_not_exist;

// - STATE 16 -
state_16_label:
   CLOSE_CHAR(22);
   return 22;

// - STATE 17 -
state_17_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 101) {
      goto state_24_label;
   }
   return c_idx_not_exist;

// - STATE 18 -
state_18_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 110) {
      goto state_25_label;
   }
   return c_idx_not_exist;

// - STATE 19 -
state_19_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 116) {
      goto state_26_label;
   }
   return c_idx_not_exist;

// - STATE 20 -
state_20_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 102) {
      goto state_27_label;
   }
   if (in_char == 103) {
      goto state_28_label;
   }
   return c_idx_not_exist;

// - STATE 21 -
state_21_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 115) {
      goto state_29_label;
   }
   return c_idx_not_exist;

// - STATE 22 -
state_22_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 112) {
      goto state_30_label;
   }
   return c_idx_not_exist;

// - STATE 23 -
state_23_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 45) {
      goto state_31_label;
   }
   return c_idx_not_exist;

// - STATE 24 -
state_24_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 109) {
      goto state_32_label;
   }
   return c_idx_not_exist;

// - STATE 25 -
state_25_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 103) {
      goto state_33_label;
   }
   return c_idx_not_exist;

// - STATE 26 -
state_26_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 45) {
      goto state_34_label;
   }
   return c_idx_not_exist;

// - STATE 27 -
state_27_label:
   CLOSE_CHAR(13);
   GET_NEXT_CHAR();

   if (in_char == 45) {
      goto state_35_label;
   }
   return 13;

// - STATE 28 -
state_28_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 101) {
      goto state_36_label;
   }
   return c_idx_not_exist;

// - STATE 29 -
state_29_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 116) {
      goto state_37_label;
   }
   return c_idx_not_exist;

// - STATE 30 -
state_30_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 101) {
      goto state_38_label;
   }
   return c_idx_not_exist;

// - STATE 31 -
state_31_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 105) {
      goto state_39_label;
   }
   if (in_char == 107) {
      goto state_40_label;
   }
   return c_idx_not_exist;

// - STATE 32 -
state_32_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 115) {
      goto state_41_label;
   }
   return c_idx_not_exist;

// - STATE 33 -
state_33_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 116) {
      goto state_42_label;
   }
   return c_idx_not_exist;

// - STATE 34 -
state_34_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 105) {
      goto state_43_label;
   }
   return c_idx_not_exist;

// - STATE 35 -
state_35_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 105) {
      goto state_44_label;
   }
   if (in_char == 116) {
      goto state_45_label;
   }
   return c_idx_not_exist;

// - STATE 36 -
state_36_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 120) {
      goto state_46_label;
   }
   return c_idx_not_exist;

// - STATE 37 -
state_37_label:
   CLOSE_CHAR(17);
   return 17;

// - STATE 38 -
state_38_label:
   CLOSE_CHAR(0);
   return 0;

// - STATE 39 -
state_39_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 116) {
      goto state_47_label;
   }
   return c_idx_not_exist;

// - STATE 40 -
state_40_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 101) {
      goto state_48_label;
   }
   return c_idx_not_exist;

// - STATE 41 -
state_41_label:
   CLOSE_CHAR(18);
   return 18;

// - STATE 42 -
state_42_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 104) {
      goto state_49_label;
   }
   return c_idx_not_exist;

// - STATE 43 -
state_43_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 116) {
      goto state_50_label;
   }
   return c_idx_not_exist;

// - STATE 44 -
state_44_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 102) {
      goto state_51_label;
   }
   return c_idx_not_exist;

// - STATE 45 -
state_45_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 121) {
      goto state_52_label;
   }
   return c_idx_not_exist;

// - STATE 46 -
state_46_label:
   CLOSE_CHAR(16);
   return 16;

// - STATE 47 -
state_47_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 101) {
      goto state_53_label;
   }
   return c_idx_not_exist;

// - STATE 48 -
state_48_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 121) {
      goto state_54_label;
   }
   return c_idx_not_exist;

// - STATE 49 -
state_49_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 32) {
      goto state_55_label;
   }
   return c_idx_not_exist;

// - STATE 50 -
state_50_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 101) {
      goto state_56_label;
   }
   return c_idx_not_exist;

// - STATE 51 -
state_51_label:
   CLOSE_CHAR(14);
   return 14;

// - STATE 52 -
state_52_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 112) {
      goto state_57_label;
   }
   return c_idx_not_exist;

// - STATE 53 -
state_53_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 109) {
      goto state_58_label;
   }
   return c_idx_not_exist;

// - STATE 54 -
state_54_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 115) {
      goto state_59_label;
   }
   return c_idx_not_exist;

// - STATE 55 -
state_55_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 33) {
      goto state_60_label;
   }
   if (in_char == 60) {
      goto state_61_label;
   }
   if (in_char == 61) {
      goto state_62_label;
   }
   if (in_char == 62) {
      goto state_63_label;
   }
   return c_idx_not_exist;

// - STATE 56 -
state_56_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 109) {
      goto state_64_label;
   }
   return c_idx_not_exist;

// - STATE 57 -
state_57_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 101) {
      goto state_65_label;
   }
   return c_idx_not_exist;

// - STATE 58 -
state_58_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 115) {
      goto state_66_label;
   }
   return c_idx_not_exist;

// - STATE 59 -
state_59_label:
   CLOSE_CHAR(21);
   return 21;

// - STATE 60 -
state_60_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 61) {
      goto state_67_label;
   }
   return c_idx_not_exist;

// - STATE 61 -
state_61_label:
   CLOSE_CHAR(9);
   GET_NEXT_CHAR();

   if (in_char == 61) {
      goto state_68_label;
   }
   return 9;

// - STATE 62 -
state_62_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 61) {
      goto state_69_label;
   }
   return c_idx_not_exist;

// - STATE 63 -
state_63_label:
   CLOSE_CHAR(10);
   GET_NEXT_CHAR();

   if (in_char == 61) {
      goto state_70_label;
   }
   return 10;

// - STATE 64 -
state_64_label:
   CLOSE_CHAR(c_idx_not_exist);
   GET_NEXT_CHAR();

   if (in_char == 115) {
      goto state_71_label;
   }
   return c_idx_not_exist;

// - STATE 65 -
state_65_label:
   CLOSE_CHAR(15);
   return 15;

// - STATE 66 -
state_66_label:
   CLOSE_CHAR(20);
   return 20;

// - STATE 67 -
state_67_label:
   CLOSE_CHAR(8);
   return 8;

// - STATE 68 -
state_68_label:
   CLOSE_CHAR(11);
   return 11;

// - STATE 69 -
state_69_label:
   CLOSE_CHAR(7);
   return 7;

// - STATE 70 -
state_70_label:
   CLOSE_CHAR(12);
   return 12;

// - STATE 71 -
state_71_label:
   CLOSE_CHAR(19);
   return 19;

}/*}}}*/

#define BIC_VALIDATE_TODO_ERROR(FILE_NAME,LINE) \
{/*{{{*/\
  string_s *string_ptr = it.get_new_string_ptr();\
  string_ptr->set(strlen(FILE_NAME),FILE_NAME);\
\
  location_s *new_location = it.get_new_location_ptr();\
  new_location->v_type = c_bi_class_string;\
  new_location->v_reference_cnt.atomic_set(0);\
  new_location->v_data_ptr = string_ptr;\
\
  exception_s *new_exception = exception_s::throw_exception(it,c_error_TODO_EXCEPTION,source_pos,new_location);\
  new_exception->params.push(LINE);\
}/*}}}*/

#define VALIDATE_PAIR_REFERENCE(VALUE,PROPS_REF,ERR_CODE) \
{/*{{{*/\
  pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)schema->v_data_ptr;\
\
  tree_ptr->it_ptr = it_ptr;\
  tree_ptr->source_pos = source_pos;\
\
  pointer_map_s search_map = {(pointer)PROPS_REF,nullptr};\
  unsigned index = tree_ptr->get_idx(search_map);\
\
  if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)\
  {\
    (PROPS_REF)->v_reference_cnt.atomic_inc();\
    ((pointer_array_s *)props_stack->v_data_ptr)->push(PROPS_REF);\
\
    ERR_CODE;\
  }\
\
  /* - ERROR - */\
  if (index == c_idx_not_exist)\
  {\
    (PROPS_REF)->v_reference_cnt.atomic_inc();\
    ((pointer_array_s *)props_stack->v_data_ptr)->push(PROPS_REF);\
\
    exception_s::throw_exception(it,error_base + c_error_VALIDATOR_ENTRY_NOT_FOUND,source_pos,PROPS_REF);\
\
    ERR_CODE;\
  }\
\
  if (!validate_pair(VALUE,it.get_location_value(tree_ptr->data[index].object.value)))\
  {\
    (PROPS_REF)->v_reference_cnt.atomic_inc();\
    ((pointer_array_s *)props_stack->v_data_ptr)->push(PROPS_REF);\
\
    ERR_CODE;\
  }\
}/*}}}*/

#define VALIDATE_PAIR_CALL(VALUE,PROPS,ERR_CODE) \
{/*{{{*/\
  if (PROPS->v_type == c_bi_class_string)\
  {\
    VALIDATE_PAIR_REFERENCE(VALUE,PROPS,ERR_CODE);\
  }\
  else\
  {\
    if (!validate_pair(VALUE,PROPS))\
    {\
      ERR_CODE;\
    }\
  }\
}/*}}}*/

bool validator_s::validate_pair(location_s *a_value,location_s *a_props) //NOLINT(google-readability-function-size,readability-function-size)
{/*{{{*/
  interpreter_thread_s &it = *it_ptr;

  // - ERROR -
  if (a_props->v_type != c_bi_class_array)
  {
    exception_s::throw_exception(it,error_base + c_error_VALIDATOR_INVALID_PROPERTY_TYPE,source_pos,(location_s *)it.blank_location);
    return false;
  }

  pointer_array_s *props_array = (pointer_array_s *)a_props->v_data_ptr;

  // - ERROR -
  if (props_array->used & 0x01)
  {
    exception_s::throw_exception(it,error_base + c_error_VALIDATOR_WRONG_PROPERTIES_ARRAY_SIZE,source_pos,(location_s *)it.blank_location);
    return false;
  }

  if (props_array->used != 0)
  {
    pointer *prop_ptr = props_array->data;
    pointer *prop_ptr_end = prop_ptr + props_array->used;

    do {

      // - retrieve property key and value -
      location_s *prop_key = it.get_location_value(prop_ptr[0]);
      location_s *prop_value = it.get_location_value(prop_ptr[1]);

#define VALIDATE_STACKS_PUSH_PROP_KEY() \
/*{{{*/\
  prop_key->v_reference_cnt.atomic_inc();\
  ((pointer_array_s *)props_stack->v_data_ptr)->push(prop_key);\
/*}}}*/

      // - ERROR -
      if (prop_key->v_type != c_bi_class_string)
      {
        exception_s::throw_exception(it,error_base + c_error_VALIDATOR_INVALID_PROPERTY_TYPE,source_pos,(location_s *)it.blank_location);
        return false;
      }

      string_s *prop_key_str = (string_s *)prop_key->v_data_ptr;

      unsigned input_idx = 0;
      unsigned prop_id = recognize_property(prop_key_str->data,input_idx);

      // - just part of prop key was processed -
      if (input_idx != prop_key_str->size - 1)
      {
        prop_id = c_idx_not_exist;
      }

      switch (prop_id)
      {
      case prop_type:
      {/*{{{*/

        // - ERROR -
        if (prop_value->v_type != c_bi_class_type)
        {
          VALIDATE_STACKS_PUSH_PROP_KEY();

          exception_s::throw_exception(it,error_base + c_error_VALIDATOR_INVALID_PROPERTY_TYPE,source_pos,(location_s *)it.blank_location);
          return false;
        }

        // - ERROR -
        if (a_value->v_type != (unsigned)prop_value->v_data_ptr)
        {
          VALIDATE_STACKS_PUSH_PROP_KEY();

          exception_s::throw_exception(it,error_base + c_error_VALIDATOR_INVALID_VALUE_TYPE,source_pos,(location_s *)it.blank_location);
          return false;
        }
      }/*}}}*/
      break;
      case prop_equal:
      case prop_not_equal:
      case prop_lesser:
      case prop_greater:
      case prop_lesser_equal:
      case prop_greater_equal:
      {/*{{{*/
        long long int result;
        BIC_CALL_COMPARE(it,a_value,prop_value,source_pos,return false;)

        bool ok;
        switch (prop_id)
        {
          case prop_equal:
            ok = result == 0;
            break;
          case prop_not_equal:
            ok = result != 0;
            break;
          case prop_lesser:
            ok = result < 0;
            break;
          case prop_greater:
            ok = result > 0;
            break;
          case prop_lesser_equal:
            ok = result <= 0;
            break;
          case prop_greater_equal:
            ok = result >= 0;
            break;
        }

        // - ERROR -
        if (!ok)
        {
          VALIDATE_STACKS_PUSH_PROP_KEY();

          exception_s::throw_exception(it,error_base + c_error_VALIDATOR_INVALID_VALUE,source_pos,(location_s *)it.blank_location);
          return false;
        }
      }/*}}}*/
      break;
      case prop_length_equal:
      case prop_length_not_equal:
      case prop_length_lesser:
      case prop_length_greater:
      case prop_length_lesser_equal:
      case prop_length_greater_equal:
      {/*{{{*/

        // - ERROR -
        if (prop_value->v_type != c_bi_class_integer)
        {
          exception_s::throw_exception(it,error_base + c_error_VALIDATOR_INVALID_PROPERTY_TYPE,source_pos,(location_s *)it.blank_location);
          return false;
        }

        long long int prop_length = (long long int)prop_value->v_data_ptr;
        long long int value_length;

        BIC_CALL_LENGTH(it,a_value,value_length,source_pos,return false);

        bool ok;
        switch (prop_id)
        {
          case prop_length_equal:
            ok = value_length == prop_length;
            break;
          case prop_length_not_equal:
            ok = value_length != prop_length;
            break;
          case prop_length_lesser:
            ok = value_length < prop_length;
            break;
          case prop_length_greater:
            ok = value_length > prop_length;
            break;
          case prop_length_lesser_equal:
            ok = value_length <= prop_length;
            break;
          case prop_length_greater_equal:
            ok = value_length >= prop_length;
            break;
        }

        // - ERROR -
        if (!ok)
        {
          VALIDATE_STACKS_PUSH_PROP_KEY();

          exception_s::throw_exception(it,error_base + c_error_VALIDATOR_INVALID_VALUE_LENGTH,source_pos,(location_s *)it.blank_location);
          return false;
        }
      }/*}}}*/
      break;
      case prop_reference:
      {/*{{{*/

        // - ERROR -
        if (prop_value->v_type != c_bi_class_string)
        {
          VALIDATE_STACKS_PUSH_PROP_KEY();

          exception_s::throw_exception(it,error_base + c_error_VALIDATOR_INVALID_PROPERTY_TYPE,source_pos,(location_s *)it.blank_location);
          return false;
        }

        VALIDATE_PAIR_REFERENCE(a_value,prop_value,
          VALIDATE_STACKS_PUSH_PROP_KEY();

          return false;
        );
      }/*}}}*/
      break;
      case prop_reference_if:
      case prop_reference_type:
      {/*{{{*/

        // - ERROR -
        if (prop_value->v_type != c_bi_class_array)
        {
          VALIDATE_STACKS_PUSH_PROP_KEY();

          exception_s::throw_exception(it,error_base + c_error_VALIDATOR_INVALID_PROPERTY_TYPE,source_pos,(location_s *)it.blank_location);
          return false;
        }

        // - ERROR -
        if (a_value->v_type != c_rm_class_dict)
        {
          VALIDATE_STACKS_PUSH_PROP_KEY();

          exception_s::throw_exception(it,error_base + c_error_VALIDATOR_INVALID_VALUE_TYPE,source_pos,(location_s *)it.blank_location);
          return false;
        }

        pointer_array_s *array_ptr = (pointer_array_s *)prop_value->v_data_ptr;

        // - ERROR -
        if (array_ptr->used != 2)
        {
          VALIDATE_STACKS_PUSH_PROP_KEY();

          exception_s::throw_exception(it,error_base + c_error_VALIDATOR_INVALID_PROPERTY_VALUE,source_pos,(location_s *)it.blank_location);
          return false;
        }

        location_s *ref_location = it.get_location_value(array_ptr->data[0]);
        location_s *key_location = it.get_location_value(array_ptr->data[1]);

        // - ERROR -
        if (ref_location->v_type != c_bi_class_string)
        {
          VALIDATE_STACKS_PUSH_PROP_KEY();

          exception_s::throw_exception(it,error_base + c_error_VALIDATOR_INVALID_PROPERTY_VALUE,source_pos,(location_s *)it.blank_location);
          return false;
        }

        // - search for item -
        pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)a_value->v_data_ptr;

        tree_ptr->it_ptr = &it;
        tree_ptr->source_pos = source_pos;

        pointer_map_s search_map = {(pointer)key_location,nullptr};
        unsigned ref_index = tree_ptr->get_idx(search_map);

        if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
        {
          VALIDATE_STACKS_PUSH_PROP_KEY();

          return false;
        }

        if (ref_index != c_idx_not_exist)
        {
          switch (prop_id)
          {
          case prop_reference_if:
            {/*{{{*/
              VALIDATE_PAIR_REFERENCE(a_value,ref_location,VALIDATE_STACKS_PUSH_PROP_KEY();
                VALIDATE_STACKS_PUSH_PROP_KEY();

                return false;
              );
            }/*}}}*/
            break;
          case prop_reference_type:
            {/*{{{*/
              location_s *type_location = it.get_location_value(tree_ptr->data[ref_index].object.value);

              // - ERROR -
              if (type_location->v_type != c_bi_class_string)
              {
                VALIDATE_STACKS_PUSH_PROP_KEY();

                exception_s::throw_exception(it,error_base + c_error_VALIDATOR_INVALID_PROPERTY_VALUE,source_pos,(location_s *)it.blank_location);
                return false;
              }

              string_s *prop_ref_str = it.get_new_string_ptr();
              prop_ref_str->setf("%s-%s",
                  ((string_s *)ref_location->v_data_ptr)->data,
                  ((string_s *)type_location->v_data_ptr)->data);

              // - create properties reference location -
              BIC_CREATE_NEW_LOCATION(prop_ref_location,c_bi_class_string,prop_ref_str);

              VALIDATE_PAIR_REFERENCE(a_value,prop_ref_location,
                it.release_location_ptr(prop_ref_location);

                VALIDATE_STACKS_PUSH_PROP_KEY();

                return false;
              );

              it.release_location_ptr(prop_ref_location);
            }/*}}}*/
            break;
          }
        }
      }/*}}}*/
      break;
      case prop_regex:
      {/*{{{*/

        // - ERROR -
        if (prop_value->v_type != c_bi_class_string)
        {
          VALIDATE_STACKS_PUSH_PROP_KEY();

          exception_s::throw_exception(it,error_base + c_error_VALIDATOR_INVALID_PROPERTY_TYPE,source_pos,(location_s *)it.blank_location);
          return false;
        }

        // - ERROR -
        if (a_value->v_type != c_bi_class_string)
        {
          VALIDATE_STACKS_PUSH_PROP_KEY();

          exception_s::throw_exception(it,error_base + c_error_VALIDATOR_INVALID_VALUE_TYPE,source_pos,(location_s *)it.blank_location);
          return false;
        }

        // - retrieve regular expression index -
        string_s *string_ptr = (string_s *)prop_value->v_data_ptr;
        unsigned regex_idx = regex_map.unique_insert(*string_ptr);

        regex_t *regex_ptr;
        if (regex_idx >= regex_list.used)
        {
          while (regex_list.used < regex_idx) { regex_list.push(nullptr); }

          // - compile new regular expresion -
          regex_ptr = (regex_t *)cmalloc(sizeof(regex_t));

          // - ERROR -
          if (regcomp(regex_ptr,string_ptr->data,0) != 0)
          {
            cfree(regex_ptr);

            VALIDATE_STACKS_PUSH_PROP_KEY();

            exception_s::throw_exception(it,error_base + c_error_VALIDATOR_INVALID_PROPERTY_REGULAR_EXPRESSION,source_pos,(location_s *)it.blank_location);
            return false;
          }

          regex_list.push(regex_ptr);
        }
        else
        {
          regex_ptr = (regex_t *)regex_list[regex_idx];
        }

        // - ERROR -
        regmatch_t regmatch;
        if (regexec(regex_ptr,((string_s *)a_value->v_data_ptr)->data,1,&regmatch,0) != 0)
        {
          VALIDATE_STACKS_PUSH_PROP_KEY();

          exception_s::throw_exception(it,error_base + c_error_VALIDATOR_INVALID_VALUE,source_pos,(location_s *)it.blank_location);
          return false;
        }
      }/*}}}*/
      break;
      case prop_test:
      {/*{{{*/

        // - ERROR -
        if (prop_value->v_type != c_bi_class_delegate)
        {
          VALIDATE_STACKS_PUSH_PROP_KEY();

          exception_s::throw_exception(it,error_base + c_error_VALIDATOR_INVALID_PROPERTY_TYPE,source_pos,(location_s *)it.blank_location);
          return false;
        }

        delegate_s *delegate_ptr = (delegate_s *)prop_value->v_data_ptr;

        // - ERROR -
        if (delegate_ptr->param_cnt != 1)
        {
          VALIDATE_STACKS_PUSH_PROP_KEY();

          exception_s::throw_exception(it,error_base + c_error_VALIDATOR_INVALID_PROPERTY_DELEGATE,source_pos,(location_s *)it.blank_location);
          return false;
        }

        // - callback parameters -
        const unsigned param_cnt = 1;
        pointer *param_data = (pointer *)&a_value;

        // - call delegate method -
        location_s *trg_location = nullptr;
        BIC_CALL_DELEGATE(it,delegate_ptr,param_data,param_cnt,trg_location,source_pos,
          VALIDATE_STACKS_PUSH_PROP_KEY();

          return false;
        );

        // - ERROR -
        if (trg_location->v_type != c_bi_class_integer)
        {
          it.release_location_ptr(trg_location);

          VALIDATE_STACKS_PUSH_PROP_KEY();

          exception_s::throw_exception(it,error_base + c_error_VALIDATOR_INVALID_PROPERTY_DELEGATE_RETURN_VALUE,source_pos,(location_s *)it.blank_location);
          return false;
        }

        long long int result = (long long int)trg_location->v_data_ptr;
        it.release_location_ptr(trg_location);

        // - ERROR -
        if (result == 0)
        {
          VALIDATE_STACKS_PUSH_PROP_KEY();

          exception_s::throw_exception(it,error_base + c_error_VALIDATOR_INVALID_VALUE,source_pos,(location_s *)it.blank_location);
          return false;
        }
      }/*}}}*/
      break;
      case prop_items:
      {/*{{{*/

        // - ERROR -
        if (prop_value->v_type != c_bi_class_array)
        {
          VALIDATE_STACKS_PUSH_PROP_KEY();

          exception_s::throw_exception(it,error_base + c_error_VALIDATOR_INVALID_PROPERTY_TYPE,source_pos,(location_s *)it.blank_location);
          return false;
        }

        pointer_array_s *item_array = (pointer_array_s *)prop_value->v_data_ptr;

        // - ERROR -
        if (item_array->used & 0x01)
        {
          VALIDATE_STACKS_PUSH_PROP_KEY();

          exception_s::throw_exception(it,error_base + c_error_VALIDATOR_WRONG_PROPERTIES_ARRAY_SIZE,source_pos,(location_s *)it.blank_location);
          return false;
        }

        if (item_array->used != 0)
        {
          pointer *i_ptr = item_array->data;
          pointer *i_ptr_end = i_ptr + item_array->used;
          do {
            location_s *item_key = it.get_location_value(i_ptr[0]);
            location_s *item_props = it.get_location_value(i_ptr[1]);

#define VALIDATE_STACKS_PUSH_ITEMS() \
/*{{{*/\
  item_key->v_reference_cnt.atomic_add(2);\
  ((pointer_array_s *)value_stack->v_data_ptr)->push(item_key);\
  ((pointer_array_s *)props_stack->v_data_ptr)->push(item_key);\
\
  VALIDATE_STACKS_PUSH_PROP_KEY();\
/*}}}*/

            location_s *trg_location;
            BIC_CALL_OPERATOR_BINARY_LE_BR_RE_BR(it,a_value,item_key,trg_location,source_pos,
              VALIDATE_STACKS_PUSH_ITEMS();

              return false;
            );

            VALIDATE_PAIR_CALL(it.get_location_value(trg_location),item_props,
              it.release_location_ptr(trg_location);

              VALIDATE_STACKS_PUSH_ITEMS();

              return false;
            );

            it.release_location_ptr(trg_location);
          } while((i_ptr += 2) < i_ptr_end);
        }
      }/*}}}*/
      break;
      case prop_opt_items:
      {/*{{{*/

        // - ERROR -
        if (prop_value->v_type != c_bi_class_array)
        {
          VALIDATE_STACKS_PUSH_PROP_KEY();

          exception_s::throw_exception(it,error_base + c_error_VALIDATOR_INVALID_PROPERTY_TYPE,source_pos,(location_s *)it.blank_location);
          return false;
        }

        // - ERROR -
        if (a_value->v_type != c_rm_class_dict)
        {
          VALIDATE_STACKS_PUSH_PROP_KEY();

          exception_s::throw_exception(it,error_base + c_error_VALIDATOR_INVALID_VALUE_TYPE,source_pos,(location_s *)it.blank_location);
          return false;
        }

        pointer_array_s *item_array = (pointer_array_s *)prop_value->v_data_ptr;

        // - ERROR -
        if (item_array->used & 0x01)
        {
          VALIDATE_STACKS_PUSH_PROP_KEY();

          exception_s::throw_exception(it,error_base + c_error_VALIDATOR_WRONG_PROPERTIES_ARRAY_SIZE,source_pos,(location_s *)it.blank_location);
          return false;
        }

        if (item_array->used != 0)
        {
          pointer *i_ptr = item_array->data;
          pointer *i_ptr_end = i_ptr + item_array->used;
          do {
            location_s *item_key = it.get_location_value(i_ptr[0]);
            location_s *item_props = it.get_location_value(i_ptr[1]);

#define VALIDATE_STACKS_PUSH_ITEMS() \
/*{{{*/\
  item_key->v_reference_cnt.atomic_add(2);\
  ((pointer_array_s *)value_stack->v_data_ptr)->push(item_key);\
  ((pointer_array_s *)props_stack->v_data_ptr)->push(item_key);\
\
  VALIDATE_STACKS_PUSH_PROP_KEY();\
/*}}}*/

            // - search for item -
            pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)a_value->v_data_ptr;

            tree_ptr->it_ptr = &it;
            tree_ptr->source_pos = source_pos;

            pointer_map_s search_map = {(pointer)item_key,nullptr};
            unsigned index = tree_ptr->get_idx(search_map);

            if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
            {
              VALIDATE_STACKS_PUSH_ITEMS();

              return false;
            }

            // - item was found -
            if (index != c_idx_not_exist)
            {
              pointer value_location = tree_ptr->data[index].object.value;

              VALIDATE_PAIR_CALL(it.get_location_value(value_location),item_props,
                VALIDATE_STACKS_PUSH_ITEMS();

                return false;
              );
            }
          } while((i_ptr += 2) < i_ptr_end);
        }
      }/*}}}*/
      break;
      case prop_all_items:
      {/*{{{*/
        if (a_value->v_type == c_bi_class_array)
        {/*{{{*/
          pointer_array_s *array_ptr = (pointer_array_s *)a_value->v_data_ptr;

          if (array_ptr->used != 0)
          {
            pointer *i_ptr = array_ptr->data;
            pointer *i_ptr_end = i_ptr + array_ptr->used;
            do {
              location_s *item_location = it.get_location_value(*i_ptr);

              VALIDATE_PAIR_CALL(item_location,prop_value,
                long long int index = i_ptr - array_ptr->data;

                BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_integer,index,2);
                ((pointer_array_s *)value_stack->v_data_ptr)->push(new_location);
                ((pointer_array_s *)props_stack->v_data_ptr)->push(new_location);

                VALIDATE_STACKS_PUSH_PROP_KEY();

                return false;
              );
            } while(++i_ptr < i_ptr_end);
          }
        }/*}}}*/
        else if (a_value->v_type == c_rm_class_dict)
        {/*{{{*/
          pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)a_value->v_data_ptr;

          if (tree_ptr->root_idx != c_idx_not_exist)
          {
            unsigned stack[RB_TREE_STACK_SIZE(*tree_ptr)];
            unsigned *stack_ptr = stack;

            unsigned t_idx = tree_ptr->get_stack_min_value_idx(tree_ptr->root_idx,&stack_ptr);
            do
            {
              pointer_map_s &map = tree_ptr->data[t_idx].object;

              VALIDATE_PAIR_CALL(it.get_location_value(map.value),prop_value,
                location_s *key_location = (location_s *)map.key;

                key_location->v_reference_cnt.atomic_add(2);
                ((pointer_array_s *)value_stack->v_data_ptr)->push(key_location);
                ((pointer_array_s *)props_stack->v_data_ptr)->push(key_location);

                VALIDATE_STACKS_PUSH_PROP_KEY();

                return false;
              );

              t_idx = tree_ptr->get_stack_next_idx(t_idx,&stack_ptr,stack);
            }
            while(t_idx != c_idx_not_exist);
          }
        }/*}}}*/
        else
        {/*{{{*/
          unsigned iter_type = it.get_iterable_type(a_value);

          // - ERROR -
          if (iter_type != c_iter_first_idx_next_idx_item)
          {
            VALIDATE_STACKS_PUSH_PROP_KEY();

            exception_s::throw_exception(it,error_base + c_error_VALIDATOR_INVALID_VALUE,source_pos,(location_s *)it.blank_location);
            return false;
          }

          long long int index;
          location_s *item_reference;
          location_s *item_location;

          // - retrieve first index -
          BIC_CALL_FIRST_IDX(it,a_value,index,source_pos,
            VALIDATE_STACKS_PUSH_PROP_KEY();

            return false;
          );

          while (index != c_idx_not_exist)
          {
            // - retrieve item location -
            BIC_CALL_ITEM(it,a_value,index,item_reference,source_pos,
              VALIDATE_STACKS_PUSH_PROP_KEY();

              return false;
            );
            item_location = it.get_location_value(item_reference);

            VALIDATE_PAIR_CALL(item_location,prop_value,
              it.release_location_ptr(item_reference);

              BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_integer,index,2);

              ((pointer_array_s *)value_stack->v_data_ptr)->push(new_location);
              ((pointer_array_s *)props_stack->v_data_ptr)->push(new_location);

              VALIDATE_STACKS_PUSH_PROP_KEY();

              return false;
            );

            it.release_location_ptr(item_reference);

            // - retrieve next index -
            BIC_CALL_NEXT_IDX(it,a_value,index,index,source_pos,
              VALIDATE_STACKS_PUSH_PROP_KEY();

              return false;
            );
          }
        }/*}}}*/
      }/*}}}*/
      break;
      case prop_all_keys:
      {/*{{{*/

        // - ERROR -
        if (a_value->v_type != c_rm_class_dict)
        {
          VALIDATE_STACKS_PUSH_PROP_KEY();

          exception_s::throw_exception(it,error_base + c_error_VALIDATOR_INVALID_VALUE,source_pos,(location_s *)it.blank_location);
          return false;
        }

        pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)a_value->v_data_ptr;

        if (tree_ptr->root_idx != c_idx_not_exist)
        {
          unsigned stack[RB_TREE_STACK_SIZE(*tree_ptr)];
          unsigned *stack_ptr = stack;

          unsigned t_idx = tree_ptr->get_stack_min_value_idx(tree_ptr->root_idx,&stack_ptr);
          do
          {
            location_s *key_location = (location_s *)tree_ptr->data[t_idx].object.key;

            VALIDATE_PAIR_CALL(key_location,prop_value,
              key_location->v_reference_cnt.atomic_add(2);
              ((pointer_array_s *)value_stack->v_data_ptr)->push(key_location);
              ((pointer_array_s *)props_stack->v_data_ptr)->push(key_location);

              VALIDATE_STACKS_PUSH_PROP_KEY();

              return false;
            );

            t_idx = tree_ptr->get_stack_next_idx(t_idx,&stack_ptr,stack);
          }
          while(t_idx != c_idx_not_exist);
        }
      }/*}}}*/
      break;
      case prop_in:
      {/*{{{*/

        // - ERROR -
        if (prop_value->v_type != c_rm_class_set)
        {
          VALIDATE_STACKS_PUSH_PROP_KEY();

          exception_s::throw_exception(it,error_base + c_error_VALIDATOR_INVALID_PROPERTY_TYPE,source_pos,(location_s *)it.blank_location);
          return false;
        }

        pointer_tree_s *tree_ptr = (pointer_tree_s *)prop_value->v_data_ptr;
        tree_ptr->it_ptr = &it;
        tree_ptr->source_pos = source_pos;

        unsigned index = tree_ptr->get_idx((pointer)a_value);

        if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
        {
          VALIDATE_STACKS_PUSH_PROP_KEY();

          return false;
        }

        // - ERROR -
        if (index == c_idx_not_exist)
        {
          VALIDATE_STACKS_PUSH_PROP_KEY();

          exception_s::throw_exception(it,error_base + c_error_VALIDATOR_INVALID_VALUE,source_pos,(location_s *)it.blank_location);
          return false;
        }
      }/*}}}*/
      break;

      // - ERROR -
      default:
        VALIDATE_STACKS_PUSH_PROP_KEY();

        exception_s::throw_exception(it,error_base + c_error_VALIDATOR_INVALID_PROPERTY_ID,source_pos,prop_key);
        return false;
      }
    } while((prop_ptr += 2) < prop_ptr_end);
  }

  return true;
}/*}}}*/

