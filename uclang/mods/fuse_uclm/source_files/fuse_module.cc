
@begin
include "fuse_module.h"
@end

// - FUSE indexes of built in classes -
unsigned c_bi_class_fuse_channel = c_idx_not_exist;
unsigned c_bi_class_fuse_ops = c_idx_not_exist;
unsigned c_bi_class_fuse_handle = c_idx_not_exist;
unsigned c_bi_class_fuse_stat = c_idx_not_exist;
unsigned c_bi_class_fuse_file_info = c_idx_not_exist;
unsigned c_bi_class_fuse_dir_filler = c_idx_not_exist;
unsigned c_bi_class_fuse_file_filler = c_idx_not_exist;

// - FUSE module -
built_in_module_s module =
{/*{{{*/
  7,                    // Class count
  fuse_classes,         // Classes

  0,                    // Error base index
  14,                   // Error count
  fuse_error_strings,   // Error strings

  fuse_initialize,      // Initialize function
  fuse_print_exception, // Print exceptions function
};/*}}}*/

// - FUSE classes -
built_in_class_s *fuse_classes[] =
{/*{{{*/
  &fuse_channel_class,
  &fuse_ops_class,
  &fuse_handle_class,
  &fuse_stat_class,
  &fuse_file_info_class,
  &fuse_dir_filler_class,
  &fuse_file_filler_class,
};/*}}}*/

// - FUSE error strings -
const char *fuse_error_strings[] =
{/*{{{*/
  "error_FUSE_ARG_EXPECTED_STRING",
  "error_FUSE_CHANNEL_CREATE_ERROR",
  "error_FUSE_CHANNEL_ALREADY_ATTACHED",
  "error_FUSE_OPS_WRONG_OPERATIONS_ARRAY_SIZE",
  "error_FUSE_OPS_WRONG_OPERATIONS_ARRAY_CONTENT",
  "error_FUSE_OPS_UNSUPPORTED_OPERATION",
  "error_FUSE_OPS_DELEGATE_WRONG_PARAM_CNT",
  "error_FUSE_OPS_DELEGATE_ALREADY_ASSIGNED_TO_OPERATION",
  "error_FUSE_HANDLE_CREATE_ERROR",
  "error_FUSE_HANDLE_GET_OUTSIDE_OF_FILESYS_OPERATION",
  "error_FUSE_HANDLE_LOOP_ALREADY_RUNNING",
  "error_FUSE_HANDLE_LOOP_ERROR",
  "error_FUSE_HANDLE_CALLBACK_WRONG_RETURN_VALUE",
  "error_FUSE_DIR_FILLER_FILL_ERROR",
};/*}}}*/

// - FUSE initialize -
bool fuse_initialize(script_parser_s &sp)
{/*{{{*/

  // - initialize external error identifiers -
  c_ext_error_FUSE_HANDLE_CALLBACK_WRONG_RETURN_VALUE =
    module.error_base + c_error_FUSE_HANDLE_CALLBACK_WRONG_RETURN_VALUE;

  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize fuse_channel class identifier -
  c_bi_class_fuse_channel = class_base_idx++;

  // - initialize fuse_ops class identifier -
  c_bi_class_fuse_ops = class_base_idx++;

  // - initialize fuse_handle class identifier -
  c_bi_class_fuse_handle = class_base_idx++;

  // - initialize fuse_stat class identifier -
  c_bi_class_fuse_stat = class_base_idx++;

  // - initialize fuse_file_info class identifier -
  c_bi_class_fuse_file_info = class_base_idx++;

  // - initialize fuse_dir_filler class identifier -
  c_bi_class_fuse_dir_filler = class_base_idx++;

  // - initialize fuse_file_filler class identifier -
  c_bi_class_fuse_file_filler = class_base_idx++;

  return true;
}/*}}}*/

// - FUSE print exception -
bool fuse_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_FUSE_ARG_EXPECTED_STRING:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nExpected string as command line argument at position %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FUSE_CHANNEL_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot create requested fuse channel\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FUSE_CHANNEL_ALREADY_ATTACHED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFuse channel is already attached to fuse handle\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FUSE_OPS_WRONG_OPERATIONS_ARRAY_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong size of fuse operations array\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FUSE_OPS_WRONG_OPERATIONS_ARRAY_CONTENT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong content of fuse operations array\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FUSE_OPS_UNSUPPORTED_OPERATION:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUnsupported fuse operation with id %" HOST_LL_FORMAT "d, at position %" HOST_LL_FORMAT "d\n",exception.params[0],exception.params[1]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FUSE_OPS_DELEGATE_WRONG_PARAM_CNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong count of delegate parameters, expected %" HOST_LL_FORMAT "d parameter/s, at position %" HOST_LL_FORMAT "d\n",exception.params[0],exception.params[1]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FUSE_OPS_DELEGATE_ALREADY_ASSIGNED_TO_OPERATION:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nDelegate is already assigned to operation %" HOST_LL_FORMAT "d, at position %" HOST_LL_FORMAT "d\n",exception.params[0],exception.params[1]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FUSE_HANDLE_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot create fuse handle\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FUSE_HANDLE_GET_OUTSIDE_OF_FILESYS_OPERATION:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot retrieve fuse handle outside of filesystem operation\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FUSE_HANDLE_LOOP_ALREADY_RUNNING:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFuse handle loop is already running\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FUSE_HANDLE_LOOP_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError received in fuse handle loop\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FUSE_HANDLE_CALLBACK_WRONG_RETURN_VALUE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nFuse callback delegate does not return integer\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FUSE_DIR_FILLER_FILL_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while adding directory to fuse directory filler\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class FUSE_CHANNEL -
built_in_class_s fuse_channel_class =
{/*{{{*/
  "FuseChannel",
  c_modifier_public | c_modifier_final,
  4, fuse_channel_methods,
  0, fuse_channel_variables,
  bic_fuse_channel_consts,
  bic_fuse_channel_init,
  bic_fuse_channel_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s fuse_channel_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_fuse_channel_operator_binary_equal
  },
  {
    "FuseChannel#2",
    c_modifier_public | c_modifier_final,
    bic_fuse_channel_method_FuseChannel_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_fuse_channel_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_fuse_channel_method_print_0
  },
};/*}}}*/

built_in_variable_s fuse_channel_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_FUSE_CONSTRUCT_ARGV(ARRAY_PTR) \
/*{{{*/\
  int argc = ARRAY_PTR->used;\
  char *argv[argc + 1];\
  \
  if (ARRAY_PTR->used != 0)\
  {\
    /* - process arguments array - */\
    pointer *a_ptr = ARRAY_PTR->data;\
    pointer *a_ptr_end = a_ptr + ARRAY_PTR->used;\
    char **arg_ptr = argv;\
\
    do {\
      location_s *item_location = it.get_location_value(*a_ptr);\
\
      /* - ERROR - */\
      if (item_location->v_type != c_bi_class_string)\
      {\
        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FUSE_ARG_EXPECTED_STRING,operands[c_source_pos_idx],(location_s *)it.blank_location);\
        new_exception->params.push(a_ptr - ARRAY_PTR->data);\
\
        return false;\
      }\
\
      /* - set argument pointer - */\
      *arg_ptr = ((string_s *)item_location->v_data_ptr)->data;\
\
    } while(++arg_ptr,++a_ptr < a_ptr_end);\
  }\
\
  /* - set terminating pointer - */\
  argv[argc] = NULL;\
/*}}}*/

void bic_fuse_channel_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_fuse_channel_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (fuse_channel_s *)NULL;
}/*}}}*/

void bic_fuse_channel_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  fuse_channel_s *fch_ptr = (fuse_channel_s *)location_ptr->v_data_ptr;

  if (fch_ptr != NULL)
  {
    fch_ptr->clear(it);
    cfree(fch_ptr);
  }
}/*}}}*/

bool bic_fuse_channel_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_fuse_channel_method_FuseChannel_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  if (src_0_location->v_type != c_bi_class_string ||
      src_1_location->v_type != c_bi_class_array)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("FuseChannel#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  string_s *mountpoint = (string_s *)src_0_location->v_data_ptr;
  pointer_array_s *arg_array = (pointer_array_s *)src_1_location->v_data_ptr;

  BIC_FUSE_CONSTRUCT_ARGV(arg_array);

  // - create fuse channel object -
  fuse_channel_s *fch_ptr = (fuse_channel_s *)cmalloc(sizeof(fuse_channel_s));
  fch_ptr->init();

  fuse_args fargs = FUSE_ARGS_INIT(argc,argv);
  fch_ptr->fuse_chan_ptr = fuse_mount(mountpoint->data,&fargs);

  // - ERROR -
  if (fch_ptr->fuse_chan_ptr == NULL)
  {
    fch_ptr->clear(it);
    cfree(fch_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_FUSE_CHANNEL_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - copy fuse channel mountpoint -
  fch_ptr->mountpoint = *mountpoint;

  dst_location->v_data_ptr = (fuse_channel_s *)fch_ptr;

  return true;
}/*}}}*/

bool bic_fuse_channel_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("FuseChannel"),"FuseChannel");
  );

  return true;
}/*}}}*/

bool bic_fuse_channel_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("FuseChannel");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class FUSE_OPS -
built_in_class_s fuse_ops_class =
{/*{{{*/
  "FuseOps",
  c_modifier_public | c_modifier_final,
  4, fuse_ops_methods,
  44, fuse_ops_variables,
  bic_fuse_ops_consts,
  bic_fuse_ops_init,
  bic_fuse_ops_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s fuse_ops_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_fuse_ops_operator_binary_equal
  },
  {
    "FuseOps#1",
    c_modifier_public | c_modifier_final,
    bic_fuse_ops_method_FuseOps_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_fuse_ops_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_fuse_ops_method_print_0
  },
};/*}}}*/

built_in_variable_s fuse_ops_variables[] =
{/*{{{*/
  { "GETATTR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "READLINK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GETDIR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MKNOD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "MKDIR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "UNLINK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "RMDIR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SYMLINK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "RENAME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "LINK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CHMOD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CHOWN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TRUNCATE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "UTIME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPEN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "READ", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "WRITE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "STATFS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FLUSH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "RELEASE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FSYNC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "SETXATTR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "GETXATTR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "LISTXATTR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "REMOVEXATTR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "OPENDIR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "READDIR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "RELEASEDIR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FSYNCDIR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "INIT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "DESTROY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ACCESS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "CREATE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FTRUNCATE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FGETATTR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "LOCK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "UTIMENS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "BMAP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IOCTL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "POLL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "WRITE_BUF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "READ_BUF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FLOCK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FALLOCATE", c_modifier_public | c_modifier_static | c_modifier_static_const },
};/*}}}*/

void bic_fuse_ops_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert fuse operation type constants -
  {
    const_locations.push_blanks(44);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 44);

#define CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_getattr);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_readlink);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_getdir);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_mknod);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_mkdir);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_unlink);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_rmdir);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_symlink);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_rename);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_link);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_chmod);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_chown);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_truncate);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_utime);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_open);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_read);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_write);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_statfs);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_flush);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_release);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_fsync);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_setxattr);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_getxattr);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_listxattr);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_removexattr);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_opendir);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_readdir);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_releasedir);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_fsyncdir);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_init);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_destroy);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_access);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_create);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_ftruncate);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_fgetattr);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_lock);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_utimens);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_bmap);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_ioctl);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_poll);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_write_buf);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_read_buf);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_flock);
    CREATE_FUSE_OPS_OPERATION_TYPE_BIC_STATIC(c_fuse_fallocate);
  }
}/*}}}*/

void bic_fuse_ops_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (fuse_operations_s *)NULL;
}/*}}}*/

void bic_fuse_ops_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  fuse_operations_s *fops_ptr = (fuse_operations_s *)location_ptr->v_data_ptr;

  if (fops_ptr != NULL)
  {
    fops_ptr->clear(it);
    cfree(fops_ptr);
  }
}/*}}}*/

bool bic_fuse_ops_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_fuse_ops_method_FuseOps_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_array)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("FuseOps#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  pointer_array_s *array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (array_ptr->used & 0x01)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FUSE_OPS_WRONG_OPERATIONS_ARRAY_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create fuse operations object -
  fuse_operations_s *fops_ptr = (fuse_operations_s *)cmalloc(sizeof(fuse_operations_s));
  fops_ptr->init();

  // - install fuse init callback -
  fops_ptr->fuse_ops.init = fuse_handle_s::cb_fuse_init;

  // - initialize operations delegates -
  fops_ptr->fuse_ops_dlgs.copy_resize(c_fuse_ops_count);
  fops_ptr->fuse_ops_dlgs.fill(NULL);

#define BIC_FUSE_OPS_INSTALL_CALLBACK(NAME,PARAM_CNT) \
/*{{{*/\
  case c_fuse_ ## NAME:\
    {\
      delegate_s *delegate_ptr = (delegate_s *)dlg_location->v_data_ptr;\
\
      /* - ERROR - */\
      if (delegate_ptr->param_cnt != PARAM_CNT)\
      {\
        fops_ptr->clear(it);\
        cfree(fops_ptr);\
\
        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FUSE_OPS_DELEGATE_WRONG_PARAM_CNT,operands[c_source_pos_idx],(location_s *)it.blank_location);\
        new_exception->params.push(PARAM_CNT);\
        new_exception->params.push((p_ptr - array_ptr->data) / 2);\
\
        return false;\
      }\
\
      /* - ERROR - */\
      if (fops_ptr->fuse_ops_dlgs[c_fuse_ ## NAME] != NULL)\
      {\
        fops_ptr->clear(it);\
        cfree(fops_ptr);\
\
        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FUSE_OPS_DELEGATE_ALREADY_ASSIGNED_TO_OPERATION,operands[c_source_pos_idx],(location_s *)it.blank_location);\
        new_exception->params.push(id);\
        new_exception->params.push((p_ptr - array_ptr->data) / 2);\
\
        return false;\
      }\
\
      /* - install fuse callback - */\
      fops_ptr->fuse_ops.NAME = fuse_handle_s::cb_fuse_ ## NAME;\
\
      /* - store callback delegate - */\
      dlg_location->v_reference_cnt.atomic_inc();\
      fops_ptr->fuse_ops_dlgs[c_fuse_ ## NAME] = dlg_location;\
    }\
    break;\
/*}}}*/

  if (array_ptr->used != 0)
  {
    pointer *p_ptr = array_ptr->data;
    pointer *p_ptr_end = p_ptr + array_ptr->used;
    do {
      location_s *id_location = it.get_location_value(p_ptr[0]);
      location_s *dlg_location = it.get_location_value(p_ptr[1]);

      long long int id;

      // - ERROR -
      if (!it.retrieve_integer(id_location,id) ||
          dlg_location->v_type != c_bi_class_delegate)
      {
        fops_ptr->clear(it);
        cfree(fops_ptr);

        exception_s::throw_exception(it,module.error_base + c_error_FUSE_OPS_WRONG_OPERATIONS_ARRAY_CONTENT,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      // - process operation identifier -
      switch (id)
      {
        BIC_FUSE_OPS_INSTALL_CALLBACK(init,0);
        BIC_FUSE_OPS_INSTALL_CALLBACK(getattr,2);
        BIC_FUSE_OPS_INSTALL_CALLBACK(readdir,3);
        BIC_FUSE_OPS_INSTALL_CALLBACK(open,2);
        BIC_FUSE_OPS_INSTALL_CALLBACK(release,2);
        BIC_FUSE_OPS_INSTALL_CALLBACK(opendir,2);
        BIC_FUSE_OPS_INSTALL_CALLBACK(releasedir,2);
        BIC_FUSE_OPS_INSTALL_CALLBACK(read,3);
        BIC_FUSE_OPS_INSTALL_CALLBACK(write,4);
        BIC_FUSE_OPS_INSTALL_CALLBACK(create,3);
        BIC_FUSE_OPS_INSTALL_CALLBACK(unlink,1);
        BIC_FUSE_OPS_INSTALL_CALLBACK(mkdir,2);
        BIC_FUSE_OPS_INSTALL_CALLBACK(rmdir,1);
        BIC_FUSE_OPS_INSTALL_CALLBACK(rename,2);
        BIC_FUSE_OPS_INSTALL_CALLBACK(truncate,2);
        BIC_FUSE_OPS_INSTALL_CALLBACK(chmod,2);
        BIC_FUSE_OPS_INSTALL_CALLBACK(chown,3);
        BIC_FUSE_OPS_INSTALL_CALLBACK(utimens,3);

        // - ERROR -
        default:

          fops_ptr->clear(it);
          cfree(fops_ptr);

          exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FUSE_OPS_UNSUPPORTED_OPERATION,operands[c_source_pos_idx],(location_s *)it.blank_location);
          new_exception->params.push(id);
          new_exception->params.push((p_ptr - array_ptr->data) / 2);

          return false;
      }

    } while((p_ptr += 2) < p_ptr_end);
  }

  dst_location->v_data_ptr = (fuse_operations_s *)fops_ptr;

  return true;
}/*}}}*/

bool bic_fuse_ops_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("FuseOps"),"FuseOps");
  );

  return true;
}/*}}}*/

bool bic_fuse_ops_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("FuseOps");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class FUSE_HANDLE -
built_in_class_s fuse_handle_class =
{/*{{{*/
  "FuseHandle",
  c_modifier_public | c_modifier_final,
  7, fuse_handle_methods,
  57, fuse_handle_variables,
  bic_fuse_handle_consts,
  bic_fuse_handle_init,
  bic_fuse_handle_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s fuse_handle_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_fuse_handle_operator_binary_equal
  },
  {
    "FuseHandle#3",
    c_modifier_public | c_modifier_final,
    bic_fuse_handle_method_FuseHandle_3
  },
  {
    "get_handle#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_fuse_handle_method_get_handle_0
  },
  {
    "private_data#0",
    c_modifier_public | c_modifier_final,
    bic_fuse_handle_method_private_data_0
  },
  {
    "loop#0",
    c_modifier_public | c_modifier_final,
    bic_fuse_handle_method_loop_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_fuse_handle_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_fuse_handle_method_print_0
  },
};/*}}}*/

built_in_variable_s fuse_handle_variables[] =
{/*{{{*/
  { "EPERM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ENOENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ESRCH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EINTR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EIO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ENXIO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "E2BIG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ENOEXEC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EBADF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ECHILD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EAGAIN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ENOMEM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EACCES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EFAULT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ENOTBLK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EBUSY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EEXIST", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EXDEV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ENODEV", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ENOTDIR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EISDIR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EINVAL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ENFILE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EMFILE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ENOTTY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ETXTBSY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EFBIG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ENOSPC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ESPIPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EROFS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EMLINK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EPIPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EDOM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ERANGE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EDEADLK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ENAMETOOLONG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ENOLCK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ENOSYS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ENOTEMPTY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ELOOP", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EWOULDBLOCK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ENOMSG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EIDRM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ECHRNG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EL2NSYNC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EL3HLT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EL3RST", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ELNRNG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EUNATCH", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ENOCSI", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EL2HLT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EBADE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EBADR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EXFULL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "ENOANO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EBADRQC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EBADSLT", c_modifier_public | c_modifier_static | c_modifier_static_const },
};/*}}}*/

void bic_fuse_handle_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert fuse handle error type constants -
  {
    const_locations.push_blanks(57);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 57);

#define CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(EPERM);        /* Operation not permitted */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(ENOENT);       /* No such file or directory */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(ESRCH);        /* No such process */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(EINTR);        /* Interrupted system call */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(EIO);          /* I/O error */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(ENXIO);        /* No such device or address */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(E2BIG);        /* Argument list too long */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(ENOEXEC);      /* Exec format error */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(EBADF);        /* Bad file number */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(ECHILD);       /* No child processes */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(EAGAIN);       /* Try again */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(ENOMEM);       /* Out of memory */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(EACCES);       /* Permission denied */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(EFAULT);       /* Bad address */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(ENOTBLK);      /* Block device required */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(EBUSY);        /* Device or resource busy */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(EEXIST);       /* File exists */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(EXDEV);        /* Cross-device link */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(ENODEV);       /* No such device */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(ENOTDIR);      /* Not a directory */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(EISDIR);       /* Is a directory */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(EINVAL);       /* Invalid argument */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(ENFILE);       /* File table overflow */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(EMFILE);       /* Too many open files */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(ENOTTY);       /* Not a typewriter */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(ETXTBSY);      /* Text file busy */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(EFBIG);        /* File too large */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(ENOSPC);       /* No space left on device */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(ESPIPE);       /* Illegal seek */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(EROFS);        /* Read-only file system */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(EMLINK);       /* Too many links */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(EPIPE);        /* Broken pipe */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(EDOM);         /* Math argument out of domain of func */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(ERANGE);       /* Math result not representable */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(EDEADLK);      /* Resource deadlock would occur */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(ENAMETOOLONG); /* File name too long */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(ENOLCK);       /* No record locks available */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(ENOSYS);       /* Function not implemented */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(ENOTEMPTY);    /* Directory not empty */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(ELOOP);        /* Too many symbolic links encountered */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(EWOULDBLOCK);  /* Operation would block */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(ENOMSG);       /* No message of desired type */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(EIDRM);        /* Identifier removed */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(ECHRNG);       /* Channel number out of range */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(EL2NSYNC);     /* Level 2 not synchronized */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(EL3HLT);       /* Level 3 halted */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(EL3RST);       /* Level 3 reset */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(ELNRNG);       /* Link number out of range */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(EUNATCH);      /* Protocol driver not attached */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(ENOCSI);       /* No CSI structure available */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(EL2HLT);       /* Level 2 halted */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(EBADE);        /* Invalid exchange */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(EBADR);        /* Invalid request descriptor */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(EXFULL);       /* Exchange full */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(ENOANO);       /* No anode */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(EBADRQC);      /* Invalid request code */
    CREATE_FUSE_HANDLE_ERROR_TYPE_BIC_STATIC(EBADSLT);      /* Invalid slot */
  }
}/*}}}*/

void bic_fuse_handle_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (fuse_handle_s *)NULL;
}/*}}}*/

void bic_fuse_handle_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  fuse_handle_s *fhnd_ptr = (fuse_handle_s *)location_ptr->v_data_ptr;

  if (fhnd_ptr != NULL)
  {
    fhnd_ptr->clear(it);
    cfree(fhnd_ptr);
  }
}/*}}}*/

bool bic_fuse_handle_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_fuse_handle_method_FuseHandle_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);

  if (src_0_location->v_type != c_bi_class_fuse_channel ||
      src_1_location->v_type != c_bi_class_fuse_ops ||
      src_2_location->v_type != c_bi_class_array)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("FuseHandle#3");
    new_exception->params.push(3);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);

    return false;
  }

  fuse_channel_s *fch_ptr = (fuse_channel_s *)src_0_location->v_data_ptr;
  fuse_operations_s *fops_ptr = (fuse_operations_s *)src_1_location->v_data_ptr;
  pointer_array_s *arg_array = (pointer_array_s *)src_2_location->v_data_ptr;

  BIC_FUSE_CONSTRUCT_ARGV(arg_array);

  // - ERROR -
  if (fch_ptr->attached)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FUSE_CHANNEL_ALREADY_ATTACHED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create fuse handle object -
  fuse_handle_s *fhnd_ptr = (fuse_handle_s *)cmalloc(sizeof(fuse_handle_s));
  fhnd_ptr->init();

  fuse_args fargs = FUSE_ARGS_INIT(argc,argv);
  fhnd_ptr->fuse_ptr = fuse_new(fch_ptr->fuse_chan_ptr,&fargs,&fops_ptr->fuse_ops,sizeof(fops_ptr->fuse_ops),dst_location);

  // - ERROR -
  if (fhnd_ptr->fuse_ptr == NULL)
  {
    fhnd_ptr->clear(it);
    cfree(fhnd_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_FUSE_HANDLE_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set fuse channel as attached -
  fch_ptr->attached = true;

  // - set fuse channel reference -
  src_0_location->v_reference_cnt.atomic_inc();
  fhnd_ptr->fuse_channel_ptr = src_0_location;

  // - set fuse operations reference -
  src_1_location->v_reference_cnt.atomic_inc();
  fhnd_ptr->fuse_operations_ptr = src_1_location;

  // - set private data location -
  ((location_s *)it.blank_location)->v_reference_cnt.atomic_inc();
  fhnd_ptr->private_data_ptr = (location_s *)it.blank_location;

  dst_location->v_data_ptr = (fuse_handle_s *)fhnd_ptr;

  return true;
}/*}}}*/

bool bic_fuse_handle_method_get_handle_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  struct fuse_context *fctx_ptr = fuse_get_context();

  // - ERROR -
  if (fctx_ptr == NULL || fctx_ptr->private_data == NULL)
  {
    if (fctx_ptr) free(fctx_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_FUSE_HANDLE_GET_OUTSIDE_OF_FILESYS_OPERATION,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  location_s *fhnd_location = (location_s *)fctx_ptr->private_data;
  fhnd_location->v_reference_cnt.atomic_inc();

  BIC_SET_RESULT(fhnd_location);

  return true;
}/*}}}*/

bool bic_fuse_handle_method_private_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  fuse_handle_s *fhnd_ptr = (fuse_handle_s *)dst_location->v_data_ptr;

  location_s *new_ref_location = it.get_new_reference(&fhnd_ptr->private_data_ptr);

  BIC_SET_RESULT(new_ref_location);

  return true;
}/*}}}*/

bool bic_fuse_handle_method_loop_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  unsigned res_loc_idx = stack_base + operands[c_res_op_idx];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve fuse handle -
  fuse_handle_s *fhnd_ptr = (fuse_handle_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (fhnd_ptr->it_ptr != NULL)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FUSE_HANDLE_LOOP_ALREADY_RUNNING,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set fuse handle it pointer -
  fhnd_ptr->it_ptr = &it;
  fhnd_ptr->source_pos = operands[c_source_pos_idx];
  fhnd_ptr->ret_code = c_run_return_code_OK;

  // - ERROR -
  if (fuse_loop(fhnd_ptr->fuse_ptr) != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FUSE_HANDLE_LOOP_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - reset fuse handle it pointer -
  fhnd_ptr->it_ptr = NULL;

  // - if exception occurred -
  if (fhnd_ptr->ret_code == c_run_return_code_EXCEPTION)
  {
    return false;
  }

  pointer &res_location = it.data_stack[res_loc_idx];
  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_fuse_handle_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("FuseHandle"),"FuseHandle");
  );

  return true;
}/*}}}*/

bool bic_fuse_handle_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("FuseHandle");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class FUSE_STAT -
built_in_class_s fuse_stat_class =
{/*{{{*/
  "FuseStat",
  c_modifier_public | c_modifier_final,
  11, fuse_stat_methods,
  8, fuse_stat_variables,
  bic_fuse_stat_consts,
  bic_fuse_stat_init,
  bic_fuse_stat_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s fuse_stat_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_fuse_stat_operator_binary_equal
  },
  {
    "st_mode#1",
    c_modifier_public | c_modifier_final,
    bic_fuse_stat_method_st_mode_1
  },
  {
    "st_nlink#1",
    c_modifier_public | c_modifier_final,
    bic_fuse_stat_method_st_nlink_1
  },
  {
    "st_uid#1",
    c_modifier_public | c_modifier_final,
    bic_fuse_stat_method_st_uid_1
  },
  {
    "st_gid#1",
    c_modifier_public | c_modifier_final,
    bic_fuse_stat_method_st_gid_1
  },
  {
    "st_size#1",
    c_modifier_public | c_modifier_final,
    bic_fuse_stat_method_st_size_1
  },
  {
    "st_atime#1",
    c_modifier_public | c_modifier_final,
    bic_fuse_stat_method_st_atime_1
  },
  {
    "st_mtime#1",
    c_modifier_public | c_modifier_final,
    bic_fuse_stat_method_st_mtime_1
  },
  {
    "st_ctime#1",
    c_modifier_public | c_modifier_final,
    bic_fuse_stat_method_st_ctime_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_fuse_stat_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_fuse_stat_method_print_0
  },
};/*}}}*/

built_in_variable_s fuse_stat_variables[] =
{/*{{{*/
  { "S_IFMT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "S_IFSOCK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "S_IFLNK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "S_IFREG", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "S_IFBLK", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "S_IFDIR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "S_IFCHR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "S_IFIFO", c_modifier_public | c_modifier_static | c_modifier_static_const },
};/*}}}*/

#define BIC_FUSE_STAT_SET_VALUE(NAME,VALUE) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
  long long int value;\
\
  if (!it.retrieve_integer(src_0_location,value))\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
    new_exception->params.push(1);\
    new_exception->params.push(src_0_location->v_type);\
\
    return false;\
  }\
\
  struct stat *st_ptr = (struct stat *)dst_location->v_data_ptr;\
  st_ptr->VALUE = value;\
\
  BIC_SET_RESULT_BLANK();\
\
  return true;\
}/*}}}*/

void bic_fuse_stat_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert fuse stat file type constants -
  {
    const_locations.push_blanks(8);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 8);

#define CREATE_FUSE_STAT_FILE_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_FUSE_STAT_FILE_TYPE_BIC_STATIC(S_IFMT);
    CREATE_FUSE_STAT_FILE_TYPE_BIC_STATIC(S_IFSOCK);
    CREATE_FUSE_STAT_FILE_TYPE_BIC_STATIC(S_IFLNK);
    CREATE_FUSE_STAT_FILE_TYPE_BIC_STATIC(S_IFREG);
    CREATE_FUSE_STAT_FILE_TYPE_BIC_STATIC(S_IFBLK);
    CREATE_FUSE_STAT_FILE_TYPE_BIC_STATIC(S_IFDIR);
    CREATE_FUSE_STAT_FILE_TYPE_BIC_STATIC(S_IFCHR);
    CREATE_FUSE_STAT_FILE_TYPE_BIC_STATIC(S_IFIFO);
  }
}/*}}}*/

void bic_fuse_stat_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_fuse_stat_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

bool bic_fuse_stat_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_fuse_stat_method_st_mode_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FUSE_STAT_SET_VALUE("st_mode#1",st_mode);
}/*}}}*/

bool bic_fuse_stat_method_st_nlink_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FUSE_STAT_SET_VALUE("st_nlink#1",st_nlink);
}/*}}}*/

bool bic_fuse_stat_method_st_uid_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FUSE_STAT_SET_VALUE("st_uid#1",st_uid);
}/*}}}*/

bool bic_fuse_stat_method_st_gid_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FUSE_STAT_SET_VALUE("st_gid#1",st_gid);
}/*}}}*/

bool bic_fuse_stat_method_st_size_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FUSE_STAT_SET_VALUE("st_size#1",st_size);
}/*}}}*/

bool bic_fuse_stat_method_st_atime_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FUSE_STAT_SET_VALUE("st_atime#1",st_atime);
}/*}}}*/

bool bic_fuse_stat_method_st_mtime_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FUSE_STAT_SET_VALUE("st_mtime#1",st_mtime);
}/*}}}*/

bool bic_fuse_stat_method_st_ctime_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FUSE_STAT_SET_VALUE("st_ctime#1",st_ctime);
}/*}}}*/

bool bic_fuse_stat_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("FuseStat"),"FuseStat");
  );

  return true;
}/*}}}*/

bool bic_fuse_stat_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("FuseStat");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class FUSE_FILE_INFO -
built_in_class_s fuse_file_info_class =
{/*{{{*/
  "FuseFileInfo",
  c_modifier_public | c_modifier_final,
  3, fuse_file_info_methods,
  0, fuse_file_info_variables,
  bic_fuse_file_info_consts,
  bic_fuse_file_info_init,
  bic_fuse_file_info_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s fuse_file_info_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_fuse_file_info_operator_binary_equal
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_fuse_file_info_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_fuse_file_info_method_print_0
  },
};/*}}}*/

built_in_variable_s fuse_file_info_variables[] =
{/*{{{*/
};/*}}}*/

void bic_fuse_file_info_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_fuse_file_info_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_fuse_file_info_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

bool bic_fuse_file_info_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_fuse_file_info_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("FuseFileInfo"),"FuseFileInfo");
  );

  return true;
}/*}}}*/

bool bic_fuse_file_info_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("FuseFileInfo");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class FUSE_DIR_FILLER -
built_in_class_s fuse_dir_filler_class =
{/*{{{*/
  "FuseDirFiller",
  c_modifier_public | c_modifier_final,
  5, fuse_dir_filler_methods,
  0, fuse_dir_filler_variables,
  bic_fuse_dir_filler_consts,
  bic_fuse_dir_filler_init,
  bic_fuse_dir_filler_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s fuse_dir_filler_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_fuse_dir_filler_operator_binary_equal
  },
  {
    "offset#0",
    c_modifier_public | c_modifier_final,
    bic_fuse_dir_filler_method_offset_0
  },
  {
    "fill_dir#1",
    c_modifier_public | c_modifier_final,
    bic_fuse_dir_filler_method_fill_dir_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_fuse_dir_filler_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_fuse_dir_filler_method_print_0
  },
};/*}}}*/

built_in_variable_s fuse_dir_filler_variables[] =
{/*{{{*/
};/*}}}*/

void bic_fuse_dir_filler_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_fuse_dir_filler_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_fuse_dir_filler_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  fuse_dir_filler_s *fdf_ptr = (fuse_dir_filler_s *)location_ptr->v_data_ptr;

  if (fdf_ptr != NULL)
  {
    fdf_ptr->clear(it);
    cfree(fdf_ptr);
  }
}/*}}}*/

bool bic_fuse_dir_filler_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_fuse_dir_filler_method_offset_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  fuse_dir_filler_s *fdf_ptr = (fuse_dir_filler_s *)dst_location->v_data_ptr;

  long long int result = fdf_ptr->offset;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_fuse_dir_filler_method_fill_dir_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("fill_dir#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  fuse_dir_filler_s *fdf_ptr = (fuse_dir_filler_s *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (fdf_ptr->filler(fdf_ptr->buffer,string_ptr->data,NULL,0) != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_FUSE_DIR_FILLER_FILL_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_fuse_dir_filler_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("FuseDirFiller"),"FuseDirFiller");
  );

  return true;
}/*}}}*/

bool bic_fuse_dir_filler_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("FuseDirFiller");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class FUSE_FILE_FILLER -
built_in_class_s fuse_file_filler_class =
{/*{{{*/
  "FuseFileFiller",
  c_modifier_public | c_modifier_final,
  7, fuse_file_filler_methods,
  0, fuse_file_filler_variables,
  bic_fuse_file_filler_consts,
  bic_fuse_file_filler_init,
  bic_fuse_file_filler_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s fuse_file_filler_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_fuse_file_filler_operator_binary_equal
  },
  {
    "size#0",
    c_modifier_public | c_modifier_final,
    bic_fuse_file_filler_method_size_0
  },
  {
    "offset#0",
    c_modifier_public | c_modifier_final,
    bic_fuse_file_filler_method_offset_0
  },
  {
    "writed#0",
    c_modifier_public | c_modifier_final,
    bic_fuse_file_filler_method_writed_0
  },
  {
    "write#1",
    c_modifier_public | c_modifier_final,
    bic_fuse_file_filler_method_write_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_fuse_file_filler_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_fuse_file_filler_method_print_0
  },
};/*}}}*/

built_in_variable_s fuse_file_filler_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_FUSE_FILE_FILLER_GET_VALUE(NAME) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  fuse_file_filler_s *fff_ptr = (fuse_file_filler_s *)dst_location->v_data_ptr;\
\
  long long int result = fff_ptr->NAME;\
\
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
\
  return true;\
}/*}}}*/

void bic_fuse_file_filler_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_fuse_file_filler_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_fuse_file_filler_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  fuse_file_filler_s *fff_ptr = (fuse_file_filler_s *)location_ptr->v_data_ptr;

  if (fff_ptr != NULL)
  {
    fff_ptr->clear(it);
    cfree(fff_ptr);
  }
}/*}}}*/

bool bic_fuse_file_filler_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_fuse_file_filler_method_size_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FUSE_FILE_FILLER_GET_VALUE(size);
}/*}}}*/

bool bic_fuse_file_filler_method_offset_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FUSE_FILE_FILLER_GET_VALUE(offset);
}/*}}}*/

bool bic_fuse_file_filler_method_writed_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FUSE_FILE_FILLER_GET_VALUE(writed);
}/*}}}*/

bool bic_fuse_file_filler_method_write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("write#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  fuse_file_filler_s *fff_ptr = (fuse_file_filler_s *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - unused space in target buffer -
  unsigned space = fff_ptr->size - fff_ptr->writed;

  // - if there is unused space -
  if (space > 0)
  {
    unsigned string_len = string_ptr->size - 1;
    unsigned copy_len = string_len > space ? space : string_len;

    memcpy(fff_ptr->buffer + fff_ptr->writed,string_ptr->data,copy_len);
    fff_ptr->writed += copy_len;
  }

  // - return 1 if buffer is full -
  long long int result = fff_ptr->writed >= fff_ptr->size;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_fuse_file_filler_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("FuseFileFiller"),"FuseFileFiller");
  );

  return true;
}/*}}}*/

bool bic_fuse_file_filler_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("FuseFileFiller");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

