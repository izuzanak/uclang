
#ifndef __UCL_LIBNODE_H
#define __UCL_LIBNODE_H

@begin
include "ucl_var.h"
@end

/*
 * definition of class UclNode
 */

class UclNode
{
  private:
  script_parser_s parser;
  interpreter_s interpreter;
  interpreter_thread_s *thread;

  public:
  inline UclNode();
  inline ~UclNode();

  bool Initialize(bool *a_modules);
  bool Clear();

  inline void PrintExceptionMessage();
};

// - UclNode global init object -
extern UclNode g_UclNode;

/*
 * inline methods of class UclNode
 */

inline UclNode::UclNode()
{/*{{{*/
  parser.init();
  interpreter.init();
  thread = NULL;
}/*}}}*/

inline UclNode::~UclNode()
{/*{{{*/
  parser.clear();
  interpreter.clear();
}/*}}}*/

inline void UclNode::PrintExceptionMessage()
{/*{{{*/
  exception_s *exception_ptr = (exception_s *)((location_s *)thread->exception_location)->v_data_ptr;
  interpreter.print_exception_message(*exception_ptr);
}/*}}}*/

#endif

