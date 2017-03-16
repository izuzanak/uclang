
# Flow loops

This document describes syntax of loops used in Uclang.

### While loop statement

Standard loop statement with test at its beginning. Syntax of statement is
same as in languages C, C++, Java or JavaScript.

**Statement syntax:**

```
<command> -> while ( <expression> ) <command>
```

Where used symbols have following meaning:

* `<expression>` - represents single Uclang expression.
* `<command>` - represents one command, or block of commands enclosed in curly
  brackets `{` and `}`.

**Example:**

```cpp
idx = 0;
while(idx < 5)
{
  ("idx: %d\n" % idx++).print();
}
```
```
idx: 0
idx: 1
idx: 2
idx: 3
idx: 4
```

### Do while loop statement

Standard loop statement with test at its end. Syntax of statement is same as
in languages C, C++, Java or JavaScript.

**Statement syntax:**

```
<command> -> do <command> while ( <expression> ) ;
```

Where used symbols have following meaning:

* `<expression>` - represents single Uclang expression.
* `<command>` - represents one command, or block of commands enclosed in curly
  brackets `{` and `}`.

**Example:**

```cpp
idx = 0;
do {
  ("idx: %d\n" % idx).print();
} while(++idx < 5);
```
```
idx: 0
idx: 1
idx: 2
idx: 3
idx: 4
```

### For loop statement

Statement looping through values of iterable object.  Content of object which
is iterated through should not be changed, until iteration end.  Two types of
iterable objects are supported:

1. Objects with methods `first_idx#0`, `next_idx#1` and `item#1`.
2. Objects with method `next_item#0`.

**Statement syntax:**

```
for ( <variable> <- <expression> ) <command>
```

Where used symbols have following meaning:

* `<variable>` - name of variable which value is set to objects of iterable,
  one by one.
* `<expression>` - represents single Uclang expression.
* `<command>` - represents one command, or block of commands enclosed in curly
  brackets `{` and `}`.

**First example:**

```cpp
for (val <- ["One","Two","Three","Four"])
{
  ("val: %s\n" % val).print();
}
```
```
val: One
val: Two
val: Three
val: Four
```

**Second example:**

```cpp
dict = new Dict(["One",1,"Two",2,"Three",3]);
for (val <- dict)
{
  ("dict[\"%s\"]: %d\n" % [val,dict[val]]).print();
}
```
```
dict["One"]: 1
dict["Two"]: 2
dict["Three"]: 3
```

### Keywords continue and break

Keywords `continue` is used for skip one iteration of loop, in which it
appears.  Keywords `break` is used for immediate termination of loop in which
it appears.

**Statement syntax:**

```
<command> -> break ;
<command> -> continue ;
```

**First example:**

```cpp
for (val <- ["One","Two","Three","Four"])
{
  if (val == "Three")
    continue;

  ("val: %s\n" % val).print();
}
```
```
val: One
val: Two
val: Four
```

**Second example:**

```cpp
for (val <- ["One","Two","Three","Four"])
{
  if (val == "Three")
    break;

  ("val: %s\n" % val).print();
}
```
```
val: One
val: Two
```

