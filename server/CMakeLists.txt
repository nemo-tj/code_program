project(main_server)

# Create the executable
SET(MAIN_SRC main.cc)
add_executable(${PROJECT_NAME} ${MAIN_SRC})

# Link the static library from subproject1 using its alias sub::lib1
# Link the header only library from subproject2 using its alias sub::lib2
# This will cause the include directories for that target to be added to this project


target_link_libraries(${PROJECT_NAME}
  nemo::struct
  nemo::util
  nemo::alg
  nemo::common
  nemo::pb
)
