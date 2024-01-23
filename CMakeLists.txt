# Copyright (C) 2024 Kokuhatsu
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.27.0)

project(AOC-23-1
        LANGUAGES CXX)

add_subdirectory(cmake)
include(third_party/list.cmake)
add_subdirectory(src)
