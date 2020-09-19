load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "func",
    srcs = glob(["*.cc"],
                exclude=["main.cc"]
                ),
    hdrs = glob(["*.h"]),
)

cc_binary(
    name = "run_bin",
    srcs = ["main.cc"],
    deps = [
        ":func",
        "//component:components",
        "//work:worker",
    ],
)
