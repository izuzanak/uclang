
#ifndef __ZLIB_MODULE_H
#define __ZLIB_MODULE_H

@begin
include "ucl_zlib.h"
@end

// - ZLIB indexes of built in classes -
extern unsigned c_bi_class_zlib;
extern unsigned c_bi_class_gz_file;

// - ZLIB module -
extern "C" IMPORT built_in_module_s module;

// - ZLIB classes -
extern built_in_class_s *zlib_classes[];

// - ZLIB error identifiers -
enum
{
  c_error_ZLIB_COMPRESS_INVALID_LEVEL = 0,
  c_error_ZLIB_NOT_ENOUGHT_SPACE_IN_BUFFER,
  c_error_ZLIB_COMPRESS_ERROR,
  c_error_ZLIB_UNCOMPRESS_ERROR,
  c_error_GZ_FILE_OPEN_ERROR,
  c_error_GZ_FILE_SEEK_ERROR,
  c_error_GZ_FILE_CLOSE_ERROR,
  c_error_GZ_FILE_WRITE_ERROR,
  c_error_GZ_FILE_READ_ERROR,
  c_error_GZ_FILE_READ_NEGATIVE_BYTE_COUNT,
  c_error_GZ_FILE_NOT_OPENED,
};

// - ZLIB error strings -
extern const char *zlib_error_strings[];

// - ZLIB initialize -
bool zlib_initialize(script_parser_s &sp);

// - ZLIB print exception -
bool zlib_print_exception(interpreter_s &it,exception_s &exception);

// - class ZLIB -
extern built_in_variable_s zlib_variables[];
extern built_in_method_s zlib_methods[];
extern built_in_class_s zlib_class;

void bic_zlib_consts(location_array_s &const_locations);
void bic_zlib_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_zlib_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_zlib_method_compress_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_zlib_method_uncompress_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_zlib_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_zlib_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class GZ_FILE -
extern built_in_variable_s gz_file_variables[];
extern built_in_method_s gz_file_methods[];
extern built_in_class_s gz_file_class;

void bic_gz_file_consts(location_array_s &const_locations);
void bic_gz_file_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_gz_file_clear(interpreter_thread_s &it,location_s *location_ptr);
location_s *bic_gz_file_next_item(interpreter_thread_s &it,location_s *location_ptr,unsigned source_pos);

bool bic_gz_file_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gz_file_method_GzFile_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gz_file_method_seek_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gz_file_method_tell_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gz_file_method_close_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gz_file_method_write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gz_file_method_write_close_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gz_file_method_read_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gz_file_method_readln_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gz_file_method_read_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gz_file_method_read_close_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gz_file_method_next_item_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gz_file_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_gz_file_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

