#!/bin/bash
set -x

ROOT_DIR=`pwd`
#dir="01-basic/J-building-with-ninja"
dir="."

if [ -d "$ROOT_DIR/$dir/build.ninja" ]; then
    echo "deleting $dir/build.ninja"
    rm -r $dir/build.ninja
fi
