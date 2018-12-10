
@begin
include "intelhex_module.h"
@end

// - INTELHEX indexes of built in classes -
unsigned c_bi_class_intel_hex = c_idx_not_exist;

// - INTELHEX module -
built_in_module_s module =
{/*{{{*/
  1,                        // Class count
  intelhex_classes,         // Classes

  0,                        // Error base index
  6,                        // Error count
  intelhex_error_strings,   // Error strings

  intelhex_initialize,      // Initialize function
  intelhex_print_exception, // Print exceptions function
};/*}}}*/

// - INTELHEX classes -
built_in_class_s *intelhex_classes[] =
{/*{{{*/
  &intel_hex_class,
};/*}}}*/

// - INTELHEX error strings -
const char *intelhex_error_strings[] =
{/*{{{*/
  "error_INTEL_HEX_FILE_OPEN_ERROR",
  "error_INTEL_HEX_WRONG_CALLBACK_DELEGATE",
  "error_INTEL_HEX_INVALID_RECORD_LENGTH",
  "error_INTEL_HEX_INVALID_RECORD_DATA",
  "error_INTEL_HEX_INVALID_RECORD_TYPE",
  "error_INTEL_HEX_UNEXPECTED_DATA_END",
};/*}}}*/

// - INTELHEX initialize -
bool intelhex_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize intel_hex class identifier -
  c_bi_class_intel_hex = class_base_idx++;

  return true;
}/*}}}*/

// - INTELHEX print exception -
bool intelhex_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_INTEL_HEX_FILE_OPEN_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot open Intel HEX file \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_INTEL_HEX_WRONG_CALLBACK_DELEGATE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong type of delegate for Intel HEX reader\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_INTEL_HEX_INVALID_RECORD_LENGTH:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid length of Intel HEX record on line: %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_INTEL_HEX_INVALID_RECORD_DATA:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid data of Intel HEX record on line: %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_INTEL_HEX_INVALID_RECORD_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid type of Intel HEX record on line: %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_INTEL_HEX_UNEXPECTED_DATA_END:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUnexpected end of Intel HEX data source\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class INTEL_HEX -
built_in_class_s intel_hex_class =
{/*{{{*/
  "IntelHex",
  c_modifier_public | c_modifier_final,
  11, intel_hex_methods,
  0, intel_hex_variables,
  bic_intel_hex_consts,
  bic_intel_hex_init,
  bic_intel_hex_clear,
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

built_in_method_s intel_hex_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_intel_hex_operator_binary_equal
  },
  {
    "IntelHex#1",
    c_modifier_public | c_modifier_final,
    bic_intel_hex_method_IntelHex_1
  },
  {
    "IntelHex#2",
    c_modifier_public | c_modifier_final,
    bic_intel_hex_method_IntelHex_2
  },
  {
    "esa#0",
    c_modifier_public | c_modifier_final,
    bic_intel_hex_method_esa_0
  },
  {
    "ssa_cs#0",
    c_modifier_public | c_modifier_final,
    bic_intel_hex_method_ssa_cs_0
  },
  {
    "ssa_ip#0",
    c_modifier_public | c_modifier_final,
    bic_intel_hex_method_ssa_ip_0
  },
  {
    "ela#0",
    c_modifier_public | c_modifier_final,
    bic_intel_hex_method_ela_0
  },
  {
    "sla_eip#0",
    c_modifier_public | c_modifier_final,
    bic_intel_hex_method_sla_eip_0
  },
  {
    "next_item#0",
    c_modifier_public | c_modifier_final,
    bic_intel_hex_method_next_item_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_intel_hex_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_intel_hex_method_print_0
  },
};/*}}}*/

built_in_variable_s intel_hex_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_INTEL_HEX_CONSTRUCTOR_OPEN_FILE() \
/*{{{*/\
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;\
\
  /* - ERROR - */\
  FILE *f = fopen(string_ptr->data,"r");\
  if (f == nullptr)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_INTEL_HEX_FILE_OPEN_ERROR,operands[c_source_pos_idx],src_0_location);\
    return false;\
  }\
\
  /* - create intel_hex object - */\
  intel_hex_s *ih_ptr = (intel_hex_s *)cmalloc(sizeof(intel_hex_s));\
  ih_ptr->init();\
\
  ih_ptr->file = f;\
  ih_ptr->line_cnt = 0;\
\
  /* - reset read done flag - */\
  ih_ptr->read_done = false;\
\
  ih_ptr->esa     = 0;\
  ih_ptr->ssa_cs  = 0;\
  ih_ptr->ssa_ip  = 0;\
  ih_ptr->ela     = 0;\
  ih_ptr->sla_eip = 0;\
/*}}}*/

#define BIC_INTEL_HEX_METHOD_VALUE_INTEGER(NAME) \
{/*{{{*/\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  long long int result = ((intel_hex_s *)dst_location->v_data_ptr)->NAME;\
\
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
\
  return true;\
}/*}}}*/

void bic_intel_hex_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_intel_hex_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (intel_hex_s *)nullptr;
}/*}}}*/

void bic_intel_hex_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  intel_hex_s *ih_ptr = (intel_hex_s *)location_ptr->v_data_ptr;

  if (ih_ptr != nullptr)
  {
    ih_ptr->clear(it);
    cfree(ih_ptr);
  }
}/*}}}*/

bool bic_intel_hex_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_intel_hex_method_IntelHex_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
path:c_bi_class_string
>
method IntelHex
; @end

  BIC_INTEL_HEX_CONSTRUCTOR_OPEN_FILE();

  // - set intel_hex destination location -
  dst_location->v_data_ptr = (intel_hex_s *)ih_ptr;

  return true;
}/*}}}*/

bool bic_intel_hex_method_IntelHex_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
path:c_bi_class_string
delegate:c_bi_class_delegate
>
method IntelHex
; @end

  delegate_s *delegate_ptr = (delegate_s *)src_1_location->v_data_ptr;

  // - ERROR -
  if (delegate_ptr->param_cnt != 2)
  {
    exception_s::throw_exception(it,module.error_base + c_error_INTEL_HEX_WRONG_CALLBACK_DELEGATE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_INTEL_HEX_CONSTRUCTOR_OPEN_FILE();

  // - set callback delegate -
  src_1_location->v_reference_cnt.atomic_inc();
  ih_ptr->callback_dlg = src_1_location;

  // - set intel_hex destination location -
  dst_location->v_data_ptr = (intel_hex_s *)ih_ptr;

  return true;
}/*}}}*/

bool bic_intel_hex_method_esa_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INTEL_HEX_METHOD_VALUE_INTEGER(esa);
}/*}}}*/

bool bic_intel_hex_method_ssa_cs_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INTEL_HEX_METHOD_VALUE_INTEGER(ssa_cs);
}/*}}}*/

bool bic_intel_hex_method_ssa_ip_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INTEL_HEX_METHOD_VALUE_INTEGER(ssa_ip);
}/*}}}*/

bool bic_intel_hex_method_ela_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INTEL_HEX_METHOD_VALUE_INTEGER(ela);
}/*}}}*/

bool bic_intel_hex_method_sla_eip_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INTEL_HEX_METHOD_VALUE_INTEGER(sla_eip);
}/*}}}*/

bool bic_intel_hex_method_next_item_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  intel_hex_s *ih_ptr = (intel_hex_s *)dst_location->v_data_ptr;

  // - read is not done yet -
  if (!ih_ptr->read_done)
  {
    do {
      char *line = nullptr;
      size_t size = 0;

      // - read line from text file -
      ssize_t length = getline(&line,&size,ih_ptr->file);

      if (length == -1)
      {
        free(line);

        exception_s::throw_exception(it,module.error_base + c_error_INTEL_HEX_UNEXPECTED_DATA_END,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }
      else
      {
        // - decrease line length if needed -
        if (length >= 2 && (line[length - 2] == '\r' || line[length - 2] == '\n'))
        {
          --length;
        }

        // - ERROR -
        if (length < 12)
        {
          free(line);

          exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_INTEL_HEX_INVALID_RECORD_LENGTH,operands[c_source_pos_idx],(location_s *)it.blank_location);
          new_exception->params.push(ih_ptr->line_cnt + 1);

          return false;
        }

        // - ERROR -
        if (*line != ':')
        {
          free(line);

          exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_INTEL_HEX_INVALID_RECORD_DATA,operands[c_source_pos_idx],(location_s *)it.blank_location);
          new_exception->params.push(ih_ptr->line_cnt + 1);

          return false;
        }

        const char *ptr = line + 1;
        int byte_count = intel_hex_s::read_byte(ptr);

        // - ERROR -
        if (byte_count < 0 ||
            (byte_count << 1) != (length - 12) ||
            (byte_count + 5) > 512)
        {
          free(line);

          exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_INTEL_HEX_INVALID_RECORD_LENGTH,operands[c_source_pos_idx],(location_s *)it.blank_location);
          new_exception->params.push(ih_ptr->line_cnt + 1);

          return false;
        }

        // - reuse line as byte buffer -
        unsigned char *buffer = (unsigned char *)line;

        // - ERROR -
        if (!intel_hex_s::read_line(buffer,line + 1,byte_count + 5))
        {
          free(line);

          exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_INTEL_HEX_INVALID_RECORD_DATA,operands[c_source_pos_idx],(location_s *)it.blank_location);
          new_exception->params.push(ih_ptr->line_cnt + 1);

          return false;
        }

        unsigned short address = (buffer[1] << 8) | buffer[2];
        unsigned short type  = buffer[3];

        switch (type)
        {
        case 0:
          {/*{{{*/
            pointer_array_s *array_ptr = it.get_new_array_ptr();
            BIC_CREATE_NEW_LOCATION(array_location,c_bi_class_array,array_ptr);

            BIC_CREATE_NEW_LOCATION(addr_location,c_bi_class_integer,(long long int)address);
            array_ptr->push(addr_location);

            string_s *string_ptr = it.get_new_string_ptr();
            string_ptr->set(byte_count,(char *)buffer + 4);

            BIC_CREATE_NEW_LOCATION(data_location,c_bi_class_string,string_ptr);
            array_ptr->push(data_location);

            BIC_SET_RESULT(array_location);
          }/*}}}*/
          break;
        case 1:
          {/*{{{*/

            // - ERROR -
            if (address != 0 || byte_count != 0)
            {
              free(line);

              exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_INTEL_HEX_INVALID_RECORD_DATA,operands[c_source_pos_idx],(location_s *)it.blank_location);
              new_exception->params.push(ih_ptr->line_cnt + 1);

              return false;
            }

            // - set read done flag -
            ih_ptr->read_done = true;

            BIC_SET_RESULT_BLANK();
          }/*}}}*/
          break;
        case 2:
        case 3:
        case 4:
        case 5:
          {/*{{{*/
            switch (type)
            {
            case 2:
              {/*{{{*/

                // - ERROR -
                if (address != 0 || byte_count != 2)
                {
                  free(line);

                  exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_INTEL_HEX_INVALID_RECORD_DATA,operands[c_source_pos_idx],(location_s *)it.blank_location);
                  new_exception->params.push(ih_ptr->line_cnt + 1);

                  return false;
                }

                ih_ptr->esa = (buffer[4] << 8) | buffer[5];
              }/*}}}*/
              break;
            case 3:
              {/*{{{*/

                // - ERROR -
                if (address != 0 || byte_count != 4)
                {
                  free(line);

                  exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_INTEL_HEX_INVALID_RECORD_DATA,operands[c_source_pos_idx],(location_s *)it.blank_location);
                  new_exception->params.push(ih_ptr->line_cnt + 1);

                  return false;
                }

                ih_ptr->ssa_cs = (buffer[4] << 8) | buffer[5];
                ih_ptr->ssa_ip = (buffer[6] << 8) | buffer[7];
              }/*}}}*/
              break;
            case 4:
              {/*{{{*/

                // - ERROR -
                if (address != 0 || byte_count != 2)
                {
                  free(line);

                  exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_INTEL_HEX_INVALID_RECORD_DATA,operands[c_source_pos_idx],(location_s *)it.blank_location);
                  new_exception->params.push(ih_ptr->line_cnt + 1);

                  return false;
                }

                ih_ptr->ela = (buffer[4] << 8) | buffer[5];
              }/*}}}*/
              break;
            case 5:
              {/*{{{*/

                // - ERROR -
                if (address != 0 || byte_count != 4)
                {
                  free(line);

                  exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_INTEL_HEX_INVALID_RECORD_DATA,operands[c_source_pos_idx],(location_s *)it.blank_location);
                  new_exception->params.push(ih_ptr->line_cnt + 1);

                  return false;
                }

                ih_ptr->sla_eip = (buffer[4] << 24) | (buffer[5] << 16) | (buffer[6] << 8) | buffer[7];
              }/*}}}*/
              break;
            }

            // - increase line counter -
            free(line);
            ++ih_ptr->line_cnt;

            // - if callback delegate is set -
            if (ih_ptr->callback_dlg != nullptr)
            {
              delegate_s *delegate_ptr = (delegate_s *)ih_ptr->callback_dlg->v_data_ptr;

              BIC_CREATE_NEW_LOCATION_REFS(type_location,c_bi_class_integer,(long long int)type,0);

              // - callback parameters -
              const unsigned param_cnt = 2;
              pointer param_data[2] = {type_location,dst_location};

              // - call delegate method -
              location_s *trg_location = nullptr;
              BIC_CALL_DELEGATE(it,delegate_ptr,param_data,param_cnt,trg_location,operands[c_source_pos_idx],
                return false;
              );
              it.release_location_ptr(trg_location);
            }

            continue;
          }/*}}}*/
          break;
        // - ERROR -
        default:
          free(line);

          exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_INTEL_HEX_INVALID_RECORD_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
          new_exception->params.push(ih_ptr->line_cnt + 1);

          return false;
        }

        // - increase line counter -
        free(line);
        ++ih_ptr->line_cnt;

        break;
      }
    } while(1);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_intel_hex_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("IntelHex"),"IntelHex");
  );

  return true;
}/*}}}*/

bool bic_intel_hex_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("IntelHex");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

