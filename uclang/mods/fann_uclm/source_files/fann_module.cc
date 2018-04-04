
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
  1,                    // Error count
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
  "error_FANN_DUMMY_ERROR",
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
  case c_error_FANN_DUMMY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFann dummy error\n");
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
  6, fann_net_methods,
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
    /* FIXME TODO throw proper exception */\
    BIC_TODO_ERROR(__FILE__,__LINE__);\
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
      /* FIXME TODO throw proper exception */\
      BIC_TODO_ERROR(__FILE__,__LINE__);\
      return false;\
    }\
\
    /* - retrieve layer neuron count - */\
    long long int neuron_count = (long long int)item_location->v_data_ptr;\
\
    /* - ERROR - */\
    if (neuron_count <= 0 || neuron_count > UINT_MAX)\
    {\
      /* FIXME TODO throw proper exception */\
      BIC_TODO_ERROR(__FILE__,__LINE__);\
      return false;\
    }\
\
    *l_ptr = neuron_count;\
\
  } while(++l_ptr,++p_ptr < p_ptr_end);\
}/*}}}*/

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
  2, fann_train_data_methods,
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
  fann_train_data *ft_ptr = (fann_train_data *)location_ptr->v_data_ptr;

  if (ft_ptr != nullptr)
  {
    fann_destroy_train(ft_ptr);
  }
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

