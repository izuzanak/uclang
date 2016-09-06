
@begin
include "script_parser.h"
@end

/*
 * constants and definitions
 */

#define IT_INTERPRETER ((interpreter_s *)it.interpreter_ptr)

// - callers of interpreter instruction functions -
const unsigned c_instruction_cnt = 19;
int(*instruction_callers[c_instruction_cnt])(inst_params_s *params) =
{/*{{{*/
  inst_this_element,
  inst_const,
  inst_static,
  inst_call,
  inst_static_call,
  inst_element_array,
  inst_new_object,
  inst_new_object_array,
  inst_free_object,
  inst_type_identification,
  inst_object_reference_copy,
  inst_conditional_expression,
  inst_logical_and,
  inst_logical_or,
  inst_object_member_select,
  inst_switch_test,
  inst_slice_range,
  inst_expression_end,
  inst_return,
};/*}}}*/

int inst_this_element(inst_params_s *params)
{/*{{{*/
  interpreter_thread_s &it = *params->it_ptr;
  uli *&code = *params->code_ptr;
  unsigned stack_base = params->stack_base;

  // -----

  debug_message_5(fprintf(stderr,"interpreter: instruction: i_this_element: %lu <- element: %s\n",stack_base + code[ite_stack_trg],IT_INTERPRETER->variable_symbol_names[code[ite_name_idx]].data));

  location_s *this_location = (location_s *)it.get_stack_value(stack_base);

  unsigned element_position = IT_INTERPRETER->class_records[this_location->v_type].vn_ri_ep_map.map_name(code[ite_name_idx]).element_position;
  debug_assert(element_position != c_idx_not_exist);

  pointer *element_location = &(((pointer_array_s *)this_location->v_data_ptr)->data[element_position]);
  location_s *new_ref_location = it.get_new_reference((location_s **)element_location);

  pointer &stack_location = it.data_stack[stack_base + code[ite_stack_trg]];
  it.release_location_ptr((location_s *)stack_location);
  stack_location = (pointer)new_ref_location;

  code += ite_size;

  return c_run_return_code_OK;
}/*}}}*/

int inst_const(inst_params_s *params)
{/*{{{*/
  interpreter_thread_s &it = *params->it_ptr;
  uli *&code = *params->code_ptr;
  unsigned stack_base = params->stack_base;

  // -----

  debug_message_5(fprintf(stderr,"interpreter: instruction: i_const: %lu <- const:%lu\n",stack_base + code[ic_stack_trg],code[ic_const_idx]));

  location_s *location = IT_INTERPRETER->const_locations.data + code[ic_const_idx];
  location->v_reference_cnt.atomic_inc();

  pointer &stack_location = it.data_stack[stack_base + code[ic_stack_trg]];
  it.release_location_ptr((location_s *)stack_location);
  stack_location = (pointer)location;

  code += ic_size;

  return c_run_return_code_OK;
}/*}}}*/

int inst_static(inst_params_s *params)
{/*{{{*/
  interpreter_thread_s &it = *params->it_ptr;
  uli *&code = *params->code_ptr;
  unsigned stack_base = params->stack_base;

  // -----

  debug_message_5(fprintf(stderr,"interpreter: instruction: i_static: %lu <- static:%lu\n",stack_base + code[is_stack_trg],code[is_element_pos]));

  pointer *static_location = IT_INTERPRETER->static_location_ptrs.data + code[is_element_pos];
  location_s *new_ref_location = it.get_new_reference((location_s **)static_location);

  pointer &stack_location = it.data_stack[stack_base + code[is_stack_trg]];
  it.release_location_ptr((location_s *)stack_location);
  stack_location = (pointer)new_ref_location;

  code += is_size;

  return c_run_return_code_OK;
}/*}}}*/

int inst_call(inst_params_s *params)
{/*{{{*/
  interpreter_thread_s &it = *params->it_ptr;
  uli *&code = *params->code_ptr;
  unsigned stack_base = params->stack_base;

  // -----

  debug_message_5(
    fprintf(stderr,"interpreter: instruction: i_call: %lu <- %s params: ",stack_base + code[icl_stack_trg],IT_INTERPRETER->method_symbol_names[code[icl_name_idx]].data);

    uli *p_ptr = code + icl_parm_this;
    uli *p_ptr_end = p_ptr + code[icl_parm_cnt];
    do
    {
      fprintf(stderr,"%lu, ",stack_base + *p_ptr);
    }
    while(++p_ptr < p_ptr_end);

    fputc('\n',stderr);
  );

  // - test if caller address for built in class is stored -
  if (code[icl_last_class] == ((location_s *)it.get_stack_value(stack_base + code[icl_parm_this]))->v_type)
  {
    // - call built in method -
    if (!((bi_method_caller_dt)(code[icl_last_bi_mc]))(it,stack_base,code + icl_source_pos))
    {
      return c_run_return_code_EXCEPTION;
    }
  }
  else
  {
    // - proper call of method -
    if (!it.call_method(code,stack_base))
    {
      return c_run_return_code_EXCEPTION;
    }
  }

  code += (icl_size + code[icl_parm_cnt]);

  return c_run_return_code_OK;
}/*}}}*/

int inst_static_call(inst_params_s *params)
{/*{{{*/
  interpreter_thread_s &it = *params->it_ptr;
  uli *&code = *params->code_ptr;
  unsigned stack_base = params->stack_base;

  // -----

  debug_message_5(
    fprintf(stderr,"interpreter: instruction: i_static_call: %lu <- mr_idx: %lu,  ",stack_base + code[iscl_stack_trg],code[iscl_method_ri]);

    uli *p_ptr = code + iscl_parm_first;
    uli *p_ptr_end = p_ptr + code[iscl_parm_cnt];
    do
    {
      fprintf(stderr,"%lu, ",stack_base + *p_ptr);
    }
    while(++p_ptr < p_ptr_end);

    fputc('\n',stderr);
  );

  method_record_s &method_record = IT_INTERPRETER->method_records[code[iscl_method_ri]];

  if (method_record.modifiers & c_modifier_built_in)
  {
    // - calling of built in method -
    if (!method_record.bi_method_caller(it,stack_base,code + iscl_source_pos))
    {
      return c_run_return_code_EXCEPTION;
    }
  }
  else
  {
    // - creation of new thread -
    if (method_record.modifiers & c_modifier_parallel)
    {
      IT_INTERPRETER->run_new_thread(it,stack_base,code[iscl_stack_trg],method_record,code[iscl_parm_cnt],code + iscl_parm_first);
    }
    else
    {
      // - new stack base -
      unsigned new_stack_base = it.data_stack.used;

      unsigned parm_cnt = code[iscl_parm_cnt];
      if (parm_cnt != 0)
      {
        ui_array_s &parm_record_idxs = method_record.parameter_record_idxs;
        uli *c_ptr = code + iscl_parm_first;
        unsigned p_idx = 0;

        do
        {
          if (IT_INTERPRETER->variable_records[parm_record_idxs[p_idx]].modifiers & c_variable_modifier_reference)
          {
            // - passing of parameters by reference -
            pointer *parameter = &it.data_stack[stack_base + c_ptr[p_idx]];
            location_s *new_ref_location = it.get_new_reference((location_s **)parameter);

            it.data_stack.push((pointer)new_ref_location);
          }
          else
          {
            // - passing of parameter by "value" -
            location_s *parameter = (location_s *)it.get_stack_value(stack_base + c_ptr[p_idx]);
            parameter->v_reference_cnt.atomic_inc();
            it.data_stack.push((pointer)parameter);
          }
        }
        while(++p_idx < parm_cnt);
      }

      // - creation of stack for local variables of method -
      if (method_record.stack_size > (it.data_stack.used - new_stack_base))
      {
        unsigned stack_size_cnt = method_record.stack_size - (it.data_stack.used - new_stack_base);
        ((location_s *)it.blank_location)->v_reference_cnt.atomic_add(stack_size_cnt);

        do
        {
          it.data_stack.push(it.blank_location);
        }
        while(--stack_size_cnt);
      }

      // - launching of method begin code -
      if (!it.run_expression_code(method_record.begin_code.data,new_stack_base,NULL))
      {
        it.release_stack_from(new_stack_base);

        return c_run_return_code_EXCEPTION;
      }

      // - launching of method run time code -
      if (!it.run_method_code(method_record,new_stack_base,stack_base + code[iscl_stack_trg]))
      {
        return c_run_return_code_EXCEPTION;
      }
    }
  }

  code += (iscl_size + code[iscl_parm_cnt]);

  return c_run_return_code_OK;
}/*}}}*/

int inst_element_array(inst_params_s *params)
{/*{{{*/
  interpreter_thread_s &it = *params->it_ptr;
  uli *&code = *params->code_ptr;
  unsigned stack_base = params->stack_base;

  // -----

  debug_message_5(
    fprintf(stderr,"interpreter: instruction: i_element_array: %lu <- ",stack_base + code[iea_stack_trg]);

    if (code[iea_element_cnt] != 0)
    {
      uli *e_ptr = code + iea_element_first;
      uli *e_ptr_end = e_ptr + code[iea_element_cnt];
      do
      {
        fprintf(stderr,"%lu, ",stack_base + *e_ptr);
      }
      while(++e_ptr < e_ptr_end);
    }

    fputc('\n',stderr);
  );

  // - create result array -
  pointer_array_s *object_array = it.get_new_array_ptr();

  unsigned element_cnt = code[iea_element_cnt];
  if (element_cnt != 0)
  {
    object_array->copy_resize(element_cnt);
    object_array->used = element_cnt;

    pointer *o_ptr = object_array->data;
    pointer *o_ptr_end = o_ptr + object_array->used;
    uli *c_ptr = code + iea_element_first;

    do
    {
      location_s *element_location = (location_s *)it.get_stack_value(stack_base + *c_ptr);

      element_location->v_reference_cnt.atomic_inc();

      *o_ptr = (pointer)element_location;
    }
    while(++c_ptr,++o_ptr < o_ptr_end);
  }

  location_s *new_location = it.get_new_location_ptr();
  new_location->v_type = c_bi_class_array;
  new_location->v_reference_cnt.atomic_set(1);
  new_location->v_data_ptr = (basic_64b)object_array;

  pointer &trg_location = it.data_stack[stack_base + code[iea_stack_trg]];
  it.release_location_ptr((location_s *)trg_location);
  trg_location = (pointer)new_location;

  code += (iea_size + code[iea_element_cnt]);

  return c_run_return_code_OK;
}/*}}}*/

int inst_new_object(inst_params_s *params)
{/*{{{*/
  interpreter_thread_s &it = *params->it_ptr;
  uli *&code = *params->code_ptr;
  unsigned stack_base = params->stack_base;

  // -----

  debug_message_5(
    fprintf(stderr,"interpreter: instruction: i_new_object: %lu <- class: %s constructor: %s params: ",stack_base + code[ino_stack_trg],IT_INTERPRETER->class_symbol_names[IT_INTERPRETER->class_records[code[ino_class_ri]].name_idx].data,IT_INTERPRETER->method_symbol_names[code[ino_constr_name]].data);

    uli *p_ptr = code + ino_parm_first;
    uli *p_ptr_end = p_ptr + code[ino_parm_cnt];
    do
    {
      fprintf(stderr,"%lu, ",stack_base + *p_ptr);
    }
    while(++p_ptr < p_ptr_end);

    fputc('\n',stderr);
  );

  class_record_s &class_record = IT_INTERPRETER->class_records[code[ino_class_ri]];

  // - creation of new object locations -
  pointer &trg_location = it.data_stack[stack_base + code[ino_stack_trg]];
  it.release_location_ptr((location_s *)trg_location);

  location_s *new_location = it.get_new_location_ptr();
  new_location->v_type = code[ino_class_ri];
  new_location->v_reference_cnt.atomic_set(1);
  trg_location = (pointer)new_location;

  if (class_record.modifiers & c_modifier_built_in)
  {
    // - call built in class initializer function -
    class_record.bi_class_ptr->init_caller(it, new_location);
  }
  else
  {
    // - creation of new object -
    pointer_array_s *object_ptr = it.get_new_object_ptr();

    // - creation of class elements -
    if (class_record.element_cnt != 0)
    {
      object_ptr->copy_resize(class_record.element_cnt);
      ((location_s *)it.blank_location)->v_reference_cnt.atomic_add(class_record.element_cnt);

      do
      {
        object_ptr->push(it.blank_location);
      }
      while(object_ptr->used < class_record.element_cnt);
    }

    new_location->v_data_ptr = (basic_64b)object_ptr;

    // - traverse through all initializing codes -
    unsigned new_stack_base = it.data_stack.used;
    unsigned *ec_ptr_end = class_record.extend_array.data;
    unsigned *ec_ptr = ec_ptr_end + class_record.extend_array.used - 1;

    // - launching of classes initializing codes -
    new_location->v_reference_cnt.atomic_inc();
    it.data_stack.push((pointer)new_location);

    do
    {
      class_record_s &e_class_record = IT_INTERPRETER->class_records[*ec_ptr];

      if (e_class_record.stack_size > (it.data_stack.used - new_stack_base))
      {
        unsigned stack_size_cnt = e_class_record.stack_size - (it.data_stack.used - new_stack_base);
        ((location_s *)it.blank_location)->v_reference_cnt.atomic_add(stack_size_cnt);

        do
        {
          it.data_stack.push(it.blank_location);
        }
        while(--stack_size_cnt > 0);
      }

      // - launch class initializing begin code -
      if (!it.run_expression_code(e_class_record.init_begin_code.data,new_stack_base,NULL))
      {
        it.release_stack_from(new_stack_base);

        return c_run_return_code_EXCEPTION;
      }

      // - launch class initializing run time code -
      if (!it.run_expression_code(e_class_record.init_run_time_code.data,new_stack_base,NULL))
      {
        it.release_stack_from(new_stack_base);

        return c_run_return_code_EXCEPTION;
      }

    }
    while(--ec_ptr >= ec_ptr_end);

    // - remove parameters from stack -
    it.release_stack_from(new_stack_base);
  }

  // - call class constructor -
  unsigned method_ri = class_record.mnri_map.map_name(code[ino_constr_name]);

  // - ERROR -
  if (method_ri == c_idx_not_exist)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_CLASS_DOES_NOT_CONTAIN_CONSTRUCTOR,code[ino_source_pos],(location_s *)it.blank_location);
    new_exception->params.push(code[ino_class_ri]);
    new_exception->params.push(code[ino_constr_name]);

    return c_run_return_code_EXCEPTION;
  }

  method_record_s &method_record = IT_INTERPRETER->method_records[method_ri];

  if (method_record.modifiers & c_modifier_built_in)
  {
    // - call built in class constructor -
    if (!method_record.bi_method_caller(it,stack_base,code + ino_source_pos))
    {
      return c_run_return_code_EXCEPTION;
    }
  }
  else
  {
    unsigned new_stack_base = it.data_stack.used;

    new_location->v_reference_cnt.atomic_inc();
    it.data_stack.push((pointer)new_location);

    // - setting of method parameters -
    unsigned parm_cnt = code[ino_parm_cnt];
    if (parm_cnt != 0)
    {
      ui_array_s &parm_record_idxs = method_record.parameter_record_idxs;
      uli *c_ptr = code + ino_parm_first;
      unsigned p_idx = 0;

      do
      {
        if (IT_INTERPRETER->variable_records[parm_record_idxs[p_idx]].modifiers & c_variable_modifier_reference)
        {
          // - passing of parameters by reference -
          pointer *parameter = &it.data_stack[stack_base + c_ptr[p_idx]];
          location_s *new_ref_location = it.get_new_reference((location_s **)parameter);

          it.data_stack.push((pointer)new_ref_location);
        }
        else
        {
          // - passing of parameter by "value" -
          location_s *parameter = (location_s *)it.get_stack_value(stack_base + c_ptr[p_idx]);
          parameter->v_reference_cnt.atomic_inc();
          it.data_stack.push((pointer)parameter);
        }
      }
      while(++p_idx < parm_cnt);
    }

    // - creation of stack for local variables of method -
    if (method_record.stack_size > (it.data_stack.used - new_stack_base))
    {
      unsigned stack_size_cnt = method_record.stack_size - (it.data_stack.used - new_stack_base);
      ((location_s *)it.blank_location)->v_reference_cnt.atomic_add(stack_size_cnt);

      do
      {
        it.data_stack.push(it.blank_location);
      }
      while(--stack_size_cnt);
    }

    // - launching of method begin code -
    if (!it.run_expression_code(method_record.begin_code.data,new_stack_base,NULL))
    {
      it.release_stack_from(new_stack_base);

      return c_run_return_code_EXCEPTION;
    }

    // - launching of method run time code -
    if (!it.run_method_code(method_record,new_stack_base,c_idx_not_exist))
    {
      return c_run_return_code_EXCEPTION;
    }
  }

  code += (ino_size + code[ino_parm_cnt]);

  return c_run_return_code_OK;
}/*}}}*/

int inst_new_object_array(inst_params_s *params)
{/*{{{*/
  interpreter_thread_s &it = *params->it_ptr;
  uli *&code = *params->code_ptr;
  unsigned stack_base = params->stack_base;

  // -----

  debug_message_5(fprintf(stderr,"interpreter: instruction: i_new_objects_array: %lu <- class: %s constructor: %s count_pos: %lu\n",stack_base + code[inoa_stack_trg],IT_INTERPRETER->class_symbol_names[IT_INTERPRETER->class_records[code[inoa_class_ri]].name_idx].data,IT_INTERPRETER->method_symbol_names[code[inoa_constr_name]].data,stack_base + code[inoa_stack_cnt]));

  location_s *array_size_location = (location_s *)it.get_stack_value(stack_base + code[inoa_stack_cnt]);

  long long int obj_array_size;
  if (!it.retrieve_integer(array_size_location,obj_array_size))
  {
    // - ERROR -
    exception_s *new_exception = exception_s::throw_exception(it,c_error_CANNOT_CONVERT_TYPE_TO_INTEGER,code[inoa_source_pos],(location_s *)it.blank_location);
    new_exception->params.push(array_size_location->v_type);

    return c_run_return_code_EXCEPTION;
  }

  // - test array size correctness -

  // - ERROR -
  if (obj_array_size < 0)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_CANNOT_USE_NEGATIVE_NUMBER,code[inoa_source_pos],(location_s *)it.blank_location);
    new_exception->params.push(obj_array_size);

    return c_run_return_code_EXCEPTION;
  }

  // - creation of array of objects -
  pointer_array_s *object_array = it.get_new_array_ptr();

  // - creation of array objects -
  if (obj_array_size != 0)
  {
    object_array->copy_resize(obj_array_size);
    object_array->used = obj_array_size;

    pointer *o_ptr = object_array->data;
    pointer *o_ptr_end = o_ptr + object_array->used;

    do
    {
      *o_ptr = (pointer)it.get_new_location_ptr();

      if (!it.create_new_object_blank_constructor((location_s *)*o_ptr,code))
      {
        // - remove so far created array elements -
        if (o_ptr >= object_array->data)
        {
          pointer *co_ptr = object_array->data;

          do
          {
            it.release_location_ptr((location_s *)*co_ptr);
          }
          while(++co_ptr <= o_ptr);
        }

        object_array->clear();
        free(object_array);

        return c_run_return_code_EXCEPTION;
      }
    }
    while(++o_ptr < o_ptr_end);
  }

  // - creation of element array location -
  location_s *new_location = it.get_new_location_ptr();
  new_location->v_type = c_bi_class_array;
  new_location->v_reference_cnt.atomic_set(1);
  new_location->v_data_ptr = (basic_64b)object_array;

  pointer &trg_location = it.data_stack[stack_base + code[inoa_stack_trg]];
  it.release_location_ptr((location_s *)trg_location);
  trg_location = (pointer)new_location;

  code += inoa_size;

  return c_run_return_code_OK;
}/*}}}*/

int inst_free_object(inst_params_s *params)
{/*{{{*/
  interpreter_thread_s &it = *params->it_ptr;
  uli *&code = *params->code_ptr;
  unsigned stack_base = params->stack_base;

  // -----

  debug_message_5(fprintf(stderr,"interpreter: instruction: i_free_object: %lu <- %lu\n",stack_base + code[ifo_stack_trg],stack_base + code[ifo_stack_object]));

  pointer &object_location = it.get_stack_value(stack_base + code[ifo_stack_object]);
  it.release_location_ptr((location_s *)object_location);

  ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();
  object_location = it.blank_location;

  code += ifo_size;

  return c_run_return_code_OK;
}/*}}}*/

int inst_type_identification(inst_params_s *params)
{/*{{{*/
  interpreter_thread_s &it = *params->it_ptr;
  uli *&code = *params->code_ptr;
  unsigned stack_base = params->stack_base;

  // -----

  debug_message_5(fprintf(stderr,"interpreter: instruction: i_type_identification: %lu <- %lu\n",stack_base + code[iti_stack_trg],stack_base + code[iti_stack_object]));

  location_s *object_location = (location_s *)it.get_stack_value(stack_base + code[iti_stack_object]);

  location_s *new_location = it.get_new_location_ptr();
  new_location->v_type = c_bi_class_type;
  new_location->v_reference_cnt.atomic_set(1);
  new_location->v_data_ptr = (basic_64b)object_location->v_type;

  pointer &trg_location = it.data_stack[stack_base + code[iti_stack_trg]];
  it.release_location_ptr((location_s *)trg_location);
  trg_location = (pointer)new_location;

  code += iti_size;

  return c_run_return_code_OK;
}/*}}}*/

int inst_object_reference_copy(inst_params_s *params)
{/*{{{*/
  interpreter_thread_s &it = *params->it_ptr;
  uli *&code = *params->code_ptr;
  unsigned stack_base = params->stack_base;

  // -----

  debug_message_5(fprintf(stderr,"interpreter: instruction: i_reference_copy: %lu <- %lu, %lu\n",stack_base + code[iorc_stack_trg],stack_base + code[iorc_stack_dst],stack_base + code[iorc_stack_src]));

  pointer *object_location = &it.data_stack[stack_base + code[iorc_stack_src]];
  pointer &trg_location = it.data_stack[stack_base + code[iorc_stack_trg]];
  pointer &dst_location = it.data_stack[stack_base + code[iorc_stack_dst]];

  location_s *new_ref_location = it.get_new_reference((location_s **)object_location);
  new_ref_location->v_reference_cnt.atomic_inc();

  it.release_location_ptr((location_s *)trg_location);
  trg_location = (pointer)new_ref_location;

  it.release_location_ptr((location_s *)dst_location);
  dst_location = (pointer)new_ref_location;

  code += iorc_size;

  return c_run_return_code_OK;
}/*}}}*/

int inst_conditional_expression(inst_params_s *params)
{/*{{{*/
  interpreter_thread_s &it = *params->it_ptr;
  uli *&code = *params->code_ptr;
  unsigned stack_base = params->stack_base;

  // -----

  debug_message_5(fprintf(stderr,"interpreter: instruction: i_conditional_expression: %lu <- %lu\n",stack_base + code[ice_stack_trg],stack_base + code[ice_stack_src]));

  // - location containing tested value -
  location_s *location_ptr = (location_s *)it.get_stack_value(stack_base + code[ice_stack_src]);

  bool result;
  if (!it.test_value(location_ptr,result))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_CANNOT_TEST_TYPE_VALUE,code[ice_source_pos],(location_s *)it.blank_location);
    new_exception->params.push(location_ptr->v_type);

    return c_run_return_code_EXCEPTION;
  }

  // - execute expression -
  unsigned result_idx;

  if (result)
  {
    if (!it.run_expression_code(code + ice_size,stack_base,&result_idx))
    {
      return c_run_return_code_EXCEPTION;
    }
  }
  else
  {
    if (!it.run_expression_code(code + code[ice_second_exp],stack_base,&result_idx))
    {
      return c_run_return_code_EXCEPTION;
    }
  }

  // - copy result location to target location -
  {
    location_s *res_location = (location_s *)it.data_stack[stack_base + result_idx];
    pointer &trg_location = it.data_stack[stack_base + code[ice_stack_trg]];

    res_location->v_reference_cnt.atomic_inc();
    it.release_location_ptr((location_s *)trg_location);
    trg_location = (pointer)res_location;
  }

  code += code[ice_end];

  return c_run_return_code_OK;
}/*}}}*/

int inst_logical_and(inst_params_s *params)
{/*{{{*/
  interpreter_thread_s &it = *params->it_ptr;
  uli *&code = *params->code_ptr;
  unsigned stack_base = params->stack_base;

  // -----

  debug_message_5(fprintf(stderr,"interpreter: instruction: i_logical_and: %lu <- %lu\n",stack_base + code[ila_stack_trg],stack_base + code[ila_stack_src]));

  // - location containing tested value -
  location_s *location_ptr = (location_s *)it.get_stack_value(stack_base + code[ila_stack_src]);

  bool result;
  if (!it.test_value(location_ptr,result))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_CANNOT_TEST_TYPE_VALUE,code[ila_source_pos],(location_s *)it.blank_location);
    new_exception->params.push(location_ptr->v_type);

    return c_run_return_code_EXCEPTION;
  }

  if (result)
  {
    // - execute expression -
    unsigned result_idx;
    if (!it.run_expression_code(code + ila_size,stack_base,&result_idx))
    {
      return c_run_return_code_EXCEPTION;
    }

    // - copy result location to target location -
    {
      location_s *res_location = (location_s *)it.data_stack[stack_base + result_idx];
      pointer &trg_location = it.data_stack[stack_base + code[ila_stack_trg]];

      res_location->v_reference_cnt.atomic_inc();
      it.release_location_ptr((location_s *)trg_location);
      trg_location = (pointer)res_location;
    }
  }
  else
  {
    // - copy location to target location -
    {
      pointer &trg_location = it.data_stack[stack_base + code[ila_stack_trg]];

      location_ptr->v_reference_cnt.atomic_inc();
      it.release_location_ptr((location_s *)trg_location);
      trg_location = (pointer)location_ptr;
    }
  }

  code += code[ila_end];

  return c_run_return_code_OK;
}/*}}}*/

int inst_logical_or(inst_params_s *params)
{/*{{{*/
  interpreter_thread_s &it = *params->it_ptr;
  uli *&code = *params->code_ptr;
  unsigned stack_base = params->stack_base;

  // -----

  debug_message_5(fprintf(stderr,"interpreter: instruction: i_logical_or: %lu <- %lu\n",stack_base + code[ilo_stack_trg],stack_base + code[ilo_stack_src]));

  // - location containing tested value -
  location_s *location_ptr = (location_s *)it.get_stack_value(stack_base + code[ilo_stack_src]);

  bool result;
  if (!it.test_value(location_ptr,result))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_CANNOT_TEST_TYPE_VALUE,code[ilo_source_pos],(location_s *)it.blank_location);
    new_exception->params.push(location_ptr->v_type);

    return c_run_return_code_EXCEPTION;
  }

  if (!result)
  {
    // - execute expression -
    unsigned result_idx;
    if (!it.run_expression_code(code + ilo_size,stack_base,&result_idx))
    {
      return c_run_return_code_EXCEPTION;
    }

    // - copy result location to target location -
    {
      location_s *res_location = (location_s *)it.data_stack[stack_base + result_idx];
      pointer &trg_location = it.data_stack[stack_base + code[ilo_stack_trg]];

      res_location->v_reference_cnt.atomic_inc();
      it.release_location_ptr((location_s *)trg_location);
      trg_location = (pointer)res_location;
    }
  }
  else
  {
    // - copy location to target location -
    {
      pointer &trg_location = it.data_stack[stack_base + code[ilo_stack_trg]];

      location_ptr->v_reference_cnt.atomic_inc();
      it.release_location_ptr((location_s *)trg_location);
      trg_location = (pointer)location_ptr;
    }
  }

  code += code[ilo_end];

  return c_run_return_code_OK;
}/*}}}*/

int inst_object_member_select(inst_params_s *params)
{/*{{{*/
  interpreter_thread_s &it = *params->it_ptr;
  uli *&code = *params->code_ptr;
  unsigned stack_base = params->stack_base;

  // -----

  debug_message_5(fprintf(stderr,"interpreter: instruction: i_object_member_select: %lu <- %s %lu\n",stack_base + code[ioms_stack_trg],IT_INTERPRETER->variable_symbol_names[code[ioms_var_name]].data,stack_base + code[ioms_stack_object]));

  location_s *object_location = (location_s *)it.get_stack_value(stack_base + code[ioms_stack_object]);

  ri_ep_s &element_ri_ep = IT_INTERPRETER->class_records[object_location->v_type].vn_ri_ep_map.map_name(code[ioms_var_name]);

  // - ERROR -
  if (element_ri_ep.record_idx == c_idx_not_exist)
  {
    class_record_s &class_record = IT_INTERPRETER->class_records[object_location->v_type];

    if (class_record.modifiers & c_modifier_built_in && class_record.bi_class_ptr->member_caller != NULL)
    {
      // - call object member caller -
      if (!class_record.bi_class_ptr->member_caller(it,code,stack_base))
      {
        return false;
      }
    }

    // - ERROR -
    else
    {
      exception_s *new_exception = exception_s::throw_exception(it,c_error_CLASS_DOES_NOT_CONTAIN_VARIABLE,code[ioms_source_pos],(location_s *)it.blank_location);
      new_exception->params.push(object_location->v_type);
      new_exception->params.push(code[ioms_var_name]);

      return c_run_return_code_EXCEPTION;
    }
  }
  else 
  {
    // - acquire reference to object member -
    variable_record_s &variable_record = IT_INTERPRETER->variable_records[element_ri_ep.record_idx];

    // - if member is private, test correctness of access -
    if (variable_record.modifiers & c_modifier_private)
    {
      // - ERROR -
      if (((location_s *)it.data_stack[stack_base])->v_type != variable_record.parent_record)
      {
        exception_s *new_exception = exception_s::throw_exception(it,c_error_CANNOT_ACCESS_PRIVATE_VARIABLE,code[ioms_source_pos],(location_s *)it.blank_location);
        new_exception->params.push(element_ri_ep.record_idx);

        return c_run_return_code_EXCEPTION;
      }
    }

    // - acquire position of pointer to location -
    pointer *element_location;

    if (variable_record.modifiers & c_modifier_static)
    {
      // - test if static reference is not built in static variable -
      if (variable_record.modifiers & c_modifier_static_const)
      {
        // - process built in static variable -
        location_s *location = IT_INTERPRETER->const_locations.data + element_ri_ep.element_position;
        location->v_reference_cnt.atomic_inc();

        pointer &stack_location = it.data_stack[stack_base + code[ioms_stack_trg]];
        it.release_location_ptr((location_s *)stack_location);
        stack_location = (pointer)location;

        code += ioms_size;
        return c_run_return_code_OK;
      }
      else
      {
        element_location = IT_INTERPRETER->static_location_ptrs.data + (element_ri_ep.element_position);
      }
    }
    else
    {
      element_location = &(((pointer_array_s *)object_location->v_data_ptr)->data[element_ri_ep.element_position]);
    }

    location_s *new_ref_location = it.get_new_reference((location_s **)element_location);

    pointer &trg_location = it.data_stack[stack_base + code[ioms_stack_trg]];
    it.release_location_ptr((location_s *)trg_location);
    trg_location = (pointer)new_ref_location;
  }

  code += ioms_size;

  return c_run_return_code_OK;
}/*}}}*/

int inst_switch_test(inst_params_s *params)
{/*{{{*/
  interpreter_thread_s &it = *params->it_ptr;
  uli *&code = *params->code_ptr;
  unsigned stack_base = params->stack_base;

  // -----

  debug_message_5(
    fprintf(stderr,"interpreter: instruction: i_switch_test: %lu <- ",stack_base + code[ist_stack_trg]);

    if (code[ist_value_cnt] != 0)
    {
      uli *e_ptr = code + ist_value_first;
      uli *e_ptr_end = e_ptr + code[ist_value_cnt];
      do
      {
        fprintf(stderr,"%lu, ",stack_base + *e_ptr);
      }
      while(++e_ptr < e_ptr_end);
    }

    fputc('\n',stderr);
  );

  // - create result array -
  ui_array_s *index_array = (ui_array_s *)cmalloc(sizeof(ui_array_s));
  index_array->init();

  // - create result array location -
  location_s *blank_location = it.get_new_location_ptr();
  blank_location->v_type = c_bi_class_blank;
  blank_location->v_reference_cnt.atomic_set(1);
  blank_location->v_data_ptr = (basic_64b)index_array;

  unsigned value_cnt = code[ist_value_cnt];
  if (value_cnt > 1)
  {
    location_s *ref_location = (location_s *)it.data_stack[stack_base + code[ist_value_first]];
    long long int result;

    unsigned v_idx = 1;
    do
    {
      location_s *location = (location_s *)it.data_stack[stack_base + code[ist_value_first + v_idx]];

      BIC_CALL_COMPARE((it),ref_location,location,code[ist_source_pos],

                       // - release index array -
                       index_array->clear();
                       cfree(index_array);

                       // - release blank location -
                       it.release_location_ptr(blank_location);

                       return c_run_return_code_EXCEPTION
                      );

      if (result == 0)
      {
        index_array->push(v_idx - 1);
      }

    }
    while(++v_idx < value_cnt);
  }

  pointer &trg_location = it.data_stack[stack_base + code[ist_stack_trg]];
  it.release_location_ptr((location_s *)trg_location);
  trg_location = (pointer)blank_location;

  code += (ist_size + code[ist_value_cnt]);

  return c_run_return_code_OK;
}/*}}}*/

int inst_slice_range(inst_params_s *params)
{/*{{{*/
  interpreter_thread_s &it = *params->it_ptr;
  uli *&code = *params->code_ptr;
  unsigned stack_base = params->stack_base;

  // -----

  debug_message_5(fprintf(stderr,"interpreter: instruction: i_slice_range: %lu <- %lu, %lu, %lu, %lu\n",stack_base + code[isr_stack_trg],stack_base + code[isr_stack_src],stack_base + code[isr_start],stack_base + code[isr_stop],stack_base + code[isr_step]));

  unsigned trg_loc_idx = stack_base + code[isr_stack_trg];
  location_s *src_location = (location_s *)it.get_stack_value(stack_base + code[isr_stack_src]);
  location_s *start_location = (location_s *)it.get_stack_value(stack_base + code[isr_start]);
  location_s *stop_location = (location_s *)it.get_stack_value(stack_base + code[isr_stop]);
  location_s *step_location = (location_s *)it.get_stack_value(stack_base + code[isr_step]);

  // - ERROR -
  if (start_location->v_type != c_bi_class_integer ||
      stop_location->v_type != c_bi_class_integer ||
      step_location->v_type != c_bi_class_integer)
  {
    exception_s::throw_exception(it,c_error_SLICE_NOT_INTEGER_ARGUMENTS,code[isr_source_pos],(location_s *)it.blank_location);
    return c_run_return_code_EXCEPTION;
  }

  long long start = (long long)start_location->v_data_ptr;
  long long stop = (long long)stop_location->v_data_ptr;
  long long step = (long long)step_location->v_data_ptr;
  long long length = LLONG_MAX;
  bool reverse = false;

  // - adjust start value -
  if (start < 0)
  {
    // - retrieve length -
    BIC_CALL_LENGTH(it,src_location,length,code[isr_source_pos],
                    return c_run_return_code_EXCEPTION;
                   );

    // - ERROR -
    if ((start += length) < 0)
    {
      exception_s::throw_exception(it,c_error_SLICE_START_LESS_THAN_ZERO,code[isr_source_pos],(location_s *)it.blank_location);
      return c_run_return_code_EXCEPTION;
    }
  }

  // - adjust stop value -
  if (stop < 0)
  {
    if (length == LLONG_MAX)    
    {
      // - retrieve length -
      BIC_CALL_LENGTH(it,src_location,length,code[isr_source_pos],
                      return c_run_return_code_EXCEPTION;
                     );
    }

    // - ERROR -
    if ((stop += length) < 0)
    {
      exception_s::throw_exception(it,c_error_SLICE_STOP_LESS_THAN_ZERO,code[isr_source_pos],(location_s *)it.blank_location);
      return c_run_return_code_EXCEPTION;
    }
  }

  // - ERROR -
  if (step == 0)
  {
    exception_s::throw_exception(it,c_error_SLICE_STEP_EQUAL_TO_ZERO,code[isr_source_pos],(location_s *)it.blank_location);
    return c_run_return_code_EXCEPTION;
  }

  // - adjust step value -
  if (step == LLONG_MAX)
  {
    step = 1;
  }

  // - adjust step, start and stop values -
  if (step < 0)
  {
    // - adjust step value -
    step = -step;

    long long old_start = start;
    if (old_start == LLONG_MAX)
    {
      if (length == LLONG_MAX)    
      {
        // - retrieve length -
        BIC_CALL_LENGTH(it,src_location,length,code[isr_source_pos],
                        return c_run_return_code_EXCEPTION;
                       );
      }

      old_start = length - 1;
    }

    // - adjust start value -
    start = stop == LLONG_MAX ? 0 : stop;

    if (old_start > 0)
    {
      start += old_start % step;
    }

    // - adjust stop value -
    stop = old_start;

    reverse = true;
  }
  else
  {
    // - adjust start value -
    start = start == LLONG_MAX ? 0 : start;
  }

#define INST_SLICE_RANGE_EXCEPTION() \
  {/*{{{*/\
    pointer &trg_location = it.data_stack[trg_loc_idx];\
    it.release_location_ptr((location_s *)trg_location);\
    ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();\
    trg_location = it.blank_location;\
    \
    return c_run_return_code_EXCEPTION;\
  }/*}}}*/

  pointer_array_s *array_ptr = it.get_new_array_ptr();
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);

  pointer &trg_location = it.data_stack[trg_loc_idx];
  it.release_location_ptr((location_s *)trg_location);
  trg_location = (pointer)new_location;

  long long actual = 0;
  long long next = start;

  // - retrieve iterable type -
  unsigned iter_type = it.get_iterable_type(src_location);

  // - ERROR -
  if (iter_type == c_idx_not_exist)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_OBJECT_OF_CLASS_IS_NOT_ITERABLE,code[isr_source_pos],(location_s *)it.blank_location);
    new_exception->params.push(src_location->v_type);

    return c_run_return_code_EXCEPTION;
  }

#define INST_SLICE_RANGE_BODY() \
  {/*{{{*/\
    /* - push item location to result array - */\
    array_ptr->push(item_location);\
    \
    next = actual + step;\
  }/*}}}*/

  if (iter_type == c_iter_first_idx_next_idx_item)
  {
    long long index;
    location_s *item_location;

    // - retrieve first index -
    BIC_CALL_FIRST_IDX(it,src_location,index,code[isr_source_pos],
                       INST_SLICE_RANGE_EXCEPTION();
                      );

    while (index != c_idx_not_exist && next <= stop)
    {
      if (actual == next)
      {
        // - retrieve item location -
        BIC_CALL_ITEM(it,src_location,index,item_location,code[isr_source_pos],
                      INST_SLICE_RANGE_EXCEPTION();
                     );

        INST_SLICE_RANGE_BODY();
      }

      // - retrieve next index -
      BIC_CALL_NEXT_IDX(it,src_location,index,index,code[isr_source_pos],
                        INST_SLICE_RANGE_EXCEPTION();
                       );

      actual++;
    }
  }
  else if (iter_type == c_iter_next_item)
  {
    location_s *item_location;

    while (next <= stop)
    {
      // - retrieve next item location -
      BIC_CALL_NEXT_ITEM(it,src_location,item_location,code[isr_source_pos],
                         INST_SLICE_RANGE_EXCEPTION();
                        );

      if (it.get_location_value(item_location)->v_type == c_bi_class_blank)
      {
        it.release_location_ptr(item_location);
        break;
      }

      if (actual == next)
      {
        INST_SLICE_RANGE_BODY();
      }
      else
      {
        it.release_location_ptr(item_location);
      }

      actual++;
    }
  }
  else
  {
    cassert(0);
  }

  // - reverse values requested -
  if (reverse && array_ptr->used > 0)
  {
    pointer_array_s reverse_array;
    reverse_array.init_size(array_ptr->used);

    // - reverse order of result array -
    pointer *ptr = array_ptr->data + array_ptr->used;
    pointer *ptr_end = array_ptr->data;
    do
    {
      reverse_array.push(*(--ptr));
    }
    while(ptr > ptr_end);

    // - swap reverse and result arrays -
    array_ptr->swap(reverse_array);
    reverse_array.clear();
  }

  // - if source location is string -
  if (src_location->v_type == c_bi_class_string)
  {
    string_s *string_ptr = it.get_new_string_ptr();
    string_ptr->create(array_ptr->used);

    // - join slice array to string -
    if (array_ptr->used > 0)
    {
      pointer *l_ptr = array_ptr->data;
      pointer *l_ptr_end = l_ptr + array_ptr->used;
      char *s_ptr = string_ptr->data;
      do
      {
        *s_ptr = (char)((location_s *)*l_ptr)->v_data_ptr;
      }
      while(++s_ptr,++l_ptr < l_ptr_end);
    }

    // - create new string location -
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);

    // - assign string location to target location -
    pointer &trg_location = it.data_stack[trg_loc_idx];
    it.release_location_ptr((location_s *)trg_location);
    trg_location = (pointer)new_location;
  }

  code += isr_size;

  return c_run_return_code_OK;
}/*}}}*/

int inst_expression_end(inst_params_s *params)
{/*{{{*/

  // -----

  debug_message_5(fprintf(stderr,"interpreter: instruction: i_expression_end\n"));

  return c_run_return_code_RETURN;
}/*}}}*/

int inst_return(inst_params_s *params)
{/*{{{*/
  uli *&code = *params->code_ptr;
  unsigned *return_value = params->return_value;

  // -----

  debug_message_5(fprintf(stderr,"interpreter: instruction: i_return: %lu ->\n",params->stack_base + code[ir_stack_pos]));

  *return_value = code[ir_stack_pos];

  return c_run_return_code_RETURN;
}/*}}}*/

