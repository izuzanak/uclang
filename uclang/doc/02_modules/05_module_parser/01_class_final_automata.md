
# Class FinalAutomata
Class implementing final automata designed for recognition of terminal symbols
in input source strings. Final automata can be used for recognition of
binary data sequences too.

## Regular expressions
> FIXME TODO continue ...

## Constructors

#### Constructor `FinalAutomata#1`
Creates final automata recognizing terminal symbols from array of strings
describing regular expressions.

**Parameters:**

1. Object of class `Array` containing objects of class `String` representing
   regular expressions describing terminal symbols.

**Example:**

```cpp
fa = new FinalAutomata(
[
  "'0'.<07>*",
  "<19>.d*",
  "'0'.[xX].(<09>+<af>+<AF>).(<09>+<af>+<AF>)*",
  "('_'+l).('_'+l+d)*",
  "w.w*"
]);
("fa: %s\n" % fa.to_string()).print();
```
```
fa: FinalAutomata
```

## Operators

#### Operator `operator_binary_equal#1`
Assignment operator `=`. Object of class `FinalAutomata` is replaced by method
parameter.

**Parameters:**

1. Any type.

**Return:**

Value of object.

**Example:**

```cpp
fa = new FinalAutomata(["('_'+l).('_'+l+d)*","w.w*"]);
("fa: %s\n" % fa.to_string()).print();
fa = "Hello world";
("fa: %s\n" % fa.to_string()).print();
```
```
fa: FinalAutomata
fa: Hello world
```

## Methods

#### Method `get_source#1`
Create object of class `FaSource` that can be used for retrieval of terminal
symbol indexes.

**Parameters:**

1. Object of class `String` representing source string in which terminals should
   be recognized.

**Return:**

Object of class `FaSource`.

**Example:**

```cpp
fa = new FinalAutomata(["('_'+l).('_'+l+d)*","w.w*"]);
fa_src = fa.get_source("Hello world");
("fa_src: %s\n" % fa_src.to_string()).print();

```
```
fa_src: FaSource
```

#### Method `to_string#0`
Convert object of class `FinalAutomata` to object of class `String`.  This
method returns name of class `FinalAutomata`.

**Return:**

Object of class `String`.

**Example:**

```cpp
fa = new FinalAutomata(["('_'+l).('_'+l+d)*","w.w*"]);
("fa: %s\n" % fa.to_string()).print();
```
```
fa: FinalAutomata
```

#### Method `print#0`
Print string representation of object of class `FinalAutomata` to standard
output. This method prints name of class `FinalAutomata`.

**Return:**

Object of class `Blank`.

**Example:**

```cpp
fa = new FinalAutomata(["('_'+l).('_'+l+d)*","w.w*"]);
fa.print();
"\n".print();
```
```
FinalAutomata
```

