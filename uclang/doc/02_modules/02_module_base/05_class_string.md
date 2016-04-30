# Class String

Class describing strings of one byte characters.

-----

## Table of methods

* Constructors

  * Constructor [`String#0`](#String%230)
  * Constructor [`String#1`](#String%231)

* Operators

  * Operator [`operator_binary_equal#1`](#operator_binary_equal%231)
  * Operator [`operator_binary_plus_equal#1`](#operator_binary_plus_equal%231)
  * Operator [`operator_binary_asterisk_equal#1`](#operator_binary_asterisk_equal%231)
  * Operator [`operator_binary_double_equal#1`](#operator_binary_double_equal%231)
  * Operator [`operator_binary_exclamation_equal#1`](#operator_binary_exclamation_equal%231)
  * Operator [`operator_binary_plus#1`](#operator_binary_plus%231)
  * Operator [`operator_binary_asterisk#1`](#operator_binary_asterisk%231)
  * Operator [`operator_binary_percent#1`](#operator_binary_percent%231)
  * Operator [`operator_binary_le_br_re_br#1`](#operator_binary_le_br_re_br%231)

* Methods

  * Method [`create#1`](#create%231)
  * Method [`split#1`](#split%231)
  * Method [`join#1`](#join%231)
  * Method [`head#1`](#head%231)
  * Method [`tail#1`](#tail%231)
  * Method [`range#2`](#range%232)
  * Method [`get_idx#1`](#get_idx%231)
  * Method [`get_idxs#1`](#get_idxs%231)
  * Method [`replace#2`](#replace%232)
  * Method [`contain#1`](#contain%231)
  * Method [`compare#1`](#compare%231)
  * Method [`item#1`](#item%231)
  * Method [`first_idx#0`](#first_idx%230)
  * Method [`next_idx#1`](#next_idx%231)
  * Method [`length#0`](#length%230)
  * Method [`to_string#0`](#to_string%230)
  * Method [`print#0`](#print%230)

-----

## Constructors

<a name="String#0" />

### Constructor [`String#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L5078)

Creates default object of class `String`.

**Example:**

```cpp
obj = new String();
("obj: %s\n" % obj.to_string()).print();
```
```
obj: 
```

<a name="String#1" />

### Constructor [`String#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L5083)

Creates object of class `String` from method parameter.

**Parameters:**

1. Object of class `Char`, `Integer`, `Float` or `String`.

**Example:**

```cpp
obj = new String('e');
("obj: %s\n" % obj).print();
obj = new String(123);
("obj: %s\n" % obj).print();
obj = new String(12.234);
("obj: %s\n" % obj).print();
obj = new String("Hi world!");
("obj: %s\n" % obj).print();
```
```
obj: e
obj: 123
obj: 12.234000
obj: Hi world!
```

-----

## Operators

<a name="operator_binary_equal#1" />

### Operator [`operator_binary_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L4422)

Assignment operator `=`. Object of class `String` is replaced by method parameter.

**Parameters:**

1. Any type.

**Return:**

* Method parameter.

**Example:**

```cpp
obj = "Hi world!";
("obj: %s\n" % obj.to_string()).print();
obj = "New value";
("obj: %s\n" % obj.to_string()).print();
```
```
obj: Hi world!
obj: New value
```

<a name="operator_binary_plus_equal#1" />

### Operator [`operator_binary_plus_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L4436)

Append and assign operator `+=`. Operator appends value of method parameter to value of object of class `String`.

**Parameters:**

1. Object of class `String`.

**Return:**

* Value of object.

**Example:**

```cpp
obj = "Hi world!";
("obj: %s\n" % obj).print();
obj += " How are you?";
("obj: %s\n" % obj).print();
```
```
obj: Hi world!
obj: Hi world! How are you?
```

<a name="operator_binary_asterisk_equal#1" />

### Operator [`operator_binary_asterisk_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L4475)

Repeat and assign operator `*=`. Repeat value of object of class `String` `x` times, where `x` is given by method parameter.

**Parameters:**

1. Type convertible to integer.

**Return:**

* Value of object.

**Example:**

```cpp
obj = "Hi world!";
("obj: %s\n" % obj).print();
obj *= 5;
("obj: %s\n" % obj).print();
```
```
obj: Hi world!
obj: Hi world!Hi world!Hi world!Hi world!Hi world!
```

<a name="operator_binary_double_equal#1" />

### Operator [`operator_binary_double_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L4512)

Comparison operator `==`. Compares object of class `String` with method parameter and return `1` if objects has same value or `0` otherwise.

**Parameters:**

1. Any type.

**Return:**

* Object of class `Integer`.
  * `0` - method parameter has different value than object.
  * `1` - method parameter has same value as object.

**Example:**

```cpp
obj_0 = "Hi world!";
obj_1 = "How are you?";
obj_2 = obj_0;
("obj_0 == obj_1: %d\n" % (obj_0 == obj_1)).print();
("obj_0 == obj_2: %d\n" % (obj_0 == obj_2)).print();
```
```
obj_0 == obj_1: 0
obj_0 == obj_2: 1
```

<a name="operator_binary_exclamation_equal#1" />

### Operator [`operator_binary_exclamation_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L4534)

Comparison operator `!=`. Compares object of class `String` with method parameter and return `0` if objects has same value or `1` otherwise.

**Parameters:**

1. Any type.

**Return:**

* Object of class `Integer`.
  * `0` - method parameter has same value as object.
  * `1` - method parameter has different value than object.

**Example:**

```cpp
obj_0 = "Hi world!";
obj_1 = "How are you?";
obj_2 = obj_0;
("obj_0 != obj_1: %d\n" % (obj_0 != obj_1)).print();
("obj_0 != obj_2: %d\n" % (obj_0 != obj_2)).print();
```
```
obj_0 != obj_1: 1
obj_0 != obj_2: 0
```

<a name="operator_binary_plus#1" />

### Operator [`operator_binary_plus#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L4556)

Append operator `+`. Append value of method parameter to value of object of class `String`.

**Parameters:**

1. Object of class `String`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
obj = "Hi world!";
("obj: %s\n" % obj).print();
("res: %s\n" % (obj + " How are you?")).print();
```
```
obj: Hi world!
res: Hi world! How are you?
```

<a name="operator_binary_asterisk#1" />

### Operator [`operator_binary_asterisk#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L4593)

Repeat operator `*`. Repeat value of object of class `String` `x` times, where `x` is given by method parameter.

**Parameters:**

1. Type convertible to integer.

**Return:**

* Value of class `String`.

**Example:**

```cpp
obj = "Hi world!";
("obj: %s\n" % obj).print();
("res: %s\n" % (obj * 5)).print();
```
```
obj: Hi world!
res: Hi world!Hi world!Hi world!Hi world!Hi world!
```

<a name="operator_binary_percent#1" />

### Operator [`operator_binary_percent#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L4628)

String format operator `%`. Value of class `String` is formatted according to formating characters contained in it.

**Parameters:**

1. Any type supported by formating characters or object of class `Array`.

**Return:**

* Value of class `String`.

**Example:**

```cpp
("res: %s\n" % ("char:    %c" % 'e')).print();
("res: %s\n" % ("integer: %d" % 123)).print();
("res: %s\n" % ("float:   %f" % 12.234)).print();
("res: %s\n" % ("string:  %s" % "Hi world!")).print();
("res: %s\n" % ("array:   %d,%d,%d" % [1,2,3])).print();
```
```
res: char:    e
res: integer: 123
res: float:   12.234000
res: string:  Hi world!
res: array:   1,2,3
```

<a name="operator_binary_le_br_re_br#1" />

### Operator [`operator_binary_le_br_re_br#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L5071)

Item selection operator `[]`.
Retrieve element from object of class `String` stored at requested index position.

**Parameters:**

1. Type convertible to integer.

**Return:**

 * Object stored in object of class `String` at position of requested index.

**Example:**

```cpp
obj = "Hi world!";
("obj: %s\n" % obj.to_string()).print();
("obj[0]: %s\n" % obj[0].to_string()).print();
("obj[1]: %s\n" % obj[1].to_string()).print();
("obj[2]: %s\n" % obj[2].to_string()).print();
("obj[3]: %s\n" % obj[3].to_string()).print();
("obj[4]: %s\n" % obj[4].to_string()).print();
```
```
obj: Hi world!
obj[0]: H
obj[1]: i
obj[2]:  
obj[3]: w
obj[4]: o
```

-----

## Methods

<a name="create#1" />

### Method `static` [`create#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L5153)

Create new object of class `String` which size is given by method parameter.

**Parameters:**

1. Type convertible to integer.

**Return:**

* Object of class `String`.

**Example:**

```cpp
obj = String.create('e');
("obj.length(): %d\n" % obj.length()).print();
obj = String.create(123);
("obj.length(): %d\n" % obj.length()).print();
obj = String.create(12.234);
("obj.length(): %d\n" % obj.length()).print();
```
```
obj.length(): 101
obj.length(): 123
obj.length(): 12
```

<a name="split#1" />

### Method [`split#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L5179)

Split object of class `String` to object of class ``Array`` containing one or more objects of class `String`.

**Parameters:**

1. Object of class `String`.

**Return:**

* Object of class `Array` containing one or more objects of class `String`.

**Example:**

```cpp
obj = "Hi world!";
("obj: %s\n" % obj).print();
("res: %s\n" % obj.split(" ").to_string()).print();
```
```
obj: Hi world!
res: [Hi,world!]
```

<a name="join#1" />

### Method [`join#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L5242)

Objects of iterable which is given as method parameter are converted to
strings by call of its to_string#0 method.  Result strings are then
concatenated to one string, with object of class `String` used as separator.

**Parameters:**

1. Iterable type.

**Return:**

* Object of class `String`.

**Example:**

```cpp
obj = [1,2,3,4,5];
("res: %s\n" % " ".join(obj).to_string()).print();
obj = new Dict(["One",1,"Two",2,"Three",3]);
("res: %s\n" % " ".join(obj).to_string()).print();
obj = ["numbers:",1,2,3,4,"end"];
("res: %s\n" % " ".join(obj).to_string()).print();
```
```
res: 1 2 3 4 5
res: One Two Three
res: numbers: 1 2 3 4 end
```

<a name="head#1" />

### Method [`head#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L5356)

Retrieve substring of object of class `String` containing first `n` characters, where `n` is given by method parameter.

**Parameters:**

1. Object of class convertible to `Integer`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
obj = "Hi world!";
("obj.head(2): %s\n" % obj.head(2)).print();
("obj.head(8.25): %s\n" % obj.head(8.25)).print();
("obj.head(-1): %s\n" % obj.head(-1)).print();
```
```
obj.head(2): Hi
obj.head(8.25): Hi world
obj.head(-1): Hi world
```

<a name="tail#1" />

### Method [`tail#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L5403)

Retrieve substring of object of class `String` containing last `n` characters, where `n` is given by method parameter.

**Parameters:**

1. Object of class convertible to `Integer`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
obj = "Hi world!";
("obj.tail(6): %s\n" % obj.tail(6)).print();
("obj.tail(6.25): %s\n" % obj.tail(6.25)).print();
("obj.tail(-3): %s\n" % obj.tail(-3)).print();
```
```
obj.tail(6): world!
obj.tail(6.25): world!
obj.tail(-3): world!
```

<a name="range#2" />

### Method [`range#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L5450)

From object of class `String` retrieve substring identified by indexes of first and last character in source string.

**Parameters:**

1. Object of class convertible to `Integer`.
2. Object of class convertible to `Integer`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
obj = "Hi world!";
("obj.range(0,1): %s\n" % obj.range(0,1)).print();
("obj.range(3,-2): %s\n" % obj.range(3,-2)).print();
("obj.range(-1,-1): %s\n" % obj.range(-1,-1)).print();
```
```
obj.range(0,1): Hi
obj.range(3,-2): world
obj.range(-1,-1): !
```

<a name="get_idx#1" />

### Method [`get_idx#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L5522)

Retrieve index of substring given by method parameter in object of class `String`.

**Parameters:**

1. Object of class `String`.

**Return:**

* Object of class `Integer`, if substring is contained in object of class `String`.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = "Hi world!";
("obj.get_idx(\"Hi\"): %d\n" % obj.get_idx("Hi")).print();
("obj.get_idx(\"world\"): %d\n" % obj.get_idx("world")).print();
("obj.get_idx(\"Test\"): %s\n" % obj.get_idx("Test").to_string()).print();
```
```
obj.get_idx("Hi"): 0
obj.get_idx("world"): 3
obj.get_idx("Test"): <blank>
```

<a name="get_idxs#1" />

### Method [`get_idxs#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L5550)

Retrieve all indexes of substring given by method parameter in object of class `String`.

**Parameters:**

1. Object of class `String`.

**Return:**

* Object of class `Array`, containing all positions of substring in original object of class `String`.

**Example:**

```cpp
obj = "This sentence contain more than one character 'e'.";
("obj.get_idxs(\"one\"): %s\n" % obj.get_idxs("one").to_string()).print();
("obj.get_idxs(\"Test\"): %s\n" % obj.get_idxs("Test").to_string()).print();
("obj.get_idxs(\"e\"): %s\n" % obj.get_idxs("e").to_string()).print();
```
```
obj.get_idxs("one"): [32]
obj.get_idxs("Test"): []
obj.get_idxs("e"): [6,9,12,25,34,43,47]
```

<a name="replace#2" />

### Method [`replace#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L5604)

In object of class `String` replace all substrings given as first method parameter by string given as second method parameter.

**Parameters:**

1. Object of class `String` identifying substrings to be replaced by second method parameter.
2. Object of class `String` which replaces substrings identified by first method parameter.

**Return:**

* Object of class `String`.

**Example:**

```cpp
obj = "Hi world!";
("res: %s\n" % obj.replace("Hi","Hello")).print();
("res: %s\n" % obj.replace("world","universe")).print();
```
```
res: Hello world!
res: Hi universe!
```

<a name="contain#1" />

### Method [`contain#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L5676)

Test if object of class `String` contains substring equal to method parameter.

**Parameters:**

1. Object of class ``String``.

**Return:**

Object of class ``Integer``.
  * `0` - object of class `String` does not contain substring equal to method parameter.
  * `1` - object of class `String` does contain substring equal to method parameter.

**Example:**

```cpp
obj = "Hi world!";
("obj.contain(\"Hi\"): %d\n" % obj.contain("Hi")).print();
("obj.contain(\"world\"): %d\n" % obj.contain("world")).print();
("obj.contain(\"Hello\"): %d\n" % obj.contain("Hello")).print();
```
```
obj.contain("Hi"): 1
obj.contain("world"): 1
obj.contain("Hello"): 0
```

<a name="compare#1" />

### Method `spec` [`compare#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L5705)

Compare object of class `String` with method parameter.

**Parameters:**

1. Any type.

**Return:**

* Integer `-1` if object of class `String` is lesser than method parameter.
* Integer `1` if object of class `String` is greater than method parameter.
* Integer `0` if object of class `String` is equal to method parameter.

**Example:**

```cpp
obj_0 = "Hi world!";
obj_1 = "How are you?";
("obj_0.compare(obj_1): %d\n" % obj_0.compare(obj_1)).print();
("obj_1.compare(obj_0): %d\n" % obj_1.compare(obj_0)).print();
("obj_0.compare(obj_0): %d\n" % obj_0.compare(obj_0)).print();
```
```
obj_0.compare(obj_1): -1
obj_1.compare(obj_0): 1
obj_0.compare(obj_0): 0
```

<a name="item#1" />

### Method `spec` [`item#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L5737)

Retrieve character from object of class `String` stored at requested index position.

**Parameters:**

1. Type convertible to integer.

**Return:**

* Object representing character in object of class `String` at position of requested index.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = "Hi world!";
("obj: %s\n" % obj.to_string()).print();
idx = obj.first_idx();
do {
  ("obj.item(%d): %s\n" % [idx,obj.item(idx).to_string()]).print();
  idx = obj.next_idx(idx);
} while(Blank != idx);
```
```
obj: Hi world!
obj.item(0): H
obj.item(1): i
obj.item(2):  
obj.item(3): w
obj.item(4): o
obj.item(5): r
obj.item(6): l
obj.item(7): d
obj.item(8): !
```

<a name="first_idx#0" />

### Method `spec` [`first_idx#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L5744)

Retrieve index of first character in object of class `String`.

**Return:**

* Object of class `Integer` if object of class `String` contains some characters.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = "Hi world!";
("obj.first_idx: %s\n" % obj.first_idx().to_string()).print();
obj = "";
("obj.first_idx: %s\n" % obj.first_idx().to_string()).print();
```
```
obj.first_idx: 0
obj.first_idx: <blank>
```

<a name="next_idx#1" />

### Method `spec` [`next_idx#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L5763)

From object of class `String` retrieve index of character following character identified by method parameter.

**Parameters:**

1. Type convertible to integer.

**Return:**

* Object of class `Integer` if there is some character following character identified by method parameter.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = "Hi world!";
("obj: %s\n" % obj.to_string()).print();
idx = obj.first_idx();
do {
  ("idx: %s\n" % idx.to_string()).print();
  idx = obj.next_idx(idx);
} while(Blank != idx);
```
```
obj: Hi world!
idx: 0
idx: 1
idx: 2
idx: 3
idx: 4
idx: 5
idx: 6
idx: 7
idx: 8
```

<a name="length#0" />

### Method `spec` [`length#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L5796)

Retrieve count of characters in object of class `String`.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
obj = "Hi world!";
("obj.length(): %d\n" % obj.length()).print();
obj = "";
("obj.length(): %d\n" % obj.length()).print();
```
```
obj.length(): 9
obj.length(): 0
```

<a name="to_string#0" />

### Method `spec` [`to_string#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L5808)

Convert object of class `String` to object of class `String`.
Reference counter of object is increased.

**Return:**

* Object of class `String`.

**Example:**

```cpp
obj = "Hi world!";
("obj.to_string(): %s\n" % obj.to_string()).print();
```
```
obj.to_string(): Hi world!
```

<a name="print#0" />

### Method `spec` [`print#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L5820)

Print object of class `String` to standard output.

**Return:**

* Object of class `Blank`.

**Example:**

```cpp
obj = "Hi world!";
obj.print();
"\n".print();
```
```
Hi world!
```
