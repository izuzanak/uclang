
if(OS_LINUX)
  find_path(PATH_PAM_APPL_H NAMES "security/pam_appl.h")
  if(PATH_PAM_APPL_H)
    set(LIBPAM_FOUND TRUE)
  endif()
endif()

if(LIBPAM_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS)
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    pam)
endif()

