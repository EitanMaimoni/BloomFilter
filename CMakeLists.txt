cmake_minimum_required(VERSION 3.14)
project("Ex1") # Replace “MyCalc” with your repo name

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

set(SOURCE_FILES
    src/bloomFilter.cpp # this is where the code we want to test
    src/hFunc.cpp  # Add this line if hFunc.cpp is a source file
    src/oneHashBloomFilterValidator.cpp # Add this line if oneHashBloomFilterValidator.cpp is a source file
    src/twoHashBloomFilterValidator.cpp # Add this line if twoHashBloomFilterValidator.cpp is a source file
    src/addUrl.cpp
    src/checkUrl.cpp
)

set(TEST_FILES
    tests/test_main.cpp # this is the main for tests
    tests/oneHashBloomFilterValidator_test.cpp # this file contain the tests
    tests/twoHashBloomFilterValidator_test.cpp # this file contain the tests
)
add_executable(oneHashBloomFilterValidator ${SOURCE_FILES} ${TEST_FILES})
# Link Google Test to the test executable
target_link_libraries(oneHashBloomFilterValidator PRIVATE gtest gtest_main)

# Include the source directory for tests
target_include_directories(oneHashBloomFilterValidator PRIVATE src)
include(GoogleTest)
add_test(NAME oneHashBloomFilterValidator COMMAND oneHashBloomFilterValidator)