cmake_minimum_required(VERSION 3.5)
    
# Set the project name
project (cc_struct)

# Add a library with the above sources
#set(STRUCT_SRC src/link.cc)

file(GLOB STRUCT_SRC "src/*.cc")
add_library(${PROJECT_NAME} ${STRUCT_SRC})
add_library(nemo::struct ALIAS ${PROJECT_NAME})

# include header files
target_include_directories(${PROJECT_NAME}
  PUBLIC
      ${PROJECT_SOURCE_DIR}/include
)
target_link_libraries(${PROJECT_NAME}
       nemo::common
       nemo::util
)
