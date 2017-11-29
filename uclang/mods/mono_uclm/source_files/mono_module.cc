
@begin
include "mono_module.h"
@end

// - MONO indexes of built in classes -
unsigned c_bi_class_mono_assembly = c_idx_not_exist;
unsigned c_bi_class_mono_class = c_idx_not_exist;
unsigned c_bi_class_mono_object = c_idx_not_exist;
unsigned c_bi_class_mono_property = c_idx_not_exist;
unsigned c_bi_class_mono_item_ref = c_idx_not_exist;

// - MONO indexes of remote classes -
unsigned c_rm_class_stack = c_idx_not_exist;
unsigned c_rm_class_queue = c_idx_not_exist;
unsigned c_rm_class_set = c_idx_not_exist;
unsigned c_rm_class_list = c_idx_not_exist;
unsigned c_rm_class_dict = c_idx_not_exist;

// - MONO module -
built_in_module_s module =
{/*{{{*/
  5,                    // Class count
  mono_classes,         // Classes

  0,                    // Error base index
  21,                   // Error count
  mono_error_strings,   // Error strings

  mono_initialize,      // Initialize function
  mono_print_exception, // Print exceptions function
};/*}}}*/

// - MONO classes -
built_in_class_s *mono_classes[] =
{/*{{{*/
  &mono_assembly_class,
  &mono_class_class,
  &mono_object_class,
  &mono_property_class,
  &mono_item_ref_class,
};/*}}}*/

// - MONO error strings -
const char *mono_error_strings[] =
{/*{{{*/
  "error_MONO_RUNTIME_EXCEPTION",
  "error_MONO_ASSEMBLY_ALREADY_OPEN",
  "error_MONO_ASSEMBLY_NO_COMMAND_LINE_ARGUMENTS",
  "error_MONO_ASSEMBLY_NO_STRING_COMMAND_LINE_ARGUMET",
  "error_MONO_ASSEMBLY_OPEN_ERROR",
  "error_MONO_ASSEMBLY_EXEC_ERROR",
  "error_MONO_ASSEMBLY_INVALID_UCLANG_CLASSES",
  "error_MONO_ASSEMBLY_NOT_OPEN",
  "error_MONO_ASSEMBLY_CLASS_NOT_FOUND",
  "error_MONO_CLASS_CANNOT_FIND_CONSTRUCTOR",
  "error_MONO_OBJECT_INVOKE_METHOD_UNKNOWN_NAME",
  "error_MONO_OBJECT_INVOKE_METHOD_WRONG_PARAMETER",
  "error_MONO_OBJECT_MEMBER_SELECT_UNKNOWN_NAME",
  "error_MONO_OBJECT_ITEM_SELECT_ERROR",
  "error_MONO_OBJECT_CREATE_ERROR",
  "error_MONO_OBJECT_WRONG_OBJECT_REFERENCE",
  "error_MONO_OBJECT_ARRAY_CREATE_ERROR",
  "error_MONO_OBJECT_VALUE_ERROR",
  "error_MONO_OBJECT_TO_STRING_ERROR",
  "error_MONO_OBJECT_SET_ITEM_ERROR",
  "error_MONO_PROPERTY_NO_SET_METHOD",
};/*}}}*/

// - MONO initialize -
bool mono_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize mono_assembly class identifier -
  c_bi_class_mono_assembly = class_base_idx++;

  // - initialize mono_class class identifier -
  c_bi_class_mono_class = class_base_idx++;

  // - initialize mono_object class identifier -
  c_bi_class_mono_object = class_base_idx++;

  // - initialize mono_property class identifier -
  c_bi_class_mono_property = class_base_idx++;

  // - initialize mono_item_ref class identifier -
  c_bi_class_mono_item_ref = class_base_idx++;

  // - retrieve remote stack class index -
  c_rm_class_stack = sp.resolve_class_idx_by_name("Stack",c_idx_not_exist);

  // - retrieve remote queue class index -
  c_rm_class_queue = sp.resolve_class_idx_by_name("Queue",c_idx_not_exist);

  // - retrieve remote set class index -
  c_rm_class_set = sp.resolve_class_idx_by_name("Set",c_idx_not_exist);

  // - retrieve remote list class index -
  c_rm_class_list = sp.resolve_class_idx_by_name("List",c_idx_not_exist);

  // - retrieve remote dict class index -
  c_rm_class_dict = sp.resolve_class_idx_by_name("Dict",c_idx_not_exist);

  // - ERROR -
  if (c_rm_class_stack == c_idx_not_exist ||
      c_rm_class_queue == c_idx_not_exist ||
      c_rm_class_set == c_idx_not_exist ||
      c_rm_class_list == c_idx_not_exist ||
      c_rm_class_dict == c_idx_not_exist)
  {
    sp.error_code.push(ei_module_cannot_find_remote_class);
    sp.error_code.push(sp.module_names_positions[sp.module_idx].ui_first);
    sp.error_code.push(sp.module_idx);

    return false;
  }

  return true;
}/*}}}*/

// - MONO print exception -
bool mono_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_MONO_RUNTIME_EXCEPTION:
    {
      location_s *obj_location = (location_s *)exception.obj_location;

      fprintf(stderr," ---------------------------------------- \n");
      fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
      print_error_line(source.source_string,source_pos);
      fprintf(stderr,"\nMono runtime exception");

      if (obj_location->v_type == c_bi_class_string)
      {
        fprintf(stderr,":\n\n%s\n",((string_s *)obj_location->v_data_ptr)->data);
      }
      else
      {
        fprintf(stderr,"\n");
      }

      fprintf(stderr," ---------------------------------------- \n");
    }
    break;
  case c_error_MONO_ASSEMBLY_ALREADY_OPEN:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMono assembly is already open\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MONO_ASSEMBLY_NO_COMMAND_LINE_ARGUMENTS:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMono assembly, expected at least one command line argument\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MONO_ASSEMBLY_NO_STRING_COMMAND_LINE_ARGUMET:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMono assembly, expected string as command line argument\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MONO_ASSEMBLY_OPEN_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while openning mono assembly\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MONO_ASSEMBLY_EXEC_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while executing mono assembly\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MONO_ASSEMBLY_INVALID_UCLANG_CLASSES:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMono assembly invalid uclang classes\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MONO_ASSEMBLY_NOT_OPEN:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMono assembly is not opened\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MONO_ASSEMBLY_CLASS_NOT_FOUND:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nRequested class \"%s\" was not found\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MONO_CLASS_CANNOT_FIND_CONSTRUCTOR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot find requested constructor of object\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MONO_OBJECT_INVOKE_METHOD_UNKNOWN_NAME:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUnknown name of mono object method\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MONO_OBJECT_INVOKE_METHOD_WRONG_PARAMETER:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);

    if (exception.params[0] != c_idx_not_exist)
    {
      fprintf(stderr,"\nCannot process parameter %" HOST_LL_FORMAT "d of mono object method\n",exception.params[0]);
    }
    else
    {
      fprintf(stderr,"\nCannot process parameters of mono object method\n");
    }

    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MONO_OBJECT_MEMBER_SELECT_UNKNOWN_NAME:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUnknown name of mono object property\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MONO_OBJECT_ITEM_SELECT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while selecting item from mono object\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MONO_OBJECT_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating mono object\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MONO_OBJECT_WRONG_OBJECT_REFERENCE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong reference to mono object\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MONO_OBJECT_ARRAY_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating mono array object\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MONO_OBJECT_VALUE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while retrieving mono object value\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MONO_OBJECT_TO_STRING_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot convert mono object to string\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MONO_OBJECT_SET_ITEM_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot set item of mono object\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MONO_PROPERTY_NO_SET_METHOD:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nProperty has no set method defined\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class MONO_ASSEMBLY -
built_in_class_s mono_assembly_class =
{/*{{{*/
  "MonoAssembly",
  c_modifier_public | c_modifier_final,
  5, mono_assembly_methods,
  0, mono_assembly_variables,
  bic_mono_assembly_consts,
  bic_mono_assembly_init,
  bic_mono_assembly_clear,
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

built_in_method_s mono_assembly_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_mono_assembly_operator_binary_equal
  },
  {
    "MonoAssembly#2",
    c_modifier_public | c_modifier_final,
    bic_mono_assembly_method_MonoAssembly_2
  },
  {
    "get_class#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_mono_assembly_method_get_class_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_mono_assembly_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_mono_assembly_method_print_0
  },
};/*}}}*/

built_in_variable_s mono_assembly_variables[] =
{/*{{{*/
};/*}}}*/

void bic_mono_assembly_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_mono_assembly_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (pointer)nullptr;
}/*}}}*/

void bic_mono_assembly_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  if (mono_c::assembly_opened)
  {
    // - reset mono assembly opened flag -
    mono_c::assembly_opened = false;

    if (mono_c::domain != nullptr)
    {
      // - cleanup mono jit -
      mono_jit_cleanup(mono_c::domain);
    }
  }
}/*}}}*/

bool bic_mono_assembly_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_mono_assembly_method_MonoAssembly_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  if (src_0_location->v_type != c_bi_class_string ||
      src_1_location->v_type != c_bi_class_array)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_mono_assembly,"MonoAssembly#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;
  pointer_array_s *array_ptr = (pointer_array_s *)src_1_location->v_data_ptr;

  // - ERROR -
  if (mono_c::assembly != nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MONO_ASSEMBLY_ALREADY_OPEN,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  if (array_ptr->used < 1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MONO_ASSEMBLY_NO_COMMAND_LINE_ARGUMENTS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - retrieve arguments -
  int argc = array_ptr->used;
  char *argv[array_ptr->used];

  {
    pointer *a_ptr = array_ptr->data;
    pointer *a_ptr_end = a_ptr + array_ptr->used;
    char **av_ptr = argv;
    do {
      location_s *item_location = it.get_location_value(*a_ptr);

      // - ERROR -
      if (item_location->v_type != c_bi_class_string)
      {
        exception_s::throw_exception(it,module.error_base + c_error_MONO_ASSEMBLY_NO_STRING_COMMAND_LINE_ARGUMET,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      // - retrieve argument -
      *av_ptr = ((string_s *)item_location->v_data_ptr)->data;

    } while(++av_ptr,++a_ptr < a_ptr_end);
  }

  // - initialize mono domain -
  mono_c::domain = mono_jit_init("uclang");

  if (mono_c::domain != nullptr)
  {
    // - open mono assembly -
    mono_c::assembly = mono_domain_assembly_open(mono_c::domain,string_ptr->data);

    if (mono_c::assembly != nullptr)
    {
      // - retrieve mono assembly image -
      mono_c::image = mono_assembly_get_image(mono_c::assembly);
    }
  }

  // - ERROR -
  if (mono_c::domain == nullptr || mono_c::assembly == nullptr || mono_c::image == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MONO_ASSEMBLY_OPEN_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (mono_jit_exec(mono_c::domain,mono_c::assembly,argc,argv) != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MONO_ASSEMBLY_EXEC_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - retrieve containers class -
  MonoClass *cont_class = mono_class_from_name(mono_c::image,"Uclang","Containers");

  // - ERROR -
  if (cont_class == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MONO_ASSEMBLY_INVALID_UCLANG_CLASSES,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - retrieve container constructors -
  mono_c::list_constr = mono_class_get_method_from_name(cont_class,"list",1);
  mono_c::stack_constr = mono_class_get_method_from_name(cont_class,"stack",1);
  mono_c::queue_constr = mono_class_get_method_from_name(cont_class,"queue",1);
  mono_c::hset_constr = mono_class_get_method_from_name(cont_class,"hset",1);
  mono_c::llist_constr = mono_class_get_method_from_name(cont_class,"llist",1);
  mono_c::dict_constr = mono_class_get_method_from_name(cont_class,"dict",0);

  // - retrieve special methods -
  mono_c::hset_arr = mono_class_get_method_from_name(cont_class,"hset_arr",1);
  mono_c::llist_arr = mono_class_get_method_from_name(cont_class,"llist_arr",1);
  mono_c::dict_arr = mono_class_get_method_from_name(cont_class,"dict_arr",3);

  // - ERROR -
  if (mono_c::list_constr == nullptr ||
      mono_c::stack_constr == nullptr ||
      mono_c::queue_constr == nullptr ||
      mono_c::hset_constr == nullptr ||
      mono_c::llist_constr == nullptr ||
      mono_c::dict_constr == nullptr ||
      mono_c::hset_arr == nullptr ||
      mono_c::llist_arr == nullptr ||
      mono_c::dict_arr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MONO_ASSEMBLY_INVALID_UCLANG_CLASSES,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

#define MONO_ASSEMBLY_OPEN_CHECK_EXCEPTION() \
{/*{{{*/\
  if (mono_c::mono_exc)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_MONO_ASSEMBLY_INVALID_UCLANG_CLASSES,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
}/*}}}*/

  mono_c::mono_exc = nullptr;

  // - create empty array parameter -
  MonoArray *array_obj = mono_array_new(mono_c::domain,mono_get_object_class(),0);
  void **params = (void **)&array_obj;

  // - retrieve container classes -
  mono_c::array_class = mono_array_class_get(mono_get_object_class(),1);

  MonoObject *list_obj = mono_runtime_invoke(mono_c::list_constr,nullptr,params,&mono_c::mono_exc);
  MONO_ASSEMBLY_OPEN_CHECK_EXCEPTION();
  mono_c::list_class = mono_object_get_class(list_obj);

  MonoObject *stack_obj = mono_runtime_invoke(mono_c::stack_constr,nullptr,params,&mono_c::mono_exc);
  MONO_ASSEMBLY_OPEN_CHECK_EXCEPTION();
  mono_c::stack_class = mono_object_get_class(stack_obj);

  MonoObject *queue_obj = mono_runtime_invoke(mono_c::queue_constr,nullptr,params,&mono_c::mono_exc);
  MONO_ASSEMBLY_OPEN_CHECK_EXCEPTION();
  mono_c::queue_class = mono_object_get_class(queue_obj);

  MonoObject *hset_obj = mono_runtime_invoke(mono_c::hset_constr,nullptr,params,&mono_c::mono_exc);
  MONO_ASSEMBLY_OPEN_CHECK_EXCEPTION();
  mono_c::hset_class = mono_object_get_class(hset_obj);

  MonoObject *llist_obj = mono_runtime_invoke(mono_c::llist_constr,nullptr,params,&mono_c::mono_exc);
  MONO_ASSEMBLY_OPEN_CHECK_EXCEPTION();
  mono_c::llist_class = mono_object_get_class(llist_obj);

  MonoObject *dict_obj = mono_runtime_invoke(mono_c::dict_constr,nullptr,nullptr,&mono_c::mono_exc);
  MONO_ASSEMBLY_OPEN_CHECK_EXCEPTION();
  mono_c::dict_class = mono_object_get_class(dict_obj);

  // - retrieve container methods -
  mono_c::list_to_array = mono_class_get_method_from_name(mono_c::list_class,"ToArray",0);
  mono_c::stack_to_array = mono_class_get_method_from_name(mono_c::stack_class,"ToArray",0);
  mono_c::queue_to_array = mono_class_get_method_from_name(mono_c::queue_class,"ToArray",0);

  mono_c::dict_add = mono_class_get_method_from_name(mono_c::dict_class,"Add",2);

  // - ERROR -
  if (mono_c::list_to_array == nullptr ||
      mono_c::stack_to_array == nullptr ||
      mono_c::queue_to_array == nullptr ||
      mono_c::dict_add == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MONO_ASSEMBLY_INVALID_UCLANG_CLASSES,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  mono_c::list_item = mono_class_get_property_from_name(mono_c::list_class,"Item");
  mono_c::dict_item = mono_class_get_property_from_name(mono_c::dict_class,"Item");

  // - ERROR -
  if (mono_c::list_item == nullptr ||
      mono_c::dict_item == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MONO_ASSEMBLY_INVALID_UCLANG_CLASSES,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set mono assembly reference -
  mono_c::assembly_loc = dst_location;

  // - set mono assembly opened flag -
  mono_c::assembly_opened = true;

  return true;
}/*}}}*/

bool bic_mono_assembly_method_get_class_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  if (src_0_location->v_type != c_bi_class_string ||
      src_1_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_mono_assembly,"class#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  string_s *namespace_ptr = (string_s *)src_0_location->v_data_ptr;
  string_s *name_ptr = (string_s *)src_1_location->v_data_ptr;

  // - ERROR -
  if (!mono_c::assembly_opened)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MONO_ASSEMBLY_NOT_OPEN,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  MonoClass *mono_class = mono_class_from_name(mono_c::image,namespace_ptr->data,name_ptr->data);

  // - ERROR -
  if (mono_class == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MONO_ASSEMBLY_CLASS_NOT_FOUND,operands[c_source_pos_idx],src_1_location);
    return false;
  }

  mono_c::assembly_ref_inc();
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mono_class,mono_class);
  BIC_SET_RESULT(new_location)

  return true;
}/*}}}*/

bool bic_mono_assembly_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("MonoAssembly"),"MonoAssembly");
  );

  return true;
}/*}}}*/

bool bic_mono_assembly_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("MonoAssembly");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class MONO_CLASS -
built_in_class_s mono_class_class =
{/*{{{*/
  "MonoClass",
  c_modifier_public | c_modifier_final,
  9, mono_class_methods,
  0, mono_class_variables,
  bic_mono_class_consts,
  bic_mono_class_init,
  bic_mono_class_clear,
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

built_in_method_s mono_class_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_mono_class_operator_binary_equal
  },
  {
    "_name#0",
    c_modifier_public | c_modifier_final,
    bic_mono_class_method__name_0
  },
  {
    "_namespace#0",
    c_modifier_public | c_modifier_final,
    bic_mono_class_method__namespace_0
  },
  {
    "_new#1",
    c_modifier_public | c_modifier_final,
    bic_mono_class_method__new_1
  },
  {
    "fields#0",
    c_modifier_public | c_modifier_final,
    bic_mono_class_method_fields_0
  },
  {
    "methods#0",
    c_modifier_public | c_modifier_final,
    bic_mono_class_method_methods_0
  },
  {
    "properties#0",
    c_modifier_public | c_modifier_final,
    bic_mono_class_method_properties_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_mono_class_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_mono_class_method_print_0
  },
};/*}}}*/

built_in_variable_s mono_class_variables[] =
{/*{{{*/
};/*}}}*/

void bic_mono_class_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_mono_class_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (MonoClass *)nullptr;
}/*}}}*/

void bic_mono_class_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  mono_c::assembly_ref_dec(it);
}/*}}}*/

bool bic_mono_class_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_mono_class_method__name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve class name -
  const char *name = mono_class_get_name((MonoClass *)dst_location->v_data_ptr);

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(name),name);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_mono_class_method__namespace_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve class namespace -
  const char *nmspace = mono_class_get_namespace((MonoClass *)dst_location->v_data_ptr);

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(nmspace),nmspace);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_mono_class_method__new_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - create mono array object -
  MonoObject *mono_params = mono_c::create_mono_array(it,src_0_location);

  // - ERROR -
  if (mono_params == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MONO_OBJECT_ARRAY_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  MonoClass *mono_class = (MonoClass *)dst_location->v_data_ptr;

  uintptr_t param_cnt = mono_array_length((MonoArray *)mono_params);
  MonoMethod *mono_ctor = mono_class_get_method_from_name(mono_class,".ctor",param_cnt);

  // - ERROR -
  if (mono_ctor == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MONO_CLASS_CANNOT_FIND_CONSTRUCTOR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  MonoObject *mono_obj = mono_object_new(mono_c::domain,mono_class);

  mono_c::mono_exc = nullptr;
  mono_runtime_invoke_array(mono_ctor,mono_obj,(MonoArray *)mono_params,&mono_c::mono_exc);
  BIC_MONO_CHECK_EXCEPTION_RETHROW();

  // - create mono object handle -
  guint32 gchandle = mono_c::gchandle_new(mono_obj);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mono_object,gchandle);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_mono_class_method_fields_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  MonoClass *mono_class = (MonoClass *)dst_location->v_data_ptr;

  // - create target array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  MonoClassField *mf_ptr;
  void *iter = nullptr;
  while ((mf_ptr = mono_class_get_fields(mono_class,&iter)))
  {
    // - retrieve field name -
    const char *name = mono_field_get_name(mf_ptr);

    // - create field name string -
    string_s *string_ptr = it.get_new_string_ptr();
    string_ptr->set(strlen(name),name);

    // - create field name location -
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
    array_ptr->push(new_location);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_mono_class_method_methods_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  MonoClass *mono_class = (MonoClass *)dst_location->v_data_ptr;

  // - create target array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  MonoMethod *mm_ptr;
  void *iter = nullptr;
  while ((mm_ptr = mono_class_get_methods(mono_class,&iter)))
  {
    // - retrieve method name -
    const char *name = mono_method_get_name(mm_ptr);

    // - create method name string -
    string_s *string_ptr = it.get_new_string_ptr();
    string_ptr->set(strlen(name),name);

    // - create method name location -
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
    array_ptr->push(new_location);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_mono_class_method_properties_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  MonoClass *mono_class = (MonoClass *)dst_location->v_data_ptr;

  // - create target array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  MonoProperty *mono_prop;
  void *iter = nullptr;
  while ((mono_prop = mono_class_get_properties(mono_class,&iter)))
  {
    // - retrieve property name -
    const char *name = mono_property_get_name(mono_prop);

    // - create property name string -
    string_s *string_ptr = it.get_new_string_ptr();
    string_ptr->set(strlen(name),name);

    // - create property name location -
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
    array_ptr->push(new_location);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_mono_class_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("MonoClass"),"MonoClass");
  );

  return true;
}/*}}}*/

bool bic_mono_class_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("MonoClass");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class MONO_OBJECT -
built_in_class_s mono_object_class =
{/*{{{*/
  "MonoObject",
  c_modifier_public | c_modifier_final,
  8, mono_object_methods,
  0, mono_object_variables,
  bic_mono_object_consts,
  bic_mono_object_init,
  bic_mono_object_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  bic_mono_object_invoke,
  bic_mono_object_member
};/*}}}*/

built_in_method_s mono_object_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_mono_object_operator_binary_equal
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_mono_object_operator_binary_le_br_re_br
  },
  {
    "MonoObject#1",
    c_modifier_public | c_modifier_final,
    bic_mono_object_method_MonoObject_1
  },
  {
    "_array#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_mono_object_method__array_1
  },
  {
    "_value#0",
    c_modifier_public | c_modifier_final,
    bic_mono_object_method__value_0
  },
  {
    "_class#0",
    c_modifier_public | c_modifier_final,
    bic_mono_object_method__class_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_mono_object_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_mono_object_method_print_0
  },
};/*}}}*/

built_in_variable_s mono_object_variables[] =
{/*{{{*/
};/*}}}*/

void bic_mono_object_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_mono_object_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (guint32)0;
}/*}}}*/

void bic_mono_object_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  guint32 gchandle = (guint32)location_ptr->v_data_ptr;

  if (gchandle != 0)
  {
    mono_c::gchandle_free(it,gchandle);
  }
}/*}}}*/

bool bic_mono_object_invoke(interpreter_thread_s &it,uli *code,unsigned stack_base,uli *operands)
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
  MonoObject *mono_dst = mono_c::create_mono_object(it,dst_location);

  // - ERROR -
  if (mono_dst == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MONO_OBJECT_WRONG_OBJECT_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - retrieve object method -
  MonoClass *mono_class = mono_object_get_class(mono_dst);
  MonoMethod *mono_method = mono_class_get_method_from_name(mono_class,name,param_cnt);

  // - ERROR -
  if (mono_method == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MONO_OBJECT_INVOKE_METHOD_UNKNOWN_NAME,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - prepare parameters -
  MonoArray *mono_params = mono_array_new(mono_c::domain,mono_get_object_class(),param_cnt);

  if (param_cnt > 0)
  {
    unsigned param_idx = 0;
    do {
      location_s *param_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx + param_idx]);
      MonoObject *mono_param = mono_c::create_mono_object(it,param_location);

      // - ERROR -
      if (mono_param == nullptr)
      {
        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_MONO_OBJECT_INVOKE_METHOD_WRONG_PARAMETER,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(param_idx);

        return false;
      }

      mono_array_set(mono_params,MonoObject *,param_idx,mono_param);

    } while(++param_idx < param_cnt);
  }

  // - call object method -
  mono_c::mono_exc = nullptr;
  MonoObject *mono_result = mono_runtime_invoke_array(mono_method,mono_dst,mono_params,&mono_c::mono_exc);
  BIC_MONO_CHECK_EXCEPTION_RETHROW();

  // - create mono object handle -
  guint32 gchandle = mono_c::gchandle_new(mono_result);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mono_object,gchandle);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_mono_object_member(interpreter_thread_s &it,uli *code,unsigned stack_base)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + code[ioms_stack_object]);

  // - retrieve member name -
  string_s &name_ref = ((interpreter_s *)it.interpreter_ptr)->variable_symbol_names[code[ioms_var_name]];

  // - retrieve object -
  MonoObject *mono_dst = mono_c::create_mono_object(it,dst_location);

  // - ERROR -
  if (mono_dst == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MONO_OBJECT_WRONG_OBJECT_REFERENCE,code[ioms_source_pos],(location_s *)it.blank_location);
    return false;
  }

  // - retrieve property -
  MonoClass *mono_class = mono_object_get_class(mono_dst);
  MonoProperty *mono_prop = mono_class_get_property_from_name(mono_class,name_ref.data);

  // - ERROR -
  if (mono_prop == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MONO_OBJECT_MEMBER_SELECT_UNKNOWN_NAME,code[ioms_source_pos],(location_s *)it.blank_location);
    return false;
  }

  // - create property object -
  mono_property_s *mp_ptr = (mono_property_s *)cmalloc(sizeof(mono_property_s));
  mp_ptr->init();

  mp_ptr->mono_prop = mono_prop;
  mp_ptr->gchandle = mono_gchandle_new(mono_dst,TRUE);

  // - create target location -
  mono_c::assembly_ref_inc();
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mono_property,mp_ptr);

  pointer &trg_location = it.data_stack[stack_base + code[ioms_stack_trg]];
  it.release_location_ptr((location_s *)trg_location);
  trg_location = (pointer)new_location;

  return true;
}/*}}}*/

bool bic_mono_object_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_mono_object_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  MonoObject *mono_dst = mono_c::create_mono_object(it,dst_location);

  // - ERROR -
  if (mono_dst == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MONO_OBJECT_WRONG_OBJECT_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  MonoObject *mono_src_0 = mono_c::create_mono_object(it,src_0_location);

  // - ERROR -
  if (mono_src_0 == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MONO_OBJECT_ITEM_SELECT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create reference object -
  mono_reference_s *mr_ptr = (mono_reference_s *)cmalloc(sizeof(mono_reference_s));
  mr_ptr->init();

  mr_ptr->gchnd_obj = mono_gchandle_new(mono_dst,TRUE);
  mr_ptr->gchnd_key = mono_gchandle_new(mono_src_0,TRUE);

  mono_c::assembly_ref_inc();
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mono_item_ref,mr_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_mono_object_method_MonoObject_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (!mono_c::assembly_opened)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MONO_ASSEMBLY_NOT_OPEN,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create mono object -
  MonoObject *mono_obj = mono_c::create_mono_object(it,src_0_location);

  // - ERROR -
  if (mono_obj == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MONO_OBJECT_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create mono object handle -
  guint32 gchandle = mono_c::gchandle_new(mono_obj);

  // - set mono object handle -
  dst_location->v_data_ptr = (guint32)gchandle;

  return true;
}/*}}}*/

bool bic_mono_object_method__array_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (!mono_c::assembly_opened)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MONO_ASSEMBLY_NOT_OPEN,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create mono array object -
  MonoObject *mono_array = mono_c::create_mono_array(it,src_0_location);

  // - ERROR -
  if (mono_array == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MONO_OBJECT_ARRAY_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create mono object handle -
  guint32 gchandle = mono_c::gchandle_new(mono_array);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mono_object,gchandle);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_mono_object_method__value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  MonoObject *mono_dst = mono_c::create_mono_object(it,dst_location);

  // - ERROR -
  if (mono_dst == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MONO_OBJECT_WRONG_OBJECT_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  location_s *location_ptr = mono_c::mono_object_value(it,mono_dst,operands[c_source_pos_idx]);

  // - ERROR -
  if (location_ptr == nullptr)
  {
    // - if exception was already thrown -
    if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
    {
      return false;
    }

    exception_s::throw_exception(it,module.error_base + c_error_MONO_OBJECT_VALUE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT(location_ptr);

  return true;
}/*}}}*/

bool bic_mono_object_method__class_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  MonoObject *mono_dst = mono_c::create_mono_object(it,dst_location);

  // - ERROR -
  if (mono_dst == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MONO_OBJECT_WRONG_OBJECT_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  MonoClass *mono_class = mono_object_get_class(mono_dst);

  mono_c::assembly_ref_inc();
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mono_class,mono_class)
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_mono_object_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  MonoObject *mono_dst = mono_c::create_mono_object(it,dst_location);

  // - ERROR -
  if (mono_dst == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MONO_OBJECT_WRONG_OBJECT_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  mono_c::mono_exc = nullptr;
  MonoString *mono_str = mono_object_to_string(mono_dst,&mono_c::mono_exc);
  BIC_MONO_CHECK_EXCEPTION_RETHROW();

  MonoError error;
  char *utf8_str = mono_string_to_utf8_checked(mono_str,&error);

  // - ERROR -
  if (!mono_error_ok(&error))
  {
    mono_error_cleanup(&error);

    exception_s::throw_exception(it,module.error_base + c_error_MONO_OBJECT_TO_STRING_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create string object -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(utf8_str),utf8_str);
  mono_free(utf8_str);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_mono_object_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  MonoObject *mono_dst = mono_c::create_mono_object(it,dst_location);

  // - ERROR -
  if (mono_dst == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MONO_OBJECT_WRONG_OBJECT_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  mono_c::mono_exc = nullptr;
  MonoString *mono_str = mono_object_to_string(mono_dst,&mono_c::mono_exc);
  BIC_MONO_CHECK_EXCEPTION_RETHROW();

  MonoError error;
  char *utf8_str = mono_string_to_utf8_checked(mono_str,&error);

  // - ERROR -
  if (!mono_error_ok(&error))
  {
    mono_error_cleanup(&error);

    exception_s::throw_exception(it,module.error_base + c_error_MONO_OBJECT_TO_STRING_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - print string content -
  fwrite(utf8_str,strlen(utf8_str),1,stdout);
  mono_free(utf8_str);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

// - class MONO_PROPERTY -
built_in_class_s mono_property_class =
{/*{{{*/
  "MonoProperty",
  c_modifier_public | c_modifier_final,
  6, mono_property_methods,
  0, mono_property_variables,
  bic_mono_property_consts,
  bic_mono_property_init,
  bic_mono_property_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  bic_mono_object_invoke,
  bic_mono_object_member
};/*}}}*/

built_in_method_s mono_property_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_mono_property_operator_binary_equal
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_mono_object_operator_binary_le_br_re_br
  },
  {
    "_value#0",
    c_modifier_public | c_modifier_final,
    bic_mono_object_method__value_0
  },
  {
    "_class#0",
    c_modifier_public | c_modifier_final,
    bic_mono_object_method__class_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_mono_object_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_mono_object_method_print_0
  },
};/*}}}*/

built_in_variable_s mono_property_variables[] =
{/*{{{*/
};/*}}}*/

void bic_mono_property_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_mono_property_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (mono_property_s *)nullptr;
}/*}}}*/

void bic_mono_property_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  mono_property_s *mp_ptr = (mono_property_s *)location_ptr->v_data_ptr;

  if (mp_ptr != nullptr)
  {
    mp_ptr->clear(it);
    cfree(mp_ptr);

    mono_c::assembly_ref_dec(it);
  }
}/*}}}*/

bool bic_mono_property_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  MonoObject *mono_src_0 = mono_c::create_mono_object(it,src_0_location);

  // - ERROR -
  if (mono_src_0 == nullptr)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_equal#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  mono_property_s *mp_ptr = (mono_property_s *)dst_location->v_data_ptr;
  MonoMethod *mono_set_method = mono_property_get_set_method(mp_ptr->mono_prop);

  // - ERROR -
  if (mono_set_method == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MONO_PROPERTY_NO_SET_METHOD,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  MonoArray *mono_params = mono_array_new(mono_c::domain,mono_get_object_class(),1);
  mono_array_set(mono_params,MonoObject *,0,mono_src_0);

  mono_c::mono_exc = nullptr;
  mono_runtime_invoke_array(mono_set_method,
      mono_gchandle_get_target(mp_ptr->gchandle),mono_params,&mono_c::mono_exc);
  BIC_MONO_CHECK_EXCEPTION_RETHROW();

  // - create mono object handle -
  guint32 gchandle = mono_c::gchandle_new(mono_src_0);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mono_object,gchandle);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

// - class MONO_ITEM_REF -
built_in_class_s mono_item_ref_class =
{/*{{{*/
  "MonoItemRef",
  c_modifier_public | c_modifier_final,
  6, mono_item_ref_methods,
  0, mono_item_ref_variables,
  bic_mono_item_ref_consts,
  bic_mono_item_ref_init,
  bic_mono_item_ref_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  bic_mono_object_invoke,
  bic_mono_object_member
};/*}}}*/

built_in_method_s mono_item_ref_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_mono_item_ref_operator_binary_equal
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_mono_object_operator_binary_le_br_re_br
  },
  {
    "_value#0",
    c_modifier_public | c_modifier_final,
    bic_mono_object_method__value_0
  },
  {
    "_class#0",
    c_modifier_public | c_modifier_final,
    bic_mono_object_method__class_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_mono_object_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_mono_object_method_print_0
  },
};/*}}}*/

built_in_variable_s mono_item_ref_variables[] =
{/*{{{*/
};/*}}}*/

void bic_mono_item_ref_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_mono_item_ref_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (mono_reference_s *)nullptr;
}/*}}}*/

void bic_mono_item_ref_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  mono_reference_s *mr_ptr = (mono_reference_s *)location_ptr->v_data_ptr;

  if (mr_ptr != nullptr)
  {
    mr_ptr->clear(it);
    cfree(mr_ptr);

    mono_c::assembly_ref_dec(it);
  }
}/*}}}*/

bool bic_mono_item_ref_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  MonoObject *mono_src_0 = mono_c::create_mono_object(it,src_0_location);

  // - ERROR -
  if (mono_src_0 == nullptr)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_equal#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - ERROR -
  if (!((mono_reference_s *)dst_location->v_data_ptr)->set_item(mono_src_0))
  {
    exception_s::throw_exception(it,module.error_base + c_error_MONO_OBJECT_SET_ITEM_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create mono object handle -
  guint32 gchandle = mono_c::gchandle_new(mono_src_0);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mono_object,gchandle);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

