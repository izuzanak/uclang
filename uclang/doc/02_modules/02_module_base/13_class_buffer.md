# Class Buffer

Class describing objects representing raw binary data buffers.

-----

## Table of methods

* Operators

  * Operator [`operator_binary_equal#1`](#operator_binary_equal%231)

* Methods

  * Method [`size#0`](#size%230)
  * Method [`to_string#0`](#to_string%230)
  * Method [`print#0`](#print%230)

-----

## Example context

All examples introduced below are executed in following context.

```cpp
class Main
{
  public static main(argv)
  {
    arr = new BinArray(BinArray.TYPE_INT32);
    arr.push(1);
    arr.push(2);
    arr.push(3);
    buf = arr.buffer();
--------------------------------- example code ---------------------------------
  }
}
```

-----

## Operators

<a name="operator_binary_equal#1" />

### Operator [`operator_binary_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L8886)

Assignment operator `=`. Object of class `Buffer` is replaced by method parameter.

**Parameters:**

1. Any type.

**Return:**

* Method parameter.

**Example:**

```cpp
obj = buf;
("obj: %s\n" % $obj).print();
obj = "New value";
("obj: %s\n" % $obj).print();
```
```
obj: Buffer
obj: New value
```

-----

## Methods

<a name="size#0" />

### Method [`size#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L8898)

Returns size of buffer in bytes.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
("size: %d\n" % buf.size()).print();
```
```
size: 12
```

<a name="to_string#0" />

### Method `spec` `static` [`to_string#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L8911)

Convert object of class `Buffer` to object of class `String`.
This method returns name of class `Buffer`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
("Buffer.to_string(): %s\n" % Buffer.to_string()).print();
```
```
Buffer.to_string(): Buffer
```

<a name="print#0" />

### Method `spec` `static` [`print#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L8920)

Print string representation of object of class `Buffer` to standard output.
This method prints name of class `Buffer`.

**Return:**

* Object of class `Buffer`.

**Example:**

```cpp
Buffer.print();
"\n".print();
```
```
Buffer
```
