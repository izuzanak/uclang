# Class Poll

Class providing access to system poll mechanism for monitoring multiple file descriptors.

-----

## Static constants

* Event type constants for poll operations
  * `Poll.POLLIN` - Data available to read.
  * `Poll.POLLPRI` - Urgent data available to read.
  * `Poll.POLLOUT` - Writing now will not block.
  * `Poll.POLLERR` - Error condition.
  * `Poll.POLLHUP` - Hang up.
  * `Poll.POLLNVAL` - Invalid request, file descriptor not open.

-----

## Table of methods

* Constructors

  * Constructor [`Poll#1`](#Poll%231)

* Operators

  * Operator [`operator_binary_equal#1`](#operator_binary_equal%231)

* Methods

  * Method [`ready#1`](#ready%231)
  * Method [`poll#1`](#poll%231)
  * Method [`to_string#0`](#to_string%230)
  * Method [`print#0`](#print%230)

-----

## Constructors

<a name="Poll#1" />

### Constructor [`Poll#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L4822)

Creates object of class `Poll` from array of alternating file descriptor and
event pairs.

**Parameters:**

1. Object of class `Array` containing alternating file descriptor integers and event mask integers.

**Example:**

```cpp
pipe = Sys.pipe();
pipe[1].write_close("Hello\n");
obj = new Poll([pipe[0].get_fd(),Poll.POLLIN]);
("obj: %s\n" % $obj).print();
pipe[0].close();
```
```
obj: Poll
```

-----

## Operators

<a name="operator_binary_equal#1" />

### Operator [`operator_binary_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L4810)

Assignment operator `=`. Object of class `Poll` is replaced by method parameter.

**Parameters:**

1. Any type.

**Return:**

* Method parameter.

**Example:**

```cpp
pipe = Sys.pipe();
pipe[1].write_close("Hello\n");
obj = new Poll([pipe[0].get_fd(),Poll.POLLIN]);
("obj: %s\n" % $obj).print();
obj = "New value";
("obj: %s\n" % $obj).print();
```
```
obj: Poll
obj: New value
```

-----

## Methods

<a name="ready#1" />

### Method [`ready#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L4889)

Polls file descriptors with given timeout. Returns `1` if any file descriptor
is ready, `0` if timeout expired.

**Parameters:**

1. Type convertible to integer representing timeout in milliseconds.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
pipe = Sys.pipe();
pipe[1].write_close("Hello\n");
obj = new Poll([pipe[0].get_fd(),Poll.POLLIN]);
("ready: %d\n" % obj.ready(100)).print();
pipe[0].close();
```
```
ready: 1
```

<a name="poll#1" />

### Method [`poll#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L4926)

Polls file descriptors with given timeout. Returns array of revents values
for each file descriptor, or object of class `Blank` on timeout.

**Parameters:**

1. Type convertible to integer representing timeout in milliseconds.

**Return:**

* Object of class `Array` containing revents integers, or object of class `Blank`.

**Example:**

```cpp
pipe = Sys.pipe();
pipe[1].write_close("Hello\n");
obj = new Poll([pipe[0].get_fd(),Poll.POLLIN]);
res = obj.poll(100);
("poll: %s\n" % $res).print();
pipe[0].close();
```
```
poll: [17]
```

<a name="to_string#0" />

### Method `spec` `static` [`to_string#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L4983)

Convert object of class `Poll` to object of class `String`.
This method returns name of class `Poll`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
("Poll.to_string(): %s\n" % Poll.to_string()).print();
```
```
Poll.to_string(): Poll
```

<a name="print#0" />

### Method `spec` `static` [`print#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L4992)

Print string representation of object of class `Poll` to standard output.
This method prints name of class `Poll`.

**Return:**

* Object of class `Poll`.

**Example:**

```cpp
Poll.print();
"\n".print();
```
```
Poll
```
