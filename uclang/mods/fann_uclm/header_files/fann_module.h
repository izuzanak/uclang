
#ifndef __FANN_MODULE_H
#define __FANN_MODULE_H

@begin
include "ucl_fann.h"
@end

// - FANN indexes of built in classes -
extern unsigned c_bi_class_fann_net;
extern unsigned c_bi_class_fann_train_data;

// - FANN module -
extern built_in_module_s module;

// - FANN classes -
extern built_in_class_s *fann_classes[];

// - FANN error identifiers -
enum
{
  c_error_FANN_DUMMY_ERROR = 0,
};

// - FANN error strings -
extern const char *fann_error_strings[];

// - FANN initialize -
bool fann_initialize(script_parser_s &sp);

// - FANN print exception -
bool fann_print_exception(interpreter_s &it,exception_s &exception);

// - class FANN_NET -
extern built_in_variable_s fann_net_variables[];
extern built_in_method_s fann_net_methods[];
extern built_in_class_s fann_net_class;

void bic_fann_net_consts(location_array_s &const_locations);
void bic_fann_net_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_fann_net_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_fann_net_method_create_standard_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fann_net_method_create_sparse_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fann_net_method_create_shortcut_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fann_net_method_randomize_weights_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fann_net_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fann_net_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class FANN_TRAIN_DATA -
extern built_in_variable_s fann_train_data_variables[];
extern built_in_method_s fann_train_data_methods[];
extern built_in_class_s fann_train_data_class;

void bic_fann_train_data_consts(location_array_s &const_locations);
void bic_fann_train_data_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_fann_train_data_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_fann_train_data_method_FannTrainData_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fann_train_data_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fann_train_data_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

