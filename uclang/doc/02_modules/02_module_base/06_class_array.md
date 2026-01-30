# Class Array

Container class implementing abstract data type dynamic array (vector).

-----

## Table of methods

* Constructors

  * Constructor [`Array#0`](#Array%230)
  * Constructor [`Array#1`](#Array%231)

* Operators

  * Operator [`operator_binary_equal#1`](#operator_binary_equal%231)
  * Operator [`operator_binary_plus_equal#1`](#operator_binary_plus_equal%231)
  * Operator [`operator_binary_double_equal#1`](#operator_binary_double_equal%231)
  * Operator [`operator_binary_exclamation_equal#1`](#operator_binary_exclamation_equal%231)
  * Operator [`operator_binary_plus#1`](#operator_binary_plus%231)
  * Operator [`operator_binary_ls_br_equal#1`](#operator_binary_ls_br_equal%231)
  * Operator [`operator_binary_le_br_re_br#1`](#operator_binary_le_br_re_br%231)

* Methods

  * Method [`clear#0`](#clear%230)
  * Method [`resize#1`](#resize%231)
  * Method [`push#1`](#push%231)
  * Method [`push_ref#1`](#push_ref%231)
  * Method [`pop#0`](#pop%230)
  * Method [`last#0`](#last%230)
  * Method [`fill#1`](#fill%231)
  * Method [`get_idx#1`](#get_idx%231)
  * Method [`get_idxs#1`](#get_idxs%231)
  * Method [`contain#1`](#contain%231)
  * Method [`compare#1`](#compare%231)
  * Method [`item#1`](#item%231)
  * Method [`first_idx#0`](#first_idx%230)
  * Method [`last_idx#0`](#last_idx%230)
  * Method [`next_idx#1`](#next_idx%231)
  * Method [`prev_idx#1`](#prev_idx%231)
  * Method [`length#0`](#length%230)
  * Method [`to_string#0`](#to_string%230)
  * Method [`to_string#1`](#to_string%231)
  * Method [`print#0`](#print%230)

-----

## Constructors

<a name="Array#0" />

### Constructor [`Array#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L6377)

Creates default object of class `Array`.

**Example:**

```cpp
obj = new Array();
("obj: %s\n" % $obj).print();
```
```
obj: []
```

<a name="Array#1" />

### Constructor [`Array#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L6382)

Creates object of class `Array` containing elements retrieved from method parameter.

**Parameters:**

1. Iterable type.

**Example:**

```cpp
obj = new Array([1,2,3,4,5]);
("obj: %s\n" % $obj).print();
```
```
obj: [1,2,3,4,5]
```

-----

## Operators

<a name="operator_binary_equal#1" />

### Operator [`operator_binary_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L6141)

Assignment operator `=`. Object of class `Array` is replaced by method parameter.

**Parameters:**

1. Any type.

**Return:**

* Method parameter.

**Example:**

```cpp
obj = [1,2,3,4,5];
("obj: %s\n" % $obj).print();
obj = "New value";
("obj: %s\n" % $obj).print();
```
```
obj: [1,2,3,4,5]
obj: New value
```

<a name="operator_binary_plus_equal#1" />

### Operator [`operator_binary_plus_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L6153)

Append operator `+=`. Append elements retrieved from method parameter to object of class `Array`.

**Parameters:**

1. Iterable type.

**Return:**

* Value of object.

**Example:**

```cpp
obj = [1,2,3,4,5];
("obj: %s\n" % $obj).print();
obj += [1,2,6,7,8];
("obj: %s\n" % $obj).print();
```
```
obj: [1,2,3,4,5]
obj: [1,2,3,4,5,1,2,6,7,8]
```

<a name="operator_binary_double_equal#1" />

### Operator [`operator_binary_double_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L6179)

Comparison operator `==`. Compares object of class `Array` with method parameter and return `1` if objects has same value or `0` otherwise.

**Parameters:**

1. Any type.

**Return:**

* Object of class `Integer`.
  * `0` - method parameter has different value than object.
  * `1` - method parameter has same value as object.

**Example:**

```cpp
obj_0 = [1,2,3,4,5];
obj_1 = [1,2,6,7,8];
obj_2 = obj_0;
("obj_0 == obj_1: %d\n" % (obj_0 == obj_1)).print();
("obj_0 == obj_2: %d\n" % (obj_0 == obj_2)).print();
```
```
obj_0 == obj_1: 0
obj_0 == obj_2: 1
```

<a name="operator_binary_exclamation_equal#1" />

### Operator [`operator_binary_exclamation_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L6194)

Comparison operator `!=`. Compares object of class `Array` with method parameter and return `0` if objects has same value or `1` otherwise.

**Parameters:**

1. Any type.

**Return:**

* Object of class `Integer`.
  * `0` - method parameter has same value as object.
  * `1` - method parameter has different value than object.

**Example:**

```cpp
obj_0 = [1,2,3,4,5];
obj_1 = [1,2,6,7,8];
obj_2 = obj_0;
("obj_0 != obj_1: %d\n" % (obj_0 != obj_1)).print();
("obj_0 != obj_2: %d\n" % (obj_0 != obj_2)).print();
```
```
obj_0 != obj_1: 1
obj_0 != obj_2: 0
```

<a name="operator_binary_plus#1" />

### Operator [`operator_binary_plus#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L6209)

Concatenation operator `+`. Creates object of class `Array` containing elements of original object of class `Array` concatenated with elements retrieved from method parameter.

**Parameters:**

1. Iterable type.

**Return:**

* Object of class `Array` containing elements of original object of class `Array` concatenated with elements retrieved from method parameter.

**Example:**

```cpp
obj = [1,2,3,4,5];
res = obj + [1,2,3,4,5];
("obj: %s\n" % $obj).print();
("res: %s\n" % $res).print();
```
```
obj: [1,2,3,4,5]
res: [1,2,3,4,5,1,2,3,4,5]
```

<a name="operator_binary_ls_br_equal#1" />

### Operator [`operator_binary_ls_br_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L6239)

Copy values of elements retrieved from method parameter to values of elements
of object of class `Array`.

**Parameters:**

1. Iterable type.

**Return:**

* Value of object.

**Example:**

```cpp
obj = [];
a = b = c = 0;
obj.push_ref(a);
obj.push_ref(b);
obj.push_ref(c);
("a,b,c: %s\n" % $[a,b,c]).print();
obj <= [1,2,3];
("a,b,c: %s\n" % $[a,b,c]).print();
```
```
a,b,c: [0,0,0]
a,b,c: [1,2,3]
```

<a name="operator_binary_le_br_re_br#1" />

### Operator [`operator_binary_le_br_re_br#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L6370)

Item selection operator `[]`.
Retrieve element from object of class `Array` stored at requested index position.

**Parameters:**

1. Type convertible to integer.

**Return:**

 * Object stored in object of class `Array` at position of requested index.

**Example:**

```cpp
obj = [1,2,3,4,5];
("obj: %s\n" % $obj).print();
("obj[0]: %s\n" % $obj[0]).print();
("obj[1]: %s\n" % $obj[1]).print();
("obj[2]: %s\n" % $obj[2]).print();
```
```
obj: [1,2,3,4,5]
obj[0]: 1
obj[1]: 2
obj[2]: 3
```

-----

## Methods

<a name="clear#0" />

### Method [`clear#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L6404)

Release all elements stored in object of class `Array`.

**Return:**

* Object of class `Array`.

**Example:**

```cpp
obj = [1,2,3,4,5];
("obj: %s\n" % $obj).print();
obj.clear();
("obj: %s\n" % $obj).print();
```
```
obj: [1,2,3,4,5]
obj: []
```

<a name="resize#1" />

### Method [`resize#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L6429)

Resize object of class `Array` to size given by method parameter. New
elements are initialized to objects of class `Blank`.

**Parameters:**

1. Object of class convertible to `Integer`.

**Return:**

* Object of class `Array`.

**Example:**

```cpp
obj = [1,2,3,4,5];
("obj: %s\n" % $obj).print();
obj.resize(8);
("obj: %s\n" % $obj).print();
```
```
obj: [1,2,3,4,5]
obj: [1,2,3,4,5,<blank>,<blank>,<blank>]
```

<a name="push#1" />

### Method [`push#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L6475)

Insert method parameter to end of object of class `Array`.

**Parameters:**

1. Any type.

**Return:**

* Object of class `Array`.

**Example:**

```cpp
obj = [1,2,3,4,5];
("obj: %s\n" % $obj).print();
obj.push(6);
obj.push(7);
("obj: %s\n" % $obj).print();
```
```
obj: [1,2,3,4,5]
obj: [1,2,3,4,5,6,7]
```

<a name="push_ref#1" />

### Method [`push_ref#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L6490)

Insert reference to method parameter to end of object of class `Array`.

**Parameters:**

1. Any type.

**Return:**

* Object of class `Array`.

**Example:**

```cpp
obj = [1,2,3,4,5];
value = 0;
obj.push_ref(value);
("obj: %s\n" % $obj).print();
value = "Hello world!";
("obj: %s\n" % $obj).print();
```
```
obj: [1,2,3,4,5,0]
obj: [1,2,3,4,5,Hello world!]
```

<a name="pop#0" />

### Method [`pop#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L6505)

Remove and return last element from object of class `Array`.

**Return:**

* Object removed from object of class `Array`.

**Example:**

```cpp
obj = [1,2,3,4,5];
("obj: %s\n" % $obj).print();
("obj.pop(): %s\n" % $obj.pop()).print();
("obj.pop(): %s\n" % $obj.pop()).print();
("obj: %s\n" % $obj).print();
```
```
obj: [1,2,3,4,5]
obj.pop(): 5
obj.pop(): 4
obj: [1,2,3]
```

<a name="last#0" />

### Method [`last#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L6526)

Retrieve and return last element of object of class `Array`.

**Return:**

* Object representing last element of object of class `Array`.

**Example:**

```cpp
obj = [1,2,3,4,5];
("obj: %s\n" % $obj).print();
("obj.last(): %s\n" % $obj.last()).print();
("obj: %s\n" % $obj).print();
```
```
obj: [1,2,3,4,5]
obj.last(): 5
obj: [1,2,3,4,5]
```

<a name="fill#1" />

### Method [`fill#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L6549)

Replace all elements of object of class `Array` by method parameter.

**Parameters:**

1. Any type.

**Return:**

* Object of class `Array`.

**Example:**

```cpp
obj = [1,2,3,4,5];
("obj: %s\n" % $obj).print();
obj.fill(0);
("obj: %s\n" % $obj).print();
```
```
obj: [1,2,3,4,5]
obj: [0,0,0,0,0]
```

<a name="get_idx#1" />

### Method [`get_idx#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L6575)

From object of class `Array`, retrieve index of first element equal to method parameter.

**Parameters:**

1. Any type.

**Return:**

* Object of class ``Integer``, if method parameter is contained as element in object of class `Array`.
* Object of class ``Blank`` otherwise.

**Example:**

```cpp
obj = [1,2,3,4,5];
("obj: %s\n" % $obj).print();
("obj.get_idx(2): %s\n" % $obj.get_idx(2)).print();
("obj.get_idx(100): %s\n" % $obj.get_idx(100)).print();
```
```
obj: [1,2,3,4,5]
obj.get_idx(2): 1
obj.get_idx(100): <blank>
```

<a name="get_idxs#1" />

### Method [`get_idxs#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L6608)

From object of class `Array`, retrieve indexes of elements that are equal to method parameter. Element indexes are returned as object of class ``Array``.

**Parameters:**

1. Any type.

**Return:**

* Object of class ``Array`` containing indexes of elements, that are equal to method parameter.

**Example:**

```cpp
obj = new Array([1,2,2,4,2,5]);
("obj: %s\n" % $obj).print();
("obj.get_idxs(2): %s\n" % $obj.get_idxs(2)).print();
("obj.get_idxs(100): %s\n" % $obj.get_idxs(100)).print();
```
```
obj: [1,2,2,4,2,5]
obj.get_idxs(2): [1,2,4]
obj.get_idxs(100): []
```

<a name="contain#1" />

### Method [`contain#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L6650)

Test if object of class `Array` contains element with same value as object given by method parameter.

**Parameters:**

1. Any type.

**Return:**

Object of class ``Integer``.
  * `0` - object of class `Array` does not contain element equal to method parameter.
  * `1` - object of class `Array` does contain element equal to method parameter.

**Example:**

```cpp
obj = [1,2,3,4,5];
("obj.contain(1): %d\n" % obj.contain(1)).print();
("obj.contain(2): %d\n" % obj.contain(2)).print();
("obj.contain(100): %d\n" % obj.contain(100)).print();
```
```
obj.contain(1): 1
obj.contain(2): 1
obj.contain(100): 0
```

<a name="compare#1" />

### Method `spec` [`compare#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L6683)

Compare object of class `Array` with method parameter.

**Parameters:**

1. Any type.

**Return:**

* Integer `-1` if object of class `Array` is lesser than method parameter.
* Integer `1` if object of class `Array` is greater than method parameter.
* Integer `0` if object of class `Array` is equal to method parameter.

**Example:**

```cpp
obj_0 = [1,2,3,4,5];
obj_1 = [1,2,6,7,8];
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

### Method `spec` [`item#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L6697)

Retrieve element from object of class `Array` stored at requested index position.

**Parameters:**

1. Type convertible to integer.

**Return:**

* Object representing element in object of class `Array` at position of requested index.

**Example:**

```cpp
obj = [1,2,3,4,5];
("obj: %s\n" % $obj).print();
idx = obj.first_idx();
do {
  ("obj.item(%d): %s\n" % [idx,$obj.item(idx)]).print();
  idx = obj.next_idx(idx);
} while(Blank != idx);
```
```
obj: [1,2,3,4,5]
obj.item(0): 1
obj.item(1): 2
obj.item(2): 3
obj.item(3): 4
obj.item(4): 5
```

<a name="first_idx#0" />

### Method `spec` [`first_idx#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L6704)

Retrieve index of first element in object of class `Array`.

**Return:**

* Object of class `Integer` if object of class `Array` contains some elements.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = [1,2,3,4,5];
("obj.first_idx: %s\n" % $obj.first_idx()).print();
obj.clear();
("obj.first_idx: %s\n" % $obj.first_idx()).print();
```
```
obj.first_idx: 0
obj.first_idx: <blank>
```

<a name="last_idx#0" />

### Method `spec` [`last_idx#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L6722)

Retrieve index of last element in object of class `Array`.

**Return:**

* Object of class `Integer` if object of class `Array` contains some elements.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = [1,2,3,4,5];
("obj.last_idx: %s\n" % $obj.last_idx()).print();
obj.pop();
("obj.last_idx: %s\n" % $obj.last_idx()).print();
obj.clear();
("obj.last_idx: %s\n" % $obj.last_idx()).print();
```
```
obj.last_idx: 4
obj.last_idx: 3
obj.last_idx: <blank>
```

<a name="next_idx#1" />

### Method `spec` [`next_idx#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L6742)

From object of class `Array` retrieve index of element following element identified by method parameter.

**Parameters:**

1. Type convertible to integer.

**Return:**

* Object of class `Integer` if there is some element following element identified by method parameter.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = [1,2,3,4,5];
("obj: %s\n" % $obj).print();
idx = obj.first_idx();
do {
  ("idx: %s\n" % $idx).print();
  idx = obj.next_idx(idx);
} while(Blank != idx);
```
```
obj: [1,2,3,4,5]
idx: 0
idx: 1
idx: 2
idx: 3
idx: 4
```

<a name="prev_idx#1" />

### Method `spec` [`prev_idx#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L6765)

From object of class `Array` retrieve index of element preceding element identified by method parameter.

**Parameters:**

1. Type convertible to integer.

**Return:**

* Object of class `Integer` if there is some element preceding element identified by method parameter.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = [1,2,3,4,5];
("obj: %s\n" % $obj).print();
idx = obj.last_idx();
do {
  ("idx: %s\n" % $idx).print();
  idx = obj.prev_idx(idx);
} while(Blank != idx);
```
```
obj: [1,2,3,4,5]
idx: 4
idx: 3
idx: 2
idx: 1
idx: 0
```

<a name="length#0" />

### Method `spec` [`length#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L6790)

Retrieve count of elements in object of class `Array`.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
obj = [1,2,3,4,5];
("obj.length(): %d\n" % obj.length()).print();
obj.clear();
("obj.length(): %d\n" % obj.length()).print();
```
```
obj.length(): 5
obj.length(): 0
```

<a name="to_string#0" />

### Method `spec` [`to_string#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L6801)

Convert object of class `Array` to object of class `String`.
Each element of object of class `Array` is converted to string by call of its
`to_string#0` method. As separator of string values is used character `,`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
obj = [1,2,3,4,5];
("obj.to_string(): %s\n" % obj.to_string()).print();
```
```
obj.to_string(): [1,2,3,4,5]
```

<a name="to_string#1" />

### Method [`to_string#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L6841)

Convert object of class `Array` to object of class `String`.
Each element of object of class `Array` is converted to string by call of its
`to_string#0` method. As separator of string values is used method parameter.

**Parameters:**

1. Object of class `String`. Separator of values formated to result string.

**Return:**

* Object of class `String`.

**Example:**

```cpp
obj = [1,2,3,4,5];
("obj.to_string(\"+\"): %s\n" % obj.to_string("+")).print();
("obj.to_string(\"<->\"): %s\n" % obj.to_string("<->")).print();
```
```
obj.to_string("+"): 1+2+3+4+5
obj.to_string("<->"): 1<->2<->3<->4<->5
```

<a name="print#0" />

### Method `spec` [`print#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L6887)

Print string representation of object of class `Array` to standard output.
Each element of object of class `Array` is printed by call of its `print#0`
method. As separator of printed values is used character `,`.

**Return:**

* Object of class `Array`.

**Example:**

```cpp
obj = [1,2,3,4,5];
obj.print();
"\n".print();
```
```
[1,2,3,4,5]
```
