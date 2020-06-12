
cmake_minimum_required(VERSION 3.0.2)

find_package(PkgConfig)

project(uclang)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
enable_testing()

# - process component -
function(process_component)
  set(PROC_SOURCE_FILES)
  foreach(SOURCE_DIR ${COMP_SOURCE_DIRS})
    set(SOURCE_FILES)
    aux_source_directory(${SOURCE_DIR} SOURCE_FILES)
    list(APPEND PROC_SOURCE_FILES "${SOURCE_FILES}")
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

  if(EXISTS ${COMP_DIR}/CMakeLists.txt)
    include(${COMP_DIR}/CMakeLists.txt)

    if(CONF_DO_BUILD)
      set(COMP_DO_BUILD TRUE)
    endif()

    if(COMP_DO_BUILD)
      set(COMP_HEADER_DIRS "${COMP_DIR}/header_files" ${CONF_HEADER_DIRS})
      set(COMP_SOURCE_DIRS "${COMP_DIR}/source_files")
      set(COMP_INCLUDE_DIRS ${CONF_INCLUDE_DIRS} ${COMP_HEADER_DIRS})
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

set(EXT_LIBS "${CMAKE_CURRENT_SOURCE_DIR}/ext_libs")
set(LIBS "${CMAKE_CURRENT_SOURCE_DIR}/uclang/libs")
set(MODS "${CMAKE_CURRENT_SOURCE_DIR}/uclang/mods")

set(LIB_BASE "${CMAKE_CURRENT_SOURCE_DIR}/uclang/libs/base_ucll")
set(LIB_FTGL "${CMAKE_CURRENT_SOURCE_DIR}/uclang/libs/ftgl_ucll")
set(LIB_NODE "${CMAKE_CURRENT_SOURCE_DIR}/uclang/libs/node_ucll")

# - process libraries -
process_components("uclang/libs")

# - process programs -
process_components("uclang/progs")

# - process modules -
process_components("uclang/mods")

