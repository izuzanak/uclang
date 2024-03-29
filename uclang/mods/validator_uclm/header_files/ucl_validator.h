
#ifndef __UCL_VALIDATOR_H
#define __UCL_VALIDATOR_H

@begin
include "script_parser.h"
@end

#include <regex.h>

/*
 * basic definitions and constants
 */

extern unsigned c_rm_class_set;
extern unsigned c_rm_class_dict;

enum {
  prop_type = 0,
  prop_equal,
  prop_not_equal,
  prop_lesser,
  prop_greater,
  prop_lesser_equal,
  prop_greater_equal,
  prop_length_equal,
  prop_length_not_equal,
  prop_length_lesser,
  prop_length_greater,
  prop_length_lesser_equal,
  prop_length_greater_equal,
  prop_reference,
  prop_reference_if,
  prop_reference_type,
  prop_regex,
  prop_test,
  prop_items,
  prop_opt_items,
  prop_all_items,
  prop_all_keys,
  prop_in,
};

// - VALIDATOR error identifiers -
enum
{
  c_error_VALIDATOR_ENTRY_NOT_FOUND = 0,
  c_error_VALIDATOR_WRONG_PROPERTIES_ARRAY_SIZE,
  c_error_VALIDATOR_INVALID_PROPERTY_ID,
  c_error_VALIDATOR_INVALID_PROPERTY_TYPE,
  c_error_VALIDATOR_INVALID_PROPERTY_VALUE,
  c_error_VALIDATOR_INVALID_PROPERTY_REGULAR_EXPRESSION,
  c_error_VALIDATOR_INVALID_PROPERTY_DELEGATE,
  c_error_VALIDATOR_INVALID_PROPERTY_DELEGATE_RETURN_VALUE,
  c_error_VALIDATOR_INVALID_VALUE_TYPE,
  c_error_VALIDATOR_INVALID_VALUE_LENGTH,
  c_error_VALIDATOR_INVALID_VALUE,
};

/*
 * definition of structure validator_s
 */

struct validator_s
{
  interpreter_thread_s *it_ptr;
  unsigned source_pos;
  unsigned error_base;

  location_s *schema;
  location_s *value_stack;
  location_s *props_stack;

  string_rb_tree_s regex_map;
  pointer_array_s regex_list;

  static unsigned recognize_property(const char *a_string,unsigned &a_input_idx);
  bool validate_pair(location_s *a_value,location_s *a_props);

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure validator_s
 */

inline void validator_s::init()
{/*{{{*/
  it_ptr = nullptr;
  source_pos = 0;
  error_base = 0;

  schema = nullptr;
  value_stack = nullptr;
  props_stack = nullptr;

  regex_map.init();
  regex_list.init();
}/*}}}*/

inline void validator_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (schema != nullptr)
  {
    it.release_location_ptr(schema);
  }

  if (value_stack != nullptr)
  {
    it.release_location_ptr(value_stack);
  }

  if (props_stack != nullptr)
  {
    it.release_location_ptr(props_stack);
  }

  regex_map.clear();

  // - release regular expressions -
  if (regex_list.used != 0)
  {
    pointer *r_ptr = regex_list.data;
    pointer *r_ptr_end = r_ptr + regex_list.used;
    do {

      // - if regular expression exist -
      if (*r_ptr != nullptr)
      {
        regfree((regex_t *)*r_ptr);
        cfree(*r_ptr);
      }
    } while(++r_ptr < r_ptr_end);
  }

  regex_list.clear();

  init();
}/*}}}*/

#endif

