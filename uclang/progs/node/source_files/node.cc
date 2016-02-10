
@begin
include "node.h"
@end

UclVar callback(UclVar a_conn)
{/*{{{*/
  UCL_NODE_TRY

  UclVar type = a_conn.get_type();

  if (type.__int() == UclVar::HttpConn::TYPE_GET.__int())
  {
    UclVar resp = UclVar::HttpResp(
      UclVar::HttpResp::FROM_STRING,"<html><body>Hello, browser!</body></html>");

    resp.add_header("Content-Type","text/html");
    a_conn.queue_response(UclVar::HttpResp::HTTP_OK,resp);
  }
  else
  {
    //UclVar::Exception(UclVar("Unknown method: \"%s\"") % a_conn.method())._throw();
    fprintf(stderr,"Unknown method: \"%s\"\n",a_conn.method().__str());
  }

  UCL_NODE_CATCH

  return UclVar();
}/*}}}*/

UclVar node_to_dict(UclVar a_node)
{/*{{{*/
  UclVar dict = UclVar::Dict();

  UCL_FOR_LOOP(node,a_node.nodes(),
  {
    dict[node.name()] = node.text();
  })

  return dict;
}/*}}}*/

UclVar parse_cb(UclVar a_state)
{/*{{{*/
  if (a_state.rule_idx().__int() == 1)
  {
    printf("rule_body: '%s' , '%s' , '%s'\n",
      a_state.rule_body(0).__str(),a_state.rule_body(1).__str(),a_state.rule_body(2).__str());
  }

  return UclVar();
}/*}}}*/

#if SYSTEM_TYPE_UNIX_CHROME_NACL != ENABLED
int main(int argc,char **argv)
{/*{{{*/

  // - select modules to import -
  const char *modules[] = {
    "sys","containers",NULL
    //"sys","containers","json","websocket","jit","ucf",NULL
  };

  // - initialize uclang node -
  if (g_UclNode.Initialize(modules))
  {
    UCL_NODE_TRY

    // - simple loop and array -
    {
      UclVar array = UclVar::Array();

      UclVar idx = 0;
      do {
        array.push(idx);
      } while((++idx < 10).__int());

      printf("array: %s\n",array.to_string().__str());
    }

    // - slice range test -
    //{/*{{{*/
    //  UclVar array = {0,1,2,3,4,5,6,7,8,9};
    //  printf("array: %s\n",array.to_string().__str());

    //  UclVar slice = array.__slice(7,LLONG_MAX,-2);
    //  UCL_FOR_LOOP(var,slice,
    //  {
    //    printf("val: %s\n",var.to_string().__str());
    //  })
    //}/*}}}*/

    // - for loop test -
    //{/*{{{*/
    //  UclVar dict = UclVar::Dict({1,2,3,4,5,6});
    //  UCL_FOR_LOOP(item,dict,
    //  {
    //    printf("key/val: %" HOST_LL_FORMAT "d:%" HOST_LL_FORMAT "d\n",item.__int(),dict[item].__int());
    //  })

    //  // - file loop test -
    //  UclVar file = UclVar::File("node.log","r");
    //  UCL_FOR_LOOP(item,file,
    //  {
    //    printf("item: %s\n",item.__str());
    //  })

    //  // - array loop test -
    //  UclVar array = {0,1,2,3,4,5,6,7,8,9};
    //  UCL_FOR_LOOP(item,array,
    //  {
    //    printf("item: %" HOST_LL_FORMAT "d\n",item.__int());
    //  })
    //}/*}}}*/

    // - http server example -
    //{/*{{{*/
    //  UclVar dlg = UclVar::Delegate(callback);
    //  UclVar server = UclVar::HttpServer(8888,dlg);

    //  do {
    //      UclVar poll = UclVar::Poll(server.get_fds());
    //      poll.ready(5000);

    //      server.process();
    //  } while(true);
    //}/*}}}*/

    // - exception test -
    //{/*{{{*/
    //  UCL_NODE_TRY
    //  UclVar(10)/0;
    //  UCL_NODE_CATCH
    //}/*}}}*/

    // - test ucl module -
    //{/*{{{*/

    //  // FIXME object construction test
    //  UclVar test = UclVar::__new("NodeTest");
    //  printf("test: %s\n",test.to_string().__str());
    //  test.__free();

    //  test = UclVar::__new("NodeTest","a");
    //  printf("test: %s\n",test.to_string().__str());
    //  test.__free();

    //  test = UclVar::__new("NodeTest","a","b");
    //  printf("test: %s\n",test.to_string().__str());
    //  test.__free();

    //  test = UclVar::__new("NodeTest","a","b","c");
    //  printf("test: %s\n",test.to_string().__str());
    //  test.__free();

    //  // FIXME method call test
    //  test = UclVar::__new("NodeTest");
    //  test.__call("print");
    //  putchar('\n');
    //  test.__call("print","a");
    //  putchar('\n');
    //  test.__call("print","a","b");
    //  putchar('\n');
    //  test.__call("print","a","b","c");
    //  putchar('\n');
    //  test.__call("print","a","b","c","d");
    //  putchar('\n');
    //  test.__free();

    //  // FIXME method call return value test
    //  test = UclVar::__new("NodeTest");
    //  UclVar val = test.__call("to_string");
    //  printf("val: %s\n",val.to_string().__str());
    //  test.__free();

    //  // FIXME static method call test
    //  UclVar value;

    //  value = UclVar::__static_call("NodeTest","static_method");
    //  printf("value: %" HOST_LL_FORMAT "d\n",value.__int());

    //  value = UclVar::__static_call("NodeTest","static_method",1);
    //  printf("value: %" HOST_LL_FORMAT "d\n",value.__int());

    //  value = UclVar::__static_call("NodeTest","static_method",1,2);
    //  printf("value: %" HOST_LL_FORMAT "d\n",value.__int());

    //  // FIXME member select test
    //  test = UclVar::__new("NodeTest","a","b");
    //  printf("test.m_value: %s\n",test.__member("m_value").__str());
    //  test.__free();
    //}/*}}}*/

    // - module pack test -
    //{/*{{{*/

    //  // - write to file -
    //  UclVar file = UclVar::File("pack.bin","w")
    //    .write_close(UclVar::Pack::pack(
    //          {1,2,3,4,UclVar::Dict({1,2,3,4}),"Hello World!!!"}));

    //  // - read from file -
    //  {
    //    UclVar array = UclVar::Pack::unpack(
    //      UclVar::File("pack.bin","r").read_close());

    //    printf("unpacked array: %s\n",array.to_string().__str());
    //  }
    //}/*}}}*/

    // - module algorithms test -
    //{/*{{{*/
    //  UclVar range = UclVar::Range(0,20);
    //  UCL_FOR_LOOP(item,range,
    //  {
    //    printf("%" HOST_LL_FORMAT "d\n",item.__int());
    //  })

    //  UclVar array = UclVar::Array(UclVar::Range(0,1000));
    //  printf("array: %s\n",array.to_string().__str());
    //}/*}}}*/

    // - module curl test -
    //{/*{{{*/
    //  UclVar res = UclVar::Curl::GET("localhost:8888");
    //  printf("data: %s\n",res.data().__str());
    //}/*}}}*/

    // - module xml test -
    //{/*{{{*/
    //  UclVar data = UclVar::File("trasa.gpx","r").read_close();
    //  UclVar doc = UclVar::Xml::parse(data);

    //  UclVar nodes = doc.nodes();
    //  UCL_FOR_LOOP(node,nodes,
    //  {
    //    UclVar dict = node_to_dict(node.nodes()[1]);
    //    printf("node: %s\n",dict.to_string().__str());
    //  })
    //}/*}}}*/

    // - module fpt test -
    //{/*{{{*/
    //  UclVar server = "127.0.0.1";
    //  UclVar user = "<user>";
    //  UclVar pass = "<pass>";

    //  UclVar ftp_session = UclVar::FtpSession(server);
    //  ftp_session.login(user,pass);

    //  ftp_session.chdir("folder/work");
    //  
    //  //UclVar list = ftp_session.listdir(".");
    //  //printf("LIST: %s\n",list.to_string().__str());

    //  UCL_FOR_LOOP(file,ftp_session.listdir("."),
    //  {
    //    printf("FILE: %s\n",file.__str());
    //  });
    //}/*}}}*/

    // - module ssh2 test -
    //{/*{{{*/
    //  UclVar server = "192.168.2.2";
    //  UclVar user = "<user>";
    //  UclVar password = "<pass>";

    //  UclVar socket = UclVar::Socket(UclVar::Socket::AF_INET,UclVar::Socket::SOCK_STREAM);
    //  socket.connect(UclVar::SocketAddr(server,22));

    //  UclVar ssh_session = UclVar::Ssh2Session(socket);
    //  UclVar auth_list = ssh_session.userauth_list(user);
    //  printf("auth_list: %s\n",auth_list.to_string().__str());

    //  ssh_session.userauth_password(user,password);
    //  UclVar channel = ssh_session.shell();

    //  channel.write("ls\n");
    //  channel.flush();
    //  printf("DATA: %s\n",channel.read().__str());

    //  channel.send_eof();
    //}/*}}}*/

    // - module sqlite test -
    //{/*{{{*/
    //  UclVar conn = UclVar::SQLiteConn("gtrip.sqlite",
    //    UclVar::SQLiteConn::OPEN_CREATE |
    //    UclVar::SQLiteConn::OPEN_READWRITE |
    //    UclVar::SQLiteConn::OPEN_FULLMUTEX);

    //  UclVar res = conn.prepare("select * from STATION;");
    //  UCL_FOR_LOOP(station,res,
    //  {
    //    printf("station: %s\n",station.to_string().__str());
    //  });
    //}/*}}}*/

    // - module parser test -
    //{/*{{{*/
    //  UclVar fa = UclVar::FinalAutomata({"\"xxx\"","'y'.'y'*","\"zzz\""});
    //  UclVar src = fa.get_source("xxxyyyyyyyyzzz");

    //  UCL_FOR_LOOP(term,src,
    //  {
    //    printf("terminal: %" HOST_LL_FORMAT "d\n",term.__int());
    //  });

    //  UclVar parser = UclVar::Parser(UclVar::File("new_reg.rules","r").read_close());
    //  parser.parse("('\\xff' + <\\nz>.d + \"Hello\\n\" + '\\n' + '\\\\' + 'X' + |0123| + |abc\\||)\0",UclVar::Delegate(parse_cb));
    //}/*}}}*/

#if __cplusplus >= 201103

    // - c++11 initializer_list -
    {
      UclVar array = {1,2,3,4,UclVar::Dict({1,2,3,4}),"Hello World!!!"};
      array[4]["test"] = 120;
      printf("array: %s\n",array.to_string().__str());
    }
#endif

    UCL_NODE_CATCH

    g_UclNode.Clear();
  }

  return 0;
}/*}}}*/
#endif

