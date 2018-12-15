# Class Filter

Class implementing lazy algorithms for processing of
iterable types.

-----

## Table of methods

* Operators

  * Operator [`operator_binary_equal#1`](#operator_binary_equal%231)

* Methods

  * Method [`map#2`](#map%232)
  * Method [`filter#2`](#filter%232)
  * Method [`next_item#0`](#next_item%230)
  * Method [`to_string#0`](#to_string%230)
  * Method [`print#0`](#print%230)

-----

## Operators

<a name="operator_binary_equal#1" />

### Operator [`operator_binary_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/algorithms_uclm/source_files/algorithms_module.cc#L1743)

Assignment operator `=`. Object of class `Filter` is replaced by method parameter.

**Parameters:**

1. Any type.

**Return:**

* Method parameter.

**Example:**

```cpp
obj = Filter.map([0,1,2],["Zero","One","Two"]);
("obj: %s\n" % $obj).print();
obj = "New value";
("obj: %s\n" % $obj).print();
```
```
obj: Filter
obj: New value
```

-----

## Methods

<a name="map#2" />

### Method `static` [`map#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/algorithms_uclm/source_files/algorithms_module.cc#L1755)

Creates object of type `Filter` representing iterable containing elements
from input iterable object transformed by given map function.

**Parameters:**

1. Iterable type.
2. Map function represented by object of class `Array`, `Dict` or `Delegate`.

**Return:**

Object of class `Filter` representing iterable containing elements from input
iterable object transformed by given map function.

**Example:**

```cpp
result = Filter.map([0,1,2,1,0,2],["Zero","One","Two"]);
("result: %s\n" % $result[::]).print();
result = Filter.map([0,1,1000,1,0,1000],new Dict([0,"Zero",1,"One",1000,"One thousand"]));
("result: %s\n" % $result[::]).print();
result = Filter.map(new Range(1,5),:(size) return new Integer[size];);
("result: %s\n" % $result[::]).print();
```
```
result: [Zero,One,Two,One,Zero,Two]
result: [Zero,One,One thousand,One,Zero,One thousand]
result: [[0],[0,0],[0,0,0],[0,0,0,0],[0,0,0,0,0]]
```

<a name="filter#2" />

### Method `static` [`filter#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/algorithms_uclm/source_files/algorithms_module.cc#L1760)

Creates object of type `Filter` representing iterable containing elements from
input iterable object for which filter function returns true.

**Parameters:**

1. Iterable type.
2. Filter function represented by object of class `Array`, `Dict` or `Delegate`.

**Return:**

Object of class `Filter` representing iterable containing elements from
input iterable object for which filter function returns true.

**Example:**

```cpp
result = Filter.filter([0,1,2,1,0,2],[0,0,1]);
("result: %s\n" % $result[::]).print();
result = Filter.filter([0,1,1000,1,0,1000],new Dict([0,1,1,1,1000,0]));
("result: %s\n" % $result[::]).print();
result = Filter.filter(new Range(1,10),:(value) return value & 1;);
("result: %s\n" % $result[::]).print();
```
```
result: [2,2]
result: [0,1,1,0]
result: [1,3,5,7,9]
```

<a name="next_item#0" />

### Method `spec` [`next_item#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/algorithms_uclm/source_files/algorithms_module.cc#L1765)

Retrieve next element from iterable object `Filter`.

**Return:**

Next element from iterable object `Filter`.

**Example:**

```cpp
obj = Filter.map([0,1,2],["Zero","One","Two"]);
while (Blank != (element = obj.next_item()))
{
  ("element: %s\n" % element).print();
}
```
```
element: Zero
element: One
element: Two
```

<a name="to_string#0" />

### Method `spec` `static` [`to_string#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/algorithms_uclm/source_files/algorithms_module.cc#L1780)

Convert object of class `Filter` to object of class `String`.
This method returns name of class `Filter`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
("Filter.to_string(): %s\n" % Filter.to_string()).print();
```
```
Filter.to_string(): Filter
```

<a name="print#0" />

### Method `spec` `static` [`print#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/algorithms_uclm/source_files/algorithms_module.cc#L1789)

Print string representation of object of class `Filter` to standard output.
This method prints name of class `Filter`.

**Return:**

* Object of class `Filter`.

**Example:**

```cpp
Filter.print();
"\n".print();
```
```
Filter
```
