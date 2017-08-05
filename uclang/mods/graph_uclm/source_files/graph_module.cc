
@begin
include "graph_module.h"
@end

// - GRAPH indexes of built in classes -
unsigned c_bi_class_graph = c_idx_not_exist;
unsigned c_bi_class_graph_vertex = c_idx_not_exist;
unsigned c_bi_class_graph_edge = c_idx_not_exist;
unsigned c_bi_class_subgraph = c_idx_not_exist;
unsigned c_bi_class_graph_paths = c_idx_not_exist;

// - GRAPH module -
built_in_module_s module =
{/*{{{*/
  5,                      // Class count
  graph_classes,          // Classes

  0,                      // Error base index
  16,                     // Error count
  graph_error_strings,    // Error strings

  graph_initialize,       // Initialize function
  graph_print_exception,  // Print exceptions function
};/*}}}*/

// - GRAPH classes -
built_in_class_s *graph_classes[] =
{/*{{{*/
  &graph_class,
  &graph_vertex_class,
  &graph_edge_class,
  &subgraph_class,
  &graph_paths_class,
};/*}}}*/

// - GRAPH error strings -
const char *graph_error_strings[] =
{/*{{{*/
  "error_GRAPH_UNRECOGNIZED_GRAPH_TYPE",
  "error_GRAPH_EXPECTED_UNDIRECTED_GRAPH",
  "error_GRAPH_EXPECTED_DIRECTED_GRAPH",
  "error_GRAPH_GENERATE_CONNECTED_ERROR",
  "error_GRAPH_SHORTEST_PATH_ERROR",
  "error_GRAPH_BREADTH_FIRST_SEARCH_ERROR",
  "error_GRAPH_DEPTH_FIRST_SEARCH_ERROR",
  "error_GRAPH_STRONGLY_CONNECTED_COMPONENTS_ERROR",
  "error_GRAPH_VERTEX_INDEX_INVALID",
  "error_GRAPH_EDGE_INDEX_INVALID",
  "error_GRAPH_SUBGRAPH_VERTEX_INDEX_INVALID",
  "error_GRAPH_SUBGRAPH_EDGE_INDEX_INVALID",
  "error_GRAPH_VERTEX_INDEX_EXPECTED_INTEGER",
  "error_GRAPH_EDGE_INDEX_EXPECTED_INTEGER",
  "error_GRAPH_VERTEX_REMOVE_ERROR_INCIDENT_EDGES",
  "error_GRAPH_EDGE_VERTEX_NOT_INCIDENT",
};/*}}}*/

// - GRAPH initialize -
bool graph_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize graph class identifier -
  c_bi_class_graph = class_base_idx++;

  // - initialize graph_vertex class identifier -
  c_bi_class_graph_vertex = class_base_idx++;

  // - initialize graph_edge class identifier -
  c_bi_class_graph_edge = class_base_idx++;

  // - initialize subgraph class identifier -
  c_bi_class_subgraph = class_base_idx++;

  // - initialize graph_paths class identifier -
  c_bi_class_graph_paths = class_base_idx++;

  return true;
}/*}}}*/

// - GRAPH print exception -
bool graph_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_GRAPH_UNRECOGNIZED_GRAPH_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUnrecognized type of graph\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GRAPH_EXPECTED_UNDIRECTED_GRAPH:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nOperation is expecting undirected graph\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GRAPH_EXPECTED_DIRECTED_GRAPH:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nOperation is expecting directed graph\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GRAPH_GENERATE_CONNECTED_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while generating connected graph\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GRAPH_SHORTEST_PATH_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while searching for shortest path in graph\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GRAPH_BREADTH_FIRST_SEARCH_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while executing BFS on graph\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GRAPH_DEPTH_FIRST_SEARCH_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while executing DFS on graph\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GRAPH_STRONGLY_CONNECTED_COMPONENTS_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while searching for strongly connected components\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GRAPH_VERTEX_INDEX_INVALID:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid graph vertex index %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GRAPH_EDGE_INDEX_INVALID:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid graph edge index %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GRAPH_SUBGRAPH_VERTEX_INDEX_INVALID:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid subgraph vertex index %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GRAPH_SUBGRAPH_EDGE_INDEX_INVALID:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid subgraph edge index %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GRAPH_VERTEX_INDEX_EXPECTED_INTEGER:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInteger is expected as graph vertex index\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GRAPH_EDGE_INDEX_EXPECTED_INTEGER:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInteger is expected as graph edge index\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GRAPH_VERTEX_REMOVE_ERROR_INCIDENT_EDGES:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot remove vertex, there are incident edges on it\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_GRAPH_EDGE_VERTEX_NOT_INCIDENT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nEdge is not incident on vertex %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class GRAPH -
built_in_class_s graph_class =
{/*{{{*/
  "Graph",
  c_modifier_public | c_modifier_final,
  33, graph_methods,
  2, graph_variables,
  bic_graph_consts,
  bic_graph_init,
  bic_graph_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  bic_graph_pack,
  bic_graph_unpack,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s graph_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_graph_operator_binary_equal
  },
  {
    "Graph#0",
    c_modifier_public | c_modifier_final,
    bic_graph_method_Graph_0
  },
  {
    "Graph#1",
    c_modifier_public | c_modifier_final,
    bic_graph_method_Graph_1
  },
  {
    "get_type#0",
    c_modifier_public | c_modifier_final,
    bic_graph_method_get_type_0
  },
  {
    "duplicate#0",
    c_modifier_public | c_modifier_final,
    bic_graph_method_duplicate_0
  },
  {
    "subgraph#1",
    c_modifier_public | c_modifier_final,
    bic_graph_method_subgraph_1
  },
  {
    "subgraph#2",
    c_modifier_public | c_modifier_final,
    bic_graph_method_subgraph_2
  },
  {
    "generate_connected#3",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_graph_method_generate_connected_3
  },
  {
    "degree_sequence#0",
    c_modifier_public | c_modifier_final,
    bic_graph_method_degree_sequence_0
  },
  {
    "minimum_spanning_tree#0",
    c_modifier_public | c_modifier_final,
    bic_graph_method_minimum_spanning_tree_0
  },
  {
    "shortest_path#2",
    c_modifier_public | c_modifier_final,
    bic_graph_method_shortest_path_2
  },
  {
    "BFS#2",
    c_modifier_public | c_modifier_final,
    bic_graph_method_BFS_2
  },
  {
    "DFS#2",
    c_modifier_public | c_modifier_final,
    bic_graph_method_DFS_2
  },
  {
    "strongly_connected_components#0",
    c_modifier_public | c_modifier_final,
    bic_graph_method_strongly_connected_components_0
  },
  {
    "is_weakly_connected#0",
    c_modifier_public | c_modifier_final,
    bic_graph_method_is_weakly_connected_0
  },
  {
    "is_strongly_connected#0",
    c_modifier_public | c_modifier_final,
    bic_graph_method_is_strongly_connected_0
  },
  {
    "vertex_add#1",
    c_modifier_public | c_modifier_final,
    bic_graph_method_vertex_add_1
  },
  {
    "vertex_remove#1",
    c_modifier_public | c_modifier_final,
    bic_graph_method_vertex_remove_1
  },
  {
    "vertex#1",
    c_modifier_public | c_modifier_final,
    bic_graph_method_vertex_1
  },
  {
    "vertex_cnt#0",
    c_modifier_public | c_modifier_final,
    bic_graph_method_vertex_cnt_0
  },
  {
    "vertex_idxs#0",
    c_modifier_public | c_modifier_final,
    bic_graph_method_vertex_idxs_0
  },
  {
    "vertex_idxs#1",
    c_modifier_public | c_modifier_final,
    bic_graph_method_vertex_idxs_1
  },
  {
    "vertex_values#1",
    c_modifier_public | c_modifier_final,
    bic_graph_method_vertex_values_1
  },
  {
    "edge_add#3",
    c_modifier_public | c_modifier_final,
    bic_graph_method_edge_add_3
  },
  {
    "edge_remove#1",
    c_modifier_public | c_modifier_final,
    bic_graph_method_edge_remove_1
  },
  {
    "edge#1",
    c_modifier_public | c_modifier_final,
    bic_graph_method_edge_1
  },
  {
    "edge_cnt#0",
    c_modifier_public | c_modifier_final,
    bic_graph_method_edge_cnt_0
  },
  {
    "edge_idxs#0",
    c_modifier_public | c_modifier_final,
    bic_graph_method_edge_idxs_0
  },
  {
    "edge_idxs#1",
    c_modifier_public | c_modifier_final,
    bic_graph_method_edge_idxs_1
  },
  {
    "edge_values#1",
    c_modifier_public | c_modifier_final,
    bic_graph_method_edge_values_1
  },
  {
    "get_dot_code#0",
    c_modifier_public | c_modifier_final,
    bic_graph_method_get_dot_code_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_graph_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_graph_method_print_0
  },
};/*}}}*/

built_in_variable_s graph_variables[] =
{/*{{{*/
  {
    "TYPE_GRAPH",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "TYPE_DIGRAPH",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
};/*}}}*/

void bic_graph_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert graph type constants -
  {
    const_locations.push_blanks(2);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 2);

#define CREATE_GRAPH_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_GRAPH_TYPE_BIC_STATIC(c_graph_type_graph);
    CREATE_GRAPH_TYPE_BIC_STATIC(c_graph_type_digraph);
  }
}/*}}}*/

void bic_graph_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  graph_s *graph_ptr = (graph_s *)cmalloc(sizeof(graph_s));
  graph_ptr->init();

  location_ptr->v_data_ptr = (graph_s *)graph_ptr;
}/*}}}*/

void bic_graph_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  graph_s *graph_ptr = (graph_s *)location_ptr->v_data_ptr;
  graph_ptr->ucl_prepare(it,0);

  graph_ptr->clear();
  cfree(graph_ptr);
}/*}}}*/

bool bic_graph_pack(location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack)
{/*{{{*/
  graph_s *graph_ptr = (graph_s *)location_ptr->v_data_ptr;
  vertex_rb_tree_s &vertices = graph_ptr->vertices;
  edge_rb_tree_s &edges = graph_ptr->edges;

  pointer *v_locations = (pointer *)cmalloc(vertices.count*sizeof(pointer));
  unsigned *v_idx_to_v_pos = (unsigned *)cmalloc(vertices.used*sizeof(unsigned));

  // - process graph vertices -
  if (vertices.root_idx != c_idx_not_exist)
  {
    unsigned stack[vertices.get_descent_stack_size()];
    unsigned *stack_ptr = stack;

    unsigned v_pos = 0;
    unsigned v_idx = vertices.get_stack_min_value_idx(vertices.root_idx,&stack_ptr);
    do
    {
      v_locations[v_pos] = vertices[v_idx].value;
      v_idx_to_v_pos[v_idx] = v_pos++;

      v_idx = vertices.get_stack_next_idx(v_idx,&stack_ptr,stack);
    }
    while(v_idx != c_idx_not_exist);
  }

  // - process graph edges -
  if (edges.root_idx != c_idx_not_exist)
  {
    unsigned stack[edges.get_descent_stack_size()];
    unsigned *stack_ptr = stack;

    unsigned e_idx = edges.get_stack_min_value_idx(edges.root_idx,&stack_ptr);
    do
    {
      edge_s &edge = edges[e_idx];

      stream.append(sizeof(unsigned),(const char *)&v_idx_to_v_pos[edge.trg_vertex_idx]);
      stream.append(sizeof(unsigned),(const char *)&v_idx_to_v_pos[edge.src_vertex_idx]);

      loc_stack.push(edge.value);

      e_idx = edges.get_stack_next_idx(e_idx,&stack_ptr,stack);
    }
    while(e_idx != c_idx_not_exist);
  }

  // - append vertex locations -
  if (vertices.root_idx != c_idx_not_exist)
  {
    pointer *vl_ptr = v_locations;
    pointer *vl_ptr_end = vl_ptr + vertices.count;
    do
    {
      loc_stack.push(*vl_ptr);
    }
    while(++vl_ptr < vl_ptr_end);
  }

  cfree(v_idx_to_v_pos);
  cfree(v_locations);

  stream.append(sizeof(unsigned),(const char *)&edges.count);
  stream.append(sizeof(unsigned),(const char *)&vertices.count);
  stream.append(sizeof(unsigned),(const char *)&graph_ptr->type);

  return true;
}/*}}}*/

bool bic_graph_unpack(interpreter_thread_s &it,location_s *location_ptr,bc_array_s &stream,pointer_array_s &loc_stack,bool order_bytes,unsigned source_pos)
{/*{{{*/
  graph_s *graph_ptr = (graph_s *)cmalloc(sizeof(graph_s));
  graph_ptr->init();
  graph_ptr->ucl_prepare(it,source_pos);

  location_ptr->v_data_ptr = (graph_s *)graph_ptr;

  if (stream.used < 3*sizeof(unsigned))
  {
    return false;
  }

  unsigned vertex_cnt;
  unsigned edge_cnt;

  stream.from_end(sizeof(unsigned),(char *)&graph_ptr->type,order_bytes);
  stream.from_end(sizeof(unsigned),(char *)&vertex_cnt,order_bytes);
  stream.from_end(sizeof(unsigned),(char *)&edge_cnt,order_bytes);

  if (loc_stack.used < (vertex_cnt + edge_cnt))
  {
    return false;
  }

  unsigned *v_pos_to_v_idx = (unsigned *)cmalloc(vertex_cnt*sizeof(unsigned));

  // - process vertices -
  if (vertex_cnt > 0)
  {
    unsigned v_pos = vertex_cnt;
    do {

      location_s *value_location = (location_s *)loc_stack.pop();

      // - insert vertex to graph -
      v_pos_to_v_idx[--v_pos] = graph_ptr->insert_vertex(value_location);

      // - release value location -
      it.release_location_ptr(value_location);

      if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
      {
        cfree(v_pos_to_v_idx);

        return false;
      }

    } while(v_pos > 0);
  }

  // - process edges -
  if (edge_cnt > 0)
  {
    unsigned e_pos = 0;
    do {

      if (stream.used < (sizeof(unsigned) << 1))
      {
        cfree(v_pos_to_v_idx);

        return false;
      }

      unsigned src_v_pos;
      unsigned trg_v_pos;

      stream.from_end(sizeof(unsigned),(char *)&src_v_pos,order_bytes);
      stream.from_end(sizeof(unsigned),(char *)&trg_v_pos,order_bytes);

      location_s *value_location = (location_s *)loc_stack.pop();

      // - insert edge to graph -
      graph_ptr->insert_edge(v_pos_to_v_idx[src_v_pos],v_pos_to_v_idx[trg_v_pos],value_location);

      // - release value location -
      it.release_location_ptr(value_location);

      if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
      {
        cfree(v_pos_to_v_idx);

        return false;
      }

    } while(++e_pos < edge_cnt);
  }

  cfree(v_pos_to_v_idx);

  return true;
}/*}}}*/

bool bic_graph_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_graph_method_Graph_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  return true;
}/*}}}*/

bool bic_graph_method_Graph_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  graph_s *graph_ptr = (graph_s *)dst_location->v_data_ptr;
  graph_ptr->ucl_prepare(it,operands[c_source_pos_idx]);

  long long int graph_type;

  if (!it.retrieve_integer(src_0_location,graph_type))
  {
    // - ERROR -
    if (src_0_location->v_type != c_bi_class_subgraph)
    {
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
      BIC_EXCEPTION_PUSH_METHOD_RI("Graph#1");
      new_exception->params.push(1);
      new_exception->params.push(src_0_location->v_type);

      return false;
    }

    // - retrieve subgraph pointer -
    subgraph_s *sg_ptr = (subgraph_s *)src_0_location->v_data_ptr;
    ui_array_s &sg_vertex_idxs = sg_ptr->vertex_idxs;
    ui_array_s &sg_edge_idxs = sg_ptr->edge_idxs;

    // - retrieve host graph pointer -
    graph_s *hg_ptr = (graph_s *)((location_s *)sg_ptr->graph_ptr)->v_data_ptr;
    vertex_rb_tree_s &hg_vertices = hg_ptr->vertices;
    edge_rb_tree_s &hg_edges = hg_ptr->edges;

    // - initialize graph type from host graph -
    graph_ptr->type = hg_ptr->type;

    unsigned *v_hg_to_g_map = (unsigned *)cmalloc(hg_vertices.used*sizeof(unsigned));
    memset(v_hg_to_g_map,c_idx_not_exist,hg_vertices.used*sizeof(unsigned));

    if (sg_vertex_idxs.used != 0)
    {
      unsigned *sgvi_ptr = sg_vertex_idxs.data;
      unsigned *sgvi_ptr_end = sgvi_ptr + sg_vertex_idxs.used;
      do {

        // - ERROR -
        if (!hg_ptr->ucl_check_vertex_idx(*sgvi_ptr))
        {
          cfree(v_hg_to_g_map);

          exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GRAPH_SUBGRAPH_VERTEX_INDEX_INVALID,operands[c_source_pos_idx],(location_s *)it.blank_location);
          new_exception->params.push(*sgvi_ptr);

          return false;
        }

        // - insert vertex to graph -
        v_hg_to_g_map[*sgvi_ptr] = graph_ptr->insert_vertex(hg_vertices[*sgvi_ptr].value);

      } while(++sgvi_ptr < sgvi_ptr_end);
    }

    if (sg_edge_idxs.used != 0)
    {
      unsigned *sgei_ptr = sg_edge_idxs.data;
      unsigned *sgei_ptr_end = sgei_ptr + sg_edge_idxs.used;
      do {

        // - ERROR -
        if (!hg_ptr->ucl_check_edge_idx(*sgei_ptr))
        {
          cfree(v_hg_to_g_map);

          exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GRAPH_SUBGRAPH_EDGE_INDEX_INVALID,operands[c_source_pos_idx],(location_s *)it.blank_location);
          new_exception->params.push(*sgei_ptr);

          return false;
        }

        edge_s &edge = hg_edges[*sgei_ptr];

        // - references to vertex host graph to graph map values -
        unsigned &v_src_hg_to_g = v_hg_to_g_map[edge.src_vertex_idx];
        unsigned &v_trg_hg_to_g = v_hg_to_g_map[edge.trg_vertex_idx];

        // - insert source vertex to graph -
        if (v_src_hg_to_g == c_idx_not_exist)
        {
          v_src_hg_to_g = graph_ptr->insert_vertex(hg_vertices[edge.src_vertex_idx].value);
        }

        // - insert target vertex to graph -
        if (v_trg_hg_to_g == c_idx_not_exist)
        {
          v_trg_hg_to_g = graph_ptr->insert_vertex(hg_vertices[edge.trg_vertex_idx].value);
        }

        // - insert edge to graph -
        graph_ptr->insert_edge(v_src_hg_to_g,v_trg_hg_to_g,edge.value);

      } while(++sgei_ptr < sgei_ptr_end);
    }

    cfree(v_hg_to_g_map);

    return true;
  }

  switch (graph_type)
  {
  case c_graph_type_graph:
  case c_graph_type_digraph:
    break;

  // - ERROR -
  default:

    exception_s::throw_exception(it,module.error_base + c_error_GRAPH_UNRECOGNIZED_GRAPH_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set graph type -
  graph_ptr->type = graph_type;

  return true;
}/*}}}*/

bool bic_graph_method_get_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  graph_s *graph_ptr = (graph_s *)dst_location->v_data_ptr;

  long long int result = graph_ptr->type;

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_graph_method_duplicate_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  graph_s *graph_ptr = (graph_s *)dst_location->v_data_ptr;

  // - create graph object -
  graph_s *dup_graph_ptr = (graph_s *)cmalloc(sizeof(graph_s));
  dup_graph_ptr->init();
  dup_graph_ptr->ucl_prepare(it,operands[c_source_pos_idx]);

  // - duplicate graph -
  dup_graph_ptr->duplicate(*graph_ptr);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_graph,dup_graph_ptr);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_graph_method_subgraph_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_array)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("subgraph#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  graph_s *graph_ptr = (graph_s *)((location_s *)dst_location)->v_data_ptr;

  bool *e_used = (bool *)cmalloc(graph_ptr->edges.used*sizeof(bool));
  memset(e_used,false,graph_ptr->edges.used*sizeof(bool));

  ui_array_s edge_idxs;
  edge_idxs.init();

  pointer_array_s *edge_array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

  if (edge_array_ptr->used > 0)
  {
    pointer *ep_ptr = edge_array_ptr->data;
    pointer *ep_ptr_end = ep_ptr + edge_array_ptr->used;
    do {
      location_s *item_location = it.get_location_value(*ep_ptr);

      // - ERROR -
      if (item_location->v_type != c_bi_class_integer)
      {
        cfree(e_used);
        edge_idxs.clear();

        exception_s::throw_exception(it,module.error_base + c_error_GRAPH_EDGE_INDEX_EXPECTED_INTEGER,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      long long int edge_idx = (long long int)item_location->v_data_ptr;

      // - ERROR -
      if (!graph_ptr->ucl_check_edge_idx(edge_idx))
      {
        cfree(e_used);
        edge_idxs.clear();

        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GRAPH_EDGE_INDEX_INVALID,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(edge_idx);

        return false;
      }

      if (!e_used[edge_idx])
      {
        // - push index to subgraph edge list -
        edge_idxs.push(edge_idx);
        e_used[edge_idx] = true;
      }

    } while(++ep_ptr < ep_ptr_end);
  }

  cfree(e_used);

  // - create subgraph object -
  subgraph_s *sg_ptr = (subgraph_s *)cmalloc(sizeof(subgraph_s));
  sg_ptr->init();

  // - swap edge indexes -
  sg_ptr->edge_idxs.swap(edge_idxs);
  edge_idxs.clear();

  // - create reference to graph -
  dst_location->v_reference_cnt.atomic_inc();
  sg_ptr->graph_ptr = dst_location;

  // - create result location -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_subgraph,sg_ptr);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_graph_method_subgraph_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_array ||
      src_1_location->v_type != c_bi_class_array)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("subgraph#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  graph_s *graph_ptr = (graph_s *)((location_s *)dst_location)->v_data_ptr;

  bool *v_used = (bool *)cmalloc(graph_ptr->vertices.used*sizeof(bool));
  memset(v_used,false,graph_ptr->vertices.used*sizeof(bool));

  bool *e_used = (bool *)cmalloc(graph_ptr->edges.used*sizeof(bool));
  memset(e_used,false,graph_ptr->edges.used*sizeof(bool));

  ui_array_s vertex_idxs;
  vertex_idxs.init();

  ui_array_s edge_idxs;
  edge_idxs.init();

#define BIC_GRAPH_METHOD_SUBGRAPH_2_CLEAR() \
{/*{{{*/\
  cfree(v_used);\
  cfree(e_used);\
\
  vertex_idxs.clear();\
  edge_idxs.clear();\
}/*}}}*/

  pointer_array_s *vertex_array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

  if (vertex_array_ptr->used > 0)
  {
    pointer *vp_ptr = vertex_array_ptr->data;
    pointer *vp_ptr_end = vp_ptr + vertex_array_ptr->used;
    do {
      location_s *item_location = it.get_location_value(*vp_ptr);

      // - ERROR -
      if (item_location->v_type != c_bi_class_integer)
      {
        BIC_GRAPH_METHOD_SUBGRAPH_2_CLEAR();

        exception_s::throw_exception(it,module.error_base + c_error_GRAPH_VERTEX_INDEX_EXPECTED_INTEGER,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      long long int vertex_idx = (long long int)item_location->v_data_ptr;

      // - ERROR -
      if (!graph_ptr->ucl_check_vertex_idx(vertex_idx))
      {
        BIC_GRAPH_METHOD_SUBGRAPH_2_CLEAR();

        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GRAPH_VERTEX_INDEX_INVALID,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(vertex_idx);

        return false;
      }

      if (!v_used[vertex_idx])
      {
        // - push index to subgraph vertex list -
        vertex_idxs.push(vertex_idx);
        v_used[vertex_idx] = true;
      }
    } while(++vp_ptr < vp_ptr_end);
  }

  pointer_array_s *edge_array_ptr = (pointer_array_s *)src_1_location->v_data_ptr;

  if (edge_array_ptr->used > 0)
  {
    pointer *ep_ptr = edge_array_ptr->data;
    pointer *ep_ptr_end = ep_ptr + edge_array_ptr->used;
    do {
      location_s *item_location = it.get_location_value(*ep_ptr);

      // - ERROR -
      if (item_location->v_type != c_bi_class_integer)
      {
        BIC_GRAPH_METHOD_SUBGRAPH_2_CLEAR();

        exception_s::throw_exception(it,module.error_base + c_error_GRAPH_EDGE_INDEX_EXPECTED_INTEGER,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      long long int edge_idx = (long long int)item_location->v_data_ptr;

      // - ERROR -
      if (!graph_ptr->ucl_check_edge_idx(edge_idx))
      {
        BIC_GRAPH_METHOD_SUBGRAPH_2_CLEAR();

        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GRAPH_EDGE_INDEX_INVALID,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(edge_idx);

        return false;
      }

      if (!e_used[edge_idx])
      {
        // - push index to subgraph edge list -
        edge_idxs.push(edge_idx);
        e_used[edge_idx] = true;
      }

    } while(++ep_ptr < ep_ptr_end);
  }

  cfree(v_used);
  cfree(e_used);

  // - create subgraph object -
  subgraph_s *sg_ptr = (subgraph_s *)cmalloc(sizeof(subgraph_s));
  sg_ptr->init();

  // - swap vertex and edge indexes -
  sg_ptr->vertex_idxs.swap(vertex_idxs);
  sg_ptr->edge_idxs.swap(edge_idxs);

  vertex_idxs.clear();
  edge_idxs.clear();

  // - create reference to graph -
  dst_location->v_reference_cnt.atomic_inc();
  sg_ptr->graph_ptr = dst_location;

  // - create result location -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_subgraph,sg_ptr);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_graph_method_generate_connected_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);

  long long int vertex_cnt;
  long long int edge_cnt;
  long long int graph_type;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,vertex_cnt) ||
      !it.retrieve_integer(src_1_location,edge_cnt) ||
      !it.retrieve_integer(src_2_location,graph_type))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_graph,"generate_connected#3");
    new_exception->params.push(3);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);

    return false;
  }

  graph_s *graph_ptr = (graph_s *)cmalloc(sizeof(graph_s));
  graph_ptr->init();
  graph_ptr->ucl_prepare(it,operands[c_source_pos_idx]);

  // - ERROR -
  if (!graph_ptr->generate_connected(vertex_cnt,edge_cnt,graph_type))
  {
    graph_ptr->clear();
    cfree(graph_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_GRAPH_GENERATE_CONNECTED_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
  {
    return false;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_graph,graph_ptr);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_graph_method_degree_sequence_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  graph_s *graph_ptr = (graph_s *)dst_location->v_data_ptr;

  ui_array_s degree_sequence;
  degree_sequence.init();

  // - retrieve graph degree sequence -
  graph_ptr->degree_sequence(degree_sequence);

  // - create target array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  if (degree_sequence.used != 0)
  {
    unsigned *ptr = degree_sequence.data;
    unsigned *ptr_end = ptr + degree_sequence.used;
    do {
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,*ptr);
      array_ptr->push(new_location);
    } while(++ptr < ptr_end);
  }


  degree_sequence.clear();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_graph_method_minimum_spanning_tree_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  graph_s *graph_ptr = (graph_s *)((location_s *)dst_location)->v_data_ptr;

  ui_array_s edge_idxs;
  edge_idxs.init();

  if (graph_ptr->minimum_spanning_tree_kruskals(edge_idxs))
  {
    // - create subgraph object -
    subgraph_s *sg_ptr = (subgraph_s *)cmalloc(sizeof(subgraph_s));
    sg_ptr->init();

    // - swap edge indexes -
    sg_ptr->edge_idxs.swap(edge_idxs);

    // - create reference to graph -
    dst_location->v_reference_cnt.atomic_inc();
    sg_ptr->graph_ptr = dst_location;

    // - create result location -
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_subgraph,sg_ptr);

    pointer &res_location = it.data_stack[res_loc_idx];
    BIC_SET_RESULT(new_location);
  }
  else
  {
    pointer &res_location = it.data_stack[res_loc_idx];
    BIC_SET_RESULT_BLANK();
  }

  edge_idxs.clear();

  return true;
}/*}}}*/

bool bic_graph_method_shortest_path_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int src_vertex_idx;
  long long int trg_vertex_idx;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,src_vertex_idx) ||
      !it.retrieve_integer(src_1_location,trg_vertex_idx))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("shortest_path#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  graph_s *graph_ptr = (graph_s *)((location_s *)dst_location)->v_data_ptr;
  graph_ptr->ucl_prepare(it,operands[c_source_pos_idx]);

  // - ERROR -
  if (!graph_ptr->ucl_check_vertex_idx(src_vertex_idx))
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GRAPH_VERTEX_INDEX_INVALID,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(src_vertex_idx);

    return false;
  }

  // - adjust target vertex index -
  if (trg_vertex_idx == -1)
  {
    trg_vertex_idx = c_idx_not_exist;
  }

  // - create lengths array and its location -
  pointer_array_s *lengths_ptr = it.get_new_array_ptr();
  BIC_CREATE_NEW_LOCATION(lengths_location,c_bi_class_array,lengths_ptr);

  // - edge indexes array -
  ui_array_s edge_idxs;
  edge_idxs.init();

  switch (graph_ptr->type)
  {
  case c_graph_type_graph:
    {
      // - ERROR -
      if (!graph_ptr->shortest_path_graph_dijkstra(src_vertex_idx,trg_vertex_idx,*lengths_ptr,edge_idxs))
      {
        it.release_location_ptr(lengths_location);
        edge_idxs.clear();

        exception_s::throw_exception(it,module.error_base + c_error_GRAPH_SHORTEST_PATH_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }
    }
    break;

  case c_graph_type_digraph:
    {
      // - ERROR -
      if (!graph_ptr->shortest_path_digraph_dijkstra(src_vertex_idx,trg_vertex_idx,*lengths_ptr,edge_idxs))
      {
        it.release_location_ptr(lengths_location);
        edge_idxs.clear();

        exception_s::throw_exception(it,module.error_base + c_error_GRAPH_SHORTEST_PATH_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }
    }
    break;

  // - ERROR -
  default:

    it.release_location_ptr(lengths_location);
    edge_idxs.clear();

    exception_s::throw_exception(it,module.error_base + c_error_GRAPH_UNRECOGNIZED_GRAPH_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create graph paths object -
  graph_paths_s *gp_ptr = (graph_paths_s *)cmalloc(sizeof(graph_paths_s));
  gp_ptr->init();

  // - create reference to graph -
  dst_location->v_reference_cnt.atomic_inc();
  gp_ptr->graph_ptr = dst_location;

  // - set graph paths lengths -
  gp_ptr->lengths_arr = lengths_location;

  // - set source vertex index -
  gp_ptr->src_vertex_idx = src_vertex_idx;

  // - swap edge indexes -
  gp_ptr->edge_idxs.swap(edge_idxs);
  edge_idxs.clear();

  // - create result location -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_graph_paths,gp_ptr);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_graph_method_BFS_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int src_vertex_idx;
  long long int trg_vertex_idx;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,src_vertex_idx) ||
      !it.retrieve_integer(src_1_location,trg_vertex_idx))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("BFS#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  graph_s *graph_ptr = (graph_s *)((location_s *)dst_location)->v_data_ptr;

  // - ERROR -
  if (!graph_ptr->ucl_check_vertex_idx(src_vertex_idx))
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GRAPH_VERTEX_INDEX_INVALID,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(src_vertex_idx);

    return false;
  }

  // - adjust target vertex index -
  if (trg_vertex_idx == -1)
  {
    trg_vertex_idx = c_idx_not_exist;
  }

  ui_array_s edge_idxs;
  edge_idxs.init();

  switch (graph_ptr->type)
  {
  case c_graph_type_graph:
    {
      // - ERROR -
      if (!graph_ptr->BFS_graph(src_vertex_idx,trg_vertex_idx,edge_idxs))
      {
        edge_idxs.clear();

        exception_s::throw_exception(it,module.error_base + c_error_GRAPH_BREADTH_FIRST_SEARCH_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }
    }
    break;

  case c_graph_type_digraph:
    {
      // - ERROR -
      if (!graph_ptr->BFS_digraph(src_vertex_idx,trg_vertex_idx,edge_idxs))
      {
        edge_idxs.clear();

        exception_s::throw_exception(it,module.error_base + c_error_GRAPH_BREADTH_FIRST_SEARCH_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }
    }
    break;

  // - ERROR -
  default:

    edge_idxs.clear();

    exception_s::throw_exception(it,module.error_base + c_error_GRAPH_UNRECOGNIZED_GRAPH_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create subgraph object -
  subgraph_s *sg_ptr = (subgraph_s *)cmalloc(sizeof(subgraph_s));
  sg_ptr->init();

  // - swap edge indexes -
  sg_ptr->edge_idxs.swap(edge_idxs);
  edge_idxs.clear();

  // - create reference to graph -
  dst_location->v_reference_cnt.atomic_inc();
  sg_ptr->graph_ptr = dst_location;

  // - create result location -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_subgraph,sg_ptr);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_graph_method_DFS_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int src_vertex_idx;
  long long int trg_vertex_idx;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,src_vertex_idx) ||
      !it.retrieve_integer(src_1_location,trg_vertex_idx))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("DFS#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  graph_s *graph_ptr = (graph_s *)((location_s *)dst_location)->v_data_ptr;

  // - ERROR -
  if (!graph_ptr->ucl_check_vertex_idx(src_vertex_idx))
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GRAPH_VERTEX_INDEX_INVALID,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(src_vertex_idx);

    return false;
  }

  // - adjust target vertex index -
  if (trg_vertex_idx == -1)
  {
    trg_vertex_idx = c_idx_not_exist;
  }

  ui_array_s edge_idxs;
  edge_idxs.init();

  switch (graph_ptr->type)
  {
  case c_graph_type_graph:
    {
      // - ERROR -
      if (!graph_ptr->DFS_graph(src_vertex_idx,trg_vertex_idx,edge_idxs))
      {
        edge_idxs.clear();

        exception_s::throw_exception(it,module.error_base + c_error_GRAPH_DEPTH_FIRST_SEARCH_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }
    }
    break;

  case c_graph_type_digraph:
    {
      // - ERROR -
      if (!graph_ptr->DFS_digraph(src_vertex_idx,trg_vertex_idx,edge_idxs))
      {
        edge_idxs.clear();

        exception_s::throw_exception(it,module.error_base + c_error_GRAPH_DEPTH_FIRST_SEARCH_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }
    }
    break;

  // - ERROR -
  default:

    edge_idxs.clear();

    exception_s::throw_exception(it,module.error_base + c_error_GRAPH_UNRECOGNIZED_GRAPH_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create subgraph object -
  subgraph_s *sg_ptr = (subgraph_s *)cmalloc(sizeof(subgraph_s));
  sg_ptr->init();

  // - swap edge indexes -
  sg_ptr->edge_idxs.swap(edge_idxs);
  edge_idxs.clear();

  // - create reference to graph -
  dst_location->v_reference_cnt.atomic_inc();
  sg_ptr->graph_ptr = dst_location;

  // - create result location -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_subgraph,sg_ptr);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_graph_method_strongly_connected_components_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  graph_s *graph_ptr = (graph_s *)((location_s *)dst_location)->v_data_ptr;

  // - ERROR -
  if (graph_ptr->type != c_graph_type_digraph)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GRAPH_EXPECTED_DIRECTED_GRAPH,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  ui_array_s comp_idxs;
  comp_idxs.init();

  // - ERROR -
  if (!graph_ptr->strongly_connected_components_tarjans(comp_idxs))
  {
    comp_idxs.clear();

    exception_s::throw_exception(it,module.error_base + c_error_GRAPH_STRONGLY_CONNECTED_COMPONENTS_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create target array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  if (comp_idxs.used > 0)
  {
    unsigned *ci_ptr = comp_idxs.data;
    unsigned *ci_ptr_end = ci_ptr + comp_idxs.used;
    do {
      long long int comp_idx = *ci_ptr == c_idx_not_exist ?
        -1LL : *ci_ptr;

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,comp_idx);
      array_ptr->push(new_location);
    } while(++ci_ptr < ci_ptr_end);
  }

  comp_idxs.clear();

  // - create result location -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_graph_method_is_weakly_connected_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  graph_s *graph_ptr = (graph_s *)dst_location->v_data_ptr;

  long long int result = graph_ptr->is_weakly_connected_graph();

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_graph_method_is_strongly_connected_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  graph_s *graph_ptr = (graph_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (graph_ptr->type != c_graph_type_digraph)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GRAPH_EXPECTED_DIRECTED_GRAPH,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  long long int result = graph_ptr->is_strongly_connected_graph_tarjans();

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_graph_method_vertex_add_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  graph_s *graph_ptr = (graph_s *)dst_location->v_data_ptr;
  graph_ptr->ucl_prepare(it,operands[c_source_pos_idx]);

  // - insert vertex to graph -
  unsigned vertex_idx = graph_ptr->insert_vertex(src_0_location);

  if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
  {
    return false;
  }

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,vertex_idx);

  return true;
}/*}}}*/

bool bic_graph_method_vertex_remove_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int vertex_idx;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,vertex_idx))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("vertex_remove#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  graph_s *graph_ptr = (graph_s *)dst_location->v_data_ptr;
  graph_ptr->ucl_prepare(it,operands[c_source_pos_idx]);

  // - ERROR -
  if (!graph_ptr->ucl_check_vertex_idx(vertex_idx))
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GRAPH_VERTEX_INDEX_INVALID,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(vertex_idx);

    return false;
  }

  // - ERROR -
  if (graph_ptr->vertices[vertex_idx].edge_idxs.root_idx != c_idx_not_exist)
  {
    exception_s::throw_exception(it,module.error_base + c_error_GRAPH_VERTEX_REMOVE_ERROR_INCIDENT_EDGES,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - remove vertex from graph -
  graph_ptr->remove_vertex(vertex_idx);

  if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
  {
    return false;
  }

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_graph_method_vertex_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int vertex_idx;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,vertex_idx))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("vertex#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  graph_s *graph_ptr = (graph_s *)((location_s *)dst_location)->v_data_ptr;

  // - ERROR -
  if (!graph_ptr->ucl_check_vertex_idx(vertex_idx))
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GRAPH_VERTEX_INDEX_INVALID,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(vertex_idx);

    return false;
  }

  // - create graph vertex object -
  graph_vertex_s *gv_ptr = (graph_vertex_s *)cmalloc(sizeof(graph_vertex_s));
  gv_ptr->init();

  // - set vertex index -
  gv_ptr->vertex_idx = vertex_idx;

  // - create reference to graph -
  dst_location->v_reference_cnt.atomic_inc();
  gv_ptr->graph_ptr = dst_location;

  // - create result location -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_graph_vertex,gv_ptr);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_graph_method_vertex_cnt_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  graph_s *graph_ptr = (graph_s *)dst_location->v_data_ptr;

  long long int result = graph_ptr->vertices.count;

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_graph_method_vertex_idxs_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  graph_s *graph_ptr = (graph_s *)dst_location->v_data_ptr;

  // - reference to graph vertices -
  vertex_rb_tree_s &vertices = graph_ptr->vertices;

  // - create target array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  if (vertices.root_idx != c_idx_not_exist)
  {
    unsigned stack[vertices.get_descent_stack_size()];
    unsigned *stack_ptr = stack;

    unsigned v_idx = vertices.get_stack_min_value_idx(vertices.root_idx,&stack_ptr);
    do {
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,v_idx);
      array_ptr->push(new_location);

      v_idx = vertices.get_stack_next_idx(v_idx,&stack_ptr,stack);
    } while(v_idx != c_idx_not_exist);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_graph_method_vertex_idxs_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  graph_s *graph_ptr = (graph_s *)dst_location->v_data_ptr;
  graph_ptr->ucl_prepare(it,operands[c_source_pos_idx]);

  // - create search vertex -
  vertex_s search_vertex;
  search_vertex.value = src_0_location;

  ui_array_s vertex_idxs;
  vertex_idxs.init();

  // - retrieve vertex indexes -
  graph_ptr->vertices.get_idxs(search_vertex,vertex_idxs);

  if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
  {
    vertex_idxs.clear();

    return false;
  }

  // - create target array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  if (vertex_idxs.used != 0)
  {
    unsigned *ptr = vertex_idxs.data;
    unsigned *ptr_end = ptr + vertex_idxs.used;
    do {
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,*ptr);
      array_ptr->push(new_location);
    } while(++ptr < ptr_end);
  }

  vertex_idxs.clear();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_graph_method_vertex_values_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  graph_s *graph_ptr = (graph_s *)dst_location->v_data_ptr;

  long long int vertex_idx;
  if (!it.retrieve_integer(src_0_location,vertex_idx))
  {
    // - ERROR -
    if (src_0_location->v_type != c_bi_class_array)
    {
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
      BIC_EXCEPTION_PUSH_METHOD_RI("vertex_values#1");
      new_exception->params.push(1);
      new_exception->params.push(src_0_location->v_type);

      return false;
    }

    pointer_array_s *idx_array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

    // - create result array -
    pointer_array_s *array_ptr = it.get_new_array_ptr();

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);

    pointer &res_location = it.data_stack[res_loc_idx];
    BIC_SET_RESULT(new_location);

    // - process all vertices from array -
    if (idx_array_ptr->used > 0)
    {
      pointer *p_ptr = idx_array_ptr->data;
      pointer *p_ptr_end = p_ptr + idx_array_ptr->used;
      do {
        location_s *item_location = it.get_location_value(*p_ptr);

        // - ERROR -
        if (item_location->v_type != c_bi_class_integer)
        {
          exception_s::throw_exception(it,module.error_base + c_error_GRAPH_VERTEX_INDEX_EXPECTED_INTEGER,operands[c_source_pos_idx],(location_s *)it.blank_location);
          return false;
        }

        vertex_idx = (long long int)item_location->v_data_ptr;

        // - ERROR -
        if (!graph_ptr->ucl_check_vertex_idx(vertex_idx))
        {
          exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GRAPH_VERTEX_INDEX_INVALID,operands[c_source_pos_idx],(location_s *)it.blank_location);
          new_exception->params.push(vertex_idx);

          return false;
        }

        location_s *value_location = (location_s *)graph_ptr->vertices[vertex_idx].value;

        // - push value location to result array -
        value_location->v_reference_cnt.atomic_inc();
        array_ptr->push(value_location);

      } while(++p_ptr < p_ptr_end);
    }
  }
  else
  {
    // - ERROR -
    if (!graph_ptr->ucl_check_vertex_idx(vertex_idx))
    {
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GRAPH_VERTEX_INDEX_INVALID,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(vertex_idx);

      return false;
    }

    location_s *value_location = (location_s *)graph_ptr->vertices[vertex_idx].value;
    value_location->v_reference_cnt.atomic_inc();

    pointer &res_location = it.data_stack[res_loc_idx];
    BIC_SET_RESULT(value_location);
  }

  return true;
}/*}}}*/

bool bic_graph_method_edge_add_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);

  long long int sv_idx;
  long long int tv_idx;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,sv_idx) ||
      !it.retrieve_integer(src_1_location,tv_idx))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("edge_add#3");
    new_exception->params.push(3);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);

    return false;
  }

  graph_s *graph_ptr = (graph_s *)dst_location->v_data_ptr;
  graph_ptr->ucl_prepare(it,operands[c_source_pos_idx]);

  // - ERROR -
  if (!graph_ptr->ucl_check_vertex_idx(sv_idx))
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GRAPH_VERTEX_INDEX_INVALID,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(sv_idx);

    return false;
  }

  // - ERROR -
  if (!graph_ptr->ucl_check_vertex_idx(tv_idx))
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GRAPH_VERTEX_INDEX_INVALID,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(tv_idx);

    return false;
  }

  // - insert edge to graph -
  unsigned edge_idx = graph_ptr->insert_edge(sv_idx,tv_idx,src_2_location);

  if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
  {
    return false;
  }

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,edge_idx);

  return true;
}/*}}}*/

bool bic_graph_method_edge_remove_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int edge_idx;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,edge_idx))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("edge_remove#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  graph_s *graph_ptr = (graph_s *)dst_location->v_data_ptr;
  graph_ptr->ucl_prepare(it,operands[c_source_pos_idx]);

  // - ERROR -
  if (!graph_ptr->ucl_check_edge_idx(edge_idx))
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GRAPH_EDGE_INDEX_INVALID,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(edge_idx);

    return false;
  }

  // - remove edge from graph -
  graph_ptr->remove_edge(edge_idx);

  if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
  {
    return false;
  }

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_graph_method_edge_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int edge_idx;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,edge_idx))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("edge#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  graph_s *graph_ptr = (graph_s *)((location_s *)dst_location)->v_data_ptr;

  // - ERROR -
  if (!graph_ptr->ucl_check_edge_idx(edge_idx))
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GRAPH_EDGE_INDEX_INVALID,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(edge_idx);

    return false;
  }

  // - create graph edge object -
  graph_edge_s *ge_ptr = (graph_edge_s *)cmalloc(sizeof(graph_edge_s));
  ge_ptr->init();

  // - set edge index -
  ge_ptr->edge_idx = edge_idx;

  // - create reference to graph -
  dst_location->v_reference_cnt.atomic_inc();
  ge_ptr->graph_ptr = dst_location;

  // - create result location -
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_graph_edge,ge_ptr);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_graph_method_edge_cnt_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  graph_s *graph_ptr = (graph_s *)dst_location->v_data_ptr;

  long long int result = graph_ptr->edges.count;

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_graph_method_edge_idxs_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  graph_s *graph_ptr = (graph_s *)dst_location->v_data_ptr;

  // - reference to graph edges -
  edge_rb_tree_s &edges = graph_ptr->edges;

  // - create target array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  if (edges.root_idx != c_idx_not_exist)
  {
    unsigned stack[edges.get_descent_stack_size()];
    unsigned *stack_ptr = stack;

    unsigned e_idx = edges.get_stack_min_value_idx(edges.root_idx,&stack_ptr);
    do {
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,e_idx);
      array_ptr->push(new_location);

      e_idx = edges.get_stack_next_idx(e_idx,&stack_ptr,stack);
    } while(e_idx != c_idx_not_exist);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_graph_method_edge_idxs_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  graph_s *graph_ptr = (graph_s *)dst_location->v_data_ptr;
  graph_ptr->ucl_prepare(it,operands[c_source_pos_idx]);

  // - create search edge -
  edge_s search_edge;
  search_edge.value = src_0_location;

  ui_array_s edge_idxs;
  edge_idxs.init();

  // - retrieve edge indexes -
  graph_ptr->edges.get_idxs(search_edge,edge_idxs);

  if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
  {
    edge_idxs.clear();

    return false;
  }

  // - create target array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  if (edge_idxs.used != 0)
  {
    unsigned *ptr = edge_idxs.data;
    unsigned *ptr_end = ptr + edge_idxs.used;
    do {
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,*ptr);
      array_ptr->push(new_location);
    } while(++ptr < ptr_end);
  }

  edge_idxs.clear();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_graph_method_edge_values_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  graph_s *graph_ptr = (graph_s *)dst_location->v_data_ptr;

  long long int edge_idx;
  if (!it.retrieve_integer(src_0_location,edge_idx))
  {
    // - ERROR -
    if (src_0_location->v_type != c_bi_class_array)
    {
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
      BIC_EXCEPTION_PUSH_METHOD_RI("edge_values#1");
      new_exception->params.push(1);
      new_exception->params.push(src_0_location->v_type);

      return false;
    }

    pointer_array_s *idx_array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

    // - create result array -
    pointer_array_s *array_ptr = it.get_new_array_ptr();

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);

    pointer &res_location = it.data_stack[res_loc_idx];
    BIC_SET_RESULT(new_location);

    // - process all edges from array -
    if (idx_array_ptr->used > 0)
    {
      pointer *p_ptr = idx_array_ptr->data;
      pointer *p_ptr_end = p_ptr + idx_array_ptr->used;
      do {
        location_s *item_location = it.get_location_value(*p_ptr);

        // - ERROR -
        if (item_location->v_type != c_bi_class_integer)
        {
          exception_s::throw_exception(it,module.error_base + c_error_GRAPH_EDGE_INDEX_EXPECTED_INTEGER,operands[c_source_pos_idx],(location_s *)it.blank_location);
          return false;
        }

        edge_idx = (long long int)item_location->v_data_ptr;

        // - ERROR -
        if (!graph_ptr->ucl_check_edge_idx(edge_idx))
        {
          exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GRAPH_VERTEX_INDEX_INVALID,operands[c_source_pos_idx],(location_s *)it.blank_location);
          new_exception->params.push(edge_idx);

          return false;
        }

        location_s *value_location = (location_s *)graph_ptr->edges[edge_idx].value;

        // - push value location to result array -
        value_location->v_reference_cnt.atomic_inc();
        array_ptr->push(value_location);

      } while(++p_ptr < p_ptr_end);
    }
  }
  else
  {
    // - ERROR -
    if (!graph_ptr->ucl_check_edge_idx(edge_idx))
    {
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GRAPH_EDGE_INDEX_INVALID,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(edge_idx);

      return false;
    }

    location_s *value_location = (location_s *)graph_ptr->edges[edge_idx].value;
    value_location->v_reference_cnt.atomic_inc();

    pointer &res_location = it.data_stack[res_loc_idx];
    BIC_SET_RESULT(value_location);
  }

  return true;
}/*}}}*/

bool bic_graph_method_get_dot_code_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  graph_s *graph_ptr = (graph_s *)dst_location->v_data_ptr;
  graph_ptr->ucl_prepare(it,operands[c_source_pos_idx]);

  string_s *string_ptr = it.get_new_string_ptr();

  // - retrieve graph dot code -
  graph_ptr->get_dot_code(*string_ptr);

  if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
  {
    return false;
  }

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_graph_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Graph"),"Graph");
  );

  return true;
}/*}}}*/

bool bic_graph_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];

  printf("Graph");

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class GRAPH_VERTEX -
built_in_class_s graph_vertex_class =
{/*{{{*/
  "GraphVertex",
  c_modifier_public | c_modifier_final,
  13, graph_vertex_methods,
  0, graph_vertex_variables,
  bic_graph_vertex_consts,
  bic_graph_vertex_init,
  bic_graph_vertex_clear,
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

built_in_method_s graph_vertex_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_graph_vertex_operator_binary_equal
  },
  {
    "index#0",
    c_modifier_public | c_modifier_final,
    bic_graph_vertex_method_index_0
  },
  {
    "value#0",
    c_modifier_public | c_modifier_final,
    bic_graph_vertex_method_value_0
  },
  {
    "degree#0",
    c_modifier_public | c_modifier_final,
    bic_graph_vertex_method_degree_0
  },
  {
    "out_degree#0",
    c_modifier_public | c_modifier_final,
    bic_graph_vertex_method_out_degree_0
  },
  {
    "in_degree#0",
    c_modifier_public | c_modifier_final,
    bic_graph_vertex_method_in_degree_0
  },
  {
    "adjacent_idxs#0",
    c_modifier_public | c_modifier_final,
    bic_graph_vertex_method_adjacent_idxs_0
  },
  {
    "incident_idxs#0",
    c_modifier_public | c_modifier_final,
    bic_graph_vertex_method_incident_idxs_0
  },
  {
    "edge_idxs#0",
    c_modifier_public | c_modifier_final,
    bic_graph_vertex_method_edge_idxs_0
  },
  {
    "out_idxs#0",
    c_modifier_public | c_modifier_final,
    bic_graph_vertex_method_out_idxs_0
  },
  {
    "in_idxs#0",
    c_modifier_public | c_modifier_final,
    bic_graph_vertex_method_in_idxs_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_graph_vertex_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_graph_vertex_method_print_0
  },
};/*}}}*/

built_in_variable_s graph_vertex_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_GRAPH_VERTEX_CHECK_INDEX() \
{/*{{{*/\
\
  /* - ERROR - */\
  if (!graph_ptr->ucl_check_vertex_idx(gv_ptr->vertex_idx))\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GRAPH_VERTEX_INDEX_INVALID,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(gv_ptr->vertex_idx);\
\
    return false;\
  }\
}/*}}}*/

#define BIC_GRAPH_VERTEX_IN_OUT_IDXS(VERTEX_IDX) \
{/*{{{*/\
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  graph_vertex_s *gv_ptr = (graph_vertex_s *)dst_location->v_data_ptr;\
  graph_s *graph_ptr = (graph_s *)((location_s *)gv_ptr->graph_ptr)->v_data_ptr;\
  edge_rb_tree_s &edges = graph_ptr->edges;\
\
  BIC_GRAPH_VERTEX_CHECK_INDEX();\
\
  edge_idxs_s &edge_idxs = graph_ptr->vertices[gv_ptr->vertex_idx].edge_idxs;\
\
  /* - create target array - */\
  pointer_array_s *array_ptr = it.get_new_array_ptr();\
  BIC_CREATE_NEW_LOCATION(array_location,c_bi_class_array,array_ptr);\
\
  if (edge_idxs.root_idx != c_idx_not_exist)\
  {\
    unsigned stack[edge_idxs.get_descent_stack_size()];\
    unsigned *stack_ptr = stack;\
\
    unsigned ei_idx = edge_idxs.get_stack_min_value_idx(edge_idxs.root_idx,&stack_ptr);\
    do\
    {\
      unsigned edge_idx = edge_idxs[ei_idx];\
\
      /* - ERROR - */\
      if (!graph_ptr->ucl_check_edge_idx(edge_idx))\
      {\
        it.release_location_ptr(array_location);\
\
        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GRAPH_EDGE_INDEX_INVALID,operands[c_source_pos_idx],(location_s *)it.blank_location);\
        new_exception->params.push(edge_idx);\
\
        return false;\
      }\
\
      /* - if edge is outgoing from vertex - */\
      if (edges[edge_idx].VERTEX_IDX == gv_ptr->vertex_idx)\
      {\
        /* - insert edge index to target array - */\
        BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,edge_idx);\
        array_ptr->push(new_location);\
      }\
\
      ei_idx = edge_idxs.get_next_idx(ei_idx);\
    }\
    while(ei_idx != c_idx_not_exist);\
  }\
\
  pointer &res_location = it.data_stack[res_loc_idx];\
  BIC_SET_RESULT(array_location);\
\
  return true;\
}/*}}}*/

void bic_graph_vertex_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_graph_vertex_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (graph_vertex_s *)nullptr;
}/*}}}*/

void bic_graph_vertex_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  graph_vertex_s *gv_ptr = (graph_vertex_s *)location_ptr->v_data_ptr;

  if (gv_ptr != nullptr)
  {
    gv_ptr->clear(it);
    cfree(gv_ptr);
  }
}/*}}}*/

bool bic_graph_vertex_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_graph_vertex_method_index_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  graph_vertex_s *gv_ptr = (graph_vertex_s *)dst_location->v_data_ptr;

  long long int result = gv_ptr->vertex_idx;

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_graph_vertex_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  graph_vertex_s *gv_ptr = (graph_vertex_s *)dst_location->v_data_ptr;
  graph_s *graph_ptr = (graph_s *)((location_s *)gv_ptr->graph_ptr)->v_data_ptr;

  BIC_GRAPH_VERTEX_CHECK_INDEX();

  location_s *value_location = (location_s *)graph_ptr->vertices[gv_ptr->vertex_idx].value;
  value_location->v_reference_cnt.atomic_inc();

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(value_location);

  return true;
}/*}}}*/

bool bic_graph_vertex_method_degree_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  graph_vertex_s *gv_ptr = (graph_vertex_s *)dst_location->v_data_ptr;
  graph_s *graph_ptr = (graph_s *)((location_s *)gv_ptr->graph_ptr)->v_data_ptr;

  BIC_GRAPH_VERTEX_CHECK_INDEX();

  long long int result = graph_ptr->vertices[gv_ptr->vertex_idx].get_degree();

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_graph_vertex_method_out_degree_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  graph_vertex_s *gv_ptr = (graph_vertex_s *)dst_location->v_data_ptr;
  graph_s *graph_ptr = (graph_s *)((location_s *)gv_ptr->graph_ptr)->v_data_ptr;

  BIC_GRAPH_VERTEX_CHECK_INDEX();

  long long int result = graph_ptr->vertices[gv_ptr->vertex_idx].output_degree;

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_graph_vertex_method_in_degree_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  graph_vertex_s *gv_ptr = (graph_vertex_s *)dst_location->v_data_ptr;
  graph_s *graph_ptr = (graph_s *)((location_s *)gv_ptr->graph_ptr)->v_data_ptr;

  BIC_GRAPH_VERTEX_CHECK_INDEX();

  long long int result = graph_ptr->vertices[gv_ptr->vertex_idx].input_degree;

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_graph_vertex_method_adjacent_idxs_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  graph_vertex_s *gv_ptr = (graph_vertex_s *)dst_location->v_data_ptr;
  graph_s *graph_ptr = (graph_s *)((location_s *)gv_ptr->graph_ptr)->v_data_ptr;

  BIC_GRAPH_VERTEX_CHECK_INDEX();

  ui_array_s vertex_idxs;
  vertex_idxs.init();

  // - retrieve adjacent vertices -
  graph_ptr->adjacent_vertices(gv_ptr->vertex_idx,vertex_idxs);

  // - create target array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  if (vertex_idxs.used != 0)
  {
    unsigned *ptr = vertex_idxs.data;
    unsigned *ptr_end = ptr + vertex_idxs.used;
    do {
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,*ptr);
      array_ptr->push(new_location);
    } while(++ptr < ptr_end);
  }

  vertex_idxs.clear();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_graph_vertex_method_incident_idxs_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  graph_vertex_s *gv_ptr = (graph_vertex_s *)dst_location->v_data_ptr;
  graph_s *graph_ptr = (graph_s *)((location_s *)gv_ptr->graph_ptr)->v_data_ptr;

  BIC_GRAPH_VERTEX_CHECK_INDEX();

  ui_array_s edge_idxs;
  edge_idxs.init();

  // - retrieve incident edges -
  graph_ptr->incident_edges(gv_ptr->vertex_idx,edge_idxs);

  // - create target array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  if (edge_idxs.used != 0)
  {
    unsigned *ptr = edge_idxs.data;
    unsigned *ptr_end = ptr + edge_idxs.used;
    do {
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,*ptr);
      array_ptr->push(new_location);
    } while(++ptr < ptr_end);
  }

  edge_idxs.clear();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_graph_vertex_method_edge_idxs_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  graph_vertex_s *gv_ptr = (graph_vertex_s *)dst_location->v_data_ptr;
  graph_s *graph_ptr = (graph_s *)((location_s *)gv_ptr->graph_ptr)->v_data_ptr;

  BIC_GRAPH_VERTEX_CHECK_INDEX();

  edge_idxs_s &edge_idxs = graph_ptr->vertices[gv_ptr->vertex_idx].edge_idxs;

  // - create target array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  if (edge_idxs.root_idx != c_idx_not_exist)
  {
    unsigned stack[edge_idxs.get_descent_stack_size()];
    unsigned *stack_ptr = stack;

    unsigned ei_idx = edge_idxs.get_stack_min_value_idx(edge_idxs.root_idx,&stack_ptr);
    do
    {
      // - insert edge index to target array -
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,edge_idxs[ei_idx]);
      array_ptr->push(new_location);

      ei_idx = edge_idxs.get_next_idx(ei_idx);
    }
    while(ei_idx != c_idx_not_exist);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_graph_vertex_method_out_idxs_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GRAPH_VERTEX_IN_OUT_IDXS(src_vertex_idx);
}/*}}}*/

bool bic_graph_vertex_method_in_idxs_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_GRAPH_VERTEX_IN_OUT_IDXS(trg_vertex_idx);
}/*}}}*/

bool bic_graph_vertex_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("GraphVertex"),"GraphVertex");
  );

  return true;
}/*}}}*/

bool bic_graph_vertex_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];

  printf("GraphVertex");

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class GRAPH_EDGE -
built_in_class_s graph_edge_class =
{/*{{{*/
  "GraphEdge",
  c_modifier_public | c_modifier_final,
  8, graph_edge_methods,
  0, graph_edge_variables,
  bic_graph_edge_consts,
  bic_graph_edge_init,
  bic_graph_edge_clear,
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

built_in_method_s graph_edge_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_graph_edge_operator_binary_equal
  },
  {
    "index#0",
    c_modifier_public | c_modifier_final,
    bic_graph_edge_method_index_0
  },
  {
    "value#0",
    c_modifier_public | c_modifier_final,
    bic_graph_edge_method_value_0
  },
  {
    "source_idx#0",
    c_modifier_public | c_modifier_final,
    bic_graph_edge_method_source_idx_0
  },
  {
    "target_idx#0",
    c_modifier_public | c_modifier_final,
    bic_graph_edge_method_target_idx_0
  },
  {
    "opposite_idx#1",
    c_modifier_public | c_modifier_final,
    bic_graph_edge_method_opposite_idx_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_graph_edge_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_graph_edge_method_print_0
  },
};/*}}}*/

built_in_variable_s graph_edge_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_GRAPH_EDGE_CHECK_INDEX() \
{/*{{{*/\
\
  /* - ERROR - */\
  if (!graph_ptr->ucl_check_edge_idx(ge_ptr->edge_idx))\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GRAPH_EDGE_INDEX_INVALID,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(ge_ptr->edge_idx);\
\
    return false;\
  }\
}/*}}}*/

void bic_graph_edge_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_graph_edge_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (graph_edge_s *)nullptr;
}/*}}}*/

void bic_graph_edge_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  graph_edge_s *ge_ptr = (graph_edge_s *)location_ptr->v_data_ptr;

  if (ge_ptr != nullptr)
  {
    ge_ptr->clear(it);
    cfree(ge_ptr);
  }
}/*}}}*/

bool bic_graph_edge_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_graph_edge_method_index_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  graph_edge_s *ge_ptr = (graph_edge_s *)dst_location->v_data_ptr;

  long long int result = ge_ptr->edge_idx;

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_graph_edge_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  graph_edge_s *ge_ptr = (graph_edge_s *)dst_location->v_data_ptr;
  graph_s *graph_ptr = (graph_s *)((location_s *)ge_ptr->graph_ptr)->v_data_ptr;

  BIC_GRAPH_EDGE_CHECK_INDEX();

  location_s *value_location = (location_s *)graph_ptr->edges[ge_ptr->edge_idx].value;
  value_location->v_reference_cnt.atomic_inc();

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(value_location);

  return true;
}/*}}}*/

bool bic_graph_edge_method_source_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  graph_edge_s *ge_ptr = (graph_edge_s *)dst_location->v_data_ptr;
  graph_s *graph_ptr = (graph_s *)((location_s *)ge_ptr->graph_ptr)->v_data_ptr;

  BIC_GRAPH_EDGE_CHECK_INDEX();

  long long int result = graph_ptr->edges[ge_ptr->edge_idx].src_vertex_idx;

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_graph_edge_method_target_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  graph_edge_s *ge_ptr = (graph_edge_s *)dst_location->v_data_ptr;
  graph_s *graph_ptr = (graph_s *)((location_s *)ge_ptr->graph_ptr)->v_data_ptr;

  BIC_GRAPH_EDGE_CHECK_INDEX();

  long long int result = graph_ptr->edges[ge_ptr->edge_idx].trg_vertex_idx;

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_graph_edge_method_opposite_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int vertex_idx;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,vertex_idx))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("opposite_idx#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  graph_edge_s *ge_ptr = (graph_edge_s *)dst_location->v_data_ptr;
  graph_s *graph_ptr = (graph_s *)((location_s *)ge_ptr->graph_ptr)->v_data_ptr;

  BIC_GRAPH_EDGE_CHECK_INDEX();

  edge_s &edge = graph_ptr->edges[ge_ptr->edge_idx];

  long long int result;

  // - test source vertex index -
  if (vertex_idx == edge.src_vertex_idx)
  {
    result = edge.trg_vertex_idx;
  }

  // - test target vertex index -
  else if (vertex_idx == edge.trg_vertex_idx)
  {
    result = edge.src_vertex_idx;
  }

  // - ERROR -
  else
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GRAPH_EDGE_VERTEX_NOT_INCIDENT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(vertex_idx);

    return false;
  }

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_graph_edge_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("GraphEdge"),"GraphEdge");
  );

  return true;
}/*}}}*/

bool bic_graph_edge_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];

  printf("GraphEdge");

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class SUBGRAPH -
built_in_class_s subgraph_class =
{/*{{{*/
  "Subgraph",
  c_modifier_public | c_modifier_final,
  3, subgraph_methods,
  0, subgraph_variables,
  bic_subgraph_consts,
  bic_subgraph_init,
  bic_subgraph_clear,
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

built_in_method_s subgraph_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_subgraph_operator_binary_equal
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_subgraph_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_subgraph_method_print_0
  },
};/*}}}*/

built_in_variable_s subgraph_variables[] =
{/*{{{*/
};/*}}}*/

void bic_subgraph_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_subgraph_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (subgraph_s *)nullptr;
}/*}}}*/

void bic_subgraph_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  subgraph_s *sg_ptr = (subgraph_s *)location_ptr->v_data_ptr;

  if (sg_ptr != nullptr)
  {
    sg_ptr->clear(it);
    cfree(sg_ptr);
  }
}/*}}}*/

bool bic_subgraph_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_subgraph_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Subgraph"),"Subgraph");
  );

  return true;
}/*}}}*/

bool bic_subgraph_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];

  printf("Subgraph");

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class GRAPH_PATHS -
built_in_class_s graph_paths_class =
{/*{{{*/
  "GraphPaths",
  c_modifier_public | c_modifier_final,
  7, graph_paths_methods,
  0, graph_paths_variables,
  bic_graph_paths_consts,
  bic_graph_paths_init,
  bic_graph_paths_clear,
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

built_in_method_s graph_paths_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_graph_paths_operator_binary_equal
  },
  {
    "lengths#0",
    c_modifier_public | c_modifier_final,
    bic_graph_paths_method_lengths_0
  },
  {
    "source_idx#0",
    c_modifier_public | c_modifier_final,
    bic_graph_paths_method_source_idx_0
  },
  {
    "raw_paths#0",
    c_modifier_public | c_modifier_final,
    bic_graph_paths_method_raw_paths_0
  },
  {
    "path_to#1",
    c_modifier_public | c_modifier_final,
    bic_graph_paths_method_path_to_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_graph_paths_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_graph_paths_method_print_0
  },
};/*}}}*/

built_in_variable_s graph_paths_variables[] =
{/*{{{*/
};/*}}}*/

void bic_graph_paths_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_graph_paths_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (graph_paths_s *)nullptr;
}/*}}}*/

void bic_graph_paths_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  graph_paths_s *gp_ptr = (graph_paths_s *)location_ptr->v_data_ptr;

  if (gp_ptr != nullptr)
  {
    gp_ptr->clear(it);
    cfree(gp_ptr);
  }
}/*}}}*/

bool bic_graph_paths_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_graph_paths_method_lengths_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  graph_paths_s *gp_ptr = (graph_paths_s *)dst_location->v_data_ptr;

  location_s *lengths_arr = (location_s *)gp_ptr->lengths_arr;
  lengths_arr->v_reference_cnt.atomic_inc();

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(lengths_arr);

  return true;
}/*}}}*/

bool bic_graph_paths_method_source_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  graph_paths_s *gp_ptr = (graph_paths_s *)dst_location->v_data_ptr;

  long long int result = gp_ptr->src_vertex_idx;

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_graph_paths_method_raw_paths_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  graph_paths_s *gp_ptr = (graph_paths_s *)dst_location->v_data_ptr;
  ui_array_s &edge_idxs = gp_ptr->edge_idxs;

  pointer_array_s *array_ptr = it.get_new_array_ptr();

  if (edge_idxs.used > 0)
  {
    unsigned *ei_ptr = edge_idxs.data;
    unsigned *ei_ptr_end = ei_ptr + edge_idxs.used;
    do {
      long long int edge_idx = *ei_ptr == c_idx_not_exist ?
        -1LL : *ei_ptr;

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,edge_idx);
      array_ptr->push(new_location);
    } while(++ei_ptr < ei_ptr_end);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_graph_paths_method_path_to_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int trg_vertex_idx;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,trg_vertex_idx))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("path_to#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  graph_paths_s *gp_ptr = (graph_paths_s *)dst_location->v_data_ptr;
  graph_s *graph_ptr = (graph_s *)((location_s *)gp_ptr->graph_ptr)->v_data_ptr;

  // - ERROR -
  if (!graph_ptr->ucl_check_vertex_idx(trg_vertex_idx))
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GRAPH_VERTEX_INDEX_INVALID,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(trg_vertex_idx);

    return false;
  }

  // - retrieve path length location -
  pointer_array_s *lengths_arr = (pointer_array_s *)((location_s *)gp_ptr->lengths_arr)->v_data_ptr;
  location_s *length_location = (location_s *)lengths_arr->data[trg_vertex_idx];

  // - if there is no path to target vertex -
  if (length_location->v_type == c_bi_class_blank)
  {
    pointer &res_location = it.data_stack[res_loc_idx];
    BIC_SET_RESULT_BLANK();
  }

  // - if there is path to target vertex -
  else
  {
    // - create target array -
    pointer_array_s *array_ptr = it.get_new_array_ptr();
    BIC_CREATE_NEW_LOCATION(array_location,c_bi_class_array,array_ptr);

    if (trg_vertex_idx != gp_ptr->src_vertex_idx)
    {
      ui_array_s &edge_idxs = gp_ptr->edge_idxs;

      unsigned v_idx = trg_vertex_idx;
      do {

        // - retrieve transitive edge -
        unsigned edge_idx = edge_idxs[v_idx];

        // - ERROR -
        if (!graph_ptr->ucl_check_edge_idx(edge_idx))
        {
          it.release_location_ptr(array_location);

          exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_GRAPH_EDGE_INDEX_INVALID,operands[c_source_pos_idx],(location_s *)it.blank_location);
          new_exception->params.push(edge_idx);

          return false;
        }

        // - insert edge index to target array -
        BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,edge_idx);
        array_ptr->push(new_location);

        // - reference to transitive edge -
        edge_s &edge = graph_ptr->edges[edge_idx];

        // - find target vertex index -
        v_idx = edge.src_vertex_idx == v_idx ?
          edge.trg_vertex_idx : edge.src_vertex_idx;

      } while(v_idx != gp_ptr->src_vertex_idx);
    }

    pointer &res_location = it.data_stack[res_loc_idx];
    BIC_SET_RESULT(array_location);
  }

  return true;
}/*}}}*/

bool bic_graph_paths_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("GraphPaths"),"GraphPaths");
  );

  return true;
}/*}}}*/

bool bic_graph_paths_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];

  printf("GraphPaths");

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

