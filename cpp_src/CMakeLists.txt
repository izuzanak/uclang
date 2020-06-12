
cmake_minimum_required(VERSION 3.0.2)

find_package(PkgConfig)

project(uclang)

set(CURRENT_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/..")

set(PROC_DIR "${CMAKE_CURRENT_BINARY_DIR}/proc_files")
file(MAKE_DIRECTORY ${PROC_DIR})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
enable_testing()

# - process target source file -
function(process_source SOURCE TARGET)
# {{{
  execute_process(COMMAND ${PROCESS_BIN} --output "${TARGET}" "${SOURCE}" ${COMP_HEADER_DIRS}
      OUTPUT_VARIABLE DEPS
      ERROR_QUIET)
# }}}
endfunction()

# - process component -
function(process_component)
  foreach(SOURCE_DIR "header_files" "source_files")
    file(MAKE_DIRECTORY "${COMP_PROC_DIR}/${SOURCE_DIR}")
    file(GLOB SOURCE_FILES "" "${COMP_DIR}/${SOURCE_DIR}/*.*[hc]")

    foreach(SOURCE_FILE ${SOURCE_FILES})
      get_filename_component(SOURCE_NAME ${SOURCE_FILE} NAME)
      
      process_source("${COMP_DIR}/${SOURCE_DIR}/${SOURCE_NAME}" "${COMP_PROC_DIR}/${SOURCE_DIR}/${SOURCE_NAME}")
    endforeach()
  endforeach()
endfunction()

# - process components -
function(process_components COMPS_DIR)
file(GLOB MODULE_DIRS "" "${CURRENT_SOURCE_DIR}/${COMPS_DIR}/*")
foreach(COMP_DIR ${MODULE_DIRS})
  get_filename_component(COMP_NAME ${COMP_DIR} NAME)

  set(CONF_DO_BUILD FALSE)
  set(COMP_DO_BUILD FALSE)

  if(EXISTS ${COMP_DIR}/CMakeLists.txt)
    string(REPLACE "${CURRENT_SOURCE_DIR}" "${PROC_DIR}" COMP_PROC_DIR "${COMP_DIR}")

    # - copy component cmake file -
    file(COPY "${COMP_DIR}/CMakeLists.txt" DESTINATION "${COMP_PROC_DIR}")
    include(${COMP_DIR}/CMakeLists.txt)

    set(COMP_DO_BUILD TRUE)
    if(COMP_DO_BUILD)
      set(COMP_HEADER_DIRS "${COMP_DIR}/header_files" ${CONF_HEADER_DIRS})
      set(COMP_SOURCE_DIRS "${COMP_DIR}/source_files")
      set(COMP_INCLUDE_DIRS ${CONF_INCLUDE_DIRS})
      set(COMP_COMP_DEFS ${CONF_COMP_DEFS})
      set(COMP_LINK_LIBS ${CONF_LINK_LIBS})

      process_component()
    endif()
  endif()
endforeach()
endfunction()

# - set global variables -
if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
  set(OS_LINUX TRUE)
  set(OS_WINDOWS FALSE)
  #add_definitions(-Wall -Wfatal-errors -Wno-class-memaccess -DLINUX)
  add_definitions(-Wall -O3 -DNDEBUG -Wfatal-errors -Wno-class-memaccess -DLINUX)
else()
  set(OS_LINUX FALSE)
  set(OS_WINDOWS TRUE)
  add_definitions("/DWINDOWS /D_CRT_SECURE_NO_WARNINGS /wd4244")
endif()

# - find process binary -
find_program(PROCESS_BIN cont)

if(NOT PROCESS_BIN)
  message("WARNING: Cannot found container generator")
  return()
endif()

set(EXT_LIBS "${CURRENT_SOURCE_DIR}/ext_libs")
set(LIBS "${CURRENT_SOURCE_DIR}/uclang/libs")
set(MODS "${CURRENT_SOURCE_DIR}/uclang/mods")

set(LIB_BASE "${CURRENT_SOURCE_DIR}/uclang/libs/base_ucll")
set(LIB_FTGL "${CURRENT_SOURCE_DIR}/uclang/libs/ftgl_ucll")
set(LIB_NODE "${CURRENT_SOURCE_DIR}/uclang/libs/node_ucll")

# - process libraries -
process_components("uclang/libs")

# - process programs -
process_components("uclang/progs")

# - process modules -
process_components("uclang/mods")

