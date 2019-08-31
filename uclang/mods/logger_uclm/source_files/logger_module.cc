
@begin
include "logger_module.h"
@end

// - LOGGER indexes of built in classes -
unsigned c_bi_class_logger = c_idx_not_exist;

// - LOGGER module -
EXPORT built_in_module_s module =
{/*{{{*/
  1,                      // Class count
  logger_classes,         // Classes
  0,                      // Error base index
  1,                      // Error count
  logger_error_strings,   // Error strings
  logger_initialize,      // Initialize function
  logger_print_exception, // Print exceptions function
};/*}}}*/

// - LOGGER classes -
built_in_class_s *logger_classes[] =
{/*{{{*/
  &logger_class,
};/*}}}*/

// - LOGGER error strings -
const char *logger_error_strings[] =
{/*{{{*/
  "error_LOGGER_DUMMY_ERROR",
};/*}}}*/

// - LOGGER initialize -
bool logger_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize logger class identifier -
  c_bi_class_logger = class_base_idx++;

  return true;
}/*}}}*/

// - LOGGER print exception -
bool logger_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_LOGGER_DUMMY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nLogger dummy error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class LOGGER -
built_in_class_s logger_class =
{/*{{{*/
  "Logger",
  c_modifier_public | c_modifier_final,
  6, logger_methods,
  0, logger_variables,
  bic_logger_consts,
  bic_logger_init,
  bic_logger_clear,
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

built_in_method_s logger_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_logger_operator_binary_equal
  },
  {
    "Logger#1",
    c_modifier_public | c_modifier_final,
    bic_logger_method_Logger_1
  },
  {
    "add_file#4",
    c_modifier_public | c_modifier_final,
    bic_logger_method_add_file_4
  },
  {
    "write#2",
    c_modifier_public | c_modifier_final,
    bic_logger_method_write_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_logger_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_logger_method_print_0
  },
};/*}}}*/

built_in_variable_s logger_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_logger_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_logger_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (logger_s *)nullptr;
}/*}}}*/

void bic_logger_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  logger_s *logger_ptr = (logger_s *)location_ptr->v_data_ptr;

  if (logger_ptr != nullptr)
  {
    logger_ptr->clear(it);
    cfree(logger_ptr);
  }
}/*}}}*/

bool bic_logger_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_logger_method_Logger_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
user:c_bi_class_string
>
method Logger
; @end

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create logger object -
  logger_s *logger_ptr = (logger_s *)cmalloc(sizeof(logger_s));
  logger_ptr->init();

  // - set logger user -
  logger_ptr->user = *string_ptr;

  // - set destination data pointer -
  dst_location->v_data_ptr = (logger_s *)logger_ptr;

  return true;
}/*}}}*/

bool bic_logger_method_add_file_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
level:retrieve_integer
path:c_bi_class_string
max_size:retrieve_integer
max_count:retrieve_integer
>
method add_file
; @end

  logger_s *logger_ptr = (logger_s *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_1_location->v_data_ptr;

  // - ERROR -
  if (level < 0 || max_size < 4096 || max_count < 1 ||
      max_size > UINT_MAX || max_count > UINT_MAX)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  // - ERROR -
  if (!logger_ptr->add_file(level,*string_ptr,max_size,max_count))
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_logger_method_write_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
level:retrieve_integer
message:c_bi_class_string
>
method write
; @end

  logger_s *logger_ptr = (logger_s *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_1_location->v_data_ptr;

  // - ERROR -
  if (level < 0)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  if (!logger_ptr->write(level,*string_ptr))
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_logger_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Logger"),"Logger")
  );

  return true;
}/*}}}*/

bool bic_logger_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Logger");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

