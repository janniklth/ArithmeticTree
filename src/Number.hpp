#ifndef ARITHMETIC_TREE_NUMBER_HPP
#define ARITHMETIC_TREE_NUMBER_HPP

#include <iostream>
#include <string>
#include "Token.hpp"

/*
 * Baumknoten und Token zur Darstellung einer Zahl.
 */
class Number : public Token
{
public:

    // default constructor, creates a new number node
    Number() {} // DIESEN LEEREN STANDARDKONSTRUKTOR NICHT LÖSCHEN, WIESOOOOO?? TODO: WHY?

    /// overloaded constructor, creates a new number node with the given value
    /// @param i: the value of the number node
	Number(int i) {
        m_number = i;
        m_value = to_string(i);
        m_tokenType = TokenType::NUMBER;
    }

    /// evaluates the result of the tree/subtree
    /// @return int: the result of the evaluation
    int eval() override;

    /// method to return the prefix representation of the tree/subtree
    /// @return string: the prefix representation of the tree/subtree
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
    void order(Order o);


    // - - - - - Getter and Setter - - - - -

    /// Getter for the number value
    /// @return int: the number value
    int getNumber() const;

private:
    /// the value of the number
    int m_number;
};

#endif //ARITHMETIC_TREE_NUMBER_HPP