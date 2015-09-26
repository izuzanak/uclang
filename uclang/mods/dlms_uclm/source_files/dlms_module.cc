
@begin
include "dlms_module.h"
@end

// - DLMS indexes of built in classes -
unsigned c_bi_class_dlms_server = c_idx_not_exist;
unsigned c_bi_class_dlms_object = c_idx_not_exist;

// - DLMS module -
built_in_module_s module =
{/*{{{*/
  2,                    // Class count
  dlms_classes,         // Classes

  0,                    // Error base index
  11,                   // Error count
  dlms_error_strings,   // Error strings

  dlms_initialize,      // Initialize function
  dlms_print_exception, // Print exceptions function
};/*}}}*/

// - DLMS classes -
built_in_class_s *dlms_classes[] =
{/*{{{*/
  &dlms_server_class,
  &dlms_object_class,
};/*}}}*/

// - DLMS error strings -
const char *dlms_error_strings[] =
{/*{{{*/
  "error_DLMS_SERVER_INVALID_MANUFACTURER_ID",
  "error_DLMS_SERVER_INVALID_SERIAL_NUMBER",
  "error_DLMS_SERVER_INVALID_PORT_VALUE",
  "error_DLMS_SERVER_INVALID_OBJECT_ARRAY_SIZE",
  "error_DLMS_SERVER_INVALID_OBJECT_ARRAY_VALUE_TYPE",
  "error_DLMS_SERVER_CREATE_ERROR",
  "error_DLMS_SERVER_OBJECT_CODE_NOT_FOUND",
  "error_DLMS_SERVER_OBJECT_INDEX_EXCEEDS_RANGE",
  "error_DLMS_OBJECT_UNSUPPORTED_OBJECT_TYPE",
  "error_DLMS_OBJECT_UNSUPPORTED_DATA_TYPE",
  "error_DLMS_OBJECT_WRITE_WRONG_TYPE",
};/*}}}*/

// - DLMS initialize -
bool dlms_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize dlms_server class identifier -
  c_bi_class_dlms_server = class_base_idx++;

  // - initialize dlms_object class identifier -
  c_bi_class_dlms_object = class_base_idx++;

  return true;
}/*}}}*/

// - DLMS print exception -
bool dlms_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_DLMS_SERVER_INVALID_MANUFACTURER_ID:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid meter manufacturer id\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_DLMS_SERVER_INVALID_SERIAL_NUMBER:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid meter serial number\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_DLMS_SERVER_INVALID_PORT_VALUE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid port %" HOST_LL_FORMAT "d for DLMS server\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_DLMS_SERVER_INVALID_OBJECT_ARRAY_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nLength of object array is not divisible by two\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_DLMS_SERVER_INVALID_OBJECT_ARRAY_VALUE_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid type of object array value\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_DLMS_SERVER_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError received while creating DLMS server\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_DLMS_SERVER_OBJECT_CODE_NOT_FOUND:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nDLMS server object code \"%s\" was not found\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_DLMS_SERVER_OBJECT_INDEX_EXCEEDS_RANGE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nIndex %" HOST_LL_FORMAT "d exceeds range of DLMS server objects\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_DLMS_OBJECT_UNSUPPORTED_OBJECT_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUnsupported type %" HOST_LL_FORMAT "d of DLMS object\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_DLMS_OBJECT_UNSUPPORTED_DATA_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUnsupported data type %" HOST_LL_FORMAT "d of DLMS object\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_DLMS_OBJECT_WRITE_WRONG_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nDLMS object write error, expected %s\n",it.class_symbol_names[it.class_records[exception.params[0]].name_idx].data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class DLMS_SERVER -
built_in_class_s dlms_server_class =
{/*{{{*/
  "DlmsServer",
  c_modifier_public | c_modifier_final,
  11, dlms_server_methods,
  0, dlms_server_variables,
  bic_dlms_server_consts,
  bic_dlms_server_init,
  bic_dlms_server_clear,
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

built_in_method_s dlms_server_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_dlms_server_operator_binary_equal
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_dlms_server_operator_binary_le_br_re_br
  },
  {
    "DlmsServer#4",
    c_modifier_public | c_modifier_final,
    bic_dlms_server_method_DlmsServer_4
  },
  {
    "get_fds#0",
    c_modifier_public | c_modifier_final,
    bic_dlms_server_method_get_fds_0
  },
  {
    "process#0",
    c_modifier_public | c_modifier_final,
    bic_dlms_server_method_process_0
  },
  {
    "item#1",
    c_modifier_public | c_modifier_final,
    bic_dlms_server_method_item_1
  },
  {
    "first_idx#0",
    c_modifier_public | c_modifier_final,
    bic_dlms_server_method_first_idx_0
  },
  {
    "next_idx#1",
    c_modifier_public | c_modifier_final,
    bic_dlms_server_method_next_idx_1
  },
  {
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_dlms_server_method_length_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_dlms_server_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_dlms_server_method_print_0
  },
};/*}}}*/

built_in_variable_s dlms_server_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_DLMS_SERVER_CHECK_INDEX() \
/*{{{*/\
  CGXDLMSObjectCollection &items = ((CGXDLMSBase *)dst_location->v_data_ptr)->m_Items;\
\
  /* - ERROR - */\
  if (index < 0 || index >= items.size())\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_DLMS_SERVER_OBJECT_INDEX_EXCEEDS_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(index);\
\
    return false;\
  }\
/*}}}*/

#define BIC_DLMS_SERVER_ITEM(NAME) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
  long long int index;\
\
  if (!it.retrieve_integer(src_0_location,index))\
  {\
    /* - ERROR - */\
    if (src_0_location->v_type != c_bi_class_string)\
    {\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
\
      return false;\
    }\
\
    /* - retrieve dlms server items and code string - */\
    CGXDLMSObjectCollection &items = ((CGXDLMSBase *)dst_location->v_data_ptr)->m_Items;\
    string_s *code_ptr = (string_s *)src_0_location->v_data_ptr;\
\
    string obj_log_name;\
    CGXDLMSObjectCollection::iterator obj_it;\
\
    for (obj_it = items.begin();obj_it != items.end();++obj_it)\
    {\
      (*obj_it)->GetLogicalName(obj_log_name);\
      if (code_ptr->compare_char_ptr(obj_log_name.length(),obj_log_name.data()))\
      {\
        break;\
      }\
    }\
\
    /* - ERROR - */\
    if (obj_it == items.end())\
    {\
      exception_s::throw_exception(it,module.error_base + c_error_DLMS_SERVER_OBJECT_CODE_NOT_FOUND,operands[c_source_pos_idx],src_0_location);\
      return false;\
    }\
\
    index = obj_it - items.begin();\
  }\
  else {\
    BIC_DLMS_SERVER_CHECK_INDEX();\
  }\
\
  /* - create new dlms object object - */\
  dlms_object_s *dlmso_ptr = (dlms_object_s *)cmalloc(sizeof(dlms_object_s));\
  dlmso_ptr->init();\
\
  dst_location->v_reference_cnt.atomic_inc();\
  dlmso_ptr->dlmss_ptr = dst_location;\
  dlmso_ptr->index = index;\
\
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_dlms_object,dlmso_ptr);\
  BIC_SET_RESULT(new_location);\
\
  return true;\
}/*}}}*/

void bic_dlms_server_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_dlms_server_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)NULL;
}/*}}}*/

void bic_dlms_server_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  CGXDLMSBase *dlmss_ptr = (CGXDLMSBase *)location_ptr->v_data_ptr;

  if (dlmss_ptr != NULL)
  {
    delete dlmss_ptr;
  }
}/*}}}*/

bool bic_dlms_server_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_dlms_server_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_DLMS_SERVER_ITEM("operator_binary_le_br_re_br#1");
}/*}}}*/

bool bic_dlms_server_method_DlmsServer_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);
  location_s *src_3_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_3_op_idx]);

  long long int port;

  if (src_0_location->v_type != c_bi_class_string ||
      src_1_location->v_type != c_bi_class_string ||
      src_2_location->v_type != c_bi_class_array ||
      !it.retrieve_integer(src_3_location,port))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("DlmsServer#4");
    new_exception->params.push(4);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);
    new_exception->params.push(src_3_location->v_type);

    return false;
  }

  string_s *man_id_str = (string_s *)src_0_location->v_data_ptr;
  string_s *serial_str = (string_s *)src_1_location->v_data_ptr;
  pointer_array_s *objs_ptr = (pointer_array_s *)src_2_location->v_data_ptr;

  // - ERROR -
  if (man_id_str->size != 4)
  {
    exception_s::throw_exception(it,module.error_base + c_error_DLMS_SERVER_INVALID_MANUFACTURER_ID,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (serial_str->size > 14)
  {
    exception_s::throw_exception(it,module.error_base + c_error_DLMS_SERVER_INVALID_SERIAL_NUMBER,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (port < 1 || port > 65535)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_DLMS_SERVER_INVALID_PORT_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(port);

    return false;
  }

  // - ERROR -
  if (objs_ptr->used & 0x01)
  {
    exception_s::throw_exception(it,module.error_base + c_error_DLMS_SERVER_INVALID_OBJECT_ARRAY_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create dlms server object -
  CGXDLMSBase *dlmss_ptr = new CGXDLMSBase(true,GXDLMS_INTERFACETYPE_GENERAL);

  // - ERROR -
  if (dlmss_ptr->PrepareInit(man_id_str->data,serial_str->data,port) != ERROR_CODES_OK)
  {
    delete dlmss_ptr;

    exception_s::throw_exception(it,module.error_base + c_error_DLMS_SERVER_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - add objects to server -
  if (objs_ptr->used != 0)
  {
    CGXDLMSObjectCollection &items = dlmss_ptr->m_Items;
    CGXDLMSRegister *reg_ptr;

    pointer *p_ptr = objs_ptr->data;
    pointer *p_ptr_end = p_ptr + objs_ptr->used;
    do {
      location_s *code_loc = it.get_location_value(p_ptr[0]);
      location_s *type_loc = it.get_location_value(p_ptr[1]);

      // - ERROR -
      if (code_loc->v_type != c_bi_class_string)
      {
        delete dlmss_ptr;

        exception_s::throw_exception(it,module.error_base + c_error_DLMS_SERVER_INVALID_OBJECT_ARRAY_VALUE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      string_s *obj_code = (string_s *)code_loc->v_data_ptr;
      long long int data_type;

      // - ERROR -
      if (!it.retrieve_integer(type_loc,data_type))
      {
        delete dlmss_ptr;

        exception_s::throw_exception(it,module.error_base + c_error_DLMS_SERVER_INVALID_OBJECT_ARRAY_VALUE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      switch (data_type)
      {
	case DLMS_DATA_TYPE_INT32:
          reg_ptr = new CGXDLMSRegister(obj_code->data,0,0,(int)0);
          break;
        case DLMS_DATA_TYPE_UINT32:
          reg_ptr = new CGXDLMSRegister(obj_code->data,0,0,(unsigned)0);
          break;
        case DLMS_DATA_TYPE_INT8:
          reg_ptr = new CGXDLMSRegister(obj_code->data,0,0,(char)0);
          break;
        case DLMS_DATA_TYPE_INT16:
          reg_ptr = new CGXDLMSRegister(obj_code->data,0,0,(short)0);
          break;
        case DLMS_DATA_TYPE_UINT8:
          reg_ptr = new CGXDLMSRegister(obj_code->data,0,0,(unsigned char)0);
          break;
        case DLMS_DATA_TYPE_UINT16:
          reg_ptr = new CGXDLMSRegister(obj_code->data,0,0,(unsigned short)0);
          break;
        case DLMS_DATA_TYPE_INT64:
          reg_ptr = new CGXDLMSRegister(obj_code->data,0,0,(long long int)0);
          break;
        case DLMS_DATA_TYPE_UINT64:
          reg_ptr = new CGXDLMSRegister(obj_code->data,0,0,(unsigned long long int)0);
          break;
	case DLMS_DATA_TYPE_FLOAT32:
          reg_ptr = new CGXDLMSRegister(obj_code->data,0,0,(float)0);
          break;
	case DLMS_DATA_TYPE_FLOAT64:
          reg_ptr = new CGXDLMSRegister(obj_code->data,0,0,(double)0.0);
          break;
        case DLMS_DATA_TYPE_STRING:
          reg_ptr = new CGXDLMSRegister(obj_code->data,0,0,"");
          break;
	case DLMS_DATA_TYPE_DATE:
	case DLMS_DATA_TYPE_TIME:

        // - ERROR -
        default:
          {
            delete dlmss_ptr;

            exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_DLMS_OBJECT_UNSUPPORTED_DATA_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
            new_exception->params.push(data_type);

            return false;
          }
      }

      // - add object to server -
      reg_ptr->SetAccess(2,ACCESSMODE_READ);
      items.push_back(reg_ptr);

    } while((p_ptr += 2) < p_ptr_end);
  }

  // - ERROR -
  if (dlmss_ptr->Init() != ERROR_CODES_OK)
  {
    delete dlmss_ptr;

    exception_s::throw_exception(it,module.error_base + c_error_DLMS_SERVER_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set destination data pointer -
  dst_location->v_data_ptr = (basic_64b)dlmss_ptr;

  return true;
}/*}}}*/

bool bic_dlms_server_method_get_fds_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  CGXDLMSBase *dlmss_ptr = (CGXDLMSBase *)dst_location->v_data_ptr;
  CGXNet &media = dlmss_ptr->m_Media;

  // - create result array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  if (media.m_ServerSocket)
  {
    BIC_CREATE_NEW_LOCATION(fd_location,c_bi_class_integer,media.m_ServerSocket);
    array_ptr->push(fd_location);

    BIC_CREATE_NEW_LOCATION(flags_location,c_bi_class_integer,POLLIN | POLLPRI);
    array_ptr->push(flags_location);
  }

  if (media.m_Socket)
  {
    BIC_CREATE_NEW_LOCATION(fd_location,c_bi_class_integer,media.m_Socket);
    array_ptr->push(fd_location);

    BIC_CREATE_NEW_LOCATION(flags_location,c_bi_class_integer,POLLIN | POLLPRI);
    array_ptr->push(flags_location);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_dlms_server_method_process_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  CGXDLMSBase *dlmss_ptr = (CGXDLMSBase *)dst_location->v_data_ptr;
  dlmss_ptr->m_Media.ListenerStep();

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_dlms_server_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_DLMS_SERVER_ITEM("item#1");
}/*}}}*/

bool bic_dlms_server_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  CGXDLMSObjectCollection &items = ((CGXDLMSBase *)dst_location->v_data_ptr)->m_Items;

  if (items.size() > 0)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,0);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_dlms_server_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int index;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,index))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("next_idx#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  BIC_DLMS_SERVER_CHECK_INDEX();

  if (++index < items.size())
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,index);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_dlms_server_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  CGXDLMSObjectCollection &items = ((CGXDLMSBase *)dst_location->v_data_ptr)->m_Items;

  long long int result = items.size();

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_dlms_server_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("DlmsServer"),"DlmsServer");
  );

  return true;
}/*}}}*/

bool bic_dlms_server_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("DlmsServer");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class DLMS_OBJECT -
built_in_class_s dlms_object_class =
{/*{{{*/
  "DlmsObject",
  c_modifier_public | c_modifier_final,
  6, dlms_object_methods,
  48 + 24, dlms_object_variables,
  bic_dlms_object_consts,
  bic_dlms_object_init,
  bic_dlms_object_clear,
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

built_in_method_s dlms_object_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_dlms_object_operator_binary_equal
  },
  {
    "code#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_dlms_object_method_code_0
  },
  {
    "value#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_dlms_object_method_value_0
  },
  {
    "value#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_dlms_object_method_value_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_dlms_object_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_dlms_object_method_print_0
  },
};/*}}}*/

built_in_variable_s dlms_object_variables[] =
{/*{{{*/

  // - dlms object types -
  { "OBJECT_TYPE_ALL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_NONE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_DATA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_REGISTER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_EXTENDED_REGISTER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_DEMAND_REGISTER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_REGISTER_ACTIVATION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_PROFILE_GENERIC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_CLOCK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_SCRIPT_TABLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_SCHEDULE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_SPECIAL_DAYS_TABLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_ASSOCIATION_SHORT_NAME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_ASSOCIATION_LOGICAL_NAME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_SAP_ASSIGNMENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_IMAGE_TRANSFER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_IEC_LOCAL_PORT_SETUP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_ACTIVITY_CALENDAR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_REGISTER_MONITOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_ACTION_SCHEDULE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_IEC_HDLC_SETUP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_IEC_TWISTED_PAIR_SETUP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_MBUS_SLAVE_PORT_SETUP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_UTILITY_TABLES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_MODEM_CONFIGURATION", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_AUTO_ANSWER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_AUTO_CONNECT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_TCP_UDP_SETUP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_IP4_SETUP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_MAC_ADDRESS_SETUP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_PPP_SETUP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_GPRS_SETUP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_SMTP_SETUP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_REGISTER_TABLE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_STATUS_MAPPING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_SECURITY_SETUP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_DISCONNECT_CONTROL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_LIMITER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_MBUS_CLIENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_PUSH_SETUP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_MESSAGE_HANDLER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_PARAMETER_MONITOR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_WIRELESS_MODE_Q_CHANNEL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_MBUS_MASTER_PORT_SETUP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_EVENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_REMOTE_DIGITAL_CONTROL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_REMOTE_ANALOGUE_CONTROL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OBJECT_TYPE_TUNNEL", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - dlms data types -
  { "DATA_TYPE_NONE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "DATA_TYPE_BOOLEAN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "DATA_TYPE_BIT_STRING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "DATA_TYPE_INT32", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "DATA_TYPE_UINT32", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "DATA_TYPE_OCTET_STRING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "DATA_TYPE_STRING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "DATA_TYPE_BINARY_CODED_DESIMAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "DATA_TYPE_STRING_UTF8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "DATA_TYPE_INT8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "DATA_TYPE_INT16", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "DATA_TYPE_UINT8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "DATA_TYPE_UINT16", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "DATA_TYPE_INT64", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "DATA_TYPE_UINT64", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "DATA_TYPE_ENUM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "DATA_TYPE_FLOAT32", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "DATA_TYPE_FLOAT64", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "DATA_TYPE_DATETIME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "DATA_TYPE_DATE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "DATA_TYPE_TIME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "DATA_TYPE_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "DATA_TYPE_STRUCTURE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "DATA_TYPE_COMPACT_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
};/*}}}*/

void bic_dlms_object_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert dlms object types constants -
  {
    const_locations.push_blanks(48);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 48);

#define CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (basic_64b)VALUE;\
  cv_ptr++;

    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_ALL);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_NONE);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_DATA);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_REGISTER);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_EXTENDED_REGISTER);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_DEMAND_REGISTER);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_REGISTER_ACTIVATION);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_PROFILE_GENERIC);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_CLOCK);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_SCRIPT_TABLE);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_SCHEDULE);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_SPECIAL_DAYS_TABLE);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_ASSOCIATION_SHORT_NAME);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_ASSOCIATION_LOGICAL_NAME);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_SAP_ASSIGNMENT);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_IMAGE_TRANSFER);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_IEC_LOCAL_PORT_SETUP);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_ACTIVITY_CALENDAR);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_REGISTER_MONITOR);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_ACTION_SCHEDULE);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_IEC_HDLC_SETUP);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_IEC_TWISTED_PAIR_SETUP);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_MBUS_SLAVE_PORT_SETUP);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_UTILITY_TABLES);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_MODEM_CONFIGURATION);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_AUTO_ANSWER);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_AUTO_CONNECT);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_TCP_UDP_SETUP);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_IP4_SETUP);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_MAC_ADDRESS_SETUP);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_PPP_SETUP);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_GPRS_SETUP);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_SMTP_SETUP);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_REGISTER_TABLE);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_STATUS_MAPPING);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_SECURITY_SETUP);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_DISCONNECT_CONTROL);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_LIMITER);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_MBUS_CLIENT);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_PUSH_SETUP);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_MESSAGE_HANDLER);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_PARAMETER_MONITOR);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_WIRELESS_MODE_Q_CHANNEL);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_MBUS_MASTER_PORT_SETUP);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_EVENT);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_REMOTE_DIGITAL_CONTROL);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_REMOTE_ANALOGUE_CONTROL);
    CREATE_DLMS_OBJECT_TYPE_BIC_STATIC(OBJECT_TYPE_TUNNEL);
  }

  // - insert dlms data types constants -
  {
    const_locations.push_blanks(24);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 24);

#define CREATE_DLMS_DATA_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (basic_64b)VALUE;\
  cv_ptr++;

    CREATE_DLMS_DATA_TYPE_BIC_STATIC(DLMS_DATA_TYPE_NONE);
    CREATE_DLMS_DATA_TYPE_BIC_STATIC(DLMS_DATA_TYPE_BOOLEAN);
    CREATE_DLMS_DATA_TYPE_BIC_STATIC(DLMS_DATA_TYPE_BIT_STRING);
    CREATE_DLMS_DATA_TYPE_BIC_STATIC(DLMS_DATA_TYPE_INT32);
    CREATE_DLMS_DATA_TYPE_BIC_STATIC(DLMS_DATA_TYPE_UINT32);
    CREATE_DLMS_DATA_TYPE_BIC_STATIC(DLMS_DATA_TYPE_OCTET_STRING);
    CREATE_DLMS_DATA_TYPE_BIC_STATIC(DLMS_DATA_TYPE_STRING);
    CREATE_DLMS_DATA_TYPE_BIC_STATIC(DLMS_DATA_TYPE_BINARY_CODED_DESIMAL);
    CREATE_DLMS_DATA_TYPE_BIC_STATIC(DLMS_DATA_TYPE_STRING_UTF8);
    CREATE_DLMS_DATA_TYPE_BIC_STATIC(DLMS_DATA_TYPE_INT8);
    CREATE_DLMS_DATA_TYPE_BIC_STATIC(DLMS_DATA_TYPE_INT16);
    CREATE_DLMS_DATA_TYPE_BIC_STATIC(DLMS_DATA_TYPE_UINT8);
    CREATE_DLMS_DATA_TYPE_BIC_STATIC(DLMS_DATA_TYPE_UINT16);
    CREATE_DLMS_DATA_TYPE_BIC_STATIC(DLMS_DATA_TYPE_INT64);
    CREATE_DLMS_DATA_TYPE_BIC_STATIC(DLMS_DATA_TYPE_UINT64);
    CREATE_DLMS_DATA_TYPE_BIC_STATIC(DLMS_DATA_TYPE_ENUM);
    CREATE_DLMS_DATA_TYPE_BIC_STATIC(DLMS_DATA_TYPE_FLOAT32);
    CREATE_DLMS_DATA_TYPE_BIC_STATIC(DLMS_DATA_TYPE_FLOAT64);
    CREATE_DLMS_DATA_TYPE_BIC_STATIC(DLMS_DATA_TYPE_DATETIME);
    CREATE_DLMS_DATA_TYPE_BIC_STATIC(DLMS_DATA_TYPE_DATE);
    CREATE_DLMS_DATA_TYPE_BIC_STATIC(DLMS_DATA_TYPE_TIME);
    CREATE_DLMS_DATA_TYPE_BIC_STATIC(DLMS_DATA_TYPE_ARRAY);
    CREATE_DLMS_DATA_TYPE_BIC_STATIC(DLMS_DATA_TYPE_STRUCTURE);
    CREATE_DLMS_DATA_TYPE_BIC_STATIC(DLMS_DATA_TYPE_COMPACT_ARRAY);
  }
}/*}}}*/

void bic_dlms_object_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)NULL;
}/*}}}*/

void bic_dlms_object_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  dlms_object_s *dlmso_ptr = (dlms_object_s *)location_ptr->v_data_ptr;

  if (dlmso_ptr != NULL)
  {
    dlmso_ptr->clear(it);
    cfree(dlmso_ptr);
  }
}/*}}}*/

bool bic_dlms_object_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_dlms_object_method_code_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  dlms_object_s *dlmso_ptr = (dlms_object_s *)dst_location->v_data_ptr;
  CGXDLMSObject *obj_ptr = ((CGXDLMSBase *)dlmso_ptr->dlmss_ptr->v_data_ptr)->m_Items[dlmso_ptr->index];

  // - retrieve object code -
  string obj_code;
  obj_ptr->GetLogicalName(obj_code);

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(obj_code.length(),obj_code.data());

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_dlms_object_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  dlms_object_s *dlmso_ptr = (dlms_object_s *)dst_location->v_data_ptr;
  CGXDLMSObject *obj_ptr = ((CGXDLMSBase *)dlmso_ptr->dlmss_ptr->v_data_ptr)->m_Items[dlmso_ptr->index];

  switch (obj_ptr->GetObjectType())
  {
    case OBJECT_TYPE_REGISTER:
      {
        CGXDLMSVariant variant = ((CGXDLMSRegister *)obj_ptr)->GetValue();
        
        switch (variant.vt)
        {
          case DLMS_DATA_TYPE_INT32:
          case DLMS_DATA_TYPE_UINT32:
          case DLMS_DATA_TYPE_INT8:
          case DLMS_DATA_TYPE_INT16:
          case DLMS_DATA_TYPE_UINT8:
          case DLMS_DATA_TYPE_UINT16:
          case DLMS_DATA_TYPE_INT64:
          case DLMS_DATA_TYPE_UINT64:
            {
              long long int result;

              switch (variant.vt)
              {
                case DLMS_DATA_TYPE_INT32: result = variant.intVal; break;
                case DLMS_DATA_TYPE_UINT32: result = variant.uintVal; break;
                case DLMS_DATA_TYPE_INT8: result = variant.cVal; break;
                case DLMS_DATA_TYPE_INT16: result = variant.iVal; break;
                case DLMS_DATA_TYPE_UINT8: result = variant.bVal; break;
                case DLMS_DATA_TYPE_UINT16: result = variant.uiVal; break;
                case DLMS_DATA_TYPE_INT64: result = variant.llVal; break;
                case DLMS_DATA_TYPE_UINT64: result = variant.ullVal; break;
                default:
                  cassert(0);
              }

              BIC_SIMPLE_SET_RES(c_bi_class_integer,result);
            }
            break;

          case DLMS_DATA_TYPE_FLOAT32:
          case DLMS_DATA_TYPE_FLOAT64:
            {
              double result;

              switch (variant.vt)
              {
                case DLMS_DATA_TYPE_FLOAT32: result = variant.fltVal; break;
                case DLMS_DATA_TYPE_FLOAT64: result = variant.dblVal; break;
                default:
                  cassert(0);
              }

              basic_64b &v_data_ptr = *((basic_64b *)&result);
              BIC_SIMPLE_SET_RES(c_bi_class_float,v_data_ptr);
            }
            break;

          case DLMS_DATA_TYPE_STRING:
            {
              string_s *string_ptr = it.get_new_string_ptr();
              string_ptr->set(variant.strVal.length(),variant.strVal.data());
              BIC_SET_RESULT_STRING(string_ptr);
            }
            break;

          // - ERROR -
          default:
          {
            exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_DLMS_OBJECT_UNSUPPORTED_DATA_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
            new_exception->params.push(variant.vt);

            return false;
          }
        }
      }
      break;

    // - ERROR -
    default:
    {
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_DLMS_OBJECT_UNSUPPORTED_OBJECT_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(obj_ptr->GetObjectType());

      return false;
    }
  }

  return true;
}/*}}}*/

bool bic_dlms_object_method_value_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  dlms_object_s *dlmso_ptr = (dlms_object_s *)dst_location->v_data_ptr;
  CGXDLMSObject *obj_ptr = ((CGXDLMSBase *)dlmso_ptr->dlmss_ptr->v_data_ptr)->m_Items[dlmso_ptr->index];

  switch (obj_ptr->GetObjectType())
  {
    case OBJECT_TYPE_REGISTER:
      {
        CGXDLMSRegister *reg_ptr = (CGXDLMSRegister *)obj_ptr;
        CGXDLMSVariant variant = reg_ptr->GetValue();
        
        switch (variant.vt)
        {
          case DLMS_DATA_TYPE_INT32:
          case DLMS_DATA_TYPE_UINT32:
          case DLMS_DATA_TYPE_INT8:
          case DLMS_DATA_TYPE_INT16:
          case DLMS_DATA_TYPE_UINT8:
          case DLMS_DATA_TYPE_UINT16:
          case DLMS_DATA_TYPE_INT64:
          case DLMS_DATA_TYPE_UINT64:
            {
              long long int value;

              // - ERROR -
              if (!it.retrieve_integer(src_0_location,value))
              {
                exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_DLMS_OBJECT_WRITE_WRONG_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
                new_exception->params.push(c_bi_class_integer);

                return false;
              }

              switch (variant.vt)
              {
                case DLMS_DATA_TYPE_INT32: variant.intVal = value; break;
                case DLMS_DATA_TYPE_UINT32: variant.uintVal = value; break;
                case DLMS_DATA_TYPE_INT8: variant.cVal = value; break;
                case DLMS_DATA_TYPE_INT16: variant.iVal = value; break;
                case DLMS_DATA_TYPE_UINT8: variant.bVal = value; break;
                case DLMS_DATA_TYPE_UINT16: variant.uiVal = value; break;
                case DLMS_DATA_TYPE_INT64: variant.llVal = value; break;
                case DLMS_DATA_TYPE_UINT64: variant.ullVal = value; break;
                default:
                  cassert(0);
              }

              reg_ptr->SetValue(variant);
            }
            break;

          case DLMS_DATA_TYPE_FLOAT32:
          case DLMS_DATA_TYPE_FLOAT64:
            {
              double value;

              // - ERROR -
              if (!it.retrieve_float(src_0_location,value))
              {
                exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_DLMS_OBJECT_WRITE_WRONG_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
                new_exception->params.push(c_bi_class_float);

                return false;
              }

              switch (variant.vt)
              {
                case DLMS_DATA_TYPE_FLOAT32: variant.fltVal = value; break;
                case DLMS_DATA_TYPE_FLOAT64: variant.dblVal = value; break;
                default:
                  cassert(0);
              }

              reg_ptr->SetValue(variant);
            }
            break;

          case DLMS_DATA_TYPE_STRING:
            {
              // - ERROR -
              if (src_0_location->v_type != c_bi_class_string)
              {
                exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_DLMS_OBJECT_WRITE_WRONG_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
                new_exception->params.push(c_bi_class_string);

                return false;
              }

              string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

              variant.strVal.assign(string_ptr->data,string_ptr->size - 1);
              reg_ptr->SetValue(variant);
            }
            break;

          // - ERROR -
          default:
          {
            exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_DLMS_OBJECT_UNSUPPORTED_DATA_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
            new_exception->params.push(variant.vt);

            return false;
          }
        }
      }
      break;

    // - ERROR -
    default:
    {
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_DLMS_OBJECT_UNSUPPORTED_OBJECT_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(obj_ptr->GetObjectType());

      return false;
    }
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_dlms_object_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("DlmsObject"),"DlmsObject");
  );

  return true;
}/*}}}*/

bool bic_dlms_object_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("DlmsObject");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

