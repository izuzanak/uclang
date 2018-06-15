# Class Json

Class supporting serialization and deserialization of language objects to JavaScript Object Notation.

-----

## Table of methods

* Methods

  * Method [`create#1`](#create%231)
  * Method [`create_nice#2`](#create_nice%232)
  * Method [`create_nice#3`](#create_nice%233)
  * Method [`parse#1`](#parse%231)
  * Method [`to_string#0`](#to_string%230)
  * Method [`print#0`](#print%230)

-----

## Methods

<a name="create#1" />

### Method `static` [`create#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/json_uclm/source_files/json_module.cc#L186)

Create object of class `String` containing `JSON` representation of method parameter.

**Parameters:**

1. Object of class `Dict`.

**Return:**

Object of class `String` containing `JSON` representation of method parameter.

**Example:**

```cpp
obj = Json.create(new Dict(["One",1,"Two",2,"Three",3]));
("obj: %s\n" % obj).print();
```
```
obj: {"One":1,"Two":2,"Three":3}
```

<a name="create_nice#2" />

### Method `static` [`create_nice#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/json_uclm/source_files/json_module.cc#L386)

Create object of class `String` containing `JSON` representation of method parameter.
Output is formatted in Human readable format.

**Parameters:**

1. Object of class `Dict`.
2. Object of class `String`, representing tabular string.

**Return:**

Object of class `String` containing `JSON` representation of method parameter.

**Example:**

```cpp
dict = new Dict(["One",1,"Two",2,"Three",3]);
obj = Json.create_nice(dict,"   ");
("obj: %s\n" % obj).print();
```
```
obj: {
   "One": 1,
   "Two": 2,
   "Three": 3
}
```

<a name="create_nice#3" />

### Method `static` [`create_nice#3`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/json_uclm/source_files/json_module.cc#L436)

Create object of class `String` containing `JSON` representation of method parameter.
Output is formatted in Human readable format, and all but first line are indented by given string.

**Parameters:**

1. Object of class `Dict`.
2. Object of class `String`, representing tabular string.
3. Object of class `String`, representing indentation string.

**Return:**

Object of class `String` containing `JSON` representation of method parameter.

**Example:**

```cpp
dict = new Dict(["One",1,"Two",2,"Three",3]);
obj = Json.create_nice(dict,"   ","|||");
("obj: %s\n" % obj).print();
```
```
obj: {
|||   "One": 1,
|||   "Two": 2,
|||   "Three": 3
|||}
```

<a name="parse#1" />

### Method `static` [`parse#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/json_uclm/source_files/json_module.cc#L487)

Parse object of class `String` containing `JSON` representation of object.

**Parameters:**

1. Object of class `String` containing `JSON` representation of object.

**Return:**

Object of class `Dict`.

**Example:**

```cpp
obj = Json.parse("{\"One\":1,\"Two\":2,\"Three\":3}");
("obj: %s\n" % $obj).print();
```
```
obj: [One:1,Two:2,Three:3]
```

<a name="to_string#0" />

### Method `spec` `static` [`to_string#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/json_uclm/source_files/json_module.cc#L532)

Convert object of class `Json` to object of class `String`.
This method returns name of class `Json`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
("Json.to_string(): %s\n" % Json.to_string()).print();
```
```
Json.to_string(): Json
```

<a name="print#0" />

### Method `spec` `static` [`print#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/json_uclm/source_files/json_module.cc#L541)

Print string representation of object of class `Json` to standard output.
This method prints name of class `Json`.

**Return:**

* Object of class `Json`.

**Example:**

```cpp
Json.print();
"\n".print();
```
```
Json
```
