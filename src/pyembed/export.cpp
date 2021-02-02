#include <string>
#include <vector>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "src/pyembed/data.h"

namespace py = pybind11;

PYBIND11_MODULE(datamodule, m) {
  m.doc() = "embedding python example";
  py::class_<CustomData>(m, "CustomData")
      .def(py::init<const std::string &, const std::vector<int> &>())
      .def_readwrite("str", &CustomData::str)
      .def_readwrite("v", &CustomData::v);
}