
@begin
include "epoll_module.h"
@end

// - EPOLL indexes of built in classes -
unsigned c_bi_class_epoll = c_idx_not_exist;

// - EPOLL module -
built_in_module_s module =
{/*{{{*/
  1,                     // Class count
  epoll_classes,         // Classes
  0,                     // Error base index
  1,                     // Error count
  epoll_error_strings,   // Error strings
  epoll_initialize,      // Initialize function
  epoll_print_exception, // Print exceptions function
};/*}}}*/

// - EPOLL classes -
built_in_class_s *epoll_classes[] =
{/*{{{*/
  &epoll_class,
};/*}}}*/

// - EPOLL error strings -
const char *epoll_error_strings[] =
{/*{{{*/
  "error_EPOLL_CREATE_ERROR",
};/*}}}*/

// - EPOLL initialize -
bool epoll_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize epoll class identifier -
  c_bi_class_epoll = class_base_idx++;

  return true;
}/*}}}*/

// - EPOLL print exception -
bool epoll_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_EPOLL_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nEpoll create error: ");
    errno = exception.params[0];
    perror("");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class EPOLL -
built_in_class_s epoll_class =
{/*{{{*/
  "Epoll",
  c_modifier_public | c_modifier_final,
  4, epoll_methods,
  1, epoll_variables,
  bic_epoll_consts,
  bic_epoll_init,
  bic_epoll_clear,
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

built_in_method_s epoll_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_epoll_operator_binary_equal
  },
  {
    "Epoll#1",
    c_modifier_public | c_modifier_final,
    bic_epoll_method_Epoll_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_epoll_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_epoll_method_print_0
  },
};/*}}}*/

built_in_variable_s epoll_variables[] =
{/*{{{*/

  // - epoll create flags -
  { "CLOEXEC",  c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_epoll_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert epoll create flags -
  {
    const_locations.push_blanks(1);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 1);

#define CREATE_EPOLL_CREATE_FLAG_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_EPOLL_CREATE_FLAG_BIC_STATIC(EPOLL_CLOEXEC);
  }

}/*}}}*/

void bic_epoll_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (epoll_s *)nullptr;
}/*}}}*/

void bic_epoll_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  epoll_s *ep_ptr = (epoll_s *)location_ptr->v_data_ptr;

  if (ep_ptr != nullptr)
  {
    ep_ptr->clear(it);
    cfree(ep_ptr);
  }
}/*}}}*/

bool bic_epoll_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_epoll_method_Epoll_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int flags;

  if (!it.retrieve_integer(src_0_location,flags))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Epoll#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  int fd = epoll_create1(flags);

  // - ERROR -
  if (fd == -1)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_EPOLL_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(errno);

    return false;
  }

  // - create epoll object -
  epoll_s *ep_ptr = (epoll_s *)cmalloc(sizeof(epoll_s));
  ep_ptr->init();

  ep_ptr->fd = fd;

  dst_location->v_data_ptr = (epoll_s *)ep_ptr;

  return true;
}/*}}}*/

bool bic_epoll_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Epoll"),"Epoll")
  );

  return true;
}/*}}}*/

bool bic_epoll_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Epoll");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

