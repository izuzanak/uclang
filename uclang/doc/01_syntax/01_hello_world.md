
# Hello world program

In this document is introduced "Hello world" program written in language
uclang. On this simple program we describe some basic (process execution related)
concepts of language uclang.

```cpp
class Main
{
  static public main(argv)
  {
    "Hello world!!!\n".print();
  }
}
```

### Program entry method

Program entry method is `Main.main#1`. If this class and its method are not
defined in none of imported modules, script cannot be executed.
If method `Main.main#1` is not present, script execution will end with
following error:

```
 ---------------------------------------- 
Exception: ERROR

Cannot find main entry method to execute
 ---------------------------------------- 
```

Method `Main.main#1` must be declared as `static`, because there is no valid
object of class `Main` at startup to be given to method `Main.main#1`. If program entry
method is not defined as static, script execution will end with following error:

```
 ---------------------------------------- 
Exception: ERROR: in file: "scripts/hello.ucl" on line: 3

Invalid modifiers of main entry method
 ---------------------------------------- 
```

### Command line arguments

Program entry method accepts exactly one parameter (in our case named `argv`),
that represents arguments retrieved from command line.  Arguments are
represented by object of class `Array`, and its members are objects of class
`String`.  First command line argument always contain name of executed script.
Following code snippet will print command line arguments to standard output.

```cpp
class Main
{
  static public main(argv)
  {
    ("argv: %s\n" % argv.to_string()).print();
  }
}
```

### Program exit status

Program exit status can be returned from method `Main.main#1`. Exit status is
modified if value returned from method `Main.main#1` is object of class
`Integer`, otherwise returned value is ignored, and program exit status
defaults to `0`.

```cpp
class Main
{
  static public main(argv)
  {
    "Hello world!\n".print();

    return 1;
  }
}
```

