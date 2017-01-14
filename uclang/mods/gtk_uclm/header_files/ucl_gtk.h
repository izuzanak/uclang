
#ifndef __UCL_GTK_H
#define __UCL_GTK_H

@begin
include "script_parser.h"
@end

#define GTK_DISABLE_DEPRECATED 1
#define GDK_DISABLE_DEPRECATED 1
#define GDK_PIXBUF_DISABLE_DEPRECATED 1
#define G_DISABLE_DEPRECATED 1
#define GTK_MULTIHEAD_SAFE 1

#include <gtk/gtk.h>

// G_OBJECT_GET_CLASS(object)
// g_object_class_list_properties - Get an array of GParamSpec* for all properties of a class.
// g_object_class_find_property - Looks up the GParamSpec for a property of a class.
// g_signal_list_ids

// g_object_ref_sink
// g_object_ref
// g_object_unref

// g_quark_from_string
// g_object_set_qdata_full
// g_object_get_qdata

// #define G_TYPE_INVALID
// #define G_TYPE_NONE
// #define G_TYPE_INTERFACE
// #define G_TYPE_CHAR
// #define G_TYPE_UCHAR
// #define G_TYPE_BOOLEAN
// #define G_TYPE_INT
// #define G_TYPE_UINT
// #define G_TYPE_LONG
// #define G_TYPE_ULONG
// #define G_TYPE_INT64
// #define G_TYPE_UINT64
// #define G_TYPE_ENUM
// #define G_TYPE_FLAGS
// #define G_TYPE_FLOAT
// #define G_TYPE_DOUBLE
// #define G_TYPE_STRING
// #define G_TYPE_POINTER
// #define G_TYPE_BOXED
// #define G_TYPE_PARAM
// #define G_TYPE_OBJECT
// #define G_TYPE_GTYPE
// #define G_TYPE_VARIANT
// #define G_TYPE_CHECKSUM

/*
 * constants and definitions
 */

extern unsigned c_bi_class_gtk_g_object;

/*
 * definition of class gtk_c
 */

class gtk_c
{
  public:
  static GQuark ucl_dlgs_quark;

  static bool main_loop;
  static unsigned main_source_pos;
  static unsigned main_ret_code;

  static inline void init_static();

  inline gtk_c();
  inline ~gtk_c();

  static void dlg_data_release(gpointer data);
  static void callback_handler(gpointer g_obj,gpointer data);

  static GValue *create_g_value(interpreter_thread_s &it,location_s *location_ptr,GValue *g_value);
  static location_s *g_value_value(interpreter_thread_s &it,GType g_type,GValue *g_value);
};

/*
 * definition of generated structures
 */

// -- gtk_delegate_s --
@begin
struct
<
pointer:delegate_loc
pointer:data_loc
>
gtk_delegate_s;
@end

// -- gtk_delegate_list_s --
@begin
list<gtk_delegate_s> gtk_delegate_list_s;
@end

// -- gtk_dlg_data_s --
@begin
struct
<
pointer:it_ptr
pointer:object_loc
gtk_delegate_list_s:delegates
>
gtk_dlg_data_s;
@end

/*
 * inline methods of class gtk_c
 */

inline void gtk_c::init_static()
{/*{{{*/
  main_loop = false;
  main_source_pos = 0;
  main_ret_code = c_run_return_code_OK;
}/*}}}*/

inline gtk_c::gtk_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"gtk_init()\n"););

  gtk_init(0,NULL);

  ucl_dlgs_quark = g_quark_from_string("uclang delegates");
  gtk_c::init_static();
}/*}}}*/

inline gtk_c::~gtk_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"gtk_exit()\n"););
}/*}}}*/

/*
 * inline methods of generated structures
 */

// -- gtk_delegate_s --
@begin
inlines gtk_delegate_s
@end

// -- gtk_delegate_list_s --
@begin
inlines gtk_delegate_list_s
@end

// -- gtk_dlg_data_s --
@begin
inlines gtk_dlg_data_s
@end

#endif

