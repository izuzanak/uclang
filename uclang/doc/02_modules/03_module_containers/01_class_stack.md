
# Class Stack
Container class implementing simple abstract data type stack.

## Constructors

#### Constructor `Stack#0`
Creates empty object of class `Stack`.

**Example:**

```cpp
stack = new Stack();
("stack: %s\n" % stack.to_string()).print();
```
```
stack: []
```

#### Constructor `Stack#1`
Creates object of class `Stack` containing elements retrieved from method parameter.

**Parameters:**

1. Iterable type.

**Example:**

```cpp
stack = new Stack([1,2,3]);
("stack: %s\n" % stack.to_string()).print();
```
```
stack: [1,2,3]
```

## Operators

#### Operator `operator_binary_equal#1`
Assignment operator `=`. Object of class `Stack` is replaced by method
parameter.

**Parameters:**

1. Any type.

**Return:**

Value of object.

**Example:**

```cpp
stack = new Stack();
("stack: %s\n" % stack.to_string()).print();
stack = "Hello world";
("stack: %s\n" % stack.to_string()).print();
```
```
stack: []
stack: Hello world
```

#### Operator `operator_binary_plus_equal#1`
Append operator `+=`. Append elements retrieved from method parameter to object
of class `Stack`.

**Parameters:**

1. Iterable type.

**Return:**

Value of object.

**Example:**

```cpp
stack = new Stack([1,2,3]);
stack += [4,5,6];
("stack: %s\n" % stack.to_string()).print();
```
```
stack: [1,2,3,4,5,6]
```

#### Operator `operator_binary_double_equal#1`
Comparison operator `==`. Compares object of class `Stack` with method
parameter and return `1` if objects has same value or `0` otherwise.

**Parameters:**

1. Any type.

**Return:**

Object of class `Integer`.
  * `0` - method parameter has different value than object.
  * `1` - method parameter has same value as object.

**Example:**

```cpp
stack_0 = new Stack([1,2,3]);
stack_1 = new Stack([1,2,4]);
stack_2 = stack_0;
("stack_0 == stack_1: %d\n" % (stack_0 == stack_1)).print();
("stack_0 == stack_2: %d\n" % (stack_0 == stack_2)).print();
```
```
stack_0 == stack_1: 0
stack_0 == stack_2: 1
```

#### Operator `operator_binary_exclamation_equal#1`
Comparison operator `!=`. Compares object of class `Stack` with method parameter and
return `0` if objects has same value or `1` otherwise.

**Parameters:**

1. Any type.

**Return:**

Object of class `Integer`.
  * `0` - method parameter has same value as object.
  * `1` - method parameter has different value than object.

**Example:**

```cpp
stack_0 = new Stack([1,2,3]);
stack_1 = new Stack([1,2,4]);
stack_2 = stack_0;
("stack_0 != stack_1: %d\n" % (stack_0 != stack_1)).print();
("stack_0 != stack_2: %d\n" % (stack_0 != stack_2)).print();
```
```
stack_0 != stack_1: 1
stack_0 != stack_2: 0
```

#### Operator `operator_binary_plus#1`
Concatenation operator `+`. Creates object of class `Stack` containing elements
of original object of class `Stack` concatenated with elements retrieved from
method parameter.

**Parameters:**

1. Iterable type.

**Return:**

Object of class `Stack` containing elements of original stack concatenated with
elements retrieved from method parameter.

**Example:**

```cpp
stack_0 = new Stack([1,2,3]);
stack_1 = new Stack([1,2,4]);
("stack_0 + stack_1: %s\n" % (stack_0 + stack_1).to_string()).print();
```
```
stack_0 + stack_1: [1,2,3,1,2,4]
```

## Methods

#### Method `clear#0`
Empty stack. Release all elements stored in object of class `Stack`.

**Return:**

Object of class `Blank`.

**Example:**

```cpp
stack = new Stack([1,2,3]);
("stack: %s\n" % stack.to_string()).print();
stack.clear();
("stack: %s\n" % stack.to_string()).print();
```
```
stack: [1,2,3]
stack: []
```

#### Method `items#0`
Retrieve elements contained in object of class `Stack`. Elements are returned
as object of class `Array`.

**Return:**

Object of class `Array` containing all elements of stack.

**Example:**

```cpp
stack = new Stack([1,2,3]);
array = stack.items();
("type array: %s\n" % (type array).to_string()).print();
("array: %s\n" % array.to_string()).print();
```
```
type array: Array
array: [1,2,3]
```

#### Method `push#1`
Insert method parameter to end of object of class `Stack`.

**Parameters:**

1. Any type.

**Return:**

Object of class `Blank`.

**Example:**

```cpp
stack = new Stack([1,2,3]);
("stack: %s\n" % stack.to_string()).print();
stack.push(4);
stack.push(5);
stack.push(6);
("stack: %s\n" % stack.to_string()).print();
```
```
stack: [1,2,3]
stack: [1,2,3,4,5,6]
```

#### Method `push_ref#1`
Insert reference to method parameter to end of object of class `Stack`.

**Parameters:**

1. Any type.

**Return:**

Object of class `Blank`.

**Example:**

```cpp
value = 10;
stack = new Stack([1,2,3]);
("stack: %s\n" % stack.to_string()).print();
stack.push_ref(value);
("stack: %s\n" % stack.to_string()).print();
value = 100;
("stack: %s\n" % stack.to_string()).print();
```
```
stack: [1,2,3]
stack: [1,2,3,10]
stack: [1,2,3,100]
```

#### Method `pop#0`
Retrieve and return object from top of object of class `Stack`.

**Return:**

Object from top of stack.

**Example:**

```cpp
stack = new Stack([1,2,3]);
("stack: %s\n" % stack.to_string()).print();
("stack.pop(): %d\n" % stack.pop()).print();
("stack.pop(): %d\n" % stack.pop()).print();
```
```
stack: [1,2,3]
stack.pop(): 3
stack.pop(): 2
```

#### Method `compare#1`
Compare object of class `Stack` with method parameter.

**Parameters:**

1. Any type.

**Return:**

Object of class `Integer`.
* `-1` - if object of class `Stack` is lesser than method parameter.
* `1` - if object of class `Stack` is greater than method parameter.
* `0` - if object of class `Stack` is equal to method parameter.

**Example:**

```cpp
stack_0 = new Stack([1,2,3]);
stack_1 = new Stack([1,2,3,4]);
("stack_0.compare(stack_1): %d\n" % stack_0.compare(stack_1)).print();
("stack_0.compare(stack_0): %d\n" % stack_0.compare(stack_0)).print();
("stack_0.compare(0): %d\n" % stack_0.compare(0)).print();
```
```
stack_0.compare(stack_1): -1
stack_0.compare(stack_0): 0
stack_0.compare(0): 1
```

#### Method `item#1`
Retrieve element from object of class `Stack` stored at requested index position.

**Parameters:**

1. Type convertible to integer.

**Return:**

Object stored in object of class `Stack` at position of requested index.

**Example:**

```cpp
stack = new Stack([1,2,3]);
("stack: %s\n" % stack.to_string()).print();
("stack.item(1): %d\n" % stack.item(1)).print();
("stack.item(2): %d\n" % stack.item(2)).print();
```
```
stack: [1,2,3]
stack.item(1): 2
stack.item(2): 3
```

#### Method `first_idx#0`
Retrieve index of first element in object of class `Stack`.

**Return:**

* Object of class `Integer` if object of class `Stack` contains some elements.
* Object of class `Blank` otherwise.

**Example:**

```cpp
stack = new Stack([1]);
("stack.first_idx(): %s\n" % stack.first_idx().to_string()).print();
stack.pop();
("stack.first_idx(): %s\n" % stack.first_idx().to_string()).print();
```
```
stack.first_idx(): 0
stack.first_idx(): <blank>
```

#### Method `last_idx#0`
Retrieve index of last element in object of class `Stack`.

**Return:**

* Object of class `Integer` if object of class `Stack` contains some elements.
* Object of class `Blank` otherwise.

**Example:**

```cpp
stack = new Stack([1,2,3]);
("stack.last_idx(): %s\n" % stack.last_idx().to_string()).print();
stack.pop();
("stack.last_idx(): %s\n" % stack.last_idx().to_string()).print();
stack.clear();
("stack.last_idx(): %s\n" % stack.last_idx().to_string()).print();
```
```
stack.last_idx(): 2
stack.last_idx(): 1
stack.last_idx(): <blank>
```

#### Method `next_idx#1`
From object of class `Stack` retrieve index of element following element
identified by method parameter.

**Parameters:**

1. Type convertible to integer.

**Return:**

* Object of class `Integer` if there is some element following element
  identified by method parameter.
* Object of class `Blank` otherwise.

**Example:**

```cpp
stack = new Stack([1,2,3]);
("stack: %s\n" % stack.to_string()).print();
idx = stack.first_idx();
do {
  ("idx: %s\n" % idx.to_string()).print();
  idx = stack.next_idx(idx);
} while(Blank != idx);
```
```
stack: [1,2,3]
idx: 0
idx: 1
idx: 2
```

#### Method `prev_idx#1`
From object of class `Stack` retrieve index of element preceding element
identified by method parameter.

**Parameters:**

1. Type convertible to integer.

**Return:**

* Object of class `Integer` if there is some element preceding element
  identified by method parameter.
* Object of class `Blank` otherwise.

**Example:**

```cpp
stack = new Stack([1,2,3]);
("stack: %s\n" % stack.to_string()).print();
idx = stack.last_idx();
do {
  ("idx: %s\n" % idx.to_string()).print();
  idx = stack.prev_idx(idx);
} while(Blank != idx);
```
```
stack: [1,2,3]
idx: 2
idx: 1
idx: 0
```

#### Method `length#0`
Retrieve count of elements in object of class `Stack`.

**Return:**

Object of class `Integer`.

**Example:**

```cpp
stack = new Stack([1,2,3]);
("stack.length(): %d\n" % stack.length()).print();
stack.pop();
("stack.length(): %d\n" % stack.length()).print();
```
```
stack.length(): 3
stack.length(): 2
```

#### Method `to_string#0`
Convert object of class `Stack` to object of class `String`. Each element of
stack is converted to string by call of its `to_string#0` method. As separator
of string values of elements is used character `,`.

**Return:**

Object of class `String`.

**Example:**

```cpp
stack = new Stack([1,2,3]);
("stack: %s\n" % stack.to_string()).print();
```
```
stack: [1,2,3]
```

#### Method `to_string#1`
Convert object of class `Stack` to object of class `String`. Each element of
stack is converted to string by call of its `to_string#0` method. As separator
of string values is used method parameter.

**Parameters:**

1. Object of class `String`.

**Return:**

Object of class `String`.

**Example:**

```cpp
stack = new Stack([1,2,3,new Stack([1,2,3])]);
("stack: %s\n" % stack.to_string("+")).print();
("stack: %s\n" % stack.to_string("<->")).print();
```
```
stack: 1+2+3+[1,2,3]
stack: 1<->2<->3<->[1,2,3]
```

#### Method `print#0`
Print string representation of object of class `Stack` to standard output.

**Return:**

Object of class `Blank`.

**Example:**

```cpp
stack = new Stack([1,2,3]);
stack.print();
"\n".print();
```
```
[1,2,3]
```

