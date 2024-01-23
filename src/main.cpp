// Copyright (C) 2024 Kokuhatsu
// SPDX-License-Identifier: MIT

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "line_parsers.hpp"

int main() {
  std::ifstream input_file(
    std::filesystem::path(__FILE__).remove_filename()
    / ".."
    / "input.txt");

  std::int64_t result = 0;

  while(input_file.eof() == false) {
    std::string line;
    input_file >> line;

    if(line.empty()) break;

    result += aoc231::get_value_from_line(line);
  }

  std::cout << "result: " << result << std::endl;

  return 0;
}
