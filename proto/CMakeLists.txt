cmake_minimum_required(VERSION 3.5)

project(pb_cc)

file(GLOB PB_SRC "proto/*.cc")

add_library(${PROJECT_NAME} ${PB_SRC}) 
add_library(nemo::pb ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
		PUBLIC	
			${PROJECT_SOURCE_DIR}
)
message(STATUS "PTOTO_GEN_SRC dir : ${PROJECT_SOURCE_DIR}")

