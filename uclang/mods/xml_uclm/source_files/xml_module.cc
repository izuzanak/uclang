
@begin
include "xml_module.h"
@end

// - XML indexes of built in classes -
unsigned c_bi_class_xml = c_idx_not_exist;
unsigned c_bi_class_xml_node = c_idx_not_exist;

// - XML indexes of remote classes -
unsigned c_rm_class_dict = c_idx_not_exist;

// - XML module -
built_in_module_s module =
{/*{{{*/
  2,                    // Class count
  xml_classes,          // Classes

  0,                    // Error base index
  5,                    // Error count
  xml_error_strings,    // Error strings

  xml_initialize,       // Initialize function
  xml_print_exception,  // Print exceptions function
};/*}}}*/

// - XML classes -
built_in_class_s *xml_classes[] =
{/*{{{*/
  &xml_class,
  &xml_node_class,
};/*}}}*/

// - XML error strings -
const char *xml_error_strings[] =
{/*{{{*/
  "error_XML_ERROR_PARSING_DATA",
  "error_XML_NODE_NAME_INVALID_VALUE_ERROR",
  "error_XML_NODE_NODE_DICTIONARY_NOT_AVAILABLE",
  "error_XML_NODE_ATTRIBUTE_INVALID_VALUE_ERROR",
  "error_XML_NODE_TEXT_VALUE_ERROR",
};/*}}}*/

// - XML initialize -
bool xml_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize xml class identifier -
  c_bi_class_xml = class_base_idx++;

  // - initialize xml_node class identifier -
  c_bi_class_xml_node = class_base_idx++;

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

// - XML print exception -
bool xml_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_XML_ERROR_PARSING_DATA:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError parsing XML data, not well formed document\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_XML_NODE_NAME_INVALID_VALUE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid value of XML node name\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_XML_NODE_NODE_DICTIONARY_NOT_AVAILABLE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nXML node dictionary is not available or updated\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_XML_NODE_ATTRIBUTE_INVALID_VALUE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid value of XML node attribute\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_XML_NODE_TEXT_VALUE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nXML node does not contain simple text value\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class XML -
built_in_class_s xml_class =
{/*{{{*/
  "Xml",
  c_modifier_public | c_modifier_final,
  6, xml_methods,
  0, xml_variables,
  bic_xml_consts,
  bic_xml_init,
  bic_xml_clear,
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

built_in_method_s xml_methods[] =
{/*{{{*/
  {
    "create#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_xml_method_create_1
  },
  {
    "create_nice#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_xml_method_create_nice_2
  },
  {
    "create_nice#3",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_xml_method_create_nice_3
  },
  {
    "parse#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_xml_method_parse_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_xml_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_xml_method_print_0
  },
};/*}}}*/

built_in_variable_s xml_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_xml_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_xml_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_xml_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_xml_method_create_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
node:c_bi_class_xml_node
>
class c_bi_class_xml
method create
static_method
; @end

  bc_array_s buffer;
  buffer.init();

  // - initialize create stack -
  create_stack_s create_stack;
  create_stack.init();

  // - insert root node to create stack -
  create_stack.push_blank();
  create_stack.last().set(src_0_location->v_data_ptr,0,true);

  do {

    // - reference to last stack element -
    cs_element_s &cs_elm = create_stack.last();

    // - retrieve node pointer -
    xml_node_s *node_ptr = (xml_node_s *)cs_elm.node_ptr;

    // - format node open tag -
    if (cs_elm.index == 0)
    {
      buffer.push('<');

      string_s *name_ptr = (string_s *)node_ptr->name->v_data_ptr;
      buffer.append(name_ptr->size - 1,name_ptr->data);

      // - format node attributes -
      if (node_ptr->attributes->v_type != c_bi_class_blank)
      {
        pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)node_ptr->attributes->v_data_ptr;

        if (tree_ptr->root_idx != c_idx_not_exist)
        {
          pointer_map_tree_s_node *tn_ptr = tree_ptr->data;
          pointer_map_tree_s_node *tn_ptr_end = tn_ptr + tree_ptr->used;
          do {

            // - tree node is valid -
            if (tn_ptr->valid)
            {
              buffer.push(' ');

              string_s *key_ptr = (string_s *)((location_s *)tn_ptr->object.key)->v_data_ptr;
              buffer.append(key_ptr->size - 1,key_ptr->data);

              buffer.push('=');
              buffer.push('"');

              string_s *value_ptr = (string_s *)it.get_location_value(tn_ptr->object.value)->v_data_ptr;
              xml_creator_s::append_string(value_ptr->data,value_ptr->size - 1,buffer);

              buffer.push('"');
            }
          } while(++tn_ptr < tn_ptr_end);
        }
      }

      buffer.push('>');
    }

    // - process node contents -
    if (node_ptr->conts->v_type != c_bi_class_blank)
    {
      pointer_array_s *conts_array = (pointer_array_s *)node_ptr->conts->v_data_ptr;

      if (cs_elm.index < conts_array->used)
      {
        location_s *item_location = it.get_location_value(conts_array->data[cs_elm.index++]);

        if (item_location->v_type == c_bi_class_xml_node)
        {
          create_stack.push_blank();
          create_stack.last().set(item_location->v_data_ptr,0,true);
        }
        else if (item_location->v_type == c_bi_class_string)
        {
          string_s *string_ptr = (string_s *)item_location->v_data_ptr;
          xml_creator_s::append_string(string_ptr->data,string_ptr->size - 1,buffer);
        }
        else
        {
          cassert(0);
        }

        continue;
      }
    }

    // - format node close tag -
    {
      buffer.push('<');
      buffer.push('/');

      string_s *name_ptr = (string_s *)node_ptr->name->v_data_ptr;
      buffer.append(name_ptr->size - 1,name_ptr->data);

      buffer.push('>');
    }

    create_stack.pop();

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

bool bic_xml_method_create_nice_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
node:c_bi_class_xml_node
tabulator:c_bi_class_string
>
class c_bi_class_xml
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

  xml_creator_s::create_nice(it,src_0_location->v_data_ptr,*tabulator_ptr,indent,buffer);
  indent.clear();

  // - create result string from buffer -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->size = buffer.used;
  string_ptr->data = buffer.data;

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_xml_method_create_nice_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
node:c_bi_class_xml_node
tabulator:c_bi_class_string
indent:c_bi_class_string
>
class c_bi_class_xml
method create_nice
static_method
; @end

  // - retrieve tabulator pointer -
  string_s *tabulator_ptr = (string_s *)src_1_location->v_data_ptr;

  // - retrieve indentation pointer -
  string_s *indent_ptr = (string_s *)src_2_location->v_data_ptr;

  bc_array_s buffer;
  buffer.init();

  xml_creator_s::create_nice(it,src_0_location->v_data_ptr,*tabulator_ptr,*indent_ptr,buffer);

  // - create result string from buffer -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->size = buffer.used;
  string_ptr->data = buffer.data;

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_xml_method_parse_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:c_bi_class_string
>
class c_bi_class_xml
method parse
static_method
; @end

  string_s *data_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create sax handler -
  xmlSAXHandler sax;
  memset(&sax,0,sizeof(sax));

  // - set sax callbacks -
  sax.startDocument = xml_start_document;
  sax.endDocument = xml_end_document;
  sax.startElement = xml_start_element;
  sax.endElement = xml_end_element;
  sax.characters = xml_characters;

  sax.warning = xml_warning;
  sax.error = xml_error;
  sax.fatalError = xml_fatal_error;

  // - create sax_parser object -
  sax_parser_s sp;
  sp.init();

  // - initialize sax parser -
  sp.it_ptr = (pointer)&it;
  sp.node_array_stack.push_blank();
  sp.cont_array_stack.push_blank();

  // - parse xml data -
  int res = xmlSAXUserParseMemory(&sax,&sp,data_ptr->data,data_ptr->size - 1);

  // - ERROR -
  if (res != 0)
  {
    sp.release_locations();
    sp.clear();

    exception_s::throw_exception(it,module.error_base + c_error_XML_ERROR_PARSING_DATA,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - retrieve root location -
  location_s *root_loc = (location_s *)sp.node_array_stack.last().pop();

  BIC_SET_RESULT(root_loc);

  sp.release_locations();
  sp.clear();

  return true;
}/*}}}*/

bool bic_xml_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Xml"),"Xml");
  );

  return true;
}/*}}}*/

bool bic_xml_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Xml");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class XML_NODE -
built_in_class_s xml_node_class =
{/*{{{*/
  "XmlNode",
  c_modifier_public | c_modifier_final,
  22, xml_node_methods,
  0, xml_node_variables,
  bic_xml_node_consts,
  bic_xml_node_init,
  bic_xml_node_clear,
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

built_in_method_s xml_node_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_xml_node_operator_binary_equal
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_xml_node_operator_binary_le_br_re_br
  },
  {
    "XmlNode#1",
    c_modifier_public | c_modifier_final,
    bic_xml_node_method_XmlNode_1
  },
  {
    "update_node_dict#0",
    c_modifier_public | c_modifier_final,
    bic_xml_node_method_update_node_dict_0
  },
  {
    "attr_#2",
    c_modifier_public | c_modifier_final,
    bic_xml_node_method_attr__2
  },
  {
    "node#1",
    c_modifier_public | c_modifier_final,
    bic_xml_node_method_node_1
  },
  {
    "node_#1",
    c_modifier_public | c_modifier_final,
    bic_xml_node_method_node__1
  },
  {
    "node#2",
    c_modifier_public | c_modifier_final,
    bic_xml_node_method_node_2
  },
  {
    "node_#2",
    c_modifier_public | c_modifier_final,
    bic_xml_node_method_node__2
  },
  {
    "text_#1",
    c_modifier_public | c_modifier_final,
    bic_xml_node_method_text__1
  },
  {
    "append#1",
    c_modifier_public | c_modifier_final,
    bic_xml_node_method_append_1
  },
  {
    "has_key#1",
    c_modifier_public | c_modifier_final,
    bic_xml_node_method_has_key_1
  },
  {
    "name#0",
    c_modifier_public | c_modifier_final,
    bic_xml_node_method_name_0
  },
  {
    "text#0",
    c_modifier_public | c_modifier_final,
    bic_xml_node_method_text_0
  },
  {
    "attributes#0",
    c_modifier_public | c_modifier_final,
    bic_xml_node_method_attributes_0
  },
  {
    "node_dict#0",
    c_modifier_public | c_modifier_final,
    bic_xml_node_method_node_dict_0
  },
  {
    "nodes#0",
    c_modifier_public | c_modifier_final,
    bic_xml_node_method_nodes_0
  },
  {
    "texts#0",
    c_modifier_public | c_modifier_final,
    bic_xml_node_method_texts_0
  },
  {
    "content#0",
    c_modifier_public | c_modifier_final,
    bic_xml_node_method_content_0
  },
  {
    "contain#1",
    c_modifier_public | c_modifier_final,
    bic_xml_node_method_has_key_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_xml_node_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_xml_node_method_print_0
  },
};/*}}}*/

built_in_variable_s xml_node_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

#define BIC_XML_NODE_MEMBER(MEMBER_NAME) \
{/*{{{*/\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  xml_node_s *node_ptr = (xml_node_s *)dst_location->v_data_ptr;\
\
  location_s *location = node_ptr->MEMBER_NAME;\
  location->v_reference_cnt.atomic_inc();\
\
  BIC_SET_RESULT(location);\
\
  return true;\
}/*}}}*/

#define BIC_XML_NODE_METHOD_NODE_1(NAME,REF_CNT) \
/*{{{*/\
@begin ucl_params
<
name:c_bi_class_string
>
method NAME
macro
; @end\
\
  xml_node_s *node_ptr = (xml_node_s *)dst_location->v_data_ptr;\
  string_s *name_ptr = (string_s *)src_0_location->v_data_ptr;\
\
  /* - ERROR - */\
  if (name_ptr->size <= 1)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_XML_NODE_NAME_INVALID_VALUE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  pointer_array_s *nodes_array = xml_node_s::get_conts_array(it,node_ptr->nodes);\
  pointer_array_s *conts_array = xml_node_s::get_conts_array(it,node_ptr->conts);\
\
  /* - create xml node object - */\
  xml_node_s *new_node_ptr = (xml_node_s *)cmalloc(sizeof(xml_node_s));\
  new_node_ptr->init();\
\
  src_0_location->v_reference_cnt.atomic_inc();\
  new_node_ptr->name = src_0_location;\
\
  location_s *blank_location = (location_s *)it.blank_location;\
  blank_location->v_reference_cnt.atomic_add(5);\
\
  new_node_ptr->attributes = blank_location;\
  new_node_ptr->node_dict = blank_location;\
  new_node_ptr->nodes = blank_location;\
  new_node_ptr->texts = blank_location;\
  new_node_ptr->conts = blank_location;\
\
  BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_xml_node,new_node_ptr,REF_CNT);\
\
  nodes_array->push(new_location);\
  conts_array->push(new_location);\
/*}}}*/

#define BIC_XML_NODE_METHOD_NODE_2(NAME,REF_CNT) \
/*{{{*/\
@begin ucl_params
<
name:c_bi_class_string
data:c_bi_class_string
>
method NAME
macro
; @end\
\
  xml_node_s *node_ptr = (xml_node_s *)dst_location->v_data_ptr;\
  string_s *name_ptr = (string_s *)src_0_location->v_data_ptr;\
\
  /* - ERROR - */\
  if (name_ptr->size <= 1)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_XML_NODE_NAME_INVALID_VALUE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  pointer_array_s *nodes_array = xml_node_s::get_conts_array(it,node_ptr->nodes);\
  pointer_array_s *conts_array = xml_node_s::get_conts_array(it,node_ptr->conts);\
\
  /* - create xml node object - */\
  xml_node_s *new_node_ptr = (xml_node_s *)cmalloc(sizeof(xml_node_s));\
  new_node_ptr->init();\
\
  src_0_location->v_reference_cnt.atomic_inc();\
  new_node_ptr->name = src_0_location;\
\
  location_s *blank_location = (location_s *)it.blank_location;\
  blank_location->v_reference_cnt.atomic_add(3);\
\
  new_node_ptr->attributes = blank_location;\
  new_node_ptr->node_dict = blank_location;\
  new_node_ptr->nodes = blank_location;\
\
  pointer_array_s *new_texts_array = xml_node_s::get_conts_array(it,new_node_ptr->texts);\
  pointer_array_s *new_conts_array = xml_node_s::get_conts_array(it,new_node_ptr->conts);\
\
  src_1_location->v_reference_cnt.atomic_add(2);\
  new_texts_array->push(src_1_location);\
  new_conts_array->push(src_1_location);\
\
  BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_xml_node,new_node_ptr,REF_CNT);\
\
  nodes_array->push(new_location);\
  conts_array->push(new_location);\
/*}}}*/

void bic_xml_node_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_xml_node_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (xml_node_s *)nullptr;
}/*}}}*/

void bic_xml_node_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  xml_node_s *node_ptr = (xml_node_s *)location_ptr->v_data_ptr;

  // - if xml node exists -
  if (node_ptr != nullptr)
  {
    node_ptr->clear(it);
    cfree(node_ptr);
  }
}/*}}}*/

bool bic_xml_node_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_xml_node_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  xml_node_s *node_ptr = (xml_node_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (node_ptr->node_dict->v_type != c_rm_class_dict)
  {
    exception_s::throw_exception(it,module.error_base + c_error_XML_NODE_NODE_DICTIONARY_NOT_AVAILABLE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)node_ptr->node_dict->v_data_ptr;

  tree_ptr->it_ptr = &it;
  tree_ptr->source_pos = operands[c_source_pos_idx];

  pointer_map_s search_map = {(pointer)src_0_location,nullptr};
  unsigned index = tree_ptr->get_idx(search_map);

  if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
  {
    return false;
  }

  if (index != c_idx_not_exist)
  {
    location_s *value_location = (location_s *)tree_ptr->data[index].object.value;

    value_location->v_reference_cnt.atomic_inc();
    BIC_SET_RESULT(value_location);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_xml_node_method_XmlNode_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
name:c_bi_class_string
>
method XmlNode
; @end

  string_s *name_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (name_ptr->size <= 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_XML_NODE_NAME_INVALID_VALUE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create xml node object -
  xml_node_s *node_ptr = (xml_node_s *)cmalloc(sizeof(xml_node_s));
  node_ptr->init();

  src_0_location->v_reference_cnt.atomic_inc();
  node_ptr->name = src_0_location;

  location_s *blank_location = (location_s *)it.blank_location;
  blank_location->v_reference_cnt.atomic_add(5);

  node_ptr->attributes = blank_location;
  node_ptr->node_dict = blank_location;
  node_ptr->nodes = blank_location;
  node_ptr->texts = blank_location;
  node_ptr->conts = blank_location;

  // - set xml_node destination location -
  dst_location->v_data_ptr = (xml_node_s *)node_ptr;

  return true;
}/*}}}*/

bool bic_xml_node_method_update_node_dict_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_array_s node_stack;
  node_stack.init();

  // - push node to node stack -
  node_stack.push(dst_location->v_data_ptr);

  do {
    xml_node_s *node_ptr = (xml_node_s *)node_stack.pop();

    // - create node dictionary -
    pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)cmalloc(sizeof(pointer_map_tree_s));
    tree_ptr->init();

    tree_ptr->it_ptr = &it;
    tree_ptr->source_pos = 0;

    BIC_CREATE_NEW_LOCATION(new_location,c_rm_class_dict,tree_ptr);

    it.release_location_ptr(node_ptr->node_dict);
    node_ptr->node_dict = new_location;

    // - contains another nodes -
    if (node_ptr->nodes->v_type == c_bi_class_array)
    {
      pointer_array_s *nodes_array = (pointer_array_s *)node_ptr->nodes->v_data_ptr;

      // - process all nodes -
      if (nodes_array->used != 0)
      {
        pointer *n_ptr = nodes_array->data;
        pointer *n_ptr_end = n_ptr + nodes_array->used;
        do {
          xml_node_s *node_ptr = (xml_node_s *)((location_s *)*n_ptr)->v_data_ptr;

          // - add node to node dictionary -
          xml_node_s::add_node_to_node_dict(it,*tree_ptr,node_ptr->name,(location_s *)*n_ptr);

          // - push node to node stack -
          node_stack.push(node_ptr);

        } while(++n_ptr < n_ptr_end);
      }
    }

  } while(node_stack.used > 0);

  node_stack.clear();

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_xml_node_method_attr__2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
name:c_bi_class_string
value:c_bi_class_string
>
method attr_
; @end

  xml_node_s *node_ptr = (xml_node_s *)dst_location->v_data_ptr;
  string_s *name_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (name_ptr->size <= 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_XML_NODE_ATTRIBUTE_INVALID_VALUE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  pointer_map_tree_s *tree_ptr;

  // - if attributes does not exist -
  if (node_ptr->attributes->v_type != c_rm_class_dict)
  {
    tree_ptr = (pointer_map_tree_s *)cmalloc(sizeof(pointer_map_tree_s));
    tree_ptr->init();

    BIC_CREATE_NEW_LOCATION(new_location,c_rm_class_dict,tree_ptr);

    it.release_location_ptr(node_ptr->attributes);
    node_ptr->attributes = new_location;
  }
  else
  {
    tree_ptr = (pointer_map_tree_s *)node_ptr->attributes->v_data_ptr;
  }

  tree_ptr->it_ptr = &it;
  tree_ptr->source_pos = operands[c_source_pos_idx];

  // - push key and value locations to dictionary -
  pointer_map_s insert_map = {src_0_location,nullptr};
  unsigned index = tree_ptr->unique_insert(insert_map);

  // - ERROR -
  if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
  {
    return false;
  }

  pointer_map_s &map = tree_ptr->data[index].object;

  if (map.value)
  {
    it.release_location_ptr((location_s *)map.value);
  }
  else
  {
    src_0_location->v_reference_cnt.atomic_inc();
  }

  src_1_location->v_reference_cnt.atomic_inc();
  map.value = (pointer)src_1_location;

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_xml_node_method_node_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_XML_NODE_METHOD_NODE_1("node#1",3);

  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_xml_node_method_node__1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_XML_NODE_METHOD_NODE_1("node_#1",2);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_xml_node_method_node_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_XML_NODE_METHOD_NODE_2("node#2",3);

  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_xml_node_method_node__2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_XML_NODE_METHOD_NODE_2("node_#2",2);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_xml_node_method_text__1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:c_bi_class_string
>
method text_
; @end

  xml_node_s *node_ptr = (xml_node_s *)dst_location->v_data_ptr;

  pointer_array_s *texts_array = xml_node_s::get_conts_array(it,node_ptr->texts);
  pointer_array_s *conts_array = xml_node_s::get_conts_array(it,node_ptr->conts);

  src_0_location->v_reference_cnt.atomic_add(2);
  texts_array->push(src_0_location);
  conts_array->push(src_0_location);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_xml_node_method_append_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
node:c_bi_class_xml_node
>
method append
; @end

  xml_node_s *node_ptr = (xml_node_s *)dst_location->v_data_ptr;

  pointer_array_s *nodes_array = xml_node_s::get_conts_array(it,node_ptr->nodes);
  pointer_array_s *conts_array = xml_node_s::get_conts_array(it,node_ptr->conts);

  src_0_location->v_reference_cnt.atomic_add(2);
  nodes_array->push(src_0_location);
  conts_array->push(src_0_location);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_xml_node_method_has_key_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  xml_node_s *node_ptr = (xml_node_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (node_ptr->node_dict->v_type != c_rm_class_dict)
  {
    exception_s::throw_exception(it,module.error_base + c_error_XML_NODE_NODE_DICTIONARY_NOT_AVAILABLE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)node_ptr->node_dict->v_data_ptr;

  tree_ptr->it_ptr = &it;
  tree_ptr->source_pos = operands[c_source_pos_idx];

  pointer_map_s search_map = {(pointer)src_0_location,nullptr};
  unsigned index = tree_ptr->get_idx(search_map);

  if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
  {
    return false;
  }

  long long int result = index != c_idx_not_exist;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_xml_node_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_XML_NODE_MEMBER(name);
}/*}}}*/

bool bic_xml_node_method_text_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  xml_node_s *node_ptr = (xml_node_s *)dst_location->v_data_ptr;

  location_s *texts_location = node_ptr->texts;
  location_s *conts_location = node_ptr->conts;

  // - if node does not contain text -
  if (texts_location->v_type == c_bi_class_blank)
  {
    // - ERROR -
    if (conts_location->v_type != c_bi_class_blank)
    {
      exception_s::throw_exception(it,module.error_base + c_error_XML_NODE_TEXT_VALUE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    string_s *string_ptr = it.get_new_string_ptr();

    BIC_SET_RESULT_STRING(string_ptr);

    return true;
  }

  pointer_array_s *texts_array_ptr = (pointer_array_s *)texts_location->v_data_ptr;
  pointer_array_s *conts_array_ptr = (pointer_array_s *)conts_location->v_data_ptr;

  // - ERROR -
  if (texts_array_ptr->used != 1 || texts_array_ptr->used != conts_array_ptr->used)
  {
    exception_s::throw_exception(it,module.error_base + c_error_XML_NODE_TEXT_VALUE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  location_s *item_location = it.get_location_value(texts_array_ptr->data[0]);
  item_location->v_reference_cnt.atomic_inc();

  BIC_SET_RESULT(item_location);

  return true;
}/*}}}*/

bool bic_xml_node_method_attributes_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_XML_NODE_MEMBER(attributes);
}/*}}}*/

bool bic_xml_node_method_node_dict_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_XML_NODE_MEMBER(node_dict);
}/*}}}*/

bool bic_xml_node_method_nodes_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_XML_NODE_MEMBER(nodes);
}/*}}}*/

bool bic_xml_node_method_texts_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_XML_NODE_MEMBER(texts);
}/*}}}*/

bool bic_xml_node_method_content_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_XML_NODE_MEMBER(conts);
}/*}}}*/

bool bic_xml_node_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("XmlNode"),"XmlNode");
  );

  return true;
}/*}}}*/

bool bic_xml_node_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("XmlNode");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

