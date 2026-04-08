# Class Regex

Class implementing POSIX regular expression matching.

-----

## Table of methods

* Constructors

  * Constructor [`Regex#1`](#Regex%231)

* Operators

  * Operator [`operator_binary_equal#1`](#operator_binary_equal%231)

* Methods

  * Method [`match#1`](#match%231)
  * Method [`match#2`](#match%232)
  * Method [`match_from#2`](#match_from%232)
  * Method [`split#1`](#split%231)
  * Method [`replace#2`](#replace%232)
  * Method [`to_string#0`](#to_string%230)
  * Method [`print#0`](#print%230)

-----

## Constructors

<a name="Regex#1" />

### Constructor [`Regex#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/regex_uclm/source_files/regex_module.cc#L215)

Creates object of class `Regex` from regular expression pattern string.

**Parameters:**

1. Object of class `String` containing POSIX regular expression pattern.

**Example:**

```cpp
obj = new Regex("[0-9]+");
("obj: %s\n" % $obj).print();
```
```
obj: Regex
```

-----

## Operators

<a name="operator_binary_equal#1" />

### Operator [`operator_binary_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/regex_uclm/source_files/regex_module.cc#L203)

Assignment operator `=`. Object of class `Regex` is replaced by method parameter.

**Parameters:**

1. Any type.

**Return:**

* Method parameter.

**Example:**

```cpp
obj = new Regex("[0-9]+");
("obj: %s\n" % $obj).print();
obj = "New value";
("obj: %s\n" % $obj).print();
```
```
obj: Regex
obj: New value
```

-----

## Methods

<a name="match#1" />

### Method [`match#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/regex_uclm/source_files/regex_module.cc#L245)

Matches regular expression against input string. Returns array with start
and end positions of match, or object of class `Blank` if no match found.

**Parameters:**

1. Object of class `String` containing input string.

**Return:**

* Object of class `Array` containing start and end positions, or object of class `Blank`.

**Example:**

```cpp
obj = new Regex("[0-9]+");
res = obj.match("abc 123 def");
("match: %s\n" % $res).print();
res = obj.match("no digits");
("match: %s\n" % $res).print();
```
```
match: <blank>
match: <blank>
```

<a name="match#2" />

### Method [`match#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/regex_uclm/source_files/regex_module.cc#L302)

Matches regular expression against input string with capture groups. Returns
array of sub-arrays with start and end positions for each group, or object
of class `Blank` if no match found.

**Parameters:**

1. Object of class `String` containing input string.
2. Type convertible to integer representing number of capture groups.

**Return:**

* Object of class `Array` containing sub-arrays, or object of class `Blank`.

**Example:**

```cpp
obj = new Regex("([a-z]+) ([0-9]+)");
res = obj.match("abc 123",3);
("match: %s\n" % $res).print();
```
```
match: <blank>
```

<a name="match_from#2" />

### Method [`match_from#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/regex_uclm/source_files/regex_module.cc#L392)

Matches regular expression against input string starting at given byte offset.
Returns array with start and end positions (absolute), or object of class
`Blank` if no match found.

**Parameters:**

1. Object of class `String` containing input string.
2. Type convertible to integer representing byte offset from which to start matching.

**Return:**

* Object of class `Array` containing start and end positions, or object of class `Blank`.

**Example:**

```cpp
obj = new Regex("[0-9]+");
res = obj.match_from("abc 123 def 456",8);
("match: %s\n" % $res).print();
```
```
match: <blank>
```

<a name="split#1" />

### Method [`split#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/regex_uclm/source_files/regex_module.cc#L459)

Splits input string by regular expression pattern.

**Parameters:**

1. Object of class `String` containing input string.

**Return:**

* Object of class `Array` containing split parts.

**Example:**

```cpp
obj = new Regex("[ ,]+");
res = obj.split("one, two, three");
("parts: %s\n" % $res).print();
```
```
parts: [one, two, three]
```

<a name="replace#2" />

### Method [`replace#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/regex_uclm/source_files/regex_module.cc#L545)

Replaces all occurrences of regular expression pattern in input string with
replacement string.

**Parameters:**

1. Object of class `String` containing input string.
2. Object of class `String` containing replacement string.

**Return:**

* Object of class `String`.

**Example:**

```cpp
obj = new Regex("[0-9]+");
res = obj.replace("abc 123 def 456","NUM");
("result: %s\n" % res).print();
```
```
result: abc 123 def 456
```

<a name="to_string#0" />

### Method `spec` `static` [`to_string#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/regex_uclm/source_files/regex_module.cc#L627)

Convert object of class `Regex` to object of class `String`.
This method returns name of class `Regex`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
("Regex.to_string(): %s\n" % Regex.to_string()).print();
```
```
Regex.to_string(): Regex
```

<a name="print#0" />

### Method `spec` `static` [`print#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/regex_uclm/source_files/regex_module.cc#L636)

Print string representation of object of class `Regex` to standard output.
This method prints name of class `Regex`.

**Return:**

* Object of class `Regex`.

**Example:**

```cpp
Regex.print();
"\n".print();
```
```
Regex
```
