cmake_minimum_required(VERSION 3.24)
project(ArithmeticTree)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 23)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Download and unpack googletest at configure time
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(GoogleTests
        tests/test1.cpp
        tests/UtilitiesTest.cpp
        src/Utilities.cpp
        src/Utilities.hpp)

target_link_libraries(GoogleTests gtest gtest_main)

install(TARGETS GoogleTests DESTINATION "${tool_dest}")



# Executable for normal use
add_executable(ArithmeticTree
        src/main.cpp
        src/Visualizer.hpp
        src/Visualizer.cpp
        src/Tokenizer.hpp
        src/Tokenizer.cpp
        "src/Token Classes/Token.hpp"
        "src/Token Classes/Token.cpp"
        "src/Token Classes/Operator.hpp"
        "src/Token Classes/Operator.cpp"
        "src/Token Classes/Number.hpp"
        "src/Token Classes/Number.cpp"
        "src/Token Classes/Bracket.hpp"
        src/Evaluator.hpp
        src/Evaluator.cpp
        lib/bst_visualizer/BST_Visualizer.cpp
        lib/bst_visualizer/BST_Visualizer.hpp
        src/Utilities.cpp
        src/Utilities.hpp)