
@begin
include "containers_module.h"
include "containers_stack.h"
include "containers_queue.h"
include "containers_set.h"
include "containers_list.h"
include "containers_tree.h"
include "containers_dict.h"
@end

// - CONTAINERS indexes of built in classes -
unsigned c_bi_class_stack = c_idx_not_exist;
unsigned c_bi_class_queue = c_idx_not_exist;
unsigned c_bi_class_set = c_idx_not_exist;
unsigned c_bi_class_list = c_idx_not_exist;
unsigned c_bi_class_tree = c_idx_not_exist;
unsigned c_bi_class_dict = c_idx_not_exist;

// - CONTAINERS module -
built_in_module_s module =
{/*{{{*/
  6,                          // Class count
  containers_classes,         // Classes

  0,                          // Error base index
  12,                         // Error count
  containers_error_strings,   // Error strings

  containers_initialize,      // Initialize function
  containers_print_exception, // Print exceptions function
};/*}}}*/

// - CONTAINERS classes -
built_in_class_s *containers_classes[] =
{/*{{{*/
  &stack_class,
  &queue_class,
  &set_class,
  &list_class,
  &tree_class,
  &dict_class,
};/*}}}*/

// - CONTAINERS error strings -
const char *containers_error_strings[] =
{/*{{{*/
  "error_STACK_INDEX_EXCEEDS_RANGE",
  "error_STACK_NO_OTHER_ELEMENTS",
  "error_QUEUE_INDEX_EXCEEDS_RANGE",
  "error_QUEUE_NO_OTHER_ELEMENTS",
  "error_SET_INDEX_DOES_NOT_REFER_TO_VALID_VALUE",
  "error_SET_DOES_NOT_CONTAIN_ELEMENT",
  "error_LIST_INDEX_DOES_NOT_REFER_TO_VALID_VALUE",
  "error_TREE_INDEX_DOES_NOT_REFER_TO_VALID_VALUE",
  "error_DICT_INDEX_DOES_NOT_REFER_TO_VALID_VALUE",
  "error_DICT_INVALID_KEY",
  "error_DICT_SOURCE_NOT_DIVISIBLE_BY_TWO",
  "error_DICT_SOURCES_NOT_SAME_LENGTH",
};/*}}}*/

// - CONTAINERS initialize -
bool containers_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize stack class identifier -
  c_bi_class_stack = class_base_idx++;

  // - initialize queue class identifier -
  c_bi_class_queue = class_base_idx++;

  // - initialize set class identifier -
  c_bi_class_set = class_base_idx++;

  // - initialize list class identifier -
  c_bi_class_list = class_base_idx++;

  // - initialize tree class identifier -
  c_bi_class_tree = class_base_idx++;

  // - initialize dict class identifier -
  c_bi_class_dict = class_base_idx++;

  return true;
}/*}}}*/

// - CONTAINERS print exception -
bool containers_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_STACK_INDEX_EXCEEDS_RANGE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nIndex %" HOST_LL_FORMAT "d exceeds stack range\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_STACK_NO_OTHER_ELEMENTS:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nStack does not contain any other elements\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_QUEUE_INDEX_EXCEEDS_RANGE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nIndex %" HOST_LL_FORMAT "d exceeds queue range\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_QUEUE_NO_OTHER_ELEMENTS:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nQueue does not contain any other elements\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SET_INDEX_DOES_NOT_REFER_TO_VALID_VALUE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nIndex %" HOST_LL_FORMAT "d does not refer to valid set element\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SET_DOES_NOT_CONTAIN_ELEMENT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSet does not contain requested element\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_LIST_INDEX_DOES_NOT_REFER_TO_VALID_VALUE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nIndex %" HOST_LL_FORMAT "d does not refer to valid list element\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TREE_INDEX_DOES_NOT_REFER_TO_VALID_VALUE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nIndex %" HOST_LL_FORMAT "d does not refer to valid tree element\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_DICT_INDEX_DOES_NOT_REFER_TO_VALID_VALUE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nIndex %" HOST_LL_FORMAT "d does not refer to valid dictionary element\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_DICT_INVALID_KEY:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid dictionary key value\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_DICT_SOURCE_NOT_DIVISIBLE_BY_TWO:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nLength of dictionary source is not divisible by two\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_DICT_SOURCES_NOT_SAME_LENGTH:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nLengths of dictionary sources are not equal\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

