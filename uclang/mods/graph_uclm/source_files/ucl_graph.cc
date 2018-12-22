
@begin
include "ucl_graph.h"
@end

/*
 * constants and definitions
 */

// - strings of graph type dot codes -
const char *c_graph_type_dot_codes[c_graph_type_cnt] =
{
  "--",
  "->",
};

// - graph functions for uclang variable types -

int gf_uclvar_compare(interpreter_thread_s &it,unsigned source_pos,void *a_first,void *a_second)
{/*{{{*/
  long long int result;

  BIC_CALL_COMPARE(it,a_first,a_second,source_pos,return 0);

  return result;
}/*}}}*/

void gf_uclvar_operator_plus(interpreter_thread_s &it,unsigned source_pos,void **a_trg,void *a_first,void *a_second)
{/*{{{*/
  pointer result_location;

  BIC_CALL_OPERATOR_BINARY_PLUS(it,a_first,a_second,result_location,source_pos,return);

  it.release_location_ptr((location_s *)*a_trg);
  *a_trg = result_location;
}/*}}}*/

void gf_uclvar_get_string(interpreter_thread_s &it,unsigned source_pos,void *a_value,string_s &a_string)
{/*{{{*/
  unsigned strings_size = 0;
  string_s *s_ptr = &a_string;

  BIC_CALL_TO_STRING(it,a_value,source_pos,
      s_ptr->clear();
      );

  // - process result string -
  bc_array_s buff;
  buff.init();
  buff.push('"');

  if (a_string.size > 1)
  {
    char *c_ptr = a_string.data;
    char *c_ptr_end = c_ptr + a_string.size - 1;
    do {

      // - escape special characters in string -
      switch (*c_ptr)
      {
      case '"':
      case '\\':
        buff.push('\\');
        break;
      }

      buff.push(*c_ptr);
    } while(++c_ptr < c_ptr_end);
  }

  buff.push('"');
  buff.push('\0');

  a_string.clear();
  a_string.data = buff.data;
  a_string.size = buff.used;
}/*}}}*/

/*
 * methods of generated structures
 */

// -- bb_array_s --
@begin
methods bb_array_s
@end

// -- gg_vertex_map_s --
@begin
methods gg_vertex_map_s
@end

// -- edge_s --
@begin
methods edge_s
@end

// -- edge_rb_tree_s --
@begin
methods edge_rb_tree_s
@end

// -- edge_idxs_s --
@begin
methods edge_idxs_s
@end

void edge_idxs_s::get_edge_idxs_by_edge(edge_s &a_edge,ui_array_s &a_edge_idxs,unsigned &a_edge_cnt)
{/*{{{*/
  a_edge_idxs.used = 0;

  if (root_idx == c_idx_not_exist)
  {
    return;
  }

  edge_rb_tree_s &edges = ((graph_s *)graph_ptr)->edges;

  unsigned stack[RB_TREE_STACK_SIZE(*this)];
  unsigned *stack_ptr = stack;

  *(stack_ptr++) = root_idx;
  do
  {
    unsigned node_idx = *(--stack_ptr);
    edge_idxs_s_node &node = data[node_idx];

    int comp_result = compare_edges(a_edge,edges[node.object]);
    if (comp_result < 0)
    {
      if (node.left_idx != leaf_idx)
      {
        *(stack_ptr++) = node.left_idx;
      }
    }
    else
    {
      if (comp_result == 0)
      {
        a_edge_idxs.push(data[node_idx].object);
        a_edge_cnt++;

        if (node.left_idx != leaf_idx)
        {
          *(stack_ptr++) = node.left_idx;
        }
      }

      if (node.right_idx != leaf_idx)
      {
        *(stack_ptr++) = node.right_idx;
      }
    }
  }
  while(stack_ptr > stack);
}/*}}}*/

// -- vertex_s --
@begin
methods vertex_s
@end

// -- vertex_rb_tree_s --
@begin
methods vertex_rb_tree_s
@end

// -- graph_s --
@begin
methods graph_s
@end

void graph_s::clear()
{/*{{{*/
  if (vertices.root_idx != c_idx_not_exist)
  {
    unsigned stack[RB_TREE_STACK_SIZE(vertices)];
    unsigned *stack_ptr = stack;

    unsigned v_idx = vertices.get_stack_min_value_idx(vertices.root_idx,&stack_ptr);
    do
    {
      vertices.vf_clear(vertices[v_idx].value);

      v_idx = vertices.get_stack_next_idx(v_idx,&stack_ptr,stack);
    }
    while(v_idx != c_idx_not_exist);
  }

  if (edges.root_idx != c_idx_not_exist)
  {
    unsigned stack[RB_TREE_STACK_SIZE(edges)];
    unsigned *stack_ptr = stack;

    unsigned e_idx = edges.get_stack_min_value_idx(edges.root_idx,&stack_ptr);
    do
    {
      edges.ef_clear(edges[e_idx].value);

      e_idx = edges.get_stack_next_idx(e_idx,&stack_ptr,stack);
    }
    while(e_idx != c_idx_not_exist);
  }

  vertices.clear();
  edges.clear();

  init();
}/*}}}*/

void graph_s::swap(graph_s &second)
{/*{{{*/
  unsigned tmp_type = type;
  type = second.type;
  second.type = tmp_type;

  vertices.swap(second.vertices);

  // - remap edge_idxs graph_ptr -
  if (vertices.root_idx != c_idx_not_exist)
  {
    unsigned stack[RB_TREE_STACK_SIZE(vertices)];
    unsigned *stack_ptr = stack;

    unsigned v_idx = vertices.get_stack_min_value_idx(vertices.root_idx,&stack_ptr);
    do
    {
      vertices[v_idx].edge_idxs.graph_ptr = (pointer)this;
      v_idx = vertices.get_stack_next_idx(v_idx,&stack_ptr,stack);
    }
    while(v_idx != c_idx_not_exist);
  }

  // - remap second edge_idxs graph_ptr -
  if (second.vertices.root_idx != c_idx_not_exist)
  {
    vertex_rb_tree_s &s_vertices = second.vertices;

    unsigned stack[RB_TREE_STACK_SIZE(s_vertices)];
    unsigned *stack_ptr = stack;

    unsigned v_idx = s_vertices.get_stack_min_value_idx(s_vertices.root_idx,&stack_ptr);
    do
    {
      s_vertices[v_idx].edge_idxs.graph_ptr = (pointer)&second;
      v_idx = s_vertices.get_stack_next_idx(v_idx,&stack_ptr,stack);
    }
    while(v_idx != c_idx_not_exist);
  }

  edges.swap(second.edges);
}/*}}}*/

graph_s &graph_s::operator=(graph_s &second)
{/*{{{*/
  clear();

  type = second.type;
  vertices = second.vertices;
  edges = second.edges;

  // - remap edge_idxs graph_ptr, and copy vertex evaluation -
  if (vertices.root_idx != c_idx_not_exist)
  {
    unsigned stack[RB_TREE_STACK_SIZE(vertices)];
    unsigned *stack_ptr = stack;

    unsigned v_idx = vertices.get_stack_min_value_idx(vertices.root_idx,&stack_ptr);
    do
    {
      vertex_s &vertex = vertices[v_idx];

      vertices.vf_init(&vertex.value);
      vertices.vf_operator_equal(&vertex.value,second.vertices[v_idx].value);
      vertex.edge_idxs.graph_ptr = (pointer)this;

      v_idx = vertices.get_stack_next_idx(v_idx,&stack_ptr,stack);
    }
    while(v_idx != c_idx_not_exist);
  }

  // - copy edge evaluation -
  if (edges.root_idx != c_idx_not_exist)
  {
    unsigned stack[RB_TREE_STACK_SIZE(edges)];
    unsigned *stack_ptr = stack;

    unsigned e_idx = edges.get_stack_min_value_idx(edges.root_idx,&stack_ptr);
    do
    {
      edge_s &edge = edges[e_idx];

      edges.ef_init(&edge.value);
      edges.ef_operator_equal(&edge.value,second.edges[e_idx].value);

      e_idx = edges.get_stack_next_idx(e_idx,&stack_ptr,stack);
    }
    while(e_idx != c_idx_not_exist);
  }

  return *this;
}/*}}}*/

void graph_s::duplicate(graph_s &a_src)
{/*{{{*/
  clear();

  type = a_src.type;

  // - references on vertices and edges of source graph -
  vertex_rb_tree_s &s_vertices = a_src.vertices;
  edge_rb_tree_s &s_edges = a_src.edges;

  // - source to duplicate vertex map -
  unsigned *v_map = (unsigned *)cmalloc(s_vertices.used*sizeof(unsigned));

  // - insert vertices to duplicate graph -
  if (s_vertices.root_idx != c_idx_not_exist)
  {
    unsigned stack[RB_TREE_STACK_SIZE(s_vertices)];
    unsigned *stack_ptr = stack;

    unsigned sv_idx = s_vertices.get_stack_min_value_idx(s_vertices.root_idx,&stack_ptr);
    do
    {
      v_map[sv_idx] = insert_vertex(s_vertices[sv_idx].value);

      sv_idx = s_vertices.get_stack_next_idx(sv_idx,&stack_ptr,stack);
    }
    while(sv_idx != c_idx_not_exist);
  }

  // - insert edges to duplicate graph -
  if (s_edges.root_idx != c_idx_not_exist)
  {
    unsigned stack[RB_TREE_STACK_SIZE(s_edges)];
    unsigned *stack_ptr = stack;

    unsigned e_idx = s_edges.get_stack_min_value_idx(s_edges.root_idx,&stack_ptr);
    do
    {
      edge_s &edge = s_edges[e_idx];

      insert_edge(v_map[edge.src_vertex_idx],v_map[edge.trg_vertex_idx],edge.value);

      e_idx = s_edges.get_stack_next_idx(e_idx,&stack_ptr,stack);
    }
    while(e_idx != c_idx_not_exist);
  }

  cfree(v_map);
}/*}}}*/

void graph_s::adjacent_vertices(unsigned a_vertex_idx,ui_array_s &a_vertex_idxs)
{/*{{{*/
  a_vertex_idxs.used = 0;

  bool *v_unused = (bool *)cmalloc(vertices.used*sizeof(bool));
  memset(v_unused,true,vertices.used*sizeof(bool));

  // - set of edges incident to vertex -
  edge_idxs_s &edge_idxs = vertices[a_vertex_idx].edge_idxs;
  if (edge_idxs.root_idx != c_idx_not_exist)
  {
    unsigned stack[RB_TREE_STACK_SIZE(edge_idxs)];
    unsigned *stack_ptr = stack;

    unsigned ei_idx = edge_idxs.get_stack_min_value_idx(edge_idxs.root_idx,&stack_ptr);
    do
    {
      edge_s &edge = edges[edge_idxs[ei_idx]];

      // - insert all vertices which are not same as a_vertex_idx to result array -
      if (a_vertex_idx != edge.src_vertex_idx && v_unused[edge.src_vertex_idx])
      {
        a_vertex_idxs.push(edge.src_vertex_idx);
        v_unused[edge.src_vertex_idx] = false;
      }

      if (a_vertex_idx != edge.trg_vertex_idx && v_unused[edge.trg_vertex_idx])
      {
        a_vertex_idxs.push(edge.trg_vertex_idx);
        v_unused[edge.trg_vertex_idx] = false;
      }

      // - move to next edge -
      ei_idx = edge_idxs.get_next_idx(ei_idx);
    }
    while(ei_idx != c_idx_not_exist);
  }

  cfree(v_unused);
}/*}}}*/

void graph_s::incident_edges(unsigned a_vertex_idx,ui_array_s &a_edge_idxs)
{/*{{{*/
  a_edge_idxs.used = 0;

  edge_idxs_s &edge_idxs = vertices[a_vertex_idx].edge_idxs;

  // - insert all edges in incident set to result array -
  if (edge_idxs.root_idx != c_idx_not_exist)
  {
    unsigned stack[RB_TREE_STACK_SIZE(edge_idxs)];
    unsigned *stack_ptr = stack;

    unsigned ei_idx = edge_idxs.get_stack_min_value_idx(edge_idxs.root_idx,&stack_ptr);
    do
    {
      a_edge_idxs.push(edge_idxs[ei_idx]);
      ei_idx = edge_idxs.get_stack_next_idx(ei_idx,&stack_ptr,stack);
    }
    while(ei_idx != c_idx_not_exist);
  }
}/*}}}*/

inline int comp_int(const void *first,const void *second)
{/*{{{*/
  register unsigned f_val = *((unsigned *)first);
  register unsigned s_val = *((unsigned *)second);

  return (f_val > s_val?-1:(f_val < s_val)?1:0);
}/*}}}*/

void graph_s::degree_sequence(ui_array_s &a_degree_sequence)
{/*{{{*/
  a_degree_sequence.used = 0;

  if (vertices.root_idx == c_idx_not_exist)
  {
    return;
  }

  // - retrieve array of degrees -
  unsigned stack[RB_TREE_STACK_SIZE(vertices)];
  unsigned *stack_ptr = stack;

  unsigned v_idx = vertices.get_stack_min_value_idx(vertices.root_idx,&stack_ptr);
  do
  {
    a_degree_sequence.push(vertices[v_idx].get_degree());
    v_idx = vertices.get_stack_next_idx(v_idx,&stack_ptr,stack);
  }
  while(v_idx != c_idx_not_exist);

  // - sort degrees in non decreasing order -
  qsort(a_degree_sequence.data,a_degree_sequence.used,sizeof(unsigned),comp_int);
}/*}}}*/

bool graph_s::minimum_spanning_tree_kruskals(ui_array_s &a_edge_idxs)
{/*{{{*/
  a_edge_idxs.used = 0;

  unsigned v_used_cnt = 0;

  bool *v_used = (bool *)cmalloc(vertices.used*sizeof(bool));
  memset(v_used,false,vertices.used*sizeof(bool));

  // - traverse throught all edges -
  if (edges.root_idx != c_idx_not_exist)
  {
    unsigned stack[RB_TREE_STACK_SIZE(edges)];
    unsigned *stack_ptr = stack;

    unsigned e_idx = edges.get_stack_min_value_idx(edges.root_idx,&stack_ptr);
    do {
      edge_s &edge = edges[e_idx];

      unsigned old_v_used_cnt = v_used_cnt;

      // - if source vertex was not used -
      if (!v_used[edge.src_vertex_idx])
      {
        v_used[edge.src_vertex_idx] = true;
        v_used_cnt++;
      }

      // - if target vertex was not used -
      if (!v_used[edge.trg_vertex_idx])
      {
        v_used[edge.trg_vertex_idx] = true;
        v_used_cnt++;
      }

      // - if some vertex was added to spanning tree -
      if (v_used_cnt != old_v_used_cnt)
      {
        a_edge_idxs.push(e_idx);

        if (v_used_cnt >= vertices.count)
        {
          break;
        }
      }

      e_idx = edges.get_stack_next_idx(e_idx,&stack_ptr,stack);
    } while(e_idx != c_idx_not_exist);
  }

  cfree(v_used);

  return v_used_cnt == vertices.count;
}/*}}}*/

#define SHORTEST_PATH_DIJKSTRA_FIRST_VERTEX_EDGE() \
/*{{{*/\
\
  /* - pointer to new length value - */\
  pointer new_length = edge.value;\
\
/*}}}*/

#define SHORTEST_PATH_DIJKSTRA_VERTEX_EDGE() \
/*{{{*/\
\
  /* - compute new length - */\
  gf_uclvar_operator_plus(it MP_COMMA source_pos MP_COMMA &tmp_length MP_COMMA a_lengths[sv_idx] MP_COMMA edge.value);\
\
  /* - pointer to new length value - */\
  pointer new_length = tmp_length;\
/*}}}*/

#define SHORTEST_PATH_DIJKSTRA_PROC_LENGTH() \
{/*{{{*/\
  if (!v_done[tv_idx])\
  {\
    bool shorter_path = false;\
    pointer &length = a_lengths[tv_idx];\
\
    /* - vertex has no length assigned yet - */\
    if (vi_vvi_map[tv_idx] == c_idx_not_exist)\
    {\
      shorter_path = true;\
    }\
    else \
    {\
      /* - new path is shorter than actual - */\
      if (gf_uclvar_compare(it,source_pos,new_length,length) < 0)\
      {\
        /* - remove vertex from vertex set - */\
        vvi_set.remove(vi_vvi_map[tv_idx]);\
\
        shorter_path = true;\
      }\
    }\
\
    if (shorter_path)\
    {\
      /* - update path length - */\
      gf_uclvar_operator_equal(it,&length,new_length);\
\
      /* - insert vertex to vertex set - */\
      value_idx_s vvi = {length,tv_idx};\
      vi_vvi_map[tv_idx] = vvi_set.insert(vvi);\
\
      /* - update source vertex - */\
      a_edge_idxs[tv_idx] = edge_idx;\
    }\
  }\
}/*}}}*/

#define SHORTEST_PATH_DIJKSTRA(FIRST_VERTEX_EDGE_CODE,VERTEX_EDGE_CODE) \
{/*{{{*/\
  if (a_src_vertex_idx == a_trg_vertex_idx)\
  {\
    return false;\
  }\
\
  interpreter_thread_s &it = *((interpreter_thread_s *)vertices.it_ptr);\
  unsigned source_pos = vertices.source_pos;\
\
  location_s *blank_location = (location_s *)it.blank_location;\
\
  /* - initialize lengths array - */\
  a_lengths.used = 0;\
  a_lengths.copy_resize(vertices.used);\
\
  blank_location->v_reference_cnt.atomic_add(vertices.used);\
  a_lengths.fill(blank_location);\
\
  /* - initialize source indexes array- */\
  a_edge_idxs.used = 0;\
  a_edge_idxs.copy_resize(vertices.used);\
  a_edge_idxs.fill(c_idx_not_exist);\
\
  /* - create value vertex index set - */\
  value_idx_rb_tree_s vvi_set;\
  vvi_set.init();\
  vvi_set.ucl_prepare(it,source_pos);\
\
  unsigned *vi_vvi_map = (unsigned *)cmalloc(vertices.used*sizeof(unsigned));\
  memset(vi_vvi_map,c_idx_not_exist,vertices.used*sizeof(unsigned));\
\
  bool *v_done = (bool *)cmalloc(vertices.used*sizeof(bool));\
  memset(v_done,false,vertices.used*sizeof(bool));\
\
  /* - process source vertex - */\
  {\
    unsigned sv_idx = a_src_vertex_idx;\
\
    /* - mark vertex as processed - */\
    v_done[sv_idx] = true;\
\
    vertex_s &vertex = vertices[sv_idx];\
    edge_idxs_s &edge_idxs = vertex.edge_idxs;\
\
    if (edge_idxs.root_idx != c_idx_not_exist)\
    {\
      unsigned stack[RB_TREE_STACK_SIZE(edge_idxs)];\
      unsigned *stack_ptr = stack;\
\
      unsigned ei_idx = edge_idxs.get_stack_min_value_idx(edge_idxs.root_idx,&stack_ptr);\
      do\
      {\
        unsigned edge_idx = edge_idxs[ei_idx];\
        edge_s &edge = edges[edge_idx];\
\
        FIRST_VERTEX_EDGE_CODE\
\
        ei_idx = edge_idxs.get_stack_next_idx(ei_idx,&stack_ptr,stack);\
      }\
      while(ei_idx != c_idx_not_exist);\
    }\
  }\
\
  if (vvi_set.root_idx != c_idx_not_exist)\
  {\
    pointer tmp_length;\
    gf_uclvar_init(it,&tmp_length);\
\
    do {\
      unsigned vvi_idx = vvi_set.get_min_value_idx(vvi_set.root_idx);\
      unsigned sv_idx = vvi_set[vvi_idx].idx;\
\
      /* - mark vertex as processed - */\
      v_done[sv_idx] = true;\
\
      /* - if target vertex was found - */\
      if (sv_idx == a_trg_vertex_idx)\
      {\
        break;\
      }\
\
      /* - remove vertex from vertex set - */\
      vvi_set.remove(vvi_idx);\
\
      vertex_s &vertex = vertices[sv_idx];\
      edge_idxs_s &edge_idxs = vertex.edge_idxs;\
\
      if (edge_idxs.root_idx != c_idx_not_exist)\
      {\
        unsigned stack[RB_TREE_STACK_SIZE(edge_idxs)];\
        unsigned *stack_ptr = stack;\
\
        unsigned ei_idx = edge_idxs.get_stack_min_value_idx(edge_idxs.root_idx,&stack_ptr);\
        do\
        {\
          unsigned edge_idx = edge_idxs[ei_idx];\
          edge_s &edge = edges[edge_idx];\
\
          VERTEX_EDGE_CODE\
\
          ei_idx = edge_idxs.get_stack_next_idx(ei_idx,&stack_ptr,stack);\
        }\
        while(ei_idx != c_idx_not_exist);\
      }\
\
    } while(vvi_set.root_idx != c_idx_not_exist);\
\
    gf_uclvar_clear(it,tmp_length);\
  }\
\
  cfree(v_done);\
  cfree(vi_vvi_map);\
  vvi_set.clear();\
\
  return true;\
}/*}}}*/

bool graph_s::shortest_path_graph_dijkstra(unsigned a_src_vertex_idx,unsigned a_trg_vertex_idx,pointer_array_s &a_lengths,ui_array_s &a_edge_idxs)
{/*{{{*/

  SHORTEST_PATH_DIJKSTRA(

    SHORTEST_PATH_DIJKSTRA_FIRST_VERTEX_EDGE();

    // - target vertex index -
    unsigned tv_idx = sv_idx == edge.src_vertex_idx ?
        edge.trg_vertex_idx :
        edge.src_vertex_idx;

    SHORTEST_PATH_DIJKSTRA_PROC_LENGTH();
  ,
    SHORTEST_PATH_DIJKSTRA_VERTEX_EDGE();

    // - target vertex index -
    unsigned tv_idx = sv_idx == edge.src_vertex_idx ?
        edge.trg_vertex_idx :
        edge.src_vertex_idx;

    SHORTEST_PATH_DIJKSTRA_PROC_LENGTH();
  );

}/*}}}*/

bool graph_s::shortest_path_digraph_dijkstra(unsigned a_src_vertex_idx,unsigned a_trg_vertex_idx,pointer_array_s &a_lengths,ui_array_s &a_edge_idxs)
{/*{{{*/
  if (type != c_graph_type_digraph)
  {
    return false;
  }

  SHORTEST_PATH_DIJKSTRA(

    // - process only outgoing edges -
    if (edge.src_vertex_idx == sv_idx)
    {
      SHORTEST_PATH_DIJKSTRA_FIRST_VERTEX_EDGE();

      // - target vertex index -
      unsigned tv_idx = edge.trg_vertex_idx;

      SHORTEST_PATH_DIJKSTRA_PROC_LENGTH();
    }
  ,
    // - process only outgoing edges -
    if (edge.src_vertex_idx == sv_idx)
    {
      SHORTEST_PATH_DIJKSTRA_VERTEX_EDGE();

      // - target vertex index -
      unsigned tv_idx = edge.trg_vertex_idx;

      SHORTEST_PATH_DIJKSTRA_PROC_LENGTH();
    }
  );

}/*}}}*/

#define BFS_TARGET_VERTEX() \
{/*{{{*/\
  if (!v_used[tv_idx])\
  {\
    a_edge_idxs.push(edge_idx);\
\
    v_queue.insert(tv_idx);\
    v_used[tv_idx] = true;\
  }\
}/*}}}*/

#define BFS(EDGE_CODE) \
{/*{{{*/\
  a_edge_idxs.used = 0;\
\
  bool *v_used = (bool *)cmalloc(vertices.used*sizeof(bool));\
  memset(v_used,false,vertices.used*sizeof(bool));\
\
  ui_queue_s v_queue;\
  v_queue.init();\
\
  v_queue.insert(a_src_vertex_idx);\
  v_used[a_src_vertex_idx] = true;\
\
  do {\
    unsigned sv_idx = v_queue.next();\
\
    if (sv_idx == a_trg_vertex_idx)\
    {\
      v_queue.clear();\
      cfree(v_used);\
\
      return true;\
    }\
\
    edge_idxs_s &edge_idxs = vertices[sv_idx].edge_idxs;\
\
    if (edge_idxs.root_idx != c_idx_not_exist)\
    {\
      unsigned stack[RB_TREE_STACK_SIZE(edge_idxs)];\
      unsigned *stack_ptr = stack;\
\
      unsigned ei_idx = edge_idxs.get_stack_min_value_idx(edge_idxs.root_idx,&stack_ptr);\
      do\
      {\
        unsigned edge_idx = edge_idxs[ei_idx];\
        edge_s &edge = edges[edge_idx];\
\
        EDGE_CODE\
\
        ei_idx = edge_idxs.get_next_idx(ei_idx);\
      }\
      while(ei_idx != c_idx_not_exist);\
    }\
\
  } while(v_queue.used > 0);\
\
  v_queue.clear();\
  cfree(v_used);\
\
  return true;\
}/*}}}*/

bool graph_s::BFS_graph(unsigned a_src_vertex_idx,unsigned a_trg_vertex_idx,ui_array_s &a_edge_idxs)
{/*{{{*/

  BFS(
    unsigned tv_idx = sv_idx == edge.src_vertex_idx ?
      edge.trg_vertex_idx : edge.src_vertex_idx;

    BFS_TARGET_VERTEX();
  );

}/*}}}*/

bool graph_s::BFS_digraph(unsigned a_src_vertex_idx,unsigned a_trg_vertex_idx,ui_array_s &a_edge_idxs)
{/*{{{*/
  if (type != c_graph_type_digraph)
  {
    return false;
  }

  BFS(
    // - process only outgoing edges -
    if (sv_idx == edge.src_vertex_idx)
    {
      unsigned tv_idx = edge.trg_vertex_idx;

      BFS_TARGET_VERTEX();
    }
  );

}/*}}}*/

#define DFS_PUSH_VERTEX(V_IDX) \
{/*{{{*/\
  v_stack.push(V_IDX);\
  v_used[V_IDX] = true;\
\
  edge_idxs_s &edge_idxs = vertices[V_IDX].edge_idxs;\
  v_edge_idx[V_IDX] = edge_idxs.root_idx != c_idx_not_exist ?\
        edge_idxs.get_min_value_idx(edge_idxs.root_idx) : c_idx_not_exist;\
}/*}}}*/

#define DFS_TARGET_VERTEX() \
{/*{{{*/\
  if (!v_used[tv_idx])\
  {\
    a_edge_idxs.push(edge_idx);\
\
    DFS_PUSH_VERTEX(tv_idx);\
    break;\
  }\
}/*}}}*/

#define DFS(EDGE_CODE) \
{/*{{{*/\
  a_edge_idxs.used = 0;\
\
  bool *v_used = (bool *)cmalloc(vertices.used*sizeof(bool));\
  memset(v_used,false,vertices.used*sizeof(bool));\
\
  unsigned *v_edge_idx = (unsigned *)cmalloc(vertices.used*sizeof(unsigned));\
\
  ui_array_s v_stack;\
  v_stack.init();\
\
  DFS_PUSH_VERTEX(a_src_vertex_idx);\
\
  do {\
    unsigned sv_idx = v_stack.last();\
\
    /* - requested vertex was found - */\
    if (sv_idx == a_trg_vertex_idx)\
    {\
      v_stack.clear();\
      cfree(v_edge_idx);\
      cfree(v_used);\
\
      return true;\
    }\
\
    edge_idxs_s &edge_idxs = vertices[sv_idx].edge_idxs;\
    unsigned &ei_idx = v_edge_idx[sv_idx];\
\
    do {\
      unsigned edge_idx = edge_idxs[ei_idx];\
      edge_s &edge = edges[edge_idx];\
\
      EDGE_CODE\
\
      if ((ei_idx = edge_idxs.get_next_idx(ei_idx)) == c_idx_not_exist)\
      {\
        /* - remove vertex from stack - */\
        v_stack.pop();\
        break;\
      }\
\
    } while(1);\
\
  } while(v_stack.used > 0);\
\
  v_stack.clear();\
  cfree(v_edge_idx);\
  cfree(v_used);\
\
  return true;\
}/*}}}*/

bool graph_s::DFS_graph(unsigned a_src_vertex_idx,unsigned a_trg_vertex_idx,ui_array_s &a_edge_idxs)
{/*{{{*/

  DFS(
    unsigned tv_idx = sv_idx == edge.src_vertex_idx ?
      edge.trg_vertex_idx : edge.src_vertex_idx;

    DFS_TARGET_VERTEX();
  );

}/*}}}*/

bool graph_s::DFS_digraph(unsigned a_src_vertex_idx,unsigned a_trg_vertex_idx,ui_array_s &a_edge_idxs)
{/*{{{*/
  if (type != c_graph_type_digraph)
  {
    return false;
  }

  DFS(
    // - process only outgoing edges -
    if (edge.src_vertex_idx == sv_idx)
    {
      unsigned tv_idx = edge.trg_vertex_idx;

      DFS_TARGET_VERTEX();
    }
  );

}/*}}}*/

bool graph_s::strongly_connected_components_tarjans(ui_array_s &a_comp_idxs)
{/*{{{*/

  // - digraph is expected -
  if (type != c_graph_type_digraph)
  {
    return false;
  }

  a_comp_idxs.used = 0;

  // - if there are no vertices in graph -
  if (vertices.used == 0)
  {
    return true;
  }

  a_comp_idxs.copy_resize(vertices.used);
  a_comp_idxs.used = a_comp_idxs.size;
  memset(a_comp_idxs.data,c_idx_not_exist,a_comp_idxs.used*sizeof(unsigned));

  unsigned *v_edge_idx = (unsigned *)cmalloc(vertices.used*sizeof(unsigned));

  ui_array_s v_stack;
  v_stack.init();

  unsigned mark = 0;

  // - process all vertices -
  unsigned stack[RB_TREE_STACK_SIZE(vertices)];
  unsigned *stack_ptr = stack;

  unsigned v_idx = vertices.get_stack_min_value_idx(vertices.root_idx,&stack_ptr);
  do
  {
    // - if vertex was not processed yet -
    if (a_comp_idxs[v_idx] == c_idx_not_exist)
    {
      // - push vertex to stack -
      v_stack.push(v_idx);

      do {
        unsigned sv_idx = v_stack.last();

        edge_idxs_s &edge_idxs = vertices[sv_idx].edge_idxs;
        unsigned &ei_idx = v_edge_idx[sv_idx];

        // - if vertex mark is not set -
        if (a_comp_idxs[sv_idx] == c_idx_not_exist)
        {
          // - initialize vertex mark -
          a_comp_idxs[sv_idx] = mark++;

          // - initialize vertex edge idx -
          ei_idx = edge_idxs.root_idx != c_idx_not_exist ?
            edge_idxs.get_min_value_idx(edge_idxs.root_idx) : c_idx_not_exist;
        }

        // - traverse throught vertex incident edges -
        do {

          // - if there are no more edges -
          if (ei_idx == c_idx_not_exist)
          {
            // - remove vertex from stack -
            v_stack.pop();

            break;
          }

          edge_s &edge = edges[edge_idxs[ei_idx]];
          if (edge.src_vertex_idx == sv_idx)
          {
            unsigned &m_trg = a_comp_idxs[edge.trg_vertex_idx];

            // - if target vertex was processed -
            if (m_trg != c_idx_not_exist)
            {
              unsigned &m_src = a_comp_idxs[edge.src_vertex_idx];

              if (m_trg < m_src)
              {
                m_src = m_trg;
              }
            }

            // - if target vertex was not processed -
            else
            {
              // - push vertex to vertex stack -
              v_stack.push(edge.trg_vertex_idx);

              break;
            }
          }

          ei_idx = edge_idxs.get_next_idx(ei_idx);
        } while(1);

      } while(v_stack.used > 0);
    }

    v_idx = vertices.get_stack_next_idx(v_idx,&stack_ptr,stack);
  }
  while(v_idx != c_idx_not_exist);

  v_stack.clear();
  cfree(v_edge_idx);

  return true;
}/*}}}*/

bool graph_s::is_weakly_connected_graph()
{/*{{{*/
  if (vertices.count <= 1)
  {
    return true;
  }

  bool *v_map = (bool *)cmalloc(vertices.used*sizeof(bool));
  memset(v_map,false,vertices.used*sizeof(bool));

  bool *e_map = (bool *)cmalloc(edges.used*sizeof(bool));
  memset(e_map,false,edges.used*sizeof(bool));

  // - traverse throught all edges, closure incident to vertices of first edge -
  if (edges.root_idx != c_idx_not_exist)
  {
    ui_array_s edge_stack;
    edge_stack.init();

    // - push first edge on stack and mark it -
    e_map[edges.root_idx] = true;
    edge_stack.push(edges.root_idx);

    do
    {
      edge_s &edge = edges[edge_stack.pop()];

      // - if edge source vertex was not processed -
      if (!v_map[edge.src_vertex_idx])
      {
        // - traverse throught its incident edges -
        edge_idxs_s &edge_idxs = vertices[edge.src_vertex_idx].edge_idxs;
        if (edge_idxs.root_idx != c_idx_not_exist)
        {
          unsigned stack[RB_TREE_STACK_SIZE(edge_idxs)];
          unsigned *stack_ptr = stack;

          unsigned ei_idx = edge_idxs.get_stack_min_value_idx(edge_idxs.root_idx,&stack_ptr);
          do
          {
            // - if edge was not processed push it on the stack and process it -
            if (!e_map[edge_idxs[ei_idx]])
            {
              edge_stack.push(edge_idxs[ei_idx]);
              e_map[edge_idxs[ei_idx]] = true;
            }

            ei_idx = edge_idxs.get_stack_next_idx(ei_idx,&stack_ptr,stack);
          }
          while(ei_idx != c_idx_not_exist);
        }

        // - mark vertex as processed -
        v_map[edge.src_vertex_idx] = true;
      }

      // - if edge target vertex was not processed -
      if (!v_map[edge.trg_vertex_idx])
      {
        // - traverse throught its incident edges -
        edge_idxs_s &edge_idxs = vertices[edge.trg_vertex_idx].edge_idxs;
        if (edge_idxs.root_idx != c_idx_not_exist)
        {
          unsigned stack[RB_TREE_STACK_SIZE(edge_idxs)];
          unsigned *stack_ptr = stack;

          unsigned ei_idx = edge_idxs.get_stack_min_value_idx(edge_idxs.root_idx,&stack_ptr);
          do
          {
            // - if edge was not processed push it on the stack and process it -
            if (!e_map[edge_idxs[ei_idx]])
            {
              edge_stack.push(edge_idxs[ei_idx]);
              e_map[edge_idxs[ei_idx]] = true;
            }

            ei_idx = edge_idxs.get_stack_next_idx(ei_idx,&stack_ptr,stack);
          }
          while(ei_idx != c_idx_not_exist);
        }

        // - mark vertex as processed -
        v_map[edge.trg_vertex_idx] = true;
      }

    }
    while(edge_stack.used > 0);

    edge_stack.clear();
  }

  // - test if all vertices was accesed (if not graph is not connected) -
  {
    unsigned stack[RB_TREE_STACK_SIZE(vertices)];
    unsigned *stack_ptr = stack;

    unsigned v_idx = vertices.get_stack_min_value_idx(vertices.root_idx,&stack_ptr);
    do
    {
      if (!v_map[v_idx])
      {
        cfree(v_map);
        cfree(e_map);

        return false;
      }

      v_idx = vertices.get_stack_next_idx(v_idx,&stack_ptr,stack);
    }
    while(v_idx != c_idx_not_exist);

    cfree(v_map);
    cfree(e_map);

    return true;
  }
}/*}}}*/

bool graph_s::is_strongly_connected_graph_tarjans()
{/*{{{*/
  if (vertices.count <= 1)
  {
    return true;
  }

  unsigned *v_mark = (unsigned *)cmalloc(vertices.used*sizeof(unsigned));
  memset(v_mark,c_idx_not_exist,vertices.used*sizeof(unsigned));

  unsigned *v_edge_idx = (unsigned *)cmalloc(vertices.used*sizeof(unsigned));

  ui_array_s v_stack;
  v_stack.init();
  v_stack.push(vertices.root_idx);

  unsigned mark = 0;
  do {
    unsigned vertex_idx = v_stack.last();

    edge_idxs_s &edge_idxs = vertices[vertex_idx].edge_idxs;
    unsigned &ei_idx = v_edge_idx[vertex_idx];

    // - if vertex mark is not set -
    if (v_mark[vertex_idx] == c_idx_not_exist)
    {
      // - initialize vertex mark -
      v_mark[vertex_idx] = mark++;

      // - initialize vertex edge idx -
      ei_idx = edge_idxs.root_idx != c_idx_not_exist ?
        edge_idxs.get_min_value_idx(edge_idxs.root_idx) : c_idx_not_exist;
    }

    // - traverse throught vertex incident edges -
    do {

      // - if there are no more edges -
      if (ei_idx == c_idx_not_exist)
      {
        // - remove vertex from stack -
        v_stack.pop();

        break;
      }

      edge_s &edge = edges[edge_idxs[ei_idx]];
      if (edge.src_vertex_idx == vertex_idx)
      {
        unsigned &m_trg = v_mark[edge.trg_vertex_idx];

        // - if target vertex was processed -
        if (m_trg != c_idx_not_exist)
        {
          unsigned &m_src = v_mark[edge.src_vertex_idx];

          if (m_trg < m_src)
          {
            m_src = m_trg;
          }
        }

        // - if target vertex was not processed -
        else
        {
          // - push vertex to vertex stack -
          v_stack.push(edge.trg_vertex_idx);

          break;
        }
      }

      ei_idx = edge_idxs.get_next_idx(ei_idx);
    } while(1);

  } while(v_stack.used > 0);

  v_stack.clear();

  // - test if all vertices fall in one component -
  {
    unsigned stack[RB_TREE_STACK_SIZE(vertices)];
    unsigned *stack_ptr = stack;

    unsigned v_idx = vertices.get_stack_min_value_idx(vertices.root_idx,&stack_ptr);
    do
    {
      if (v_mark[v_idx] != 0)
      {
        cfree(v_mark);
        cfree(v_edge_idx);

        return false;
      }

      v_idx = vertices.get_stack_next_idx(v_idx,&stack_ptr,stack);
    }
    while(v_idx != c_idx_not_exist);

    cfree(v_mark);
    cfree(v_edge_idx);

    return true;
  }
}/*}}}*/

bool graph_s::is_regular_graph()
{/*{{{*/
  if (vertices.count == 0)
  {
    return true;
  }

  unsigned stack[RB_TREE_STACK_SIZE(vertices)];
  unsigned *stack_ptr = stack;

  unsigned v_idx = vertices.get_stack_min_value_idx(vertices.root_idx,&stack_ptr);
  unsigned regular_degree = vertices[v_idx].get_degree();

  // - if graph is regular all vertices has same (regular) degree -
  v_idx = vertices.get_stack_next_idx(v_idx,&stack_ptr,stack);
  if (v_idx != c_idx_not_exist)
  {
    do
    {
      if (vertices[v_idx].get_degree() != regular_degree)
      {
        return false;
      }

      v_idx = vertices.get_stack_next_idx(v_idx,&stack_ptr,stack);
    }
    while(v_idx != c_idx_not_exist);
  }

  return true;
}/*}}}*/

bool graph_s::generate_connected(unsigned a_vertex_cnt,unsigned a_edge_cnt,unsigned a_graph_type)
{/*{{{*/

  // - test given parameters -
  if (a_vertex_cnt <= 1 || a_edge_cnt < a_vertex_cnt - 1 ||
      (a_graph_type != c_graph_type_graph && a_graph_type != c_graph_type_digraph))
  {
    return false;
  }

  clear();

  // - create new location -
  interpreter_thread_s &it = *((interpreter_thread_s *)vertices.it_ptr);
  BIC_CREATE_NEW_LOCATION_REFS(new_location,c_bi_class_integer,0,0);

  // - set graph type -
  type = a_graph_type;

  // - create vertex map array -
#ifdef _MSC_VER
  unsigned *vertex_map = (unsigned *)cmalloc(a_vertex_cnt*sizeof(unsigned));
#else
  unsigned vertex_map[a_vertex_cnt];
#endif

  // - insert vertices to graph -
  {
    unsigned idx = 0;
    do {
      vertex_map[idx] = insert_vertex(new_location);
    } while(++idx < a_vertex_cnt);
  }

  // - no loops and multiple edges -
  bb_array_s imat;
  imat.init_size(vertices.used*vertices.used);
  imat.used = imat.size;
  memset(imat.data,false,imat.used*sizeof(bool));

  // - create unused vertices array -
#ifdef _MSC_VER
  bool *used_vertices = (bool *)cmalloc(a_vertex_cnt*sizeof(bool));
#else
  bool used_vertices[a_vertex_cnt];
#endif
  memset(used_vertices,false,a_vertex_cnt*sizeof(bool));

  // - create graph spanning tree -
  unsigned unused_vertex_cnt = a_vertex_cnt;
  unsigned v_idx = rand()%(unused_vertex_cnt--);
  used_vertices[v_idx] = true;

  do {
    unsigned last_v_idx = v_idx;
    v_idx = rand()%(unused_vertex_cnt--);

    unsigned idx = 0;
    do {
      if (!used_vertices[idx]) {
        if (v_idx-- == 0) {
          v_idx = idx;
          break;
        }
      }
    } while(++idx);

    used_vertices[v_idx] = true;

    unsigned sv_idx = vertex_map[last_v_idx];
    unsigned tv_idx = vertex_map[v_idx];

    // - insert edge between vertices -
    insert_edge(sv_idx,tv_idx,new_location);
    imat[sv_idx*vertices.used + tv_idx] = true;

  } while(unused_vertex_cnt > 0);

#ifdef _MSC_VER
  cfree(used_vertices);
#endif

  unsigned edge_cnt = a_edge_cnt - (a_vertex_cnt - 1);
  if (edge_cnt > 0) {
    do {

      // - insert edge between random vertices -
      unsigned sv_idx = vertex_map[rand()%a_vertex_cnt];
      unsigned tv_idx = vertex_map[rand()%a_vertex_cnt];

      if (!imat[sv_idx*vertices.used + tv_idx])
      {
        insert_edge(sv_idx,tv_idx,new_location);
        imat[sv_idx*vertices.used + tv_idx] = true;
        --edge_cnt;
      }
    } while(edge_cnt > 0);
  }

  imat.clear();

#ifdef _MSC_VER
  cfree(vertex_map);
#endif

  return true;
}/*}}}*/

void graph_s::get_dot_code_params(string_s &a_string,const char *a_header,const char *a_node_prefix,const char *a_indent)
{/*{{{*/
  string_array_s str_array;
  str_array.init();

  str_array.push_blank();
  str_array.last().setf("%s",a_header);

  string_s value_str;
  value_str.init();

  // - traverse thought vertices and print their values to output -
  if (vertices.root_idx != c_idx_not_exist)
  {
    unsigned stack[RB_TREE_STACK_SIZE(vertices)];
    unsigned *stack_ptr = stack;

    unsigned v_idx = vertices.get_stack_min_value_idx(vertices.root_idx,&stack_ptr);
    do
    {
      vertices.vf_get_string(vertices[v_idx].value,value_str);

      if (value_str.size > 1)
      {
        str_array.push_blank();
        str_array.last().setf("%s   %snode_%u [ label = %s ]\n",a_indent,a_node_prefix,v_idx,value_str.data);
      }
      else
      {
        str_array.push_blank();
        str_array.last().setf("%s   %snode_%u [ label = %u ]\n",a_indent,a_node_prefix,v_idx,v_idx);
      }

      v_idx = vertices.get_stack_next_idx(v_idx,&stack_ptr,stack);
    }
    while(v_idx != c_idx_not_exist);
  }

  // - traverse thought edges and print their values to output -
  if (edges.root_idx != c_idx_not_exist)
  {
    unsigned stack[RB_TREE_STACK_SIZE(edges)];
    unsigned *stack_ptr = stack;

    unsigned e_idx = edges.get_stack_min_value_idx(edges.root_idx,&stack_ptr);
    do
    {
      edge_s &edge = edges[e_idx];

      edges.ef_get_string(edge.value,value_str);

      if (value_str.size > 1)
      {
        str_array.push_blank();
        str_array.last().setf("%s   /* %snode_%u_%snode_%u */ %snode_%u %s %snode_%u [ label = %s ]\n",
            a_indent,a_node_prefix,edge.src_vertex_idx,a_node_prefix,edge.trg_vertex_idx,a_node_prefix,
            edge.src_vertex_idx,c_graph_type_dot_codes[type],a_node_prefix,edge.trg_vertex_idx,value_str.data);
      }
      else
      {
        str_array.push_blank();
        str_array.last().setf("%s   /* %snode_%u_%snode_%u */ %snode_%u %s %snode_%u [ label = %u ]\n",
            a_indent,a_node_prefix,edge.src_vertex_idx,a_node_prefix,edge.trg_vertex_idx,a_node_prefix,
            edge.src_vertex_idx,c_graph_type_dot_codes[type],a_node_prefix,edge.trg_vertex_idx,e_idx);
      }

      e_idx = edges.get_stack_next_idx(e_idx,&stack_ptr,stack);
    }
    while(e_idx != c_idx_not_exist);
  }

  value_str.clear();

  str_array.push_blank();
  str_array.last().setf("%s}\n",a_indent);

  str_array.join(a_string);
  str_array.clear();
}/*}}}*/

void graph_s::get_dot_code(string_s &a_string)
{/*{{{*/
  string_array_s str_array;
  str_array.init();

  switch (type)
  {
  case c_graph_type_graph:
    str_array.push_blank();
    str_array.last().setf("%s","graph G {\n");
    break;
  case c_graph_type_digraph:
    str_array.push_blank();
    str_array.last().setf("%s","digraph G {\n");
    break;
  default:
    cassert(0);
  }

  str_array.push_blank();
  str_array.last().setf("%s",
      "   rankdir = LR\n"
      "   node [ shape = ellipse ]\n"
      "\n"
      );

  str_array.push_blank();
  get_dot_code_params(str_array.last(),"","","");

  str_array.join(a_string);
  str_array.clear();
}/*}}}*/

// -- value_idx_s --
@begin
methods value_idx_s
@end

// -- value_idx_rb_tree_s --
@begin
methods value_idx_rb_tree_s
@end

