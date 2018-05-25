
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
  {/*{{{*/
    perl_value_s *pv_ptr = (perl_value_s *)location_ptr->v_data_ptr;

    // - ERROR -
    if (((perl_interpreter_s *)pv_ptr->pi_loc->v_data_ptr)->interpreter != my_perl)
    {
      return nullptr;
    }

    // - dereference perl reference values -
    SV *sv = SvROK(pv_ptr->sv) ? SvRV(pv_ptr->sv) : pv_ptr->sv;

    SvREFCNT_inc(sv);
    return sv;
  }/*}}}*/
  else if (location_ptr->v_type == c_bi_class_perl_reference)
  {/*{{{*/
    perl_reference_s *pr_ptr = (perl_reference_s *)location_ptr->v_data_ptr;

    // - ERROR -
    if (((perl_interpreter_s *)pr_ptr->pi_loc->v_data_ptr)->interpreter != my_perl)
    {
      return nullptr;
    }

    // - retrieve reference value -
    SV *sv = pr_ptr->get(my_perl);

    // - dereference perl reference values -
    sv = SvROK(sv) ? SvRV(sv) : sv;

    SvREFCNT_inc(sv);
    return sv;
  }/*}}}*/
  else if (location_ptr->v_type == c_rm_class_dict)
  {/*{{{*/
    pointer_map_tree_s *tree_ptr = (pointer_map_tree_s *)location_ptr->v_data_ptr;
    HV *hv = newHV();

    if (tree_ptr->root_idx != c_idx_not_exist)
    {
      unsigned stack[tree_ptr->get_descent_stack_size()];
      unsigned *stack_ptr = stack;

      unsigned t_idx = tree_ptr->get_stack_min_value_idx(tree_ptr->root_idx,&stack_ptr);

      do
      {
        pointer_map_tree_s_node &node = tree_ptr->data[t_idx];

        location_s *key_location = (location_s *)node.object.key;
        SV *sv_key = create_perl_sv(it,my_perl,key_location);

        // - ERROR -
        if (sv_key == nullptr)
        {
          SvREFCNT_dec(hv);

          return nullptr;
        }

        location_s *value_location = it.get_location_value(node.object.value);
        SV *sv_value = create_perl_sv(it,my_perl,value_location);

        // - ERROR -
        if (sv_value == nullptr)
        {
          SvREFCNT_dec(sv_key);
          SvREFCNT_dec(hv);

          return nullptr;
        }

        // - ERROR -
        if (hv_store_ent(hv,sv_key,sv_value,0) == nullptr)
        {
          SvREFCNT_dec(sv_key);
          SvREFCNT_dec(sv_value);
          SvREFCNT_dec(hv);

          return nullptr;
        }

        SvREFCNT_dec(sv_key);

        t_idx = tree_ptr->get_stack_next_idx(t_idx,&stack_ptr,stack);
      }
      while(t_idx != c_idx_not_exist);
    }

    return (SV *)hv;
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
        return newSViv((char)location_ptr->v_data_ptr);
      }
    case c_bi_class_integer:
      {
        return newSViv((long long int)location_ptr->v_data_ptr);
      }
    case c_bi_class_float:
      {
        return newSVnv((double)location_ptr->v_data_ptr);
      }
    case c_bi_class_string:
      {
        string_s *string_ptr = (string_s *)location_ptr->v_data_ptr;
        return newSVpvn(string_ptr->data,string_ptr->size - 1);
      }
    case c_bi_class_array:
      {/*{{{*/
        pointer_array_s *array_ptr = (pointer_array_s *)location_ptr->v_data_ptr;
        AV *av = newAV();

        if (array_ptr->used != 0)
        {
          pointer *a_ptr = array_ptr->data;
          pointer *a_ptr_end = a_ptr + array_ptr->used;
          do {
            SV *sv_item = create_perl_sv(it,my_perl,it.get_location_value(*a_ptr));

            // - ERROR -
            if (sv_item == nullptr)
            {
              SvREFCNT_dec(av);

              return nullptr;
            }

            // - push item to perl array -
            av_push(av,sv_item);

          } while(++a_ptr < a_ptr_end);
        }

        return (SV *)av;
      }/*}}}*/

    // - ERROR -
    default:
      return nullptr;
    }
  }

  return nullptr;
}/*}}}*/

location_s *perl_c::perl_sv_value(interpreter_thread_s &it,PerlInterpreter *my_perl,SV *sv,uli source_pos)
{/*{{{*/

  //// FIXME debug output
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
  //  default:
  //    fprintf(stderr,"UNKNOWN");
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

        BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_float,value);
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
          location_s *item_location;

          SV **sv_ptr = av_fetch(av,idx,0);

          // - undefined array element interpreted as blank -
          if (sv_ptr == nullptr)
          {
            ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();
            item_location = (location_s *)it.blank_location;
          }
          else
          {
            item_location = perl_sv_value(it,my_perl,*sv_ptr,source_pos);
          }

          // - ERROR -
          if (item_location == nullptr)
          {
            it.release_location_ptr(arr_location);
            return nullptr;
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
          if (sv_value == nullptr)
          {
            it.release_location_ptr(dict_location);
            return nullptr;
          }

          location_s *value_location = perl_sv_value(it,my_perl,sv_value,source_pos);

          // - ERROR -
          if (value_location == nullptr)
          {
            it.release_location_ptr(dict_location);

            return nullptr;
          }

          string_s *string_ptr = it.get_new_string_ptr();
          string_ptr->set(keylen,key);

          BIC_CREATE_NEW_LOCATION(key_location,c_bi_class_string,string_ptr);

          pointer_map_s insert_map = {key_location,nullptr};
          unsigned index = tree_ptr->unique_insert(insert_map);

          if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
          {
            it.release_location_ptr(key_location);
            it.release_location_ptr(value_location);
            it.release_location_ptr(dict_location);

            return nullptr;
          }

          pointer_map_s &map = tree_ptr->data[index].object;

          if (map.value != nullptr)
          {
            it.release_location_ptr(key_location);
            it.release_location_ptr(value_location);
            it.release_location_ptr(dict_location);

            return nullptr;
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
      return nullptr;
  }
}/*}}}*/

