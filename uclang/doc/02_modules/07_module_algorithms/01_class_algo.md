# Class Algo

Class containing various algorithms for processing of
iterable types.

-----

## Table of methods

* Methods

  * Method [`all_true#1`](#all_true%231)
  * Method [`any_true#1`](#any_true%231)
  * Method [`map#2`](#map%232)
  * Method [`reduce#3`](#reduce%233)
  * Method [`filter#2`](#filter%232)
  * Method [`zip#1`](#zip%231)
  * Method [`to_string#0`](#to_string%230)
  * Method [`print#0`](#print%230)

-----

## Example context

All examples introduced below are executed in following context.

```cpp
class Main
{
  static public reduce_add(a_first,a_second)
  {
    return a_first + a_second;
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

## Methods

<a name="all_true#1" />

### Method `static` [`all_true#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/algorithms_uclm/source_files/algorithms_module.cc#L306)

Test if all elements in iterable object are true.

**Parameters:**

1. Iterable type.

**Return:**

Object of class `Integer`.
  * `0` - at least one element in iterable object is false.
  * `1` - all elements in iterable object are true.

**Example:**

```cpp
obj = [0,1,2,3,4,5];
("result: %d\n" % Algo.all_true(obj)).print();
obj = [1,2,3,4,5,6];
("result: %d\n" % Algo.all_true(obj)).print();
```
```
result: 0
result: 1
```

<a name="any_true#1" />

### Method `static` [`any_true#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/algorithms_uclm/source_files/algorithms_module.cc#L361)

Test if any element in iterable object is true.

**Parameters:**

1. Iterable type.

**Return:**

Object of class `Integer`.
  * `0` - all elements in iterable object are false.
  * `1` - at least one element in iterable object is true.

**Example:**

```cpp
obj = [0,0,0,0,0,0];
("result: %d\n" % Algo.any_true(obj)).print();
obj = [0,0,0,0,1,0];
("result: %d\n" % Algo.any_true(obj)).print();
```
```
result: 0
result: 1
```

<a name="map#2" />

### Method `static` [`map#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/algorithms_uclm/source_files/algorithms_module.cc#L416)

Creates object of type `Array` containing elements from input iterable object
transformed by given map function.

**Parameters:**

1. Iterable type.
2. Map function represented by object of class `Array`, `Dict` or `Delegate`.

**Return:**

Object of class `Array` containing elements from input iterable object
transformed by given map function.

**Example:**

```cpp
result = Algo.map([0,1,2,1,0,2],["Zero","One","Two"]);
("result: %s\n" % $result).print();
result = Algo.map([0,1,1000,1,0,1000],new Dict([0,"Zero",1,"One",1000,"One thousand"]));
("result: %s\n" % $result).print();
result = Algo.map(new Range(1,5),:(size) return new Integer[size];);
("result: %s\n" % $result).print();
```
```
result: [Zero,One,Two,One,Zero,Two]
result: [Zero,One,One thousand,One,Zero,One thousand]
result: [[0],[0,0],[0,0,0],[0,0,0,0],[0,0,0,0,0]]
```

<a name="reduce#3" />

### Method `static` [`reduce#3`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/algorithms_uclm/source_files/algorithms_module.cc#L628)

Reduces all elements of iterable type object to one value.

**Parameters:**

1. Initial value.
2. Iterable type.
3. Object of class `Delegate` performing reduction step.

**Return:**

Object representing result of reduction.

**Example:**

```cpp
dlg = new Delegate(this,"reduce_add",2);
result = Algo.reduce(0,[1,2,3,4,5],dlg);
("result: %d\n" % result).print();
result = Algo.reduce("",["a","b","c","d","e"],dlg);
("result: %s\n" % result).print();
result = Algo.reduce(0,new Range(1,10),:(acc,value) return acc + value;);
("result: %d\n" % result).print();
```
```
result: 15
result: abcde
result: 55
```

<a name="filter#2" />

### Method `static` [`filter#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/algorithms_uclm/source_files/algorithms_module.cc#L710)

Creates object of type `Array` containing elements from input iterable object
for which filter function returns true.

**Parameters:**

1. Iterable type.
2. Filter function represented by object of class `Array`, `Dict` or `Delegate`.

**Return:**

Object of class `Array` containing elements from input iterable object for which
filter function returns true.

**Example:**

```cpp
result = Algo.filter([0,1,2,1,0,2],[0,0,1]);
("result: %s\n" % $result).print();
result = Algo.filter([0,1,1000,1,0,1000],new Dict([0,1,1,1,1000,0]));
("result: %s\n" % $result).print();
result = Algo.filter(new Range(1,10),:(value) return value & 1;);
("result: %s\n" % $result).print();
```
```
result: [2,2]
result: [0,1,1,0]
result: [1,3,5,7,9]
```

<a name="zip#1" />

### Method `static` [`zip#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/algorithms_uclm/source_files/algorithms_module.cc#L945)

Creates object of type `Array` containing interleaved elements from input iterable objects.

**Parameters:**

1. Object of class `Array` containing iterable objects.

**Return:**

Object of class `Array` containing interleaved elements from input iterable objects.

**Example:**

```cpp
result = Algo.zip(["Hello",new Range(1,10)]);
("result: %s\n" % $result).print();
```
```
result: [H,1,e,2,l,3,l,4,o,5]
```

<a name="to_string#0" />

### Method `spec` `static` [`to_string#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/algorithms_uclm/source_files/algorithms_module.cc#L1115)

Convert object of class `Algo` to object of class `String`.
This method returns name of class `Algo`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
("Algo.to_string(): %s\n" % Algo.to_string()).print();
```
```
Algo.to_string(): Algo
```

<a name="print#0" />

### Method `spec` `static` [`print#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/algorithms_uclm/source_files/algorithms_module.cc#L1124)

Print string representation of object of class `Algo` to standard output.
This method prints name of class `Algo`.

**Return:**

* Object of class `Algo`.

**Example:**

```cpp
Algo.print();
"\n".print();
```
```
Algo
```
