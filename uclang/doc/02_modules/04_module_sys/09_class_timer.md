# Class Timer

Class implementing timer scheduling mechanism.

-----

## Table of methods

* Constructors

  * Constructor [`Timer#0`](#Timer%230)

* Operators

  * Operator [`operator_binary_equal#1`](#operator_binary_equal%231)

* Methods

  * Method [`schedule#3`](#schedule%233)
  * Method [`cancel#1`](#cancel%231)
  * Method [`process#0`](#process%230)
  * Method [`remain#0`](#remain%230)
  * Method [`timeout#0`](#timeout%230)
  * Method [`to_string#0`](#to_string%230)
  * Method [`print#0`](#print%230)

-----

## Example context

All examples introduced below are executed in following context.

```cpp
class Main
{
  public timer_cb(a_data)
  {
    ("timer_cb: %s\n" % $a_data).print();
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

## Constructors

<a name="Timer#0" />

### Constructor [`Timer#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L5114)

Creates object of class `Timer`.

**Example:**

```cpp
obj = new Timer();
("obj: %s\n" % $obj).print();
```
```
obj: Timer
```

-----

## Operators

<a name="operator_binary_equal#1" />

### Operator [`operator_binary_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L5102)

Assignment operator `=`. Object of class `Timer` is replaced by method parameter.

**Parameters:**

1. Any type.

**Return:**

* Method parameter.

**Example:**

```cpp
obj = new Timer();
("obj: %s\n" % $obj).print();
obj = "New value";
("obj: %s\n" % $obj).print();
```
```
obj: Timer
obj: New value
```

-----

## Methods

<a name="schedule#3" />

### Method [`schedule#3`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L5127)

Schedules callback to be called after given delay. Returns record index that
can be used to cancel scheduled callback.

**Parameters:**

1. Type convertible to integer representing delay in milliseconds.
2. Object of class `Delegate` to be called when timer fires.
3. User data to be passed to callback delegate.

**Return:**

* Object of class `Integer` representing scheduled record index.

**Example:**

```cpp
obj = new Timer();
idx = obj.schedule(100,new Delegate(this,"timer_cb",1),"data");
("idx: %d\n" % idx).print();
Sys.sleep(150);
obj.process();
```
```
idx: 0
timer_cb: data
```

<a name="cancel#1" />

### Method [`cancel#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L5174)

Cancels scheduled timer callback identified by record index.

**Parameters:**

1. Type convertible to integer representing record index returned by [`schedule#3`](#schedule%233).

**Example:**

```cpp
obj = new Timer();
idx = obj.schedule(100,new Delegate(this,"timer_cb",1),"data");
obj.cancel(idx);
("cancelled\n").print();
```
```
cancelled
```

<a name="process#0" />

### Method [`process#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L5262)

Fires all scheduled callbacks whose delay has expired.

**Example:**

```cpp
obj = new Timer();
obj.schedule(50,new Delegate(this,"timer_cb",1),"hello");
Sys.sleep(100);
obj.process();
```
```
timer_cb: hello
```

<a name="remain#0" />

### Method [`remain#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L5210)

Returns time remaining in milliseconds until next scheduled event, or object
of class `Blank` if no timers are scheduled.

**Return:**

* Object of class `Integer`, or object of class `Blank`.

**Example:**

```cpp
obj = new Timer();
obj.schedule(1000,new Delegate(this,"timer_cb",1),"data");
("type: %s\n" % $(type obj.remain())).print();
```
```
type: Integer
```

<a name="timeout#0" />

### Method [`timeout#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L5235)

Returns time remaining in milliseconds until next scheduled event. Returns
`0` if a timer has already expired.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
obj = new Timer();
obj.schedule(1000,new Delegate(this,"timer_cb",1),"data");
("type: %s\n" % $(type obj.timeout())).print();
```
```
type: Integer
```

<a name="to_string#0" />

### Method `spec` `static` [`to_string#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L5323)

Convert object of class `Timer` to object of class `String`.
This method returns name of class `Timer`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
("Timer.to_string(): %s\n" % Timer.to_string()).print();
```
```
Timer.to_string(): Timer
```

<a name="print#0" />

### Method `spec` `static` [`print#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L5332)

Print string representation of object of class `Timer` to standard output.
This method prints name of class `Timer`.

**Return:**

* Object of class `Timer`.

**Example:**

```cpp
Timer.print();
"\n".print();
```
```
Timer
```
