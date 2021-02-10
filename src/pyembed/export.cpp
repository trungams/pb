#include <string>
#include <vector>

#include <pybind11/buffer_info.h>
#include <pybind11/embed.h>
#include <pybind11/numpy.h>
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
  py::class_<Int64Matrix>(m, "IntMatrix", py::buffer_protocol())
      .def(py::init([](const py::buffer &b) {
        py::buffer_info info = b.request();

        if (info.format != py::format_descriptor<int64_t>::format())
          throw std::runtime_error("Incompatible format");
        if (info.ndim != 2)
          throw std::runtime_error("Incompatible buffer dimension");

        Int64Matrix *m = new Int64Matrix(info.shape[0], info.shape[1]);
        memcpy(m->data(), info.ptr, sizeof(int64_t) * m->rows() * m->cols());
        return m;
      }))
      .def_buffer([](Int64Matrix &m) -> py::buffer_info {
        return py::buffer_info(m.data(), sizeof(int64_t),
                               py::format_descriptor<int64_t>::format(), 2,
                               {m.rows(), m.cols()},
                               {sizeof(int64_t) * m.cols(), sizeof(int64_t)});
      });
}
