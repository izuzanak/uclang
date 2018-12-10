
@begin
include "inotify_module.h"
@end

// - INOTIFY indexes of built in classes -
unsigned c_bi_class_inotify = c_idx_not_exist;
unsigned c_bi_class_inotify_watch = c_idx_not_exist;
unsigned c_bi_class_inotify_event = c_idx_not_exist;

// - INOTIFY module -
built_in_module_s module =
{/*{{{*/
  3,                       // Class count
  inotify_classes,         // Classes

  0,                       // Error base index
  3,                       // Error count
  inotify_error_strings,   // Error strings

  inotify_initialize,      // Initialize function
  inotify_print_exception, // Print exceptions function
};/*}}}*/

// - INOTIFY classes -
built_in_class_s *inotify_classes[] =
{/*{{{*/
  &inotify_class,
  &inotify_watch_class,
  &inotify_event_class,
};/*}}}*/

// - INOTIFY error strings -
const char *inotify_error_strings[] =
{/*{{{*/
  "error_INOTIFY_CREATE_ERROR",
  "error_INOTIFY_ADD_WATCH_ERROR",
  "error_INOTIFY_READ_ERROR",
};/*}}}*/

// - INOTIFY initialize -
bool inotify_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize inotify class identifier -
  c_bi_class_inotify = class_base_idx++;

  // - initialize inotify_watch class identifier -
  c_bi_class_inotify_watch = class_base_idx++;

  // - initialize inotify_event class identifier -
  c_bi_class_inotify_event = class_base_idx++;

  return true;
}/*}}}*/

// - INOTIFY print exception -
bool inotify_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_INOTIFY_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot create inotify instance\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_INOTIFY_ADD_WATCH_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInotify, error while adding watch\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_INOTIFY_READ_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInotify, error while reading events\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class INOTIFY -
built_in_class_s inotify_class =
{/*{{{*/
  "Inotify",
  c_modifier_public | c_modifier_final,
  7, inotify_methods,
  23, inotify_variables,
  bic_inotify_consts,
  bic_inotify_init,
  bic_inotify_clear,
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

built_in_method_s inotify_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_inotify_operator_binary_equal
  },
  {
    "Inotify#0",
    c_modifier_public | c_modifier_final,
    bic_inotify_method_Inotify_0
  },
  {
    "add_watch#2",
    c_modifier_public | c_modifier_final,
    bic_inotify_method_add_watch_2
  },
  {
    "read#0",
    c_modifier_public | c_modifier_final,
    bic_inotify_method_read_0
  },
  {
    "get_fd#0",
    c_modifier_public | c_modifier_final,
    bic_inotify_method_get_fd_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_inotify_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_inotify_method_print_0
  },
};/*}}}*/

built_in_variable_s inotify_variables[] =
{/*{{{*/

  // - inotify watch flags -
  { "IN_ACCESS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IN_MODIFY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IN_ATTRIB", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IN_CLOSE_WRITE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IN_CLOSE_NOWRITE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IN_CLOSE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IN_OPEN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IN_MOVED_FROM", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IN_MOVED_TO", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IN_MOVE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IN_CREATE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IN_DELETE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IN_DELETE_SELF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IN_MOVE_SELF", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IN_UNMOUNT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IN_Q_OVERFLOW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IN_IGNORED", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IN_ONLYDIR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IN_DONT_FOLLOW", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IN_MASK_ADD", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IN_ISDIR", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IN_ONESHOT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "IN_ALL_EVENTS", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_inotify_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert inotify watch flags -
  {
    const_locations.push_blanks(23);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 23);

#define CREATE_INOTIFY_WATCH_FLAG_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_INOTIFY_WATCH_FLAG_BIC_STATIC(IN_ACCESS);
    CREATE_INOTIFY_WATCH_FLAG_BIC_STATIC(IN_MODIFY);
    CREATE_INOTIFY_WATCH_FLAG_BIC_STATIC(IN_ATTRIB);
    CREATE_INOTIFY_WATCH_FLAG_BIC_STATIC(IN_CLOSE_WRITE);
    CREATE_INOTIFY_WATCH_FLAG_BIC_STATIC(IN_CLOSE_NOWRITE);
    CREATE_INOTIFY_WATCH_FLAG_BIC_STATIC(IN_CLOSE);
    CREATE_INOTIFY_WATCH_FLAG_BIC_STATIC(IN_OPEN);
    CREATE_INOTIFY_WATCH_FLAG_BIC_STATIC(IN_MOVED_FROM);
    CREATE_INOTIFY_WATCH_FLAG_BIC_STATIC(IN_MOVED_TO);
    CREATE_INOTIFY_WATCH_FLAG_BIC_STATIC(IN_MOVE);
    CREATE_INOTIFY_WATCH_FLAG_BIC_STATIC(IN_CREATE);
    CREATE_INOTIFY_WATCH_FLAG_BIC_STATIC(IN_DELETE);
    CREATE_INOTIFY_WATCH_FLAG_BIC_STATIC(IN_DELETE_SELF);
    CREATE_INOTIFY_WATCH_FLAG_BIC_STATIC(IN_MOVE_SELF);
    CREATE_INOTIFY_WATCH_FLAG_BIC_STATIC(IN_UNMOUNT);
    CREATE_INOTIFY_WATCH_FLAG_BIC_STATIC(IN_Q_OVERFLOW);
    CREATE_INOTIFY_WATCH_FLAG_BIC_STATIC(IN_IGNORED);
    CREATE_INOTIFY_WATCH_FLAG_BIC_STATIC(IN_ONLYDIR);
    CREATE_INOTIFY_WATCH_FLAG_BIC_STATIC(IN_DONT_FOLLOW);
    CREATE_INOTIFY_WATCH_FLAG_BIC_STATIC(IN_MASK_ADD);
    CREATE_INOTIFY_WATCH_FLAG_BIC_STATIC(IN_ISDIR);
    CREATE_INOTIFY_WATCH_FLAG_BIC_STATIC(IN_ONESHOT);
    CREATE_INOTIFY_WATCH_FLAG_BIC_STATIC(IN_ALL_EVENTS);
  }

}/*}}}*/

void bic_inotify_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (int)-1;
}/*}}}*/

void bic_inotify_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  int ntfy_fd = (int)location_ptr->v_data_ptr;

  if (ntfy_fd != -1)
  {
    close(ntfy_fd);
  }
}/*}}}*/

bool bic_inotify_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_inotify_method_Inotify_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - create inotify instance -
  int ntfy_fd = inotify_init();

  // - ERROR -
  if (ntfy_fd == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_INOTIFY_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set destination data pointer -
  dst_location->v_data_ptr = (int)ntfy_fd;

  return true;
}/*}}}*/

bool bic_inotify_method_add_watch_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
path:c_bi_class_string
mask:retrieve_integer
>
method add_watch
; @end

  int ntfy_fd = (int)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - add new watch to inotify -
  int wd = inotify_add_watch(ntfy_fd,string_ptr->data,mask);

  // - ERROR -
  if (wd == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_INOTIFY_ADD_WATCH_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create inotify watch object -
  inotify_watch_s *iw_ptr = (inotify_watch_s *)cmalloc(sizeof(inotify_watch_s));
  iw_ptr->init();

  dst_location->v_reference_cnt.atomic_inc();
  iw_ptr->inotify_loc = dst_location;

  src_0_location->v_reference_cnt.atomic_inc();
  iw_ptr->name_loc = src_0_location;

  iw_ptr->mask = mask;
  iw_ptr->wd = wd;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_inotify_watch,iw_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_inotify_method_read_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  int ntfy_fd = (int)dst_location->v_data_ptr;

  char buff[512];
  ssize_t read_cnt = read(ntfy_fd,buff,512);

  // - ERROR -
  if (read_cnt == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_INOTIFY_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  pointer_array_s *array_ptr = it.get_new_array_ptr();

  // - process inotify events -
  if (read_cnt > 0)
  {
    char *b_ptr = buff;
    char *b_ptr_end = b_ptr + read_cnt;
    do {
      inotify_event *event = (inotify_event *)b_ptr;

      // - create inotify event object -
      inotify_event_s *ie_ptr = (inotify_event_s *)cmalloc(sizeof(inotify_event_s));
      ie_ptr->init();

      ie_ptr->wd = event->wd;
      ie_ptr->mask = event->mask;
      ie_ptr->cookie = event->cookie;

      // - set inotify event name -
      string_s *string_ptr = it.get_new_string_ptr();
      string_ptr->set(strlen(event->name),event->name);

      BIC_CREATE_NEW_LOCATION(name_location,c_bi_class_string,string_ptr);
      ie_ptr->name_loc = name_location;

      // - create inotify event location -
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_inotify_event,ie_ptr)
      array_ptr->push(new_location);

      b_ptr += sizeof(inotify_event) + event->len;
    } while(b_ptr < b_ptr_end);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_inotify_method_get_fd_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = (int)dst_location->v_data_ptr;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_inotify_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Inotify"),"Inotify");
  );

  return true;
}/*}}}*/

bool bic_inotify_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Inotify");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class INOTIFY_WATCH -
built_in_class_s inotify_watch_class =
{/*{{{*/
  "InotifyWatch",
  c_modifier_public | c_modifier_final,
  6, inotify_watch_methods,
  0, inotify_watch_variables,
  bic_inotify_watch_consts,
  bic_inotify_watch_init,
  bic_inotify_watch_clear,
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

built_in_method_s inotify_watch_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_inotify_watch_operator_binary_equal
  },
  {
    "watch_id#0",
    c_modifier_public | c_modifier_final,
    bic_inotify_watch_method_watch_id_0
  },
  {
    "mask#0",
    c_modifier_public | c_modifier_final,
    bic_inotify_watch_method_mask_0
  },
  {
    "name#0",
    c_modifier_public | c_modifier_final,
    bic_inotify_watch_method_name_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_inotify_watch_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_inotify_watch_method_print_0
  },
};/*}}}*/

built_in_variable_s inotify_watch_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_INOTIFY_WATCH_RETRIEVE_INTEGER(NAME) \
{/*{{{*/\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  inotify_watch_s *iw_ptr = (inotify_watch_s *)dst_location->v_data_ptr;\
\
  long long int result = iw_ptr->NAME;\
\
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
\
  return true;\
}/*}}}*/

void bic_inotify_watch_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_inotify_watch_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (inotify_watch_s *)nullptr;
}/*}}}*/

void bic_inotify_watch_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  inotify_watch_s *iw_ptr = (inotify_watch_s *)location_ptr->v_data_ptr;

  if (iw_ptr != nullptr)
  {
    iw_ptr->clear(it);
    cfree(iw_ptr);
  }
}/*}}}*/

bool bic_inotify_watch_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_inotify_watch_method_watch_id_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INOTIFY_WATCH_RETRIEVE_INTEGER(wd);
}/*}}}*/

bool bic_inotify_watch_method_mask_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INOTIFY_WATCH_RETRIEVE_INTEGER(mask);
}/*}}}*/

bool bic_inotify_watch_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  inotify_watch_s *iw_ptr = (inotify_watch_s *)dst_location->v_data_ptr;

  iw_ptr->name_loc->v_reference_cnt.atomic_inc();
  BIC_SET_RESULT(iw_ptr->name_loc);

  return true;
}/*}}}*/

bool bic_inotify_watch_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("InotifyWatch"),"InotifyWatch");
  );

  return true;
}/*}}}*/

bool bic_inotify_watch_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("InotifyWatch");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class INOTIFY_EVENT -
built_in_class_s inotify_event_class =
{/*{{{*/
  "InotifyEvent",
  c_modifier_public | c_modifier_final,
  7, inotify_event_methods,
  0, inotify_event_variables,
  bic_inotify_event_consts,
  bic_inotify_event_init,
  bic_inotify_event_clear,
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

built_in_method_s inotify_event_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_inotify_event_operator_binary_equal
  },
  {
    "watch_id#0",
    c_modifier_public | c_modifier_final,
    bic_inotify_event_method_watch_id_0
  },
  {
    "mask#0",
    c_modifier_public | c_modifier_final,
    bic_inotify_event_method_mask_0
  },
  {
    "cookie#0",
    c_modifier_public | c_modifier_final,
    bic_inotify_event_method_cookie_0
  },
  {
    "name#0",
    c_modifier_public | c_modifier_final,
    bic_inotify_event_method_name_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_inotify_event_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_inotify_event_method_print_0
  },
};/*}}}*/

built_in_variable_s inotify_event_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_INOTIFY_EVENT_RETRIEVE_INTEGER(NAME) \
{/*{{{*/\
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
\
  inotify_event_s *ie_ptr = (inotify_event_s *)dst_location->v_data_ptr;\
\
  long long int result = ie_ptr->NAME;\
\
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
\
  return true;\
}/*}}}*/

void bic_inotify_event_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_inotify_event_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (inotify_event_s *)nullptr;
}/*}}}*/

void bic_inotify_event_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  inotify_event_s *ie_ptr = (inotify_event_s *)location_ptr->v_data_ptr;

  if (ie_ptr != nullptr)
  {
    ie_ptr->clear(it);
    cfree(ie_ptr);
  }
}/*}}}*/

bool bic_inotify_event_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_inotify_event_method_watch_id_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INOTIFY_EVENT_RETRIEVE_INTEGER(wd);
}/*}}}*/

bool bic_inotify_event_method_mask_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INOTIFY_EVENT_RETRIEVE_INTEGER(mask);
}/*}}}*/

bool bic_inotify_event_method_cookie_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_INOTIFY_EVENT_RETRIEVE_INTEGER(cookie);
}/*}}}*/

bool bic_inotify_event_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  inotify_event_s *ie_ptr = (inotify_event_s *)dst_location->v_data_ptr;

  ie_ptr->name_loc->v_reference_cnt.atomic_inc();
  BIC_SET_RESULT(ie_ptr->name_loc);

  return true;
}/*}}}*/

bool bic_inotify_event_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("InotifyEvent"),"InotifyEvent");
  );

  return true;
}/*}}}*/

bool bic_inotify_event_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("InotifyEvent");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

