
#ifndef __UCL_LLVM_H
#define __UCL_LLVM_H

@begin
include "llvm_parser.h"
@end

/*
 * definition of structure llvm_context_s
 */

struct llvm_context_s
{
  LLVMContext *context;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure llvm_module_s
 */

struct llvm_module_s
{
  Module *module;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of class llvm_c
 */
class llvm_c
{
  public:
  inline llvm_c();
  inline ~llvm_c();
};

/*
 * inline methods of structure llvm_context_s
 */

inline void llvm_context_s::init()
{/*{{{*/
  context = NULL;
}/*}}}*/

inline void llvm_context_s::clear(interpreter_thread_s &it)
{/*{{{*/
  
  // - release llvm context -
  if (context != NULL)
  {
    delete context;
  }

  init();
}/*}}}*/

/*
 * inline methods of structure llvm_module_s
 */

inline void llvm_module_s::init()
{/*{{{*/
  module = NULL;
}/*}}}*/

inline void llvm_module_s::clear(interpreter_thread_s &it)
{/*{{{*/
  init();
}/*}}}*/

/*
 * inline methods of class llvm_c
 */

inline llvm_c::llvm_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"llvm_init()\n"););

  // - initialize llvm native target -
  InitializeNativeTarget();
}/*}}}*/

inline llvm_c::~llvm_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"llvm_exit()\n"););
}/*}}}*/

#endif

