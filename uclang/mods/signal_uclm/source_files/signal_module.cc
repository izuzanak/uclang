
@begin
include "signal_module.h"
@end

// - SIGNAL indexes of built in classes -
unsigned c_bi_class_data_signal = c_idx_not_exist;

// - SINGAL indexes of remote classes -
unsigned c_rm_class_bin_array = c_idx_not_exist;

// - SIGNAL module -
EXPORT built_in_module_s module =
{/*{{{*/
  1,                      // Class count
  signal_classes,         // Classes

  0,                      // Error base index
  3,                      // Error count
  signal_error_strings,   // Error strings

  signal_initialize,      // Initialize function
  signal_print_exception, // Print exceptions function
};/*}}}*/

// - SIGNAL classes -
built_in_class_s *signal_classes[] =
{/*{{{*/
  &data_signal_class,
};/*}}}*/

// - SIGNAL error strings -
const char *signal_error_strings[] =
{/*{{{*/
  "error_SIGNAL_SEARCH_INVALID_DATA_ARRAYS",
  "error_SIGNAL_SEARCH_INVALID_DATA_ARRAYS_DIMENSION",
  "error_SIGNAL_SEARCH_INVALID_PARAMETERS",
};/*}}}*/

// - SIGNAL initialize -
bool signal_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize data_signal class identifier -
  c_bi_class_data_signal = class_base_idx++;

  // - retrieve remote bin_array class index -
  c_rm_class_bin_array = sp.resolve_class_idx_by_name("BinArray",c_idx_not_exist);

  // - ERROR -
  if (c_rm_class_bin_array == c_idx_not_exist)
  {
    sp.error_code.push(ei_module_cannot_find_remote_class);
    sp.error_code.push(sp.module_names_positions[sp.module_idx].ui_first);
    sp.error_code.push(sp.module_idx);

    return false;
  }

  return true;
}/*}}}*/

// - SIGNAL print exception -
bool signal_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_SIGNAL_SEARCH_INVALID_DATA_ARRAYS:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSignal, invalid search data arrays\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SIGNAL_SEARCH_INVALID_DATA_ARRAYS_DIMENSION:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSignal, invalid dimension of search data arrays\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SIGNAL_SEARCH_INVALID_PARAMETERS:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSignal, invalid search parameters\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class DATA_SIGNAL -
built_in_class_s data_signal_class =
{/*{{{*/
  "DataSignal",
  c_modifier_public | c_modifier_final,
  3, data_signal_methods,
  0, data_signal_variables,
  bic_data_signal_consts,
  bic_data_signal_init,
  bic_data_signal_clear,
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

built_in_method_s data_signal_methods[] =
{/*{{{*/
  {
    "search#6",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_data_signal_method_search_6
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_data_signal_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_data_signal_method_print_0
  },
};/*}}}*/

built_in_variable_s data_signal_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_data_signal_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_data_signal_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_data_signal_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_data_signal_method_search_6(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:c_bi_class_array
window:c_bi_class_array
search_step:retrieve_integer
search_dist:retrieve_integer
dist_max:retrieve_float
dist_cnt:retrieve_integer
>
class c_bi_class_data_signal
method search
static_method
; @end

  pointer_array_s *data_ptr = (pointer_array_s *)src_0_location->v_data_ptr;
  pointer_array_s *window_ptr = (pointer_array_s *)src_1_location->v_data_ptr;

  // - ERROR -
  if (data_ptr->used != window_ptr->used || data_ptr->used == 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SIGNAL_SEARCH_INVALID_DATA_ARRAYS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  bd_array_s *data_arrays[data_ptr->used];
  bd_array_s *window_arrays[window_ptr->used];

#define DATA_SIGNAL_METHOD_SEARCH_RETRIEVE_DATA(NAME) \
{/*{{{*/\
  pointer *s_ptr = NAME ## _ptr->data;\
  pointer *s_ptr_end = s_ptr + NAME ## _ptr->used;\
  bd_array_s **t_ptr = NAME ## _arrays;\
  do\
  {\
    location_s *item_location = it.get_location_value(*s_ptr);\
    bin_array_s *ba_ptr = (bin_array_s *)item_location->v_data_ptr;\
\
    /* - ERROR - */\
    if (item_location->v_type != c_rm_class_bin_array ||\
        ba_ptr->type != c_bin_array_type_double)\
    {\
      exception_s::throw_exception(it,module.error_base + c_error_SIGNAL_SEARCH_INVALID_DATA_ARRAYS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      return false;\
    }\
\
    /* - retrieve data pointer - */\
    *t_ptr = (bd_array_s *)ba_ptr->cont;\
\
    /* - ERROR - */\
    if ((*t_ptr)->used != NAME ## _arrays[0]->used)\
    {\
      exception_s::throw_exception(it,module.error_base + c_error_SIGNAL_SEARCH_INVALID_DATA_ARRAYS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      return false;\
    }\
\
  } while(++t_ptr,++s_ptr < s_ptr_end);\
}/*}}}*/

  // - retrieve data pointers -
  DATA_SIGNAL_METHOD_SEARCH_RETRIEVE_DATA(data);

  // - retrieve window pointers -
  DATA_SIGNAL_METHOD_SEARCH_RETRIEVE_DATA(window);

  // - ERROR -
  if (data_ptr->used != 2)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SIGNAL_SEARCH_INVALID_DATA_ARRAYS_DIMENSION,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (search_step < 1 || search_step > window_arrays[0]->used ||
      search_dist < 0 || search_dist > window_arrays[0]->used ||
      dist_max < 0.0 ||
      dist_cnt < 0 || dist_cnt > window_arrays[0]->used)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SIGNAL_SEARCH_INVALID_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  search_results_s results;
  results.init();

  data_signal_s::search_2d(data_arrays,window_arrays,
      search_step,search_dist,dist_max,dist_cnt,results);

  pointer_array_s *array_ptr = it.get_new_array_ptr();

  if (results.used != 0)
  {
    array_ptr->copy_resize(results.used << 1);

    search_result_s *r_ptr = results.data;
    search_result_s *r_ptr_end = r_ptr + results.used;
    do {
      long long int start = r_ptr->start;
      BIC_CREATE_NEW_LOCATION(start_location,c_bi_class_integer,start);
      array_ptr->push(start_location);

      long long int end = r_ptr->end;
      BIC_CREATE_NEW_LOCATION(end_location,c_bi_class_integer,end);
      array_ptr->push(end_location);
    } while(++r_ptr < r_ptr_end);
  }

  results.clear();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_data_signal_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("DataSignal"),"DataSignal");
  );

  return true;
}/*}}}*/

bool bic_data_signal_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("DataSignal");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

