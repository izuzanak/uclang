
#include "p.ucl_libnode.h"

int main(int argc,char **argv)
{/*{{{*/

  // - select modules to import -
  const char *modules[] = {
    "containers",NULL
  };

  // - initialize uclang node -
  if (g_UclNode.Initialize(modules))
  {
    try {

      // - create simple array -
      UclVar array_data[] = {1,2,3,4};
      UclVar array(ARRAY_LENGTH(array_data),array_data);

      // - create new dictionary -
      UclVar dict = UclVar::Dict();

      // - fill dictionary with data -
      dict[1]       = "Number";
      dict["Hello"] = "String";
      dict[array]   = "Array";
      dict[UclVar::Dict(array)] = "Dict";

      // - print dictionary content -
      printf("dict: %s\n",dict.to_string().__str());

      // - access dictionary data -
      printf("%s\n",dict[1].__str());
      printf("%s\n",dict["Hello"].__str());
      printf("%s\n",dict[array].__str());
      printf("%s\n",dict[UclVar::Dict(array)].__str());

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

