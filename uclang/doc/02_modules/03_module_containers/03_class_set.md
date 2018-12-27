# Class Set

Container class implementing abstract data type set.

-----

## Table of methods

* Constructors

  * Constructor [`Set#0`](#Set%230)
  * Constructor [`Set#1`](#Set%231)

* Operators

  * Operator [`operator_binary_equal#1`](#operator_binary_equal%231)
  * Operator [`operator_binary_plus_equal#1`](#operator_binary_plus_equal%231)
  * Operator [`operator_binary_minus_equal#1`](#operator_binary_minus_equal%231)
  * Operator [`operator_binary_ampersand_equal#1`](#operator_binary_ampersand_equal%231)
  * Operator [`operator_binary_pipe_equal#1`](#operator_binary_pipe_equal%231)
  * Operator [`operator_binary_circumflex_equal#1`](#operator_binary_circumflex_equal%231)
  * Operator [`operator_binary_ampersand#1`](#operator_binary_ampersand%231)
  * Operator [`operator_binary_pipe#1`](#operator_binary_pipe%231)
  * Operator [`operator_binary_circumflex#1`](#operator_binary_circumflex%231)
  * Operator [`operator_binary_double_equal#1`](#operator_binary_double_equal%231)
  * Operator [`operator_binary_exclamation_equal#1`](#operator_binary_exclamation_equal%231)
  * Operator [`operator_binary_rs_br_equal#1`](#operator_binary_rs_br_equal%231)
  * Operator [`operator_binary_ls_br_equal#1`](#operator_binary_ls_br_equal%231)
  * Operator [`operator_binary_plus#1`](#operator_binary_plus%231)
  * Operator [`operator_binary_minus#1`](#operator_binary_minus%231)
  * Operator [`operator_binary_le_br_re_br#1`](#operator_binary_le_br_re_br%231)

* Methods

  * Method [`clear#0`](#clear%230)
  * Method [`items#0`](#items%230)
  * Method [`insert#1`](#insert%231)
  * Method [`remove#1`](#remove%231)
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

<a name="Set#0" />

### Constructor [`Set#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_set.cc#L1198)

Creates default object of class `Set`.

**Example:**

```cpp
obj = new Set();
("obj: %s\n" % $obj).print();
```
```
obj: []
```

<a name="Set#1" />

### Constructor [`Set#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_set.cc#L1203)

Creates object of class `Set` containing elements retrieved from method parameter.

**Parameters:**

1. Iterable type.

**Example:**

```cpp
obj = new Set([1,2,3,4,5]);
("obj: %s\n" % $obj).print();
```
```
obj: [1,2,3,4,5]
```

-----

## Operators

<a name="operator_binary_equal#1" />

### Operator [`operator_binary_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_set.cc#L826)

Assignment operator `=`. Object of class `Set` is replaced by method parameter.

**Parameters:**

1. Any type.

**Return:**

* Method parameter.

**Example:**

```cpp
obj = new Set([1,2,3,4,5]);
("obj: %s\n" % $obj).print();
obj = "New value";
("obj: %s\n" % $obj).print();
```
```
obj: [1,2,3,4,5]
obj: New value
```

<a name="operator_binary_plus_equal#1" />

### Operator [`operator_binary_plus_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_set.cc#L838)

Append operator `+=`. Append elements retrieved from method parameter to object of class `Set`.

**Parameters:**

1. Iterable type.

**Return:**

* Value of object.

**Example:**

```cpp
obj = new Set([1,2,3,4,5]);
("obj: %s\n" % $obj).print();
obj += [1,2,6,7,8];
("obj: %s\n" % $obj).print();
```
```
obj: [1,2,3,4,5]
obj: [1,2,3,4,5,6,7,8]
```

<a name="operator_binary_minus_equal#1" />

### Operator [`operator_binary_minus_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_set.cc#L866)

Set difference operator `-=`. Creates object of class `Set` containing
elements from first object of class `Set` that are not contained in second
object of class `Set`. Value of variable is set to result object of class
`Set`.

**Parameters:**

1. Object of class `Set`.

**Return:**

* Value of object.

**Example:**

```cpp
obj_0 = new Set([1,2,3,4,5]);
obj_1 = new Set([1,2,6,7,8]);
obj_0 -= obj_1;
("obj_0: %s\n" % $obj_0).print();
```
```
obj_0: [3,4,5]
```

<a name="operator_binary_ampersand_equal#1" />

### Operator [`operator_binary_ampersand_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_set.cc#L895)

Set intersection operator `&=`. Creates object of class `Set` containing
elements contained in both source objects of class `Set`. Value of variable is
set to result object of class `Set`.

**Parameters:**

1. Object of class `Set`.

**Return:**

* Value of object.

**Example:**

```cpp
obj_0 = new Set([1,2,3,4,5]);
obj_1 = new Set([1,2,6,7,8]);
obj_0 &= obj_1;
("obj_0: %s\n" % $obj_0).print();
```
```
obj_0: [1,2]
```

<a name="operator_binary_pipe_equal#1" />

### Operator [`operator_binary_pipe_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_set.cc#L924)

Set union operator `|=`. Creates object of class `Set` containing elements
from both source objects of class `Set`. Value of variable is set to result
object of class `Set`.

**Parameters:**

1. Object of class `Set`.

**Return:**

* Value of object.

**Example:**

```cpp
obj_0 = new Set([1,2,3,4,5]);
obj_1 = new Set([1,2,6,7,8]);
obj_0 |= obj_1;
("obj_0: %s\n" % $obj_0).print();
```
```
obj_0: [1,2,3,4,5,6,7,8]
```

<a name="operator_binary_circumflex_equal#1" />

### Operator [`operator_binary_circumflex_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_set.cc#L953)

Set symmetric difference operator `^=`. Creates object of class `Set`
containing elements from both source objects of class `Set` that are contained
exactly in one of them. Value of variable is set to result object of class
`Set`.

**Parameters:**

1. Object of class `Set`.

**Return:**

* Value of object.

**Example:**

```cpp
obj_0 = new Set([1,2,3,4,5]);
obj_1 = new Set([1,2,6,7,8]);
obj_0 ^= obj_1;
("obj_0: %s\n" % $obj_0).print();
```
```
obj_0: [3,4,5,6,7,8]
```

<a name="operator_binary_ampersand#1" />

### Operator [`operator_binary_ampersand#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_set.cc#L982)

Set intersection operator `&`. Creates object of class `Set` containing
elements contained in both source objects of class `Set`.

**Parameters:**

1. Object of class `Set`.

**Return:**

* Object of class `Set`.

**Example:**

```cpp
obj_0 = new Set([1,2,3,4,5]);
obj_1 = new Set([1,2,6,7,8]);
res = obj_0 & obj_1;
("res: %s\n" % $res).print();
```
```
res: [1,2]
```

<a name="operator_binary_pipe#1" />

### Operator [`operator_binary_pipe#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_set.cc#L1008)

Set union operator `|`. Creates object of class `Set` containing elements from
both source objects of class `Set`.

**Parameters:**

1. Object of class `Set`.

**Return:**

* Object of class `Set`.

**Example:**

```cpp
obj_0 = new Set([1,2,3,4,5]);
obj_1 = new Set([1,2,6,7,8]);
res = obj_0 | obj_1;
("res: %s\n" % $res).print();
```
```
res: [1,2,3,4,5,6,7,8]
```

<a name="operator_binary_circumflex#1" />

### Operator [`operator_binary_circumflex#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_set.cc#L1034)

Set symmetric difference operator `^`. Creates object of class `Set`
containing elements from both source objects of class `Set` that are contained
exactly in one of them.

**Parameters:**

1. Object of class `Set`.

**Return:**

* Object of class `Set`.

**Example:**

```cpp
obj_0 = new Set([1,2,3,4,5]);
obj_1 = new Set([1,2,6,7,8]);
res = obj_0 ^ obj_1;
("res: %s\n" % $res).print();
```
```
res: [3,4,5,6,7,8]
```

<a name="operator_binary_double_equal#1" />

### Operator [`operator_binary_double_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_set.cc#L1060)

Comparison operator `==`. Compares object of class `Set` with method parameter and return `1` if objects has same value or `0` otherwise.

**Parameters:**

1. Any type.

**Return:**

* Object of class `Integer`.
  * `0` - method parameter has different value than object.
  * `1` - method parameter has same value as object.

**Example:**

```cpp
obj_0 = new Set([1,2,3,4,5]);
obj_1 = new Set([1,2,6,7,8]);
obj_2 = obj_0;
("obj_0 == obj_1: %d\n" % (obj_0 == obj_1)).print();
("obj_0 == obj_2: %d\n" % (obj_0 == obj_2)).print();
```
```
obj_0 == obj_1: 0
obj_0 == obj_2: 1
```

<a name="operator_binary_exclamation_equal#1" />

### Operator [`operator_binary_exclamation_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_set.cc#L1075)

Comparison operator `!=`. Compares object of class `Set` with method parameter and return `0` if objects has same value or `1` otherwise.

**Parameters:**

1. Any type.

**Return:**

* Object of class `Integer`.
  * `0` - method parameter has same value as object.
  * `1` - method parameter has different value than object.

**Example:**

```cpp
obj_0 = new Set([1,2,3,4,5]);
obj_1 = new Set([1,2,6,7,8]);
obj_2 = obj_0;
("obj_0 != obj_1: %d\n" % (obj_0 != obj_1)).print();
("obj_0 != obj_2: %d\n" % (obj_0 != obj_2)).print();
```
```
obj_0 != obj_1: 1
obj_0 != obj_2: 0
```

<a name="operator_binary_rs_br_equal#1" />

### Operator [`operator_binary_rs_br_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_set.cc#L1090)

Subset test operator `>=`. Test if object of class `Set` given by method
parameter is subset of object of class `Set`.

**Parameters:**

1. Object of class `Set`.

**Return:**

* Object of class `Integer`.
  * `0` - method parameter is not subset of object.
  * `1` - method parameter is subset of object.

**Example:**

```cpp
obj_0 = new Set([1,2,3,4,5]);
obj_1 = new Set(obj_0[0:2:]);
("obj_0: %s\n" % $obj_0).print();
("obj_1: %s\n" % $obj_1).print();
("obj_0 >= obj_1: %d\n" % (obj_0 >= obj_1)).print();
("obj_1 >= obj_0: %d\n" % (obj_1 >= obj_0)).print();
```
```
obj_0: [1,2,3,4,5]
obj_1: [1,2,3]
obj_0 >= obj_1: 1
obj_1 >= obj_0: 0
```

<a name="operator_binary_ls_br_equal#1" />

### Operator [`operator_binary_ls_br_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_set.cc#L1112)

Superset test operator `<=`. Test if object of class `Set` given by method
parameter is superset of object of class `Set`.

**Parameters:**

1. Object of class `Set`.

**Return:**

* Object of class `Integer`.
  * `0` - method parameter is not superset of object.
  * `1` - method parameter is superset of object.

**Example:**

```cpp
obj_0 = new Set([1,2,3,4,5]);
obj_1 = new Set(obj_0[0:2:]);
("obj_0: %s\n" % $obj_0).print();
("obj_1: %s\n" % $obj_1).print();
("obj_0 <= obj_1: %d\n" % (obj_0 <= obj_1)).print();
("obj_1 <= obj_0: %d\n" % (obj_1 <= obj_0)).print();
```
```
obj_0: [1,2,3,4,5]
obj_1: [1,2,3]
obj_0 <= obj_1: 0
obj_1 <= obj_0: 1
```

<a name="operator_binary_plus#1" />

### Operator [`operator_binary_plus#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_set.cc#L1134)

Concatenation operator `+`. Creates object of class `Set` containing elements of original object of class `Set` concatenated with elements retrieved from method parameter.

**Parameters:**

1. Iterable type.

**Return:**

* Object of class `Set` containing elements of original object of class `Set` concatenated with elements retrieved from method parameter.

**Example:**

```cpp
obj = new Set([1,2,3,4,5]);
res = obj + [1,2,3,4,5];
("obj: %s\n" % $obj).print();
("res: %s\n" % $res).print();
```
```
obj: [1,2,3,4,5]
res: [1,2,3,4,5]
```

<a name="operator_binary_minus#1" />

### Operator [`operator_binary_minus#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_set.cc#L1167)

Set difference operator `-`. Creates object of class `Set` containing elements
from first object of class `Set` that are not contained in second object of
class `Set`.

**Parameters:**

1. Object of class `Set`.

**Return:**

* Object of class `Set`.

**Example:**

```cpp
obj_0 = new Set([1,2,3,4,5]);
obj_1 = new Set([1,2,6,7,8]);
res = obj_0 - obj_1;
("res: %s\n" % $res).print();
```
```
res: [3,4,5]
```

<a name="operator_binary_le_br_re_br#1" />

### Operator [`operator_binary_le_br_re_br#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_set.cc#L1193)

Item selection operator `[]`.
Retrieve element from object of class `Set` stored at requested index position.

**Parameters:**

1. Type convertible to integer.

**Return:**

 * Object stored in object of class `Set` at position of requested index.

**Example:**

```cpp
obj = new Set([1,2,3,4,5]);
("obj: %s\n" % $obj).print();
("obj[0]: %s\n" % $obj[0]).print();
("obj[2]: %s\n" % $obj[2]).print();
("obj[3]: %s\n" % $obj[3]).print();
```
```
obj: [1,2,3,4,5]
obj[0]: 1
obj[2]: 2
obj[3]: 3
```

-----

## Methods

<a name="clear#0" />

### Method [`clear#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_set.cc#L1227)

Release all elements stored in object of class `Set`.

**Return:**

* Object of class `Set`.

**Example:**

```cpp
obj = new Set([1,2,3,4,5]);
("obj: %s\n" % $obj).print();
obj.clear();
("obj: %s\n" % $obj).print();
```
```
obj: [1,2,3,4,5]
obj: []
```

<a name="items#0" />

### Method [`items#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_set.cc#L1255)

Retrieve list of elements contained in object of class `Set`. Elements are returned as object of class `Array`.

**Return:**

* Object of class `Array` containing all elements.

**Example:**

```cpp
obj = new Set([1,2,3,4,5]);
("obj: %s\n" % $obj).print();
items = obj.items();
("type items: %s\n" % $(type items)).print();
("items: %s\n" % $items).print();
```
```
obj: [1,2,3,4,5]
type items: Array
items: [1,2,3,4,5]
```

<a name="insert#1" />

### Method [`insert#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_set.cc#L1286)

Insert method parameter to object of class `Set`.

**Parameters:**

1. Any type.

**Return:**

* Object of class `Set`.

**Example:**

```cpp
obj = new Set([1,2,3,4,5]);
("obj: %s\n" % $obj).print();
obj.insert(5);
obj.insert(6);
obj.insert(7);
("obj: %s\n" % $obj).print();
```
```
obj: [1,2,3,4,5]
obj: [1,2,3,4,5,6,7]
```

<a name="remove#1" />

### Method [`remove#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_set.cc#L1310)

From object of class `Set` remove elements with value equal to value of method
parameter.

**Parameters:**

1. Any type.

**Return:**

* Object of class `Blank`.

**Example:**

```cpp
obj = new Set([1,2,3,4,5]);
("obj: %s\n" % $obj).print();
obj.remove(2);
obj.remove(4);
("obj: %s\n" % $obj).print();
```
```
obj: [1,2,3,4,5]
obj: [1,3,5]
```

<a name="contain#1" />

### Method [`contain#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_set.cc#L1342)

Test if object of class `Set` contains element with same value as object given by method parameter.

**Parameters:**

1. Any type.

**Return:**

Object of class ``Integer``.
  * `0` - object of class `Set` does not contain element equal to method parameter.
  * `1` - object of class `Set` does contain element equal to method parameter.

**Example:**

```cpp
obj = new Set([1,2,3,4,5]);
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

### Method `spec` [`compare#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_set.cc#L1365)

Compare object of class `Set` with method parameter.

**Parameters:**

1. Any type.

**Return:**

* Integer `-1` if object of class `Set` is lesser than method parameter.
* Integer `1` if object of class `Set` is greater than method parameter.
* Integer `0` if object of class `Set` is equal to method parameter.

**Example:**

```cpp
obj_0 = new Set([1,2,3,4,5]);
obj_1 = new Set([1,2,6,7,8]);
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

### Method `spec` [`item#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_set.cc#L1379)

Retrieve element from object of class `Set` stored at requested index position.

**Parameters:**

1. Type convertible to integer.

**Return:**

* Object representing element in object of class `Set` at position of requested index.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = new Set([1,2,3,4,5]);
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
obj.item(2): 2
obj.item(3): 3
obj.item(4): 4
obj.item(5): 5
```

<a name="first_idx#0" />

### Method `spec` [`first_idx#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_set.cc#L1384)

Retrieve index of first element in object of class `Set`.

**Return:**

* Object of class `Integer` if object of class `Set` contains some elements.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = new Set([1,2,3,4,5]);
("obj.first_idx: %s\n" % $obj.first_idx()).print();
obj.clear();
("obj.first_idx: %s\n" % $obj.first_idx()).print();
```
```
obj.first_idx: 0
obj.first_idx: <blank>
```

<a name="last_idx#0" />

### Method `spec` [`last_idx#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_set.cc#L1404)

Retrieve index of last element in object of class `Set`.

**Return:**

* Object of class `Integer` if object of class `Set` contains some elements.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = new Set([1,2,3,4,5]);
("obj.last_idx: %s\n" % $obj.last_idx()).print();
obj.clear();
("obj.last_idx: %s\n" % $obj.last_idx()).print();
```
```
obj.last_idx: 5
obj.last_idx: <blank>
```

<a name="next_idx#1" />

### Method `spec` [`next_idx#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_set.cc#L1424)

From object of class `Set` retrieve index of element following element identified by method parameter.

**Parameters:**

1. Type convertible to integer.

**Return:**

* Object of class `Integer` if there is some element following element identified by method parameter.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = new Set([1,2,3,4,5]);
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
idx: 2
idx: 3
idx: 4
idx: 5
```

<a name="prev_idx#1" />

### Method `spec` [`prev_idx#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_set.cc#L1442)

From object of class `Set` retrieve index of element preceding element identified by method parameter.

**Parameters:**

1. Type convertible to integer.

**Return:**

* Object of class `Integer` if there is some element preceding element identified by method parameter.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = new Set([1,2,3,4,5]);
("obj: %s\n" % $obj).print();
idx = obj.last_idx();
do {
  ("idx: %s\n" % $idx).print();
  idx = obj.prev_idx(idx);
} while(Blank != idx);
```
```
obj: [1,2,3,4,5]
idx: 5
idx: 4
idx: 3
idx: 2
idx: 0
```

<a name="length#0" />

### Method `spec` [`length#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_set.cc#L1460)

Retrieve count of elements in object of class `Set`.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
obj = new Set([1,2,3,4,5]);
("obj.length(): %d\n" % obj.length()).print();
obj.clear();
("obj.length(): %d\n" % obj.length()).print();
```
```
obj.length(): 5
obj.length(): 0
```

<a name="to_string#0" />

### Method `spec` [`to_string#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_set.cc#L1471)

Convert object of class `Set` to object of class `String`.
Each element of object of class `Set` is converted to string by call of its
`to_string#0` method. As separator of string values is used character `,`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
obj = new Set([1,2,3,4,5]);
("obj.to_string(): %s\n" % obj.to_string()).print();
```
```
obj.to_string(): [1,2,3,4,5]
```

<a name="to_string#1" />

### Method [`to_string#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_set.cc#L1514)

Convert object of class `Set` to object of class `String`.
Each element of object of class `Set` is converted to string by call of its
`to_string#0` method. As separator of string values is used method parameter.

**Parameters:**

1. Object of class `String`. Separator of values formated to result string.

**Return:**

* Object of class `String`.

**Example:**

```cpp
obj = new Set([1,2,3,4,5]);
("obj.to_string(\"+\"): %s\n" % obj.to_string("+")).print();
("obj.to_string(\"<->\"): %s\n" % obj.to_string("<->")).print();
```
```
obj.to_string("+"): 1+2+3+4+5
obj.to_string("<->"): 1<->2<->3<->4<->5
```

<a name="print#0" />

### Method `spec` [`print#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_set.cc#L1563)

Print string representation of object of class `Set` to standard output.
Each element of object of class `Set` is printed by call of its `print#0`
method. As separator of printed values is used character `,`.

**Return:**

* Object of class `Set`.

**Example:**

```cpp
obj = new Set([1,2,3,4,5]);
obj.print();
"\n".print();
```
```
[1,2,3,4,5]
```
