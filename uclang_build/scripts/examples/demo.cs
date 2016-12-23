using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using Newtonsoft.Json;

using t_list  = System.Collections.Generic.List<object>;
using t_stack = System.Collections.Generic.Stack<object>;
using t_queue = System.Collections.Generic.Queue<object>;
using t_hset  = System.Collections.Generic.HashSet<object>;
using t_llist = System.Collections.Generic.LinkedList<object>;
using t_dict  = System.Collections.Generic.Dictionary<object,object>;

namespace Uclang
{
  public class Containers
  {
    public static object list (object[] arr) { return new t_list(arr); }
    public static object stack(object[] arr) { return new t_stack(arr); }
    public static object queue(object[] arr) { return new t_queue(arr); }
    public static object hset (object[] arr) { return new t_hset(arr); }
    public static object llist(object[] arr) { return new t_llist(arr); }
    public static object dict()              { return new t_dict(); }

    public static object[] hset_arr(t_hset a_hset)    { return a_hset.ToArray(); }
    public static object[] llist_arr(t_llist a_llist) { return a_llist.ToArray(); }

    public static void dict_arr(Dictionary<object,object> a_dict,out object[] a_keys,out object[] a_vals)
    {
      a_keys = new object[a_dict.Count];
      a_vals = new object[a_dict.Count];

      int idx = 0;
      foreach(var item in a_dict)
      {
        a_keys[idx] = item.Key;
        a_vals[idx] = item.Value;

        ++idx;
      }
    }
  }
}

public class Person
{
  public string name {get;set;}
  public string surname {get;set;}

  public Person(string a_name,string a_surname)
  {
    name = a_name;
    surname = a_surname;
  }
}

public class Demo
{
  public t_dict persons {get;set;}

  public Demo()
  {
    persons = new t_dict
    {
      {"omar", new Person("Omar","Little")},
      {"avone", new Person("Avone","Barksdale")}
    };
  }

  public t_dict person_dict()
  {
    t_dict result = new t_dict();

    foreach(KeyValuePair<object,object> item in persons)
    {
      Person person = (Person)item.Value;

      result[item.Key] = new t_dict{
        {"name",person.name},
        {"surname",person.surname}
      };
    }

    return result;
  }

  public t_list person_list()
  {
    t_list result = new t_list();

    foreach(Person person in persons.Values)
    {
      result.Add(string.Format("{0} {1}",person.name,person.surname));
    }

    return result;
  }

  public string json(t_dict dict)
  {
    return JsonConvert.SerializeObject(dict);
  }

  public static int Main(string[] argv)
  {
    return 0;
  }
}

