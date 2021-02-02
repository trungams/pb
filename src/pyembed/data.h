#pragma once

#include <string>
#include <vector>

struct CustomData {
  CustomData(const std::string &s, const std::vector<int> &v) : str(s), v(v) {}

  std::string str;
  std::vector<int> v;
};