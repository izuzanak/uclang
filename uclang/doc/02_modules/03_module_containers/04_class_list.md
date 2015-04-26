
# class List
Container class implementing simple abstract data type list.

## Constructors

#### Method `List#0`
Creates empty object of class `List`.

##### Example:
```cpp
list = new List();
("list: %s\n" % list.to_string()).print();
```
```
list: []
```

#### Method `List#1`
Creates object of class `List` containing elements retrieved from method parameter.

##### Parameters:
1. Iterable type.

##### Example:
```cpp
list = new List([1,2,3]);
("list: %s\n" % list.to_string()).print();
```
```
list: [1,2,3]
```

## Operators

#### Operator `operator_binary_equal#1`,
Assignment operator `=`. Object of class `List` is replaced by method
parameter.

##### Parameters:
1. Any type.

##### Return:
Value of object.

##### Example:

```cpp
list = new List();
("list: %s\n" % list.to_string()).print();
list = "Hello world";
("list: %s\n" % list.to_string()).print();
```
```
list: []
list: Hello world
```

#### Operator `operator_binary_plus_equal#1`,
Append operator `+=`. Append elements retrieved from method parameter to object
of class `List`.

##### Parameters:
1. Iterable type.

##### Return:
Value of object.

##### Example:
```cpp
list = new List([1,2,3]);
list += [4,5,6];
("list: %s\n" % list.to_string()).print();
```
```
list: [1,2,3,4,5,6]
```

#### Operator `operator_binary_double_equal#1`,
Comparison operator `==`. Compares object of class `List` with method
parameter and return `1` if objects has same value or `0` otherwise.

##### Parameters:
1. Any type.

##### Return:
Object of class `Integer`.
  * `0` - method parameter has different value than object.
  * `1` - method parameter has same value as object.

##### Example:
```cpp
list_0 = new List([1,2,3]);
list_1 = new List([1,2,4]);
list_2 = list_0;
("list_0 == list_1: %d\n" % (list_0 == list_1)).print();
("list_0 == list_2: %d\n" % (list_0 == list_2)).print();
```
```
list_0 == list_1: 0
list_0 == list_2: 1
```

#### Operator `operator_binary_exclamation_equal#1`,
Comparison operator `!=`. Compares object of class `List` with method parameter and
return `0` if objects has same value or `1` otherwise.

##### Parameters:
1. Any type.

##### Return:
Object of class `Integer`.
  * `0` - method parameter has different value than object.
  * `1` - method parameter has same value as object.

##### Example:
```cpp
list_0 = new List([1,2,3]);
list_1 = new List([1,2,4]);
list_2 = list_0;
("list_0 != list_1: %d\n" % (list_0 != list_1)).print();
("list_0 != list_2: %d\n" % (list_0 != list_2)).print();
```
```
list_0 != list_1: 1
list_0 != list_2: 0
```

#### Operator `operator_binary_plus#1`,
Concatenation operator `+`. Creates object of class `List` containing elements
of original object of class `List` concatenated with elements retrieved from
method parameter.

##### Parameters:
1. Iterable type.

##### Return
Object of class `List` containing elements of original list concatenated with
elements retrieved from method parameter.

##### Example:
```cpp
list_0 = new List([1,2,3]);
list_1 = new List([1,2,4]);
("list_0 + list_1: %s\n" % (list_0 + list_1).to_string()).print();
```
```
list_0 + list_1: [1,2,3,1,2,4]
```

#### Operator `operator_binary_le_br_re_br#1`,
Item selection operator `[]`. Retrieve element from object of class `List`
stored at requested index position.

##### Parameters:
1. Type convertible to integer.

##### Return:
Object stored in object of class `List` at position of requested index.

##### Example:
```cpp
list = new List([1,2,3]);
("list: %s\n" % list.to_string()).print();
("list[1]: %d\n" % list[1]).print();
("list[2]: %d\n" % list[2]).print();
```
```
list: [1,2,3]
list[1]: 2
list[2]: 3
```

## Methods

#### Method `clear#0`
Empty list. Release all elements stored in object of class `List`.

##### Return:
object of class `Blank`.

##### Example:
```cpp
list = new List([1,2,3]);
("list: %s\n" % list.to_string()).print();
list.clear();
("list: %s\n" % list.to_string()).print();
```
```
list: [1,2,3]
list: []
```

#### Method `items#0`
Retrieve elements contained in object of class `List`. Elements are returned
as object of class `Array`.

##### Return:
Object of class `Array` containing all elements of list.

##### Example:
```cpp
list = new List([1,2,3]);
array = list.items();
("type array: %s\n" % (type array).to_string()).print();
("array: %s\n" % list.to_string()).print();
```
```
type array: Array
array: [1,2,3]
```

#### Method `append#1`
Append method parameter to end of object of class `List`.

##### Parameters:
1. Any type.

##### Return:
Object of class `Integer`. Index of appended element in object of class `List`.

##### Example:
```cpp
list = new List([1,2,3]);
("list: %s\n" % list.to_string()).print();
list.append(4);
list.append(5);
list.append(6);
("list: %s\n" % list.to_string()).print();
```
```
list: [1,2,3]
list: [1,2,3,4,5,6]
```

#### Method `append_ref#1`
Append reference to method parameter to end of object of class `List`.

##### Parameters:
1. Any type.

##### Return:
Object of class `Integer`. Index of appended element in object of class `List`.

##### Example:
```cpp
value = 10;
list = new List([1,2,3]);
("list: %s\n" % list.to_string()).print();
list.append_ref(value);
("list: %s\n" % list.to_string()).print();
value = 100;
("list: %s\n" % list.to_string()).print();
```
```
list: [1,2,3]
list: [1,2,3,10]
list: [1,2,3,100]
```

#### Method `prepend#1`
Prepend method parameter before begining of object of class `List`.

##### Parameters:
1. Any type.

##### Return:
Object of class `Integer`. Index of prepended element in object of class `List`.

##### Example:
```cpp
list = new List([1,2,3]);
("list: %s\n" % list.to_string()).print();
list.prepend(4);
list.prepend(5);
list.prepend(6);
("list: %s\n" % list.to_string()).print();
```
```
list: [1,2,3]
list: [6,5,4,1,2,3]
```

#### Method `prepend_ref#1`
Prepend reference to method parameter before begining of object of class
`List`.

##### Parameters:
1. Any type.

##### Return:
Object of class `Integer`. Index of prepended element in object of class `List`.

##### Example:
```cpp
value = 10;
list = new List([1,2,3]);
("list: %s\n" % list.to_string()).print();
list.prepend_ref(value);
("list: %s\n" % list.to_string()).print();
value = 100;
("list: %s\n" % list.to_string()).print();
```
```
list: [1,2,3]
list: [10,1,2,3]
list: [100,1,2,3]
```

#### Method `insert_before#2`
Insert second method parameter before element identified by first method
parameter to object of class `List`.

##### Parameters:
1. Type convertible to integer.
2. Any type.

##### Return:
Object of class `Integer`. Index of inserted element in object of class `List`.

##### Example:
```cpp
list = new List([1,2,3]);
idx = list.get_idx(2);
("list: %s\n" % list.to_string()).print();
list.insert_before(idx,4);
list.insert_before(idx,5);
list.insert_before(idx,6);
("list: %s\n" % list.to_string()).print();
```
```
list: [1,2,3]
list: [1,4,5,6,2,3]
```

#### Method `insert_before_ref#2`
Insert reference to second method parameter before element identified by first
method parameter to object of class `List`.

##### Parameters:
1. Type convertible to integer.
2. Any type.

##### Return:
Object of class `Integer`. Index of inserted element in object of class `List`.

##### Example:
```cpp
value = 10;
list = new List([1,2,3]);
("list: %s\n" % list.to_string()).print();
idx = list.get_idx(2);
list.insert_before_ref(idx,value);
("list: %s\n" % list.to_string()).print();
value = 100;
("list: %s\n" % list.to_string()).print();
```
```
list: [1,2,3]
list: [1,10,2,3]
list: [1,100,2,3]
```

#### Method `insert_after#2`
Insert second method parameter after element identified by first method
parameter to object of class `List`.

##### Parameters:
1. Type convertible to integer.
2. Any type.

##### Return:
Object of class `Integer`. Index of inserted element in object of class `List`.

##### Example:
```cpp
list = new List([1,2,3]);
idx = list.get_idx(2);
("list: %s\n" % list.to_string()).print();
list.insert_after(idx,4);
list.insert_after(idx,5);
list.insert_after(idx,6);
("list: %s\n" % list.to_string()).print();
```
```
list: [1,2,3]
list: [1,2,6,5,4,3]
```

#### Method `insert_after_ref#2`
Insert reference to second method parameter after element identified by first
method parameter to object of class `List`.

##### Parameters:
1. Type convertible to integer.
2. Any type.

##### Return:
Object of class `Integer`. Index of inserted element in object of class `List`.

##### Example:
```cpp
value = 10;
list = new List([1,2,3]);
("list: %s\n" % list.to_string()).print();
idx = list.get_idx(2);
list.insert_after_ref(idx,value);
("list: %s\n" % list.to_string()).print();
value = 100;
("list: %s\n" % list.to_string()).print();
```
```
list: [1,2,3]
list: [1,2,10,3]
list: [1,2,100,3]
```

#### Method `remove#1`
Remove element indetified by method parameter from object of class `List`.

##### Parameters:
1. Type convertible to integer.

##### Return:
Object of class `Blank`.

##### Example:
```cpp
list = new List([1,2,3]);
idx = list.get_idx(2);
("list: %s\n" % list.to_string()).print();
list.remove(idx);
("list: %s\n" % list.to_string()).print();
```
```
list: [1,2,3]
list: [1,3]
```

#### Method `has_idx#1`
Test if object of class `List` contain element with index given by method
parameter.

##### Parameters:
1. Type convertible to integer.

##### Return:
Object of class `Integer`.
* `1` - if object of class `List` contain element with given index.
* `0` - otherwise.

##### Example:
```cpp
list = new List([1,2,3]);
("list: %s\n" % list.to_string()).print();
("list.has_idx(3): %d\n" % list.has_idx(3)).print();
list.append(4);
("list.has_idx(3): %d\n" % list.has_idx(3)).print();
```
```
list: [1,2,3]
list.has_idx(3): 0
list.has_idx(3): 1
```

#### Method `get_idx#1`
Retrieve index of method parameter in object of class `List`.

##### Parameters:
1. Any type.

##### Return:
* Object of class `Integer`, if method parameter is contained as element in
  object of class `List`.
* Object of class `Blank` otherwise.

##### Example:
```cpp
list = new List([1,2,3]);
("list: %s\n" % list.to_string()).print();
("list.get_idx(3): %s\n" % list.get_idx(3).to_string()).print();
("list.get_idx(4): %s\n" % list.get_idx(4).to_string()).print();
```
```
list: [1,2,3]
list.get_idx(3): 2
list.get_idx(4): <blank>
```

#### Method `get_idxs#1`
Retrieve indexes of method parameter in object of class `List`. Element indexes
are returned as object of class `Array`.

##### Parameters:
1. Any type.

##### Return:
* Object of class `Array` containing indexes of elements of object of class
  `List` equal to method parameter.

##### Example:
```cpp
list = new List([1,2,3,2,2]);
("list: %s\n" % list.to_string()).print();
("list.get_idxs(2): %s\n" % list.get_idxs(2).to_string()).print();
("list.get_idxs(3): %s\n" % list.get_idxs(3).to_string()).print();
("list.get_idxs(4): %s\n" % list.get_idxs(4).to_string()).print();
```
```
list: [1,2,3,2,2]
list.get_idxs(2): [1,3,4]
list.get_idxs(3): [2]
list.get_idxs(4): []
```

#### Method `compare#1`
Compare object of class `List` with method parameter.

##### Parameters:
1. Any type.

##### Return:
Object of class `Integer`.
* `-1` - if object of class `List` is lesser than method parameter.
* `1` - if object of class `List` is greater than method parameter.
* `0` - if object of class `List` is equal to method parameter.

##### Example:
```cpp
list_0 = new List([1,2,3]);
list_1 = new List([1,2,3,4]);
("list_0.compare(list_1): %d\n" % list_0.compare(list_1)).print();
("list_0.compare(list_0): %d\n" % list_0.compare(list_0)).print();
("list_0.compare(0): %d\n" % list_0.compare(0)).print();
```
```
list_0.compare(list_1): -1
list_0.compare(list_0): 0
list_0.compare(0): 1
```

#### Method `item#1`
Retrieve element from object of class `List` stored at requested index position.

##### Parameters:
1. Type convertible to integer.

##### Return:
Object stored in object of class `List` at position of requested index.

##### Example:
```cpp
list = new List([1,2,3]);
("list: %s\n" % list.to_string()).print();
("list.item(1): %d\n" % list.item(1)).print();
("list.item(2): %d\n" % list.item(2)).print();
```
```
list: [1,2,3]
list.item(1): 2
list.item(2): 3
```

#### Method `first_idx#0`
Retrieve index of first element in object of class `List`.

##### Return:
* Object of class `Integer` if object of class `List` contain some elements.
* Object of class `Blank` otherwise.

##### Example:
```cpp
list = new List([1]);
("list.first_idx(): %s\n" % list.first_idx().to_string()).print();
list.remove(list.get_idx(1));
("list.first_idx(): %s\n" % list.first_idx().to_string()).print();
```
```
list.first_idx(): 0
list.first_idx(): <blank>
```

#### Method `last_idx#0`
Retrieve index of last element in object of class `List`.

##### Return:
* Object of class `Integer` if object of class `List` contain some elements.
* Object of class `Blank` otherwise.

##### Example:
```cpp
list = new List([1,2,3]);
("list.last_idx(): %s\n" % list.last_idx().to_string()).print();
list.remove(list.get_idx(3));
("list.last_idx(): %s\n" % list.last_idx().to_string()).print();
list.clear();
("list.last_idx(): %s\n" % list.last_idx().to_string()).print();
```
```
list.last_idx(): 2
list.last_idx(): 1
list.last_idx(): <blank>
```

#### Method `next_idx#1`
From object of class `List` retrieve index of element following element
identified by method parameter.

##### Parameters:

1. Type convertible to integer.

##### Return:
* Object of class `Integer` if there is some element following element
  identified by method parameter.
* Object of class `Blank` otherwise.

##### Example:
```cpp
list = new List([1,2,3]);
("list: %s\n" % list.to_string()).print();
idx = list.first_idx();
do {
  ("idx: %s\n" % idx.to_string()).print();
  idx = list.next_idx(idx);
} while(Blank != idx);
```
```
list: [1,2,3]
idx: 0
idx: 1
idx: 2
```

#### Method `prev_idx#1`
From object of class `List` retrieve index of element preceding element
identified by method parameter.

##### Parameters:

1. Type convertible to integer.

##### Return:
* Object of class `Integer` if there is some element preceding element
  identified by method parameter.
* Object of class `Blank` otherwise.

##### Example:
```cpp
list = new List([1,2,3]);
("list: %s\n" % list.to_string()).print();
idx = list.last_idx();
do {
  ("idx: %s\n" % idx.to_string()).print();
  idx = list.prev_idx(idx);
} while(Blank != idx);
```
```
list: [1,2,3]
idx: 2
idx: 1
idx: 0
```

#### Method `length#0`
Retrieve count of elements in object of class `List`.

##### Return:
Object of class `Integer`.

##### Example:
```cpp
list = new List([1,2,3]);
("list.length(): %d\n" % list.length()).print();
list.remove(list.get_idx(3));
("list.length(): %d\n" % list.length()).print();
```
```
list.length(): 3
list.length(): 2
```

#### Method `to_string#0`
Convert object of class `List` to object of class `String`. Each element of
list is converted to string by call of its `to_string#0` method. As separator
of string values of elements is used `,`.

##### Return:
Object of class `String`.

##### Example:
```cpp
list = new List([1,2,3]);
("list: %s\n" % list.to_string()).print();
```
```
list: [1,2,3]
```

#### Method `to_string#1`
Convert object of class `List` to object of class `String`. Each element of
list is converted to string by call of its `to_string#0` method. As separator
of string values is used method parameter.

##### Parameters:
1. Object of class `String`.

##### Return:
Object of class `String`.

##### Example:
```cpp
list = new List([1,2,3,new List([1,2,3])]);
("list: %s\n" % list.to_string("+")).print();
("list: %s\n" % list.to_string("<->")).print();
```
```
list: 1+2+3+[1,2,3]
list: 1<->2<->3<->[1,2,3]
```

#### Method `print#0`
Print string representation of object of class `List` to standard output.

##### Return:
Object of class `Blank`.

##### Example:
```cpp
list = new List([1,2,3]);
list.print();
"\n".print();
```
```
[1,2,3]
```

