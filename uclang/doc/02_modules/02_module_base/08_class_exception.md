# Class Exception

Class describing objects representing various types of exceptions.

-----

## Static constants

* Built in exceptions
  * `Exception.USER_EXCEPTION`
  * `Exception.TODO_EXCEPTION`
  * `Exception.CLASS_DOES_NOT_CONTAIN_CONSTRUCTOR`
  * `Exception.CLASS_DOES_NOT_CONTAIN_METHOD`
  * `Exception.CLASS_DOES_NOT_CONTAIN_VARIABLE`
  * `Exception.CANNOT_ACCESS_PRIVATE_METHOD`
  * `Exception.CANNOT_ACCESS_PRIVATE_VARIABLE`
  * `Exception.METHOD_CANNOT_RETURN_VALUE`
  * `Exception.CANNOT_TEST_TYPE_VALUE`
  * `Exception.CANNOT_CONVERT_TYPE_TO_INTEGER`
  * `Exception.CANNOT_USE_NEGATIVE_NUMBER`
  * `Exception.SLICE_NOT_INTEGER_ARGUMENTS`
  * `Exception.SLICE_START_LESS_THAN_ZERO`
  * `Exception.SLICE_STOP_LESS_THAN_ZERO`
  * `Exception.SLICE_STEP_EQUAL_TO_ZERO`
  * `Exception.OBJECT_OF_CLASS_IS_NOT_ITERABLE`
  * `Exception.UNEXPECTED_END_OF_ITERABLE`
  * `Exception.BUILT_IN_NOT_IMPLEMENTED_METHOD`
  * `Exception.METHOD_NOT_DEFINED_WITH_PARAMETERS`
  * `Exception.WRONG_METHOD_PARAMETER_VALUE`
  * `Exception.DIVISION_BY_ZERO`
  * `Exception.NEGATIVE_SHIFT_COUNT`
  * `Exception.METHOD_NOT_RETURN_INTEGER`
  * `Exception.METHOD_NOT_RETURN_STRING`
  * `Exception.METHOD_NOT_RETURN_INDEX`
  * `Exception.INTEGER_BASE_OUT_OF_RANGE`
  * `Exception.INTEGER_CONVERT_INVALID_STRING`
  * `Exception.FLOAT_CONVERT_INVALID_STRING`
  * `Exception.STRING_FORMAT_NOT_ENOUGH_ARGUMENTS`
  * `Exception.STRING_FORMAT_WRONG_ARGUMENT_TYPE`
  * `Exception.STRING_FORMAT_ARGUMENT_FORMAT_ERROR`
  * `Exception.STRING_FORMAT_WRONG_FORMAT_SPECIFIER`
  * `Exception.STRING_FORMAT_NOT_ALL_ARGUMENTS_CONVERTED`
  * `Exception.STRING_INDEX_EXCEEDS_RANGE`
  * `Exception.STRING_WRONG_RANGE_INDEXES`
  * `Exception.STRING_CONVERT_FROM_INTEGER`
  * `Exception.STRING_CONVERT_FROM_FLOAT`
  * `Exception.ARRAY_INDEX_EXCEEDS_RANGE`
  * `Exception.ARRAY_CANNOT_RESIZE_TO_SMALLER_SIZE`
  * `Exception.ARRAY_NO_ELEMENTS`
  * `Exception.ARRAY_ELEMENT_ASSIGN_NOT_SAME_LENGTH`
  * `Exception.DELEGATE_NEGATIVE_PARAMETER_COUNT`
  * `Exception.DELEGATE_OBJECT_DOES_NOT_CONTAIN_METHOD`
  * `Exception.DELEGATE_CALL_WRONG_PARAMETER_COUNT`
  * `Exception.DELEGATE_WRONG_RETURN_VALUE_TYPE`

-----

## Table of methods

* Constructors

  * Constructor [`Exception#0`](#Exception%230)
  * Constructor [`Exception#1`](#Exception%231)

* Methods

  * Method [`throw#0`](#throw%230)
  * Method [`get_type#0`](#get_type%230)
  * Method [`get_value#0`](#get_value%230)
  * Method [`get_file_name#0`](#get_file_name%230)
  * Method [`get_line#0`](#get_line%230)
  * Method [`error_print#0`](#error_print%230)
  * Method [`to_string#0`](#to_string%230)
  * Method [`print#0`](#print%230)

-----

## Constructors

<a name="Exception#0" />

### Constructor [`Exception#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L7688)

Creates default object of class `Exception`.

**Example:**

```cpp
obj = new Exception();
("obj: %s\n" % obj.to_string()).print();
```
```
obj: Exception
```

<a name="Exception#1" />

### Constructor [`Exception#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L7702)

Creates user exception (object of class `Exception`) encapsulating object given by method parameter.

**Parameters:**

1. Any type.

**Example:**

```cpp
obj = new Exception("Simple exception");
("obj: %s\n" % obj.to_string()).print();
```
```
obj: Exception
```

-----

## Methods

<a name="throw#0" />

### Method [`throw#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L7723)

Throws exception represented by object of class `Exception`.

**Example:**

```cpp
try
{
  new Exception("Simple exception").throw();
}
catch (exc)
{
  ("exc: %s\n" % exc.to_string()).print();
}
```
```
exc: Exception
```

<a name="get_type#0" />

### Method [`get_type#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L7746)

Retrieve object of class `Error` representing type of exception.

**Return:**

* Object of class `Error`.

**Example:**

```cpp
obj = new Exception("Simple exception");
("obj.get_type(): %s\n" % obj.get_type().to_string()).print();
```
```
obj.get_type(): error_USER_EXCEPTION
```

<a name="get_value#0" />

### Method [`get_value#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L7759)

Retrieve value encapsulated by object of type `Exception`.

**Return:**

* Any type.

**Example:**

```cpp
obj = new Exception("Simple exception");
("obj.get_value(): %s\n" % obj.get_value()).print();
```
```
obj.get_value(): Simple exception
```

<a name="get_file_name#0" />

### Method [`get_file_name#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L7777)

Return name of source file in which object of class `Exception` was thrown.

**Return:**

* Object of class `String` if exception was thrown.
* Object of class `Blank` otherwise.

**Example:**

```cpp
try {
  obj = new Exception("Simple exception");
  ("obj.get_file_name(): %s\n" % obj.get_file_name().to_string()).print();
  obj.throw();
}
catch (exc)
{
  ("exc.get_file_name(): %s\n" % exc.get_file_name()).print();
}
```
```
obj.get_file_name(): <blank>
exc.get_file_name(): ./snippet.ucl
```

<a name="get_line#0" />

### Method [`get_line#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L7803)

Return line of source file in which object of class `Exception` was thrown.

**Return:**

* Object of class `Integer` if exception was thrown.
* Object of class `Blank` otherwise.

**Example:**

```cpp
try {
  obj = new Exception("Simple exception");
  ("obj.get_line(): %s\n" % obj.get_line().to_string()).print();
  obj.throw();
}
catch (exc)
{
  ("exc.get_line(): %d\n" % exc.get_line()).print();
}
```
```
obj.get_line(): <blank>
exc.get_line(): 10
```

<a name="error_print#0" />

### Method [`error_print#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L7827)

Print information about exception described by object of class `Exception` to
error output of process.

**Return:**

* Object of class `Blank`.

**Example:**

```cpp
try {
  new Exception("Simple exception").throw();
}
catch (exc)
{
  exc.error_print();
}
```
```
 ---------------------------------------- 
Exception: ERROR: in file: "./snippet.ucl" on line: 8
  new Exception("Simple exception").throw();

Simple exception
 ---------------------------------------- 
```

<a name="to_string#0" />

### Method `spec` `static` [`to_string#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L7855)

Convert object of class `Exception` to object of class `String`.
This method returns name of class `Exception`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
("Exception.to_string(): %s\n" % Exception.to_string()).print();
```
```
Exception.to_string(): Exception
```

<a name="print#0" />

### Method `spec` `static` [`print#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L7864)

Print string representation of object of class `Exception` to standard output.
This method prints name of class `Exception`.

**Return:**

* Object of class `Blank`.

**Example:**

```cpp
Exception.print();
"\n".print();
```
```
Exception
```
