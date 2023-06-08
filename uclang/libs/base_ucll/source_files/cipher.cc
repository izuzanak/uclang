
@begin
include "cipher.h"
@end

/*
 * constants and definitions
 */

unsigned char c_cm_value[] = {0xb2, 0x7f, 0x02, 0x98};
unsigned char c_ck_value[] = {
  0x67, 0x30, 0xf3, 0xa4,
  0xb7, 0xbd, 0x32, 0x70,
  0x91, 0x56, 0x15, 0x58,
  0xa1, 0xea, 0xc8, 0x3a,
  0xcc, 0x54, 0xe5, 0x30,
  0xed, 0x3f, 0xf5, 0xd5,
  0x79, 0x2b, 0x27, 0x01,
  0xf7, 0xd4, 0x65, 0x86,
  0x13, 0xb8, 0xe2, 0x57,
  0x45, 0x98, 0x4a, 0x86,
};

unsigned c_cm_length = sizeof(c_cm_value);
unsigned c_ck_length = sizeof(c_ck_value);

/*
 * methods of structure cipher_s
 */

void cipher_s::create(unsigned a_length,const char *a_data)
{/*{{{*/
  cassert(a_length > 0);

  unsigned idx = 0;
  do {
    state[idx] = idx;
  } while(++idx < 256);

  unsigned char *key = (unsigned char *)a_data;

  j = 0;
  i = 0;
  do {
    j = j + state[i] + key[i % a_length];

    unsigned char state_j = state[j];
    state[j] = state[i];
    state[i] = state_j;

  } while(++i != 0);

  i = 0;
  j = 0;
}/*}}}*/

void cipher_s::process(unsigned a_length,char *a_data)
{/*{{{*/
  if (a_length == 0)
  {
    return;
  }

  unsigned char *ptr = (unsigned char *)a_data;
  unsigned char *ptr_end = ptr + a_length;
  do {
    j += state[++i];

    unsigned char state_j = state[j];
    unsigned char state_i = state[i];

    state[j] = state_i;
    state[i] = state_j;

    unsigned char xor_idx = state_i + state_j;

    *ptr ^= state[xor_idx];

  } while(++ptr < ptr_end);
}/*}}}*/

