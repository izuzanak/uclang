
@begin
include "node.h"
@end

UclVar callback_0()
{/*{{{*/
  fprintf(stderr,"Callback succ. called\n");

  UclVar dict = UclVar::Dict();
  dict["one"] = 1;
  dict["two"] = 2;
  dict["three"] = 3;

  return UclVar::Json::create(dict);
}/*}}}*/

UclVar callback_1(UclVar a_op)
{/*{{{*/
  fprintf(stderr,"Callback succ. called: %s\n",a_op.__str());

  return a_op;
}/*}}}*/

UclVar callback_2(UclVar a_op,UclVar a_op_1)
{/*{{{*/
  fprintf(stderr,"Callback succ. called: %s\n",a_op.__str());

  UclVar arr = UclVar::Array();
  arr.push(a_op);
  arr.push(a_op_1);

  return arr;
}/*}}}*/

UclVar timer_cb(UclVar a_op)
{/*{{{*/
  fprintf(stderr,"TIMER_CB: %s\n",a_op.to_string().__str());

  return UclVar();
}/*}}}*/

// - websocket connection -
UclVar connection(UclVar a_conn)
{/*{{{*/
  UclVar reason = a_conn.reason();

  if ((reason == UclVar::WsConn::CB_ESTABLISHED).__int())
  {
    a_conn.callback_on_writable();
    return UclVar();
  }

  if ((reason == UclVar::WsConn::CB_RECEIVE).__int())
  {
    fprintf(stderr,"Received: %s\n",a_conn.received_data().__str());
    return UclVar();
  }

  if ((reason == UclVar::WsConn::CB_SERVER_WRITEABLE).__int())
  {
    a_conn.write("Hello there, how are you my friend?");
    return UclVar();
  }

  return UclVar();
}/*}}}*/

#if SYSTEM_TYPE_UNIX_CHROME_NACL != ENABLED
int main(int argc,char **argv)
{/*{{{*/

  // - call main thread function -
#if THREAD_LIB == THREAD_LIB_DSP_TSK
  fprintf(stderr,"DSP main function ... nothing to do\n");
#else

  bool modules[c_uclvar_module_count];
  memset(modules,0,c_uclvar_module_count*sizeof(bool));

  modules[c_uclvar_module_sys] = true;
  modules[c_uclvar_module_containers] = true;
  modules[c_uclvar_module_json] = true;
  modules[c_uclvar_module_websocket] = true;
  modules[c_uclvar_module_jit] = true;

  g_UclNode.Initialize(modules);

  try {
    //string_s string;
    //string.init();
    //string.load_text_file("config.json");

    //UclVar data = UclVar::Json::parse(string.data);
    //string.clear();

    UclVar data = UclVar::Json::parse("{\"name\":\"Jiří\",\"surname\":\"Zuzaňák\"}");
    //UclVar data = UclVar::Dict();

    //UclVar cb = UclVar::NodeCallback(callback_fun,1);
    //UclVar dlg = UclVar::Delegate(cb,cb.name(),1);

    //UclVar delegate = UclVar::Delegate(callback_0);
    //UclVar delegate = UclVar::Delegate(callback_1);
    UclVar delegate = UclVar::Delegate(callback_2);
    UclVar params = UclVar::Array();
    params.push("First");
    params.push("Second");

    UclVar result = delegate.call(params);
    (UclVar("call res: %s\n") % result.to_string()).print();

    UclVar format("Value: %s\n");
    
    (format % data["name"].to_string()).print();
    (format % data["surname"].to_string()).print();

    data["variable_0"] = UclVar();
    data["variable_1"] = 1.167;
    data["variable_2"] = 678 / 3;
    data["variable_3"] = "string value";

    UclVar array = UclVar::Array();
    array.push("index_0");
    array.push("index_1");
    array.push("index_2");
    array.push("index_3");
    array.push("index_4");
    array.push("index_5");

    //array.clear();
    //array.resize(10);

    UclVar dct = UclVar::Dict(array);
    (format % dct.next_key(dct.first_key())).print();

    (UclVar("Blank: '%s'\n") % UclVar::Blank().to_string()).print();

    (UclVar("Char: '%c'\n") % UclVar::Char()).print();
    (UclVar("Char: '%c'\n") % UclVar::Char('A')).print();

    (UclVar("Integer: %d\n") % UclVar::Integer()).print();
    (UclVar("Integer: %d\n") % UclVar::Integer(189)).print();
    (UclVar("Integer: %d\n") % UclVar::Integer("16",10)).print();

    (UclVar("Float: %f\n") % UclVar::Float()).print();
    (UclVar("Float: %f\n") % UclVar::Float("12.8")).print();

    (UclVar("String: %s\n") % UclVar::String()).print();
    (UclVar("String: %s\n") % UclVar::String(12.8)).print();

    (UclVar("compare: %d\n") % (UclVar(15.6).compare(10.9))).print();
    (UclVar("sin: %f\n") % (UclVar(15.6).sin())).print();

    UclVar str = "Some,Words,Separated,By,Commas";
    UclVar spl = str.split(",");
    (format % spl.to_string()).print();
    (format % UclVar(":").join(spl)).print();
    (UclVar("str.head(): %s\n") % str.head(10)).print();
    (UclVar("str.tail(): %s\n") % str.tail(10)).print();
    (UclVar("str.range(): %s\n") % str.range(10,15)).print();
    (UclVar("str.get_idx(): %s\n") % str.get_idx("Words").to_string()).print();
    (UclVar("str.get_idxs(): %s\n") % str.get_idxs("a").to_string()).print();

    (UclVar("Array: %s\n") % UclVar::Array().to_string()).print();
    (UclVar("Array: %s\n") % UclVar::Array(array).to_string()).print();

    (UclVar("Error: %s\n") % UclVar::Error().to_string()).print();

    (UclVar("Exception: %s\n") % UclVar::Exception().to_string()).print();
    (UclVar("Exception: %s\n") % UclVar::Exception("Some exception").to_string()).print();

    //UclVar::Exception();
    UclVar except = UclVar::Exception("Exception example");

    (UclVar("except.get_type(): %s\n") % except.get_type().to_string()).print();
    (UclVar("except.get_value(): %s\n") % except.get_value().to_string()).print();
    (UclVar("except.get_file_name(): %s\n") % except.get_file_name().to_string()).print();
    (UclVar("except.get_line(): %s\n") % except.get_line().to_string()).print();

    //UclVar::Exception("Exception example").__throw();

    (UclVar("Type: %s\n") % UclVar::Type().to_string()).print();
    (UclVar("Type: %s\n") % UclVar::Type(UclVar(10)).to_string()).print();

    (UclVar("Type: %s\n") % UclVar(10).__type().to_string()).print();
    (UclVar("Type: %s\n") % UclVar("Hello world").__type().to_string()).print();
    (UclVar("Type: %s\n") % UclVar::Array().__type().to_string()).print();

    UclVar mutex = UclVar::Mutex();
    mutex.lock();
    mutex.unlock();
    mutex.try_lock();
    mutex.unlock();

    (UclVar("Mutex::ERROR_INVALID: %s\n") % UclVar::Mutex::ERROR_INVALID.to_string()).print();
    (UclVar("Mutex::ERROR_DEADLOCK: %s\n") % UclVar::Mutex::ERROR_DEADLOCK.to_string()).print();
    (UclVar("Mutex::ERROR_BUSY: %s\n") % UclVar::Mutex::ERROR_BUSY.to_string()).print();
    (UclVar("Mutex::ERROR_PERMISSION: %s\n") % UclVar::Mutex::ERROR_PERMISSION.to_string()).print();

    (UclVar("Thread::ERROR_AGAIN: %s\n") % UclVar::Thread::ERROR_AGAIN.to_string()).print();
    (UclVar("Thread::ERROR_SEARCH: %s\n") % UclVar::Thread::ERROR_SEARCH.to_string()).print();
    (UclVar("Thread::ERROR_INVALID: %s\n") % UclVar::Thread::ERROR_INVALID.to_string()).print();
    (UclVar("Thread::ERROR_DEADLOCK: %s\n") % UclVar::Thread::ERROR_DEADLOCK.to_string()).print();
    (UclVar("Thread::ERROR_BUSY: %s\n") % UclVar::Thread::ERROR_BUSY.to_string()).print();

    (UclVar("spl.to_string(\" : \"): %s\n") % spl.to_string(" : ")).print();

    //UclVar::Sys::sleep(100);
    UclVar::Sys::srand(13);
    fprintf(stdout,"rand(): %lld\n",UclVar::Sys::rand().__int() % 1000);
    fprintf(stdout,"getpid(): %lld\n",UclVar::Sys::getpid().__int());
    fprintf(stdout,"getuid(): %lld\n",UclVar::Sys::getuid().__int());
    fprintf(stdout,"getgid(): %lld\n",UclVar::Sys::getgid().__int());
    UclVar::Sys::system("ls");
    UclVar::Sys::rmdir("koleda");
    UclVar::Sys::mkdir("koleda");
    UclVar::Sys::mkdir("koleda/test");
    UclVar::Sys::chdir("koleda");
    //UclVar::Sys::system("ls");
    UclVar::Sys::chdir("..");
    UclVar::Sys::rmdir("koleda/test");
    fprintf(stdout,"listdir(): %s\n",UclVar::Sys::listdir(".").to_string().__str());
    fprintf(stdout,"getenv(\"PWD\"): %s\n",UclVar::Sys::getenv("PWD").__str());
    fprintf(stdout,"is_file(\".\"): %s\n",UclVar::Sys::is_file(".").to_string().__str());
    fprintf(stdout,"is_dir(\".\"): %s\n",UclVar::Sys::is_dir(".").to_string().__str());
    fprintf(stdout,"time(): %s\n",UclVar::Sys::time().to_string().__str());

    UclVar Test = UclVar::Sys::NAME;
    (UclVar("Sys::NAME: %s\n") % UclVar::Sys::NAME).print();
    (UclVar("Sys::NAME: %s\n") % UclVar::Sys::NAME).print();
    (UclVar("Sys::NAME: %s\n") % UclVar::Sys::NAME).print();
    (UclVar("Sys::NAME: %s\n") % UclVar::Sys::NAME).print();
    (UclVar("Sys::SEP: %s\n") % UclVar::Sys::SEP).print();

    UclVar pipe = UclVar::Pipe("ls","r");
    UclVar("pipe.read(): %s\n") % pipe.read();
    pipe.close();

    UclVar file = UclVar::File("elmeter.log","r");
    file.read();

    UclVar::File::stdout.write("Output to stdout\n");
    UclVar::File::stderr.write("Output to stderr\n");

    UclVar();

    (UclVar("SocketAddr: %s\n") % UclVar::SocketAddr("192.168.2.69",8888).to_string()).print();

    (UclVar("Socket::AF_UNIX: %s\n") % UclVar::Socket::AF_UNIX.to_string()).print();
    (UclVar("Socket::AF_FILE: %s\n") % UclVar::Socket::AF_FILE.to_string()).print();
    (UclVar("Socket::AF_INET: %s\n") % UclVar::Socket::AF_INET.to_string()).print();
    (UclVar("Socket::SOCK_STREAM: %s\n") % UclVar::Socket::SOCK_STREAM.to_string()).print();
    (UclVar("Socket::SOCK_DGRAM: %s\n") % UclVar::Socket::SOCK_DGRAM.to_string()).print();
    (UclVar("Socket::SOCK_RAW: %s\n") % UclVar::Socket::SOCK_RAW.to_string()).print();
    (UclVar("Socket::SO_RCVTIMEO: %s\n") % UclVar::Socket::SO_RCVTIMEO.to_string()).print();
    (UclVar("Socket::SO_SNDTIMEO: %s\n") % UclVar::Socket::SO_SNDTIMEO.to_string()).print();

    // FIXME debug socket test
    //{
    //  UclVar sock = UclVar::Socket(UclVar::Socket::AF_INET,UclVar::Socket::SOCK_DGRAM);
    //  sock.bind(UclVar::SocketAddr("192.168.3.16",5601));
    //  //sock.set_timeout(UclVar::Socket::SO_RCVTIMEO,1000000);

    //  UclVar data;
    //  do {
    //    data = sock.recvfrom()[0];

    //    fprintf(stderr,"data: \"%s\"\n",data.__str());

    //  } while((data != "END").__int());
    //}

    UclVar regex = UclVar::Regex("xx*");
    UclVar res = regex.match("aaaaxxxxxbbbb");
    (UclVar("RES: %s\n") % res.to_string()).print();

    UclVar poll_arr = UclVar::Array();
    (UclVar("Poll: %s\n") % UclVar::Poll(poll_arr).to_string()).print();
    UclVar poll = UclVar::Poll(poll_arr);
    //poll.ready(100);
    //poll.poll(100);

    (UclVar("Signal::_SIGINT: %d\n") % UclVar::Signal::_SIGINT).print();
    (UclVar("Signal::_SIGTERM: %d\n") % UclVar::Signal::_SIGTERM).print();
    (UclVar("Signal::_SIGHUP: %d\n") % UclVar::Signal::_SIGHUP).print();

    (UclVar("Poll::POLLIN: %d\n") % UclVar::Poll::POLLIN).print();
    (UclVar("Poll::POLLPRI: %d\n") % UclVar::Poll::POLLPRI).print();
    (UclVar("Poll::POLLOUT: %d\n") % UclVar::Poll::POLLOUT).print();
    (UclVar("Poll::POLLERR: %d\n") % UclVar::Poll::POLLERR).print();
    (UclVar("Poll::POLLHUP: %d\n") % UclVar::Poll::POLLHUP).print();
    (UclVar("Poll::POLLNVAL: %d\n") % UclVar::Poll::POLLNVAL).print();

    (UclVar("Timer: %s\n") % UclVar::Timer().to_string()).print();

    UclVar timer = UclVar::Timer();
    timer.schedule(2000,UclVar::Delegate(timer_cb),"Test data");

    //unsigned t_idx = 0;
    //do {
    //  timer.process();
    //  (UclVar("timer.remain(): %s\n") % timer.remain().to_string()).print();

    //  usleep(250000);
    //} while(++t_idx < 20);

    // - terminate itself -
    //UclVar::Signal::send(UclVar::Sys::getpid(),UclVar::Signal::_SIGTERM);

    (UclVar("Stack: %s\n") % UclVar::Stack().to_string()).print();
    (UclVar("Stack: %s\n") % UclVar::Stack(spl).to_string()).print();
    UclVar stack = UclVar::Stack(spl);
    stack.push("Pushed");
    stack.push("Pushed");
    (UclVar("stack.pop(): %s\n") % stack.pop()).print();
    (UclVar("stack: %s\n") % stack.to_string()).print();

    (UclVar("Queue: %s\n") % UclVar::Queue().to_string()).print();

    UclVar queue = UclVar::Queue(spl);
    queue.insert(0);
    queue.insert(1);

    (UclVar("Queue: %s\n") % queue.to_string()).print();
    while(queue.length().__int() > 0)
    {
      (UclVar("Queue.next(): %s\n") % queue.next().to_string()).print();
    }

    (UclVar("Set: %s\n") % UclVar::Set().to_string()).print();

    UclVar set = UclVar::Set(spl);
    set.insert(0);
    set.insert(1);
    set.insert(1);

    (UclVar("Set: %s\n") % set.to_string()).print();

    set.remove(1);

    (UclVar("Set: %s\n") % set.to_string()).print();

    (UclVar("List: %s\n") % UclVar::List().to_string()).print();

    UclVar list = UclVar::List(spl);
    list.append("Appended");
    list.prepend("Prepended");
    list.insert_after(0,"After");
    list.insert_before(0,"Before");

    (UclVar("List: %s\n") % list.to_string()).print();

    (UclVar("Tree: %s\n") % UclVar::Tree().to_string()).print();
    (UclVar("Tree: %s\n") % UclVar::Tree(array).to_string()).print();

    (UclVar("Dict: %s\n") % UclVar::Dict().to_string()).print();
    (UclVar("Dict: %s\n") % UclVar::Dict(array).to_string()).print();

    //UclVar arr[] = {"test-protocol",UclVar::Delegate(connection)};
    //UclVar ws_ctx = UclVar::WsContext(8888,UclVar(ARRAY_LENGTH(arr),arr));
    //fprintf(stderr,"FDS: %s\n",ws_ctx.get_fds().to_string().__str());

    fprintf(stdout,"PORT_NO_LISTEN: %s\n",UclVar::WsContext::PORT_NO_LISTEN.to_string().__str());

    fprintf(stdout,"WRITE_TEXT: %s\n",UclVar::WsConn::WRITE_TEXT.to_string().__str());
    fprintf(stdout,"WRITE_BINARY: %s\n",UclVar::WsConn::WRITE_BINARY.to_string().__str());
    fprintf(stdout,"WRITE_CONTINUATION: %s\n",UclVar::WsConn::WRITE_CONTINUATION.to_string().__str());
    fprintf(stdout,"WRITE_HTTP: %s\n",UclVar::WsConn::WRITE_HTTP.to_string().__str());
    fprintf(stdout,"WRITE_CLOSE: %s\n",UclVar::WsConn::WRITE_CLOSE.to_string().__str());

    fprintf(stdout,"CB_ESTABLISHED: %s\n",UclVar::WsConn::CB_ESTABLISHED.to_string().__str());
    fprintf(stdout,"CB_CLIENT_CONNECTION_ERROR: %s\n",UclVar::WsConn::CB_CLIENT_CONNECTION_ERROR.to_string().__str());
    fprintf(stdout,"CB_CLIENT_FILTER_PRE_ESTABLISH: %s\n",UclVar::WsConn::CB_CLIENT_FILTER_PRE_ESTABLISH.to_string().__str());
    fprintf(stdout,"CB_CLIENT_ESTABLISHED: %s\n",UclVar::WsConn::CB_CLIENT_ESTABLISHED.to_string().__str());
    fprintf(stdout,"CB_CLOSED: %s\n",UclVar::WsConn::CB_CLOSED.to_string().__str());
    fprintf(stdout,"CB_RECEIVE: %s\n",UclVar::WsConn::CB_RECEIVE.to_string().__str());
    fprintf(stdout,"CB_CLIENT_RECEIVE: %s\n",UclVar::WsConn::CB_CLIENT_RECEIVE.to_string().__str());
    fprintf(stdout,"CB_CLIENT_RECEIVE_PONG: %s\n",UclVar::WsConn::CB_CLIENT_RECEIVE_PONG.to_string().__str());
    fprintf(stdout,"CB_CLIENT_WRITEABLE: %s\n",UclVar::WsConn::CB_CLIENT_WRITEABLE.to_string().__str());
    fprintf(stdout,"CB_SERVER_WRITEABLE: %s\n",UclVar::WsConn::CB_SERVER_WRITEABLE.to_string().__str());
    fprintf(stdout,"CB_HTTP: %s\n",UclVar::WsConn::CB_HTTP.to_string().__str());
    fprintf(stdout,"CB_HTTP_FILE_COMPLETION: %s\n",UclVar::WsConn::CB_HTTP_FILE_COMPLETION.to_string().__str());
    fprintf(stdout,"CB_FILTER_NETWORK_CONNECTION: %s\n",UclVar::WsConn::CB_FILTER_NETWORK_CONNECTION.to_string().__str());
    fprintf(stdout,"CB_FILTER_PROTOCOL_CONNECTION: %s\n",UclVar::WsConn::CB_FILTER_PROTOCOL_CONNECTION.to_string().__str());
    fprintf(stdout,"CB_OPENSSL_LOAD_EXTRA_CLIENT_VERIFY_CERTS: %s\n",UclVar::WsConn::CB_OPENSSL_LOAD_EXTRA_CLIENT_VERIFY_CERTS.to_string().__str());
    fprintf(stdout,"CB_OPENSSL_LOAD_EXTRA_SERVER_VERIFY_CERTS: %s\n",UclVar::WsConn::CB_OPENSSL_LOAD_EXTRA_SERVER_VERIFY_CERTS.to_string().__str());
    fprintf(stdout,"CB_OPENSSL_PERFORM_CLIENT_CERT_VERIFICATION: %s\n",UclVar::WsConn::CB_OPENSSL_PERFORM_CLIENT_CERT_VERIFICATION.to_string().__str());
    fprintf(stdout,"CB_CLIENT_APPEND_HANDSHAKE_HEADER: %s\n",UclVar::WsConn::CB_CLIENT_APPEND_HANDSHAKE_HEADER.to_string().__str());
    fprintf(stdout,"CB_CONFIRM_EXTENSION_OKAY: %s\n",UclVar::WsConn::CB_CONFIRM_EXTENSION_OKAY.to_string().__str());
    fprintf(stdout,"CB_CLIENT_CONFIRM_EXTENSION_SUPPORTED: %s\n",UclVar::WsConn::CB_CLIENT_CONFIRM_EXTENSION_SUPPORTED.to_string().__str());
    fprintf(stdout,"CB_PROTOCOL_INIT: %s\n",UclVar::WsConn::CB_PROTOCOL_INIT.to_string().__str());
    fprintf(stdout,"CB_PROTOCOL_DESTROY: %s\n",UclVar::WsConn::CB_PROTOCOL_DESTROY.to_string().__str());
    fprintf(stdout,"CB_ADD_POLL_FD: %s\n",UclVar::WsConn::CB_ADD_POLL_FD.to_string().__str());
    fprintf(stdout,"CB_DEL_POLL_FD: %s\n",UclVar::WsConn::CB_DEL_POLL_FD.to_string().__str());
    fprintf(stdout,"CB_CHANGE_MODE_POLL_FD: %s\n",UclVar::WsConn::CB_CHANGE_MODE_POLL_FD.to_string().__str());

    fprintf(stdout,"TIMEOUT_NO_PENDING: %s\n",UclVar::WsConn::TIMEOUT_NO_PENDING.to_string().__str());
    fprintf(stdout,"TIMEOUT_AWAITING_PROXY_RESPONSE: %s\n",UclVar::WsConn::TIMEOUT_AWAITING_PROXY_RESPONSE.to_string().__str());
    fprintf(stdout,"TIMEOUT_AWAITING_CONNECT_RESPONSE: %s\n",UclVar::WsConn::TIMEOUT_AWAITING_CONNECT_RESPONSE.to_string().__str());
    fprintf(stdout,"TIMEOUT_ESTABLISH_WITH_SERVER: %s\n",UclVar::WsConn::TIMEOUT_ESTABLISH_WITH_SERVER.to_string().__str());
    fprintf(stdout,"TIMEOUT_AWAITING_SERVER_RESPONSE: %s\n",UclVar::WsConn::TIMEOUT_AWAITING_SERVER_RESPONSE.to_string().__str());
    fprintf(stdout,"TIMEOUT_AWAITING_PING: %s\n",UclVar::WsConn::TIMEOUT_AWAITING_PING.to_string().__str());
    fprintf(stdout,"TIMEOUT_CLOSE_ACK: %s\n",UclVar::WsConn::TIMEOUT_CLOSE_ACK.to_string().__str());
    fprintf(stdout,"TIMEOUT_AWAITING_EXTENSION_CONNECT_RESPONSE: %s\n",UclVar::WsConn::TIMEOUT_AWAITING_EXTENSION_CONNECT_RESPONSE.to_string().__str());
    fprintf(stdout,"TIMEOUT_SENT_CLIENT_HANDSHAKE: %s\n",UclVar::WsConn::TIMEOUT_SENT_CLIENT_HANDSHAKE.to_string().__str());
    fprintf(stdout,"TIMEOUT_SSL_ACCEPT: %s\n",UclVar::WsConn::TIMEOUT_SSL_ACCEPT.to_string().__str());

    //unsigned idx = 0;
    //do {
    //  fprintf(stderr,"Waiting ...\n");
    //  ws_ctx.process(1000);
    //} while(++idx < 15);

    UclVar code = UclVar::WsBase64::encode("Some text ...");
    (UclVar("code: %s\n") % code).print();
    code = UclVar::WsBase64::decode(code);
    (UclVar("code: %s\n") % code).print();

    (UclVar("string: %s\n") % UclVar(5,"Hello world")).print();

    UclVar res_str = UclVar("CB_OPENSSL_LOAD_EXTRA_SERVER_VERIFY_CERTS").replace("OPENSSL","GCRYPT");
    printf("res: %s\n",res_str.__str());

    UclVar("-----\n").print();

    // - jit test -
    {
      fprintf(stdout,"TYPE_I8: %s\n",UclVar::JitContext::TYPE_I8.to_string().__str());
      fprintf(stdout,"TYPE_U8: %s\n",UclVar::JitContext::TYPE_U8.to_string().__str());
      fprintf(stdout,"TYPE_I16: %s\n",UclVar::JitContext::TYPE_I16.to_string().__str());
      fprintf(stdout,"TYPE_U16: %s\n",UclVar::JitContext::TYPE_U16.to_string().__str());
      fprintf(stdout,"TYPE_I32: %s\n",UclVar::JitContext::TYPE_I32.to_string().__str());
      fprintf(stdout,"TYPE_U32: %s\n",UclVar::JitContext::TYPE_U32.to_string().__str());
      fprintf(stdout,"TYPE_I64: %s\n",UclVar::JitContext::TYPE_I64.to_string().__str());
      fprintf(stdout,"TYPE_U64: %s\n",UclVar::JitContext::TYPE_U64.to_string().__str());
      fprintf(stdout,"TYPE_F32: %s\n",UclVar::JitContext::TYPE_F32.to_string().__str());
      fprintf(stdout,"TYPE_F64: %s\n",UclVar::JitContext::TYPE_F64.to_string().__str());

      //UclVar::Sys::exit(12);

      UclVar jit_ctx = UclVar::JitContext();
      UclVar jit_fun = jit_ctx.create_fun(
"i32 test(u32 a_ptr,u32 a_cnt)"
"{"
"  i32 *ptr = (i32 *)a_ptr;"
"  i32 *ptr_end = ptr + a_cnt;"
""
"  i32 idx = 0;"
"  if (ptr < ptr_end)"
"  {"
"    do {"
"      *ptr = idx++;"
"    } while(++ptr < ptr_end);"
"  }"
""
"  return 0;"
"}"
      );

      int idx;
      int num_cnt = 10;
      int nums[num_cnt];
      memset(nums,0,num_cnt*sizeof(int));
      for (idx=0;idx<num_cnt;idx++) fprintf(stderr,"%d, ",nums[idx]); fprintf(stderr,"\n");

      UclVar args_arr[] = {(long long int)nums,num_cnt};
      UclVar args(ARRAY_LENGTH(args_arr),args_arr);

      res = jit_fun.call(args);
      for (idx=0;idx<num_cnt;idx++) fprintf(stderr,"%d, ",nums[idx]); fprintf(stderr,"\n");

      fprintf(stdout,"jit_fun.signature(): %s\n",jit_fun.signature().to_string().__str());
      fprintf(stdout,"res: %s\n",res.to_string().__str());
    }
  }
  catch (std::string reason)
  {
    if (reason == "Exception")
    {
      g_UclNode.PrintExceptionMessage();
    }
    else
    {
      fprintf(stderr," ---------------------------------------- \n");
      fprintf(stderr,"Error: %s\n",reason.data());
      fprintf(stderr," ---------------------------------------- \n");
    }
  }

  g_UclNode.Clear();
#endif
}/*}}}*/
#endif

