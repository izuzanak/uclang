
@begin
include "node.h"
@end

#if SYSTEM_TYPE_UNIX_CHROME_NACL != ENABLED
int main(int argc,char **argv)
{/*{{{*/

  // - select modules to import -
  const char *modules[] = {
    "node_test",NULL
    //"sys","containers","json","websocket","jit",NULL
  };

  // - initialize uclang node -
  if (g_UclNode.Initialize(modules))
  {
    try {

      // - simple loop and array -
      {
        UclVar array = UclVar::Array();
        UclVar idx = 0;
        do {
          array.push(idx);
        } while((++idx < 10).__int());

        printf("array: %s\n",array.to_string().__str());
      }

      // FIXME object construction test
      UclVar test = UclVar::__new("NodeTest");
      printf("test: %s\n",test.to_string().__str());
      test.__free();

      test = UclVar::__new("NodeTest","a");
      printf("test: %s\n",test.to_string().__str());
      test.__free();

      test = UclVar::__new("NodeTest","a","b");
      printf("test: %s\n",test.to_string().__str());
      test.__free();

      test = UclVar::__new("NodeTest","a","b","c");
      printf("test: %s\n",test.to_string().__str());
      test.__free();

      // FIXME method call test
      test = UclVar::__new("NodeTest");
      test.__call("print");
      putchar('\n');
      test.__call("print","a");
      putchar('\n');
      test.__call("print","a","b");
      putchar('\n');
      test.__call("print","a","b","c");
      putchar('\n');
      test.__call("print","a","b","c","d");
      putchar('\n');
      test.__free();

      // FIXME method call return value test
      test = UclVar::__new("NodeTest");
      UclVar val = test.__call("to_string");
      printf("val: %s\n",val.to_string().__str());
      test.__free();

      // FIXME static method call test
      UclVar value;

      value = UclVar::__static_call("NodeTest","static_method");
      printf("value: %lld\n",value.__int());

      value = UclVar::__static_call("NodeTest","static_method",1);
      printf("value: %lld\n",value.__int());

      value = UclVar::__static_call("NodeTest","static_method",1,2);
      printf("value: %lld\n",value.__int());

      // FIXME member select test
      test = UclVar::__new("NodeTest","a","b");
      printf("test.m_value: %s\n",test.__member("m_value").__str());
      test.__free();

#if __cplusplus >= 201103

      // - c++11 initializer_list -
      {
        UclVar array = {1,2,3,4,"Hello World!!!"};
        printf("array: %s\n",array.to_string().__str());
      }
#endif

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
  }

  return 0;
}/*}}}*/
#endif

