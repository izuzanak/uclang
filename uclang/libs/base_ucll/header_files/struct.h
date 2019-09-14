
#ifndef __STRUCT_H
#define __STRUCT_H

@begin
include "atomic.h"
include "ucl_string.h"
include "datetime.h"
include "dynlib.h"
@end

/*
 * definition of generated structures
 */

// -- bc_array_s --
@begin
array<char>

additions
{
  // - append characters to the end of character buffer -
  inline void append(unsigned a_count,const char *a_data);

  // - append formatted characters to the end of character buffer -
  void append_format_ap(const char *a_format,va_list a_ap);

  // - append formatted characters to the end of character buffer -
  inline void append_format(const char *a_format,...);

  // - retrieve data from end of buffer -
  inline void from_end(unsigned a_count,char *a_trg,bool a_order_bytes);

  // - move data from buffer tail to its begin (drop head) -
  inline void tail(unsigned a_count);
}

bc_array_s;
@end

// -- bi_array_s --
@begin
array<int> bi_array_s;
@end

// -- ui_array_s --
@begin
array<unsigned>

additions
{
  /*
   * \brief used for mapping of function name indexes to indexes of its records
   * \param a_name_idx - method name index
   * \return method record index
   */
  inline unsigned map_name(unsigned a_name_idx);
}

ui_array_s;
@end

// -- lli_array_s --
@begin
array<lli> lli_array_s;
@end

// -- uli_array_s --
@begin
   array<uli> uli_array_s;
@end

// -- lli_rb_tree_s --
@begin
rb_tree<lli> lli_rb_tree_s;
@end

// -- ui_queue_s --
@begin
queue<unsigned> ui_queue_s;
@end

// -- pointer_array_s --
@begin
array<pointer> pointer_array_s;
@end

// -- ui_arrays_s --
@begin
array<ui_array_s> ui_arrays_s;
@end

// -- ui_arrays_array_s --
@begin
array<ui_arrays_s> ui_arrays_array_s;
@end

// -- bf_array_s --
@begin
array<float> bf_array_s;
@end

// -- bd_array_s --
@begin
array<double> bd_array_s;
@end

// -- bd_rb_tree_s --
@begin
rb_tree<double> bd_rb_tree_s;
@end

// -- string_array_s --
@begin
array<string_s>

additions
{
  /*
   * \brief find index of string described by its length and pointer to char *
   * \param a_length - length of searched string
   * \param a_data - pointer to searched string data
   * \return index of string
   */
  libbase_ucll_EXPORT unsigned get_idx_char_ptr(unsigned a_length,const char *a_data);

  /*
   * \brief join all strings in array to one string
   * \param a_string - target string to be set to concatenated result
   */
  libbase_ucll_EXPORT void join(string_s &a_string);

  /*
   * \brief split string to strings array by given separator string
   * \param a_string - string to be splitted
   * \param a_length - length of separator string
   * \param a_data - pointer to separator string data
   */
  void split(string_s &a_string,unsigned a_length,const char *a_data);
}

string_array_s;
@end

// -- string_rb_tree_s --
@begin
rb_tree<string_s>

additions
{
  /*
   * \brief find index of string described by its length and pointer to char *
   * \param a_length - length of searched string
   * \param a_data - pointer to searched string data
   * \return index of string
   */
  inline unsigned get_idx_char_ptr(unsigned a_length,const char *a_data);
  inline void get_idxs_char_ptr(unsigned a_length,const char *a_data,ui_array_s &a_idxs_array);
  inline unsigned get_idx_char_ptr_insert(unsigned a_length,const char *a_data);
}

string_rb_tree_s;
@end

// -- dynlib_array_s --
@begin
array<dynlib_s> dynlib_array_s;
@end

// -- name_pos_s --
// -- ri_ep_s --
// -- idx_size_s --
@begin
struct
<                    $//tmp_name_pos      ri_ep_s            idx_size_s
unsigned:ui_first    $//ui_first          record_idx         ui_first
unsigned:ui_second   $//ui_second         element_position   ui_second
>
name_pos_s
ri_ep_s
idx_size_s;
@end

const ri_ep_s c_blank_ri_ep = {c_idx_not_exist,c_idx_not_exist};

#define record_idx ui_first
#define element_position ui_second

// -- lalr_stack_element_s --
@begin
struct
<
unsigned:lalr_state
unsigned:terminal_start
unsigned:terminal_end
>
lalr_stack_element_s;
@end

// -- lalr_stack_s --
@begin
array<lalr_stack_element_s>

additions
{
  /*
   * \brief push new element and set only its state
   * \param a_lalr_state - state of new element
   */
  inline void push(unsigned a_lalr_state);

  /*
   * \brief push new element
   * \param a_lalr_state - state of new element
   * \param a_terminal_start - start of terminal in source string
   * \param a_terminal_end - end of terminal in source string
   */
  inline void push(unsigned a_lalr_state,unsigned a_terminal_start,unsigned a_terminal_end);
}

lalr_stack_s;
@end

// - v_data_type typedef -
union v_data_type
{
  long long int lli;
  long long unsigned llu;
  double bd;
  pointer ptr;

  v_data_type() {}
  v_data_type(char a_bc) { lli = a_bc; }
  v_data_type(int a_bi) { lli = a_bi; }
  v_data_type(unsigned a_ui) { lli = a_ui; }
  v_data_type(long long int a_lli) { lli = a_lli; }
  v_data_type(long long unsigned a_llu) { llu = a_llu; }
  v_data_type(double a_bd) { bd = a_bd; }
  template <class T> v_data_type(T* a_ptr) { ptr = (pointer)a_ptr; }

  operator char () const { return lli; }
  operator int () const { return lli; }
  operator unsigned () const { return lli; }
  operator long long int () const { return lli; }
  operator long long unsigned () const { return llu; }
  operator double () const { return bd; }
  template <class T> operator T* () const { return (T *)ptr; }

  v_data_type& operator=(const v_data_type &a_src) { lli = a_src.lli; return *this; }
  bool operator==(const v_data_type &a_second) { return lli == a_second.lli; }
};

@begin
define v_data_type basic
@end

// -- location_s --
@begin
struct
<
unsigned:v_type
atomic_s:v_reference_cnt
v_data_type:v_data_ptr
>
location_s;
@end

typedef location_s * location_s_ptr;

@begin
define location_s_ptr basic
@end

// -- location_array_s --
@begin
array<location_s> location_array_s;
@end

// -- source_s --
@begin
struct
<
string_s:file_name
string_s:source_string
>
source_s;
@end

// -- source_array_s --
@begin
array<source_s> source_array_s;
@end

/*
 * inline methods of generated structures
 */

// -- bc_array_s --
@begin
inlines bc_array_s
@end

inline void bc_array_s::append(unsigned a_count,const char *a_data)
{/*{{{*/
  unsigned old_used = used;
  push_blanks(a_count);
  memcpy(data + old_used,a_data,a_count);
}/*}}}*/

inline void bc_array_s::append_format(const char *a_format,...)
{/*{{{*/
  va_list ap;
  va_start(ap,a_format);
  append_format_ap(a_format,ap);
  va_end(ap);
}/*}}}*/

inline void bc_array_s::from_end(unsigned a_count,char *a_trg,bool a_order_bytes)
{/*{{{*/
  debug_assert(used >= a_count);

  unsigned new_used = used - a_count;
  memcpy_bo(a_trg,data + new_used,a_count,a_order_bytes);
  used = new_used;
}/*}}}*/

inline void bc_array_s::tail(unsigned a_count)
{/*{{{*/
  debug_assert(a_count <= used);

  if (a_count != 0)
  {
    unsigned begin = used - a_count;

    if (begin < a_count)
    {
      memmove(data,data + begin,a_count);
    }
    else
    {
      memcpy(data,data + begin,a_count);
    }
  }

  used = a_count;
}/*}}}*/

// -- bi_array_s --
@begin
inlines bi_array_s
@end

// -- ui_array_s --
@begin
inlines ui_array_s
@end

inline unsigned ui_array_s::map_name(unsigned a_name_idx)
{/*{{{*/
  if (a_name_idx >= used)
  {
    return c_idx_not_exist;
  }

  return data[a_name_idx];
}/*}}}*/

// -- lli_array_s --
@begin
inlines lli_array_s
@end

// -- uli_array_s --
@begin
inlines uli_array_s
@end

// -- lli_rb_tree_s --
@begin
inlines lli_rb_tree_s
@end

inline int lli_rb_tree_s::__compare_value(lli &a_first,lli &a_second)
{/*{{{*/
  return a_first < a_second ? -1 : a_first > a_second ? 1 : 0;
}/*}}}*/

// -- ui_queue_s --
@begin
inlines ui_queue_s
@end

// -- pointer_array_s --
@begin
inlines pointer_array_s
@end

// -- ui_arrays_s --
@begin
inlines ui_arrays_s
@end

// -- ui_arrays_array_s --
@begin
inlines ui_arrays_array_s
@end

// -- bf_array_s --
@begin
inlines bf_array_s
@end

// -- bd_array_s --
@begin
inlines bd_array_s
@end

// -- bd_rb_tree_s --
@begin
inlines bd_rb_tree_s
@end

inline int bd_rb_tree_s::__compare_value(double &a_first,double &a_second)
{/*{{{*/
  return a_first < a_second ? -1 : a_first > a_second ? 1 : 0;
}/*}}}*/

// -- string_array_s --
@begin
inlines string_array_s
@end

// -- string_rb_tree_s --
@begin
inlines string_rb_tree_s
@end

inline int string_rb_tree_s::__compare_value(string_s &a_first,string_s &a_second)
{/*{{{*/
  if (a_first.size < a_second.size) { return -1; }
  if (a_first.size > a_second.size) { return 1; }
  return memcmp(a_first.data,a_second.data,a_first.size - 1);
}/*}}}*/

inline unsigned string_rb_tree_s::get_idx_char_ptr(unsigned a_length,const char *a_data)
{/*{{{*/
  string_s tmp_str;
  tmp_str.data = (char *)a_data;
  tmp_str.size = a_length + 1;

  return get_idx(tmp_str);
}/*}}}*/

inline void string_rb_tree_s::get_idxs_char_ptr(unsigned a_length,const char *a_data,ui_array_s &a_idxs_array)
{/*{{{*/
  string_s tmp_str;
  tmp_str.data = (char *)a_data;
  tmp_str.size = a_length + 1;

  get_idxs(tmp_str,a_idxs_array);
}/*}}}*/

inline unsigned string_rb_tree_s::get_idx_char_ptr_insert(unsigned a_length,const char *a_data)
{/*{{{*/
  string_s tmp_str;
  tmp_str.data = (char *)a_data;
  tmp_str.size = a_length + 1;

  return unique_insert(tmp_str);
}/*}}}*/

// -- dynlib_array_s --
@begin
inlines dynlib_array_s
@end

// -- name_pos_s --
// -- ri_ep_s --
// -- idx_size_s --
@begin
inlines name_pos_s
@end

// -- lalr_stack_element_s --
@begin
inlines lalr_stack_element_s
@end

// -- lalr_stack_s --
@begin
inlines lalr_stack_s
@end

inline void lalr_stack_s::push(unsigned a_lalr_state)
{/*{{{*/
  if (used >= size)
  {
    copy_resize(size + c_array_add);
  }

  lalr_stack_element_s &target = data[used++];

  target.lalr_state = a_lalr_state;
}/*}}}*/

inline void lalr_stack_s::push(unsigned a_lalr_state,unsigned a_terminal_start,unsigned a_terminal_end)
{/*{{{*/
  if (used >= size)
  {
    copy_resize(size + c_array_add);
  }

  lalr_stack_element_s &target = data[used++];

  target.lalr_state = a_lalr_state;
  target.terminal_start = a_terminal_start;
  target.terminal_end = a_terminal_end;
}/*}}}*/

// -- location_s --
@begin
inlines location_s
@end

// -- location_array_s --
@begin
inlines location_array_s
@end

// -- source_s --
@begin
inlines source_s
@end

// -- source_array_s --
@begin
inlines source_array_s
@end

#endif

