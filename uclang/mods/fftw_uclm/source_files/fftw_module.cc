
@begin
include "fftw_module.h"
@end

// - FFTW indexes of built in classes -
unsigned c_bi_class_fftw = c_idx_not_exist;
unsigned c_bi_class_fftw_plan = c_idx_not_exist;

// - FFTW module -
built_in_module_s module =
{/*{{{*/
  2,                    // Class count
  fftw_classes,         // Classes

  0,                    // Error base index
  1,                    // Error count
  fftw_error_strings,   // Error strings

  fftw_initialize,      // Initialize function
  fftw_print_exception, // Print exceptions function
};/*}}}*/

// - FFTW classes -
built_in_class_s *fftw_classes[] =
{/*{{{*/
  &fftw_class,
  &fftw_plan_class,
};/*}}}*/

// - FFTW error strings -
const char *fftw_error_strings[] =
{/*{{{*/
  "error_FFTW_DUMMY_ERROR",
};/*}}}*/

// - FFTW initialize -
bool fftw_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize fftw class identifier -
  c_bi_class_fftw = class_base_idx++;

  // - initialize fftw_plan class identifier -
  c_bi_class_fftw_plan = class_base_idx++;

  return true;
}/*}}}*/

// - FFTW print exception -
bool fftw_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_FFTW_DUMMY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFFTW dummy error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class FFTW -
built_in_class_s fftw_class =
{/*{{{*/
  "Fftw",
  c_modifier_public | c_modifier_final,
  3, fftw_methods,
  2 + 1 + 9, fftw_variables,
  bic_fftw_consts,
  bic_fftw_init,
  bic_fftw_clear,
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

built_in_method_s fftw_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_fftw_operator_binary_equal
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_fftw_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_fftw_method_print_0
  },
};/*}}}*/

built_in_variable_s fftw_variables[] =
{/*{{{*/

  // - fftw direction constants -
  { "FFTW_FORWARD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FFTW_BACKWARD", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - fftw timelimit constants -
  { "FFTW_NO_TIMELIMIT", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - fftw flag constants -
  { "FFTW_MEASURE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FFTW_DESTROY_INPUT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FFTW_UNALIGNED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FFTW_CONSERVE_MEMORY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FFTW_EXHAUSTIVE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FFTW_PRESERVE_INPUT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FFTW_PATIENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FFTW_ESTIMATE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FFTW_WISDOM_ONLY", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_fftw_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert fftw direction constants -
  {
    const_locations.push_blanks(2);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 2);

#define CREATE_FFTW_DIRECTION_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_FFTW_DIRECTION_BIC_STATIC(FFTW_FORWARD);
    CREATE_FFTW_DIRECTION_BIC_STATIC(FFTW_BACKWARD);
  }

  // - insert fftw timelimit constants -
  {
    const_locations.push_blanks(1);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 1);

#define CREATE_FFTW_TIMELIMIT_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_float;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (double)VALUE;\
  cv_ptr++;

    CREATE_FFTW_TIMELIMIT_BIC_STATIC(FFTW_NO_TIMELIMIT);
  }

  // - insert fftw flag constants -
  {
    const_locations.push_blanks(9);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 9);

#define CREATE_FFTW_FLAG_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_FFTW_FLAG_BIC_STATIC(FFTW_MEASURE);
    CREATE_FFTW_FLAG_BIC_STATIC(FFTW_DESTROY_INPUT);
    CREATE_FFTW_FLAG_BIC_STATIC(FFTW_UNALIGNED);
    CREATE_FFTW_FLAG_BIC_STATIC(FFTW_CONSERVE_MEMORY);
    CREATE_FFTW_FLAG_BIC_STATIC(FFTW_EXHAUSTIVE);
    CREATE_FFTW_FLAG_BIC_STATIC(FFTW_PRESERVE_INPUT);
    CREATE_FFTW_FLAG_BIC_STATIC(FFTW_PATIENT);
    CREATE_FFTW_FLAG_BIC_STATIC(FFTW_ESTIMATE);
    CREATE_FFTW_FLAG_BIC_STATIC(FFTW_WISDOM_ONLY);
  }

}/*}}}*/

void bic_fftw_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_fftw_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_fftw_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_fftw_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Fftw"),"Fftw");
  );

  return true;
}/*}}}*/

bool bic_fftw_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Fftw");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class FFTW_PLAN -
built_in_class_s fftw_plan_class =
{/*{{{*/
  "FftwPlan",
  c_modifier_public | c_modifier_final,
  4, fftw_plan_methods,
  0, fftw_plan_variables,
  bic_fftw_plan_consts,
  bic_fftw_plan_init,
  bic_fftw_plan_clear,
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

built_in_method_s fftw_plan_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_fftw_plan_operator_binary_equal
  },
  {
    "FftwPlan#0",
    c_modifier_public | c_modifier_final,
    bic_fftw_plan_method_FftwPlan_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_fftw_plan_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_fftw_plan_method_print_0
  },
};/*}}}*/

built_in_variable_s fftw_plan_variables[] =
{/*{{{*/
};/*}}}*/

void bic_fftw_plan_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_fftw_plan_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (fftw_plan_s *)nullptr;
}/*}}}*/

void bic_fftw_plan_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  fftw_plan_s *fp_ptr = (fftw_plan_s *)location_ptr->v_data_ptr;

  if (fp_ptr != nullptr)
  {
    fp_ptr->clear(it);
    cfree(fp_ptr);
  }
}/*}}}*/

bool bic_fftw_plan_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_fftw_plan_method_FftwPlan_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/

  // FIXME TODO continue ...
  BIC_TODO_ERROR(__FILE__,__LINE__);
  return false;
}/*}}}*/

bool bic_fftw_plan_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("FftwPlan"),"FftwPlan");
  );

  return true;
}/*}}}*/

bool bic_fftw_plan_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("FftwPlan");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

