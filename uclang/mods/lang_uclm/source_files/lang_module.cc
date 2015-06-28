
@begin
include "lang_module.h"
@end

// - LANG indexes of built in classes -
unsigned c_bi_class_lang = c_idx_not_exist;
unsigned c_bi_class_namespace_ref = c_idx_not_exist;
unsigned c_bi_class_class_ref = c_idx_not_exist;
unsigned c_bi_class_method_ref = c_idx_not_exist;
unsigned c_bi_class_var_ref = c_idx_not_exist;
unsigned c_bi_class_param_ref = c_idx_not_exist;

// - LANG module -
built_in_module_s module =
{/*{{{*/
  6,                    // Class count
  lang_classes,         // Classes

  0,                    // Error base index
  5,                    // Error count
  lang_error_strings,   // Error strings

  lang_initialize,      // Initialize function
  lang_print_exception, // Print exceptions function
};/*}}}*/

// - LANG classes -
built_in_class_s *lang_classes[] =
{/*{{{*/
  &lang_class,
  &namespace_ref_class,
  &class_ref_class,
  &method_ref_class,
  &var_ref_class,
  &param_ref_class,
};/*}}}*/

// - LANG error strings -
const char *lang_error_strings[] =
{/*{{{*/
  "error_LANG_CLASS_WAS_NOT_FOUND",
  "error_CLASS_REF_CLASS_WAS_NOT_FOUND",
  "error_CLASS_REF_METHOD_WAS_NOT_FOUND",
  "error_CLASS_REF_VARIABLE_WAS_NOT_FOUND",
  "error_METHOD_REF_PARAMETER_WAS_NOT_FOUND",
};/*}}}*/

// - LANG initialize -
bool lang_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize lang class identifier -
  c_bi_class_lang = class_base_idx++;

  // - initialize namespace_ref class identifier -
  c_bi_class_namespace_ref = class_base_idx++;

  // - initialize class_ref class identifier -
  c_bi_class_class_ref = class_base_idx++;

  // - initialize method_ref class identifier -
  c_bi_class_method_ref = class_base_idx++;

  // - initialize var_ref class identifier -
  c_bi_class_var_ref = class_base_idx++;

  // - initialize param_ref class identifier -
  c_bi_class_param_ref = class_base_idx++;

  return true;
}/*}}}*/

// - LANG print exception -
bool lang_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_LANG_CLASS_WAS_NOT_FOUND:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTop level class named \"%s\" was not found\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CLASS_REF_CLASS_WAS_NOT_FOUND:
  {
    class_record_s &class_record = it.class_records[exception.params[0]];

    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nClass ");
    print_class_sequence(it.class_symbol_names,it.class_records,class_stack,class_record.parent_record);
    fprintf(stderr,"%s does not contain subclass named \"%s\"\n",it.class_symbol_names[class_record.name_idx].data,((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
  }
  break;
  case c_error_CLASS_REF_METHOD_WAS_NOT_FOUND:
  {
    class_record_s &class_record = it.class_records[exception.params[0]];

    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nClass ");
    print_class_sequence(it.class_symbol_names,it.class_records,class_stack,class_record.parent_record);
    fprintf(stderr,"%s does not contain method named \"%s\"\n",it.class_symbol_names[class_record.name_idx].data,((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
  }
  break;
  case c_error_CLASS_REF_VARIABLE_WAS_NOT_FOUND:
  {
    class_record_s &class_record = it.class_records[exception.params[0]];

    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nClass ");
    print_class_sequence(it.class_symbol_names,it.class_records,class_stack,class_record.parent_record);
    fprintf(stderr,"%s does not contain variable named \"%s\"\n",it.class_symbol_names[class_record.name_idx].data,((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
  }
  break;
  case c_error_METHOD_REF_PARAMETER_WAS_NOT_FOUND:
  {
    method_record_s &method_record = it.method_records[exception.params[0]];
    class_record_s &class_record = it.class_records[method_record.parent_record];

    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMethod ");
    print_class_sequence(it.class_symbol_names,it.class_records,class_stack,class_record.parent_record);
    fprintf(stderr,"%s.%s does not contain parameter named \"%s\"\n",
      it.class_symbol_names[class_record.name_idx].data,it.method_symbol_names[method_record.name_idx].data,((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
  }
  break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class LANG -
built_in_class_s lang_class =
{/*{{{*/
  "Lang",
  c_modifier_public | c_modifier_final,
  6, lang_methods,
  0, lang_variables,
  bic_lang_consts,
  bic_lang_init,
  bic_lang_clear,
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

built_in_method_s lang_methods[] =
{/*{{{*/
  {
    "name#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_lang_method_name_0
  },
  {
    "version#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_lang_method_version_0
  },
  {
    "classes#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_lang_method_classes_0
  },
  {
    "cls#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_lang_method_cls_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_lang_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_lang_method_print_0
  },
};/*}}}*/

built_in_variable_s lang_variables[] =
{/*{{{*/
};/*}}}*/

void bic_lang_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_lang_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_lang_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_lang_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(c_name_str),c_name_str);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_lang_method_version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(c_version_str),c_version_str);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_lang_method_classes_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  namespace_record_s &namespace_record = ((interpreter_s *)it.interpreter_ptr)->namespace_records[0];
  ui_array_s &class_record_idxs = namespace_record.class_record_idxs;

  // - construct result array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  if (class_record_idxs.used != 0)
  {
    unsigned *cri_ptr = class_record_idxs.data;
    unsigned *cri_ptr_end = cri_ptr + class_record_idxs.used;

    do
    {
      long long int value = *cri_ptr;

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_class_ref,value);
      array_ptr->push(new_location);
    }
    while(++cri_ptr < cri_ptr_end);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_lang_method_cls_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_lang,"cls#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  interpreter_s &interpreter = *((interpreter_s *)it.interpreter_ptr);
  string_rb_tree_s &class_symbol_names = interpreter.class_symbol_names;
  class_records_s &class_records = interpreter.class_records;

  // - retrieve class name index -
  unsigned class_name_idx = class_symbol_names.get_idx(*((string_s *)src_0_location->v_data_ptr));

  // - ERROR -
  if (class_name_idx == c_idx_not_exist)
  {
    exception_s::throw_exception(it,module.error_base + c_error_LANG_CLASS_WAS_NOT_FOUND,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  namespace_record_s &namespace_record = ((interpreter_s *)it.interpreter_ptr)->namespace_records[0];
  ui_array_s &class_record_idxs = namespace_record.class_record_idxs;

  // - find class index by name -
  unsigned cr_idx = c_idx_not_exist;
  if (class_record_idxs.used != 0)
  {
    unsigned *cri_ptr = class_record_idxs.data;
    unsigned *cri_ptr_end = cri_ptr + class_record_idxs.used;

    do
    {
      if (class_name_idx == class_records[*cri_ptr].name_idx)
      {
        cr_idx = *cri_ptr;
        break;
      }
    }
    while(++cri_ptr < cri_ptr_end);
  }

  // - ERROR -
  if (cr_idx == c_idx_not_exist)
  {
    exception_s::throw_exception(it,module.error_base + c_error_LANG_CLASS_WAS_NOT_FOUND,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_class_ref,cr_idx);

  return true;
}/*}}}*/

bool bic_lang_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->setf("%s %s",c_name_str,c_version_str)
  );

  return true;
}/*}}}*/

bool bic_lang_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("%s %s",c_name_str,c_version_str);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class CLASS_REF -
built_in_class_s class_ref_class =
{/*{{{*/
  "ClassRef",
  c_modifier_public | c_modifier_final,
  13, class_ref_methods,
  0, class_ref_variables,
  bic_class_ref_consts,
  bic_class_ref_init,
  bic_class_ref_clear,
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

built_in_method_s class_ref_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_class_ref_operator_binary_equal
  },
  {
    "ClassRef#1",
    c_modifier_public | c_modifier_final,
    bic_class_ref_method_ClassRef_1
  },
  {
    "name#0",
    c_modifier_public | c_modifier_final,
    bic_class_ref_method_name_0
  },
  {
    "is_built_in#0",
    c_modifier_public | c_modifier_final,
    bic_class_ref_method_is_built_in_0
  },
  {
    "parent#0",
    c_modifier_public | c_modifier_final,
    bic_class_ref_method_parent_0
  },
  {
    "classes#0",
    c_modifier_public | c_modifier_final,
    bic_class_ref_method_classes_0
  },
  {
    "methods#0",
    c_modifier_public | c_modifier_final,
    bic_class_ref_method_methods_0
  },
  {
    "vars#0",
    c_modifier_public | c_modifier_final,
    bic_class_ref_method_vars_0
  },
  {
    "cls#1",
    c_modifier_public | c_modifier_final,
    bic_class_ref_method_cls_1
  },
  {
    "method#1",
    c_modifier_public | c_modifier_final,
    bic_class_ref_method_method_1
  },
  {
    "variable#1",
    c_modifier_public | c_modifier_final,
    bic_class_ref_method_variable_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_class_ref_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_class_ref_method_print_0
  },
};/*}}}*/

built_in_variable_s class_ref_variables[] =
{/*{{{*/
};/*}}}*/

void bic_class_ref_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_class_ref_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)0;
}/*}}}*/

void bic_class_ref_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

bool bic_class_ref_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_class_ref_method_ClassRef_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  dst_location->v_data_ptr = (basic_64b)src_0_location->v_type;

  return true;
}/*}}}*/

bool bic_class_ref_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  interpreter_s &interpreter = *((interpreter_s *)it.interpreter_ptr);
  string_rb_tree_s &class_symbol_names = interpreter.class_symbol_names;
  class_records_s &class_records = interpreter.class_records;

  long long int cr_idx = (long long int)dst_location->v_data_ptr;

  string_s *string_ptr = it.get_new_string_ptr();
  *string_ptr = class_symbol_names[class_records[cr_idx].name_idx];

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_class_ref_method_is_built_in_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  class_records_s &class_records = ((interpreter_s *)it.interpreter_ptr)->class_records;

  long long int cr_idx = (long long int)dst_location->v_data_ptr;
  long long int result = (class_records[cr_idx].modifiers & c_modifier_built_in) != 0;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_class_ref_method_parent_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  class_records_s &class_records = ((interpreter_s *)it.interpreter_ptr)->class_records;

  long long int cr_idx = (long long int)dst_location->v_data_ptr;
  long long int pr_idx = class_records[cr_idx].parent_record;

  if (pr_idx != c_idx_not_exist)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_class_ref,pr_idx);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_class_ref_method_classes_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  class_records_s &class_records = ((interpreter_s *)it.interpreter_ptr)->class_records;

  long long int cr_idx = (long long int)dst_location->v_data_ptr;

  // - retrieve subclass record indexes -
  ui_array_s &scr_idxs = class_records[cr_idx].class_record_idxs;

  // - construct result array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  if (scr_idxs.used != 0)
  {
    unsigned *scri_ptr = scr_idxs.data;
    unsigned *scri_ptr_end = scri_ptr + scr_idxs.used;

    do
    {
      long long int value = *scri_ptr;

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_class_ref,value);
      array_ptr->push(new_location);
    }
    while(++scri_ptr < scri_ptr_end);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_class_ref_method_methods_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  class_records_s &class_records = ((interpreter_s *)it.interpreter_ptr)->class_records;

  long long int cr_idx = (long long int)dst_location->v_data_ptr;

  // - retrieve method record indexes -
  ui_array_s &mr_idxs = class_records[cr_idx].method_record_idxs;

  // - construct result array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  if (mr_idxs.used != 0)
  {
    unsigned *mri_ptr = mr_idxs.data;
    unsigned *mri_ptr_end = mri_ptr + mr_idxs.used;

    do
    {
      long long int value = *mri_ptr;

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_method_ref,value);
      array_ptr->push(new_location);
    }
    while(++mri_ptr < mri_ptr_end);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_class_ref_method_vars_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  class_records_s &class_records = ((interpreter_s *)it.interpreter_ptr)->class_records;

  long long int cr_idx = (long long int)dst_location->v_data_ptr;

  // - retrieve variable record indexes -
  ui_array_s &vr_idxs = class_records[cr_idx].variable_record_idxs;

  // - construct result array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  if (vr_idxs.used != 0)
  {
    unsigned *vri_ptr = vr_idxs.data;
    unsigned *vri_ptr_end = vri_ptr + vr_idxs.used;

    do
    {
      long long int value = *vri_ptr;

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_var_ref,value);
      array_ptr->push(new_location);
    }
    while(++vri_ptr < vri_ptr_end);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_class_ref_method_cls_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("cls#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  interpreter_s &interpreter = *((interpreter_s *)it.interpreter_ptr);
  string_rb_tree_s &class_symbol_names = interpreter.class_symbol_names;
  class_records_s &class_records = interpreter.class_records;

  long long int cr_idx = (long long int)dst_location->v_data_ptr;

  // - retrieve subclass name index -
  unsigned subclass_name_idx = class_symbol_names.get_idx(*((string_s *)src_0_location->v_data_ptr));

  // - ERROR -
  if (subclass_name_idx == c_idx_not_exist)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_CLASS_REF_CLASS_WAS_NOT_FOUND,operands[c_source_pos_idx],src_0_location);
    new_exception->params.push(cr_idx);

    return false;
  }

  // - retrieve classes indexes -
  ui_array_s &cr_idxs = class_records[cr_idx].class_record_idxs;

  // - find class index by name -
  unsigned scr_idx = c_idx_not_exist;
  if (cr_idxs.used != 0)
  {
    unsigned *scri_ptr = cr_idxs.data;
    unsigned *scri_ptr_end = scri_ptr + cr_idxs.used;

    do
    {
      if (subclass_name_idx == class_records[*scri_ptr].name_idx)
      {
        scr_idx = *scri_ptr;
        break;
      }
    }
    while(++scri_ptr < scri_ptr_end);
  }

  // - ERROR -
  if (scr_idx == c_idx_not_exist)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_CLASS_REF_CLASS_WAS_NOT_FOUND,operands[c_source_pos_idx],src_0_location);
    new_exception->params.push(cr_idx);

    return false;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_class_ref,scr_idx);

  return true;
}/*}}}*/

bool bic_class_ref_method_method_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("method#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  interpreter_s &interpreter = *((interpreter_s *)it.interpreter_ptr);
  string_rb_tree_s &method_symbol_names = interpreter.method_symbol_names;
  class_records_s &class_records = interpreter.class_records;
  method_records_s &method_records = interpreter.method_records;

  long long int cr_idx = (long long int)dst_location->v_data_ptr;

  // - retrieve method name index -
  unsigned method_name_idx = method_symbol_names.get_idx(*((string_s *)src_0_location->v_data_ptr));

  // - ERROR -
  if (method_name_idx == c_idx_not_exist)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_CLASS_REF_METHOD_WAS_NOT_FOUND,operands[c_source_pos_idx],src_0_location);
    new_exception->params.push(cr_idx);

    return false;
  }

  // - retrieve method record indexes -
  ui_array_s &mr_idxs = class_records[cr_idx].method_record_idxs;

  // - find method index by name -
  unsigned mr_idx = c_idx_not_exist;
  if (mr_idxs.used != 0)
  {
    unsigned *mri_ptr = mr_idxs.data;
    unsigned *mri_ptr_end = mri_ptr + mr_idxs.used;

    do
    {
      if (method_name_idx == method_records[*mri_ptr].name_idx)
      {
        mr_idx = *mri_ptr;
        break;
      }
    }
    while(++mri_ptr < mri_ptr_end);
  }

  // - ERROR -
  if (mr_idx == c_idx_not_exist)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_CLASS_REF_METHOD_WAS_NOT_FOUND,operands[c_source_pos_idx],src_0_location);
    new_exception->params.push(cr_idx);

    return false;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_method_ref,mr_idx);

  return true;
}/*}}}*/

bool bic_class_ref_method_variable_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("variable#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  interpreter_s &interpreter = *((interpreter_s *)it.interpreter_ptr);
  string_rb_tree_s &variable_symbol_names = interpreter.variable_symbol_names;
  class_records_s &class_records = interpreter.class_records;
  variable_records_s &variable_records = interpreter.variable_records;

  long long int cr_idx = (long long int)dst_location->v_data_ptr;

  // - retrieve variable name index -
  unsigned variable_name_idx = variable_symbol_names.get_idx(*((string_s *)src_0_location->v_data_ptr));

  // - ERROR -
  if (variable_name_idx == c_idx_not_exist)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_CLASS_REF_VARIABLE_WAS_NOT_FOUND,operands[c_source_pos_idx],src_0_location);
    new_exception->params.push(cr_idx);

    return false;
  }

  // - retrieve variable record indexes -
  ui_array_s &vr_idxs = class_records[cr_idx].variable_record_idxs;

  // - find variable index by name -
  unsigned vr_idx = c_idx_not_exist;
  if (vr_idxs.used != 0)
  {
    unsigned *vri_ptr = vr_idxs.data;
    unsigned *vri_ptr_end = vri_ptr + vr_idxs.used;

    do
    {
      if (variable_name_idx == variable_records[*vri_ptr].name_idx)
      {
        vr_idx = *vri_ptr;
        break;
      }
    }
    while(++vri_ptr < vri_ptr_end);
  }

  // - ERROR -
  if (vr_idx == c_idx_not_exist)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_CLASS_REF_VARIABLE_WAS_NOT_FOUND,operands[c_source_pos_idx],src_0_location);
    new_exception->params.push(cr_idx);

    return false;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_var_ref,vr_idx);

  return true;
}/*}}}*/

bool bic_class_ref_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("ClassRef"),"ClassRef");
  );

  return true;
}/*}}}*/

bool bic_class_ref_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("ClassRef");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class NAMESPACE_REF -
built_in_class_s namespace_ref_class =
{/*{{{*/
  "NamespaceRef",
  c_modifier_public | c_modifier_final,
  9, namespace_ref_methods,
  0, namespace_ref_variables,
  bic_namespace_ref_consts,
  bic_namespace_ref_init,
  bic_namespace_ref_clear,
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

built_in_method_s namespace_ref_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_namespace_ref_operator_binary_equal
  },
  {
    "global#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_namespace_ref_method_global_0
  },
  {
    "name#0",
    c_modifier_public | c_modifier_final,
    bic_namespace_ref_method_name_0
  },
  {
    "namespaces#0",
    c_modifier_public | c_modifier_final,
    bic_namespace_ref_method_namespaces_0
  },
  {
    "classes#0",
    c_modifier_public | c_modifier_final,
    bic_namespace_ref_method_classes_0
  },
  {
    "nspace#1",
    c_modifier_public | c_modifier_final,
    bic_namespace_ref_method_nspace_1
  },
  {
    "cls#1",
    c_modifier_public | c_modifier_final,
    bic_namespace_ref_method_cls_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_namespace_ref_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_namespace_ref_method_print_0
  },
};/*}}}*/

built_in_variable_s namespace_ref_variables[] =
{/*{{{*/
};/*}}}*/

void bic_namespace_ref_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_namespace_ref_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)0;
}/*}}}*/

void bic_namespace_ref_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

bool bic_namespace_ref_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_namespace_ref_method_global_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  BIC_SIMPLE_SET_RES(c_bi_class_namespace_ref,0);

  return true;
}/*}}}*/

bool bic_namespace_ref_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  interpreter_s &interpreter = *((interpreter_s *)it.interpreter_ptr);
  string_rb_tree_s &class_symbol_names = interpreter.class_symbol_names;
  namespace_records_s &namespace_records = interpreter.namespace_records;

  long long int nsr_idx = (long long int)dst_location->v_data_ptr;

  string_s *string_ptr = it.get_new_string_ptr();
  *string_ptr = class_symbol_names[namespace_records[nsr_idx].name_idx];

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_namespace_ref_method_namespaces_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  namespace_records_s &namespace_records = ((interpreter_s *)it.interpreter_ptr)->namespace_records;

  long long int nsr_idx = (long long int)dst_location->v_data_ptr;

  // - retrieve namespace record indexes -
  ui_array_s &namespace_record_idxs = namespace_records[nsr_idx].namespace_record_idxs;

  // - construct result array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  if (namespace_record_idxs.used != 0)
  {
    unsigned *nsri_ptr = namespace_record_idxs.data;
    unsigned *nsri_ptr_end = nsri_ptr + namespace_record_idxs.used;

    do
    {
      long long int value = *nsri_ptr;

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_namespace_ref,value);
      array_ptr->push(new_location);
    }
    while(++nsri_ptr < nsri_ptr_end);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_namespace_ref_method_classes_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  namespace_records_s &namespace_records = ((interpreter_s *)it.interpreter_ptr)->namespace_records;

  long long int nsr_idx = (long long int)dst_location->v_data_ptr;

  // - retrieve class record indexes -
  ui_array_s &class_record_idxs = namespace_records[nsr_idx].class_record_idxs;

  // - construct result array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  if (class_record_idxs.used != 0)
  {
    unsigned *cri_ptr = class_record_idxs.data;
    unsigned *cri_ptr_end = cri_ptr + class_record_idxs.used;

    do
    {
      long long int value = *cri_ptr;

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_class_ref,value);
      array_ptr->push(new_location);
    }
    while(++cri_ptr < cri_ptr_end);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_namespace_ref_method_nspace_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("nspace#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  interpreter_s &interpreter = *((interpreter_s *)it.interpreter_ptr);
  string_rb_tree_s &class_symbol_names = interpreter.class_symbol_names;
  namespace_records_s &namespace_records = interpreter.namespace_records;

  long long int nsr_idx = (long long int)dst_location->v_data_ptr;

  // - retrieve namespace name index -
  unsigned namespace_name_idx = class_symbol_names.get_idx(*((string_s *)src_0_location->v_data_ptr));

  // - ERROR -
  if (namespace_name_idx == c_idx_not_exist)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  // - retrieve namespace record indexes -
  ui_array_s &namespace_record_idxs = namespace_records[nsr_idx].namespace_record_idxs;

  // - find namespace record index by name -
  unsigned fnsr_idx = c_idx_not_exist;
  if (namespace_record_idxs.used != 0)
  {
    unsigned *nsri_ptr = namespace_record_idxs.data;
    unsigned *nsri_ptr_end = nsri_ptr + namespace_record_idxs.used;

    do
    {
      if (namespace_name_idx == namespace_records[*nsri_ptr].name_idx)
      {
        fnsr_idx = *nsri_ptr;
        break;
      }
    }
    while(++nsri_ptr < nsri_ptr_end);
  }

  // - ERROR -
  if (fnsr_idx == c_idx_not_exist)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_namespace_ref,fnsr_idx);

  return true;
}/*}}}*/

bool bic_namespace_ref_method_cls_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("nspace#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  interpreter_s &interpreter = *((interpreter_s *)it.interpreter_ptr);
  string_rb_tree_s &class_symbol_names = interpreter.class_symbol_names;
  namespace_records_s &namespace_records = interpreter.namespace_records;
  class_records_s &class_records = interpreter.class_records;

  long long int nsr_idx = (long long int)dst_location->v_data_ptr;

  // - retrieve class name index -
  unsigned class_name_idx = class_symbol_names.get_idx(*((string_s *)src_0_location->v_data_ptr));

  // - ERROR -
  if (class_name_idx == c_idx_not_exist)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  // - retrieve class record indexes -
  ui_array_s &class_record_idxs = namespace_records[nsr_idx].class_record_idxs;

  // - find class record index by name -
  unsigned fcr_idx = c_idx_not_exist;
  if (class_record_idxs.used != 0)
  {
    unsigned *cri_ptr = class_record_idxs.data;
    unsigned *cri_ptr_end = cri_ptr + class_record_idxs.used;

    do
    {
      if (class_name_idx == class_records[*cri_ptr].name_idx)
      {
        fcr_idx = *cri_ptr;
        break;
      }
    }
    while(++cri_ptr < cri_ptr_end);
  }

  // - ERROR -
  if (fcr_idx == c_idx_not_exist)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_class_ref,fcr_idx);

  return true;
}/*}}}*/

bool bic_namespace_ref_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("NamespaceRef"),"NamespaceRef");
  );

  return true;
}/*}}}*/

bool bic_namespace_ref_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("NamespaceRef");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class METHOD_REF -
built_in_class_s method_ref_class =
{/*{{{*/
  "MethodRef",
  c_modifier_public | c_modifier_final,
  8, method_ref_methods,
  0, method_ref_variables,
  bic_method_ref_consts,
  bic_method_ref_init,
  bic_method_ref_clear,
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

built_in_method_s method_ref_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_method_ref_operator_binary_equal
  },
  {
    "name#0",
    c_modifier_public | c_modifier_final,
    bic_method_ref_method_name_0
  },
  {
    "is_static#0",
    c_modifier_public | c_modifier_final,
    bic_method_ref_method_is_static_0
  },
  {
    "parent#0",
    c_modifier_public | c_modifier_final,
    bic_method_ref_method_parent_0
  },
  {
    "params#0",
    c_modifier_public | c_modifier_final,
    bic_method_ref_method_params_0
  },
  {
    "param#1",
    c_modifier_public | c_modifier_final,
    bic_method_ref_method_param_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_method_ref_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_method_ref_method_print_0
  },
};/*}}}*/

built_in_variable_s method_ref_variables[] =
{/*{{{*/
};/*}}}*/

void bic_method_ref_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_method_ref_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)0;
}/*}}}*/

void bic_method_ref_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

bool bic_method_ref_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_method_ref_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  interpreter_s &interpreter = *((interpreter_s *)it.interpreter_ptr);
  string_rb_tree_s &method_symbol_names = interpreter.method_symbol_names;
  method_records_s &method_records = interpreter.method_records;

  long long int mr_idx = (long long int)dst_location->v_data_ptr;

  string_s *string_ptr = it.get_new_string_ptr();
  *string_ptr = method_symbol_names[method_records[mr_idx].name_idx];

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_method_ref_method_is_static_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  method_records_s &method_records = ((interpreter_s *)it.interpreter_ptr)->method_records;

  long long int mr_idx = (long long int)dst_location->v_data_ptr;
  long long int result = (method_records[mr_idx].modifiers & c_modifier_static) != 0;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_method_ref_method_parent_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  method_records_s &method_records = ((interpreter_s *)it.interpreter_ptr)->method_records;

  long long int mr_idx = (long long int)dst_location->v_data_ptr;
  long long int pr_idx = method_records[mr_idx].parent_record;

  if (pr_idx != c_idx_not_exist)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_class_ref,pr_idx);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_method_ref_method_params_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  method_records_s &method_records = ((interpreter_s *)it.interpreter_ptr)->method_records;

  long long int mr_idx = (long long int)dst_location->v_data_ptr;

  // - retrieve parameter record indexes -
  ui_array_s &pr_idxs = method_records[mr_idx].parameter_record_idxs;

  // - construct result array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  if (pr_idxs.used != 0)
  {
    unsigned *pri_ptr = pr_idxs.data;
    unsigned *pri_ptr_end = pri_ptr + pr_idxs.used;

    do
    {
      long long int value = *pri_ptr;

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_param_ref,value);
      array_ptr->push(new_location);
    }
    while(++pri_ptr < pri_ptr_end);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_method_ref_method_param_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("param#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  interpreter_s &interpreter = *((interpreter_s *)it.interpreter_ptr);
  string_rb_tree_s &variable_symbol_names = interpreter.variable_symbol_names;
  method_records_s &method_records = interpreter.method_records;
  variable_records_s &variable_records = interpreter.variable_records;

  long long int mr_idx = (long long int)dst_location->v_data_ptr;

  // - retrieve parameter name index -
  unsigned parameter_name_idx = variable_symbol_names.get_idx(*((string_s *)src_0_location->v_data_ptr));

  // - ERROR -
  if (parameter_name_idx == c_idx_not_exist)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_METHOD_REF_PARAMETER_WAS_NOT_FOUND,operands[c_source_pos_idx],src_0_location);
    new_exception->params.push(mr_idx);

    return false;
  }

  // - retrieve parameter record indexes -
  ui_array_s &pr_idxs = method_records[mr_idx].parameter_record_idxs;

  // - find parameter index by name -
  unsigned pr_idx = c_idx_not_exist;
  if (pr_idxs.used != 0)
  {
    unsigned *pri_ptr = pr_idxs.data;
    unsigned *pri_ptr_end = pri_ptr + pr_idxs.used;

    do
    {
      if (parameter_name_idx == variable_records[*pri_ptr].name_idx)
      {
        pr_idx = *pri_ptr;
        break;
      }
    }
    while(++pri_ptr < pri_ptr_end);
  }

  // - ERROR -
  if (pr_idx == c_idx_not_exist)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_METHOD_REF_PARAMETER_WAS_NOT_FOUND,operands[c_source_pos_idx],src_0_location);
    new_exception->params.push(mr_idx);

    return false;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_param_ref,pr_idx);

  return true;
}/*}}}*/

bool bic_method_ref_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("MethodRef"),"MethodRef");
  );

  return true;
}/*}}}*/

bool bic_method_ref_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("MethodRef");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class VAR_REF -
built_in_class_s var_ref_class =
{/*{{{*/
  "VarRef",
  c_modifier_public | c_modifier_final,
  5, var_ref_methods,
  0, var_ref_variables,
  bic_var_ref_consts,
  bic_var_ref_init,
  bic_var_ref_clear,
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

built_in_method_s var_ref_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_var_ref_operator_binary_equal
  },
  {
    "name#0",
    c_modifier_public | c_modifier_final,
    bic_var_ref_method_name_0
  },
  {
    "parent#0",
    c_modifier_public | c_modifier_final,
    bic_var_ref_method_parent_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_var_ref_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_var_ref_method_print_0
  },
};/*}}}*/

built_in_variable_s var_ref_variables[] =
{/*{{{*/
};/*}}}*/

void bic_var_ref_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_var_ref_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)0;
}/*}}}*/

void bic_var_ref_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

bool bic_var_ref_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_var_ref_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  interpreter_s &interpreter = *((interpreter_s *)it.interpreter_ptr);
  string_rb_tree_s &variable_symbol_names = interpreter.variable_symbol_names;
  variable_records_s &variable_records = interpreter.variable_records;

  long long int vr_idx = (long long int)dst_location->v_data_ptr;

  string_s *string_ptr = it.get_new_string_ptr();
  *string_ptr = variable_symbol_names[variable_records[vr_idx].name_idx];

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_var_ref_method_parent_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  variable_records_s &variable_records = ((interpreter_s *)it.interpreter_ptr)->variable_records;

  long long int vr_idx = (long long int)dst_location->v_data_ptr;
  long long int pr_idx = variable_records[vr_idx].parent_record;

  if (pr_idx != c_idx_not_exist)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_class_ref,pr_idx);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_var_ref_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("VarRef"),"VarRef");
  );

  return true;
}/*}}}*/

bool bic_var_ref_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("VarRef");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class PARAM_REF -
built_in_class_s param_ref_class =
{/*{{{*/
  "ParamRef",
  c_modifier_public | c_modifier_final,
  5, param_ref_methods,
  0, param_ref_variables,
  bic_param_ref_consts,
  bic_param_ref_init,
  bic_param_ref_clear,
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

built_in_method_s param_ref_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_param_ref_operator_binary_equal
  },
  {
    "name#0",
    c_modifier_public | c_modifier_final,
    bic_param_ref_method_name_0
  },
  {
    "parent#0",
    c_modifier_public | c_modifier_final,
    bic_param_ref_method_parent_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_param_ref_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_param_ref_method_print_0
  },
};/*}}}*/

built_in_variable_s param_ref_variables[] =
{/*{{{*/
};/*}}}*/

void bic_param_ref_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_param_ref_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)0;
}/*}}}*/

void bic_param_ref_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

bool bic_param_ref_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_param_ref_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  interpreter_s &interpreter = *((interpreter_s *)it.interpreter_ptr);
  string_rb_tree_s &variable_symbol_names = interpreter.variable_symbol_names;
  variable_records_s &variable_records = interpreter.variable_records;

  long long int vr_idx = (long long int)dst_location->v_data_ptr;

  string_s *string_ptr = it.get_new_string_ptr();
  *string_ptr = variable_symbol_names[variable_records[vr_idx].name_idx];

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_param_ref_method_parent_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  variable_records_s &variable_records = ((interpreter_s *)it.interpreter_ptr)->variable_records;

  long long int vr_idx = (long long int)dst_location->v_data_ptr;
  long long int pr_idx = variable_records[vr_idx].parent_record;

  if (pr_idx != c_idx_not_exist)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_method_ref,pr_idx);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_param_ref_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("ParamRef"),"ParamRef");
  );

  return true;
}/*}}}*/

bool bic_param_ref_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("ParamRef");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

