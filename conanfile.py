# Copyright (C) 2024 Kokuhatsu
# SPDX-License-Identifier: MIT

from conan import ConanFile


class aoc241Recipe(ConanFile):
  settings = "arch", "os", "build_type", "compiler"
  generators = "CMakeToolchain", "CMakeDeps"

  def requirements(self):
    self.requires("doctest/2.4.11")
