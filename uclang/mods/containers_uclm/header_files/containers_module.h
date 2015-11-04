
#ifndef __CONTAINERS_MODULE_H
#define __CONTAINERS_MODULE_H

@begin
include "script_parser.h"
@end

// - CONTAINERS indexes of built in classes -
extern unsigned c_bi_class_stack;
extern unsigned c_bi_class_queue;
extern unsigned c_bi_class_set;
extern unsigned c_bi_class_list;
extern unsigned c_bi_class_tree;
extern unsigned c_bi_class_dict;

// - CONTAINERS module -
extern built_in_module_s module;

// - CONTAINERS classes -
extern built_in_class_s *containers_classes[];

// - CONTAINERS error identifiers -
enum
{
  c_error_STACK_INDEX_EXCEEDS_RANGE = 0,
  c_error_STACK_NO_OTHER_ELEMENTS,
  c_error_QUEUE_INDEX_EXCEEDS_RANGE,
  c_error_QUEUE_NO_OTHER_ELEMENTS,
  c_error_SET_INDEX_DOES_NOT_REFER_TO_VALID_VALUE,
  c_error_SET_DOES_NOT_CONTAIN_ELEMENT,
  c_error_LIST_INDEX_DOES_NOT_REFER_TO_VALID_VALUE,
  c_error_TREE_INDEX_DOES_NOT_REFER_TO_VALID_VALUE,
  c_error_DICT_INDEX_DOES_NOT_REFER_TO_VALID_VALUE,
  c_error_DICT_INVALID_KEY,
  c_error_DICT_SOURCE_NOT_DIVISIBLE_BY_TWO,
  c_error_DICT_SOURCES_NOT_SAME_LENGTH,
};

// - CONTAINERS error strings -
extern const char *containers_error_strings[];

// - CONTAINERS initialize -
bool containers_initialize(script_parser_s &sp);

// - CONTAINERS print exception -
bool containers_print_exception(interpreter_s &it,exception_s &exception);

#endif

