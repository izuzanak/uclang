
@begin
include "ucl_validator.h"
@end

/*
 * basic definitions and constants
 */

const char *c_prop_names[c_prop_name_cnt] =
{/*{{{*/
  "type",
  "==",
  "!=",
  "<",
  ">",
  "<=",
  ">=",
  "length ==",
  "length !=",
  "length <",
  "length >",
  "length <=",
  "length >=",
  "regex",
  "items",
};/*}}}*/

// - validator global init object -
validator_c g_validator;

string_rb_tree_s validator_c::c_prop_map;

/*
 * methods of structure validator_s
 */

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

#define VALIDATOR_VALIDATE_PAIR_REFERENCE(VALUE,PROPS_REF,ERR_CODE) \
{/*{{{*/\
  \
  /* FIXME TODO continue */\
  cassert(0);\
}/*}}}*/

#define VALIDATOR_VALIDATE_PAIR_CALL(VALUE,PROPS,ERR_CODE) \
{/*{{{*/\
  if (PROPS->v_type == c_bi_class_string)\
  {\
    VALIDATOR_VALIDATE_PAIR_REFERENCE(VALUE,PROPS,ERR_CODE);\
  }\
  else\
  {\
    if (!validate_pair(VALUE,PROPS))\
    {\
      ERR_CODE;\
    }\
  }\
}/*}}}*/

bool validator_s::validate_pair(location_s *a_value,location_s *a_props)
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

      unsigned prop_id = validator_c::c_prop_map.get_idx(*((string_s *)prop_key->v_data_ptr));
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
          while (regex_list.used < regex_idx) regex_list.push(nullptr);

          // - compile new regular expresion -
          regex_ptr = (regex_t *)cmalloc(sizeof(regex_t));

          // - ERROR -
          if (regcomp(regex_ptr,string_ptr->data,0) != 0)
          {
            cfree(regex_ptr);

            VALIDATE_STACKS_PUSH_PROP_KEY();

            exception_s::throw_exception(it,error_base + c_error_VALIDATOR_INVALID_REGULAR_EXPRESSION,source_pos,(location_s *)it.blank_location);
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

            VALIDATOR_VALIDATE_PAIR_CALL(it.get_location_value(trg_location),item_props,
              it.release_location_ptr(trg_location);

              VALIDATE_STACKS_PUSH_ITEMS();

              return false;
            );

            it.release_location_ptr(trg_location);
          } while((i_ptr += 2) < i_ptr_end);
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

