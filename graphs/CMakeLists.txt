cmake_minimum_required(VERSION 3.5)

set(subproject graph)
set(subproject_lib ${subproject}_lib)
set(subproject_tests ${subproject}_tests)

add_subdirectory(lib)
add_subdirectory(tests)

file(GLOB app *)

add_executable(${subproject} ${app})

target_link_libraries(${subproject}
    ${subproject_lib}
)


target_include_directories(${subproject}
    PRIVATE ${Boost_INCLUDE_DIRS}
)
