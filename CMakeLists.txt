cmake_minimum_required(VERSION 3.10)
project(BloomFilterServer)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add windows socket library
if(WIN32)
    link_libraries(ws2_32)
endif()

# Source files
set(SOURCES
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

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

# Add compiler flags
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)
endif()