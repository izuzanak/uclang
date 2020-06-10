
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

#define UCL_FOR_LOOP(ITEM,ITER,CODE) \
{/*{{{*/\
  interpreter_thread_s &it = *UclVar::__it_ptr();\
\
  UclVar __iter_val(ITER);\
  location_s *__iter_loc = it.get_location_value(__iter_val.__loc());\
\
  switch (it.get_iterable_type(__iter_loc))\
  {\
  case c_iter_first_idx_next_idx_item:\
    {/*{{{*/\
      unsigned __index;\
\
      /* - retrieve first index - */\
      BIC_CALL_FIRST_IDX(it,__iter_loc,__index,0,throw std::string("Exception"));\
\
      /* - while index is not blank - */\
      while (__index != c_idx_not_exist)\
      {\
        /* - retrieve item - */\
        location_s *trg_location;\
        BIC_CALL_ITEM(it,__iter_loc,__index,trg_location,0,throw std::string("Exception"));\
\
        UclVar ITEM(&trg_location);\
        it.release_location_ptr(trg_location);\
\
        CODE;\
\
        /* - retrieve next index - */\
        BIC_CALL_NEXT_IDX(it,__iter_loc,__index,__index,0,throw std::string("Exception"));\
      }\
    }/*}}}*/\
    break;\
  case c_iter_next_item:\
    {/*{{{*/\
      do {\
\
        /* - retrieve item - */\
        location_s *trg_location;\
        BIC_CALL_NEXT_ITEM(it,__iter_loc,trg_location,0,throw std::string("Exception"));\
\
        if (it.get_location_value(trg_location)->v_type == c_bi_class_blank)\
        {\
          it.release_location_ptr(trg_location);\
          break;\
        }\
\
        UclVar ITEM(&trg_location);\
        it.release_location_ptr(trg_location);\
\
        CODE;\
\
      } while(true);\
    }/*}}}*/\
    break;\
\
  /* - ERROR - */\
  default:\
    throw std::string("Not iterable object error");\
  }\
}/*}}}*/

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

  libnode_ucll_EXPORT bool Initialize(const char **a_modules);
  libnode_ucll_EXPORT bool Clear();

  inline UclVar RetrieveException();
  inline void PrintExceptionMessage();
};

// - UclNode global init object -
libnode_ucll_EXPORT extern UclNode g_UclNode;

/*
 * inline methods of class UclNode
 */

inline UclNode::UclNode()
{/*{{{*/
  parser.init();
  interpreter.init();
  thread = nullptr;
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

