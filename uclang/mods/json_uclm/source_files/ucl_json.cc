
@begin
include "ucl_json.h"
include "json_parse_actions.h"
@end

/*
 * constants and definitions
 */

const unsigned json_rule_head_idxs[c_json_rule_cnt] = {17, 18, 19, 20, 20, 21, 22, 22, 23, 24, 25, 25, 26, 27, 27, 28, 28, 28, 28, 28, 28, 28, 28, 29, };
const unsigned json_rule_body_lengths[c_json_rule_cnt] = {1, 2, 2, 1, 2, 1, 3, 1, 3, 2, 1, 2, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };

const unsigned json_lalr_table[json_lalr_state_cnt*c_json_terminal_plus_nonterminal_cnt] =
{/*{{{*/
   JSON_SHIFT(11),    JSON_SHIFT(4),    JSON_SHIFT(5),    JSON_SHIFT(8),    JSON_SHIFT(9),   JSON_SHIFT(10),   JSON_SHIFT(16),       json_blank,   JSON_SHIFT(17),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,     JSON_GOTO(1),     JSON_GOTO(6),    JSON_GOTO(12),    JSON_GOTO(14),       json_blank,       json_blank,     JSON_GOTO(7),    JSON_GOTO(13),    JSON_GOTO(15),       json_blank,     JSON_GOTO(2),     JSON_GOTO(3),
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,   JSON_SHIFT(18),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,  JSON_REDUCE(15),       json_blank,  JSON_REDUCE(15),  JSON_REDUCE(15),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,  JSON_REDUCE(15),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,  JSON_REDUCE(16),       json_blank,  JSON_REDUCE(16),  JSON_REDUCE(16),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,  JSON_REDUCE(16),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,  JSON_REDUCE(17),       json_blank,  JSON_REDUCE(17),  JSON_REDUCE(17),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,  JSON_REDUCE(17),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,  JSON_REDUCE(18),       json_blank,  JSON_REDUCE(18),  JSON_REDUCE(18),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,  JSON_REDUCE(18),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,  JSON_REDUCE(19),       json_blank,  JSON_REDUCE(19),  JSON_REDUCE(19),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,  JSON_REDUCE(19),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,  JSON_REDUCE(20),       json_blank,  JSON_REDUCE(20),  JSON_REDUCE(20),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,  JSON_REDUCE(20),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,  JSON_REDUCE(21),       json_blank,  JSON_REDUCE(21),  JSON_REDUCE(21),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,  JSON_REDUCE(21),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,  JSON_REDUCE(22),       json_blank,  JSON_REDUCE(22),  JSON_REDUCE(22),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,  JSON_REDUCE(22),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,  JSON_REDUCE(23),       json_blank,  JSON_REDUCE(23),  JSON_REDUCE(23),  JSON_REDUCE(23),       json_blank,       json_blank,       json_blank,       json_blank,  JSON_REDUCE(23),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,   JSON_SHIFT(19),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,   JSON_SHIFT(20),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
   JSON_SHIFT(11),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,   JSON_REDUCE(3),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,    JSON_GOTO(21),    JSON_GOTO(22),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,    JSON_GOTO(23),
   JSON_SHIFT(11),    JSON_SHIFT(4),    JSON_SHIFT(5),    JSON_SHIFT(8),    JSON_SHIFT(9),   JSON_SHIFT(10),   JSON_SHIFT(16),       json_blank,   JSON_SHIFT(17),  JSON_REDUCE(10),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,     JSON_GOTO(6),    JSON_GOTO(12),    JSON_GOTO(14),       json_blank,       json_blank,     JSON_GOTO(7),    JSON_GOTO(13),    JSON_GOTO(15),    JSON_GOTO(24),    JSON_GOTO(25),     JSON_GOTO(3),
   JSON_REDUCE(5),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,   JSON_REDUCE(5),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
  JSON_REDUCE(12),  JSON_REDUCE(12),  JSON_REDUCE(12),  JSON_REDUCE(12),  JSON_REDUCE(12),  JSON_REDUCE(12),  JSON_REDUCE(12),       json_blank,  JSON_REDUCE(12),  JSON_REDUCE(12),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,   JSON_REDUCE(2),       json_blank,   JSON_REDUCE(2),   JSON_REDUCE(2),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,   JSON_REDUCE(2),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,   JSON_REDUCE(9),       json_blank,   JSON_REDUCE(9),   JSON_REDUCE(9),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,   JSON_REDUCE(9),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,   JSON_REDUCE(4),       json_blank,       json_blank,   JSON_SHIFT(26),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,   JSON_REDUCE(7),       json_blank,       json_blank,   JSON_REDUCE(7),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,   JSON_SHIFT(27),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,  JSON_REDUCE(11),   JSON_SHIFT(28),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,  JSON_REDUCE(14),  JSON_REDUCE(14),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
   JSON_SHIFT(11),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,    JSON_GOTO(29),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,    JSON_GOTO(23),
   JSON_SHIFT(11),    JSON_SHIFT(4),    JSON_SHIFT(5),    JSON_SHIFT(8),    JSON_SHIFT(9),   JSON_SHIFT(10),   JSON_SHIFT(16),       json_blank,   JSON_SHIFT(17),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,     JSON_GOTO(6),    JSON_GOTO(12),    JSON_GOTO(14),       json_blank,       json_blank,     JSON_GOTO(7),    JSON_GOTO(13),    JSON_GOTO(15),       json_blank,    JSON_GOTO(30),     JSON_GOTO(3),
   JSON_SHIFT(11),    JSON_SHIFT(4),    JSON_SHIFT(5),    JSON_SHIFT(8),    JSON_SHIFT(9),   JSON_SHIFT(10),   JSON_SHIFT(16),       json_blank,   JSON_SHIFT(17),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,     JSON_GOTO(6),    JSON_GOTO(12),    JSON_GOTO(14),       json_blank,       json_blank,     JSON_GOTO(7),    JSON_GOTO(13),    JSON_GOTO(15),       json_blank,    JSON_GOTO(31),     JSON_GOTO(3),
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,   JSON_REDUCE(6),       json_blank,       json_blank,   JSON_REDUCE(6),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,   JSON_REDUCE(8),       json_blank,       json_blank,   JSON_REDUCE(8),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,  JSON_REDUCE(13),  JSON_REDUCE(13),       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,       json_blank,
};/*}}}*/

/*
 * methods of structure json_creator_s
 */

void json_creator_s::append_string(string_s &a_string,bc_array_s &a_buffer)
{/*{{{*/
  if (a_string.size > 1)
  {
    char *ptr = a_string.data;
    char *ptr_end = ptr + a_string.size - 1;
    do {

      switch (*ptr)
      {
        case '\b':
          a_buffer.push('\\');
          a_buffer.push('b');
          break;
        case '\f':
          a_buffer.push('\\');
          a_buffer.push('f');
          break;
        case '\n':
          a_buffer.push('\\');
          a_buffer.push('n');
          break;
        case '\r':
          a_buffer.push('\\');
          a_buffer.push('r');
          break;
        case '\t':
          a_buffer.push('\\');
          a_buffer.push('t');
          break;
        case '\\':
          a_buffer.push('\\');
          a_buffer.push('\\');
          break;
        case '"':
          a_buffer.push('\\');
          a_buffer.push('"');
          break;
        default:
          a_buffer.push(*ptr);
      }

    } while(++ptr < ptr_end);
  }
}/*}}}*/

unsigned json_creator_s::create_nice(interpreter_thread_s &it,location_s *a_location,string_s &a_tabulator,string_s &a_indent,bc_array_s &a_buffer)
{/*{{{*/

#define JSON_CREATE_NICE_CLEAR() \
{/*{{{*/\
  create_stack.clear();\
  indent_buffer.clear();\
}/*}}}*/

#define JSON_CREATE_NICE_PUSH_TAB() \
{/*{{{*/\
  if ((indent_size += a_tabulator.size - 1) > indent_buffer.used)\
  {\
    indent_buffer.append(a_tabulator.size - 1,a_tabulator.data);\
  }\
}/*}}}*/

#define JSON_CREATE_NICE_POP_TAB() \
{/*{{{*/\
  indent_size -= a_tabulator.size - 1;\
}/*}}}*/

#define JSON_CREATE_NICE_INDENT() \
{/*{{{*/\
  a_buffer.push('\n');\
  a_buffer.append(indent_size,indent_buffer.data);\
}/*}}}*/

  // - initialize indent buffer -
  bc_array_s indent_buffer;
  indent_buffer.init();

  indent_buffer.append(a_indent.size - 1,a_indent.data);

  // - initialize actual indent size -
  unsigned indent_size = indent_buffer.used;

  // - initialize create stack -
  create_stack_s create_stack;
  create_stack.init();

  // - insert source location to create stack -
  create_stack.push_blank();
  create_stack.last().set(a_location,true,c_idx_not_exist);

  do {

    // - reference to last stack element -
    cs_element_s &cs_elm = create_stack.last();

    // - retrieve location pointer -
    location_s *location_ptr = (location_s *)cs_elm.location_ptr;

    // - process dictionary -
    if (location_ptr->v_type == c_rm_class_dict)
    {/*{{{*/
      pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)location_ptr->v_data_ptr;

      if (cs_elm.index == c_idx_not_exist)
      {
        cs_elm.index = 0;
      }

      if (cs_elm.index < tree_ptr->used)
      {
        pointer_map_tree_s_node &node = tree_ptr->data[cs_elm.index++];

        if (node.valid)
        {
          if (cs_elm.initialize)
          {
            a_buffer.push('{');

            // - push tabulator to indent -
            JSON_CREATE_NICE_PUSH_TAB();

            // - insert indentation -
            JSON_CREATE_NICE_INDENT();
          }
          else
          {
            a_buffer.push(',');

            // - insert indentation -
            JSON_CREATE_NICE_INDENT();
          }

          cs_elm.initialize = false;

          location_s *key_location = (location_s *)node.object.key;
          location_s *item_location = it.get_location_value(node.object.value);

          // - ERROR -
          if (key_location->v_type != c_bi_class_string)
          {
            JSON_CREATE_NICE_CLEAR();

            return c_error_JSON_CREATE_NO_STRING_DICT_KEY;
          }

          // - retrieve key string -
          string_s *string_ptr = (string_s *)key_location->v_data_ptr;

          a_buffer.push('"');
          json_creator_s::append_string(*string_ptr,a_buffer);
          a_buffer.push('"');
          a_buffer.push(':');
          a_buffer.push(' ');

          // - insert value object to create stack -
          create_stack.push_blank();
          create_stack.last().set(item_location,true,c_idx_not_exist);
        }
      }
      else
      {
        if (cs_elm.initialize)
        {
          a_buffer.push('{');
        }
        else
        {
          // - remove tabulator from indent -
          JSON_CREATE_NICE_POP_TAB();

          // - insert indentation -
          JSON_CREATE_NICE_INDENT();
        }

        a_buffer.push('}');

        create_stack.pop();
      }
    }/*}}}*/
    else
    {
      switch (location_ptr->v_type)
      {
      case c_bi_class_blank:
        {/*{{{*/
          a_buffer.append(strlen("null"),"null");
          create_stack.pop();
        }/*}}}*/
        break;

      case c_bi_class_integer:
        {/*{{{*/
          long long int value = (long long int)location_ptr->v_data_ptr;

          a_buffer.reserve(max_number_string_length);
          a_buffer.used += snprintf(a_buffer.data + a_buffer.used,max_number_string_length,"%" HOST_LL_FORMAT "d",value);

          create_stack.pop();
        }/*}}}*/
        break;

      case c_bi_class_float:
        {/*{{{*/
          double value = (double)location_ptr->v_data_ptr;

          a_buffer.reserve(max_number_string_length);
          a_buffer.used += snprintf(a_buffer.data + a_buffer.used,max_number_string_length,"%f",value);

          create_stack.pop();
        }/*}}}*/
        break;

      case c_bi_class_string:
        {/*{{{*/
          string_s *string_ptr = (string_s *)location_ptr->v_data_ptr;

          a_buffer.push('"');
          json_creator_s::append_string(*string_ptr,a_buffer);
          a_buffer.push('"');

          create_stack.pop();
        }/*}}}*/
        break;

      case c_bi_class_array:
        {/*{{{*/
          pointer_array_s *array_ptr = (pointer_array_s *)location_ptr->v_data_ptr;

          if (cs_elm.initialize)
          {
            a_buffer.push('[');

            // - if array is not empty -
            if (array_ptr->used != 0)
            {
              // - push tabulator to indent -
              JSON_CREATE_NICE_PUSH_TAB();

              // - insert indentation -
              JSON_CREATE_NICE_INDENT();
            }

            cs_elm.index = 0;
            cs_elm.initialize = false;
          }
          else
          {
            if (cs_elm.index < array_ptr->used)
            {
              a_buffer.push(',');

              // - insert indentation -
              JSON_CREATE_NICE_INDENT();
            }
          }

          if (cs_elm.index < array_ptr->used)
          {
            location_s *item_location = it.get_location_value(array_ptr->data[cs_elm.index++]);

            // - insert value object to create stack -
            create_stack.push_blank();
            create_stack.last().set(item_location,true,c_idx_not_exist);
          }
          else
          {
            // - if array is not empty -
            if (array_ptr->used != 0)
            {
              // - remove tabulator from indent -
              JSON_CREATE_NICE_POP_TAB();

              // - insert indentation -
              JSON_CREATE_NICE_INDENT();
            }

            a_buffer.push(']');

            create_stack.pop();
          }
        }/*}}}*/
        break;

      // - ERROR -
      default:
        JSON_CREATE_NICE_CLEAR();

        return c_error_JSON_CREATE_UNSUPPORTED_CLASS;
      }
    }
  } while(create_stack.used > 0);

  // - release create stack -
  create_stack.clear();

  // - release indent buffer -
  indent_buffer.clear();

  // - push terminating character to buffer -
  a_buffer.push('\0');

  return c_idx_not_exist;
}/*}}}*/

/*
 * methods of generated structures
 */

// -- cs_element_s --
@begin
methods cs_element_s
@end

// -- create_stack_s --
@begin
methods create_stack_s
@end

// -- json_parser_s --
@begin
methods json_parser_s
@end

unsigned json_parser_s::recognize_terminal(unsigned &a_input_idx) // lgtm [cpp/use-of-goto]
{/*{{{*/
  unsigned source_string_length = source_string.size - 1;

#define JSON_GET_NEXT_CHAR() \
  {\
    if (a_input_idx < source_string_length) {\
      in_char = (unsigned char)source_string[a_input_idx];\
    }\
    else {\
      in_char = '\0';\
    }\
  }

#define JSON_CLOSE_CHAR(RET_TERM_IDX) \
  {\
    if (in_char == '\0') {\
      return RET_TERM_IDX;\
    }\
\
    a_input_idx++;\
  }

   unsigned char in_char;

// - STATE 0 -
   JSON_GET_NEXT_CHAR();

   if (in_char == 0) {
      goto state_1_label;
   }
   if (in_char >= 8 && in_char < 14) {
      goto state_17_label;
   }
   if (in_char == 32) {
      goto state_17_label;
   }
   if (in_char == 34) {
      goto state_2_label;
   }
   if (in_char == 35) {
      goto state_3_label;
   }
   if (in_char == 44) {
      goto state_4_label;
   }
   if (in_char == 45) {
      goto state_5_label;
   }
   if (in_char == 47) {
      goto state_6_label;
   }
   if (in_char == 48) {
      goto state_7_label;
   }
   if (in_char >= 49 && in_char < 58) {
      goto state_8_label;
   }
   if (in_char == 58) {
      goto state_9_label;
   }
   if (in_char == 91) {
      goto state_10_label;
   }
   if (in_char == 93) {
      goto state_11_label;
   }
   if (in_char == 102) {
      goto state_12_label;
   }
   if (in_char == 110) {
      goto state_13_label;
   }
   if (in_char == 116) {
      goto state_14_label;
   }
   if (in_char == 123) {
      goto state_15_label;
   }
   if (in_char == 125) {
      goto state_16_label;
   }
   return c_idx_not_exist;

// - STATE 1 -
state_1_label:
   JSON_CLOSE_CHAR(16);
   return 16;

// - STATE 2 -
state_2_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char < 34) {
      goto state_2_label;
   }
   if (in_char == 34) {
      goto state_18_label;
   }
   if (in_char < 92) {
      goto state_2_label;
   }
   if (in_char == 92) {
      goto state_19_label;
   }
   goto state_2_label;

// - STATE 3 -
state_3_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char < 10) {
      goto state_3_label;
   }
   if (in_char == 10) {
      goto state_20_label;
   }
   goto state_3_label;

// - STATE 4 -
state_4_label:
   JSON_CLOSE_CHAR(10);
   return 10;

// - STATE 5 -
state_5_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char == 48) {
      goto state_7_label;
   }
   if (in_char >= 49 && in_char < 58) {
      goto state_8_label;
   }
   return c_idx_not_exist;

// - STATE 6 -
state_6_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char == 42) {
      goto state_21_label;
   }
   if (in_char == 47) {
      goto state_22_label;
   }
   return c_idx_not_exist;

// - STATE 7 -
state_7_label:
   JSON_CLOSE_CHAR(1);
   JSON_GET_NEXT_CHAR();

   if (in_char == 46) {
      goto state_23_label;
   }
   if (in_char == 69) {
      goto state_24_label;
   }
   if (in_char == 101) {
      goto state_24_label;
   }
   return 1;

// - STATE 8 -
state_8_label:
   JSON_CLOSE_CHAR(1);
   JSON_GET_NEXT_CHAR();

   if (in_char == 46) {
      goto state_23_label;
   }
   if (in_char >= 48 && in_char < 58) {
      goto state_8_label;
   }
   if (in_char == 69) {
      goto state_24_label;
   }
   if (in_char == 101) {
      goto state_24_label;
   }
   return 1;

// - STATE 9 -
state_9_label:
   JSON_CLOSE_CHAR(11);
   return 11;

// - STATE 10 -
state_10_label:
   JSON_CLOSE_CHAR(8);
   return 8;

// - STATE 11 -
state_11_label:
   JSON_CLOSE_CHAR(9);
   return 9;

// - STATE 12 -
state_12_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char == 97) {
      goto state_25_label;
   }
   return c_idx_not_exist;

// - STATE 13 -
state_13_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char == 117) {
      goto state_26_label;
   }
   return c_idx_not_exist;

// - STATE 14 -
state_14_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char == 114) {
      goto state_27_label;
   }
   return c_idx_not_exist;

// - STATE 15 -
state_15_label:
   JSON_CLOSE_CHAR(6);
   return 6;

// - STATE 16 -
state_16_label:
   JSON_CLOSE_CHAR(7);
   return 7;

// - STATE 17 -
state_17_label:
   JSON_CLOSE_CHAR(12);
   JSON_GET_NEXT_CHAR();

   if (in_char >= 8 && in_char < 14) {
      goto state_17_label;
   }
   if (in_char == 32) {
      goto state_17_label;
   }
   return 12;

// - STATE 18 -
state_18_label:
   JSON_CLOSE_CHAR(0);
   return 0;

// - STATE 19 -
state_19_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char == 34) {
      goto state_2_label;
   }
   if (in_char == 47) {
      goto state_2_label;
   }
   if (in_char == 92) {
      goto state_2_label;
   }
   if (in_char == 98) {
      goto state_2_label;
   }
   if (in_char == 102) {
      goto state_2_label;
   }
   if (in_char == 110) {
      goto state_2_label;
   }
   if (in_char == 114) {
      goto state_2_label;
   }
   if (in_char == 116) {
      goto state_2_label;
   }
   if (in_char == 117) {
      goto state_28_label;
   }
   return c_idx_not_exist;

// - STATE 20 -
state_20_label:
   JSON_CLOSE_CHAR(13);
   return 13;

// - STATE 21 -
state_21_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char < 42) {
      goto state_21_label;
   }
   if (in_char == 42) {
      goto state_29_label;
   }
   goto state_21_label;

// - STATE 22 -
state_22_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char < 10) {
      goto state_22_label;
   }
   if (in_char == 10) {
      goto state_30_label;
   }
   goto state_22_label;

// - STATE 23 -
state_23_label:
   JSON_CLOSE_CHAR(2);
   JSON_GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_23_label;
   }
   if (in_char == 69) {
      goto state_24_label;
   }
   if (in_char == 101) {
      goto state_24_label;
   }
   return 2;

// - STATE 24 -
state_24_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char == 43) {
      goto state_31_label;
   }
   if (in_char == 45) {
      goto state_31_label;
   }
   if (in_char >= 48 && in_char < 58) {
      goto state_32_label;
   }
   return c_idx_not_exist;

// - STATE 25 -
state_25_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char == 108) {
      goto state_33_label;
   }
   return c_idx_not_exist;

// - STATE 26 -
state_26_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char == 108) {
      goto state_34_label;
   }
   return c_idx_not_exist;

// - STATE 27 -
state_27_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char == 117) {
      goto state_35_label;
   }
   return c_idx_not_exist;

// - STATE 28 -
state_28_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_36_label;
   }
   if (in_char >= 65 && in_char < 71) {
      goto state_36_label;
   }
   if (in_char >= 97 && in_char < 103) {
      goto state_36_label;
   }
   return c_idx_not_exist;

// - STATE 29 -
state_29_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char < 47) {
      goto state_21_label;
   }
   if (in_char == 47) {
      goto state_37_label;
   }
   goto state_21_label;

// - STATE 30 -
state_30_label:
   JSON_CLOSE_CHAR(14);
   return 14;

// - STATE 31 -
state_31_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_32_label;
   }
   return c_idx_not_exist;

// - STATE 32 -
state_32_label:
   JSON_CLOSE_CHAR(2);
   JSON_GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_32_label;
   }
   return 2;

// - STATE 33 -
state_33_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char == 115) {
      goto state_38_label;
   }
   return c_idx_not_exist;

// - STATE 34 -
state_34_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char == 108) {
      goto state_39_label;
   }
   return c_idx_not_exist;

// - STATE 35 -
state_35_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char == 101) {
      goto state_40_label;
   }
   return c_idx_not_exist;

// - STATE 36 -
state_36_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_41_label;
   }
   if (in_char >= 65 && in_char < 71) {
      goto state_41_label;
   }
   if (in_char >= 97 && in_char < 103) {
      goto state_41_label;
   }
   return c_idx_not_exist;

// - STATE 37 -
state_37_label:
   JSON_CLOSE_CHAR(15);
   return 15;

// - STATE 38 -
state_38_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char == 101) {
      goto state_42_label;
   }
   return c_idx_not_exist;

// - STATE 39 -
state_39_label:
   JSON_CLOSE_CHAR(5);
   return 5;

// - STATE 40 -
state_40_label:
   JSON_CLOSE_CHAR(3);
   return 3;

// - STATE 41 -
state_41_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_43_label;
   }
   if (in_char >= 65 && in_char < 71) {
      goto state_43_label;
   }
   if (in_char >= 97 && in_char < 103) {
      goto state_43_label;
   }
   return c_idx_not_exist;

// - STATE 42 -
state_42_label:
   JSON_CLOSE_CHAR(4);
   return 4;

// - STATE 43 -
state_43_label:
   JSON_CLOSE_CHAR(c_idx_not_exist);
   JSON_GET_NEXT_CHAR();

   if (in_char >= 48 && in_char < 58) {
      goto state_2_label;
   }
   if (in_char >= 65 && in_char < 71) {
      goto state_2_label;
   }
   if (in_char >= 97 && in_char < 103) {
      goto state_2_label;
   }
   return c_idx_not_exist;

}/*}}}*/

bool json_parser_s::parse_source(interpreter_thread_s &a_it,string_s &a_string)
{/*{{{*/
  it_ptr = &a_it;
  source_string.swap(a_string);

  old_input_idx = 0;

  true_location = nullptr;
  false_location = nullptr;

  lalr_stack.clear();
  lalr_stack.push(0);

  unsigned input_idx = 0;
  unsigned ret_term = c_idx_not_exist;

#define JSON_PARSE_SOURCE_RETURN() \
  source_string.swap(a_string);

  do
  {
    // - retrieve next terminal symbol -
    while (ret_term == c_idx_not_exist)
    {
      old_input_idx = input_idx;

      ret_term = recognize_terminal(input_idx);
      debug_message_6(fprintf(stderr,"json_parser: recognized terminal: %u\n",ret_term));

      // - PARSE ERROR unrecognized terminal -
      if (ret_term == c_idx_not_exist)
      {
        JSON_PARSE_SOURCE_RETURN();
        return false;
      }

      // - skipping of _SKIP_ terminals -
      if (ret_term >= 12 && ret_term <= 15)
      {
        ret_term = c_idx_not_exist;
      }
    }

    // - retrieve action from table of actions -
    unsigned parse_action = json_lalr_table[lalr_stack.last().lalr_state*c_json_terminal_plus_nonterminal_cnt + ret_term];

    // - PARSE ERROR wrong syntax -
    if (parse_action == c_idx_not_exist)
    {
      JSON_PARSE_SOURCE_RETURN();
      return false;
    }

    // - action JSON_SHIFT -
    if (parse_action < c_json_lalr_table_reduce_base)
    {
      if (ret_term == 16)
      {
        break;
      }

      // - insertion of state, and terminal position in source string -
      lalr_stack.push(parse_action,old_input_idx,input_idx);
      ret_term = c_idx_not_exist;
    }

    // - action JSON_REDUCE-
    else
    {
      parse_action -= c_json_lalr_table_reduce_base;

      // - call function assigned to reduction -
      if (json_pa_callers[parse_action] != pa_json_null)
      {
        if (!json_pa_callers[parse_action](*this))
        {
          JSON_PARSE_SOURCE_RETURN();
          return false;
        }
      }

      // - remove rule body from lalr_stack -
      lalr_stack.used -= json_rule_body_lengths[parse_action];

      // - insert new automat state to stack -
      unsigned goto_val = json_lalr_table[lalr_stack.last().lalr_state*c_json_terminal_plus_nonterminal_cnt + json_rule_head_idxs[parse_action]];
      lalr_stack.push(goto_val);
    }

  }
  while(true);

  JSON_PARSE_SOURCE_RETURN();
  return true;
}/*}}}*/

void json_parser_s::release_locations()
{/*{{{*/
  interpreter_thread_s &it = *((interpreter_thread_s *)it_ptr);

  // - release true location -
  if (true_location != nullptr)
  {
    it.release_location_ptr((location_s *)true_location);
  }

  // - release false location -
  if (false_location != nullptr)
  {
    it.release_location_ptr((location_s *)false_location);
  }

  // - release integer locations -
  if (integer_locations.used != 0)
  {
    pointer *il_ptr = integer_locations.data;
    pointer *il_ptr_end = il_ptr + integer_locations.used;
    do {
      if (*il_ptr != nullptr)
      {
        it.release_location_ptr((location_s *)*il_ptr);
      }
    } while(++il_ptr < il_ptr_end);
  }

  // - release float locations -
  if (float_locations.used != 0)
  {
    pointer *fl_ptr = float_locations.data;
    pointer *fl_ptr_end = fl_ptr + float_locations.used;
    do {
      if (*fl_ptr != nullptr)
      {
        it.release_location_ptr((location_s *)*fl_ptr);
      }
    } while(++fl_ptr < fl_ptr_end);
  }

  // - release string locations -
  if (string_locations.used != 0)
  {
    pointer *sl_ptr = string_locations.data;
    pointer *sl_ptr_end = sl_ptr + string_locations.used;
    do {
      if (*sl_ptr != nullptr)
      {
        it.release_location_ptr((location_s *)*sl_ptr);
      }
    } while(++sl_ptr < sl_ptr_end);
  }

  // - release values -
  if (values.used != 0)
  {
    pointer *v_ptr = values.data;
    pointer *v_ptr_end = v_ptr + values.used;
    do {
      it.release_location_ptr((location_s *)*v_ptr);
    } while(++v_ptr < v_ptr_end);
  }

  // - release arrays -
  if (arrays.used != 0)
  {
    pointer *a_ptr = arrays.data;
    pointer *a_ptr_end = a_ptr + arrays.used;
    do {
      it.release_location_ptr((location_s *)*a_ptr);
    } while(++a_ptr < a_ptr_end);
  }

  // - release objects -
  if (objects.used != 0)
  {
    pointer *o_ptr = objects.data;
    pointer *o_ptr_end = o_ptr + objects.used;
    do {
      it.release_location_ptr((location_s *)*o_ptr);
    } while(++o_ptr < o_ptr_end);
  }
}/*}}}*/

/*
 * global function
 */

