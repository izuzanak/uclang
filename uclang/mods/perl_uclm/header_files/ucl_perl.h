
#ifndef __UCL_PERL_H
#define __UCL_PERL_H

@begin
include "script_parser.h"
@end

#include <EXTERN.h>
#include <perl.h>

// C perl functions
// eval_pv(a,b) - evaluate individual perl string

// C call function - http://perldoc.perl.org/perlcall.html#THE-CALL_-FUNCTIONS
// C call flags - http://perldoc.perl.org/perlcall.html#G_ARRAY
// C call stack - http://perldoc.perl.org/perlcall.html#Returning-a-List-of-Values

//#undef SvREFCNT_inc
//#define SvREFCNT_inc(sv) (fprintf(stderr,"+"),S_SvREFCNT_inc(MUTABLE_SV(sv)))

//#undef SvREFCNT_inc_NN
//#define SvREFCNT_inc_NN(sv) (fprintf(stderr,"+"),S_SvREFCNT_inc_NN(MUTABLE_SV(sv)))

//#undef SvREFCNT_dec
//#define SvREFCNT_dec(sv) (fprintf(stderr,"-"),S_SvREFCNT_dec(aTHX_ MUTABLE_SV(sv)))

//#undef SvREFCNT_dec_NN
//#define SvREFCNT_dec_NN(sv) (fprintf(stderr,"-"),S_SvREFCNT_dec_NN(aTHX_ MUTABLE_SV(sv)))

/*
 * constants and definitions
 */

extern unsigned c_bi_class_perl_value;
extern unsigned c_bi_class_perl_reference;
extern unsigned c_rm_class_dict;

/*
 * definition of structure perl_interpreter_s
 */

struct perl_interpreter_s
{
  PerlInterpreter *interpreter;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure perl_value_s
 */

struct perl_value_s
{
  location_s *pi_loc;
  SV *sv;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure perl_reference_s
 */

struct perl_reference_s
{
  location_s *pi_loc;
  SV *sv;
  v_data_type v_key_ptr;

  inline void init();
  inline void clear(interpreter_thread_s &it);

  inline SV *get(PerlInterpreter *my_perl);
  inline bool set(PerlInterpreter *my_perl,SV *sv_value);
};

/*
 * definition of class perl_c
 */
class perl_c
{
  public:
  inline perl_c();
  inline ~perl_c();

  static SV *create_perl_sv(interpreter_thread_s &it,PerlInterpreter *my_perl,location_s *location_ptr);
  static location_s *perl_sv_value(interpreter_thread_s &it,PerlInterpreter *my_perl,SV *sv,uli source_pos);
};

/*
 * inline methods of structure perl_interpreter_s
 */

inline void perl_interpreter_s::init()
{/*{{{*/
  interpreter = NULL;
}/*}}}*/

inline void perl_interpreter_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (interpreter != NULL)
  {
    // - set perl context -
    PerlInterpreter *my_perl = interpreter;
    PERL_SET_CONTEXT(interpreter);

    // - destruct perl interpreter -
    PL_perl_destruct_level = 1;
    perl_destruct(interpreter);
    perl_free(interpreter);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure perl_value_s
 */

inline void perl_value_s::init()
{/*{{{*/
  pi_loc = NULL;
  sv = NULL;
}/*}}}*/

inline void perl_value_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release value -
  if (sv != NULL)
  {
    perl_interpreter_s *pi_ptr = (perl_interpreter_s *)pi_loc->v_data_ptr;

    // - set perl context -
    PerlInterpreter *my_perl = pi_ptr->interpreter;
    PERL_SET_CONTEXT(pi_ptr->interpreter);

    // - decrement reference counter -
    SvREFCNT_dec(sv);
  }

  // - release perl interpreter location -
  if (pi_loc != NULL)
  {
    it.release_location_ptr(pi_loc);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure perl_reference_s
 */

inline void perl_reference_s::init()
{/*{{{*/
  pi_loc = NULL;
  sv = NULL;
}/*}}}*/

inline void perl_reference_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release value -
  if (sv != NULL)
  {
    perl_interpreter_s *pi_ptr = (perl_interpreter_s *)pi_loc->v_data_ptr;

    // - set perl context -
    PerlInterpreter *my_perl = pi_ptr->interpreter;
    PERL_SET_CONTEXT(pi_ptr->interpreter);

    switch (SvTYPE(sv))
    {
    case SVt_PVAV:
      break;
    case SVt_PVHV:

      SvREFCNT_dec((SV *)v_key_ptr);
      break;
    default:
      cassert(0);
    }

    // - decrement reference counter -
    SvREFCNT_dec(sv);
  }

  // - release perl interpreter location -
  if (pi_loc != NULL)
  {
    it.release_location_ptr(pi_loc);
  }

  init();
}/*}}}*/

inline SV *perl_reference_s::get(PerlInterpreter *my_perl)
{/*{{{*/
  switch (SvTYPE(sv))
  {
  case SVt_PVAV:
    {/*{{{*/
      SV **sv_ptr = av_fetch((AV *)sv,(long long int)v_key_ptr,0);

      // - ERROR -
      if (sv_ptr == NULL)
      {
        return NULL;
      }

      SvREFCNT_inc(*sv_ptr);
      return *sv_ptr;
    }/*}}}*/
  case SVt_PVHV:
    {/*{{{*/
      HE *he = hv_fetch_ent((HV *)sv,(SV *)v_key_ptr,1,0);

      if (he == NULL)
      {
        return NULL;
      }

      SV *sv = HeVAL(he);
      SvREFCNT_inc(sv);

      return sv;
    }/*}}}*/
  default:
    cassert(0);
  }
}/*}}}*/

inline bool perl_reference_s::set(PerlInterpreter *my_perl,SV *sv_value)
{/*{{{*/
  switch (SvTYPE(sv))
  {
  case SVt_PVAV:
    {/*{{{*/
      SvREFCNT_inc(sv_value);
      SV **sv_res = av_store((AV *)sv,(long long int)v_key_ptr,sv_value);

      // - ERROR -
      if (sv_res == NULL)
      {
        SvREFCNT_dec(sv_value);
        return false;
      }

      return true;
    }/*}}}*/
  case SVt_PVHV:
    {/*{{{*/
      SvREFCNT_inc(sv_value);
      HE *he_res = hv_store_ent((HV *)sv,(SV *)v_key_ptr,sv_value,0);

      // - ERROR -
      if (he_res == NULL)
      {
        SvREFCNT_dec(sv_value);
        return false;
      }

      return true;
    }/*}}}*/
  default:
    cassert(0);
  }
}/*}}}*/

/*
 * inline methods of class perl_c
 */

inline perl_c::perl_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"perl_init()\n"););

  PERL_SYS_INIT3(0,NULL,NULL);
}/*}}}*/

inline perl_c::~perl_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"perl_exit()\n"););

  PERL_SYS_TERM();
}/*}}}*/

#endif

