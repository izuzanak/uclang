
#ifndef __PROTOBUF_MODULE_H
#define __PROTOBUF_MODULE_H

@begin
include "ucl_protobuf.h"
@end

// - PROTOBUF indexes of built in classes -
extern unsigned c_bi_class_proto_source;
extern unsigned c_bi_class_proto_msg_descr;

// - PROTOBUF module -
extern "C" EXPORT built_in_module_s module;

// - PROTOBUF classes -
extern built_in_class_s *protobuf_classes[];

// - PROTOBUF error identifiers -
enum
{
  c_error_PROTOBUF_DUMMY_ERROR = 0,
};

// - PROTOBUF error strings -
extern const char *protobuf_error_strings[];

// - PROTOBUF initialize -
bool protobuf_initialize(script_parser_s &sp);

// - PROTOBUF print exception -
bool protobuf_print_exception(interpreter_s &it,exception_s &exception);

// - class PROTO_SOURCE -
extern built_in_variable_s proto_source_variables[];
extern built_in_method_s proto_source_methods[];
extern built_in_class_s proto_source_class;

void bic_proto_source_consts(location_array_s &const_locations);
void bic_proto_source_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_proto_source_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_proto_source_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_proto_source_method_ProtoSource_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_proto_source_method_msg_descr_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_proto_source_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_proto_source_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class PROTO_MSG_DESCR -
extern built_in_variable_s proto_msg_descr_variables[];
extern built_in_method_s proto_msg_descr_methods[];
extern built_in_class_s proto_msg_descr_class;

void bic_proto_msg_descr_consts(location_array_s &const_locations);
void bic_proto_msg_descr_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_proto_msg_descr_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_proto_msg_descr_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_proto_msg_descr_method_ProtoMsgDescr_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_proto_msg_descr_method_pack_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_proto_msg_descr_method_unpack_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_proto_msg_descr_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_proto_msg_descr_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

