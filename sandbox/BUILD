load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_test")

cc_binary(
    name = "show_args",
    srcs = ["show_args.cc"],
)

cc_binary(
    name = "dso_loader",
    srcs = ["dso_loader.cc"],
    linkopts = ["-ldl"],
)

cc_test(
    name = "dso_test",
    srcs = ["dso_test.cc"],
    data = [":dso_demo.so"],
    linkopts = ["-ldl"],
    deps = [
        "//lib:runfiles_for_test",
        "@googletest//:gtest_main",
    ],
)

cc_binary(
    name = "dso_demo.so",
    srcs = ["dso_demo.cc"],
    linkshared = 1,
    linkstatic = 1,
    deps = [
        "@abseil-cpp//absl/container:flat_hash_map",
        "@abseil-cpp//absl/strings",
    ],
)

cc_binary(
    name = "data_haver",
    srcs = ["data_haver.cc"],
    data = [":dso_demo.so"],
    linkopts = ["-ldl"],
    deps = [
        "//lib:runfiles",
        "@bazel_tools//tools/cpp/runfiles",
    ],
)

cc_binary(
    name = "dlopen_benchmark",
    srcs = ["dlopen_benchmark.cc"],
    linkopts = ["-ldl"],
    deps = ["@google_benchmark//:benchmark"],
)
