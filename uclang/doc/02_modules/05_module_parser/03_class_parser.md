# Class Parser

Class implementing parser capable to perform lexical and
syntactical analysis of input strings. Parser construction is based on
string containing description of language terminal symbols and its
grammar rules.

Parser demo is introduced in script - [parser
demo](https://github.com/izuzanak/uclang/blob/master/uclang_build/scripts/examples/demo_parser.ucl).

-----

## Table of methods

* Constructors

  * Constructor [`Parser#1`](#Parser%231)

* Operators

  * Operator [`operator_binary_equal#1`](#operator_binary_equal%231)

* Methods

  * Method [`parse#2`](#parse%232)
  * Method [`to_string#0`](#to_string%230)
  * Method [`print#0`](#print%230)

-----

## Example context

All examples introduced below are executed in following context.

```cpp
class Main
{
  public parse_cb(a_state)
  {
    ("a_state.rule_idx(): %d\n" % a_state.rule_idx()).print();
  }

  public Main(a_argv)
  {
--------------------------------- example code ---------------------------------
  }

  public static main(argv)
  {
    new Main(argv);
  }
}
```

-----

## Constructors

<a name="Parser#1" />

### Constructor [`Parser#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/parser_uclm/source_files/parser_module.cc#L761)

Creates object of class `Parser` based on string containing description of language terminal
symbols and its grammar rules.

**Parameters:**

1. Object of class `String` containing description of language terminal symbols and
its grammar rules.

**Example:**

```cpp
obj = new Parser("
  init_code: {}
  terminals: id {('_'+l).('_'+l+d)*} excl {'!'} _SKIP_ {w.w*} _END_ {'\\0'}
  nonterminals: <start> <exp>
  rules:
    <start> -> <exp> _END_ ->> {}
    <exp> -> excl <exp>    ->> {}
    <exp> -> id            ->> {}
");
("obj: %s\n" % $obj).print();
```
```
obj: Parser
```

-----

## Operators

<a name="operator_binary_equal#1" />

### Operator [`operator_binary_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/parser_uclm/source_files/parser_module.cc#L747)

Assignment operator `=`. Object of class `Parser` is replaced by method parameter.

**Parameters:**

1. Any type.

**Return:**

* Method parameter.

**Example:**

```cpp
obj = new Parser("
  init_code: {}
  terminals: id {('_'+l).('_'+l+d)*} excl {'!'} _SKIP_ {w.w*} _END_ {'\\0'}
  nonterminals: <start> <exp>
  rules:
    <start> -> <exp> _END_ ->> {}
    <exp> -> excl <exp>    ->> {}
    <exp> -> id            ->> {}
");
("obj: %s\n" % $obj).print();
obj = "New value";
("obj: %s\n" % $obj).print();
```
```
obj: Parser
obj: New value
```

-----

## Methods

<a name="parse#2" />

### Method [`parse#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/parser_uclm/source_files/parser_module.cc#L811)

Parse source string given as first method parameter, and for each reduction
occurred according to language grammar rules, call delegate given as second
method parameter. Delegate accepts one parameter represented by object of class
`ParseState`.

**Parameters:**

1. Object of class `String` representing string to be parsed by parser.
2. Object of class `Delegate` to be called when reduction according to language grammar rule has occur.

**Return:**

* Object of class `Blank`.

**Example:**

```cpp
obj = new Parser("
  init_code: {}
  terminals: id {('_'+l).('_'+l+d)*} excl {'!'} _SKIP_ {w.w*} _END_ {'\\0'}
  nonterminals: <start> <exp>
  rules:
    <start> -> <exp> _END_ ->> {}
    <exp> -> excl <exp>    ->> {}
    <exp> -> id            ->> {}
");
obj.parse("!!test",new Delegate(this,"parse_cb",1));
```
```
a_state.rule_idx(): 2
a_state.rule_idx(): 1
a_state.rule_idx(): 1
```

<a name="to_string#0" />

### Method `spec` `static` [`to_string#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/parser_uclm/source_files/parser_module.cc#L884)

Convert object of class `Parser` to object of class `String`.
This method returns name of class `Parser`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
("Parser.to_string(): %s\n" % Parser.to_string()).print();
```
```
Parser.to_string(): Parser
```

<a name="print#0" />

### Method `spec` `static` [`print#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/parser_uclm/source_files/parser_module.cc#L893)

Print string representation of object of class `Parser` to standard output.
This method prints name of class `Parser`.

**Return:**

* Object of class `Blank`.

**Example:**

```cpp
Parser.print();
"\n".print();
```
```
Parser
```
