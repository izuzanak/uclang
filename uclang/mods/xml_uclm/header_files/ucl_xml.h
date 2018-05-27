
#ifndef __UCL_XML_H
#define __UCL_XML_H

/*
 * header files
 */

@begin
include "script_parser.h"
@end

#include <libxml/tree.h>
#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>

/*
 * constants and definitions
 */

extern unsigned c_bi_class_xml_node;
extern unsigned c_rm_class_dict;

/*
 * definition of structure xml_creator_s
 */

struct xml_creator_s
{
  static void append_string(const char *a_data,unsigned a_size,bc_array_s &a_buffer);
};

/*
 * definition of structure xml_node_s
 */

struct xml_node_s
{
  location_s *name;
  location_s *attributes;
  location_s *nodes;
  location_s *texts;
  location_s *conts;

  static inline pointer_array_s *get_conts_array(interpreter_thread_s &it,location_s *&a_location_ptr);

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of class xml_c
 */

class xml_c
{
  public:
  inline xml_c();
  inline ~xml_c();
};

/*
 * definition of generated structures
 */

// -- cs_element_s --
@begin
struct
<
pointer:node_ptr
unsigned:index
bool:after_node
>
cs_element_s;
@end

// -- create_stack_s --
@begin
array<cs_element_s> create_stack_s;
@end

// -- pointer_arrays_s --
@begin
array<pointer_array_s> pointer_arrays_s;
@end

// -- sax_parser_s --
@begin
struct
<
pointer:it_ptr

string_rb_tree_s:const_strings
pointer_array_s:string_locations

pointer_array_s:attrs_stack
pointer_arrays_s:node_array_stack
pointer_arrays_s:text_array_stack
pointer_arrays_s:cont_array_stack
>

additions
{
  // - retrieve or create string location -
  location_s *get_string_location(unsigned a_length,const char *a_data);

  // - release parser locations -
  void release_locations();
}

  sax_parser_s;
@end

/*
 * definition of global functions
 */

void xml_start_document(void *user);
void xml_end_document(void *user);
void xml_start_element(void *user,const xmlChar *name,const xmlChar **attrs);
void xml_end_element(void *user,const xmlChar *name);
void xml_characters(void *user,const xmlChar *ch,int len);

void xml_warning(void *user,const char *msg,...);
void xml_error(void *user,const char *msg,...);
void xml_fatal_error(void *user,const char *msg,...);

/*
 * inline methods of structure xml_node_s
 */

inline pointer_array_s *xml_node_s::get_conts_array(interpreter_thread_s &it,location_s *&a_location_ptr)
{/*{{{*/

  // - if array does not exist -
  if (a_location_ptr == nullptr ||
      a_location_ptr->v_type != c_bi_class_array)
  {
    pointer_array_s *conts_array = it.get_new_array_ptr();

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,conts_array);

    if (a_location_ptr != nullptr)
    {
      it.release_location_ptr(a_location_ptr);
    }

    a_location_ptr = new_location;

    return conts_array;
  }

  return a_location_ptr->v_data_ptr;
}/*}}}*/

inline void xml_node_s::init()
{/*{{{*/
  name = nullptr;
  attributes = nullptr;
  nodes = nullptr;
  texts = nullptr;
  conts = nullptr;
}/*}}}*/

inline void xml_node_s::clear(interpreter_thread_s &it)
{/*{{{*/
#define RELEASE_XML_NODE_MEMBER(MEMBER) \
{/*{{{*/\
  if (MEMBER != nullptr)\
  {\
    it.release_location_ptr(MEMBER);\
  }\
}/*}}}*/

  RELEASE_XML_NODE_MEMBER(name);
  RELEASE_XML_NODE_MEMBER(attributes);
  RELEASE_XML_NODE_MEMBER(nodes);
  RELEASE_XML_NODE_MEMBER(texts);
  RELEASE_XML_NODE_MEMBER(conts);

  init();
}/*}}}*/

/*
 * inline methods of class xml_c
 */

inline xml_c::xml_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"libxml_init()\n"););

  xmlInitParser();
}/*}}}*/

inline xml_c::~xml_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"libxml_exit()\n"););

  xmlCleanupParser();
}/*}}}*/

/*
 * inline methods of generated structures
 */

// -- cs_element_s --
@begin
inlines cs_element_s
@end

// -- create_stack_s --
@begin
inlines create_stack_s
@end

// -- pointer_arrays_s --
@begin
inlines pointer_arrays_s
@end

// -- sax_parser_s --
@begin
inlines sax_parser_s
@end

#endif

