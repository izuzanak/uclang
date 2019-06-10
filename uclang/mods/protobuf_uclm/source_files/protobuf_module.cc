
@begin
include "protobuf_module.h"
@end

// - PROTOBUF indexes of built in classes -
unsigned c_bi_class_proto_msg_descr = c_idx_not_exist;

// - PROTOBUF module -
EXPORT built_in_module_s module =
{/*{{{*/
  1,                        // Class count
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

  // - initialize proto_msg_descr class identifier -
  c_bi_class_proto_msg_descr = class_base_idx++;

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

// - class PROTO_MSG_DESCR -
built_in_class_s proto_msg_descr_class =
{/*{{{*/
  "ProtoMsgDescr",
  c_modifier_public | c_modifier_final,
  4, proto_msg_descr_methods,
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

