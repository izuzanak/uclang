
@begin
include "avahi_module.h"
@end

// - AVAHI indexes of built in classes -
unsigned c_bi_class_avahi_poll = c_idx_not_exist;
unsigned c_bi_class_avahi_client = c_idx_not_exist;
unsigned c_bi_class_avahi_service_browser = c_idx_not_exist;

// - AVAHI module -
EXPORT built_in_module_s module =
{/*{{{*/
  3,                     // Class count
  avahi_classes,         // Classes

  0,                     // Error base index
  8,                     // Error count
  avahi_error_strings,   // Error strings

  avahi_initialize,      // Initialize function
  avahi_print_exception, // Print exceptions function
};/*}}}*/

// - AVAHI classes -
built_in_class_s *avahi_classes[] =
{/*{{{*/
  &avahi_poll_class,
  &avahi_client_class,
  &avahi_service_browser_class,
};/*}}}*/

// - AVAHI error strings -
const char *avahi_error_strings[] =
{/*{{{*/
  "error_AVAHI_CLIENT_WRONG_CALLBACK_DELEGATE",
  "error_AVAHI_CLIENT_CREATE_ERROR",
  "error_AVAHI_CLIENT_ACCESS_OUTSIDE_OF_CALLBACK",
  "error_AVAHI_SERVICE_BROWSER_WRONG_CALLBACK_DELEGATE",
  "error_AVAHI_SERVICE_BROWSER_CREATE_ERROR",
  "error_AVAHI_SERVICE_BROWSER_ACCESS_OUTSIDE_OF_BROWSE_CALLBACK",
  "error_AVAHI_SERVICE_BROWSER_ACCESS_OUTSIDE_OF_RESOLVE_CALLBACK",
  "error_AVAHI_SERVICE_BROWSER_CREATE_RESOLVER_ERROR",
};/*}}}*/

// - AVAHI initialize -
bool avahi_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize avahi_poll class identifier -
  c_bi_class_avahi_poll = class_base_idx++;

  // - initialize avahi_client class identifier -
  c_bi_class_avahi_client = class_base_idx++;

  // - initialize avahi_service_browser class identifier -
  c_bi_class_avahi_service_browser = class_base_idx++;

  return true;
}/*}}}*/

// - AVAHI print exception -
bool avahi_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_AVAHI_CLIENT_WRONG_CALLBACK_DELEGATE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong type of delegate for avahi client\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_AVAHI_CLIENT_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot create avahi client\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_AVAHI_CLIENT_ACCESS_OUTSIDE_OF_CALLBACK:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nAccess to member outside of avahi client callback\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_AVAHI_SERVICE_BROWSER_WRONG_CALLBACK_DELEGATE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong type of delegate for avahi service browser\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_AVAHI_SERVICE_BROWSER_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot create avahi service browser\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_AVAHI_SERVICE_BROWSER_ACCESS_OUTSIDE_OF_BROWSE_CALLBACK:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nAccess to member outside of avahi service browse callback\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_AVAHI_SERVICE_BROWSER_ACCESS_OUTSIDE_OF_RESOLVE_CALLBACK:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nAccess to member outside of avahi service resolve callback\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_AVAHI_SERVICE_BROWSER_CREATE_RESOLVER_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot create avahi service resolver\n");
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
    "process#2",
    c_modifier_public | c_modifier_final,
    bic_avahi_poll_method_process_2
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

  ap_ptr->avahi_poll.userdata = ap_ptr;

  // - set avahi_poll destination location -
  dst_location->v_data_ptr = (avahi_poll_s *)ap_ptr;

  return true;
}/*}}}*/

bool bic_avahi_poll_method_get_fds_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve avahi_poll pointer -
  avahi_poll_s *ap_ptr = (avahi_poll_s *)dst_location->v_data_ptr;
  watch_array_s &watch_array = ap_ptr->watch_array;

  // - create result array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  if (watch_array.used != 0)
  {
    watch_pointer *wp_ptr = watch_array.data;
    watch_pointer *wp_ptr_end = wp_ptr + watch_array.used;
    do
    {
      if (*wp_ptr != nullptr)
      {
        watch_s *watch = *wp_ptr;

        long long int fd_value = watch->fd;
        long long int flags = watch->event;

        // - create fd value -
        {
          BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,fd_value);
          array_ptr->push(new_location);
        }

        // - create flags -
        {
          BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,flags);
          array_ptr->push(new_location);
        }
      }
    } while(++wp_ptr < wp_ptr_end);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_avahi_poll_method_timeout_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve avahi_poll pointer -
  avahi_poll_s *ap_ptr = (avahi_poll_s *)dst_location->v_data_ptr;
  timeout_tree_s &timeout_tree = ap_ptr->timeout_tree;

  long long int result;

  // - some timeout exists -
  if (timeout_tree.root_idx != c_idx_not_exist)
  {
    timeout_s *timeout = timeout_tree[timeout_tree.get_min_value_idx(timeout_tree.root_idx)];

    if (timeout->target_time == LLONG_MAX)
    {
      result = LLONG_MAX;
    }
    else
    {
      // - ERROR -
      struct timespec ts;
      if (clock_gettime(CLOCK_MONOTONIC,&ts) != 0)
      {
        BIC_TODO_ERROR(__FILE__,__LINE__);
        return false;
      }

      lli time_now = (ts.tv_sec*1000000000ULL + ts.tv_nsec);
      result = timeout->target_time > time_now ? (timeout->target_time - time_now)/1000000ULL : 0;
    }
  }
  else
  {
    result = LLONG_MAX;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_avahi_poll_method_process_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
fd:retrieve_integer
events:retrieve_integer
>
method process
; @end

  // - retrieve avahi_poll pointer -
  avahi_poll_s *ap_ptr = (avahi_poll_s *)dst_location->v_data_ptr;
  watch_array_s &watch_array = ap_ptr->watch_array;

  ap_ptr->it_ptr = &it;
  ap_ptr->source_pos = operands[c_source_pos_idx];
  ap_ptr->ret_code = c_run_return_code_OK;

  if (fd >= 0 && fd < watch_array.used && watch_array[fd] != nullptr)
  {
    watch_s *watch = watch_array[fd];
    watch->revent = (AvahiWatchEvent)events;

    // - call avahi watch callback -
    watch->callback((AvahiWatch *)watch,fd,watch->revent,watch->userdata);

    // - if exception occurred -
    if (ap_ptr->ret_code == c_run_return_code_EXCEPTION)
    {
      return false;
    }
  }
  else
  {
    timeout_tree_s &timeout_tree = ap_ptr->timeout_tree;

    // - some timeout exists -
    if (timeout_tree.root_idx != c_idx_not_exist)
    {
      timeout_s *timeout = timeout_tree[timeout_tree.get_min_value_idx(timeout_tree.root_idx)];

      // - ERROR -
      struct timespec ts;
      if (clock_gettime(CLOCK_MONOTONIC,&ts) != 0)
      {
        BIC_TODO_ERROR(__FILE__,__LINE__);
        return false;
      }

      lli time_now = (ts.tv_sec*1000000000ULL + ts.tv_nsec);

      // - timeout expired -
      if (timeout->target_time <= time_now)
      {
        timeout_tree.remove(timeout->index);

        timeout->target_time = LLONG_MAX;
        timeout->index = timeout_tree.insert(timeout);

        // - call avahi timeout callback -
        timeout->callback((AvahiTimeout *)timeout,timeout->userdata);

        // - if exception occurred -
        if (ap_ptr->ret_code == c_run_return_code_EXCEPTION)
        {
          return false;
        }
      }
    }
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
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
  7, avahi_client_methods,
  5, avahi_client_variables,
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
    "state#0",
    c_modifier_public | c_modifier_final,
    bic_avahi_client_method_state_0
  },
  {
    "user_data#0",
    c_modifier_public | c_modifier_final,
    bic_avahi_client_method_user_data_0
  },
  {
    "service_browser#6",
    c_modifier_public | c_modifier_final,
    bic_avahi_client_method_service_browser_6
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

  // - avahi client state constants -
  { "STATE_REGISTERING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "STATE_RUNNING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "STATE_COLLISION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "STATE_FAILURE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "STATE_CONNECTING", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_avahi_client_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert avahi client state constants -
  {
    const_locations.push_blanks(5);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 5);

#define CREATE_AVAHI_CLIENT_STATE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_AVAHI_CLIENT_STATE_BIC_STATIC(AVAHI_CLIENT_S_REGISTERING);
    CREATE_AVAHI_CLIENT_STATE_BIC_STATIC(AVAHI_CLIENT_S_RUNNING);
    CREATE_AVAHI_CLIENT_STATE_BIC_STATIC(AVAHI_CLIENT_S_COLLISION);
    CREATE_AVAHI_CLIENT_STATE_BIC_STATIC(AVAHI_CLIENT_FAILURE);
    CREATE_AVAHI_CLIENT_STATE_BIC_STATIC(AVAHI_CLIENT_CONNECTING);
  }

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
    exception_s::throw_exception(it,module.error_base + c_error_AVAHI_CLIENT_WRONG_CALLBACK_DELEGATE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create avahi_client object -
  avahi_client_s *ac_ptr = (avahi_client_s *)cmalloc(sizeof(avahi_client_s));
  ac_ptr->init();

  // - set avahi_poll location -
  src_0_location->v_reference_cnt.atomic_inc();
  ac_ptr->avahi_poll_loc = src_0_location;

  // - set callback delegate -
  src_2_location->v_reference_cnt.atomic_inc();
  ac_ptr->callback_dlg = src_2_location;

  // - set user_data location -
  src_3_location->v_reference_cnt.atomic_inc();
  ac_ptr->user_data_loc = src_3_location;

  // - set avahi_client data pointer -
  dst_location->v_data_ptr = (avahi_client_s *)ac_ptr;

  ap_ptr->it_ptr = &it;
  ap_ptr->source_pos = operands[c_source_pos_idx];
  ap_ptr->ret_code = c_run_return_code_OK;

  int error;
  ac_ptr->avahi_client = avahi_client_new(&ap_ptr->avahi_poll,
      (AvahiClientFlags)flags,avahi_client_s::callback,dst_location,&error);

  // - if exception occurred -
  if (ap_ptr->ret_code == c_run_return_code_EXCEPTION)
  {
    return false;
  }

  // - ERROR -
  if (ac_ptr->avahi_client == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_AVAHI_CLIENT_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  return true;
}/*}}}*/

bool bic_avahi_client_method_state_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  avahi_client_s *ac_ptr = (avahi_client_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (ac_ptr->state == (AvahiClientState)-1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_AVAHI_CLIENT_ACCESS_OUTSIDE_OF_CALLBACK,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  long long int result = ac_ptr->state;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_avahi_client_method_user_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  avahi_client_s *ac_ptr = (avahi_client_s *)dst_location->v_data_ptr;

  location_s *new_ref_location = it.get_new_reference(&ac_ptr->user_data_loc);

  BIC_SET_RESULT(new_ref_location);

  return true;
}/*}}}*/

bool bic_avahi_client_method_service_browser_6(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
type:c_bi_class_string
domain:c_bi_class_string
flags:retrieve_integer
browse_callback:c_bi_class_delegate
resolve_callback:c_bi_class_delegate
user_data:ignore
>
method service_browser
; @end

  avahi_client_s *ac_ptr = (avahi_client_s *)dst_location->v_data_ptr;
  avahi_poll_s *ap_ptr = (avahi_poll_s *)ac_ptr->avahi_poll_loc->v_data_ptr;

  // - retrieve browse delegate pointer -
  delegate_s *browse_delegate_ptr = (delegate_s *)src_3_location->v_data_ptr;

  // - ERROR -
  if (browse_delegate_ptr->param_cnt != 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_AVAHI_SERVICE_BROWSER_WRONG_CALLBACK_DELEGATE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - retrieve resolve delegate pointer -
  delegate_s *resolve_delegate_ptr = (delegate_s *)src_4_location->v_data_ptr;

  // - ERROR -
  if (resolve_delegate_ptr->param_cnt != 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_AVAHI_SERVICE_BROWSER_WRONG_CALLBACK_DELEGATE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create avahi_service_browser object -
  avahi_service_browser_s *asb_ptr = (avahi_service_browser_s *)cmalloc(sizeof(avahi_service_browser_s));
  asb_ptr->init();

  // - set avahi_client location -
  dst_location->v_reference_cnt.atomic_inc();
  asb_ptr->avahi_client_loc = dst_location;

  // - set browse callback delegate -
  src_3_location->v_reference_cnt.atomic_inc();
  asb_ptr->browse_cb_dlg = src_3_location;

  // - set resolve callback delegate -
  src_4_location->v_reference_cnt.atomic_inc();
  asb_ptr->resolve_cb_dlg = src_4_location;

  // - set user_data location -
  src_5_location->v_reference_cnt.atomic_inc();
  asb_ptr->user_data_loc = src_5_location;

  // - set avahi_service_browser result -
  BIC_CREATE_NEW_LOCATION(service_browser_location,c_bi_class_avahi_service_browser,asb_ptr);
  BIC_SET_RESULT(service_browser_location);

  ap_ptr->it_ptr = &it;
  ap_ptr->source_pos = operands[c_source_pos_idx];
  ap_ptr->ret_code = c_run_return_code_OK;

  string_s *type_str = (string_s *)src_0_location->v_data_ptr;
  string_s *domain_str = (string_s *)src_1_location->v_data_ptr;

  asb_ptr->avahi_service_browser = avahi_service_browser_new(ac_ptr->avahi_client,
      AVAHI_IF_UNSPEC,AVAHI_PROTO_UNSPEC,type_str->data,domain_str->data,
      (AvahiLookupFlags)flags,avahi_service_browser_s::browse_callback,service_browser_location);

  // - if exception occurred -
  if (ap_ptr->ret_code == c_run_return_code_EXCEPTION)
  {
    return false;
  }

  // - ERROR -
  if (asb_ptr->avahi_service_browser == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_AVAHI_SERVICE_BROWSER_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

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

// - class AVAHI_SERVICE_BROWSER -
built_in_class_s avahi_service_browser_class =
{/*{{{*/
  "AvahiServiceBrowser",
  c_modifier_public | c_modifier_final,
  9, avahi_service_browser_methods,
  7, avahi_service_browser_variables,
  bic_avahi_service_browser_consts,
  bic_avahi_service_browser_init,
  bic_avahi_service_browser_clear,
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

built_in_method_s avahi_service_browser_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_avahi_service_browser_operator_binary_equal
  },
  {
    "AvahiServiceBrowser#7",
    c_modifier_public | c_modifier_final,
    bic_avahi_service_browser_method_AvahiServiceBrowser_7
  },
  {
    "event#0",
    c_modifier_public | c_modifier_final,
    bic_avahi_service_browser_method_event_0
  },
  {
    "service#0",
    c_modifier_public | c_modifier_final,
    bic_avahi_service_browser_method_service_0
  },
  {
    "txt#0",
    c_modifier_public | c_modifier_final,
    bic_avahi_service_browser_method_txt_0
  },
  {
    "resolve#1",
    c_modifier_public | c_modifier_final,
    bic_avahi_service_browser_method_resolve_1
  },
  {
    "user_data#0",
    c_modifier_public | c_modifier_final,
    bic_avahi_service_browser_method_user_data_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_avahi_service_browser_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_avahi_service_browser_method_print_0
  },
};/*}}}*/

built_in_variable_s avahi_service_browser_variables[] =
{/*{{{*/

  // - avahi service browser event constants -
  { "EVENT_NEW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EVENT_REMOVE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EVENT_CACHE_EXHAUSTED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EVENT_ALL_FOR_NOW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EVENT_FAILURE", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - avahi service browser resolve constants -
  { "RESOLVER_FOUND", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "RESOLVER_FAILURE", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_avahi_service_browser_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert avahi service browser event constants -
  {
    const_locations.push_blanks(5);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 5);

#define CREATE_AVAHI_SERVICE_BROWSER_EVENT_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_AVAHI_SERVICE_BROWSER_EVENT_BIC_STATIC(AVAHI_BROWSER_NEW);
    CREATE_AVAHI_SERVICE_BROWSER_EVENT_BIC_STATIC(AVAHI_BROWSER_REMOVE);
    CREATE_AVAHI_SERVICE_BROWSER_EVENT_BIC_STATIC(AVAHI_BROWSER_CACHE_EXHAUSTED);
    CREATE_AVAHI_SERVICE_BROWSER_EVENT_BIC_STATIC(AVAHI_BROWSER_ALL_FOR_NOW);
    CREATE_AVAHI_SERVICE_BROWSER_EVENT_BIC_STATIC(AVAHI_BROWSER_FAILURE);
  }

  // - insert avahi service browser resolve constants -
  {
    const_locations.push_blanks(2);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 2);

#define CREATE_AVAHI_SERVICE_BROWSER_RESOLVE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_AVAHI_SERVICE_BROWSER_RESOLVE_BIC_STATIC(AVAHI_RESOLVER_FOUND);
    CREATE_AVAHI_SERVICE_BROWSER_RESOLVE_BIC_STATIC(AVAHI_RESOLVER_FAILURE);
  }

}/*}}}*/

void bic_avahi_service_browser_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (avahi_service_browser_s *)nullptr;
}/*}}}*/

void bic_avahi_service_browser_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  avahi_service_browser_s *asb_ptr = (avahi_service_browser_s *)location_ptr->v_data_ptr;

  if (asb_ptr != nullptr)
  {
    asb_ptr->clear(it);
    cfree(asb_ptr);
  }
}/*}}}*/

bool bic_avahi_service_browser_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_avahi_service_browser_method_AvahiServiceBrowser_7(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
client:c_bi_class_avahi_client
type:c_bi_class_string
domain:c_bi_class_string
flags:retrieve_integer
browse_callback:c_bi_class_delegate
resolve_callback:c_bi_class_delegate
user_data:ignore
>
method AvahiServiceBrowser
; @end

  avahi_client_s *ac_ptr = (avahi_client_s *)src_0_location->v_data_ptr;
  avahi_poll_s *ap_ptr = (avahi_poll_s *)ac_ptr->avahi_poll_loc->v_data_ptr;

  // - retrieve browse delegate pointer -
  delegate_s *browse_delegate_ptr = (delegate_s *)src_4_location->v_data_ptr;

  // - ERROR -
  if (browse_delegate_ptr->param_cnt != 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_AVAHI_SERVICE_BROWSER_WRONG_CALLBACK_DELEGATE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - retrieve resolve delegate pointer -
  delegate_s *resolve_delegate_ptr = (delegate_s *)src_5_location->v_data_ptr;

  // - ERROR -
  if (resolve_delegate_ptr->param_cnt != 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_AVAHI_SERVICE_BROWSER_WRONG_CALLBACK_DELEGATE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create avahi_service_browser object -
  avahi_service_browser_s *asb_ptr = (avahi_service_browser_s *)cmalloc(sizeof(avahi_service_browser_s));
  asb_ptr->init();

  // - set avahi_client location -
  src_0_location->v_reference_cnt.atomic_inc();
  asb_ptr->avahi_client_loc = src_0_location;

  // - set browse callback delegate -
  src_4_location->v_reference_cnt.atomic_inc();
  asb_ptr->browse_cb_dlg = src_4_location;

  // - set resolve callback delegate -
  src_5_location->v_reference_cnt.atomic_inc();
  asb_ptr->resolve_cb_dlg = src_5_location;

  // - set user_data location -
  src_6_location->v_reference_cnt.atomic_inc();
  asb_ptr->user_data_loc = src_6_location;

  // - set avahi_service_browser data pointer -
  dst_location->v_data_ptr = (avahi_service_browser_s *)asb_ptr;

  ap_ptr->it_ptr = &it;
  ap_ptr->source_pos = operands[c_source_pos_idx];
  ap_ptr->ret_code = c_run_return_code_OK;

  string_s *type_str = (string_s *)src_1_location->v_data_ptr;
  string_s *domain_str = (string_s *)src_2_location->v_data_ptr;

  asb_ptr->avahi_service_browser = avahi_service_browser_new(ac_ptr->avahi_client,
      AVAHI_IF_UNSPEC,AVAHI_PROTO_UNSPEC,type_str->data,domain_str->data,
      (AvahiLookupFlags)flags,avahi_service_browser_s::browse_callback,dst_location);

  // - if exception occurred -
  if (ap_ptr->ret_code == c_run_return_code_EXCEPTION)
  {
    return false;
  }

  // - ERROR -
  if (asb_ptr->avahi_service_browser == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_AVAHI_SERVICE_BROWSER_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  return true;
}/*}}}*/

bool bic_avahi_service_browser_method_event_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  avahi_service_browser_s *asb_ptr = (avahi_service_browser_s *)dst_location->v_data_ptr;

  long long int result;

  if (asb_ptr->browse_event != (AvahiBrowserEvent)-1)
  {
    result = asb_ptr->browse_event;
  }
  else if (asb_ptr->resolve_event != (AvahiResolverEvent)-1)
  {
    result = asb_ptr->resolve_event;
  }

  // - ERROR -
  else
  {
    exception_s::throw_exception(it,module.error_base + c_error_AVAHI_SERVICE_BROWSER_ACCESS_OUTSIDE_OF_BROWSE_CALLBACK,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_avahi_service_browser_method_service_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  avahi_service_browser_s *asb_ptr = (avahi_service_browser_s *)dst_location->v_data_ptr;

  // - create result array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

#define BIC_AVAHI_SERVICE_BROWSER_SERVICE_STRING_VALUE(NAME) \
/*{{{*/\
  if (asb_ptr->NAME != nullptr)\
  {\
    string_s *value_str = it.get_new_string_ptr();\
    value_str->set(strlen(asb_ptr->NAME),asb_ptr->NAME);\
\
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,value_str);\
    array_ptr->push(new_location);\
  }\
  else\
  {\
    ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();\
    array_ptr->push(it.blank_location);\
  }
/*}}}*/

  if (asb_ptr->browse_event != (AvahiBrowserEvent)-1)
  {
    BIC_AVAHI_SERVICE_BROWSER_SERVICE_STRING_VALUE(browse_name);
    BIC_AVAHI_SERVICE_BROWSER_SERVICE_STRING_VALUE(browse_type);
    BIC_AVAHI_SERVICE_BROWSER_SERVICE_STRING_VALUE(browse_domain);
  }
  else if (asb_ptr->resolve_event != (AvahiResolverEvent)-1)
  {
    BIC_AVAHI_SERVICE_BROWSER_SERVICE_STRING_VALUE(resolve_name);
    BIC_AVAHI_SERVICE_BROWSER_SERVICE_STRING_VALUE(resolve_type);
    BIC_AVAHI_SERVICE_BROWSER_SERVICE_STRING_VALUE(resolve_domain);
    BIC_AVAHI_SERVICE_BROWSER_SERVICE_STRING_VALUE(resolve_host);

    long long int resolve_port = asb_ptr->resolve_port;
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,resolve_port);
    array_ptr->push(new_location);
  }

  // - ERROR -
  else
  {
    array_ptr->clear();
    cfree(array_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_AVAHI_SERVICE_BROWSER_ACCESS_OUTSIDE_OF_BROWSE_CALLBACK,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_CREATE_NEW_LOCATION(array_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(array_location);

  return true;
}/*}}}*/

bool bic_avahi_service_browser_method_txt_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  avahi_service_browser_s *asb_ptr = (avahi_service_browser_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (asb_ptr->resolve_event == (AvahiResolverEvent)-1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_AVAHI_SERVICE_BROWSER_ACCESS_OUTSIDE_OF_RESOLVE_CALLBACK,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create result array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  AvahiStringList *txt = asb_ptr->resolve_txt;
  while (txt != nullptr)
  {
    string_s *value_str = it.get_new_string_ptr();
    value_str->set(txt->size,(const char *)txt->text);

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,value_str);
    array_ptr->push(new_location);

    txt = txt->next;
  }

  BIC_CREATE_NEW_LOCATION(array_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(array_location);

  return true;
}/*}}}*/

bool bic_avahi_service_browser_method_resolve_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
flags:retrieve_integer
>
method resolve
; @end

  avahi_service_browser_s *asb_ptr = (avahi_service_browser_s *)dst_location->v_data_ptr;
  avahi_client_s *ac_ptr = (avahi_client_s *)asb_ptr->avahi_client_loc->v_data_ptr;

  // - ERROR -
  if (asb_ptr->browse_event == (AvahiBrowserEvent)-1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_AVAHI_SERVICE_BROWSER_ACCESS_OUTSIDE_OF_BROWSE_CALLBACK,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  AvahiServiceResolver *resolver = avahi_service_resolver_new(ac_ptr->avahi_client,asb_ptr->browse_interface,
      asb_ptr->browse_protocol,asb_ptr->browse_name,asb_ptr->browse_type,asb_ptr->browse_domain,
      AVAHI_PROTO_INET,(AvahiLookupFlags)flags,avahi_service_browser_s::resolve_callback,dst_location);

  // - ERROR -
  if (resolver == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_AVAHI_SERVICE_BROWSER_CREATE_RESOLVER_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_avahi_service_browser_method_user_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  avahi_service_browser_s *asb_ptr = (avahi_service_browser_s *)dst_location->v_data_ptr;

  location_s *new_ref_location = it.get_new_reference(&asb_ptr->user_data_loc);

  BIC_SET_RESULT(new_ref_location);

  return true;
}/*}}}*/

bool bic_avahi_service_browser_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("AvahiServiceBrowser"),"AvahiServiceBrowser");
  );

  return true;
}/*}}}*/

bool bic_avahi_service_browser_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("AvahiServiceBrowser");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

