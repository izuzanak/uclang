# Class Float

Class describing 64bit real numbers.

-----

## Static constants

* Constant values
  * `Float.INFINITY` - Positive infinity value.

* Real number classes
  * `Float.CLASS_NAN` - Value is "Not a Number".
  * `Float.CLASS_INFINITE` - Value is positive infinity or negative infinity.
  * `Float.CLASS_ZERO` - Value is zero.
  * `Float.CLASS_SUBNORMAL` - Value is too small to be represented in normalized format.
  * `Float.CLASS_NORMAL` - Value is a normal floating-point number.

-----

## Table of methods

* Constructors

  * Constructor [`Float#0`](#Float%230)
  * Constructor [`Float#1`](#Float%231)

* Operators

  * Operator [`operator_binary_equal#1`](#operator_binary_equal%231)
  * Operator [`operator_binary_plus_equal#1`](#operator_binary_plus_equal%231)
  * Operator [`operator_binary_minus_equal#1`](#operator_binary_minus_equal%231)
  * Operator [`operator_binary_asterisk_equal#1`](#operator_binary_asterisk_equal%231)
  * Operator [`operator_binary_slash_equal#1`](#operator_binary_slash_equal%231)
  * Operator [`operator_binary_double_ampersand#1`](#operator_binary_double_ampersand%231)
  * Operator [`operator_binary_double_pipe#1`](#operator_binary_double_pipe%231)
  * Operator [`operator_binary_double_equal#1`](#operator_binary_double_equal%231)
  * Operator [`operator_binary_exclamation_equal#1`](#operator_binary_exclamation_equal%231)
  * Operator [`operator_binary_rs_br#1`](#operator_binary_rs_br%231)
  * Operator [`operator_binary_ls_br#1`](#operator_binary_ls_br%231)
  * Operator [`operator_binary_rs_br_equal#1`](#operator_binary_rs_br_equal%231)
  * Operator [`operator_binary_ls_br_equal#1`](#operator_binary_ls_br_equal%231)
  * Operator [`operator_binary_plus#1`](#operator_binary_plus%231)
  * Operator [`operator_binary_minus#1`](#operator_binary_minus%231)
  * Operator [`operator_binary_asterisk#1`](#operator_binary_asterisk%231)
  * Operator [`operator_binary_slash#1`](#operator_binary_slash%231)
  * Operator [`operator_unary_post_double_plus#0`](#operator_unary_post_double_plus%230)
  * Operator [`operator_unary_post_double_minus#0`](#operator_unary_post_double_minus%230)
  * Operator [`operator_unary_pre_double_plus#0`](#operator_unary_pre_double_plus%230)
  * Operator [`operator_unary_pre_double_minus#0`](#operator_unary_pre_double_minus%230)
  * Operator [`operator_unary_pre_plus#0`](#operator_unary_pre_plus%230)
  * Operator [`operator_unary_pre_minus#0`](#operator_unary_pre_minus%230)
  * Operator [`operator_unary_pre_exclamation#0`](#operator_unary_pre_exclamation%230)

* Methods

  * Method [`sin#0`](#sin%230)
  * Method [`cos#0`](#cos%230)
  * Method [`tan#0`](#tan%230)
  * Method [`asin#0`](#asin%230)
  * Method [`acos#0`](#acos%230)
  * Method [`atan#0`](#atan%230)
  * Method [`exp#0`](#exp%230)
  * Method [`log#0`](#log%230)
  * Method [`pow#1`](#pow%231)
  * Method [`sqrt#0`](#sqrt%230)
  * Method [`cbrt#0`](#cbrt%230)
  * Method [`hypot#1`](#hypot%231)
  * Method [`classify#0`](#classify%230)
  * Method [`isnan#0`](#isnan%230)
  * Method [`compare#1`](#compare%231)
  * Method [`to_string#0`](#to_string%230)
  * Method [`print#0`](#print%230)

-----

## Constructors

<a name="Float#0" />

### Constructor [`Float#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3898)

Creates default object of class `Float`.

**Example:**

```cpp
obj = new Float();
("obj: %s\n" % $obj).print();
```
```
obj: 0.000000
```

<a name="Float#1" />

### Constructor [`Float#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3903)

Creates object of class `Float` from method parameter.

**Parameters:**

1. Object of class `Char`, `Integer`, `Float` or `String`.

**Example:**

```cpp
("obj: %f\n" % new Float('e')).print();
("obj: %f\n" % new Float(123)).print();
("obj: %f\n" % new Float(12.234)).print();
("obj: %f\n" % new Float("51.26")).print();
("obj: %f\n" % new Float("151e-2")).print();
("obj: %f\n" % new Float("0xff")).print();
```
```
obj: 101.000000
obj: 123.000000
obj: 12.234000
obj: 51.260000
obj: 1.510000
obj: 255.000000
```

-----

## Operators

<a name="operator_binary_equal#1" />

### Operator [`operator_binary_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3408)

Assignment operator `=`. Object of class `Float` is replaced by method parameter.

**Parameters:**

1. Any type.

**Return:**

* Method parameter.

**Example:**

```cpp
obj = 12.234;
("obj: %s\n" % $obj).print();
obj = "New value";
("obj: %s\n" % $obj).print();
```
```
obj: 12.234000
obj: New value
```

<a name="operator_binary_plus_equal#1" />

### Operator [`operator_binary_plus_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3598)

Add and assign operator `+=`. Operator adds value of method parameter to value of object of class `Float`.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Value of object.

**Example:**

```cpp
obj = 549.2;
("obj: %s\n" % $obj).print();
obj += 'e';
("obj: %s\n" % $obj).print();
obj += 123;
("obj: %s\n" % $obj).print();
obj += 12.234;
("obj: %s\n" % $obj).print();
```
```
obj: 549.200000
obj: 650.200000
obj: 773.200000
obj: 785.434000
```

<a name="operator_binary_minus_equal#1" />

### Operator [`operator_binary_minus_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3605)

Subtract and assign operator `-=`. Operator subtracts value of method parameter from value of object of class `Float`.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Value of object.

**Example:**

```cpp
obj = 549.2;
("obj: %s\n" % $obj).print();
obj -= 'e';
("obj: %s\n" % $obj).print();
obj -= 123;
("obj: %s\n" % $obj).print();
obj -= 12.234;
("obj: %s\n" % $obj).print();
```
```
obj: 549.200000
obj: 448.200000
obj: 325.200000
obj: 312.966000
```

<a name="operator_binary_asterisk_equal#1" />

### Operator [`operator_binary_asterisk_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3612)

Multiply and assign operator `*=`. Operator multiplies value of object of class `Float` by value of method parameter.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Value of object.

**Example:**

```cpp
obj = 549.2;
("obj: %s\n" % $obj).print();
obj *= 'e';
("obj: %s\n" % $obj).print();
obj *= 123;
("obj: %s\n" % $obj).print();
obj *= 12.234;
("obj: %s\n" % $obj).print();
```
```
obj: 549.200000
obj: 55469.200000
obj: 6822711.600000
obj: 83469053.714400
```

<a name="operator_binary_slash_equal#1" />

### Operator [`operator_binary_slash_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3619)

Divide and assign operator `/=`. Operator divides value of object of class `Float` by value of method parameter.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Value of object.

**Example:**

```cpp
obj = 56787236.67;
obj /= 'e';
("obj: %s\n" % $obj).print();
obj = 56787236.67;
obj /= 123;
("obj: %s\n" % $obj).print();
obj = 56787236.67;
obj /= 12.234;
("obj: %s\n" % $obj).print();
```
```
obj: 562249.868020
obj: 461684.850976
obj: 4641755.490436
```

<a name="operator_binary_double_ampersand#1" />

### Operator [`operator_binary_double_ampersand#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3686)

Logical AND operator `&&`.  If object of class
`Float` is non-zero and value of method parameter is also non-zero
condition becomes true.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Integer `1` if both operands are non-zero.
* Integer `0` if either of operands is zero.

**Example:**

```cpp
obj_0 = 0.0;
("obj_0 && 0: %d\n" % (obj_0 && 0)).print();
("obj_0 && 1: %d\n" % (obj_0 && 1)).print();
obj_1 = 12.234;
("obj_1 && 0: %d\n" % (obj_1 && 0)).print();
("obj_1 && 1: %d\n" % (obj_1 && 1)).print();
```
```
obj_0 && 0: 0
obj_0 && 1: 0
obj_1 && 0: 0
obj_1 && 1: 1
```

<a name="operator_binary_double_pipe#1" />

### Operator [`operator_binary_double_pipe#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3693)

Logical OR operator `||`.  If object of class
`Float` is non-zero or value of method parameter is non-zero
condition becomes true.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Integer `1` if either of operands is non-zero.
* Integer `0` if both operands are zero.

**Example:**

```cpp
obj_0 = 0.0;
("obj_0 || 0: %d\n" % (obj_0 || 0)).print();
("obj_0 || 1: %d\n" % (obj_0 || 1)).print();
obj_1 = 12.234;
("obj_1 || 0: %d\n" % (obj_1 || 0)).print();
("obj_1 || 1: %d\n" % (obj_1 || 1)).print();
```
```
obj_0 || 0: 0
obj_0 || 1: 1
obj_1 || 0: 1
obj_1 || 1: 1
```

<a name="operator_binary_double_equal#1" />

### Operator [`operator_binary_double_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3700)

Comparison operator `==`. Compares object of class `Float` with method parameter and return `1` if objects has same value or `0` otherwise.

**Parameters:**

1. Any type.

**Return:**

* Object of class `Integer`.
  * `0` - method parameter has different value than object.
  * `1` - method parameter has same value as object.

**Example:**

```cpp
obj_0 = 12.234;
obj_1 = 14.972;
obj_2 = obj_0;
("obj_0 == obj_1: %d\n" % (obj_0 == obj_1)).print();
("obj_0 == obj_2: %d\n" % (obj_0 == obj_2)).print();
```
```
obj_0 == obj_1: 0
obj_0 == obj_2: 1
```

<a name="operator_binary_exclamation_equal#1" />

### Operator [`operator_binary_exclamation_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3714)

Comparison operator `!=`. Compares object of class `Float` with method parameter and return `0` if objects has same value or `1` otherwise.

**Parameters:**

1. Any type.

**Return:**

* Object of class `Integer`.
  * `0` - method parameter has same value as object.
  * `1` - method parameter has different value than object.

**Example:**

```cpp
obj_0 = 12.234;
obj_1 = 14.972;
obj_2 = obj_0;
("obj_0 != obj_1: %d\n" % (obj_0 != obj_1)).print();
("obj_0 != obj_2: %d\n" % (obj_0 != obj_2)).print();
```
```
obj_0 != obj_1: 1
obj_0 != obj_2: 0
```

<a name="operator_binary_rs_br#1" />

### Operator [`operator_binary_rs_br#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3729)

Greater test operator `>`. Test if value of object of class `Float` is greater than value of method parameter.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Object of class `Integer`.
  * `1` - value of object of class `Float` is greater than value of method parameter.
  * `0` - value of object of class `Float` is less or equal than value of method parameter.

**Example:**

```cpp
obj = 549.2;
("obj: %s\n" % $obj).print();
("obj > 'e': %d\n" % (obj > 'e')).print();
("obj > 123: %d\n" % (obj > 123)).print();
("obj > 12.234: %d\n" % (obj > 12.234)).print();
```
```
obj: 549.200000
obj > 'e': 1
obj > 123: 1
obj > 12.234: 1
```

<a name="operator_binary_ls_br#1" />

### Operator [`operator_binary_ls_br#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3736)

Lesser test operator `<`. Test if value of object of class `Float` is lesser than value of method parameter.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Object of class `Integer`.
  * `1` - value of object of class `Float` is less than value of method parameter.
  * `0` - value of object of class `Float` is greater or equal than value of method parameter.

**Example:**

```cpp
obj = 549.2;
("obj: %s\n" % $obj).print();
("obj < 'e': %d\n" % (obj < 'e')).print();
("obj < 123: %d\n" % (obj < 123)).print();
("obj < 12.234: %d\n" % (obj < 12.234)).print();
```
```
obj: 549.200000
obj < 'e': 0
obj < 123: 0
obj < 12.234: 0
```

<a name="operator_binary_rs_br_equal#1" />

### Operator [`operator_binary_rs_br_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3743)

Greater or equal test operator `>=`. Test if value of object of class `Float` is greater or equal than value of method parameter.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Object of class `Integer`.
  * `1` - value of object of class `Float` is greater or equal than value of method parameter.
  * `0` - value of object of class `Float` is less than value of method parameter.

**Example:**

```cpp
obj = 549.2;
("obj: %s\n" % $obj).print();
("obj >= 'e': %d\n" % (obj >= 'e')).print();
("obj >= 123: %d\n" % (obj >= 123)).print();
("obj >= 12.234: %d\n" % (obj >= 12.234)).print();
```
```
obj: 549.200000
obj >= 'e': 1
obj >= 123: 1
obj >= 12.234: 1
```

<a name="operator_binary_ls_br_equal#1" />

### Operator [`operator_binary_ls_br_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3750)

Lesser or equal test operator `<=`. Test if value of object of class `Float` is lesser or equal than value of method parameter.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Object of class `Integer`.
  * `1` - value of object of class `Float` is less or equal than value of method parameter.
  * `0` - value of object of class `Float` is greater than value of method parameter.

**Example:**

```cpp
obj = 549.2;
("obj: %s\n" % $obj).print();
("obj <= 'e': %d\n" % (obj <= 'e')).print();
("obj <= 123: %d\n" % (obj <= 123)).print();
("obj <= 12.234: %d\n" % (obj <= 12.234)).print();
```
```
obj: 549.200000
obj <= 'e': 0
obj <= 123: 0
obj <= 12.234: 0
```

<a name="operator_binary_plus#1" />

### Operator [`operator_binary_plus#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3757)

Add operator `+`. Operator adds value of method parameter to value of object of class `Float`.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Object of class `Float`.

**Example:**

```cpp
obj = 549.2;
("obj: %s\n" % $obj).print();
res = obj + 'e';
("res: %s\n" % $res).print();
res = obj + 123;
("res: %s\n" % $res).print();
res = obj + 12.234;
("res: %s\n" % $res).print();
```
```
obj: 549.200000
res: 650.200000
res: 672.200000
res: 561.434000
```

<a name="operator_binary_minus#1" />

### Operator [`operator_binary_minus#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3764)

Subtract operator `-`. Operator subtracts value of method parameter from value of object of class `Float`.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Object of class `Float`.

**Example:**

```cpp
obj = 549.2;
("obj: %s\n" % $obj).print();
res = obj - 'e';
("res: %s\n" % $res).print();
res = obj - 123;
("res: %s\n" % $res).print();
res = obj - 12.234;
("res: %s\n" % $res).print();
```
```
obj: 549.200000
res: 448.200000
res: 426.200000
res: 536.966000
```

<a name="operator_binary_asterisk#1" />

### Operator [`operator_binary_asterisk#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3771)

Multiply operator `*`. It multiplies value of object of class `Float` by value of method parameter.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Object of class `Float`.

**Example:**

```cpp
obj = 2.532;
("obj: %s\n" % $obj).print();
res = obj * 'e';
("res: %s\n" % $res).print();
res = obj * 123;
("res: %s\n" % $res).print();
res = obj * 12.234;
("res: %s\n" % $res).print();
```
```
obj: 2.532000
res: 255.732000
res: 311.436000
res: 30.976488
```

<a name="operator_binary_slash#1" />

### Operator [`operator_binary_slash#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3778)

Divide operator `/`. Operator divides value of object of class `Float` by value of method parameter.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Object of class `Float`.

**Example:**

```cpp
obj = 549.2;
("obj: %s\n" % $obj).print();
res = obj / '\x02';
("res: %s\n" % $res).print();
res = obj / 2;
("res: %s\n" % $res).print();
res = obj / 2.532;
("res: %s\n" % $res).print();
```
```
obj: 549.200000
res: 274.600000
res: 274.600000
res: 216.903633
```

<a name="operator_unary_post_double_plus#0" />

### Operator [`operator_unary_post_double_plus#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3845)

Post increment operator `++`. Increase value of object of class `Float` by one.

**Return:**

* Value of object before incrementation.

**Example:**

```cpp
obj = 12.234;
("obj: %s\n" % $obj).print();
("obj++: %s\n" % $(obj++)).print();
("obj: %s\n" % $obj).print();
```
```
obj: 12.234000
obj++: 12.234000
obj: 13.234000
```

<a name="operator_unary_post_double_minus#0" />

### Operator [`operator_unary_post_double_minus#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3852)

Post decrement operator `--`. Decrease value of object of class `Float` by one.

**Return:**

* Value of object before decrementation.

**Example:**

```cpp
obj = 12.234;
("obj: %s\n" % $obj).print();
("obj--: %s\n" % $(obj--)).print();
("obj: %s\n" % $obj).print();
```
```
obj: 12.234000
obj--: 12.234000
obj: 11.234000
```

<a name="operator_unary_pre_double_plus#0" />

### Operator [`operator_unary_pre_double_plus#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3859)

Pre increment operator `++`. Increase value of object of class `Float` by one.

**Return:**

* Value of object.

**Example:**

```cpp
obj = 12.234;
("obj: %s\n" % $obj).print();
("++obj: %s\n" % $(++obj)).print();
("obj: %s\n" % $obj).print();
```
```
obj: 12.234000
++obj: 13.234000
obj: 13.234000
```

<a name="operator_unary_pre_double_minus#0" />

### Operator [`operator_unary_pre_double_minus#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3866)

Pre decrement operator `--`. Decrease value of object of class `Float` by one.

**Return:**

* Value of object.

**Example:**

```cpp
obj = 12.234;
("obj: %s\n" % $obj).print();
("--obj: %s\n" % $(--obj)).print();
("obj: %s\n" % $obj).print();
```
```
obj: 12.234000
--obj: 11.234000
obj: 11.234000
```

<a name="operator_unary_pre_plus#0" />

### Operator [`operator_unary_pre_plus#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3873)

Unary operator `+`. Return value of object of class `Float`.

**Return:**

* Object of class `Float`.

**Example:**

```cpp
obj = 12.234;
("obj: %s\n" % $obj).print();
obj = +obj;
("obj: %s\n" % $obj).print();
```
```
obj: 12.234000
obj: 12.234000
```

<a name="operator_unary_pre_minus#0" />

### Operator [`operator_unary_pre_minus#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3880)

Unary negative operator `-`. Return negative value of object of class `Float`.

**Return:**

* Object of class `Float`.

**Example:**

```cpp
obj = 12.234;
("obj: %s\n" % $obj).print();
obj = -obj;
("obj: %s\n" % $obj).print();
```
```
obj: 12.234000
obj: -12.234000
```

<a name="operator_unary_pre_exclamation#0" />

### Operator [`operator_unary_pre_exclamation#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3887)

Logical NOT operator `!`. Reverse logical state of value of object of class `Float`.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
obj = 12.234;
("obj: %s\n" % $obj).print();
obj = !obj;
("obj: %s\n" % $obj).print();
```
```
obj: 12.234000
obj: 0
```

-----

## Methods

<a name="sin#0" />

### Method [`sin#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3947)

Compute sine of value of object of class `Float`. Angle is given in radians.

**Return:**

Object of class `Float`.

**Example:**

```cpp
pi = 3.1415926535897932384626433;
("res: %f\n" % (0.0).sin()).print();
("res: %f\n" % (0.25 * pi).sin()).print();
("res: %f\n" % (0.5 * pi).sin()).print();
("res: %f\n" % (0.75 * pi).sin()).print();
```
```
res: 0.000000
res: 0.707107
res: 1.000000
res: 0.707107
```

<a name="cos#0" />

### Method [`cos#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3954)

Compute cosine of value of object of class `Float`. Angle is given in radians.

**Return:**

Object of class `Float`.

**Example:**

```cpp
pi = 3.1415926535897932384626433;
("res: %f\n" % (0.0).cos()).print();
("res: %f\n" % (0.25 * pi).cos()).print();
("res: %f\n" % (0.5 * pi).cos()).print();
("res: %f\n" % (0.75 * pi).cos()).print();
```
```
res: 1.000000
res: 0.707107
res: 0.000000
res: -0.707107
```

<a name="tan#0" />

### Method [`tan#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3961)

Compute tangent of value of object of class `Float`. Angle is given in radians.

**Return:**

Object of class `Float`.

**Example:**

```cpp
pi = 3.1415926535897932384626433;
("res: %f\n" % (0.0).tan()).print();
("res: %f\n" % (0.25 * pi).tan()).print();
("res: %f\n" % (0.5 * pi).tan()).print();
("res: %f\n" % (0.75 * pi).tan()).print();
```
```
res: 0.000000
res: 1.000000
res: 16331239353195370.000000
res: -1.000000
```

<a name="asin#0" />

### Method [`asin#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3968)

Compute principal value of arc sine of value of object of class `Float`. Result
value represents angle in radians whose sine is equal to value of object of class
`Float`.

**Return:**

Object of class `Float`.

**Example:**

```cpp
pi = 3.1415926535897932384626433;
("res: %f\n" % (0.0.asin()/pi)).print();
("res: %f\n" % ((2.0.sqrt()/2).asin()/pi)).print();
("res: %f\n" % (1.0.asin()/pi)).print();
```
```
res: 0.000000
res: 0.250000
res: 0.500000
```

<a name="acos#0" />

### Method [`acos#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3975)

Compute principal value of arc cosine of value of object of class `Float`. Result
value represents angle in radians whose cosine is equal to value of object of class
`Float`.

**Return:**

Object of class `Float`.

**Example:**

```cpp
pi = 3.1415926535897932384626433;
("res: %f\n" % (0.0.acos()/pi)).print();
("res: %f\n" % ((2.0.sqrt()/2).acos()/pi)).print();
("res: %f\n" % (1.0.acos()/pi)).print();
```
```
res: 0.500000
res: 0.250000
res: 0.000000
```

<a name="atan#0" />

### Method [`atan#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3982)

Compute principal value of arc tangent of value of object of class `Float`. Result
value represents angle in radians whose tangent is equal to value of object of class
`Float`.

**Return:**

Object of class `Float`.

**Example:**

```cpp
pi = 3.1415926535897932384626433;
("res: %f\n" % (0.0.atan()/pi)).print();
("res: %f\n" % ((2.0.sqrt()/2).atan()/pi)).print();
("res: %f\n" % (1.0.atan()/pi)).print();
```
```
res: 0.000000
res: 0.195913
res: 0.250000
```

<a name="exp#0" />

### Method [`exp#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3989)

Compute value of e (the base  of  natural  logarithms) raised to the power
determined by value of object of class `Float`.

**Return:**

Object of class `Float`.

**Example:**

```cpp
("res: %f\n" % 0.0.exp()).print();
("res: %f\n" % 1.0.exp()).print();
("res: %f\n" % 10.0.exp()).print();
```
```
res: 1.000000
res: 2.718282
res: 22026.465795
```

<a name="log#0" />

### Method [`log#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3996)

Compute natural logarithm of value of object of class `Float`.

**Return:**

Object of class `Float`.

**Example:**

```cpp
("res: %f\n" % 1.0.log()).print();
("res: %f\n" % 2.718282.log()).print();
("res: %f\n" % 22026.465795.log()).print();
```
```
res: 0.000000
res: 1.000000
res: 10.000000
```

<a name="pow#1" />

### Method [`pow#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L4003)

Compute power of value of object of class `Float` raised to the value given by method parameter.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

Object of class `Float`.

**Example:**

```cpp
obj = 549.2;
("obj: %f\n" % obj).print();
("res: %f\n" % obj.pow('\x02')).print();
("res: %f\n" % obj.pow(2)).print();
("res: %f\n" % obj.pow(2.532)).print();
```
```
obj: 549.200000
res: 301620.640000
res: 301620.640000
res: 8649633.346304
```

<a name="sqrt#0" />

### Method [`sqrt#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L4010)

Compute nonnegative square root of value of object of class `Float`.

**Return:**

Object of class `Float`.

**Example:**

```cpp
("res: %f\n" % 25.0.sqrt()).print();
("res: %f\n" % 144.0.sqrt()).print();
("res: %f\n" % 11..sqrt()).print();
```
```
res: 5.000000
res: 12.000000
res: 3.316625
```

<a name="cbrt#0" />

### Method [`cbrt#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L4017)

Compute real cube root of value of object of class `Float`.

**Return:**

Object of class `Float`.

**Example:**

```cpp
("res: %f\n" % 1000.0.cbrt()).print();
("res: %f\n" % 1331.0.cbrt()).print();
("res: %f\n" % 11..cbrt()).print();
```
```
res: 10.000000
res: 11.000000
res: 2.223980
```

<a name="hypot#1" />

### Method [`hypot#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L4024)

Compute length of the hypotenuse of a right-angled triangle with sides
determined by value of object of class `Float` and method parameter.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

Object of class `Float`.

**Example:**

```cpp
obj = 549.2;
("obj: %f\n" % obj).print();
("res: %f\n" % obj.hypot('e')).print();
("res: %f\n" % obj.hypot(123)).print();
("res: %f\n" % obj.hypot(12.234)).print();
```
```
obj: 549.200000
res: 558.409921
res: 562.805153
res: 549.336246
```

<a name="classify#0" />

### Method [`classify#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L4031)

Return `Integer` identifying float number class.

**Return:**

Object of class `Integer`.

**Example:**

```cpp
("res: %d\n" % (Float.INFINITY / Float.INFINITY).classify()).print();
("res: %d\n" % (Float.INFINITY).classify()).print();
("res: %d\n" % 0.0.classify()).print();
("res: %d\n" % 12.234.classify()).print();
```
```
res: 0
res: 1
res: 2
res: 4
```

<a name="isnan#0" />

### Method [`isnan#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L4042)

Test if value of object of class `Float` is not an number.

**Return:**

Object of class `Integer`.

**Example:**

```cpp
("res: %d\n" % 1000.0.isnan()).print();
("res: %d\n" % ((-1.0).sqrt()).isnan()).print();
```
```
res: 0
res: 1
```

<a name="compare#1" />

### Method `spec` [`compare#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L4053)

Compare object of class `Float` with method parameter.

**Parameters:**

1. Any type.

**Return:**

* Integer `-1` if object of class `Float` is lesser than method parameter.
* Integer `1` if object of class `Float` is greater than method parameter.
* Integer `0` if object of class `Float` is equal to method parameter.

**Example:**

```cpp
obj_0 = 12.234;
obj_1 = 14.972;
("obj_0.compare(obj_1): %d\n" % obj_0.compare(obj_1)).print();
("obj_1.compare(obj_0): %d\n" % obj_1.compare(obj_0)).print();
("obj_0.compare(obj_0): %d\n" % obj_0.compare(obj_0)).print();
```
```
obj_0.compare(obj_1): -1
obj_1.compare(obj_0): 1
obj_0.compare(obj_0): 0
```

<a name="to_string#0" />

### Method `spec` [`to_string#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L4077)

Convert object of class `Float` to object of class `String`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
obj = 12.234;
("obj.to_string(): %s\n" % obj.to_string()).print();
```
```
obj.to_string(): 12.234000
```

<a name="print#0" />

### Method `spec` [`print#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L4086)

Print string representation of object of class `Float` to standard output.

**Return:**

* Object of class `Float`.

**Example:**

```cpp
obj = 12.234;
obj.print();
"\n".print();
```
```
12.234000
```
