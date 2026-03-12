# Class Signal

Class providing access to Unix signal handling.

-----

## Static constants

* Common signal constants
  * `Signal.SIGINT` - Interrupt from keyboard.
  * `Signal.SIGTERM` - Termination signal.

* Unix signal constants
  * `Signal.SIGHUP` - Hangup detected on controlling terminal.
  * `Signal.SIGQUIT` - Quit from keyboard.
  * `Signal.SIGILL` - Illegal instruction.
  * `Signal.SIGTRAP` - Trace/breakpoint trap.
  * `Signal.SIGABRT` - Abort signal.
  * `Signal.SIGIOT` - IOT trap.
  * `Signal.SIGBUS` - Bus error.
  * `Signal.SIGFPE` - Floating point exception.
  * `Signal.SIGKILL` - Kill signal.
  * `Signal.SIGUSR1` - User-defined signal 1.
  * `Signal.SIGSEGV` - Segmentation violation.
  * `Signal.SIGUSR2` - User-defined signal 2.
  * `Signal.SIGPIPE` - Broken pipe.
  * `Signal.SIGALRM` - Timer signal from alarm.
  * `Signal.SIGSTKFLT` - Stack fault on coprocessor.
  * `Signal.SIGCHLD` - Child stopped or terminated.
  * `Signal.SIGCONT` - Continue if stopped.
  * `Signal.SIGSTOP` - Stop process.
  * `Signal.SIGTSTP` - Stop typed at terminal.
  * `Signal.SIGTTIN` - Terminal input for background process.
  * `Signal.SIGTTOU` - Terminal output for background process.
  * `Signal.SIGURG` - Urgent condition on socket.
  * `Signal.SIGXCPU` - CPU time limit exceeded.
  * `Signal.SIGXFSZ` - File size limit exceeded.
  * `Signal.SIGVTALRM` - Virtual alarm clock.
  * `Signal.SIGPROF` - Profiling timer expired.
  * `Signal.SIGWINCH` - Window resize signal.
  * `Signal.SIGIO` - I/O now possible.
  * `Signal.SIGPOLL` - Pollable event.
  * `Signal.SIGPWR` - Power failure.
  * `Signal.SIGSYS` - Bad system call.
  * `Signal.SIGRTMIN` - First real-time signal.
  * `Signal.SIGRTMAX` - Last real-time signal.

-----

## Table of methods

* Methods

  * Method [`bind#2`](#bind%232)
  * Method [`unbind#1`](#unbind%231)
  * Method [`send#2`](#send%232)
  * Method [`to_string#0`](#to_string%230)
  * Method [`print#0`](#print%230)

-----

## Methods

<a name="bind#2" />

### Method `static` [`bind#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L4554)

Binds signal handler delegate to given signal number. Handler delegate must
accept one parameter. Can only be called from main thread.

**Parameters:**

1. Type convertible to integer representing signal number (e.g. `Signal.SIGINT`).
2. Object of class `Delegate`, handler to be called when signal is received.

**Example:**

```cpp
// Signal.bind(Signal.SIGINT,handler_delegate);
("Signal class\n").print();
```
```
Signal class
```

<a name="unbind#1" />

### Method `static` [`unbind#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L4628)

Removes signal handler for given signal number. Can only be called from main thread.

**Parameters:**

1. Type convertible to integer representing signal number.

**Example:**

```cpp
// Signal.unbind(Signal.SIGINT);
("Signal class\n").print();
```
```
Signal class
```

<a name="send#2" />

### Method `static` [`send#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L4678)

Sends signal to process identified by process ID.

**Parameters:**

1. Type convertible to integer representing target process ID.
2. Type convertible to integer representing signal number.

**Example:**

```cpp
("pid: %d\n" % Sys.getpid()).print();
```
```
pid: 27142
```

<a name="to_string#0" />

### Method `spec` `static` [`to_string#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L4722)

Convert object of class `Signal` to object of class `String`.
This method returns name of class `Signal`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
("Signal.to_string(): %s\n" % Signal.to_string()).print();
```
```
Signal.to_string(): Signal
```

<a name="print#0" />

### Method `spec` `static` [`print#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L4731)

Print string representation of object of class `Signal` to standard output.
This method prints name of class `Signal`.

**Return:**

* Object of class `Signal`.

**Example:**

```cpp
Signal.print();
"\n".print();
```
```
Signal
```
