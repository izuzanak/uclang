
@begin
include "ucf_module.h"
@end

// - UCF indexes of built in classes -
unsigned c_bi_class_system = c_idx_not_exist;
unsigned c_bi_class_time = c_idx_not_exist;
unsigned c_bi_class_cfg_file = c_idx_not_exist;
unsigned c_bi_class_ucf_log = c_idx_not_exist;
unsigned c_bi_class_ucf_mutex = c_idx_not_exist;
unsigned c_bi_class_ucf_led = c_idx_not_exist;
unsigned c_bi_class_serial = c_idx_not_exist;
unsigned c_bi_class_var_store = c_idx_not_exist;
unsigned c_bi_class_var_slot = c_idx_not_exist;
unsigned c_bi_class_nvm_segment = c_idx_not_exist;
unsigned c_bi_class_msg_queue = c_idx_not_exist;
unsigned c_bi_class_bcc = c_idx_not_exist;
unsigned c_bi_class_crc = c_idx_not_exist;
unsigned c_bi_class_md5 = c_idx_not_exist;

// - UCF module -
built_in_module_s module =
{/*{{{*/
  14,                   // Class count
  ucf_classes,          // Classes

  0,                    // Error base index
  49,                   // Error count
  ucf_error_strings,    // Error strings

  ucf_initialize,       // Initialize function
  ucf_print_exception,  // Print exceptions function
};/*}}}*/

// - UCF classes -
built_in_class_s *ucf_classes[] =
{/*{{{*/
  &system_class,
  &time_class,
  &cfg_file_class,
  &ucf_log_class,
  &ucf_mutex_class,
  &ucf_led_class,
  &serial_class,
  &var_store_class,
  &var_slot_class,
  &nvm_segment_class,
  &msg_queue_class,
  &bcc_class,
  &crc_class,
  &md5_class,
};/*}}}*/

// - UCF error strings -
const char *ucf_error_strings[] =
{/*{{{*/
  "error_TIME_EXPECTED_MINIMAL_YEAR_VALUE",
  "error_TIME_WRONG_INIT_STRING",
  "error_CFG_FILE_OPEN_ERROR",
  "error_CFG_FILE_SECTION_NAME_ERROR",
  "error_CFG_FILE_ENTRY_NAME_ERROR",
  "error_UCF_LOG_NEGATIVE_SIZE_OF_LOG_FILE",
  "error_UCF_LOG_NEGATIVE_OR_ZERO_COUNT_OF_LOG_FILES",
  "error_UCF_LOG_NEGATIVE_VERBOSITY",
  "error_UCF_LOG_CANNOT_CREATE_LOG_FILE",
  "error_UCF_LOG_NEGATIVE_PRIORITY_LEVEL",
  "error_UCF_LOG_CANNOT_OPEN_LOG_NVM_SEGMENT",
  "error_UCF_MUTEX_CREATE_ERROR",
  "error_UCF_MUTEX_OPEN_ERROR",
  "error_UCF_MUTEX_TIMEOUT_PARM_ERROR",
  "error_UCF_LED_OPEN_ERROR",
  "error_SERIAL_OPEN_ERROR",
  "error_SERIAL_SETUP_ERROR",
  "error_SERIAL_WRITE_ERROR",
  "error_SERIAL_READ_ERROR",
  "error_VAR_STORE_CREATE_NO_SLOTS_DEFINED",
  "error_VAR_STORE_CREATE_WRONG_SLOT_DESCRIPTION",
  "error_VAR_STORE_UNKNOWN_TYPE_SIZE_COMBINATION",
  "error_VAR_STORE_CREATE_WRONG_VARIABLE_COUNT",
  "error_VAR_STORE_CREATE_SLOT_NAME_TOO_LONG",
  "error_VAR_STORE_CREATE_ERROR",
  "error_VAR_STORE_OPEN_ERROR",
  "error_VAR_STORE_CLIENT_NAME_TOO_LONG",
  "error_VAR_STORE_SLOT_NAME_NOT_FOUND",
  "error_VAR_STORE_INDEX_EXCEEDS_RANGE",
  "error_VAR_SLOT_WRITE_UNKNOWN_TYPE",
  "error_VAR_SLOT_WRITE_WRONG_TYPE",
  "error_VAR_SLOT_WRITE_STRING_TOO_LONG",
  "error_VAR_SLOT_WRITE_EXPECTED_ARRAY",
  "error_VAR_SLOT_WRITE_WRONG_ARRAY_ELEMENT_TYPE",
  "error_VAR_SLOT_READ_UNKNOWN_TYPE",
  "error_VAR_SLOT_INDEX_EXCEEDS_RANGE",
  "error_NVM_SEGMENT_OPEN_ERROR",
  "error_NVM_SEGMENT_CREATE_NEGATIVE_SIZE",
  "error_NVM_SEGMENT_INVALID_DATA_POS_SIZE",
  "error_NVM_SEGMENT_WRITE_ERROR",
  "error_NVM_SEGMENT_READ_ERROR",
  "error_MSG_QUEUE_OPEN_ERROR",
  "error_MSG_QUEUE_INVALID_BUFFER_SIZE",
  "error_MSG_QUEUE_INVALID_MAX_MESSAGE_COUNT",
  "error_MSG_QUEUE_CREATE_ERROR",
  "error_MSG_QUEUE_WRITE_ERROR",
  "error_MSG_QUEUE_READ_ERROR",
  "error_CRC_UNKNOWN_REQUESTED_SIZE",
  "error_CRC_WRONG_INITIAL_VALUE_ACCORDING_TO_SIZE",
};/*}}}*/

// - UCF initialize -
bool ucf_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize system class identifier -
  c_bi_class_system = class_base_idx++;

  // - initialize time class identifier -
  c_bi_class_time = class_base_idx++;

  // - initialize cfg_file class identifier -
  c_bi_class_cfg_file = class_base_idx++;

  // - initialize ucf_log class identifier -
  c_bi_class_ucf_log = class_base_idx++;

  // - initialize ucf_mutex class identifier -
  c_bi_class_ucf_mutex = class_base_idx++;

  // - initialize ucf_led class identifier -
  c_bi_class_ucf_led = class_base_idx++;

  // - initialize serial class identifier -
  c_bi_class_serial = class_base_idx++;

  // - initialize var_store class identifier -
  c_bi_class_var_store = class_base_idx++;

  // - initialize var_slot class identifier -
  c_bi_class_var_slot = class_base_idx++;

  // - initialize nvm_segment class identifier -
  c_bi_class_nvm_segment = class_base_idx++;

  // - initialize msg_queue class identifier -
  c_bi_class_msg_queue = class_base_idx++;

  // - initialize bcc class identifier -
  c_bi_class_bcc = class_base_idx++;

  // - initialize crc class identifier -
  c_bi_class_crc = class_base_idx++;

  // - initialize md5 class identifier -
  c_bi_class_md5 = class_base_idx++;

  return true;
}/*}}}*/

// - UCF print exception -
bool ucf_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_TIME_EXPECTED_MINIMAL_YEAR_VALUE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nExpected minimal year value %" HOST_LL_FORMAT "d, received %" HOST_LL_FORMAT "d\n",exception.params[0],exception.params[1]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_TIME_WRONG_INIT_STRING:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong date/time string \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CFG_FILE_OPEN_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot open config file \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CFG_FILE_SECTION_NAME_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUnknown configuration section \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CFG_FILE_ENTRY_NAME_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUnknown configuration entry \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_UCF_LOG_NEGATIVE_SIZE_OF_LOG_FILE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nRequested negative size of log file\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_UCF_LOG_NEGATIVE_OR_ZERO_COUNT_OF_LOG_FILES:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nRequested negative or zero count of log files\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_UCF_LOG_NEGATIVE_VERBOSITY:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nRequested negative log verbosity\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_UCF_LOG_CANNOT_CREATE_LOG_FILE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot create log file \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_UCF_LOG_NEGATIVE_PRIORITY_LEVEL:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nNegative log message priority level\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_UCF_LOG_CANNOT_OPEN_LOG_NVM_SEGMENT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot open NVM log segment \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_UCF_MUTEX_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot create named mutex \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_UCF_MUTEX_OPEN_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot open named mutex \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_UCF_MUTEX_TIMEOUT_PARM_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nTimeout parameter of Reserve must be greater or equal to -1\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_UCF_LED_OPEN_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot open light emitting diode \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SERIAL_OPEN_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot open serial port \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SERIAL_SETUP_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot setup serial port\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SERIAL_WRITE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while writing to serial port\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SERIAL_READ_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while reading from serial port\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_VAR_STORE_CREATE_NO_SLOTS_DEFINED:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nThere are no slots defined for new varstore\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_VAR_STORE_CREATE_WRONG_SLOT_DESCRIPTION:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong description of slot at position %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_VAR_STORE_UNKNOWN_TYPE_SIZE_COMBINATION:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUnknown varstore slot type: %" HOST_LL_FORMAT "d and size: %" HOST_LL_FORMAT "d combination\n",exception.params[0],exception.params[1]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_VAR_STORE_CREATE_WRONG_VARIABLE_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong requested count of variables: %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_VAR_STORE_CREATE_SLOT_NAME_TOO_LONG:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nVarstore slot name \"%s\" is too long\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_VAR_STORE_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating varstore \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_VAR_STORE_OPEN_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while openning varstore \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_VAR_STORE_CLIENT_NAME_TOO_LONG:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nVarstore client name \"%s\" is too long\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_VAR_STORE_SLOT_NAME_NOT_FOUND:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nVarstore slot with name \"%s\" was not found\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_VAR_STORE_INDEX_EXCEEDS_RANGE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nIndex %" HOST_LL_FORMAT "d exceeds varstore range\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_VAR_SLOT_WRITE_UNKNOWN_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nVarstore slot write error, unknown variable type\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_VAR_SLOT_WRITE_WRONG_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nVarstore slot write error, expected %s\n",it.class_symbol_names[it.class_records[exception.params[0]].name_idx].data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_VAR_SLOT_WRITE_STRING_TOO_LONG:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nVarstore slot write error, string exceeds maximal length\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_VAR_SLOT_WRITE_EXPECTED_ARRAY:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nVarstore slot write error, expected array of length %" HOST_LL_FORMAT "d with elements of same type\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_VAR_SLOT_WRITE_WRONG_ARRAY_ELEMENT_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nVarstore slot write error, elements of array must be of type %s\n",it.class_symbol_names[it.class_records[exception.params[0]].name_idx].data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_VAR_SLOT_READ_UNKNOWN_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nVarstore slot read error, unknown variable type\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_VAR_SLOT_INDEX_EXCEEDS_RANGE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nIndex %" HOST_LL_FORMAT "d exceeds variable slot range\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_NVM_SEGMENT_OPEN_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while openning NVM segment \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_NVM_SEGMENT_CREATE_NEGATIVE_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSize of NVM segment must be greater than zero\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_NVM_SEGMENT_INVALID_DATA_POS_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid NVM segment read/write data position %" HOST_LL_FORMAT "d and/or size %" HOST_LL_FORMAT "d\n",exception.params[0],exception.params[1]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_NVM_SEGMENT_WRITE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while writing to NVM segment\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_NVM_SEGMENT_READ_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while reading from NVM segment\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MSG_QUEUE_OPEN_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while opening message queue \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MSG_QUEUE_INVALID_BUFFER_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid message queue buffer size %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MSG_QUEUE_INVALID_MAX_MESSAGE_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid message queue max message count %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MSG_QUEUE_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating message queue \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MSG_QUEUE_WRITE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while writing message to message queue\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_MSG_QUEUE_READ_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while reading message from message queue\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CRC_UNKNOWN_REQUESTED_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nUnknown requested size %" HOST_LL_FORMAT "d of CRC code\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CRC_WRONG_INITIAL_VALUE_ACCORDING_TO_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid initial value %" HOST_LL_FORMAT "d according to requested size %" HOST_LL_FORMAT "d\n",exception.params[0],exception.params[1]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class SYSTEM -
built_in_class_s system_class =
{/*{{{*/
  "System",
  c_modifier_public | c_modifier_final,
  6, system_methods,
  0, system_variables,
  bic_system_consts,
  bic_system_init,
  bic_system_clear,
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

built_in_method_s system_methods[] =
{/*{{{*/
  {
    "GetProcessId#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_system_method_GetProcessId_0
  },
  {
    "GetProcessName#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_system_method_GetProcessName_0
  },
  {
    "GetWorkingDirectory#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_system_method_GetWorkingDirectory_0
  },
  {
    "Sleep#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_system_method_Sleep_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_system_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_system_method_print_0
  },
};/*}}}*/

built_in_variable_s system_variables[] =
{/*{{{*/
};/*}}}*/

void bic_system_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_system_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_system_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_system_method_GetProcessId_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  long long int process_id = GetProcessId();

  BIC_SIMPLE_SET_RES(c_bi_class_integer,process_id);

  return true;
}/*}}}*/

bool bic_system_method_GetProcessName_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  const char *proc_name = GetProcessName();

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(proc_name),proc_name);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_system_method_GetWorkingDirectory_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  const char *directory = GetWorkingDirectory();

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(directory),directory);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_system_method_Sleep_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int delay;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,delay))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_system,"Sleep#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  Sleep(delay);

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

bool bic_system_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("System"),"System")
  );

  return true;
}/*}}}*/

bool bic_system_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("System");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class TIME -
built_in_class_s time_class =
{/*{{{*/
  "Time",
  c_modifier_public | c_modifier_final,
  21, time_methods,
  0, time_variables,
  bic_time_consts,
  bic_time_init,
  bic_time_clear,
  bic_time_compare,
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

built_in_method_s time_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_time_operator_binary_equal
  },
  {
    "operator_binary_double_equal#1",
    c_modifier_public | c_modifier_final,
    bic_time_operator_binary_double_equal
  },
  {
    "operator_binary_exclamation_equal#1",
    c_modifier_public | c_modifier_final,
    bic_time_operator_binary_exclamation_equal
  },
  {
    "Time#0",
    c_modifier_public | c_modifier_final,
    bic_time_method_Time_0
  },
  {
    "Time#1",
    c_modifier_public | c_modifier_final,
    bic_time_method_Time_1
  },
  {
    "GetNanosec#0",
    c_modifier_public | c_modifier_final,
    bic_time_method_GetNanosec_0
  },
  {
    "GetMicrosec#0",
    c_modifier_public | c_modifier_final,
    bic_time_method_GetMicrosec_0
  },
  {
    "GetMillisec#0",
    c_modifier_public | c_modifier_final,
    bic_time_method_GetMillisec_0
  },
  {
    "GetSeconds#0",
    c_modifier_public | c_modifier_final,
    bic_time_method_GetSeconds_0
  },
  {
    "GetMinutes#0",
    c_modifier_public | c_modifier_final,
    bic_time_method_GetMinutes_0
  },
  {
    "GetHours#0",
    c_modifier_public | c_modifier_final,
    bic_time_method_GetHours_0
  },
  {
    "GetDays#0",
    c_modifier_public | c_modifier_final,
    bic_time_method_GetDays_0
  },
  {
    "IsLeapYear#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_time_method_IsLeapYear_1
  },
  {
    "DaysTillYear#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_time_method_DaysTillYear_1
  },
  {
    "GetSystemTime#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_time_method_GetSystemTime_0
  },
  {
    "SetSystemTime#0",
    c_modifier_public | c_modifier_final,
    bic_time_method_SetSystemTime_0
  },
  {
    "ToSystemTime#0",
    c_modifier_public | c_modifier_final,
    bic_time_method_ToSystemTime_0
  },
  {
    "ToLocalTime#0",
    c_modifier_public | c_modifier_final,
    bic_time_method_ToLocalTime_0
  },
  {
    "compare#1",
    c_modifier_public | c_modifier_final,
    bic_time_method_compare_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_time_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_time_method_print_0
  },
};/*}}}*/

built_in_variable_s time_variables[] =
{/*{{{*/
};/*}}}*/

void bic_time_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_time_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (Time *)nullptr;
}/*}}}*/

void bic_time_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/

  // - retrieve time object pointer -
  Time *time_ptr = (Time *)location_ptr->v_data_ptr;

  // - if time object pointer is not null -
  if (time_ptr != nullptr)
  {
    delete time_ptr;
  }
}/*}}}*/

int bic_time_compare(location_s *first_loc,location_s *second_loc)
{/*{{{*/
  Time *first = (Time *)first_loc->v_data_ptr;
  Time *second = (Time *)second_loc->v_data_ptr;

  return first->Compare(*second);
}/*}}}*/

bool bic_time_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_time_operator_binary_double_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  if (src_0_location->v_type == c_bi_class_time)
  {
    result = (((Time *)dst_location->v_data_ptr)->Compare(*((Time *)src_0_location->v_data_ptr))) == 0;
  }
  else
  {
    result = 0;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_time_operator_binary_exclamation_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  if (src_0_location->v_type == c_bi_class_time)
  {
    result = (((Time *)dst_location->v_data_ptr)->Compare(*((Time *)src_0_location->v_data_ptr))) != 0;
  }
  else
  {
    result = 1;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_time_method_Time_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - construct empty time object -
  dst_location->v_data_ptr = (Time *)new Time();

  return true;
}/*}}}*/

bool bic_time_method_Time_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  switch (src_0_location->v_type)
  {
  case c_bi_class_integer:

    // - construct time object -
    dst_location->v_data_ptr = (Time *)new Time((long long int)src_0_location->v_data_ptr);

    break;

  case c_bi_class_string:
  {
    string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

    // - ERROR -
    if (string_ptr->size != 15)
    {
      exception_s::throw_exception(it,module.error_base + c_error_TIME_WRONG_INIT_STRING,operands[c_source_pos_idx],src_0_location);
      return false;
    }

    DateTime dt;

    char *str = string_ptr->data;

#define BIC_TIME_RETRIEVE_COMP(TARGET,START,END) \
{/*{{{*/\
  char tmp_char = str[END];\
  str[END] = '\0';\
  \
  char *end_ptr;\
  TARGET = strtol(str + START,&end_ptr,10);\
  \
  /* - ERROR - */\
  if (end_ptr != str + END)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_TIME_WRONG_INIT_STRING,operands[c_source_pos_idx],src_0_location);\
    return false;\
  }\
  \
  str[END] = tmp_char;\
}/*}}}*/

    dt.nsec = 0;
    dt.usec = 0;
    dt.msec = 0;

    BIC_TIME_RETRIEVE_COMP(dt.sec  ,12,14);
    BIC_TIME_RETRIEVE_COMP(dt.min  ,10,12);
    BIC_TIME_RETRIEVE_COMP(dt.hour ,8 ,10);
    BIC_TIME_RETRIEVE_COMP(dt.day  ,6 ,8);
    BIC_TIME_RETRIEVE_COMP(dt.month,4 ,6);
    BIC_TIME_RETRIEVE_COMP(dt.year ,0 ,4);

    // - ERROR -
    if (dt.year < 1970 || dt.month < 1 || dt.month > 12 || dt.day < 1 ||
        dt.day > c_days_in_month[Time::IsLeapYear(dt.year)][dt.month] ||
        dt.hour >= 24 || dt.min >= 60 || dt.sec >= 60)
    {
      exception_s::throw_exception(it,module.error_base + c_error_TIME_WRONG_INIT_STRING,operands[c_source_pos_idx],src_0_location);
      return false;
    }

    // - construct time object -
    dst_location->v_data_ptr = (Time *)new Time(dt);
  }
  break;

  // - ERROR -
  default:
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Time#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  return true;
}/*}}}*/

#define BIC_TIME_GET_RESULT_INTEGER(METHOD) \
  {/*{{{*/\
    pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
    \
    long long int result = ((Time *)dst_location->v_data_ptr)->METHOD();\
    \
    BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
  }/*}}}*/

bool bic_time_method_GetNanosec_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TIME_GET_RESULT_INTEGER(GetNanosec)

  return true;
}/*}}}*/

bool bic_time_method_GetMicrosec_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TIME_GET_RESULT_INTEGER(GetMicrosec)

  return true;
}/*}}}*/

bool bic_time_method_GetMillisec_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TIME_GET_RESULT_INTEGER(GetMillisec)

  return true;
}/*}}}*/

bool bic_time_method_GetSeconds_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TIME_GET_RESULT_INTEGER(GetSeconds)

  return true;
}/*}}}*/

bool bic_time_method_GetMinutes_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TIME_GET_RESULT_INTEGER(GetMinutes)

  return true;
}/*}}}*/

bool bic_time_method_GetHours_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TIME_GET_RESULT_INTEGER(GetHours)

  return true;
}/*}}}*/

bool bic_time_method_GetDays_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TIME_GET_RESULT_INTEGER(GetDays)

  return true;
}/*}}}*/

bool bic_time_method_IsLeapYear_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_integer)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_time,"IsLeapYear#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  long long int year = (long long int)src_0_location->v_data_ptr;
  long long int result = Time::IsLeapYear(year);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_time_method_DaysTillYear_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_integer)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_time,"DaysTillYear#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  long long int year = (long long int)src_0_location->v_data_ptr;

  // - ERROR -
  if (year < 1601)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_TIME_EXPECTED_MINIMAL_YEAR_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(1601);
    new_exception->params.push(year);

    return false;
  }

  long long int result = Time::DaysTillYear(year);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_time_method_GetSystemTime_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  // - create time pointer -
  Time *time_ptr = new Time();
  *time_ptr = GetSystemTime();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_time,time_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_time_method_SetSystemTime_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - convert time to date time structure -
  DateTime dateTime;
  ((Time *)dst_location->v_data_ptr)->ToSystemTime(dateTime);

  // - set system time -
  SetSystemTime(dateTime);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

#define BIC_TIME_TO_RESULT_SYSTIME(METHOD) \
  {/*{{{*/\
    pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
    \
    /* - convert time to date time structure - */\
    DateTime dateTime;\
    ((Time *)dst_location->v_data_ptr)->METHOD(dateTime);\
    \
    /* - create new array pointer - */\
    pointer_array_s *array_ptr = it.get_new_array_ptr();\
    array_ptr->copy_resize(SYSTIME_VALUE_CNT);\
    array_ptr->used = array_ptr->size;\
    \
    pointer *l_ptr = array_ptr->data;\
    pointer *l_ptr_end = array_ptr->data + array_ptr->used;\
    do {\
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,0)\
      \
      *l_ptr = (pointer)new_location;\
      \
    } while(++l_ptr < l_ptr_end);\
    \
    /* - set system time values - */\
    ((location_s *)array_ptr->data[0])->v_data_ptr = (long long int)dateTime.year;\
    ((location_s *)array_ptr->data[1])->v_data_ptr = (long long int)dateTime.month;\
    ((location_s *)array_ptr->data[2])->v_data_ptr = (long long int)dateTime.day;\
    ((location_s *)array_ptr->data[3])->v_data_ptr = (long long int)dateTime.dayOfWeek;\
    ((location_s *)array_ptr->data[4])->v_data_ptr = (long long int)dateTime.hour;\
    ((location_s *)array_ptr->data[5])->v_data_ptr = (long long int)dateTime.min;\
    ((location_s *)array_ptr->data[6])->v_data_ptr = (long long int)dateTime.sec;\
    ((location_s *)array_ptr->data[7])->v_data_ptr = (long long int)dateTime.msec;\
    ((location_s *)array_ptr->data[8])->v_data_ptr = (long long int)dateTime.usec;\
    ((location_s *)array_ptr->data[9])->v_data_ptr = (long long int)dateTime.nsec;\
    \
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);\
    BIC_SET_RESULT(new_location);\
  }/*}}}*/

bool bic_time_method_ToSystemTime_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TIME_TO_RESULT_SYSTIME(ToSystemTime);

  return true;
}/*}}}*/

bool bic_time_method_ToLocalTime_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TIME_TO_RESULT_SYSTIME(ToLocalTime);

  return true;
}/*}}}*/

bool bic_time_method_compare_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int result;

  if (src_0_location->v_type == c_bi_class_time)
  {
    Time *first = (Time *)dst_location->v_data_ptr;
    Time *second = (Time *)src_0_location->v_data_ptr;

    result = first->Compare(*second);
  }
  else
  {
    result = c_bi_class_time < src_0_location->v_type ? -1 : 1;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_time_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING(

    // - convert time to date time structure -
    DateTime dateTime;
    ((Time *)dst_location->v_data_ptr)->ToSystemTime(dateTime);

    string_ptr->setf("%4.4hu/%2.2hhu/%2.2hhu %2.2hhu:%2.2hhu:%2.2hhu"
      ,dateTime.year,dateTime.month,dateTime.day,dateTime.hour,dateTime.min,dateTime.sec);
  );

  return true;
}/*}}}*/

bool bic_time_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - convert time to date time structure -
  DateTime dateTime;
  ((Time *)dst_location->v_data_ptr)->ToSystemTime(dateTime);

  printf("%4.4hu/%2.2hhu/%2.2hhu %2.2hhu:%2.2hhu:%2.2hhu"
      ,dateTime.year,dateTime.month,dateTime.day,dateTime.hour,dateTime.min,dateTime.sec);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

// - class CFG_FILE -
built_in_class_s cfg_file_class =
{/*{{{*/
  "CfgFile",
  c_modifier_public | c_modifier_final,
  13, cfg_file_methods,
  0, cfg_file_variables,
  bic_cfg_file_consts,
  bic_cfg_file_init,
  bic_cfg_file_clear,
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

built_in_method_s cfg_file_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_cfg_file_operator_binary_equal
  },
  {
    "CfgFile#0",
    c_modifier_public | c_modifier_final,
    bic_cfg_file_method_CfgFile_0
  },
  {
    "CfgFile#1",
    c_modifier_public | c_modifier_final,
    bic_cfg_file_method_CfgFile_1
  },
  {
    "Open#1",
    c_modifier_public | c_modifier_final,
    bic_cfg_file_method_Open_1
  },
  {
    "EnumSections#0",
    c_modifier_public | c_modifier_final,
    bic_cfg_file_method_EnumSections_0
  },
  {
    "OpenSection#1",
    c_modifier_public | c_modifier_final,
    bic_cfg_file_method_OpenSection_1
  },
  {
    "GetSection#0",
    c_modifier_public | c_modifier_final,
    bic_cfg_file_method_GetSection_0
  },
  {
    "EnumEntries#0",
    c_modifier_public | c_modifier_final,
    bic_cfg_file_method_EnumEntries_0
  },
  {
    "GetValue#1",
    c_modifier_public | c_modifier_final,
    bic_cfg_file_method_GetValue_1
  },
  {
    "GetValue#2",
    c_modifier_public | c_modifier_final,
    bic_cfg_file_method_GetValue_2
  },
  {
    "GetValueArray#1",
    c_modifier_public | c_modifier_final,
    bic_cfg_file_method_GetValueArray_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cfg_file_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_cfg_file_method_print_0
  },
};/*}}}*/

built_in_variable_s cfg_file_variables[] =
{/*{{{*/
};/*}}}*/

void bic_cfg_file_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_cfg_file_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (CfgFile *)nullptr;
}/*}}}*/

void bic_cfg_file_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/

  // - retrieve config file object pointer -
  CfgFile *cfg_file_ptr = (CfgFile *)location_ptr->v_data_ptr;

  // - if config file object pointer is not null -
  if (cfg_file_ptr != nullptr)
  {
    delete cfg_file_ptr;
  }
}/*}}}*/

bool bic_cfg_file_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_cfg_file_method_CfgFile_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - construct empty config file object -
  dst_location->v_data_ptr = (CfgFile *)new CfgFile();

  return true;
}/*}}}*/

bool bic_cfg_file_method_CfgFile_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("CfgFile#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - construct temporary file name string -
  String filename(((string_s *)src_0_location->v_data_ptr)->data);

  try
  {
    // - construct config file object -
    dst_location->v_data_ptr = (CfgFile *)new CfgFile(filename);
  }
  catch(Exception e)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CFG_FILE_OPEN_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  return true;
}/*}}}*/

bool bic_cfg_file_method_Open_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Open#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve config file pointer -
  CfgFile *cfg_file_ptr = (CfgFile *)dst_location->v_data_ptr;

  // - construct temporary file name string -
  String filename(((string_s *)src_0_location->v_data_ptr)->data);

  try
  {
    // - open configuration file -
    cfg_file_ptr->Open(filename);
  }
  catch(Exception e)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CFG_FILE_OPEN_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_cfg_file_method_EnumSections_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve config file pointer -
  CfgFile *cfg_file_ptr = (CfgFile *)dst_location->v_data_ptr;

  // - create sections name array -
  string_array_s sect_names;
  sect_names.init();

  int sect_idx = 0;
  const char *sect_name = nullptr;
  while ((sect_name = cfg_file_ptr->EnumSections(sect_idx)) != nullptr)
  {
    // - insert section name to section names array -
    sect_names.push_blank();
    sect_names.last().set(strlen(sect_name),sect_name);

    // - increase section index -
    sect_idx++;
  }

  // - create result array -
  pointer_array_s *res_array_ptr = it.get_new_array_ptr();

  if (sect_names.used != 0)
  {
    res_array_ptr->copy_resize(sect_names.used);

    // - create string variables for section names -
    string_s *s_ptr = sect_names.data;
    string_s *s_ptr_end = s_ptr + sect_names.used;
    do
    {
      string_s *new_string_ptr = it.get_new_string_ptr();
      new_string_ptr->swap(*s_ptr);

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,new_string_ptr);
      res_array_ptr->push((pointer)new_location);

    }
    while(++s_ptr < s_ptr_end);
  }

  sect_names.clear();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,res_array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_cfg_file_method_OpenSection_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("OpenSection#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve config file pointer -
  CfgFile *cfg_file_ptr = (CfgFile *)dst_location->v_data_ptr;

  // - construct temporary section name string -
  String sect_name(((string_s *)src_0_location->v_data_ptr)->data);

  try
  {
    // - open configuration section -
    cfg_file_ptr->OpenSection(sect_name);
  }

  // - ERROR -
  catch (Exception e)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CFG_FILE_SECTION_NAME_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_cfg_file_method_GetSection_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve config file pointer -
  CfgFile *cfg_file_ptr = (CfgFile *)dst_location->v_data_ptr;

  String sect_name = cfg_file_ptr->GetSection();

  if (sect_name != "")
  {
    // - create section name string location -
    string_s *new_string_ptr = it.get_new_string_ptr();
    new_string_ptr->set(sect_name.Length(),sect_name.Mem());

    BIC_SET_RESULT_STRING(new_string_ptr);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_cfg_file_method_EnumEntries_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve config file pointer -
  CfgFile *cfg_file_ptr = (CfgFile *)dst_location->v_data_ptr;

  // - create entries name array -
  string_array_s entry_names;
  entry_names.init();

  int entry_idx = 0;
  const char *entry_name = nullptr;
  while ((entry_name = cfg_file_ptr->EnumEntries(entry_idx)) != nullptr)
  {
    // - insert entry name to entry names array -
    entry_names.push_blank();
    entry_names.last().set(strlen(entry_name),entry_name);

    // - increase entry index -
    entry_idx++;
  }

  // - create result array -
  pointer_array_s *res_array_ptr = it.get_new_array_ptr();

  if (entry_names.used != 0)
  {
    res_array_ptr->copy_resize(entry_names.used);

    // - create string variables for entry names -
    string_s *e_ptr = entry_names.data;
    string_s *e_ptr_end = e_ptr + entry_names.used;
    do
    {
      string_s *new_string_ptr = it.get_new_string_ptr();
      new_string_ptr->swap(*e_ptr);

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,new_string_ptr);
      res_array_ptr->push((pointer)new_location);

    }
    while(++e_ptr < e_ptr_end);
  }

  entry_names.clear();

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,res_array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_cfg_file_method_GetValue_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("GetValue#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve config file pointer -
  CfgFile *cfg_file_ptr = (CfgFile *)dst_location->v_data_ptr;

  // - construct entry string -
  String entry(((string_s *)src_0_location->v_data_ptr)->data);

  string_s *new_string_ptr;

  try
  {
    // - retrieve entry value -
    String value = cfg_file_ptr->GetString(entry);

    new_string_ptr = it.get_new_string_ptr();
    new_string_ptr->set(value.Length(),value.Mem());
  }
  catch(Exception e)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CFG_FILE_ENTRY_NAME_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  BIC_SET_RESULT_STRING(new_string_ptr);

  return true;
}/*}}}*/

bool bic_cfg_file_method_GetValue_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string || src_1_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("GetValue#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  // - retrieve config file pointer -
  CfgFile *cfg_file_ptr = (CfgFile *)dst_location->v_data_ptr;

  // - construct entry string -
  String entry(((string_s *)src_0_location->v_data_ptr)->data);

  string_s *new_string_ptr;

  try
  {
    // - retrieve entry value -
    String value = cfg_file_ptr->GetString(entry);

    new_string_ptr = it.get_new_string_ptr();
    new_string_ptr->set(value.Length(),value.Mem());
  }
  catch(Exception e)
  {
    // - return default value -
    src_1_location->v_reference_cnt.atomic_inc();

    BIC_SET_RESULT(src_1_location);

    return true;
  }

  BIC_SET_RESULT_STRING(new_string_ptr);

  return true;
}/*}}}*/

bool bic_cfg_file_method_GetValueArray_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("GetValueArray#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve config file pointer -
  CfgFile *cfg_file_ptr = (CfgFile *)dst_location->v_data_ptr;

  // - construct entry string -
  String entry(((string_s *)src_0_location->v_data_ptr)->data);

  // - array of entry values -
  DynArray<String> values;

  try
  {
    // - retrieve entry values -
    cfg_file_ptr->GetMultiple(entry,values);
  }
  catch(Exception e)
  {
    exception_s::throw_exception(it,module.error_base + c_error_CFG_FILE_ENTRY_NAME_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  // - construct result array -
  pointer_array_s *array_ptr = it.get_new_array_ptr();

  // - copy value strings to result array -
  if (values.Num() > 0)
  {
    unsigned value_cnt = values.Num();

    array_ptr->copy_resize(value_cnt);
    array_ptr->used = value_cnt;

    unsigned v_idx = 0;
    do
    {
      String &str = values[v_idx];

      string_s *new_string_ptr = it.get_new_string_ptr();
      new_string_ptr->set(str.Length(),str.Mem());

      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,new_string_ptr);
      array_ptr->data[v_idx] = (pointer)new_location;

    }
    while(++v_idx < value_cnt);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_cfg_file_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("CfgFile"),"CfgFile")
  );

  return true;
}/*}}}*/

bool bic_cfg_file_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("CfgFile");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class UCF_LOG -
built_in_class_s ucf_log_class =
{/*{{{*/
  "UcfLog",
  c_modifier_public | c_modifier_final,
  12, ucf_log_methods,
  0, ucf_log_variables,
  bic_ucf_log_consts,
  bic_ucf_log_init,
  bic_ucf_log_clear,
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

built_in_method_s ucf_log_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_ucf_log_operator_binary_equal
  },
  {
    "UcfLog#0",
    c_modifier_public | c_modifier_final,
    bic_ucf_log_method_UcfLog_0
  },
  {
    "UcfLog#1",
    c_modifier_public | c_modifier_final,
    bic_ucf_log_method_UcfLog_1
  },
  {
    "add_file#4",
    c_modifier_public | c_modifier_final,
    bic_ucf_log_method_add_file_4
  },
  {
    "add_file#5",
    c_modifier_public | c_modifier_final,
    bic_ucf_log_method_add_file_5
  },
  {
    "add_stdout#1",
    c_modifier_public | c_modifier_final,
    bic_ucf_log_method_add_stdout_1
  },
  {
    "add_stderr#1",
    c_modifier_public | c_modifier_final,
    bic_ucf_log_method_add_stderr_1
  },
  {
    "add_nvm#2",
    c_modifier_public | c_modifier_final,
    bic_ucf_log_method_add_nvm_2
  },
  {
    "write#2",
    c_modifier_public | c_modifier_final,
    bic_ucf_log_method_write_2
  },
  {
    "write#3",
    c_modifier_public | c_modifier_final,
    bic_ucf_log_method_write_3
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ucf_log_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ucf_log_method_print_0
  },
};/*}}}*/

built_in_variable_s ucf_log_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_UCF_LOG_METHOD_ADD_FILE(SYNC) \
{/*{{{*/\
  LogSet *log_set_ptr = ((ucf_log_s *)dst_location->v_data_ptr)->log_set_ptr;\
  string_s *file_name_ptr = (string_s *)src_0_location->v_data_ptr;\
\
  /* - ERROR - */\
  if (size < 0)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_UCF_LOG_NEGATIVE_SIZE_OF_LOG_FILE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  /* - ERROR - */\
  if (count <= 0)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_UCF_LOG_NEGATIVE_OR_ZERO_COUNT_OF_LOG_FILES,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  /* - ERROR - */\
  if (verbosity < 0)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_UCF_LOG_NEGATIVE_VERBOSITY,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  LogFile *file_log_ptr = nullptr;\
\
  try\
  {\
    file_log_ptr = new LogFile(file_name_ptr->data,size,count,SYNC);\
  }\
\
  /* - ERROR - */\
  catch (Exception e)\
  {\
    exception_s::throw_exception(it,module.error_base + c_error_UCF_LOG_CANNOT_CREATE_LOG_FILE,operands[c_source_pos_idx],src_0_location);\
    return false;\
  }\
\
  file_log_ptr->SetVerbosity(verbosity);\
  log_set_ptr->AddLog(file_log_ptr);\
\
  BIC_SET_RESULT_DESTINATION();\
\
  return true;\
}/*}}}*/

#define BIC_UCF_LOG_ADD_STDOUT_STDERR(NAME,STDERR) \
  {/*{{{*/\
    pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
    location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
    \
    long long int verbosity;\
    \
    /* - ERROR - */\
    if (!it.retrieve_integer(src_0_location,verbosity))\
    {\
      exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
      new_exception->params.push(1);\
      new_exception->params.push(src_0_location->v_type);\
      \
      return false;\
    }\
    \
    LogSet *log_set_ptr = ((ucf_log_s *)dst_location->v_data_ptr)->log_set_ptr;\
    \
    LogStdOut *stdout_log_ptr = new LogStdOut(STDERR,2);\
    \
    stdout_log_ptr->SetVerbosity(verbosity);\
    log_set_ptr->AddLog(stdout_log_ptr);\
    \
    BIC_SET_RESULT_DESTINATION();\
    \
    return true;\
  }/*}}}*/

void bic_ucf_log_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_ucf_log_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (ucf_log_s *)nullptr;
}/*}}}*/

void bic_ucf_log_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  ucf_log_s *log_ptr = (ucf_log_s *)location_ptr->v_data_ptr;

  if (log_ptr != nullptr)
  {
    log_ptr->log_set_ptr->RemoveAll();
    delete log_ptr->log_set_ptr;

    log_ptr->source.clear();

    cfree(log_ptr);
  }
}/*}}}*/

bool bic_ucf_log_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_ucf_log_method_UcfLog_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - create new log object -
  ucf_log_s *log_ptr = (ucf_log_s *)cmalloc(sizeof(ucf_log_s));
  log_ptr->source.init();

  // - retrieve process name -
  const char *proc_name = GetProcessName();

  // - setup log object -
  log_ptr->log_set_ptr = new LogSet();
  log_ptr->source.set(strlen(proc_name),proc_name);

  dst_location->v_data_ptr = (ucf_log_s *)log_ptr;

  return true;
}/*}}}*/

bool bic_ucf_log_method_UcfLog_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("UcfLog#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve source name -
  string_s *source = (string_s *)src_0_location->v_data_ptr;

  // - create new log object -
  ucf_log_s *log_ptr = (ucf_log_s *)cmalloc(sizeof(ucf_log_s));
  log_ptr->source.init();

  // - setup log object -
  log_ptr->log_set_ptr = new LogSet();
  log_ptr->source = *source;

  dst_location->v_data_ptr = (ucf_log_s *)log_ptr;

  return true;
}/*}}}*/

bool bic_ucf_log_method_add_file_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);
  location_s *src_3_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_3_op_idx]);

  long long int size;
  long long int count;
  long long int verbosity;

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string ||
      !it.retrieve_integer(src_1_location,size) ||
      !it.retrieve_integer(src_2_location,count) ||
      !it.retrieve_integer(src_3_location,verbosity)
     )
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("add_file#4");
    new_exception->params.push(4);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);
    new_exception->params.push(src_3_location->v_type);

    return false;
  }

  BIC_UCF_LOG_METHOD_ADD_FILE(false);
}/*}}}*/

bool bic_ucf_log_method_add_file_5(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);
  location_s *src_3_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_3_op_idx]);
  location_s *src_4_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_4_op_idx]);

  long long int size;
  long long int count;
  long long int verbosity;
  long long int sync;

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string ||
      !it.retrieve_integer(src_1_location,size) ||
      !it.retrieve_integer(src_2_location,count) ||
      !it.retrieve_integer(src_3_location,verbosity) ||
      !it.retrieve_integer(src_4_location,sync)
     )
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("add_file#5");
    new_exception->params.push(5);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);
    new_exception->params.push(src_3_location->v_type);
    new_exception->params.push(src_4_location->v_type);

    return false;
  }

  BIC_UCF_LOG_METHOD_ADD_FILE(sync);
}/*}}}*/

bool bic_ucf_log_method_add_stdout_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_UCF_LOG_ADD_STDOUT_STDERR("add_stdout#1",false);
}/*}}}*/

bool bic_ucf_log_method_add_stderr_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_UCF_LOG_ADD_STDOUT_STDERR("add_stderr#1",true);
}/*}}}*/

bool bic_ucf_log_method_add_nvm_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int verbosity;

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string ||
      !it.retrieve_integer(src_1_location,verbosity))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("add_nvm#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  LogSet *log_set_ptr = ((ucf_log_s *)dst_location->v_data_ptr)->log_set_ptr;
  string_s *name_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (verbosity < 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_UCF_LOG_NEGATIVE_VERBOSITY,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  LogNvm *nvm_log_ptr = nullptr;

  try
  {
    nvm_log_ptr = new LogNvm(name_ptr->data);
  }

  // - ERROR -
  catch (Exception e)
  {
    exception_s::throw_exception(it,module.error_base + c_error_UCF_LOG_CANNOT_OPEN_LOG_NVM_SEGMENT,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  nvm_log_ptr->SetVerbosity(verbosity);
  log_set_ptr->AddLog(nvm_log_ptr);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_ucf_log_method_write_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int level;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,level) ||
      src_1_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("write#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  ucf_log_s *log_ptr = (ucf_log_s *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_1_location->v_data_ptr;

  // - ERROR -
  if (level < 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_UCF_LOG_NEGATIVE_PRIORITY_LEVEL,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - write string to log -
  log_ptr->log_set_ptr->Write(level,log_ptr->source.data,GetSystemTime(),"%s",string_ptr->data);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_ucf_log_method_write_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);

  long long int level;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,level) ||
      src_2_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("write#3");
    new_exception->params.push(3);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);

    return false;
  }

  ucf_log_s *log_ptr = (ucf_log_s *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_2_location->v_data_ptr;

  // - ERROR -
  if (level < 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_UCF_LOG_NEGATIVE_PRIORITY_LEVEL,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  char *source_ptr = nullptr;
  Time log_time;

  // - retrieve source and log time -
  if (src_1_location->v_type == c_bi_class_string)
  {
    source_ptr = ((string_s *)src_1_location->v_data_ptr)->data;
    log_time = GetSystemTime();
  }
  else if (src_1_location->v_type == c_bi_class_time)
  {
    source_ptr = log_ptr->source.data;
    log_time = *((Time *)src_1_location->v_data_ptr);
  }

  // - ERROR -
  else
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("write#3");
    new_exception->params.push(3);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);

    return false;
  }

  // - write string to log -
  log_ptr->log_set_ptr->Write(level,source_ptr,log_time,"%s",string_ptr->data);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_ucf_log_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("UcfLog"),"UcfLog")
  );

  return true;
}/*}}}*/

bool bic_ucf_log_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("UcfLog");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class UCF_MUTEX -
built_in_class_s ucf_mutex_class =
{/*{{{*/
  "UcfMutex",
  c_modifier_public | c_modifier_final,
  8, ucf_mutex_methods,
  0, ucf_mutex_variables,
  bic_ucf_mutex_consts,
  bic_ucf_mutex_init,
  bic_ucf_mutex_clear,
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

built_in_method_s ucf_mutex_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_ucf_mutex_operator_binary_equal
  },
  {
    "UcfMutex#1",
    c_modifier_public | c_modifier_final,
    bic_ucf_mutex_method_UcfMutex_1
  },
  {
    "UcfMutex#2",
    c_modifier_public | c_modifier_final,
    bic_ucf_mutex_method_UcfMutex_2
  },
  {
    "Reserve#0",
    c_modifier_public | c_modifier_final,
    bic_ucf_mutex_method_Reserve_0
  },
  {
    "Reserve#1",
    c_modifier_public | c_modifier_final,
    bic_ucf_mutex_method_Reserve_1
  },
  {
    "Release#0",
    c_modifier_public | c_modifier_final,
    bic_ucf_mutex_method_Release_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ucf_mutex_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ucf_mutex_method_print_0
  },
};/*}}}*/

built_in_variable_s ucf_mutex_variables[] =
{/*{{{*/
};/*}}}*/

void bic_ucf_mutex_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_ucf_mutex_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (Mutex *)nullptr;
}/*}}}*/

void bic_ucf_mutex_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  Mutex *mutex_ptr = (Mutex *)location_ptr->v_data_ptr;

  // - if mutex object exists -
  if (mutex_ptr != nullptr)
  {
    delete mutex_ptr;
  }
}/*}}}*/

bool bic_ucf_mutex_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_ucf_mutex_method_UcfMutex_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("UcfMutex#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve mutex name -
  string_s *name_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create mutex object -
  Mutex *mutex_ptr = new Mutex();

  try
  {
    mutex_ptr->Open(name_ptr->data);
  }

  // - ERROR -
  catch (Exception e)
  {
    delete mutex_ptr;

    exception_s::throw_exception(it,module.error_base + c_error_UCF_MUTEX_OPEN_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  // - set destination data pointer -
  dst_location->v_data_ptr = (Mutex *)mutex_ptr;

  return true;
}/*}}}*/

bool bic_ucf_mutex_method_UcfMutex_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int own;

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string ||
      !it.retrieve_integer(src_1_location,own))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("UcfMutex#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  // - retrieve mutex name -
  string_s *name_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create mutex object -
  Mutex *mutex_ptr = new Mutex();

  try
  {
    mutex_ptr->Create(name_ptr->data,own);
  }

  // - ERROR -
  catch (Exception e)
  {
    delete mutex_ptr;

    exception_s::throw_exception(it,module.error_base + c_error_UCF_MUTEX_CREATE_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  // - set destination data pointer -
  dst_location->v_data_ptr = (Mutex *)mutex_ptr;

  return true;
}/*}}}*/

bool bic_ucf_mutex_method_Reserve_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  Mutex *mutex_ptr = (Mutex *)dst_location->v_data_ptr;
  mutex_ptr->Reserve();

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_ucf_mutex_method_Reserve_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int timeout;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,timeout))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Reserve#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - ERROR -
  if (timeout < -1 || timeout > INT_MAX)
  {
    exception_s::throw_exception(it,module.error_base + c_error_UCF_MUTEX_TIMEOUT_PARM_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  Mutex *mutex_ptr = (Mutex *)dst_location->v_data_ptr;
  long long int result = mutex_ptr->Reserve(timeout);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_ucf_mutex_method_Release_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  Mutex *mutex_ptr = (Mutex *)dst_location->v_data_ptr;
  mutex_ptr->Release();

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_ucf_mutex_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("UcfMutex"),"UcfMutex")
  );

  return true;
}/*}}}*/

bool bic_ucf_mutex_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("UcfMutex");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class UCF_LED -
built_in_class_s ucf_led_class =
{/*{{{*/
  "UcfLed",
  c_modifier_public | c_modifier_final,
  7, ucf_led_methods,
  0, ucf_led_variables,
  bic_ucf_led_consts,
  bic_ucf_led_init,
  bic_ucf_led_clear,
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

built_in_method_s ucf_led_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_ucf_led_operator_binary_equal
  },
  {
    "UcfLed#1",
    c_modifier_public | c_modifier_final,
    bic_ucf_led_method_UcfLed_1
  },
  {
    "LightOn#0",
    c_modifier_public | c_modifier_final,
    bic_ucf_led_method_LightOn_0
  },
  {
    "LightOff#0",
    c_modifier_public | c_modifier_final,
    bic_ucf_led_method_LightOff_0
  },
  {
    "Toggle#0",
    c_modifier_public | c_modifier_final,
    bic_ucf_led_method_Toggle_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ucf_led_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_ucf_led_method_print_0
  },
};/*}}}*/

built_in_variable_s ucf_led_variables[] =
{/*{{{*/
};/*}}}*/

void bic_ucf_led_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_ucf_led_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (Led *)nullptr;
}/*}}}*/

void bic_ucf_led_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  Led *led_ptr = (Led *)location_ptr->v_data_ptr;

  // - if led object exists -
  if (led_ptr != nullptr)
  {
    delete led_ptr;
  }
}/*}}}*/

bool bic_ucf_led_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_ucf_led_method_UcfLed_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("UcfLed#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve led name -
  string_s *name_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create led object -
  Led *led_ptr = new Led();

  try
  {
    led_ptr->Open(name_ptr->data);
  }

  // - ERROR -
  catch (Exception e)
  {
    delete led_ptr;

    exception_s::throw_exception(it,module.error_base + c_error_UCF_LED_OPEN_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  // - set destination data pointer -
  dst_location->v_data_ptr = (Led *)led_ptr;

  return true;
}/*}}}*/

bool bic_ucf_led_method_LightOn_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve led pointer -
  Led *led_ptr = (Led *)dst_location->v_data_ptr;

  // - turn on led diod -
  led_ptr->LightOn();

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_ucf_led_method_LightOff_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve led pointer -
  Led *led_ptr = (Led *)dst_location->v_data_ptr;

  // - turn off led diod -
  led_ptr->LightOff();

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_ucf_led_method_Toggle_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve led pointer -
  Led *led_ptr = (Led *)dst_location->v_data_ptr;

  // - toggle led diod -
  led_ptr->Toggle();

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_ucf_led_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("UcfLed"),"UcfLed")
  );

  return true;
}/*}}}*/

bool bic_ucf_led_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("UcfLed");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class SERIAL -
built_in_class_s serial_class =
{/*{{{*/
  "Serial",
  c_modifier_public | c_modifier_final,
  8, serial_methods,
  6, serial_variables,
  bic_serial_consts,
  bic_serial_init,
  bic_serial_clear,
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

built_in_method_s serial_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_serial_operator_binary_equal
  },
  {
    "Serial#1",
    c_modifier_public | c_modifier_final,
    bic_serial_method_Serial_1
  },
  {
    "SetFormat#5",
    c_modifier_public | c_modifier_final,
    bic_serial_method_SetFormat_5
  },
  {
    "Write#1",
    c_modifier_public | c_modifier_final,
    bic_serial_method_Write_1
  },
  {
    "WriteAll#1",
    c_modifier_public | c_modifier_final,
    bic_serial_method_WriteAll_1
  },
  {
    "Read#0",
    c_modifier_public | c_modifier_final,
    bic_serial_method_Read_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_serial_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_serial_method_print_0
  },
};/*}}}*/

built_in_variable_s serial_variables[] =
{/*{{{*/
  {
    "FC_NONE",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "FC_RTS_CTS",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "FC_RS_485",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "PAR_NONE",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "PAR_EVEN",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "PAR_ODD",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
};/*}}}*/

void bic_serial_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert serial constants -
  {
    const_locations.push_blanks(6);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 6);

#define CREATE_SERIAL_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_SERIAL_BIC_STATIC(SerialPort::FC_NONE);
    CREATE_SERIAL_BIC_STATIC(SerialPort::FC_RTS_CTS);
    CREATE_SERIAL_BIC_STATIC(SerialPort::FC_RS_485);

    CREATE_SERIAL_BIC_STATIC(SerialPort::PAR_NONE);
    CREATE_SERIAL_BIC_STATIC(SerialPort::PAR_EVEN);
    CREATE_SERIAL_BIC_STATIC(SerialPort::PAR_ODD);
  }
}/*}}}*/

void bic_serial_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (SerialPort *)nullptr;
}/*}}}*/

void bic_serial_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/

  // - retrieve serial port object pointer -
  SerialPort *serial_ptr = (SerialPort *)location_ptr->v_data_ptr;

  // - if serial port object pointer is not null -
  if (serial_ptr != nullptr)
  {
    delete serial_ptr;
  }
}/*}}}*/

bool bic_serial_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_serial_method_Serial_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Serial#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - create new serial port object -
  SerialPort *serial_ptr = new SerialPort();

  // - retrieve name pointer -
  string_s *name_ptr = (string_s *)src_0_location->v_data_ptr;

  try
  {
    serial_ptr->Open(String(name_ptr->data));
  }

  // - ERROR -
  catch (Exception e)
  {
    delete serial_ptr;

    exception_s::throw_exception(it,module.error_base + c_error_SERIAL_OPEN_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  // - set destination data pointer -
  dst_location->v_data_ptr = (SerialPort *)serial_ptr;

  return true;
}/*}}}*/

bool bic_serial_method_SetFormat_5(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);
  location_s *src_3_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_3_op_idx]);
  location_s *src_4_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_4_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_integer ||
      src_1_location->v_type != c_bi_class_integer ||
      src_2_location->v_type != c_bi_class_integer ||
      src_3_location->v_type != c_bi_class_integer ||
      src_4_location->v_type != c_bi_class_integer)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("SetFormat#5");
    new_exception->params.push(5);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);
    new_exception->params.push(src_3_location->v_type);
    new_exception->params.push(src_4_location->v_type);

    return false;
  }

  // - retrieve serial port object pointer -
  SerialPort *serial_ptr = (SerialPort *)dst_location->v_data_ptr;

  int baudrate = (long long int)src_0_location->v_data_ptr;
  SerialPort::Flow flow = (SerialPort::Flow)(long long int)src_1_location->v_data_ptr;
  SerialPort::Parity parity = (SerialPort::Parity)(long long int)src_2_location->v_data_ptr;
  int data = (long long int)src_3_location->v_data_ptr;
  int stop = (long long int)src_4_location->v_data_ptr;

  try
  {
    serial_ptr->SetFormat(baudrate,flow,parity,data,stop);
  }

  // - ERROR -
  catch (Exception e)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SERIAL_SETUP_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_serial_method_Write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Write#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve serial port object pointer -
  SerialPort *serial_ptr = (SerialPort *)dst_location->v_data_ptr;

  // - retrieve string pointer -
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  long long int writed = 0;
  try
  {
    // - try to write string to serial port -
    int length = string_ptr->size - 1;
    if (length > 0)
    {
      writed = serial_ptr->Write(string_ptr->data,length);
    }
  }

  // - ERROR -
  catch (Exception e)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SERIAL_WRITE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,writed);

  return true;
}/*}}}*/

bool bic_serial_method_WriteAll_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("WriteAll#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve serial port object pointer -
  SerialPort *serial_ptr = (SerialPort *)dst_location->v_data_ptr;

  // - retrieve string pointer -
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  try
  {
    // - write whole string to serial port -
    int length = string_ptr->size - 1;
    if (length > 0)
    {
      int writed = 0;
      do
      {
        writed += serial_ptr->Write(string_ptr->data + writed,length - writed);
      }
      while(writed < length);
    }
  }

  // - ERROR -
  catch (Exception e)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SERIAL_WRITE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_serial_method_Read_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve serial port object pointer -
  SerialPort *serial_ptr = (SerialPort *)dst_location->v_data_ptr;

  const unsigned c_buffer_add = 1024;

  // - target data buffer -
  bc_array_s data_buffer;
  data_buffer.init();

  // - read all available data from serial port -
  try
  {
    unsigned read_cnt;
    do
    {
      unsigned old_used = data_buffer.used;
      data_buffer.push_blanks(c_buffer_add);
      read_cnt = serial_ptr->Read(data_buffer.data + old_used,c_buffer_add);
    }
    while(read_cnt >= c_buffer_add);

    data_buffer.used = (data_buffer.used - c_buffer_add) + read_cnt;
    data_buffer.push('\0');
  }

  // - ERROR -
  catch (Exception e)
  {
    data_buffer.clear();

    exception_s::throw_exception(it,module.error_base + c_error_SERIAL_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - return data string -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->data = data_buffer.data;
  string_ptr->size = data_buffer.used;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_serial_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Serial"),"Serial")
  );

  return true;
}/*}}}*/

bool bic_serial_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("Serial");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class VAR_STORE -
built_in_class_s var_store_class =
{/*{{{*/
  "VarStore",
  c_modifier_public | c_modifier_final,
  11, var_store_methods,
  16, var_store_variables,
  bic_var_store_consts,
  bic_var_store_init,
  bic_var_store_clear,
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

built_in_method_s var_store_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_var_store_operator_binary_equal
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_var_store_operator_binary_le_br_re_br
  },
  {
    "VarStore#2",
    c_modifier_public | c_modifier_final,
    bic_var_store_method_VarStore_2
  },
  {
    "VarStore#5",
    c_modifier_public | c_modifier_final,
    bic_var_store_method_VarStore_5
  },
  {
    "clear_slots#0",
    c_modifier_public | c_modifier_final,
    bic_var_store_method_clear_slots_0
  },
  {
    "item#1",
    c_modifier_public | c_modifier_final,
    bic_var_store_method_item_1
  },
  {
    "first_idx#0",
    c_modifier_public | c_modifier_final,
    bic_var_store_method_first_idx_0
  },
  {
    "next_idx#1",
    c_modifier_public | c_modifier_final,
    bic_var_store_method_next_idx_1
  },
  {
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_var_store_method_length_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_var_store_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_var_store_method_print_0
  },
};/*}}}*/

built_in_variable_s var_store_variables[] =
{/*{{{*/
  {
    "TBOOL",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "TSINT",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "TINT",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "TDINT",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "TLINT",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "TUSINT",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "TUINT",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "TUDINT",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "TULINT",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "TREAL",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "TLREAL",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "TTIME",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "TDATE",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "TTOD",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "TDT",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "TSTRING",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
};/*}}}*/

#define BIC_VAR_STORE_VAR_SLOT_CHECK() \
  /*{{{*/\
  switch (varType)\
  {\
  case TBOOL:   size_test = varSize == 1; break;\
  case TSINT:   size_test = varSize == 1; break;\
  case TINT:    size_test = varSize == 2; break;\
  case TDINT:   size_test = varSize == 4; break;\
  case TLINT:   size_test = varSize == 8; break;\
  case TUSINT:  size_test = varSize == 1; break;\
  case TUINT:   size_test = varSize == 2; break;\
  case TUDINT:  size_test = varSize == 4; break;\
  case TULINT:  size_test = varSize == 8; break;\
  case TREAL:   size_test = varSize == 4; break;\
  case TLREAL:  size_test = varSize == 8; break;\
  case TSTRING: \
    size_test = varSize >= 1 && varSize <= c_vs_max_str_size;\
    break;\
  }\
  /*}}}*/

#define BIC_VAR_STORE_CHECK_INDEX() \
  /*{{{*/\
  VarStore *vs_ptr = (VarStore *)dst_location->v_data_ptr;\
  \
  VarStore::StoreInfo vsInfo;\
  vs_ptr->GetStoreInfo(&vsInfo);\
  \
  /* - ERROR - */\
  if (index < 0 || index >= vsInfo.slots) {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_VAR_STORE_INDEX_EXCEEDS_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(index);\
    \
    return false;\
  }\
  /*}}}*/

#define BIC_VAR_STORE_ITEM(NAME) \
  {/*{{{*/\
    pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];\
    location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);\
    location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);\
    \
    long long int index;\
    \
    if (!it.retrieve_integer(src_0_location,index))\
    {\
      /* - ERROR - */\
      if (src_0_location->v_type != c_bi_class_string)\
      {\
        exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);\
        BIC_EXCEPTION_PUSH_METHOD_RI(NAME);\
        new_exception->params.push(1);\
        new_exception->params.push(src_0_location->v_type);\
        \
        return false;\
      }\
      \
      /* - retrieve varstore pointer and slot name - */\
      VarStore *vs_ptr = (VarStore *)dst_location->v_data_ptr;\
      string_s *name_ptr = (string_s *)src_0_location->v_data_ptr;\
      \
      VarStore::StoreInfo vsInfo;\
      vs_ptr->GetStoreInfo(&vsInfo);\
      \
      /* - find slot index by its name - */\
      int idx = 0;\
      if (vsInfo.slots > 0 && name_ptr->size <= c_vs_slot_info_name_size)\
      {\
        VarStore::SlotInfo vssInfo;\
        \
        do {\
          vs_ptr->GetSlotInfo(idx,&vssInfo);\
          \
          if (memcmp(name_ptr->data,vssInfo.name,name_ptr->size) == 0)\
          {\
            break;\
          }\
        } while(++idx < vsInfo.slots);\
        \
        /* - ERROR - */\
        if (idx >= vsInfo.slots)\
        {\
          exception_s::throw_exception(it,module.error_base + c_error_VAR_STORE_SLOT_NAME_NOT_FOUND,operands[c_source_pos_idx],src_0_location);\
          return false;\
        }\
      }\
      \
      index = (long long int)idx;\
    }\
    else {\
      BIC_VAR_STORE_CHECK_INDEX();\
    }\
    \
    /* - create new varstore slot object - */\
    varstore_slot_s *new_vss_ptr = (varstore_slot_s *)cmalloc(sizeof(varstore_slot_s));\
    \
    dst_location->v_reference_cnt.atomic_inc();\
    new_vss_ptr->vs_ptr = dst_location;\
    new_vss_ptr->slot_idx = index;\
    \
    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_var_slot,new_vss_ptr);\
    BIC_SET_RESULT(new_location);\
    \
    return true;\
  }/*}}}*/

void bic_var_store_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert varstore data type constants -
  {
    const_locations.push_blanks(16);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 16);

#define CREATE_VAR_STORE_TYPE_BIC_STATIC(DATA_TYPE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)DATA_TYPE;\
  cv_ptr++;

    CREATE_VAR_STORE_TYPE_BIC_STATIC(TBOOL);
    CREATE_VAR_STORE_TYPE_BIC_STATIC(TSINT);
    CREATE_VAR_STORE_TYPE_BIC_STATIC(TINT);
    CREATE_VAR_STORE_TYPE_BIC_STATIC(TDINT);
    CREATE_VAR_STORE_TYPE_BIC_STATIC(TLINT);
    CREATE_VAR_STORE_TYPE_BIC_STATIC(TUSINT);
    CREATE_VAR_STORE_TYPE_BIC_STATIC(TUINT);
    CREATE_VAR_STORE_TYPE_BIC_STATIC(TUDINT);
    CREATE_VAR_STORE_TYPE_BIC_STATIC(TULINT);
    CREATE_VAR_STORE_TYPE_BIC_STATIC(TREAL);
    CREATE_VAR_STORE_TYPE_BIC_STATIC(TLREAL);
    CREATE_VAR_STORE_TYPE_BIC_STATIC(TTIME);
    CREATE_VAR_STORE_TYPE_BIC_STATIC(TDATE);
    CREATE_VAR_STORE_TYPE_BIC_STATIC(TTOD);
    CREATE_VAR_STORE_TYPE_BIC_STATIC(TDT);
    CREATE_VAR_STORE_TYPE_BIC_STATIC(TSTRING);
  }

}/*}}}*/

void bic_var_store_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (VarStore *)nullptr;
}/*}}}*/

void bic_var_store_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  VarStore *vs_ptr = (VarStore *)location_ptr->v_data_ptr;

  if (vs_ptr != nullptr)
  {
    delete vs_ptr;
  }
}/*}}}*/

bool bic_var_store_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_var_store_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_VAR_STORE_ITEM("operator_binary_le_br_re_br#1");
}/*}}}*/

bool bic_var_store_method_VarStore_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string ||
      src_1_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("VarStore#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  // - retrieve varstore and client name -
  string_s *vs_name_ptr = (string_s *)src_0_location->v_data_ptr;
  string_s *cl_name_ptr = (string_s *)src_1_location->v_data_ptr;

  // - ERROR -
  if (cl_name_ptr->size - 1 > c_vs_client_info_name_size)
  {
    exception_s::throw_exception(it,module.error_base + c_error_VAR_STORE_CLIENT_NAME_TOO_LONG,operands[c_source_pos_idx],src_1_location);
    return false;
  }

  VarStore *new_vs_ptr = new VarStore();

  try
  {
    new_vs_ptr->Open(String(vs_name_ptr->data),cl_name_ptr->data);
  }

  // - ERROR -
  catch (Exception e)
  {
    delete new_vs_ptr;

    exception_s::throw_exception(it,module.error_base + c_error_VAR_STORE_OPEN_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  // - check varstore slots -
  VarStore::StoreInfo vsInfo;
  new_vs_ptr->GetStoreInfo(&vsInfo);

  if (vsInfo.slots > 0)
  {
    VarStore::SlotInfo vssInfo;

    int s_idx = 0;
    do
    {
      new_vs_ptr->GetSlotInfo(s_idx,&vssInfo);

      int varType = vssInfo.varType;
      int varSize = vssInfo.varSize;

      bool size_test = true;
      BIC_VAR_STORE_VAR_SLOT_CHECK();

      // - ERROR -
      if (!size_test)
      {
        delete new_vs_ptr;

        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_VAR_STORE_UNKNOWN_TYPE_SIZE_COMBINATION,operands[c_source_pos_idx],(location_s *)it.blank_location);
        new_exception->params.push(varType);
        new_exception->params.push(varSize);

        return false;
      }

    }
    while(++s_idx < vsInfo.slots);
  }

  // - set destination data pointer -
  dst_location->v_data_ptr = (VarStore *)new_vs_ptr;

  return true;
}/*}}}*/

bool bic_var_store_method_VarStore_5(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);
  location_s *src_3_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_3_op_idx]);
  location_s *src_4_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_4_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string ||
      src_1_location->v_type != c_bi_class_array ||
      src_2_location->v_type != c_bi_class_integer ||
      src_3_location->v_type != c_bi_class_integer ||
      src_4_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("VarStore#5");
    new_exception->params.push(5);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);
    new_exception->params.push(src_3_location->v_type);
    new_exception->params.push(src_4_location->v_type);

    return false;
  }

  pointer_array_s *slots_ptr = (pointer_array_s *)src_1_location->v_data_ptr;

  // - ERROR -
  if (slots_ptr->used == 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_VAR_STORE_CREATE_NO_SLOTS_DEFINED,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  VarStore::SlotInfo *SlotInfos = (VarStore::SlotInfo *)cmalloc(slots_ptr->used*sizeof(VarStore::SlotInfo));

  unsigned s_idx = 0;
  do
  {
    location_s *slot_location = it.get_location_value(slots_ptr->data[s_idx]);

    // - ERROR -
    if (slot_location->v_type != c_bi_class_array)
    {
      cfree(SlotInfos);

      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_VAR_STORE_CREATE_WRONG_SLOT_DESCRIPTION,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(s_idx);

      return false;
    }

    pointer_array_s *slot_ptr = (pointer_array_s *)slot_location->v_data_ptr;

    // - ERROR -
    if (slot_ptr->used < 6)
    {
      cfree(SlotInfos);

      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_VAR_STORE_CREATE_WRONG_SLOT_DESCRIPTION,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(s_idx);

      return false;
    }

    location_s *slot_name_loc    = it.get_location_value(slot_ptr->data[0]);
    location_s *slot_status_loc  = it.get_location_value(slot_ptr->data[1]);
    location_s *slot_varId_loc   = it.get_location_value(slot_ptr->data[2]);
    location_s *slot_varType_loc = it.get_location_value(slot_ptr->data[3]);
    location_s *slot_varSize_loc = it.get_location_value(slot_ptr->data[4]);
    location_s *slot_nVars_loc   = it.get_location_value(slot_ptr->data[5]);

    // - ERROR -
    if (slot_name_loc->v_type != c_bi_class_string ||
        slot_status_loc->v_type != c_bi_class_integer ||
        slot_varId_loc->v_type != c_bi_class_integer ||
        slot_varType_loc->v_type != c_bi_class_integer ||
        slot_varSize_loc->v_type != c_bi_class_integer ||
        slot_nVars_loc->v_type != c_bi_class_integer)
    {
      cfree(SlotInfos);

      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_VAR_STORE_CREATE_WRONG_SLOT_DESCRIPTION,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(s_idx);

      return false;
    }

    string_s *s_name_ptr = (string_s *)slot_name_loc->v_data_ptr;
    int status = (long long int)slot_status_loc->v_data_ptr;
    int varId = (long long int)slot_varId_loc->v_data_ptr;
    int varType = (long long int)slot_varType_loc->v_data_ptr;
    int varSize = (long long int)slot_varSize_loc->v_data_ptr;
    int nVars = (long long int)slot_nVars_loc->v_data_ptr;

    bool size_test = true;
    BIC_VAR_STORE_VAR_SLOT_CHECK();

    // - ERROR -
    if (!size_test)
    {
      cfree(SlotInfos);

      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_VAR_STORE_UNKNOWN_TYPE_SIZE_COMBINATION,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(varType);
      new_exception->params.push(varSize);

      return false;
    }

    // - ERROR -
    if (nVars <= 0)
    {
      cfree(SlotInfos);

      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_VAR_STORE_CREATE_WRONG_VARIABLE_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(nVars);

      return false;
    }

    // - ERROR -
    if (s_name_ptr->size - 1 > c_vs_slot_info_name_size)
    {
      cfree(SlotInfos);

      exception_s::throw_exception(it,module.error_base + c_error_VAR_STORE_CREATE_SLOT_NAME_TOO_LONG,operands[c_source_pos_idx],slot_name_loc);
      return false;
    }

    VarStore::SlotInfo &SlotInfo = SlotInfos[s_idx];

    // - initialize variable slot -
    memcpy(SlotInfo.name,s_name_ptr->data,s_name_ptr->size);
    SlotInfo.status = status;
    SlotInfo.varId = varId;
    SlotInfo.varType = varType;
    SlotInfo.varSize = varSize;
    SlotInfo.nVars = nVars;

  }
  while(++s_idx < slots_ptr->used);

  string_s *vs_name_ptr = (string_s *)src_0_location->v_data_ptr;
  int clients = (long long int)src_2_location->v_data_ptr;
  int events = (long long int)src_3_location->v_data_ptr;
  string_s *cl_name_ptr = (string_s *)src_4_location->v_data_ptr;

  // - ERROR -
  if (cl_name_ptr->size - 1 > c_vs_client_info_name_size)
  {
    cfree(SlotInfos);

    exception_s::throw_exception(it,module.error_base + c_error_VAR_STORE_CLIENT_NAME_TOO_LONG,operands[c_source_pos_idx],src_4_location);
    return false;
  }

  VarStore *new_vs_ptr = new VarStore();

  try
  {
    new_vs_ptr->Create(String(vs_name_ptr->data),SlotInfos,slots_ptr->used,clients,events,cl_name_ptr->data);
  }

  // - ERROR -
  catch (Exception e)
  {
    delete new_vs_ptr;
    cfree(SlotInfos);

    exception_s::throw_exception(it,module.error_base + c_error_VAR_STORE_CREATE_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  cfree(SlotInfos);

  // - set destination data pointer -
  dst_location->v_data_ptr = (VarStore *)new_vs_ptr;

  return true;
}/*}}}*/

bool bic_var_store_method_clear_slots_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve varstore pointer -
  VarStore *vs_ptr = (VarStore *)dst_location->v_data_ptr;

  // - retrieve varstore info -
  VarStore::StoreInfo vsInfo;
  vs_ptr->GetStoreInfo(&vsInfo);

  // - clear all varstore slots -
  int s_idx = 0;
  if (vsInfo.slots > 0)
  {
    VarStore::SlotInfo vssInfo;

    do {
      vs_ptr->GetSlotInfo(s_idx,&vssInfo);

      if (vssInfo.nVars >= 1)
      {
        // - erase slot variables (all indexes) -
        int v_idx = 0;
        do {
          vs_ptr->Write(s_idx,v_idx,c_zeroes,vssInfo.varSize,0,0,false);
        } while(++v_idx < vssInfo.nVars);
      }
    } while(++s_idx < vsInfo.slots);
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_var_store_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_VAR_STORE_ITEM("item#1");
}/*}}}*/

bool bic_var_store_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  VarStore *vs_ptr = (VarStore *)dst_location->v_data_ptr;

  VarStore::StoreInfo vsInfo;
  vs_ptr->GetStoreInfo(&vsInfo);

  if (vsInfo.slots > 0)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,0);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_var_store_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
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

  BIC_VAR_STORE_CHECK_INDEX();

  if (++index < vsInfo.slots)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,index);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_var_store_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  VarStore *vs_ptr = (VarStore *)dst_location->v_data_ptr;

  VarStore::StoreInfo vsInfo;
  vs_ptr->GetStoreInfo(&vsInfo);

  long long int result = vsInfo.slots;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_var_store_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("VarStore"),"VarStore")
  );

  return true;
}/*}}}*/

bool bic_var_store_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("VarStore");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class VAR_SLOT -
built_in_class_s var_slot_class =
{/*{{{*/
  "VarSlot",
  c_modifier_public | c_modifier_final,
  17, var_slot_methods,
  0, var_slot_variables,
  bic_var_slot_consts,
  bic_var_slot_init,
  bic_var_slot_clear,
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

built_in_method_s var_slot_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_var_slot_operator_binary_equal
  },
  {
    "operator_binary_le_br_re_br#1",
    c_modifier_public | c_modifier_final,
    bic_var_slot_operator_binary_le_br_re_br
  },
  {
    "index#0",
    c_modifier_public | c_modifier_final,
    bic_var_slot_method_index_0
  },
  {
    "name#0",
    c_modifier_public | c_modifier_final,
    bic_var_slot_method_name_0
  },
  {
    "varType#0",
    c_modifier_public | c_modifier_final,
    bic_var_slot_method_varType_0
  },
  {
    "varSize#0",
    c_modifier_public | c_modifier_final,
    bic_var_slot_method_varSize_0
  },
  {
    "clear#0",
    c_modifier_public | c_modifier_final,
    bic_var_slot_method_clear_0
  },
  {
    "write#1",
    c_modifier_public | c_modifier_final,
    bic_var_slot_method_write_1
  },
  {
    "write#2",
    c_modifier_public | c_modifier_final,
    bic_var_slot_method_write_2
  },
  {
    "read#0",
    c_modifier_public | c_modifier_final,
    bic_var_slot_method_read_0
  },
  {
    "read#1",
    c_modifier_public | c_modifier_final,
    bic_var_slot_method_read_1
  },
  {
    "item#1",
    c_modifier_public | c_modifier_final,
    bic_var_slot_method_item_1
  },
  {
    "first_idx#0",
    c_modifier_public | c_modifier_final,
    bic_var_slot_method_first_idx_0
  },
  {
    "next_idx#1",
    c_modifier_public | c_modifier_final,
    bic_var_slot_method_next_idx_1
  },
  {
    "length#0",
    c_modifier_public | c_modifier_final,
    bic_var_slot_method_length_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_var_slot_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_var_slot_method_print_0
  },
};/*}}}*/

built_in_variable_s var_slot_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_VAR_SLOT_CHECK_INDEX() \
  /*{{{*/\
  varstore_slot_s *vss_ptr = (varstore_slot_s *)dst_location->v_data_ptr;\
  VarStore *vs_ptr = (VarStore *)vss_ptr->vs_ptr->v_data_ptr;\
  \
  VarStore::SlotInfo vssInfo;\
  vs_ptr->GetSlotInfo(vss_ptr->slot_idx,&vssInfo);\
  \
  /* - ERROR - */\
  if (index < 0 || index >= vssInfo.nVars) {\
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_VAR_SLOT_INDEX_EXCEEDS_RANGE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(index);\
    \
    return false;\
  }\
  /*}}}*/

#define BIC_VAR_SLOT_WRITE(INDEX,SRC_LOCATION) \
  {/*{{{*/\
    int size = vssInfo.varSize;\
    \
    switch (vssInfo.varType)\
    {\
    case TBOOL:\
    case TSINT:\
    case TINT:\
    case TDINT:\
    case TLINT:\
    case TUSINT:\
    case TUINT:\
    case TUDINT:\
    case TULINT:\
    {\
      /* - ERROR - */\
      if (SRC_LOCATION->v_type != c_bi_class_integer)\
      {\
        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_VAR_SLOT_WRITE_WRONG_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
        new_exception->params.push(c_bi_class_integer);\
        \
        return false;\
      }\
      \
      long long int value = (long long int)SRC_LOCATION->v_data_ptr;\
      \
      switch (vssInfo.varType)\
      {\
      case TBOOL:\
      {\
        unsigned char data = value;\
        vs_ptr->Write(vss_ptr->slot_idx,INDEX,&data,size,0,0,false);\
      }\
      break;\
      case TSINT:\
      {\
        signed char data = value;\
        vs_ptr->Write(vss_ptr->slot_idx,INDEX,&data,size,0,0,false);\
      }\
      break;\
      case TINT:\
      {\
        short data = value;\
        vs_ptr->Write(vss_ptr->slot_idx,INDEX,&data,size,0,0,false);\
      }\
      break;\
      case TDINT:\
      {\
        int data = value;\
        vs_ptr->Write(vss_ptr->slot_idx,INDEX,&data,size,0,0,false);\
      }\
      break;\
      case TLINT:\
      {\
        long long int data = value;\
        vs_ptr->Write(vss_ptr->slot_idx,INDEX,&data,size,0,0,false);\
      }\
      break;\
      case TUSINT:\
      {\
        unsigned char data = value;\
        vs_ptr->Write(vss_ptr->slot_idx,INDEX,&data,size,0,0,false);\
      }\
      break;\
      case TUINT:\
      {\
        unsigned short data = value;\
        vs_ptr->Write(vss_ptr->slot_idx,INDEX,&data,size,0,0,false);\
      }\
      break;\
      case TUDINT:\
      {\
        unsigned data = value;\
        vs_ptr->Write(vss_ptr->slot_idx,INDEX,&data,size,0,0,false);\
      }\
      break;\
      case TULINT:\
      {\
        long long unsigned data = value;\
        vs_ptr->Write(vss_ptr->slot_idx,INDEX,&data,size,0,0,false);\
      }\
      break;\
      }\
    }\
    break;\
    \
    case TREAL:\
    case TLREAL:\
    {\
      /* - ERROR - */\
      if (SRC_LOCATION->v_type != c_bi_class_float)\
      {\
        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_VAR_SLOT_WRITE_WRONG_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
        new_exception->params.push(c_bi_class_float);\
        \
        return false;\
      }\
      \
      double value = (double)((location_s *)SRC_LOCATION)->v_data_ptr;\
      \
      switch (vssInfo.varType)\
      {\
      case TREAL:\
      {\
        float data = value;\
        vs_ptr->Write(vss_ptr->slot_idx,INDEX,&data,size,0,0,false);\
      }\
      break;\
      case TLREAL:\
      {\
        double data = value;\
        vs_ptr->Write(vss_ptr->slot_idx,INDEX,&data,size,0,0,false);\
      }\
      break;\
      }\
    }\
    break;\
    \
    case TSTRING:\
    {\
      /* - ERROR - */\
      if (SRC_LOCATION->v_type != c_bi_class_string)\
      {\
        exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_VAR_SLOT_WRITE_WRONG_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
        new_exception->params.push(c_bi_class_string);\
        \
        return false;\
      }\
      \
      string_s *string_ptr = (string_s *)SRC_LOCATION->v_data_ptr;\
      \
      /* - ERROR - */\
      if ((int)string_ptr->size > size)\
      {\
        exception_s::throw_exception(it,module.error_base + c_error_VAR_SLOT_WRITE_STRING_TOO_LONG,operands[c_source_pos_idx],(location_s *)it.blank_location);\
        return false;\
      }\
      \
      char data[c_vs_max_str_size];\
      data[0] = string_ptr->size - 1;\
      memcpy(data + 1,string_ptr->data,string_ptr->size - 1);\
      \
      vs_ptr->Write(vss_ptr->slot_idx,INDEX,data,string_ptr->size,0,0,false);\
    }\
    break;\
    \
    /* - ERROR - */\
    default:\
      exception_s::throw_exception(it,module.error_base + c_error_VAR_SLOT_WRITE_UNKNOWN_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      return false;\
    }\
  }/*}}}*/

#define BIC_VAR_SLOT_WRITE_BLOCK_PROC_INTEGER(TYPE) \
  {/*{{{*/\
    TYPE *ptr = (TYPE *)buffer;\
    TYPE *ptr_end = ptr + count;\
    pointer *p_ptr = array_ptr->data;\
    do {\
      long long int value = (long long int)it.get_location_value(*p_ptr)->v_data_ptr;\
      *ptr = value;\
    } while(++p_ptr,++ptr < ptr_end);\
  }/*}}}*/

#define BIC_VAR_SLOT_WRITE_BLOCK_PROC_FLOAT(TYPE) \
  {/*{{{*/\
    TYPE *ptr = (TYPE *)buffer;\
    TYPE *ptr_end = ptr + count;\
    pointer *p_ptr = array_ptr->data;\
    do {\
      double value = (double)it.get_location_value(*p_ptr)->v_data_ptr;\
      *ptr = value;\
    } while(++p_ptr,++ptr < ptr_end);\
  }/*}}}*/

#define BIC_VAR_SLOT_WRITE_BLOCK(SRC_LOCATION) \
  {/*{{{*/\
    int count = vssInfo.nVars;\
    int size = vssInfo.varSize;\
    \
    /* - ERROR - */\
    if ((SRC_LOCATION)->v_type != c_bi_class_array)\
    {\
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_VAR_SLOT_WRITE_EXPECTED_ARRAY,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      new_exception->params.push(count);\
      \
      return false;\
    }\
    \
    pointer_array_s *array_ptr = (pointer_array_s *)(SRC_LOCATION)->v_data_ptr;\
    \
    /* - ERROR - */\
    if ((int)array_ptr->used != count)\
    {\
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_VAR_SLOT_WRITE_EXPECTED_ARRAY,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      new_exception->params.push(count);\
      \
      return false;\
    }\
    \
    if (count > 0)\
    {\
      unsigned type = it.get_location_value(array_ptr->data[0])->v_type;\
      \
      /* - check that all elements has same type - */\
      if(array_ptr->used >= 2)\
      {\
        pointer *p_ptr = array_ptr->data + 1;\
        pointer *p_ptr_end = array_ptr->data + array_ptr->used;\
        do {\
          \
          /* - ERROR - */\
          if (it.get_location_value(*p_ptr)->v_type != type)\
          {\
            exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_VAR_SLOT_WRITE_EXPECTED_ARRAY,operands[c_source_pos_idx],(location_s *)it.blank_location);\
            new_exception->params.push(count);\
            \
            return false;\
          }\
        } while(++p_ptr < p_ptr_end);\
      }\
      \
      switch (vssInfo.varType)\
      {\
      case TBOOL:\
      case TSINT:\
      case TINT:\
      case TDINT:\
      case TLINT:\
      case TUSINT:\
      case TUINT:\
      case TUDINT:\
      case TULINT:\
      {\
        /* - ERROR - */\
        if (type != c_bi_class_integer)\
        {\
          exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_VAR_SLOT_WRITE_WRONG_ARRAY_ELEMENT_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
          new_exception->params.push(c_bi_class_integer);\
          \
          return false;\
        }\
        \
        void *buffer = cmalloc(count*size);\
        \
        switch (vssInfo.varType)\
        {\
        case TBOOL:\
          BIC_VAR_SLOT_WRITE_BLOCK_PROC_INTEGER(unsigned char);\
          break;\
        case TSINT:\
          BIC_VAR_SLOT_WRITE_BLOCK_PROC_INTEGER(signed char);\
          break;\
        case TINT:\
          BIC_VAR_SLOT_WRITE_BLOCK_PROC_INTEGER(short);\
          break;\
        case TDINT:\
          BIC_VAR_SLOT_WRITE_BLOCK_PROC_INTEGER(int);\
          break;\
        case TLINT:\
          BIC_VAR_SLOT_WRITE_BLOCK_PROC_INTEGER(long long int);\
          break;\
        case TUSINT:\
          BIC_VAR_SLOT_WRITE_BLOCK_PROC_INTEGER(unsigned char);\
          break;\
        case TUINT:\
          BIC_VAR_SLOT_WRITE_BLOCK_PROC_INTEGER(unsigned short);\
          break;\
        case TUDINT:\
          BIC_VAR_SLOT_WRITE_BLOCK_PROC_INTEGER(unsigned);\
          break;\
        case TULINT:\
          BIC_VAR_SLOT_WRITE_BLOCK_PROC_INTEGER(long long unsigned);\
          break;\
        }\
        \
        vs_ptr->WriteBlock(vss_ptr->slot_idx,0,count,buffer,count*size,0,0,false);\
        cfree(buffer);\
      }\
      break;\
      \
      case TREAL:\
      case TLREAL:\
      {\
        /* - ERROR - */\
        if (type != c_bi_class_float)\
        {\
          exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_VAR_SLOT_WRITE_WRONG_ARRAY_ELEMENT_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
          new_exception->params.push(c_bi_class_float);\
          \
          return false;\
        }\
        \
        void *buffer = cmalloc(count*size);\
        \
        switch (vssInfo.varType)\
        {\
        case TREAL:\
          BIC_VAR_SLOT_WRITE_BLOCK_PROC_FLOAT(float);\
          break;\
        case TLREAL:\
          BIC_VAR_SLOT_WRITE_BLOCK_PROC_FLOAT(double);\
          break;\
        }\
        \
        vs_ptr->WriteBlock(vss_ptr->slot_idx,0,count,buffer,count*size,0,0,false);\
        cfree(buffer);\
      }\
      break;\
      \
      case TSTRING:\
      {\
        /* - ERROR - */\
        if (type != c_bi_class_string)\
        {\
          exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_VAR_SLOT_WRITE_WRONG_ARRAY_ELEMENT_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
          new_exception->params.push(c_bi_class_string);\
          \
          return false;\
        }\
        \
        char *buffer = (char *)cmalloc(count*size*sizeof(char));\
        \
        char *ptr = buffer;\
        char *ptr_end = ptr + count*size;\
        pointer *p_ptr = array_ptr->data;\
        do {\
          string_s *string_ptr = (string_s *)it.get_location_value(*p_ptr)->v_data_ptr;\
          \
          /* - ERROR - */\
          if ((int)string_ptr->size > size)\
          {\
            cfree(buffer);\
            \
            exception_s::throw_exception(it,module.error_base + c_error_VAR_SLOT_WRITE_STRING_TOO_LONG,operands[c_source_pos_idx],(location_s *)it.blank_location);\
            return false;\
          }\
          \
          ptr[0] = string_ptr->size - 1;\
          memcpy(ptr + 1,string_ptr->data,string_ptr->size - 1);\
          \
        } while(++p_ptr,(ptr += size) < ptr_end);\
        \
        vs_ptr->WriteBlock(vss_ptr->slot_idx,0,count,buffer,count*size,0,0,false);\
        \
        cfree(buffer);\
      }\
      break;\
      \
      /* - ERROR - */\
      default:\
        exception_s::throw_exception(it,module.error_base + c_error_VAR_SLOT_WRITE_UNKNOWN_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
        return false;\
      }\
    }\
  }/*}}}*/

#define BIC_VAR_SLOT_READ(INDEX) \
  {/*{{{*/\
    int size = vssInfo.varSize;\
    \
    switch (vssInfo.varType)\
    {\
    case TBOOL:\
    case TSINT:\
    case TINT:\
    case TDINT:\
    case TLINT:\
    case TUSINT:\
    case TUINT:\
    case TUDINT:\
    case TULINT:\
    {\
      long long int result = 0;\
      \
      switch (vssInfo.varType)\
      {\
      case TBOOL:\
      {\
        unsigned char data;\
        vs_ptr->Read(vss_ptr->slot_idx,INDEX,&data,size,0,0);\
        result = data & 0x01;\
      }\
      break;\
      case TSINT:\
      {\
        signed char data;\
        vs_ptr->Read(vss_ptr->slot_idx,INDEX,&data,size,0,0);\
        \
        result = data;\
      }\
      break;\
      case TINT:\
      {\
        short data;\
        vs_ptr->Read(vss_ptr->slot_idx,INDEX,&data,size,0,0);\
        result = data;\
      }\
      break;\
      case TDINT:\
      {\
        int data;\
        vs_ptr->Read(vss_ptr->slot_idx,INDEX,&data,size,0,0);\
        result = data;\
      }\
      break;\
      case TLINT:\
      {\
        long long int data;\
        vs_ptr->Read(vss_ptr->slot_idx,INDEX,&data,size,0,0);\
        result = data;\
      }\
      break;\
      case TUSINT:\
      {\
        unsigned char data;\
        vs_ptr->Read(vss_ptr->slot_idx,INDEX,&data,size,0,0);\
        result = data;\
      }\
      break;\
      case TUINT:\
      {\
        unsigned short data;\
        vs_ptr->Read(vss_ptr->slot_idx,INDEX,&data,size,0,0);\
        result = data;\
      }\
      break;\
      case TUDINT:\
      {\
        unsigned data;\
        vs_ptr->Read(vss_ptr->slot_idx,INDEX,&data,size,0,0);\
        result = data;\
      }\
      break;\
      case TULINT:\
      {\
        long long unsigned data;\
        vs_ptr->Read(vss_ptr->slot_idx,INDEX,&data,size,0,0);\
        result = data;\
      }\
      break;\
      }\
      \
      BIC_SIMPLE_SET_RES(c_bi_class_integer,result);\
    }\
    break;\
    \
    case TREAL:\
    case TLREAL:\
    {\
      double result = 0.0;\
      \
      switch (vssInfo.varType)\
      {\
      case TREAL:\
      {\
        float data;\
        vs_ptr->Read(vss_ptr->slot_idx,INDEX,&data,size,0,0);\
        result = data;\
      }\
      break;\
      case TLREAL:\
      {\
        double data;\
        vs_ptr->Read(vss_ptr->slot_idx,INDEX,&data,size,0,0);\
        result = data;\
      }\
      break;\
      }\
      \
      BIC_SIMPLE_SET_RES(c_bi_class_float,result);\
    }\
    break;\
    \
    case TSTRING:\
    {\
      char data[c_vs_max_str_size];\
      vs_ptr->Read(vss_ptr->slot_idx,INDEX,data,size,0,0);\
      \
      string_s *string_ptr = it.get_new_string_ptr();\
      string_ptr->set(data[0],data + 1);\
      \
      BIC_SET_RESULT_STRING(string_ptr);\
    }\
    break;\
    \
    /* - ERROR - */\
    default:\
      exception_s::throw_exception(it,module.error_base + c_error_VAR_SLOT_READ_UNKNOWN_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      return false;\
    }\
  }/*}}}*/

#define BIC_VAR_SLOT_READ_BLOCK_PROC_INTEGER(TYPE) \
  {/*{{{*/\
    TYPE *ptr = (TYPE *)buffer;\
    TYPE *ptr_end = ptr + count;\
    do {\
      long long int result = *ptr;\
      \
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_integer,result);\
      \
      array_ptr->push(new_location);\
    } while(++ptr < ptr_end);\
  }/*}}}*/

#define BIC_VAR_SLOT_READ_BLOCK_PROC_FLOAT(TYPE) \
  {/*{{{*/\
    TYPE *ptr = (TYPE *)buffer;\
    TYPE *ptr_end = ptr + count;\
    do {\
      double result = *ptr;\
      \
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_float,result);\
      \
      array_ptr->push(new_location);\
    } while(++ptr < ptr_end);\
  }/*}}}*/

#define BIC_VAR_SLOT_READ_BLOCK() \
  {/*{{{*/\
    int count = vssInfo.nVars;\
    int size = vssInfo.varSize;\
    \
    switch (vssInfo.varType)\
    {\
    case TBOOL:\
    case TSINT:\
    case TINT:\
    case TDINT:\
    case TLINT:\
    case TUSINT:\
    case TUINT:\
    case TUDINT:\
    case TULINT:\
    {\
      pointer_array_s *array_ptr = it.get_new_array_ptr();\
      \
      void *buffer = cmalloc(count*size);\
      vs_ptr->ReadBlock(vss_ptr->slot_idx,0,count,buffer,count*size,0,0);\
      \
      switch (vssInfo.varType)\
      {\
      case TBOOL:\
        BIC_VAR_SLOT_READ_BLOCK_PROC_INTEGER(unsigned char);\
        break;\
      case TSINT:\
        BIC_VAR_SLOT_READ_BLOCK_PROC_INTEGER(signed char);\
        break;\
      case TINT:\
        BIC_VAR_SLOT_READ_BLOCK_PROC_INTEGER(short);\
        break;\
      case TDINT:\
        BIC_VAR_SLOT_READ_BLOCK_PROC_INTEGER(int);\
        break;\
      case TLINT:\
        BIC_VAR_SLOT_READ_BLOCK_PROC_INTEGER(long long int);\
        break;\
      case TUSINT:\
        BIC_VAR_SLOT_READ_BLOCK_PROC_INTEGER(unsigned char);\
        break;\
      case TUINT:\
        BIC_VAR_SLOT_READ_BLOCK_PROC_INTEGER(unsigned short);\
        break;\
      case TUDINT:\
        BIC_VAR_SLOT_READ_BLOCK_PROC_INTEGER(unsigned);\
        break;\
      case TULINT:\
        BIC_VAR_SLOT_READ_BLOCK_PROC_INTEGER(long long unsigned);\
        break;\
      }\
      \
      cfree(buffer);\
      \
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);\
      BIC_SET_RESULT(new_location);\
    }\
    break;\
    \
    case TREAL:\
    case TLREAL:\
    {\
      pointer_array_s *array_ptr = it.get_new_array_ptr();\
      \
      void *buffer = cmalloc(count*size);\
      vs_ptr->ReadBlock(vss_ptr->slot_idx,0,count,buffer,count*size,0,0);\
      \
      switch (vssInfo.varType)\
      {\
      case TREAL:\
        BIC_VAR_SLOT_READ_BLOCK_PROC_FLOAT(float);\
        break;\
      case TLREAL:\
        BIC_VAR_SLOT_READ_BLOCK_PROC_FLOAT(double);\
        break;\
      }\
      \
      cfree(buffer);\
      \
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);\
      BIC_SET_RESULT(new_location);\
    }\
    break;\
    \
    case TSTRING:\
    {\
      pointer_array_s *array_ptr = it.get_new_array_ptr();\
      \
      char *buffer = (char *)cmalloc(count*size*sizeof(char));\
      vs_ptr->ReadBlock(vss_ptr->slot_idx,0,count,buffer,count*size*sizeof(char),0,0);\
      \
      char *ptr = buffer;\
      char *ptr_end = ptr + count*size;\
      do {\
        string_s *string_ptr = it.get_new_string_ptr();\
        string_ptr->set(ptr[0],ptr + 1);\
        \
        BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);\
        array_ptr->push(new_location);\
        \
      } while((ptr += size) < ptr_end);\
      \
      cfree(buffer);\
      \
      BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);\
      BIC_SET_RESULT(new_location);\
    }\
    break;\
    \
    /* - ERROR - */\
    default:\
      exception_s::throw_exception(it,module.error_base + c_error_VAR_SLOT_READ_UNKNOWN_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
      return false;\
    }\
  }/*}}}*/

#define BIC_VAR_SLOT_ITEM(NAME) \
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
    BIC_VAR_SLOT_CHECK_INDEX();\
    \
    BIC_VAR_SLOT_READ(index);\
    \
    return true;\
  }/*}}}*/

void bic_var_slot_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_var_slot_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (varstore_slot_s *)nullptr;
}/*}}}*/

void bic_var_slot_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  varstore_slot_s *vss_ptr = (varstore_slot_s *)location_ptr->v_data_ptr;

  // - if varstore slot exists -
  if (vss_ptr != nullptr)
  {
    it.release_location_ptr(vss_ptr->vs_ptr);
    cfree(vss_ptr);
  }
}/*}}}*/

bool bic_var_slot_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_var_slot_operator_binary_le_br_re_br(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_VAR_SLOT_ITEM("operator_binary_le_br_re_br#1");
}/*}}}*/

bool bic_var_slot_method_index_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve varstore slot, and varstore pointers -
  varstore_slot_s *vss_ptr = (varstore_slot_s *)dst_location->v_data_ptr;

  long long int result = vss_ptr->slot_idx;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_var_slot_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve varstore slot, and varstore pointers -
  varstore_slot_s *vss_ptr = (varstore_slot_s *)dst_location->v_data_ptr;
  VarStore *vs_ptr = (VarStore *)vss_ptr->vs_ptr->v_data_ptr;

  VarStore::SlotInfo vssInfo;
  vs_ptr->GetSlotInfo(vss_ptr->slot_idx,&vssInfo);

  // - copy varstore slot name to target string -
  string_s *string_ptr = it.get_new_string_ptr();

  unsigned name_length = c_vs_slot_info_name_size;
  string_ptr->create(name_length);

  memcpy(string_ptr->data,vssInfo.name,name_length);
  string_ptr->data[name_length] = '\0';
  string_ptr->size = strlen(string_ptr->data) + 1;

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_var_slot_method_varType_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve varstore slot, and varstore pointers -
  varstore_slot_s *vss_ptr = (varstore_slot_s *)dst_location->v_data_ptr;
  VarStore *vs_ptr = (VarStore *)vss_ptr->vs_ptr->v_data_ptr;

  VarStore::SlotInfo vssInfo;
  vs_ptr->GetSlotInfo(vss_ptr->slot_idx,&vssInfo);

  // - retrieve varstore slot variable type -
  long long int result = vssInfo.varType;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_var_slot_method_varSize_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve varstore slot, and varstore pointers -
  varstore_slot_s *vss_ptr = (varstore_slot_s *)dst_location->v_data_ptr;
  VarStore *vs_ptr = (VarStore *)vss_ptr->vs_ptr->v_data_ptr;

  VarStore::SlotInfo vssInfo;
  vs_ptr->GetSlotInfo(vss_ptr->slot_idx,&vssInfo);

  // - retrieve varstore slot variable size -
  long long int result = vssInfo.varSize;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_var_slot_method_clear_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve varstore slot, and varstore pointers -
  varstore_slot_s *vss_ptr = (varstore_slot_s *)dst_location->v_data_ptr;
  VarStore *vs_ptr = (VarStore *)vss_ptr->vs_ptr->v_data_ptr;

  VarStore::SlotInfo vssInfo;
  vs_ptr->GetSlotInfo(vss_ptr->slot_idx,&vssInfo);

  if (vssInfo.nVars >= 1)
  {
    int idx = 0;
    do {
      vs_ptr->Write(vss_ptr->slot_idx,idx,c_zeroes,vssInfo.varSize,0,0,false);
    } while(++idx < vssInfo.nVars);
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_var_slot_method_write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - retrieve varstore slot, and varstore pointers -
  varstore_slot_s *vss_ptr = (varstore_slot_s *)dst_location->v_data_ptr;
  VarStore *vs_ptr = (VarStore *)vss_ptr->vs_ptr->v_data_ptr;

  VarStore::SlotInfo vssInfo;
  vs_ptr->GetSlotInfo(vss_ptr->slot_idx,&vssInfo);

  if (vssInfo.nVars == 1)
  {
    BIC_VAR_SLOT_WRITE(0,src_0_location);
  }
  else
  {
    BIC_VAR_SLOT_WRITE_BLOCK(src_0_location);
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_var_slot_method_write_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int index;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,index))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("write#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  BIC_VAR_SLOT_CHECK_INDEX();

  BIC_VAR_SLOT_WRITE(index,src_1_location);

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_var_slot_method_read_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve varstore slot, and varstore pointers -
  varstore_slot_s *vss_ptr = (varstore_slot_s *)dst_location->v_data_ptr;
  VarStore *vs_ptr = (VarStore *)vss_ptr->vs_ptr->v_data_ptr;

  VarStore::SlotInfo vssInfo;
  vs_ptr->GetSlotInfo(vss_ptr->slot_idx,&vssInfo);

  if (vssInfo.nVars == 1)
  {
    BIC_VAR_SLOT_READ(0);
  }
  else
  {
    BIC_VAR_SLOT_READ_BLOCK();
  }

  return true;
}/*}}}*/

bool bic_var_slot_method_read_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_VAR_SLOT_ITEM("read#1");
}/*}}}*/

bool bic_var_slot_method_item_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_VAR_SLOT_ITEM("item#1");
}/*}}}*/

bool bic_var_slot_method_first_idx_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  varstore_slot_s *vss_ptr = (varstore_slot_s *)dst_location->v_data_ptr;
  VarStore *vs_ptr = (VarStore *)vss_ptr->vs_ptr->v_data_ptr;

  VarStore::SlotInfo vssInfo;
  vs_ptr->GetSlotInfo(vss_ptr->slot_idx,&vssInfo);

  if (vssInfo.nVars > 0)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,0);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_var_slot_method_next_idx_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
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

  BIC_VAR_SLOT_CHECK_INDEX();

  if (++index < vssInfo.nVars)
  {
    BIC_SIMPLE_SET_RES(c_bi_class_integer,index);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_var_slot_method_length_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  varstore_slot_s *vss_ptr = (varstore_slot_s *)dst_location->v_data_ptr;
  VarStore *vs_ptr = (VarStore *)vss_ptr->vs_ptr->v_data_ptr;

  VarStore::SlotInfo vssInfo;
  vs_ptr->GetSlotInfo(vss_ptr->slot_idx,&vssInfo);

  long long int result = vssInfo.nVars;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_var_slot_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("VarSlot"),"VarSlot")
  );

  return true;
}/*}}}*/

bool bic_var_slot_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("VarSlot");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class NVM_SEGMENT -
built_in_class_s nvm_segment_class =
{/*{{{*/
  "NvmSegment",
  c_modifier_public | c_modifier_final,
  9, nvm_segment_methods,
  0, nvm_segment_variables,
  bic_nvm_segment_consts,
  bic_nvm_segment_init,
  bic_nvm_segment_clear,
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

built_in_method_s nvm_segment_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_nvm_segment_operator_binary_equal
  },
  {
    "NvmSegment#1",
    c_modifier_public | c_modifier_final,
    bic_nvm_segment_method_NvmSegment_1
  },
  {
    "NvmSegment#2",
    c_modifier_public | c_modifier_final,
    bic_nvm_segment_method_NvmSegment_2
  },
  {
    "size#0",
    c_modifier_public | c_modifier_final,
    bic_nvm_segment_method_size_0
  },
  {
    "name#0",
    c_modifier_public | c_modifier_final,
    bic_nvm_segment_method_name_0
  },
  {
    "write#2",
    c_modifier_public | c_modifier_final,
    bic_nvm_segment_method_write_2
  },
  {
    "read#2",
    c_modifier_public | c_modifier_final,
    bic_nvm_segment_method_read_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_nvm_segment_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_nvm_segment_method_print_0
  },
};/*}}}*/

built_in_variable_s nvm_segment_variables[] =
{/*{{{*/
};/*}}}*/

void bic_nvm_segment_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_nvm_segment_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (nvm_segment_s *)nullptr;
}/*}}}*/

void bic_nvm_segment_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  nvm_segment_s *ns_ptr = (nvm_segment_s *)location_ptr->v_data_ptr;

  // - if varstore slot exists -
  if (ns_ptr != nullptr)
  {
    if (ns_ptr->ram_ptr != nullptr)
    {
      cfree(ns_ptr->ram_ptr);
    }

    delete ns_ptr->ns_ptr;
    cfree(ns_ptr);
  }
}/*}}}*/

bool bic_nvm_segment_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_nvm_segment_method_NvmSegment_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("NvmSegment#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve segment name -
  string_s *ns_name_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create new segment -
  nvm_segment_s *ns_ptr = (nvm_segment_s *)cmalloc(sizeof(nvm_segment_s));
  ns_ptr->ns_ptr = new NvmSegment();
  ns_ptr->ram_ptr = nullptr;

  try
  {
    ns_ptr->ns_ptr->Open(String(ns_name_ptr->data));
  }
  catch (Exception e)
  {
    delete ns_ptr->ns_ptr;
    cfree(ns_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_NVM_SEGMENT_OPEN_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  // - set destination data pointer -
  dst_location->v_data_ptr = (nvm_segment_s *)ns_ptr;

  return true;
}/*}}}*/

bool bic_nvm_segment_method_NvmSegment_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int size;

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string ||
      !it.retrieve_integer(src_1_location,size))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("NvmSegment#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  // - retrieve segment name -
  string_s *ns_name_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (size <= 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_NVM_SEGMENT_CREATE_NEGATIVE_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - create new segment object -
  nvm_segment_s *ns_ptr = (nvm_segment_s *)cmalloc(sizeof(nvm_segment_s));
  ns_ptr->ns_ptr = new NvmSegment();
  ns_ptr->ram_ptr = cmalloc(size*sizeof(char));

  try
  {
    ns_ptr->ns_ptr->Create(String(ns_name_ptr->data),ns_ptr->ram_ptr,size);
  }
  catch (Exception e)
  {
    cfree(ns_ptr->ram_ptr);
    delete ns_ptr->ns_ptr;
    cfree(ns_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_NVM_SEGMENT_OPEN_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  // - set destination data pointer -
  dst_location->v_data_ptr = (nvm_segment_s *)ns_ptr;

  return true;
}/*}}}*/

bool bic_nvm_segment_method_size_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve segment pointer -
  nvm_segment_s *ns_ptr = (nvm_segment_s *)dst_location->v_data_ptr;

  long long int result = ns_ptr->ns_ptr->Size();
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_nvm_segment_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve segment pointer -
  nvm_segment_s *ns_ptr = (nvm_segment_s *)dst_location->v_data_ptr;

  String name = ns_ptr->ns_ptr->Name();

  // - create new string from name string -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(name.Length(),name.Mem());

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_nvm_segment_method_write_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int pos;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,pos) ||
      src_1_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("write#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  // - retrieve segment pointer -
  nvm_segment_s *ns_ptr = (nvm_segment_s *)dst_location->v_data_ptr;

  string_s *string_ptr = (string_s *)src_1_location->v_data_ptr;

  // - ERROR -
  if (pos < 0 || pos + string_ptr->size - 1 > (long long int)ns_ptr->ns_ptr->Size())
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_NVM_SEGMENT_INVALID_DATA_POS_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(pos);
    new_exception->params.push(string_ptr->size);

    return false;
  }

  try
  {
    ns_ptr->ns_ptr->Write(pos,string_ptr->data,string_ptr->size - 1);
  }

  // - ERROR -
  catch (Exception e)
  {
    exception_s::throw_exception(it,module.error_base + c_error_NVM_SEGMENT_WRITE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_nvm_segment_method_read_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int pos;
  long long int size;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,pos) ||
      !it.retrieve_integer(src_1_location,size))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("read#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  // - retrieve segment pointer -
  nvm_segment_s *ns_ptr = (nvm_segment_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (pos < 0 || size < 0 || pos + size > (long long int)ns_ptr->ns_ptr->Size())
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_NVM_SEGMENT_INVALID_DATA_POS_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(pos);
    new_exception->params.push(size);

    return false;
  }

  // - create target string -
  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->create(size);

  try
  {
    ns_ptr->ns_ptr->Read(pos,string_ptr->data,size);
  }

  // - ERROR -
  catch (Exception e)
  {
    string_ptr->clear();
    cfree(string_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_NVM_SEGMENT_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_nvm_segment_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("NvmSegment"),"NvmSegment")
  );

  return true;
}/*}}}*/

bool bic_nvm_segment_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("NvmSegment");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class MSG_QUEUE -
built_in_class_s msg_queue_class =
{/*{{{*/
  "MsgQueue",
  c_modifier_public | c_modifier_final,
  10, msg_queue_methods,
  0, msg_queue_variables,
  bic_msg_queue_consts,
  bic_msg_queue_init,
  bic_msg_queue_clear,
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

built_in_method_s msg_queue_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_msg_queue_operator_binary_equal
  },
  {
    "MsgQueue#1",
    c_modifier_public | c_modifier_final,
    bic_msg_queue_method_MsgQueue_1
  },
  {
    "MsgQueue#3",
    c_modifier_public | c_modifier_final,
    bic_msg_queue_method_MsgQueue_3
  },
  {
    "name#0",
    c_modifier_public | c_modifier_final,
    bic_msg_queue_method_name_0
  },
  {
    "write#1",
    c_modifier_public | c_modifier_final,
    bic_msg_queue_method_write_1
  },
  {
    "read#0",
    c_modifier_public | c_modifier_final,
    bic_msg_queue_method_read_0
  },
  {
    "read_pid#0",
    c_modifier_public | c_modifier_final,
    bic_msg_queue_method_read_pid_0
  },
  {
    "peek_msg#0",
    c_modifier_public | c_modifier_final,
    bic_msg_queue_method_peek_msg_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_msg_queue_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_msg_queue_method_print_0
  },
};/*}}}*/

built_in_variable_s msg_queue_variables[] =
{/*{{{*/
};/*}}}*/

void bic_msg_queue_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_msg_queue_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (MsgQueue *)nullptr;
}/*}}}*/

void bic_msg_queue_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  MsgQueue *mq_ptr = (MsgQueue *)location_ptr->v_data_ptr;

  if (mq_ptr != nullptr)
  {
    delete mq_ptr;
  }
}/*}}}*/

bool bic_msg_queue_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_msg_queue_method_MsgQueue_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("MsgQueue#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create message queue object -
  MsgQueue *mq_ptr = new MsgQueue();

  try
  {
    mq_ptr->Open(String(string_ptr->data));
  }

  // - ERROR -
  catch (Exception e)
  {
    delete mq_ptr;

    exception_s::throw_exception(it,module.error_base + c_error_MSG_QUEUE_OPEN_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  dst_location->v_data_ptr = (MsgQueue *)mq_ptr;

  return true;
}/*}}}*/

bool bic_msg_queue_method_MsgQueue_3(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);

  long long int buffer_size;
  long long int max_msg_count;

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string ||
      !it.retrieve_integer(src_1_location,buffer_size) ||
      !it.retrieve_integer(src_2_location,max_msg_count))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("MsgQueue#3");
    new_exception->params.push(3);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);

    return false;
  }

  // - ERROR -
  if (buffer_size <= 0)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_MSG_QUEUE_INVALID_BUFFER_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(buffer_size);

    return false;
  }

  // - ERROR -
  if (max_msg_count <= 0)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_MSG_QUEUE_INVALID_MAX_MESSAGE_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(max_msg_count);

    return false;
  }

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create message queue object -
  MsgQueue *mq_ptr = new MsgQueue();

  try
  {
    mq_ptr->Create(String(string_ptr->data),buffer_size,max_msg_count);
  }

  // - ERROR -
  catch (Exception e)
  {
    delete mq_ptr;

    exception_s::throw_exception(it,module.error_base + c_error_MSG_QUEUE_CREATE_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  dst_location->v_data_ptr = (MsgQueue *)mq_ptr;

  return true;
}/*}}}*/

bool bic_msg_queue_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  MsgQueue *mq_ptr = (MsgQueue *)dst_location->v_data_ptr;

  // - retrieve message queue name -
  String name = mq_ptr->Name();

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(name.Length(),name.Mem());

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_msg_queue_method_write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("write#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  MsgQueue *mq_ptr = (MsgQueue *)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (mq_ptr->Write(string_ptr->data,string_ptr->size - 1) == 0)
  {
    exception_s::throw_exception(it,module.error_base + c_error_MSG_QUEUE_WRITE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_msg_queue_method_read_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  MsgQueue *mq_ptr = (MsgQueue *)dst_location->v_data_ptr;

  int msg_size = mq_ptr->PeekMsg();
  if (msg_size > 0)
  {
    string_s *string_ptr = it.get_new_string_ptr();
    string_ptr->create(msg_size);

    // - ERROR -
    if (mq_ptr->Read(string_ptr->data,msg_size) != msg_size)
    {
      string_ptr->clear();
      cfree(string_ptr);

      exception_s::throw_exception(it,module.error_base + c_error_MSG_QUEUE_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    BIC_SET_RESULT_STRING(string_ptr);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_msg_queue_method_read_pid_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  MsgQueue *mq_ptr = (MsgQueue *)dst_location->v_data_ptr;

  int msg_size = mq_ptr->PeekMsg();
  if (msg_size > 0)
  {
    string_s *string_ptr = it.get_new_string_ptr();
    string_ptr->create(msg_size);

    unsigned pid;

    // - ERROR -
    if (mq_ptr->Read(string_ptr->data,msg_size,&pid) != msg_size)
    {
      string_ptr->clear();
      cfree(string_ptr);

      exception_s::throw_exception(it,module.error_base + c_error_MSG_QUEUE_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    pointer_array_s *array_ptr = it.get_new_array_ptr();
    array_ptr->copy_resize(2);

    BIC_CREATE_NEW_LOCATION(str_location,c_bi_class_string,string_ptr);
    array_ptr->push(str_location);

    BIC_CREATE_NEW_LOCATION(pid_location,c_bi_class_integer,pid);
    array_ptr->push(pid_location);

    BIC_CREATE_NEW_LOCATION(arr_location,c_bi_class_array,array_ptr);
    BIC_SET_RESULT(arr_location);
  }
  else
  {
    BIC_SET_RESULT_BLANK();
  }

  return true;
}/*}}}*/

bool bic_msg_queue_method_peek_msg_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((MsgQueue *)dst_location->v_data_ptr)->PeekMsg();

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_msg_queue_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("MsgQueue"),"MsgQueue")
  );

  return true;
}/*}}}*/

bool bic_msg_queue_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("MsgQueue");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class BCC -
built_in_class_s bcc_class =
{/*{{{*/
  "Bcc",
  c_modifier_public | c_modifier_final,
  6, bcc_methods,
  0, bcc_variables,
  bic_bcc_consts,
  bic_bcc_init,
  bic_bcc_clear,
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

built_in_method_s bcc_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_bcc_operator_binary_equal
  },
  {
    "Bcc#0",
    c_modifier_public | c_modifier_final,
    bic_bcc_method_Bcc_0
  },
  {
    "append#1",
    c_modifier_public | c_modifier_final,
    bic_bcc_method_append_1
  },
  {
    "value#0",
    c_modifier_public | c_modifier_final,
    bic_bcc_method_value_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_bcc_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_bcc_method_print_0
  },
};/*}}}*/

built_in_variable_s bcc_variables[] =
{/*{{{*/
};/*}}}*/

void bic_bcc_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_bcc_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

void bic_bcc_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

bool bic_bcc_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_bcc_method_Bcc_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - set bcc value to zero -
  dst_location->v_data_ptr = (long long int)0;

  return true;
}/*}}}*/

bool bic_bcc_method_append_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("append#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve bcc value -
  unsigned char value = (long long int)dst_location->v_data_ptr;

  // - retrieve source string -
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  if (string_ptr->size > 1)
  {
    unsigned char *b_ptr = (unsigned char *)string_ptr->data;
    unsigned char *b_ptr_end = b_ptr + string_ptr->size - 1;

    do {
      value ^= *b_ptr;
    } while(++b_ptr < b_ptr_end);
  }

  // - set bcc value -
  dst_location->v_data_ptr = (long long int)value;

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_bcc_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve bcc value -
  long long int result = (long long int)dst_location->v_data_ptr;
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_bcc_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Bcc"),"Bcc")
  );

  return true;
}/*}}}*/

bool bic_bcc_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("Bcc");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class CRC -
built_in_class_s crc_class =
{/*{{{*/
  "Crc",
  c_modifier_public | c_modifier_final,
  7, crc_methods,
  3, crc_variables,
  bic_crc_consts,
  bic_crc_init,
  bic_crc_clear,
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

built_in_method_s crc_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_crc_operator_binary_equal
  },
  {
    "Crc#2",
    c_modifier_public | c_modifier_final,
    bic_crc_method_Crc_2
  },
  {
    "append#1",
    c_modifier_public | c_modifier_final,
    bic_crc_method_append_1
  },
  {
    "size#0",
    c_modifier_public | c_modifier_final,
    bic_crc_method_size_0
  },
  {
    "value#0",
    c_modifier_public | c_modifier_final,
    bic_crc_method_value_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_crc_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_crc_method_print_0
  },
};/*}}}*/

built_in_variable_s crc_variables[] =
{/*{{{*/
  {
    "CRC8",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "CRC16",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
  {
    "CRC32",
    c_modifier_public | c_modifier_static | c_modifier_static_const
  },
};/*}}}*/

void bic_crc_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert crc constants -
  {
    const_locations.push_blanks(3);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 3);

#define CREATE_CRC_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_CRC_BIC_STATIC(CRC_SIZE_8);
    CREATE_CRC_BIC_STATIC(CRC_SIZE_16);
    CREATE_CRC_BIC_STATIC(CRC_SIZE_32);
  }
}/*}}}*/

void bic_crc_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (crc_s *)nullptr;
}/*}}}*/

void bic_crc_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  crc_s *crc_ptr = (crc_s *)location_ptr->v_data_ptr;

  // - if crc pointer exist -
  if (crc_ptr != nullptr)
  {
    cfree(crc_ptr);
  }
}/*}}}*/

bool bic_crc_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_crc_method_Crc_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int size;
  long long int value;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,size) ||
      !it.retrieve_integer(src_1_location,value))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("Crc#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  switch (size)
  {
  case CRC_SIZE_8:

    // - ERROR -
    if (value < 0 || value > UCHAR_MAX)
    {
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_CRC_WRONG_INITIAL_VALUE_ACCORDING_TO_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(value);
      new_exception->params.push(size);

      return false;
    }
    break;
  case CRC_SIZE_16:

    // - ERROR -
    if (value < 0 || value > USHRT_MAX)
    {
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_CRC_WRONG_INITIAL_VALUE_ACCORDING_TO_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(value);
      new_exception->params.push(size);

      return false;
    }
    break;
  case CRC_SIZE_32:

    // - ERROR -
    if (value < 0 || value > UINT_MAX)
    {
      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_CRC_WRONG_INITIAL_VALUE_ACCORDING_TO_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(value);
      new_exception->params.push(size);

      return false;
    }
    break;

    // - ERROR -
  default:
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_CRC_UNKNOWN_REQUESTED_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(size);

    return false;
  }

  // - create new crc pointer -
  crc_s *crc_ptr = (crc_s *)cmalloc(sizeof(crc_s));
  crc_ptr->size = size;
  crc_ptr->value = value;

  dst_location->v_data_ptr = (crc_s *)crc_ptr;

  return true;
}/*}}}*/

bool bic_crc_method_append_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("append#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve crc pointer -
  crc_s *crc_ptr = (crc_s *)dst_location->v_data_ptr;

  // - retrieve string pointer -
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  switch (crc_ptr->size)
  {
  case CRC_SIZE_8:
  {
    unsigned char value = crc_ptr->value;
    Crc8(&value,string_ptr->data,string_ptr->size - 1);
    crc_ptr->value = value;
  }
  break;
  case CRC_SIZE_16:
  {
    unsigned short value = crc_ptr->value;
    Crc16(&value,string_ptr->data,string_ptr->size - 1);
    crc_ptr->value = value;
  }
  break;
  case CRC_SIZE_32:
  {
    unsigned value = crc_ptr->value;
    Crc32(&value,string_ptr->data,string_ptr->size - 1);
    crc_ptr->value = value;
  }
  break;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_crc_method_size_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve crc pointer -
  crc_s *crc_ptr = (crc_s *)dst_location->v_data_ptr;

  long long int result = crc_ptr->size;
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_crc_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve crc pointer -
  crc_s *crc_ptr = (crc_s *)dst_location->v_data_ptr;

  long long int result = crc_ptr->value;
  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_crc_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Crc"),"Crc")
  );

  return true;
}/*}}}*/

bool bic_crc_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("Crc");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class MD5 -
built_in_class_s md5_class =
{/*{{{*/
  "Md5",
  c_modifier_public | c_modifier_final,
  7, md5_methods,
  0, md5_variables,
  bic_md5_consts,
  bic_md5_init,
  bic_md5_clear,
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

built_in_method_s md5_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_md5_operator_binary_equal
  },
  {
    "Md5#0",
    c_modifier_public | c_modifier_final,
    bic_md5_method_Md5_0
  },
  {
    "append#1",
    c_modifier_public | c_modifier_final,
    bic_md5_method_append_1
  },
  {
    "value#0",
    c_modifier_public | c_modifier_final,
    bic_md5_method_value_0
  },
  {
    "string#0",
    c_modifier_public | c_modifier_final,
    bic_md5_method_string_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_md5_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_md5_method_print_0
  },
};/*}}}*/

built_in_variable_s md5_variables[] =
{/*{{{*/
};/*}}}*/

void bic_md5_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_md5_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (MD5Digest *)nullptr;
}/*}}}*/

void bic_md5_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  MD5Digest *md5_ptr = (MD5Digest *)location_ptr->v_data_ptr;

  // - if md5 pointer exist -
  if (md5_ptr != nullptr)
  {
    delete md5_ptr;
  }
}/*}}}*/

bool bic_md5_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_md5_method_Md5_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - create new md5 pointer -
  MD5Digest *md5_ptr = new MD5Digest();

  dst_location->v_data_ptr = (MD5Digest *)md5_ptr;

  return true;
}/*}}}*/

bool bic_md5_method_append_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("append#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - retrieve crc pointer -
  MD5Digest *md5_ptr = (MD5Digest *)dst_location->v_data_ptr;

  // - retrieve string pointer -
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - if there are any data to append -
  if (string_ptr->size > 1)
  {
    md5_ptr->Append(string_ptr->data,string_ptr->size - 1);
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_md5_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve crc pointer -
  MD5Digest *md5_ptr = (MD5Digest *)dst_location->v_data_ptr;

  MD5Digest md5_copy;
  memcpy(&md5_copy,md5_ptr,sizeof(MD5Digest));

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->create(16);

  // - retrieve digest from md5 -
  md5_copy.Finish((unsigned char *)string_ptr->data);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_md5_method_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve crc pointer -
  MD5Digest *md5_ptr = (MD5Digest *)dst_location->v_data_ptr;

  MD5Digest md5_copy;
  memcpy(&md5_copy,md5_ptr,sizeof(MD5Digest));

  // - retrieve digest from md5 -
  unsigned char buffer[16];
  md5_copy.Finish(buffer);

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->create(32);

  // - convert bytes to string -
  unsigned char *b_ptr = buffer;
  unsigned char *b_ptr_end = b_ptr + 16;
  char *s_ptr = string_ptr->data;

  do {
    unsigned char byte = *b_ptr;

    // - convert first four bits -
    char value = (byte & 0xf0) >> 4;
    *s_ptr++ = value < 10 ? '0' + value : 'a' + (value - 10);

    // - convert last four bits -
    value = byte & 0xf;
    *s_ptr++ = value < 10 ? '0' + value : 'a' + (value - 10);

  } while(++b_ptr < b_ptr_end);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_md5_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Md5"),"Md5")
  );

  return true;
}/*}}}*/

bool bic_md5_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("Md5");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

