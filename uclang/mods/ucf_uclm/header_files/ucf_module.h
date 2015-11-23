
#ifndef __UCF_MODULE_H
#define __UCF_MODULE_H

@begin
include "ucl_ucf.h"
@end

// - UCF indexes of built in classes -
extern unsigned c_bi_class_system;
extern unsigned c_bi_class_time;
extern unsigned c_bi_class_cfg_file;
extern unsigned c_bi_class_ucf_log;
extern unsigned c_bi_class_ucf_mutex;
extern unsigned c_bi_class_ucf_led;
extern unsigned c_bi_class_serial;
extern unsigned c_bi_class_var_store;
extern unsigned c_bi_class_var_slot;
extern unsigned c_bi_class_nvm_segment;
extern unsigned c_bi_class_msg_queue;
extern unsigned c_bi_class_bcc;
extern unsigned c_bi_class_crc;
extern unsigned c_bi_class_md5;

// - UCF module -
extern built_in_module_s module;

// - UCF classes -
extern built_in_class_s *ucf_classes[];

// - UCF error identifiers -
enum
{
  c_error_TIME_EXPECTED_MINIMAL_YEAR_VALUE = 0,
  c_error_TIME_WRONG_INIT_STRING,
  c_error_CFG_FILE_OPEN_ERROR,
  c_error_CFG_FILE_SECTION_NAME_ERROR,
  c_error_CFG_FILE_ENTRY_NAME_ERROR,
  c_error_UCF_LOG_NEGATIVE_SIZE_OF_LOG_FILE,
  c_error_UCF_LOG_NEGATIVE_OR_ZERO_COUNT_OF_LOG_FILES,
  c_error_UCF_LOG_NEGATIVE_VERBOSITY,
  c_error_UCF_LOG_CANNOT_CREATE_LOG_FILE,
  c_error_UCF_LOG_NEGATIVE_PRIORITY_LEVEL,
  c_error_UCF_LOG_CANNOT_OPEN_LOG_NVM_SEGMENT,
  c_error_UCF_MUTEX_CREATE_ERROR,
  c_error_UCF_MUTEX_OPEN_ERROR,
  c_error_UCF_MUTEX_TIMEOUT_PARM_ERROR,
  c_error_UCF_LED_OPEN_ERROR,
  c_error_SERIAL_OPEN_ERROR,
  c_error_SERIAL_SETUP_ERROR,
  c_error_SERIAL_WRITE_ERROR,
  c_error_SERIAL_READ_ERROR,
  c_error_VAR_STORE_CREATE_NO_SLOTS_DEFINED,
  c_error_VAR_STORE_CREATE_WRONG_SLOT_DESCRIPTION,
  c_error_VAR_STORE_UNKNOWN_TYPE_SIZE_COMBINATION,
  c_error_VAR_STORE_CREATE_WRONG_VARIABLE_COUNT,
  c_error_VAR_STORE_CREATE_SLOT_NAME_TOO_LONG,
  c_error_VAR_STORE_CREATE_ERROR,
  c_error_VAR_STORE_OPEN_ERROR,
  c_error_VAR_STORE_CLIENT_NAME_TOO_LONG,
  c_error_VAR_STORE_SLOT_NAME_NOT_FOUND,
  c_error_VAR_STORE_INDEX_EXCEEDS_RANGE,
  c_error_VAR_SLOT_WRITE_UNKNOWN_TYPE,
  c_error_VAR_SLOT_WRITE_WRONG_TYPE,
  c_error_VAR_SLOT_WRITE_STRING_TOO_LONG,
  c_error_VAR_SLOT_WRITE_EXPECTED_ARRAY,
  c_error_VAR_SLOT_WRITE_WRONG_ARRAY_ELEMENT_TYPE,
  c_error_VAR_SLOT_READ_UNKNOWN_TYPE,
  c_error_VAR_SLOT_INDEX_EXCEEDS_RANGE,
  c_error_NVM_SEGMENT_OPEN_ERROR,
  c_error_NVM_SEGMENT_CREATE_NEGATIVE_SIZE,
  c_error_NVM_SEGMENT_INVALID_DATA_POS_SIZE,
  c_error_NVM_SEGMENT_WRITE_ERROR,
  c_error_NVM_SEGMENT_READ_ERROR,
  c_error_MSG_QUEUE_OPEN_ERROR,
  c_error_MSG_QUEUE_INVALID_BUFFER_SIZE,
  c_error_MSG_QUEUE_INVALID_MAX_MESSAGE_COUNT,
  c_error_MSG_QUEUE_CREATE_ERROR,
  c_error_MSG_QUEUE_WRITE_ERROR,
  c_error_MSG_QUEUE_READ_ERROR,
  c_error_CRC_UNKNOWN_REQUESTED_SIZE,
  c_error_CRC_WRONG_INITIAL_VALUE_ACCORDING_TO_SIZE,
};

// - UCF error strings -
extern const char *ucf_error_strings[];

// - UCF initialize -
bool ucf_initialize(script_parser_s &sp);

// - UCF print exception -
bool ucf_print_exception(interpreter_s &it,exception_s &exception);

// - class SYSTEM -
extern built_in_variable_s system_variables[];
extern built_in_method_s system_methods[];
extern built_in_class_s system_class;

void bic_system_consts(location_array_s &const_locations);
void bic_system_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_system_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_system_method_GetProcessId_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_system_method_GetProcessName_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_system_method_GetWorkingDirectory_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_system_method_Sleep_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_system_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_system_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class TIME -
extern built_in_variable_s time_variables[];
extern built_in_method_s time_methods[];
extern built_in_class_s time_class;

void bic_time_consts(location_array_s &const_locations);
void bic_time_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_time_clear(interpreter_thread_s &it,location_s *location_ptr);
int bic_time_compare(location_s *first_loc,location_s *second_loc);

bool bic_time_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_Time_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_Time_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_GetNanosec_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_GetMicrosec_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_GetMillisec_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_GetSeconds_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_GetMinutes_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_GetHours_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_GetDays_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_IsLeapYear_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_DaysTillYear_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_GetSystemTime_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_SetSystemTime_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_ToSystemTime_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_ToLocalTime_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_time_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class CFG_FILE -
extern built_in_variable_s cfg_file_variables[];
extern built_in_method_s cfg_file_methods[];
extern built_in_class_s cfg_file_class;

void bic_cfg_file_consts(location_array_s &const_locations);
void bic_cfg_file_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_cfg_file_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_cfg_file_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cfg_file_method_CfgFile_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cfg_file_method_CfgFile_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cfg_file_method_Open_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cfg_file_method_EnumSections_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cfg_file_method_OpenSection_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cfg_file_method_GetSection_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cfg_file_method_EnumEntries_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cfg_file_method_GetValue_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cfg_file_method_GetValue_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cfg_file_method_GetValueArray_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cfg_file_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_cfg_file_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class UCF_LOG -
extern built_in_variable_s ucf_log_variables[];
extern built_in_method_s ucf_log_methods[];
extern built_in_class_s ucf_log_class;

void bic_ucf_log_consts(location_array_s &const_locations);
void bic_ucf_log_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_ucf_log_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_ucf_log_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ucf_log_method_UcfLog_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ucf_log_method_UcfLog_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ucf_log_method_add_file_4(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ucf_log_method_add_file_5(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ucf_log_method_add_stdout_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ucf_log_method_add_stderr_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ucf_log_method_add_nvm_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ucf_log_method_write_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ucf_log_method_write_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ucf_log_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ucf_log_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class UCF_MUTEX -
extern built_in_variable_s ucf_mutex_variables[];
extern built_in_method_s ucf_mutex_methods[];
extern built_in_class_s ucf_mutex_class;

void bic_ucf_mutex_consts(location_array_s &const_locations);
void bic_ucf_mutex_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_ucf_mutex_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_ucf_mutex_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ucf_mutex_method_UcfMutex_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ucf_mutex_method_UcfMutex_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ucf_mutex_method_Reserve_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ucf_mutex_method_Reserve_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ucf_mutex_method_Release_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ucf_mutex_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ucf_mutex_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class UCF_LED -
extern built_in_variable_s ucf_led_variables[];
extern built_in_method_s ucf_led_methods[];
extern built_in_class_s ucf_led_class;

void bic_ucf_led_consts(location_array_s &const_locations);
void bic_ucf_led_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_ucf_led_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_ucf_led_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ucf_led_method_UcfLed_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ucf_led_method_LightOn_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ucf_led_method_LightOff_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ucf_led_method_Toggle_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ucf_led_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_ucf_led_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class SERIAL -
extern built_in_variable_s serial_variables[];
extern built_in_method_s serial_methods[];
extern built_in_class_s serial_class;

void bic_serial_consts(location_array_s &const_locations);
void bic_serial_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_serial_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_serial_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_serial_method_Serial_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_serial_method_SetFormat_5(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_serial_method_Write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_serial_method_WriteAll_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_serial_method_Read_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_serial_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_serial_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class VAR_STORE -
extern built_in_variable_s var_store_variables[];
extern built_in_method_s var_store_methods[];
extern built_in_class_s var_store_class;

void bic_var_store_consts(location_array_s &const_locations);
void bic_var_store_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_var_store_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_var_store_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_var_store_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_var_store_method_VarStore_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_var_store_method_VarStore_5(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_var_store_method_clear_slots_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_var_store_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_var_store_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_var_store_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_var_store_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_var_store_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_var_store_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class VAR_SLOT -
extern built_in_variable_s var_slot_variables[];
extern built_in_method_s var_slot_methods[];
extern built_in_class_s var_slot_class;

void bic_var_slot_consts(location_array_s &const_locations);
void bic_var_slot_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_var_slot_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_var_slot_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_var_slot_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_var_slot_method_index_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_var_slot_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_var_slot_method_varType_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_var_slot_method_varSize_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_var_slot_method_clear_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_var_slot_method_write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_var_slot_method_write_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_var_slot_method_read_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_var_slot_method_read_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_var_slot_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_var_slot_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_var_slot_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_var_slot_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_var_slot_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_var_slot_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class NVM_SEGMENT -
extern built_in_variable_s nvm_segment_variables[];
extern built_in_method_s nvm_segment_methods[];
extern built_in_class_s nvm_segment_class;

void bic_nvm_segment_consts(location_array_s &const_locations);
void bic_nvm_segment_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_nvm_segment_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_nvm_segment_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_nvm_segment_method_NvmSegment_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_nvm_segment_method_NvmSegment_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_nvm_segment_method_size_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_nvm_segment_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_nvm_segment_method_write_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_nvm_segment_method_read_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_nvm_segment_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_nvm_segment_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class MSG_QUEUE -
extern built_in_variable_s msg_queue_variables[];
extern built_in_method_s msg_queue_methods[];
extern built_in_class_s msg_queue_class;

void bic_msg_queue_consts(location_array_s &const_locations);
void bic_msg_queue_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_msg_queue_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_msg_queue_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_msg_queue_method_MsgQueue_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_msg_queue_method_MsgQueue_3(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_msg_queue_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_msg_queue_method_write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_msg_queue_method_read_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_msg_queue_method_read_pid_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_msg_queue_method_peek_msg_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_msg_queue_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_msg_queue_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class BCC -
extern built_in_variable_s bcc_variables[];
extern built_in_method_s bcc_methods[];
extern built_in_class_s bcc_class;

void bic_bcc_consts(location_array_s &const_locations);
void bic_bcc_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_bcc_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_bcc_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bcc_method_Bcc_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bcc_method_append_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bcc_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bcc_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_bcc_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class CRC -
extern built_in_variable_s crc_variables[];
extern built_in_method_s crc_methods[];
extern built_in_class_s crc_class;

void bic_crc_consts(location_array_s &const_locations);
void bic_crc_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_crc_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_crc_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crc_method_Crc_2(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crc_method_append_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crc_method_size_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crc_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crc_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_crc_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

// - class MD5 -
extern built_in_variable_s md5_variables[];
extern built_in_method_s md5_methods[];
extern built_in_class_s md5_class;

void bic_md5_consts(location_array_s &const_locations);
void bic_md5_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_md5_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_md5_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_md5_method_Md5_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_md5_method_append_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_md5_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_md5_method_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_md5_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_md5_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

