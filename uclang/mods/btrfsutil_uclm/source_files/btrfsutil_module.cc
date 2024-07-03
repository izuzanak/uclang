
@begin
include "btrfsutil_module.h"
@end

// - BTRFS_UTIL indexes of built in classes -
unsigned c_bi_class_btrfs = c_idx_not_exist;

// - BTRFS_UTIL module -
EXPORT built_in_module_s module =
{/*{{{*/
  1,                          // Class count
  btrfs_util_classes,         // Classes

  0,                          // Error base index
  1,                          // Error count
  btrfs_util_error_strings,   // Error strings

  btrfs_util_initialize,      // Initialize function
  btrfs_util_print_exception, // Print exceptions function
};/*}}}*/

// - BTRFS_UTIL classes -
built_in_class_s *btrfs_util_classes[] =
{/*{{{*/
  &btrfs_class,
};/*}}}*/

// - BTRFS_UTIL error strings -
const char *btrfs_util_error_strings[] =
{/*{{{*/
  "error_BTRFS_UTIL_DUMMY_ERROR",
};/*}}}*/

// - BTRFS_UTIL initialize -
bool btrfs_util_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize btrfs class identifier -
  c_bi_class_btrfs = class_base_idx++;

  return true;
}/*}}}*/

// - BTRFS_UTIL print exception -
bool btrfs_util_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_BTRFS_UTIL_DUMMY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nBtrfs util, dummy error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class BTRFS -
built_in_class_s btrfs_class =
{/*{{{*/
  "Btrfs",
  c_modifier_public | c_modifier_final,
  6, btrfs_methods,
  0, btrfs_variables,
  bic_btrfs_consts,
  bic_btrfs_init,
  bic_btrfs_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s btrfs_methods[] =
{/*{{{*/
  {
    "is_sub#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_btrfs_method_is_sub_1
  },
  {
    "sub_id#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_btrfs_method_sub_id_1
  },
  {
    "sub_ro#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_btrfs_method_sub_ro_1
  },
  {
    "sub_ro#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_btrfs_method_sub_ro_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_btrfs_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_btrfs_method_print_0
  },
};/*}}}*/

built_in_variable_s btrfs_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_btrfs_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_btrfs_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_btrfs_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_btrfs_method_is_sub_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
subvolume:retrieve_integer
subvolume:c_bi_class_string
>
additions {subvolume = -1;}
class c_bi_class_btrfs
method is_sub
static_method
; @end

  enum btrfs_util_error res;

  if (src_0_location->v_type == c_bi_class_string)
  {
    // - subvolume by path -
    string_s *path_str = (string_s *)src_0_location->v_data_ptr;
    res = btrfs_util_is_subvolume(path_str->data);
  }
  else
  {
    // - subvolume by fd -
    res = btrfs_util_is_subvolume_fd(subvolume);
  }

  long long int result = 0;

  switch (res)
  {
    case BTRFS_UTIL_OK:
      result = 1;
      break;
    case BTRFS_UTIL_ERROR_NOT_BTRFS:
    case BTRFS_UTIL_ERROR_NOT_SUBVOLUME:
      break;
    default:

      // FIXME TODO throw proper exception
      BIC_TODO_ERROR(__FILE__,__LINE__);
      return false;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_btrfs_method_sub_id_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
subvolume:retrieve_integer
subvolume:c_bi_class_string
>
additions {subvolume = -1;}
class c_bi_class_btrfs
method sub_id
static_method
; @end

  enum btrfs_util_error res;
  uint64_t id_ret;

  if (src_0_location->v_type == c_bi_class_string)
  {
    // - subvolume by path -
    string_s *path_str = (string_s *)src_0_location->v_data_ptr;
    res = btrfs_util_subvolume_id(path_str->data,&id_ret);
  }
  else
  {
    // - subvolume by fd -
    res = btrfs_util_subvolume_id_fd(subvolume,&id_ret);
  }

  if (res != BTRFS_UTIL_OK)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  long long int result = id_ret;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_btrfs_method_sub_ro_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
subvolume:retrieve_integer
subvolume:c_bi_class_string
>
additions {subvolume = -1;}
class c_bi_class_btrfs
method sub_ro
static_method
; @end

  enum btrfs_util_error res;
  bool ret;

  if (src_0_location->v_type == c_bi_class_string)
  {
    // - subvolume by path -
    string_s *path_str = (string_s *)src_0_location->v_data_ptr;
    res = btrfs_util_get_subvolume_read_only(path_str->data,&ret);
  }
  else
  {
    // - subvolume by fd -
    res = btrfs_util_get_subvolume_read_only_fd(subvolume,&ret);
  }

  if (res != BTRFS_UTIL_OK)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  long long int result = ret;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_btrfs_method_sub_ro_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
subvolume:retrieve_integer
subvolume:c_bi_class_string
read_only:retrieve_integer
>
additions {subvolume = -1;}
class c_bi_class_btrfs
method sub_ro
static_method
; @end

  enum btrfs_util_error res;

  if (src_0_location->v_type == c_bi_class_string)
  {
    // - subvolume by path -
    string_s *path_str = (string_s *)src_0_location->v_data_ptr;
    res = btrfs_util_set_subvolume_read_only(path_str->data,read_only != 0);
  }
  else
  {
    // - subvolume by fd -
    res = btrfs_util_set_subvolume_read_only_fd(subvolume,read_only != 0);
  }

  if (res != BTRFS_UTIL_OK)
  {
    // FIXME TODO throw proper exception
    BIC_TODO_ERROR(__FILE__,__LINE__);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_btrfs_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Btrfs"),"Btrfs");
  );

  return true;
}/*}}}*/

bool bic_btrfs_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Btrfs");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

