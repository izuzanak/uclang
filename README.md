# uclang - programming language

Interpreted, dynamically typed, object-oriented programming language.

## Language features

Follows list of uclang features, that are supported by its interpreter.

### Feature list

* Language syntax is derived mainly from C/C++.
  * Some syntax is derived from Java programming language.
* Strong object oriented approach.
  * Everything is an object. 
  * No global functions at all.
  * Almost all actions are performed by execution of methods.
* Support for inheritance.
* Support for exceptions.
* Support for native threads, no GIL (Global Interpreter Lock).
* Module system designed for straightforward creation of binary modules in C/C++.
  * A language built in data types are implemented as binary module.
* Fast and lightweight interpreter.

## Motivation

C/C++ are excellent programming languages, but they are quite heavy-footed when
it comes to scripting, rapid development, code prototyping or gluing of
existing code.

As a programmer who started programming in Pascal programming language I was
surprised by simplicity of C. If you keep in mind a few basic concepts (data
types, memory, pointers), all high level features derive from it intuitively.

It would be nice (at least for me) to have high-level programming language for
fast prototyping and rapid development, that would be: simple, expressive and
unrestricted like C/C++ among compiled languages.

### Motivation points

Here are some point, that motivated/motivates me to develop new high-level
programming language:

* C/C++ like syntax.
* A language based on a few simple principles.
* Threading support without constraints (no GIL).
* Implicit comparison by type and value, no `===` or `!==` and alike operators.
* Module system, importing binary (C/C++) and uclang modules.
* Lightweight interpreter, deployable on embedded devices.

## Documentation

Documentation of uclang components is placed in the directory:
[`uclang/doc`](https://github.com/izuzanak/uclang/tree/master/uclang/doc)

## Language modules

A set of modules was created in order to use uclang in production.
Implementation of these modules is placed in the directory:
[`uclang/mods`](https://github.com/izuzanak/uclang/tree/master/uclang/mods)

Some of implemented modules are:

[`base`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/base_uclm),
[`sys`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/sys_uclm),
[`inotify`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/inotify_uclm),
[`time`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/time_uclm),
[`lang`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/lang_uclm),
[`pack`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/pack_uclm),
[`parser`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/parser_uclm),
[`math`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/math_uclm),
[`psql`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/psql_uclm),
[`sqlite`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/sqlite_uclm),
[`http`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/http_uclm),
[`websocket`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/websocket_uclm),
[`curl`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/curl_uclm),
[`ucf`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/ucf_uclm),
[`uctcn`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/uctcn_uclm),
[`ftp`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/ftp_uclm),
[`ssh2`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/ssh2_uclm),
[`gcrypt`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/gcrypt_uclm),
[`iconv`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/iconv_uclm),
[`jit`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/jit_uclm),
[`av`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/av_uclm),
[`ao`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/ao_uclm),
[`mpg`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/mpg_uclm),
[`portaudio`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/portaudio_uclm),
[`gstreamer`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/gstreamer_uclm),
[`image`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/image_uclm),
[`glut`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/glut_uclm),
[`glew`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/glew_uclm),
[`gl`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/gl_uclm),
[`ftgl`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/ftgl_uclm),
[`vg`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/vg_uclm),
[`imxegl`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/imxegl_uclm),
[`snmp`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/snmp_uclm),
[`node`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/node_uclm),
[`containers`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/containers_uclm),
[`algorithms`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/algorithms_uclm),
[`binbits`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/binbits_uclm),
[`graph`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/graph_uclm),
[`json`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/json_uclm),
[`xml`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/xml_uclm),
[`python`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/python_uclm),
[`v8`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/v8_uclm),
[`lua`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/lua_uclm),
[`mono`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/mono_uclm),
[`zlib`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/zlib_uclm),
[`fuse`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/fuse_uclm),
[`android`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/android_uclm)

## Examples

Examples of uclang usage are placed in the directory:
[`uclang/examples`](https://github.com/izuzanak/uclang/tree/master/uclang/examples)

### Inline examples

Follows few simple examples demonstrating uclang possibilities.

#### Hello world

Simple program printing greetings on standard output.

```cpp
class Main
{
  static public main(argv)
  {
    "Hello world!!!\n".print();
  }
}
```
```
Hello world!!!
```

#### Dynamic variable types

Type of variable can be changed any time by assign operator.

```cpp
class Main
{
  static what_type(a_value)
  {
    ("Value is of type %s.\n" % $(type a_value)).print();
  }

  static public main(argv)
  {
    what_type(4);
    what_type("4");
    what_type([4]);
    what_type(_4);
  }
}
```
```
Value is of type Integer.
Value is of type String.
Value is of type Array.
Value is of type Blank.
```

#### Operators known from C/C++

All standard operators, known from C/C++ are supported, and have same intuitive
functionality.

```cpp
class Main
{
  static public main(argv)
  {
    ("%d," % (a = 10)).print();
    ("%d," % (b = 10)).print();
    ("%d," % a++).print();
    ("%d," % ++a).print();
    ("%d," % (a += b)).print();
    ("%d," % (a + b)).print();
    ("%d\n" % (a / b)).print();
  }
}
```
```
10,10,10,12,22,32,2
```

#### Dictionary and objects comparisons

Objects of all classes can be compared as long as they implement method
`compare#1`.  Implementation of a dictionary using red-black tree accepts any
comparable value as key, even objects of user defined classes.

```cpp
import containers;

class Main
{
  static public main(argv)
  {
    dict = new Dict();

    dict[1] = "Number";
    dict["Hello"] = "String";
    dict[[1,2,3,4]] = "Array";
    dict[new Dict([1,2,3,4])] = "Dict";

    ("%s\n" % dict[1]).print();
    ("%s\n" % dict["Hello"]).print();
    ("%s\n" % dict[[1,2,3,4]]).print();
    ("%s\n" % dict[new Dict([1,2,3,4])]).print();
  }
}
```
```
Number
String
Array
Dict
```

#### Program flow branching and looping

Various program flow
[branching](https://github.com/izuzanak/uclang/blob/master/uclang/doc/01_syntax/06_flow_branching.md)
and
[looping](https://github.com/izuzanak/uclang/blob/master/uclang/doc/01_syntax/07_flow_loops.md)
statements are supported.

```cpp
import containers;
import algorithms;

class Main
{
  static public main(argv)
  {
    odd_cnt = 0;
    even_cnt = 0;

    for (value in new Range(0,1000))
    {
      if (($value).head(1) == "5")
      {
        value & 0x01 ? ++odd_cnt : ++even_cnt;
      }
    }

    ("odd_cnt: %d\n" % odd_cnt).print();
    ("even_cnt: %d\n" % even_cnt).print();
  }
}
```
```
odd_cnt: 56
even_cnt: 55
```

## Building interpreter

The container generator [`cont`](https://github.com/izuzanak/cont) is needed
for compilation of the interpreter. It will be automatically compiled in
following compilation steps.

### Linux compilation

For compilation of a interpreter on Linux OS perform following steps:

  * Download script [`try_uclang.sh`](https://raw.githubusercontent.com/izuzanak/uclang/master/uclang_try/try_uclang.sh).

```
wget https://raw.githubusercontent.com/izuzanak/uclang/master/uclang_try/try_uclang.sh
```

  * Check prerequisites mentioned in the script.
  * Execute script `try_uclang.sh`.

```
bash try_uclang.sh
```

It will clone two repositories `cont` and `uclang`, and then compile container
generator and interpreter of uclang.

### Linux example scripts

Example scripts can be executed by following commands:

```
cd uclang/uclang_build
export LD_LIBRARY_PATH=$(pwd)
./uclang scripts/hello.ucl
...
```

