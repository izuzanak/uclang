# uclang - programming language

Dynamic object-oriented, general-purpose, high-level programming language.

## Language features

Follows list of uclang programming language features, that are supported by
its interpreter.

### Feature list

* Language syntax is designed to be easy to understand by C/C++ programmers.
  * Some syntax is derived from Java programming language.
* Object oriented approach.
  * Everything is object. 
  * No global functions at all.
  * All actions are performed by calling methods of objects.
* Support for inheritance.
* Support for exceptions.
* Support for native threads, no GIL (Global Interpreter Lock).
* Module system enabling creation of binary modules in C/C++.
  * Language built in data types are implemented as language module.
* Lightweight interpreter.

## Motivation

C/C++ are excellent programming languages, but they are quite heavy-footed when
it comes to rapid development or prototyping.  With increasing computing power
of today's computers, many high-level programming languages emerged.

<!--
Many of widely known high-level programming languages have indisputable
influence on programing as we know it today. Some of these languages are even
used as first programming language in programming courses (MIT - Python).
-->

As programmer who started programming in Pacal programming language I was
surprised by simplicity of C. You just need to keep in mind few basic
principles, and everything else in C language derives from these.  C++
programming language extends set of basic principles by OOP (Object Oriented
Programming) and references.

It would be nice to have high-level programming language for fast prototyping
and rapid development, that would be: simple, strong and unrestricted like
C/C++ among compiled languages.

<!--
Advantages and drawbacks of some widespread high-level languages:

* Python
  * `-` Extraordinary language syntax to which everybody (including me) have to get used to.
  * `-` Too many unnecessary global functions and keywords.
  * `-` Global interpreter lock (GIL).
  * `+` Sophisticated module system, no difference between binary and language modules.
    * `+` Huge amount of native modules and libraries.
  * `-` Heavyweight interpreters, that are not so easily deployable on embedded devices.

* JavaScript
  * C/C++ like syntax more or less.
  * `+` Simple principles behind whole language.
    * `-` Arrays implemented as objects.
  * `+` Effective implementation and optimization (V8 JavaScript engine).
  * `-` Too many pitfalls waiting on unexperienced JavaScript programmers.
  * `-` One execution thread for process (not counting GC thread).
    * `+` Simplicity of usage resulting from this characteristics.
-->

### Motivation points

Here are some point, that motivated/motivates me to develop new high-level
programming language:

* C/C++ like syntax.
* Language based on few simple principles.
* Threading support without constraints (no GIL).
* Module system, no difference between binary and language modules.
* Lightweight interpreter, that can be deployed at embedded devices.

## Documentation

Documentation of uclang components is placed in directory: [`uclang/doc`](https://github.com/izuzanak/uclang/tree/master/uclang/doc)

## Examples

Examples of uclang usage are placed in directory: [`uclang/examples`](https://github.com/izuzanak/uclang/tree/master/uclang/examples)

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

Variable type can be changed any time by assign operator.

```cpp
class Main
{
  static what_type(a_value)
  {
    ("Value is of type %s.\n" % (type a_value).to_string()).print();
  }

  static public main(argv)
  {
    what_type(4);
    what_type("4");
    what_type(_4);
  }
}
```
```
Value is of type Integer.
Value is of type String.
Value is of type Blank.
```

#### Operators known from C/C++

Standard operators known from C/C++ are supported.

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
`compare#1`.  Implementation of dictionary using red-black tree accepts any
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

## Building interpreter

Container generator [`cont`](https://github.com/izuzanak/cont) is needed for
uclang compilation. Compile it and place binary `process` to your `PATH`
directory.

Enter build directory [`uclang_build`](https://github.com/izuzanak/uclang/tree/master/uclang_build)
```
cd uclang_build
```
Execute build script [`build.sh`](https://github.com/izuzanak/uclang/blob/master/uclang_build/build.sh)
```
sh build.sh
```

