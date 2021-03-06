
#include "p.ucl_libnode.h"

int main(int argc,char **argv)
{/*{{{*/

  // - select modules to import -
  const char *modules[] = {
    "containers","json",NULL
  };

  // - initialize uclang node -
  if (g_UclNode.Initialize(modules))
  {
    UCL_NODE_TRY

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

    UCL_NODE_CATCH

    g_UclNode.Clear();
  }

  return 0;
}/*}}}*/

