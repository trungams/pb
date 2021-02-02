#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "src/pyextend/mymodule.h"

namespace py = pybind11;

PYBIND11_MODULE(mymodule, m) {
  m.doc() = "extending python example";
  m.def("add", &Add, "Returns the sum of two integers");
  m.def("sum", &Sum, "A function that returns the sum of a list");
  m.def("reverse", &Reverse, "A function that reverses a string");
  py::class_<Person>(m, "Person")
      .def(py::init<const std::string &, uint8_t, const std::string &>(),
           py::arg("name"), py::arg("age"), py::arg("address") = "earth")
      .def("get_name", &Person::GetName)
      .def("__repr__",
           [](const Person &p) { return "<mymodule.Person - " + p.name + ">"; })
      .def_readonly("name", &Person::name)
      .def_readonly("age", &Person::age)
      .def_readwrite("address", &Person::address);
}
