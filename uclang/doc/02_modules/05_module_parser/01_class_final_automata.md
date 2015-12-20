# Class FinalAutomata

Class implementing final automata designed for recognition
of terminal symbols in input source strings. Final automata can be used
for recognition of binary data sequences too.

-----

## Table of methods

* Constructors

  * Constructor [`FinalAutomata#1`](#FinalAutomata%231)

* Operators

  * Operator [`operator_binary_equal#1`](#operator_binary_equal%231)

* Methods

  * Method [`get_source#1`](#get_source%231)
  * Method [`to_string#0`](#to_string%230)
  * Method [`print#0`](#print%230)

-----

## Constructors

<a name="FinalAutomata#1" />

### Constructor [`FinalAutomata#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/parser_uclm/source_files/parser_module.cc#L355)

Creates final automata recognizing terminal symbols, from array of strings
describing regular expressions.

**Parameters:**

1. Object of class `Array` containing objects of class `String` representing regular
expressions describing terminal symbols.

**Example:**

```cpp
obj = new FinalAutomata(
[
  "'0'.<07>*",
  "<19>.d*",
  "'0'.[xX].(<09>+<af>+<AF>).(<09>+<af>+<AF>)*",
  "('_'+l).('_'+l+d)*",
  "w.w*"
]);
("obj: %s\n" % obj.to_string()).print();
```
```
obj: FinalAutomata
```

-----

## Operators

<a name="operator_binary_equal#1" />

### Operator [`operator_binary_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/parser_uclm/source_files/parser_module.cc#L341)

Assignment operator `=`. Object of class `FinalAutomata` is replaced by method parameter.

**Parameters:**

1. Any type.

**Return:**

* Method parameter.

**Example:**

```cpp
obj = new FinalAutomata(
[
  "'0'.<07>*",
  "<19>.d*",
  "'0'.[xX].(<09>+<af>+<AF>).(<09>+<af>+<AF>)*",
  "('_'+l).('_'+l+d)*",
  "w.w*"
]);
("obj: %s\n" % obj.to_string()).print();
obj = "New value";
("obj: %s\n" % obj.to_string()).print();
```
```
obj: FinalAutomata
obj: New value
```

-----

## Methods

<a name="get_source#1" />

### Method [`get_source#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/parser_uclm/source_files/parser_module.cc#L434)

Create object of class `FaSource` that can be used for retrieval of terminal symbol indexes.

**Parameters:**

1. Object of class `String` representing source string in which terminals should be recognized.

**Return:**

* Object of class `FaSource`.

**Example:**

```cpp
fa = new FinalAutomata(["('_'+l).('_'+l+d)*","w.w*"]);
obj = fa.get_source("Hello world");
("obj: %s\n" % obj.to_string()).print();
```
```
obj: FaSource
```

<a name="to_string#0" />

### Method `spec` `static` [`to_string#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/parser_uclm/source_files/parser_module.cc#L466)

Convert object of class `FinalAutomata` to object of class `String`.
This method returns name of class `FinalAutomata`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
("FinalAutomata.to_string(): %s\n" % FinalAutomata.to_string()).print();
```
```
FinalAutomata.to_string(): FinalAutomata
```

<a name="print#0" />

### Method `spec` `static` [`print#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/parser_uclm/source_files/parser_module.cc#L475)

Print string representation of object of class `FinalAutomata` to standard output.
This method prints name of class `FinalAutomata`.

**Return:**

* Object of class `Blank`.

**Example:**

```cpp
FinalAutomata.print();
"\n".print();
```
```
FinalAutomata
```
