
@begin
include "latlon_module.h"
@end

// - LATLON indexes of built in classes -
unsigned c_bi_class_latlon = c_idx_not_exist;

// - LATLON indexes of remote classes -
unsigned c_rm_class_dict = c_idx_not_exist;

// - LATLON module -
EXPORT built_in_module_s module =
{/*{{{*/
  1,                      // Class count
  latlon_classes,         // Classes

  0,                      // Error base index
  1,                      // Error count
  latlon_error_strings,   // Error strings

  latlon_initialize,      // Initialize function
  latlon_print_exception, // Print exceptions function
};/*}}}*/

// - LATLON classes -
built_in_class_s *latlon_classes[] =
{/*{{{*/
  &latlon_class,
};/*}}}*/

// - LATLON error strings -
const char *latlon_error_strings[] =
{/*{{{*/
  "error_LATLON_DUMMY_ERROR",
};/*}}}*/

// - LATLON initialize -
bool latlon_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize latlon class identifier -
  c_bi_class_latlon = class_base_idx++;

  return true;
}/*}}}*/

// - LATLON print exception -
bool latlon_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_LATLON_DUMMY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nLatlon dummy error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class LATLON -
built_in_class_s latlon_class =
{/*{{{*/
  "LatLon",
  c_modifier_public | c_modifier_final,
  8, latlon_methods,
  0, latlon_variables,
  bic_latlon_consts,
  bic_latlon_init,
  bic_latlon_clear,
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

built_in_method_s latlon_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_latlon_operator_binary_equal
  },
  {
    "LatLon#2",
    c_modifier_public | c_modifier_final,
    bic_latlon_method_LatLon_2
  },
  {
    "lat#0",
    c_modifier_public | c_modifier_final,
    bic_latlon_method_lat_0
  },
  {
    "lon#0",
    c_modifier_public | c_modifier_final,
    bic_latlon_method_lon_0
  },
  {
    "distance#1",
    c_modifier_public | c_modifier_final,
    bic_latlon_method_distance_1
  },
  {
    "angle#1",
    c_modifier_public | c_modifier_final,
    bic_latlon_method_angle_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_latlon_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_latlon_method_print_0
  },
};/*}}}*/

built_in_variable_s latlon_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_latlon_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_latlon_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (latlon_s *)nullptr;
}/*}}}*/

void bic_latlon_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  latlon_s *ll_ptr = (latlon_s *)location_ptr->v_data_ptr;

  if (ll_ptr != nullptr)
  {
    ll_ptr->clear(it);
    cfree(ll_ptr);
  }
}/*}}}*/

bool bic_latlon_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_latlon_method_LatLon_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
lat:retrieve_float
lon:retrieve_float
>
method LatLon
; @end

  // - create latlon object -
  latlon_s *ll_ptr = (latlon_s *)cmalloc(sizeof(latlon_s));
  ll_ptr->init();

  ll_ptr->lat = lat;
  ll_ptr->lon = lon;

  dst_location->v_data_ptr = (latlon_s *)ll_ptr;

  return true;
}/*}}}*/

bool bic_latlon_method_lat_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  double result = ((latlon_s *)dst_location->v_data_ptr)->lat;

  BIC_SIMPLE_SET_RES(c_bi_class_float,result);

  return true;
}/*}}}*/

bool bic_latlon_method_lon_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  double result = ((latlon_s *)dst_location->v_data_ptr)->lon;

  BIC_SIMPLE_SET_RES(c_bi_class_float,result);

  return true;
}/*}}}*/

bool bic_latlon_method_distance_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
second:c_bi_class_latlon
>
method distance
; @end

  double result =
    ((latlon_s *)dst_location->v_data_ptr)->distance(
    *((latlon_s *)src_0_location->v_data_ptr));

  BIC_SIMPLE_SET_RES(c_bi_class_float,result);

  return true;
}/*}}}*/

bool bic_latlon_method_angle_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
second:c_bi_class_latlon
>
method angle
; @end

  double result =
    ((latlon_s *)dst_location->v_data_ptr)->angle(
    *((latlon_s *)src_0_location->v_data_ptr));

  BIC_SIMPLE_SET_RES(c_bi_class_float,result);

  return true;
}/*}}}*/

bool bic_latlon_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING(
    latlon_s *ll_ptr = (latlon_s *)dst_location->v_data_ptr;
    string_ptr->setf("(lat:%f,lon:%f)",ll_ptr->lat,ll_ptr->lon);
  );

  return true;
}/*}}}*/

bool bic_latlon_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  latlon_s *ll_ptr = (latlon_s *)dst_location->v_data_ptr;
  printf("(lat:%f,lon:%f)",ll_ptr->lat,ll_ptr->lon);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

