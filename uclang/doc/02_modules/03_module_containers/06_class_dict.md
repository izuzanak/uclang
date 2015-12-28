# Class Dict

Container class implementing abstract data type dictionary.

-----

## Table of methods

* Constructors

  * Constructor [`Dict#0`](#Dict%230)
  * Constructor [`Dict#1`](#Dict%231)

* Operators

  * Operator [`operator_binary_equal#1`](#operator_binary_equal%231)
  * Operator [`operator_binary_double_equal#1`](#operator_binary_double_equal%231)
  * Operator [`operator_binary_exclamation_equal#1`](#operator_binary_exclamation_equal%231)
  * Operator [`operator_binary_le_br_re_br#1`](#operator_binary_le_br_re_br%231)

* Methods

  * Method [`clear#0`](#clear%230)
  * Method [`keys#0`](#keys%230)
  * Method [`items#0`](#items%230)
  * Method [`store_ref#2`](#store_ref%232)
  * Method [`has_key#1`](#has_key%231)
  * Method [`remove_key#1`](#remove_key%231)
  * Method [`first_key#0`](#first_key%230)
  * Method [`last_key#0`](#last_key%230)
  * Method [`next_key#1`](#next_key%231)
  * Method [`prev_key#1`](#prev_key%231)
  * Method [`lee_key#1`](#lee_key%231)
  * Method [`gre_key#1`](#gre_key%231)
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

<a name="Dict#0" />

### Constructor [`Dict#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_dict.cc#L693)

Creates default object of class `Dict`.

**Example:**

```cpp
obj = new Dict();
("obj: %s\n" % obj.to_string()).print();
```
```
obj: []
```

<a name="Dict#1" />

### Constructor [`Dict#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_dict.cc#L698)

Creates object of class `Dict` based on elements retrieved from method
parameter. Values of parameter elements represents alternating keys and values
of new object of class `Dict`.

**Parameters:**

1. Iterable type.

**Example:**

```cpp
obj = new Dict(["One",1,"Two",2,"Three",3]);
("obj: %s\n" % obj.to_string()).print();
```
```
obj: [One:1,Two:2,Three:3]
```

-----

## Operators

<a name="operator_binary_equal#1" />

### Operator [`operator_binary_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_dict.cc#L598)

Assignment operator `=`. Object of class `Dict` is replaced by method parameter.

**Parameters:**

1. Any type.

**Return:**

* Method parameter.

**Example:**

```cpp
obj = new Dict(["One",1,"Two",2,"Three",3]);
("obj: %s\n" % obj.to_string()).print();
obj = "New value";
("obj: %s\n" % obj.to_string()).print();
```
```
obj: [One:1,Two:2,Three:3]
obj: New value
```

<a name="operator_binary_double_equal#1" />

### Operator [`operator_binary_double_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_dict.cc#L614)

Comparison operator `==`. Compares object of class `Dict` with method parameter and return `1` if objects has same value or `0` otherwise.

**Parameters:**

1. Any type.

**Return:**

* Object of class `Integer`.
  * `0` - method parameter has different value than object.
  * `1` - method parameter has same value as object.

**Example:**

```cpp
obj_0 = new Dict(["One",1,"Two",2,"Three",3]);
obj_1 = new Dict(["One",1,"Two",2,"Three",3,"Four",4]);
obj_2 = obj_0;
("obj_0 == obj_1: %d\n" % (obj_0 == obj_1)).print();
("obj_0 == obj_2: %d\n" % (obj_0 == obj_2)).print();
```
```
obj_0 == obj_1: 0
obj_0 == obj_2: 1
```

<a name="operator_binary_exclamation_equal#1" />

### Operator [`operator_binary_exclamation_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_dict.cc#L631)

Comparison operator `!=`. Compares object of class `Dict` with method parameter and return `0` if objects has same value or `1` otherwise.

**Parameters:**

1. Any type.

**Return:**

* Object of class `Integer`.
  * `0` - method parameter has same value as object.
  * `1` - method parameter has different value than object.

**Example:**

```cpp
obj_0 = new Dict(["One",1,"Two",2,"Three",3]);
obj_1 = new Dict(["One",1,"Two",2,"Three",3,"Four",4]);
obj_2 = obj_0;
("obj_0 != obj_1: %d\n" % (obj_0 != obj_1)).print();
("obj_0 != obj_2: %d\n" % (obj_0 != obj_2)).print();
```
```
obj_0 != obj_1: 1
obj_0 != obj_2: 0
```

<a name="operator_binary_le_br_re_br#1" />

### Operator [`operator_binary_le_br_re_br#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_dict.cc#L648)

Item selection operator `[]`.
Retrieve element from object of class `Dict` stored at requested key position.

**Parameters:**

1. Any type.

**Return:**

 * Object stored in object of class `Dict` at position of requested key.

**Example:**

```cpp
obj = new Dict(["One",1,"Two",2,"Three",3]);
("obj: %s\n" % obj.to_string()).print();
("obj[\"One\"]: %s\n" % obj["One"].to_string()).print();
("obj[\"Two\"]: %s\n" % obj["Two"].to_string()).print();
```
```
obj: [One:1,Two:2,Three:3]
obj["One"]: 1
obj["Two"]: 2
```

-----

## Methods

<a name="clear#0" />

### Method [`clear#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_dict.cc#L722)

Release all elements stored in object of class `Dict`.

**Return:**

* Object of class `Blank`.

**Example:**

```cpp
obj = new Dict(["One",1,"Two",2,"Three",3]);
("obj: %s\n" % obj.to_string()).print();
obj.clear();
("obj: %s\n" % obj.to_string()).print();
```
```
obj: [One:1,Two:2,Three:3]
obj: []
```

<a name="keys#0" />

### Method [`keys#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_dict.cc#L755)

Retrieve keys contained in object of class `Dict`. Keys are returned as object of class `Array`.

**Return:**

* Object of class `Array` containing all keys.

**Example:**

```cpp
obj = new Dict(["One",1,"Two",2,"Three",3]);
("obj: %s\n" % obj.to_string()).print();
keys = obj.keys();
("type keys: %s\n" % (type keys).to_string()).print();
("keys: %s\n" % keys.to_string()).print();
```
```
obj: [One:1,Two:2,Three:3]
type keys: Array
keys: [One,Two,Three]
```

<a name="items#0" />

### Method [`items#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_dict.cc#L792)

Retrieve list of elements contained in object of class `Dict`. Elements are returned as object of class `Array`.

**Return:**

* Object of class `Array` containing all elements.

**Example:**

```cpp
obj = new Dict(["One",1,"Two",2,"Three",3]);
("obj: %s\n" % obj.to_string()).print();
items = obj.items();
("type items: %s\n" % (type items).to_string()).print();
("items: %s\n" % items.to_string()).print();
```
```
obj: [One:1,Two:2,Three:3]
type items: Array
items: [1,2,3]
```

<a name="store_ref#2" />

### Method [`store_ref#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_dict.cc#L826)

Store reference to second method parameter under key given by first method parameter in object of class `Dict`.

**Parameters:**

1. Any type.
2. Any type.

**Return:**

* Object of class `Blank`.

**Example:**

```cpp
obj = new Dict(["One",1,"Two",2,"Three",3]);
value = 0;
obj.store_ref("Value",value);
("obj: %s\n" % obj.to_string()).print();
value = "Hello world!";
("obj: %s\n" % obj.to_string()).print();
```
```
obj: [One:1,Two:2,Three:3,Value:0]
obj: [One:1,Two:2,Three:3,Value:Hello world!]
```

<a name="has_key#1" />

### Method [`has_key#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_dict.cc#L874)

Test if object of class `Dict` has key given by method parameter.

**Parameters:**

1. Any type.

**Return:**

Object of class `Integer`.
* `0` - object of class `Dict` does not have given key.
* `1` - object of class `Dict` has given key.


**Example:**

```cpp
obj = new Dict(["One",1,"Two",2,"Three",3]);
("obj: %s\n" % obj.to_string()).print();
("obj.has_key(\"Two\"): %d\n" % obj.has_key("Two")).print();
("obj.has_key(\"Three\"): %d\n" % obj.has_key("Three")).print();
("obj.has_key(\"Four\"): %d\n" % obj.has_key("Four")).print();
```
```
obj: [One:1,Two:2,Three:3]
obj.has_key("Two"): 1
obj.has_key("Three"): 1
obj.has_key("Four"): 0
```

<a name="remove_key#1" />

### Method [`remove_key#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_dict.cc#L901)

Remove key given by method parameter from object of class `Dict`. Value of object stored under key will be also removed.

**Parameters:**

1. Any type.

**Return:**

Object of class `Blank`.

**Example:**

```cpp
obj = new Dict(["One",1,"Two",2,"Three",3]);
("obj: %s\n" % obj.to_string()).print();
obj.remove_key("Two");
("obj: %s\n" % obj.to_string()).print();
```
```
obj: [One:1,Two:2,Three:3]
obj: [One:1,Three:3]
```

<a name="first_key#0" />

### Method [`first_key#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_dict.cc#L940)

Retrieve first key of object of class `Dict`.

**Return:**

* Value of first key of object of class `Dict` if it contains some elements.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = new Dict(["One",1,"Two",2,"Three",3]);
("obj.first_key(): %s\n" % obj.first_key().to_string()).print();
obj.remove_key(obj.first_key());
("obj.first_key(): %s\n" % obj.first_key().to_string()).print();
obj.clear();
("obj.first_key(): %s\n" % obj.first_key().to_string()).print();
```
```
obj.first_key(): One
obj.first_key(): Two
obj.first_key(): <blank>
```

<a name="last_key#0" />

### Method [`last_key#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_dict.cc#L966)

Retrieve last key of object of class `Dict`.

**Return:**

* Value of last key of object of class `Dict` if it contains some elements.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = new Dict(["One",1,"Two",2,"Three",3]);
("obj.last_key(): %s\n" % obj.last_key().to_string()).print();
obj.remove_key(obj.last_key());
("obj.last_key(): %s\n" % obj.last_key().to_string()).print();
obj.clear();
("obj.last_key(): %s\n" % obj.last_key().to_string()).print();
```
```
obj.last_key(): Three
obj.last_key(): Two
obj.last_key(): <blank>
```

<a name="next_key#1" />

### Method [`next_key#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_dict.cc#L992)

From object of class `Dict` retrieve key following key identified by method parameter.

**Parameters:**

1. Any type.

**Return:**

* Value of key following key identified by method parameter, if key identified by method parameter is not last key in object of class `Dict`.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = new Dict(["One",1,"Two",2,"Three",3]);
("obj: %s\n" % obj.to_string()).print();
key = obj.first_key();
do {
  ("key: %s\n" % key.to_string()).print();
  key = obj.next_key(key);
} while(Blank != key);
```
```
obj: [One:1,Two:2,Three:3]
key: One
key: Two
key: Three
```

<a name="prev_key#1" />

### Method [`prev_key#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_dict.cc#L1038)

From object of class `Dict` retrieve key preceding key identified by method parameter.

**Parameters:**

1. Any type.

**Return:**

* Value of key preceding key identified by method parameter, if key identified by method parameter is not first key in object of class `Dict`.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = new Dict(["One",1,"Two",2,"Three",3]);
("obj: %s\n" % obj.to_string()).print();
key = obj.last_key();
do {
  ("key: %s\n" % key.to_string()).print();
  key = obj.prev_key(key);
} while(Blank != key);
```
```
obj: [One:1,Two:2,Three:3]
key: Three
key: Two
key: One
```

<a name="lee_key#1" />

### Method [`lee_key#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_dict.cc#L1084)

Retrieve key of object of class `Dict` which value is less or equal than value of method parameter.

**Parameters:**

1. Any type.

**Return:**

* Value of key of object of class `Dict` which is less or equal than value of method parameter.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = new Dict([1.0,"One",2.0,"Two",3.0,"Three"]);
("obj.lee_key(0.6): %s\n" % obj.lee_key(0.6).to_string()).print();
("obj.lee_key(1.5): %s\n" % obj.lee_key(1.5).to_string()).print();
("obj.lee_key(2.1): %s\n" % obj.lee_key(2.1).to_string()).print();
```
```
obj.lee_key(0.6): <blank>
obj.lee_key(1.5): 1.000000
obj.lee_key(2.1): 2.000000
```

<a name="gre_key#1" />

### Method [`gre_key#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_dict.cc#L1120)

Retrieve key of object of class `Dict` which value is greater or equal than value of method parameter.

**Parameters:**

1. Any type.

**Return:**

* Value of key of object of class `Dict` which is greater or equal than value of method parameter.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = new Dict([1.0,"One",2.0,"Two",3.0,"Three"]);
("obj.gre_key(1.5): %s\n" % obj.gre_key(1.5).to_string()).print();
("obj.gre_key(2.1): %s\n" % obj.gre_key(2.1).to_string()).print();
("obj.gre_key(3.2): %s\n" % obj.gre_key(3.2).to_string()).print();
```
```
obj.gre_key(1.5): 2.000000
obj.gre_key(2.1): 3.000000
obj.gre_key(3.2): <blank>
```

<a name="contain#1" />

### Method `contain#1`

Test if object of class `Dict` contains key with same value as object given by method parameter.

**Parameters:**

1. Any type.

**Return:**

Object of class ``Integer``.
  * `0` - object of class `Dict` does not contain key equal to method parameter.
  * `1` - object of class `Dict` does contain key equal to method parameter.

**Example:**

```cpp
obj = new Dict(["One",1,"Two",2,"Three",3]);
("obj.contain(\"One\"): %d\n" % obj.contain("One")).print();
("obj.contain(\"Two\"): %d\n" % obj.contain("Two")).print();
("obj.contain(\"Seven\"): %d\n" % obj.contain("Seven")).print();
```
```
obj.contain("One"): 1
obj.contain("Two"): 1
obj.contain("Seven"): 0
```

<a name="compare#1" />

### Method `spec` [`compare#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_dict.cc#L1156)

Compare object of class `Dict` with method parameter.

**Parameters:**

1. Any type.

**Return:**

* Integer `-1` if object of class `Dict` is lesser than method parameter.
* Integer `1` if object of class `Dict` is greater than method parameter.
* Integer `0` if object of class `Dict` is equal to method parameter.

**Example:**

```cpp
obj_0 = new Dict(["One",1,"Two",2,"Three",3]);
obj_1 = new Dict(["One",1,"Two",2,"Three",3,"Four",4]);
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

### Method `spec` [`item#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_dict.cc#L1172)

Retrieve key from object of class `Dict` stored at requested index position.

**Parameters:**

1. Type convertible to integer.

**Return:**

* Object representing key in object of class `Dict` at position of requested index.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = new Dict(["One",1,"Two",2,"Three",3]);
("obj: %s\n" % obj.to_string()).print();
idx = obj.first_idx();
do {
  ("obj.item(%d): %s\n" % [idx,obj.item(idx).to_string()]).print();
  idx = obj.next_idx(idx);
} while(Blank != idx);
```
```
obj: [One:1,Two:2,Three:3]
obj.item(0): One
obj.item(2): Two
obj.item(3): Three
```

<a name="first_idx#0" />

### Method `spec` [`first_idx#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_dict.cc#L1202)

Retrieve index of first key in object of class `Dict`.

**Return:**

* Object of class `Integer` if object of class `Dict` contains some keys.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = new Dict(["One",1,"Two",2,"Three",3]);
("obj.first_idx: %s\n" % obj.first_idx().to_string()).print();
obj.clear();
("obj.first_idx: %s\n" % obj.first_idx().to_string()).print();
```
```
obj.first_idx: 0
obj.first_idx: <blank>
```

<a name="last_idx#0" />

### Method `spec` [`last_idx#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_dict.cc#L1225)

Retrieve index of last key in object of class `Dict`.

**Return:**

* Object of class `Integer` if object of class `Dict` contains some keys.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = new Dict(["One",1,"Two",2,"Three",3]);
("obj.last_idx: %s\n" % obj.last_idx().to_string()).print();
obj.clear();
("obj.last_idx: %s\n" % obj.last_idx().to_string()).print();
```
```
obj.last_idx: 3
obj.last_idx: <blank>
```

<a name="next_idx#1" />

### Method `spec` [`next_idx#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_dict.cc#L1248)

From object of class `Dict` retrieve index of key following key identified by method parameter.

**Parameters:**

1. Type convertible to integer.

**Return:**

* Object of class `Integer` if there is some key following key identified by method parameter.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = new Dict(["One",1,"Two",2,"Three",3]);
("obj: %s\n" % obj.to_string()).print();
idx = obj.first_idx();
do {
  ("idx: %s\n" % idx.to_string()).print();
  idx = obj.next_idx(idx);
} while(Blank != idx);
```
```
obj: [One:1,Two:2,Three:3]
idx: 0
idx: 2
idx: 3
```

<a name="prev_idx#1" />

### Method `spec` [`prev_idx#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_dict.cc#L1277)

From object of class `Dict` retrieve index of key preceding key identified by method parameter.

**Parameters:**

1. Type convertible to integer.

**Return:**

* Object of class `Integer` if there is some key preceding key identified by method parameter.
* Object of class `Blank` otherwise.

**Example:**

```cpp
obj = new Dict(["One",1,"Two",2,"Three",3]);
("obj: %s\n" % obj.to_string()).print();
idx = obj.last_idx();
do {
  ("idx: %s\n" % idx.to_string()).print();
  idx = obj.prev_idx(idx);
} while(Blank != idx);
```
```
obj: [One:1,Two:2,Three:3]
idx: 3
idx: 2
idx: 0
```

<a name="length#0" />

### Method `spec` [`length#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_dict.cc#L1306)

Retrieve count of keys in object of class `Dict`.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
obj = new Dict(["One",1,"Two",2,"Three",3]);
("obj.length(): %d\n" % obj.length()).print();
obj.clear();
("obj.length(): %d\n" % obj.length()).print();
```
```
obj.length(): 3
obj.length(): 0
```

<a name="to_string#0" />

### Method `spec` [`to_string#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_dict.cc#L1319)

Convert object of class `Dict` to object of class `String`.
Each key and element of object of class `Dict` is converted to string by call of
its `to_string#0` method. As separator of string values of keys and elements is
used character `:`. As separator of key-element pairs is used character `,`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
obj = new Dict(["One",1,"Two",2,"Three",3]);
("obj.to_string(): %s\n" % obj.to_string()).print();
```
```
obj.to_string(): [One:1,Two:2,Three:3]
```

<a name="to_string#1" />

### Method [`to_string#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_dict.cc#L1417)

Convert object of class `Dict` to object of class `String`.
Each key and element of object of class `Dict` is converted to string by call of
its `to_string#0` method. As separator of string values of keys and elements is
used character `:`. As separator of key-element pairs is used method parameter.

**Parameters:**

1. Object of class `String`. Separator of values formated to result string.

**Return:**

* Object of class `String`.

**Example:**

```cpp
obj = new Dict(["One",1,"Two",2,"Three",3]);
("obj.to_string(\"+\"): %s\n" % obj.to_string("+")).print();
("obj.to_string(\"<->\"): %s\n" % obj.to_string("<->")).print();
```
```
obj.to_string("+"): One:1+Two:2+Three:3
obj.to_string("<->"): One:1<->Two:2<->Three:3
```

<a name="print#0" />

### Method `spec` [`print#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/containers_uclm/source_files/containers_dict.cc#L1524)

Print string representation of object of class `Dict` to standard output.
Each key and element of object of class `Dict` is printed by call of its
`print#0` method. As separator of printed values of keys and elements is used
character `:`. As separator of key-element pairs is used character `,`.

**Return:**

* Object of class `Blank`.

**Example:**

```cpp
obj = new Dict(["One",1,"Two",2,"Three",3]);
obj.print();
"\n".print();
```
```
[One:1,Two:2,Three:3]
```
