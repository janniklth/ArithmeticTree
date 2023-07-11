/*
 *  created by:     Jannik Loth, Leon Kühn, Mattes Wirths, Carl Felix Schlass
 */

#ifndef ARITHMETIC_TREE_EVALUATOR_HPP
#define ARITHMETIC_TREE_EVALUATOR_HPP

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <stack>

#include "Token Classes/Token.hpp"
#include "Tokenizer.hpp"
#include "Visualizer.hpp"
#include "Token Classes/Number.hpp"
#include "Utilities.hpp"

using namespace std;

/// evaluation of an arithmetic expression by first tokenizing it and then parsing it into a binary m_tree which
/// then can be evaluated and visualized with the help of the Visualizer class
class Evaluator 
{
public:
    /// evaluates an arithmetic expression by first tokenizing it and then parsing it into a binary m_tree which
    /// is then evaluated and visualized
    /// @param exp: the arithmetic expression
    /// @param mode: '<': prefix, '|': infix, '>': postfix
    void evaluate(string exp,  Utilities::ParseMode mode);

private:
    /// checks if a character is an operator
    /// @param i: the character to be checked
    /// @return bool: true if the character is an operator, false otherwise
    bool checkOperator(char i);

    /// calls the corresponding parse method (prefix, infix or postfix)
    /// @param tok: the tokenized arithmetic expression
    /// @param mode: '<': prefix, '|': infix, '>': postfix
    /// @return Token*: the arithmetic binary m_tree
	Token* parse(vector<Token*> *tok, Utilities::ParseMode mode);

    /// parses prefix expression (tokenized string) to an expression m_tree
    /// @param i: iterator that iterates through the vector of tokens
    /// @return Token*: the root node of the m_tree
	Token* parsePrefix(vector<Token*>::iterator& i);

    /// parses postfix expression (tokenized string) to an expression m_tree
    /// @param i: iterator that iterates through the vector of tokens
    /// @return Token*: the root node of the m_tree
    Token* parsePostfix(vector<Token*>::iterator i);

    /// parses infix expression (tokenized string) to an expression m_tree
    /// @param i: iterator that iterates through the vector of tokens
    /// @return Token*: the root node of the m_tree
    Token* parseInfix(vector<Token*>::iterator i);
};

#endif // ARITHMETIC_TREE_EVALUATOR_HPP