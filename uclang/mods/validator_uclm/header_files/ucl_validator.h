
#ifndef __UCL_VALIDATOR_H
#define __UCL_VALIDATOR_H

@begin
include "script_parser.h"
@end

/*
 * basic definitions and constants
 */

extern unsigned c_rm_class_dict;

const unsigned c_prop_name_cnt = 18;
extern const char *c_prop_names[c_prop_name_cnt];

enum {
  prop_type = 0,
  prop_equal = 2,
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
  prop_regex,
  prop_items,
  prop_opt_items,
  prop_all_keys,
  prop_all_items,
};

// - VALIDATOR error identifiers -
enum
{
  c_error_VALIDATOR_DUMMY_ERROR = 0,
  c_error_VALIDATOR_EXPECTED_DICT_AS_PROPERTIERS,
  c_error_VALIDATOR_EXPECTED_STRING_AS_PROPERTY_ID,
  c_error_VALIDATOR_EXPECTED_TYPE_AS_TYPE_ID,
  c_error_VALIDATOR_EXPECTED_INTEGER_AS_LENGTH,
  c_error_VALIDATOR_INVALID_PROPERTY,
  c_error_VALIDATOR_INVALID_VALUE_TYPE,
  c_error_VALIDATOR_INVALID_VALUE_LENGTH,
  c_error_VALIDATOR_INVALID_VALUE,
};

/*
 * definition of class validator_c
 */

class validator_c
{
  public:
  static string_rb_tree_s c_prop_map;

  public:
  inline validator_c();
  inline ~validator_c();
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

  bool validate_pair(location_s *a_value,location_s *a_props);

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of class validator_c
 */

inline validator_c::validator_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"validator_init()\n"););

  c_prop_map.init();

  const char **pn_ptr = c_prop_names;
  const char **pn_ptr_end = pn_ptr + c_prop_name_cnt;
  do {
    c_prop_map.get_idx_char_ptr_insert(strlen(*pn_ptr),*pn_ptr);
  } while(++pn_ptr < pn_ptr_end);
}/*}}}*/

inline validator_c::~validator_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"validator_exit()\n"););

  c_prop_map.clear();
}/*}}}*/

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

  init();
}/*}}}*/

#endif

