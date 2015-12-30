

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

/*
 * definitions of global functions
 */

unsigned sf_terminal_recognize(char **a_ptr);

#endif

