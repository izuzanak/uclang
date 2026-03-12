# Class Sys

Class providing access to system specific parameters and functions.

-----

## Static constants

* Operating system related constants
  * `Sys.NAME` - Identification of operating system type.
  * `Sys.SEP` - Character used to separate pathname components.

* Random number generation related constants
  * `Sys.RAND_MAX` - Maximum value returned by method [`Sys.rand#0`](#rand%230).

-----

## Table of methods

* Methods

  * Method [`sleep#1`](#sleep%231)
  * Method [`srand#1`](#srand%231)
  * Method [`rand#0`](#rand%230)
  * Method [`getpid#0`](#getpid%230)
  * Method [`getuid#0`](#getuid%230)
  * Method [`getgid#0`](#getgid%230)
  * Method [`system#1`](#system%231)
  * Method [`exit#1`](#exit%231)
  * Method [`open#2`](#open%232)
  * Method [`popen#2`](#popen%232)
  * Method [`pipe#0`](#pipe%230)
  * Method [`mkdir#1`](#mkdir%231)
  * Method [`rmdir#1`](#rmdir%231)
  * Method [`chdir#1`](#chdir%231)
  * Method [`listdir#1`](#listdir%231)
  * Method [`mkfifo#1`](#mkfifo%231)
  * Method [`chmod#2`](#chmod%232)
  * Method [`remove#1`](#remove%231)
  * Method [`rename#2`](#rename%232)
  * Method [`link#2`](#link%232)
  * Method [`getcwd#0`](#getcwd%230)
  * Method [`setenv#2`](#setenv%232)
  * Method [`getenv#1`](#getenv%231)
  * Method [`is_file#1`](#is_file%231)
  * Method [`is_dir#1`](#is_dir%231)
  * Method [`size#1`](#size%231)
  * Method [`time#0`](#time%230)
  * Method [`to_string#0`](#to_string%230)
  * Method [`print#0`](#print%230)

-----

## Methods

<a name="sleep#1" />

### Method `static` [`sleep#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L954)

Suspends execution for the given number of milliseconds.

**Parameters:**

1. Type convertible to integer.

**Example:**

```cpp
("time: %d ms\n" % new Time().milli_sec()).print();
Sys.sleep(250);
("time: %d ms\n" % new Time().milli_sec()).print();
```
```
time: 1773320560734 ms
time: 1773320560985 ms
```

<a name="srand#1" />

### Method `static` [`srand#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L986)

Seeds the pseudo-random number generator.

**Parameters:**

1. Type convertible to integer.

**Example:**

```cpp
Sys.srand(12345);
("rand: %d\n" % Sys.rand()).print();
("rand: %d\n" % Sys.rand()).print();
```
```
rand: 383100999
rand: 858300821
```

<a name="rand#0" />

### Method `static` [`rand#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L1004)

Returns a pseudo-random integer in range from `0` to `Sys.RAND_MAX`.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
Sys.srand(12345);
("rand: %d\n" % Sys.rand()).print();
("rand: %d\n" % Sys.rand()).print();
("rand: %d\n" % Sys.rand()).print();
```
```
rand: 383100999
rand: 858300821
rand: 357768173
```

<a name="getpid#0" />

### Method `static` [`getpid#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L1012)

Returns process identifier of current process.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
("type: %s\n" % $(type Sys.getpid())).print();
```
```
type: Integer
```

<a name="getuid#0" />

### Method `static` [`getuid#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L1032)

Returns user identifier of current process.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
("type: %s\n" % $(type Sys.getuid())).print();
```
```
type: Integer
```

<a name="getgid#0" />

### Method `static` [`getgid#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L1050)

Returns group identifier of current process.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
("type: %s\n" % $(type Sys.getgid())).print();
```
```
type: Integer
```

<a name="system#1" />

### Method `static` [`system#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L1068)

Executes shell command described by string parameter.

**Parameters:**

1. Object of class `String` containing shell command to be executed.

**Return:**

* Object of class `Integer` representing command exit status.

**Example:**

```cpp
res = Sys.system("echo Hello from shell");
("exit status: %d\n" % res).print();
```
```
Hello from shell
exit status: 0
```

<a name="exit#1" />

### Method `static` [`exit#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L1086)

Terminates current process with given exit code.

**Parameters:**

1. Type convertible to integer representing exit code.

**Example:**

```cpp
("before exit\n").print();
// Sys.exit(0);
("this would not be reached\n").print();
```
```
before exit
this would not be reached
```

<a name="open#2" />

### Method `static` [`open#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L1104)

Opens file and returns object of class `File`.

**Parameters:**

1. Object of class `String` containing path to file.
2. Object of class `String` containing file open flags.

**Return:**

* Object of class `File`.

**Example:**

```cpp
new File("temporary","w").write_close("Hello world\n");
file = Sys.open("temporary","r");
file.read().print();
file.close();
Sys.remove("temporary");
```
```
Hello world
```

<a name="popen#2" />

### Method `static` [`popen#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L1114)

Opens process pipe and returns object of class `Pipe`.

**Parameters:**

1. Object of class `String` containing system command.
2. Object of class `String` containing pipe open flags.

**Return:**

* Object of class `Pipe`.

**Example:**

```cpp
pipe = Sys.popen("echo Hello from pipe","r");
pipe.read().print();
pipe.close();
```
```
Hello from pipe
```

<a name="pipe#0" />

### Method `static` [`pipe#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L1124)

Creates anonymous pipe and returns array of two objects of class `Pipe`. First
element is read end, second is write end.

**Return:**

* Object of class `Array` containing two objects of class `Pipe`.

**Example:**

```cpp
pipes = Sys.pipe();
pipes[1].write_close("Hello pipe\n");
pipes[0].read().print();
pipes[0].close();
```
```
Hello pipe
```

<a name="mkdir#1" />

### Method `static` [`mkdir#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L1191)

Creates directory in file system.

**Parameters:**

1. Object of class `String` containing path of directory to create.

**Example:**

```cpp
Sys.mkdir("test_dir");
("is_dir: %d\n" % Sys.is_dir("test_dir")).print();
Sys.rmdir("test_dir");
```
```
is_dir: 1
```

<a name="rmdir#1" />

### Method `static` [`rmdir#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L1227)

Removes empty directory from file system.

**Parameters:**

1. Object of class `String` containing path of directory to remove.

**Example:**

```cpp
Sys.mkdir("test_dir");
("is_dir: %d\n" % Sys.is_dir("test_dir")).print();
Sys.rmdir("test_dir");
("is_dir: %d\n" % Sys.is_dir("test_dir")).print();
```
```
is_dir: 1
is_dir: 0
```

<a name="chdir#1" />

### Method `static` [`chdir#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L1263)

Changes current working directory.

**Parameters:**

1. Object of class `String` containing path of target directory.

**Example:**

```cpp
cwd = Sys.getcwd();
Sys.mkdir("test_dir");
Sys.chdir("test_dir");
("cwd changed: %d\n" % (Sys.getcwd() != cwd)).print();
Sys.chdir(cwd);
Sys.rmdir("test_dir");
```
```
cwd changed: 1
```

<a name="listdir#1" />

### Method `static` [`listdir#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L1299)

Returns list of entries in directory.

**Parameters:**

1. Object of class `String` containing path to directory.

**Return:**

* Object of class `Array` containing objects of class `String`.

**Example:**

```cpp
Sys.mkdir("test_dir");
new File("test_dir/a.txt","w").write_close("a");
new File("test_dir/b.txt","w").write_close("b");
entries = Sys.listdir("test_dir");
("entries: %s\n" % $entries).print();
Sys.remove("test_dir/a.txt");
Sys.remove("test_dir/b.txt");
Sys.rmdir("test_dir");
```
```
entries: [a.txt,b.txt]
```

<a name="mkfifo#1" />

### Method `static` [`mkfifo#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L1403)

Creates named pipe (FIFO) in file system.

**Parameters:**

1. Object of class `String` containing path of named pipe to create.

**Example:**

```cpp
Sys.mkfifo("test_fifo");
("is_file: %d\n" % Sys.is_file("test_fifo")).print();
Sys.remove("test_fifo");
```
```
is_file: 1
```

<a name="chmod#2" />

### Method `static` [`chmod#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L1438)

Changes file permissions.

**Parameters:**

1. Object of class `String` containing file path.
2. Type convertible to integer representing permission mode.

**Example:**

```cpp
new File("temporary","w").write_close("data");
Sys.chmod("temporary",0644);
("done\n").print();
Sys.remove("temporary");
```
```
done
```

<a name="remove#1" />

### Method `static` [`remove#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L1474)

Deletes file or directory from file system.

**Parameters:**

1. Object of class `String`.

**Example:**

```cpp
new File("temporary","w").write_close("Hello world\n");
("Sys.is_file(): %d\n" % Sys.is_file("temporary")).print();
Sys.remove("temporary");
("Sys.is_file(): %d\n" % Sys.is_file("temporary")).print();
```
```
Sys.is_file(): 1
Sys.is_file(): 0
```

<a name="rename#2" />

### Method `static` [`rename#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L1510)

Renames file or directory.

**Parameters:**

1. Object of class `String` containing source path.
2. Object of class `String` containing target path.

**Example:**

```cpp
new File("temporary","w").write_close("data");
Sys.rename("temporary","temporary_new");
("old exists: %d\n" % Sys.is_file("temporary")).print();
("new exists: %d\n" % Sys.is_file("temporary_new")).print();
Sys.remove("temporary_new");
```
```
old exists: 0
new exists: 1
```

<a name="link#2" />

### Method `static` [`link#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L1559)

Creates hard link to file.

**Parameters:**

1. Object of class `String` containing path to existing file.
2. Object of class `String` containing path for new link.

**Example:**

```cpp
new File("temporary","w").write_close("data");
Sys.link("temporary","temporary_link");
("link exists: %d\n" % Sys.is_file("temporary_link")).print();
Sys.remove("temporary_link");
Sys.remove("temporary");
```
```
link exists: 1
```

<a name="getcwd#0" />

### Method `static` [`getcwd#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L1606)

Returns current working directory path.

**Return:**

* Object of class `String`.

**Example:**

```cpp
("type: %s\n" % $(type Sys.getcwd())).print();
```
```
type: String
```

<a name="setenv#2" />

### Method `static` [`setenv#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L1639)

Sets environment variable.

**Parameters:**

1. Object of class `String` containing variable name.
2. Object of class `String` containing variable value.

**Example:**

```cpp
Sys.setenv("TEST_VAR","hello");
("TEST_VAR: %s\n" % Sys.getenv("TEST_VAR")).print();
```
```
TEST_VAR: hello
```

<a name="getenv#1" />

### Method `static` [`getenv#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L1681)

Returns value of environment variable.

**Parameters:**

1. Object of class `String` containing variable name.

**Return:**

* Object of class `String`.

**Example:**

```cpp
Sys.setenv("TEST_VAR","hello");
("TEST_VAR: %s\n" % Sys.getenv("TEST_VAR")).print();
```
```
TEST_VAR: hello
```

<a name="is_file#1" />

### Method `static` [`is_file#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L1721)

Tests whether given path refers to a regular file.

**Parameters:**

1. Object of class `String` containing file path.

**Return:**

* Object of class `Integer`, value `1` if path is a regular file, `0` otherwise.

**Example:**

```cpp
new File("temporary","w").write_close("data");
("is_file: %d\n" % Sys.is_file("temporary")).print();
("is_file: %d\n" % Sys.is_file("nonexistent")).print();
Sys.remove("temporary");
```
```
is_file: 1
is_file: 0
```

<a name="is_dir#1" />

### Method `static` [`is_dir#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L1753)

Tests whether given path refers to a directory.

**Parameters:**

1. Object of class `String` containing directory path.

**Return:**

* Object of class `Integer`, value `1` if path is a directory, `0` otherwise.

**Example:**

```cpp
Sys.mkdir("test_dir");
("is_dir: %d\n" % Sys.is_dir("test_dir")).print();
("is_dir: %d\n" % Sys.is_dir("nonexistent")).print();
Sys.rmdir("test_dir");
```
```
is_dir: 1
is_dir: 0
```

<a name="size#1" />

### Method `static` [`size#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L1785)

Returns size of file in bytes.

**Parameters:**

1. Object of class `String` containing file path.

**Return:**

* Object of class `Integer` representing file size in bytes.

**Example:**

```cpp
new File("temporary","w").write_close("Hello world\n");
("size: %d\n" % Sys.size("temporary")).print();
Sys.remove("temporary");
```
```
size: 12
```

<a name="time#0" />

### Method `static` [`time#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L1835)

Returns current Unix time in seconds.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
("type: %s\n" % $(type Sys.time())).print();
```
```
type: Integer
```

<a name="to_string#0" />

### Method `spec` `static` [`to_string#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L1868)

Convert object of class `Sys` to object of class `String`.
This method returns name of class `Sys`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
("Sys.to_string(): %s\n" % Sys.to_string()).print();
```
```
Sys.to_string(): Sys
```

<a name="print#0" />

### Method `spec` `static` [`print#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L1877)

Print string representation of object of class `Sys` to standard output.
This method prints name of class `Sys`.

**Return:**

* Object of class `Sys`.

**Example:**

```cpp
Sys.print();
"\n".print();
```
```
Sys
```
