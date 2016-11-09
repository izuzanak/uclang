
@begin
include "iconv_module.h"
@end

// - ICONV indexes of built in classes -
unsigned c_bi_class_iconv = c_idx_not_exist;

// - ICONV module -
built_in_module_s module =
{/*{{{*/
  1,                     // Class count
  iconv_classes,         // Classes

  0,                     // Error base index
  2,                     // Error count
  iconv_error_strings,   // Error strings

  iconv_initialize,      // Initialize function
  iconv_print_exception, // Print exceptions function
};/*}}}*/

// - ICONV classes -
built_in_class_s *iconv_classes[] =
{/*{{{*/
  &iconv_class,
};/*}}}*/

// - ICONV error strings -
const char *iconv_error_strings[] =
{/*{{{*/
  "error_ICONV_OPEN_ERROR",
  "error_ICONV_CONVERT_INVALID_INPUT",
};/*}}}*/

// - ICONV initialize -
bool iconv_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize iconv class identifier -
  c_bi_class_iconv = class_base_idx++;

  return true;
}/*}}}*/

// - ICONV print exception -
bool iconv_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_ICONV_OPEN_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nIconv open descriptor error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_ICONV_CONVERT_INVALID_INPUT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nIconv wrong input data for conversion\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class ICONV -
built_in_class_s iconv_class =
{/*{{{*/
  "Iconv",
  c_modifier_public | c_modifier_final,
  5, iconv_methods,
  0, iconv_variables,
  bic_iconv_consts,
  bic_iconv_init,
  bic_iconv_clear,
  NULL,
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

built_in_method_s iconv_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_iconv_operator_binary_equal
  },
  {
    "Iconv#2",
    c_modifier_public | c_modifier_final,
    bic_iconv_method_Iconv_2
  },
  {
    "convert#1",
    c_modifier_public | c_modifier_final,
    bic_iconv_method_convert_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_iconv_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_iconv_method_print_0
  },
};/*}}}*/

built_in_variable_s iconv_variables[] =
{/*{{{*/
};/*}}}*/

void bic_iconv_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_iconv_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (iconv_s *)NULL;
}/*}}}*/

void bic_iconv_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  iconv_s *ic_ptr = (iconv_s *)location_ptr->v_data_ptr;

  // - if iconv object exists -
  if (ic_ptr != NULL)
  {
    ic_ptr->clear(it);
    cfree(ic_ptr);
  }
}/*}}}*/

bool bic_iconv_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_iconv_method_Iconv_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string ||
      src_1_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Iconv#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  string_s *tocode_ptr = (string_s *)src_0_location->v_data_ptr;
  string_s *fromcode_ptr = (string_s *)src_1_location->v_data_ptr;

  // - ERROR -
  iconv_t new_ic_ptr;
  if ((new_ic_ptr = iconv_open(tocode_ptr->data,fromcode_ptr->data)) == (iconv_t)-1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_ICONV_OPEN_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create iconv object -
  iconv_s *ic_ptr = (iconv_s *)cmalloc(sizeof(iconv_s));
  ic_ptr->init();

  // - set iconv_t pointer -
  ic_ptr->ic_ptr = new_ic_ptr;

  dst_location->v_data_ptr = (iconv_s *)ic_ptr;

  return true;
}/*}}}*/

bool bic_iconv_method_convert_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("convert#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  iconv_s *ic_ptr = (iconv_s *)dst_location->v_data_ptr;
  string_s *input_ptr = (string_s *)src_0_location->v_data_ptr;

  // - if input string is empty -
  if (input_ptr->size <= 1)
  {
    src_0_location->v_reference_cnt.atomic_inc();

    BIC_SET_RESULT(src_0_location);

    return true;
  }

  // - create target buffer -
  bc_array_s output;
  output.init_size(input_ptr->size - 1);
  output.used = output.size;

  // - input pointer and bytes left -
  char *inbuf = input_ptr->data;
  size_t inbytesleft = input_ptr->size - 1;

  // - output pointer and bytes left -
  char *outbuf = output.data;
  size_t outbytesleft = output.used;

  do {
    
    if (iconv(ic_ptr->ic_ptr,&inbuf,&inbytesleft,&outbuf,&outbytesleft) == (size_t)(-1))
    {
      switch (errno)
      {
      case E2BIG:
        {
          // - resize output buffer -
          output.copy_resize(output.size << 1);

          // - update output pointer and bytes left -
          outbuf = output.data + (output.used - outbytesleft);
          outbytesleft += output.size - output.used;

          output.used = output.size;
        }
        break;

      // - ERROR -
      case EILSEQ:
      case EINVAL:
        {
          output.clear();

          // - reset conversion state -
          iconv(ic_ptr->ic_ptr,NULL,NULL,NULL,NULL);

          exception_s::throw_exception(it,module.error_base + c_error_ICONV_CONVERT_INVALID_INPUT,operands[c_source_pos_idx],(location_s *)it.blank_location);
          return false;
        }
        break;
      default:
        cassert(0);
      }
    }

  } while(inbytesleft > 0);

  // - remove unused bytes from buffer -
  output.used -= outbytesleft;

  // - push trailing zero to output buffer -
  output.push('\0');

  // - create output string -
  string_s *output_ptr = it.get_new_string_ptr();
  output_ptr->data = output.data;
  output_ptr->size = output.used;

  BIC_SET_RESULT_STRING(output_ptr);

  return true;
}/*}}}*/

bool bic_iconv_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Iconv"),"Iconv");
  );

  return true;
}/*}}}*/

bool bic_iconv_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("Iconv");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

