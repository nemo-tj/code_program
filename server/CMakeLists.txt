cmake_minimum_required(VERSION 3.5)
project(main_server)

set(MAIN_SRC main.cc)
add_executable(${PROJECT_NAME} ${MAIN_SRC})

target_link_libraries(${PROJECT_NAME}
    nemo::test
) 
