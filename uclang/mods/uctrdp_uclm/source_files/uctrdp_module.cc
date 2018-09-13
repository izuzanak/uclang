
@begin
include "uctrdp_module.h"
@end

// - UCTRDP indexes of built in classes -
unsigned c_bi_class_trdp_pd = c_idx_not_exist;

// - UCTRDP module -
built_in_module_s module =
{/*{{{*/
  1,                      // Class count
  uctrdp_classes,         // Classes

  0,                      // Error base index
  1,                      // Error count
  uctrdp_error_strings,   // Error strings

  uctrdp_initialize,      // Initialize function
  uctrdp_print_exception, // Print exceptions function
};/*}}}*/

// - UCTRDP classes -
built_in_class_s *uctrdp_classes[] =
{/*{{{*/
  &trdp_pd_class,
};/*}}}*/

// - UCTRDP error strings -
const char *uctrdp_error_strings[] =
{/*{{{*/
  "error_TRDP_PD_DUMMY_ERROR",
};/*}}}*/

// - UCTRDP initialize -
bool uctrdp_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize trdp_pd class identifier -
  c_bi_class_trdp_pd = class_base_idx++;

  return true;
}/*}}}*/

// - UCTRDP print exception -
bool uctrdp_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_TRDP_PD_DUMMY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTRDP process data dummy error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class TRDP_PD -
built_in_class_s trdp_pd_class =
{/*{{{*/
  "TrdpPd",
  c_modifier_public | c_modifier_final,
  4, trdp_pd_methods,
  9 + 3 + 9 + 1 + 6 + 4, trdp_pd_variables,
  bic_trdp_pd_consts,
  bic_trdp_pd_init,
  bic_trdp_pd_clear,
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

built_in_method_s trdp_pd_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_trdp_pd_operator_binary_equal
  },
  {
    "TrdpPd#1",
    c_modifier_public | c_modifier_final,
    bic_trdp_pd_method_TrdpPd_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trdp_pd_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_trdp_pd_method_print_0
  },
};/*}}}*/

built_in_variable_s trdp_pd_variables[] =
{/*{{{*/

  // - trdp generic code constants -
  { "TRDP_OK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TRDP_FAIL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TRDP_ABORT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TRDP_OUT_OF_MEMORY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TRDP_TIMEOUT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TRDP_SOCKET_ERROR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TRDP_TERMINATE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TRDP_PENDING", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TRDP_REM_ERROR", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - trdp mode constants -
  { "MODE_UNKNOWN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MODE_CONFIG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MODE_FULLOP", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - trdp qos constants -
  { "QOS_DEF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "QOS_P0", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "QOS_P1", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "QOS_P2", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "QOS_P3", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "QOS_P4", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "QOS_P5", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "QOS_P6", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "QOS_P7", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - trdp ttl constants -
  { "TTL_DEF", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - communication scope constants -
  { "CS_LOCAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CS_ETB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CS_ETB_TOPO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CS_OPT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CS_OPT_TOPO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CS_ETB_ZERO", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - max data size constants -
  { "MAX_PD_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAX_MD_SIZE", c_modifier_public | c_modifier_static | c_modifier_static_const },

  { "MAX_USR_LEN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MAX_HST_LEN", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_trdp_pd_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert trdp generic code constants -
  {
    const_locations.push_blanks(9);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 9);

#define CREATE_TRDP_GENERIC_CODE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_TRDP_GENERIC_CODE_BIC_STATIC(TRDP::TRDP_OK);
    CREATE_TRDP_GENERIC_CODE_BIC_STATIC(TRDP::TRDP_FAIL);
    CREATE_TRDP_GENERIC_CODE_BIC_STATIC(TRDP::TRDP_ABORT);
    CREATE_TRDP_GENERIC_CODE_BIC_STATIC(TRDP::TRDP_OUT_OF_MEMORY);
    CREATE_TRDP_GENERIC_CODE_BIC_STATIC(TRDP::TRDP_TIMEOUT);
    CREATE_TRDP_GENERIC_CODE_BIC_STATIC(TRDP::TRDP_SOCKET_ERROR);
    CREATE_TRDP_GENERIC_CODE_BIC_STATIC(TRDP::TRDP_TERMINATE);
    CREATE_TRDP_GENERIC_CODE_BIC_STATIC(TRDP::TRDP_PENDING);
    CREATE_TRDP_GENERIC_CODE_BIC_STATIC(TRDP::TRDP_REM_ERROR);
  }

  // - insert trdp mode constants -
  {
    const_locations.push_blanks(3);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 3);

#define CREATE_TRDP_MODE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_TRDP_MODE_BIC_STATIC(TRDP::MODE_UNKNOWN);
    CREATE_TRDP_MODE_BIC_STATIC(TRDP::MODE_CONFIG);
    CREATE_TRDP_MODE_BIC_STATIC(TRDP::MODE_FULLOP);
  }

  // - insert trdp qos constants -
  {
    const_locations.push_blanks(9);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 9);

#define CREATE_TRDP_QOS_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_TRDP_QOS_BIC_STATIC(TRDP::QOS_DEF);
    CREATE_TRDP_QOS_BIC_STATIC(TRDP::QOS_P0);
    CREATE_TRDP_QOS_BIC_STATIC(TRDP::QOS_P1);
    CREATE_TRDP_QOS_BIC_STATIC(TRDP::QOS_P2);
    CREATE_TRDP_QOS_BIC_STATIC(TRDP::QOS_P3);
    CREATE_TRDP_QOS_BIC_STATIC(TRDP::QOS_P4);
    CREATE_TRDP_QOS_BIC_STATIC(TRDP::QOS_P5);
    CREATE_TRDP_QOS_BIC_STATIC(TRDP::QOS_P6);
    CREATE_TRDP_QOS_BIC_STATIC(TRDP::QOS_P7);
  }

  // - insert trdp ttl constants -
  {
    const_locations.push_blanks(1);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 1);

#define CREATE_TRDP_TTL_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_TRDP_TTL_BIC_STATIC(TRDP::TTL_DEF);
  }

  // - insert communication scope constants -
  {
    const_locations.push_blanks(6);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 6);

#define CREATE_TRDP_CS_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_TRDP_CS_BIC_STATIC(TRDP::CS_LOCAL);
    CREATE_TRDP_CS_BIC_STATIC(TRDP::CS_ETB);
    CREATE_TRDP_CS_BIC_STATIC(TRDP::CS_ETB_TOPO);
    CREATE_TRDP_CS_BIC_STATIC(TRDP::CS_OPT);
    CREATE_TRDP_CS_BIC_STATIC(TRDP::CS_OPT_TOPO);
    CREATE_TRDP_CS_BIC_STATIC(TRDP::CS_ETB_ZERO);
  }

  // - insert max data size constants -
  {
    const_locations.push_blanks(4);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 4);

#define CREATE_TRDP_DATA_SIZE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_TRDP_DATA_SIZE_BIC_STATIC(TRDP::MAX_PD_SIZE);
    CREATE_TRDP_DATA_SIZE_BIC_STATIC(TRDP::MAX_MD_SIZE);

    CREATE_TRDP_DATA_SIZE_BIC_STATIC(TRDP::MAX_USR_LEN);
    CREATE_TRDP_DATA_SIZE_BIC_STATIC(TRDP::MAX_HST_LEN);
  }

}/*}}}*/

void bic_trdp_pd_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (TRDP::PD *)nullptr;
}/*}}}*/

void bic_trdp_pd_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  TRDP::PD *pd_ptr = (TRDP::PD *)location_ptr->v_data_ptr;

  if (pd_ptr != nullptr)
  {
    delete pd_ptr;
  }
}/*}}}*/

bool bic_trdp_pd_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_trdp_pd_method_TrdpPd_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  
  // FIXME TODO continue ...
  BIC_TODO_ERROR(__FILE__,__LINE__);
  return false;
}/*}}}*/

bool bic_trdp_pd_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("TrdpPd"),"TrdpPd");
  );

  return true;
}/*}}}*/

bool bic_trdp_pd_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("TrdpPd");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

