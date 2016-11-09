
@begin
include "docu_module.h"
@end

// - DOCU indexes of built in classes -
unsigned c_bi_class_docu = c_idx_not_exist;
unsigned c_bi_class_docu_source = c_idx_not_exist;
unsigned c_bi_class_docu_comment = c_idx_not_exist;
unsigned c_bi_class_docu_parsed = c_idx_not_exist;

// - DOCU module -
built_in_module_s module =
{/*{{{*/
  4,                    // Class count
  docu_classes,         // Classes

  0,                    // Error base index
  2,                    // Error count
  docu_error_strings,   // Error strings

  docu_initialize,      // Initialize function
  docu_print_exception, // Print exceptions function
};/*}}}*/

// - DOCU classes -
built_in_class_s *docu_classes[] =
{/*{{{*/
  &docu_class,
  &docu_source_class,
  &docu_comment_class,
  &docu_parsed_class,
};/*}}}*/

// - DOCU error strings -
const char *docu_error_strings[] =
{/*{{{*/
  "error_DOCU_SOURCE_INDEX_EXCEEDS_RANGE",
  "error_DOCU_PARSED_PARSE_ERROR",
};/*}}}*/

// - DOCU initialize -
bool docu_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize docu class identifier -
  c_bi_class_docu = class_base_idx++;

  // - initialize docu_source class identifier -
  c_bi_class_docu_source = class_base_idx++;

  // - initialize docu_comment class identifier -
  c_bi_class_docu_comment = class_base_idx++;

  // - initialize docu_parsed class identifier -
  c_bi_class_docu_parsed = class_base_idx++;

  return true;
}/*}}}*/

// - DOCU print exception -
bool docu_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_DOCU_SOURCE_INDEX_EXCEEDS_RANGE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nIndex %" HOST_LL_FORMAT "d exceeds documentation comment count\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_DOCU_PARSED_PARSE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while parsing documentation string\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class DOCU -
built_in_class_s docu_class =
{/*{{{*/
  "Docu",
  c_modifier_public | c_modifier_final,
  2, docu_methods,
  0, docu_variables,
  bic_docu_consts,
  bic_docu_init,
  bic_docu_clear,
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

built_in_method_s docu_methods[] =
{/*{{{*/
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_docu_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_docu_method_print_0
  },
};/*}}}*/

built_in_variable_s docu_variables[] =
{/*{{{*/
};/*}}}*/

void bic_docu_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_docu_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_docu_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_docu_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Docu"),"Docu");
  );

  return true;
}/*}}}*/

bool bic_docu_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("Docu");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class DOCU_SOURCE -
built_in_class_s docu_source_class =
{/*{{{*/
  "DocuSource",
  c_modifier_public | c_modifier_final,
  9, docu_source_methods,
  0, docu_source_variables,
  bic_docu_source_consts,
  bic_docu_source_init,
  bic_docu_source_clear,
  NULL,
  NULL,
  NULL,
  bic_docu_source_first_idx,
  bic_docu_source_next_idx,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s docu_source_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_docu_source_operator_binary_equal
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_docu_source_operator_binary_le_br_re_br
  },
  {
    "DocuSource#1",
    c_modifier_public | c_modifier_final,
    bic_docu_source_method_DocuSource_1
  },
  {
    "item#1",
    c_modifier_public | c_modifier_final,
    bic_docu_source_method_item_1
  },
  {
    "first_idx#0",
    c_modifier_public | c_modifier_final,
    bic_docu_source_method_first_idx_0
  },
  {
    "next_idx#1",
    c_modifier_public | c_modifier_final,
    bic_docu_source_method_next_idx_1
  },
  {
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_docu_source_method_length_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_docu_source_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_docu_source_method_print_0
  },
};/*}}}*/

built_in_variable_s docu_source_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_DOCU_SOURCE_CHECK_INDEX() \
  /*{{{*/\
  docu_source_s *ds_ptr = (docu_source_s *)dst_location->v_data_ptr;\
  \
  /* - ERROR - */\
  if (index < 0 || index >= ds_ptr->comment_ranges.used) {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_DOCU_SOURCE_INDEX_EXCEEDS_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(index);\
    \
    return false;\
  }\
  /*}}}*/

#define BIC_DOCU_SOURCE_ITEM(NAME) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
\
  long long int index;\
\
  /* - ERROR - */\
  if (!it.retrieve_integer(src_0_location,index))\
  {\
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
    new_exception->params.push(1);\
    new_exception->params.push(src_0_location->v_type);\
\
    return false;\
  }\
\
  BIC_DOCU_SOURCE_CHECK_INDEX();\
\
  /* - create docu comment object - */\
  docu_comment_s *dc_ptr = (docu_comment_s *)cmalloc(sizeof(docu_comment_s));\
  dc_ptr->init();\
\
  /* - set reference to source - */\
  dst_location->v_reference_cnt.atomic_inc();\
  dc_ptr->ds_ptr = dst_location;\
\
  /* - set comment index - */\
  dc_ptr->index = index;\
\
  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_docu_comment,dc_ptr);\
  BIC_SET_RESULT(new_location);\
\
  return true;\
}/*}}}*/

void bic_docu_source_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_docu_source_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (docu_source_s *)NULL;
}/*}}}*/

void bic_docu_source_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  docu_source_s *ds_ptr = (docu_source_s *)location_ptr->v_data_ptr;

  if (ds_ptr != NULL)
  {
    ds_ptr->clear(it);
    cfree(ds_ptr);
  }
}/*}}}*/

unsigned bic_docu_source_first_idx(location_s *location_ptr)
{/*{{{*/
  docu_source_s *ds_ptr = (docu_source_s *)location_ptr->v_data_ptr;
  return ds_ptr->comment_ranges.used != 0 ? 0 : c_idx_not_exist;
}/*}}}*/

unsigned bic_docu_source_next_idx(location_s *location_ptr,unsigned index)
{/*{{{*/
  docu_source_s *ds_ptr = (docu_source_s *)location_ptr->v_data_ptr;

  // FIXME TODO check index ...
  cassert(index < ds_ptr->comment_ranges.used);

  return (index + 1 < ds_ptr->comment_ranges.used) ? index + 1 : c_idx_not_exist;
}/*}}}*/

bool bic_docu_source_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_docu_source_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_DOCU_SOURCE_ITEM("operator_binary_le_br_re_br#1");
}/*}}}*/

bool bic_docu_source_method_DocuSource_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("DocuSource#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  docu_source_s *ds_ptr = (docu_source_s *)cmalloc(sizeof(docu_source_s));
  ds_ptr->init();

  // - set string pointer -
  src_0_location->v_reference_cnt.atomic_inc();
  ds_ptr->source_ptr = src_0_location;

  // - set source string properties -
  ds_ptr->src_length = string_ptr->size - 1;
  ds_ptr->src_data = string_ptr->data;

  // - search for comments in source string -
  ds_ptr->find_comments();

  dst_location->v_data_ptr = (docu_source_s *)ds_ptr;

  return true;
}/*}}}*/

bool bic_docu_source_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_DOCU_SOURCE_ITEM("item#1");
}/*}}}*/

bool bic_docu_source_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  docu_source_s *ds_ptr = (docu_source_s *)dst_location->v_data_ptr;

  if (ds_ptr->comment_ranges.used > 0)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,0);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_docu_source_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int index;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,index))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("next_idx#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  BIC_DOCU_SOURCE_CHECK_INDEX();

  if (++index < ds_ptr->comment_ranges.used)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,index);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_docu_source_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  docu_source_s *ds_ptr = (docu_source_s *)dst_location->v_data_ptr;

  long long int result = ds_ptr->comment_ranges.used;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_docu_source_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("DocuSource"),"DocuSource");
  );

  return true;
}/*}}}*/

bool bic_docu_source_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("DocuSource");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class DOCU_COMMENT -
built_in_class_s docu_comment_class =
{/*{{{*/
  "DocuComment",
  c_modifier_public | c_modifier_final,
  6, docu_comment_methods,
  0, docu_comment_variables,
  bic_docu_comment_consts,
  bic_docu_comment_init,
  bic_docu_comment_clear,
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

built_in_method_s docu_comment_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_docu_comment_operator_binary_equal
  },
  {
    "start#0",
    c_modifier_public | c_modifier_final,
    bic_docu_comment_method_start_0
  },
  {
    "end#0",
    c_modifier_public | c_modifier_final,
    bic_docu_comment_method_end_0
  },
  {
    "data#0",
    c_modifier_public | c_modifier_final,
    bic_docu_comment_method_data_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_docu_comment_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_docu_comment_method_print_0
  },
};/*}}}*/

built_in_variable_s docu_comment_variables[] =
{/*{{{*/
};/*}}}*/

void bic_docu_comment_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_docu_comment_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (docu_comment_s *)NULL;
}/*}}}*/

void bic_docu_comment_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  docu_comment_s *dc_ptr = (docu_comment_s *)location_ptr->v_data_ptr;

  if (dc_ptr != NULL)
  {
    dc_ptr->clear(it);
    cfree(dc_ptr);
  }
}/*}}}*/

bool bic_docu_comment_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_docu_comment_method_start_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  docu_comment_s *dc_ptr = (docu_comment_s *)dst_location->v_data_ptr;
  docu_source_s *ds_ptr = (docu_source_s *)dc_ptr->ds_ptr->v_data_ptr;

  unsigned result = ds_ptr->comment_ranges.data[dc_ptr->index].ui_first;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_docu_comment_method_end_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  docu_comment_s *dc_ptr = (docu_comment_s *)dst_location->v_data_ptr;
  docu_source_s *ds_ptr = (docu_source_s *)dc_ptr->ds_ptr->v_data_ptr;

  unsigned result = ds_ptr->comment_ranges.data[dc_ptr->index].ui_second;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_docu_comment_method_data_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  docu_comment_s *dc_ptr = (docu_comment_s *)dst_location->v_data_ptr;
  docu_source_s *ds_ptr = (docu_source_s *)dc_ptr->ds_ptr->v_data_ptr;

  name_pos_s &range = ds_ptr->comment_ranges.data[dc_ptr->index];

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(range.ui_second - range.ui_first,ds_ptr->src_data + range.ui_first);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_docu_comment_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("DocuComment"),"DocuComment");
  );

  return true;
}/*}}}*/

bool bic_docu_comment_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("DocuComment");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class DOCU_PARSED -
built_in_class_s docu_parsed_class =
{/*{{{*/
  "DocuParsed",
  c_modifier_public | c_modifier_final,
  13, docu_parsed_methods,
  5, docu_parsed_variables,
  bic_docu_parsed_consts,
  bic_docu_parsed_init,
  bic_docu_parsed_clear,
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

built_in_method_s docu_parsed_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_docu_parsed_operator_binary_equal
  },
  {
    "parse#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_docu_parsed_method_parse_1
  },
  {
    "create_brief#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_docu_parsed_method_create_brief_1
  },
  {
    "after_member#0",
    c_modifier_public | c_modifier_final,
    bic_docu_parsed_method_after_member_0
  },
  {
    "comm_type#0",
    c_modifier_public | c_modifier_final,
    bic_docu_parsed_method_comm_type_0
  },
  {
    "id_string#0",
    c_modifier_public | c_modifier_final,
    bic_docu_parsed_method_id_string_0
  },
  {
    "get_brief#0",
    c_modifier_public | c_modifier_final,
    bic_docu_parsed_method_get_brief_0
  },
  {
    "get_paragraphs#0",
    c_modifier_public | c_modifier_final,
    bic_docu_parsed_method_get_paragraphs_0
  },
  {
    "get_param_names#0",
    c_modifier_public | c_modifier_final,
    bic_docu_parsed_method_get_param_names_0
  },
  {
    "get_params#0",
    c_modifier_public | c_modifier_final,
    bic_docu_parsed_method_get_params_0
  },
  {
    "get_return#0",
    c_modifier_public | c_modifier_final,
    bic_docu_parsed_method_get_return_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_docu_parsed_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_docu_parsed_method_print_0
  },
};/*}}}*/

built_in_variable_s docu_parsed_variables[] =
{/*{{{*/
  { "TYPE_UNKNOWN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_FILE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_CLASS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_METHOD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "TYPE_VAR", c_modifier_public | c_modifier_static | c_modifier_static_const },
};/*}}}*/

void bic_docu_parsed_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert comment type constants -
  {
    const_locations.push_blanks(5);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 5);

#define CREATE_DOCU_PARSED_COMMENT_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_DOCU_PARSED_COMMENT_TYPE_BIC_STATIC(c_comm_type_unknown);
    CREATE_DOCU_PARSED_COMMENT_TYPE_BIC_STATIC(c_comm_type_file);
    CREATE_DOCU_PARSED_COMMENT_TYPE_BIC_STATIC(c_comm_type_class);
    CREATE_DOCU_PARSED_COMMENT_TYPE_BIC_STATIC(c_comm_type_method);
    CREATE_DOCU_PARSED_COMMENT_TYPE_BIC_STATIC(c_comm_type_var);
  }
}/*}}}*/

void bic_docu_parsed_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (docu_parsed_s *)NULL;
}/*}}}*/

void bic_docu_parsed_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  docu_parsed_s *dp_ptr = (docu_parsed_s *)location_ptr->v_data_ptr;

  if (dp_ptr != NULL)
  {
    dp_ptr->clear(it);
    cfree(dp_ptr);
  }
}/*}}}*/

bool bic_docu_parsed_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_docu_parsed_method_parse_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_docu_parsed,"parse#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve source string -
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create docu parsed object -
  docu_parsed_s *dp_ptr = (docu_parsed_s *)cmalloc(sizeof(docu_parsed_s));
  dp_ptr->init();

  ((location_s *)it.blank_location)->v_reference_cnt.atomic_add(6);

  // - initialize docu parsed locations -
  dp_ptr->id_string_ptr = (location_s *)it.blank_location;
  dp_ptr->brief_ptr = (location_s *)it.blank_location;
  dp_ptr->paragraphs_ptr = (location_s *)it.blank_location;
  dp_ptr->param_names_ptr = (location_s *)it.blank_location;
  dp_ptr->params_ptr = (location_s *)it.blank_location;
  dp_ptr->return_ptr = (location_s *)it.blank_location;

  // - ERROR -
  if (!dp_ptr->parse(it,*string_ptr))
  {
    dp_ptr->clear(it);
    cfree(dp_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_DOCU_PARSED_PARSE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_docu_parsed,dp_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_docu_parsed_method_create_brief_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_docu_parsed,"create_brief#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - create docu parsed object -
  docu_parsed_s *dp_ptr = (docu_parsed_s *)cmalloc(sizeof(docu_parsed_s));
  dp_ptr->init();

  ((location_s *)it.blank_location)->v_reference_cnt.atomic_add(5);

  // - initialize docu parsed locations -
  dp_ptr->id_string_ptr = (location_s *)it.blank_location;
  dp_ptr->paragraphs_ptr = (location_s *)it.blank_location;
  dp_ptr->param_names_ptr = (location_s *)it.blank_location;
  dp_ptr->params_ptr = (location_s *)it.blank_location;
  dp_ptr->return_ptr = (location_s *)it.blank_location;

  // - set brief description -
  src_0_location->v_reference_cnt.atomic_inc();
  dp_ptr->brief_ptr = src_0_location;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_docu_parsed,dp_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_docu_parsed_method_after_member_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  docu_parsed_s *dp_ptr = (docu_parsed_s *)dst_location->v_data_ptr;

  unsigned result = dp_ptr->after_member;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_docu_parsed_method_comm_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  docu_parsed_s *dp_ptr = (docu_parsed_s *)dst_location->v_data_ptr;

  unsigned result = dp_ptr->comm_type;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

#define BIC_DOCU_PARSER_GET_LOCATION(NAME) \
{/*{{{*/\
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  docu_parsed_s *dp_ptr = (docu_parsed_s *)dst_location->v_data_ptr;\
  location_s *NAME ## _location = dp_ptr->NAME ## _ptr;\
\
  NAME ## _location->v_reference_cnt.atomic_inc();\
  BIC_SET_RESULT(NAME ## _location);\
\
  return true;\
}/*}}}*/

bool bic_docu_parsed_method_id_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_DOCU_PARSER_GET_LOCATION(id_string);
}/*}}}*/

bool bic_docu_parsed_method_get_brief_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_DOCU_PARSER_GET_LOCATION(brief);
}/*}}}*/

bool bic_docu_parsed_method_get_paragraphs_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_DOCU_PARSER_GET_LOCATION(paragraphs);
}/*}}}*/

bool bic_docu_parsed_method_get_param_names_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_DOCU_PARSER_GET_LOCATION(param_names);
}/*}}}*/

bool bic_docu_parsed_method_get_params_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_DOCU_PARSER_GET_LOCATION(params);
}/*}}}*/

bool bic_docu_parsed_method_get_return_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_DOCU_PARSER_GET_LOCATION(return);
}/*}}}*/

bool bic_docu_parsed_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("DocuParsed"),"DocuParsed");
  );

  return true;
}/*}}}*/

bool bic_docu_parsed_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("DocuParsed");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

