
@begin
include "ucl_protobuf.h"
@end

// - indexes of remote classes -
unsigned c_rm_class_dict = c_idx_not_exist;

/*
 * methods of generated structures
 */

// -- ptr_loc_map_s --
@begin
methods ptr_loc_map_s
@end

// -- ptr_loc_map_tree_s --
@begin
methods ptr_loc_map_tree_s
@end

// -- bc_arrays_s --
@begin
methods bc_arrays_s
@end

/*
 * methods of structure proto_msg_descr_s
 */

void proto_msg_descr_s::update_string_map_enum(interpreter_thread_s &it,ProtobufCEnumDescriptor *descr)
{/*{{{*/
  if (descr->n_value_names != 0)
  {
    const ProtobufCEnumValueIndex *n_ptr = descr->values_by_name;
    const ProtobufCEnumValueIndex *n_ptr_end = n_ptr + descr->n_value_names;
    do {

      // - insert enum name to string map -
      ptr_loc_map_s insert_ptr_loc_map = {(void *)n_ptr->name,nullptr};
      unsigned ptr_loc_map_idx = string_location_map.unique_insert(insert_ptr_loc_map);

      ptr_loc_map_s &pointer_map = string_location_map[ptr_loc_map_idx];
      if (pointer_map.loc_value == nullptr)
      {
        string_s *string_ptr = it.get_new_string_ptr();
        string_ptr->set(strlen(n_ptr->name),n_ptr->name);

        BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
        pointer_map.loc_value = new_location;
      }

    } while(++n_ptr < n_ptr_end);
  }
}/*}}}*/

void proto_msg_descr_s::update_string_map_message(interpreter_thread_s &it,ProtobufCMessageDescriptor *descr)
{/*{{{*/
  if (descr->n_fields != 0)
  {
    const ProtobufCFieldDescriptor *f_ptr = descr->fields;
    const ProtobufCFieldDescriptor *f_ptr_end = f_ptr + descr->n_fields;
    do {

      // - insert field name to string map -
      ptr_loc_map_s insert_ptr_loc_map = {(void *)f_ptr->name,nullptr};
      unsigned ptr_loc_map_idx = string_location_map.unique_insert(insert_ptr_loc_map);

      ptr_loc_map_s &pointer_map = string_location_map[ptr_loc_map_idx];
      if (pointer_map.loc_value == nullptr)
      {
        string_s *string_ptr = it.get_new_string_ptr();
        string_ptr->set(strlen(f_ptr->name),f_ptr->name);

        BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
        pointer_map.loc_value = new_location;
      }

      // - recursive call on enums and messages -
      switch (f_ptr->type)
      {
	case PROTOBUF_C_TYPE_ENUM:
          update_string_map_enum(it,(ProtobufCEnumDescriptor *)f_ptr->descriptor);
          break;
	case PROTOBUF_C_TYPE_MESSAGE:
          update_string_map_message(it,(ProtobufCMessageDescriptor *)f_ptr->descriptor);
          break;
        default:
          break;
      }

    } while(++f_ptr < f_ptr_end);
  }
}/*}}}*/

bool proto_msg_descr_s::pack_message(interpreter_thread_s &it,ProtobufCMessageDescriptor *descr,
    pointer_map_tree_s *tree_ptr,bc_arrays_s &buffers,char *data)
{/*{{{*/
  descr->message_init((ProtobufCMessage *)data);

  if (descr->n_fields != 0)
  {
    const ProtobufCFieldDescriptor *f_ptr = descr->fields;
    const ProtobufCFieldDescriptor *f_ptr_end = f_ptr + descr->n_fields;
    do
    {
      // - retrieve field name from string map -
      ptr_loc_map_s search_ptr_loc_map = {(void *)f_ptr->name,nullptr};
      unsigned ptr_loc_map_idx = string_location_map.get_idx(search_ptr_loc_map);
      debug_assert(ptr_loc_map_idx != c_idx_not_exist);

      // - retrieve field value from dictionary -
      pointer_map_s search_map = {string_location_map[ptr_loc_map_idx].loc_value,nullptr};
      unsigned index = tree_ptr->get_idx(search_map);

      if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
      {
        return false;
      }

      location_s *value_location;
      pointer_array_s *array_ptr = nullptr;

      switch (f_ptr->label)
      {
	case PROTOBUF_C_LABEL_REQUIRED:
          {
            // - ERROR -
            if (index == c_idx_not_exist)
            {
              return false;
            }

            // - retrieve value location -
            value_location = it.get_location_value(tree_ptr->data[index].object.value);
          }
          break;
	case PROTOBUF_C_LABEL_OPTIONAL:
          {
            *((protobuf_c_boolean *)(data + f_ptr->quantifier_offset)) = index != c_idx_not_exist;

            // - skip non present optional value -
            if (index == c_idx_not_exist)
            {
              continue;
            }

            // - retrieve value location -
            value_location = it.get_location_value(tree_ptr->data[index].object.value);
          }
          break;
	case PROTOBUF_C_LABEL_REPEATED:
          {
            // - ERROR -
            if (index == c_idx_not_exist)
            {
              return false;
            }

            // - retrieve value location -
            value_location = it.get_location_value(tree_ptr->data[index].object.value);

            if (value_location->v_type != c_bi_class_array)
            {
              return false;
            }

            array_ptr = (pointer_array_s *)value_location->v_data_ptr;

            *((size_t *)(data + f_ptr->quantifier_offset)) = array_ptr->used;
          }
          break;

          // - ERROR -
          default:

            return false;
      }

#define PACK_MESSAGE_TYPE_INTEGER(TYPE) \
{/*{{{*/\
  if (array_ptr != nullptr)\
  {\
    if (array_ptr->used != 0)\
    {\
      buffers.push_blank();\
      bc_array_s &buffer = buffers.last();\
      buffer.copy_resize(array_ptr->used*sizeof(TYPE));\
\
      pointer *p_ptr = array_ptr->data;\
      pointer *p_ptr_end = p_ptr + array_ptr->used;\
      TYPE *ptr = (TYPE *)buffer.data;\
      do {\
        long long int value;\
\
        /* - ERROR - */\
        if (!it.retrieve_integer(it.get_location_value(*p_ptr),value))\
        {\
          return false;\
        }\
\
        *ptr++ = value;\
\
      } while(++p_ptr < p_ptr_end);\
\
      *((TYPE **)(data + f_ptr->offset)) = (TYPE *)buffer.data;\
    }\
  }\
  else\
  {\
    long long int value;\
\
    /* - ERROR - */\
    if (!it.retrieve_integer(value_location,value))\
    {\
      return false;\
    }\
\
    *((TYPE *)(data + f_ptr->offset)) = value;\
  }\
}/*}}}*/

#define PACK_MESSAGE_TYPE_FLOAT(TYPE) \
{/*{{{*/\
  if (array_ptr != nullptr)\
  {\
    if (array_ptr->used != 0)\
    {\
      buffers.push_blank();\
      bc_array_s &buffer = buffers.last();\
      buffer.copy_resize(array_ptr->used*sizeof(TYPE));\
\
      pointer *p_ptr = array_ptr->data;\
      pointer *p_ptr_end = p_ptr + array_ptr->used;\
      TYPE *ptr = (TYPE *)buffer.data;\
      do {\
        double value;\
\
        /* - ERROR - */\
        if (!it.retrieve_float(it.get_location_value(*p_ptr),value))\
        {\
          return false;\
        }\
\
        *ptr++ = value;\
\
      } while(++p_ptr < p_ptr_end);\
\
      *((TYPE **)(data + f_ptr->offset)) = (TYPE *)buffer.data;\
    }\
  }\
  else\
  {\
    double value;\
\
    /* - ERROR - */\
    if (!it.retrieve_float(value_location,value))\
    {\
      return false;\
    }\
\
    *((TYPE *)(data + f_ptr->offset)) = value;\
  }\
}/*}}}*/

#define PACK_MESSAGE_TYPE_BOOL(TYPE) \
{/*{{{*/\
  if (array_ptr != nullptr)\
  {\
    if (array_ptr->used != 0)\
    {\
      buffers.push_blank();\
      bc_array_s &buffer = buffers.last();\
      buffer.copy_resize(array_ptr->used*sizeof(TYPE));\
\
      pointer *p_ptr = array_ptr->data;\
      pointer *p_ptr_end = p_ptr + array_ptr->used;\
      TYPE *ptr = (TYPE *)buffer.data;\
      do {\
        long long int value;\
\
        /* - ERROR - */\
        if (!it.retrieve_integer(it.get_location_value(*p_ptr),value))\
        {\
          return false;\
        }\
\
        *ptr++ = value != 0;\
\
      } while(++p_ptr < p_ptr_end);\
\
      *((TYPE **)(data + f_ptr->offset)) = (TYPE *)buffer.data;\
    }\
  }\
  else\
  {\
    long long int value;\
\
    /* - ERROR - */\
    if (!it.retrieve_integer(value_location,value))\
    {\
      return false;\
    }\
\
    *((TYPE *)(data + f_ptr->offset)) = value != 0;\
  }\
}/*}}}*/

      switch (f_ptr->type)
      {
	case PROTOBUF_C_TYPE_INT32:
	case PROTOBUF_C_TYPE_SINT32:
	case PROTOBUF_C_TYPE_SFIXED32:
          PACK_MESSAGE_TYPE_INTEGER(int32_t);
          break;
	case PROTOBUF_C_TYPE_INT64:
	case PROTOBUF_C_TYPE_SINT64:
	case PROTOBUF_C_TYPE_SFIXED64:
          PACK_MESSAGE_TYPE_INTEGER(int64_t);
          break;
	case PROTOBUF_C_TYPE_UINT32:
	case PROTOBUF_C_TYPE_FIXED32:
          PACK_MESSAGE_TYPE_INTEGER(uint32_t);
          break;
	case PROTOBUF_C_TYPE_UINT64:
	case PROTOBUF_C_TYPE_FIXED64:
          PACK_MESSAGE_TYPE_INTEGER(uint64_t);
          break;
	case PROTOBUF_C_TYPE_FLOAT:
          PACK_MESSAGE_TYPE_FLOAT(float);
          break;
	case PROTOBUF_C_TYPE_DOUBLE:
          PACK_MESSAGE_TYPE_FLOAT(double);
          break;
	case PROTOBUF_C_TYPE_BOOL:
          PACK_MESSAGE_TYPE_BOOL(protobuf_c_boolean);
          break;
	case PROTOBUF_C_TYPE_ENUM:

          // FIXME TODO continue ...
          return false;
	case PROTOBUF_C_TYPE_STRING:
          {/*{{{*/
            if (array_ptr != nullptr)
            {
              if (array_ptr->used != 0)
              {
                buffers.push_blank();
                bc_array_s &buffer = buffers.last();
                buffer.copy_resize(array_ptr->used*sizeof(char *));

                pointer *p_ptr = array_ptr->data;
                pointer *p_ptr_end = p_ptr + array_ptr->used;
                char **ptr = (char **)buffer.data;
                do
                {
                  location_s *item_location = it.get_location_value(*p_ptr);

                  // - ERROR -
                  if (item_location->v_type != c_bi_class_string)
                  {
                    return false;
                  }

                  *ptr++ = ((string_s *)item_location->v_data_ptr)->data;

                } while(++p_ptr < p_ptr_end);

                *((char ***)(data + f_ptr->offset)) = (char **)buffer.data;
              }
            }
            else
            {
              // - ERROR -
              if (value_location->v_type != c_bi_class_string)
              {
                return false;
              }

              *((char **)(data + f_ptr->offset)) = ((string_s *)value_location->v_data_ptr)->data;
            }
          }/*}}}*/
          break;
	case PROTOBUF_C_TYPE_BYTES:
          {/*{{{*/
            if (array_ptr != nullptr)
            {
              if (array_ptr->used != 0)
              {
                buffers.push_blank();
                bc_array_s &buffer = buffers.last();
                buffer.copy_resize(array_ptr->used*sizeof(ProtobufCBinaryData));

                pointer *p_ptr = array_ptr->data;
                pointer *p_ptr_end = p_ptr + array_ptr->used;
                ProtobufCBinaryData *ptr = (ProtobufCBinaryData *)buffer.data;
                do
                {
                  const void *data_ptr;
                  unsigned data_size;

                  // - ERROR -
                  if (!it.retrieve_data_buffer(it.get_location_value(*p_ptr),data_ptr,data_size))
                  {
                    return false;
                  }

                  ptr->len = data_size;
                  ptr->data = (uint8_t *)data_ptr;

                } while(++ptr,++p_ptr < p_ptr_end);

                *((ProtobufCBinaryData **)(data + f_ptr->offset)) = (ProtobufCBinaryData *)buffer.data;
              }
            }
            else
            {
              const void *data_ptr;
              unsigned data_size;

              // - ERROR -
              if (!it.retrieve_data_buffer(value_location,data_ptr,data_size))
              {
                return false;
              }

              ProtobufCBinaryData *pb_bin = (ProtobufCBinaryData *)(data + f_ptr->offset);

              pb_bin->len = data_size;
              pb_bin->data = (uint8_t *)data_ptr;
            }
          }/*}}}*/
          break;
	case PROTOBUF_C_TYPE_MESSAGE:
          {/*{{{*/
            if (array_ptr != nullptr)
            {
              if (array_ptr->used != 0)
              {
                buffers.push_blank();
                bc_array_s &buffer = buffers.last();
                buffer.copy_resize(array_ptr->used*sizeof(char *));

                size_t sizeof_message = ((ProtobufCMessageDescriptor *)f_ptr->descriptor)->sizeof_message;

                // - create messages buffer -
                buffers.push_blank();
                bc_array_s &msgs_buffer = buffers.last();
                msgs_buffer.copy_resize(array_ptr->used*sizeof_message);

                pointer *p_ptr = array_ptr->data;
                pointer *p_ptr_end = p_ptr + array_ptr->used;
                char **d_ptr = (char **)buffer.data;
                char *m_ptr = msgs_buffer.data;
                do
                {
                  location_s *item_location = it.get_location_value(*p_ptr);

                  // - ERROR -
                  if (item_location->v_type != c_rm_class_dict)
                  {
                    return false;
                  }

                  // - retrieve dictionary -
                  pointer_map_tree_s *msg_tree_ptr = (pointer_map_tree_s *)item_location->v_data_ptr;

                  msg_tree_ptr->it_ptr = &it;
                  msg_tree_ptr->source_pos = tree_ptr->source_pos;

                  // - ERROR -
                  if (!pack_message(it,(ProtobufCMessageDescriptor *)f_ptr->descriptor,msg_tree_ptr,buffers,m_ptr))
                  {
                    return false;
                  }

                  *d_ptr++ = m_ptr;

                  // - advance to next message -
                  m_ptr += sizeof_message;

                } while(++p_ptr < p_ptr_end);

                *((char **)(data + f_ptr->offset)) = (char *)buffer.data;
              }
            }
            else
            {
              // - ERROR -
              if (value_location->v_type != c_rm_class_dict)
              {
                return false;
              }

              // - retrieve dictionary -
              pointer_map_tree_s *msg_tree_ptr = (pointer_map_tree_s *)value_location->v_data_ptr;

              msg_tree_ptr->it_ptr = &it;
              msg_tree_ptr->source_pos = tree_ptr->source_pos;

              // - create message buffer -
              buffers.push_blank();
              bc_array_s &buffer = buffers.last();
              buffer.copy_resize(((ProtobufCMessageDescriptor *)f_ptr->descriptor)->sizeof_message);

              // - ERROR -
              if (!pack_message(it,(ProtobufCMessageDescriptor *)f_ptr->descriptor,msg_tree_ptr,buffers,buffer.data))
              {
                return false;
              }

              *((char **)(data + f_ptr->offset)) = buffer.data;
            }
          }/*}}}*/
          break;
        default:

          // FIXME TODO continue ...
          return false;
      }
    } while(++f_ptr < f_ptr_end);
  }

  return true;
}/*}}}*/

bool proto_msg_descr_s::unpack_message(interpreter_thread_s &it,ProtobufCMessageDescriptor *descr,
    char *data,pointer_map_tree_s *tree_ptr)
{/*{{{*/
  if (descr->n_fields != 0)
  {
    const ProtobufCFieldDescriptor *f_ptr = descr->fields;
    const ProtobufCFieldDescriptor *f_ptr_end = f_ptr + descr->n_fields;
    do
    {
      pointer_array_s *array_ptr = nullptr;
      location_s *value_location = nullptr;

      switch (f_ptr->label)
      {
	case PROTOBUF_C_LABEL_REQUIRED:
          break;
	case PROTOBUF_C_LABEL_OPTIONAL:
          {
            // - skip non present optional value -
            if (!*((protobuf_c_boolean *)(data + f_ptr->quantifier_offset)))
            {
              continue;
            }
          }
          break;
	case PROTOBUF_C_LABEL_REPEATED:
          {
            array_ptr = it.get_new_array_ptr();
            array_ptr->copy_resize(*((size_t *)(data + f_ptr->quantifier_offset)));

            BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
            value_location = new_location;
          }
          break;

          // - ERROR -
          default:

            return false;
      }

#define UNPACK_MESSAGE_RELEASE() \
{/*{{{*/\
  if (value_location != nullptr)\
  {\
    it.release_location_ptr(value_location);\
  }\
}/*}}}*/

#define UNPACK_MESSAGE_TYPE_INTEGER(TYPE) \
{/*{{{*/\
  if (array_ptr != nullptr)\
  {\
    TYPE *ptr = *((TYPE **)(data + f_ptr->offset));\
    TYPE *ptr_end = ptr + array_ptr->size;\
    do {\
      long long int value = *ptr;\
\
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);\
      array_ptr->push(new_location);\
    } while(++ptr < ptr_end);\
  }\
  else\
  {\
    long long int value = *((TYPE *)(data + f_ptr->offset));\
    \
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);\
    value_location = new_location;\
  }\
}/*}}}*/

#define UNPACK_MESSAGE_TYPE_FLOAT(TYPE) \
{/*{{{*/\
  if (array_ptr != nullptr)\
  {\
    TYPE *ptr = *((TYPE **)(data + f_ptr->offset));\
    TYPE *ptr_end = ptr + array_ptr->size;\
    do {\
      double value = *ptr;\
\
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_float,value);\
      array_ptr->push(new_location);\
    } while(++ptr < ptr_end);\
  }\
  else\
  {\
    double value = *((TYPE *)(data + f_ptr->offset));\
    \
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_float,value);\
    value_location = new_location;\
  }\
}/*}}}*/

      switch (f_ptr->type)
      {
	case PROTOBUF_C_TYPE_INT32:
	case PROTOBUF_C_TYPE_SINT32:
	case PROTOBUF_C_TYPE_SFIXED32:
          UNPACK_MESSAGE_TYPE_INTEGER(int32_t);
          break;
	case PROTOBUF_C_TYPE_INT64:
	case PROTOBUF_C_TYPE_SINT64:
	case PROTOBUF_C_TYPE_SFIXED64:
          UNPACK_MESSAGE_TYPE_INTEGER(int64_t);
          break;
	case PROTOBUF_C_TYPE_UINT32:
	case PROTOBUF_C_TYPE_FIXED32:
          UNPACK_MESSAGE_TYPE_INTEGER(uint32_t);
          break;
	case PROTOBUF_C_TYPE_UINT64:
	case PROTOBUF_C_TYPE_FIXED64:
          UNPACK_MESSAGE_TYPE_INTEGER(uint64_t);
          break;
	case PROTOBUF_C_TYPE_FLOAT:
          UNPACK_MESSAGE_TYPE_FLOAT(float);
          break;
	case PROTOBUF_C_TYPE_DOUBLE:
          UNPACK_MESSAGE_TYPE_FLOAT(double);
          break;
	case PROTOBUF_C_TYPE_BOOL:
          UNPACK_MESSAGE_TYPE_INTEGER(protobuf_c_boolean);
          break;
	case PROTOBUF_C_TYPE_ENUM:

          // FIXME TODO continue ...
          UNPACK_MESSAGE_RELEASE();

          return false;
	case PROTOBUF_C_TYPE_STRING:
          {/*{{{*/
            if (array_ptr != nullptr)
            {
              char **ptr = *((char ***)(data + f_ptr->offset));
              char **ptr_end = ptr + array_ptr->size;
              do {
                char *value = *ptr;

                string_s *string_ptr = it.get_new_string_ptr();
                string_ptr->set(strlen(value),value);

                BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
                array_ptr->push(new_location);
              } while(++ptr < ptr_end);
            }
            else
            {
              char *value = *((char **)(data + f_ptr->offset));

              string_s *string_ptr = it.get_new_string_ptr();
              string_ptr->set(strlen(value),value);
              
              BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
              value_location = new_location;
            }
          }/*}}}*/
          break;
	case PROTOBUF_C_TYPE_BYTES:
          {/*{{{*/
            if (array_ptr != nullptr)
            {
              ProtobufCBinaryData *ptr = *((ProtobufCBinaryData **)(data + f_ptr->offset));
              ProtobufCBinaryData *ptr_end = ptr + array_ptr->size;
              do {
                string_s *string_ptr = it.get_new_string_ptr();
                string_ptr->set(ptr->len,(const char *)ptr->data);

                BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
                array_ptr->push(new_location);
              } while(++ptr < ptr_end);
            }
            else
            {
              ProtobufCBinaryData *pb_bin = (ProtobufCBinaryData *)(data + f_ptr->offset);

              string_s *string_ptr = it.get_new_string_ptr();
              string_ptr->set(pb_bin->len,(const char *)pb_bin->data);
              
              BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
              value_location = new_location;
            }
          }/*}}}*/
          break;
	case PROTOBUF_C_TYPE_MESSAGE:
          {/*{{{*/
            if (array_ptr != nullptr)
            {
              char **ptr = *((char ***)(data + f_ptr->offset));
              char **ptr_end = ptr + array_ptr->size;
              do
              {
                // - create dictionary -
                pointer_map_tree_s *msg_tree_ptr = (pointer_map_tree_s *)cmalloc(sizeof(pointer_map_tree_s));
                msg_tree_ptr->init();

                msg_tree_ptr->it_ptr = &it;
                msg_tree_ptr->source_pos = tree_ptr->source_pos;

                BIC_CREATE_NEW_LOCATION(new_location,c_rm_class_dict,msg_tree_ptr);
                array_ptr->push(new_location);

                // - ERROR -
                if (!unpack_message(it,(ProtobufCMessageDescriptor *)f_ptr->descriptor,
                      *ptr,msg_tree_ptr))
                {
                  UNPACK_MESSAGE_RELEASE();

                  return false;
                }

              } while(++ptr < ptr_end);
            }
            else
            {
              // - create dictionary -
              pointer_map_tree_s *msg_tree_ptr = (pointer_map_tree_s *)cmalloc(sizeof(pointer_map_tree_s));
              msg_tree_ptr->init();

              msg_tree_ptr->it_ptr = &it;
              msg_tree_ptr->source_pos = tree_ptr->source_pos;

              BIC_CREATE_NEW_LOCATION(new_location,c_rm_class_dict,msg_tree_ptr);
              value_location = new_location;

              // - ERROR -
              if (!unpack_message(it,(ProtobufCMessageDescriptor *)f_ptr->descriptor,
                    *((char **)(data + f_ptr->offset)),msg_tree_ptr))
              {
                UNPACK_MESSAGE_RELEASE();

                return false;
              }
            }
          }/*}}}*/
          break;
        default:

          // FIXME TODO continue ...
          UNPACK_MESSAGE_RELEASE();

          return false;
      }

      // - retrieve field name from string map -
      ptr_loc_map_s search_ptr_loc_map = {(void *)f_ptr->name,nullptr};
      unsigned ptr_loc_map_idx = string_location_map.get_idx(search_ptr_loc_map);
      debug_assert(ptr_loc_map_idx != c_idx_not_exist);

      // - retrieve name location -
      location_s *name_location = (location_s *)string_location_map[ptr_loc_map_idx].loc_value;

      // - insert field value to dictionary -
      pointer_map_s insert_map = {name_location,nullptr};
      unsigned index = tree_ptr->unique_insert(insert_map);

      if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
      {
        UNPACK_MESSAGE_RELEASE();

        return false;
      }

      pointer_map_s &map = tree_ptr->data[index].object;

      if (map.value != nullptr)
      {
        UNPACK_MESSAGE_RELEASE();

        return false;
      }

      // - increase name reference counter -
      name_location->v_reference_cnt.atomic_inc();
      
      // - update value pointer -
      map.value = (pointer)value_location;

    } while(++f_ptr < f_ptr_end);
  }

  return true;
}/*}}}*/

