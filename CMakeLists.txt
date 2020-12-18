# Copyright (c) 2020 Gemfield <gemfield@civilnet.cn>
# This file is part of SyszuxFace, licensed under the LGPLv2 (the "License")
# You may not use this file except in compliance with the License.

cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
set(SYSZUX_FACE_VERSION 0.1.0)
project(SyszuxFace
    VERSION ${SYSZUX_FACE_VERSION}
    DESCRIPTION "Face detect based on libdeepvac."
    HOMEPAGE_URL "https://github.com/CivilNet/SYSZUX-FACE"
    LANGUAGES CXX)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    set(LINUX TRUE)
else()
    set(LINUX FALSE)
endif()

if(NOT LINUX)
    message(FATAL_ERROR "SyszuxFace does not support platform: " ${CMAKE_SYSTEM_NAME})
endif()

set(CMAKE_CXX_STANDARD 17)

#setup library output dir
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
#setup binary output dir
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

find_package(OpenCV REQUIRED)
message(STATUS "OpenCV library status:")
message(STATUS "    config: ${OpenCV_DIR}")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

find_package(Deepvac REQUIRED)
message(STATUS "DEEPVAC_LIBRARIES: ${DEEPVAC_LIBRARIES}")
message(STATUS "DEEPVAC_INCLUDE_DIRS: ${DEEPVAC_INCLUDE_DIRS}")

find_package(OpenMP REQUIRED)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

# add subdiretories
file(GLOB LIB_SRC_LIST lib/*.cpp)
message(STATUS "found LIB_SRC_LIST: " ${LIB_SRC_LIST})
add_library(SyszuxFace SHARED ${LIB_SRC_LIST})

file(GLOB MAIN_SRC_LIST src/*.cpp)
message(STATUS "found MAIN_SRC_LIST: " ${MAIN_SRC_LIST})
add_executable( syszux_face_detect ${MAIN_SRC_LIST})

target_include_directories(SyszuxFace PRIVATE ${DEEPVAC_INCLUDE_DIRS} ${OpenCV_INCLUDE_DIRS})
target_include_directories(syszux_face_detect PRIVATE ${DEEPVAC_INCLUDE_DIRS} ${OpenCV_INCLUDE_DIRS})
target_include_directories(syszux_face_detect PRIVATE ${PROJECT_SOURCE_DIR}/lib/)

target_link_libraries(syszux_face_detect SyszuxFace deepvac ${OpenCV_LIBS})






