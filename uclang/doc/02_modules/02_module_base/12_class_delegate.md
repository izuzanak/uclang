# Class Delegate

Class representing delegate referring to method of particular object.

-----

## Table of methods

* Constructors

  * Constructor [`Delegate#3`](#Delegate%233)

* Operators

  * Operator [`operator_binary_equal#1`](#operator_binary_equal%231)

* Methods

  * Method [`call#1`](#call%231)
  * Method [`to_string#0`](#to_string%230)
  * Method [`print#0`](#print%230)

-----

## Example context

All examples introduced below are executed in following context.

```cpp
class Main
{
  public method(a_p0,a_p1)
  {
    ("method: %s\n" % [a_p0,a_p1].to_string()).print();
    return a_p0 + a_p1;
  }

  public Main()
  {
--------------------------------- example code ---------------------------------
  }

  public static main(argv)
  {
    new Main();
  }
}
```

-----

## Constructors

<a name="Delegate#3" />

### Constructor [`Delegate#3`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L8717)

Creates object of class `Delegate` referring to method
of object given as first parameter, with name given by second parameter,
and accepting count of parameters given by third parameter.

**Parameters:**

1. Any type.
2. Object of class `String`
3. Type convertible to integer.

**Example:**

```cpp
obj = new Delegate(this,"method",2);
("obj: %s\n" % obj.to_string()).print();
```
```
obj: Delegate
```

-----

## Operators

<a name="operator_binary_equal#1" />

### Operator [`operator_binary_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L8703)

Assignment operator `=`. Object of class `Delegate` is replaced by method parameter.

**Parameters:**

1. Any type.

**Return:**

* Method parameter.

**Example:**

```cpp
obj = new Delegate(this,"method",2);
("obj: %s\n" % obj.to_string()).print();
obj = "New value";
("obj: %s\n" % obj.to_string()).print();
```
```
obj: Delegate
obj: New value
```

-----

## Methods

<a name="call#1" />

### Method [`call#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L8800)

Calls method identified by object of class `Delegate`. Parameters 
of called method are retrieved from object of class `Array`, which is given as
method parameter.

**Parameters:**

1. Object of class `Array`.

**Return:**

* Value returned by called method.

**Example:**

```cpp
obj = new Delegate(this,"method",2);
res = obj.call([1,2]);
("res: %s\n" % res.to_string()).print();
```
```
method: [1,2]
res: 3
```

<a name="to_string#0" />

### Method `spec` `static` [`to_string#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L8843)

Convert object of class `Delegate` to object of class `String`.
This method returns name of class `Delegate`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
("Delegate.to_string(): %s\n" % Delegate.to_string()).print();
```
```
Delegate.to_string(): Delegate
```

<a name="print#0" />

### Method `spec` `static` [`print#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L8852)

Print string representation of object of class `Delegate` to standard output.
This method prints name of class `Delegate`.

**Return:**

* Object of class `Blank`.

**Example:**

```cpp
Delegate.print();
"\n".print();
```
```
Delegate
```
