cmake_minimum_required(VERSION 3.24)
project(ArithmeticTree)

set(CMAKE_CXX_STANDARD 23)

add_executable(ArithmeticTree
        src/main.cpp
        src/Visualizer.hpp
        src/Tokenizer.hpp
        src/Token.hpp
        src/Order.hpp
        src/Operator.hpp
        src/Number.hpp
        src/Evaluator.hpp
        src/Bracket.hpp
        src/ABaumVCpp.cpp
        src/Token.cpp src/Visualizer.cpp src/Evaluator.cpp)
