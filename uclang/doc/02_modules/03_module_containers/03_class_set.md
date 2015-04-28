
# Class Set
Container class implementing simple abstract data type set.

## Constructors

#### Constructor `Set#0`
Creates empty object of class `Set`.

##### Example:
```cpp
set = new Set();
("set: %s\n" % set.to_string()).print();
```
```
set: []
```

#### Constructor `Set#1`
Creates object of class `Set` containing elements retrieved from method parameter.

##### Parameters:
1. Iterable type.

##### Example:
```cpp
set = new Set([1,2,3]);
("set: %s\n" % set.to_string()).print();
```
```
set: [1,2,3]
```

## Operators

#### Operator `operator_binary_equal#1`
Assignment operator `=`. Object of class `Set` is replaced by method
parameter.

##### Parameters:
1. Any type.

##### Return:
Value of object.

##### Example:

```cpp
set = new Set();
("set: %s\n" % set.to_string()).print();
set = "Hello world";
("set: %s\n" % set.to_string()).print();
```
```
set: []
set: Hello world
```

#### Operator `operator_binary_plus_equal#1`
Append operator `+=`. Insert elements retrieved from method parameter to object
of class `Set`.

##### Parameters:
1. Iterable type.

##### Return:
Value of object.

##### Example:
```cpp
set = new Set([1,2,3]);
set += [3,4,5];
("set: %s\n" % set.to_string()).print();
```
```
set: [1,2,3,4,5]
```

#### Operator `operator_binary_minus_equal#1`
Set difference operator `-=`. Creates object of class `Set` containing elements
from first object of class `Set` that are not contained in second object of
class `Set`. Value of variable is set to result object of class `Set`.

##### Parameters:
1. Object of class `Set`.

##### Return:
Value of object.

##### Example:
```cpp
set = new Set([1,2,3]);
set -= new Set([2,3,4]);
("set: %s\n" % set.to_string()).print();
```
```
set: [1]
```

#### Operator `operator_binary_ampersand_equal#1`
Set intersection operator `&=`. Creates object of class `Set` containing
elements contained in both source objects of class `Set`. Value of variable is
set to result object of class `Set`.

##### Parameters:
1. Object of class `Set`.

##### Return:
Value of object.

##### Example:
```cpp
set = new Set([1,2,3]);
set &= new Set([2,3,4]);
("set: %s\n" % set.to_string()).print();
```
```
set: [2,3]
```

#### Operator `operator_binary_pipe_equal#1`
Set union operator `|=`. Creates object of class `Set` containing elements from
both source objects of class `Set`. Value of variable is set to result object
of class `Set`.

##### Parameters:
1. Object of class `Set`.

##### Return:
Value of object.

##### Example:
```cpp
set = new Set([1,2,3]);
set |= new Set([2,3,4]);
("set: %s\n" % set.to_string()).print();
```
```
set: [1,2,3,4]
```

#### Operator `operator_binary_circumflex_equal#1`
Set symmetric difference operator `^=`. Creates object of class `Set` containing
elements from both source objects of class `Set` that are contained exactly in
one of them. Value of variable is set to result object of class `Set`.

##### Parameters:
1. Object of class `Set`.

##### Return:
Value of object.

##### Example:
```cpp
set = new Set([1,2,3]);
set ^= new Set([2,3,4]);
("set: %s\n" % set.to_string()).print();
```
```
set: [1,4]
```

#### Operator `operator_binary_ampersand#1`
Set intersection operator `&`. Creates object of class `Set` containing elements
contained in both source objects of class `Set`.

##### Parameters:
1. Object of class `Set`.

##### Return:
Object of class `Set`.

##### Example:
```cpp
set = new Set([1,2,3]) & new Set([2,3,4]);
("set: %s\n" % set.to_string()).print();
```
```
set: [2,3]
```

#### Operator `operator_binary_pipe#1`
Set union operator `|`. Creates object of class `Set` containing elements
from both source objects of class `Set`.

##### Parameters:
1. Object of class `Set`.

##### Return:
Object of class `Set`.

##### Example:
```cpp
set = new Set([1,2,3]) | new Set([2,3,4]);
("set: %s\n" % set.to_string()).print();
```
```
set: [1,2,3,4]
```

#### Operator `operator_binary_circumflex#1`
Set symmetric difference operator `^`. Creates object of class `Set` containing
elements from both source objects of class `Set` that are contained exactly in
one of them.

##### Parameters:
1. Object of class `Set`.

##### Return:
Object of class `Set`.

##### Example:
```cpp
set = new Set([1,2,3]) ^ new Set([2,3,4]);
("set: %s\n" % set.to_string()).print();
```
```
set: [1,4]
```

#### Operator `operator_binary_double_equal#1`
Comparison operator `==`. Compares object of class `Set` with method
parameter and return `1` if objects has same value or `0` otherwise.

##### Parameters:
1. Any type.

##### Return:
Object of class `Integer`.
  * `0` - method parameter has different value than object.
  * `1` - method parameter has same value as object.

##### Example:
```cpp
set_0 = new Set([1,2,3]);
set_1 = new Set([1,2,4]);
set_2 = set_0;
("set_0 == set_1: %d\n" % (set_0 == set_1)).print();
("set_0 == set_2: %d\n" % (set_0 == set_2)).print();
```
```
set_0 == set_1: 0
set_0 == set_2: 1
```

#### Operator `operator_binary_exclamation_equal#1`
Comparison operator `!=`. Compares object of class `Set` with method parameter and
return `0` if objects has same value or `1` otherwise.

##### Parameters:
1. Any type.

##### Return:
Object of class `Integer`.
  * `0` - method parameter has different value than object.
  * `1` - method parameter has same value as object.

##### Example:
```cpp
set_0 = new Set([1,2,3]);
set_1 = new Set([1,2,4]);
set_2 = set_0;
("set_0 != set_1: %d\n" % (set_0 != set_1)).print();
("set_0 != set_2: %d\n" % (set_0 != set_2)).print();
```
```
set_0 != set_1: 1
set_0 != set_2: 0
```

#### Operator `operator_binary_rs_br_equal#1`
Subset test operator `>=`. Test if object of class `Set` given by method
parameter is subset of object of class `Set`.

##### Parameters:
1. Object of class `Set`.

##### Return:
Object of class `Integer`.
  * `0` - method parameter is not subset of object.
  * `1` - method parameter is subset of object.

##### Example:
```cpp
set_0 = new Set([1,2,3]);
set_1 = new Set([1,2,3,4]);
("set_0 >= set_1: %d\n" % (set_0 >= set_1)).print();
("set_1 >= set_0: %d\n" % (set_1 >= set_0)).print();
```
```
set_0 >= set_1: 0
set_1 >= set_0: 1
```

#### Operator `operator_binary_ls_br_equal#1`
Superset test operator `<=`. Test if object of class `Set` given by method
parameter is superset of object of class `Set`.

##### Parameters:
1. Object of class `Set`.

##### Return:
Object of class `Integer`.
  * `0` - method parameter is not superset of object.
  * `1` - method parameter is superset of object.

##### Example:
```cpp
set_0 = new Set([1,2,3]);
set_1 = new Set([1,2,3,4]);
("set_0 <= set_1: %d\n" % (set_0 <= set_1)).print();
("set_1 <= set_0: %d\n" % (set_1 <= set_0)).print();
```
```
set_0 <= set_1: 1
set_1 <= set_0: 0
```

#### Operator `operator_binary_plus#1`
Concatenation operator `+`. Creates object of class `Set` containing elements
of original object of class `Set` with inserted elements retrieved from
method parameter.

##### Parameters:
1. Iterable type.

##### Return
Object of class `Set` containing elements of original set concatenated with
elements retrieved from method parameter.

##### Example:
```cpp
set_0 = new Set([1,2,3]);
set_1 = new Set([1,2,4]);
("set_0 + set_1: %s\n" % (set_0 + set_1).to_string()).print();
```
```
set_0 + set_1: [1,2,3,4]
```

#### Operator `operator_binary_minus#1`
Set difference operator `-`. Creates object of class `Set` containing elements
from first object of class `Set` that are not contained in second object of
class `Set`.

##### Parameters:
1. Object of class `Set`.

##### Return:
Object of class `Set`.

##### Example:
```cpp
set = new Set([1,2,3]) - new Set([2,3,4]);
("set: %s\n" % set.to_string()).print();
```
```
set: [1]
```

#### Operator `operator_binary_le_br_re_br#1`
Item selection operator `[]`. Retrieve element from object of class `Set`
stored at requested index position.

##### Parameters:
1. Type convertible to integer.

##### Return:
Object stored in object of class `Set` at position of requested index.

##### Example:
```cpp
set = new Set([1,2,3]);
("set: %s\n" % set.to_string()).print();
("set[1]: %d\n" % set[1]).print();
("set[2]: %d\n" % set[2]).print();
```
```
set: [1,2,3]
set[2]: 2
set[3]: 3
```

## Methods

#### Method `clear#0`
Empty set. Release all elements stored in object of class `Set`.

##### Return:
object of class `Blank`.

##### Example:
```cpp
set = new Set([1,2,3]);
("set: %s\n" % set.to_string()).print();
set.clear();
("set: %s\n" % set.to_string()).print();
```
```
set: [1,2,3]
set: []
```

#### Method `items#0`
Retrieve elements contained in object of class `Set`. Elements are returned
as object of class `Array`.

##### Return:
Object of class `Array` containing all elements of set.

##### Example:
```cpp
set = new Set([1,2,3]);
array = set.items();
("type array: %s\n" % (type array).to_string()).print();
("array: %s\n" % set.to_string()).print();
```
```
type array: Array
array: [1,2,3]
```

#### Method `insert#1`
Insert method parameter to object of class `Set`.

##### Parameters:
1. Any type.

##### Return:
Object of class `Blank`.

##### Example:
```cpp
set = new Set([1,2,3]);
("set: %s\n" % set.to_string()).print();
set.insert(3);
set.insert(4);
set.insert(5);
("set: %s\n" % set.to_string()).print();
```
```
set: [1,2,3]
set: [1,2,3,4,5]
```

#### Method `remove#1`
Remove element given by method parameter from object of class `Set`.

##### Parameters:
1. Any type.

##### Return:
Object of class `Blank`.

##### Example:
```cpp
set = new Set([1,2,3]);
("set: %s\n" % set.to_string()).print();
set.remove(2);
("set: %s\n" % set.to_string()).print();
```
```
set: [1,2,3]
set: [1,3]
```

#### Method `contain#1`
Test if object of class `Set` contains object given by method parameter.

##### Parameters:
1. Any type.

##### Return:
Object of class `Integer`.
  * `0` - object of class `Set` does not contain method parameter.
  * `1` - object of class `Set` contain method parameter.

##### Example:
```cpp
set = new Set([1,2,3]);
("set: %s\n" % set.to_string()).print();
("set.contain(2): %d\n" % set.contain(2)).print();
("set.contain(3): %d\n" % set.contain(3)).print();
("set.contain(4): %d\n" % set.contain(4)).print();
```
```
set: [1,2,3]
set.contain(2): 1
set.contain(3): 1
set.contain(4): 0
```

#### Method `compare#1`
Compare object of class `Set` with method parameter.

##### Parameters:
1. Any type.

##### Return:
Object of class `Integer`.
* `-1` - if object of class `Set` is lesser than method parameter.
* `1` - if object of class `Set` is greater than method parameter.
* `0` - if object of class `Set` is equal to method parameter.

##### Example:
```cpp
set_0 = new Set([1,2,3]);
set_1 = new Set([1,2,3,4]);
("set_0.compare(set_1): %d\n" % set_0.compare(set_1)).print();
("set_0.compare(set_0): %d\n" % set_0.compare(set_0)).print();
("set_0.compare(0): %d\n" % set_0.compare(0)).print();
```
```
set_0.compare(set_1): -1
set_0.compare(set_0): 0
set_0.compare(0): 1
```

#### Method `item#1`
Retrieve element from object of class `Set` stored at requested index position.

##### Parameters:
1. Type convertible to integer.

##### Return:
Object stored in object of class `Set` at position of requested index.

##### Example:
```cpp
set = new Set([1,2,3]);
("set: %s\n" % set.to_string()).print();
("set.item(2): %d\n" % set.item(2)).print();
("set.item(3): %d\n" % set.item(3)).print();
```
```
set: [1,2,3]
set.item(2): 2
set.item(3): 3
```

#### Method `first_idx#0`
Retrieve index of first element in object of class `Set`.

##### Return:
* Object of class `Integer` if object of class `Set` contain some elements.
* Object of class `Blank` otherwise.

##### Example:
```cpp
set = new Set([1]);
("set.first_idx(): %s\n" % set.first_idx().to_string()).print();
set.remove(1);
("set.first_idx(): %s\n" % set.first_idx().to_string()).print();
```
```
set.first_idx(): 0
set.first_idx(): <blank>
```

#### Method `last_idx#0`
Retrieve index of last element in object of class `Set`.

##### Return:
* Object of class `Integer` if object of class `Set` contain some elements.
* Object of class `Blank` otherwise.

##### Example:
```cpp
set = new Set([1,2,3]);
("set.last_idx(): %s\n" % set.last_idx().to_string()).print();
set.remove(3);
("set.last_idx(): %s\n" % set.last_idx().to_string()).print();
set.clear();
("set.last_idx(): %s\n" % set.last_idx().to_string()).print();
```
```
set.last_idx(): 3
set.last_idx(): 2
set.last_idx(): <blank>
```

#### Method `next_idx#1`
From object of class `Set` retrieve index of element following element
identified by method parameter.

##### Parameters:

1. Type convertible to integer.

##### Return:
* Object of class `Integer` if there is some element following element
  identified by method parameter.
* Object of class `Blank` otherwise.

##### Example:
```cpp
set = new Set([1,2,3]);
("set: %s\n" % set.to_string()).print();
idx = set.first_idx();
do {
  ("idx: %s\n" % idx.to_string()).print();
  idx = set.next_idx(idx);
} while(Blank != idx);
```
```
set: [1,2,3]
idx: 0
idx: 2
idx: 3
```

#### Method `prev_idx#1`
From object of class `Set` retrieve index of element preceding element
identified by method parameter.

##### Parameters:

1. Type convertible to integer.

##### Return:
* Object of class `Integer` if there is some element preceding element
  identified by method parameter.
* Object of class `Blank` otherwise.

##### Example:
```cpp
set = new Set([1,2,3]);
("set: %s\n" % set.to_string()).print();
idx = set.last_idx();
do {
  ("idx: %s\n" % idx.to_string()).print();
  idx = set.prev_idx(idx);
} while(Blank != idx);
```
```
set: [1,2,3]
idx: 3
idx: 2
idx: 0
```

#### Method `length#0`
Retrieve count of elements in object of class `Set`.

##### Return:
Object of class `Integer`.

##### Example:
```cpp
set = new Set([1,2,3]);
("set.length(): %d\n" % set.length()).print();
set.remove(2);
("set.length(): %d\n" % set.length()).print();
```
```
set.length(): 3
set.length(): 2
```

#### Method `to_string#0`
Convert object of class `Set` to object of class `String`. Each element of
set is converted to string by call of its `to_string#0` method. As separator
of string values of elements is used `,`.

##### Return:
Object of class `String`.

##### Example:
```cpp
set = new Set([1,2,3]);
("set: %s\n" % set.to_string()).print();
```
```
set: [1,2,3]
```

#### Method `to_string#1`
Convert object of class `Set` to object of class `String`. Each element of
set is converted to string by call of its `to_string#0` method. As separator
of string values is used method parameter.

##### Parameters:
1. Object of class `String`.

##### Return:
Object of class `String`.

##### Example:
```cpp
set = new Set([1,2,3,new Set([1,2,3])]);
("set: %s\n" % set.to_string("+")).print();
("set: %s\n" % set.to_string("<->")).print();
```
```
set: 1+2+3+[1,2,3]
set: 1<->2<->3<->[1,2,3]
```

#### Method `print#0`
Print string representation of object of class `Set` to standard output.

##### Return:
Object of class `Blank`.

##### Example:
```cpp
set = new Set([1,2,3]);
set.print();
"\n".print();
```
```
[1,2,3]
```

