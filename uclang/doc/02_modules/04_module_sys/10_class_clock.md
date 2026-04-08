# Class Clock

Class providing access to POSIX clock functions.

-----

## Static constants

* Clock identifier constants
  * `Clock.CLOCK_REALTIME` - System-wide real-time clock.
  * `Clock.CLOCK_MONOTONIC` - Monotonic clock that cannot be set.
  * `Clock.CLOCK_PROCESS_CPUTIME_ID` - Per-process CPU-time clock.
  * `Clock.CLOCK_THREAD_CPUTIME_ID` - Per-thread CPU-time clock.

-----

## Table of methods

* Methods

  * Method [`getres#1`](#getres%231)
  * Method [`gettime#1`](#gettime%231)
  * Method [`settime#2`](#settime%232)
  * Method [`to_string#0`](#to_string%230)
  * Method [`print#0`](#print%230)

-----

## Methods

<a name="getres#1" />

### Method `static` [`getres#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L5429)

Returns resolution of given clock as array of seconds and nanoseconds.

**Parameters:**

1. Type convertible to integer representing clock identifier (e.g. `Clock.CLOCK_REALTIME`).

**Return:**

* Object of class `Array` containing `[seconds, nanoseconds]`.

**Example:**

```cpp
res = Clock.getres(Clock.CLOCK_REALTIME);
("resolution: %s\n" % $res).print();
```
```
resolution: 1
```

<a name="gettime#1" />

### Method `static` [`gettime#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L5456)

Returns current time of given clock as array of seconds and nanoseconds.

**Parameters:**

1. Type convertible to integer representing clock identifier (e.g. `Clock.CLOCK_MONOTONIC`).

**Return:**

* Object of class `Array` containing `[seconds, nanoseconds]`.

**Example:**

```cpp
time = Clock.gettime(Clock.CLOCK_MONOTONIC);
("time: %s\n" % $time).print();
```
```
time: 38097469273557869
```

<a name="settime#2" />

### Method `static` [`settime#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L5483)

Sets time of given clock.

**Parameters:**

1. Type convertible to integer representing clock identifier.
2. Object of class `Array` containing `[seconds, nanoseconds]`.

**Example:**

```cpp
// Clock.settime(Clock.CLOCK_REALTIME,[0,0]);
("Clock class\n").print();
```
```
Clock class
```

<a name="to_string#0" />

### Method `spec` `static` [`to_string#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L5518)

Convert object of class `Clock` to object of class `String`.
This method returns name of class `Clock`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
("Clock.to_string(): %s\n" % Clock.to_string()).print();
```
```
Clock.to_string(): Clock
```

<a name="print#0" />

### Method `spec` `static` [`print#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L5527)

Print string representation of object of class `Clock` to standard output.
This method prints name of class `Clock`.

**Return:**

* Object of class `Clock`.

**Example:**

```cpp
Clock.print();
"\n".print();
```
```
Clock
```
