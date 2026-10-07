
@begin
include "ucl_crypto.h"
@end

// - crypto global init object -
crypto_c g_crypto;

/*
 * methods of structure crypto_pkey_s
 */

int crypto_pkey_s::password_cb(char *buf,int size,int rwflag,void *userdata)
{/*{{{*/
  string_s *string_ptr = (string_s *)userdata;

  unsigned passwd_size = (unsigned)size < string_ptr->size ? size : string_ptr->size - 1;
  memcpy(buf,string_ptr->data,passwd_size*sizeof(char));

  return passwd_size;
}/*}}}*/

#if OPENSSL_VERSION_NUMBER >= 0x30000000L

// - kdf algorithm names -
const char *c_crypto_kdf_names[] =
{/*{{{*/
  "ARGON2ID",
  "SCRYPT",
  "PBKDF2",
};/*}}}*/

/*
 * methods of structure crypto_kdf_s
 */

int crypto_kdf_s::algorithm_idx(string_s &a_name)
{/*{{{*/
  unsigned idx = 0;
  do {
    if (strcmp(a_name.data,c_crypto_kdf_names[idx]) == 0)
    {
#if OPENSSL_VERSION_NUMBER < 0x30200000L
      // - argon2 needs openssl >= 3.2 -
      if (idx == c_crypto_kdf_argon2id)
      {
        return -1;
      }
#endif
      return idx;
    }
  } while(++idx < c_crypto_kdf_count);

  return -1;
}/*}}}*/

bool crypto_kdf_s::read_params(interpreter_thread_s &it,location_s *a_array_location,
    crypto_kdf_param_s *a_params,unsigned a_count,const char **a_bad_name)
{/*{{{*/
  pointer_array_s *array_ptr = (pointer_array_s *)a_array_location->v_data_ptr;

  // - ERROR -
  if (array_ptr->used & 0x01)
  {
    *a_bad_name = "params";
    return false;
  }

  if (array_ptr->used != 0)
  {
    pointer *ptr = array_ptr->data;
    pointer *ptr_end = ptr + array_ptr->used;
    do {
      location_s *key_location = it.get_location_value(ptr[0]);
      location_s *value_location = it.get_location_value(ptr[1]);

      // - ERROR -
      if (key_location->v_type != c_bi_class_string)
      {
        *a_bad_name = "params";
        return false;
      }

      string_s *key_ptr = (string_s *)key_location->v_data_ptr;

      // - find parameter description -
      crypto_kdf_param_s *param_ptr = a_params;
      crypto_kdf_param_s *param_ptr_end = param_ptr + a_count;
      do {
        if (strcmp(key_ptr->data,param_ptr->name) == 0)
        {
          break;
        }
      } while(++param_ptr < param_ptr_end);

      // - ERROR -
      if (param_ptr >= param_ptr_end)
      {
        *a_bad_name = key_ptr->data;
        return false;
      }

      if (param_ptr->is_string)
      {
        // - ERROR -
        if (value_location->v_type != c_bi_class_string)
        {
          *a_bad_name = param_ptr->name;
          return false;
        }

        param_ptr->sval = (string_s *)value_location->v_data_ptr;
      }
      else
      {
        long long int value;

        if (value_location->v_type == c_bi_class_integer)
        {
          value = (long long int)value_location->v_data_ptr;
        }
        else if (value_location->v_type == c_bi_class_char)
        {
          value = (char)value_location->v_data_ptr;
        }

        // - ERROR -
        else
        {
          *a_bad_name = param_ptr->name;
          return false;
        }

        // - ERROR -
        if (value <= 0 || value > (long long int)UINT32_MAX)
        {
          *a_bad_name = param_ptr->name;
          return false;
        }

        param_ptr->ival = value;
      }

      param_ptr->seen = true;

    } while((ptr += 2) < ptr_end);
  }

  // - check required parameters -
  crypto_kdf_param_s *param_ptr = a_params;
  crypto_kdf_param_s *param_ptr_end = param_ptr + a_count;
  do {
    // - ERROR -
    if (param_ptr->required && !param_ptr->seen)
    {
      *a_bad_name = param_ptr->name;
      return false;
    }
  } while(++param_ptr < param_ptr_end);

  return true;
}/*}}}*/

const char *crypto_kdf_s::error_reason()
{/*{{{*/
  const char *reason = ERR_reason_error_string(ERR_peek_last_error());
  return reason != nullptr ? reason : "unknown error";
}/*}}}*/

#endif
