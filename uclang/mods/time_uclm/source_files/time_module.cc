
@begin
include "time_module.h"
@end

// - TIME indexes of built in classes -
unsigned c_bi_class_time = c_idx_not_exist;

// - TIME module -
built_in_module_s module =
{/*{{{*/
  1,                     // Class count
  time_classes,          // Classes

  0,                     // Error base index
  1,                     // Error count
  time_error_strings,    // Error strings

  time_initialize,       // Initialize function
  time_print_exception,  // Print exceptions function
};/*}}}*/

// - TIME classes -
built_in_class_s *time_classes[] =
{/*{{{*/
  &time_class,
};/*}}}*/

// - TIME error strings -
const char *time_error_strings[] =
{/*{{{*/
  "error_TIME_WRONG_INIT_STRING",
};/*}}}*/

// - TIME initialize -
bool time_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize time class identifier -
  c_bi_class_time = class_base_idx++;

  return true;
}/*}}}*/

// - TIME print exception -
bool time_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_TIME_WRONG_INIT_STRING:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong date/time string \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class TIME -
built_in_class_s time_class =
{/*{{{*/
  "Time",
  c_modifier_public | c_modifier_final,
  15, time_methods,
  0, time_variables,
  bic_time_consts,
  bic_time_init,
  bic_time_clear,
  bic_time_compare,
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

built_in_method_s time_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_time_operator_binary_equal
  },
  {
    "Time#0",
    c_modifier_public | c_modifier_final,
    bic_time_method_Time_0
  },
  {
    "Time#1",
    c_modifier_public | c_modifier_final,
    bic_time_method_Time_1
  },
  {
    "value#0",
    c_modifier_public | c_modifier_final,
    bic_time_method_value_0
  },
  {
    "nano_sec#0",
    c_modifier_public | c_modifier_final,
    bic_time_method_nano_sec_0
  },
  {
    "micro_sec#0",
    c_modifier_public | c_modifier_final,
    bic_time_method_micro_sec_0
  },
  {
    "milli_sec#0",
    c_modifier_public | c_modifier_final,
    bic_time_method_milli_sec_0
  },
  {
    "seconds#0",
    c_modifier_public | c_modifier_final,
    bic_time_method_seconds_0
  },
  {
    "minutes#0",
    c_modifier_public | c_modifier_final,
    bic_time_method_minutes_0
  },
  {
    "hours#0",
    c_modifier_public | c_modifier_final,
    bic_time_method_hours_0
  },
  {
    "days#0",
    c_modifier_public | c_modifier_final,
    bic_time_method_days_0
  },
  {
    "datetime#0",
    c_modifier_public | c_modifier_final,
    bic_time_method_datetime_0
  },
  {
    "compare#1",
    c_modifier_public | c_modifier_final,
    bic_time_method_compare_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_time_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_time_method_print_0
  },
};/*}}}*/

built_in_variable_s time_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_time_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_time_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (long long unsigned)0;
}/*}}}*/

void bic_time_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

int bic_time_compare(location_s *first_loc,location_s *second_loc)
{/*{{{*/
  long long unsigned first = (long long unsigned)first_loc->v_data_ptr;
  long long unsigned second = (long long unsigned)second_loc->v_data_ptr;

  return first < second ? -1 : (first > second ? 1 : 0);
}/*}}}*/

bool bic_time_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_time_method_Time_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
  timeval tv;
  gettimeofday(&tv,nullptr);

  dst_location->v_data_ptr = (long long unsigned)(tv.tv_sec*1000000000ULL + tv.tv_usec*1000ULL);
#elif SYSTEM_TYPE == SYSTEM_TYPE_WINDOWS
  FILETIME ft;
  GetSystemTimeAsFileTime(&ft);

  ULARGE_INTEGER ularge_int = { ft.dwLowDateTime,ft.dwHighDateTime };
  dst_location->v_data_ptr = (long long unsigned)((ularge_int.QuadPart - 116444736000000000ULL)*100ULL);
#else
  exception_s *new_exception = exception_s::throw_exception(it,c_error_BUILT_IN_NOT_IMPLEMENTED_METHOD,operands[c_source_pos_idx],(location_s *)it.blank_location);
  BIC_EXCEPTION_PUSH_METHOD_RI("Time#0");

  return false;
#endif

  return true;
}/*}}}*/

bool bic_time_method_Time_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long unsigned time;

  switch (src_0_location->v_type)
  {
    case c_bi_class_integer:
    {
      time = (long long int)src_0_location->v_data_ptr;
    }
    break;

    case c_bi_class_float:
      time = (long long unsigned)(double)src_0_location->v_data_ptr;
      break;

    case c_bi_class_string:
    {
      string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

      // - ERROR -
      if (string_ptr->size != 15)
      {
        exception_s::throw_exception(it,module.error_base + c_error_TIME_WRONG_INIT_STRING,operands[c_source_pos_idx],src_0_location);
        return false;
      }

      datetime_s dt;

      char str[15];
      memcpy(str,string_ptr->data,15);

#define BIC_TIME_RETRIEVE_COMP(TARGET,START,END) \
{/*{{{*/\
  char tmp_char = str[END];\
  str[END] = '\0';\
\
  char *end_ptr;\
  TARGET = strtol(str + START,&end_ptr,10);\
\
  /* - ERROR - */\
  if (end_ptr != str + END)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_TIME_WRONG_INIT_STRING,operands[c_source_pos_idx],src_0_location);\
    return false;\
  }\
\
  str[END] = tmp_char;\
}/*}}}*/

      dt.nsec = 0;
      dt.usec = 0;
      dt.msec = 0;

      BIC_TIME_RETRIEVE_COMP(dt.sec  ,12,14);
      BIC_TIME_RETRIEVE_COMP(dt.min  ,10,12);
      BIC_TIME_RETRIEVE_COMP(dt.hour ,8 ,10);
      BIC_TIME_RETRIEVE_COMP(dt.day  ,6 ,8);
      BIC_TIME_RETRIEVE_COMP(dt.month,4 ,6);
      BIC_TIME_RETRIEVE_COMP(dt.year ,0 ,4);

      // - ERROR -
      if (dt.year < 1970 || dt.month < 1 || dt.month > 12 || dt.day < 1 ||
          dt.day > c_month_days_arr[datetime_s::is_leap_year(dt.year)][dt.month - 1] ||
          dt.hour >= 24 || dt.min >= 60 || dt.sec >= 60)
      {
        exception_s::throw_exception(it,module.error_base + c_error_TIME_WRONG_INIT_STRING,operands[c_source_pos_idx],src_0_location);
        return false;
      }

      // - convert datetime to time value -
      dt.to_nanosec(time);
    }
    break;

    default:
    {
      // - process time value -
      if (src_0_location->v_type == c_bi_class_time)
      {
        time = (long long unsigned)src_0_location->v_data_ptr;
      }

      // - ERROR -
      else
      {
        exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
        BIC_EXCEPTION_PUSH_METHOD_RI("Time#1");
        new_exception->params.push(1);
        new_exception->params.push(src_0_location->v_type);

        return false;
      }
    }
  }

  dst_location->v_data_ptr = (long long unsigned)time;

  return true;
}/*}}}*/

bool bic_time_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = (long long unsigned)dst_location->v_data_ptr;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_time_method_nano_sec_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = (long long unsigned)dst_location->v_data_ptr;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_time_method_micro_sec_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((long long unsigned)dst_location->v_data_ptr)/1000ULL;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_time_method_milli_sec_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((long long unsigned)dst_location->v_data_ptr)/1000000ULL;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_time_method_seconds_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((long long unsigned)dst_location->v_data_ptr)/1000000000ULL;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_time_method_minutes_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((long long unsigned)dst_location->v_data_ptr)/60000000000ULL;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_time_method_hours_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((long long unsigned)dst_location->v_data_ptr)/3600000000000ULL;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_time_method_days_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((long long unsigned)dst_location->v_data_ptr)/86400000000000ULL;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_time_method_datetime_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long unsigned nanosec = (long long unsigned)dst_location->v_data_ptr;

  // - convert time to date time structure -
  datetime_s datetime;
  datetime.from_nanosec(nanosec);

  // - create new array pointer -
  pointer_array_s *array_ptr = it.get_new_array_ptr();
  array_ptr->copy_resize(c_datetime_value_cnt);
  array_ptr->used = array_ptr->size;

  pointer *l_ptr = array_ptr->data;
  pointer *l_ptr_end = array_ptr->data + array_ptr->used;
  do {
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,0)

    *l_ptr = (pointer)new_location;

  } while(++l_ptr < l_ptr_end);

  // - set system time values -
  ((location_s *)array_ptr->data[0])->v_data_ptr = (long long int)datetime.year;
  ((location_s *)array_ptr->data[1])->v_data_ptr = (long long int)datetime.month;
  ((location_s *)array_ptr->data[2])->v_data_ptr = (long long int)datetime.day;
  ((location_s *)array_ptr->data[3])->v_data_ptr = (long long int)datetime.wday;
  ((location_s *)array_ptr->data[4])->v_data_ptr = (long long int)datetime.hour;
  ((location_s *)array_ptr->data[5])->v_data_ptr = (long long int)datetime.min;
  ((location_s *)array_ptr->data[6])->v_data_ptr = (long long int)datetime.sec;
  ((location_s *)array_ptr->data[7])->v_data_ptr = (long long int)datetime.msec;
  ((location_s *)array_ptr->data[8])->v_data_ptr = (long long int)datetime.usec;
  ((location_s *)array_ptr->data[9])->v_data_ptr = (long long int)datetime.nsec;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_time_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  if (src_0_location->v_type == c_bi_class_time)
  {
    long long unsigned first = (long long unsigned)dst_location->v_data_ptr;
    long long unsigned second = (long long unsigned)src_0_location->v_data_ptr;

    result = first < second ? -1 : (first > second ? 1 : 0);
  }
  else
  {
    result = c_bi_class_time < src_0_location->v_type ? -1 : 1;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_time_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING(

    long long unsigned nanosec = (long long unsigned)dst_location->v_data_ptr;

    // - convert time to datetime structure -
    datetime_s datetime;
    datetime.from_nanosec(nanosec);

    string_ptr->setf("%4.4hu/%2.2hu/%2.2hu %2.2hu:%2.2hu:%2.2hu"
      ,datetime.year,datetime.month,datetime.day,datetime.hour,datetime.min,datetime.sec);
  );

  return true;
}/*}}}*/

bool bic_time_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long unsigned nanosec = (long long unsigned)dst_location->v_data_ptr;

  // - convert time to datetime structure -
  datetime_s datetime;
  datetime.from_nanosec(nanosec);

#if SYSTEM_TYPE == SYSTEM_TYPE_UNIX
  printf("%4.4hu/%2.2hhu/%2.2hhu %2.2hhu:%2.2hhu:%2.2hhu"
      ,datetime.year,datetime.month,datetime.day,datetime.hour,datetime.min,datetime.sec);
#else
  printf("%4.4hu/%2.2hu/%2.2hu %2.2hu:%2.2hu:%2.2hu"
      ,datetime.year,(usi)datetime.month,(usi)datetime.day,(usi)datetime.hour,(usi)datetime.min,(usi)datetime.sec);
#endif

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

