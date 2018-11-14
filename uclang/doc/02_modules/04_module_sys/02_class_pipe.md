# Class Pipe

Class providing access to system pipes.

-----

## Table of methods

* Constructors

  * Constructor [`Pipe#2`](#Pipe%232)

* Operators

  * Operator [`operator_binary_equal#1`](#operator_binary_equal%231)

* Methods

  * Method [`close#0`](#close%230)
  * Method [`write#1`](#write%231)
  * Method [`write_close#1`](#write_close%231)
  * Method [`flush#0`](#flush%230)
  * Method [`read#0`](#read%230)
  * Method [`readln#0`](#readln%230)
  * Method [`read#1`](#read%231)
  * Method [`read_max#1`](#read_max%231)
  * Method [`read_close#0`](#read_close%230)
  * Method [`get_fd#0`](#get_fd%230)
  * Method [`next_item#0`](#next_item%230)
  * Method [`to_string#0`](#to_string%230)
  * Method [`print#0`](#print%230)

-----

## Constructors

<a name="Pipe#2" />

### Constructor [`Pipe#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L2218)

Creates object of class `Pipe`, based on system command to be executed and file
open flags.

**Parameters:**

1. Object of class `String` containing system command to be executed.
2. Object of class `String` containing file open flags.

**Example:**

```cpp
obj = new Pipe("cat numbers.txt 2> /dev/null","r");
obj.read().print();
```
```
Line number 1
Line number 2
Line number 3
Line number 4
Line number 5
```

-----

## Operators

<a name="operator_binary_equal#1" />

### Operator [`operator_binary_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L2206)

Assignment operator `=`. Object of class `Pipe` is replaced by method parameter.

**Parameters:**

1. Any type.

**Return:**

* Method parameter.

**Example:**

```cpp
obj = new Pipe("cat numbers.txt 2> /dev/null","r");
("obj: %s\n" % $obj).print();
obj = "New value";
("obj: %s\n" % $obj).print();
```
```
obj: Pipe
obj: New value
```

-----

## Methods

<a name="close#0" />

### Method [`close#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L2229)

Closes stream represented by object of class `Pipe`.

**Return:**

* Object of class `Pipe`.

**Example:**

```cpp
obj = new Pipe("cat numbers.txt 2> /dev/null","r");
obj.close();
obj.read();
```
```
 ---------------------------------------- 
Exception: ERROR: in file: "./snippet.ucl" on line: 10
obj.read();

Stream is not opened
 ---------------------------------------- 
```

<a name="write#1" />

### Method [`write#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L3781)

Write object of class `String` to stream represented by object of class `Pipe`.

**Parameters:**

1. Object of class `String`.

**Return:**

* Object of class `Pipe`.

**Example:**

```cpp
obj = new Pipe("cat","w");
obj.write("Hello world!\n");
"Done\n".print();
```
```
Hello world!
Done
```

<a name="write_close#1" />

### Method [`write_close#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L2250)

Write object of class `String` to stream represented by object of class `Pipe`, and closes it immediately.

**Parameters:**

1. Object of class `String`.

**Return:**

* Object of class `Pipe`.

**Example:**

```cpp
obj = new Pipe("cat","w");
obj.write_close("Hello world!\n");
"Done\n".print();
```
```
Hello world!
Done
```

<a name="flush#0" />

### Method [`flush#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L3804)

Force write of all buffered data of output stream represented by object of class `Pipe`.

**Return:**

* Object of class `Pipe`.

**Example:**

```cpp
obj = new Pipe("cat","w");
obj.write("Hello world!\n");
obj.flush();
"Done\n".print();
```
```
Hello world!
Done
```

<a name="read#0" />

### Method [`read#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L3829)

Read all data from stream represented by object of class `Pipe`, and return object of class `String` containing read data.

**Return:**

* Object of class `String` if stream contains any bytes to read.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = new Pipe("cat numbers.txt 2> /dev/null","r");
obj.read().print();
obj.read().print();
'\n'.print();
```
```
Line number 1
Line number 2
Line number 3
Line number 4
Line number 5
<blank>
```

<a name="readln#0" />

### Method [`readln#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L3838)

Read one line from stream represented by object of class `Pipe`, and return object of class `String` containing read line.

**Return:**

* Object of class `String` if stream contains any lines to read.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = new Pipe("cat numbers.txt 2> /dev/null","r");
while (Blank != (line = obj.readln()))
{
  ("line: %s\n" % line).print();
}
```
```
line: Line number 1
line: Line number 2
line: Line number 3
line: Line number 4
line: Line number 5
```

<a name="read#1" />

### Method [`read#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L3843)

Read requested count of bytes from stream represented by object of class `Pipe`, and return object of class `String` containing read bytes.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
obj = new Pipe("cat numbers.txt 2> /dev/null","r");
obj.read(32).print();
'\n'.print();
```
```
Line number 1
Line number 2
Line
```

<a name="read_max#1" />

### Method [`read_max#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L3907)

Read maximaly requested count of bytes from stream represented by object of class `Pipe`, and return object of class `String` containing read bytes.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
obj = new Pipe("cat numbers.txt 2> /dev/null","r");
obj.read_max(47).print();
'\n'.print();
obj.read_max(47).print();
'\n'.print();
```
```
Line number 1
Line number 2
Line number 3
Line 
number 4
Line number 5

```

<a name="read_close#0" />

### Method [`read_close#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L2274)

Read all data from stream represented by object of class `Pipe`, and return object of class `String` containing read data. Input stream will be closed after reading.

**Return:**

* Object of class `String` if stream contains any bytes to read.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = new Pipe("cat numbers.txt 2> /dev/null","r");
obj.read_close().print();
```
```
Line number 1
Line number 2
Line number 3
Line number 4
Line number 5
```

<a name="get_fd#0" />

### Method [`get_fd#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L3978)

Return integer file descriptor of stream represented by object of class `Pipe`.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
obj = new Pipe("cat numbers.txt 2> /dev/null","r");
("obj.get_fd(): %d\n" % obj.get_fd()).print();
```
```
obj.get_fd(): 3
```

<a name="next_item#0" />

### Method `spec` [`next_item#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L3999)

Read one line from stream represented by object of class `Pipe`, and return object of class `String` containing read line.

**Return:**

* Object of class `String` if stream contains any lines to read.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = new Pipe("cat numbers.txt 2> /dev/null","r");
for (line <- obj)
{
  ("line: %s\n" % line).print();
}
```
```
line: Line number 1
line: Line number 2
line: Line number 3
line: Line number 4
line: Line number 5
```

<a name="to_string#0" />

### Method `spec` `static` [`to_string#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L2284)

Convert object of class `Pipe` to object of class `String`.
This method returns name of class `Pipe`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
("Pipe.to_string(): %s\n" % Pipe.to_string()).print();
```
```
Pipe.to_string(): Pipe
```

<a name="print#0" />

### Method `spec` `static` [`print#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L2293)

Print string representation of object of class `Pipe` to standard output.
This method prints name of class `Pipe`.

**Return:**

* Object of class `Pipe`.

**Example:**

```cpp
Pipe.print();
"\n".print();
```
```
Pipe
```
