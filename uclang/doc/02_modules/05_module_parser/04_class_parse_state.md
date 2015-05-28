
# Class ParseState
Objects of class `ParseState` describes parsing state related to source string
and object of class `Parser`. Object of class `ParseState` is acquired as
parameter of callback called from object of class `Parser`.

## Operators

#### Operator `operator_binary_equal#1`
Assignment operator `=`. Object of class `ParseState` is replaced by method
parameter.

**Parameters:**

1. Any type.

**Return:**

Value of object.

**Example:**

```cpp
public parse_cb(a_state)
{
  a_state = "Hello world";
  ("a_state: %s\n" % a_state.to_string()).print();
}
```
```
a_state: Hello world
a_state: Hello world
a_state: Hello world
a_state: Hello world
a_state: Hello world
```

## Methods

#### Method `rule_idx#0`
Retrieve index of rule according to which reduction occurred.

**Return:**

Object of class `Integer` representing index of rule according to which
reduction occurred.

**Example:**

```cpp
public parse_cb(a_state)
{
  ("a_state.rule_idx(): %d\n" % a_state.rule_idx()).print();
}
```
```
a_state.rule_idx(): 2
a_state.rule_idx(): 1
a_state.rule_idx(): 1
a_state.rule_idx(): 1
a_state.rule_idx(): 1
```

#### Method `rule_body#1`
Retrieve object of class `String` representing substring of parsed source
string which is represented by item in rule body at position identified by
index given as method parameter.

**Parameters:**

1. Object of class `Integer` representing index of rule item. Items are indexed
   from `0`, where `0` is leftmost item in rule body.

**Return:**

Object of class `String` representing substring of parsed source string which
is represented by item in rule body at position identified by index given as
method parameter.

**Example:**

```cpp
public parse_cb(a_state)
{
  if (a_state.rule_idx() == 1)
  {
    ("%s - %s\n" % [a_state.rule_body(0),a_state.rule_body(1)]).print();
  }
  else
  {
    ("%s\n" % a_state.rule_body(0)).print();
  }
}
```
```
test
! - test
! - !test
! - !!test
! - !!!test
```

#### Method `old_input_idx#0`
Retrieve index to source string that refers to beginning of last recognized
terminal symbol.

**Return:**

Object of class `Integer` representing index to source string that refers to
beginning of last recognized terminal symbol.

**Example:**

```cpp
public parse_cb(a_state)
{
  ("a_state.old_input_idx(): %d\n" % a_state.old_input_idx()).print();
}
```
```
a_state.old_input_idx(): 8
a_state.old_input_idx(): 8
a_state.old_input_idx(): 8
a_state.old_input_idx(): 8
a_state.old_input_idx(): 8
```

#### Method `input_idx#0`
Retrieve index to source string referring to first character that was not yet
processed by parser.

**Return:**

Object of class `Integer` representing index to source string referring to
first character that was not yet processed by parser.

**Example:**

```cpp
public parse_cb(a_state)
{
  ("a_state.input_idx(): %d\n" % a_state.input_idx()).print();
}
```
```
a_state.input_idx(): 8
a_state.input_idx(): 8
a_state.input_idx(): 8
a_state.input_idx(): 8
a_state.input_idx(): 8
```

#### Method `to_string#0`
Convert object of class `ParseState` to object of class `String`.  This
method returns name of class `ParseState`.

**Return:**

Object of class `String`.

**Example:**

```cpp
public parse_cb(a_state)
{
  ("a_state: %s\n" % a_state.to_string()).print();
}
```
```
a_state: ParseState
a_state: ParseState
a_state: ParseState
a_state: ParseState
a_state: ParseState
```

#### Method `print#0`
Print string representation of object of class `ParseState` to standard
output. This method prints name of class `ParseState`.

**Return:**

Object of class `Blank`.

**Example:**

```cpp
public parse_cb(a_state)
{
  a_state.print();
  "\n".print();
}
```
```
a_state: ParseState
a_state: ParseState
a_state: ParseState
a_state: ParseState
a_state: ParseState
```

