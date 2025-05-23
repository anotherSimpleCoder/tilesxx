add_executable(PagingTests
    PagingTests.cpp
)

target_link_libraries(PagingTests
    GTest::gtest
    GTest::gtest_main
)

add_test(
        NAME PagingTests
        COMMAND PagingTests
)