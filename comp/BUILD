load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "components",
    srcs = glob(["*.cc"]),
    hdrs = glob(["*.h"]),
    deps = ["@com_github_google_glog//:glog"],
    visibility = ["//main:__pkg__",
                  "//work:__pkg__"],
)
