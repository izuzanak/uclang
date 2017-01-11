
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

// g_object_ref_sink
// g_object_ref
// g_object_unref

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
 * definition of class gtk_c
 */

class gtk_c
{
  public:
  inline gtk_c();
  inline ~gtk_c();

  static GValue *create_g_value(interpreter_thread_s &it,location_s *location_ptr,GValue *value);
  static location_s *g_value_value(interpreter_thread_s &it,GValue *value,uli source_pos);
};

/*
 * inline methods of class gtk_c
 */

inline gtk_c::gtk_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"gtk_init()\n"););
}/*}}}*/

inline gtk_c::~gtk_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"gtk_exit()\n"););
}/*}}}*/

#endif
