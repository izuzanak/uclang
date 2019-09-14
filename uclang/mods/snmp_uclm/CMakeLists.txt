
find_path(PATH_SNMP_H NAMES
  "net-snmp/net-snmp-config.h"
  "net-snmp/utilities.h"
  "net-snmp/net-snmp-includes.h"
  "net-snmp/agent/net-snmp-agent-includes.h")

if(PATH_SNMP_H)
  set(LIBSNMP_FOUND TRUE)
  set(LIBSNMP_LIBRARIES netsnmp netsnmpagent)
endif()

if(LIBSNMP_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS)
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBSNMP_LIBRARIES})
endif()
