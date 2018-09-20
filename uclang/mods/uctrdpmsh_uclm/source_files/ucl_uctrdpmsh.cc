
@begin
include "ucl_uctrdpmsh.h"
@end

// - UCTRDPMSH indexes of remote classes -
unsigned c_rm_class_dict = c_idx_not_exist;

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
 * methods of structure trdp_page_s
 */

bool trdp_page_s::process_page_description(
    interpreter_thread_s &it,pass_s &pass,pointer_array_s *array_ptr,unsigned &vd_count,unsigned &last_vd_idx)
{/*{{{*/

  // - reset variable descriptor count -
  vd_count = 0;

  // - ERROR -
  if (array_ptr->used == 0)
  {
    exception_s::throw_exception(it,c_error_TRDP_PAGE_DESCR_TOO_SHORT,0,(location_s *)it.blank_location);
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
      exception_s::throw_exception(it,c_error_TRDP_PAGE_DESCR_TOO_SHORT,0,(location_s *)it.blank_location);
      return false;
    }

    location_s *name_location = it.get_location_value(*p_ptr++);

    // - ERROR -
    long long int type;
    if (name_location->v_type != c_bi_class_string)
    {
      exception_s::throw_exception(it,c_error_TRDP_PAGE_DESCR_EXPECTED_STRING_AS_NAME,0,(location_s *)it.blank_location);
      return false;
    }

    // - ERROR -
    if (!it.retrieve_integer(it.get_location_value(*p_ptr++),type))
    {
      exception_s::throw_exception(it,c_error_TRDP_PAGE_DESCR_EXPECTED_INTEGER_AS_TYPE,0,(location_s *)it.blank_location);
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
          exception_s::throw_exception(it,c_error_TRDP_PAGE_DESCR_TOO_SHORT,0,(location_s *)it.blank_location);
          return false;
        }

        // - ERROR -
        long long int count;
        if (!it.retrieve_integer(it.get_location_value(*p_ptr++),count) || count <= 0)
        {
          exception_s::throw_exception(it,c_error_TRDP_PAGE_DESCR_EXPECTED_INTEGER_AS_ARRAY_SIZE,0,(location_s *)it.blank_location);
          return false;
        }

        location_s *array_location = it.get_location_value(*p_ptr++);

        // - ERRRO -
        if (array_location->v_type != c_bi_class_array)
        {
          exception_s::throw_exception(it,c_error_TRDP_PAGE_DESCR_EXPECTED_ARRAY_AS_ARRAY_DESCR,0,(location_s *)it.blank_location);
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

        unsigned array_vd_count;
        unsigned array_last_vd_idx;
        unsigned old_var_idx = pass.var_idx;

        // - ERROR -
        if (!process_page_description(
              it,pass,(pointer_array_s *)array_location->v_data_ptr,array_vd_count,array_last_vd_idx))
        {
          return false;
        }

        // - ERROR -
        if (array_vd_count != 1)
        {
          exception_s::throw_exception(it,c_error_TRDP_PAGE_DESCR_ARRAY_INVALID_VD_COUNT,0,(location_s *)it.blank_location);
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

        pass.var_idx += (count - 1)*(pass.var_idx - old_var_idx);

        vd_ptr->length = length;
        vd_ptr->size = length;
      }/*}}}*/
      break;
    case ANY_STRUCT:
      {/*{{{*/

        // - ERROR -
        if (p_ptr >= p_ptr_end)
        {
          exception_s::throw_exception(it,c_error_TRDP_PAGE_DESCR_TOO_SHORT,0,(location_s *)it.blank_location);
          return false;
        }

        location_s *array_location = it.get_location_value(*p_ptr++);

        // - ERRRO -
        if (array_location->v_type != c_bi_class_array)
        {
          exception_s::throw_exception(it,c_error_TRDP_PAGE_DESCR_EXPECTED_ARRAY_AS_STRUCT_DESCR,0,(location_s *)it.blank_location);
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

        unsigned struct_vd_count;
        unsigned struct_last_vd_idx;

        // - ERROR -
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
          exception_s::throw_exception(it,c_error_TRDP_PAGE_DESCR_TOO_SHORT,0,(location_s *)it.blank_location);
          return false;
        }

        // - ERROR -
        long long int count;
        if (!it.retrieve_integer(it.get_location_value(*p_ptr++),count) || count <= 0)
        {
          exception_s::throw_exception(it,c_error_TRDP_PAGE_DESCR_EXPECTED_INTEGER_AS_VARIABLE_COUNT,0,(location_s *)it.blank_location);
          return false;
        }

        // - increase variable count -
        pass.var_idx += count;

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
        case TTDsecs:
        case TTDticks:
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
              case TTDticks:
                var_descr.length = 2;
                break;
              case TDWORD:
              case TUDINT:
              case TREAL:
              case TTDsecs:
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
                    exception_s::throw_exception(it,c_error_TRDP_PAGE_DESCR_TOO_SHORT,0,(location_s *)it.blank_location);
                    return false;
                  }

                  // - ERROR -
                  long long int length;
                  if (!it.retrieve_integer(it.get_location_value(*p_ptr++),length) ||
                      length <= 0 || length >= 256)
                  {
                    exception_s::throw_exception(it,c_error_TRDP_PAGE_DESCR_EXPECTED_INTEGER_AS_STRING_LENGTH,0,(location_s *)it.blank_location);
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

          exception_s *new_exception = exception_s::throw_exception(it,c_error_TRDP_PAGE_DESCR_UNSUPPORTED_TYPE,0,(location_s *)it.blank_location);
          new_exception->params.push(type);

          return false;
        }
      }/*}}}*/
      break;
    }
  } while(p_ptr < p_ptr_end);

  return true;
}/*}}}*/

bool trdp_page_s::pack_page_data(interpreter_thread_s &it,pass_s &pass)
{/*{{{*/
  trdp_var_descr_s &var_descr = var_descrs[pass.vd_idx++];

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
      unsigned item_vd_idx = pass.vd_idx;

      while (count-- > 0)
      {
        pass.vd_idx = item_vd_idx;

        // - ERROR -
        if (!pack_page_data(it,pass))
        {
          return false;
        }
      }
    }/*}}}*/
    break;
  case ANY_STRUCT:
    {/*{{{*/
      unsigned count = var_descr.count;
      while (count-- > 0)
      {
        // - ERROR -
        if (!pack_page_data(it,pass))
        {
          return false;
        }
      }
    }/*}}}*/
    break;
  default:
    {/*{{{*/
#define TRDP_PACK_PAGE_DATA_INTEGER_VALUE(TYPE) \
{/*{{{*/\
  unsigned count = var_descr.count;\
  while (count-- > 0)\
  {\
    location_s *item_location = it.get_location_value(pass.vars_ptr->data[pass.var_idx++]);\
    \
    /* - ERROR - */\
    if (item_location->v_type != c_bi_class_integer)\
    {\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_TRDP_PAGE_PACK_INVALID_VARIABLE_TYPE,0,(location_s *)it.blank_location);\
      new_exception->params.push(pass.var_idx);\
      new_exception->params.push(c_bi_class_integer);\
      \
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
    location_s *item_location = it.get_location_value(pass.vars_ptr->data[pass.var_idx++]);\
    \
    /* - ERROR - */\
    if (item_location->v_type != c_bi_class_integer)\
    {\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_TRDP_PAGE_PACK_INVALID_VARIABLE_TYPE,0,(location_s *)it.blank_location);\
      new_exception->params.push(pass.var_idx);\
      new_exception->params.push(c_bi_class_integer);\
      \
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
    location_s *item_location = it.get_location_value(pass.vars_ptr->data[pass.var_idx++]);\
    \
    /* - ERROR - */\
    if (item_location->v_type != c_bi_class_float)\
    {\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_TRDP_PAGE_PACK_INVALID_VARIABLE_TYPE,0,(location_s *)it.blank_location);\
      new_exception->params.push(pass.var_idx);\
      new_exception->params.push(c_bi_class_float);\
      \
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
            location_s *item_location = it.get_location_value(pass.vars_ptr->data[pass.var_idx++]);

            // - ERROR -
            if (item_location->v_type != c_bi_class_integer)
            {
              exception_s *new_exception = exception_s::throw_exception(it,c_error_TRDP_PAGE_PACK_INVALID_VARIABLE_TYPE,0,(location_s *)it.blank_location);
              new_exception->params.push(pass.var_idx);
              new_exception->params.push(c_bi_class_integer);

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
      case TUSINT:
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
      case TINT:
        TRDP_PACK_PAGE_DATA_INTEGER_REORDER_VALUE(short);
        break;
      case TUINT:
      case TTDticks:
        TRDP_PACK_PAGE_DATA_INTEGER_REORDER_VALUE(unsigned short);
        break;
      case TUDINT:
      case TTDsecs:
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
            location_s *item_location = it.get_location_value(pass.vars_ptr->data[pass.var_idx++]);

            // - ERROR -
            if (item_location->v_type != c_bi_class_string)
            {
              exception_s *new_exception = exception_s::throw_exception(it,c_error_TRDP_PAGE_PACK_INVALID_VARIABLE_TYPE,0,(location_s *)it.blank_location);
              new_exception->params.push(pass.var_idx);
              new_exception->params.push(c_bi_class_string);

              return false;
            }

            string_s *string_ptr = (string_s *)item_location->v_data_ptr;

            // - ERROR -
            if (string_ptr->size - 1 > var_descr.length)
            {
              exception_s *new_exception = exception_s::throw_exception(it,c_error_TRDP_PAGE_PACK_INVALID_STRING_LENGTH,0,(location_s *)it.blank_location);
              new_exception->params.push(pass.var_idx);

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

bool trdp_page_s::unpack_page_data(interpreter_thread_s &it,pass_s &pass)
{/*{{{*/
  trdp_var_descr_s &var_descr = var_descrs[pass.vd_idx++];

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
      unsigned item_vd_idx = pass.vd_idx;

      while (count-- > 0)
      {
        pass.vd_idx = item_vd_idx;

        // - ERROR -
        if (!unpack_page_data(it,pass))
        {
          return false;
        }
      }
    }/*}}}*/
    break;
  case ANY_STRUCT:
    {/*{{{*/
      unsigned count = var_descr.count;

      while (count-- > 0)
      {
        // - ERROR -
        if (!unpack_page_data(it,pass))
        {
          return false;
        }
      }
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
    pass.vars_ptr->push(new_location);\
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
    pass.vars_ptr->push(new_location);\
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
    pass.vars_ptr->push(new_location);\
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
            pass.vars_ptr->push(new_location);

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
      case TTDticks:
        TRDP_UNPACK_PAGE_DATA_INTEGER_REORDER_VALUE(unsigned short);
        break;
      case TUDINT:
      case TTDsecs:
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
            pass.vars_ptr->push(new_location);
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

location_s *trdp_page_s::build_dict(interpreter_thread_s &it,pass_s &pass,pointer_array_s *array_ptr,pointer_map_tree_s *tree_ptr)
{/*{{{*/
  trdp_var_descr_s &var_descr = var_descrs[pass.vd_idx++];

  // - retrieved value location -
  location_s *value_location;

  switch (var_descr.type)
  {
  case ANY_ARRAY:
    {/*{{{*/
      pointer_array_s *new_arr_ptr = it.get_new_array_ptr();

      BIC_CREATE_NEW_LOCATION(array_location,c_bi_class_array,new_arr_ptr);
      value_location = array_location;

      unsigned count = var_descr.count;
      unsigned item_vd_idx = pass.vd_idx;

      while (count-- > 0)
      {
        pass.vd_idx = item_vd_idx;
        build_dict(it,pass,new_arr_ptr,nullptr);
      }
    }/*}}}*/
    break;
  case ANY_STRUCT:
    {/*{{{*/
      pointer_map_tree_s *new_tree_ptr = (pointer_map_tree_s *)cmalloc(sizeof(pointer_map_tree_s));
      new_tree_ptr->init();

      new_tree_ptr->it_ptr = &it;
      new_tree_ptr->source_pos = 0;

      BIC_CREATE_NEW_LOCATION(tree_location,c_rm_class_dict,new_tree_ptr);
      value_location = tree_location;

      unsigned count = var_descr.count;

      while (count-- > 0)
      {
        build_dict(it,pass,nullptr,new_tree_ptr);
      }
    }/*}}}*/
    break;
  default:
    {/*{{{*/
      
      // - single value -
      if (var_descr.count == 1)
      {
        location_s *item_location = it.get_location_value(pass.vars_ptr->data[pass.var_idx++]);

        item_location->v_reference_cnt.atomic_inc();
        value_location = item_location;
      }
      
      // - array of values -
      else
      {
        pointer_array_s *new_arr_ptr = it.get_new_array_ptr();
        BIC_CREATE_NEW_LOCATION(new_arr_location,c_bi_class_array,new_arr_ptr);

        unsigned var_idx_end = pass.var_idx + var_descr.count;
        do {
          location_s *item_location = it.get_location_value(pass.vars_ptr->data[pass.var_idx++]);

          item_location->v_reference_cnt.atomic_inc();
          new_arr_ptr->push(item_location);
        } while(pass.var_idx < var_idx_end);

        value_location = new_arr_location;
      }
    }/*}}}*/
    break;
  }

  // - insert value to dictionary -
  if (tree_ptr != nullptr)
  {
    pointer_map_s insert_map = {var_descr.name_location,nullptr};
    unsigned index = tree_ptr->unique_insert(insert_map);

    // - no need to check exception! -
    cassert(((location_s *)it.exception_location)->v_type == c_bi_class_blank);

    pointer_map_s &map = tree_ptr->data[index].object;

    if (map.value)
    {
      it.release_location_ptr((location_s *)map.value);
    }
    else
    {
      ((location_s *)var_descr.name_location)->v_reference_cnt.atomic_inc();
    }

    map.value = (pointer)value_location;
  }

  // - insert value to array -
  else if (array_ptr != nullptr)
  {
    array_ptr->push(value_location);
  }

  // - return value as result -
  else
  {
    return value_location;
  }

  return nullptr;
}/*}}}*/

