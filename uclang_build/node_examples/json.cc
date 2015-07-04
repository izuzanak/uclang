
#include "p.ucl_libnode.h"

int main(int argc,char **argv)
{/*{{{*/
  bool modules[c_uclvar_module_count];
  memset(modules,0,c_uclvar_module_count*sizeof(bool));

  modules[c_uclvar_module_base]       = true;
  modules[c_uclvar_module_node]       = true;
  modules[c_uclvar_module_containers] = true;
  modules[c_uclvar_module_json]       = true;

  g_UclNode.Initialize(modules);

  try {

    // - create persons array -
    UclVar persons = UclVar::Array();

    UclVar person = UclVar::Dict();
    person["name"] = "Avone";
    person["surname"] = "Barksdale";
    persons.push(person);

    person = UclVar::Dict();
    person["name"] = "Omar";
    person["surname"] = "Little";
    persons.push(person);

    person = UclVar::Dict();
    person["name"] = "Frank";
    person["surname"] = "Sobotka";
    persons.push(person);

    // - create object dictionary -
    UclVar data = UclVar::Dict();
    data["count"] = persons.length();
    data["persons"] = persons;

    // - create json string from data -
    UclVar json_str = UclVar::Json::create(data);
    printf("json_str: %s\n",json_str.__str());

    // - parse json string -
    UclVar json_data = UclVar::Json::parse(json_str);
    printf("json_data: %s\n",json_data.to_string().__str());

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

  return 0;
}/*}}}*/

