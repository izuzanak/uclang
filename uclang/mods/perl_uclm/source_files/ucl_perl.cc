
@begin
include "ucl_perl.h"
@end

// - perl global init object -
perl_c g_perl;

/*
 * methods of class perl_c
 */

SV *perl_c::create_perl_sv(interpreter_thread_s &it,PerlInterpreter *my_perl,location_s *location_ptr)
{/*{{{*/
  if (location_ptr->v_type == c_bi_class_perl_value)
  {
    perl_value_s *pv_ptr = (perl_value_s *)location_ptr->v_data_ptr;
    SvREFCNT_inc(pv_ptr->sv);

    return pv_ptr->sv;
  }
  else if (location_ptr->v_type == c_rm_class_dict)
  {/*{{{*/
    return NULL;
  }/*}}}*/
  else
  {
    switch (location_ptr->v_type)
    {
    case c_bi_class_blank:
      {
        return newSV(0);
      }
    case c_bi_class_char:
      {
        return NULL;
      }
    case c_bi_class_integer:
      {/*{{{*/
        return NULL;
      }/*}}}*/
    case c_bi_class_float:
      {
        return NULL;
      }
    case c_bi_class_string:
      {
        return NULL;
      }
    case c_bi_class_array:
      {/*{{{*/
        return NULL;
      }/*}}}*/

    // - ERROR -
    default:
      return NULL;
    }
  }

  return NULL;
}/*}}}*/

location_s *perl_c::perl_sv_value(interpreter_thread_s &it,PerlInterpreter *my_perl,SV *sv,uli source_pos)
{/*{{{*/

  // FIXME debug output
  //switch (SvTYPE(sv))
  //{
  //  case SVt_NULL: fprintf(stderr,"SVt_NULL\n"); break;
  //  case SVt_IV: fprintf(stderr,"SVt_IV\n"); break;
  //  case SVt_NV: fprintf(stderr,"SVt_NV\n"); break;
  //  case SVt_PV: fprintf(stderr,"SVt_PV\n"); break;
  //  case SVt_PVAV: fprintf(stderr,"SVt_PVAV\n"); break;
  //  case SVt_PVHV: fprintf(stderr,"SVt_PVHV\n"); break;
  //  case SVt_PVIV: fprintf(stderr,"SVt_PVIV\n"); break;
  //  case SVt_PVNV: fprintf(stderr,"SVt_PVNV\n"); break;
  //  case SVt_PVMG: fprintf(stderr,"SVt_PVMG\n"); break;
  //  case SVt_INVLIST: fprintf(stderr,"SVt_INVLIST\n"); break;
  //  case SVt_REGEXP: fprintf(stderr,"SVt_REGEXP\n"); break;
  //  case SVt_PVGV: fprintf(stderr,"SVt_PVGV\n"); break;
  //  case SVt_PVLV: fprintf(stderr,"SVt_PVLV\n"); break;
  //  case SVt_PVCV: fprintf(stderr,"SVt_PVCV\n"); break;
  //  case SVt_PVFM: fprintf(stderr,"SVt_PVFM\n"); break;
  //  case SVt_PVIO: fprintf(stderr,"SVt_PVIO\n"); break;
  //  default: break;
  //}

  // - if value is reference -
  if (SvROK(sv))
  {
    return perl_sv_value(it,my_perl,SvRV(sv),source_pos);
  }

  switch (SvTYPE(sv))
  {
    case SVt_NULL:
      ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();
      return (location_s *)it.blank_location;

    case SVt_IV:
    case SVt_PVIV:
      {
        long long int value = SvIV(sv);

        BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,value);
        return new_location;
      }

    case SVt_NV:
    case SVt_PVNV:
      {
        double value = SvNV(sv);

        basic_64b &v_data_ptr = *((basic_64b *)&value);
        BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_float,v_data_ptr);
        return new_location;
      }

    case SVt_PV:
      {
        STRLEN length;
        char *buffer = SvPV(sv,length);

        string_s *string_ptr = it.get_new_string_ptr();
        string_ptr->set(length,buffer);

        BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
        return new_location;
      }

    case SVt_PVAV:
    {/*{{{*/
      pointer_array_s *array_ptr = it.get_new_array_ptr();
      BIC_CREATE_NEW_LOCATION(arr_location,c_bi_class_array,array_ptr);

      AV *av = (AV *)sv;

      SSize_t size = av_top_index(av) + 1;
      if (size > 0)
      {
        SSize_t idx = 0;
        do {
          SV **sv_ptr = av_fetch(av,idx,0);

          // - ERROR -
          if (sv_ptr == NULL)
          {
            it.release_location_ptr(arr_location);
            return NULL;
          }

          location_s *item_location = perl_sv_value(it,my_perl,*sv_ptr,source_pos);

          // - ERROR -
          if (item_location == NULL)
          {
            it.release_location_ptr(arr_location);
            return NULL;
          }

          // - insert item to array -
          array_ptr->push(item_location);

        } while(++idx < size);
      }

      return arr_location;
    }/*}}}*/

    case SVt_PVHV:
    {/*{{{*/
      pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)cmalloc(sizeof(pointer_map_tree_s));
      tree_ptr->init();
      tree_ptr->it_ptr = &it;
      tree_ptr->source_pos = source_pos;

      BIC_CREATE_NEW_LOCATION(dict_location,c_rm_class_dict,tree_ptr);

      HV *hv = (HV *)sv;
      I32 size = hv_iterinit(hv);
      if (size > 0)
      {
        int idx = 0;
        do {
          char *key;
          I32 keylen;
          SV *sv_value = hv_iternextsv(hv,&key,&keylen);

          // - ERROR -
          if (sv_value == NULL)
          {
            it.release_location_ptr(dict_location);
            return NULL;
          }

          location_s *value_location = perl_sv_value(it,my_perl,sv_value,source_pos);

          // - ERROR -
          if (value_location == NULL)
          {
            it.release_location_ptr(dict_location);

            return NULL;
          }

          string_s *string_ptr = it.get_new_string_ptr();
          string_ptr->set(keylen,key);

          BIC_CREATE_NEW_LOCATION(key_location,c_bi_class_string,string_ptr);

          pointer_map_s insert_map = {key_location,NULL};
          unsigned index = tree_ptr->unique_insert(insert_map);

          if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
          {
            it.release_location_ptr(key_location);
            it.release_location_ptr(value_location);
            it.release_location_ptr(dict_location);

            return NULL;
          }

          pointer_map_s &map = tree_ptr->data[index].object;

          if (map.value != NULL)
          {
            it.release_location_ptr(key_location);
            it.release_location_ptr(value_location);
            it.release_location_ptr(dict_location);

            return NULL;
          }

          map.value = (pointer)value_location;

        } while(++idx < size);
      }

      return dict_location;
    }/*}}}*/

    case SVt_PVMG:
    case SVt_INVLIST:
    case SVt_REGEXP:
    case SVt_PVGV:
    case SVt_PVLV:
    case SVt_PVCV:
    case SVt_PVFM:
    case SVt_PVIO:
    default:
      return NULL;
  }
}/*}}}*/

