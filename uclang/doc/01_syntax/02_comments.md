
# Source code comments

In this document are introduced types of source code comments, that are
available in uclang source files.

### One line comments - first type

One line comments, which are used in Bash, Python or Perl scripts.

**Regular expression:**

Comment terminal symbol is defined by following regular expression:

```
'#'.!'\n'*.'\n'
```

It says that comment starts with character `#` and contains any characters,
that are not equal to `\n`. First occurrence of new line character `\n`
terminates one line comment.

**Example:**

```python
class Main
{
  # program entry method
  static public main(argv)
  {
    # retrieve integer arguments
    a = new Integer(argv[1]);
    b = new Integer(argv[2]);

    # sum two integers
    total = a + b;

    # return zero if total is qreater than one hundred
    # otherwise return one
    return total > 100 ? 0 : 1;
  }
}
```

### One line comments - second type

One line comments, which are used in C, C++ , Java or Ruby source codes.

**Regular expression:**

Comment terminal symbol is defined by following regular expression:

```
"//".!'\n'*.'\n'
```

It says that comment starts with characters `//` and contains any characters,
that are not equal to `\n`. First occurrence of new line character `\n`
terminates one line comment.

**Example:**

```cpp
class Main
{
  // program entry method
  static public main(argv)
  {
    // retrieve integer arguments
    a = new Integer(argv[1]);
    b = new Integer(argv[2]);

    // sum two integers
    total = a + b;

    // return zero if total is qreater than one hundred
    // otherwise return one
    return total > 100 ? 0 : 1;
  }
}
```

### Multi line comments

Multi line comments, which are used in C, C++ or Java source codes.

**Regular expression:**

Comment terminal symbol is defined by following regular expression:

```
"/*".(!'*'+('*'.!'/'))*."*/"
```

It says that comment starts with characters `/*` and end with characters `*/`.
Between start and end of comment are allowed characters, that are different
than `*`, or character `*` and its follower, which is different than `/`.

**Example:**

```cpp
class Main
{
  /* program entry method */
  static public main(argv)
  {
    /* retrieve integer arguments */
    a = new Integer(argv[1]);
    b = new Integer(argv[2]);

    /* sum two integers */
    total = a + b;

    /* return zero if total is qreater than one hundred
       otherwise return one */
    return total > 100 ? 0 : 1;
  }
}
```

