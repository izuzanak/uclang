
@begin
include "base_module.h"
@end

// - BASE module -
built_in_module_s module =
{/*{{{*/
  13,                   // Class count
  base_classes,         // Classes

  0,                    // Error base index
  54,                   // Error count
  base_error_strings,   // Error strings

  base_initialize,      // Initialize function
  base_print_exception, // Print exceptions function
};/*}}}*/

// - BASE classes -
built_in_class_s *base_classes[] =
{/*{{{*/
  &blank_class,
  &char_class,
  &integer_class,
  &float_class,
  &string_class,
  &array_class,
  &error_class,
  &exception_class,
  &type_class,
  &mutex_class,
  &thread_class,
  &delegate_class,
  &buffer_class,
};/*}}}*/

// - BASE error strings -
const char *base_error_strings[] =
{/*{{{*/
  "error_OK",
  "error_UNKNOWN",

  "error_INVALID",
  "error_DEADLOCK",
  "error_BUSY",
  "error_PERMISSION",
  "error_AGAIN",
  "error_SEARCH",

  // - global errors -
  "error_USER_EXCEPTION",
  "error_TODO_EXCEPTION",

  // - run_expression -
  "error_CLASS_DOES_NOT_CONTAIN_CONSTRUCTOR",

  "error_CLASS_DOES_NOT_CONTAIN_METHOD",
  "error_CLASS_DOES_NOT_CONTAIN_VARIABLE",

  "error_CANNOT_ACCESS_PRIVATE_METHOD",
  "error_CANNOT_ACCESS_PRIVATE_VARIABLE",

  "error_METHOD_CANNOT_RETURN_VALUE",
  "error_CANNOT_TEST_TYPE_VALUE",

  "error_CANNOT_CONVERT_TYPE_TO_INTEGER",
  "error_CANNOT_USE_NEGATIVE_NUMBER",

  "error_SLICE_NOT_INTEGER_ARGUMENTS",
  "error_SLICE_START_LESS_THAN_ZERO",
  "error_SLICE_STOP_LESS_THAN_ZERO",
  "error_SLICE_STEP_EQUAL_TO_ZERO",

  "error_OBJECT_OF_CLASS_IS_NOT_ITERABLE",
  "error_UNEXPECTED_END_OF_ITERABLE",

  // - built_in -
  "error_BUILT_IN_NOT_IMPLEMENTED_METHOD",

  "error_METHOD_NOT_DEFINED_WITH_PARAMETERS",
  "error_WRONG_METHOD_PARAMETER_VALUE",

  "error_DIVISION_BY_ZERO",
  "error_NEGATIVE_SHIFT_COUNT",

  "error_METHOD_NOT_RETURN_INTEGER",
  "error_METHOD_NOT_RETURN_STRING",
  "error_METHOD_NOT_RETURN_INDEX",

  "error_INTEGER_BASE_OUT_OF_RANGE",
  "error_INTEGER_CONVERT_INVALID_STRING",

  "error_FLOAT_CONVERT_INVALID_STRING",

  "error_STRING_FORMAT_NOT_ENOUGH_ARGUMENTS",
  "error_STRING_FORMAT_WRONG_ARGUMENT_TYPE",
  "error_STRING_FORMAT_ARGUMENT_FORMAT_ERROR",
  "error_STRING_FORMAT_WRONG_FORMAT_SPECIFIER",
  "error_STRING_FORMAT_NOT_ALL_ARGUMENTS_CONVERTED",

  "error_STRING_INDEX_EXCEEDS_RANGE",
  "error_STRING_WRONG_RANGE_INDEXES",
  "error_STRING_CONVERT_FROM_INTEGER",
  "error_STRING_CONVERT_FROM_FLOAT",

  "error_ARRAY_INDEX_EXCEEDS_RANGE",
  "error_ARRAY_CANNOT_RESIZE_TO_SMALLER_SIZE",
  "error_ARRAY_NO_ELEMENTS",
  "error_ARRAY_ELEMENT_ASSIGN_NOT_SAME_LENGTH",

  "error_DELEGATE_NEGATIVE_PARAMETER_COUNT",
  "error_DELEGATE_OBJECT_DOES_NOT_CONTAIN_METHOD",
  "error_DELEGATE_CALL_WRONG_PARAMETER_COUNT",
  "error_DELEGATE_PAPPLY_WRONG_PARAMETER_COUNT",
  "error_DELEGATE_WRONG_RETURN_VALUE_TYPE",
};/*}}}*/

// - BASE initialize -
bool base_initialize(script_parser_s &sp)
{/*{{{*/
  return true;
}/*}}}*/

// - BASE print exception -
bool base_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type)
  {
  case c_error_USER_EXCEPTION:
  {
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fputc('\n',stderr);

    location_s *location_ptr = interpreter_thread_s::get_location_value(exception.obj_location);
    if (location_ptr->v_type == c_bi_class_string)
    {
      fprintf(stderr, "%s\n", ((string_s *)location_ptr->v_data_ptr)->data);
    }
    else
    {
      fprintf(stderr, "Value object of exception has no %s class\n",it.class_symbol_names[it.class_records[c_bi_class_string].name_idx].data);
    }
    fprintf(stderr," ---------------------------------------- \n");
  }
  break;
  case c_error_TODO_EXCEPTION:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: TODO ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTodo error exception, in source \"%s\", on line: %" HOST_LL_FORMAT "d\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data,exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CLASS_DOES_NOT_CONTAIN_CONSTRUCTOR:
  {
    class_record_s &class_record = it.class_records[exception.params[0]];

    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nClass ");
    print_class_sequence(it.class_symbol_names,it.class_records,class_stack,class_record.parent_record);
    fprintf(stderr,"%s does not have constructor %s\n",it.class_symbol_names[class_record.name_idx].data,it.method_symbol_names[exception.params[1]].data);
    fprintf(stderr," ---------------------------------------- \n");
  }
  break;
  case c_error_CLASS_DOES_NOT_CONTAIN_METHOD:
  {
    class_record_s &class_record = it.class_records[exception.params[0]];

    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nClass ");
    print_class_sequence(it.class_symbol_names,it.class_records,class_stack,class_record.parent_record);
    fprintf(stderr,"%s does not contain method %s\n",it.class_symbol_names[class_record.name_idx].data,it.method_symbol_names[exception.params[1]].data);
    fprintf(stderr," ---------------------------------------- \n");
  }
  break;
  case c_error_CLASS_DOES_NOT_CONTAIN_VARIABLE:
  {
    class_record_s &class_record = it.class_records[exception.params[0]];

    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nClass ");
    print_class_sequence(it.class_symbol_names,it.class_records,class_stack,class_record.parent_record);
    fprintf(stderr,"%s does not contain variable %s\n",it.class_symbol_names[class_record.name_idx].data,it.variable_symbol_names[exception.params[1]].data);
    fprintf(stderr," ---------------------------------------- \n");
  }
  break;
  case c_error_CANNOT_ACCESS_PRIVATE_METHOD:
  {
    method_record_s &method_record = it.method_records[exception.params[0]];

    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot access private method ");
    print_class_sequence(it.class_symbol_names,it.class_records,class_stack,method_record.parent_record);
    fprintf(stderr,"%s\n",it.method_symbol_names[method_record.name_idx].data);
    fprintf(stderr," ---------------------------------------- \n");
  }
  break;
  case c_error_CANNOT_ACCESS_PRIVATE_VARIABLE:
  {
    variable_record_s &variable_record = it.variable_records[exception.params[0]];

    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot access private variable ");
    print_class_sequence(it.class_symbol_names,it.class_records,class_stack,variable_record.parent_record);
    fprintf(stderr,"%s\n",it.variable_symbol_names[variable_record.name_idx].data);
    fprintf(stderr," ---------------------------------------- \n");
  }
  break;
  case c_error_METHOD_CANNOT_RETURN_VALUE:
  {
    method_record_s &method_record = it.method_records[exception.params[0]];

    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMethod ");
    print_class_sequence(it.class_symbol_names,it.class_records,class_stack,method_record.parent_record);
    fprintf(stderr,"%s cannot return value\n",it.method_symbol_names[method_record.name_idx].data);
    fprintf(stderr," ---------------------------------------- \n");
  }
  break;
  case c_error_CANNOT_TEST_TYPE_VALUE:
  {
    class_record_s &class_record = it.class_records[exception.params[0]];

    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot test value of type ");
    print_class_sequence(it.class_symbol_names,it.class_records,class_stack,class_record.parent_record);
    fprintf(stderr,"%s\n",it.class_symbol_names[class_record.name_idx].data);
    fprintf(stderr," ---------------------------------------- \n");
  }
  break;
  case c_error_CANNOT_CONVERT_TYPE_TO_INTEGER:
  {
    class_record_s &class_record = it.class_records[exception.params[0]];

    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot convert from ");
    print_class_sequence(it.class_symbol_names,it.class_records,class_stack,class_record.parent_record);
    fprintf(stderr,"%s to %s\n",it.class_symbol_names[class_record.name_idx].data,it.class_symbol_names[it.class_records[c_bi_class_integer].name_idx].data);
    fprintf(stderr," ---------------------------------------- \n");
  }
  break;
  case c_error_CANNOT_USE_NEGATIVE_NUMBER:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot use negative number %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SLICE_NOT_INTEGER_ARGUMENTS:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nAll slice arguments must be integers\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SLICE_START_LESS_THAN_ZERO:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nResult slice start value must be greater or equal to zero\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SLICE_STOP_LESS_THAN_ZERO:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nResult slice stop value must be greater or equal to zero\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SLICE_STEP_EQUAL_TO_ZERO:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSlice step value cannot be zero\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_OBJECT_OF_CLASS_IS_NOT_ITERABLE:
  {
    class_record_s &class_record = it.class_records[exception.params[0]];

    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nObject of class ");
    print_class_sequence(it.class_symbol_names,it.class_records,class_stack,class_record.parent_record);
    fprintf(stderr,"%s is not iterable\n",it.class_symbol_names[class_record.name_idx].data);
    fprintf(stderr," ---------------------------------------- \n");
  }
  break;
  case c_error_UNEXPECTED_END_OF_ITERABLE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUnexpected end of iterable\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_BUILT_IN_NOT_IMPLEMENTED_METHOD:
  {
    method_record_s &method_record = it.method_records[exception.params[0]];

    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR TODO: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMethod ");
    print_class_sequence(it.class_symbol_names,it.class_records,class_stack,method_record.parent_record);
    fprintf(stderr,"%s has not been implemented yet\n",it.method_symbol_names[method_record.name_idx].data);
    fprintf(stderr," ---------------------------------------- \n");
  }
  break;
  case c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS:
  {
    method_record_s &method_record = it.method_records[exception.params[0]];

    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMethod ");
    print_class_sequence(it.class_symbol_names,it.class_records,class_stack,method_record.parent_record);
    fprintf(stderr,"%s is not defined for parameter/s: (%s",it.method_symbol_names[method_record.name_idx].data,
            it.class_symbol_names[it.class_records[exception.params[2]].name_idx].data);

    long long int *p_ptr = exception.params.data + 3;
    long long int *p_ptr_end = exception.params.data + 2 + exception.params[1];
    if (p_ptr < p_ptr_end)
    {
      do
      {
        fprintf(stderr,",%s",it.class_symbol_names[it.class_records[*p_ptr].name_idx].data);
      }
      while(++p_ptr < p_ptr_end);
    }

    fprintf(stderr,")\n");
    fprintf(stderr," ---------------------------------------- \n");
  }
  break;
  case c_error_WRONG_METHOD_PARAMETER_VALUE:
  {
    method_record_s &method_record = it.method_records[exception.params[0]];

    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nParameter of method ");
    print_class_sequence(it.class_symbol_names,it.class_records,class_stack,method_record.parent_record);
    fprintf(stderr,"%s at position %" HOST_LL_FORMAT "d. of type %s contains wrong data\n",it.method_symbol_names[method_record.name_idx].data,
            exception.params[1],it.class_symbol_names[it.class_records[exception.params[2]].name_idx].data);
    fprintf(stderr," ---------------------------------------- \n");
  }
  break;
  case c_error_DIVISION_BY_ZERO:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nDivision by zero\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_NEGATIVE_SHIFT_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nNegative shift count %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_METHOD_NOT_RETURN_INTEGER:
  {
    method_record_s &method_record = it.method_records[exception.params[0]];

    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMethod ");
    print_class_sequence(it.class_symbol_names,it.class_records,class_stack,method_record.parent_record);
    fprintf(stderr,"%s do not return integer\n",it.method_symbol_names[method_record.name_idx].data);
    fprintf(stderr," ---------------------------------------- \n");
  }
  break;
  case c_error_METHOD_NOT_RETURN_STRING:
  {
    method_record_s &method_record = it.method_records[exception.params[0]];

    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMethod ");
    print_class_sequence(it.class_symbol_names,it.class_records,class_stack,method_record.parent_record);
    fprintf(stderr,"%s do not return string\n",it.method_symbol_names[method_record.name_idx].data);
    fprintf(stderr," ---------------------------------------- \n");
  }
  break;
  case c_error_METHOD_NOT_RETURN_INDEX:
  {
    method_record_s &method_record = it.method_records[exception.params[0]];

    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nMethod ");
    print_class_sequence(it.class_symbol_names,it.class_records,class_stack,method_record.parent_record);
    fprintf(stderr,"%s do not return index value\n",it.method_symbol_names[method_record.name_idx].data);
    fprintf(stderr," ---------------------------------------- \n");
  }
  break;
  case c_error_INTEGER_BASE_OUT_OF_RANGE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInteger number base %" HOST_LL_FORMAT "d, is out of range <2, 36>\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_INTEGER_CONVERT_INVALID_STRING:
  {
    string_s *string_ptr = (string_s *)((location_s *)exception.obj_location)->v_data_ptr;

    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInteger conversion, invalid string literal \"%s\"",string_ptr->data);

    if (exception.params[0] != 0)
    {
      fprintf(stderr," for base %" HOST_LL_FORMAT "d\n",exception.params[0]);
    }
    else
    {
      fprintf(stderr,"\n");
    }

    fprintf(stderr," ---------------------------------------- \n");
  }
  break;
  case c_error_FLOAT_CONVERT_INVALID_STRING:
  {
    string_s *string_ptr = (string_s *)((location_s *)exception.obj_location)->v_data_ptr;

    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFloat conversion, invalid string literal \"%s\"\n",string_ptr->data);
    fprintf(stderr," ---------------------------------------- \n");
  }
  break;
  case c_error_STRING_FORMAT_NOT_ENOUGH_ARGUMENTS:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nNot enough arguments for string formatting\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_STRING_FORMAT_WRONG_ARGUMENT_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong argument type for string formatting, at position %" HOST_LL_FORMAT "d expected %s received %s\n",
            exception.params[0],it.class_symbol_names[it.class_records[exception.params[1]].name_idx].data,it.class_symbol_names[it.class_records[exception.params[2]].name_idx].data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_STRING_FORMAT_ARGUMENT_FORMAT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while formatting string argument at position %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_STRING_FORMAT_WRONG_FORMAT_SPECIFIER:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong parameter format specifier in format string\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_STRING_FORMAT_NOT_ALL_ARGUMENTS_CONVERTED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nNot all arguments converted during string formatting\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_STRING_INDEX_EXCEEDS_RANGE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nIndex %" HOST_LL_FORMAT "d exceeds string range\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_STRING_WRONG_RANGE_INDEXES:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong range indexes %" HOST_LL_FORMAT "d, %" HOST_LL_FORMAT "d for string\n",exception.params[0],exception.params[1]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_STRING_CONVERT_FROM_INTEGER:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while converting integer to string\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_STRING_CONVERT_FROM_FLOAT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while converting float to string\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_ARRAY_INDEX_EXCEEDS_RANGE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nIndex %" HOST_LL_FORMAT "d exceeds array range\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_ARRAY_CANNOT_RESIZE_TO_SMALLER_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nResize to size %" HOST_LL_FORMAT "d of array of actual size %" HOST_LL_FORMAT "d\n",exception.params[0],exception.params[1]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_ARRAY_NO_ELEMENTS:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nArray does not contain any elements\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_ARRAY_ELEMENT_ASSIGN_NOT_SAME_LENGTH:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nDifferent count of elements of array and source container.\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_DELEGATE_NEGATIVE_PARAMETER_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nNegative count of method parameters %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_DELEGATE_OBJECT_DOES_NOT_CONTAIN_METHOD:
  {
    class_record_s &class_record = it.class_records[exception.params[0]];

    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nDelegate: object of class ");
    print_class_sequence(it.class_symbol_names,it.class_records,class_stack,class_record.parent_record);
    fprintf(stderr,"%s does not contain requested method\n",it.class_symbol_names[class_record.name_idx].data);
    fprintf(stderr," ---------------------------------------- \n");
  }
  break;
  case c_error_DELEGATE_CALL_WRONG_PARAMETER_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nDelegate: wrong count of parameters %" HOST_LL_FORMAT "d, expected %" HOST_LL_FORMAT "d\n",exception.params[0],exception.params[1]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_DELEGATE_PAPPLY_WRONG_PARAMETER_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nDelegate: wrong count of partial application parameters %" HOST_LL_FORMAT "d, expected 1 - %" HOST_LL_FORMAT "d\n",exception.params[0],exception.params[1]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_DELEGATE_WRONG_RETURN_VALUE_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong type of value returned by delegate\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class BLANK -
built_in_class_s blank_class =
{/*{{{*/
  "Blank",
  c_modifier_public | c_modifier_final,
  7, blank_methods,
  0, blank_variables,
  bic_blank_consts,
  bic_blank_init,
  bic_blank_clear,
  bic_blank_compare,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  bic_blank_pack,
  bic_blank_unpack,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s blank_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_blank_operator_binary_equal
  },
  {
    "operator_binary_double_equal#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_blank_operator_binary_double_equal
  },
  {
    "operator_binary_exclamation_equal#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_blank_operator_binary_exclamation_equal
  },
  {
    "Blank#0",
    c_modifier_public | c_modifier_final,
    bic_blank_method_Blank_0
  },
  {
    "compare#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_blank_method_compare_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_blank_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_blank_method_print_0
  },
};/*}}}*/

built_in_variable_s blank_variables[] =
{/*{{{*/
};/*}}}*/

void bic_blank_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_blank_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

void bic_blank_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

int bic_blank_compare(location_s *first_loc,location_s *second_loc)
{/*{{{*/
  return 0;
}/*}}}*/

bool bic_blank_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack)
{/*{{{*/
  return true;
}/*}}}*/

bool bic_blank_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos)
{/*{{{*/
  return true;
}/*}}}*/

bool bic_blank_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_blank_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result = src_0_location->v_type == c_bi_class_blank;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_blank_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result = src_0_location->v_type != c_bi_class_blank;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_blank_method_Blank_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  return true;
}/*}}}*/

bool bic_blank_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  if (src_0_location->v_type == c_bi_class_blank)
  {
    result = 0;
  }
  else
  {
    result = c_bi_class_blank < src_0_location->v_type ? -1 : 1;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_blank_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("<blank>"),"<blank>")
  );

  return true;
}/*}}}*/

bool bic_blank_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("<blank>");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class CHAR -
built_in_class_s char_class =
{/*{{{*/
  "Char",
  c_modifier_public | c_modifier_final,
  42, char_methods,
  0, char_variables,
  bic_char_consts,
  bic_char_init,
  bic_char_clear,
  bic_char_compare,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  bic_char_pack,
  bic_char_unpack,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s char_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_char_operator_binary_equal
  },
  {
    "operator_binary_plus_equal#1",
    c_modifier_public | c_modifier_final,
    bic_char_operator_binary_plus_equal
  },
  {
    "operator_binary_minus_equal#1",
    c_modifier_public | c_modifier_final,
    bic_char_operator_binary_minus_equal
  },
  {
    "operator_binary_asterisk_equal#1",
    c_modifier_public | c_modifier_final,
    bic_char_operator_binary_asterisk_equal
  },
  {
    "operator_binary_slash_equal#1",
    c_modifier_public | c_modifier_final,
    bic_char_operator_binary_slash_equal
  },
  {
    "operator_binary_percent_equal#1",
    c_modifier_public | c_modifier_final,
    bic_char_operator_binary_percent_equal
  },
  {
    "operator_binary_double_ls_br_equal#1",
    c_modifier_public | c_modifier_final,
    bic_char_operator_binary_double_ls_br_equal
  },
  {
    "operator_binary_double_rs_br_equal#1",
    c_modifier_public | c_modifier_final,
    bic_char_operator_binary_double_rs_br_equal
  },
  {
    "operator_binary_ampersand_equal#1",
    c_modifier_public | c_modifier_final,
    bic_char_operator_binary_ampersand_equal
  },
  {
    "operator_binary_pipe_equal#1",
    c_modifier_public | c_modifier_final,
    bic_char_operator_binary_pipe_equal
  },
  {
    "operator_binary_circumflex_equal#1",
    c_modifier_public | c_modifier_final,
    bic_char_operator_binary_circumflex_equal
  },
  {
    "operator_binary_double_ampersand#1",
    c_modifier_public | c_modifier_final,
    bic_char_operator_binary_double_ampersand
  },
  {
    "operator_binary_double_pipe#1",
    c_modifier_public | c_modifier_final,
    bic_char_operator_binary_double_pipe
  },
  {
    "operator_binary_ampersand#1",
    c_modifier_public | c_modifier_final,
    bic_char_operator_binary_ampersand
  },
  {
    "operator_binary_pipe#1",
    c_modifier_public | c_modifier_final,
    bic_char_operator_binary_pipe
  },
  {
    "operator_binary_circumflex#1",
    c_modifier_public | c_modifier_final,
    bic_char_operator_binary_circumflex
  },
  {
    "operator_binary_double_equal#1",
    c_modifier_public | c_modifier_final,
    bic_char_operator_binary_double_equal
  },
  {
    "operator_binary_exclamation_equal#1",
    c_modifier_public | c_modifier_final,
    bic_char_operator_binary_exclamation_equal
  },
  {
    "operator_binary_rs_br#1",
    c_modifier_public | c_modifier_final,
    bic_char_operator_binary_rs_br
  },
  {
    "operator_binary_ls_br#1",
    c_modifier_public | c_modifier_final,
    bic_char_operator_binary_ls_br
  },
  {
    "operator_binary_rs_br_equal#1",
    c_modifier_public | c_modifier_final,
    bic_char_operator_binary_rs_br_equal
  },
  {
    "operator_binary_ls_br_equal#1",
    c_modifier_public | c_modifier_final,
    bic_char_operator_binary_ls_br_equal
  },
  {
    "operator_binary_double_rs_br#1",
    c_modifier_public | c_modifier_final,
    bic_char_operator_binary_double_rs_br
  },
  {
    "operator_binary_double_ls_br#1",
    c_modifier_public | c_modifier_final,
    bic_char_operator_binary_double_ls_br
  },
  {
    "operator_binary_plus#1",
    c_modifier_public | c_modifier_final,
    bic_char_operator_binary_plus
  },
  {
    "operator_binary_minus#1",
    c_modifier_public | c_modifier_final,
    bic_char_operator_binary_minus
  },
  {
    "operator_binary_asterisk#1",
    c_modifier_public | c_modifier_final,
    bic_char_operator_binary_asterisk
  },
  {
    "operator_binary_slash#1",
    c_modifier_public | c_modifier_final,
    bic_char_operator_binary_slash
  },
  {
    "operator_binary_percent#1",
    c_modifier_public | c_modifier_final,
    bic_char_operator_binary_percent
  },
  {
    "operator_unary_post_double_plus#0",
    c_modifier_public | c_modifier_final,
    bic_char_operator_unary_post_double_plus
  },
  {
    "operator_unary_post_double_minus#0",
    c_modifier_public | c_modifier_final,
    bic_char_operator_unary_post_double_minus
  },
  {
    "operator_unary_pre_double_plus#0",
    c_modifier_public | c_modifier_final,
    bic_char_operator_unary_pre_double_plus
  },
  {
    "operator_unary_pre_double_minus#0",
    c_modifier_public | c_modifier_final,
    bic_char_operator_unary_pre_double_minus
  },
  {
    "operator_unary_pre_plus#0",
    c_modifier_public | c_modifier_final,
    bic_char_operator_unary_pre_plus
  },
  {
    "operator_unary_pre_minus#0",
    c_modifier_public | c_modifier_final,
    bic_char_operator_unary_pre_minus
  },
  {
    "operator_unary_pre_exclamation#0",
    c_modifier_public | c_modifier_final,
    bic_char_operator_unary_pre_exclamation
  },
  {
    "operator_unary_pre_tilde#0",
    c_modifier_public | c_modifier_final,
    bic_char_operator_unary_pre_tilde
  },
  {
    "Char#0",
    c_modifier_public | c_modifier_final,
    bic_char_method_Char_0
  },
  {
    "Char#1",
    c_modifier_public | c_modifier_final,
    bic_char_method_Char_1
  },
  {
    "compare#1",
    c_modifier_public | c_modifier_final,
    bic_char_method_compare_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_char_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_char_method_print_0
  },
};/*}}}*/

built_in_variable_s char_variables[] =
{/*{{{*/
};/*}}}*/

void bic_char_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_char_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (char)'\0';
}/*}}}*/

void bic_char_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

int bic_char_compare(location_s *first_loc,location_s *second_loc)
{/*{{{*/
  char first = (char)first_loc->v_data_ptr;
  char second = (char)second_loc->v_data_ptr;

  return first < second ? -1 : (first > second ? 1 : 0);
}/*}}}*/

bool bic_char_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack)
{/*{{{*/
  char value = (char)location_ptr->v_data_ptr;
  stream.append(sizeof(char),&value);

  return true;
}/*}}}*/

bool bic_char_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos)
{/*{{{*/
  if (stream.used < sizeof(char))
  {
    return false;
  }

  char value;
  stream.from_end(sizeof(char),&value,order_bytes);

  location_ptr->v_data_ptr = (char)value;

  return true;
}/*}}}*/

bool bic_char_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

#define BIC_CHAR_BINARY_EQUAL_OPS_CHAR_INTEGER_FLOAT(OPERATOR,NAME) \
  {/*{{{*/\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
    location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
    char result = (char)dst_location->v_data_ptr;\
\
    switch (src_0_location->v_type) {\
    case c_bi_class_char:\
      result OPERATOR ## = (char)src_0_location->v_data_ptr;\
      break;\
    case c_bi_class_integer:\
      result OPERATOR ## = (long long int)src_0_location->v_data_ptr;\
      break;\
    case c_bi_class_float:\
      result  = (char)(result OPERATOR (double)src_0_location->v_data_ptr);\
      break;\
\
      /* - ERROR - */\
    default:\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
\
      return false;\
    }\
\
    BIC_SIMPLE_SET_DST_AND_RES(c_bi_class_char,result);\
  }/*}}}*/

#define BIC_CHAR_BINARY_EQUAL_OPS_CHAR_INTEGER(OPERATOR,NAME) \
  {/*{{{*/\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
    location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
    char result = (char)dst_location->v_data_ptr;\
\
    switch (src_0_location->v_type) {\
    case c_bi_class_char:\
      result OPERATOR ## = (char)src_0_location->v_data_ptr;\
      break;\
    case c_bi_class_integer:\
      result OPERATOR ## = (long long int)src_0_location->v_data_ptr;\
      break;\
\
      /* - ERROR - */\
    default:\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
\
      return false;\
    }\
\
    BIC_SIMPLE_SET_DST_AND_RES(c_bi_class_char,result);\
  }/*}}}*/

#define BIC_CHAR_BINARY_SHIFT_EQUAL_OPS_CHAR_INTEGER(OPERATOR,NAME) \
  {/*{{{*/\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
    location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
    char result = (char)dst_location->v_data_ptr;\
\
    switch (src_0_location->v_type) {\
    case c_bi_class_char:\
    {\
      char shift_count = (char)src_0_location->v_data_ptr;\
      if (shift_count < 0)\
      {\
        exception_s *new_exception = exception_s::throw_exception(it,c_error_NEGATIVE_SHIFT_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);\
        new_exception->params.push((long long int)shift_count);\
\
        return false;\
      }\
\
      result OPERATOR ## = shift_count;\
    }\
    break;\
    case c_bi_class_integer:\
    {\
      long long int shift_count = (long long int)src_0_location->v_data_ptr;\
      if (shift_count < 0)\
      {\
        exception_s *new_exception = exception_s::throw_exception(it,c_error_NEGATIVE_SHIFT_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);\
        new_exception->params.push(shift_count);\
\
        return false;\
      }\
\
      result OPERATOR ## = shift_count;\
    }\
    break;\
\
    /* - ERROR - */\
    default:\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
\
      return false;\
    }\
\
    BIC_SIMPLE_SET_DST_AND_RES(c_bi_class_char,result);\
  }/*}}}*/

#define BIC_CHAR_BINARY_OPS_CHAR_INTEGER_FLOAT_RESULT_INTEGER(OPERATOR,NAME) \
  {/*{{{*/\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
    location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
    long long int result;\
\
    switch (src_0_location->v_type) {\
    case c_bi_class_char:\
      result = (char)dst_location->v_data_ptr OPERATOR (char)src_0_location->v_data_ptr;\
      break;\
    case c_bi_class_integer:\
      result = (char)dst_location->v_data_ptr OPERATOR (long long int)src_0_location->v_data_ptr;\
      break;\
    case c_bi_class_float:\
      result = (char)dst_location->v_data_ptr OPERATOR (double)src_0_location->v_data_ptr;\
      break;\
\
      /* - ERROR - */\
    default:\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
\
      return false;\
    }\
\
    BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
  }/*}}}*/

#define BIC_CHAR_BINARY_OPS_CHAR_INTEGER_RESULT_INTEGER(OPERATOR,NAME) \
  {/*{{{*/\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
    location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
    long long int result;\
\
    switch (src_0_location->v_type) {\
    case c_bi_class_char:\
      result = (char)dst_location->v_data_ptr OPERATOR (char)src_0_location->v_data_ptr;\
      break;\
    case c_bi_class_integer:\
      result = (char)dst_location->v_data_ptr OPERATOR (long long int)src_0_location->v_data_ptr;\
      break;\
\
      /* - ERROR - */\
    default:\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
\
      return false;\
    }\
\
    BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
  }/*}}}*/

#define BIC_CHAR_BINARY_SHIFT_OPS_CHAR_INTEGER_RESULT_INTEGER(OPERATOR,NAME) \
  {/*{{{*/\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
    location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
    long long int result;\
\
    switch (src_0_location->v_type) {\
    case c_bi_class_char:\
    {\
      char shift_count = (char)src_0_location->v_data_ptr;\
      if (shift_count < 0)\
      {\
        exception_s *new_exception = exception_s::throw_exception(it,c_error_NEGATIVE_SHIFT_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);\
        new_exception->params.push((long long int)shift_count);\
\
        return false;\
      }\
\
      result = (char)dst_location->v_data_ptr OPERATOR shift_count;\
    }\
    break;\
    case c_bi_class_integer:\
    {\
      long long int shift_count = (long long int)src_0_location->v_data_ptr;\
      if (shift_count < 0)\
      {\
        exception_s *new_exception = exception_s::throw_exception(it,c_error_NEGATIVE_SHIFT_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);\
        new_exception->params.push(shift_count);\
\
        return false;\
      }\
\
      result = (char)dst_location->v_data_ptr OPERATOR shift_count;\
    }\
    break;\
\
    /* - ERROR - */\
    default:\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
\
      return false;\
    }\
\
    BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
  }/*}}}*/

#define BIC_CHAR_BINARY_OPS_CHAR_INTEGER_FLOAT(OPERATOR,NAME) \
  {/*{{{*/\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
    location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
    unsigned v_type;\
    v_data_type v_data_ptr;\
\
    switch (src_0_location->v_type) {\
    case c_bi_class_char:\
      v_type = c_bi_class_char;\
      v_data_ptr = (char)((char)dst_location->v_data_ptr OPERATOR (char)src_0_location->v_data_ptr);\
      break;\
    case c_bi_class_integer:\
      v_type = c_bi_class_integer;\
      v_data_ptr = (long long int)((char)dst_location->v_data_ptr OPERATOR (long long int)src_0_location->v_data_ptr);\
      break;\
    case c_bi_class_float:\
      v_type = c_bi_class_float;\
      v_data_ptr = (double)((char)dst_location->v_data_ptr OPERATOR (double)src_0_location->v_data_ptr);\
    break;\
\
    /* - ERROR - */\
    default:\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
\
      return false;\
    }\
\
    BIC_SIMPLE_SET_RES(v_type,v_data_ptr);\
  }/*}}}*/

#define BIC_CHAR_POST_UNARY(OPERATOR) \
  {/*{{{*/\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
    char result = ((char)dst_location->v_data_ptr) OPERATOR;\
\
    BIC_SIMPLE_SET_RES_SWAP(c_bi_class_char,result);\
  }/*}}}*/

#define BIC_CHAR_PRE_UNARY(OPERATOR) \
  {/*{{{*/\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
    char result = ((char)dst_location->v_data_ptr) OPERATOR;\
\
    BIC_SIMPLE_SET_DST_AND_RES(c_bi_class_char,result);\
  }/*}}}*/

#define BIC_CHAR_PRE_UNARY_TMP_RESULT(OPERATOR) \
  {/*{{{*/\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
    char result = OPERATOR (char)dst_location->v_data_ptr;\
\
    BIC_SIMPLE_SET_RES(c_bi_class_char,result);\
  }/*}}}*/

#define BIC_CHAR_COMPARE_WITH_TYPE_BOOL() \
  {/*{{{*/\
    switch (src_0_location->v_type) {\
    case c_bi_class_char:\
      result = (char)dst_location->v_data_ptr == (char)src_0_location->v_data_ptr;\
      break;\
    case c_bi_class_integer:\
      result = (char)dst_location->v_data_ptr == (long long int)src_0_location->v_data_ptr;\
      break;\
    case c_bi_class_float:\
      result = (char)dst_location->v_data_ptr == (double)src_0_location->v_data_ptr;\
      break;\
    default:\
      result = 0;\
      break;\
    }\
  }/*}}}*/

bool bic_char_operator_binary_plus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CHAR_BINARY_EQUAL_OPS_CHAR_INTEGER_FLOAT(+,"operator_binary_plus_equal#1");

  return true;
}/*}}}*/

bool bic_char_operator_binary_minus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CHAR_BINARY_EQUAL_OPS_CHAR_INTEGER_FLOAT(-,"operator_binary_minus_equal#1");

  return true;
}/*}}}*/

bool bic_char_operator_binary_asterisk_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CHAR_BINARY_EQUAL_OPS_CHAR_INTEGER_FLOAT(*,"operator_binary_asterisk_equal#1");

  return true;
}/*}}}*/

bool bic_char_operator_binary_slash_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  char result = (char)dst_location->v_data_ptr;

  switch (src_0_location->v_type)
  {
  case c_bi_class_char:
  {
    char divider = (char)src_0_location->v_data_ptr;

    // - ERROR -
    if (divider == 0)
    {
      exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    result /= divider;
  }
  break;
  case c_bi_class_integer:
  {
    long long int divider = (long long int)src_0_location->v_data_ptr;

    // - ERROR -
    if (divider == 0)
    {
      exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    result /= divider;
  }
  break;
  case c_bi_class_float:
  {
    double divider = (double)src_0_location->v_data_ptr;

    // - ERROR -
    if (divider == 0.0)
    {
      exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    result /= divider;
  }
  break;

  // - ERROR -
  default:
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_slash_equal#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  BIC_SIMPLE_SET_DST_AND_RES(c_bi_class_char,result);

  return true;
}/*}}}*/

bool bic_char_operator_binary_percent_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CHAR_BINARY_EQUAL_OPS_CHAR_INTEGER(%,"operator_binary_percent_equal#1");

  return true;
}/*}}}*/

bool bic_char_operator_binary_double_ls_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CHAR_BINARY_SHIFT_EQUAL_OPS_CHAR_INTEGER(<<,"operator_binary_double_ls_br_equal#1");

  return true;
}/*}}}*/

bool bic_char_operator_binary_double_rs_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CHAR_BINARY_SHIFT_EQUAL_OPS_CHAR_INTEGER(>>,"operator_binary_double_rs_br_equal#1");

  return true;
}/*}}}*/

bool bic_char_operator_binary_ampersand_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CHAR_BINARY_EQUAL_OPS_CHAR_INTEGER(&,"operator_binary_ampersand_equal#1");

  return true;
}/*}}}*/

bool bic_char_operator_binary_pipe_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CHAR_BINARY_EQUAL_OPS_CHAR_INTEGER(|,"operator_binary_pipe_equal#1");

  return true;
}/*}}}*/

bool bic_char_operator_binary_circumflex_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CHAR_BINARY_EQUAL_OPS_CHAR_INTEGER(^,"operator_binary_circumflex_equal#1");

  return true;
}/*}}}*/

bool bic_char_operator_binary_double_ampersand(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CHAR_BINARY_OPS_CHAR_INTEGER_FLOAT_RESULT_INTEGER(&&,"operator_binary_double_ampersand#1");

  return true;
}/*}}}*/

bool bic_char_operator_binary_double_pipe(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CHAR_BINARY_OPS_CHAR_INTEGER_FLOAT_RESULT_INTEGER(||,"operator_binary_double_pipe#1");

  return true;
}/*}}}*/

bool bic_char_operator_binary_ampersand(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CHAR_BINARY_OPS_CHAR_INTEGER_RESULT_INTEGER(&,"operator_binary_ampersand#1");

  return true;
}/*}}}*/

bool bic_char_operator_binary_pipe(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CHAR_BINARY_OPS_CHAR_INTEGER_RESULT_INTEGER(|,"operator_binary_pipe#1");

  return true;
}/*}}}*/

bool bic_char_operator_binary_circumflex(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CHAR_BINARY_OPS_CHAR_INTEGER_RESULT_INTEGER(^,"operator_binary_circumflex#1");

  return true;
}/*}}}*/

bool bic_char_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_CHAR_COMPARE_WITH_TYPE_BOOL();

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_char_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_CHAR_COMPARE_WITH_TYPE_BOOL();
  result = !result;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_char_operator_binary_rs_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CHAR_BINARY_OPS_CHAR_INTEGER_FLOAT_RESULT_INTEGER(>,"operator_binary_rs_br#1");

  return true;
}/*}}}*/

bool bic_char_operator_binary_ls_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CHAR_BINARY_OPS_CHAR_INTEGER_FLOAT_RESULT_INTEGER(<,"operator_binary_ls_br#1");

  return true;
}/*}}}*/

bool bic_char_operator_binary_rs_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CHAR_BINARY_OPS_CHAR_INTEGER_FLOAT_RESULT_INTEGER(>=,"operator_binary_rs_br_equal#1");

  return true;
}/*}}}*/

bool bic_char_operator_binary_ls_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CHAR_BINARY_OPS_CHAR_INTEGER_FLOAT_RESULT_INTEGER(<=,"operator_binary_ls_br_equal#1");

  return true;
}/*}}}*/

bool bic_char_operator_binary_double_rs_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CHAR_BINARY_SHIFT_OPS_CHAR_INTEGER_RESULT_INTEGER(>>,"operator_binary_double_rs_br#1");

  return true;
}/*}}}*/

bool bic_char_operator_binary_double_ls_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CHAR_BINARY_SHIFT_OPS_CHAR_INTEGER_RESULT_INTEGER(<<,"operator_binary_double_ls_br#1");

  return true;
}/*}}}*/

bool bic_char_operator_binary_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CHAR_BINARY_OPS_CHAR_INTEGER_FLOAT(+,"operator_binary_plus#1");

  return true;
}/*}}}*/

bool bic_char_operator_binary_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CHAR_BINARY_OPS_CHAR_INTEGER_FLOAT(-,"operator_binary_minus#1");

  return true;
}/*}}}*/

bool bic_char_operator_binary_asterisk(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CHAR_BINARY_OPS_CHAR_INTEGER_FLOAT(*,"operator_binary_asterisk#1");

  return true;
}/*}}}*/

bool bic_char_operator_binary_slash(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  unsigned v_type;
  v_data_type v_data_ptr;

  switch (src_0_location->v_type)
  {
  case c_bi_class_char:
  {
    char divider = (char)src_0_location->v_data_ptr;

    // - ERROR -
    if (divider == 0)
    {
      exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    v_type = c_bi_class_char;
    v_data_ptr = (char)((char)dst_location->v_data_ptr / divider) ;
  }
  break;
  case c_bi_class_integer:
  {
    long long int divider = (long long int)src_0_location->v_data_ptr;

    // - ERROR -
    if (divider == 0)
    {
      exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    v_type = c_bi_class_integer;
    v_data_ptr = (long long int)((char)dst_location->v_data_ptr / divider);
  }
  break;
  case c_bi_class_float:
  {
    double divider = (double)src_0_location->v_data_ptr;

    // - ERROR -
    if (divider == 0.0)
    {
      exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    v_type = c_bi_class_float;
    v_data_ptr = (double)((char)dst_location->v_data_ptr / divider);
  }
  break;

  // - ERROR -
  default:
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_slash#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  BIC_SIMPLE_SET_RES(v_type,v_data_ptr);

  return true;
}/*}}}*/

bool bic_char_operator_binary_percent(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  unsigned v_type;
  v_data_type v_data_ptr;

  switch (src_0_location->v_type) {
  case c_bi_class_char:
    v_type = c_bi_class_char;
    v_data_ptr = (char)((char)dst_location->v_data_ptr % (char)src_0_location->v_data_ptr);
    break;
  case c_bi_class_integer:
    v_type = c_bi_class_integer;
    v_data_ptr = (long long int)((char)dst_location->v_data_ptr % (long long int)src_0_location->v_data_ptr);
    break;
  break;

  /* - ERROR - */
  default:
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_percent#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  BIC_SIMPLE_SET_RES(v_type,v_data_ptr);

  return true;
}/*}}}*/

bool bic_char_operator_unary_post_double_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CHAR_POST_UNARY(+1);

  return true;
}/*}}}*/

bool bic_char_operator_unary_post_double_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CHAR_POST_UNARY(-1);

  return true;
}/*}}}*/

bool bic_char_operator_unary_pre_double_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CHAR_PRE_UNARY(+1);

  return true;
}/*}}}*/

bool bic_char_operator_unary_pre_double_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CHAR_PRE_UNARY(-1);

  return true;
}/*}}}*/

bool bic_char_operator_unary_pre_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CHAR_PRE_UNARY_TMP_RESULT(+);

  return true;
}/*}}}*/

bool bic_char_operator_unary_pre_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CHAR_PRE_UNARY_TMP_RESULT(-);

  return true;
}/*}}}*/

bool bic_char_operator_unary_pre_exclamation(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ! (char)dst_location->v_data_ptr;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_char_operator_unary_pre_tilde(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_CHAR_PRE_UNARY_TMP_RESULT(~);

  return true;
}/*}}}*/

bool bic_char_method_Char_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  return true;
}/*}}}*/

bool bic_char_method_Char_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  switch (src_0_location->v_type)
  {
  case c_bi_class_char:
    dst_location->v_data_ptr = (char)src_0_location->v_data_ptr;
    break;
  case c_bi_class_integer:
    dst_location->v_data_ptr = (char)(long long int)src_0_location->v_data_ptr;
    break;

    // - ERROR -
  default:
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Char#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  return true;
}/*}}}*/

bool bic_char_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  if (src_0_location->v_type == c_bi_class_char)
  {
    char first = (char)dst_location->v_data_ptr;
    char second = (char)src_0_location->v_data_ptr;

    result = first < second ? -1 : (first > second ? 1 : 0);
  }
  else
  {
    result = c_bi_class_char < src_0_location->v_type ? -1 : 1;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_char_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING(
    char character = (char)dst_location->v_data_ptr;
    string_ptr->set(1,&character)
  );

  return true;
}/*}}}*/

bool bic_char_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - print value to standard output -
  fputc((char)dst_location->v_data_ptr,stdout);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

// - class INTEGER -
built_in_class_s integer_class =
{/*{{{*/
  "Integer",
  c_modifier_public | c_modifier_final,
  43, integer_methods,
  0, integer_variables,
  bic_integer_consts,
  bic_integer_init,
  bic_integer_clear,
  bic_integer_compare,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  bic_integer_pack,
  bic_integer_unpack,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s integer_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_integer_operator_binary_equal
  },
  {
    "operator_binary_plus_equal#1",
    c_modifier_public | c_modifier_final,
    bic_integer_operator_binary_plus_equal
  },
  {
    "operator_binary_minus_equal#1",
    c_modifier_public | c_modifier_final,
    bic_integer_operator_binary_minus_equal
  },
  {
    "operator_binary_asterisk_equal#1",
    c_modifier_public | c_modifier_final,
    bic_integer_operator_binary_asterisk_equal
  },
  {
    "operator_binary_slash_equal#1",
    c_modifier_public | c_modifier_final,
    bic_integer_operator_binary_slash_equal
  },
  {
    "operator_binary_percent_equal#1",
    c_modifier_public | c_modifier_final,
    bic_integer_operator_binary_percent_equal
  },
  {
    "operator_binary_double_ls_br_equal#1",
    c_modifier_public | c_modifier_final,
    bic_integer_operator_binary_double_ls_br_equal
  },
  {
    "operator_binary_double_rs_br_equal#1",
    c_modifier_public | c_modifier_final,
    bic_integer_operator_binary_double_rs_br_equal
  },
  {
    "operator_binary_ampersand_equal#1",
    c_modifier_public | c_modifier_final,
    bic_integer_operator_binary_ampersand_equal
  },
  {
    "operator_binary_pipe_equal#1",
    c_modifier_public | c_modifier_final,
    bic_integer_operator_binary_pipe_equal
  },
  {
    "operator_binary_circumflex_equal#1",
    c_modifier_public | c_modifier_final,
    bic_integer_operator_binary_circumflex_equal
  },
  {
    "operator_binary_double_ampersand#1",
    c_modifier_public | c_modifier_final,
    bic_integer_operator_binary_double_ampersand
  },
  {
    "operator_binary_double_pipe#1",
    c_modifier_public | c_modifier_final,
    bic_integer_operator_binary_double_pipe
  },
  {
    "operator_binary_ampersand#1",
    c_modifier_public | c_modifier_final,
    bic_integer_operator_binary_ampersand
  },
  {
    "operator_binary_pipe#1",
    c_modifier_public | c_modifier_final,
    bic_integer_operator_binary_pipe
  },
  {
    "operator_binary_circumflex#1",
    c_modifier_public | c_modifier_final,
    bic_integer_operator_binary_circumflex
  },
  {
    "operator_binary_double_equal#1",
    c_modifier_public | c_modifier_final,
    bic_integer_operator_binary_double_equal
  },
  {
    "operator_binary_exclamation_equal#1",
    c_modifier_public | c_modifier_final,
    bic_integer_operator_binary_exclamation_equal
  },
  {
    "operator_binary_rs_br#1",
    c_modifier_public | c_modifier_final,
    bic_integer_operator_binary_rs_br
  },
  {
    "operator_binary_ls_br#1",
    c_modifier_public | c_modifier_final,
    bic_integer_operator_binary_ls_br
  },
  {
    "operator_binary_rs_br_equal#1",
    c_modifier_public | c_modifier_final,
    bic_integer_operator_binary_rs_br_equal
  },
  {
    "operator_binary_ls_br_equal#1",
    c_modifier_public | c_modifier_final,
    bic_integer_operator_binary_ls_br_equal
  },
  {
    "operator_binary_double_rs_br#1",
    c_modifier_public | c_modifier_final,
    bic_integer_operator_binary_double_rs_br
  },
  {
    "operator_binary_double_ls_br#1",
    c_modifier_public | c_modifier_final,
    bic_integer_operator_binary_double_ls_br
  },
  {
    "operator_binary_plus#1",
    c_modifier_public | c_modifier_final,
    bic_integer_operator_binary_plus
  },
  {
    "operator_binary_minus#1",
    c_modifier_public | c_modifier_final,
    bic_integer_operator_binary_minus
  },
  {
    "operator_binary_asterisk#1",
    c_modifier_public | c_modifier_final,
    bic_integer_operator_binary_asterisk
  },
  {
    "operator_binary_slash#1",
    c_modifier_public | c_modifier_final,
    bic_integer_operator_binary_slash
  },
  {
    "operator_binary_percent#1",
    c_modifier_public | c_modifier_final,
    bic_integer_operator_binary_percent
  },
  {
    "operator_unary_post_double_plus#0",
    c_modifier_public | c_modifier_final,
    bic_integer_operator_unary_post_double_plus
  },
  {
    "operator_unary_post_double_minus#0",
    c_modifier_public | c_modifier_final,
    bic_integer_operator_unary_post_double_minus
  },
  {
    "operator_unary_pre_double_plus#0",
    c_modifier_public | c_modifier_final,
    bic_integer_operator_unary_pre_double_plus
  },
  {
    "operator_unary_pre_double_minus#0",
    c_modifier_public | c_modifier_final,
    bic_integer_operator_unary_pre_double_minus
  },
  {
    "operator_unary_pre_plus#0",
    c_modifier_public | c_modifier_final,
    bic_integer_operator_unary_pre_plus
  },
  {
    "operator_unary_pre_minus#0",
    c_modifier_public | c_modifier_final,
    bic_integer_operator_unary_pre_minus
  },
  {
    "operator_unary_pre_exclamation#0",
    c_modifier_public | c_modifier_final,
    bic_integer_operator_unary_pre_exclamation
  },
  {
    "operator_unary_pre_tilde#0",
    c_modifier_public | c_modifier_final,
    bic_integer_operator_unary_pre_tilde
  },
  {
    "Integer#0",
    c_modifier_public | c_modifier_final,
    bic_integer_method_Integer_0
  },
  {
    "Integer#1",
    c_modifier_public | c_modifier_final,
    bic_integer_method_Integer_1
  },
  {
    "Integer#2",
    c_modifier_public | c_modifier_final,
    bic_integer_method_Integer_2
  },
  {
    "compare#1",
    c_modifier_public | c_modifier_final,
    bic_integer_method_compare_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_integer_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_integer_method_print_0
  },
};/*}}}*/

built_in_variable_s integer_variables[] =
{/*{{{*/
};/*}}}*/

void bic_integer_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_integer_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (long long int)0LL;
}/*}}}*/

void bic_integer_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

int bic_integer_compare(location_s *first_loc,location_s *second_loc)
{/*{{{*/
  long long int first = (long long int)first_loc->v_data_ptr;
  long long int second = (long long int)second_loc->v_data_ptr;

  return first < second ? -1 : (first > second ? 1 : 0);
}/*}}}*/

bool bic_integer_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack)
{/*{{{*/
  long long int value = (long long int)location_ptr->v_data_ptr;
  stream.append(sizeof(long long int),(const char *)&value);

  return true;
}/*}}}*/

bool bic_integer_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos)
{/*{{{*/
  if (stream.used < sizeof(long long int))
  {
    return false;
  }

  long long int value;
  stream.from_end(sizeof(long long int),(char *)&value,order_bytes);

  location_ptr->v_data_ptr = (long long int)value;

  return true;
}/*}}}*/

bool bic_integer_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

#define BIC_INTEGER_BINARY_EQUAL_OPS_CHAR_INTEGER_FLOAT(OPERATOR,NAME) \
  {/*{{{*/\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
    location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
    long long int result = (long long int)dst_location->v_data_ptr;\
\
    switch (src_0_location->v_type) {\
    case c_bi_class_char:\
      result OPERATOR ## = (char)src_0_location->v_data_ptr;\
      break;\
    case c_bi_class_integer:\
      result OPERATOR ## = (long long int)src_0_location->v_data_ptr;\
      break;\
    case c_bi_class_float:\
      result = (long long int)(result OPERATOR (double)src_0_location->v_data_ptr);\
      break;\
\
      /* - ERROR - */\
    default:\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
\
      return false;\
    }\
\
    BIC_SIMPLE_SET_DST_AND_RES(c_bi_class_integer,result);\
  }/*}}}*/

#define BIC_INTEGER_BINARY_EQUAL_OPS_CHAR_INTEGER(OPERATOR,NAME) \
  {/*{{{*/\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
    location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
    long long int result = (long long int)dst_location->v_data_ptr;\
\
    switch (src_0_location->v_type) {\
    case c_bi_class_char:\
      result OPERATOR ## = (char)src_0_location->v_data_ptr;\
      break;\
    case c_bi_class_integer:\
      result OPERATOR ## = (long long int)src_0_location->v_data_ptr;\
      break;\
\
      /* - ERROR - */\
    default:\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
\
      return false;\
    }\
\
    BIC_SIMPLE_SET_DST_AND_RES(c_bi_class_integer,result);\
  }/*}}}*/

#define BIC_INTEGER_BINARY_SHIFT_EQUAL_OPS_CHAR_INTEGER(OPERATOR,NAME) \
  {/*{{{*/\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
    location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
    long long int result = (long long int)dst_location->v_data_ptr;\
\
    switch (src_0_location->v_type) {\
    case c_bi_class_char:\
    {\
      char shift_count = (char)src_0_location->v_data_ptr;\
      if (shift_count < 0)\
      {\
        exception_s *new_exception = exception_s::throw_exception(it,c_error_NEGATIVE_SHIFT_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);\
        new_exception->params.push((long long int)shift_count);\
\
        return false;\
      }\
\
      result OPERATOR ## = shift_count;\
    }\
    break;\
    case c_bi_class_integer:\
    {\
      long long int shift_count = (long long int)src_0_location->v_data_ptr;\
      if (shift_count < 0)\
      {\
        exception_s *new_exception = exception_s::throw_exception(it,c_error_NEGATIVE_SHIFT_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);\
        new_exception->params.push(shift_count);\
\
        return false;\
      }\
\
      result OPERATOR ## = shift_count;\
    }\
    break;\
\
    /* - ERROR - */\
    default:\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
\
      return false;\
    }\
\
    BIC_SIMPLE_SET_DST_AND_RES(c_bi_class_integer,result);\
  }/*}}}*/

#define BIC_INTEGER_BINARY_OPS_CHAR_INTEGER_FLOAT_RESULT_INTEGER(OPERATOR,NAME) \
  {/*{{{*/\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
    location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
    long long int result;\
\
    switch (src_0_location->v_type) {\
    case c_bi_class_char:\
      result = (long long int)dst_location->v_data_ptr OPERATOR (char)src_0_location->v_data_ptr;\
      break;\
    case c_bi_class_integer:\
      result = (long long int)dst_location->v_data_ptr OPERATOR (long long int)src_0_location->v_data_ptr;\
      break;\
    case c_bi_class_float:\
      result = (long long int)dst_location->v_data_ptr OPERATOR (double)src_0_location->v_data_ptr;\
      break;\
\
      /* - ERROR - */\
    default:\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
\
      return false;\
    }\
\
    BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
  }/*}}}*/

#define BIC_INTEGER_BINARY_OPS_CHAR_INTEGER_RESULT_INTEGER(OPERATOR,NAME) \
  {/*{{{*/\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
    location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
    long long int result;\
\
    switch (src_0_location->v_type) {\
    case c_bi_class_char:\
      result = (long long int)dst_location->v_data_ptr OPERATOR (char)src_0_location->v_data_ptr;\
      break;\
    case c_bi_class_integer:\
      result = (long long int)dst_location->v_data_ptr OPERATOR (long long int)src_0_location->v_data_ptr;\
      break;\
\
      /* - ERROR - */\
    default:\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
\
      return false;\
    }\
\
    BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
  }/*}}}*/

#define BIC_INTEGER_BINARY_SHIFT_OPS_CHAR_INTEGER_RESULT_INTEGER(OPERATOR,NAME) \
  {/*{{{*/\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
    location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
    long long int result;\
\
    switch (src_0_location->v_type) {\
    case c_bi_class_char:\
    {\
      char shift_count = (char)src_0_location->v_data_ptr;\
      if (shift_count < 0)\
      {\
        exception_s *new_exception = exception_s::throw_exception(it,c_error_NEGATIVE_SHIFT_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);\
        new_exception->params.push((long long int)shift_count);\
\
        return false;\
      }\
\
      result = (long long int)dst_location->v_data_ptr OPERATOR shift_count;\
    }\
    break;\
    case c_bi_class_integer:\
    {\
      long long int shift_count = (long long int)src_0_location->v_data_ptr;\
      if (shift_count < 0)\
      {\
        exception_s *new_exception = exception_s::throw_exception(it,c_error_NEGATIVE_SHIFT_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);\
        new_exception->params.push(shift_count);\
\
        return false;\
      }\
\
      result = (long long int)dst_location->v_data_ptr OPERATOR shift_count;\
    }\
    break;\
\
    /* - ERROR - */\
    default:\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
\
      return false;\
    }\
\
    BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
  }/*}}}*/

#define BIC_INTEGER_BINARY_OPS_CHAR_INTEGER_FLOAT(OPERATOR,NAME) \
  {/*{{{*/\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
    location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
    unsigned v_type;\
    v_data_type v_data_ptr;\
\
    switch (src_0_location->v_type) {\
    case c_bi_class_char:\
      v_type = c_bi_class_integer;\
      v_data_ptr = (long long int)((long long int)dst_location->v_data_ptr OPERATOR (char)src_0_location->v_data_ptr);\
      break;\
    case c_bi_class_integer:\
      v_type = c_bi_class_integer;\
      v_data_ptr = (long long int)((long long int)dst_location->v_data_ptr OPERATOR (long long int)src_0_location->v_data_ptr);\
      break;\
    case c_bi_class_float:\
      v_type = c_bi_class_float;\
      v_data_ptr = (double)((long long int)dst_location->v_data_ptr OPERATOR (double)src_0_location->v_data_ptr);\
    break;\
\
    /* - ERROR - */\
    default:\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
\
      return false;\
    }\
\
    BIC_SIMPLE_SET_RES(v_type,v_data_ptr);\
  }/*}}}*/

#define BIC_INTEGER_POST_UNARY(OPERATOR) \
  {/*{{{*/\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
    long long int result = ((long long int)dst_location->v_data_ptr) OPERATOR;\
\
    BIC_SIMPLE_SET_RES_SWAP(c_bi_class_integer,result);\
  }/*}}}*/

#define BIC_INTEGER_PRE_UNARY(OPERATOR) \
  {/*{{{*/\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
    long long int result = ((long long int)dst_location->v_data_ptr) OPERATOR;\
\
    BIC_SIMPLE_SET_DST_AND_RES(c_bi_class_integer,result);\
  }/*}}}*/

#define BIC_INTEGER_PRE_UNARY_TMP_RESULT(OPERATOR) \
  {/*{{{*/\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
    long long int result = OPERATOR (long long int)dst_location->v_data_ptr;\
\
    BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
  }/*}}}*/

#define BIC_INTEGER_COMPARE_WITH_TYPE_BOOL() \
  {/*{{{*/\
    switch (src_0_location->v_type) {\
    case c_bi_class_char:\
      result = (long long int)dst_location->v_data_ptr == (char)src_0_location->v_data_ptr;\
      break;\
    case c_bi_class_integer:\
      result = (long long int)dst_location->v_data_ptr == (long long int)src_0_location->v_data_ptr;\
      break;\
    case c_bi_class_float:\
      result = (long long int)dst_location->v_data_ptr == (double)src_0_location->v_data_ptr;\
      break;\
    default:\
      result = 0;\
      break;\
    }\
  }/*}}}*/

bool bic_integer_operator_binary_plus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INTEGER_BINARY_EQUAL_OPS_CHAR_INTEGER_FLOAT(+,"operator_binary_plus_equal#1");

  return true;
}/*}}}*/

bool bic_integer_operator_binary_minus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INTEGER_BINARY_EQUAL_OPS_CHAR_INTEGER_FLOAT(-,"operator_binary_minus_equal#1");

  return true;
}/*}}}*/

bool bic_integer_operator_binary_asterisk_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INTEGER_BINARY_EQUAL_OPS_CHAR_INTEGER_FLOAT(*,"operator_binary_asterisk_equal#1");

  return true;
}/*}}}*/

bool bic_integer_operator_binary_slash_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result = (long long int)dst_location->v_data_ptr;

  switch (src_0_location->v_type)
  {
  case c_bi_class_char:
  {
    char divider = (char)src_0_location->v_data_ptr;

    // - ERROR -
    if (divider == 0)
    {
      exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    result /= divider;
  }
  break;
  case c_bi_class_integer:
  {
    long long int divider = (long long int)src_0_location->v_data_ptr;

    // - ERROR -
    if (divider == 0)
    {
      exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    result /= divider;
  }
  break;
  case c_bi_class_float:
  {
    double divider = (double)src_0_location->v_data_ptr;

    // - ERROR -
    if (divider == 0.0)
    {
      exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    result /= divider;
  }
  break;

  // - ERROR -
  default:
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_slash_equal#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  BIC_SIMPLE_SET_DST_AND_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_integer_operator_binary_percent_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INTEGER_BINARY_EQUAL_OPS_CHAR_INTEGER(%,"operator_binary_percent_equal#1");

  return true;
}/*}}}*/

bool bic_integer_operator_binary_double_ls_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INTEGER_BINARY_SHIFT_EQUAL_OPS_CHAR_INTEGER(<<,"operator_binary_double_ls_br_equal#1");

  return true;
}/*}}}*/

bool bic_integer_operator_binary_double_rs_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INTEGER_BINARY_SHIFT_EQUAL_OPS_CHAR_INTEGER(>>,"operator_binary_double_rs_br_equal#1");

  return true;
}/*}}}*/

bool bic_integer_operator_binary_ampersand_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INTEGER_BINARY_EQUAL_OPS_CHAR_INTEGER(&,"operator_binary_ampersand_equal#1");

  return true;
}/*}}}*/

bool bic_integer_operator_binary_pipe_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INTEGER_BINARY_EQUAL_OPS_CHAR_INTEGER(|,"operator_binary_pipe_equal#1");

  return true;
}/*}}}*/

bool bic_integer_operator_binary_circumflex_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INTEGER_BINARY_EQUAL_OPS_CHAR_INTEGER(^,"operator_binary_circumflex_equal#1");

  return true;
}/*}}}*/

bool bic_integer_operator_binary_double_ampersand(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INTEGER_BINARY_OPS_CHAR_INTEGER_FLOAT_RESULT_INTEGER(&&,"operator_binary_double_ampersand#1");

  return true;
}/*}}}*/

bool bic_integer_operator_binary_double_pipe(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INTEGER_BINARY_OPS_CHAR_INTEGER_FLOAT_RESULT_INTEGER(||,"operator_binary_double_pipe#1");

  return true;
}/*}}}*/

bool bic_integer_operator_binary_ampersand(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INTEGER_BINARY_OPS_CHAR_INTEGER_RESULT_INTEGER(&,"operator_binary_ampersand#1");

  return true;
}/*}}}*/

bool bic_integer_operator_binary_pipe(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INTEGER_BINARY_OPS_CHAR_INTEGER_RESULT_INTEGER(|,"operator_binary_pipe#1");

  return true;
}/*}}}*/

bool bic_integer_operator_binary_circumflex(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INTEGER_BINARY_OPS_CHAR_INTEGER_RESULT_INTEGER(^,"operator_binary_circumflex#1");

  return true;
}/*}}}*/

bool bic_integer_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_INTEGER_COMPARE_WITH_TYPE_BOOL();

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_integer_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_INTEGER_COMPARE_WITH_TYPE_BOOL();
  result = !result;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_integer_operator_binary_rs_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INTEGER_BINARY_OPS_CHAR_INTEGER_FLOAT_RESULT_INTEGER(>,"operator_binary_rs_br#1");

  return true;
}/*}}}*/

bool bic_integer_operator_binary_ls_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INTEGER_BINARY_OPS_CHAR_INTEGER_FLOAT_RESULT_INTEGER(<,"operator_binary_ls_br#1");

  return true;
}/*}}}*/

bool bic_integer_operator_binary_rs_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INTEGER_BINARY_OPS_CHAR_INTEGER_FLOAT_RESULT_INTEGER(>=,"operator_binary_rs_br_equal#1");

  return true;
}/*}}}*/

bool bic_integer_operator_binary_ls_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INTEGER_BINARY_OPS_CHAR_INTEGER_FLOAT_RESULT_INTEGER(<=,"operator_binary_ls_br_equal#1");

  return true;
}/*}}}*/

bool bic_integer_operator_binary_double_rs_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INTEGER_BINARY_SHIFT_OPS_CHAR_INTEGER_RESULT_INTEGER(>>,"operator_binary_double_rs_br#1");

  return true;
}/*}}}*/

bool bic_integer_operator_binary_double_ls_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INTEGER_BINARY_SHIFT_OPS_CHAR_INTEGER_RESULT_INTEGER(<<,"operator_binary_double_ls_br#1");

  return true;
}/*}}}*/

bool bic_integer_operator_binary_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INTEGER_BINARY_OPS_CHAR_INTEGER_FLOAT(+,"operator_binary_plus#1");

  return true;
}/*}}}*/

bool bic_integer_operator_binary_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INTEGER_BINARY_OPS_CHAR_INTEGER_FLOAT(-,"operator_binary_minus#1");

  return true;
}/*}}}*/

bool bic_integer_operator_binary_asterisk(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  unsigned v_type;
  v_data_type v_data_ptr;

  switch (src_0_location->v_type)
  {
  case c_bi_class_char:
    v_type = c_bi_class_integer;
    v_data_ptr = (long long int)((long long int)dst_location->v_data_ptr * (char)src_0_location->v_data_ptr);
    break;
  case c_bi_class_integer:
    v_type = c_bi_class_integer;
    v_data_ptr = (long long int)((long long int)dst_location->v_data_ptr * (long long int)src_0_location->v_data_ptr);
    break;
  case c_bi_class_float:
    v_type = c_bi_class_float;
    v_data_ptr = (double)((long long int)dst_location->v_data_ptr * (double)src_0_location->v_data_ptr);
  break;
  case c_bi_class_string:
  {
    long long int mult = (long long int)dst_location->v_data_ptr;
    string_s *source_ptr = (string_s *)src_0_location->v_data_ptr;

    string_s *result_ptr = it.get_new_string_ptr();

    if (mult >= 0)
    {
      result_ptr->mult_char_ptr(source_ptr->size - 1,source_ptr->data,mult);
    }

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,result_ptr);

    BIC_SET_RESULT(new_location);

    return true;
  }
  break;

  /* - ERROR - */
  default:
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_asterisk#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  BIC_SIMPLE_SET_RES(v_type,v_data_ptr);

  return true;
}/*}}}*/

bool bic_integer_operator_binary_slash(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  unsigned v_type;
  v_data_type v_data_ptr;

  switch (src_0_location->v_type)
  {
  case c_bi_class_char:
  {
    char divider = (char)src_0_location->v_data_ptr;

    // - ERROR -
    if (divider == 0)
    {
      exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    v_type = c_bi_class_integer;
    v_data_ptr = (long long int)((long long int)dst_location->v_data_ptr / divider);
  }
  break;
  case c_bi_class_integer:
  {
    long long int divider = (long long int)src_0_location->v_data_ptr;

    // - ERROR -
    if (divider == 0)
    {
      exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    v_type = c_bi_class_integer;
    v_data_ptr = (long long int)((long long int)dst_location->v_data_ptr / divider);
  }
  break;
  case c_bi_class_float:
  {
    double divider = (double)src_0_location->v_data_ptr;

    // - ERROR -
    if (divider == 0.0)
    {
      exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    v_type = c_bi_class_float;
    v_data_ptr = (double)((long long int)dst_location->v_data_ptr / divider);
  }
  break;

  // - ERROR -
  default:
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_slash#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  BIC_SIMPLE_SET_RES(v_type,v_data_ptr);

  return true;
}/*}}}*/

bool bic_integer_operator_binary_percent(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INTEGER_BINARY_OPS_CHAR_INTEGER_RESULT_INTEGER(%,"operator_binary_percent#1");

  return true;
}/*}}}*/

bool bic_integer_operator_unary_post_double_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INTEGER_POST_UNARY(+1);

  return true;
}/*}}}*/

bool bic_integer_operator_unary_post_double_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INTEGER_POST_UNARY(-1);

  return true;
}/*}}}*/

bool bic_integer_operator_unary_pre_double_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INTEGER_PRE_UNARY(+1);

  return true;
}/*}}}*/

bool bic_integer_operator_unary_pre_double_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INTEGER_PRE_UNARY(-1);

  return true;
}/*}}}*/

bool bic_integer_operator_unary_pre_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INTEGER_PRE_UNARY_TMP_RESULT(+);

  return true;
}/*}}}*/

bool bic_integer_operator_unary_pre_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INTEGER_PRE_UNARY_TMP_RESULT(-);

  return true;
}/*}}}*/

bool bic_integer_operator_unary_pre_exclamation(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INTEGER_PRE_UNARY_TMP_RESULT(!);

  return true;
}/*}}}*/

bool bic_integer_operator_unary_pre_tilde(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INTEGER_PRE_UNARY_TMP_RESULT(~);

  return true;
}/*}}}*/

bool bic_integer_method_Integer_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  return true;
}/*}}}*/

bool bic_integer_method_Integer_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  switch (src_0_location->v_type)
  {
  case c_bi_class_char:
    dst_location->v_data_ptr = (long long int)(char)src_0_location->v_data_ptr;
    break;
  case c_bi_class_integer:
    dst_location->v_data_ptr = (long long int)src_0_location->v_data_ptr;
    break;
  case c_bi_class_float:
    dst_location->v_data_ptr = (long long int)(double)src_0_location->v_data_ptr;
    break;
  case c_bi_class_string:
  {
    string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

    char *end_ptr = nullptr;
    dst_location->v_data_ptr = (long long int)strtoll(string_ptr->data,&end_ptr,0);

    if (string_ptr->size <= 1 || (string_ptr->data + string_ptr->size - 1) != end_ptr)
    {
      exception_s *new_exception = exception_s::throw_exception(it,c_error_INTEGER_CONVERT_INVALID_STRING,operands[c_source_pos_idx],src_0_location);
      new_exception->params.push(0);

      return false;
    }
  }
  break;

  // - ERROR -
  default:
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Integer#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  return true;
}/*}}}*/

bool bic_integer_method_Integer_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  switch (src_0_location->v_type)
  {
  case c_bi_class_string:
  {
    if (src_1_location->v_type != c_bi_class_integer)
    {
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
      BIC_EXCEPTION_PUSH_METHOD_RI("Integer#2");
      new_exception->params.push(2);
      new_exception->params.push(src_0_location->v_type);
      new_exception->params.push(src_1_location->v_type);

      return false;
    }

    string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;
    long long int base = (long long int)src_1_location->v_data_ptr;

    if (base < 2 || base > 36)
    {
      exception_s *new_exception = exception_s::throw_exception(it,c_error_INTEGER_BASE_OUT_OF_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(base);

      return false;
    }

    char *end_ptr = nullptr;
    dst_location->v_data_ptr = (long long int)strtoll(string_ptr->data,&end_ptr,base);

    if (string_ptr->size <= 1 || (string_ptr->data + string_ptr->size - 1) != end_ptr)
    {
      exception_s *new_exception = exception_s::throw_exception(it,c_error_INTEGER_CONVERT_INVALID_STRING,operands[c_source_pos_idx],src_0_location);
      new_exception->params.push(base);

      return false;
    }
  }
  break;

  // - ERROR -
  default:
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Integer#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  return true;
}/*}}}*/

bool bic_integer_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  if (src_0_location->v_type == c_bi_class_integer)
  {
    long long int first = (long long int)dst_location->v_data_ptr;
    long long int second = (long long int)src_0_location->v_data_ptr;

    result = first < second ? -1 : (first > second ? 1 : 0);
  }
  else
  {
    result = c_bi_class_integer < src_0_location->v_type ? -1 : 1;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_integer_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING(
    string_ptr->setf("%" HOST_LL_FORMAT "d",(long long int)dst_location->v_data_ptr)
  );

  return true;
}/*}}}*/

bool bic_integer_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - print value to standard output -
  printf("%" HOST_LL_FORMAT "d",(long long int)dst_location->v_data_ptr);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

// - class FLOAT -
built_in_class_s float_class =
{/*{{{*/
  "Float",
  c_modifier_public | c_modifier_final,
  43, float_methods,
  1 + 5, float_variables,
  bic_float_consts,
  bic_float_init,
  bic_float_clear,
  bic_float_compare,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  bic_float_pack,
  bic_float_unpack,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s float_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_float_operator_binary_equal
  },
  {
    "operator_binary_plus_equal#1",
    c_modifier_public | c_modifier_final,
    bic_float_operator_binary_plus_equal
  },
  {
    "operator_binary_minus_equal#1",
    c_modifier_public | c_modifier_final,
    bic_float_operator_binary_minus_equal
  },
  {
    "operator_binary_asterisk_equal#1",
    c_modifier_public | c_modifier_final,
    bic_float_operator_binary_asterisk_equal
  },
  {
    "operator_binary_slash_equal#1",
    c_modifier_public | c_modifier_final,
    bic_float_operator_binary_slash_equal
  },
  {
    "operator_binary_double_ampersand#1",
    c_modifier_public | c_modifier_final,
    bic_float_operator_binary_double_ampersand
  },
  {
    "operator_binary_double_pipe#1",
    c_modifier_public | c_modifier_final,
    bic_float_operator_binary_double_pipe
  },
  {
    "operator_binary_double_equal#1",
    c_modifier_public | c_modifier_final,
    bic_float_operator_binary_double_equal
  },
  {
    "operator_binary_exclamation_equal#1",
    c_modifier_public | c_modifier_final,
    bic_float_operator_binary_exclamation_equal
  },
  {
    "operator_binary_rs_br#1",
    c_modifier_public | c_modifier_final,
    bic_float_operator_binary_rs_br
  },
  {
    "operator_binary_ls_br#1",
    c_modifier_public | c_modifier_final,
    bic_float_operator_binary_ls_br
  },
  {
    "operator_binary_rs_br_equal#1",
    c_modifier_public | c_modifier_final,
    bic_float_operator_binary_rs_br_equal
  },
  {
    "operator_binary_ls_br_equal#1",
    c_modifier_public | c_modifier_final,
    bic_float_operator_binary_ls_br_equal
  },
  {
    "operator_binary_plus#1",
    c_modifier_public | c_modifier_final,
    bic_float_operator_binary_plus
  },
  {
    "operator_binary_minus#1",
    c_modifier_public | c_modifier_final,
    bic_float_operator_binary_minus
  },
  {
    "operator_binary_asterisk#1",
    c_modifier_public | c_modifier_final,
    bic_float_operator_binary_asterisk
  },
  {
    "operator_binary_slash#1",
    c_modifier_public | c_modifier_final,
    bic_float_operator_binary_slash
  },
  {
    "operator_unary_post_double_plus#0",
    c_modifier_public | c_modifier_final,
    bic_float_operator_unary_post_double_plus
  },
  {
    "operator_unary_post_double_minus#0",
    c_modifier_public | c_modifier_final,
    bic_float_operator_unary_post_double_minus
  },
  {
    "operator_unary_pre_double_plus#0",
    c_modifier_public | c_modifier_final,
    bic_float_operator_unary_pre_double_plus
  },
  {
    "operator_unary_pre_double_minus#0",
    c_modifier_public | c_modifier_final,
    bic_float_operator_unary_pre_double_minus
  },
  {
    "operator_unary_pre_plus#0",
    c_modifier_public | c_modifier_final,
    bic_float_operator_unary_pre_plus
  },
  {
    "operator_unary_pre_minus#0",
    c_modifier_public | c_modifier_final,
    bic_float_operator_unary_pre_minus
  },
  {
    "operator_unary_pre_exclamation#0",
    c_modifier_public | c_modifier_final,
    bic_float_operator_unary_pre_exclamation
  },
  {
    "Float#0",
    c_modifier_public | c_modifier_final,
    bic_float_method_Float_0
  },
  {
    "Float#1",
    c_modifier_public | c_modifier_final,
    bic_float_method_Float_1
  },
  {
    "sin#0",
    c_modifier_public | c_modifier_final,
    bic_float_method_sin_0
  },
  {
    "cos#0",
    c_modifier_public | c_modifier_final,
    bic_float_method_cos_0
  },
  {
    "tan#0",
    c_modifier_public | c_modifier_final,
    bic_float_method_tan_0
  },
  {
    "asin#0",
    c_modifier_public | c_modifier_final,
    bic_float_method_asin_0
  },
  {
    "acos#0",
    c_modifier_public | c_modifier_final,
    bic_float_method_acos_0
  },
  {
    "atan#0",
    c_modifier_public | c_modifier_final,
    bic_float_method_atan_0
  },
  {
    "exp#0",
    c_modifier_public | c_modifier_final,
    bic_float_method_exp_0
  },
  {
    "log#0",
    c_modifier_public | c_modifier_final,
    bic_float_method_log_0
  },
  {
    "pow#1",
    c_modifier_public | c_modifier_final,
    bic_float_method_pow_1
  },
  {
    "sqrt#0",
    c_modifier_public | c_modifier_final,
    bic_float_method_sqrt_0
  },
  {
    "cbrt#0",
    c_modifier_public | c_modifier_final,
    bic_float_method_cbrt_0
  },
  {
    "hypot#1",
    c_modifier_public | c_modifier_final,
    bic_float_method_hypot_1
  },
  {
    "classify#0",
    c_modifier_public | c_modifier_final,
    bic_float_method_classify_0
  },
  {
    "isnan#0",
    c_modifier_public | c_modifier_final,
    bic_float_method_isnan_0
  },
  {
    "compare#1",
    c_modifier_public | c_modifier_final,
    bic_float_method_compare_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_float_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_float_method_print_0
  },
};/*}}}*/

built_in_variable_s float_variables[] =
{/*{{{*/

  // - float constants -
  { "INFINITY", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - float classes constants -
  { "CLASS_NAN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CLASS_INFINITE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CLASS_ZERO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CLASS_SUBNORMAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CLASS_NORMAL", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_float_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert float constants -
  {
    const_locations.push_blanks(1);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 1);

#define CREATE_FLOAT_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_float;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (double)VALUE;\
  cv_ptr++;

    double value = INFINITY;
    CREATE_FLOAT_BIC_STATIC(value);
  }

  // - insert float classes constants -
  {
    const_locations.push_blanks(5);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 5);

#define CREATE_FLOAT_CLASS_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_FLOAT_CLASS_BIC_STATIC(FP_NAN);
    CREATE_FLOAT_CLASS_BIC_STATIC(FP_INFINITE);
    CREATE_FLOAT_CLASS_BIC_STATIC(FP_ZERO);
    CREATE_FLOAT_CLASS_BIC_STATIC(FP_SUBNORMAL);
    CREATE_FLOAT_CLASS_BIC_STATIC(FP_NORMAL);
  }
}/*}}}*/

void bic_float_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (double)0.0;
}/*}}}*/

void bic_float_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

int bic_float_compare(location_s *first_loc,location_s *second_loc)
{/*{{{*/
  double first = (double)first_loc->v_data_ptr;
  double second = (double)second_loc->v_data_ptr;

  return first < second ? -1 : (first > second ? 1 : 0);
}/*}}}*/

bool bic_float_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack)
{/*{{{*/
  double value = (double)location_ptr->v_data_ptr;
  stream.append(sizeof(double),(const char *)&value);

  return true;
}/*}}}*/

bool bic_float_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos)
{/*{{{*/
  if (stream.used < sizeof(double))
  {
    return false;
  }

  double value;
  stream.from_end(sizeof(double),(char *)&value,order_bytes);

  location_ptr->v_data_ptr = (double)value;

  return true;
}/*}}}*/

bool bic_float_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

#define BIC_FLOAT_BINARY_EQUAL_OPS_CHAR_INTEGER_FLOAT(OPERATOR,NAME) \
  {/*{{{*/\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
    location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
    double result = (double)dst_location->v_data_ptr;\
\
    switch (src_0_location->v_type) {\
    case c_bi_class_char:\
      result OPERATOR ## = (char)src_0_location->v_data_ptr;\
      break;\
    case c_bi_class_integer:\
      result OPERATOR ## = (long long int)src_0_location->v_data_ptr;\
      break;\
    case c_bi_class_float:\
      result OPERATOR ## = (double)src_0_location->v_data_ptr;\
      break;\
\
      /* - ERROR - */\
    default:\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
\
      return false;\
    }\
\
    BIC_SIMPLE_SET_DST_AND_RES(c_bi_class_float,result);\
  }/*}}}*/

#define BIC_FLOAT_BINARY_OPS_CHAR_INTEGER_FLOAT_RESULT_INTEGER(OPERATOR,NAME) \
  {/*{{{*/\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
    location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
    long long int result;\
\
    switch (src_0_location->v_type) {\
    case c_bi_class_char:\
      result = (double)dst_location->v_data_ptr OPERATOR (char)src_0_location->v_data_ptr;\
      break;\
    case c_bi_class_integer:\
      result = (double)dst_location->v_data_ptr OPERATOR (long long int)src_0_location->v_data_ptr;\
      break;\
    case c_bi_class_float:\
      result = (double)dst_location->v_data_ptr OPERATOR (double)src_0_location->v_data_ptr;\
      break;\
\
      /* - ERROR - */\
    default:\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
\
      return false;\
    }\
\
    BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
  }/*}}}*/

#define BIC_FLOAT_BINARY_OPS_CHAR_INTEGER_FLOAT(OPERATOR,NAME) \
  {/*{{{*/\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
    location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
    double result;\
\
    switch (src_0_location->v_type) {\
    case c_bi_class_char:\
      result = (double)dst_location->v_data_ptr OPERATOR (char)src_0_location->v_data_ptr;\
      break;\
    case c_bi_class_integer:\
      result = (double)dst_location->v_data_ptr OPERATOR (long long int)src_0_location->v_data_ptr;\
      break;\
    case c_bi_class_float:\
      result = (double)dst_location->v_data_ptr OPERATOR (double)src_0_location->v_data_ptr;\
      break;\
\
      /* - ERROR - */\
    default:\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
\
      return false;\
    }\
\
    BIC_SIMPLE_SET_RES(c_bi_class_float,result);\
  }/*}}}*/

#define BIC_FLOAT_POST_UNARY(OPERATOR) \
  {/*{{{*/\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
    double result = (double)dst_location->v_data_ptr OPERATOR;\
\
    BIC_SIMPLE_SET_RES_SWAP(c_bi_class_float,result);\
  }/*}}}*/

#define BIC_FLOAT_PRE_UNARY(OPERATOR) \
  {/*{{{*/\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
    double result = (double)dst_location->v_data_ptr OPERATOR;\
\
    BIC_SIMPLE_SET_DST_AND_RES(c_bi_class_float,result);\
  }/*}}}*/

#define BIC_FLOAT_PRE_UNARY_TMP_RESULT(OPERATOR) \
  {/*{{{*/\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
    double result = OPERATOR (double)dst_location->v_data_ptr;\
\
    BIC_SIMPLE_SET_RES(c_bi_class_float,result);\
  }/*}}}*/

#define BIC_FLOAT_COMPARE_WITH_TYPE_BOOL() \
  {/*{{{*/\
    switch (src_0_location->v_type) {\
    case c_bi_class_char:\
      result = (double)dst_location->v_data_ptr == (char)src_0_location->v_data_ptr;\
      break;\
    case c_bi_class_integer:\
      result = (double)dst_location->v_data_ptr == (long long int)src_0_location->v_data_ptr;\
      break;\
    case c_bi_class_float:\
      result = (double)dst_location->v_data_ptr == (double)src_0_location->v_data_ptr;\
      break;\
    default:\
      result = 0;\
      break;\
    }\
  }/*}}}*/

#define BIC_FLOAT_FUNCTION_BINARY_OPS_CHAR_INTEGER_FLOAT(FNAME,NAME) \
  {/*{{{*/\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
    location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
    double result;\
\
    switch (src_0_location->v_type) {\
    case c_bi_class_char:\
      result = FNAME((double)dst_location->v_data_ptr, (char)src_0_location->v_data_ptr);\
      break;\
    case c_bi_class_integer:\
      result = FNAME((double)dst_location->v_data_ptr, (long long int)src_0_location->v_data_ptr);\
      break;\
    case c_bi_class_float:\
      result = FNAME((double)dst_location->v_data_ptr, (double)src_0_location->v_data_ptr);\
      break;\
\
      /* - ERROR - */\
    default:\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
\
      return false;\
    }\
\
    BIC_SIMPLE_SET_RES(c_bi_class_float,result);\
  }/*}}}*/

#define BIC_FLOAT_FUNCTION_UNARY(FNAME) \
  {/*{{{*/\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
    double result = FNAME((double)dst_location->v_data_ptr);\
\
    BIC_SIMPLE_SET_RES(c_bi_class_float,result);\
  }/*}}}*/

bool bic_float_operator_binary_plus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FLOAT_BINARY_EQUAL_OPS_CHAR_INTEGER_FLOAT(+,"operator_binary_plus_equal#1");

  return true;
}/*}}}*/

bool bic_float_operator_binary_minus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FLOAT_BINARY_EQUAL_OPS_CHAR_INTEGER_FLOAT(-,"operator_binary_minus_equal#1");

  return true;
}/*}}}*/

bool bic_float_operator_binary_asterisk_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FLOAT_BINARY_EQUAL_OPS_CHAR_INTEGER_FLOAT(*,"operator_binary_asterisk_equal#1");

  return true;
}/*}}}*/

bool bic_float_operator_binary_slash_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  double result = (double)dst_location->v_data_ptr;

  switch (src_0_location->v_type)
  {
  case c_bi_class_char:
  {
    char divider = (char)src_0_location->v_data_ptr;

    // - ERROR -
    if (divider == 0)
    {
      exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    result /= divider;
  }
  break;
  case c_bi_class_integer:
  {
    long long int divider = (long long int)src_0_location->v_data_ptr;

    // - ERROR -
    if (divider == 0)
    {
      exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    result /= divider;
  }
  break;
  case c_bi_class_float:
  {
    double divider = (double)src_0_location->v_data_ptr;

    // - ERROR -
    if (divider == 0.0)
    {
      exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    result /= divider;
  }
  break;

  /* - ERROR - */
  default:
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_slash_equal#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  BIC_SIMPLE_SET_DST_AND_RES(c_bi_class_float,result);

  return true;
}/*}}}*/

bool bic_float_operator_binary_double_ampersand(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FLOAT_BINARY_OPS_CHAR_INTEGER_FLOAT_RESULT_INTEGER(&&,"operator_binary_double_ampersand#1");

  return true;
}/*}}}*/

bool bic_float_operator_binary_double_pipe(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FLOAT_BINARY_OPS_CHAR_INTEGER_FLOAT_RESULT_INTEGER(||,"operator_binary_double_pipe#1");

  return true;
}/*}}}*/

bool bic_float_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_FLOAT_COMPARE_WITH_TYPE_BOOL();

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_float_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_FLOAT_COMPARE_WITH_TYPE_BOOL();
  result = !result;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_float_operator_binary_rs_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FLOAT_BINARY_OPS_CHAR_INTEGER_FLOAT_RESULT_INTEGER(>,"operator_binary_rs_br#1");

  return true;
}/*}}}*/

bool bic_float_operator_binary_ls_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FLOAT_BINARY_OPS_CHAR_INTEGER_FLOAT_RESULT_INTEGER(<,"operator_binary_ls_br#1");

  return true;
}/*}}}*/

bool bic_float_operator_binary_rs_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FLOAT_BINARY_OPS_CHAR_INTEGER_FLOAT_RESULT_INTEGER(>=,"operator_binary_rs_br_equal#1");

  return true;
}/*}}}*/

bool bic_float_operator_binary_ls_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FLOAT_BINARY_OPS_CHAR_INTEGER_FLOAT_RESULT_INTEGER(<=,"operator_binary_ls_br_equal#1");

  return true;
}/*}}}*/

bool bic_float_operator_binary_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FLOAT_BINARY_OPS_CHAR_INTEGER_FLOAT(+,"operator_binary_plus#1");

  return true;
}/*}}}*/

bool bic_float_operator_binary_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FLOAT_BINARY_OPS_CHAR_INTEGER_FLOAT(-,"operator_binary_minus#1");

  return true;
}/*}}}*/

bool bic_float_operator_binary_asterisk(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FLOAT_BINARY_OPS_CHAR_INTEGER_FLOAT(*,"operator_binary_asterisk#1");

  return true;
}/*}}}*/

bool bic_float_operator_binary_slash(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  double result;

  switch (src_0_location->v_type)
  {
  case c_bi_class_char:
  {
    char divider = (char)src_0_location->v_data_ptr;

    // - ERROR -
    if (divider == 0)
    {
      exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    result = (double)dst_location->v_data_ptr / divider;
  }
  break;
  case c_bi_class_integer:
  {
    long long int divider = (long long int)src_0_location->v_data_ptr;

    // - ERROR -
    if (divider == 0)
    {
      exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    result = (double)dst_location->v_data_ptr / divider;
  }
  break;
  case c_bi_class_float:
  {
    double divider = (double)src_0_location->v_data_ptr;

    // - ERROR -
    if (divider == 0)
    {
      exception_s::throw_exception(it,c_error_DIVISION_BY_ZERO,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    result = (double)dst_location->v_data_ptr / divider;
  }
  break;

  /* - ERROR - */
  default:
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("operator_binary_slash#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_float,result);

  return true;
}/*}}}*/

bool bic_float_operator_unary_post_double_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FLOAT_POST_UNARY(+1);

  return true;
}/*}}}*/

bool bic_float_operator_unary_post_double_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FLOAT_POST_UNARY(-1);

  return true;
}/*}}}*/

bool bic_float_operator_unary_pre_double_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FLOAT_PRE_UNARY(+1);

  return true;
}/*}}}*/

bool bic_float_operator_unary_pre_double_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FLOAT_PRE_UNARY(-1);

  return true;
}/*}}}*/

bool bic_float_operator_unary_pre_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FLOAT_PRE_UNARY_TMP_RESULT(+);

  return true;
}/*}}}*/

bool bic_float_operator_unary_pre_minus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FLOAT_PRE_UNARY_TMP_RESULT(-);

  return true;
}/*}}}*/

bool bic_float_operator_unary_pre_exclamation(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ! (double)dst_location->v_data_ptr;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_float_method_Float_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  return true;
}/*}}}*/

bool bic_float_method_Float_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  switch (src_0_location->v_type)
  {
  case c_bi_class_char:
    dst_location->v_data_ptr = (double)(char)src_0_location->v_data_ptr;
    break;
  case c_bi_class_integer:
    dst_location->v_data_ptr = (double)(long long int)src_0_location->v_data_ptr;
    break;
  case c_bi_class_float:
    dst_location->v_data_ptr = (double)src_0_location->v_data_ptr;
    break;
  case c_bi_class_string:
  {
    string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

    char *end_ptr = nullptr;
    dst_location->v_data_ptr = (double)strtod(string_ptr->data,&end_ptr);

    if (string_ptr->size <= 1 || (string_ptr->data + string_ptr->size - 1) != end_ptr)
    {
      exception_s::throw_exception(it,c_error_FLOAT_CONVERT_INVALID_STRING,operands[c_source_pos_idx],src_0_location);
      return false;
    }
  }
  break;

  // - ERROR -
  default:
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Float#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  return true;
}/*}}}*/

bool bic_float_method_sin_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FLOAT_FUNCTION_UNARY(sin);

  return true;
}/*}}}*/

bool bic_float_method_cos_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FLOAT_FUNCTION_UNARY(cos);

  return true;
}/*}}}*/

bool bic_float_method_tan_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FLOAT_FUNCTION_UNARY(tan);

  return true;
}/*}}}*/

bool bic_float_method_asin_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FLOAT_FUNCTION_UNARY(asin);

  return true;
}/*}}}*/

bool bic_float_method_acos_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FLOAT_FUNCTION_UNARY(acos);

  return true;
}/*}}}*/

bool bic_float_method_atan_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FLOAT_FUNCTION_UNARY(atan);

  return true;
}/*}}}*/

bool bic_float_method_exp_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FLOAT_FUNCTION_UNARY(exp);

  return true;
}/*}}}*/

bool bic_float_method_log_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FLOAT_FUNCTION_UNARY(log);

  return true;
}/*}}}*/

bool bic_float_method_pow_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FLOAT_FUNCTION_BINARY_OPS_CHAR_INTEGER_FLOAT(pow,"pow#1");

  return true;
}/*}}}*/

bool bic_float_method_sqrt_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FLOAT_FUNCTION_UNARY(sqrt);

  return true;
}/*}}}*/

bool bic_float_method_cbrt_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FLOAT_FUNCTION_UNARY(cbrt);

  return true;
}/*}}}*/

bool bic_float_method_hypot_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FLOAT_FUNCTION_BINARY_OPS_CHAR_INTEGER_FLOAT(hypot,"hypot#1");

  return true;
}/*}}}*/

bool bic_float_method_classify_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = fpclassify((double)dst_location->v_data_ptr);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_float_method_isnan_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = isnan((double)dst_location->v_data_ptr);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_float_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  if (src_0_location->v_type == c_bi_class_float)
  {
    double first = (double)dst_location->v_data_ptr;
    double second = (double)src_0_location->v_data_ptr;

    result = first < second ? -1 : (first > second ? 1 : 0);
  }
  else
  {
    result = c_bi_class_float < src_0_location->v_type ? -1 : 1;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_float_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING(
    string_ptr->setf("%f",(double)dst_location->v_data_ptr)
  );

  return true;
}/*}}}*/

bool bic_float_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - print value to standard output -
  printf("%f",(double)dst_location->v_data_ptr);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

// - class STRING -
built_in_class_s string_class =
{/*{{{*/
  "String",
  c_modifier_public | c_modifier_final,
  28, string_methods,
  0, string_variables,
  bic_string_consts,
  bic_string_init,
  bic_string_clear,
  bic_string_compare,
  bic_string_length,
  bic_string_item,
  bic_string_first_idx,
  bic_string_next_idx,
  nullptr,
  bic_string_from_slice,
  bic_string_pack,
  bic_string_unpack,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s string_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_string_operator_binary_equal
  },
  {
    "operator_binary_plus_equal#1",
    c_modifier_public | c_modifier_final,
    bic_string_operator_binary_plus_equal
  },
  {
    "operator_binary_asterisk_equal#1",
    c_modifier_public | c_modifier_final,
    bic_string_operator_binary_asterisk_equal
  },
  {
    "operator_binary_double_equal#1",
    c_modifier_public | c_modifier_final,
    bic_string_operator_binary_double_equal
  },
  {
    "operator_binary_exclamation_equal#1",
    c_modifier_public | c_modifier_final,
    bic_string_operator_binary_exclamation_equal
  },
  {
    "operator_binary_plus#1",
    c_modifier_public | c_modifier_final,
    bic_string_operator_binary_plus
  },
  {
    "operator_binary_asterisk#1",
    c_modifier_public | c_modifier_final,
    bic_string_operator_binary_asterisk
  },
  {
    "operator_binary_percent#1",
    c_modifier_public | c_modifier_final,
    bic_string_operator_binary_percent
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_string_operator_binary_le_br_re_br
  },
  {
    "String#0",
    c_modifier_public | c_modifier_final,
    bic_string_method_String_0
  },
  {
    "String#1",
    c_modifier_public | c_modifier_final,
    bic_string_method_String_1
  },
  {
    "create#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_string_method_create_1
  },
  {
    "split#1",
    c_modifier_public | c_modifier_final,
    bic_string_method_split_1
  },
  {
    "join#1",
    c_modifier_public | c_modifier_final,
    bic_string_method_join_1
  },
  {
    "head#1",
    c_modifier_public | c_modifier_final,
    bic_string_method_head_1
  },
  {
    "tail#1",
    c_modifier_public | c_modifier_final,
    bic_string_method_tail_1
  },
  {
    "range#2",
    c_modifier_public | c_modifier_final,
    bic_string_method_range_2
  },
  {
    "get_idx#1",
    c_modifier_public | c_modifier_final,
    bic_string_method_get_idx_1
  },
  {
    "get_idxs#1",
    c_modifier_public | c_modifier_final,
    bic_string_method_get_idxs_1
  },
  {
    "replace#2",
    c_modifier_public | c_modifier_final,
    bic_string_method_replace_2
  },
  {
    "contain#1",
    c_modifier_public | c_modifier_final,
    bic_string_method_contain_1
  },
  {
    "compare#1",
    c_modifier_public | c_modifier_final,
    bic_string_method_compare_1
  },
  {
    "item#1",
    c_modifier_public | c_modifier_final,
    bic_string_method_item_1
  },
  {
    "first_idx#0",
    c_modifier_public | c_modifier_final,
    bic_string_method_first_idx_0
  },
  {
    "next_idx#1",
    c_modifier_public | c_modifier_final,
    bic_string_method_next_idx_1
  },
  {
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_string_method_length_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_string_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_string_method_print_0
  },
};/*}}}*/

built_in_variable_s string_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_STRING_CHECK_INDEX() \
  /*{{{*/\
  string_s *string_ptr = (string_s *)dst_location->v_data_ptr;\
\
  /* - ERROR - */\
  if (index < 0 || index >= (string_ptr->size - 1)) {\
    exception_s *new_exception = exception_s::throw_exception(it,c_error_STRING_INDEX_EXCEEDS_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(index);\
\
    return false;\
  }\
  /*}}}*/

#define BIC_STRING_ITEM(NAME) \
  {/*{{{*/\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
    location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
    long long int index;\
\
    /* - ERROR - */\
    if (!it.retrieve_integer(src_0_location,index))\
    {\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
\
      return false;\
    }\
\
    BIC_STRING_CHECK_INDEX();\
\
    char result = string_ptr->data[index];\
\
    BIC_SIMPLE_SET_RES(c_bi_class_char,result);\
  }/*}}}*/

#define BIC_STRING_OPERATOR_BINARY_PLUS(NAME) \
  /*{{{*/\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
  /* - ERROR - */\
  if (src_0_location->v_type != c_bi_class_string)\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
    new_exception->params.push(1);\
    new_exception->params.push(src_0_location->v_type);\
\
    return false;\
  }\
\
  string_s *first_ptr = (string_s *)dst_location->v_data_ptr;\
  string_s *second_ptr = (string_s *)src_0_location->v_data_ptr;\
\
  unsigned f_length = first_ptr->size - 1;\
  unsigned s_length = second_ptr->size - 1;\
\
  /* - create result string - */\
  string_s *result_ptr = it.get_new_string_ptr();\
  result_ptr->create(f_length + s_length);\
\
  /* - construct result string - */\
  memcpy(result_ptr->data,first_ptr->data,f_length);\
  memcpy(result_ptr->data + f_length,second_ptr->data,s_length);\
  /*}}}*/

#define BIC_STRING_OPERATOR_BINARY_ASTERISK(NAME) \
/*{{{*/\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
  long long int mult;\
\
  /* - ERROR - */\
  if (!it.retrieve_integer(src_0_location,mult))\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
    new_exception->params.push(1);\
    new_exception->params.push(src_0_location->v_type);\
\
    return false;\
  }\
\
  /* - retrieve source string - */\
  string_s *source_ptr = (string_s *)dst_location->v_data_ptr;\
\
  string_s *result_ptr = it.get_new_string_ptr();\
\
  if (mult >= 0)\
  {\
    result_ptr->mult_char_ptr(source_ptr->size - 1,source_ptr->data,mult);\
  }\
/*}}}*/

void bic_string_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_string_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (string_s *)it.get_new_string_ptr();
}/*}}}*/

void bic_string_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  string_s *string_ptr = (string_s *)location_ptr->v_data_ptr;
  string_ptr->clear();
  cfree(string_ptr);
}/*}}}*/

int bic_string_compare(location_s *first_loc,location_s *second_loc)
{/*{{{*/
  string_s *first = (string_s *)first_loc->v_data_ptr;
  string_s *second = (string_s *)second_loc->v_data_ptr;

  if (first->size < second->size) { return -1; }
  if (first->size > second->size) { return 1; }
  return memcmp(first->data,second->data,first->size - 1);
}/*}}}*/

unsigned bic_string_length(location_s *location_ptr)
{/*{{{*/
  string_s *string_ptr = (string_s *)location_ptr->v_data_ptr;
  return string_ptr->size - 1;
}/*}}}*/

location_s *bic_string_item(interpreter_thread_s &it,location_s *location_ptr,unsigned index)
{/*{{{*/
  string_s *string_ptr = (string_s *)location_ptr->v_data_ptr;

  // FIXME TODO check index ...
  cassert(index < (string_ptr->size - 1));

  char result = string_ptr->data[index];
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_char,result);

  return new_location;
}/*}}}*/

unsigned bic_string_first_idx(location_s *location_ptr)
{/*{{{*/
  string_s *string_ptr = (string_s *)location_ptr->v_data_ptr;
  return string_ptr->size > 1 ? 0 : c_idx_not_exist;
}/*}}}*/

unsigned bic_string_next_idx(location_s *location_ptr,unsigned index)
{/*{{{*/
  string_s *string_ptr = (string_s *)location_ptr->v_data_ptr;
  unsigned length = string_ptr->size - 1;

  // FIXME TODO check index ...
  cassert(index < length);

  return (index + 1 < length) ? index + 1 : c_idx_not_exist;
}/*}}}*/

location_s *bic_string_from_slice(interpreter_thread_s &it,location_s *location_ptr,pointer_array_s &slice_array)
{/*{{{*/
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->create(slice_array.used);

  if (slice_array.used != 0)
  {
    pointer *l_ptr = slice_array.data;
    pointer *l_ptr_end = l_ptr + slice_array.used;
    char *s_ptr = string_ptr->data;
    do
    {
      *s_ptr = (char)((location_s *)*l_ptr)->v_data_ptr;
    }
    while(++s_ptr,++l_ptr < l_ptr_end);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);

  return new_location;
}/*}}}*/

bool bic_string_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack)
{/*{{{*/
  string_s *string_ptr = (string_s *)location_ptr->v_data_ptr;

  unsigned length = string_ptr->size - 1;
  stream.append(length,(const char *)string_ptr->data);
  stream.append(sizeof(unsigned),(const char *)&length);

  return true;
}/*}}}*/

bool bic_string_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos)
{/*{{{*/
  string_s *string_ptr = it.get_new_string_ptr();

  location_ptr->v_data_ptr = (string_s *)string_ptr;

  if (stream.used < sizeof(unsigned))
  {
    return false;
  }

  unsigned length;
  stream.from_end(sizeof(unsigned),(char *)&length,order_bytes);

  if (stream.used < length)
  {
    return false;
  }

  string_ptr->create(length);
  stream.from_end(length,string_ptr->data,false);

  return true;
}/*}}}*/

bool bic_string_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_string_operator_binary_plus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_STRING_OPERATOR_BINARY_PLUS("operator_binary_plus_equal#1");

  BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_string,result_ptr,2);

  BIC_SET_DESTINATION(new_location);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_string_operator_binary_asterisk_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_STRING_OPERATOR_BINARY_ASTERISK("operator_binary_asterisk_equal#1");

  BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_string,result_ptr,2);

  BIC_SET_DESTINATION(new_location);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_string_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  if (src_0_location->v_type == c_bi_class_string)
  {
    result = *((string_s *)dst_location->v_data_ptr) == *((string_s *)src_0_location->v_data_ptr);
  }
  else
  {
    result = 0;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_string_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  if (src_0_location->v_type == c_bi_class_string)
  {
    result = !(*((string_s *)dst_location->v_data_ptr) == *((string_s *)src_0_location->v_data_ptr));
  }
  else
  {
    result = 1;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_string_operator_binary_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_STRING_OPERATOR_BINARY_PLUS("operator_binary_plus#1");

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,result_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_string_operator_binary_asterisk(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_STRING_OPERATOR_BINARY_ASTERISK("operator_binary_asterisk#1");

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,result_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_string_operator_binary_percent(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_array_s *array_ptr;
  pointer_array_s dummy_array;

  if (src_0_location->v_type != c_bi_class_array)
  {
    dummy_array.data = (pointer *)&src_0_location;
    dummy_array.used = 1;
    dummy_array.size = 1;

    array_ptr = &dummy_array;
  }
  else
  {
    // - retrieve argument array pointer -
    array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;
  }

  // - retrieve string pointer -
  string_s *format_string_ptr = (string_s *)dst_location->v_data_ptr;

  // - result formatted character buffer -
  bc_array_s buffer;
  buffer.init();

  // - format string buffer -
  bc_array_s format_buffer;
  format_buffer.init();

#define SF_CLEAR_DATA() \
  format_buffer.clear();\
  buffer.clear()

  // - index of element in argument array -
  unsigned element_idx = 0;

  // - process format string -
  if (format_string_ptr->size > 1)
  {
    char *f_ptr = format_string_ptr->data;
    char *f_ptr_end = f_ptr + format_string_ptr->size - 1;
    do
    {
      // - if format start character was found -
      if (*f_ptr == '%')
      {
        bool flags_done = false;
        bool dot_done = false;
        bool minus_flag = false;

        int width = 0;
        int precision = -1;

        format_buffer.used = 0;
        format_buffer.push('%');

        char *fe_ptr = f_ptr + 1;
        char *old_fe_ptr;

        unsigned ret_term = c_idx_not_exist;
        do
        {
          old_fe_ptr = fe_ptr;
          ret_term = sf_terminal_recognize(&fe_ptr);

          // - process retrieved terminal -
          switch (ret_term)
          {
          case SF_TERM_MINUS:
          {/*{{{*/

            // - ERROR -
            if (flags_done)
            {
              SF_CLEAR_DATA();

              exception_s::throw_exception(it,c_error_STRING_FORMAT_WRONG_FORMAT_SPECIFIER,operands[c_source_pos_idx],(location_s *)it.blank_location);
              return false;
            }

            minus_flag = true;

            // - append minus flag to format buffer -
            format_buffer.push('-');
          }/*}}}*/
          break;

          case SF_TERM_FLAGS:
          {/*{{{*/

            // - ERROR -
            if (flags_done)
            {
              SF_CLEAR_DATA();

              exception_s::throw_exception(it,c_error_STRING_FORMAT_WRONG_FORMAT_SPECIFIER,operands[c_source_pos_idx],(location_s *)it.blank_location);
              return false;
            }

            // - append flags to format buffer -
            format_buffer.append(fe_ptr - old_fe_ptr,old_fe_ptr);
          }/*}}}*/
          break;

          case SF_TERM_NUMBER:
          {/*{{{*/
            if (!dot_done && *old_fe_ptr == '0')
            {
              // - insert zero flag to format buffer -
              format_buffer.push('0');
            }

            long long int value = strtoll(old_fe_ptr,nullptr,10);
            dot_done ? precision = value : width = value;

            flags_done = true;
          }/*}}}*/
          break;

          case SF_TERM_PARAMETER:
          {/*{{{*/
            if (array_ptr->used <= element_idx)
            {
              SF_CLEAR_DATA();

              exception_s::throw_exception(it,c_error_STRING_FORMAT_NOT_ENOUGH_ARGUMENTS,operands[c_source_pos_idx],(location_s *)it.blank_location);
              return false;
            }

            // - retrieve argument -
            location_s *element_location = it.get_location_value(array_ptr->data[element_idx++]);
            if (element_location->v_type != c_bi_class_integer)
            {
              SF_CLEAR_DATA();

              exception_s *new_exception = exception_s::throw_exception(it,c_error_STRING_FORMAT_WRONG_ARGUMENT_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
              new_exception->params.push(element_idx);
              new_exception->params.push(c_bi_class_integer);
              new_exception->params.push(element_location->v_type);

              return false;
            }

            long long int value = (long long int)element_location->v_data_ptr;
            dot_done ? precision = value : width = value;

            flags_done = true;
          }/*}}}*/
          break;

          case SF_TERM_DOT:
          {/*{{{*/

            // - ERROR -
            if (dot_done)
            {
              SF_CLEAR_DATA();

              exception_s::throw_exception(it,c_error_STRING_FORMAT_WRONG_FORMAT_SPECIFIER,operands[c_source_pos_idx],(location_s *)it.blank_location);
              return false;
            }

            dot_done = true;
            flags_done = true;
          }/*}}}*/
          break;

          case SF_TERM_PERCENT:
          {/*{{{*/

            // - push percent symbol to result string -
            buffer.push('%');
            ret_term = c_idx_not_exist;
          }/*}}}*/
          break;

          case SF_TERM_CHARACTER:
          {/*{{{*/
            format_buffer.append(5,"*.*?");
            format_buffer.data[format_buffer.used - 2] = *old_fe_ptr;

            if (array_ptr->used <= element_idx)
            {
              SF_CLEAR_DATA();

              exception_s::throw_exception(it,c_error_STRING_FORMAT_NOT_ENOUGH_ARGUMENTS,operands[c_source_pos_idx],(location_s *)it.blank_location);
              return false;
            }

            // - retrieve argument to format -
            location_s *element_location = it.get_location_value(array_ptr->data[element_idx++]);
            if (element_location->v_type != c_bi_class_char)
            {
              SF_CLEAR_DATA();

              exception_s *new_exception = exception_s::throw_exception(it,c_error_STRING_FORMAT_WRONG_ARGUMENT_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
              new_exception->params.push(element_idx);
              new_exception->params.push(c_bi_class_char);
              new_exception->params.push(element_location->v_type);

              return false;
            }

            char argument = (char)element_location->v_data_ptr;

            unsigned old_used = buffer.used;

            int max_length = c_number_format_size;
            if (width >= max_length)
            {
              max_length = width + 1;
            }

            buffer.push_blanks(max_length);

            int char_cnt = snprintf(buffer.data + old_used,max_length,format_buffer.data,width,precision,argument);
            if (char_cnt < 0 || char_cnt >= max_length)
            {
              SF_CLEAR_DATA();

              exception_s *new_exception = exception_s::throw_exception(it,c_error_STRING_FORMAT_ARGUMENT_FORMAT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
              new_exception->params.push(element_idx);

              return false;
            }

            buffer.used = old_used + char_cnt;
            ret_term = c_idx_not_exist;
          }/*}}}*/
          break;

          case SF_TERM_INTEGER:
          {/*{{{*/
            format_buffer.append(3 + HOST_LL_FORMAT_LENGTH + 2,"*.*" HOST_LL_FORMAT "?");
            format_buffer.data[format_buffer.used - 2] = *old_fe_ptr;

            if (array_ptr->used <= element_idx)
            {
              SF_CLEAR_DATA();

              exception_s::throw_exception(it,c_error_STRING_FORMAT_NOT_ENOUGH_ARGUMENTS,operands[c_source_pos_idx],(location_s *)it.blank_location);
              return false;
            }

            // - retrieve argument to format -
            location_s *element_location = it.get_location_value(array_ptr->data[element_idx++]);
            if (element_location->v_type != c_bi_class_integer)
            {
              SF_CLEAR_DATA();

              exception_s *new_exception = exception_s::throw_exception(it,c_error_STRING_FORMAT_WRONG_ARGUMENT_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
              new_exception->params.push(element_idx);
              new_exception->params.push(c_bi_class_integer);
              new_exception->params.push(element_location->v_type);

              return false;
            }

            long long int argument = (long long int)element_location->v_data_ptr;

            unsigned old_used = buffer.used;

            int max_length = c_number_format_size;
            if (width >= max_length) { max_length = width + 1; }
            if (precision >= max_length) { max_length = precision + 1; }

            buffer.push_blanks(max_length);

            int char_cnt = snprintf(buffer.data + old_used,max_length,format_buffer.data,width,precision,argument);
            if (char_cnt < 0 || char_cnt >= max_length)
            {
              SF_CLEAR_DATA();

              exception_s *new_exception = exception_s::throw_exception(it,c_error_STRING_FORMAT_ARGUMENT_FORMAT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
              new_exception->params.push(element_idx);

              return false;
            }

            buffer.used = old_used + char_cnt;
            ret_term = c_idx_not_exist;
          }/*}}}*/
          break;

          case SF_TERM_FLOAT:
          {/*{{{*/
            format_buffer.append(5,"*.*?");
            format_buffer.data[format_buffer.used - 2] = *old_fe_ptr;

            if (array_ptr->used <= element_idx)
            {
              SF_CLEAR_DATA();

              exception_s::throw_exception(it,c_error_STRING_FORMAT_NOT_ENOUGH_ARGUMENTS,operands[c_source_pos_idx],(location_s *)it.blank_location);
              return false;
            }

            // - retrieve argument to format -
            location_s *element_location = it.get_location_value(array_ptr->data[element_idx++]);
            if (element_location->v_type != c_bi_class_float)
            {
              SF_CLEAR_DATA();

              exception_s *new_exception = exception_s::throw_exception(it,c_error_STRING_FORMAT_WRONG_ARGUMENT_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
              new_exception->params.push(element_idx);
              new_exception->params.push(c_bi_class_float);
              new_exception->params.push(element_location->v_type);

              return false;
            }

            double argument = (double)element_location->v_data_ptr;

            unsigned old_used = buffer.used;

            int max_length = c_number_format_size + 1 + precision;
            if (width >= max_length)
            {
              max_length = width + 1;
            }

            buffer.push_blanks(max_length);

            int char_cnt = snprintf(buffer.data + old_used,max_length,format_buffer.data,width,precision,argument);
            if (char_cnt < 0 || char_cnt >= max_length)
            {
              SF_CLEAR_DATA();

              exception_s *new_exception = exception_s::throw_exception(it,c_error_STRING_FORMAT_ARGUMENT_FORMAT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
              new_exception->params.push(element_idx);

              return false;
            }

            buffer.used = old_used + char_cnt;
            ret_term = c_idx_not_exist;
          }/*}}}*/
          break;

          case SF_TERM_STRING:
          {/*{{{*/
            if (array_ptr->used <= element_idx)
            {
              SF_CLEAR_DATA();

              exception_s::throw_exception(it,c_error_STRING_FORMAT_NOT_ENOUGH_ARGUMENTS,operands[c_source_pos_idx],(location_s *)it.blank_location);
              return false;
            }

            // - retrieve argument to format -
            location_s *element_location = it.get_location_value(array_ptr->data[element_idx++]);
            if (element_location->v_type != c_bi_class_string)
            {
              SF_CLEAR_DATA();

              exception_s *new_exception = exception_s::throw_exception(it,c_error_STRING_FORMAT_WRONG_ARGUMENT_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
              new_exception->params.push(element_idx);
              new_exception->params.push(c_bi_class_string);
              new_exception->params.push(element_location->v_type);

              return false;
            }

            string_s *argument = (string_s *)element_location->v_data_ptr;

            unsigned old_used = buffer.used;

            // - retrieve maximal count of characters -
            int max_length = argument->size;
            if (width >= max_length)
            {
              max_length = width + 1;
            }

            buffer.push_blanks(max_length);

            // - compute length of formatted string part -
            int string_len = argument->size - 1;
            string_len = precision != -1 ? (precision < string_len ? precision : string_len) : string_len;

            // - compute count of space characters -
            int fill_cnt = width != 0 ? (width > string_len ? width - string_len : 0) : 0;

            // - format data to target string -
            if (minus_flag)
            {
              memcpy(buffer.data + old_used,argument->data,string_len);
              memset(buffer.data + old_used + string_len,' ',fill_cnt);
            }
            else
            {
              memset(buffer.data + old_used,' ',fill_cnt);
              memcpy(buffer.data + old_used + fill_cnt,argument->data,string_len);
            }

            buffer.used = old_used + fill_cnt + string_len;
            ret_term = c_idx_not_exist;
          }/*}}}*/
          break;

          // - ERROR -
          default:
          {/*{{{*/
            SF_CLEAR_DATA();

            exception_s::throw_exception(it,c_error_STRING_FORMAT_WRONG_FORMAT_SPECIFIER,operands[c_source_pos_idx],(location_s *)it.blank_location);
            return false;
          }/*}}}*/
          }
        }
        while(ret_term != c_idx_not_exist);

        f_ptr = fe_ptr;
      }
      else
      {
        buffer.push(*f_ptr++);
      }

    }
    while(f_ptr < f_ptr_end);
  }

  format_buffer.clear();

  // - test if all parameters were used -
  if (element_idx != array_ptr->used)
  {
    buffer.clear();

    exception_s::throw_exception(it,c_error_STRING_FORMAT_NOT_ALL_ARGUMENTS_CONVERTED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - push terminating character to buffer -
  buffer.push('\0');

  // - create result string -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->data = buffer.data;
  string_ptr->size = buffer.used;

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_string_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_STRING_ITEM("operator_binary_le_br_re_br#1");

  return true;
}/*}}}*/

bool bic_string_method_String_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  return true;
}/*}}}*/

bool bic_string_method_String_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  string_s *string_ptr = (string_s *)dst_location->v_data_ptr;

  switch (src_0_location->v_type)
  {

  case c_bi_class_char:
  {
    char value = (char)src_0_location->v_data_ptr;
    string_ptr->set(1,&value);
  }
  break;

  case c_bi_class_integer:
  {
    string_ptr->create(c_number_format_size);

    int char_cnt = snprintf(string_ptr->data,c_number_format_size,"%" HOST_LL_FORMAT "d",(long long int)src_0_location->v_data_ptr);
    if (char_cnt < 0 || char_cnt >= c_number_format_size)
    {
      exception_s *new_exception = exception_s::throw_exception(it,c_error_STRING_CONVERT_FROM_INTEGER,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(0);

      return false;
    }

    string_ptr->data[char_cnt] = '\0';
    string_ptr->size = char_cnt + 1;
  }
  break;

  case c_bi_class_float:
  {
    string_ptr->create(c_number_format_size);

    int char_cnt = snprintf(string_ptr->data,c_number_format_size,"%f",(double)src_0_location->v_data_ptr);
    if (char_cnt < 0 || char_cnt >= c_number_format_size)
    {
      exception_s *new_exception = exception_s::throw_exception(it,c_error_STRING_CONVERT_FROM_FLOAT,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(0);

      return false;
    }

    string_ptr->data[char_cnt] = '\0';
    string_ptr->size = char_cnt + 1;
  }
  break;

  case c_bi_class_string:
    *string_ptr = *((string_s *)src_0_location->v_data_ptr);
    break;

    // - ERROR -
  default:
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("String#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  return true;
}/*}}}*/

bool bic_string_method_create_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int length;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,length))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_string,"create#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->create(length);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_string_method_split_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("split#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve string pointers -
  string_s *string_ptr = (string_s *)dst_location->v_data_ptr;
  string_s *substr_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create new array pointer -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  // - split string to array -
  {
    unsigned idx = 0;
    do
    {
      unsigned old_idx = idx;
      idx = string_ptr->get_idx(idx,substr_ptr->size - 1,substr_ptr->data);

      if (idx == c_idx_not_exist)
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

      // - jump over substring -
      idx += substr_ptr->size - 1;
    }
    while(true);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_string_method_join_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - retrieve string pointers -
  string_s *del_string_ptr = (string_s *)dst_location->v_data_ptr;

  // - retrieve iterable type -
  unsigned iter_type = it.get_iterable_type(src_0_location);

  // - ERROR -
  if (iter_type == c_idx_not_exist)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_OBJECT_OF_CLASS_IS_NOT_ITERABLE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_array_s strings;
  strings.init();

  unsigned strings_size = 0;

#define BIC_STRING_METHOD_JOIN_1_BODY() \
  {/*{{{*/\
\
    /* - push new string to strings - */\
    strings.push_blank();\
    string_s *s_ptr = &strings.last();\
\
    /* - convert item to string - */\
    BIC_CALL_TO_STRING(it,item_location,operands[c_source_pos_idx],\
                       strings.clear();\
                       return false;\
                      );\
\
    /* - release item location - */\
    it.release_location_ptr(item_location);\
  }/*}}}*/

  if (iter_type == c_iter_first_idx_next_idx_item)
  {
    long long int index;
    location_s *item_location;

    // - retrieve first index -
    BIC_CALL_FIRST_IDX(it,src_0_location,index,operands[c_source_pos_idx],
                       strings.clear();
                       return false;
                      );

    while (index != c_idx_not_exist)
    {
      // - retrieve item location -
      BIC_CALL_ITEM(it,src_0_location,index,item_location,operands[c_source_pos_idx],
                    strings.clear();
                    return false;
                   );

      BIC_STRING_METHOD_JOIN_1_BODY();

      // - retrieve next index -
      BIC_CALL_NEXT_IDX(it,src_0_location,index,index,operands[c_source_pos_idx],
                        strings.clear();
                        return false;
                       );
    }
  }
  else if (iter_type == c_iter_next_item)
  {
    location_s *item_location;

    do
    {
      // - retrieve next item location -
      BIC_CALL_NEXT_ITEM(it,src_0_location,item_location,operands[c_source_pos_idx],
                         strings.clear();
                         return false;
                        );

      if (it.get_location_value(item_location)->v_type == c_bi_class_blank)
      {
        // - release item location -
        it.release_location_ptr(item_location);

        break;
      }

      BIC_STRING_METHOD_JOIN_1_BODY();

    }
    while(true);
  }
  else
  {
    cassert(0);
  }

  string_s *string_ptr = it.get_new_string_ptr();

  BIC_CONT_TO_STRING_1_CONSTRUCT();

  // - release string array -
  strings.clear();

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_string_method_head_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int original_length;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,original_length))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("head#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)dst_location->v_data_ptr;
  unsigned string_length = string_ptr->size - 1;

  // - adjust length parameter -
  long long int length = original_length;

  if (length < 0)
  {
    length = string_length + length;
  }

  // - ERROR -
  if (length < 0 || length > string_length)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_STRING_INDEX_EXCEEDS_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(original_length);

    return false;
  }

  string_s *new_string_ptr = it.get_new_string_ptr();
  new_string_ptr->set(length,string_ptr->data);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,new_string_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_string_method_tail_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int original_length;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,original_length))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("tail#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)dst_location->v_data_ptr;
  unsigned string_length = string_ptr->size - 1;

  // - adjust length parameter -
  long long int length = original_length;

  if (length < 0)
  {
    length = string_length + length;
  }

  // - ERROR -
  if (length < 0 || length > string_length)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_STRING_INDEX_EXCEEDS_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(original_length);

    return false;
  }

  string_s *new_string_ptr = it.get_new_string_ptr();
  new_string_ptr->set(length,string_ptr->data + (string_length - length));

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,new_string_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_string_method_range_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int original_first_index;
  long long int original_second_index;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,original_first_index) ||
      !it.retrieve_integer(src_1_location,original_second_index))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("range#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)dst_location->v_data_ptr;
  unsigned string_length = string_ptr->size - 1;

  // - adjust first_index parameter -
  long long int first_index = original_first_index;
  if (first_index < 0)
  {
    first_index = string_length + first_index;
  }

  // - adjust second_index parameter -
  long long int second_index = original_second_index;
  if (second_index < 0)
  {
    second_index = string_length + second_index;
  }

  // - ERROR -
  if (first_index > second_index ||
      first_index < 0 || first_index >= string_length ||
      second_index < 0 || second_index >= string_length)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_STRING_WRONG_RANGE_INDEXES,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(original_first_index);
    new_exception->params.push(original_second_index);

    return false;
  }

  string_s *new_string_ptr = it.get_new_string_ptr();
  new_string_ptr->set(second_index - first_index + 1,string_ptr->data + first_index);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,new_string_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_string_method_get_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("get_idx#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve string pointers -
  string_s *string_ptr = (string_s *)dst_location->v_data_ptr;
  string_s *substr_ptr = (string_s *)src_0_location->v_data_ptr;

  long long int idx = string_ptr->get_idx(0,substr_ptr->size - 1,substr_ptr->data);

  BIC_SET_RESULT_CONT_INDEX(idx);

  return true;
}/*}}}*/

bool bic_string_method_get_idxs_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("get_idxs#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve string pointers -
  string_s *string_ptr = (string_s *)dst_location->v_data_ptr;
  string_s *substr_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create new array pointer -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  // - find substring indexes in string -
  {
    unsigned idx = 0;
    do
    {
      idx = string_ptr->get_idx(idx,substr_ptr->size - 1,substr_ptr->data);
      if (idx == c_idx_not_exist)
      {
        break;
      }

      // - create new index integer location -
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,idx);

      // - insert integer location to pointer array -
      array_ptr->push((pointer)new_location);

      // - jump over substring -
      idx += substr_ptr->size - 1;

    }
    while(true);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_string_method_replace_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string ||
      src_1_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("replace#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  // - retrieve string pointers -
  string_s *string_ptr = (string_s *)dst_location->v_data_ptr;
  string_s *oldstr_ptr = (string_s *)src_0_location->v_data_ptr;
  string_s *newstr_ptr = (string_s *)src_1_location->v_data_ptr;

  // - create target buffer -
  bc_array_s buffer;
  buffer.init();

  // - replace old string by new string -
  {
    unsigned idx = 0;
    do
    {
      unsigned old_idx = idx;
      idx = string_ptr->get_idx(idx,oldstr_ptr->size - 1,oldstr_ptr->data);

      if (idx == c_idx_not_exist)
      {
        idx = string_ptr->size - 1;
      }

      // - append part of original string to buffer -
      buffer.append(idx - old_idx,string_ptr->data + old_idx);

      if (idx >= string_ptr->size - 1)
      {
        break;
      }

      // - append new string to buffer -
      buffer.append(newstr_ptr->size - 1,newstr_ptr->data);

      // - jump over substring -
      idx += oldstr_ptr->size - 1;
    }
    while(true);
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

bool bic_string_method_contain_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("contain#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve string pointers -
  string_s *string_ptr = (string_s *)dst_location->v_data_ptr;
  string_s *substr_ptr = (string_s *)src_0_location->v_data_ptr;

  unsigned idx = string_ptr->get_idx(0,substr_ptr->size - 1,substr_ptr->data);
  long long int result = idx != c_idx_not_exist;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_string_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  if (src_0_location->v_type == c_bi_class_string)
  {
    string_s *first = (string_s *)dst_location->v_data_ptr;
    string_s *second = (string_s *)src_0_location->v_data_ptr;

    if (first->size == second->size)
    {
      result = memcmp(first->data,second->data,first->size - 1);
    }
    else
    {
      result = (first->size < second->size) ? -1 : 1;
    }
  }
  else
  {
    result = c_bi_class_string < src_0_location->v_type ? -1 : 1;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_string_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_STRING_ITEM("item#1");

  return true;
}/*}}}*/

bool bic_string_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  string_s *string_ptr = (string_s *)dst_location->v_data_ptr;

  if (string_ptr->size > 1)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,0);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_string_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int index;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,index))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("next_idx#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  BIC_STRING_CHECK_INDEX();

  if (++index < string_ptr->size - 1)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,index);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_string_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((string_s *)dst_location->v_data_ptr)->size - 1;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_string_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  dst_location->v_reference_cnt.atomic_inc();

  BIC_SET_RESULT(dst_location);

  return true;
}/*}}}*/

bool bic_string_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - print value to standard output -
  ((string_s *)dst_location->v_data_ptr)->print();

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

// - class ARRAY -
built_in_class_s array_class =
{/*{{{*/
  "Array",
  c_modifier_public | c_modifier_final,
  29, array_methods,
  0, array_variables,
  bic_array_consts,
  bic_array_init,
  bic_array_clear,
  nullptr,
  bic_array_length,
  bic_array_item,
  bic_array_first_idx,
  bic_array_next_idx,
  nullptr,
  nullptr,
  bic_array_pack,
  bic_array_unpack,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s array_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_array_operator_binary_equal
  },
  {
    "operator_binary_plus_equal#1",
    c_modifier_public | c_modifier_final,
    bic_array_operator_binary_plus_equal
  },
  {
    "operator_binary_double_equal#1",
    c_modifier_public | c_modifier_final,
    bic_array_operator_binary_double_equal
  },
  {
    "operator_binary_exclamation_equal#1",
    c_modifier_public | c_modifier_final,
    bic_array_operator_binary_exclamation_equal
  },
  {
    "operator_binary_plus#1",
    c_modifier_public | c_modifier_final,
    bic_array_operator_binary_plus
  },
  {
    "operator_binary_ls_br_equal#1",
    c_modifier_public | c_modifier_final,
    bic_array_operator_binary_ls_br_equal
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_array_operator_binary_le_br_re_br
  },
  {
    "Array#0",
    c_modifier_public | c_modifier_final,
    bic_array_method_Array_0
  },
  {
    "Array#1",
    c_modifier_public | c_modifier_final,
    bic_array_method_Array_1
  },
  {
    "clear#0",
    c_modifier_public | c_modifier_final,
    bic_array_method_clear_0
  },
  {
    "resize#1",
    c_modifier_public | c_modifier_final,
    bic_array_method_resize_1
  },
  {
    "push#1",
    c_modifier_public | c_modifier_final,
    bic_array_method_push_1
  },
  {
    "push_ref#1",
    c_modifier_public | c_modifier_final,
    bic_array_method_push_ref_1
  },
  {
    "pop#0",
    c_modifier_public | c_modifier_final,
    bic_array_method_pop_0
  },
  {
    "last#0",
    c_modifier_public | c_modifier_final,
    bic_array_method_last_0
  },
  {
    "fill#1",
    c_modifier_public | c_modifier_final,
    bic_array_method_fill_1
  },
  {
    "get_idx#1",
    c_modifier_public | c_modifier_final,
    bic_array_method_get_idx_1
  },
  {
    "get_idxs#1",
    c_modifier_public | c_modifier_final,
    bic_array_method_get_idxs_1
  },
  {
    "contain#1",
    c_modifier_public | c_modifier_final,
    bic_array_method_contain_1
  },
  {
    "compare#1",
    c_modifier_public | c_modifier_final,
    bic_array_method_compare_1
  },
  {
    "item#1",
    c_modifier_public | c_modifier_final,
    bic_array_method_item_1
  },
  {
    "first_idx#0",
    c_modifier_public | c_modifier_final,
    bic_array_method_first_idx_0
  },
  {
    "last_idx#0",
    c_modifier_public | c_modifier_final,
    bic_array_method_last_idx_0
  },
  {
    "next_idx#1",
    c_modifier_public | c_modifier_final,
    bic_array_method_next_idx_1
  },
  {
    "prev_idx#1",
    c_modifier_public | c_modifier_final,
    bic_array_method_prev_idx_1
  },
  {
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_array_method_length_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_array_method_to_string_0
  },
  {
    "to_string#1",
    c_modifier_public | c_modifier_final,
    bic_array_method_to_string_1
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_array_method_print_0
  },
};/*}}}*/

built_in_variable_s array_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_ARRAY_COMPARE(FIRST_LOC_PTR,SECOND_LOC_PTR,SOURCE_POS) \
  {/*{{{*/\
    if ((SECOND_LOC_PTR)->v_type == c_bi_class_array) {\
      pointer_array_s *f_array_ptr = (pointer_array_s *)(FIRST_LOC_PTR)->v_data_ptr;\
      pointer_array_s *s_array_ptr = (pointer_array_s *)(SECOND_LOC_PTR)->v_data_ptr;\
\
      if (f_array_ptr->used != s_array_ptr->used)\
      {\
        result = f_array_ptr->used < s_array_ptr->used ? -1 : 1;\
      }\
      else {\
        result = 0;\
\
        if (f_array_ptr->used != 0)\
        {\
          pointer *f_ptr = f_array_ptr->data;\
          pointer *f_ptr_end = f_ptr + f_array_ptr->used;\
          pointer *s_ptr = s_array_ptr->data;\
\
          do {\
            BIC_CALL_COMPARE(it,*f_ptr,*s_ptr,SOURCE_POS,return false);\
\
            if (result != 0) {\
              break;\
            }\
          } while(++s_ptr,++f_ptr < f_ptr_end);\
        }\
      }\
    }\
    else {\
      result = c_bi_class_array < (SECOND_LOC_PTR)->v_type ? -1 : 1;\
    }\
  }/*}}}*/

#define BIC_ARRAY_APPEND_ARRAY(SRC_LOCATION,TARGET_PTR) \
  {/*{{{*/\
    pointer_array_s *source_ptr = (pointer_array_s *)SRC_LOCATION->v_data_ptr;\
\
    if (source_ptr->used != 0)\
    {\
      pointer *ptr = source_ptr->data;\
      pointer *ptr_end = ptr + source_ptr->used;\
\
      do\
      {\
        location_s *item_location = it.get_location_value(*ptr);\
        item_location->v_reference_cnt.atomic_inc();\
\
        /* - push item location to array - */\
        TARGET_PTR->push(item_location);\
      }\
      while(++ptr < ptr_end);\
    }\
  }/*}}}*/

#define BIC_ARRAY_APPEND_ITERABLE_BODY(TARGET_PTR) \
  {/*{{{*/\
    item_location->v_reference_cnt.atomic_inc();\
    it.release_location_ptr(item_reference);\
\
    /* - push item location to array - */\
    TARGET_PTR->push(item_location);\
  }/*}}}*/

#define BIC_ARRAY_APPEND_ITERABLE(SRC_LOCATION,TARGET_PTR) \
  {/*{{{*/\
\
    /* - retrieve iterable type - */\
    unsigned iter_type = it.get_iterable_type(SRC_LOCATION);\
\
    /* - ERROR - */\
    if (iter_type == c_idx_not_exist)\
    {\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_OBJECT_OF_CLASS_IS_NOT_ITERABLE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      new_exception->params.push(SRC_LOCATION->v_type);\
\
      return false;\
    }\
\
    if (iter_type == c_iter_first_idx_next_idx_item)\
    {\
      long long int index;\
      location_s *item_reference;\
      location_s *item_location;\
\
      /* - retrieve first index - */\
      BIC_CALL_FIRST_IDX(it,SRC_LOCATION,index,operands[c_source_pos_idx],return false;);\
\
      while (index != c_idx_not_exist)\
      {\
        /* - retrieve item location - */\
        BIC_CALL_ITEM(it,SRC_LOCATION,index,item_reference,operands[c_source_pos_idx],return false;);\
        item_location = it.get_location_value(item_reference);\
\
        BIC_ARRAY_APPEND_ITERABLE_BODY(TARGET_PTR);\
\
        /* - retrieve next index - */\
        BIC_CALL_NEXT_IDX(it,SRC_LOCATION,index,index,operands[c_source_pos_idx],return false;);\
      }\
    }\
    else if (iter_type == c_iter_next_item)\
    {\
      location_s *item_reference;\
      location_s *item_location;\
\
      do\
      {\
        /* - retrieve next item location - */\
        BIC_CALL_NEXT_ITEM(it,SRC_LOCATION,item_reference,operands[c_source_pos_idx],return false;);\
        item_location = it.get_location_value(item_reference);\
\
        if (item_location->v_type == c_bi_class_blank)\
        {\
          it.release_location_ptr(item_reference);\
          break;\
        }\
\
        BIC_ARRAY_APPEND_ITERABLE_BODY(TARGET_PTR);\
\
      }\
      while(true);\
    }\
    else\
    {\
      cassert(0);\
    }\
  }/*}}}*/

#define BIC_ARRAY_CHECK_INDEX() \
  /*{{{*/\
  pointer_array_s *array_ptr = (pointer_array_s *)dst_location->v_data_ptr;\
\
  /* - ERROR - */\
  if (index < 0 || index >= array_ptr->used) {\
    exception_s *new_exception = exception_s::throw_exception(it,c_error_ARRAY_INDEX_EXCEEDS_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(index);\
\
    return false;\
  }\
  /*}}}*/

#define BIC_ARRAY_ITEM(NAME) \
  {/*{{{*/\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
    location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
    long long int index;\
\
    /* - ERROR - */\
    if (!it.retrieve_integer(src_0_location,index))\
    {\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
\
      return false;\
    }\
\
    BIC_ARRAY_CHECK_INDEX();\
\
    pointer *element_location = &array_ptr->data[index];\
    location_s *new_ref_location = it.get_new_reference((location_s **)element_location);\
\
    BIC_SET_RESULT(new_ref_location);\
  }/*}}}*/

void bic_array_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_array_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (pointer_array_s *)it.get_new_array_ptr();
}/*}}}*/

void bic_array_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  pointer_array_s *array_ptr = (pointer_array_s *)location_ptr->v_data_ptr;

  if (array_ptr->used != 0)
  {
    pointer *l_ptr = array_ptr->data;
    pointer *l_ptr_end = l_ptr + array_ptr->used;

    do
    {
      it.release_location_ptr((location_s *)*l_ptr);
    }
    while(++l_ptr < l_ptr_end);
  }

  array_ptr->clear();
  cfree(array_ptr);
}/*}}}*/

unsigned bic_array_length(location_s *location_ptr)
{/*{{{*/
  pointer_array_s *array_ptr = (pointer_array_s *)location_ptr->v_data_ptr;
  return array_ptr->used;
}/*}}}*/

location_s *bic_array_item(interpreter_thread_s &it,location_s *location_ptr,unsigned index)
{/*{{{*/
  pointer_array_s *array_ptr = (pointer_array_s *)location_ptr->v_data_ptr;

  // FIXME TODO check index ...
  cassert(index < array_ptr->used);

  pointer *element_location = &array_ptr->data[index];
  return it.get_new_reference((location_s **)element_location);
}/*}}}*/

unsigned bic_array_first_idx(location_s *location_ptr)
{/*{{{*/
  pointer_array_s *array_ptr = (pointer_array_s *)location_ptr->v_data_ptr;
  return array_ptr->used != 0 ? 0 : c_idx_not_exist;
}/*}}}*/

unsigned bic_array_next_idx(location_s *location_ptr,unsigned index)
{/*{{{*/
  pointer_array_s *array_ptr = (pointer_array_s *)location_ptr->v_data_ptr;

  // FIXME TODO check index ...
  cassert(index < array_ptr->used);

  return (index + 1 < array_ptr->used) ? index + 1 : c_idx_not_exist;
}/*}}}*/

bool bic_array_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack)
{/*{{{*/
  pointer_array_s *array_ptr = (pointer_array_s *)location_ptr->v_data_ptr;

  stream.append(sizeof(unsigned),(const char *)&array_ptr->used);

  if (array_ptr->used != 0)
  {
    pointer *l_ptr = array_ptr->data;
    pointer *l_ptr_end = l_ptr + array_ptr->used;

    do
    {
      loc_stack.push(*l_ptr);
    }
    while(++l_ptr < l_ptr_end);
  }

  return true;
}/*}}}*/

bool bic_array_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos)
{/*{{{*/
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  location_ptr->v_data_ptr = (pointer_array_s *)array_ptr;

  if (stream.used < sizeof(unsigned))
  {
    return false;
  }

  unsigned length;
  stream.from_end(sizeof(unsigned),(char *)&length,order_bytes);

  if (loc_stack.used < length)
  {
    return false;
  }

  if (length > 0)
  {
    array_ptr->copy_resize(length);

    pointer *l_ptr = loc_stack.data + (loc_stack.used - length);
    pointer *l_ptr_end = loc_stack.data + loc_stack.used;
    do
    {
      array_ptr->push(*l_ptr);
    }
    while(++l_ptr < l_ptr_end);

    loc_stack.used -= length;
  }

  return true;
}/*}}}*/

bool bic_array_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_array_operator_binary_plus_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_array_s *array_ptr = (pointer_array_s *)dst_location->v_data_ptr;

  // - construct container from array -
  if (src_0_location->v_type == c_bi_class_array)
  {
    BIC_ARRAY_APPEND_ARRAY(src_0_location,array_ptr);
  }

  // - construct container from iterable -
  else
  {
    BIC_ARRAY_APPEND_ITERABLE(src_0_location,array_ptr);
  }

  dst_location->v_reference_cnt.atomic_inc();

  BIC_SET_RESULT(dst_location);

  return true;
}/*}}}*/

bool bic_array_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_ARRAY_COMPARE(dst_location,src_0_location,operands[c_source_pos_idx]);
  result = result == 0;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_array_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_ARRAY_COMPARE(dst_location,src_0_location,operands[c_source_pos_idx]);
  result = result != 0;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_array_operator_binary_plus(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_array_s *array_ptr = (pointer_array_s *)it.get_new_array_ptr();

  // - create target location -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);

  BIC_SET_RESULT(new_location);

  // - copy elements from array -
  BIC_ARRAY_APPEND_ARRAY(dst_location,array_ptr);

  // - append elements from array -
  if (src_0_location->v_type == c_bi_class_array)
  {
    BIC_ARRAY_APPEND_ARRAY(src_0_location,array_ptr);
  }

  // - append elements from iterable -
  else
  {
    BIC_ARRAY_APPEND_ITERABLE(src_0_location,array_ptr);
  }

  return true;
}/*}}}*/

bool bic_array_operator_binary_ls_br_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_array_s *array_ptr = (pointer_array_s *)dst_location->v_data_ptr;

  // - retrieve length -
  long long int length;
  BIC_CALL_LENGTH(it,src_0_location,length,operands[c_source_pos_idx],
                  return false;
                 );

  // - ERROR -
  if (length != array_ptr->used)
  {
    exception_s::throw_exception(it,c_error_ARRAY_ELEMENT_ASSIGN_NOT_SAME_LENGTH,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - retrieve iterable type -
  unsigned iter_type = it.get_iterable_type(src_0_location);

  // - ERROR -
  if (iter_type == c_idx_not_exist)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_OBJECT_OF_CLASS_IS_NOT_ITERABLE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  if (length > 0)
  {
#define BIC_ARRAY_OPERATOR_BINARY_LS_BR_EQUAL_BODY() \
  {/*{{{*/\
\
    /* - retrieve target location - */\
    pointer &trg_location = \
                            ((location_s *)*p_ptr)->v_type == c_bi_reference ? \
                            *((pointer *)((location_s *)*p_ptr)->v_data_ptr) : *p_ptr;\
\
    /* - retrieve source location - */\
    location_s *src_location = it.get_location_value((pointer)item_location);\
\
    src_location->v_reference_cnt.atomic_inc();\
    it.release_location_ptr((location_s *)trg_location);\
    trg_location = (pointer)src_location;\
\
    it.release_location_ptr(item_location);\
  }/*}}}*/

    if (iter_type == c_iter_first_idx_next_idx_item)
    {
      long long int index;
      location_s *item_location;

      // - retrieve first index -
      BIC_CALL_FIRST_IDX(it,src_0_location,index,operands[c_source_pos_idx],
                         return false;
                        );

      pointer *p_ptr = array_ptr->data;
      pointer *p_ptr_end = p_ptr + array_ptr->used;
      do
      {
        // - retrieve item location -
        BIC_CALL_ITEM(it,src_0_location,index,item_location,operands[c_source_pos_idx],
                      return false;
                     );

        BIC_ARRAY_OPERATOR_BINARY_LS_BR_EQUAL_BODY();

        if (++p_ptr >= p_ptr_end)
        {
          break;
        }

        // - retrieve next index -
        BIC_CALL_NEXT_IDX(it,src_0_location,index,index,operands[c_source_pos_idx],
                          return false;
                         );

        // - ERROR -
        if (index == c_idx_not_exist)
        {
          exception_s::throw_exception(it,c_error_UNEXPECTED_END_OF_ITERABLE,operands[c_source_pos_idx],(location_s *)it.blank_location);
          return false;
        }

      }
      while(true);
    }
    else if (iter_type == c_iter_next_item)
    {
      location_s *item_location;

      pointer *p_ptr = array_ptr->data;
      pointer *p_ptr_end = p_ptr + array_ptr->used;
      do
      {
        // - retrieve next item location -
        BIC_CALL_NEXT_ITEM(it,src_0_location,item_location,operands[c_source_pos_idx],
                           return false;
                          );

        // - ERROR -
        if (it.get_location_value(item_location)->v_type == c_bi_class_blank)
        {
          exception_s::throw_exception(it,c_error_UNEXPECTED_END_OF_ITERABLE,operands[c_source_pos_idx],(location_s *)it.blank_location);
          return false;
        }

        BIC_ARRAY_OPERATOR_BINARY_LS_BR_EQUAL_BODY();

      }
      while(++p_ptr < p_ptr_end);
    }
    else
    {
      cassert(0);
    }
  }

  dst_location->v_reference_cnt.atomic_inc();

  BIC_SET_RESULT(dst_location);

  return true;
}/*}}}*/

bool bic_array_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ARRAY_ITEM("operator_binary_le_br_re_br#1");

  return true;
}/*}}}*/

bool bic_array_method_Array_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  return true;
}/*}}}*/

bool bic_array_method_Array_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_array_s *array_ptr = (pointer_array_s *)dst_location->v_data_ptr;

  // - construct container from array -
  if (src_0_location->v_type == c_bi_class_array)
  {
    BIC_ARRAY_APPEND_ARRAY(src_0_location,array_ptr);
  }

  // - construct container from iterable -
  else
  {
    BIC_ARRAY_APPEND_ITERABLE(src_0_location,array_ptr);
  }

  return true;
}/*}}}*/

bool bic_array_method_clear_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_array_s *array_ptr = (pointer_array_s *)dst_location->v_data_ptr;

  if (array_ptr->used != 0)
  {
    pointer *l_ptr = array_ptr->data;
    pointer *l_ptr_end = l_ptr + array_ptr->used;

    do
    {
      it.release_location_ptr((location_s *)*l_ptr);
    }
    while(++l_ptr < l_ptr_end);
  }

  array_ptr->clear();

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_array_method_resize_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int new_size;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,new_size))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("resize#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  pointer_array_s *array_ptr = (pointer_array_s *)dst_location->v_data_ptr;

  // - ERROR -
  if ((int)array_ptr->used > new_size)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_ARRAY_CANNOT_RESIZE_TO_SMALLER_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(new_size);
    new_exception->params.push(array_ptr->used);

    return false;
  }

  // - increase array size -
  if (new_size > (int)array_ptr->used)
  {
    // - increase reference count on blank location -
    ((location_s *)it.blank_location)->v_reference_cnt.atomic_add(new_size - array_ptr->used);

    // - resize pointer array -
    array_ptr->copy_resize(new_size);

    pointer *p_ptr = array_ptr->data + array_ptr->used;
    pointer *p_ptr_end = array_ptr->data + new_size;
    do
    {
      *p_ptr = it.blank_location;
    }
    while(++p_ptr < p_ptr_end);

    array_ptr->used = new_size;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_array_method_push_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_array_s *array_ptr = (pointer_array_s *)dst_location->v_data_ptr;

  src_0_location->v_reference_cnt.atomic_inc();
  array_ptr->push((pointer)src_0_location);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_array_method_push_ref_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  pointer &src_0_location = it.data_stack[stack_base + operands[c_src_0_op_idx]];

  pointer_array_s *array_ptr = (pointer_array_s *)dst_location->v_data_ptr;

  location_s *new_ref_location = it.get_new_reference((location_s **)&src_0_location);
  array_ptr->push((pointer)new_ref_location);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_array_method_pop_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_array_s *array_ptr = (pointer_array_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (array_ptr->used == 0)
  {
    exception_s::throw_exception(it,c_error_ARRAY_NO_ELEMENTS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // pop next value from array -
  location_s *location_ptr = (location_s *)array_ptr->pop();

  BIC_SET_RESULT(location_ptr);

  return true;
}/*}}}*/

bool bic_array_method_last_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_array_s *array_ptr = (pointer_array_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (array_ptr->used == 0)
  {
    exception_s::throw_exception(it,c_error_ARRAY_NO_ELEMENTS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // retrieve last value from array -
  pointer *element_location = &array_ptr->last();
  location_s *new_ref_location = it.get_new_reference((location_s **)element_location);

  // - set result location -
  BIC_SET_RESULT(new_ref_location);

  return true;
}/*}}}*/

bool bic_array_method_fill_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_array_s *array_ptr = (pointer_array_s *)dst_location->v_data_ptr;

  if (array_ptr->used != 0)
  {
    src_0_location->v_reference_cnt.atomic_add(array_ptr->used);

    pointer *p_ptr = array_ptr->data;
    pointer *p_ptr_end = p_ptr + array_ptr->used;
    do
    {
      it.release_location_ptr((location_s *)*p_ptr);
      *p_ptr = (pointer)src_0_location;
    }
    while(++p_ptr < p_ptr_end);
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_array_method_get_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_array_s *array_ptr = (pointer_array_s *)dst_location->v_data_ptr;

  long long int index = c_idx_not_exist;
  long long int result;

  if (array_ptr->used != 0)
  {
    pointer *l_ptr = array_ptr->data;
    pointer *l_ptr_end = l_ptr + array_ptr->used;

    do
    {
      BIC_CALL_COMPARE(it,*l_ptr,src_0_location,operands[c_source_pos_idx],return false);

      if (result == 0)
      {
        index = l_ptr - array_ptr->data;
        break;
      }
    }
    while(++l_ptr < l_ptr_end);
  }

  BIC_SET_RESULT_CONT_INDEX(index);

  return true;
}/*}}}*/

bool bic_array_method_get_idxs_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_array_s *array_ptr = (pointer_array_s *)dst_location->v_data_ptr;

  ui_array_s idxs_array;
  idxs_array.init();

  long long int result;

  if (array_ptr->used != 0)
  {
    pointer *l_ptr = array_ptr->data;
    pointer *l_ptr_end = l_ptr + array_ptr->used;

    do
    {
      BIC_CALL_COMPARE(it,*l_ptr,src_0_location,operands[c_source_pos_idx],return false);

      if (result == 0)
      {
        idxs_array.push(l_ptr - array_ptr->data);
      }
    }
    while(++l_ptr < l_ptr_end);
  }

  // - construct array from temporary array of indexes -
  pointer_array_s *res_array_ptr = it.get_new_array_ptr();

  BIC_CONT_CONSTRUCT_IDXS_ARRAY();

  idxs_array.clear();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,res_array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_array_method_contain_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  pointer_array_s *array_ptr = (pointer_array_s *)dst_location->v_data_ptr;

  long long int found = 0;
  long long int result;

  if (array_ptr->used != 0)
  {
    pointer *l_ptr = array_ptr->data;
    pointer *l_ptr_end = l_ptr + array_ptr->used;

    do
    {
      BIC_CALL_COMPARE(it,*l_ptr,src_0_location,operands[c_source_pos_idx],return false);

      if (result == 0)
      {
        found = 1;
        break;
      }
    }
    while(++l_ptr < l_ptr_end);
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,found);

  return true;
}/*}}}*/

bool bic_array_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  BIC_ARRAY_COMPARE(dst_location,src_0_location,operands[c_source_pos_idx]);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_array_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_ARRAY_ITEM("item#1");

  return true;
}/*}}}*/

bool bic_array_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_array_s *array_ptr = (pointer_array_s *)dst_location->v_data_ptr;

  if (array_ptr->used != 0)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,0);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_array_method_last_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_array_s *array_ptr = (pointer_array_s *)dst_location->v_data_ptr;

  if (array_ptr->used != 0)
  {
    long long int result = array_ptr->used - 1;

    BIC_SIMPLE_SET_RES(c_bi_class_integer,result);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_array_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int index;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,index))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("next_idx#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  BIC_ARRAY_CHECK_INDEX();

  if (++index < array_ptr->used)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,index);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_array_method_prev_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int index;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,index))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("prev_idx#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  BIC_ARRAY_CHECK_INDEX();

  if (index >= 1)
  {
    long long int result = index - 1;

    BIC_SIMPLE_SET_RES(c_bi_class_integer,result);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_array_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((pointer_array_s *)dst_location->v_data_ptr)->used;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_array_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_array_s *array_ptr = (pointer_array_s *)dst_location->v_data_ptr;

  string_array_s strings;
  strings.init_size(array_ptr->used);
  strings.used = strings.size;

  unsigned strings_size = 0;

  if (array_ptr->used != 0)
  {
    pointer *e_ptr = array_ptr->data;
    pointer *e_ptr_end = e_ptr + array_ptr->used;
    string_s *s_ptr = strings.data;

    do
    {
      BIC_CALL_TO_STRING(it,*e_ptr,operands[c_source_pos_idx],
                         strings.clear();
                         return false;
                        );
    }
    while(++s_ptr,++e_ptr < e_ptr_end);
  }

  string_s *string_ptr = it.get_new_string_ptr();

  BIC_CONT_TO_STRING_0_CONSTRUCT();

  // - release string array -
  strings.clear();

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_array_method_to_string_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("to_string#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  pointer_array_s *array_ptr = (pointer_array_s *)dst_location->v_data_ptr;
  string_s *del_string_ptr = (string_s *)src_0_location->v_data_ptr;

  string_array_s strings;
  strings.init_size(array_ptr->used);
  strings.used = strings.size;

  unsigned strings_size = 0;

  if (array_ptr->used != 0)
  {
    pointer *e_ptr = array_ptr->data;
    pointer *e_ptr_end = e_ptr + array_ptr->used;
    string_s *s_ptr = strings.data;

    do
    {
      BIC_CALL_TO_STRING(it,*e_ptr,operands[c_source_pos_idx],
                         strings.clear();
                         return false;
                        );
    }
    while(++s_ptr,++e_ptr < e_ptr_end);
  }

  string_s *string_ptr = it.get_new_string_ptr();

  BIC_CONT_TO_STRING_1_CONSTRUCT();

  // - release string array -
  strings.clear();

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_array_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  pointer_array_s *array_ptr = ((pointer_array_s *)dst_location->v_data_ptr);

  putchar('[');

  if (array_ptr->used != 0)
  {
    pointer *e_ptr = array_ptr->data;
    pointer *e_ptr_end = e_ptr + array_ptr->used;

    do
    {
      BIC_CALL_PRINT(it,*e_ptr,operands[c_source_pos_idx],return false;);
      if (++e_ptr >= e_ptr_end)
      {
        break;
      }
      putchar(',');
    }
    while(true);
  }

  putchar(']');

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

// - class ERROR -
built_in_class_s error_class =
{/*{{{*/
  "Error",
  c_modifier_public | c_modifier_final,
  7, error_methods,
  0, error_variables,
  bic_error_consts,
  bic_error_init,
  bic_error_clear,
  bic_error_compare,
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

built_in_method_s error_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_error_operator_binary_equal
  },
  {
    "operator_binary_double_equal#1",
    c_modifier_public | c_modifier_final,
    bic_error_operator_binary_double_equal
  },
  {
    "operator_binary_exclamation_equal#1",
    c_modifier_public | c_modifier_final,
    bic_error_operator_binary_exclamation_equal
  },
  {
    "Error#0",
    c_modifier_public | c_modifier_final,
    bic_error_method_Error_0
  },
  {
    "compare#1",
    c_modifier_public | c_modifier_final,
    bic_error_method_compare_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_error_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_error_method_print_0
  },
};/*}}}*/

built_in_variable_s error_variables[] =
{/*{{{*/
};/*}}}*/

void bic_error_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_error_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (unsigned)c_error_OK;
}/*}}}*/

void bic_error_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

int bic_error_compare(location_s *first_loc,location_s *second_loc)
{/*{{{*/
  unsigned first = (unsigned)first_loc->v_data_ptr;
  unsigned second = (unsigned)second_loc->v_data_ptr;

  return first < second ? -1 : (first > second ? 1 : 0);
}/*}}}*/

bool bic_error_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_error_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  if (src_0_location->v_type == c_bi_class_error)
  {
    result = (unsigned)dst_location->v_data_ptr == (unsigned)src_0_location->v_data_ptr;
  }
  else
  {
    result = 0;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_error_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  if (src_0_location->v_type == c_bi_class_error)
  {
    result = (unsigned)dst_location->v_data_ptr != (unsigned)src_0_location->v_data_ptr;
  }
  else
  {
    result = 1;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_error_method_Error_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  return true;
}/*}}}*/

bool bic_error_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  if (src_0_location->v_type == c_bi_class_error)
  {
    unsigned first = (unsigned)dst_location->v_data_ptr;
    unsigned second = (unsigned)src_0_location->v_data_ptr;

    result = first < second ? -1 : (first > second ? 1 : 0);
  }
  else
  {
    result = c_bi_class_error < src_0_location->v_type ? -1 : 1;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_error_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING(
    string_ptr->setf("%s",((interpreter_s *)it.interpreter_ptr)->error_strings[(unsigned)dst_location->v_data_ptr].data)
  );

  return true;
}/*}}}*/

bool bic_error_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - print error to standard output -
  printf("%s",((interpreter_s *)it.interpreter_ptr)->error_strings[(unsigned)dst_location->v_data_ptr].data);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

// - class EXCEPTION -
built_in_class_s exception_class =
{/*{{{*/
  "Exception",
  c_modifier_public | c_modifier_final,
  10, exception_methods,
  46, exception_variables,
  bic_exception_consts,
  bic_exception_init,
  bic_exception_clear,
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

built_in_method_s exception_methods[] =
{/*{{{*/
  {
    "Exception#0",
    c_modifier_public | c_modifier_final,
    bic_exception_method_Exception_0
  },
  {
    "Exception#1",
    c_modifier_public | c_modifier_final,
    bic_exception_method_Exception_1
  },
  {
    "throw#0",
    c_modifier_public | c_modifier_final,
    bic_exception_method_throw_0
  },
  {
    "get_type#0",
    c_modifier_public | c_modifier_final,
    bic_exception_method_get_type_0
  },
  {
    "get_value#0",
    c_modifier_public | c_modifier_final,
    bic_exception_method_get_value_0
  },
  {
    "get_file_name#0",
    c_modifier_public | c_modifier_final,
    bic_exception_method_get_file_name_0
  },
  {
    "get_line#0",
    c_modifier_public | c_modifier_final,
    bic_exception_method_get_line_0
  },
  {
    "error_print#0",
    c_modifier_public | c_modifier_final,
    bic_exception_method_error_print_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_exception_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_exception_method_print_0
  },
};/*}}}*/

built_in_variable_s exception_variables[] =
{/*{{{*/
  {
    "USER_EXCEPTION",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "TODO_EXCEPTION",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "CLASS_DOES_NOT_CONTAIN_CONSTRUCTOR",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "CLASS_DOES_NOT_CONTAIN_METHOD",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "CLASS_DOES_NOT_CONTAIN_VARIABLE",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "CANNOT_ACCESS_PRIVATE_METHOD",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "CANNOT_ACCESS_PRIVATE_VARIABLE",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "METHOD_CANNOT_RETURN_VALUE",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "CANNOT_TEST_TYPE_VALUE",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "CANNOT_CONVERT_TYPE_TO_INTEGER",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "CANNOT_USE_NEGATIVE_NUMBER",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "SLICE_NOT_INTEGER_ARGUMENTS",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "SLICE_START_LESS_THAN_ZERO",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "SLICE_STOP_LESS_THAN_ZERO",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "SLICE_STEP_EQUAL_TO_ZERO",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "OBJECT_OF_CLASS_IS_NOT_ITERABLE",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "UNEXPECTED_END_OF_ITERABLE",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "BUILT_IN_NOT_IMPLEMENTED_METHOD",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "METHOD_NOT_DEFINED_WITH_PARAMETERS",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "WRONG_METHOD_PARAMETER_VALUE",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "DIVISION_BY_ZERO",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "NEGATIVE_SHIFT_COUNT",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "METHOD_NOT_RETURN_INTEGER",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "METHOD_NOT_RETURN_STRING",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "METHOD_NOT_RETURN_INDEX",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "INTEGER_BASE_OUT_OF_RANGE",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "INTEGER_CONVERT_INVALID_STRING",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "FLOAT_CONVERT_INVALID_STRING",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "STRING_FORMAT_NOT_ENOUGH_ARGUMENTS",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "STRING_FORMAT_WRONG_ARGUMENT_TYPE",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "STRING_FORMAT_ARGUMENT_FORMAT_ERROR",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "STRING_FORMAT_WRONG_FORMAT_SPECIFIER",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "STRING_FORMAT_NOT_ALL_ARGUMENTS_CONVERTED",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "STRING_INDEX_EXCEEDS_RANGE",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "STRING_WRONG_RANGE_INDEXES",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "STRING_CONVERT_FROM_INTEGER",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "STRING_CONVERT_FROM_FLOAT",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "ARRAY_INDEX_EXCEEDS_RANGE",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "ARRAY_CANNOT_RESIZE_TO_SMALLER_SIZE",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "ARRAY_NO_ELEMENTS",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "ARRAY_ELEMENT_ASSIGN_NOT_SAME_LENGTH",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "DELEGATE_NEGATIVE_PARAMETER_COUNT",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "DELEGATE_OBJECT_DOES_NOT_CONTAIN_METHOD",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "DELEGATE_CALL_WRONG_PARAMETER_COUNT",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "DELEGATE_PAPPLY_WRONG_PARAMETER_COUNT",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "DELEGATE_WRONG_RETURN_VALUE_TYPE",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
};/*}}}*/

void bic_exception_consts(location_array_s &const_locations)
{/*{{{*/
  const_locations.push_blanks(46);
  location_s *cv_ptr = const_locations.data + (const_locations.used - 46);

#define CREATE_EXCEPTION_TYPE_BIC_STATIC(EXCEPTION_TYPE)\
  cv_ptr->v_type = c_bi_class_error;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (unsigned)EXCEPTION_TYPE;\
  cv_ptr++;

  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_USER_EXCEPTION);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_TODO_EXCEPTION);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_CLASS_DOES_NOT_CONTAIN_CONSTRUCTOR);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_CLASS_DOES_NOT_CONTAIN_METHOD);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_CLASS_DOES_NOT_CONTAIN_VARIABLE);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_CANNOT_ACCESS_PRIVATE_METHOD);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_CANNOT_ACCESS_PRIVATE_VARIABLE);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_METHOD_CANNOT_RETURN_VALUE);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_CANNOT_TEST_TYPE_VALUE);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_CANNOT_CONVERT_TYPE_TO_INTEGER);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_CANNOT_USE_NEGATIVE_NUMBER);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_SLICE_NOT_INTEGER_ARGUMENTS);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_SLICE_START_LESS_THAN_ZERO);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_SLICE_STOP_LESS_THAN_ZERO);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_SLICE_STEP_EQUAL_TO_ZERO);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_OBJECT_OF_CLASS_IS_NOT_ITERABLE);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_UNEXPECTED_END_OF_ITERABLE);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_BUILT_IN_NOT_IMPLEMENTED_METHOD);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_WRONG_METHOD_PARAMETER_VALUE);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_DIVISION_BY_ZERO);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_NEGATIVE_SHIFT_COUNT);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_METHOD_NOT_RETURN_INTEGER);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_METHOD_NOT_RETURN_STRING);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_METHOD_NOT_RETURN_INDEX);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_INTEGER_BASE_OUT_OF_RANGE);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_INTEGER_CONVERT_INVALID_STRING);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_FLOAT_CONVERT_INVALID_STRING);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_STRING_FORMAT_NOT_ENOUGH_ARGUMENTS);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_STRING_FORMAT_WRONG_ARGUMENT_TYPE);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_STRING_FORMAT_ARGUMENT_FORMAT_ERROR);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_STRING_FORMAT_WRONG_FORMAT_SPECIFIER);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_STRING_FORMAT_NOT_ALL_ARGUMENTS_CONVERTED);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_STRING_INDEX_EXCEEDS_RANGE);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_STRING_WRONG_RANGE_INDEXES);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_STRING_CONVERT_FROM_INTEGER);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_STRING_CONVERT_FROM_FLOAT);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_ARRAY_INDEX_EXCEEDS_RANGE);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_ARRAY_CANNOT_RESIZE_TO_SMALLER_SIZE);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_ARRAY_NO_ELEMENTS);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_ARRAY_ELEMENT_ASSIGN_NOT_SAME_LENGTH);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_DELEGATE_NEGATIVE_PARAMETER_COUNT);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_DELEGATE_OBJECT_DOES_NOT_CONTAIN_METHOD);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_DELEGATE_CALL_WRONG_PARAMETER_COUNT);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_DELEGATE_PAPPLY_WRONG_PARAMETER_COUNT);
  CREATE_EXCEPTION_TYPE_BIC_STATIC(c_error_DELEGATE_WRONG_RETURN_VALUE_TYPE);
}/*}}}*/

void bic_exception_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  exception_s *exception_ptr = (exception_s *)cmalloc(sizeof(exception_s));
  exception_ptr->init();

  ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();
  exception_ptr->obj_location = it.blank_location;

  location_ptr->v_data_ptr = (exception_s *)exception_ptr;
}/*}}}*/

void bic_exception_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  exception_s *exception_ptr = (exception_s *)location_ptr->v_data_ptr;

  // - release exception object -
  it.release_location_ptr((location_s *)(exception_ptr->obj_location));

  exception_ptr->clear();
  cfree(exception_ptr);
}/*}}}*/

bool bic_exception_method_Exception_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve exception pointer -
  exception_s *exception_ptr = (exception_s *)dst_location->v_data_ptr;

  // - setup exception default values -
  exception_ptr->type = c_error_USER_EXCEPTION;
  exception_ptr->position = c_idx_not_exist;

  return true;
}/*}}}*/

bool bic_exception_method_Exception_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - retrieve exception pointer -
  exception_s *exception_ptr = (exception_s *)dst_location->v_data_ptr;

  // - setup exception default values -
  exception_ptr->type = c_error_USER_EXCEPTION;
  exception_ptr->position = c_idx_not_exist;

  src_0_location->v_reference_cnt.atomic_inc();

  // - copy reference of new location to exception object location -
  it.release_location_ptr((location_s *)exception_ptr->obj_location);
  exception_ptr->obj_location = (pointer)src_0_location;

  return true;
}/*}}}*/

bool bic_exception_method_throw_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve exception pointer -
  exception_s *exception_ptr = (exception_s *)dst_location->v_data_ptr;

  // - set exception position if it is not already set -
  if (exception_ptr->position == c_idx_not_exist)
  {
    exception_ptr->position = operands[c_source_pos_idx];
  }

  // - increase exception location reference counter -
  dst_location->v_reference_cnt.atomic_inc();

  // - set this exception as active, and throw it -
  it.release_location_ptr((location_s *)it.exception_location);
  it.exception_location = (pointer)dst_location;

  return false;
}/*}}}*/

bool bic_exception_method_get_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve exception pointer -
  exception_s *exception_ptr = (exception_s *)dst_location->v_data_ptr;

  BIC_SIMPLE_SET_RES(c_bi_class_error,exception_ptr->type);

  return true;
}/*}}}*/

bool bic_exception_method_get_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve exception pointer -
  exception_s *exception_ptr = (exception_s *)dst_location->v_data_ptr;

  location_s *obj_location = (location_s *)exception_ptr->obj_location;
  obj_location->v_reference_cnt.atomic_inc();

  BIC_SET_RESULT(obj_location);

  return true;
}/*}}}*/

bool bic_exception_method_get_file_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve exception pointer -
  exception_s *exception_ptr = (exception_s *)dst_location->v_data_ptr;

  if (exception_ptr->position != c_idx_not_exist)
  {
    source_s &source = ((interpreter_s *)it.interpreter_ptr)->sources[GET_SRC_IDX(exception_ptr->position)];

    // - create new string pointer -
    string_s *new_string_ptr = it.get_new_string_ptr();
    *new_string_ptr = source.file_name;

    BIC_SET_RESULT_STRING(new_string_ptr);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_exception_method_get_line_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve exception pointer -
  exception_s *exception_ptr = (exception_s *)dst_location->v_data_ptr;

  if (exception_ptr->position != c_idx_not_exist)
  {
    unsigned source_pos = GET_SRC_POS(exception_ptr->position);
    source_s &source = ((interpreter_s *)it.interpreter_ptr)->sources[GET_SRC_IDX(exception_ptr->position)];

    long long int result = source.source_string.get_character_line(source_pos);
    BIC_SIMPLE_SET_RES(c_bi_class_integer,result);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_exception_method_error_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve exception pointer -
  exception_s *exception_ptr = (exception_s *)dst_location->v_data_ptr;

  // - store exception position -
  unsigned position = exception_ptr->position;

  // - set exception position if it is not set -
  if (exception_ptr->position == c_idx_not_exist)
  {
    exception_ptr->position = operands[c_source_pos_idx];
  }

  // - print exception error message -
  IT_INTERPRETER->print_exception_message(*exception_ptr);

  // - set back exception position -
  exception_ptr->position = position;

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_exception_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Exception"),"Exception")
  );

  return true;
}/*}}}*/

bool bic_exception_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Exception");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class TYPE -
built_in_class_s type_class =
{/*{{{*/
  "Type",
  c_modifier_public | c_modifier_final,
  8, type_methods,
  0, type_variables,
  bic_type_consts,
  bic_type_init,
  bic_type_clear,
  bic_type_compare,
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

built_in_method_s type_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_type_operator_binary_equal
  },
  {
    "operator_binary_double_equal#1",
    c_modifier_public | c_modifier_final,
    bic_type_operator_binary_double_equal
  },
  {
    "operator_binary_exclamation_equal#1",
    c_modifier_public | c_modifier_final,
    bic_type_operator_binary_exclamation_equal
  },
  {
    "Type#0",
    c_modifier_public | c_modifier_final,
    bic_type_method_Type_0
  },
  {
    "Type#1",
    c_modifier_public | c_modifier_final,
    bic_type_method_Type_1
  },
  {
    "compare#1",
    c_modifier_public | c_modifier_final,
    bic_type_method_compare_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_type_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_type_method_print_0
  },
};/*}}}*/

built_in_variable_s type_variables[] =
{/*{{{*/
};/*}}}*/

void bic_type_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_type_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (unsigned)c_bi_class_blank;
}/*}}}*/

void bic_type_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

int bic_type_compare(location_s *first_loc,location_s *second_loc)
{/*{{{*/
  unsigned first = (unsigned)first_loc->v_data_ptr;
  unsigned second = (unsigned)second_loc->v_data_ptr;

  return first < second ? -1 : (first > second ? 1 : 0);
}/*}}}*/

bool bic_type_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_type_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  if (src_0_location->v_type == c_bi_class_type)
  {
    result = (unsigned)dst_location->v_data_ptr == (unsigned)src_0_location->v_data_ptr;
  }
  else
  {
    result = 0;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_type_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  if (src_0_location->v_type == c_bi_class_type)
  {
    result = (unsigned)dst_location->v_data_ptr != (unsigned)src_0_location->v_data_ptr;
  }
  else
  {
    result = 1;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_type_method_Type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  return true;
}/*}}}*/

bool bic_type_method_Type_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  dst_location->v_data_ptr = (unsigned)src_0_location->v_type;

  return true;
}/*}}}*/

bool bic_type_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  if (src_0_location->v_type == c_bi_class_type)
  {
    unsigned first = (unsigned)dst_location->v_data_ptr;
    unsigned second = (unsigned)src_0_location->v_data_ptr;

    result = first < second ? -1 : (first > second ? 1 : 0);
  }
  else
  {
    result = c_bi_class_type < src_0_location->v_type ? -1 : 1;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_type_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  interpreter_s &interpreter = *((interpreter_s *)it.interpreter_ptr);

  BIC_TO_STRING(
    string_ptr->setf("%s",interpreter.class_symbol_names[interpreter.class_records[(unsigned)dst_location->v_data_ptr].name_idx].data);
  );

  return true;
}/*}}}*/

bool bic_type_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  interpreter_s &interpreter = *((interpreter_s *)it.interpreter_ptr);

  // - print value to standard output -
  printf("%s",interpreter.class_symbol_names[interpreter.class_records[(unsigned)dst_location->v_data_ptr].name_idx].data);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

// - class MUTEX -
built_in_class_s mutex_class =
{/*{{{*/
  "Mutex",
  c_modifier_public | c_modifier_final,
  7, mutex_methods,
  4, mutex_variables,
  bic_mutex_consts,
  bic_mutex_init,
  bic_mutex_clear,
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

built_in_method_s mutex_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_mutex_operator_binary_equal
  },
  {
    "Mutex#0",
    c_modifier_public | c_modifier_final,
    bic_mutex_method_Mutex_0
  },
  {
    "lock#0",
    c_modifier_public | c_modifier_final,
    bic_mutex_method_lock_0
  },
  {
    "try_lock#0",
    c_modifier_public | c_modifier_final,
    bic_mutex_method_try_lock_0
  },
  {
    "unlock#0",
    c_modifier_public | c_modifier_final,
    bic_mutex_method_unlock_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_mutex_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_mutex_method_print_0
  },
};/*}}}*/

built_in_variable_s mutex_variables[] =
{/*{{{*/
  {
    "ERROR_INVALID",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "ERROR_DEADLOCK",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "ERROR_BUSY",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "ERROR_PERMISSION",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
};/*}}}*/

void bic_mutex_consts(location_array_s &const_locations)
{/*{{{*/
  const_locations.push_blanks(4);
  location_s *cv_ptr = const_locations.data + (const_locations.used - 4);

#define CREATE_MUTEX_ERROR_BIC_STATIC(ERROR_CODE)\
  cv_ptr->v_type = c_bi_class_error;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (unsigned)ERROR_CODE;\
  cv_ptr++;

  CREATE_MUTEX_ERROR_BIC_STATIC(c_error_EINVAL);
  CREATE_MUTEX_ERROR_BIC_STATIC(c_error_EDEADLK);
  CREATE_MUTEX_ERROR_BIC_STATIC(c_error_EBUSY);
  CREATE_MUTEX_ERROR_BIC_STATIC(c_error_EPERM);
}/*}}}*/

void bic_mutex_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  mutex_s *mutex_ptr = (mutex_s *)cmalloc(sizeof(mutex_s));
  cassert(mutex_ptr->init() == c_error_OK);

  location_ptr->v_data_ptr = (mutex_s *)mutex_ptr;
}/*}}}*/

void bic_mutex_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  mutex_s *mutex_ptr = (mutex_s *)location_ptr->v_data_ptr;

  int ret_val;
  while ((ret_val = mutex_ptr->clear()) == c_error_EBUSY)
  {
    cassert(mutex_ptr->unlock() == c_error_OK);
  }

  cassert(ret_val == c_error_OK);

  cfree(mutex_ptr);
}/*}}}*/

bool bic_mutex_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_mutex_method_Mutex_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  return true;
}/*}}}*/

bool bic_mutex_method_lock_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - mutex lock -
  unsigned ret = ((mutex_s *)dst_location->v_data_ptr)->lock();

  if (ret != c_error_OK)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_error,ret);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_mutex_method_try_lock_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - try lock of mutex -
  unsigned ret = ((mutex_s *)dst_location->v_data_ptr)->try_lock();

  if (ret != c_error_OK)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_error,ret);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_mutex_method_unlock_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - unlock mutex -
  unsigned ret = ((mutex_s *)dst_location->v_data_ptr)->unlock();

  if (ret != c_error_OK)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_error,ret);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_mutex_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Mutex"),"Mutex")
  );

  return true;
}/*}}}*/

bool bic_mutex_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Mutex");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class THREAD -
built_in_class_s thread_class =
{/*{{{*/
  "Thread",
  c_modifier_public | c_modifier_final,
  6

#ifdef ENABLE_THREAD_TRY_JOIN
  + 1
#endif

  , thread_methods,
  5, thread_variables,
  bic_thread_consts,
  bic_thread_init,
  bic_thread_clear,
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

built_in_method_s thread_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_thread_operator_binary_equal
  },
  {
    "join#0",
    c_modifier_public | c_modifier_final,
    bic_thread_method_join_0
  },
#ifdef ENABLE_THREAD_TRY_JOIN
  {
    "try_join#0",
    c_modifier_public | c_modifier_final,
    bic_thread_method_try_join_0
  },
#endif
  {
    "detach#0",
    c_modifier_public | c_modifier_final,
    bic_thread_method_detach_0
  },
  {
    "yield#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_thread_method_yield_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_thread_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_thread_method_print_0
  }
};/*}}}*/

built_in_variable_s thread_variables[] =
{/*{{{*/
  {
    "ERROR_AGAIN",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "ERROR_SEARCH",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "ERROR_INVALID",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "ERROR_DEADLOCK",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "ERROR_BUSY",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  }
};/*}}}*/

void bic_thread_consts(location_array_s &const_locations)
{/*{{{*/
  const_locations.push_blanks(5);
  location_s *cv_ptr = const_locations.data + (const_locations.used - 5);

#define CREATE_THREAD_ERROR_BIC_STATIC(ERROR_CODE)\
  cv_ptr->v_type = c_bi_class_error;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (unsigned)ERROR_CODE;\
  cv_ptr++;

  CREATE_THREAD_ERROR_BIC_STATIC(c_error_EAGAIN);
  CREATE_THREAD_ERROR_BIC_STATIC(c_error_ESRCH);
  CREATE_THREAD_ERROR_BIC_STATIC(c_error_EINVAL);
  CREATE_THREAD_ERROR_BIC_STATIC(c_error_EDEADLK);
  CREATE_THREAD_ERROR_BIC_STATIC(c_error_EBUSY);
}/*}}}*/

void bic_thread_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_thread_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  thread_s *thread_ptr = (thread_s *)location_ptr->v_data_ptr;

  thread_ptr->clear();
  cfree(thread_ptr);
}/*}}}*/

bool bic_thread_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_thread_method_join_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - test if thread exist -
  thread_s *thread_ptr = (thread_s *)dst_location->v_data_ptr;

  void *return_location;

  // - join thread -
  unsigned ret = thread_ptr->join(&return_location);

  // - error while joining thread -
  if (ret != c_error_OK)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_error,ret);
  }
  else
  {
    // - set proper return value -
    if (return_location != nullptr)
    {
      BIC_SET_RESULT(return_location);
    }
    else
    {
      BIC_SET_RESULT_BLANK();
    }
  }

  return true;
}/*}}}*/

#ifdef ENABLE_THREAD_TRY_JOIN
bool bic_thread_method_try_join_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - test if thread exist -
  thread_s *thread_ptr = (thread_s *)dst_location->v_data_ptr;

  void *return_location;

  // - join thread -
  unsigned ret = thread_ptr->try_join(&return_location);

  // - error while joining thread -
  if (ret != c_error_OK)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_error,ret);
  }
  else
  {
    // - set proper return value -
    if (return_location != nullptr)
    {
      BIC_SET_RESULT(return_location);
    }
    else
    {
      BIC_SET_RESULT_BLANK();
    }
  }

  return true;
}/*}}}*/
#endif

bool bic_thread_method_detach_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - test if thread exist -
  thread_s *thread_ptr = (thread_s *)dst_location->v_data_ptr;

  // - thread detach -
  int ret = thread_ptr->detach();

  // - error occurred while detaching thread -
  if (ret != c_error_OK)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_error,ret);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_thread_method_yield_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  thread_s::yield();

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_thread_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Thread"),"Thread")
  );

  return true;
}/*}}}*/

bool bic_thread_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Thread");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class DELEGATE -
built_in_class_s delegate_class =
{/*{{{*/
  "Delegate",
  c_modifier_public | c_modifier_final,
  6, delegate_methods,
  0, delegate_variables,
  bic_delegate_consts,
  bic_delegate_init,
  bic_delegate_clear,
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

built_in_method_s delegate_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_delegate_operator_binary_equal
  },
  {
    "Delegate#3",
    c_modifier_public | c_modifier_final,
    bic_delegate_method_Delegate_3
  },
  {
    "call#1",
    c_modifier_public | c_modifier_final,
    bic_delegate_method_call_1
  },
  {
    "papply#1",
    c_modifier_public | c_modifier_final,
    bic_delegate_method_papply_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_delegate_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_delegate_method_print_0
  }
};/*}}}*/

built_in_variable_s delegate_variables[] =
{/*{{{*/
};/*}}}*/

void bic_delegate_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_delegate_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (delegate_s *)nullptr;
}/*}}}*/

void bic_delegate_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  delegate_s *delegate_ptr = (delegate_s *)location_ptr->v_data_ptr;

  // - if delegate exist -
  if (delegate_ptr != nullptr)
  {
    // - release delegate object -
    if (delegate_ptr->object_location != nullptr)
    {
      it.release_location_ptr(delegate_ptr->object_location);
    }

    // - release delegate partial application parameters -
    if (delegate_ptr->papply != nullptr)
    {
      pointer_array_s *papply_params = (pointer_array_s *)delegate_ptr->papply;

      // - release partial application parameters locations -
      if (papply_params->used != 0)
      {
        pointer *p_ptr = papply_params->data;
        pointer *p_ptr_end = p_ptr + papply_params->used;
        do {
          it.release_location_ptr((location_s *)*p_ptr);
        } while(++p_ptr < p_ptr_end);
      }

      papply_params->clear();
      cfree(papply_params);
    }

    cfree(delegate_ptr);
  }
}/*}}}*/

bool bic_delegate_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_delegate_method_Delegate_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  location_s *src_0_reference = (location_s *)it.data_stack[stack_base + operands[c_src_0_op_idx]];
  location_s *src_0_location = it.get_location_value(src_0_reference);

  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);

  long long int param_cnt;

  if (src_1_location->v_type != c_bi_class_string ||
      !it.retrieve_integer(src_2_location,param_cnt))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Delegate#3");
    new_exception->params.push(3);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);

    return false;
  }

  // - ERROR -
  if (param_cnt < 0)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_DELEGATE_NEGATIVE_PARAMETER_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(param_cnt);

    return false;
  }

  // - retrieve method name -
  string_s *string_ptr = (string_s *)src_1_location->v_data_ptr;

  unsigned name_max_len = string_ptr->size - 1 + max_number_string_length;
  char *buffer = (char *)cmalloc(name_max_len);

  // - create complete method name -
  unsigned name_len = snprintf(buffer,name_max_len,"%s#%" HOST_LL_FORMAT "d",string_ptr->data,param_cnt);

  // - retrieve method name index -
  unsigned name_idx = IT_INTERPRETER->method_symbol_names.get_idx_char_ptr(name_len,buffer);
  cfree(buffer);

  // - create new delegate object -
  delegate_s *delegate_ptr = (delegate_s *)cmalloc(sizeof(delegate_s));

  // - process static method delegate -
  if (src_0_location->v_type == c_bi_class_type)
  {/*{{{*/
    unsigned class_idx = (unsigned)src_0_location->v_data_ptr;

    // - ERROR -
    if (name_idx == c_idx_not_exist)
    {
      cfree(delegate_ptr);

      exception_s *new_exception = exception_s::throw_exception(it,c_error_DELEGATE_OBJECT_DOES_NOT_CONTAIN_METHOD,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(class_idx);

      return false;
    }

    // - retrieve method record index -
    unsigned method_ri = IT_INTERPRETER->class_records[class_idx].mnri_map.map_name(name_idx);

    // - ERROR -
    if (method_ri == c_idx_not_exist)
    {
      cfree(delegate_ptr);

      exception_s *new_exception = exception_s::throw_exception(it,c_error_DELEGATE_OBJECT_DOES_NOT_CONTAIN_METHOD,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(class_idx);

      return false;
    }

    method_record_s &method_record = IT_INTERPRETER->method_records[method_ri];

    // - ERROR -
    if (!(method_record.modifiers & c_modifier_static))
    {
      cfree(delegate_ptr);

      exception_s *new_exception = exception_s::throw_exception(it,c_error_DELEGATE_OBJECT_DOES_NOT_CONTAIN_METHOD,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(class_idx);

      return false;
    }

    delegate_ptr->object_location = nullptr;
    delegate_ptr->name_idx_ri = method_ri;
    delegate_ptr->orig_param_cnt = param_cnt;
    delegate_ptr->param_cnt = param_cnt;
    delegate_ptr->papply = nullptr;
  }/*}}}*/

  // - process method delegate -
  else
  {/*{{{*/

    // - ERROR -
    if (name_idx == c_idx_not_exist)
    {
      cfree(delegate_ptr);

      exception_s *new_exception = exception_s::throw_exception(it,c_error_DELEGATE_OBJECT_DOES_NOT_CONTAIN_METHOD,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(src_0_location->v_type);

      return false;
    }

    // - retrieve method record index -
    unsigned method_ri = IT_INTERPRETER->class_records[src_0_location->v_type].mnri_map.map_name(name_idx);

    // - ERROR -
    if (method_ri == c_idx_not_exist)
    {
      cfree(delegate_ptr);

      exception_s *new_exception = exception_s::throw_exception(it,c_error_DELEGATE_OBJECT_DOES_NOT_CONTAIN_METHOD,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(src_0_location->v_type);

      return false;
    }

    src_0_reference->v_reference_cnt.atomic_inc();
    delegate_ptr->object_location = src_0_reference;

    delegate_ptr->name_idx_ri = name_idx;
    delegate_ptr->orig_param_cnt = param_cnt;
    delegate_ptr->param_cnt = param_cnt;
    delegate_ptr->papply = nullptr;
  }/*}}}*/

  // - set object pointer to result -
  dst_location->v_data_ptr = (delegate_s *)delegate_ptr;

  return true;
}/*}}}*/

bool bic_delegate_method_call_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_array)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("call#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve delegate pointer -
  delegate_s *delegate_ptr = (delegate_s *)dst_location->v_data_ptr;

  // - retrieve parameters array -
  pointer_array_s *params_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (params_ptr->used != delegate_ptr->param_cnt)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_DELEGATE_CALL_WRONG_PARAMETER_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(params_ptr->used);
    new_exception->params.push(delegate_ptr->param_cnt);

    return false;
  }

  // - call delegate method -
  location_s *trg_location = nullptr;
  BIC_CALL_DELEGATE(it,delegate_ptr,params_ptr->data,params_ptr->used,trg_location,operands[c_source_pos_idx],return false);

  BIC_SET_RESULT(trg_location);

  return true;
}/*}}}*/

bool bic_delegate_method_papply_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_array)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("papply#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve delegate pointer -
  delegate_s *orig_dlg_ptr = (delegate_s *)dst_location->v_data_ptr;

  // - retrieve parameters array -
  pointer_array_s *params_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (params_ptr->used == 0 || params_ptr->used > orig_dlg_ptr->param_cnt)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_DELEGATE_PAPPLY_WRONG_PARAMETER_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(params_ptr->used);
    new_exception->params.push(orig_dlg_ptr->param_cnt);

    return false;
  }

  // - create new delegate object -
  delegate_s *new_dlg_ptr = (delegate_s *)cmalloc(sizeof(delegate_s));

  // - retrieve object location -
  if (orig_dlg_ptr->object_location != nullptr)
  {
    orig_dlg_ptr->object_location->v_reference_cnt.atomic_inc();
  }

  new_dlg_ptr->object_location = orig_dlg_ptr->object_location;

  // - retrieve method properties -
  new_dlg_ptr->name_idx_ri = orig_dlg_ptr->name_idx_ri;
  new_dlg_ptr->orig_param_cnt = orig_dlg_ptr->orig_param_cnt;
  new_dlg_ptr->param_cnt = orig_dlg_ptr->param_cnt - params_ptr->used;

  // - retrieve partial application parameters -
  pointer_array_s *new_papply_params = (pointer_array_s *)cmalloc(sizeof(pointer_array_s));
  new_papply_params->init();

  // - copy original partial application parameters -
  if (orig_dlg_ptr->papply != nullptr)
  {
    pointer_array_s *orig_papply_params = (pointer_array_s *)orig_dlg_ptr->papply;

    pointer *p_ptr = orig_papply_params->data;
    pointer *p_ptr_end = p_ptr + orig_papply_params->used;
    do {
      ((location_s *)*p_ptr)->v_reference_cnt.atomic_inc();
      new_papply_params->push(*p_ptr);
    } while(++p_ptr < p_ptr_end);
  }

  // - copy new partial application parameters -
  {
    pointer *p_ptr = params_ptr->data;
    pointer *p_ptr_end = p_ptr + params_ptr->used;
    do {
      location_s *location_ptr = it.get_location_value(*p_ptr);

      location_ptr->v_reference_cnt.atomic_inc();
      new_papply_params->push(location_ptr);
    } while(++p_ptr < p_ptr_end);
  }

  new_dlg_ptr->papply = new_papply_params;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_delegate,new_dlg_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_delegate_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Delegate"),"Delegate")
  );

  return true;
}/*}}}*/

bool bic_delegate_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Delegate");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class BUFFER -
built_in_class_s buffer_class =
{/*{{{*/
  "Buffer",
  c_modifier_public | c_modifier_final,
  4, buffer_methods,
  0, buffer_variables,
  bic_buffer_consts,
  bic_buffer_init,
  bic_buffer_clear,
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

built_in_method_s buffer_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_buffer_operator_binary_equal
  },
  {
    "size#0",
    c_modifier_public | c_modifier_final,
    bic_buffer_method_size_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_buffer_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_buffer_method_print_0
  }
};/*}}}*/

built_in_variable_s buffer_variables[] =
{/*{{{*/
};/*}}}*/

void bic_buffer_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_buffer_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (buffer_s *)nullptr;
}/*}}}*/

void bic_buffer_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  buffer_s *b_ptr = (buffer_s *)location_ptr->v_data_ptr;

  // - if buffer exist -
  if (b_ptr != nullptr)
  {
    if (b_ptr->owner_ptr != nullptr)
    {
      it.release_location_ptr(b_ptr->owner_ptr);
    }
    else
    {
      // - if buffer owns data -
      if (b_ptr->data != nullptr)
      {
        // - release data -
        cfree(b_ptr->data);
      }
    }

    cfree(b_ptr);
  }
}/*}}}*/

bool bic_buffer_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_buffer_method_size_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  buffer_s *buffer_ptr = (buffer_s *)dst_location->v_data_ptr;

  long long int result = buffer_ptr->size;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_buffer_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Buffer"),"Buffer")
  );

  return true;
}/*}}}*/

bool bic_buffer_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Buffer");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

