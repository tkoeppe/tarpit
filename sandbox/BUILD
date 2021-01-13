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
        "@com_google_absl//absl/strings",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_binary(
    name = "dso_demo.so",
    srcs = ["dso_demo.cc"],
    linkshared = 1,
    linkstatic = 1,
)
