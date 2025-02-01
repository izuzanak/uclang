
@begin
include "ucl_xml.h"
@end

// - xml global init object -
xml_c g_xml;

/*
 * methods of structure xml_creator_s
 */

void xml_creator_s::append_string(const char *a_data,unsigned a_size,bc_array_s &a_buffer)
{/*{{{*/
  if (a_size != 0)
  {
    const char *ptr = a_data;
    const char *ptr_end = ptr + a_size;
    do {

      switch (*ptr)
      {
        case '<':
          a_buffer.append(4,"&lt;");
          break;
        case '>':
          a_buffer.append(4,"&gt;");
          break;
        case '&':
          a_buffer.append(5,"&amp;");
          break;
        case '\'':
          a_buffer.append(6,"&apos;");
          break;
        case '"':
          a_buffer.append(6,"&quot;");
          break;
        default:
          a_buffer.push(*ptr);
      }

    } while(++ptr < ptr_end);
  }
}/*}}}*/

void xml_creator_s::create_nice(interpreter_thread_s &it,pointer a_node_ptr,string_s &a_tabulator,string_s &a_indent,bc_array_s &a_buffer)
{/*{{{*/
#define XML_CREATE_NICE_PUSH_TAB() \
{/*{{{*/\
  if ((indent_size += a_tabulator.size - 1) > indent_buffer.used)\
  {\
    indent_buffer.append(a_tabulator.size - 1,a_tabulator.data);\
  }\
}/*}}}*/

#define XML_CREATE_NICE_POP_TAB() \
{/*{{{*/\
  indent_size -= a_tabulator.size - 1;\
}/*}}}*/

#define XML_CREATE_NICE_INDENT() \
{/*{{{*/\
  a_buffer.push('\n');\
  xml_creator_s::append_string(indent_buffer.data,indent_size,a_buffer);\
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

  // - insert root node to create stack -
  create_stack.push_blank();
  create_stack.last().set(a_node_ptr,0,false);

  do {

    // - reference to last stack element -
    cs_element_s &cs_elm = create_stack.last();

    // - retrieve node pointer -
    xml_node_s *node_ptr = (xml_node_s *)cs_elm.node_ptr;

    // - format node open tag -
    if (cs_elm.index == 0)
    {
      if (cs_elm.after_node)
      {
        XML_CREATE_NICE_INDENT();
      }

      a_buffer.push('<');

      string_s *name_ptr = (string_s *)node_ptr->name->v_data_ptr;
      a_buffer.append(name_ptr->size - 1,name_ptr->data);

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
              a_buffer.push(' ');

              string_s *key_ptr = (string_s *)((location_s *)tn_ptr->object.key)->v_data_ptr;
              a_buffer.append(key_ptr->size - 1,key_ptr->data);

              a_buffer.push('=');
              a_buffer.push('"');

              string_s *value_ptr = (string_s *)it.get_location_value(tn_ptr->object.value)->v_data_ptr;
              xml_creator_s::append_string(value_ptr->data,value_ptr->size - 1,a_buffer);

              a_buffer.push('"');
            }
          } while(++tn_ptr < tn_ptr_end);
        }
      }

      // - self close tag if there is no content -
      if (node_ptr->conts->v_type == c_bi_class_blank)
      {
        a_buffer.push('/');
      }

      a_buffer.push('>');

      cs_elm.after_node = true;
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
          XML_CREATE_NICE_PUSH_TAB();

          bool cs_elm_after_node = cs_elm.after_node;
          cs_elm.after_node = true;

          create_stack.push_blank();
          create_stack.last().set(item_location->v_data_ptr,0,cs_elm_after_node);
        }
        else if (item_location->v_type == c_bi_class_string)
        {
          string_s *string_ptr = (string_s *)item_location->v_data_ptr;

          if (node_ptr->escape_texts)
          {
            xml_creator_s::append_string(string_ptr->data,string_ptr->size - 1,a_buffer);
          }
          else
          {
            a_buffer.append(string_ptr->size - 1,string_ptr->data);
          }

          cs_elm.after_node = false;
        }
        else
        {
          cassert(0);
        }

        continue;
      }
    }

    // - format node close tag -
    if (node_ptr->conts->v_type != c_bi_class_blank)
    {
      if (cs_elm.after_node && cs_elm.index > 0)
      {
        XML_CREATE_NICE_INDENT();
      }

      a_buffer.push('<');
      a_buffer.push('/');

      string_s *name_ptr = (string_s *)node_ptr->name->v_data_ptr;
      a_buffer.append(name_ptr->size - 1,name_ptr->data);

      a_buffer.push('>');
    }

    XML_CREATE_NICE_POP_TAB();

    create_stack.pop();

  } while(create_stack.used > 0);

  // - release create stack -
  create_stack.clear();

  // - release indent buffer -
  indent_buffer.clear();

  // - push terminating character to buffer -
  a_buffer.push('\0');
}/*}}}*/

/*
 * methods of structure xml_node_s
 */

void xml_node_s::add_node_to_node_dict(interpreter_thread_s &it,pointer_map_tree_s &a_tree,
    location_s *a_name,location_s *a_node)
{/*{{{*/

  // - push key and value locations to dictionary -
  pointer_map_s insert_map = {a_name,nullptr};
  unsigned index = a_tree.unique_insert(insert_map);
  cassert(((location_s *)it.exception_location)->v_type == c_bi_class_blank);

  pointer_map_s &map = a_tree.data[index].object;

  if (map.value)
  {
    location_s *value_location = (location_s *)map.value;

    if (value_location->v_type == c_bi_class_array)
    {
      pointer_array_s *array_ptr = (pointer_array_s *)value_location->v_data_ptr;

      a_node->v_reference_cnt.atomic_inc();
      array_ptr->push(a_node);
    }
    else if (value_location->v_type == c_bi_class_xml_node)
    {
      pointer_array_s *array_ptr = it.get_new_array_ptr();
      array_ptr->push(value_location);

      a_node->v_reference_cnt.atomic_inc();
      array_ptr->push(a_node);

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);

      map.value = new_location;
    }
    else
    {
      cassert(0);
    }
  }
  else
  {
    a_name->v_reference_cnt.atomic_inc();

    a_node->v_reference_cnt.atomic_inc();
    map.value = (pointer)a_node;
  }
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

// -- pointer_arrays_s --
@begin
methods pointer_arrays_s
@end

// -- sax_parser_s --
@begin
methods sax_parser_s
@end

location_s *sax_parser_s::get_string_location(unsigned a_length,const char *a_data)
{/*{{{*/
  interpreter_thread_s &it = *((interpreter_thread_s *)it_ptr);

  string_s tmp_string;
  tmp_string.size = a_length + 1;
  tmp_string.data = (char *)a_data;

  // - get constant position in tree -
  unsigned cs_idx = const_strings.unique_insert(tmp_string);

  if (cs_idx >= string_locations.used)
  {
    // - skip rb_tree indexes gap -
    while (cs_idx > string_locations.used)
    {
      string_locations.push(nullptr);
    }

    // - create location string copy -
    string_s *string_ptr = it.get_new_string_ptr();
    *string_ptr = const_strings[cs_idx];

    // - create new string location -
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
    string_locations.push(new_location);

    return new_location;
  }

  return (location_s *)string_locations[cs_idx];
}/*}}}*/

#if LIBXML_VERSION >= 21104
int sax_parser_s::sax_user_parse_memory(xmlSAXHandler *a_sax_handler,
    void *a_user_data,const char *a_data,int a_length)
{/*{{{*/
  if (!a_sax_handler || !a_data || a_length <= 0)
  {
      return -1;
  }

  // - create the parser context -
  xmlParserCtxtPtr ctxt = xmlCreatePushParserCtxt(a_sax_handler,a_user_data,nullptr,0,nullptr);
  if (!ctxt)
  {
      return -1;
  }

  // - feed xml data to the parser -
  int ret = xmlParseChunk(ctxt,a_data,a_length,0);
  if (ret != 0)
  {
      xmlFreeParserCtxt(ctxt);
      return ret;
  }

  // - finalize the parsing -
  ret = xmlParseChunk(ctxt,nullptr,0,1);
  if (ret != 0)
  {
      xmlFreeParserCtxt(ctxt);
      return ret;
  }

  xmlFreeParserCtxt(ctxt);

  return 0;
}/*}}}*/
#endif

void sax_parser_s::release_locations()
{/*{{{*/
  interpreter_thread_s &it = *((interpreter_thread_s *)it_ptr);

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

  // - release attributes stack -
  if (attrs_stack.used != 0)
  {
    pointer *as_ptr = attrs_stack.data;
    pointer *as_ptr_end = as_ptr + attrs_stack.used;
    do {
      it.release_location_ptr((location_s *)*as_ptr);
    } while(++as_ptr < as_ptr_end);
  }

  // - release node array stack -
  if (node_array_stack.used != 0)
  {
    pointer_array_s *na_ptr = node_array_stack.data;
    pointer_array_s *na_ptr_end = na_ptr + node_array_stack.used;
    do {

      // - release node array -
      if (na_ptr->used != 0)
      {
        pointer *n_ptr = na_ptr->data;
        pointer *n_ptr_end = n_ptr + na_ptr->used;
        do {
          it.release_location_ptr((location_s *)*n_ptr);
        } while(++n_ptr < n_ptr_end);
      }
    } while(++na_ptr < na_ptr_end);
  }

  // - release text array stack -
  if (text_array_stack.used != 0)
  {
    pointer_array_s *ta_ptr = text_array_stack.data;
    pointer_array_s *ta_ptr_end = ta_ptr + text_array_stack.used;
    do {

      // - release text array -
      if (ta_ptr->used != 0)
      {
        pointer *t_ptr = ta_ptr->data;
        pointer *t_ptr_end = t_ptr + ta_ptr->used;
        do {
          it.release_location_ptr((location_s *)*t_ptr);
        } while(++t_ptr < t_ptr_end);
      }
    } while(++ta_ptr < ta_ptr_end);
  }

  // - release content array stack -
  if (cont_array_stack.used != 0)
  {
    pointer_array_s *ca_ptr = cont_array_stack.data;
    pointer_array_s *ca_ptr_end = ca_ptr + cont_array_stack.used;
    do {

      // - release content array -
      if (ca_ptr->used != 0)
      {
        pointer *c_ptr = ca_ptr->data;
        pointer *c_ptr_end = c_ptr + ca_ptr->used;
        do {
          it.release_location_ptr((location_s *)*c_ptr);
        } while(++c_ptr < c_ptr_end);
      }
    } while(++ca_ptr < ca_ptr_end);
  }
}/*}}}*/

/*
 * global functions
 */

void xml_start_document(void *user)
{/*{{{*/
}/*}}}*/

void xml_end_document(void *user)
{/*{{{*/
}/*}}}*/

void xml_start_element(void *user,const xmlChar *name,const xmlChar **attrs)
{/*{{{*/
  sax_parser_s *sp = (sax_parser_s *)user;
  interpreter_thread_s &it = *((interpreter_thread_s *)sp->it_ptr);
  pointer_array_s &attrs_stack = sp->attrs_stack;
  pointer_arrays_s &node_array_stack = sp->node_array_stack;
  pointer_arrays_s &text_array_stack = sp->text_array_stack;
  pointer_arrays_s &cont_array_stack = sp->cont_array_stack;

  // -----

  if (attrs != nullptr)
  {
    // - process element attributes -
    pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)cmalloc(sizeof(pointer_map_tree_s));
    tree_ptr->init();

    tree_ptr->it_ptr = &it;
    tree_ptr->source_pos = 0;

    const char **attr_ptr = (const char **)attrs;
    while (*attr_ptr != nullptr)
    {
      location_s *attr_name = sp->get_string_location(strlen(attr_ptr[0]),attr_ptr[0]);
      location_s *attr_value = sp->get_string_location(strlen(attr_ptr[1]),attr_ptr[1]);

      // - increase value reference count -
      attr_value->v_reference_cnt.atomic_inc();

      // - search index of key location -
      pointer_map_s insert_map = {(pointer)attr_name,nullptr};
      unsigned index = tree_ptr->unique_insert(insert_map);
      cassert(((location_s *)it.exception_location)->v_type == c_bi_class_blank);

      pointer_map_s &map = tree_ptr->data[index].object;

      if (map.value)
      {
        it.release_location_ptr((location_s *)map.value);
      }
      else
      {
        attr_name->v_reference_cnt.atomic_inc();
      }

      map.value = (pointer)attr_value;

      attr_ptr += 2;
    }

    BIC_CREATE_NEW_LOCATION(new_location,c_rm_class_dict,tree_ptr);
    attrs_stack.push(new_location);
  }
  else
  {
    // - there are no attributes -
    ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();
    attrs_stack.push(it.blank_location);
  }

  // - push new node array -
  node_array_stack.push_blank();

  // - push new text array -
  text_array_stack.push_blank();

  // - push new content array -
  cont_array_stack.push_blank();
}/*}}}*/

void xml_end_element(void *user,const xmlChar *name)
{/*{{{*/
  sax_parser_s *sp = (sax_parser_s *)user;
  interpreter_thread_s &it = *((interpreter_thread_s *)sp->it_ptr);
  pointer_array_s &attrs_stack = sp->attrs_stack;
  pointer_arrays_s &node_array_stack = sp->node_array_stack;
  pointer_arrays_s &text_array_stack = sp->text_array_stack;
  pointer_arrays_s &cont_array_stack = sp->cont_array_stack;

  // -----

  xml_node_s *node_ptr = (xml_node_s *)cmalloc(sizeof(xml_node_s));
  node_ptr->init();

  // - set node name -
  node_ptr->name = sp->get_string_location(strlen((const char *)name),(const char *)name);
  node_ptr->name->v_reference_cnt.atomic_inc();

  // - set node attributes -
  node_ptr->attributes = (location_s *)attrs_stack.pop();

  // - set node dictionary -
  ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();
  node_ptr->node_dict = (location_s *)it.blank_location;

  // - retrieve node array -
  pointer_array_s &node_array = node_array_stack.pop();

  if (node_array.used != 0)
  {
    pointer_array_s *array_ptr = it.get_new_array_ptr();
    array_ptr->swap(node_array);

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
    node_ptr->nodes = new_location;
  }
  else
  {
    // - there are no nodes -
    ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();
    node_ptr->nodes = (location_s *)it.blank_location;
  }

  // - retrieve text array -
  pointer_array_s &text_array = text_array_stack.pop();

  if (text_array.used != 0)
  {
    pointer_array_s *array_ptr = it.get_new_array_ptr();
    array_ptr->swap(text_array);

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
    node_ptr->texts = new_location;
  }
  else
  {
    // - there are no texts -
    ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();
    node_ptr->texts = (location_s *)it.blank_location;
  }

  // - retrieve content array -
  pointer_array_s &cont_array = cont_array_stack.pop();

  if (cont_array.used != 0)
  {
    pointer_array_s *array_ptr = it.get_new_array_ptr();
    array_ptr->swap(cont_array);

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
    node_ptr->conts = new_location;
  }
  else
  {
    // - there is no content -
    ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();
    node_ptr->conts = (location_s *)it.blank_location;
  }

  // - push node to element and content arrays -
  BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_xml_node,node_ptr,2);
  node_array_stack.last().push(new_location);
  cont_array_stack.last().push(new_location);
}/*}}}*/

void xml_characters(void *user,const xmlChar *ch,int len)
{/*{{{*/
  sax_parser_s *sp = (sax_parser_s *)user;
  pointer_arrays_s &text_array_stack = sp->text_array_stack;
  pointer_arrays_s &cont_array_stack = sp->cont_array_stack;

  // -----

  if (text_array_stack.used != 0 && cont_array_stack.used != 0)
  {
    location_s *text_location = sp->get_string_location(len,(const char *)ch);
    text_location->v_reference_cnt.atomic_add(2);

    // - push text to text and content arrays -
    text_array_stack.last().push(text_location);
    cont_array_stack.last().push(text_location);
  }
}/*}}}*/

void xml_warning(void *user,const char *msg,...)
{/*{{{*/
}/*}}}*/

void xml_error(void *user,const char *msg,...)
{/*{{{*/
}/*}}}*/

void xml_fatal_error(void *user,const char *msg,...)
{/*{{{*/
}/*}}}*/

