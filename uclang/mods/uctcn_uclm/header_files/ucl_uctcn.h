
#ifndef __UCL_UCTCN_H
#define __UCL_UCTCN_H

@begin
include "script_parser.h"
@end

#include "ucf.h"
using namespace Ucf;

#include "uctcn.h"
using namespace Tcn;

/*
 * basic definitions and constants
 */

static const int c_type_bits[] =
{
  1,  /* BOOLEAN1 */
  2,  /* ANTIVALENT2 */
  4,  /* ENUM4  */
  8,  /* BITSET8 */
  8,  /* UNSIGNED8 */
  8,  /* INTEGER8 */
  8,  /* CHARACTER8 */
  16, /* BITSET16 */
  16, /* UNSIGNED16 */
  16, /* INTEGER16 */
  16, /* BIPOLAR_16_14 */
  16, /* UNIPOLAR_16_14 */
  16, /* BIPOLAR_16_12 */
  32, /* REAL32 */
  32, /* BITSET32 */
  32, /* UNSIGNED32 */
  32, /* INTEGER32 */
  48, /* TIMEDATE48 */
  64, /* BITSET64 */
  64, /* UNSIGNED64 */
  64, /* INTEGER64 */
  8,  /* ODD_U8_ARRAY */
  8,  /* EVEN_U8_ARRAY */
  16, /* U16_ARRAY */
  16, /* I16_ARRAY */
  32, /* U32_ARRAY */
  32, /* I32_ARRAY */
};

static const bool c_type_array[] =
{
  false, /* BOOLEAN1 */
  false, /* ANTIVALENT2 */
  false, /* ENUM4  */
  false, /* BITSET8 */
  false, /* UNSIGNED8 */
  false, /* INTEGER8 */
  false, /* CHARACTER8 */
  false, /* BITSET16 */
  false, /* UNSIGNED16 */
  false, /* INTEGER16 */
  false, /* BIPOLAR_16_14 */
  false, /* UNIPOLAR_16_14 */
  false, /* BIPOLAR_16_12 */
  false, /* REAL32 */
  false, /* BITSET32 */
  false, /* UNSIGNED32 */
  false, /* INTEGER32 */
  false, /* TIMEDATE48 */
  false, /* BITSET64 */
  false, /* UNSIGNED64 */
  false, /* INTEGER64 */
  true,  /* ODD_U8_ARRAY */
  true,  /* EVEN_U8_ARRAY */
  true,  /* U16_ARRAY */
  true,  /* I16_ARRAY */
  true,  /* U32_ARRAY */
  true,  /* I32_ARRAY */
};

static const bool c_type_bitoff[] =
{
  true,  /* BOOLEAN1 */
  true,  /* ANTIVALENT2 */
  true,  /* ENUM4  */
  false, /* BITSET8 */
  false, /* UNSIGNED8 */
  false, /* INTEGER8 */
  false, /* CHARACTER8 */
  false, /* BITSET16 */
  false, /* UNSIGNED16 */
  false, /* INTEGER16 */
  false, /* BIPOLAR_16_14 */
  false, /* UNIPOLAR_16_14 */
  false, /* BIPOLAR_16_12 */
  false, /* REAL32 */
  false, /* BITSET32 */
  false, /* UNSIGNED32 */
  false, /* INTEGER32 */
  false, /* TIMEDATE48 */
  false, /* BITSET64 */
  false, /* UNSIGNED64 */
  false, /* INTEGER64 */
  false, /* ODD_U8_ARRAY */
  false, /* EVEN_U8_ARRAY */
  false, /* U16_ARRAY */
  false, /* I16_ARRAY */
  false, /* U32_ARRAY */
  false, /* I32_ARRAY */
};

/*
 * definition of structure pv_list_s
 */

@begin
define pv_list_s dynamic
@end

struct pv_list_s : public SPvList
{
  inline void swap(pv_list_s &second)
  {/*{{{*/
    cassert(0);
  }/*}}}*/

  inline pv_list_s &operator=(pv_list_s &src)
  {/*{{{*/
    cassert(0);
    return *this;
  };/*}}}*/

  inline bool operator==(pv_list_s &second)
  {/*{{{*/
    cassert(0);
    return false;
  }/*}}}*/

  inline void init();
  inline void clear();
};

/*
 * definition of generated structures
 */

// -- ui_rb_tree_s --
@begin
rb_tree<unsigned> ui_rb_tree_s;
@end

// -- pv_list_array_s --
@begin
array<pv_list_s> pv_list_array_s;
@end

/*
 * definition of structure traffic_store_s
 */

struct traffic_store_s
{
  unsigned ts_id;
  ui_rb_tree_s subscribed_ports;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure traffic_port_s
 */

struct traffic_port_s
{
  location_s *ts_ptr;
  SDsName ds_name;
  SPortConfig port_cfg;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure proc_var_set_s
 */

struct proc_var_set_s
{
  location_s *tp_ptr;
  char *var_data;
  string_array_s name_array;
  pv_list_array_s list_array;
  U16 freshness;
  SPvSet pv_set;

  inline void init();
  inline void clear(interpreter_thread_s &it);

  void add_variable(string_s &a_name,int a_type,int a_count,int a_offset,int a_bitoff,int a_bit_size);
};

/*
 * definition of structure proc_varriable_s
 */

struct proc_variable_s
{
  location_s *pvs_ptr;
  unsigned var_idx;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of class uctcn_c
 */

class uctcn_c
{
  public:
  bool ts_initialized[AP_TS_ID_MAX + 1];

  public:
  inline uctcn_c();
  inline ~uctcn_c();
};

// - uctcn global init object -
extern uctcn_c g_uctcn;

/*
 * inline methods of structure pv_list_s
 */

inline void pv_list_s::init()
{/*{{{*/
  pVariable = NULL;
}/*}}}*/

inline void pv_list_s::clear()
{/*{{{*/

  // - if variable pointer exists -
  if (pVariable != NULL)
  {
    cfree(pVariable);
  }

  init();
}/*}}}*/

/*
 * inline methods of generated structures
 */

// -- ui_rb_tree_s --
@begin
inlines ui_rb_tree_s
@end

inline int ui_rb_tree_s::__compare_value(unsigned &a_first,unsigned &a_second)
{/*{{{*/
  return a_first < a_second ? -1 : a_first > a_second ? 1 : 0;
}/*}}}*/

// -- pv_list_array_s --
@begin
inlines pv_list_array_s
@end

/*
 * inline methods of structure traffic_store_s
 */

inline void traffic_store_s::init()
{/*{{{*/
  ts_id = 0;
  subscribed_ports.init();
}/*}}}*/

inline void traffic_store_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - destroy link service interface -
  lsa_destroy(ts_id);

  // - clear subscribed ports set -
  subscribed_ports.clear();

  // - flag traffic store as uninitialized -
  g_uctcn.ts_initialized[ts_id] = false;

  init();
}/*}}}*/

/*
 * inline methods of structure traffic_port_s
 */

inline void traffic_port_s::init()
{/*{{{*/
  ts_ptr = NULL;
}/*}}}*/

inline void traffic_port_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release traffic store -
  if (ts_ptr != NULL)
  {
    it.release_location_ptr(ts_ptr);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure proc_var_set_s
 */

inline void proc_var_set_s::init()
{/*{{{*/
  tp_ptr = NULL;
  var_data = NULL;
  name_array.init();
  list_array.init();
}/*}}}*/

inline void proc_var_set_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release traffic port -
  if (tp_ptr != NULL)
  {
    it.release_location_ptr(tp_ptr);
  }

  // - release variable data -
  if (var_data != NULL)
  {
    cfree(var_data);
  }

  name_array.clear();
  list_array.clear();

  init();
}/*}}}*/

/*
 * inline methods of structure proc_variable_s
 */

inline void proc_variable_s::init()
{/*{{{*/
  pvs_ptr = NULL;
}/*}}}*/

inline void proc_variable_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release process variable set -
  if (pvs_ptr != NULL)
  {
    it.release_location_ptr(pvs_ptr);
  }

  init();
}/*}}}*/

/*
 * inline methods of class uctcn_c
 */

inline uctcn_c::uctcn_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"uctcn_init()\n"););

  memset(ts_initialized,0,(AP_TS_ID_MAX + 1)*sizeof(bool));
}/*}}}*/

inline uctcn_c::~uctcn_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"uctcn_exit()\n"););
}/*}}}*/

#endif

