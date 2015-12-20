# Class Tree

Container class implementing abstract data type tree.

-----

## Table of methods

* Constructors

  * Constructor [`Tree#0`](#Tree%230)
  * Constructor [`Tree#1`](#Tree%231)

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
  * Method [`insert#1`](#insert%231)
  * Method [`remove#1`](#remove%231)
  * Method [`get_idx#1`](#get_idx%231)
  * Method [`get_idxs#1`](#get_idxs%231)
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

<a name="Tree#0" />

### Constructor [`Tree#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_tree.cc#L664)

Creates default object of class `Tree`.

**Example:**

```cpp
obj = new Tree();
("obj: %s\n" % obj.to_string()).print();
```
```
obj: []
```

<a name="Tree#1" />

### Constructor [`Tree#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_tree.cc#L669)

Creates object of class `Tree` containing elements retrieved from method parameter.

**Parameters:**

1. Iterable type.

**Example:**

```cpp
obj = new Tree([1,2,3,4,5]);
("obj: %s\n" % obj.to_string()).print();
```
```
obj: [1,2,3,4,5]
```

-----

## Operators

<a name="operator_binary_equal#1" />

### Operator [`operator_binary_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_tree.cc#L541)

Assignment operator `=`. Object of class `Tree` is replaced by method parameter.

**Parameters:**

1. Any type.

**Return:**

* Method parameter.

**Example:**

```cpp
obj = new Tree([1,2,3,4,5]);
("obj: %s\n" % obj.to_string()).print();
obj = "New value";
("obj: %s\n" % obj.to_string()).print();
```
```
obj: [1,2,3,4,5]
obj: New value
```

<a name="operator_binary_plus_equal#1" />

### Operator [`operator_binary_plus_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_tree.cc#L557)

Append operator `+=`. Append elements retrieved from method parameter to object of class `Tree`.

**Parameters:**

1. Iterable type.

**Return:**

* Value of object.

**Example:**

```cpp
obj = new Tree([1,2,3,4,5]);
("obj: %s\n" % obj.to_string()).print();
obj += [1,2,6,7,8];
("obj: %s\n" % obj.to_string()).print();
```
```
obj: [1,2,3,4,5]
obj: [1,1,2,2,3,4,5,6,7,8]
```

<a name="operator_binary_double_equal#1" />

### Operator [`operator_binary_double_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_tree.cc#L587)

Comparison operator `==`. Compares object of class `Tree` with method parameter and return `1` if objects has same value or `0` otherwise.

**Parameters:**

1. Any type.

**Return:**

* Object of class `Integer`.
  * `0` - method parameter has different value than object.
  * `1` - method parameter has same value as object.

**Example:**

```cpp
obj_0 = new Tree([1,2,3,4,5]);
obj_1 = new Tree([1,2,6,7,8]);
obj_2 = obj_0;
("obj_0 == obj_1: %d\n" % (obj_0 == obj_1)).print();
("obj_0 == obj_2: %d\n" % (obj_0 == obj_2)).print();
```
```
obj_0 == obj_1: 0
obj_0 == obj_2: 1
```

<a name="operator_binary_exclamation_equal#1" />

### Operator [`operator_binary_exclamation_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_tree.cc#L604)

Comparison operator `!=`. Compares object of class `Tree` with method parameter and return `0` if objects has same value or `1` otherwise.

**Parameters:**

1. Any type.

**Return:**

* Object of class `Integer`.
  * `0` - method parameter has same value as object.
  * `1` - method parameter has different value than object.

**Example:**

```cpp
obj_0 = new Tree([1,2,3,4,5]);
obj_1 = new Tree([1,2,6,7,8]);
obj_2 = obj_0;
("obj_0 != obj_1: %d\n" % (obj_0 != obj_1)).print();
("obj_0 != obj_2: %d\n" % (obj_0 != obj_2)).print();
```
```
obj_0 != obj_1: 1
obj_0 != obj_2: 0
```

<a name="operator_binary_plus#1" />

### Operator [`operator_binary_plus#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_tree.cc#L621)

Concatenation operator `+`. Creates object of class `Tree` containing elements of original object of class `Tree` concatenated with elements retrieved from method parameter.

**Parameters:**

1. Iterable type.

**Return:**

* Object of class `Tree` containing elements of original object of class `Tree` concatenated with elements retrieved from method parameter.

**Example:**

```cpp
obj = new Tree([1,2,3,4,5]);
res = obj + [1,2,3,4,5];
("obj: %s\n" % obj.to_string()).print();
("res: %s\n" % res.to_string()).print();
```
```
obj: [1,2,3,4,5]
res: [1,1,2,2,3,3,4,4,5,5]
```

<a name="operator_binary_le_br_re_br#1" />

### Operator [`operator_binary_le_br_re_br#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_tree.cc#L657)

Item selection operator `[]`.
Retrieve element from object of class `Tree` stored at requested index position.

**Parameters:**

1. Type convertible to integer.

**Return:**

 * Object stored in object of class `Tree` at position of requested index.

**Example:**

```cpp
obj = new Tree([1,2,3,4,5]);
("obj: %s\n" % obj.to_string()).print();
("obj[0]: %s\n" % obj[0].to_string()).print();
("obj[2]: %s\n" % obj[2].to_string()).print();
("obj[3]: %s\n" % obj[3].to_string()).print();
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

### Method [`clear#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_tree.cc#L693)

Release all elements stored in object of class `Tree`.

**Return:**

* Object of class `Blank`.

**Example:**

```cpp
obj = new Tree([1,2,3,4,5]);
("obj: %s\n" % obj.to_string()).print();
obj.clear();
("obj: %s\n" % obj.to_string()).print();
```
```
obj: [1,2,3,4,5]
obj: []
```

<a name="items#0" />

### Method [`items#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_tree.cc#L723)

Retrieve list of elements contained in object of class `Tree`. Elements are returned as object of class `Array`.

**Return:**

* Object of class `Array` containing all elements.

**Example:**

```cpp
obj = new Tree([1,2,3,4,5]);
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

<a name="insert#1" />

### Method [`insert#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_tree.cc#L757)

Insert method parameter to object of class `Tree`.

**Parameters:**

1. Any type.

**Return:**

* Object of class ``Blank``.

**Example:**

```cpp
obj = new Tree([1,2,3,4,5]);
("obj: %s\n" % obj.to_string()).print();
obj.insert(5);
obj.insert(6);
obj.insert(7);
("obj: %s\n" % obj.to_string()).print();
```
```
obj: [1,2,3,4,5]
obj: [1,2,3,4,5,5,6,7]
```

<a name="remove#1" />

### Method [`remove#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_tree.cc#L782)

Remove element from object of class `Tree` stored at position given by method parameter.

**Parameters:**

1. Type convertible to integer.

**Return:**

* Object of class ``Blank``.

**Example:**

```cpp
obj = new Tree([1,2,3,4,5]);
("obj: %s\n" % obj.to_string()).print();
obj.remove(0);
obj.remove(2);
("obj: %s\n" % obj.to_string()).print();
```
```
obj: [1,2,3,4,5]
obj: [3,4,5]
```

<a name="get_idx#1" />

### Method [`get_idx#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_tree.cc#L812)

From object of class `Tree`, retrieve index of first element equal to method parameter.

**Parameters:**

1. Any type.

**Return:**

* Object of class ``Integer``, if method parameter is contained as element in object of class `Tree`.
* Object of class ``Blank`` otherwise.

**Example:**

```cpp
obj = new Tree([1,2,3,4,5]);
("obj: %s\n" % obj.to_string()).print();
("obj.get_idx(2): %s\n" % obj.get_idx(2).to_string()).print();
("obj.get_idx(100): %s\n" % obj.get_idx(100).to_string()).print();
```
```
obj: [1,2,3,4,5]
obj.get_idx(2): 2
obj.get_idx(100): <blank>
```

<a name="get_idxs#1" />

### Method [`get_idxs#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_tree.cc#L836)

From object of class `Tree`, retrieve indexes of elements that are equal to method parameter. Element indexes are returned as object of class ``Array``.

**Parameters:**

1. Any type.

**Return:**

* Object of class ``Array`` containing indexes of elements, that are equal to method parameter.

**Example:**

```cpp
obj = new Tree([1,2,2,4,2,5]);
("obj: %s\n" % obj.to_string()).print();
("obj.get_idxs(2): %s\n" % obj.get_idxs(2).to_string()).print();
("obj.get_idxs(100): %s\n" % obj.get_idxs(100).to_string()).print();
```
```
obj: [1,2,2,2,4,5]
obj.get_idxs(2): [2,5,3]
obj.get_idxs(100): []
```

<a name="compare#1" />

### Method `spec` [`compare#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_tree.cc#L876)

Compare object of class `Tree` with method parameter.

**Parameters:**

1. Any type.

**Return:**

* Integer `-1` if object of class `Tree` is lesser than method parameter.
* Integer `1` if object of class `Tree` is greater than method parameter.
* Integer `0` if object of class `Tree` is equal to method parameter.

**Example:**

```cpp
obj_0 = new Tree([1,2,3,4,5]);
obj_1 = new Tree([1,2,6,7,8]);
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

### Method `spec` [`item#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_tree.cc#L892)

Retrieve element from object of class `Tree` stored at requested index position.

**Parameters:**

1. Type convertible to integer.

**Return:**

* Object representing element in object of class `Tree` at position of requested index.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = new Tree([1,2,3,4,5]);
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
obj.item(2): 2
obj.item(3): 3
obj.item(4): 4
obj.item(5): 5
```

<a name="first_idx#0" />

### Method `spec` [`first_idx#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_tree.cc#L899)

Retrieve index of first element in object of class `Tree`.

**Return:**

* Object of class `Integer` if object of class `Tree` contains some elements.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = new Tree([1,2,3,4,5]);
("obj.first_idx: %s\n" % obj.first_idx().to_string()).print();
obj.clear();
("obj.first_idx: %s\n" % obj.first_idx().to_string()).print();
```
```
obj.first_idx: 0
obj.first_idx: <blank>
```

<a name="last_idx#0" />

### Method `spec` [`last_idx#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_tree.cc#L922)

Retrieve index of last element in object of class `Tree`.

**Return:**

* Object of class `Integer` if object of class `Tree` contains some elements.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = new Tree([1,2,3,4,5]);
("obj.last_idx: %s\n" % obj.last_idx().to_string()).print();
obj.clear();
("obj.last_idx: %s\n" % obj.last_idx().to_string()).print();
```
```
obj.last_idx: 5
obj.last_idx: <blank>
```

<a name="next_idx#1" />

### Method `spec` [`next_idx#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_tree.cc#L945)

From object of class `Tree` retrieve index of element following element identified by method parameter.

**Parameters:**

1. Type convertible to integer.

**Return:**

* Object of class `Integer` if there is some element following element identified by method parameter.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = new Tree([1,2,3,4,5]);
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
idx: 2
idx: 3
idx: 4
idx: 5
```

<a name="prev_idx#1" />

### Method `spec` [`prev_idx#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_tree.cc#L974)

From object of class `Tree` retrieve index of element preceding element identified by method parameter.

**Parameters:**

1. Type convertible to integer.

**Return:**

* Object of class `Integer` if there is some element preceding element identified by method parameter.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = new Tree([1,2,3,4,5]);
("obj: %s\n" % obj.to_string()).print();
idx = obj.last_idx();
do {
  ("idx: %s\n" % idx.to_string()).print();
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

### Method `spec` [`length#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_tree.cc#L1003)

Retrieve count of elements in object of class `Tree`.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
obj = new Tree([1,2,3,4,5]);
("obj.length(): %d\n" % obj.length()).print();
obj.clear();
("obj.length(): %d\n" % obj.length()).print();
```
```
obj.length(): 5
obj.length(): 0
```

<a name="to_string#0" />

### Method `spec` [`to_string#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_tree.cc#L1016)

Convert object of class `Tree` to object of class `String`.
Each element of object of class `Tree` is converted to string by call of its
`to_string#0` method. As separator of string values is used character `,`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
obj = new Tree([1,2,3,4,5]);
("obj.to_string(): %s\n" % obj.to_string()).print();
```
```
obj.to_string(): [1,2,3,4,5]
```

<a name="to_string#1" />

### Method [`to_string#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_tree.cc#L1061)

Convert object of class `Tree` to object of class `String`.
Each element of object of class `Tree` is converted to string by call of its
`to_string#0` method. As separator of string values is used method parameter.

**Parameters:**

1. Object of class `String`. Separator of values formated to result string.

**Return:**

* Object of class `String`.

**Example:**

```cpp
obj = new Tree([1,2,3,4,5]);
("obj.to_string(\"+\"): %s\n" % obj.to_string("+")).print();
("obj.to_string(\"<->\"): %s\n" % obj.to_string("<->")).print();
```
```
obj.to_string("+"): 1+2+3+4+5
obj.to_string("<->"): 1<->2<->3<->4<->5
```

<a name="print#0" />

### Method `spec` [`print#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_tree.cc#L1119)

Print string representation of object of class `Tree` to standard output.
Each element of object of class `Tree` is printed by call of its `print#0`
method. As separator of printed values is used character `,`.

**Return:**

* Object of class `Blank`.

**Example:**

```cpp
obj = new Tree([1,2,3,4,5]);
obj.print();
"\n".print();
```
```
[1,2,3,4,5]
```
