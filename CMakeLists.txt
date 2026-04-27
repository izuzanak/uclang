
cmake_minimum_required(VERSION 3.0.2...3.13)

option(FILC_BUILD "Build with Fil-C compiler (/opt/fil/)" OFF)

set(COMPONENTS "" CACHE STRING
    "Comma-separated list of components to build.")

if(FILC_BUILD)
  set(CMAKE_C_COMPILER "/opt/fil/bin/filcc")
  set(CMAKE_CXX_COMPILER "/opt/fil/bin/fil++")
  set(PKG_CONFIG_EXECUTABLE "/opt/fil/bin/pkg-config")
  set(CMAKE_FIND_ROOT_PATH "/opt/fil")
  set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
  set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
  set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
endif()

find_package(PkgConfig)

project(uclang)

set(PROC_DIR "${CMAKE_CURRENT_BINARY_DIR}/proc_files")
file(MAKE_DIRECTORY ${PROC_DIR})

set(USE_MF_MODS FALSE)
set(MF_MODS_FILE "${CMAKE_CURRENT_SOURCE_DIR}/uclang_build/mf_mods.py")

set_property(GLOBAL PROPERTY TARGET_MESSAGES OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
enable_testing()

if(COMPONENTS)
  string(REPLACE "," ";" COMPONENTS_LIST "${COMPONENTS}")
  list(TRANSFORM COMPONENTS_LIST STRIP)
  list(REMOVE_ITEM COMPONENTS_LIST "")
  set(COMPONENTS_FILTER TRUE)
  set_property(GLOBAL PROPERTY COMPONENTS_REMAINING "${COMPONENTS_LIST}")
else()
  set(COMPONENTS_FILTER FALSE)
endif()

# - update compilation flags -
if(FILC_BUILD)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wfatal-errors -Wno-vla-cxx-extension")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fprofile-arcs -ftest-coverage")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wfatal-errors")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address -fsanitize=undefined -fprofile-arcs -ftest-coverage")
endif()
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")

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

  set_target_properties(${COMP_NAME} PROPERTIES
   INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib/uclang")

  target_include_directories(${COMP_NAME} PUBLIC ${COMP_INCLUDE_DIRS})
  target_compile_definitions(${COMP_NAME} PUBLIC ${COMP_COMP_DEFS})
  target_link_libraries(${COMP_NAME} ${COMP_LINK_LIBS})
endfunction()

# - process components -
function(process_components COMPS_DIR)
file(GLOB MODULE_DIRS "" "${CMAKE_CURRENT_SOURCE_DIR}/${COMPS_DIR}/*")
foreach(COMP_DIR ${MODULE_DIRS})
  get_filename_component(COMP_NAME ${COMP_DIR} NAME)

  if(COMPONENTS_FILTER)
    get_property(REMAINING GLOBAL PROPERTY COMPONENTS_REMAINING)
    if(NOT "${COMP_NAME}" IN_LIST REMAINING)
      continue()
    endif()
  endif()

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

    if(COMPONENTS_FILTER)
      if(NOT CONF_DO_BUILD)
        message(FATAL_ERROR
            "COMPONENTS: component '${COMP_NAME}' cannot be built.")
      endif()
      list(REMOVE_ITEM REMAINING "${COMP_NAME}")
      set_property(GLOBAL PROPERTY COMPONENTS_REMAINING "${REMAINING}")
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
  add_definitions(-DLINUX)
elseif(MSYS)
  set(OS_MSYS2 TRUE)
  add_definitions(-DMSYS2 -DDISABLE_SO_DOMAIN)
else()
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

if(COMPONENTS_FILTER)
  get_property(REMAINING GLOBAL PROPERTY COMPONENTS_REMAINING)
  if(REMAINING)
    message(FATAL_ERROR
        "COMPONENTS: following components were not found: ${REMAINING}")
  endif()
endif()

# - module tests -
set(TEST_RUNNER "${CMAKE_CURRENT_SOURCE_DIR}/build/scripts/test.ucl")
if(EXISTS "${TEST_RUNNER}")
  file(GLOB MODULE_TEST_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/uclang/mods/*/test")
  foreach(TEST_DIR ${MODULE_TEST_DIRS})
    get_filename_component(MOD_DIR ${TEST_DIR} DIRECTORY)
    get_filename_component(MOD_NAME ${MOD_DIR} NAME)
    string(REGEX REPLACE "_uclm$" "" MOD_SHORT_NAME ${MOD_NAME})

    add_test(
      NAME "mod_${MOD_SHORT_NAME}"
      COMMAND ${CMAKE_CURRENT_BINARY_DIR}/uclang
              ${TEST_RUNNER}
              ${CMAKE_CURRENT_SOURCE_DIR}/uclang/mods
              ${CMAKE_CURRENT_BINARY_DIR}
              ${MOD_SHORT_NAME}
      WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    )
    set_tests_properties("mod_${MOD_SHORT_NAME}" PROPERTIES
      ENVIRONMENT "LD_LIBRARY_PATH=${CMAKE_CURRENT_BINARY_DIR};PATH=${CMAKE_CURRENT_BINARY_DIR}:$ENV{PATH}"
      SKIP_RETURN_CODE 77
    )
  endforeach()
endif()

