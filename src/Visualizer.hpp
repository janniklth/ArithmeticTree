#ifndef ARITHMETIC_TREE_VISUALIZER_HPP
#define ARITHMETIC_TREE_VISUALIZER_HPP


#include "Token Classes/Token.hpp"

#include "iostream"



/// class to visualize a tree
class Visualizer
{
public:
    /// simple test method to print a tree
    /// @param root: the root node of tree to print
    static void printSimpleTree(Token* root, std::string prefix = "", bool isLast = true);


private:

};

#endif // ARITHMETIC_TREE_VISUALIZER_HPP