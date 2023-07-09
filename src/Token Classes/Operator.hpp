/*
 *  created by:     Jannik Loth, Leon Kühn, Mattes Wirths, Carl Felix Schlass
 */

#ifndef ARITHMETIC_TREE_OPERATOR_HPP
#define ARITHMETIC_TREE_OPERATOR_HPP

#include <iostream>
#include <string>
#include "Token.hpp"
#include <sstream>

/// Operator node class
/// @brief node class representing an operator
class Operator : public Token
{

public:
    /// overloaded constructor, creates a new operator node
    /// @param operator_value: the operator (´+´, ´-´, ´*´ or ´/´)
    /// @param left_token: the left subtree
    /// @param right_token: the right subtree
    Operator(string operator_value, Token *left_token, Token *right_token)
	{
        m_value = operator_value;
        m_left = left_token;
        m_right = right_token;
        m_tokenType = TokenType::OPERATOR;
    }

    /// overloaded constructor, creates a new operator token
    /// @param s: the operator (´+´, ´-´, ´*´ or ´/´)
    Operator(char operator_value)
	{
        m_tokenType = TokenType::OPERATOR;
        m_value = operator_value;
        m_left = NULL;
        m_right = NULL;
    }


    /// evaluate result of the tree/subtree
    /// @return int: the result of the evaluation
    int eval() override;

    /// method to return the postfix representation of the tree/subtree
    /// @return string: the postfix representation of the tree/subtree
    string prefix() override;

    /// method to return the infix representation of the tree/subtree
    /// @return string: the infix representation of the tree/subtree
    string infix() override;

    /// method to return the postfix representation of the tree/subtree
    /// @return string: the postfix representation of the tree/subtree
    string postfix() override;

    /// TODO: implement order() method, what does it do?
    /// numerates the tree starting from the current node using a counter in infix order, important for visualization
    /// @param o: the counter
    void order(Order *o);


    // - - - - - Getter and Setter - - - - -

    /// Getter for the left subtree/child_node
    /// @return Token*: the left subtree/child_node
    Token *getLeft() override;

    /// Getter for the right subtree/child_node
    /// @return Token*: the right subtree/child_node
    Token *getRight() override;

private:
    Token *m_left;
    Token *m_right;
};

#endif // ARITHMETIC_TREE_OPERATOR_HPP