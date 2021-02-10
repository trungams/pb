#include <iostream>
#include <numeric>
#include <vector>

#include <pybind11/embed.h>
#include <pybind11/pybind11.h>

#include "src/pyembed/pywrapper.h"

namespace py = pybind11;

int main(void) {
  py::scoped_interpreter guard;
  PyModuleWrapper mod;
  std::vector<int> v(10);
  std::iota(v.begin(), v.end(), 0);
  CustomData data("data", std::move(v));
  std::cout << "C++: Calling Python method" << std::endl;
  int result = mod.execute(data);
  std::cout << "Return value from Python: " << result << std::endl;

  Int64Matrix ma(3, 2), mb(2, 3);
  for (int i = 0; i < static_cast<int>(ma.rows()); i++)
    for (int j = 0; j < static_cast<int>(ma.cols()); j++)
      ma[i][j] = i * j;

  for (int i = 0; i < static_cast<int>(mb.rows()); i++)
    for (int j = 0; j < static_cast<int>(mb.cols()); j++)
      mb[i][j] = i * j;

  std::cout << "Input values from C++" << std::endl;
  std::cout << ma << std::endl;
  std::cout << mb << std::endl;
  auto prod = mod.multiply_matrices(ma, mb);
  std::cout << "Return value from Python:" << std::endl;
  std::cout << prod << std::endl;
  return 0;
}
