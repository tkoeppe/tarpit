load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "runfiles",
    srcs = ["runfiles.cc"],
    hdrs = ["runfiles.h"],
    visibility = ["//visibility:public"],
    deps = [
        "@abseil-cpp//absl/memory",
        "@abseil-cpp//absl/status:statusor",
        "@bazel_tools//tools/cpp/runfiles",
    ],
)

cc_library(
    name = "runfiles_for_test",
    testonly = 1,
    srcs = ["runfiles_for_test.cc"],
    hdrs = ["runfiles_for_test.h"],
    visibility = ["//visibility:public"],
    deps = [
        "@abseil-cpp//absl/memory",
        "@abseil-cpp//absl/status:statusor",
        "@bazel_tools//tools/cpp/runfiles",
    ],
)
