# Class Range

Class allowing creation of lazy object sequences.

-----

## Table of methods

* Constructors

  * Constructor [`Range#2`](#Range%232)
  * Constructor [`Range#3`](#Range%233)

* Operators

  * Operator [`operator_binary_equal#1`](#operator_binary_equal%231)

* Methods

  * Method [`next_item#0`](#next_item%230)
  * Method [`to_string#0`](#to_string%230)
  * Method [`print#0`](#print%230)

-----

## Constructors

<a name="Range#2" />

### Constructor [`Range#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/algorithms_uclm/source_files/algorithms_module.cc#L1812)

Creates object of class `Range`, based on first and last values of requested
sequence.

**Parameters:**

1. First value in generated sequence.
2. Last value in generated sequence.

**Example:**

```cpp
obj = new Range(1,10);
("obj: %s\n" % $obj).print();
("obj: %s\n" % $obj[::]).print();
```
```
obj: Range
obj: [1,2,3,4,5,6,7,8,9,10]
```

<a name="Range#3" />

### Constructor [`Range#3`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/algorithms_uclm/source_files/algorithms_module.cc#L1864)

Creates object of class `Range`, based on first, last and step value
of requested sequence.

**Parameters:**

1. First value in generated sequence.
2. Last value in generated sequence.
3. Step value of generated sequence.

**Example:**

```cpp
obj = new Range(0,-19,-2);
("obj: %s\n" % $obj).print();
("obj: %s\n" % $obj[::]).print();
```
```
obj: Range
obj: [0,-2,-4,-6,-8,-10,-12,-14,-16,-18]
```

-----

## Operators

<a name="operator_binary_equal#1" />

### Operator [`operator_binary_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/algorithms_uclm/source_files/algorithms_module.cc#L1798)

Assignment operator `=`. Object of class `Range` is replaced by method parameter.

**Parameters:**

1. Any type.

**Return:**

* Method parameter.

**Example:**

```cpp
obj = new Range(1,10);
("obj: %s\n" % $obj).print();
obj = "New value";
("obj: %s\n" % $obj).print();
```
```
obj: Range
obj: New value
```

-----

## Methods

<a name="next_item#0" />

### Method `spec` [`next_item#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/algorithms_uclm/source_files/algorithms_module.cc#L1912)

Retrieve next element from iterable object `Range`.

**Return:**

Next element from iterable object `Range`.

**Example:**

```cpp
obj = new Range(0,20,4);
while (Blank != (element = obj.next_item()))
{
  ("element: %d\n" % element).print();
}
```
```
element: 0
element: 4
element: 8
element: 12
element: 16
element: 20
```

<a name="to_string#0" />

### Method `spec` `static` [`to_string#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/algorithms_uclm/source_files/algorithms_module.cc#L1936)

Convert object of class `Range` to object of class `String`.
This method returns name of class `Range`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
("Range.to_string(): %s\n" % Range.to_string()).print();
```
```
Range.to_string(): Range
```

<a name="print#0" />

### Method `spec` `static` [`print#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/algorithms_uclm/source_files/algorithms_module.cc#L1945)

Print string representation of object of class `Range` to standard output.
This method prints name of class `Range`.

**Return:**

* Object of class `Range`.

**Example:**

```cpp
Range.print();
"\n".print();
```
```
Range
```
