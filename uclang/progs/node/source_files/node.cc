
@begin
include "node.h"
@end

#if SYSTEM_TYPE_UNIX_CHROME_NACL != ENABLED
int main(int argc,char **argv)
{/*{{{*/

  // - select modules to import -
  const char *modules[] = {
    "sys","containers","json","websocket","jit",NULL
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

