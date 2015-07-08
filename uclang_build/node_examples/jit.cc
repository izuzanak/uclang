
#include "p.ucl_libnode.h"

int main(int argc,char **argv)
{/*{{{*/
  bool modules[c_uclvar_module_count];
  memset(modules,0,c_uclvar_module_count*sizeof(bool));

  modules[c_uclvar_module_base] = true;
  modules[c_uclvar_module_node] = true;
  modules[c_uclvar_module_jit]  = true;

  g_UclNode.Initialize(modules);

  try {

// - construct array from list -
#define GET_ARRAY(NAME,LIST) \
  UclVar NAME ## _list[] = LIST;\
  UclVar NAME(ARRAY_LENGTH(NAME ## _list),NAME ## _list);\

    // - create jit context -
    UclVar jit_ctx = UclVar::JitContext();

    // - create factorial function -
    UclVar fact_fun = jit_ctx.create_fun(
"i64 fact(i64 a_num)\n"
"{\n"
"  i64 result = 1;\n"
"  while (a_num > 1) result *= a_num--;\n"
"  return result;\n"
"}\n"
    );

    {
      GET_ARRAY(args,{(long long int)10});
      printf("fact(10): %s\n",fact_fun.call(args).to_string().__str());
    }

    // - create jit function -
    UclVar jit_fun = jit_ctx.create_fun(
"i32 test(u64 a_ptr,i64 a_cnt)\n"
"{\n"
"  i32 *ptr = (i32 *)a_ptr;\n"
"  i32 *ptr_end = ptr + a_cnt;\n"
"\n"
"  i32 idx = 1;\n"
"  if (ptr < ptr_end)\n"
"  {\n"
"    do {\n"
"      *ptr = fact(idx++);\n"
"    } while(++ptr < ptr_end);\n"
"  }\n"
"\n"
"  return 0;\n"
"}\n"
    );

    int num_cnt = 10;
    int nums[num_cnt];

    memset(nums,0,num_cnt*sizeof(int));
    for (int idx=0;idx<num_cnt;idx++) printf("%d, ",nums[idx]); printf("\n");

    {
      GET_ARRAY(args,{(long long int)nums MP_COMMA num_cnt});
      UclVar res = jit_fun.call(args);
    }

    for (int idx=0;idx<num_cnt;idx++) printf("%d, ",nums[idx]); printf("\n");

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

