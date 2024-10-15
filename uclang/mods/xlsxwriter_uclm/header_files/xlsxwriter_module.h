
#ifndef __XLSXWRITER_MODULE_H
#define __XLSXWRITER_MODULE_H

@begin
include "ucl_xlsxwriter.h"
@end

// - XLSX_WRITER indexes of built in classes -
extern unsigned c_bi_class_xlsx_workbook;
extern unsigned c_bi_class_xlsx_worksheet;
extern unsigned c_bi_class_xlsx_format;

// - XLSX_WRITER module -
extern "C" EXPORT built_in_module_s module;

// - XLSX_WRITER classes -
extern built_in_class_s *xlsx_writer_classes[];

// - XLSX_WRITER error identifiers -
enum
{
  c_error_XLSX_WORKBOOK_CREATE_ERROR = 0,
  c_error_XLSX_WORKBOOK_CLOSE_ERROR,
  c_error_XLSX_WORKBOOK_NOT_OPENED,
  c_error_XLSX_WORKBOOK_ADD_WORKSHEET_ERROR,
  c_error_XLSX_WORKBOOK_ADD_FORMAT_ERROR,
  c_error_XLSX_WORKSHEET_FORMAT_WORKBOOK_MISMATCH,
  c_error_XLSX_WORKSHEET_WRITE_ERROR,
  c_error_XLSX_WORKSHEET_WRITE_INVALID_VALUE_TYPE,
};

// - XLSX_WRITER error strings -
extern const char *xlsx_writer_error_strings[];

// - XLSX_WRITER initialize -
bool xlsx_writer_initialize(script_parser_s &sp);

// - XLSX_WRITER print exception -
bool xlsx_writer_print_exception(interpreter_s &it,exception_s &exception);

// - class XLSX_WORKBOOK -
extern built_in_variable_s xlsx_workbook_variables[];
extern built_in_method_s xlsx_workbook_methods[];
extern built_in_class_s xlsx_workbook_class;

void bic_xlsx_workbook_consts(location_array_s &const_locations);
void bic_xlsx_workbook_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_xlsx_workbook_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_xlsx_workbook_method_XlsxWorkbook_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xlsx_workbook_method_add_worksheet_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xlsx_workbook_method_add_format_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xlsx_workbook_method_close_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xlsx_workbook_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xlsx_workbook_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class XLSX_WORKSHEET -
extern built_in_variable_s xlsx_worksheet_variables[];
extern built_in_method_s xlsx_worksheet_methods[];
extern built_in_class_s xlsx_worksheet_class;

void bic_xlsx_worksheet_consts(location_array_s &const_locations);
void bic_xlsx_worksheet_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_xlsx_worksheet_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_xlsx_worksheet_method_set_format_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xlsx_worksheet_method_reset_format_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xlsx_worksheet_method_write_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xlsx_worksheet_method_write_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xlsx_worksheet_method_write_time_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xlsx_worksheet_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xlsx_worksheet_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class XLSX_FORMAT -
extern built_in_variable_s xlsx_format_variables[];
extern built_in_method_s xlsx_format_methods[];
extern built_in_class_s xlsx_format_class;

void bic_xlsx_format_consts(location_array_s &const_locations);
void bic_xlsx_format_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_xlsx_format_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_xlsx_format_method_set_num_format_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xlsx_format_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_xlsx_format_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

