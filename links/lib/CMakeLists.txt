cmake_minimum_required(VERSION 3.5)

file(GLOB lib *)

add_library(${subproject_lib} SHARED
    ${lib}
)

target_link_libraries(${subproject_lib}
)

target_include_directories(${subproject_lib}
    PRIVATE ${BOOST_INCLUDE_DIRS}
    PUBLIC .
)
