
@begin
include "script_parser.h"
@end

/*
 * constants and constant structures
 */

#define INTERPRETER ((interpreter_s *)interpreter_ptr)

/*
 * methods of generated structures
 */

// -- exception_s --
@begin
methods exception_s
@end

extern "C" {
exception_s *exception_s_throw_exception(interpreter_thread_s &it,unsigned a_type,unsigned a_pos,location_s *obj_location_ptr)
{/*{{{*/
  return exception_s::throw_exception(it,a_type,a_pos,obj_location_ptr);
}/*}}}*/

void exception_s_push_method_ri_class_idx(interpreter_thread_s &it,exception_s *new_exception,unsigned a_class_idx,const char *a_method_name)
{/*{{{*/
  BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,a_class_idx,a_method_name);
}/*}}}*/

void exception_s_push_parameter(exception_s *a_this,lli a_param)
{/*{{{*/
  a_this->params.push(a_param);
}/*}}}*/
}

exception_s *exception_s::throw_exception(interpreter_thread_s &it,unsigned a_type,unsigned a_pos,location_s *obj_location_ptr)
{/*{{{*/
  exception_s *new_exception = (exception_s *)cmalloc(sizeof(exception_s));
  new_exception->init();
  new_exception->type = a_type;
  new_exception->position = a_pos;

  obj_location_ptr->v_reference_cnt.atomic_inc();
  new_exception->obj_location = (pointer)obj_location_ptr;

  location_s *new_location = it.get_new_location_ptr();
  new_location->v_type = c_bi_class_exception;
  new_location->v_reference_cnt.atomic_set(1);
  new_location->v_data_ptr = (exception_s *)new_exception;

  it.release_location_ptr((location_s *)it.exception_location);
  it.exception_location = (pointer)new_location;

  return new_exception;
}/*}}}*/

// -- pointer_queue_s --
@begin
methods pointer_queue_s
@end

// -- pointer_list_s --
@begin
methods pointer_list_s
@end

// -- pointer_tree_s --
@begin
methods pointer_tree_s
@end

// -- pointer_map_s --
@begin
methods pointer_map_s
@end

// -- pointer_map_tree_s --
@begin
methods pointer_map_tree_s
@end

// -- interpreter_thread_s --
@begin
methods interpreter_thread_s
@end

extern "C" {
location_s *interpreter_thread_s_get_new_location_ptr(interpreter_thread_s *a_this)
{/*{{{*/
  return a_this->get_new_location_ptr();
}/*}}}*/

string_s *interpreter_thread_s_get_new_string_ptr(interpreter_thread_s *a_this)
{/*{{{*/
  return a_this->get_new_string_ptr();
}/*}}}*/

void interpreter_thread_s_release_location_ptr(interpreter_thread_s *a_this,location_s *location_ptr)
{/*{{{*/
  a_this->release_location_ptr(location_ptr);
}/*}}}*/
}

void interpreter_thread_s::release_stack_from(unsigned stack_base)
{/*{{{*/
  if (stack_base < data_stack.used)
  {
    pointer *s_ptr = data_stack.data + stack_base;
    pointer *s_ptr_end = data_stack.data + data_stack.used;

    do
    {
      release_location_ptr((location_s *)*s_ptr);
    }
    while(++s_ptr < s_ptr_end);

    data_stack.used = stack_base;
  }
}/*}}}*/

void interpreter_thread_s::_release_location_ptr(location_s *location_ptr)
{/*{{{*/

  // - if location is not reference -
  if (location_ptr->v_type != c_bi_reference)
  {
    if (!(INTERPRETER->class_records[location_ptr->v_type].modifiers & c_modifier_built_in))
    {
      // - store pointers to objects -
      pointer_array_s *object_ptr = (pointer_array_s *)location_ptr->v_data_ptr;

      if (object_ptr->used != 0)
      {
        pointer *l_ptr = object_ptr->data;
        pointer *l_ptr_end = l_ptr + object_ptr->used;

        do
        {
          release_location_ptr((location_s *)*l_ptr);
        }
        while(++l_ptr < l_ptr_end);
      }

      object_ptr->clear();
      cfree(object_ptr);
    }
    else
    {
      // - call built in class clear function -
      INTERPRETER->class_records[location_ptr->v_type].bi_class_ptr->clear_caller(*this, location_ptr);
    }
  }
  else
  {
    release_location_ptr((location_s *)*((pointer *)location_ptr->v_data_ptr));
    free_reference_ptrs.push((pointer)location_ptr->v_data_ptr);
  }

  location_ptr->v_type = c_bi_class_blank;
  free_location_ptrs.push((pointer)location_ptr);
}/*}}}*/

bool interpreter_thread_s::create_new_object_blank_constructor(location_s *new_location,uli *code)
{/*{{{*/
  class_record_s &class_record = INTERPRETER->class_records[code[inoa_class_ri]];

  // - creation of new object locations -
  new_location->v_type = code[inoa_class_ri];
  new_location->v_reference_cnt.atomic_set(1);

  if (class_record.modifiers & c_modifier_built_in)
  {
    // - call built in class initializer function -
    class_record.bi_class_ptr->init_caller(*this, new_location);
  }
  else
  {
    // - creation of new object -
    pointer_array_s *object_ptr = get_new_object_ptr();

    // - creation of class elements -
    if (class_record.element_cnt != 0)
    {
      object_ptr->copy_resize(class_record.element_cnt);
      ((location_s *)blank_location)->v_reference_cnt.atomic_add(class_record.element_cnt);

      do
      {
        object_ptr->push(blank_location);
      }
      while(object_ptr->used < class_record.element_cnt);
    }

    new_location->v_data_ptr = (pointer_array_s *)object_ptr;

    // - traverse through all initializing codes -
    unsigned new_stack_base = data_stack.used;
    unsigned *ec_ptr_end = class_record.extend_array.data;
    unsigned *ec_ptr = ec_ptr_end + class_record.extend_array.used - 1;

    // - launching of all classes initializing codes -
    new_location->v_reference_cnt.atomic_inc();
    data_stack.push((pointer)new_location);

    do
    {
      class_record_s &e_class_record = INTERPRETER->class_records[*ec_ptr];

      if (e_class_record.stack_size > (data_stack.used - new_stack_base))
      {
        unsigned stack_size_cnt = e_class_record.stack_size - (data_stack.used - new_stack_base);
        ((location_s *)blank_location)->v_reference_cnt.atomic_add(stack_size_cnt);

        do
        {
          data_stack.push(blank_location);
        }
        while(--stack_size_cnt > 0);
      }

      // - launch class initialization begin code -
      if (!run_expression_code(e_class_record.init_begin_code.data,new_stack_base,nullptr))
      {
        release_stack_from(new_stack_base);

        return false;
      }

      // - launch class initialization run time code -
      if (!run_expression_code(e_class_record.init_run_time_code.data,new_stack_base,nullptr))
      {
        release_stack_from(new_stack_base);

        return false;
      }

    }
    while(--ec_ptr >= ec_ptr_end);

    // - remove parameters from stack -
    release_stack_from(new_stack_base);
  }

  // - call object constructor -
  unsigned method_ri = class_record.mnri_map.map_name(code[inoa_constr_name]);

  // - ERROR -
  if (method_ri == c_idx_not_exist)
  {
    exception_s *new_exception = exception_s::throw_exception(*this,c_error_CLASS_DOES_NOT_CONTAIN_CONSTRUCTOR,code[inoa_source_pos],(location_s *)blank_location);
    new_exception->params.push(code[inoa_class_ri]);
    new_exception->params.push(code[inoa_constr_name]);

    return false;
  }

  method_record_s &method_record = INTERPRETER->method_records[method_ri];

  // - new stack base -
  unsigned new_stack_base = data_stack.used;

  // - push object location on stack -
  new_location->v_reference_cnt.atomic_inc();
  data_stack.push((pointer)new_location);

  if (method_record.modifiers & c_modifier_built_in)
  {
    // - call function implementing built in constructor -
    uli tmp_code[3] = {inoa_source_pos,c_idx_not_exist,0};
    if (!method_record.bi_method_caller(*this,new_stack_base,tmp_code))
    {
      return false;
    }

    release_stack_from(new_stack_base);
  }
  else
  {
    // - creation of stack for method local variable -
    if (method_record.stack_size > 1)
    {
      unsigned stack_size_cnt = method_record.stack_size - 1;
      ((location_s *)blank_location)->v_reference_cnt.atomic_add(stack_size_cnt);

      do
      {
        data_stack.push(blank_location);
      }
      while(--stack_size_cnt);
    }

    // - launch method begin code -
    if (!run_expression_code(method_record.begin_code.data,new_stack_base,nullptr))
    {
      release_stack_from(new_stack_base);

      return false;
    }

    // - launch method run time code -
    if (!run_method_code(method_record,new_stack_base,c_idx_not_exist))
    {
      return false;
    }
  }

  return true;
}/*}}}*/

unsigned interpreter_thread_s::catch_exception(method_record_s &method_record,unsigned stack_base,unsigned fg_idx,unsigned start_fg_idx)
{/*{{{*/
  try_fg_maps_s &try_fg_maps = method_record.try_fg_maps;

  if (try_fg_maps.used != 0)
  {
    unsigned try_fg_map_idx = c_idx_not_exist;

    try_fg_map_s *tfg_ptr = method_record.try_fg_maps.data;
    try_fg_map_s *tfg_ptr_end = tfg_ptr + method_record.try_fg_maps.used;

    // - cycle through all try block ranges defined in method -
    do
    {
      if (start_fg_idx == c_idx_not_exist || tfg_ptr->tfgm_first_fg_node >= start_fg_idx)
      {
        if (fg_idx >= tfg_ptr->tfgm_first_fg_node && fg_idx < tfg_ptr->tfgm_last_fg_node)
        {
          // - test if block is defined deeper as its predecessor (if any predecessor exist) -
          if (try_fg_map_idx != c_idx_not_exist)
          {
            if (tfg_ptr->tfgm_first_fg_node >= try_fg_maps[try_fg_map_idx].tfgm_first_fg_node)
            {
              try_fg_map_idx = tfg_ptr - method_record.try_fg_maps.data;
            }
          }
          else
          {
            try_fg_map_idx = tfg_ptr - method_record.try_fg_maps.data;
          }
        }
      }
    }
    while(++tfg_ptr < tfg_ptr_end);

    // - if exception handler was found -
    if (try_fg_map_idx != c_idx_not_exist)
    {
      // - retrieve exception handler -
      try_fg_map_s &try_fg_map = try_fg_maps[try_fg_map_idx];

      // - retrieve exception variable location -
      pointer &trg_exception_location = data_stack[stack_base + try_fg_map.tfgm_var_idx];
      release_location_ptr((location_s *)trg_exception_location);
      trg_exception_location = exception_location;

      // - set exception_location to blank_location -
      ((location_s *)blank_location)->v_reference_cnt.atomic_inc();
      exception_location = blank_location;

      return try_fg_map.tfgm_fg_idx;
    }
  }

  return c_idx_not_exist;
}/*}}}*/

#if THREAD_LIB == THREAD_LIB_DSP_TSK
static atomic_s instruction_counter;
#endif

int interpreter_thread_s::run_method_code(method_record_s &method_record,unsigned stack_base,unsigned return_trg_idx,unsigned start_fg_idx)
{/*{{{*/
  flow_graph_s &flow_graph = INTERPRETER->method_flow_graphs[method_record.flow_graph_idx];
  uli *code = method_record.run_time_code.data;

  unsigned fg_idx;

  // - retrieve starting flow graph index -
  if (start_fg_idx == c_idx_not_exist)
  {
    fg_idx = flow_graph.start_node_idx;
  }
  else
  {
    fg_idx = start_fg_idx;
  }

#define FG_HANDLE_EXCEPTION() \
{/*{{{*/\
\
  /* - exception handler search - */\
  fg_idx = catch_exception(method_record,stack_base,fg_idx,start_fg_idx);\
  if (fg_idx != c_idx_not_exist)\
  {\
    continue;\
  }\
\
  /* - remove parameters from stack - */\
  if (start_fg_idx == c_idx_not_exist)\
  {\
    release_stack_from(stack_base);\
  }\
\
  return c_run_return_code_EXCEPTION;\
}/*}}}*/

  do
  {
#if THREAD_LIB == THREAD_LIB_DSP_TSK
    // - release DSP processor for another thread, after constant instruction count -
    if (instruction_counter.atomic_inc_and_test(c_DSP_yield_cycle_const))
    {
      instruction_counter.atomic_set(0);
      thread_s::yield();
    }
#endif

    unsigned *fg_ptr = flow_graph.nodes.data + fg_idx;
    switch (*fg_ptr)
    {

    // - process expression -
    case c_fg_type_expression:
    {/*{{{*/
      if (!run_expression_code(code + fg_ptr[c_fg_expression_idx],stack_base,nullptr))
      {
        FG_HANDLE_EXCEPTION()
      }

      fg_idx = fg_ptr[c_fg_expression_first_out];
    }/*}}}*/
    break;

    // - process condition -
    case c_fg_type_condition:
    {/*{{{*/
      unsigned tested_value;
      if (!run_expression_code(code + fg_ptr[c_fg_expression_idx],stack_base,&tested_value))
      {
        FG_HANDLE_EXCEPTION()
      }

      // - location containing tested value -
      location_s *location_ptr = (location_s *)get_stack_value(stack_base + tested_value);

      bool result;
      if (!test_value(location_ptr,result))
      {
        exception_s *new_exception = exception_s::throw_exception(*this,c_error_CANNOT_TEST_TYPE_VALUE,fg_ptr[c_fg_condition_source_pos],(location_s *)blank_location);
        new_exception->params.push(location_ptr->v_type);

        FG_HANDLE_EXCEPTION()
      }

      fg_idx = result ? fg_ptr[c_fg_condition_first_out] : fg_ptr[c_fg_condition_second_out];
    }/*}}}*/
    break;

    // - process return expression -
    case c_fg_type_return_expression:
    {/*{{{*/
      unsigned return_src_idx;
      if (!run_expression_code(code + fg_ptr[c_fg_expression_idx],stack_base,&return_src_idx))
      {
        FG_HANDLE_EXCEPTION()
      }

      // - ERROR -
      if (return_trg_idx == c_idx_not_exist)
      {
        exception_s *new_exception = exception_s::throw_exception(*this,c_error_METHOD_CANNOT_RETURN_VALUE,fg_ptr[c_fg_return_expression_source_pos],(location_s *)blank_location);
        new_exception->params.push(&method_record - INTERPRETER->method_records.data);

        FG_HANDLE_EXCEPTION()
      }

      location_s *rp_location = (location_s *)get_stack_value(stack_base + return_src_idx);
      rp_location->v_reference_cnt.atomic_inc();

      pointer &return_trg = data_stack[return_trg_idx];
      release_location_ptr((location_s *)return_trg);
      return_trg = (pointer)rp_location;

      // - remove parameters from stack -
      if (start_fg_idx == c_idx_not_exist)
      {
        release_stack_from(stack_base);
      }

      return c_run_return_code_RETURN;
    }/*}}}*/
    break;

    // - process for loop -
    case c_fg_type_for_loop:
    {/*{{{*/
      unsigned cont_src_idx;
      if (!run_expression_code(code + fg_ptr[c_fg_expression_idx],stack_base,&cont_src_idx))
      {
        FG_HANDLE_EXCEPTION()
      }

#define FG_TYPE_FOR_LOOP_RELEASE() \
{/*{{{*/\
\
  /* - free item variable - */\
  pointer &res_location = data_stack[res_loc_idx];\
  release_location_ptr((location_s *)res_location);\
  ((location_s *)blank_location)->v_reference_cnt.atomic_inc();\
  res_location = blank_location;\
\
  /* - release location pointers - */\
  release_location_ptr(dst_location);\
}/*}}}*/

#define FG_TYPE_FOR_LOOP_EXCEPTION(EXIT) \
{/*{{{*/\
\
  /* - exception handler search - */\
  fg_idx = catch_exception(method_record,stack_base,fg_idx,start_fg_idx);\
  if (fg_idx != c_idx_not_exist)\
  {\
    EXIT;\
  }\
\
  FG_TYPE_FOR_LOOP_RELEASE();\
\
  /* - remove parameters from stack - */\
  if (start_fg_idx == c_idx_not_exist)\
  {\
    release_stack_from(stack_base);\
  }\
\
  return c_run_return_code_EXCEPTION;\
}/*}}}*/

#define FG_TYPE_FOR_LOOP_RETURN() \
{/*{{{*/\
\
  FG_TYPE_FOR_LOOP_RELEASE();\
\
  /* - remove parameters from stack - */\
  if (start_fg_idx == c_idx_not_exist)\
  {\
    release_stack_from(stack_base);\
  }\
\
  return c_run_return_code_RETURN;\
}/*}}}*/

#define FG_TYPE_FOR_LOOP_BODY() \
{/*{{{*/\
\
  /* - test if loop body was defined - */\
  if (fg_ptr[c_fg_for_loop_body] != c_idx_not_exist)\
  {\
    int ret_value;\
\
    try {\
      ret_value = run_method_code(method_record,stack_base,return_trg_idx,fg_ptr[c_fg_for_loop_body]);\
    }\
    catch (int)\
    {\
      FG_TYPE_FOR_LOOP_RETURN();\
    }\
\
    switch (ret_value)\
    {\
    case c_run_return_code_OK:\
      break;\
\
    case c_run_return_code_EXCEPTION:\
      FG_TYPE_FOR_LOOP_EXCEPTION(\
                                 loop_run = false;\
                                 continue;\
                                );\
      break;\
\
    case c_run_return_code_RETURN:\
      FG_TYPE_FOR_LOOP_RETURN();\
      break;\
\
    case c_run_return_code_BREAK:\
\
      /* - continue to next instruction - */\
      fg_idx = fg_ptr[c_fg_expression_first_out];\
\
      loop_run = false;\
      continue;\
      break;\
\
    case c_run_return_code_CONTINUE:\
      break;\
\
    default:\
      cassert(0);\
    }\
  }\
}/*}}}*/

      // - retrieve loop variable locations -
      unsigned res_loc_idx = stack_base + cont_src_idx;
      location_s *dst_location = (location_s *)get_stack_value(stack_base + cont_src_idx);

      // - increase reference counter of container location -
      dst_location->v_reference_cnt.atomic_inc();

      // - retrieve iterable type -
      unsigned iter_type = get_iterable_type(dst_location);

      // - ERROR -
      if (iter_type == c_idx_not_exist)
      {
        exception_s *new_exception = exception_s::throw_exception(*this,c_error_OBJECT_OF_CLASS_IS_NOT_ITERABLE,fg_ptr[c_fg_for_loop_source_pos],(location_s *)blank_location);
        new_exception->params.push(dst_location->v_type);

        FG_TYPE_FOR_LOOP_EXCEPTION(
          FG_TYPE_FOR_LOOP_RELEASE();
          break;
        );
      }

      // - run for loop body -
      bool loop_run = true;

      if (iter_type == c_iter_first_idx_next_idx_item)
      {
        long long index = c_idx_not_exist;

        BIC_CALL_FIRST_IDX((*this),dst_location,index,fg_ptr[c_fg_for_loop_source_pos],
                           FG_TYPE_FOR_LOOP_EXCEPTION(
                             FG_TYPE_FOR_LOOP_RELEASE();
                             break;
                           );
                          );

        // - test end of iteration -
        if (index == c_idx_not_exist)
        {
          // - continue to next instruction -
          fg_idx = fg_ptr[c_fg_expression_first_out];

          // - stop looping -
          loop_run = false;
        }

        while (loop_run)
        {
          location_s *new_location;

          // - retrieve item variable location -
          BIC_CALL_ITEM((*this),dst_location,index,new_location,fg_ptr[c_fg_for_loop_source_pos],
                        FG_TYPE_FOR_LOOP_EXCEPTION(
                          loop_run = false;
                          continue;
                        );
                       );

          pointer &res_location = data_stack[res_loc_idx];
          release_location_ptr((location_s *)res_location);
          res_location = (pointer)new_location;

          FG_TYPE_FOR_LOOP_BODY();

          BIC_CALL_NEXT_IDX((*this),dst_location,index,index,fg_ptr[c_fg_for_loop_source_pos],
                            FG_TYPE_FOR_LOOP_EXCEPTION(
                              loop_run = false;
                              continue;
                            );
                           );

          // - test end of iteration -
          if (index == c_idx_not_exist)
          {
            // - continue to next instruction -
            fg_idx = fg_ptr[c_fg_expression_first_out];

            // - stop looping -
            loop_run = false;
          }
        }
      }
      else if (iter_type == c_iter_next_item)
      {
        while (loop_run)
        {
          location_s *new_location;

          // - retrieve item variable location -
          BIC_CALL_NEXT_ITEM((*this),dst_location,new_location,fg_ptr[c_fg_for_loop_source_pos],
                             FG_TYPE_FOR_LOOP_EXCEPTION(
                               loop_run = false;
                               continue;
                             );
                            );

          pointer &res_location = data_stack[res_loc_idx];
          release_location_ptr((location_s *)res_location);
          res_location = (pointer)new_location;

          // - test end of iteration -
          if (get_location_value(res_location)->v_type == c_bi_class_blank)
          {
            // - continue to next instruction -
            fg_idx = fg_ptr[c_fg_expression_first_out];

            // - stop looping -
            loop_run = false;
          }
          else
          {
            FG_TYPE_FOR_LOOP_BODY();
          }
        }
      }
      else
      {
        cassert(0);
      }

      FG_TYPE_FOR_LOOP_RELEASE();
    }/*}}}*/
    break;

    // - process break -
    case c_fg_type_break:
    {/*{{{*/

      // - remove parameters from stack -
      if (start_fg_idx == c_idx_not_exist)
      {
        release_stack_from(stack_base);
      }

      return c_run_return_code_BREAK;
    }/*}}}*/
    break;

    // - process continue -
    case c_fg_type_continue:
    {/*{{{*/

      // - remove parameters from stack -
      if (start_fg_idx == c_idx_not_exist)
      {
        release_stack_from(stack_base);
      }

      return c_run_return_code_CONTINUE;
    }/*}}}*/
    break;

    // - process switch -
    case c_fg_type_switch:
    {/*{{{*/
      unsigned test_src_idx;
      if (!run_expression_code(code + fg_ptr[c_fg_expression_idx],stack_base,&test_src_idx))
      {
        FG_HANDLE_EXCEPTION()
      }

#define FG_TYPE_SWITCH_RELEASE() \
{/*{{{*/\
  /* - release index array - */\
  index_array->clear();\
  cfree(index_array);\
}/*}}}*/

#define FG_TYPE_SWITCH_EXCEPTION() \
{/*{{{*/\
  /* - exception handler search - */\
  fg_idx = catch_exception(method_record,stack_base,fg_idx,start_fg_idx);\
  if (fg_idx != c_idx_not_exist)\
  {\
    /* - stop looping - */\
    loop_run = false;\
    continue;\
  }\
\
  FG_TYPE_SWITCH_RELEASE();\
\
  /* - remove parameters from stack - */\
  if (start_fg_idx == c_idx_not_exist)\
  {\
    release_stack_from(stack_base);\
  }\
\
  return c_run_return_code_EXCEPTION;\
}/*}}}*/

#define FG_TYPE_SWITCH_RETURN() \
{/*{{{*/\
  FG_TYPE_SWITCH_RELEASE();\
\
  /* - remove parameters from stack - */\
  if (start_fg_idx == c_idx_not_exist)\
  {\
    release_stack_from(stack_base);\
  }\
\
  return c_run_return_code_RETURN;\
}/*}}}*/

      // - retrieve switch test result -
      location_s *blank_location = (location_s *)get_stack_value(stack_base + test_src_idx);

      // - retrieve count of default cases -
      unsigned default_cnt = fg_ptr[c_fg_switch_default_cnt];

      // - retrieve switch test result array -
      ui_array_s *index_array = (ui_array_s *)blank_location->v_data_ptr;

      // - if result array is not empty, process expression cases -
      if (index_array->used != 0)
      {
        // - index of last executed code -
        unsigned last_code_idx = c_idx_not_exist;

        // - pointers to locations of expression indexes -
        unsigned *ei_ptr = index_array->data;
        unsigned *ei_ptr_end = ei_ptr + index_array->used;

        // - run switch case codes -
        bool loop_run = true;

        while (loop_run)
        {
          // - retrieve index of code to be executed -
          unsigned code_idx = fg_ptr[c_fg_switch_defaults + default_cnt + *ei_ptr];

          // - if code index is not empty, and not equal to last executed code -
          if (code_idx != c_idx_not_exist && last_code_idx != code_idx)
          {
            // - execute switch case code -
            int ret_value;

            try {
              ret_value = run_method_code(method_record,stack_base,return_trg_idx,code_idx);
            }
            catch (int)
            {
              FG_TYPE_SWITCH_RETURN();
            }

            switch (ret_value)
            {
            case c_run_return_code_OK:
              break;

            case c_run_return_code_EXCEPTION:
              FG_TYPE_SWITCH_EXCEPTION();
              break;

            case c_run_return_code_RETURN:
              FG_TYPE_SWITCH_RETURN();
              break;

            default:
              cassert(0);
            }

            // - store last executed code index -
            last_code_idx = code_idx;
          }

          if (++ei_ptr >= ei_ptr_end)
          {
            // - continue to next instruction -
            fg_idx = fg_ptr[c_fg_expression_first_out];

            // - stop looping -
            loop_run = false;
          }
        }
      }

      // - else process default cases -
      else
      {
        // - if any default cases are defined -
        if (default_cnt != 0)
        {
          // - code indexes to be executed -
          unsigned *ci_ptr = fg_ptr + c_fg_switch_defaults;
          unsigned *ci_ptr_end = ci_ptr + default_cnt;

          // - run switch case codes -
          bool loop_run = true;

          while (loop_run)
          {
            // - if code index is not empty -
            if (*ci_ptr != c_idx_not_exist)
            {
              // - execute default case code -
              int ret_value;

              try {
                ret_value = run_method_code(method_record,stack_base,return_trg_idx,*ci_ptr);
              }
              catch (int)
              {
                FG_TYPE_SWITCH_RETURN();
              }

              switch (ret_value)
              {
              case c_run_return_code_OK:
                break;

              case c_run_return_code_EXCEPTION:
                FG_TYPE_SWITCH_EXCEPTION();
                break;

              case c_run_return_code_RETURN:
                FG_TYPE_SWITCH_RETURN();
                break;

              default:
                cassert(0);
              }
            }

            if (++ci_ptr >= ci_ptr_end)
            {
              // - continue to next instruction -
              fg_idx = fg_ptr[c_fg_expression_first_out];

              // - stop looping -
              loop_run = false;
            }
          }
        }
        else
        {
          // - continue to next instruction -
          fg_idx = fg_ptr[c_fg_expression_first_out];
        }
      }

      FG_TYPE_SWITCH_RELEASE();
    }/*}}}*/
    break;

    default:
      debug_assert(0);
    }

  }
  while(fg_idx != c_idx_not_exist);

  // - remove parameters from stack -
  if (start_fg_idx == c_idx_not_exist)
  {
    release_stack_from(stack_base);
  }

  return c_run_return_code_OK;
}/*}}}*/

bool interpreter_thread_s::call_method(uli *code,unsigned stack_base)
{/*{{{*/
  location_s *call_location = (location_s *)get_stack_value(stack_base + code[icl_parm_this]);

  unsigned method_ri = INTERPRETER->class_records[call_location->v_type].mnri_map.map_name(code[icl_name_idx]);

  // - ERROR -
  if (method_ri == c_idx_not_exist)
  {
    class_record_s &class_record = INTERPRETER->class_records[call_location->v_type];

    if (class_record.modifiers & c_modifier_built_in && class_record.bi_class_ptr->invoke_caller != nullptr)
    {
      // - call object invoke caller -
      if (!class_record.bi_class_ptr->invoke_caller(*this,code,stack_base,code + icl_source_pos))
      {
        return false;
      }
    }

    // - ERROR -
    else
    {
      exception_s *new_exception = exception_s::throw_exception(*this,c_error_CLASS_DOES_NOT_CONTAIN_METHOD,code[icl_source_pos],(location_s *)blank_location);
      new_exception->params.push(call_location->v_type);
      new_exception->params.push(code[icl_name_idx]);

      return false;
    }
  }
  else
  {
    method_record_s &method_record = INTERPRETER->method_records[method_ri];

    if (method_record.modifiers & c_modifier_built_in)
    {
      // - call built in method -
      if (!method_record.bi_method_caller(*this,stack_base,code + icl_source_pos))
      {
        return false;
      }
    }
    else
    {
      // - if method is private, then test calling -
      if (method_record.modifiers & c_modifier_private)
      {
        // - ERROR -
        if (((location_s *)data_stack[stack_base])->v_type != method_record.parent_record)
        {
          exception_s *new_exception = exception_s::throw_exception(*this,c_error_CANNOT_ACCESS_PRIVATE_METHOD,code[icl_source_pos],(location_s *)blank_location);
          new_exception->params.push(method_ri);

          return false;
        }
      }

      // - creation of new thread -
      if (method_record.modifiers & c_modifier_parallel)
      {
        // - parallel method must be always static -
        INTERPRETER->run_new_thread(*this,stack_base,code[icl_stack_trg],method_record,code[icl_parm_cnt] - 1,code + icl_parm_this + 1);
      }
      else
      {
        // - new stack base -
        unsigned new_stack_base = data_stack.used;

        // - if method is not static store to stack location of this variable -
        if (!(method_record.modifiers & c_modifier_static))
        {
          location_s *this_parameter = (location_s *)get_stack_value(stack_base + code[icl_parm_this]);
          this_parameter->v_reference_cnt.atomic_inc();
          data_stack.push((pointer)this_parameter);
        }

        // - store on stack location of method parameters -
        unsigned parm_cnt = code[icl_parm_cnt] - 1;
        if (parm_cnt != 0)
        {
          ui_array_s &parm_record_idxs = method_record.parameter_record_idxs;
          uli *c_ptr = code + icl_parm_this + 1;
          unsigned p_idx = 0;

          do
          {
            if (INTERPRETER->variable_records[parm_record_idxs[p_idx]].modifiers & c_variable_modifier_reference)
            {
              // - passing of parameters by reference -
              pointer *parameter = &data_stack[stack_base + c_ptr[p_idx]];
              location_s *new_ref_location = get_new_reference((location_s **)parameter);

              data_stack.push((pointer)new_ref_location);
            }
            else
            {
              // - passing of parameter by its value -
              location_s *parameter = (location_s *)get_stack_value(stack_base + c_ptr[p_idx]);
              parameter->v_reference_cnt.atomic_inc();
              data_stack.push((pointer)parameter);
            }
          }
          while(++p_idx < parm_cnt);
        }

        // - creation of stack for local variables of method -
        if (method_record.stack_size > (data_stack.used - new_stack_base))
        {
          unsigned stack_size_cnt = method_record.stack_size - (data_stack.used - new_stack_base);
          ((location_s *)blank_location)->v_reference_cnt.atomic_add(stack_size_cnt);

          do
          {
            data_stack.push(blank_location);
          }
          while(--stack_size_cnt);
        }

        // - launching of method begin code -
        if (!run_expression_code(method_record.begin_code.data,new_stack_base,nullptr))
        {
          release_stack_from(new_stack_base);

          return false;
        }

        // - launching of method run time code -
        if (!run_method_code(method_record,new_stack_base,stack_base + code[icl_stack_trg]))
        {
          return false;
        }
      }
    }
  }

  return true;
}/*}}}*/

bool interpreter_thread_s::handle_signal(int signal_number)
{/*{{{*/
  pointer_array_s &sh_locations = INTERPRETER->signal_handler_locations;

  // - test if signal handler is defined -
  if (sh_locations.used <= (unsigned)signal_number)
  {
    return false;
  }

  // - retrieve signal handler location -
  location_s *sh_location = (location_s *)sh_locations[signal_number];

  // - test if signal handler is delegate object -
  if (sh_location->v_type != c_bi_class_delegate)
  {
    return false;
  }

  // - retrieve delegate pointer -
  delegate_s *delegate_ptr = (delegate_s *)sh_location->v_data_ptr;

  // - create signal number location -
  location_s *sn_location = get_new_location_ptr();
  sn_location->v_type = c_bi_class_integer;
  sn_location->v_reference_cnt.atomic_set(1);
  sn_location->v_data_ptr = (long long int)signal_number;

  // - call delegate method -
  location_s *trg_location = nullptr;

  // FIXME TODO set properly SOURCE_POS, now set to zero
  BIC_CALL_DELEGATE((*this),delegate_ptr,(pointer *)&sn_location,1,trg_location,0,
                    release_location_ptr(sn_location);
                    return false;
                   );

  // - release unused locations -
  release_location_ptr(sn_location);
  release_location_ptr(trg_location);

  return true;
}/*}}}*/

void interpreter_thread_s::free_variables_clear()
{/*{{{*/

  // - release free locations -
  if (free_location_ptrs.used != 0)
  {
    pointer *fl_ptr = free_location_ptrs.data;
    pointer *fl_ptr_end = fl_ptr + free_location_ptrs.used;

    do
    {
      cfree((location_s *)*fl_ptr);
    }
    while(++fl_ptr < fl_ptr_end);
  }

  // - release free reference pointers -
  if (free_reference_ptrs.used != 0)
  {
    pointer *fr_ptr = free_reference_ptrs.data;
    pointer *fr_ptr_end = fr_ptr + free_reference_ptrs.used;

    do
    {
      cfree(*fr_ptr);
    }
    while(++fr_ptr < fr_ptr_end);
  }

}/*}}}*/

// -- interpreter_s --
@begin
methods interpreter_s
@end

void interpreter_s::create_from_script_parser(script_parser_s &sp)
{/*{{{*/
  sources.swap(sp.sources);

  bi_module_libs.swap(sp.bi_module_libs);
  bi_module_pointers.swap(sp.bi_module_pointers);

  error_strings.swap(sp.error_strings);

  class_symbol_names.swap(sp.class_symbol_names);
  method_symbol_names.swap(sp.method_symbol_names);
  variable_symbol_names.swap(sp.variable_symbol_names);

  namespace_records.swap(sp.namespace_records);
  class_records.swap(sp.class_records);
  method_records.swap(sp.method_records);
  variable_records.swap(sp.variable_records);

  // - parsed informations -
  const_chars.swap(sp.const_chars);
  const_ints.swap(sp.const_ints);
  const_floats.swap(sp.const_floats);
  const_strings.swap(sp.const_strings);
  const_delegates.swap(sp.const_delegates);

  // - graphs of program flow -

  if (sp.method_flow_graphs.used != 0)
  {
    method_flow_graphs.copy_resize(sp.method_flow_graphs.used);
    method_flow_graphs.used = sp.method_flow_graphs.used;

    unsigned fg_idx = 0;
    do
    {
      exp_flow_graph_s &src = sp.method_flow_graphs[fg_idx];
      flow_graph_s &trg = method_flow_graphs[fg_idx];

      trg.start_node_idx = src.start_node_idx;
      trg.nodes.swap(src.nodes);
    }
    while(++fg_idx < sp.method_flow_graphs.used);
  }

  static_element_cnt = sp.static_element_cnt;

  stack_size = sp.stack_size;
  static_begin_code.swap(sp.static_begin_code);
  static_run_time_code.swap(sp.static_run_time_code);

  // - constant and static variables -
  const_locations.clear();
  static_location_ptrs.clear();

  // - signal handlers locations -
  signal_handler_locations.clear();

  // - pointer to interpreter main thread -
  main_thread_ptr = nullptr;

  // - count of created threads -
  thread_cnt.atomic_set(0);

  // - interpreter terminate flag -
  terminate.atomic_set(0);
}/*}}}*/

void interpreter_s::create_constant_and_static_locations()
{/*{{{*/
  const_locations.push_blanks(
    const_chars.used +
    const_ints.used +
    const_floats.used +
    const_strings.used +
    const_delegates.used +
    class_records.used);

  location_s *cv_ptr = const_locations.data;

  // - process char constants -
  if (const_chars.used != 0)
  {
    char *c_ptr = const_chars.data;
    char *c_ptr_end = c_ptr + const_chars.used;

    do
    {
      cv_ptr->v_type = c_bi_class_char;
      cv_ptr->v_reference_cnt.atomic_set(1);
      cv_ptr->v_data_ptr = (char)*c_ptr;
    }
    while(++cv_ptr,++c_ptr < c_ptr_end);
  }

  // - process int constants -
  if (const_ints.used != 0)
  {
    unsigned ci_idx = 0;
    do
    {
      cv_ptr->v_type = c_bi_class_integer;
      cv_ptr->v_reference_cnt.atomic_set(1);
      cv_ptr->v_data_ptr = (long long int)const_ints.data[ci_idx].object;
    }
    while(++cv_ptr,++ci_idx < const_ints.used);
  }

  // - process float constants -
  if (const_floats.used != 0)
  {
    unsigned cf_idx = 0;
    do
    {
      cv_ptr->v_type = c_bi_class_float;
      cv_ptr->v_reference_cnt.atomic_set(1);
      cv_ptr->v_data_ptr = (double)const_floats.data[cf_idx].object;
    }
    while(++cv_ptr,++cf_idx < const_floats.used);
  }

  // - process string constants -
  if (const_strings.used != 0)
  {
    unsigned cs_idx = 0;
    do
    {
      cv_ptr->v_type = c_bi_class_string;
      cv_ptr->v_reference_cnt.atomic_set(1);
      cv_ptr->v_data_ptr = (string_s *)&const_strings.data[cs_idx].object;
    }
    while(++cv_ptr,++cs_idx < const_strings.used);
  }

  // - process delegate constants -
  if (const_delegates.used != 0)
  {
    unsigned cd_idx = 0;
    do
    {
      cv_ptr->v_type = c_bi_class_delegate;
      cv_ptr->v_reference_cnt.atomic_set(1);
      cv_ptr->v_data_ptr = (delegate_s *)&const_delegates[cd_idx];
    }
    while(++cv_ptr,++cd_idx < const_delegates.used);
  }

  // - creation type constants -
  if (class_records.used != 0)
  {
    unsigned cr_idx = 0;

    do
    {
      cv_ptr->v_type = c_bi_class_type;
      cv_ptr->v_reference_cnt.atomic_set(1);
      cv_ptr->v_data_ptr = (unsigned)cr_idx;
    }
    while(++cv_ptr,++cr_idx < class_records.used);
  }

  // - creation of static built in constants -
  if (class_records.used != 0)
  {
    class_record_s *cr_ptr = class_records.data;
    class_record_s *cr_ptr_end = cr_ptr + class_records.used;
    do
    {
      if (cr_ptr->modifiers & c_modifier_built_in)
      {
        cr_ptr->bi_class_ptr->consts_caller(const_locations);
      }
    }
    while(++cr_ptr < cr_ptr_end);
  }

  // - creation of static variable locations of interpreter -
  if (static_element_cnt > 0)
  {
    location_s *blank_location = (location_s *)cmalloc(sizeof(location_s));
    blank_location->v_type = c_bi_class_blank;
    blank_location->v_reference_cnt.atomic_set(static_element_cnt);

    static_location_ptrs.copy_resize(static_element_cnt);
    static_location_ptrs.used = static_element_cnt;

    pointer *sl_ptr = static_location_ptrs.data;
    pointer *sl_ptr_end = sl_ptr + static_element_cnt;

    do
    {
      *sl_ptr = (pointer)blank_location;
    }
    while(++sl_ptr < sl_ptr_end);
  }
}/*}}}*/

void interpreter_s::release_constant_and_static_locations()
{/*{{{*/

  // - create dummy interpreter thread -
  interpreter_thread_s dummy_thread;
  dummy_thread.init();

  // - set thread pointer to interpreter -
  dummy_thread.interpreter_ptr = this;

  // - reset throw on terminate flag -
  dummy_thread.throw_on_terminate = false;

  // - release static built in constants -
  unsigned parse_constant_cnt = const_chars.used + const_ints.used +
                                const_floats.used + const_strings.used +
                                const_delegates.used + class_records.used;

  if (const_locations.used > parse_constant_cnt)
  {
    location_s *cv_ptr = const_locations.data + parse_constant_cnt;
    location_s *cv_ptr_end = const_locations.data + const_locations.used;

    do
    {
      cassert(class_records[cv_ptr->v_type].modifiers & c_modifier_built_in);
      class_records[cv_ptr->v_type].bi_class_ptr->clear_caller(dummy_thread,cv_ptr);
    }
    while(++cv_ptr < cv_ptr_end);
  }

  // - release locations of static variables -
  if (static_element_cnt != 0)
  {
    pointer *sl_ptr = static_location_ptrs.data;
    pointer *sl_ptr_end = sl_ptr + static_location_ptrs.used;

    do
    {
      dummy_thread.release_location_ptr((location_s *)*sl_ptr);
    }
    while(++sl_ptr < sl_ptr_end);
  }

  // - release signal handler locations -
  if (signal_handler_locations.used != 0)
  {
    pointer *sh_ptr = signal_handler_locations.data;
    pointer *sh_ptr_end = sh_ptr + signal_handler_locations.used;

    do
    {
      dummy_thread.release_location_ptr((location_s *)*sh_ptr);
    }
    while(++sh_ptr < sh_ptr_end);
  }

  // - clear dummy thread -
  dummy_thread.free_variables_clear();
  dummy_thread.clear();
}/*}}}*/

#if SYSTEM_TYPE != SYSTEM_TYPE_DSP
void interpreter_s::DEBUG_print_const_locations()
{/*{{{*/
  if (const_locations.used != 0)
  {
    location_s *v_ptr = const_locations.data;
    location_s *v_ptr_end = v_ptr + const_locations.used;

    do
    {
      switch(v_ptr->v_type)
      {
      case c_bi_class_char:
        printf("Char: %c\n",(char)v_ptr->v_data_ptr);
        break;
      case c_bi_class_integer:
        printf("Integer: %" HOST_LL_FORMAT "d\n",(long long int)v_ptr->v_data_ptr);
        break;
      case c_bi_class_float:
        printf("Float: %f\n",(double)v_ptr->v_data_ptr);
        break;
      case c_bi_class_string:
        printf("String: %s\n",((string_s *)v_ptr->v_data_ptr)->data);
        break;
      case c_bi_class_error:
        printf("Error: %s\n",error_strings[(unsigned)v_ptr->v_data_ptr].data);
        break;
      case c_bi_class_type:
        printf("Type: %s\n",class_symbol_names[class_records[(unsigned)v_ptr->v_data_ptr].name_idx].data);
        break;
      default:
      {
        printf("%s: N/A\n",class_symbol_names[class_records[v_ptr->v_type].name_idx].data);
      }
      }
    }
    while(++v_ptr < v_ptr_end);
  }
}/*}}}*/
#endif

void interpreter_s::print_exception_message(exception_s &exception)
{/*{{{*/

  // - if there are any modules loaded -
  if (bi_module_pointers.used != 0)
  {
    built_in_module_s **m_ptr = (built_in_module_s **)bi_module_pointers.data;
    built_in_module_s **m_ptr_end = m_ptr + bi_module_pointers.used;
    do
    {
      if ((*m_ptr)->print_exception_caller(*this,exception))
      {
        return;
      }
    }
    while(++m_ptr < m_ptr_end);
  }

  // - exception was not recognized by any of modules -
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = sources[GET_SRC_IDX(exception.position)];

  fprintf(stderr," ---------------------------------------- \n");
  fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
  print_error_line(source.source_string,source_pos);
  fprintf(stderr,"Unrecognized exception\n");
  fprintf(stderr," ---------------------------------------- \n");

}/*}}}*/

unsigned interpreter_s::get_global_namespace_class_idx_by_name_idx(unsigned a_name_idx)
{/*{{{*/

  // - search for name in global namespace -
  ui_array_s &global_ns_class_records = namespace_records[0].class_record_idxs;

  // - if there are some classes in global namespace -
  if (global_ns_class_records.used != 0)
  {
    unsigned *gni_ptr = global_ns_class_records.data;
    unsigned *gni_ptr_end = gni_ptr + global_ns_class_records.used;
    do
    {
      if (class_records[*gni_ptr].name_idx == a_name_idx)
      {
        return *gni_ptr;
      }
    }
    while(++gni_ptr < gni_ptr_end);
  }

  return c_idx_not_exist;
}/*}}}*/

bool interpreter_s::run_new_thread(interpreter_thread_s &p_thread,unsigned p_stack_base,unsigned p_stack_trg,method_record_s &method_record,unsigned param_cnt,uli *parms)
{/*{{{*/

  // - creation of new thread structure -
  thread_s *new_thread_ptr = (thread_s *)cmalloc(sizeof(thread_s));
  new_thread_ptr->init();

  // - creation of location for reference to thread -
  location_s *thread_location = p_thread.get_new_location_ptr();
  thread_location->v_type = c_bi_class_thread;
  thread_location->v_reference_cnt.atomic_set(2);
  thread_location->v_data_ptr = (thread_s *)new_thread_ptr;

  // - store location to old thread stack -
  pointer &stack_location = p_thread.data_stack[p_stack_base + p_stack_trg];
  p_thread.release_location_ptr((location_s *)stack_location);
  stack_location = (pointer)thread_location;

  // - creation of structure describing interpreter thread -
  interpreter_thread_s *thread = (interpreter_thread_s *)cmalloc(sizeof(interpreter_thread_s));
  thread->init();

  // - set thread pointer to interpreter -
  thread->interpreter_ptr = (pointer)this;

  // - set throw on terminate flag -
  thread->throw_on_terminate = true;

  // - attach thread location -
  thread->thread_location = (pointer)thread_location;

  // - copy blank thread location, and exception location -
  ((location_s *)p_thread.blank_location)->v_reference_cnt.atomic_add(2);
  thread->blank_location = p_thread.blank_location;
  thread->exception_location = p_thread.blank_location;

  // - store position of location of return value -
  ((location_s *)thread->blank_location)->v_reference_cnt.atomic_inc();
  thread->data_stack.push(thread->blank_location);

  // - store method parameters to thread stack -
  {
    if (param_cnt != 0)
    {
      ui_array_s &parm_record_idxs = method_record.parameter_record_idxs;
      unsigned p_idx = 0;

      do
      {
        if (variable_records[parm_record_idxs[p_idx]].modifiers & c_variable_modifier_reference)
        {
          // - passing of parameter by reference -
          pointer *parameter = &p_thread.data_stack[p_stack_base + parms[p_idx]];
          location_s *new_ref_location = thread->get_new_reference((location_s **)parameter);

          thread->data_stack.push((pointer)new_ref_location);
        }
        else
        {
          // - passing of parameter by its value -
          location_s *parameter = (location_s *)p_thread.get_stack_value(p_stack_base + parms[p_idx]);
          parameter->v_reference_cnt.atomic_inc();
          thread->data_stack.push((pointer)parameter);
        }
      }
      while(++p_idx < param_cnt);
    }
  }

  // - fill stack to size used by method -
  {
    unsigned stack_size_cnt = (method_record.stack_size + 1) - thread->data_stack.used;
    if (stack_size_cnt > 0)
    {
      ((location_s *)thread->blank_location)->v_reference_cnt.atomic_add(stack_size_cnt);

      do
      {
        thread->data_stack.push(thread->blank_location);
      }
      while(--stack_size_cnt > 0);
    }
  }

  // - block passing pointer to thread and method description -
  pointer *nt_start_info = (pointer *)cmalloc(2*sizeof(pointer));
  nt_start_info[0] = (pointer)thread;
  nt_start_info[1] = (pointer)&method_record;

  // - increase interpreter thread count -
  thread_cnt.atomic_inc();

  int ret = new_thread_ptr->create((void *)new_thread_function,(void *)nt_start_info);

  if (ret != c_error_OK)
  {
    // - decrease interpreter thread count -
    thread_cnt.atomic_dec();

    // - release temporary block -
    cfree(nt_start_info);

    // - release location from stack -
    thread->release_stack_from(0);

    // - release thread location -
    p_thread.release_location_ptr((location_s *)thread->thread_location);

    // - release blank and exception locations of thread -
    p_thread.release_location_ptr((location_s *)thread->blank_location);
    p_thread.release_location_ptr((location_s *)thread->exception_location);

    // - release thread description from memory -
    thread->free_variables_clear();
    thread->clear();
    cfree(thread);

    // - release location of thread variable -
    p_thread.release_location_ptr(thread_location);

    // - creation of error value location -
    location_s *error_location = p_thread.get_new_location_ptr();
    error_location->v_type = c_bi_class_error;
    error_location->v_reference_cnt.atomic_set(1);
    error_location->v_data_ptr = (unsigned)ret;

    // - insert error value to return position -
    p_thread.data_stack[p_stack_base + p_stack_trg] = (pointer)error_location;
  }

  return true;
}/*}}}*/

int interpreter_s::run_main_thread(const char *class_name,const char *method_name,string_array_s &arg_list)
{/*{{{*/

#if THREAD_LIB == THREAD_LIB_DSP_TSK
  instruction_counter.atomic_set(0);
#endif

  unsigned class_name_idx = class_symbol_names.get_idx_char_ptr(strlen(class_name),class_name);
  unsigned class_record_idx;
  unsigned method_name_idx = method_symbol_names.get_idx_char_ptr(strlen(method_name),method_name);
  unsigned method_record_idx = c_idx_not_exist;

  // - retrieve main method index -
  if (class_name_idx != c_idx_not_exist && method_name_idx != c_idx_not_exist)
  {
    class_record_idx = get_global_namespace_class_idx_by_name_idx(class_name_idx);
    if (class_record_idx != c_idx_not_exist && !(class_records[class_record_idx].modifiers & c_modifier_built_in))
    {
      method_record_idx = class_records[class_record_idx].mnri_map.map_name(method_name_idx);
    }
  }

  if (method_record_idx == c_idx_not_exist)
  {
    // - ERROR -
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR\n");
    fprintf(stderr,"\n");
    fprintf(stderr,"Cannot find main entry method to execute\n");
    fprintf(stderr," ---------------------------------------- \n");

    return 125;
  }

  // - retrieve main method record -
  method_record_s &method_record = method_records[method_record_idx];
  if (!(method_record.modifiers & c_modifier_static))
  {
    // - ERROR -
    unsigned source_pos = GET_SRC_POS(method_record.name_position.ui_first);
    source_s &source = sources[GET_SRC_IDX(method_record.name_position.ui_first)];

    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    fprintf(stderr,"\n");
    fprintf(stderr,"Invalid modifiers of main entry method\n");
    fprintf(stderr," ---------------------------------------- \n");

    return 125;
  }

  // *****

  // - pointer to location of return value -
  location_s *return_location;

  // - return integer value -
  int return_value = 0;

  // - creation of description of main thread -
  interpreter_thread_s *thread = (interpreter_thread_s *)cmalloc(sizeof(interpreter_thread_s));
  thread->init();

  // - set thread pointer to interpreter -
  thread->interpreter_ptr = (pointer)this;

  // - set throw on terminate flag -
  thread->throw_on_terminate = true;

  // - creation of thread location for main thread -
  {
    thread_s *new_thread = (thread_s *)cmalloc(sizeof(thread_s));
    new_thread->init();

    new_thread->create_from_actual();

    location_s *new_location = thread->get_new_location_ptr();
    new_location->v_type = c_bi_class_thread;
    new_location->v_reference_cnt.atomic_set(1);
    new_location->v_data_ptr = (thread_s *)new_thread;

    thread->thread_location = (pointer)new_location;
  }

  // - creation of blank, and exception location for main thread -
  {
    location_s *new_location = thread->get_new_location_ptr();
    new_location->v_type = c_bi_class_blank;
    new_location->v_reference_cnt.atomic_set(2);

    thread->blank_location = (pointer)new_location;
    thread->exception_location = (pointer)new_location;
  }

  try
  {
    // - setting of stack for static code -
    if (stack_size != 0)
    {
      unsigned stack_size_cnt = stack_size;
      ((location_s *)thread->blank_location)->v_reference_cnt.atomic_add(stack_size_cnt);

      do
      {
        thread->data_stack.push(thread->blank_location);
      }
      while(--stack_size_cnt);
    }

    // - launch static begin code -
    thread->run_expression_code(static_begin_code.data,0,nullptr);
    if (((location_s *)thread->exception_location)->v_type != c_bi_class_blank)
    {
      // - print exception message -
      exception_s *exception_ptr = (exception_s *)((location_s *)thread->exception_location)->v_data_ptr;
      print_exception_message(*exception_ptr);
    }
    else
    {
      // - launch static run time code -
      thread->run_expression_code(static_run_time_code.data,0,nullptr);
      if (((location_s *)thread->exception_location)->v_type != c_bi_class_blank)
      {
        // - print exception message -
        exception_s *exception_ptr = (exception_s *)((location_s *)thread->exception_location)->v_data_ptr;
        print_exception_message(*exception_ptr);
      }
      else
      {
        thread->release_stack_from(0);

        // - set pointer to interpreter main thread -
        main_thread_ptr = thread;

        // - store position of location for return value at stack -
        ((location_s *)thread->blank_location)->v_reference_cnt.atomic_inc();
        thread->data_stack.push(thread->blank_location);

        // - pass arguments to main function -
        {
          pointer_array_s *array_ptr = thread->get_new_array_ptr();
          array_ptr->copy_resize(arg_list.used);

          if (arg_list.used != 0)
          {
            string_s *a_ptr = arg_list.data;
            string_s *a_ptr_end = a_ptr + arg_list.used;
            do {

              // - argument string -
              string_s *string_ptr = thread->get_new_string_ptr();
              string_ptr->swap(*a_ptr);

              // - location of argument string -
              location_s *new_location = thread->get_new_location_ptr();
              new_location->v_type = c_bi_class_string;
              new_location->v_reference_cnt.atomic_set(1);
              new_location->v_data_ptr = (string_s *)string_ptr;

              // - insertion of string location to argument array -
              array_ptr->push((pointer)new_location);

            } while(++a_ptr < a_ptr_end);
          }

          // - arguments array location -
          location_s *args_location = thread->get_new_location_ptr();
          args_location->v_type = c_bi_class_array;
          args_location->v_reference_cnt.atomic_set(1);
          args_location->v_data_ptr = (pointer_array_s *)array_ptr;

          thread->data_stack.push((pointer)args_location);
        }

        // - fill stack to size used by method -
        {
          unsigned stack_size_cnt = (method_record.stack_size + 1) - thread->data_stack.used;

          if (stack_size_cnt != 0)
          {
            ((location_s *)thread->blank_location)->v_reference_cnt.atomic_add(stack_size_cnt);

            do
            {
              thread->data_stack.push(thread->blank_location);
            }
            while(--stack_size_cnt);
          }
        }

        // - launch method begin code -
        thread->run_expression_code(method_record.begin_code.data,1,nullptr);
        if (((location_s *)thread->exception_location)->v_type != c_bi_class_blank)
        {
          // - print exception message -
          exception_s *exception_ptr = (exception_s *)((location_s *)thread->exception_location)->v_data_ptr;
          print_exception_message(*exception_ptr);
        }
        else
        {
          // - launch method run time code -
          thread->run_method_code(method_record,1,0);
          if (((location_s *)thread->exception_location)->v_type != c_bi_class_blank)
          {
            // - print exception message -
            exception_s *exception_ptr = (exception_s *)((location_s *)thread->exception_location)->v_data_ptr;
            print_exception_message(*exception_ptr);

            return_value = 125;
          }
          else
          {
            // - acquire location of return value -
            return_location = (location_s *)thread->get_stack_value(0);
            return_location->v_reference_cnt.atomic_inc();

            // - return only integer value, ignore others -
            if (return_location->v_type == c_bi_class_integer)
            {
              return_value = (long long int)return_location->v_data_ptr;
            }

            // - release location of return value -
            thread->release_location_ptr(return_location);
          }
        }
      }
    }
  }
  catch (int) {}

  // - reset throw on terminate flag -
  thread->throw_on_terminate = false;

  // - release location from stack -
  thread->release_stack_from(0);

  // - wait for end of all threads -
  while (thread_cnt.counter > 0)
  {
    thread_s::yield();
  }

  // - remove pointer to interpreter main thread -
  main_thread_ptr = nullptr;

  // - release thread locations -
  thread->release_location_ptr((location_s *)thread->thread_location);

  // - release thread blank and exception locations -
  thread->release_location_ptr((location_s *)thread->blank_location);
  thread->release_location_ptr((location_s *)thread->exception_location);

  // - remove othread description from memory -
  thread->free_variables_clear();
  thread->clear();
  cfree(thread);

  return return_value;
}/*}}}*/

/*
 * global functions
 */

void *new_thread_function(void *nt_start_info)
{/*{{{*/

#if defined(LINUX) && !defined(EMSCRIPTEN)
  sigset_t signal_set;

  // - set term signals to be blocked -
  sigemptyset(&signal_set);
  sigaddset(&signal_set,SIGINT);
  sigaddset(&signal_set,SIGTERM);
  sigaddset(&signal_set,SIGHUP);

  // - block term signals by this thread -
  cassert(pthread_sigmask(SIG_BLOCK,&signal_set,nullptr) == 0);
#endif

  // - acquire pointer to thread and its method -
  interpreter_thread_s *thread = (interpreter_thread_s *)(((pointer *)nt_start_info)[0]);
  method_record_s *method_record_ptr = (method_record_s *)(((pointer *)nt_start_info)[1]);
  cfree(nt_start_info);

  // - pointer to location of return value -
  location_s *return_location = nullptr;

  try
  {
    // - launch method begin code -
    thread->run_expression_code(method_record_ptr->begin_code.data,1,nullptr);
    if (((location_s *)thread->exception_location)->v_type != c_bi_class_blank)
    {
      // - print exception message -
      exception_s *exception_ptr = (exception_s *)((location_s *)thread->exception_location)->v_data_ptr;
      ((interpreter_s *)thread->interpreter_ptr)->print_exception_message(*exception_ptr);
    }
    else
    {
      // - launch method run time code -
      thread->run_method_code(*method_record_ptr,1,0);
      if (((location_s *)thread->exception_location)->v_type != c_bi_class_blank)
      {
        // - print exception message -
        exception_s *exception_ptr = (exception_s *)((location_s *)thread->exception_location)->v_data_ptr;
        ((interpreter_s *)thread->interpreter_ptr)->print_exception_message(*exception_ptr);
      }
      else
      {
        // - process thread return value -
        location_s *ret_location = (location_s *)thread->get_stack_value(0);

#if THREAD_LIB == THREAD_LIB_PTHREAD
        if (ret_location->v_type != c_bi_class_blank)
        {
          ret_location->v_reference_cnt.atomic_inc();
          return_location = ret_location;
        }
#endif
      }
    }
  }
  catch (int) {}

  // - reset throw on terminate flag -
  thread->throw_on_terminate = false;

  // - release locations from stack -
  thread->release_stack_from(0);

  // - release thread location -
  thread->release_location_ptr((location_s *)thread->thread_location);

  // - release thread blank and exception locations -
  thread->release_location_ptr((location_s *)thread->blank_location);
  thread->release_location_ptr((location_s *)thread->exception_location);

  // - decrease interpreter running threads -
  ((interpreter_s *)thread->interpreter_ptr)->thread_cnt.atomic_dec();

  // - remove thread description from memory -
  thread->free_variables_clear();
  thread->clear();
  cfree(thread);

#if THREAD_LIB == THREAD_LIB_PTHREAD
  return return_location;
#elif THREAD_LIB == THREAD_LIB_WINDOWS
  return 0;
#else
  cassert(0);
#endif
}/*}}}*/

