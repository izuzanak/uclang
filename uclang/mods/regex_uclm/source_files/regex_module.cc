
@begin
include "regex_module.h"
@end

// - REGEX indexes of built in classes -
unsigned c_bi_class_regex = c_idx_not_exist;

// - REGEX module -
EXPORT built_in_module_s module =
{/*{{{*/
  1,                      // Class count
  regex_classes,          // Classes

  0,                      // Error base index
  5,                      // Error count
  regex_error_strings,    // Error strings

  regex_initialize,       // Initialize function
  regex_print_exception,  // Print exceptions function
};/*}}}*/

// - REGEX classes -
built_in_class_s *regex_classes[] =
{/*{{{*/
  &regex_class,
};/*}}}*/

// - REGEX error strings -
const char *regex_error_strings[] =
{/*{{{*/
  "error_REGEX_COMPILE_ERROR",
  "error_REGEX_NOT_COMPILED",
  "error_REGEX_WRONG_MATCH_COUNT",
  "error_REGEX_WRONG_MATCH_OFFSET",
  "error_REGEX_STRING_SPLIT_EMPTY_MATCH",
};/*}}}*/

// - REGEX initialize -
bool regex_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize regex class identifier -
  c_bi_class_regex = class_base_idx++;

  return true;
}/*}}}*/

// - REGEX print exception -
bool regex_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_REGEX_COMPILE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot compile regular expression \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_REGEX_NOT_COMPILED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nRegular expression is not compiled\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_REGEX_WRONG_MATCH_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong match count %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_REGEX_WRONG_MATCH_OFFSET:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMatch offset %" HOST_LL_FORMAT "d, is greater than string size\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_REGEX_STRING_SPLIT_EMPTY_MATCH:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nEmpty match found while splitting string\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class REGEX -
built_in_class_s regex_class =
{/*{{{*/
  "Regex",
  c_modifier_public | c_modifier_final,
  9, regex_methods,
  0, regex_variables,
  bic_regex_consts,
  bic_regex_init,
  bic_regex_clear,
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

built_in_method_s regex_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_regex_operator_binary_equal
  },
  {
    "Regex#1",
    c_modifier_public | c_modifier_final,
    bic_regex_method_Regex_1
  },
  {
    "match#1",
    c_modifier_public | c_modifier_final,
    bic_regex_method_match_1
  },
  {
    "match#2",
    c_modifier_public | c_modifier_final,
    bic_regex_method_match_2
  },
  {
    "match_from#2",
    c_modifier_public | c_modifier_final,
    bic_regex_method_match_from_2
  },
  {
    "split#1",
    c_modifier_public | c_modifier_final,
    bic_regex_method_split_1
  },
  {
    "replace#2",
    c_modifier_public | c_modifier_final,
    bic_regex_method_replace_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_regex_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_regex_method_print_0
  },
};/*}}}*/

built_in_variable_s regex_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_regex_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_regex_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (regex_t *)nullptr;
}/*}}}*/

void bic_regex_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/

  // - retrieve regex pointer -
  regex_t *re = (regex_t *)location_ptr->v_data_ptr;

  // - if regex pointer is not null release it -
  if (re != nullptr)
  {
    regfree(re);
    cfree(re);
  }

}/*}}}*/

bool bic_regex_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_regex_method_Regex_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:c_bi_class_string
>
method Regex
; @end

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - allocate regex pointer -
  regex_t *re = (regex_t *)cmalloc(sizeof(regex_t));

  // - compile regular expression -
  if (regcomp(re,string_ptr->data,0) == 0)
  {
    dst_location->v_data_ptr = (regex_t *)re;
  }
  else
  {
    cfree(re);

    exception_s::throw_exception(it,module.error_base + c_error_REGEX_COMPILE_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  return true;
}/*}}}*/

bool bic_regex_method_match_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:c_bi_class_string
>
method match
; @end

  regex_t *re = (regex_t *)dst_location->v_data_ptr;

  // - ERROR -
  if (re == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_REGEX_NOT_COMPILED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create match target structure -
  regmatch_t match;

  // - execute regular expression -
  int res = regexec(re,string_ptr->data,1,&match,0);

  // - if match was found -
  if (res == 0)
  {
    pointer_array_s *array_ptr = it.get_new_array_ptr();

    // - resize result array -
    array_ptr->copy_resize(2);

    {
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,match.rm_so);
      array_ptr->push(new_location);
    }

    {
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,match.rm_eo);
      array_ptr->push(new_location);
    }

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
    BIC_SET_RESULT(new_location)
  }

  // - if match was not found -
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_regex_method_match_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:c_bi_class_string
match_count:retrieve_integer
>
method match
; @end

  regex_t *re = (regex_t *)dst_location->v_data_ptr;

  // - ERROR -
  if (re == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_REGEX_NOT_COMPILED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
#ifdef _MSC_VER
  if (match_count < 1 || match_count > 256)
#else
  if (match_count < 1)
#endif
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_REGEX_WRONG_MATCH_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(match_count);

    return false;
  }

  // - create match target structure -
  size_t nmatch = match_count;

#ifdef _MSC_VER
  regmatch_t pmatch[256];
#else
  regmatch_t pmatch[nmatch];
#endif

  // - execute regular expression -
  int res = regexec(re,string_ptr->data,nmatch,pmatch,0);

  // - if match was found -
  if (res == 0)
  {
    pointer_array_s *array_ptr = it.get_new_array_ptr();

    regmatch_t *rm_ptr = pmatch;
    regmatch_t *rm_ptr_end = rm_ptr + nmatch;
    do
    {
      pointer_array_s *sub_array_ptr = it.get_new_array_ptr();

      // - resize result sub array -
      sub_array_ptr->copy_resize(2);

      {
        BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,rm_ptr->rm_so);
        sub_array_ptr->push(new_location);
      }

      {
        BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,rm_ptr->rm_eo);
        sub_array_ptr->push(new_location);
      }

      // - push sub array to array -
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,sub_array_ptr);
      array_ptr->push(new_location);

    }
    while(++rm_ptr < rm_ptr_end && rm_ptr->rm_so != -1);

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
    BIC_SET_RESULT(new_location)
  }

  // - if match was not found -
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_regex_method_match_from_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:c_bi_class_string
offset:retrieve_integer
>
method match_from
; @end

  regex_t *re = (regex_t *)dst_location->v_data_ptr;

  // - ERROR -
  if (re == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_REGEX_NOT_COMPILED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (offset >= string_ptr->size - 1)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_REGEX_WRONG_MATCH_OFFSET,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(offset);

    return false;
  }

  // - create match target structure -
  regmatch_t match;

  // - execute regular expression -
  int res = regexec(re,string_ptr->data + offset,1,&match,0);

  // - if match was found -
  if (res == 0)
  {
    pointer_array_s *array_ptr = it.get_new_array_ptr();

    // - resize result array -
    array_ptr->copy_resize(2);

    {
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,offset + match.rm_so);
      array_ptr->push(new_location);
    }

    {
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,offset + match.rm_eo);
      array_ptr->push(new_location);
    }

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
    BIC_SET_RESULT(new_location)
  }

  // - if match was not found -
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_regex_method_split_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:c_bi_class_string
>
method split
; @end

  regex_t *re = (regex_t *)dst_location->v_data_ptr;

  // - ERROR -
  if (re == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_REGEX_NOT_COMPILED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - retrieve string pointers -
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create new array pointer -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  // - create new array location -
  BIC_CREATE_NEW_LOCATION(array_location,c_bi_class_array,array_ptr);

  // - create match target structure -
  regmatch_t match;

  // - split string to array -
  {
    unsigned idx = 0;
    do
    {
      unsigned old_idx = idx;

      // - execute regular expression -
      int res = regexec(re,string_ptr->data + idx,1,&match,0);

      // - if match was found -
      if (res == 0)
      {
        // - ERROR -
        if (match.rm_so == match.rm_eo)
        {
          it.release_location_ptr(array_location);

          exception_s::throw_exception(it,module.error_base + c_error_REGEX_STRING_SPLIT_EMPTY_MATCH,operands[c_source_pos_idx],(location_s *)it.blank_location);
          return false;
        }

        idx += match.rm_so;
      }

      // - if match was not found -
      else
      {
        idx = string_ptr->size - 1;
      }

      // - create new string pointer -
      string_s *new_string_ptr = it.get_new_string_ptr();
      new_string_ptr->set(idx - old_idx,string_ptr->data + old_idx);

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,new_string_ptr);

      // - insert string location to pointer array -
      array_ptr->push((pointer)new_location);

      if (idx >= string_ptr->size - 1)
      {
        break;
      }

      // - jump over matched string -
      idx += match.rm_eo - match.rm_so;
    }
    while(true);
  }

  BIC_SET_RESULT(array_location);

  return true;
}/*}}}*/

bool bic_regex_method_replace_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:c_bi_class_string
new_value:c_bi_class_string
>
method replace
; @end

  regex_t *re = (regex_t *)dst_location->v_data_ptr;

  // - ERROR -
  if (re == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_REGEX_NOT_COMPILED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - retrieve string pointers -
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;
  string_s *newstr_ptr = (string_s *)src_1_location->v_data_ptr;

  // - create target buffer -
  bc_array_s buffer;
  buffer.init();

  // - replace regex matches by new string -
  {
    regmatch_t regmatch;

    unsigned pos = 0;
    do {
      unsigned old_pos = pos;

      // - search for substring -
      if (regexec(re,string_ptr->data + pos,1,&regmatch,0) == 0)
      {
        pos += regmatch.rm_so;
      }
      else
      {
        pos = string_ptr->size - 1;
      }

      // - append part of original string to result -
      buffer.append(pos - old_pos,string_ptr->data + old_pos);

      if (pos >= string_ptr->size - 1)
      {
        break;
      }

      // - append new string to result -
      buffer.append(newstr_ptr->size - 1,newstr_ptr->data);

      // - jump over substring -
      pos += regmatch.rm_eo - regmatch.rm_so;

    } while(true);
  }

  // - insert terminating character to buffer -
  buffer.push('\0');

  // - create result string -
  string_s *result_ptr = it.get_new_string_ptr();
  result_ptr->data = buffer.data;
  result_ptr->size = buffer.used;

  BIC_SET_RESULT_STRING(result_ptr);

  return true;
}/*}}}*/

bool bic_regex_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Regex"),"Regex")
  );

  return true;
}/*}}}*/

bool bic_regex_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Regex");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

