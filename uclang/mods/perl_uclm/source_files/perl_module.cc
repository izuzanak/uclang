
@begin
include "perl_module.h"
@end

// - PERL indexes of built in classes -
unsigned c_bi_class_perl_interpreter = c_idx_not_exist;
unsigned c_bi_class_perl_value = c_idx_not_exist;

// - PERL indexes of remote classes -
unsigned c_rm_class_dict = c_idx_not_exist;

// - PERL module -
built_in_module_s module =
{/*{{{*/
  2,                     // Class count
  perl_classes,          // Classes

  0,                     // Error base index
  5,                     // Error count
  perl_error_strings,    // Error strings

  perl_initialize,       // Initialize function
  perl_print_exception,  // Print exceptions function
};/*}}}*/

// - PERL classes -
built_in_class_s *perl_classes[] =
{/*{{{*/
  &perl_interpreter_class,
  &perl_value_class,
};/*}}}*/

// - PERL error strings -
const char *perl_error_strings[] =
{/*{{{*/
  "error_PERL_INTERPRETER_TOO_FEW_ARGUMENTS",
  "error_PERL_INTERPRETER_NO_STRING_ARGUMENT",
  "error_PERL_INTERPRETER_PARSE_ERROR",
  "error_PERL_INTERPRETER_RUN_ERROR",
  "error_PERL_VALUE_GET_VARIABLE_DOES_NOT_EXIST",
};/*}}}*/

// - PERL initialize -
bool perl_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize perl_interpreter class identifier -
  c_bi_class_perl_interpreter = class_base_idx++;

  // - initialize perl_value class identifier -
  c_bi_class_perl_value = class_base_idx++;

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

// - PERL print exception -
bool perl_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_PERL_INTERPRETER_TOO_FEW_ARGUMENTS:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nPerl interpreter, too few arguments\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PERL_INTERPRETER_NO_STRING_ARGUMENT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nPerl interpreter, expected string as argument\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PERL_INTERPRETER_PARSE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError received while parsing perl script\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PERL_INTERPRETER_RUN_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError received while running perl script\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PERL_VALUE_GET_VARIABLE_DOES_NOT_EXIST:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nPerl variable of requested name and type does not exist\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class PERL_INTERPRETER -
built_in_class_s perl_interpreter_class =
{/*{{{*/
  "PerlInterpreter",
  c_modifier_public | c_modifier_final,
  8, perl_interpreter_methods,
  0, perl_interpreter_variables,
  bic_perl_interpreter_consts,
  bic_perl_interpreter_init,
  bic_perl_interpreter_clear,
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

built_in_method_s perl_interpreter_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_perl_interpreter_operator_binary_equal
  },
  {
    "PerlInterpreter#1",
    c_modifier_public | c_modifier_final,
    bic_perl_interpreter_method_PerlInterpreter_1
  },
  {
    "new_value#1",
    c_modifier_public | c_modifier_final,
    bic_perl_interpreter_method_new_value_1
  },
  {
    "get_sv#1",
    c_modifier_public | c_modifier_final,
    bic_perl_interpreter_method_get_sv_1
  },
  {
    "get_av#1",
    c_modifier_public | c_modifier_final,
    bic_perl_interpreter_method_get_av_1
  },
  {
    "get_hv#1",
    c_modifier_public | c_modifier_final,
    bic_perl_interpreter_method_get_hv_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_perl_interpreter_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_perl_interpreter_method_print_0
  },
};/*}}}*/

built_in_variable_s perl_interpreter_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_PERL_INTERPRETER_METHOD_GET_XV(XV,xv) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
  /* - ERROR - */\
  if (src_0_location->v_type != c_bi_class_string)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    BIC_EXCEPTION_PUSH_METHOD_RI("get_sv#1");\
    new_exception->params.push(1);\
    new_exception->params.push(src_0_location->v_type);\
\
    return false;\
  }\
\
  perl_interpreter_s *pi_ptr = (perl_interpreter_s *)dst_location->v_data_ptr;\
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;\
\
  /* - set perl context - */\
  PerlInterpreter *my_perl = pi_ptr->interpreter;\
  PERL_SET_CONTEXT(pi_ptr->interpreter);\
\
  /* - get scalar value - */\
  XV *value = get_ ## xv(string_ptr->data,0);\
\
  /* - ERROR - */\
  if (value == NULL)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_PERL_VALUE_GET_VARIABLE_DOES_NOT_EXIST,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  /* - increment reference counter - */\
  SvREFCNT_inc(value);\
\
  /* - create perl value object - */\
  perl_value_s *pv_ptr = (perl_value_s *)cmalloc(sizeof(perl_value_s));\
  pv_ptr->init();\
\
  dst_location->v_reference_cnt.atomic_inc();\
  pv_ptr->pi_loc = dst_location;\
  pv_ptr->sv = (SV *)value;\
\
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_perl_value,pv_ptr);\
  BIC_SET_RESULT(new_location);\
\
  return true;\
}/*}}}*/

void bic_perl_interpreter_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_perl_interpreter_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)NULL;
}/*}}}*/

void bic_perl_interpreter_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  perl_interpreter_s *pi_ptr = (perl_interpreter_s *)location_ptr->v_data_ptr;

  if (pi_ptr != NULL)
  {
    pi_ptr->clear(it);
    cfree(pi_ptr);
  }
}/*}}}*/

bool bic_perl_interpreter_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_perl_interpreter_method_PerlInterpreter_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_array)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("PerlInterpreter#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  pointer_array_s *array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (array_ptr->used < 2)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PERL_INTERPRETER_TOO_FEW_ARGUMENTS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  char *argv[array_ptr->used];

  // - process arguments array -
  pointer *i_ptr = array_ptr->data;
  pointer *i_ptr_end = i_ptr + array_ptr->used;
  char **a_ptr = argv;
  do {
    location_s *item_location = it.get_location_value(*i_ptr);

    // - ERROR -
    if (item_location->v_type != c_bi_class_string)
    {
      exception_s::throw_exception(it,module.error_base + c_error_PERL_INTERPRETER_NO_STRING_ARGUMENT,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    // - set argument pointer -
    *a_ptr = ((string_s *)item_location->v_data_ptr)->data;

  } while(++a_ptr,++i_ptr < i_ptr_end);

  // - create perl interpreter object -
  perl_interpreter_s *pi_ptr = (perl_interpreter_s *)cmalloc(sizeof(perl_interpreter_s));
  pi_ptr->init();

  // - create new interpreter -
  pi_ptr->interpreter = perl_alloc();

  // - set perl context -
  PerlInterpreter *my_perl = pi_ptr->interpreter;
  PERL_SET_CONTEXT(pi_ptr->interpreter);

  // - construct perl interpreter -
  PL_perl_destruct_level = 1;
  perl_construct(pi_ptr->interpreter);

  // - executes end blocks in perl_destruct -
  PL_exit_flags |= PERL_EXIT_DESTRUCT_END;

  // - ERROR -
  if (perl_parse(pi_ptr->interpreter,NULL,array_ptr->used,argv,NULL) != 0)
  {
    pi_ptr->clear(it);
    cfree(pi_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_PERL_INTERPRETER_PARSE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (perl_run(pi_ptr->interpreter) != 0)
  {
    pi_ptr->clear(it);
    cfree(pi_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_PERL_INTERPRETER_RUN_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  dst_location->v_data_ptr = (basic_64b)pi_ptr;

  return true;
}/*}}}*/

bool bic_perl_interpreter_method_new_value_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  perl_interpreter_s *pi_ptr = (perl_interpreter_s *)dst_location->v_data_ptr;

  // - set perl context -
  PerlInterpreter *my_perl = pi_ptr->interpreter;
  PERL_SET_CONTEXT(pi_ptr->interpreter);

  // - create perl value -
  SV *sv = perl_c::create_perl_sv(it,my_perl,src_0_location);

  // - ERROR -
  if (sv == NULL)
  {
    // FIXME TODO throw proper exception (PERL_VALUE_CREATE_ERROR)
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  // - create perl value object -
  perl_value_s *pv_ptr = (perl_value_s *)cmalloc(sizeof(perl_value_s));
  pv_ptr->init();

  dst_location->v_reference_cnt.atomic_inc();
  pv_ptr->pi_loc = dst_location;
  pv_ptr->sv = sv;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_perl_value,pv_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_perl_interpreter_method_get_sv_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_PERL_INTERPRETER_METHOD_GET_XV(SV,sv);
}/*}}}*/

bool bic_perl_interpreter_method_get_av_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_PERL_INTERPRETER_METHOD_GET_XV(AV,av);
}/*}}}*/

bool bic_perl_interpreter_method_get_hv_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_PERL_INTERPRETER_METHOD_GET_XV(HV,hv);
}/*}}}*/

bool bic_perl_interpreter_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("PerlInterpreter"),"PerlInterpreter");
  );

  return true;
}/*}}}*/

bool bic_perl_interpreter_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("PerlInterpreter");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class PERL_VALUE -
built_in_class_s perl_value_class =
{/*{{{*/
  "PerlValue",
  c_modifier_public | c_modifier_final,
  4, perl_value_methods,
  0, perl_value_variables,
  bic_perl_value_consts,
  bic_perl_value_init,
  bic_perl_value_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,//bic_perl_value_invoke,
  NULL //bic_perl_value_member
};/*}}}*/

built_in_method_s perl_value_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_perl_value_operator_binary_equal
  },
  {
    "value#0",
    c_modifier_public | c_modifier_final,
    bic_perl_value_method_value_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_perl_value_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_perl_value_method_print_0
  },
};/*}}}*/

built_in_variable_s perl_value_variables[] =
{/*{{{*/
};/*}}}*/

void bic_perl_value_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_perl_value_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)NULL;
}/*}}}*/

void bic_perl_value_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  perl_value_s *pv_ptr = (perl_value_s *)location_ptr->v_data_ptr;

  if (pv_ptr != NULL)
  {
    pv_ptr->clear(it);
    cfree(pv_ptr);
  }
}/*}}}*/

bool bic_perl_value_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_perl_value_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  perl_value_s *pv_ptr = (perl_value_s *)dst_location->v_data_ptr;
  perl_interpreter_s *pi_ptr = (perl_interpreter_s *)pv_ptr->pi_loc->v_data_ptr;

  // - set perl context -
  PerlInterpreter *my_perl = pi_ptr->interpreter;
  PERL_SET_CONTEXT(pi_ptr->interpreter);

  SV *sv = perl_c::create_perl_sv(it,my_perl,dst_location);
  
  // - ERROR -
  if (sv == NULL)
  {
    // FIXME TODO throw proper exception (PERL_VALUE_WRONG_VALUE_REFERENCE)
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  location_s *location_ptr = perl_c::perl_sv_value(it,my_perl,sv,operands[c_source_pos_idx]);
  SvREFCNT_dec(sv);

  // - ERROR -
  if (location_ptr == NULL)
  {
    // - if exception was already thrown -
    if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
    {
      return false;
    }

    // FIXME TODO throw proper exception (PERL_VALUE_VALUE_ERROR)
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  BIC_SET_RESULT(location_ptr);

  return true;
}/*}}}*/

bool bic_perl_value_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("PerlValue"),"PerlValue");
  );

  return true;
}/*}}}*/

bool bic_perl_value_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("PerlValue");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

