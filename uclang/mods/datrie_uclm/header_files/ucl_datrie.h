
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
 * definition of structure datrie_iterator_s
 */

struct datrie_iterator_s
{
  location_s *datrie_loc;
  TrieState *state_ptr;
  TrieIterator *iter_ptr;

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

/*
 * inline methods of structure datrie_iterator_s
 */

inline void datrie_iterator_s::init()
{/*{{{*/
  datrie_loc = nullptr;
  state_ptr = nullptr;
  iter_ptr = nullptr;
}/*}}}*/

inline void datrie_iterator_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (iter_ptr != nullptr)
  {
    trie_iterator_free(iter_ptr);
  }

  if (state_ptr != nullptr)
  {
    trie_state_free(state_ptr);
  }

  if (datrie_loc != nullptr)
  {
    it.release_location_ptr(datrie_loc);
  }

  init();
}/*}}}*/

#endif

