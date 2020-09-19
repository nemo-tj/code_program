load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "components",
    srcs = glob(["*.cc"]),
    hdrs = glob(["*.h"]),
    visibility = ["//main:__pkg__",
                  "//work:__pkg__"],
)
