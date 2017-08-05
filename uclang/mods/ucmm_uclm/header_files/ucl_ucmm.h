
#ifndef __UCL_UCMM_H
#define __UCL_UCMM_H

/*
 Based on revision 4 of svn/ucmm.
 */

@begin
include "script_parser.h"
@end

#include "ucmm.h"

using namespace ucmm;

/*
 * definition of structure device_info_s
 */

struct device_info_s
{
  location_s *manufacturer;
  location_s *model;
  location_s *revision;
  location_s *device_id;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure network_info_s
 */

struct network_info_s
{
  NetworkStatus status;
  NetworkType type;
  location_s *oper_name;
  location_s *oper_code;
  int signal;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure device_info_s
 */

inline void device_info_s::init()
{/*{{{*/
  manufacturer = nullptr;
  model = nullptr;
  revision = nullptr;
  device_id = nullptr;
}/*}}}*/

inline void device_info_s::clear(interpreter_thread_s &it)
{/*{{{*/

#define RELEASE_LOCATION_PTR(NAME) \
{/*{{{*/\
  if (NAME != nullptr)\
  {\
    it.release_location_ptr(NAME);\
  }\
}/*}}}*/

  RELEASE_LOCATION_PTR(manufacturer);
  RELEASE_LOCATION_PTR(model);
  RELEASE_LOCATION_PTR(revision);
  RELEASE_LOCATION_PTR(device_id);

  init();
}/*}}}*/

/*
 * inline methods of structure network_info_s
 */

inline void network_info_s::init()
{/*{{{*/
  oper_name = nullptr;
  oper_code = nullptr;
}/*}}}*/

inline void network_info_s::clear(interpreter_thread_s &it)
{/*{{{*/

#define RELEASE_LOCATION_PTR(NAME) \
{/*{{{*/\
  if (NAME != nullptr)\
  {\
    it.release_location_ptr(NAME);\
  }\
}/*}}}*/

  RELEASE_LOCATION_PTR(oper_name);
  RELEASE_LOCATION_PTR(oper_code);

  init();
}/*}}}*/

#endif

