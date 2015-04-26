# uclang - programming language

Dynamic object-oriented, general-purpose, high-level programming language.

## Language features

* Language syntax is designed to be easy to understand by C/C++ programmers.
* Object oriented approach.
  * Not even one global function.
  * All actions are performed by calling objects methods.
* Support for inheritance.
* Support for exceptions.
* Support for native threads, no interpreter locks or so.
* Module system enabling creation of binary modules in C/C++.
  * Language built in data types are implemented as such module.

## Building interpreter

Container generator [`cont`](https://github.com/izuzanak/cont) is needed for
uclang compilation. Compile it and place binary `process` to your `PATH`
directory.

<!--
Edit file
[`uclang_build/mf_cfg.py`](https://github.com/izuzanak/uclang/blob/master/uclang_build/mf_cfg.py)
containing configuration of language modules to be build. Development packages
related to particular module should be present in system, otherwise compilation
will fail. In future versions modules should be auto configured according to
system properties.
-->

Enter build directory [`uclang_build`](https://github.com/izuzanak/uclang/tree/master/uclang_build)
```
cd uclang_build
```
Execute build script [`build.sh`](https://github.com/izuzanak/uclang/blob/master/uclang_build/build.sh)
```
sh build.sh
```

## Examples

Examples of uclang usage are presented in directory: [`uclang/examples`](https://github.com/izuzanak/uclang/tree/master/uclang/examples)

### Inline examples

Follows few simple examples demonstrating uclang possibilities.

#### Hello world

Simple program printing greetings to standard output.

```cpp
class Main
{
  static public main(argv)
  {
    "Hello world!!!\n".print();
  }
}
```
