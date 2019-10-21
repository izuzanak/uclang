
#ifndef __PARSER_MODULE_H
#define __PARSER_MODULE_H

@begin
include "ucl_parser.h"
@end

// - PARSER indexes of built in classes -
extern unsigned c_bi_class_final_automata;
extern unsigned c_bi_class_fa_source;
extern unsigned c_bi_class_parser;
extern unsigned c_bi_class_parse_state;

// - PARSER module -
extern "C" EXPORT built_in_module_s module;

// - PARSER classes -
extern built_in_class_s *parser_classes[];

// - PARSER error identifiers -
// - moved to file parser_code.h -

// - PARSER error strings -
extern const char *parser_error_strings[];

// - PARSER initialize -
bool parser_initialize(script_parser_s &sp);

// - PARSER print exception -
bool parser_print_exception(interpreter_s &it,exception_s &exception);

// - class FINAL_AUTOMATA -
extern built_in_variable_s final_automata_variables[];
extern built_in_method_s final_automata_methods[];
extern built_in_class_s final_automata_class;

void bic_final_automata_consts(location_array_s &const_locations);
void bic_final_automata_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_final_automata_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_final_automata_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_final_automata_method_FinalAutomata_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_final_automata_method_get_source_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_final_automata_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_final_automata_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class FA_SOURCE -
extern built_in_variable_s fa_source_variables[];
extern built_in_method_s fa_source_methods[];
extern built_in_class_s fa_source_class;

void bic_fa_source_consts(location_array_s &const_locations);
void bic_fa_source_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_fa_source_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_fa_source_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fa_source_method_next_terminal_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fa_source_method_old_input_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fa_source_method_input_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fa_source_method_terminal_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fa_source_method_terminal_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fa_source_method_next_item_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fa_source_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_fa_source_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class PARSER -
extern built_in_variable_s parser_variables[];
extern built_in_method_s parser_methods[];
extern built_in_class_s parser_class;

void bic_parser_consts(location_array_s &const_locations);
void bic_parser_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_parser_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_parser_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_parser_method_Parser_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_parser_method_parse_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_parser_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_parser_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class PARSE_STATE -
extern built_in_variable_s parse_state_variables[];
extern built_in_method_s parse_state_methods[];
extern built_in_class_s parse_state_class;

void bic_parse_state_consts(location_array_s &const_locations);
void bic_parse_state_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_parse_state_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_parse_state_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_parse_state_method_rule_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_parse_state_method_rule_body_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_parse_state_method_old_input_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_parse_state_method_input_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_parse_state_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_parse_state_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

