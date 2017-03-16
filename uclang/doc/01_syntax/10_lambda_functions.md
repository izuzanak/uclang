
# Lambda functions

This document describes lambda functions in Uclang.

### Lambda function expression

Lambda functions are implemented as anonymous functions that has no access to
any other variables, than its own parameters. At runtime lambda functions are
represented by objects of class `Delegate`.

**Expression syntax:**

```
<expression> -> : ( <parameter_list> ) <command>
```

Where used symbols have following meaning:

* `<parameter_list>` - represents list of function parameters.
* `<command>` - represents one command, or block of commands enclosed in curly
  brackets `{` and `}`.

**Example:**

```cpp
lambda = :(a,b) return a + b;;
("lambda type: %s\n" % $(type lambda)).print();
("lambda.call([10,5]): %d\n" % lambda.call([10,5])).print();
```
```
lambda type: Delegate
lambda.call([10,5]): 15
```

### Single or multiple statement lambda functions

Body of lambda function can be expressed by single command or by block of
commands.

**Single command example:**

```cpp
result = Algo.reduce(0,new Range(1,10),:(a,b) return a + b;);
("result: %s\n" % $result).print();
```
```
result: 55
```

**Block of commands example:**

```cpp
Algo.reduce(0,new Range(1,10),:(a,b) {
  res = a + b;
  ("res: %d\n" % res).print();
  return res;
});
```
```
res: 1
res: 3
res: 6
res: 10
res: 15
res: 21
res: 28
res: 36
res: 45
res: 55
```

### Partial application of lambda function

As any other object of class `Delegate`, lambda function parameters can be
partially applied.

**Example:**

```cpp
lambda = :(a,b) return a + b;.papply([10]);

("result: %d\n" % lambda.call([5])).print();
("result: %f\n" % lambda.call([5.0])).print();
```
```
result: 15
result: 15.000000
```

### Lambda function returning lambda function

Example of lambda function returning lambda functions selected by index
parameter. Returned lambda functions are used in reduce algorithms.

**Example:**

```cpp
lambda = :(index) {
  return [
    :(a,b) return a + b;,
    :(a,b) return a - b;,
    :(a,b) return a * b;,
    :(a,b) return a / b;
  ][index];
};

("result: %d\n" % Algo.reduce(0,new Range(1,10),lambda.call([0]))).print();
("result: %d\n" % Algo.reduce(0,new Range(1,10),lambda.call([1]))).print();
("result: %d\n" % Algo.reduce(1,new Range(1,10),lambda.call([2]))).print();
("result: %d\n" % Algo.reduce(5000000,new Range(1,5),lambda.call([3]))).print();
```
```
result: 55
result: -55
result: 3628800
result: 41666
```

