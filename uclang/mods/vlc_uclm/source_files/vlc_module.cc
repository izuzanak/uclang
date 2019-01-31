
@begin
include "vlc_module.h"
@end

// - VLC indexes of built in classes -

unsigned c_bi_class_vlc_instance = c_idx_not_exist;
unsigned c_bi_class_vlc_media = c_idx_not_exist;
unsigned c_bi_class_vlc_player = c_idx_not_exist;

// - VLC module -
EXPORT built_in_module_s module =
{/*{{{*/
  3,                   // Class count
  vlc_classes,         // Classes
  0,                   // Error base index
  6,                   // Error count
  vlc_error_strings,   // Error strings
  vlc_initialize,      // Initialize function
  vlc_print_exception, // Print exceptions function
};/*}}}*/

// - VLC classes -
built_in_class_s *vlc_classes[] =
{/*{{{*/
  &vlc_instance_class,
  &vlc_media_class,
  &vlc_player_class,
};/*}}}*/

// - VLC error strings -
const char *vlc_error_strings[] =
{/*{{{*/
  "error_VLC_INSTANCE_EXPECTED_STRING_AS_ARGUMENT",
  "error_VLC_INSTANCE_NEW_ERROR",
  "error_VLC_MEDIA_NEW_ERROR",
  "error_VLC_PLAYER_NEW_FROM_MEDIA_ERROR",
  "error_VLC_PLAYER_INVALID_VIDEO_FORMAT_PARAMETERS",
  "error_VLC_PLAYER_PLAY_ERROR",
};/*}}}*/

// - VLC initialize -
bool vlc_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize vlc_instance class identifier -
  c_bi_class_vlc_instance = class_base_idx++;

  // - initialize vlc_media class identifier -
  c_bi_class_vlc_media = class_base_idx++;

  // - initialize vlc_player class identifier -
  c_bi_class_vlc_player = class_base_idx++;

  return true;
}/*}}}*/

// - VLC print exception -
bool vlc_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_VLC_INSTANCE_EXPECTED_STRING_AS_ARGUMENT:
    {
      class_record_s &class_record = it.class_records[exception.params[0]];

      fprintf(stderr," ---------------------------------------- \n");
      fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
      print_error_line(source.source_string,source_pos);
      fprintf(stderr,"\nReceived ");
      print_class_sequence(it.class_symbol_names,it.class_records,class_stack,class_record.parent_record);
      fprintf(stderr,"%s while expecting String as VlcInstance argument\n",it.class_symbol_names[class_record.name_idx].data);
      fprintf(stderr," ---------------------------------------- \n");
    }
    break;
  case c_error_VLC_INSTANCE_NEW_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating new VLC instance\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_VLC_MEDIA_NEW_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating new VLC media from %s\n",exception.params[0] ? "path" : "location");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_VLC_PLAYER_NEW_FROM_MEDIA_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating new VLC player from media\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_VLC_PLAYER_INVALID_VIDEO_FORMAT_PARAMETERS:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nVLC player, invalid video format parameters\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_VLC_PLAYER_PLAY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nVLC player, error while trying to play\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class VLC_INSTANCE -
built_in_class_s vlc_instance_class =
{/*{{{*/
  "VlcInstance",
  c_modifier_public | c_modifier_final,
  6, vlc_instance_methods,
  0, vlc_instance_variables,
  bic_vlc_instance_consts,
  bic_vlc_instance_init,
  bic_vlc_instance_clear,
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

built_in_method_s vlc_instance_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_vlc_instance_operator_binary_equal
  },
  {
    "VlcInstance#1",
    c_modifier_public | c_modifier_final,
    bic_vlc_instance_method_VlcInstance_1
  },
  {
    "media_path#1",
    c_modifier_public | c_modifier_final,
    bic_vlc_instance_method_media_path_1
  },
  {
    "media_location#1",
    c_modifier_public | c_modifier_final,
    bic_vlc_instance_method_media_location_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_vlc_instance_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_vlc_instance_method_print_0
  },
};/*}}}*/

built_in_variable_s vlc_instance_variables[] =
{/*{{{*/
};/*}}}*/

void bic_vlc_instance_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_vlc_instance_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (libvlc_instance_t *)nullptr;
}/*}}}*/

void bic_vlc_instance_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  libvlc_instance_t *vi_ptr = (libvlc_instance_t *)location_ptr->v_data_ptr;

  if (vi_ptr != nullptr)
  {
    libvlc_release(vi_ptr);
  }
}/*}}}*/

bool bic_vlc_instance_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_vlc_instance_method_VlcInstance_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
arguments:c_bi_class_array
>
method VlcInstance
; @end

  pointer_array_s *array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

  const char *arguments[array_ptr->used];
  const char **a_ptr = arguments;

  if (array_ptr->used != 0)
  {
    pointer *p_ptr = array_ptr->data;
    pointer *p_ptr_end = p_ptr + array_ptr->used;
    do {
      location_s *item_location = it.get_location_value(*p_ptr);

      // - ERROR -
      if (item_location->v_type != c_bi_class_string)
      {
        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_VLC_INSTANCE_EXPECTED_STRING_AS_ARGUMENT,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(item_location->v_type);

        return false;
      }

      *a_ptr = ((string_s *)item_location->v_data_ptr)->data;

    } while(++a_ptr,++p_ptr < p_ptr_end);
  }

  libvlc_instance_t *vi_ptr = libvlc_new(array_ptr->used,arguments);

  // - ERROR -
  if (vi_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_VLC_INSTANCE_NEW_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  dst_location->v_data_ptr = vi_ptr;

  return true;
}/*}}}*/

bool bic_vlc_instance_method_media_path_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
path:c_bi_class_string
>
method media_path
; @end

  libvlc_instance_t *vi_ptr = (libvlc_instance_t *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  libvlc_media_t *media_ptr = libvlc_media_new_path(vi_ptr,string_ptr->data);

  // - ERROR -
  if (media_ptr == nullptr)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_VLC_MEDIA_NEW_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(1);

    return false;
  }

  // - create vlc media object -
  vlc_media_s *vm_ptr = (vlc_media_s *)cmalloc(sizeof(vlc_media_s));
  vm_ptr->init();

  // - set instance reference -
  dst_location->v_reference_cnt.atomic_inc();
  vm_ptr->instance_loc = dst_location;

  vm_ptr->media_ptr = media_ptr;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_vlc_media,vm_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_vlc_instance_method_media_location_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
url:c_bi_class_string
>
method media_location
; @end

  libvlc_instance_t *vi_ptr = (libvlc_instance_t *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  libvlc_media_t *media_ptr = libvlc_media_new_location(vi_ptr,string_ptr->data);

  // - ERROR -
  if (media_ptr == nullptr)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_VLC_MEDIA_NEW_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(0);

    return false;
  }

  // - create vlc media object -
  vlc_media_s *vm_ptr = (vlc_media_s *)cmalloc(sizeof(vlc_media_s));
  vm_ptr->init();

  // - set instance reference -
  dst_location->v_reference_cnt.atomic_inc();
  vm_ptr->instance_loc = dst_location;

  vm_ptr->media_ptr = media_ptr;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_vlc_media,vm_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_vlc_instance_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("VlcInstance"),"VlcInstance");
  );

  return true;
}/*}}}*/

bool bic_vlc_instance_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("VlcInstance");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class VLC_MEDIA -
built_in_class_s vlc_media_class =
{/*{{{*/
  "VlcMedia",
  c_modifier_public | c_modifier_final,
  4, vlc_media_methods,
  0, vlc_media_variables,
  bic_vlc_media_consts,
  bic_vlc_media_init,
  bic_vlc_media_clear,
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

built_in_method_s vlc_media_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_vlc_media_operator_binary_equal
  },
  {
    "player#0",
    c_modifier_public | c_modifier_final,
    bic_vlc_media_method_player_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_vlc_media_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_vlc_media_method_print_0
  },
};/*}}}*/

built_in_variable_s vlc_media_variables[] =
{/*{{{*/
};/*}}}*/

void bic_vlc_media_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_vlc_media_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (vlc_media_s *)nullptr;
}/*}}}*/

void bic_vlc_media_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  vlc_media_s *vm_ptr = (vlc_media_s *)location_ptr->v_data_ptr;

  if (vm_ptr != nullptr)
  {
    vm_ptr->clear(it);
    cfree(vm_ptr);
  }
}/*}}}*/

bool bic_vlc_media_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_vlc_media_method_player_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  vlc_media_s *vm_ptr = (vlc_media_s *)dst_location->v_data_ptr;

  libvlc_media_player_t *player_ptr = libvlc_media_player_new_from_media(vm_ptr->media_ptr);

  // - ERROR -
  if (player_ptr == nullptr)
  {
    exception_s::throw_exception(it,module.error_base + c_error_VLC_PLAYER_NEW_FROM_MEDIA_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create vlc player object -
  vlc_player_s *vp_ptr = (vlc_player_s *)cmalloc(sizeof(vlc_player_s));
  vp_ptr->init();

  // - set instance reference -
  vm_ptr->instance_loc->v_reference_cnt.atomic_inc();
  vp_ptr->instance_loc = vm_ptr->instance_loc;

  vp_ptr->player_ptr = player_ptr;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_vlc_player,vp_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_vlc_media_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("VlcMedia"),"VlcMedia");
  );

  return true;
}/*}}}*/

bool bic_vlc_media_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("VlcMedia");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class VLC_PLAYER -
built_in_class_s vlc_player_class =
{/*{{{*/
  "VlcPlayer",
  c_modifier_public | c_modifier_final,
  8, vlc_player_methods,
  1, vlc_player_variables,
  bic_vlc_player_consts,
  bic_vlc_player_init,
  bic_vlc_player_clear,
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

built_in_method_s vlc_player_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_vlc_player_operator_binary_equal
  },
  {
    "video_set_format#4",
    c_modifier_public | c_modifier_final,
    bic_vlc_player_method_video_set_format_4
  },
  {
    "video_set_callbacks#0",
    c_modifier_public | c_modifier_final,
    bic_vlc_player_method_video_set_callbacks_0
  },
  {
    "play#0",
    c_modifier_public | c_modifier_final,
    bic_vlc_player_method_play_0
  },
  {
    "pause#0",
    c_modifier_public | c_modifier_final,
    bic_vlc_player_method_pause_0
  },
  {
    "stop#0",
    c_modifier_public | c_modifier_final,
    bic_vlc_player_method_stop_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_vlc_player_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_vlc_player_method_print_0
  },
};/*}}}*/

built_in_variable_s vlc_player_variables[] =
{/*{{{*/

  // - vlc player chroma constants -
  { "CHROMA_RV24", c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_vlc_player_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert vlc player chroma constants -
  {
    const_locations.push_blanks(1);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 1);

#define CREATE_VLC_PLAYER_CHROMA_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_VLC_PLAYER_CHROMA_BIC_STATIC(c_vlc_chroma_RV24);
  }

}/*}}}*/

void bic_vlc_player_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (vlc_player_s *)nullptr;
}/*}}}*/

void bic_vlc_player_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  vlc_player_s *vp_ptr = (vlc_player_s *)location_ptr->v_data_ptr;

  if (vp_ptr != nullptr)
  {
    vp_ptr->clear(it);
    cfree(vp_ptr);
  }
}/*}}}*/

bool bic_vlc_player_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_vlc_player_method_video_set_format_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
chroma:retrieve_integer
width:retrieve_integer
height:retrieve_integer
pitch:retrieve_integer
>
method video_set_format
; @end

  // - ERROR -
  if (chroma < 0 || chroma >= c_vlc_chroma_count ||
      width <= 0 || height <= 0 ||
      pitch < width*c_vlc_chroma_sizes[chroma])
  {
    exception_s::throw_exception(it,module.error_base + c_error_VLC_PLAYER_INVALID_VIDEO_FORMAT_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  vlc_player_s *vp_ptr = (vlc_player_s *)dst_location->v_data_ptr;

  // - set player video format -
  libvlc_video_set_format(vp_ptr->player_ptr,c_vlc_chroma_fourcc[chroma],width,height,pitch);

  // - store player video properties -
  vp_ptr->chroma = chroma;
  vp_ptr->width  = width;
  vp_ptr->height = height;
  vp_ptr->pitch  = pitch;

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_vlc_player_method_video_set_callbacks_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  vlc_player_s *vp_ptr = (vlc_player_s *)dst_location->v_data_ptr;

  // - set player video callbacks -
  libvlc_video_set_callbacks(vp_ptr->player_ptr,vlc_player_s::lock,vlc_player_s::unlock,vlc_player_s::display,vp_ptr);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_vlc_player_method_play_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - ERROR -
  if (libvlc_media_player_play(((vlc_player_s *)dst_location->v_data_ptr)->player_ptr) != 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_VLC_PLAYER_PLAY_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_vlc_player_method_pause_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  libvlc_media_player_pause(((vlc_player_s *)dst_location->v_data_ptr)->player_ptr);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_vlc_player_method_stop_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  libvlc_media_player_stop(((vlc_player_s *)dst_location->v_data_ptr)->player_ptr);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_vlc_player_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("VlcPlayer"),"VlcPlayer");
  );

  return true;
}/*}}}*/

bool bic_vlc_player_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("VlcPlayer");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

