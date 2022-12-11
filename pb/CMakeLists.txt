cmake_minimum_required(VERSION 3.5)

# Set the project name
project (pb3_cc)

# find the protobuf compiler and libraries, and threads gRPC
find_package(Threads REQUIRED)
find_package(Protobuf REQUIRED)
find_package(gRPC CONFIG REQUIRED)

# message info
message(STATUS "Using protobuf-${Protobuf_VERSION}")
message(STATUS "Using gRPC-${gRPC_VERSION}")

# Print path to generated files
file(GLOB PROTO_SRCS "src/*.cc")
file(GLOB PROTO_HDRS "src/*.h")
message ("PROTO_HDRS   = ${PROTO_HDRS}")
message ("PROTO_SRCS   = ${PROTO_SRCS}")

# Add Library
add_library(${PROJECT_NAME}
    STATIC
    ${PROTO_SRCS}
    ${PROTO_HDRS}
)
add_library(nemo::pb ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(${PROJECT_NAME}
    gRPC::grpc++
    gRPC::grpc++_reflection
    protobuf::libprotobuf
)
#########################################################################

    # ${CMAKE_CURRENT_BINARY_DIR}
    # ${PROTOBUF_INCLUDE_DIRS}

# Generate the .h and .cxx files
# set(MSG_PROTO_PATH ${CMAKE_CURRENT_SOURCE_DIR}/msg)
# file(GLOB MSG_PROTO "${MSG_PROTO_PATH}/*.proto")
# PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS ${MSG_PROTO})
# 
# set(RPC_PROTO_PATH ${CMAKE_CURRENT_SOURCE_DIR}/rpc)
# file(GLOB RPC_PROTO "${RPC_PROTO_PATH}/*.proto")
# PROTOBUF_GENERATE_GRPC_CPP(RPC_SRCS RPC_HDRS ${RPC_PROTO})


