// Copyright (C) 2024 Kokuhatsu
// SPDX-License-Identifier: MIT

#include <doctest/doctest.h>

#include <cstdint>

#include "line_parsers.hpp"

TEST_CASE("get value from line") {
  std::int64_t value = aoc231::get_value_from_line("1abc2");
  CHECK(value == 12);

  value = aoc231::get_value_from_line("pqr3stu8vwx");
  CHECK(value == 38);

  value = aoc231::get_value_from_line("a1b2c3d4e5f");
  CHECK(value == 15);

  value = aoc231::get_value_from_line("treb7uchet");
  CHECK(value == 77);
}
