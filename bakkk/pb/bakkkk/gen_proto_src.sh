#! /bin/bash
set -x
SRC_DIR=pb_cc
rm -rf ${SRC_DIR}
mkdir -p ${SRC_DIR}

# generate msg
MSG_DIR=msg
protoc  --cpp_out=${SRC_DIR} ${MSG_DIR}/*.proto

# generate rpc
RPC_DIR=rpc
GRPC_CPP_PLUGIN=grpc_cpp_plugin
GRPC_CPP_PLUGIN_PATH=`which ${GRPC_CPP_PLUGIN}`
protoc --grpc_out=${SRC_DIR} --plugin=protoc-gen-grpc=${GRPC_CPP_PLUGIN_PATH} ${RPC_DIR}/*.proto

cd ${SRC_DIR}
ln -sf ../CMakeLists.txt .
cd -
