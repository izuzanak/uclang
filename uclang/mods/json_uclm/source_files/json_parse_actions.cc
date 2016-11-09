
@begin
include "ucl_json.h"
include "json_parse_actions.h"
@end

/*
 * constants and definitions
 */

// - callers of parse action functions -
const unsigned c_json_parse_action_cnt = 24;
bool(*json_pa_callers[c_json_parse_action_cnt])(json_parser_s &_this) =
{/*{{{*/
  pa_json_null,
  pa_json_null,
  pa_json_null,
  pa_json_null,
  pa_json_null,
  pa_json_object_begin,
  pa_json_null,
  pa_json_null,
  pa_json_object_pair,
  pa_json_null,
  pa_json_null,
  pa_json_null,
  pa_json_array_begin,
  pa_json_array_value,
  pa_json_array_value,
  pa_json_val_string,
  pa_json_val_integer,
  pa_json_val_float,
  pa_json_val_object,
  pa_json_val_array,
  pa_json_val_true,
  pa_json_val_false,
  pa_json_val_null,
  pa_json_string,
};/*}}}*/

/*
 * parse action macros
 */

/*
 * functions implementing parse actions of json parser
 */

bool pa_json_null(json_parser_s &_this)
{/*{{{*/
  debug_assert(0);

  debug_message_6(fprintf(stderr,"json_parser: parse_action: pa_json_null\n"));

  return true;
}/*}}}*/

bool pa_json_object_begin(json_parser_s &_this)
{/*{{{*/
  interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);
  pointer_array_s &objects = _this.objects;

  // *****

  pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)cmalloc(sizeof(pointer_map_tree_s));
  tree_ptr->init();

  BIC_CREATE_NEW_LOCATION(new_location,c_rm_class_dict,tree_ptr);
  objects.push(new_location);

  debug_message_6(fprintf(stderr,"json_parser: parse_action: pa_json_object_begin\n"));

  return true;
}/*}}}*/

bool pa_json_object_pair(json_parser_s &_this)
{/*{{{*/
  interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);
  pointer_array_s &string_locations = _this.string_locations;
  ui_array_s &string_idxs = _this.string_idxs;
  pointer_array_s &values = _this.values;
  pointer_array_s &objects = _this.objects;

  // *****

  // - retrieve key and value location -
  location_s *key_location = (location_s *)string_locations[string_idxs.pop()];
  location_s *value_location = (location_s *)values.pop();

  // - retrieve object location -
  location_s *obj_location = (location_s *)objects.last();
  pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)obj_location->v_data_ptr;

  tree_ptr->it_ptr = &it;
  tree_ptr->source_pos = 0;

  // - search index of key location -
  pointer_map_s insert_map = {(pointer)key_location,NULL};
  unsigned index = tree_ptr->unique_insert(insert_map);
  cassert(((location_s *)it.exception_location)->v_type == c_bi_class_blank);

  pointer_map_s &map = tree_ptr->data[index].object;

  if (map.value)
  {
    // - release existing value -
    it.release_location_ptr((location_s *)map.value);
  }
  else
  {
    // - new key was inserted -
    key_location->v_reference_cnt.atomic_inc();
  }

  map.value = (pointer)value_location;

  debug_message_6(fprintf(stderr,"json_parser: parse_action: pa_json_object_pair\n"));

  return true;
}/*}}}*/

bool pa_json_array_begin(json_parser_s &_this)
{/*{{{*/
  interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);
  pointer_array_s &arrays = _this.arrays;

  // *****

  pointer_array_s *array_ptr = it.get_new_array_ptr();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  arrays.push(new_location);

  debug_message_6(fprintf(stderr,"json_parser: parse_action: pa_json_array_begin\n"));

  return true;
}/*}}}*/

bool pa_json_array_value(json_parser_s &_this)
{/*{{{*/
  pointer_array_s &values = _this.values;
  pointer_array_s &arrays = _this.arrays;

  // *****

  location_s *array_location = (location_s *)arrays.last();
  pointer_array_s *array_ptr = (pointer_array_s *)array_location->v_data_ptr;

  array_ptr->push(values.pop());

  debug_message_6(fprintf(stderr,"json_parser: parse_action: pa_json_array_value\n"));

  return true;
}/*}}}*/

bool pa_json_val_string(json_parser_s &_this)
{/*{{{*/
  pointer_array_s &string_locations = _this.string_locations;
  ui_array_s &string_idxs = _this.string_idxs;
  pointer_array_s &values = _this.values;

  // *****

  location_s *string_location = (location_s *)string_locations[string_idxs.pop()];

  // - insert string location to values -
  string_location->v_reference_cnt.atomic_inc();
  values.push(string_location);

  debug_message_6(fprintf(stderr,"json_parser: parse_action: pa_json_val_string\n"));

  return true;
}/*}}}*/

bool pa_json_val_integer(json_parser_s &_this)
{/*{{{*/
  interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);
  string_s &source_string = _this.source_string;
  lli_rb_tree_s &const_integers = _this.const_integers;
  pointer_array_s &integer_locations = _this.integer_locations;
  pointer_array_s &values = _this.values;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned int_num_end = lse.terminal_end - lse.terminal_start;
  char *int_num_data = source_string.data + lse.terminal_start;

  // - retrieve number from string -
  char tmp_char = int_num_data[int_num_end];
  int_num_data[int_num_end] = '\0';
  long long int const_int = strtoll(int_num_data,NULL,10);
  int_num_data[int_num_end] = tmp_char;

  // - get constant position in array -
  unsigned cd_idx = const_integers.unique_insert(const_int);

  if (cd_idx >= integer_locations.used)
  {
    // - skip rb_tree indexes gap -
    while (cd_idx > integer_locations.used)
    {
      integer_locations.push(NULL);
    }

    // - create new integer location -
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,const_int);
    integer_locations.push(new_location);
  }

  location_s *integer_location = (location_s *)integer_locations[cd_idx];

  // - insert integer location to values -
  integer_location->v_reference_cnt.atomic_inc();
  values.push(integer_location);

  debug_message_6(
    int_num_data[int_num_end] = '\0';
    fprintf(stderr,"json_parser: parse_action: pa_json_val_integer: %s\n",int_num_data);
    int_num_data[int_num_end] = tmp_char;
  );

  return true;
}/*}}}*/

bool pa_json_val_float(json_parser_s &_this)
{/*{{{*/
  interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);
  string_s &source_string = _this.source_string;
  bd_rb_tree_s &const_floats = _this.const_floats;
  pointer_array_s &float_locations = _this.float_locations;
  pointer_array_s &values = _this.values;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();
  unsigned float_num_end = lse.terminal_end - lse.terminal_start;
  char *float_num_data = source_string.data + lse.terminal_start;

  // - retrieve number from string -
  char tmp_char = float_num_data[float_num_end];
  float_num_data[float_num_end] = '\0';
  double const_float = strtod(float_num_data,NULL);
  float_num_data[float_num_end] = tmp_char;

  // - get constant position in array -
  unsigned cd_idx = const_floats.unique_insert(const_float);

  if (cd_idx >= float_locations.used)
  {
    // - skip rb_tree indexes gap -
    while (cd_idx > float_locations.used)
    {
      float_locations.push(NULL);
    }

    // - create new float location -
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_float,const_float);
    float_locations.push(new_location);
  }

  location_s *float_location = (location_s *)float_locations[cd_idx];

  // - insert float location to values -
  float_location->v_reference_cnt.atomic_inc();
  values.push(float_location);

  debug_message_6(
    float_num_data[float_num_end] = '\0';
    fprintf(stderr,"json_parser: parse_action: pa_json_val_float: %s\n",float_num_data);
    float_num_data[float_num_end] = tmp_char;
  );

  return true;
}/*}}}*/

bool pa_json_val_object(json_parser_s &_this)
{/*{{{*/
  pointer_array_s &values = _this.values;
  pointer_array_s &objects = _this.objects;

  // *****

  values.push(objects.pop());

  debug_message_6(fprintf(stderr,"json_parser: parse_action: pa_json_val_object\n"));

  return true;
}/*}}}*/

bool pa_json_val_array(json_parser_s &_this)
{/*{{{*/
  pointer_array_s &values = _this.values;
  pointer_array_s &arrays = _this.arrays;

  // *****

  values.push(arrays.pop());

  debug_message_6(fprintf(stderr,"json_parser: parse_action: pa_json_val_array\n"));

  return true;
}/*}}}*/

bool pa_json_val_true(json_parser_s &_this)
{/*{{{*/
  interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);
  pointer &true_location = _this.true_location;
  pointer_array_s &values = _this.values;

  // *****

  if (true_location == NULL)
  {
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,1);
    true_location = new_location;
  }

  ((location_s *)true_location)->v_reference_cnt.atomic_inc();
  values.push(true_location);

  debug_message_6(fprintf(stderr,"json_parser: parse_action: pa_json_val_true\n"));

  return true;
}/*}}}*/

bool pa_json_val_false(json_parser_s &_this)
{/*{{{*/
  interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);
  pointer &false_location = _this.false_location;
  pointer_array_s &values = _this.values;

  // *****

  if (false_location == NULL)
  {
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,0);
    false_location = new_location;
  }

  ((location_s *)false_location)->v_reference_cnt.atomic_inc();
  values.push(false_location);

  debug_message_6(fprintf(stderr,"json_parser: parse_action: pa_json_val_false\n"));

  return true;
}/*}}}*/

bool pa_json_val_null(json_parser_s &_this)
{/*{{{*/
  interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);
  pointer_array_s &values = _this.values;

  // *****

  ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();
  values.push(it.blank_location);

  debug_message_6(fprintf(stderr,"json_parser: parse_action: pa_json_val_null\n"));

  return true;
}/*}}}*/

bool pa_json_string(json_parser_s &_this)
{/*{{{*/
  interpreter_thread_s &it = *((interpreter_thread_s *)_this.it_ptr);
  string_s &source_string = _this.source_string;
  string_rb_tree_s &const_strings = _this.const_strings;
  pointer_array_s &string_locations = _this.string_locations;
  ui_array_s &string_idxs = _this.string_idxs;
  lalr_stack_s &lalr_stack = _this.lalr_stack;

  // *****

  lalr_stack_element_s &lse = lalr_stack.last();

  char *ptr = source_string.data + lse.terminal_start + 1;
  char *ptr_end = source_string.data + lse.terminal_end - 1;

  bc_array_s char_buffer;
  char_buffer.init_size((ptr_end - ptr) + 1);

  if (ptr < ptr_end)
  {
    do
    {
      if (*ptr == '\\')
      {
        ptr++;

        // - process character represented by unicode number -
        if (*ptr == 'u')
        {
          ptr++;

          unsigned value = 0;

          // - retrieve character value -
          char *ptr_end = ptr + 4;
          do {
            value <<= 4;

            if (*ptr >= '0' && *ptr <= '9')
            {
              value += *ptr - '0';
            }
            else if (*ptr >= 'a' && *ptr <= 'f')
            {
              value += 10 + (*ptr - 'a');
            }
            else if (*ptr >= 'A' && *ptr <= 'F')
            {
              value += 10 + (*ptr - 'A');
            }
            else
            {
              debug_assert(0);
            }

          } while(++ptr < ptr_end);

          // - convert utf16/32 value to utf8 character string -
          if (value <= 0x7f)
          {
            char_buffer.push(value);
          }
          else if (value <= 0x7ff)
          {
            char_buffer.push(0xc0 | value >> 6);
            char_buffer.push(0x80 | (value & 0x3f));
          }
          else if (value <= 0xffff)
          {
            char_buffer.push(0xe0 |   value >> 12);
            char_buffer.push(0x80 | ((value >>  6) & 0x3f));
            char_buffer.push(0x80 |  (value        & 0x3f));
          }
        }
        else
        {
          switch (*ptr++)
          {
          case 'b':
            char_buffer.push('\b');
            break;
          case 'f':
            char_buffer.push('\f');
            break;
          case 'n':
            char_buffer.push('\n');
            break;
          case 'r':
            char_buffer.push('\r');
            break;
          case 't':
            char_buffer.push('\t');
            break;
          case '\\':
            char_buffer.push('\\');
            break;
          case '"':
            char_buffer.push('"');
            break;
          default:
            debug_assert(0);
          }
        }
      }
      else
      {
        char_buffer.push(*ptr++);
      }
    }
    while(ptr < ptr_end);
  }

  // - modification of character buffer -
  char_buffer.data[char_buffer.used] = '\0';

  string_s const_str;
  const_str.size = char_buffer.used + 1;
  const_str.data = char_buffer.data;

  // - get constant position in array -
  unsigned cs_idx = const_strings.unique_swap_insert(const_str);
  const_str.clear();

  if (cs_idx >= string_locations.used)
  {
    // - skip rb_tree indexes gap -
    while (cs_idx > string_locations.used)
    {
      string_locations.push(NULL);
    }

    // - create location string copy -
    string_s *string_ptr = it.get_new_string_ptr();
    *string_ptr = const_strings[cs_idx];

    // - create new string location -
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
    string_locations.push(new_location);
  }

  // - store string index -
  string_idxs.push(cs_idx);

  debug_message_6(
    char *end_ptr = source_string.data + lse.terminal_end;
    char tmp_char = *end_ptr;
    *end_ptr = '\0';
    fprintf(stderr,"json_parser: parse_action: pa_json_string: %s\n",source_string.data + lse.terminal_start);
    *end_ptr = tmp_char;
  );

  return true;
}/*}}}*/

