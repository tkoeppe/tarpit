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
        "@com_google_googletest//:gtest_main",
    ],
)

cc_binary(
    name = "dso_demo.so",
    srcs = ["dso_demo.cc"],
    linkshared = 1,
    linkstatic = 1,
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
