
@begin
include "tzone_module.h"
@end

// - TZONE indexes of built in classes -
unsigned c_bi_class_time_zone = c_idx_not_exist;

// - TZONE module -
EXPORT built_in_module_s module =
{/*{{{*/
  1,                     // Class count
  tzone_classes,         // Classes

  0,                     // Error base index
  1,                     // Error count
  tzone_error_strings,   // Error strings

  tzone_initialize,      // Initialize function
  tzone_print_exception, // Print exceptions function
};/*}}}*/

// - TZONE classes -
built_in_class_s *tzone_classes[] =
{/*{{{*/
  &time_zone_class,
};/*}}}*/

// - TZONE error strings -
const char *tzone_error_strings[] =
{/*{{{*/
  "error_TIME_ZONE_PARSE_ERROR",
};/*}}}*/

// - TZONE initialize -
bool tzone_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize time class identifier -
  c_bi_class_time_zone = class_base_idx++;

  return true;
}/*}}}*/

// - TZONE print exception -
bool tzone_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_TIME_ZONE_PARSE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTime zone, parse error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class TIME_ZONE -
built_in_class_s time_zone_class =
{/*{{{*/
  "TimeZone",
  c_modifier_public | c_modifier_final,
  5, time_zone_methods,
  0, time_zone_variables,
  bic_time_zone_consts,
  bic_time_zone_init,
  bic_time_zone_clear,
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

built_in_method_s time_zone_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_time_zone_operator_binary_equal
  },
  {
    "TimeZone#1",
    c_modifier_public | c_modifier_final,
    bic_time_zone_method_TimeZone_1
  },
  {
    "to_local#1",
    c_modifier_public | c_modifier_final,
    bic_time_zone_method_to_local_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_time_zone_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_time_zone_method_print_0
  },
};/*}}}*/

built_in_variable_s time_zone_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_time_zone_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_time_zone_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (time_zone_s *)nullptr;
}/*}}}*/

void bic_time_zone_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  time_zone_s *tz_ptr = (time_zone_s *)location_ptr->v_data_ptr;

  if (tz_ptr != nullptr)
  {
    tz_ptr->clear();
    cfree(tz_ptr);
  }
}/*}}}*/

bool bic_time_zone_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_time_zone_method_TimeZone_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
tz_string:c_bi_class_string
>
method TimeZone
; @end

  string_s *tz_string = (string_s *)src_0_location->v_data_ptr;

  // - create time zone object -
  time_zone_s *tz_ptr = (time_zone_s *)cmalloc(sizeof(time_zone_s));
  tz_ptr->init();

  // - ERROR -
  if (tz_ptr->create(tz_string->data))
  {
    tz_ptr->clear();
    cfree(tz_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_TIME_ZONE_PARSE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  dst_location->v_data_ptr = (time_zone_s *)tz_ptr;

  return true;
}/*}}}*/

bool bic_time_zone_method_to_local_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
utc_time:retrieve_integer
>
method to_local
; @end

  time_zone_s *tz_ptr = (time_zone_s *)dst_location->v_data_ptr;

  long long int result = 0;
  tz_ptr->to_local(utc_time,&result);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_time_zone_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TimeZone"),"TimeZone");
  );

  return true;
}/*}}}*/

bool bic_time_zone_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("TimeZone");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

