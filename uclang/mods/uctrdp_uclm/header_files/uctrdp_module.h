
#ifndef __UCTRDP_MODULE_H
#define __UCTRDP_MODULE_H

@begin
include "ucl_uctrdp.h"
@end

// - UCTRDP indexes of built in classes -
extern unsigned c_bi_class_trdp_pd;
extern unsigned c_bi_class_trdp_pd_page;
extern unsigned c_bi_class_trdp_pd_address;
extern unsigned c_bi_class_trdp_pd_port;

// - UCTRDP module -
extern built_in_module_s module;

// - UCTRDP classes -
extern built_in_class_s *uctrdp_classes[];

// - UCTRDP error identifiers -
enum
{
  c_error_TRDP_PD_INITIALIZE_ERROR = 0,
  c_error_TRDP_PD_SET_MODE_INVALID_MODE,
  c_error_TRDP_PD_SET_MODE_ERROR,
  c_error_TRDP_PD_SET_PERIOD_ERROR,
  c_error_TRDP_PD_REMOVE_PORTS_ERROR,
  c_error_TRDP_PD_ADDRESS_INVALID_SCOPE,
  c_error_TRDP_PD_ADDRESS_INVALID_ADDRESS,
  c_error_TRDP_PD_PORT_STATE_ERROR,
  c_error_TRDP_PD_PORT_PUBLISH_ERROR,
  c_error_TRDP_PD_PORT_SUBSCRIBE_ERROR,
  c_error_TRDP_PD_PORT_GET_PORT_ERROR,
  c_error_TRDP_PD_PORT_WRITE_READ_ERROR,
  c_error_TRDP_PD_PORT_INVALID_PAGE_SIZE,
  c_error_TRDP_PD_PORT_RELEASE_PAGE_ERROR,
};

// - UCTRDP error strings -
extern const char *uctrdp_error_strings[];

// - UCTRDP initialize -
bool uctrdp_initialize(script_parser_s &sp);

// - UCTRDP print exception -
bool uctrdp_print_exception(interpreter_s &it,exception_s &exception);

// - class TRDP_PD -
extern built_in_variable_s trdp_pd_variables[];
extern built_in_method_s trdp_pd_methods[];
extern built_in_class_s trdp_pd_class;

void bic_trdp_pd_consts(location_array_s &const_locations);
void bic_trdp_pd_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_trdp_pd_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_trdp_pd_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_pd_method_TrdpPd_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_pd_method_SetMode_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_pd_method_SetPeriod_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_pd_method_RemoveAllPorts_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_pd_method_Port_5(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_pd_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_pd_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class TRDP_PD_PAGE -
extern built_in_variable_s trdp_pd_page_variables[];
extern built_in_method_s trdp_pd_page_methods[];
extern built_in_class_s trdp_pd_page_class;

void bic_trdp_pd_page_consts(location_array_s &const_locations);
void bic_trdp_pd_page_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_trdp_pd_page_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_trdp_pd_page_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_pd_page_method_TrdpPdPage_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_pd_page_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_pd_page_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class TRDP_PD_ADDRESS -
extern built_in_variable_s trdp_pd_address_variables[];
extern built_in_method_s trdp_pd_address_methods[];
extern built_in_class_s trdp_pd_address_class;

void bic_trdp_pd_address_consts(location_array_s &const_locations);
void bic_trdp_pd_address_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_trdp_pd_address_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_trdp_pd_address_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_pd_address_method_TrdpPdAddress_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_pd_address_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_pd_address_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class TRDP_PD_PORT -
extern built_in_variable_s trdp_pd_port_variables[];
extern built_in_method_s trdp_pd_port_methods[];
extern built_in_class_s trdp_pd_port_class;

void bic_trdp_pd_port_consts(location_array_s &const_locations);
void bic_trdp_pd_port_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_trdp_pd_port_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_trdp_pd_port_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_pd_port_method_Publish_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_pd_port_method_Subscribe_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_pd_port_method_Unpublish_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_pd_port_method_Unsubscribe_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_pd_port_method_write_size_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_pd_port_method_Write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_pd_port_method_Read_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_pd_port_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_trdp_pd_port_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

