cmake_minimum_required(VERSION 3.5)

project(cc_alg)

add_library(${PROJECT_NAME} INTERFACE)
add_library(nemo::alg ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
  INTERFACE
      ${PROJECT_SOURCE_DIR}/include
)
