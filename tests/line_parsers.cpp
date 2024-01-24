// Copyright (C) 2024 Kokuhatsu
// SPDX-License-Identifier: MIT

#include <doctest/doctest.h>

#include <cstdint>

#include "line_parsers.hpp"

TEST_CASE("get value from line only digits") {
  std::int64_t value = aoc231::get_value_from_line("1abc2");
  CHECK(value == 12);

  value = aoc231::get_value_from_line("pqr3stu8vwx");
  CHECK(value == 38);

  value = aoc231::get_value_from_line("a1b2c3d4e5f");
  CHECK(value == 15);

  value = aoc231::get_value_from_line("treb7uchet");
  CHECK(value == 77);
}

TEST_CASE("get value from line digits and literals") {
  std::int64_t value = aoc231::get_value_from_line_with_literals("two1nine");
  CHECK(value == 29);
  value = aoc231::get_value_from_line_with_literals("eightwothree");
  CHECK(value == 83);
  value = aoc231::get_value_from_line_with_literals("abcone2threexyz");
  CHECK(value == 13);
  value = aoc231::get_value_from_line_with_literals("xtwone3four");
  CHECK(value == 24);
  value = aoc231::get_value_from_line_with_literals("4nineeightseven2");
  CHECK(value == 42);
  value = aoc231::get_value_from_line_with_literals("zoneight234");
  CHECK(value == 14);
  value = aoc231::get_value_from_line_with_literals("7pqrstsixteen");
  CHECK(value == 76);
}
