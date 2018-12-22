
#ifndef __DOCU_MODULE_H
#define __DOCU_MODULE_H

@begin
include "ucl_docu.h"
@end

// - DOCU indexes of built in classes -
extern unsigned c_bi_class_docu;
extern unsigned c_bi_class_docu_source;
extern unsigned c_bi_class_docu_comment;
extern unsigned c_bi_class_docu_parsed;

// - DOCU module -
extern "C" IMPORT built_in_module_s module;

// - DOCU classes -
extern built_in_class_s *docu_classes[];

// - DOCU error identifiers -
enum
{
  c_error_DOCU_SOURCE_INDEX_EXCEEDS_RANGE = 0,
  c_error_DOCU_PARSED_PARSE_ERROR,
};

// - DOCU error strings -
extern const char *docu_error_strings[];

// - DOCU initialize -
bool docu_initialize(script_parser_s &sp);

// - DOCU print exception -
bool docu_print_exception(interpreter_s &it,exception_s &exception);

// - class DOCU -
extern built_in_variable_s docu_variables[];
extern built_in_method_s docu_methods[];
extern built_in_class_s docu_class;

void bic_docu_consts(location_array_s &const_locations);
void bic_docu_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_docu_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_docu_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_docu_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class DOCU_SOURCE -
extern built_in_variable_s docu_source_variables[];
extern built_in_method_s docu_source_methods[];
extern built_in_class_s docu_source_class;

void bic_docu_source_consts(location_array_s &const_locations);
void bic_docu_source_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_docu_source_clear(interpreter_thread_s &it,location_s *location_ptr);
unsigned bic_docu_source_first_idx(location_s *location_ptr);
unsigned bic_docu_source_next_idx(location_s *location_ptr,unsigned index);

bool bic_docu_source_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_docu_source_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_docu_source_method_DocuSource_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_docu_source_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_docu_source_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_docu_source_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_docu_source_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_docu_source_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_docu_source_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class DOCU_COMMENT -
extern built_in_variable_s docu_comment_variables[];
extern built_in_method_s docu_comment_methods[];
extern built_in_class_s docu_comment_class;

void bic_docu_comment_consts(location_array_s &const_locations);
void bic_docu_comment_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_docu_comment_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_docu_comment_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_docu_comment_method_start_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_docu_comment_method_end_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_docu_comment_method_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_docu_comment_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_docu_comment_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class DOCU_PARSED -
extern built_in_variable_s docu_parsed_variables[];
extern built_in_method_s docu_parsed_methods[];
extern built_in_class_s docu_parsed_class;

void bic_docu_parsed_consts(location_array_s &const_locations);
void bic_docu_parsed_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_docu_parsed_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_docu_parsed_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_docu_parsed_method_parse_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_docu_parsed_method_create_brief_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_docu_parsed_method_after_member_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_docu_parsed_method_comm_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_docu_parsed_method_id_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_docu_parsed_method_get_brief_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_docu_parsed_method_get_paragraphs_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_docu_parsed_method_get_param_names_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_docu_parsed_method_get_params_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_docu_parsed_method_get_return_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_docu_parsed_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_docu_parsed_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

