

#ifndef __UCL_BASE_H
#define __UCL_BASE_H

@begin
include "script_parser.h"
@end

#if defined(_GNU_SOURCE) && !defined(ANDROID)
#define ENABLE_THREAD_TRY_JOIN
#endif

/*
 * basic definitions and constants
 */

#define IT_INTERPRETER ((interpreter_s *)it.interpreter_ptr)

const unsigned max_number_string_length = 20;

// - string format terminals -
enum
{
  SF_TERM_MINUS = 0,
  SF_TERM_FLAGS,
  SF_TERM_NUMBER,
  SF_TERM_PARAMETER,
  SF_TERM_DOT,
  SF_TERM_PERCENT,
  SF_TERM_CHARACTER,
  SF_TERM_INTEGER,
  SF_TERM_FLOAT,
  SF_TERM_STRING,
};

// - range type identifiers -
enum
{
  c_range_type_ascending = 0,
  c_range_type_descending,
};

/*
 * definitions of global functions
 */

unsigned sf_terminal_recognize(char **a_ptr);

/*
 * definition of structure range_s
 */

struct range_s
{
  unsigned type;
  location_s *start_location;
  location_s *end_location;
  location_s *step_location;
  location_s *actual_location;

  uli tmp_code[9];

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure range_s
 */

inline void range_s::init()
{/*{{{*/
  start_location = NULL;
  end_location = NULL;
  step_location = NULL;
  actual_location = NULL;
}/*}}}*/

inline void range_s::clear(interpreter_thread_s &it)
{/*{{{*/

#define RELEASE_LOCATION_PTR(LOCATION_PTR) \
{/*{{{*/\
  if (LOCATION_PTR != NULL)\
  {\
    it.release_location_ptr(LOCATION_PTR);\
  }\
}/*}}}*/

  RELEASE_LOCATION_PTR(start_location);
  RELEASE_LOCATION_PTR(end_location);
  RELEASE_LOCATION_PTR(step_location);
  RELEASE_LOCATION_PTR(actual_location);

  init();
}/*}}}*/

#endif

