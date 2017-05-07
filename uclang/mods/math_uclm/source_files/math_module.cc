
@begin
include "math_module.h"
@end

// - MATH indexes of built in classes -
unsigned c_bi_class_math = c_idx_not_exist;
unsigned c_bi_class_vec2 = c_idx_not_exist;
unsigned c_bi_class_vec3 = c_idx_not_exist;
unsigned c_bi_class_vec4 = c_idx_not_exist;
unsigned c_bi_class_mat4 = c_idx_not_exist;
unsigned c_bi_class_primes = c_idx_not_exist;

// - MATH module -
built_in_module_s module =
{/*{{{*/
  6,                    // Class count
  math_classes,         // Classes

  0,                    // Error base index
  9,                    // Error count
  math_error_strings,   // Error strings

  math_initialize,      // Initialize function
  math_print_exception, // Print exceptions function
};/*}}}*/

// - MATH classes -
built_in_class_s *math_classes[] =
{/*{{{*/
  &math_class,
  &vec2_class,
  &vec3_class,
  &vec4_class,
  &mat4_class,
  &primes_class,
};/*}}}*/

// - MATH error strings -
const char *math_error_strings[] =
{/*{{{*/
  "error_MATH_ARRAY_OF_NUMBERS_WRONG_LENGTH",
  "error_MATH_ARRAY_OF_NUMBERS_EXPECTED",
  "error_MAT4_INDEX_EXCEEDS_ROW_COUNT",
  "error_MAT4_INDEX_EXCEEDS_COLUMN_COUNT",
  "error_PRIMES_SIEVE_SIZE_NEGATIVE",
  "error_PRIMES_SIEVE_SIZE_TOO_BIG",
  "error_PRIMES_SIEVE_SIZE_NOT_ENOUGH",
  "error_PRIMES_PRIME_FACTORS_NUMBER_LESS_THAN_ONE",
  "error_PRIMES_INDEX_DOES_NOT_REFER_TO_VALID_VALUE",
};/*}}}*/

// - MATH initialize -
bool math_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize math class identifier -
  c_bi_class_math = class_base_idx++;

  // - initialize vec2 class identifier -
  c_bi_class_vec2 = class_base_idx++;

  // - initialize vec3 class identifier -
  c_bi_class_vec3 = class_base_idx++;

  // - initialize vec4 class identifier -
  c_bi_class_vec4 = class_base_idx++;

  // - initialize mat4 class identifier -
  c_bi_class_mat4 = class_base_idx++;

  // - initialize primes class identifier -
  c_bi_class_primes = class_base_idx++;

  return true;
}/*}}}*/

// - MATH print exception -
bool math_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_MATH_ARRAY_OF_NUMBERS_WRONG_LENGTH:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nExpected array of length %" HOST_LL_FORMAT "d, received array of length %" HOST_LL_FORMAT "d\n",exception.params[0],exception.params[1]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MATH_ARRAY_OF_NUMBERS_EXPECTED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nExpected array of float and integer values\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MAT4_INDEX_EXCEEDS_ROW_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nIndex %" HOST_LL_FORMAT "d exceeds count of matrix rows\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MAT4_INDEX_EXCEEDS_COLUMN_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nIndex %" HOST_LL_FORMAT "d exceeds count of matrix columns\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PRIMES_SIEVE_SIZE_NEGATIVE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nRequested prime sieve size %" HOST_LL_FORMAT "d is less than zero\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PRIMES_SIEVE_SIZE_TOO_BIG:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nRequested prime sieve size %" HOST_LL_FORMAT "d is too big\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PRIMES_SIEVE_SIZE_NOT_ENOUGH:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSieve size is not enough to finish computation\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PRIMES_PRIME_FACTORS_NUMBER_LESS_THAN_ONE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nPrime factors parameter %" HOST_LL_FORMAT "d is less than one\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PRIMES_INDEX_DOES_NOT_REFER_TO_VALID_VALUE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nIndex %" HOST_LL_FORMAT "d does not refer to valid prime number\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

#define MATH_RETRIEVE_FLOAT_FROM_ARRAY(LOCATION,FLOATS_PTR,FLOAT_CNT) \
  /*{{{*/\
  const unsigned float_cnt = FLOAT_CNT;\
  \
  pointer_array_s *array_ptr = (pointer_array_s *)(LOCATION)->v_data_ptr;\
  \
  /* - ERROR - */\
  if (array_ptr->used != float_cnt)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_MATH_ARRAY_OF_NUMBERS_WRONG_LENGTH,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(float_cnt);\
    new_exception->params.push(array_ptr->used);\
    \
    return false;\
  }\
  \
  /* - process source number array - */\
  pointer *p_ptr = array_ptr->data;\
  pointer *p_ptr_end = p_ptr + array_ptr->used;\
  float *f_ptr = FLOATS_PTR;\
  do {\
    location_s *item_location = it.get_location_value(*p_ptr);\
    \
    /* - store value from array to floats - */\
    switch (item_location->v_type)\
    {\
    case c_bi_class_integer:\
      *f_ptr = (float)(long long int)item_location->v_data_ptr;\
      break;\
      \
    case c_bi_class_float:\
      *f_ptr = (double)item_location->v_data_ptr;\
      break;\
      \
      /* - ERROR - */\
    default:\
      exception_s::throw_exception(it,module.error_base + c_error_MATH_ARRAY_OF_NUMBERS_EXPECTED,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      return false;\
    }\
    \
  } while(++f_ptr,++p_ptr < p_ptr_end);\
  /*}}}*/

#define MATH_RETRIEVE_ARRAY_FROM_FLOAT(FLOATS_PTR,FLOAT_CNT,ARRAY_PTR) \
  {/*{{{*/\
    float *f_ptr = FLOATS_PTR;\
    float *f_ptr_end = f_ptr + FLOAT_CNT;\
    do {\
      double value = *f_ptr;\
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_float,value);\
      (ARRAY_PTR)->push(new_location);\
    } while(++f_ptr < f_ptr_end);\
  }/*}}}*/

#define MATH_RETRIEVE_ARRAY_FROM_FLOAT_STEP(FLOATS_PTR,FLOAT_CNT,FLOAT_STEP,ARRAY_PTR) \
  {/*{{{*/\
    float *f_ptr = FLOATS_PTR;\
    float *f_ptr_end = f_ptr + FLOAT_CNT;\
    do {\
      double value = *f_ptr;\
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_float,value);\
      (ARRAY_PTR)->push(new_location);\
    } while((f_ptr += (FLOAT_STEP)) < f_ptr_end);\
  }/*}}}*/

#define MATH_RETRIEVE_FLOAT(LOCATION) \
  {/*{{{*/\
    switch ((LOCATION)->v_type)\
    {\
    case c_bi_class_integer:\
      *float_ptr++ = (float)(long long int)(LOCATION)->v_data_ptr;\
      break;\
      \
    case c_bi_class_float:\
      *float_ptr++ = (double)(LOCATION)->v_data_ptr;\
      break;\
      \
    default:\
      type_error = true;\
    }\
  }/*}}}*/

#define MATH_VEC_RETRIEVE_ELEMENT(VEC_TYPE,ELEMENT_NAME) \
  {/*{{{*/\
    pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
    \
    double result = ((glm::VEC_TYPE *)dst_location->v_data_ptr)->ELEMENT_NAME;\
    \
    BIC_SIMPLE_SET_RES(c_bi_class_float,result);\
    \
    return true;\
  }/*}}}*/

#define BIC_VEC_BINARY_EQUAL_OPS_FLOAT_VEC(VEC_TYPE,OPERATOR,NAME) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
  glm::VEC_TYPE &vec_dst = *((glm::VEC_TYPE *)((location_s *)dst_location)->v_data_ptr);\
  glm::VEC_TYPE *vec_res_ptr;\
\
  double scalar;\
  if (it.retrieve_float(src_0_location,scalar))\
  {\
    vec_res_ptr = new glm::VEC_TYPE(vec_dst OPERATOR (float)scalar);\
  }\
  else if (src_0_location->v_type == c_bi_class_ ## VEC_TYPE)\
  {\
    glm::VEC_TYPE &vec_src = *((glm::VEC_TYPE *)src_0_location->v_data_ptr);\
    vec_res_ptr = new glm::VEC_TYPE(vec_dst OPERATOR vec_src);\
  }\
  \
  /* - ERROR - */\
  else\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
    new_exception->params.push(1);\
    new_exception->params.push(src_0_location->v_type);\
\
    return false;\
  }\
\
  BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_ ## VEC_TYPE,vec_res_ptr,2);\
\
  BIC_SET_DESTINATION(new_location);\
  BIC_SET_RESULT(new_location);\
\
  return true;\
}/*}}}*/

#define BIC_VEC_BINARY_OPS_FLOAT_VEC(VEC_TYPE,OPERATOR,NAME) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
  glm::VEC_TYPE &vec_dst = *((glm::VEC_TYPE *)dst_location->v_data_ptr);\
  glm::VEC_TYPE *vec_res_ptr;\
\
  double scalar;\
  if (it.retrieve_float(src_0_location,scalar))\
  {\
    vec_res_ptr = new glm::VEC_TYPE(vec_dst OPERATOR (float)scalar);\
  }\
  else if (src_0_location->v_type == c_bi_class_ ## VEC_TYPE)\
  {\
    glm::VEC_TYPE &vec_src = *((glm::VEC_TYPE *)src_0_location->v_data_ptr);\
    vec_res_ptr = new glm::VEC_TYPE(vec_dst OPERATOR vec_src);\
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
\
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_ ## VEC_TYPE,vec_res_ptr);\
  BIC_SET_RESULT(new_location);\
\
  return true;\
}/*}}}*/

#define BIC_VEC_UNARY_FUNCTION(VEC_TYPE,FUNCTION,NAME) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  glm::VEC_TYPE &vec_dst = *((glm::VEC_TYPE *)dst_location->v_data_ptr);\
\
  double result = glm::FUNCTION(vec_dst);\
\
  BIC_SIMPLE_SET_RES(c_bi_class_float,result);\
\
  return true;\
}/*}}}*/

#define BIC_VEC_BINARY_FUNCTION_OPS_VEC(VEC_TYPE,FUNCTION,NAME) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
  /* - ERROR - */\
  if (src_0_location->v_type != c_bi_class_ ## VEC_TYPE)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
    new_exception->params.push(1);\
    new_exception->params.push(src_0_location->v_type);\
\
    return false;\
  }\
\
  glm::VEC_TYPE &vec_dst = *((glm::VEC_TYPE *)dst_location->v_data_ptr);\
  glm::VEC_TYPE &vec_src = *((glm::VEC_TYPE *)src_0_location->v_data_ptr);\
\
  double result = glm::FUNCTION(vec_dst,vec_src);\
\
  BIC_SIMPLE_SET_RES(c_bi_class_float,result);\
\
  return true;\
}/*}}}*/

// - class MATH -
built_in_class_s math_class =
{/*{{{*/
  "Math",
  c_modifier_public | c_modifier_final,
  2, math_methods,
  3, math_variables,
  bic_math_consts,
  bic_math_init,
  bic_math_clear,
  NULL,
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

built_in_method_s math_methods[] =
{/*{{{*/
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_math_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_math_method_print_0
  },
};/*}}}*/

built_in_variable_s math_variables[] =
{/*{{{*/
  {
    "PI",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "E",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "GOLDEN_RATIO",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
};/*}}}*/

void bic_math_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert math basic float constants -
  {
    const_locations.push_blanks(3);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 3);

#define CREATE_MATH_BASIC_FLOAT_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_float;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (double)VALUE;\
  cv_ptr++;

    CREATE_MATH_BASIC_FLOAT_BIC_STATIC(3.14159265358979323846264338327950288L);
    CREATE_MATH_BASIC_FLOAT_BIC_STATIC(2.71828182845904523536028747135266250L);
    CREATE_MATH_BASIC_FLOAT_BIC_STATIC(1.61803398874989484820458683436563812L);
  }
}/*}}}*/

void bic_math_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_math_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_math_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Math"),"Math");
  );

  return true;
}/*}}}*/

bool bic_math_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("Math");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class VEC2 -
built_in_class_s vec2_class =
{/*{{{*/
  "Vec2",
  c_modifier_public | c_modifier_final,
  23, vec2_methods,
  0, vec2_variables,
  bic_vec2_consts,
  bic_vec2_init,
  bic_vec2_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  bic_vec2_pack,
  bic_vec2_unpack,
  NULL,
  NULL
};/*}}}*/

built_in_method_s vec2_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_vec2_operator_binary_equal
  },
  {
    "operator_binary_plus_equal#1",
    c_modifier_public | c_modifier_final,
    bic_vec2_operator_binary_plus_equal
  },
  {
    "operator_binary_minus_equal#1",
    c_modifier_public | c_modifier_final,
    bic_vec2_operator_binary_minus_equal
  },
  {
    "operator_binary_asterisk_equal#1",
    c_modifier_public | c_modifier_final,
    bic_vec2_operator_binary_asterisk_equal
  },
  {
    "operator_binary_slash_equal#1",
    c_modifier_public | c_modifier_final,
    bic_vec2_operator_binary_slash_equal
  },
  {
    "operator_binary_plus#1",
    c_modifier_public | c_modifier_final,
    bic_vec2_operator_binary_plus
  },
  {
    "operator_binary_minus#1",
    c_modifier_public | c_modifier_final,
    bic_vec2_operator_binary_minus
  },
  {
    "operator_binary_asterisk#1",
    c_modifier_public | c_modifier_final,
    bic_vec2_operator_binary_asterisk
  },
  {
    "operator_binary_slash#1",
    c_modifier_public | c_modifier_final,
    bic_vec2_operator_binary_slash
  },
  {
    "Vec2#0",
    c_modifier_public | c_modifier_final,
    bic_vec2_method_Vec2_0
  },
  {
    "Vec2#1",
    c_modifier_public | c_modifier_final,
    bic_vec2_method_Vec2_1
  },
  {
    "Vec2#2",
    c_modifier_public | c_modifier_final,
    bic_vec2_method_Vec2_2
  },
  { "x#0", c_modifier_public | c_modifier_final, bic_vec2_method_x_0 },
  { "r#0", c_modifier_public | c_modifier_final, bic_vec2_method_x_0 },
  { "s#0", c_modifier_public | c_modifier_final, bic_vec2_method_x_0 },
  { "y#0", c_modifier_public | c_modifier_final, bic_vec2_method_y_0 },
  { "g#0", c_modifier_public | c_modifier_final, bic_vec2_method_y_0 },
  { "t#0", c_modifier_public | c_modifier_final, bic_vec2_method_y_0 },
  {
    "data#0",
    c_modifier_public | c_modifier_final,
    bic_vec2_method_data_0
  },
  {
    "dot#1",
    c_modifier_public | c_modifier_final,
    bic_vec2_method_dot_1
  },
  {
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_vec2_method_length_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_vec2_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_vec2_method_print_0
  },
};/*}}}*/

built_in_variable_s vec2_variables[] =
{/*{{{*/
};/*}}}*/

void bic_vec2_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_vec2_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  glm::vec2 *v2_ptr = new glm::vec2();

  location_ptr->v_data_ptr = (glm::vec2 *)v2_ptr;
}/*}}}*/

void bic_vec2_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  glm::vec2 *v2_ptr = (glm::vec2 *)location_ptr->v_data_ptr;

  delete v2_ptr;
}/*}}}*/

bool bic_vec2_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack)
{/*{{{*/
  glm::vec2 &v2 = *((glm::vec2 *)location_ptr->v_data_ptr);

  stream.append(sizeof(float),(const char *)&v2.x);
  stream.append(sizeof(float),(const char *)&v2.y);

  return true;
}/*}}}*/

bool bic_vec2_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos)
{/*{{{*/
  glm::vec2 *v2_ptr = new glm::vec2();

  location_ptr->v_data_ptr = (glm::vec2 *)v2_ptr;

  if (stream.used < (sizeof(float) << 1))
  {
    return false;
  }

  stream.from_end(sizeof(float),(char *)&v2_ptr->y,order_bytes);
  stream.from_end(sizeof(float),(char *)&v2_ptr->x,order_bytes);

  return true;
}/*}}}*/

bool bic_vec2_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_vec2_operator_binary_plus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_VEC_BINARY_EQUAL_OPS_FLOAT_VEC(vec2,+,"operator_binary_plus_equal#1")
}/*}}}*/

bool bic_vec2_operator_binary_minus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_VEC_BINARY_EQUAL_OPS_FLOAT_VEC(vec2,-,"operator_binary_minus_equal#1")
}/*}}}*/

bool bic_vec2_operator_binary_asterisk_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_VEC_BINARY_EQUAL_OPS_FLOAT_VEC(vec2,*,"operator_binary_asterisk_equal#1")
}/*}}}*/

bool bic_vec2_operator_binary_slash_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_VEC_BINARY_EQUAL_OPS_FLOAT_VEC(vec2,/,"operator_binary_slash_equal#1")
}/*}}}*/

bool bic_vec2_operator_binary_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_VEC_BINARY_OPS_FLOAT_VEC(vec2,+,"operator_binary_plus#1");
}/*}}}*/

bool bic_vec2_operator_binary_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_VEC_BINARY_OPS_FLOAT_VEC(vec2,-,"operator_binary_minus#1");
}/*}}}*/

bool bic_vec2_operator_binary_asterisk(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_VEC_BINARY_OPS_FLOAT_VEC(vec2,*,"operator_binary_asterisk#1");
}/*}}}*/

bool bic_vec2_operator_binary_slash(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_VEC_BINARY_OPS_FLOAT_VEC(vec2,/,"operator_binary_slash#1");
}/*}}}*/

bool bic_vec2_method_Vec2_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  return true;
}/*}}}*/

bool bic_vec2_method_Vec2_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_array)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Vec2#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  glm::vec2 &v2 = *((glm::vec2 *)dst_location->v_data_ptr);

  MATH_RETRIEVE_FLOAT_FROM_ARRAY(src_0_location,glm::value_ptr(v2),2);

  return true;
}/*}}}*/

bool bic_vec2_method_Vec2_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  glm::vec2 &v2 = *((glm::vec2 *)dst_location->v_data_ptr);

  bool type_error = false;
  float *float_ptr = glm::value_ptr(v2);

  MATH_RETRIEVE_FLOAT(src_0_location);
  MATH_RETRIEVE_FLOAT(src_1_location);

  // - ERROR -
  if (type_error)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Vec2#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  return true;
}/*}}}*/

bool bic_vec2_method_x_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  MATH_VEC_RETRIEVE_ELEMENT(vec2,x);
}/*}}}*/

bool bic_vec2_method_y_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  MATH_VEC_RETRIEVE_ELEMENT(vec2,y);
}/*}}}*/

bool bic_vec2_method_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  glm::vec2 *v2_ptr = (glm::vec2 *)dst_location->v_data_ptr;

  pointer_array_s *array_ptr = it.get_new_array_ptr();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  MATH_RETRIEVE_ARRAY_FROM_FLOAT(&v2_ptr->x,2,array_ptr);

  return true;
}/*}}}*/

bool bic_vec2_method_dot_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_VEC_BINARY_FUNCTION_OPS_VEC(vec2,dot,"dot#1");
}/*}}}*/

bool bic_vec2_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_VEC_UNARY_FUNCTION(vec2,length,"length#0");
}/*}}}*/

bool bic_vec2_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING(
    glm::vec2 &v2 = *((glm::vec2 *)dst_location->v_data_ptr);

    string_ptr->setf("[%f,%f]",v2.x,v2.y);
  );

  return true;
}/*}}}*/

bool bic_vec2_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  glm::vec2 &v2 = *((glm::vec2 *)dst_location->v_data_ptr);

  printf("[%f,%f]",v2.x,v2.y);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

// - class VEC3 -
built_in_class_s vec3_class =
{/*{{{*/
  "Vec3",
  c_modifier_public | c_modifier_final,
  27, vec3_methods,
  0, vec3_variables,
  bic_vec3_consts,
  bic_vec3_init,
  bic_vec3_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  bic_vec3_pack,
  bic_vec3_unpack,
  NULL,
  NULL
};/*}}}*/

built_in_method_s vec3_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_vec3_operator_binary_equal
  },
  {
    "operator_binary_plus_equal#1",
    c_modifier_public | c_modifier_final,
    bic_vec3_operator_binary_plus_equal
  },
  {
    "operator_binary_minus_equal#1",
    c_modifier_public | c_modifier_final,
    bic_vec3_operator_binary_minus_equal
  },
  {
    "operator_binary_asterisk_equal#1",
    c_modifier_public | c_modifier_final,
    bic_vec3_operator_binary_asterisk_equal
  },
  {
    "operator_binary_slash_equal#1",
    c_modifier_public | c_modifier_final,
    bic_vec3_operator_binary_slash_equal
  },
  {
    "operator_binary_plus#1",
    c_modifier_public | c_modifier_final,
    bic_vec3_operator_binary_plus
  },
  {
    "operator_binary_minus#1",
    c_modifier_public | c_modifier_final,
    bic_vec3_operator_binary_minus
  },
  {
    "operator_binary_asterisk#1",
    c_modifier_public | c_modifier_final,
    bic_vec3_operator_binary_asterisk
  },
  {
    "operator_binary_slash#1",
    c_modifier_public | c_modifier_final,
    bic_vec3_operator_binary_slash
  },
  {
    "Vec3#0",
    c_modifier_public | c_modifier_final,
    bic_vec3_method_Vec3_0
  },
  {
    "Vec3#1",
    c_modifier_public | c_modifier_final,
    bic_vec3_method_Vec3_1
  },
  {
    "Vec3#3",
    c_modifier_public | c_modifier_final,
    bic_vec3_method_Vec3_3
  },
  { "x#0", c_modifier_public | c_modifier_final, bic_vec3_method_x_0 },
  { "r#0", c_modifier_public | c_modifier_final, bic_vec3_method_x_0 },
  { "s#0", c_modifier_public | c_modifier_final, bic_vec3_method_x_0 },
  { "y#0", c_modifier_public | c_modifier_final, bic_vec3_method_y_0 },
  { "g#0", c_modifier_public | c_modifier_final, bic_vec3_method_y_0 },
  { "t#0", c_modifier_public | c_modifier_final, bic_vec3_method_y_0 },
  { "z#0", c_modifier_public | c_modifier_final, bic_vec3_method_z_0 },
  { "b#0", c_modifier_public | c_modifier_final, bic_vec3_method_z_0 },
  { "p#0", c_modifier_public | c_modifier_final, bic_vec3_method_z_0 },
  {
    "data#0",
    c_modifier_public | c_modifier_final,
    bic_vec3_method_data_0
  },
  {
    "dot#1",
    c_modifier_public | c_modifier_final,
    bic_vec3_method_dot_1
  },
  {
    "cross#1",
    c_modifier_public | c_modifier_final,
    bic_vec3_method_cross_1
  },
  {
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_vec3_method_length_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_vec3_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_vec3_method_print_0
  },
};/*}}}*/

built_in_variable_s vec3_variables[] =
{/*{{{*/
};/*}}}*/

void bic_vec3_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_vec3_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  glm::vec3 *v3_ptr = new glm::vec3();

  location_ptr->v_data_ptr = (glm::vec3 *)v3_ptr;
}/*}}}*/

void bic_vec3_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  glm::vec3 *v3_ptr = (glm::vec3 *)location_ptr->v_data_ptr;

  delete v3_ptr;
}/*}}}*/

bool bic_vec3_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack)
{/*{{{*/
  glm::vec3 &v3 = *((glm::vec3 *)location_ptr->v_data_ptr);

  stream.append(sizeof(float),(const char *)&v3.x);
  stream.append(sizeof(float),(const char *)&v3.y);
  stream.append(sizeof(float),(const char *)&v3.z);

  return true;
}/*}}}*/

bool bic_vec3_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos)
{/*{{{*/
  glm::vec3 *v3_ptr = new glm::vec3();

  location_ptr->v_data_ptr = (glm::vec3 *)v3_ptr;

  if (stream.used < 3*sizeof(float))
  {
    return false;
  }

  stream.from_end(sizeof(float),(char *)&v3_ptr->z,order_bytes);
  stream.from_end(sizeof(float),(char *)&v3_ptr->y,order_bytes);
  stream.from_end(sizeof(float),(char *)&v3_ptr->x,order_bytes);

  return true;
}/*}}}*/

bool bic_vec3_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_vec3_operator_binary_plus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_VEC_BINARY_EQUAL_OPS_FLOAT_VEC(vec3,+,"operator_binary_plus_equal#1")
}/*}}}*/

bool bic_vec3_operator_binary_minus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_VEC_BINARY_EQUAL_OPS_FLOAT_VEC(vec3,-,"operator_binary_minus_equal#1")
}/*}}}*/

bool bic_vec3_operator_binary_asterisk_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_VEC_BINARY_EQUAL_OPS_FLOAT_VEC(vec3,*,"operator_binary_asterisk_equal#1")
}/*}}}*/

bool bic_vec3_operator_binary_slash_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_VEC_BINARY_EQUAL_OPS_FLOAT_VEC(vec3,/,"operator_binary_slash_equal#1")
}/*}}}*/

bool bic_vec3_operator_binary_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_VEC_BINARY_OPS_FLOAT_VEC(vec3,+,"operator_binary_plus#1");
}/*}}}*/

bool bic_vec3_operator_binary_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_VEC_BINARY_OPS_FLOAT_VEC(vec3,-,"operator_binary_minus#1");
}/*}}}*/

bool bic_vec3_operator_binary_asterisk(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_VEC_BINARY_OPS_FLOAT_VEC(vec3,*,"operator_binary_asterisk#1");
}/*}}}*/

bool bic_vec3_operator_binary_slash(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_VEC_BINARY_OPS_FLOAT_VEC(vec3,/,"operator_binary_slash#1");
}/*}}}*/

bool bic_vec3_method_Vec3_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  return true;
}/*}}}*/

bool bic_vec3_method_Vec3_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_array)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Vec3#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  glm::vec3 &v3 = *((glm::vec3 *)dst_location->v_data_ptr);

  MATH_RETRIEVE_FLOAT_FROM_ARRAY(src_0_location,glm::value_ptr(v3),3);

  return true;
}/*}}}*/

bool bic_vec3_method_Vec3_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);

  glm::vec3 &v3 = *((glm::vec3 *)dst_location->v_data_ptr);

  bool type_error = false;
  float *float_ptr = glm::value_ptr(v3);

  MATH_RETRIEVE_FLOAT(src_0_location);
  MATH_RETRIEVE_FLOAT(src_1_location);
  MATH_RETRIEVE_FLOAT(src_2_location);

  // - ERROR -
  if (type_error)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Vec3#3");
    new_exception->params.push(3);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);

    return false;
  }

  return true;
}/*}}}*/

bool bic_vec3_method_x_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  MATH_VEC_RETRIEVE_ELEMENT(vec3,x);
}/*}}}*/

bool bic_vec3_method_y_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  MATH_VEC_RETRIEVE_ELEMENT(vec3,y);
}/*}}}*/

bool bic_vec3_method_z_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  MATH_VEC_RETRIEVE_ELEMENT(vec3,z);
}/*}}}*/

bool bic_vec3_method_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  glm::vec3 *v3_ptr = (glm::vec3 *)dst_location->v_data_ptr;

  pointer_array_s *array_ptr = it.get_new_array_ptr();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  MATH_RETRIEVE_ARRAY_FROM_FLOAT(&v3_ptr->x,3,array_ptr);

  return true;
}/*}}}*/

bool bic_vec3_method_dot_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_VEC_BINARY_FUNCTION_OPS_VEC(vec3,dot,"dot#1");
}/*}}}*/

bool bic_vec3_method_cross_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_vec3)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("cross#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  glm::vec3 &vec_dst = *((glm::vec3 *)dst_location->v_data_ptr);
  glm::vec3 &vec_src = *((glm::vec3 *)src_0_location->v_data_ptr);

  // - compute vectors cross product -
  glm::vec3 *vec_res_ptr = new glm::vec3(glm::cross(vec_dst,vec_src));

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_vec3,vec_res_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_vec3_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_VEC_UNARY_FUNCTION(vec3,length,"length#0");
}/*}}}*/

bool bic_vec3_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING(
    glm::vec3 &v3 = *((glm::vec3 *)dst_location->v_data_ptr);

    string_ptr->setf("[%f,%f,%f]",v3.x,v3.y,v3.z);
  );

  return true;
}/*}}}*/

bool bic_vec3_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  glm::vec3 &v3 = *((glm::vec3 *)dst_location->v_data_ptr);

  printf("[%f,%f,%f]",v3.x,v3.y,v3.z);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

// - class VEC4 -
built_in_class_s vec4_class =
{/*{{{*/
  "Vec4",
  c_modifier_public | c_modifier_final,
  29, vec4_methods,
  0, vec4_variables,
  bic_vec4_consts,
  bic_vec4_init,
  bic_vec4_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  bic_vec4_pack,
  bic_vec4_unpack,
  NULL,
  NULL
};/*}}}*/

built_in_method_s vec4_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_vec4_operator_binary_equal
  },
  {
    "operator_binary_plus_equal#1",
    c_modifier_public | c_modifier_final,
    bic_vec4_operator_binary_plus_equal
  },
  {
    "operator_binary_minus_equal#1",
    c_modifier_public | c_modifier_final,
    bic_vec4_operator_binary_minus_equal
  },
  {
    "operator_binary_asterisk_equal#1",
    c_modifier_public | c_modifier_final,
    bic_vec4_operator_binary_asterisk_equal
  },
  {
    "operator_binary_slash_equal#1",
    c_modifier_public | c_modifier_final,
    bic_vec4_operator_binary_slash_equal
  },
  {
    "operator_binary_plus#1",
    c_modifier_public | c_modifier_final,
    bic_vec4_operator_binary_plus
  },
  {
    "operator_binary_minus#1",
    c_modifier_public | c_modifier_final,
    bic_vec4_operator_binary_minus
  },
  {
    "operator_binary_asterisk#1",
    c_modifier_public | c_modifier_final,
    bic_vec4_operator_binary_asterisk
  },
  {
    "operator_binary_slash#1",
    c_modifier_public | c_modifier_final,
    bic_vec4_operator_binary_slash
  },
  {
    "Vec4#0",
    c_modifier_public | c_modifier_final,
    bic_vec4_method_Vec4_0
  },
  {
    "Vec4#1",
    c_modifier_public | c_modifier_final,
    bic_vec4_method_Vec4_1
  },
  {
    "Vec4#4",
    c_modifier_public | c_modifier_final,
    bic_vec4_method_Vec4_4
  },
  { "x#0", c_modifier_public | c_modifier_final, bic_vec4_method_x_0 },
  { "r#0", c_modifier_public | c_modifier_final, bic_vec4_method_x_0 },
  { "s#0", c_modifier_public | c_modifier_final, bic_vec4_method_x_0 },
  { "y#0", c_modifier_public | c_modifier_final, bic_vec4_method_y_0 },
  { "g#0", c_modifier_public | c_modifier_final, bic_vec4_method_y_0 },
  { "t#0", c_modifier_public | c_modifier_final, bic_vec4_method_y_0 },
  { "z#0", c_modifier_public | c_modifier_final, bic_vec4_method_z_0 },
  { "b#0", c_modifier_public | c_modifier_final, bic_vec4_method_z_0 },
  { "p#0", c_modifier_public | c_modifier_final, bic_vec4_method_z_0 },
  { "w#0", c_modifier_public | c_modifier_final, bic_vec4_method_w_0 },
  { "a#0", c_modifier_public | c_modifier_final, bic_vec4_method_w_0 },
  { "q#0", c_modifier_public | c_modifier_final, bic_vec4_method_w_0 },
  {
    "data#0",
    c_modifier_public | c_modifier_final,
    bic_vec4_method_data_0
  },
  {
    "dot#1",
    c_modifier_public | c_modifier_final,
    bic_vec4_method_dot_1
  },
  {
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_vec4_method_length_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_vec4_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_vec4_method_print_0
  },
};/*}}}*/

built_in_variable_s vec4_variables[] =
{/*{{{*/
};/*}}}*/

void bic_vec4_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_vec4_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  glm::vec4 *v4_ptr = new glm::vec4();

  location_ptr->v_data_ptr = (glm::vec4 *)v4_ptr;
}/*}}}*/

void bic_vec4_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  glm::vec4 *v4_ptr = (glm::vec4 *)location_ptr->v_data_ptr;

  delete v4_ptr;
}/*}}}*/

bool bic_vec4_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack)
{/*{{{*/
  glm::vec4 &v4 = *((glm::vec4 *)location_ptr->v_data_ptr);

  stream.append(sizeof(float),(const char *)&v4.x);
  stream.append(sizeof(float),(const char *)&v4.y);
  stream.append(sizeof(float),(const char *)&v4.z);
  stream.append(sizeof(float),(const char *)&v4.w);

  return true;
}/*}}}*/

bool bic_vec4_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos)
{/*{{{*/
  glm::vec4 *v4_ptr = new glm::vec4();

  location_ptr->v_data_ptr = (glm::vec4 *)v4_ptr;

  if (stream.used < 4*sizeof(float))
  {
    return false;
  }

  stream.from_end(sizeof(float),(char *)&v4_ptr->w,order_bytes);
  stream.from_end(sizeof(float),(char *)&v4_ptr->z,order_bytes);
  stream.from_end(sizeof(float),(char *)&v4_ptr->y,order_bytes);
  stream.from_end(sizeof(float),(char *)&v4_ptr->x,order_bytes);

  return true;
}/*}}}*/

bool bic_vec4_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_vec4_operator_binary_plus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_VEC_BINARY_EQUAL_OPS_FLOAT_VEC(vec4,+,"operator_binary_plus_equal#1")
}/*}}}*/

bool bic_vec4_operator_binary_minus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_VEC_BINARY_EQUAL_OPS_FLOAT_VEC(vec4,-,"operator_binary_minus_equal#1")
}/*}}}*/

bool bic_vec4_operator_binary_asterisk_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_VEC_BINARY_EQUAL_OPS_FLOAT_VEC(vec4,*,"operator_binary_asterisk_equal#1")
}/*}}}*/

bool bic_vec4_operator_binary_slash_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_VEC_BINARY_EQUAL_OPS_FLOAT_VEC(vec4,/,"operator_binary_slash_equal#1")
}/*}}}*/

bool bic_vec4_operator_binary_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_VEC_BINARY_OPS_FLOAT_VEC(vec4,+,"operator_binary_plus#1");
}/*}}}*/

bool bic_vec4_operator_binary_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_VEC_BINARY_OPS_FLOAT_VEC(vec4,-,"operator_binary_minus#1");
}/*}}}*/

bool bic_vec4_operator_binary_asterisk(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_VEC_BINARY_OPS_FLOAT_VEC(vec4,*,"operator_binary_asterisk#1");
}/*}}}*/

bool bic_vec4_operator_binary_slash(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_VEC_BINARY_OPS_FLOAT_VEC(vec4,/,"operator_binary_slash#1");
}/*}}}*/

bool bic_vec4_method_Vec4_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  return true;
}/*}}}*/

bool bic_vec4_method_Vec4_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_array)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Vec4#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  glm::vec4 &v4 = *((glm::vec4 *)dst_location->v_data_ptr);

  MATH_RETRIEVE_FLOAT_FROM_ARRAY(src_0_location,glm::value_ptr(v4),4);

  return true;
}/*}}}*/

bool bic_vec4_method_Vec4_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);
  location_s *src_3_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_3_op_idx]);

  glm::vec4 &v4 = *((glm::vec4 *)dst_location->v_data_ptr);

  bool type_error = false;
  float *float_ptr = glm::value_ptr(v4);

  MATH_RETRIEVE_FLOAT(src_0_location);
  MATH_RETRIEVE_FLOAT(src_1_location);
  MATH_RETRIEVE_FLOAT(src_2_location);
  MATH_RETRIEVE_FLOAT(src_3_location);

  // - ERROR -
  if (type_error)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Vec4#4");
    new_exception->params.push(4);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);
    new_exception->params.push(src_3_location->v_type);

    return false;
  }

  return true;
}/*}}}*/

bool bic_vec4_method_x_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  MATH_VEC_RETRIEVE_ELEMENT(vec4,x);
}/*}}}*/

bool bic_vec4_method_y_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  MATH_VEC_RETRIEVE_ELEMENT(vec4,y);
}/*}}}*/

bool bic_vec4_method_z_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  MATH_VEC_RETRIEVE_ELEMENT(vec4,z);
}/*}}}*/

bool bic_vec4_method_w_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  MATH_VEC_RETRIEVE_ELEMENT(vec4,w);
}/*}}}*/

bool bic_vec4_method_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  glm::vec4 *v4_ptr = (glm::vec4 *)dst_location->v_data_ptr;

  pointer_array_s *array_ptr = it.get_new_array_ptr();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  MATH_RETRIEVE_ARRAY_FROM_FLOAT(&v4_ptr->x,4,array_ptr);

  return true;
}/*}}}*/

bool bic_vec4_method_dot_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_VEC_BINARY_FUNCTION_OPS_VEC(vec4,dot,"dot#1");
}/*}}}*/

bool bic_vec4_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_VEC_UNARY_FUNCTION(vec4,length,"length#0");
}/*}}}*/

bool bic_vec4_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING(
    glm::vec4 &v4 = *((glm::vec4 *)dst_location->v_data_ptr);

    string_ptr->setf("[%f,%f,%f,%f]",v4.x,v4.y,v4.z,v4.w);
  );

  return true;
}/*}}}*/

bool bic_vec4_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  glm::vec4 &v4 = *((glm::vec4 *)dst_location->v_data_ptr);

  printf("[%f,%f,%f,%f]",v4.x,v4.y,v4.z,v4.w);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

// - class MAT4 -
built_in_class_s mat4_class =
{/*{{{*/
  "Mat4",
  c_modifier_public | c_modifier_final,
  24, mat4_methods,
  0, mat4_variables,
  bic_mat4_consts,
  bic_mat4_init,
  bic_mat4_clear,
  NULL,
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

built_in_method_s mat4_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_mat4_operator_binary_equal
  },
  {
    "operator_binary_plus_equal#1",
    c_modifier_public | c_modifier_final,
    bic_mat4_operator_binary_plus_equal
  },
  {
    "operator_binary_minus_equal#1",
    c_modifier_public | c_modifier_final,
    bic_mat4_operator_binary_minus_equal
  },
  {
    "operator_binary_asterisk_equal#1",
    c_modifier_public | c_modifier_final,
    bic_mat4_operator_binary_asterisk_equal
  },
  {
    "operator_binary_slash_equal#1",
    c_modifier_public | c_modifier_final,
    bic_mat4_operator_binary_slash_equal
  },
  {
    "operator_binary_plus#1",
    c_modifier_public | c_modifier_final,
    bic_mat4_operator_binary_plus
  },
  {
    "operator_binary_minus#1",
    c_modifier_public | c_modifier_final,
    bic_mat4_operator_binary_minus
  },
  {
    "operator_binary_asterisk#1",
    c_modifier_public | c_modifier_final,
    bic_mat4_operator_binary_asterisk
  },
  {
    "operator_binary_slash#1",
    c_modifier_public | c_modifier_final,
    bic_mat4_operator_binary_slash
  },
  {
    "Mat4#0",
    c_modifier_public | c_modifier_final,
    bic_mat4_method_Mat4_0
  },
  {
    "Mat4#1",
    c_modifier_public | c_modifier_final,
    bic_mat4_method_Mat4_1
  },
  {
    "data#0",
    c_modifier_public | c_modifier_final,
    bic_mat4_method_data_0
  },
  {
    "row#1",
    c_modifier_public | c_modifier_final,
    bic_mat4_method_row_1
  },
  {
    "col#1",
    c_modifier_public | c_modifier_final,
    bic_mat4_method_col_1
  },
  {
    "translate#1",
    c_modifier_public | c_modifier_final,
    bic_mat4_method_translate_1
  },
  {
    "rotate#2",
    c_modifier_public | c_modifier_final,
    bic_mat4_method_rotate_2
  },
  {
    "scale#1",
    c_modifier_public | c_modifier_final,
    bic_mat4_method_scale_1
  },
  {
    "ortho#6",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_mat4_method_ortho_6
  },
  {
    "perspective#4",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_mat4_method_perspective_4
  },
  {
    "perspective#5",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_mat4_method_perspective_5
  },
  {
    "look_at#3",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_mat4_method_look_at_3
  },
  {
    "nice_string#0",
    c_modifier_public | c_modifier_final,
    bic_mat4_method_nice_string_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_mat4_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_mat4_method_print_0
  },
};/*}}}*/

built_in_variable_s mat4_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_MAT4_BINARY_EQUAL_OPS_FLOAT_MAT4(OPERATOR,NAME) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
  glm::mat4 &m4_dst = *((glm::mat4 *)((location_s *)dst_location)->v_data_ptr);\
  glm::mat4 *m4_res_ptr;\
\
  double scalar;\
  if (it.retrieve_float(src_0_location,scalar))\
  {\
    m4_res_ptr = new glm::mat4(m4_dst OPERATOR (float)scalar);\
  }\
  else if (src_0_location->v_type == c_bi_class_mat4)\
  {\
    glm::mat4 &m4_src = *((glm::mat4 *)src_0_location->v_data_ptr);\
    m4_res_ptr = new glm::mat4(m4_dst OPERATOR m4_src);\
  }\
  \
  /* - ERROR - */\
  else\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
    new_exception->params.push(1);\
    new_exception->params.push(src_0_location->v_type);\
\
    return false;\
  }\
\
  BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_mat4,m4_res_ptr,2);\
\
  BIC_SET_DESTINATION(new_location);\
  BIC_SET_RESULT(new_location);\
\
  return true;\
}/*}}}*/

#define BIC_MAT4_BINARY_OPS_FLOAT_MAT4(OPERATOR,NAME) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
  glm::mat4 &m4_dst = *((glm::mat4 *)dst_location->v_data_ptr);\
  glm::mat4 *m4_res_ptr;\
\
  double scalar;\
  if (it.retrieve_float(src_0_location,scalar))\
  {\
    m4_res_ptr = new glm::mat4(m4_dst OPERATOR (float)scalar);\
  }\
  else if (src_0_location->v_type == c_bi_class_mat4)\
  {\
    glm::mat4 &m4_src = *((glm::mat4 *)src_0_location->v_data_ptr);\
    m4_res_ptr = new glm::mat4(m4_dst OPERATOR m4_src);\
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
\
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mat4,m4_res_ptr);\
  BIC_SET_RESULT(new_location);\
\
  return true;\
}/*}}}*/

void bic_mat4_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_mat4_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  glm::mat4 *m4_ptr = new glm::mat4();

  location_ptr->v_data_ptr = (glm::mat4 *)m4_ptr;
}/*}}}*/

void bic_mat4_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  glm::mat4 *m4_ptr = (glm::mat4 *)location_ptr->v_data_ptr;

  delete m4_ptr;
}/*}}}*/

bool bic_mat4_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_mat4_operator_binary_plus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_MAT4_BINARY_EQUAL_OPS_FLOAT_MAT4(+,"operator_binary_plus_equal#1");
}/*}}}*/

bool bic_mat4_operator_binary_minus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_MAT4_BINARY_EQUAL_OPS_FLOAT_MAT4(-,"operator_binary_minus_equal#1");
}/*}}}*/

bool bic_mat4_operator_binary_asterisk_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_MAT4_BINARY_EQUAL_OPS_FLOAT_MAT4(*,"operator_binary_asterisk_equal#1");
}/*}}}*/

bool bic_mat4_operator_binary_slash_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_MAT4_BINARY_EQUAL_OPS_FLOAT_MAT4(/,"operator_binary_slash_equal#1");
}/*}}}*/

bool bic_mat4_operator_binary_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_MAT4_BINARY_OPS_FLOAT_MAT4(+,"operator_binary_plus#1");
}/*}}}*/

bool bic_mat4_operator_binary_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_MAT4_BINARY_OPS_FLOAT_MAT4(-,"operator_binary_minus#1");
}/*}}}*/

bool bic_mat4_operator_binary_asterisk(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  glm::mat4 &m4_dst = *((glm::mat4 *)dst_location->v_data_ptr);

  double scalar;
  if (it.retrieve_float(src_0_location,scalar))
  {
    glm::mat4 *m4_res_ptr = new glm::mat4(m4_dst * (float)scalar);

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mat4,m4_res_ptr);
    BIC_SET_RESULT(new_location);
  }
  else if (src_0_location->v_type == c_bi_class_vec2)
  {
    glm::vec2 &v2_src = *((glm::vec2 *)src_0_location->v_data_ptr);
    glm::vec2 *v2_res_ptr = new glm::vec2(m4_dst * glm::vec4(v2_src,0.0f,1.0f));

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_vec2,v2_res_ptr);
    BIC_SET_RESULT(new_location);
  }
  else if (src_0_location->v_type == c_bi_class_vec3)
  {
    glm::vec3 &v3_src = *((glm::vec3 *)src_0_location->v_data_ptr);
    glm::vec3 *v3_res_ptr = new glm::vec3(m4_dst * glm::vec4(v3_src,1.0f));

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_vec3,v3_res_ptr);
    BIC_SET_RESULT(new_location);
  }
  else if (src_0_location->v_type == c_bi_class_vec4)
  {
    glm::vec4 &v4_src = *((glm::vec4 *)src_0_location->v_data_ptr);
    glm::vec4 *v4_res_ptr = new glm::vec4(m4_dst * v4_src);

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_vec4,v4_res_ptr);
    BIC_SET_RESULT(new_location);
  }
  else if (src_0_location->v_type == c_bi_class_mat4)
  {
    glm::mat4 &m4_src = *((glm::mat4 *)src_0_location->v_data_ptr);
    glm::mat4 *m4_res_ptr = new glm::mat4(m4_dst * m4_src);

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mat4,m4_res_ptr);
    BIC_SET_RESULT(new_location);
  }

  // - ERROR -
  else
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_asterisk#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  return true;
}/*}}}*/

bool bic_mat4_operator_binary_slash(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_MAT4_BINARY_OPS_FLOAT_MAT4(/,"operator_binary_slash#1");
}/*}}}*/

bool bic_mat4_method_Mat4_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  return true;
}/*}}}*/

bool bic_mat4_method_Mat4_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_array)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Mat4#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  glm::mat4 &m4 = *((glm::mat4 *)dst_location->v_data_ptr);

  MATH_RETRIEVE_FLOAT_FROM_ARRAY(src_0_location,glm::value_ptr(m4),16);

  return true;
}/*}}}*/

bool bic_mat4_method_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  glm::mat4 &m4 = *((glm::mat4 *)dst_location->v_data_ptr);

  pointer_array_s *array_ptr = it.get_new_array_ptr();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  MATH_RETRIEVE_ARRAY_FROM_FLOAT(glm::value_ptr(m4),16,array_ptr);

  return true;
}/*}}}*/

bool bic_mat4_method_row_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int index;

  if (!it.retrieve_integer(src_0_location,index))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("row#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - ERROR -
  if (index < 0 || index >= 4)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_MAT4_INDEX_EXCEEDS_ROW_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(index);

    return false;
  }

  glm::mat4 &m4 = *((glm::mat4 *)dst_location->v_data_ptr);

  pointer_array_s *array_ptr = it.get_new_array_ptr();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  MATH_RETRIEVE_ARRAY_FROM_FLOAT(&m4[index].x,4,array_ptr);

  return true;
}/*}}}*/

bool bic_mat4_method_col_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int index;

  if (!it.retrieve_integer(src_0_location,index))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("col#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - ERROR -
  if (index < 0 || index >= 4)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_MAT4_INDEX_EXCEEDS_COLUMN_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(index);

    return false;
  }

  glm::mat4 &m4 = *((glm::mat4 *)dst_location->v_data_ptr);

  pointer_array_s *array_ptr = it.get_new_array_ptr();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  MATH_RETRIEVE_ARRAY_FROM_FLOAT_STEP(glm::value_ptr(m4) + index,16,4,array_ptr);

  return true;
}/*}}}*/

bool bic_mat4_method_translate_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_vec3)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("translate#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  glm::mat4 &m4 = *((glm::mat4 *)dst_location->v_data_ptr);
  glm::vec3 &v3 = *((glm::vec3 *)src_0_location->v_data_ptr);

  glm::mat4 *trg_m4_ptr = new glm::mat4(glm::translate(m4,v3));

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mat4,trg_m4_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_mat4_method_rotate_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  double angle;

  if (!it.retrieve_float(src_0_location,angle) ||
      src_1_location->v_type != c_bi_class_vec3)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("rotate#1");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  glm::mat4 &m4 = *((glm::mat4 *)dst_location->v_data_ptr);
  glm::vec3 &axis = *((glm::vec3 *)src_1_location->v_data_ptr);

  glm::mat4 *trg_m4_ptr = new glm::mat4(glm::rotate(m4,(float)angle,axis));

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mat4,trg_m4_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_mat4_method_scale_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_vec3)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("scale#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  glm::mat4 &m4 = *((glm::mat4 *)dst_location->v_data_ptr);
  glm::vec3 &v3 = *((glm::vec3 *)src_0_location->v_data_ptr);

  glm::mat4 *trg_m4_ptr = new glm::mat4(glm::scale(m4,v3));

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mat4,trg_m4_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_mat4_method_ortho_6(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);
  location_s *src_3_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_3_op_idx]);
  location_s *src_4_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_4_op_idx]);
  location_s *src_5_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_5_op_idx]);

  double doubles[6];

  if (!it.retrieve_float(src_0_location,doubles[0]) || // left
      !it.retrieve_float(src_1_location,doubles[1]) || // right
      !it.retrieve_float(src_2_location,doubles[2]) || // bottom
      !it.retrieve_float(src_3_location,doubles[3]) || // top
      !it.retrieve_float(src_4_location,doubles[4]) || // zNear
      !it.retrieve_float(src_5_location,doubles[5]))   // zFar
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_mat4,"ortho#6");
    new_exception->params.push(6);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);
    new_exception->params.push(src_3_location->v_type);
    new_exception->params.push(src_4_location->v_type);
    new_exception->params.push(src_5_location->v_type);

    return false;
  }

  glm::mat4 *trg_m4_ptr = new glm::mat4(glm::ortho(
                                          doubles[0],doubles[1],doubles[2],doubles[3],doubles[4],doubles[5]));

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mat4,trg_m4_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_mat4_method_perspective_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);
  location_s *src_3_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_3_op_idx]);

  double doubles[4];

  if (!it.retrieve_float(src_0_location,doubles[0]) || // fovy
      !it.retrieve_float(src_1_location,doubles[1]) || // aspect
      !it.retrieve_float(src_2_location,doubles[2]) || // zNear
      !it.retrieve_float(src_3_location,doubles[3]))   // zFar
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_mat4,"perspective#4");
    new_exception->params.push(4);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);
    new_exception->params.push(src_3_location->v_type);

    return false;
  }

  glm::mat4 *trg_m4_ptr = new glm::mat4(glm::perspective(
                                          doubles[0],doubles[1],doubles[2],doubles[3]));

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mat4,trg_m4_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_mat4_method_perspective_5(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);
  location_s *src_3_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_3_op_idx]);
  location_s *src_4_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_4_op_idx]);

  double doubles[5];

  if (!it.retrieve_float(src_0_location,doubles[0]) || // fov
      !it.retrieve_float(src_1_location,doubles[1]) || // width
      !it.retrieve_float(src_2_location,doubles[2]) || // height
      !it.retrieve_float(src_3_location,doubles[3]) || // zNear
      !it.retrieve_float(src_4_location,doubles[4]))   // zFar
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_mat4,"perspective#5");
    new_exception->params.push(5);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);
    new_exception->params.push(src_3_location->v_type);
    new_exception->params.push(src_4_location->v_type);

    return false;
  }

  glm::mat4 *trg_m4_ptr = new glm::mat4(glm::perspectiveFov(
                                          doubles[0],doubles[1],doubles[2],doubles[3],doubles[4]));

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mat4,trg_m4_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_mat4_method_look_at_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);

  if (src_0_location->v_type != c_bi_class_vec3 || // eye
      src_1_location->v_type != c_bi_class_vec3 || // center
      src_2_location->v_type != c_bi_class_vec3)   // up
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_mat4,"look_at#3");
    new_exception->params.push(3);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);

    return false;
  }

  glm::vec3 &v3_eye = *((glm::vec3 *)src_0_location->v_data_ptr);
  glm::vec3 &v3_center = *((glm::vec3 *)src_1_location->v_data_ptr);
  glm::vec3 &v3_up = *((glm::vec3 *)src_2_location->v_data_ptr);

  glm::mat4 *trg_m4_ptr = new glm::mat4(glm::lookAt(v3_eye,v3_center,v3_up));

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mat4,trg_m4_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_mat4_method_nice_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING(
    glm::mat4 &m4 = *((glm::mat4 *)dst_location->v_data_ptr);

    string_ptr->setf(
      "|%10.3f,%10.3f,%10.3f,%10.3f|\n"
      "|%10.3f,%10.3f,%10.3f,%10.3f|\n"
      "|%10.3f,%10.3f,%10.3f,%10.3f|\n"
      "|%10.3f,%10.3f,%10.3f,%10.3f|\n",
      m4[0].x,m4[0].y,m4[0].z,m4[0].w,
      m4[1].x,m4[1].y,m4[1].z,m4[1].w,
      m4[2].x,m4[2].y,m4[2].z,m4[2].w,
      m4[3].x,m4[3].y,m4[3].z,m4[3].w);
  );

  return true;
}/*}}}*/

bool bic_mat4_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING(
    glm::mat4 &m4 = *((glm::mat4 *)dst_location->v_data_ptr);

    string_ptr->setf("["
                     "%f,%f,%f,%f;"
                     "%f,%f,%f,%f;"
                     "%f,%f,%f,%f;"
                     "%f,%f,%f,%f]",
                     m4[0].x,m4[0].y,m4[0].z,m4[0].w,
                     m4[1].x,m4[1].y,m4[1].z,m4[1].w,
                     m4[2].x,m4[2].y,m4[2].z,m4[2].w,
                     m4[3].x,m4[3].y,m4[3].z,m4[3].w);
  );

  return true;
}/*}}}*/

bool bic_mat4_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  glm::mat4 &m4 = *((glm::mat4 *)dst_location->v_data_ptr);

  printf("["
         "%f,%f,%f,%f;"
         "%f,%f,%f,%f;"
         "%f,%f,%f,%f;"
         "%f,%f,%f,%f]",
         m4[0].x,m4[0].y,m4[0].z,m4[0].w,
         m4[1].x,m4[1].y,m4[1].z,m4[1].w,
         m4[2].x,m4[2].y,m4[2].z,m4[2].w,
         m4[3].x,m4[3].y,m4[3].z,m4[3].w);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

// - class PRIMES -
built_in_class_s primes_class =
{/*{{{*/
  "Primes",
  c_modifier_public | c_modifier_final,
  8, primes_methods,
  0, primes_variables,
  bic_primes_consts,
  bic_primes_init,
  bic_primes_clear,
  NULL,
  NULL,
  bic_primes_item,
  bic_primes_first_idx,
  bic_primes_next_idx,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s primes_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_primes_operator_binary_equal
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_primes_operator_binary_le_br_re_br
  },
  {
    "Primes#1",
    c_modifier_public | c_modifier_final,
    bic_primes_method_Primes_1
  },
  {
    "prime_factors#1",
    c_modifier_public | c_modifier_final,
    bic_primes_method_prime_factors_1
  },
  {
    "item#1",
    c_modifier_public | c_modifier_final,
    bic_primes_method_item_1
  },
  {
    "first_idx#0",
    c_modifier_public | c_modifier_final,
    bic_primes_method_first_idx_0
  },
  {
    "next_idx#1",
    c_modifier_public | c_modifier_final,
    bic_primes_method_next_idx_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_primes_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_primes_method_print_0
  },
};/*}}}*/

built_in_variable_s primes_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_PRIMES_ITEM(NAME) \
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
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
      \
      return false;\
    }\
    \
    primes_s *primes_ptr = (primes_s *)dst_location->v_data_ptr;\
    \
    /* - retrieve next index - */\
    long long int prime = primes_ptr->get_prime(index);\
    \
    /* - ERROR - */\
    if (prime == c_idx_not_exist)\
    {\
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PRIMES_INDEX_DOES_NOT_REFER_TO_VALID_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      new_exception->params.push(index);\
      \
      return false;\
    }\
    \
    BIC_SIMPLE_SET_RES(c_bi_class_integer,prime);\
    \
    return true;\
  }/*}}}*/

void bic_primes_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_primes_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  primes_s *primes_ptr = (primes_s *)cmalloc(sizeof(primes_s));
  primes_ptr->init();

  location_ptr->v_data_ptr = (primes_s *)primes_ptr;
}/*}}}*/

void bic_primes_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  primes_s *primes_ptr = (primes_s *)location_ptr->v_data_ptr;

  primes_ptr->clear();
  cfree(primes_ptr);
}/*}}}*/

location_s *bic_primes_item(interpreter_thread_s &it,location_s *location_ptr,unsigned index)
{/*{{{*/
  primes_s *primes_ptr = (primes_s *)location_ptr->v_data_ptr;

  long long int prime = primes_ptr->get_prime(index);

  // FIXME TODO check index ...
  cassert(prime != c_idx_not_exist);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,prime);

  return new_location;
}/*}}}*/

unsigned bic_primes_first_idx(location_s *location_ptr)
{/*{{{*/
  primes_s *primes_ptr = (primes_s *)location_ptr->v_data_ptr;
  return primes_ptr->sieve.used != 0 ? 0 : c_idx_not_exist;
}/*}}}*/

unsigned bic_primes_next_idx(location_s *location_ptr,unsigned index)
{/*{{{*/
  primes_s *primes_ptr = (primes_s *)location_ptr->v_data_ptr;
  return primes_ptr->next_idx(index);
}/*}}}*/

bool bic_primes_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_primes_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_PRIMES_ITEM("operator_binary_le_br_re_br#1");
}/*}}}*/

bool bic_primes_method_Primes_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  primes_s *primes_ptr = (primes_s *)dst_location->v_data_ptr;

  long long int size;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,size))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Primes#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - ERROR -
  if (size < 0)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PRIMES_SIEVE_SIZE_NEGATIVE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(size);

    return false;
  }

  // - ERROR -
  if (size >= (UINT_MAX - 1))
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PRIMES_SIEVE_SIZE_TOO_BIG,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(size);

    return false;
  }

  primes_ptr->create_sieve(size);

  return true;
}/*}}}*/

bool bic_primes_method_prime_factors_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int number;

  /* - ERROR - */
  if (!it.retrieve_integer(src_0_location,number))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("item#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  primes_s *primes_ptr = (primes_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (number <= 0)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PRIMES_PRIME_FACTORS_NUMBER_LESS_THAN_ONE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(number);

    return false;
  }

  // - create target array and its location -
  pointer_array_s *array_ptr = it.get_new_array_ptr();
  BIC_CREATE_NEW_LOCATION(array_location,c_bi_class_array,array_ptr);

  unsigned prime_idx = 0;
  do
  {
    // - retrieve next prime -
    long long int prime = primes_ptr->get_prime(prime_idx);

    if (prime*prime > number)
    {
      break;
    }

    while (number % prime == 0)
    {
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,prime);
      array_ptr->push(new_location);

      number /= prime;
    }

    // - retrieve next prime index -
    prime_idx = primes_ptr->next_idx(prime_idx);

    // - ERROR -
    if (prime_idx == c_idx_not_exist)
    {
      it.release_location_ptr(array_location);

      exception_s::throw_exception(it,module.error_base + c_error_PRIMES_SIEVE_SIZE_NOT_ENOUGH,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

  }
  while(true);

  if (number > 1)
  {
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,number);
    array_ptr->push(new_location);
  }

  BIC_SET_RESULT(array_location);

  return true;
}/*}}}*/

bool bic_primes_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_PRIMES_ITEM("item#1");
}/*}}}*/

bool bic_primes_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  primes_s *primes_ptr = (primes_s *)dst_location->v_data_ptr;

  if (primes_ptr->sieve.used > 0)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,0);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_primes_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
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

  primes_s *primes_ptr = (primes_s *)dst_location->v_data_ptr;

  // - retrieve next index -
  long long int next_index = primes_ptr->next_idx(index);

  if (next_index != c_idx_not_exist)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,next_index);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_primes_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Primes"),"Primes");
  );

  return true;
}/*}}}*/

bool bic_primes_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("Primes");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

