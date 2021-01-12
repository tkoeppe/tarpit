cc_binary(
    name = "show_args",
    srcs = ["show_args.cc"],
)

cc_binary(
    name = "dso_loader",
    srcs = ["dso_loader.cc"],
    linkopts = ["-ldl"],
)

cc_binary(
    name = "dso_demo.so",
    srcs = ["dso_demo.cc"],
    linkshared = 1,
    linkstatic = 1,
)
