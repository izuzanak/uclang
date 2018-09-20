
@begin
include "uctrdpmsh_module.h"
@end

// - UCTRDPMSH indexes of built in classes -
unsigned c_bi_class_trdp_page = c_idx_not_exist;

// - UCTRDPMSH module -
built_in_module_s module =
{/*{{{*/
  1,                      // Class count
  uctrdpmsh_classes,         // Classes

  0,                      // Error base index
  18,                     // Error count
  uctrdpmsh_error_strings,   // Error strings

  uctrdpmsh_initialize,      // Initialize function
  uctrdpmsh_print_exception, // Print exceptions function
};/*}}}*/

// - UCTRDPMSH classes -
built_in_class_s *uctrdpmsh_classes[] =
{/*{{{*/
  &trdp_page_class,
};/*}}}*/

// - UCTRDPMSH error strings -
const char *uctrdpmsh_error_strings[] =
{/*{{{*/
  "error_TRDP_PAGE_DESCR_PROCESS_ERROR",
  "error_TRDP_PAGE_DESCR_TOO_SHORT",
  "error_TRDP_PAGE_DESCR_EXPECTED_STRING_AS_NAME",
  "error_TRDP_PAGE_DESCR_EXPECTED_INTEGER_AS_TYPE",
  "error_TRDP_PAGE_DESCR_EXPECTED_INTEGER_AS_ARRAY_SIZE",
  "error_TRDP_PAGE_DESCR_EXPECTED_INTEGER_AS_VARIABLE_COUNT",
  "error_TRDP_PAGE_DESCR_EXPECTED_INTEGER_AS_STRING_LENGTH",
  "error_TRDP_PAGE_DESCR_EXPECTED_ARRAY_AS_ARRAY_DESCR",
  "error_TRDP_PAGE_DESCR_EXPECTED_ARRAY_AS_STRUCT_DESCR",
  "error_TRDP_PAGE_DESCR_ARRAY_INVALID_VD_COUNT",
  "error_TRDP_PAGE_DESCR_UNSUPPORTED_TYPE",
  "error_TRDP_PAGE_PACK_ERROR",
  "error_TRDP_PAGE_PACK_DICT_ERROR",
  "error_TRDP_PAGE_PACK_INVALID_VARIABLE_COUNT",
  "error_TRDP_PAGE_PACK_INVALID_DATA_SIZE",
  "error_TRDP_PAGE_PACK_INVALID_VARIABLE_TYPE",
  "error_TRDP_PAGE_PACK_INVALID_STRING_LENGTH",
  "error_TRDP_PAGE_UNPACK_ERROR",
};/*}}}*/

// - UCTRDPMSH initialize -
bool uctrdpmsh_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize trdp_page class identifier -
  c_bi_class_trdp_page = class_base_idx++;

  // - retrieve remote dict class index -
  c_rm_class_dict = sp.resolve_class_idx_by_name("Dict",c_idx_not_exist);

  // - ERROR -
  if (c_rm_class_dict == c_idx_not_exist)
  {
    sp.error_code.push(ei_module_cannot_find_remote_class);
    sp.error_code.push(sp.module_names_positions[sp.module_idx].ui_first);
    sp.error_code.push(sp.module_idx);

    return false;
  }

  return true;
}/*}}}*/

// - UCTRDPMSH print exception -
bool uctrdpmsh_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_TRDP_PAGE_DESCR_PROCESS_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP page, page description error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_PAGE_DESCR_TOO_SHORT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP page, description unexpectedly ended\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_PAGE_DESCR_EXPECTED_STRING_AS_NAME:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP page, expected string as variable name\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_PAGE_DESCR_EXPECTED_INTEGER_AS_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP page, expected integer as variable type\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_PAGE_DESCR_EXPECTED_INTEGER_AS_ARRAY_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP page, expected integer as array size\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_PAGE_DESCR_EXPECTED_INTEGER_AS_VARIABLE_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP page, expected integer as variable count\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_PAGE_DESCR_EXPECTED_INTEGER_AS_STRING_LENGTH:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP page, expected integer as string length\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_PAGE_DESCR_EXPECTED_ARRAY_AS_ARRAY_DESCR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP page, expected array as array description\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_PAGE_DESCR_EXPECTED_ARRAY_AS_STRUCT_DESCR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP page, expected array as structure description\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_PAGE_DESCR_ARRAY_INVALID_VD_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP page, invalid count of array variable descriptors\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_PAGE_DESCR_UNSUPPORTED_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP page, unsupported variable type %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_PAGE_PACK_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP page, page pack error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_PAGE_PACK_DICT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP page, page pack from dictionary error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_PAGE_PACK_INVALID_VARIABLE_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP page, invalid variable count\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_PAGE_PACK_INVALID_DATA_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP process data, invalid page size\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_PAGE_PACK_INVALID_VARIABLE_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP page, invalid variable type at position %" HOST_LL_FORMAT "d, expected %s\n",exception.params[0],it.class_symbol_names[it.class_records[exception.params[1]].name_idx].data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_PAGE_PACK_INVALID_STRING_LENGTH:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP page, invalid string length at position %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TRDP_PAGE_UNPACK_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP page, page unpack error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class TRDP_PAGE -
built_in_class_s trdp_page_class =
{/*{{{*/
  "TrdpPage",
  c_modifier_public | c_modifier_final,
  9, trdp_page_methods,
  24, trdp_page_variables,
  bic_trdp_page_consts,
  bic_trdp_page_init,
  bic_trdp_page_clear,
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

built_in_method_s trdp_page_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_trdp_page_operator_binary_equal
  },
  {
    "TrdpPage#1",
    c_modifier_public | c_modifier_final,
    bic_trdp_page_method_TrdpPage_1
  },
  {
    "size#0",
    c_modifier_public | c_modifier_final,
    bic_trdp_page_method_size_0
  },
  {
    "pack#1",
    c_modifier_public | c_modifier_final,
    bic_trdp_page_method_pack_1
  },
  {
    "pack_dict#1",
    c_modifier_public | c_modifier_final,
    bic_trdp_page_method_pack_dict_1
  },
  {
    "unpack#1",
    c_modifier_public | c_modifier_final,
    bic_trdp_page_method_unpack_1
  },
  {
    "unpack_dict#1",
    c_modifier_public | c_modifier_final,
    bic_trdp_page_method_unpack_dict_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trdp_page_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trdp_page_method_print_0
  },
};/*}}}*/

built_in_variable_s trdp_page_variables[] =
{/*{{{*/

  // - trdp variable type constants -
  { "TBOOL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TBYTE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TWORD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TDWORD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TLWORD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TUSINT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TSTRINGB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TINT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TUINT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TUDINT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TREAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TLREAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TBCD8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TTSTAMP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TDATE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TTDsecs", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TTDticks", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TTIMEhm", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TTODhm", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TDThm", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TUNICODE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TSTRING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ANY_ARRAY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ANY_STRUCT", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

#define BIC_TRDP_PAGE_METHOD_PACK(CLEAR_CODE) \
{/*{{{*/\
  string_s *string_ptr = it.get_new_string_ptr();\
  string_ptr->create(tpg_ptr->size);\
  \
  trdp_page_s::pass_s pass = {(unsigned char *)string_ptr->data,array_ptr,0,0,0,0};\
  \
  /* - ERROR - */\
  if (!tpg_ptr->pack_page_data(it,pass))\
  {\
    CLEAR_CODE;\
    \
    string_ptr->clear();\
    cfree(string_ptr);\
    \
    location_s *exception_loc = (location_s *)it.exception_location;\
    if (exception_loc->v_type != c_bi_class_blank)\
    {\
      /* - retrieve thrown exception - */\
      exception_s *exception = (exception_s *)((location_s *)it.exception_location)->v_data_ptr;\
      \
      /* - modify error type and position - */\
      exception->type += module.error_base;\
      exception->position = operands[c_source_pos_idx];\
    }\
    else\
    {\
      exception_s::throw_exception(it,module.error_base + c_error_TRDP_PAGE_PACK_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      return false;\
    }\
    \
    return false;\
  }\
  \
  cassert((pass.address + !!pass.bit_pos) == tpg_ptr->size &&\
          pass.var_idx == tpg_ptr->var_count &&\
          pass.vd_idx == tpg_ptr->var_descrs.used);\
  \
  BIC_SET_RESULT_STRING(string_ptr);\
  \
  CLEAR_CODE;\
}/*}}}*/

#define BIC_TRDP_PAGE_METHOD_UNPACK() \
/*{{{*/\
  trdp_page_s *tpg_ptr = (trdp_page_s *)dst_location->v_data_ptr;\
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;\
  \
  /* - ERROR - */\
  if (string_ptr->size - 1 != tpg_ptr->size)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_TRDP_PAGE_PACK_INVALID_DATA_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
  \
  pointer_array_s *array_ptr = it.get_new_array_ptr();\
  BIC_CREATE_NEW_LOCATION(array_location,c_bi_class_array,array_ptr);\
  \
  trdp_page_s::pass_s pass = {(unsigned char *)string_ptr->data,array_ptr,0,0,0,0};\
  \
  /* - ERROR - */\
  if (!tpg_ptr->unpack_page_data(it,pass))\
  {\
    it.release_location_ptr(array_location);\
    \
    exception_s::throw_exception(it,module.error_base + c_error_TRDP_PAGE_UNPACK_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
  \
  cassert((pass.address + !!pass.bit_pos) == tpg_ptr->size &&\
          pass.vd_idx == tpg_ptr->var_descrs.used);\
/*}}}*/

void bic_trdp_page_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert trdp variable type constants -
  {
    const_locations.push_blanks(24);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 24);

#define CREATE_TRDP_VARIABLE_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_TRDP_VARIABLE_TYPE_BIC_STATIC(TBOOL);
    CREATE_TRDP_VARIABLE_TYPE_BIC_STATIC(TBYTE);
    CREATE_TRDP_VARIABLE_TYPE_BIC_STATIC(TWORD);
    CREATE_TRDP_VARIABLE_TYPE_BIC_STATIC(TDWORD);
    CREATE_TRDP_VARIABLE_TYPE_BIC_STATIC(TLWORD);
    CREATE_TRDP_VARIABLE_TYPE_BIC_STATIC(TUSINT);
    CREATE_TRDP_VARIABLE_TYPE_BIC_STATIC(TSTRINGB);
    CREATE_TRDP_VARIABLE_TYPE_BIC_STATIC(TINT);
    CREATE_TRDP_VARIABLE_TYPE_BIC_STATIC(TUINT);
    CREATE_TRDP_VARIABLE_TYPE_BIC_STATIC(TUDINT);
    CREATE_TRDP_VARIABLE_TYPE_BIC_STATIC(TREAL);
    CREATE_TRDP_VARIABLE_TYPE_BIC_STATIC(TLREAL);
    CREATE_TRDP_VARIABLE_TYPE_BIC_STATIC(TBCD8);
    CREATE_TRDP_VARIABLE_TYPE_BIC_STATIC(TTSTAMP);
    CREATE_TRDP_VARIABLE_TYPE_BIC_STATIC(TDATE);
    CREATE_TRDP_VARIABLE_TYPE_BIC_STATIC(TTDsecs);
    CREATE_TRDP_VARIABLE_TYPE_BIC_STATIC(TTDticks);
    CREATE_TRDP_VARIABLE_TYPE_BIC_STATIC(TTIMEhm);
    CREATE_TRDP_VARIABLE_TYPE_BIC_STATIC(TTODhm);
    CREATE_TRDP_VARIABLE_TYPE_BIC_STATIC(TDThm);
    CREATE_TRDP_VARIABLE_TYPE_BIC_STATIC(TUNICODE);
    CREATE_TRDP_VARIABLE_TYPE_BIC_STATIC(TSTRING);
    CREATE_TRDP_VARIABLE_TYPE_BIC_STATIC(ANY_ARRAY);
    CREATE_TRDP_VARIABLE_TYPE_BIC_STATIC(ANY_STRUCT);
  }

}/*}}}*/

void bic_trdp_page_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (trdp_page_s *)nullptr;
}/*}}}*/

void bic_trdp_page_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  trdp_page_s *tpg_ptr = (trdp_page_s *)location_ptr->v_data_ptr;

  if (tpg_ptr != nullptr)
  {
    tpg_ptr->clear(it);
    cfree(tpg_ptr);
  }
}/*}}}*/

bool bic_trdp_page_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_trdp_page_method_TrdpPage_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_array)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("TrdpPage#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - create trdp_page object -
  trdp_page_s *tpg_ptr = (trdp_page_s *)cmalloc(sizeof(trdp_page_s));
  tpg_ptr->init();

  // - create variable descriptor -
  tpg_ptr->var_descrs.push_blank();
  trdp_var_descr_s &var_descr = tpg_ptr->var_descrs.last();

  // - fill variable descriptor -
  ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();
  var_descr.name_location = (location_s *)it.blank_location;
  var_descr.type = ANY_STRUCT;
  var_descr.address = 0;
  var_descr.length = 0;
  var_descr.size = 0;

  // - create page pass structure -
  trdp_page_s::pass_s pass = {nullptr,nullptr,0,0,0,0};

  // - ERROR -
  unsigned struct_vd_count;
  unsigned struct_vd_idx;
  if (!tpg_ptr->process_page_description(
        it,pass,(pointer_array_s *)src_0_location->v_data_ptr,struct_vd_count,struct_vd_idx))
  {
    tpg_ptr->clear(it);
    cfree(tpg_ptr);

    location_s *exception_loc = (location_s *)it.exception_location;
    if (exception_loc->v_type != c_bi_class_blank)
    {
      // - retrieve thrown exception -
      exception_s *exception = (exception_s *)((location_s *)it.exception_location)->v_data_ptr;

      // - modify error type and position -
      exception->type += module.error_base;
      exception->position = operands[c_source_pos_idx];
    }
    else
    {
      exception_s::throw_exception(it,module.error_base + c_error_TRDP_PAGE_DESCR_PROCESS_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    return false;
  }

  tpg_ptr->var_descrs[0].count = struct_vd_count;

  // - set page size -
  tpg_ptr->size = pass.address + !!pass.bit_pos;

  // - set page count of variables -
  tpg_ptr->var_count = pass.var_idx;

  // - set trdp_page destination location -
  dst_location->v_data_ptr = (trdp_page_s *)tpg_ptr;

  return true;
}/*}}}*/

bool bic_trdp_page_method_size_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  trdp_page_s *tpg_ptr = (trdp_page_s *)dst_location->v_data_ptr;

  long long int result = tpg_ptr->size;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_trdp_page_method_pack_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_array)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("pack#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  trdp_page_s *tpg_ptr = (trdp_page_s *)dst_location->v_data_ptr;
  pointer_array_s *array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (array_ptr->used != tpg_ptr->var_count)
  {
    exception_s::throw_exception(it,module.error_base + c_error_TRDP_PAGE_PACK_INVALID_VARIABLE_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_TRDP_PAGE_METHOD_PACK();

  return true;
}/*}}}*/

bool bic_trdp_page_method_pack_dict_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_rm_class_dict)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("pack_dict#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  trdp_page_s *tpg_ptr = (trdp_page_s *)dst_location->v_data_ptr;

  pointer_array_s *array_ptr = it.get_new_array_ptr();
  BIC_CREATE_NEW_LOCATION(array_location,c_bi_class_array,array_ptr);

  trdp_page_s::pass_s pass = {nullptr,array_ptr,0,0,0,0};

  if (!tpg_ptr->from_dict(it,pass,src_0_location,nullptr))
  {
    it.release_location_ptr(array_location);

    exception_s::throw_exception(it,module.error_base + c_error_TRDP_PAGE_PACK_DICT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  cassert(array_ptr->used == tpg_ptr->var_count &&
          pass.vd_idx == tpg_ptr->var_descrs.used);

  BIC_TRDP_PAGE_METHOD_PACK(
    it.release_location_ptr(array_location);
  );

  return true;
}/*}}}*/

bool bic_trdp_page_method_unpack_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("unpack#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  BIC_TRDP_PAGE_METHOD_UNPACK();

  BIC_SET_RESULT(array_location);

  return true;
}/*}}}*/

bool bic_trdp_page_method_unpack_dict_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("unpack_dict#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  BIC_TRDP_PAGE_METHOD_UNPACK();

  // - reset pass index variables -
  pass.var_idx = 0;
  pass.vd_idx = 0;

  location_s *tree_location = tpg_ptr->to_dict(it,pass,nullptr,nullptr);
  it.release_location_ptr(array_location);

  cassert(pass.var_idx == tpg_ptr->var_count &&
          pass.vd_idx == tpg_ptr->var_descrs.used);

  BIC_SET_RESULT(tree_location);

  return true;
}/*}}}*/

bool bic_trdp_page_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TrdpPage"),"TrdpPage");
  );

  return true;
}/*}}}*/

bool bic_trdp_page_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("TrdpPage");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

