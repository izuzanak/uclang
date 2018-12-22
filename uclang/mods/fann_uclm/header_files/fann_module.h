
#ifndef __FANN_MODULE_H
#define __FANN_MODULE_H

@begin
include "ucl_fann.h"
@end

// - FANN indexes of built in classes -
extern unsigned c_bi_class_fann_net;
extern unsigned c_bi_class_fann_train_data;

// - FANN module -
extern "C" EXPORT built_in_module_s module;

// - FANN classes -
extern built_in_class_s *fann_classes[];

// - FANN error identifiers -
enum
{
  c_error_FANN_NET_CREATE_IN_OUT_LAYER_MISSING = 0,
  c_error_FANN_NET_CREATE_LAYER_NEURON_COUNT_ERROR,
  c_error_FANN_NET_TRAIN_DATA_IN_OUT_NEURON_COUNT_ERROR,
  c_error_FANN_NET_RUN_INPUT_SIZE_ERROR,
  c_error_FANN_NET_RUN_INPUT_VALUE_ERROR,
  c_error_FANN_NET_SAVE_ERROR,
  c_error_FANN_NET_LOAD_ERROR,
  c_error_FANN_NET_INVALID_TRAINING_ALGORITHM,
  c_error_FANN_NET_INVALID_LEARNING_MOMENTUM,
  c_error_FANN_TRAIN_DATA_ARRAY_SIZE_ERROR,
  c_error_FANN_TRAIN_DATA_IN_OUT_VALUES_ERROR,
  c_error_FANN_TRAIN_DATA_SAVE_ERROR,
  c_error_FANN_TRAIN_DATA_LOAD_ERROR,
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

bool bic_fann_net_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fann_net_method_create_standard_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fann_net_method_create_sparse_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fann_net_method_create_shortcut_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fann_net_method_randomize_weights_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fann_net_method_init_weights_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fann_net_method_train_on_data_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fann_net_method_train_epoch_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fann_net_method_test_data_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fann_net_method_run_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fann_net_method_save_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fann_net_method_load_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fann_net_method_input_cnt_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fann_net_method_output_cnt_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fann_net_method_network_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fann_net_method_layer_array_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fann_net_method_algorithm_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fann_net_method_algorithm_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fann_net_method_rate_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fann_net_method_rate_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fann_net_method_momentum_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fann_net_method_momentum_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fann_net_method_print_connections_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fann_net_method_print_parameters_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fann_net_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fann_net_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class FANN_TRAIN_DATA -
extern built_in_variable_s fann_train_data_variables[];
extern built_in_method_s fann_train_data_methods[];
extern built_in_class_s fann_train_data_class;

void bic_fann_train_data_consts(location_array_s &const_locations);
void bic_fann_train_data_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_fann_train_data_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_fann_train_data_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fann_train_data_method_FannTrainData_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fann_train_data_method_save_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fann_train_data_method_load_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fann_train_data_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fann_train_data_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

