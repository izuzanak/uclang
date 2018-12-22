
@begin
include "json_module.h"
@end

// - JSON indexes of built in classes -
unsigned c_bi_class_json = c_idx_not_exist;

// - JSON indexes of remote classes -
unsigned c_rm_class_dict = c_idx_not_exist;

// - JSON module -
EXPORT built_in_module_s module =
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
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nJSON create, unsupported class\n");
    fprintf(stderr," ---------------------------------------- \n");
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
  6, json_methods,
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
    "create_nice#3",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_json_method_create_nice_3
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
  BIC_CLASS_EMPTY_VARIABLES
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
@begin ucl_params
<
dict:c_rm_class_dict
>
class c_bi_class_json
method create
static_method
; @end

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

      if (cs_elm.index == c_idx_not_exist)
      {
        cs_elm.index = 0;
      }

      if (cs_elm.index < tree_ptr->used)
      {
        pointer_map_tree_s_node &node = tree_ptr->data[cs_elm.index++];

        if (node.valid)
        {
          buffer.push(cs_elm.initialize ? '{' : ',');
          cs_elm.initialize = false;

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

          // - insert value object to create stack -
          create_stack.push_blank();
          create_stack.last().set(item_location,true,c_idx_not_exist);
        }
      }
      else
      {
        if (cs_elm.initialize)
        {
          buffer.push('{');
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

        exception_s::throw_exception(it,module.error_base + c_error_JSON_CREATE_UNSUPPORTED_CLASS,operands[c_source_pos_idx],(location_s *)it.blank_location);
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
@begin ucl_params
<
dict:c_rm_class_dict
tabulator:c_bi_class_string
>
class c_bi_class_json
method create_nice
static_method
; @end

  // - retrieve tabulator pointer -
  string_s *tabulator_ptr = (string_s *)src_1_location->v_data_ptr;

  // - create empty indentation string -
  string_s indent;
  indent.init();

  bc_array_s buffer;
  buffer.init();

  unsigned error = json_creator_s::create_nice(it,src_0_location,*tabulator_ptr,indent,buffer);
  indent.clear();

  // - ERROR -
  if (error != c_idx_not_exist)
  {
    buffer.clear();

    exception_s::throw_exception(it,module.error_base + error,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create result string from buffer -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->size = buffer.used;
  string_ptr->data = buffer.data;

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_json_method_create_nice_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
dict:c_rm_class_dict
tabulator:c_bi_class_string
indent:c_bi_class_string
>
class c_bi_class_json
method create_nice
static_method
; @end

  // - retrieve tabulator pointer -
  string_s *tabulator_ptr = (string_s *)src_1_location->v_data_ptr;

  // - retrieve indentation pointer -
  string_s *indent_ptr = (string_s *)src_2_location->v_data_ptr;

  bc_array_s buffer;
  buffer.init();

  unsigned error = json_creator_s::create_nice(it,src_0_location,*tabulator_ptr,*indent_ptr,buffer);

  // - ERROR -
  if (error != c_idx_not_exist)
  {
    buffer.clear();

    exception_s::throw_exception(it,module.error_base + error,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create result string from buffer -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->size = buffer.used;
  string_ptr->data = buffer.data;

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_json_method_parse_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:c_bi_class_string
>
class c_bi_class_json
method parse
static_method
; @end

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

