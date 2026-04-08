# Class Time

Class describing time values with nanosecond precision.

-----

## Table of methods

* Constructors

  * Constructor [`Time#0`](#Time%230)
  * Constructor [`Time#1`](#Time%231)

* Operators

  * Operator [`operator_binary_equal#1`](#operator_binary_equal%231)

* Methods

  * Method [`value#0`](#value%230)
  * Method [`nano_sec#0`](#nano_sec%230)
  * Method [`micro_sec#0`](#micro_sec%230)
  * Method [`milli_sec#0`](#milli_sec%230)
  * Method [`seconds#0`](#seconds%230)
  * Method [`minutes#0`](#minutes%230)
  * Method [`hours#0`](#hours%230)
  * Method [`days#0`](#days%230)
  * Method [`datetime#0`](#datetime%230)
  * Method [`day_of_week#0`](#day_of_week%230)
  * Method [`compare#1`](#compare%231)
  * Method [`to_string#0`](#to_string%230)
  * Method [`print#0`](#print%230)

-----

## Constructors

<a name="Time#0" />

### Constructor [`Time#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/ucf_uclm/source_files/ucf_module.cc#L928)

Creates object of class `Time` representing current time.

**Example:**

```cpp
obj = new Time();
("type: %s\n" % $(type obj)).print();
```
```
type: Time
```

<a name="Time#1" />

### Constructor [`Time#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/ucf_uclm/source_files/ucf_module.cc#L938)

Creates object of class `Time` from given value. Accepts integer (nanoseconds),
float, object of class `Time`, or string in format `"YYYYMMDDHHmmSS"`.

**Parameters:**

1. Object of class `Integer`, `Float`, `Time` or `String`.

**Example:**

```cpp
obj = new Time(1742049025000000000);
("obj: %s\n" % $obj).print();
obj = new Time("20250101120000");
("obj: %s\n" % $obj).print();
```
```
obj: 2025/03/15 14:30:25
obj: 2025/01/01 12:00:00
```

-----

## Operators

<a name="operator_binary_equal#1" />

### Operator [`operator_binary_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/ucf_uclm/source_files/ucf_module.cc#L874)

Assignment operator `=`. Object of class `Time` is replaced by method parameter.

**Parameters:**

1. Any type.

**Return:**

* Method parameter.

**Example:**

```cpp
obj = new Time();
("obj: %s\n" % $obj).print();
obj = "New value";
("obj: %s\n" % $obj).print();
```
```
obj: 2026/04/07 10:30:00
obj: New value
```

-----

## Methods

<a name="value#0" />

### Method [`value#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/nacl_uclm/source_files/nacl_module.cc#L964)

Returns raw time value in nanoseconds.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
obj = new Time("20250315143025");
("value: %d\n" % obj.value()).print();
```
```
value: 1742049025000000000
```

<a name="nano_sec#0" />

### Method [`nano_sec#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/time_uclm/source_files/time_module.cc#L353)

Returns time value in nanoseconds.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
obj = new Time("20250315143025");
("nano_sec: %d\n" % obj.nano_sec()).print();
```
```
nano_sec: 1742049025000000000
```

<a name="micro_sec#0" />

### Method [`micro_sec#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/time_uclm/source_files/time_module.cc#L364)

Returns time value in microseconds.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
obj = new Time("20250315143025");
("micro_sec: %d\n" % obj.micro_sec()).print();
```
```
micro_sec: 1742049025000000
```

<a name="milli_sec#0" />

### Method [`milli_sec#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/time_uclm/source_files/time_module.cc#L375)

Returns time value in milliseconds.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
obj = new Time("20250315143025");
("milli_sec: %d\n" % obj.milli_sec()).print();
```
```
milli_sec: 1742049025000
```

<a name="seconds#0" />

### Method [`seconds#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/nacl_uclm/source_files/nacl_module.cc#L975)

Returns time value in seconds.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
obj = new Time("20250315143025");
("seconds: %d\n" % obj.seconds()).print();
```
```
seconds: 1742049025
```

<a name="minutes#0" />

### Method [`minutes#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/nacl_uclm/source_files/nacl_module.cc#L987)

Returns time value in minutes.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
obj = new Time("20250315143025");
("minutes: %d\n" % obj.minutes()).print();
```
```
minutes: 29034150
```

<a name="hours#0" />

### Method [`hours#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/nacl_uclm/source_files/nacl_module.cc#L999)

Returns time value in hours.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
obj = new Time("20250315143025");
("hours: %d\n" % obj.hours()).print();
```
```
hours: 483902
```

<a name="days#0" />

### Method [`days#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/nacl_uclm/source_files/nacl_module.cc#L1011)

Returns time value in days.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
obj = new Time("20250315143025");
("days: %d\n" % obj.days()).print();
```
```
days: 20162
```

<a name="datetime#0" />

### Method [`datetime#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/nacl_uclm/source_files/nacl_module.cc#L1023)

Returns array of 10 integers representing date and time components:
`[year, month, day, weekday, hour, minute, second, millisecond, microsecond, nanosecond]`.

**Return:**

* Object of class `Array`.

**Example:**

```cpp
obj = new Time("20250101120000");
dt = obj.datetime();
("datetime: %s\n" % $dt).print();
```
```
datetime: [2025,1,1,3,12,0,0,0,0,0]
```

<a name="day_of_week#0" />

### Method [`day_of_week#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/time_uclm/source_files/time_module.cc#L472)

Returns day of week as integer.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
obj = new Time("20250101120000");
("day_of_week: %d\n" % obj.day_of_week()).print();
```
```
day_of_week: 3
```

<a name="compare#1" />

### Method `spec` [`compare#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/ucf_uclm/source_files/ucf_module.cc#L1208)

Compare object of class `Time` with method parameter.

**Parameters:**

1. Any type.

**Return:**

* Integer `-1` if object of class `Time` is lesser than method parameter.
* Integer `1` if object of class `Time` is greater than method parameter.
* Integer `0` if object of class `Time` is equal to method parameter.

**Example:**

```cpp
obj_0 = new Time();
obj_1 = new Time("20250101120000");
("obj_0.compare(obj_1): %d\n" % obj_0.compare(obj_1)).print();
("obj_1.compare(obj_0): %d\n" % obj_1.compare(obj_0)).print();
("obj_0.compare(obj_0): %d\n" % obj_0.compare(obj_0)).print();
```
```
obj_0.compare(obj_1): 1
obj_1.compare(obj_0): -1
obj_0.compare(obj_0): 0
```

<a name="to_string#0" />

### Method `spec` [`to_string#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/ucf_uclm/source_files/ucf_module.cc#L1232)

Convert object of class `Time` to object of class `String`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
obj = new Time();
("obj.to_string(): %s\n" % obj.to_string()).print();
```
```
obj.to_string(): 2026/04/07 10:30:00
```

<a name="print#0" />

### Method `spec` [`print#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/ucf_uclm/source_files/ucf_module.cc#L1247)

Print string representation of object of class `Time` to standard output.

**Return:**

* Object of class `Time`.

**Example:**

```cpp
obj = new Time();
obj.print();
"\n".print();
```
```
2026/04/07 10:30:00
```
