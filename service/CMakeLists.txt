project(service)

find_package(Protobuf REQUIRED)

foreach(_target
    read write
    )
    add_executable(${_target} "${_target}.cc")
    target_link_libraries(${_target}
                nemo::pb
                nemo::util
                nemo::common
                ${PROTOBUF_LIBRARIES}
) 
endforeach()

# greeter_server greeter_client greeter_client_again
