
@begin
include "ucl_xml.h"
@end

// - xml global init object -
xml_c g_xml;

/*
 * methods of generated structures
 */

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
      string_locations.push(NULL);
    }

    // - create location string copy -
    string_s *string_ptr = it.get_new_string_ptr();
    *string_ptr = const_strings[cs_idx];

    // - create new string location -
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
    string_locations.push(new_location);

    return new_location;
  }
  else
  {
    return (location_s *)string_locations[cs_idx];
  }
}/*}}}*/

void sax_parser_s::release_locations()
{/*{{{*/
  interpreter_thread_s &it = *((interpreter_thread_s *)it_ptr);

  // - release string locations -
  if (string_locations.used != 0)
  {
    pointer *sl_ptr = string_locations.data;
    pointer *sl_ptr_end = sl_ptr + string_locations.used;
    do {
      if (*sl_ptr != NULL)
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

  if (attrs != NULL)
  {
    // - process element attributes -
    pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)cmalloc(sizeof(pointer_map_tree_s));
    tree_ptr->init();

    tree_ptr->it_ptr = &it;
    tree_ptr->source_pos = 0;

    const char **attr_ptr = (const char **)attrs;
    while (*attr_ptr != NULL)
    {
      location_s *attr_name = sp->get_string_location(strlen(attr_ptr[0]),attr_ptr[0]);
      location_s *attr_value = sp->get_string_location(strlen(attr_ptr[1]),attr_ptr[1]);

      // - increase value reference count -
      attr_value->v_reference_cnt.atomic_inc();

      // - search index of key location -
      pointer_map_s insert_map = {(pointer)attr_name,NULL};
      unsigned index = tree_ptr->unique_insert(insert_map);
      cassert(((location_s *)it.exception_location)->v_type == c_bi_class_blank);

      pointer_map_s &map = tree_ptr->data[index].object;

      if (map.value)
      {
        // - release old value -
        it.release_location_ptr((location_s *)map.value);
      }
      else
      {
        // - key was used -
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
  pointer_arrays_s &node_array_stack = sp->node_array_stack;
  pointer_arrays_s &text_array_stack = sp->text_array_stack;
  pointer_arrays_s &cont_array_stack = sp->cont_array_stack;
  pointer_array_s &attrs_stack = sp->attrs_stack;

  // -----

  xml_node_s *node_ptr = (xml_node_s *)cmalloc(sizeof(xml_node_s));
  node_ptr->init();

  // - set node name -
  node_ptr->name = sp->get_string_location(strlen((const char *)name),(const char *)name);
  node_ptr->name->v_reference_cnt.atomic_inc();

  // - set node attributes -
  node_ptr->attributes = (location_s *)attrs_stack.pop();

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

  location_s *text_location = sp->get_string_location(len,(const char *)ch);
  text_location->v_reference_cnt.atomic_add(2);

  // - push text to text and content arrays -
  text_array_stack.last().push(text_location);
  cont_array_stack.last().push(text_location);
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

