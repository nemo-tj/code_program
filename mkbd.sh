#!/bin/sh
set -x

rm -rf bazel*

bazel build //main:run_bin

# run the code
export GLOG_log_dir=log
export GLOG_minloglevel=1
export GLOG_stderrthreshold=1
export GLOG_v=3
export GLOG_max_log_size=1
# ./bazel-bin/main/run_bin
./bazel-bin/main/run_bin  --alsologtostderr=1
