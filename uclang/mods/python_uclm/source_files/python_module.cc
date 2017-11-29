
@begin
include "python_module.h"
@end

// - PYTHON indexes of built in classes -
unsigned c_bi_class_py_object = c_idx_not_exist;
unsigned c_bi_class_py_attr_ref = c_idx_not_exist;
unsigned c_bi_class_py_item_ref = c_idx_not_exist;

// - PYTHON indexes of remote classes -
unsigned c_rm_class_set = c_idx_not_exist;
unsigned c_rm_class_dict = c_idx_not_exist;

// - PYTHON module -
built_in_module_s module =
{/*{{{*/
  3,                       // Class count
  python_classes,          // Classes

  0,                       // Error base index
  20,                      // Error count
  python_error_strings,    // Error strings

  python_initialize,       // Initialize function
  python_print_exception,  // Print exceptions function
};/*}}}*/

// - PYTHON classes -
built_in_class_s *python_classes[] =
{/*{{{*/
  &py_object_class,
  &py_attr_ref_class,
  &py_item_ref_class,
};/*}}}*/

// - PYTHON error strings -
const char *python_error_strings[] =
{/*{{{*/
  "error_PY_OBJECT_INVOKE_METHOD_UNKNOWN_NAME",
  "error_PY_OBJECT_INVOKE_METHOD_ERROR",
  "error_PY_OBJECT_INVOKE_METHOD_WRONG_PARAMETER",
  "error_PY_OBJECT_MEMBER_SELECT_ERROR",
  "error_PY_OBJECT_ITEM_SELECT_ERROR",
  "error_PY_OBJECT_WRONG_OBJECT_REFERENCE",
  "error_PY_OBJECT_CREATE_ERROR",
  "error_PY_OBJECT_MODULE_ERROR",
  "error_PY_OBJECT_TUPLE_CREATE_ERROR",
  "error_PY_OBJECT_VALUE_ERROR",
  "error_PY_OBJECT_TYPE_ERROR",
  "error_PY_OBJECT_LENGTH_ERROR",
  "error_PY_OBJECT_GET_ATTR_ERROR",
  "error_PY_OBJECT_SET_ATTR_ERROR",
  "error_PY_OBJECT_DEL_ATTR_ERROR",
  "error_PY_OBJECT_GET_ITEM_ERROR",
  "error_PY_OBJECT_SET_ITEM_ERROR",
  "error_PY_OBJECT_DEL_ITEM_ERROR",
  "error_PY_OBJECT_DIR_ERROR",
  "error_PY_OBJECT_TO_STRING_ERROR",
};/*}}}*/

// - PYTHON initialize -
bool python_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize py_object class identifier -
  c_bi_class_py_object = class_base_idx++;

  // - initialize py_attr_ref class identifier -
  c_bi_class_py_attr_ref = class_base_idx++;

  // - initialize py_item_ref class identifier -
  c_bi_class_py_item_ref = class_base_idx++;

  // - retrieve remote set class index -
  c_rm_class_set = sp.resolve_class_idx_by_name("Set",c_idx_not_exist);

  // - retrieve remote dict class index -
  c_rm_class_dict = sp.resolve_class_idx_by_name("Dict",c_idx_not_exist);

  // - ERROR -
  if (c_rm_class_set == c_idx_not_exist ||
      c_rm_class_dict == c_idx_not_exist)
  {
    sp.error_code.push(ei_module_cannot_find_remote_class);
    sp.error_code.push(sp.module_names_positions[sp.module_idx].ui_first);
    sp.error_code.push(sp.module_idx);

    return false;
  }

  return true;
}/*}}}*/

// - PYTHON print exception -
bool python_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_PY_OBJECT_INVOKE_METHOD_UNKNOWN_NAME:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUnknown name of python object method\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PY_OBJECT_INVOKE_METHOD_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while invoking python object method\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PY_OBJECT_INVOKE_METHOD_WRONG_PARAMETER:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);

    if (exception.params[0] != c_idx_not_exist)
    {
      fprintf(stderr,"\nCannot process parameter %" HOST_LL_FORMAT "d of python object method\n",exception.params[0]);
    }
    else
    {
      fprintf(stderr,"\nCannot process parameters of python object method\n");
    }

    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PY_OBJECT_MEMBER_SELECT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while selecting member of python object\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PY_OBJECT_ITEM_SELECT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while selecting item from python object\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PY_OBJECT_WRONG_OBJECT_REFERENCE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong reference to python object\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PY_OBJECT_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating python object\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PY_OBJECT_MODULE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot import python module \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PY_OBJECT_TUPLE_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating python tuple object\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PY_OBJECT_VALUE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while retrieving python object value\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PY_OBJECT_TYPE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot retrieve type of python object\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PY_OBJECT_LENGTH_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot get length of python object\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PY_OBJECT_GET_ATTR_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot get attribute of python object\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PY_OBJECT_SET_ATTR_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot set attribute of python object\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PY_OBJECT_DEL_ATTR_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot delete attribute of python object\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PY_OBJECT_GET_ITEM_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot get item from python object\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PY_OBJECT_SET_ITEM_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot set item of python object\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PY_OBJECT_DEL_ITEM_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot delete item of python object\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PY_OBJECT_DIR_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot retrieve list of python object attributes\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PY_OBJECT_TO_STRING_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot convert python object to string\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class PY_OBJECT -
built_in_class_s py_object_class =
{/*{{{*/
  "PyObject",
  c_modifier_public | c_modifier_final,
  19, py_object_methods,
  0, py_object_variables,
  bic_py_object_consts,
  bic_py_object_init,
  bic_py_object_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  bic_py_object_invoke,
  bic_py_object_member
};/*}}}*/

built_in_method_s py_object_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_py_object_operator_binary_equal
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_py_object_operator_binary_le_br_re_br
  },
  {
    "PyObject#1",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_PyObject_1
  },
  {
    "module#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_py_object_method_module_1
  },
  {
    "tuple#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_py_object_method_tuple_1
  },
  {
    "value#0",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_value_0
  },
  {
    "get_type#0",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_get_type_0
  },
  {
    "has_attr#1",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_has_attr_1
  },
  {
    "get_attr#1",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_get_attr_1
  },
  {
    "set_attr#2",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_set_attr_2
  },
  {
    "del_attr#1",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_del_attr_1
  },
  {
    "call_attr#2",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_call_attr_2
  },
  {
    "get_item#1",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_get_item_1
  },
  {
    "set_item#2",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_set_item_2
  },
  {
    "del_item#1",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_del_item_1
  },
  {
    "dir#0",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_dir_0
  },
  {
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_length_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_print_0
  },
};/*}}}*/

built_in_variable_s py_object_variables[] =
{/*{{{*/
};/*}}}*/

void bic_py_object_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_py_object_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (PyObject *)nullptr;
}/*}}}*/

void bic_py_object_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  PyObject *pyo_obj = (PyObject *)location_ptr->v_data_ptr;

  if (pyo_obj != nullptr)
  {
    Py_DECREF(pyo_obj);
  }
}/*}}}*/

bool bic_py_object_invoke(interpreter_thread_s &it,uli *code,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - method name reference -
  string_s &name_ref = ((interpreter_s *)it.interpreter_ptr)->method_symbol_names[code[icl_name_idx]];

  // - parameter count and method name length -
  unsigned param_cnt = (unsigned)code[icl_parm_cnt] - 1;
  unsigned name_length = strchr(name_ref.data,'#') - name_ref.data;

  char name[c_max_method_name_length];
  memcpy(name,name_ref.data,name_length);
  name[name_length] = '\0';

  // - retrieve object -
  PyObject *pyo_dst = python_c::create_py_object(it,dst_location);

  // - ERROR -
  if (pyo_dst == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_WRONG_OBJECT_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - retrieve function object -
  PyObject *pyo_fun = PyObject_GetAttrString(pyo_dst,name);
  Py_DECREF(pyo_dst);

  // - ERROR -
  if (pyo_fun == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_INVOKE_METHOD_UNKNOWN_NAME,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - prepare parameters -
  PyObject *pyo_params = PyTuple_New(param_cnt);

  // - ERROR -
  if (pyo_params == nullptr)
  {
    Py_DECREF(pyo_fun);

    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_INVOKE_METHOD_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  if (param_cnt > 0)
  {
    unsigned param_idx = 0;
    do {
      location_s *param_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx + param_idx]);
      PyObject *pyo_param = python_c::create_py_object(it,param_location);

      // - ERROR -
      if (pyo_param == nullptr)
      {
        Py_DECREF(pyo_fun);
        Py_DECREF(pyo_params);

        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_INVOKE_METHOD_WRONG_PARAMETER,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(param_idx);

        return false;
      }

      PyTuple_SetItem(pyo_params,param_idx,pyo_param);

    } while(++param_idx < param_cnt);
  }

  // - call object method -
  PyObject *pyo_result = PyObject_CallObject(pyo_fun,pyo_params);
  Py_DECREF(pyo_fun);
  Py_DECREF(pyo_params);

  // - ERROR -
  if (pyo_result == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_INVOKE_METHOD_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_py_object,pyo_result);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_py_object_member(interpreter_thread_s &it,uli *code,unsigned stack_base)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + code[ioms_stack_object]);

  // - retrieve member name -
  string_s &name_ref = ((interpreter_s *)it.interpreter_ptr)->variable_symbol_names[code[ioms_var_name]];

  // - create key object -
  PyObject *pyo_key = PyString_FromStringAndSize(name_ref.data,name_ref.size - 1);

  // - ERROR -
  if (pyo_key == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_MEMBER_SELECT_ERROR,code[ioms_source_pos],(location_s *)it.blank_location);
    return false;
  }

  // - retrieve object -
  PyObject *pyo_dst = python_c::create_py_object(it,dst_location);

  // - ERROR -
  if (pyo_dst == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_WRONG_OBJECT_REFERENCE,code[ioms_source_pos],(location_s *)it.blank_location);
    return false;
  }

  // - create reference object -
  py_reference_s *py_aref_ptr = (py_reference_s *)cmalloc(sizeof(py_reference_s));
  py_aref_ptr->init();

  py_aref_ptr->pyo_obj = pyo_dst;
  py_aref_ptr->pyo_key = pyo_key;

  // - create target location -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_py_attr_ref,py_aref_ptr);

  pointer &trg_location = it.data_stack[stack_base + code[ioms_stack_trg]];
  it.release_location_ptr((location_s *)trg_location);
  trg_location = (pointer)new_location;

  return true;
}/*}}}*/

bool bic_py_object_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_py_object_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  PyObject *pyo_dst = python_c::create_py_object(it,dst_location);

  // - ERROR -
  if (pyo_dst == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_WRONG_OBJECT_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  PyObject *pyo_src_0 = python_c::create_py_object(it,src_0_location);

  // - ERROR -
  if (pyo_src_0 == nullptr)
  {
    Py_DECREF(pyo_dst);

    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_ITEM_SELECT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create reference object -
  py_reference_s *py_item_ref = (py_reference_s *)cmalloc(sizeof(py_reference_s));
  py_item_ref->init();

  py_item_ref->pyo_obj = pyo_dst;
  py_item_ref->pyo_key = pyo_src_0;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_py_item_ref,py_item_ref);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_py_object_method_PyObject_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - create python object -
  PyObject *pyo_obj = python_c::create_py_object(it,src_0_location);

  // - ERROR -
  if (pyo_obj == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set python object pointer -
  dst_location->v_data_ptr = (PyObject *)pyo_obj;

  return true;
}/*}}}*/

bool bic_py_object_method_module_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_py_object,"module#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - import python module -
  PyObject *pyo_module = PyImport_ImportModule(string_ptr->data);

  // - ERROR -
  if (pyo_module == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_MODULE_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_py_object,pyo_module);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_py_object_method_tuple_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - create python tuple object -
  PyObject *pyo_tuple = python_c::create_py_tuple(it,src_0_location);

  // - ERROR -
  if (pyo_tuple == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_TUPLE_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_py_object,pyo_tuple);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_py_object_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  PyObject *pyo_dst = python_c::create_py_object(it,dst_location);

  // - ERROR -
  if (pyo_dst == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_WRONG_OBJECT_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  location_s *location_ptr = python_c::py_object_value(it,pyo_dst,operands[c_source_pos_idx]);
  Py_DECREF(pyo_dst);

  // - ERROR -
  if (location_ptr == nullptr)
  {
    // - if exception was already thrown -
    if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
    {
      return false;
    }

    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_VALUE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT(location_ptr);

  return true;
}/*}}}*/

bool bic_py_object_method_get_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  PyObject *pyo_dst = python_c::create_py_object(it,dst_location);

  // - ERROR -
  if (pyo_dst == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_WRONG_OBJECT_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - retrieve python object type -
  PyObject *pyo_type = PyObject_Type(pyo_dst);
  Py_DECREF(pyo_dst);

  // - ERROR -
  if (pyo_type == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_TYPE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_py_object,pyo_type);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_py_object_method_has_attr_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  PyObject *pyo_dst = python_c::create_py_object(it,dst_location);

  // - ERROR -
  if (pyo_dst == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_WRONG_OBJECT_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  PyObject *pyo_src_0 = python_c::create_py_object(it,src_0_location);

  // - ERROR -
  if (pyo_src_0 == nullptr)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("has_attr#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - test presence of python object attribute -
  long long int result = PyObject_HasAttr(pyo_dst,pyo_src_0);
  Py_DECREF(pyo_dst);
  Py_DECREF(pyo_src_0);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_py_object_method_get_attr_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  PyObject *pyo_dst = python_c::create_py_object(it,dst_location);

  // - ERROR -
  if (pyo_dst == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_WRONG_OBJECT_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  PyObject *pyo_src_0 = python_c::create_py_object(it,src_0_location);

  // - ERROR -
  if (pyo_src_0 == nullptr)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("get_attr#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve python object attribute -
  PyObject *pyo_attr = PyObject_GetAttr(pyo_dst,pyo_src_0);
  Py_DECREF(pyo_dst);
  Py_DECREF(pyo_src_0);

  // - ERROR -
  if (pyo_attr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_GET_ATTR_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_py_object,pyo_attr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_py_object_method_set_attr_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  PyObject *pyo_dst = python_c::create_py_object(it,dst_location);

  // - ERROR -
  if (pyo_dst == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_WRONG_OBJECT_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  PyObject *pyo_src_0 = python_c::create_py_object(it,src_0_location);
  PyObject *pyo_src_1 = python_c::create_py_object(it,src_1_location);

  // - ERROR -
  if (pyo_src_0 == nullptr || pyo_src_1 == nullptr)
  {
    Py_XDECREF(pyo_src_0);
    Py_XDECREF(pyo_src_1);

    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("set_attr#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  // - set python object attribute -
  int result = PyObject_SetAttr(pyo_dst,pyo_src_0,pyo_src_1);
  Py_DECREF(pyo_dst);
  Py_DECREF(pyo_src_0);
  Py_DECREF(pyo_src_1);

  // - ERROR -
  if (result == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_SET_ATTR_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_py_object_method_del_attr_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  PyObject *pyo_dst = python_c::create_py_object(it,dst_location);

  // - ERROR -
  if (pyo_dst == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_WRONG_OBJECT_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  PyObject *pyo_src_0 = python_c::create_py_object(it,src_0_location);

  // - ERROR -
  if (pyo_src_0 == nullptr)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("del_attr#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - delete python object attribute -
  int result = PyObject_DelAttr(pyo_dst,pyo_src_0);
  Py_DECREF(pyo_dst);
  Py_DECREF(pyo_src_0);

  // - ERROR -
  if (result == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_DEL_ATTR_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_py_object_method_call_attr_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  PyObject *pyo_dst = python_c::create_py_object(it,dst_location);

  // - ERROR -
  if (pyo_dst == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_WRONG_OBJECT_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  PyObject *pyo_name = python_c::create_py_object(it,src_0_location);

  // - ERROR -
  if (pyo_name == nullptr)
  {
    Py_DECREF(pyo_dst);

    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("call_attr#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  PyObject *pyo_fun = PyObject_GetAttr(pyo_dst,pyo_name);
  Py_DECREF(pyo_dst);
  Py_DECREF(pyo_name);

  // - ERROR -
  if (pyo_fun == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_INVOKE_METHOD_UNKNOWN_NAME,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  PyObject *pyo_params = python_c::create_py_tuple(it,src_1_location);

  // - ERROR -
  if (pyo_params == nullptr)
  {
    Py_DECREF(pyo_fun);

    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_INVOKE_METHOD_WRONG_PARAMETER,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(c_idx_not_exist);

    return false;
  }

  // - call object method -
  PyObject *pyo_result = PyObject_CallObject(pyo_fun,pyo_params);
  Py_DECREF(pyo_fun);
  Py_DECREF(pyo_params);

  // - ERROR -
  if (pyo_result == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_INVOKE_METHOD_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_py_object,pyo_result);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_py_object_method_get_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  PyObject *pyo_dst = python_c::create_py_object(it,dst_location);

  // - ERROR -
  if (pyo_dst == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_WRONG_OBJECT_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  PyObject *pyo_src_0 = python_c::create_py_object(it,src_0_location);

  // - ERROR -
  if (pyo_src_0 == nullptr)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("get_item#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve python object item -
  PyObject *pyo_item = PyObject_GetItem(pyo_dst,pyo_src_0);
  Py_DECREF(pyo_dst);
  Py_DECREF(pyo_src_0);

  // - ERROR -
  if (pyo_item == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_GET_ITEM_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_py_object,pyo_item);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_py_object_method_set_item_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  PyObject *pyo_dst = python_c::create_py_object(it,dst_location);

  // - ERROR -
  if (pyo_dst == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_WRONG_OBJECT_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  PyObject *pyo_src_0 = python_c::create_py_object(it,src_0_location);
  PyObject *pyo_src_1 = python_c::create_py_object(it,src_1_location);

  // - ERROR -
  if (pyo_src_0 == nullptr || pyo_src_1 == nullptr)
  {
    Py_XDECREF(pyo_src_0);
    Py_XDECREF(pyo_src_1);

    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("set_item#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  // - retrieve python object item -
  int result = PyObject_SetItem(pyo_dst,pyo_src_0,pyo_src_1);
  Py_DECREF(pyo_dst);
  Py_DECREF(pyo_src_0);
  Py_DECREF(pyo_src_1);

  // - ERROR -
  if (result == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_SET_ITEM_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_py_object_method_del_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  PyObject *pyo_dst = python_c::create_py_object(it,dst_location);

  // - ERROR -
  if (pyo_dst == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_WRONG_OBJECT_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  PyObject *pyo_src_0 = python_c::create_py_object(it,src_0_location);

  // - ERROR -
  if (pyo_src_0 == nullptr)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("del_item#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - delete python object item -
  int result = PyObject_DelItem(pyo_dst,pyo_src_0);
  Py_DECREF(pyo_dst);
  Py_DECREF(pyo_src_0);

  // - ERROR -
  if (result == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_DEL_ITEM_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_py_object_method_dir_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  PyObject *pyo_dst = python_c::create_py_object(it,dst_location);

  // - ERROR -
  if (pyo_dst == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_WRONG_OBJECT_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - retrieve list of python object attributes -
  PyObject *pyo_result = PyObject_Dir(pyo_dst);
  Py_DECREF(pyo_dst);

  // - ERROR -
  if (pyo_result == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_DIR_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_py_object,pyo_result);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_py_object_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  PyObject *pyo_dst = python_c::create_py_object(it,dst_location);

  // - ERROR -
  if (pyo_dst == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_WRONG_OBJECT_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - retrieve python object length -
  long long int length = PyObject_Length(pyo_dst);
  Py_DECREF(pyo_dst);

  // - ERROR -
  if (length == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_LENGTH_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,length);

  return true;
}/*}}}*/

bool bic_py_object_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  PyObject *pyo_dst = python_c::create_py_object(it,dst_location);

  // - ERROR -
  if (pyo_dst == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_WRONG_OBJECT_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - convert python object to python string -
  PyObject *pyo_str = PyObject_Str(pyo_dst);
  Py_DECREF(pyo_dst);

  // - ERROR -
  if (pyo_str == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_TO_STRING_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  char *buffer;
  Py_ssize_t length;

  // - retrieve python string properties -
  PyString_AsStringAndSize(pyo_str,&buffer,&length);

  // - create string object -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(length,buffer);

  // - release python variable -
  Py_DECREF(pyo_str);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_py_object_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  PyObject *pyo_dst = python_c::create_py_object(it,dst_location);

  // - ERROR -
  if (pyo_dst == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_WRONG_OBJECT_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - print python object to stdout -
  PyObject_Print(pyo_dst,stdout,Py_PRINT_RAW);
  Py_DECREF(pyo_dst);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

// - class PY_ATTR_REF -
built_in_class_s py_attr_ref_class =
{/*{{{*/
  "PyAttrRef",
  c_modifier_public | c_modifier_final,
  17, py_attr_ref_methods,
  0, py_attr_ref_variables,
  bic_py_attr_ref_consts,
  bic_py_attr_ref_init,
  bic_py_attr_ref_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  bic_py_object_invoke,
  bic_py_object_member
};/*}}}*/

built_in_method_s py_attr_ref_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_py_attr_ref_operator_binary_equal
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_py_object_operator_binary_le_br_re_br
  },
  {
    "value#0",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_value_0
  },
  {
    "get_type#0",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_get_type_0
  },
  {
    "has_attr#1",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_has_attr_1
  },
  {
    "get_attr#1",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_get_attr_1
  },
  {
    "set_attr#2",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_set_attr_2
  },
  {
    "del_attr#1",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_del_attr_1
  },
  {
    "get_item#1",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_get_item_1
  },
  {
    "set_item#2",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_set_item_2
  },
  {
    "del_item#1",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_del_item_1
  },
  {
    "dir#0",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_dir_0
  },
  {
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_length_0
  },
  {
    "get#0",
    c_modifier_public | c_modifier_final,
    bic_py_attr_ref_method_get_0
  },
  {
    "set#1",
    c_modifier_public | c_modifier_final,
    bic_py_attr_ref_method_set_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_print_0
  },
};/*}}}*/

built_in_variable_s py_attr_ref_variables[] =
{/*{{{*/
};/*}}}*/

void bic_py_attr_ref_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_py_attr_ref_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (py_reference_s *)nullptr;
}/*}}}*/

void bic_py_attr_ref_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  py_reference_s *py_aref_ptr = (py_reference_s *)location_ptr->v_data_ptr;

  if (py_aref_ptr != nullptr)
  {
    py_aref_ptr->clear(it);
    cfree(py_aref_ptr);
  }
}/*}}}*/

bool bic_py_attr_ref_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  PyObject *pyo_src_0 = python_c::create_py_object(it,src_0_location);

  // - ERROR -
  if (pyo_src_0 == nullptr)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_equal#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - ERROR -
  if (!((py_reference_s *)dst_location->v_data_ptr)->set_attr(pyo_src_0))
  {
    Py_DECREF(pyo_src_0);

    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_SET_ATTR_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_py_object,pyo_src_0);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_py_attr_ref_method_get_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  PyObject *pyo_result = ((py_reference_s *)dst_location->v_data_ptr)->get_attr();

  // - ERROR -
  if (pyo_result == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_GET_ATTR_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_py_object,pyo_result);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_py_attr_ref_method_set_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  PyObject *pyo_src_0 = python_c::create_py_object(it,src_0_location);

  // - ERROR -
  if (pyo_src_0 == nullptr)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("set#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  bool result = ((py_reference_s *)dst_location->v_data_ptr)->set_attr(pyo_src_0);
  Py_DECREF(pyo_src_0);

  // - ERROR -
  if (!result)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_SET_ATTR_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

// - class PY_ITEM_REF -
built_in_class_s py_item_ref_class =
{/*{{{*/
  "PyItemRef",
  c_modifier_public | c_modifier_final,
  17, py_item_ref_methods,
  0, py_item_ref_variables,
  bic_py_item_ref_consts,
  bic_py_item_ref_init,
  bic_py_item_ref_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  bic_py_object_invoke,
  bic_py_object_member
};/*}}}*/

built_in_method_s py_item_ref_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_py_item_ref_operator_binary_equal
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_py_object_operator_binary_le_br_re_br
  },
  {
    "value#0",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_value_0
  },
  {
    "get_type#0",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_get_type_0
  },
  {
    "has_attr#1",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_has_attr_1
  },
  {
    "get_attr#1",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_get_attr_1
  },
  {
    "set_attr#2",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_set_attr_2
  },
  {
    "del_attr#1",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_del_attr_1
  },
  {
    "get_item#1",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_get_item_1
  },
  {
    "set_item#2",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_set_item_2
  },
  {
    "del_item#1",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_del_item_1
  },
  {
    "dir#0",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_dir_0
  },
  {
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_length_0
  },
  {
    "get#0",
    c_modifier_public | c_modifier_final,
    bic_py_item_ref_method_get_0
  },
  {
    "set#1",
    c_modifier_public | c_modifier_final,
    bic_py_item_ref_method_set_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_py_object_method_print_0
  },
};/*}}}*/

built_in_variable_s py_item_ref_variables[] =
{/*{{{*/
};/*}}}*/

void bic_py_item_ref_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_py_item_ref_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (py_reference_s *)nullptr;
}/*}}}*/

void bic_py_item_ref_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  py_reference_s *py_iref_ptr = (py_reference_s *)location_ptr->v_data_ptr;

  if (py_iref_ptr != nullptr)
  {
    py_iref_ptr->clear(it);
    cfree(py_iref_ptr);
  }
}/*}}}*/

bool bic_py_item_ref_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  PyObject *pyo_src_0 = python_c::create_py_object(it,src_0_location);

  // - ERROR -
  if (pyo_src_0 == nullptr)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_equal#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - ERROR -
  if (!((py_reference_s *)dst_location->v_data_ptr)->set_item(pyo_src_0))
  {
    Py_DECREF(pyo_src_0);

    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_SET_ITEM_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_py_object,pyo_src_0);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_py_item_ref_method_get_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  PyObject *pyo_result = ((py_reference_s *)dst_location->v_data_ptr)->get_item();

  // - ERROR -
  if (pyo_result == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_GET_ITEM_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_py_object,pyo_result);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_py_item_ref_method_set_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  PyObject *pyo_src_0 = python_c::create_py_object(it,src_0_location);

  // - ERROR -
  if (pyo_src_0 == nullptr)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("set#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  bool result = ((py_reference_s *)dst_location->v_data_ptr)->set_item(pyo_src_0);
  Py_DECREF(pyo_src_0);

  // - ERROR -
  if (!result)
  {
    exception_s::throw_exception(it,module.error_base + c_error_PY_OBJECT_SET_ITEM_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

