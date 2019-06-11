
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

/*
 * definition of structure proto_source_s
 */

struct proto_source_s
{
  dynlib_s dynlib;

  inline void init();
  void clear(interpreter_thread_s &it);
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
  ptr_loc_map_tree_s string_location_map;

  ProtobufCMessageDescriptor *msg_descriptor;

  msg_init_t            msg_init;
  msg_get_packed_size_t msg_get_packed_size;
  msg_pack_t            msg_pack;
  msg_pack_to_buffer_t  msg_pack_to_buffer;
  msg_unpack_t          msg_unpack;
  msg_free_unpacked_t   msg_free_unpacked;

  inline void init();
  inline void clear(interpreter_thread_s &it);

  void update_string_map_enum(interpreter_thread_s &it,ProtobufCEnumDescriptor *descr);
  void update_string_map_message(interpreter_thread_s &it,ProtobufCMessageDescriptor *descr);

  bool pack_message(interpreter_thread_s &it,ProtobufCMessageDescriptor *descr,
      pointer_map_tree_s *tree_ptr,bc_arrays_s &buffers,char *data);
  bool unpack_message(interpreter_thread_s &it,ProtobufCMessageDescriptor *descr,
      char *data,pointer_map_tree_s *tree_ptr);
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

/*
 * inline methods of structure proto_source_s
 */

inline void proto_source_s::init()
{/*{{{*/
  dynlib.init();
}/*}}}*/

inline void proto_source_s::clear(interpreter_thread_s &it)
{/*{{{*/
  dynlib.clear();

  init();
}/*}}}*/

/*
 * inline methods of structure proto_msg_descr_s
 */

inline void proto_msg_descr_s::init()
{/*{{{*/
  source_loc = nullptr;
  string_location_map.init();
}/*}}}*/

inline void proto_msg_descr_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (source_loc != nullptr)
  {
    it.release_location_ptr(source_loc);
  }

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

  init();
}/*}}}*/

#endif

