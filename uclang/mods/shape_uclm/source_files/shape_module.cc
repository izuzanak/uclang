
@begin
include "shape_module.h"
@end

// - SHAPE indexes of built in classes -
unsigned c_bi_class_shp_handle = c_idx_not_exist;
unsigned c_bi_class_shp_object = c_idx_not_exist;
unsigned c_bi_class_shp_part = c_idx_not_exist;

// - SHAPE module -
EXPORT built_in_module_s module =
{/*{{{*/
  3,                     // Class count
  shape_classes,         // Classes

  0,                     // Error base index
  4,                     // Error count
  shape_error_strings,   // Error strings

  shape_initialize,      // Initialize function
  shape_print_exception, // Print exceptions function
};/*}}}*/

// - SHAPE classes -
built_in_class_s *shape_classes[] =
{/*{{{*/
  &shp_handle_class,
  &shp_object_class,
  &shp_part_class,
};/*}}}*/

// - SHAPE error strings -
const char *shape_error_strings[] =
{/*{{{*/
  "error_SHP_HANDLE_FILE_OPEN_ERROR",
  "error_SHP_HANDLE_INDEX_EXCEEDS_RANGE",
  "error_SHP_OBJECT_INDEX_EXCEEDS_RANGE",
  "error_SHP_PART_INDEX_EXCEEDS_RANGE",
};/*}}}*/

// - SHAPE initialize -
bool shape_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize shp_handle class identifier -
  c_bi_class_shp_handle = class_base_idx++;

  // - initialize shp_object class identifier -
  c_bi_class_shp_object = class_base_idx++;

  // - initialize shp_part class identifier -
  c_bi_class_shp_part = class_base_idx++;

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
  case c_error_SHP_OBJECT_INDEX_EXCEEDS_RANGE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nIndex %" HOST_LL_FORMAT "d exceeds shape object parts range\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SHP_PART_INDEX_EXCEEDS_RANGE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nIndex %" HOST_LL_FORMAT "d exceeds shape part vertices range\n",exception.params[0]);
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
    SHPObject *so_ptr = SHPReadObject(sh_ptr->handle,index);\
\
    /* ERROR */\
    if (so_ptr == nullptr)\
    {\
      /* FIXME TODO throw proper exception */\
      BIC_TODO_ERROR(__FILE__,__LINE__);\
      return false;\
    }\
\
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_shp_object,so_ptr);\
    BIC_SET_RESULT(new_location);\
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
  12, shp_object_methods,
  14, shp_object_variables,
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
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_shp_object_operator_binary_le_br_re_br
  },
  {
    "shape_type#0",
    c_modifier_public | c_modifier_final,
    bic_shp_object_method_shape_type_0
  },
  {
    "id#0",
    c_modifier_public | c_modifier_final,
    bic_shp_object_method_id_0
  },
  {
    "min#0",
    c_modifier_public | c_modifier_final,
    bic_shp_object_method_min_0
  },
  {
    "max#0",
    c_modifier_public | c_modifier_final,
    bic_shp_object_method_max_0
  },
  {
    "item#1",
    c_modifier_public | c_modifier_final,
    bic_shp_object_method_item_1
  },
  {
    "first_idx#0",
    c_modifier_public | c_modifier_final,
    bic_shp_object_method_first_idx_0
  },
  {
    "next_idx#1",
    c_modifier_public | c_modifier_final,
    bic_shp_object_method_next_idx_1
  },
  {
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_shp_object_method_length_0
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

  // - shape object type constants -
  { "T_NULL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "T_POINT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "T_ARC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "T_POLYGON", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "T_MULTIPOINT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "T_POINTZ", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "T_ARCZ", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "T_POLYGONZ", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "T_MULTIPOINTZ", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "T_POINTM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "T_ARCM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "T_POLYGONM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "T_MULTIPOINTM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "T_MULTIPATCH", c_modifier_public | c_modifier_static | c_modifier_static_const },
};/*}}}*/

#define BIC_SHP_OBJECT_CHECK_INDEX() \
  /*{{{*/\
  SHPObject *so_ptr = (SHPObject *)dst_location->v_data_ptr;\
\
  /* - ERROR - */\
  if (index < 0 || index >= so_ptr->nParts) {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_SHP_OBJECT_INDEX_EXCEEDS_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(index);\
\
    return false;\
  }\
  /*}}}*/

#define BIC_SHP_OBJECT_ITEM(NAME) \
  {/*{{{*/\
@begin ucl_params
<
index:retrieve_integer
>
method NAME
macro
; @end\
\
    BIC_SHP_OBJECT_CHECK_INDEX();\
\
    /* - create shp part object - */\
    shp_part_s *sp_ptr = (shp_part_s *)cmalloc(sizeof(shp_part_s));\
    sp_ptr->init();\
\
    dst_location->v_reference_cnt.atomic_inc();\
    sp_ptr->object_loc = dst_location;\
    sp_ptr->part_idx = index;\
\
    int part_start = so_ptr->panPartStart[index];\
    int part_end;\
\
    /* - not last part of object - */\
    if (index + 1 < so_ptr->nParts)\
    {\
      part_end = so_ptr->panPartStart[index + 1];\
    }\
    else\
    {\
      part_end = so_ptr->nVertices;\
    }\
\
    sp_ptr->length = part_end - part_start;\
\
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_shp_part,sp_ptr);\
    BIC_SET_RESULT(new_location);\
  }/*}}}*/

#define BIC_SHP_OBJECT_MIN_MAX_VALUE(NAME) \
{/*{{{*/\
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_float,so_ptr->NAME);\
  array_ptr->push(new_location);\
}/*}}}*/

void bic_shp_object_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert shape object type constants -
  {
    const_locations.push_blanks(14);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 14);

#define CREATE_SHAPE_OBJECT_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_SHAPE_OBJECT_TYPE_BIC_STATIC(SHPT_NULL);
    CREATE_SHAPE_OBJECT_TYPE_BIC_STATIC(SHPT_POINT);
    CREATE_SHAPE_OBJECT_TYPE_BIC_STATIC(SHPT_ARC);
    CREATE_SHAPE_OBJECT_TYPE_BIC_STATIC(SHPT_POLYGON);
    CREATE_SHAPE_OBJECT_TYPE_BIC_STATIC(SHPT_MULTIPOINT);
    CREATE_SHAPE_OBJECT_TYPE_BIC_STATIC(SHPT_POINTZ);
    CREATE_SHAPE_OBJECT_TYPE_BIC_STATIC(SHPT_ARCZ);
    CREATE_SHAPE_OBJECT_TYPE_BIC_STATIC(SHPT_POLYGONZ);
    CREATE_SHAPE_OBJECT_TYPE_BIC_STATIC(SHPT_MULTIPOINTZ);
    CREATE_SHAPE_OBJECT_TYPE_BIC_STATIC(SHPT_POINTM);
    CREATE_SHAPE_OBJECT_TYPE_BIC_STATIC(SHPT_ARCM);
    CREATE_SHAPE_OBJECT_TYPE_BIC_STATIC(SHPT_POLYGONM);
    CREATE_SHAPE_OBJECT_TYPE_BIC_STATIC(SHPT_MULTIPOINTM);
    CREATE_SHAPE_OBJECT_TYPE_BIC_STATIC(SHPT_MULTIPATCH);
  }
}/*}}}*/

void bic_shp_object_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (SHPObject *)nullptr;
}/*}}}*/

void bic_shp_object_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  SHPObject *so_ptr = (SHPObject *)location_ptr->v_data_ptr;

  if (so_ptr != nullptr)
  {
    SHPDestroyObject(so_ptr);
  }
}/*}}}*/

bool bic_shp_object_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_shp_object_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_SHP_OBJECT_ITEM("operator_binary_le_br_re_br#1");

  return true;
}/*}}}*/

bool bic_shp_object_method_shape_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  SHPObject *so_ptr = (SHPObject *)dst_location->v_data_ptr;

  long long int result = so_ptr->nSHPType;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_shp_object_method_id_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  SHPObject *so_ptr = (SHPObject *)dst_location->v_data_ptr;

  long long int result = so_ptr->nShapeId;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_shp_object_method_min_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  SHPObject *so_ptr = (SHPObject *)dst_location->v_data_ptr;

  pointer_array_s *array_ptr = it.get_new_array_ptr();

  BIC_SHP_OBJECT_MIN_MAX_VALUE(dfXMin);
  BIC_SHP_OBJECT_MIN_MAX_VALUE(dfYMin);
  BIC_SHP_OBJECT_MIN_MAX_VALUE(dfZMin);
  BIC_SHP_OBJECT_MIN_MAX_VALUE(dfMMin);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_shp_object_method_max_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  SHPObject *so_ptr = (SHPObject *)dst_location->v_data_ptr;

  pointer_array_s *array_ptr = it.get_new_array_ptr();

  BIC_SHP_OBJECT_MIN_MAX_VALUE(dfXMax);
  BIC_SHP_OBJECT_MIN_MAX_VALUE(dfYMax);
  BIC_SHP_OBJECT_MIN_MAX_VALUE(dfZMax);
  BIC_SHP_OBJECT_MIN_MAX_VALUE(dfMMax);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_shp_object_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_SHP_OBJECT_ITEM("item#1");

  return true;
}/*}}}*/

bool bic_shp_object_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  SHPObject *so_ptr = (SHPObject *)dst_location->v_data_ptr;

  if (so_ptr->nParts > 0)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,0);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_shp_object_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
index:retrieve_integer
>
method next_idx
; @end

  BIC_SHP_OBJECT_CHECK_INDEX();

  if (++index < so_ptr->nParts)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,index);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_shp_object_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((SHPObject *)dst_location->v_data_ptr)->nParts;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

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

// - class SHP_PART -
built_in_class_s shp_part_class =
{/*{{{*/
  "ShpPart",
  c_modifier_public | c_modifier_final,
  9, shp_part_methods,
  0, shp_part_variables,
  bic_shp_part_consts,
  bic_shp_part_init,
  bic_shp_part_clear,
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

built_in_method_s shp_part_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_shp_part_operator_binary_equal
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_shp_part_operator_binary_le_br_re_br
  },
  {
    "shape_type#0",
    c_modifier_public | c_modifier_final,
    bic_shp_part_method_shape_type_0
  },
  {
    "item#1",
    c_modifier_public | c_modifier_final,
    bic_shp_part_method_item_1
  },
  {
    "first_idx#0",
    c_modifier_public | c_modifier_final,
    bic_shp_part_method_first_idx_0
  },
  {
    "next_idx#1",
    c_modifier_public | c_modifier_final,
    bic_shp_part_method_next_idx_1
  },
  {
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_shp_part_method_length_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_shp_part_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_shp_part_method_print_0
  },
};/*}}}*/

built_in_variable_s shp_part_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

#define BIC_SHP_PART_CHECK_INDEX() \
  /*{{{*/\
  shp_part_s *sp_ptr = (shp_part_s *)dst_location->v_data_ptr;\
\
  /* - ERROR - */\
  if (index < 0 || index >= sp_ptr->length) {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_SHP_PART_INDEX_EXCEEDS_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(index);\
\
    return false;\
  }\
  /*}}}*/

#define BIC_SHP_PART_ITEM(NAME) \
  {/*{{{*/\
@begin ucl_params
<
index:retrieve_integer
>
method NAME
macro
; @end\
\
    BIC_SHP_PART_CHECK_INDEX();\
\
    SHPObject *so_ptr = (SHPObject *)sp_ptr->object_loc->v_data_ptr;\
\
    /* - retrieve vertex index - */\
    unsigned vertex_idx = so_ptr->panPartStart[sp_ptr->part_idx] + index;\
\
    pointer_array_s *array_ptr = it.get_new_array_ptr();\
\
    BIC_CREATE_NEW_LOCATION(x_location,c_bi_class_float,so_ptr->padfX[vertex_idx]);\
    array_ptr->push(x_location);\
\
    BIC_CREATE_NEW_LOCATION(y_location,c_bi_class_float,so_ptr->padfY[vertex_idx]);\
    array_ptr->push(y_location);\
\
    if (so_ptr->padfZ != nullptr)\
    {\
      BIC_CREATE_NEW_LOCATION(z_location,c_bi_class_float,so_ptr->padfZ[vertex_idx]);\
      array_ptr->push(z_location);\
    }\
\
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);\
    BIC_SET_RESULT(new_location);\
  }/*}}}*/

void bic_shp_part_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_shp_part_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (shp_part_s *)nullptr;
}/*}}}*/

void bic_shp_part_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  shp_part_s *sp_ptr = (shp_part_s *)location_ptr->v_data_ptr;

  if (sp_ptr != nullptr)
  {
    sp_ptr->clear(it);
    cfree(sp_ptr);
  }
}/*}}}*/

bool bic_shp_part_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_shp_part_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_SHP_PART_ITEM("operator_binary_le_br_re_br#1");

  return true;
}/*}}}*/

bool bic_shp_part_method_shape_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  shp_part_s *sp_ptr = (shp_part_s *)dst_location->v_data_ptr;
  SHPObject *so_ptr = (SHPObject *)sp_ptr->object_loc->v_data_ptr;

  long long int result = so_ptr->panPartType[sp_ptr->part_idx];

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_shp_part_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_SHP_PART_ITEM("item#1");

  return true;
}/*}}}*/

bool bic_shp_part_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  shp_part_s *sp_ptr = (shp_part_s *)dst_location->v_data_ptr;

  if (sp_ptr->length > 0)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,0);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_shp_part_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
index:retrieve_integer
>
method next_idx
; @end

  BIC_SHP_PART_CHECK_INDEX();

  if (++index < sp_ptr->length)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,index);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_shp_part_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((shp_part_s *)dst_location->v_data_ptr)->length;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_shp_part_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("ShpPart"),"ShpPart");
  );

  return true;
}/*}}}*/

bool bic_shp_part_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("ShpPart");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

