cmake_minimum_required(VERSION 3.5)

set(subproject graph)
set(subproject_lib ${subproject}_lib)
set(subproject_tests ${subproject}_tests)

add_subdirectory(lib)
add_subdirectory(tests)

add_executable(${subproject} main.cpp)

target_link_libraries(${subproject}
    ${subproject_lib}
)
