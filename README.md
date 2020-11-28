# uclang - programming language

[![Build Status](https://travis-ci.com/izuzanak/uclang.svg?branch=master)](https://travis-ci.com/izuzanak/uclang)
![CI](https://github.com/izuzanak/uclang/workflows/CI/badge.svg)
[![Total alerts](https://img.shields.io/lgtm/alerts/g/izuzanak/uclang.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/izuzanak/uclang/alerts/)
[![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/izuzanak/uclang.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/izuzanak/uclang/context:cpp)

Interpreted, dynamically typed, object-oriented programming language.

## Language features

* Language syntax is derived from C/C++ programming languages.
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
* Lightweight interpreter, deployable on embedded devices.

## Documentation

Documentation of uclang components is located in 
[`uclang/doc`](https://github.com/izuzanak/uclang/tree/master/uclang/doc).
Short introduction to language syntax and features can be found in
[`uclang/doc/intro.md`](https://github.com/izuzanak/uclang/blob/master/uclang/doc/intro.md).

## Language modules

A set of modules was created in order to use uclang in production.
Implementation of these modules is located in
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
[`ftp`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/ftp_uclm),
[`ssh2`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/ssh2_uclm),
[`gcrypt`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/gcrypt_uclm),
[`iconv`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/iconv_uclm),
[`jit`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/jit_uclm),
[`fann`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/fann_uclm),
[`av`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/av_uclm),
[`ao`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/ao_uclm),
[`mpg`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/mpg_uclm),
[`portaudio`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/portaudio_uclm),
[`gstreamer`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/gstreamer_uclm),
[`gtk`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/gtk_uclm),
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
[`perl`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/perl_uclm),
[`ruby`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/ruby_uclm),
[`prolog`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/prolog_uclm),
[`zlib`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/zlib_uclm),
[`zip`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/zip_uclm),
[`snappy`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/snappy_uclm),
[`fuse`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/fuse_uclm),
[`android`](https://github.com/izuzanak/uclang/tree/master/uclang/mods/android_uclm)

## Examples

Some examples are introduced in
[`uclang/doc/intro.md`](https://github.com/izuzanak/uclang/blob/master/uclang/doc/intro.md).

## Building interpreter

The container generator [`cont`](https://github.com/izuzanak/cont) is needed
for compilation of the interpreter.

### Linux compilation

Enter build directory [`build`](https://github.com/izuzanak/uclang/tree/master/build).
```
cd build
```

Process cmake source.
```sh
cmake ..
```

Build uclang.
```sh
make -j$(nproc)
```

### Linux example scripts

Example scripts can be executed by following commands:

```
cd uclang/uclang_build
export LD_LIBRARY_PATH=$(pwd)
./uclang scripts/hello.ucl
...
```

