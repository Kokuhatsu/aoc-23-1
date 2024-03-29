// Copyright (C) 2024 Kokuhatsu
// SPDX-License-Identifier: MIT

#pragma once

#include <cstdint>
#include <string>

namespace aoc231 {
  std::int64_t get_value_from_line(const std::string& line_to_parse);
  std::int64_t get_value_from_line_with_literals(const std::string& line_to_parse);
}
