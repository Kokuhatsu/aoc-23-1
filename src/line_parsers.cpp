// Copyright (C) 2024 Kokuhatsu
// SPDX-License-Identifier: MIT

#include <algorithm>
#include <cctype>
#include <ranges>

#include "line_parsers.hpp"

namespace {
  std::int64_t convert_char_to_digit(char character) {
    return character - '0';
  }

  template <typename string_template>
  std::int64_t find_first_digit(const string_template& line) {
    const auto digit_iterator = std::ranges::find_if(line, std::isdigit);
    const auto digit_ascii_code = *digit_iterator;
    const std::int64_t digit = convert_char_to_digit(digit_ascii_code);

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

  auto get_literals() {
    const std::array<std::string, 9> literals{"one"
                                            , "two"
                                            , "three"
                                            , "four"
                                            , "five"
                                            , "six"
                                            , "seven"
                                            , "eight"
                                            , "nine"};
    return literals;
  }

  auto get_literals_first_char() {
    std::string result;
    std::ranges::transform(
      get_literals()
      , std::back_inserter(result)
      , [](std::string literal) {
        return literal.front();
      });
    return result;
  }

  auto get_literals_last_char() {
    std::string result;
    std::ranges::transform(
      get_literals()
      , std::back_inserter(result)
      , [](std::string literal) {
        return literal.back();
      });
    return result;
  }

  auto enumerate_literals() {
    return get_literals() | std::views::enumerate;
  }

  auto drop_back(const std::string& container, const std::ptrdiff_t& number) {
    return container
           | std::views::reverse
           | std::views::drop(number)
           | std::views::reverse;
  }

  std::int64_t find_first_digit_with_literals(const std::string& line) {
    for(const auto& [index, character] : line | std::views::enumerate) {
      if(std::isdigit(character)) {
        return convert_char_to_digit(character);
      } else if(std::ranges::contains(get_literals_first_char(), character)) {
        for(const auto& [literal_index, literal] : get_literals()
                                                   | std::views::enumerate)
          if(std::ranges::starts_with(line | std::views::drop(index), literal))
            return literal_index + 1;
      }
    }

    return 0;
  }

  std::int64_t find_last_digit_with_literals(const std::string& line) {
    for(const auto& [index, character] : line
                                         | std::views::reverse
                                         | std::views::enumerate) {
      if(std::isdigit(character)) {
        return convert_char_to_digit(character);
      } else if(std::ranges::contains(get_literals_last_char(), character)) {
        for(const auto& [literal_index, literal] : get_literals()
                                                   | std::views::enumerate)
          if(std::ranges::ends_with(drop_back(line, index), literal))
            return literal_index + 1;
      }
    }

    return 0;
  }
}

namespace aoc231 {
  std::int64_t get_value_from_line(const std::string& line) {
    std::int64_t first_digit = find_first_digit(line);
    std::int64_t last_digit = find_last_digit(line);
    return get_trebuchet_score(first_digit, last_digit);
  }

  std::int64_t get_value_from_line_with_literals(const std::string& line) {
    std::int64_t first_digit = find_first_digit_with_literals(line);
    std::int64_t second_digit = find_last_digit_with_literals(line);
    return get_trebuchet_score(first_digit, second_digit);
  }
}
