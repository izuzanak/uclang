
@begin
include "script_parser.h"
@end

// - callers of intermediate code generating functions -
const unsigned c_script_im_gen_action_cnt = 58;
bool(*script_im_callers[c_script_im_gen_action_cnt])(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this) =
{/*{{{*/
  im_elements_array,
  im_switch_test,
  im_slice_range,
  im_operator_binary_equal,
  im_operator_binary_plus_equal,
  im_operator_binary_minus_equal,
  im_operator_binary_asterisk_equal,
  im_operator_binary_slash_equal,
  im_operator_binary_percent_equal,
  im_operator_binary_double_ls_br_equal,
  im_operator_binary_double_rs_br_equal,
  im_operator_binary_ampersand_equal,
  im_operator_binary_pipe_equal,
  im_operator_binary_circumflex_equal,
  im_operator_binary_double_ampersand,
  im_operator_binary_double_pipe,
  im_operator_binary_ampersand,
  im_operator_binary_pipe,
  im_operator_binary_circumflex,
  im_operator_binary_double_equal,
  im_operator_binary_exclamation_equal,
  im_operator_binary_rs_br,
  im_operator_binary_ls_br,
  im_operator_binary_rs_br_equal,
  im_operator_binary_ls_br_equal,
  im_operator_binary_double_rs_br,
  im_operator_binary_double_ls_br,
  im_operator_binary_plus,
  im_operator_binary_minus,
  im_operator_binary_asterisk,
  im_operator_binary_slash,
  im_operator_binary_percent,
  im_operator_unary_post_double_plus,
  im_operator_unary_post_double_minus,
  im_operator_unary_pre_double_plus,
  im_operator_unary_pre_double_minus,
  im_operator_unary_pre_plus,
  im_operator_unary_pre_minus,
  im_operator_unary_pre_exclamation,
  im_operator_unary_pre_tilde,
  im_operator_binary_le_br_re_br,
  im_identifier,
  im_element_identifier,
  im_this_access,
  im_new_object,
  im_new_objects_array,
  im_free_object,
  im_type_identification,
  im_object_reference_copy,
  im_conditional_expression,
  im_class_access,
  im_object_member_select,
  im_this_method_call,
  im_object_method_call,
  im_const_char,
  im_const_int,
  im_const_float,
  im_const_string,
};/*}}}*/

/*
 * intermediate code generation macros
 */

#define IM_OPERATOR_UNARY(OP_NAME) \
  {/*{{{*/\
    im_descr_s &im = _this.im_descr;\
    \
    /* ***** */\
    \
    unsigned exp_node_idx = im.exp_node_stack.last();\
    \
    /* - set up method parameters - */\
    if (im.done_exp_nodes[exp_node_idx] == c_idx_not_exist) {\
      im.exp_node_stack.push(exp.nodes[exp_node_idx + 2]);\
      im.done_exp_nodes[exp_node_idx] = 1;\
    }\
    else {\
      /* - get temporary position for location of operator result - */\
      unsigned tmp_local_idx = im.free_stack_idxs.used != 0?im.free_stack_idxs.pop():im.stack_idx_max++;\
      \
      /* - process operator parameters - */\
      unsigned *op_ptr = im.operands.data + im.operand_stack.pop();\
      \
      if (*op_ptr & c_op_modifier_static_class) {\
        \
        /* - process static method call - */\
        class_record_s &class_record = _this.class_records[op_ptr[1]];\
        \
        unsigned method_ri = class_record.mnri_map.map_name(OP_NAME);\
        \
        /* - ERROR - */\
        if (method_ri == c_idx_not_exist) {\
          _this.error_code.push(ei_class_does_not_contain_method);\
          _this.error_code.push(exp.nodes[exp_node_idx + 1]);\
          _this.error_code.push(op_ptr[1]);\
          _this.error_code.push(OP_NAME);\
          \
          return false;\
        }\
        \
        method_record_s &method_record = _this.method_records[method_ri];\
        \
        /* - ERROR - */\
        if (!(method_record.modifiers & c_modifier_static)) {\
          _this.error_code.push(ei_static_reference_to_nonstatic_method);\
          _this.error_code.push(exp.nodes[exp_node_idx + 1]);\
          _this.error_code.push(method_ri);\
          \
          return false;\
        }\
        \
        /* - ERROR test if method is private, parent class must be im.class_idx - */\
        if ((method_record.modifiers & c_modifier_private) && (method_record.parent_record != im.class_idx)) {\
          _this.error_code.push(ei_cannot_access_private_method);\
          _this.error_code.push(exp.nodes[exp_node_idx + 1]);\
          _this.error_code.push(method_ri);\
          \
          return false;\
        }\
        \
        code.push(i_static_call);\
        code.push(0);\
        code.push(exp.nodes[exp_node_idx + 1]);\
        code.push(tmp_local_idx);\
        code.push(method_ri);\
      }\
      else {\
        \
        /* - process method call - */\
        code.push(i_call);\
        code.push(1);\
        code.push(OP_NAME);\
        code.push(c_idx_not_exist);\
        code.push(c_idx_not_exist);\
        code.push(exp.nodes[exp_node_idx + 1]);\
        code.push(tmp_local_idx);\
        \
        /* - ERROR - */\
        if (!(*op_ptr & c_op_modifier_object)) {\
          _this.error_code.push(ei_expected_object_as_operand);\
          _this.error_code.push(exp.nodes[exp_node_idx + 1]);\
          \
          return false;\
        }\
        \
        code.push(op_ptr[1]);\
        if (*op_ptr & c_op_modifier_tmp) {\
          im.free_stack_idxs.push(op_ptr[1]);\
        }\
      }\
      \
      /* - store position of operator result reference - */\
      im.operand_stack.push(im.operands.used);\
      im.operands.push(c_op_modifier_object | c_op_modifier_tmp);\
      im.operands.push(tmp_local_idx);\
      \
      im.exp_node_stack.used--;\
    }\
  }/*}}}*/

#define IM_OPERATOR_BINARY(OP_NAME) \
  {/*{{{*/\
    im_descr_s &im = _this.im_descr;\
    \
    /* ***** */\
    \
    unsigned exp_node_idx = im.exp_node_stack.last();\
    \
    /* - set up of method operators - */\
    if (im.done_exp_nodes[exp_node_idx] == c_idx_not_exist) {\
      unsigned *exp_node_ptr = exp.nodes.data + exp_node_idx;\
      \
      im.exp_node_stack.push(exp_node_ptr[3]);\
      im.exp_node_stack.push(exp_node_ptr[2]);\
      \
      im.done_exp_nodes[exp_node_idx] = 1;\
    }\
    else {\
      /* - get temporary location for operator result - */\
      unsigned tmp_local_idx = im.free_stack_idxs.used != 0?im.free_stack_idxs.pop():im.stack_idx_max++;\
      \
      /* - process operator parameters - */\
      unsigned *op2_ptr = im.operands.data + im.operand_stack.pop();\
      unsigned *op1_ptr = im.operands.data + im.operand_stack.pop();\
      \
      if (*op1_ptr & c_op_modifier_static_class) {\
        \
        /* - process static method call - */\
        class_record_s &class_record = _this.class_records[op1_ptr[1]];\
        \
        unsigned method_ri = class_record.mnri_map.map_name(OP_NAME);\
        \
        /* - ERROR - */\
        if (method_ri == c_idx_not_exist) {\
          _this.error_code.push(ei_class_does_not_contain_method);\
          _this.error_code.push(exp.nodes[exp_node_idx + 1]);\
          _this.error_code.push(op1_ptr[1]);\
          _this.error_code.push(OP_NAME);\
          \
          return false;\
        }\
        \
        method_record_s &method_record = _this.method_records[method_ri];\
        \
        /* - ERROR - */\
        if (!(method_record.modifiers & c_modifier_static)) {\
          _this.error_code.push(ei_static_reference_to_nonstatic_method);\
          _this.error_code.push(exp.nodes[exp_node_idx + 1]);\
          _this.error_code.push(method_ri);\
          \
          return false;\
        }\
        \
        /* - ERROR if method is private, then parent class must be im.class_idx - */\
        if ((method_record.modifiers & c_modifier_private) && (method_record.parent_record != im.class_idx)) {\
          _this.error_code.push(ei_cannot_access_private_method);\
          _this.error_code.push(exp.nodes[exp_node_idx + 1]);\
          _this.error_code.push(method_ri);\
          \
          return false;\
        }\
        \
        code.push(i_static_call);\
        code.push(1);\
        code.push(exp.nodes[exp_node_idx + 1]);\
        code.push(tmp_local_idx);\
        code.push(method_ri);\
      }\
      else {\
        \
        /* - process method call - */\
        code.push(i_call);\
        code.push(2);\
        code.push(OP_NAME);\
        code.push(c_idx_not_exist);\
        code.push(c_idx_not_exist);\
        code.push(exp.nodes[exp_node_idx + 1]);\
        code.push(tmp_local_idx);\
        \
        /* - ERROR - */\
        if (!(*op1_ptr & c_op_modifier_object)) {\
          _this.error_code.push(ei_expected_object_as_operand);\
          _this.error_code.push(exp.nodes[exp_node_idx + 1]);\
          \
          return false;\
        }\
        \
        code.push(op1_ptr[1]);\
        if (*op1_ptr & c_op_modifier_tmp) {\
          im.free_stack_idxs.push(op1_ptr[1]);\
        }\
      }\
      \
      /* - ERROR - */\
      if (!(*op2_ptr & c_op_modifier_object)) {\
        _this.error_code.push(ei_expected_object_as_operand);\
        _this.error_code.push(exp.nodes[exp_node_idx + 1]);\
        \
        return false;\
      }\
      \
      code.push(op2_ptr[1]);\
      if (*op2_ptr & c_op_modifier_tmp) {\
        im.free_stack_idxs.push(op2_ptr[1]);\
      }\
      \
      /* - store position of operator result reference - */\
      im.operand_stack.push(im.operands.used);\
      im.operands.push(c_op_modifier_object | c_op_modifier_tmp);\
      im.operands.push(tmp_local_idx);\
      \
      im.exp_node_stack.used--;\
    }\
  }/*}}}*/

#define IM_IDENTIFIER(ID_EXIST_TEST,STATIC_EXIST_TEST) \
  {/*{{{*/\
    class_records_s &class_records = _this.class_records;\
    method_records_s &method_records = _this.method_records;\
    variable_records_s &variable_records = _this.variable_records;\
    im_descr_s &im = _this.im_descr;\
    \
    /* ***** */\
    \
    unsigned exp_node_idx = im.exp_node_stack.last();\
    \
    unsigned id_name_idx = exp.nodes[exp_node_idx + 2];\
    unsigned id_idx;\
    \
    ID_EXIST_TEST\
    {\
      \
      if (im.code_modifiers & c_code_modifier_run_time)\
      {\
        \
        /* - test if identifier is method parameter - */\
        method_record_s &method_record = method_records[im.method_idx];\
        \
        if (method_record.parameter_record_idxs.used != 0)\
        {\
          unsigned *vri_ptr = method_record.parameter_record_idxs.data;\
          unsigned *vri_ptr_end = vri_ptr + method_record.parameter_record_idxs.used;\
          \
          do\
          {\
            if (variable_records[*vri_ptr].name_idx == id_name_idx)\
            {\
              \
              /* - get index of parameter in method - */\
              id_idx = vri_ptr - method_record.parameter_record_idxs.data;\
              \
              if (!(im.code_modifiers & c_code_modifier_static))\
              {\
                \
                /* - add one because of this parameter - */\
                id_idx += 1;\
              }\
              \
              /* - insertion of new operand describing identifier - */\
              im.var_name_fo_map[id_name_idx] = im.found_operands.used;\
              im.found_operands.push(c_op_modifier_object);\
              im.found_operands.push(id_idx);\
              \
              /* - store information about identifier to operand stack - */\
              im.operand_stack.push(im.operands.used);\
              im.operands.push(c_op_modifier_object);\
              im.operands.push(id_idx);\
              \
              break;\
            }\
          }\
          while(++vri_ptr < vri_ptr_end);\
        }\
      }\
      \
      if (id_idx == c_idx_not_exist)\
      {\
        \
        /* - test if identifier is member of class, or parent classes - */\
        unsigned cr_idx = im.class_idx;\
        \
        /* - loop trough nested classes - */\
        do\
        {\
          class_record_s &class_record = class_records[cr_idx];\
          ri_ep_s &ri_ep = class_record.vn_ri_ep_map.map_name(id_name_idx);\
          \
          id_idx = ri_ep.record_idx;\
          \
          if (id_idx != c_idx_not_exist)\
          {\
            \
            variable_record_s &variable_record = variable_records[ri_ep.record_idx];\
            \
            /* - ERROR test in static code must be used static variable - */\
            if ((im.code_modifiers & c_code_modifier_static) && !(variable_record.modifiers & c_modifier_static))\
            {\
              _this.error_code.push(ei_static_reference_to_nonstatic_variable);\
              _this.error_code.push(exp.nodes[exp_node_idx + 1]);\
              _this.error_code.push(ri_ep.record_idx);\
              \
              return false;\
            }\
            \
            /* - ERROR if variable is private, parent class index must be im.class_idx - */\
            if ((variable_record.modifiers & c_modifier_private) && (variable_record.parent_record != im.class_idx))\
            {\
              _this.error_code.push(ei_cannot_access_private_variable);\
              _this.error_code.push(exp.nodes[exp_node_idx + 1]);\
              _this.error_code.push(ri_ep.record_idx);\
              \
              return false;\
            }\
            \
            if (variable_record.modifiers & c_modifier_static)\
            {\
              /* - test if static variable is built in constant - */\
              if (variable_record.modifiers & c_modifier_static_const)\
              {\
                /* - store access to static constant - */\
                unsigned const_idx = ri_ep.element_position;\
                unsigned &cv_operand = im.const_idx_fo_map[const_idx];\
                \
                if (cv_operand == c_idx_not_exist)\
                {\
                  \
                  /* - creation of position on stack for reference on constant - */\
                  unsigned local_idx = im.stack_idx_max++;\
                  \
                  cv_operand = im.found_operands.used;\
                  im.found_operands.push(c_op_modifier_object);\
                  im.found_operands.push(local_idx);\
                  \
                  im.operand_stack.push(im.operands.used);\
                  im.operands.push(c_op_modifier_object);\
                  im.operands.push(local_idx);\
                  \
                  begin_code.push(i_const);\
                  begin_code.push(local_idx);\
                  begin_code.push(const_idx);\
                }\
                else\
                {\
                  im.operand_stack.push(im.operands.used);\
                  \
                  unsigned *fo_ptr = im.found_operands.data + cv_operand;\
                  im.operands.push(*fo_ptr);\
                  im.operands.push(fo_ptr[1]);\
                }\
              }\
              else\
              {\
                /* - process static variable - */\
                STATIC_EXIST_TEST\
                {\
                  \
                  /* - position of static variable on stack - */\
                  unsigned local_idx = im.stack_idx_max++;\
                  \
                  im.var_name_fo_map[id_name_idx] = im.found_operands.used;\
                  im.static_vi_fo_map[ri_ep.element_position] = im.found_operands.used;\
                  im.found_operands.push(c_op_modifier_object);\
                  im.found_operands.push(local_idx);\
                  \
                  begin_code.push(i_static);\
                  begin_code.push(exp.nodes[exp_node_idx + 1]);\
                  begin_code.push(local_idx);\
                  begin_code.push(ri_ep.element_position);\
                  \
                  /* - store reference describing static variable - */\
                  im.operand_stack.push(im.operands.used);\
                  im.operands.push(c_op_modifier_object);\
                  im.operands.push(local_idx);\
                }\
              }\
            }\
            else\
            {\
              \
              /* - access to nonstatic variable, only for this class - */\
              if (cr_idx == im.class_idx)\
              {\
                \
                /* - position of value at stack - */\
                unsigned local_idx = im.stack_idx_max++;\
                \
                /* - creation of new operand describing identifier - */\
                im.var_name_fo_map[id_name_idx] = im.found_operands.used;\
                im.found_operands.push(c_op_modifier_object);\
                im.found_operands.push(local_idx);\
                \
                /* - store informations about identifier to operand stack - */\
                im.operand_stack.push(im.operands.used);\
                im.operands.push(c_op_modifier_object);\
                im.operands.push(local_idx);\
                \
                /* - identifier is variable of actual (this) class - */\
                begin_code.push(i_this_element);\
                begin_code.push(exp.nodes[exp_node_idx + 1]);\
                begin_code.push(local_idx);\
                begin_code.push(id_name_idx);\
              }\
              else\
              {\
                \
                /* - clear identifier index - */\
                id_idx = c_idx_not_exist;\
                \
                /* - continue by next class - */\
                cr_idx = class_record.parent_record;\
                \
                continue;\
              }\
            }\
            \
            break;\
          }\
          \
          cr_idx = class_record.parent_record;\
          \
        }\
        while(cr_idx != c_idx_not_exist);\
      }\
      \
      /* - test if identifier is link to static class name - */\
      if (id_idx == c_idx_not_exist)\
      {\
        id_idx = _this.class_symbol_names.get_idx(_this.variable_symbol_names[id_name_idx]);\
        \
        if (id_idx != c_idx_not_exist)\
        {\
          \
          unsigned class_ri = _this.resolve_class_idx_by_name_idx(id_idx,im.class_idx);\
          \
          /* - ERROR - */\
          if (class_ri == c_idx_not_exist)\
          {\
            id_idx = c_idx_not_exist;\
          }\
          else\
          {\
            /* - insertion of new operand describing identifier - */\
            im.var_name_fo_map[id_name_idx] = im.found_operands.used;\
            im.found_operands.push(c_op_modifier_static_class);\
            im.found_operands.push(class_ri);\
            \
            /* - store information about identifier operand to operand stack - */\
            im.operand_stack.push(im.operands.used);\
            im.operands.push(c_op_modifier_static_class);\
            im.operands.push(class_ri);\
          }\
        }\
      }\
      \
      /* - creation of new local variable - */\
      if (id_idx == c_idx_not_exist)\
      {\
        \
        /* - ERROR code is not run time - */\
        if (!(im.code_modifiers & c_code_modifier_run_time))\
        {\
          _this.error_code.push(ei_variable_name_cannot_be_resolved);\
          _this.error_code.push(exp.nodes[exp_node_idx + 1]);\
          _this.error_code.push(id_name_idx);\
          \
          return false;\
        }\
        \
        /* - position of local variable at stack - */\
        unsigned local_idx = im.stack_idx_max++;\
        \
        /* - insertion of new operand describing identifier - */\
        im.var_name_fo_map[id_name_idx] = im.found_operands.used;\
        im.found_operands.push(c_op_modifier_object);\
        im.found_operands.push(local_idx);\
        \
        /* - store information about identifier operand to operand stack - */\
        im.operand_stack.push(im.operands.used);\
        im.operands.push(c_op_modifier_object);\
        im.operands.push(local_idx);\
      }\
    }\
    \
    im.exp_node_stack.used--;\
  }/*}}}*/

/*
 * functions implementing intermediate code generating actions of parser
 */

bool im_elements_array(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  im_descr_s &im = _this.im_descr;

  // *****

  unsigned exp_node_idx = im.exp_node_stack.last();
  unsigned element_cnt = exp.nodes[exp_node_idx + 2];

  if (im.done_exp_nodes[exp_node_idx] == c_idx_not_exist)
  {

    // - process object inserted to array -
    if (element_cnt != 0)
    {
      unsigned *m_ptr_end = exp.nodes.data + exp_node_idx + 2;
      unsigned *m_ptr = m_ptr_end + element_cnt;

      do
      {
        im.exp_node_stack.push(*m_ptr);
      }
      while(--m_ptr > m_ptr_end);
    }

    // - denote that node has been processed -
    im.done_exp_nodes[exp_node_idx] = 1;
  }
  else
  {

    // - get temporary location of array at stack -
    unsigned tmp_local_idx = im.free_stack_idxs.used != 0?im.free_stack_idxs.pop():im.stack_idx_max++;

    code.push(i_element_array);
    code.push(exp.nodes[exp_node_idx + 1]);
    code.push(element_cnt);
    code.push(tmp_local_idx);

    // - processing of operands inserted to array -
    if (element_cnt != 0)
    {
      unsigned *ops_ptr_end = im.operand_stack.data + im.operand_stack.used;
      unsigned *ops_ptr = ops_ptr_end - element_cnt;

      do
      {
        unsigned *op_ptr = im.operands.data + *ops_ptr;

        // - ERROR -
        if (!(*op_ptr & c_op_modifier_object))
        {
          _this.error_code.push(ei_expected_object_as_operand);
          _this.error_code.push(exp.nodes[exp_node_idx + 1]);

          return false;
        }

        code.push(op_ptr[1]);
        if (*op_ptr & c_op_modifier_tmp)
        {
          im.free_stack_idxs.push(op_ptr[1]);
        }
      }
      while(++ops_ptr < ops_ptr_end);

      im.operand_stack.used -= element_cnt;
    }

    // - insert operand denoting created array -
    im.operand_stack.push(im.operands.used);
    im.operands.push(c_op_modifier_object | c_op_modifier_tmp);
    im.operands.push(tmp_local_idx);

    im.exp_node_stack.used--;

    debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_elements_array\n"));
  }

  return true;
}/*}}}*/

bool im_switch_test(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  im_descr_s &im = _this.im_descr;

  // *****

  unsigned exp_node_idx = im.exp_node_stack.last();
  unsigned value_cnt = exp.nodes[exp_node_idx + 2];

  if (im.done_exp_nodes[exp_node_idx] == c_idx_not_exist)
  {

    // - process values to be tested -
    if (value_cnt != 0)
    {
      unsigned *v_ptr_end = exp.nodes.data + exp_node_idx + 2;
      unsigned *v_ptr = v_ptr_end + value_cnt;

      do
      {
        im.exp_node_stack.push(*v_ptr);
      }
      while(--v_ptr > v_ptr_end);
    }

    // - denote that node has been processed -
    im.done_exp_nodes[exp_node_idx] = 1;
  }
  else
  {

    // - get temporary location of result at stack -
    unsigned tmp_local_idx = im.free_stack_idxs.used != 0?im.free_stack_idxs.pop():im.stack_idx_max++;

    code.push(i_switch_test);
    code.push(exp.nodes[exp_node_idx + 1]);
    code.push(value_cnt);
    code.push(tmp_local_idx);

    // - processing of tested values -
    if (value_cnt != 0)
    {
      unsigned *ops_ptr_end = im.operand_stack.data + im.operand_stack.used;
      unsigned *ops_ptr = ops_ptr_end - value_cnt;

      do
      {
        unsigned *op_ptr = im.operands.data + *ops_ptr;

        // - ERROR -
        if (!(*op_ptr & c_op_modifier_object))
        {
          _this.error_code.push(ei_switch_expect_objects_as_operands);
          _this.error_code.push(exp.nodes[exp_node_idx + 1]);

          return false;
        }

        code.push(op_ptr[1]);
        if (*op_ptr & c_op_modifier_tmp)
        {
          im.free_stack_idxs.push(op_ptr[1]);
        }
      }
      while(++ops_ptr < ops_ptr_end);

      im.operand_stack.used -= value_cnt;
    }

    // - insert operand denoting created result -
    im.operand_stack.push(im.operands.used);
    im.operands.push(c_op_modifier_object | c_op_modifier_tmp);
    im.operands.push(tmp_local_idx);

    im.exp_node_stack.used--;

    debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_switch_test\n"));
  }

  return true;
}/*}}}*/

bool im_slice_range(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  im_descr_s &im = _this.im_descr;

  // *****

  unsigned exp_node_idx = im.exp_node_stack.last();
  const unsigned param_cnt = 4;

  if (im.done_exp_nodes[exp_node_idx] == c_idx_not_exist)
  {

    // - process slice range parameters -
    unsigned param_idx = exp_node_idx + 1 + param_cnt;

    im.exp_node_stack.push(exp.nodes[param_idx--]);
    im.exp_node_stack.push(exp.nodes[param_idx--]);
    im.exp_node_stack.push(exp.nodes[param_idx--]);
    im.exp_node_stack.push(exp.nodes[param_idx--]);

    // - denote that node has been processed -
    im.done_exp_nodes[exp_node_idx] = 1;
  }
  else
  {

    // - get temporary location of slice at stack -
    unsigned tmp_local_idx = im.free_stack_idxs.used != 0?im.free_stack_idxs.pop():im.stack_idx_max++;

    code.push(i_slice_range);
    code.push(exp.nodes[exp_node_idx + 1]);
    code.push(tmp_local_idx);

    // - processing of slice range parameters -
    unsigned *ops_ptr_end = im.operand_stack.data + im.operand_stack.used;
    unsigned *ops_ptr = ops_ptr_end - param_cnt;

    do
    {
      unsigned *op_ptr = im.operands.data + *ops_ptr;

      // - ERROR -
      if (!(*op_ptr & c_op_modifier_object))
      {
        _this.error_code.push(ei_expected_object_as_operand);
        _this.error_code.push(exp.nodes[exp_node_idx + 1]);

        return false;
      }

      code.push(op_ptr[1]);
      if (*op_ptr & c_op_modifier_tmp)
      {
        im.free_stack_idxs.push(op_ptr[1]);
      }
    }
    while(++ops_ptr < ops_ptr_end);

    im.operand_stack.used -= param_cnt;

    // - insert operand denoting created slice -
    im.operand_stack.push(im.operands.used);
    im.operands.push(c_op_modifier_object | c_op_modifier_tmp);
    im.operands.push(tmp_local_idx);

    im.exp_node_stack.used--;

    debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_slice_range\n"));
  }

  return true;
}/*}}}*/

bool im_operator_binary_equal(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_BINARY(c_built_in_method_idxs[c_operator_binary_equal]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_binary_equal\n"));

  return true;
}/*}}}*/

bool im_operator_binary_plus_equal(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_BINARY(c_built_in_method_idxs[c_operator_binary_plus_equal]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_binary_plus_equal\n"));

  return true;
}/*}}}*/

bool im_operator_binary_minus_equal(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_BINARY(c_built_in_method_idxs[c_operator_binary_minus_equal]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_binary_minus_equal\n"));

  return true;
}/*}}}*/

bool im_operator_binary_asterisk_equal(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_BINARY(c_built_in_method_idxs[c_operator_binary_asterisk_equal]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_binary_asterisk_equal\n"));

  return true;
}/*}}}*/

bool im_operator_binary_slash_equal(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_BINARY(c_built_in_method_idxs[c_operator_binary_slash_equal]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_binary_slash_equal\n"));

  return true;
}/*}}}*/

bool im_operator_binary_percent_equal(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_BINARY(c_built_in_method_idxs[c_operator_binary_percent_equal]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_binary_percent_equal\n"));

  return true;
}/*}}}*/

bool im_operator_binary_double_ls_br_equal(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_BINARY(c_built_in_method_idxs[c_operator_binary_double_ls_br_equal]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_binary_double_ls_br_equal\n"));

  return true;
}/*}}}*/

bool im_operator_binary_double_rs_br_equal(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_BINARY(c_built_in_method_idxs[c_operator_binary_double_rs_br_equal]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_binary_double_rs_br_equal\n"));

  return true;
}/*}}}*/

bool im_operator_binary_ampersand_equal(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_BINARY(c_built_in_method_idxs[c_operator_binary_ampersand_equal]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_binary_ampersand_equal\n"));

  return true;
}/*}}}*/

bool im_operator_binary_pipe_equal(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_BINARY(c_built_in_method_idxs[c_operator_binary_pipe_equal]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_binary_pipe_equal\n"));

  return true;
}/*}}}*/

bool im_operator_binary_circumflex_equal(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_BINARY(c_built_in_method_idxs[c_operator_binary_circumflex_equal]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_binary_circumflex_equal\n"));

  return true;
}/*}}}*/

bool im_operator_binary_double_ampersand(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_BINARY(c_built_in_method_idxs[c_operator_binary_double_ampersand]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_binary_double_ampersand\n"));

  return true;
}/*}}}*/

bool im_operator_binary_double_pipe(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_BINARY(c_built_in_method_idxs[c_operator_binary_double_pipe]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_binary_double_pipe\n"));

  return true;
}/*}}}*/

bool im_operator_binary_ampersand(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_BINARY(c_built_in_method_idxs[c_operator_binary_ampersand]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_binary_ampersand\n"));

  return true;
}/*}}}*/

bool im_operator_binary_pipe(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_BINARY(c_built_in_method_idxs[c_operator_binary_pipe]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_binary_pipe\n"));

  return true;
}/*}}}*/

bool im_operator_binary_circumflex(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_BINARY(c_built_in_method_idxs[c_operator_binary_circumflex]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_binary_circumflex\n"));

  return true;
}/*}}}*/

bool im_operator_binary_double_equal(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_BINARY(c_built_in_method_idxs[c_operator_binary_double_equal]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_binary_double_equal\n"));

  return true;
}/*}}}*/

bool im_operator_binary_exclamation_equal(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_BINARY(c_built_in_method_idxs[c_operator_binary_exclamation_equal]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_binary_exclamation_equal\n"));

  return true;
}/*}}}*/

bool im_operator_binary_rs_br(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_BINARY(c_built_in_method_idxs[c_operator_binary_rs_br]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_binary_rs_br\n"));

  return true;
}/*}}}*/

bool im_operator_binary_ls_br(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_BINARY(c_built_in_method_idxs[c_operator_binary_ls_br]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_binary_ls_br\n"));

  return true;
}/*}}}*/

bool im_operator_binary_rs_br_equal(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_BINARY(c_built_in_method_idxs[c_operator_binary_rs_br_equal]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_binary_rs_br_equal\n"));

  return true;
}/*}}}*/

bool im_operator_binary_ls_br_equal(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_BINARY(c_built_in_method_idxs[c_operator_binary_ls_br_equal]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_binary_ls_br_equal\n"));

  return true;
}/*}}}*/

bool im_operator_binary_double_rs_br(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_BINARY(c_built_in_method_idxs[c_operator_binary_double_rs_br]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_binary_double_rs_br\n"));

  return true;
}/*}}}*/

bool im_operator_binary_double_ls_br(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_BINARY(c_built_in_method_idxs[c_operator_binary_double_ls_br]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_binary_double_ls_br\n"));

  return true;
}/*}}}*/

bool im_operator_binary_plus(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_BINARY(c_built_in_method_idxs[c_operator_binary_plus]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_binary_plus\n"));

  return true;
}/*}}}*/

bool im_operator_binary_minus(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_BINARY(c_built_in_method_idxs[c_operator_binary_minus]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_binary_minus\n"));

  return true;
}/*}}}*/

bool im_operator_binary_asterisk(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_BINARY(c_built_in_method_idxs[c_operator_binary_asterisk]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_binary_asterisk\n"));

  return true;
}/*}}}*/

bool im_operator_binary_slash(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_BINARY(c_built_in_method_idxs[c_operator_binary_slash]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_binary_slash\n"));

  return true;
}/*}}}*/

bool im_operator_binary_percent(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_BINARY(c_built_in_method_idxs[c_operator_binary_percent]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_binary_percent\n"));

  return true;
}/*}}}*/

bool im_operator_unary_post_double_plus(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_UNARY(c_built_in_method_idxs[c_operator_unary_post_double_plus]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_unary_post_double_plus\n"));

  return true;
}/*}}}*/

bool im_operator_unary_post_double_minus(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_UNARY(c_built_in_method_idxs[c_operator_unary_post_double_minus]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_unary_post_double_minus\n"));

  return true;
}/*}}}*/

bool im_operator_unary_pre_double_plus(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_UNARY(c_built_in_method_idxs[c_operator_unary_pre_double_plus]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_unary_pre_double_plus\n"));

  return true;
}/*}}}*/

bool im_operator_unary_pre_double_minus(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_UNARY(c_built_in_method_idxs[c_operator_unary_pre_double_minus]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_unary_pre_double_minus\n"));

  return true;
}/*}}}*/

bool im_operator_unary_pre_plus(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_UNARY(c_built_in_method_idxs[c_operator_unary_pre_plus]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_unary_pre_plus\n"));

  return true;
}/*}}}*/

bool im_operator_unary_pre_minus(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_UNARY(c_built_in_method_idxs[c_operator_unary_pre_minus]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_unary_pre_minus\n"));

  return true;
}/*}}}*/

bool im_operator_unary_pre_exclamation(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_UNARY(c_built_in_method_idxs[c_operator_unary_pre_exclamation]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_unary_pre_exclamation\n"));

  return true;
}/*}}}*/

bool im_operator_unary_pre_tilde(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_UNARY(c_built_in_method_idxs[c_operator_unary_pre_tilde]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_unary_pre_tilde\n"));

  return true;
}/*}}}*/

bool im_operator_binary_le_br_re_br(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_OPERATOR_BINARY(c_built_in_method_idxs[c_operator_binary_le_br_re_br]);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_operator_binary_le_br_re_br\n"));

  return true;
}/*}}}*/

bool im_identifier(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_IDENTIFIER(
    if ((id_idx = im.var_name_fo_map[id_name_idx]) != c_idx_not_exist)
{
  /* - identifier has been recognized -> store its operand to operand stack - */
  im.operand_stack.push(im.operands.used);

    unsigned *fo_ptr = im.found_operands.data + id_idx;
    im.operands.push(*fo_ptr);
    im.operands.push(fo_ptr[1]);
  }
  else
    ,
    unsigned fo_idx = im.static_vi_fo_map[ri_ep.element_position];
                      if (fo_idx != c_idx_not_exist)
  {
    /* - static variable has been recognized - */
    im.var_name_fo_map[id_name_idx] = fo_idx;

      /* - store operator describing static variable on stack - */
      im.operand_stack.push(im.operands.used);

      unsigned *fo_ptr = im.found_operands.data + fo_idx;
      im.operands.push(*fo_ptr);
      im.operands.push(fo_ptr[1]);
    }
    else
      );

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_identifier\n"));

  return true;
}/*}}}*/

bool im_element_identifier(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  IM_IDENTIFIER(id_idx = c_idx_not_exist; ,);

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_element_identifier\n"));

  return true;
}/*}}}*/

bool im_this_access(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  im_descr_s &im = _this.im_descr;

  // *****

  // - ERROR test this reference in static code -
  if (im.code_modifiers & c_code_modifier_static)
  {
    _this.error_code.push(ei_cannot_use_this_in_static_code);
    _this.error_code.push(exp.nodes[im.exp_node_stack.last() + 1]);

    return false;
  }

  im.operand_stack.push(im.operands.used);

  // - reference to this is always at zero position on stack -
  im.operands.push(c_op_modifier_object);
  im.operands.push(0);

  im.exp_node_stack.used--;

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_this_access\n"));

  return true;
}/*}}}*/

bool im_new_object(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  class_records_s &class_records = _this.class_records;
  im_descr_s &im = _this.im_descr;

  // *****

  unsigned exp_node_idx = im.exp_node_stack.last();
  unsigned parm_cnt = exp.nodes[exp_node_idx + 4];

  if (im.done_exp_nodes[exp_node_idx] == c_idx_not_exist)
  {

    // - process constructor parameters -
    if (parm_cnt != 0)
    {
      unsigned *m_ptr_end = exp.nodes.data + exp_node_idx + 4;
      unsigned *m_ptr = m_ptr_end + parm_cnt;

      do
      {
        im.exp_node_stack.push(*m_ptr);
      }
      while(--m_ptr > m_ptr_end);
    }

    // - mark node as processed -
    im.done_exp_nodes[exp_node_idx] = 1;
  }
  else
  {

    // - get temporary stack location for reference to new object -
    unsigned tmp_local_idx = im.free_stack_idxs.used != 0?im.free_stack_idxs.pop():im.stack_idx_max++;

    // - get class record index by class name -
    unsigned class_record_idx = _this.resolve_class_idx_by_name_idx(exp.nodes[exp_node_idx + 2],im.class_idx);

    // - ERROR class name can not be resolved -
    if (class_record_idx == c_idx_not_exist)
    {
      _this.error_code.push(ei_class_name_cannot_be_resolved);
      _this.error_code.push(exp.nodes[exp_node_idx + 1]);
      _this.error_code.push(exp.nodes[exp_node_idx + 2]);

      return false;
    }

    class_record_s &class_record = class_records[class_record_idx];
    unsigned method_ri = class_record.mnri_map.map_name(exp.nodes[exp_node_idx + 3]);

    // - ERROR -
    if (method_ri == c_idx_not_exist)
    {
      _this.error_code.push(ei_class_does_not_have_constructor);
      _this.error_code.push(exp.nodes[exp_node_idx + 1]);
      _this.error_code.push(class_record_idx);
      _this.error_code.push(exp.nodes[exp_node_idx + 3]);

      return false;
    }

    // - ERROR class is defined as abstract -
    if (class_record.modifiers & c_modifier_abstract)
    {
      _this.error_code.push(ei_cannot_create_abstract_class_object);
      _this.error_code.push(exp.nodes[exp_node_idx + 1]);
      _this.error_code.push(class_record_idx);
    }

    code.push(i_new_object);
    code.push(parm_cnt);
    code.push(class_record_idx);
    code.push(exp.nodes[exp_node_idx + 1]);
    code.push(exp.nodes[exp_node_idx + 3]);
    code.push(tmp_local_idx);

    // - process object constructor parameters -
    if (parm_cnt != 0)
    {
      unsigned *ops_ptr_end = im.operand_stack.data + im.operand_stack.used;
      unsigned *ops_ptr = ops_ptr_end - parm_cnt;

      do
      {
        unsigned *op_ptr = im.operands.data + *ops_ptr;

        // - ERROR -
        if (!(*op_ptr & c_op_modifier_object))
        {
          _this.error_code.push(ei_expected_object_as_operand);
          _this.error_code.push(exp.nodes[exp_node_idx + 1]);

          return false;
        }

        code.push(op_ptr[1]);
        if (*op_ptr & c_op_modifier_tmp)
        {
          im.free_stack_idxs.push(op_ptr[1]);
        }
      }
      while(++ops_ptr < ops_ptr_end);

      im.operand_stack.used -= parm_cnt;
    }

    // - store operand of new object -
    im.operand_stack.push(im.operands.used);

    im.operands.push(c_op_modifier_object | c_op_modifier_tmp);
    im.operands.push(tmp_local_idx);

    im.exp_node_stack.used--;
  }

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_new_object\n"));

  return true;
}/*}}}*/

bool im_new_objects_array(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  class_records_s &class_records = _this.class_records;
  im_descr_s &im = _this.im_descr;

  // *****

  unsigned exp_node_idx = im.exp_node_stack.last();

  if (im.done_exp_nodes[exp_node_idx] == c_idx_not_exist)
  {

    // - process location describing size of object array -
    im.exp_node_stack.push(exp.nodes[exp_node_idx + 4]);
    im.done_exp_nodes[exp_node_idx] = 1;
  }
  else
  {

    // - get temporary location for store of location of reference to object array -
    unsigned tmp_local_idx = im.free_stack_idxs.used != 0?im.free_stack_idxs.pop():im.stack_idx_max++;

    // - get class record index by class name -
    unsigned class_record_idx = _this.resolve_class_idx_by_name_idx(exp.nodes[exp_node_idx + 2],im.class_idx);

    // - ERROR class cannot be resolved -
    if (class_record_idx == c_idx_not_exist)
    {
      _this.error_code.push(ei_class_name_cannot_be_resolved);
      _this.error_code.push(exp.nodes[exp_node_idx + 1]);
      _this.error_code.push(exp.nodes[exp_node_idx + 2]);

      return false;
    }

    class_record_s &class_record = class_records[class_record_idx];
    unsigned method_ri = class_record.mnri_map.map_name(exp.nodes[exp_node_idx + 3]);

    // - ERROR -
    if (method_ri == c_idx_not_exist)
    {
      _this.error_code.push(ei_class_does_not_have_constructor);
      _this.error_code.push(exp.nodes[exp_node_idx + 1]);
      _this.error_code.push(class_record_idx);
      _this.error_code.push(exp.nodes[exp_node_idx + 3]);

      return false;
    }

    // - ERROR class is defined as abstract -
    if (class_record.modifiers & c_modifier_abstract)
    {
      _this.error_code.push(ei_cannot_create_abstract_class_object);
      _this.error_code.push(exp.nodes[exp_node_idx + 1]);

      return false;
    }

    code.push(i_new_objects_array);
    code.push(exp.nodes[exp_node_idx + 1]);
    code.push(tmp_local_idx);
    code.push(class_record_idx);
    code.push(exp.nodes[exp_node_idx + 3]);

    // - process operator describing reference to variable containing array size -
    unsigned *op_ptr = im.operands.data + im.operand_stack.pop();

    // - ERROR -
    if (!(*op_ptr & c_op_modifier_object))
    {
      _this.error_code.push(ei_expected_object_as_operand);
      _this.error_code.push(exp.nodes[exp_node_idx + 1]);

      return false;
    }

    code.push(op_ptr[1]);
    if (*op_ptr & c_op_modifier_tmp)
    {
      im.free_stack_idxs.push(op_ptr[1]);
    }

    // - store location of object array -
    im.operand_stack.push(im.operands.used);
    im.operands.push(c_op_modifier_object | c_op_modifier_tmp);
    im.operands.push(tmp_local_idx);

    im.exp_node_stack.used--;
  }

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_objects_array\n"));

  return true;
}/*}}}*/

bool im_free_object(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  im_descr_s &im = _this.im_descr;

  // *****

  unsigned exp_node_idx = im.exp_node_stack.last();

  // - set up object -
  if (im.done_exp_nodes[exp_node_idx] == c_idx_not_exist)
  {

    // - process expression nodes describing tested object -
    im.exp_node_stack.push(exp.nodes[exp_node_idx + 2]);
    im.done_exp_nodes[exp_node_idx] = 1;
  }
  else
  {

    // - process freed object -
    unsigned *op_ptr = im.operands.data + im.operand_stack.pop();

    // - get temporary position of result location -
    unsigned tmp_local_idx = im.free_stack_idxs.used != 0?im.free_stack_idxs.pop():im.stack_idx_max++;

    // - free object instruction -
    code.push(i_free_object);
    code.push(tmp_local_idx);

    // - ERROR -
    if (!(*op_ptr & c_op_modifier_object))
    {
      _this.error_code.push(ei_expected_object_as_operand);
      _this.error_code.push(exp.nodes[exp_node_idx + 1]);

      return false;
    }

    code.push(op_ptr[1]);
    if (*op_ptr & c_op_modifier_tmp)
    {
      im.free_stack_idxs.push(op_ptr[1]);
    }

    // - store position of data type -
    im.operand_stack.push(im.operands.used);
    im.operands.push(c_op_modifier_object | c_op_modifier_tmp);
    im.operands.push(tmp_local_idx);

    im.exp_node_stack.used--;
  }

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_free_object\n"));

  return true;
}/*}}}*/

bool im_type_identification(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  im_descr_s &im = _this.im_descr;

  // *****

  unsigned exp_node_idx = im.exp_node_stack.last();

  // - set up of object -
  if (im.done_exp_nodes[exp_node_idx] == c_idx_not_exist)
  {

    // - process expression nodes describing tested object -
    im.exp_node_stack.push(exp.nodes[exp_node_idx + 1]);
    im.done_exp_nodes[exp_node_idx] = 1;
  }
  else
  {

    // - process tested object -
    unsigned *op_ptr = im.operands.data + im.operand_stack.pop();

    if (*op_ptr & c_op_modifier_static_class)
    {

      // - access to constant type value -
      unsigned const_idx = im.cv_type_base + op_ptr[1];
      unsigned &cv_operand = im.const_idx_fo_map[const_idx];

      if (cv_operand == c_idx_not_exist)
      {

        // - get position for reference to constant -
        unsigned local_idx = im.stack_idx_max++;

        cv_operand = im.found_operands.used;
        im.found_operands.push(c_op_modifier_object);
        im.found_operands.push(local_idx);

        im.operand_stack.push(im.operands.used);
        im.operands.push(c_op_modifier_object);
        im.operands.push(local_idx);

        begin_code.push(i_const);
        begin_code.push(local_idx);
        begin_code.push(const_idx);
      }
      else
      {
        im.operand_stack.push(im.operands.used);

        unsigned *fo_ptr = im.found_operands.data + cv_operand;
        im.operands.push(*fo_ptr);
        im.operands.push(fo_ptr[1]);
      }
    }
    else
    {

      // - get temporary position of result location -
      unsigned tmp_local_idx = im.free_stack_idxs.used != 0?im.free_stack_idxs.pop():im.stack_idx_max++;

      // - identification of object type -
      code.push(i_type_identification);
      code.push(tmp_local_idx);

      // - ERROR -
      if (!(*op_ptr & c_op_modifier_object))
      {
        _this.error_code.push(ei_expected_object_as_operand);
        _this.error_code.push(exp.nodes[exp_node_idx + 1]);

        return false;
      }

      code.push(op_ptr[1]);
      if (*op_ptr & c_op_modifier_tmp)
      {
        im.free_stack_idxs.push(op_ptr[1]);
      }

      // - store position of data type -
      im.operand_stack.push(im.operands.used);
      im.operands.push(c_op_modifier_object | c_op_modifier_tmp);
      im.operands.push(tmp_local_idx);
    }

    im.exp_node_stack.used--;
  }

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_type_identification\n"));

  return true;
}/*}}}*/

bool im_object_reference_copy(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  im_descr_s &im = _this.im_descr;

  // *****

  unsigned exp_node_idx = im.exp_node_stack.last();

  // - set up of object operand -
  if (im.done_exp_nodes[exp_node_idx] == c_idx_not_exist)
  {
    unsigned *exp_node_ptr = exp.nodes.data + exp_node_idx;

    im.exp_node_stack.push(exp_node_ptr[2]);
    im.exp_node_stack.push(exp_node_ptr[1]);

    im.done_exp_nodes[exp_node_idx] = 1;
  }
  else
  {

    // - get temporary location position -
    unsigned tmp_local_idx = im.free_stack_idxs.used != 0?im.free_stack_idxs.pop():im.stack_idx_max++;

    // - process two location operands -
    unsigned *op2_ptr = im.operands.data + im.operand_stack.pop();
    unsigned *op1_ptr = im.operands.data + im.operand_stack.pop();

    code.push(i_object_reference_copy);
    code.push(tmp_local_idx);

    // - ERROR -
    if (!(*op1_ptr & c_op_modifier_object))
    {
      _this.error_code.push(ei_expected_object_as_operand);
      _this.error_code.push(exp.nodes[exp_node_idx + 1]);

      return false;
    }

    code.push(op1_ptr[1]);
    if (*op1_ptr & c_op_modifier_tmp)
    {
      im.free_stack_idxs.push(op1_ptr[1]);
    }

    // - ERROR -
    if (!(*op2_ptr & c_op_modifier_object))
    {
      _this.error_code.push(ei_expected_object_as_operand);
      _this.error_code.push(exp.nodes[exp_node_idx + 1]);

      return false;
    }

    code.push(op2_ptr[1]);
    if (*op2_ptr & c_op_modifier_tmp)
    {
      im.free_stack_idxs.push(op2_ptr[1]);
    }

    // - store reference position -
    im.operand_stack.push(im.operands.used);
    im.operands.push(c_op_modifier_object | c_op_modifier_tmp);
    im.operands.push(tmp_local_idx);

    im.exp_node_stack.used--;
  }

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_object_reference_copy\n"));

  return true;
}/*}}}*/

bool im_conditional_expression(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  im_descr_s &im = _this.im_descr;

  // *****

  unsigned exp_node_idx = im.exp_node_stack.last();
  unsigned &exp_node_done = im.done_exp_nodes[exp_node_idx];

  // - set up tested value -
  if (exp_node_done == c_idx_not_exist)
  {
    // - process expression nodes describing tested value -
    im.exp_node_stack.push(exp.nodes[exp_node_idx + 2]);
    exp_node_done = 1;
  }
  else
  {
    switch (exp_node_done)
    {
    case 1:
    {
      // - store test code index -
      im.cond_exp_code_idxs.push(code.used);

      // - process tested value -
      unsigned *op_ptr = im.operands.data + im.operand_stack.pop();

      code.push(i_conditional_expression);
      code.push(exp.nodes[exp_node_idx + 1]);
      code.push(c_idx_not_exist);

      // - ERROR -
      if (!(*op_ptr & c_op_modifier_object))
      {
        _this.error_code.push(ei_expected_object_as_operand);
        _this.error_code.push(exp.nodes[exp_node_idx + 1]);

        return false;
      }

      code.push(op_ptr[1]);
      if (*op_ptr & c_op_modifier_tmp)
      {
        im.free_stack_idxs.push(op_ptr[1]);
      }

      // - generated indexes of expression codes -
      code.push(c_idx_not_exist);
      code.push(c_idx_not_exist);

      // - process expression nodes describing first expression -
      im.exp_node_stack.push(exp.nodes[exp_node_idx + 3]);
      exp_node_done = 2;
    }
    break;

    case 2:
    {
      // - process first expression return value -
      unsigned *op_ptr = im.operands.data + im.operand_stack.pop();

      // - ERROR -
      if (!(*op_ptr & c_op_modifier_object))
      {
        _this.error_code.push(ei_expected_object_as_operand);
        _this.error_code.push(exp.nodes[exp_node_idx + 1]);

        return false;
      }

      // - generate return code -
      code.push(i_return);
      code.push(op_ptr[1]);
      if (*op_ptr & c_op_modifier_tmp)
      {
        im.free_stack_idxs.push(op_ptr[1]);
      }

      // - retrieve test code index -
      unsigned code_idx = im.cond_exp_code_idxs.last();

      // - store second expression offset -
      code[code_idx + ice_second_exp] = code.used - code_idx;

      // - process expression nodes describing second expression -
      im.exp_node_stack.push(exp.nodes[exp_node_idx + 4]);
      exp_node_done = 3;
    }
    break;

    case 3:
    {
      // - process second expression return value -
      unsigned *op_ptr = im.operands.data + im.operand_stack.pop();

      // - ERROR -
      if (!(*op_ptr & c_op_modifier_object))
      {
        _this.error_code.push(ei_expected_object_as_operand);
        _this.error_code.push(exp.nodes[exp_node_idx + 1]);

        return false;
      }

      // - generate return code -
      code.push(i_return);
      code.push(op_ptr[1]);
      if (*op_ptr & c_op_modifier_tmp)
      {
        im.free_stack_idxs.push(op_ptr[1]);
      }

      // - retrieve and remove test code index -
      unsigned code_idx = im.cond_exp_code_idxs.pop();

      // - store second expression offset -
      code[code_idx + ice_end] = code.used - code_idx;

      // - get temporary location for store of object member location -
      unsigned tmp_local_idx = im.free_stack_idxs.used != 0?im.free_stack_idxs.pop():im.stack_idx_max++;
      code[code_idx + ice_stack_trg] = tmp_local_idx;

      // - store position of conditional expression result reference -
      im.operand_stack.push(im.operands.used);
      im.operands.push(c_op_modifier_object | c_op_modifier_tmp);
      im.operands.push(tmp_local_idx);

      im.exp_node_stack.used--;
    }
    break;

    default:
      cassert(0);
    }
  }

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_conditional_expression\n"));

  return true;
}/*}}}*/

bool im_class_access(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  im_descr_s &im = _this.im_descr;

  // *****

  unsigned exp_node_idx = im.exp_node_stack.last();

  // - retrieve count of names -
  unsigned name_cnt = exp.nodes[exp_node_idx + 2];

  // - class record index -
  unsigned class_ri;

  // - class name with preceding namespaces -
  if (name_cnt > 1)
  {
    // - retrieve namespace record index -
    unsigned namespace_ri = _this.resolve_namespace_idx_by_name_idx(exp.nodes[exp_node_idx + 3]);

    // - ERROR -
    if (namespace_ri == c_idx_not_exist)
    {
      _this.error_code.push(ei_namespace_name_cannot_be_resolved);
      _this.error_code.push(exp.nodes[exp_node_idx + 1]);
      _this.error_code.push(exp.nodes[exp_node_idx + 3]);

      return false;
    }

    unsigned *name_ptr = exp.nodes.data + exp_node_idx + 4;

    if (name_cnt > 2)
    {
      unsigned *name_ptr_end = name_ptr + name_cnt - 2;
      do {

        // - retrieve next namespace record index -
        namespace_ri = _this.get_parent_namespace_namespace_idx_by_name_idx(*name_ptr,namespace_ri);

        // - ERROR -
        if (namespace_ri == c_idx_not_exist)
        {
          _this.error_code.push(ei_namespace_name_cannot_be_resolved);
          _this.error_code.push(exp.nodes[exp_node_idx + 1]);
          _this.error_code.push(*name_ptr);

          return false;
        }

      } while(++name_ptr < name_ptr_end);
    }

    // - retrieve class record index -
    class_ri = _this.get_parent_namespace_class_idx_by_name_idx(*name_ptr,namespace_ri);
  }

  // - only class name -
  else
  {
    // - retrieve class record index -
    class_ri = _this.resolve_class_idx_by_name_idx(exp.nodes[exp_node_idx + 3],im.class_idx);
  }

  // - ERROR -
  if (class_ri == c_idx_not_exist)
  {
    _this.error_code.push(ei_class_name_cannot_be_resolved);
    _this.error_code.push(exp.nodes[exp_node_idx + 1]);
    _this.error_code.push(exp.nodes[exp_node_idx + 2 + name_cnt]);

    return false;
  }

  // - store static reference to class -
  im.operand_stack.push(im.operands.used);
  im.operands.push(c_op_modifier_static_class);
  im.operands.push(class_ri);

  im.exp_node_stack.used--;

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_class_access\n"));

  return true;
}/*}}}*/

bool im_object_member_select(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  im_descr_s &im = _this.im_descr;

  // *****

  unsigned exp_node_idx = im.exp_node_stack.last();

  if (im.done_exp_nodes[exp_node_idx] == c_idx_not_exist)
  {

    // - process object location -
    im.exp_node_stack.push(exp.nodes[exp_node_idx + 3]);
    im.done_exp_nodes[exp_node_idx] = 2;
  }
  else
  {

    // - process position of object reference -
    unsigned *op_ptr = im.operands.data + im.operand_stack.pop();

    if (*op_ptr & c_op_modifier_static_class)
    {

      // - process static variable -
      class_record_s &class_record = _this.class_records[op_ptr[1]];

      ri_ep_s &element_ri_ep = class_record.vn_ri_ep_map.map_name(exp.nodes[exp_node_idx + 2]);

      // - ERROR -
      if (element_ri_ep.record_idx == c_idx_not_exist)
      {
        _this.error_code.push(ei_class_does_not_contain_variable);
        _this.error_code.push(exp.nodes[exp_node_idx + 1]);
        _this.error_code.push(op_ptr[1]);
        _this.error_code.push(exp.nodes[exp_node_idx + 2]);

        return false;
      }

      // - test if variable is static -
      variable_record_s &variable_record = _this.variable_records[element_ri_ep.record_idx];

      // - ERROR -
      if (!(variable_record.modifiers & c_modifier_static))
      {
        _this.error_code.push(ei_static_reference_to_nonstatic_variable);
        _this.error_code.push(exp.nodes[exp_node_idx + 1]);
        _this.error_code.push(element_ri_ep.record_idx);

        return false;
      }

      // - ERROR if variable is private, parent_record must be im.class_idx -
      if ((variable_record.modifiers & c_modifier_private) && (variable_record.parent_record != im.class_idx))
      {
        _this.error_code.push(ei_cannot_access_private_variable);
        _this.error_code.push(exp.nodes[exp_node_idx + 1]);
        _this.error_code.push(element_ri_ep.record_idx);

        return false;
      }

      // - test if static variable is built in variable -
      if (variable_record.modifiers & c_modifier_static_const)
      {

        // - access to built in static constant -
        unsigned const_idx = element_ri_ep.element_position;
        unsigned &cv_operand = im.const_idx_fo_map[const_idx];

        if (cv_operand == c_idx_not_exist)
        {

          // - creation of position for reference to constant -
          unsigned local_idx = im.stack_idx_max++;

          cv_operand = im.found_operands.used;
          im.found_operands.push(c_op_modifier_object);
          im.found_operands.push(local_idx);

          im.operand_stack.push(im.operands.used);
          im.operands.push(c_op_modifier_object);
          im.operands.push(local_idx);

          begin_code.push(i_const);
          begin_code.push(local_idx);
          begin_code.push(const_idx);
        }
        else
        {
          im.operand_stack.push(im.operands.used);

          unsigned *fo_ptr = im.found_operands.data + cv_operand;
          im.operands.push(*fo_ptr);
          im.operands.push(fo_ptr[1]);
        }
      }
      else
      {

        // - process static variable -
        unsigned fo_idx = im.static_vi_fo_map[element_ri_ep.element_position];
        if (fo_idx != c_idx_not_exist)
        {
          im.operand_stack.push(im.operands.used);

          unsigned *fo_ptr = im.found_operands.data + fo_idx;
          im.operands.push(*fo_ptr);
          im.operands.push(fo_ptr[1]);
        }
        else
        {

          // - get temporary location for store of static variable -
          unsigned local_idx = im.stack_idx_max++;

          im.static_vi_fo_map[element_ri_ep.element_position] = im.found_operands.used;
          im.found_operands.push(c_op_modifier_object);
          im.found_operands.push(local_idx);

          begin_code.push(i_static);
          begin_code.push(exp.nodes[exp_node_idx + 1]);
          begin_code.push(local_idx);
          begin_code.push(element_ri_ep.element_position);

          // - store reference describing variable position -
          im.operand_stack.push(im.operands.used);
          im.operands.push(c_op_modifier_object);
          im.operands.push(local_idx);
        }
      }
    }
    else
    {
      // - get temporary location for store of object member location -
      unsigned tmp_local_idx = im.free_stack_idxs.used != 0?im.free_stack_idxs.pop():im.stack_idx_max++;

      // - access to object member -
      code.push(i_object_member_select);
      code.push(exp.nodes[exp_node_idx + 1]);
      code.push(tmp_local_idx);
      code.push(exp.nodes[exp_node_idx + 2]);

      // - ERROR -
      if (!(*op_ptr & c_op_modifier_object))
      {
        _this.error_code.push(ei_expected_object_as_operand);
        _this.error_code.push(exp.nodes[exp_node_idx + 1]);

        return false;
      }

      code.push(op_ptr[1]);
      if (*op_ptr & c_op_modifier_tmp)
      {
        im.free_stack_idxs.push(op_ptr[1]);
      }

      // - store reference to object member -
      im.operand_stack.push(im.operands.used);
      im.operands.push(c_op_modifier_object | c_op_modifier_tmp);
      im.operands.push(tmp_local_idx);
    }

    im.exp_node_stack.used--;
  }

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_object_member_select\n"));

  return true;
}/*}}}*/

bool im_this_method_call(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  im_descr_s &im = _this.im_descr;

  // *****

  unsigned exp_node_idx = im.exp_node_stack.last();
  unsigned parm_cnt = exp.nodes[exp_node_idx + 3];

  if (im.done_exp_nodes[exp_node_idx] == c_idx_not_exist)
  {

    // - process expression node describing method parameters -
    if (parm_cnt != 0)
    {
      unsigned *m_ptr_end = exp.nodes.data + exp_node_idx + 3;
      unsigned *m_ptr = m_ptr_end + parm_cnt;

      do
      {
        im.exp_node_stack.push(*m_ptr);
      }
      while(--m_ptr > m_ptr_end);
    }

    im.done_exp_nodes[exp_node_idx] = 1;
  }
  else
  {

    // - get temporary position for store of method return value -
    unsigned tmp_local_idx = im.free_stack_idxs.used != 0?im.free_stack_idxs.pop():im.stack_idx_max++;

    class_record_s &class_record = _this.class_records[im.class_idx];
    unsigned method_ri = class_record.mnri_map.map_name(exp.nodes[exp_node_idx + 2]);

    // - ERROR -
    if (method_ri == c_idx_not_exist)
    {
      _this.error_code.push(ei_class_does_not_contain_method);
      _this.error_code.push(exp.nodes[exp_node_idx + 1]);
      _this.error_code.push(im.class_idx);
      _this.error_code.push(exp.nodes[exp_node_idx + 2]);

      return false;
    }

    method_record_s &method_record = _this.method_records[method_ri];

    // - ERROR if code is static, called method must be static too -
    if ((im.code_modifiers & c_code_modifier_static) && !(method_record.modifiers & c_modifier_static))
    {
      _this.error_code.push(ei_static_reference_to_nonstatic_method);
      _this.error_code.push(exp.nodes[exp_node_idx + 1]);
      _this.error_code.push(method_ri);

      return false;
    }

    // - test if called method is static -
    if (method_record.modifiers & c_modifier_static)
    {

      // - calling of static method -
      code.push(i_static_call);
      code.push(parm_cnt);
      code.push(exp.nodes[exp_node_idx + 1]);
      code.push(tmp_local_idx);
      code.push(method_ri);
    }
    else
    {

      // - calling of ordinary method -
      code.push(i_call);
      code.push(parm_cnt + 1);
      code.push(exp.nodes[exp_node_idx + 2]);
      code.push(c_idx_not_exist);
      code.push(c_idx_not_exist);
      code.push(exp.nodes[exp_node_idx + 1]);
      code.push(tmp_local_idx);
      code.push(0);
    }

    // - process reference positions of each parameter of called method -
    if (parm_cnt != 0)
    {
      unsigned *ops_ptr_end = im.operand_stack.data + im.operand_stack.used;
      unsigned *ops_ptr = ops_ptr_end - parm_cnt;

      do
      {
        unsigned *op_ptr = im.operands.data + *ops_ptr;

        // - ERROR -
        if (!(*op_ptr & c_op_modifier_object))
        {
          _this.error_code.push(ei_expected_object_as_operand);
          _this.error_code.push(exp.nodes[exp_node_idx + 1]);

          return false;
        }

        code.push(op_ptr[1]);
        if (*op_ptr & c_op_modifier_tmp)
        {
          im.free_stack_idxs.push(op_ptr[1]);
        }
      }
      while(++ops_ptr < ops_ptr_end);

      im.operand_stack.used -= parm_cnt;
    }

    // - store operand of method result -
    im.operand_stack.push(im.operands.used);
    im.operands.push(c_op_modifier_object | c_op_modifier_tmp);
    im.operands.push(tmp_local_idx);

    im.exp_node_stack.used--;
  }

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_this_method_call\n"));

  return true;
}/*}}}*/

bool im_object_method_call(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  im_descr_s &im = _this.im_descr;

  // *****

  unsigned exp_node_idx = im.exp_node_stack.last();
  unsigned parm_cnt = exp.nodes[exp_node_idx + 3] + 1;


  if (im.done_exp_nodes[exp_node_idx] == c_idx_not_exist)
  {

    // - process expression nodes of each parameter of called method -
    unsigned *m_ptr_end = exp.nodes.data + exp_node_idx + 3;
    unsigned *m_ptr = m_ptr_end + parm_cnt;

    do
    {
      im.exp_node_stack.push(*m_ptr);
    }
    while(--m_ptr > m_ptr_end);

    im.done_exp_nodes[exp_node_idx] = 1;
  }
  else
  {

    // - get temporary position of location of method return value -
    unsigned tmp_local_idx = im.free_stack_idxs.used != 0?im.free_stack_idxs.pop():im.stack_idx_max++;

    // - process position of each parameter reference -
    unsigned *ops_ptr_end = im.operand_stack.data + im.operand_stack.used;
    unsigned *ops_ptr = ops_ptr_end - parm_cnt;

    unsigned *op_ptr = im.operands.data + *(ops_ptr++);

    if (*op_ptr & c_op_modifier_static_class)
    {

      // - call static class method -
      class_record_s &class_record = _this.class_records[op_ptr[1]];

      unsigned method_ri = class_record.mnri_map.map_name(exp.nodes[exp_node_idx + 2]);

      // - ERROR -
      if (method_ri == c_idx_not_exist)
      {
        _this.error_code.push(ei_class_does_not_contain_method);
        _this.error_code.push(exp.nodes[exp_node_idx + 1]);
        _this.error_code.push(op_ptr[1]);
        _this.error_code.push(exp.nodes[exp_node_idx + 2]);

        return false;
      }

      method_record_s &method_record = _this.method_records[method_ri];

      // - ERROR -
      if (!(method_record.modifiers & c_modifier_static))
      {
        _this.error_code.push(ei_static_reference_to_nonstatic_method);
        _this.error_code.push(exp.nodes[exp_node_idx + 1]);
        _this.error_code.push(method_ri);

        return false;
      }

      // - ERROR if method is private, actual class must be im.class_idx -
      if ((method_record.modifiers & c_modifier_private) && (method_record.parent_record != im.class_idx))
      {
        _this.error_code.push(ei_cannot_access_private_method);
        _this.error_code.push(exp.nodes[exp_node_idx + 1]);
        _this.error_code.push(method_ri);

        return false;
      }

      code.push(i_static_call);
      code.push(parm_cnt - 1);
      code.push(exp.nodes[exp_node_idx + 1]);
      code.push(tmp_local_idx);
      code.push(method_ri);
    }
    else
    {

      // - calling of object method -
      code.push(i_call);
      code.push(parm_cnt);
      code.push(exp.nodes[exp_node_idx + 2]);
      code.push(c_idx_not_exist);
      code.push(c_idx_not_exist);
      code.push(exp.nodes[exp_node_idx + 1]);
      code.push(tmp_local_idx);

      // - ERROR -
      if (!(*op_ptr & c_op_modifier_object))
      {
        _this.error_code.push(ei_expected_object_as_operand);
        _this.error_code.push(exp.nodes[exp_node_idx + 1]);

        return false;
      }

      code.push(op_ptr[1]);
      if (*op_ptr & c_op_modifier_tmp)
      {
        im.free_stack_idxs.push(op_ptr[1]);
      }
    }

    // - insertion of parameter locations to code -
    if (ops_ptr < ops_ptr_end)
    {
      do
      {
        unsigned *op_ptr = im.operands.data + *ops_ptr;

        // - ERROR -
        if (!(*op_ptr & c_op_modifier_object))
        {
          _this.error_code.push(ei_expected_object_as_operand);
          _this.error_code.push(exp.nodes[exp_node_idx + 1]);

          return false;
        }

        code.push(op_ptr[1]);
        if (*op_ptr & c_op_modifier_tmp)
        {
          im.free_stack_idxs.push(op_ptr[1]);
        }
      }
      while(++ops_ptr < ops_ptr_end);
    }

    im.operand_stack.used -= parm_cnt;

    // - store position of reference method return value -
    im.operand_stack.push(im.operands.used);
    im.operands.push(c_op_modifier_object | c_op_modifier_tmp);
    im.operands.push(tmp_local_idx);

    im.exp_node_stack.used--;
  }

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_object_method_call\n"));

  return true;
}/*}}}*/

bool im_const_char(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  im_descr_s &im = _this.im_descr;

  // *****

  unsigned const_idx = im.cv_char_base + exp.nodes[im.exp_node_stack.pop() + 1];
  unsigned &cv_operand = im.const_idx_fo_map[const_idx];

  if (cv_operand == c_idx_not_exist)
  {

    // - creation of position for reference to constant -
    unsigned local_idx = im.stack_idx_max++;

    cv_operand = im.found_operands.used;
    im.found_operands.push(c_op_modifier_object);
    im.found_operands.push(local_idx);

    im.operand_stack.push(im.operands.used);
    im.operands.push(c_op_modifier_object);
    im.operands.push(local_idx);

    begin_code.push(i_const);
    begin_code.push(local_idx);
    begin_code.push(const_idx);
  }
  else
  {
    im.operand_stack.push(im.operands.used);

    unsigned *fo_ptr = im.found_operands.data + cv_operand;
    im.operands.push(*fo_ptr);
    im.operands.push(fo_ptr[1]);
  }

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_const_char\n"));

  return true;
}/*}}}*/

bool im_const_int(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  im_descr_s &im = _this.im_descr;

  // *****

  unsigned const_idx = im.cv_integer_base + exp.nodes[im.exp_node_stack.pop() + 1];
  unsigned &cv_operand = im.const_idx_fo_map[const_idx];

  if (cv_operand == c_idx_not_exist)
  {

    // - creation of position for reference to constant -
    unsigned local_idx = im.stack_idx_max++;

    cv_operand = im.found_operands.used;
    im.found_operands.push(c_op_modifier_object);
    im.found_operands.push(local_idx);

    im.operand_stack.push(im.operands.used);
    im.operands.push(c_op_modifier_object);
    im.operands.push(local_idx);

    begin_code.push(i_const);
    begin_code.push(local_idx);
    begin_code.push(const_idx);
  }
  else
  {
    im.operand_stack.push(im.operands.used);

    unsigned *fo_ptr = im.found_operands.data + cv_operand;
    im.operands.push(*fo_ptr);
    im.operands.push(fo_ptr[1]);
  }

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_const_int\n"));

  return true;
}/*}}}*/

bool im_const_float(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  im_descr_s &im = _this.im_descr;

  // *****

  unsigned const_idx = im.cv_float_base + exp.nodes[im.exp_node_stack.pop() + 1];
  unsigned &cv_operand = im.const_idx_fo_map[const_idx];

  if (cv_operand == c_idx_not_exist)
  {

    // - creation of position for reference to constant -
    unsigned local_idx = im.stack_idx_max++;

    cv_operand = im.found_operands.used;
    im.found_operands.push(c_op_modifier_object);
    im.found_operands.push(local_idx);

    im.operand_stack.push(im.operands.used);
    im.operands.push(c_op_modifier_object);
    im.operands.push(local_idx);

    begin_code.push(i_const);
    begin_code.push(local_idx);
    begin_code.push(const_idx);
  }
  else
  {
    im.operand_stack.push(im.operands.used);

    unsigned *fo_ptr = im.found_operands.data + cv_operand;
    im.operands.push(*fo_ptr);
    im.operands.push(fo_ptr[1]);
  }

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_const_float\n"));

  return true;
}/*}}}*/

bool im_const_string(expression_s &exp,uli_array_s &begin_code,uli_array_s &code,script_parser_s &_this)
{/*{{{*/
  im_descr_s &im = _this.im_descr;

  // *****

  unsigned const_idx = im.cv_string_base + exp.nodes[im.exp_node_stack.pop() + 1];
  unsigned &cv_operand = im.const_idx_fo_map[const_idx];

  if (cv_operand == c_idx_not_exist)
  {

    // - creation of position for reference to constant -
    unsigned local_idx = im.stack_idx_max++;

    cv_operand = im.found_operands.used;
    im.found_operands.push(c_op_modifier_object);
    im.found_operands.push(local_idx);

    im.operand_stack.push(im.operands.used);
    im.operands.push(c_op_modifier_object);
    im.operands.push(local_idx);

    begin_code.push(i_const);
    begin_code.push(local_idx);
    begin_code.push(const_idx);
  }
  else
  {
    im.operand_stack.push(im.operands.used);

    unsigned *fo_ptr = im.found_operands.data + cv_operand;
    im.operands.push(*fo_ptr);
    im.operands.push(fo_ptr[1]);
  }

  debug_message_4(fprintf(stderr,"script_parser: intermediate generate: im_const_string\n"));

  return true;
}/*}}}*/

