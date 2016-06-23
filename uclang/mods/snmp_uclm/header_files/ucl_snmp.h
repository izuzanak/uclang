
#ifndef __UCL_SNMP_H
#define __UCL_SNMP_H

@begin
include "script_parser.h"
@end

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/utilities.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

// - SNMP constants -
const unsigned c_snmp_max_string_length = 255;
const unsigned c_snmp_max_string_size = c_snmp_max_string_length + 1;

// - snmp agent types -
enum
{
  SNMP_AGENT_TYPE_NONE = 0,
  SNMP_AGENT_TYPE_MASTER,
  SNMP_AGENT_TYPE_SUBAGENT,
};

// - snmp value types -
enum
{
  SNMP_VALUE_NONE = 0,
  SNMP_VALUE_INTEGER,
  SNMP_VALUE_STRING,
};

/*
 * definition of generated structures
 */

// -- snmp_object_s --
@begin
struct
<
string_s:name
unsigned:type
pointer:data
>
snmp_object_s;
@end

// -- snmp_object_rb_tree_s --
@begin
safe_rb_tree<snmp_object_s> snmp_object_rb_tree_s;
@end

/*
 * definition of structure snmp_session_s
 */

struct snmp_session_s
{
  static bool exists;

  netsnmp_session session;
  netsnmp_session *ss;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure snmp_agent_s
 */

struct snmp_agent_s
{
  static bool exists;

  unsigned type;
  string_s name;
  snmp_object_rb_tree_s objects;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure snmp_obj_s
 */

struct snmp_obj_s
{
  location_s *snmpa_ptr;
  unsigned index;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure snmp_oid_s
 */

struct snmp_oid_s
{
  size_t length;
  oid data[MAX_OID_LEN];

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of generated structures
 */

// -- snmp_object_s --
@begin
inlines snmp_object_s
@end

// -- snmp_object_rb_tree_s --
@begin
inlines snmp_object_rb_tree_s
@end

inline int snmp_object_rb_tree_s::__compare_value(snmp_object_s &a_first,snmp_object_s &a_second)
{/*{{{*/
  string_s &f_name = a_first.name;
  string_s &s_name = a_second.name;

  if (f_name.size < s_name.size) return -1;
  if (f_name.size > s_name.size) return 1;
  return memcmp(f_name.data,s_name.data,f_name.size - 1);
}/*}}}*/

/*
 * inline methods of structure snmp_session_s
 */

inline void snmp_session_s::init()
{/*{{{*/
  ss = NULL;
}/*}}}*/

inline void snmp_session_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (ss != NULL)
  {
    snmp_close(ss);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure snmp_agent_s
 */

inline void snmp_agent_s::init()
{/*{{{*/
  type = SNMP_AGENT_TYPE_NONE;
  name.init();
  objects.init();
}/*}}}*/

inline void snmp_agent_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (name.data != &c_string_terminating_char)
  {
    snmp_shutdown(name.data);
  }

  name.clear();

  // - release all object data pointers -
  if (objects.root_idx != c_idx_not_exist)
  {
    unsigned stack[objects.get_descent_stack_size()];
    unsigned *stack_ptr = stack;
    
    unsigned o_idx = objects.get_stack_min_value_idx(objects.root_idx,&stack_ptr);
    do {
      cfree(objects.data[o_idx].object.data);
      
      o_idx = objects.get_stack_next_idx(o_idx,&stack_ptr,stack);
    } while(o_idx != c_idx_not_exist);
  }

  objects.clear();

  init();
}/*}}}*/

/*
 * inline methods of structure snmp_obj_s
 */

inline void snmp_obj_s::init()
{/*{{{*/
  snmpa_ptr = NULL;
  index = c_idx_not_exist;
}/*}}}*/

inline void snmp_obj_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (snmpa_ptr != NULL)
  {
    it.release_location_ptr(snmpa_ptr);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure snmp_oid_s
 */

inline void snmp_oid_s::init()
{/*{{{*/
  length = MAX_OID_LEN;
}/*}}}*/

inline void snmp_oid_s::clear(interpreter_thread_s &it)
{/*{{{*/
  init();
}/*}}}*/

#endif

