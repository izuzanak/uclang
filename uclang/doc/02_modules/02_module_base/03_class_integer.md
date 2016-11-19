# Class Integer

Class describing signed 64bit integer numbers.

-----

## Table of methods

* Constructors

  * Constructor [`Integer#0`](#Integer%230)
  * Constructor [`Integer#1`](#Integer%231)
  * Constructor [`Integer#2`](#Integer%232)

* Operators

  * Operator [`operator_binary_equal#1`](#operator_binary_equal%231)
  * Operator [`operator_binary_plus_equal#1`](#operator_binary_plus_equal%231)
  * Operator [`operator_binary_minus_equal#1`](#operator_binary_minus_equal%231)
  * Operator [`operator_binary_asterisk_equal#1`](#operator_binary_asterisk_equal%231)
  * Operator [`operator_binary_slash_equal#1`](#operator_binary_slash_equal%231)
  * Operator [`operator_binary_percent_equal#1`](#operator_binary_percent_equal%231)
  * Operator [`operator_binary_double_ls_br_equal#1`](#operator_binary_double_ls_br_equal%231)
  * Operator [`operator_binary_double_rs_br_equal#1`](#operator_binary_double_rs_br_equal%231)
  * Operator [`operator_binary_ampersand_equal#1`](#operator_binary_ampersand_equal%231)
  * Operator [`operator_binary_pipe_equal#1`](#operator_binary_pipe_equal%231)
  * Operator [`operator_binary_circumflex_equal#1`](#operator_binary_circumflex_equal%231)
  * Operator [`operator_binary_double_ampersand#1`](#operator_binary_double_ampersand%231)
  * Operator [`operator_binary_double_pipe#1`](#operator_binary_double_pipe%231)
  * Operator [`operator_binary_ampersand#1`](#operator_binary_ampersand%231)
  * Operator [`operator_binary_pipe#1`](#operator_binary_pipe%231)
  * Operator [`operator_binary_circumflex#1`](#operator_binary_circumflex%231)
  * Operator [`operator_binary_double_equal#1`](#operator_binary_double_equal%231)
  * Operator [`operator_binary_exclamation_equal#1`](#operator_binary_exclamation_equal%231)
  * Operator [`operator_binary_rs_br#1`](#operator_binary_rs_br%231)
  * Operator [`operator_binary_ls_br#1`](#operator_binary_ls_br%231)
  * Operator [`operator_binary_rs_br_equal#1`](#operator_binary_rs_br_equal%231)
  * Operator [`operator_binary_ls_br_equal#1`](#operator_binary_ls_br_equal%231)
  * Operator [`operator_binary_double_rs_br#1`](#operator_binary_double_rs_br%231)
  * Operator [`operator_binary_double_ls_br#1`](#operator_binary_double_ls_br%231)
  * Operator [`operator_binary_plus#1`](#operator_binary_plus%231)
  * Operator [`operator_binary_minus#1`](#operator_binary_minus%231)
  * Operator [`operator_binary_asterisk#1`](#operator_binary_asterisk%231)
  * Operator [`operator_binary_slash#1`](#operator_binary_slash%231)
  * Operator [`operator_binary_percent#1`](#operator_binary_percent%231)
  * Operator [`operator_unary_post_double_plus#0`](#operator_unary_post_double_plus%230)
  * Operator [`operator_unary_post_double_minus#0`](#operator_unary_post_double_minus%230)
  * Operator [`operator_unary_pre_double_plus#0`](#operator_unary_pre_double_plus%230)
  * Operator [`operator_unary_pre_double_minus#0`](#operator_unary_pre_double_minus%230)
  * Operator [`operator_unary_pre_plus#0`](#operator_unary_pre_plus%230)
  * Operator [`operator_unary_pre_minus#0`](#operator_unary_pre_minus%230)
  * Operator [`operator_unary_pre_exclamation#0`](#operator_unary_pre_exclamation%230)
  * Operator [`operator_unary_pre_tilde#0`](#operator_unary_pre_tilde%230)

* Methods

  * Method [`compare#1`](#compare%231)
  * Method [`to_string#0`](#to_string%230)
  * Method [`print#0`](#print%230)

-----

## Constructors

<a name="Integer#0" />

### Constructor [`Integer#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2960)

Creates default object of class `Integer`.

**Example:**

```cpp
obj = new Integer();
("obj: %s\n" % obj.to_string()).print();
```
```
obj: 0
```

<a name="Integer#1" />

### Constructor [`Integer#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2965)

Creates object of class `Integer` from method parameter.

**Parameters:**

1. Object of class `Char`, `Integer`, `Float` or `String`.

**Example:**

```cpp
("obj: %d\n" % new Integer('e')).print();
("obj: %d\n" % new Integer(123)).print();
("obj: %d\n" % new Integer(12.234)).print();
("obj: %d\n" % new Integer("512")).print();
("obj: %d\n" % new Integer("0xff")).print();
```
```
obj: 101
obj: 123
obj: 12
obj: 512
obj: 255
```

<a name="Integer#2" />

### Constructor [`Integer#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3011)

Creates object of class `Integer` from its string representation.

**Parameters:**

1. Object of class `String`, containing string representation of integer value.
2. Object of class `Integer`, representing base of integer stored in first method parameter. Must be value from 2 to 36.

**Example:**

```cpp
("obj: %d\n" % new Integer("1110",2)).print();
("obj: %d\n" % new Integer("777",8)).print();
("obj: %d\n" % new Integer("1245",10)).print();
("obj: %d\n" % new Integer("7e",16)).print();
("obj: %d\n" % new Integer("0xfff",16)).print();
```
```
obj: 14
obj: 511
obj: 1245
obj: 126
obj: 4095
```

-----

## Operators

<a name="operator_binary_equal#1" />

### Operator [`operator_binary_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2188)

Assignment operator `=`. Object of class `Integer` is replaced by method parameter.

**Parameters:**

1. Any type.

**Return:**

* Method parameter.

**Example:**

```cpp
obj = 123;
("obj: %s\n" % obj.to_string()).print();
obj = "New value";
("obj: %s\n" % obj.to_string()).print();
```
```
obj: 123
obj: New value
```

<a name="operator_binary_plus_equal#1" />

### Operator [`operator_binary_plus_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2514)

Add and assign operator `+=`. Operator adds value of method parameter to value of object of class `Integer`.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Value of object.

**Example:**

```cpp
obj = 567;
("obj: %s\n" % obj.to_string()).print();
obj += 'e';
("obj: %s\n" % obj.to_string()).print();
obj += 123;
("obj: %s\n" % obj.to_string()).print();
obj += 12.234;
("obj: %s\n" % obj.to_string()).print();
```
```
obj: 567
obj: 668
obj: 791
obj: 803
```

<a name="operator_binary_minus_equal#1" />

### Operator [`operator_binary_minus_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2521)

Subtract and assign operator `-=`. Operator subtracts value of method parameter from value of object of class `Integer`.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Value of object.

**Example:**

```cpp
obj = 567;
("obj: %s\n" % obj.to_string()).print();
obj -= 'e';
("obj: %s\n" % obj.to_string()).print();
obj -= 123;
("obj: %s\n" % obj.to_string()).print();
obj -= 12.234;
("obj: %s\n" % obj.to_string()).print();
```
```
obj: 567
obj: 466
obj: 343
obj: 330
```

<a name="operator_binary_asterisk_equal#1" />

### Operator [`operator_binary_asterisk_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2528)

Multiply and assign operator `*=`. Operator multiplies value of object of class `Integer` by value of method parameter.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Value of object.

**Example:**

```cpp
obj = 567;
("obj: %s\n" % obj.to_string()).print();
obj *= 'e';
("obj: %s\n" % obj.to_string()).print();
obj *= 123;
("obj: %s\n" % obj.to_string()).print();
obj *= 12.234;
("obj: %s\n" % obj.to_string()).print();
```
```
obj: 567
obj: 57267
obj: 7043841
obj: 86174350
```

<a name="operator_binary_slash_equal#1" />

### Operator [`operator_binary_slash_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2535)

Divide and assign operator `/=`. Operator divides value of object of class `Integer` by value of method parameter.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Value of object.

**Example:**

```cpp
obj = 0xffffffff;
obj /= 'e';
("obj: %s\n" % obj.to_string()).print();
obj = 0xffffffff;
obj /= 123;
("obj: %s\n" % obj.to_string()).print();
obj = 0xffffffff;
obj /= 12.234;
("obj: %s\n" % obj.to_string()).print();
```
```
obj: 42524428
obj: 34918433
obj: 351068113
```

<a name="operator_binary_percent_equal#1" />

### Operator [`operator_binary_percent_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2603)

Modulus and assign operator `%=`. Operator computes modulus of value of object of class `Integer` divided by value of method parameter.

**Parameters:**

1. Object of class `Char` or `Integer`.

**Return:**

* Value of object.

**Example:**

```cpp
obj = 567;
obj %= 'e';
("obj: %s\n" % obj.to_string()).print();
obj = 567;
obj %= 123;
("obj: %s\n" % obj.to_string()).print();
```
```
obj: 62
obj: 75
```

<a name="operator_binary_double_ls_br_equal#1" />

### Operator [`operator_binary_double_ls_br_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2610)

Left shift and assign operator `<<=`. Value of object of class `Integer` is shifted to left by count of bits given by method parameter.

**Parameters:**

1. Object of class `Char` or `Integer`.

**Return:**

* Value of object.

**Example:**

```cpp
obj = 567;
("obj: %s\n" % obj.to_string()).print();
obj <<= '\x02';
("obj: %s\n" % obj.to_string()).print();
obj <<= 2;
("obj: %s\n" % obj.to_string()).print();
```
```
obj: 567
obj: 2268
obj: 9072
```

<a name="operator_binary_double_rs_br_equal#1" />

### Operator [`operator_binary_double_rs_br_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2617)

Right shift and assign operator `>>=`. Value of object of class `Integer` is shifted to right by count of bits given by method parameter.

**Parameters:**

1. Object of class `Char` or `Integer`.

**Return:**

* Value of object.

**Example:**

```cpp
obj = 567;
("obj: %s\n" % obj.to_string()).print();
obj >>= '\x02';
("obj: %s\n" % obj.to_string()).print();
obj >>= 2;
("obj: %s\n" % obj.to_string()).print();
```
```
obj: 567
obj: 141
obj: 35
```

<a name="operator_binary_ampersand_equal#1" />

### Operator [`operator_binary_ampersand_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2624)

Bitwise AND and assign operator `&=`. Value of
object of class `Integer` is modified according to value given by
method parameter. Bit in result value is set, if it exists in
object of class `Integer` and method parameter.

**Parameters:**

1. Object of class `Char` or `Integer`.

**Return:**

* Value of object.

**Example:**

```cpp
obj = 567;
obj &= 'e';
("obj: %s\n" % obj.to_string()).print();
obj = 567;
obj &= 123;
("obj: %s\n" % obj.to_string()).print();
```
```
obj: 37
obj: 51
```

<a name="operator_binary_pipe_equal#1" />

### Operator [`operator_binary_pipe_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2631)

Bitwise OR and assign operator `|=`. Value of
object of class `Integer` is modified according to value given by
method parameter. Bit in result value is set, if it exists in
object of class `Integer` or in method parameter.

**Parameters:**

1. Object of class `Char` or `Integer`.

**Return:**

* Value of object.

**Example:**

```cpp
obj = 567;
obj |= 'e';
("obj: %s\n" % obj.to_string()).print();
obj = 567;
obj |= 123;
("obj: %s\n" % obj.to_string()).print();
```
```
obj: 631
obj: 639
```

<a name="operator_binary_circumflex_equal#1" />

### Operator [`operator_binary_circumflex_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2638)

Bitwise XOR and assign operator `^=`. Value of
object of class `Integer` is modified according to value given by
method parameter. Bit in result value is set, if it exists in
object of class `Integer` or in method parameter, but not both.

**Parameters:**

1. Object of class `Char` or `Integer`.

**Return:**

* Value of object.

**Example:**

```cpp
obj = 567;
obj ^= 'e';
("obj: %s\n" % obj.to_string()).print();
obj = 567;
obj ^= 123;
("obj: %s\n" % obj.to_string()).print();
```
```
obj: 594
obj: 588
```

<a name="operator_binary_double_ampersand#1" />

### Operator [`operator_binary_double_ampersand#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2645)

Logical AND operator `&&`.  If object of class
`Integer` is non-zero and value of method parameter is also non-zero
condition becomes true.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Integer `1` if both operands are non-zero.
* Integer `0` if either of operands is zero.

**Example:**

```cpp
obj_0 = 0;
("obj_0 && 0: %d\n" % (obj_0 && 0)).print();
("obj_0 && 1: %d\n" % (obj_0 && 1)).print();
obj_1 = 123;
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

### Operator [`operator_binary_double_pipe#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2652)

Logical OR operator `||`.  If object of class
`Integer` is non-zero or value of method parameter is non-zero
condition becomes true.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Integer `1` if either of operands is non-zero.
* Integer `0` if both operands are zero.

**Example:**

```cpp
obj_0 = 0;
("obj_0 || 0: %d\n" % (obj_0 || 0)).print();
("obj_0 || 1: %d\n" % (obj_0 || 1)).print();
obj_1 = 123;
("obj_1 || 0: %d\n" % (obj_1 || 0)).print();
("obj_1 || 1: %d\n" % (obj_1 || 1)).print();
```
```
obj_0 || 0: 0
obj_0 || 1: 1
obj_1 || 0: 1
obj_1 || 1: 1
```

<a name="operator_binary_ampersand#1" />

### Operator [`operator_binary_ampersand#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2659)

Bitwise AND operator `&`. Bit in result value is set, if it exists in object of class `Integer` and in method parameter.

**Parameters:**

1. Object of class `Char` or `Integer`.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
obj = 567;
("obj & 'e': %d\n" % (obj & 'e')).print();
("obj & 123: %d\n" % (obj & 123)).print();
```
```
obj & 'e': 37
obj & 123: 51
```

<a name="operator_binary_pipe#1" />

### Operator [`operator_binary_pipe#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2666)

Bitwise OR operator `|`. Bit in result value is set, if it exists in object of class `Integer` or in method parameter.

**Parameters:**

1. Object of class `Char` or `Integer`.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
obj = 567;
("obj | 'e': %d\n" % (obj | 'e')).print();
("obj | 123: %d\n" % (obj | 123)).print();
```
```
obj | 'e': 631
obj | 123: 639
```

<a name="operator_binary_circumflex#1" />

### Operator [`operator_binary_circumflex#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2673)

Bitwise XOR operator `^`. Bit in result value is set, if it exists in object of class `Integer` or in method parameter, but not both.

**Parameters:**

1. Object of class `Char` or `Integer`.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
obj = 567;
("obj ^ 'e': %d\n" % (obj ^ 'e')).print();
("obj ^ 123: %d\n" % (obj ^ 123)).print();
```
```
obj ^ 'e': 594
obj ^ 123: 588
```

<a name="operator_binary_double_equal#1" />

### Operator [`operator_binary_double_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2680)

Comparison operator `==`. Compares object of class `Integer` with method parameter and return `1` if objects has same value or `0` otherwise.

**Parameters:**

1. Any type.

**Return:**

* Object of class `Integer`.
  * `0` - method parameter has different value than object.
  * `1` - method parameter has same value as object.

**Example:**

```cpp
obj_0 = 123;
obj_1 = 0xff;
obj_2 = obj_0;
("obj_0 == obj_1: %d\n" % (obj_0 == obj_1)).print();
("obj_0 == obj_2: %d\n" % (obj_0 == obj_2)).print();
```
```
obj_0 == obj_1: 0
obj_0 == obj_2: 1
```

<a name="operator_binary_exclamation_equal#1" />

### Operator [`operator_binary_exclamation_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2695)

Comparison operator `!=`. Compares object of class `Integer` with method parameter and return `0` if objects has same value or `1` otherwise.

**Parameters:**

1. Any type.

**Return:**

* Object of class `Integer`.
  * `0` - method parameter has same value as object.
  * `1` - method parameter has different value than object.

**Example:**

```cpp
obj_0 = 123;
obj_1 = 0xff;
obj_2 = obj_0;
("obj_0 != obj_1: %d\n" % (obj_0 != obj_1)).print();
("obj_0 != obj_2: %d\n" % (obj_0 != obj_2)).print();
```
```
obj_0 != obj_1: 1
obj_0 != obj_2: 0
```

<a name="operator_binary_rs_br#1" />

### Operator [`operator_binary_rs_br#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2711)

Greater test operator `>`. Test if value of object of class `Integer` is greater than value of method parameter.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Object of class `Integer`.
  * `1` - value of object of class `Integer` is greater than value of method parameter.
  * `0` - value of object of class `Integer` is less or equal than value of method parameter.

**Example:**

```cpp
obj = 567;
("obj: %s\n" % obj.to_string()).print();
("obj > 'e': %d\n" % (obj > 'e')).print();
("obj > 123: %d\n" % (obj > 123)).print();
("obj > 12.234: %d\n" % (obj > 12.234)).print();
```
```
obj: 567
obj > 'e': 1
obj > 123: 1
obj > 12.234: 1
```

<a name="operator_binary_ls_br#1" />

### Operator [`operator_binary_ls_br#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2718)

Lesser test operator `<`. Test if value of object of class `Integer` is lesser than value of method parameter.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Object of class `Integer`.
  * `1` - value of object of class `Integer` is less than value of method parameter.
  * `0` - value of object of class `Integer` is greater or equal than value of method parameter.

**Example:**

```cpp
obj = 567;
("obj: %s\n" % obj.to_string()).print();
("obj < 'e': %d\n" % (obj < 'e')).print();
("obj < 123: %d\n" % (obj < 123)).print();
("obj < 12.234: %d\n" % (obj < 12.234)).print();
```
```
obj: 567
obj < 'e': 0
obj < 123: 0
obj < 12.234: 0
```

<a name="operator_binary_rs_br_equal#1" />

### Operator [`operator_binary_rs_br_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2725)

Greater or equal test operator `>=`. Test if value of object of class `Integer` is greater or equal than value of method parameter.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Object of class `Integer`.
  * `1` - value of object of class `Integer` is greater or equal than value of method parameter.
  * `0` - value of object of class `Integer` is less than value of method parameter.

**Example:**

```cpp
obj = 567;
("obj: %s\n" % obj.to_string()).print();
("obj >= 'e': %d\n" % (obj >= 'e')).print();
("obj >= 123: %d\n" % (obj >= 123)).print();
("obj >= 12.234: %d\n" % (obj >= 12.234)).print();
```
```
obj: 567
obj >= 'e': 1
obj >= 123: 1
obj >= 12.234: 1
```

<a name="operator_binary_ls_br_equal#1" />

### Operator [`operator_binary_ls_br_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2732)

Lesser or equal test operator `<=`. Test if value of object of class `Integer` is lesser or equal than value of method parameter.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Object of class `Integer`.
  * `1` - value of object of class `Integer` is less or equal than value of method parameter.
  * `0` - value of object of class `Integer` is greater than value of method parameter.

**Example:**

```cpp
obj = 567;
("obj: %s\n" % obj.to_string()).print();
("obj <= 'e': %d\n" % (obj <= 'e')).print();
("obj <= 123: %d\n" % (obj <= 123)).print();
("obj <= 12.234: %d\n" % (obj <= 12.234)).print();
```
```
obj: 567
obj <= 'e': 0
obj <= 123: 0
obj <= 12.234: 0
```

<a name="operator_binary_double_rs_br#1" />

### Operator [`operator_binary_double_rs_br#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2739)

Right shift operator `>>`. Value of object of class `Integer` is shifted to right by count of bits given by method parameter.

**Parameters:**

1. Object of class `Char` or `Integer`.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
obj = 567;
("obj: %s\n" % obj.to_string()).print();
res = obj >> '\x02';
("res: %s\n" % res.to_string()).print();
res = obj >> 2;
("res: %s\n" % res.to_string()).print();
```
```
obj: 567
res: 141
res: 141
```

<a name="operator_binary_double_ls_br#1" />

### Operator [`operator_binary_double_ls_br#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2746)

Left shift operator `<<`. Value of object of class `Integer` is shifted to left by count of bits given by method parameter.

**Parameters:**

1. Object of class `Char` or `Integer`.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
obj = 567;
("obj: %s\n" % obj.to_string()).print();
res = obj << '\x02';
("res: %s\n" % res.to_string()).print();
res = obj << 2;
("res: %s\n" % res.to_string()).print();
```
```
obj: 567
res: 2268
res: 2268
```

<a name="operator_binary_plus#1" />

### Operator [`operator_binary_plus#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2753)

Add operator `+`. Operator adds value of method parameter to value of object of class `Integer`.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Object of class `Integer` or `Float`.

**Example:**

```cpp
obj = 567;
("obj: %s\n" % obj.to_string()).print();
res = obj + 'e';
("res: %s\n" % res.to_string()).print();
res = obj + 123;
("res: %s\n" % res.to_string()).print();
res = obj + 12.234;
("res: %s\n" % res.to_string()).print();
```
```
obj: 567
res: 668
res: 690
res: 579.234000
```

<a name="operator_binary_minus#1" />

### Operator [`operator_binary_minus#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2760)

Subtract operator `-`. Operator subtracts value of method parameter from value of object of class `Integer`.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Object of class `Integer` or `Float`.

**Example:**

```cpp
obj = 567;
("obj: %s\n" % obj.to_string()).print();
res = obj - 'e';
("res: %s\n" % res.to_string()).print();
res = obj - 123;
("res: %s\n" % res.to_string()).print();
res = obj - 12.234;
("res: %s\n" % res.to_string()).print();
```
```
obj: 567
res: 466
res: 444
res: 554.766000
```

<a name="operator_binary_asterisk#1" />

### Operator [`operator_binary_asterisk#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2767)

Multiply operator `*`. It multiplies value of object of class `Integer` by value of method parameter.
If method parameter is object of class `String`, then result will be created as repeated concatenation of this string.

**Parameters:**

1. Object of class `Char`, `Integer`, `Float` or `String`.

**Return:**

* Object of class `Integer`, `Float` or `String`.

**Example:**

```cpp
obj = 2;
("obj: %s\n" % obj.to_string()).print();
res = obj * 'e';
("res: %s\n" % res.to_string()).print();
res = obj * 123;
("res: %s\n" % res.to_string()).print();
res = obj * 12.234;
("res: %s\n" % res.to_string()).print();
res = obj * "Hi world!";
("res: %s\n" % res.to_string()).print();
```
```
obj: 2
res: 202
res: 246
res: 24.468000
res: Hi world!Hi world!
```

<a name="operator_binary_slash#1" />

### Operator [`operator_binary_slash#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2825)

Divide operator `/`. Operator divides value of object of class `Integer` by value of method parameter.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Object of class `Integer` or `Float`.

**Example:**

```cpp
obj = 567;
("obj: %s\n" % obj.to_string()).print();
res = obj / '\x02';
("res: %s\n" % res.to_string()).print();
res = obj / 2;
("res: %s\n" % res.to_string()).print();
res = obj / 2.532;
("res: %s\n" % res.to_string()).print();
```
```
obj: 567
res: 283
res: 283
res: 223.933649
```

<a name="operator_binary_percent#1" />

### Operator [`operator_binary_percent#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2897)

Modulus operator `%`. Operator computes modulus of value of object of class `Integer` divided by value of method parameter.

**Parameters:**

1. Object of class `Char` or `Integer`.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
obj = 567;
("obj: %s\n" % obj.to_string()).print();
res = obj % 'e';
("res: %s\n" % res.to_string()).print();
res = obj % 123;
("res: %s\n" % res.to_string()).print();
```
```
obj: 567
res: 62
res: 75
```

<a name="operator_unary_post_double_plus#0" />

### Operator [`operator_unary_post_double_plus#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2904)

Post increment operator `++`. Increase value of object of class `Integer` by one.

**Return:**

* Value of object before incrementation.

**Example:**

```cpp
obj = 123;
("obj: %s\n" % obj.to_string()).print();
("obj++: %s\n" % (obj++).to_string()).print();
("obj: %s\n" % obj.to_string()).print();
```
```
obj: 123
obj++: 123
obj: 124
```

<a name="operator_unary_post_double_minus#0" />

### Operator [`operator_unary_post_double_minus#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2911)

Post decrement operator `--`. Decrease value of object of class `Integer` by one.

**Return:**

* Value of object before decrementation.

**Example:**

```cpp
obj = 123;
("obj: %s\n" % obj.to_string()).print();
("obj--: %s\n" % (obj--).to_string()).print();
("obj: %s\n" % obj.to_string()).print();
```
```
obj: 123
obj--: 123
obj: 122
```

<a name="operator_unary_pre_double_plus#0" />

### Operator [`operator_unary_pre_double_plus#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2918)

Pre increment operator `++`. Increase value of object of class `Integer` by one.

**Return:**

* Value of object.

**Example:**

```cpp
obj = 123;
("obj: %s\n" % obj.to_string()).print();
("++obj: %s\n" % (++obj).to_string()).print();
("obj: %s\n" % obj.to_string()).print();
```
```
obj: 123
++obj: 124
obj: 124
```

<a name="operator_unary_pre_double_minus#0" />

### Operator [`operator_unary_pre_double_minus#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2925)

Pre decrement operator `--`. Decrease value of object of class `Integer` by one.

**Return:**

* Value of object.

**Example:**

```cpp
obj = 123;
("obj: %s\n" % obj.to_string()).print();
("--obj: %s\n" % (--obj).to_string()).print();
("obj: %s\n" % obj.to_string()).print();
```
```
obj: 123
--obj: 122
obj: 122
```

<a name="operator_unary_pre_plus#0" />

### Operator [`operator_unary_pre_plus#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2932)

Unary operator `+`. Return value of object of class `Integer`.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
obj = 123;
("obj: %s\n" % obj.to_string()).print();
obj = +obj;
("obj: %s\n" % obj.to_string()).print();
```
```
obj: 123
obj: 123
```

<a name="operator_unary_pre_minus#0" />

### Operator [`operator_unary_pre_minus#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2939)

Unary negative operator `-`. Return negative value of object of class `Integer`.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
obj = 123;
("obj: %s\n" % obj.to_string()).print();
obj = -obj;
("obj: %s\n" % obj.to_string()).print();
```
```
obj: 123
obj: -123
```

<a name="operator_unary_pre_exclamation#0" />

### Operator [`operator_unary_pre_exclamation#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2946)

Logical NOT operator `!`. Reverse logical state of value of object of class `Integer`.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
obj = 123;
("obj: %s\n" % obj.to_string()).print();
obj = !obj;
("obj: %s\n" % obj.to_string()).print();
```
```
obj: 123
obj: 0
```

<a name="operator_unary_pre_tilde#0" />

### Operator [`operator_unary_pre_tilde#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L2953)

Bitwise complement operator `~`. Return binary complement of value of object of class `Integer`.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
obj = 123;
("obj: %s\n" % obj.to_string()).print();
obj = ~obj;
("obj: %s\n" % obj.to_string()).print();
```
```
obj: 123
obj: -124
```

-----

## Methods

<a name="compare#1" />

### Method `spec` [`compare#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3070)

Compare object of class `Integer` with method parameter.

**Parameters:**

1. Any type.

**Return:**

* Integer `-1` if object of class `Integer` is lesser than method parameter.
* Integer `1` if object of class `Integer` is greater than method parameter.
* Integer `0` if object of class `Integer` is equal to method parameter.

**Example:**

```cpp
obj_0 = 123;
obj_1 = 0xff;
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

### Method `spec` [`to_string#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3095)

Convert object of class `Integer` to object of class `String`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
obj = 123;
("obj.to_string(): %s\n" % obj.to_string()).print();
```
```
obj.to_string(): 123
```

<a name="print#0" />

### Method `spec` [`print#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L3104)

Print string representation of object of class `Integer` to standard output.

**Return:**

* Object of class `Blank`.

**Example:**

```cpp
obj = 123;
obj.print();
"\n".print();
```
```
123
```
