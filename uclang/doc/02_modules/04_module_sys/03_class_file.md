# Class File

Class providing access to system files.

-----

## Static constants

* Files related to current process
  * `File.stdin` - Object of class `File` representing standard input of process.
  * `File.stdout` - Object of class `File` representing standard output of process.
  * `File.stderr` - Object of class `File` representing error output of process.

* Constants of [`File.seek#2`](#seek%232) method.
  * `File.SEEK_SET` - Object of class `Integer`. Seek position relative to file begining.
  * `File.SEEK_CUR` - Object of class `Integer`. Seek position relative to current position.
  * `File.SEEK_END` - Object of class `Integer`. Seek position relative to end of file.

-----

## Table of methods

* Constructors

  * Constructor [`File#2`](#File%232)

* Operators

  * Operator [`operator_binary_equal#1`](#operator_binary_equal%231)

* Methods

  * Method [`seek#2`](#seek%232)
  * Method [`tell#0`](#tell%230)
  * Method [`close#0`](#close%230)
  * Method [`write#1`](#write%231)
  * Method [`write_close#1`](#write_close%231)
  * Method [`flush#0`](#flush%230)
  * Method [`read#0`](#read%230)
  * Method [`readln#0`](#readln%230)
  * Method [`read#1`](#read%231)
  * Method [`read_close#0`](#read_close%230)
  * Method [`get_fd#0`](#get_fd%230)
  * Method [`next_item#0`](#next_item%230)
  * Method [`to_string#0`](#to_string%230)
  * Method [`print#0`](#print%230)

-----

## Constructors

<a name="File#2" />

### Constructor [`File#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L2480)

Creates object of class `File`, based on file path and file open flags.

**Parameters:**

1. Object of class `String` containing path to file.
2. Object of class `String` containing file open flags.

**Example:**

```cpp
obj = new File("numbers.txt","r");
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

### Operator [`operator_binary_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L2466)

Assignment operator `=`. Object of class `File` is replaced by method parameter.

**Parameters:**

1. Any type.

**Return:**

* Method parameter.

**Example:**

```cpp
obj = new File("numbers.txt","r");
("obj: %s\n" % $obj).print();
obj = "New value";
("obj: %s\n" % $obj).print();
```
```
obj: File
obj: New value
```

-----

## Methods

<a name="seek#2" />

### Method [`seek#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L2491)

Sets file position indicator of stream represented by object of class `File`.
New position in bytes is obtained by adding offset to given position
indicator.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float` identifying offset in bytes.
2. Object of class `Char`, `Integer` or `Float` identifying position to which offset is added.

**Return:**

* Object of class `File`.

**Example:**

```cpp
obj = new File("numbers.txt","r");
("line: %s\n" % obj.readln()).print();
("line: %s\n" % obj.readln()).print();
obj.seek(0,File.SEEK_SET);
("line: %s\n" % obj.readln()).print();
```
```
line: Line number 1
line: Line number 2
line: Line number 1
```

<a name="tell#0" />

### Method [`tell#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L2536)

Return of file position indicator of stream represented by object of class
`File`.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
obj = new File("numbers.txt","r");
obj.readln();
("obj.tell(): %d\n" % obj.tell()).print();
obj.readln();
("obj.tell(): %d\n" % obj.tell()).print();
```
```
obj.tell(): 14
obj.tell(): 28
```

<a name="close#0" />

### Method [`close#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L2565)

Closes stream represented by object of class `File`.

**Return:**

* Object of class `File`.

**Example:**

```cpp
obj = new File("numbers.txt","r");
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

### Method [`write#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L3779)

Write object of class `String` to stream represented by object of class `File`.

**Parameters:**

1. Object of class `String`.

**Return:**

* Object of class `File`.

**Example:**

```cpp
obj = new File("output.txt","w");
obj.write("Hello world!\n");
"Done\n".print();
```
```
Done
```

<a name="write_close#1" />

### Method [`write_close#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L2587)

Write object of class `String` to stream represented by object of class `File`, and closes it immediately.

**Parameters:**

1. Object of class `String`.

**Return:**

* Object of class `File`.

**Example:**

```cpp
obj = new File("output.txt","w");
obj.write_close("Hello world!\n");
"Done\n".print();
```
```
Done
```

<a name="flush#0" />

### Method [`flush#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L3803)

Force write of all buffered data of output stream represented by object of class `File`.

**Return:**

* Object of class `File`.

**Example:**

```cpp
obj = new File("output.txt","w");
obj.write("Hello world!\n");
obj.flush();
"Done\n".print();
```
```
Done
```

<a name="read#0" />

### Method [`read#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L3829)

Read all data from stream represented by object of class `File`, and return object of class `String` containing read data.

**Return:**

* Object of class `String` if stream contains any bytes to read.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = new File("numbers.txt","r");
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

### Method [`readln#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L3839)

Read one line from stream represented by object of class `File`, and return object of class `String` containing read line.

**Return:**

* Object of class `String` if stream contains any lines to read.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = new File("numbers.txt","r");
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

### Method [`read#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L3844)

Read requested count of bytes from stream represented by object of class `File`, and return object of class `String` containing read bytes.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
obj = new File("numbers.txt","r");
obj.read(32).print();
'\n'.print();
```
```
Line number 1
Line number 2
Line
```

<a name="read_close#0" />

### Method [`read_close#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L2612)

Read all data from stream represented by object of class `File`, and return object of class `String` containing read data. Input stream will be closed after reading.

**Return:**

* Object of class `String` if stream contains any bytes to read.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = new File("numbers.txt","r");
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

### Method [`get_fd#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L3909)

Return integer file descriptor of stream represented by object of class `File`.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
obj = new File("numbers.txt","r");
("obj.get_fd(): %d\n" % obj.get_fd()).print();
```
```
obj.get_fd(): 3
```

<a name="next_item#0" />

### Method `spec` [`next_item#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L3931)

Read one line from stream represented by object of class `File`, and return object of class `String` containing read line.

**Return:**

* Object of class `String` if stream contains any lines to read.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = new File("numbers.txt","r");
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

### Method `spec` `static` [`to_string#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L2623)

Convert object of class `File` to object of class `String`.
This method returns name of class `File`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
("File.to_string(): %s\n" % File.to_string()).print();
```
```
File.to_string(): File
```

<a name="print#0" />

### Method `spec` `static` [`print#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L2632)

Print string representation of object of class `File` to standard output.
This method prints name of class `File`.

**Return:**

* Object of class `File`.

**Example:**

```cpp
File.print();
"\n".print();
```
```
File
```
