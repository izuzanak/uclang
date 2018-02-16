
@begin
include "ucgcg_module.h"
@end

// - UCGCG indexes of built in classes -
unsigned c_bi_class_gcg_msg = c_idx_not_exist;

// - UCGCG module -
built_in_module_s module =
{/*{{{*/
  1,                     // Class count
  ucgcg_classes,         // Classes

  0,                     // Error base index
  3,                     // Error count
  ucgcg_error_strings,   // Error strings

  ucgcg_initialize,      // Initialize function
  ucgcg_print_exception, // Print exceptions function
};/*}}}*/

// - UCGCG classes -
built_in_class_s *ucgcg_classes[] =
{/*{{{*/
  &gcg_msg_class,
};/*}}}*/

// - UCGCG error strings -
const char *ucgcg_error_strings[] =
{/*{{{*/
  "error_GCG_INVALID_MESSAGE_HEAD",
  "error_GCG_INVALID_MESSAGE_TAIL",
  "error_GCG_INVALID_MESSAGE_CRC_CHECKSUM",
};/*}}}*/

// - UCGCG initialize -
bool ucgcg_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize gcg_msg class identifier -
  c_bi_class_gcg_msg = class_base_idx++;

  return true;
}/*}}}*/

// - UCGCG print exception -
bool ucgcg_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_GCG_INVALID_MESSAGE_HEAD:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nGCG invalid message head\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GCG_INVALID_MESSAGE_TAIL:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nGCG invalid message tail\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GCG_INVALID_MESSAGE_CRC_CHECKSUM:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nGCG invalid message CRC checksum\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class GCG_MSG -
built_in_class_s gcg_msg_class =
{/*{{{*/
  "GcgMsg",
  c_modifier_public | c_modifier_final,
  6, gcg_msg_methods,
  0, gcg_msg_variables,
  bic_gcg_msg_consts,
  bic_gcg_msg_init,
  bic_gcg_msg_clear,
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

built_in_method_s gcg_msg_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gcg_msg_operator_binary_equal
  },
  {
    "GcgMsg#1",
    c_modifier_public | c_modifier_final,
    bic_gcg_msg_method_GcgMsg_1
  },
  {
    "GcgMsg#2",
    c_modifier_public | c_modifier_final,
    bic_gcg_msg_method_GcgMsg_2
  },
  {
    "data#0",
    c_modifier_public | c_modifier_final,
    bic_gcg_msg_method_data_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gcg_msg_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gcg_msg_method_print_0
  },
};/*}}}*/

built_in_variable_s gcg_msg_variables[] =
{/*{{{*/
};/*}}}*/

void bic_gcg_msg_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_gcg_msg_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (gcg_msg_s *)nullptr;
}/*}}}*/

void bic_gcg_msg_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  gcg_msg_s *gm_ptr = (gcg_msg_s *)location_ptr->v_data_ptr;

  if (gm_ptr != nullptr)
  {
    gm_ptr->clear(it);
    cfree(gm_ptr);
  }
}/*}}}*/

bool bic_gcg_msg_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_gcg_msg_method_GcgMsg_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("GcgMsg#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  unsigned data_begin;
  gcg_msg_s::head_find(string_ptr->data,data_begin);

  // - ERROR -
  if (data_begin == c_idx_not_exist)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GCG_INVALID_MESSAGE_HEAD,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  unsigned crc_begin;
  unsigned data_end;
  gcg_msg_s::tail_find(string_ptr->data,string_ptr->size - 1,crc_begin,data_end);

  // - ERROR -
  if (crc_begin == c_idx_not_exist || data_end == c_idx_not_exist)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GCG_INVALID_MESSAGE_TAIL,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - compute crc value -
  unsigned crc_comp = 0;
  Crc32(&crc_comp,string_ptr->data + data_begin,data_end - data_begin + 1);

  // - retrieve message crc value -
  const char *ptr = string_ptr->data + crc_begin;
  char *end_ptr;
  unsigned crc_msg = strtoll(ptr,&end_ptr,16);

  // - ERROR -
  if (end_ptr - ptr != 8 || crc_msg != crc_comp)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GCG_INVALID_MESSAGE_CRC_CHECKSUM,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create gcg_msg object -
  gcg_msg_s *gm_ptr = (gcg_msg_s *)cmalloc(sizeof(gcg_msg_s));
  gm_ptr->init();

  // - set reference to data location -
  src_0_location->v_reference_cnt.atomic_inc();
  gm_ptr->data_loc = src_0_location;

  // - set gcg_msg destination location -
  dst_location->v_data_ptr = (gcg_msg_s *)gm_ptr;

  return true;
}/*}}}*/

bool bic_gcg_msg_method_GcgMsg_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  if (src_0_location->v_type != c_bi_class_string ||
      src_1_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("GcgMsg#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  string_s *header_ptr = (string_s *)src_0_location->v_data_ptr;
  string_s *body_ptr = (string_s *)src_1_location->v_data_ptr;

  // - create gcg_msg object -
  gcg_msg_s *gm_ptr = (gcg_msg_s *)cmalloc(sizeof(gcg_msg_s));
  gm_ptr->init();

  bc_array_s buffer;
  buffer.init_size(header_ptr->size - 1 + body_ptr->size - 1 + (12 + 10 + 9 + 10 + 2));

  unsigned data_begin = 1;
  buffer.append(12,"{\"MDHeader\":");
  buffer.append(header_ptr->size - 1,header_ptr->data);
  buffer.append(10,",\"MDBody\":");
  buffer.append(body_ptr->size - 1,body_ptr->data);
  unsigned data_size = buffer.used - data_begin;
  buffer.append(9,",\"mdFCS\":");
  unsigned fcs_begin = buffer.used;

  unsigned crc_value = 0;
  Crc32(&crc_value,buffer.data + data_begin,data_size);

  buffer.push_blanks(10);
  snprintf(buffer.data + fcs_begin,11,"\"%08X\"",crc_value);
  buffer.append(2,"}\0");

  // - just assert -
  cassert(buffer.size == buffer.used);

  string_s *data_ptr = it.get_new_string_ptr();
  data_ptr->data = buffer.data;
  data_ptr->size = buffer.used;

  BIC_CREATE_NEW_LOCATION(data_location,c_bi_class_string,data_ptr);
  gm_ptr->data_loc = data_location;

  // - set gcg_msg destination location -
  dst_location->v_data_ptr = (gcg_msg_s *)gm_ptr;

  return true;
}/*}}}*/

bool bic_gcg_msg_method_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  location_s *data_location = ((gcg_msg_s *)dst_location->v_data_ptr)->data_loc;
  data_location->v_reference_cnt.atomic_inc();

  BIC_SET_RESULT(data_location);

  return true;
}/*}}}*/

bool bic_gcg_msg_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("GcgMsg"),"GcgMsg")
  );

  return true;
}/*}}}*/

bool bic_gcg_msg_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("GcgMsg");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

