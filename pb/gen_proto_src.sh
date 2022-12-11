#! /bin/bash
set -x
SRC_DIR=src
rm -rf ${SRC_DIR}
mkdir -p ${SRC_DIR}

# generate msg
MSG_DIR=msg
protoc -I ${MSG_DIR} --cpp_out=${SRC_DIR} ${MSG_DIR}/*.proto

# generate rpc
RPC_DIR=rpc
cd ${RPC_DIR}
GRPC_CPP_PLUGIN=grpc_cpp_plugin
GRPC_CPP_PLUGIN_PATH=`which ${GRPC_CPP_PLUGIN}`
protoc --grpc_out=. --cpp_out=. --plugin=protoc-gen-grpc=${GRPC_CPP_PLUGIN_PATH} ./*.proto 
mv *.cc *.h ../${SRC_DIR}/
cd -
