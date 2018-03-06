# Copyright 2017 - 2018 The WizTK Authors.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required(VERSION 3.1)

project(Elysium)

# The project version number.
set(VERSION_MAJOR 0 CACHE STRING "Project major version number.")
set(VERSION_MINOR 0 CACHE STRING "Project minor version number.")
set(VERSION_PATCH 1 CACHE STRING "Project patch version number.")
mark_as_advanced(VERSION_MAJOR VERSION_MINOR VERSION_PATCH)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/modules/")

# ----------------------------------------------------------------------------
# System check
# ----------------------------------------------------------------------------

if (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    set(APPLE TRUE)
    set(UNIX TRUE)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(LINUX TRUE)
    set(UNIX TRUE)
    add_definitions(-D__linux__)
else ()
    message(FATAL_ERROR "Unsupported system!")
endif ()

# ----------------------------------------------------------------------------
# Compiler and basic compile options
# ----------------------------------------------------------------------------

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    # using clang
    message(STATUS "Use C++ compiler: Clang")
    # add_definitions(-D__clang__)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    # using GCC
    message(STATUS "Use C++ compiler: GCC")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
    # using Intel C++
    message(STATUS "Use C++ compiler: Intel C++")
else ()
    message(FATAL "Unsupported c++ compiler: ${CMAKE_CXX_COMPILER}")
endif ()

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif ()
set(CMAKE_CXX_STANDARD 14)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-D__DEBUG__)
    set(CMAKE_CXX_FLAGS "-g -Wall -std=c++14")
else ()
    set(CMAKE_CXX_FLAGS "-O3 -std=c++14")
endif ()

if (TRACE)
    add_definitions(-D__TRACE__)
endif ()

# ----------------------------------------------------------------------------
# Find prerequisites
# ----------------------------------------------------------------------------

find_package(Wayland REQUIRED)
if (WAYLAND_FOUND)
    include_directories(${WAYLAND_SERVER_INCLUDE_DIR} ${WAYLAND_EGL_INCLUDE_DIR})
    set(LIBS ${LIBS} ${WAYLAND_SERVER_LIBRARIES} ${WAYLAND_EGL_LIBRARIES})
endif ()

# Prebuilts setting:

set(PREBUILTS_DIR ${PROJECT_BINARY_DIR}/prebuilts/${CMAKE_SYSTEM_PROCESSOR})

# Wayland protocols
include_directories(${PREBUILTS_DIR}/wayland-protocols/unstable/xdg-shell)
link_directories(${PREBUILTS_DIR}/wayland-protocols/unstable/xdg-shell)

add_subdirectory(docs)
add_subdirectory(src)

message(STATUS "IMPORTANT: checkout 'https://github.com/wiztk/prebuilts.git' to ${PROJECT_BINARY_DIR}/prebuilts.")
