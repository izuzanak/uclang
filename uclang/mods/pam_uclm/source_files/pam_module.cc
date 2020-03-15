
@begin
include "pam_module.h"
@end

// - PAM indexes of built in classes -
unsigned c_bi_class_pam = c_idx_not_exist;

// - PAM module -
EXPORT built_in_module_s module =
{/*{{{*/
  1,                   // Class count
  pam_classes,         // Classes

  0,                   // Error base index
  1,                   // Error count
  pam_error_strings,   // Error strings

  pam_initialize,      // Initialize function
  pam_print_exception, // Print exceptions function
};/*}}}*/

// - PAM classes -
built_in_class_s *pam_classes[] =
{/*{{{*/
  &pam_class,
};/*}}}*/

// - PAM error strings -
const char *pam_error_strings[] =
{/*{{{*/
  "error_PAM_DUMMY_ERROR",
};/*}}}*/

// - PAM initialize -
bool pam_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize pam class identifier -
  c_bi_class_pam = class_base_idx++;

  return true;
}/*}}}*/

// - PAM print exception -
bool pam_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_PAM_DUMMY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nPAM dummy error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class PAM -
built_in_class_s pam_class =
{/*{{{*/
  "Pam",
  c_modifier_public | c_modifier_final,
  3, pam_methods,
  0, pam_variables,
  bic_pam_consts,
  bic_pam_init,
  bic_pam_clear,
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

built_in_method_s pam_methods[] =
{/*{{{*/
  {
    "authenticate#3",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_pam_method_authenticate_3
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_pam_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_pam_method_print_0
  },
};/*}}}*/

built_in_variable_s pam_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_pam_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_pam_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_pam_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_pam_method_authenticate_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
service:c_bi_class_string
user:c_bi_class_string
pass:c_bi_class_string
>
class c_bi_class_pam
method authenticate
static_method
; @end

  string_s *service_ptr = (string_s *)src_0_location->v_data_ptr;
  string_s *user_ptr = (string_s *)src_1_location->v_data_ptr;
  string_s *pass_ptr = (string_s *)src_2_location->v_data_ptr;

  long long int result = pam_s::authenticate(service_ptr->data,user_ptr->data,pass_ptr->data);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_pam_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Pam"),"Pam");
  );

  return true;
}/*}}}*/

bool bic_pam_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Pam");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

