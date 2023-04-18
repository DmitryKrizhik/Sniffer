CMAKE_MINIMUM_REQUIRED(VERSION 3.5)
project(TestSniffer)

add_executable(TestApp tmain.cpp)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)
enable_testing()

target_link_libraries(TestApp
    GTest::gtest_main
    SnifferLib
)

include(GoogleTest)
gtest_discover_tests(TestApp)

target_include_directories(TestApp PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR}/../include
)