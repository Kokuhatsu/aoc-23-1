# Copyright (C) 2024 Kokuhatsu
# SPDX-License-Identifier: MIT

add_executable(aoc-23-1)

target_sources(aoc-23-1 PRIVATE
               main.cpp
               line_parsers.cpp)

target_include_directories(aoc-23-1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_features(aoc-23-1 PUBLIC cxx_std_20)
target_compile_options(aoc-23-1 PRIVATE ${COMMON_COMPILE_OPTIONS})
set_target_properties(aoc-23-1 PROPERTIES
                      CXX_EXTENSIONS OFF
                      CMAKE_CXX_STANDARD_REQUIRED ON
                      RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
