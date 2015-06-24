
#ifndef __SCRIPT_PARSER_H
#define __SCRIPT_PARSER_H

@begin
include "mutex.h"
include "thread.h"
include "struct.h"
include "dynlib.h"
include "cipher.h"
@end

/*
 * constants and definitions
 */

#if THREAD_LIB == THREAD_LIB_DSP_TSK

// - after how many instructions yield DSP processor -
const int c_DSP_yield_cycle_const = 5;
#endif

// - maximal number format size -
const int c_number_format_size = 128;

// - retrieval of source index and position from position -
#define GET_SRC_IDX(POS) ((POS & 0xfff00000) >> 20)
#define GET_SRC_POS(POS)  (POS & 0x000fffff)
#define SET_SRC_POS(IDX,POS) ((IDX << 20) | POS)

// - flow graph node types -
enum
{
  c_fg_type_expression,
  c_fg_type_condition,
  c_fg_type_return_expression,
  c_fg_type_for_loop,
  c_fg_type_break,
  c_fg_type_continue,
  c_fg_type_switch
};

// - sizes of nodes in flow graphs -
enum
{
  c_fg_expression_size = 3,
  c_fg_condition_size = 5,
  c_fg_return_expression_size = 3,
  c_fg_for_loop_size = 5,
  c_fg_break_size = 1,
  c_fg_continue_size = 1,
  c_fg_switch_size = 6
};

// - elements from which are composed flow graph nodes -
enum
{
  c_fg_expression_idx = 1,
  c_fg_expression_first_out = 2,

  c_fg_condition_first_out = 2,
  c_fg_condition_second_out,
  c_fg_condition_source_pos,

  c_fg_return_expression_source_pos = 2,

  c_fg_for_loop_body = 3,
  c_fg_for_loop_source_pos,

  c_fg_switch_default_cnt = 3,
  c_fg_switch_exp_cnt,
  c_fg_switch_source_pos,
  c_fg_switch_defaults,
};

// - types of thread (threads from which is composed flow graph) while generatin flow graphs -
enum
{
  c_fgts_type_blank,
  c_fgts_type_thread
};

// - break and continue identifiers among thread nodes -
const unsigned c_fgts_bc_value_base = 0xfffffff0;
enum
{
  c_fgts_value_break = c_fgts_bc_value_base,
  c_fgts_value_continue
};

// - identifiers of expression graph nodes -
enum
{

  c_node_type_elements_array,
  c_node_type_switch_test,
  c_node_type_slice_range,

  c_node_type_operator_binary_equal,
  c_node_type_operator_binary_plus_equal,
  c_node_type_operator_binary_minus_equal,
  c_node_type_operator_binary_asterisk_equal,
  c_node_type_operator_binary_slash_equal,
  c_node_type_operator_binary_percent_equal,
  c_node_type_operator_binary_double_ls_br_equal,
  c_node_type_operator_binary_double_rs_br_equal,
  c_node_type_operator_binary_ampersand_equal,
  c_node_type_operator_binary_pipe_equal,
  c_node_type_operator_binary_circumflex_equal,
  c_node_type_operator_binary_double_ampersand,
  c_node_type_operator_binary_double_pipe,
  c_node_type_operator_binary_ampersand,
  c_node_type_operator_binary_pipe,
  c_node_type_operator_binary_circumflex,
  c_node_type_operator_binary_double_equal,
  c_node_type_operator_binary_exclamation_equal,
  c_node_type_operator_binary_rs_br,
  c_node_type_operator_binary_ls_br,
  c_node_type_operator_binary_rs_br_equal,
  c_node_type_operator_binary_ls_br_equal,
  c_node_type_operator_binary_double_rs_br,
  c_node_type_operator_binary_double_ls_br,
  c_node_type_operator_binary_plus,
  c_node_type_operator_binary_minus,
  c_node_type_operator_binary_asterisk,
  c_node_type_operator_binary_slash,
  c_node_type_operator_binary_percent,
  c_node_type_operator_unary_post_double_plus,
  c_node_type_operator_unary_post_double_minus,
  c_node_type_operator_unary_pre_double_plus,
  c_node_type_operator_unary_pre_double_minus,
  c_node_type_operator_unary_pre_plus,
  c_node_type_operator_unary_pre_minus,
  c_node_type_operator_unary_pre_exclamation,
  c_node_type_operator_unary_pre_tilde,
  c_node_type_operator_binary_le_br_re_br,

  c_node_type_identifier,
  c_node_type_element_identifier,

  c_node_type_this_access,

  c_node_type_new_object,
  c_node_type_new_objects_array,
  c_node_type_free_object,
  c_node_type_type_identification,
  c_node_type_object_reference_copy,
  c_node_type_conditional_expression,
  c_node_type_object_member_select,
  c_node_type_this_method_call,
  c_node_type_object_method_call,

  c_node_type_const_char,
  c_node_type_const_int,
  c_node_type_const_float,
  c_node_type_const_string
};

// - modifiers of operands used while generating intermediate code -
enum
{
  c_op_modifier_nothing =      0x00000000,
  c_op_modifier_tmp =          0x00000001,
  c_op_modifier_object =       0x00000002,
  c_op_modifier_static_class = 0x00000004
};

// - modifiers of code types used while generating intermediate code -
enum
{
  c_code_modifier_nothing =  0x00000000,
  c_code_modifier_static =   0x00000001,
  c_code_modifier_run_time = 0x00000002
};

// - identifiers of intermediate code instructions -
enum
{
  i_this_element,
  i_const,
  i_static,

  i_call,
  i_static_call,
  i_element_array,
  i_new_object,
  i_new_objects_array,
  i_free_object,
  i_type_identification,
  i_object_reference_copy,
  i_conditional_expression,
  i_object_member_select,
  i_switch_test,
  i_slice_range,

  i_expression_end,
  i_return
};

// - size of intermediate code instructions -
enum
{
  ite_size    = 4,
  ic_size     = 3,
  is_size     = 4,

  icl_size    = 7,
  iscl_size   = 5,
  iea_size    = 4,
  ino_size    = 6,
  inoa_size   = 6,
  ifo_size    = 3,
  iti_size    = 3,
  iorc_size   = 4,
  ice_size    = 6,
  ioms_size   = 5,
  ist_size    = 4,
  isr_size    = 7,

  iee_size    = 1,
  ir_size     = 2
};

// - indexes of intermediate code instruction elements -
enum
{
  ite_source_pos    = 1,
  ite_stack_trg,
  ite_name_idx,

  ic_stack_trg      = 1,
  ic_const_idx,

  is_source_pos     = 1,
  is_stack_trg,
  is_element_pos,

  icl_parm_cnt      = 1,
  icl_name_idx,
  icl_last_class,
  icl_last_bi_mc,
  icl_source_pos,
  icl_stack_trg,
  icl_parm_this,

  iscl_parm_cnt     = 1,
  iscl_source_pos,
  iscl_stack_trg,
  iscl_method_ri,
  iscl_parm_first,

  iea_source_pos    = 1,
  iea_element_cnt,
  iea_stack_trg,
  iea_element_first,

  ino_parm_cnt      = 1,
  ino_class_ri,
  ino_source_pos,
  ino_constr_name,
  ino_stack_trg,
  ino_parm_first,

  inoa_source_pos   = 1,
  inoa_stack_trg,
  inoa_class_ri,
  inoa_constr_name,
  inoa_stack_cnt,

  ifo_stack_trg     = 1,
  ifo_stack_object,

  iti_stack_trg     = 1,
  iti_stack_object,

  iorc_stack_trg    = 1,
  iorc_stack_dst,
  iorc_stack_src,

  ice_source_pos    = 1,
  ice_stack_trg,
  ice_stack_src,
  ice_second_exp,
  ice_end,

  ioms_source_pos   = 1,
  ioms_stack_trg,
  ioms_var_name,
  ioms_stack_object,

  ist_source_pos    = 1,
  ist_value_cnt,
  ist_stack_trg,
  ist_value_first,

  isr_source_pos    = 1,
  isr_stack_trg,
  isr_stack_src,
  isr_start,
  isr_stop,
  isr_step,

  ir_stack_pos      = 1
};

// - identifiers of error codes -
enum
{

  // - parse_script errors -
  ei_unrecognizable_terminal,
  ei_wrong_program_syntax,

  ei_duplicate_class_element_name,
  ei_duplicate_class_method_name,
  ei_duplicate_class_name,
  ei_duplicate_method_parameter,

  ei_variable_ilegall_modifier,
  ei_variable_modifier_private_and_public,

  ei_class_ilegall_modifier,
  ei_class_modifier_abstract_and_final,

  ei_method_modifier_private_and_public,
  ei_method_modifier_abstract_and_static_or_final,
  ei_method_modifier_parallel_must_be_static,

  ei_constructor_ilegall_modifier,

  ei_abstract_method_no_abstract_class,

  ei_non_abstract_method_without_body,
  ei_abstract_method_with_body,

  ei_break_continue_out_of_loop_or_switch,

  // - process_moules errors -
  ei_module_duplicate_class_element_name,
  ei_module_duplicate_class_method_name,
  ei_module_duplicate_class_name,
  ei_module_cannot_find_remote_class,
  ei_module_initialize_error,
  ei_cannot_find_module,

  // - extended_classes_search errors -
  ei_cannot_resolve_extended_class,
  ei_class_cannot_extend_itself,
  ei_cannot_extend_final_class,

  // - element_search -
  ei_must_implement_inherited_abstract_method,
  ei_cannot_override_final_method,

  // - generate_intermediate_code -
  ei_no_classes_defined,

  // - im_gen_actions -
  ei_class_does_not_contain_method,
  ei_class_does_not_have_constructor,
  ei_class_does_not_contain_variable,

  ei_static_reference_to_nonstatic_method,
  ei_cannot_access_private_method,

  ei_static_reference_to_nonstatic_variable,
  ei_cannot_access_private_variable,

  ei_class_name_cannot_be_resolved,
  ei_variable_name_cannot_be_resolved,

  ei_cannot_use_this_in_static_code,

  ei_cannot_create_abstract_class_object,
  ei_expected_object_as_operand,

  ei_switch_expect_objects_as_operands
};

// - run method code return values -
enum
{
  c_run_return_code_EXCEPTION = 0,
  c_run_return_code_OK        = 1,
  c_run_return_code_RETURN    = 2,
  c_run_return_code_BREAK     = 3,
  c_run_return_code_CONTINUE  = 4
};

/*
 * parse constants
 */
const unsigned c_rule_cnt = 177;
const unsigned rule_head_idxs[c_rule_cnt] = {90, 91, 91, 92, 93, 93, 94, 96, 96, 97, 98, 97, 99, 100, 100, 101, 101, 102, 97, 95, 95, 95, 95, 95, 95, 103, 103, 104, 105, 106, 106, 107, 107, 108, 108, 109, 109, 109, 110, 110, 111, 112, 113, 114, 115, 115, 116, 116, 117, 117, 118, 118, 118, 119, 120, 120, 121, 122, 122, 123, 121, 124, 125, 126, 121, 127, 127, 121, 128, 121, 129, 121, 130, 131, 132, 121, 133, 134, 134, 135, 136, 136, 137, 137, 121, 121, 121, 121, 160, 146, 146, 147, 148, 148, 138, 139, 140, 153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 153, 154, 154, 154, 155, 155, 155, 155, 155, 155, 155, 156, 156, 156, 156, 157, 157, 157, 158, 158, 158, 159, 159, 159, 159, 160, 160, 160, 160, 160, 160, 160, 160, 160, 149, 149, 150, 150, 151, 152, 152, 160, 160, 160, 160, 160, 144, 160, 160, 160, 153, 160, 160, 160, 141, 141, 142, 143, 143, 145, 160, 160, 160, 160, 160, 160, 160, 160, 160, };
const unsigned rule_body_lengths[c_rule_cnt] = {1, 2, 1, 1, 2, 1, 3, 2, 1, 3, 2, 3, 3, 2, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 3, 2, 3, 1, 2, 1, 2, 1, 1, 1, 1, 2, 2, 3, 1, 3, 2, 2, 1, 3, 1, 1, 2, 1, 2, 3, 1, 2, 1, 1, 2, 3, 1, 1, 4, 1, 4, 3, 1, 3, 3, 1, 5, 1, 5, 3, 1, 1, 6, 1, 2, 1, 2, 3, 2, 3, 1, 2, 2, 3, 2, 2, 1, 2, 1, 3, 1, 3, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 3, 3, 1, 3, 3, 3, 3, 3, 3, 1, 3, 3, 3, 1, 3, 3, 1, 3, 3, 1, 3, 3, 3, 1, 2, 2, 2, 2, 2, 2, 2, 2, 4, 1, 1, 1, 2, 2, 2, 1, 3, 1, 1, 3, 4, 2, 2, 2, 3, 5, 1, 3, 3, 1, 2, 1, 3, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, };

/*
 * LALR parse table
 */
#define blank c_idx_not_exist
#define SHIFT(VALUE) VALUE
#define REDUCE(VALUE) c_lalr_table_reduce_base + VALUE
#define GOTO(VALUE) VALUE

const unsigned c_lalr_table_reduce_base = 0x80000000;
const unsigned c_terminal_plus_nonterminal_cnt = 161;
const unsigned lalr_state_cnt = 307;

extern const unsigned lalr_table[lalr_state_cnt*c_terminal_plus_nonterminal_cnt];

// - built in methods operand positions -
enum
{
  c_source_pos_idx = 0,
  c_res_op_idx,
  c_dst_op_idx,
  c_src_0_op_idx,
  c_src_1_op_idx,
  c_src_2_op_idx,
  c_src_3_op_idx,
  c_src_4_op_idx,
  c_src_5_op_idx,
};

// - modifiers of classes, methods and variables -
enum
{
  c_modifier_public       = 0x00000001,
  c_modifier_private      = 0x00000002,
  c_modifier_static       = 0x00000004,
  c_modifier_abstract     = 0x00000008,
  c_modifier_final        = 0x00000010,
  c_modifier_parallel     = 0x00000020,
  c_modifier_static_const = 0x00000040, // - built in only -
  c_modifier_built_in     = 0x00000080, // - built in only -

  c_variable_modifier_blank     = 0x00000000,
  c_variable_modifier_reference = 0x00000100,

  c_variable_ilegal_modifiers = c_modifier_abstract | c_modifier_final | c_modifier_parallel,
  c_class_ilegal_modifiers    = c_modifier_private | c_modifier_static | c_modifier_parallel,
  c_constr_ilegal_modifiers   = c_modifier_private | c_modifier_static | c_modifier_abstract | c_modifier_parallel
};

// - iterable types -
enum
{
  c_iter_first_idx_next_idx_item = 0,
  c_iter_next_item
};

/*
 * structure definitions
 */

typedef struct built_in_class_s built_in_class_s;
typedef struct exception_s exception_s;
typedef struct interpreter_thread_s interpreter_thread_s;
typedef struct script_parser_s script_parser_s;
typedef struct interpreter_s interpreter_s;

/*
 * built in function pointer types
 */

typedef built_in_class_s * built_in_class_ptr;
typedef bool (*bi_module_initialize_caller_dt)(script_parser_s &);
typedef bool (*bi_module_print_exception_caller_dt)(interpreter_s &,exception_s &);
typedef void (*bi_class_consts_caller_dt)(location_array_s &);
typedef void (*bi_class_init_caller_dt)(interpreter_thread_s &,location_s *);
typedef void (*bi_class_clear_caller_dt)(interpreter_thread_s &,location_s *);
typedef int (*bi_class_compare_caller_dt)(location_s *,location_s *);
typedef unsigned (*bi_class_length_caller_dt)(location_s *);
typedef location_s *(*bi_class_item_caller_dt)(interpreter_thread_s &,location_s *,unsigned);
typedef unsigned (*bi_class_first_idx_caller_dt)(location_s *);
typedef unsigned (*bi_class_next_idx_caller_dt)(location_s *,unsigned);
typedef location_s *(*bi_class_next_item_caller_dt)(interpreter_thread_s &,location_s *);
typedef bool (*bi_class_pack_caller_dt)(location_s *,bc_array_s &,pointer_array_s &);
typedef bool (*bi_class_unpack_caller_dt)(interpreter_thread_s &,location_s *,bc_array_s &,pointer_array_s &,bool,unsigned);
typedef bool (*bi_class_invoke_caller_dt)(interpreter_thread_s &,uli *,unsigned,uli *);
typedef bool (*bi_class_member_caller_dt)(interpreter_thread_s &,uli *,unsigned);
typedef bool (*bi_method_caller_dt)(interpreter_thread_s &,unsigned,uli *);

@begin
define built_in_class_ptr basic
define bi_module_initialize_caller_dt basic
define bi_module_print_exception_caller_dt basic
define bi_class_consts_caller_dt basic
define bi_class_init_caller_dt basic
define bi_class_clear_caller_dt basic
define bi_class_compare_caller_dt basic
define bi_class_length_caller_dt basic
define bi_class_item_caller_dt basic
define bi_class_first_idx_caller_dt basic
define bi_class_next_idx_caller_dt basic
define bi_class_next_item_caller_dt basic
define bi_class_pack_caller_dt basic
define bi_class_unpack_caller_dt basic
define bi_class_invoke_caller_dt basic
define bi_class_member_caller_dt basic
define bi_method_caller_dt basic
@end

/*
 * format of module built in structures
 */

// - built in variable structure -
struct built_in_variable_s
{
  const char *name;
  unsigned modifiers;
};

// - built in method structure -
struct built_in_method_s
{
  const char *name;
  unsigned modifiers;
  bi_method_caller_dt method_caller;
};

// - built in class structure -
struct built_in_class_s
{
  const char *name;
  unsigned modifiers;

  unsigned method_cnt;
  built_in_method_s *methods;

  unsigned variable_cnt;
  built_in_variable_s *variables;

  bi_class_consts_caller_dt consts_caller;
  bi_class_init_caller_dt init_caller;
  bi_class_clear_caller_dt clear_caller;
  bi_class_compare_caller_dt compare_caller;
  bi_class_length_caller_dt length_caller;
  bi_class_item_caller_dt item_caller;
  bi_class_first_idx_caller_dt first_idx_caller;
  bi_class_next_idx_caller_dt next_idx_caller;
  bi_class_next_item_caller_dt next_item_caller;
  bi_class_pack_caller_dt pack_caller;
  bi_class_unpack_caller_dt unpack_caller;
  bi_class_invoke_caller_dt invoke_caller;
  bi_class_member_caller_dt member_caller;
};

// - built in module structure -
struct built_in_module_s
{
  unsigned class_cnt;
  built_in_class_s **classes;

  unsigned error_base;
  unsigned error_cnt;
  const char **error_strings;

  bi_module_initialize_caller_dt initialize_caller;
  bi_module_print_exception_caller_dt print_exception_caller;
};

/*
 * definition of structure delegate_s
 */

struct delegate_s
{
  location_s *object_location;
  unsigned method_name_idx;
  unsigned param_cnt;
};

/*
 * definition of structure buffer_s
 */

struct buffer_s
{
  location_s *owner_ptr;
  pointer data;
  unsigned size;
};

/*
 * definition of generated structures
 */

// -- name_pos_array_s --
// -- ri_ep_array_s --
// -- idx_size_array_s --
@begin
array<name_pos_s>

additions
{
  /*!
   * \brief return record index and element position descriptor, attached to variable name_idx
   * \param a_name_idx - variable name index
   * \return record index and element position descriptor
   */
  inline ri_ep_s &map_name(unsigned a_name_idx);
}

name_pos_array_s
ri_ep_array_s
idx_size_array_s;
@end

// -- try_fg_map_s --
@begin
struct
    <
    unsigned:tfgm_first_fg_node
    unsigned:tfgm_last_fg_node
    unsigned:tfgm_fg_idx
    unsigned:tfgm_var_idx
    >
    try_fg_map_s;
@end

// -- try_fg_maps_s --
@begin
array<try_fg_map_s> try_fg_maps_s;
@end

// -- namespace_record_s --
@begin
    struct
    <
    unsigned:name_idx
    ui_array_s:namespace_record_idxs
    ui_array_s:class_record_idxs
    >
    namespace_record_s;
@end

// -- namespace_records_s --
@begin
   array<namespace_record_s> namespace_records_s;
@end

// -- class_record_s --
@begin
struct
    <
    unsigned:name_idx
    unsigned:modifiers
    unsigned:parent_record
    unsigned:extend_class_idx

    ui_array_s:using_namespace_idxs
    ui_array_s:class_record_idxs
    ui_array_s:method_record_idxs
    ui_array_s:variable_record_idxs

    unsigned:element_cnt
    ui_array_s:extend_array

    ui_array_s:mnri_map
    ri_ep_array_s:vn_ri_ep_map

    name_pos_s:name_position

    built_in_class_ptr:bi_class_ptr

    unsigned:stack_size
    uli_array_s:init_begin_code
    uli_array_s:init_run_time_code
    >
    class_record_s;
@end

// -- class_records_s --
@begin
array<class_record_s>

additions
{
  /*!
   * \brief get class record index by its name
   * \param a_name_idx - index of class name
   * \return class record index, c_idx_not_exist if class not exist
   */
  unsigned get_class_idx_by_name_idx(unsigned a_name_idx);
}

class_records_s;
@end

// -- method_record_s --
@begin
struct
    <
    unsigned:name_idx
    unsigned:modifiers
    unsigned:parent_record
    ui_array_s:parameter_record_idxs
    unsigned:flow_graph_idx
    name_pos_s:name_position
    bi_method_caller_dt:bi_method_caller

    try_fg_maps_s:try_fg_maps

    unsigned:stack_size
    uli_array_s:begin_code
    uli_array_s:run_time_code
    >
    method_record_s;
@end

// -- method_records_s --
@begin
array<method_record_s> method_records_s;
@end

// -- variable_record_s --
@begin
struct
    <
    unsigned:name_idx
    unsigned:modifiers
    unsigned:parent_record
    unsigned:init_expression_idx

    name_pos_s:name_position
    >
    variable_record_s;
@end

// -- variable_records_s --
@begin
array<variable_record_s> variable_records_s;
@end

// -- expression_s --
// -- flow_graph_s --
@begin
struct
    <
    unsigned:start_node_idx
    ui_array_s:nodes
    >
    expression_s
    flow_graph_s;
@end

// -- expressions_s --
// -- flow_graphs_s --
@begin
array<expression_s>
expressions_s
flow_graphs_s;
@end

// -- exp_flow_graph_s --
@begin
struct
    <
    unsigned:start_node_idx
    ui_array_s:nodes
    expressions_s:expressions
    >
    exp_flow_graph_s;
@end

// -- exp_flow_graphs_s --
@begin
array<exp_flow_graph_s> exp_flow_graphs_s;
@end

// -- expression_descr_s --
@begin
struct
    <
    ui_array_s:tmp_expression
    idx_size_array_s:tmp_exp_info
    >
    expression_descr_s;
@end

// -- expression_descrs_s --
@begin
array<expression_descr_s> expression_descrs_s;
@end

// -- flow_graph_descr_s --
@begin
struct
    <
    ui_array_s:fg_thread_stack
    ui_array_s:fgts_type
    ui_array_s:fgts_cnt
    ui_arrays_array_s:fgts_bc_ends_array
    >
    flow_graph_descr_s;
@end

// -- im_descr_s --
@begin
struct
    <
    unsigned:cv_char_base
    unsigned:cv_integer_base
    unsigned:cv_float_base
    unsigned:cv_string_base
    unsigned:cv_type_base
    unsigned:cv_count

    unsigned:code_modifiers
    unsigned:class_idx
    unsigned:method_idx
    unsigned:exp_idx

    unsigned:stack_idx_max
    ui_array_s:free_stack_idxs

    ui_array_s:exp_node_stack
    ui_array_s:done_exp_nodes

    ui_array_s:found_operands
    ui_array_s:operands
    ui_array_s:operand_stack

    ui_array_s:var_name_fo_map
    ui_array_s:const_idx_fo_map
    ui_array_s:static_vi_fo_map

    ui_array_s:cond_exp_code_idxs
    >
    im_descr_s;
@end

// -- script_parser_s --
@begin
struct
    <
    $// - module search dirs -
    string_array_s:module_dirs

    $// - code sources -
    source_array_s:sources

    $// - module names -
    unsigned:module_idx
    string_array_s:module_names
    name_pos_array_s:module_names_positions

    $// - module libraries and pointers -
    dynlib_array_s:bi_module_libs
    pointer_array_s:bi_module_pointers

    $// - error, exception strings -
    string_array_s:error_strings

    $// - symbol names -
    string_rb_tree_s:class_symbol_names
    string_rb_tree_s:method_symbol_names
    string_rb_tree_s:variable_symbol_names

    $// - classes, methods and variables records -
    namespace_records_s:namespace_records
    class_records_s:class_records
    method_records_s:method_records
    variable_records_s:variable_records

    $// - parse variables BEGIN -

    $// - parse, index of source code -
    unsigned:source_idx

    $// - parse, old index of lexical analyzer -
    unsigned:old_input_idx

    $// - parse, modifiers of element, method, class, ... -
    unsigned:modifiers

    $// - parse, list of namespace identifiers -
    ui_array_s:namespace_name_idxs

    $// - parse, stack of parent namespace indexes -
    ui_array_s:parent_namespace_idxs

    $// - parse, stack of parent namespace indexes -
    ui_array_s:using_namespace_idxs

    $// - parse, stack of parent class indexes -
    ui_array_s:parent_class_idxs

    $// - parse, stack of try flow graph map indexes -
    ui_array_s:try_fg_map_idxs

    $// - parse, temporary storage of name of element, method, class -
    name_pos_array_s:tmp_name_pos_array

    $// - parse, count of object members in objects, arrays, ... -
    ui_array_s:member_cnt

    $// - parse, list of errors constructed while parsing source code -
    ui_array_s:error_code

    $// - parse, switch statement description -
    ui_arrays_s:switch_descrs

    $// - parse, temporary expression variables -
    expression_descrs_s:switch_expression_descrs

    $// - parse, temporary flow graph storage -
    ui_array_s:tmp_flow_graph

    $// - parse, temporary expression storage -
    expressions_s:tmp_expressions

    $// - parse, temporary expression variables -
    expression_descr_s:expression_descr

    $// - parse, temporary flow graph variables -
    flow_graph_descr_s:flow_graph_descr

    $// - parse, LALR stack -
    lalr_stack_s:lalr_stack

    $// - parse variables END -

    $// - parsed information -
    bc_array_s:const_chars
    lli_rb_tree_s:const_ints
    bd_rb_tree_s:const_floats
    string_rb_tree_s:const_strings

    expressions_s:init_expressions

    $// - graphs of program flow -
    exp_flow_graphs_s:method_flow_graphs

    unsigned:static_const_element_cnt
    unsigned:static_element_cnt

    $// - intermediate variables BEGIN -

    $// - intermediate generation variable -
    im_descr_s:im_descr

    $// - intermediate variables END -

    $// - static code description -
    unsigned:stack_size
    uli_array_s:static_begin_code
    uli_array_s:static_run_time_code

    $// - indexes of classes extending some class -
    ui_array_s:extending_idxs
    >

    additions
{
  /*!
   * \brief return method name index, if name not exist use parameter string as name
   * \param a_name - reference to string_s containing method name
   * \return always return method name index
   */
  inline unsigned get_method_name_idx_swap(string_s &a_name);

  /*!
   * \brief retrieve namespace record index by namespace name index
   * \param a_name_idx - index of namespace name (in class_symbol_names)
   * \param a_parent_namespace_idx - namespace record index of namespace to be searched
   * \return index of namespace record, or c_idx_not_exist
   */
  unsigned get_namespace_idx_by_name_idx(unsigned a_name_idx,unsigned a_parent_namespace_idx);

  /*!
   * \brief finds class record index by its name in defined parent class
   * \param a_name_idx - index of class name (in class_symbol_names)
   * \param a_parent_class_idx - index of parent class record (in class_records)
   * \return return class record index, or c_idx_not_exist
   */
  unsigned get_nested_enclosing_class_idx_by_name_idx(unsigned a_name_idx,unsigned a_parent_class_idx);

  /*!
   * \brief resolve class record index by class name index
   * \param a_name_idx - index of class name (in class_symbol_names)
   * \param a_class_idx - class record index of class from which search begins
   * \return index of class record, or c_idx_not_exist
   */
  unsigned resolve_class_idx_by_name_idx(unsigned a_name_idx,unsigned a_class_idx);

  /*!
   * \brief resolve class record index by class name
   * \param a_name - name of class to be resolved
   * \param a_class_idx - class record index of class from which search begins
   * \return index of class record, or c_idx_not_exist
   */
  inline unsigned resolve_class_idx_by_name(const char *a_name,unsigned a_class_idx);

  /*!
   * \brief resolve class record index by class name index in top namespace
   * \param a_name_idx - index of class name (in class_symbol_names)
   * \param a_class_idx - class record index of class from which search begins
   * \return index of class record, or c_idx_not_exist
   */
  unsigned get_topns_class_idx_by_name_idx(unsigned a_name_idx,unsigned a_class_idx);

  /*!
   * \brief resolve class record index by class name in top namespace
   * \param a_name - name of class to be resolved
   * \param a_class_idx - class record index of class from which search begins
   * \return index of class record, or c_idx_not_exist
   */
  inline unsigned get_topns_class_idx_by_name(const char *a_name,unsigned a_class_idx);

#if SYSTEM_TYPE != SYSTEM_TYPE_DSP
  void DEBUG_show_variables();
  void DEBUG_show_methods();
  void DEBUG_show_classes();
  void DEBUG_show_namespaces();

  void DEBUG_print_spaces(unsigned space_cnt);
  void DEBUG_show_expression(expression_s &exp);
  void DEBUG_show_flow_graph(exp_flow_graph_s &fg);
  void DEBUG_show_method_flow_graphs();
  void DEBUG_show_init_expressions();

  void DEBUG_show_dot_format_expression(expression_s &exp);
  void DEBUG_show_dot_format_method_expressions();
  void DEBUG_show_dot_format_init_expressions();
  void DEBUG_show_dot_format_flow_graph(exp_flow_graph_s &fg);
  void DEBUG_show_dot_format_method_flow_graphs();
  void DEBUG_show_dot_format_class_inheritance();

  void DEBUG_print_instruction(uli **pptr);
  void DEBUG_show_static_im_code();
  void DEBUG_show_class_im_codes();
  void DEBUG_show_method_im_codes();

  void DEBUG_gen_ucl_description(FILE *a_file);
#endif

  /*!
   * \brief import module classes from pointed structures
   * \param a_module - pointer to build in module structure
   */
  bool import_module(built_in_module_s *a_module);

  /*!
   * \brief load module from shared library
   * \param a_file_name - name of module shared library file
   */
  bool load_module(const char *a_file_name);

  /*!
   * \brief initialize parser for parsing of other input string, creates description of built in classes, methods and variables
   * \param a_source - source of code to execute
   * \param a_mods_path - module import paths string
   */
  void initialize_parser(source_s &a_source,string_s &a_mods_path);

  /*!
   * \brief return index of next terminal symbol (token) in input source
   * \param input_idx - actual position in input string
   * \return index of recognized terminal (token)
   */
  unsigned recognize_terminal(unsigned &input_idx);

  /*!
   * \brief parse input string and keep parsed informations in its members
   * \param a_source_idx - index of source to be parsed
   */
  void parse_script(unsigned a_source_idx);

  /*!
   * \brief recursively process all imported modules
   */
  void process_modules();

  /*!
   * \brief finds extended classes
   */
  void extended_classes_search();

  /*!
   * \brief creates mapping arrays of methods, and variables for each class, count element usage of each class, separate static variables from classes, ...
   */
  void element_search();

  /*!
   * \brief generate intermediate code for one expression
   * \param begin_code - reference to array which contain begin code of method, or class initialization
   * \param code - reference to array containing code of method, or class initialization
   * \param exp - reference to expression tree
   * \return false if generation failed, otherwise returns true
   */
  bool generate_expression_intermediate_code(uli_array_s &begin_code,uli_array_s &code,expression_s &exp);

  /*!
   * \brief generate intermediate code for all methods, class initializations and static variables initializations
   */
  void generate_intermediate_code();

  /*!
   * process created error codes, and prints error messages to error output
   */
  void process_errors();
}

script_parser_s;
@end

// -- exception_s --
@begin
struct
    <
    unsigned:type
    unsigned:position
    pointer:obj_location
    lli_array_s:params
    >

    additions
{
  static exception_s *throw_exception(interpreter_thread_s &it,unsigned a_type,unsigned a_pos,location_s *obj_location_ptr);

  inline void print();
}

exception_s;
@end

// -- pointer_tree_s --
@begin
safe_rb_tree<pointer
pointer:it_ptr
unsigned:source_pos
>

additions
{
  inline bool unique_insert(pointer a_value);
}

pointer_tree_s;
@end

// -- pointer_map_s --
@begin
struct
    <
    pointer:key
    pointer:value
    >
    pointer_map_s;
@end

// -- pointer_map_tree_s --
@begin
safe_rb_tree<pointer_map_s
pointer:
it_ptr
unsigned:
source_pos
>
pointer_map_tree_s;
@end

// -- interpreter_thread_s --
@begin
struct
    <
    pointer_array_s:free_location_ptrs
    pointer_array_s:free_reference_ptrs

    pointer:interpreter_ptr
    pointer_array_s:data_stack

    pointer:thread_location
    pointer:blank_location
    pointer:exception_location
    >

    additions
{
  /*!
   * \brief return new location of interpreter_thread
   * \return pointer to new location
   */
  inline location_s *get_new_location_ptr();

  /*!
   * \brief return new reference to given location
   * \return pointer to new reference location
   */
  inline location_s *get_new_reference(location_s **src_location_ptr);

  /*!
   * \brief return new string of interpreter_thread
   * \return pointer to new string
   */
  inline string_s *get_new_string_ptr();

  /*!
   * \brief return new array of interpreter_thread
   * \return pointer to new array
   */
  inline pointer_array_s *get_new_array_ptr();

  /*!
   * \brief return new object of interpreter_thread
   * \return pointer to new object
   */
  inline pointer_array_s *get_new_object_ptr();

  /*!
   * \brief retrieve integer number from location pointer
   * \param location_ptr - pointer to source location
   * \param a_number - reference to target number variable
   * \return true if number was successfuly retrieved
   */
  inline bool retrieve_integer(location_s *location_ptr,long long int &a_number);

  /*!
   * \brief retrieve float number from location pointer
   * \param location_ptr - pointer to source location
   * \param a_number - reference to target number variable
   * \return true if number was successfuly retrieved
   */
  inline bool retrieve_float(location_s *location_ptr,double &a_number);

  /*!
   * \brief test value represented by location pointer
   * \param location_ptr - pointer to source location
   * \param a_result - reference to target bool variable
   * \return true if value was successfully tested
   */
  inline bool test_value(location_s *location_ptr,bool &a_result);

  /*!
   * \brief return location pointer (dereferencing references)
   * \return pointer to location
   */
  inline static location_s *get_location_value(pointer location_ptr);

  /*!
   * \brief return unsigned (location_s *) location from stack (dereferencing references)
   * \param stack_idx - position at stack
   * \return unsigned (location_s *) pointer to location
   */
  inline pointer &get_stack_value(unsigned stack_idx);

  /*!
   * \brief release all locations on stack from position stack_base
   * \param stack_base - position to which are locations released
   */
  void release_stack_from(unsigned stack_base);

  /*!
   * \brief test and release location and variable in it contained
   * \param location_ptr - pointer to location to test and release
   */
  inline void release_location_ptr(location_s *location_ptr);

  /*!
   * \brief release location and variable in it contained
   * \param location_ptr - pointer to location to release
   */
  void _release_location_ptr(location_s *location_ptr);

  /*!
   * \brief creates new object by calling its blank constructor
   * \param new_location - location to hold new object
   * \param code - pointer to code which describes properties of created object
   * \param parent_ptr - pointer to location which hold object parent object
   * \return true if creation succeed, otherwise return false
   */
  bool create_new_object_blank_constructor(location_s *new_location,uli *code);

  /*!
   * \brief find exception handler and run it
   * \return fg_idx or c_idx_not_exist if handler does not exist
   * \param start_fg_idx - index of method start flow graph index (defauts to c_idx_not_exist)
   */
  unsigned catch_exception(method_record_s &method_record,unsigned stack_base,unsigned fg_idx,unsigned start_fg_idx);

  /*!
   * \brief run code of specified method
   * \param method_record - reference to record of executed method
   * \param stack_base - base of stack used by this method
   * \param return_trg_idx - stack index of return value of method
   * \param start_fg_idx - index of method start flow graph index (defauts to c_idx_not_exist)
   */
  int run_method_code(method_record_s &method_record,unsigned stack_base,unsigned return_trg_idx,unsigned start_fg_idx = c_idx_not_exist);

  /*!
   * \brief run code of one expression
   * \param code - code pointing to actual executed instructions
   * \param stack_base - actual stack_base
   * \param return_value - pointer to position at which will be saved return value, if any exist
   * \return true if everything is ok, otherwise return false
   */
  inline bool run_expression_code(uli *code,unsigned stack_base,unsigned *return_value);

  /*!
   * \brief call method of obj_location and name identified by method_name_idx
   * \param code - method call code (first position, caller class idx)
   * \param stack_base - base of thread stack
   * \return true if everything is ok, otherwise return false
   */
  bool call_method(uli *code,unsigned stack_base);

  /*!
   * \brief if location is iterable return type of iterable
   * \param location_ptr - pointer to possible iterable location
   * \return type of iterable if location is iterable, c_idx_not_exist otherwise
   */
  inline unsigned get_iterable_type(location_s *location_ptr);

  /*!
   * \brief handle system signal identified by signal_number
   * \param signal_number - number of signal to be handled
   * \return true if operation was successfull
   */
  bool handle_signal(int signal_number);

  /*!
   * \brief release stored allocated locations, strings, arrays and objects
   */
  void free_variables_clear();
}

interpreter_thread_s;
@end

// -- interpreter_s --
@begin
struct
    <
    $// - code sources -
    source_array_s:sources

    $// - module libraries and pointers -
    dynlib_array_s:bi_module_libs
    pointer_array_s:bi_module_pointers

    $// - error, exception strings -
    string_array_s:error_strings

    $// - symbol names -
    string_rb_tree_s:class_symbol_names
    string_rb_tree_s:method_symbol_names
    string_rb_tree_s:variable_symbol_names

    $// - classes, methods and variables records -
    class_records_s:class_records
    method_records_s:method_records
    variable_records_s:variable_records

    $// - parsed information -
    bc_array_s:const_chars
    lli_rb_tree_s:const_ints
    bd_rb_tree_s:const_floats
    string_rb_tree_s:const_strings

    $// - graphs of program flow -
    flow_graphs_s:method_flow_graphs

    $// - count of static elements -
    unsigned:static_element_cnt

    $// - static code description -
    unsigned:stack_size
    uli_array_s:static_begin_code
    uli_array_s:static_run_time_code

    $// - constant and static variables -
    location_array_s:const_locations
    pointer_array_s:static_location_ptrs

    $// - signal handlers locations -
    pointer_array_s:signal_handler_locations

    $// - pointer to main interpreter thread -
    pointer:main_thread_ptr

    $// - count of running threads -
    atomic_s:thread_cnt

    $// - interpreter terminate flasg -
    atomic_s:terminate
    >

    additions
{
  /*!
   * \brief creates interpreter structures from script_parser
   * \param sp - reference to script parser with structures filed by parsing of source file
   */
  void create_from_script_parser(script_parser_s &sp);

  /*!
   * \brief create constant and static variable locations of interpreter
   */
  void create_constant_and_static_locations();

  /*!
   * \brief release constant and static locations of interpreter
   */
  void release_constant_and_static_locations();

#if SYSTEM_TYPE != SYSTEM_TYPE_DSP
  void DEBUG_print_const_locations();
#endif

  /*!
   * \brief print message based on given exception
   */
  void print_exception_message(exception_s &exception);

  /*!
   * \brief creates and execute desired method in new thread
   * \param p_thread - reference to parent thread to new thread
   * \param p_stack_base - base of parent thread stack
   * \param p_stack_trg - target for location describing new thread at parent thread stack
   * \param method_record - reference to method_record describing called method
   * \param param_cnt - count of parameters of called method
   * \param parms - pointer to locations of parameters at parent thread stack
   * \return true if no error occurred, otherwise return false
   */
  bool run_new_thread(interpreter_thread_s &p_thread,unsigned p_stack_base,unsigned p_stack_trg,method_record_s &method_record,unsigned param_cnt,uli *parms);

  /*!
   * \brief execute described method as first thread of interpreter
   * \param class_name - name of class containing method
   * \param method_name - name of method desired to run
   * \param argc - count of arguments given to interpreter
   * \param argv - pointer to array of string arguments given to  interpreter
   * \return thread (program) exit code
   */
  int run_main_thread(const char *class_name,const char *method_name,int argc,char **argv);
}

interpreter_s;
@end

/*
 * definitions of global functions
 */

// - script_parser global functions -

/*!
 * \brief print line of input source string, on which was error detected, and mark error position on it
 * \param source_string - reference to input source string
 * \param begin - position of error begin
 */
void print_error_show_line(string_s &source_string,unsigned begin);

/*!
 * \brief print input source string line, on which is char positioned
 * \param source_string - reference to input source string
 * \param char_pos - position of character in source input string
 */
void print_error_line(string_s &source_string,unsigned char_pos);

/*!
 * \brief print sequence of classes which contain given class
 * \param class_symbol_names - reference to names of classes
 * \param class_records - reference to class records
 * \param class_stack - work stack for class indexes
 * \param class_record_idx - index of investigating class
 */
void print_class_sequence(string_rb_tree_s &class_symbol_names,class_records_s &class_records,ui_array_s &class_stack,unsigned class_record_idx);

// - interpreter global functions -

/*!
 * \brief function starting new thread of interpreter
 * \param nt_start_info - structure describing thread, and executed method
 * \return pointer to returned value by executed method
 */
void *new_thread_function(void *nt_start_info);

/*
 * inline methods of generated structures
 */

// -- method_record_s --
@begin
inlines method_record_s
@end

// -- name_pos_array_s --
// -- ri_ep_array_s --
// -- idx_size_array_s --
@begin
inlines name_pos_array_s
@end

inline ri_ep_s &ri_ep_array_s::map_name(unsigned a_name_idx)
{/*{{{*/
  if (a_name_idx >= used) return *(ri_ep_s *)&c_blank_ri_ep;
  return data[a_name_idx];
}/*}}}*/

// -- try_fg_map_s --
@begin
inlines try_fg_map_s
@end

// -- try_fg_maps_s --
@begin
inlines try_fg_maps_s
@end

// -- namespace_record_s --
@begin
   inlines namespace_record_s
@end

// -- namespace_records_s --
@begin
   inlines namespace_records_s
@end

// -- class_record_s --
@begin
inlines class_record_s
@end

// -- class_records_s --
@begin
inlines class_records_s
@end

// -- method_records_s --
@begin
inlines method_records_s
@end

// -- variable_record_s --
@begin
inlines variable_record_s
@end

// -- variable_records_s --
@begin
inlines variable_records_s
@end

// -- expression_s --
// -- flow_graph_s --
@begin
inlines expression_s
@end

// -- expressions_s --
// -- flow_graphs_s --
@begin
inlines expressions_s
@end

// -- exp_flow_graph_s --
@begin
inlines exp_flow_graph_s
@end

// -- exp_flow_graphs_s --
@begin
inlines exp_flow_graphs_s
@end

// -- expression_descr_s --
@begin
inlines expression_descr_s
@end

// -- expression_descrs_s --
@begin
inlines expression_descrs_s
@end

// -- flow_graph_descr_s --
@begin
inlines flow_graph_descr_s
@end

// -- im_descr_s --
@begin
inlines im_descr_s
@end

// -- script_parser_s --
@begin
inlines script_parser_s
@end

inline unsigned script_parser_s::get_method_name_idx_swap(string_s &a_name)
{/*{{{*/
  unsigned name_idx = method_symbol_names.get_idx(a_name);

  if (name_idx == c_idx_not_exist)
  {
    return method_symbol_names.swap_insert(a_name);
  }

  return name_idx;
}/*}}}*/

inline unsigned script_parser_s::resolve_class_idx_by_name(const char *a_name,unsigned a_class_idx)
{/*{{{*/
  unsigned name_idx = class_symbol_names.get_idx_char_ptr(strlen(a_name),a_name);
  if (name_idx == c_idx_not_exist)
  {
    return c_idx_not_exist;
  }

  return resolve_class_idx_by_name_idx(name_idx,a_class_idx);
}/*}}}*/

inline unsigned script_parser_s::get_topns_class_idx_by_name(const char *a_name,unsigned a_class_idx)
{/*{{{*/
  unsigned name_idx = class_symbol_names.get_idx_char_ptr(strlen(a_name),a_name);
  if (name_idx == c_idx_not_exist)
  {
    return c_idx_not_exist;
  }

  return get_topns_class_idx_by_name_idx(name_idx,a_class_idx);
}/*}}}*/

@begin
include "parse_actions.h"
include "im_gen_actions.h"
include "instructions.h"
include "built_in.h"
@end

// -- exception_s --
@begin
inlines exception_s
@end

inline void exception_s::print()
{/*{{{*/
  printf("Exception");
}/*}}}*/

// -- pointer_tree_s --
@begin
inlines pointer_tree_s
@end

inline bool pointer_tree_s::unique_insert(pointer a_value)
{/*{{{*/
  unsigned new_node_idx = __get_new_index();

  if (!__binary_tree_insert(new_node_idx,a_value,true))
  {
    pointer_tree_s_node &new_node = data[new_node_idx];

    new_node.parent_idx = free_idx;
    free_idx = new_node_idx;

    new_node.valid = false;
    count--;

    return false;
  }

  __insert_operation(new_node_idx);

  data[new_node_idx].object = a_value;

  return true;
}/*}}}*/

inline int pointer_tree_s::__compare_value(pointer &a_first,pointer &a_second)
{/*{{{*/
  interpreter_thread_s &it = *((interpreter_thread_s *)it_ptr);

  long long int result;

  BIC_CALL_COMPARE(it,a_first,a_second,source_pos,return 0);

  return result;
}/*}}}*/

// -- pointer_map_s --
@begin
inlines pointer_map_s
@end

// -- pointer_map_tree_s --
@begin
inlines pointer_map_tree_s
@end

inline int pointer_map_tree_s::__compare_value(pointer_map_s &a_first,pointer_map_s &a_second)
{/*{{{*/
  interpreter_thread_s &it = *((interpreter_thread_s *)it_ptr);

  long long int result;

  BIC_CALL_COMPARE(it,a_first.key,a_second.key,source_pos,return 0);

  return result;
}/*}}}*/

// -- interpreter_thread_s --
@begin
inlines interpreter_thread_s
@end

inline location_s *interpreter_thread_s::get_new_location_ptr()
{/*{{{*/
  if (free_location_ptrs.used != 0)
  {
    return (location_s *)free_location_ptrs.pop();
  }

  return (location_s *)cmalloc(sizeof(location_s));
}/*}}}*/

inline location_s *interpreter_thread_s::get_new_reference(location_s **src_location_ptr)
{/*{{{*/
  if ((*src_location_ptr)->v_type == c_bi_reference)
  {
    (*src_location_ptr)->v_reference_cnt.atomic_inc();
    return *src_location_ptr;
  }
  else
  {
    pointer *reference_ptr;

    if (free_reference_ptrs.used != 0)
    {
      reference_ptr = (pointer *)free_reference_ptrs.pop();
    }
    else
    {
      reference_ptr = (pointer *)cmalloc(sizeof(pointer));
    }

    *reference_ptr = *src_location_ptr;

    location_s *ref_location = get_new_location_ptr();
    ref_location->v_type = c_bi_reference;
    ref_location->v_reference_cnt.atomic_set(2);
    ref_location->v_data_ptr = (basic_64b)reference_ptr;

    *src_location_ptr = ref_location;

    return ref_location;
  }
}/*}}}*/

inline string_s *interpreter_thread_s::get_new_string_ptr()
{/*{{{*/
  string_s *string_ptr = (string_s *)cmalloc(sizeof(string_s));
  string_ptr->init();

  return string_ptr;
}/*}}}*/

inline pointer_array_s *interpreter_thread_s::get_new_array_ptr()
{/*{{{*/
  pointer_array_s *pointer_array_ptr = (pointer_array_s *)cmalloc(sizeof(pointer_array_s));
  pointer_array_ptr->init();

  return pointer_array_ptr;
}/*}}}*/

inline pointer_array_s *interpreter_thread_s::get_new_object_ptr()
{/*{{{*/
  pointer_array_s *object_ptr = (pointer_array_s *)cmalloc(sizeof(pointer_array_s));
  object_ptr->init();

  return object_ptr;
}/*}}}*/

inline location_s *interpreter_thread_s::get_location_value(pointer location_ptr)
{/*{{{*/
  if (((location_s *)location_ptr)->v_type == c_bi_reference)
  {
    return (location_s *)*((pointer *)((location_s *)location_ptr)->v_data_ptr);
  }

  return (location_s *)location_ptr;
}/*}}}*/

inline bool interpreter_thread_s::run_expression_code(uli *code,unsigned stack_base,unsigned *return_value)
{/*{{{*/
  int ret_code;
  atomic_s &terminate = ((interpreter_s *)interpreter_ptr)->terminate;

  inst_params_s params = {this,&code,stack_base,return_value};
  do
  {
    ret_code = instruction_callers[*code](&params);

    // - test interpreter terminate flag -
    register int tc = terminate.counter;
    if (tc != 0)
    {
      throw tc;
    }
  }
  while(ret_code == c_run_return_code_OK);

  return ret_code == c_run_return_code_RETURN;
}/*}}}*/

inline unsigned interpreter_thread_s::get_iterable_type(location_s *location_ptr)
{/*{{{*/
  ui_array_s &mnri_map = ((interpreter_s *)interpreter_ptr)->class_records[location_ptr->v_type].mnri_map;

  // - test first_idx_0, next_idx_1, item_1 iterable -
  if (mnri_map[c_built_in_method_idxs[c_built_in_method_first_idx_0]] != c_idx_not_exist &&
      mnri_map[c_built_in_method_idxs[c_built_in_method_next_idx_1]] != c_idx_not_exist &&
      mnri_map[c_built_in_method_idxs[c_built_in_method_item_1]] != c_idx_not_exist)
  {
    return c_iter_first_idx_next_idx_item;
  }

  // - test next_item_0 iterable -
  if (mnri_map[c_built_in_method_idxs[c_built_in_method_next_item_0]] != c_idx_not_exist)
  {
    return c_iter_next_item;
  }

  return c_idx_not_exist;
}/*}}}*/

inline pointer &interpreter_thread_s::get_stack_value(unsigned stack_idx)
{/*{{{*/
  pointer &location = data_stack[stack_idx];

  if (((location_s *)location)->v_type == c_bi_reference)
  {
    return *((pointer *)((location_s *)location)->v_data_ptr);
  }

  return location;
}/*}}}*/

inline void interpreter_thread_s::release_location_ptr(location_s *location_ptr)
{/*{{{*/

  // - decrease and test reference counter -
  if (location_ptr->v_reference_cnt.atomic_dec_and_test())
  {
    // - call release location method -
    _release_location_ptr(location_ptr);
  }
}/*}}}*/

inline bool interpreter_thread_s::retrieve_integer(location_s *location_ptr,long long int &a_number)
{/*{{{*/
  switch (location_ptr->v_type)
  {
  case c_bi_class_char:
    a_number = (char)location_ptr->v_data_ptr;
    break;
  case c_bi_class_integer:
    a_number = (long long int)location_ptr->v_data_ptr;
    break;
  case c_bi_class_float:
    a_number = (long long int)*((double *)&location_ptr->v_data_ptr);
    break;

  default:
    return false;
  }

  return true;
}/*}}}*/

inline bool interpreter_thread_s::retrieve_float(location_s *location_ptr,double &a_number)
{/*{{{*/
  switch (location_ptr->v_type)
  {
  case c_bi_class_integer:
    a_number = (double)(long long int)location_ptr->v_data_ptr;
    break;
  case c_bi_class_float:
    a_number = *((double *)&location_ptr->v_data_ptr);
    break;

  default:
    return false;
  }

  return true;
}/*}}}*/

inline bool interpreter_thread_s::test_value(location_s *location_ptr,bool &a_result)
{/*{{{*/
  switch(location_ptr->v_type)
  {
  case c_bi_class_char:
    a_result = (((char)location_ptr->v_data_ptr) != 0);
    break;
  case c_bi_class_integer:
    a_result = (((long long int)location_ptr->v_data_ptr) != 0);
    break;
  case c_bi_class_float:
    a_result = (*((double *)&location_ptr->v_data_ptr) != 0.0);
    break;
  case c_bi_class_string:
    a_result = (((string_s *)location_ptr->v_data_ptr)->size > 1);
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// -- interpreter_s --
@begin
inlines interpreter_s
@end

#endif

