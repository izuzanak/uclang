
@begin
include "uccan_module.h"
@end

// - UCCAN indexes of built in classes -
unsigned c_bi_class_can_obj_dict = c_idx_not_exist;
unsigned c_bi_class_can_object = c_idx_not_exist;

// - UCCAN module -
built_in_module_s module =
{/*{{{*/
  2,                     // Class count
  uccan_classes,         // Classes

  0,                     // Error base index
  9,                     // Error count
  uccan_error_strings,   // Error strings

  uccan_initialize,      // Initialize function
  uccan_print_exception, // Print exceptions function
};/*}}}*/

// - UCCAN classes -
built_in_class_s *uccan_classes[] =
{/*{{{*/
  &can_obj_dict_class,
  &can_object_class,
};/*}}}*/

// - UCCAN error strings -
const char *uccan_error_strings[] =
{/*{{{*/
  "error_CAN_OBJECT_DICT_CREATE_ERROR",
  "error_CAN_OBJECT_DICT_OPEN_ERROR",
  "error_CAN_OBJECT_DICT_INDEX_NOT_PRESENT",
  "error_CAN_OBJECT_UNSUPPORTED_VARIABLE_TYPE",
  "error_CAN_OBJECT_UNSUPPORTED_OBJECT_TYPE",
  "error_CAN_OBJECT_READ_ERROR",
  "error_CAN_OBJECT_WRITE_ERROR",
  "error_CAN_OBJECT_WRITE_VARIABLE_NOT_WRITABLE",
  "error_CAN_OBJECT_WRITE_WRONG_VARIABLE_TYPE",
};/*}}}*/

// - UCCAN initialize -
bool uccan_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize can_obj_dict class identifier -
  c_bi_class_can_obj_dict = class_base_idx++;

  // - initialize can_object class identifier -
  c_bi_class_can_object = class_base_idx++;

  return true;
}/*}}}*/

// - UCCAN print exception -
bool uccan_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_CAN_OBJECT_DICT_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating CAN object dictionary \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CAN_OBJECT_DICT_OPEN_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while openning CAN object dictionary \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CAN_OBJECT_DICT_INDEX_NOT_PRESENT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCAN object dictionary does not contain index %" HOST_LL_FORMAT "d:%" HOST_LL_FORMAT "d\n",exception.params[0],exception.params[1]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CAN_OBJECT_UNSUPPORTED_VARIABLE_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUnsupported CANopen variable type %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CAN_OBJECT_UNSUPPORTED_OBJECT_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUnsupported CANopen object type %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CAN_OBJECT_READ_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCANopen variable read error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CAN_OBJECT_WRITE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCANopen variable write error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CAN_OBJECT_WRITE_VARIABLE_NOT_WRITABLE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCANopen variable is not writable\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CAN_OBJECT_WRITE_WRONG_VARIABLE_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCANopen variable write error, expected %s\n",it.class_symbol_names[it.class_records[exception.params[0]].name_idx].data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class CAN_OBJ_DICT -
built_in_class_s can_obj_dict_class =
{/*{{{*/
  "CanObjDict",
  c_modifier_public | c_modifier_final,
  8, can_obj_dict_methods,
  0, can_obj_dict_variables,
  bic_can_obj_dict_consts,
  bic_can_obj_dict_init,
  bic_can_obj_dict_clear,
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

built_in_method_s can_obj_dict_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_can_obj_dict_operator_binary_equal
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_can_obj_dict_operator_binary_le_br_re_br
  },
  {
    "CanObjDict#1",
    c_modifier_public | c_modifier_final,
    bic_can_obj_dict_method_CanObjDict_1
  },
  {
    "CanObjDict#4",
    c_modifier_public | c_modifier_final,
    bic_can_obj_dict_method_CanObjDict_4
  },
  {
    "FindObj#1",
    c_modifier_public | c_modifier_final,
    bic_can_obj_dict_method_FindObj_1
  },
  {
    "FindObj#2",
    c_modifier_public | c_modifier_final,
    bic_can_obj_dict_method_FindObj_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_can_obj_dict_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_can_obj_dict_method_print_0
  },
};/*}}}*/

built_in_variable_s can_obj_dict_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_CAN_OBJ_DICT_METHOD_FINDOBJ() \
{/*{{{*/\
\
  /* - create new can object - */\
  can_object_s *co_ptr = (can_object_s *)cmalloc(sizeof(can_object_s));\
\
  /* - find object in dictionary - */\
  U32 result = cod_ptr->dict_ptr->FindObj(mux,co_ptr->handle);\
\
  /* - ERROR - */\
  if (result != SDO_ABORT_OK)\
  {\
    cfree(co_ptr);\
\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_CAN_OBJECT_DICT_INDEX_NOT_PRESENT,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(mux.idx);\
    new_exception->params.push(mux.sidx);\
\
    return false;\
  }\
\
  dst_location->v_reference_cnt.atomic_inc();\
  co_ptr->dict_loc = dst_location;\
\
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_can_object,co_ptr);\
  BIC_SET_RESULT(new_location);\
}/*}}}*/

void bic_can_obj_dict_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_can_obj_dict_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (can_obj_dict_s *)nullptr;
}/*}}}*/

void bic_can_obj_dict_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  can_obj_dict_s *cod_ptr = (can_obj_dict_s *)location_ptr->v_data_ptr;

  if (cod_ptr != nullptr)
  {
    cod_ptr->clear(it);
    cfree(cod_ptr);
  }
}/*}}}*/

bool bic_can_obj_dict_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_can_obj_dict_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int index;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,index))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_le_br_re_br#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  can_obj_dict_s *cod_ptr = (can_obj_dict_s *)dst_location->v_data_ptr;
  ObjDict::Mux mux((U32)index);

  BIC_CAN_OBJ_DICT_METHOD_FINDOBJ();

  return true;
}/*}}}*/

bool bic_can_obj_dict_method_CanObjDict_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("CanObjDict#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *name_ptr = (string_s *)src_0_location->v_data_ptr;

  ObjDict *dict_ptr = new ObjDict();

  try
  {
    // - open object dictionary -
    dict_ptr->Open(String(name_ptr->data));
  }

  // - ERROR -
  catch (Exception &e)
  {
    delete dict_ptr;

    exception_s::throw_exception(it,module.error_base + c_error_CAN_OBJECT_DICT_OPEN_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  // - create new can obj dict object -
  can_obj_dict_s *cod_ptr = (can_obj_dict_s *)cmalloc(sizeof(can_obj_dict_s));
  cod_ptr->eds_builder = false;
  cod_ptr->dict_ptr = dict_ptr;

  // - set destination data pointer -
  dst_location->v_data_ptr = (can_obj_dict_s *)cod_ptr;

  return true;
}/*}}}*/

bool bic_can_obj_dict_method_CanObjDict_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);
  location_s *src_3_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_3_op_idx]);

  long long int size;
  long long int node_id;

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string ||
      !it.retrieve_integer(src_1_location,size) ||
      src_2_location->v_type != c_bi_class_string ||
      !it.retrieve_integer(src_3_location,node_id))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("CanObjDict#4");
    new_exception->params.push(4);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);
    new_exception->params.push(src_3_location->v_type);

    return false;
  }

  string_s *name_ptr = (string_s *)src_0_location->v_data_ptr;
  string_s *file_ptr = (string_s *)src_2_location->v_data_ptr;

  LodEdsBuilder *dict_ptr = new LodEdsBuilder();

  try
  {
    // - create object dictionary -
    dict_ptr->Create(String(name_ptr->data),size,String(file_ptr->data),node_id);
  }

  // - ERROR -
  catch (Exception &e)
  {
    delete dict_ptr;

    exception_s::throw_exception(it,module.error_base + c_error_CAN_OBJECT_DICT_CREATE_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  // - create new can obj dict object -
  can_obj_dict_s *cod_ptr = (can_obj_dict_s *)cmalloc(sizeof(can_obj_dict_s));
  cod_ptr->eds_builder = true;
  cod_ptr->dict_ptr = dict_ptr;

  // - set destination data pointer -
  dst_location->v_data_ptr = (can_obj_dict_s *)cod_ptr;

  return true;
}/*}}}*/

bool bic_can_obj_dict_method_FindObj_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int index;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,index))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("FindObj#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  can_obj_dict_s *cod_ptr = (can_obj_dict_s *)dst_location->v_data_ptr;
  ObjDict::Mux mux((U32)index);

  BIC_CAN_OBJ_DICT_METHOD_FINDOBJ();

  return true;
}/*}}}*/

bool bic_can_obj_dict_method_FindObj_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int index;
  long long int sub_index;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,index) ||
      !it.retrieve_integer(src_1_location,sub_index))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("FindObj#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  can_obj_dict_s *cod_ptr = (can_obj_dict_s *)dst_location->v_data_ptr;
  ObjDict::Mux mux(index,sub_index);

  BIC_CAN_OBJ_DICT_METHOD_FINDOBJ();

  return true;
}/*}}}*/

bool bic_can_obj_dict_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("CanObjDict"),"CanObjDict")
  );

  return true;
}/*}}}*/

bool bic_can_obj_dict_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("CanObjDict");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class CAN_OBJECT -
built_in_class_s can_object_class =
{/*{{{*/
  "CanObject",
  c_modifier_public | c_modifier_final,
  9, can_object_methods,
  6 + 12, can_object_variables,
  bic_can_object_consts,
  bic_can_object_init,
  bic_can_object_clear,
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

built_in_method_s can_object_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_can_object_operator_binary_equal
  },
  {
    "size#0",
    c_modifier_public | c_modifier_final,
    bic_can_object_method_size_0
  },
  {
    "flags#0",
    c_modifier_public | c_modifier_final,
    bic_can_object_method_flags_0
  },
  {
    "buffer#0",
    c_modifier_public | c_modifier_final,
    bic_can_object_method_buffer_0
  },
  {
    "get_type#0",
    c_modifier_public | c_modifier_final,
    bic_can_object_method_get_type_0
  },
  {
    "write#1",
    c_modifier_public | c_modifier_final,
    bic_can_object_method_write_1
  },
  {
    "read#0",
    c_modifier_public | c_modifier_final,
    bic_can_object_method_read_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_can_object_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_can_object_method_print_0
  },
};/*}}}*/

built_in_variable_s can_object_variables[] =
{/*{{{*/

  // - can object flag constants -
  { "FLAG_RO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FLAG_WO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FLAG_RW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FLAG_CO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FLAG_MAP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FLAG_LEN", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - can object type constants -
  { "TYPE_BOOL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_I8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_I16", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_I32", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_U8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_U16", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_U32", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_VISIBLE_STRING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_OCTET_STRING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_TIME_OF_DAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_DOMAIN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_U64", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_can_object_consts(location_array_s &const_locations)
{/*{{{*/

  // - can object flag constants -
  {
    const_locations.push_blanks(6);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 6);

#define CREATE_CAN_OBJECT_FLAG_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_CAN_OBJECT_FLAG_BIC_STATIC(ObjAttr::RO);
    CREATE_CAN_OBJECT_FLAG_BIC_STATIC(ObjAttr::WO);
    CREATE_CAN_OBJECT_FLAG_BIC_STATIC(ObjAttr::RW);
    CREATE_CAN_OBJECT_FLAG_BIC_STATIC(ObjAttr::CO);
    CREATE_CAN_OBJECT_FLAG_BIC_STATIC(ObjAttr::MAP);
    CREATE_CAN_OBJECT_FLAG_BIC_STATIC(ObjAttr::LEN);
  }

  // - can object type constants -
  {
    const_locations.push_blanks(12);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 12);

#define CREATE_CAN_OBJECT_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_CAN_OBJECT_TYPE_BIC_STATIC(CT_BOOL);
    CREATE_CAN_OBJECT_TYPE_BIC_STATIC(CT_I8);
    CREATE_CAN_OBJECT_TYPE_BIC_STATIC(CT_I16);
    CREATE_CAN_OBJECT_TYPE_BIC_STATIC(CT_I32);
    CREATE_CAN_OBJECT_TYPE_BIC_STATIC(CT_U8);
    CREATE_CAN_OBJECT_TYPE_BIC_STATIC(CT_U16);
    CREATE_CAN_OBJECT_TYPE_BIC_STATIC(CT_U32);
    CREATE_CAN_OBJECT_TYPE_BIC_STATIC(CT_VISIBLE_STRING);
    CREATE_CAN_OBJECT_TYPE_BIC_STATIC(CT_OCTET_STRING);
    CREATE_CAN_OBJECT_TYPE_BIC_STATIC(CT_TIME_OF_DAY);
    CREATE_CAN_OBJECT_TYPE_BIC_STATIC(CT_DOMAIN);
    CREATE_CAN_OBJECT_TYPE_BIC_STATIC(CT_U64);
  }
}/*}}}*/

void bic_can_object_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (can_object_s *)nullptr;
}/*}}}*/

void bic_can_object_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  can_object_s *co_ptr = (can_object_s *)location_ptr->v_data_ptr;

  if (co_ptr != nullptr)
  {
    co_ptr->clear(it);
    cfree(co_ptr);
  }
}/*}}}*/

bool bic_can_object_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

#define BIC_CAN_OBJECT_METHOD_GET_VALUE(VALUE) \
{/*{{{*/\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  can_object_s *co_ptr = (can_object_s *)dst_location->v_data_ptr;\
\
  long long int result = (*((can_object_s::ObjMap_s **)(&co_ptr->handle)))->VALUE;\
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
\
  return true;\
}/*}}}*/

bool bic_can_object_method_size_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CAN_OBJECT_METHOD_GET_VALUE(size);
}/*}}}*/

bool bic_can_object_method_flags_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CAN_OBJECT_METHOD_GET_VALUE(flags);
}/*}}}*/

bool bic_can_object_method_buffer_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CAN_OBJECT_METHOD_GET_VALUE(alloc);
}/*}}}*/

bool bic_can_object_method_get_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CAN_OBJECT_METHOD_GET_VALUE(copType);
}/*}}}*/

bool bic_can_object_method_write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  can_object_s *co_ptr = (can_object_s *)dst_location->v_data_ptr;
  can_obj_dict_s *cod_ptr = (can_obj_dict_s *)co_ptr->dict_loc->v_data_ptr;
  can_object_s::ObjMap_s *obj_map = *((can_object_s::ObjMap_s **)(&co_ptr->handle));

  // - ERROR -
  if (obj_map->desc.objectCode != CO_VAR)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_CAN_OBJECT_UNSUPPORTED_OBJECT_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(obj_map->desc.objectCode);

    return false;
  }

  // - ERROR -
  if (!(obj_map->flags & ObjAttr::WO))
  {
    exception_s::throw_exception(it,module.error_base + c_error_CAN_OBJECT_WRITE_VARIABLE_NOT_WRITABLE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  switch (obj_map->copType)
  {
    case CT_BOOL:
    case CT_I8:
    case CT_I16:
    case CT_I32:
    case CT_U8:
    case CT_U16:
    case CT_U32:
    case CT_U64:
      {/*{{{*/
        long long int value;

        // - ERROR -
        if (!it.retrieve_integer(src_0_location,value))
        {
          exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_CAN_OBJECT_WRITE_WRONG_VARIABLE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
          new_exception->params.push(c_bi_class_integer);

          return false;
        }

        U32 result = SDO_ABORT_OK;

#define CAN_OBJECT_METHOD_WRITE_COD_VALUE_INTEGER(TYPE) \
{/*{{{*/\
  TYPE cod_value = value;\
  result = cod_ptr->dict_ptr->Write(co_ptr->handle,&cod_value,sizeof(TYPE),0,false);\
}/*}}}*/

        switch (obj_map->copType)
        {
          case CT_BOOL:
          case CT_I8:
            CAN_OBJECT_METHOD_WRITE_COD_VALUE_INTEGER(I8)
            break;
          case CT_I16:
            CAN_OBJECT_METHOD_WRITE_COD_VALUE_INTEGER(I16)
            break;
          case CT_I32:
            CAN_OBJECT_METHOD_WRITE_COD_VALUE_INTEGER(I32)
            break;
          case CT_U8:
            CAN_OBJECT_METHOD_WRITE_COD_VALUE_INTEGER(U8)
            break;
          case CT_U16:
            CAN_OBJECT_METHOD_WRITE_COD_VALUE_INTEGER(U16)
            break;
          case CT_U32:
            CAN_OBJECT_METHOD_WRITE_COD_VALUE_INTEGER(U32)
            break;
          case CT_U64:
            CAN_OBJECT_METHOD_WRITE_COD_VALUE_INTEGER(U64)
            break;
        }

        // - ERROR -
        if (result != SDO_ABORT_OK)
        {
          exception_s::throw_exception(it,module.error_base + c_error_CAN_OBJECT_WRITE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
          return false;
        }

      }/*}}}*/
      break;

    case CT_VISIBLE_STRING:
    case CT_OCTET_STRING:
      {/*{{{*/
        
        // - ERROR -
        if (src_0_location->v_type != c_bi_class_string)
        {
          exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_CAN_OBJECT_WRITE_WRONG_VARIABLE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
          new_exception->params.push(c_bi_class_string);

          return false;
        }

        // - retrieve source string -
        string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

        U32 result = cod_ptr->dict_ptr->Write(co_ptr->handle,string_ptr->data,string_ptr->size - 1,0,false);

        // - ERROR -
        if (result != SDO_ABORT_OK)
        {
          exception_s::throw_exception(it,module.error_base + c_error_CAN_OBJECT_WRITE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
          return false;
        }
      }/*}}}*/
      break;

    // - ERROR -
    case CT_TIME_OF_DAY:
    case CT_DOMAIN:
    default:
      {
        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_CAN_OBJECT_UNSUPPORTED_VARIABLE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(obj_map->copType);

        return false;
      }
      break;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_can_object_method_read_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  can_object_s *co_ptr = (can_object_s *)dst_location->v_data_ptr;
  can_obj_dict_s *cod_ptr = (can_obj_dict_s *)co_ptr->dict_loc->v_data_ptr;
  can_object_s::ObjMap_s *obj_map = *((can_object_s::ObjMap_s **)(&co_ptr->handle));

  // - ERROR -
  if (obj_map->desc.objectCode != CO_VAR)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_CAN_OBJECT_UNSUPPORTED_OBJECT_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(obj_map->desc.objectCode);

    return false;
  }

  switch (obj_map->copType)
  {
    case CT_BOOL:
    case CT_I8:
    case CT_I16:
    case CT_I32:
    case CT_U8:
    case CT_U16:
    case CT_U32:
    case CT_U64:
      {/*{{{*/
        long long int value = 0;
        U32 result = SDO_ABORT_OK;

#define CAN_OBJECT_METHOD_READ_COD_VALUE_INTEGER(TYPE) \
{/*{{{*/\
  TYPE cod_value;\
  U32 size = sizeof(TYPE);\
  result = cod_ptr->dict_ptr->Read(co_ptr->handle,&cod_value,size,0,false,nullptr);\
  value = cod_value;\
}/*}}}*/

        switch (obj_map->copType)
        {
          case CT_BOOL:
          case CT_I8:
            CAN_OBJECT_METHOD_READ_COD_VALUE_INTEGER(I8)
            break;
          case CT_I16:
            CAN_OBJECT_METHOD_READ_COD_VALUE_INTEGER(I16)
            break;
          case CT_I32:
            CAN_OBJECT_METHOD_READ_COD_VALUE_INTEGER(I32)
            break;
          case CT_U8:
            CAN_OBJECT_METHOD_READ_COD_VALUE_INTEGER(U8)
            break;
          case CT_U16:
            CAN_OBJECT_METHOD_READ_COD_VALUE_INTEGER(U16)
            break;
          case CT_U32:
            CAN_OBJECT_METHOD_READ_COD_VALUE_INTEGER(U32)
            break;
          case CT_U64:
            CAN_OBJECT_METHOD_READ_COD_VALUE_INTEGER(U64)
            break;
        }

        // - ERROR -
        if (result != SDO_ABORT_OK)
        {
          exception_s::throw_exception(it,module.error_base + c_error_CAN_OBJECT_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
          return false;
        }

        BIC_SIMPLE_SET_RES(c_bi_class_integer,value);
      }/*}}}*/
      break;

    case CT_VISIBLE_STRING:
    case CT_OCTET_STRING:
      {/*{{{*/
        U32 size = obj_map->size;

        // - create result string -
        string_s *string_ptr = it.get_new_string_ptr();
        string_ptr->create(size);

        U32 result = cod_ptr->dict_ptr->Read(co_ptr->handle,string_ptr->data,size,0,false,nullptr);

        // - ERROR -
        if (result != SDO_ABORT_OK || size != obj_map->size)
        {
          string_ptr->clear();
          cfree(string_ptr);

          exception_s::throw_exception(it,module.error_base + c_error_CAN_OBJECT_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
          return false;
        }

        BIC_SET_RESULT_STRING(string_ptr);
      }/*}}}*/
      break;
      
    // - ERROR -
    case CT_TIME_OF_DAY:
    case CT_DOMAIN:
    default:
      {
        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_CAN_OBJECT_UNSUPPORTED_VARIABLE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(obj_map->copType);

        return false;
      }
      break;
  }

  return true;
}/*}}}*/

bool bic_can_object_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("CanObject"),"CanObject")
  );

  return true;
}/*}}}*/

bool bic_can_object_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("CanObject");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

