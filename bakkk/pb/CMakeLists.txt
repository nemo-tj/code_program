cmake_minimum_required(VERSION 3.5)

project(pb3_cc)

add_library(${PROJECT_NAME} INTERFACE)
add_library(nemo::pb ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
  INTERFACE
      ${PROJECT_SOURCE_DIR}
)
