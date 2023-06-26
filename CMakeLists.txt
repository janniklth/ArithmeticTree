cmake_minimum_required(VERSION 3.24)
project(ArithmeticTree)

set(CMAKE_CXX_STANDARD 23)

add_executable(ArithmeticTree
        src/main.cpp
        src/Vis.hpp
        src/Tokenizer.hpp
        src/Token.hpp
        src/Order.hpp
        src/Op.hpp
        src/Num.hpp
        src/Evaluator.hpp
        src/Bracket.hpp
        src/ABaumVCpp.cpp)
