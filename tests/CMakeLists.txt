include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG main
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    graph-tests
    graph.cc
)

target_link_libraries(
    graph-tests
    graph
    GTest::gtest_main
)


include(GoogleTest)
gtest_discover_tests(graph-tests)
