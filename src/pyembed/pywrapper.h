#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include <pybind11/embed.h>
#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "src/pyembed/data.h"

namespace py = pybind11;

class PyModuleWrapper {
public:
  PyModuleWrapper() {}

  int execute(const CustomData &data) {
    // load the .so module to include the definitions
    py::module datamod = py::module_::import("src.pyembed.datamodule");
    py::module pymod = py::module_::import("src.pyembed.mod");
    py::object obj = pymod.attr("MyModule")();
    py::object input = py::cast(&data);
    return obj.attr("execute")(input).cast<int>();
  }

  Int64Matrix multiply_matrices(const Int64Matrix &a, const Int64Matrix &b) {
    py::module datamod = py::module_::import("src.pyembed.datamodule");
    py::module pymod = py::module_::import("src.pyembed.mod");
    py::object obj = pymod.attr("MyModule")();
    py::object m_a = py::cast(&a);
    py::object m_b = py::cast(&b);
    // call the function and retrieve the result as a python object
    py::object prod = obj.attr("multiply_matrices")(m_a, m_b);
    // print the result using the interpreter
    py::print("multiply_matrices result as received in C++:");
    py::print(prod);
    return prod.cast<Int64Matrix>();
  }
};
