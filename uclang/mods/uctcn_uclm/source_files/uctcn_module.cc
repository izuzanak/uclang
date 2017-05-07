
@begin
include "uctcn_module.h"
@end

// - UCTCN indexes of built in classes -
unsigned c_bi_class_traffic_store = c_idx_not_exist;
unsigned c_bi_class_tcn_port_config = c_idx_not_exist;
unsigned c_bi_class_traffic_port = c_idx_not_exist;
unsigned c_bi_class_proc_var_set = c_idx_not_exist;
unsigned c_bi_class_proc_variable = c_idx_not_exist;

// - UCTCN module -
built_in_module_s module =
{/*{{{*/
  5,                      // Class count
  uctcn_classes,          // Classes

  0,                      // Error base index
  38,                     // Error count
  uctcn_error_strings,    // Error strings

  uctcn_initialize,       // Initialize function
  uctcn_print_exception,  // Print exceptions function
};/*}}}*/

// - UCTCN classes -
built_in_class_s *uctcn_classes[] =
{/*{{{*/
  &traffic_store_class,
  &tcn_port_config_class,
  &traffic_port_class,
  &proc_var_set_class,
  &proc_variable_class,
};/*}}}*/

// - UCTCN error strings -
const char *uctcn_error_strings[] =
{/*{{{*/
  "error_TRAFFIC_STORE_MAX_ID_EXCEEDED",
  "error_TRAFFIC_STORE_ALREADY_INITIALIZED_ERROR",
  "error_TRAFFIC_STORE_INITIALIZATION_ERROR",
  "error_TRAFFIC_STORE_LINK_LAYER_START_ERROR",
  "error_TRAFFIC_STORE_LINK_LAYER_STOP_ERROR",
  "error_TRAFFIC_STORE_PORT_CONFIGURATION_READ_ERROR",
  "error_TRAFFIC_STORE_PORT_ALREADY_SUBSCRIBED_ERROR",
  "error_TRAFFIC_STORE_CANNOT_FIND_PORT_CONFIGURATION",
  "error_TRAFFIC_STORE_PORT_SUBSCRIBE_ERROR",
  "error_TRAFFIC_PORT_INVALID_DATASET_SIZE",
  "error_TRAFFIC_PORT_PUT_DATASET_ERROR",
  "error_TRAFFIC_PORT_GET_DATASET_ERROR",
  "error_TRAFFIC_PORT_GET_DATASET_NO_DATA_IN_PORT",
  "error_TRAFFIC_PORT_ENABLE_ERROR",
  "error_TRAFFIC_PORT_DISABLE_ERROR",
  "error_PROC_VAR_SET_CREATE_NO_VARIABLES_DEFINED",
  "error_PROC_VAR_SET_CREATE_WRONG_VARIABLE_DESCRIPTION",
  "error_PROC_VAR_SET_CREATE_UNKNOWN_VARIABLE_TYPE",
  "error_PROC_VAR_SET_CREATE_WRONG_ELEMENT_COUNT",
  "error_PROC_VAR_SET_CREATE_NEGATIVE_OFFSET_VALUE",
  "error_PROC_VAR_SET_CREATE_WRONG_BIT_OFFSET_VALUE",
  "error_PROC_VAR_SET_CREATE_VARIABLE_NOT_FIT_TO_PORT",
  "error_PROC_VAR_SET_CREATE_VARIABLE_NAME_IS_ALREADY_USED",
  "error_PROC_VAR_SET_VARIABLE_NAME_NOT_FOUND",
  "error_PROC_VAR_SET_INDEX_EXCEEDS_RANGE",
  "error_PROC_VAR_SET_WRITE_ERROR",
  "error_PROC_VAR_SET_GET_DATSET_ERROR",
  "error_PROC_VAR_SET_READ_ERROR",
  "error_PROC_VAR_SET_READ_NO_DATA_IN_PORT",
  "error_PROC_VAR_SET_FORCE_ERROR",
  "error_PROC_VAR_SET_UNFORCE_ERROR",
  "error_PROC_VARIABLE_SET_UNKNOWN_TYPE",
  "error_PROC_VARIABLE_SET_WRONG_TYPE",
  "error_PROC_VARIABLE_SET_WRONG_ARRAY_ELEMENT_COUNT",
  "error_PROC_VARIABLE_SET_WRONG_ARRAY_ELEMENT_TYPE",
  "error_PROC_VARIABLE_UNIMPLEMENTED_TYPE",
  "error_PROC_VARIABLE_GET_UNKNOWN_TYPE",
  "error_PROC_VARIABLE_GET_STRING_UNSUPPORTED_TYPE",
};/*}}}*/

// - UCTCN initialize -
bool uctcn_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize traffic_store class identifier -
  c_bi_class_traffic_store = class_base_idx++;

  // - initialize tcn_port_config class identifier -
  c_bi_class_tcn_port_config = class_base_idx++;

  // - initialize traffic_port class identifier -
  c_bi_class_traffic_port = class_base_idx++;

  // - initialize proc_var_set class identifier -
  c_bi_class_proc_var_set = class_base_idx++;

  // - initialize proc_variable class identifier -
  c_bi_class_proc_variable = class_base_idx++;

  return true;
}/*}}}*/

// - UCTCN print exception -
bool uctcn_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_TRAFFIC_STORE_MAX_ID_EXCEEDED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTraffic store id %" HOST_LL_FORMAT "d exceeds maximal trafic store id %d\n",exception.params[0],AP_TS_ID_MAX);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRAFFIC_STORE_ALREADY_INITIALIZED_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTraffic store with id %" HOST_LL_FORMAT "d is already initialized\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRAFFIC_STORE_INITIALIZATION_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInitialization of traffic store with id %" HOST_LL_FORMAT "d failed\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRAFFIC_STORE_LINK_LAYER_START_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTraffic store link layer start error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRAFFIC_STORE_LINK_LAYER_STOP_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTraffic store link layer stop error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRAFFIC_STORE_PORT_CONFIGURATION_READ_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTraffic store ports configuration read error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRAFFIC_STORE_PORT_ALREADY_SUBSCRIBED_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTraffic store port %" HOST_LL_FORMAT "d is already subscribed\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRAFFIC_STORE_CANNOT_FIND_PORT_CONFIGURATION:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot find configuration of requested port\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRAFFIC_STORE_PORT_SUBSCRIBE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTraffic store, subscription of port %" HOST_LL_FORMAT "d failed\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRAFFIC_PORT_INVALID_DATASET_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid dataset size %" HOST_LL_FORMAT "d, traffic port size is %" HOST_LL_FORMAT "d\n",exception.params[0],exception.params[1]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRAFFIC_PORT_PUT_DATASET_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while writing data to traffic port\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRAFFIC_PORT_GET_DATASET_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while reading data from traffic port\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRAFFIC_PORT_GET_DATASET_NO_DATA_IN_PORT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nNo data to read from traffic port\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRAFFIC_PORT_ENABLE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while enabling traffic port\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRAFFIC_PORT_DISABLE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while disabling traffic port\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PROC_VAR_SET_CREATE_NO_VARIABLES_DEFINED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nThere are no variables defined for new process variable set\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PROC_VAR_SET_CREATE_WRONG_VARIABLE_DESCRIPTION:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong description of variable at position %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PROC_VAR_SET_CREATE_UNKNOWN_VARIABLE_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUnknown variable type at position %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PROC_VAR_SET_CREATE_WRONG_ELEMENT_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong element count at position %" HOST_LL_FORMAT "d, should be zero for variable, not zero for array\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PROC_VAR_SET_CREATE_NEGATIVE_OFFSET_VALUE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nNegative offset value of variable at position %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PROC_VAR_SET_CREATE_WRONG_BIT_OFFSET_VALUE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong bit offset value of variable at position %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PROC_VAR_SET_CREATE_VARIABLE_NOT_FIT_TO_PORT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nVariable at position %" HOST_LL_FORMAT "d do not fit to target port\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PROC_VAR_SET_CREATE_VARIABLE_NAME_IS_ALREADY_USED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nName \"%s\" of process variable at position %" HOST_LL_FORMAT "d is already in use\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data,exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PROC_VAR_SET_VARIABLE_NAME_NOT_FOUND:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nProcess variable \"%s\" was not found in set\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PROC_VAR_SET_INDEX_EXCEEDS_RANGE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nIndex %" HOST_LL_FORMAT "d exceeds varstore range\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PROC_VAR_SET_WRITE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nProcess variable set write error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PROC_VAR_SET_GET_DATSET_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nProcess variable set, get dataset error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PROC_VAR_SET_READ_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nProcess variable set read error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PROC_VAR_SET_READ_NO_DATA_IN_PORT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nProcess variable set read, no data in port\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PROC_VAR_SET_FORCE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nProcess variable set force error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PROC_VAR_SET_UNFORCE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nProcess variable set unforce error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PROC_VARIABLE_SET_UNKNOWN_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nProcess variable set error, unknown variable type\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PROC_VARIABLE_SET_WRONG_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nProcess variable wrong value type, expected %s\n",it.class_symbol_names[it.class_records[exception.params[0]].name_idx].data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PROC_VARIABLE_SET_WRONG_ARRAY_ELEMENT_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nProcess variable wrong array element count %" HOST_LL_FORMAT "d, expected %" HOST_LL_FORMAT "d\n",exception.params[0],exception.params[1]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PROC_VARIABLE_SET_WRONG_ARRAY_ELEMENT_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nProcess variable wrong array element type, expected %s\n",it.class_symbol_names[it.class_records[exception.params[0]].name_idx].data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PROC_VARIABLE_UNIMPLEMENTED_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUnimplemented type of process variable\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PROC_VARIABLE_GET_UNKNOWN_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nProcess variable get error, unknown variable type\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PROC_VARIABLE_GET_STRING_UNSUPPORTED_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nProcess variable get string error, unsupported variable type\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class TRAFFIC_STORE -
built_in_class_s traffic_store_class =
{/*{{{*/
  "TrafficStore",
  c_modifier_public | c_modifier_final,
  8, traffic_store_methods,
  6, traffic_store_variables,
  bic_traffic_store_consts,
  bic_traffic_store_init,
  bic_traffic_store_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s traffic_store_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_traffic_store_operator_binary_equal
  },
  {
    "TrafficStore#1",
    c_modifier_public | c_modifier_final,
    bic_traffic_store_method_TrafficStore_1
  },
  {
    "start#0",
    c_modifier_public | c_modifier_final,
    bic_traffic_store_method_start_0
  },
  {
    "stop#0",
    c_modifier_public | c_modifier_final,
    bic_traffic_store_method_stop_0
  },
  {
    "port_config#0",
    c_modifier_public | c_modifier_final,
    bic_traffic_store_method_port_config_0
  },
  {
    "get_port#1",
    c_modifier_public | c_modifier_final,
    bic_traffic_store_method_get_port_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_traffic_store_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_traffic_store_method_print_0
  },
};/*}}}*/

built_in_variable_s traffic_store_variables[] =
{/*{{{*/

  // - traffic store constants -
  { "AP_TS_ID_MAX", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAX_PORT_SZ", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NUM_PAGES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAX_FRESHNESS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAX_NR_CHG_PORTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "LP_PAGE_MSK", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_traffic_store_consts(location_array_s &const_locations)
{/*{{{*/

  // - traffic store constants -
  {
    const_locations.push_blanks(6);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 6);

#define CREATE_TRAFFIC_STORE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_TRAFFIC_STORE_BIC_STATIC(AP_TS_ID_MAX);
    CREATE_TRAFFIC_STORE_BIC_STATIC(MAX_PORT_SZ);
    CREATE_TRAFFIC_STORE_BIC_STATIC(NUM_PAGES);
    CREATE_TRAFFIC_STORE_BIC_STATIC(MAX_FRESHNESS);
    CREATE_TRAFFIC_STORE_BIC_STATIC(MAX_NR_CHG_PORTS);
    CREATE_TRAFFIC_STORE_BIC_STATIC(LP_PAGE_MSK);
  }

}/*}}}*/

void bic_traffic_store_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (traffic_store_s *)NULL;
}/*}}}*/

void bic_traffic_store_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  traffic_store_s *ts_ptr = (traffic_store_s *)location_ptr->v_data_ptr;

  if (ts_ptr != NULL)
  {
    ts_ptr->clear(it);
    cfree(ts_ptr);
  }
}/*}}}*/

bool bic_traffic_store_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_traffic_store_method_TrafficStore_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int ts_id;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,ts_id))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("TrafficStore#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - ERROR -
  if (ts_id > AP_TS_ID_MAX)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRAFFIC_STORE_MAX_ID_EXCEEDED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(ts_id);

    return false;
  }

  // - ERROR -
  if (g_uctcn.ts_initialized[ts_id])
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRAFFIC_STORE_ALREADY_INITIALIZED_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(ts_id);

    return false;
  }

  // - ERROR -
  if (lsa_init(ts_id,NULL) != LS_OK)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRAFFIC_STORE_INITIALIZATION_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(ts_id);

    return false;
  }

  // - ERROR -
  if (lp_init(ts_id,&sLpAdapter) != LP_OK)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRAFFIC_STORE_INITIALIZATION_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(ts_id);

    return false;
  }

  // - flag traffic store as initialized -
  g_uctcn.ts_initialized[ts_id] = true;

  // - create traffic store object -
  traffic_store_s *ts_ptr = (traffic_store_s *)cmalloc(sizeof(traffic_store_s));
  ts_ptr->init();

  // - set traffic store id -
  ts_ptr->ts_id = ts_id;

  dst_location->v_data_ptr = (traffic_store_s *)ts_ptr;

  return true;
}/*}}}*/

bool bic_traffic_store_method_start_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve traffic store pointer -
  traffic_store_s *ts_ptr = (traffic_store_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (lsa_start(ts_ptr->ts_id) != LS_OK)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TRAFFIC_STORE_LINK_LAYER_START_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_traffic_store_method_stop_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve traffic store pointer -
  traffic_store_s *ts_ptr = (traffic_store_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (lsa_stop(ts_ptr->ts_id) != LS_OK)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TRAFFIC_STORE_LINK_LAYER_STOP_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_traffic_store_method_port_config_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve traffic store pointer -
  traffic_store_s *ts_ptr = (traffic_store_s *)dst_location->v_data_ptr;

  U16 port_cnt = 0;
  SPortConfig *port_cfg = NULL;

  // - ERROR -
  if (lp_get_config(ts_ptr->ts_id,&port_cnt,&port_cfg) != LP_OK)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TRAFFIC_STORE_PORT_CONFIGURATION_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  pointer_array_s *array_ptr = it.get_new_array_ptr();

  // - if there are some ports -
  if (port_cnt > 0)
  {
    SPortConfig *p_ptr = port_cfg;
    SPortConfig *p_ptr_end = p_ptr + port_cnt;

    do
    {
      SPortConfig *port_cfg_ptr = (SPortConfig *)cmalloc(sizeof(SPortConfig));
      *port_cfg_ptr = *p_ptr;

      // - create new port config location -
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_tcn_port_config,port_cfg_ptr);
      array_ptr->push(new_location);

    }
    while(++p_ptr < p_ptr_end);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_traffic_store_method_get_port_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int port_addr;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,port_addr))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("get_port#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve traffic store pointer -
  traffic_store_s *ts_ptr = (traffic_store_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (ts_ptr->subscribed_ports.get_idx(port_addr) != c_idx_not_exist)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRAFFIC_STORE_PORT_ALREADY_SUBSCRIBED_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(port_addr);

    return false;
  }

  // - ports configuration -
  U16 port_cnt = 0;
  SPortConfig *port_cfg = NULL;

  // - ERROR -
  if (lp_get_config(ts_ptr->ts_id,&port_cnt,&port_cfg) != LP_OK)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TRAFFIC_STORE_PORT_CONFIGURATION_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (port_cnt == 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TRAFFIC_STORE_CANNOT_FIND_PORT_CONFIGURATION,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - find requested port -
  SPortConfig *port_cfg_ptr = NULL;
  SPortConfig *pc_ptr = port_cfg;
  SPortConfig *pc_ptr_end = pc_ptr + port_cnt;

  do
  {
    if (pc_ptr->u12PortAddr == port_addr)
    {
      port_cfg_ptr = pc_ptr;
      break;
    }
  }
  while(++pc_ptr < pc_ptr_end);

  // - ERROR -
  if (port_cfg_ptr == NULL)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TRAFFIC_STORE_CANNOT_FIND_PORT_CONFIGURATION,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create tcn dataset name -
  SDsName ds_name;
  ds_name.u4TrafficStoreId = ts_ptr->ts_id;
  ds_name.u12PortAddress = port_addr;

  // - ERROR -
  if (ds_subscribe(&ds_name,NULL,NULL) != LP_OK)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRAFFIC_STORE_PORT_SUBSCRIBE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(port_addr);

    return false;
  }

  // - insert port to set of subscribed ports -
  ts_ptr->subscribed_ports.insert(port_addr);

  // - create traffic port object -
  traffic_port_s *tp_ptr = (traffic_port_s *)cmalloc(sizeof(traffic_port_s));
  tp_ptr->init();

  // - set traffic store reference -
  dst_location->v_reference_cnt.atomic_inc();
  tp_ptr->ts_ptr = dst_location;

  // - set tcn dataset name -
  tp_ptr->ds_name = ds_name;

  // - set port configuration -
  tp_ptr->port_cfg = *port_cfg_ptr;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_traffic_port,tp_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_traffic_store_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TrafficStore"),"TrafficStore")
  );

  return true;
}/*}}}*/

bool bic_traffic_store_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("TrafficStore");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class TCN_PORT_CONFIG -
built_in_class_s tcn_port_config_class =
{/*{{{*/
  "TcnPortConfig",
  c_modifier_public | c_modifier_final,
  8, tcn_port_config_methods,
  13, tcn_port_config_variables,
  bic_tcn_port_config_consts,
  bic_tcn_port_config_init,
  bic_tcn_port_config_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s tcn_port_config_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_tcn_port_config_operator_binary_equal
  },
  {
    "traffic_store_id#0",
    c_modifier_public | c_modifier_final,
    bic_tcn_port_config_method_traffic_store_id_0
  },
  {
    "address#0",
    c_modifier_public | c_modifier_final,
    bic_tcn_port_config_method_address_0
  },
  {
    "fcode#0",
    c_modifier_public | c_modifier_final,
    bic_tcn_port_config_method_fcode_0
  },
  {
    "config#0",
    c_modifier_public | c_modifier_final,
    bic_tcn_port_config_method_config_0
  },
  {
    "size#0",
    c_modifier_public | c_modifier_final,
    bic_tcn_port_config_method_size_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_tcn_port_config_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_tcn_port_config_method_print_0
  },
};/*}}}*/

built_in_variable_s tcn_port_config_variables[] =
{/*{{{*/

  // - tcn port config type constants -
  { "TYPE_SOURCE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_SINK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_CHECKSUM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_FORCED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_PASSIVE", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - tcn port config fcode constants -
  { "FCODE_PD16", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FCODE_PD32", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FCODE_PD64", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FCODE_PD128", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FCODE_PD256", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FCODE_PD512", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FCODE_PD1024", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FCODE_PDW", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_tcn_port_config_consts(location_array_s &const_locations)
{/*{{{*/

  // - tcn port config type constants -
  {
    const_locations.push_blanks(5);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 5);

#define CREATE_TCN_PORT_CONFIG_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_TCN_PORT_CONFIG_TYPE_BIC_STATIC(port_src);
    CREATE_TCN_PORT_CONFIG_TYPE_BIC_STATIC(port_snk);
    CREATE_TCN_PORT_CONFIG_TYPE_BIC_STATIC(port_twc);
    CREATE_TCN_PORT_CONFIG_TYPE_BIC_STATIC(port_frc);
    CREATE_TCN_PORT_CONFIG_TYPE_BIC_STATIC(port_psv);
  }

  // - tcn port config fcode constants -
  {
    const_locations.push_blanks(8);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 8);

#define CREATE_TCN_PORT_CONFIG_FCODE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_TCN_PORT_CONFIG_FCODE_BIC_STATIC(fcode_pd16);
    CREATE_TCN_PORT_CONFIG_FCODE_BIC_STATIC(fcode_pd32);
    CREATE_TCN_PORT_CONFIG_FCODE_BIC_STATIC(fcode_pd64);
    CREATE_TCN_PORT_CONFIG_FCODE_BIC_STATIC(fcode_pd128);
    CREATE_TCN_PORT_CONFIG_FCODE_BIC_STATIC(fcode_pd256);
    CREATE_TCN_PORT_CONFIG_FCODE_BIC_STATIC(fcode_pd512);
    CREATE_TCN_PORT_CONFIG_FCODE_BIC_STATIC(fcode_pd1024);
    CREATE_TCN_PORT_CONFIG_FCODE_BIC_STATIC(fcode_pdw);
  }

}/*}}}*/

void bic_tcn_port_config_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (SPortConfig *)NULL;
}/*}}}*/

void bic_tcn_port_config_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  SPortConfig *port_cfg_ptr = (SPortConfig *)location_ptr->v_data_ptr;

  if (port_cfg_ptr != NULL)
  {
    cfree(port_cfg_ptr);
  }
}/*}}}*/

bool bic_tcn_port_config_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_tcn_port_config_method_traffic_store_id_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  SPortConfig *port_cfg_ptr = (SPortConfig *)dst_location->v_data_ptr;

  long long int result = port_cfg_ptr->u4TsId;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_tcn_port_config_method_address_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  SPortConfig *port_cfg_ptr = (SPortConfig *)dst_location->v_data_ptr;

  long long int result = port_cfg_ptr->u12PortAddr;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_tcn_port_config_method_fcode_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  SPortConfig *port_cfg_ptr = (SPortConfig *)dst_location->v_data_ptr;

  long long int result = port_cfg_ptr->u4FCode;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_tcn_port_config_method_config_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  SPortConfig *port_cfg_ptr = (SPortConfig *)dst_location->v_data_ptr;

  long long int result = port_cfg_ptr->u4PortCfg;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_tcn_port_config_method_size_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  SPortConfig *port_cfg_ptr = (SPortConfig *)dst_location->v_data_ptr;

  long long int result = port_cfg_ptr->u8PortSize;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_tcn_port_config_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TcnPortConfig"),"TcnPortConfig")
  );

  return true;
}/*}}}*/

bool bic_tcn_port_config_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("TcnPortConfig");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class TRAFFIC_PORT -
built_in_class_s traffic_port_class =
{/*{{{*/
  "TrafficPort",
  c_modifier_public | c_modifier_final,
  9, traffic_port_methods,
  0, traffic_port_variables,
  bic_traffic_port_consts,
  bic_traffic_port_init,
  bic_traffic_port_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s traffic_port_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_traffic_port_operator_binary_equal
  },
  {
    "port_config#0",
    c_modifier_public | c_modifier_final,
    bic_traffic_port_method_port_config_0
  },
  {
    "create_set#1",
    c_modifier_public | c_modifier_final,
    bic_traffic_port_method_create_set_1
  },
  {
    "put_dataset#1",
    c_modifier_public | c_modifier_final,
    bic_traffic_port_method_put_dataset_1
  },
  {
    "get_dataset#0",
    c_modifier_public | c_modifier_final,
    bic_traffic_port_method_get_dataset_0
  },
  {
    "enable#0",
    c_modifier_public | c_modifier_final,
    bic_traffic_port_method_enable_0
  },
  {
    "disable#0",
    c_modifier_public | c_modifier_final,
    bic_traffic_port_method_disable_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_traffic_port_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_traffic_port_method_print_0
  },
};/*}}}*/

built_in_variable_s traffic_port_variables[] =
{/*{{{*/
};/*}}}*/

void bic_traffic_port_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_traffic_port_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (traffic_port_s *)NULL;
}/*}}}*/

void bic_traffic_port_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  traffic_port_s *tp_ptr = (traffic_port_s *)location_ptr->v_data_ptr;

  if (tp_ptr != NULL)
  {
    traffic_store_s *ts_ptr = (traffic_store_s *)tp_ptr->ts_ptr->v_data_ptr;
    ui_rb_tree_s &subscribed_ports = ts_ptr->subscribed_ports;

    unsigned idx = subscribed_ports.get_idx(tp_ptr->ds_name.u12PortAddress);
    cassert(idx != c_idx_not_exist);

    // - desubscribe tcn dataset -
    ds_desubscribe(&tp_ptr->ds_name);

    // - remove port from set of subscribed ports -
    subscribed_ports.remove(idx);

    tp_ptr->clear(it);
    cfree(tp_ptr);
  }
}/*}}}*/

bool bic_traffic_port_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_traffic_port_method_port_config_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  traffic_port_s *tp_ptr = (traffic_port_s *)dst_location->v_data_ptr;

  SPortConfig *port_cfg_ptr = (SPortConfig *)cmalloc(sizeof(SPortConfig));
  *port_cfg_ptr = tp_ptr->port_cfg;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_tcn_port_config,port_cfg_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_traffic_port_method_create_set_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_array)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("create_set#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  traffic_port_s *tp_ptr = (traffic_port_s *)dst_location->v_data_ptr;

  // - create process variable set object -
  proc_var_set_s *pvs_ptr = (proc_var_set_s *)cmalloc(sizeof(proc_var_set_s));
  pvs_ptr->init();

  // - set traffic port reference -
  dst_location->v_reference_cnt.atomic_inc();
  pvs_ptr->tp_ptr = dst_location;

  // - allocate data buffer for variables -
  unsigned var_data_size = tp_ptr->port_cfg.u8PortSize*sizeof(char);
  pvs_ptr->var_data = (char *)cmalloc(var_data_size);
  memset(pvs_ptr->var_data,0,var_data_size);

  // - set freshness to maximal value -
  pvs_ptr->freshness = 0xffff;

  // - set pv_set properties -
  SPvSet &pv_set = pvs_ptr->pv_set;
  pv_set.pu16Freshtime = &pvs_ptr->freshness;
  pv_set.sDatasetName = tp_ptr->ds_name;
  pv_set.u16CPvList = 0;
  pv_set.asPvList = NULL;

  // - retrieve variable configuration -
  pointer_array_s *vars_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (vars_ptr->used == 0)
  {
    pvs_ptr->clear(it);
    cfree(pvs_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_PROC_VAR_SET_CREATE_NO_VARIABLES_DEFINED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  unsigned v_idx = 0;
  do
  {
    location_s *var_location = it.get_location_value(vars_ptr->data[v_idx]);

    // - ERROR -
    if (var_location->v_type != c_bi_class_array)
    {
      pvs_ptr->clear(it);
      cfree(pvs_ptr);

      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PROC_VAR_SET_CREATE_WRONG_VARIABLE_DESCRIPTION,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(v_idx);

      return false;
    }

    pointer_array_s *var_ptr = (pointer_array_s *)var_location->v_data_ptr;

    // - ERROR -
    if (var_ptr->used < 5)
    {
      pvs_ptr->clear(it);
      cfree(pvs_ptr);

      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PROC_VAR_SET_CREATE_WRONG_VARIABLE_DESCRIPTION,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(v_idx);

      return false;
    }

    location_s *var_name_loc   = it.get_location_value(var_ptr->data[0]);
    location_s *var_type_loc   = it.get_location_value(var_ptr->data[1]);
    location_s *var_count_loc  = it.get_location_value(var_ptr->data[2]);
    location_s *var_offset_loc = it.get_location_value(var_ptr->data[3]);
    location_s *var_bitoff_loc = it.get_location_value(var_ptr->data[4]);

    // - ERROR -

    if (var_name_loc->v_type != c_bi_class_string ||
        var_type_loc->v_type != c_bi_class_integer ||
        var_count_loc->v_type != c_bi_class_integer ||
        var_offset_loc->v_type != c_bi_class_integer ||
        var_bitoff_loc->v_type != c_bi_class_integer)
    {
      pvs_ptr->clear(it);
      cfree(pvs_ptr);

      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PROC_VAR_SET_CREATE_WRONG_VARIABLE_DESCRIPTION,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(v_idx);

      return false;
    }

    string_s *name_ptr = (string_s *)var_name_loc->v_data_ptr;
    int type = (long long int)var_type_loc->v_data_ptr;
    int count = (long long int)var_count_loc->v_data_ptr;
    int offset = (long long int)var_offset_loc->v_data_ptr;
    int bitoff = (long long int)var_bitoff_loc->v_data_ptr;

    // - ERROR -
    if (type < 0 || type > dt_i32_array)
    {
      pvs_ptr->clear(it);
      cfree(pvs_ptr);

      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PROC_VAR_SET_CREATE_UNKNOWN_VARIABLE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(v_idx);

      return false;
    }

    // - flag indicating worng count of value elements -
    bool err_count;

    // - data type is array -
    if (c_type_array[type])
    {
      err_count = count <= 0;

      switch (type)
      {
        case dt_odd_u8_array:
          err_count |= !(count & 0x01);
          break;
        case dt_even_u8_array:
          err_count |= count & 0x01;
          break;
      }
    }

    // - data type is not array -
    else
    {
      err_count = count != 0;
    }

    // - ERROR -
    if (err_count)
    {
      pvs_ptr->clear(it);
      cfree(pvs_ptr);

      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PROC_VAR_SET_CREATE_WRONG_ELEMENT_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(v_idx);

      return false;
    }

    // - ERROR -
    if (offset < 0)
    {
      pvs_ptr->clear(it);
      cfree(pvs_ptr);

      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PROC_VAR_SET_CREATE_NEGATIVE_OFFSET_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(v_idx);

      return false;
    }

    int type_bits = c_type_bits[type];

    // - ERROR -
    if (c_type_bitoff[type] ? (bitoff < 0) || (bitoff > (8 - type_bits)) || (bitoff % type_bits) : bitoff != 0)
    {
      pvs_ptr->clear(it);
      cfree(pvs_ptr);

      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PROC_VAR_SET_CREATE_WRONG_BIT_OFFSET_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(v_idx);

      return false;
    }

    int var_count = c_type_array[type] ? count : 1;
    int bit_size = var_count*c_type_bits[type];

    // - ERROR -
    if (((offset << 3) + bitoff + bit_size) > (tp_ptr->port_cfg.u8PortSize << 3))
    {
      pvs_ptr->clear(it);
      cfree(pvs_ptr);

      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PROC_VAR_SET_CREATE_VARIABLE_NOT_FIT_TO_PORT,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(v_idx);

      return false;
    }

    // - ERROR -
    if (pvs_ptr->name_array.get_idx(*name_ptr) != c_idx_not_exist)
    {
      pvs_ptr->clear(it);
      cfree(pvs_ptr);

      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PROC_VAR_SET_CREATE_VARIABLE_NAME_IS_ALREADY_USED,operands[c_source_pos_idx],var_name_loc);
      new_exception->params.push(v_idx);

      return false;
    }

    // - add variable to set -
    pvs_ptr->add_variable(*name_ptr,type,count,offset,bitoff,bit_size);

  }
  while(++v_idx < vars_ptr->used);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_proc_var_set,pvs_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_traffic_port_method_put_dataset_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("put_dataset#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  traffic_port_s *tp_ptr = (traffic_port_s *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (string_ptr->size - 1 != tp_ptr->port_cfg.u8PortSize)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TRAFFIC_PORT_INVALID_DATASET_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(string_ptr->size - 1);
    new_exception->params.push(tp_ptr->port_cfg.u8PortSize);

    return false;
  }

  // - port data buffer -
  char port_buffer[MAX_PORT_SZ];
  char *port_buff_ptr = port_buffer;

  // - copy data to port buffer -
  if (tp_ptr->port_cfg.u8PortSize == MAX_PORT_SZ)
  {
    // - reference to source string data -
    port_buff_ptr = string_ptr->data;
  }
  else
  {
    // - copy source string data -
    memcpy(port_buffer,string_ptr->data,string_ptr->size - 1);
  }

  // - ERROR -
  if (lp_put_dataset(&tp_ptr->ds_name,port_buff_ptr) != LP_OK)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TRAFFIC_PORT_PUT_DATASET_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_traffic_port_method_get_dataset_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve traffic port object -
  traffic_port_s *tp_ptr = (traffic_port_s *)dst_location->v_data_ptr;

  // - create target string -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->create(MAX_PORT_SZ);

  U16 freshness;

  // - read dataset from traffic store -
  ELpResult res = lp_get_dataset(&tp_ptr->ds_name,string_ptr->data,&freshness);

  // - ERROR -
  if (res != LP_OK)
  {
    string_ptr->clear();
    cfree(string_ptr);

    if (res == LP_NO_DATA)
    {
      exception_s::throw_exception(it,module.error_base + c_error_TRAFFIC_PORT_GET_DATASET_NO_DATA_IN_PORT,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    exception_s::throw_exception(it,module.error_base + c_error_TRAFFIC_PORT_GET_DATASET_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  unsigned str_length = tp_ptr->port_cfg.u8PortSize;

  // - adjust string according to port size -
  string_ptr->data[str_length] = '\0';
  string_ptr->size = str_length + 1;

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_traffic_port_method_enable_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  traffic_port_s *tp_ptr = (traffic_port_s *)dst_location->v_data_ptr;

  // - temporary set -
  SPvSet pv_set = {NULL,tp_ptr->ds_name,0,NULL};

  // - ERROR -
  if (ap_enable_set(&pv_set) != AP_OK)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TRAFFIC_PORT_ENABLE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_traffic_port_method_disable_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  traffic_port_s *tp_ptr = (traffic_port_s *)dst_location->v_data_ptr;

  // - temporary set -
  SPvSet pv_set = {NULL,tp_ptr->ds_name,0,NULL};

  // - ERROR -
  if (ap_disable_set(&pv_set) != AP_OK)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TRAFFIC_PORT_DISABLE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_traffic_port_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TrafficPort"),"TrafficPort")
  );

  return true;
}/*}}}*/

bool bic_traffic_port_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("TrafficPort");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class PROC_VAR_SET -
built_in_class_s proc_var_set_class =
{/*{{{*/
  "ProcVarSet",
  c_modifier_public | c_modifier_final,
  14, proc_var_set_methods,
  0, proc_var_set_variables,
  bic_proc_var_set_consts,
  bic_proc_var_set_init,
  bic_proc_var_set_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s proc_var_set_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_proc_var_set_operator_binary_equal
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_proc_var_set_operator_binary_le_br_re_br
  },
  {
    "freshness#0",
    c_modifier_public | c_modifier_final,
    bic_proc_var_set_method_freshness_0
  },
  {
    "write#0",
    c_modifier_public | c_modifier_final,
    bic_proc_var_set_method_write_0
  },
  {
    "safe_write#0",
    c_modifier_public | c_modifier_final,
    bic_proc_var_set_method_safe_write_0
  },
  {
    "read#0",
    c_modifier_public | c_modifier_final,
    bic_proc_var_set_method_read_0
  },
  {
    "force#0",
    c_modifier_public | c_modifier_final,
    bic_proc_var_set_method_force_0
  },
  {
    "unforce#0",
    c_modifier_public | c_modifier_final,
    bic_proc_var_set_method_unforce_0
  },
  {
    "item#1",
    c_modifier_public | c_modifier_final,
    bic_proc_var_set_method_item_1
  },
  {
    "first_idx#0",
    c_modifier_public | c_modifier_final,
    bic_proc_var_set_method_first_idx_0
  },
  {
    "next_idx#1",
    c_modifier_public | c_modifier_final,
    bic_proc_var_set_method_next_idx_1
  },
  {
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_proc_var_set_method_length_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_proc_var_set_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_proc_var_set_method_print_0
  },
};/*}}}*/

built_in_variable_s proc_var_set_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_PROC_VAR_SET_CHECK_INDEX() \
  /*{{{*/\
  proc_var_set_s *pvs_ptr = (proc_var_set_s *)dst_location->v_data_ptr;\
  \
  /* - ERROR - */\
  if (index < 0 || index >= pvs_ptr->list_array.used) {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PROC_VAR_SET_INDEX_EXCEEDS_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(index);\
    \
    return false;\
  }\
  /*}}}*/

#define BIC_PROC_VAR_SET_ITEM(NAME) \
  {/*{{{*/\
    pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
    location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
    \
    long long int index;\
    \
    if (!it.retrieve_integer(src_0_location,index))\
    {\
      /* - ERROR - */\
      if (src_0_location->v_type != c_bi_class_string)\
      {\
        exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
        BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
        new_exception->params.push(1);\
        new_exception->params.push(src_0_location->v_type);\
        \
        return false;\
      }\
      \
      /* - retrieve process variable set - */\
      proc_var_set_s *pvs_ptr = (proc_var_set_s *)dst_location->v_data_ptr;\
      \
      unsigned idx = pvs_ptr->name_array.get_idx(*((string_s *)src_0_location->v_data_ptr));\
      \
      /* - ERROR - */\
      if (idx == c_idx_not_exist)\
      {\
        exception_s::throw_exception(it,module.error_base + c_error_PROC_VAR_SET_VARIABLE_NAME_NOT_FOUND,operands[c_source_pos_idx],src_0_location);\
        return false;\
      }\
      \
      index = (long long int)idx;\
    }\
    else {\
      BIC_PROC_VAR_SET_CHECK_INDEX();\
    }\
    \
    /* - create new proc variable object - */\
    proc_variable_s *pv_ptr = (proc_variable_s *)cmalloc(sizeof(proc_variable_s));\
    pv_ptr->init();\
    \
    /* - process variable set reference - */\
    dst_location->v_reference_cnt.atomic_inc();\
    pv_ptr->pvs_ptr = dst_location;\
    \
    /* - set variable index - */\
    pv_ptr->var_idx = index;\
    \
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_proc_variable,pv_ptr);\
    BIC_SET_RESULT(new_location);\
    \
    return true;\
  }/*}}}*/

void bic_proc_var_set_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_proc_var_set_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (proc_var_set_s *)NULL;
}/*}}}*/

void bic_proc_var_set_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  proc_var_set_s *pvs_ptr = (proc_var_set_s *)location_ptr->v_data_ptr;

  if (pvs_ptr != NULL)
  {
    pvs_ptr->clear(it);
    cfree(pvs_ptr);
  }
}/*}}}*/

bool bic_proc_var_set_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_proc_var_set_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_PROC_VAR_SET_ITEM("operator_binary_le_br_re_br#1");
}/*}}}*/

bool bic_proc_var_set_method_freshness_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  proc_var_set_s *pvs_ptr = (proc_var_set_s *)dst_location->v_data_ptr;

  long long int result = pvs_ptr->freshness;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_proc_var_set_method_write_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  proc_var_set_s *pvs_ptr = (proc_var_set_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (ap_proc_write_set(&pvs_ptr->pv_set,NULL,
      ap_get_swap_endian(pvs_ptr->pv_set.sDatasetName.u4TrafficStoreId)) != AP_OK)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PROC_VAR_SET_WRITE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_proc_var_set_method_safe_write_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  proc_var_set_s *pvs_ptr = (proc_var_set_s *)dst_location->v_data_ptr;
  traffic_port_s *tp_ptr = (traffic_port_s *)pvs_ptr->tp_ptr->v_data_ptr;

  // - allocate port buffer -
  U8 *port_buffer = (U8 *)cmalloc(tp_ptr->port_cfg.u8PortSize*sizeof(U8));

  // - ERROR -
  if (lp_get_dataset(&pvs_ptr->pv_set.sDatasetName,port_buffer,&pvs_ptr->freshness) != LP_OK)
  {
    cfree(port_buffer);

    exception_s::throw_exception(it,module.error_base + c_error_PROC_VAR_SET_GET_DATSET_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (ap_proc_write_set(&pvs_ptr->pv_set,port_buffer,
      ap_get_swap_endian(pvs_ptr->pv_set.sDatasetName.u4TrafficStoreId)) != AP_OK)
  {
    cfree(port_buffer);

    exception_s::throw_exception(it,module.error_base + c_error_PROC_VAR_SET_WRITE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - release port buffer -
  cfree(port_buffer);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_proc_var_set_method_read_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  proc_var_set_s *pvs_ptr = (proc_var_set_s *)dst_location->v_data_ptr;

  // - read set data from port -
  eAP_RESULT res = ap_proc_read_set(
      &pvs_ptr->pv_set,
      ap_get_swap_endian(pvs_ptr->pv_set.sDatasetName.u4TrafficStoreId));

  // - ERROR -
  if (res != AP_OK)
  {
    if (res == AP_NO_DATA)
    {
      exception_s::throw_exception(it,module.error_base + c_error_PROC_VAR_SET_READ_NO_DATA_IN_PORT,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    exception_s::throw_exception(it,module.error_base + c_error_PROC_VAR_SET_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_proc_var_set_method_force_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  proc_var_set_s *pvs_ptr = (proc_var_set_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (ap_proc_force_set(&pvs_ptr->pv_set,
      ap_get_swap_endian(pvs_ptr->pv_set.sDatasetName.u4TrafficStoreId)) != AP_OK)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PROC_VAR_SET_FORCE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_proc_var_set_method_unforce_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  proc_var_set_s *pvs_ptr = (proc_var_set_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (ap_proc_unforce_set(&pvs_ptr->pv_set,
      ap_get_swap_endian(pvs_ptr->pv_set.sDatasetName.u4TrafficStoreId)) != AP_OK)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PROC_VAR_SET_UNFORCE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_proc_var_set_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_PROC_VAR_SET_ITEM("item#1");
}/*}}}*/

bool bic_proc_var_set_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  proc_var_set_s *pvs_ptr = (proc_var_set_s *)dst_location->v_data_ptr;

  if (pvs_ptr->list_array.used > 0)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,0);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_proc_var_set_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int index;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,index))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("next_idx#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  BIC_PROC_VAR_SET_CHECK_INDEX();

  if (++index < pvs_ptr->list_array.used)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,index);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_proc_var_set_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  proc_var_set_s *pvs_ptr = (proc_var_set_s *)dst_location->v_data_ptr;

  long long int result = pvs_ptr->list_array.used;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_proc_var_set_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("ProcVarSet"),"ProcVarSet")
  );

  return true;
}/*}}}*/

bool bic_proc_var_set_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("ProcVarSet");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class PROC_VARIABLE -
built_in_class_s proc_variable_class =
{/*{{{*/
  "ProcVariable",
  c_modifier_public | c_modifier_final,
  8, proc_variable_methods,
  27 + 6, proc_variable_variables,
  bic_proc_variable_consts,
  bic_proc_variable_init,
  bic_proc_variable_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s proc_variable_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_proc_variable_operator_binary_equal
  },
  {
    "name#0",
    c_modifier_public | c_modifier_final,
    bic_proc_variable_method_name_0
  },
  {
    "get_type#0",
    c_modifier_public | c_modifier_final,
    bic_proc_variable_method_get_type_0
  },
  {
    "set#1",
    c_modifier_public | c_modifier_final,
    bic_proc_variable_method_set_1
  },
  {
    "get#0",
    c_modifier_public | c_modifier_final,
    bic_proc_variable_method_get_0
  },
  {
    "get_string#0",
    c_modifier_public | c_modifier_final,
    bic_proc_variable_method_get_string_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_proc_var_set_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_proc_variable_method_print_0
  },
};/*}}}*/

built_in_variable_s proc_variable_variables[] =
{/*{{{*/

  // - proc variable type constants -
  { "TYPE_BOOLEAN1", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_ANTIVALENT2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_ENUM4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_BITSET8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_UNSIGNED8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_INTEGER8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_CHARACTER8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_BITSET16", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_UNSIGNED16", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_INTEGER16", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_BIPOLAR_16_14", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_UNIPOLAR_16_14", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_BIPOLAR_16_12", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_REAL32", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_BITSET32", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_UNSIGNED32", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_INTEGER32", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_TIMEDATE48", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_BITSET64", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_UNSIGNED64", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_INTEGER64", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_ODD_U8_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_EVEN_U8_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_U16_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_I16_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_U32_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_I32_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - proc variable check values -
  { "VR_ERROR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VR_VALID", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VR_FALSE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VR_FORCED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VR_TRUE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "VR_UNDEFINED", c_modifier_public | c_modifier_static | c_modifier_static_const },
};/*}}}*/

void bic_proc_variable_consts(location_array_s &const_locations)
{/*{{{*/

  // - proc variable type constants -
  {
    const_locations.push_blanks(27);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 27);

#define CREATE_PROC_VARIABLE_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_PROC_VARIABLE_TYPE_BIC_STATIC(dt_boolean1);
    CREATE_PROC_VARIABLE_TYPE_BIC_STATIC(dt_antivalent2);
    CREATE_PROC_VARIABLE_TYPE_BIC_STATIC(dt_enum4);
    CREATE_PROC_VARIABLE_TYPE_BIC_STATIC(dt_bitset8);
    CREATE_PROC_VARIABLE_TYPE_BIC_STATIC(dt_unsigned8);
    CREATE_PROC_VARIABLE_TYPE_BIC_STATIC(dt_integer8);
    CREATE_PROC_VARIABLE_TYPE_BIC_STATIC(dt_character8);
    CREATE_PROC_VARIABLE_TYPE_BIC_STATIC(dt_bitset16);
    CREATE_PROC_VARIABLE_TYPE_BIC_STATIC(dt_unsigned16);
    CREATE_PROC_VARIABLE_TYPE_BIC_STATIC(dt_integer16);
    CREATE_PROC_VARIABLE_TYPE_BIC_STATIC(dt_bipolar_16_14);
    CREATE_PROC_VARIABLE_TYPE_BIC_STATIC(dt_unipolar_16_14);
    CREATE_PROC_VARIABLE_TYPE_BIC_STATIC(dt_bipolar_16_12);
    CREATE_PROC_VARIABLE_TYPE_BIC_STATIC(dt_real32);
    CREATE_PROC_VARIABLE_TYPE_BIC_STATIC(dt_bitset32);
    CREATE_PROC_VARIABLE_TYPE_BIC_STATIC(dt_unsigned32);
    CREATE_PROC_VARIABLE_TYPE_BIC_STATIC(dt_integer32);
    CREATE_PROC_VARIABLE_TYPE_BIC_STATIC(dt_timedate48);
    CREATE_PROC_VARIABLE_TYPE_BIC_STATIC(dt_bitset64);
    CREATE_PROC_VARIABLE_TYPE_BIC_STATIC(dt_unsigned64);
    CREATE_PROC_VARIABLE_TYPE_BIC_STATIC(dt_integer64);
    CREATE_PROC_VARIABLE_TYPE_BIC_STATIC(dt_odd_u8_array);
    CREATE_PROC_VARIABLE_TYPE_BIC_STATIC(dt_even_u8_array);
    CREATE_PROC_VARIABLE_TYPE_BIC_STATIC(dt_u16_array);
    CREATE_PROC_VARIABLE_TYPE_BIC_STATIC(dt_i16_array);
    CREATE_PROC_VARIABLE_TYPE_BIC_STATIC(dt_u32_array);
    CREATE_PROC_VARIABLE_TYPE_BIC_STATIC(dt_i32_array);
  }

  // - proc variable check values -
  {
    const_locations.push_blanks(6);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 6);

#define CREATE_PROC_VARIABLE_CHECK_VAL_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_PROC_VARIABLE_CHECK_VAL_BIC_STATIC(VR_ERROR);
    CREATE_PROC_VARIABLE_CHECK_VAL_BIC_STATIC(VR_VALID);
    CREATE_PROC_VARIABLE_CHECK_VAL_BIC_STATIC(VR_FALSE);
    CREATE_PROC_VARIABLE_CHECK_VAL_BIC_STATIC(VR_FORCED);
    CREATE_PROC_VARIABLE_CHECK_VAL_BIC_STATIC(VR_TRUE);
    CREATE_PROC_VARIABLE_CHECK_VAL_BIC_STATIC(VR_UNDEFINED);
  }

}/*}}}*/

void bic_proc_variable_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (proc_variable_s *)NULL;
}/*}}}*/

void bic_proc_variable_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  proc_variable_s *pv_ptr = (proc_variable_s *)location_ptr->v_data_ptr;

  if (pv_ptr != NULL)
  {
    pv_ptr->clear(it);
    cfree(pv_ptr);
  }
}/*}}}*/

bool bic_proc_variable_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_proc_variable_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  proc_variable_s *pv_ptr = (proc_variable_s *)dst_location->v_data_ptr;
  proc_var_set_s *pvs_ptr = (proc_var_set_s *)pv_ptr->pvs_ptr->v_data_ptr;

  // - retrieve variable name -
  string_s *string_ptr = it.get_new_string_ptr();
  *string_ptr = pvs_ptr->name_array[pv_ptr->var_idx];

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_proc_variable_method_get_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  proc_variable_s *pv_ptr = (proc_variable_s *)dst_location->v_data_ptr;
  proc_var_set_s *pvs_ptr = (proc_var_set_s *)pv_ptr->pvs_ptr->v_data_ptr;

  long long int result = pvs_ptr->list_array[pv_ptr->var_idx].u8DerivedType;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_proc_variable_method_set_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  proc_variable_s *pv_ptr = (proc_variable_s *)dst_location->v_data_ptr;
  proc_var_set_s *pvs_ptr = (proc_var_set_s *)pv_ptr->pvs_ptr->v_data_ptr;

  // - retrieve process variable -
  pv_list_s &pv_list = pvs_ptr->list_array[pv_ptr->var_idx];

  switch (pv_list.u8DerivedType)
  {
  case dt_character8:

    // - ERROR -
    exception_s::throw_exception(it,module.error_base + c_error_PROC_VARIABLE_UNIMPLEMENTED_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;

  case dt_boolean1:
  case dt_antivalent2:
  case dt_enum4:
  case dt_bitset8:
  case dt_unsigned8:
  case dt_integer8:
  case dt_bitset16:
  case dt_unsigned16:
  case dt_integer16:
  case dt_bipolar_16_14:
  case dt_unipolar_16_14:
  case dt_bipolar_16_12:
  case dt_bitset32:
  case dt_unsigned32:
  case dt_integer32:
  case dt_timedate48:
  case dt_bitset64:
  case dt_unsigned64:
  case dt_integer64:
  {
    // - ERROR -
    if (src_0_location->v_type != c_bi_class_integer)
    {
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PROC_VARIABLE_SET_WRONG_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(c_bi_class_integer);

      return false;
    }

    long long int value = (long long int)src_0_location->v_data_ptr;

    switch (pv_list.u8DerivedType)
    {
    case dt_boolean1:
    case dt_antivalent2:
    case dt_enum4:
    case dt_bitset8:
    case dt_unsigned8:
    {
      unsigned char data = value;
      *((unsigned char *)pv_list.pVariable) = data;
    }
    break;
    case dt_integer8:
    {
      char data = value;
      *((char *)pv_list.pVariable) = data;
    }
    break;
    case dt_bitset16:
    case dt_unsigned16:
    {
      unsigned short data = value;
      *((unsigned short *)pv_list.pVariable) = data;
    }
    break;
    case dt_integer16:
    {
      short data = value;
      *((short *)pv_list.pVariable) = data;
    }
    break;
    case dt_bipolar_16_14:
    case dt_unipolar_16_14:
    case dt_bipolar_16_12:

      // - ERROR -
      exception_s::throw_exception(it,module.error_base + c_error_PROC_VARIABLE_UNIMPLEMENTED_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;

    case dt_bitset32:
    case dt_unsigned32:
    {
      unsigned data = value;
      *((unsigned *)pv_list.pVariable) = data;
    }
    break;
    case dt_integer32:
    {
      int data = value;
      *((int *)pv_list.pVariable) = data;
    }
    break;
    case dt_timedate48:
    {
      unsigned seconds = value / 1000000000LL;
      unsigned short ticks = ((value % 1000000000LL) * 65536) / 1000000000LL;

      *((unsigned *)pv_list.pVariable) = seconds;
      *((unsigned short *)(((char *)pv_list.pVariable) + sizeof(unsigned))) = ticks;
    }
    break;
    case dt_bitset64:
    case dt_unsigned64:
    {
      long long unsigned data = value;
      *((long long unsigned *)pv_list.pVariable) = data;
    }
    break;
    case dt_integer64:
    {
      long long int data = value;
      *((long long int *)pv_list.pVariable) = data;
    }
    break;
    }
  }
  break;

  case dt_real32:
  {
    // - ERROR -
    if (src_0_location->v_type != c_bi_class_float)
    {
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PROC_VARIABLE_SET_WRONG_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(c_bi_class_float);

      return false;
    }

    double value = (double)src_0_location->v_data_ptr;
    *((float *)pv_list.pVariable) = value;
  }
  break;

  case dt_odd_u8_array:
  case dt_even_u8_array:
    {
      switch (src_0_location->v_type)
      {
        case c_bi_class_string:
          {
            string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

            // - ERROR -
            if (string_ptr->size - 1 != pv_list.u8ArrayCount)
            {
              exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PROC_VARIABLE_SET_WRONG_ARRAY_ELEMENT_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
              new_exception->params.push(string_ptr->size - 1);
              new_exception->params.push(pv_list.u8ArrayCount);

              return false;
            }

            unsigned char *c_ptr = (unsigned char *)string_ptr->data;
            unsigned char *c_ptr_end = c_ptr + string_ptr->size - 1;
            unsigned char *v_ptr = (unsigned char *)pv_list.pVariable;
            do {
              *v_ptr = *c_ptr;
            } while(++v_ptr,++c_ptr < c_ptr_end);
          }
          break;
        case c_bi_class_array:
          {
            pointer_array_s *array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

            // - ERROR -
            if (array_ptr->used != pv_list.u8ArrayCount)
            {
              exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PROC_VARIABLE_SET_WRONG_ARRAY_ELEMENT_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
              new_exception->params.push(array_ptr->used);
              new_exception->params.push(pv_list.u8ArrayCount);

              return false;
            }

            pointer *a_ptr = array_ptr->data;
            pointer *a_ptr_end = a_ptr + array_ptr->used;
            unsigned char *v_ptr = (unsigned char *)pv_list.pVariable;
            long long int value;
            do {
              location_s *item_location = it.get_location_value(*a_ptr);

              // - ERROR -
              if (!it.retrieve_integer(item_location,value))
              {
                exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PROC_VARIABLE_SET_WRONG_ARRAY_ELEMENT_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
                new_exception->params.push(c_bi_class_integer);

                return false;
              }

              *v_ptr = value;
            } while(++v_ptr,++a_ptr < a_ptr_end);
          }
          break;

        // - ERROR -
        default:
          exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PROC_VARIABLE_SET_WRONG_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
          new_exception->params.push(c_bi_class_array);

          return false;
      }
    }
    break;
  case dt_u16_array:
  case dt_i16_array:
  case dt_u32_array:
  case dt_i32_array:

    // - ERROR -
    exception_s::throw_exception(it,module.error_base + c_error_PROC_VARIABLE_UNIMPLEMENTED_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;

  // - ERROR -
  default:

    exception_s::throw_exception(it,module.error_base + c_error_PROC_VARIABLE_SET_UNKNOWN_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_proc_variable_method_get_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  proc_variable_s *pv_ptr = (proc_variable_s *)dst_location->v_data_ptr;
  proc_var_set_s *pvs_ptr = (proc_var_set_s *)pv_ptr->pvs_ptr->v_data_ptr;

  // - retrieve process variable -
  pv_list_s &pv_list = pvs_ptr->list_array[pv_ptr->var_idx];

  switch (pv_list.u8DerivedType)
  {
  case dt_character8:

    // - ERROR -
    exception_s::throw_exception(it,module.error_base + c_error_PROC_VARIABLE_UNIMPLEMENTED_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;

  case dt_boolean1:
  case dt_antivalent2:
  case dt_enum4:
  case dt_bitset8:
  case dt_unsigned8:
  case dt_integer8:
  case dt_bitset16:
  case dt_unsigned16:
  case dt_integer16:
  case dt_bipolar_16_14:
  case dt_unipolar_16_14:
  case dt_bipolar_16_12:
  case dt_bitset32:
  case dt_unsigned32:
  case dt_integer32:
  case dt_timedate48:
  case dt_bitset64:
  case dt_unsigned64:
  case dt_integer64:
  {
    long long int result = 0;

    switch (pv_list.u8DerivedType)
    {
    case dt_boolean1:
    case dt_antivalent2:
    case dt_enum4:
    case dt_bitset8:
    case dt_unsigned8:
    {
      unsigned char data = *((unsigned char *)pv_list.pVariable);
      result = data;
    }
    break;
    case dt_integer8:
    {
      char data = *((char *)pv_list.pVariable);
      result = data;
    }
    break;
    case dt_bitset16:
    case dt_unsigned16:
    {
      unsigned short data = *((unsigned short *)pv_list.pVariable);
      result = data;
    }
    break;
    case dt_integer16:
    {
      short data = *((short *)pv_list.pVariable);
      result = data;
    }
    break;
    case dt_bipolar_16_14:
    case dt_unipolar_16_14:
    case dt_bipolar_16_12:

      // - ERROR -
      exception_s::throw_exception(it,module.error_base + c_error_PROC_VARIABLE_UNIMPLEMENTED_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;

    case dt_bitset32:
    case dt_unsigned32:
    {
      unsigned int data = *((unsigned int *)pv_list.pVariable);
      result = data;
    }
    break;
    case dt_integer32:
    {
      int data = *((int *)pv_list.pVariable);
      result = data;
    }
    break;
    case dt_timedate48:
    {
      unsigned seconds = *((unsigned *)pv_list.pVariable);
      unsigned short ticks = *((unsigned short *)(((char *)pv_list.pVariable) + sizeof(unsigned)));

      result = seconds*1000000000LL + (ticks * 1000000000LL) / 65536;
    }
    break;
    case dt_bitset64:
    case dt_unsigned64:
    {
      long long unsigned data = *((long long unsigned *)pv_list.pVariable);
      result = data;
    }
    break;
    case dt_integer64:
    {
      long long int data = *((long long int *)pv_list.pVariable);
      result = data;
    }
    break;
    }

    BIC_SIMPLE_SET_RES(c_bi_class_integer,result);
  }
  break;

  case dt_real32:
  {
    double result = *((float *)pv_list.pVariable);

    BIC_SIMPLE_SET_RES(c_bi_class_float,result);
  }
  break;

  case dt_odd_u8_array:
  case dt_even_u8_array:
  {
    pointer_array_s *array_ptr = it.get_new_array_ptr();

    if (pv_list.u8ArrayCount > 0)
    {
      unsigned char *v_ptr = (unsigned char *)pv_list.pVariable;
      unsigned char *v_ptr_end = v_ptr + pv_list.u8ArrayCount;
      do {
        long long int value = *v_ptr;

        BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);
        array_ptr->push(new_location);

      } while(++v_ptr < v_ptr_end);
    }

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
    BIC_SET_RESULT(new_location);
  }
  break;

  case dt_u16_array:
  case dt_i16_array:
  case dt_u32_array:
  case dt_i32_array:

    // - ERROR -
    exception_s::throw_exception(it,module.error_base + c_error_PROC_VARIABLE_UNIMPLEMENTED_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;

  // - ERROR -
  default:

    exception_s::throw_exception(it,module.error_base + c_error_PROC_VARIABLE_GET_UNKNOWN_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  return true;
}/*}}}*/

bool bic_proc_variable_method_get_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  proc_variable_s *pv_ptr = (proc_variable_s *)dst_location->v_data_ptr;
  proc_var_set_s *pvs_ptr = (proc_var_set_s *)pv_ptr->pvs_ptr->v_data_ptr;

  // - retrieve process variable -
  pv_list_s &pv_list = pvs_ptr->list_array[pv_ptr->var_idx];

  switch (pv_list.u8DerivedType)
  {
  case dt_odd_u8_array:
  case dt_even_u8_array:
  {
    string_s *string_ptr = it.get_new_string_ptr();

    if (pv_list.u8ArrayCount > 0)
    {
      string_ptr->create(pv_list.u8ArrayCount);

      unsigned char *v_ptr = (unsigned char *)pv_list.pVariable;
      unsigned char *v_ptr_end = v_ptr + pv_list.u8ArrayCount;
      unsigned char *c_ptr = (unsigned char *)string_ptr->data;
      do {
        *c_ptr = *v_ptr;
      } while(++c_ptr,++v_ptr < v_ptr_end);
    }

    BIC_SET_RESULT_STRING(string_ptr);
  }
  break;

  // - ERROR -
  default:

    exception_s::throw_exception(it,module.error_base + c_error_PROC_VARIABLE_GET_STRING_UNSUPPORTED_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  return true;
}/*}}}*/

bool bic_proc_variable_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("ProcVariable"),"ProcVariable")
  );

  return true;
}/*}}}*/

bool bic_proc_variable_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("ProcVariable");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

