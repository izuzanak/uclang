
#ifndef __UCL_PROTOBUF_H
#define __UCL_PROTOBUF_H

@begin
include "script_parser.h"
@end

#include <protobuf-c/protobuf-c.h>

// - indexes of remote classes -
extern unsigned c_rm_class_dict;

/*
 * definition of generated structures
 */

// -- ptr_loc_map_s --
@begin
struct
<
pointer:key
pointer:loc_value
>
ptr_loc_map_s;
@end

// -- ptr_loc_map_tree_s --
@begin
safe_rb_tree<ptr_loc_map_s> ptr_loc_map_tree_s;
@end

// -- bc_arrays_s --
@begin
array<bc_array_s> bc_arrays_s;
@end

// -- proto_enum_s --
@begin
struct
<
pointer:descr
pointer_tree_s:name_tree
lli_rb_tree_s:lli_tree
>
proto_enum_s;
@end

// -- proto_enum_tree_s --
@begin
safe_rb_tree<proto_enum_s> proto_enum_tree_s;
@end

/*
 * definition of structure proto_source_s
 */

struct proto_source_s
{
  interpreter_thread_s *it_ptr;
  unsigned source_pos;

  dynlib_s dynlib;
  ptr_loc_map_tree_s string_location_map;
  proto_enum_tree_s enum_tree;

  inline void init();
  void clear(interpreter_thread_s &it);

  void update_init_descr_enum(interpreter_thread_s &it,ProtobufCEnumDescriptor *descr);
  void update_init_descr_message(interpreter_thread_s &it,ProtobufCMessageDescriptor *descr);

  bool pack_value(interpreter_thread_s &it,const ProtobufCFieldDescriptor *field_descr,
      bc_arrays_s &buffers,location_s *value_location,pointer_array_s *array_ptr,char *data);
  bool pack_message(interpreter_thread_s &it,ProtobufCMessageDescriptor *descr,
      pointer_map_tree_s *tree_ptr,bc_arrays_s &buffers,char *data);

  bool unpack_value(interpreter_thread_s &it,const ProtobufCFieldDescriptor *field_descr,
      location_s *&value_location,pointer_array_s *array_ptr,char *data);
  bool unpack_message(interpreter_thread_s &it,ProtobufCMessageDescriptor *descr,
      char *data,pointer_map_tree_s *tree_ptr);
};

/*
 * definition of structure proto_msg_descr_s
 */

// - types of protobuf message functions -
typedef void   (*msg_init_t)           (void *message);
typedef size_t (*msg_get_packed_size_t)(const void *message);
typedef size_t (*msg_pack_t)           (const void *message,uint8_t *out);
typedef size_t (*msg_pack_to_buffer_t) (const void *message,ProtobufCBuffer *buffer);
typedef void * (*msg_unpack_t)         (ProtobufCAllocator *allocator,size_t len,const uint8_t *data);
typedef void   (*msg_free_unpacked_t)  (void *message,ProtobufCAllocator *allocator);

struct proto_msg_descr_s
{
  location_s *source_loc;
  ProtobufCMessageDescriptor *msg_descriptor;

  msg_init_t            msg_init;
  msg_get_packed_size_t msg_get_packed_size;
  msg_pack_t            msg_pack;
  msg_pack_to_buffer_t  msg_pack_to_buffer;
  msg_unpack_t          msg_unpack;
  msg_free_unpacked_t   msg_free_unpacked;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of generated structures
 */

// -- ptr_loc_map_s --
@begin
inlines ptr_loc_map_s
@end

// -- ptr_loc_map_tree_s --
@begin
inlines ptr_loc_map_tree_s
@end

inline int ptr_loc_map_tree_s::__compare_value(ptr_loc_map_s &a_first,ptr_loc_map_s &a_second)
{/*{{{*/
  return a_first.key < a_second.key ? -1 : a_first.key > a_second.key ? 1 : 0;
}/*}}}*/

// -- bc_arrays_s --
@begin
inlines bc_arrays_s
@end

// -- proto_enum_s --
@begin
inlines proto_enum_s
@end

// -- proto_enum_tree_s --
@begin
inlines proto_enum_tree_s
@end

inline int proto_enum_tree_s::__compare_value(proto_enum_s &a_first,proto_enum_s &a_second)
{/*{{{*/
  return a_first.descr < a_second.descr ? -1 : a_first.descr > a_second.descr ? 1 : 0;
}/*}}}*/

/*
 * inline methods of structure proto_source_s
 */

inline void proto_source_s::init()
{/*{{{*/
  dynlib.init();
  string_location_map.init();
  enum_tree.init();
}/*}}}*/

inline void proto_source_s::clear(interpreter_thread_s &it)
{/*{{{*/
  dynlib.clear();

  // - release string locations -
  if (string_location_map.root_idx != c_idx_not_exist)
  {
    ptr_loc_map_tree_s_node *pmtn_ptr = string_location_map.data;
    ptr_loc_map_tree_s_node *pmtn_ptr_end = pmtn_ptr + string_location_map.used;
    do {
      if (pmtn_ptr->valid)
      {
        it.release_location_ptr((location_s *)pmtn_ptr->object.loc_value);
      }
    } while(++pmtn_ptr < pmtn_ptr_end);
  }

  string_location_map.clear();

  // - release enum locations -
  if (enum_tree.root_idx != c_idx_not_exist)
  {
    proto_enum_tree_s_node *petn_ptr = enum_tree.data;
    proto_enum_tree_s_node *petn_ptr_end = petn_ptr + enum_tree.used;
    do {
      if (petn_ptr->valid)
      {
        // - release enum value name locations -
        pointer_tree_s &name_tree = petn_ptr->object.name_tree;

        if (name_tree.root_idx != c_idx_not_exist)
        {
          pointer_tree_s_node *p_ptr = name_tree.data;
          pointer_tree_s_node *p_ptr_end = p_ptr + name_tree.used;
          do {
            if (p_ptr->valid)
            {
              it.release_location_ptr((location_s *)p_ptr->object);
            }
          } while(++p_ptr < p_ptr_end);
        }
      }
    } while(++petn_ptr < petn_ptr_end);
  }

  enum_tree.clear();

  init();
}/*}}}*/

/*
 * inline methods of structure proto_msg_descr_s
 */

inline void proto_msg_descr_s::init()
{/*{{{*/
  source_loc = nullptr;
}/*}}}*/

inline void proto_msg_descr_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (source_loc != nullptr)
  {
    it.release_location_ptr(source_loc);
  }

  init();
}/*}}}*/

#endif

