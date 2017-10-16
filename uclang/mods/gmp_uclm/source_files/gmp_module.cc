
@begin
include "gmp_module.h"
@end

// - GMP indexes of built in classes -
unsigned c_bi_class_gmp = c_idx_not_exist;
unsigned c_bi_class_gmp_integer = c_idx_not_exist;
unsigned c_bi_class_gmp_rational = c_idx_not_exist;
unsigned c_bi_class_gmp_fixed_point = c_idx_not_exist;

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
  &gmp_fixed_point_class,
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

  // - initialize gmp_fixed_point class identifier -
  c_bi_class_gmp_fixed_point = class_base_idx++;

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
  7, gmp_integer_methods,
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
  nullptr,
  nullptr,
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
    else if (src_0_location->v_type == c_bi_class_gmp_fixed_point)
    {
      mpz_set_f(*mpz_ptr,*((mpf_t *)src_0_location->v_data_ptr));
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
  gmp_printf("%Zd",*((mpz_t *)dst_location->v_data_ptr));

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

// - class GMP_RATIONAL -
built_in_class_s gmp_rational_class =
{/*{{{*/
  "GmpRational",
  c_modifier_public | c_modifier_final,
  7, gmp_rational_methods,
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
  nullptr,
  nullptr,
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

bool bic_gmp_rational_method_GmpRational_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  mpq_set_d(*((mpq_t *)dst_location->v_data_ptr),0.0);

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
    else if (src_0_location->v_type == c_bi_class_gmp_fixed_point)
    {
      mpq_set_f(*mpq_ptr,*((mpf_t *)src_0_location->v_data_ptr));
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
  gmp_printf("%Qd",*((mpq_t *)dst_location->v_data_ptr));

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

// - class GMP_FIXED_POINT -
built_in_class_s gmp_fixed_point_class =
{/*{{{*/
  "GmpFixedPoint",
  c_modifier_public | c_modifier_final,
  7, gmp_fixed_point_methods,
  0, gmp_fixed_point_variables,
  bic_gmp_fixed_point_consts,
  bic_gmp_fixed_point_init,
  bic_gmp_fixed_point_clear,
  bic_gmp_fixed_point_compare,
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

built_in_method_s gmp_fixed_point_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_fixed_point_operator_binary_equal
  },
  {
    "GmpFixedPoint#0",
    c_modifier_public | c_modifier_final,
    bic_gmp_fixed_point_method_GmpFixedPoint_0
  },
  {
    "GmpFixedPoint#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_fixed_point_method_GmpFixedPoint_1
  },
  {
    "GmpFixedPoint#2",
    c_modifier_public | c_modifier_final,
    bic_gmp_fixed_point_method_GmpFixedPoint_2
  },
  {
    "compare#1",
    c_modifier_public | c_modifier_final,
    bic_gmp_fixed_point_method_compare_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_gmp_fixed_point_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_gmp_fixed_point_method_print_0
  },
};/*}}}*/

built_in_variable_s gmp_fixed_point_variables[] =
{/*{{{*/
};/*}}}*/

void bic_gmp_fixed_point_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_gmp_fixed_point_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  mpf_t *mpf_ptr = (mpf_t *)cmalloc(sizeof(mpf_t));
  mpf_init(*mpf_ptr);
  location_ptr->v_data_ptr = mpf_ptr;
}/*}}}*/

void bic_gmp_fixed_point_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  mpf_t *mpf_ptr = (mpf_t *)location_ptr->v_data_ptr;
  mpf_clear(*mpf_ptr);
  cfree(mpf_ptr);
}/*}}}*/

int bic_gmp_fixed_point_compare(location_s *first_loc,location_s *second_loc)
{/*{{{*/
  mpf_t *first_ptr = (mpf_t *)first_loc->v_data_ptr;
  mpf_t *second_ptr = (mpf_t *)second_loc->v_data_ptr;

  return mpf_cmp(*first_ptr,*second_ptr);
}/*}}}*/

bool bic_gmp_fixed_point_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_gmp_fixed_point_method_GmpFixedPoint_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  mpf_set_d(*((mpf_t *)dst_location->v_data_ptr),0.0);

  return true;
}/*}}}*/

bool bic_gmp_fixed_point_method_GmpFixedPoint_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  mpf_t *mpf_ptr = (mpf_t *)dst_location->v_data_ptr;

  switch (src_0_location->v_type)
  {
  case c_bi_class_char:
    mpf_set_si(*mpf_ptr,(char)src_0_location->v_data_ptr);
    break;
  case c_bi_class_integer:
    gmp_c::mpf_set_lli(*mpf_ptr,(long long int)src_0_location->v_data_ptr);
    break;
  case c_bi_class_float:
    mpf_set_d(*mpf_ptr,(double)src_0_location->v_data_ptr);
    break;
  case c_bi_class_string:

    // - ERROR -
    if (mpf_set_str(*mpf_ptr,((string_s *)src_0_location->v_data_ptr)->data,0))
    {
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GMP_NUMBER_CONVERT_INVALID_STRING,operands[c_source_pos_idx],src_0_location);
      new_exception->params.push(c_bi_class_gmp_fixed_point);
      new_exception->params.push(0);

      return false;
    }
    break;
  default:
    if (src_0_location->v_type == c_bi_class_gmp_integer)
    {
      mpf_set_z(*mpf_ptr,*((mpz_t *)src_0_location->v_data_ptr));
    }
    else if (src_0_location->v_type == c_bi_class_gmp_rational)
    {
      mpf_set_q(*mpf_ptr,*((mpq_t *)src_0_location->v_data_ptr));
    }
    else if (src_0_location->v_type == c_bi_class_gmp_fixed_point)
    {
      mpf_set(*mpf_ptr,*((mpf_t *)src_0_location->v_data_ptr));
    }
    else
    {
      // - ERROR -
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
      BIC_EXCEPTION_PUSH_METHOD_RI("GmpFixedPoint#1");
      new_exception->params.push(1);
      new_exception->params.push(src_0_location->v_type);

      return false;
    }
  }

  return true;
}/*}}}*/

bool bic_gmp_fixed_point_method_GmpFixedPoint_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
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
      BIC_EXCEPTION_PUSH_METHOD_RI("GmpFixedPoint#2");
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
      new_exception->params.push(c_bi_class_gmp_fixed_point);
      new_exception->params.push(base);

      return false;
    }

    // - ERROR -
    if (mpf_set_str(*((mpf_t *)dst_location->v_data_ptr),string_ptr->data,base))
    {
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GMP_NUMBER_CONVERT_INVALID_STRING,operands[c_source_pos_idx],src_0_location);
      new_exception->params.push(c_bi_class_gmp_fixed_point);
      new_exception->params.push(base);

      return false;
    }
  }
  break;

  // - ERROR -
  default:
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("GmpFixedPoint#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  return true;
}/*}}}*/

bool bic_gmp_fixed_point_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  if (src_0_location->v_type == c_bi_class_gmp_fixed_point)
  {
    mpf_t *first_ptr = (mpf_t *)dst_location->v_data_ptr;
    mpf_t *second_ptr = (mpf_t *)src_0_location->v_data_ptr;

    result = mpf_cmp(*first_ptr,*second_ptr);
  }
  else
  {
    result = c_bi_class_gmp_fixed_point < src_0_location->v_type ? -1 : 1;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_gmp_fixed_point_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING(
    gmp_c::setf(*string_ptr,"%Ff",*((mpf_t *)dst_location->v_data_ptr))
  );

  return true;
}/*}}}*/

bool bic_gmp_fixed_point_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - print value to standard output -
  gmp_printf("%Ff",*((mpf_t *)dst_location->v_data_ptr));

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

