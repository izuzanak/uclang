# Class Pack

Class supporting packing of arbitrary data to its binary
representation.

-----

## Table of methods

* Methods

  * Method [`pack#1`](#pack%231)
  * Method [`unpack#1`](#unpack%231)
  * Method [`code#2`](#code%232)
  * Method [`decode#2`](#decode%232)
  * Method [`to_string#0`](#to_string%230)
  * Method [`print#0`](#print%230)

-----

## Methods

<a name="pack#1" />

### Method `static` [`pack#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/pack_uclm/source_files/pack_module.cc#L254)

Convert object of any type to its binary representation.

**Parameters:**

1. Any type.

**Return:**

* Object of class `String`.

**Example:**

```cpp
data = Pack.pack(new Dict(["One",1,"Two",2,"Three",3]));
("data.length(): %d\n" % data.length()).print();
```
```
data.length(): 129
```

<a name="unpack#1" />

### Method `static` [`unpack#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/pack_uclm/source_files/pack_module.cc#L365)

Creates object from its binary representation.

**Parameters:**

1. Object of class `String`.

**Return:**

* Object of class determined by its binary representation.

**Example:**

```cpp
data = Pack.pack(new Dict(["One",1,"Two",2,"Three",3]));
result = Pack.unpack(data);
("result: %s\n" % result.to_string()).print();
```
```
result: [One:1,Two:2,Three:3]
```

<a name="code#2" />

### Method `static` [`code#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/pack_uclm/source_files/pack_module.cc#L547)

Convert list of objects to their binary representation. Binary format of
encoded objects is determined by first method parameter. Parser
of binary format string is described in file
[`pack_code.rules`](https://github.com/izuzanak/uclang/blob/master/uclang/parsers/pack_code/pack_code.rules).

**Parameters:**

1. Object of class `String`.
2. Single object or array of objects to be converted to their binary
representation.

**Return:**

* Object of class `String`.

**Example:**

```cpp
data = Pack.code("bhif",[127,32767,2147483647,1.0]);
("data.length(): %d\n" % data.length()).print();
```
```
data.length(): 11
```

<a name="decode#2" />

### Method `static` [`decode#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/pack_uclm/source_files/pack_module.cc#L920)

Convert binary string to array of objects. Binary format of encoded objects
is determined by first method parameter. Parser of binary format string is
described in file
[`pack_code.rules`](https://github.com/izuzanak/uclang/blob/master/uclang/parsers/pack_code/pack_code.rules).

**Parameters:**

1. Object of class `String`.
2. Object of class `String`.

**Return:**

* Object of class `Array` containing retrieved objects. Last element of
array contains unused part of input binary string.

**Example:**

```cpp
format = "bhif";
data = Pack.code(format,[127,32767,2147483647,1.0]);
result = Pack.decode(format,data);
("result: %s\n" % result.to_string()).print();
```
```
result: [127,32767,2147483647,1.000000,]
```

<a name="to_string#0" />

### Method `spec` `static` [`to_string#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/pack_uclm/source_files/pack_module.cc#L1254)

Convert object of class `Pack` to object of class `String`.
This method returns name of class `Pack`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
("Pack.to_string(): %s\n" % Pack.to_string()).print();
```
```
Pack.to_string(): Pack
```

<a name="print#0" />

### Method `spec` `static` [`print#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/pack_uclm/source_files/pack_module.cc#L1263)

Print string representation of object of class `Pack` to standard output.
This method prints name of class `Pack`.

**Return:**

* Object of class `Blank`.

**Example:**

```cpp
Pack.print();
"\n".print();
```
```
Pack
```
