
@begin
include "gsl_module.h"
@end

// - GSL indexes of built in classes -
unsigned c_bi_class_gsl_spline = c_idx_not_exist;

// - GSL module -
EXPORT built_in_module_s module =
{/*{{{*/
  1,                   // Class count
  gsl_classes,         // Classes

  0,                   // Error base index
  5,                   // Error count
  gsl_error_strings,   // Error strings

  gsl_initialize,      // Initialize function
  gsl_print_exception, // Print exceptions function
};/*}}}*/

// - GSL classes -
built_in_class_s *gsl_classes[] =
{/*{{{*/
  &gsl_spline_class,
};/*}}}*/

// - GSL error strings -
const char *gsl_error_strings[] =
{/*{{{*/
  "error_GSL_INVALID_DATA_VALUE_TYPE",
  "error_GSL_SPLINE_UNKNOWN_INTERP_TYPE",
  "error_GSL_SPLINE_INVALID_DATA_LENGTHS",
  "error_GSL_SPLINE_CREATE_ERROR",
  "error_GSL_SPLINE_EVAL_ERROR",
};/*}}}*/

// - GSL initialize -
bool gsl_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize gsl_spline class identifier -
  c_bi_class_gsl_spline = class_base_idx++;

  return true;
}/*}}}*/

// - GSL print exception -
bool gsl_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_GSL_INVALID_DATA_VALUE_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid type of data value, expected %s\n",it.class_symbol_names[it.class_records[exception.params[0]].name_idx].data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GSL_SPLINE_UNKNOWN_INTERP_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUnrecognized interpolation type\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GSL_SPLINE_INVALID_DATA_LENGTHS:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid interpolation data lengths %" HOST_LL_FORMAT "d and %" HOST_LL_FORMAT "d\n",exception.params[0],exception.params[1]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GSL_SPLINE_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating spline interpolation\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GSL_SPLINE_EVAL_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while evaluating spline interpolation\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class GSL_SPLINE -
built_in_class_s gsl_spline_class =
{/*{{{*/
  "GslSpline",
  c_modifier_public | c_modifier_final,
  5, gsl_spline_methods,
  7, gsl_spline_variables,
  bic_gsl_spline_consts,
  bic_gsl_spline_init,
  bic_gsl_spline_clear,
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

built_in_method_s gsl_spline_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_gsl_spline_operator_binary_equal
  },
  {
    "GslSpline#3",
    c_modifier_public | c_modifier_final,
    bic_gsl_spline_method_GslSpline_3
  },
  {
    "eval#1",
    c_modifier_public | c_modifier_final,
    bic_gsl_spline_method_eval_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gsl_spline_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_gsl_spline_method_print_0
  },
};/*}}}*/

built_in_variable_s gsl_spline_variables[] =
{/*{{{*/

  // - interpolation type constants -
  { "INTERP_LINEAR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INTERP_POLYNOMIAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INTERP_CSPLINE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INTERP_CSPLINE_PERIODIC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INTERP_AKIMA", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INTERP_AKIMA_PERIODIC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INTERP_STEFFEN", c_modifier_public | c_modifier_static | c_modifier_static_const },
};/*}}}*/

void bic_gsl_spline_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert interpolation type constants -
  {
    const_locations.push_blanks(7);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 7);

#define CREATE_INTERPOLATION_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_INTERPOLATION_TYPE_BIC_STATIC(c_gsl_interp_type_linear);
    CREATE_INTERPOLATION_TYPE_BIC_STATIC(c_gsl_interp_type_polynomial);
    CREATE_INTERPOLATION_TYPE_BIC_STATIC(c_gsl_interp_type_cspline);
    CREATE_INTERPOLATION_TYPE_BIC_STATIC(c_gsl_interp_type_cspline_periodic);
    CREATE_INTERPOLATION_TYPE_BIC_STATIC(c_gsl_interp_type_akima);
    CREATE_INTERPOLATION_TYPE_BIC_STATIC(c_gsl_interp_type_akima_periodic);
    CREATE_INTERPOLATION_TYPE_BIC_STATIC(c_gsl_interp_type_steffen);
  }

}/*}}}*/

void bic_gsl_spline_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (gsl_spline_s *)nullptr;
}/*}}}*/

void bic_gsl_spline_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  gsl_spline_s *spl_ptr = (gsl_spline_s *)location_ptr->v_data_ptr;

  if (spl_ptr != nullptr)
  {
    spl_ptr->clear(it);
    cfree(spl_ptr);
  }
}/*}}}*/

bool bic_gsl_spline_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_gsl_spline_method_GslSpline_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
interp_type:retrieve_integer
x_array:c_bi_class_array
y_array:c_bi_class_array
>
method GslSpline
; @end

  pointer_array_s *x_arr_ptr = (pointer_array_s *)src_1_location->v_data_ptr;
  pointer_array_s *y_arr_ptr = (pointer_array_s *)src_2_location->v_data_ptr;

  // - ERROR -
  if (interp_type >= c_gsl_interp_type_count)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GSL_SPLINE_UNKNOWN_INTERP_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - retrieve interpolation type pointer -
  const gsl_interp_type *interp_type_ptr = c_gsl_interp_types[interp_type];

  // - ERROR -
  if (x_arr_ptr->used != y_arr_ptr->used || x_arr_ptr->used < interp_type_ptr->min_size)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GSL_SPLINE_INVALID_DATA_LENGTHS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(x_arr_ptr->used);
    new_exception->params.push(y_arr_ptr->used);

    return false;
  }

  size_t size = x_arr_ptr->used;

  double *xa = (double *)cmalloc(size*sizeof(double));
  double *ya = (double *)cmalloc(size*sizeof(double));

  if (size > 0)
  {
    double *x_ptr = xa;
    double *x_ptr_end = x_ptr + size;
    double *y_ptr = ya;

    pointer *xi_ptr = x_arr_ptr->data;
    pointer *yi_ptr = y_arr_ptr->data;

    do {

      // - ERROR -
      if (!it.retrieve_float(it.get_location_value(*xi_ptr++),*x_ptr++))
      {
        cfree(xa);
        cfree(ya);

        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GSL_INVALID_DATA_VALUE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(c_bi_class_float);

        return false;
      }

      // - ERROR -
      if (!it.retrieve_float(it.get_location_value(*yi_ptr++),*y_ptr++))
      {
        cfree(xa);
        cfree(ya);

        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GSL_INVALID_DATA_VALUE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(c_bi_class_float);

        return false;
      }

    } while(x_ptr < x_ptr_end);
  }

  // - create gsl_spline object -
  gsl_spline_s *spline_ptr = (gsl_spline_s *)cmalloc(sizeof(gsl_spline_s));
  spline_ptr->init();

  // - ERROR -
  if ((spline_ptr->accel = gsl_interp_accel_alloc()) == nullptr ||
      (spline_ptr->interp = gsl_interp_alloc(interp_type_ptr,size)) == nullptr ||
      gsl_interp_init(spline_ptr->interp,xa,ya,size) != GSL_SUCCESS)
  {
    cfree(xa);
    cfree(ya);

    spline_ptr->clear(it);
    cfree(spline_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_GSL_SPLINE_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set spline properties -
  spline_ptr->xa = xa;
  spline_ptr->ya = ya;
  spline_ptr->size = size;

  // - set gsl_spline destination location -
  dst_location->v_data_ptr = (gsl_spline_s *)spline_ptr;

  return true;
}/*}}}*/

bool bic_gsl_spline_method_eval_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
x_value:retrieve_float
>
method eval
; @end

  gsl_spline_s *spline_ptr = (gsl_spline_s *)dst_location->v_data_ptr;

  double result;

  // - check lower bound -
  if (x_value <= spline_ptr->xa[0])
  {
    result = spline_ptr->ya[0];
  }

  // - check upper bound -
  else if (x_value >= spline_ptr->xa[spline_ptr->size - 1])
  {
    result = spline_ptr->ya[spline_ptr->size - 1];
  }

  // - retrieve interpolated value -
  else
  {
    // - ERROR -
    if (gsl_interp_eval_e(spline_ptr->interp,spline_ptr->xa,spline_ptr->ya,
                          x_value,spline_ptr->accel,&result) != GSL_SUCCESS)
    {
      exception_s::throw_exception(it,module.error_base + c_error_GSL_SPLINE_EVAL_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }
  }

  BIC_SIMPLE_SET_RES(c_bi_class_float,result);

  return true;
}/*}}}*/

bool bic_gsl_spline_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("GslSpline"),"GslSpline");
  );

  return true;
}/*}}}*/

bool bic_gsl_spline_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("GslSpline");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

