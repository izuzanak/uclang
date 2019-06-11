
@begin
include "protobuf_module.h"
@end

// - PROTOBUF indexes of built in classes -
unsigned c_bi_class_proto_source = c_idx_not_exist;
unsigned c_bi_class_proto_msg_descr = c_idx_not_exist;

// - PROTOBUF module -
EXPORT built_in_module_s module =
{/*{{{*/
  2,                        // Class count
  protobuf_classes,         // Classes

  0,                        // Error base index
  1,                        // Error count
  protobuf_error_strings,   // Error strings

  protobuf_initialize,      // Initialize function
  protobuf_print_exception, // Print exceptions function
};/*}}}*/

// - PROTOBUF classes -
built_in_class_s *protobuf_classes[] =
{/*{{{*/
  &proto_source_class,
  &proto_msg_descr_class,
};/*}}}*/

// - PROTOBUF error strings -
const char *protobuf_error_strings[] =
{/*{{{*/
  "error_PROTOBUF_DUMMY_ERROR",
};/*}}}*/

// - PROTOBUF initialize -
bool protobuf_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize proto_source class identifier -
  c_bi_class_proto_source = class_base_idx++;

  // - initialize proto_msg_descr class identifier -
  c_bi_class_proto_msg_descr = class_base_idx++;

  // - retrieve remote dict class index -
  c_rm_class_dict = sp.resolve_class_idx_by_name("Dict",c_idx_not_exist);

  // - ERROR -
  if (c_rm_class_dict == c_idx_not_exist)
  {
    sp.error_code.push(ei_module_cannot_find_remote_class);
    sp.error_code.push(sp.module_names_positions[sp.module_idx].ui_first);
    sp.error_code.push(sp.module_idx);

    return false;
  }

  return true;
}/*}}}*/

// - PROTOBUF print exception -
bool protobuf_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_PROTOBUF_DUMMY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nProtobuf dummy error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class PROTO_SOURCE -
built_in_class_s proto_source_class =
{/*{{{*/
  "ProtoSource",
  c_modifier_public | c_modifier_final,
  5, proto_source_methods,
  0, proto_source_variables,
  bic_proto_source_consts,
  bic_proto_source_init,
  bic_proto_source_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s proto_source_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_proto_source_operator_binary_equal
  },
  {
    "ProtoSource#1",
    c_modifier_public | c_modifier_final,
    bic_proto_source_method_ProtoSource_1
  },
  {
    "msg_descr#1",
    c_modifier_public | c_modifier_final,
    bic_proto_source_method_msg_descr_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_proto_source_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_proto_source_method_print_0
  },
};/*}}}*/

built_in_variable_s proto_source_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_proto_source_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_proto_source_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (proto_source_s *)nullptr;
}/*}}}*/

void bic_proto_source_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  proto_source_s *ps_ptr = (proto_source_s *)location_ptr->v_data_ptr;

  if (ps_ptr != nullptr)
  {
    ps_ptr->clear(it);
    cfree(ps_ptr);
  }
}/*}}}*/

bool bic_proto_source_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_proto_source_method_ProtoSource_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
file:c_bi_class_string
>
method ProtoSource
; @end

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create proto_source object -
  proto_source_s *ps_ptr = (proto_source_s *)cmalloc(sizeof(proto_source_s));
  ps_ptr->init();

  // - ERROR -
  if (!ps_ptr->dynlib.open(string_ptr->data,0))
  {
    //fprintf(stderr,"DL ERROR: %s\n",ps_ptr->dynlib.get_error());

    ps_ptr->clear(it);
    cfree(ps_ptr);

    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  dst_location->v_data_ptr = (proto_source_s *)ps_ptr;

  return true;
}/*}}}*/

bool bic_proto_source_method_msg_descr_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
name:c_bi_class_string
>
method msg_descr
; @end

  proto_source_s *ps_ptr = (proto_source_s *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  const int buffer_size = 256;
  char buffer[buffer_size];
 
  // - create proto_msg_descr object -
  proto_msg_descr_s *pmd_ptr = (proto_msg_descr_s *)cmalloc(sizeof(proto_msg_descr_s));
  pmd_ptr->init();

#define BIC_PROTO_SOURCE_METHOD_MSG_DESCR_GET_SYMBOL(TYPE,SYM_SUFFIX) \
{/*{{{*/\
\
  /* - ERROR - */\
  if (snprintf(buffer,buffer_size,"%s__" #SYM_SUFFIX,string_ptr->data) >= buffer_size)\
  {\
    pmd_ptr->clear(it);\
    cfree(pmd_ptr);\
\
    /* FIXME TODO throw proper exception */\
    BIC_TODO_ERROR(__FILE__,__LINE__);\
    return false;\
  }\
\
  /* - ERROR - */\
  void *address;\
  if (!ps_ptr->dynlib.get_symbol_addr(buffer,&address))\
  {\
    pmd_ptr->clear(it);\
    cfree(pmd_ptr);\
\
    /* FIXME TODO throw proper exception */\
    BIC_TODO_ERROR(__FILE__,__LINE__);\
    return false;\
  }\
\
  /* - store message descriptor - */\
  pmd_ptr->msg_ ## SYM_SUFFIX = (TYPE)address;\
}/*}}}*/

  BIC_PROTO_SOURCE_METHOD_MSG_DESCR_GET_SYMBOL(ProtobufCMessageDescriptor *,descriptor);

  BIC_PROTO_SOURCE_METHOD_MSG_DESCR_GET_SYMBOL(msg_init_t,init);
  BIC_PROTO_SOURCE_METHOD_MSG_DESCR_GET_SYMBOL(msg_get_packed_size_t,get_packed_size);
  BIC_PROTO_SOURCE_METHOD_MSG_DESCR_GET_SYMBOL(msg_pack_t,pack);
  BIC_PROTO_SOURCE_METHOD_MSG_DESCR_GET_SYMBOL(msg_pack_to_buffer_t,pack_to_buffer);
  BIC_PROTO_SOURCE_METHOD_MSG_DESCR_GET_SYMBOL(msg_unpack_t,unpack);
  BIC_PROTO_SOURCE_METHOD_MSG_DESCR_GET_SYMBOL(msg_free_unpacked_t,free_unpacked);

  // - store proto source location -
  dst_location->v_reference_cnt.atomic_inc();
  pmd_ptr->source_loc = dst_location;

  // - initialize string location map -
  pmd_ptr->update_string_map_message(it,pmd_ptr->msg_descriptor);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_proto_msg_descr,pmd_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_proto_source_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("ProtoSource"),"ProtoSource");
  );

  return true;
}/*}}}*/

bool bic_proto_source_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("ProtoSource");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class PROTO_MSG_DESCR -
built_in_class_s proto_msg_descr_class =
{/*{{{*/
  "ProtoMsgDescr",
  c_modifier_public | c_modifier_final,
  6, proto_msg_descr_methods,
  0, proto_msg_descr_variables,
  bic_proto_msg_descr_consts,
  bic_proto_msg_descr_init,
  bic_proto_msg_descr_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s proto_msg_descr_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_proto_msg_descr_operator_binary_equal
  },
  {
    "ProtoMsgDescr#2",
    c_modifier_public | c_modifier_final,
    bic_proto_msg_descr_method_ProtoMsgDescr_2
  },
  {
    "pack#1",
    c_modifier_public | c_modifier_final,
    bic_proto_msg_descr_method_pack_1
  },
  {
    "unpack#1",
    c_modifier_public | c_modifier_final,
    bic_proto_msg_descr_method_unpack_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_proto_msg_descr_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_proto_msg_descr_method_print_0
  },
};/*}}}*/

built_in_variable_s proto_msg_descr_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_proto_msg_descr_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_proto_msg_descr_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (proto_msg_descr_s *)nullptr;
}/*}}}*/

void bic_proto_msg_descr_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  proto_msg_descr_s *pmd_ptr = (proto_msg_descr_s *)location_ptr->v_data_ptr;

  if (pmd_ptr != nullptr)
  {
    pmd_ptr->clear(it);
    cfree(pmd_ptr);
  }
}/*}}}*/

bool bic_proto_msg_descr_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_proto_msg_descr_method_ProtoMsgDescr_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/

  // FIXME TODO continue ...
  BIC_TODO_ERROR(__FILE__,__LINE__);
  return false;
}/*}}}*/

bool bic_proto_msg_descr_method_pack_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
dict:c_rm_class_dict
>
method pack
; @end

  proto_msg_descr_s *pmd_ptr = (proto_msg_descr_s *)dst_location->v_data_ptr;
  pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)src_0_location->v_data_ptr;

  tree_ptr->it_ptr = &it;
  tree_ptr->source_pos = operands[c_source_pos_idx];

  bc_arrays_s buffers;
  buffers.init();

  buffers.push_blank();
  buffers.last().copy_resize(pmd_ptr->msg_descriptor->sizeof_message);
  char *msg_data = buffers.last().data;

  // - ERROR -
  if (!pmd_ptr->pack_message(it,pmd_ptr->msg_descriptor,tree_ptr,buffers,msg_data))
  {
    buffers.clear();

    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  // - retrieve message packed size -
  size_t length = pmd_ptr->msg_get_packed_size(msg_data);

  // - create result string -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->create(length);

  // - pack message -
  pmd_ptr->msg_pack(msg_data,(uint8_t *)string_ptr->data);

  buffers.clear();

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_proto_msg_descr_method_unpack_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:retrieve_data_buffer
>
method send
; @end

  proto_msg_descr_s *pmd_ptr = (proto_msg_descr_s *)dst_location->v_data_ptr;

  // - unpack message -
  void *msg_data = pmd_ptr->msg_unpack(nullptr,data_size,(const uint8_t *)data_ptr);

  // - create dictionary -
  pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)cmalloc(sizeof(pointer_map_tree_s));
  tree_ptr->init();

  tree_ptr->it_ptr = &it;
  tree_ptr->source_pos = operands[c_source_pos_idx];

  BIC_CREATE_NEW_LOCATION(new_location,c_rm_class_dict,tree_ptr);
  BIC_SET_RESULT(new_location);

  // - ERROR -
  if (!pmd_ptr->unpack_message(it,pmd_ptr->msg_descriptor,(char *)msg_data,tree_ptr))
  {
    pmd_ptr->msg_free_unpacked(msg_data,nullptr);

    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  pmd_ptr->msg_free_unpacked(msg_data,nullptr);

  return true;
}/*}}}*/

bool bic_proto_msg_descr_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("ProtoMsgDescr"),"ProtoMsgDescr");
  );

  return true;
}/*}}}*/

bool bic_proto_msg_descr_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("ProtoMsgDescr");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

