# Class Blank

Class describing blank value.

-----

## Table of methods

* Constructors

  * Constructor [`Blank#0`](#Blank%230)

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

<a name="Blank#0" />

### Constructor [`Blank#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L733)

Creates default object of class `Blank`.

**Example:**

```cpp
obj = new Blank();
("obj: %s\n" % $obj).print();
```
```
obj: <blank>
```

-----

## Operators

<a name="operator_binary_equal#1" />

### Operator [`operator_binary_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L695)

Assignment operator `=`. Object of class `Blank` is replaced by method parameter.

**Parameters:**

1. Any type.

**Return:**

* Method parameter.

**Example:**

```cpp
obj = new Blank();
("obj: %s\n" % $obj).print();
obj = "New value";
("obj: %s\n" % $obj).print();
```
```
obj: <blank>
obj: New value
```

<a name="operator_binary_double_equal#1" />

### Operator `static` [`operator_binary_double_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L709)

Comparison operator `==`. Compares object of class `Blank` with method parameter and return `1` if objects has same value or `0` otherwise.

**Parameters:**

1. Any type.

**Return:**

* Object of class `Integer`.
  * `0` - method parameter has different value than object.
  * `1` - method parameter has same value as object.

**Example:**

```cpp
obj_0 = new Blank();
obj_1 = 0;
obj_2 = obj_0;
("obj_0 == obj_1: %d\n" % (obj_0 == obj_1)).print();
("obj_0 == obj_2: %d\n" % (obj_0 == obj_2)).print();
```
```
obj_0 == obj_1: 0
obj_0 == obj_2: 1
```

<a name="operator_binary_exclamation_equal#1" />

### Operator `static` [`operator_binary_exclamation_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L721)

Comparison operator `!=`. Compares object of class `Blank` with method parameter and return `0` if objects has same value or `1` otherwise.

**Parameters:**

1. Any type.

**Return:**

* Object of class `Integer`.
  * `0` - method parameter has same value as object.
  * `1` - method parameter has different value than object.

**Example:**

```cpp
obj_0 = new Blank();
obj_1 = 0;
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

### Method `spec` `static` [`compare#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L738)

Compare object of class `Blank` with method parameter.

**Parameters:**

1. Any type.

**Return:**

* Integer `-1` if object of class `Blank` is lesser than method parameter.
* Integer `1` if object of class `Blank` is greater than method parameter.
* Integer `0` if object of class `Blank` is equal to method parameter.

**Example:**

```cpp
obj_0 = new Blank();
obj_1 = 0;
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

### Method `spec` `static` [`to_string#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L759)

Convert object of class `Blank` to object of class `String`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
("Blank.to_string(): %s\n" % Blank.to_string()).print();
```
```
Blank.to_string(): <blank>
```

<a name="print#0" />

### Method `spec` `static` [`print#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L768)

Print string representation of object of class `Blank` to standard output.

**Return:**

* Object of class `Blank`.

**Example:**

```cpp
Blank.print();
"\n".print();
```
```
<blank>
```
