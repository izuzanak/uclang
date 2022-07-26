
@begin
include "xxhash_module.h"
@end

// - XXHASH indexes of built in classes -
unsigned c_bi_class_xxhash64 = c_idx_not_exist;

// - XXHASH module -
EXPORT built_in_module_s module =
{/*{{{*/
  1,                      // Class count
  xxhash_classes,         // Classes

  0,                      // Error base index
  2,                      // Error count
  xxhash_error_strings,   // Error strings

  xxhash_initialize,      // Initialize function
  xxhash_print_exception, // Print exceptions function
};/*}}}*/

// - XXHASH classes -
built_in_class_s *xxhash_classes[] =
{/*{{{*/
  &xxhash64_class,
};/*}}}*/

// - XXHASH error strings -
const char *xxhash_error_strings[] =
{/*{{{*/
  "error_XXHASH_CREATE_RESET_ERROR",
  "error_XXHASH_UPDATE_ERROR",
};/*}}}*/

// - XXHASH initialize -
bool xxhash_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize xxhash64 class identifier -
  c_bi_class_xxhash64 = class_base_idx++;

  return true;
}/*}}}*/

// - XXHASH print exception -
bool xxhash_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_XXHASH_CREATE_RESET_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating XXHash digest state\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_XXHASH_UPDATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while updating XXHash digest state\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class XXHash64 -
built_in_class_s xxhash64_class =
{/*{{{*/
  "XXHash64",
  c_modifier_public | c_modifier_final,
  7, xxhash64_methods,
  0, xxhash64_variables,
  bic_xxhash64_consts,
  bic_xxhash64_init,
  bic_xxhash64_clear,
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

built_in_method_s xxhash64_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_xxhash64_operator_binary_equal
  },
  {
    "XXHash64#1",
    c_modifier_public | c_modifier_final,
    bic_xxhash64_method_XXHash64_1
  },
  {
    "hash#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_xxhash64_method_hash_2
  },
  {
    "update#1",
    c_modifier_public | c_modifier_final,
    bic_xxhash64_method_update_1
  },
  {
    "digest#0",
    c_modifier_public | c_modifier_final,
    bic_xxhash64_method_digest_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_xxhash64_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_xxhash64_method_print_0
  },
};/*}}}*/

built_in_variable_s xxhash64_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_xxhash64_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_xxhash64_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (XXH64_state_t *)nullptr;
}/*}}}*/

void bic_xxhash64_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/

  // - retrieve xxh state pointer -
  XXH64_state_t *xxhs_ptr = (XXH64_state_t *)location_ptr->v_data_ptr;

  // - if xxh state pointer is not null release it -
  if (xxhs_ptr != nullptr)
  {
    XXH64_freeState(xxhs_ptr);
  }
}/*}}}*/

bool bic_xxhash64_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_xxhash64_method_XXHash64_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
init:c_bi_class_xxhash64
init:retrieve_integer_init
>
method XXHash64
; @end

  XXH64_state_t *xxhs_ptr = XXH64_createState();

  // - ERROR -
  if (xxhs_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_XXHASH_CREATE_RESET_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  if (src_0_location->v_type == c_bi_class_xxhash64)
  {
    XXH64_state_t *xxhs_src_ptr = (XXH64_state_t *)src_0_location->v_data_ptr;

    XXH64_copyState(xxhs_ptr,xxhs_src_ptr);
  }
  else
  {
    XXH64_hash_t hash;
    memcpy(&hash,&init,sizeof(XXH64_hash_t));

    // - ERROR -
    if (XXH64_reset(xxhs_ptr,hash) == XXH_ERROR)
    {
      XXH64_freeState(xxhs_ptr);

      exception_s::throw_exception(it,module.error_base + c_error_XXHASH_CREATE_RESET_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }
  }

  dst_location->v_data_ptr = (XXH64_state_t *)xxhs_ptr;

  return true;
}/*}}}*/

bool bic_xxhash64_method_hash_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:retrieve_data_buffer
seed:retrieve_integer
>
class c_bi_class_xxhash64
method hash
static_method
; @end

  XXH64_hash_t hash = XXH64(data_ptr,data_size,seed);
  long long int result;
  memcpy(&result,&hash,sizeof(XXH64_hash_t));

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_xxhash64_method_update_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:retrieve_data_buffer
>
method update
; @end

  XXH64_state_t *xxhs_ptr = (XXH64_state_t *)dst_location->v_data_ptr;

  // - ERROR -
  if (XXH64_update(xxhs_ptr,data_ptr,data_size) == XXH_ERROR)
  {
    exception_s::throw_exception(it,module.error_base + c_error_XXHASH_UPDATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_xxhash64_method_digest_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  XXH64_state_t *xxhs_ptr = (XXH64_state_t *)dst_location->v_data_ptr;

  XXH64_hash_t hash = XXH64_digest(xxhs_ptr);
  long long int result;
  memcpy(&result,&hash,sizeof(XXH64_hash_t));

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_xxhash64_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("XXHash64"),"XXHash64");
  );

  return true;
}/*}}}*/

bool bic_xxhash64_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("XXHash64");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

