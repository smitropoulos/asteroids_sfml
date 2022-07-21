enable_testing()

add_executable(
        ConfigurationLoaderIniTests
        ConfigurationLoaderIniTests.cpp
)
target_link_libraries(
        ConfigurationLoaderIniTests
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(ConfigurationLoaderIniTests)
