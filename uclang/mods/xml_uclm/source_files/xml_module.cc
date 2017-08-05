
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
  2,                    // Error count
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
  3, xml_methods,
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

bool bic_xml_method_parse_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_xml,"parse#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

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
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];

  printf("Xml");

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class XML_NODE -
built_in_class_s xml_node_class =
{/*{{{*/
  "XmlNode",
  c_modifier_public | c_modifier_final,
  9, xml_node_methods,
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
};/*}}}*/

#define BIC_XML_NODE_MEMBER(MEMBER_NAME) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
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
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_xml_node_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_XML_NODE_MEMBER(name);
}/*}}}*/

bool bic_xml_node_method_text_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
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
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];

  printf("XmlNode");

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

