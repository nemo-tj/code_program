cmake_minimum_required(VERSION 3.5)
    
# Set the project name
project (cc_common)

add_library(${PROJECT_NAME} INTERFACE)
add_library(nemo::common ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
  INTERFACE
      ${PROJECT_SOURCE_DIR}
)
