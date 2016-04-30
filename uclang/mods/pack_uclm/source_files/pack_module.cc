
@begin
include "pack_module.h"
@end

// - PACK indexes of built in classes -
unsigned c_bi_class_pack = c_idx_not_exist;

// - PACK module -
built_in_module_s module =
{/*{{{*/
  1,                     // Class count
  pack_classes,          // Classes

  0,                     // Error base index
  11,                    // Error count
  pack_error_strings,    // Error strings

  pack_initialize,       // Initialize function
  pack_print_exception,  // Print exceptions function
};/*}}}*/

// - PACK classes -
built_in_class_s *pack_classes[] =
{/*{{{*/
  &pack_class,
};/*}}}*/

// - PACK error strings -
const char *pack_error_strings[] =
{/*{{{*/
  "error_PACK_BUILT_IN_NOT_DEFINED_PACK",
  "error_PACK_BUILT_IN_NOT_DEFINED_UNPACK",
  "error_PACK_ERROR_WHILE_PACKING_OBJECT",
  "error_PACK_ERROR_WHILE_UNPACKING_VALUE_STREAM",
  "error_PACK_ERROR_WHILE_UNPACKING_CLASS_STREAM",
  "error_PACK_ERROR_WHILE_UNPACKING_OBJECT",
  "error_PACK_CODE_NOT_ENOUGH_ARGUMENTS",
  "error_PACK_CODE_WRONG_ARGUMENT_TYPE",
  "error_PACK_CODE_WRONG_FORMAT_STRING",
  "error_PACK_CODE_NOT_ALL_ARGUMENTS_CONVERTED",
  "error_PACK_DECODE_NOT_ENOUGH_DATA_BYTES",
};/*}}}*/

// - PACK initialize -
bool pack_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize pack class identifier -
  c_bi_class_pack = class_base_idx++;

  return true;
}/*}}}*/

// - PACK print exception -
bool pack_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_PACK_BUILT_IN_NOT_DEFINED_PACK:
  {
    class_record_s &class_record = it.class_records[exception.params[0]];

    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nObject of class ");
    print_class_sequence(it.class_symbol_names,it.class_records,class_stack,class_record.parent_record);
    fprintf(stderr,"%s cannot be packed\n",it.class_symbol_names[class_record.name_idx].data);
    fprintf(stderr," ---------------------------------------- \n");
  }
  break;
  case c_error_PACK_BUILT_IN_NOT_DEFINED_UNPACK:
  {
    class_record_s &class_record = it.class_records[exception.params[0]];

    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nObject of class ");
    print_class_sequence(it.class_symbol_names,it.class_records,class_stack,class_record.parent_record);
    fprintf(stderr,"%s cannot be unpacked\n",it.class_symbol_names[class_record.name_idx].data);
    fprintf(stderr," ---------------------------------------- \n");
  }
  break;
  case c_error_PACK_ERROR_WHILE_PACKING_OBJECT:
  {
    class_record_s &class_record = it.class_records[exception.params[0]];

    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while packing object of class ");
    print_class_sequence(it.class_symbol_names,it.class_records,class_stack,class_record.parent_record);
    fprintf(stderr,"%s\n",it.class_symbol_names[class_record.name_idx].data);
    fprintf(stderr," ---------------------------------------- \n");
  }
  break;
  case c_error_PACK_ERROR_WHILE_UNPACKING_VALUE_STREAM:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while unpacking stream of values\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PACK_ERROR_WHILE_UNPACKING_CLASS_STREAM:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while unpacking stream of classes\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PACK_ERROR_WHILE_UNPACKING_OBJECT:
  {
    class_record_s &class_record = it.class_records[exception.params[0]];

    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while unpacking object of class ");
    print_class_sequence(it.class_symbol_names,it.class_records,class_stack,class_record.parent_record);
    fprintf(stderr,"%s\n",it.class_symbol_names[class_record.name_idx].data);
    fprintf(stderr," ---------------------------------------- \n");
  }
  break;
  case c_error_PACK_CODE_NOT_ENOUGH_ARGUMENTS:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nNot enough arguments to be coded according to format string\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PACK_CODE_WRONG_ARGUMENT_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong argument type for pack code, at position %" HOST_LL_FORMAT "d expected %s received %s\n",
            exception.params[0],it.class_symbol_names[it.class_records[exception.params[1]].name_idx].data,it.class_symbol_names[it.class_records[exception.params[2]].name_idx].data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PACK_CODE_WRONG_FORMAT_STRING:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError in pack code format string, at index: %" HOST_LL_FORMAT "d \n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PACK_CODE_NOT_ALL_ARGUMENTS_CONVERTED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nNot all arguments converted during pack code\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PACK_DECODE_NOT_ENOUGH_DATA_BYTES:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nNot enough bytes in data source string\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class PACK -
built_in_class_s pack_class =
{/*{{{*/
  "Pack",
  c_modifier_public | c_modifier_final,
  6, pack_methods,
  0, pack_variables,
  bic_pack_consts,
  bic_pack_init,
  bic_pack_clear,
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

built_in_method_s pack_methods[] =
{/*{{{*/
  {
    "pack#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_pack_method_pack_1
  },
  {
    "unpack#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_pack_method_unpack_1
  },
  {
    "code#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_pack_method_code_2
  },
  {
    "decode#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_pack_method_decode_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_pack_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_pack_method_print_0
  },
};/*}}}*/

built_in_variable_s pack_variables[] =
{/*{{{*/
};/*}}}*/

void bic_pack_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_pack_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_pack_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_pack_method_pack_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - initialize location stack -
  pointer_array_s loc_stack;
  loc_stack.init();

  // - initialize value stream buffer -
  bc_array_s value_stream;
  value_stream.init();

  // - initialize class pack -
  class_pack_s class_pack;
  class_pack.init();

#define PACK_RELEASE() \
  {/*{{{*/\
    loc_stack.clear();\
    value_stream.clear();\
    class_pack.clear();\
  }/*}}}*/

  // - push initial value to location stack -
  loc_stack.push((pointer)src_0_location);

  do
  {
    // - retrieve location from stack -
    location_s *location = it.get_location_value((location_s *)loc_stack.pop());

    // - retrieve location class record -
    class_record_s &class_record = ((interpreter_s *)it.interpreter_ptr)->class_records[location->v_type];

    if (class_record.modifiers & c_modifier_built_in)
    {
      // - ERROR -
      if (class_record.bi_class_ptr->pack_caller == NULL)
      {
        PACK_RELEASE();

        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PACK_BUILT_IN_NOT_DEFINED_PACK,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(location->v_type);

        return false;
      }

      // - ERROR -
      if (!class_record.bi_class_ptr->pack_caller(location,value_stream,loc_stack))
      {
        PACK_RELEASE();

        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PACK_ERROR_WHILE_PACKING_OBJECT,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(location->v_type);

        return false;
      }
    }
    else
    {
      // - ERROR -
      if (!bi_object_pack(location,value_stream,loc_stack))
      {
        PACK_RELEASE();

        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PACK_ERROR_WHILE_PACKING_OBJECT,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(location->v_type);

        return false;
      }
    }

    // - translate class index to class position -
    unsigned class_pos = class_pack.pack_class_name(it,location->v_type);

    // - insert class identification to value stream -
    value_stream.append(sizeof(unsigned),(const char *)&class_pos);

  }
  while(loc_stack.used != 0);

  // - append class pack stream to value stream -
  {
    bc_array_s &class_stream = class_pack.class_stream;

    value_stream.append(class_stream.used,(const char *)class_stream.data);
    value_stream.append(sizeof(unsigned),(const char *)&class_stream.used);
  }

  loc_stack.clear();
  class_pack.clear();

  // - insert byte order test value -
  unsigned short byte_order_test = 0x00ff;
  value_stream.append(sizeof(unsigned short),(const char *)&byte_order_test);

  // - insert terminating character to result value stream -
  value_stream.push('\0');

  // - construct result string -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->data = value_stream.data;
  string_ptr->size = value_stream.used;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_pack_method_unpack_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_pack,"unpack#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - initialize value stream buffer -
  bc_array_s value_stream;
  value_stream.data = string_ptr->data;
  value_stream.size = string_ptr->size - 1;
  value_stream.used = value_stream.size;

  // - initialize location stack -
  pointer_array_s loc_stack;
  loc_stack.init();

  // - initialize class unpack -
  class_unpack_s class_unpack;
  class_unpack.init();

#define UNPACK_RELEASE() \
  {/*{{{*/\
    class_unpack.clear();\
    \
    if (loc_stack.used != 0)\
    {\
      /* - release locations from location stack - */\
      pointer *l_ptr = loc_stack.data;\
      pointer *l_ptr_end = l_ptr + loc_stack.used;\
      \
      do {\
        it.release_location_ptr((location_s *)*l_ptr);\
      } while(++l_ptr < l_ptr_end);\
    }\
    \
    loc_stack.clear();\
  }/*}}}*/

#define UNPACK_ERROR_TEST(CONDITION) \
  {/*{{{*/\
    if (CONDITION)\
    {\
      UNPACK_RELEASE();\
      \
      exception_s::throw_exception(it,module.error_base + c_error_PACK_ERROR_WHILE_UNPACKING_VALUE_STREAM,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      return false;\
    }\
  }/*}}}*/

  // - ERROR -
  UNPACK_ERROR_TEST(value_stream.used < sizeof(unsigned short));

  // - retrieve byte order test value -
  unsigned short byte_order_test;
  value_stream.from_end(sizeof(unsigned short),(char *)&byte_order_test,false);

  // - ERROR -
  UNPACK_ERROR_TEST(byte_order_test != 0x00ff && byte_order_test != 0xff00);

  // - set order bytes indicator -
  bool order_bytes = byte_order_test == 0xff00;

  // - ERROR -
  UNPACK_ERROR_TEST(value_stream.used < sizeof(unsigned));

  // - retrieve class pack stream size -
  unsigned cp_stream_size;
  value_stream.from_end(sizeof(unsigned),(char *)&cp_stream_size,order_bytes);

  // - ERROR -
  UNPACK_ERROR_TEST(value_stream.used < cp_stream_size);

  // - read class stream -
  if (!class_unpack.unpack_from_stream(it,value_stream.data + value_stream.used - cp_stream_size,cp_stream_size,order_bytes))
  {
    UNPACK_RELEASE();

    exception_s::throw_exception(it,module.error_base + c_error_PACK_ERROR_WHILE_UNPACKING_CLASS_STREAM,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - remove class stream from value stream -
  value_stream.used -= cp_stream_size;

  do
  {
    // - ERROR -
    UNPACK_ERROR_TEST(value_stream.used < sizeof(unsigned));

    // - retrieve class position -
    unsigned class_pos;
    value_stream.from_end(sizeof(unsigned),(char *)&class_pos,order_bytes);

    // - retrieve class index -
    unsigned class_idx = class_unpack.get_class_idx(class_pos);

    // - ERROR -
    UNPACK_ERROR_TEST(class_idx == c_idx_not_exist);

    // - retrieve location class record -
    class_record_s &class_record = ((interpreter_s *)it.interpreter_ptr)->class_records[class_idx];

    if (class_record.modifiers & c_modifier_built_in)
    {
      // - ERROR -
      if (class_record.bi_class_ptr->unpack_caller == NULL)
      {
        UNPACK_RELEASE();

        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PACK_BUILT_IN_NOT_DEFINED_UNPACK,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(class_idx);

        return false;
      }

      // - construct new location -
      BIC_CREATE_NEW_LOCATION(new_location,class_idx,0);

      // - ERROR -
      if (!class_record.bi_class_ptr->unpack_caller(it,new_location,value_stream,loc_stack,order_bytes,operands[c_source_pos_idx]))
      {
        UNPACK_RELEASE();

        it.release_location_ptr(new_location);

        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PACK_ERROR_WHILE_UNPACKING_OBJECT,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(class_idx);

        return false;
      }

      // - insert new location to location stack -
      loc_stack.push((pointer)new_location);
    }
    else
    {
      // - construct new location -
      BIC_CREATE_NEW_LOCATION(new_location,class_idx,0);

      // - ERROR -
      if (!bi_object_unpack(it,new_location,value_stream,loc_stack,order_bytes,operands[c_source_pos_idx]))
      {
        UNPACK_RELEASE();

        it.release_location_ptr(new_location);

        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PACK_ERROR_WHILE_UNPACKING_OBJECT,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(class_idx);

        return false;
      }

      // - insert new location to location stack -
      loc_stack.push((pointer)new_location);
    }

  }
  while(value_stream.used != 0);

  // - ERROR -
  UNPACK_ERROR_TEST(loc_stack.used != 1);

  BIC_SET_RESULT(loc_stack.pop());

  class_unpack.clear();
  loc_stack.clear();

  return true;
}/*}}}*/

bool bic_pack_method_code_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_pack,"code#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  // - retrieve string pointer -
  string_s *format_string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - retrieve arguments array -
  pointer_array_s *array_ptr;
  pointer_array_s dummy_array;

  if (src_1_location->v_type != c_bi_class_array)
  {
    dummy_array.data = (pointer *)&src_1_location;
    dummy_array.used = 1;
    dummy_array.size = 1;

    array_ptr = &dummy_array;
  }
  else
  {
    // - retrieve argument array pointer -
    array_ptr = (pointer_array_s *)src_1_location->v_data_ptr;
  }

  // - result character buffer -
  bc_array_s buffer;
  buffer.init();

#define PC_CLEAR_DATA() \
  buffer.clear()

#define PC_PROCESS_ELEMENT(TYPE,CLASS_TYPE,RETRIEVE_CODE) \
  {/*{{{*/\
    data_size = count*sizeof(TYPE);\
    \
    if (data_size > c_temp_size)\
    {\
      data_buffer = (char *)cmalloc(data_size);\
    }\
    \
    if (data_size > 0)\
    {\
      TYPE *d_ptr;\
      TYPE *d_ptr_end;\
      int d_step;\
      \
      if (change_byte_order)\
      {\
        d_ptr = (TYPE *)data_buffer + count - 1;\
        d_ptr_end = (TYPE *)data_buffer;\
        d_step = -1;\
      }\
      else {\
        d_ptr = (TYPE *)data_buffer;\
        d_ptr_end = (TYPE *)data_buffer + count - 1;\
        d_step = 1;\
      }\
      \
      do {\
        \
        /* - ERROR - */\
        if (array_ptr->used <= element_idx)\
        {\
          PC_CLEAR_DATA();\
          \
          exception_s::throw_exception(it,module.error_base + c_error_PACK_CODE_NOT_ENOUGH_ARGUMENTS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
          return false;\
        }\
        \
        /* - retrieve argument - */\
        location_s *element_location = it.get_location_value(array_ptr->data[element_idx++]);\
        \
        /* - ERROR - */\
        if (element_location->v_type != CLASS_TYPE)\
        {\
          PC_CLEAR_DATA();\
          \
          exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PACK_CODE_WRONG_ARGUMENT_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
          new_exception->params.push(element_idx);\
          new_exception->params.push(CLASS_TYPE);\
          new_exception->params.push(element_location->v_type);\
          \
          return false;\
        }\
        \
        *d_ptr = RETRIEVE_CODE;\
        \
        if (d_ptr == d_ptr_end)\
        {\
          break;\
        }\
        \
        d_ptr += d_step;\
        \
      } while(true);\
    }\
  }/*}}}*/

  // - index of element in argument array -
  unsigned element_idx = 0;

  if (format_string_ptr->size > 1)
  {
    char *f_ptr = format_string_ptr->data;
    char *old_f_ptr;

    bool change_byte_order = false;
    unsigned count = 1;

    const unsigned c_temp_size = 512;
    char temp_buffer[c_temp_size];

    char *data_buffer = temp_buffer;
    unsigned data_size = 0;

    unsigned ret_term;
    do
    {
      old_f_ptr = f_ptr;
      ret_term = pcd_terminal_recognize(&f_ptr);

      // - ERROR -
      if (ret_term == c_idx_not_exist)
      {
        PC_CLEAR_DATA();

        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PACK_CODE_WRONG_FORMAT_STRING,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(old_f_ptr - format_string_ptr->data);

        return false;
      }

      // - test end of format string -
      if (ret_term != PCD_TERM_END)
      {
        switch (ret_term)
        {
        case PCD_TERM_NUMBER:
        {/*{{{*/
          count = strtoll(old_f_ptr,NULL,10);
        }/*}}}*/
        break;
        case PCD_TERM_NATIVE:
        {/*{{{*/
          change_byte_order = false;
        }/*}}}*/
        break;
        case PCD_TERM_LITTLE_ENDIAN:
        {/*{{{*/
          change_byte_order = !c_little_endian;
        }/*}}}*/
        break;
        case PCD_TERM_BIG_ENDIAN:
        {/*{{{*/
          change_byte_order = !c_big_endian;
        }/*}}}*/
        break;
        case PCD_TERM_CHAR:
        {/*{{{*/
          PC_PROCESS_ELEMENT(char,c_bi_class_char,(char)element_location->v_data_ptr)
        }/*}}}*/
        goto PCD_WRITE_DATA;
        case PCD_TERM_SIGNED_BYTE:
        {/*{{{*/
          PC_PROCESS_ELEMENT(signed char,c_bi_class_integer,(signed char)(long long int)element_location->v_data_ptr)
        }/*}}}*/
        goto PCD_WRITE_DATA;
        case PCD_TERM_UNSIGNED_BYTE:
        {/*{{{*/
          PC_PROCESS_ELEMENT(unsigned char,c_bi_class_integer,(unsigned char)(long long int)element_location->v_data_ptr)
        }/*}}}*/
        goto PCD_WRITE_DATA;
        case PCD_TERM_SHORT:
        {/*{{{*/
          PC_PROCESS_ELEMENT(short,c_bi_class_integer,(short)(long long int)element_location->v_data_ptr)
        }/*}}}*/
        goto PCD_WRITE_DATA;
        case PCD_TERM_UNSIGNED_SHORT:
        {/*{{{*/
          PC_PROCESS_ELEMENT(unsigned short,c_bi_class_integer,(unsigned short)(long long int)element_location->v_data_ptr)
        }/*}}}*/
        goto PCD_WRITE_DATA;
        case PCD_TERM_INT:
        {/*{{{*/
          PC_PROCESS_ELEMENT(int,c_bi_class_integer,(int)(long long int)element_location->v_data_ptr)
        }/*}}}*/
        goto PCD_WRITE_DATA;
        case PCD_TERM_UNSIGNED:
        {/*{{{*/
          PC_PROCESS_ELEMENT(unsigned,c_bi_class_integer,(unsigned)(long long int)element_location->v_data_ptr)
        }/*}}}*/
        goto PCD_WRITE_DATA;
        case PCD_TERM_LONG_INT:
        {/*{{{*/
          PC_PROCESS_ELEMENT(long int,c_bi_class_integer,(long int)(long long int)element_location->v_data_ptr)
        }/*}}}*/
        goto PCD_WRITE_DATA;
        case PCD_TERM_LONG_UNSIGNED:
        {/*{{{*/
          PC_PROCESS_ELEMENT(long unsigned,c_bi_class_integer,(long unsigned)(long long int)element_location->v_data_ptr)
        }/*}}}*/
        goto PCD_WRITE_DATA;
        case PCD_TERM_LONG_LONG_INT:
        {/*{{{*/
          PC_PROCESS_ELEMENT(long long int,c_bi_class_integer,(long long int)(long long int)element_location->v_data_ptr)
        }/*}}}*/
        goto PCD_WRITE_DATA;
        case PCD_TERM_LONG_LONG_UNSIGNED:
        {/*{{{*/
          PC_PROCESS_ELEMENT(long long unsigned,c_bi_class_integer,(long long unsigned)(long long int)element_location->v_data_ptr)
        }/*}}}*/
        goto PCD_WRITE_DATA;
        case PCD_TERM_FLOAT:
        {/*{{{*/
          PC_PROCESS_ELEMENT(float,c_bi_class_float,(float)*((double *)&element_location->v_data_ptr))
        }/*}}}*/
        goto PCD_WRITE_DATA;
        case PCD_TERM_DOUBLE:
        {/*{{{*/
          PC_PROCESS_ELEMENT(double,c_bi_class_float,*((double *)&element_location->v_data_ptr))
        }/*}}}*/
        goto PCD_WRITE_DATA;
        case PCD_TERM_STRING:
        {/*{{{*/
          if (count > 0)
          {
            unsigned val_idx = 0;
            do
            {
              // - ERROR -
              if (array_ptr->used <= element_idx)
              {
                PC_CLEAR_DATA();

                exception_s::throw_exception(it,module.error_base + c_error_PACK_CODE_NOT_ENOUGH_ARGUMENTS,operands[c_source_pos_idx],(location_s *)it.blank_location);
                return false;
              }

              // - retrieve argument -
              location_s *element_location = it.get_location_value(array_ptr->data[element_idx++]);

              // - ERROR -
              if (element_location->v_type != c_bi_class_string)
              {
                PC_CLEAR_DATA();

                exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PACK_CODE_WRONG_ARGUMENT_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
                new_exception->params.push(element_idx);
                new_exception->params.push(c_bi_class_string);
                new_exception->params.push(element_location->v_type);

                return false;
              }

              // - retrieve string -
              string_s *string_ptr = (string_s *)element_location->v_data_ptr;
              unsigned string_length = string_ptr->size - 1;

              unsigned old_used = buffer.used;
              buffer.push_blanks(sizeof(unsigned));

              if (change_byte_order)
              {
                // - copy string length with reversed byte order -
                char *ptr = (char *)&string_length;
                char *ptr_end = ptr + sizeof(unsigned);
                char *t_ptr = buffer.data + old_used + sizeof(unsigned);
                do
                {
                  *(--t_ptr) = *ptr;
                }
                while(++ptr < ptr_end);
              }
              else
              {
                // - copy string length with preserved byte order -
                *((unsigned *)(buffer.data + old_used)) = string_length;
              }

              // - copy string data -
              if (string_length > 0)
              {
                old_used = buffer.used;
                buffer.push_blanks(string_length);
                memcpy(buffer.data + old_used,string_ptr->data,string_length);
              }

            }
            while(++val_idx < count);
          }
        }/*}}}*/
        break;
PCD_WRITE_DATA:
        {/*{{{*/
          if (data_size > 0)
          {
            // - copy data to target buffer -
            unsigned old_used = buffer.used;
            buffer.push_blanks(data_size);

            if (change_byte_order)
            {
              // - copy data with reversed byte order -
              char *d_ptr = data_buffer + data_size - 1;
              char *d_ptr_end = data_buffer;
              char *ptr = buffer.data + old_used;
              do
              {
                *ptr = *d_ptr;
              }
              while(++ptr,--d_ptr >= d_ptr_end);
            }
            else
            {
              // - copy data with preserved byte order -
              memcpy(buffer.data + old_used,data_buffer,data_size);
            }
          }

          if (data_buffer != temp_buffer)
          {
            cfree(data_buffer);
            data_buffer = temp_buffer;
          }

          count = 1;
        }/*}}}*/
        break;
        default:
          cassert(0);
        }
      }
    }
    while(ret_term != PCD_TERM_END);
  }

  // - ERROR -
  if (element_idx < array_ptr->used)
  {
    PC_CLEAR_DATA();

    exception_s::throw_exception(it,module.error_base + c_error_PACK_CODE_NOT_ALL_ARGUMENTS_CONVERTED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - push terminating character to buffer -
  buffer.push('\0');

  // - create result string -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->data = buffer.data;
  string_ptr->size = buffer.used;

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_pack_method_decode_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string ||
      src_1_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_pack,"decode#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  // - retrieve string pointer -
  string_s *format_string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - retrieve data pointer -
  string_s *data_string_ptr = (string_s *)src_1_location->v_data_ptr;

  // - create result location -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  location_s *array_location = it.get_new_location_ptr();
  array_location->v_type = c_bi_class_array;
  array_location->v_reference_cnt.atomic_set(1);
  array_location->v_data_ptr = (basic_64b)array_ptr;

#define PD_CLEAR_DATA() \
  it.release_location_ptr(array_location);

#define PD_PROCESS_ELEMENT(TYPE,CLASS_TYPE,RETRIEVE_CODE) \
  {/*{{{*/\
    data_size = count*sizeof(TYPE);\
    \
    if (data_size > 0)\
    {\
      if (data_size > c_temp_size)\
      {\
        data_buffer = (char *)cmalloc(data_size);\
      }\
      \
      /* - ERROR - */\
      if ((unsigned)(ds_ptr_end - ds_ptr) < data_size)\
      {\
        PD_CLEAR_DATA();\
        \
        exception_s::throw_exception(it,module.error_base + c_error_PACK_DECODE_NOT_ENOUGH_DATA_BYTES,operands[c_source_pos_idx],(location_s *)it.blank_location);\
        return false;\
      }\
      \
      TYPE *d_ptr;\
      TYPE *d_ptr_end;\
      int d_step;\
      \
      if (change_byte_order)\
      {\
        /* - copy data with reversed byte order - */\
        char *ptr = data_buffer + data_size - 1;\
        char *ptr_end = data_buffer;\
        do\
        {\
          *ptr = *ds_ptr;\
        }\
        while(++ds_ptr,--ptr >= ptr_end);\
        \
        /* - initialize loop variables - */\
        d_ptr = (TYPE *)data_buffer + count - 1;\
        d_ptr_end = (TYPE *)data_buffer;\
        d_step = -1;\
      }\
      else\
      {\
        /* - copy data with preserved byte order - */\
        memcpy(data_buffer,ds_ptr,data_size);\
        ds_ptr += data_size;\
        \
        /* - initialize loop variables - */\
        d_ptr = (TYPE *)data_buffer;\
        d_ptr_end = (TYPE *)data_buffer + count - 1;\
        d_step = 1;\
      }\
      \
      do {\
        \
        /* - create new location and push it to result array - */\
        basic_64b v_data_ptr;\
        RETRIEVE_CODE;\
        BIC_CREATE_NEW_LOCATION(new_location,CLASS_TYPE,v_data_ptr);\
        array_ptr->push(new_location);\
        \
        if (d_ptr == d_ptr_end)\
        {\
          break;\
        }\
        \
        d_ptr += d_step;\
        \
      } while(true);\
      \
      if (data_buffer != temp_buffer)\
      {\
        cfree(data_buffer);\
        data_buffer = temp_buffer;\
      }\
    }\
    \
    count = 1;\
  }/*}}}*/

  char *ds_ptr = data_string_ptr->data;
  char *ds_ptr_end = ds_ptr + data_string_ptr->size - 1;

  if (format_string_ptr->size > 1)
  {
    char *f_ptr = format_string_ptr->data;
    char *old_f_ptr;

    bool change_byte_order = false;
    unsigned count = 1;

    const unsigned c_temp_size = 512;
    char temp_buffer[c_temp_size];

    char *data_buffer = temp_buffer;
    unsigned data_size = 0;

    unsigned ret_term;
    do
    {
      old_f_ptr = f_ptr;
      ret_term = pcd_terminal_recognize(&f_ptr);

      // - ERROR -
      if (ret_term == c_idx_not_exist)
      {
        PD_CLEAR_DATA();

        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PACK_CODE_WRONG_FORMAT_STRING,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(old_f_ptr - format_string_ptr->data);

        return false;
      }

      // - test end of format string -
      if (ret_term != PCD_TERM_END)
      {
        switch (ret_term)
        {
        case PCD_TERM_NUMBER:
        {/*{{{*/
          count = strtoll(old_f_ptr,NULL,10);
        }/*}}}*/
        break;
        case PCD_TERM_NATIVE:
        {/*{{{*/
          change_byte_order = false;
        }/*}}}*/
        break;
        case PCD_TERM_LITTLE_ENDIAN:
        {/*{{{*/
          change_byte_order = !c_little_endian;
        }/*}}}*/
        break;
        case PCD_TERM_BIG_ENDIAN:
        {/*{{{*/
          change_byte_order = !c_big_endian;
        }/*}}}*/
        break;
        case PCD_TERM_CHAR:
        {/*{{{*/
          PD_PROCESS_ELEMENT(char,c_bi_class_char,v_data_ptr = (basic_64b)*d_ptr);
        }/*}}}*/
        break;
        case PCD_TERM_SIGNED_BYTE:
        {/*{{{*/
          PD_PROCESS_ELEMENT(signed char,c_bi_class_integer,v_data_ptr = (basic_64b)(long long int)*d_ptr);
        }/*}}}*/
        break;
        case PCD_TERM_UNSIGNED_BYTE:
        {/*{{{*/
          PD_PROCESS_ELEMENT(unsigned char,c_bi_class_integer,v_data_ptr = (basic_64b)(long long int)*d_ptr);
        }/*}}}*/
        break;
        case PCD_TERM_SHORT:
        {/*{{{*/
          PD_PROCESS_ELEMENT(short,c_bi_class_integer,v_data_ptr = (basic_64b)(long long int)*d_ptr);
        }/*}}}*/
        break;
        case PCD_TERM_UNSIGNED_SHORT:
        {/*{{{*/
          PD_PROCESS_ELEMENT(unsigned short,c_bi_class_integer,v_data_ptr = (basic_64b)(long long int)*d_ptr);
        }/*}}}*/
        break;
        case PCD_TERM_INT:
        {/*{{{*/
          PD_PROCESS_ELEMENT(int,c_bi_class_integer,v_data_ptr = (basic_64b)(long long int)*d_ptr);
        }/*}}}*/
        break;
        case PCD_TERM_UNSIGNED:
        {/*{{{*/
          PD_PROCESS_ELEMENT(unsigned,c_bi_class_integer,v_data_ptr = (basic_64b)(long long int)*d_ptr);
        }/*}}}*/
        break;
        case PCD_TERM_LONG_INT:
        {/*{{{*/
          PD_PROCESS_ELEMENT(long int,c_bi_class_integer,v_data_ptr = (basic_64b)(long long int)*d_ptr);
        }/*}}}*/
        break;
        case PCD_TERM_LONG_UNSIGNED:
        {/*{{{*/
          PD_PROCESS_ELEMENT(long unsigned,c_bi_class_integer,v_data_ptr = (basic_64b)(long long int)*d_ptr);
        }/*}}}*/
        break;
        case PCD_TERM_LONG_LONG_INT:
        {/*{{{*/
          PD_PROCESS_ELEMENT(long long int,c_bi_class_integer,v_data_ptr = (basic_64b)(long long int)*d_ptr);
        }/*}}}*/
        break;
        case PCD_TERM_LONG_LONG_UNSIGNED:
        {/*{{{*/
          PD_PROCESS_ELEMENT(long long unsigned,c_bi_class_integer,v_data_ptr = (basic_64b)(long long int)*d_ptr);
        }/*}}}*/
        break;
        case PCD_TERM_FLOAT:
        {/*{{{*/
          PD_PROCESS_ELEMENT(float,c_bi_class_float,*((double *)&v_data_ptr) = *d_ptr);
        }/*}}}*/
        break;
        case PCD_TERM_DOUBLE:
        {/*{{{*/
          PD_PROCESS_ELEMENT(double,c_bi_class_float,*((double *)&v_data_ptr) = *d_ptr);
        }/*}}}*/
        break;
        case PCD_TERM_STRING:
        {/*{{{*/
          if (count > 0)
          {
            unsigned val_idx = 0;
            do
            {
              // - ERROR -
              if ((unsigned)(ds_ptr_end - ds_ptr) < sizeof(unsigned))
              {
                PD_CLEAR_DATA();

                exception_s::throw_exception(it,module.error_base + c_error_PACK_DECODE_NOT_ENOUGH_DATA_BYTES,operands[c_source_pos_idx],(location_s *)it.blank_location);
                return false;
              }

              unsigned string_length;

              if (change_byte_order)
              {
                // - copy string length with reversed byte order -
                char *sl_ptr_end = ds_ptr + sizeof(unsigned);
                char *ptr = (char *)&string_length + sizeof(unsigned);
                do
                {
                  *(--ptr) = *ds_ptr;
                }
                while(++ds_ptr < sl_ptr_end);
              }
              else
              {
                // - copy string length with preserved byte order -
                string_length = *((unsigned *)ds_ptr);
                ds_ptr += sizeof(unsigned);
              }

              // - ERROR -
              if ((unsigned)(ds_ptr_end - ds_ptr) < string_length)
              {
                PD_CLEAR_DATA();

                exception_s::throw_exception(it,module.error_base + c_error_PACK_DECODE_NOT_ENOUGH_DATA_BYTES,operands[c_source_pos_idx],(location_s *)it.blank_location);
                return false;
              }

              // - create string -
              string_s *string_ptr = it.get_new_string_ptr();

              // - copy string data -
              if (string_length > 0)
              {
                string_ptr->create(string_length);
                memcpy(string_ptr->data,ds_ptr,string_length);
                ds_ptr += string_length;
              }

              // - create new location and push it to result array -
              BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
              array_ptr->push(new_location);

            }
            while(++val_idx < count);
          }
        }/*}}}*/
        break;
        default:
          cassert(0);
        }
      }
    }
    while(ret_term != PCD_TERM_END);
  }

  // - create rest of data string -
  string_s *string_ptr = it.get_new_string_ptr();

  // - retrieve length of data string rest -
  unsigned length = ds_ptr_end - ds_ptr;

  // - copy rest of data string -
  if (length > 0)
  {
    string_ptr->create(length);
    memcpy(string_ptr->data,ds_ptr,length);
  }

  // - insert rest of data string to result array -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
  array_ptr->push(new_location);

  BIC_SET_RESULT(array_location);

  return true;
}/*}}}*/

bool bic_pack_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Pack"),"Pack");
  );

  return true;
}/*}}}*/

bool bic_pack_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("Pack");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

