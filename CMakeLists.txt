cmake_minimum_required (VERSION 3.19)

project(cc_program)

# Add sub directories
add_subdirectory(server)
add_subdirectory(struct)
add_subdirectory(util)
add_subdirectory(alg)
add_subdirectory(common)

# Service
add_subdirectory(service)
add_subdirectory(pb)
# add_subdirectory(worker)
