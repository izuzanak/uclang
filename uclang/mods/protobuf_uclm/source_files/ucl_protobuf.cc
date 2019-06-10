
@begin
include "ucl_protobuf.h"
@end

// - indexes of remote classes -
unsigned c_rm_class_dict = c_idx_not_exist;

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
      pointer_map_s insert_pointer_map = {(void *)n_ptr->name,nullptr};
      unsigned pointer_map_idx = string_location_map.unique_insert(insert_pointer_map);

      pointer_map_s &pointer_map = string_location_map[pointer_map_idx];
      if (pointer_map.value == nullptr)
      {
        string_s *string_ptr = it.get_new_string_ptr();
        string_ptr->set(strlen(n_ptr->name),n_ptr->name);

        BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
        pointer_map.value = new_location;
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
      pointer_map_s insert_pointer_map = {(void *)f_ptr->name,nullptr};
      unsigned pointer_map_idx = string_location_map.unique_insert(insert_pointer_map);

      pointer_map_s &pointer_map = string_location_map[pointer_map_idx];
      if (pointer_map.value == nullptr)
      {
        string_s *string_ptr = it.get_new_string_ptr();
        string_ptr->set(strlen(f_ptr->name),f_ptr->name);

        BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
        pointer_map.value = new_location;
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

