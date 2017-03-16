# Class Type

Class describing one particular data type, by identification of its class.

-----

## Table of methods

* Constructors

  * Constructor [`Type#0`](#Type%230)
  * Constructor [`Type#1`](#Type%231)

* Operators

  * Operator [`operator_binary_equal#1`](#operator_binary_equal%231)
  * Operator [`operator_binary_double_equal#1`](#operator_binary_double_equal%231)
  * Operator [`operator_binary_exclamation_equal#1`](#operator_binary_exclamation_equal%231)

* Methods

  * Method [`compare#1`](#compare%231)
  * Method [`to_string#0`](#to_string%230)
  * Method [`print#0`](#print%230)

-----

## Constructors

<a name="Type#0" />

### Constructor [`Type#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L8056)

Creates default object of class `Type`.

**Example:**

```cpp
obj = new Type();
("obj: %s\n" % $obj).print();
```
```
obj: Blank
```

<a name="Type#1" />

### Constructor [`Type#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L8061)

Creates object of class `Type` identifying type of method parameter.

**Parameters:**

1. Any type.

**Example:**

```cpp
obj = new Type("Hello world");
("obj: %s\n" % $obj).print();
```
```
obj: String
```

-----

## Operators

<a name="operator_binary_equal#1" />

### Operator [`operator_binary_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L7998)

Assignment operator `=`. Object of class `Type` is replaced by method parameter.

**Parameters:**

1. Any type.

**Return:**

* Method parameter.

**Example:**

```cpp
obj = type Integer;
("obj: %s\n" % $obj).print();
obj = "New value";
("obj: %s\n" % $obj).print();
```
```
obj: Integer
obj: New value
```

<a name="operator_binary_double_equal#1" />

### Operator [`operator_binary_double_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L8012)

Comparison operator `==`. Compares object of class `Type` with method parameter and return `1` if objects has same value or `0` otherwise.

**Parameters:**

1. Any type.

**Return:**

* Object of class `Integer`.
  * `0` - method parameter has different value than object.
  * `1` - method parameter has same value as object.

**Example:**

```cpp
obj_0 = type Integer;
obj_1 = type [1,2,3,4,5];
obj_2 = obj_0;
("obj_0 == obj_1: %d\n" % (obj_0 == obj_1)).print();
("obj_0 == obj_2: %d\n" % (obj_0 == obj_2)).print();
```
```
obj_0 == obj_1: 0
obj_0 == obj_2: 1
```

<a name="operator_binary_exclamation_equal#1" />

### Operator [`operator_binary_exclamation_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L8034)

Comparison operator `!=`. Compares object of class `Type` with method parameter and return `0` if objects has same value or `1` otherwise.

**Parameters:**

1. Any type.

**Return:**

* Object of class `Integer`.
  * `0` - method parameter has same value as object.
  * `1` - method parameter has different value than object.

**Example:**

```cpp
obj_0 = type Integer;
obj_1 = type [1,2,3,4,5];
obj_2 = obj_0;
("obj_0 != obj_1: %d\n" % (obj_0 != obj_1)).print();
("obj_0 != obj_2: %d\n" % (obj_0 != obj_2)).print();
```
```
obj_0 != obj_1: 1
obj_0 != obj_2: 0
```

-----

## Methods

<a name="compare#1" />

### Method `spec` [`compare#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L8071)

Compare object of class `Type` with method parameter.

**Parameters:**

1. Any type.

**Return:**

* Integer `-1` if object of class `Type` is lesser than method parameter.
* Integer `1` if object of class `Type` is greater than method parameter.
* Integer `0` if object of class `Type` is equal to method parameter.

**Example:**

```cpp
obj_0 = type Integer;
obj_1 = type [1,2,3,4,5];
("obj_0.compare(obj_1): %d\n" % obj_0.compare(obj_1)).print();
("obj_1.compare(obj_0): %d\n" % obj_1.compare(obj_0)).print();
("obj_0.compare(obj_0): %d\n" % obj_0.compare(obj_0)).print();
```
```
obj_0.compare(obj_1): -1
obj_1.compare(obj_0): 1
obj_0.compare(obj_0): 0
```

<a name="to_string#0" />

### Method `spec` [`to_string#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L8096)

Convert object of class `Type` to object of class `String`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
obj = type Integer;
("obj.to_string(): %s\n" % obj.to_string()).print();
```
```
obj.to_string(): Integer
```

<a name="print#0" />

### Method `spec` [`print#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L8107)

Print string representation of object of class `Type` to standard output.

**Return:**

* Object of class `Blank`.

**Example:**

```cpp
obj = type Integer;
obj.print();
"\n".print();
```
```
Integer
```
