
#ifndef __UCL_BINBITS_H
#define __UCL_BINBITS_H

@begin
include "script_parser.h"
@end

// - bin array types -
enum
{
  c_bin_array_type_int32,
  c_bin_array_type_uint32,
  //c_bin_array_type_float,
  //c_bin_array_type_double,
};

// - bin dict types -
enum
{
  c_bin_dict_type_int64_int64,
  c_bin_dict_type_int64_float64,
};

/*
 * definition of structure bin_array_ref_s
 */

struct bin_array_ref_s
{
  location_s *ba_location;
  unsigned index;
};

/*
 * definition of structure bin_array_s
 */

struct bin_array_s
{
  unsigned type;
  void *cont;
  pointer_array_s free_references;

  inline void init();
  inline void clear(interpreter_thread_s &it);

  inline bin_array_ref_s *create_reference(location_s *ba_location,unsigned index);
  inline void release_reference(interpreter_thread_s &it,bin_array_ref_s *bar_ptr);
};

/*
 * definition of structure bin_dict_ref_s
 */

struct bin_dict_ref_s
{
  location_s *bd_location;
  unsigned index;
};

/*
 * definition of structure bin_dict_s
 */

struct bin_dict_s
{
  unsigned type;
  void *cont;
  pointer_array_s free_references;

  inline void init();
  inline void clear(interpreter_thread_s &it);

  inline bin_dict_ref_s *create_reference(location_s *bd_location,unsigned index);
  inline void release_reference(interpreter_thread_s &it,bin_dict_ref_s *bdr_ptr);
};

/*
 * definition of generated structures
 */

// -- lli_lli_map_s --
@begin
struct
<
lli:key
lli:value
>
lli_lli_map_s;
@end

// -- lli_lli_map_tree_s --
@begin
safe_rb_tree<lli_lli_map_s> lli_lli_map_tree_s;
@end

// -- lli_bd_map_s --
@begin
struct
<
lli:key
bd:value
>
lli_bd_map_s;
@end

// -- lli_bd_map_tree_s --
@begin
safe_rb_tree<lli_bd_map_s> lli_bd_map_tree_s;
@end

/*
 * inline methods of structure bin_array_s
 */

inline void bin_array_s::init()
{/*{{{*/
  cont = NULL;
  free_references.init();
}/*}}}*/

inline void bin_array_s::clear(interpreter_thread_s &it)
{/*{{{*/
  
  if (cont != NULL)
  {
    switch (type)
    {
    case c_bin_array_type_int32:
      ((bi_array_s *)cont)->clear();
      break;
    case c_bin_array_type_uint32:
      ((ui_array_s *)cont)->clear();
      break;
    default:
      cassert(0);
    }

    cfree(cont);
  }

  // - release bin array references -
  if (free_references.used > 0)
  {
    pointer *r_ptr = free_references.data;
    pointer *r_ptr_end = r_ptr + free_references.used;
    do {
      cfree(*r_ptr);
    } while(++r_ptr < r_ptr_end);
  }

  free_references.clear();

  init();
}/*}}}*/

inline bin_array_ref_s *bin_array_s::create_reference(location_s *ba_location,unsigned index)
{/*{{{*/
  bin_array_ref_s *bar_ptr;

  // - if there are some existing references -
  if (free_references.used > 0)
  {
    // - reuse existing reference -
    bar_ptr = (bin_array_ref_s *)free_references.pop();
  }
  else
  {
    // - create new reference -
    bar_ptr = (bin_array_ref_s *)cmalloc(sizeof(bin_array_ref_s));
  }

  ba_location->v_reference_cnt.atomic_inc();
  bar_ptr->ba_location = ba_location;
  bar_ptr->index = index;

  return bar_ptr;
}/*}}}*/

inline void bin_array_s::release_reference(interpreter_thread_s &it,bin_array_ref_s *bar_ptr)
{/*{{{*/
  
  // - store released reference -
  free_references.push(bar_ptr);

  it.release_location_ptr(bar_ptr->ba_location);
}/*}}}*/

/*
 * inline methods of structure bin_dict_s
 */

inline void bin_dict_s::init()
{/*{{{*/
  cont = NULL;
  free_references.init();
}/*}}}*/

inline void bin_dict_s::clear(interpreter_thread_s &it)
{/*{{{*/
  
  if (cont != NULL)
  {
    switch (type)
    {
    case c_bin_dict_type_int64_int64:
      ((lli_lli_map_tree_s *)cont)->clear();
      break;
    case c_bin_dict_type_int64_float64:
      ((lli_bd_map_tree_s *)cont)->clear();
      break;
    default:
      cassert(0);
    }

    cfree(cont);
  }

  // - release bin dict references -
  if (free_references.used > 0)
  {
    pointer *r_ptr = free_references.data;
    pointer *r_ptr_end = r_ptr + free_references.used;
    do {
      cfree(*r_ptr);
    } while(++r_ptr < r_ptr_end);
  }

  free_references.clear();

  init();
}/*}}}*/

inline bin_dict_ref_s *bin_dict_s::create_reference(location_s *bd_location,unsigned index)
{/*{{{*/
  bin_dict_ref_s *bdr_ptr;

  // - if there are some existing references -
  if (free_references.used > 0)
  {
    // - reuse existing reference -
    bdr_ptr = (bin_dict_ref_s *)free_references.pop();
  }
  else
  {
    // - create new reference -
    bdr_ptr = (bin_dict_ref_s *)cmalloc(sizeof(bin_dict_ref_s));
  }

  bd_location->v_reference_cnt.atomic_inc();
  bdr_ptr->bd_location = bd_location;
  bdr_ptr->index = index;

  return bdr_ptr;
}/*}}}*/

inline void bin_dict_s::release_reference(interpreter_thread_s &it,bin_dict_ref_s *bdr_ptr)
{/*{{{*/
  
  // - store released reference -
  free_references.push(bdr_ptr);

  it.release_location_ptr(bdr_ptr->bd_location);
}/*}}}*/

/*
 * inline methods of generated structures
 */

// -- lli_lli_map_s --
@begin
inlines lli_lli_map_s
@end

// -- lli_lli_map_tree_s --
@begin
inlines lli_lli_map_tree_s
@end

inline int lli_lli_map_tree_s::__compare_value(lli_lli_map_s &a_first,lli_lli_map_s &a_second)
{/*{{{*/
  return a_first.key < a_second.key ? -1 : a_first.key > a_second.key ? 1 : 0;
}/*}}}*/

// -- lli_bd_map_s --
@begin
inlines lli_bd_map_s
@end

// -- lli_bd_map_tree_s --
@begin
inlines lli_bd_map_tree_s
@end

inline int lli_bd_map_tree_s::__compare_value(lli_bd_map_s &a_first,lli_bd_map_s &a_second)
{/*{{{*/
  return a_first.key < a_second.key ? -1 : a_first.key > a_second.key ? 1 : 0;
}/*}}}*/

#endif

