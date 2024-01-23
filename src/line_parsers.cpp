// Copyright (C) 2024 Kokuhatsu
// SPDX-License-Identifier: MIT

#include <algorithm>
#include <cctype>
#include <ranges>

#include "line_parsers.hpp"

namespace {
  template <typename string_template>
  std::int64_t find_first_digit(const string_template& line) {
    const auto digit_iterator = std::ranges::find_if(line, std::isdigit);
    const auto digit_ascii_code = *digit_iterator;
    const std::int64_t digit = digit_ascii_code - '0';

    return digit;
  }

  std::int64_t find_last_digit(const std::string& line) {
    const auto reversed_view = line | std::views::reverse;

    return find_first_digit(reversed_view);
  }

  std::int64_t get_trebuchet_score(std::int64_t first_digit
                                 , std::int64_t last_digit) {
    return first_digit * 10 + last_digit;
  }
}

namespace aoc231 {
  std::int64_t get_value_from_line(const std::string& line) {
    std::int64_t first_digit = find_first_digit(line);
    std::int64_t last_digit = find_last_digit(line);
    return get_trebuchet_score(first_digit, last_digit);
  }
}
