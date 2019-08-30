
@begin
include "epoll_module.h"
@end

// - EPOLL indexes of built in classes -
unsigned c_bi_class_epoll = c_idx_not_exist;

// - EPOLL module -
EXPORT built_in_module_s module =
{/*{{{*/
  1,                     // Class count
  epoll_classes,         // Classes
  0,                     // Error base index
  8,                     // Error count
  epoll_error_strings,   // Error strings
  epoll_initialize,      // Initialize function
  epoll_print_exception, // Print exceptions function
};/*}}}*/

// - EPOLL classes -
built_in_class_s *epoll_classes[] =
{/*{{{*/
  &epoll_class,
};/*}}}*/

// - EPOLL error strings -
const char *epoll_error_strings[] =
{/*{{{*/
  "error_EPOLL_CREATE_ERROR",
  "error_EPOLL_WRONG_FDS_AND_EVENTS_ARRAY_SIZE",
  "error_EPOLL_WRONG_FD_OR_EVENTS_VALUE_TYPE",
  "error_EPOLL_CONTROL_ADD_ERROR",
  "error_EPOLL_CONTROL_MODIFY_ERROR",
  "error_EPOLL_CONTROL_DELETE_ERROR",
  "error_EPOLL_WAIT_INVALID_MAX_EVENT_COUNT",
  "error_EPOLL_WAIT_ERROR",
};/*}}}*/

// - EPOLL initialize -
bool epoll_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize epoll class identifier -
  c_bi_class_epoll = class_base_idx++;

  return true;
}/*}}}*/

// - EPOLL print exception -
bool epoll_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_EPOLL_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nEpoll create error: ");
    errno = exception.params[0];
    perror("");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_EPOLL_WRONG_FDS_AND_EVENTS_ARRAY_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong size of epoll file descriptors and events array\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_EPOLL_WRONG_FD_OR_EVENTS_VALUE_TYPE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong type of file descriptor or events value\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_EPOLL_CONTROL_ADD_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nEpoll control add error: ");
    errno = exception.params[0];
    perror("");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_EPOLL_CONTROL_MODIFY_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nEpoll control modify error: ");
    errno = exception.params[0];
    perror("");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_EPOLL_CONTROL_DELETE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nEpoll control delete error: ");
    errno = exception.params[0];
    perror("");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_EPOLL_WAIT_INVALID_MAX_EVENT_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nEpoll wait, invalid max event count %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_EPOLL_WAIT_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nEpoll wait error: ");
    errno = exception.params[0];
    perror("");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class EPOLL -
built_in_class_s epoll_class =
{/*{{{*/
  "Epoll",
  c_modifier_public | c_modifier_final,
  6, epoll_methods,
  1 + 8, epoll_variables,
  bic_epoll_consts,
  bic_epoll_init,
  bic_epoll_clear,
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

built_in_method_s epoll_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_epoll_operator_binary_equal
  },
  {
    "Epoll#1",
    c_modifier_public | c_modifier_final,
    bic_epoll_method_Epoll_1
  },
  {
    "update#1",
    c_modifier_public | c_modifier_final,
    bic_epoll_method_update_1
  },
  {
    "wait#2",
    c_modifier_public | c_modifier_final,
    bic_epoll_method_wait_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_epoll_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_epoll_method_print_0
  },
};/*}}}*/

built_in_variable_s epoll_variables[] =
{/*{{{*/

  // - epoll create flags -
  { "CLOEXEC",  c_modifier_public | c_modifier_static | c_modifier_static_const },

  // - epoll event types -
  { "EPOLLIN",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EPOLLOUT",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EPOLLRDHUP",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EPOLLPRI",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EPOLLERR",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EPOLLHUP",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EPOLLET",  c_modifier_public | c_modifier_static | c_modifier_static_const },
  { "EPOLLONESHOT",  c_modifier_public | c_modifier_static | c_modifier_static_const },

};/*}}}*/

void bic_epoll_consts(location_array_s &const_locations)
{/*{{{*/

  // - insert epoll create flags -
  {
    const_locations.push_blanks(1);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 1);

#define CREATE_EPOLL_CREATE_FLAG_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_EPOLL_CREATE_FLAG_BIC_STATIC(EPOLL_CLOEXEC);
  }

  // - insert epoll event types -
  {
    const_locations.push_blanks(8);
    location_s *cv_ptr = const_locations.data + (const_locations.used - 8);

#define CREATE_EPOLL_EVENT_TYPE_BIC_STATIC(VALUE)\
  cv_ptr->v_type = c_bi_class_integer;\
  cv_ptr->v_reference_cnt.atomic_set(1);\
  cv_ptr->v_data_ptr = (long long int)VALUE;\
  cv_ptr++;

    CREATE_EPOLL_EVENT_TYPE_BIC_STATIC(EPOLLIN);
    CREATE_EPOLL_EVENT_TYPE_BIC_STATIC(EPOLLOUT);
    CREATE_EPOLL_EVENT_TYPE_BIC_STATIC(EPOLLRDHUP);
    CREATE_EPOLL_EVENT_TYPE_BIC_STATIC(EPOLLPRI);
    CREATE_EPOLL_EVENT_TYPE_BIC_STATIC(EPOLLERR);
    CREATE_EPOLL_EVENT_TYPE_BIC_STATIC(EPOLLHUP);
    CREATE_EPOLL_EVENT_TYPE_BIC_STATIC(EPOLLET);
    CREATE_EPOLL_EVENT_TYPE_BIC_STATIC(EPOLLONESHOT);
  }

}/*}}}*/

void bic_epoll_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (epoll_s *)nullptr;
}/*}}}*/

void bic_epoll_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  epoll_s *ep_ptr = (epoll_s *)location_ptr->v_data_ptr;

  if (ep_ptr != nullptr)
  {
    ep_ptr->clear(it);
    cfree(ep_ptr);
  }
}/*}}}*/

bool bic_epoll_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_epoll_method_Epoll_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
flags:retrieve_integer
>
method Epoll
; @end

  int fd = epoll_create1(flags);

  // - ERROR -
  if (fd == -1)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_EPOLL_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(errno);

    return false;
  }

  // - create epoll object -
  epoll_s *ep_ptr = (epoll_s *)cmalloc(sizeof(epoll_s));
  ep_ptr->init();

  ep_ptr->fd = fd;

  dst_location->v_data_ptr = (epoll_s *)ep_ptr;

  return true;
}/*}}}*/

bool bic_epoll_method_update_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
fds:c_bi_class_array
>
method update
; @end

  epoll_s *ep_ptr = (epoll_s *)dst_location->v_data_ptr;
  pointer_array_s *array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

  // - ERROR -
  if (array_ptr->used & 0x01)
  {
    exception_s::throw_exception(it,module.error_base + c_error_EPOLL_WRONG_FDS_AND_EVENTS_ARRAY_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  epoll_fds_s &fds = ep_ptr->fds;
  epoll_event event = {0};

  // - preprocess all fds -
  if (fds.used != 0)
  {
    epoll_fd_s *fd_ptr = fds.data;
    epoll_fd_s *fd_ptr_end = fd_ptr + fds.used;
    do {
      
      // - fd is not unused -
      if (fd_ptr->fd != EPOLL_FD_UNUSED)
      {
        // - mark fd as removed -
        fd_ptr->fd = EPOLL_FD_REMOVED;
      }
    } while(++fd_ptr < fd_ptr_end);
  }

  if (array_ptr->used > 0)
  {
    // - fill pollfd structures -
    pointer *p_ptr = array_ptr->data;
    pointer *p_ptr_end = p_ptr + array_ptr->used;
    do {
      location_s *fd_location = it.get_location_value(p_ptr[0]);
      location_s *events_location = it.get_location_value(p_ptr[1]);

      // - ERROR -
      if (fd_location->v_type != c_bi_class_integer ||
          events_location->v_type != c_bi_class_integer)
      {
        exception_s::throw_exception(it,module.error_base + c_error_EPOLL_WRONG_FD_OR_EVENTS_VALUE_TYPE,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }

      long long int fd = (long long int)fd_location->v_data_ptr;
      long long int events = (long long int)events_location->v_data_ptr;

      // - resize fds if needed -
      if (fd >= fds.used)
      {
        fds.reserve(fd + 1 - fds.used);

        do {
          fds.push_blank();
          fds.last().set(EPOLL_FD_UNUSED,0);
        } while(fd >= fds.used);
      }

      // - add new fd -
      if (fds[fd].fd == EPOLL_FD_UNUSED)
      {
        event.events = events;
        event.data.fd = fd;

        // - ERROR -
        if (epoll_ctl(ep_ptr->fd,EPOLL_CTL_ADD,fd,&event) == -1)
        {
          exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_EPOLL_CONTROL_ADD_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
          new_exception->params.push(errno);

          return false;
        }

        // - update fd value -
        fds[fd].set(fd,events);
      }

      // - modify old fd -
      else
      {
        // - event set was changed -
        if (fds[fd].events != events)
        {
          event.events = events;
          event.data.fd = fd;

          // - ERROR -
          if (epoll_ctl(ep_ptr->fd,EPOLL_CTL_MOD,fd,&event) == -1)
          {
            // - reopened fd, not problem -
            if (errno != ENOENT)
            {
              exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_EPOLL_CONTROL_MODIFY_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
              new_exception->params.push(errno);

              return false;
            }

            // - ERROR -
            if (epoll_ctl(ep_ptr->fd,EPOLL_CTL_ADD,fd,&event) == -1)
            {
              exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_EPOLL_CONTROL_ADD_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
              new_exception->params.push(errno);

              return false;
            }
          }
        }

        // - update fd value -
        fds[fd].set(fd,events);
      }
    } while((p_ptr += 2) < p_ptr_end);
  }

  // - preprocess all fds -
  if (fds.used != 0)
  {
    // - reset props of dummy event -
    event.events = 0;
    event.data.fd = 0;

    epoll_fd_s *fd_ptr = fds.data;
    epoll_fd_s *fd_ptr_end = fd_ptr + fds.used;
    do {
      
      // - fd is marked as removed -
      if (fd_ptr->fd == EPOLL_FD_REMOVED)
      {
        // - ERROR -
        if (epoll_ctl(ep_ptr->fd,EPOLL_CTL_DEL,fd_ptr - fds.data,&event) == -1)
        {
          // - closed fd, not problem -
          if (errno != EBADF)
          {
            exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_EPOLL_CONTROL_DELETE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
            new_exception->params.push(errno);

            return false;
          }
        }

        // - mark fd as unused -
        fd_ptr->fd = EPOLL_FD_UNUSED;
      }
    } while(++fd_ptr < fd_ptr_end);
  }

  BIC_SET_RESULT_DESTINATION();

  return true;
}/*}}}*/

bool bic_epoll_method_wait_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
max_events:retrieve_integer
timeout:retrieve_integer
>
method wait
; @end

  // - ERROR -
  if (max_events <= 0)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_EPOLL_WAIT_INVALID_MAX_EVENT_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(max_events);

    return false;
  }

  epoll_s *ep_ptr = (epoll_s *)dst_location->v_data_ptr;

  epoll_event stack_events[32];
  epoll_event *events = max_events <= 32 ? stack_events :
    (epoll_event *)cmalloc(max_events*sizeof(epoll_event));

  int count = epoll_wait(ep_ptr->fd,events,max_events,timeout);

  // - ERROR -
  if (count == -1)
  {
    if (events != stack_events)
    {
      cfree(events);
    }

    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_EPOLL_WAIT_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(errno);

    return false;
  }

  pointer_array_s *array_ptr = it.get_new_array_ptr();

  if (count > 0)
  {
    epoll_event *e_ptr = events;
    epoll_event *e_ptr_end = e_ptr + count;
    do {
      long long int fd = e_ptr->data.fd;
      long long int events = e_ptr->events;

      BIC_CREATE_NEW_LOCATION(fd_location,c_bi_class_integer,fd)
      array_ptr->push(fd_location);

      BIC_CREATE_NEW_LOCATION(events_location,c_bi_class_integer,events)
      array_ptr->push(events_location);

    } while(++e_ptr < e_ptr_end);
  }

  if (events != stack_events)
  {
    cfree(events);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_array,array_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_epoll_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Epoll"),"Epoll")
  );

  return true;
}/*}}}*/

bool bic_epoll_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("Epoll");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

