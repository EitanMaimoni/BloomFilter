
# Bloom Filter Server - Windows

This project is a C++ server that interacts with a React-based web application to filter and censor links. It approves or disapproves links based on a pre-defined set of censored URLs that are initialized when the web application connects to the server.

## How to Run the Bloom Filter Server

1. **From the project directory, create a build directory and navigate into it:**

    ```bash
    mkdir build
    cd build
    ```

2. **Configure CMake:**

    ```bash
    cmake ..
    ```

3. **Build the project:**

    ```bash
    cmake --build . --config Release
    ```

4. **Run the server:**

    ```bash
    build/Release/BloomFilterServer.exe
    ```
