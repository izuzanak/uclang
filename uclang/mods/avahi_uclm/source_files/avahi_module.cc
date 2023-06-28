
@begin
include "avahi_module.h"
@end

// - AVAHI indexes of built in classes -
unsigned c_bi_class_avahi_poll = c_idx_not_exist;
unsigned c_bi_class_avahi_client = c_idx_not_exist;

// - AVAHI module -
EXPORT built_in_module_s module =
{/*{{{*/
  2,                     // Class count
  avahi_classes,         // Classes

  0,                     // Error base index
  1,                     // Error count
  avahi_error_strings,   // Error strings

  avahi_initialize,      // Initialize function
  avahi_print_exception, // Print exceptions function
};/*}}}*/

// - AVAHI classes -
built_in_class_s *avahi_classes[] =
{/*{{{*/
  &avahi_poll_class,
  &avahi_client_class,
};/*}}}*/

// - AVAHI error strings -
const char *avahi_error_strings[] =
{/*{{{*/
  "error_AVAHI_DUMMY_ERROR",
};/*}}}*/

// - AVAHI initialize -
bool avahi_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize avahi_poll class identifier -
  c_bi_class_avahi_poll = class_base_idx++;

  // - initialize avahi_client class identifier -
  c_bi_class_avahi_client = class_base_idx++;

  return true;
}/*}}}*/

// - AVAHI print exception -
bool avahi_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_AVAHI_DUMMY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nAvahi dummy error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class AVAHI_POLL -
built_in_class_s avahi_poll_class =
{/*{{{*/
  "AvahiPoll",
  c_modifier_public | c_modifier_final,
  7, avahi_poll_methods,
  0, avahi_poll_variables,
  bic_avahi_poll_consts,
  bic_avahi_poll_init,
  bic_avahi_poll_clear,
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

built_in_method_s avahi_poll_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_avahi_poll_operator_binary_equal
  },
  {
    "AvahiPoll#0",
    c_modifier_public | c_modifier_final,
    bic_avahi_poll_method_AvahiPoll_0
  },
  {
    "get_fds#0",
    c_modifier_public | c_modifier_final,
    bic_avahi_poll_method_get_fds_0
  },
  {
    "timeout#0",
    c_modifier_public | c_modifier_final,
    bic_avahi_poll_method_timeout_0
  },
  {
    "process#1",
    c_modifier_public | c_modifier_final,
    bic_avahi_poll_method_process_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_avahi_poll_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_avahi_poll_method_print_0
  },
};/*}}}*/

built_in_variable_s avahi_poll_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_avahi_poll_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_avahi_poll_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (avahi_poll_s *)nullptr;
}/*}}}*/

void bic_avahi_poll_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  avahi_poll_s *ap_ptr = (avahi_poll_s *)location_ptr->v_data_ptr;

  if (ap_ptr != nullptr)
  {
    ap_ptr->clear(it);
    cfree(ap_ptr);
  }
}/*}}}*/

bool bic_avahi_poll_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_avahi_poll_method_AvahiPoll_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - create avahi_poll object -
  avahi_poll_s *ap_ptr = (avahi_poll_s *)cmalloc(sizeof(avahi_poll_s));
  ap_ptr->init();

  // - set avahi_poll destination location -
  dst_location->v_data_ptr = (avahi_poll_s *)ap_ptr;

  return true;
}/*}}}*/

bool bic_avahi_poll_method_get_fds_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/

  // FIXME TODO continue ...
  BIC_TODO_ERROR(__FILE__,__LINE__);
  return false;
}/*}}}*/

bool bic_avahi_poll_method_timeout_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/

  // FIXME TODO continue ...
  BIC_TODO_ERROR(__FILE__,__LINE__);
  return false;
}/*}}}*/

bool bic_avahi_poll_method_process_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/

  // FIXME TODO continue ...
  BIC_TODO_ERROR(__FILE__,__LINE__);
  return false;
}/*}}}*/

bool bic_avahi_poll_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("AvahiPoll"),"AvahiPoll");
  );

  return true;
}/*}}}*/

bool bic_avahi_poll_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("AvahiPoll");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class AVAHI_CLIENT -
built_in_class_s avahi_client_class =
{/*{{{*/
  "AvahiClient",
  c_modifier_public | c_modifier_final,
  4, avahi_client_methods,
  0, avahi_client_variables,
  bic_avahi_client_consts,
  bic_avahi_client_init,
  bic_avahi_client_clear,
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

built_in_method_s avahi_client_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_avahi_client_operator_binary_equal
  },
  {
    "AvahiClient#4",
    c_modifier_public | c_modifier_final,
    bic_avahi_client_method_AvahiClient_4
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_avahi_client_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_avahi_client_method_print_0
  },
};/*}}}*/

built_in_variable_s avahi_client_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_avahi_client_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_avahi_client_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (avahi_client_s *)nullptr;
}/*}}}*/

void bic_avahi_client_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  avahi_client_s *ac_ptr = (avahi_client_s *)location_ptr->v_data_ptr;

  if (ac_ptr != nullptr)
  {
    ac_ptr->clear(it);
    cfree(ac_ptr);
  }
}/*}}}*/

bool bic_avahi_client_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_avahi_client_method_AvahiClient_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
poll:c_bi_class_avahi_poll
flags:retrieve_integer
delegate:c_bi_class_delegate
user_data:ignore
>
method AvahiClient
; @end

  avahi_poll_s *ap_ptr = (avahi_poll_s *)src_0_location->v_data_ptr;

  // - retrieve delegate pointer -
  delegate_s *delegate_ptr = (delegate_s *)src_2_location->v_data_ptr;

  // - ERROR -
  if (delegate_ptr->param_cnt != 1)
  {
    // FIXME TODO throw proper execption ...
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  int error;
  AvahiClient *avahi_client = avahi_client_new(&ap_ptr->avahi_poll,
      (AvahiClientFlags)flags,avahi_client_s::callback,dst_location,&error);

  // - ERROR -
  if (avahi_client == nullptr)
  {
    // FIXME TODO throw proper execption ...
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  // - create avahi_client object -
  avahi_client_s *ac_ptr = (avahi_client_s *)cmalloc(sizeof(avahi_client_s));
  ac_ptr->init();

  ac_ptr->avahi_client = avahi_client;

  // - set user data pointer -
  src_3_location->v_reference_cnt.atomic_inc();
  ac_ptr->user_data_ptr = src_3_location;

  // - set avahi_client destination location -
  dst_location->v_data_ptr = (avahi_client_s *)ac_ptr;

  return true;
}/*}}}*/

bool bic_avahi_client_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("AvahiClient"),"AvahiClient");
  );

  return true;
}/*}}}*/

bool bic_avahi_client_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("AvahiClient");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

