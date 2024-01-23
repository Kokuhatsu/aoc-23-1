# Copyright (C) 2024 Kokuhatsu
# SPDX-License-Identifier: MIT

add_executable(unit-tests)

target_sources(unit-tests PRIVATE
               unit-tests.cpp
               line_parsers.cpp)

target_include_directories(unit-tests PRIVATE
                           ${CMAKE_CURRENT_SOURCE_DIR}
                           ${CMAKE_SOURCE_DIR}/src/)

target_compile_features(unit-tests PUBLIC cxx_std_20)
target_compile_options(unit-tests PRIVATE ${COMMON_COMPILE_OPTIONS})
set_target_properties(unit-tests PROPERTIES
                      CXX_EXTENSIONS OFF
                      CMAKE_CXX_STANDARD_REQUIRED ON
                      RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

target_link_libraries(unit-tests PRIVATE aoc-23-1-lib doctest::doctest)
