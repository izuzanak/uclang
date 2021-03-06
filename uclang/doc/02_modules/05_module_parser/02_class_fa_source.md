# Class FaSource

Class of objects representing reference to object of class
`FinalAutomata` and object of class `String`. Object also holds information about position
of last recognized terminal symbol.

-----

## Table of methods

* Operators

  * Operator [`operator_binary_equal#1`](#operator_binary_equal%231)

* Methods

  * Method [`next_terminal#0`](#next_terminal%230)
  * Method [`old_input_idx#0`](#old_input_idx%230)
  * Method [`input_idx#0`](#input_idx%230)
  * Method [`terminal#2`](#terminal%232)
  * Method [`terminal_length#0`](#terminal_length%230)
  * Method [`next_item#0`](#next_item%230)
  * Method [`to_string#0`](#to_string%230)
  * Method [`print#0`](#print%230)

-----

## Operators

<a name="operator_binary_equal#1" />

### Operator [`operator_binary_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/parser_uclm/source_files/parser_module.cc#L601)

Assignment operator `=`. Object of class `FaSource` is replaced by method parameter.

**Parameters:**

1. Any type.

**Return:**

* Method parameter.

**Example:**

```cpp
fa = new FinalAutomata(["('_'+l).('_'+l+d)*","w.w*"]);
obj = fa.get_source("hello world");
("obj: %s\n" % $obj).print();
obj = "New value";
("obj: %s\n" % $obj).print();
```
```
obj: FaSource
obj: New value
```

-----

## Methods

<a name="next_terminal#0" />

### Method [`next_terminal#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/parser_uclm/source_files/parser_module.cc#L613)

Retrieve next terminal symbol identified by object of class `Integer`. If no terminal
symbol was recognized, method will return object of class `Blank`.

**Return:**

* Object of class `Integer` if next terminal symbol was recognized. Integer represents index in original array of regular expressions used to create object of class `FinalAtomata`.
* Object of class `Blank` if next terminal symbol was not recognized.

**Example:**

```cpp
fa = new FinalAutomata(["('_'+l).('_'+l+d)*","w.w*"]);
obj = fa.get_source("hello world");
("obj: %s\n" % $obj).print();
while(Blank != (term = obj.next_terminal()))
{
  ("terminal: %d\n" % term).print();
}
```
```
obj: FaSource
terminal: 0
terminal: 1
terminal: 0
```

<a name="old_input_idx#0" />

### Method [`old_input_idx#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/parser_uclm/source_files/parser_module.cc#L618)

Retrieve index in source string that refers to beginning of last recognized terminal symbol.

**Return:**

* Object of class `Integer` representing index in source string that refers to beginning of last recognized terminal symbol.

**Example:**

```cpp
fa = new FinalAutomata(["('_'+l).('_'+l+d)*","w.w*"]);
obj = fa.get_source("hello world");
("obj: %s\n" % $obj).print();
while(Blank != (term = obj.next_terminal()))
{
  ("obj.old_input_idx(): %d\n" % obj.old_input_idx()).print();
}
```
```
obj: FaSource
obj.old_input_idx(): 0
obj.old_input_idx(): 5
obj.old_input_idx(): 6
```

<a name="input_idx#0" />

### Method [`input_idx#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/parser_uclm/source_files/parser_module.cc#L631)

Retrieve index in source string referring to first character that was not yet processed by final automata.

**Return:**

* Object of class `Integer` representing index in source string referring to first character that was not yet processed by final automata.

**Example:**

```cpp
fa = new FinalAutomata(["('_'+l).('_'+l+d)*","w.w*"]);
obj = fa.get_source("hello world");
("obj: %s\n" % $obj).print();
while(Blank != (term = obj.next_terminal()))
{
  ("obj.input_idx(): %d\n" % obj.input_idx()).print();
}
```
```
obj: FaSource
obj.input_idx(): 5
obj.input_idx(): 6
obj.input_idx(): 11
```

<a name="terminal#2" />

### Method [`terminal#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/parser_uclm/source_files/parser_module.cc#L644)

Retrieve string that was recognized as last terminal symbol by final automata.

**Parameters:**

1. Type convertible to integer, representing offset from terminal begin.
2. Type convertible to integer, representing offset from terminal end.

**Return:**

* Object of class `String` representing last symbol recognized by final automata.

**Example:**

```cpp
fa = new FinalAutomata(["('_'+l).('_'+l+d)*","w.w*"]);
obj = fa.get_source("hello world");
("obj: %s\n" % $obj).print();
while(Blank != (term = obj.next_terminal()))
{
  ("obj.terminal(0,0): %s\n" % obj.terminal(0,0)).print();
}
```
```
obj: FaSource
obj.terminal(0,0): hello
obj.terminal(0,0):  
obj.terminal(0,0): world
```

<a name="terminal_length#0" />

### Method [`terminal_length#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/parser_uclm/source_files/parser_module.cc#L675)

Retrieve length of last terminal symbol recognized by final automata.

**Return:**

* Object of class `Integer` representing length of last terminal symbol recognized by final automata.

**Example:**

```cpp
fa = new FinalAutomata(["('_'+l).('_'+l+d)*","w.w*"]);
obj = fa.get_source("hello world");
("obj: %s\n" % $obj).print();
while(Blank != (term = obj.next_terminal()))
{
  ("obj.terminal_length(): %d\n" % obj.terminal_length()).print();
}
```
```
obj: FaSource
obj.terminal_length(): 5
obj.terminal_length(): 1
obj.terminal_length(): 5
```

<a name="next_item#0" />

### Method `spec` [`next_item#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/parser_uclm/source_files/parser_module.cc#L688)

Retrieve next terminal symbol identified by object of class `Integer`. If no terminal symbol was recognized, method will return object of class `Blank`. Presence of this method implies that object of class `FaSource` is iterable.

**Return:**

* Object of class `Integer` if next terminal symbol was recognized. Integer represents index in original array of regular expressions used to create object of class `FinalAtomata`.
* Object of class `Blank` if next terminal symbol was not recognized.

**Example:**

```cpp
fa = new FinalAutomata(["('_'+l).('_'+l+d)*","w.w*"]);
obj = fa.get_source("hello world");
("obj: %s\n" % $obj).print();
for (term <- obj)
{
  ("terminal: %d\n" % term).print();
}
```
```
obj: FaSource
terminal: 0
terminal: 1
terminal: 0
```

<a name="to_string#0" />

### Method `spec` `static` [`to_string#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/parser_uclm/source_files/parser_module.cc#L693)

Convert object of class `FaSource` to object of class `String`.
This method returns name of class `FaSource`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
("FaSource.to_string(): %s\n" % FaSource.to_string()).print();
```
```
FaSource.to_string(): FaSource
```

<a name="print#0" />

### Method `spec` `static` [`print#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/parser_uclm/source_files/parser_module.cc#L702)

Print string representation of object of class `FaSource` to standard output.
This method prints name of class `FaSource`.

**Return:**

* Object of class `FaSource`.

**Example:**

```cpp
FaSource.print();
"\n".print();
```
```
FaSource
```
