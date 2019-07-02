
#ifndef __VLC_MODULE_H
#define __VLC_MODULE_H

@begin
include "ucl_vlc.h"
@end

// - VLC indexes of built in classes -
extern unsigned c_bi_class_vlc_instance;
extern unsigned c_bi_class_vlc_media;
extern unsigned c_bi_class_vlc_player;

// - VLC module -
extern "C" EXPORT built_in_module_s module;

// - VLC classes -
extern built_in_class_s *vlc_classes[];

// - VLC error identifiers -
enum
{
  c_error_VLC_INSTANCE_EXPECTED_STRING_AS_ARGUMENT = 0,
  c_error_VLC_INSTANCE_NEW_ERROR,
  c_error_VLC_MEDIA_NEW_ERROR,
  c_error_VLC_PLAYER_NEW_FROM_MEDIA_ERROR,
  c_error_VLC_PLAYER_INVALID_VIDEO_FORMAT_PARAMETERS,
  c_error_VLC_PLAYER_PLAY_ERROR,
};

// - VLC error strings -
extern const char *vlc_error_strings[];

// - VLC initialize -
bool vlc_initialize(script_parser_s &sp);

// - VLC print exception -
bool vlc_print_exception(interpreter_s &it,exception_s &exception);

// - class VLC_INSTANCE -
extern built_in_variable_s vlc_instance_variables[];
extern built_in_method_s vlc_instance_methods[];
extern built_in_class_s vlc_instance_class;

void bic_vlc_instance_consts(location_array_s &const_locations);
void bic_vlc_instance_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_vlc_instance_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_vlc_instance_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vlc_instance_method_VlcInstance_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vlc_instance_method_media_path_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vlc_instance_method_media_location_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vlc_instance_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vlc_instance_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class VLC_MEDIA -
extern built_in_variable_s vlc_media_variables[];
extern built_in_method_s vlc_media_methods[];
extern built_in_class_s vlc_media_class;

void bic_vlc_media_consts(location_array_s &const_locations);
void bic_vlc_media_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_vlc_media_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_vlc_media_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vlc_media_method_player_5(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vlc_media_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vlc_media_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class VLC_PLAYER -
extern built_in_variable_s vlc_player_variables[];
extern built_in_method_s vlc_player_methods[];
extern built_in_class_s vlc_player_class;

void bic_vlc_player_consts(location_array_s &const_locations);
void bic_vlc_player_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_vlc_player_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_vlc_player_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vlc_player_method_play_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vlc_player_method_pause_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vlc_player_method_stop_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vlc_player_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_vlc_player_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

