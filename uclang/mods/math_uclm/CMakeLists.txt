
if(PKG_CONFIG_FOUND)
  pkg_search_module(LIBGLM "glm")
endif()

if(NOT LIBGLM_FOUND)
  find_package(glm CONFIG QUIET)
  if(glm_FOUND)
    if(TARGET glm::glm)
      get_target_property(LIBGLM_INCLUDE_DIRS glm::glm
          INTERFACE_INCLUDE_DIRECTORIES)
      if(NOT LIBGLM_INCLUDE_DIRS AND TARGET glm::glm-header-only)
        get_target_property(LIBGLM_INCLUDE_DIRS glm::glm-header-only
            INTERFACE_INCLUDE_DIRECTORIES)
      endif()
      if(LIBGLM_INCLUDE_DIRS)
        set(LIBGLM_FOUND TRUE)
        set(LIBGLM_LIBRARIES glm::glm)
      endif()
    endif()
  endif()
endif()

if(NOT LIBGLM_FOUND)
  find_path(LIBGLM_INCLUDE_DIR glm/glm.hpp)
  if(LIBGLM_INCLUDE_DIR)
    set(LIBGLM_FOUND TRUE)
    set(LIBGLM_INCLUDE_DIRS ${LIBGLM_INCLUDE_DIR})
    set(LIBGLM_LIBRARIES "")
  endif()
endif()

if(LIBGLM_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${LIBGLM_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${LIBGLM_LIBRARIES})
endif()

