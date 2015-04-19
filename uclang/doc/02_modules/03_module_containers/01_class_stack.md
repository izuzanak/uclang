
# class Stack

Container class implementing simple abstract data type stack.

## Constructors

#### Constructor `Stack#0`
Creates empty object of class `Stack`.

##### Example:
```cpp
stack = new Stack();
("stack: %s\n" % stack.to_string()).print();
```
```
stack: []
```

#### Constructor `Stack#1`
Creates object of class `Stack` containing elements retrieved from parameter. 

##### Parameters:
1. Iterable type. 

##### Example:
```cpp
stack = new Stack([1,2,3]);
("stack: %s\n" % stack.to_string()).print();
```
```
stack: [1,2,3]
```

## Operators

#### Operator `operator_binary_equal#1`
Asignment operator `=`. Location of object of class `Stack` is replaced by parameter value.

##### Parameters:

1. Any type.

##### Return:
Return value of object.

##### Example:

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
Append operator `+=`. Append to stack elements retrieved from parameter.

##### Parameters:
1. Iterable type.

##### Return:
Return value of object.

##### Example:
```cpp
stack = new Stack([1,2,3]);
stack += [4,5,6];
("stack: %s\n" % stack.to_string()).print();
```
```
stack: [1,2,3,4,5,6]
```

#### Operator `operator_binary_double_equal#1`
Comparison operator `==`. Compares object of class `Stack` with parameter and return `1` if objects has same value and `0` otherwise.

##### Parameters:
1. Any type.

##### Return:
Object of class `Integer`.
  * `0` - parameter has different value than object.
  * `1` - parameter has same value as object.

##### Example:
```cpp
stack_0 = new Stack([1,2,3]);
stack_1 = new Stack([1,2,4]);
stack_2 = stack_1;
("stack_0 == stack_1: %d\n" % (stack_0 == stack_1)).print();
("stack_0 == stack_2: %d\n" % (stack_0 == stack_2)).print();
```
```
stack_0 == stack_1: 0
stack_0 == stack_2: 1
```

#### Operator `operator_binary_exclamation_equal#1`
#### Operator `operator_binary_plus#1`

#### Method `clear#0`
#### Method `items#0`
#### Method `push#1`
#### Method `push_ref#1`
#### Method `pop#0`
#### Method `compare#1`
#### Method `item#1`
#### Method `first_idx#0`
#### Method `last_idx#0`
#### Method `next_idx#1`
#### Method `prev_idx#1`
#### Method `length#0`
#### Method `to_string#0`
#### Method `to_string#1`
#### Method `print#0`

