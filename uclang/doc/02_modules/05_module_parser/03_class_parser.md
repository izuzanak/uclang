
# Class Parser
Class implementing parser capable to perform lexical and syntactical analysis
of input strings. Parser construction is based on string containing description
of language terminal symbols and its grammar rules.

## Language rules string
> FIXME TODO continue ...

## Constructors

#### Constructor `Parser#1`
Creates parser based on string containing description of language terminal
symbols and its grammar rules.

**Parameters:**

1. Object of class `String` containing description of language terminal symbols
   and its grammar rules.

**Example:**

```cpp
parser = new Parser("
  init_code: {}
  terminals: id {('_'+l).('_'+l+d)*} excl {'!'} _SKIP_ {w.w*} _END_ {'\\0'}
  nonterminals: <start> <exp>
  rules:
    <start> -> <exp> _END_ ->> {}
    <exp> -> excl <exp>    ->> {}
    <exp> -> id            ->> {}
");
("parser: %s\n" % parser.to_string()).print();
```
```
parser: Parser
```

## Operators

#### Operator `operator_binary_equal#1`
Assignment operator `=`. Object of class `Parser` is replaced by method
parameter.

**Parameters:**

1. Any type.

**Return:**

Value of object.

**Example:**

```cpp
parser = new Parser("
  init_code: {}
  terminals: id {('_'+l).('_'+l+d)*} excl {'!'} _SKIP_ {w.w*} _END_ {'\\0'}
  nonterminals: <start> <exp>
  rules:
    <start> -> <exp> _END_ ->> {}
    <exp> -> excl <exp>    ->> {}
    <exp> -> id            ->> {}
");
("parser: %s\n" % parser.to_string()).print();
parser = "Hello world";
("parser: %s\n" % parser.to_string()).print();
```
```
parser: Parser
parser: Hello world
```

## Methods

#### Method `parse#2`
Parse source string given as first method parameter, and for each reduction
occurred according to language grammar rules, call delegate given as second
method parameter. Delegate accepts one parameter represented by object of class
`ParseState`.

**Parameters:**

1. Object of class `String` representing string to be parsed by parser.
2. Object of class `Delegate` to be called when reduction according to language
   grammar rule has occur.

**Return:**

Object of class `Blank`.

**Example:**

```cpp
parser = new Parser("
  init_code: {}
  terminals: id {('_'+l).('_'+l+d)*} excl {'!'} _SKIP_ {w.w*} _END_ {'\\0'}
  nonterminals: <start> <exp>
  rules:
    <start> -> <exp> _END_ ->> {}
    <exp> -> excl <exp>    ->> {}
    <exp> -> id            ->> {}
");
parser.parse("!!!!test",new Delegate(this,"parse_cb",1));
```

Complete parser demo is introduced in script:
[Parser demo](https://github.com/izuzanak/uclang/blob/master/uclang_build/scripts/examples/demo_parser.ucl)

#### Method `to_string#0`
Convert object of class `Parser` to object of class `String`.  This
method returns name of class `Parser`.

**Return:**

Object of class `String`.

**Example:**

```cpp
parser = new Parser("
  init_code: {}
  terminals: id {('_'+l).('_'+l+d)*} excl {'!'} _SKIP_ {w.w*} _END_ {'\\0'}
  nonterminals: <start> <exp>
  rules:
    <start> -> <exp> _END_ ->> {}
    <exp> -> excl <exp>    ->> {}
    <exp> -> id            ->> {}
");
("parser: %s\n" % parser.to_string()).print();
```
```
parser: Parser
```

#### Method `print#0`
Print string representation of object of class `Parser` to standard
output. This method prints name of class `Parser`.

**Return:**

Object of class `Blank`.

**Example:**

```cpp
parser = new Parser("
  init_code: {}
  terminals: id {('_'+l).('_'+l+d)*} excl {'!'} _SKIP_ {w.w*} _END_ {'\\0'}
  nonterminals: <start> <exp>
  rules:
    <start> -> <exp> _END_ ->> {}
    <exp> -> excl <exp>    ->> {}
    <exp> -> id            ->> {}
");
parser.print();
"\n".print();
```
```
Parser
```

