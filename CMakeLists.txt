#########################################################################
#
#  CMAKE
#
#########################################################################

###
#  Minimum Version
#  ---------------
#  The CMake version required.
###
cmake_minimum_required(VERSION 3.1)

###
#  CMake Configuration
#  -------------------
#  Configuration settings for CMake.
#
#  NOTE:
#  These settings have to be applied before the project() setting!
###
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_C_STANDARD 99)

###
#  Project Info
#  ------------
#  General simple information about our project.
###
project(libmrhev VERSION 1.0
                 DESCRIPTION "Event queue management library for the MRH Platform"
                 LANGUAGES C)

#########################################################################
#
#  PATHS
#
#########################################################################

###
#  Binary Paths
#  ------------
#  The paths for our created binary file(s).
###
set(BIN_DIR_PATH "${CMAKE_SOURCE_DIR}/lib/")
file(MAKE_DIRECTORY ${BIN_DIR_PATH})

###
#  Build Paths
#  -----------
#  The paths for the cmake build.
###
set(BUILD_DIR_PATH "${CMAKE_SOURCE_DIR}/build/")
file(MAKE_DIRECTORY ${BUILD_DIR_PATH})

###
#  Source Paths
#  ------------
#  The paths to the source files to use.
###
set(SRC_DIR_PATH "${CMAKE_SOURCE_DIR}/src/")
set(INCLUDE_DIR_PATH "${CMAKE_SOURCE_DIR}/include/")

set(SRC_LIST_GLOBAL "${SRC_DIR_PATH}/libmrhev/Error/MRH_EventQueueError.c"
                    "${SRC_DIR_PATH}/libmrhev/Error/MRH_EventQueueErrorInternal.h"
                    "${SRC_DIR_PATH}/libmrhev/Source/MRH_SourcePipe.c"
                    "${SRC_DIR_PATH}/libmrhev/Source/MRH_SourcePipe.h"
                    "${SRC_DIR_PATH}/libmrhev/MRH_QueueUpdatePipe.c"
                    "${SRC_DIR_PATH}/libmrhev/MRH_QueueUpdatePipe.h"
                    "${SRC_DIR_PATH}/libmrhev/MRH_EventQueue.h"
                    "${SRC_DIR_PATH}/libmrhev.c"
                    "${INCLUDE_DIR_PATH}/libmrhev/libmrhev/Error/MRH_EventQueueError.h"
                    "${INCLUDE_DIR_PATH}/libmrhev/libmrhev/MRH_EvRevision.h"
                    "${INCLUDE_DIR_PATH}/libmrhev/libmrhev.h")

#
# TODO: Implement MRHCKM with lib check
#
#if()
#endif()
#
#set(SRC_LIST_MRHCKM "${SRC_DIR_PATH}/libmrhev/Source/MRH_SourceMRHCKM.c"
#				    "${SRC_DIR_PATH}/libmrhev/Source/MRH_SourceMRHCKM.h"
#					"${SRC_DIR_PATH}/libmrhev/MRH_QueueUpdateMRHCKM.c"
#					"${SRC_DIR_PATH}/libmrhev/MRH_QueueUpdateMRHCKM.h")

###
#  Library Paths
#  -------------
#  The paths to the external libraries to use. 
#  Both the binary and include paths should be set here.
#  Add OS specific libraries in their own lists.
###
set(LIB_INCLUDE_LIST "${INCLUDE_DIR_PATH}/mrhshared")
					 
#########################################################################
#
#  TARGET
#
#########################################################################

###
#  Target
#  ------
#  The target(s) to build.
###
add_library(libmrhev_Shared SHARED ${SRC_LIST_GLOBAL})
set_target_properties(libmrhev_Shared
                      PROPERTIES
                      PREFIX ""
                      OUTPUT_NAME "libmrhev"
                      SUFFIX ".so"
                      ARCHIVE_OUTPUT_DIRECTORY ${BIN_DIR_PATH}
                      LIBRARY_OUTPUT_DIRECTORY ${BIN_DIR_PATH}
                      RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR_PATH})
					  
add_library(libmrhev_Static STATIC ${SRC_LIST_GLOBAL})
set_target_properties(libmrhev_Static
                      PROPERTIES
                      PREFIX ""
                      OUTPUT_NAME "libmrhev"
                      SUFFIX ".a"
                      ARCHIVE_OUTPUT_DIRECTORY ${BIN_DIR_PATH}
                      LIBRARY_OUTPUT_DIRECTORY ${BIN_DIR_PATH}
                      RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR_PATH})

###
#  Required Libraries
#  ------------------
#  Libraries and / or headers required by this library.
###
include_directories(${LIB_INCLUDE_LIST})