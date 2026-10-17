cmake_minimum_required(VERSION 3.20)
project(DSAPractice LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Keep main.cpp for quick experiments
add_executable(Playground main.cpp)

# Find each standalone solution
file(GLOB_RECURSE SOLUTION_FILES CONFIGURE_DEPENDS
        "${CMAKE_SOURCE_DIR}/Codeforces/*.cpp"
        "${CMAKE_SOURCE_DIR}/LeetCode/*.cpp"
        "${CMAKE_SOURCE_DIR}/DSA/*.cpp"
)

# Build each solution as a separate executable
foreach(SOURCE_FILE IN LISTS SOLUTION_FILES)
    file(RELATIVE_PATH REL_PATH
            "${CMAKE_SOURCE_DIR}"
            "${SOURCE_FILE}"
    )

    string(REPLACE "/" "_" TARGET_NAME "${REL_PATH}")
    string(REGEX REPLACE "\\.cpp$" "" TARGET_NAME "${TARGET_NAME}")

    add_executable("${TARGET_NAME}" "${SOURCE_FILE}")
endforeach()