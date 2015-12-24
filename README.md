# uclang - programming language

Dynamic, object-oriented, general-purpose, high-level programming language.

## Language features

Follows list of uclang features, that are supported by its interpreter.

### Feature list

* Language syntax is designed to be easy to understand by C/C++ programmers.
  * Some syntax is derived from Java programming language.
* Strong object oriented approach.
  * Everything is object. 
  * No global functions at all.
  * All actions are performed by executing of methods.
* Support for inheritance.
* Support for exceptions.
* Support for native threads, no GIL (Global Interpreter Lock).
* Module system designed for straightforward creation of binary modules in C/C++.
  * Language built in data types are implemented as binary module.
* Fast and lightweight interpreter.

## Motivation

C/C++ are excellent programming languages, but they are quite heavy-footed when
it comes to rapid development or prototyping.

As programmer who started programming in Pascal programming language I was
surprised by simplicity of C. If you keep in mind few basic concepts (data
types, memory, pointers), all higher level features derives from it
intuitively.

It would be nice (at least fro me) to have high-level programming language for
fast prototyping and rapid development, that would be: simple, strong and
unrestricted like C/C++ among compiled languages.

### Motivation points

Here are some point, that motivated/motivates me to develop new high-level
programming language:

* C/C++ like syntax.
* Language based on few simple principles.
* Threading support without constraints (no GIL).
* Implicit comparison by type and value, no `===` or `!==` and alike operators.
* Module system, no difference between binary and uclang modules.
* Lightweight interpreter, deployable on embedded devices.

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

Type of variable can be changed any time by assign operator.

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

All standard operators known from C/C++ are supported, and have same intuitive
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
compilation of interpreter. It will be automatically compiled in following
compilation steps.

### Linux compilation

For compilation of interpreter on Linux OS perform following steps:

  * Download script [`try_uclang.sh`](https://raw.githubusercontent.com/izuzanak/uclang/master/uclang_try/try_uclang.sh).

```
wget https://raw.githubusercontent.com/izuzanak/uclang/master/uclang_try/try_uclang.sh
```

  * Check prerequisites mentioned in script.
  * Execute script `try_uclang.sh`.

```
bash try_uclang.sh
```

It will clone two repositories `cont` and `uclang`, and subsequently compile
container generator and interpreter of uclang programing language.

### Linux example scripts

Example scripts can be executed by following commands:

```
cd uclang/uclang_build
export LD_LIBRARY_PATH=$(pwd)
./uclang scripts/hello.ucl
...
```

