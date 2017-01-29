
@begin
include "prolog_module.h"
@end

// - PROLOG indexes of built in classes -
unsigned c_bi_class_prolog_context = c_idx_not_exist;
unsigned c_bi_class_prolog_atom = c_idx_not_exist;
unsigned c_bi_class_prolog_functor = c_idx_not_exist;

// - PROLOG indexes of remote classes -
unsigned c_rm_class_dict = c_idx_not_exist;

// - PROLOG module -
built_in_module_s module =
{/*{{{*/
  3,                      // Class count
  prolog_classes,         // Classes

  0,                      // Error base index
  1,                      // Error count
  prolog_error_strings,   // Error strings

  prolog_initialize,      // Initialize function
  prolog_print_exception, // Print exceptions function
};/*}}}*/

// - PROLOG classes -
built_in_class_s *prolog_classes[] =
{/*{{{*/
  &prolog_context_class,
  &prolog_atom_class,
  &prolog_functor_class,
};/*}}}*/

// - PROLOG error strings -
const char *prolog_error_strings[] =
{/*{{{*/
  "error_PROLOG_DUMMY_ERROR",
};/*}}}*/

// - PROLOG initialize -
bool prolog_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize prolog_context class identifier -
  c_bi_class_prolog_context = class_base_idx++;

  // - initialize prolog_atom class identifier -
  c_bi_class_prolog_atom = class_base_idx++;

  // - initialize prolog_functor class identifier -
  c_bi_class_prolog_functor = class_base_idx++;

  return true;
}/*}}}*/

// - PROLOG print exception -
bool prolog_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_PROLOG_DUMMY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nProlog dummy error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class PROLOG_CONTEXT -
built_in_class_s prolog_context_class =
{/*{{{*/
  "PrologContext",
  c_modifier_public | c_modifier_final,
  4, prolog_context_methods,
  0, prolog_context_variables,
  bic_prolog_context_consts,
  bic_prolog_context_init,
  bic_prolog_context_clear,
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

built_in_method_s prolog_context_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_prolog_context_operator_binary_equal
  },
  {
    "PrologContext#1",
    c_modifier_public | c_modifier_final,
    bic_prolog_context_method_PrologContext_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_prolog_context_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_prolog_context_method_print_0
  },
};/*}}}*/

built_in_variable_s prolog_context_variables[] =
{/*{{{*/
};/*}}}*/

void bic_prolog_context_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_prolog_context_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/

  // FIXME TODO continue ...
  cassert(0);
}/*}}}*/

void bic_prolog_context_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/

  // FIXME TODO continue ...
  cassert(0);
}/*}}}*/

bool bic_prolog_context_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_prolog_context_method_PrologContext_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  
  // FIXME TODO continue ...
  BIC_TODO_ERROR(__FILE__,__LINE__);
  return false;
}/*}}}*/

bool bic_prolog_context_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("PrologContext"),"PrologContext");
  );

  return true;
}/*}}}*/

bool bic_prolog_context_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("PrologContext");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class PROLOG_ATOM -
built_in_class_s prolog_atom_class =
{/*{{{*/
  "PrologAtom",
  c_modifier_public | c_modifier_final,
  5, prolog_atom_methods,
  0, prolog_atom_variables,
  bic_prolog_atom_consts,
  bic_prolog_atom_init,
  bic_prolog_atom_clear,
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

built_in_method_s prolog_atom_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_prolog_atom_operator_binary_equal
  },
  {
    "PrologAtom#1",
    c_modifier_public | c_modifier_final,
    bic_prolog_atom_method_PrologAtom_1
  },
  {
    "text#0",
    c_modifier_public | c_modifier_final,
    bic_prolog_atom_method_text_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_prolog_atom_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_prolog_atom_method_print_0
  },
};/*}}}*/

built_in_variable_s prolog_atom_variables[] =
{/*{{{*/
};/*}}}*/

void bic_prolog_atom_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_prolog_atom_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (atom_t)0;
}/*}}}*/

void bic_prolog_atom_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  atom_t atom = (atom_t)location_ptr->v_data_ptr;
  PL_unregister_atom(atom);
}/*}}}*/

bool bic_prolog_atom_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_prolog_atom_method_PrologAtom_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("PrologAtom#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create and register prolog atom -
  atom_t atom = PL_new_atom_nchars(string_ptr->size - 1,string_ptr->data);
  PL_register_atom(atom);

  dst_location->v_data_ptr = (atom_t)atom;

  return true;
}/*}}}*/

bool bic_prolog_atom_method_text_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  atom_t atom = (atom_t)dst_location->v_data_ptr;

  size_t length;
  const char *data = PL_atom_nchars(atom,&length);
  cassert(data != NULL);

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(length,data);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_prolog_atom_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("PrologAtom"),"PrologAtom");
  );

  return true;
}/*}}}*/

bool bic_prolog_atom_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("PrologAtom");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class PROLOG_FUNCTOR -
built_in_class_s prolog_functor_class =
{/*{{{*/
  "PrologFunctor",
  c_modifier_public | c_modifier_final,
  6, prolog_functor_methods,
  0, prolog_functor_variables,
  bic_prolog_functor_consts,
  bic_prolog_functor_init,
  bic_prolog_functor_clear,
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

built_in_method_s prolog_functor_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_prolog_functor_operator_binary_equal
  },
  {
    "PrologFunctor#2",
    c_modifier_public | c_modifier_final,
    bic_prolog_functor_method_PrologFunctor_2
  },
  {
    "name#0",
    c_modifier_public | c_modifier_final,
    bic_prolog_functor_method_name_0
  },
  {
    "arity#0",
    c_modifier_public | c_modifier_final,
    bic_prolog_functor_method_arity_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_prolog_functor_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_prolog_functor_method_print_0
  },
};/*}}}*/

built_in_variable_s prolog_functor_variables[] =
{/*{{{*/
};/*}}}*/

void bic_prolog_functor_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_prolog_functor_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (functor_t)0;
}/*}}}*/

void bic_prolog_functor_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

bool bic_prolog_functor_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_prolog_functor_method_PrologFunctor_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int arity;

  if ((src_0_location->v_type != c_bi_class_prolog_atom &&
       src_0_location->v_type != c_bi_class_string) ||
      !it.retrieve_integer(src_1_location,arity))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("PrologFunctor#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  atom_t atom;

  if (src_0_location->v_type == c_bi_class_prolog_atom)
  {
    atom = (atom_t)src_0_location->v_data_ptr;
  }
  else
  {
    string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;
    atom = PL_new_atom_nchars(string_ptr->size - 1,string_ptr->data);
  }

  // - create prolog functor -
  functor_t ftor = PL_new_functor(atom,arity);

  dst_location->v_data_ptr = (functor_t)ftor;

  return true;
}/*}}}*/

bool bic_prolog_functor_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  atom_t atom = PL_functor_name((functor_t)dst_location->v_data_ptr);
  PL_register_atom(atom);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_prolog_atom,atom);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_prolog_functor_method_arity_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int arity = PL_functor_arity((functor_t)dst_location->v_data_ptr);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,arity);

  return true;
}/*}}}*/

bool bic_prolog_functor_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("PrologFunctor"),"PrologFunctor");
  );

  return true;
}/*}}}*/

bool bic_prolog_functor_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("PrologFunctor");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

