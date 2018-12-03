
@begin
include "ucl_string.h"
@end

/*
 * constants and definitions
 */

// - string terminating character -
const char c_string_terminating_char = '\0';

/*
 * methods of structure string_s
 */

extern "C" {
void string_s_set(string_s *a_this,unsigned a_length,const char *a_data)
{/*{{{*/
  a_this->set(a_length,a_data);
}/*}}}*/
}

void string_s::mult_char_ptr(unsigned a_length,const char *a_data,unsigned a_mult)
{/*{{{*/
  if (a_length == 0 || a_mult == 0)
  {
    clear();
    return;
  }

  create(a_length*a_mult);

  char *s_ptr = data;
  do
  {
    memcpy(s_ptr,a_data,a_length*sizeof(char));
  }
  while(s_ptr += a_length, --a_mult > 0);

}/*}}}*/

int string_s::utf8_to_utf32(char *a_src,unsigned *a_trg,unsigned a_size)
{/*{{{*/
  if (a_size == 0)
  {
    return 0;
  }

  unsigned char *s_ptr = (unsigned char *)a_src;
  unsigned char *s_ptr_end = s_ptr + a_size;
  unsigned *t_ptr = a_trg;
  do {

    if (*s_ptr <= 127)
    {
      *t_ptr = (unsigned)*s_ptr++;
    }
    else
    {
      unsigned char value = *s_ptr++ << 2;
      unsigned count = 2;
      unsigned code = *s_ptr++ & 0x3f;

      while (value & 0x80)
      {
        if ((*s_ptr & 0xc0) != 0x80)
        {
          return -1;
        }

        code |= (code << 6) | (*s_ptr++ & 0x3f);
        value <<= 1;
        count++;
      }

      *t_ptr = code | (value << (5*count - 6));
    }

  } while(++t_ptr,s_ptr < s_ptr_end);

  return t_ptr - a_trg;
}/*}}}*/

unsigned string_s::utf32_to_utf8(unsigned *a_src,char *a_trg,unsigned a_size)
{/*{{{*/
  if (a_size == 0)
  {
    return 0;
  }

  unsigned *s_ptr = a_src;
  unsigned *s_ptr_end = s_ptr + a_size;
  unsigned char *t_ptr = (unsigned char *)a_trg;
  do {
    register unsigned value = *s_ptr;

    if (value <= 0x7f)
    {
      *t_ptr++ = value;
      continue;
    }

    if (value <= 0x7ff)
    {
      t_ptr[0] = 0xc0 | value >> 6;
      t_ptr[1] = 0x80 | (value & 0x3f);
      t_ptr += 2;
      continue;
    }

    if (value <= 0xffff)
    {
      t_ptr[0] = 0xe0 |   value >> 12;
      t_ptr[1] = 0x80 | ((value >>  6) & 0x3f);
      t_ptr[2] = 0x80 |  (value        & 0x3f);
      t_ptr += 3;
      continue;
    }

    if (value <= 0x1fffff)
    {
      t_ptr[0] = 0xf0 |   value >> 18;
      t_ptr[1] = 0x80 | ((value >> 12) & 0x3f);
      t_ptr[2] = 0x80 | ((value >>  6) & 0x3f);
      t_ptr[3] = 0x80 |  (value        & 0x3f);
      t_ptr += 4;
      continue;
    }

    if (value <= 0x3ffffff)
    {
      t_ptr[0] = 0xf8 |   value >> 24;
      t_ptr[1] = 0x80 | ((value >> 18) & 0x3f);
      t_ptr[2] = 0x80 | ((value >> 12) & 0x3f);
      t_ptr[3] = 0x80 | ((value >>  6) & 0x3f);
      t_ptr[4] = 0x80 |  (value        & 0x3f);
      t_ptr += 5;
      continue;
    }

    if (value <= 0x7fffffff)
    {
      t_ptr[0] = 0xfc |   value >> 30;
      t_ptr[1] = 0x80 | ((value >> 24) & 0x3f);
      t_ptr[2] = 0x80 | ((value >> 18) & 0x3f);
      t_ptr[3] = 0x80 | ((value >> 12) & 0x3f);
      t_ptr[4] = 0x80 | ((value >>  6) & 0x3f);
      t_ptr[5] = 0x80 |  (value        & 0x3f);
      t_ptr += 6;
      continue;
    }

  } while(++s_ptr < s_ptr_end);

  return t_ptr - (unsigned char *)a_trg;
}/*}}}*/

void string_s::setf(const char *a_format,...)
{/*{{{*/
  clear();

  const size_t init_size = 128;
  va_list ap;

  data = (char *)cmalloc(init_size*sizeof(char));

  va_start(ap,a_format);
  int length = vsnprintf(data,init_size,a_format,ap);
  va_end(ap);

  size = length + 1;

  if (size > init_size)
  {
    cfree(data);
    data = (char *)cmalloc(size*sizeof(char));

    va_start(ap,a_format);
    vsnprintf(data,size,a_format,ap);
    va_end(ap);
  }
}/*}}}*/

unsigned string_s::get_idx(unsigned a_idx,unsigned a_length,const char *a_data)
{/*{{{*/
  if (a_idx >= (size - 1) || a_length == 0 || a_length >= (size - a_idx))
  {
    return c_idx_not_exist;
  }

  // - single character search -
  if (a_length == 1)
  {
    char *s_ptr = data + a_idx;
    char *s_ptr_end = data + (size - a_length);
    do {
      if (*s_ptr == *a_data)
      {
        return s_ptr - data;
      }
    } while(++s_ptr < s_ptr_end);
  }

  // - multiple characters search -
  else
  {
    // - compute search sum -
    unsigned search_sum = 0;
    const unsigned char *ss_ptr = (const unsigned char *)a_data;
    const unsigned char *ss_ptr_end = ss_ptr + a_length;
    do {
      search_sum += *ss_ptr;
    } while(++ss_ptr < ss_ptr_end);

    // - compute text sum -
    unsigned text_sum = 0;
    unsigned char *s_ptr = (unsigned char *)data + a_idx;
    unsigned char *s_ptr_end = s_ptr + a_length;
    do {
      text_sum += *s_ptr;
    } while(++s_ptr < s_ptr_end);

    s_ptr = (unsigned char *)data + a_idx;
    s_ptr_end = (unsigned char *)data + (size - a_length);
    do {

      // - if search sum was found -
      if (text_sum == search_sum)
      {
        if (memcmp(a_data,s_ptr,a_length) == 0)
        {
          return s_ptr - (unsigned char *)data;
        }
      }

      // - update text sum -
      text_sum -= *s_ptr;
      text_sum += s_ptr[a_length];

    } while(++s_ptr < s_ptr_end);
  }

  return c_idx_not_exist;
}/*}}}*/

unsigned string_s::get_print_size_between(unsigned f_idx,unsigned s_idx)
{/*{{{*/
  debug_assert(f_idx < size && s_idx < size);

  if (f_idx >= s_idx)
  {
    return 0;
  }

  unsigned char_cnt = s_idx - f_idx;
  unsigned utf32_data[char_cnt];

  int utf32_cnt = utf8_to_utf32(data + f_idx,utf32_data,char_cnt);
  if (utf32_cnt < 0)
  {
    return 0;
  }

  unsigned *c_ptr = utf32_data;
  unsigned *c_ptr_end = c_ptr + utf32_cnt;
  unsigned print_size = 0;

  do
  {
    if (*c_ptr == '\t')
    {
      print_size += c_tabulator_size;
    }
    else
    {
      print_size++;
    }
  }
  while(++c_ptr < c_ptr_end);

  return print_size;
}/*}}}*/

unsigned string_s::get_character_line(unsigned c_idx)
{/*{{{*/
  if (size <= c_idx)
  {
    return 0;
  }

  char *c_ptr = data;
  char *c_ptr_end = c_ptr + c_idx;
  unsigned line_cnt = 1;

  do
  {
    if (*c_ptr == '\n')
    {
      line_cnt++;
    }
  }
  while(++c_ptr < c_ptr_end);

  return line_cnt;
}/*}}}*/

unsigned string_s::get_character_line_begin(unsigned c_idx)
{/*{{{*/
  char *s_ptr = data + c_idx;

  do
  {
    if (*s_ptr == '\n')
    {
      break;
    }
  }
  while(--s_ptr >= data);

  return (s_ptr - data) + 1;
}/*}}}*/

unsigned string_s::get_character_line_end(unsigned c_idx)
{/*{{{*/
  char *e_ptr = data + c_idx;
  char *e_ptr_end = data + size - 1;

  while(e_ptr < e_ptr_end)
  {
    if (*e_ptr == '\n')
    {
      break;
    }

    ++e_ptr;
  }

  return e_ptr - data;
}/*}}}*/

