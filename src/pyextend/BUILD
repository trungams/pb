load("@pybind11_bazel//:build_defs.bzl", "pybind_library", "pybind_extension")
load("@rules_python//python:defs.bzl", "py_binary")

package(default_visibility = ["//visibility:public"])

pybind_library(
  name = "libmymodule",
  hdrs = ["mymodule.h"],
)

pybind_extension(
  name = "mymodule",
  srcs = ["export.cpp"],
  deps = [":libmymodule"]
)

py_binary(
  name = "main",
  srcs = ["main.py"],
  data = [":mymodule.so"]
)
