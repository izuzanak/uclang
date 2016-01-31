
#ifndef __UCL_GRAPH_H
#define __UCL_GRAPH_H

/*
 * header files
 */

@begin
include "script_parser.h"
@end

/*
 * constants and definitions
 */

// - graph types count -
const unsigned c_graph_type_cnt = 2;

// - list of graph types -
enum
{
  c_graph_type_graph = 0,
  c_graph_type_digraph
};

// - strings of graph type dot codes -
extern const char *c_graph_type_dot_codes[c_graph_type_cnt];

// - list of graph function types -
enum
{
  c_graph_function_init = 0,
  c_graph_function_compare,
  c_graph_function_operator_equal,
  c_graph_function_get_string,
  c_graph_function_clear,
};

// - declarations of graph functions for precreated types -
inline void gf_uclvar_init(interpreter_thread_s &it,void **a_value_ptr);
int gf_uclvar_compare(interpreter_thread_s &it,unsigned source_pos,void *a_first,void *a_second);
inline void gf_uclvar_operator_equal(interpreter_thread_s &it,void **a_trg,void *a_src);
void gf_uclvar_operator_plus(interpreter_thread_s &it,unsigned source_pos,void **a_trg,void *a_first,void *a_second);
void gf_uclvar_get_string(interpreter_thread_s &it,unsigned source_pos,void *a_value,string_s &a_string);
inline void gf_uclvar_clear(interpreter_thread_s &it,void *a_value);

/*
 * definition of generated structures
 */

// -- bb_array_s --
@begin
array<bool> bb_array_s;
@end

// -- gg_vertex_map_s --
@begin
struct
    <
    unsigned:sv_idx
    unsigned:mv_idx
    unsigned:prev_map_idx
    unsigned:reference_cnt
    unsigned:next_edge_idx
    unsigned:length
    >
    gg_vertex_map_s;
@end

// -- edge_s --
@begin
struct
    <
    pointer:value
    unsigned:src_vertex_idx
    unsigned:trg_vertex_idx
    >
    edge_s;
@end

// -- edge_rb_tree_s --
@begin
safe_rb_tree
<
edge_s
pointer:it_ptr
unsigned:source_pos
>

additions
{
  inline void ef_init(void **a_value_ptr);
  inline int ef_compare(void *a_first,void *a_second);
  inline void ef_operator_equal(void **a_trg,void *a_src);
  inline void ef_get_string(void *a_value,string_s &a_string);
  inline void ef_clear(void *a_value);
}

edge_rb_tree_s;
@end

// -- edge_idxs_s --
@begin
safe_rb_tree<unsigned
pointer:graph_ptr
unsigned:vertex_idx
>

additions
{
  inline int compare_edges(edge_s &a_f_edge,edge_s &a_s_edge);
  void get_edge_idxs_by_edge(edge_s &a_edge,ui_array_s &a_edge_idxs,unsigned &a_edge_cnt);
}

edge_idxs_s;
@end

// -- vertex_s --
@begin
struct
    <
    pointer:value
    unsigned:input_degree
    unsigned:output_degree
    edge_idxs_s:edge_idxs
    >

    additions
{
  inline unsigned get_degree();
}

vertex_s;
@end

// -- vertex_rb_tree_s --
@begin
safe_rb_tree
<
vertex_s
pointer:it_ptr
unsigned:source_pos
>

additions
{
  inline void vf_init(void **a_value_ptr);
  inline int vf_compare(void *a_first,void *a_second);
  inline void vf_operator_equal(void **a_trg,void *a_src);
  inline void vf_get_string(void *a_value,string_s &a_string);
  inline void vf_clear(void *a_value);
}

vertex_rb_tree_s;
@end

// -- graph_s --
@begin
struct
    <
    unsigned:type
    vertex_rb_tree_s:vertices
    edge_rb_tree_s:edges
    >
    options ( no_init no_clear no_swap no_copy strict_dynamic )
    additions
{

  inline void init();
  inline void init(unsigned a_type);
  void clear();

  void swap(graph_s &second);
  graph_s &operator=(graph_s &second);
  void duplicate(graph_s &a_src);

  inline void ucl_prepare(interpreter_thread_s &a_it,unsigned a_source_pos);
  inline bool ucl_check_vertex_idx(long long int a_idx);
  inline bool ucl_check_edge_idx(long long int a_idx);

  inline bool edge_src_trg_vertex_idxs_compare(edge_s &a_first,edge_s &a_second);
  inline unsigned __insert_swap_vertex(vertex_s &a_vertex);
  inline unsigned insert_vertex_move_value(void *a_value);
  inline unsigned insert_vertex(void *a_value);
  inline unsigned __insert_swap_edge(unsigned a_sv_idx,unsigned a_tv_idx,edge_s &a_edge);
  inline unsigned insert_edge_move_value(unsigned a_sv_idx,unsigned a_tv_idx,void *a_value);
  inline unsigned insert_edge(unsigned a_sv_idx,unsigned a_tv_idx,void *a_value);
  inline void remove_vertex(unsigned a_idx,bool a_free_eval);
  inline void remove_edge(unsigned a_idx,bool a_free_eval);

  void adjacent_vertices(unsigned a_vertex_idx,ui_array_s &a_vertex_idxs);
  void incident_edges(unsigned a_vertex_idx,ui_array_s &a_edge_idxs);
  void degree_sequence(ui_array_s &a_degree_sequence);

  bool minimum_spanning_tree_kruskals(ui_array_s &a_edge_idxs);
  bool shortest_path_graph_dijkstra(unsigned a_src_vertex_idx,unsigned a_trg_vertex_idx,pointer_array_s &a_lengths,ui_array_s &a_edge_idxs);
  bool shortest_path_digraph_dijkstra(unsigned a_src_vertex_idx,unsigned a_trg_vertex_idx,pointer_array_s &a_lengths,ui_array_s &a_edge_idxs);
  bool BFS_graph(unsigned a_src_vertex_idx,unsigned a_trg_vertex_idx,ui_array_s &a_edge_idxs);
  bool BFS_digraph(unsigned a_src_vertex_idx,unsigned a_trg_vertex_idx,ui_array_s &a_edge_idxs);
  bool DFS_graph(unsigned a_src_vertex_idx,unsigned a_trg_vertex_idx,ui_array_s &a_edge_idxs);
  bool DFS_digraph(unsigned a_src_vertex_idx,unsigned a_trg_vertex_idx,ui_array_s &a_edge_idxs);
  bool strongly_connected_components_tarjans(ui_array_s &a_comp_idxs);

  bool is_weakly_connected_graph();
  bool is_strongly_connected_graph_tarjans();
  bool is_regular_graph();

  bool generate_connected(unsigned a_vertex_cnt,unsigned a_edge_cnt,unsigned a_graph_type);

  void get_dot_code_params(string_s &a_string,const char *a_header,const char *a_node_prefix,const char *a_indent);
  void get_dot_code(string_s &a_string);
}

graph_s;
@end

// -- value_idx_s --
@begin
   struct
   <
   pointer:value
   unsigned:idx
   >
   value_idx_s;
@end

// -- value_idx_rb_tree_s --
@begin
  rb_tree<
  value_idx_s
  pointer:it_ptr
  unsigned:source_pos
  >

  additions
{
  inline void ucl_prepare(interpreter_thread_s &a_it,unsigned a_source_pos);
}

value_idx_rb_tree_s;
@end

/*
 * definition of structure graph_vertex_s
 */

struct graph_vertex_s
{
  location_s *graph_ptr;
  unsigned vertex_idx;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure graph_edge_s
 */

struct graph_edge_s
{
  location_s *graph_ptr;
  unsigned edge_idx;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure subgraph_s
 */

struct subgraph_s
{
  location_s *graph_ptr;
  ui_array_s vertex_idxs;
  ui_array_s edge_idxs;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure graph_paths_s
 */

struct graph_paths_s
{
  location_s *graph_ptr;
  location_s *lengths_arr;
  unsigned src_vertex_idx;
  ui_array_s edge_idxs;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

// - inline graph functions for uclang variable types -

inline void gf_uclvar_init(interpreter_thread_s &it,void **a_value_ptr)
{/*{{{*/
  ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();
  *a_value_ptr = (void *)it.blank_location;
}/*}}}*/

inline void gf_uclvar_operator_equal(interpreter_thread_s &it,void **a_trg,void *a_src)
{/*{{{*/
  ((location_s *)a_src)->v_reference_cnt.atomic_inc();
  it.release_location_ptr((location_s *)*a_trg);
  *a_trg = a_src;
}/*}}}*/

inline void gf_uclvar_clear(interpreter_thread_s &it,void *a_value)
{/*{{{*/
  it.release_location_ptr((location_s *)a_value);
}/*}}}*/

/*
 * inline methods of generated structures
 */

// -- bb_array_s --
@begin
inlines bb_array_s
@end

// -- gg_vertex_map_s --
@begin
inlines gg_vertex_map_s
@end

// -- edge_s --
@begin
inlines edge_s
@end

// -- edge_rb_tree_s --
@begin
inlines edge_rb_tree_s
@end

inline int edge_rb_tree_s::__compare_value(edge_s &a_first,edge_s &a_second)
{/*{{{*/
  return ef_compare(a_first.value,a_second.value);
}/*}}}*/

inline void edge_rb_tree_s::ef_init(void **a_value_ptr)
{/*{{{*/
  gf_uclvar_init(*((interpreter_thread_s *)it_ptr),a_value_ptr);
}/*}}}*/

inline int edge_rb_tree_s::ef_compare(void *a_first,void *a_second)
{/*{{{*/
  return gf_uclvar_compare(*((interpreter_thread_s *)it_ptr),source_pos,a_first,a_second);
}/*}}}*/

inline void edge_rb_tree_s::ef_operator_equal(void **a_trg,void *a_src)
{/*{{{*/
  gf_uclvar_operator_equal(*((interpreter_thread_s *)it_ptr),a_trg,a_src);
}/*}}}*/

inline void edge_rb_tree_s::ef_get_string(void *a_value,string_s &a_string)
{/*{{{*/
  gf_uclvar_get_string(*((interpreter_thread_s *)it_ptr),source_pos,a_value,a_string);
}/*}}}*/

inline void edge_rb_tree_s::ef_clear(void *a_value)
{/*{{{*/
  gf_uclvar_clear(*((interpreter_thread_s *)it_ptr),a_value);
}/*}}}*/

// -- edge_idxs_s --
@begin
inlines edge_idxs_s
@end

inline int edge_idxs_s::compare_edges(edge_s &a_f_edge,edge_s &a_s_edge)
{/*{{{*/
  edge_rb_tree_s &edges = ((graph_s *)graph_ptr)->edges;
  vertex_rb_tree_s &vertices = ((graph_s *)graph_ptr)->vertices;

  // - test edge evaluations -
  unsigned cmp_res = edges.ef_compare(a_f_edge.value,a_s_edge.value);
  if (cmp_res != 0) return cmp_res;

  unsigned f_tv_idx;
  unsigned s_tv_idx;

  bool f_orientation;
  bool s_orientation;

  // - find first edge target vertex and orientation -
  if (a_s_edge.src_vertex_idx == vertex_idx)
  {
    f_tv_idx = a_s_edge.trg_vertex_idx;
    f_orientation = true;
  }
  else
  {
    f_tv_idx = a_s_edge.src_vertex_idx;
    f_orientation = false;
  }

  // - find second edge target vertex and orientation -
  if (a_f_edge.src_vertex_idx == vertex_idx)
  {
    s_tv_idx = a_f_edge.trg_vertex_idx;
    s_orientation = true;
  }
  else
  {
    s_tv_idx = a_f_edge.src_vertex_idx;
    s_orientation = false;
  }

  cmp_res = vertices.vf_compare(vertices[f_tv_idx].value,vertices[s_tv_idx].value);
  if (cmp_res != 0) return cmp_res;

  if (((graph_s *)graph_ptr)->type == c_graph_type_digraph && f_orientation != s_orientation)
  {
    return f_orientation?-1:1;
  }

  return f_tv_idx < s_tv_idx?-1:f_tv_idx > s_tv_idx;
}/*}}}*/

inline int edge_idxs_s::__compare_value(unsigned &a_first,unsigned &a_second)
{/*{{{*/
  edge_rb_tree_s &edges = ((graph_s *)graph_ptr)->edges;

  int res = compare_edges(edges[a_first],edges[a_second]);
  if (res != 0)
  {
    return res;
  }

  return a_first < a_second?-1:a_second < a_first;
}/*}}}*/

// -- vertex_s --
@begin
inlines vertex_s
@end

inline unsigned vertex_s::get_degree()
{/*{{{*/
  return input_degree + output_degree;
}/*}}}*/

// -- vertex_rb_tree_s --
@begin
inlines vertex_rb_tree_s
@end

inline int vertex_rb_tree_s::__compare_value(vertex_s &a_first,vertex_s &a_second)
{/*{{{*/
  return vf_compare(a_first.value,a_second.value);
}/*}}}*/

inline void vertex_rb_tree_s::vf_init(void **a_value_ptr)
{/*{{{*/
  gf_uclvar_init(*((interpreter_thread_s *)it_ptr),a_value_ptr);
}/*}}}*/

inline int vertex_rb_tree_s::vf_compare(void *a_first,void *a_second)
{/*{{{*/
  return gf_uclvar_compare(*((interpreter_thread_s *)it_ptr),source_pos,a_first,a_second);
}/*}}}*/

inline void vertex_rb_tree_s::vf_operator_equal(void **a_trg,void *a_src)
{/*{{{*/
  gf_uclvar_operator_equal(*((interpreter_thread_s *)it_ptr),a_trg,a_src);
}/*}}}*/

inline void vertex_rb_tree_s::vf_get_string(void *a_value,string_s &a_string)
{/*{{{*/
  gf_uclvar_get_string(*((interpreter_thread_s *)it_ptr),source_pos,a_value,a_string);
}/*}}}*/

inline void vertex_rb_tree_s::vf_clear(void *a_value)
{/*{{{*/
  gf_uclvar_clear(*((interpreter_thread_s *)it_ptr),a_value);
}/*}}}*/

// -- graph_s --
@begin
inlines graph_s
@end

inline void graph_s::init()
{/*{{{*/
  init(c_graph_type_digraph);
}/*}}}*/

inline void graph_s::init(unsigned a_type)
{/*{{{*/
  type = a_type;
  vertices.init();
  edges.init();
}/*}}}*/

inline void graph_s::ucl_prepare(interpreter_thread_s &a_it,unsigned a_source_pos)
{/*{{{*/

  // - update references to interpreter thread -
  vertices.it_ptr = &a_it;
  edges.it_ptr = &a_it;

  // - update source position -
  vertices.source_pos = a_source_pos;
  edges.source_pos = a_source_pos;
}/*}}}*/

inline bool graph_s::ucl_check_vertex_idx(long long int a_idx)
{/*{{{*/
  if (a_idx < 0 || a_idx > vertices.used)
  {
    return false;
  }

  return vertices.data[a_idx].valid;
}/*}}}*/

inline bool graph_s::ucl_check_edge_idx(long long int a_idx)
{/*{{{*/
  if (a_idx < 0 || a_idx > edges.used)
  {
    return false;
  }

  return edges.data[a_idx].valid;
}/*}}}*/

inline bool graph_s::edge_src_trg_vertex_idxs_compare(edge_s &a_first,edge_s &a_second)
{/*{{{*/
  return (type == c_graph_type_digraph)?
         (a_first.src_vertex_idx == a_second.src_vertex_idx && a_first.trg_vertex_idx == a_second.trg_vertex_idx):
         (a_first.src_vertex_idx == a_second.src_vertex_idx && a_first.trg_vertex_idx == a_second.trg_vertex_idx) ||
         (a_first.src_vertex_idx == a_second.trg_vertex_idx && a_first.trg_vertex_idx == a_second.src_vertex_idx);
}/*}}}*/

inline unsigned graph_s::__insert_swap_vertex(vertex_s &a_vertex)
{/*{{{*/
  a_vertex.input_degree = 0;
  a_vertex.output_degree = 0;

  unsigned vertex_idx = vertices.swap_insert(a_vertex);

  // - set edge indexes structure pointers and vertex index -
  edge_idxs_s &edge_idxs = vertices[vertex_idx].edge_idxs;
  edge_idxs.graph_ptr = (pointer)this;
  edge_idxs.vertex_idx = vertex_idx;

  return vertex_idx;
}/*}}}*/

inline unsigned graph_s::insert_vertex_move_value(void *a_value)
{/*{{{*/
  vertex_s new_vertex;
  new_vertex.init();
  new_vertex.value = a_value;

  unsigned vertex_idx = __insert_swap_vertex(new_vertex);
  new_vertex.clear();

  return vertex_idx;
}/*}}}*/

inline unsigned graph_s::insert_vertex(void *a_value)
{/*{{{*/
  vertex_s new_vertex;
  new_vertex.init();

  vertices.vf_init(&new_vertex.value);
  vertices.vf_operator_equal(&new_vertex.value,a_value);

  unsigned vertex_idx = __insert_swap_vertex(new_vertex);
  new_vertex.clear();

  return vertex_idx;
}/*}}}*/

inline unsigned graph_s::__insert_swap_edge(unsigned a_sv_idx,unsigned a_tv_idx,edge_s &a_edge)
{/*{{{*/
  vertex_s &src_vertex = vertices[a_sv_idx];
  vertex_s &trg_vertex = vertices[a_tv_idx];

  a_edge.src_vertex_idx = a_sv_idx;
  a_edge.trg_vertex_idx = a_tv_idx;

  unsigned edge_idx = edges.swap_insert(a_edge);

  src_vertex.output_degree++;
  src_vertex.edge_idxs.insert(edge_idx);

  trg_vertex.input_degree++;
  if (a_sv_idx != a_tv_idx)
  {
    trg_vertex.edge_idxs.insert(edge_idx);
  }

  return edge_idx;
}/*}}}*/

inline unsigned graph_s::insert_edge_move_value(unsigned a_sv_idx,unsigned a_tv_idx,void *a_value)
{/*{{{*/
  edge_s new_edge;
  new_edge.init();
  new_edge.value = a_value;

  unsigned edge_idx = __insert_swap_edge(a_sv_idx,a_tv_idx,new_edge);
  new_edge.clear();

  return edge_idx;
}/*}}}*/

inline unsigned graph_s::insert_edge(unsigned a_sv_idx,unsigned a_tv_idx,void *a_value)
{/*{{{*/
  edge_s new_edge;
  new_edge.init();

  edges.ef_init(&new_edge.value);
  edges.ef_operator_equal(&new_edge.value,a_value);

  unsigned edge_idx = __insert_swap_edge(a_sv_idx,a_tv_idx,new_edge);
  new_edge.clear();

  return edge_idx;
}/*}}}*/

inline void graph_s::remove_vertex(unsigned a_idx,bool a_free_eval = true)
{/*{{{*/
  vertex_s &vertex = vertices[a_idx];
  debug_assert(vertex.edge_idxs.root_idx == c_idx_not_exist);

  if (a_free_eval)
  {
    vertices.vf_clear(vertex.value);
  }

  vertices.remove(a_idx);
}/*}}}*/

inline void graph_s::remove_edge(unsigned a_idx,bool a_free_eval = true)
{/*{{{*/
  edge_s &edge = edges[a_idx];

  vertex_s &src_vertex = vertices[edge.src_vertex_idx];
  vertex_s &trg_vertex = vertices[edge.trg_vertex_idx];

  // - remove edge index from source vertex edge indexes -
  unsigned sv_edge_idx = src_vertex.edge_idxs.get_idx(a_idx);
  src_vertex.edge_idxs.remove(sv_edge_idx);
  src_vertex.output_degree--;

  // - if source and target vertex are different, then remove edge index from target vertex edge indexes -
  if (edge.src_vertex_idx != edge.trg_vertex_idx)
  {
    unsigned tv_edge_idx = trg_vertex.edge_idxs.get_idx(a_idx);
    trg_vertex.edge_idxs.remove(tv_edge_idx);
  }
  trg_vertex.input_degree--;

  if (a_free_eval)
  {
    edges.ef_clear(edge.value);
  }

  edges.remove(a_idx);
}/*}}}*/

// -- value_idx_s --
@begin
   inlines value_idx_s
@end

// -- value_idx_rb_tree_s --
@begin
   inlines value_idx_rb_tree_s
@end

inline int value_idx_rb_tree_s::__compare_value(value_idx_s &a_first,value_idx_s &a_second)
{/*{{{*/
  return gf_uclvar_compare(*((interpreter_thread_s *)it_ptr),source_pos,a_first.value,a_second.value);
}/*}}}*/

inline void value_idx_rb_tree_s::ucl_prepare(interpreter_thread_s &a_it,unsigned a_source_pos)
{/*{{{*/
  it_ptr = &a_it;
  source_pos = a_source_pos;
}/*}}}*/

/*
 * inline methods of structure graph_vertex_s
 */

inline void graph_vertex_s::init()
{/*{{{*/
  graph_ptr = NULL;
  vertex_idx = c_idx_not_exist;
}/*}}}*/

inline void graph_vertex_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (graph_ptr != NULL)
  {
    it.release_location_ptr(graph_ptr);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure graph_edge_s
 */

inline void graph_edge_s::init()
{/*{{{*/
  graph_ptr = NULL;
  edge_idx = c_idx_not_exist;
}/*}}}*/

inline void graph_edge_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (graph_ptr != NULL)
  {
    it.release_location_ptr(graph_ptr);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure subgraph_s
 */

inline void subgraph_s::init()
{/*{{{*/
  graph_ptr = NULL;
  vertex_idxs.init();
  edge_idxs.init();
}/*}}}*/

inline void subgraph_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (graph_ptr != NULL)
  {
    it.release_location_ptr(graph_ptr);
  }

  vertex_idxs.clear();
  edge_idxs.clear();

  init();
}/*}}}*/

/*
 * inline methods of structure graph_paths_s
 */

inline void graph_paths_s::init()
{/*{{{*/
  graph_ptr = NULL;
  lengths_arr = NULL;
  src_vertex_idx = c_idx_not_exist;
  edge_idxs.init();
}/*}}}*/

inline void graph_paths_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (graph_ptr != NULL)
  {
    it.release_location_ptr(graph_ptr);
  }

  if (lengths_arr != NULL)
  {
    it.release_location_ptr(lengths_arr);
  }

  edge_idxs.clear();

  init();
}/*}}}*/

#endif

