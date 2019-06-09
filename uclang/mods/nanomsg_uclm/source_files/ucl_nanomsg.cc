
@begin
include "ucl_nanomsg.h"
@end

/*
 * methods of structure nano_msg_s
 */

unsigned nano_msg_s::option_type(int a_level,int a_option)
{/*{{{*/
  switch (a_level)
  {
  case NN_SOL_SOCKET:
    {/*{{{*/
      switch (a_option)
      {
      case NN_DOMAIN:
      case NN_PROTOCOL:
      case NN_LINGER:
      case NN_SNDBUF:
      case NN_RCVBUF:
      case NN_RCVMAXSIZE:
      case NN_SNDTIMEO:
      case NN_RCVTIMEO:
      case NN_RECONNECT_IVL:
      case NN_RECONNECT_IVL_MAX:
      case NN_SNDPRIO:
      case NN_RCVPRIO:
      case NN_IPV4ONLY:
      case NN_SNDFD:
      case NN_RCVFD:
      case NN_MAXTTL:
        return c_option_type_int;
      case NN_SOCKET_NAME:
        return c_option_type_string;
      default:
        return c_option_type_error;
      }
    }/*}}}*/
    break;
  case NN_REQ:
    {/*{{{*/
      switch (a_option)
      {
        case NN_REQ_RESEND_IVL:
          return c_option_type_int;
        default:
          return c_option_type_error;
      }
    }/*}}}*/
    break;
  case NN_SUB:
    {/*{{{*/
      switch (a_option)
      {
        case NN_SUB_SUBSCRIBE:
        case NN_SUB_UNSUBSCRIBE:
          return c_option_type_string;
        default:
          return c_option_type_error;
      }
    }/*}}}*/
    break;
  case NN_SURVEYOR:
    {/*{{{*/
      switch (a_option)
      {
        case NN_SURVEYOR_DEADLINE:
          return c_option_type_int;
        default:
          return c_option_type_error;
      }
    }/*}}}*/
    break;
  case NN_TCP:
    {/*{{{*/
      switch (a_option)
      {
        case NN_TCP_NODELAY:
          return c_option_type_int;
        default:
          return c_option_type_error;
      }
    }/*}}}*/
    break;
  case NN_WS:
    {/*{{{*/
      switch (a_option)
      {
        case NN_WS_MSG_TYPE:
          return c_option_type_int;
        default:
          return c_option_type_error;
      }
    }/*}}}*/
    break;
  default:
    return c_option_type_error;
  }
}/*}}}*/

