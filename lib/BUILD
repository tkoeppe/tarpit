cc_library(
    name = "runfiles",
    srcs = ["runfiles.cc"],
    hdrs = ["runfiles.h"],
    visibility = ["//visibility:public"],
    deps = [
        "@bazel_tools//tools/cpp/runfiles",
        "@com_google_absl//absl/memory",
        "@com_google_absl//absl/status:statusor",
    ],
)

cc_library(
    name = "runfiles_for_test",
    testonly = 1,
    srcs = ["runfiles_for_test.cc"],
    hdrs = ["runfiles_for_test.h"],
    visibility = ["//visibility:public"],
    deps = [
        "@bazel_tools//tools/cpp/runfiles",
        "@com_google_absl//absl/memory",
        "@com_google_absl//absl/status:statusor",
    ],
)
