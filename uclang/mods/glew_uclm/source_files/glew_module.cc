
@begin
include "glew_module.h"
@end

// - GLEW indexes of built in classes -
unsigned c_bi_class_glew = c_idx_not_exist;

// - GLEW module -
EXPORT built_in_module_s module =
{/*{{{*/
  1,                    // Class count
  glew_classes,         // Classes

  0,                    // Error base index
  1,                    // Error count
  glew_error_strings,   // Error strings

  glew_initialize,      // Initialize function
  glew_print_exception, // Print exceptions function
};/*}}}*/

// - GLEW classes -
built_in_class_s *glew_classes[] =
{/*{{{*/
  &glew_class,
};/*}}}*/

// - GLEW error strings -
const char *glew_error_strings[] =
{/*{{{*/
  "error_GLEW_INITIALIZATION_FAILED",
};/*}}}*/

// - GLEW initialize -
bool glew_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize glew class identifier -
  c_bi_class_glew = class_base_idx++;

  return true;
}/*}}}*/

// - GLEW print exception -
bool glew_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_GLEW_INITIALIZATION_FAILED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nGLEW initialization failed\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class GLEW -
built_in_class_s glew_class =
{/*{{{*/
  "Glew",
  c_modifier_public | c_modifier_final,
  5, glew_methods,
  0, glew_variables,
  bic_glew_consts,
  bic_glew_init,
  bic_glew_clear,
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

built_in_method_s glew_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_glew_operator_binary_equal
  },
  {
    "Glew#0",
    c_modifier_public | c_modifier_final,
    bic_glew_method_Glew_0
  },
  {
    "IsSupported#1",
    c_modifier_public | c_modifier_final,
    bic_glew_method_IsSupported_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_glew_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_glew_method_print_0
  },
};/*}}}*/

built_in_variable_s glew_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_glew_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_glew_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

void bic_glew_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

bool bic_glew_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_glew_method_Glew_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/

  // - ERROR -
  if (glewInit() != GLEW_OK)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GLEW_INITIALIZATION_FAILED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  return true;
}/*}}}*/

bool bic_glew_method_IsSupported_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
extension:c_bi_class_string
>
method IsSupported
; @end

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  long long int result = glewIsSupported(string_ptr->data);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_glew_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Glew"),"Glew");
  );

  return true;
}/*}}}*/

bool bic_glew_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Glew");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

