
cmake_minimum_required(VERSION 3.1.0)

project(uclang)

set(PROC_DIR "${CMAKE_CURRENT_BINARY_DIR}/proc_files")
file(MAKE_DIRECTORY ${PROC_DIR})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
enable_testing()

find_package(PkgConfig)

# -----

function(process TARGET)
  execute_process(COMMAND process --deps "${SOURCE_DIR}/${TARGET}.cc" ${COMP_HEADER_DIRS}
      OUTPUT_VARIABLE DEPS
      ERROR_QUIET)
  add_custom_command(OUTPUT "${PROC_DIR}/p.${TARGET}.cc"
      DEPENDS ${DEPS}
      COMMAND process "${SOURCE_DIR}/${TARGET}.cc" ${COMP_HEADER_DIRS} > "${PROC_DIR}/p.${TARGET}.cc")
  add_custom_target(${COMP_NAME}_p_${TARGET}
      DEPENDS "${PROC_DIR}/p.${TARGET}.cc")
endfunction()

# -----

function(add_component)
  set(PROC_DIR "${PROC_DIR}/${COMP_NAME}")
  file(MAKE_DIRECTORY ${PROC_DIR})

  set(DEPENDENCIES)
  set(PROC_SOURCE_FILES)
  foreach(SOURCE_DIR ${COMP_SOURCE_DIRS})
    set(SOURCE_FILES)
    aux_source_directory(${SOURCE_DIR} SOURCE_FILES)

    foreach(SOURCE_FILE ${SOURCE_FILES})
      get_filename_component(TARGET ${SOURCE_FILE} NAME_WE)
      process(${TARGET})

      list(APPEND DEPENDENCIES ${COMP_NAME}_p_${TARGET})
      list(APPEND PROC_SOURCE_FILES "${PROC_DIR}/p.${TARGET}.cc")
    endforeach()
  endforeach()

  if(${COMP_NAME} MATCHES "_ucl[lm]$")
    add_library(${COMP_NAME} SHARED ${PROC_SOURCE_FILES})
    set_target_properties(${COMP_NAME} PROPERTIES PREFIX "")
  else()
    add_executable(${COMP_NAME} ${PROC_SOURCE_FILES})
  endif()

  target_include_directories(${COMP_NAME} PUBLIC ${COMP_INCLUDE_DIRS})
  target_compile_definitions(${COMP_NAME} PUBLIC ${COMP_COMP_DEFS})
  target_link_libraries(${COMP_NAME} ${COMP_LINK_LIBS})
  add_dependencies(${COMP_NAME} ${DEPENDENCIES})
endfunction()

# -----

function(add_components COMPS_DIR)
file(GLOB MODULE_DIRS "" "${CMAKE_CURRENT_SOURCE_DIR}/${COMPS_DIR}/*")
foreach(COMP_DIR ${MODULE_DIRS})
  get_filename_component(COMP_NAME ${COMP_DIR} NAME)
  if(${MF_MODS} MATCHES "True,[ #-A-Z_]*${COMP_NAME}")
    if (EXISTS ${COMP_DIR}/CMakeLists.txt)
      include(${COMP_DIR}/CMakeLists.txt)
      set(COMP_HEADER_DIRS "${COMP_DIR}/header_files" ${CONF_HEADER_DIRS})
      set(COMP_SOURCE_DIRS "${COMP_DIR}/source_files")
      set(COMP_INCLUDE_DIRS ${CONF_INCLUDE_DIRS})
      set(COMP_COMP_DEFS ${CONF_COMP_DEFS})
      set(COMP_LINK_LIBS ${CONF_LINK_LIBS})
      add_component()
    endif()
  endif()
endforeach()
endfunction()

# -----

set(EXT_LIBS "${CMAKE_CURRENT_SOURCE_DIR}/../ext_libs")
set(LIBS "${CMAKE_CURRENT_SOURCE_DIR}/libs")
set(MODS "${CMAKE_CURRENT_SOURCE_DIR}/mods")

set(LIB_BASE "${CMAKE_CURRENT_SOURCE_DIR}/libs/libbase_ucll")
set(LIB_FTGL "${CMAKE_CURRENT_SOURCE_DIR}/libs/libftgl_ucll")
set(LIB_NODE "${CMAKE_CURRENT_SOURCE_DIR}/libs/libnode_ucll")

file(READ "${CMAKE_CURRENT_SOURCE_DIR}/../uclang_build/mf_mods.py" MF_MODS)

# - process libraries -
add_components("libs")

# - process programs -
add_components("progs")

# - process modules -
add_components("mods")

# -----

add_definitions(-Wall -Wfatal-errors -Wno-class-memaccess -DLINUX)

