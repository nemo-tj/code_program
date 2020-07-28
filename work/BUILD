load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "worker",
    srcs = glob(["*.cc"]),
    hdrs = glob(["*.h"]),
    deps = ["//comp:components",
            ],
    visibility = ["//main:__pkg__"],
)
