
#ifndef __ZIP_MODULE_H
#define __ZIP_MODULE_H

@begin
include "ucl_zip.h"
@end

// - ZIP indexes of built in classes -
extern unsigned c_bi_class_zip_archive;
extern unsigned c_bi_class_zip_index;

// - ZIP module -
extern built_in_module_s module;

// - ZIP classes -
extern built_in_class_s *zip_classes[];

// - ZIP error identifiers -
enum
{
  c_error_ZIP_ARCHIVE_OPEN_ERROR = 0,
  c_error_ZIP_ARCHIVE_NOT_OPENED,
};

// - ZIP error strings -
extern const char *zip_error_strings[];

// - ZIP initialize -
bool zip_initialize(script_parser_s &sp);

// - ZIP print exception -
bool zip_print_exception(interpreter_s &it,exception_s &exception);

// - class ZIP_ARCHIVE -
extern built_in_variable_s zip_archive_variables[];
extern built_in_method_s zip_archive_methods[];
extern built_in_class_s zip_archive_class;

void bic_zip_archive_consts(location_array_s &const_locations);
void bic_zip_archive_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_zip_archive_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_zip_archive_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_zip_archive_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_zip_archive_method_ZipArchive_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_zip_archive_method_close_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_zip_archive_method_discard_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_zip_archive_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_zip_archive_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_zip_archive_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_zip_archive_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_zip_archive_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_zip_archive_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class ZIP_INDEX -
extern built_in_variable_s zip_index_variables[];
extern built_in_method_s zip_index_methods[];
extern built_in_class_s zip_index_class;

void bic_zip_index_consts(location_array_s &const_locations);
void bic_zip_index_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_zip_index_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_zip_index_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_zip_index_method_index_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_zip_index_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_zip_index_method_size_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_zip_index_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_zip_index_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

