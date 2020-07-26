
@begin
include "shape_module.h"
@end

// - SHAPE indexes of built in classes -
unsigned c_bi_class_shp_handle = c_idx_not_exist;
unsigned c_bi_class_shp_object = c_idx_not_exist;

// - SHAPE module -
EXPORT built_in_module_s module =
{/*{{{*/
  2,                     // Class count
  shape_classes,         // Classes

  0,                     // Error base index
  2,                     // Error count
  shape_error_strings,   // Error strings

  shape_initialize,      // Initialize function
  shape_print_exception, // Print exceptions function
};/*}}}*/

// - SHAPE classes -
built_in_class_s *shape_classes[] =
{/*{{{*/
  &shp_handle_class,
  &shp_object_class,
};/*}}}*/

// - SHAPE error strings -
const char *shape_error_strings[] =
{/*{{{*/
  "error_SHP_HANDLE_FILE_OPEN_ERROR",
  "error_SHP_HANDLE_INDEX_EXCEEDS_RANGE",
};/*}}}*/

// - SHAPE initialize -
bool shape_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize shp_handle class identifier -
  c_bi_class_shp_handle = class_base_idx++;

  // - initialize shp_object class identifier -
  c_bi_class_shp_object = class_base_idx++;

  return true;
}/*}}}*/

// - SHAPE print exception -
bool shape_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_SHP_HANDLE_FILE_OPEN_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot open shape file \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SHP_HANDLE_INDEX_EXCEEDS_RANGE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nIndex %" HOST_LL_FORMAT "d exceeds shape entities range\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class SHP_HANDLE -
built_in_class_s shp_handle_class =
{/*{{{*/
  "ShpHandle",
  c_modifier_public | c_modifier_final,
  9, shp_handle_methods,
  0, shp_handle_variables,
  bic_shp_handle_consts,
  bic_shp_handle_init,
  bic_shp_handle_clear,
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

built_in_method_s shp_handle_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_shp_handle_operator_binary_equal
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_shp_handle_operator_binary_le_br_re_br
  },
  {
    "ShpHandle#2",
    c_modifier_public | c_modifier_final,
    bic_shp_handle_method_ShpHandle_2
  },
  {
    "item#1",
    c_modifier_public | c_modifier_final,
    bic_shp_handle_method_item_1
  },
  {
    "first_idx#0",
    c_modifier_public | c_modifier_final,
    bic_shp_handle_method_first_idx_0
  },
  {
    "next_idx#1",
    c_modifier_public | c_modifier_final,
    bic_shp_handle_method_next_idx_1
  },
  {
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_shp_handle_method_length_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_shp_handle_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_shp_handle_method_print_0
  },
};/*}}}*/

built_in_variable_s shp_handle_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

#define BIC_SHP_HANDLE_CHECK_INDEX() \
  /*{{{*/\
  shp_handle_s *sh_ptr = (shp_handle_s *)dst_location->v_data_ptr;\
\
  /* - ERROR - */\
  if (index < 0 || index >= sh_ptr->ent_count) {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_SHP_HANDLE_INDEX_EXCEEDS_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(index);\
\
    return false;\
  }\
  /*}}}*/

#define BIC_SHP_HANDLE_ITEM(NAME) \
  {/*{{{*/\
@begin ucl_params
<
index:retrieve_integer
>
method NAME
macro
; @end\
\
    BIC_SHP_HANDLE_CHECK_INDEX();\
\
    /* FIXME TODO continue ... */\
    BIC_SET_RESULT_BLANK();\
  }/*}}}*/

void bic_shp_handle_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_shp_handle_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (shp_handle_s *)nullptr;
}/*}}}*/

void bic_shp_handle_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  shp_handle_s *sh_ptr = (shp_handle_s *)location_ptr->v_data_ptr;

  if (sh_ptr != nullptr)
  {
    sh_ptr->clear(it);
    cfree(sh_ptr);
  }
}/*}}}*/

bool bic_shp_handle_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_shp_handle_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_SHP_HANDLE_ITEM("operator_binary_le_br_re_br#1");

  return true;
}/*}}}*/

bool bic_shp_handle_method_ShpHandle_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
path:c_bi_class_string
mode:c_bi_class_string
>
method ShpHandle
; @end

  string_s *path_ptr = (string_s *)src_0_location->v_data_ptr;
  string_s *mode_ptr = (string_s *)src_1_location->v_data_ptr;

  SHPHandle handle = SHPOpen(path_ptr->data,mode_ptr->data);

  // - ERROR -
  if (handle == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SHP_HANDLE_FILE_OPEN_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  // - create shp handle object -
  shp_handle_s *sh_ptr = (shp_handle_s *)cmalloc(sizeof(shp_handle_s));
  sh_ptr->init();

  sh_ptr->handle = handle;

  // - retrieve handle info -
  SHPGetInfo(handle,
    &sh_ptr->ent_count,
    &sh_ptr->shape_type,
    sh_ptr->min_bound,
    sh_ptr->max_bound);

  // - set shp_handle destination location -
  dst_location->v_data_ptr = (shp_handle_s *)sh_ptr;

  return true;
}/*}}}*/

bool bic_shp_handle_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_SHP_HANDLE_ITEM("item#1");

  return true;
}/*}}}*/

bool bic_shp_handle_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  shp_handle_s *sh_ptr = (shp_handle_s *)dst_location->v_data_ptr;

  if (sh_ptr->ent_count != 0)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,0);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_shp_handle_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
index:retrieve_integer
>
method next_idx
; @end

  BIC_SHP_HANDLE_CHECK_INDEX();

  if (++index < sh_ptr->ent_count)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,index);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_shp_handle_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((shp_handle_s *)dst_location->v_data_ptr)->ent_count;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_shp_handle_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("ShpHandle"),"ShpHandle");
  );

  return true;
}/*}}}*/

bool bic_shp_handle_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("ShpHandle");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class SHP_OBJECT -
built_in_class_s shp_object_class =
{/*{{{*/
  "ShpObject",
  c_modifier_public | c_modifier_final,
  3, shp_object_methods,
  0, shp_object_variables,
  bic_shp_object_consts,
  bic_shp_object_init,
  bic_shp_object_clear,
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

built_in_method_s shp_object_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_shp_object_operator_binary_equal
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_shp_object_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_shp_object_method_print_0
  },
};/*}}}*/

built_in_variable_s shp_object_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_shp_object_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_shp_object_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
  //location_ptr->v_data_ptr = (shp_object_s *)nullptr;
}/*}}}*/

void bic_shp_object_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
  //shp_object_s *sh_ptr = (shp_object_s *)location_ptr->v_data_ptr;

  //if (sh_ptr != nullptr)
  //{
  //  sh_ptr->clear(it);
  //  cfree(sh_ptr);
  //}
}/*}}}*/

bool bic_shp_object_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_shp_object_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("ShpObject"),"ShpObject");
  );

  return true;
}/*}}}*/

bool bic_shp_object_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("ShpObject");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

