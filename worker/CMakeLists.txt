# Set the project name
project (worklibrary)

add_library(${PROJECT_NAME} INTERFACE)
add_library(nemo::test ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    INTERFACE
        ${PROJECT_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME}
    INTERFACE
        nemo::test
        nemo::struct
        nemo::util
        nemo::alg
        nemo::common
        nemo::pb
)
