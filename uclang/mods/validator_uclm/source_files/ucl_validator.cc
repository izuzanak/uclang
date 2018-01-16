
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
  "opt-items",
  "all-keys",
  "all-items",
};/*}}}*/

// - validator global init object -
validator_c g_validator;

string_rb_tree_s validator_c::c_prop_map;

/*
 * methods of structure validator_s
 */

#define BIC_VALIDATE_TODO_ERROR(FILE_NAME,LINE) \
{/*{{{*/\
  string_s *string_ptr = it_ptr->get_new_string_ptr();\
  string_ptr->set(strlen(FILE_NAME),FILE_NAME);\
  \
  location_s *new_location = it_ptr->get_new_location_ptr();\
  new_location->v_type = c_bi_class_string;\
  new_location->v_reference_cnt.atomic_set(0);\
  new_location->v_data_ptr = string_ptr;\
  \
  exception_s *new_exception = exception_s::throw_exception(it,c_error_TODO_EXCEPTION,source_pos,new_location);\
  new_exception->params.push(LINE);\
}/*}}}*/

bool validator_s::validate_pair(location_s *a_value,location_s *a_props)
{/*{{{*/
  interpreter_thread_s &it = *it_ptr;

  // - ERROR -
  if (a_props->v_type != c_rm_class_dict)
  {
    exception_s::throw_exception(it,error_base + c_error_VALIDATOR_EXPECTED_DICT_AS_PROPERTIERS,source_pos,(location_s *)it_ptr->blank_location);
    return false;
  }

  pointer_map_tree_s *props_tree = (pointer_map_tree_s *)a_props->v_data_ptr;

  if (props_tree->root_idx != c_idx_not_exist)
  {
    unsigned stack[props_tree->get_descent_stack_size()];
    unsigned *stack_ptr = stack;

    unsigned t_idx = props_tree->get_stack_min_value_idx(props_tree->root_idx,&stack_ptr);
    do {
      pointer_map_s &map = props_tree->data[t_idx].object;

      // - retrieve property key and value -
      location_s *prop_key = (location_s *)map.key;
      location_s *prop_value = (location_s *)it_ptr->get_location_value(map.value);

      // - ERROR -
      if (prop_key->v_type != c_bi_class_string)
      {
        exception_s::throw_exception(it,error_base + c_error_VALIDATOR_EXPECTED_STRING_AS_PROPERTY_ID,source_pos,(location_s *)it_ptr->blank_location);
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
          exception_s::throw_exception(it,error_base + c_error_VALIDATOR_EXPECTED_TYPE_AS_TYPE_ID,source_pos,(location_s *)it_ptr->blank_location);
          return false;
        }

        // - ERROR -
        if (a_value->v_type != (unsigned)prop_value->v_data_ptr)
        {
          exception_s::throw_exception(it,error_base + c_error_VALIDATOR_INVALID_VALUE_TYPE,source_pos,(location_s *)it_ptr->blank_location);
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
          exception_s::throw_exception(it,error_base + c_error_VALIDATOR_INVALID_VALUE,source_pos,(location_s *)it_ptr->blank_location);
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
          exception_s::throw_exception(it,error_base + c_error_VALIDATOR_EXPECTED_INTEGER_AS_LENGTH,source_pos,(location_s *)it_ptr->blank_location);
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
          exception_s::throw_exception(it,error_base + c_error_VALIDATOR_INVALID_VALUE_LENGTH,source_pos,(location_s *)it_ptr->blank_location);
          return false;
        }
      }/*}}}*/
      break;

      // - ERROR -
      default:

        exception_s::throw_exception(it,error_base + c_error_VALIDATOR_INVALID_PROPERTY,source_pos,prop_key);
        return false;
      }

      t_idx = props_tree->get_stack_next_idx(t_idx,&stack_ptr,stack);
    } while(t_idx != c_idx_not_exist);
  }

  return true;
}/*}}}*/

