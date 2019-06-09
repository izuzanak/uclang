
@begin
include "nanomsg_module.h"
@end

// - NANOMSG indexes of built in classes -
unsigned c_bi_class_nano_msg = c_idx_not_exist;
unsigned c_bi_class_nano_socket = c_idx_not_exist;
unsigned c_bi_class_nano_endpoint = c_idx_not_exist;

// - NANOMSG module -
EXPORT built_in_module_s module =
{/*{{{*/
  3,                       // Class count
  nanomsg_classes,         // Classes

  0,                       // Error base index
  1,                       // Error count
  nanomsg_error_strings,   // Error strings

  nanomsg_initialize,      // Initialize function
  nanomsg_print_exception, // Print exceptions function
};/*}}}*/

// - NANOMSG classes -
built_in_class_s *nanomsg_classes[] =
{/*{{{*/
  &nano_msg_class,
  &nano_socket_class,
  &nano_endpoint_class,
};/*}}}*/

// - NANOMSG error strings -
const char *nanomsg_error_strings[] =
{/*{{{*/
  "error_NANOMSG_DUMMY_ERROR",
};/*}}}*/

// - NANOMSG initialize -
bool nanomsg_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize nano_msg class identifier -
  c_bi_class_nano_msg = class_base_idx++;

  // - initialize nano_socket class identifier -
  c_bi_class_nano_socket = class_base_idx++;

  // - initialize nano_endpoint class identifier -
  c_bi_class_nano_endpoint = class_base_idx++;

  return true;
}/*}}}*/

// - NANOMSG print exception -
bool nanomsg_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_NANOMSG_DUMMY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nNanoMsg dummy error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class NANO_MSG -
built_in_class_s nano_msg_class =
{/*{{{*/
  "NanoMsg",
  c_modifier_public | c_modifier_final,
  3, nano_msg_methods,
  0, nano_msg_variables,
  bic_nano_msg_consts,
  bic_nano_msg_init,
  bic_nano_msg_clear,
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

built_in_method_s nano_msg_methods[] =
{/*{{{*/
  {
    "term#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_nano_msg_method_term_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_nano_msg_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_nano_msg_method_print_0
  },
};/*}}}*/

built_in_variable_s nano_msg_variables[] =
{/*{{{*/
};/*}}}*/

void bic_nano_msg_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_nano_msg_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_nano_msg_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_nano_msg_method_term_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  nn_term();

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_nano_msg_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("NanoMsg"),"NanoMsg");
  );

  return true;
}/*}}}*/

bool bic_nano_msg_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("NanoMsg");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class NANO_SOCKET -
built_in_class_s nano_socket_class =
{/*{{{*/
  "NanoSocket",
  c_modifier_public | c_modifier_final,
  6, nano_socket_methods,
  2 + 10, nano_socket_variables,
  bic_nano_socket_consts,
  bic_nano_socket_init,
  bic_nano_socket_clear,
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

built_in_method_s nano_socket_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_nano_socket_operator_binary_equal
  },
  {
    "NanoSocket#2",
    c_modifier_public | c_modifier_final,
    bic_nano_socket_method_NanoSocket_2
  },
  {
    "bind#1",
    c_modifier_public | c_modifier_final,
    bic_nano_socket_method_bind_1
  },
  {
    "connect#1",
    c_modifier_public | c_modifier_final,
    bic_nano_socket_method_connect_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_nano_socket_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_nano_socket_method_print_0
  },
};/*}}}*/

built_in_variable_s nano_socket_variables[] =
{/*{{{*/
  { "AF_SP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "AF_SP_RAW", c_modifier_public | c_modifier_static | c_modifier_static_const },

  { "NN_BUS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_PAIR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_PUSH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_PULL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_PUB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_SUB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_REQ", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_REP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_SURVEYOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "NN_RESPONDENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
};/*}}}*/

void bic_nano_socket_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert socket constants -
  {
    const_locations.push_blanks(2);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 2);

#define CREATE_NANO_SOCKET_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_NANO_SOCKET_BIC_STATIC(AF_SP);
    CREATE_NANO_SOCKET_BIC_STATIC(AF_SP_RAW);
  }

  // - insert socket protocol constants -
  {
    const_locations.push_blanks(10);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 10);

#define CREATE_NANO_SOCKET_PROTOCOL_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_NANO_SOCKET_PROTOCOL_BIC_STATIC(NN_BUS);
    CREATE_NANO_SOCKET_PROTOCOL_BIC_STATIC(NN_PAIR);
    CREATE_NANO_SOCKET_PROTOCOL_BIC_STATIC(NN_PUSH);
    CREATE_NANO_SOCKET_PROTOCOL_BIC_STATIC(NN_PULL);
    CREATE_NANO_SOCKET_PROTOCOL_BIC_STATIC(NN_PUB);
    CREATE_NANO_SOCKET_PROTOCOL_BIC_STATIC(NN_SUB);
    CREATE_NANO_SOCKET_PROTOCOL_BIC_STATIC(NN_REQ);
    CREATE_NANO_SOCKET_PROTOCOL_BIC_STATIC(NN_REP);
    CREATE_NANO_SOCKET_PROTOCOL_BIC_STATIC(NN_SURVEYOR);
    CREATE_NANO_SOCKET_PROTOCOL_BIC_STATIC(NN_RESPONDENT);
  }
}/*}}}*/

void bic_nano_socket_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (int)-1;
}/*}}}*/

void bic_nano_socket_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  int nn_fd = (int)location_ptr->v_data_ptr;

  if (nn_fd != -1)
  {
    nn_close(nn_fd);
  }
}/*}}}*/

bool bic_nano_socket_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_nano_socket_method_NanoSocket_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
domain:retrieve_integer
protocol:retrieve_integer
>
method NanoSocket
; @end

  int nn_fd;

  // - ERROR -
  if ((nn_fd = nn_socket(domain,protocol)) == -1)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  dst_location->v_data_ptr = (int)nn_fd;

  return true;
}/*}}}*/

bool bic_nano_socket_method_bind_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
address:c_bi_class_string
>
method bind
; @end

  int nn_fd = (int)dst_location->v_data_ptr;
  string_s *address_ptr = (string_s *)src_0_location->v_data_ptr;

  int end_id;

  // - ERROR -
  if ((end_id = nn_bind(nn_fd,address_ptr->data)) == -1)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  // - create nano_endpoint object -
  nano_endpoint_s *ne_ptr = (nano_endpoint_s *)cmalloc(sizeof(nano_endpoint_s));
  ne_ptr->init();

  // - store reference to socket -
  dst_location->v_reference_cnt.atomic_inc();
  ne_ptr->socket_ptr = dst_location;

  ne_ptr->end_id = end_id;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_nano_endpoint,ne_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_nano_socket_method_connect_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
address:c_bi_class_string
>
method connect
; @end

  int nn_fd = (int)dst_location->v_data_ptr;
  string_s *address_ptr = (string_s *)src_0_location->v_data_ptr;

  int end_id;

  // - ERROR -
  if ((end_id = nn_connect(nn_fd,address_ptr->data)) == -1)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  // - create nano_endpoint object -
  nano_endpoint_s *ne_ptr = (nano_endpoint_s *)cmalloc(sizeof(nano_endpoint_s));
  ne_ptr->init();

  // - store reference to socket -
  dst_location->v_reference_cnt.atomic_inc();
  ne_ptr->socket_ptr = dst_location;

  ne_ptr->end_id = end_id;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_nano_endpoint,ne_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_nano_socket_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("NanoSocket"),"NanoSocket");
  );

  return true;
}/*}}}*/

bool bic_nano_socket_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("NanoSocket");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class NANO_ENDPOINT -
built_in_class_s nano_endpoint_class =
{/*{{{*/
  "NanoEndpoint",
  c_modifier_public | c_modifier_final,
  3, nano_endpoint_methods,
  0, nano_endpoint_variables,
  bic_nano_endpoint_consts,
  bic_nano_endpoint_init,
  bic_nano_endpoint_clear,
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

built_in_method_s nano_endpoint_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_nano_endpoint_operator_binary_equal
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_nano_endpoint_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_nano_endpoint_method_print_0
  },
};/*}}}*/

built_in_variable_s nano_endpoint_variables[] =
{/*{{{*/
};/*}}}*/

void bic_nano_endpoint_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_nano_endpoint_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (nano_endpoint_s *)nullptr;
}/*}}}*/

void bic_nano_endpoint_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  nano_endpoint_s *ne_ptr = (nano_endpoint_s *)location_ptr->v_data_ptr;

  if (ne_ptr != nullptr)
  {
    ne_ptr->clear(it);
    cfree(ne_ptr);
  }
}/*}}}*/

bool bic_nano_endpoint_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_nano_endpoint_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("NanoEndpoint"),"NanoEndpoint");
  );

  return true;
}/*}}}*/

bool bic_nano_endpoint_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("NanoEndpoint");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

