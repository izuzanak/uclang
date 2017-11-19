
#ifndef __GRAPH_MODULE_H
#define __GRAPH_MODULE_H

@begin
include "ucl_graph.h"
@end

// - GRAPH indexes of built in classes -
extern unsigned c_bi_class_graph;
extern unsigned c_bi_class_graph_vertex;
extern unsigned c_bi_class_graph_edge;
extern unsigned c_bi_class_subgraph;
extern unsigned c_bi_class_graph_paths;

// - GRAPH module -
extern built_in_module_s module;

// - GRAPH classes -
extern built_in_class_s *graph_classes[];

// - GRAPH error identifiers -
enum
{
  c_error_GRAPH_UNRECOGNIZED_GRAPH_TYPE = 0,
  c_error_GRAPH_EXPECTED_UNDIRECTED_GRAPH,
  c_error_GRAPH_EXPECTED_DIRECTED_GRAPH,

  c_error_GRAPH_GENERATE_CONNECTED_ERROR,
  c_error_GRAPH_SHORTEST_PATH_ERROR,
  c_error_GRAPH_BREADTH_FIRST_SEARCH_ERROR,
  c_error_GRAPH_DEPTH_FIRST_SEARCH_ERROR,
  c_error_GRAPH_STRONGLY_CONNECTED_COMPONENTS_ERROR,

  c_error_GRAPH_VERTEX_INDEX_INVALID,
  c_error_GRAPH_EDGE_INDEX_INVALID,

  c_error_GRAPH_SUBGRAPH_VERTEX_INDEX_INVALID,
  c_error_GRAPH_SUBGRAPH_EDGE_INDEX_INVALID,

  c_error_GRAPH_VERTEX_INDEX_EXPECTED_INTEGER,
  c_error_GRAPH_EDGE_INDEX_EXPECTED_INTEGER,
  c_error_GRAPH_VERTEX_REMOVE_ERROR_INCIDENT_EDGES,

  c_error_GRAPH_EDGE_VERTEX_NOT_INCIDENT,
};

// - GRAPH error strings -
extern const char *graph_error_strings[];

// - GRAPH initialize -
bool graph_initialize(script_parser_s &sp);

// - GRAPH print exception -
bool graph_print_exception(interpreter_s &it,exception_s &exception);

// - class GRAPH -
extern built_in_variable_s graph_variables[];
extern built_in_method_s graph_methods[];
extern built_in_class_s graph_class;

void bic_graph_consts(location_array_s &const_locations);
void bic_graph_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_graph_clear(interpreter_thread_s &it,location_s *location_ptr);
bool bic_graph_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack);
bool bic_graph_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos);

bool bic_graph_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_method_Graph_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_method_Graph_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_method_get_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

bool bic_graph_method_duplicate_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_method_subgraph_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_method_subgraph_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_method_generate_connected_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);

bool bic_graph_method_degree_sequence_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_method_minimum_spanning_tree_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_method_shortest_path_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_method_BFS_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_method_DFS_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_method_strongly_connected_components_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

bool bic_graph_method_is_weakly_connected_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_method_is_strongly_connected_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

bool bic_graph_method_vertex_add_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_method_vertex_remove_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_method_vertex_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_method_vertex_cnt_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_method_vertex_idxs_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_method_vertex_idxs_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_method_vertex_values_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);

bool bic_graph_method_edge_add_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_method_edge_remove_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_method_edge_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_method_edge_cnt_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_method_edge_idxs_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_method_edge_idxs_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_method_edge_values_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);

bool bic_graph_method_get_dot_code_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class GRAPH_VERTEX -
extern built_in_variable_s graph_vertex_variables[];
extern built_in_method_s graph_vertex_methods[];
extern built_in_class_s graph_vertex_class;

void bic_graph_vertex_consts(location_array_s &const_locations);
void bic_graph_vertex_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_graph_vertex_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_graph_vertex_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_vertex_method_index_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_vertex_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_vertex_method_degree_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_vertex_method_out_degree_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_vertex_method_in_degree_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_vertex_method_adjacent_idxs_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_vertex_method_incident_idxs_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_vertex_method_edge_idxs_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_vertex_method_out_idxs_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_vertex_method_in_idxs_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_vertex_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_vertex_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class GRAPH_EDGE -
extern built_in_variable_s graph_edge_variables[];
extern built_in_method_s graph_edge_methods[];
extern built_in_class_s graph_edge_class;

void bic_graph_edge_consts(location_array_s &const_locations);
void bic_graph_edge_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_graph_edge_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_graph_edge_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_edge_method_index_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_edge_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_edge_method_source_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_edge_method_target_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_edge_method_opposite_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_edge_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_edge_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class SUBGRAPH -
extern built_in_variable_s subgraph_variables[];
extern built_in_method_s subgraph_methods[];
extern built_in_class_s subgraph_class;

void bic_subgraph_consts(location_array_s &const_locations);
void bic_subgraph_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_subgraph_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_subgraph_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_subgraph_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_subgraph_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class GRAPH_PATHS -
extern built_in_variable_s graph_paths_variables[];
extern built_in_method_s graph_paths_methods[];
extern built_in_class_s graph_paths_class;

void bic_graph_paths_consts(location_array_s &const_locations);
void bic_graph_paths_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_graph_paths_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_graph_paths_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_paths_method_lengths_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_paths_method_source_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_paths_method_raw_paths_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_paths_method_path_to_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_paths_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_graph_paths_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

