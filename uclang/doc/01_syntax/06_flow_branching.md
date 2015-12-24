
# Flow branching

This document describes branching structures and syntax of loops used in
uclang.

### If statement

Basic conditional branch statement. Syntax of statement is same as in
languages C, C++, Java or JavaScript.

**Statement syntax:**

```
<command> -> if ( <expression> ) <command>
```

Where used symbols have following meaning:

* `<expression>` - represents single uclang expression.
* `<command>` - represents one command, or block of commands enclosed in curly
  brackets `{` and `}`.

**First example:**

```cpp
for (val <- [1,2,3,4])
if (val == 3)
  ("value %d is equal to three\n" % val).print();
```
```
value 3 is equal to three
```

**Second example:**

```cpp
for (val <- [1,2,3,4])
if (val != 3)
{
  ("value %d is not equal to three\n" % val).print();
}
```
```
value 1 is not equal to three
value 2 is not equal to three
value 4 is not equal to three
```

### If-else statement

Conditional branch statement extended by else branch. Syntax of statement is
same as in languages C, C++, Java or JavaScript.

**Statement syntax:**

```
<command> -> if ( <expression> ) <command> else <command>
```

Where used symbols have following meaning:

* `<expression>` - represents single uclang expression.
* `<command>` - represents one command, or block of commands enclosed in curly
  brackets `{` and `}`.

**Example:**

```cpp
for (val <- [1,2,3,4])
if (val == 3)
  ("value %d is equal to three\n" % val).print();
else
  ("value %d is not equal to three\n" % val).print();
```
```
value 1 is not equal to three
value 2 is not equal to three
value 3 is equal to three
value 4 is not equal to three
```

<!--
### If-else syntax grammar rules

Grammar rules of if-else statement, that are defined in real syntax grammar
used for parsing of uclang source files:

```
<command>   -> if <condition> <if_else>
<condition> -> ( <expression> )
<if_else>   -> <command>
<if_else>   -> <command> else <command>
```
-->

### Switch statement

Switch statement is used to select one or more blocks from many blocks of code
to be executed. Syntax of statement differs from syntax of switch used in
languages C, C++, Java or JavaScript.

**Statement syntax:**

```
<command> -> switch ( <expression> )
{
  case <expression> : <command>
  case <expression> , <expression> , ... : <command>
  default : <command>
}
```

Where used symbols have following meaning:

* `<expression>` - represents single uclang expression.
* `<command>` - represents one command, or block of commands enclosed in curly
  brackets `{` and `}`.

**Function:**

Result of switch expression is compared to result of each case expression. If
these values are equal, then code block related to this case expression is
executed. One code block can have more related case expressions separated by
commas. If none of results of case expressions equal to result of switch
expression, then default code block is executed, if it is defined.  This type
of switch statement do not enable use of fall-through technique.

**First example:**

```cpp
for (val <- [1,2,3,4])
switch (val)
{
  case 1: ("value %d is equal to one\n" % val).print();
  case 2: ("value %d is equal to two\n" % val).print();
  case 3: ("value %d is equal to three\n" % val).print();
  default:
    ("value %d is not equal to one, two or three\n" % val).print();
}
```
```
value 1 is equal to one
value 2 is equal to two
value 3 is equal to three
value 4 is not equal to one, two or three
```

**Second example:**

```cpp
for (val <- [1,2,3,4,5])
switch (val)
{
  case 1,2: ("value %d is equal to one or two\n" % val).print();
  case 3,4: ("value %d is equal to three or four\n" % val).print();
  case 5,6: ("value %d is equal to five or six\n" % val).print();
}
```
```
value 1 is equal to one or two
value 2 is equal to one or two
value 3 is equal to three or four
value 4 is equal to three or four
value 5 is equal to five or six
```

**Third example:**

```cpp
for (val <- [1,2,3,4,5])
{
  descr = [];

  switch (1)
  {
    case !(val & 1): descr.push("is even");
    case val &1:     descr.push("is odd");

    case val == 1: descr.push("is one");
    case val == 2: descr.push("is two");
    case val == 3: descr.push("is three");

    case val < 2: descr.push("is lesser than two");
    case val > 2: descr.push("is greater than two");

    case Blank != [2,3,5,7].get_idx(val): descr.push("is prime");

    default:
      descr.push("is unknown");
  }

  ("value %d %s\n" % [val,descr.to_string(", ")]).print();
}
```
```
value 1 is odd, is one, is lesser than two
value 2 is even, is two, is prime
value 3 is odd, is three, is greater than two, is prime
value 4 is even, is greater than two
value 5 is odd, is greater than two, is prime
```

### Conditional expression

Conditional expression operator returns value based on some condition test.
Syntax of conditional expression is same as in languages C, C++, Java or
JavaScript.

**Statement syntax:**

```
<expression> -> <expression> ? <expression> : <expression>
```

Where symbol `<expression>` represents single uclang expression.

**Example:**

```cpp
for (val <- [1,2,3,4])
("value %d is %s to three\n" % [val,val == 3 ? "equal" : "not equal"]).print();
```
```
value 1 is not equal to three
value 2 is not equal to three
value 3 is equal to three
value 4 is not equal to three
```

