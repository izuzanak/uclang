
@begin
include "websocket_module.h"
@end

// - WEBSOCKET indexes of built in classes -
unsigned c_bi_class_ws_context = c_idx_not_exist;
unsigned c_bi_class_ws_conn = c_idx_not_exist;
unsigned c_bi_class_ws_client = c_idx_not_exist;
unsigned c_bi_class_ws_base64 = c_idx_not_exist;

// - WEBSOCKET module -
built_in_module_s module =
{/*{{{*/
  4,                         // Class count
  websocket_classes,         // Classes

  0,                         // Error base index
  14,                        // Error count
  websocket_error_strings,   // Error strings

  websocket_initialize,      // Initialize function
  websocket_print_exception, // Print exceptions function
};/*}}}*/

// - WEBSOCKET classes -
built_in_class_s *websocket_classes[] =
{/*{{{*/
  &ws_context_class,
  &ws_conn_class,
  &ws_client_class,
  &ws_base64_class,
};/*}}}*/

// - WEBSOCKET error strings -
const char *websocket_error_strings[] =
{/*{{{*/
  "error_WS_CONTEXT_CREATE_ERROR",
  "error_WS_CONTEXT_EMPTY_PROTOCOL_ARRAY",
  "error_WS_CONTEXT_NOT_EVEN_PROTOCOL_ARRAY",
  "error_WS_CONTEXT_WRONG_PAIR_NAME_DELEGATE",
  "error_WS_CONTEXT_WRONG_CALLBACK_DELEGATE",
  "error_WS_CONTEXT_CANNOT_CREATE_CLIENT_CONNECTION",
  "error_WS_CONTEXT_PROTOCOL_NAME_NOT_FOUND",
  "error_WS_CONTEXT_PROTOCOL_INDEX_EXCEEDS_RANGE",
  "error_WS_CONN_SET_TIMEOUT_UNKNOWN_REASON",
  "error_WS_CONN_SET_TIMEOUT_WRONG_VALUE",
  "error_WS_CONN_WRITE_ERROR",
  "error_WS_CLIENT_NOT_CONNECTED_TO_SERVER",
  "error_WS_BASE64_ENCODE_ERROR",
  "error_WS_BASE64_DECODE_ERROR",
};/*}}}*/

// - WEBSOCKET initialize -
bool websocket_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize ws_context class identifier -
  c_bi_class_ws_context = class_base_idx++;

  // - initialize ws_conn class identifier -
  c_bi_class_ws_conn = class_base_idx++;

  // - initialize ws_client class identifier -
  c_bi_class_ws_client = class_base_idx++;

  // - initialize ws_base64 class identifier -
  c_bi_class_ws_base64 = class_base_idx++;

  return true;
}/*}}}*/

// - WEBSOCKET print exception -
bool websocket_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_WS_CONTEXT_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating websocket context\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_WS_CONTEXT_EMPTY_PROTOCOL_ARRAY:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nEmpty protocol array was received\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_WS_CONTEXT_NOT_EVEN_PROTOCOL_ARRAY:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nProtocol array must have even count of elements\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_WS_CONTEXT_WRONG_PAIR_NAME_DELEGATE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid protocol array name-delegate pair at position %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_WS_CONTEXT_WRONG_CALLBACK_DELEGATE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong type of protocol callback delegate at position %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_WS_CONTEXT_CANNOT_CREATE_CLIENT_CONNECTION:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot create requested client connection\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_WS_CONTEXT_PROTOCOL_NAME_NOT_FOUND:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nProtocol with name \"%s\" was not found\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_WS_CONTEXT_PROTOCOL_INDEX_EXCEEDS_RANGE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nProtocol index %" HOST_LL_FORMAT "d exceeds protocol count\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_WS_CONN_SET_TIMEOUT_UNKNOWN_REASON:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUnrecognized identifier of timeout reason\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_WS_CONN_SET_TIMEOUT_WRONG_VALUE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong (negative) timeout value: %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_WS_CONN_WRITE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while writing to websocket\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_WS_CLIENT_NOT_CONNECTED_TO_SERVER:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nClient is not connected to server\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_WS_BASE64_ENCODE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while encoding data to Base64\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_WS_BASE64_DECODE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while decoding data from Base64\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class WS_CONTEXT -
built_in_class_s ws_context_class =
{/*{{{*/
  "WsContext",
  c_modifier_public | c_modifier_final,
  11, ws_context_methods,
  1, ws_context_variables,
  bic_ws_context_consts,
  bic_ws_context_init,
  bic_ws_context_clear,
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

built_in_method_s ws_context_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_ws_context_operator_binary_equal
  },
  {
    "WsContext#2",
    c_modifier_public | c_modifier_final,
    bic_ws_context_method_WsContext_2
  },
  {
    "version#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ws_context_method_version_0
  },
  {
    "user_data#0",
    c_modifier_public | c_modifier_final,
    bic_ws_context_method_user_data_0
  },
  {
    "client#4",
    c_modifier_public | c_modifier_final,
    bic_ws_context_method_client_4
  },
  {
    "get_fds#0",
    c_modifier_public | c_modifier_final,
    bic_ws_context_method_get_fds_0
  },
  {
    "process#1",
    c_modifier_public | c_modifier_final,
    bic_ws_context_method_process_1
  },
  {
    "protocol_idx#1",
    c_modifier_public | c_modifier_final,
    bic_ws_context_method_protocol_idx_1
  },
  {
    "callback_on_writable#1",
    c_modifier_public | c_modifier_final,
    bic_ws_context_method_callback_on_writable_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ws_context_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ws_context_method_print_0
  },
};/*}}}*/

built_in_variable_s ws_context_variables[] =
{/*{{{*/
  { "PORT_NO_LISTEN", c_modifier_public | c_modifier_static | c_modifier_static_const },
};/*}}}*/

void bic_ws_context_consts(location_array_s &const_locations)
{/*{{{*/

  const_locations.push_blanks(1);
  location_s *cv_ptr = const_locations.data + (const_locations.used - 1);

#define CREATE_WS_PORT_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

  CREATE_WS_PORT_TYPE_BIC_STATIC(CONTEXT_PORT_NO_LISTEN);
}/*}}}*/

void bic_ws_context_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (ws_context_s *)NULL;
}/*}}}*/

void bic_ws_context_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  ws_context_s *wsc_ptr = (ws_context_s *)location_ptr->v_data_ptr;

  // - if websocket context exists -
  if (wsc_ptr != NULL)
  {
    wsc_ptr->clear(it);
    cfree(wsc_ptr);
  }
}/*}}}*/

bool bic_ws_context_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_ws_context_method_WsContext_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int port;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,port) ||
      src_1_location->v_type != c_bi_class_array)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("WsContext#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  // - retrieve protocols array -
  pointer_array_s *array_ptr = (pointer_array_s *)src_1_location->v_data_ptr;

  // - ERROR -
  if (array_ptr->used == 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_WS_CONTEXT_EMPTY_PROTOCOL_ARRAY,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (array_ptr->used & 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_WS_CONTEXT_NOT_EVEN_PROTOCOL_ARRAY,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create websocket context object -
  ws_context_s *wsc_ptr = (ws_context_s *)cmalloc(sizeof(ws_context_s));
  wsc_ptr->init();

  // - create websocket protocols structure -
  wsc_ptr->protocols = (libwebsocket_protocols *)cmalloc((2 + (array_ptr->used / 2))*sizeof(libwebsocket_protocols));

  // - configure http protocol -
  libwebsocket_protocols *http_prot = wsc_ptr->protocols;
  http_prot->name = "http-only";
  http_prot->callback = http_func;
  http_prot->per_session_data_size = 0;
  http_prot->rx_buffer_size = 0;

  // - process protocol names and delegates -
  pointer *ptr = array_ptr->data;
  pointer *ptr_end = ptr + array_ptr->used;
  unsigned prot_idx = 1;
  do {
    location_s *name_location = it.get_location_value(ptr[0]);
    location_s *dlg_location = it.get_location_value(ptr[1]);

    // - ERROR -
    if (name_location->v_type != c_bi_class_string ||
        dlg_location->v_type != c_bi_class_delegate)
    {
      wsc_ptr->clear(it);
      cfree(wsc_ptr);

      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_WS_CONTEXT_WRONG_PAIR_NAME_DELEGATE,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(prot_idx - 1);

      return false;
    }

    // - copy websocket protocol name -
    wsc_ptr->prot_names.push(*((string_s *)name_location->v_data_ptr));

    // - retrieve delegate pointer -
    delegate_s *delegate_ptr = (delegate_s *)dlg_location->v_data_ptr;

    // - ERROR -
    if (delegate_ptr->param_cnt != 1)
    {
      wsc_ptr->clear(it);
      cfree(wsc_ptr);

      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_WS_CONTEXT_WRONG_CALLBACK_DELEGATE,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(prot_idx - 1);

      return false;
    }

    // - store websocket protocol callback delegate -
    dlg_location->v_reference_cnt.atomic_inc();
    wsc_ptr->prot_dlgs.push(dlg_location);

    // - configure websocket protocol -
    libwebsocket_protocols *ws_prot = wsc_ptr->protocols + prot_idx++;
    ws_prot->name = wsc_ptr->prot_names.last().data;
    ws_prot->callback = protocol_func;
    ws_prot->per_session_data_size = sizeof(pointer);
    ws_prot->rx_buffer_size = 0;
    ws_prot->no_buffer_all_partial_tx = 1;

  } while((ptr += 2) < ptr_end);

  // - configure terminator protocol -
  libwebsocket_protocols *term_prot = wsc_ptr->protocols + prot_idx;
  term_prot->name = NULL;
  term_prot->callback = NULL;
  term_prot->per_session_data_size = 0;
  term_prot->rx_buffer_size = 0;

  // - create websocket context creation info -
  lws_context_creation_info info;
  memset(&info,0,sizeof info);

  info.port = port;
  info.iface = NULL;
  info.protocols = wsc_ptr->protocols;
  info.extensions = libwebsocket_get_internal_extensions();
  info.gid = -1;
  info.uid = -1;
  info.options = 0;
  info.user = wsc_ptr;

  // - create wesocket context -
  wsc_ptr->context = libwebsocket_create_context(&info);

  // - ERROR -
  if (wsc_ptr->context == NULL)
  {
    wsc_ptr->clear(it);
    cfree(wsc_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_WS_CONTEXT_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - initialize user data pointer -
  ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();
  wsc_ptr->user_data_ptr = (location_s *)it.blank_location;

  dst_location->v_data_ptr = (ws_context_s *)wsc_ptr;

  return true;
}/*}}}*/

bool bic_ws_context_method_version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  // - retrieve websockets library version -
  const char *version = lws_get_library_version();

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(version),version);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_ws_context_method_user_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ws_context_s *wsc_ptr = (ws_context_s *)dst_location->v_data_ptr;

  location_s *new_ref_location = it.get_new_reference(&wsc_ptr->user_data_ptr);

  BIC_SET_RESULT(new_ref_location);

  return true;
}/*}}}*/

bool bic_ws_context_method_client_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);
  location_s *src_3_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_3_op_idx]);

  long long int port;

  if (src_0_location->v_type != c_bi_class_string ||
      !it.retrieve_integer(src_1_location,port)||
      src_2_location->v_type != c_bi_class_string ||
      src_3_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("client#4");
    new_exception->params.push(4);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);
    new_exception->params.push(src_3_location->v_type);

    return false;
  }

  ws_context_s *wsc_ptr = (ws_context_s *)dst_location->v_data_ptr;

  string_s *addr_ptr = (string_s *)src_0_location->v_data_ptr;
  string_s *path_ptr = (string_s *)src_2_location->v_data_ptr;
  string_s *prot_ptr = (string_s *)src_3_location->v_data_ptr;

  // - create websocket client user data pointer -
  ws_client_s **wscl_udp_ptr = (ws_client_s **)cmalloc(sizeof(ws_client_s *));

  // - connect client to server -
  libwebsocket *wsi = libwebsocket_client_connect_extended(
      wsc_ptr->context,addr_ptr->data,port,0,path_ptr->data,
      addr_ptr->data,addr_ptr->data,prot_ptr->data,-1,wscl_udp_ptr);

  // - ERROR -
  if (wsi == NULL)
  {
    cfree(wscl_udp_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_WS_CONTEXT_CANNOT_CREATE_CLIENT_CONNECTION,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create websocket client object -
  ws_client_s *wscl_ptr = (ws_client_s *)cmalloc(sizeof(ws_client_s));
  wscl_ptr->init();

  // - set websocket client user data pointer -
  *wscl_udp_ptr = wscl_ptr;

  // - set websocket context pointer -
  dst_location->v_reference_cnt.atomic_inc();
  wscl_ptr->wsc_location = dst_location;

  // - set websocket pointer -
  wscl_ptr->ws_ptr = wsi;

  // - set websocket client user data pointer -
  wscl_ptr->wscl_udp_ptr = wscl_udp_ptr;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_ws_client,wscl_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_ws_context_method_get_fds_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ws_context_s *wsc_ptr = (ws_context_s *)dst_location->v_data_ptr;
  fd_flags_rb_tree_s &poll_fds = wsc_ptr->poll_fds;

  // - create result array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  if (poll_fds.root_idx != c_idx_not_exist)
  {
    unsigned stack[poll_fds.get_descent_stack_size()];
    unsigned *stack_ptr = stack;

    unsigned ff_idx = poll_fds.get_stack_min_value_idx(poll_fds.root_idx,&stack_ptr);
    do {
      fd_flags_s &fd_flags = poll_fds[ff_idx];

      {
        BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,fd_flags.fd);
        array_ptr->push(new_location);
      }

      {
        BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,fd_flags.flags);
        array_ptr->push(new_location);
      }

      ff_idx = poll_fds.get_stack_next_idx(ff_idx,&stack_ptr,stack);
    } while(ff_idx != c_idx_not_exist);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_ws_context_method_process_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int timeout;

  if (!it.retrieve_integer(src_0_location,timeout))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("process#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve websocket context -
  ws_context_s *wsc_ptr = (ws_context_s *)dst_location->v_data_ptr;
  wsc_ptr->it_ptr = &it;
  wsc_ptr->source_pos = operands[c_source_pos_idx];
  wsc_ptr->ret_code = c_run_return_code_OK;

  // - service websocket context -
  libwebsocket_service(wsc_ptr->context,timeout);

  // - if exception occurred -
  if (wsc_ptr->ret_code == c_run_return_code_EXCEPTION)
  {
    return false;
  }

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_ws_context_method_protocol_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("protocol_idx#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  ws_context_s *wsc_ptr = (ws_context_s *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - search websocket protocol index by its name -
  long long int result = wsc_ptr->prot_names.get_idx(*string_ptr);

  // - ERROR -
  if (result == c_idx_not_exist)
  {
    exception_s::throw_exception(it,module.error_base + c_error_WS_CONTEXT_PROTOCOL_NAME_NOT_FOUND,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_ws_context_method_callback_on_writable_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int prot_idx;

  if (!it.retrieve_integer(src_0_location,prot_idx))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("callback_on_writable#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  ws_context_s *wsc_ptr = (ws_context_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (prot_idx >= wsc_ptr->prot_names.used)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_WS_CONTEXT_PROTOCOL_INDEX_EXCEEDS_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(prot_idx);

    return false;
  }

  libwebsocket_callback_on_writable_all_protocol(wsc_ptr->protocols + 1 + prot_idx);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_ws_context_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("WsContext"),"WsContext");
  );

  return true;
}/*}}}*/

bool bic_ws_context_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("WsContext");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class WS_CONN -
built_in_class_s ws_conn_class =
{/*{{{*/
  "WsConn",
  c_modifier_public | c_modifier_final,
  12, ws_conn_methods,
  7 + 25 + 10, ws_conn_variables,
  bic_ws_conn_consts,
  bic_ws_conn_init,
  bic_ws_conn_clear,
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

built_in_method_s ws_conn_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_ws_conn_operator_binary_equal
  },
  {
    "reason#0",
    c_modifier_public | c_modifier_final,
    bic_ws_conn_method_reason_0
  },
  {
    "received_data#0",
    c_modifier_public | c_modifier_final,
    bic_ws_conn_method_received_data_0
  },
  {
    "user_data#0",
    c_modifier_public | c_modifier_final,
    bic_ws_conn_method_user_data_0
  },
  {
    "ctx_user_data#0",
    c_modifier_public | c_modifier_final,
    bic_ws_conn_method_ctx_user_data_0
  },
  {
    "protocol_name#0",
    c_modifier_public | c_modifier_final,
    bic_ws_conn_method_protocol_name_0
  },
  {
    "callback_on_writable#0",
    c_modifier_public | c_modifier_final,
    bic_ws_conn_method_callback_on_writable_0
  },
  {
    "set_timeout#2",
    c_modifier_public | c_modifier_final,
    bic_ws_conn_method_set_timeout_2
  },
  {
    "write#1",
    c_modifier_public | c_modifier_final,
    bic_ws_conn_method_write_1
  },
  {
    "write#2",
    c_modifier_public | c_modifier_final,
    bic_ws_conn_method_write_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ws_conn_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ws_conn_method_print_0
  },
};/*}}}*/

built_in_variable_s ws_conn_variables[] =
{/*{{{*/

  // - write data types -
  { "WRITE_TEXT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "WRITE_BINARY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "WRITE_CONTINUATION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "WRITE_HTTP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "WRITE_CLOSE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "WRITE_PING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "WRITE_PONG", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - callback types -
  { "CB_ESTABLISHED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CB_CLIENT_CONNECTION_ERROR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CB_CLIENT_FILTER_PRE_ESTABLISH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CB_CLIENT_ESTABLISHED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CB_CLOSED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CB_RECEIVE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CB_CLIENT_RECEIVE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CB_CLIENT_RECEIVE_PONG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CB_CLIENT_WRITEABLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CB_SERVER_WRITEABLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CB_HTTP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CB_HTTP_FILE_COMPLETION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CB_FILTER_NETWORK_CONNECTION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CB_FILTER_PROTOCOL_CONNECTION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CB_OPENSSL_LOAD_EXTRA_CLIENT_VERIFY_CERTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CB_OPENSSL_LOAD_EXTRA_SERVER_VERIFY_CERTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CB_OPENSSL_PERFORM_CLIENT_CERT_VERIFICATION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CB_CLIENT_APPEND_HANDSHAKE_HEADER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CB_CONFIRM_EXTENSION_OKAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CB_CLIENT_CONFIRM_EXTENSION_SUPPORTED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CB_PROTOCOL_INIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CB_PROTOCOL_DESTROY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CB_ADD_POLL_FD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CB_DEL_POLL_FD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CB_CHANGE_MODE_POLL_FD", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - timeout types -
  { "TIMEOUT_NO_PENDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TIMEOUT_AWAITING_PROXY_RESPONSE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TIMEOUT_AWAITING_CONNECT_RESPONSE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TIMEOUT_ESTABLISH_WITH_SERVER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TIMEOUT_AWAITING_SERVER_RESPONSE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TIMEOUT_AWAITING_PING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TIMEOUT_CLOSE_ACK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TIMEOUT_AWAITING_EXTENSION_CONNECT_RESPONSE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TIMEOUT_SENT_CLIENT_HANDSHAKE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TIMEOUT_SSL_ACCEPT", c_modifier_public | c_modifier_static | c_modifier_static_const },
};/*}}}*/

#define BIC_WS_CONN_WRITE(DATA_LOCATION,WRITE_TYPE) \
{/*{{{*/\
\
  /* - retrieve websocket connection - */\
  ws_conn_s *wscn_ptr = (ws_conn_s *)dst_location->v_data_ptr;\
\
  string_s *string_ptr = (string_s *)DATA_LOCATION->v_data_ptr;\
  unsigned string_len = string_ptr->size - 1;\
\
  /* - allocate data buffer - */\
  unsigned char *buffer = (unsigned char *)cmalloc(\
      LWS_SEND_BUFFER_PRE_PADDING + string_len +\
      LWS_SEND_BUFFER_POST_PADDING);\
\
  /* - pointer to data in buffer - */\
  unsigned char *buff_ptr = buffer + LWS_SEND_BUFFER_PRE_PADDING;\
\
  /* - fill data to buffer - */\
  memcpy(buff_ptr,string_ptr->data,string_len);\
\
  /* - ERROR - */\
  if (libwebsocket_write(wscn_ptr->ws_ptr,buff_ptr,string_len,WRITE_TYPE) < 0)\
  {\
    /* - release data buffer - */\
    cfree(buffer);\
\
    exception_s::throw_exception(it,module.error_base + c_error_WS_CONN_WRITE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  /* - release data buffer - */\
  cfree(buffer);\
\
  BIC_SET_RESULT_BLANK();\
\
  return true;\
}/*}}}*/

void bic_ws_conn_consts(location_array_s &const_locations)
{/*{{{*/

  // - write data types -
  {
    const_locations.push_blanks(7);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 7);

#define CREATE_WS_CONN_WRITE_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_WS_CONN_WRITE_TYPE_BIC_STATIC(LWS_WRITE_TEXT);
    CREATE_WS_CONN_WRITE_TYPE_BIC_STATIC(LWS_WRITE_BINARY);
    CREATE_WS_CONN_WRITE_TYPE_BIC_STATIC(LWS_WRITE_CONTINUATION);
    CREATE_WS_CONN_WRITE_TYPE_BIC_STATIC(LWS_WRITE_HTTP);
    CREATE_WS_CONN_WRITE_TYPE_BIC_STATIC(LWS_WRITE_CLOSE);
    CREATE_WS_CONN_WRITE_TYPE_BIC_STATIC(LWS_WRITE_PING);
    CREATE_WS_CONN_WRITE_TYPE_BIC_STATIC(LWS_WRITE_PONG);
  }

  // - callback types -
  {
    const_locations.push_blanks(25);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 25);

#define CREATE_WS_CONN_CB_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_WS_CONN_CB_TYPE_BIC_STATIC(LWS_CALLBACK_ESTABLISHED);
    CREATE_WS_CONN_CB_TYPE_BIC_STATIC(LWS_CALLBACK_CLIENT_CONNECTION_ERROR);
    CREATE_WS_CONN_CB_TYPE_BIC_STATIC(LWS_CALLBACK_CLIENT_FILTER_PRE_ESTABLISH);
    CREATE_WS_CONN_CB_TYPE_BIC_STATIC(LWS_CALLBACK_CLIENT_ESTABLISHED);
    CREATE_WS_CONN_CB_TYPE_BIC_STATIC(LWS_CALLBACK_CLOSED);
    CREATE_WS_CONN_CB_TYPE_BIC_STATIC(LWS_CALLBACK_RECEIVE);
    CREATE_WS_CONN_CB_TYPE_BIC_STATIC(LWS_CALLBACK_CLIENT_RECEIVE);
    CREATE_WS_CONN_CB_TYPE_BIC_STATIC(LWS_CALLBACK_CLIENT_RECEIVE_PONG);
    CREATE_WS_CONN_CB_TYPE_BIC_STATIC(LWS_CALLBACK_CLIENT_WRITEABLE);
    CREATE_WS_CONN_CB_TYPE_BIC_STATIC(LWS_CALLBACK_SERVER_WRITEABLE);
    CREATE_WS_CONN_CB_TYPE_BIC_STATIC(LWS_CALLBACK_HTTP);
    CREATE_WS_CONN_CB_TYPE_BIC_STATIC(LWS_CALLBACK_HTTP_FILE_COMPLETION);
    CREATE_WS_CONN_CB_TYPE_BIC_STATIC(LWS_CALLBACK_FILTER_NETWORK_CONNECTION);
    CREATE_WS_CONN_CB_TYPE_BIC_STATIC(LWS_CALLBACK_FILTER_PROTOCOL_CONNECTION);
    CREATE_WS_CONN_CB_TYPE_BIC_STATIC(LWS_CALLBACK_OPENSSL_LOAD_EXTRA_CLIENT_VERIFY_CERTS);
    CREATE_WS_CONN_CB_TYPE_BIC_STATIC(LWS_CALLBACK_OPENSSL_LOAD_EXTRA_SERVER_VERIFY_CERTS);
    CREATE_WS_CONN_CB_TYPE_BIC_STATIC(LWS_CALLBACK_OPENSSL_PERFORM_CLIENT_CERT_VERIFICATION);
    CREATE_WS_CONN_CB_TYPE_BIC_STATIC(LWS_CALLBACK_CLIENT_APPEND_HANDSHAKE_HEADER);
    CREATE_WS_CONN_CB_TYPE_BIC_STATIC(LWS_CALLBACK_CONFIRM_EXTENSION_OKAY);
    CREATE_WS_CONN_CB_TYPE_BIC_STATIC(LWS_CALLBACK_CLIENT_CONFIRM_EXTENSION_SUPPORTED);
    CREATE_WS_CONN_CB_TYPE_BIC_STATIC(LWS_CALLBACK_PROTOCOL_INIT);
    CREATE_WS_CONN_CB_TYPE_BIC_STATIC(LWS_CALLBACK_PROTOCOL_DESTROY);
    CREATE_WS_CONN_CB_TYPE_BIC_STATIC(LWS_CALLBACK_ADD_POLL_FD);
    CREATE_WS_CONN_CB_TYPE_BIC_STATIC(LWS_CALLBACK_DEL_POLL_FD);
    CREATE_WS_CONN_CB_TYPE_BIC_STATIC(LWS_CALLBACK_CHANGE_MODE_POLL_FD);
  }

  // - timeout types -
  {
    const_locations.push_blanks(10);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 10);

#define CREATE_WS_CONN_TIMEOUT_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_WS_CONN_CB_TYPE_BIC_STATIC(NO_PENDING_TIMEOUT);
    CREATE_WS_CONN_CB_TYPE_BIC_STATIC(PENDING_TIMEOUT_AWAITING_PROXY_RESPONSE);
    CREATE_WS_CONN_CB_TYPE_BIC_STATIC(PENDING_TIMEOUT_AWAITING_CONNECT_RESPONSE);
    CREATE_WS_CONN_CB_TYPE_BIC_STATIC(PENDING_TIMEOUT_ESTABLISH_WITH_SERVER);
    CREATE_WS_CONN_CB_TYPE_BIC_STATIC(PENDING_TIMEOUT_AWAITING_SERVER_RESPONSE);
    CREATE_WS_CONN_CB_TYPE_BIC_STATIC(PENDING_TIMEOUT_AWAITING_PING);
    CREATE_WS_CONN_CB_TYPE_BIC_STATIC(PENDING_TIMEOUT_CLOSE_ACK);
    CREATE_WS_CONN_CB_TYPE_BIC_STATIC(PENDING_TIMEOUT_AWAITING_EXTENSION_CONNECT_RESPONSE);
    CREATE_WS_CONN_CB_TYPE_BIC_STATIC(PENDING_TIMEOUT_SENT_CLIENT_HANDSHAKE);
    CREATE_WS_CONN_CB_TYPE_BIC_STATIC(PENDING_TIMEOUT_SSL_ACCEPT);
  }
}/*}}}*/

void bic_ws_conn_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (ws_conn_s *)NULL;
}/*}}}*/

void bic_ws_conn_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  ws_conn_s *wscn_ptr = (ws_conn_s *)location_ptr->v_data_ptr;

  // - if websocket context exists -
  if (wscn_ptr != NULL)
  {
    wscn_ptr->clear(it);
    cfree(wscn_ptr);
  }
}/*}}}*/

bool bic_ws_conn_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_ws_conn_method_reason_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ws_conn_s *wscn_ptr = (ws_conn_s *)dst_location->v_data_ptr;
  long long int result = wscn_ptr->reason;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_ws_conn_method_received_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ws_conn_s *wscn_ptr = (ws_conn_s *)dst_location->v_data_ptr;

  // - create received data string -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(wscn_ptr->data_len,(char *)wscn_ptr->data_in);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_ws_conn_method_user_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ws_conn_s *wscn_ptr = (ws_conn_s *)dst_location->v_data_ptr;

  location_s *new_ref_location = it.get_new_reference(&wscn_ptr->user_data_ptr);

  BIC_SET_RESULT(new_ref_location);

  return true;
}/*}}}*/

bool bic_ws_conn_method_ctx_user_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ws_conn_s *wscn_ptr = (ws_conn_s *)dst_location->v_data_ptr;
  ws_context_s *wsc_ptr = wscn_ptr->wsc_ptr;

  location_s *new_ref_location = it.get_new_reference(&wsc_ptr->user_data_ptr);

  BIC_SET_RESULT(new_ref_location);

  return true;
}/*}}}*/

bool bic_ws_conn_method_protocol_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ws_conn_s *wscn_ptr = (ws_conn_s *)dst_location->v_data_ptr;

  // - retrieve websocket protocol -
  const libwebsocket_protocols *protocol = libwebsockets_get_protocol(wscn_ptr->ws_ptr);

  // - retrieve protocol name -
  string_s *string_ptr = (string_s *)it.get_new_string_ptr();
  string_ptr->set(strlen(protocol->name),protocol->name);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_ws_conn_method_callback_on_writable_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ws_conn_s *wscn_ptr = (ws_conn_s *)dst_location->v_data_ptr;
  ws_context_s *wsc_ptr = wscn_ptr->wsc_ptr;

  libwebsocket_callback_on_writable(wsc_ptr->context,wscn_ptr->ws_ptr);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_ws_conn_method_set_timeout_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int reason;
  long long int seconds;

  if (!it.retrieve_integer(src_0_location,reason) ||
      !it.retrieve_integer(src_1_location,seconds))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("set_timeout#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  // - retrieve websocket connection -
  ws_conn_s *wscn_ptr = (ws_conn_s *)dst_location->v_data_ptr;

  switch (reason)
  {
  case NO_PENDING_TIMEOUT:
  case PENDING_TIMEOUT_AWAITING_PROXY_RESPONSE:
  case PENDING_TIMEOUT_AWAITING_CONNECT_RESPONSE:
  case PENDING_TIMEOUT_ESTABLISH_WITH_SERVER:
  case PENDING_TIMEOUT_AWAITING_SERVER_RESPONSE:
  case PENDING_TIMEOUT_AWAITING_PING:
  case PENDING_TIMEOUT_CLOSE_ACK:
  case PENDING_TIMEOUT_AWAITING_EXTENSION_CONNECT_RESPONSE:
  case PENDING_TIMEOUT_SENT_CLIENT_HANDSHAKE:
  case PENDING_TIMEOUT_SSL_ACCEPT:
    break;

  // - ERROR -
  default:

    exception_s::throw_exception(it,module.error_base + c_error_WS_CONN_SET_TIMEOUT_UNKNOWN_REASON,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (seconds < 0)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_WS_CONN_SET_TIMEOUT_WRONG_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(seconds);

    return false;
  }

  // - set connection timeout -
  libwebsocket_set_timeout(wscn_ptr->ws_ptr,(pending_timeout)reason,seconds);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_ws_conn_method_write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("write#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  BIC_WS_CONN_WRITE(src_0_location,LWS_WRITE_TEXT);
}/*}}}*/

bool bic_ws_conn_method_write_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int write_type;

  if (!it.retrieve_integer(src_0_location,write_type) ||
      src_1_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("write#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  BIC_WS_CONN_WRITE(src_1_location,(libwebsocket_write_protocol)write_type);
}/*}}}*/

bool bic_ws_conn_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("WsConn"),"WsConn");
  );

  return true;
}/*}}}*/

bool bic_ws_conn_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("WsConn");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class WS_CLIENT -
built_in_class_s ws_client_class =
{/*{{{*/
  "WsClient",
  c_modifier_public | c_modifier_final,
  5, ws_client_methods,
  0, ws_client_variables,
  bic_ws_client_consts,
  bic_ws_client_init,
  bic_ws_client_clear,
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

built_in_method_s ws_client_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_ws_client_operator_binary_equal
  },
  {
    "connected#0",
    c_modifier_public | c_modifier_final,
    bic_ws_client_method_connected_0
  },
  {
    "callback_on_writable#0",
    c_modifier_public | c_modifier_final,
    bic_ws_client_method_callback_on_writable_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ws_client_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ws_client_method_print_0
  },
};/*}}}*/

built_in_variable_s ws_client_variables[] =
{/*{{{*/
};/*}}}*/

void bic_ws_client_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_ws_client_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (ws_client_s *)NULL;
}/*}}}*/

void bic_ws_client_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  ws_client_s *wscl_ptr = (ws_client_s *)location_ptr->v_data_ptr;

  // - if websocket context exists -
  if (wscl_ptr != NULL)
  {
    wscl_ptr->clear(it);
    cfree(wscl_ptr);
  }
}/*}}}*/

bool bic_ws_client_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_ws_client_method_connected_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ws_client_s *wscl_ptr = (ws_client_s *)dst_location->v_data_ptr;

  long long int result = wscl_ptr->connected;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_ws_client_method_callback_on_writable_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ws_client_s *wscl_ptr = (ws_client_s *)dst_location->v_data_ptr;
  ws_context_s *wsc_ptr = (ws_context_s*)((location_s *)wscl_ptr->wsc_location)->v_data_ptr;

  // - ERROR -
  if (!wscl_ptr->connected)
  {
    exception_s::throw_exception(it,module.error_base + c_error_WS_CLIENT_NOT_CONNECTED_TO_SERVER,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  libwebsocket_callback_on_writable(wsc_ptr->context,wscl_ptr->ws_ptr);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_ws_client_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("WsClient"),"WsClient");
  );

  return true;
}/*}}}*/

bool bic_ws_client_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("WsClient");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class WS_BASE64 -
built_in_class_s ws_base64_class =
{/*{{{*/
  "WsBase64",
  c_modifier_public | c_modifier_final,
  4, ws_base64_methods,
  0, ws_base64_variables,
  bic_ws_base64_consts,
  bic_ws_base64_init,
  bic_ws_base64_clear,
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

built_in_method_s ws_base64_methods[] =
{/*{{{*/
  {
    "encode#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ws_base64_method_encode_1
  },
  {
    "decode#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ws_base64_method_decode_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ws_base64_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ws_base64_method_print_0
  },
};/*}}}*/

built_in_variable_s ws_base64_variables[] =
{/*{{{*/
};/*}}}*/

void bic_ws_base64_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_ws_base64_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_ws_base64_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_ws_base64_method_encode_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_ws_base64,"encode#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *source_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create target buffer -
  int target_size = (((source_ptr->size - 1)/3 + 1) << 2) + 2;
  char *target_data = (char *)cmalloc(target_size*sizeof(char));

  // - encode string to base64 -
  int target_length = lws_b64_encode_string(source_ptr->data,source_ptr->size - 1,target_data,target_size);

  // - ERROR -
  if (target_length < 0)
  {
    cfree(target_data);

    exception_s::throw_exception(it,module.error_base + c_error_WS_BASE64_ENCODE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create target string -
  string_s *target_ptr = it.get_new_string_ptr();
  target_ptr->data = target_data;
  target_ptr->size = target_length + 1;

  BIC_SET_RESULT_STRING(target_ptr);

  return true;
}/*}}}*/

bool bic_ws_base64_method_decode_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/

  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_ws_base64,"decode#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *source_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create target buffer -
  int target_size = (((source_ptr->size - 1) >> 2) * 3) + 2;
  char *target_data = (char *)cmalloc(target_size*sizeof(char));

  // - initialize decode state -
  base64_decodestate state;
  base64_init_decodestate(&state);

  // - decode string from base64 -
  int target_length = base64_decode_block(source_ptr->data,source_ptr->size - 1,target_data,&state);

  // - ERROR -
  if (target_length < 0)
  {
    cfree(target_data);

    exception_s::throw_exception(it,module.error_base + c_error_WS_BASE64_DECODE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create target string -
  string_s *target_ptr = it.get_new_string_ptr();
  target_ptr->data = target_data;
  target_ptr->size = target_length + 1;

  BIC_SET_RESULT_STRING(target_ptr);

  return true;
}/*}}}*/

bool bic_ws_base64_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("WsBase64"),"WsBase64");
  );

  return true;
}/*}}}*/

bool bic_ws_base64_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("WsBase64");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

