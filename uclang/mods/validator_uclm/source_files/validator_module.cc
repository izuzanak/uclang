
@begin
include "validator_module.h"
@end

// - VALIDATOR indexes of built in classes -
unsigned c_bi_class_validator = c_idx_not_exist;

// - VALIDATOR indexes of remote classes -
unsigned c_rm_class_set = c_idx_not_exist;
unsigned c_rm_class_dict = c_idx_not_exist;

// - VALIDATOR module -
EXPORT built_in_module_s module =
{/*{{{*/
  1,                         // Class count
  validator_classes,         // Classes

  0,                         // Error base index
  10,                        // Error count
  validator_error_strings,   // Error strings

  validator_initialize,      // Initialize function
  validator_print_exception, // Print exceptions function
};/*}}}*/

// - VALIDATOR classes -
built_in_class_s *validator_classes[] =
{/*{{{*/
  &validator_class,
};/*}}}*/

// - VALIDATOR error strings -
const char *validator_error_strings[] =
{/*{{{*/
  "error_VALIDATOR_ENTRY_NOT_FOUND",
  "error_VALIDATOR_WRONG_PROPERTIES_ARRAY_SIZE",
  "error_VALIDATOR_INVALID_PROPERTY_ID",
  "error_VALIDATOR_INVALID_PROPERTY_TYPE",
  "error_VALIDATOR_INVALID_PROPERTY_REGULAR_EXPRESSION",
  "error_VALIDATOR_INVALID_PROPERTY_DELEGATE",
  "error_VALIDATOR_INVALID_PROPERTY_DELEGATE_RETURN_VALUE",
  "error_VALIDATOR_INVALID_VALUE_TYPE",
  "error_VALIDATOR_INVALID_VALUE_LENGTH",
  "error_VALIDATOR_INVALID_VALUE",
};/*}}}*/

// - VALIDATOR initialize -
bool validator_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize validator class identifier -
  c_bi_class_validator = class_base_idx++;

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

// - VALIDATOR print exception -
bool validator_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_VALIDATOR_ENTRY_NOT_FOUND:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot find validation entry \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_VALIDATOR_WRONG_PROPERTIES_ARRAY_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong size of properties array\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_VALIDATOR_INVALID_PROPERTY_ID:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUnrecognized property identifier \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_VALIDATOR_INVALID_PROPERTY_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid property type\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_VALIDATOR_INVALID_PROPERTY_REGULAR_EXPRESSION:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid property regular expression\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_VALIDATOR_INVALID_PROPERTY_DELEGATE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid property delegate\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_VALIDATOR_INVALID_PROPERTY_DELEGATE_RETURN_VALUE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid return value of property delegate\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_VALIDATOR_INVALID_VALUE_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid value type\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_VALIDATOR_INVALID_VALUE_LENGTH:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid value length\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_VALIDATOR_INVALID_VALUE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid value\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class VALIDATOR -
built_in_class_s validator_class =
{/*{{{*/
  "Validator",
  c_modifier_public | c_modifier_final,
  6, validator_methods,
  0, validator_variables,
  bic_validator_consts,
  bic_validator_init,
  bic_validator_clear,
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

built_in_method_s validator_methods[] =
{/*{{{*/
  {
    "Validator#1",
    c_modifier_public | c_modifier_final,
    bic_validator_method_Validator_1
  },
  {
    "validate#2",
    c_modifier_public | c_modifier_final,
    bic_validator_method_validate_2
  },
  {
    "value_stack#0",
    c_modifier_public | c_modifier_final,
    bic_validator_method_value_stack_0
  },
  {
    "props_stack#0",
    c_modifier_public | c_modifier_final,
    bic_validator_method_props_stack_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_validator_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_validator_method_print_0
  },
};/*}}}*/

built_in_variable_s validator_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_validator_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_validator_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (validator_s *)nullptr;
}/*}}}*/

void bic_validator_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  validator_s *val_ptr = (validator_s *)location_ptr->v_data_ptr;

  if (val_ptr != nullptr)
  {
    val_ptr->clear(it);
    cfree(val_ptr);
  }
}/*}}}*/

bool bic_validator_method_Validator_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
dict:c_rm_class_dict
>
method Validator
; @end

  // - create validator object -
  validator_s *val_ptr = (validator_s *)cmalloc(sizeof(validator_s));
  val_ptr->init();

  src_0_location->v_reference_cnt.atomic_inc();
  val_ptr->schema = src_0_location;

  // - set validator destination location -
  dst_location->v_data_ptr = (validator_s *)val_ptr;

  return true;
}/*}}}*/

bool bic_validator_method_validate_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
ref_name:c_bi_class_string
value:ignore
>
method validate
; @end

  validator_s *val_ptr = (validator_s *)dst_location->v_data_ptr;
  pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)val_ptr->schema->v_data_ptr;

  tree_ptr->it_ptr = &it;
  tree_ptr->source_pos = operands[c_source_pos_idx];

  pointer_map_s search_map = {(pointer)src_0_location,nullptr};
  unsigned index = tree_ptr->get_idx(search_map);

  if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
  {
    return false;
  }

  // - ERROR -
  if (index == c_idx_not_exist)
  {
    exception_s::throw_exception(it,module.error_base + c_error_VALIDATOR_ENTRY_NOT_FOUND,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  val_ptr->it_ptr = &it;
  val_ptr->source_pos = operands[c_source_pos_idx];
  val_ptr->error_base = module.error_base;

  // - release value stack -
  if (val_ptr->value_stack != nullptr)
  {
    it.release_location_ptr(val_ptr->value_stack);
  }

  // - release props stack -
  if (val_ptr->props_stack != nullptr)
  {
    it.release_location_ptr(val_ptr->props_stack);
  }

  // - create value stack -
  {
    pointer_array_s *array_ptr = it.get_new_array_ptr();
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
    val_ptr->value_stack = new_location;
  }

  // - create props stack -
  {
    pointer_array_s *array_ptr = it.get_new_array_ptr();
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
    val_ptr->props_stack = new_location;
  }

  // - ERROR -
  if (!val_ptr->validate_pair(src_1_location,it.get_location_value(tree_ptr->data[index].object.value)))
  {
    src_0_location->v_reference_cnt.atomic_inc();
    ((pointer_array_s *)val_ptr->props_stack->v_data_ptr)->push(src_0_location);

    pointer_array_s new_array;
    new_array.init();

#define BIC_VALIDATOR_METHOD_VALIDATE_REVERSE_STACK(LOCATION) \
{/*{{{*/\
  pointer_array_s *array_ptr = (pointer_array_s *)LOCATION->v_data_ptr;\
  if (array_ptr->used > 1)\
  {\
    new_array.used = 0;\
\
    pointer *ptr = array_ptr->data + array_ptr->used;\
    pointer *ptr_end = array_ptr->data;\
    do {\
      new_array.push(*--ptr);\
    } while(ptr > ptr_end);\
\
    array_ptr->swap(new_array);\
  }\
}/*}}}*/

    // - reverse value stack -
    BIC_VALIDATOR_METHOD_VALIDATE_REVERSE_STACK(val_ptr->value_stack);

    // - reverse props stack -
    BIC_VALIDATOR_METHOD_VALIDATE_REVERSE_STACK(val_ptr->props_stack);

    new_array.clear();

    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_validator_method_value_stack_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  location_s *value_stack = ((validator_s *)dst_location->v_data_ptr)->value_stack;

  if (value_stack != nullptr)
  {
    value_stack->v_reference_cnt.atomic_inc();
    BIC_SET_RESULT(value_stack);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_validator_method_props_stack_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  location_s *props_stack = ((validator_s *)dst_location->v_data_ptr)->props_stack;

  if (props_stack != nullptr)
  {
    props_stack->v_reference_cnt.atomic_inc();
    BIC_SET_RESULT(props_stack);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_validator_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Validator"),"Validator");
  );

  return true;
}/*}}}*/

bool bic_validator_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Validator");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

