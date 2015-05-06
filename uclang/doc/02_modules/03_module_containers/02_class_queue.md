
# Class Queue
Container class implementing simple abstract data type queue.

## Constructors

#### Constructor `Queue#0`
Create empty object of class `Queue`.

##### Example:
```cpp
queue = new Queue();
("queue: %s\n" % queue.to_string()).print();
```
```
queue: []
```

#### Constructor `Queue#1`
Creates object of class `Queue` containing elements retrieved from method parameter.

#### Parameters:
1. Iterable type.

##### Example:
```cpp
queue = new Queue([1,2,3]);
("queue: %s\n" % queue.to_string()).print();
```
```
queue: [1,2,3]
```

## Operators

#### Operator `operator_binary_equal#1`
Assignment operator `=`. Object of class `Queue` is replaced by method
parameter.

##### Parameters:
1. Any type.

##### Return:
Value of object.

##### Example:

```cpp
queue = new Queue();
("queue: %s\n" % queue.to_string()).print();
queue = "Hello world";
("queue: %s\n" % queue.to_string()).print();
```
```
queue: []
queue: Hello world
```

#### Operator `operator_binary_plus_equal#1`
Append operator `+=`. Append elements retrieved from method parameter to object
of class `Queue`.

##### Parameters:
1. Iterable type.

##### Return:
Value of object.

##### Example:
```cpp
queue = new Queue([1,2,3]);
queue += [4,5,6];
("queue: %s\n" % queue.to_string()).print();
```
```
queue: [1,2,3,4,5,6]
```

#### Operator `operator_binary_double_equal#1`
Comparison operator `==`. Compares object of class `Queue` with method
parameter and return `1` if objects has same value or `0` otherwise.

##### Parameters:
1. Any type.

##### Return:
Object of class `Integer`.
  * `0` - method parameter has different value than object.
  * `1` - method parameter has same value as object.

##### Example:
```cpp
queue_0 = new Queue([1,2,3]);
queue_1 = new Queue([1,2,4]);
queue_2 = queue_0;
("queue_0 == queue_1: %d\n" % (queue_0 == queue_1)).print();
("queue_0 == queue_2: %d\n" % (queue_0 == queue_2)).print();
```
```
queue_0 == queue_1: 0
queue_0 == queue_2: 1
```

#### Operator `operator_binary_exclamation_equal#1`
Comparison operator `!=`. Compares object of class `Queue` with method parameter and
return `0` if objects has same value or `1` otherwise.

##### Parameters:
1. Any type.

##### Return:
Object of class `Integer`.
  * `0` - method parameter has same value as object.
  * `1` - method parameter has different value than object.

##### Example:
```cpp
queue_0 = new Queue([1,2,3]);
queue_1 = new Queue([1,2,4]);
queue_2 = queue_0;
("queue_0 != queue_1: %d\n" % (queue_0 != queue_1)).print();
("queue_0 != queue_2: %d\n" % (queue_0 != queue_2)).print();
```
```
queue_0 != queue_1: 1
queue_0 != queue_2: 0
```

#### Operator `operator_binary_plus#1`
Concatenation operator `+`. Creates object of class `Queue` containing elements
of original object of class `Queue` concatenated with elements retrieved from
method parameter.

##### Parameters:
1. Iterable type.

##### Return
Object of class `Queue` containing elements of original object of class `Queue`
concatenated with elements retrieved from method parameter.

##### Example:
```cpp
queue_0 = new Queue([1,2,3]);
queue_1 = new Queue([1,2,4]);
("queue_0 + queue_1: %s\n" % (queue_0 + queue_1).to_string()).print();
```
```
queue_0 + queue_1: [1,2,3,1,2,4]
```

## Methods

#### Method `clear#0`
Empty queue. Release all elements stored in object of class `Queue`.

##### Return:
Object of class `Blank`.

##### Example:
```cpp
queue = new Queue([1,2,3]);
("queue: %s\n" % queue.to_string()).print();
queue.clear();
("queue: %s\n" % queue.to_string()).print();
```
```
queue: [1,2,3]
queue: []
```

#### Method `items#0`
Retrieve elements contained in object of class `Queue`. Elements are returned
as object of class `Array`.

##### Return:
Object of class `Array` containing all elements of queue.

##### Example:
```cpp
queue = new Queue([1,2,3]);
array = queue.items();
("type array: %s\n" % (type array).to_string()).print();
("array: %s\n" % queue.to_string()).print();
```
```
type array: Array
array: [1,2,3]
```

#### Method `insert#1`
Insert method parameter to end of object of class `Queue`.

##### Parameters:
1. Any type.

##### Return:
Object of class `Blank`.

##### Example:
```cpp
queue = new Queue([1,2,3]);
("queue: %s\n" % queue.to_string()).print();
queue.insert(4);
queue.insert(5);
queue.insert(6);
("queue: %s\n" % queue.to_string()).print();
```
```
queue: [1,2,3]
queue: [1,2,3,4,5,6]
```

#### Method `insert_ref#1`
Insert reference to method parameter to end of object of class `Queue`.

##### Parameters:
1. Any type.

##### Return:
Object of class `Blank`.

##### Example:
```cpp
value = 10;
queue = new Queue([1,2,3]);
("queue: %s\n" % queue.to_string()).print();
queue.insert_ref(value);
("queue: %s\n" % queue.to_string()).print();
value = 100;
("queue: %s\n" % queue.to_string()).print();
```
```
queue: [1,2,3]
queue: [1,2,3,10]
queue: [1,2,3,100]
```

#### Method `next#0`
Retrieve and return next object from object of class `Queue`.

##### Return:
Next object from queue.

##### Example:
```cpp
queue = new Queue([1,2,3]);
("queue: %s\n" % queue.to_string()).print();
("queue.pop(): %d\n" % queue.pop()).print();
("queue.pop(): %d\n" % queue.pop()).print();
```
```
queue: [1,2,3]
queue.pop(): 3
queue.pop(): 2
```

#### Method `compare#1`
Compare object of class `Queue` with method parameter.

##### Parameters:
1. Any type.

##### Return:
Object of class `Integer`.
* `-1` - if object of class `Queue` is lesser than method parameter.
* `1` - if object of class `Queue` is greater than method parameter.
* `0` - if object of class `Queue` is equal to method parameter.

##### Example:
```cpp
queue_0 = new Queue([1,2,3]);
queue_1 = new Queue([1,2,3,4]);
("queue_0.compare(queue_1): %d\n" % queue_0.compare(queue_1)).print();
("queue_0.compare(queue_0): %d\n" % queue_0.compare(queue_0)).print();
("queue_0.compare(0): %d\n" % queue_0.compare(0)).print();
```
```
queue_0.compare(queue_1): -1
queue_0.compare(queue_0): 0
queue_0.compare(0): 1
```

#### Method `item#1`
Retrieve element from object of class `Queue` stored at requested index position.

##### Parameters:
1. Type convertible to integer.

##### Return:
Object stored in object of class `Queue` at position of requested index.

##### Example:
```cpp
queue = new Queue([1,2,3]);
("queue: %s\n" % queue.to_string()).print();
("queue.item(1): %d\n" % queue.item(1)).print();
("queue.item(2): %d\n" % queue.item(2)).print();
```
```
queue: [1,2,3]
queue.item(1): 2
queue.item(2): 3
```

#### Method `first_idx#0`
Retrieve index of first element in object of class `Queue`.

##### Return:
* Object of class `Integer` if object of class `Queue` contain some elements.
* Object of class `Blank` otherwise.

##### Example:
```cpp
queue = new Queue([1]);
("queue.first_idx(): %s\n" % queue.first_idx().to_string()).print();
queue.next();
("queue.first_idx(): %s\n" % queue.first_idx().to_string()).print();
```
```
queue.first_idx(): 0
queue.first_idx(): <blank>
```

#### Method `last_idx#0`
Retrieve index of last element in object of class `Queue`.

##### Return:
* Object of class `Integer` if object of class `Queue` contain some elements.
* Object of class `Blank` otherwise.

##### Example:
```cpp
queue = new Queue([1,2,3]);
("queue.last_idx(): %s\n" % queue.last_idx().to_string()).print();
queue.insert(4);
("queue.last_idx(): %s\n" % queue.last_idx().to_string()).print();
queue.clear();
("queue.last_idx(): %s\n" % queue.last_idx().to_string()).print();
```
```
queue.last_idx(): 2
queue.last_idx(): 3
queue.last_idx(): <blank>
```

#### Method `next_idx#1`
From object of class `Queue` retrieve index of element following element
identified by method parameter.

##### Parameters:

1. Type convertible to integer.

##### Return:
* Object of class `Integer` if there is some element following element
  identified by method parameter.
* Object of class `Blank` otherwise.

##### Example:
```cpp
queue = new Queue([1,2,3]);
("queue: %s\n" % queue.to_string()).print();
idx = queue.first_idx();
do {
  ("idx: %s\n" % idx.to_string()).print();
  idx = queue.next_idx(idx);
} while(Blank != idx);
```
```
queue: [1,2,3]
idx: 0
idx: 1
idx: 2
```

#### Method `prev_idx#1`
From object of class `Queue` retrieve index of element preceding element
identified by method parameter.

##### Parameters:

1. Type convertible to integer.

##### Return:
* Object of class `Integer` if there is some element preceding element
  identified by method parameter.
* Object of class `Blank` otherwise.

##### Example:
```cpp
queue = new Queue([1,2,3]);
("queue: %s\n" % queue.to_string()).print();
idx = queue.last_idx();
do {
  ("idx: %s\n" % idx.to_string()).print();
  idx = queue.prev_idx(idx);
} while(Blank != idx);
```
```
queue: [1,2,3]
idx: 2
idx: 1
idx: 0
```

#### Method `length#0`
Retrieve count of elements in object of class `Queue`.

##### Return:
Object of class `Integer`.

##### Example:
```cpp
queue = new Queue([1,2,3]);
("queue.length(): %d\n" % queue.length()).print();
queue.next();
("queue.length(): %d\n" % queue.length()).print();
```
```
queue.length(): 3
queue.length(): 2
```

#### Method `to_string#0`
Convert object of class `Queue` to object of class `String`. Each element of
queue is converted to string by call of its `to_string#0` method. As separator
of string values of elements is used `,`.

##### Return:
Object of class `String`.

##### Example:
```cpp
queue = new Queue([1,2,3]);
("queue: %s\n" % queue.to_string()).print();
```
```
queue: [1,2,3]
```

#### Method `to_string#1`
Convert object of class `Queue` to object of class `String`. Each element of
queue is converted to string by call of its `to_string#0` method. As separator
of string values is used method parameter.

##### Parameters:
1. Object of class `String`.

##### Return:
Object of class `String`.

##### Example:
```cpp
queue = new Queue([1,2,3,new Queue([1,2,3])]);
("queue: %s\n" % queue.to_string("+")).print();
("queue: %s\n" % queue.to_string("<->")).print();
```
```
queue: 1+2+3+[1,2,3]
queue: 1<->2<->3<->[1,2,3]
```

#### Method `print#0`
Print string representation of object of class `Queue` to standard output.

##### Return:
Object of class `Blank`.

##### Example:
```cpp
queue = new Queue([1,2,3]);
queue.print();
"\n".print();
```
```
[1,2,3]
```

