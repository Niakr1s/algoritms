cmake_minimum_required(VERSION 3.5)

file(GLOB tests *)

add_executable(${subproject_tests}
    ${tests}
)

target_link_libraries(${subproject_tests}
    PRIVATE ${subproject}_lib
    PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main
)

target_include_directories(${subproject_tests}
    PRIVATE ${BOOST_INCLUDE_DIRS}
)
