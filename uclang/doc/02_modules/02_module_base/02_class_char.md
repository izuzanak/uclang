# Class Char

Class describing single byte characters.

-----

## Table of methods

* Constructors

  * Constructor [`Char#0`](#Char%230)
  * Constructor [`Char#1`](#Char%231)

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

<a name="Char#0" />

### Constructor [`Char#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1818)

Creates default object of class `Char`.

**Example:**

```cpp
obj = new Char();
("obj: %d\n" % new Integer(obj)).print();
```
```
obj: 0
```

<a name="Char#1" />

### Constructor [`Char#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1823)

Creates object of class `Char` from method parameter.

**Parameters:**

1. Object of class `Char` or `Integer`.

**Example:**

```cpp
("obj: %c\n" % new Char('e')).print();
("obj: %c\n" % new Char(0x041)).print();
```
```
obj: e
obj: A
```

-----

## Operators

<a name="operator_binary_equal#1" />

### Operator [`operator_binary_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1064)

Assignment operator `=`. Object of class `Char` is replaced by method parameter.

**Parameters:**

1. Any type.

**Return:**

* Method parameter.

**Example:**

```cpp
obj = 'e';
("obj: %s\n" % obj.to_string()).print();
obj = "New value";
("obj: %s\n" % obj.to_string()).print();
```
```
obj: e
obj: New value
```

<a name="operator_binary_plus_equal#1" />

### Operator [`operator_binary_plus_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1390)

Add and assign operator `+=`. Operator adds value of method parameter to value of object of class `Char`.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Value of object.

**Example:**

```cpp
obj = '\x45';
("obj: %d\n" % new Integer(obj)).print();
obj += 'e';
("obj: %d\n" % new Integer(obj)).print();
obj += 123;
("obj: %d\n" % new Integer(obj)).print();
obj += 12.234;
("obj: %d\n" % new Integer(obj)).print();
```
```
obj: 69
obj: -86
obj: 37
obj: 49
```

<a name="operator_binary_minus_equal#1" />

### Operator [`operator_binary_minus_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1397)

Subtract and assign operator `-=`. Operator subtracts value of method parameter from value of object of class `Char`.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Value of object.

**Example:**

```cpp
obj = '\x45';
("obj: %d\n" % new Integer(obj)).print();
obj -= 'e';
("obj: %d\n" % new Integer(obj)).print();
obj -= 123;
("obj: %d\n" % new Integer(obj)).print();
obj -= 12.234;
("obj: %d\n" % new Integer(obj)).print();
```
```
obj: 69
obj: -32
obj: 101
obj: 88
```

<a name="operator_binary_asterisk_equal#1" />

### Operator [`operator_binary_asterisk_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1404)

Multiply and assign operator `*=`. Operator multiplies value of object of class `Char` by value of method parameter.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Value of object.

**Example:**

```cpp
obj = '\x45';
("obj: %d\n" % new Integer(obj)).print();
obj *= 'e';
("obj: %d\n" % new Integer(obj)).print();
obj *= 123;
("obj: %d\n" % new Integer(obj)).print();
obj *= 12.234;
("obj: %d\n" % new Integer(obj)).print();
```
```
obj: 69
obj: 57
obj: 99
obj: -69
```

<a name="operator_binary_slash_equal#1" />

### Operator [`operator_binary_slash_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1411)

Divide and assign operator `/=`. Operator divides value of object of class `Char` by value of method parameter.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Value of object.

**Example:**

```cpp
obj = '\x7f';
obj /= 'e';
("obj: %d\n" % new Integer(obj)).print();
obj = '\x7f';
obj /= 123;
("obj: %d\n" % new Integer(obj)).print();
obj = '\x7f';
obj /= 12.234;
("obj: %d\n" % new Integer(obj)).print();
```
```
obj: 1
obj: 1
obj: 10
```

<a name="operator_binary_percent_equal#1" />

### Operator [`operator_binary_percent_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1479)

Modulus and assign operator `%=`. Operator computes modulus of value of object of class `Char` divided by value of method parameter.

**Parameters:**

1. Object of class `Char` or `Integer`.

**Return:**

* Value of object.

**Example:**

```cpp
obj = '\x45';
obj %= 'e';
("obj: %d\n" % new Integer(obj)).print();
obj = '\x45';
obj %= 123;
("obj: %d\n" % new Integer(obj)).print();
```
```
obj: 69
obj: 69
```

<a name="operator_binary_double_ls_br_equal#1" />

### Operator [`operator_binary_double_ls_br_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1486)

Left shift and assign operator `<<=`. Value of object of class `Char` is shifted to left by count of bits given by method parameter.

**Parameters:**

1. Object of class `Char` or `Integer`.

**Return:**

* Value of object.

**Example:**

```cpp
obj = '\x45';
("obj: %d\n" % new Integer(obj)).print();
obj <<= '\x02';
("obj: %d\n" % new Integer(obj)).print();
obj <<= 2;
("obj: %d\n" % new Integer(obj)).print();
```
```
obj: 69
obj: 20
obj: 80
```

<a name="operator_binary_double_rs_br_equal#1" />

### Operator [`operator_binary_double_rs_br_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1493)

Right shift and assign operator `>>=`. Value of object of class `Char` is shifted to right by count of bits given by method parameter.

**Parameters:**

1. Object of class `Char` or `Integer`.

**Return:**

* Value of object.

**Example:**

```cpp
obj = '\x45';
("obj: %d\n" % new Integer(obj)).print();
obj >>= '\x02';
("obj: %d\n" % new Integer(obj)).print();
obj >>= 2;
("obj: %d\n" % new Integer(obj)).print();
```
```
obj: 69
obj: 17
obj: 4
```

<a name="operator_binary_ampersand_equal#1" />

### Operator [`operator_binary_ampersand_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1500)

Bitwise AND and assign operator `&=`. Value of
object of class `Char` is modified according to value given by
method parameter. Bit in result value is set, if it exists in
object of class `Char` and method parameter.

**Parameters:**

1. Object of class `Char` or `Integer`.

**Return:**

* Value of object.

**Example:**

```cpp
obj = '\x45';
obj &= 'e';
("obj: %d\n" % new Integer(obj)).print();
obj = '\x45';
obj &= 123;
("obj: %d\n" % new Integer(obj)).print();
```
```
obj: 69
obj: 65
```

<a name="operator_binary_pipe_equal#1" />

### Operator [`operator_binary_pipe_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1507)

Bitwise OR and assign operator `|=`. Value of
object of class `Char` is modified according to value given by
method parameter. Bit in result value is set, if it exists in
object of class `Char` or in method parameter.

**Parameters:**

1. Object of class `Char` or `Integer`.

**Return:**

* Value of object.

**Example:**

```cpp
obj = '\x45';
obj |= 'e';
("obj: %d\n" % new Integer(obj)).print();
obj = '\x45';
obj |= 123;
("obj: %d\n" % new Integer(obj)).print();
```
```
obj: 101
obj: 127
```

<a name="operator_binary_circumflex_equal#1" />

### Operator [`operator_binary_circumflex_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1514)

Bitwise XOR and assign operator `^=`. Value of
object of class `Char` is modified according to value given by
method parameter. Bit in result value is set, if it exists in
object of class `Char` or in method parameter, but not both.

**Parameters:**

1. Object of class `Char` or `Integer`.

**Return:**

* Value of object.

**Example:**

```cpp
obj = '\x45';
obj ^= 'e';
("obj: %d\n" % new Integer(obj)).print();
obj = '\x45';
obj ^= 123;
("obj: %d\n" % new Integer(obj)).print();
```
```
obj: 32
obj: 62
```

<a name="operator_binary_double_ampersand#1" />

### Operator [`operator_binary_double_ampersand#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1521)

Logical AND operator `&&`.  If object of class
`Char` is non-zero and value of method parameter is also non-zero
condition becomes true.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Integer `1` if both operands are non-zero.
* Integer `0` if either of operands is zero.

**Example:**

```cpp
obj_0 = '\x0';
("obj_0 && 0: %d\n" % (obj_0 && 0)).print();
("obj_0 && 1: %d\n" % (obj_0 && 1)).print();
obj_1 = 'e';
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

### Operator [`operator_binary_double_pipe#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1528)

Logical OR operator `||`.  If object of class
`Char` is non-zero or value of method parameter is non-zero
condition becomes true.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Integer `1` if either of operands is non-zero.
* Integer `0` if both operands are zero.

**Example:**

```cpp
obj_0 = '\x0';
("obj_0 || 0: %d\n" % (obj_0 || 0)).print();
("obj_0 || 1: %d\n" % (obj_0 || 1)).print();
obj_1 = 'e';
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

### Operator [`operator_binary_ampersand#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1535)

Bitwise AND operator `&`. Bit in result value is set, if it exists in object of class `Char` and in method parameter.

**Parameters:**

1. Object of class `Char` or `Integer`.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
obj = '\x45';
("obj & 'e': %d\n" % (obj & 'e')).print();
("obj & 123: %d\n" % (obj & 123)).print();
```
```
obj & 'e': 69
obj & 123: 65
```

<a name="operator_binary_pipe#1" />

### Operator [`operator_binary_pipe#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1542)

Bitwise OR operator `|`. Bit in result value is set, if it exists in object of class `Char` or in method parameter.

**Parameters:**

1. Object of class `Char` or `Integer`.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
obj = '\x45';
("obj | 'e': %d\n" % (obj | 'e')).print();
("obj | 123: %d\n" % (obj | 123)).print();
```
```
obj | 'e': 101
obj | 123: 127
```

<a name="operator_binary_circumflex#1" />

### Operator [`operator_binary_circumflex#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1549)

Bitwise XOR operator `^`. Bit in result value is set, if it exists in object of class `Char` or in method parameter, but not both.

**Parameters:**

1. Object of class `Char` or `Integer`.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
obj = '\x45';
("obj ^ 'e': %d\n" % (obj ^ 'e')).print();
("obj ^ 123: %d\n" % (obj ^ 123)).print();
```
```
obj ^ 'e': 32
obj ^ 123: 62
```

<a name="operator_binary_double_equal#1" />

### Operator [`operator_binary_double_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1556)

Comparison operator `==`. Compares object of class `Char` with method parameter and return `1` if objects has same value or `0` otherwise.

**Parameters:**

1. Any type.

**Return:**

* Object of class `Integer`.
  * `0` - method parameter has different value than object.
  * `1` - method parameter has same value as object.

**Example:**

```cpp
obj_0 = 'e';
obj_1 = '\x46';
obj_2 = obj_0;
("obj_0 == obj_1: %d\n" % (obj_0 == obj_1)).print();
("obj_0 == obj_2: %d\n" % (obj_0 == obj_2)).print();
```
```
obj_0 == obj_1: 0
obj_0 == obj_2: 1
```

<a name="operator_binary_exclamation_equal#1" />

### Operator [`operator_binary_exclamation_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1571)

Comparison operator `!=`. Compares object of class `Char` with method parameter and return `0` if objects has same value or `1` otherwise.

**Parameters:**

1. Any type.

**Return:**

* Object of class `Integer`.
  * `0` - method parameter has same value as object.
  * `1` - method parameter has different value than object.

**Example:**

```cpp
obj_0 = 'e';
obj_1 = '\x46';
obj_2 = obj_0;
("obj_0 != obj_1: %d\n" % (obj_0 != obj_1)).print();
("obj_0 != obj_2: %d\n" % (obj_0 != obj_2)).print();
```
```
obj_0 != obj_1: 1
obj_0 != obj_2: 0
```

<a name="operator_binary_rs_br#1" />

### Operator [`operator_binary_rs_br#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1587)

Greater test operator `>`. Test if value of object of class `Char` is greater than value of method parameter.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Object of class `Integer`.
  * `1` - value of object of class `Char` is greater than value of method parameter.
  * `0` - value of object of class `Char` is less or equal than value of method parameter.

**Example:**

```cpp
obj = '\x45';
("obj: %s\n" % obj.to_string()).print();
("obj > 'e': %d\n" % (obj > 'e')).print();
("obj > 123: %d\n" % (obj > 123)).print();
("obj > 12.234: %d\n" % (obj > 12.234)).print();
```
```
obj: E
obj > 'e': 0
obj > 123: 0
obj > 12.234: 1
```

<a name="operator_binary_ls_br#1" />

### Operator [`operator_binary_ls_br#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1594)

Lesser test operator `<`. Test if value of object of class `Char` is lesser than value of method parameter.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Object of class `Integer`.
  * `1` - value of object of class `Char` is less than value of method parameter.
  * `0` - value of object of class `Char` is greater or equal than value of method parameter.

**Example:**

```cpp
obj = '\x45';
("obj: %s\n" % obj.to_string()).print();
("obj < 'e': %d\n" % (obj < 'e')).print();
("obj < 123: %d\n" % (obj < 123)).print();
("obj < 12.234: %d\n" % (obj < 12.234)).print();
```
```
obj: E
obj < 'e': 1
obj < 123: 1
obj < 12.234: 0
```

<a name="operator_binary_rs_br_equal#1" />

### Operator [`operator_binary_rs_br_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1601)

Greater or equal test operator `>=`. Test if value of object of class `Char` is greater or equal than value of method parameter.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Object of class `Integer`.
  * `1` - value of object of class `Char` is greater or equal than value of method parameter.
  * `0` - value of object of class `Char` is less than value of method parameter.

**Example:**

```cpp
obj = '\x45';
("obj: %s\n" % obj.to_string()).print();
("obj >= 'e': %d\n" % (obj >= 'e')).print();
("obj >= 123: %d\n" % (obj >= 123)).print();
("obj >= 12.234: %d\n" % (obj >= 12.234)).print();
```
```
obj: E
obj >= 'e': 0
obj >= 123: 0
obj >= 12.234: 1
```

<a name="operator_binary_ls_br_equal#1" />

### Operator [`operator_binary_ls_br_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1608)

Lesser or equal test operator `<=`. Test if value of object of class `Char` is lesser or equal than value of method parameter.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Object of class `Integer`.
  * `1` - value of object of class `Char` is less or equal than value of method parameter.
  * `0` - value of object of class `Char` is greater than value of method parameter.

**Example:**

```cpp
obj = '\x45';
("obj: %s\n" % obj.to_string()).print();
("obj <= 'e': %d\n" % (obj <= 'e')).print();
("obj <= 123: %d\n" % (obj <= 123)).print();
("obj <= 12.234: %d\n" % (obj <= 12.234)).print();
```
```
obj: E
obj <= 'e': 1
obj <= 123: 1
obj <= 12.234: 0
```

<a name="operator_binary_double_rs_br#1" />

### Operator [`operator_binary_double_rs_br#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1615)

Right shift operator `>>`. Value of object of class `Char` is shifted to right by count of bits given by method parameter.

**Parameters:**

1. Object of class `Char` or `Integer`.

**Return:**

* Object of class `Char`.

**Example:**

```cpp
obj = '\x45';
("obj: %d\n" % new Integer(obj)).print();
res = obj >> '\x02';
("res: %d\n" % new Integer(res)).print();
res = obj >> 2;
("res: %d\n" % new Integer(res)).print();
```
```
obj: 69
res: 17
res: 17
```

<a name="operator_binary_double_ls_br#1" />

### Operator [`operator_binary_double_ls_br#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1622)

Left shift operator `<<`. Value of object of class `Char` is shifted to left by count of bits given by method parameter.

**Parameters:**

1. Object of class `Char` or `Integer`.

**Return:**

* Object of class `Char`.

**Example:**

```cpp
obj = '\x45';
("obj: %d\n" % new Integer(obj)).print();
res = obj << '\x02';
("res: %d\n" % new Integer(res)).print();
res = obj << 2;
("res: %d\n" % new Integer(res)).print();
```
```
obj: 69
res: 276
res: 276
```

<a name="operator_binary_plus#1" />

### Operator [`operator_binary_plus#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1629)

Add operator `+`. Operator adds value of method parameter to value of object of class `Char`.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Object of class `Char`, `Integer` or `Float`.

**Example:**

```cpp
obj = '\x45';
("obj: %d\n" % new Integer(obj)).print();
res = obj + 'e';
("res: %d\n" % new Integer(res)).print();
res = obj + 123;
("res: %s\n" % res.to_string()).print();
res = obj + 12.234;
("res: %s\n" % res.to_string()).print();
```
```
obj: 69
res: -86
res: 192
res: 81.234000
```

<a name="operator_binary_minus#1" />

### Operator [`operator_binary_minus#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1636)

Subtract operator `-`. Operator subtracts value of method parameter from value of object of class `Char`.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Object of class `Char`, `Integer` or `Float`.

**Example:**

```cpp
obj = '\x45';
("obj: %d\n" % new Integer(obj)).print();
res = obj - 'e';
("res: %d\n" % new Integer(res)).print();
res = obj - 123;
("res: %s\n" % res.to_string()).print();
res = obj - 12.234;
("res: %s\n" % res.to_string()).print();
```
```
obj: 69
res: -32
res: -54
res: 56.766000
```

<a name="operator_binary_asterisk#1" />

### Operator [`operator_binary_asterisk#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1643)

Multiply operator `*`. It multiplies value of object of class `Char` by value of method parameter.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Object of class `Char`, `Integer` or `Float`.

**Example:**

```cpp
obj = '\x02';
("obj: %d\n" % new Integer(obj)).print();
res = obj * 'e';
("res: %d\n" % new Integer(res)).print();
res = obj * 123;
("res: %s\n" % res.to_string()).print();
res = obj * 12.234;
("res: %s\n" % res.to_string()).print();
```
```
obj: 2
res: -54
res: 246
res: 24.468000
```

<a name="operator_binary_slash#1" />

### Operator [`operator_binary_slash#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1650)

Divide operator `/`. Operator divides value of object of class `Char` by value of method parameter.

**Parameters:**

1. Object of class `Char`, `Integer` or `Float`.

**Return:**

* Object of class `Char`, `Integer` or `Float`.

**Example:**

```cpp
obj = '\x45';
("obj: %d\n" % new Integer(obj)).print();
res = obj / '\x02';
("res: %d\n" % new Integer(res)).print();
res = obj / 2;
("res: %s\n" % res.to_string()).print();
res = obj / 2.532;
("res: %s\n" % res.to_string()).print();
```
```
obj: 69
res: 34
res: 34
res: 27.251185
```

<a name="operator_binary_percent#1" />

### Operator [`operator_binary_percent#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1722)

Modulus operator `%`. Operator computes modulus of value of object of class `Char` divided by value of method parameter.

**Parameters:**

1. Object of class `Char` or `Integer`.

**Return:**

* Object of class `Char` or `Integer`.

**Example:**

```cpp
obj = '\x45';
("obj: %d\n" % new Integer(obj)).print();
res = obj % 'e';
("res: %d\n" % new Integer(res)).print();
res = obj % 123;
("res: %s\n" % res.to_string()).print();
```
```
obj: 69
res: 69
res: 69
```

<a name="operator_unary_post_double_plus#0" />

### Operator [`operator_unary_post_double_plus#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1757)

Post increment operator `++`. Increase value of object of class `Char` by one.

**Return:**

* Value of object before incrementation.

**Example:**

```cpp
obj = 'e';
("obj: %s\n" % obj.to_string()).print();
("obj++: %s\n" % (obj++).to_string()).print();
("obj: %s\n" % obj.to_string()).print();
```
```
obj: e
obj++: e
obj: f
```

<a name="operator_unary_post_double_minus#0" />

### Operator [`operator_unary_post_double_minus#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1764)

Post decrement operator `--`. Decrease value of object of class `Char` by one.

**Return:**

* Value of object before decrementation.

**Example:**

```cpp
obj = 'e';
("obj: %s\n" % obj.to_string()).print();
("obj--: %s\n" % (obj--).to_string()).print();
("obj: %s\n" % obj.to_string()).print();
```
```
obj: e
obj--: e
obj: d
```

<a name="operator_unary_pre_double_plus#0" />

### Operator [`operator_unary_pre_double_plus#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1771)

Pre increment operator `++`. Increase value of object of class `Char` by one.

**Return:**

* Value of object.

**Example:**

```cpp
obj = 'e';
("obj: %s\n" % obj.to_string()).print();
("++obj: %s\n" % (++obj).to_string()).print();
("obj: %s\n" % obj.to_string()).print();
```
```
obj: e
++obj: f
obj: f
```

<a name="operator_unary_pre_double_minus#0" />

### Operator [`operator_unary_pre_double_minus#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1778)

Pre decrement operator `--`. Decrease value of object of class `Char` by one.

**Return:**

* Value of object.

**Example:**

```cpp
obj = 'e';
("obj: %s\n" % obj.to_string()).print();
("--obj: %s\n" % (--obj).to_string()).print();
("obj: %s\n" % obj.to_string()).print();
```
```
obj: e
--obj: d
obj: d
```

<a name="operator_unary_pre_plus#0" />

### Operator [`operator_unary_pre_plus#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1785)

Unary operator `+`. Return value of object of class `Char`.

**Return:**

* Object of class `Char`.

**Example:**

```cpp
obj = 'e';
("obj: %d\n" % new Integer(obj)).print();
obj = +obj;
("obj: %d\n" % new Integer(obj)).print();
```
```
obj: 101
obj: 101
```

<a name="operator_unary_pre_minus#0" />

### Operator [`operator_unary_pre_minus#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1792)

Unary negative operator `-`. Return negative value of object of class `Char`.

**Return:**

* Object of class `Char`.

**Example:**

```cpp
obj = 'e';
("obj: %d\n" % new Integer(obj)).print();
obj = -obj;
("obj: %d\n" % new Integer(obj)).print();
```
```
obj: 101
obj: -101
```

<a name="operator_unary_pre_exclamation#0" />

### Operator [`operator_unary_pre_exclamation#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1799)

Logical NOT operator `!`. Reverse logical state of value of object of class `Char`.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
obj = 'e';
("obj: %d\n" % new Integer(obj)).print();
obj = !obj;
("obj: %d\n" % new Integer(obj)).print();
```
```
obj: 101
obj: 0
```

<a name="operator_unary_pre_tilde#0" />

### Operator [`operator_unary_pre_tilde#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1811)

Bitwise complement operator `~`. Return binary complement of value of object of class `Char`.

**Return:**

* Object of class `Char`.

**Example:**

```cpp
obj = 'e';
("obj: %d\n" % new Integer(obj)).print();
obj = ~obj;
("obj: %d\n" % new Integer(obj)).print();
```
```
obj: 101
obj: -102
```

-----

## Methods

<a name="compare#1" />

### Method `spec` [`compare#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1850)

Compare object of class `Char` with method parameter.

**Parameters:**

1. Any type.

**Return:**

* Integer `-1` if object of class `Char` is lesser than method parameter.
* Integer `1` if object of class `Char` is greater than method parameter.
* Integer `0` if object of class `Char` is equal to method parameter.

**Example:**

```cpp
obj_0 = 'e';
obj_1 = '\x46';
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

### Method `spec` [`to_string#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1875)

Convert object of class `Char` to object of class `String`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
obj = 'e';
("obj.to_string(): %s\n" % obj.to_string()).print();
```
```
obj.to_string(): e
```

<a name="print#0" />

### Method `spec` [`print#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/base_uclm/source_files/base_module.cc#L1885)

Print string representation of object of class `Char` to standard output.

**Return:**

* Object of class `Blank`.

**Example:**

```cpp
obj = 'e';
obj.print();
"\n".print();
```
```
e
```
