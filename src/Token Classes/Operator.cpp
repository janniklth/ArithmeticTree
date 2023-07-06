//
// Created by Jannik Loth on 05.07.23.
//

#include "Operator.hpp"

// method to evaluate the result of the tree/subtree
int Operator::eval()
{
    // if tree is empty
    if (getValue() == "") {
        return 0;
    }

    if (!getLeft() && !getRight()) {
        // Leaf node (Operand)
        std::istringstream iss(getValue());
        int value;
        iss >> value;
        return value;
    }

    int left_value = m_left->eval();
    int right_value = m_right->eval();

    if (getValue() == "+")
    {
        return left_value + right_value;
    }
    else if (getValue() == "-")
    {
        return left_value - right_value;
    }
    else if (getValue() == "*")
    {
        return left_value * right_value;
    }
    else if (getValue() == "/")
    {
        return left_value / right_value;
    }
    return 1; // Default case (should not reach here)
}

// method to return the prefix representation of the tree/subtree
string Operator::prefix()
{
    string prefix_return = "";

    prefix_return += getValue() + " ";
    prefix_return += m_left->prefix();
    prefix_return += m_right->prefix();

    return prefix_return; // remove this line
}

// method to return the infix representation of the tree/subtree
string Operator::infix()
{
    string infix_return = "";

    // put an opening bracket to the start of the string
    if (m_left != NULL && m_right != NULL)
        infix_return += "(";


    infix_return += m_left->infix();
    infix_return += " " + getValue() + " ";
    infix_return += m_right->infix();

    // put an closing bracket to the end of the string
    if (m_left != NULL && m_right != NULL)
        infix_return += ")";

    return infix_return; // remove this line
}

// method to return the postfix representation of the tree/subtree
string Operator::postfix()
{
    string postfix_return = "";

    postfix_return += m_left->postfix();
    postfix_return += m_right->postfix();
    postfix_return += getValue() + " ";

    return postfix_return; // remove this line
}

// TODO: implement order() method, what does it do?
void Operator::order(Order *o)
{
    m_left->order(o);
    setOrd(++o->counter);
    m_right->order(o);
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
