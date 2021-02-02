load("@rules_cc//cc:defs.bzl", "cc_binary")
load("@pybind11_bazel//:build_defs.bzl", "pybind_library", "pybind_extension")

package(default_visibility = ["//visibility:public"])

pybind_library(
  name = "libdata",
  hdrs = ["data.h"]
)

pybind_extension(
  name = "datamodule",
  srcs = ["export.cpp"],
  deps = [":libdata"]
)

cc_binary(
  name = "main",
  srcs = [
    "pywrapper.h",
    "main.cpp"
  ],
  data = [
    "mod.py"
  ],
  copts = [
    "-std=c++1z"
  ],
  linkopts = [
    "-I/usr/include/python3.6m",
    "-I/usr/include/x86_64-linux-gnu/python3.6m",
    "-lpython3.6m"
  ],
  deps = [
    "@pybind11//:pybind11_embed",
    ":libdata",
    ":datamodule.so"
  ]
)