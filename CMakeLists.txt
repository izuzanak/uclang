
cmake_minimum_required(VERSION 3.0.2)

find_package(PkgConfig)

project(uclang)

set(PROC_DIR "${CMAKE_CURRENT_BINARY_DIR}/proc_files")
file(MAKE_DIRECTORY ${PROC_DIR})

set(USE_MF_MODS FALSE)
set(MF_MODS_FILE "${CMAKE_CURRENT_SOURCE_DIR}/uclang_build/mf_mods.py")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
enable_testing()

# - process target source file -
function(process_source TARGET)
  execute_process(COMMAND ${PROCESS_BIN} --deps "${SOURCE_DIR}/${TARGET}.cc" ${COMP_HEADER_DIRS}
      OUTPUT_VARIABLE DEPS
      ERROR_QUIET)
  add_custom_command(OUTPUT "${PROC_DIR}/p.${TARGET}.cc"
      DEPENDS ${DEPS}
      COMMAND ${PROCESS_BIN} --geninc "--output" "${PROC_DIR}/p.${TARGET}.cc" "${SOURCE_DIR}/${TARGET}.cc" ${COMP_HEADER_DIRS})
endfunction()

# - process component -
function(process_component)
  set(PROC_DIR "${PROC_DIR}/${COMP_NAME}")
  file(MAKE_DIRECTORY ${PROC_DIR})

  set(PROC_SOURCE_FILES)
  foreach(SOURCE_DIR ${COMP_SOURCE_DIRS})
    set(SOURCE_FILES)
    aux_source_directory(${SOURCE_DIR} SOURCE_FILES)

    foreach(SOURCE_FILE ${SOURCE_FILES})
      get_filename_component(TARGET ${SOURCE_FILE} NAME_WE)
      process_source(${TARGET})

      list(APPEND PROC_SOURCE_FILES "${PROC_DIR}/p.${TARGET}.cc")
    endforeach()
  endforeach()

  if(${COMP_NAME} MATCHES "_ucl[lm]$")
    add_library("${COMP_NAME}" SHARED ${PROC_SOURCE_FILES})
    install(TARGETS ${COMP_NAME} LIBRARY DESTINATION lib/uclang)
  else()
    add_executable(${COMP_NAME} ${PROC_SOURCE_FILES})
    install(TARGETS ${COMP_NAME} RUNTIME DESTINATION bin)
  endif()

  target_include_directories(${COMP_NAME} PUBLIC ${COMP_INCLUDE_DIRS})
  target_compile_definitions(${COMP_NAME} PUBLIC ${COMP_COMP_DEFS})
  target_link_libraries(${COMP_NAME} ${COMP_LINK_LIBS})
endfunction()

# - process components -
function(process_components COMPS_DIR)
file(GLOB MODULE_DIRS "" "${CMAKE_CURRENT_SOURCE_DIR}/${COMPS_DIR}/*")
foreach(COMP_DIR ${MODULE_DIRS})
  get_filename_component(COMP_NAME ${COMP_DIR} NAME)

  set(CONF_DO_BUILD FALSE)
  set(COMP_DO_BUILD FALSE)

  if(USE_MF_MODS)
    if(${MF_MODS} MATCHES "True,[ #-A-Z_]*${COMP_NAME}")
      set(COMP_DO_BUILD TRUE)
    endif()
  endif()

  if(EXISTS ${COMP_DIR}/CMakeLists.txt)
    include(${COMP_DIR}/CMakeLists.txt)

    if(CONF_DO_BUILD)
      set(COMP_DO_BUILD TRUE)
    endif()

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
  #add_definitions(-Wall -std=c++11 -Wfatal-errors -Wno-class-memaccess -DLINUX)
  add_definitions(-Wall -std=c++11 -O3 -DNDEBUG -Wfatal-errors -Wno-class-memaccess -DLINUX)
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

set(EXT_LIBS "${CMAKE_CURRENT_SOURCE_DIR}/ext_libs")
set(LIBS "${CMAKE_CURRENT_SOURCE_DIR}/uclang/libs")
set(MODS "${CMAKE_CURRENT_SOURCE_DIR}/uclang/mods")

set(LIB_BASE "${CMAKE_CURRENT_SOURCE_DIR}/uclang/libs/base_ucll")
set(LIB_FTGL "${CMAKE_CURRENT_SOURCE_DIR}/uclang/libs/ftgl_ucll")
set(LIB_NODE "${CMAKE_CURRENT_SOURCE_DIR}/uclang/libs/node_ucll")

if(USE_MF_MODS)
  file(READ ${MF_MODS_FILE} MF_MODS)
endif()

# - process libraries -
process_components("uclang/libs")

# - process programs -
process_components("uclang/progs")

# - process modules -
process_components("uclang/mods")

