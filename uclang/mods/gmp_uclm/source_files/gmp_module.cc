
@begin
include "gmp_module.h"
@end

// - GMP indexes of built in classes -
unsigned c_bi_class_gmp = c_idx_not_exist;
unsigned c_bi_class_gmp_integer = c_idx_not_exist;
unsigned c_bi_class_gmp_rational = c_idx_not_exist;
unsigned c_bi_class_mpfr_fixed = c_idx_not_exist;

// - GMP module -
built_in_module_s module =
{/*{{{*/
  4,                   // Class count
  gmp_classes,         // Classes

  0,                   // Error base index
  2,                   // Error count
  gmp_error_strings,   // Error strings

  gmp_initialize,      // Initialize function
  gmp_print_exception, // Print exceptions function
};/*}}}*/

// - GMP classes -
built_in_class_s *gmp_classes[] =
{/*{{{*/
  &gmp_class,
  &gmp_integer_class,
  &gmp_rational_class,
  &mpfr_fixed_class,
};/*}}}*/

// - GMP error strings -
const char *gmp_error_strings[] =
{/*{{{*/
  "error_GMP_NUMBER_BASE_OUT_OF_RANGE",
  "error_GMP_NUMBER_CONVERT_INVALID_STRING",
};/*}}}*/

// - GMP initialize -
bool gmp_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize gmp class identifier -
  c_bi_class_gmp = class_base_idx++;

  // - initialize gmp_integer class identifier -
  c_bi_class_gmp_integer = class_base_idx++;

  // - initialize gmp_rational class identifier -
  c_bi_class_gmp_rational = class_base_idx++;

  // - initialize mpfr_fixed class identifier -
  c_bi_class_mpfr_fixed = class_base_idx++;

  return true;
}/*}}}*/

// - GMP print exception -
bool gmp_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_GMP_NUMBER_BASE_OUT_OF_RANGE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\n%s number base %" HOST_LL_FORMAT "d, is out of range <2, 62>\n",
        it.class_symbol_names[it.class_records[exception.params[0]].name_idx].data,exception.params[1]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GMP_NUMBER_CONVERT_INVALID_STRING:
  {
    string_s *string_ptr = (string_s *)((location_s *)exception.obj_location)->v_data_ptr;

    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\n%s conversion, invalid string literal \"%s\"",
        it.class_symbol_names[it.class_records[exception.params[0]].name_idx].data,string_ptr->data);

    if (exception.params[1] != 0)
    {
      fprintf(stderr," for base %" HOST_LL_FORMAT "d\n",exception.params[1]);
    }
    else
    {
      fprintf(stderr,"\n");
    }

    fprintf(stderr," ---------------------------------------- \n");
  }
  break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class GMP -
built_in_class_s gmp_class =
{/*{{{*/
  "Gmp",
  c_modifier_public | c_modifier_final,
  2, gmp_methods,
  0, gmp_variables,
  bic_gmp_consts,
  bic_gmp_init,
  bic_gmp_clear,
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

built_in_method_s gmp_methods[] =
{/*{{{*/
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gmp_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gmp_method_print_0
  },
};/*}}}*/

built_in_variable_s gmp_variables[] =
{/*{{{*/
};/*}}}*/

void bic_gmp_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_gmp_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_gmp_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_gmp_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Gmp"),"Gmp");
  );

  return true;
}/*}}}*/

bool bic_gmp_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("Gmp");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class GMP_INTEGER -
built_in_class_s gmp_integer_class =
{/*{{{*/
  "GmpInteger",
  c_modifier_public | c_modifier_final,
  43, gmp_integer_methods,
  0, gmp_integer_variables,
  bic_gmp_integer_consts,
  bic_gmp_integer_init,
  bic_gmp_integer_clear,
  bic_gmp_integer_compare,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  bic_gmp_integer_pack,
  bic_gmp_integer_unpack,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s gmp_integer_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_operator_binary_equal
  },
  {
    "operator_binary_plus_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_operator_binary_plus_equal
  },
  {
    "operator_binary_minus_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_operator_binary_minus_equal
  },
  {
    "operator_binary_asterisk_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_operator_binary_asterisk_equal
  },
  {
    "operator_binary_slash_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_operator_binary_slash_equal
  },
  {
    "operator_binary_percent_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_operator_binary_percent_equal
  },
  {
    "operator_binary_double_ls_br_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_operator_binary_double_ls_br_equal
  },
  {
    "operator_binary_double_rs_br_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_operator_binary_double_rs_br_equal
  },
  {
    "operator_binary_ampersand_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_operator_binary_ampersand_equal
  },
  {
    "operator_binary_pipe_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_operator_binary_pipe_equal
  },
  {
    "operator_binary_circumflex_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_operator_binary_circumflex_equal
  },
  {
    "operator_binary_double_ampersand#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_operator_binary_double_ampersand
  },
  {
    "operator_binary_double_pipe#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_operator_binary_double_pipe
  },
  {
    "operator_binary_ampersand#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_operator_binary_ampersand
  },
  {
    "operator_binary_pipe#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_operator_binary_pipe
  },
  {
    "operator_binary_circumflex#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_operator_binary_circumflex
  },
  {
    "operator_binary_double_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_operator_binary_double_equal
  },
  {
    "operator_binary_exclamation_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_operator_binary_exclamation_equal
  },
  {
    "operator_binary_rs_br#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_operator_binary_rs_br
  },
  {
    "operator_binary_ls_br#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_operator_binary_ls_br
  },
  {
    "operator_binary_rs_br_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_operator_binary_rs_br_equal
  },
  {
    "operator_binary_ls_br_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_operator_binary_ls_br_equal
  },
  {
    "operator_binary_double_rs_br#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_operator_binary_double_rs_br
  },
  {
    "operator_binary_double_ls_br#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_operator_binary_double_ls_br
  },
  {
    "operator_binary_plus#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_operator_binary_plus
  },
  {
    "operator_binary_minus#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_operator_binary_minus
  },
  {
    "operator_binary_asterisk#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_operator_binary_asterisk
  },
  {
    "operator_binary_slash#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_operator_binary_slash
  },
  {
    "operator_binary_percent#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_operator_binary_percent
  },
  {
    "operator_unary_post_double_plus#0",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_operator_unary_post_double_plus
  },
  {
    "operator_unary_post_double_minus#0",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_operator_unary_post_double_minus
  },
  {
    "operator_unary_pre_double_plus#0",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_operator_unary_pre_double_plus
  },
  {
    "operator_unary_pre_double_minus#0",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_operator_unary_pre_double_minus
  },
  {
    "operator_unary_pre_plus#0",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_operator_unary_pre_plus
  },
  {
    "operator_unary_pre_minus#0",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_operator_unary_pre_minus
  },
  {
    "operator_unary_pre_exclamation#0",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_operator_unary_pre_exclamation
  },
  {
    "operator_unary_pre_tilde#0",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_operator_unary_pre_tilde
  },
  {
    "GmpInteger#0",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_method_GmpInteger_0
  },
  {
    "GmpInteger#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_method_GmpInteger_1
  },
  {
    "GmpInteger#2",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_method_GmpInteger_2
  },
  {
    "compare#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_method_compare_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_gmp_integer_method_print_0
  },
};/*}}}*/

built_in_variable_s gmp_integer_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_GMP_INTEGER_BINARY_ADD_SUB_EQUAL(OPERATION,NAME) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
  \
  mpz_t *res_ptr = (mpz_t *)cmalloc(sizeof(mpz_t));\
  mpz_init(*res_ptr);\
  \
  mpz_t *mpz_ptr = (mpz_t *)((location_s *)dst_location)->v_data_ptr;\
  \
  switch (src_0_location->v_type) {\
  case c_bi_class_char:\
    gmp_c::OPERATION ## _lli(*res_ptr,*mpz_ptr,(char)src_0_location->v_data_ptr);\
    break;\
  case c_bi_class_integer:\
    gmp_c::OPERATION ## _lli(*res_ptr,*mpz_ptr,(long long int)src_0_location->v_data_ptr);\
    break;\
  case c_bi_class_float:\
    gmp_c::OPERATION ## _lli(*res_ptr,*mpz_ptr,(double)src_0_location->v_data_ptr);\
    break;\
  default:\
    if (src_0_location->v_type == c_bi_class_gmp_integer)\
    {\
      OPERATION(*res_ptr,*mpz_ptr,*((mpz_t *)src_0_location->v_data_ptr));\
    }\
    else if (src_0_location->v_type == c_bi_class_gmp_rational)\
    {\
      mpz_set_q(*res_ptr,*((mpq_t *)src_0_location->v_data_ptr));\
      OPERATION(*res_ptr,*mpz_ptr,*res_ptr);\
    }\
    else if (src_0_location->v_type == c_bi_class_mpfr_fixed)\
    {\
      mpfr_get_z(*res_ptr,*((mpfr_t *)src_0_location->v_data_ptr),MPFR_RNDD);\
      OPERATION(*res_ptr,*mpz_ptr,*res_ptr);\
    }\
    else\
    {\
      mpz_clear(*res_ptr);\
      cfree(res_ptr);\
      \
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
      \
      return false;\
    }\
  }\
  \
  BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_gmp_integer,res_ptr,2);\
  \
  BIC_SET_DESTINATION(new_location);\
  BIC_SET_RESULT(new_location);\
}/*}}}*/

#define BIC_GMP_INTEGER_BINARY_SHIFT(OPERATION,NAME) \
/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
  \
  mpz_t *res_ptr = (mpz_t *)cmalloc(sizeof(mpz_t));\
  mpz_init(*res_ptr);\
  \
  mpz_t *mpz_ptr = (mpz_t *)((location_s *)dst_location)->v_data_ptr;\
  \
  switch (src_0_location->v_type) {\
  case c_bi_class_char:\
  {\
    char shift_count = (char)src_0_location->v_data_ptr;\
    if (shift_count < 0)\
    {\
      mpz_clear(*res_ptr);\
      cfree(res_ptr);\
      \
      exception_s *new_exception = exception_s::throw_exception(it,c_error_NEGATIVE_SHIFT_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      new_exception->params.push((long long int)shift_count);\
      \
      return false;\
    }\
    \
    mpz_ ## OPERATION(*res_ptr,*mpz_ptr,shift_count);\
  }\
  break;\
  case c_bi_class_integer:\
  {\
    long long int shift_count = (long long int)src_0_location->v_data_ptr;\
    if (shift_count < 0)\
    {\
      mpz_clear(*res_ptr);\
      cfree(res_ptr);\
      \
      exception_s *new_exception = exception_s::throw_exception(it,c_error_NEGATIVE_SHIFT_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      new_exception->params.push(shift_count);\
      \
      return false;\
    }\
    \
    mpz_ ## OPERATION(*res_ptr,*mpz_ptr,shift_count);\
  }\
  break;\
  default:\
    mpz_clear(*res_ptr);\
    cfree(res_ptr);\
    \
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
    new_exception->params.push(1);\
    new_exception->params.push(src_0_location->v_type);\
    \
    return false;\
  }\
/*}}}*/

#define BIC_GMP_INTEGER_BINARY_BIT_LOGIC(OPERATION,NAME) \
/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
  \
  mpz_t *res_ptr = (mpz_t *)cmalloc(sizeof(mpz_t));\
  mpz_init(*res_ptr);\
  \
  mpz_t *mpz_ptr = (mpz_t *)((location_s *)dst_location)->v_data_ptr;\
  \
  switch (src_0_location->v_type) {\
  case c_bi_class_char:\
    mpz_set_si(*res_ptr,(char)src_0_location->v_data_ptr);\
    OPERATION(*res_ptr,*mpz_ptr,*res_ptr);\
    break;\
  case c_bi_class_integer:\
    gmp_c::mpz_set_lli(*res_ptr,(long long int)src_0_location->v_data_ptr);\
    OPERATION(*res_ptr,*mpz_ptr,*res_ptr);\
    break;\
  default:\
    if (src_0_location->v_type == c_bi_class_gmp_integer)\
    {\
      OPERATION(*res_ptr,*mpz_ptr,*((mpz_t *)src_0_location->v_data_ptr));\
    }\
    else\
    {\
      mpz_clear(*res_ptr);\
      cfree(res_ptr);\
      \
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
      \
      return false;\
    }\
  }\
/*}}}*/

#define BIC_GMP_INTEGER_BINARY_LOGIC(OPERATOR,NAME) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
  \
  long long int result;\
  \
  mpz_t *mpz_ptr = (mpz_t *)dst_location->v_data_ptr;\
  \
  switch (src_0_location->v_type) {\
  case c_bi_class_char:\
    result = mpz_sgn(*mpz_ptr) OPERATOR (char)src_0_location->v_data_ptr;\
    break;\
  case c_bi_class_integer:\
    result = mpz_sgn(*mpz_ptr) OPERATOR (long long int)src_0_location->v_data_ptr;\
    break;\
  case c_bi_class_float:\
    result = mpz_sgn(*mpz_ptr) OPERATOR (double)src_0_location->v_data_ptr;\
    break;\
  default:\
    if (src_0_location->v_type == c_bi_class_gmp_integer)\
    {\
      result = mpz_sgn(*mpz_ptr) OPERATOR mpz_sgn(*((mpz_t *)src_0_location->v_data_ptr));\
    }\
    else if (src_0_location->v_type == c_bi_class_gmp_rational)\
    {\
      result = mpz_sgn(*mpz_ptr) OPERATOR mpq_sgn(*((mpq_t *)src_0_location->v_data_ptr));\
    }\
    else if (src_0_location->v_type == c_bi_class_mpfr_fixed)\
    {\
      result = mpz_sgn(*mpz_ptr) OPERATOR mpfr_sgn(*((mpfr_t *)src_0_location->v_data_ptr));\
    }\
    else\
    {\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
      \
      return false;\
    }\
  }\
  \
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
}/*}}}*/

#define BIC_GMP_INTEGER_COMPARE_WITH_TYPE_BOOL() \
{/*{{{*/\
  mpz_t *mpz_ptr = (mpz_t *)dst_location->v_data_ptr;\
  \
  switch (src_0_location->v_type) {\
  case c_bi_class_char:\
    result = mpz_cmp_si(*mpz_ptr,(char)src_0_location->v_data_ptr) == 0;\
    break;\
  case c_bi_class_integer:\
    result = gmp_c::mpz_cmp_lli(*mpz_ptr,(long long int)src_0_location->v_data_ptr) == 0;\
    break;\
  case c_bi_class_float:\
    result = mpz_cmp_d(*mpz_ptr,(double)src_0_location->v_data_ptr) == 0;\
    break;\
  default:\
    if (src_0_location->v_type == c_bi_class_gmp_integer)\
    {\
      result = mpz_cmp(*mpz_ptr,*((mpz_t *)src_0_location->v_data_ptr)) == 0;\
    }\
    else if (src_0_location->v_type == c_bi_class_gmp_rational)\
    {\
      result = mpq_cmp_z(*((mpq_t *)src_0_location->v_data_ptr),*mpz_ptr) == 0;\
    }\
    else if (src_0_location->v_type == c_bi_class_mpfr_fixed)\
    {\
      result = mpfr_cmp_z(*((mpfr_t *)src_0_location->v_data_ptr),*mpz_ptr) == 0;\
    }\
    else\
    {\
      result = 0;\
    }\
  }\
}/*}}}*/

#define BIC_GMP_INTEGER_COMPARE_WITH_TYPE_INT(NAME) \
{/*{{{*/\
  mpz_t *mpz_ptr = (mpz_t *)dst_location->v_data_ptr;\
  \
  switch (src_0_location->v_type) {\
  case c_bi_class_char:\
    result = mpz_cmp_si(*mpz_ptr,(char)src_0_location->v_data_ptr);\
    break;\
  case c_bi_class_integer:\
    result = gmp_c::mpz_cmp_lli(*mpz_ptr,(long long int)src_0_location->v_data_ptr);\
    break;\
  case c_bi_class_float:\
    result = mpz_cmp_d(*mpz_ptr,(double)src_0_location->v_data_ptr);\
    break;\
  default:\
    if (src_0_location->v_type == c_bi_class_gmp_integer)\
    {\
      result = mpz_cmp(*mpz_ptr,*((mpz_t *)src_0_location->v_data_ptr));\
    }\
    else if (src_0_location->v_type == c_bi_class_gmp_rational)\
    {\
      result = -mpq_cmp_z(*((mpq_t *)src_0_location->v_data_ptr),*mpz_ptr);\
    }\
    else if (src_0_location->v_type == c_bi_class_mpfr_fixed)\
    {\
      result = -mpfr_cmp_z(*((mpfr_t *)src_0_location->v_data_ptr),*mpz_ptr);\
    }\
    else\
    {\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
      \
      return false;\
    }\
  }\
}/*}}}*/

#define BIC_GMP_INTEGER_BINARY_ADD_SUB_MUL(OPERATION,NAME) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
  \
  mpz_t *mpz_ptr = (mpz_t *)((location_s *)dst_location)->v_data_ptr;\
  \
  switch (src_0_location->v_type) {\
  case c_bi_class_char:\
  {\
    mpz_t *res_ptr = (mpz_t *)cmalloc(sizeof(mpz_t));\
    mpz_init(*res_ptr);\
    gmp_c::mpz_ ## OPERATION ## _lli(*res_ptr,*mpz_ptr,(char)src_0_location->v_data_ptr);\
    \
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gmp_integer,res_ptr);\
    BIC_SET_RESULT(new_location);\
  }\
  break;\
  case c_bi_class_integer:\
  {\
    mpz_t *res_ptr = (mpz_t *)cmalloc(sizeof(mpz_t));\
    mpz_init(*res_ptr);\
    gmp_c::mpz_ ## OPERATION ## _lli(*res_ptr,*mpz_ptr,(long long int)src_0_location->v_data_ptr);\
    \
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gmp_integer,res_ptr);\
    BIC_SET_RESULT(new_location);\
  }\
  break;\
  case c_bi_class_float:\
  {\
    mpfr_t *res_ptr = (mpfr_t *)cmalloc(sizeof(mpfr_t));\
    mpfr_init_set_z(*res_ptr,*mpz_ptr,MPFR_RNDD);\
    mpfr_ ## OPERATION ## _d(*res_ptr,*res_ptr,(double)src_0_location->v_data_ptr,MPFR_RNDD);\
    \
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mpfr_fixed,res_ptr);\
    BIC_SET_RESULT(new_location);\
  }\
  break;\
  default:\
    if (src_0_location->v_type == c_bi_class_gmp_integer)\
    {\
      mpz_t *res_ptr = (mpz_t *)cmalloc(sizeof(mpz_t));\
      mpz_init(*res_ptr);\
      mpz_ ## OPERATION(*res_ptr,*mpz_ptr,*((mpz_t *)src_0_location->v_data_ptr));\
      \
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gmp_integer,res_ptr);\
      BIC_SET_RESULT(new_location);\
    }\
    else if (src_0_location->v_type == c_bi_class_gmp_rational)\
    {\
      mpq_t *res_ptr = (mpq_t *)cmalloc(sizeof(mpq_t));\
      mpq_init(*res_ptr);\
      mpq_set_z(*res_ptr,*mpz_ptr);\
      mpq_ ## OPERATION(*res_ptr,*res_ptr,*((mpq_t *)src_0_location->v_data_ptr));\
      \
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gmp_rational,res_ptr);\
      BIC_SET_RESULT(new_location);\
    }\
    else if (src_0_location->v_type == c_bi_class_mpfr_fixed)\
    {\
      mpfr_t *res_ptr = (mpfr_t *)cmalloc(sizeof(mpfr_t));\
      mpfr_init_set_z(*res_ptr,*mpz_ptr,MPFR_RNDD);\
      mpfr_ ## OPERATION(*res_ptr,*res_ptr,*((mpfr_t *)src_0_location->v_data_ptr),MPFR_RNDD);\
      \
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mpfr_fixed,res_ptr);\
      BIC_SET_RESULT(new_location);\
    }\
    else\
    {\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
      \
      return false;\
    }\
  }\
}/*}}}*/

#define BIC_GMP_INTEGER_POST_UNARY_INC_DEC(OPERATION) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  \
  mpz_t *res_ptr = (mpz_t *)cmalloc(sizeof(mpz_t));\
  mpz_init(*res_ptr);\
  \
  mpz_t *mpz_ptr = (mpz_t *)((location_s *)dst_location)->v_data_ptr;\
  mpz_ ## OPERATION ## _ui(*res_ptr,*mpz_ptr,1);\
  \
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gmp_integer,res_ptr);\
  BIC_SET_RESULT(new_location);\
  \
  pointer tmp_location = res_location;\
  res_location = dst_location;\
  dst_location = tmp_location;\
}/*}}}*/

#define BIC_GMP_INTEGER_PRE_UNARY_INC_DEC(OPERATION) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  \
  mpz_t *res_ptr = (mpz_t *)cmalloc(sizeof(mpz_t));\
  mpz_init(*res_ptr);\
  \
  mpz_t *mpz_ptr = (mpz_t *)((location_s *)dst_location)->v_data_ptr;\
  mpz_ ## OPERATION ## _ui(*res_ptr,*mpz_ptr,1);\
  \
  BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_gmp_integer,res_ptr,2);\
  \
  BIC_SET_DESTINATION(new_location);\
  BIC_SET_RESULT(new_location);\
}/*}}}*/

#define BIC_GMP_INTEGER_PRE_UNARY_TMP_RESULT(OPERATION) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  \
  mpz_t *res_ptr = (mpz_t *)cmalloc(sizeof(mpz_t));\
  mpz_init(*res_ptr);\
  \
  mpz_ ## OPERATION(*res_ptr,*((mpz_t *)dst_location->v_data_ptr));\
  \
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gmp_integer,res_ptr);\
  BIC_SET_RESULT(new_location);\
  \
  return true;\
}/*}}}*/

void bic_gmp_integer_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_gmp_integer_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  mpz_t *mpz_ptr = (mpz_t *)cmalloc(sizeof(mpz_t));
  mpz_init(*mpz_ptr);
  location_ptr->v_data_ptr = mpz_ptr;
}/*}}}*/

void bic_gmp_integer_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  mpz_t *mpz_ptr = (mpz_t *)location_ptr->v_data_ptr;
  mpz_clear(*mpz_ptr);
  cfree(mpz_ptr);
}/*}}}*/

int bic_gmp_integer_compare(location_s *first_loc,location_s *second_loc)
{/*{{{*/
  mpz_t *first_ptr = (mpz_t *)first_loc->v_data_ptr;
  mpz_t *second_ptr = (mpz_t *)second_loc->v_data_ptr;

  return mpz_cmp(*first_ptr,*second_ptr);
}/*}}}*/

bool bic_gmp_integer_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack)
{/*{{{*/
  mpz_t *mpz_ptr = (mpz_t *)location_ptr->v_data_ptr;

  size_t count;
  stream.reserve((mpz_sizeinbase(*mpz_ptr,2) + 7)/8);
  mpz_export(stream.data + stream.used,&count,1,1,1,0,*mpz_ptr);
  stream.used += count;

  // - store number sign -
  if (count > 0)
  {
    stream.push(mpz_sgn(*mpz_ptr));
  }

  stream.append(sizeof(size_t),(const char *)&count);

  return true;
}/*}}}*/

bool bic_gmp_integer_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos)
{/*{{{*/
  mpz_t *mpz_ptr = (mpz_t *)cmalloc(sizeof(mpz_t));
  mpz_init(*mpz_ptr);
  location_ptr->v_data_ptr = mpz_ptr;

  if (stream.used < sizeof(size_t))
  {
    return false;
  }

  size_t count;
  stream.from_end(sizeof(size_t),(char *)&count,order_bytes);

  if (count > 0)
  {
    if (stream.used < sizeof(char) + count)
    {
      return false;
    }

    char sign = stream.pop();

    mpz_import(*mpz_ptr,count,1,1,1,0,stream.data + (stream.used - count));
    stream.used -= count;

    // - apply negative sign -
    if (sign < 0)
    {
      mpz_neg(*mpz_ptr,*mpz_ptr);
    }
  }

  return true;
}/*}}}*/

bool bic_gmp_integer_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_gmp_integer_operator_binary_plus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GMP_INTEGER_BINARY_ADD_SUB_EQUAL(mpz_add,"operator_binary_plus_equal#1");

  return true;
}/*}}}*/

bool bic_gmp_integer_operator_binary_minus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GMP_INTEGER_BINARY_ADD_SUB_EQUAL(mpz_sub,"operator_binary_minus_equal#1");

  return true;
}/*}}}*/

bool bic_gmp_integer_operator_binary_asterisk_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  mpz_t *res_ptr = (mpz_t *)cmalloc(sizeof(mpz_t));
  mpz_init(*res_ptr);

  mpz_t *mpz_ptr = (mpz_t *)((location_s *)dst_location)->v_data_ptr;

  switch (src_0_location->v_type) {
  case c_bi_class_char:
    mpz_mul_si(*res_ptr,*mpz_ptr,(char)src_0_location->v_data_ptr);
    break;
  case c_bi_class_integer:
    gmp_c::mpz_mul_lli(*res_ptr,*mpz_ptr,(long long int)src_0_location->v_data_ptr);
    break;
  case c_bi_class_float:
    {
      mpfr_t tmp_mpfr;
      mpfr_init_set_d(tmp_mpfr,(double)src_0_location->v_data_ptr,MPFR_RNDD);
      mpfr_mul_z(tmp_mpfr,tmp_mpfr,*mpz_ptr,MPFR_RNDD);
      mpfr_get_z(*res_ptr,tmp_mpfr,MPFR_RNDD);
      mpfr_clear(tmp_mpfr);
    }
    break;
  default:
    if (src_0_location->v_type == c_bi_class_gmp_integer)
    {
      mpz_mul(*res_ptr,*mpz_ptr,*((mpz_t *)src_0_location->v_data_ptr));
    }
    else if (src_0_location->v_type == c_bi_class_gmp_rational)
    {
      mpq_t tmp_mpq;
      mpq_init(tmp_mpq);
      gmp_c::mpq_mul_z(tmp_mpq,*((mpq_t *)src_0_location->v_data_ptr),*mpz_ptr);
      mpz_set_q(*res_ptr,tmp_mpq);
      mpq_clear(tmp_mpq);
    }
    else if (src_0_location->v_type == c_bi_class_mpfr_fixed)
    {
      mpfr_t tmp_mpfr;
      mpfr_init(tmp_mpfr);
      mpfr_mul_z(tmp_mpfr,*((mpfr_t *)src_0_location->v_data_ptr),*mpz_ptr,MPFR_RNDD);
      mpfr_get_z(*res_ptr,tmp_mpfr,MPFR_RNDD);
      mpfr_clear(tmp_mpfr);
    }
    else
    {
      mpz_clear(*res_ptr);
      cfree(res_ptr);

      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
      BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_asterisk_equal#1");
      new_exception->params.push(1);
      new_exception->params.push(src_0_location->v_type);

      return false;
    }
  }

  BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_gmp_integer,res_ptr,2);

  BIC_SET_DESTINATION(new_location);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_gmp_integer_operator_binary_slash_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  mpz_t *res_ptr = (mpz_t *)cmalloc(sizeof(mpz_t));
  mpz_init(*res_ptr);

  mpz_t *mpz_ptr = (mpz_t *)((location_s *)dst_location)->v_data_ptr;

  switch (src_0_location->v_type) {
  case c_bi_class_char:
  {
    char divider = (char)src_0_location->v_data_ptr;

    // - ERROR -
    if (divider == 0)
    {
      mpz_clear(*res_ptr);
      cfree(res_ptr);

      exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    gmp_c::mpz_div_lli(*res_ptr,*mpz_ptr,divider);
  }
  break;
  case c_bi_class_integer:
  {
    long long int divider = (long long int)src_0_location->v_data_ptr;

    // - ERROR -
    if (divider == 0)
    {
      mpz_clear(*res_ptr);
      cfree(res_ptr);

      exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    gmp_c::mpz_div_lli(*res_ptr,*mpz_ptr,divider);
  }
  break;
  case c_bi_class_float:
  {
    double divider = (double)src_0_location->v_data_ptr;

    // - ERROR -
    if (divider == 0.0)
    {
      mpz_clear(*res_ptr);
      cfree(res_ptr);

      exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    mpfr_t tmp_mpfr;
    mpfr_init_set_z(tmp_mpfr,*mpz_ptr,MPFR_RNDD);
    mpfr_div_d(tmp_mpfr,tmp_mpfr,divider,MPFR_RNDD);
    mpfr_get_z(*res_ptr,tmp_mpfr,MPFR_RNDD);
    mpfr_clear(tmp_mpfr);
  }
  break;
  default:
    if (src_0_location->v_type == c_bi_class_gmp_integer)
    {
      mpz_t *divider = (mpz_t *)src_0_location->v_data_ptr;

      // - ERROR -
      if (mpz_sgn(*divider) == 0)
      {
        mpz_clear(*res_ptr);
        cfree(res_ptr);

        exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      mpz_div(*res_ptr,*mpz_ptr,*divider);
    }
    else if (src_0_location->v_type == c_bi_class_gmp_rational)
    {
      mpq_t *divider = (mpq_t *)src_0_location->v_data_ptr;

      // - ERROR -
      if (mpq_sgn(*divider) == 0)
      {
        mpz_clear(*res_ptr);
        cfree(res_ptr);

        exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      mpq_t tmp_mpq;
      mpq_init(tmp_mpq);
      mpq_set_z(tmp_mpq,*mpz_ptr);
      mpq_div(tmp_mpq,tmp_mpq,*divider);
      mpz_set_q(*res_ptr,tmp_mpq);
      mpq_clear(tmp_mpq);
    }
    else if (src_0_location->v_type == c_bi_class_mpfr_fixed)
    {
      mpfr_t *divider = (mpfr_t *)src_0_location->v_data_ptr;

      // - ERROR -
      if (mpfr_sgn(*divider) == 0)
      {
        mpz_clear(*res_ptr);
        cfree(res_ptr);

        exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      mpfr_t tmp_mpfr;
      mpfr_init_set_z(tmp_mpfr,*mpz_ptr,MPFR_RNDD);
      mpfr_div(tmp_mpfr,tmp_mpfr,*divider,MPFR_RNDD);
      mpfr_get_z(*res_ptr,tmp_mpfr,MPFR_RNDD);
      mpfr_clear(tmp_mpfr);
    }
    else
    {
      mpz_clear(*res_ptr);
      cfree(res_ptr);

      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
      BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_slash_equal#1");
      new_exception->params.push(1);
      new_exception->params.push(src_0_location->v_type);

      return false;
    }
  }

  BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_gmp_integer,res_ptr,2);

  BIC_SET_DESTINATION(new_location);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_gmp_integer_operator_binary_percent_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  mpz_t *res_ptr = (mpz_t *)cmalloc(sizeof(mpz_t));
  mpz_init(*res_ptr);

  mpz_t *mpz_ptr = (mpz_t *)((location_s *)dst_location)->v_data_ptr;

  switch (src_0_location->v_type) {
  case c_bi_class_char:
    gmp_c::mpz_mod_lli(*res_ptr,*mpz_ptr,(char)src_0_location->v_data_ptr);
    break;
  case c_bi_class_integer:
    gmp_c::mpz_mod_lli(*res_ptr,*mpz_ptr,(long long int)src_0_location->v_data_ptr);
    break;
  default:
    if (src_0_location->v_type == c_bi_class_gmp_integer)
    {
      mpz_mod(*res_ptr,*mpz_ptr,*((mpz_t *)src_0_location->v_data_ptr));
    }
    else
    {
      mpz_clear(*res_ptr);
      cfree(res_ptr);

      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
      BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_percent_equal#1");
      new_exception->params.push(1);
      new_exception->params.push(src_0_location->v_type);

      return false;
    }
  }

  BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_gmp_integer,res_ptr,2);

  BIC_SET_DESTINATION(new_location);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_gmp_integer_operator_binary_double_ls_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GMP_INTEGER_BINARY_SHIFT(mul_2exp,"operator_binary_double_ls_br_equal#1");

  BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_gmp_integer,res_ptr,2);

  BIC_SET_DESTINATION(new_location);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_gmp_integer_operator_binary_double_rs_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GMP_INTEGER_BINARY_SHIFT(div_2exp,"operator_binary_double_rs_br_equal#1");

  BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_gmp_integer,res_ptr,2);

  BIC_SET_DESTINATION(new_location);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_gmp_integer_operator_binary_ampersand_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GMP_INTEGER_BINARY_BIT_LOGIC(mpz_and,"operator_binary_ampersand_equal#1");

  BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_gmp_integer,res_ptr,2);

  BIC_SET_DESTINATION(new_location);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_gmp_integer_operator_binary_pipe_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GMP_INTEGER_BINARY_BIT_LOGIC(mpz_ior,"operator_binary_pipe_equal#1");

  BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_gmp_integer,res_ptr,2);

  BIC_SET_DESTINATION(new_location);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_gmp_integer_operator_binary_circumflex_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GMP_INTEGER_BINARY_BIT_LOGIC(mpz_xor,"operator_binary_circumflex_equal#1");

  BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_gmp_integer,res_ptr,2);

  BIC_SET_DESTINATION(new_location);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_gmp_integer_operator_binary_double_ampersand(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GMP_INTEGER_BINARY_LOGIC(&&,"operator_binary_double_ampersand#1");

  return true;
}/*}}}*/

bool bic_gmp_integer_operator_binary_double_pipe(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GMP_INTEGER_BINARY_LOGIC(||,"operator_binary_double_pipe#1");

  return true;
}/*}}}*/

bool bic_gmp_integer_operator_binary_ampersand(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GMP_INTEGER_BINARY_BIT_LOGIC(mpz_and,"operator_binary_ampersand#1");

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gmp_integer,res_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_gmp_integer_operator_binary_pipe(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GMP_INTEGER_BINARY_BIT_LOGIC(mpz_ior,"operator_binary_pipe#1");

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gmp_integer,res_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_gmp_integer_operator_binary_circumflex(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GMP_INTEGER_BINARY_BIT_LOGIC(mpz_xor,"operator_binary_circumflex#1");

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gmp_integer,res_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_gmp_integer_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_GMP_INTEGER_COMPARE_WITH_TYPE_BOOL();

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_gmp_integer_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_GMP_INTEGER_COMPARE_WITH_TYPE_BOOL();
  result = !result;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_gmp_integer_operator_binary_rs_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_GMP_INTEGER_COMPARE_WITH_TYPE_INT("operator_binary_rs_br#1");

  result = result > 0;
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_gmp_integer_operator_binary_ls_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_GMP_INTEGER_COMPARE_WITH_TYPE_INT("operator_binary_ls_br#1");

  result = result < 0;
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_gmp_integer_operator_binary_rs_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_GMP_INTEGER_COMPARE_WITH_TYPE_INT("operator_binary_rs_br_equal#1");

  result = result >= 0;
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_gmp_integer_operator_binary_ls_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_GMP_INTEGER_COMPARE_WITH_TYPE_INT("operator_binary_ls_br_equal#1");

  result = result <= 0;
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_gmp_integer_operator_binary_double_rs_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GMP_INTEGER_BINARY_SHIFT(div_2exp,"operator_binary_double_rs_br#1");

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gmp_integer,res_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_gmp_integer_operator_binary_double_ls_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GMP_INTEGER_BINARY_SHIFT(mul_2exp,"operator_binary_double_ls_br#1");

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gmp_integer,res_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_gmp_integer_operator_binary_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GMP_INTEGER_BINARY_ADD_SUB_MUL(add,"operator_binary_plus#1");

  return true;
}/*}}}*/

bool bic_gmp_integer_operator_binary_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GMP_INTEGER_BINARY_ADD_SUB_MUL(sub,"operator_binary_minus#1");

  return true;
}/*}}}*/

bool bic_gmp_integer_operator_binary_asterisk(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GMP_INTEGER_BINARY_ADD_SUB_MUL(mul,"operator_binary_asterisk#1");

  return true;
}/*}}}*/

bool bic_gmp_integer_operator_binary_slash(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  mpz_t *mpz_ptr = (mpz_t *)((location_s *)dst_location)->v_data_ptr;

  switch (src_0_location->v_type) {
  case c_bi_class_char:
  {
    char divider = (char)src_0_location->v_data_ptr;

    // - ERROR -
    if (divider == 0)
    {
      exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    mpz_t *res_ptr = (mpz_t *)cmalloc(sizeof(mpz_t));
    mpz_init(*res_ptr);
    gmp_c::mpz_div_lli(*res_ptr,*mpz_ptr,divider);

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gmp_integer,res_ptr);
    BIC_SET_RESULT(new_location);
  }
  break;
  case c_bi_class_integer:
  {
    long long int divider = (long long int)src_0_location->v_data_ptr;

    // - ERROR -
    if (divider == 0)
    {
      exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    mpz_t *res_ptr = (mpz_t *)cmalloc(sizeof(mpz_t));
    mpz_init(*res_ptr);
    gmp_c::mpz_div_lli(*res_ptr,*mpz_ptr,divider);

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gmp_integer,res_ptr);
    BIC_SET_RESULT(new_location);
  }
  break;
  case c_bi_class_float:
  {
    double divider = (double)src_0_location->v_data_ptr;

    // - ERROR -
    if (divider == 0.0)
    {
      exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    mpfr_t *res_ptr = (mpfr_t *)cmalloc(sizeof(mpfr_t));
    mpfr_init_set_z(*res_ptr,*mpz_ptr,MPFR_RNDD);
    mpfr_div_d(*res_ptr,*res_ptr,divider,MPFR_RNDD);

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mpfr_fixed,res_ptr);
    BIC_SET_RESULT(new_location);
  }
  break;
  default:
    if (src_0_location->v_type == c_bi_class_gmp_integer)
    {
      mpz_t *divider = (mpz_t *)src_0_location->v_data_ptr;

      // - ERROR -
      if (mpz_sgn(*divider) == 0)
      {
        exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      mpz_t *res_ptr = (mpz_t *)cmalloc(sizeof(mpz_t));
      mpz_init(*res_ptr);
      mpz_div(*res_ptr,*mpz_ptr,*divider);

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gmp_integer,res_ptr);
      BIC_SET_RESULT(new_location);
    }
    else if (src_0_location->v_type == c_bi_class_gmp_rational)
    {
      mpq_t *divider = (mpq_t *)src_0_location->v_data_ptr;

      // - ERROR -
      if (mpq_sgn(*divider) == 0)
      {
        exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      mpq_t *res_ptr = (mpq_t *)cmalloc(sizeof(mpq_t));
      mpq_init(*res_ptr);
      mpq_set_z(*res_ptr,*mpz_ptr);
      mpq_div(*res_ptr,*res_ptr,*divider);

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gmp_rational,res_ptr);
      BIC_SET_RESULT(new_location);
    }
    else if (src_0_location->v_type == c_bi_class_mpfr_fixed)
    {
      mpfr_t *divider = (mpfr_t *)src_0_location->v_data_ptr;

      // - ERROR -
      if (mpfr_sgn(*divider) == 0)
      {
        exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      mpfr_t *res_ptr = (mpfr_t *)cmalloc(sizeof(mpfr_t));
      mpfr_init_set_z(*res_ptr,*mpz_ptr,MPFR_RNDD);
      mpfr_div(*res_ptr,*res_ptr,*divider,MPFR_RNDD);

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mpfr_fixed,res_ptr);
      BIC_SET_RESULT(new_location);
    }
    else
    {
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
      BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_slash#1");
      new_exception->params.push(1);
      new_exception->params.push(src_0_location->v_type);

      return false;
    }
  }

  return true;
}/*}}}*/

bool bic_gmp_integer_operator_binary_percent(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  mpz_t *res_ptr = (mpz_t *)cmalloc(sizeof(mpz_t));
  mpz_init(*res_ptr);

  mpz_t *mpz_ptr = (mpz_t *)dst_location->v_data_ptr;

  switch (src_0_location->v_type) {
  case c_bi_class_char:
    gmp_c::mpz_mod_lli(*res_ptr,*mpz_ptr,(char)src_0_location->v_data_ptr);
    break;
  case c_bi_class_integer:
    gmp_c::mpz_mod_lli(*res_ptr,*mpz_ptr,(long long int)src_0_location->v_data_ptr);
    break;
  default:
    if (src_0_location->v_type == c_bi_class_gmp_integer)
    {
      mpz_mod(*res_ptr,*mpz_ptr,*((mpz_t *)src_0_location->v_data_ptr));
    }
    else
    {
      mpz_clear(*res_ptr);
      cfree(res_ptr);

      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
      BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_percent#1");
      new_exception->params.push(1);
      new_exception->params.push(src_0_location->v_type);

      return false;
    }
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gmp_integer,res_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_gmp_integer_operator_unary_post_double_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GMP_INTEGER_POST_UNARY_INC_DEC(add);

  return true;
}/*}}}*/

bool bic_gmp_integer_operator_unary_post_double_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GMP_INTEGER_POST_UNARY_INC_DEC(sub);

  return true;
}/*}}}*/

bool bic_gmp_integer_operator_unary_pre_double_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GMP_INTEGER_PRE_UNARY_INC_DEC(add);

  return true;
}/*}}}*/

bool bic_gmp_integer_operator_unary_pre_double_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GMP_INTEGER_PRE_UNARY_INC_DEC(sub);

  return true;
}/*}}}*/

bool bic_gmp_integer_operator_unary_pre_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  dst_location->v_reference_cnt.atomic_inc();

  BIC_SET_RESULT(dst_location);

  return true;
}/*}}}*/

bool bic_gmp_integer_operator_unary_pre_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GMP_INTEGER_PRE_UNARY_TMP_RESULT(neg);

  return true;
}/*}}}*/

bool bic_gmp_integer_operator_unary_pre_exclamation(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = mpz_sgn(*((mpz_t *)dst_location->v_data_ptr)) == 0;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_gmp_integer_operator_unary_pre_tilde(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GMP_INTEGER_PRE_UNARY_TMP_RESULT(com);

  return true;
}/*}}}*/

bool bic_gmp_integer_method_GmpInteger_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  return true;
}/*}}}*/

bool bic_gmp_integer_method_GmpInteger_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  mpz_t *mpz_ptr = (mpz_t *)dst_location->v_data_ptr;

  switch (src_0_location->v_type)
  {
  case c_bi_class_char:
    mpz_set_si(*mpz_ptr,(char)src_0_location->v_data_ptr);
    break;
  case c_bi_class_integer:
    gmp_c::mpz_set_lli(*mpz_ptr,(long long int)src_0_location->v_data_ptr);
    break;
  case c_bi_class_float:
    mpz_set_d(*mpz_ptr,(double)src_0_location->v_data_ptr);
    break;
  case c_bi_class_string:

    // - ERROR -
    if (mpz_set_str(*mpz_ptr,((string_s *)src_0_location->v_data_ptr)->data,0))
    {
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GMP_NUMBER_CONVERT_INVALID_STRING,operands[c_source_pos_idx],src_0_location);
      new_exception->params.push(c_bi_class_gmp_integer);
      new_exception->params.push(0);

      return false;
    }
    break;
  default:
    if (src_0_location->v_type == c_bi_class_gmp_integer)
    {
      mpz_set(*mpz_ptr,*((mpz_t *)src_0_location->v_data_ptr));
    }
    else if (src_0_location->v_type == c_bi_class_gmp_rational)
    {
      mpz_set_q(*mpz_ptr,*((mpq_t *)src_0_location->v_data_ptr));
    }
    else if (src_0_location->v_type == c_bi_class_mpfr_fixed)
    {
      mpfr_get_z(*mpz_ptr,*((mpfr_t *)src_0_location->v_data_ptr),MPFR_RNDD);
    }
    else
    {
      // - ERROR -
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
      BIC_EXCEPTION_PUSH_METHOD_RI("GmpInteger#1");
      new_exception->params.push(1);
      new_exception->params.push(src_0_location->v_type);

      return false;
    }
  }

  return true;
}/*}}}*/

bool bic_gmp_integer_method_GmpInteger_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  switch (src_0_location->v_type)
  {
  case c_bi_class_string:
  {
    if (src_1_location->v_type != c_bi_class_integer)
    {
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
      BIC_EXCEPTION_PUSH_METHOD_RI("GmpInteger#2");
      new_exception->params.push(2);
      new_exception->params.push(src_0_location->v_type);
      new_exception->params.push(src_1_location->v_type);

      return false;
    }

    string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;
    long long int base = (long long int)src_1_location->v_data_ptr;

    if (base < 2 || base > 62)
    {
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GMP_NUMBER_BASE_OUT_OF_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(c_bi_class_gmp_integer);
      new_exception->params.push(base);

      return false;
    }

    // - ERROR -
    if (mpz_set_str(*((mpz_t *)dst_location->v_data_ptr),string_ptr->data,base))
    {
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GMP_NUMBER_CONVERT_INVALID_STRING,operands[c_source_pos_idx],src_0_location);
      new_exception->params.push(c_bi_class_gmp_integer);
      new_exception->params.push(base);

      return false;
    }
  }
  break;

  // - ERROR -
  default:
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("GmpInteger#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  return true;
}/*}}}*/

bool bic_gmp_integer_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  if (src_0_location->v_type == c_bi_class_gmp_integer)
  {
    mpz_t *first_ptr = (mpz_t *)dst_location->v_data_ptr;
    mpz_t *second_ptr = (mpz_t *)src_0_location->v_data_ptr;

    result = mpz_cmp(*first_ptr,*second_ptr);
  }
  else
  {
    result = c_bi_class_gmp_integer < src_0_location->v_type ? -1 : 1;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_gmp_integer_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING(
    gmp_c::setf(*string_ptr,"%Zd",*((mpz_t *)dst_location->v_data_ptr))
  );

  return true;
}/*}}}*/

bool bic_gmp_integer_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - print value to standard output -
  mpfr_printf("%Zd",*((mpz_t *)dst_location->v_data_ptr));

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

// - class GMP_RATIONAL -
built_in_class_s gmp_rational_class =
{/*{{{*/
  "GmpRational",
  c_modifier_public | c_modifier_final,
  34, gmp_rational_methods,
  0, gmp_rational_variables,
  bic_gmp_rational_consts,
  bic_gmp_rational_init,
  bic_gmp_rational_clear,
  bic_gmp_rational_compare,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  bic_gmp_rational_pack,
  bic_gmp_rational_unpack,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s gmp_rational_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_rational_operator_binary_equal
  },
  {
    "operator_binary_plus_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_rational_operator_binary_plus_equal
  },
  {
    "operator_binary_minus_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_rational_operator_binary_minus_equal
  },
  {
    "operator_binary_asterisk_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_rational_operator_binary_asterisk_equal
  },
  {
    "operator_binary_slash_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_rational_operator_binary_slash_equal
  },
  {
    "operator_binary_double_ls_br_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_rational_operator_binary_double_ls_br_equal
  },
  {
    "operator_binary_double_rs_br_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_rational_operator_binary_double_rs_br_equal
  },
  {
    "operator_binary_double_ampersand#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_rational_operator_binary_double_ampersand
  },
  {
    "operator_binary_double_pipe#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_rational_operator_binary_double_pipe
  },
  {
    "operator_binary_double_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_rational_operator_binary_double_equal
  },
  {
    "operator_binary_exclamation_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_rational_operator_binary_exclamation_equal
  },
  {
    "operator_binary_rs_br#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_rational_operator_binary_rs_br
  },
  {
    "operator_binary_ls_br#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_rational_operator_binary_ls_br
  },
  {
    "operator_binary_rs_br_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_rational_operator_binary_rs_br_equal
  },
  {
    "operator_binary_ls_br_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_rational_operator_binary_ls_br_equal
  },
  {
    "operator_binary_double_rs_br#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_rational_operator_binary_double_rs_br
  },
  {
    "operator_binary_double_ls_br#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_rational_operator_binary_double_ls_br
  },
  {
    "operator_binary_plus#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_rational_operator_binary_plus
  },
  {
    "operator_binary_minus#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_rational_operator_binary_minus
  },
  {
    "operator_binary_asterisk#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_rational_operator_binary_asterisk
  },
  {
    "operator_binary_slash#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_rational_operator_binary_slash
  },
  {
    "operator_unary_post_double_plus#0",
    c_modifier_public | c_modifier_final,
    bic_gmp_rational_operator_unary_post_double_plus
  },
  {
    "operator_unary_post_double_minus#0",
    c_modifier_public | c_modifier_final,
    bic_gmp_rational_operator_unary_post_double_minus
  },
  {
    "operator_unary_pre_double_plus#0",
    c_modifier_public | c_modifier_final,
    bic_gmp_rational_operator_unary_pre_double_plus
  },
  {
    "operator_unary_pre_double_minus#0",
    c_modifier_public | c_modifier_final,
    bic_gmp_rational_operator_unary_pre_double_minus
  },
  {
    "operator_unary_pre_plus#0",
    c_modifier_public | c_modifier_final,
    bic_gmp_rational_operator_unary_pre_plus
  },
  {
    "operator_unary_pre_minus#0",
    c_modifier_public | c_modifier_final,
    bic_gmp_rational_operator_unary_pre_minus
  },
  {
    "operator_unary_pre_exclamation#0",
    c_modifier_public | c_modifier_final,
    bic_gmp_rational_operator_unary_pre_exclamation
  },
  {
    "GmpRational#0",
    c_modifier_public | c_modifier_final,
    bic_gmp_rational_method_GmpRational_0
  },
  {
    "GmpRational#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_rational_method_GmpRational_1
  },
  {
    "GmpRational#2",
    c_modifier_public | c_modifier_final,
    bic_gmp_rational_method_GmpRational_2
  },
  {
    "compare#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_rational_method_compare_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_gmp_rational_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_gmp_rational_method_print_0
  },
};/*}}}*/

built_in_variable_s gmp_rational_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_GMP_RATIONAL_BINARY_ADD_SUB_EQUAL(OPERATION,NAME) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
  \
  mpq_t *res_ptr = (mpq_t *)cmalloc(sizeof(mpq_t));\
  mpq_init(*res_ptr);\
  \
  mpq_t *mpq_ptr = (mpq_t *)((location_s *)dst_location)->v_data_ptr;\
  \
  switch (src_0_location->v_type) {\
  case c_bi_class_char:\
    gmp_c::mpq_ ## OPERATION ## _lli(*res_ptr,*mpq_ptr,(char)src_0_location->v_data_ptr);\
    break;\
  case c_bi_class_integer:\
    gmp_c::mpq_ ## OPERATION ## _lli(*res_ptr,*mpq_ptr,(long long int)src_0_location->v_data_ptr);\
    break;\
  case c_bi_class_float:\
    mpq_set_d(*res_ptr,(double)src_0_location->v_data_ptr);\
    mpq_ ## OPERATION(*res_ptr,*mpq_ptr,*res_ptr);\
    break;\
  default:\
    if (src_0_location->v_type == c_bi_class_gmp_integer)\
    {\
      mpq_set(*res_ptr,*mpq_ptr);\
      mpz_ ## OPERATION ## mul(mpq_numref(*res_ptr),mpq_denref(*res_ptr),*((mpz_t *)src_0_location->v_data_ptr));\
    }\
    else if (src_0_location->v_type == c_bi_class_gmp_rational)\
    {\
      mpq_ ## OPERATION(*res_ptr,*mpq_ptr,*((mpq_t *)src_0_location->v_data_ptr));\
    }\
    else if (src_0_location->v_type == c_bi_class_mpfr_fixed)\
    {\
      mpf_t tmp_mpf;\
      mpf_init(tmp_mpf);\
      mpfr_get_f(tmp_mpf,*((mpfr_t *)src_0_location->v_data_ptr),MPFR_RNDD);\
      mpq_set_f(*res_ptr,tmp_mpf);\
      mpf_clear(tmp_mpf);\
      mpq_ ## OPERATION(*res_ptr,*mpq_ptr,*res_ptr);\
    }\
    else\
    {\
      mpq_clear(*res_ptr);\
      cfree(res_ptr);\
      \
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
      \
      return false;\
    }\
  }\
  \
  BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_gmp_rational,res_ptr,2);\
  \
  BIC_SET_DESTINATION(new_location);\
  BIC_SET_RESULT(new_location);\
}/*}}}*/

#define BIC_GMP_RATIONAL_BINARY_SHIFT(OPERATION,NAME) \
/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
  \
  mpq_t *res_ptr = (mpq_t *)cmalloc(sizeof(mpq_t));\
  mpq_init(*res_ptr);\
  \
  mpq_t *mpq_ptr = (mpq_t *)((location_s *)dst_location)->v_data_ptr;\
  \
  switch (src_0_location->v_type) {\
  case c_bi_class_char:\
  {\
    char shift_count = (char)src_0_location->v_data_ptr;\
    if (shift_count < 0)\
    {\
      mpq_clear(*res_ptr);\
      cfree(res_ptr);\
      \
      exception_s *new_exception = exception_s::throw_exception(it,c_error_NEGATIVE_SHIFT_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      new_exception->params.push((long long int)shift_count);\
      \
      return false;\
    }\
    \
    mpq_ ## OPERATION(*res_ptr,*mpq_ptr,shift_count);\
  }\
  break;\
  case c_bi_class_integer:\
  {\
    long long int shift_count = (long long int)src_0_location->v_data_ptr;\
    if (shift_count < 0)\
    {\
      mpq_clear(*res_ptr);\
      cfree(res_ptr);\
      \
      exception_s *new_exception = exception_s::throw_exception(it,c_error_NEGATIVE_SHIFT_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      new_exception->params.push(shift_count);\
      \
      return false;\
    }\
    \
    mpq_ ## OPERATION(*res_ptr,*mpq_ptr,shift_count);\
  }\
  break;\
  default:\
    mpq_clear(*res_ptr);\
    cfree(res_ptr);\
    \
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
    new_exception->params.push(1);\
    new_exception->params.push(src_0_location->v_type);\
    \
    return false;\
  }\
/*}}}*/

#define BIC_GMP_RATIONAL_BINARY_LOGIC(OPERATOR,NAME) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
  \
  long long int result;\
  \
  mpq_t *mpq_ptr = (mpq_t *)dst_location->v_data_ptr;\
  \
  switch (src_0_location->v_type) {\
  case c_bi_class_char:\
    result = mpq_sgn(*mpq_ptr) OPERATOR (char)src_0_location->v_data_ptr;\
    break;\
  case c_bi_class_integer:\
    result = mpq_sgn(*mpq_ptr) OPERATOR (long long int)src_0_location->v_data_ptr;\
    break;\
  case c_bi_class_float:\
    result = mpq_sgn(*mpq_ptr) OPERATOR (double)src_0_location->v_data_ptr;\
    break;\
  default:\
    if (src_0_location->v_type == c_bi_class_gmp_integer)\
    {\
      result = mpq_sgn(*mpq_ptr) OPERATOR mpz_sgn(*((mpz_t *)src_0_location->v_data_ptr));\
    }\
    else if (src_0_location->v_type == c_bi_class_gmp_rational)\
    {\
      result = mpq_sgn(*mpq_ptr) OPERATOR mpq_sgn(*((mpq_t *)src_0_location->v_data_ptr));\
    }\
    else if (src_0_location->v_type == c_bi_class_mpfr_fixed)\
    {\
      result = mpq_sgn(*mpq_ptr) OPERATOR mpfr_sgn(*((mpfr_t *)src_0_location->v_data_ptr));\
    }\
    else\
    {\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
      \
      return false;\
    }\
  }\
  \
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
}/*}}}*/

#define BIC_GMP_RATIONAL_COMPARE_WITH_TYPE_BOOL() \
{/*{{{*/\
  mpq_t *mpq_ptr = (mpq_t *)dst_location->v_data_ptr;\
  \
  switch (src_0_location->v_type) {\
  case c_bi_class_char:\
    result = mpq_cmp_si(*mpq_ptr,(char)src_0_location->v_data_ptr,1) == 0;\
    break;\
  case c_bi_class_integer:\
    result = gmp_c::mpq_cmp_lli(*mpq_ptr,(long long int)src_0_location->v_data_ptr) == 0;\
    break;\
  case c_bi_class_float:\
  {\
    mpq_t tmp_mpq;\
    mpq_init(tmp_mpq);\
    mpq_set_d(tmp_mpq,(double)src_0_location->v_data_ptr);\
    result = mpq_cmp(*mpq_ptr,tmp_mpq) == 0;\
    mpq_clear(tmp_mpq);\
  }\
  break;\
  default:\
    if (src_0_location->v_type == c_bi_class_gmp_integer)\
    {\
      result = mpq_cmp_z(*mpq_ptr,*((mpz_t *)src_0_location->v_data_ptr)) == 0;\
    }\
    else if (src_0_location->v_type == c_bi_class_gmp_rational)\
    {\
      result = mpq_cmp(*mpq_ptr,*((mpq_t *)src_0_location->v_data_ptr)) == 0;\
    }\
    else if (src_0_location->v_type == c_bi_class_mpfr_fixed)\
    {\
      result = mpfr_cmp_q(*((mpfr_t *)src_0_location->v_data_ptr),*mpq_ptr) == 0;\
    }\
    else\
    {\
      result = 0;\
    }\
  }\
}/*}}}*/

#define BIC_GMP_RATIONAL_COMPARE_WITH_TYPE_INT(NAME) \
{/*{{{*/\
  mpq_t *mpq_ptr = (mpq_t *)dst_location->v_data_ptr;\
  \
  switch (src_0_location->v_type) {\
  case c_bi_class_char:\
    result = mpq_cmp_si(*mpq_ptr,(char)src_0_location->v_data_ptr,1);\
    break;\
  case c_bi_class_integer:\
    result = gmp_c::mpq_cmp_lli(*mpq_ptr,(long long int)src_0_location->v_data_ptr);\
    break;\
  case c_bi_class_float:\
  {\
    mpq_t tmp_mpq;\
    mpq_init(tmp_mpq);\
    mpq_set_d(tmp_mpq,(double)src_0_location->v_data_ptr);\
    result = mpq_cmp(*mpq_ptr,tmp_mpq);\
    mpq_clear(tmp_mpq);\
  }\
  break;\
  default:\
    if (src_0_location->v_type == c_bi_class_gmp_integer)\
    {\
      result = mpq_cmp_z(*mpq_ptr,*((mpz_t *)src_0_location->v_data_ptr));\
    }\
    else if (src_0_location->v_type == c_bi_class_gmp_rational)\
    {\
      result = mpq_cmp(*mpq_ptr,*((mpq_t *)src_0_location->v_data_ptr));\
    }\
    else if (src_0_location->v_type == c_bi_class_mpfr_fixed)\
    {\
      result = -mpfr_cmp_q(*((mpfr_t *)src_0_location->v_data_ptr),*mpq_ptr);\
    }\
    else\
    {\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
      \
      return false;\
    }\
  }\
}/*}}}*/

#define BIC_GMP_RATIONAL_BINARY_ADD_SUB(OPERATION,NAME) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
  \
  mpq_t *mpq_ptr = (mpq_t *)dst_location->v_data_ptr;\
  \
  switch (src_0_location->v_type) {\
  case c_bi_class_char:\
  {\
    mpq_t *res_ptr = (mpq_t *)cmalloc(sizeof(mpq_t));\
    mpq_init(*res_ptr);\
    gmp_c::mpq_ ## OPERATION ## _lli(*res_ptr,*mpq_ptr,(char)src_0_location->v_data_ptr);\
    \
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gmp_rational,res_ptr);\
    BIC_SET_RESULT(new_location);\
  }\
  break;\
  case c_bi_class_integer:\
  {\
    mpq_t *res_ptr = (mpq_t *)cmalloc(sizeof(mpq_t));\
    mpq_init(*res_ptr);\
    gmp_c::mpq_ ## OPERATION ## _lli(*res_ptr,*mpq_ptr,(long long int)src_0_location->v_data_ptr);\
    \
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gmp_rational,res_ptr);\
    BIC_SET_RESULT(new_location);\
  }\
  break;\
  case c_bi_class_float:\
  {\
    mpfr_t *res_ptr = (mpfr_t *)cmalloc(sizeof(mpfr_t));\
    mpfr_init_set_q(*res_ptr,*mpq_ptr,MPFR_RNDD);\
    mpfr_ ## OPERATION ## _d(*res_ptr,*res_ptr,(double)src_0_location->v_data_ptr,MPFR_RNDD);\
    \
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mpfr_fixed,res_ptr);\
    BIC_SET_RESULT(new_location);\
  }\
  break;\
  default:\
    if (src_0_location->v_type == c_bi_class_gmp_integer)\
    {\
      mpq_t *res_ptr = (mpq_t *)cmalloc(sizeof(mpq_t));\
      mpq_init(*res_ptr);\
      mpq_set(*res_ptr,*mpq_ptr);\
      mpz_ ## OPERATION ## mul(mpq_numref(*res_ptr),mpq_denref(*res_ptr),*((mpz_t *)src_0_location->v_data_ptr));\
      \
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gmp_rational,res_ptr);\
      BIC_SET_RESULT(new_location);\
    }\
    else if (src_0_location->v_type == c_bi_class_gmp_rational)\
    {\
      mpq_t *res_ptr = (mpq_t *)cmalloc(sizeof(mpq_t));\
      mpq_init(*res_ptr);\
      mpq_ ## OPERATION(*res_ptr,*mpq_ptr,*((mpq_t *)src_0_location->v_data_ptr));\
      \
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gmp_rational,res_ptr);\
      BIC_SET_RESULT(new_location);\
    }\
    else if (src_0_location->v_type == c_bi_class_mpfr_fixed)\
    {\
      mpfr_t *res_ptr = (mpfr_t *)cmalloc(sizeof(mpfr_t));\
      mpfr_init_set_q(*res_ptr,*mpq_ptr,MPFR_RNDD);\
      mpfr_ ## OPERATION(*res_ptr,*res_ptr,*((mpfr_t *)src_0_location->v_data_ptr),MPFR_RNDD);\
      \
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mpfr_fixed,res_ptr);\
      BIC_SET_RESULT(new_location);\
    }\
    else\
    {\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
      \
      return false;\
    }\
  }\
}/*}}}*/

#define BIC_GMP_RATIONAL_POST_UNARY_INC_DEC(OPERATION) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  \
  mpq_t *res_ptr = (mpq_t *)cmalloc(sizeof(mpq_t));\
  mpq_init(*res_ptr);\
  \
  mpq_t *mpq_ptr = (mpq_t *)((location_s *)dst_location)->v_data_ptr;\
  mpz_ ## OPERATION(mpq_numref(*res_ptr),mpq_numref(*mpq_ptr),mpq_denref(*mpq_ptr));\
  mpz_set(mpq_denref(*res_ptr),mpq_denref(*mpq_ptr));\
  \
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gmp_rational,res_ptr);\
  BIC_SET_RESULT(new_location);\
  \
  pointer tmp_location = res_location;\
  res_location = dst_location;\
  dst_location = tmp_location;\
}/*}}}*/

#define BIC_GMP_RATIONAL_PRE_UNARY_INC_DEC(OPERATION) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  \
  mpq_t *res_ptr = (mpq_t *)cmalloc(sizeof(mpq_t));\
  mpq_init(*res_ptr);\
  \
  mpq_t *mpq_ptr = (mpq_t *)((location_s *)dst_location)->v_data_ptr;\
  mpz_ ## OPERATION(mpq_numref(*res_ptr),mpq_numref(*mpq_ptr),mpq_denref(*mpq_ptr));\
  mpz_set(mpq_denref(*res_ptr),mpq_denref(*mpq_ptr));\
  \
  BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_gmp_rational,res_ptr,2);\
  \
  BIC_SET_DESTINATION(new_location);\
  BIC_SET_RESULT(new_location);\
}/*}}}*/

void bic_gmp_rational_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_gmp_rational_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  mpq_t *mpq_ptr = (mpq_t *)cmalloc(sizeof(mpq_t));
  mpq_init(*mpq_ptr);
  location_ptr->v_data_ptr = mpq_ptr;
}/*}}}*/

void bic_gmp_rational_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  mpq_t *mpq_ptr = (mpq_t *)location_ptr->v_data_ptr;
  mpq_clear(*mpq_ptr);
  cfree(mpq_ptr);
}/*}}}*/

int bic_gmp_rational_compare(location_s *first_loc,location_s *second_loc)
{/*{{{*/
  mpq_t *first_ptr = (mpq_t *)first_loc->v_data_ptr;
  mpq_t *second_ptr = (mpq_t *)second_loc->v_data_ptr;

  return mpq_cmp(*first_ptr,*second_ptr);
}/*}}}*/

bool bic_gmp_rational_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack)
{/*{{{*/
  mpq_t *mpq_ptr = (mpq_t *)location_ptr->v_data_ptr;

  // - store numerator -
  size_t num_count;
  stream.reserve((mpz_sizeinbase(mpq_numref(*mpq_ptr),2) + 7)/8);
  mpz_export(stream.data + stream.used,&num_count,1,1,1,0,mpq_numref(*mpq_ptr));
  stream.used += num_count;

  // - store number sign -
  if (num_count > 0)
  {
    stream.push(mpz_sgn(mpq_numref(*mpq_ptr)));

    // - store denominator -
    size_t den_count;
    stream.reserve((mpz_sizeinbase(mpq_denref(*mpq_ptr),2) + 7)/8);
    mpz_export(stream.data + stream.used,&den_count,1,1,1,0,mpq_denref(*mpq_ptr));
    stream.used += den_count;

    stream.append(sizeof(size_t),(const char *)&den_count);
  }

  stream.append(sizeof(size_t),(const char *)&num_count);

  return true;
}/*}}}*/

bool bic_gmp_rational_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos)
{/*{{{*/
  mpq_t *mpq_ptr = (mpq_t *)cmalloc(sizeof(mpq_t));
  mpq_init(*mpq_ptr);
  location_ptr->v_data_ptr = mpq_ptr;

  if (stream.used < sizeof(size_t))
  {
    return false;
  }

  size_t num_count;
  stream.from_end(sizeof(size_t),(char *)&num_count,order_bytes);

  if (num_count > 0)
  {
    if (stream.used < sizeof(size_t) + sizeof(char) + num_count)
    {
      return false;
    }

    size_t den_count;
    stream.from_end(sizeof(size_t),(char *)&den_count,order_bytes);

    if (stream.used < den_count + sizeof(char) + num_count)
    {
      return false;
    }

    mpz_import(mpq_denref(*mpq_ptr),den_count,1,1,1,0,stream.data + (stream.used - den_count));
    stream.used -= den_count;

    char sign = stream.pop();

    mpz_import(mpq_numref(*mpq_ptr),num_count,1,1,1,0,stream.data + (stream.used - num_count));
    stream.used -= num_count;

    // - apply negative sign -
    if (sign < 0)
    {
      mpz_neg(mpq_numref(*mpq_ptr),mpq_numref(*mpq_ptr));
    }
  }
  else
  {
    mpq_set_si(*mpq_ptr,0,1);
  }

  return true;
}/*}}}*/

bool bic_gmp_rational_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_gmp_rational_operator_binary_plus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GMP_RATIONAL_BINARY_ADD_SUB_EQUAL(add,"operator_binary_plus_equal#1");

  return true;
}/*}}}*/

bool bic_gmp_rational_operator_binary_minus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GMP_RATIONAL_BINARY_ADD_SUB_EQUAL(sub,"operator_binary_minus_equal#1");

  return true;
}/*}}}*/

bool bic_gmp_rational_operator_binary_asterisk_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  mpq_t *res_ptr = (mpq_t *)cmalloc(sizeof(mpq_t));
  mpq_init(*res_ptr);

  mpq_t *mpq_ptr = (mpq_t *)((location_s *)dst_location)->v_data_ptr;

  switch (src_0_location->v_type) {
  case c_bi_class_char:
    gmp_c::mpq_mul_lli(*res_ptr,*mpq_ptr,(char)src_0_location->v_data_ptr);
    break;
  case c_bi_class_integer:
    gmp_c::mpq_mul_lli(*res_ptr,*mpq_ptr,(long long int)src_0_location->v_data_ptr);
    break;
  case c_bi_class_float:
    mpq_set_d(*res_ptr,(double)src_0_location->v_data_ptr);
    mpq_mul(*res_ptr,*mpq_ptr,*res_ptr);
    break;
  default:
    if (src_0_location->v_type == c_bi_class_gmp_integer)
    {
      gmp_c::mpq_mul_z(*res_ptr,*mpq_ptr,*((mpz_t *)src_0_location->v_data_ptr));
    }
    else if (src_0_location->v_type == c_bi_class_gmp_rational)
    {
      mpq_mul(*res_ptr,*mpq_ptr,*((mpq_t *)src_0_location->v_data_ptr));
    }
    else if (src_0_location->v_type == c_bi_class_mpfr_fixed)
    {
      mpf_t tmp_mpf;
      mpf_init(tmp_mpf);
      mpfr_get_f(tmp_mpf,*((mpfr_t *)src_0_location->v_data_ptr),MPFR_RNDD);
      mpq_set_f(*res_ptr,tmp_mpf);
      mpf_clear(tmp_mpf);
      mpq_mul(*res_ptr,*mpq_ptr,*res_ptr);
    }
    else
    {
      mpq_clear(*res_ptr);
      cfree(res_ptr);

      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
      BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_asterisk_equal#1");
      new_exception->params.push(1);
      new_exception->params.push(src_0_location->v_type);

      return false;
    }
  }

  BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_gmp_rational,res_ptr,2);

  BIC_SET_DESTINATION(new_location);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_gmp_rational_operator_binary_slash_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  mpq_t *res_ptr = (mpq_t *)cmalloc(sizeof(mpq_t));
  mpq_init(*res_ptr);

  mpq_t *mpq_ptr = (mpq_t *)((location_s *)dst_location)->v_data_ptr;

  switch (src_0_location->v_type) {
  case c_bi_class_char:
  {
    char divider = (char)src_0_location->v_data_ptr;

    // - ERROR -
    if (divider == 0)
    {
      mpq_clear(*res_ptr);
      cfree(res_ptr);

      exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    mpq_set_si(*res_ptr,divider,1);
    mpq_div(*res_ptr,*mpq_ptr,*res_ptr);
  }
  break;
  case c_bi_class_integer:
  {
    long long int divider = (long long int)src_0_location->v_data_ptr;

    // - ERROR -
    if (divider == 0)
    {
      mpq_clear(*res_ptr);
      cfree(res_ptr);

      exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    gmp_c::mpq_set_lli(*res_ptr,divider);
    mpq_div(*res_ptr,*mpq_ptr,*res_ptr);
  }
  break;
  case c_bi_class_float:
  {
    double divider = (double)src_0_location->v_data_ptr;

    // - ERROR -
    if (divider == 0.0)
    {
      mpq_clear(*res_ptr);
      cfree(res_ptr);

      exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    mpq_set_d(*res_ptr,divider);
    mpq_div(*res_ptr,*mpq_ptr,*res_ptr);
  }
  break;
  default:
    if (src_0_location->v_type == c_bi_class_gmp_integer)
    {
      mpz_t *divider = (mpz_t *)src_0_location->v_data_ptr;

      // - ERROR -
      if (mpz_sgn(*divider) == 0)
      {
        mpq_clear(*res_ptr);
        cfree(res_ptr);

        exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      mpq_set_z(*res_ptr,*divider);
      mpq_div(*res_ptr,*mpq_ptr,*res_ptr);
    }
    else if (src_0_location->v_type == c_bi_class_gmp_rational)
    {
      mpq_t *divider = (mpq_t *)src_0_location->v_data_ptr;

      // - ERROR -
      if (mpq_sgn(*divider) == 0)
      {
        mpq_clear(*res_ptr);
        cfree(res_ptr);

        exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      mpq_div(*res_ptr,*mpq_ptr,*divider);
    }
    else if (src_0_location->v_type == c_bi_class_mpfr_fixed)
    {
      mpfr_t *divider = (mpfr_t *)src_0_location->v_data_ptr;

      // - ERROR -
      if (mpfr_sgn(*divider) == 0)
      {
        mpq_clear(*res_ptr);
        cfree(res_ptr);

        exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      mpf_t tmp_mpf;
      mpf_init(tmp_mpf);
      mpfr_get_f(tmp_mpf,*divider,MPFR_RNDD);
      mpq_set_f(*res_ptr,tmp_mpf);
      mpf_clear(tmp_mpf);
      mpq_div(*res_ptr,*mpq_ptr,*res_ptr);
    }
    else
    {
      mpq_clear(*res_ptr);
      cfree(res_ptr);

      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
      BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_slash_equal#1");
      new_exception->params.push(1);
      new_exception->params.push(src_0_location->v_type);

      return false;
    }
  }

  BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_gmp_rational,res_ptr,2);

  BIC_SET_DESTINATION(new_location);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_gmp_rational_operator_binary_double_ls_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GMP_RATIONAL_BINARY_SHIFT(mul_2exp,"operator_binary_double_ls_br_equal#1");

  BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_gmp_rational,res_ptr,2);

  BIC_SET_DESTINATION(new_location);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_gmp_rational_operator_binary_double_rs_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GMP_RATIONAL_BINARY_SHIFT(div_2exp,"operator_binary_double_rs_br_equal#1");

  BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_gmp_rational,res_ptr,2);

  BIC_SET_DESTINATION(new_location);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_gmp_rational_operator_binary_double_ampersand(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GMP_RATIONAL_BINARY_LOGIC(&&,"operator_binary_double_ampersand#1");

  return true;
}/*}}}*/

bool bic_gmp_rational_operator_binary_double_pipe(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GMP_RATIONAL_BINARY_LOGIC(||,"operator_binary_double_pipe#1");

  return true;
}/*}}}*/

bool bic_gmp_rational_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_GMP_RATIONAL_COMPARE_WITH_TYPE_BOOL();

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_gmp_rational_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_GMP_RATIONAL_COMPARE_WITH_TYPE_BOOL();
  result = !result;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_gmp_rational_operator_binary_rs_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_GMP_RATIONAL_COMPARE_WITH_TYPE_INT("operator_binary_rs_br#1");

  result = result > 0;
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_gmp_rational_operator_binary_ls_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_GMP_RATIONAL_COMPARE_WITH_TYPE_INT("operator_binary_ls_br#1");

  result = result < 0;
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_gmp_rational_operator_binary_rs_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_GMP_RATIONAL_COMPARE_WITH_TYPE_INT("operator_binary_rs_br_equal#1");

  result = result >= 0;
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_gmp_rational_operator_binary_ls_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_GMP_RATIONAL_COMPARE_WITH_TYPE_INT("operator_binary_ls_br_equal#1");

  result = result <= 0;
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_gmp_rational_operator_binary_double_rs_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GMP_RATIONAL_BINARY_SHIFT(div_2exp,"operator_binary_double_rs_br#1");

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gmp_rational,res_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_gmp_rational_operator_binary_double_ls_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GMP_RATIONAL_BINARY_SHIFT(mul_2exp,"operator_binary_double_ls_br#1");

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gmp_rational,res_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_gmp_rational_operator_binary_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GMP_RATIONAL_BINARY_ADD_SUB(add,"operator_binary_plus#1");

  return true;
}/*}}}*/

bool bic_gmp_rational_operator_binary_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GMP_RATIONAL_BINARY_ADD_SUB(sub,"operator_binary_minus#1");

  return true;
}/*}}}*/

bool bic_gmp_rational_operator_binary_asterisk(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  mpq_t *mpq_ptr = (mpq_t *)dst_location->v_data_ptr;

  switch (src_0_location->v_type) {
  case c_bi_class_char:
  {
    mpq_t *res_ptr = (mpq_t *)cmalloc(sizeof(mpq_t));
    mpq_init(*res_ptr);
    gmp_c::mpq_mul_lli(*res_ptr,*mpq_ptr,(char)src_0_location->v_data_ptr);

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gmp_rational,res_ptr);
    BIC_SET_RESULT(new_location);
  }
  break;
  case c_bi_class_integer:
  {
    mpq_t *res_ptr = (mpq_t *)cmalloc(sizeof(mpq_t));
    mpq_init(*res_ptr);
    gmp_c::mpq_mul_lli(*res_ptr,*mpq_ptr,(long long int)src_0_location->v_data_ptr);

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gmp_rational,res_ptr);
    BIC_SET_RESULT(new_location);
  }
  break;
  case c_bi_class_float:
  {
    mpfr_t *res_ptr = (mpfr_t *)cmalloc(sizeof(mpfr_t));
    mpfr_init_set_q(*res_ptr,*mpq_ptr,MPFR_RNDD);
    mpfr_mul_d(*res_ptr,*res_ptr,(double)src_0_location->v_data_ptr,MPFR_RNDD);

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mpfr_fixed,res_ptr);
    BIC_SET_RESULT(new_location);
  }
  break;
  default:
    if (src_0_location->v_type == c_bi_class_gmp_integer)
    {
      mpq_t *res_ptr = (mpq_t *)cmalloc(sizeof(mpq_t));
      mpq_init(*res_ptr);
      gmp_c::mpq_mul_z(*res_ptr,*mpq_ptr,*((mpz_t *)src_0_location->v_data_ptr));

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gmp_rational,res_ptr);
      BIC_SET_RESULT(new_location);
    }
    else if (src_0_location->v_type == c_bi_class_gmp_rational)
    {
      mpq_t *res_ptr = (mpq_t *)cmalloc(sizeof(mpq_t));
      mpq_init(*res_ptr);
      mpq_mul(*res_ptr,*mpq_ptr,*((mpq_t *)src_0_location->v_data_ptr));

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gmp_rational,res_ptr);
      BIC_SET_RESULT(new_location);
    }
    else if (src_0_location->v_type == c_bi_class_mpfr_fixed)
    {
      mpfr_t *res_ptr = (mpfr_t *)cmalloc(sizeof(mpfr_t));
      mpfr_init_set_q(*res_ptr,*mpq_ptr,MPFR_RNDD);
      mpfr_mul(*res_ptr,*res_ptr,*((mpfr_t *)src_0_location->v_data_ptr),MPFR_RNDD);

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mpfr_fixed,res_ptr);
      BIC_SET_RESULT(new_location);
    }
    else
    {
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
      BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_asterisk#1");
      new_exception->params.push(1);
      new_exception->params.push(src_0_location->v_type);

      return false;
    }
  }

  return true;
}/*}}}*/

bool bic_gmp_rational_operator_binary_slash(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  mpq_t *mpq_ptr = (mpq_t *)dst_location->v_data_ptr;

  switch (src_0_location->v_type) {
  case c_bi_class_char:
  {
    char divider = (char)src_0_location->v_data_ptr;

    // - ERROR -
    if (divider == 0)
    {
      exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    mpq_t *res_ptr = (mpq_t *)cmalloc(sizeof(mpq_t));
    mpq_init(*res_ptr);
    mpq_set_si(*res_ptr,divider,1);
    mpq_div(*res_ptr,*mpq_ptr,*res_ptr);

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gmp_rational,res_ptr);
    BIC_SET_RESULT(new_location);
  }
  break;
  case c_bi_class_integer:
  {
    long long int divider = (long long int)src_0_location->v_data_ptr;

    // - ERROR -
    if (divider == 0)
    {
      exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    mpq_t *res_ptr = (mpq_t *)cmalloc(sizeof(mpq_t));
    mpq_init(*res_ptr);
    gmp_c::mpq_set_lli(*res_ptr,divider);
    mpq_div(*res_ptr,*mpq_ptr,*res_ptr);

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gmp_rational,res_ptr);
    BIC_SET_RESULT(new_location);
  }
  break;
  case c_bi_class_float:
  {
    double divider = (double)src_0_location->v_data_ptr;

    // - ERROR -
    if (divider == 0.0)
    {
      exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    mpfr_t *res_ptr = (mpfr_t *)cmalloc(sizeof(mpfr_t));
    mpfr_init_set_q(*res_ptr,*mpq_ptr,MPFR_RNDD);
    mpfr_div_d(*res_ptr,*res_ptr,divider,MPFR_RNDD);

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mpfr_fixed,res_ptr);
    BIC_SET_RESULT(new_location);
  }
  break;
  default:
    if (src_0_location->v_type == c_bi_class_gmp_integer)
    {
      mpz_t *divider = (mpz_t *)src_0_location->v_data_ptr;

      // - ERROR -
      if (mpz_sgn(*divider) == 0)
      {
        exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      mpq_t *res_ptr = (mpq_t *)cmalloc(sizeof(mpq_t));
      mpq_init(*res_ptr);
      mpq_set_z(*res_ptr,*divider);
      mpq_div(*res_ptr,*mpq_ptr,*res_ptr);

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gmp_rational,res_ptr);
      BIC_SET_RESULT(new_location);
    }
    else if (src_0_location->v_type == c_bi_class_gmp_rational)
    {
      mpq_t *divider = (mpq_t *)src_0_location->v_data_ptr;

      // - ERROR -
      if (mpq_sgn(*divider) == 0)
      {
        exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      mpq_t *res_ptr = (mpq_t *)cmalloc(sizeof(mpq_t));
      mpq_init(*res_ptr);
      mpq_div(*res_ptr,*mpq_ptr,*divider);

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gmp_rational,res_ptr);
      BIC_SET_RESULT(new_location);
    }
    else if (src_0_location->v_type == c_bi_class_mpfr_fixed)
    {
      mpfr_t *divider = (mpfr_t *)src_0_location->v_data_ptr;

      // - ERROR -
      if (mpfr_sgn(*divider) == 0)
      {
        exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      mpfr_t *res_ptr = (mpfr_t *)cmalloc(sizeof(mpfr_t));
      mpfr_init_set_q(*res_ptr,*mpq_ptr,MPFR_RNDD);
      mpfr_div(*res_ptr,*res_ptr,*divider,MPFR_RNDD);

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mpfr_fixed,res_ptr);
      BIC_SET_RESULT(new_location);
    }
    else
    {
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
      BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_slash#1");
      new_exception->params.push(1);
      new_exception->params.push(src_0_location->v_type);

      return false;
    }
  }

  return true;
}/*}}}*/

bool bic_gmp_rational_operator_unary_post_double_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GMP_RATIONAL_POST_UNARY_INC_DEC(add);

  return true;
}/*}}}*/

bool bic_gmp_rational_operator_unary_post_double_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GMP_RATIONAL_POST_UNARY_INC_DEC(sub);

  return true;
}/*}}}*/

bool bic_gmp_rational_operator_unary_pre_double_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GMP_RATIONAL_PRE_UNARY_INC_DEC(add);

  return true;
}/*}}}*/

bool bic_gmp_rational_operator_unary_pre_double_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GMP_RATIONAL_PRE_UNARY_INC_DEC(sub);

  return true;
}/*}}}*/

bool bic_gmp_rational_operator_unary_pre_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  dst_location->v_reference_cnt.atomic_inc();

  BIC_SET_RESULT(dst_location);

  return true;
}/*}}}*/

bool bic_gmp_rational_operator_unary_pre_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  mpq_t *res_ptr = (mpq_t *)cmalloc(sizeof(mpq_t));
  mpq_init(*res_ptr);

  mpq_neg(*res_ptr,*((mpq_t *)dst_location->v_data_ptr));

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_gmp_rational,res_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_gmp_rational_operator_unary_pre_exclamation(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = mpq_sgn(*((mpq_t *)dst_location->v_data_ptr)) == 0;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_gmp_rational_method_GmpRational_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  mpq_set_si(*((mpq_t *)dst_location->v_data_ptr),0,1);

  return true;
}/*}}}*/

bool bic_gmp_rational_method_GmpRational_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  mpq_t *mpq_ptr = (mpq_t *)dst_location->v_data_ptr;

  switch (src_0_location->v_type)
  {
  case c_bi_class_char:
    mpq_set_si(*mpq_ptr,(char)src_0_location->v_data_ptr,1);
    break;
  case c_bi_class_integer:
    gmp_c::mpq_set_lli(*mpq_ptr,(long long int)src_0_location->v_data_ptr);
    break;
  case c_bi_class_float:
    mpq_set_d(*mpq_ptr,(double)src_0_location->v_data_ptr);
    break;
  case c_bi_class_string:

    // - ERROR -
    if (mpq_set_str(*mpq_ptr,((string_s *)src_0_location->v_data_ptr)->data,0))
    {
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GMP_NUMBER_CONVERT_INVALID_STRING,operands[c_source_pos_idx],src_0_location);
      new_exception->params.push(c_bi_class_gmp_rational);
      new_exception->params.push(0);

      return false;
    }

    mpq_canonicalize(*mpq_ptr);

    break;
  default:
    if (src_0_location->v_type == c_bi_class_gmp_integer)
    {
      mpq_set_z(*mpq_ptr,*((mpz_t *)src_0_location->v_data_ptr));
    }
    else if (src_0_location->v_type == c_bi_class_gmp_rational)
    {
      mpq_set(*mpq_ptr,*((mpq_t *)src_0_location->v_data_ptr));
    }
    else if (src_0_location->v_type == c_bi_class_mpfr_fixed)
    {
      mpf_t tmp_mpf;
      mpf_init(tmp_mpf);
      mpfr_get_f(tmp_mpf,*((mpfr_t *)src_0_location->v_data_ptr),MPFR_RNDD);
      mpq_set_f(*mpq_ptr,tmp_mpf);
      mpf_clear(tmp_mpf);
    }
    else
    {
      // - ERROR -
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
      BIC_EXCEPTION_PUSH_METHOD_RI("GmpRational#1");
      new_exception->params.push(1);
      new_exception->params.push(src_0_location->v_type);

      return false;
    }
  }

  return true;
}/*}}}*/

bool bic_gmp_rational_method_GmpRational_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  mpq_t *mpq_ptr = (mpq_t *)dst_location->v_data_ptr;

  switch (src_0_location->v_type)
  {
  case c_bi_class_integer:
  {
    if (src_1_location->v_type != c_bi_class_integer)
    {
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
      BIC_EXCEPTION_PUSH_METHOD_RI("GmpRational#2");
      new_exception->params.push(2);
      new_exception->params.push(src_0_location->v_type);
      new_exception->params.push(src_1_location->v_type);

      return false;
    }

    gmp_c::mpq_set_lli_lli(*mpq_ptr,
        (long long int)src_0_location->v_data_ptr,
        (long long int)src_1_location->v_data_ptr);
  }
  break;

  case c_bi_class_string:
  {
    if (src_1_location->v_type != c_bi_class_integer)
    {
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
      BIC_EXCEPTION_PUSH_METHOD_RI("GmpRational#2");
      new_exception->params.push(2);
      new_exception->params.push(src_0_location->v_type);
      new_exception->params.push(src_1_location->v_type);

      return false;
    }

    string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;
    long long int base = (long long int)src_1_location->v_data_ptr;

    if (base < 2 || base > 62)
    {
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GMP_NUMBER_BASE_OUT_OF_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(c_bi_class_gmp_rational);
      new_exception->params.push(base);

      return false;
    }

    // - ERROR -
    if (mpq_set_str(*mpq_ptr,string_ptr->data,base))
    {
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GMP_NUMBER_CONVERT_INVALID_STRING,operands[c_source_pos_idx],src_0_location);
      new_exception->params.push(c_bi_class_gmp_rational);
      new_exception->params.push(base);

      return false;
    }

    mpq_canonicalize(*mpq_ptr);
  }
  break;

  // - ERROR -
  default:
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("GmpRational#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  return true;
}/*}}}*/

bool bic_gmp_rational_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  if (src_0_location->v_type == c_bi_class_gmp_rational)
  {
    mpq_t *first_ptr = (mpq_t *)dst_location->v_data_ptr;
    mpq_t *second_ptr = (mpq_t *)src_0_location->v_data_ptr;

    result = mpq_cmp(*first_ptr,*second_ptr);
  }
  else
  {
    result = c_bi_class_gmp_rational < src_0_location->v_type ? -1 : 1;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_gmp_rational_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING(
    gmp_c::setf(*string_ptr,"%Qd",*((mpq_t *)dst_location->v_data_ptr))
  );

  return true;
}/*}}}*/

bool bic_gmp_rational_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - print value to standard output -
  mpfr_printf("%Qd",*((mpq_t *)dst_location->v_data_ptr));

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

// - class MPFR_FIXED -
built_in_class_s mpfr_fixed_class =
{/*{{{*/
  "MpfrFixed",
  c_modifier_public | c_modifier_final,
  30, mpfr_fixed_methods,
  0, mpfr_fixed_variables,
  bic_mpfr_fixed_consts,
  bic_mpfr_fixed_init,
  bic_mpfr_fixed_clear,
  bic_mpfr_fixed_compare,
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

built_in_method_s mpfr_fixed_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_mpfr_fixed_operator_binary_equal
  },
  {
    "operator_binary_plus_equal#1",
    c_modifier_public | c_modifier_final,
    bic_mpfr_fixed_operator_binary_plus_equal
  },
  {
    "operator_binary_minus_equal#1",
    c_modifier_public | c_modifier_final,
    bic_mpfr_fixed_operator_binary_minus_equal
  },
  {
    "operator_binary_asterisk_equal#1",
    c_modifier_public | c_modifier_final,
    bic_mpfr_fixed_operator_binary_asterisk_equal
  },
  {
    "operator_binary_slash_equal#1",
    c_modifier_public | c_modifier_final,
    bic_mpfr_fixed_operator_binary_slash_equal
  },
  {
    "operator_binary_double_ampersand#1",
    c_modifier_public | c_modifier_final,
    bic_mpfr_fixed_operator_binary_double_ampersand
  },
  {
    "operator_binary_double_pipe#1",
    c_modifier_public | c_modifier_final,
    bic_mpfr_fixed_operator_binary_double_pipe
  },
  {
    "operator_binary_double_equal#1",
    c_modifier_public | c_modifier_final,
    bic_mpfr_fixed_operator_binary_double_equal
  },
  {
    "operator_binary_exclamation_equal#1",
    c_modifier_public | c_modifier_final,
    bic_mpfr_fixed_operator_binary_exclamation_equal
  },
  {
    "operator_binary_rs_br#1",
    c_modifier_public | c_modifier_final,
    bic_mpfr_fixed_operator_binary_rs_br
  },
  {
    "operator_binary_ls_br#1",
    c_modifier_public | c_modifier_final,
    bic_mpfr_fixed_operator_binary_ls_br
  },
  {
    "operator_binary_rs_br_equal#1",
    c_modifier_public | c_modifier_final,
    bic_mpfr_fixed_operator_binary_rs_br_equal
  },
  {
    "operator_binary_ls_br_equal#1",
    c_modifier_public | c_modifier_final,
    bic_mpfr_fixed_operator_binary_ls_br_equal
  },
  {
    "operator_binary_plus#1",
    c_modifier_public | c_modifier_final,
    bic_mpfr_fixed_operator_binary_plus
  },
  {
    "operator_binary_minus#1",
    c_modifier_public | c_modifier_final,
    bic_mpfr_fixed_operator_binary_minus
  },
  {
    "operator_binary_asterisk#1",
    c_modifier_public | c_modifier_final,
    bic_mpfr_fixed_operator_binary_asterisk
  },
  {
    "operator_binary_slash#1",
    c_modifier_public | c_modifier_final,
    bic_mpfr_fixed_operator_binary_slash
  },
  {
    "operator_unary_post_double_plus#0",
    c_modifier_public | c_modifier_final,
    bic_mpfr_fixed_operator_unary_post_double_plus
  },
  {
    "operator_unary_post_double_minus#0",
    c_modifier_public | c_modifier_final,
    bic_mpfr_fixed_operator_unary_post_double_minus
  },
  {
    "operator_unary_pre_double_plus#0",
    c_modifier_public | c_modifier_final,
    bic_mpfr_fixed_operator_unary_pre_double_plus
  },
  {
    "operator_unary_pre_double_minus#0",
    c_modifier_public | c_modifier_final,
    bic_mpfr_fixed_operator_unary_pre_double_minus
  },
  {
    "operator_unary_pre_plus#0",
    c_modifier_public | c_modifier_final,
    bic_mpfr_fixed_operator_unary_pre_plus
  },
  {
    "operator_unary_pre_minus#0",
    c_modifier_public | c_modifier_final,
    bic_mpfr_fixed_operator_unary_pre_minus
  },
  {
    "operator_unary_pre_exclamation#0",
    c_modifier_public | c_modifier_final,
    bic_mpfr_fixed_operator_unary_pre_exclamation
  },
  {
    "MpfrFixed#0",
    c_modifier_public | c_modifier_final,
    bic_mpfr_fixed_method_MpfrFixed_0
  },
  {
    "MpfrFixed#1",
    c_modifier_public | c_modifier_final,
    bic_mpfr_fixed_method_MpfrFixed_1
  },
  {
    "MpfrFixed#2",
    c_modifier_public | c_modifier_final,
    bic_mpfr_fixed_method_MpfrFixed_2
  },
  {
    "compare#1",
    c_modifier_public | c_modifier_final,
    bic_mpfr_fixed_method_compare_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_mpfr_fixed_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_mpfr_fixed_method_print_0
  },
};/*}}}*/

built_in_variable_s mpfr_fixed_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_MPFR_FIXED_BINARY_ADD_SUB_MUL(OPERATION,NAME) \
/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
  \
  mpfr_t *res_ptr = (mpfr_t *)cmalloc(sizeof(mpfr_t));\
  mpfr_init(*res_ptr);\
  \
  mpfr_t *mpfr_ptr = (mpfr_t *)((location_s *)dst_location)->v_data_ptr;\
  \
  switch (src_0_location->v_type) {\
  case c_bi_class_char:\
    mpfr_ ## OPERATION ## _si(*res_ptr,*mpfr_ptr,(char)src_0_location->v_data_ptr,MPFR_RNDD);\
    break;\
  case c_bi_class_integer:\
    gmp_c::mpfr_ ## OPERATION ## _lli(*res_ptr,*mpfr_ptr,(long long int)src_0_location->v_data_ptr,MPFR_RNDD);\
    break;\
  case c_bi_class_float:\
    mpfr_ ## OPERATION ## _d(*res_ptr,*mpfr_ptr,(double)src_0_location->v_data_ptr,MPFR_RNDD);\
    break;\
  default:\
    if (src_0_location->v_type == c_bi_class_gmp_integer)\
    {\
      mpfr_ ## OPERATION ## _z(*res_ptr,*mpfr_ptr,*((mpz_t *)src_0_location->v_data_ptr),MPFR_RNDD);\
    }\
    else if (src_0_location->v_type == c_bi_class_gmp_rational)\
    {\
      mpfr_ ## OPERATION ## _q(*res_ptr,*mpfr_ptr,*((mpq_t *)src_0_location->v_data_ptr),MPFR_RNDD);\
    }\
    else if (src_0_location->v_type == c_bi_class_mpfr_fixed)\
    {\
      mpfr_ ## OPERATION(*res_ptr,*mpfr_ptr,*((mpfr_t *)src_0_location->v_data_ptr),MPFR_RNDD);\
    }\
    else\
    {\
      mpfr_clear(*res_ptr);\
      cfree(res_ptr);\
      \
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
      \
      return false;\
    }\
  }\
/*}}}*/

#define BIC_MPFR_FIXED_BINARY_DIV(NAME) \
/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
  \
  mpfr_t *res_ptr = (mpfr_t *)cmalloc(sizeof(mpfr_t));\
  mpfr_init(*res_ptr);\
  \
  mpfr_t *mpfr_ptr = (mpfr_t *)((location_s *)dst_location)->v_data_ptr;\
  \
  switch (src_0_location->v_type) {\
  case c_bi_class_char:\
  {\
    char divider = (char)src_0_location->v_data_ptr;\
    \
    /* - ERROR - */\
    if (divider == 0)\
    {\
      mpfr_clear(*res_ptr);\
      cfree(res_ptr);\
      \
      exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      return false;\
    }\
    \
    mpfr_div_si(*res_ptr,*mpfr_ptr,divider,MPFR_RNDD);\
  }\
  break;\
  case c_bi_class_integer:\
  {\
    long long int divider = (long long int)src_0_location->v_data_ptr;\
    \
    /* - ERROR - */\
    if (divider == 0)\
    {\
      mpfr_clear(*res_ptr);\
      cfree(res_ptr);\
      \
      exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      return false;\
    }\
    \
    gmp_c::mpfr_div_lli(*res_ptr,*mpfr_ptr,divider,MPFR_RNDD);\
  }\
  break;\
  case c_bi_class_float:\
  {\
    double divider = (double)src_0_location->v_data_ptr;\
    \
    /* - ERROR - */\
    if (divider == 0.0)\
    {\
      mpfr_clear(*res_ptr);\
      cfree(res_ptr);\
      \
      exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      return false;\
    }\
    \
    mpfr_div_d(*res_ptr,*mpfr_ptr,divider,MPFR_RNDD);\
  }\
  break;\
  default:\
    if (src_0_location->v_type == c_bi_class_gmp_integer)\
    {\
      mpz_t *divider = (mpz_t *)src_0_location->v_data_ptr;\
      \
      /* - ERROR - */\
      if (mpz_sgn(*divider) == 0)\
      {\
        mpfr_clear(*res_ptr);\
        cfree(res_ptr);\
        \
        exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);\
        return false;\
      }\
      \
      mpfr_div_z(*res_ptr,*mpfr_ptr,*divider,MPFR_RNDD);\
    }\
    else if (src_0_location->v_type == c_bi_class_gmp_rational)\
    {\
      mpq_t *divider = (mpq_t *)src_0_location->v_data_ptr;\
      \
      /* - ERROR - */\
      if (mpq_sgn(*divider) == 0)\
      {\
        mpfr_clear(*res_ptr);\
        cfree(res_ptr);\
        \
        exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);\
        return false;\
      }\
      \
      mpfr_div_q(*res_ptr,*mpfr_ptr,*divider,MPFR_RNDD);\
    }\
    else if (src_0_location->v_type == c_bi_class_mpfr_fixed)\
    {\
      mpfr_t *divider = (mpfr_t *)src_0_location->v_data_ptr;\
      \
      /* - ERROR - */\
      if (mpfr_sgn(*divider) == 0)\
      {\
        mpfr_clear(*res_ptr);\
        cfree(res_ptr);\
        \
        exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);\
        return false;\
      }\
      \
      mpfr_div(*res_ptr,*mpfr_ptr,*divider,MPFR_RNDD);\
    }\
    else\
    {\
      mpfr_clear(*res_ptr);\
      cfree(res_ptr);\
      \
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
      \
      return false;\
    }\
  }\
/*}}}*/

#define BIC_MFPR_FIXED_BINARY_LOGIC(OPERATOR,NAME) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
  \
  long long int result;\
  \
  mpfr_t *mpfr_ptr = (mpfr_t *)dst_location->v_data_ptr;\
  \
  switch (src_0_location->v_type) {\
  case c_bi_class_char:\
    result = mpfr_sgn(*mpfr_ptr) OPERATOR (char)src_0_location->v_data_ptr;\
    break;\
  case c_bi_class_integer:\
    result = mpfr_sgn(*mpfr_ptr) OPERATOR (long long int)src_0_location->v_data_ptr;\
    break;\
  case c_bi_class_float:\
    result = mpfr_sgn(*mpfr_ptr) OPERATOR (double)src_0_location->v_data_ptr;\
    break;\
  default:\
    if (src_0_location->v_type == c_bi_class_gmp_integer)\
    {\
      result = mpfr_sgn(*mpfr_ptr) OPERATOR mpz_sgn(*((mpz_t *)src_0_location->v_data_ptr));\
    }\
    else if (src_0_location->v_type == c_bi_class_gmp_rational)\
    {\
      result = mpfr_sgn(*mpfr_ptr) OPERATOR mpq_sgn(*((mpq_t *)src_0_location->v_data_ptr));\
    }\
    else if (src_0_location->v_type == c_bi_class_mpfr_fixed)\
    {\
      result = mpfr_sgn(*mpfr_ptr) OPERATOR mpfr_sgn(*((mpfr_t *)src_0_location->v_data_ptr));\
    }\
    else\
    {\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
      \
      return false;\
    }\
  }\
  \
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
}/*}}}*/

#define BIC_MPFR_FIXED_COMPARE_WITH_TYPE_BOOL() \
{/*{{{*/\
  mpfr_t *mpfr_ptr = (mpfr_t *)dst_location->v_data_ptr;\
  \
  switch (src_0_location->v_type) {\
  case c_bi_class_char:\
    result = mpfr_cmp_si(*mpfr_ptr,(char)src_0_location->v_data_ptr) == 0;\
    break;\
  case c_bi_class_integer:\
    result = gmp_c::mpfr_cmp_lli(*mpfr_ptr,(long long int)src_0_location->v_data_ptr) == 0;\
    break;\
  case c_bi_class_float:\
    result = mpfr_cmp_d(*mpfr_ptr,(double)src_0_location->v_data_ptr) == 0;\
    break;\
  default:\
    if (src_0_location->v_type == c_bi_class_gmp_integer)\
    {\
      result = mpfr_cmp_z(*mpfr_ptr,*((mpz_t *)src_0_location->v_data_ptr)) == 0;\
    }\
    else if (src_0_location->v_type == c_bi_class_gmp_rational)\
    {\
      result = mpfr_cmp_q(*mpfr_ptr,*((mpq_t *)src_0_location->v_data_ptr)) == 0;\
    }\
    else if (src_0_location->v_type == c_bi_class_mpfr_fixed)\
    {\
      result = mpfr_cmp(*mpfr_ptr,*((mpfr_t *)src_0_location->v_data_ptr)) == 0;\
    }\
    else\
    {\
      result = 0;\
    }\
  }\
}/*}}}*/

#define BIC_MPFR_FIXED_COMPARE_WITH_TYPE_INT(NAME) \
{/*{{{*/\
  mpfr_t *mpfr_ptr = (mpfr_t *)dst_location->v_data_ptr;\
  \
  switch (src_0_location->v_type) {\
  case c_bi_class_char:\
    result = mpfr_cmp_si(*mpfr_ptr,(char)src_0_location->v_data_ptr);\
    break;\
  case c_bi_class_integer:\
    result = gmp_c::mpfr_cmp_lli(*mpfr_ptr,(long long int)src_0_location->v_data_ptr);\
    break;\
  case c_bi_class_float:\
    result = mpfr_cmp_d(*mpfr_ptr,(double)src_0_location->v_data_ptr);\
    break;\
  default:\
    if (src_0_location->v_type == c_bi_class_gmp_integer)\
    {\
      result = mpfr_cmp_z(*mpfr_ptr,*((mpz_t *)src_0_location->v_data_ptr));\
    }\
    else if (src_0_location->v_type == c_bi_class_gmp_rational)\
    {\
      result = mpfr_cmp_q(*mpfr_ptr,*((mpq_t *)src_0_location->v_data_ptr));\
    }\
    else if (src_0_location->v_type == c_bi_class_mpfr_fixed)\
    {\
      result = mpfr_cmp(*mpfr_ptr,*((mpfr_t *)src_0_location->v_data_ptr));\
    }\
    else\
    {\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
      \
      return false;\
    }\
  }\
}/*}}}*/

#define BIC_MPFR_FIXED_POST_UNARY_INC_DEC(OPERATION) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  \
  mpfr_t *res_ptr = (mpfr_t *)cmalloc(sizeof(mpfr_t));\
  mpfr_init(*res_ptr);\
  \
  mpfr_t *mpfr_ptr = (mpfr_t *)((location_s *)dst_location)->v_data_ptr;\
  mpfr_ ## OPERATION ## _si(*res_ptr,*mpfr_ptr,1,MPFR_RNDD);\
  \
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mpfr_fixed,res_ptr);\
  BIC_SET_RESULT(new_location);\
  \
  pointer tmp_location = res_location;\
  res_location = dst_location;\
  dst_location = tmp_location;\
}/*}}}*/

#define BIC_MPFR_FIXED_PRE_UNARY_INC_DEC(OPERATION) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  \
  mpfr_t *res_ptr = (mpfr_t *)cmalloc(sizeof(mpfr_t));\
  mpfr_init(*res_ptr);\
  \
  mpfr_t *mpfr_ptr = (mpfr_t *)((location_s *)dst_location)->v_data_ptr;\
  mpfr_ ## OPERATION ## _si(*res_ptr,*mpfr_ptr,1,MPFR_RNDD);\
  \
  BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_mpfr_fixed,res_ptr,2);\
  \
  BIC_SET_DESTINATION(new_location);\
  BIC_SET_RESULT(new_location);\
}/*}}}*/

void bic_mpfr_fixed_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_mpfr_fixed_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  mpfr_t *mpfr_ptr = (mpfr_t *)cmalloc(sizeof(mpfr_t));
  mpfr_init(*mpfr_ptr);
  location_ptr->v_data_ptr = mpfr_ptr;
}/*}}}*/

void bic_mpfr_fixed_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  mpfr_t *mpfr_ptr = (mpfr_t *)location_ptr->v_data_ptr;
  mpfr_clear(*mpfr_ptr);
  cfree(mpfr_ptr);
}/*}}}*/

int bic_mpfr_fixed_compare(location_s *first_loc,location_s *second_loc)
{/*{{{*/
  mpfr_t *first_ptr = (mpfr_t *)first_loc->v_data_ptr;
  mpfr_t *second_ptr = (mpfr_t *)second_loc->v_data_ptr;

  return mpfr_cmp(*first_ptr,*second_ptr);
}/*}}}*/

bool bic_mpfr_fixed_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_mpfr_fixed_operator_binary_plus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_MPFR_FIXED_BINARY_ADD_SUB_MUL(add,"operator_binary_plus_equal#1");

  BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_mpfr_fixed,res_ptr,2);

  BIC_SET_DESTINATION(new_location);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_mpfr_fixed_operator_binary_minus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_MPFR_FIXED_BINARY_ADD_SUB_MUL(sub,"operator_binary_minus_equal#1");

  BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_mpfr_fixed,res_ptr,2);

  BIC_SET_DESTINATION(new_location);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_mpfr_fixed_operator_binary_asterisk_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_MPFR_FIXED_BINARY_ADD_SUB_MUL(mul,"operator_binary_asterisk_equal#1");

  BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_mpfr_fixed,res_ptr,2);

  BIC_SET_DESTINATION(new_location);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_mpfr_fixed_operator_binary_slash_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_MPFR_FIXED_BINARY_DIV("operator_binary_slash_equal#1");

  BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_mpfr_fixed,res_ptr,2);

  BIC_SET_DESTINATION(new_location);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_mpfr_fixed_operator_binary_double_ampersand(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_MFPR_FIXED_BINARY_LOGIC(&&,"operator_binary_double_ampersand#1");

  return true;
}/*}}}*/

bool bic_mpfr_fixed_operator_binary_double_pipe(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_MFPR_FIXED_BINARY_LOGIC(||,"operator_binary_double_pipe#1");

  return true;
}/*}}}*/

bool bic_mpfr_fixed_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_MPFR_FIXED_COMPARE_WITH_TYPE_BOOL();

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_mpfr_fixed_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_MPFR_FIXED_COMPARE_WITH_TYPE_BOOL();
  result = !result;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_mpfr_fixed_operator_binary_rs_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_MPFR_FIXED_COMPARE_WITH_TYPE_INT("operator_binary_rs_br#1");

  result = result > 0;
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_mpfr_fixed_operator_binary_ls_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_MPFR_FIXED_COMPARE_WITH_TYPE_INT("operator_binary_ls_br#1");

  result = result < 0;
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_mpfr_fixed_operator_binary_rs_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_MPFR_FIXED_COMPARE_WITH_TYPE_INT("operator_binary_rs_br_equal#1");

  result = result >= 0;
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_mpfr_fixed_operator_binary_ls_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_MPFR_FIXED_COMPARE_WITH_TYPE_INT("operator_binary_ls_br_equal#1");

  result = result <= 0;
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_mpfr_fixed_operator_binary_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_MPFR_FIXED_BINARY_ADD_SUB_MUL(add,"operator_binary_plus#1");

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mpfr_fixed,res_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_mpfr_fixed_operator_binary_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_MPFR_FIXED_BINARY_ADD_SUB_MUL(sub,"operator_binary_minus#1");

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mpfr_fixed,res_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_mpfr_fixed_operator_binary_asterisk(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_MPFR_FIXED_BINARY_ADD_SUB_MUL(mul,"operator_binary_asterisk#1");

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mpfr_fixed,res_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_mpfr_fixed_operator_binary_slash(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_MPFR_FIXED_BINARY_DIV("operator_binary_slash#1");

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mpfr_fixed,res_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_mpfr_fixed_operator_unary_post_double_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_MPFR_FIXED_POST_UNARY_INC_DEC(add);

  return true;
}/*}}}*/

bool bic_mpfr_fixed_operator_unary_post_double_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_MPFR_FIXED_POST_UNARY_INC_DEC(sub);

  return true;
}/*}}}*/

bool bic_mpfr_fixed_operator_unary_pre_double_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_MPFR_FIXED_PRE_UNARY_INC_DEC(add);

  return true;
}/*}}}*/

bool bic_mpfr_fixed_operator_unary_pre_double_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_MPFR_FIXED_PRE_UNARY_INC_DEC(sub);

  return true;
}/*}}}*/

bool bic_mpfr_fixed_operator_unary_pre_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  dst_location->v_reference_cnt.atomic_inc();

  BIC_SET_RESULT(dst_location);

  return true;
}/*}}}*/

bool bic_mpfr_fixed_operator_unary_pre_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  mpfr_t *res_ptr = (mpfr_t *)cmalloc(sizeof(mpfr_t));
  mpfr_init(*res_ptr);

  mpfr_neg(*res_ptr,*((mpfr_t *)dst_location->v_data_ptr),MPFR_RNDD);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mpfr_fixed,res_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_mpfr_fixed_operator_unary_pre_exclamation(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = mpfr_sgn(*((mpfr_t *)dst_location->v_data_ptr)) == 0;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_mpfr_fixed_method_MpfrFixed_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  mpfr_set_si(*((mpfr_t *)dst_location->v_data_ptr),0,MPFR_RNDD);

  return true;
}/*}}}*/

bool bic_mpfr_fixed_method_MpfrFixed_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  mpfr_t *mpfr_ptr = (mpfr_t *)dst_location->v_data_ptr;

  switch (src_0_location->v_type)
  {
  case c_bi_class_char:
    mpfr_set_si(*mpfr_ptr,(char)src_0_location->v_data_ptr,MPFR_RNDD);
    break;
  case c_bi_class_integer:
    mpfr_set_sj(*mpfr_ptr,(long long int)src_0_location->v_data_ptr,MPFR_RNDD);
    break;
  case c_bi_class_float:
    mpfr_set_d(*mpfr_ptr,(double)src_0_location->v_data_ptr,MPFR_RNDD);
    break;
  case c_bi_class_string:

    // - ERROR -
    if (mpfr_set_str(*mpfr_ptr,((string_s *)src_0_location->v_data_ptr)->data,0,MPFR_RNDD))
    {
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GMP_NUMBER_CONVERT_INVALID_STRING,operands[c_source_pos_idx],src_0_location);
      new_exception->params.push(c_bi_class_mpfr_fixed);
      new_exception->params.push(0);

      return false;
    }
    break;
  default:
    if (src_0_location->v_type == c_bi_class_gmp_integer)
    {
      mpfr_set_z(*mpfr_ptr,*((mpz_t *)src_0_location->v_data_ptr),MPFR_RNDD);
    }
    else if (src_0_location->v_type == c_bi_class_gmp_rational)
    {
      mpfr_set_q(*mpfr_ptr,*((mpq_t *)src_0_location->v_data_ptr),MPFR_RNDD);
    }
    else if (src_0_location->v_type == c_bi_class_mpfr_fixed)
    {
      mpfr_set(*mpfr_ptr,*((mpfr_t *)src_0_location->v_data_ptr),MPFR_RNDD);
    }
    else
    {
      // - ERROR -
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
      BIC_EXCEPTION_PUSH_METHOD_RI("MpfrFixed#1");
      new_exception->params.push(1);
      new_exception->params.push(src_0_location->v_type);

      return false;
    }
  }

  return true;
}/*}}}*/

bool bic_mpfr_fixed_method_MpfrFixed_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  switch (src_0_location->v_type)
  {
  case c_bi_class_string:
  {
    if (src_1_location->v_type != c_bi_class_integer)
    {
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
      BIC_EXCEPTION_PUSH_METHOD_RI("MpfrFixed#2");
      new_exception->params.push(2);
      new_exception->params.push(src_0_location->v_type);
      new_exception->params.push(src_1_location->v_type);

      return false;
    }

    string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;
    long long int base = (long long int)src_1_location->v_data_ptr;

    if (base < 2 || base > 62)
    {
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GMP_NUMBER_BASE_OUT_OF_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(c_bi_class_mpfr_fixed);
      new_exception->params.push(base);

      return false;
    }

    // - ERROR -
    if (mpfr_set_str(*((mpfr_t *)dst_location->v_data_ptr),string_ptr->data,base,MPFR_RNDD))
    {
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GMP_NUMBER_CONVERT_INVALID_STRING,operands[c_source_pos_idx],src_0_location);
      new_exception->params.push(c_bi_class_mpfr_fixed);
      new_exception->params.push(base);

      return false;
    }
  }
  break;

  // - ERROR -
  default:
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("MpfrFixed#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  return true;
}/*}}}*/

bool bic_mpfr_fixed_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  if (src_0_location->v_type == c_bi_class_mpfr_fixed)
  {
    mpfr_t *first_ptr = (mpfr_t *)dst_location->v_data_ptr;
    mpfr_t *second_ptr = (mpfr_t *)src_0_location->v_data_ptr;

    result = mpfr_cmp(*first_ptr,*second_ptr);
  }
  else
  {
    result = c_bi_class_mpfr_fixed < src_0_location->v_type ? -1 : 1;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_mpfr_fixed_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING(
    gmp_c::setf(*string_ptr,"%Rf",*((mpf_t *)dst_location->v_data_ptr))
  );

  return true;
}/*}}}*/

bool bic_mpfr_fixed_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - print value to standard output -
  mpfr_printf("%Rf",*((mpfr_t *)dst_location->v_data_ptr));

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

