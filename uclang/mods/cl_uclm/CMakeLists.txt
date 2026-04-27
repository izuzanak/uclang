
if(PKG_CONFIG_FOUND)
  pkg_search_module(OPENCL "OpenCL")
endif()

if(NOT OPENCL_FOUND)
  find_package(OpenCL QUIET)
  if(OPENCL_FOUND OR OpenCL_FOUND)
    set(OPENCL_FOUND TRUE)
    if(TARGET OpenCL::OpenCL)
      get_target_property(OPENCL_INCLUDE_DIRS OpenCL::OpenCL
          INTERFACE_INCLUDE_DIRECTORIES)
      set(OpenCL_LIBRARIES OpenCL::OpenCL)
    else()
      set(OPENCL_INCLUDE_DIRS ${OpenCL_INCLUDE_DIRS})
    endif()
  endif()
endif()

if(NOT OPENCL_FOUND)
  find_path(OPENCL_INCLUDE_DIR CL/cl.h)
  find_library(OPENCL_LIBRARY NAMES OpenCL)
  if(OPENCL_INCLUDE_DIR AND OPENCL_LIBRARY)
    set(OPENCL_FOUND TRUE)
    set(OPENCL_INCLUDE_DIRS ${OPENCL_INCLUDE_DIR})
    set(OpenCL_LIBRARIES ${OPENCL_LIBRARY})
  endif()
endif()

if(OPENCL_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${OPENCL_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${OpenCL_LIBRARIES})
endif()

