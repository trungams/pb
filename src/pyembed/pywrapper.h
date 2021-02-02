#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include <pybind11/embed.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "src/pyembed/data.h"

namespace py = pybind11;

class PyModuleWrapper {
public:
  PyModuleWrapper() {}

  int execute(const CustomData &data) {
    py::scoped_interpreter guard;
    // load the .so module to include the definitions
    py::module datamod = py::module_::import("src.pyembed.datamodule");
    py::module pymod = py::module_::import("src.pyembed.mod");
    py::object obj = pymod.attr("MyModule")();
    py::object input = py::cast(&data);
    return obj.attr("execute")(input).cast<int>();
  }
};
