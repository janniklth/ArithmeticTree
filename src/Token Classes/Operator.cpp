/*
 *  created by:     Jannik Loth, Leon Kühn, Mattes Wirths, Carl Felix Schlass
 */

#include "Operator.hpp"

// method to evaluate the result of the tree/subtree
int Operator::eval()
{
    // if there is nothing in the tree, return 0
    if (getValue() == "")
    {
        return 0;
    }

    // if the node is a leaf node, return the value of the node
    if (!getLeft() && !getRight())
    {
        // Leaf node (Operand)
        std::istringstream iss(getValue());
        int value;
        iss >> value;
        return value;
    }

    // return the mathematical result of the operation of the left and right subtree
    if (getValue() == "+")
    {
        return m_left->eval() + m_right->eval();
    }
    else if (getValue() == "-")
    {
        return m_left->eval() - m_right->eval();
    }
    else if (getValue() == "*")
    {
        return m_left->eval() * m_right->eval();
    }
    else if (getValue() == "/")
    {
        return m_left->eval() / m_right->eval();
    }
    return 1; // Default case (should not reach here)
}

// method to return the prefix representation of the tree/subtree
string Operator::prefix()
{
    // return the prefix representation of the left and right subtree behind the operator
    return getValue() + " " + m_left->prefix() + m_right->prefix();
}

// method to return the infix representation of the tree/subtree
string Operator::infix()
{
    string infix_representation;

    // put an opening bracket to the start of the string
    if (m_left != NULL && m_right != NULL)
        infix_representation += "(";

    // add the infix representation of the left and right subtree to the string, separated by the operator
    infix_representation += m_left->infix() + " " + getValue() + " " + m_right->infix();

    // put a closing bracket to the end of the string, when the node has two children
    // TODO: jannik does not understand this part
    if (m_left != NULL && m_right != NULL)
        infix_representation += ")";

    return infix_representation;
}

// method to return the postfix representation of the tree/subtree
string Operator::postfix()
{
    // return the postfix representation of the left and right subtree before the operator
    return m_left->postfix() + m_right->postfix() + getValue() + " ";
}

// - - - - - Getter and Setter - - - - -

// Getter for the left subtree/child_node
Token *Operator::getLeft()
{
    return m_left;
}

// Getter for the right subtree/child_node
Token *Operator::getRight()
{
    return m_right;
}
