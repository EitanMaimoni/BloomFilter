cmake_minimum_required(VERSION 3.14)
project(Ex1)  # Replace "Ex1" with your project name

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# List your source files with correct paths
set(SOURCE_FILES
        src/main.cpp
        src/AddUrl.cpp
        src/App.cpp
        src/BloomFilter.cpp
        src/CheckUrl.cpp
        src/CommandValidator.cpp
        src/HFunc.cpp
        src/OneHashValidator.cpp
        src/TwoHashValidator.cpp
        )

# Create an executable target named "BloomFilter"
add_executable(BloomFilter ${SOURCE_FILES})

# Link against the Winsock library for Windows sockets
if(WIN32)
    target_link_libraries(BloomFilter Ws2_32)
endif()