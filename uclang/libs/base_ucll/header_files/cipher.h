
#ifndef __CIPHER_H
#define __CIPHER_H

@begin
include "basic.h"
@end

/*
 * constants and definitions
 */
libbase_ucll_EXPORT extern unsigned char c_cm_value[4];
libbase_ucll_EXPORT extern unsigned char c_ck_value[40];

libbase_ucll_EXPORT extern unsigned c_cm_length;
libbase_ucll_EXPORT extern unsigned c_ck_length;

/*
 * definition of structure cipher_s
 */

@begin
define cipher_s dynamic
@end

struct cipher_s
{
  unsigned char i;
  unsigned char j;
  unsigned char state[256];

  /*!
   * \brief initialization of cipher variables
   */
  inline void init() {};

  /*!
   * \brief release of cipher variables
   */
  inline void clear() {};

  /*!
   * \brief flush all variables of cipher
   */
  inline void flush_all() {}

  /*!
   * \brief swap cipher variables with another cipher
   * \param second - reference to another cipher
   */
  inline void swap(cipher_s &second)
  {
    cassert(0);
  }

  /*!
   * \brief set cipher to value of another cipher
   * \param src - reference to another cipher
   * \return reference to this cipher
   */
  inline cipher_s &operator=(cipher_s &src)
  {
    cassert(0);
    return *this;
  }

  /*!
   * \brief compare value with another cipher
   * \param second - reference to another cipher
   * \return result of comparison
   */
  inline bool operator==(cipher_s &second)
  {
    cassert(0);
    return false;
  }

  /*!
   * \brief create new cipher according to given key
   * \param a_length - length of key
   * \param a_data - pointer to data of key
   */
  libbase_ucll_EXPORT void create(unsigned a_length,const char *a_data);

  /*!
   * \brief process encipher given message according to cipher state
   * \param a_length - length of message to encipher
   * \param a_data - pointer to data of message
   */
  libbase_ucll_EXPORT void process(unsigned a_length,char *a_data);

  /*!
   * \brief test if given message is cipher
   * \param a_length - length of message to be tested
   * \param a_data - pointer to data of message
   * \return true if message represents cipher
   */
  inline bool is_cipher(unsigned a_length,char *a_data);
};


/*
 * inline methods of structure cipher_s
 */

inline bool cipher_s::is_cipher(unsigned a_length,char *a_data)
{/*{{{*/
  if (a_length < c_cm_length)
  {
    return false;
  }

  return memcmp(a_data,c_cm_value,c_cm_length) == 0;
}/*}}}*/

#endif

