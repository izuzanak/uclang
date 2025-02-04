
#ifndef __XML_MODULE_H
#define __XML_MODULE_H

@begin
include "ucl_xml.h"
@end

// - XML indexes of built in classes -
extern unsigned c_bi_class_xml;

// - XML module -
extern "C" EXPORT built_in_module_s module;

// - XML classes -
extern built_in_class_s *xml_classes[];

// - XML error identifiers -
enum
{
  c_error_XML_ERROR_PARSING_DATA,
  c_error_XML_NODE_NAME_INVALID_VALUE_ERROR,
  c_error_XML_NODE_NODE_DICTIONARY_NOT_AVAILABLE,
  c_error_XML_NODE_ATTRIBUTE_INVALID_VALUE_ERROR,
  c_error_XML_NODE_TEXT_VALUE_ERROR,
};

// - XML error strings -
extern const char *xml_error_strings[];

// - XML initialize -
bool xml_initialize(script_parser_s &sp);

// - XML print exception -
bool xml_print_exception(interpreter_s &it,exception_s &exception);

// - class XML -
extern built_in_variable_s xml_variables[];
extern built_in_method_s xml_methods[];
extern built_in_class_s xml_class;

void bic_xml_consts(location_array_s &const_locations);
void bic_xml_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_xml_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_xml_method_create_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xml_method_create_nice_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xml_method_create_nice_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xml_method_parse_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xml_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xml_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class XML_NODE -
extern built_in_variable_s xml_node_variables[];
extern built_in_method_s xml_node_methods[];
extern built_in_class_s xml_node_class;

void bic_xml_node_consts(location_array_s &const_locations);
void bic_xml_node_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_xml_node_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_xml_node_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xml_node_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xml_node_method_XmlNode_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xml_node_method_update_node_dict_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xml_node_method_escape_texts_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xml_node_method_attr__2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xml_node_method_node_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xml_node_method_node__1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xml_node_method_node_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xml_node_method_node__2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xml_node_method_text__1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xml_node_method_append_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xml_node_method_has_key_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xml_node_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xml_node_method_text_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xml_node_method_attributes_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xml_node_method_node_dict_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xml_node_method_nodes_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xml_node_method_texts_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xml_node_method_content_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xml_node_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xml_node_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

