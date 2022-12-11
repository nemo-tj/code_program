cmake_minimum_required(VERSION 3.19)

# Set the project name
project (pb_cc)

# find the protobuf compiler and libraries
find_package(Protobuf REQUIRED)

# check if protobuf was found
if(PROTOBUF_FOUND)
    message ("protobuf found")
else()
    message (FATAL_ERROR "Cannot find Protobuf")
endif()

# Generate the .h and .cxx files
file(GLOB PROTO_FILE "proto/*.proto")
PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS ${PROTO_FILE})

file(GLOB RPC_PROTO "rpc/*.proto")
PROTOBUF_GENERATE_CPP(RPC_SRCS RPC_HDRS ${RPC_PROTO})

# fetch grpc
# include(FetchContent)
# FetchContent_Declare(
#   gRPC
#   GIT_REPOSITORY https://github.com/grpc/grpc
#   GIT_TAG        v1.28.0 # RELEASE_TAG_HERE  e.g v1.28.0
# )
# set(FETCHCONTENT_QUIET OFF)
# FetchContent_MakeAvailable(gRPC)

# Add Library
add_library(${PROJECT_NAME}
    STATIC
    ${PROTO_SRCS}
    ${PROTO_HDRS}
    ${RPC_SRCS}
    ${RPC_HDRS}
)
add_library(nemo::pb ALIAS ${PROJECT_NAME})

# Print path to generated files
message ("PROTO_SRCS = ${PROTO_SRCS}")
message ("PROTO_HDRS = ${PROTO_HDRS}")
message ("RPC_HDRS   = ${RPC_HDRS}")
message ("RPC_SRCS   = ${RPC_SRCS}")

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${PROTOBUF_INCLUDE_DIRS}
    ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(${PROJECT_NAME} grpc++)


# PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS proto/address_book.proto)
