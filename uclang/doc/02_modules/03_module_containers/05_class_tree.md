
# Class Tree
Container class implementing simple abstract data type tree.

## Constructors

#### Constructor `Tree#0`
Creates empty object of class `Tree`.

**Example:**

```cpp
tree = new Tree();
("tree: %s\n" % tree.to_string()).print();
```
```
tree: []
```

#### Constructor `Tree#1`
Creates object of class `Tree` containing elements retrieved from method parameter.

**Parameters:**

1. Iterable type.

**Example:**

```cpp
tree = new Tree([1,2,3]);
("tree: %s\n" % tree.to_string()).print();
```
```
tree: [1,2,3]
```

## Operators

#### Operator `operator_binary_equal#1`
Assignment operator `=`. Object of class `Tree` is replaced by method
parameter.

**Parameters:**

1. Any type.

**Return:**

Value of object.

**Example:**

```cpp
tree = new Tree();
("tree: %s\n" % tree.to_string()).print();
tree = "Hello world";
("tree: %s\n" % tree.to_string()).print();
```
```
tree: []
tree: Hello world
```

#### Operator `operator_binary_plus_equal#1`
Append operator `+=`. Insert elements retrieved from method parameter to object
of class `Tree`.

**Parameters:**

1. Iterable type.

**Return:**

Value of object.

**Example:**

```cpp
tree = new Tree([1,2,3]);
tree += [3,4,5];
("tree: %s\n" % tree.to_string()).print();
```
```
tree: [1,2,3,3,4,5]
```

#### Operator `operator_binary_double_equal#1`
Comparison operator `==`. Compares object of class `Tree` with method
parameter and return `1` if objects has same value or `0` otherwise.

**Parameters:**

1. Any type.

**Return:**

Object of class `Integer`.
  * `0` - method parameter has different value than object.
  * `1` - method parameter has same value as object.

**Example:**

```cpp
tree_0 = new Tree([1,2,3]);
tree_1 = new Tree([1,2,4]);
tree_2 = tree_0;
("tree_0 == tree_1: %d\n" % (tree_0 == tree_1)).print();
("tree_0 == tree_2: %d\n" % (tree_0 == tree_2)).print();
```
```
tree_0 == tree_1: 0
tree_0 == tree_2: 1
```

#### Operator `operator_binary_exclamation_equal#1`
Comparison operator `!=`. Compares object of class `Tree` with method parameter and
return `0` if objects has same value or `1` otherwise.

**Parameters:**

1. Any type.

**Return:**

Object of class `Integer`.
  * `0` - method parameter has same value as object.
  * `1` - method parameter has different value than object.

**Example:**

```cpp
tree_0 = new Tree([1,2,3]);
tree_1 = new Tree([1,2,4]);
tree_2 = tree_0;
("tree_0 != tree_1: %d\n" % (tree_0 != tree_1)).print();
("tree_0 != tree_2: %d\n" % (tree_0 != tree_2)).print();
```
```
tree_0 != tree_1: 1
tree_0 != tree_2: 0
```

#### Operator `operator_binary_plus#1`
Concatenation operator `+`. Creates object of class `Tree` containing elements
of original object of class `Tree` with inserted elements retrieved from
method parameter.

**Parameters:**

1. Iterable type.

**Return:**

Object of class `Tree` containing elements of original tree extended by
elements retrieved from method parameter.

**Example:**

```cpp
tree_0 = new Tree([1,2,3]);
tree_1 = new Tree([1,2,4]);
("tree_0 + tree_1: %s\n" % (tree_0 + tree_1).to_string()).print();
```
```
tree_0 + tree_1: [1,1,2,2,3,4]
```

#### Operator `operator_binary_le_br_re_br#1`
Item selection operator `[]`. Retrieve element from object of class `Tree`
stored at requested index position.

**Parameters:**

1. Type convertible to integer.

**Return:**

Object stored in object of class `Tree` at position of requested index.

**Example:**

```cpp
tree = new Tree([1,2,3]);
("tree: %s\n" % tree.to_string()).print();
("tree[1]: %d\n" % tree[1]).print();
("tree[2]: %d\n" % tree[2]).print();
```
```
tree: [1,2,3]
tree[2]: 2
tree[3]: 3
```

## Methods

#### Method `clear#0`
Empty tree. Release all elements stored in object of class `Tree`.

**Return:**

Object of class `Blank`.

**Example:**

```cpp
tree = new Tree([1,2,3]);
("tree: %s\n" % tree.to_string()).print();
tree.clear();
("tree: %s\n" % tree.to_string()).print();
```
```
tree: [1,2,3]
tree: []
```

#### Method `items#0`
Retrieve elements contained in object of class `Tree`. Elements are returned
as object of class `Array`.

**Return:**

Object of class `Array` containing all elements of tree.

**Example:**

```cpp
tree = new Tree([1,2,3]);
array = tree.items();
("type array: %s\n" % (type array).to_string()).print();
("array: %s\n" % array.to_string()).print();
```
```
type array: Array
array: [1,2,3]
```

#### Method `insert#1`
Insert method parameter to object of class `Tree`.

**Parameters:**

1. Any type.

**Return:**

Object of class `Blank`.

**Example:**

```cpp
tree = new Tree([1,2,3]);
("tree: %s\n" % tree.to_string()).print();
tree.insert(3);
tree.insert(4);
tree.insert(5);
("tree: %s\n" % tree.to_string()).print();
```
```
tree: [1,2,3]
tree: [1,2,3,3,4,5]
```

#### Method `remove#1`
Remove element given by method parameter from object of class `Tree`.

**Parameters:**

1. Any type.

**Return:**

Object of class `Blank`.

**Example:**

```cpp
tree = new Tree([1,2,3]);
("tree: %s\n" % tree.to_string()).print();
tree.remove(2);
("tree: %s\n" % tree.to_string()).print();
```
```
tree: [1,2,3]
tree: [1,3]
```

#### Method `get_idx#1`
Retrieve index of method parameter in object of class `Tree`.

**Parameters:**

1. Any type.

**Return:**

* Object of class `Integer`, if method parameter is contained as element in
  object of class `Tree`.
* Object of class `Blank` otherwise.

**Example:**

```cpp
tree = new Tree([1,2,3]);
("tree: %s\n" % tree.to_string()).print();
("tree.get_idx(3): %s\n" % tree.get_idx(3).to_string()).print();
("tree.get_idx(4): %s\n" % tree.get_idx(4).to_string()).print();
```
```
tree: [1,2,3]
tree.get_idx(3): 3
tree.get_idx(4): <blank>
```

#### Method `get_idxs#1`
Retrieve indexes of method parameter in object of class `Tree`. Element indexes
are returned as object of class `Array`.

**Parameters:**

1. Any type.

**Return:**

* Object of class `Array` containing indexes of elements of object of class
  `Tree` equal to method parameter.

**Example:**

```cpp
tree = new Tree([1,2,3,2,2]);
("tree: %s\n" % tree.to_string()).print();
("tree.get_idxs(2): %s\n" % tree.get_idxs(2).to_string()).print();
("tree.get_idxs(3): %s\n" % tree.get_idxs(3).to_string()).print();
("tree.get_idxs(4): %s\n" % tree.get_idxs(4).to_string()).print();
```
```
tree: [1,2,2,2,3]
tree.get_idxs(2): [2,5,4]
tree.get_idxs(3): [3]
tree.get_idxs(4): []
```

#### Method `compare#1`
Compare object of class `Tree` with method parameter.

**Parameters:**

1. Any type.

**Return:**

Object of class `Integer`.
* `-1` - if object of class `Tree` is lesser than method parameter.
* `1` - if object of class `Tree` is greater than method parameter.
* `0` - if object of class `Tree` is equal to method parameter.

**Example:**

```cpp
tree_0 = new Tree([1,2,3]);
tree_1 = new Tree([1,2,3,4]);
("tree_0.compare(tree_1): %d\n" % tree_0.compare(tree_1)).print();
("tree_0.compare(tree_0): %d\n" % tree_0.compare(tree_0)).print();
("tree_0.compare(0): %d\n" % tree_0.compare(0)).print();
```
```
tree_0.compare(tree_1): -1
tree_0.compare(tree_0): 0
tree_0.compare(0): 1
```

#### Method `item#1`
Retrieve element from object of class `Tree` stored at requested index position.

**Parameters:**

1. Type convertible to integer.

**Return:**

Object stored in object of class `Tree` at position of requested index.

**Example:**

```cpp
tree = new Tree([1,2,3]);
("tree: %s\n" % tree.to_string()).print();
("tree.item(2): %d\n" % tree.item(2)).print();
("tree.item(3): %d\n" % tree.item(3)).print();
```
```
tree: [1,2,3]
tree.item(2): 2
tree.item(3): 3
```

#### Method `first_idx#0`
Retrieve index of first element in object of class `Tree`.

**Return:**

* Object of class `Integer` if object of class `Tree` contains some elements.
* Object of class `Blank` otherwise.

**Example:**

```cpp
tree = new Tree([1]);
("tree.first_idx(): %s\n" % tree.first_idx().to_string()).print();
tree.remove(tree.get_idx(1));
("tree.first_idx(): %s\n" % tree.first_idx().to_string()).print();
```
```
tree.first_idx(): 0
tree.first_idx(): <blank>
```

#### Method `last_idx#0`
Retrieve index of last element in object of class `Tree`.

**Return:**

* Object of class `Integer` if object of class `Tree` contains some elements.
* Object of class `Blank` otherwise.

**Example:**

```cpp
tree = new Tree([1,2,3]);
("tree.last_idx(): %s\n" % tree.last_idx().to_string()).print();
tree.remove(tree.get_idx(3));
("tree.last_idx(): %s\n" % tree.last_idx().to_string()).print();
tree.clear();
("tree.last_idx(): %s\n" % tree.last_idx().to_string()).print();
```
```
tree.last_idx(): 3
tree.last_idx(): 2
tree.last_idx(): <blank>
```

#### Method `next_idx#1`
From object of class `Tree` retrieve index of element following element
identified by method parameter.

**Parameters:**

1. Type convertible to integer.

**Return:**

* Object of class `Integer` if there is some element following element
  identified by method parameter.
* Object of class `Blank` otherwise.

**Example:**

```cpp
tree = new Tree([1,2,3]);
("tree: %s\n" % tree.to_string()).print();
idx = tree.first_idx();
do {
  ("idx: %s\n" % idx.to_string()).print();
  idx = tree.next_idx(idx);
} while(Blank != idx);
```
```
tree: [1,2,3]
idx: 0
idx: 2
idx: 3
```

#### Method `prev_idx#1`
From object of class `Tree` retrieve index of element preceding element
identified by method parameter.

**Parameters:**

1. Type convertible to integer.

**Return:**

* Object of class `Integer` if there is some element preceding element
  identified by method parameter.
* Object of class `Blank` otherwise.

**Example:**

```cpp
tree = new Tree([1,2,3]);
("tree: %s\n" % tree.to_string()).print();
idx = tree.last_idx();
do {
  ("idx: %s\n" % idx.to_string()).print();
  idx = tree.prev_idx(idx);
} while(Blank != idx);
```
```
tree: [1,2,3]
idx: 3
idx: 2
idx: 0
```

#### Method `length#0`
Retrieve count of elements in object of class `Tree`.

**Return:**

Object of class `Integer`.

**Example:**

```cpp
tree = new Tree([1,2,3]);
("tree.length(): %d\n" % tree.length()).print();
tree.remove(tree.get_idx(2));
("tree.length(): %d\n" % tree.length()).print();
```
```
tree.length(): 3
tree.length(): 2
```

#### Method `to_string#0`
Convert object of class `Tree` to object of class `String`. Each element of
tree is converted to string by call of its `to_string#0` method. As separator
of string values of elements is used character `,`.

**Return:**

Object of class `String`.

**Example:**

```cpp
tree = new Tree([1,2,3]);
("tree: %s\n" % tree.to_string()).print();
```
```
tree: [1,2,3]
```

#### Method `to_string#1`
Convert object of class `Tree` to object of class `String`. Each element of
tree is converted to string by call of its `to_string#0` method. As separator
of string values is used method parameter.

**Parameters:**

1. Object of class `String`.

**Return:**

Object of class `String`.

**Example:**

```cpp
tree = new Tree([1,2,3,new Tree([1,2,3])]);
("tree: %s\n" % tree.to_string("+")).print();
("tree: %s\n" % tree.to_string("<->")).print();
```
```
tree: 1+2+3+[1,2,3]
tree: 1<->2<->3<->[1,2,3]
```

#### Method `print#0`
Print string representation of object of class `Tree` to standard output.

**Return:**

Object of class `Blank`.

**Example:**

```cpp
tree = new Tree([1,2,3]);
tree.print();
"\n".print();
```
```
[1,2,3]
```

