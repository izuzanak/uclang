# Class ParseState

Objects of class `ParseState` describes parsing state related to
source string and object of class `Parser`. Object of class `ParseState` is acquired as
parameter of callback called from object of class `Parser`.

-----

## Table of methods

* Operators

  * Operator [`operator_binary_equal#1`](#operator_binary_equal%231)

* Methods

  * Method [`rule_idx#0`](#rule_idx%230)
  * Method [`rule_body#1`](#rule_body%231)
  * Method [`old_input_idx#0`](#old_input_idx%230)
  * Method [`input_idx#0`](#input_idx%230)
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
    --------------------------------- example code ---------------------------------
  }

  public Main(a_argv)
  {
    parser = new Parser("
      init_code: {}
      terminals: id {('_'+l).('_'+l+d)*} excl {'!'} _SKIP_ {w.w*} _END_ {'\\0'}
      nonterminals: <start> <exp>
      rules:
        <start> -> <exp> _END_ ->> {}
        <exp> -> excl <exp>    ->> {}
        <exp> -> id            ->> {}
    ");

    parser.parse("!!test",new Delegate(this,"parse_cb",1));
  }

  public static main(argv)
  {
    new Main(argv);
  }
}
```

-----

## Operators

<a name="operator_binary_equal#1" />

### Operator [`operator_binary_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/parser_uclm/source_files/parser_module.cc#L1012)

Assignment operator `=`. Object of class `ParseState` is replaced by method parameter.

**Parameters:**

1. Any type.

**Return:**

* Method parameter.

**Example:**

```cpp
obj = a_state;
("obj: %s\n" % $obj).print();
obj = "New value";
("obj: %s\n" % $obj).print();
```
```
obj: ParseState
obj: New value
obj: ParseState
obj: New value
obj: ParseState
obj: New value
```

-----

## Methods

<a name="rule_idx#0" />

### Method [`rule_idx#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/parser_uclm/source_files/parser_module.cc#L1024)

Retrieve index of rule according to which reduction occurred.

**Return:**

* Object of class `Integer` representing index of rule according to which reduction occurred.

**Example:**

```cpp
("a_state.rule_idx(): %d\n" % a_state.rule_idx()).print();
```
```
a_state.rule_idx(): 2
a_state.rule_idx(): 1
a_state.rule_idx(): 1
```

<a name="rule_body#1" />

### Method [`rule_body#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/parser_uclm/source_files/parser_module.cc#L1044)

Retrieve substring of parsed source string which is represented by item in
rule body at position identified by index given as method parameter.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float` representing index of rule item.

**Return:**

* Object of class `String`.

**Example:**

```cpp
if (a_state.rule_idx() == 1)
  ("%s - %s\n" % [a_state.rule_body(0),a_state.rule_body(1)]).print();
else
  ("%s\n" % a_state.rule_body(0)).print();
```
```
test
! - test
! - !test
```

<a name="old_input_idx#0" />

### Method [`old_input_idx#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/parser_uclm/source_files/parser_module.cc#L1089)

Retrieve index to source string that refers to beginning of last recognized
terminal symbol.

**Return:**

* Object of class `Integer` representing index to source string that refers to
  beginning of last recognized terminal symbol.

**Example:**

```cpp
("a_state.old_input_idx(): %d\n" % a_state.old_input_idx()).print();
```
```
a_state.old_input_idx(): 6
a_state.old_input_idx(): 6
a_state.old_input_idx(): 6
```

<a name="input_idx#0" />

### Method [`input_idx#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/parser_uclm/source_files/parser_module.cc#L1109)

Retrieve index to source string referring to first character that was not yet
processed by parser.

**Return:**

* Object of class `Integer` representing index to source string referring to
  first character that was not yet processed by parser.

**Example:**

```cpp
("a_state.input_idx(): %d\n" % a_state.input_idx()).print();
```
```
a_state.input_idx(): 6
a_state.input_idx(): 6
a_state.input_idx(): 6
```

<a name="to_string#0" />

### Method `spec` `static` [`to_string#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/parser_uclm/source_files/parser_module.cc#L1129)

Convert object of class `ParseState` to object of class `String`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
("ParseState.to_string(): %s\n" % ParseState.to_string()).print();
```
```
ParseState.to_string(): ParseState
ParseState.to_string(): ParseState
ParseState.to_string(): ParseState
```

<a name="print#0" />

### Method `spec` `static` [`print#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/parser_uclm/source_files/parser_module.cc#L1138)

Print string representation of object of class `ParseState` to standard output.

**Return:**

* Object of class `ParseState`.

**Example:**

```cpp
ParseState.print();
"\n".print();
```
```
ParseState
ParseState
ParseState
```
