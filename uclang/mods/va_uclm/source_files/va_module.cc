
@begin
include "va_module.h"
@end

// - VA indexes of built in classes -

unsigned c_bi_class_va_display = c_idx_not_exist;

// - VA module -
EXPORT built_in_module_s module =
{/*{{{*/
  1,                  // Class count
  va_classes,         // Classes
  0,                  // Error base index
  3,                  // Error count
  va_error_strings,   // Error strings
  va_initialize,      // Initialize function
  va_print_exception, // Print exceptions function
};/*}}}*/

// - VA classes -
built_in_class_s *va_classes[] =
{/*{{{*/
  &va_display_class,
};/*}}}*/

// - VA error strings -
const char *va_error_strings[] =
{/*{{{*/
  "error_VA_DISPLAY_NATIVE_OPEN_ERROR",
  "error_VA_DISPLAY_GET_DISPLAY_ERROR",
  "error_VA_DISPLAY_INITIALIZE_ERROR",
};/*}}}*/

// - VA initialize -
bool va_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize va_display class identifier -
  c_bi_class_va_display = class_base_idx++;

  return true;
}/*}}}*/

// - VA print exception -
bool va_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_VA_DISPLAY_NATIVE_OPEN_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while openning native display\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_VA_DISPLAY_GET_DISPLAY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot create VaDisplay from native display\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_VA_DISPLAY_INITIALIZE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while initializing VaDisplay\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class VA_DISPLAY -
built_in_class_s va_display_class =
{/*{{{*/
  "VaDisplay",
  c_modifier_public | c_modifier_final,
  4, va_display_methods,
  0, va_display_variables,
  bic_va_display_consts,
  bic_va_display_init,
  bic_va_display_clear,
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

built_in_method_s va_display_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_va_display_operator_binary_equal
  },
  {
    "VaDisplay#1",
    c_modifier_public | c_modifier_final,
    bic_va_display_method_VaDisplay_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_va_display_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_va_display_method_print_0
  },
};/*}}}*/

built_in_variable_s va_display_variables[] =
{/*{{{*/
};/*}}}*/

void bic_va_display_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_va_display_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (va_display_s *)nullptr;
}/*}}}*/

void bic_va_display_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  va_display_s *vd_ptr = (va_display_s *)location_ptr->v_data_ptr;

  if (vd_ptr != nullptr)
  {
    vd_ptr->clear(it);
    cfree(vd_ptr);
  }
}/*}}}*/

bool bic_va_display_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_va_display_method_VaDisplay_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
name:c_bi_class_string
>
method VADisplay
; @end

  Display *x11_display_ptr = XOpenDisplay(((string_s *)src_0_location->v_data_ptr)->data);

  // - ERROR -
  if (x11_display_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_VA_DISPLAY_NATIVE_OPEN_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  VADisplay display_ptr = vaGetDisplay(x11_display_ptr);

  // - ERROR -
  if (display_ptr == nullptr)
  {
    XCloseDisplay(x11_display_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_VA_DISPLAY_GET_DISPLAY_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create va display object -
  va_display_s *vd_ptr = (va_display_s *)cmalloc(sizeof(va_display_s));
  vd_ptr->init();

  vd_ptr->x11_display_ptr = x11_display_ptr;
  vd_ptr->display_ptr = display_ptr;

  // - set error message callback -
  vaSetErrorCallback(display_ptr,va_display_s::error_callback,dst_location);

  // - set info message callback -
  vaSetInfoCallback(display_ptr,va_display_s::info_callback,dst_location);

  // - ERROR -
  if (vaInitialize(display_ptr,&vd_ptr->major_version,&vd_ptr->minor_version) != VA_STATUS_SUCCESS)
  {
    vd_ptr->clear(it);
    cfree(vd_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_VA_DISPLAY_INITIALIZE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  dst_location->v_data_ptr = vd_ptr;

  return true;
}/*}}}*/

bool bic_va_display_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("VaDisplay"),"VaDisplay");
  );

  return true;
}/*}}}*/

bool bic_va_display_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("VaDisplay");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

