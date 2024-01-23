# Copyright (C) 2024 Kokuhatsu
# SPDX-License-Identifier: MIT

set(unix_werror_flags -Wall -Wextra -Werror -Wconversion -Wsign-conversion -pedantic-errors)

set(COMMON_COMPILE_OPTIONS
      $<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:${unix_werror_flags}>
      $<$<CXX_COMPILER_ID:MSVC>:-WX -W4>
    PARENT_SCOPE
   )
