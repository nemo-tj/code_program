cmake_minimum_required(VERSION 3.19)
    
# Set the project name
project (cc_util)

add_library(${PROJECT_NAME} INTERFACE)
add_library(nemo::util ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
  INTERFACE
      ${PROJECT_SOURCE_DIR}/
)
