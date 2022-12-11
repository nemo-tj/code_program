project(service)

find_package(Protobuf REQUIRED)

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${PROTOBUF_INCLUDE_DIRS}
)

foreach(_target
    read write
    greeter_server greeter_client greeter_client_again
    )
    add_executable(${_target} "${_target}.cc")
    target_link_libraries(${_target}
                nemo::pb
                nemo::util
                nemo::common
                ${PROTOBUF_LIBRARIES}
) 
endforeach()
