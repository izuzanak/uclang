# Class Mutex

Class representing system wide mutual exclusion objects.

-----

## Static constants

* Error codes
  * `Mutex.ERROR_INVALID`
  * `Mutex.ERROR_DEADLOCK`
  * `Mutex.ERROR_BUSY`
  * `Mutex.ERROR_PERMISSION`

-----

## Table of methods

* Constructors

  * Constructor [`Mutex#0`](#Mutex%230)

* Operators

  * Operator [`operator_binary_equal#1`](#operator_binary_equal%231)

* Methods

  * Method [`lock#0`](#lock%230)
  * Method [`try_lock#0`](#try_lock%230)
  * Method [`unlock#0`](#unlock%230)
  * Method [`to_string#0`](#to_string%230)
  * Method [`print#0`](#print%230)

-----

## Constructors

<a name="Mutex#0" />

### Constructor [`Mutex#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L8279)

Creates default object of class `Mutex`.

**Example:**

```cpp
obj = new Mutex();
("obj: %s\n" % obj.to_string()).print();
```
```
obj: Mutex
```

-----

## Operators

<a name="operator_binary_equal#1" />

### Operator [`operator_binary_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L8265)

Assignment operator `=`. Object of class `Mutex` is replaced by method parameter.

**Parameters:**

1. Any type.

**Return:**

* Method parameter.

**Example:**

```cpp
obj = new Mutex();
("obj: %s\n" % obj.to_string()).print();
obj = "New value";
("obj: %s\n" % obj.to_string()).print();
```
```
obj: Mutex
obj: New value
```

-----

## Methods

<a name="lock#0" />

### Method [`lock#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L8284)

Try to lock object of class `Mutex` by calling thread. If mutex is already
locked, calling thread blocks until the mutex becomes available.

**Return:**

* Object of class `Blank` if object of class `Mutex` was successfully locked.
* Object of class `Error` otherwise.

**Example:**

```cpp
obj = new Mutex();
("obj.lock(): %s\n" % obj.lock().to_string()).print();
obj.unlock();
```
```
obj.lock(): <blank>
```

<a name="try_lock#0" />

### Method [`try_lock#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L8304)

Try to lock object of class `Mutex` by calling thread. If mutex is already
locked, method do not blocks and returns object of class `Error` immediately.

**Return:**

* Object of class `Blank` if object of class `Mutex` was successfully locked.
* Object of class `Error` otherwise.

**Example:**

```cpp
obj = new Mutex();
("obj.try_lock(): %s\n" % obj.try_lock().to_string()).print();
obj.unlock();
```
```
obj.try_lock(): <blank>
```

<a name="unlock#0" />

### Method [`unlock#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L8324)

Unlock object of class `Mutex` owned by calling thread.

**Return:**

* Object of class `Blank` if object of class `Mutex` was successfully unlocked.
* Object of class `Error` otherwise.

**Example:**

```cpp
obj = new Mutex();
obj.lock();
("obj.unlock(): %s\n" % obj.unlock().to_string()).print();
```
```
obj.unlock(): <blank>
```

<a name="to_string#0" />

### Method `spec` `static` [`to_string#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L8344)

Convert object of class `Mutex` to object of class `String`.
This method returns name of class `Mutex`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
("Mutex.to_string(): %s\n" % Mutex.to_string()).print();
```
```
Mutex.to_string(): Mutex
```

<a name="print#0" />

### Method `spec` `static` [`print#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L8353)

Print string representation of object of class `Mutex` to standard output.
This method prints name of class `Mutex`.

**Return:**

* Object of class `Blank`.

**Example:**

```cpp
Mutex.print();
"\n".print();
```
```
Mutex
```
