
#ifndef __UCL_DATRIE_H
#define __UCL_DATRIE_H

@begin
include "script_parser.h"
@end

#include <datrie/trie.h>

/*
 * definition of structure datrie_s
 */

struct datrie_s
{
  Trie *trie_ptr;
  location_s *alpha_map_loc;
  pointer_list_s data_list;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure datrie_s
 */

inline void datrie_s::init()
{/*{{{*/
  trie_ptr = nullptr;
  alpha_map_loc = nullptr;
  data_list.init();
}/*}}}*/

inline void datrie_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (trie_ptr != nullptr)
  {
    trie_free(trie_ptr);
  }

  if (alpha_map_loc != nullptr)
  {
    it.release_location_ptr(alpha_map_loc);
  }

  if (data_list.first_idx != c_idx_not_exist)
  {
    unsigned dl_idx = data_list.first_idx;
    do {

      // - release data location -
      it.release_location_ptr((location_s *)data_list[dl_idx]);

      dl_idx = data_list.next_idx(dl_idx);
    } while(dl_idx != c_idx_not_exist);
  }

  data_list.clear();

  init();
}/*}}}*/

#endif

