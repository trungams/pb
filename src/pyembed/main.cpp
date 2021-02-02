#include <iostream>
#include <numeric>
#include <vector>

#include "src/pyembed/pywrapper.h"

int main(void) {
  PyModuleWrapper mod;
  std::vector<int> v(10);
  std::iota(v.begin(), v.end(), 0);
  CustomData data("data", std::move(v));
  std::cout << "C++: Calling Python method" << std::endl;
  int result = mod.execute(data);
  std::cout << "Return value from Python: " << result << std::endl;
  return 0;
}
