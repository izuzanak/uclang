
#ifndef __SNMP_MODULE_H
#define __SNMP_MODULE_H

@begin
include "ucl_snmp.h"
@end

// - SNMP indexes of built in classes -
extern unsigned c_bi_class_snmp_session;
extern unsigned c_bi_class_snmp_agent;
extern unsigned c_bi_class_snmp_obj;
extern unsigned c_bi_class_snmp_oid;

// - SNMP module -
extern "C" IMPORT built_in_module_s module;

// - SNMP classes -
extern built_in_class_s *snmp_classes[];

// - SNMP error identifiers -
enum
{
  c_error_SNMP_SESSION_IS_ALREADY_RUNNING = 0,
  c_error_SNMP_SESSION_ARGUMENT_MUST_BE_STRING,
  c_error_SNMP_SESSION_ARGUMENTS_PARSE_ERROR,
  c_error_SNMP_SESSION_OPEN_ERROR,
  c_error_SNMP_SESSION_DIFFERENT_OID_AND_VALUE_ARRAY_LENGTHS,
  c_error_SNMP_SESSION_EXPECTED_OID_ARRAY,
  c_error_SNMP_SESSION_UNSUPPORTED_VALUE_TYPE,
  c_error_SNMP_SESSION_WRITE_VALUE_ERROR,
  c_error_SNMP_SESSION_READ_VALUE_ERROR,
  c_error_SNMP_AGENT_UNRECOGNIZED_AGENT_TYPE,
  c_error_SNMP_AGENT_IS_ALREADY_RUNNING,
  c_error_SNMP_AGENT_CREATE_ERROR,
  c_error_SNMP_AGENT_UNRECOGNIZED_OBJECT_TYPE,
  c_error_SNMP_AGENT_OBJECT_ALREADY_EXISTS,
  c_error_SNMP_AGENT_INJECT_OBJECT_ERROR,
  c_error_SNMP_AGENT_CHECK_AND_PROCESS_ERROR,
  c_error_SNMP_AGENT_OBJECT_NAME_NOT_FOUND,
  c_error_SNMP_AGENT_INDEX_DOES_NOT_REFER_TO_VALID_VALUE,
  c_error_SNMP_OID_PARSE_ERROR,
  c_error_SNMP_OBJ_SET_WRONG_TYPE,
  c_error_SNMP_OBJ_SET_VALUE_STRING_TOO_LONG,
};

// - SNMP error strings -
extern const char *snmp_error_strings[];

// - SNMP initialize -
bool snmp_initialize(script_parser_s &sp);

// - SNMP print exception -
bool snmp_print_exception(interpreter_s &it,exception_s &exception);

// - class SNMP_SESSION -
extern built_in_variable_s snmp_session_variables[];
extern built_in_method_s snmp_session_methods[];
extern built_in_class_s snmp_session_class;

void bic_snmp_session_consts(location_array_s &const_locations);
void bic_snmp_session_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_snmp_session_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_snmp_session_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_snmp_session_method_SnmpSession_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_snmp_session_method_set_list_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_snmp_session_method_get_list_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_snmp_session_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_snmp_session_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class SNMP_AGENT -
extern built_in_variable_s snmp_agent_variables[];
extern built_in_method_s snmp_agent_methods[];
extern built_in_class_s snmp_agent_class;

void bic_snmp_agent_consts(location_array_s &const_locations);
void bic_snmp_agent_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_snmp_agent_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_snmp_agent_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_snmp_agent_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_snmp_agent_method_SnmpAgent_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_snmp_agent_method_add_object_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_snmp_agent_method_check_and_process_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_snmp_agent_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_snmp_agent_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_snmp_agent_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_snmp_agent_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_snmp_agent_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class SNMP_OBJ -
extern built_in_variable_s snmp_obj_variables[];
extern built_in_method_s snmp_obj_methods[];
extern built_in_class_s snmp_obj_class;

void bic_snmp_obj_consts(location_array_s &const_locations);
void bic_snmp_obj_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_snmp_obj_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_snmp_obj_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_snmp_obj_method_get_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_snmp_obj_method_get_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_snmp_obj_method_set_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_snmp_obj_method_get_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_snmp_obj_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_snmp_obj_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class SNMP_OID -
extern built_in_variable_s snmp_oid_variables[];
extern built_in_method_s snmp_oid_methods[];
extern built_in_class_s snmp_oid_class;

void bic_snmp_oid_consts(location_array_s &const_locations);
void bic_snmp_oid_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_snmp_oid_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_snmp_oid_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_snmp_oid_method_SnmpOid_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_snmp_oid_method_items_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_snmp_oid_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_snmp_oid_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

