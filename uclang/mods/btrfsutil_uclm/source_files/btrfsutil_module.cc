
@begin
include "btrfsutil_module.h"
@end

// - BTRFS_UTIL indexes of built in classes -
unsigned c_bi_class_btrfs = c_idx_not_exist;
unsigned c_bi_class_btrfs_sub = c_idx_not_exist;

// - BTRFS_UTIL module -
EXPORT built_in_module_s module =
{/*{{{*/
  2,                          // Class count
  btrfs_util_classes,         // Classes

  0,                          // Error base index
  9,                          // Error count
  btrfs_util_error_strings,   // Error strings

  btrfs_util_initialize,      // Initialize function
  btrfs_util_print_exception, // Print exceptions function
};/*}}}*/

// - BTRFS_UTIL classes -
built_in_class_s *btrfs_util_classes[] =
{/*{{{*/
  &btrfs_class,
  &btrfs_sub_class,
};/*}}}*/

// - BTRFS_UTIL error strings -
const char *btrfs_util_error_strings[] =
{/*{{{*/
  "error_BTRFS_UTIL_REALPATH_ERROR",
  "error_BTRFS_UTIL_CREATE_SUBVOLUME_ERROR",
  "error_BTRFS_UTIL_DELETE_SUBVOLUME_ERROR",
  "error_BTRFS_UTIL_SUB_IS_NOT_SUBVOLUME",
  "error_BTRFS_UTIL_SUB_GET_ID_ERROR",
  "error_BTRFS_UTIL_SUB_GET_READ_ONLY_ERROR",
  "error_BTRFS_UTIL_SUB_SET_READ_ONLY_ERROR",
  "error_BTRFS_UTIL_SUB_SNAPSHOT_ERROR",
  "error_BTRFS_UTIL_SUB_DELETE_ERROR",
};/*}}}*/

// - BTRFS_UTIL initialize -
bool btrfs_util_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize btrfs class identifier -
  c_bi_class_btrfs = class_base_idx++;

  // - initialize btrfs_sub class identifier -
  c_bi_class_btrfs_sub = class_base_idx++;

  return true;
}/*}}}*/

// - BTRFS_UTIL print exception -
bool btrfs_util_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_BTRFS_UTIL_REALPATH_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nBtrfs, retrieve realpath error\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_BTRFS_UTIL_CREATE_SUBVOLUME_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nBtrfs, create subvolume: %s\n",
        btrfs_util_strerror((enum btrfs_util_error)exception.params[0]));
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_BTRFS_UTIL_DELETE_SUBVOLUME_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nBtrfs, delete subvolume: %s\n",
        btrfs_util_strerror((enum btrfs_util_error)exception.params[0]));
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_BTRFS_UTIL_SUB_IS_NOT_SUBVOLUME:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nBtrfsSub, given path is not btrfs subvolume\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_BTRFS_UTIL_SUB_GET_ID_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nBtrfsSub, get id: %s\n",
        btrfs_util_strerror((enum btrfs_util_error)exception.params[0]));
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_BTRFS_UTIL_SUB_GET_READ_ONLY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nBtrfsSub, get read only: %s\n",
        btrfs_util_strerror((enum btrfs_util_error)exception.params[0]));
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_BTRFS_UTIL_SUB_SET_READ_ONLY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nBtrfsSub, set read only: %s\n",
        btrfs_util_strerror((enum btrfs_util_error)exception.params[0]));
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_BTRFS_UTIL_SUB_SNAPSHOT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nBtrfsSub, snapshot: %s\n",
        btrfs_util_strerror((enum btrfs_util_error)exception.params[0]));
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_BTRFS_UTIL_SUB_DELETE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nBtrfsSub, delete: %s\n",
        btrfs_util_strerror((enum btrfs_util_error)exception.params[0]));
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
  5, btrfs_methods,
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
    "create_sub#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_btrfs_method_create_sub_1
  },
  {
    "delete_sub#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_btrfs_method_delete_sub_1
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

  enum btrfs_util_error err;

  if (src_0_location->v_type == c_bi_class_string)
  {
    // - subvolume by path -
    string_s *path_str = (string_s *)src_0_location->v_data_ptr;
    err = btrfs_util_is_subvolume(path_str->data);
  }
  else
  {
    // - subvolume by fd -
    err = btrfs_util_is_subvolume_fd(subvolume);
  }

  long long int result = err == BTRFS_UTIL_OK;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_btrfs_method_create_sub_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
path:c_bi_class_string
>
class c_bi_class_btrfs
method create_sub
static_method
; @end

  string_s *path_str = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  enum btrfs_util_error err;
  if ((err = btrfs_util_create_subvolume(path_str->data,0,nullptr,nullptr)) != BTRFS_UTIL_OK)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_BTRFS_UTIL_CREATE_SUBVOLUME_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(err);

    return false;
  }

  // - ERROR -
  char *abs_path = realpath(path_str->data,nullptr);
  if (abs_path == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_BTRFS_UTIL_REALPATH_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create btrfs sub object -
  btrfs_sub_s *bs_ptr = (btrfs_sub_s *)cmalloc(sizeof(btrfs_sub_s));
  bs_ptr->init();

  // - set subvolume absolute path -
  bs_ptr->path.set(strlen(abs_path),abs_path);
  free(abs_path);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_btrfs_sub,bs_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_btrfs_method_delete_sub_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
path:c_bi_class_string
>
class c_bi_class_btrfs
method delete_sub
static_method
; @end

  string_s *path_str = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  enum btrfs_util_error err;
  if ((err = btrfs_util_delete_subvolume(path_str->data,0)) != BTRFS_UTIL_OK)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_BTRFS_UTIL_DELETE_SUBVOLUME_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(err);

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

// - class BTRFS_SUB -
built_in_class_s btrfs_sub_class =
{/*{{{*/
  "BtrfsSub",
  c_modifier_public | c_modifier_final,
  9, btrfs_sub_methods,
  0, btrfs_sub_variables,
  bic_btrfs_sub_consts,
  bic_btrfs_sub_init,
  bic_btrfs_sub_clear,
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

built_in_method_s btrfs_sub_methods[] =
{/*{{{*/
  {
    "BtrfsSub#1",
    c_modifier_public | c_modifier_final,
    bic_btrfs_sub_method_BtrfsSub_1
  },
  {
    "is_sub#0",
    c_modifier_public | c_modifier_final,
    bic_btrfs_sub_method_is_sub_0
  },
  {
    "id#0",
    c_modifier_public | c_modifier_final,
    bic_btrfs_sub_method_id_0
  },
  {
    "read_only#0",
    c_modifier_public | c_modifier_final,
    bic_btrfs_sub_method_read_only_0
  },
  {
    "read_only#1",
    c_modifier_public | c_modifier_final,
    bic_btrfs_sub_method_read_only_1
  },
  {
    "snapshot#2",
    c_modifier_public | c_modifier_final,
    bic_btrfs_sub_method_snapshot_2
  },
  {
    "delete#0",
    c_modifier_public | c_modifier_final,
    bic_btrfs_sub_method_delete_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_btrfs_sub_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_btrfs_sub_method_print_0
  },
};/*}}}*/

built_in_variable_s btrfs_sub_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_btrfs_sub_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_btrfs_sub_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (btrfs_sub_s *)nullptr;
}/*}}}*/

void bic_btrfs_sub_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  btrfs_sub_s *bs_ptr = (btrfs_sub_s *)location_ptr->v_data_ptr;

  if (bs_ptr != nullptr)
  {
    bs_ptr->clear(it);
    cfree(bs_ptr);
  }
}/*}}}*/

bool bic_btrfs_sub_method_BtrfsSub_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
path:c_bi_class_string
>
method BtrfsSub
; @end

  string_s *path_str = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (btrfs_util_is_subvolume(path_str->data) != BTRFS_UTIL_OK)
  {
    exception_s::throw_exception(it,module.error_base + c_error_BTRFS_UTIL_SUB_IS_NOT_SUBVOLUME,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - ERROR -
  char *abs_path = realpath(path_str->data,nullptr);
  if (abs_path == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_BTRFS_UTIL_REALPATH_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create btrfs sub object -
  btrfs_sub_s *bs_ptr = (btrfs_sub_s *)cmalloc(sizeof(btrfs_sub_s));
  bs_ptr->init();

  // - set subvolume absolute path -
  bs_ptr->path.set(strlen(abs_path),abs_path);
  free(abs_path);

  dst_location->v_data_ptr = (btrfs_sub_s *)bs_ptr;

  return true;
}/*}}}*/

bool bic_btrfs_sub_method_is_sub_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  btrfs_sub_s *bs_ptr = (btrfs_sub_s *)dst_location->v_data_ptr;

  long long int result = btrfs_util_is_subvolume(bs_ptr->path.data) == BTRFS_UTIL_OK;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_btrfs_sub_method_id_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  btrfs_sub_s *bs_ptr = (btrfs_sub_s *)dst_location->v_data_ptr;

  uint64_t id_ret = 0;

  // - ERROR -
  enum btrfs_util_error err;
  if ((err = btrfs_util_subvolume_id(bs_ptr->path.data,&id_ret)) != BTRFS_UTIL_OK)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_BTRFS_UTIL_SUB_GET_ID_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(err);

    return false;
  }

  long long int result = id_ret;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_btrfs_sub_method_read_only_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  btrfs_sub_s *bs_ptr = (btrfs_sub_s *)dst_location->v_data_ptr;

  bool ret = false;

  // - ERROR -
  enum btrfs_util_error err;
  if ((err = btrfs_util_get_subvolume_read_only(bs_ptr->path.data,&ret)) != BTRFS_UTIL_OK)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_BTRFS_UTIL_SUB_GET_READ_ONLY_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(err);

    return false;
  }

  long long int result = ret;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_btrfs_sub_method_read_only_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
read_only:retrieve_integer
>
method read_only
; @end

  btrfs_sub_s *bs_ptr = (btrfs_sub_s *)dst_location->v_data_ptr;

  // - ERROR -
  enum btrfs_util_error err;
  if ((err = btrfs_util_set_subvolume_read_only(bs_ptr->path.data,read_only != 0)) != BTRFS_UTIL_OK)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_BTRFS_UTIL_SUB_SET_READ_ONLY_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(err);

    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_btrfs_sub_method_snapshot_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
path:c_bi_class_string
flags:retrieve_integer
>
method read_only
; @end

  string_s *path_str = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  enum btrfs_util_error err;
  if ((err = btrfs_util_create_snapshot(
      ((btrfs_sub_s *)dst_location->v_data_ptr)->path.data,
      path_str->data,flags,nullptr,nullptr)) != BTRFS_UTIL_OK)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_BTRFS_UTIL_SUB_SNAPSHOT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(err);

    return false;
  }

  // - ERROR -
  char *abs_path = realpath(path_str->data,nullptr);
  if (abs_path == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_BTRFS_UTIL_REALPATH_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create btrfs sub object -
  btrfs_sub_s *bs_ptr = (btrfs_sub_s *)cmalloc(sizeof(btrfs_sub_s));
  bs_ptr->init();

  // - set subvolume absolute path -
  bs_ptr->path.set(strlen(abs_path),abs_path);
  free(abs_path);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_btrfs_sub,bs_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_btrfs_sub_method_delete_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  btrfs_sub_s *bs_ptr = (btrfs_sub_s *)dst_location->v_data_ptr;

  // - ERROR -
  enum btrfs_util_error err;
  if ((err = btrfs_util_delete_subvolume(bs_ptr->path.data,0)) != BTRFS_UTIL_OK)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_BTRFS_UTIL_SUB_DELETE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(err);

    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_btrfs_sub_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("BtrfsSub"),"BtrfsSub");
  );

  return true;
}/*}}}*/

bool bic_btrfs_sub_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("BtrfsSub");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

