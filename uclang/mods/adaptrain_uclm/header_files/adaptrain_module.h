
#ifndef __ADAPTRAIN_MODULE_H
#define __ADAPTRAIN_MODULE_H

@begin
include "ucl_adaptrain.h"
@end

// - ADAPTRAIN indexes of built in classes -
extern unsigned c_bi_class_ato_aru;
extern unsigned c_bi_class_ato_aru_record;
extern unsigned c_bi_class_optim_speed_profile;
extern unsigned c_bi_class_optim_line_section;
extern unsigned c_bi_class_optim_line_segment;
extern unsigned c_bi_class_ato_loco;
extern unsigned c_bi_class_ato_train;
extern unsigned c_bi_class_ato_trip;
extern unsigned c_bi_class_ato_trip_sec;
extern unsigned c_bi_class_ato_line_sec;
extern unsigned c_bi_class_ato_line_sec_point;

// - ADAPTRAIN module -
extern built_in_module_s module;

// - ADAPTRAIN classes -
extern built_in_class_s *adaptrain_classes[];

// - ADAPTRAIN error identifiers -
enum
{
  c_error_ATO_ARU_ARCHIVE_WRONG_DATA = 0,
  c_error_ATO_ARU_ARCHIVE_WRONG_COOKIE,
  c_error_ATO_ARU_ARCHIVE_UNSUPPORTED_VALUE_TYPE,
  c_error_ATO_ARU_ARCHIVE_INDEX_EXCEEDS_RANGE,
  c_error_ATO_ARU_ARCHIVE_DIFFERENT_X_VALUES_AND_VALUES_SIZES,
  c_error_ATO_ARU_ARCHIVE_X_VALUE_WRONG_TYPE,
  c_error_ATO_ARU_ARCHIVE_VALUE_WRONG_TYPE,
  c_error_ATO_ARU_RECORD_UNSUPPORTED_VALUE_TYPE,
  c_error_OPTIM_SPEED_PROFILE_WRONG_DATA,
  c_error_OPTIM_LINE_SECTION_WRONG_DATA,
  c_error_OPTIM_LINE_SECTION_INDEX_EXCEEDS_RANGE,
  c_error_ATO_LOCO_WRONG_DATA,
  c_error_ATO_TRAIN_WRONG_DATA,
  c_error_ATO_TRIP_WRONG_DATA,
  c_error_ATO_TRIP_WRONG_MD5_CHECKSUM,
  c_error_ATO_TRIP_INDEX_EXCEEDS_RANGE,
  c_error_ATO_LINE_SEC_WRONG_DATA,
  c_error_ATO_LINE_SEC_WRONG_MD5_CHECKSUM,
  c_error_ATO_LINE_SEC_INDEX_EXCEEDS_RANGE,
};

// - ADAPTRAIN error strings -
extern const char *adaptrain_error_strings[];

// - ADAPTRAIN initialize -
bool adaptrain_initialize(script_parser_s &sp);

// - ADAPTRAIN print exception -
bool adaptrain_print_exception(interpreter_s &it,exception_s &exception);

// - class ATO_ARU -
extern built_in_variable_s ato_aru_variables[];
extern built_in_method_s ato_aru_methods[];
extern built_in_class_s ato_aru_class;

void bic_ato_aru_consts(location_array_s &const_locations);
void bic_ato_aru_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_ato_aru_clear(interpreter_thread_s &it,location_s *location_ptr);
unsigned bic_ato_aru_length(location_s *location_ptr);
location_s *bic_ato_aru_item(interpreter_thread_s &it,location_s *location_ptr,unsigned index);
unsigned bic_ato_aru_first_idx(location_s *location_ptr);
unsigned bic_ato_aru_next_idx(location_s *location_ptr,unsigned index);

bool bic_ato_aru_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_aru_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_aru_method_AtoAru_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_aru_method_create_5(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_aru_method_pack_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_aru_method_unpack_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_aru_method_data_type_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_aru_method_primary_key_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_aru_method_version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_aru_method_first_x_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_aru_method_last_x_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_aru_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_aru_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_aru_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_aru_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_aru_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_aru_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class ATO_ARU_RECORD -
extern built_in_variable_s ato_aru_record_variables[];
extern built_in_method_s ato_aru_record_methods[];
extern built_in_class_s ato_aru_record_class;

void bic_ato_aru_record_consts(location_array_s &const_locations);
void bic_ato_aru_record_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_ato_aru_record_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_ato_aru_record_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_aru_record_method_status_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_aru_record_method_x_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_aru_record_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_aru_record_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_aru_record_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class OPTIM_SPEED_PROFILE -
extern built_in_variable_s optim_speed_profile_variables[];
extern built_in_method_s optim_speed_profile_methods[];
extern built_in_class_s optim_speed_profile_class;

void bic_optim_speed_profile_consts(location_array_s &const_locations);
void bic_optim_speed_profile_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_optim_speed_profile_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_optim_speed_profile_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_optim_speed_profile_method_OptimSpeedProfile_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_optim_speed_profile_method_TripId_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_optim_speed_profile_method_TimeStamp_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_optim_speed_profile_method_Version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_optim_speed_profile_method_InitSectionIndx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_optim_speed_profile_method_LineSectionIds_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_optim_speed_profile_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_optim_speed_profile_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class OPTIM_LINE_SECTION -
extern built_in_variable_s optim_line_section_variables[];
extern built_in_method_s optim_line_section_methods[];
extern built_in_class_s optim_line_section_class;

void bic_optim_line_section_consts(location_array_s &const_locations);
void bic_optim_line_section_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_optim_line_section_clear(interpreter_thread_s &it,location_s *location_ptr);
unsigned bic_optim_line_section_length(location_s *location_ptr);
location_s *bic_optim_line_section_item(interpreter_thread_s &it,location_s *location_ptr,unsigned index);
unsigned bic_optim_line_section_first_idx(location_s *location_ptr);
unsigned bic_optim_line_section_next_idx(location_s *location_ptr,unsigned index);

bool bic_optim_line_section_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_optim_line_section_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_optim_line_section_method_OptimLineSection_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_optim_line_section_method_LineSectionId_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_optim_line_section_method_TimeStamp_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_optim_line_section_method_Version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_optim_line_section_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_optim_line_section_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_optim_line_section_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_optim_line_section_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_optim_line_section_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_optim_line_section_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class OPTIM_LINE_SEGMENT -
extern built_in_variable_s optim_line_segment_variables[];
extern built_in_method_s optim_line_segment_methods[];
extern built_in_class_s optim_line_segment_class;

void bic_optim_line_segment_consts(location_array_s &const_locations);
void bic_optim_line_segment_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_optim_line_segment_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_optim_line_segment_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_optim_line_segment_method_LPindx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_optim_line_segment_method_LPindxR_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_optim_line_segment_method_Dist2RefLP_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_optim_line_segment_method_DrivingMode_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_optim_line_segment_method_TargLPindx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_optim_line_segment_method_TargLPindxR_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_optim_line_segment_method_SegmentLength_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_optim_line_segment_method_RunningTime_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_optim_line_segment_method_RunningTimeMin_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_optim_line_segment_method_TargSpeed_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_optim_line_segment_method_BegSpeed_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_optim_line_segment_method_MeanAcceleration_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_optim_line_segment_method_PeakAcceleration_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_optim_line_segment_method_TravelTime2Stat_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_optim_line_segment_method_TravelTime2StatMin_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_optim_line_segment_method_items_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_optim_line_segment_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_optim_line_segment_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class ATO_LOCO -
extern built_in_variable_s ato_loco_variables[];
extern built_in_method_s ato_loco_methods[];
extern built_in_class_s ato_loco_class;

void bic_ato_loco_consts(location_array_s &const_locations);
void bic_ato_loco_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_ato_loco_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_ato_loco_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_loco_method_AtoLoco_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_loco_method_LocoId_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_loco_method_LocoType_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_loco_method_UIC_Id_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_loco_method_TimeStamp_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_loco_method_Version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_loco_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_loco_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class ATO_TRAIN -
extern built_in_variable_s ato_train_variables[];
extern built_in_method_s ato_train_methods[];
extern built_in_class_s ato_train_class;

void bic_ato_train_consts(location_array_s &const_locations);
void bic_ato_train_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_ato_train_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_ato_train_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_train_method_AtoTrain_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_train_method_TrainId_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_train_method_TrainIdNum_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_train_method_TimeStamp_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_train_method_Version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_train_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_train_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class ATO_TRIP -
extern built_in_variable_s ato_trip_variables[];
extern built_in_method_s ato_trip_methods[];
extern built_in_class_s ato_trip_class;

void bic_ato_trip_consts(location_array_s &const_locations);
void bic_ato_trip_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_ato_trip_clear(interpreter_thread_s &it,location_s *location_ptr);
unsigned bic_ato_trip_length(location_s *location_ptr);
location_s *bic_ato_trip_item(interpreter_thread_s &it,location_s *location_ptr,unsigned index);
unsigned bic_ato_trip_first_idx(location_s *location_ptr);
unsigned bic_ato_trip_next_idx(location_s *location_ptr,unsigned index);

bool bic_ato_trip_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_trip_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_trip_method_AtoTrip_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_trip_method_pack_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_trip_method_unpack_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_trip_method_TripId_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_trip_method_TrainIdNum_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_trip_method_DepartStation_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_trip_method_DestinStation_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_trip_method_TimeStamp_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_trip_method_DepartTime_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_trip_method_DepartTime_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_trip_method_ArrivalTime_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_trip_method_ArrivalTime_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_trip_method_Version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_trip_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_trip_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_trip_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_trip_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_trip_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_trip_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class ATO_TRIP_SEC -
extern built_in_variable_s ato_trip_sec_variables[];
extern built_in_method_s ato_trip_sec_methods[];
extern built_in_class_s ato_trip_sec_class;

void bic_ato_trip_sec_consts(location_array_s &const_locations);
void bic_ato_trip_sec_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_ato_trip_sec_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_ato_trip_sec_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_trip_sec_method_LineSectionId_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_trip_sec_method_TimeStamp_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_trip_sec_method_IntermedStation_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_trip_sec_method_ArrivalTime_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_trip_sec_method_DepartTime_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_trip_sec_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_trip_sec_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class ATO_LINE_SEC -
extern built_in_variable_s ato_line_sec_variables[];
extern built_in_method_s ato_line_sec_methods[];
extern built_in_class_s ato_line_sec_class;

void bic_ato_line_sec_consts(location_array_s &const_locations);
void bic_ato_line_sec_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_ato_line_sec_clear(interpreter_thread_s &it,location_s *location_ptr);
unsigned bic_ato_line_sec_length(location_s *location_ptr);
location_s *bic_ato_line_sec_item(interpreter_thread_s &it,location_s *location_ptr,unsigned index);
unsigned bic_ato_line_sec_first_idx(location_s *location_ptr);
unsigned bic_ato_line_sec_next_idx(location_s *location_ptr,unsigned index);

bool bic_ato_line_sec_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_line_sec_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_line_sec_method_AtoLineSec_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_line_sec_method_LineSectionId_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_line_sec_method_DepartStation_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_line_sec_method_DestinStation_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_line_sec_method_GLPsId_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_line_sec_method_TextsId_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_line_sec_method_BalisesId_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_line_sec_method_TrackMenuId_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_line_sec_method_SignalLightsId_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_line_sec_method_TimeStamp_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_line_sec_method_TimeStampG_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_line_sec_method_TimeStampT_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_line_sec_method_TimeStampB_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_line_sec_method_TimeStampD_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_line_sec_method_TimeStampS_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_line_sec_method_SchedulTravelTime_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_line_sec_method_SectionLength_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_line_sec_method_StoppingDistMax_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_line_sec_method_Deceler1DistMax_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_line_sec_method_TargDisplac_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_line_sec_method_SpeedTargMin_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_line_sec_method_SpeedTargMax_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_line_sec_method_SpeedMin_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_line_sec_method_SpeedMax_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_line_sec_method_SpeedCoastMin_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_line_sec_method_TargDisplacMax_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_line_sec_method_Version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_line_sec_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_line_sec_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_line_sec_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_line_sec_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_line_sec_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_line_sec_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class ATO_LINE_SEC_POINT -
extern built_in_variable_s ato_line_sec_point_variables[];
extern built_in_method_s ato_line_sec_point_methods[];
extern built_in_class_s ato_line_sec_point_class;

void bic_ato_line_sec_point_consts(location_array_s &const_locations);
void bic_ato_line_sec_point_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_ato_line_sec_point_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_ato_line_sec_point_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_line_sec_point_method_LPindx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_line_sec_point_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ato_line_sec_point_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

