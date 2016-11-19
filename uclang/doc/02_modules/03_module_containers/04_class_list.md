# Class List

Container class implementing abstract data type list.

-----

## Table of methods

* Constructors

  * Constructor [`List#0`](#List%230)
  * Constructor [`List#1`](#List%231)

* Operators

  * Operator [`operator_binary_equal#1`](#operator_binary_equal%231)
  * Operator [`operator_binary_plus_equal#1`](#operator_binary_plus_equal%231)
  * Operator [`operator_binary_double_equal#1`](#operator_binary_double_equal%231)
  * Operator [`operator_binary_exclamation_equal#1`](#operator_binary_exclamation_equal%231)
  * Operator [`operator_binary_plus#1`](#operator_binary_plus%231)
  * Operator [`operator_binary_le_br_re_br#1`](#operator_binary_le_br_re_br%231)

* Methods

  * Method [`clear#0`](#clear%230)
  * Method [`items#0`](#items%230)
  * Method [`append#1`](#append%231)
  * Method [`append_ref#1`](#append_ref%231)
  * Method [`prepend#1`](#prepend%231)
  * Method [`prepend_ref#1`](#prepend_ref%231)
  * Method [`insert_before#2`](#insert_before%232)
  * Method [`insert_before_ref#2`](#insert_before_ref%232)
  * Method [`insert_after#2`](#insert_after%232)
  * Method [`insert_after_ref#2`](#insert_after_ref%232)
  * Method [`remove#1`](#remove%231)
  * Method [`has_idx#1`](#has_idx%231)
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

<a name="List#0" />

### Constructor [`List#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_list.cc#L651)

Creates default object of class `List`.

**Example:**

```cpp
obj = new List();
("obj: %s\n" % obj.to_string()).print();
```
```
obj: []
```

<a name="List#1" />

### Constructor [`List#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_list.cc#L656)

Creates object of class `List` containing elements retrieved from method parameter.

**Parameters:**

1. Iterable type.

**Example:**

```cpp
obj = new List([1,2,3,4,5]);
("obj: %s\n" % obj.to_string()).print();
```
```
obj: [1,2,3,4,5]
```

-----

## Operators

<a name="operator_binary_equal#1" />

### Operator [`operator_binary_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_list.cc#L533)

Assignment operator `=`. Object of class `List` is replaced by method parameter.

**Parameters:**

1. Any type.

**Return:**

* Method parameter.

**Example:**

```cpp
obj = new List([1,2,3,4,5]);
("obj: %s\n" % obj.to_string()).print();
obj = "New value";
("obj: %s\n" % obj.to_string()).print();
```
```
obj: [1,2,3,4,5]
obj: New value
```

<a name="operator_binary_plus_equal#1" />

### Operator [`operator_binary_plus_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_list.cc#L549)

Append operator `+=`. Append elements retrieved from method parameter to object of class `List`.

**Parameters:**

1. Iterable type.

**Return:**

* Value of object.

**Example:**

```cpp
obj = new List([1,2,3,4,5]);
("obj: %s\n" % obj.to_string()).print();
obj += [1,2,6,7,8];
("obj: %s\n" % obj.to_string()).print();
```
```
obj: [1,2,3,4,5]
obj: [1,2,3,4,5,1,2,6,7,8]
```

<a name="operator_binary_double_equal#1" />

### Operator [`operator_binary_double_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_list.cc#L577)

Comparison operator `==`. Compares object of class `List` with method parameter and return `1` if objects has same value or `0` otherwise.

**Parameters:**

1. Any type.

**Return:**

* Object of class `Integer`.
  * `0` - method parameter has different value than object.
  * `1` - method parameter has same value as object.

**Example:**

```cpp
obj_0 = new List([1,2,3,4,5]);
obj_1 = new List([1,2,6,7,8]);
obj_2 = obj_0;
("obj_0 == obj_1: %d\n" % (obj_0 == obj_1)).print();
("obj_0 == obj_2: %d\n" % (obj_0 == obj_2)).print();
```
```
obj_0 == obj_1: 0
obj_0 == obj_2: 1
```

<a name="operator_binary_exclamation_equal#1" />

### Operator [`operator_binary_exclamation_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_list.cc#L594)

Comparison operator `!=`. Compares object of class `List` with method parameter and return `0` if objects has same value or `1` otherwise.

**Parameters:**

1. Any type.

**Return:**

* Object of class `Integer`.
  * `0` - method parameter has same value as object.
  * `1` - method parameter has different value than object.

**Example:**

```cpp
obj_0 = new List([1,2,3,4,5]);
obj_1 = new List([1,2,6,7,8]);
obj_2 = obj_0;
("obj_0 != obj_1: %d\n" % (obj_0 != obj_1)).print();
("obj_0 != obj_2: %d\n" % (obj_0 != obj_2)).print();
```
```
obj_0 != obj_1: 1
obj_0 != obj_2: 0
```

<a name="operator_binary_plus#1" />

### Operator [`operator_binary_plus#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_list.cc#L611)

Concatenation operator `+`. Creates object of class `List` containing elements of original object of class `List` concatenated with elements retrieved from method parameter.

**Parameters:**

1. Iterable type.

**Return:**

* Object of class `List` containing elements of original object of class `List` concatenated with elements retrieved from method parameter.

**Example:**

```cpp
obj = new List([1,2,3,4,5]);
res = obj + [1,2,3,4,5];
("obj: %s\n" % obj.to_string()).print();
("res: %s\n" % res.to_string()).print();
```
```
obj: [1,2,3,4,5]
res: [1,2,3,4,5,1,2,3,4,5]
```

<a name="operator_binary_le_br_re_br#1" />

### Operator [`operator_binary_le_br_re_br#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_list.cc#L644)

Item selection operator `[]`.
Retrieve element from object of class `List` stored at requested index position.

**Parameters:**

1. Type convertible to integer.

**Return:**

 * Object stored in object of class `List` at position of requested index.

**Example:**

```cpp
obj = new List([1,2,3,4,5]);
("obj: %s\n" % obj.to_string()).print();
("obj[0]: %s\n" % obj[0].to_string()).print();
("obj[1]: %s\n" % obj[1].to_string()).print();
("obj[2]: %s\n" % obj[2].to_string()).print();
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

### Method [`clear#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_list.cc#L678)

Release all elements stored in object of class `List`.

**Return:**

* Object of class `Blank`.

**Example:**

```cpp
obj = new List([1,2,3,4,5]);
("obj: %s\n" % obj.to_string()).print();
obj.clear();
("obj: %s\n" % obj.to_string()).print();
```
```
obj: [1,2,3,4,5]
obj: []
```

<a name="items#0" />

### Method [`items#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_list.cc#L704)

Retrieve list of elements contained in object of class `List`. Elements are returned as object of class `Array`.

**Return:**

* Object of class `Array` containing all elements.

**Example:**

```cpp
obj = new List([1,2,3,4,5]);
("obj: %s\n" % obj.to_string()).print();
items = obj.items();
("type items: %s\n" % (type items).to_string()).print();
("items: %s\n" % items.to_string()).print();
```
```
obj: [1,2,3,4,5]
type items: Array
items: [1,2,3,4,5]
```

<a name="append#1" />

### Method [`append#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_list.cc#L735)

Append method parameter to end of object of class `List`.

**Parameters:**

1. Any type.

**Return:**

* Object of class ``Integer``. Index of appended element in object of class `List`.

**Example:**

```cpp
obj = new List([1,2,3,4,5]);
("obj: %s\n" % obj.to_string()).print();
("obj.append(1): %d\n" % obj.append(1)).print();
("obj.append(2): %d\n" % obj.append(2)).print();
("obj.append(3): %d\n" % obj.append(3)).print();
("obj: %s\n" % obj.to_string()).print();
```
```
obj: [1,2,3,4,5]
obj.append(1): 5
obj.append(2): 6
obj.append(3): 7
obj: [1,2,3,4,5,1,2,3]
```

<a name="append_ref#1" />

### Method [`append_ref#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_list.cc#L753)

Append reference to method parameter to end of object of class `List`.

**Parameters:**

1. Any type.

**Return:**

* Object of class ``Integer``. Index of appended element in object of class `List`.

**Example:**

```cpp
obj = new List([1,2,3,4,5]);
value = 0;
("obj.append_ref(value): %d\n" % obj.append_ref(value)).print();
("obj: %s\n" % obj.to_string()).print();
value = "Hello world!";
("obj: %s\n" % obj.to_string()).print();
```
```
obj.append_ref(value): 5
obj: [1,2,3,4,5,0]
obj: [1,2,3,4,5,Hello world!]
```

<a name="prepend#1" />

### Method [`prepend#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_list.cc#L771)

Prepend method parameter before begining of object of class `List`.

**Parameters:**

1. Any type.

**Return:**

* Object of class ``Integer``. Index of prepended element in object of class `List`.

**Example:**

```cpp
obj = new List([1,2,3,4,5]);
("obj: %s\n" % obj.to_string()).print();
("obj.prepend(1): %d\n" % obj.prepend(1)).print();
("obj.prepend(2): %d\n" % obj.prepend(2)).print();
("obj.prepend(3): %d\n" % obj.prepend(3)).print();
("obj: %s\n" % obj.to_string()).print();
```
```
obj: [1,2,3,4,5]
obj.prepend(1): 5
obj.prepend(2): 6
obj.prepend(3): 7
obj: [3,2,1,1,2,3,4,5]
```

<a name="prepend_ref#1" />

### Method [`prepend_ref#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_list.cc#L789)

Prepend reference to method parameter before begining of object of class `List`.

**Parameters:**

1. Any type.

**Return:**

* Object of class ``Integer``. Index of prepended element in object of class `List`.

**Example:**

```cpp
obj = new List([1,2,3,4,5]);
value = 0;
("obj.prepend_ref(value): %d\n" % obj.prepend_ref(value)).print();
("obj: %s\n" % obj.to_string()).print();
value = "Hello world!";
("obj: %s\n" % obj.to_string()).print();
```
```
obj.prepend_ref(value): 5
obj: [0,1,2,3,4,5]
obj: [Hello world!,1,2,3,4,5]
```

<a name="insert_before#2" />

### Method [`insert_before#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_list.cc#L807)

Insert second method parameter before element identified by first method parameter to object of class `List`.

**Parameters:**

1. Type convertible to integer.
2. Any type.

**Return:**

* Object of class ``Integer``. Index of inserted element in object of class `List`.

**Example:**

```cpp
obj = new List([1,2,3,4,5]);
idx = obj.get_idx(2);
("obj: %s\n" % obj.to_string()).print();
obj.insert_before(idx,4);
obj.insert_before(idx,5);
obj.insert_before(idx,6);
("obj: %s\n" % obj.to_string()).print();
```
```
obj: [1,2,3,4,5]
obj: [1,4,5,6,2,3,4,5]
```

<a name="insert_before_ref#2" />

### Method [`insert_before_ref#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_list.cc#L840)

Insert reference to second method parameter before element identified by first method parameter to object of class `List`.

**Parameters:**

1. Type convertible to integer.
2. Any type.

**Return:**

* Object of class ``Integer``. Index of inserted element in object of class `List`.

**Example:**

```cpp
obj = new List([1,2,3,4,5]);
value = 0;
idx = obj.get_idx(2);
("obj: %s\n" % obj.to_string()).print();
obj.insert_before_ref(idx,value);
("obj: %s\n" % obj.to_string()).print();
value = "Hello world!";
("obj: %s\n" % obj.to_string()).print();
```
```
obj: [1,2,3,4,5]
obj: [1,0,2,3,4,5]
obj: [1,Hello world!,2,3,4,5]
```

<a name="insert_after#2" />

### Method [`insert_after#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_list.cc#L873)

Insert second method parameter after element identified by first method parameter to object of class `List`.

**Parameters:**

1. Type convertible to integer.
2. Any type.

**Return:**

* Object of class ``Integer``. Index of inserted element in object of class `List`.

**Example:**

```cpp
obj = new List([1,2,3,4,5]);
idx = obj.get_idx(2);
("obj: %s\n" % obj.to_string()).print();
obj.insert_after(idx,4);
obj.insert_after(idx,5);
obj.insert_after(idx,6);
("obj: %s\n" % obj.to_string()).print();
```
```
obj: [1,2,3,4,5]
obj: [1,2,6,5,4,3,4,5]
```

<a name="insert_after_ref#2" />

### Method [`insert_after_ref#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_list.cc#L906)

Insert reference to second method parameter after element identified by first method parameter to object of class `List`.

**Parameters:**

1. Type convertible to integer.
2. Any type.

**Return:**

* Object of class ``Integer``. Index of inserted element in object of class `List`.

**Example:**

```cpp
obj = new List([1,2,3,4,5]);
value = 0;
idx = obj.get_idx(2);
("obj: %s\n" % obj.to_string()).print();
obj.insert_after_ref(idx,value);
("obj: %s\n" % obj.to_string()).print();
value = "Hello world!";
("obj: %s\n" % obj.to_string()).print();
```
```
obj: [1,2,3,4,5]
obj: [1,2,0,3,4,5]
obj: [1,2,Hello world!,3,4,5]
```

<a name="remove#1" />

### Method [`remove#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_list.cc#L939)

Remove element from object of class `List` stored at position given by method parameter.

**Parameters:**

1. Type convertible to integer.

**Return:**

* Object of class ``Blank``.

**Example:**

```cpp
obj = new List([1,2,3,4,5]);
("obj: %s\n" % obj.to_string()).print();
obj.remove(0);
obj.remove(1);
("obj: %s\n" % obj.to_string()).print();
```
```
obj: [1,2,3,4,5]
obj: [3,4,5]
```

<a name="has_idx#1" />

### Method [`has_idx#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_list.cc#L969)

Test if object of class `List` contains element with index given by method parameter.

**Parameters:**

1. Type convertible to integer.

**Return:**

Object of class `Integer`.
  * `1` - if object of class `List` contains element with given index.
  * `0` - otherwise.


**Example:**

```cpp
obj = new List([1,2,3,4,5]);
("obj: %s\n" % obj.to_string()).print();
("obj.has_idx(2): %d\n" % obj.has_idx(2)).print();
("obj.has_idx(100): %d\n" % obj.has_idx(100)).print();
```
```
obj: [1,2,3,4,5]
obj.has_idx(2): 1
obj.has_idx(100): 0
```

<a name="get_idx#1" />

### Method [`get_idx#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_list.cc#L1006)

From object of class `List`, retrieve index of first element equal to method parameter.

**Parameters:**

1. Any type.

**Return:**

* Object of class ``Integer``, if method parameter is contained as element in object of class `List`.
* Object of class ``Blank`` otherwise.

**Example:**

```cpp
obj = new List([1,2,3,4,5]);
("obj: %s\n" % obj.to_string()).print();
("obj.get_idx(2): %s\n" % obj.get_idx(2).to_string()).print();
("obj.get_idx(100): %s\n" % obj.get_idx(100).to_string()).print();
```
```
obj: [1,2,3,4,5]
obj.get_idx(2): 1
obj.get_idx(100): <blank>
```

<a name="get_idxs#1" />

### Method [`get_idxs#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_list.cc#L1040)

From object of class `List`, retrieve indexes of elements that are equal to method parameter. Element indexes are returned as object of class ``Array``.

**Parameters:**

1. Any type.

**Return:**

* Object of class ``Array`` containing indexes of elements, that are equal to method parameter.

**Example:**

```cpp
obj = new List([1,2,2,4,2,5]);
("obj: %s\n" % obj.to_string()).print();
("obj.get_idxs(2): %s\n" % obj.get_idxs(2).to_string()).print();
("obj.get_idxs(100): %s\n" % obj.get_idxs(100).to_string()).print();
```
```
obj: [1,2,2,4,2,5]
obj.get_idxs(2): [1,2,4]
obj.get_idxs(100): []
```

<a name="contain#1" />

### Method [`contain#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_list.cc#L1088)

Test if object of class `List` contains element with same value as object given by method parameter.

**Parameters:**

1. Any type.

**Return:**

Object of class ``Integer``.
  * `0` - object of class `List` does not contain element equal to method parameter.
  * `1` - object of class `List` does contain element equal to method parameter.

**Example:**

```cpp
obj = new List([1,2,3,4,5]);
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

### Method `spec` [`compare#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_list.cc#L1122)

Compare object of class `List` with method parameter.

**Parameters:**

1. Any type.

**Return:**

* Integer `-1` if object of class `List` is lesser than method parameter.
* Integer `1` if object of class `List` is greater than method parameter.
* Integer `0` if object of class `List` is equal to method parameter.

**Example:**

```cpp
obj_0 = new List([1,2,3,4,5]);
obj_1 = new List([1,2,6,7,8]);
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

### Method `spec` [`item#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_list.cc#L1138)

Retrieve element from object of class `List` stored at requested index position.

**Parameters:**

1. Type convertible to integer.

**Return:**

* Object representing element in object of class `List` at position of requested index.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = new List([1,2,3,4,5]);
("obj: %s\n" % obj.to_string()).print();
idx = obj.first_idx();
do {
  ("obj.item(%d): %s\n" % [idx,obj.item(idx).to_string()]).print();
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

### Method `spec` [`first_idx#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_list.cc#L1145)

Retrieve index of first element in object of class `List`.

**Return:**

* Object of class `Integer` if object of class `List` contains some elements.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = new List([1,2,3,4,5]);
("obj.first_idx: %s\n" % obj.first_idx().to_string()).print();
obj.clear();
("obj.first_idx: %s\n" % obj.first_idx().to_string()).print();
```
```
obj.first_idx: 0
obj.first_idx: <blank>
```

<a name="last_idx#0" />

### Method `spec` [`last_idx#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_list.cc#L1158)

Retrieve index of last element in object of class `List`.

**Return:**

* Object of class `Integer` if object of class `List` contains some elements.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = new List([1,2,3,4,5]);
("obj.last_idx: %s\n" % obj.last_idx().to_string()).print();
obj.clear();
("obj.last_idx: %s\n" % obj.last_idx().to_string()).print();
```
```
obj.last_idx: 4
obj.last_idx: <blank>
```

<a name="next_idx#1" />

### Method `spec` [`next_idx#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_list.cc#L1171)

From object of class `List` retrieve index of element following element identified by method parameter.

**Parameters:**

1. Type convertible to integer.

**Return:**

* Object of class `Integer` if there is some element following element identified by method parameter.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = new List([1,2,3,4,5]);
("obj: %s\n" % obj.to_string()).print();
idx = obj.first_idx();
do {
  ("idx: %s\n" % idx.to_string()).print();
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

### Method `spec` [`prev_idx#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_list.cc#L1200)

From object of class `List` retrieve index of element preceding element identified by method parameter.

**Parameters:**

1. Type convertible to integer.

**Return:**

* Object of class `Integer` if there is some element preceding element identified by method parameter.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = new List([1,2,3,4,5]);
("obj: %s\n" % obj.to_string()).print();
idx = obj.last_idx();
do {
  ("idx: %s\n" % idx.to_string()).print();
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

### Method `spec` [`length#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_list.cc#L1229)

Retrieve count of elements in object of class `List`.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
obj = new List([1,2,3,4,5]);
("obj.length(): %d\n" % obj.length()).print();
obj.clear();
("obj.length(): %d\n" % obj.length()).print();
```
```
obj.length(): 5
obj.length(): 0
```

<a name="to_string#0" />

### Method `spec` [`to_string#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_list.cc#L1242)

Convert object of class `List` to object of class `String`.
Each element of object of class `List` is converted to string by call of its
`to_string#0` method. As separator of string values is used character `,`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
obj = new List([1,2,3,4,5]);
("obj.to_string(): %s\n" % obj.to_string()).print();
```
```
obj.to_string(): [1,2,3,4,5]
```

<a name="to_string#1" />

### Method [`to_string#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_list.cc#L1284)

Convert object of class `List` to object of class `String`.
Each element of object of class `List` is converted to string by call of its
`to_string#0` method. As separator of string values is used method parameter.

**Parameters:**

1. Object of class `String`. Separator of values formated to result string.

**Return:**

* Object of class `String`.

**Example:**

```cpp
obj = new List([1,2,3,4,5]);
("obj.to_string(\"+\"): %s\n" % obj.to_string("+")).print();
("obj.to_string(\"<->\"): %s\n" % obj.to_string("<->")).print();
```
```
obj.to_string("+"): 1+2+3+4+5
obj.to_string("<->"): 1<->2<->3<->4<->5
```

<a name="print#0" />

### Method `spec` [`print#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_list.cc#L1339)

Print string representation of object of class `List` to standard output.
Each element of object of class `List` is printed by call of its `print#0`
method. As separator of printed values is used character `,`.

**Return:**

* Object of class `Blank`.

**Example:**

```cpp
obj = new List([1,2,3,4,5]);
obj.print();
"\n".print();
```
```
[1,2,3,4,5]
```
