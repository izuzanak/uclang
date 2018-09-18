
@begin
include "ucl_uctrdp.h"
@end

/*
 * basic definitions and constants
 */

const unsigned short c_two_bytes = 0xff00;
const bool c_little_endian = ((unsigned char *)&c_two_bytes)[1] == 0xff;

/*
 * methods of generated structures
 */

// -- trdp_var_descr_s --
@begin
methods trdp_var_descr_s
@end

// -- trdp_var_descrs_s --
@begin
methods trdp_var_descrs_s
@end

/*
 * methods of structure trdp_pd_page_s
 */

bool trdp_pd_page_s::process_page_description(
    interpreter_thread_s &it,pass_s &pass,pointer_array_s *array_ptr,unsigned &vd_count,unsigned &last_vd_idx)
{/*{{{*/

  // - reset variable descriptor count -
  vd_count = 0;

  // - ERROR -
  if (array_ptr->used == 0)
  {
    return false;
  }

  pointer *p_ptr = array_ptr->data;
  pointer *p_ptr_end = p_ptr + array_ptr->used;
  do {

    // - increase variable descriptor count -
    ++vd_count;

    // - set last variable descriptor index -
    last_vd_idx = var_descrs.used;

    // - ERROR -
    if (p_ptr_end - p_ptr < 2)
    {
      return false;
    }

    location_s *name_location = it.get_location_value(*p_ptr++);

    // - ERROR -
    long long int type;
    if (name_location->v_type != c_bi_class_string ||
        !it.retrieve_integer(it.get_location_value(*p_ptr++),type))
    {
      return false;
    }

    // - align to bytes -
    if (type != TBOOL)
    {
      pass.address += !!pass.bit_pos;
      pass.bit_pos = 0;
    }

    switch (type)
    {
    case ANY_ARRAY:
      {/*{{{*/

        // - ERROR -
        if (p_ptr_end - p_ptr < 2)
        {
          return false;
        }

        // - ERROR -
        long long int count;
        if (!it.retrieve_integer(it.get_location_value(*p_ptr++),count) || count <= 0)
        {
          return false;
        }

        location_s *array_location = it.get_location_value(*p_ptr++);

        // - ERRRO -
        if (array_location->v_type != c_bi_class_array)
        {
          return false;
        }

        unsigned var_descr_idx = var_descrs.used;

        // - create variable descriptor -
        var_descrs.push_blank();
        trdp_var_descr_s *vd_ptr = var_descrs.data + var_descr_idx;

        // - fill variable descriptor -
        name_location->v_reference_cnt.atomic_inc();
        vd_ptr->name_location = name_location;
        vd_ptr->type = type;
        vd_ptr->address = pass.address;
        vd_ptr->count = count;

        // - ERROR -
        unsigned array_vd_count;
        unsigned array_last_vd_idx;
        if (!process_page_description(
              it,pass,(pointer_array_s *)array_location->v_data_ptr,array_vd_count,array_last_vd_idx))
        {
          return false;
        }

        // - ERROR -
        if (array_vd_count != 1)
        {
          return false;
        }

        vd_ptr = var_descrs.data + var_descr_idx;
        trdp_var_descr_s *item_vd_ptr = var_descrs.data + var_descr_idx + 1;

        unsigned length = item_vd_ptr->size*count;

        if (item_vd_ptr->type == TBOOL)
        {
          pass.address += (pass.bit_pos += (length - item_vd_ptr->size)) >> 3;
          pass.bit_pos &= 0x07;

          length = (length >> 3) + !!(length & 0x07);
        }
        else
        {
          pass.address += length - item_vd_ptr->size;
        }

        vd_ptr->length = length;
        vd_ptr->size = length;
      }/*}}}*/
      break;
    case ANY_STRUCTURED:
      {/*{{{*/

        // - ERROR -
        if (p_ptr >= p_ptr_end)
        {
          return false;
        }

        location_s *array_location = it.get_location_value(*p_ptr++);

        // - ERRRO -
        if (array_location->v_type != c_bi_class_array)
        {
          return false;
        }

        unsigned var_descr_idx = var_descrs.used;

        // - create variable descriptor -
        var_descrs.push_blank();
        trdp_var_descr_s *vd_ptr = var_descrs.data + var_descr_idx;

        // - fill variable descriptor -
        name_location->v_reference_cnt.atomic_inc();
        vd_ptr->name_location = name_location;
        vd_ptr->type = type;
        vd_ptr->address = pass.address;

        // - ERROR -
        unsigned struct_vd_count;
        unsigned struct_last_vd_idx;
        if (!process_page_description(
              it,pass,(pointer_array_s *)array_location->v_data_ptr,struct_vd_count,struct_last_vd_idx))
        {
          return false;
        }

        // - ERROR -
        if (struct_vd_count <= 0)
        {
          return false;
        }

        vd_ptr = var_descrs.data + var_descr_idx;
        trdp_var_descr_s *last_vd_ptr = var_descrs.data + struct_last_vd_idx;

        unsigned end_address = last_vd_ptr->address + last_vd_ptr->size;

        if (last_vd_ptr->type == TBOOL)
        {
          end_address = (end_address >> 3) + !!(end_address & 0x07);
        }

        vd_ptr->length = end_address - vd_ptr->address;
        vd_ptr->size = vd_ptr->length;
        vd_ptr->count = struct_vd_count;
      }/*}}}*/
      break;
    default:
      {/*{{{*/

        // - ERROR -
        if (p_ptr >= p_ptr_end)
        {
          return false;
        }

        // - ERROR -
        long long int count;
        if (!it.retrieve_integer(it.get_location_value(*p_ptr++),count) || count <= 0)
        {
          return false;
        }

        // - increase variable count -
        var_count += count;

        // - create variable descriptor -
        var_descrs.push_blank();
        trdp_var_descr_s &var_descr = var_descrs.last();

        // - fill variable descriptor -
        name_location->v_reference_cnt.atomic_inc();
        var_descr.name_location = name_location;
        var_descr.type = type;
        var_descr.count = count;

        switch (type)
        {
        case TBOOL:
          {/*{{{*/
            var_descr.address = (pass.address << 3) + pass.bit_pos;
            var_descr.length = 1;
            var_descr.size = count;

            pass.address += (pass.bit_pos += count) >> 3;
            pass.bit_pos &= 0x07;
          }/*}}}*/
          break;
        case TBYTE:
        case TWORD:
        case TDWORD:
        case TLWORD:
        case TUSINT:
        case TINT:
        case TUINT:
        case TUDINT:
        case TREAL:
        case TLREAL:
        case TSTRINGB:
        case TSTRING:
          {/*{{{*/
            var_descr.address = pass.address;

            switch (type)
            {
              case TBYTE:
              case TUSINT:
                var_descr.length = 1;
                break;
              case TWORD:
              case TINT:
              case TUINT:
                var_descr.length = 2;
                break;
              case TDWORD:
              case TUDINT:
              case TREAL:
                var_descr.length = 4;
                break;
              case TLWORD:
              case TLREAL:
                var_descr.length = 8;
                break;
              case TSTRINGB:
              case TSTRING:
                {/*{{{*/

                  // - ERROR -
                  if (p_ptr >= p_ptr_end)
                  {
                    return false;
                  }

                  // - ERROR -
                  long long int length;
                  if (!it.retrieve_integer(it.get_location_value(*p_ptr++),length) ||
                      length <= 0 || length >= 256)
                  {
                    return false;
                  }

                  var_descr.length = length;
                }/*}}}*/
                break;
            }

            var_descr.size = var_descr.length*count;
            pass.address += var_descr.size;
          }/*}}}*/
          break;

        // - ERROR -
        default:
          return false;
        }
      }/*}}}*/
      break;
    }
  } while(p_ptr < p_ptr_end);

  return true;
}/*}}}*/

bool trdp_pd_page_s::pack_page_data(interpreter_thread_s &it,pass_s &pass,unsigned vd_idx)
{/*{{{*/
  trdp_var_descr_s &var_descr = var_descrs[vd_idx];

  // - align to bytes -
  if (var_descr.type != TBOOL)
  {
    pass.address += !!pass.bit_pos;
    pass.bit_pos = 0;
  }

  switch (var_descr.type)
  {
  case ANY_ARRAY:
    {/*{{{*/
      unsigned count = var_descr.count;
      unsigned item_vd_idx = vd_idx + 1;

      while (count-- > 0)
      {
        // - ERROR -
        if (!pack_page_data(it,pass,item_vd_idx))
        {
          return false;
        }
      }
    }/*}}}*/
    break;
  case ANY_STRUCTURED:
    {/*{{{*/
      unsigned svd_idx = vd_idx + 1;
      unsigned svd_idx_end = svd_idx + var_descr.count;
      do {

        // - ERROR -
        if (!pack_page_data(it,pass,svd_idx))
        {
          return false;
        }
      } while(++svd_idx < svd_idx_end);
    }/*}}}*/
    break;
  default:
    {/*{{{*/

      // - ERROR -
      if (pass.array_ptr->used - pass.array_idx < var_descr.count)
      {
        return false;
      }

#define TRDP_PACK_PAGE_DATA_INTEGER_VALUE(TYPE) \
{/*{{{*/\
  unsigned count = var_descr.count;\
  while (count-- > 0)\
  {\
    location_s *item_location = it.get_location_value(pass.array_ptr->data[pass.array_idx++]);\
    \
    /* - ERROR - */\
    if (item_location->v_type != c_bi_class_integer)\
    {\
      return false;\
    }\
    \
    TYPE value = (long long int)item_location->v_data_ptr;\
    memcpy(pass.data_ptr + pass.address,(unsigned char *)&value,var_descr.length);\
    pass.address += var_descr.length;\
  }\
}/*}}}*/

#define TRDP_PACK_PAGE_DATA_INTEGER_REORDER_VALUE(TYPE) \
{/*{{{*/\
  unsigned count = var_descr.count;\
  while (count-- > 0)\
  {\
    location_s *item_location = it.get_location_value(pass.array_ptr->data[pass.array_idx++]);\
    \
    /* - ERROR - */\
    if (item_location->v_type != c_bi_class_integer)\
    {\
      return false;\
    }\
    \
    TYPE value = (long long int)item_location->v_data_ptr;\
    memcpy_bo(pass.data_ptr + pass.address,(unsigned char *)&value,var_descr.length,c_little_endian);\
    pass.address += var_descr.length;\
  }\
}/*}}}*/

#define TRDP_PACK_PAGE_DATA_FLOAT_REORDER_VALUE(TYPE) \
{/*{{{*/\
  unsigned count = var_descr.count;\
  while (count-- > 0)\
  {\
    location_s *item_location = it.get_location_value(pass.array_ptr->data[pass.array_idx++]);\
    \
    /* - ERROR - */\
    if (item_location->v_type != c_bi_class_float)\
    {\
      return false;\
    }\
    \
    TYPE value = (double)item_location->v_data_ptr;\
    memcpy_bo(pass.data_ptr + pass.address,(unsigned char *)&value,var_descr.length,c_little_endian);\
    pass.address += var_descr.length;\
  }\
}/*}}}*/

      switch (var_descr.type)
      {
      case TBOOL:
        {/*{{{*/
          unsigned count = var_descr.count;
          while (count-- > 0)
          {
            location_s *item_location = it.get_location_value(pass.array_ptr->data[pass.array_idx++]);

            // - ERROR -
            if (item_location->v_type != c_bi_class_integer)
            {
              return false;
            }

            unsigned char value = !!(long long int)item_location->v_data_ptr;

            // - set bit value -
            if (!pass.bit_pos)
            {
              pass.data_ptr[pass.address] = value;
            }
            else
            {
              pass.data_ptr[pass.address] |= value << pass.bit_pos;
            }

            // - advance bit position -
            if (++pass.bit_pos >= 8)
            {
              ++pass.address;
              pass.bit_pos = 0;
            }
          }
        }/*}}}*/
        break;
      case TBYTE:
        TRDP_PACK_PAGE_DATA_INTEGER_VALUE(unsigned char);
        break;
      case TWORD:
        TRDP_PACK_PAGE_DATA_INTEGER_VALUE(unsigned short);
        break;
      case TDWORD:
        TRDP_PACK_PAGE_DATA_INTEGER_VALUE(unsigned);
        break;
      case TLWORD:
        TRDP_PACK_PAGE_DATA_INTEGER_VALUE(unsigned long long);
        break;
      case TUSINT:
        TRDP_PACK_PAGE_DATA_INTEGER_VALUE(unsigned char);
        break;
      case TINT:
        TRDP_PACK_PAGE_DATA_INTEGER_REORDER_VALUE(short);
        break;
      case TUINT:
        TRDP_PACK_PAGE_DATA_INTEGER_REORDER_VALUE(unsigned short);
        break;
      case TUDINT:
        TRDP_PACK_PAGE_DATA_INTEGER_REORDER_VALUE(unsigned);
        break;
      case TREAL:
        TRDP_PACK_PAGE_DATA_FLOAT_REORDER_VALUE(float);
        break;
      case TLREAL:
        TRDP_PACK_PAGE_DATA_FLOAT_REORDER_VALUE(double);
        break;
      case TSTRINGB:
      case TSTRING:
        {/*{{{*/
          unsigned count = var_descr.count;
          while (count-- > 0)
          {
            location_s *item_location = it.get_location_value(pass.array_ptr->data[pass.array_idx++]);

            // - ERROR -
            if (item_location->v_type != c_bi_class_string)
            {
              return false;
            }

            string_s *string_ptr = (string_s *)item_location->v_data_ptr;

            // - ERROR -
            if (string_ptr->size - 1 > var_descr.length)
            {
              return false;
            }

            if (string_ptr->size < var_descr.length)
            {
              memcpy(pass.data_ptr + pass.address,string_ptr->data,string_ptr->size);
              memset(pass.data_ptr + pass.address + string_ptr->size,0,var_descr.length - string_ptr->size);
            }
            else
            {
              memcpy(pass.data_ptr + pass.address,string_ptr->data,var_descr.length);
            }

            pass.address += var_descr.length;
          }
        }/*}}}*/
        break;

      // - ERROR -
      default:
        return false;
      }

    }/*}}}*/
    break;
  }

  return true;
}/*}}}*/

bool trdp_pd_page_s::unpack_page_data(interpreter_thread_s &it,pass_s &pass,unsigned vd_idx)
{/*{{{*/
  trdp_var_descr_s &var_descr = var_descrs[vd_idx];

  // - align to bytes -
  if (var_descr.type != TBOOL)
  {
    pass.address += !!pass.bit_pos;
    pass.bit_pos = 0;
  }

  switch (var_descr.type)
  {
  case ANY_ARRAY:
    {/*{{{*/
      unsigned count = var_descr.count;
      unsigned item_vd_idx = vd_idx + 1;

      while (count-- > 0)
      {
        // - ERROR -
        if (!unpack_page_data(it,pass,item_vd_idx))
        {
          return false;
        }
      }
    }/*}}}*/
    break;
  case ANY_STRUCTURED:
    {/*{{{*/
      unsigned svd_idx = vd_idx + 1;
      unsigned svd_idx_end = svd_idx + var_descr.count;
      do {

        // - ERROR -
        if (!unpack_page_data(it,pass,svd_idx))
        {
          return false;
        }
      } while(++svd_idx < svd_idx_end);
    }/*}}}*/
    break;
  default:
    {/*{{{*/

#define TRDP_UNPACK_PAGE_DATA_INTEGER_VALUE(TYPE) \
{/*{{{*/\
  unsigned count = var_descr.count;\
  while (count-- > 0)\
  {\
    TYPE value;\
    memcpy((unsigned char *)&value,pass.data_ptr + pass.address,var_descr.length);\
    pass.address += var_descr.length;\
\
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,(long long int)value);\
    pass.array_ptr->push(new_location);\
  }\
}/*}}}*/

#define TRDP_UNPACK_PAGE_DATA_INTEGER_REORDER_VALUE(TYPE) \
{/*{{{*/\
  unsigned count = var_descr.count;\
  while (count-- > 0)\
  {\
    TYPE value;\
    memcpy_bo((unsigned char *)&value,pass.data_ptr + pass.address,var_descr.length,c_little_endian);\
    pass.address += var_descr.length;\
\
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,(long long int)value);\
    pass.array_ptr->push(new_location);\
  }\
}/*}}}*/

#define TRDP_UNPACK_PAGE_DATA_FLOAT_VALUE(TYPE) \
{/*{{{*/\
  unsigned count = var_descr.count;\
  while (count-- > 0)\
  {\
    TYPE value;\
    memcpy_bo((unsigned char *)&value,pass.data_ptr + pass.address,var_descr.length,c_little_endian);\
    pass.address += var_descr.length;\
\
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_float,(double)value);\
    pass.array_ptr->push(new_location);\
  }\
}/*}}}*/

      switch (var_descr.type)
      {
      case TBOOL:
        {/*{{{*/
          unsigned count = var_descr.count;
          while (count-- > 0)
          {
            long long int value = !!(pass.data_ptr[pass.address] & (0x01 << pass.bit_pos));

            BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);
            pass.array_ptr->push(new_location);

            // - advance bit position -
            if (++pass.bit_pos >= 8)
            {
              ++pass.address;
              pass.bit_pos = 0;
            }
          }
        }/*}}}*/
        break;
      case TBYTE:
        TRDP_UNPACK_PAGE_DATA_INTEGER_VALUE(unsigned char);
        break;
      case TWORD:
        TRDP_UNPACK_PAGE_DATA_INTEGER_VALUE(unsigned short);
        break;
      case TDWORD:
        TRDP_UNPACK_PAGE_DATA_INTEGER_VALUE(unsigned);
        break;
      case TLWORD:
        TRDP_UNPACK_PAGE_DATA_INTEGER_VALUE(unsigned long long);
        break;
      case TUSINT:
        TRDP_UNPACK_PAGE_DATA_INTEGER_VALUE(unsigned char);
        break;
      case TINT:
        TRDP_UNPACK_PAGE_DATA_INTEGER_REORDER_VALUE(short);
        break;
      case TUINT:
        TRDP_UNPACK_PAGE_DATA_INTEGER_REORDER_VALUE(unsigned short);
        break;
      case TUDINT:
        TRDP_UNPACK_PAGE_DATA_INTEGER_REORDER_VALUE(unsigned);
        break;
      case TREAL:
        TRDP_UNPACK_PAGE_DATA_FLOAT_VALUE(float);
        break;
      case TLREAL:
        TRDP_UNPACK_PAGE_DATA_FLOAT_VALUE(double);
        break;
      case TSTRINGB:
      case TSTRING:
        {/*{{{*/
          unsigned count = var_descr.count;
          while (count-- > 0)
          {
            unsigned length = strnlen((char *)(pass.data_ptr + pass.address),var_descr.length);

            string_s *string_ptr = it.get_new_string_ptr();
            string_ptr->create(length);

            memcpy(string_ptr->data,pass.data_ptr + pass.address,length);
            pass.address += var_descr.length;

            BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
            pass.array_ptr->push(new_location);
          }
        }/*}}}*/
        break;

      // - ERROR -
      default:
        return false;
      }

    }/*}}}*/
    break;
  }

  return true;
}/*}}}*/

