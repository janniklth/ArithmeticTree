cmake_minimum_required(VERSION 3.24)
project(ArithmeticTree)

set(CMAKE_CXX_STANDARD 23)

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
        lib/BST_Visualizer.cpp
        lib/BST_Visualizer.hpp)
