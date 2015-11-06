
@begin
include "adaptrain_module.h"
@end

// - ADAPTRAIN indexes of built in classes -
unsigned c_bi_class_ato_aru = c_idx_not_exist;
unsigned c_bi_class_ato_aru_record = c_idx_not_exist;
unsigned c_bi_class_optim_speed_profile = c_idx_not_exist;
unsigned c_bi_class_optim_line_section = c_idx_not_exist;
unsigned c_bi_class_optim_line_segment = c_idx_not_exist;
unsigned c_bi_class_ato_loco = c_idx_not_exist;
unsigned c_bi_class_ato_train = c_idx_not_exist;
unsigned c_bi_class_ato_trip = c_idx_not_exist;
unsigned c_bi_class_ato_trip_sec = c_idx_not_exist;
unsigned c_bi_class_ato_line_sec = c_idx_not_exist;
unsigned c_bi_class_ato_line_sec_point = c_idx_not_exist;

// - ADAPTRAIN module -
built_in_module_s module =
{/*{{{*/
  11,                        // Class count
  adaptrain_classes,         // Classes

  0,                         // Error base index
  16,                        // Error count
  adaptrain_error_strings,   // Error strings

  adaptrain_initialize,      // Initialize function
  adaptrain_print_exception, // Print exceptions function
};/*}}}*/

// - ADAPTRAIN classes -
built_in_class_s *adaptrain_classes[] =
{/*{{{*/
  &ato_aru_class,
  &ato_aru_record_class,
  &optim_speed_profile_class,
  &optim_line_section_class,
  &optim_line_segment_class,
  &ato_loco_class,
  &ato_train_class,
  &ato_trip_class,
  &ato_trip_sec_class,
  &ato_line_sec_class,
  &ato_line_sec_point_class,
};/*}}}*/

// - ADAPTRAIN error strings -
const char *adaptrain_error_strings[] =
{/*{{{*/
  "error_ATO_ARU_ARCHIVE_WRONG_DATA",
  "error_ATO_ARU_ARCHIVE_WRONG_COOKIE",
  "error_ATO_ARU_ARCHIVE_UNSUPPORTED_VALUE_TYPE",
  "error_ATO_ARU_ARCHIVE_INDEX_EXCEEDS_RANGE",
  "error_ATO_ARU_RECORD_UNSUPPORTED_VALUE_TYPE",
  "error_OPTIM_SPEED_PROFILE_WRONG_DATA",
  "error_OPTIM_LINE_SECTION_WRONG_DATA",
  "error_OPTIM_LINE_SECTION_INDEX_EXCEEDS_RANGE",
  "error_ATO_LOCO_WRONG_DATA",
  "error_ATO_TRAIN_WRONG_DATA",
  "error_ATO_TRIP_WRONG_DATA",
  "error_ATO_TRIP_WRONG_MD5_CHECKSUM",
  "error_ATO_TRIP_INDEX_EXCEEDS_RANGE",
  "error_ATO_LINE_SEC_WRONG_DATA",
  "error_ATO_LINE_SEC_WRONG_MD5_CHECKSUM",
  "error_ATO_LINE_SEC_INDEX_EXCEEDS_RANGE",
};/*}}}*/

// - ADAPTRAIN initialize -
bool adaptrain_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize ato_aru class identifier -
  c_bi_class_ato_aru = class_base_idx++;

  // - initialize ato_aru_record class identifier -
  c_bi_class_ato_aru_record = class_base_idx++;

  // - initialize optim_speed_profile class identifier -
  c_bi_class_optim_speed_profile = class_base_idx++;

  // - initialize optim_line_section class identifier -
  c_bi_class_optim_line_section = class_base_idx++;

  // - initialize optim_line_segment class identifier -
  c_bi_class_optim_line_segment = class_base_idx++;

  // - initialize ato_loco class identifier -
  c_bi_class_ato_loco = class_base_idx++;

  // - initialize ato_train class identifier -
  c_bi_class_ato_train = class_base_idx++;

  // - initialize ato_trip class identifier -
  c_bi_class_ato_trip = class_base_idx++;

  // - initialize ato_trip_sec class identifier -
  c_bi_class_ato_trip_sec = class_base_idx++;

  // - initialize ato_line_sec class identifier -
  c_bi_class_ato_line_sec = class_base_idx++;

  // - initialize ato_line_sec_point class identifier -
  c_bi_class_ato_line_sec_point = class_base_idx++;

  return true;
}/*}}}*/

// - ADAPTRAIN print exception -
bool adaptrain_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_ATO_ARU_ARCHIVE_WRONG_DATA:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong data of ATO ARU archive\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_ATO_ARU_ARCHIVE_WRONG_COOKIE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong cookie of ATO ARU archive\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_ATO_ARU_ARCHIVE_UNSUPPORTED_VALUE_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUnsupported ATO ARU archive value type %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_ATO_ARU_ARCHIVE_INDEX_EXCEEDS_RANGE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nIndex %" HOST_LL_FORMAT "d exceeds ATO ARU archive range\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_ATO_ARU_RECORD_UNSUPPORTED_VALUE_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUnsupported ATO ARU record value type %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_OPTIM_SPEED_PROFILE_WRONG_DATA:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong data of optim speed profile record\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_OPTIM_LINE_SECTION_WRONG_DATA:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong data of optim line section record\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_OPTIM_LINE_SECTION_INDEX_EXCEEDS_RANGE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nIndex %" HOST_LL_FORMAT "d exceeds optim line section range\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_ATO_LOCO_WRONG_DATA:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong data of ATO LOCO record\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_ATO_TRAIN_WRONG_DATA:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong data of ATO TRAIN record\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_ATO_TRIP_WRONG_DATA:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong data of ATO TRIP record\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_ATO_TRIP_WRONG_MD5_CHECKSUM:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong MD5 checksum of ATO TRIP record\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_ATO_TRIP_INDEX_EXCEEDS_RANGE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nIndex %" HOST_LL_FORMAT "d exceeds ATO TRIP range\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_ATO_LINE_SEC_WRONG_DATA:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong data of ATO LINE SECTION record\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_ATO_LINE_SEC_WRONG_MD5_CHECKSUM:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong MD5 checksum of ATO LINE SECTION record\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_ATO_LINE_SEC_INDEX_EXCEEDS_RANGE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nIndex %" HOST_LL_FORMAT "d exceeds ATO LINE SECTION range\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class ATO_ARU -
built_in_class_s ato_aru_class =
{/*{{{*/
  "AtoAru",
  c_modifier_public | c_modifier_final,
  12, ato_aru_methods,
  0, ato_aru_variables,
  bic_ato_aru_consts,
  bic_ato_aru_init,
  bic_ato_aru_clear,
  NULL,
  bic_ato_aru_length,
  bic_ato_aru_item,
  bic_ato_aru_first_idx,
  bic_ato_aru_next_idx,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s ato_aru_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_ato_aru_operator_binary_equal
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_ato_aru_operator_binary_le_br_re_br
  },
  {
    "AtoAru#1",
    c_modifier_public | c_modifier_final,
    bic_ato_aru_method_AtoAru_1
  },
  {
    "primary_key#0",
    c_modifier_public | c_modifier_final,
    bic_ato_aru_method_primary_key_0
  },
  {
    "first_x_value#0",
    c_modifier_public | c_modifier_final,
    bic_ato_aru_method_first_x_value_0
  },
  {
    "last_x_value#0",
    c_modifier_public | c_modifier_final,
    bic_ato_aru_method_last_x_value_0
  },
  {
    "item#1",
    c_modifier_public | c_modifier_final,
    bic_ato_aru_method_item_1
  },
  {
    "first_idx#0",
    c_modifier_public | c_modifier_final,
    bic_ato_aru_method_first_idx_0
  },
  {
    "next_idx#1",
    c_modifier_public | c_modifier_final,
    bic_ato_aru_method_next_idx_1
  },
  {
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_ato_aru_method_length_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ato_aru_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ato_aru_method_print_0
  },
};/*}}}*/

built_in_variable_s ato_aru_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_ATO_ARU_CHECK_INDEX() \
/*{{{*/\
ato_aru_s *aa_ptr = (ato_aru_s *)dst_location->v_data_ptr;\
\
/* - ERROR - */\
if (index < 0 || index >= aa_ptr->record_count) {\
  exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_ATO_ARU_ARCHIVE_INDEX_EXCEEDS_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
  new_exception->params.push(index);\
  \
  return false;\
}\
/*}}}*/\

#define BIC_ATO_ARU_ITEM(NAME) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
  \
  long long int index;\
  \
  /* - ERROR - */\
  if (!it.retrieve_integer(src_0_location,index))\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
    new_exception->params.push(1);\
    new_exception->params.push(src_0_location->v_type);\
    \
    return false;\
  }\
  \
  BIC_ATO_ARU_CHECK_INDEX();\
  \
  /* - create ato aru record object - */\
  ato_aru_record_s *aar_ptr = (ato_aru_record_s *)cmalloc(sizeof(ato_aru_record_s));\
  aar_ptr->init();\
\
  dst_location->v_reference_cnt.atomic_inc();\
  aar_ptr->ato_aru_loc = dst_location;\
  aar_ptr->index = index;\
\
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_ato_aru_record,aar_ptr);\
  BIC_SET_RESULT(new_location);\
\
  return true;\
}/*}}}*/

void bic_ato_aru_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_ato_aru_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)NULL;
}/*}}}*/

void bic_ato_aru_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  ato_aru_s *aa_ptr = (ato_aru_s *)location_ptr->v_data_ptr;

  if (aa_ptr != NULL)
  {
    aa_ptr->clear(it);
    cfree(aa_ptr);
  }
}/*}}}*/

unsigned bic_ato_aru_length(location_s *location_ptr)
{/*{{{*/
  ato_aru_s *aa_ptr = (ato_aru_s *)location_ptr->v_data_ptr;
  return aa_ptr->record_count;
}/*}}}*/

location_s *bic_ato_aru_item(interpreter_thread_s &it,location_s *location_ptr,unsigned index)
{/*{{{*/
  ato_aru_s *aa_ptr = (ato_aru_s *)location_ptr->v_data_ptr;

  // FIXME TODO check index ...
  cassert(index < aa_ptr->record_count);

  // - create ato aru record object -
  ato_aru_record_s *aar_ptr = (ato_aru_record_s *)cmalloc(sizeof(ato_aru_record_s));
  aar_ptr->init();

  location_ptr->v_reference_cnt.atomic_inc();
  aar_ptr->ato_aru_loc = location_ptr;
  aar_ptr->index = index;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_ato_aru_record,aar_ptr);

  return new_location;
}/*}}}*/

unsigned bic_ato_aru_first_idx(location_s *location_ptr)
{/*{{{*/
  ato_aru_s *aa_ptr = (ato_aru_s *)location_ptr->v_data_ptr;
  return aa_ptr->record_count > 0 ? 0 : c_idx_not_exist;
}/*}}}*/

unsigned bic_ato_aru_next_idx(location_s *location_ptr,unsigned index)
{/*{{{*/
  ato_aru_s *aa_ptr = (ato_aru_s *)location_ptr->v_data_ptr;

  // FIXME TODO check index ...
  cassert(index < aa_ptr->record_count);

  return (index + 1 < aa_ptr->record_count) ? index + 1 : c_idx_not_exist;
}/*}}}*/

bool bic_ato_aru_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_ato_aru_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_ARU_ITEM("operator_binary_le_br_re_br#1");
}/*}}}*/

bool bic_ato_aru_method_AtoAru_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("AtoAru#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create ato aru object -
  ato_aru_s *aa_ptr = (ato_aru_s *)cmalloc(sizeof(ato_aru_s));
  aa_ptr->init();

  // - ERROR -
  if (string_ptr->size - 1 < sizeof(sFILEARCH_HEAD))
  {
    aa_ptr->clear(it);
    cfree(aa_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_ATO_ARU_ARCHIVE_WRONG_DATA,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - process sFILEARCH_HEAD structure -
  sFILEARCH_HEAD &src_head = *((sFILEARCH_HEAD *)string_ptr->data);
  sFILEARCH_HEAD &head = aa_ptr->head;

  // - ERROR -
  if (memcmp(c_ato_aru_cookie,src_head.cookie,sizeof(c_ato_aru_cookie)) != 0)
  {
    aa_ptr->clear(it);
    cfree(aa_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_ATO_ARU_ARCHIVE_WRONG_COOKIE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  memcpy(&head,&src_head,sizeof(sFILEARCH_HEAD) - sizeof(sEVTARCH_HEAD));

#define FILEARCH_HEAD_COPY(NAME,TYPE) \
{/*{{{*/\
  memcpy_bo(&head.NAME,&src_head.NAME,sizeof(TYPE),c_little_endian);\
}/*}}}*/

  FILEARCH_HEAD_COPY(RepreCode,U16);
  FILEARCH_HEAD_COPY(MultConst,float);

  // - process sEVTARCH_HEAD structure -
  sEVTARCH_HEAD &src_std_head = src_head.stdHead;
  sEVTARCH_HEAD &std_head = head.stdHead;

#define EVTARCH_HEAD_COPY(NAME,TYPE) \
{/*{{{*/\
  memcpy_bo(&std_head.NAME,&src_std_head.NAME,sizeof(TYPE),c_little_endian);\
}/*}}}*/

  EVTARCH_HEAD_COPY(i32PK_Variable,I32);
  EVTARCH_HEAD_COPY(u16Year,U16);
  EVTARCH_HEAD_COPY(u16DataType,U16);
  EVTARCH_HEAD_COPY(VarAdr,U16);
  EVTARCH_HEAD_COPY(VarIndx,U16);
  EVTARCH_HEAD_COPY(i32ArchiveLen,I32);
  EVTARCH_HEAD_COPY(i32TotalEvents,I32);
  EVTARCH_HEAD_COPY(i32EventIndx,I32);
  EVTARCH_HEAD_COPY(r32FXValue,R32);
  EVTARCH_HEAD_COPY(r32LXValue,R32);
  EVTARCH_HEAD_COPY(u8Version,U8);
  EVTARCH_HEAD_COPY(u8FTimeStampms,U8);
  EVTARCH_HEAD_COPY(u8LTimeStampms,U8);
  EVTARCH_HEAD_COPY(u8VarLength,U8);

  // - retrieve record size -
  unsigned record_size;
  switch (std_head.u16DataType)
  {
    case TUDINT:
    case TDWORD:
      record_size = sizeof(sEVTARCH_RECORD_U32);
      break;
    case TREAL:
      record_size = sizeof(sEVTARCH_RECORD_R32);
      break;
    case TWORD:
    case TTDticks:
      record_size = sizeof(sEVTARCH_RECORD_U16);
      break;

    // - ERROR -
    default:
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_ATO_ARU_ARCHIVE_UNSUPPORTED_VALUE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(std_head.u16DataType);

      aa_ptr->clear(it);
      cfree(aa_ptr);

      return false;
  }
  
  // - compute record memory size -
  unsigned records_mem_size = std_head.i32TotalEvents*record_size;

  // - ERROR -
  if (std_head.i32TotalEvents < 0 || string_ptr->size - 1 < sizeof(sFILEARCH_HEAD) + records_mem_size)
  {
    aa_ptr->clear(it);
    cfree(aa_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_ATO_ARU_ARCHIVE_WRONG_DATA,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set record count -
  aa_ptr->record_count = std_head.i32TotalEvents;

  if (std_head.i32TotalEvents > 0)
  {
    // - allocate records memory -
    aa_ptr->records = cmalloc(records_mem_size);

#define EVTARCH_RECORD_COPY_BSWP(NAME,TYPE) \
{/*{{{*/\
    memcpy_bo(&t_ptr->NAME,&s_ptr->NAME,sizeof(TYPE),c_little_endian);\
}/*}}}*/

#define EVTARCH_RECORD_COPY(NAME,TYPE) \
{/*{{{*/\
    memcpy_bo(&t_ptr->NAME,&s_ptr->NAME,sizeof(TYPE),false);\
}/*}}}*/

    // - process archive records -
    switch (std_head.u16DataType)
    {
      case TUDINT:
        {/*{{{*/
          sEVTARCH_RECORD_U32 *s_ptr = (sEVTARCH_RECORD_U32 *)(string_ptr->data + sizeof(sFILEARCH_HEAD));
          sEVTARCH_RECORD_U32 *s_ptr_end = s_ptr + std_head.i32TotalEvents;
          sEVTARCH_RECORD_U32 *t_ptr = (sEVTARCH_RECORD_U32 *)aa_ptr->records;
          do {
            EVTARCH_RECORD_COPY_BSWP(r32XValue,R32);
            EVTARCH_RECORD_COPY_BSWP(u8TimeStampms,U8);
            EVTARCH_RECORD_COPY_BSWP(u8Status,U8);
            EVTARCH_RECORD_COPY_BSWP(u32Value,U32);
          } while(++t_ptr,++s_ptr < s_ptr_end);
        }/*}}}*/
        break;
      case TREAL:
        {/*{{{*/
          sEVTARCH_RECORD_R32 *s_ptr = (sEVTARCH_RECORD_R32 *)(string_ptr->data + sizeof(sFILEARCH_HEAD));
          sEVTARCH_RECORD_R32 *s_ptr_end = s_ptr + std_head.i32TotalEvents;
          sEVTARCH_RECORD_R32 *t_ptr = (sEVTARCH_RECORD_R32 *)aa_ptr->records;
          do {
            EVTARCH_RECORD_COPY_BSWP(r32XValue,R32);
            EVTARCH_RECORD_COPY_BSWP(u8TimeStampms,U8);
            EVTARCH_RECORD_COPY_BSWP(u8Status,U8);
            EVTARCH_RECORD_COPY_BSWP(r32Value,R32);
          } while(++t_ptr,++s_ptr < s_ptr_end);
        }/*}}}*/
        break;
      case TTDticks:
        {/*{{{*/
          sEVTARCH_RECORD_U16 *s_ptr = (sEVTARCH_RECORD_U16 *)(string_ptr->data + sizeof(sFILEARCH_HEAD));
          sEVTARCH_RECORD_U16 *s_ptr_end = s_ptr + std_head.i32TotalEvents;
          sEVTARCH_RECORD_U16 *t_ptr = (sEVTARCH_RECORD_U16 *)aa_ptr->records;
          do {
            EVTARCH_RECORD_COPY_BSWP(r32XValue,R32);
            EVTARCH_RECORD_COPY_BSWP(u8TimeStampms,U8);
            EVTARCH_RECORD_COPY_BSWP(u8Status,U8);
            EVTARCH_RECORD_COPY_BSWP(u16Value,U16);
          } while(++t_ptr,++s_ptr < s_ptr_end);
        }/*}}}*/
        break;
      case TWORD:
        {/*{{{*/
          sEVTARCH_RECORD_U16 *s_ptr = (sEVTARCH_RECORD_U16 *)(string_ptr->data + sizeof(sFILEARCH_HEAD));
          sEVTARCH_RECORD_U16 *s_ptr_end = s_ptr + std_head.i32TotalEvents;
          sEVTARCH_RECORD_U16 *t_ptr = (sEVTARCH_RECORD_U16 *)aa_ptr->records;
          do {
            EVTARCH_RECORD_COPY_BSWP(r32XValue,R32);
            EVTARCH_RECORD_COPY_BSWP(u8TimeStampms,U8);
            EVTARCH_RECORD_COPY_BSWP(u8Status,U8);
            EVTARCH_RECORD_COPY(u16Value,U16);
          } while(++t_ptr,++s_ptr < s_ptr_end);
        }/*}}}*/
        break;
      case TDWORD:
        {/*{{{*/
          sEVTARCH_RECORD_U32 *s_ptr = (sEVTARCH_RECORD_U32 *)(string_ptr->data + sizeof(sFILEARCH_HEAD));
          sEVTARCH_RECORD_U32 *s_ptr_end = s_ptr + std_head.i32TotalEvents;
          sEVTARCH_RECORD_U32 *t_ptr = (sEVTARCH_RECORD_U32 *)aa_ptr->records;
          do {
            EVTARCH_RECORD_COPY_BSWP(r32XValue,R32);
            EVTARCH_RECORD_COPY_BSWP(u8TimeStampms,U8);
            EVTARCH_RECORD_COPY_BSWP(u8Status,U8);
            EVTARCH_RECORD_COPY(u32Value,U32);
          } while(++t_ptr,++s_ptr < s_ptr_end);
        }/*}}}*/
        break;

      // - ERROR -
      default:
        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_ATO_ARU_ARCHIVE_UNSUPPORTED_VALUE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(std_head.u16DataType);

        aa_ptr->clear(it);
        cfree(aa_ptr);

        return false;
    }
  }

  dst_location->v_data_ptr = (basic_64b)aa_ptr;

  return true;
}/*}}}*/

bool bic_ato_aru_method_primary_key_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ato_aru_s *aa_ptr = (ato_aru_s *)dst_location->v_data_ptr;

  long long int result = aa_ptr->head.stdHead.i32PK_Variable;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_ato_aru_method_first_x_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ato_aru_s *aa_ptr = (ato_aru_s *)dst_location->v_data_ptr;

  double result = aa_ptr->head.stdHead.r32FXValue;

  basic_64b &v_data_ptr = *((basic_64b *)&result);
  BIC_SIMPLE_SET_RES(c_bi_class_float,v_data_ptr);

  return true;
}/*}}}*/

bool bic_ato_aru_method_last_x_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ato_aru_s *aa_ptr = (ato_aru_s *)dst_location->v_data_ptr;

  double result = aa_ptr->head.stdHead.r32LXValue;

  basic_64b &v_data_ptr = *((basic_64b *)&result);
  BIC_SIMPLE_SET_RES(c_bi_class_float,v_data_ptr);

  return true;
}/*}}}*/

bool bic_ato_aru_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_ARU_ITEM("item#1");
}/*}}}*/

bool bic_ato_aru_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ato_aru_s *aa_ptr = (ato_aru_s *)dst_location->v_data_ptr;

  if (aa_ptr->record_count > 0)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,0);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_ato_aru_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
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

  BIC_ATO_ARU_CHECK_INDEX();

  if (++index < aa_ptr->record_count)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,index);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_ato_aru_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ato_aru_s *aa_ptr = (ato_aru_s *)dst_location->v_data_ptr;
  long long int result = aa_ptr->record_count;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_ato_aru_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("AtoAru"),"AtoAru");
  );

  return true;
}/*}}}*/

bool bic_ato_aru_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("AtoAru");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class ATO_ARU_RECORD -
built_in_class_s ato_aru_record_class =
{/*{{{*/
  "AtoAruRecord",
  c_modifier_public | c_modifier_final,
  6, ato_aru_record_methods,
  0, ato_aru_record_variables,
  bic_ato_aru_record_consts,
  bic_ato_aru_record_init,
  bic_ato_aru_record_clear,
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

built_in_method_s ato_aru_record_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_ato_aru_record_operator_binary_equal
  },
  {
    "status#0",
    c_modifier_public | c_modifier_final,
    bic_ato_aru_record_method_status_0
  },
  {
    "x_value#0",
    c_modifier_public | c_modifier_final,
    bic_ato_aru_record_method_x_value_0
  },
  {
    "value#0",
    c_modifier_public | c_modifier_final,
    bic_ato_aru_record_method_value_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ato_aru_record_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ato_aru_record_method_print_0
  },
};/*}}}*/

built_in_variable_s ato_aru_record_variables[] =
{/*{{{*/
};/*}}}*/

void bic_ato_aru_record_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_ato_aru_record_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)NULL;
}/*}}}*/

void bic_ato_aru_record_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  ato_aru_record_s *aar_ptr = (ato_aru_record_s *)location_ptr->v_data_ptr;

  if (aar_ptr != NULL)
  {
    aar_ptr->clear(it);
    cfree(aar_ptr);
  }
}/*}}}*/

bool bic_ato_aru_record_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_ato_aru_record_method_status_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ato_aru_record_s *aar_ptr = (ato_aru_record_s *)dst_location->v_data_ptr;
  ato_aru_s *aa_ptr = (ato_aru_s *)aar_ptr->ato_aru_loc->v_data_ptr;

  long long int result;

  switch (aa_ptr->head.stdHead.u16DataType)
  {
    case TUDINT:
    case TDWORD:
      result = ((sEVTARCH_RECORD_U32 *)aa_ptr->records)[aar_ptr->index].u8Status;
      break;
    case TREAL:
      result = ((sEVTARCH_RECORD_R32 *)aa_ptr->records)[aar_ptr->index].u8Status;
      break;
    case TWORD:
    case TTDticks:
      result = ((sEVTARCH_RECORD_U16 *)aa_ptr->records)[aar_ptr->index].u8Status;
      break;

    // - ERROR -
    default:
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_ATO_ARU_RECORD_UNSUPPORTED_VALUE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(aa_ptr->head.stdHead.u16DataType);

      return false;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_ato_aru_record_method_x_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ato_aru_record_s *aar_ptr = (ato_aru_record_s *)dst_location->v_data_ptr;
  ato_aru_s *aa_ptr = (ato_aru_s *)aar_ptr->ato_aru_loc->v_data_ptr;

  double result;

  switch (aa_ptr->head.stdHead.u16DataType)
  {
    case TUDINT:
    case TDWORD:
      result = ((sEVTARCH_RECORD_U32 *)aa_ptr->records)[aar_ptr->index].r32XValue;
      break;
    case TREAL:
      result = ((sEVTARCH_RECORD_R32 *)aa_ptr->records)[aar_ptr->index].r32XValue;
      break;
    case TWORD:
    case TTDticks:
      result = ((sEVTARCH_RECORD_U16 *)aa_ptr->records)[aar_ptr->index].r32XValue;
      break;

    // - ERROR -
    default:
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_ATO_ARU_RECORD_UNSUPPORTED_VALUE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(aa_ptr->head.stdHead.u16DataType);

      return false;
  }

  basic_64b &v_data_ptr = *((basic_64b *)&result);
  BIC_SIMPLE_SET_RES(c_bi_class_float,v_data_ptr);

  return true;
}/*}}}*/

bool bic_ato_aru_record_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ato_aru_record_s *aar_ptr = (ato_aru_record_s *)dst_location->v_data_ptr;
  ato_aru_s *aa_ptr = (ato_aru_s *)aar_ptr->ato_aru_loc->v_data_ptr;

  switch (aa_ptr->head.stdHead.u16DataType)
  {
    case TUDINT:
    case TWORD:
    case TDWORD:
    case TTDticks:
      {
        long long int result;
        
        switch (aa_ptr->head.stdHead.u16DataType)
        {
          case TUDINT:
          case TDWORD:
            result = ((sEVTARCH_RECORD_U32 *)aa_ptr->records)[aar_ptr->index].u32Value;
            break;
          case TWORD:
          case TTDticks:
            result = ((sEVTARCH_RECORD_U16 *)aa_ptr->records)[aar_ptr->index].u16Value;
            break;
          default:
            cassert(0);
        }

        BIC_SIMPLE_SET_RES(c_bi_class_integer,result);
      }
      break;
    case TREAL:
      {
        double result = ((sEVTARCH_RECORD_R32 *)aa_ptr->records)[aar_ptr->index].r32Value;

        basic_64b &v_data_ptr = *((basic_64b *)&result);
        BIC_SIMPLE_SET_RES(c_bi_class_float,v_data_ptr);
      }
      break;

    // - ERROR -
    default:
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_ATO_ARU_RECORD_UNSUPPORTED_VALUE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(aa_ptr->head.stdHead.u16DataType);

      return false;
  }

  return true;
}/*}}}*/

bool bic_ato_aru_record_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("AtoAruRecord"),"AtoAruRecord");
  );

  return true;
}/*}}}*/

bool bic_ato_aru_record_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("AtoAruRecord");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class OPTIM_SPEED_PROFILE -
built_in_class_s optim_speed_profile_class =
{/*{{{*/
  "OptimSpeedProfile",
  c_modifier_public | c_modifier_final,
  9, optim_speed_profile_methods,
  0, optim_speed_profile_variables,
  bic_optim_speed_profile_consts,
  bic_optim_speed_profile_init,
  bic_optim_speed_profile_clear,
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

built_in_method_s optim_speed_profile_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_optim_speed_profile_operator_binary_equal
  },
  {
    "OptimSpeedProfile#1",
    c_modifier_public | c_modifier_final,
    bic_optim_speed_profile_method_OptimSpeedProfile_1
  },
  {
    "TripId#0",
    c_modifier_public | c_modifier_final,
    bic_optim_speed_profile_method_TripId_0
  },
  {
    "TimeStamp#0",
    c_modifier_public | c_modifier_final,
    bic_optim_speed_profile_method_TimeStamp_0
  },
  {
    "Version#0",
    c_modifier_public | c_modifier_final,
    bic_optim_speed_profile_method_Version_0
  },
  {
    "InitSectionIndx#0",
    c_modifier_public | c_modifier_final,
    bic_optim_speed_profile_method_InitSectionIndx_0
  },
  {
    "LineSectionIds#0",
    c_modifier_public | c_modifier_final,
    bic_optim_speed_profile_method_LineSectionIds_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_optim_speed_profile_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_optim_speed_profile_method_print_0
  },
};/*}}}*/

built_in_variable_s optim_speed_profile_variables[] =
{/*{{{*/
};/*}}}*/

void bic_optim_speed_profile_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_optim_speed_profile_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)NULL;
}/*}}}*/

void bic_optim_speed_profile_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  optim_speed_profile_s *osp_ptr = (optim_speed_profile_s *)location_ptr->v_data_ptr;

  if (osp_ptr != NULL)
  {
    osp_ptr->clear(it);
    cfree(osp_ptr);
  }
}/*}}}*/

bool bic_optim_speed_profile_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_optim_speed_profile_method_OptimSpeedProfile_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("OptimSpeedProfile#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create optim speed profile object -
  optim_speed_profile_s *osp_ptr = (optim_speed_profile_s *)cmalloc(sizeof(optim_speed_profile_s));
  osp_ptr->init();

  // - compute section name and optim profile header size -
  const unsigned c_section_name_size = sizeof(sOPTIM_SPEED_PROFILE::LineSectionIds[0]);
  const unsigned c_osp_head_size = sizeof(sOPTIM_SPEED_PROFILE) - c_section_name_size;

  // - ERROR -
  if (string_ptr->size - 1 < c_osp_head_size)
  {
    osp_ptr->clear(it);
    cfree(osp_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_OPTIM_SPEED_PROFILE_WRONG_DATA,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - process sOPTIM_SPEED_PROFILE structure -
  sOPTIM_SPEED_PROFILE &src_osp = *((sOPTIM_SPEED_PROFILE *)string_ptr->data);
  sOPTIM_SPEED_PROFILE &osp = osp_ptr->osp;

  memcpy(&osp,&src_osp,c_osp_head_size);

#define OPTIM_SPEED_PROFILE_COPY(NAME,TYPE) \
{/*{{{*/\
  memcpy_bo(&NAME,&src_ ## NAME,sizeof(TYPE),c_little_endian);\
}/*}}}*/

#define OPTIM_SPEED_PROFILE_DATETIME48_COPY(NAME) \
{/*{{{*/\
  OPTIM_SPEED_PROFILE_COPY(osp.NAME.seconds,U32);\
  OPTIM_SPEED_PROFILE_COPY(osp.NAME.ticks,U16);\
}/*}}}*/

  OPTIM_SPEED_PROFILE_DATETIME48_COPY(TimeStamp);

  OPTIM_SPEED_PROFILE_COPY(osp.Version,U16);
  OPTIM_SPEED_PROFILE_COPY(osp.HeadingSize,U16);
  OPTIM_SPEED_PROFILE_COPY(osp.InitSectionIndx,U16);
  OPTIM_SPEED_PROFILE_COPY(osp.NofSections,U16);

  pointer_array_s *array_ptr = it.get_new_array_ptr();
  BIC_CREATE_NEW_LOCATION(arr_location,c_bi_class_array,array_ptr);
  osp_ptr->sections_loc = arr_location;

  // - process optim speed profile sections -
  if (osp.NofSections > 0)
  {
    // - ERROR -
    if (string_ptr->size - 1 < c_osp_head_size + osp.NofSections*c_section_name_size)
    {
      osp_ptr->clear(it);
      cfree(osp_ptr);

      exception_s::throw_exception(it,module.error_base + c_error_OPTIM_SPEED_PROFILE_WRONG_DATA,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    char *ptr = string_ptr->data + c_osp_head_size;
    char *ptr_end = ptr + osp.NofSections*c_section_name_size;
    do {
      unsigned length = strnlen(ptr,c_section_name_size);

      // - retrieve section name -
      string_s *string_ptr = it.get_new_string_ptr();
      string_ptr->set(length,ptr);

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
      array_ptr->push(new_location);

    } while((ptr += c_section_name_size) < ptr_end);
  }

  dst_location->v_data_ptr = (basic_64b)osp_ptr;

  return true;
}/*}}}*/

bool bic_optim_speed_profile_method_TripId_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  optim_speed_profile_s *osp_ptr = (optim_speed_profile_s *)dst_location->v_data_ptr;

  unsigned length = strnlen(osp_ptr->osp.TripId,sizeof(sOPTIM_SPEED_PROFILE::TripId));

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(length,osp_ptr->osp.TripId);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_optim_speed_profile_method_TimeStamp_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  optim_speed_profile_s *osp_ptr = (optim_speed_profile_s *)dst_location->v_data_ptr;

  long long int result = time_stamp_to_nanosec(osp_ptr->osp.TimeStamp);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_optim_speed_profile_method_Version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  optim_speed_profile_s *osp_ptr = (optim_speed_profile_s *)dst_location->v_data_ptr;

  long long int result = osp_ptr->osp.Version;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_optim_speed_profile_method_InitSectionIndx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  optim_speed_profile_s *osp_ptr = (optim_speed_profile_s *)dst_location->v_data_ptr;

  long long int result = osp_ptr->osp.InitSectionIndx;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_optim_speed_profile_method_LineSectionIds_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  optim_speed_profile_s *osp_ptr = (optim_speed_profile_s *)dst_location->v_data_ptr;

  osp_ptr->sections_loc->v_reference_cnt.atomic_inc();

  BIC_SET_RESULT(osp_ptr->sections_loc);

  return true;
}/*}}}*/

bool bic_optim_speed_profile_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("OptimSpeedProfile"),"OptimSpeedProfile");
  );

  return true;
}/*}}}*/

bool bic_optim_speed_profile_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("OptimSpeedProfile");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class OPTIM_LINE_SECTION -
built_in_class_s optim_line_section_class =
{/*{{{*/
  "OptimLineSection",
  c_modifier_public | c_modifier_final,
  12, optim_line_section_methods,
  0, optim_line_section_variables,
  bic_optim_line_section_consts,
  bic_optim_line_section_init,
  bic_optim_line_section_clear,
  NULL,
  bic_optim_line_section_length,
  bic_optim_line_section_item,
  bic_optim_line_section_first_idx,
  bic_optim_line_section_next_idx,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s optim_line_section_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_optim_line_section_operator_binary_equal
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_optim_line_section_operator_binary_le_br_re_br
  },
  {
    "OptimLineSection#1",
    c_modifier_public | c_modifier_final,
    bic_optim_line_section_method_OptimLineSection_1
  },
  {
    "LineSectionId#0",
    c_modifier_public | c_modifier_final,
    bic_optim_line_section_method_LineSectionId_0
  },
  {
    "TimeStamp#0",
    c_modifier_public | c_modifier_final,
    bic_optim_line_section_method_TimeStamp_0
  },
  {
    "Version#0",
    c_modifier_public | c_modifier_final,
    bic_optim_line_section_method_Version_0
  },
  {
    "item#1",
    c_modifier_public | c_modifier_final,
    bic_optim_line_section_method_item_1
  },
  {
    "first_idx#0",
    c_modifier_public | c_modifier_final,
    bic_optim_line_section_method_first_idx_0
  },
  {
    "next_idx#1",
    c_modifier_public | c_modifier_final,
    bic_optim_line_section_method_next_idx_1
  },
  {
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_optim_line_section_method_length_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_optim_line_section_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_optim_line_section_method_print_0
  },
};/*}}}*/

built_in_variable_s optim_line_section_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_OPTIM_LINE_SECTION_CHECK_INDEX() \
/*{{{*/\
optim_line_section_s *ols_ptr = (optim_line_section_s *)dst_location->v_data_ptr;\
\
/* - ERROR - */\
if (index < 0 || index >= ols_ptr->ols.NofLineSegments) {\
  exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_OPTIM_LINE_SECTION_INDEX_EXCEEDS_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
  new_exception->params.push(index);\
  \
  return false;\
}\
/*}}}*/\

#define BIC_OPTIM_LINE_SECTION_ITEM(NAME) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
  \
  long long int index;\
  \
  /* - ERROR - */\
  if (!it.retrieve_integer(src_0_location,index))\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
    new_exception->params.push(1);\
    new_exception->params.push(src_0_location->v_type);\
    \
    return false;\
  }\
  \
  BIC_OPTIM_LINE_SECTION_CHECK_INDEX();\
  \
  /* - create optim line segment object - */\
  optim_line_segment_s *olseg_ptr = (optim_line_segment_s *)cmalloc(sizeof(optim_line_segment_s));\
  olseg_ptr->init();\
\
  dst_location->v_reference_cnt.atomic_inc();\
  olseg_ptr->ols_loc = dst_location;\
  olseg_ptr->index = index;\
\
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_optim_line_segment,olseg_ptr);\
  BIC_SET_RESULT(new_location);\
\
  return true;\
}/*}}}*/

void bic_optim_line_section_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_optim_line_section_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)NULL;
}/*}}}*/

void bic_optim_line_section_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  optim_line_section_s *ols_ptr = (optim_line_section_s *)location_ptr->v_data_ptr;

  if (ols_ptr != NULL)
  {
    ols_ptr->clear(it);
    cfree(ols_ptr);
  }
}/*}}}*/

unsigned bic_optim_line_section_length(location_s *location_ptr)
{/*{{{*/
  optim_line_section_s *ols_ptr = (optim_line_section_s *)location_ptr->v_data_ptr;
  return ols_ptr->ols.NofLineSegments;
}/*}}}*/

location_s *bic_optim_line_section_item(interpreter_thread_s &it,location_s *location_ptr,unsigned index)
{/*{{{*/
  optim_line_section_s *ols_ptr = (optim_line_section_s *)location_ptr->v_data_ptr;

  // FIXME TODO check index ...
  cassert(index < ols_ptr->ols.NofLineSegments);

  // - create optim line segment object -
  optim_line_segment_s *olseg_ptr = (optim_line_segment_s *)cmalloc(sizeof(optim_line_segment_s));
  olseg_ptr->init();

  location_ptr->v_reference_cnt.atomic_inc();
  olseg_ptr->ols_loc = location_ptr;
  olseg_ptr->index = index;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_optim_line_segment,olseg_ptr);

  return new_location;
}/*}}}*/

unsigned bic_optim_line_section_first_idx(location_s *location_ptr)
{/*{{{*/
  optim_line_section_s *ols_ptr = (optim_line_section_s *)location_ptr->v_data_ptr;
  return ols_ptr->ols.NofLineSegments > 0 ? 0 : c_idx_not_exist;
}/*}}}*/

unsigned bic_optim_line_section_next_idx(location_s *location_ptr,unsigned index)
{/*{{{*/
  optim_line_section_s *ols_ptr = (optim_line_section_s *)location_ptr->v_data_ptr;

  // FIXME TODO check index ...
  cassert(index < ols_ptr->ols.NofLineSegments);

  return (index + 1 < ols_ptr->ols.NofLineSegments) ? index + 1 : c_idx_not_exist;
}/*}}}*/

bool bic_optim_line_section_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_optim_line_section_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_OPTIM_LINE_SECTION_ITEM("operator_binary_le_br_re_br#1");
}/*}}}*/

bool bic_optim_line_section_method_OptimLineSection_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("OptimLineSection#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create optim line section object -
  optim_line_section_s *ols_ptr = (optim_line_section_s *)cmalloc(sizeof(optim_line_section_s));
  ols_ptr->init();

  // - compute optim line header size -
  const unsigned c_ols_head_size = sizeof(sOPTIM_LINE_SECTION) - sizeof(sOPTIM_LINE_SEGMENT);

  // - ERROR -
  if (string_ptr->size - 1 < c_ols_head_size)
  {
    ols_ptr->clear(it);
    cfree(ols_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_OPTIM_LINE_SECTION_WRONG_DATA,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - process sOPTIM_LINE_SECTION structure -
  sOPTIM_LINE_SECTION &src_ols = *((sOPTIM_LINE_SECTION *)string_ptr->data);
  sOPTIM_LINE_SECTION &ols = ols_ptr->ols;

  memcpy(&ols,&src_ols,c_ols_head_size);

#define OPTIM_LINE_SECTION_COPY(NAME,TYPE) \
{/*{{{*/\
  memcpy_bo(&NAME,&src_ ## NAME,sizeof(TYPE),c_little_endian);\
}/*}}}*/

#define OPTIM_LINE_SECTION_DATETIME48_COPY(NAME) \
{/*{{{*/\
  OPTIM_LINE_SECTION_COPY(ols.NAME.seconds,U32);\
  OPTIM_LINE_SECTION_COPY(ols.NAME.ticks,U16);\
}/*}}}*/

  OPTIM_LINE_SECTION_DATETIME48_COPY(TimeStamp);

  OPTIM_LINE_SECTION_COPY(ols.Version,U16);
  OPTIM_LINE_SECTION_COPY(ols.HeadingSize,U16);
  OPTIM_LINE_SECTION_COPY(ols.LineSegmentOptSize,U16);
  OPTIM_LINE_SECTION_COPY(ols.NofLineSegments,U16);

  if (ols.NofLineSegments > 0)
  {
    // - compute segments memory size -
    unsigned segments_mem_size = ols.NofLineSegments*sizeof(sOPTIM_LINE_SEGMENT);

    // - ERROR -
    if (string_ptr->size - 1 < c_ols_head_size + segments_mem_size)
    {
      ols_ptr->clear(it);
      cfree(ols_ptr);

      exception_s::throw_exception(it,module.error_base + c_error_OPTIM_LINE_SECTION_WRONG_DATA,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    // - allocate segments memory -
    ols_ptr->segments = (sOPTIM_LINE_SEGMENT *)cmalloc(segments_mem_size);

    sOPTIM_LINE_SEGMENT *s_ptr = (sOPTIM_LINE_SEGMENT *)(string_ptr->data + c_ols_head_size);
    sOPTIM_LINE_SEGMENT *s_ptr_end = s_ptr + ols.NofLineSegments;
    sOPTIM_LINE_SEGMENT *t_ptr = ols_ptr->segments;

#define OPTIM_LINE_SEGMENT_COPY(NAME,TYPE) \
{/*{{{*/\
  memcpy_bo(&t_ptr->NAME,&s_ptr->NAME,sizeof(TYPE),c_little_endian);\
}/*}}}*/

    do {
      OPTIM_LINE_SEGMENT_COPY(LPindx,U16);
      OPTIM_LINE_SEGMENT_COPY(LPindxR,U16);
      OPTIM_LINE_SEGMENT_COPY(Dist2RefLP,R32);

      memcpy(t_ptr->DrivingMode,s_ptr->DrivingMode,4*sizeof(U8));

      OPTIM_LINE_SEGMENT_COPY(TargLPindx,U16);
      OPTIM_LINE_SEGMENT_COPY(TargLPindxR,U16);
      OPTIM_LINE_SEGMENT_COPY(SegmentLength,R32);
      OPTIM_LINE_SEGMENT_COPY(RunningTime,R32);
      OPTIM_LINE_SEGMENT_COPY(RunningTimeMin,R32);
      OPTIM_LINE_SEGMENT_COPY(TargSpeed,R32);
      OPTIM_LINE_SEGMENT_COPY(BegSpeed,R32);
      OPTIM_LINE_SEGMENT_COPY(MeanAcceleration,R32);
      OPTIM_LINE_SEGMENT_COPY(PeakAcceleration,R32);
      OPTIM_LINE_SEGMENT_COPY(TravelTime2Stat,R32);
      OPTIM_LINE_SEGMENT_COPY(TravelTime2StatMin,R32);
    } while(++t_ptr,++s_ptr < s_ptr_end);
  }

  dst_location->v_data_ptr = (basic_64b)ols_ptr;

  return true;
}/*}}}*/

bool bic_optim_line_section_method_LineSectionId_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  optim_line_section_s *ols_ptr = (optim_line_section_s *)dst_location->v_data_ptr;

  unsigned length = strnlen(ols_ptr->ols.LineSectionId,sizeof(sOPTIM_LINE_SECTION::LineSectionId));

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(length,ols_ptr->ols.LineSectionId);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_optim_line_section_method_TimeStamp_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  optim_line_section_s *ols_ptr = (optim_line_section_s *)dst_location->v_data_ptr;

  long long int result = time_stamp_to_nanosec(ols_ptr->ols.TimeStamp);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_optim_line_section_method_Version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  optim_line_section_s *ols_ptr = (optim_line_section_s *)dst_location->v_data_ptr;

  long long int result = ols_ptr->ols.Version;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_optim_line_section_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_OPTIM_LINE_SECTION_ITEM("item#1");
}/*}}}*/

bool bic_optim_line_section_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  optim_line_section_s *ols_ptr = (optim_line_section_s *)dst_location->v_data_ptr;

  if (ols_ptr->ols.NofLineSegments > 0)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,0);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_optim_line_section_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
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

  BIC_OPTIM_LINE_SECTION_CHECK_INDEX();

  if (++index < ols_ptr->ols.NofLineSegments)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,index);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_optim_line_section_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  optim_line_section_s *ols_ptr = (optim_line_section_s *)dst_location->v_data_ptr;
  long long int result = ols_ptr->ols.NofLineSegments;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_optim_line_section_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("OptimLineSection"),"OptimLineSection");
  );

  return true;
}/*}}}*/

bool bic_optim_line_section_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("OptimLineSection");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class OPTIM_LINE_SEGMENT -
built_in_class_s optim_line_segment_class =
{/*{{{*/
  "OptimLineSegment",
  c_modifier_public | c_modifier_final,
  19, optim_line_segment_methods,
  6, optim_line_segment_variables,
  bic_optim_line_segment_consts,
  bic_optim_line_segment_init,
  bic_optim_line_segment_clear,
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

built_in_method_s optim_line_segment_methods[] =
{/*{{{*/
  { 
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_optim_line_segment_operator_binary_equal
  },
  { 
    "LPindx#0",
    c_modifier_public | c_modifier_final,
    bic_optim_line_segment_method_LPindx_0
  },
  { 
    "LPindxR#0",
    c_modifier_public | c_modifier_final,
    bic_optim_line_segment_method_LPindxR_0
  },
  { 
    "Dist2RefLP#0",
    c_modifier_public | c_modifier_final,
    bic_optim_line_segment_method_Dist2RefLP_0
  },
  { 
    "DrivingMode#0",
    c_modifier_public | c_modifier_final,
    bic_optim_line_segment_method_DrivingMode_0
  },
  { 
    "TargLPindx#0",
    c_modifier_public | c_modifier_final,
    bic_optim_line_segment_method_TargLPindx_0
  },
  { 
    "TargLPindxR#0",
    c_modifier_public | c_modifier_final,
    bic_optim_line_segment_method_TargLPindxR_0
  },
  { 
    "SegmentLength#0",
    c_modifier_public | c_modifier_final,
    bic_optim_line_segment_method_SegmentLength_0
  },
  { 
    "RunningTime#0",
    c_modifier_public | c_modifier_final,
    bic_optim_line_segment_method_RunningTime_0
  },
  { 
    "RunningTimeMin#0",
    c_modifier_public | c_modifier_final,
    bic_optim_line_segment_method_RunningTimeMin_0
  },
  { 
    "TargSpeed#0",
    c_modifier_public | c_modifier_final,
    bic_optim_line_segment_method_TargSpeed_0
  },
  { 
    "BegSpeed#0",
    c_modifier_public | c_modifier_final,
    bic_optim_line_segment_method_BegSpeed_0
  },
  { 
    "MeanAcceleration#0",
    c_modifier_public | c_modifier_final,
    bic_optim_line_segment_method_MeanAcceleration_0
  },
  { 
    "PeakAcceleration#0",
    c_modifier_public | c_modifier_final,
    bic_optim_line_segment_method_PeakAcceleration_0
  },
  { 
    "TravelTime2Stat#0",
    c_modifier_public | c_modifier_final,
    bic_optim_line_segment_method_TravelTime2Stat_0
  },
  { 
    "TravelTime2StatMin#0",
    c_modifier_public | c_modifier_final,
    bic_optim_line_segment_method_TravelTime2StatMin_0
  },
  { 
    "items#0",
    c_modifier_public | c_modifier_final,
    bic_optim_line_segment_method_items_0
  },
  { 
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_optim_line_segment_method_to_string_0
  },
  { 
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_optim_line_segment_method_print_0
  },
};/*}}}*/

built_in_variable_s optim_line_segment_variables[] =
{/*{{{*/
  { "VALID_SEG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ACCELER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CRUISING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "DECELER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "COASTING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "REGENBRAK", c_modifier_public | c_modifier_static | c_modifier_static_const },
};/*}}}*/

#define BIC_OPTIM_LINE_SEGMENT_INTEGER_VALUE(NAME)\
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  optim_line_segment_s *olseg_ptr = (optim_line_segment_s *)dst_location->v_data_ptr;\
  optim_line_section_s *ols_ptr = (optim_line_section_s *)olseg_ptr->ols_loc->v_data_ptr;\
\
  long long int result = ols_ptr->segments[olseg_ptr->index].NAME;\
\
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
\
  return true;\
}/*}}}*/

#define BIC_OPTIM_LINE_SEGMENT_FLOAT_VALUE(NAME)\
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  optim_line_segment_s *olseg_ptr = (optim_line_segment_s *)dst_location->v_data_ptr;\
  optim_line_section_s *ols_ptr = (optim_line_section_s *)olseg_ptr->ols_loc->v_data_ptr;\
\
  double result = ols_ptr->segments[olseg_ptr->index].NAME;\
\
  basic_64b &v_data_ptr = *((basic_64b *)&result);\
  BIC_SIMPLE_SET_RES(c_bi_class_float,v_data_ptr);\
\
  return true;\
}/*}}}*/

void bic_optim_line_segment_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert optim line segment driving mode identifiers -
  {
    const_locations.push_blanks(6);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 6);

#define CREATE_OPTIM_LINE_SEGMENT_DRIVING_MODE_IDENTIFIER(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (basic_64b)VALUE;\
  cv_ptr++;

    CREATE_OPTIM_LINE_SEGMENT_DRIVING_MODE_IDENTIFIER(OPT_I_VALID_SEG);
    CREATE_OPTIM_LINE_SEGMENT_DRIVING_MODE_IDENTIFIER(OPT_I_ACCELER);
    CREATE_OPTIM_LINE_SEGMENT_DRIVING_MODE_IDENTIFIER(OPT_I_CRUISING);
    CREATE_OPTIM_LINE_SEGMENT_DRIVING_MODE_IDENTIFIER(OPT_I_DECELER);
    CREATE_OPTIM_LINE_SEGMENT_DRIVING_MODE_IDENTIFIER(OPT_I_COASTING);
    CREATE_OPTIM_LINE_SEGMENT_DRIVING_MODE_IDENTIFIER(OPT_I_REGENBRAK);
  }

}/*}}}*/

void bic_optim_line_segment_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)NULL;
}/*}}}*/

void bic_optim_line_segment_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  optim_line_segment_s *olseg_ptr = (optim_line_segment_s *)location_ptr->v_data_ptr;

  if (olseg_ptr != NULL)
  {
    olseg_ptr->clear(it);
    cfree(olseg_ptr);
  }
}/*}}}*/

bool bic_optim_line_segment_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_optim_line_segment_method_LPindx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_OPTIM_LINE_SEGMENT_INTEGER_VALUE(LPindx);
}/*}}}*/

bool bic_optim_line_segment_method_LPindxR_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_OPTIM_LINE_SEGMENT_INTEGER_VALUE(LPindxR);
}/*}}}*/

bool bic_optim_line_segment_method_Dist2RefLP_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_OPTIM_LINE_SEGMENT_FLOAT_VALUE(Dist2RefLP);
}/*}}}*/

bool bic_optim_line_segment_method_DrivingMode_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_OPTIM_LINE_SEGMENT_INTEGER_VALUE(DrivingMode[0]);
}/*}}}*/

bool bic_optim_line_segment_method_TargLPindx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_OPTIM_LINE_SEGMENT_INTEGER_VALUE(TargLPindx);
}/*}}}*/

bool bic_optim_line_segment_method_TargLPindxR_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_OPTIM_LINE_SEGMENT_INTEGER_VALUE(TargLPindxR);
}/*}}}*/

bool bic_optim_line_segment_method_SegmentLength_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_OPTIM_LINE_SEGMENT_FLOAT_VALUE(SegmentLength);
}/*}}}*/

bool bic_optim_line_segment_method_RunningTime_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_OPTIM_LINE_SEGMENT_FLOAT_VALUE(RunningTime);
}/*}}}*/

bool bic_optim_line_segment_method_RunningTimeMin_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_OPTIM_LINE_SEGMENT_FLOAT_VALUE(RunningTimeMin);
}/*}}}*/

bool bic_optim_line_segment_method_TargSpeed_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_OPTIM_LINE_SEGMENT_FLOAT_VALUE(TargSpeed);
}/*}}}*/

bool bic_optim_line_segment_method_BegSpeed_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_OPTIM_LINE_SEGMENT_FLOAT_VALUE(BegSpeed);
}/*}}}*/

bool bic_optim_line_segment_method_MeanAcceleration_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_OPTIM_LINE_SEGMENT_FLOAT_VALUE(MeanAcceleration);
}/*}}}*/

bool bic_optim_line_segment_method_PeakAcceleration_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_OPTIM_LINE_SEGMENT_FLOAT_VALUE(PeakAcceleration);
}/*}}}*/

bool bic_optim_line_segment_method_TravelTime2Stat_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_OPTIM_LINE_SEGMENT_FLOAT_VALUE(TravelTime2Stat);
}/*}}}*/

bool bic_optim_line_segment_method_TravelTime2StatMin_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_OPTIM_LINE_SEGMENT_FLOAT_VALUE(TravelTime2StatMin);
}/*}}}*/

bool bic_optim_line_segment_method_items_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  optim_line_segment_s *olseg_ptr = (optim_line_segment_s *)dst_location->v_data_ptr;
  optim_line_section_s *ols_ptr = (optim_line_section_s *)olseg_ptr->ols_loc->v_data_ptr;

  sOPTIM_LINE_SEGMENT &segment = ols_ptr->segments[olseg_ptr->index];
  pointer_array_s *array_ptr = it.get_new_array_ptr();

#define BIC_OPTIM_LINE_SEGMENT_ITEMS_GET_INTEGER(NAME) \
{/*{{{*/\
  long long int result = segment.NAME;\
\
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,result);\
  array_ptr->push(new_location);\
}/*}}}*/

#define BIC_OPTIM_LINE_SEGMENT_ITEMS_GET_FLOAT(NAME) \
{/*{{{*/\
  double result = segment.NAME;\
  basic_64b &v_data_ptr = *((basic_64b *)&result);\
\
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_float,v_data_ptr);\
  array_ptr->push(new_location);\
}/*}}}*/

  BIC_OPTIM_LINE_SEGMENT_ITEMS_GET_INTEGER(LPindx);
  BIC_OPTIM_LINE_SEGMENT_ITEMS_GET_INTEGER(LPindxR);
  BIC_OPTIM_LINE_SEGMENT_ITEMS_GET_FLOAT(Dist2RefLP);
  BIC_OPTIM_LINE_SEGMENT_ITEMS_GET_INTEGER(DrivingMode[0]);
  BIC_OPTIM_LINE_SEGMENT_ITEMS_GET_INTEGER(TargLPindx);
  BIC_OPTIM_LINE_SEGMENT_ITEMS_GET_INTEGER(TargLPindxR);
  BIC_OPTIM_LINE_SEGMENT_ITEMS_GET_FLOAT(SegmentLength);
  BIC_OPTIM_LINE_SEGMENT_ITEMS_GET_FLOAT(RunningTime);
  BIC_OPTIM_LINE_SEGMENT_ITEMS_GET_FLOAT(RunningTimeMin);
  BIC_OPTIM_LINE_SEGMENT_ITEMS_GET_FLOAT(TargSpeed);
  BIC_OPTIM_LINE_SEGMENT_ITEMS_GET_FLOAT(BegSpeed);
  BIC_OPTIM_LINE_SEGMENT_ITEMS_GET_FLOAT(MeanAcceleration);
  BIC_OPTIM_LINE_SEGMENT_ITEMS_GET_FLOAT(PeakAcceleration);
  BIC_OPTIM_LINE_SEGMENT_ITEMS_GET_FLOAT(TravelTime2Stat);
  BIC_OPTIM_LINE_SEGMENT_ITEMS_GET_FLOAT(TravelTime2StatMin);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_optim_line_segment_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("OptimLineSegment"),"OptimLineSegment");
  );

  return true;
}/*}}}*/

bool bic_optim_line_segment_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("OptimLineSegment");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class ATO_LOCO -
built_in_class_s ato_loco_class =
{/*{{{*/
  "AtoLoco",
  c_modifier_public | c_modifier_final,
  9, ato_loco_methods,
  0, ato_loco_variables,
  bic_ato_loco_consts,
  bic_ato_loco_init,
  bic_ato_loco_clear,
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

built_in_method_s ato_loco_methods[] =
{/*{{{*/
  { 
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_ato_loco_operator_binary_equal
  },
  { 
    "AtoLoco#1",
    c_modifier_public | c_modifier_final,
    bic_ato_loco_method_AtoLoco_1
  },
  { 
    "LocoId#0",
    c_modifier_public | c_modifier_final,
    bic_ato_loco_method_LocoId_0
  },
  { 
    "LocoType#0",
    c_modifier_public | c_modifier_final,
    bic_ato_loco_method_LocoType_0
  },
  { 
    "UIC_Id#0",
    c_modifier_public | c_modifier_final,
    bic_ato_loco_method_UIC_Id_0
  },
  { 
    "TimeStamp#0",
    c_modifier_public | c_modifier_final,
    bic_ato_loco_method_TimeStamp_0
  },
  { 
    "Version#0",
    c_modifier_public | c_modifier_final,
    bic_ato_loco_method_Version_0
  },
  { 
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ato_loco_method_to_string_0
  },
  { 
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ato_loco_method_print_0
  },
};/*}}}*/

built_in_variable_s ato_loco_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_ATO_LOCO_STRING_VALUE(NAME)\
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  ato_loco_s *loco_ptr = (ato_loco_s *)dst_location->v_data_ptr;\
\
  unsigned length = strnlen(loco_ptr->loco.NAME,sizeof(sLOCO::NAME));\
\
  string_s *string_ptr = it.get_new_string_ptr();\
  string_ptr->set(length,loco_ptr->loco.NAME);\
\
  BIC_SET_RESULT_STRING(string_ptr);\
\
  return true;\
}/*}}}*/

void bic_ato_loco_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_ato_loco_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)NULL;
}/*}}}*/

void bic_ato_loco_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  ato_loco_s *loco_ptr = (ato_loco_s *)location_ptr->v_data_ptr;

  if (loco_ptr != NULL)
  {
    loco_ptr->clear(it);
    cfree(loco_ptr);
  }
}/*}}}*/

bool bic_ato_loco_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_ato_loco_method_AtoLoco_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("AtoLoco#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create ato loco object -
  ato_loco_s *loco_ptr = (ato_loco_s *)cmalloc(sizeof(ato_loco_s));
  loco_ptr->init();

  // - compute loco header size -
  const unsigned c_loco_head_size = sizeof(sLOCO) - sizeof(R32);

  // - ERROR -
  if (string_ptr->size - 1 < c_loco_head_size)
  {
    loco_ptr->clear(it);
    cfree(loco_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_ATO_LOCO_WRONG_DATA,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - process sLOCO structure -
  sLOCO &src_loco = *((sLOCO *)string_ptr->data);
  sLOCO &loco = loco_ptr->loco;

#define ATO_LOCO_COPY(NAME,TYPE) \
{/*{{{*/\
  memcpy_bo(&NAME,&src_ ## NAME,sizeof(TYPE),c_little_endian);\
}/*}}}*/

#define ATO_LOCO_DATETIME48_COPY(NAME) \
{/*{{{*/\
  ATO_LOCO_COPY(loco.NAME.seconds,U32);\
  ATO_LOCO_COPY(loco.NAME.ticks,U16);\
}/*}}}*/

  memcpy(loco.MD5digest,src_loco.MD5digest,sizeof(sLOCO::MD5digest));
  memcpy(loco.LocoId,src_loco.LocoId,sizeof(sLOCO::LocoId));
  memcpy(loco.LocoType,src_loco.LocoType,sizeof(sLOCO::LocoType));
  memcpy(loco.UIC_Id,src_loco.UIC_Id,sizeof(sLOCO::UIC_Id));

  ATO_LOCO_DATETIME48_COPY(TimeStamp);

  ATO_LOCO_COPY(loco.Mass,R32);
  ATO_LOCO_COPY(loco.RotatMassCoef,R32);
  ATO_LOCO_COPY(loco.LocoLength,R32);
  ATO_LOCO_COPY(loco.GPSantennaDist,R32);
  ATO_LOCO_COPY(loco.SpeedLimit,R32);
  ATO_LOCO_COPY(loco.AccelerLimit,R32);
  ATO_LOCO_COPY(loco.DecelerLimit,R32);
  ATO_LOCO_COPY(loco.ComfortAcceler,R32);
  ATO_LOCO_COPY(loco.ComfortDeceler,R32);
  ATO_LOCO_COPY(loco.AccelerJerk,R32);
  ATO_LOCO_COPY(loco.DecelerJerk,R32);
  ATO_LOCO_COPY(loco.ResistCoefA,R32);
  ATO_LOCO_COPY(loco.ResistCoefB,R32);
  ATO_LOCO_COPY(loco.ResistCoefC,R32);
  ATO_LOCO_COPY(loco.ResistCoefA_RMSD,R32);
  ATO_LOCO_COPY(loco.ResistCoefB_RMSD,R32);
  ATO_LOCO_COPY(loco.ResistCoefC_RMSD,R32);
  ATO_LOCO_COPY(loco.PropulsPowerC1,R32);
  ATO_LOCO_COPY(loco.PropulsPowerC2,R32);
  ATO_LOCO_COPY(loco.PropulsPowerC3,R32);
  ATO_LOCO_COPY(loco.PropulsPowerH1,R32);
  ATO_LOCO_COPY(loco.PropulsPowerH2,R32);
  ATO_LOCO_COPY(loco.PropulsPowerH3,R32);
  ATO_LOCO_COPY(loco.EDB_PowerC,R32);
  ATO_LOCO_COPY(loco.EDB_PowerS,R32);
  ATO_LOCO_COPY(loco.EDB_PowerS_Durat,R32);
  ATO_LOCO_COPY(loco.EDB_PowerS_Recov,R32);
  ATO_LOCO_COPY(loco.EDB_PowerRegen1,R32);
  ATO_LOCO_COPY(loco.EDB_PowerRegen2,R32);
  ATO_LOCO_COPY(loco.EDB_PowerRegen3,R32);
  ATO_LOCO_COPY(loco.EDB_RegenEffic1,R32);
  ATO_LOCO_COPY(loco.EDB_RegenEffic2,R32);
  ATO_LOCO_COPY(loco.EDB_RegenEffic3,R32);
  ATO_LOCO_COPY(loco.WheelDiameter1,R32);
  ATO_LOCO_COPY(loco.WheelDiameter2,R32);
  ATO_LOCO_COPY(loco.WheelDiameter3,R32);
  ATO_LOCO_COPY(loco.WheelDiameter4,R32);
  ATO_LOCO_COPY(loco.WheelDiameter5,R32);
  ATO_LOCO_COPY(loco.WheelDiameter6,R32);
  ATO_LOCO_COPY(loco.FlywheelMoment,R32);
  ATO_LOCO_COPY(loco.ViscousFrictRotCoef,R32);
  ATO_LOCO_COPY(loco.TractForceMax,R32);
  ATO_LOCO_COPY(loco.EDB_ForceMax,R32);
  ATO_LOCO_COPY(loco.TractForceGradMax,R32);
  ATO_LOCO_COPY(loco.EDB_ForceGradMax,R32);
  ATO_LOCO_COPY(loco.BWP,R32);

  loco.BrakeMode            = src_loco.BrakeMode;
  loco.PropulsType          = src_loco.PropulsType;
  loco.TractForceCurveSize1 = src_loco.TractForceCurveSize1;
  loco.TractForceCurveSize2 = src_loco.TractForceCurveSize2;
  loco.TractForceCurveSize3 = src_loco.TractForceCurveSize3;
  loco.EDBForceC_CurveSize  = src_loco.EDBForceC_CurveSize;
  loco.EDBForceH_CurveSize  = src_loco.EDBForceH_CurveSize;
  loco.TrackImpactClass     = src_loco.TrackImpactClass;

  loco.Version = src_loco.Version;

  // - retrieve characteristics size -
  unsigned charts_size = 2*(loco.TractForceCurveSize1
                          + loco.TractForceCurveSize2
                          + loco.TractForceCurveSize3
                          + loco.EDBForceC_CurveSize
                          + loco.EDBForceH_CurveSize);

  // - if there are characteristics -
  if (charts_size > 0)
  {
    unsigned charts_memory_size = charts_size*sizeof(R32);

    // - ERROR -
    if (string_ptr->size - 1 < c_loco_head_size + charts_memory_size)
    {
      loco_ptr->clear(it);
      cfree(loco_ptr);

      exception_s::throw_exception(it,module.error_base + c_error_ATO_LOCO_WRONG_DATA,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }
    
    // - allocate characteristics memory -
    loco_ptr->charts = (R32 *)cmalloc(charts_memory_size);

    // - copy characteristics -
    R32 *t_ptr = loco_ptr->charts;
    R32 *t_ptr_end = t_ptr + charts_size;
    R32 *s_ptr = (R32 *)(string_ptr->data + c_loco_head_size);
    do {
      memcpy_bo(t_ptr,s_ptr,sizeof(R32),c_little_endian);
    } while(++s_ptr,++t_ptr < t_ptr_end);
  }

  dst_location->v_data_ptr = (basic_64b)loco_ptr;

  return true;
}/*}}}*/

bool bic_ato_loco_method_LocoId_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_LOCO_STRING_VALUE(LocoId);
}/*}}}*/

bool bic_ato_loco_method_LocoType_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_LOCO_STRING_VALUE(LocoType);
}/*}}}*/

bool bic_ato_loco_method_UIC_Id_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ato_loco_s *loco_ptr = (ato_loco_s *)dst_location->v_data_ptr;

  unsigned length = strnlen((char *)loco_ptr->loco.UIC_Id,sizeof(sLOCO::UIC_Id));

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(length,(char *)loco_ptr->loco.UIC_Id);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_ato_loco_method_TimeStamp_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ato_loco_s *loco_ptr = (ato_loco_s *)dst_location->v_data_ptr;

  long long int result = time_stamp_to_nanosec(loco_ptr->loco.TimeStamp);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_ato_loco_method_Version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ato_loco_s *loco_ptr = (ato_loco_s *)dst_location->v_data_ptr;

  long long int result = loco_ptr->loco.Version;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_ato_loco_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("AtoLoco"),"AtoLoco");
  );

  return true;
}/*}}}*/

bool bic_ato_loco_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("AtoLoco");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class ATO_TRAIN -
built_in_class_s ato_train_class =
{/*{{{*/
  "AtoTrain",
  c_modifier_public | c_modifier_final,
  8, ato_train_methods,
  0, ato_train_variables,
  bic_ato_train_consts,
  bic_ato_train_init,
  bic_ato_train_clear,
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

built_in_method_s ato_train_methods[] =
{/*{{{*/
  { 
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_ato_train_operator_binary_equal
  },
  { 
    "AtoTrain#1",
    c_modifier_public | c_modifier_final,
    bic_ato_train_method_AtoTrain_1
  },
  { 
    "TrainId#0",
    c_modifier_public | c_modifier_final,
    bic_ato_train_method_TrainId_0
  },
  { 
    "TrainIdNum#0",
    c_modifier_public | c_modifier_final,
    bic_ato_train_method_TrainIdNum_0
  },
  { 
    "TimeStamp#0",
    c_modifier_public | c_modifier_final,
    bic_ato_train_method_TimeStamp_0
  },
  { 
    "Version#0",
    c_modifier_public | c_modifier_final,
    bic_ato_train_method_Version_0
  },
  { 
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ato_train_method_to_string_0
  },
  { 
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ato_train_method_print_0
  },
};/*}}}*/

built_in_variable_s ato_train_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_ATO_TRAIN_STRING_VALUE(NAME)\
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  ato_train_s *train_ptr = (ato_train_s *)dst_location->v_data_ptr;\
\
  unsigned length = strnlen(train_ptr->train.NAME,sizeof(sTRAIN::NAME));\
\
  string_s *string_ptr = it.get_new_string_ptr();\
  string_ptr->set(length,train_ptr->train.NAME);\
\
  BIC_SET_RESULT_STRING(string_ptr);\
\
  return true;\
}/*}}}*/

void bic_ato_train_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_ato_train_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)NULL;
}/*}}}*/

void bic_ato_train_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  ato_train_s *train_ptr = (ato_train_s *)location_ptr->v_data_ptr;

  if (train_ptr != NULL)
  {
    train_ptr->clear(it);
    cfree(train_ptr);
  }
}/*}}}*/

bool bic_ato_train_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_ato_train_method_AtoTrain_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("AtoTrain#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create ato train object -
  ato_train_s *train_ptr = (ato_train_s *)cmalloc(sizeof(ato_train_s));
  train_ptr->init();

  // - ERROR -
  if (string_ptr->size - 1 < sizeof(sTRAIN))
  {
    train_ptr->clear(it);
    cfree(train_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_ATO_TRAIN_WRONG_DATA,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - process sTRAIN structure -
  sTRAIN &src_train = *((sTRAIN *)string_ptr->data);
  sTRAIN &train = train_ptr->train;

#define ATO_TRAIN_COPY(NAME,TYPE) \
{/*{{{*/\
  memcpy_bo(&NAME,&src_ ## NAME,sizeof(TYPE),c_little_endian);\
}/*}}}*/

#define ATO_TRAIN_DATETIME48_COPY(NAME) \
{/*{{{*/\
  ATO_TRAIN_COPY(train.NAME.seconds,U32);\
  ATO_TRAIN_COPY(train.NAME.ticks,U16);\
}/*}}}*/

  memcpy(train.MD5digest,src_train.MD5digest,sizeof(sTRAIN::MD5digest));
  memcpy(train.TrainId,src_train.TrainId,sizeof(sTRAIN::TrainId));
  memcpy(train.TrainIdNum,src_train.TrainIdNum,sizeof(sTRAIN::TrainIdNum));

  ATO_TRAIN_DATETIME48_COPY(TimeStamp);

  ATO_TRAIN_COPY(train.MassEstim,R32);
  ATO_TRAIN_COPY(train.MassEstim_RMSD,R32);
  ATO_TRAIN_COPY(train.RotatMassCoef,R32);
  ATO_TRAIN_COPY(train.TrainLength,R32);
  ATO_TRAIN_COPY(train.SpeedLimit,R32);
  ATO_TRAIN_COPY(train.AccelerLimit,R32);
  ATO_TRAIN_COPY(train.DecelerLimit,R32);
  ATO_TRAIN_COPY(train.ComfortAcceler,R32);
  ATO_TRAIN_COPY(train.ComfortDeceler,R32);
  ATO_TRAIN_COPY(train.AccelerJerk,R32);
  ATO_TRAIN_COPY(train.DecelerJerk,R32);
  ATO_TRAIN_COPY(train.ResistCoefA,R32);
  ATO_TRAIN_COPY(train.ResistCoefB,R32);
  ATO_TRAIN_COPY(train.ResistCoefC,R32);
  ATO_TRAIN_COPY(train.ResistCoefA_RMSD,R32);
  ATO_TRAIN_COPY(train.ResistCoefB_RMSD,R32);
  ATO_TRAIN_COPY(train.ResistCoefC_RMSD,R32);
  ATO_TRAIN_COPY(train.BWP,R32);

  train.BrakeMode = src_train.BrakeMode;
  train.TrainType = src_train.TrainType;

  ATO_TRAIN_COPY(train.TrainSetClass,U16);
  ATO_TRAIN_COPY(train.Version,U16);

  dst_location->v_data_ptr = (basic_64b)train_ptr;

  return true;
}/*}}}*/

bool bic_ato_train_method_TrainId_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_TRAIN_STRING_VALUE(TrainId);
}/*}}}*/

bool bic_ato_train_method_TrainIdNum_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_TRAIN_STRING_VALUE(TrainIdNum);
}/*}}}*/

bool bic_ato_train_method_TimeStamp_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ato_train_s *train_ptr = (ato_train_s *)dst_location->v_data_ptr;

  long long int result = time_stamp_to_nanosec(train_ptr->train.TimeStamp);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_ato_train_method_Version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ato_train_s *train_ptr = (ato_train_s *)dst_location->v_data_ptr;

  long long int result = train_ptr->train.Version;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_ato_train_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("AtoTrain"),"AtoTrain");
  );

  return true;
}/*}}}*/

bool bic_ato_train_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("AtoTrain");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class ATO_TRIP -
built_in_class_s ato_trip_class =
{/*{{{*/
  "AtoTrip",
  c_modifier_public | c_modifier_final,
  17, ato_trip_methods,
  0, ato_trip_variables,
  bic_ato_trip_consts,
  bic_ato_trip_init,
  bic_ato_trip_clear,
  NULL,
  bic_ato_trip_length,
  bic_ato_trip_item,
  bic_ato_trip_first_idx,
  bic_ato_trip_next_idx,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s ato_trip_methods[] =
{/*{{{*/
  { 
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_ato_trip_operator_binary_equal
  },
  { 
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_ato_trip_operator_binary_le_br_re_br
  },
  { 
    "AtoTrip#1",
    c_modifier_public | c_modifier_final,
    bic_ato_trip_method_AtoTrip_1
  },
  { 
    "TripId#0",
    c_modifier_public | c_modifier_final,
    bic_ato_trip_method_TripId_0
  },
  { 
    "TrainIdNum#0",
    c_modifier_public | c_modifier_final,
    bic_ato_trip_method_TrainIdNum_0
  },
  { 
    "DepartStation#0",
    c_modifier_public | c_modifier_final,
    bic_ato_trip_method_DepartStation_0
  },
  { 
    "DestinStation#0",
    c_modifier_public | c_modifier_final,
    bic_ato_trip_method_DestinStation_0
  },
  { 
    "TimeStamp#0",
    c_modifier_public | c_modifier_final,
    bic_ato_trip_method_TimeStamp_0
  },
  { 
    "DepartTime#0",
    c_modifier_public | c_modifier_final,
    bic_ato_trip_method_DepartTime_0
  },
  { 
    "ArrivalTime#0",
    c_modifier_public | c_modifier_final,
    bic_ato_trip_method_ArrivalTime_0
  },
  { 
    "Version#0",
    c_modifier_public | c_modifier_final,
    bic_ato_trip_method_Version_0
  },
  { 
    "item#1",
    c_modifier_public | c_modifier_final,
    bic_ato_trip_method_item_1
  },
  { 
    "first_idx#0",
    c_modifier_public | c_modifier_final,
    bic_ato_trip_method_first_idx_0
  },
  { 
    "next_idx#1",
    c_modifier_public | c_modifier_final,
    bic_ato_trip_method_next_idx_1
  },
  { 
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_ato_trip_method_length_0
  },
  { 
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ato_trip_method_to_string_0
  },
  { 
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ato_trip_method_print_0
  },
};/*}}}*/

built_in_variable_s ato_trip_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_ATO_TRIP_STRING_VALUE(NAME)\
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  ato_trip_s *trip_ptr = (ato_trip_s *)dst_location->v_data_ptr;\
\
  unsigned length = strnlen(trip_ptr->trip.NAME,sizeof(sTRIP::NAME));\
\
  string_s *string_ptr = it.get_new_string_ptr();\
  string_ptr->set(length,trip_ptr->trip.NAME);\
\
  BIC_SET_RESULT_STRING(string_ptr);\
\
  return true;\
}/*}}}*/

#define BIC_ATO_TRIP_TIME_STAMP_VALUE(NAME)\
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  ato_trip_s *trip_ptr = (ato_trip_s *)dst_location->v_data_ptr;\
\
  long long int result = time_stamp_to_nanosec(trip_ptr->trip.NAME);\
\
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
\
  return true;\
}/*}}}*/

#define BIC_ATO_TRIP_CHECK_INDEX() \
/*{{{*/\
ato_trip_s *trip_ptr = (ato_trip_s *)dst_location->v_data_ptr;\
\
/* - ERROR - */\
if (index < 0 || index >= trip_ptr->trip.NofLineSections) {\
  exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_ATO_TRIP_INDEX_EXCEEDS_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
  new_exception->params.push(index);\
  \
  return false;\
}\
/*}}}*/\

#define BIC_ATO_TRIP_ITEM(NAME) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
  \
  long long int index;\
  \
  /* - ERROR - */\
  if (!it.retrieve_integer(src_0_location,index))\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
    new_exception->params.push(1);\
    new_exception->params.push(src_0_location->v_type);\
    \
    return false;\
  }\
  \
  BIC_ATO_TRIP_CHECK_INDEX();\
  \
  /* - create ato trip section object - */\
  ato_trip_sec_s *ats_ptr = (ato_trip_sec_s *)cmalloc(sizeof(ato_trip_sec_s));\
  ats_ptr->init();\
\
  dst_location->v_reference_cnt.atomic_inc();\
  ats_ptr->trip_loc = dst_location;\
  ats_ptr->index = index;\
\
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_ato_trip_sec,ats_ptr);\
  BIC_SET_RESULT(new_location);\
\
  return true;\
}/*}}}*/

void bic_ato_trip_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_ato_trip_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)NULL;
}/*}}}*/

void bic_ato_trip_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  ato_trip_s *trip_ptr = (ato_trip_s *)location_ptr->v_data_ptr;

  if (trip_ptr != NULL)
  {
    trip_ptr->clear(it);
    cfree(trip_ptr);
  }
}/*}}}*/

unsigned bic_ato_trip_length(location_s *location_ptr)
{/*{{{*/
  ato_trip_s *trip_ptr = (ato_trip_s *)location_ptr->v_data_ptr;
  return trip_ptr->trip.NofLineSections;
}/*}}}*/

location_s *bic_ato_trip_item(interpreter_thread_s &it,location_s *location_ptr,unsigned index)
{/*{{{*/
  ato_trip_s *trip_ptr = (ato_trip_s *)location_ptr->v_data_ptr;

  // FIXME TODO check index ...
  cassert(index < trip_ptr->trip.NofLineSections);

  // - create ato trip section object -
  ato_trip_sec_s *ats_ptr = (ato_trip_sec_s *)cmalloc(sizeof(ato_trip_sec_s));
  ats_ptr->init();

  location_ptr->v_reference_cnt.atomic_inc();
  ats_ptr->trip_loc = location_ptr;
  ats_ptr->index = index;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_ato_trip_sec,ats_ptr);

  return new_location;
}/*}}}*/

unsigned bic_ato_trip_first_idx(location_s *location_ptr)
{/*{{{*/
  ato_trip_s *trip_ptr = (ato_trip_s *)location_ptr->v_data_ptr;
  return trip_ptr->trip.NofLineSections > 0 ? 0 : c_idx_not_exist;
}/*}}}*/

unsigned bic_ato_trip_next_idx(location_s *location_ptr,unsigned index)
{/*{{{*/
  ato_trip_s *trip_ptr = (ato_trip_s *)location_ptr->v_data_ptr;

  // FIXME TODO check index ...
  cassert(index < trip_ptr->trip.NofLineSections);

  return (index + 1 < trip_ptr->trip.NofLineSections) ? index + 1 : c_idx_not_exist;
}/*}}}*/

bool bic_ato_trip_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_ato_trip_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_TRIP_ITEM("operator_binary_le_br_re_br#1");
}/*}}}*/

bool bic_ato_trip_method_AtoTrip_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("AtoTrip#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - check MD5 digest -
  BIC_CHECK_MD5_DIGEST(ATO_TRIP_WRONG_MD5_CHECKSUM);

  // - create ato trip object -
  ato_trip_s *trip_ptr = (ato_trip_s *)cmalloc(sizeof(ato_trip_s));
  trip_ptr->init();

  // - compute trip header size -
  const unsigned c_trip_head_size = sizeof(sTRIP) - sizeof(sLINE_SEC_DESC);

  // - ERROR -
  if (string_ptr->size - 1 < c_trip_head_size)
  {
    trip_ptr->clear(it);
    cfree(trip_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_ATO_TRIP_WRONG_DATA,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - process sTRIP structure -
  sTRIP &src_trip = *((sTRIP *)string_ptr->data);
  sTRIP &trip = trip_ptr->trip;

  memcpy(&trip,&src_trip,c_trip_head_size);

#define ATO_TRIP_COPY(NAME,TYPE) \
{/*{{{*/\
  memcpy_bo(&NAME,&src_ ## NAME,sizeof(TYPE),c_little_endian);\
}/*}}}*/

#define ATO_TRIP_DATETIME48_COPY(NAME) \
{/*{{{*/\
  ATO_TRIP_COPY(trip.NAME.seconds,U32);\
  ATO_TRIP_COPY(trip.NAME.ticks,U16);\
}/*}}}*/

  ATO_TRIP_DATETIME48_COPY(TimeStamp);
  ATO_TRIP_DATETIME48_COPY(DepartTime);
  ATO_TRIP_DATETIME48_COPY(ArrivalTime);

  ATO_TRIP_COPY(trip.Version,U16);
  ATO_TRIP_COPY(trip.HeadingSize,U16);
  ATO_TRIP_COPY(trip.LineSectSize,U16);
  ATO_TRIP_COPY(trip.NofLineSections,U16);

  if (trip.NofLineSections > 0)
  {
    // - compute trip sections memory size -
    unsigned sections_mem_size = trip.NofLineSections*sizeof(sLINE_SEC_DESC);

    // - ERROR -
    if (string_ptr->size - 1 < c_trip_head_size + sections_mem_size)
    {
      trip_ptr->clear(it);
      cfree(trip_ptr);

      exception_s::throw_exception(it,module.error_base + c_error_ATO_TRIP_WRONG_DATA,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    // - allocate trip sections memory -
    trip_ptr->sec_descrs = (sLINE_SEC_DESC *)cmalloc(sections_mem_size);

    sLINE_SEC_DESC *s_ptr = (sLINE_SEC_DESC *)(string_ptr->data + c_trip_head_size);
    sLINE_SEC_DESC *s_ptr_end = s_ptr + trip.NofLineSections;
    sLINE_SEC_DESC *t_ptr = trip_ptr->sec_descrs;

#define ATO_TRIP_SEC_COPY(NAME,TYPE) \
{/*{{{*/\
  memcpy_bo(&t_ptr->NAME,&s_ptr->NAME,sizeof(TYPE),c_little_endian);\
}/*}}}*/

#define ATO_TRIP_SEC_DATETIME48_COPY(NAME) \
{/*{{{*/\
  ATO_TRIP_SEC_COPY(NAME.seconds,U32);\
  ATO_TRIP_SEC_COPY(NAME.ticks,U16);\
}/*}}}*/

    do {
      memcpy(t_ptr,s_ptr,sizeof(sLINE_SEC_DESC));

      ATO_TRIP_SEC_DATETIME48_COPY(TimeStamp);
      ATO_TRIP_SEC_DATETIME48_COPY(ArrivalTime);
      ATO_TRIP_SEC_DATETIME48_COPY(DepartTime);
    } while(++t_ptr,++s_ptr < s_ptr_end);
  }

  dst_location->v_data_ptr = (basic_64b)trip_ptr;

  return true;
}/*}}}*/

bool bic_ato_trip_method_TripId_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_TRIP_STRING_VALUE(TripId);
}/*}}}*/

bool bic_ato_trip_method_TrainIdNum_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_TRIP_STRING_VALUE(TrainIdNum);
}/*}}}*/

bool bic_ato_trip_method_DepartStation_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_TRIP_STRING_VALUE(DepartStation);
}/*}}}*/

bool bic_ato_trip_method_DestinStation_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_TRIP_STRING_VALUE(DestinStation);
}/*}}}*/

bool bic_ato_trip_method_TimeStamp_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_TRIP_TIME_STAMP_VALUE(TimeStamp);
}/*}}}*/

bool bic_ato_trip_method_DepartTime_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_TRIP_TIME_STAMP_VALUE(DepartTime);
}/*}}}*/

bool bic_ato_trip_method_ArrivalTime_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_TRIP_TIME_STAMP_VALUE(ArrivalTime);
}/*}}}*/

bool bic_ato_trip_method_Version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ato_trip_s *trip_ptr = (ato_trip_s *)dst_location->v_data_ptr;

  long long int result = trip_ptr->trip.Version;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_ato_trip_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_TRIP_ITEM("item#1");
}/*}}}*/

bool bic_ato_trip_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ato_trip_s *trip_ptr = (ato_trip_s *)dst_location->v_data_ptr;

  if (trip_ptr->trip.NofLineSections > 0)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,0);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_ato_trip_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
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

  BIC_ATO_TRIP_CHECK_INDEX();

  if (++index < trip_ptr->trip.NofLineSections)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,index);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_ato_trip_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ato_trip_s *trip_ptr = (ato_trip_s *)dst_location->v_data_ptr;
  long long int result = trip_ptr->trip.NofLineSections;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_ato_trip_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("AtoTrip"),"AtoTrip");
  );

  return true;
}/*}}}*/

bool bic_ato_trip_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("AtoTrip");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class ATO_TRIP_SEC -
built_in_class_s ato_trip_sec_class =
{/*{{{*/
  "AtoTripSec",
  c_modifier_public | c_modifier_final,
  8, ato_trip_sec_methods,
  0, ato_trip_sec_variables,
  bic_ato_trip_sec_consts,
  bic_ato_trip_sec_init,
  bic_ato_trip_sec_clear,
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

built_in_method_s ato_trip_sec_methods[] =
{/*{{{*/
  { 
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_ato_trip_sec_operator_binary_equal
  },
  { 
    "LineSectionId#0",
    c_modifier_public | c_modifier_final,
    bic_ato_trip_sec_method_LineSectionId_0
  },
  { 
    "TimeStamp#0",
    c_modifier_public | c_modifier_final,
    bic_ato_trip_sec_method_TimeStamp_0
  },
  { 
    "IntermedStation#0",
    c_modifier_public | c_modifier_final,
    bic_ato_trip_sec_method_IntermedStation_0
  },
  { 
    "ArrivalTime#0",
    c_modifier_public | c_modifier_final,
    bic_ato_trip_sec_method_ArrivalTime_0
  },
  { 
    "DepartTime#0",
    c_modifier_public | c_modifier_final,
    bic_ato_trip_sec_method_DepartTime_0
  },
  { 
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ato_trip_sec_method_to_string_0
  },
  { 
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ato_trip_sec_method_print_0
  },
};/*}}}*/

built_in_variable_s ato_trip_sec_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_ATO_TRIP_SEC_STRING_VALUE(NAME)\
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  ato_trip_sec_s *ats_ptr = (ato_trip_sec_s *)dst_location->v_data_ptr;\
  ato_trip_s *trip_ptr = (ato_trip_s *)ats_ptr->trip_loc->v_data_ptr;\
\
  sLINE_SEC_DESC &line_sec_desc = trip_ptr->sec_descrs[ats_ptr->index];\
  unsigned length = strnlen(line_sec_desc.NAME,sizeof(sLINE_SEC_DESC::NAME));\
\
  string_s *string_ptr = it.get_new_string_ptr();\
  string_ptr->set(length,line_sec_desc.NAME);\
\
  BIC_SET_RESULT_STRING(string_ptr);\
\
  return true;\
}/*}}}*/

#define BIC_ATO_TRIP_SEC_TIME_STAMP_VALUE(NAME)\
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  ato_trip_sec_s *ats_ptr = (ato_trip_sec_s *)dst_location->v_data_ptr;\
  ato_trip_s *trip_ptr = (ato_trip_s *)ats_ptr->trip_loc->v_data_ptr;\
\
  sLINE_SEC_DESC &line_sec_desc = trip_ptr->sec_descrs[ats_ptr->index];\
  long long int result = time_stamp_to_nanosec(line_sec_desc.NAME);\
\
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
\
  return true;\
}/*}}}*/

void bic_ato_trip_sec_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_ato_trip_sec_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)NULL;
}/*}}}*/

void bic_ato_trip_sec_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  ato_trip_sec_s *ats_ptr = (ato_trip_sec_s *)location_ptr->v_data_ptr;

  if (ats_ptr != NULL)
  {
    ats_ptr->clear(it);
    cfree(ats_ptr);
  }
}/*}}}*/

bool bic_ato_trip_sec_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_ato_trip_sec_method_LineSectionId_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_TRIP_SEC_STRING_VALUE(LineSectionId);
}/*}}}*/

bool bic_ato_trip_sec_method_TimeStamp_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_TRIP_SEC_TIME_STAMP_VALUE(TimeStamp);
}/*}}}*/

bool bic_ato_trip_sec_method_IntermedStation_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_TRIP_SEC_STRING_VALUE(IntermedStation);
}/*}}}*/

bool bic_ato_trip_sec_method_ArrivalTime_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_TRIP_SEC_TIME_STAMP_VALUE(ArrivalTime);
}/*}}}*/

bool bic_ato_trip_sec_method_DepartTime_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_TRIP_SEC_TIME_STAMP_VALUE(DepartTime);
}/*}}}*/

bool bic_ato_trip_sec_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("AtoTripSec"),"AtoTripSec");
  );

  return true;
}/*}}}*/

bool bic_ato_trip_sec_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("AtoTripSec");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class ATO_LINE_SEC -
built_in_class_s ato_line_sec_class =
{/*{{{*/
  "AtoLineSec",
  c_modifier_public | c_modifier_final,
  35, ato_line_sec_methods,
  0, ato_line_sec_variables,
  bic_ato_line_sec_consts,
  bic_ato_line_sec_init,
  bic_ato_line_sec_clear,
  NULL,
  bic_ato_line_sec_length,
  bic_ato_line_sec_item,
  bic_ato_line_sec_first_idx,
  bic_ato_line_sec_next_idx,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s ato_line_sec_methods[] =
{/*{{{*/
  { 
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_ato_line_sec_operator_binary_equal
  },
  { 
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_ato_line_sec_operator_binary_le_br_re_br
  },
  { 
    "AtoLineSec#1",
    c_modifier_public | c_modifier_final,
    bic_ato_line_sec_method_AtoLineSec_1
  },
  { 
    "LineSectionId#0",
    c_modifier_public | c_modifier_final,
    bic_ato_line_sec_method_LineSectionId_0
  },
  { 
    "DepartStation#0",
    c_modifier_public | c_modifier_final,
    bic_ato_line_sec_method_DepartStation_0
  },
  { 
    "DestinStation#0",
    c_modifier_public | c_modifier_final,
    bic_ato_line_sec_method_DestinStation_0
  },
  { 
    "GLPsId#0",
    c_modifier_public | c_modifier_final,
    bic_ato_line_sec_method_GLPsId_0
  },
  { 
    "TextsId#0",
    c_modifier_public | c_modifier_final,
    bic_ato_line_sec_method_TextsId_0
  },
  { 
    "BalisesId#0",
    c_modifier_public | c_modifier_final,
    bic_ato_line_sec_method_BalisesId_0
  },
  { 
    "TrackMenuId#0",
    c_modifier_public | c_modifier_final,
    bic_ato_line_sec_method_TrackMenuId_0
  },
  { 
    "SignalLightsId#0",
    c_modifier_public | c_modifier_final,
    bic_ato_line_sec_method_SignalLightsId_0
  },
  { 
    "TimeStamp#0",
    c_modifier_public | c_modifier_final,
    bic_ato_line_sec_method_TimeStamp_0
  },
  { 
    "TimeStampG#0",
    c_modifier_public | c_modifier_final,
    bic_ato_line_sec_method_TimeStampG_0
  },
  { 
    "TimeStampT#0",
    c_modifier_public | c_modifier_final,
    bic_ato_line_sec_method_TimeStampT_0
  },
  { 
    "TimeStampB#0",
    c_modifier_public | c_modifier_final,
    bic_ato_line_sec_method_TimeStampB_0
  },
  { 
    "TimeStampD#0",
    c_modifier_public | c_modifier_final,
    bic_ato_line_sec_method_TimeStampD_0
  },
  { 
    "TimeStampS#0",
    c_modifier_public | c_modifier_final,
    bic_ato_line_sec_method_TimeStampS_0
  },
  { 
    "SchedulTravelTime#0",
    c_modifier_public | c_modifier_final,
    bic_ato_line_sec_method_SchedulTravelTime_0
  },
  { 
    "SectionLength#0",
    c_modifier_public | c_modifier_final,
    bic_ato_line_sec_method_SectionLength_0
  },
  { 
    "StoppingDistMax#0",
    c_modifier_public | c_modifier_final,
    bic_ato_line_sec_method_StoppingDistMax_0
  },
  { 
    "Deceler1DistMax#0",
    c_modifier_public | c_modifier_final,
    bic_ato_line_sec_method_Deceler1DistMax_0
  },
  { 
    "TargDisplac#0",
    c_modifier_public | c_modifier_final,
    bic_ato_line_sec_method_TargDisplac_0
  },
  { 
    "SpeedTargMin#0",
    c_modifier_public | c_modifier_final,
    bic_ato_line_sec_method_SpeedTargMin_0
  },
  { 
    "SpeedTargMax#0",
    c_modifier_public | c_modifier_final,
    bic_ato_line_sec_method_SpeedTargMax_0
  },
  { 
    "SpeedMin#0",
    c_modifier_public | c_modifier_final,
    bic_ato_line_sec_method_SpeedMin_0
  },
  { 
    "SpeedMax#0",
    c_modifier_public | c_modifier_final,
    bic_ato_line_sec_method_SpeedMax_0
  },
  { 
    "SpeedCoastMin#0",
    c_modifier_public | c_modifier_final,
    bic_ato_line_sec_method_SpeedCoastMin_0
  },
  { 
    "TargDisplacMax#0",
    c_modifier_public | c_modifier_final,
    bic_ato_line_sec_method_TargDisplacMax_0
  },
  { 
    "Version#0",
    c_modifier_public | c_modifier_final,
    bic_ato_line_sec_method_Version_0
  },
  { 
    "item#1",
    c_modifier_public | c_modifier_final,
    bic_ato_line_sec_method_item_1
  },
  { 
    "first_idx#0",
    c_modifier_public | c_modifier_final,
    bic_ato_line_sec_method_first_idx_0
  },
  { 
    "next_idx#1",
    c_modifier_public | c_modifier_final,
    bic_ato_line_sec_method_next_idx_1
  },
  { 
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_ato_line_sec_method_length_0
  },
  { 
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ato_line_sec_method_to_string_0
  },
  { 
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ato_line_sec_method_print_0
  },
};/*}}}*/

built_in_variable_s ato_line_sec_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_ATO_LINE_SEC_INTEGER_VALUE(NAME)\
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  ato_line_sec_s *als_ptr = (ato_line_sec_s *)dst_location->v_data_ptr;\
\
  long long int result = als_ptr->line_sec.NAME;\
\
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
\
  return true;\
}/*}}}*/

#define BIC_ATO_LINE_SEC_FLOAT_VALUE(NAME)\
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  ato_line_sec_s *als_ptr = (ato_line_sec_s *)dst_location->v_data_ptr;\
\
  double result = als_ptr->line_sec.NAME;\
\
  basic_64b &v_data_ptr = *((basic_64b *)&result);\
  BIC_SIMPLE_SET_RES(c_bi_class_float,v_data_ptr);\
\
  return true;\
}/*}}}*/

#define BIC_ATO_LINE_SEC_STRING_VALUE(NAME)\
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  ato_line_sec_s *als_ptr = (ato_line_sec_s *)dst_location->v_data_ptr;\
\
  unsigned length = strnlen(als_ptr->line_sec.NAME,sizeof(sLINE_SECTION::NAME));\
\
  string_s *string_ptr = it.get_new_string_ptr();\
  string_ptr->set(length,als_ptr->line_sec.NAME);\
\
  BIC_SET_RESULT_STRING(string_ptr);\
\
  return true;\
}/*}}}*/

#define BIC_ATO_LINE_SEC_TIME_STAMP_VALUE(NAME)\
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  ato_line_sec_s *als_ptr = (ato_line_sec_s *)dst_location->v_data_ptr;\
\
  long long int result = time_stamp_to_nanosec(als_ptr->line_sec.NAME);\
\
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
\
  return true;\
}/*}}}*/

#define BIC_ATO_LINE_SEC_CHECK_INDEX() \
/*{{{*/\
ato_line_sec_s *als_ptr = (ato_line_sec_s *)dst_location->v_data_ptr;\
\
/* - ERROR - */\
if (index < 0 || index >= als_ptr->line_sec.NofLinePoints) {\
  exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_ATO_LINE_SEC_INDEX_EXCEEDS_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
  new_exception->params.push(index);\
  \
  return false;\
}\
/*}}}*/\

#define BIC_ATO_LINE_SEC_ITEM(NAME) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
  \
  long long int index;\
  \
  /* - ERROR - */\
  if (!it.retrieve_integer(src_0_location,index))\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
    new_exception->params.push(1);\
    new_exception->params.push(src_0_location->v_type);\
    \
    return false;\
  }\
  \
  BIC_ATO_LINE_SEC_CHECK_INDEX();\
  \
  /* - create ato line section point object - */\
  ato_line_sec_point_s *alsp_ptr = (ato_line_sec_point_s *)cmalloc(sizeof(ato_line_sec_point_s));\
  alsp_ptr->init();\
\
  dst_location->v_reference_cnt.atomic_inc();\
  alsp_ptr->line_sec_loc = dst_location;\
  alsp_ptr->index = index;\
\
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_ato_line_sec_point,alsp_ptr);\
  BIC_SET_RESULT(new_location);\
\
  return true;\
}/*}}}*/

void bic_ato_line_sec_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_ato_line_sec_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)NULL;
}/*}}}*/

void bic_ato_line_sec_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  ato_line_sec_s *als_ptr = (ato_line_sec_s *)location_ptr->v_data_ptr;

  if (als_ptr != NULL)
  {
    als_ptr->clear(it);
    cfree(als_ptr);
  }
}/*}}}*/

unsigned bic_ato_line_sec_length(location_s *location_ptr)
{/*{{{*/
  ato_line_sec_s *als_ptr = (ato_line_sec_s *)location_ptr->v_data_ptr;
  return als_ptr->line_sec.NofLinePoints;
}/*}}}*/

location_s *bic_ato_line_sec_item(interpreter_thread_s &it,location_s *location_ptr,unsigned index)
{/*{{{*/
  ato_line_sec_s *als_ptr = (ato_line_sec_s *)location_ptr->v_data_ptr;

  // FIXME TODO check index ...
  cassert(index < als_ptr->line_sec.NofLinePoints);

  // - create ato line section point object -
  ato_line_sec_point_s *alsp_ptr = (ato_line_sec_point_s *)cmalloc(sizeof(ato_line_sec_point_s));
  alsp_ptr->init();

  location_ptr->v_reference_cnt.atomic_inc();
  alsp_ptr->line_sec_loc = location_ptr;
  alsp_ptr->index = index;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_ato_line_sec_point,alsp_ptr);

  return new_location;
}/*}}}*/

unsigned bic_ato_line_sec_first_idx(location_s *location_ptr)
{/*{{{*/
  ato_line_sec_s *als_ptr = (ato_line_sec_s *)location_ptr->v_data_ptr;
  return als_ptr->line_sec.NofLinePoints > 0 ? 0 : c_idx_not_exist;
}/*}}}*/

unsigned bic_ato_line_sec_next_idx(location_s *location_ptr,unsigned index)
{/*{{{*/
  ato_line_sec_s *als_ptr = (ato_line_sec_s *)location_ptr->v_data_ptr;

  // FIXME TODO check index ...
  cassert(index < als_ptr->line_sec.NofLinePoints);

  return (index + 1 < als_ptr->line_sec.NofLinePoints) ? index + 1 : c_idx_not_exist;
}/*}}}*/

bool bic_ato_line_sec_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_ato_line_sec_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_LINE_SEC_ITEM("operator_binary_le_br_re_br#1");
}/*}}}*/

bool bic_ato_line_sec_method_AtoLineSec_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("AtoLineSec#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - check MD5 digest -
  BIC_CHECK_MD5_DIGEST(ATO_LINE_SEC_WRONG_MD5_CHECKSUM);

  // - create ato line section object -
  ato_line_sec_s *als_ptr = (ato_line_sec_s *)cmalloc(sizeof(ato_line_sec_s));
  als_ptr->init();

  // - compute line section header size -
  const unsigned c_line_sec_head_size = sizeof(sLINE_SECTION) - sizeof(sLINE_POINT);

  // - ERROR -
  if (string_ptr->size - 1 < c_line_sec_head_size)
  {
    als_ptr->clear(it);
    cfree(als_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_ATO_LINE_SEC_WRONG_DATA,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - process sLINE_SECTION structure -
  sLINE_SECTION &src_line_sec = *((sLINE_SECTION *)string_ptr->data);
  sLINE_SECTION &line_sec = als_ptr->line_sec;

  memcpy(&line_sec,&src_line_sec,c_line_sec_head_size);

#define ATO_LINE_SEC_COPY(NAME,TYPE) \
{/*{{{*/\
  memcpy_bo(&NAME,&src_ ## NAME,sizeof(TYPE),c_little_endian);\
}/*}}}*/

#define ATO_LINE_SEC_DATETIME48_COPY(NAME) \
{/*{{{*/\
  ATO_LINE_SEC_COPY(line_sec.NAME.seconds,U32);\
  ATO_LINE_SEC_COPY(line_sec.NAME.ticks,U16);\
}/*}}}*/

  ATO_LINE_SEC_DATETIME48_COPY(TimeStamp);
  ATO_LINE_SEC_DATETIME48_COPY(TimeStampG);
  ATO_LINE_SEC_DATETIME48_COPY(TimeStampT);
  ATO_LINE_SEC_DATETIME48_COPY(TimeStampB);
  ATO_LINE_SEC_DATETIME48_COPY(TimeStampD);
  ATO_LINE_SEC_DATETIME48_COPY(TimeStampS);

  ATO_LINE_SEC_COPY(line_sec.SchedulTravelTime,R32); 
  ATO_LINE_SEC_COPY(line_sec.SectionLength,R32);
  ATO_LINE_SEC_COPY(line_sec.StoppingDistMax,R32);
  ATO_LINE_SEC_COPY(line_sec.Deceler1DistMax,R32);

  unsigned idx = 0;
  do {
    ATO_LINE_SEC_COPY(line_sec.TargDisplac[idx],U16);
  } while(++idx < 10);

  ATO_LINE_SEC_COPY(line_sec.SpeedTargMin,R32);
  ATO_LINE_SEC_COPY(line_sec.SpeedTargMax,R32);
  ATO_LINE_SEC_COPY(line_sec.SpeedMin,R32);
  ATO_LINE_SEC_COPY(line_sec.SpeedMax,R32);
  ATO_LINE_SEC_COPY(line_sec.SpeedCoastMin,R32);
  ATO_LINE_SEC_COPY(line_sec.TargDisplacMax,U16);
  ATO_LINE_SEC_COPY(line_sec.Version,U16);
  ATO_LINE_SEC_COPY(line_sec.HeadingSize,U16);
  ATO_LINE_SEC_COPY(line_sec.LinePointSize,U16);
  ATO_LINE_SEC_COPY(line_sec.LPApkmMax,U16);
  ATO_LINE_SEC_COPY(line_sec.LPRpkmMax,U16);
  ATO_LINE_SEC_COPY(line_sec.NofLinePointsR,U16);
  ATO_LINE_SEC_COPY(line_sec.NofLinePoints,U16);

  if (line_sec.NofLinePoints > 0)
  {
    // - compute line section points memory size -
    unsigned points_mem_size = line_sec.NofLinePoints*sizeof(sLINE_POINT);

    // - ERROR -
    if (string_ptr->size - 1 < c_line_sec_head_size + points_mem_size)
    {
      als_ptr->clear(it);
      cfree(als_ptr);

      exception_s::throw_exception(it,module.error_base + c_error_ATO_LINE_SEC_WRONG_DATA,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    // - allocate line section points memory -
    als_ptr->line_points = (sLINE_POINT *)cmalloc(points_mem_size);

    sLINE_POINT *s_ptr = (sLINE_POINT *)(string_ptr->data + c_line_sec_head_size);
    sLINE_POINT *s_ptr_end = s_ptr + line_sec.NofLinePoints;
    sLINE_POINT *t_ptr = als_ptr->line_points;

#define ATO_LINE_SEC_POINT_COPY(NAME,TYPE) \
{/*{{{*/\
  memcpy_bo(&t_ptr->NAME,&s_ptr->NAME,sizeof(TYPE),c_little_endian);\
}/*}}}*/

    do {
      ATO_LINE_SEC_POINT_COPY(LPindx,U16);
      ATO_LINE_SEC_POINT_COPY(LPindxR,U16);
      ATO_LINE_SEC_POINT_COPY(Dist2RefLP,R32);
      ATO_LINE_SEC_POINT_COPY(Dist2RefLP_RMSD,R32);
      ATO_LINE_SEC_POINT_COPY(LineGrad,R32);
      ATO_LINE_SEC_POINT_COPY(LineGradEff,R32);
      ATO_LINE_SEC_POINT_COPY(LineGradEffRMSD,R32);
      ATO_LINE_SEC_POINT_COPY(SpeedLimit,R32);
      ATO_LINE_SEC_POINT_COPY(LPId,U16);

      memcpy(t_ptr->sLPtype,s_ptr->sLPtype,8*sizeof(U8));
    } while(++t_ptr,++s_ptr < s_ptr_end);
  }

  dst_location->v_data_ptr = (basic_64b)als_ptr;

  return true;
}/*}}}*/

bool bic_ato_line_sec_method_LineSectionId_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_LINE_SEC_STRING_VALUE(LineSectionId);
}/*}}}*/

bool bic_ato_line_sec_method_DepartStation_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_LINE_SEC_STRING_VALUE(DepartStation);
}/*}}}*/

bool bic_ato_line_sec_method_DestinStation_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_LINE_SEC_STRING_VALUE(DestinStation);
}/*}}}*/

bool bic_ato_line_sec_method_GLPsId_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_LINE_SEC_STRING_VALUE(GLPsId);
}/*}}}*/

bool bic_ato_line_sec_method_TextsId_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_LINE_SEC_STRING_VALUE(TextsId);
}/*}}}*/

bool bic_ato_line_sec_method_BalisesId_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_LINE_SEC_STRING_VALUE(BalisesId);
}/*}}}*/

bool bic_ato_line_sec_method_TrackMenuId_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_LINE_SEC_STRING_VALUE(TrackMenuId);
}/*}}}*/

bool bic_ato_line_sec_method_SignalLightsId_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_LINE_SEC_STRING_VALUE(SignalLightsId);
}/*}}}*/

bool bic_ato_line_sec_method_TimeStamp_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_LINE_SEC_TIME_STAMP_VALUE(TimeStamp);
}/*}}}*/

bool bic_ato_line_sec_method_TimeStampG_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_LINE_SEC_TIME_STAMP_VALUE(TimeStampG);
}/*}}}*/

bool bic_ato_line_sec_method_TimeStampT_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_LINE_SEC_TIME_STAMP_VALUE(TimeStampT);
}/*}}}*/

bool bic_ato_line_sec_method_TimeStampB_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_LINE_SEC_TIME_STAMP_VALUE(TimeStampB);
}/*}}}*/

bool bic_ato_line_sec_method_TimeStampD_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_LINE_SEC_TIME_STAMP_VALUE(TimeStampD);
}/*}}}*/

bool bic_ato_line_sec_method_TimeStampS_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_LINE_SEC_TIME_STAMP_VALUE(TimeStampS);
}/*}}}*/

bool bic_ato_line_sec_method_SchedulTravelTime_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_LINE_SEC_FLOAT_VALUE(SchedulTravelTime);
}/*}}}*/

bool bic_ato_line_sec_method_SectionLength_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_LINE_SEC_FLOAT_VALUE(SectionLength);
}/*}}}*/

bool bic_ato_line_sec_method_StoppingDistMax_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_LINE_SEC_FLOAT_VALUE(StoppingDistMax);
}/*}}}*/

bool bic_ato_line_sec_method_Deceler1DistMax_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_LINE_SEC_FLOAT_VALUE(Deceler1DistMax);
}/*}}}*/

bool bic_ato_line_sec_method_TargDisplac_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ato_line_sec_s *als_ptr = (ato_line_sec_s *)dst_location->v_data_ptr;
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  U16 *ptr = als_ptr->line_sec.TargDisplac;
  U16 *ptr_end = ptr + 10;
  do {
    long long int value = *ptr;

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);
    array_ptr->push(new_location);
  } while(++ptr < ptr_end);

  BIC_SIMPLE_SET_RES(c_bi_class_array,array_ptr);

  return true;
}/*}}}*/

bool bic_ato_line_sec_method_SpeedTargMin_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_LINE_SEC_FLOAT_VALUE(SpeedTargMin);
}/*}}}*/

bool bic_ato_line_sec_method_SpeedTargMax_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_LINE_SEC_FLOAT_VALUE(SpeedTargMax);
}/*}}}*/

bool bic_ato_line_sec_method_SpeedMin_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_LINE_SEC_FLOAT_VALUE(SpeedMin);
}/*}}}*/

bool bic_ato_line_sec_method_SpeedMax_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_LINE_SEC_FLOAT_VALUE(SpeedMax);
}/*}}}*/

bool bic_ato_line_sec_method_SpeedCoastMin_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_LINE_SEC_FLOAT_VALUE(SpeedCoastMin);
}/*}}}*/

bool bic_ato_line_sec_method_TargDisplacMax_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_LINE_SEC_INTEGER_VALUE(TargDisplacMax);
}/*}}}*/

bool bic_ato_line_sec_method_Version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_LINE_SEC_INTEGER_VALUE(Version);
}/*}}}*/

bool bic_ato_line_sec_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ATO_LINE_SEC_ITEM("item#1");
}/*}}}*/

bool bic_ato_line_sec_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ato_line_sec_s *als_ptr = (ato_line_sec_s *)dst_location->v_data_ptr;

  if (als_ptr->line_sec.NofLinePoints > 0)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,0);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_ato_line_sec_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
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

  BIC_ATO_LINE_SEC_CHECK_INDEX();

  if (++index < als_ptr->line_sec.NofLinePoints)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,index);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_ato_line_sec_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ato_line_sec_s *als_ptr = (ato_line_sec_s *)dst_location->v_data_ptr;
  long long int result = als_ptr->line_sec.NofLinePoints;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_ato_line_sec_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("AtoLineSec"),"AtoLineSec");
  );

  return true;
}/*}}}*/

bool bic_ato_line_sec_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("AtoLineSec");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class ATO_LINE_SEC_POINT -
built_in_class_s ato_line_sec_point_class =
{/*{{{*/
  "AtoLineSecPoint",
  c_modifier_public | c_modifier_final,
  4, ato_line_sec_point_methods,
  0, ato_line_sec_point_variables,
  bic_ato_line_sec_point_consts,
  bic_ato_line_sec_point_init,
  bic_ato_line_sec_point_clear,
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

built_in_method_s ato_line_sec_point_methods[] =
{/*{{{*/
  { 
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_ato_line_sec_point_operator_binary_equal
  },
  { 
    "LPindx#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ato_line_sec_point_method_LPindx_0
  },
  { 
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ato_line_sec_point_method_to_string_0
  },
  { 
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ato_line_sec_point_method_print_0
  },
};/*}}}*/

built_in_variable_s ato_line_sec_point_variables[] =
{/*{{{*/
};/*}}}*/

void bic_ato_line_sec_point_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_ato_line_sec_point_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)NULL;
}/*}}}*/

void bic_ato_line_sec_point_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  ato_line_sec_point_s *alsp_ptr = (ato_line_sec_point_s *)location_ptr->v_data_ptr;

  if (alsp_ptr != NULL)
  {
    alsp_ptr->clear(it);
    cfree(alsp_ptr);
  }
}/*}}}*/

bool bic_ato_line_sec_point_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_ato_line_sec_point_method_LPindx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ato_line_sec_point_s *alsp_ptr = (ato_line_sec_point_s *)dst_location->v_data_ptr;
  ato_line_sec_s *als_ptr = (ato_line_sec_s *)alsp_ptr->line_sec_loc->v_data_ptr;

  sLINE_POINT &line_point = als_ptr->line_points[alsp_ptr->index];
  long long int result = line_point.LPindx;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_ato_line_sec_point_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("AtoLineSecPoint"),"AtoLineSecPoint");
  );

  return true;
}/*}}}*/

bool bic_ato_line_sec_point_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("AtoLineSecPoint");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

