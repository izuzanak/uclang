# uclang - programming language

![CI](https://github.com/izuzanak/uclang/workflows/CI/badge.svg)

Interpreted, dynamically typed, object-oriented programming language.

## Language features

* Language syntax is derived from C/C++ programming languages.
  * Some syntax is derived from Java programming language.
* Strong object oriented approach.
  * Everything is an object.
  * No global functions at all.
  * Almost all actions are performed by execution of methods.
* Support for inheritance.
* Support for exceptions.
* Support for native threads, no GIL (Global Interpreter Lock).
* Module system designed for straightforward creation of binary modules in C/C++.
  * A language built in data types are implemented as binary module.
* Lightweight interpreter, deployable on embedded devices.

## Documentation

Documentation of uclang components is located in
[`uclang/doc`](https://github.com/izuzanak/uclang/tree/master/uclang/doc).
Short introduction to language syntax and features can be found in
[`uclang/doc/intro.md`](https://github.com/izuzanak/uclang/blob/master/uclang/doc/intro.md).

## Language modules

A set of 114 modules was created in order to use uclang in production.
Implementation of these modules is located in
[`uclang/mods`](https://github.com/izuzanak/uclang/tree/master/uclang/mods).

* **Core**: base, sys, lang, containers, algorithms, math, regex, pcre, utf8proc, pack, parser, docu
* **Data Formats**: json, xml, protobuf, xlsxwriter
* **Databases**: sqlite, psql, ddb
* **Networking**: http, websocket, curl, ftp, ssh2, tcp, mqtt, nanomsg, snmp, avahi, dlms
* **Cryptography**: crypto, cipher, gcrypt, openssl, nacl, checksum, xxhash
* **Compression**: zlib, zip, snappy, isal
* **Graphics/UI**: gl, glew, glut, ftgl, gtk, image, vg, shivavg, amanithvg, imxegl, opencv, freetype2, gif, qrencode, quirc, shape
* **Audio/Video**: av, ao, mpg, portaudio, gstreamer, vlc, va
* **Language Interop**: python, v8, lua, mono, perl, ruby, prolog, rust, emscripten
* **System/OS**: inotify, linux, signal, epoll, fuse, btrfsutil, pam, uv, serial, pigpio, readline, curses, android, node
* **Math/Science**: gmp, gsl, fftw, fann, graph, ga, lightning, jit, llvm, cl
* **Utilities**: time, tzone, iconv, locale, logger, channel, binbits, raw, validator, counter, latlon, ledmat, datrie, intelhex, comelm, fgettools, uctrdpmsh

## Examples

### Native multithreading

Mark a method `parallel` and it runs in a new thread — no GIL, true parallelism:

```cpp
class Main
{
  static public parallel do_work(count)
  {
    result = 0;
    idx = 0;
    while (idx < count) { result += idx++; }
    return result;
  }

  static public main(argv)
  {
    threads = [];
    idx = 0;
    while (idx++ < 4)
    {
      threads.push(do_work(1000));
    }

    for (thread <- threads)
    {
      ("result: %d\n" % thread.join()).print();
    }
  }
}
```

### Lambdas and functional programming

First-class lambdas with map, filter, reduce and partial application:

```cpp
import containers;
import algorithms;

class Main
{
  static public main(argv)
  {
    // Lambda as first-class object
    add = :(a,b) return a + b;;
    ("3 + 4 = %d\n" % add.call([3,4])).print();

    // Functional: map, filter, reduce
    squares = Algo.map(new Range(1,5), :(x) return x * x;);
    ("squares: %s\n" % $squares).print();

    evens = Algo.filter(new Range(1,10), :(x) return (x % 2) == 0;);
    ("evens: %s\n" % $evens).print();

    sum = Algo.reduce(0, new Range(1,10), :(a,b) return a + b;);
    ("sum(1..10): %d\n" % sum).print();

    // Partial application
    add10 = :(a,b) return a + b;.papply([10]);
    ("add10(5): %d\n" % add10.call([5])).print();
  }
}
```

### Inheritance with abstract and final methods

```cpp
abstract class Shape
{
  abstract public area();
  final public describe()
  {
    return "Shape(area=%s)" % $this.area();
  }
}

class Circle extends Shape
{
  radius;
  public Circle(r) { radius = r; }
  public area() { return 3.14159 * radius * radius; }
  public to_string() { return "Circle(r=%s)" % $radius; }
}

class Rect extends Shape
{
  w; h;
  public Rect(a_w,a_h) { w = a_w; h = a_h; }
  public area() { return w * h; }
  public to_string() { return "Rect(%sx%s)" % [$w,$h]; }
}

class Main
{
  static public main(argv)
  {
    shapes = [new Circle(5), new Rect(4,6), new Circle(1)];
    for (s <- shapes)
    {
      ("%s -> %s\n" % [$s, s.describe()]).print();
    }
  }
}
```

More examples are introduced in
[`uclang/doc/intro.md`](https://github.com/izuzanak/uclang/blob/master/uclang/doc/intro.md).
Syntax examples covering hello world through special methods can be found in
[`uclang/examples/01_syntax`](https://github.com/izuzanak/uclang/tree/master/uclang/examples/01_syntax).

## Building interpreter

Prerequisites: CMake >= 3.0.2, GCC, and the container generator
[`cont`](https://github.com/izuzanak/cont).

### Linux compilation

Enter build directory [`build`](https://github.com/izuzanak/uclang/tree/master/build).
```
cd build
```

Process cmake source.
```sh
cmake -DCMAKE_BUILD_TYPE="Release" ..
```

Build uclang.
```sh
make -j$(nproc)
```

Optionally install to system.
```sh
sudo make install
```

### Running scripts

After building, scripts can be run from the build directory:

```sh
cd build
export LD_LIBRARY_PATH=$(pwd)
./uclang scripts/hello.ucl
```

After installation:

```sh
uclang script.ucl [args...]
```

## License

This project is licensed under the GNU General Public License v2 - see the
[LICENSE](https://github.com/izuzanak/uclang/blob/master/LICENSE) file for details.
