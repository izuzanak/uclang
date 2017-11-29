
@begin
include "json_module.h"
@end

// - JSON indexes of built in classes -
unsigned c_bi_class_json = c_idx_not_exist;

// - JSON indexes of remote classes -
unsigned c_rm_class_dict = c_idx_not_exist;

// - JSON module -
built_in_module_s module =
{/*{{{*/
  1,                    // Class count
  json_classes,         // Classes

  0,                    // Error base index
  3,                    // Error count
  json_error_strings,   // Error strings

  json_initialize,      // Initialize function
  json_print_exception, // Print exceptions function
};/*}}}*/

// - JSON classes -
built_in_class_s *json_classes[] =
{/*{{{*/
  &json_class,
};/*}}}*/

// - JSON error strings -
const char *json_error_strings[] =
{/*{{{*/
  "error_JSON_CREATE_UNSUPPORTED_CLASS",
  "error_JSON_CREATE_NO_STRING_DICT_KEY",
  "error_JSON_PARSE_ERROR",
};/*}}}*/

// - JSON initialize -
bool json_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize json class identifier -
  c_bi_class_json = class_base_idx++;

  // - retrieve remote dict class index -
  c_rm_class_dict = sp.resolve_class_idx_by_name("Dict",c_idx_not_exist);

  // - ERROR -
  if (c_rm_class_dict == c_idx_not_exist)
  {
    sp.error_code.push(ei_module_cannot_find_remote_class);
    sp.error_code.push(sp.module_names_positions[sp.module_idx].ui_first);
    sp.error_code.push(sp.module_idx);

    return false;
  }

  return true;
}/*}}}*/

// - JSON print exception -
bool json_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_JSON_CREATE_UNSUPPORTED_CLASS:
  {
    class_record_s &class_record = it.class_records[exception.params[0]];

    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nJSON create, unsupported class ");
    print_class_sequence(it.class_symbol_names,it.class_records,class_stack,class_record.parent_record);
    fprintf(stderr,"%s\n",it.class_symbol_names[class_record.name_idx].data);
    fprintf(stderr," ---------------------------------------- \n");
  }
  break;
  case c_error_JSON_CREATE_NO_STRING_DICT_KEY:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nJSON create, dictionary key must be string value\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_JSON_PARSE_ERROR:
  {
    string_s &json_source = *((string_s *)((location_s *)exception.obj_location)->v_data_ptr);

    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while parsing JSON source string on line: %u\n",json_source.get_character_line(exception.params[0]));
    print_error_line(json_source,exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  }
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class JSON -
built_in_class_s json_class =
{/*{{{*/
  "Json",
  c_modifier_public | c_modifier_final,
  5, json_methods,
  0, json_variables,
  bic_json_consts,
  bic_json_init,
  bic_json_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s json_methods[] =
{/*{{{*/
  {
    "create#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_json_method_create_1
  },
  {
    "create_nice#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_json_method_create_nice_2
  },
  {
    "parse#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_json_method_parse_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_json_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_json_method_print_0
  },
};/*}}}*/

built_in_variable_s json_variables[] =
{/*{{{*/
};/*}}}*/

void bic_json_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_json_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_json_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_json_method_create_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_rm_class_dict)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_json,"create#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - initialize character buffer -
  bc_array_s buffer;
  buffer.init();

  // - initialize create stack -
  create_stack_s create_stack;
  create_stack.init();

  // - insert source location to create stack -
  create_stack.push_blank();
  create_stack.last().set(src_0_location,true,c_idx_not_exist);

  do {

    // - reference to last stack element -
    cs_element_s &cs_elm = create_stack.last();

    // - retrieve location pointer -
    location_s *location_ptr = (location_s *)cs_elm.location_ptr;

    // - process dictionary -
    if (location_ptr->v_type == c_rm_class_dict)
    {/*{{{*/
      pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)location_ptr->v_data_ptr;

      if (cs_elm.initialize)
      {
        buffer.push('{');

        cs_elm.index = tree_ptr->root_idx == c_idx_not_exist ?
          c_idx_not_exist : tree_ptr->get_min_value_idx(tree_ptr->root_idx);

        cs_elm.initialize = false;
      }
      else
      {
        if (cs_elm.index != c_idx_not_exist)
        {
          buffer.push(',');
        }
      }

      if (cs_elm.index != c_idx_not_exist)
      {
        pointer_map_tree_s_node &node = tree_ptr->data[cs_elm.index];
        location_s *key_location = (location_s *)node.object.key;
        location_s *item_location = it.get_location_value(node.object.value);

        // - ERROR -
        if (key_location->v_type != c_bi_class_string)
        {
          buffer.clear();
          create_stack.clear();

          exception_s::throw_exception(it,module.error_base + c_error_JSON_CREATE_NO_STRING_DICT_KEY,operands[c_source_pos_idx],(location_s *)it.blank_location);
          return false;
        }

        // - retrieve key string -
        string_s *string_ptr = (string_s *)key_location->v_data_ptr;

        buffer.push('"');
        json_creator_s::append_string(*string_ptr,buffer);
        buffer.push('"');
        buffer.push(':');

        cs_elm.index = tree_ptr->get_next_idx(cs_elm.index);

        // - insert value object to create stack -
        create_stack.push_blank();
        create_stack.last().set(item_location,true,c_idx_not_exist);
      }
      else
      {
        buffer.push('}');

        create_stack.pop();
      }
    }/*}}}*/
    else
    {
      switch (location_ptr->v_type)
      {
      case c_bi_class_blank:
        {/*{{{*/
          buffer.append(strlen("null"),"null");
          create_stack.pop();
        }/*}}}*/
        break;

      case c_bi_class_integer:
        {/*{{{*/
          long long int value = (long long int)location_ptr->v_data_ptr;

          buffer.reserve(max_number_string_length);
          buffer.used += snprintf(buffer.data + buffer.used,max_number_string_length,"%" HOST_LL_FORMAT "d",value);

          create_stack.pop();
        }/*}}}*/
        break;

      case c_bi_class_float:
        {/*{{{*/
          double value = (double)location_ptr->v_data_ptr;

          buffer.reserve(max_number_string_length);
          buffer.used += snprintf(buffer.data + buffer.used,max_number_string_length,"%f",value);

          create_stack.pop();
        }/*}}}*/
        break;

      case c_bi_class_string:
        {/*{{{*/
          string_s *string_ptr = (string_s *)location_ptr->v_data_ptr;

          buffer.push('"');
          json_creator_s::append_string(*string_ptr,buffer);
          buffer.push('"');

          create_stack.pop();
        }/*}}}*/
        break;

      case c_bi_class_array:
        {/*{{{*/
          pointer_array_s *array_ptr = (pointer_array_s *)location_ptr->v_data_ptr;

          if (cs_elm.initialize)
          {
            buffer.push('[');

            cs_elm.index = 0;
            cs_elm.initialize = false;
          }
          else
          {
            if (cs_elm.index < array_ptr->used)
            {
              buffer.push(',');
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
            buffer.push(']');

            create_stack.pop();
          }
        }/*}}}*/
        break;

      // - ERROR -
      default:
        buffer.clear();
        create_stack.clear();

        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_JSON_CREATE_UNSUPPORTED_CLASS,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(location_ptr->v_type);

        return false;
      }
    }
  } while(create_stack.used > 0);

  // - release create stack -
  create_stack.clear();

  // - push terminating character to buffer -
  buffer.push('\0');

  // - create result string from buffer -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->size = buffer.used;
  string_ptr->data = buffer.data;

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_json_method_create_nice_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_rm_class_dict ||
      src_1_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_json,"create_nice#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

#define JSON_CREATE_NICE_CLEAR() \
{/*{{{*/\
  create_stack.clear();\
  buffer.clear();\
  indent_buffer.clear();\
}/*}}}*/

#define JSON_CREATE_NICE_PUSH_TAB() \
{/*{{{*/\
  if ((indent_size += tab_str_ptr->size - 1) > indent_buffer.used)\
  {\
    indent_buffer.append(tab_str_ptr->size - 1,tab_str_ptr->data);\
  }\
}/*}}}*/

#define JSON_CREATE_NICE_POP_TAB() \
{/*{{{*/\
  indent_size -= tab_str_ptr->size - 1;\
}/*}}}*/

#define JSON_CREATE_NICE_INDENT() \
{/*{{{*/\
  buffer.push('\n');\
  buffer.append(indent_size,indent_buffer.data);\
}/*}}}*/

  // - retrieve tabulator pointer -
  string_s *tab_str_ptr = (string_s *)src_1_location->v_data_ptr;

  // - initialize indent buffer -
  bc_array_s indent_buffer;
  indent_buffer.init();

  // - initialize actual indent size -
  unsigned indent_size = 0;

  // - initialize character buffer -
  bc_array_s buffer;
  buffer.init();

  // - initialize create stack -
  create_stack_s create_stack;
  create_stack.init();

  // - insert source location to create stack -
  create_stack.push_blank();
  create_stack.last().set(src_0_location,true,c_idx_not_exist);

  do {

    // - reference to last stack element -
    cs_element_s &cs_elm = create_stack.last();

    // - retrieve location pointer -
    location_s *location_ptr = (location_s *)cs_elm.location_ptr;

    // - process dictionary -
    if (location_ptr->v_type == c_rm_class_dict)
    {/*{{{*/
      pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)location_ptr->v_data_ptr;

      if (cs_elm.initialize)
      {
        buffer.push('{');

        // - if dictionary is not empty -
        if (tree_ptr->count != 0)
        {
          // - push tabulator to indent -
          JSON_CREATE_NICE_PUSH_TAB();

          // - insert indentation -
          JSON_CREATE_NICE_INDENT();
        }

        cs_elm.index = tree_ptr->root_idx == c_idx_not_exist ?
          c_idx_not_exist : tree_ptr->get_min_value_idx(tree_ptr->root_idx);

        cs_elm.initialize = false;
      }
      else
      {
        if (cs_elm.index != c_idx_not_exist)
        {
          buffer.push(',');

          // - insert indentation -
          JSON_CREATE_NICE_INDENT();
        }
      }

      if (cs_elm.index != c_idx_not_exist)
      {
        pointer_map_tree_s_node &node = tree_ptr->data[cs_elm.index];
        location_s *key_location = (location_s *)node.object.key;
        location_s *item_location = it.get_location_value(node.object.value);

        // - ERROR -
        if (key_location->v_type != c_bi_class_string)
        {
          JSON_CREATE_NICE_CLEAR();

          exception_s::throw_exception(it,module.error_base + c_error_JSON_CREATE_NO_STRING_DICT_KEY,operands[c_source_pos_idx],(location_s *)it.blank_location);
          return false;
        }

        // - retrieve key string -
        string_s *string_ptr = (string_s *)key_location->v_data_ptr;

        buffer.push('"');
        json_creator_s::append_string(*string_ptr,buffer);
        buffer.push('"');
        buffer.push(':');
        buffer.push(' ');

        cs_elm.index = tree_ptr->get_next_idx(cs_elm.index);

        // - insert value object to create stack -
        create_stack.push_blank();
        create_stack.last().set(item_location,true,c_idx_not_exist);
      }
      else
      {
        // - if dictionary is not empty -
        if (tree_ptr->count != 0)
        {
          // - remove tabulator from indent -
          JSON_CREATE_NICE_POP_TAB();

          // - insert indentation -
          JSON_CREATE_NICE_INDENT();
        }

        buffer.push('}');

        create_stack.pop();
      }
    }/*}}}*/
    else
    {
      switch (location_ptr->v_type)
      {
      case c_bi_class_blank:
        {/*{{{*/
          buffer.append(strlen("null"),"null");
          create_stack.pop();
        }/*}}}*/
        break;

      case c_bi_class_integer:
        {/*{{{*/
          long long int value = (long long int)location_ptr->v_data_ptr;

          buffer.reserve(max_number_string_length);
          buffer.used += snprintf(buffer.data + buffer.used,max_number_string_length,"%" HOST_LL_FORMAT "d",value);

          create_stack.pop();
        }/*}}}*/
        break;

      case c_bi_class_float:
        {/*{{{*/
          double value = (double)location_ptr->v_data_ptr;

          buffer.reserve(max_number_string_length);
          buffer.used += snprintf(buffer.data + buffer.used,max_number_string_length,"%f",value);

          create_stack.pop();
        }/*}}}*/
        break;

      case c_bi_class_string:
        {/*{{{*/
          string_s *string_ptr = (string_s *)location_ptr->v_data_ptr;

          buffer.push('"');
          json_creator_s::append_string(*string_ptr,buffer);
          buffer.push('"');

          create_stack.pop();
        }/*}}}*/
        break;

      case c_bi_class_array:
        {/*{{{*/
          pointer_array_s *array_ptr = (pointer_array_s *)location_ptr->v_data_ptr;

          if (cs_elm.initialize)
          {
            buffer.push('[');

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
              buffer.push(',');

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

            buffer.push(']');

            create_stack.pop();
          }
        }/*}}}*/
        break;

      // - ERROR -
      default:
        JSON_CREATE_NICE_CLEAR();

        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_JSON_CREATE_UNSUPPORTED_CLASS,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(location_ptr->v_type);

        return false;
      }
    }
  } while(create_stack.used > 0);

  // - release create stack -
  create_stack.clear();

  // - release indent buffer -
  indent_buffer.clear();

  // - push terminating character to buffer -
  buffer.push('\0');

  // - create result string from buffer -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->size = buffer.used;
  string_ptr->data = buffer.data;

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_json_method_parse_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_json,"parse#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create json parser -
  json_parser_s json_parser;
  json_parser.init();

  // - ERROR -
  if (!json_parser.parse_source(it,*string_ptr))
  {
    unsigned old_input_idx = json_parser.old_input_idx;

    json_parser.release_locations();
    json_parser.clear();

    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_JSON_PARSE_ERROR,operands[c_source_pos_idx],src_0_location);
    new_exception->params.push(old_input_idx);

    return false;
  }

  // - retrieve object location -
  location_s *obj_location = (location_s *)json_parser.objects.pop();
  BIC_SET_RESULT(obj_location);

  json_parser.release_locations();
  json_parser.clear();

  return true;
}/*}}}*/

bool bic_json_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Json"),"Json");
  );

  return true;
}/*}}}*/

bool bic_json_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Json");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

