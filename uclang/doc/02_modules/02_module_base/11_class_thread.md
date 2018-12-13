# Class Thread

Class representing operating system threads.

-----

## Static constants

* Error codes
  * `Thread.ERROR_AGAIN`
  * `Thread.ERROR_SEARCH`
  * `Thread.ERROR_INVALID`
  * `Thread.ERROR_DEADLOCK`
  * `Thread.ERROR_BUSY`

-----

## Table of methods

* Operators

  * Operator [`operator_binary_equal#1`](#operator_binary_equal%231)

* Methods

  * Method [`join#0`](#join%230)
  * Method [`try_join#0`](#try_join%230)
  * Method [`detach#0`](#detach%230)
  * Method [`yield#0`](#yield%230)
  * Method [`to_string#0`](#to_string%230)
  * Method [`print#0`](#print%230)

-----

## Example context

All examples introduced below are executed in following context.

```cpp
class Main
{
  public static parallel thread_fun(a_param)
  {
    return "Thread return: " + a_param;
  }

  public static main(argv)
  {
--------------------------------- example code ---------------------------------
  }
}
```

-----

## Operators

<a name="operator_binary_equal#1" />

### Operator [`operator_binary_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L8161)

Assignment operator `=`. Object of class `Thread` is replaced by method parameter.

**Parameters:**

1. Any type.

**Return:**

* Method parameter.

**Example:**

```cpp
obj = thread_fun("Data");
("obj: %s\n" % $obj).print();
obj = "New value";
("obj: %s\n" % $obj).print();
```
```
obj: Thread
obj: New value
```

-----

## Methods

<a name="join#0" />

### Method [`join#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L8173)

Method waits for thread specified by object of class `Thread` to terminate.

**Return:**

* Value returned by entry method of successfully joined thread.
* Object of class `Error` if thread was not joined.

**Example:**

```cpp
obj = thread_fun("Data");
("obj.join(): %s\n" % $obj.join()).print();
```
```
obj.join(): Thread return: Data
```

<a name="try_join#0" />

### Method [`try_join#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L8207)

Method tries to join thread specified by object of class `Thread`. Method returns
immediately even if thread was not yet terminated.

**Return:**

* Value returned by entry method of successfully joined thread.
* Object of class `Error` if thread was not joined.

**Example:**

```cpp
obj = thread_fun("Data");
("obj.try_join(): %s\n" % $obj.try_join()).print();
Sys.sleep(100);
("obj.try_join(): %s\n" % $obj.try_join()).print();
```
```
obj.try_join(): error_BUSY
obj.try_join(): Thread return: Data
```

<a name="detach#0" />

### Method [`detach#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L8241)

Method marks thread specified by object of class `Thread` as detached.
When detached thread terminates its resources are released without need for
joining.

**Return:**

* Return object of class `Blank` if thread was successfully detached.
* Object of class `Error` otherwise.

**Example:**

```cpp
obj = thread_fun("Data");
("obj.detach(): %s\n" % $obj.detach()).print();
```
```
obj.detach(): <blank>
```

<a name="yield#0" />

### Method `static` [`yield#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L8264)

Method suspend thread execution in favor of other threads running in system.

**Return:**

* Object of class `Blank`.

**Example:**

```cpp
("Thread.yield(): %s\n" % $Thread.yield()).print();
```
```
Thread.yield(): <blank>
```

<a name="to_string#0" />

### Method `spec` `static` [`to_string#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L8273)

Convert object of class `Thread` to object of class `String`.
This method returns name of class `Thread`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
("Thread.to_string(): %s\n" % Thread.to_string()).print();
```
```
Thread.to_string(): Thread
```

<a name="print#0" />

### Method `spec` `static` [`print#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L8282)

Print string representation of object of class `Thread` to standard output.
This method prints name of class `Thread`.

**Return:**

* Object of class `Thread`.

**Example:**

```cpp
Thread.print();
"\n".print();
```
```
Thread
```
