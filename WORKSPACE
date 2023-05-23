workspace(name = "tarpit")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "bazel_skylib",
    strip_prefix = "bazel-skylib-main",
    urls = ["https://github.com/bazelbuild/bazel-skylib/archive/main.zip"],
)

http_archive(
    name = "rules_cc",
    strip_prefix = "rules_cc-main",
    urls = ["https://github.com/bazelbuild/rules_cc/archive/main.zip"],
)

http_archive(
    name = "com_google_absl",
    strip_prefix = "abseil-cpp-master",
    urls = ["https://github.com/abseil/abseil-cpp/archive/master.zip"],
)

http_archive(
    name = "com_google_googletest",
    strip_prefix = "googletest-main",
    urls = ["https://github.com/google/googletest/archive/main.zip"],
)

http_archive(
    name = "com_google_benchmark",
    strip_prefix = "benchmark-main",
    urls = ["https://github.com/google/benchmark/archive/main.zip"],
)

http_archive(
    name = "build_bazel_apple_support",
    sha256 = "9f7bb62c3ae889e0eae8c18458fd8764e2e537687d9a1d85885d6af980e4fc31",
    url = "https://github.com/bazelbuild/apple_support/releases/download/1.6.0/apple_support.1.6.0.tar.gz",
)

load("@build_bazel_apple_support//lib:repositories.bzl", "apple_support_dependencies")

apple_support_dependencies()
