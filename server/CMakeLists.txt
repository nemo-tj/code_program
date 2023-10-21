cmake_minimum_required(VERSION 3.5)
project(main_server VERSION 1.0)

set(MAIN_SRC main.cc)

find_package (glog 0.6.0 REQUIRED)

add_executable(${PROJECT_NAME} ${MAIN_SRC})

target_link_libraries(${PROJECT_NAME}
    nemo::test
		glog::glog
) 
