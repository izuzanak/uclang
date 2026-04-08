# Class SocketAddr

Class describing network socket addresses.

-----

## Table of methods

* Constructors

  * Constructor [`SocketAddr#2`](#SocketAddr%232)

* Operators

  * Operator [`operator_binary_equal#1`](#operator_binary_equal%231)

* Methods

  * Method [`name#0`](#name%230)
  * Method [`port#0`](#port%230)
  * Method [`to_string#0`](#to_string%230)
  * Method [`print#0`](#print%230)

-----

## Constructors

<a name="SocketAddr#2" />

### Constructor [`SocketAddr#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L2664)

Creates object of class `SocketAddr` from hostname or IP address string and port number.

**Parameters:**

1. Object of class `String` containing hostname or IP address.
2. Type convertible to integer representing port number.

**Example:**

```cpp
obj = new SocketAddr("127.0.0.1",8080);
("obj: %s\n" % $obj).print();
```
```
obj: SocketAddr
```

-----

## Operators

<a name="operator_binary_equal#1" />

### Operator [`operator_binary_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L2652)

Assignment operator `=`. Object of class `SocketAddr` is replaced by method parameter.

**Parameters:**

1. Any type.

**Return:**

* Method parameter.

**Example:**

```cpp
obj = new SocketAddr("127.0.0.1",8080);
("obj: %s\n" % $obj).print();
obj = "New value";
("obj: %s\n" % $obj).print();
```
```
obj: SocketAddr
obj: New value
```

-----

## Methods

<a name="name#0" />

### Method [`name#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L2703)

Returns hostname or IP address of socket address.

**Return:**

* Object of class `String`.

**Example:**

```cpp
obj = new SocketAddr("127.0.0.1",8080);
("name: %s\n" % obj.name()).print();
```
```
name: 127.0.0.1
```

<a name="port#0" />

### Method [`port#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L2731)

Returns port number of socket address.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
obj = new SocketAddr("127.0.0.1",8080);
("port: %d\n" % obj.port()).print();
```
```
port: 8080
```

<a name="to_string#0" />

### Method `spec` `static` [`to_string#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L2744)

Convert object of class `SocketAddr` to object of class `String`.
This method returns name of class `SocketAddr`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
("SocketAddr.to_string(): %s\n" % SocketAddr.to_string()).print();
```
```
SocketAddr.to_string(): SocketAddr
```

<a name="print#0" />

### Method `spec` `static` [`print#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L2753)

Print string representation of object of class `SocketAddr` to standard output.
This method prints name of class `SocketAddr`.

**Return:**

* Object of class `SocketAddr`.

**Example:**

```cpp
SocketAddr.print();
"\n".print();
```
```
SocketAddr
```
