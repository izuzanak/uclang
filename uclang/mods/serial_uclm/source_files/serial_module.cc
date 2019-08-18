
@begin
include "serial_module.h"
@end

// - SERIAL indexes of built in classes -
unsigned c_bi_class_serial = c_idx_not_exist;

// - SERIAL module -
EXPORT built_in_module_s module =
{/*{{{*/
  1,                      // Class count
  serial_classes,         // Classes
  0,                      // Error base index
  4,                      // Error count
  serial_error_strings,   // Error strings
  serial_initialize,      // Initialize function
  serial_print_exception, // Print exceptions function
};/*}}}*/

// - SERIAL classes -
built_in_class_s *serial_classes[] =
{/*{{{*/
  &serial_class,
};/*}}}*/

// - SERIAL error strings -
const char *serial_error_strings[] =
{/*{{{*/
  "error_SERIAL_OPEN_ERROR",
  "error_SERIAL_SETUP_ERROR",
  "error_SERIAL_WRITE_ERROR",
  "error_SERIAL_READ_ERROR",
};/*}}}*/

// - SERIAL initialize -
bool serial_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize serial class identifier -
  c_bi_class_serial = class_base_idx++;

  return true;
}/*}}}*/

// - SERIAL print exception -
bool serial_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_SERIAL_OPEN_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot open serial device \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SERIAL_SETUP_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot setup serial device\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SERIAL_WRITE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while writing to serial device\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_SERIAL_READ_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while reading from serial device\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class SERIAL -
built_in_class_s serial_class =
{/*{{{*/
  "Serial",
  c_modifier_public | c_modifier_final,
  8, serial_methods,
  3 + 3, serial_variables,
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
    "set_format#5",
    c_modifier_public | c_modifier_final,
    bic_serial_method_set_format_5
  },
  {
    "write#1",
    c_modifier_public | c_modifier_final,
    bic_serial_method_write_1
  },
  {
    "read#0",
    c_modifier_public | c_modifier_final,
    bic_serial_method_read_0
  },
  {
    "get_fd#0",
    c_modifier_public | c_modifier_final,
    bic_serial_method_get_fd_0
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

  // - serial flow control constants -
  { "FC_NONE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FC_RTS_CTS", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "FC_RS_485", c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - serial parity constants -
  { "PARITY_NONE", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PARITY_EVEN", c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "PARITY_ODD", c_modifier_public | c_modifier_static | c_modifier_static_const },
};/*}}}*/

void bic_serial_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert serial flow control constants -
  {
    const_locations.push_blanks(3);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 3);

#define CREATE_SERIAL_FLOW_CONTROL_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_SERIAL_FLOW_CONTROL_BIC_STATIC(c_serial_FC_NONE);
    CREATE_SERIAL_FLOW_CONTROL_BIC_STATIC(c_serial_FC_RTS_CTS);
    CREATE_SERIAL_FLOW_CONTROL_BIC_STATIC(c_serial_FC_RS_485);
  }

  // - insert serial parity constants -
  {
    const_locations.push_blanks(3);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 3);

#define CREATE_SERIAL_PARITY_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_SERIAL_PARITY_BIC_STATIC(c_serial_PARITY_NONE);
    CREATE_SERIAL_PARITY_BIC_STATIC(c_serial_PARITY_EVEN);
    CREATE_SERIAL_PARITY_BIC_STATIC(c_serial_PARITY_ODD);
  }

}/*}}}*/

void bic_serial_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (serial_s *)nullptr;
}/*}}}*/

void bic_serial_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  serial_s *serial_ptr = (serial_s *)location_ptr->v_data_ptr;

  if (serial_ptr != nullptr)
  {
    serial_ptr->clear(it);
    cfree(serial_ptr);
  }
}/*}}}*/

bool bic_serial_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_serial_method_Serial_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
path:c_bi_class_string
>
method Serial
; @end

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - open serial device -
  int fd = open(string_ptr->data,O_RDWR | O_NOCTTY | O_CLOEXEC);

  // - ERROR -
  if (fd == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SERIAL_OPEN_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  // - create serial object -
  serial_s *serial_ptr = (serial_s *)cmalloc(sizeof(serial_s));
  serial_ptr->init();

  // - set serial pointer fd -
  serial_ptr->fd = fd;

  // - set destination data pointer -
  dst_location->v_data_ptr = (serial_s *)serial_ptr;

  return true;
}/*}}}*/

bool bic_serial_method_set_format_5(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
baudrate:retrieve_integer
flow:retrieve_integer
parity:retrieve_integer
data:retrieve_integer
stop:retrieve_integer
>
method set_format
; @end

  serial_s *serial_ptr = (serial_s *)dst_location->v_data_ptr;
  termios termio;

  // - ERROR -
  if (tcgetattr(serial_ptr->fd,&termio) == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SERIAL_SETUP_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  switch (baudrate)
  {
  case   1200: cfsetspeed(&termio,  B1200); break;
  case   2400: cfsetspeed(&termio,  B2400); break;
  case   4800: cfsetspeed(&termio,  B4800); break;
  case   9600: cfsetspeed(&termio,  B9600); break;
  case  19200: cfsetspeed(&termio, B19200); break;
  case  38400: cfsetspeed(&termio, B38400); break;
  case  57600: cfsetspeed(&termio, B57600); break;
  case 115200: cfsetspeed(&termio,B115200); break;
  case 230400: cfsetspeed(&termio,B230400); break;

  // - ERROR -
  default:
    
    exception_s::throw_exception(it,module.error_base + c_error_SERIAL_SETUP_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  switch (flow)
  {
  case c_serial_FC_NONE:
      termio.c_cflag &= ~CRTSCTS;
      termio.c_cflag &= ~CRS485;
      termio.c_iflag &= ~(IXON | IXOFF | IXANY);
      break;
  case c_serial_FC_RTS_CTS:
      termio.c_cflag |=  CRTSCTS;
      termio.c_cflag &= ~CRS485;
      termio.c_iflag &= ~(IXON | IXOFF | IXANY);
      break;
  case c_serial_FC_RS_485:
      termio.c_cflag &= ~CRTSCTS;
      termio.c_cflag |=  CRS485;
      termio.c_iflag &= ~(IXON | IXOFF | IXANY);
      break;

  // - ERROR -
  default:

    exception_s::throw_exception(it,module.error_base + c_error_SERIAL_SETUP_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  switch (parity)
  {
  case c_serial_PARITY_NONE:
      termio.c_cflag &= ~PARENB;
      termio.c_iflag &= ~INPCK;
      break;
  case c_serial_PARITY_EVEN:
      termio.c_cflag |= PARENB;
      termio.c_cflag &= ~PARODD;
      termio.c_iflag |= INPCK;
      break;
  case c_serial_PARITY_ODD:
      termio.c_cflag |= PARENB;
      termio.c_cflag |= PARODD;
      termio.c_iflag |= INPCK;
      break;

  // - ERROR -
  default:

    exception_s::throw_exception(it,module.error_base + c_error_SERIAL_SETUP_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  switch (data)
  {
  case 8:
      termio.c_cflag &= ~CSIZE;
      termio.c_cflag |= CS8;
      break;
  case 7:
      termio.c_cflag &= ~CSIZE;
      termio.c_cflag |= CS7;
      break;
  case 6:
      termio.c_cflag &= ~CSIZE;
      termio.c_cflag |= CS6;
      break;
  case 5:
      termio.c_cflag &= ~CSIZE;
      termio.c_cflag |= CS5;
      break;

  // - ERROR -
  default:

    exception_s::throw_exception(it,module.error_base + c_error_SERIAL_SETUP_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  switch (stop)
  {
  case 1:
      termio.c_cflag &= ~CSTOPB;
      break;
  case 2:
      termio.c_cflag |= CSTOPB;
      break;

  // - ERROR -
  default:

    exception_s::throw_exception(it,module.error_base + c_error_SERIAL_SETUP_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - input flags -
  termio.c_iflag &= ~(
      IGNBRK              // do not ignore break conditions on input
      | BRKINT            // do not send SIGINT in case of break condition
      | IGNPAR            // do not ignore framing and parity errors
      | PARMRK            // do not prefix characters with parity error
      | ISTRIP            // do not strip-off eighth bit
      | INLCR             // do not translate NL to CR on input
      | IGNCR             // do not ignore CR on input
      | ICRNL             // do not translate CR to NL on input
      | IUCLC             // do not map uppercase chars to lowercase
      | IMAXBEL);         // do not ring bell when input queue is full

  // - output flags -
  termio.c_oflag &= ~(
      OPOST               // do not enable output processing
      | OLCUC             // do not translate lowercase chars to uppercase
      | ONLCR             // do not translate NL to NL-CR on output
      | OCRNL             // do not translate CR to NL on output
      | ONOCR             // allow to output CR at column 0
      | ONLRET);          // do not suppress CR output

  // - control flags -
  termio.c_cflag |=
      CREAD               // enable receiver
      | CLOCAL;           // ignore modem control lines

  // - local flags -
  termio.c_lflag &= ~(
      ISIG                // do not generate signals
      | ICANON            // disable canonical mode
      | ECHO              // do not echo input characters
      | ECHOE             // do not use erase character
      | ECHOK             // do not use kill character
      | ECHONL            // do not echo NL character
      | ECHOCTL           // do not echo control signals as ^X
      | ECHOPRT           // do not print erased characters
      | ECHOKE            // do not echo kill as erase chars
      | NOFLSH            // do not disable flushing queues
      | TOSTOP            // do not send SIGTTOU signal
      | IEXTEN);          // disable input processing

  termio.c_cc[VMIN] = 0;  // minimum number of characters to wait for
  termio.c_cc[VTIME] = 0; // timeout in deciseconds

  // - ERROR -
  if (tcsetattr(serial_ptr->fd,TCSANOW,&termio) == -1)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SERIAL_SETUP_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_serial_method_write_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
data:retrieve_data_buffer
>
method write
; @end

  serial_s *serial_ptr = (serial_s *)dst_location->v_data_ptr;

  // - ERROR -
  if (write(serial_ptr->fd,data_ptr,data_size) != (ssize_t)data_size)
  {
    exception_s::throw_exception(it,module.error_base + c_error_SERIAL_WRITE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_serial_method_read_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  serial_s *serial_ptr = (serial_s *)dst_location->v_data_ptr;

  const long int c_buffer_add = 1024;

  // - target data buffer -
  bc_array_s data_buffer;
  data_buffer.init();

  int inq_cnt;
  long int read_cnt;
  do
  {
    data_buffer.reserve(c_buffer_add);
    read_cnt = read(serial_ptr->fd,data_buffer.data + data_buffer.used,c_buffer_add);

    // - ERROR -
    if (read_cnt == -1)
    {
      data_buffer.clear();

      exception_s::throw_exception(it,module.error_base + c_error_SERIAL_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    data_buffer.used += read_cnt;

    // - ERROR -
    if (ioctl(serial_ptr->fd,TIOCINQ,&inq_cnt) == -1)
    {
      data_buffer.clear();

      exception_s::throw_exception(it,module.error_base + c_error_SERIAL_READ_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }
  }
  while(inq_cnt > 0);

  // - was any data read -
  if (data_buffer.used == 0)
  {
    data_buffer.clear();

    BIC_SET_RESULT_BLANK();
  }
  else
  {
    data_buffer.push('\0');

    // - return data string -
    string_s *string_ptr = it.get_new_string_ptr();
    string_ptr->data = data_buffer.data;
    string_ptr->size = data_buffer.used;

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
    BIC_SET_RESULT(new_location);
  }

  return true;
}/*}}}*/

bool bic_serial_method_get_fd_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int result = ((serial_s *)dst_location->v_data_ptr)->fd;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

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
  printf("Serial");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

