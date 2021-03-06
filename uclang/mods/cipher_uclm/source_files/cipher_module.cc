
@begin
include "cipher_module.h"
@end

// - CIPHER indexes of built in classes -
unsigned c_bi_class_cipher_rc4 = c_idx_not_exist;

// - CIPHER module -
EXPORT built_in_module_s module =
{/*{{{*/
  1,                       // Class count
  cipher_classes,          // Classes

  0,                       // Error base index
  0,                       // Error count
  cipher_error_strings,    // Error strings

  cipher_initialize,       // Initialize function
  cipher_print_exception,  // Print exceptions function
};/*}}}*/

// - CIPHER classes -
built_in_class_s *cipher_classes[] =
{/*{{{*/
  &cipher_rc4_class,
};/*}}}*/

// - CIPHER error strings -
const char *cipher_error_strings[] =
{/*{{{*/
  BIC_MODULE_EMPTY_ERROR_STRINGS
};/*}}}*/

// - CIPHER initialize -
bool cipher_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize cipher_rc4 class identifier -
  c_bi_class_cipher_rc4 = class_base_idx++;

  return true;
}/*}}}*/

// - CIPHER print exception -
bool cipher_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  return false;
}/*}}}*/

// - class CIPHER_RC4 -
built_in_class_s cipher_rc4_class =
{/*{{{*/
  "CipherRc4",
  c_modifier_public | c_modifier_final,
  5, cipher_rc4_methods,
  0, cipher_rc4_variables,
  bic_cipher_rc4_consts,
  bic_cipher_rc4_init,
  bic_cipher_rc4_clear,
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

built_in_method_s cipher_rc4_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_cipher_rc4_operator_binary_equal
  },
  {
    "CipherRc4#1",
    c_modifier_public | c_modifier_final,
    bic_cipher_rc4_method_CipherRc4_1
  },
  {
    "process#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cipher_rc4_method_process_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cipher_rc4_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cipher_rc4_method_print_0
  },
};/*}}}*/

built_in_variable_s cipher_rc4_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_cipher_rc4_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_cipher_rc4_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (cipher_s *)nullptr;
}/*}}}*/

void bic_cipher_rc4_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cipher_s *cipher_ptr = (cipher_s *)location_ptr->v_data_ptr;

  // - if cipher exists -
  if (cipher_ptr != nullptr)
  {
    cipher_ptr->clear();
    cfree(cipher_ptr);
  }
}/*}}}*/

bool bic_cipher_rc4_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_cipher_rc4_method_CipherRc4_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
key:retrieve_data_buffer
>
method CipherRc4
; @end

  // - create cipher object -
  cipher_s *cipher_ptr = (cipher_s *)cmalloc(sizeof(cipher_s));
  cipher_ptr->init();

  // - initialize cipher by given key -
  cipher_ptr->create(key_size,(const char *)key_ptr);

  dst_location->v_data_ptr = (cipher_s *)cipher_ptr;

  return true;
}/*}}}*/

bool bic_cipher_rc4_method_process_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:retrieve_data_buffer
>
method process
; @end

  // - retrieve cipher object -
  cipher_s *cipher_ptr = (cipher_s *)dst_location->v_data_ptr;

  // - retrieve source string -

  // - create new string -
  string_s *target_ptr = it.get_new_string_ptr();
  target_ptr->set(data_size,(const char *)data_ptr);

  // - process target string data -
  cipher_ptr->process(target_ptr->size - 1,target_ptr->data);

  BIC_SET_RESULT_STRING(target_ptr);

  return true;
}/*}}}*/

bool bic_cipher_rc4_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("CipherRc4"),"CipherRc4");
  );

  return true;
}/*}}}*/

bool bic_cipher_rc4_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("CipherRc4");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

