cmake_minimum_required(VERSION 3.24)
project(ArithmeticTree)

set(CMAKE_CXX_STANDARD 23)

add_executable(ArithmeticTree
        src/main.cpp
        src/Visualizer.hpp
        src/Visualizer.cpp
        src/Tokenizer.hpp
        src/Tokenizer.cpp
        src/Token.hpp
        src/Token.cpp
        src/Operator.hpp
        src/Operator.cpp
        src/Number.hpp
        src/Number.cpp
        src/Evaluator.hpp
        src/Evaluator.cpp
        src/Bracket.hpp
        src/ABaumVCpp.cpp
        src/Order.hpp)
