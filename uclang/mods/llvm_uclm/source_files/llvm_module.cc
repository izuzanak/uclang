
@begin
include "llvm_module.h"
@end

// - LLVM indexes of built in classes -
unsigned c_bi_class_llvm_context = c_idx_not_exist;
unsigned c_bi_class_llvm_module = c_idx_not_exist;

// - LLVM module -
built_in_module_s module =
{/*{{{*/
  2,                    // Class count
  llvm_classes,         // Classes

  0,                    // Error base index
  2,                    // Error count
  llvm_error_strings,   // Error strings

  llvm_initialize,      // Initialize function
  llvm_print_exception, // Print exceptions function
};/*}}}*/

// - LLVM classes -
built_in_class_s *llvm_classes[] =
{/*{{{*/
  &llvm_context_class,
  &llvm_module_class,
};/*}}}*/

// - LLVM error strings -
const char *llvm_error_strings[] =
{/*{{{*/
  "error_LLVM_PARSER_UNRECOGNIZED_TERMINAL",
  "error_LLVM_PARSER_SYNTAX_ERROR",
};/*}}}*/

// - LLVM initialize -
bool llvm_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize llvm_context class identifier -
  c_bi_class_llvm_context = class_base_idx++;

  // - initialize llvm_module class identifier -
  c_bi_class_llvm_module = class_base_idx++;

  return true;
}/*}}}*/

// - LLVM print exception -
bool llvm_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_LLVM_PARSER_UNRECOGNIZED_TERMINAL:
  case c_error_LLVM_PARSER_SYNTAX_ERROR:
    {
      string_s &llvm_source = *((string_s *)((location_s *)exception.obj_location)->v_data_ptr);
      unsigned llvm_source_pos = exception.params[0];

      fprintf(stderr," ---------------------------------------- \n");
      fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
      fprintf(stderr,"LLVM source string on line: %u\n",llvm_source.get_character_line(llvm_source_pos));
      //print_error_line(llvm_source,llvm_source_pos);
      //print_error_show_line(llvm_source,llvm_source_pos);

      switch (exception.type - module.error_base)
      {
      case c_error_LLVM_PARSER_UNRECOGNIZED_TERMINAL:
        print_error_show_line(llvm_source,llvm_source_pos);
        fprintf(stderr,"Unrecognized input terminal\n");
        fprintf(stderr," ---------------------------------------- \n");
        break;
      case c_error_LLVM_PARSER_SYNTAX_ERROR:
        print_error_show_line(llvm_source,llvm_source_pos);
        fprintf(stderr,"Wrong program syntax\n");
        fprintf(stderr," ---------------------------------------- \n");
        break;
      }
    }
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class LLVM_CONTEXT -
built_in_class_s llvm_context_class =
{/*{{{*/
  "LlvmContext",
  c_modifier_public | c_modifier_final,
  5, llvm_context_methods,
  10, llvm_context_variables,
  bic_llvm_context_consts,
  bic_llvm_context_init,
  bic_llvm_context_clear,
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

built_in_method_s llvm_context_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_llvm_context_operator_binary_equal
  },
  {
    "LlvmContext#0",
    c_modifier_public | c_modifier_final,
    bic_llvm_context_method_LlvmContext_0
  },
  {
    "module#1",
    c_modifier_public | c_modifier_final,
    bic_llvm_context_method_module_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_llvm_context_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_llvm_context_method_print_0
  },
};/*}}}*/

built_in_variable_s llvm_context_variables[] =
{/*{{{*/

  // - llvm data types -
  { "TYPE_I8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_U8", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_I16", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_U16", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_I32", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_U32", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_I64", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_U64", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_F32", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_F64", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_llvm_context_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert llvm data type constants -
  {
    const_locations.push_blanks(10);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 10);

#define CREATE_LLVM_CONTEXT_DATA_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (basic_64b)VALUE;\
  cv_ptr++;

    CREATE_LLVM_CONTEXT_DATA_TYPE_BIC_STATIC(c_var_type_i8);
    CREATE_LLVM_CONTEXT_DATA_TYPE_BIC_STATIC(c_var_type_u8);
    CREATE_LLVM_CONTEXT_DATA_TYPE_BIC_STATIC(c_var_type_i16);
    CREATE_LLVM_CONTEXT_DATA_TYPE_BIC_STATIC(c_var_type_u16);
    CREATE_LLVM_CONTEXT_DATA_TYPE_BIC_STATIC(c_var_type_i32);
    CREATE_LLVM_CONTEXT_DATA_TYPE_BIC_STATIC(c_var_type_u32);
    CREATE_LLVM_CONTEXT_DATA_TYPE_BIC_STATIC(c_var_type_i64);
    CREATE_LLVM_CONTEXT_DATA_TYPE_BIC_STATIC(c_var_type_u64);
    CREATE_LLVM_CONTEXT_DATA_TYPE_BIC_STATIC(c_var_type_f32);
    CREATE_LLVM_CONTEXT_DATA_TYPE_BIC_STATIC(c_var_type_f64);
  }

}/*}}}*/

void bic_llvm_context_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)NULL;
}/*}}}*/

void bic_llvm_context_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  llvm_context_s *llvmc_ptr = (llvm_context_s *)location_ptr->v_data_ptr;

  // - if llvm context object exists -
  if (llvmc_ptr != NULL)
  {
    llvmc_ptr->clear(it);
    cfree(llvmc_ptr);
  }
}/*}}}*/

bool bic_llvm_context_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_llvm_context_method_LlvmContext_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  LLVMContext *context = new LLVMContext();

  // - create llvm context object -
  llvm_context_s *llvmc_ptr = (llvm_context_s *)cmalloc(sizeof(llvm_context_s));
  llvmc_ptr->init();

  llvmc_ptr->context = context;

  dst_location->v_data_ptr = (basic_64b)llvmc_ptr;

  return true;
}/*}}}*/

bool bic_llvm_context_method_module_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  llvm_context_s *llvmc_ptr = (llvm_context_s *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  Module *module = new Module(
    StringRef(string_ptr->data,string_ptr->size - 1),*llvmc_ptr->context);

  // - create llvm module object -
  llvm_module_s *module_ptr = (llvm_module_s *)cmalloc(sizeof(llvm_module_s));
  module_ptr->init();

  module_ptr->module = module;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_llvm_module,module_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_llvm_context_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("LlvmContext"),"LlvmContext");
  );

  return true;
}/*}}}*/

bool bic_llvm_context_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("LlvmContext");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class LLVM_MODULE -
built_in_class_s llvm_module_class =
{/*{{{*/
  "LlvmModule",
  c_modifier_public | c_modifier_final,
  4, llvm_module_methods,
  0, llvm_module_variables,
  bic_llvm_module_consts,
  bic_llvm_module_init,
  bic_llvm_module_clear,
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

built_in_method_s llvm_module_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_llvm_module_operator_binary_equal
  },
  {
    "create_fun#1",
    c_modifier_public | c_modifier_final,
    bic_llvm_module_method_create_fun_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_llvm_module_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_llvm_module_method_print_0
  },
};/*}}}*/

built_in_variable_s llvm_module_variables[] =
{/*{{{*/
};/*}}}*/

void bic_llvm_module_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_llvm_module_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)NULL;
}/*}}}*/

void bic_llvm_module_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  llvm_module_s *module_ptr = (llvm_module_s *)location_ptr->v_data_ptr;

  // - if llvm module object exists -
  if (module_ptr != NULL)
  {
    module_ptr->clear(it);
    cfree(module_ptr);
  }
}/*}}}*/

bool bic_llvm_module_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_llvm_module_method_create_fun_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("create_fun#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create llvm parser -
  llvm_parser_s parser;
  parser.init();
  
  parser.it_ptr = &it;

  // - parse source string -
  parser.source_string = *string_ptr;

  if (!parser.parse_source())
  {
    parser.clear();

    // - retrieve thrown exception -
    exception_s *exception = (exception_s *)((location_s *)it.exception_location)->v_data_ptr;

    // - modify error type and position -
    exception->type += module.error_base;
    exception->position = operands[c_source_pos_idx];

    // - add source string as object to exception -
    it.release_location_ptr((location_s *)exception->obj_location);
    src_0_location->v_reference_cnt.atomic_inc();
    exception->obj_location = src_0_location;

    return false;
  }

  // - release llvm parser -
  parser.clear();

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_llvm_module_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("LlvmModule"),"LlvmModule");
  );

  return true;
}/*}}}*/

bool bic_llvm_module_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("LlvmModule");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

