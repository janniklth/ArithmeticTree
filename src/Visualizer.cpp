//
// Created by Jannik Loth on 03.07.23.
//

#include "Visualizer.hpp"

/// simple test method to print a tree
void Visualizer::printSimpleTree(Token *root, std::string prefix, bool isLast)
{
    if (root == nullptr)
        return;

    std::cout << prefix;

    if (isLast)
    {
        std::cout << "└──";
        prefix += "    ";
    }
    else
    {
        std::cout << "├──";
        prefix += "│   ";
    }

    std::cout << " " << root->getValue() << std::endl;

    printSimpleTree(root->getRight(), prefix, false);
    printSimpleTree(root->getLeft(), prefix, true);

}
