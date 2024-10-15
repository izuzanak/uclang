
@begin
include "xlsxwriter_module.h"
@end

// - XLSX_WRITER indexes of built in classes -
unsigned c_bi_class_xlsx_workbook = c_idx_not_exist;
unsigned c_bi_class_xlsx_worksheet = c_idx_not_exist;
unsigned c_bi_class_xlsx_format = c_idx_not_exist;

// - XLSX_WRITER module -
EXPORT built_in_module_s module =
{/*{{{*/
  3,                           // Class count
  xlsx_writer_classes,         // Classes

  0,                           // Error base index
  8,                           // Error count
  xlsx_writer_error_strings,   // Error strings

  xlsx_writer_initialize,      // Initialize function
  xlsx_writer_print_exception, // Print exceptions function
};/*}}}*/

// - XLSX_WRITER classes -
built_in_class_s *xlsx_writer_classes[] =
{/*{{{*/
  &xlsx_workbook_class,
  &xlsx_worksheet_class,
  &xlsx_format_class,
};/*}}}*/

// - XLSX_WRITER error strings -
const char *xlsx_writer_error_strings[] =
{/*{{{*/
  "error_XLSX_WORKBOOK_CREATE_ERROR",
  "error_XLSX_WORKBOOK_CLOSE_ERROR",
  "error_XLSX_WORKBOOK_NOT_OPENED",
  "error_XLSX_WORKBOOK_ADD_WORKSHEET_ERROR",
  "error_XLSX_WORKBOOK_ADD_FORMAT_ERROR",
  "error_XLSX_WORKSHEET_FORMAT_WORKBOOK_MISMATCH",
  "error_XLSX_WORKSHEET_WRITE_ERROR",
  "error_XLSX_WORKSHEET_WRITE_INVALID_VALUE_TYPE",
};/*}}}*/

// - XLSX_WRITER initialize -
bool xlsx_writer_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize xlsx_workbook class identifier -
  c_bi_class_xlsx_workbook = class_base_idx++;

  // - initialize xlsx_worksheet class identifier -
  c_bi_class_xlsx_worksheet = class_base_idx++;

  // - initialize xlsx_format class identifier -
  c_bi_class_xlsx_format = class_base_idx++;

  return true;
}/*}}}*/

// - XLSX_WRITER print exception -
bool xlsx_writer_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_XLSX_WORKBOOK_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nXLSX Workbook, create error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_XLSX_WORKBOOK_CLOSE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nXLSX Workbook, close error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_XLSX_WORKBOOK_NOT_OPENED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nXLSX Workbook is not opened\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_XLSX_WORKBOOK_ADD_WORKSHEET_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nXLSX Workbook, add worksheet error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_XLSX_WORKBOOK_ADD_FORMAT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nXLSX Workbook, add format error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_XLSX_WORKSHEET_FORMAT_WORKBOOK_MISMATCH:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nXLSX Worksheet, format workbook mismatch\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_XLSX_WORKSHEET_WRITE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nXLSX Worksheet, write error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_XLSX_WORKSHEET_WRITE_INVALID_VALUE_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nXLSX Worksheet, invalid value type to write\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class XLSX_WORKBOOK -
built_in_class_s xlsx_workbook_class =
{/*{{{*/
  "XlsxWorkbook",
  c_modifier_public | c_modifier_final,
  6, xlsx_workbook_methods,
  0, xlsx_workbook_variables,
  bic_xlsx_workbook_consts,
  bic_xlsx_workbook_init,
  bic_xlsx_workbook_clear,
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

built_in_method_s xlsx_workbook_methods[] =
{/*{{{*/
  {
    "XlsxWorkbook#1",
    c_modifier_public | c_modifier_final,
    bic_xlsx_workbook_method_XlsxWorkbook_1
  },
  {
    "add_worksheet#1",
    c_modifier_public | c_modifier_final,
    bic_xlsx_workbook_method_add_worksheet_1
  },
  {
    "add_format#0",
    c_modifier_public | c_modifier_final,
    bic_xlsx_workbook_method_add_format_0
  },
  {
    "close#0",
    c_modifier_public | c_modifier_final,
    bic_xlsx_workbook_method_close_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_xlsx_workbook_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_xlsx_workbook_method_print_0
  },
};/*}}}*/

built_in_variable_s xlsx_workbook_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_xlsx_workbook_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_xlsx_workbook_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (lxw_workbook *)nullptr;
}/*}}}*/

void bic_xlsx_workbook_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  lxw_workbook *xwb_ptr = (lxw_workbook *)location_ptr->v_data_ptr;

  if (xwb_ptr != nullptr)
  {
    workbook_close(xwb_ptr);
  }
}/*}}}*/

bool bic_xlsx_workbook_method_XlsxWorkbook_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
path:c_bi_class_string
>
method XlsxWorkbook
; @end

  string_s *path_str = (string_s *)src_0_location->v_data_ptr;

  lxw_workbook *xwb_ptr = workbook_new(path_str->data);

  // - ERROR -
  if (xwb_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_XLSX_WORKBOOK_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  dst_location->v_data_ptr = (lxw_workbook *)xwb_ptr;

  return true;
}/*}}}*/

bool bic_xlsx_workbook_method_add_worksheet_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
sheetname:c_bi_class_string
>
method add_worksheet
; @end

  lxw_workbook *xwb_ptr = (lxw_workbook *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (xwb_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_XLSX_WORKBOOK_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  lxw_worksheet *worksheet = workbook_add_worksheet(xwb_ptr,string_ptr->data);

  // - ERROR -
  if (worksheet == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_XLSX_WORKBOOK_ADD_WORKSHEET_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create xlsx worksheet object -
  xlsx_worksheet_s *xws_ptr = (xlsx_worksheet_s *)cmalloc(sizeof(xlsx_worksheet_s));
  xws_ptr->init();

  dst_location->v_reference_cnt.atomic_inc();
  xws_ptr->workbook_loc = dst_location;
  xws_ptr->worksheet = worksheet;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_xlsx_worksheet,xws_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_xlsx_workbook_method_add_format_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  lxw_workbook *xwb_ptr = (lxw_workbook *)dst_location->v_data_ptr;

  // - ERROR -
  if (xwb_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_XLSX_WORKBOOK_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  lxw_format *format = workbook_add_format(xwb_ptr);

  // - ERROR -
  if (format == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_XLSX_WORKBOOK_ADD_FORMAT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create xlsx format object -
  xlsx_format_s *xf_ptr = (xlsx_format_s *)cmalloc(sizeof(xlsx_format_s));
  xf_ptr->init();

  dst_location->v_reference_cnt.atomic_inc();
  xf_ptr->workbook_loc = dst_location;
  xf_ptr->format = format;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_xlsx_format,xf_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_xlsx_workbook_method_close_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  lxw_workbook *xwb_ptr = (lxw_workbook *)dst_location->v_data_ptr;

  // - ERROR -
  if (xwb_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_XLSX_WORKBOOK_NOT_OPENED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  if (workbook_close(xwb_ptr) != LXW_NO_ERROR)
  {
    dst_location->v_data_ptr = (lxw_workbook *)nullptr;

    exception_s::throw_exception(it,module.error_base + c_error_XLSX_WORKBOOK_CLOSE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  dst_location->v_data_ptr = (lxw_workbook *)nullptr;

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_xlsx_workbook_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("XlsxWorkbook"),"XlsxWorkbook");
  );

  return true;
}/*}}}*/

bool bic_xlsx_workbook_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("XlsxWorkbook");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class XLSX_WORKSHEET -
built_in_class_s xlsx_worksheet_class =
{/*{{{*/
  "XlsxWorksheet",
  c_modifier_public | c_modifier_final,
  7, xlsx_worksheet_methods,
  0, xlsx_worksheet_variables,
  bic_xlsx_worksheet_consts,
  bic_xlsx_worksheet_init,
  bic_xlsx_worksheet_clear,
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

built_in_method_s xlsx_worksheet_methods[] =
{/*{{{*/
  {
    "set_format#1",
    c_modifier_public | c_modifier_final,
    bic_xlsx_worksheet_method_set_format_1
  },
  {
    "reset_format#0",
    c_modifier_public | c_modifier_final,
    bic_xlsx_worksheet_method_reset_format_0
  },
  {
    "write#3",
    c_modifier_public | c_modifier_final,
    bic_xlsx_worksheet_method_write_3
  },
  {
    "write#4",
    c_modifier_public | c_modifier_final,
    bic_xlsx_worksheet_method_write_4
  },
  {
    "write_time#4",
    c_modifier_public | c_modifier_final,
    bic_xlsx_worksheet_method_write_time_4
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_xlsx_worksheet_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_xlsx_worksheet_method_print_0
  },
};/*}}}*/

built_in_variable_s xlsx_worksheet_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_xlsx_worksheet_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_xlsx_worksheet_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (xlsx_worksheet_s *)nullptr;
}/*}}}*/

void bic_xlsx_worksheet_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  xlsx_worksheet_s *xws_ptr = (xlsx_worksheet_s *)location_ptr->v_data_ptr;

  if (xws_ptr != nullptr)
  {
    xws_ptr->clear(it);
    cfree(xws_ptr);
  }
}/*}}}*/

bool bic_xlsx_worksheet_method_set_format_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
format:c_bi_class_xlsx_format
>
method set_format
; @end

  xlsx_worksheet_s *xws_ptr = (xlsx_worksheet_s *)dst_location->v_data_ptr;
  xlsx_format_s *xf_ptr = (xlsx_format_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (xws_ptr->workbook_loc != xf_ptr->workbook_loc)
  {
    exception_s::throw_exception(it,module.error_base + c_error_XLSX_WORKSHEET_FORMAT_WORKBOOK_MISMATCH,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - release format -
  if (xws_ptr->format_loc != nullptr)
  {
    it.release_location_ptr(xws_ptr->format_loc);
  }

  // - set format -
  src_0_location->v_reference_cnt.atomic_inc();
  xws_ptr->format_loc = src_0_location;

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_xlsx_worksheet_method_reset_format_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  xlsx_worksheet_s *xws_ptr = (xlsx_worksheet_s *)dst_location->v_data_ptr;

  // - release format -
  if (xws_ptr->format_loc != nullptr)
  {
    it.release_location_ptr(xws_ptr->format_loc);
    xws_ptr->format_loc = nullptr;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_xlsx_worksheet_method_write_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
row:retrieve_integer
col:retrieve_integer
value:ignore
>
method write
; @end

  xlsx_worksheet_s *xws_ptr = (xlsx_worksheet_s *)dst_location->v_data_ptr;
  lxw_format *format = nullptr;

  // - default format is set -
  if (xws_ptr->format_loc != nullptr)
  {
    format = ((xlsx_format_s *)xws_ptr->format_loc->v_data_ptr)->format;
  }

  switch (src_2_location->v_type)
  {
    case c_bi_class_integer:
    case c_bi_class_float:
      {/*{{{*/
        double value;
        cassert(it.retrieve_float(src_2_location,value));

        // - ERROR -
        if (worksheet_write_number(xws_ptr->worksheet,row,col,value,format) != LXW_NO_ERROR)
        {
          exception_s::throw_exception(it,module.error_base + c_error_XLSX_WORKSHEET_WRITE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
          return false;
        }
      }/*}}}*/
      break;
    case c_bi_class_string:
      {/*{{{*/
        string_s *string_ptr = (string_s *)src_2_location->v_data_ptr;

        // - ERROR -
        if (worksheet_write_string(xws_ptr->worksheet,row,col,string_ptr->data,format) != LXW_NO_ERROR)
        {
          exception_s::throw_exception(it,module.error_base + c_error_XLSX_WORKSHEET_WRITE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
          return false;
        }
      }/*}}}*/
      break;

    // - ERROR -
    default:

      exception_s::throw_exception(it,module.error_base + c_error_XLSX_WORKSHEET_WRITE_INVALID_VALUE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_xlsx_worksheet_method_write_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
row:retrieve_integer
col:retrieve_integer
value:ignore
format:c_bi_class_blank
format:c_bi_class_xlsx_format
>
method write
; @end

  xlsx_worksheet_s *xws_ptr = (xlsx_worksheet_s *)dst_location->v_data_ptr;
  lxw_format *format = nullptr;

  // - format was given -
  if (src_3_location->v_type == c_bi_class_xlsx_format)
  {
    format = ((xlsx_format_s *)src_3_location->v_data_ptr)->format;
  }

  switch (src_2_location->v_type)
  {
    case c_bi_class_integer:
    case c_bi_class_float:
      {/*{{{*/
        double value;
        cassert(it.retrieve_float(src_2_location,value));

        // - ERROR -
        if (worksheet_write_number(xws_ptr->worksheet,row,col,value,format) != LXW_NO_ERROR)
        {
          exception_s::throw_exception(it,module.error_base + c_error_XLSX_WORKSHEET_WRITE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
          return false;
        }
      }/*}}}*/
      break;
    case c_bi_class_string:
      {/*{{{*/
        string_s *string_ptr = (string_s *)src_2_location->v_data_ptr;

        // - ERROR -
        if (worksheet_write_string(xws_ptr->worksheet,row,col,string_ptr->data,format) != LXW_NO_ERROR)
        {
          exception_s::throw_exception(it,module.error_base + c_error_XLSX_WORKSHEET_WRITE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
          return false;
        }
      }/*}}}*/
      break;

    // - ERROR -
    default:

      exception_s::throw_exception(it,module.error_base + c_error_XLSX_WORKSHEET_WRITE_INVALID_VALUE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_xlsx_worksheet_method_write_time_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
row:retrieve_integer
col:retrieve_integer
unixtime:retrieve_integer
format:c_bi_class_xlsx_format
>
method write_time
; @end

  xlsx_worksheet_s *xws_ptr = (xlsx_worksheet_s *)dst_location->v_data_ptr;
  xlsx_format_s *xf_ptr = (xlsx_format_s *)src_3_location->v_data_ptr;

  if (worksheet_write_unixtime(xws_ptr->worksheet,row,col,unixtime,xf_ptr->format) != LXW_NO_ERROR)
  {
    exception_s::throw_exception(it,module.error_base + c_error_XLSX_WORKSHEET_WRITE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_xlsx_worksheet_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("XlsxWorksheet"),"XlsxWorksheet");
  );

  return true;
}/*}}}*/

bool bic_xlsx_worksheet_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("XlsxWorksheet");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class XLSX_FORMAT -
built_in_class_s xlsx_format_class =
{/*{{{*/
  "Xlsxformat",
  c_modifier_public | c_modifier_final,
  3, xlsx_format_methods,
  0, xlsx_format_variables,
  bic_xlsx_format_consts,
  bic_xlsx_format_init,
  bic_xlsx_format_clear,
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

built_in_method_s xlsx_format_methods[] =
{/*{{{*/
  {
    "set_num_format#1",
    c_modifier_public | c_modifier_final,
    bic_xlsx_format_method_set_num_format_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_xlsx_format_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_xlsx_format_method_print_0
  },
};/*}}}*/

built_in_variable_s xlsx_format_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_xlsx_format_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_xlsx_format_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (xlsx_format_s *)nullptr;
}/*}}}*/

void bic_xlsx_format_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  xlsx_format_s *xf_ptr = (xlsx_format_s *)location_ptr->v_data_ptr;

  if (xf_ptr != nullptr)
  {
    xf_ptr->clear(it);
    cfree(xf_ptr);
  }
}/*}}}*/

bool bic_xlsx_format_method_set_num_format_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
format:c_bi_class_string
>
method set_num_format
; @end

  xlsx_format_s *xf_ptr = (xlsx_format_s *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  format_set_num_format(xf_ptr->format,string_ptr->data);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_xlsx_format_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("XlsxFormat"),"XlsxFormat");
  );

  return true;
}/*}}}*/

bool bic_xlsx_format_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("XlsxFormat");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

