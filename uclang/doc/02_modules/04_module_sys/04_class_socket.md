# Class Socket

Class providing access to system sockets.

-----

## Static constants

* Domain identifying protocol family to be used for communication
  * `Socket.AF_UNIX` - Local communication socket.
  * `Socket.AF_FILE` - Local communication socket.
  * `Socket.AF_INET` - IPv4 Internet protocols.

* Type specifying communication semantics
  * `Socket.SOCK_STREAM` - Sequenced, reliable, two-way, connection-based byte streams.
  * `Socket.SOCK_DGRAM` - Connectionless, unreliable messages of a fixed maximum length.
  * `Socket.SOCK_RAW` - Raw network protocol access.

* Socket related options
  * `Socket.SOL_SOCKET` - Socket level for socket options.
  * `Socket.SO_ERROR` - Get and clear pending socket error.
  * `Socket.SO_SNDBUF` - Send buffer size.
  * `Socket.SO_RCVBUF` - Receive buffer size.
  * `Socket.SO_RCVTIMEO` - Receiving timeout until reporting an error.
  * `Socket.SO_SNDTIMEO` - Sending timeout until reporting an error.
  * `Socket.SO_BROADCAST` - Enable sending of broadcast messages.

* Protocol level constants
  * `Socket.IPPROTO_IP` - IP protocol level.

* IP protocol options
  * `Socket.IP_ADD_MEMBERSHIP` - Join a multicast group.
  * `Socket.IP_DROP_MEMBERSHIP` - Leave a multicast group.

-----

## Table of methods

* Constructors

  * Constructor [`Socket#2`](#Socket%232)

* Operators

  * Operator [`operator_binary_equal#1`](#operator_binary_equal%231)

* Methods

  * Method [`listen#2`](#listen%232)
  * Method [`accept#0`](#accept%230)
  * Method [`connect#1`](#connect%231)
  * Method [`bind#1`](#bind%231)
  * Method [`sendto#2`](#sendto%232)
  * Method [`recvfrom#0`](#recvfrom%230)
  * Method [`close#0`](#close%230)
  * Method [`set_timeout#2`](#set_timeout%232)
  * Method [`sockopt#3`](#sockopt%233)
  * Method [`sockopt#2`](#sockopt%232)
  * Method [`write#1`](#write%231)
  * Method [`read#0`](#read%230)
  * Method [`read#1`](#read%231)
  * Method [`get_fd#0`](#get_fd%230)
  * Method [`to_string#0`](#to_string%230)
  * Method [`print#0`](#print%230)

-----

## Example context

All examples introduced below are executed in following context.

```cpp
class Main
{
  static public parallel sock_source(socket,@stop)
  {
    poll = new Poll([socket.get_fd(),Poll.POLLIN | Poll.POLLPRI]);

    try {
      while (!stop)
      {
        if (poll.ready(100))
        {
          conn_sock = socket.accept()[0];
          
          for (line_idx <- [1,2,3,4,5])
            conn_sock.write("Data line %d\n" % line_idx);

          conn_sock.close();
        }
      }
    }
    catch (e) {}
  }

  public static main(argv)
  {
    stop = 0;

    socket = new Socket(Socket.AF_INET,Socket.SOCK_STREAM);
    socket.listen(new SocketAddr("127.0.0.1",5555),10);
    sock_source(socket,stop);

    try {
--------------------------------- example code ---------------------------------
    }
    catch (e)
    {
      e.error_print();
    }

    stop = 1;
  }
}
```

-----

## Constructors

<a name="Socket#2" />

### Constructor [`Socket#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L3043)

Creates object of class `Socket` with given domain and type.

**Parameters:**

1. Type convertible to integer representing communication domain (e.g. `Socket.AF_INET`).
2. Type convertible to integer representing socket type (e.g. `Socket.SOCK_STREAM`).

**Example:**

```cpp
obj = new Socket(Socket.AF_INET,Socket.SOCK_STREAM);
("obj: %s\n" % $obj).print();
obj.close();
```
```
obj: Socket
```

-----

## Operators

<a name="operator_binary_equal#1" />

### Operator [`operator_binary_equal#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L3031)

Assignment operator `=`. Object of class `Socket` is replaced by method parameter.

**Parameters:**

1. Any type.

**Return:**

* Method parameter.

**Example:**

```cpp
obj = new Socket(Socket.AF_INET,Socket.SOCK_STREAM);
obj.connect(new SocketAddr("127.0.0.1",5555));
("obj: %s\n" % $obj).print();
obj = "New value";
("obj: %s\n" % $obj).print();
```
```
obj: Socket
obj: New value
```

-----

## Methods

<a name="listen#2" />

### Method [`listen#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L3068)

Binds socket to address and starts listening for incoming connections.

**Parameters:**

1. Object of class `SocketAddr` representing address to bind to.
2. Type convertible to integer representing connection backlog size.

**Example:**

```cpp
obj = new Socket(Socket.AF_INET,Socket.SOCK_STREAM);
obj.connect(new SocketAddr("127.0.0.1",5555));
("obj: %s\n" % $obj).print();
```
```
obj: Socket
```

<a name="accept#0" />

### Method [`accept#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L3134)

Accepts incoming connection on listening socket. Returns array containing
new connected socket and address of connecting peer.

**Return:**

* Object of class `Array` containing object of class `Socket` and object of class `SocketAddr`.

**Example:**

```cpp
obj = new Socket(Socket.AF_INET,Socket.SOCK_STREAM);
obj.connect(new SocketAddr("127.0.0.1",5555));
("obj: %s\n" % $obj).print();
```
```
obj: Socket
```

<a name="connect#1" />

### Method [`connect#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L3221)

Connects socket to given address.

**Parameters:**

1. Object of class `SocketAddr` representing address to connect to.

**Example:**

```cpp
obj = new Socket(Socket.AF_INET,Socket.SOCK_STREAM);
obj.connect(new SocketAddr("127.0.0.1",5555));
("obj: %s\n" % $obj).print();
```
```
obj: Socket
```

<a name="bind#1" />

### Method [`bind#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L3278)

Binds socket to given local address.

**Parameters:**

1. Object of class `SocketAddr` representing local address to bind to.

**Example:**

```cpp
obj = new Socket(Socket.AF_INET,Socket.SOCK_DGRAM);
obj.bind(new SocketAddr("127.0.0.1",0));
("obj: %s\n" % $obj).print();
obj.close();
```
```
obj: Socket
```

<a name="sendto#2" />

### Method [`sendto#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L3332)

Sends data to given address using connectionless socket.

**Parameters:**

1. Object of class `String` containing data to send.
2. Object of class `SocketAddr` representing target address.

**Example:**

```cpp
obj = new Socket(Socket.AF_INET,Socket.SOCK_DGRAM);
obj.bind(new SocketAddr("127.0.0.1",0));
("obj: %s\n" % $obj).print();
obj.close();
```
```
obj: Socket
```

<a name="recvfrom#0" />

### Method [`recvfrom#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L3377)

Receives data from connectionless socket. Returns array containing received
data string and sender address.

**Return:**

* Object of class `Array` containing object of class `String` and object of class `SocketAddr`.

**Example:**

```cpp
obj = new Socket(Socket.AF_INET,Socket.SOCK_DGRAM);
obj.bind(new SocketAddr("127.0.0.1",0));
("obj: %s\n" % $obj).print();
obj.close();
```
```
obj: Socket
```

<a name="close#0" />

### Method [`close#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L3466)

Closes socket and releases associated resources.

**Example:**

```cpp
obj = new Socket(Socket.AF_INET,Socket.SOCK_STREAM);
obj.close();
("closed\n").print();
```
```
closed
```

<a name="set_timeout#2" />

### Method [`set_timeout#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L3494)

Sets socket send/receive timeout.

**Parameters:**

1. Type convertible to integer representing timeout seconds.
2. Type convertible to integer representing timeout microseconds.

**Example:**

```cpp
obj = new Socket(Socket.AF_INET,Socket.SOCK_STREAM);
obj.connect(new SocketAddr("127.0.0.1",5555));
obj.set_timeout(5,0);
("timeout set\n").print();
```
```
timeout set
```

<a name="sockopt#3" />

### Method [`sockopt#3`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L3530)

Sets socket option.

**Parameters:**

1. Type convertible to integer representing option level (e.g. `Socket.SOL_SOCKET`).
2. Type convertible to integer representing option name (e.g. `Socket.SO_BROADCAST`).
3. Type convertible to integer representing option value.

**Example:**

```cpp
obj = new Socket(Socket.AF_INET,Socket.SOCK_DGRAM);
obj.sockopt(Socket.SOL_SOCKET,Socket.SO_BROADCAST,1);
("option set\n").print();
obj.close();
```
```
option set
```

<a name="sockopt#2" />

### Method [`sockopt#2`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L3640)

Retrieves socket option value.

**Parameters:**

1. Type convertible to integer representing option level (e.g. `Socket.SOL_SOCKET`).
2. Type convertible to integer representing option name (e.g. `Socket.SO_SNDBUF`).

**Return:**

* Object of class `Integer` representing option value.

**Example:**

```cpp
obj = new Socket(Socket.AF_INET,Socket.SOCK_STREAM);
("SO_SNDBUF: %d\n" % obj.sockopt(Socket.SOL_SOCKET,Socket.SO_SNDBUF)).print();
obj.close();
```
```
SO_SNDBUF: 16384
```

<a name="write#1" />

### Method [`write#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L4144)

Writes data to connected socket.

**Parameters:**

1. Object of class `String` containing data to write.

**Example:**

```cpp
obj = new Socket(Socket.AF_INET,Socket.SOCK_STREAM);
obj.connect(new SocketAddr("127.0.0.1",5555));
obj.write("Hello\n");
("written\n").print();
```
```
written
```

<a name="read#0" />

### Method [`read#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L4185)

Reads all available data from socket.

**Return:**

* Object of class `String`.

**Example:**

```cpp
obj = new Socket(Socket.AF_INET,Socket.SOCK_STREAM);
obj.connect(new SocketAddr("127.0.0.1",5555));
data = obj.read();
("data: %s\n" % data).print();
```
```
data: Data line 1
Data line 2

```

<a name="read#1" />

### Method [`read#1`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L4256)

Reads exactly given number of bytes from socket.

**Parameters:**

1. Type convertible to integer representing number of bytes to read.

**Return:**

* Object of class `String`.

**Example:**

```cpp
obj = new Socket(Socket.AF_INET,Socket.SOCK_STREAM);
obj.connect(new SocketAddr("127.0.0.1",5555));
data = obj.read(5);
("data: %s\n" % data).print();
```
```
data: Data 
```

<a name="get_fd#0" />

### Method [`get_fd#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L4323)

Returns underlying file descriptor of socket.

**Return:**

* Object of class `Integer`.

**Example:**

```cpp
obj = new Socket(Socket.AF_INET,Socket.SOCK_STREAM);
("type: %s\n" % $(type obj.get_fd())).print();
obj.close();
```
```
type: Integer
```

<a name="to_string#0" />

### Method `spec` `static` [`to_string#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L3704)

Convert object of class `Socket` to object of class `String`.
This method returns name of class `Socket`.

**Return:**

* Object of class `String`.

**Example:**

```cpp
("Socket.to_string(): %s\n" % Socket.to_string()).print();
```
```
Socket.to_string(): Socket
```

<a name="print#0" />

### Method `spec` `static` [`print#0`](https://github.com/izuzanak/uclang/blob/master/uclang/../uclang/mods/sys_uclm/source_files/sys_module.cc#L3713)

Print string representation of object of class `Socket` to standard output.
This method prints name of class `Socket`.

**Return:**

* Object of class `Socket`.

**Example:**

```cpp
Socket.print();
"\n".print();
```
```
Socket
```
