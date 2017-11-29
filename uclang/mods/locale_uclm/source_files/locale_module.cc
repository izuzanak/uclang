
@begin
include "locale_module.h"
@end

// - LOCALE indexes of built in classes -
unsigned c_bi_class_locale = c_idx_not_exist;

// - LOCALE module -
built_in_module_s module =
{/*{{{*/
  1,                      // Class count
  locale_classes,         // Classes

  0,                      // Error base index
  4,                      // Error count
  locale_error_strings,   // Error strings

  locale_initialize,      // Initialize function
  locale_print_exception, // Print exceptions function
};/*}}}*/

// - LOCALE classes -
built_in_class_s *locale_classes[] =
{/*{{{*/
  &locale_class,
};/*}}}*/

// - LOCALE error strings -
const char *locale_error_strings[] =
{/*{{{*/
  "error_LOCALE_BIND_MESSAGE_DOMAIN_ERROR",
  "error_LOCALE_MESSAGE_DOMAIN_ERROR",
  "error_LOCALE_INVALID_LOCALE_CATEGORY",
  "error_LOCALE_LOCALE_ERROR",
};/*}}}*/

// - LOCALE initialize -
bool locale_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize locale class identifier -
  c_bi_class_locale = class_base_idx++;

  return true;
}/*}}}*/

// - LOCALE print exception -
bool locale_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_LOCALE_BIND_MESSAGE_DOMAIN_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while %s base directory of message domain\n",exception.params[0] ? "retrieving" : "setting");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_LOCALE_MESSAGE_DOMAIN_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while %s message domain\n",exception.params[0] ? "retrieving" : "setting");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_LOCALE_INVALID_LOCALE_CATEGORY:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid locale category\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_LOCALE_LOCALE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while %s current locale\n",exception.params[0] ? "retrieving" : "setting");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class LOCALE -
built_in_class_s locale_class =
{/*{{{*/
  "Locale",
  c_modifier_public | c_modifier_final,
  9, locale_methods,
  13, locale_variables,
  bic_locale_consts,
  bic_locale_init,
  bic_locale_clear,
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

built_in_method_s locale_methods[] =
{/*{{{*/
  {
    "bind_domain#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_locale_method_bind_domain_2
  },
  {
    "bind_domain#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_locale_method_bind_domain_1
  },
  {
    "domain#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_locale_method_domain_1
  },
  {
    "domain#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_locale_method_domain_0
  },
  {
    "locale#2",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_locale_method_locale_2
  },
  {
    "locale#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_locale_method_locale_1
  },
  {
    "gettext#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_locale_method_gettext_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_locale_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_locale_method_print_0
  },
};/*}}}*/

built_in_variable_s locale_variables[] =
{/*{{{*/

  // - locale category constants -
  { "LC_CTYPE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "LC_NUMERIC", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "LC_TIME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "LC_COLLATE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "LC_MONETARY", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "LC_MESSAGES", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "LC_ALL", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "LC_PAPER", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "LC_NAME", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "LC_ADDRESS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "LC_TELEPHONE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "LC_MEASUREMENT", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "LC_IDENTIFICATION", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_locale_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert locale category constants -
  {
    const_locations.push_blanks(13);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 13);

#define CREATE_LOCALE_CATEGORY_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_LOCALE_CATEGORY_BIC_STATIC(LC_CTYPE);
    CREATE_LOCALE_CATEGORY_BIC_STATIC(LC_NUMERIC);
    CREATE_LOCALE_CATEGORY_BIC_STATIC(LC_TIME);
    CREATE_LOCALE_CATEGORY_BIC_STATIC(LC_COLLATE);
    CREATE_LOCALE_CATEGORY_BIC_STATIC(LC_MONETARY);
    CREATE_LOCALE_CATEGORY_BIC_STATIC(LC_MESSAGES);
    CREATE_LOCALE_CATEGORY_BIC_STATIC(LC_ALL);
    CREATE_LOCALE_CATEGORY_BIC_STATIC(LC_PAPER);
    CREATE_LOCALE_CATEGORY_BIC_STATIC(LC_NAME);
    CREATE_LOCALE_CATEGORY_BIC_STATIC(LC_ADDRESS);
    CREATE_LOCALE_CATEGORY_BIC_STATIC(LC_TELEPHONE);
    CREATE_LOCALE_CATEGORY_BIC_STATIC(LC_MEASUREMENT);
    CREATE_LOCALE_CATEGORY_BIC_STATIC(LC_IDENTIFICATION);
  }
}/*}}}*/

void bic_locale_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_locale_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_locale_method_bind_domain_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_locale,"bind_domain#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  // - ERROR -
  if (bindtextdomain(
        ((string_s *)src_0_location->v_data_ptr)->data,
        ((string_s *)src_1_location->v_data_ptr)->data) == nullptr)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_LOCALE_BIND_MESSAGE_DOMAIN_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(0);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_locale_method_bind_domain_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_locale,"bind_domain#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  char *base_dir = bindtextdomain(((string_s *)src_0_location->v_data_ptr)->data,nullptr);

  // - ERROR -
  if (base_dir == nullptr)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_LOCALE_BIND_MESSAGE_DOMAIN_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(1);
    return false;
  }

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(base_dir),base_dir);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_locale_method_domain_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_locale,"domain#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - ERROR -
  if (textdomain(((string_s *)src_0_location->v_data_ptr)->data) == nullptr)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_LOCALE_MESSAGE_DOMAIN_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(0);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_locale_method_domain_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  char *domain = textdomain(nullptr);

  // - ERROR -
  if (domain == nullptr)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_LOCALE_MESSAGE_DOMAIN_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(1);
    return false;
  }

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(domain),domain);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_locale_method_locale_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_integer ||
      src_1_location->v_type != c_bi_class_string )
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_locale,"locale#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  long long int category = (long long int)src_0_location->v_data_ptr;

  switch (category)
  {
    case LC_CTYPE:
    case LC_NUMERIC:
    case LC_TIME:
    case LC_COLLATE:
    case LC_MONETARY:
    case LC_MESSAGES:
    case LC_ALL:
    case LC_PAPER:
    case LC_NAME:
    case LC_ADDRESS:
    case LC_TELEPHONE:
    case LC_MEASUREMENT:
    case LC_IDENTIFICATION:
      break;

    // - ERROR -
    default:
      exception_s::throw_exception(it,module.error_base + c_error_LOCALE_INVALID_LOCALE_CATEGORY,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
  }

  // - ERROR -
  if (setlocale(category,((string_s *)src_1_location->v_data_ptr)->data) == nullptr)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_LOCALE_LOCALE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(0);
    return false;
  }

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_locale_method_locale_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_integer)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_locale,"locale#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  long long int category = (long long int)src_0_location->v_data_ptr;

  switch (category)
  {
    case LC_CTYPE:
    case LC_NUMERIC:
    case LC_TIME:
    case LC_COLLATE:
    case LC_MONETARY:
    case LC_MESSAGES:
    case LC_ALL:
    case LC_PAPER:
    case LC_NAME:
    case LC_ADDRESS:
    case LC_TELEPHONE:
    case LC_MEASUREMENT:
    case LC_IDENTIFICATION:
      break;

    // - ERROR -
    default:
      exception_s::throw_exception(it,module.error_base + c_error_LOCALE_INVALID_LOCALE_CATEGORY,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
  }

  char *locale = setlocale(category,nullptr);

  // - ERROR -
  if (locale == nullptr)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_LOCALE_LOCALE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(1);
    return false;
  }

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(locale),locale);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_locale_method_gettext_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_locale,"gettext#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  char *message = gettext(((string_s *)src_0_location->v_data_ptr)->data);

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(message),message);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_locale_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Locale"),"Locale");
  );

  return true;
}/*}}}*/

bool bic_locale_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Locale");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

