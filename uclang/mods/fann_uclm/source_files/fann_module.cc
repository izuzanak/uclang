
@begin
include "fann_module.h"
@end

// - FANN indexes of built in classes -
unsigned c_bi_class_fann_net = c_idx_not_exist;
unsigned c_bi_class_fann_train_data = c_idx_not_exist;

// - FANN module -
built_in_module_s module =
{/*{{{*/
  2,                    // Class count
  fann_classes,         // Classes

  0,                    // Error base index
  13,                   // Error count
  fann_error_strings,   // Error strings

  fann_initialize,      // Initialize function
  fann_print_exception, // Print exceptions function
};/*}}}*/

// - FANN classes -
built_in_class_s *fann_classes[] =
{/*{{{*/
  &fann_net_class,
  &fann_train_data_class,
};/*}}}*/

// - FANN error strings -
const char *fann_error_strings[] =
{/*{{{*/
  "error_FANN_NET_CREATE_IN_OUT_LAYER_MISSING",
  "error_FANN_NET_CREATE_LAYER_NEURON_COUNT_ERROR",
  "error_FANN_NET_TRAIN_DATA_IN_OUT_NEURON_COUNT_ERROR",
  "error_FANN_NET_RUN_INPUT_SIZE_ERROR",
  "error_FANN_NET_RUN_INPUT_VALUE_ERROR",
  "error_FANN_NET_SAVE_ERROR",
  "error_FANN_NET_LOAD_ERROR",
  "error_FANN_NET_INVALID_TRAINING_ALGORITHM",
  "error_FANN_NET_INVALID_LEARNING_MOMENTUM",
  "error_FANN_TRAIN_DATA_ARRAY_SIZE_ERROR",
  "error_FANN_TRAIN_DATA_IN_OUT_VALUES_ERROR",
  "error_FANN_TRAIN_DATA_SAVE_ERROR",
  "error_FANN_TRAIN_DATA_LOAD_ERROR",
};/*}}}*/

// - FANN initialize -
bool fann_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize fann_net class identifier -
  c_bi_class_fann_net = class_base_idx++;

  // - initialize fann_train_data class identifier -
  c_bi_class_fann_train_data = class_base_idx++;

  return true;
}/*}}}*/

// - FANN print exception -
bool fann_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_FANN_NET_CREATE_IN_OUT_LAYER_MISSING:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFannNet create, missing neuron counts for input and/or output layer\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FANN_NET_CREATE_LAYER_NEURON_COUNT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFannNet create, invalid count of neurons in layer %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FANN_NET_TRAIN_DATA_IN_OUT_NEURON_COUNT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFannNet and FannTrainData mismatch of in/out neuron counts\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FANN_NET_RUN_INPUT_SIZE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFannNet invalid size of input data\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FANN_NET_RUN_INPUT_VALUE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFannNet invalid input data value, expected real number\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FANN_NET_SAVE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while saving FannNet to file \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FANN_NET_LOAD_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while loading FannNet from file \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FANN_NET_INVALID_TRAINING_ALGORITHM:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFannNet invalid training algorithm\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FANN_NET_INVALID_LEARNING_MOMENTUM:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFannNet invalid learning momentum\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FANN_TRAIN_DATA_ARRAY_SIZE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid size of FannTrainData source array\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FANN_TRAIN_DATA_IN_OUT_VALUES_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid FannTrainData in/out values at index %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FANN_TRAIN_DATA_SAVE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while saving FannTrainData to file \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FANN_TRAIN_DATA_LOAD_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while loading FannTrainData from file \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class FANN_NET -
built_in_class_s fann_net_class =
{/*{{{*/
  "FannNet",
  c_modifier_public | c_modifier_final,
  26, fann_net_methods,
  4 + 18 + 2 + 2 + 2, fann_net_variables,
  bic_fann_net_consts,
  bic_fann_net_init,
  bic_fann_net_clear,
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

built_in_method_s fann_net_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_fann_net_operator_binary_equal
  },
  {
    "create_standard#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_fann_net_method_create_standard_1
  },
  {
    "create_sparse#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_fann_net_method_create_sparse_2
  },
  {
    "create_shortcut#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_fann_net_method_create_shortcut_1
  },
  {
    "randomize_weights#2",
    c_modifier_public | c_modifier_final,
    bic_fann_net_method_randomize_weights_2
  },
  {
    "init_weights#1",
    c_modifier_public | c_modifier_final,
    bic_fann_net_method_init_weights_1
  },
  {
    "train_on_data#4",
    c_modifier_public | c_modifier_final,
    bic_fann_net_method_train_on_data_4
  },
  {
    "train_epoch#1",
    c_modifier_public | c_modifier_final,
    bic_fann_net_method_train_epoch_1
  },
  {
    "test_data#1",
    c_modifier_public | c_modifier_final,
    bic_fann_net_method_test_data_1
  },
  {
    "run#1",
    c_modifier_public | c_modifier_final,
    bic_fann_net_method_run_1
  },
  {
    "save#1",
    c_modifier_public | c_modifier_final,
    bic_fann_net_method_save_1
  },
  {
    "load#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_fann_net_method_load_1
  },
  {
    "input_cnt#0",
    c_modifier_public | c_modifier_final,
    bic_fann_net_method_input_cnt_0
  },
  {
    "output_cnt#0",
    c_modifier_public | c_modifier_final,
    bic_fann_net_method_output_cnt_0
  },
  {
    "network_type#0",
    c_modifier_public | c_modifier_final,
    bic_fann_net_method_network_type_0
  },
  {
    "layer_array#0",
    c_modifier_public | c_modifier_final,
    bic_fann_net_method_layer_array_0
  },
  {
    "algorithm#0",
    c_modifier_public | c_modifier_final,
    bic_fann_net_method_algorithm_0
  },
  {
    "algorithm#1",
    c_modifier_public | c_modifier_final,
    bic_fann_net_method_algorithm_1
  },
  {
    "rate#0",
    c_modifier_public | c_modifier_final,
    bic_fann_net_method_rate_0
  },
  {
    "rate#1",
    c_modifier_public | c_modifier_final,
    bic_fann_net_method_rate_1
  },
  {
    "momentum#0",
    c_modifier_public | c_modifier_final,
    bic_fann_net_method_momentum_0
  },
  {
    "momentum#1",
    c_modifier_public | c_modifier_final,
    bic_fann_net_method_momentum_1
  },
  {
    "print_connections#0",
    c_modifier_public | c_modifier_final,
    bic_fann_net_method_print_connections_0
  },
  {
    "print_parameters#0",
    c_modifier_public | c_modifier_final,
    bic_fann_net_method_print_parameters_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_fann_net_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_fann_net_method_print_0
  },
};/*}}}*/

built_in_variable_s fann_net_variables[] =
{/*{{{*/

  // - fann net training algorithm constants -
  { "TRAIN_INCREMENTAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TRAIN_BATCH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TRAIN_RPROP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TRAIN_QUICKPROP", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - fann net activation function constants -
  { "LINEAR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "THRESHOLD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "THRESHOLD_SYMMETRIC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SIGMOID", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SIGMOID_STEPWISE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SIGMOID_SYMMETRIC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SIGMOID_SYMMETRIC_STEPWISE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GAUSSIAN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GAUSSIAN_SYMMETRIC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GAUSSIAN_STEPWISE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ELLIOT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ELLIOT_SYMMETRIC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "LINEAR_PIECE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "LINEAR_PIECE_SYMMETRIC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SIN_SYMMETRIC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "COS_SYMMETRIC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SIN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "COS", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - fann net error function constants -
  { "ERRORFUNC_LINEAR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ERRORFUNC_TANH", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - fann net stop function constants -
  { "STOPFUNC_MSE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "STOPFUNC_BIT", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - fann net net type constants -
  { "NETTYPE_LAYER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NETTYPE_SHORTCUT", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

#define BIC_FANN_NET_CREATE_PROC_LAYERS_ARRAY() \
{/*{{{*/\
  \
  /* - ERROR - */\
  if (array_ptr->used < 2)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_FANN_NET_CREATE_IN_OUT_LAYER_MISSING,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
  \
  pointer *p_ptr = array_ptr->data;\
  pointer *p_ptr_end = p_ptr + array_ptr->used;\
  unsigned *l_ptr = layers;\
  do {\
    location_s *item_location = it.get_location_value(*p_ptr);\
    \
    /* - ERROR - */\
    if (item_location->v_type != c_bi_class_integer)\
    {\
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FANN_NET_CREATE_LAYER_NEURON_COUNT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      new_exception->params.push(l_ptr - layers);\
      \
      return false;\
    }\
    \
    /* - retrieve layer neuron count - */\
    long long int neuron_count = (long long int)item_location->v_data_ptr;\
    \
    /* - ERROR - */\
    if (neuron_count <= 0 || neuron_count > UINT_MAX)\
    {\
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FANN_NET_CREATE_LAYER_NEURON_COUNT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      new_exception->params.push(l_ptr - layers);\
      \
      return false;\
    }\
    \
    *l_ptr = neuron_count;\
    \
  } while(++l_ptr,++p_ptr < p_ptr_end);\
}/*}}}*/

#define BIC_FANN_NET_TRAIN_DATA_TEST() \
/*{{{*/\
  fann *fann_ptr = (fann *)dst_location->v_data_ptr;\
  fann_train_data *ftd_ptr = (fann_train_data *)src_0_location->v_data_ptr;\
  \
  /* - ERROR - */\
  if (fann_get_num_input(fann_ptr) != fann_num_input_train_data(ftd_ptr) ||\
      fann_get_num_output(fann_ptr) != fann_num_output_train_data(ftd_ptr))\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_FANN_NET_TRAIN_DATA_IN_OUT_NEURON_COUNT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
/*}}}*/

void bic_fann_net_consts(location_array_s &const_locations)
{/*{{{*/

  // - fann net training algorithm constants -
  {
    const_locations.push_blanks(4);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 4);

#define CREATE_FUNNET_TRAIN_ALGO_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_FUNNET_TRAIN_ALGO_BIC_STATIC(FANN_TRAIN_INCREMENTAL);
    CREATE_FUNNET_TRAIN_ALGO_BIC_STATIC(FANN_TRAIN_BATCH);
    CREATE_FUNNET_TRAIN_ALGO_BIC_STATIC(FANN_TRAIN_RPROP);
    CREATE_FUNNET_TRAIN_ALGO_BIC_STATIC(FANN_TRAIN_QUICKPROP);
  }

  // - fann net activation function constants -
  {
    const_locations.push_blanks(18);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 18);

#define CREATE_FUNNET_ACTIVATION_FUNC_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_FUNNET_ACTIVATION_FUNC_BIC_STATIC(FANN_LINEAR);
    CREATE_FUNNET_ACTIVATION_FUNC_BIC_STATIC(FANN_THRESHOLD);
    CREATE_FUNNET_ACTIVATION_FUNC_BIC_STATIC(FANN_THRESHOLD_SYMMETRIC);
    CREATE_FUNNET_ACTIVATION_FUNC_BIC_STATIC(FANN_SIGMOID);
    CREATE_FUNNET_ACTIVATION_FUNC_BIC_STATIC(FANN_SIGMOID_STEPWISE);
    CREATE_FUNNET_ACTIVATION_FUNC_BIC_STATIC(FANN_SIGMOID_SYMMETRIC);
    CREATE_FUNNET_ACTIVATION_FUNC_BIC_STATIC(FANN_SIGMOID_SYMMETRIC_STEPWISE);
    CREATE_FUNNET_ACTIVATION_FUNC_BIC_STATIC(FANN_GAUSSIAN);
    CREATE_FUNNET_ACTIVATION_FUNC_BIC_STATIC(FANN_GAUSSIAN_SYMMETRIC);
    CREATE_FUNNET_ACTIVATION_FUNC_BIC_STATIC(FANN_GAUSSIAN_STEPWISE);
    CREATE_FUNNET_ACTIVATION_FUNC_BIC_STATIC(FANN_ELLIOT);
    CREATE_FUNNET_ACTIVATION_FUNC_BIC_STATIC(FANN_ELLIOT_SYMMETRIC);
    CREATE_FUNNET_ACTIVATION_FUNC_BIC_STATIC(FANN_LINEAR_PIECE);
    CREATE_FUNNET_ACTIVATION_FUNC_BIC_STATIC(FANN_LINEAR_PIECE_SYMMETRIC);
    CREATE_FUNNET_ACTIVATION_FUNC_BIC_STATIC(FANN_SIN_SYMMETRIC);
    CREATE_FUNNET_ACTIVATION_FUNC_BIC_STATIC(FANN_COS_SYMMETRIC);
    CREATE_FUNNET_ACTIVATION_FUNC_BIC_STATIC(FANN_SIN);
    CREATE_FUNNET_ACTIVATION_FUNC_BIC_STATIC(FANN_COS);
  }

  // - fann net error function constants -
  {
    const_locations.push_blanks(2);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 2);

#define CREATE_FUNNET_ERROR_FUNC_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_FUNNET_ERROR_FUNC_BIC_STATIC(FANN_ERRORFUNC_LINEAR);
    CREATE_FUNNET_ERROR_FUNC_BIC_STATIC(FANN_ERRORFUNC_TANH);
  }

  // - fann net stop function constants -
  {
    const_locations.push_blanks(2);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 2);

#define CREATE_FUNNET_STOP_FUNC_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_FUNNET_STOP_FUNC_BIC_STATIC(FANN_STOPFUNC_MSE);
    CREATE_FUNNET_STOP_FUNC_BIC_STATIC(FANN_STOPFUNC_BIT);
  }

  // - fann net net type constants -
  {
    const_locations.push_blanks(2);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 2);

#define CREATE_FUNNET_NET_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_FUNNET_NET_TYPE_BIC_STATIC(FANN_NETTYPE_LAYER);
    CREATE_FUNNET_NET_TYPE_BIC_STATIC(FANN_NETTYPE_SHORTCUT);
  }

}/*}}}*/

void bic_fann_net_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_fann_net_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  fann *fann_ptr = (fann *)location_ptr->v_data_ptr;

  if (fann_ptr != nullptr)
  {
    fann_destroy(fann_ptr);
  }
}/*}}}*/

bool bic_fann_net_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_fann_net_method_create_standard_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_array)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_fann_net,"create_standard#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  pointer_array_s *array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;
  unsigned layers[array_ptr->used];

  BIC_FANN_NET_CREATE_PROC_LAYERS_ARRAY();

  // - create standard ann -
  fann *fann_ptr = fann_create_standard_array(array_ptr->used,layers);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_fann_net,fann_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_fann_net_method_create_sparse_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  double connection_rate;

  if (!it.retrieve_float(src_0_location,connection_rate) ||
      src_1_location->v_type != c_bi_class_array)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_fann_net,"create_sparse#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  pointer_array_s *array_ptr = (pointer_array_s *)src_1_location->v_data_ptr;
  unsigned layers[array_ptr->used];

  BIC_FANN_NET_CREATE_PROC_LAYERS_ARRAY();

  // - create standard ann -
  fann *fann_ptr = fann_create_sparse_array(connection_rate,array_ptr->used,layers);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_fann_net,fann_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_fann_net_method_create_shortcut_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_array)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_fann_net,"create_shortcut#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  pointer_array_s *array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;
  unsigned layers[array_ptr->used];

  BIC_FANN_NET_CREATE_PROC_LAYERS_ARRAY();

  // - create standard ann -
  fann *fann_ptr = fann_create_shortcut_array(array_ptr->used,layers);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_fann_net,fann_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_fann_net_method_randomize_weights_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  double min_weight;
  double max_weight;

  if (!it.retrieve_float(src_0_location,min_weight) ||
      !it.retrieve_float(src_1_location,max_weight))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("randomize_weights#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  fann_randomize_weights((fann *)dst_location->v_data_ptr,min_weight,max_weight);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_fann_net_method_init_weights_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_fann_train_data)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("init_weights#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  BIC_FANN_NET_TRAIN_DATA_TEST();

  fann_init_weights(fann_ptr,ftd_ptr);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_fann_net_method_train_on_data_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);
  location_s *src_3_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_3_op_idx]);

  long long int max_epochs;
  long long int epochs_between_reports;
  double desired_error;

  if (src_0_location->v_type != c_bi_class_fann_train_data ||
      !it.retrieve_integer(src_1_location,max_epochs) ||
      !it.retrieve_integer(src_2_location,epochs_between_reports) ||
      !it.retrieve_float(src_3_location,desired_error))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("train_on_data#4");
    new_exception->params.push(4);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);
    new_exception->params.push(src_3_location->v_type);

    return false;
  }

  BIC_FANN_NET_TRAIN_DATA_TEST();

  fann_train_on_data(fann_ptr,ftd_ptr,max_epochs,epochs_between_reports,desired_error);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_fann_net_method_train_epoch_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_fann_train_data)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("train_epoch#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  BIC_FANN_NET_TRAIN_DATA_TEST();

  double result = fann_train_epoch(fann_ptr,ftd_ptr);

  BIC_SIMPLE_SET_RES(c_bi_class_float,result);

  return true;
}/*}}}*/

bool bic_fann_net_method_test_data_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_fann_train_data)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("test_data#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  BIC_FANN_NET_TRAIN_DATA_TEST();

  double result = fann_test_data(fann_ptr,ftd_ptr);

  BIC_SIMPLE_SET_RES(c_bi_class_float,result);

  return true;
}/*}}}*/

bool bic_fann_net_method_run_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_array)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("run#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  fann *fann_ptr = (fann *)dst_location->v_data_ptr;
  pointer_array_s *array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (fann_get_num_input(fann_ptr) != array_ptr->used)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FANN_NET_RUN_INPUT_SIZE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  double input[array_ptr->used];

  // - fill input array -
  pointer *p_ptr = array_ptr->data;
  pointer *p_ptr_end = p_ptr + array_ptr->used;
  double *i_ptr = input;
  do {

    // - ERROR -
    if (!it.retrieve_float(it.get_location_value(*p_ptr),*i_ptr))
    {
      exception_s::throw_exception(it,module.error_base + c_error_FANN_NET_RUN_INPUT_VALUE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

  } while(++i_ptr,++p_ptr < p_ptr_end);

  double *output = fann_run(fann_ptr,input);

  // - run ann on input -
  pointer_array_s *result_arr = it.get_new_array_ptr();

  // - fill result array -
  double *o_ptr = output;
  double *o_ptr_end = o_ptr + fann_get_num_output(fann_ptr);
  do {
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_float,*o_ptr);
    result_arr->push(new_location);
  } while(++o_ptr < o_ptr_end);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,result_arr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_fann_net_method_save_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("save#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (fann_save((fann *)dst_location->v_data_ptr,string_ptr->data) != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FANN_NET_SAVE_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_fann_net_method_load_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_fann_net,"load#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  fann *fann_ptr = fann_create_from_file(((string_s *)src_0_location->v_data_ptr)->data);

  // - ERROR -
  if (fann_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FANN_NET_LOAD_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_fann_net,fann_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_fann_net_method_input_cnt_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = fann_get_num_input((fann *)dst_location->v_data_ptr);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_fann_net_method_output_cnt_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = fann_get_num_output((fann *)dst_location->v_data_ptr);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_fann_net_method_network_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = fann_get_network_type((fann *)dst_location->v_data_ptr);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_fann_net_method_layer_array_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  fann *fann_ptr = (fann *)dst_location->v_data_ptr;

  unsigned layer_count = fann_get_num_layers(fann_ptr);
  unsigned layers[layer_count];

  // - retrieve layers of fann -
  fann_get_layer_array(fann_ptr,layers);

  pointer_array_s *array_ptr = it.get_new_array_ptr();

  if (layer_count != 0)
  {
    unsigned *l_ptr = layers;
    unsigned *l_ptr_end = l_ptr + layer_count;
    do {
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,*l_ptr);
      array_ptr->push(new_location);
    } while(++l_ptr < l_ptr_end);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_fann_net_method_algorithm_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = fann_get_training_algorithm((fann *)dst_location->v_data_ptr);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_fann_net_method_algorithm_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int algorithm;

  if (!it.retrieve_integer(src_0_location,algorithm))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("algorithm#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - ERROR -
  if (algorithm < FANN_TRAIN_INCREMENTAL || algorithm > FANN_TRAIN_QUICKPROP)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FANN_NET_INVALID_TRAINING_ALGORITHM,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  fann_set_training_algorithm((fann *)dst_location->v_data_ptr,(fann_train_enum)algorithm);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_fann_net_method_rate_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  double result = fann_get_learning_rate((fann *)dst_location->v_data_ptr);

  BIC_SIMPLE_SET_RES(c_bi_class_float,result);

  return true;
}/*}}}*/

bool bic_fann_net_method_rate_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  double rate;

  if (!it.retrieve_float(src_0_location,rate))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("rate#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  fann_set_learning_rate((fann *)dst_location->v_data_ptr,rate);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_fann_net_method_momentum_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  double result = fann_get_learning_momentum((fann *)dst_location->v_data_ptr);

  BIC_SIMPLE_SET_RES(c_bi_class_float,result);

  return true;
}/*}}}*/

bool bic_fann_net_method_momentum_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  double momentum;

  if (!it.retrieve_float(src_0_location,momentum))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("momentum#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - ERROR -
  if (momentum < 0.0 || momentum > 1.0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FANN_NET_INVALID_LEARNING_MOMENTUM,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  fann_set_learning_momentum((fann *)dst_location->v_data_ptr,momentum);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_fann_net_method_print_connections_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  fann_print_connections((fann *)dst_location->v_data_ptr);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_fann_net_method_print_parameters_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  fann_print_parameters((fann *)dst_location->v_data_ptr);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_fann_net_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("FannNet"),"FannNet");
  );

  return true;
}/*}}}*/

bool bic_fann_net_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("FannNet");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class FANN_TREAIN_DATA -
built_in_class_s fann_train_data_class =
{/*{{{*/
  "FannTrainData",
  c_modifier_public | c_modifier_final,
  6, fann_train_data_methods,
  0, fann_train_data_variables,
  bic_fann_train_data_consts,
  bic_fann_train_data_init,
  bic_fann_train_data_clear,
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

built_in_method_s fann_train_data_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_fann_train_data_operator_binary_equal
  },
  {
    "FannTrainData#1",
    c_modifier_public | c_modifier_final,
    bic_fann_train_data_method_FannTrainData_1
  },
  {
    "save#1",
    c_modifier_public | c_modifier_final,
    bic_fann_train_data_method_save_1
  },
  {
    "load#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_fann_train_data_method_load_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_fann_train_data_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_fann_train_data_method_print_0
  },
};/*}}}*/

built_in_variable_s fann_train_data_variables[] =
{/*{{{*/
};/*}}}*/

void bic_fann_train_data_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_fann_train_data_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (fann_train_data *)nullptr;
}/*}}}*/

void bic_fann_train_data_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  fann_train_data *ftd_ptr = (fann_train_data *)location_ptr->v_data_ptr;

  if (ftd_ptr != nullptr)
  {
    fann_destroy_train(ftd_ptr);
  }
}/*}}}*/

bool bic_fann_train_data_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_fann_train_data_method_FannTrainData_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_array)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("FannTrainData#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  pointer_array_s *array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (array_ptr->used == 0 || array_ptr->used & 0x01)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FANN_TRAIN_DATA_ARRAY_SIZE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  unsigned num_data = array_ptr->used >> 1;
  unsigned num_input;
  unsigned num_output;

  pointer *a_ptr = array_ptr->data;
  pointer *a_ptr_end = a_ptr + array_ptr->used;

  // - retrieve num_input and num_output -
  {/*{{{*/
    location_s *input_loc = it.get_location_value(a_ptr[0]);
    location_s *output_loc = it.get_location_value(a_ptr[1]);

    // - ERROR -
    if (input_loc->v_type != c_bi_class_array ||
        output_loc->v_type != c_bi_class_array)
    {
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FANN_TRAIN_DATA_IN_OUT_VALUES_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(0);

      return false;
    }

    num_input = ((pointer_array_s *)input_loc->v_data_ptr)->used;
    num_output = ((pointer_array_s *)output_loc->v_data_ptr)->used;

    // - ERROR -
    if (num_input == 0 || num_output == 0)
    {
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FANN_TRAIN_DATA_IN_OUT_VALUES_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(0);

      return false;
    }
  }/*}}}*/

  do {
    location_s *input_loc = it.get_location_value(a_ptr[0]);
    location_s *output_loc = it.get_location_value(a_ptr[1]);

    // - ERROR -
    if (input_loc->v_type != c_bi_class_array ||
        output_loc->v_type != c_bi_class_array)
    {
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FANN_TRAIN_DATA_IN_OUT_VALUES_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push((a_ptr - array_ptr->data) >> 1);

      return false;
    }

    pointer_array_s *input_array = (pointer_array_s *)input_loc->v_data_ptr;
    pointer_array_s *output_array = (pointer_array_s *)output_loc->v_data_ptr;

    // - ERROR -
    if (input_array->used != num_input || output_array->used != num_output)
    {
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FANN_TRAIN_DATA_IN_OUT_VALUES_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push((a_ptr - array_ptr->data) >> 1);

      return false;
    }

    {
      pointer *i_ptr = input_array->data;
      pointer *i_ptr_end = i_ptr + input_array->used;
      do {
        location_s *item_location = it.get_location_value(*i_ptr);
        double dummy;

        // - ERROR -
        if (!it.retrieve_float(item_location,dummy))
        {
          exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FANN_TRAIN_DATA_IN_OUT_VALUES_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
          new_exception->params.push((a_ptr - array_ptr->data) >> 1);

          return false;
        }
      } while(++i_ptr < i_ptr_end);
    }

    {
      pointer *o_ptr = output_array->data;
      pointer *o_ptr_end = o_ptr + output_array->used;
      do {
        location_s *item_location = it.get_location_value(*o_ptr);
        double dummy;

        // - ERROR -
        if (!it.retrieve_float(item_location,dummy))
        {
          exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FANN_TRAIN_DATA_IN_OUT_VALUES_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
          new_exception->params.push((a_ptr - array_ptr->data) >> 1);

          return false;
        }
      } while(++o_ptr < o_ptr_end);
    }

  } while((a_ptr += 2) < a_ptr_end);

  fann_c::train_data_cb_mutex.lock();
  fann_c::train_data_array = array_ptr;

  // - fill train data by callback -
  fann_train_data *ftd_ptr = fann_create_train_from_callback(
      num_data,num_input,num_output,fann_c::train_data_cb);

  fann_c::train_data_cb_mutex.unlock();

  // - set fann_train_data destination location -
  dst_location->v_data_ptr = (fann_train_data *)ftd_ptr;

  return true;
}/*}}}*/

bool bic_fann_train_data_method_save_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("save#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (fann_save_train((fann_train_data *)dst_location->v_data_ptr,string_ptr->data) != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FANN_TRAIN_DATA_SAVE_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_fann_train_data_method_load_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_fann_net,"load#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  fann_train_data *ftd_ptr = fann_read_train_from_file(((string_s *)src_0_location->v_data_ptr)->data);

  // - ERROR -
  if (ftd_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FANN_TRAIN_DATA_LOAD_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_fann_train_data,ftd_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_fann_train_data_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("FannTrainData"),"FannTrainData");
  );

  return true;
}/*}}}*/

bool bic_fann_train_data_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("FannTrainData");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

