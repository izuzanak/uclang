
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

#if SYSTEM_TYPE_UNIX_CHROME_NACL != ENABLED
int main(int argc,char **argv)
{/*{{{*/

  // - select modules to import -
  const char *modules[] = {
    "containers","sys",NULL
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

    // - for loop test -
    //{/*{{{*/
    //  UclVar dict = UclVar::Dict({1,2,3,4,5,6});
    //  UCL_FOR_LOOP(item,dict,
    //  {
    //    printf("key/val: %lld:%lld\n",item.__int(),dict[item].__int());
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
    //    printf("item: %lld\n",item.__int());
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

    // - test ucl module usage -
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

    // FIXME write_close, read_close test
    UclVar data = UclVar::File("node.log","r").read_close();
    UclVar::File("test.log","w").write_close(data);

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

