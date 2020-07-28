# /usr/bin/sh
bazel query --notool_deps --noimplicit_deps "deps(//main:run_bin)" --output graph > view/run_bin.dot
dot view/run_bin.dot -T png -o view/run_bin.png
