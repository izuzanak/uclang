
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
    pointer_map_tree_s *tree_ptr,bc_arrays_s *buffers,char *data)
{/*{{{*/
  msg_init(data);

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

      switch (f_ptr->type)
      {
	case PROTOBUF_C_TYPE_INT32:
	case PROTOBUF_C_TYPE_SINT32:
	case PROTOBUF_C_TYPE_SFIXED32:
          {/*{{{*/
            if (array_ptr != nullptr)
            {
              // FIXME TODO continue ...
              return false;
            }
            else
            {
              long long int value;

              // - ERROR -
              if (!it.retrieve_integer(value_location,value))
              {
                return false;
              }

              *((int32_t *)(data + f_ptr->offset)) = value;
            }
          }/*}}}*/
          break;
	case PROTOBUF_C_TYPE_INT64:
	case PROTOBUF_C_TYPE_SINT64:
	case PROTOBUF_C_TYPE_SFIXED64:
	case PROTOBUF_C_TYPE_UINT32:
	case PROTOBUF_C_TYPE_FIXED32:
	case PROTOBUF_C_TYPE_UINT64:
	case PROTOBUF_C_TYPE_FIXED64:
	case PROTOBUF_C_TYPE_FLOAT:
	case PROTOBUF_C_TYPE_DOUBLE:
	case PROTOBUF_C_TYPE_BOOL:
	case PROTOBUF_C_TYPE_ENUM:
	case PROTOBUF_C_TYPE_STRING:
	case PROTOBUF_C_TYPE_BYTES:
	case PROTOBUF_C_TYPE_MESSAGE:

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

      switch (f_ptr->type)
      {
	case PROTOBUF_C_TYPE_INT32:
	case PROTOBUF_C_TYPE_SINT32:
	case PROTOBUF_C_TYPE_SFIXED32:
          {/*{{{*/
            if (array_ptr != nullptr)
            {
              // FIXME TODO continue ...
              UNPACK_MESSAGE_RELEASE();

              return false;
            }
            else
            {
              long long int value = *((int32_t *)(data + f_ptr->offset));
              
              BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);
              value_location = new_location;
            }
          }/*}}}*/
          break;
	case PROTOBUF_C_TYPE_INT64:
	case PROTOBUF_C_TYPE_SINT64:
	case PROTOBUF_C_TYPE_SFIXED64:
	case PROTOBUF_C_TYPE_UINT32:
	case PROTOBUF_C_TYPE_FIXED32:
	case PROTOBUF_C_TYPE_UINT64:
	case PROTOBUF_C_TYPE_FIXED64:
	case PROTOBUF_C_TYPE_FLOAT:
	case PROTOBUF_C_TYPE_DOUBLE:
	case PROTOBUF_C_TYPE_BOOL:
	case PROTOBUF_C_TYPE_ENUM:
	case PROTOBUF_C_TYPE_STRING:
	case PROTOBUF_C_TYPE_BYTES:
	case PROTOBUF_C_TYPE_MESSAGE:

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

