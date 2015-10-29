
@begin
include "mono_module.h"
@end

// - MONO indexes of built in classes -
unsigned c_bi_class_mono_assembly = c_idx_not_exist;
unsigned c_bi_class_mono_class = c_idx_not_exist;

// - MONO indexes of remote classes -
unsigned c_rm_class_dict = c_idx_not_exist;

// - MONO module -
built_in_module_s module =
{/*{{{*/
  2,                    // Class count
  mono_classes,         // Classes

  0,                    // Error base index
  6,                    // Error count
  mono_error_strings,   // Error strings

  mono_initialize,      // Initialize function
  mono_print_exception, // Print exceptions function
};/*}}}*/

// - MONO classes -
built_in_class_s *mono_classes[] =
{/*{{{*/
  &mono_assembly_class,
  &mono_class_class,
};/*}}}*/

// - MONO error strings -
const char *mono_error_strings[] =
{/*{{{*/
  "error_MONO_ASSEMBLY_ALREADY_OPEN",
  "error_MONO_ASSEMBLY_NO_STRING_COMMAND_LINE_ARGUMET",
  "error_MONO_ASSEMBLY_OPEN_ERROR",
  "error_MONO_ASSEMBLY_EXEC_ERROR",
  "error_MONO_ASSEMBLY_NOT_OPEN",
  "error_MONO_ASSEMBLY_CLASS_NOT_FOUND",
};/*}}}*/

// - MONO initialize -
bool mono_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize mono_assembly class identifier -
  c_bi_class_mono_assembly = class_base_idx++;

  // - initialize mono_class class identifier -
  c_bi_class_mono_class = class_base_idx++;

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

// - MONO print exception -
bool mono_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_MONO_ASSEMBLY_ALREADY_OPEN:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMono assembly is already open\n");
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
  case c_error_MONO_ASSEMBLY_NOT_OPEN:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMono assembly was not opened yet\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MONO_ASSEMBLY_CLASS_NOT_FOUND:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nRequested class \"%s\" was not found\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
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
  4, mono_assembly_methods,
  0, mono_assembly_variables,
  bic_mono_assembly_consts,
  bic_mono_assembly_init,
  bic_mono_assembly_clear,
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

built_in_method_s mono_assembly_methods[] =
{/*{{{*/
  {
    "open#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_mono_assembly_method_open_2
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
  cassert(0);
}/*}}}*/

void bic_mono_assembly_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_mono_assembly_method_open_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  if (src_0_location->v_type != c_bi_class_string ||
      src_1_location->v_type != c_bi_class_array)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_mono_assembly,"open#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;
  pointer_array_s *array_ptr = (pointer_array_s *)src_1_location->v_data_ptr;

  // - ERROR -
  if (mono_c::assembly != NULL)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MONO_ASSEMBLY_ALREADY_OPEN,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  int argc = array_ptr->used;
  char *argv[array_ptr->used];

  // - retrieve arguments -
  if (array_ptr->used > 0)
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

  // - open mono assembly -
  mono_c::assembly = mono_domain_assembly_open(mono_c::domain,string_ptr->data);

  if (mono_c::assembly != NULL)
  {
    // - retrieve mono assembly image -
    mono_c::image = mono_assembly_get_image(mono_c::assembly);
  }

  // - ERROR -
  if (mono_c::assembly == NULL || mono_c::image == NULL)
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

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_mono_assembly_method_get_class_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
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
  if (mono_c::assembly == NULL)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MONO_ASSEMBLY_NOT_OPEN,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  MonoClass *mc_ptr = mono_class_from_name(mono_c::image,namespace_ptr->data,name_ptr->data);

  // - ERROR -
  if (mc_ptr == NULL)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MONO_ASSEMBLY_CLASS_NOT_FOUND,operands[c_source_pos_idx],src_1_location);
    return false;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_mono_class,mc_ptr);
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
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("MonoAssembly");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class MONO_CLASS -
built_in_class_s mono_class_class =
{/*{{{*/
  "MonoClass",
  c_modifier_public | c_modifier_final,
  5, mono_class_methods,
  0, mono_class_variables,
  bic_mono_class_consts,
  bic_mono_class_init,
  bic_mono_class_clear,
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

built_in_method_s mono_class_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_mono_class_operator_binary_equal
  },
  {
    "name#0",
    c_modifier_public | c_modifier_final,
    bic_mono_class_method_name_0
  },
  {
    "name_space#0",
    c_modifier_public | c_modifier_final,
    bic_mono_class_method_name_space_0
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
  location_ptr->v_data_ptr = (basic_64b)NULL;
}/*}}}*/

void bic_mono_class_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

bool bic_mono_class_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_mono_class_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve class name -
  const char *name = mono_class_get_name((MonoClass *)dst_location->v_data_ptr);

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(name),name);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_mono_class_method_name_space_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve class namespace -
  const char *name_space = mono_class_get_namespace((MonoClass *)dst_location->v_data_ptr);

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(name_space),name_space);

  BIC_SET_RESULT_STRING(string_ptr);

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
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("MonoClass");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

