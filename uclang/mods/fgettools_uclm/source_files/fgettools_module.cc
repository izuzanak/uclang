
@begin
include "fgettools_module.h"
@end

// - FGETTOOLS indexes of built in classes -
unsigned c_bi_class_fget_target = c_idx_not_exist;

// - FGETTOOLS module -
built_in_module_s module =
{/*{{{*/
  1,                         // Class count
  fgettools_classes,         // Classes

  0,                         // Error base index
  8,                         // Error count
  fgettools_error_strings,   // Error strings

  fgettools_initialize,      // Initialize function
  fgettools_print_exception, // Print exceptions function
};/*}}}*/

// - FGETTOOLS classes -
built_in_class_s *fgettools_classes[] =
{/*{{{*/
  &fget_target_class,
};/*}}}*/

// - FGETTOOLS error strings -
const char *fgettools_error_strings[] =
{/*{{{*/
  "error_FGET_TARGET_INVALID_BLOCK_SIZE",
  "error_FGET_TARGET_CANNOT_OPEN_TARGET_FILE",
  "error_FGET_TARGET_CANNOT_OPEN_MAP_FILE",
  "error_FGET_TARGET_FILES_SIZE_MISMATCH",
  "error_FGET_TARGET_CANNOT_MAP_FILES_TO_MEMORY",
  "error_FGET_TARGET_NEGATIVE_REQUEST_COUNT",
  "error_FGET_TARGET_INVALID_INDEX_VALUE",
  "error_FGET_TARGET_INVALID_BLOCK_INDEX",
};/*}}}*/

// - FGETTOOLS initialize -
bool fgettools_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize fget_target class identifier -
  c_bi_class_fget_target = class_base_idx++;

  return true;
}/*}}}*/

// - FGETTOOLS print exception -
bool fgettools_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_FGET_TARGET_INVALID_BLOCK_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid size %" HOST_LL_FORMAT "d of data block\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FGET_TARGET_CANNOT_OPEN_TARGET_FILE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot open target file \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FGET_TARGET_CANNOT_OPEN_MAP_FILE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot open map file \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FGET_TARGET_FILES_SIZE_MISMATCH:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTarget and map files size mismatch\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FGET_TARGET_CANNOT_MAP_FILES_TO_MEMORY:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while mapping files to memory\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FGET_TARGET_NEGATIVE_REQUEST_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nRequested negative count %" HOST_LL_FORMAT "d of requests\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FGET_TARGET_INVALID_INDEX_VALUE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid index value %" HOST_LL_FORMAT "d cannot be set\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_FGET_TARGET_INVALID_BLOCK_INDEX:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid index %" HOST_LL_FORMAT "d of data block\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class FGET_TARGET -
built_in_class_s fget_target_class =
{/*{{{*/
  "FgetTarget",
  c_modifier_public | c_modifier_final,
  10, fget_target_methods,
  0, fget_target_variables,
  bic_fget_target_consts,
  bic_fget_target_init,
  bic_fget_target_clear,
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

built_in_method_s fget_target_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_fget_target_operator_binary_equal
  },
  {
    "FgetTarget#3",
    c_modifier_public | c_modifier_final,
    bic_fget_target_method_FgetTarget_3
  },
  {
    "index#1",
    c_modifier_public | c_modifier_final,
    bic_fget_target_method_index_1
  },
  {
    "received#1",
    c_modifier_public | c_modifier_final,
    bic_fget_target_method_received_1
  },
  {
    "update_data#2",
    c_modifier_public | c_modifier_final,
    bic_fget_target_method_update_data_2
  },
  {
    "block_cnt#0",
    c_modifier_public | c_modifier_final,
    bic_fget_target_method_block_cnt_0
  },
  {
    "done_cnt#0",
    c_modifier_public | c_modifier_final,
    bic_fget_target_method_done_cnt_0
  },
  {
    "done_percent#0",
    c_modifier_public | c_modifier_final,
    bic_fget_target_method_done_percent_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_fget_target_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_fget_target_method_print_0
  },
};/*}}}*/

built_in_variable_s fget_target_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_FGET_TARGET_RETRIEVE_INTEGER(VALUE) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  fget_target_s *ft_ptr = (fget_target_s *)dst_location->v_data_ptr;\
  long long int result = ft_ptr->VALUE;\
\
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
\
  return true;\
}/*}}}*/

void bic_fget_target_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_fget_target_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (fget_target_s *)nullptr;
}/*}}}*/

void bic_fget_target_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  fget_target_s *ft_ptr = (fget_target_s *)location_ptr->v_data_ptr;

  if (ft_ptr != nullptr)
  {
    ft_ptr->clear(it);
    cfree(ft_ptr);
  }
}/*}}}*/

bool bic_fget_target_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_fget_target_method_FgetTarget_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);

  long long int block_size;

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string ||
      src_1_location->v_type != c_bi_class_string ||
      !it.retrieve_integer(src_2_location,block_size))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("FgetTarget#3");
    new_exception->params.push(3);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);

    return false;
  }

  string_s *file_name_ptr = (string_s *)src_0_location->v_data_ptr;
  string_s *map_name_ptr = (string_s *)src_1_location->v_data_ptr;

  // - ERROR -
  if (block_size <= 0)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FGET_TARGET_INVALID_BLOCK_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(block_size);

    return false;
  }

  struct stat file_st;
  int file_fd = open(file_name_ptr->data,O_RDWR);

  // - ERROR -
  if (file_fd == -1 || fstat(file_fd,&file_st) == -1)
  {
    if (file_fd != -1)
    {
      close(file_fd);
    }

    exception_s::throw_exception(it,module.error_base + c_error_FGET_TARGET_CANNOT_OPEN_TARGET_FILE,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  struct stat map_st;
  int map_fd = open(map_name_ptr->data,O_RDWR);

  // - ERROR -
  if (map_fd == -1 || fstat(map_fd,&map_st) == -1)
  {
    if (map_fd != -1)
    {
      close(map_fd);
    }

    exception_s::throw_exception(it,module.error_base + c_error_FGET_TARGET_CANNOT_OPEN_MAP_FILE,operands[c_source_pos_idx],src_1_location);
    return false;
  }

  unsigned file_size = file_st.st_size;
  unsigned map_size = map_st.st_size;
  unsigned block_cnt = file_size/block_size + (file_size%block_size != 0);

  // - ERROR -
  if (map_size != block_cnt/8 + (block_cnt%8 != 0))
  {
    close(file_fd);
    close(map_fd);

    exception_s::throw_exception(it,module.error_base + c_error_FGET_TARGET_FILES_SIZE_MISMATCH,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - map files to memory -
  void *file_ptr = mmap(nullptr,file_size,PROT_READ | PROT_WRITE,MAP_SHARED,file_fd,0);
  void *map_ptr = mmap(nullptr,map_size,PROT_READ | PROT_WRITE,MAP_SHARED,map_fd,0);

  // - ERROR -
  if (file_ptr == MAP_FAILED || map_ptr == MAP_FAILED)
  {
    if (file_ptr != MAP_FAILED) { munmap(file_ptr,file_size); }
    if (map_ptr != MAP_FAILED) { munmap(map_ptr,map_size); }

    close(file_fd);
    close(map_fd);

    exception_s::throw_exception(it,module.error_base + c_error_FGET_TARGET_CANNOT_MAP_FILES_TO_MEMORY,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  close(file_fd);
  close(map_fd);

  // - create fget target object -
  fget_target_s *ft_ptr = (fget_target_s *)cmalloc(sizeof(fget_target_s));
  ft_ptr->init();

  ft_ptr->block_size = block_size;
  ft_ptr->block_cnt = block_cnt;

  ft_ptr->file_size = file_size;
  ft_ptr->map_size = map_size;

  ft_ptr->file_ptr = (char *)file_ptr;
  ft_ptr->map_ptr = (char *)map_ptr;

  ft_ptr->index = 0;
  ft_ptr->done_cnt = 0;

  // - set destination data pointer -
  dst_location->v_data_ptr = (fget_target_s *)ft_ptr;

  return true;
}/*}}}*/

bool bic_fget_target_method_index_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int index;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,index))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("index#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  fget_target_s *ft_ptr = (fget_target_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (index < 0 || index >= ft_ptr->block_cnt)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FGET_TARGET_INVALID_INDEX_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(index);

    return false;
  }

  // - set fget target index -
  ft_ptr->index = index;

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

#define BIC_FGET_TARGET_CREATE_REQUEST_RECEIVE() \
{/*{{{*/\
  pointer_array_s *request_ptr = it.get_new_array_ptr();\
  request_ptr->copy_resize(2);\
\
  BIC_CREATE_NEW_LOCATION(request_loc,c_bi_class_array,request_ptr);\
\
  requests_ptr->push(request_loc);\
\
  long long int block_idx = start_idx;\
  long long int block_cnt = (end_idx - start_idx) + 1;\
\
  BIC_CREATE_NEW_LOCATION(block_idx_loc,c_bi_class_integer,block_idx);\
  BIC_CREATE_NEW_LOCATION(block_cnt_loc,c_bi_class_integer,block_cnt);\
\
  request_ptr->push(block_idx_loc);\
  request_ptr->push(block_cnt_loc);\
}/*}}}*/

bool bic_fget_target_method_received_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int request_cnt;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,request_cnt))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("received#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - ERROR -
  if (request_cnt < 0)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FGET_TARGET_NEGATIVE_REQUEST_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(request_cnt);

    return false;
  }

  fget_target_s *ft_ptr = (fget_target_s *)dst_location->v_data_ptr;

  pointer_array_s *requests_ptr = it.get_new_array_ptr();
  BIC_CREATE_NEW_LOCATION(requests_loc,c_bi_class_array,requests_ptr);

  if (ft_ptr->block_cnt > 0)
  {
    unsigned index = ft_ptr->index;

    unsigned done_cnt = 0;
    unsigned begin_idx = index;

    unsigned start_idx = c_idx_not_exist;
    unsigned end_idx = c_idx_not_exist;

    do {

      // - if package was received -
      if (ft_ptr->map_ptr[index >> 3] & (1 << (index & 0x07)))
      {
        ++done_cnt;

        if (start_idx == c_idx_not_exist)
        {
          start_idx = index;
        }

        end_idx = index;
      }

      // - if package was not received -
      else
      {
        if (request_cnt > 0 && start_idx != c_idx_not_exist)
        {
          // - create request -
          BIC_FGET_TARGET_CREATE_REQUEST_RECEIVE()

          // - update fget target index -
          ft_ptr->index = index;

          // - reset start index -
          start_idx = c_idx_not_exist;

          // - decrease count of requests -
          --request_cnt;
        }
      }

      // - increase index -
      if (++index >= ft_ptr->block_cnt)
      {
        if (request_cnt > 0 && start_idx != c_idx_not_exist)
        {
          // - create request -
          BIC_FGET_TARGET_CREATE_REQUEST_RECEIVE()

          // - update fget target index -
          ft_ptr->index = index;

          // - reset start index -
          start_idx = c_idx_not_exist;

          // - decrease count of requests -
          --request_cnt;
        }

        index = 0;
      }

    } while(index != begin_idx);

    // - update done package counter -
    ft_ptr->done_cnt = done_cnt;
  }

  BIC_SET_RESULT(requests_loc);

  return true;
}/*}}}*/

bool bic_fget_target_method_update_data_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int block_index;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,block_index) ||
      src_1_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("update_data#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  fget_target_s *ft_ptr = (fget_target_s *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_1_location->v_data_ptr;

  // - ERROR -
  if (block_index < 0 || block_index >= ft_ptr->block_cnt)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_FGET_TARGET_INVALID_BLOCK_INDEX,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(block_index);

    return false;
  }

  // - retrieve map file byte -
  char *byte_ptr = ft_ptr->map_ptr + (block_index >> 3);
  char bit_mask = 1 << (block_index & 0x07);

  // - block need for update test -
  long long int update = (*byte_ptr & bit_mask) == 0;

  if (update)
  {
    // - update target file -
    char *data_ptr = ft_ptr->file_ptr + block_index*ft_ptr->block_size;
    unsigned data_size = string_ptr->size - 1;

    memcpy(data_ptr,string_ptr->data,data_size);
    msync(data_ptr,data_size,MS_SYNC);

    // - update map file -
    *byte_ptr |= bit_mask;
    msync(byte_ptr,1,MS_SYNC);
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,update);

  return true;
}/*}}}*/

bool bic_fget_target_method_block_cnt_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FGET_TARGET_RETRIEVE_INTEGER(block_cnt);
}/*}}}*/

bool bic_fget_target_method_done_cnt_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_FGET_TARGET_RETRIEVE_INTEGER(done_cnt);
}/*}}}*/

bool bic_fget_target_method_done_percent_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  fget_target_s *ft_ptr = (fget_target_s *)dst_location->v_data_ptr;
  double result = (100.0*ft_ptr->done_cnt)/ft_ptr->block_cnt;

  BIC_SIMPLE_SET_RES(c_bi_class_float,result);

  return true;
}/*}}}*/

bool bic_fget_target_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("FgetTarget"),"FgetTarget");
  );

  return true;
}/*}}}*/

bool bic_fget_target_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("FgetTarget");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

