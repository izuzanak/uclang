
@begin
include "ucl_python.h"
@end

// - python global init object -
python_c g_python;

/*
 * methods of class python_c
 */

PyObject *python_c::create_py_object(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  if (location_ptr->v_type == c_bi_class_py_object)
  {
    PyObject *pyo_obj = (PyObject *)location_ptr->v_data_ptr;
    Py_INCREF(pyo_obj);

    return pyo_obj;
  }
  else if (location_ptr->v_type == c_bi_class_py_attr_ref)
  {
    return ((py_reference_s *)location_ptr->v_data_ptr)->get_attr();
  }
  else if (location_ptr->v_type == c_bi_class_py_item_ref)
  {
    return ((py_reference_s *)location_ptr->v_data_ptr)->get_item();
  }
  else if (location_ptr->v_type == c_rm_class_set)
  {/*{{{*/
    pointer_tree_s *tree_ptr = (pointer_tree_s *)location_ptr->v_data_ptr;
    PyObject *pyo_set = PySet_New(nullptr);

    // - ERROR -
    if (pyo_set == nullptr)
    {
      return nullptr;
    }

    if (tree_ptr->count != 0)
    {
      unsigned stack[tree_ptr->get_descent_stack_size()];
      unsigned *stack_ptr = stack;

      unsigned t_idx = tree_ptr->get_stack_min_value_idx(tree_ptr->root_idx,&stack_ptr);

      do
      {
        location_s *item_location = it.get_location_value(tree_ptr->data[t_idx].object);
        PyObject *pyo_item = create_py_object(it,item_location);

        // - ERROR -
        if (pyo_item == nullptr)
        {
          Py_DECREF(pyo_set);

          return nullptr;
        }

        // - ERROR -
        if (PySet_Add(pyo_set,pyo_item) == -1)
        {
          Py_DECREF(pyo_item);
          Py_DECREF(pyo_set);

          return nullptr;
        }

        Py_DECREF(pyo_item);

        t_idx = tree_ptr->get_stack_next_idx(t_idx,&stack_ptr,stack);
      }
      while(t_idx != c_idx_not_exist);
    }

    return pyo_set;
  }/*}}}*/
  else if (location_ptr->v_type == c_rm_class_dict)
  {/*{{{*/
    pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)location_ptr->v_data_ptr;
    PyObject *pyo_dict = PyDict_New();

    // - ERROR -
    if (pyo_dict == nullptr)
    {
      return nullptr;
    }

    if (tree_ptr->root_idx != c_idx_not_exist)
    {
      unsigned stack[tree_ptr->get_descent_stack_size()];
      unsigned *stack_ptr = stack;

      unsigned t_idx = tree_ptr->get_stack_min_value_idx(tree_ptr->root_idx,&stack_ptr);

      do
      {
        pointer_map_tree_s_node &node = tree_ptr->data[t_idx];

        location_s *key_location = (location_s *)node.object.key;
        PyObject *pyo_key = create_py_object(it,key_location);

        // - ERROR -
        if (pyo_key == nullptr)
        {
          Py_DECREF(pyo_dict);

          return nullptr;
        }

        location_s *value_location = it.get_location_value(node.object.value);
        PyObject *pyo_value = create_py_object(it,value_location);

        // - ERROR -
        if (pyo_value == nullptr)
        {
          Py_DECREF(pyo_key);
          Py_DECREF(pyo_dict);

          return nullptr;
        }

        // - ERROR -
        if (PyDict_SetItem(pyo_dict,pyo_key,pyo_value) == -1)
        {
          Py_DECREF(pyo_key);
          Py_DECREF(pyo_value);
          Py_DECREF(pyo_dict);

          return nullptr;
        }

        Py_DECREF(pyo_key);
        Py_DECREF(pyo_value);

        t_idx = tree_ptr->get_stack_next_idx(t_idx,&stack_ptr,stack);
      }
      while(t_idx != c_idx_not_exist);
    }

    return pyo_dict;
  }/*}}}*/
  else
  {
    switch (location_ptr->v_type)
    {
    case c_bi_class_blank:
      {
        Py_INCREF(Py_None);
        return Py_None;
      }
    case c_bi_class_char:
      {
        return PyInt_FromLong((char)location_ptr->v_data_ptr);
      }
    case c_bi_class_integer:
      {/*{{{*/
        long long int value = (long long int)location_ptr->v_data_ptr;

        if (value > INT_MAX || value < INT_MIN)
        {
          return PyLong_FromLongLong(value);
        }

        return PyInt_FromLong(value);
      }/*}}}*/
    case c_bi_class_float:
      {
        return PyFloat_FromDouble((double)location_ptr->v_data_ptr);
      }
    case c_bi_class_string:
      {
        string_s *string_ptr = (string_s *)location_ptr->v_data_ptr;
        return PyString_FromStringAndSize(string_ptr->data,string_ptr->size - 1);
      }
    case c_bi_class_array:
      {/*{{{*/
        pointer_array_s *array_ptr = (pointer_array_s *)location_ptr->v_data_ptr;
        PyObject *pyo_list = PyList_New(array_ptr->used);

        // - ERROR -
        if (pyo_list == nullptr)
        {
          return nullptr;
        }

        if (array_ptr->used != 0)
        {
          unsigned idx = 0;
          do {
            PyObject *pyo_item = create_py_object(it,it.get_location_value(array_ptr->data[idx]));

            // - ERROR -
            if (pyo_item == nullptr)
            {
              Py_DECREF(pyo_list);

              return nullptr;
            }

            // - set python list item -
            PyList_SetItem(pyo_list,idx,pyo_item);

          } while(++idx < array_ptr->used);
        }

        return pyo_list;
      }/*}}}*/

    // - ERROR -
    default:
      return nullptr;
    }
  }
}/*}}}*/

PyObject *python_c::create_py_tuple(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  if (location_ptr->v_type == c_bi_class_py_object)
  {
    PyObject *pyo_obj = (PyObject *)location_ptr->v_data_ptr;

    // - object is already python tuple -
    if (PyTuple_Check(pyo_obj))
    {
      Py_INCREF(pyo_obj);
      return pyo_obj;
    }
  }

  // - convert array to python tuple -
  if (location_ptr->v_type == c_bi_class_array)
  {
    pointer_array_s *array_ptr = (pointer_array_s *)location_ptr->v_data_ptr;
    PyObject *pyo_tuple = PyTuple_New(array_ptr->used);

    // - ERROR -
    if (pyo_tuple == nullptr)
    {
      return nullptr;
    }

    if (array_ptr->used > 0)
    {
      unsigned idx = 0;
      do {
        PyObject *pyo_item = create_py_object(it,it.get_location_value(array_ptr->data[idx]));

        // - ERROR -
        if (pyo_item == nullptr)
        {
          Py_DECREF(pyo_tuple);

          return nullptr;
        }

        // - set python tuple item -
        PyTuple_SetItem(pyo_tuple,idx,pyo_item);

      } while(++idx < array_ptr->used);
    }

    return pyo_tuple;
  }

  // - convert single object to python tuple -
  else
  {
    PyObject *pyo_tuple = PyTuple_New(1);

    // - ERROR -
    if (pyo_tuple == nullptr)
    {
      return nullptr;
    }

    PyObject *pyo_obj = create_py_object(it,location_ptr);

    // - ERROR -
    if (pyo_obj == nullptr)
    {
      Py_DECREF(pyo_tuple);

      return nullptr;
    }

    // - set python tuple item -
    PyTuple_SetItem(pyo_tuple,0,pyo_obj);

    return pyo_tuple;
  }
}/*}}}*/

location_s *python_c::py_object_value(interpreter_thread_s &it,PyObject *pyo_obj,uli source_pos)
{/*{{{*/
  if (pyo_obj == Py_None)
  {
    ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();
    return (location_s *)it.blank_location;
  }
  else if (PyInt_Check(pyo_obj))
  {
    long long int value = PyInt_AsLong(pyo_obj);

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);
    return new_location;
  }
  else if (PyLong_Check(pyo_obj))
  {
    long long int value = PyLong_AsLongLong(pyo_obj);

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);
    return new_location;
  }
  else if (PyFloat_Check(pyo_obj))
  {
    double value = PyFloat_AsDouble(pyo_obj);

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_float,value);
    return new_location;
  }
  else if (PyString_Check(pyo_obj))
  {
    char *buffer;
    Py_ssize_t length;

    // - retrieve python string properties -
    PyString_AsStringAndSize(pyo_obj,&buffer,&length);

    string_s *string_ptr = it.get_new_string_ptr();
    string_ptr->set(length,buffer);

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
    return new_location;
  }
  else if (PyList_Check(pyo_obj))
  {/*{{{*/
    pointer_array_s *array_ptr = it.get_new_array_ptr();
    BIC_CREATE_NEW_LOCATION(arr_location,c_bi_class_array,array_ptr);

    Py_ssize_t size = PyList_Size(pyo_obj);
    if (size > 0)
    {
      Py_ssize_t idx = 0;
      do {
        PyObject *pyo_item = PyList_GetItem(pyo_obj,idx);

        // - ERROR -
        if (pyo_item == nullptr)
        {
          it.release_location_ptr(arr_location);
          return nullptr;
        }

        location_s *item_location = py_object_value(it,pyo_item,source_pos);

        // - ERROR -
        if (item_location == nullptr)
        {
          it.release_location_ptr(arr_location);
          return nullptr;
        }

        // - insert item to array -
        array_ptr->push(item_location);

      } while(++idx < size);
    }

    return arr_location;
  }/*}}}*/
  else if (PySet_Check(pyo_obj))
  {/*{{{*/
    pointer_tree_s *tree_ptr = (pointer_tree_s *)cmalloc(sizeof(pointer_tree_s));
    tree_ptr->init();
    tree_ptr->it_ptr = &it;
    tree_ptr->source_pos = source_pos;

    BIC_CREATE_NEW_LOCATION(set_location,c_rm_class_set,tree_ptr);

    Py_ssize_t size = PySet_Size(pyo_obj);
    if (size > 0)
    {
      Py_ssize_t idx = 0;
      Py_ssize_t cnt = 0;
      do {
        PyObject *pyo_key;

        // - ERROR -
        if (_PySet_Next(pyo_obj,&idx,&pyo_key) == -1)
        {
          it.release_location_ptr(set_location);
          return nullptr;
        }

        location_s *key_location = py_object_value(it,pyo_key,source_pos);

        // - ERROR -
        if (key_location == nullptr)
        {
          it.release_location_ptr(set_location);
          return nullptr;
        }

        // - insert key to set -
        if (!tree_ptr->set_unique_insert((pointer)key_location))
        {
          it.release_location_ptr(key_location);
        }

        if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
        {
          it.release_location_ptr(set_location);
          return nullptr;
        }

      } while(++cnt < size);
    }

    return set_location;
  }/*}}}*/
  else if (PyDict_Check(pyo_obj))
  {/*{{{*/
    pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)cmalloc(sizeof(pointer_map_tree_s));
    tree_ptr->init();
    tree_ptr->it_ptr = &it;
    tree_ptr->source_pos = source_pos;

    BIC_CREATE_NEW_LOCATION(dict_location,c_rm_class_dict,tree_ptr);

    Py_ssize_t size = PyDict_Size(pyo_obj);
    if (size > 0)
    {
      Py_ssize_t idx = 0;
      Py_ssize_t cnt = 0;

      do {
        PyObject *pyo_key;
        PyObject *pyo_value;

        // - ERROR -
        if (PyDict_Next(pyo_obj,&idx,&pyo_key,&pyo_value) == -1)
        {
          it.release_location_ptr(dict_location);
          return nullptr;
        }

        location_s *key_location = py_object_value(it,pyo_key,source_pos);

        // - ERROR -
        if (key_location == nullptr)
        {
          it.release_location_ptr(dict_location);
          return nullptr;
        }

        location_s *value_location = py_object_value(it,pyo_value,source_pos);

        // - ERROR -
        if (value_location == nullptr)
        {
          it.release_location_ptr(key_location);
          it.release_location_ptr(dict_location);

          return nullptr;
        }

        pointer_map_s insert_map = {key_location,nullptr};
        unsigned index = tree_ptr->unique_insert(insert_map);

        if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
        {
          it.release_location_ptr(key_location);
          it.release_location_ptr(value_location);
          it.release_location_ptr(dict_location);

          return nullptr;
        }

        pointer_map_s &map = tree_ptr->data[index].object;

        if (map.value != nullptr)
        {
          it.release_location_ptr(key_location);
          it.release_location_ptr(value_location);
          it.release_location_ptr(dict_location);

          return nullptr;
        }

        map.value = (pointer)value_location;

      } while(++cnt < size);
    }

    return dict_location;
  }/*}}}*/

  return nullptr;
}/*}}}*/

