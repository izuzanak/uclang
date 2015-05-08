
# Class Dict
Container class implementing simple abstract data type dictionary.

## Constructors

#### Constructor `Dict#0`
Creates empty object of class `Dict`.

**Example:**

```cpp
dict = new Dict();
("dict: %s\n" % dict.to_string()).print();
```
```
dict: []
```

#### Constructor `Dict#1`
Creates object of class `Dict` based on elements retrieved from method
parameter. Values of parameter elements represents alternating keys and values
of new object of class `Dict`.

**Parameters:**

1. Iterable type.

**Example:**

```cpp
dict = new Dict(["One",1,"Two",2,"Three",3]);
("dict: %s\n" % dict.to_string()).print();
```
```
dict: [One:1,Two:2,Three:3]
```

## Operators

#### Operator `operator_binary_equal#1`
Assignment operator `=`. Object of class `Dict` is replaced by method
parameter.

**Parameters:**

1. Any type.

**Return:**

Value of object.

**Example:**

```cpp
dict = new Dict();
("dict: %s\n" % dict.to_string()).print();
dict = "Hello world";
("dict: %s\n" % dict.to_string()).print();
```
```
dict: []
dict: Hello world
```

#### Operator `operator_binary_double_equal#1`
Comparison operator `==`. Compares object of class `Dict` with method
parameter and return `1` if objects has same value or `0` otherwise.

**Parameters:**

1. Any type.

**Return:**

Object of class `Integer`.
  * `0` - method parameter has different value than object.
  * `1` - method parameter has same value as object.

**Example:**

```cpp
dict_0 = new Dict(["One",1,"Two",2,"Three",3]);
dict_1 = new Dict(["One",1,"Two",2,"Three",4]);
dict_2 = dict_0;
("dict_0 == dict_1: %d\n" % (dict_0 == dict_1)).print();
("dict_0 == dict_2: %d\n" % (dict_0 == dict_2)).print();
```
```
dict_0 == dict_1: 0
dict_0 == dict_2: 1
```

#### Operator `operator_binary_exclamation_equal#1`
Comparison operator `!=`. Compares object of class `Dict` with method parameter and
return `0` if objects has same value or `1` otherwise.

**Parameters:**

1. Any type.

**Return:**

Object of class `Integer`.
  * `0` - method parameter has same value as object.
  * `1` - method parameter has different value than object.

**Example:**

```cpp
dict_0 = new Dict(["One",1,"Two",2,"Three",3]);
dict_1 = new Dict(["One",1,"Two",2,"Three",4]);
dict_2 = dict_0;
("dict_0 != dict_1: %d\n" % (dict_0 != dict_1)).print();
("dict_0 != dict_2: %d\n" % (dict_0 != dict_2)).print();
```
```
dict_0 != dict_1: 1
dict_0 != dict_2: 0
```

#### Operator `operator_binary_le_br_re_br#1`
Item selection operator `[]`. Retrieve element from object of class `Dict`
stored at requested key position.

**Parameters:**

1. Any type.

**Return:**

Object stored in object of class `Dict` at position of requested key.

**Example:**

```cpp
dict = new Dict(["One",1,"Two",2,"Three",3]);
("dict: %s\n" % dict.to_string()).print();
("dict[\"One\"]: %d\n" % dict["One"]).print();
("dict[\"Two\"]: %d\n" % dict["Two"]).print();
```
```
dict: [One:1,Two:2,Three:3]
dict["One"]: 1
dict["Two"]: 2
```

## Methods

#### Method `clear#0`
Empty dictionary. Release all elements stored in object of class `Dict`.

**Return:**

Object of class `Blank`.

**Example:**

```cpp
dict = new Dict(["One",1,"Two",2,"Three",3]);
("dict: %s\n" % dict.to_string()).print();
dict.clear();
("dict: %s\n" % dict.to_string()).print();
```
```
dict: [One:1,Two:2,Three:3]
dict: []
```

#### Method `keys#0`
Retrieve keys contained in object of class `Dict`. Keys are returned as object
of class `Array`.

**Return:**

Object of class `Array` containing all keys of dictionary.

**Example:**

```cpp
dict = new Dict(["One",1,"Two",2,"Three",3]);
array = dict.keys();
("type array: %s\n" % (type array).to_string()).print();
("array: %s\n" % array.to_string()).print();
```
```
type array: Array
array: [One,Two,Three]
```

#### Method `items#0`
Retrieve elements contained in object of class `Dict`. Elements are returned
as object of class `Array`.

**Return:**

Object of class `Array` containing all elements of dictionary.

**Example:**

```cpp
dict = new Dict(["One",1,"Two",2,"Three",3]);
array = dict.items();
("type array: %s\n" % (type array).to_string()).print();
("array: %s\n" % array.to_string()).print();
```
```
type array: Array
array: [1,2,3]
```

#### Method `store_ref#2`
Store reference to second method parameter under key determined by first
method parameter in object of class `Dict`.

**Parameters:**

1. Any type.
2. Any type.

**Return:**

Object of class `Blank`.

**Example:**

```cpp
value = 10;
dict = new Dict(["One",1,"Two",2,"Three",3]);
("dict: %s\n" % dict.to_string()).print();
dict.store_ref("Two",value);
("dict: %s\n" % dict.to_string()).print();
value = 100;
("dict: %s\n" % dict.to_string()).print();
```
```
dict: [One:1,Two:2,Three:3]
dict: [One:1,Two:10,Three:3]
dict: [One:1,Two:100,Three:3]
```

#### Method `has_key#1`
Test if object of class `Dict` has key given by method parameter.

**Parameters:**

1. Any type.

**Return:**

Object of class `Integer`.
  * `0` - object of class `Dict` does not have given key.
  * `1` - object of class `Dict` has given key.

**Example:**

```cpp
dict = new Dict(["One",1,"Two",2,"Three",3]);
("dict: %s\n" % dict.to_string()).print();
("dict.has_key(\"Two\"): %d\n" % dict.has_key("Two")).print();
("dict.has_key(\"Three\"): %d\n" % dict.has_key("Three")).print();
("dict.has_key(\"Four\"): %d\n" % dict.has_key("Four")).print();
```
```
dict: [One:1,Two:2,Three:3]
dict.has_key("Two"): 1
dict.has_key("Three"): 1
dict.has_key("Four"): 0
```

#### Method `remove_key#1`
Remove key given by method parameter from object of class `Dict`.
Value of object stored under key to be removed is also removed.

**Parameters:**

1. Any type.

**Return:**

Object of class `Blank`.

**Example:**

```cpp
dict = new Dict(["One",1,"Two",2,"Three",3]);
("dict: %s\n" % dict.to_string()).print();
dict.remove_key("Two");
("dict: %s\n" % dict.to_string()).print();
```
```
dict: [One:1,Two:2,Three:3]
dict: [One:1,Three:3]
```

#### Method `first_key#0`
Retrieve first key of object of class `Dict`.

**Return:**

* Value of first key of object of class `Dict` if it contains some elements.
* Object of class `Blank` otherwise.

**Example:**

```cpp
dict = new Dict(["One",1]);
("dict.first_key(): %s\n" % dict.first_key().to_string()).print();
dict.remove_key("One");
("dict.first_key(): %s\n" % dict.first_key().to_string()).print();
```
```
dict.first_key(): One
dict.first_key(): <blank>
```

#### Method `last_key#0`
Retrieve last key of object of class `Dict`.

**Return:**

* Value of last key of object of class `Dict` if it contains some elements.
* Object of class `Blank` otherwise.

**Example:**

```cpp
dict = new Dict(["One",1,"Two",2,"Three",3]);
("dict.last_key(): %s\n" % dict.last_key().to_string()).print();
dict.remove_key("Three");
("dict.last_key(): %s\n" % dict.last_key().to_string()).print();
dict.clear();
("dict.last_key(): %s\n" % dict.last_key().to_string()).print();
```
```
dict.last_key(): Three
dict.last_key(): Two
dict.last_key(): <blank>
```

#### Method `next_key#1`
From object of class `Dict` retrieve key following key identified by method
parameter.

**Parameters:**

1. Any type.

**Return:**

* Value of key following key identified by method parameter, if key identified
  by method parameter is not last key in object of class `Dict`.
* Object of class `Blank` otherwise.

**Example:**

```cpp
dict = new Dict(["One",1,"Two",2,"Three",3]);
("dict: %s\n" % dict.to_string()).print();
key = dict.first_key();
do {
  ("key: %s\n" % key.to_string()).print();
  key = dict.next_key(key);
} while(Blank != key);
```
```
dict: [One:1,Two:2,Three:3]
key: One
key: Two
key: Three
```

#### Method `prev_key#1`
From object of class `Dict` retrieve key preceding key identified by method
parameter.

**Parameters:**

1. Any type.

**Return:**

* Value of key preceding key identified by method parameter, if key identified
  by method parameter is not first key in object of class `Dict`.
* Object of class `Blank` otherwise.

**Example:**

```cpp
dict = new Dict(["One",1,"Two",2,"Three",3]);
("dict: %s\n" % dict.to_string()).print();
key = dict.last_key();
do {
  ("key: %s\n" % key.to_string()).print();
  key = dict.prev_key(key);
} while(Blank != key);
```
```
dict: [One:1,Two:2,Three:3]
key: Three
key: Two
key: One
```

#### Method `lee_key#1`
Retrieve key of object of class `Dict` which value is less or equal
than value of method parameter.

**Return:**

* Value of key of object of class `Dict` which is less or equal than value of
  method parameter.
* Object of class `Blank` otherwise.

**Example:**

```cpp
dict = new Dict([1.0,"One",2.0,"Two",3.0,"Three"]);
("dict.lee_key(0.6): %s\n" % dict.lee_key(0.6).to_string()).print();
("dict.lee_key(1.5): %s\n" % dict.lee_key(1.5).to_string()).print();
("dict.lee_key(2.1): %s\n" % dict.lee_key(2.1).to_string()).print();
```
```
dict.lee_key(0.6): <blank>
dict.lee_key(1.5): 1.000000
dict.lee_key(2.1): 2.000000
```

#### Method `gre_key#1`
Retrieve key of object of class `Dict` which value is greater or equal
than value of method parameter.

**Return:**

* Value of key of object of class `Dict` which is greater or equal than value
  of method parameter.
* Object of class `Blank` otherwise.

**Example:**

```cpp
dict = new Dict([1.0,"One",2.0,"Two",3.0,"Three"]);
("dict.gre_key(1.5): %s\n" % dict.gre_key(1.5).to_string()).print();
("dict.gre_key(2.1): %s\n" % dict.gre_key(2.1).to_string()).print();
("dict.gre_key(3.2): %s\n" % dict.gre_key(3.2).to_string()).print();
```
```
dict.gre_key(1.5): 2.000000
dict.gre_key(2.1): 3.000000
dict.gre_key(3.2): <blank>
```

#### Method `compare#1`
Compare object of class `Dict` with method parameter.

**Parameters:**

1. Any type.

**Return:**

Object of class `Integer`.
* `-1` - if object of class `Dict` is lesser than method parameter.
* `1` - if object of class `Dict` is greater than method parameter.
* `0` - if object of class `Dict` is equal to method parameter.

**Example:**

```cpp
dict_0 = new Dict(["One",1,"Two",2,"Three",3]);
dict_1 = new Dict(["One",1,"Two",2,"Three",4]);
("dict_0.compare(dict_1): %d\n" % dict_0.compare(dict_1)).print();
("dict_0.compare(dict_0): %d\n" % dict_0.compare(dict_0)).print();
("dict_0.compare(0): %d\n" % dict_0.compare(0)).print();
```
```
dict_0.compare(dict_1): -1
dict_0.compare(dict_0): 0
dict_0.compare(0): 1
```

#### Method `item#1`
Retrieve key from object of class `Dict` stored at requested index position.

**Parameters:**

1. Type convertible to integer.

**Return:**

Object representing key in object of class `Dict` at position of requested index.

**Example:**

```cpp
dict = new Dict(["One",1,"Two",2,"Three",3]);
("dict: %s\n" % dict.to_string()).print();
("dict.item(2): %s\n" % dict.item(2)).print();
("dict.item(3): %s\n" % dict.item(3)).print();
```
```
dict: [One:1,Two:2,Three:3]
dict.item(2): Two
dict.item(3): Three
```

#### Method `first_idx#0`
Retrieve index of first key in object of class `Dict`.

**Return:**

* Object of class `Integer` if object of class `Dict` contains some keys.
* Object of class `Blank` otherwise.

**Example:**

```cpp
dict = new Dict(["One",1]);
("dict.first_idx(): %s\n" % dict.first_idx().to_string()).print();
dict.remove_key("One");
("dict.first_idx(): %s\n" % dict.first_idx().to_string()).print();
```
```
dict.first_idx(): 0
dict.first_idx(): <blank>
```

#### Method `last_idx#0`
Retrieve index of last key in object of class `Dict`.

**Return:**

* Object of class `Integer` if object of class `Dict` contains some keys.
* Object of class `Blank` otherwise.

**Example:**

```cpp
dict = new Dict(["One",1,"Two",2,"Three",3]);
("dict.last_idx(): %s\n" % dict.last_idx().to_string()).print();
dict.remove_key("Three");
("dict.last_idx(): %s\n" % dict.last_idx().to_string()).print();
dict.clear();
("dict.last_idx(): %s\n" % dict.last_idx().to_string()).print();
```
```
dict.last_idx(): 3
dict.last_idx(): 2
dict.last_idx(): <blank>
```

#### Method `next_idx#1`
From object of class `Dict` retrieve index of key following key
identified by method parameter.

**Parameters:**

1. Type convertible to integer.

**Return:**

* Object of class `Integer` if there is some key following key identified by
  method parameter.
* Object of class `Blank` otherwise.

**Example:**

```cpp
dict = new Dict(["One",1,"Two",2,"Three",3]);
("dict: %s\n" % dict.to_string()).print();
idx = dict.first_idx();
do {
  ("idx: %s\n" % idx.to_string()).print();
  idx = dict.next_idx(idx);
} while(Blank != idx);
```
```
dict: [One:1,Two:2,Three:3]
idx: 0
idx: 2
idx: 3
```

#### Method `prev_idx#1`
From object of class `Dict` retrieve index of key preceding key
identified by method parameter.

**Parameters:**

1. Type convertible to integer.

**Return:**

* Object of class `Integer` if there is some key preceding key identified by
  method parameter.
* Object of class `Blank` otherwise.

**Example:**

```cpp
dict = new Dict(["One",1,"Two",2,"Three",3]);
("dict: %s\n" % dict.to_string()).print();
idx = dict.last_idx();
do {
  ("idx: %s\n" % idx.to_string()).print();
  idx = dict.prev_idx(idx);
} while(Blank != idx);
```
```
dict: [One:1,Two:2,Three:3]
idx: 3
idx: 2
idx: 0
```

#### Method `length#0`
Retrieve count of keys in object of class `Dict`.

**Return:**

Object of class `Integer`.

**Example:**

```cpp
dict = new Dict(["One",1,"Two",2,"Three",3]);
("dict.length(): %d\n" % dict.length()).print();
dict.remove_key("Two");
("dict.length(): %d\n" % dict.length()).print();
```
```
dict.length(): 3
dict.length(): 2
```

#### Method `to_string#0`
Convert object of class `Dict` to object of class `String`. Each key and
element of dictionary is converted to string by call of its `to_string#0`
method. As separator of string values of keys and elements is used character
`:`. As separator of key-value pairs is used character `,`.

**Return:**

Object of class `String`.

**Example:**

```cpp
dict = new Dict(["One",1,"Two",2,"Three",3]);
("dict: %s\n" % dict.to_string()).print();
```
```
dict: [One:1,Two:2,Three:3]
```

#### Method `to_string#1`
Convert object of class `Dict` to object of class `String`. Each element of
dictionary is converted to string by call of its `to_string#0` method.  As separator
of string values of keys and elements is used character `:`.  As separator of
key-value pairs is used method parameter.

**Parameters:**

1. Object of class `String`.

**Return:**

Object of class `String`.

**Example:**

```cpp
dict = new Dict(["One",1,"Two",2,"Dict",new Dict(["One",1,"Two",2,"Three",3])]);
("dict: %s\n" % dict.to_string("+")).print();
("dict: %s\n" % dict.to_string("<->")).print();
```
```
dict: One:1+Two:2+Dict:[One:1,Two:2,Three:3]
dict: One:1<->Two:2<->Dict:[One:1,Two:2,Three:3]
```

#### Method `print#0`
Print string representation of object of class `Dict` to standard output.

**Return:**

Object of class `Blank`.

**Example:**

```cpp
dict = new Dict(["One",1,"Two",2,"Three",3]);
dict.print();
"\n".print();
```
```
[One:1,Two:2,Three:3]
```

