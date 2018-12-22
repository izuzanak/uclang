
#ifndef __INSTRUCTIONS_H
#define __INSTRUCTIONS_H

/*
 * definition of interpreter instruction callback parameters
 */

struct inst_params_s
{
  interpreter_thread_s *it_ptr;
  uli **code_ptr;
  unsigned stack_base;
  unsigned *return_value;
};

/*
 * declaration of function describing interpreter instructions
 */

int inst_this_element(inst_params_s *params);
int inst_const(inst_params_s *params);
int inst_static(inst_params_s *params);
EXPORT int inst_call(inst_params_s *params);
EXPORT int inst_static_call(inst_params_s *params);
int inst_element_array(inst_params_s *params);
int inst_new_object(inst_params_s *params);
int inst_new_object_array(inst_params_s *params);
int inst_free_object(inst_params_s *params);
int inst_type_identification(inst_params_s *params);
int inst_object_reference_copy(inst_params_s *params);
int inst_conditional_expression(inst_params_s *params);
int inst_logical_and(inst_params_s *params);
int inst_logical_or(inst_params_s *params);
int inst_object_member_select(inst_params_s *params);
int inst_switch_test(inst_params_s *params);
int inst_slice_range(inst_params_s *params);
int inst_expression_end(inst_params_s *params);
int inst_return(inst_params_s *params);

/*
 * access to function callers
 */

extern int(*instruction_callers[])(inst_params_s *params);

#endif

