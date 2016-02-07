
#ifndef __UCL_LIBNODE_H
#define __UCL_LIBNODE_H

@begin
include "ucl_var.h"
@end

/*
 * constants and definitions
 */

#define UCL_NODE_TRY \
/*{{{*/\
try {
/*}}}*/

#define UCL_NODE_CATCH \
/*{{{*/\
}\
catch (std::string reason)\
{\
  if (reason == "Exception")\
  {\
    g_UclNode.PrintExceptionMessage();\
  }\
  else\
  {\
    fprintf(stderr," ---------------------------------------- \n");\
    fprintf(stderr,"Error: %s\n",reason.data());\
    fprintf(stderr," ---------------------------------------- \n");\
  }\
}
/*}}}*/

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

  bool Initialize(const char **a_modules);
  bool Clear();

  inline UclVar RetrieveException();
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

inline UclVar UclNode::RetrieveException()
{/*{{{*/
  location_s *exception_location = (location_s *)thread->exception_location;

  UclVar exception(&exception_location);
  thread->release_location_ptr(exception_location);

  // - set exception_location to blank_location -
  ((location_s *)thread->blank_location)->v_reference_cnt.atomic_inc();
  thread->exception_location = thread->blank_location;

  return exception;
}/*}}}*/

inline void UclNode::PrintExceptionMessage()
{/*{{{*/
  exception_s *exception_ptr = (exception_s *)((location_s *)thread->exception_location)->v_data_ptr;
  interpreter.print_exception_message(*exception_ptr);
  thread->release_location_ptr((location_s *)thread->exception_location);

  // - set exception_location to blank_location -
  ((location_s *)thread->blank_location)->v_reference_cnt.atomic_inc();
  thread->exception_location = thread->blank_location;
}/*}}}*/

#endif

