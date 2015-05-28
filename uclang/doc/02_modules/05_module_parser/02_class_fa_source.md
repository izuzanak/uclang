
# Class FaSource
Object representing reference to object of class `FinalAutomata` and object of
class `String`. Object also holds information about position of last recognized
terminal symbol.

## Operators

#### Operator `operator_binary_equal#1`
Assignment operator `=`. Object of class `FaSource` is replaced by method
parameter.

**Parameters:**

1. Any type.

**Return:**

Value of object.

**Example:**

```cpp
fa = new FinalAutomata(["('_'+l).('_'+l+d)*","w.w*"]);
fa_src = fa.get_source("hello world");
("fa_src: %s\n" % fa_src.to_string()).print();
fa_src = "Hello world";
("fa_src: %s\n" % fa_src.to_string()).print();
```
```
fa_src: FaSource
fa_src: Hello world
```

## Methods

#### Method `next_terminal#0`
Retrieve next terminal symbol identified by object of class `Integer`. If no
terminal symbol was recognized, method will return object of class `Blank`.

**Return:**

* Object of class `Integer` if next terminal symbol was recognized. Integer
  represents index in original array of regular expressions used to create
  object of class `FinalAutomata`.
* Object of class `Blank` if next terminal symbol was not recognized.

**Example:**

```cpp
fa = new FinalAutomata(["('_'+l).('_'+l+d)*","w.w*"]);
fa_src = fa.get_source("hello world");
while(Blank != (term = fa_src.next_terminal()))
{
  ("terminal: %d\n" % term).print();
}
```
```
terminal: 0
terminal: 1
terminal: 0
```

#### Method `old_input_idx#0`
Retrieve index to source string that refers to beginning of last recognized
terminal symbol.

**Return:**

Object of class `Integer` representing index to source string that refers to
beginning of last recognized terminal symbol.

**Example:**

```cpp
fa = new FinalAutomata(["('_'+l).('_'+l+d)*","w.w*"]);
fa_src = fa.get_source("hello world");
while(Blank != fa_src.next_terminal())
{
  ("fa_src.old_input_idx(): %d\n" % fa_src.old_input_idx()).print();
}
```
```
fa_src.old_input_idx(): 0
fa_src.old_input_idx(): 5
fa_src.old_input_idx(): 6
```

#### Method `input_idx#0`
Retrieve index to source string referring to first character that was not yet
processed by final automata.

**Return:**

Object of class `Integer` representing index to source string referring to
first character that was not yet processed by final automata.

**Example:**

```cpp
fa = new FinalAutomata(["('_'+l).('_'+l+d)*","w.w*"]);
fa_src = fa.get_source("hello world");
while(Blank != fa_src.next_terminal())
{
  ("fa_src.input_idx(): %d\n" % fa_src.input_idx()).print();
}
```
```
fa_src.input_idx(): 5
fa_src.input_idx(): 6
fa_src.input_idx(): 11
```

#### Method `next_item#0`
Retrieve next terminal symbol identified by object of class `Integer`. If no
terminal symbol was recognized, method will return object of class `Blank`.
Presence of this method implies that object of class `FaSource` is iterable.

**Return:**

* Object of class `Integer` if next terminal symbol was recognized. Integer
  represents index in original array of regular expressions used to create
  object of class `FinalAutomata`.
* Object of class `Blank` if next terminal symbol was not recognized.

**Example:**

```cpp
fa = new FinalAutomata(["('_'+l).('_'+l+d)*","w.w*"]);
fa_src = fa.get_source("hello world");
for (term <- fa_src)
{
  ("terminal: %d\n" % term).print();
}
```
```
terminal: 0
terminal: 1
terminal: 0
```

#### Method `to_string#0`
Convert object of class `FaSource` to object of class `String`.  This
method returns name of class `FaSource`.

**Return:**

Object of class `String`.

**Example:**

```cpp
fa = new FinalAutomata(["('_'+l).('_'+l+d)*","w.w*"]);
fa_src = fa.get_source("hello world");
("fa_src: %s\n" % fa_src.to_string()).print();
```
```
fa: FaSource
```

#### Method `print#0`
Print string representation of object of class `FaSource` to standard
output. This method prints name of class `FaSource`.

**Return:**

Object of class `Blank`.

**Example:**

```cpp
fa = new FinalAutomata(["('_'+l).('_'+l+d)*","w.w*"]);
fa_src = fa.get_source("hello world");
fa_src.print();
"\n".print();
```
```
FaSource
```

