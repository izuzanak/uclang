
# class Set
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

<!-- FIXME TODO continue -->
#### Operator `operator_binary_rs_br_equal#1`
#### Operator `operator_binary_ls_br_equal#1`
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

<!-- FIXME TODO continue -->
#### Method `clear#0`
#### Method `items#0`
#### Method `insert#1`
#### Method `remove#1`
#### Method `contain#1`
#### Method `compare#1`
#### Method `item#1`
#### Method `first_idx#0`
#### Method `next_idx#1`
#### Method `length#0`
#### Method `to_string#0`
#### Method `to_string#1`
#### Method `print#0`

