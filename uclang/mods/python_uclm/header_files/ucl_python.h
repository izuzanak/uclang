
#ifndef __UCL_PYTHON_H
#define __UCL_PYTHON_H

@begin
include "script_parser.h"
@end

#include "Python.h"

/*
 * constants and definitions
 */

extern unsigned c_bi_class_py_object;
extern unsigned c_bi_class_py_attr_ref;
extern unsigned c_bi_class_py_item_ref;
extern unsigned c_rm_class_set;
extern unsigned c_rm_class_dict;

// - max method name length -
const unsigned c_max_method_name_length = 256;

/*
 * definition of structure py_reference_s
 */

struct py_reference_s
{
  PyObject *pyo_obj;
  PyObject *pyo_key;

  inline void init();
  inline void clear(interpreter_thread_s &it);

  inline PyObject *get_attr();
  inline bool set_attr(PyObject *pyo_value);

  inline PyObject *get_item();
  inline bool set_item(PyObject *pyo_value);
};

/*
 * definition of class python_c
 */
class python_c
{
  private:
  void *dl_handle;

  public:
  inline python_c();
  inline ~python_c();

  static PyObject *create_py_object(interpreter_thread_s &it,location_s *location_ptr);
  static PyObject *create_py_tuple(interpreter_thread_s &it,location_s *location_ptr);
  static location_s *py_object_value(interpreter_thread_s &it,PyObject *pyo_obj,uli source_pos);
};

/*
 * inline methods of structure py_reference_s
 */

inline void py_reference_s::init()
{/*{{{*/
  pyo_obj = NULL;
  pyo_key = NULL;
}/*}}}*/

inline void py_reference_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (pyo_obj != NULL)
  {
    Py_DECREF(pyo_obj);
  }
  
  if (pyo_key != NULL)
  {
    Py_DECREF(pyo_key);
  }

  init();
}/*}}}*/

inline PyObject *py_reference_s::get_attr()
{/*{{{*/
  return PyObject_GetAttr(pyo_obj,pyo_key);
}/*}}}*/

inline bool py_reference_s::set_attr(PyObject *pyo_value)
{/*{{{*/
  return PyObject_SetAttr(pyo_obj,pyo_key,pyo_value) != -1;
}/*}}}*/

inline PyObject *py_reference_s::get_item()
{/*{{{*/
  return PyObject_GetItem(pyo_obj,pyo_key);
}/*}}}*/

inline bool py_reference_s::set_item(PyObject *pyo_value)
{/*{{{*/
  return PyObject_SetItem(pyo_obj,pyo_key,pyo_value) != -1;
}/*}}}*/

/*
 * inline methods of class python_c
 */

inline python_c::python_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"python_init()\n"););

  // - load python dynamic library -
  dl_handle = dlopen("libpython2.7.so",RTLD_LAZY | RTLD_GLOBAL);

  // - initialize python interpreter -
  Py_Initialize();
}/*}}}*/

inline python_c::~python_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"python_exit()\n"););

  // - finalize python interpreter -
  Py_Finalize();

  // - release python dynamic library -
  if (dl_handle != NULL)
  {
    dlclose(dl_handle);
  }
}/*}}}*/

#endif

