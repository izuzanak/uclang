
@begin
include "ucl_uctrdp.h"
@end

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
          var_descr.address = (pass.address << 3) + pass.bit_pos;
          var_descr.length = 1;
          var_descr.size = count;

          pass.address += (pass.bit_pos += count) >> 3;
          pass.bit_pos &= 0x07;
          break;
        case TBYTE:
          var_descr.address = pass.address;
          var_descr.length = 1;
          var_descr.size = count;

          ++pass.address;
          break;

        // FIXME TODO continue ...

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

            long long int value = !!(long long int)item_location->v_data_ptr;

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

            // - set byte value -
            *((unsigned char *)(pass.data_ptr + pass.address)) = (long long int)item_location->v_data_ptr;
            ++pass.address;
          }
        }/*}}}*/
        break;

      // FIXME TODO continue ...

      // - ERROR -
      default:
        return false;
      }

    }/*}}}*/
    break;
  }

  return true;
}/*}}}*/

