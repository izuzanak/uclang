
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

// -- proto_enum_s --
@begin
methods proto_enum_s
@end

// -- proto_enum_tree_s --
@begin
methods proto_enum_tree_s
@end

/*
 * methods of structure proto_source_s
 */

void proto_source_s::update_init_descr_enum(interpreter_thread_s &it,ProtobufCEnumDescriptor *descr)
{/*{{{*/
  proto_enum_s proto_enum;
  proto_enum.init();

  proto_enum.descr = descr;

  unsigned index = enum_tree.get_idx(proto_enum);
  if (index == c_idx_not_exist)
  {
    if (descr->n_values != 0)
    {
      proto_enum.name_tree.it_ptr = it_ptr;
      proto_enum.name_tree.source_pos = source_pos;

      const ProtobufCEnumValue *n_ptr = descr->values;
      const ProtobufCEnumValue *n_ptr_end = n_ptr + descr->n_values;
      do {

        // - insert enum value name -
        string_s *string_ptr = it.get_new_string_ptr();
        string_ptr->set(strlen(n_ptr->name),n_ptr->name);

        BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
        proto_enum.name_tree.insert(new_location);

        // - insert enum value integer -
        proto_enum.lli_tree.insert(n_ptr->value);

      } while(++n_ptr < n_ptr_end);
    }

    // - insert enum to enum tree -
    enum_tree.swap_insert(proto_enum);
  }

  proto_enum.clear();
}/*}}}*/

void proto_source_s::update_init_descr_message(interpreter_thread_s &it,ProtobufCMessageDescriptor *descr)
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
          update_init_descr_enum(it,(ProtobufCEnumDescriptor *)f_ptr->descriptor);
          break;
	case PROTOBUF_C_TYPE_MESSAGE:
          update_init_descr_message(it,(ProtobufCMessageDescriptor *)f_ptr->descriptor);
          break;
        default:
          break;
      }

    } while(++f_ptr < f_ptr_end);
  }
}/*}}}*/

bool proto_source_s::pack_value(interpreter_thread_s &it,const ProtobufCFieldDescriptor *field_descr,
    bc_arrays_s &buffers,location_s *value_location,pointer_array_s *array_ptr,char *data)
{/*{{{*/

#define PACK_MESSAGE_TYPE_INTEGER(TYPE) \
{/*{{{*/\
  if (array_ptr != nullptr)\
  {\
    if (array_ptr->used != 0)\
    {\
      buffers.push_blank();\
      buffers.last().copy_resize(array_ptr->used*sizeof(TYPE));\
      char *buffer = buffers.last().data;\
\
      pointer *p_ptr = array_ptr->data;\
      pointer *p_ptr_end = p_ptr + array_ptr->used;\
      TYPE *ptr = (TYPE *)buffer;\
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
      *((TYPE **)(data + field_descr->offset)) = (TYPE *)buffer;\
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
    *((TYPE *)(data + field_descr->offset)) = value;\
  }\
}/*}}}*/

#define PACK_MESSAGE_TYPE_FLOAT(TYPE) \
{/*{{{*/\
  if (array_ptr != nullptr)\
  {\
    if (array_ptr->used != 0)\
    {\
      buffers.push_blank();\
      buffers.last().copy_resize(array_ptr->used*sizeof(TYPE));\
      char *buffer = buffers.last().data;\
\
      pointer *p_ptr = array_ptr->data;\
      pointer *p_ptr_end = p_ptr + array_ptr->used;\
      TYPE *ptr = (TYPE *)buffer;\
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
      *((TYPE **)(data + field_descr->offset)) = (TYPE *)buffer;\
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
    *((TYPE *)(data + field_descr->offset)) = value;\
  }\
}/*}}}*/

#define PACK_MESSAGE_TYPE_BOOL(TYPE) \
{/*{{{*/\
  if (array_ptr != nullptr)\
  {\
    if (array_ptr->used != 0)\
    {\
      buffers.push_blank();\
      buffers.last().copy_resize(array_ptr->used*sizeof(TYPE));\
      char *buffer = buffers.last().data;\
\
      pointer *p_ptr = array_ptr->data;\
      pointer *p_ptr_end = p_ptr + array_ptr->used;\
      TYPE *ptr = (TYPE *)buffer;\
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
      *((TYPE **)(data + field_descr->offset)) = (TYPE *)buffer;\
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
    *((TYPE *)(data + field_descr->offset)) = value != 0;\
  }\
}/*}}}*/

  switch (field_descr->type)
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
      {/*{{{*/
        proto_enum_s search_proto_enum = {(pointer)field_descr->descriptor,};
        unsigned proto_enum_idx = enum_tree.get_idx(search_proto_enum);

        // - ERROR -
        if (proto_enum_idx == c_idx_not_exist)
        {
          return false;
        }

        proto_enum_s &proto_enum = enum_tree[proto_enum_idx];

        proto_enum.name_tree.it_ptr = it_ptr;
        proto_enum.name_tree.source_pos = source_pos;

        if (array_ptr != nullptr)
        {
          if (array_ptr->used != 0)
          {
            buffers.push_blank();
            buffers.last().copy_resize(array_ptr->used*sizeof(int32_t));
            char *buffer = buffers.last().data;

            pointer *p_ptr = array_ptr->data;
            pointer *p_ptr_end = p_ptr + array_ptr->used;
            int32_t *ptr = (int32_t *)buffer;
            do {
              unsigned enum_value_idx = proto_enum.name_tree.get_idx(*p_ptr);

              if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
              {
                return false;
              }

              // - ERROR -
              if (enum_value_idx == c_idx_not_exist)
              {
                return false;
              }

              *ptr++ = proto_enum.lli_tree[enum_value_idx];

            } while(++p_ptr < p_ptr_end);

            *((int32_t **)(data + field_descr->offset)) = (int32_t *)buffer;
          }
        }
        else
        {
          unsigned enum_value_idx = proto_enum.name_tree.get_idx(value_location);

          if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
          {
            return false;
          }

          // - ERROR -
          if (enum_value_idx == c_idx_not_exist)
          {
            return false;
          }

          *((int32_t *)(data + field_descr->offset)) = proto_enum.lli_tree[enum_value_idx];
        }
      }/*}}}*/
      break;
    case PROTOBUF_C_TYPE_STRING:
      {/*{{{*/
        if (array_ptr != nullptr)
        {
          if (array_ptr->used != 0)
          {
            buffers.push_blank();
            buffers.last().copy_resize(array_ptr->used*sizeof(char *));
            char *buffer = buffers.last().data;

            pointer *p_ptr = array_ptr->data;
            pointer *p_ptr_end = p_ptr + array_ptr->used;
            char **ptr = (char **)buffer;
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

            *((char ***)(data + field_descr->offset)) = (char **)buffer;
          }
        }
        else
        {
          // - ERROR -
          if (value_location->v_type != c_bi_class_string)
          {
            return false;
          }

          *((char **)(data + field_descr->offset)) = ((string_s *)value_location->v_data_ptr)->data;
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
            buffers.last().copy_resize(array_ptr->used*sizeof(ProtobufCBinaryData));
            char *buffer = buffers.last().data;

            pointer *p_ptr = array_ptr->data;
            pointer *p_ptr_end = p_ptr + array_ptr->used;
            ProtobufCBinaryData *ptr = (ProtobufCBinaryData *)buffer;
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

            *((ProtobufCBinaryData **)(data + field_descr->offset)) = (ProtobufCBinaryData *)buffer;
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

          ProtobufCBinaryData *pb_bin = (ProtobufCBinaryData *)(data + field_descr->offset);

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
            buffers.last().copy_resize(array_ptr->used*sizeof(char *));
            char *buffer = buffers.last().data;

            size_t sizeof_message = ((ProtobufCMessageDescriptor *)field_descr->descriptor)->sizeof_message;

            // - create messages buffer -
            buffers.push_blank();
            buffers.last().copy_resize(array_ptr->used*sizeof_message);
            char *msgs_buffer = buffers.last().data;

            pointer *p_ptr = array_ptr->data;
            pointer *p_ptr_end = p_ptr + array_ptr->used;
            char **d_ptr = (char **)buffer;
            char *m_ptr = msgs_buffer;
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

              msg_tree_ptr->it_ptr = it_ptr;
              msg_tree_ptr->source_pos = source_pos;

              // - ERROR -
              if (!pack_message(it,(ProtobufCMessageDescriptor *)field_descr->descriptor,msg_tree_ptr,buffers,m_ptr))
              {
                return false;
              }

              *d_ptr++ = m_ptr;

              // - advance to next message -
              m_ptr += sizeof_message;

            } while(++p_ptr < p_ptr_end);

            *((char **)(data + field_descr->offset)) = (char *)buffer;
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

          msg_tree_ptr->it_ptr = it_ptr;
          msg_tree_ptr->source_pos = source_pos;

          // - create message buffer -
          buffers.push_blank();
          buffers.last().copy_resize(((ProtobufCMessageDescriptor *)field_descr->descriptor)->sizeof_message);
          char *buffer = buffers.last().data;

          // - ERROR -
          if (!pack_message(it,(ProtobufCMessageDescriptor *)field_descr->descriptor,msg_tree_ptr,buffers,buffer))
          {
            return false;
          }

          *((char **)(data + field_descr->offset)) = buffer;
        }
      }/*}}}*/
      break;

    // - ERROR -
    default:

      return false;
  }

  return true;
}/*}}}*/

bool proto_source_s::pack_message(interpreter_thread_s &it,ProtobufCMessageDescriptor *descr,
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
          {/*{{{*/

            // - ERROR -
            if (index == c_idx_not_exist)
            {
              return false;
            }

            // - retrieve value location -
            value_location = it.get_location_value(tree_ptr->data[index].object.value);
          }/*}}}*/
          break;
	case PROTOBUF_C_LABEL_OPTIONAL:
          {/*{{{*/

            // - skip non present optional value -
            if (index == c_idx_not_exist)
            {
              continue;
            }

            if (f_ptr->flags & PROTOBUF_C_FIELD_FLAG_ONEOF)
            {
              uint32_t &oneof_case = *((uint32_t *)(data + f_ptr->quantifier_offset));

              // - ERROR -
              if (oneof_case != 0)
              {
                return false;
              }

              // - set oneof case to field id -
              oneof_case = f_ptr->id;
            }
            else
            {
              if (f_ptr->type != PROTOBUF_C_TYPE_STRING &&
                  f_ptr->type != PROTOBUF_C_TYPE_MESSAGE)
              {
                // - set optional boolean flag -
                *((protobuf_c_boolean *)(data + f_ptr->quantifier_offset)) = true;
              }
            }

            // - retrieve value location -
            value_location = it.get_location_value(tree_ptr->data[index].object.value);
          }/*}}}*/
          break;
	case PROTOBUF_C_LABEL_REPEATED:
          {/*{{{*/

            // - ERROR -
            if (index == c_idx_not_exist)
            {
              return false;
            }

            // - retrieve value location -
            value_location = it.get_location_value(tree_ptr->data[index].object.value);

            // - detect map -
            if (f_ptr->type == PROTOBUF_C_TYPE_MESSAGE &&
                ((ProtobufCMessageDescriptor *)f_ptr->descriptor)->n_fields == 2)
            {
              const ProtobufCMessageDescriptor *msg_descr = (ProtobufCMessageDescriptor *)f_ptr->descriptor;
              const ProtobufCFieldDescriptor *msg_field_descrs = msg_descr->fields;

              if (strcmp(msg_field_descrs[0].name,"key") == 0 &&
                  strcmp(msg_field_descrs[1].name,"value") == 0)
              {
                // - retrieve dictionary for map -
                if (value_location->v_type != c_rm_class_dict)
                {
                  return false;
                }

                pointer_map_tree_s *dict_tree_ptr = (pointer_map_tree_s *)value_location->v_data_ptr;

                dict_tree_ptr->it_ptr = it_ptr;
                dict_tree_ptr->source_pos = source_pos;

                if (dict_tree_ptr->root_idx != c_idx_not_exist)
                {
                  buffers.push_blank();
                  buffers.last().copy_resize(dict_tree_ptr->count*sizeof(char *));
                  char *buffer = buffers.last().data;

                  // - create messages buffer -
                  buffers.push_blank();
                  buffers.last().copy_resize(dict_tree_ptr->count*msg_descr->sizeof_message);
                  char *msgs_buffer = buffers.last().data;

                  pointer_map_tree_s_node *pmtn_ptr = dict_tree_ptr->data;
                  pointer_map_tree_s_node *pmtn_ptr_end = pmtn_ptr + dict_tree_ptr->used;
                  char **d_ptr = (char **)buffer;
                  char *m_ptr = msgs_buffer;
                  do {
                    if (pmtn_ptr->valid)
                    {
                      // - init map entry message -
                      msg_descr->message_init((ProtobufCMessage *)m_ptr);

                      // - set has_key flag if needed -
                      if (msg_field_descrs->quantifier_offset != 0)
                      {
                        *((protobuf_c_boolean *)(m_ptr + msg_field_descrs->quantifier_offset)) = 1;
                      }

                      location_s *key_location = (location_s *)pmtn_ptr->object.key;

                      // - ERROR -
                      if (!pack_value(it,msg_field_descrs,buffers,key_location,nullptr,m_ptr))
                      {
                        return false;
                      }

                      // - set has_value flag if needed -
                      if ((msg_field_descrs + 1)->quantifier_offset != 0)
                      {
                        *((protobuf_c_boolean *)(m_ptr + (msg_field_descrs + 1)->quantifier_offset)) = 1;
                      }

                      location_s *item_location = it.get_location_value(pmtn_ptr->object.value);

                      // - ERROR -
                      if (!pack_value(it,msg_field_descrs + 1,buffers,item_location,nullptr,m_ptr))
                      {
                        return false;
                      }

                      *d_ptr++ = m_ptr;

                      // - advance to next message -
                      m_ptr += msg_descr->sizeof_message;
                    }
                  } while(++pmtn_ptr < pmtn_ptr_end);

                  *((char **)(data + f_ptr->offset)) = (char *)buffer;
                }

                *((size_t *)(data + f_ptr->quantifier_offset)) = dict_tree_ptr->count;

                continue;
              }
            }

            // - retrieve array for repeated field -
            if (value_location->v_type != c_bi_class_array)
            {
              return false;
            }

            array_ptr = (pointer_array_s *)value_location->v_data_ptr;

            *((size_t *)(data + f_ptr->quantifier_offset)) = array_ptr->used;
          }/*}}}*/
          break;

          // - ERROR -
          default:

            return false;
      }

      // - pack single field -
      if (!pack_value(it,f_ptr,buffers,value_location,array_ptr,data))
      {
        return false;
      }

    } while(++f_ptr < f_ptr_end);
  }

  return true;
}/*}}}*/

bool proto_source_s::unpack_value(interpreter_thread_s &it,const ProtobufCFieldDescriptor *field_descr,
    location_s *&value_location,pointer_array_s *array_ptr,char *data)
{/*{{{*/

#define UNPACK_MESSAGE_TYPE_INTEGER(TYPE) \
{/*{{{*/\
  if (array_ptr != nullptr)\
  {\
    TYPE *ptr = *((TYPE **)(data + field_descr->offset));\
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
    long long int value = *((TYPE *)(data + field_descr->offset));\
    \
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);\
    value_location = new_location;\
  }\
}/*}}}*/

#define UNPACK_MESSAGE_TYPE_FLOAT(TYPE) \
{/*{{{*/\
  if (array_ptr != nullptr)\
  {\
    TYPE *ptr = *((TYPE **)(data + field_descr->offset));\
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
    double value = *((TYPE *)(data + field_descr->offset));\
    \
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_float,value);\
    value_location = new_location;\
  }\
}/*}}}*/

      switch (field_descr->type)
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
          {/*{{{*/
            proto_enum_s search_proto_enum = {(pointer)field_descr->descriptor,};
            unsigned proto_enum_idx = enum_tree.get_idx(search_proto_enum);

            // - ERROR -
            if (proto_enum_idx == c_idx_not_exist)
            {
              return false;
            }

            proto_enum_s &proto_enum = enum_tree[proto_enum_idx];

            if (array_ptr != nullptr)
            {
              int32_t *ptr = *((int32_t **)(data + field_descr->offset));
              int32_t *ptr_end = ptr + array_ptr->size;
              do {
                unsigned enum_value_idx = proto_enum.lli_tree.get_idx(*ptr);

                location_s *name_location = (location_s *)proto_enum.name_tree[enum_value_idx];
                name_location->v_reference_cnt.atomic_inc();

                array_ptr->push(name_location);
              } while(++ptr < ptr_end);
            }
            else
            {
              long long int value = *((int32_t *)(data + field_descr->offset));

              unsigned enum_value_idx = proto_enum.lli_tree.get_idx(value);

              value_location = (location_s *)proto_enum.name_tree[enum_value_idx];
              value_location->v_reference_cnt.atomic_inc();
            }
          }/*}}}*/
          break;
	case PROTOBUF_C_TYPE_STRING:
          {/*{{{*/
            if (array_ptr != nullptr)
            {
              char **ptr = *((char ***)(data + field_descr->offset));
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
              char *value = *((char **)(data + field_descr->offset));

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
              ProtobufCBinaryData *ptr = *((ProtobufCBinaryData **)(data + field_descr->offset));
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
              ProtobufCBinaryData *pb_bin = (ProtobufCBinaryData *)(data + field_descr->offset);

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
              char **ptr = *((char ***)(data + field_descr->offset));
              char **ptr_end = ptr + array_ptr->size;
              do
              {
                // - create dictionary -
                pointer_map_tree_s *msg_tree_ptr = (pointer_map_tree_s *)cmalloc(sizeof(pointer_map_tree_s));
                msg_tree_ptr->init();

                msg_tree_ptr->it_ptr = it_ptr;
                msg_tree_ptr->source_pos = source_pos;

                BIC_CREATE_NEW_LOCATION(new_location,c_rm_class_dict,msg_tree_ptr);
                array_ptr->push(new_location);

                // - ERROR -
                if (!unpack_message(it,(ProtobufCMessageDescriptor *)field_descr->descriptor,
                      *ptr,msg_tree_ptr))
                {
                  return false;
                }

              } while(++ptr < ptr_end);
            }
            else
            {
              // - create dictionary -
              pointer_map_tree_s *msg_tree_ptr = (pointer_map_tree_s *)cmalloc(sizeof(pointer_map_tree_s));
              msg_tree_ptr->init();

              msg_tree_ptr->it_ptr = it_ptr;
              msg_tree_ptr->source_pos = source_pos;

              BIC_CREATE_NEW_LOCATION(new_location,c_rm_class_dict,msg_tree_ptr);
              value_location = new_location;

              // - ERROR -
              if (!unpack_message(it,(ProtobufCMessageDescriptor *)field_descr->descriptor,
                    *((char **)(data + field_descr->offset)),msg_tree_ptr))
              {
                return false;
              }
            }
          }/*}}}*/
          break;

        // - ERROR -
        default:

          return false;
      }

  return true;
}/*}}}*/

bool proto_source_s::unpack_message(interpreter_thread_s &it,ProtobufCMessageDescriptor *descr,
    char *data,pointer_map_tree_s *tree_ptr)
{/*{{{*/

#define UNPACK_MESSAGE_RELEASE() \
{/*{{{*/\
  if (value_location != nullptr)\
  {\
    it.release_location_ptr(value_location);\
  }\
}/*}}}*/

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
          {/*{{{*/

            // - unpack single field -
            if (!unpack_value(it,f_ptr,value_location,array_ptr,data))
            {
              UNPACK_MESSAGE_RELEASE();

              return false;
            }
          }/*}}}*/
          break;
	case PROTOBUF_C_LABEL_OPTIONAL:
          {/*{{{*/
            if (f_ptr->flags & PROTOBUF_C_FIELD_FLAG_ONEOF)
            {
              // - skip non present optional oneof value -
              if (*((uint32_t *)(data + f_ptr->quantifier_offset)) != f_ptr->id)
              {
                continue;
              }
            }
            else
            {
              if (f_ptr->type != PROTOBUF_C_TYPE_STRING &&
                  f_ptr->type != PROTOBUF_C_TYPE_MESSAGE)
              {
                // - skip non present optional value -
                if (!*((protobuf_c_boolean *)(data + f_ptr->quantifier_offset)))
                {
                  continue;
                }
              }
              else
              {
                // - skip non present optional value -
                if (*((void **)(data + f_ptr->offset)) == nullptr)
                {
                  continue;
                }
              }
            }

            // - unpack single field -
            if (!unpack_value(it,f_ptr,value_location,array_ptr,data))
            {
              UNPACK_MESSAGE_RELEASE();

              return false;
            }
          }/*}}}*/
          break;
	case PROTOBUF_C_LABEL_REPEATED:
          {/*{{{*/

            // - detect map -
            if (f_ptr->type == PROTOBUF_C_TYPE_MESSAGE &&
                ((ProtobufCMessageDescriptor *)f_ptr->descriptor)->n_fields == 2)
            {
              const ProtobufCMessageDescriptor *msg_descr = (ProtobufCMessageDescriptor *)f_ptr->descriptor;
              const ProtobufCFieldDescriptor *msg_field_descrs = msg_descr->fields;

              if (strcmp(msg_field_descrs[0].name,"key") == 0 &&
                  strcmp(msg_field_descrs[1].name,"value") == 0)
              {
                // - create dictionary -
                pointer_map_tree_s *dict_tree_ptr = (pointer_map_tree_s *)cmalloc(sizeof(pointer_map_tree_s));
                dict_tree_ptr->init();

                dict_tree_ptr->it_ptr = it_ptr;
                dict_tree_ptr->source_pos = source_pos;

                BIC_CREATE_NEW_LOCATION(new_location,c_rm_class_dict,dict_tree_ptr);
                value_location = new_location;

                size_t map_size = *((size_t *)(data + f_ptr->quantifier_offset));

                if (map_size > 0)
                {
                  char **ptr = *((char ***)(data + f_ptr->offset));
                  char **ptr_end = ptr + map_size;
                  do {
                    location_s *key_location = nullptr;
                    location_s *item_location = nullptr;

                    // - ERROR -
                    if (!unpack_value(it,msg_field_descrs,key_location,nullptr,*ptr))
                    {
                      UNPACK_MESSAGE_RELEASE();

                      return false;
                    }

                    // - ERROR -
                    if (!unpack_value(it,msg_field_descrs + 1,item_location,nullptr,*ptr))
                    {
                      it.release_location_ptr(key_location);

                      UNPACK_MESSAGE_RELEASE();

                      return false;
                    }

                    // - insert key value pair to dictionary -
                    pointer_map_s insert_map = {key_location,nullptr};
                    unsigned index = dict_tree_ptr->unique_insert(insert_map);

                    if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
                    {
                      it.release_location_ptr(key_location);
                      it.release_location_ptr(item_location);

                      UNPACK_MESSAGE_RELEASE();

                      return false;
                    }

                    pointer_map_s &map = dict_tree_ptr->data[index].object;

                    if (map.value != nullptr)
                    {
                      it.release_location_ptr(key_location);
                      it.release_location_ptr(item_location);

                      UNPACK_MESSAGE_RELEASE();

                      return false;
                    }

                    // - update value pointer -
                    map.value = (pointer)item_location;

                  } while(++ptr < ptr_end);
                }

                break;
              }
            }

            size_t quantity = *((size_t *)(data + f_ptr->quantifier_offset));

            // - create array location -
            array_ptr = it.get_new_array_ptr();
            array_ptr->copy_resize(quantity);

            BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
            value_location = new_location;

            if (quantity != 0)
            {
              // - unpack single field -
              if (!unpack_value(it,f_ptr,value_location,array_ptr,data))
              {
                UNPACK_MESSAGE_RELEASE();

                return false;
              }
            }
          }/*}}}*/
          break;

          // - ERROR -
          default:

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

